#include "temporary.h"
/* FUSION_GLOBALS */
extern int *piGpffffb98c;
typedef int (*code)(...);
u32 FUN_0040ec50(float param_1,int param_2,u32 param_3,u32 param_4,
                 u32 param_5,u8 *param_6,u32 param_7,int param_8,code param_9,
                 u32 param_10);
/* FUSION_EXACT_PROTOS */
u32 FUN_003c8b50();
extern void FUN_003c9240(int *);
extern u64 FUN_003c9290(int *,u64,u64);
extern s8 FUN_003c9340(int *);
extern void FUN_003c9390(int *);
extern u32 FUN_003c9460(int *);
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

#pragma alias DAT_007ce680_y2 DAT_007ce680
#pragma alias iGpffffb730_y2 iGpffffb730_y2
#pragma alias DAT_0096017c_y2 DAT_0096017c_y2
#pragma alias FUN_00316f70_y2 FUN_00316f70_y2
#pragma alias FUN_00194b20_y2 FUN_00194b20_y2
#pragma alias FUN_003174e0_y2 FUN_003174e0_y2
#pragma alias FUN_005225a8_y2 FUN_005225a8_y2
#pragma alias FUN_001052b0_y2 FUN_001052b0_y2
#pragma alias FUN_003cf960_y2 FUN_003cf960_y2
#pragma alias FUN_003c49e0_y2 FUN_003c49e0_y2
#pragma alias FUN_003c44d0_y2 FUN_003c44d0_y2
#pragma alias FUN_00100ec0_y2 FUN_00100ec0_y2
#pragma alias FUN_0019d3f0_y2 FUN_0019d3f0_y2
#pragma alias FUN_00521408_y2 FUN_00521408_y2

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
extern u32 DAT_007ce680_y2;
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
// W212: structured break-based list search measured nd126 -> nd231 and 328/336 -> 344/336; rejected as over-window.
#pragma push
/* W389 sweep: opt_common_subs off measured nd126/obj328 -> nd95/obj336 (window 336). */
#pragma opt_common_subs off
// FUN_003C8400 NONMATCHING
u32 FUN_003c8400(u32 param_1,int param_2)
{
  u32 lVar2;
  int iVar4;
  int iVar3;
  u32 *puVar5;
  int iVar6;

  if (param_1 == 0) {
    FUN_0019d3f0(DAT_006a3e18_abs,0x396);
  }
  if ((param_2 < 0) || (0xb < param_2)) {
    FUN_0019d3f0(DAT_006a3e18_abs,0x397);
  }
  iVar6 = (int)param_1;
  puVar5 = (u32 *)(iVar6 + param_2 * 0xc + 0x1c);
  if ((*puVar5 & 2) == 0) {
    iVar3 = *(int *)(*(int *)(iVar6 + 0x18) + 4);
    while (iVar3 != 0) {
      iVar4 = *(int *)(iVar3 + 0x14);
      if (*(int *)(iVar4 + 4) != param_2) {
        iVar3 = *(int *)(iVar3 + 0x10);
      } else {
        goto LAB_003c84bc;
      }
    }
    iVar4 = 0;
LAB_003c84bc:
    if (iVar4 == 0) {
      *(int *)((int)puVar5 + 4) = param_2;
      lVar2 = FUN_003c4910(*(int *)(iVar6 + 0x18),
                           *(u16 *)(*(int *)(iVar6 + 0x18) + 0x10) + 1, 0);
      if (lVar2 == 0) {
        FUN_0019d3f0(0x7bb4d8,0x50);
      }
      *(u32 **)(lVar2 + 0x14) = puVar5;
      return 1;
    }
  }
  if ((*puVar5 & 4) != 0) {
    *puVar5 = *puVar5 & 0xfffffffb;
  }
  return 0;
}
#pragma opt_common_subs reset
#pragma pop
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#undef FUN_003c8550
// FUN_003C8550


u64 FUN_003c8550(u8 *param_1)
{
  u8 *context;
  int iVar5;
  int iVar6;
  u32 uVar1;
  u32 lVar2;
  u32 *puVar3;
  u8 auStack_20[32];

  if (param_1 == 0) {
    FUN_0019d3f0("fclMisc.c",0x3ad);
  }
  context = param_1;
  iVar5 = *(int *)(*(int *)(context + 0x18) + 4);
  if (iVar5 != 0) {
    puVar3 = *(u32 **)(iVar5 + 0x14);
    if (puVar3[2] == 0) {
      if (puVar3[1] == 0) {
        FUN_00523ac8(auStack_20,DAT_006a3e18_abs + 0xc8);
      } else {
        lVar2 = FUN_0017d800();
        if (lVar2 != 0) {
        if (puVar3[1] == 1) {
          FUN_00523ac8(auStack_20,DAT_006a3e18_abs + 0xe8,puVar3[1]);
        } else if (puVar3[1] == 9) {
          FUN_00523ac8(auStack_20,DAT_006a3e18_abs + 0x108,puVar3[1]);
        } else {
          FUN_00523ac8(auStack_20,DAT_006a3e18_abs + 0x128,puVar3[1]);
        }
        } else {
          FUN_00523ac8(auStack_20,DAT_006a3e18_abs + 0x128,puVar3[1]);
        }
      }
      uVar1 = FUN_00112370(auStack_20);
      puVar3[2] = uVar1;
    } else {
      lVar2 = fclMisc11f30Call((s16 *)puVar3[2]);
      if (lVar2 != 0) {
        *puVar3 = *puVar3 | 2;
        FUN_003c49e0(*(int *)(context + 0x18),*(int *)(context + 0x18) + 4,iVar5);
      }
    }
  }
  puVar3 = (u32 *)(context + 0x1c);
  for (iVar6 = 0; iVar6 < 0xb; iVar6 = iVar6 + 1) {
    uVar1 = *puVar3;
    if ((uVar1 & 4) != 0) {
      if (puVar3[2] != 0) {
        lVar2 = fclMisc11f30Call((s16 *)puVar3[2]);
        if (lVar2 != 0) {
          *puVar3 &= 0xfffffffb;
          *puVar3 &= 0xfffffffd;
          FUN_001124b0(puVar3[2]);
          puVar3[2] = 0;
        }
      } else {
        *puVar3 &= 0xfffffffb;
        *puVar3 &= 0xfffffffd;
      }
    }
    puVar3 = puVar3 + 3;
  }
  return 0;
}
#define FUN_003c8550(...) ((u64 (*)(...))FUN_003c8550)(__VA_ARGS__)
#undef FUN_003c8770
// FUN_003C8770


u64 FUN_003c8770(u32 param_1, s32 param_2)
{
  u32 entry;
  extern u32 FUN_0019d3f0(u32, u32);

  if (param_1 == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0x3eb);
  }
  if (param_2 < 0 || 0xb < param_2) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0x3ec);
  }
  entry = param_1 + param_2 * 0xc;
  *(u32 *)(entry + 0x1c) |= 4;
  return 0;
}
#define FUN_003c8770(...) ((u64 (*)(...))FUN_003c8770)(__VA_ARGS__)
#undef FUN_003c8810
 
 
// FUN_003C8810
u64 FUN_003c8810(int *param_1)
{
  int *item;
  int *node;

  item = *(int **)(param_1[6] + 4);
  while (item != 0) {
    node = *(int **)((u8 *)item + 0x14);
    if (*(int *)((u8 *)node + 8) == 0) {
      item = fclMiscC49e0Call((int *)param_1[6],(int *)(param_1[6] + 4),item);
    }
    else {
      item = *(int **)((u8 *)item + 0x10);
    }
  }
  item = *(int **)(*param_1 + 4);
  while (item != 0) {
    node = *(int **)((u8 *)item + 0x14);
    if ((*(u32 *)((u8 *)node + 4) & 2) == 0) {
      item = fclMiscC49e0Call((int *)*param_1,(int *)(*param_1 + 4),item);
    }
    else {
      item = *(int **)((u8 *)item + 0x10);
    }
  }
  return 0;
}
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#undef FUN_003c88d0
#pragma alias DAT_0095be80_abs DAT_0095be80
extern u8 DAT_0095be80_abs[];
extern u8 DAT_006a3f60[];
#undef FUN_003c89a0
extern u64 FUN_003c89a0(void);
// FUN_003C88D0


void FUN_003c88d0(void)
{
  u32 object;
  u32 work;
  u8 *state;

  state = DAT_0095be80_abs;
  object = FUN_003c44d0(0xa0, 0, 0, 0);
  work = *(u32 *)(object + 0x24);
  *(u32 *)work = object;
  object = FUN_003c44d0(0xc, 0, 0, 0);
  *(u32 *)(work + 0x18) = object;
  *(u32 *)(work + 4) |= 1;
  piGpffffb98c = (int *)work;
  if (state != 0) {
    *(s32 *)(state + 0) = -1;
    state[4] = 0;
    state[5] = 0;
    *(s32 *)(state + 8) = -1;
    state[12] = 1;
    state[13] = 1;
  }
  FUN_00194b20(0, DAT_006a3f60, 0x18bf, FUN_003c89a0, 0, 0);
}
#define FUN_003c88d0(...) ((void (*)(...))FUN_003c88d0)(__VA_ARGS__)
#undef FUN_003c89a0
#undef FUN_003c8770
extern u64 FUN_003c8770(u32, s32);
#undef FUN_003c8810
extern u64 FUN_003c8810(int *);
#undef FUN_003c8dc0
extern void FUN_003c8dc0(u32);
#undef FUN_003c8400
extern u32 FUN_003c8400();
#undef FUN_003c8b50
extern u32 FUN_003c8b50();
#undef FUN_003c91b0
extern u8 FUN_003c91b0(u8 *, u32);
// FUN_003C89A0
u64 FUN_003c89a0(void)
{
    u32 result;
    int *piVar2;
    int iVar4;
    int *pContext;

    piVar2 = piGpffffb98c;
    if ((piVar2[1] & 1U) != 0) {
        if ((piVar2[1] & 2U) != 0) {
            FUN_003c8810(piVar2);
            result = fclMisc8d80Int();
            if (result != 0) {
                piVar2[1] &= ~2;
                FUN_003c8dc0(0);
                FUN_003c4a90(*piVar2, *piVar2 + 4);
                for (iVar4 = 0; iVar4 < 0xb; iVar4++) {
                    FUN_003c8770((u32)piVar2, iVar4);
                }
            }
        } else {
            iVar4 = *(int *)(*piVar2 + 4);
            if (iVar4 == 0) {
                iVar4 = 0;
            } else {
                goto LAB_003c8a68;
            }
            goto LAB_003c8a6c;
LAB_003c8a68:
            iVar4 = *(int *)(iVar4 + 0x14);
LAB_003c8a6c:
            if (iVar4 == 0) {
                goto LAB_003c8ac8;
            }
            piVar2[1] &= ~1;
            FUN_003c91b0((u8 *)(iVar4 + 0x10), *(u32 *)(iVar4 + 0x28));
            FUN_003c8400((u32)piVar2, 0);
            FUN_003c8400((u32)piVar2, *(u32 *)(iVar4 + 0x2c));
            *(u32 *)(iVar4 + 4) |= 2;
            *(u32 *)(iVar4 + 4) |= 1;
        }
    }
LAB_003c8ac8:
    iVar4 = *(int *)(*piVar2 + 4);
    if (iVar4 != 0) {
        pContext = *(int **)(iVar4 + 0x14);
        if ((pContext[1] & 2U) != 0 &&
            FUN_003c8b50(piVar2, pContext) != 0) {
            piVar2[1] |= 1;
            FUN_003c49e0(*piVar2, *piVar2 + 4, iVar4);
        }
    }
    fclMisc8550Call((u32)piVar2);
    return 0;
}
#define FUN_003c89a0(...) ((u64 (*)(...))FUN_003c89a0)(__VA_ARGS__)
#undef FUN_003c8b50
// FUN_003C8B50


u32 FUN_003c8b50(u32 param_1,int param_2)



{

  u32 uVar1;


  u32 uVar3;


  int iVar5;

  

  iVar5 = (int)param_1;

  if ((*(u32 *)(param_2 + 4) & 4) != 0) {

    uVar3 = FUN_003a3da0(*(u32 *)(param_2 + 0x10));

    if ((uVar3 & 0x3300) == 0) {
      fclMisc9240Call((int *)(param_2 + 0x10));


      if ((*(u32 *)(iVar5 + 0x14) & 1) == 0) {

        if (param_1 == 0) {

          FUN_0019d3f0("fclMisc.c",0x3eb);

        }

        *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar5 + 0x1c) | 4;

      }

      uVar1 = *(u32 *)(param_2 + 0x2c);

      if ((*(u32 *)(iVar5 + 0x14) & 1 << uVar1) == 0) {

        if (param_1 == 0) {

          FUN_0019d3f0("fclMisc.c",0x3eb);

        }

        if (((int)uVar1 < 0) || (0xb < (int)uVar1)) {

          FUN_0019d3f0("fclMisc.c",0x3ec);

        }

        iVar5 = iVar5 + uVar1 * 0xc;

        *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar5 + 0x1c) | 4;

      }

      return 1;

    }

    return 0;

  }

  if ((*(u32 *)(param_2 + 4) & 1) != 0) {

    if (param_1 == 0) {

      FUN_0019d3f0("fclMisc.c",0x3e3);

    }

    if ((*(u32 *)(iVar5 + 0x1c) & 2) == 0) {

      return 0;

    }

    uVar1 = *(int *)(param_2 + 0x2c);

    if (param_1 == 0) {

      FUN_0019d3f0("fclMisc.c",0x3e3);

    }

    if ((*(u32 *)(iVar5 + uVar1 * 0xc + 0x1c) & 2) == 0) {

      return 0;

    }

    *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) & 0xfffffffe;
    fclMisc9290Call((int *)(param_2 + 0x10),*(u32 *)(param_2 + 0x2c),
                    *(u32 *)(param_2 + 0x20));
  }
  fclMisc9390Call((int *)(param_2 + 0x10));
  if (fclMisc9340Call((int *)(param_2 + 0x10)) == 0) {
    fclMisc9460DirectCall((int *)(param_2 + 0x10));
    *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) | 4;
  }





  return 0;

}
#define FUN_003c8b50(...) ((u32 (*)(...))FUN_003c8b50)(__VA_ARGS__)
#undef FUN_003c8d80
// FUN_003C8D80


u8 FUN_003c8d80(void)



{

  return *(int *)(*(int *)(iGpffffb98c + 0x18) + 4) == 0;

}
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#undef FUN_003c8da0
// FUN_003C8DA0


void FUN_003c8da0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0x14) = *(u32 *)(iGpffffb98c + 0x14) | param_1;

  return;

}
#define FUN_003c8da0(...) ((void (*)(...))FUN_003c8da0)(__VA_ARGS__)
#undef FUN_003c8dc0
// FUN_003C8DC0


void FUN_003c8dc0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0x14) = param_1;

  return;

}
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#undef FUN_003c8dd0
// FUN_003C8DD0


void FUN_003c8dd0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0xc) = param_1;

  return;

}
#define FUN_003c8dd0(...) ((void (*)(...))FUN_003c8dd0)(__VA_ARGS__)
#undef FUN_003c8de0
// FUN_003C8DE0


u64 FUN_003c8de0(int param_1,int param_2,int param_3,u16 param_4)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = piGpffffb98c;

  if (piGpffffb98c[3] == 0) {

    FUN_0019d3f0(DAT_006a3e18,0x4ae);

  }

  iVar1 = piVar2[3];

  iVar3 = *piVar2;

  iVar3 = FUN_003c4910(iVar3,*(u16 *)(iVar3 + 0x10) + 1,0x30);

  piVar2 = *(int **)(iVar3 + 0x14);

  *piVar2 = iVar3;

  piVar2[0xb] = param_1;

  piVar2[8] = param_2;

  piVar2[9] = param_3;

  piVar2[10] = iVar1;

  *(u16 *)((int)piVar2 + 0xe) = param_4;

  return 0;

}
#define FUN_003c8de0(...) ((u64 (*)(...))FUN_003c8de0)(__VA_ARGS__)
#undef FUN_003c8ea0
// FUN_003C8EA0


u16 FUN_003c8ea0(void)



{

  return *(u16 *)(*piGpffffb98c + 0x10);

}
#define FUN_003c8ea0(...) ((u16 (*)(...))FUN_003c8ea0)(__VA_ARGS__)
#undef FUN_003c8ec0
// FUN_003C8EC0


u32 FUN_003c8ec0(int param_1, int param_2)
{
  int iVar1;

  iVar1 = *(int *)(*piGpffffb98c + 4);
  while (iVar1 != 0) {
    if ((*(int *)(*(int *)(iVar1 + 0x14) + 0x2c) == param_1) &&
        (*(int *)(*(int *)(iVar1 + 0x14) + 0x20) == param_2)) {
      return 1;
    }
    iVar1 = *(int *)(iVar1 + 0x10);
  }
  return 0;
}
#define FUN_003c8ec0(...) ((u32 (*)(...))FUN_003c8ec0)(__VA_ARGS__)
#undef FUN_003c8f20
// FUN_003C8F20


void FUN_003c8f20(void)



{

  *(u32 *)(iGpffffb98c + 4) = *(u32 *)(iGpffffb98c + 4) | 2;

  return;

}
#define FUN_003c8f20(...) ((void (*)(...))FUN_003c8f20)(__VA_ARGS__)
#undef FUN_003c8f40
#undef FUN_003c8810
// FUN_003C8F40


void FUN_003c8f40(void)



{
  FUN_003c8810((int *)uGpffffb98c);


  return;

}
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#define FUN_003c8f40(...) ((void (*)(...))FUN_003c8f40)(__VA_ARGS__)
#undef FUN_003c8f70
#undef FUN_003c8fa0
void FUN_003c8fa0(void);
// FUN_003C8F70


void FUN_003c8f70(void)



{

  FUN_00109f60(2,0);
  FUN_003c8fa0();


  return;

}
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#define FUN_003c8f70(...) ((void (*)(...))FUN_003c8f70)(__VA_ARGS__)
#undef FUN_003c8fa0
#undef FUN_003c9460
u32 FUN_003c9460();
// FUN_003C8FA0


void FUN_003c8fa0(void)
{
  u8* context;

  if (*(int *)(*piGpffffb98c + 4) != 0) {
    context = *(u8 **)(*(int *)(*piGpffffb98c + 4) + 0x14);
    if ((*(u32 *)(context + 4) & 2) != 0) {
      FUN_003c9460(context + 0x10);
      *(u32 *)(context + 4) |= 4;
    }
  }
}
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#undef FUN_003c9000
static inline f32 fclMiscMulFirst(f32 left, f32 right) { return left * right; }
#pragma push
#pragma opt_rebuildconditionals off
// Conditional-rebuild pragma measured normalized_diff 76 -> 14; remaining
// residuals are commutative mul.s operand order and result-register coloring.
// W389 re-test: six-knob singles/inverse/pairs and m_loadperm found no further change; nd14 remains.
// FUN_003C9000 NONMATCHING


void FUN_003c9000(int param_4, int param_5, f32 param_1, u32 param_6,
                  f32 param_2, f32 param_3, int param_7, u32 param_8)
{
  extern u32 FUN_001158b0(int param_1, u32 param_2, u32 param_3);
  extern void FUN_001127d0(u32 param_1, u32 param_2);
  extern void FUN_00115980(u32 param_1);

  u32 uVar1;

  int iVar2;
  u32 offset;
  u16 uVar3;

  

  iVar2 = iGpffffb98c;
  offset = param_7 * 0xc;
  iVar2 = offset + iVar2;

  if ((*(u32 *)(iVar2 + 0x1c) & 2) != 0) {

    uVar1 = FUN_001158b0(0,*(u32 *)(iVar2 + 0x24),param_8);


    iVar2 = (int)uVar1;
    *(float *)(iVar2 + 0x10) = (float)param_4;

    *(float *)(iVar2 + 0x14) = (float)param_5;

    *(f32 *)(iVar2 + 0x2c) = param_1;
    *(char *)(iVar2 + 0x19) = 0xff - (param_6 & 0xff);

    param_2 = fclMiscMulFirst(4096.0f, param_2);
    if (2147483648.0f <= param_2) goto scale_x_high_9000;
    uVar3 = (u16)(int)param_2;
    goto scale_x_done_9000;
scale_x_high_9000:
    uVar3 = (u16)(0x80000000 | (u32)(int)(param_2 - 2147483648.0f));
scale_x_done_9000:
    *(u16 *)(iVar2 + 0x28) = uVar3;

    param_3 = fclMiscMulFirst(4096.0f, param_3);
    if (2147483648.0f <= param_3) goto scale_y_high_9000;
    uVar3 = (u16)(int)param_3;
    goto scale_y_done_9000;
scale_y_high_9000:
    uVar3 = (u16)(0x80000000 | (u32)(int)(param_3 - 2147483648.0f));
scale_y_done_9000:
    *(u16 *)(iVar2 + 0x2a) = uVar3;

    FUN_001127d0(uVar1,1);

    FUN_00115980(uVar1);

  }

  return;

}
#pragma pop
#define FUN_003c9000(...) ((void (*)(...))FUN_003c9000)(__VA_ARGS__)
#undef FUN_003c91b0
// FUN_003C91B0


u8 FUN_003c91b0(u8 *state, u32 resource)
{
  u32 handle;
  if (state != 0) {
    *(s32 *)(state + 0) = -1;
    state[4] = 0;
    state[5] = 0;
    *(s32 *)(state + 8) = -1;
    state[12] = 1;
    state[13] = 1;
  }
  if (*(s32 *)(state + 0) < 0) {
    handle = FUN_003a2d80(resource);
    *(u32 *)(state + 0) = handle;
    FUN_003a4360(handle, 5);
    return 1;
  }
  return 0;
}
#define FUN_003c91b0(...) ((u8 (*)(...))FUN_003c91b0)(__VA_ARGS__)
#undef FUN_003c9240
#undef FUN_003c9460
u32 FUN_003c9460();
// FUN_003C9240


void FUN_003c9240(int *param_1)



{
  FUN_003c9460(param_1);


  if (*param_1 >= 0) {

    FUN_003a3060(*param_1);

    *param_1 = -1;

    *(u8 *)(param_1 + 1) = 0;

    *(u8 *)((int)param_1 + 5) = 0;

  }

  return;

}
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c9240(...) ((void (*)(...))FUN_003c9240)(__VA_ARGS__)
#undef FUN_003c9290
// FUN_003C9290


u64 FUN_003c9290(int *param_1,u64 param_2,u64 param_3)
{
  if (*param_1 < 0) {
    return 0;
  }
  FUN_003a3e10(*param_1,0x200000);
  FUN_003a30c0(*param_1,param_3,0);
  FUN_003a5210(*param_1,1,5,0x20,0);
  FUN_003a8600(*param_1,param_2);
  *(u8 *)(param_1 + 1) = 1;
  return 0;
}

#define FUN_003c9290(...) ((u64 (*)(...))FUN_003c9290)(__VA_ARGS__)
#undef FUN_003c9340
// FUN_003C9340


s8 FUN_003c9340(int *param_1)
{
  s8 result;

  if (*param_1 < 0) {
    result = 0;
  }
  else if ((*(s8*)((u8*)param_1 + 5) != 0) && (*(s8*)((u8*)param_1 + 4) == 2)) {
    result = 0;
  }
  else {
    result = *(s8*)((u8*)param_1 + 4);
  }
  return result;
}
#define FUN_003c9340(...) ((s8 (*)(...))FUN_003c9340)(__VA_ARGS__)
#undef FUN_003c9390
// FUN_003C9390
void FUN_003c9390(int *param_1)
{
  int state;
  s8 mode;

  state = *param_1;
  if (state < 0) {
    return;
  }
  mode = *(s8 *)((u8 *)param_1 + 4);
  switch (mode) {
  case 0:
    return;
  case 1:
    if (fclMiscA2580Call(state) < 0) {
      *(u8 *)(param_1 + 1) = 2;
    }
    break;
  case 2:
    if (param_1[2] >= 0) {
      param_1[2] = -1;
    }
    if (*(s8 *)((u8 *)param_1 + 5) == 0) {
      *(u8 *)(param_1 + 1) = 3;
    }
    break;
  case 3:
    fclMisc9460Call((u32 *)param_1);
    break;
  }
}
#define FUN_003c9390(...) ((void (*)(...))FUN_003c9390)(__VA_ARGS__)
#undef FUN_003c9460
// FUN_003C9460


u32 FUN_003c9460(u32 *param_1)
{
  u32 result;

  if (param_1 == 0) {
    result = 0;
  }
  else if ((s32)*param_1 < 0) {
    result = 0;
  }
  else {
    FUN_003a25f0(*param_1, 0);
    FUN_003a2a30(*param_1);
    FUN_003a3420(*param_1, 0);
    *((u8 *)param_1 + 4) = 0;
    result = 1;
  }
  return result;
}
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#undef FUN_003c94e0
#pragma alias DAT_0095be90_abs DAT_0095be90
extern u8 DAT_0095be90_abs[];
// FUN_003C94E0






u32 FUN_003c94e0(void)
{
  u8* state;
  u32 resource;

  state = DAT_0095be90_abs;
  if (state != 0) {
    *(s32 *)(state + 0) = -1;
    state[4] = 0;
    state[5] = 0;
    *(s32 *)(state + 8) = -1;
    state[12] = 1;
    state[13] = 1;
  }
  if (*(s32 *)(state + 0) < 0) {
    resource = FUN_003a2d80();
    *(s32 *)(state + 0) = resource;
    FUN_003a4360(resource, 6);
    return 1;
  }
  return 0;
}
#define FUN_003c94e0(...) ((u32 (*)(...))FUN_003c94e0)(__VA_ARGS__)
#undef FUN_003c9570
// FUN_003C9570


void FUN_003c9570(u64 param_1)
{
  int x;
  int width;
  int height;
  int special;
  int index;
  int y;
  int *source;
  int *destination;
  int count;
  int first;
  int second;
  FclMisc9570Layout layout;

  special = 0;
  index = 0;
  source = fclMiscSizeTable;
  destination = layout.sizeTable;
  count = 3;
  do {
    first = source[0];
    second = source[1];
    source += 2;
    count--;
    destination[0] = first;
    destination[1] = second;
    destination += 2;
  } while (count > 0);

  layout.specialValues.vec = *(FclMiscVec3 *)fclMiscSpecialValues;

  if ((short)(width = FUN_003af380()) == -1) {
    special = 1;
    index = FUN_003af390();
    width = layout.sizeTable[index * 2];
    height = layout.sizeTable[index * 2 + 1] * 25;
  }
  else {
    height = FUN_003af390() * 25;
  }

  if ((short)(x = FUN_003af360()) == -1) {
    x = 0x140 - (width >> 1);
  }

  y = FUN_003af370();
  if ((short)y == -1) {
    y = 0xe0 - (height >> 1);
  }

  if (special) {
    FUN_003a3ce0(param_1,0x4d0,0x4e0);
    source = layout.specialValues.raw + index;
    index = *source;
    FUN_003a8650(param_1,0,0x408,0,0x2800,index << 3);
    FUN_003a6a80(param_1,0x254,index + 0x71);
  }
  else {
    FUN_003a3ce0(param_1,x << 4,y << 3);
    FUN_003a8650(param_1,x << 4,y << 3,0,width << 4,height << 3);
  }
}
#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#undef FUN_003c9570
#undef FUN_003c9790
// FUN_003C9790


u8 FUN_003c9790(u64 param_1)
{
  s32* state = (s32*)DAT_0095be90_abs;

  if (*state < 0) {
    return 0;
  }
  FUN_003a3e10(*state, 0x200000);
  FUN_003a30c0(*state, param_1, 0);
  FUN_003c9570(*state);
  FUN_003a5210(*state, 0, 0, 0x20, 0);
  *((u8*)state + 4) = 1;
  FUN_003a27c0(*state, -1);
  return 1;
}

// FUN_003C9840
int FUN_003c9840(void)
{
  return 0;
}

#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#define FUN_003c9790(...) ((u8 (*)(...))FUN_003c9790)(__VA_ARGS__)
#undef FUN_003c9850
// FUN_003C9850


u32 FUN_003c9850(int param_1,int param_2,u16 param_3,u16 param_4)



{

  u8 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u8 **ppuVar6;

  u32 *puVar5;

  int *piVar7;

  FclMisc9850Work *work;

  int iVar4;
  u32 ok;

  int aiStack_20 [8];

  u32 auStack_60 [16];

  

  if (param_2 < 0) {
    goto invalidFacility;
  }
  ok = (param_2 < 5);
  if (ok) {
    goto validFacility;
  }
invalidFacility:
  FUN_0019d3f0("fclMisc.c",0x661);
validFacility:

  ppuVar6 = fclMiscFacilityPssBattlePakTable;

  piVar7 = aiStack_20;

  iVar4 = 5;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *piVar7 = (int)puVar1;

    piVar7 = piVar7 + 1;

  } while (0 < iVar4);

  ppuVar6 = PTR_LAB_006a4060_abs;

  puVar5 = auStack_60;

  iVar4 = 0xf;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *puVar5 = (u32)puVar1;

    puVar5 = puVar5 + 1;

  } while (0 < iVar4);

  uVar2 = DAT_00960178_abs[0](0xec,0x40000);

  FUN_00521408(uVar2,0,0xec);

  work = (FclMisc9850Work *)uVar2;

  work->active = 1;

  iVar4 = (int)param_2;

  work->facility = iVar4;

  work->battlePackage = aiStack_20[iVar4];

  FUN_00521250(work->initialData,auStack_60 + iVar4 * 3,0xc);

  work->width = param_3;

  work->height = param_4;

  if (work->width < 1) {

    work->width = 1;

  }

  if (work->height < 1) {

    work->height = 1;

  }

  work->status = -1;

  uVar3 = FUN_00194b20(param_1,fclMiscTaskDescriptor0,10,fclMiscTaskUpdateCallback,fclMiscTaskDestroyCallback,uVar2);

  FUN_00194b20(uVar3,fclMiscTaskDescriptor1,0x1070,fclMiscTaskLoadCallback,0,uVar2);

  FUN_00194b20(uVar3,fclMiscTaskDescriptor2,0x18aa,fclMiscTaskDrawCallback,0,uVar2);

  iVar4 = FUN_001339a0_f32(0.0f,uVar3,0x1488,0,-1);

  work->drawHandle = iVar4;

  FUN_005225a8(&gp0xffffaa08,DAT_006a3e18_abs,0x67c);

  FUN_005225a8(fclMiscTaskWork);

  FUN_001052b0(fclMiscTaskWork);

  return uVar3;

}
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#undef FUN_003c9cd0
// FUN_003c9ab0
u32 fclMisc003c9ab0(void)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(ctx != 0, 0x683);
    return *(u32*)(ctx + 8) & 0x20;
}

// FUN_003c9b00
void fclMisc003c9b00(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    if (param_3 != NULL) {
        memcpy((void *)(ctx + 0x1c), param_3, 0x54);
    } else {
        memset((void *)(ctx + 0x1c), 0, 0x54);
    }
    if (param_2 != NULL) {
        memcpy((void *)(ctx + 0x20), param_2, 0x34);
    }
}

// FUN_003c9ba0
void fclMisc003c9ba0(u32 param_1, void* param_2)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL, 0x697);
    memcpy((void *)(ctx + 0x20), param_2, 0x34);
}

// FUN_003c9c10
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL && param_3 != NULL, 0x69e);
    memcpy((void *)(ctx + 0x20), param_2, 0x34);
    memcpy((void *)(ctx + 0x74), param_3, 0x34);
    if ((*(u32*)(ctx + 8) & 0x40) == 0) {
        *(s16*)(ctx + 0x16) = (s16)(*(s8*)(ctx + 0xe8) * *(s16*)(ctx + 0x14));
    }
    *(u32*)(ctx + 8) |= 0x40;
    return 1;
}
// FUN_003C9CD0


void FUN_003c9cd0(u64 param_1,u32 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u32 *)(iVar1 + 0x18) = param_2;

  return;

}
#define FUN_003c9cd0(...) ((void (*)(...))FUN_003c9cd0)(__VA_ARGS__)
#undef FUN_003c9d00
// FUN_003C9D00


void FUN_003c9d00(u32 param_1, u32 param_2)
{
  u32 context;
  u32 message;
  u32 source;
  extern u8 DAT_006a40f0[];

  context = FUN_00195540();
  *(u32 *)(context + 8) |= param_2;
  message = (u32)&gp0xffffaa08;
  source = (u32)DAT_006a3e18;
  FUN_005225a8(message, source, 0x6b3);
  FUN_005225a8(DAT_006a40f0, param_2);
  FUN_001052b0(DAT_006a40f0, param_2);
}
#define FUN_003c9d00(...) ((void (*)(...))FUN_003c9d00)(__VA_ARGS__)
#undef FUN_003c9d80
// FUN_003C9D80


void FUN_003c9d80(u32 param_1, u32 param_2)
{
  u32 context;
  u32 message;
  u32 source;
  extern u8 DAT_006a4110[];

  context = FUN_00195540();
  *(u32 *)(context + 8) &= ~param_2;
  message = (u32)&gp0xffffaa08;
  source = (u32)DAT_006a3e18;
  FUN_005225a8(message, source, 0x6b9);
  FUN_005225a8(DAT_006a4110, param_2);
  FUN_001052b0(DAT_006a4110, param_2);
}
#define FUN_003c9d80(...) ((void (*)(...))FUN_003c9d80)(__VA_ARGS__)
#undef FUN_003c9e00
// FUN_003C9E00


void FUN_003c9e00(u64 param_1,u16 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u16 *)(iVar1 + 0xea) = param_2;

  return;

}
#define FUN_003c9e00(...) ((void (*)(...))FUN_003c9e00)(__VA_ARGS__)
#undef FUN_003c9e30
// FUN_003C9E30


void FUN_003c9e30(u64 param_1,u8 param_2,u8 param_3)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u8 *)(iVar1 + 0xe9) = param_2;

  *(u8 *)(iVar1 + 0xe8) = param_3;

  return;

}
#define FUN_003c9e30(...) ((void (*)(...))FUN_003c9e30)(__VA_ARGS__)
#undef FUN_003c9e70
// FUN_003C9E70


void FUN_003c9e70(u64 param_1, s8 param_2)
{
  s32 limit;
  s32 value;
  u32 context;

  context = FUN_00195540();
  *(s8 *)(context + 0xe8) = param_2;
  value = param_2;
  if (value < 0) {
    ((u8 *)context)[0xe8] = 0;
  }
  else {
    limit = *(s8 *)(context + 0xe9);
    value = value < limit;
    if (value != 0) {
      return;
    }
    ((s8 *)context)[0xe8] = limit - 1;
  }
}
#define FUN_003c9e70(...) ((void (*)(...))FUN_003c9e70)(__VA_ARGS__)
#undef FUN_003c9ee0
// FUN_003C9EE0


s8 FUN_003c9ee0(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  return *(char *)(iVar1 + 0xe8);

}
#define FUN_003c9ee0(...) ((s8 (*)(...))FUN_003c9ee0)(__VA_ARGS__)
#undef FUN_003c9f10
// FUN_003C9F10


void FUN_003c9f10(u64 param_1,short param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(short *)(iVar1 + 0xc) = param_2;

  if (param_2 == 0) {

    ((short *)iVar1)[6] = 1;

  }

  return;

}
#define FUN_003c9f10(...) ((void (*)(...))FUN_003c9f10)(__VA_ARGS__)
#undef FUN_003c9f60
// FUN_003C9F60


void FUN_003c9f60(u64 param_1,short param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(short *)(iVar1 + 0xe) = param_2;

  if (param_2 == 0) {

    ((short *)iVar1)[7] = 1;

  }

  return;

}
#define FUN_003c9f60(...) ((void (*)(...))FUN_003c9f60)(__VA_ARGS__)
#undef FUN_003c9fb0
// FUN_003C9FB0


void FUN_003c9fb0(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u16 *)(iVar1 + 0x14) = 0xf;

  return;

}
#define FUN_003c9fb0(...) ((void (*)(...))FUN_003c9fb0)(__VA_ARGS__)
#undef FUN_003c9fe0
// FUN_003C9FE0


void FUN_003c9fe0(int *param_1)
{
  extern u8 DAT_006a4130[];
  extern u8 DAT_006a4150[];
  extern u8 DAT_006a4170[];
  int iVar1;
  int iVar2;
  u32 uVar3;
  u8 auStack_4[4];

  iVar2 = param_1[0x32];
  FUN_005225a8(&gp0xffffaa08,DAT_006a3e18_abs,0x718);
  FUN_005225a8(DAT_006a4130);
  FUN_001052b0(DAT_006a4130);
  FUN_00119a20();
  FUN_005225a8(&gp0xffffaa08,DAT_006a3e18_abs,0x71a);
  FUN_005225a8(DAT_006a4150);
  FUN_001052b0(DAT_006a4150);

  uVar3 = FUN_00102100(iVar2,0,auStack_4);
  uVar3 = FUN_00112420(uVar3);
  FUN_00119a80(6,uVar3);
  uVar3 = FUN_00102100(iVar2,1,auStack_4);
  uVar3 = FUN_00112420(uVar3);
  FUN_00119a80(8,uVar3);
  uVar3 = FUN_00102100(iVar2,2,auStack_4);
  uVar3 = FUN_00112420(uVar3);
  FUN_00119a80(10,uVar3);
  uVar3 = FUN_00102100(iVar2,3,auStack_4);
  iVar1 = FUN_00112420(uVar3);
  param_1[0x34] = iVar1;

  iVar1 = *param_1;
  switch (iVar1) {
  case 0:
  case 1:
    uVar3 = FUN_00102100(iVar2,4,auStack_4);
    iVar2 = FUN_00112420(uVar3);
    param_1[0x35] = iVar2;
    break;
  case 3:
    uVar3 = FUN_00102100(iVar2,4,auStack_4);
    iVar2 = FUN_00112420(uVar3);
    param_1[0x35] = iVar2;
    break;
  case 2:
  case 4:
    uVar3 = FUN_00102100(iVar2,4,auStack_4);
    iVar2 = FUN_00112420(uVar3);
    param_1[0x36] = iVar2;
    break;
  }

  FUN_005225a8(&gp0xffffaa08,DAT_006a3e18_abs,0x730);
  FUN_005225a8(DAT_006a4170);
  FUN_001052b0(DAT_006a4170);
  return;
}
#define FUN_003c9fe0(...) ((void (*)(...))FUN_003c9fe0)(__VA_ARGS__)
#undef FUN_003ca230
// FUN_003CA230 NONMATCHING


u64 FUN_003ca230(void)
{
  u8 *context;
  s32 state;
  s16 value;
  u32 flags;
  u32 color;
  s32 status;

  context = (u8 *)FUN_00195540();
  state = *(s32 *)(context + 4);

  if (state != 4) {
    if (state != 3) {
      if (state != 2) {
        if (state != 1) {
          goto fclMiscCa230Return;
        }
        *(u32 *)(context + 4) = 2;
        FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x73d);
        FUN_005225a8(0x6a4190);
        FUN_001052b0(0x6a4190);
      }
      *(u32 *)(context + 4) = 3;
      color = FUN_00100d80(*(u32 *)(context + 0xcc),1);
      *(u32 *)(context + 0xc8) = color;
      FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x741);
      FUN_005225a8(0x6a41b0,*(u32 *)(context + 0xcc),*(u32 *)(context + 0xc8));
      FUN_001052b0(0x6a41b0,*(u32 *)(context + 0xcc),*(u32 *)(context + 0xc8));
    }
    status = FUN_001016b0(*(u32 *)(context + 0xc8));
    if (status != 0) {
      fclMisc9fe0Call((int *)context);
      *(u32 *)(context + 4) = 4;
      *(u32 *)(context + 8) = *(u32 *)(context + 8) | 0x20;
      FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x747);
      FUN_005225a8(0x6a41d0);
      FUN_001052b0(0x6a41d0);
    }
  }
  else {
    flags = *(u32 *)(context + 8);
    if ((flags & 8) == 0) {
      if ((flags & 0x10) != 0) {
        value = *(s16 *)(context + 0x10) + 1;
        *(s16 *)(context + 0x10) = value;
        *(s16 *)(context + 0x12) =
          0xff - (s16)((value * 0xff) / (s32)*(s16 *)(context + 0xe));
        if (*(s16 *)(context + 0xe) <= *(s16 *)(context + 0x10)) {
          *(u16 *)(context + 0x10) = 0;
          flags = *(u32 *)(context + 8);
          *(u32 *)(context + 8) = flags & 0xffffffef;
          *(u32 *)(context + 8) = flags & 0xffffffee;
        }
      }
    }
    else {
      *(u32 *)(context + 8) = flags | 1;
      value = *(s16 *)(context + 0x10) + 1;
      *(s16 *)(context + 0x10) = value;
      *(s16 *)(context + 0x12) =
        (s16)((value * 0xff) / (s32)*(s16 *)(context + 0xc));
      if (*(s16 *)(context + 0xc) <= *(s16 *)(context + 0x10)) {
        *(u16 *)(context + 0x10) = 0;
        *(u32 *)(context + 8) = *(u32 *)(context + 8) & 0xfffffff7;
      }
    }

    if ((*(u32 *)(context + 8) & 0x40) != 0) {
      if (*(s8 *)(context + 0xe8) == 0) {
        value = *(s16 *)(context + 0x16) - 1;
        *(s16 *)(context + 0x16) = value;
        if (value < 1) {
          *(u32 *)(context + 8) = *(u32 *)(context + 8) & 0xffffffbf;
        }
      }
      else if (*(s8 *)(context + 0xe8) == 1) {
        value = *(s16 *)(context + 0x16) + 1;
        *(s16 *)(context + 0x16) = value;
        if (*(s16 *)(context + 0x14) <= value) {
          *(u32 *)(context + 8) = *(u32 *)(context + 8) & 0xffffffbf;
        }
      }
    }

    (*(code *)(context + 0xdc))(context);
    if ((*(u32 *)(context + 8) & 1) != 0) {
      if ((*(u32 *)(context + 8) & 4) != 0) {
        color = FUN_00133b70(*(u32 *)(context + 0xc4));
        FUN_00133b80(*(u32 *)(context + 0xc4),0,
                     (*(u32 *)(context + 0x18) & 0xffffff00) | (color & 0xff));
        *(u32 *)(context + 8) = *(u32 *)(context + 8) & 0xfffffffb;
      }
      color = FUN_00133b70(*(u32 *)(context + 0xc4));
      FUN_00133b80(*(u32 *)(context + 0xc4),*(u16 *)(context + 0x22),
                   (*(u32 *)(context + 0x18) & 0xffffff00) | (color & 0xff));
      FUN_00133b40(*(u32 *)(context + 0xc4),*(u8 *)(context + 0x12));
    }
    else {
      color = FUN_00133b70(*(u32 *)(context + 0xc4));
      FUN_00133b80(*(u32 *)(context + 0xc4),0,
                   (*(u32 *)(context + 0x18) & 0xffffff00) | (color & 0xff));
    }
  }

fclMiscCa230Return:
  return 0;
}
#define FUN_003ca230(...) ((u64 (*)(...))FUN_003ca230)(__VA_ARGS__)
#undef FUN_003ca610
// FUN_003CA610


u64 FUN_003ca610(void)
{
  u8* context;

  context = (u8*)FUN_00195540();
  if (((*(u32*)(context + 8) & 1) != 0) &&
      (*(u16*)(context + 0x22) != 0)) {
    (*(code *)(context + 0xe0))(context);
  }
  return 0;
}
#define FUN_003ca610(...) ((u64 (*)(...))FUN_003ca610)(__VA_ARGS__)
#undef FUN_003ca660
// FUN_003CA660


u64 FUN_003ca660(void)
{
  u8* context;

  context = (u8*)FUN_00195540();
  if (((*(u32*)(context + 8) & 1) != 0) &&
      (*(u16*)(context + 0x22) != 0)) {
    (*(code *)(context + 0xe4))(context);
  }
  return 0;
}
#define FUN_003ca660(...) ((u64 (*)(...))FUN_003ca660)(__VA_ARGS__)
#undef FUN_003ca6b0
// FUN_003CA6B0


void FUN_003ca6b0(void)
{
  s32 context;
  s32 resource;

  context = fclMiscContextCall();
  resource = fclMiscAllocCall(6);
  fclMiscReleaseCall(resource);
  resource = fclMiscAllocCall(8);
  fclMiscReleaseCall(resource);
  resource = fclMiscAllocCall(10);
  fclMiscReleaseCall(resource);
  fclMiscReleaseCall(*(u32 *)(context + 0xd0));
  if (*(s32 *)(context + 0xd4) != 0) {
    fclMiscReleaseCall(*(u32 *)(context + 0xd4));
  }
  if (*(s32 *)(context + 0xd8) != 0) {
    fclMiscReleaseCall(*(u32 *)(context + 0xd8));
  }
  fclMiscFreeCall(*(u32 *)(context + 0xc8));
  DAT_0096017c_abs[0]((void *)context);
}

#define FUN_003ca6b0(...) ((void (*)(...))FUN_003ca6b0)(__VA_ARGS__)
#undef FUN_003ca780
#pragma push
#pragma opt_rebuildconditionals off
// Conditional-rebuild pragma and integer-first signature measured normalized_diff
// 36 -> 14; remaining residuals are mul.s operand order and v0/v1 coloring.
// W389 re-test: six-knob singles/inverse/pairs and m_loadperm found no further change; nd14 remains.
// FUN_003CA780 NONMATCHING

u64
FUN_003ca780(int param_1,int param_2,float param_3,u32 param_7,u32 param_8,
            u16 param_9,u16 param_10,u32 param_11,float param_4,float param_5,
            float param_6)
{
  extern u32 FUN_001158b0(int param_1, u32 param_2, u32 param_3);
  extern void FUN_001127d0(u32 param_1, u32 param_2);
  extern void FUN_00115980(u32 param_1);
  int iVar1;
  u32 uVar2;
  u16 uVar3;
  uVar2 = FUN_001158b0(0,param_11,param_8);
  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x10) = (float)param_1;
  *(float *)(iVar1 + 0x14) = (float)param_2;
  *(float *)(iVar1 + 0x2c) = param_3;
  *(u8 *)(iVar1 + 0x19) = 0xff - (param_7 & 0xff);
  *(char *)(iVar1 + 0x30) = (char)(param_7 >> 0x18);
  *(char *)(iVar1 + 0x31) = (char)(param_7 >> 0x10);
  *(char *)(iVar1 + 0x32) = (char)(param_7 >> 8);
  *(u16 *)(iVar1 + 0x24) = param_9;
  *(u16 *)(iVar1 + 0x26) = param_10;
  *(float *)(iVar1 + 0x20) = param_4;
  param_5 = fclMiscMulFirst(4096.0f, param_5);
  if (2147483648.0f <= param_5) goto scale_x_high_ca780;
  uVar3 = (u16)(int)param_5;
  goto scale_x_done_ca780;
scale_x_high_ca780:
  uVar3 = (u16)(0x80000000 | (u32)(int)(param_5 - 2147483648.0f));
scale_x_done_ca780:
  *(u16 *)(iVar1 + 0x28) = uVar3;
  param_6 = fclMiscMulFirst(4096.0f, param_6);
  if (2147483648.0f <= param_6) goto scale_y_high_ca780;
  uVar3 = (u16)(int)param_6;
  goto scale_y_done_ca780;
scale_y_high_ca780:
  uVar3 = (u16)(0x80000000 | (u32)(int)(param_6 - 2147483648.0f));
scale_y_done_ca780:
  *(u16 *)(iVar1 + 0x2a) = uVar3;
  FUN_001127d0(uVar2,1);
  FUN_00115980(uVar2);
  return 0;
}
#pragma pop
#define FUN_003ca780(...) fclMiscCa780Call(__VA_ARGS__)
#undef FUN_003ca960
// W418 negative: 24 declaration/prototype permutation probes left nd438/obj856 unchanged (window 864); neutral and rejected.
// FUN_003CA960 NONMATCHING


void FUN_003ca960(int param_1)



{

  float *pfVar3;

  float *pfVar2;

  float *pfVar1;

  int iVar4;

  int iVar6;

  int lVar5;

  int iVar8;

  float fVar7;

  FclMiscPair stackPair;

  

  pfVar3 = &stackPair.vec.x;

  pfVar2 = (float *)0x8;

  if (pfVar3 != (float *)0x0) {

    do {

      *(u8 *)pfVar3 = 0;

      pfVar3 = (float *)((int)pfVar3 + 1);

      pfVar2 = (float *)((int)pfVar2 + -1);

    } while (pfVar2 != (float *)0x0);

  }

  if (*(char *)(param_1 + 0xe8) == '\0') {

    iVar4 = param_1 + 0x1c;

  }

  else {

    iVar4 = param_1 + 0x70;

  }
  if ((*(u32 *)(param_1 + 8) & 0x40) != 0) {

    lVar5 = (int)*(short *)(param_1 + 0x16);

    fVar7 = (float)(int)*(short *)(param_1 + 0x14);

    iVar4 = (int)(fGpffff808c * fVar7);

    iVar8 = (int)(fGpffff80e0 * fVar7);
    if (*(char *)(param_1 + 0xe8) == '\0') {

      lVar5 = (s16)(*(short *)(param_1 + 0x14) - *(short *)(param_1 + 0x16));

      iVar6 = param_1 + 0x70;

    }

    else {

      iVar6 = param_1 + 0x1c;

    }

    if (lVar5 <= iVar8) {

      fVar7 = fclMisc52e878Call((fGpffff81f0 + 0.0f) -

                                  fGpffff8110 * ((float)(int)lVar5 / (float)iVar8));

      stackPair.vec.x = (fVar7 + 1.0f) * 80.0f;

      if (*(char *)(param_1 + 0xe8) == '\0') {

        stackPair.vec.x = stackPair.vec.x * -1.0f;

      }

      if ((*(u32 *)(param_1 + 8) & 2) == 0) {

        fclMiscDrawStatusCall(stackPair.bits,0.0f,(void *)iVar6,
                              (void *)(iVar6 + 4),
                              (int)((float)(int)*(short *)(param_1 + 0x12) * (1.0f - (fVar7 + 1.0f))));

      }

      else {

        fclMiscDrawStatusNoPersonaCall(stackPair.bits,0.0f,
                                        (void *)iVar6,(void *)(iVar6 + 4),0);

      }

    }

    if (*(char *)(param_1 + 0xe8) == '\0') {

      iVar6 = param_1 + 0x1c;

    }

    else {

      iVar6 = param_1 + 0x70;

    }

    if (iVar4 <= lVar5) {

      fVar7 = fclMisc52e878Call((fGpffff81f0 + 0.0f) -

                                  fGpffff8110 * ((float)((int)lVar5 - iVar4) / (float)iVar8));

      stackPair.vec.x = (1.0f - (fVar7 + 1.0f)) * -80.0f;

      if (*(char *)(param_1 + 0xe8) == '\0') {

        stackPair.vec.x = stackPair.vec.x * -1.0f;

      }

      if ((*(u32 *)(param_1 + 8) & 2) == 0) {

        fclMiscDrawStatusCall(stackPair.bits,0.0f,(void *)iVar6,
                              (void *)(iVar6 + 4),
                              (int)((float)(int)*(short *)(param_1 + 0x12) * (fVar7 + 1.0f)));

      }

      else {

        fclMiscDrawStatusNoPersonaCall(stackPair.bits,0.0f,
                                        (void *)iVar6,(void *)(iVar6 + 4),0);

      }

    }

  }

  else {

    if ((*(u32 *)(param_1 + 8) & 2) == 0) {

      fclMiscDrawStatusCall(stackPair.bits,0.0f,(void *)iVar4,
                            (void *)(iVar4 + 4),*(u16 *)(param_1 + 0x12));

    }

    else {

      fclMiscDrawStatusNoPersonaCall(stackPair.bits,0.0f,
                                     (void *)iVar4,(void *)(iVar4 + 4),
                                     *(u16 *)(param_1 + 0x12));

    }

  }

  return;

}
#define FUN_003ca960(...) ((void (*)(...))FUN_003ca960)(__VA_ARGS__)
#undef FUN_003cacc0
#pragma push
/* W389 pair sweep: opt_lifetimes on + opt_propagation off measured nd617/obj900 -> nd616/obj900 (window 912). */
#pragma opt_lifetimes on
#pragma opt_propagation off
// FUN_003CACC0 NONMATCHING


void FUN_003cacc0(int param_1)



{

  short sVar1;

  int iVar2;

  short *psVar3;

  short *psVar4;

  int iVar5;
  int lVar6;


  

  short asStack_20 [8];

  short asStack_10 [8];

  

  psVar4 = (short *)DAT_006a41e8_abs;

  psVar3 = asStack_10;

  iVar2 = 5;

  do {

    sVar1 = *psVar4;

    psVar4 = psVar4 + 1;

    iVar2 = iVar2 + -1;

    *psVar3 = sVar1;

    psVar3 = psVar3 + 1;

  } while (0 < iVar2);

  psVar4 = (short *)DAT_006a41f8_abs;

  iVar2 = 5;

  do {

    sVar1 = *psVar4;

    psVar4 = psVar4 + 1;

    iVar2 = iVar2 + -1;

    *psVar3 = sVar1;

    psVar3 = psVar3 + 1;

  } while (0 < iVar2);

  iVar2 = *(char *)(param_1 + 0xe9) + -3;

  lVar6 = 0;

  psVar4 = asStack_20 + iVar2;

  psVar3 = asStack_10 + iVar2;

  while( 1 ) {

    iVar5 = *(char *)(param_1 + 0xe9) + -1;

    if (iVar5 <= lVar6) break;

    iVar5 = (int)lVar6;

    if (*(char *)(param_1 + 0xe8) == lVar6) {

      FUN_003ca780(0,0,1.0f,1.0f,(int)*psVar3 + iVar5 * *psVar4,10,

                   *(u16 *)(param_1 + 0x12) | 0xff00,0x18,0,0,*(u32 *)(param_1 + 0xd0));

      FUN_003ca780(0,0,1.0f,1.0f,(int)*psVar3 + iVar5 * *psVar4,8,

                   *(u16 *)(param_1 + 0x12) | 0xff00,iVar5 * 2 + 0x1a,0,0,

                   *(u32 *)(param_1 + 0xd0));

    }

    else {

      FUN_003ca780(0,0,1.0f,1.0f,(int)*psVar3 + iVar5 * *psVar4,10,

                   *(u16 *)(param_1 + 0x12) | 0xff00,0x17,0,0,*(u32 *)(param_1 + 0xd0));

      FUN_003ca780(0,0,1.0f,1.0f,(int)*psVar3 + iVar5 * *psVar4,8,

                   *(u16 *)(param_1 + 0x12) | 0xff00,iVar5 * 2 + 0x19,0,0,

                   *(u32 *)(param_1 + 0xd0));

    }

    lVar6 = iVar5 + 1;

  }

  if ((int)*(char *)(param_1 + 0xe8) == iVar5) {

    FUN_003ca780(0,0,1.0f,1.0f,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],10,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x18,0,0,*(u32 *)(param_1 + 0xd0));

    FUN_003ca780(0,0,1.0f,1.0f,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],8,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x26,0,0,*(u32 *)(param_1 + 0xd0));

  }

  else {

    FUN_003ca780(0,0,1.0f,1.0f,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],10,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x17,0,0,*(u32 *)(param_1 + 0xd0));

    FUN_003ca780(0,0,1.0f,1.0f,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],8,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x25,0,0,*(u32 *)(param_1 + 0xd0));

  }

  return;

}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma pop
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#undef FUN_003cb050
#pragma push
// b210 floor: both call sites differ only in independent argument setup order
// (mtc1/addiu and lw/move/move/mov.s/mov.s); the calls and values are identical.
// FUN_003CB050 NONMATCHING
void FUN_003cb050(u32 param_1,s32 param_2,u32 param_3,s32 param_4,s32 param_5,
                  s32 param_6,s32 param_7,s32 param_8)
{
  s32 offset;
  s32 flags;
  s32 kind;

  if (param_4 == 0) {
    offset = param_2 - param_6 * 4;
    kind = param_5 + 2;
    flags = *(s16 *)(param_8 + 0x12) | -0x100;
    fclMiscCa780Call(0.0f,0.0f,1.0f,1.0f,param_1,offset,
                     flags,kind,0,0,*(u32 *)(param_8 + 0xd8));
  }
  else {
    offset = param_2 + (param_7 - param_6) * 4;
    kind = param_5 + 2;
    flags = *(s16 *)(param_8 + 0x12) | -0x100;
    fclMiscCa780Call(0.0f,0.0f,1.0f,1.0f,param_1,offset,
                     flags,kind,0,0,*(u32 *)(param_8 + 0xd8));
  }
}
#pragma pop
#define FUN_003cb050(...) ((void (*)(...))FUN_003cb050)(__VA_ARGS__)
#undef FUN_003cb100
// W419 negative: inlining the flags expressions into all three Ca780 calls left FUN_003cb100/FUN_003cb960 at nd144/obj236 (baseline nd132/obj236, window240); reverted.
// W419 negative: exact FUN_003ca780 definition-order alias + reordered twin calls gave cb100/cb960 nd94/object236 (baseline nd132/object236; window240) but wrong f12-f15 class mapping; exact alias alone nd354/object412 over-window. Keep the retail ABI-order alias.
// FUN_003CB100 NONMATCHING


void FUN_003cb100(int param_1)



{
  s32 flags;

  flags = *(s16 *)(param_1 + 0x12) | -0x100;
  fclMiscCa780Call(0.0f,0.0f,1.0f,1.0f,0,0,
                    flags,2,0,0,
                    *(u32 *)(param_1 + 0xd0));

  flags = *(s16 *)(param_1 + 0x12) | -0x100;
  fclMiscCa780Call(0.0f,-35.0f,1.0f,1.0f,-0x165,0xbd,
                    flags,0,0,0,
                    *(u32 *)(param_1 + 0xd0));

  flags = *(s16 *)(param_1 + 0x12) | -0x100;
  fclMiscCa780Call(0.0f,-35.0f,1.0f,1.0f,-0x61,0xbd,
                    flags,1,-0x104,0,
                    *(u32 *)(param_1 + 0xd0));

  return;
}

#define FUN_003cb100(...) ((void (*)(...))FUN_003cb100)(__VA_ARGS__)
#undef FUN_003cb1f0
// FUN_003CB1F0 NONMATCHING


void FUN_003cb1f0(u64 param_1)



{

  short sVar1;

  int iVar2;

  u64 *puVar3;

  u8 uVar4;

  u64 *puVar5;

  u16 uVar6;

  u64 *puVar7;

  int *piVar8;

  u8 auStack_18 [8];

  u8 auStack_10 [8];

  u64 uStack_8;

  

  piVar8 = (int *)param_1;

  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(u16 *)((int)piVar8 + 0x12) | 0xff00,5,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(u16 *)((int)piVar8 + 0x12) | 0xff00,6,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(u16 *)((int)piVar8 + 0x12) | 0xff00,4,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,0,0,

               piVar8[0x34]);

  FUN_00133a80(piVar8[0x31]);

  puVar5 = (u64 *)0x8;

  puVar7 = &uStack_8;

  puVar3 = puVar7;

  while (puVar3 != (u64 *)0x0) {

    *(u8 *)puVar7 = 0;

    puVar7 = (u64 *)((int)puVar7 + 1);

    puVar5 = (u64 *)((int)puVar5 + -1);

    puVar3 = puVar5;

  }

  if ((piVar8[2] & 2U) != 0) {

    FUN_001332f0(0,uStack_8,piVar8 + 7,piVar8 + 8,*(u16 *)((int)piVar8 + 0x12));

  }

  else {

    FUN_00133180(0,uStack_8,piVar8 + 7,piVar8 + 8,*(u16 *)((int)piVar8 + 0x12));

  }

  sVar1 = *(short *)((int)piVar8 + 0xea);

  if (sVar1 == 2) {

    iVar2 = *piVar8;

    if ((iVar2 == 4) || (iVar2 == 2)) {
    
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,
    
                   0x15,0,0,piVar8[0x34]);
    
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,
    
                   0x16,0,0,piVar8[0x34]);
    
    }
    
    else if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 0)) {
    
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,2,0,0
    
                   ,piVar8[0x35]);
    
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,
    
                   0,0,piVar8[0x35]);
    
    }


    if ((*(u16 *)((int)piVar8 + 0x22) != 0) && (piVar8[0x1b] != 0)) {

      uVar6 = FUN_0016deb0(*(u8 *)

                            ((u32)*(u16 *)((int)piVar8 + 0x22) * 0xe + iGpffffb730 + 2));

      uVar4 = FUN_0016dba0(uVar6);

      FUN_003ca780(0,0,1.0f,1.0f,0x169,0xc9,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,0

                   ,0,piVar8[0x36]);

      FUN_00523ac8(auStack_18,&gp0xffffaa10,uVar4);

      FUN_0040ec50(0.0f,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_18,0,0x17,(code)0x3cb050,

                   (u32)piVar8);

      FUN_00523ac8(auStack_18,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0.0f,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_18,1,0x1b,

                   (code)0x3cb050,(u32)piVar8);

    }

  }

  else if (sVar1 == 1) {

    iVar2 = *piVar8;

    if ((iVar2 == 4) || (iVar2 == 2)) {
    
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,
    
                   0x15,0,0,piVar8[0x34]);
    
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,
    
                   0x16,0,0,piVar8[0x34]);
    
    }
    
    else if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 0)) {
    
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,2,0,0
    
                   ,piVar8[0x35]);
    
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,
    
                   0,0,piVar8[0x35]);
    
    }

    FUN_003ca780(0,0,1.0f,1.0f,0xc1,8,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x14,0,0,

                 piVar8[0x34]);

  }

  else if (sVar1 == 0) {

    FUN_003ca780(0,0,1.0f,1.0f,0xc1,8,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x14,0,0,

                 piVar8[0x34]);
    fclMiscCacc0Call((void *)((int)piVar8 + 0x12));

    if ((*(u16 *)((int)piVar8 + 0x22) != 0) && (piVar8[0x1b] != 0)) {

      uVar6 = FUN_0016deb0(*(u8 *)

                            ((u32)*(u16 *)((int)piVar8 + 0x22) * 0xe + iGpffffb730 + 2));

      uVar4 = FUN_0016dba0(uVar6);

      FUN_003ca780(0,0,1.0f,1.0f,0x169,0xc9,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,0

                   ,0,piVar8[0x36]);

      FUN_00523ac8(auStack_10,&gp0xffffaa10,uVar4);

      FUN_0040ec50(0.0f,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_10,0,0x17,(code)0x3cb050,

                   (u32)piVar8);

      FUN_00523ac8(auStack_10,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0.0f,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_10,1,0x1b,

                   (code)0x3cb050,(u32)piVar8);

    }

  }

  return;

}
#define FUN_003cb1f0(...) ((void (*)(...))FUN_003cb1f0)(__VA_ARGS__)
#undef FUN_003cb960
// FUN_003CB960 NONMATCHING


void FUN_003cb960(int param_1)



{
  s32 flags;

  flags = *(s16 *)(param_1 + 0x12) | -0x100;

  fclMiscCa780Call(0.0f,0.0f,1.0f,1.0f,0,0,
                   flags,2,0,0,
                   *(u32 *)(param_1 + 0xd0));

  flags = *(s16 *)(param_1 + 0x12) | -0x100;
  fclMiscCa780Call(0.0f,-35.0f,1.0f,1.0f,-0x165,0xbd,
                   flags,0,0,0,
                   *(u32 *)(param_1 + 0xd0));

  flags = *(s16 *)(param_1 + 0x12) | -0x100;
  fclMiscCa780Call(0.0f,-35.0f,1.0f,1.0f,-0x61,0xbd,
                   flags,1,-0x104,0,
                   *(u32 *)(param_1 + 0xd0));

  return;

}
#define FUN_003cb960(...) ((void (*)(...))FUN_003cb960)(__VA_ARGS__)
#undef FUN_003cba50
// Signed color masks and the byte-clear do/while now follow retail's load/store widths.
// The stack scratch area remains a padded aggregate so its 16-byte stores are preserved.
// The reconstructed loop uses retail's pointer guard and decrementing count shape.
// Remaining differences are instruction scheduling and register-coloring around helper calls.
// Keep the marker NONMATCHING until verifier reports an exact match.
// FUN_003CBA50 NONMATCHING


void FUN_003cba50(int *param_1)



{

  int iVar6;
  int offset;

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;


  s16 uVar1;

  int lVar7;
  s16 *entry;

  struct {
    u64 pad;
    s16 values[16];
  } stackArray;
#define auStack_28 stackArray.values

  u64 uStack_8;

  


  switch (*(short *)((int)param_1 + 0xea)) { case 3: if ((char)param_1[0x3a] == '\x01') {
    FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,5,0,0,
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,6,0
  
                 ,0,param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)((char *)param_1 + 0x12) | -0x100,4,0,0,
  
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,0,0,
  
                 param_1[0x34]);
  
    FUN_00133a80(param_1[0x31]);
  
    puVar3 = &uStack_8;
    puVar4 = (u64 *)0x8;
    if (puVar3 != (u64 *)0x0) {
      do {
        *(u8 *)puVar3 = 0;
        puVar3 = (u64 *)((int)puVar3 + 1);
        puVar4 = (u64 *)((int)puVar4 + -1);
      } while (puVar4 != (u64 *)0x0);
    }
  
    if ((param_1[2] & 2U) == 0) {
    
      FUN_00133180(0,uStack_8,param_1 + 7,param_1 + 8,*(s16 *)((char *)param_1 + 0x12));
    
    }
    
    else {
    
      FUN_001332f0(0,uStack_8,param_1 + 7,param_1 + 8,*(s16 *)((char *)param_1 + 0x12));
    
    }
  
  
    iVar6 = *param_1;
  
    if ((iVar6 == 4) || (iVar6 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x15,0,0,param_1[0x34]);
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x16,0,0,param_1[0x34]);
    }
    else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,2,0,
                   0,param_1[0x35]);
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,
                   0,0,param_1[0x35]);
    }
  
    auStack_28[0xc] = uGpffffaa18;
  
    auStack_28[0xd] = uGpffffaa1a;
  
    auStack_28[0xe] = uGpffffaa1c;
  
    auStack_28[0xf] = uGpffffaa1e;
  
    lVar7 = 0;
  
    while (lVar7 < *(char *)((int)param_1 + 0xe9)) {
  
      iVar6 = (int)lVar7;
      offset = iVar6 * 2;
      entry = (s16 *)((u8 *)auStack_28 + offset + 0x18);
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x32,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x36,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x33,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x37,0,0,param_1[0x34]);
  
      }
  
      lVar7 = (long)(iVar6 + 1);
  
    }
  
  }
  
  else {
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,0,0,
  
                 param_1[0x34]);
  
    iVar6 = *param_1;
  
    if ((iVar6 == 4) || (iVar6 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x15,0,0,param_1[0x34]);
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x16,0,0,param_1[0x34]);
    }
    else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,2,0,
                   0,param_1[0x35]);
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,
                   0,0,param_1[0x35]);
    }
  
    auStack_28[8] = uGpffffaa18;
  
    auStack_28[9] = uGpffffaa1a;
  
    auStack_28[10] = uGpffffaa1c;
  
    auStack_28[0xb] = uGpffffaa1e;
  
    lVar7 = 0;
  
    while (lVar7 < *(char *)((int)param_1 + 0xe9)) {
  
      iVar6 = (int)lVar7;
      offset = iVar6 * 2;
      entry = (s16 *)((u8 *)auStack_28 + offset + 0x10);
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x32,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x36,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x33,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x37,0,0,param_1[0x34]);
  
      }
  
      lVar7 = (long)(iVar6 + 1);
  
    }
  
  } break; case 4: if ((char)param_1[0x3a] == '\x01') {
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,5,0,0,
  
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,6,0
  
                 ,0,param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)((char *)param_1 + 0x12) | -0x100,4,0,0,
  
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,0,0,
  
                 param_1[0x34]);
  
    FUN_00133a80(param_1[0x31]);
  
  
    iVar6 = *param_1;
  
    if ((iVar6 == 4) || (iVar6 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x15,0,0,param_1[0x34]);
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x16,0,0,param_1[0x34]);
    }
    else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,2,0,
                   0,param_1[0x35]);
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,
                   0,0,param_1[0x35]);
    }
  
    auStack_28[4] = uGpffffaa20;
  
    auStack_28[5] = uGpffffaa22;
  
    auStack_28[6] = uGpffffaa24;
  
    auStack_28[7] = uGpffffaa26;
  
    lVar7 = 0;
  
    while (lVar7 < *(char *)((int)param_1 + 0xe9)) {
  
      iVar6 = (int)lVar7;
      offset = iVar6 * 2;
      entry = (s16 *)((u8 *)auStack_28 + offset + 8);
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x46,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x48,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x45,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x47,0,0,param_1[0x34]);
  
      }
  
      lVar7 = (long)(iVar6 + 1);
  
    }
  
  }
  
  else {
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,5,0,0,
  
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)((char *)param_1 + 0x12) | -0x100,6,0
  
                 ,0,param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)((char *)param_1 + 0x12) | -0x100,4,0,0,
  
                 param_1[0x34]);
  
    FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,0,0,
  
                 param_1[0x34]);
  
    FUN_00133a80(param_1[0x31]);
  
  
    iVar6 = *param_1;
  
    if ((iVar6 == 4) || (iVar6 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x15,0,0,param_1[0x34]);
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,
                   0x16,0,0,param_1[0x34]);
    }
    else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,2,0,
                   0,param_1[0x35]);
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)((char *)param_1 + 0x12) | -0x100,3,
                   0,0,param_1[0x35]);
    }
  
    auStack_28[0] = uGpffffaa20;
  
    auStack_28[1] = uGpffffaa22;
  
    auStack_28[2] = uGpffffaa24;
  
    auStack_28[3] = uGpffffaa26;
  
    lVar7 = 0;
  
    while (lVar7 < *(char *)((int)param_1 + 0xe9)) {
  
      iVar6 = (int)lVar7;
      offset = iVar6 * 2;
      entry = (s16 *)((u8 *)auStack_28 + offset);
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x46,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x48,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = *entry;
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x45,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,entry[2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     offset + 0x47,0,0,param_1[0x34]);
  
      }
  
      lVar7 = (long)(iVar6 + 1);
  
    }
  
  } break; default: FUN_003ca780(0,0,1.0f,1.0f,0xc1,8,*(s16 *)((char *)param_1 + 0x12) | -0x100,0x14,0,0,
  
               param_1[0x34]); break; }

  return;

}
#undef auStack_28
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)
// FUN_003CCC30
void FUN_003ccc30(void)
{
}

#undef FUN_003ccc40
#pragma push
/* W389 sweep: opt_propagation off measured nd799/obj1112 -> nd720/obj1108 (window 1120). */
#pragma opt_propagation off
// W418 negative: switch shape for the flags&2 dispatch measured nd720/1108 -> nd808/1128 (window 1120); over-window and rejected.
// W418 negative: branch inversion for the flags&2 dispatch was nd720/1108 -> nd720/1108; neutral and rejected.
// FUN_003CCC40 NONMATCHING


void FUN_003ccc40(int *param_1)
{
  int iVar1;
  int context;
  u64 *puVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uStack_8;

  context = (int)param_1;

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | -0x100,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | -0x100,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | -0x100,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | -0x100,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | -0x100,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,3,0,0,
               *(int *)(context + 0xd0));

  FUN_00133a80(*(int *)(context + 0xc4));

  puVar3 = (u64 *)0x8;
  puVar4 = &uStack_8;
  puVar2 = puVar4;
  while (puVar2 != (u64 *)0x0) {
    *(u8 *)puVar4 = 0;
    puVar4 = (u64 *)((int)puVar4 + 1);
    puVar3 = (u64 *)((int)puVar3 + -1);
    puVar2 = puVar3;
  }

  if ((*(int *)(context + 8) & 2U) == 0) {
    FUN_00133460(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }
  else {
    FUN_001332f0(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }

  if (*(int *)(context + 0xd4) != 0) {
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | -0x100,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | -0x100,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    switch (iVar1) { case 0: case 1: case 3: FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | -0x100,2,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | -0x100,3,0,
                 0,*(int *)(context + 0xd4)); break; case 2: case 4: FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | -0x100,0x15,
                 0,0,*(int *)(context + 0xd0));
    FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | -0x100,
                 0x16,0,0,*(int *)(context + 0xd0)); break; }
  }
  return;
}
#pragma opt_propagation reset
#pragma pop
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)
// Retail sibling at 0x3cd0a0: standalone jr $ra nullsub.
// FUN_003CD0A0
void FUN_003cd0a0(void)
{
}

#undef FUN_003cd0b0
#pragma push
/* W389 sweep: opt_propagation off measured nd916/obj1248 -> nd800/obj1244 (window 1248). */
#pragma opt_propagation off
// W418 negative: branch inversion for the flags&2 dispatch was nd800/1244 -> nd800/1244; neutral and rejected.
// FUN_003CD0B0 NONMATCHING


void FUN_003cd0b0(int *param_1)
{
  int iVar1;
  int context;
  u64 *puVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uStack_8;

  context = (int)param_1;

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | -0x100,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | -0x100,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | -0x100,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | -0x100,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | -0x100,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,3,0,0,
               *(int *)(context + 0xd0));

  FUN_00133a80(*(int *)(context + 0xc4));

  puVar3 = (u64 *)0x8;
  puVar4 = &uStack_8;
  puVar2 = puVar4;
  while (puVar2 != (u64 *)0x0) {
    *(u8 *)puVar4 = 0;
    puVar4 = (u64 *)((int)puVar4 + 1);
    puVar3 = (u64 *)((int)puVar3 + -1);
    puVar2 = puVar3;
  }

  if ((*(int *)(context + 8) & 2U) == 0) {
    FUN_00133180(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }
  else {
    FUN_001332f0(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }

  if (*(int *)(context + 0xd4) != 0) {
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | -0x100,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | -0x100,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    switch (iVar1) {
    case 0:
    case 1:
    case 3:
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | -0x100,2,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | -0x100,3,0,0,
                   *(int *)(context + 0xd4));
      break;
    case 2:
    case 4:
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | -0x100,0x15,0,0,
                   *(int *)(context + 0xd0));
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | -0x100,
                   0x16,0,0,*(int *)(context + 0xd0));
      break;
    }
  }

  if (*(int *)(context + 0xd4) != 0) {
    FUN_003ca780(0,0,1.0f,1.0f,0x1d4,0x1a1,*(s16 *)(context + 0x12) | -0x100,0xd,
                 0,0,*(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x231,0x1a1,*(s16 *)(context + 0x12) | -0x100,0xe,
                 0,0,*(int *)(context + 0xd4));
  }
  return;
}
#pragma opt_propagation reset
#pragma pop
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
// Retail sibling at 0x3cd590: standalone jr $ra nullsub.
// FUN_003CD590
void FUN_003cd590(void)
{
}
#undef FUN_003cd5a0
#pragma push
/* W389 sweep: opt_propagation off measured nd799/obj1112 -> nd720/obj1108 (window 1120). */
#pragma opt_propagation off
// W418 negative: branch inversion for the flags&2 dispatch was nd720/1108 -> nd720/1108; neutral and rejected.
// FUN_003CD5A0 NONMATCHING


void FUN_003cd5a0(int *param_1)
{
  int iVar1;
  int context;
  u64 *puVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uStack_8;

  context = (int)param_1;

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | -0x100,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | -0x100,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | -0x100,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | -0x100,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | -0x100,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | -0x100,3,0,0,
               *(int *)(context + 0xd0));

  FUN_00133a80(*(int *)(context + 0xc4));

  puVar3 = (u64 *)0x8;
  puVar4 = &uStack_8;
  puVar2 = puVar4;
  while (puVar2 != (u64 *)0x0) {
    *(u8 *)puVar4 = 0;
    puVar4 = (u64 *)((int)puVar4 + 1);
    puVar3 = (u64 *)((int)puVar3 + -1);
    puVar2 = puVar3;
  }

  if ((*(int *)(context + 8) & 2U) == 0) {
    FUN_00133180(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }
  else {
    FUN_001332f0(0,uStack_8,(int *)(context + 0x1c),(int *)(context + 0x20),
                 *(s16 *)(context + 0x12));
  }

  if (*(int *)(context + 0xd4) != 0) {
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | -0x100,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | -0x100,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    switch (iVar1) {
    case 0:
    case 1:
    case 3:
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | -0x100,2,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | -0x100,3,0,0,
                   *(int *)(context + 0xd4));
      break;
    case 2:
    case 4:
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | -0x100,0x15,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | -0x100,
                   0x16,0,0,*(int *)(context + 0xd0));
      break;
    }
  }
  return;
}
#pragma opt_propagation reset
#pragma pop
#define FUN_003cd5a0(...) ((void (*)(...))FUN_003cd5a0)(__VA_ARGS__)
#undef FUN_003cda00
// FUN_003CDA00


u32 FUN_003cda00(void)
{
  u32 context;

  context = FUN_00195540();
  if (FUN_00316f70(context) != 0) {
    FUN_003174e0(context);
    return 0xffffffff;
  }
  return 0;
}
#define FUN_003cda00(...) ((u32 (*)(...))FUN_003cda00)(__VA_ARGS__)
#undef FUN_003cda60
// Addressing-signal audit: retail has the same $gp color load and $gp data address.
// Residual +48..+60 is aggregate load/store scheduling; +216..+244 is JAL setup order.
// Direct aggregate assignment measured nd20 -> nd200 and exceeded the window, so reverted.
// W389 hand tests: translation z volatile load held nd12; volatile handle sequencing regressed nd12 -> nd16; both reverted.
// W414 argument-order probes: hoisting arg3 pointer before/after argument locals left nd12 unchanged; explicit handle/pointer locals regressed nd12 -> nd16; reverted.

#pragma push
/* W389 sweep: opt_propagation off measured nd20/obj320 -> nd12/obj320 (window 320). */
#pragma opt_propagation off
// FUN_003CDA60 NONMATCHING


void FUN_003cda60(u32 param_1)



{

  u32 uVar1;

  int iVar2;
  u64 xy;
  f32 z;

  FclMiscVec3 rotation;

  FclMiscVec3 translation;

  FclMiscColor color;
  xy = *(u64 *)&fclMiscInitialRotation[0];
  z = fclMiscInitialRotation[0].z;
  *(u64 *)&rotation = xy;
  rotation.z = z;

  xy = *(u64 *)&fclMiscInitialTranslation[0];
  z = fclMiscInitialTranslation[0].z;
  *(u64 *)&translation = xy;
  translation.z = z;

  color.packed = DAT_007cd718;

  uVar1 = DAT_00960178_abs[0](0x100,0x40000);

  FUN_00521408(uVar1,0,0x100);

  iVar2 = (int)uVar1;

  *(u16 *)(iVar2 + 0xc) = 0;

  *(u32 *)(iVar2 + 8) = 1;

  fclMiscC31b0Call(180.0f,(void *)(iVar2 + 0x40),&translation,0);

  FUN_004c35d0(iVar2 + 0x40,&rotation,2);

  *(FclMiscRGBA *)(iVar2 + 0x80) = color.rgba;

  fclMisc6bc80Call(0,*(u16 *)(iVar2 + 0xc),(void *)(iVar2 + 0x84));
  fclMisc6bdb0Call(0,*(u16 *)(iVar2 + 0xc),(void *)(iVar2 + 0x94));

  FUN_00194b20(param_1,&DAT_007cd720,0x147c,
                fclMiscE2a0Callback,fclMiscF080Callback,uVar1);

  return;

}
#pragma opt_propagation reset
#pragma pop
#define FUN_003cda60(...) ((void (*)(...))FUN_003cda60)(__VA_ARGS__)
#undef FUN_003cdba0
// FUN_003CDBA0


u32 FUN_003cdba0(u64 param_1,u16 param_2)
{
  u32 result;
  u8 *context;
  u32 flags;
  context = (u8 *)fclMiscContextCall();
  if (context == 0) {
    fclMiscAssertCall((u32)DAT_006a3e18,0x9e2);
  }
  if (*(s16 *)(context + 0xc) == (param_2 & 0xffff)) {
    *(u16 *)(context + 0xe) = 0;
    result = 0;
  }
  else {
    flags = *(u32 *)(context + 4);
    if ((flags & 1) == 0) {
      *(u16 *)(context + 0xe) = param_2;
      result = 0;
    }
    else {
      if ((param_2 & 0xffff) != 0) {
        flags &= 0xfffffffe;
        *(u32 *)(context + 4) = flags;
        *(u32 *)(context + 8) = 2;
      }
      else {
        if (*(s32 *)(context + 0x18) != 0) {
          fclMisc3174e0Call(*(u32 *)(context + 0x18));
          *(u32 *)(context + 0x18) = 0;
        }
      }
      *(u16 *)(context + 0xc) = param_2;
      *(u16 *)(context + 0xe) = 0;
      result = 1;
    }
  }
  return result;
}

#define FUN_003cdba0(...) ((u32 (*)(...))FUN_003cdba0)(__VA_ARGS__)
#undef FUN_003cdc80
// FUN_003CDC80


u32 FUN_003cdc80(void)
{
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa01);
  }
  return *(u32 *)(context + 4) & 1;
}
#define FUN_003cdc80(...) ((u32 (*)(...))FUN_003cdc80)(__VA_ARGS__)
#undef FUN_003cdcd0
// FUN_003CDCD0


u64 FUN_003cdcd0(u64 param_1, u64 param_2, u64 param_3, u64 param_4)
{
  u32 context;
  u64 result;
  extern u32 FUN_0019d3f0(u32, u32);
  extern u64 FUN_003182d0(u32, u32, u64, u64, u64);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa08);
  }
  if ((*(u32 *)(context + 4) & 1) == 0) {
    result = 0;
  }
  else {
    result = FUN_003182d0(*(u32 *)(context + 0x18), 0, param_2, param_3, param_4);
  }
  return result;
}
#define FUN_003cdcd0(...) ((u64 (*)(...))FUN_003cdcd0)(__VA_ARGS__)
#undef FUN_003cdd80
// FUN_003CDD80


u8 FUN_003cdd80(void)
{
  u8 result;
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa10);
  }
  if ((*(u32 *)(context + 4) & 1) == 0) {
    result = 1;
  }
  else {
    result = *(u8 *)(*(u32 *)(context + 0x18) + 0xee) == 1;
  }
  return result;
}
#define FUN_003cdd80(...) ((u8 (*)(...))FUN_003cdd80)(__VA_ARGS__)
#undef FUN_003cde00
// FUN_003CDE00


void FUN_003cde00(u64 param_1, int param_2)
{
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa18);
  }
  *(u32 *)(context + 4) |= param_2 << 0x10;
}
#define FUN_003cde00(...) ((void (*)(...))FUN_003cde00)(__VA_ARGS__)
#undef FUN_003cde70
// FUN_003CDE70


void FUN_003cde70(u64 param_1, int param_2)
{
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa1e);
  }
  *(u32 *)(context + 4) &= ~(param_2 << 0x10);
}
#define FUN_003cde70(...) ((void (*)(...))FUN_003cde70)(__VA_ARGS__)
#undef FUN_003cdee0
// FUN_003CDEE0


void FUN_003cdee0(u64 param_1, u16 param_2)
{
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa26);
  }
  *(u16 *)context = param_2;
}
#define FUN_003cdee0(...) ((void (*)(...))FUN_003cdee0)(__VA_ARGS__)
#undef FUN_003cdf40
// FUN_003CDF40


void FUN_003cdf40(u64 param_1, u8 *param_2, int param_3)
{
  u8 byte0;
  u8 byte1;
  u8 byte2;
  u8 byte3;
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa51);
  }
  if (param_3 == 0) {
    byte0 = param_2[0];
    byte1 = param_2[1];
    byte2 = param_2[2];
    byte3 = param_2[3];
    *(u8 *)(context + 0xa8) = byte0;
    *(u8 *)(context + 0xa9) = byte1;
    *(u8 *)(context + 0xaa) = byte2;
    *(u8 *)(context + 0xab) = byte3;
    byte0 = *(u8 *)(context + 0xa8);
    byte1 = *(u8 *)(context + 0xa9);
    byte2 = *(u8 *)(context + 0xaa);
    byte3 = *(u8 *)(context + 0xab);
    *(u8 *)(context + 0xa4) = byte0;
    *(u8 *)(context + 0xa5) = byte1;
    *(u8 *)(context + 0xa6) = byte2;
    *(u8 *)(context + 0xa7) = byte3;
    byte0 = *(u8 *)(context + 0xa4);
    byte1 = *(u8 *)(context + 0xa5);
    byte2 = *(u8 *)(context + 0xa6);
    byte3 = *(u8 *)(context + 0xa7);
    *(u8 *)(context + 0x80) = byte0;
    *(u8 *)(context + 0x81) = byte1;
    *(u8 *)(context + 0x82) = byte2;
    *(u8 *)(context + 0x83) = byte3;
  }
  else {
    byte0 = param_2[0];
    byte1 = param_2[1];
    byte2 = param_2[2];
    byte3 = param_2[3];
    *(u8 *)(context + 0xa4) = byte0;
    *(u8 *)(context + 0xa5) = byte1;
    *(u8 *)(context + 0xa6) = byte2;
    *(u8 *)(context + 0xa7) = byte3;
    byte0 = *(u8 *)(context + 0x80);
    byte1 = *(u8 *)(context + 0x81);
    byte2 = *(u8 *)(context + 0x82);
    byte3 = *(u8 *)(context + 0x83);
    *(u8 *)(context + 0xa8) = byte0;
    *(u8 *)(context + 0xa9) = byte1;
    *(u8 *)(context + 0xaa) = byte2;
    *(u8 *)(context + 0xab) = byte3;
  }
  *(u16 *)(context + 0xac) = 0;
  *(s16 *)(context + 0xae) = param_3;
}
#define FUN_003cdf40(...) ((void (*)(...))FUN_003cdf40)(__VA_ARGS__)
#undef FUN_003ce060
// FUN_003CE060


void FUN_003ce060(u64 param_1, f32 *param_2, int param_3)
{
  f32 value0;
  f32 value1;
  f32 value2;
  f32 value3;
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa61);
  }
  if (param_3 == 0) {
    value0 = param_2[0];
    value1 = param_2[1];
    value2 = param_2[2];
    value3 = param_2[3];
    *(f32 *)(context + 0xc0) = value0;
    *(f32 *)(context + 0xc4) = value1;
    *(f32 *)(context + 0xc8) = value2;
    *(f32 *)(context + 0xcc) = value3;
    value0 = *(f32 *)(context + 0xc0);
    value1 = *(f32 *)(context + 0xc4);
    value2 = *(f32 *)(context + 0xc8);
    value3 = *(f32 *)(context + 0xcc);
    *(f32 *)(context + 0xb0) = value0;
    *(f32 *)(context + 0xb4) = value1;
    *(f32 *)(context + 0xb8) = value2;
    *(f32 *)(context + 0xbc) = value3;
    value0 = *(f32 *)(context + 0xb0);
    value1 = *(f32 *)(context + 0xb4);
    value2 = *(f32 *)(context + 0xb8);
    value3 = *(f32 *)(context + 0xbc);
    *(f32 *)(context + 0x84) = value0;
    *(f32 *)(context + 0x88) = value1;
    *(f32 *)(context + 0x8c) = value2;
    *(f32 *)(context + 0x90) = value3;
  }
  else {
    value0 = param_2[0];
    value1 = param_2[1];
    value2 = param_2[2];
    value3 = param_2[3];
    *(f32 *)(context + 0xb0) = value0;
    *(f32 *)(context + 0xb4) = value1;
    *(f32 *)(context + 0xb8) = value2;
    *(f32 *)(context + 0xbc) = value3;
    value0 = *(f32 *)(context + 0x84);
    value1 = *(f32 *)(context + 0x88);
    value2 = *(f32 *)(context + 0x8c);
    value3 = *(f32 *)(context + 0x90);
    *(f32 *)(context + 0xc0) = value0;
    *(f32 *)(context + 0xc4) = value1;
    *(f32 *)(context + 0xc8) = value2;
    *(f32 *)(context + 0xcc) = value3;
  }
  *(u16 *)(context + 0xd0) = 0;
  *(s16 *)(context + 0xd2) = param_3;
}
#define FUN_003ce060(...) ((void (*)(...))FUN_003ce060)(__VA_ARGS__)
#undef FUN_003ce180
// FUN_003CE180


void FUN_003ce180(u64 param_1, f32 *param_2, int param_3)
{
  f32 value0;
  f32 value1;
  f32 value2;
  f32 value3;
  u32 context;
  extern u32 FUN_0019d3f0(u32, u32);

  context = FUN_00195540();
  if (context == 0) {
    FUN_0019d3f0((u32)DAT_006a3e18, 0xa77);
  }
  if (param_3 == 0) {
    value0 = param_2[0];
    value1 = param_2[1];
    value2 = param_2[2];
    value3 = param_2[3];
    *(f32 *)(context + 0xe4) = value0;
    *(f32 *)(context + 0xe8) = value1;
    *(f32 *)(context + 0xec) = value2;
    *(f32 *)(context + 0xf0) = value3;
    value0 = *(f32 *)(context + 0xe4);
    value1 = *(f32 *)(context + 0xe8);
    value2 = *(f32 *)(context + 0xec);
    value3 = *(f32 *)(context + 0xf0);
    *(f32 *)(context + 0xd4) = value0;
    *(f32 *)(context + 0xd8) = value1;
    *(f32 *)(context + 0xdc) = value2;
    *(f32 *)(context + 0xe0) = value3;
    value0 = *(f32 *)(context + 0xd4);
    value1 = *(f32 *)(context + 0xd8);
    value2 = *(f32 *)(context + 0xdc);
    value3 = *(f32 *)(context + 0xe0);
    *(f32 *)(context + 0x94) = value0;
    *(f32 *)(context + 0x98) = value1;
    *(f32 *)(context + 0x9c) = value2;
    *(f32 *)(context + 0xa0) = value3;
  }
  else {
    value0 = param_2[0];
    value1 = param_2[1];
    value2 = param_2[2];
    value3 = param_2[3];
    *(f32 *)(context + 0xd4) = value0;
    *(f32 *)(context + 0xd8) = value1;
    *(f32 *)(context + 0xdc) = value2;
    *(f32 *)(context + 0xe0) = value3;
    value0 = *(f32 *)(context + 0x94);
    value1 = *(f32 *)(context + 0x98);
    value2 = *(f32 *)(context + 0x9c);
    value3 = *(f32 *)(context + 0xa0);
    *(f32 *)(context + 0xe4) = value0;
    *(f32 *)(context + 0xe8) = value1;
    *(f32 *)(context + 0xec) = value2;
    *(f32 *)(context + 0xf0) = value3;
  }
  *(u16 *)(context + 0xf4) = 0;
  *(s16 *)(context + 0xf6) = param_3;
}
#define FUN_003ce180(...) ((void (*)(...))FUN_003ce180)(__VA_ARGS__)
#undef FUN_003ce2a0












// W418 negative: appending direct FUN_003cea50((u16 *)iVar9) measured nd1233/obj1956 -> nd1240/obj1968 (window1968); worsened and filled the window, reverted.
// W418 probe setup: appended call without a forward declaration failed undefined-identifier compilation; macro-active prototype failed declaration syntax; no measurement.
// FUN_003CE2A0 NONMATCHING
u64 FUN_003ce2a0(u64 param_1)



{

  int iVar1;

  u8 *puVar2;

  short sVar3;

  u8 *puVar4;

  u32 uVar5;

  u32 uVar6;

  int lVar7;

  u8 *puVar8;

  int iVar9;

  float fVar10;

  u8 uVar11;

  u8 auStack_8 [8];

  

  uVar6 = FUN_00195540();

  puVar4 = (u8 *)0x8;

  puVar8 = auStack_8;

  puVar2 = puVar8;

  while (puVar2 != (u8 *)0x0) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

    puVar4 = puVar4 + -1;

    puVar2 = puVar4;

  }

  iVar9 = (int)uVar6;

  iVar1 = *(int *)(iVar9 + 8);

  if (iVar1 == 4) {

    if (((*(u32 *)(iVar9 + 4) & 1) != 0) && ((*(u32 *)(iVar9 + 4) & 0x10000) != 0)) {

      if (*(short *)(iVar9 + 0xac) < *(short *)(iVar9 + 0xae)) {

        sVar3 = *(short *)(iVar9 + 0xac) + 1;

        *(short *)(iVar9 + 0xac) = sVar3;

        fVar10 = (float)*(u8 *)(iVar9 + 0xa8) +

                 (float)(int)((int)sVar3 *

                             ((u32)*(u8 *)(iVar9 + 0xa4) - (u32)*(u8 *)(iVar9 + 0xa8))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09f) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09f);

        }

        *(u8 *)(iVar9 + 0x80) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xa9) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa5) - (u32)*(u8 *)(iVar9 + 0xa9))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09f) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09f);

        }

        *(u8 *)(iVar9 + 0x81) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xaa) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa6) - (u32)*(u8 *)(iVar9 + 0xaa))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09f) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09f);

        }

        *(u8 *)(iVar9 + 0x82) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xab) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa7) - (u32)*(u8 *)(iVar9 + 0xab))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09f) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09f);

        }

        *(u8 *)(iVar9 + 0x83) = uVar11;

      }

      if (*(short *)(iVar9 + 0xd0) < *(short *)(iVar9 + 0xd2)) {

        sVar3 = *(short *)(iVar9 + 0xd0) + 1;

        *(short *)(iVar9 + 0xd0) = sVar3;

        *(float *)(iVar9 + 0x84) =

             *(float *)(iVar9 + 0xc0) +

             ((float)(int)sVar3 * (*(float *)(iVar9 + 0xb0) - *(float *)(iVar9 + 0xc0))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x88) =

             *(float *)(iVar9 + 0xc4) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xb4) - *(float *)(iVar9 + 0xc4))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x8c) =

             *(float *)(iVar9 + 200) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xb8) - *(float *)(iVar9 + 200))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x90) =

             *(float *)(iVar9 + 0xcc) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xbc) - *(float *)(iVar9 + 0xcc))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

      }

      if (*(short *)(iVar9 + 0xf4) < *(short *)(iVar9 + 0xf6)) {

        sVar3 = *(short *)(iVar9 + 0xf4) + 1;

        *(short *)(iVar9 + 0xf4) = sVar3;

        *(float *)(iVar9 + 0x94) =

             *(float *)(iVar9 + 0xe4) +

             ((float)(int)sVar3 * (*(float *)(iVar9 + 0xd4) - *(float *)(iVar9 + 0xe4))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0x98) =

             *(float *)(iVar9 + 0xe8) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xd8) - *(float *)(iVar9 + 0xe8))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0x9c) =

             *(float *)(iVar9 + 0xec) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xdc) - *(float *)(iVar9 + 0xec))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0xa0) =

             *(float *)(iVar9 + 0xf0) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xe0) - *(float *)(iVar9 + 0xf0))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

      }


    }

  }

  else {

    if (iVar1 != 3) {

      if (iVar1 != 2) {

        if (iVar1 != 1) {

          return 0;

        }

        *(u32 *)(iVar9 + 8) = 2;

      }

      if (*(int *)(iVar9 + 0x18) != 0) {

        FUN_003174e0();

      }

      if (*(short *)(iVar9 + 0xc) == 0) {

        *(u32 *)(iVar9 + 8) = 4;

        *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 1;

        return 0;

      }

      uVar5 = FUN_00316e00(0xb,*(short *)(iVar9 + 0xc),0);

      *(u32 *)(iVar9 + 0x18) = uVar5;

      *(u32 *)(iVar9 + 8) = 3;

    }

    lVar7 = FUN_00316f70(*(u32 *)(iVar9 + 0x18));

    if (lVar7 != 0) {

      FUN_00319230(*(u32 *)(iVar9 + 0x18),8);

      *(u32 *)(iVar9 + 8) = 4;

      *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 1;

      if (*(short *)(iVar9 + 0xe) == 0) {

        *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) =

             *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) & 0xfeff;

        FUN_00319050(*(u32 *)(iVar9 + 0x18));

        sVar3 = FUN_0017c0e0(*(u16 *)(iVar9 + 0xc));

        if (sVar3 != 8) {

          if (sVar3 == 4) {

            FUN_00319070(*(u32 *)(iVar9 + 0x18));

          }

          else if (sVar3 == 2) {

            *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) =

                 *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) | 0x200;

          }

        }

        FUN_0016bc80(0,*(u16 *)(iVar9 + 0xc),iVar9 + 0x84);

        FUN_0016bdb0(0,*(u16 *)(iVar9 + 0xc),iVar9 + 0x94);

      }

      else {
        FUN_003cdba0(param_1,*(short *)(iVar9 + 0xe));

      }

    }

  }

  return 0;

}
#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#undef FUN_003cea50
#pragma push
/* W389 sweep: opt_lifetimes on measured nd1041/obj1532 -> nd942/obj1488 (window 1584). */
#pragma opt_lifetimes on
// FUN_003CEA50 NONMATCHING


u64 FUN_003cea50(u16 *param_1)



{
  extern float FUN_001a4600(u32);
  extern void FUN_001a4580(u32, float);


  u32 uVar1;

  u32 uVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  u32 uVar6;

  u32 uVar7;

  u32 lVar8;

  float *pfVar9;

  u32 *puVar10;

  u32 *puVar11;


  int iVar12;

  float fVar13;

  float uVar14;

  float fVar15;

  float fVar16;

  short sStack_160;

  short sStack_15e;

  short sStack_15c;

  float fStack_158;

  float fStack_154;

  short sStack_150;

  short sStack_144;

  short sStack_142;

  u32 auStack_140 [16];

  FclMiscVec4 vStack_100;

    RwMatrix matrix;

  u32 auStack_b0 [16];

    FclMiscVec4 savedView;
    FclMiscVec4 savedProjection;

  u64 uStack_48;

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  u64 uStack_28;
  float fStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  u8 auStack_4 [3];

  u8 bStack_1;

  

  uVar6 = FUN_00198590();

  uVar14 = FUN_001a4600(uVar6);

  iVar4 = FUN_00198560();

  savedView.x = *(float *)(iVar4 + 0x18);
  savedView.y = *(float *)(iVar4 + 0x1c);
  savedView.z = *(float *)(iVar4 + 0x20);
  savedView.w = *(float *)(iVar4 + 0x24);

  iVar4 = FUN_00198570();

  savedProjection.x = *(float *)(iVar4 + 0x18);
  savedProjection.y = *(float *)(iVar4 + 0x1c);
  savedProjection.z = *(float *)(iVar4 + 0x20);
  savedProjection.w = *(float *)(iVar4 + 0x24);

  iVar4 = FUN_00198590();

  fStack_10 = *(float *)(iVar4 + 0x78);

  fStack_c = *(float *)(iVar4 + 0x7c);

  iVar4 = FUN_00198570();

  puVar11 = (u32 *)(*(int *)(iVar4 + 4) + 0x10);

  puVar10 = auStack_b0;

  iVar4 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar4 = iVar4 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar4);

  vStack_100 = fclMiscDefaultQuat[0];

  uStack_28 = fclMiscDefaultScale[0];
  fStack_20 = fclMiscDefaultScaleZ[0];

  pfVar5 = (float *)0xc;

  pfVar9 = &fStack_38;

  pfVar3 = pfVar9;

  while (pfVar3 != (float *)0x0) {

    *(u8 *)pfVar9 = 0;

    pfVar9 = (float *)((int)pfVar9 + 1);

    pfVar5 = (float *)((int)pfVar5 + -1);

    pfVar3 = pfVar5;

  }

  uStack_48 = fclMiscDefaultPosition[0];
  fStack_40 = fclMiscDefaultPositionZ[0];

  iVar4 = FUN_00198590();

  iVar12 = *(int *)(iVar4 + 4) + 0x10;

  uVar6 = FUN_00198590();

  FUN_001a4580(uVar6, 40.0f);

  uVar6 = FUN_00198560();

  FUN_004944b0(uVar6,param_1 + 0x42);

  uVar6 = FUN_00198570();

  FUN_004944b0(uVar6,param_1 + 0x4a);

  FUN_0016bee0(0,param_1[6],&vStack_100);

  fVar15 = 2.0f / (vStack_100.w * vStack_100.w +
                 vStack_100.z * vStack_100.z + vStack_100.x * vStack_100.x + vStack_100.y * vStack_100.y);

  fVar16 = vStack_100.x * fVar15;

  fVar13 = vStack_100.y * fVar15;

  fVar15 = vStack_100.z * fVar15;

  matrix.right.x = 1.0f - (vStack_100.y * fVar13 + vStack_100.z * fVar15);
  matrix.right.y = vStack_100.x * fVar13 + fVar15 * vStack_100.w;
  matrix.right.z = vStack_100.z * fVar16 - fVar13 * vStack_100.w;
  matrix.up.x = vStack_100.x * fVar13 - fVar15 * vStack_100.w;
  matrix.up.y = 1.0f - (vStack_100.z * fVar15 + vStack_100.x * fVar16);
  matrix.up.z = vStack_100.y * fVar15 + fVar16 * vStack_100.w;
  matrix.at.x = vStack_100.z * fVar16 + fVar13 * vStack_100.w;
  matrix.at.y = vStack_100.y * fVar15 - fVar16 * vStack_100.w;
  matrix.at.z = 1.0f - (vStack_100.x * fVar16 + vStack_100.y * fVar13);
  matrix.pos.x = 0.0f;
  matrix.pos.y = 0.0f;
  matrix.pos.z = 0.0f;
  matrix.flags = 3;
  FUN_004c2f30(&matrix, &matrix, iVar12);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4), &matrix, 0);

  iVar4 = FUN_00198570();

  *(u8 *)(iVar4 + 2) = 3;

  FUN_00198570();

  uVar6 = FUN_00198540(DAT_007ce0cc);

  uVar7 = FUN_00198580();

  FUN_0049c480(uVar6,uVar7);

  FUN_0016bf80(*param_1,param_1[6],&sStack_160);

  fStack_18 = (float)(int)sStack_144 / 640.0f;

  fStack_14 = (float)(int)sStack_142 / 448.0f;

  fStack_38 = (float)((int)(short)param_1[0xe] + (int)sStack_160);

  fStack_34 = (float)((int)(short)param_1[0xf] + (int)sStack_15e);

  fStack_30 = (float)((int)(short)param_1[0x10] + (int)sStack_15c);

  fStack_40 = *(float *)(param_1 + 0x12) + fStack_158;

  uStack_48 = ((u64)*(u32 *)&fStack_40 << 32) | *(u32 *)&fStack_40;

  FUN_00521250(auStack_4,param_1 + 0x40,4);

  bStack_1 = (u8)((int)((u32)bStack_1 * (int)sStack_150) / 0xff);

  puVar11 = (u32 *)(param_1 + 0x20);

  puVar10 = auStack_140;

  iVar4 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar4 = iVar4 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar4);

  fclMiscC31b0Call(fStack_154,auStack_140,&uStack_28,1);

  FUN_004c35d0(auStack_140,&fStack_38,2);

  FUN_004c2f30(auStack_140,auStack_140,iVar12);

  FUN_00318a70(*(u32 *)(param_1 + 0xc),auStack_140,0);

  FUN_00318a90(*(u32 *)(param_1 + 0xc),&uStack_48,1);

  FUN_00318ad0(*(u32 *)(param_1 + 0xc),auStack_4);

  uVar6 = FUN_00198590();

  FUN_004c9d20(uVar6,&fStack_18);

  uVar6 = FUN_00198590();

  lVar8 = FUN_004c9d10(uVar6);

  if (lVar8 == 0) {

    FUN_0019d3f0("fclMisc.c",0xb2d);

  }

  else {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(0xe,0);

    FUN_004d7f60(2,0x44);

    FUN_004d7f60(3,0x717fb);

    FUN_00317a20(*(u32 *)(param_1 + 0xc));

    uVar6 = FUN_00198590();

    FUN_004c9d00(uVar6);

  }

  uVar6 = FUN_00198590();

  FUN_001a4580(uVar6, uVar14);

  uVar6 = FUN_00198560();

  FUN_004944b0(uVar6, &savedView);
  uVar6 = FUN_00198570();
  FUN_004944b0(uVar6, &savedProjection);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),auStack_b0,0);

  iVar4 = FUN_00198570();

  *(u8 *)(iVar4 + 2) = 3;

  FUN_00198570();

  uVar6 = FUN_00198590();

  FUN_004c9d20(uVar6,&fStack_10);

  return 0;

}
#pragma opt_lifetimes reset
#pragma pop
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#undef FUN_003cf6c0
// FUN_003cf080
void fclCombine003cf080(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 temp;

    temp = FUN_00195540();
    if (0 == *(s32*)(temp + 0x18)) goto done;
    if (FUN_00316f70_y2(*(s32*)(temp + 0x18)) != 0) {
        FUN_003174e0_y2(*(s32*)(temp + 0x18));
    } else {
        FUN_00194b20_y2(0, DAT_006a4208, 0x147c, fclCombine003cf080, 0, *(s32*)(temp + 0x18));
    }
done:
    ((void (*)(s32))DAT_0096017c_y2[0])(temp);
}

// FUN_003cf120
s32 fclCombine003cf120(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    DAT_007ce680 = FUN_003c44d0_y2(0x40, 0, 0, 0);
    return *(s32*)(DAT_007ce680 + 0x24);
}

// FUN_003cf160
s64 fclCombine003cf160(s32 param_1, s32 param_2)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    u32 lo;
    u32 mid;
    u32 hi;
    s64 result;

    FUN_005225a8_y2((char*)&DAT_007cd728, DAT_006a4270, 0x66);
    lo = (u32)param_1 & 0xff;
    mid = ((u32)param_1 & 0xff00) >> 8;
    hi = ((u32)param_1 & 0xffff0000) >> 0x10;
    FUN_005225a8_y2(DAT_006a4288, param_1, hi, mid, lo);
    FUN_001052b0_y2(DAT_006a4288, param_1, hi, mid, lo);
    result = FUN_003cf960_y2(param_1, param_2) != 0;
    return (result << 48) >> 48;
}

#pragma push
#pragma opt_propagation off
// FUN_003cf240
s32 fclCombine003cf240(s32 param_1, s32 param_2)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s16 index;
    s32 base;
    s16 mask;
    s32 offset;
    s32 entryAddress;
    u32 lo;
    u32 mid;
    u32 hi;

    FUN_005225a8_y2((char*)&DAT_007cd728, DAT_006a4270, 0x7e);
    lo = (u32)param_1 & 0xff;
    mid = ((u32)param_1 & 0xff00) >> 8;
    hi = ((u32)param_1 & 0xffff0000) >> 0x10;
    FUN_005225a8_y2(DAT_006a4298, param_1, hi, mid, lo);
    FUN_001052b0_y2(DAT_006a4298, param_1, hi, mid, lo);
    index = fclCombine003cf8f0(param_1);
    if (index != -1) {
        base = *(s32*)(DAT_007ce680 + 0x24);
        mask = param_2 & 0xff00;
        offset = index * 0x14;
        entryAddress = offset + base;
        *(s16*)(entryAddress + 4) = *(s16*)(entryAddress + 4) | mask;
        FUN_005225a8_y2((char*)&DAT_007cd728, DAT_006a4270, 0x83);
        FUN_005225a8_y2(DAT_006a42b0, index);
        FUN_001052b0_y2(DAT_006a42b0, index);
        return 1;
    }
    return 0;
}
#pragma pop

// FUN_003cf3a0
s32 fclCombine003cf3a0(s32 param_1)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s16* entry;
    s32 i;
    s16 flags;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    i = 0;
    while (i < 3) {
        flags = *entry;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            if (param_1 != 0 && (flags & 0x100) != 0) {
                return *(s32*)(entry + 2);
            }
            if (param_1 == 0 && (flags & 0x100) == 0) {
                return *(s32*)(entry + 2);
            }
        }
        entry += 10;
        i++;
    }
    return 0;
}

// FUN_003cf440
void fclCombine003cf440(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 i;
    s16* entry;
    s16 flags;
    struct FclCombineNode* node;
    struct FclCombineNext* next;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0 || (flags & 2) != 0) {
                *entry |= 0x400;
            }
            if (FUN_0016f190(0x1419) == 0) {
                *entry |= 0x800;
            }
        }
        entry += 10;
    }
    node = (struct FclCombineNode*)*(s32*)(DAT_007ce680 + 4);
    while (node != 0) {
        next = *(struct FclCombineNext**)((u8*)node + 0x10);
        FUN_003c49e0_y2(DAT_007ce680, DAT_007ce680 + 4, (s32)node);
        node = (struct FclCombineNode*)(s32)next;
    }
}

// FUN_003cf520
void fclCombine003cf520(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 i;
    s16* entry;
    s16 flags;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0 || (flags & 2) != 0) {
                *entry |= 0x400;
            }
            if (FUN_0016f190(0x1419) == 0) {
                *entry |= 0x800;
            }
        }
        entry += 10;
    }
}

// FUN_003cf5d0
void fclCombine003cf5d0(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 i;
    s16 flags;
    s16* entry;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0 && (flags & 8) == 0) {
            *entry = flags | 0x800;
        }
        entry = entry + (10);
    }
}

// FUN_003cf630
s32 fclCombine003cf630(void)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 i;
    s16 flags;
    s16* entry;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    if (*(s32*)(DAT_007ce680 + 4) != 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0 && ((flags & 2) != 0 || (flags & 0x10) != 0)) {
            return 1;
        }
        entry = entry + (10);
    }
    return 0;
}
#pragma push
/* W389 sweep: opt_lifetimes on measured nd378/obj524 -> nd339/obj520 (window 560). */
#pragma opt_lifetimes on
/* W416 width audit: retail offsets 0x40/0x68/0x6c use 0x10 extension shifts; ours' corresponding pairs are at 0x48/0x4c and 0x70/0x74 with the same 0x10 shifts. Existing s16 sVar4 and (short)iVar6 casts already encode the candidate width; no edit was justified. */
// FUN_003CF6C0 NONMATCHING


short FUN_003cf6c0(int param_1)



{

  u16 uVar1;

  u16 *puVar2;

  u32 uVar3;

  short sVar4;

  short sVar5;

  int iVar6;

  u16 *puVar7;

  

  puVar7 = (u16 *)(*(int *)(DAT_007ce680_y2 + 0x24) + 4);

  for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

    if ((*puVar7 & 1) == 0) {

      sVar4 = (short)iVar6;

      goto LAB_003cf728;

    }

    puVar7 = puVar7 + 10;

  }

  sVar4 = -1;

LAB_003cf728:

  if (sVar4 == -1) {

    puVar7 = (u16 *)(*(int *)(DAT_007ce680_y2 + 0x24) + 4);

    for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

      uVar1 = *puVar7;

      if ((((uVar1 & 1) != 0) && ((uVar1 & 2) == 0)) && ((uVar1 & 8) == 0)) {

        sVar4 = (short)iVar6;

        goto LAB_003cf7a4;

      }

      puVar7 = puVar7 + 10;

    }

    sVar4 = -1;

  }

LAB_003cf7a4:

  FUN_005225a8(0x7cd728,0x6a4270,0x167);

  FUN_005225a8(0x6a42d8,sVar4);

  FUN_001052b0(0x6a42d8,sVar4);

  sVar5 = -1;

  if (sVar4 != -1) {

    puVar2 = *(u16 **)((int)param_1 + 0x14);

    iVar6 = *(int *)(DAT_007ce680_y2 + 0x24) + sVar4 * 0x14;

    puVar7 = (u16 *)(iVar6 + 4);

    *(u32 *)(iVar6 + 8) = *(u32 *)(puVar2 + 2);

    *(u16 *)(iVar6 + 4) = *puVar2;

    *(short *)(iVar6 + 0xc) = sVar4;

    uVar3 = *(u32 *)(iVar6 + 8);

    FUN_00106860(sVar4,(short)((u32)uVar3 >> 0x10),(u16)((u32)uVar3 >> 8) & 0xff,

                 (u16)uVar3 & 0xff);

    FUN_00106ec0(*(u16 *)(iVar6 + 0xc),1);

    FUN_00106f30(*(u16 *)(iVar6 + 0xc),0);

    *puVar7 = *puVar7 | 1;
    *puVar7 = *puVar7 | 2;

    FUN_003c49e0(DAT_007ce680_y2,DAT_007ce680_y2 + 4,param_1);

    sVar5 = sVar4;

  }

  return sVar5;

}
#pragma opt_lifetimes reset
#pragma pop
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#undef FUN_003cf960
// FUN_003cf8f0
s16 fclCombine003cf8f0(s32 param_1)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s32 i;
    s16* entry;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    i = 0;
    while (i < 3) {
        if ((*entry & 1) != 0 && *(s32*)(entry + 2) == param_1) {
            return (s16)i;
        }
        entry += 10;
        i++;
    }
    return -1;
}
// W414 MIXED probes: sVar2 u8/u16/s32 widened nd26 -> nd121; direct byte/cast and named-OR assignments measured nd118/119 or unchanged; reverted.
// W419 negative: DAT_007ce680_y2 array/absolute alias changed FUN_003cf960 nd26/object340 to nd210/object344 (window352); reverted.
// FUN_003CF960 NONMATCHING


u32 FUN_003cf960(int param_1,short param_2)
{
  u32 uVar3;
  int iVar6;
  short *puVar4;
  short sVar2;
  short sVar5;

  puVar4 = (short *)(*(int *)(DAT_007ce680_y2 + 0x24) + 4);
  for (iVar6 = 0; iVar6 < 3; iVar6++) {
    if (((*puVar4 & 1) != 0) && (*(int *)(puVar4 + 2) == param_1)) {
      sVar5 = (short)iVar6;
      goto LAB_003cf9d8;
    }
    puVar4 += 10;
  }
  sVar5 = -1;

LAB_003cf9d8:
  if (sVar5 != -1) {
    puVar4 = (short *)(*(int *)(DAT_007ce680_y2 + 0x24) + sVar5 * 0x14);
    sVar2 = *(u8 *)(puVar4 + 2);
    puVar4[2] = sVar2;
    puVar4[2] = (param_2 & 0xff00) | sVar2;
    FUN_005225a8(&DAT_007cd728,DAT_006a4270,0x1b6);
    FUN_005225a8(DAT_006a42f0,sVar5);
    FUN_001052b0(DAT_006a42f0,sVar5);
    return 0;
  }

  uVar3 = FUN_003c4910(DAT_007ce680_y2,0,0x14);
  puVar4 = *(short **)((int)uVar3 + 0x14);
  *(int *)(puVar4 + 2) = param_1;
  *puVar4 = param_2 & 0xff00 | 3;
  return uVar3;
}
#define FUN_003cf960(...) ((u32 (*)(...))FUN_003cf960)(__VA_ARGS__)
#undef FUN_003cfb50
// FUN_003cfac0
s32 fclCombine003cfac0(s16* param_1)
{
    extern s32 DAT_007ce680;
    extern void* DAT_0096017c_y2[];
    extern char DAT_006a4208[];
    extern char DAT_006a4288[];
    extern char DAT_006a4298[];
    extern char DAT_006a42b0[];
    s32 FUN_00316f70_y2(s32 param_1);
    s32 FUN_00194b20_y2();
    void FUN_003174e0_y2(s32 param_1);
    void FUN_005225a8_y2();
    void FUN_001052b0_y2();
    s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
    s32 FUN_0016f190(s32 param_1);
    void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
    s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
    s16 fclCombine003cf8f0(s32 param_1);
    s32 ret;
    s16* entry;
    s32 i;
    s16 flags;

    ret = 1;
    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        if (entry != param_1) {
            flags = *entry;
            if ((flags & 1) != 0 && (flags & 8) != 0 && (flags & 0x100) == (*param_1 & 0x100)) {
                *entry = flags | 0x400;
                if ((*entry & 4) == 0) {
                    ret = 0;
                }
            }
        }
        entry += 10;
    }
    return ret;
}
// FUN_003CFB50 NONMATCHING


void FUN_003cfb50(void)



{

  u16 uVar1;

  float *pfVar2;

  float *pfVar3;

  u16 uVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  u16 *puVar8;

  FclMiscPair stackPair;

  

  puVar8 = (u16 *)(*(int *)(DAT_007ce680_y2 + 0x24) + 4);

  iVar7 = 0;

  do {

    if (2 < iVar7) {

      return;

    }

    if ((*puVar8 & 1) != 0) {

      switch(puVar8[1]) {

      case 1:

        puVar8[1] = 2;

        uVar1 = *puVar8;

        *puVar8 = uVar1 | 8;

        *puVar8 = uVar1 | 0x18;

        *puVar8 = uVar1 & 0xfffb | 0x18;

        puVar8[8] = 0;

      case 2:

        puVar8[8] = puVar8[8] + 1;

        uVar1 = *puVar8;

        if ((uVar1 & 0x20) == 0) {

          if ((uVar1 & 0x100) == 0) {

            iVar6 = 0x120 - ((int)(short)puVar8[8] << 5) / 5;

          }

          else {

            iVar6 = ((int)(short)puVar8[8] << 5) / 5 + -0x9e;

          }

        }

        else if ((uVar1 & 0x100) == 0) {

          iVar6 = 0x100;

        }

        else {

          iVar6 = -0x7e;

        }

        pfVar3 = (float *)0x8;

        pfVar5 = &stackPair.vec.x;

        pfVar2 = pfVar5;

        while (pfVar2 != (float *)0x0) {

          *(u8 *)pfVar5 = 0;

          pfVar5 = (float *)((int)pfVar5 + 1);

          pfVar3 = (float *)((int)pfVar3 + -1);

          pfVar2 = pfVar3;

        }

        stackPair.vec.x = (float)iVar6;

        fclMisc106fb0Call(puVar8[4],stackPair.bits);

        FUN_00106e90(puVar8[4],((short)puVar8[8] * 0xff) / 5 & 0xff);

        FUN_00106f60(puVar8[4],0);

        if (4 < (short)puVar8[8]) {

          puVar8[8] = 0;

          uVar1 = *puVar8;

          *puVar8 = uVar1 | 4;

          *puVar8 = uVar1 & 0xffef | 4;

          puVar8[1] = 3;

        }

        break;

      case 3:

        FUN_00106f60(puVar8[4],0);

        break;

      case 4:

        puVar8[1] = 5;

        uVar1 = *puVar8;

        *puVar8 = uVar1 | 0x10;

        *puVar8 = uVar1 & 0xfffb | 0x10;

        puVar8[8] = 0;

      case 5:

        uVar1 = puVar8[8];

        puVar8[8] = uVar1 + 1;

        FUN_00106e90(puVar8[4],0xffU - ((short)(uVar1 + 1) * 0xff) / 5 & 0xff);

        FUN_00106f60(puVar8[4],0);

        if (4 < (short)puVar8[8]) {

          puVar8[8] = 0;

          uVar1 = *puVar8;

          uVar4 = uVar1 & 0xfff7;

          *puVar8 = uVar4;

          *puVar8 = uVar4 | 4;

          *puVar8 = uVar1 & 0xffe7 | 4;

          puVar8[1] = 0;

        }

      }

    }

    puVar8 = puVar8 + 10;

    iVar7 = iVar7 + 1;

  } while( 1 );

}
#define FUN_003cfb50(...) ((void (*)(...))FUN_003cfb50)(__VA_ARGS__)



extern void (*PTR_LAB_007bb510[])();
extern u32 uGpffffb994;
extern u32 DAT_006a4610;
extern u32 DAT_006a4614;
extern u32 DAT_006a4618;
#pragma alias DAT_006a4610_abs DAT_006a4610
extern u8 DAT_006a4610_abs[];
#pragma alias DAT_006a4614_abs DAT_006a4614
extern u8 DAT_006a4614_abs[];
#pragma alias DAT_006a4618_abs DAT_006a4618
extern u8 DAT_006a4618_abs[];
extern u8 DAT_006a4380[];
extern u8 DAT_006a4382[];
extern u8 DAT_006a4383[];
extern char *PTR_s_fcl_combine_pak_006a4384[];
extern u8 **PTR_FUN_006a4620;
extern u8 **PTR_FUN_006a46b0;
#pragma alias PTR_FUN_006a46b0_abs PTR_FUN_006a46b0
extern u8 PTR_FUN_006a46b0_abs[];
#pragma alias PTR_FUN_006a4620_abs PTR_FUN_006a4620
extern u8 PTR_FUN_006a4620_abs[];
extern u8 **PTR_FUN_006a46e0;
#pragma alias PTR_FUN_006a46e0_abs PTR_FUN_006a46e0
extern u8 PTR_FUN_006a46e0_abs[];
extern u8 **PTR_FUN_006a4870;
#pragma alias PTR_FUN_006a4870_abs PTR_FUN_006a4870
extern u8 PTR_FUN_006a4870_abs[];
extern u8 *PTR_FUN_006a48a0[];
extern char gp0xffffaa60[];
extern char gp0xffffaa68;
extern char gp0xffffaa70[];
extern char gp0xffffaa7c[];
extern char s_NORMAL_006a4730[];
extern char DAT_006a4710[];
extern u32 DAT_006a4810[];
extern u32 DAT_006a4830[];
extern float fGpffff830c;
extern float fGpffff8224;
extern f32 cosf(f32);
extern f32 sinf(f32);
extern void FUN_0040e3c0(f32, s32, s32, u8, s32, s32);
extern void FUN_0040e3f0(f32, f32, f32, f32, s32, s32, u8, s32, s32, s32, s32);
extern int iGpffffb730_y2;
extern int iGpffffb7f4;
extern int iGpffffb800;
extern void H_Dbprt_FmtLog(const char* fmt, ...);
extern float uGpffffaa78;
extern u8 DAT_007e094e;
extern u8 DAT_007e0958;
/* FUSION_PROTOS */
void FUN_003d06d0(s32 param_1,s32 param_2,s32 param_3);
void FUN_003d1df0(s32 param_1,int param_2);
u32 FUN_003d2200(void);
void FUN_003d25c0(u32 param_1);
u8 * FUN_003d2740(s32 param_1,u32 param_2);
u32 FUN_003d2c10(s32 param_1);
#pragma alias FUN_003d2f00_result FUN_003d2f00
extern s32 FUN_003d2f00_result(void);
u64 FUN_003d32e0(u64 param_1,u32 param_2);
void FUN_003d3760(int param_1,int param_2,int param_3);
void FUN_003d38b0(u64 param_1,int param_2,int param_3);
u32 FUN_003d3b70(u32 param_1,u32 param_2);
u8 * FUN_003d3d20(u64 param_1,u64 param_2);
u32 FUN_003d4de0(s32 param_1);
u8 * FUN_003d4ff0(u64 param_1,u32 param_2);
typedef int (*code)(...);
int FUN_003c5470(int task);
s32 FUN_003c5460(...);
u32 FUN_003c58f0(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
u32 FUN_003d84c0(void *param_1, s32 param_2);
s32 FUN_003f0830(s32 param_1);
s32 FUN_003f0ac0(s32 param_1);
s32 FUN_003c7850(void);
extern s32 DAT_007ce684;
extern char DAT_006b1fa0[];
void FUN_003db580(int param_1);
int FUN_0040c6f0(int param_1);
void FUN_0040c9a0(int param_1);
void FUN_00401420(int param_1, char* param_2);
s32 FUN_004014e0(int param_1);
void FUN_003c5a20(int param_1);
void FUN_003c6f10(int param_1);
void FUN_003c6f50(int param_1);
void FUN_003ded40(int param_1);
void FUN_003dff00(int param_1);
void FUN_0040cad0(int param_1);
void FUN_003deda0(int param_1);
s32 FUN_003dfac0(int param_1);
void FUN_003e0680(int param_1, void* param_2, s32 param_3);
void func_003d38b0(void);
void FUN_003e0650(int param_1);
void FUN_003ded70(int param_1);
s32 FUN_003c6270(int param_1);
s32 FUN_003df010(int param_1);
s32 FUN_003c6ce0(int param_1);
s32 FUN_003c6d10(int param_1);
s32 FUN_003c6ca0(int param_1);
s32 FUN_003c6cc0(int param_1);
void FUN_0010a4e0(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern u8 LAB_003c5170[];
extern s32 DAT_007ce680;
extern void* DAT_0096017c_y2[];
extern char DAT_006a4208[];
extern char DAT_006a4288[];
extern char DAT_006a4298[];
extern char DAT_006a42b0[];
extern char DAT_006a43b0[];
extern char DAT_006a43c0[];
extern char DAT_006a43d0[];
extern char DAT_006a4648[];
extern char gp0xffffaa38;

s32 FUN_00316f70_y2(s32 param_1);
s32 FUN_00194b20_y2();
void FUN_003174e0_y2(s32 param_1);
void FUN_005225a8_y2();
void FUN_001052b0_y2();
s32 FUN_003cf960_y2(s32 param_1, s32 param_2);
s32 FUN_0016f190(s32 param_1);
void FUN_003c49e0_y2(s32 param_1, s32 param_2, s32 param_3);
s32 FUN_003c44d0_y2(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
s32 FUN_003c5760(s32 param_1);
s32 FUN_003c5180(s32 param_1, s32 param_2);
s32 FUN_003dfeb0(s32 param_1);
short FUN_003d5cd0(void *param_1);
s32 FUN_003c5490(s32 param_1);
void FUN_0040e360(void);
void FUN_003c77a0(void);
void FUN_00100ec0_y2(s32 param_1);
void FUN_003c5220(s32 param_1);
s32 FUN_003c5240(s32 param_1, s32 param_2, void* param_3, s32 param_4, s32 param_5);
void FUN_003c5480(s32 param_1);
s32 FUN_003c6c50(s32 param_1);
s32 FUN_003c6c80(s32 param_1);
void FUN_003def80(s32 param_1);
u32 FUN_003c4e60(s32* param_1, s32* param_2);
void FUN_003c4de0(s32* param_1, s32* param_2, s32 param_3);
void FUN_003def10();
s32 FUN_003def40();
s32 FUN_003dee80();
void FUN_0019d3f0_y2(s32 param_1, s32 param_2);
void FUN_00521408_y2(s32 param_1, s32 param_2, s32 param_3);
void FUN_003c6f50(s32 param_1);

s16 fclCombine003cf8f0(s32 param_1);
s32 fclCombine003d03c0(void);
s32 fclCombine003d0400(void);
s32 fclCombine003d0470(void);
void fclCombine003d1df0(void);
void fclCombine003d2200(void);
void fclCombine003d0310(void);
s32 fclCombine003d04d0(void);
s32 fclCombine003d0600(void);
s32 fclCombine003d0610(void);
s32 fclCombine003d3050(s32 param_1);
s32 fclCombine003d3170(s32 param_1);
void fclCombine003d3280(s32 param_1);
void fclCombine003d3760(s32 param_1, s32 param_2, s32 param_3);







/* Removing this loses fclCombine003d03c0 (MATCH nd0 -> MISMATCH nd19) - measured W161. */


































// HARVESTED 3D-42FF

extern s32 DAT_006a43e0[];
extern s32 FUN_003dffc0(s32 param_1, s32 param_2, s32 param_3);
extern u32 fclCombineList003df100();

struct _m2c_stack_func_003d06d0 {
    /* 0x0030 */ s32 sp30;                          /* inferred */
    /* 0x0034 */ char pad34[0x14];                  /* maybe part of sp30[6]s32 */
    /* 0x0048 */ s16 sp48;                          /* inferred */
    /* 0x004A */ char pad4A[2];
    /* 0x004C */ s32 sp4C;                          /* inferred */
    /* 0x0050 */ char pad50[0x14];                  /* maybe part of sp4C[6]s32 */
    /* 0x0064 */ s16 sp64;                          /* inferred */
    /* 0x0066 */ char pad66[2];
    /* 0x0068 */ s32 sp68;                          /* inferred */
    /* 0x006C */ char pad6C[0x14];                  /* maybe part of sp68[6]s32 */
    /* 0x0080 */ s16 sp80;                          /* inferred */
    /* 0x0082 */ char pad82[2];
    /* 0x0084 */ s32 sp84;                          /* inferred */
    /* 0x0088 */ char pad88[0x14];                  /* maybe part of sp84[6]s32 */
    /* 0x009C */ s16 sp9C;                          /* inferred */
    /* 0x009E */ char pad9E[2];
    /* 0x00A0 */ s32 spA0;                          /* inferred */
    /* 0x00A4 */ char padA4[0x14];                  /* maybe part of spA0[6]s32 */
    /* 0x00B8 */ s16 spB8;                          /* inferred */
    /* 0x00BA */ char padBA[2];
    /* 0x00BC */ s32 spBC;                          /* inferred */
    /* 0x00C0 */ char padC0[0x14];                  /* maybe part of spBC[6]s32 */
    /* 0x00D4 */ s16 spD4;                          /* inferred */
    /* 0x00D6 */ char padD6[2];
    /* 0x00D8 */ s32 spD8;                          /* inferred */
    /* 0x00DC */ char padDC[0x14];                  /* maybe part of spD8[6]s32 */
    /* 0x00F0 */ s16 spF0;                          /* inferred */
    /* 0x00F2 */ char padF2[2];
    /* 0x00F4 */ s32 spF4;                          /* inferred */
    /* 0x00F8 */ char padF8[0x14];                  /* maybe part of spF4[6]s32 */
    /* 0x010C */ s16 sp10C;                         /* inferred */
    /* 0x010E */ char pad10E[2];
    /* 0x0110 */ s32 sp110;                         /* inferred */
    /* 0x0114 */ char pad114[0x14];                 /* maybe part of sp110[6]s32 */
    /* 0x0128 */ s16 sp128;                         /* inferred */
    /* 0x012A */ char pad12A[2];
    /* 0x012C */ s32 sp12C;                         /* inferred */
    /* 0x0130 */ char pad130[0x14];                 /* maybe part of sp12C[6]s32 */
    /* 0x0144 */ s16 sp144;                         /* inferred */
    /* 0x0146 */ char pad146[2];
    /* 0x0148 */ s32 sp148;                         /* inferred */
    /* 0x014C */ char pad14C[0x14];                 /* maybe part of sp148[6]s32 */
    /* 0x0160 */ s16 sp160;                         /* inferred */
    /* 0x0162 */ char pad162[2];
    /* 0x0164 */ s32 sp164;                         /* inferred */
    /* 0x0168 */ char pad168[0x14];                 /* maybe part of sp164[6]s32 */
    /* 0x017C */ s16 sp17C;                         /* inferred */
    /* 0x017E */ char pad17E[2];
    /* 0x0180 */ s32 sp180;                         /* inferred */
    /* 0x0184 */ char pad184[0x14];                 /* maybe part of sp180[6]s32 */
    /* 0x0198 */ s16 sp198;                         /* inferred */
    /* 0x019A */ char pad19A[2];
    /* 0x019C */ s32 sp19C;                         /* inferred */
    /* 0x01A0 */ char pad1A0[0x14];                 /* maybe part of sp19C[6]s32 */
    /* 0x01B4 */ s16 sp1B4;                         /* inferred */
    /* 0x01B6 */ char pad1B6[2];
    /* 0x01B8 */ s32 sp1B8;                         /* inferred */
    /* 0x01BC */ char pad1BC[0x14];                 /* maybe part of sp1B8[6]s32 */
    /* 0x01D0 */ s16 sp1D0;                         /* inferred */
    /* 0x01D2 */ char pad1D2[2];
    /* 0x01D4 */ s32 sp1D4;                         /* inferred */
    /* 0x01D8 */ char pad1D8[0x14];                 /* maybe part of sp1D4[6]s32 */
    /* 0x01EC */ s16 sp1EC;                         /* inferred */
    /* 0x01EE */ char pad1EE[2];
    /* 0x01F0 */ s32 sp1F0;                         /* inferred */
    /* 0x01F4 */ char pad1F4[0x14];                 /* maybe part of sp1F0[6]s32 */
    /* 0x0208 */ s16 sp208;                         /* inferred */
    /* 0x020A */ char pad20A[2];
    /* 0x020C */ s32 sp20C;                         /* inferred */
    /* 0x0210 */ char pad210[0x14];                 /* maybe part of sp20C[6]s32 */
    /* 0x0224 */ s16 sp224;                         /* inferred */
    /* 0x0226 */ char pad226[2];
    /* 0x0228 */ s32 sp228;                         /* inferred */
    /* 0x022C */ char pad22C[0x14];                 /* maybe part of sp228[6]s32 */
    /* 0x0240 */ s16 sp240;                         /* inferred */
    /* 0x0242 */ char pad242[2];
    /* 0x0244 */ s32 sp244;                         /* inferred */
    /* 0x0248 */ char pad248[0x14];                 /* maybe part of sp244[6]s32 */
    /* 0x025C */ s16 sp25C;                         /* inferred */
    /* 0x025E */ char pad25E[2];
    /* 0x0260 */ s32 sp260;                         /* inferred */
    /* 0x0264 */ char pad264[0x14];                 /* maybe part of sp260[6]s32 */
    /* 0x0278 */ s16 sp278;                         /* inferred */
    /* 0x027A */ char pad27A[2];
    /* 0x027C */ s32 sp27C;                         /* inferred */
    /* 0x0280 */ char pad280[0x14];                 /* maybe part of sp27C[6]s32 */
    /* 0x0294 */ s16 sp294;                         /* inferred */
    /* 0x0296 */ char pad296[2];
    /* 0x0298 */ s32 sp298;                         /* inferred */
    /* 0x029C */ char pad29C[0x14];                 /* maybe part of sp298[6]s32 */
    /* 0x02B0 */ s16 sp2B0;                         /* inferred */
    /* 0x02B2 */ char pad2B2[2];
    /* 0x02B4 */ s32 sp2B4;                         /* inferred */
    /* 0x02B8 */ char pad2B8[0x14];                 /* maybe part of sp2B4[6]s32 */
    /* 0x02CC */ s16 sp2CC;                         /* inferred */
    /* 0x02CE */ char pad2CE[2];
    /* 0x02D0 */ s32 sp2D0;                         /* inferred */
    /* 0x02D4 */ char pad2D4[0x14];                 /* maybe part of sp2D0[6]s32 */
    /* 0x02E8 */ s16 sp2E8;                         /* inferred */
    /* 0x02EA */ char pad2EA[2];
    /* 0x02EC */ s32 sp2EC;                         /* inferred */
    /* 0x02F0 */ char pad2F0[0x14];                 /* maybe part of sp2EC[6]s32 */
    /* 0x0304 */ s16 sp304;                         /* inferred */
    /* 0x0306 */ char pad306[2];
    /* 0x0308 */ s32 sp308;                         /* inferred */
    /* 0x030C */ char pad30C[0x14];                 /* maybe part of sp308[6]s32 */
    /* 0x0320 */ s16 sp320;                         /* inferred */
    /* 0x0322 */ char pad322[2];
    /* 0x0324 */ s32 sp324;                         /* inferred */
    /* 0x0328 */ char pad328[0x14];                 /* maybe part of sp324[6]s32 */
    /* 0x033C */ s16 sp33C;                         /* inferred */
    /* 0x033E */ char pad33E[2];
    /* 0x0340 */ s32 sp340;                         /* inferred */
    /* 0x0344 */ char pad344[0x14];                 /* maybe part of sp340[6]s32 */
    /* 0x0358 */ s16 sp358;                         /* inferred */
    /* 0x035A */ char pad35A[2];
    /* 0x035C */ s32 sp35C;                         /* inferred */
    /* 0x0360 */ char pad360[0x14];                 /* maybe part of sp35C[6]s32 */
    /* 0x0374 */ s16 sp374;                         /* inferred */
    /* 0x0376 */ char pad376[2];
    /* 0x0378 */ s32 sp378;                         /* inferred */
    /* 0x037C */ char pad37C[0x14];                 /* maybe part of sp378[6]s32 */
    /* 0x0390 */ s16 sp390;                         /* inferred */
    /* 0x0392 */ char pad392[2];
    /* 0x0394 */ s32 sp394;                         /* inferred */
    /* 0x0398 */ char pad398[0x14];                 /* maybe part of sp394[6]s32 */
    /* 0x03AC */ s16 sp3AC;                         /* inferred */
    /* 0x03AE */ char pad3AE[2];
    /* 0x03B0 */ s32 sp3B0;                         /* inferred */
    /* 0x03B4 */ char pad3B4[0x14];                 /* maybe part of sp3B0[6]s32 */
    /* 0x03C8 */ s16 sp3C8;                         /* inferred */
    /* 0x03CA */ char pad3CA[2];
    /* 0x03CC */ s32 sp3CC;                         /* inferred */
    /* 0x03D0 */ char pad3D0[0x14];                 /* maybe part of sp3CC[6]s32 */
    /* 0x03E4 */ s16 sp3E4;                         /* inferred */
    /* 0x03E6 */ char pad3E6[2];
    /* 0x03E8 */ s32 sp3E8;                         /* inferred */
    /* 0x03EC */ char pad3EC[0x14];                 /* maybe part of sp3E8[6]s32 */
    /* 0x0400 */ s16 sp400;                         /* inferred */
    /* 0x0402 */ char pad402[2];
    /* 0x0404 */ s32 sp404;                         /* inferred */
    /* 0x0408 */ char pad408[0x14];                 /* maybe part of sp404[6]s32 */
    /* 0x041C */ s16 sp41C;                         /* inferred */
    /* 0x041E */ char pad41E[2];
    /* 0x0420 */ s32 sp420;                         /* inferred */
    /* 0x0424 */ char pad424[0x14];                 /* maybe part of sp420[6]s32 */
    /* 0x0438 */ s16 sp438;                         /* inferred */
    /* 0x043A */ char pad43A[2];
    /* 0x043C */ s32 sp43C;                         /* inferred */
    /* 0x0440 */ char pad440[0x14];                 /* maybe part of sp43C[6]s32 */
    /* 0x0454 */ s16 sp454;                         /* inferred */
    /* 0x0456 */ char pad456[2];
    /* 0x0458 */ s32 sp458;                         /* inferred */
    /* 0x045C */ char pad45C[0x14];                 /* maybe part of sp458[6]s32 */
    /* 0x0470 */ s16 sp470;                         /* inferred */
    /* 0x0472 */ char pad472[2];
    /* 0x0474 */ s32 sp474;                         /* inferred */
    /* 0x0478 */ char pad478[0x14];                 /* maybe part of sp474[6]s32 */
    /* 0x048C */ s16 sp48C;                         /* inferred */
    /* 0x048E */ char pad48E[2];
    /* 0x0490 */ s32 sp490;                         /* inferred */
    /* 0x0494 */ char pad494[0x14];                 /* maybe part of sp490[6]s32 */
    /* 0x04A8 */ s16 sp4A8;                         /* inferred */
    /* 0x04AA */ char pad4AA[2];
    /* 0x04AC */ s32 sp4AC;                         /* inferred */
    /* 0x04B0 */ char pad4B0[0x14];                 /* maybe part of sp4AC[6]s32 */
    /* 0x04C4 */ s16 sp4C4;                         /* inferred */
    /* 0x04C6 */ char pad4C6[2];
    /* 0x04C8 */ s32 sp4C8;                         /* inferred */
    /* 0x04CC */ char pad4CC[0x14];                 /* maybe part of sp4C8[6]s32 */
    /* 0x04E0 */ s16 sp4E0;                         /* inferred */
    /* 0x04E2 */ char pad4E2[2];
    /* 0x04E4 */ s32 sp4E4;                         /* inferred */
    /* 0x04E8 */ char pad4E8[0x14];                 /* maybe part of sp4E4[6]s32 */
    /* 0x04FC */ s16 sp4FC;                         /* inferred */
    /* 0x04FE */ char pad4FE[2];
    /* 0x0500 */ s32 sp500;                         /* inferred */
    /* 0x0504 */ char pad504[0x14];                 /* maybe part of sp500[6]s32 */
    /* 0x0518 */ s16 sp518;                         /* inferred */
    /* 0x051A */ char pad51A[2];
    /* 0x051C */ s32 sp51C;                         /* inferred */
    /* 0x0520 */ char pad520[0x14];                 /* maybe part of sp51C[6]s32 */
    /* 0x0534 */ s16 sp534;                         /* inferred */
    /* 0x0536 */ char pad536[2];
    /* 0x0538 */ s32 sp538;                         /* inferred */
    /* 0x053C */ char pad53C[0x14];                 /* maybe part of sp538[6]s32 */
    /* 0x0550 */ s16 sp550;                         /* inferred */
    /* 0x0552 */ char pad552[2];
    /* 0x0554 */ s32 sp554;                         /* inferred */
    /* 0x0558 */ char pad558[0x14];                 /* maybe part of sp554[6]s32 */
    /* 0x056C */ s16 sp56C;                         /* inferred */
    /* 0x056E */ char pad56E[2];
    /* 0x0570 */ s32 sp570;                         /* inferred */
    /* 0x0574 */ char pad574[0x14];                 /* maybe part of sp570[6]s32 */
    /* 0x0588 */ s16 sp588;                         /* inferred */
    /* 0x058A */ char pad58A[2];
    /* 0x058C */ s32 sp58C;                         /* inferred */
    /* 0x0590 */ char pad590[0x14];                 /* maybe part of sp58C[6]s32 */
    /* 0x05A4 */ s16 sp5A4;                         /* inferred */
    /* 0x05A6 */ char pad5A6[2];
    /* 0x05A8 */ s32 sp5A8;                         /* inferred */
    /* 0x05AC */ char pad5AC[0x14];                 /* maybe part of sp5A8[6]s32 */
    /* 0x05C0 */ s16 sp5C0;                         /* inferred */
    /* 0x05C2 */ char pad5C2[2];
    /* 0x05C4 */ s32 sp5C4;                         /* inferred */
    /* 0x05C8 */ char pad5C8[0x14];                 /* maybe part of sp5C4[6]s32 */
    /* 0x05DC */ s16 sp5DC;                         /* inferred */
    /* 0x05DE */ char pad5DE[2];
    /* 0x05E0 */ s32 sp5E0;                         /* inferred */
    /* 0x05E4 */ char pad5E4[0x14];                 /* maybe part of sp5E0[6]s32 */
    /* 0x05F8 */ s16 sp5F8;                         /* inferred */
    /* 0x05FA */ char pad5FA[2];
    /* 0x05FC */ s32 sp5FC;                         /* inferred */
    /* 0x0600 */ char pad600[0x14];                 /* maybe part of sp5FC[6]s32 */
    /* 0x0614 */ s16 sp614;                         /* inferred */
    /* 0x0616 */ char pad616[2];
    /* 0x0618 */ s32 sp618;                         /* inferred */
    /* 0x061C */ char pad61C[0x14];                 /* maybe part of sp618[6]s32 */
    /* 0x0630 */ s16 sp630;                         /* inferred */
    /* 0x0632 */ char pad632[2];
    /* 0x0634 */ s32 sp634;                         /* inferred */
    /* 0x0638 */ char pad638[0x14];                 /* maybe part of sp634[6]s32 */
    /* 0x064C */ s16 sp64C;                         /* inferred */
    /* 0x064E */ char pad64E[2];
    /* 0x0650 */ s32 sp650;                         /* inferred */
    /* 0x0654 */ char pad654[0x14];                 /* maybe part of sp650[6]s32 */
    /* 0x0668 */ s16 sp668;                         /* inferred */
    /* 0x066A */ char pad66A[2];
    /* 0x066C */ s32 sp66C;                         /* inferred */
    /* 0x0670 */ char pad670[0x14];                 /* maybe part of sp66C[6]s32 */
    /* 0x0684 */ s16 sp684;                         /* inferred */
    /* 0x0686 */ char pad686[2];
    /* 0x0688 */ s32 sp688;                         /* inferred */
    /* 0x068C */ char pad68C[0x14];                 /* maybe part of sp688[6]s32 */
    /* 0x06A0 */ s16 sp6A0;                         /* inferred */
    /* 0x06A2 */ char pad6A2[2];
    /* 0x06A4 */ s32 sp6A4;                         /* inferred */
    /* 0x06A8 */ char pad6A8[0x14];                 /* maybe part of sp6A4[6]s32 */
    /* 0x06BC */ s16 sp6BC;                         /* inferred */
    /* 0x06BE */ char pad6BE[2];
    /* 0x06C0 */ s32 sp6C0;                         /* inferred */
    /* 0x06C4 */ char pad6C4[0x14];                 /* maybe part of sp6C0[6]s32 */
    /* 0x06D8 */ s16 sp6D8;                         /* inferred */
    /* 0x06DA */ char pad6DA[2];
    /* 0x06DC */ s32 sp6DC;                         /* inferred */
    /* 0x06E0 */ char pad6E0[0x14];                 /* maybe part of sp6DC[6]s32 */
    /* 0x06F4 */ s16 sp6F4;                         /* inferred */
    /* 0x06F6 */ char pad6F6[2];
    /* 0x06F8 */ s32 sp6F8;                         /* inferred */
    /* 0x06FC */ char pad6FC[0x14];                 /* maybe part of sp6F8[6]s32 */
    /* 0x0710 */ s16 sp710;                         /* inferred */
    /* 0x0712 */ char pad712[2];
    /* 0x0714 */ s32 sp714;                         /* inferred */
    /* 0x0718 */ char pad718[0x14];                 /* maybe part of sp714[6]s32 */
    /* 0x072C */ s16 sp72C;                         /* inferred */
    /* 0x072E */ char pad72E[2];
    /* 0x0730 */ s32 sp730;                         /* inferred */
    /* 0x0734 */ char pad734[0x14];                 /* maybe part of sp730[6]s32 */
    /* 0x0748 */ s16 sp748;                         /* inferred */
    /* 0x074A */ char pad74A[2];
    /* 0x074C */ s32 sp74C;                         /* inferred */
    /* 0x0750 */ char pad750[0x14];                 /* maybe part of sp74C[6]s32 */
    /* 0x0764 */ s16 sp764;                         /* inferred */
    /* 0x0766 */ char pad766[2];
    /* 0x0768 */ s32 sp768;                         /* inferred */
    /* 0x076C */ char pad76C[0x14];                 /* maybe part of sp768[6]s32 */
    /* 0x0780 */ s16 sp780;                         /* inferred */
    /* 0x0782 */ char pad782[2];
    /* 0x0784 */ s32 sp784;                         /* inferred */
    /* 0x0788 */ char pad788[0x14];                 /* maybe part of sp784[6]s32 */
    /* 0x079C */ s16 sp79C;                         /* inferred */
    /* 0x079E */ char pad79E[2];
    /* 0x07A0 */ s32 sp7A0;                         /* inferred */
    /* 0x07A4 */ char pad7A4[0x14];                 /* maybe part of sp7A0[6]s32 */
    /* 0x07B8 */ s16 sp7B8;                         /* inferred */
    /* 0x07BA */ char pad7BA[2];
    /* 0x07BC */ s32 sp7BC;                         /* inferred */
    /* 0x07C0 */ char pad7C0[0x14];                 /* maybe part of sp7BC[6]s32 */
    /* 0x07D4 */ s16 sp7D4;                         /* inferred */
    /* 0x07D6 */ char pad7D6[2];
    /* 0x07D8 */ s32 sp7D8;                         /* inferred */
    /* 0x07DC */ char pad7DC[0x14];                 /* maybe part of sp7D8[6]s32 */
    /* 0x07F0 */ s16 sp7F0;                         /* inferred */
    /* 0x07F2 */ char pad7F2[2];
    /* 0x07F4 */ s32 sp7F4;                         /* inferred */
    /* 0x07F8 */ char pad7F8[0x14];                 /* maybe part of sp7F4[6]s32 */
    /* 0x080C */ s16 sp80C;                         /* inferred */
    /* 0x080E */ char pad80E[2];
    /* 0x0810 */ s32 sp810;                         /* inferred */
    /* 0x0814 */ char pad814[0x14];                 /* maybe part of sp810[6]s32 */
    /* 0x0828 */ s16 sp828;                         /* inferred */
    /* 0x082A */ char pad82A[2];
    /* 0x082C */ s32 sp82C;                         /* inferred */
    /* 0x0830 */ char pad830[0x14];                 /* maybe part of sp82C[6]s32 */
    /* 0x0844 */ s16 sp844;                         /* inferred */
    /* 0x0846 */ char pad846[2];
    /* 0x0848 */ s32 sp848;                         /* inferred */
    /* 0x084C */ char pad84C[0x14];                 /* maybe part of sp848[6]s32 */
    /* 0x0860 */ s16 sp860;                         /* inferred */
    /* 0x0862 */ char pad862[2];
    /* 0x0864 */ s32 sp864;                         /* inferred */
    /* 0x0868 */ char pad868[0x14];                 /* maybe part of sp864[6]s32 */
    /* 0x087C */ s16 sp87C;                         /* inferred */
    /* 0x087E */ char pad87E[2];
    /* 0x0880 */ s32 sp880;                         /* inferred */
    /* 0x0884 */ char pad884[0x14];                 /* maybe part of sp880[6]s32 */
    /* 0x0898 */ s16 sp898;                         /* inferred */
    /* 0x089A */ char pad89A[2];
    /* 0x089C */ s32 sp89C;                         /* inferred */
    /* 0x08A0 */ char pad8A0[0x14];                 /* maybe part of sp89C[6]s32 */
    /* 0x08B4 */ s16 sp8B4;                         /* inferred */
    /* 0x08B6 */ char pad8B6[2];
    /* 0x08B8 */ s32 sp8B8;                         /* inferred */
    /* 0x08BC */ char pad8BC[0x14];                 /* maybe part of sp8B8[6]s32 */
    /* 0x08D0 */ s16 sp8D0;                         /* inferred */
    /* 0x08D2 */ char pad8D2[2];
    /* 0x08D4 */ s32 sp8D4;                         /* inferred */
    /* 0x08D8 */ char pad8D8[0x14];                 /* maybe part of sp8D4[6]s32 */
    /* 0x08EC */ s16 sp8EC;                         /* inferred */
    /* 0x08EE */ char pad8EE[2];
    /* 0x08F0 */ s32 sp8F0;
    /* 0x08F4 */ char pad8F4[0x14];
    /* 0x0908 */ s16 sp908;
    /* 0x090A */ char pad90A[2];
    /* 0x090C */ s32 sp90C;
    /* 0x0910 */ char pad910[0x14];
    /* 0x0924 */ s16 sp924;
    /* 0x0926 */ char pad926[2];
    /* 0x0928 */ s32 sp928;
    /* 0x092C */ char pad92C[0x14];
    /* 0x0940 */ s16 sp940;
    /* 0x0942 */ char pad942[2];
    /* 0x0944 */ s32 sp944;
    /* 0x0948 */ char pad948[0x14];
    /* 0x095C */ s16 sp95C;
    /* 0x095E */ char pad95E[2];
    /* 0x0960 */ s32 sp960;
    /* 0x0964 */ char pad964[0x14];
    /* 0x0978 */ s16 sp978;
    /* 0x097A */ char pad97A[2];
    /* 0x097C */ s32 sp97C;
    /* 0x0980 */ char pad980[0x14];
    /* 0x0994 */ s16 sp994;
    /* 0x0996 */ char pad996[2];
    /* 0x0998 */ s32 sp998;
    /* 0x099C */ char pad99C[0x14];
    /* 0x09B0 */ s16 sp9B0;
    /* 0x09B2 */ char pad9B2[2];
    /* 0x09B4 */ s32 sp9B4;
    /* 0x09B8 */ char pad9B8[0x14];
    /* 0x09CC */ s16 sp9CC;
    /* 0x09CE */ char pad9CE[2];
    /* 0x09D0 */ s32 sp9D0;
    /* 0x09D4 */ char pad9D4[0x14];
    /* 0x09E8 */ s16 sp9E8;
    /* 0x09EA */ char pad9EA[2];
    /* 0x09EC */ s32 sp9EC;
    /* 0x09F0 */ char pad9F0[0x14];
    /* 0x0A04 */ s16 spA04;
    /* 0x0A06 */ char padA06[2];
    /* 0x0A08 */ s32 spA08;
    /* 0x0A0C */ char padA0C[0x14];
    /* 0x0A20 */ s16 spA20;
    /* 0x0A22 */ char padA22[2];
    /* 0x0A24 */ s32 spA24;
    /* 0x0A28 */ char padA28[0x14];
    /* 0x0A3C */ s16 spA3C;
    /* 0x0A3E */ char padA3E[2];
    /* 0x0A40 */ s32 spA40;
    /* 0x0A44 */ char padA44[0x14];
    /* 0x0A58 */ s16 spA58;
    /* 0x0A5A */ char padA5A[2];
    /* 0x0A5C */ s32 spA5C;
    /* 0x0A60 */ char padA60[0x14];
    /* 0x0A74 */ s16 spA74;
    /* 0x0A76 */ char padA76[2];
    /* 0x0A78 */ s32 spA78;
    /* 0x0A7C */ char padA7C[0x14];
    /* 0x0A90 */ s16 spA90;
    /* 0x0A92 */ char padA92[2];
    /* 0x0A94 */ s32 spA94;
    /* 0x0A98 */ char padA98[0x14];
    /* 0x0AAC */ s16 spAAC;
    /* 0x0AAE */ char padAAE[2];
    /* 0x0AB0 */ s32 spAB0;
    /* 0x0AB4 */ char padAB4[0x14];
    /* 0x0AC8 */ s16 spAC8;
    /* 0x0ACA */ char padACA[2];
    /* 0x0ACC */ s32 spACC;
    /* 0x0AD0 */ char padAD0[0x14];
    /* 0x0AE4 */ s16 spAE4;
    /* 0x0AE6 */ char padAE6[2];
    /* 0x0AE8 */ s32 spAE8;
    /* 0x0AEC */ char padAEC[0x14];
    /* 0x0B00 */ s16 spB00;
    /* 0x0B02 */ char padB02[2];
    /* 0x0B04 */ s32 spB04;
    /* 0x0B08 */ char padB08[0x14];
    /* 0x0B1C */ s16 spB1C;
    /* 0x0B1E */ char padB1E[2];
    /* 0x0B20 */ s32 spB20;
    /* 0x0B24 */ char padB24[0x14];
    /* 0x0B38 */ s16 spB38;
    /* 0x0B3A */ char padB3A[2];
    /* 0x0B3C */ s32 spB3C;
    /* 0x0B40 */ char padB40[0x14];
    /* 0x0B54 */ s16 spB54;
    /* 0x0B56 */ char padB56[2];
    /* 0x0B58 */ s32 spB58;
    /* 0x0B5C */ char padB5C[0x14];
    /* 0x0B70 */ s16 spB70;
    /* 0x0B72 */ char padB72[2];
    /* 0x0B74 */ s32 spB74;
    /* 0x0B78 */ char padB78[0x14];
    /* 0x0B8C */ s16 spB8C;
    /* 0x0B8E */ char padB8E[2];
    /* 0x0B90 */ s32 spB90;
    /* 0x0B94 */ char padB94[0x14];
    /* 0x0BA8 */ s16 spBA8;
    /* 0x0BAA */ char padBAA[2];
    /* 0x0BAC */ s32 spBAC;
    /* 0x0BB0 */ char padBB0[0x14];
    /* 0x0BC4 */ s16 spBC4;
    /* 0x0BC6 */ char padBC6[2];
    /* 0x0BC8 */ s32 spBC8;
    /* 0x0BCC */ char padBCC[0x14];
    /* 0x0BE0 */ s16 spBE0;
    /* 0x0BE2 */ char padBE2[2];
    /* 0x0BE4 */ s32 spBE4;
    /* 0x0BE8 */ char padBE8[0x14];
    /* 0x0BFC */ s16 spBFC;
    /* 0x0BFE */ char padBFE[2];
    /* 0x0C00 */ s32 spC00;
    /* 0x0C04 */ char padC04[0x14];
    /* 0x0C18 */ s16 spC18;
    /* 0x0C1A */ char padC1A[2];
    /* 0x0C1C */ s32 spC1C;
    /* 0x0C20 */ char padC20[0x14];
    /* 0x0C34 */ s16 spC34;
    /* 0x0C36 */ char padC36[2];
    /* 0x0C38 */ s32 spC38;
    /* 0x0C3C */ char padC3C[0x14];
    /* 0x0C50 */ s16 spC50;
    /* 0x0C52 */ char padC52[2];
    /* 0x0C54 */ s32 spC54;
    /* 0x0C58 */ char padC58[0x14];
    /* 0x0C6C */ s16 spC6C;
    /* 0x0C6E */ char padC6E[2];
    /* 0x0C70 */ s32 spC70;
    /* 0x0C74 */ char padC74[0x14];
    /* 0x0C88 */ s16 spC88;
    /* 0x0C8A */ char padC8A[2];
    /* 0x0C8C */ s32 spC8C;
    /* 0x0C90 */ char padC90[0x14];
    /* 0x0CA4 */ s16 spCA4;
    /* 0x0CA6 */ char padCA6[2];
    /* 0x0CA8 */ s32 spCA8;
    /* 0x0CAC */ char padCAC[0x14];
    /* 0x0CC0 */ s16 spCC0;
    /* 0x0CC2 */ char padCC2[2];
    /* 0x0CC4 */ s32 spCC4;
    /* 0x0CC8 */ char padCC8[0x14];
    /* 0x0CDC */ s16 spCDC;
    /* 0x0CDE */ char padCDE[2];
    /* 0x0CE0 */ s32 spCE0;
    /* 0x0CE4 */ char padCE4[0x14];
    /* 0x0CF8 */ s16 spCF8;
    /* 0x0CFA */ char padCFA[2];
    /* 0x0CFC */ s32 spCFC;
    /* 0x0D00 */ char padD00[0x14];
    /* 0x0D14 */ s16 spD14;
    /* 0x0D16 */ char padD16[2];
    /* 0x0D18 */ s32 spD18;
    /* 0x0D1C */ char padD1C[0x14];
    /* 0x0D30 */ s16 spD30;
    /* 0x0D32 */ char padD32[2];
    /* 0x0D34 */ s32 spD34;
    /* 0x0D38 */ char padD38[0x14];
    /* 0x0D4C */ s16 spD4C;
    /* 0x0D4E */ char padD4E[2];
    /* 0x0D50 */ s32 spD50;                         /* inferred */
    /* 0x0D54 */ char padD54[0x14];                 /* maybe part of spD50[6]s32 */
    /* 0x0D68 */ s16 spD68;                         /* inferred */
    /* 0x0D6A */ char padD6A[2];
    /* 0x0D6C */ s32 spD6C;                         /* inferred */
    /* 0x0D70 */ char padD70[0x14];                 /* maybe part of spD6C[6]s32 */
    /* 0x0D84 */ s16 spD84;                         /* inferred */
    /* 0x0D86 */ char padD86[2];
    /* 0x0D88 */ s32 spD88;                         /* inferred */
    /* 0x0D8C */ char padD8C[0x14];                 /* maybe part of spD88[6]s32 */
    /* 0x0DA0 */ s16 spDA0;                         /* inferred */
    /* 0x0DA2 */ char padDA2[2];
    /* 0x0DA4 */ s32 spDA4;                         /* inferred */
    /* 0x0DA8 */ char padDA8[0x14];                 /* maybe part of spDA4[6]s32 */
    /* 0x0DBC */ s16 spDBC;                         /* inferred */
    /* 0x0DBE */ char padDBE[2];
    /* 0x0DC0 */ s32 spDC0;                         /* inferred */
    /* 0x0DC4 */ char padDC4[0x14];                 /* maybe part of spDC0[6]s32 */
    /* 0x0DD8 */ s16 spDD8;                         /* inferred */
    /* 0x0DDA */ char padDDA[2];
    /* 0x0DDC */ s32 spDDC;                         /* inferred */
    /* 0x0DE0 */ char padDE0[0x14];                 /* maybe part of spDDC[6]s32 */
    /* 0x0DF4 */ s16 spDF4;                         /* inferred */
    /* 0x0DF6 */ char padDF6[2];
    /* 0x0DF8 */ s32 spDF8;                         /* inferred */
    /* 0x0DFC */ char padDFC[0x14];                 /* maybe part of spDF8[6]s32 */
    /* 0x0E10 */ s16 spE10;                         /* inferred */
    /* 0x0E12 */ char padE12[2];
    /* 0x0E14 */ s32 spE14;                         /* inferred */
    /* 0x0E18 */ char padE18[0x14];                 /* maybe part of spE14[6]s32 */
    /* 0x0E2C */ s16 spE2C;                         /* inferred */
    /* 0x0E2E */ char padE2E[2];
    /* 0x0E30 */ s32 spE30;                         /* inferred */
    /* 0x0E34 */ char padE34[0x14];                 /* maybe part of spE30[6]s32 */
    /* 0x0E48 */ s16 spE48;                         /* inferred */
    /* 0x0E4A */ char padE4A[2];
    /* 0x0E4C */ s32 spE4C;                         /* inferred */
    /* 0x0E50 */ char padE50[0x14];                 /* maybe part of spE4C[6]s32 */
    /* 0x0E64 */ s16 spE64;                         /* inferred */
    /* 0x0E66 */ char padE66[2];
    /* 0x0E68 */ s32 spE68;                         /* inferred */
    /* 0x0E6C */ char padE6C[0x14];                 /* maybe part of spE68[6]s32 */
    /* 0x0E80 */ s16 spE80;                         /* inferred */
    /* 0x0E82 */ char padE82[2];
    /* 0x0E84 */ s32 spE84;                         /* inferred */
    /* 0x0E88 */ char padE88[0x14];                 /* maybe part of spE84[6]s32 */
    /* 0x0E9C */ s16 spE9C;                         /* inferred */
    /* 0x0E9E */ char padE9E[2];
    /* 0x0EA0 */ s32 spEA0;                         /* inferred */
    /* 0x0EA4 */ char padEA4[0x14];                 /* maybe part of spEA0[6]s32 */
    /* 0x0EB8 */ s16 spEB8;                         /* inferred */
    /* 0x0EBA */ char padEBA[2];
    /* 0x0EBC */ s32 spEBC;                         /* inferred */
    /* 0x0EC0 */ char padEC0[0x14];                 /* maybe part of spEBC[6]s32 */
    /* 0x0ED4 */ s16 spED4;                         /* inferred */
    /* 0x0ED6 */ char padED6[2];
    /* 0x0ED8 */ s32 spED8;                         /* inferred */
    /* 0x0EDC */ char padEDC[0x14];                 /* maybe part of spED8[6]s32 */
    /* 0x0EF0 */ s16 spEF0;                         /* inferred */
    /* 0x0EF2 */ char padEF2[2];
    /* 0x0EF4 */ s32 spEF4;                         /* inferred */
    /* 0x0EF8 */ char padEF8[0x14];                 /* maybe part of spEF4[6]s32 */
    /* 0x0F0C */ s16 spF0C;                         /* inferred */
    /* 0x0F0E */ char padF0E[2];
    /* 0x0F10 */ s32 spF10;                         /* inferred */
    /* 0x0F14 */ char padF14[0x14];                 /* maybe part of spF10[6]s32 */
    /* 0x0F28 */ s16 spF28;                         /* inferred */
    /* 0x0F2A */ char padF2A[2];
    /* 0x0F2C */ s32 spF2C;                         /* inferred */
    /* 0x0F30 */ char padF30[0x14];                 /* maybe part of spF2C[6]s32 */
    /* 0x0F44 */ s16 spF44;                         /* inferred */
    /* 0x0F46 */ char padF46[2];
    /* 0x0F48 */ s32 spF48;                         /* inferred */
    /* 0x0F4C */ char padF4C[0x14];                 /* maybe part of spF48[6]s32 */
    /* 0x0F60 */ s16 spF60;                         /* inferred */
    /* 0x0F62 */ char padF62[2];
    /* 0x0F64 */ s32 spF64;                         /* inferred */
    /* 0x0F68 */ char padF68[0x14];                 /* maybe part of spF64[6]s32 */
    /* 0x0F7C */ s16 spF7C;                         /* inferred */
    /* 0x0F7E */ char padF7E[2];
    /* 0x0F80 */ s32 spF80;
    /* 0x0F84 */ char padF84[0x14];
    /* 0x0F98 */ s16 spF98;
    /* 0x0F9A */ char padF9A[2];
    /* 0x0F9C */ s32 spF9C;
    /* 0x0FA0 */ char padFA0[0x14];
    /* 0x0FB4 */ s16 spFB4;
    /* 0x0FB6 */ char padFB6[2];
    /* 0x0FB8 */ s32 spFB8;
    /* 0x0FBC */ char padFBC[0x14];
    /* 0x0FD0 */ s16 spFD0;
    /* 0x0FD2 */ char padFD2[2];
    /* 0x0FD4 */ s32 spFD4;
    /* 0x0FD8 */ char padFD8[0x14];
    /* 0x0FEC */ s16 spFEC;
    /* 0x0FEE */ char padFEE[2];
    /* 0x0FF0 */ s32 spFF0;
    /* 0x0FF4 */ char padFF4[0x14];
    /* 0x1008 */ s16 sp1008;
    /* 0x100A */ char pad100A[2];
    /* 0x100C */ s32 sp100C;
    /* 0x1010 */ char pad1010[0x14];
    /* 0x1024 */ s16 sp1024;
    /* 0x1026 */ char pad1026[2];
    /* 0x1028 */ s32 sp1028;
    /* 0x102C */ char pad102C[0x14];
    /* 0x1040 */ s16 sp1040;
    /* 0x1042 */ char pad1042[2];
    /* 0x1044 */ s32 sp1044;
    /* 0x1048 */ char pad1048[0x14];
    /* 0x105C */ s16 sp105C;
    /* 0x105E */ char pad105E[2];
    /* 0x1060 */ s32 sp1060;
    /* 0x1064 */ char pad1064[0x14];
    /* 0x1078 */ s16 sp1078;
    /* 0x107A */ char pad107A[2];
    /* 0x107C */ s32 sp107C;
    /* 0x1080 */ char pad1080[0x14];
    /* 0x1094 */ s16 sp1094;
    /* 0x1096 */ char pad1096[2];
    /* 0x1098 */ s32 sp1098;
    /* 0x109C */ char pad109C[0x14];
    /* 0x10B0 */ s16 sp10B0;
    /* 0x10B2 */ char pad10B2[2];
    /* 0x10B4 */ s32 sp10B4;
    /* 0x10B8 */ char pad10B8[0x14];
    /* 0x10CC */ s16 sp10CC;
    /* 0x10CE */ char pad10CE[2];
    /* 0x10D0 */ s32 sp10D0;
    /* 0x10D4 */ char pad10D4[0x14];
    /* 0x10E8 */ s16 sp10E8;
    /* 0x10EA */ char pad10EA[2];
    /* 0x10EC */ s32 sp10EC;
    /* 0x10F0 */ char pad10F0[0x14];
    /* 0x1104 */ s16 sp1104;
    /* 0x1106 */ char pad1106[2];
    /* 0x1108 */ s32 sp1108;
    /* 0x110C */ char pad110C[0x14];
    /* 0x1120 */ s16 sp1120;
    /* 0x1122 */ char pad1122[2];
    /* 0x1124 */ s32 sp1124;
    /* 0x1128 */ char pad1128[0x14];
    /* 0x113C */ s16 sp113C;
    /* 0x113E */ char pad113E[2];
    /* 0x1140 */ s32 sp1140;
    /* 0x1144 */ char pad1144[0x14];
    /* 0x1158 */ s16 sp1158;
    /* 0x115A */ char pad115A[2];
    /* 0x115C */ s32 sp115C;
    /* 0x1160 */ char pad1160[0x14];
    /* 0x1174 */ s16 sp1174;
    /* 0x1176 */ char pad1176[2];
    /* 0x1178 */ s32 sp1178;
    /* 0x117C */ char pad117C[0x14];
    /* 0x1190 */ s16 sp1190;
    /* 0x1192 */ char pad1192[2];
    /* 0x1194 */ s32 sp1194;
    /* 0x1198 */ char pad1198[0x14];
    /* 0x11AC */ s16 sp11AC;
    /* 0x11AE */ char pad11AE[2];
    /* 0x11B0 */ s32 sp11B0;                        /* inferred */
    /* 0x11B4 */ char pad11B4[0x14];                /* maybe part of sp11B0[6]s32 */
    /* 0x11C8 */ s16 sp11C8;                        /* inferred */
    /* 0x11CA */ char pad11CA[2];
    /* 0x11CC */ s32 sp11CC;                        /* inferred */
    /* 0x11D0 */ char pad11D0[0x14];                /* maybe part of sp11CC[6]s32 */
    /* 0x11E4 */ s16 sp11E4;                        /* inferred */
    /* 0x11E6 */ char pad11E6[2];
    /* 0x11E8 */ s32 sp11E8;                        /* inferred */
    /* 0x11EC */ char pad11EC[0x14];                /* maybe part of sp11E8[6]s32 */
    /* 0x1200 */ s16 sp1200;                        /* inferred */
    /* 0x1202 */ char pad1202[2];
    /* 0x1204 */ s32 sp1204;                        /* inferred */
    /* 0x1208 */ char pad1208[0x14];                /* maybe part of sp1204[6]s32 */
    /* 0x121C */ s16 sp121C;                        /* inferred */
    /* 0x121E */ char pad121E[2];
    /* 0x1220 */ s32 sp1220;                        /* inferred */
    /* 0x1224 */ char pad1224[0x14];                /* maybe part of sp1220[6]s32 */
    /* 0x1238 */ s16 sp1238;                        /* inferred */
    /* 0x123A */ char pad123A[2];
    /* 0x123C */ s32 sp123C;                        /* inferred */
    /* 0x1240 */ char pad1240[0x14];                /* maybe part of sp123C[6]s32 */
    /* 0x1254 */ s16 sp1254;                        /* inferred */
    /* 0x1256 */ char pad1256[2];
    /* 0x1258 */ s32 sp1258;                        /* inferred */
    /* 0x125C */ char pad125C[0x14];                /* maybe part of sp1258[6]s32 */
    /* 0x1270 */ s16 sp1270;                        /* inferred */
    /* 0x1272 */ char pad1272[2];
    /* 0x1274 */ s32 sp1274;                        /* inferred */
    /* 0x1278 */ char pad1278[0x14];                /* maybe part of sp1274[6]s32 */
    /* 0x128C */ s16 sp128C;                        /* inferred */
    /* 0x128E */ char pad128E[2];
    /* 0x1290 */ s32 sp1290;                        /* inferred */
    /* 0x1294 */ char pad1294[0x14];                /* maybe part of sp1290[6]s32 */
    /* 0x12A8 */ s16 sp12A8;                        /* inferred */
    /* 0x12AA */ char pad12AA[2];
    /* 0x12AC */ s32 sp12AC;                        /* inferred */
    /* 0x12B0 */ char pad12B0[0x14];                /* maybe part of sp12AC[6]s32 */
    /* 0x12C4 */ s16 sp12C4;                        /* inferred */
    /* 0x12C6 */ char pad12C6[2];
    /* 0x12C8 */ s32 sp12C8;                        /* inferred */
    /* 0x12CC */ char pad12CC[0x14];                /* maybe part of sp12C8[6]s32 */
    /* 0x12E0 */ s16 sp12E0;                        /* inferred */
    /* 0x12E2 */ char pad12E2[2];
    /* 0x12E4 */ s32 sp12E4;                        /* inferred */
    /* 0x12E8 */ char pad12E8[0x14];                /* maybe part of sp12E4[6]s32 */
    /* 0x12FC */ s16 sp12FC;                        /* inferred */
    /* 0x12FE */ char pad12FE[2];
    /* 0x1300 */ s32 sp1300;                        /* inferred */
    /* 0x1304 */ char pad1304[0x14];                /* maybe part of sp1300[6]s32 */
    /* 0x1318 */ s16 sp1318;                        /* inferred */
    /* 0x131A */ char pad131A[2];
    /* 0x131C */ s32 sp131C;                        /* inferred */
    /* 0x1320 */ char pad1320[0x14];                /* maybe part of sp131C[6]s32 */
    /* 0x1334 */ s16 sp1334;                        /* inferred */
    /* 0x1336 */ char pad1336[2];
    /* 0x1338 */ s32 sp1338;                        /* inferred */
    /* 0x133C */ char pad133C[0x14];                /* maybe part of sp1338[6]s32 */
    /* 0x1350 */ s16 sp1350;                        /* inferred */
    /* 0x1352 */ char pad1352[2];
    /* 0x1354 */ s32 sp1354;                        /* inferred */
    /* 0x1358 */ char pad1358[0x14];                /* maybe part of sp1354[6]s32 */
    /* 0x136C */ s16 sp136C;                        /* inferred */
    /* 0x136E */ char pad136E[2];
    /* 0x1370 */ s32 sp1370;                        /* inferred */
    /* 0x1374 */ char pad1374[0x14];                /* maybe part of sp1370[6]s32 */
    /* 0x1388 */ s16 sp1388;                        /* inferred */
    /* 0x138A */ char pad138A[2];
    /* 0x138C */ s32 sp138C;                        /* inferred */
    /* 0x1390 */ char pad1390[0x14];                /* maybe part of sp138C[6]s32 */
    /* 0x13A4 */ s16 sp13A4;                        /* inferred */
    /* 0x13A6 */ char pad13A6[2];
    /* 0x13A8 */ s32 sp13A8;                        /* inferred */
    /* 0x13AC */ char pad13AC[0x14];                /* maybe part of sp13A8[6]s32 */
    /* 0x13C0 */ s16 sp13C0;                        /* inferred */
    /* 0x13C2 */ char pad13C2[2];
    /* 0x13C4 */ s32 sp13C4;                        /* inferred */
    char pad13C8_extra[0x14];
    /* 0x13DC */ s16 sp13DC;                        /* inferred */
    /* 0x13DE */ char pad13DE[2];
    /* 0x13E0 */ s32 sp13E0;                        /* inferred */
    /* 0x13E4 */ char pad13E4[0x14];                /* maybe part of sp13E0[6]s32 */
    /* 0x13F8 */ s16 sp13F8;                        /* inferred */
    /* 0x13FA */ char pad13FA[2];
    /* 0x13FC */ s32 sp13FC;                        /* inferred */
    /* 0x1400 */ char pad1400[0x14];                /* maybe part of sp13FC[6]s32 */
    /* 0x1414 */ s16 sp1414;                        /* inferred */
    /* 0x1416 */ char pad1416[2];
    /* 0x1418 */ s32 sp1418;                        /* inferred */
    /* 0x141C */ char pad141C[0x14];                /* maybe part of sp1418[6]s32 */
    /* 0x1430 */ s16 sp1430;                        /* inferred */
    /* 0x1432 */ char pad1432[2];
    /* 0x1434 */ s32 sp1434;                        /* inferred */
    /* 0x1438 */ char pad1438[0x14];                /* maybe part of sp1434[6]s32 */
    /* 0x144C */ s16 sp144C;                        /* inferred */
    /* 0x144E */ char pad144E[2];
    /* 0x1450 */ s32 sp1450;                        /* inferred */
    /* 0x1454 */ char pad1454[0x14];                /* maybe part of sp1450[6]s32 */
    /* 0x1468 */ s16 sp1468;                        /* inferred */
    /* 0x146A */ char pad146A[2];
    /* 0x146C */ s32 sp146C;                        /* inferred */
    /* 0x1470 */ char pad1470[0x14];                /* maybe part of sp146C[6]s32 */
    /* 0x1484 */ s16 sp1484;                        /* inferred */
    /* 0x1486 */ char pad1486[2];
    /* 0x1488 */ s32 sp1488;                        /* inferred */
    /* 0x148C */ char pad148C[0x14];                /* maybe part of sp1488[6]s32 */
    /* 0x14A0 */ s16 sp14A0;                        /* inferred */
    /* 0x14A2 */ char pad14A2[2];
    /* 0x14A4 */ s32 sp14A4;                        /* inferred */
    /* 0x14A8 */ char pad14A8[0x14];                /* maybe part of sp14A4[6]s32 */
    /* 0x14BC */ s16 sp14BC;                        /* inferred */
    /* 0x14BE */ char pad14BE[2];
    /* 0x14C0 */ s32 sp14C0;                        /* inferred */
    /* 0x14C4 */ char pad14C4[0x14];                /* maybe part of sp14C0[6]s32 */
    /* 0x14D8 */ s16 sp14D8;                        /* inferred */
    /* 0x14DA */ char pad14DA[2];
    /* 0x14DC */ s32 sp14DC;                        /* inferred */
    /* 0x14E0 */ char pad14E0[0x14];                /* maybe part of sp14DC[6]s32 */
    /* 0x14F4 */ s16 sp14F4;                        /* inferred */
    /* 0x14F6 */ char pad14F6[2];
    /* 0x14F8 */ s32 sp14F8;                        /* inferred */
    /* 0x14FC */ char pad14FC[0x14];                /* maybe part of sp14F8[6]s32 */
    /* 0x1510 */ s16 sp1510;                        /* inferred */
    /* 0x1512 */ char pad1512[2];
    /* 0x1514 */ s32 sp1514;                        /* inferred */
    /* 0x1518 */ char pad1518[0x14];                /* maybe part of sp1514[6]s32 */
    /* 0x152C */ s16 sp152C;                        /* inferred */
    /* 0x152E */ char pad152E[2];
    /* 0x1530 */ s32 sp1530;                        /* inferred */
    /* 0x1534 */ char pad1534[0x14];                /* maybe part of sp1530[6]s32 */
    /* 0x1548 */ s16 sp1548;                        /* inferred */
    /* 0x154A */ char pad154A[2];
    /* 0x154C */ s32 sp154C;                        /* inferred */
    /* 0x1550 */ char pad1550[0x14];                /* maybe part of sp154C[6]s32 */
    /* 0x1564 */ s16 sp1564;                        /* inferred */
    /* 0x1566 */ char pad1566[2];
    /* 0x1568 */ s32 sp1568;                        /* inferred */
    /* 0x156C */ char pad156C[0x14];                /* maybe part of sp1568[6]s32 */
    /* 0x1580 */ s16 sp1580;                        /* inferred */
    /* 0x1582 */ char pad1582[2];
    /* 0x1584 */ s32 sp1584;                        /* inferred */
    /* 0x1588 */ char pad1588[0x14];                /* maybe part of sp1584[6]s32 */
    /* 0x159C */ s16 sp159C;                        /* inferred */
    /* 0x159E */ char pad159E[2];
    /* 0x15A0 */ s32 sp15A0;                        /* inferred */
    /* 0x15A4 */ char pad15A4[0x14];                /* maybe part of sp15A0[6]s32 */
    /* 0x15B8 */ s16 sp15B8;                        /* inferred */
    /* 0x15BA */ char pad15BA[2];
    /* 0x15BC */ s32 sp15BC;                        /* inferred */
    /* 0x15C0 */ char pad15C0[0x14];                /* maybe part of sp15BC[6]s32 */
    /* 0x15D4 */ s16 sp15D4;                        /* inferred */
    /* 0x15D6 */ char pad15D6[2];
    /* 0x15D8 */ s32 sp15D8;                        /* inferred */
    /* 0x15DC */ char pad15DC[0x14];                /* maybe part of sp15D8[6]s32 */
    /* 0x15F0 */ s16 sp15F0;                        /* inferred */
    /* 0x15F2 */ char pad15F2[2];
    /* 0x15F4 */ s32 sp15F4;                        /* inferred */
    /* 0x15F8 */ char pad15F8[0x14];                /* maybe part of sp15F4[6]s32 */
    /* 0x160C */ s16 sp160C;                        /* inferred */
    /* 0x160E */ char pad160E[2];
    /* 0x1610 */ s32 sp1610;                        /* inferred */
    /* 0x1614 */ char pad1614[0x14];                /* maybe part of sp1610[6]s32 */
    /* 0x1628 */ s16 sp1628;                        /* inferred */
    /* 0x162A */ char pad162A[2];
    /* 0x162C */ s32 sp162C;                        /* inferred */
    /* 0x1630 */ char pad1630[0x14];                /* maybe part of sp162C[6]s32 */
    /* 0x1644 */ s16 sp1644;                        /* inferred */
    /* 0x1646 */ char pad1646[2];
    /* 0x1648 */ s32 sp1648;                        /* inferred */
    /* 0x164C */ char pad164C[0x14];                /* maybe part of sp1648[6]s32 */
    /* 0x1660 */ s16 sp1660;                        /* inferred */
    /* 0x1662 */ char pad1662[2];
    /* 0x1664 */ s32 sp1664;                        /* inferred */
    /* 0x1668 */ char pad1668[0x14];                /* maybe part of sp1664[6]s32 */
    /* 0x167C */ s16 sp167C;                        /* inferred */
    /* 0x167E */ char pad167E[2];
    /* 0x1680 */ s32 sp1680;                        /* inferred */
    /* 0x1684 */ char pad1684[0x14];                /* maybe part of sp1680[6]s32 */
    /* 0x1698 */ s16 sp1698;                        /* inferred */
    /* 0x169A */ char pad169A[2];
    /* 0x169C */ s32 sp169C;                        /* inferred */
    /* 0x16A0 */ char pad16A0[0x14];                /* maybe part of sp169C[6]s32 */
    /* 0x16B4 */ s16 sp16B4;                        /* inferred */
    /* 0x16B6 */ char pad16B6[2];
    /* 0x16B8 */ s32 sp16B8;                        /* inferred */
    /* 0x16BC */ char pad16BC[0x14];                /* maybe part of sp16B8[6]s32 */
    /* 0x16D0 */ s16 sp16D0;                        /* inferred */
    /* 0x16D2 */ char pad16D2[2];
    /* 0x16D4 */ s32 sp16D4;                        /* inferred */
    /* 0x16D8 */ char pad16D8[0x14];                /* maybe part of sp16D4[6]s32 */
    /* 0x16EC */ s16 sp16EC;                        /* inferred */
    /* 0x16EE */ char pad16EE[2];
    /* 0x16F0 */ s32 sp16F0;                        /* inferred */
    /* 0x16F4 */ char pad16F4[0x14];                /* maybe part of sp16F0[6]s32 */
    /* 0x1708 */ s16 sp1708;                        /* inferred */
    /* 0x170A */ char pad170A[2];
    /* 0x170C */ s32 sp170C;                        /* inferred */
    /* 0x1710 */ char pad1710[0x14];                /* maybe part of sp170C[6]s32 */
    /* 0x1724 */ s16 sp1724;                        /* inferred */
    /* 0x1726 */ char pad1726[2];
    /* 0x1728 */ s32 sp1728;                        /* inferred */
    /* 0x172C */ char pad172C[0x14];                /* maybe part of sp1728[6]s32 */
    /* 0x1740 */ s16 sp1740;                        /* inferred */
    /* 0x1742 */ char pad1742[2];
    /* 0x1744 */ s32 sp1744;                        /* inferred */
    /* 0x1748 */ char pad1748[0x14];                /* maybe part of sp1744[6]s32 */
    /* 0x175C */ s16 sp175C;                        /* inferred */
    /* 0x175E */ char pad175E[2];
    /* 0x1760 */ s32 sp1760;                        /* inferred */
    /* 0x1764 */ char pad1764[0x14];                /* maybe part of sp1760[6]s32 */
    /* 0x1778 */ s16 sp1778;                        /* inferred */
    /* 0x177A */ char pad177A[2];
    /* 0x177C */ s32 sp177C;                        /* inferred */
    /* 0x1780 */ char pad1780[0x14];                /* maybe part of sp177C[6]s32 */
    /* 0x1794 */ s16 sp1794;                        /* inferred */
    /* 0x1796 */ char pad1796[2];
    /* 0x1798 */ s32 sp1798;                        /* inferred */
    /* 0x179C */ char pad179C[0x14];                /* maybe part of sp1798[6]s32 */
    /* 0x17B0 */ s16 sp17B0;                        /* inferred */
    /* 0x17B2 */ char pad17B2[2];
    /* 0x17B4 */ s32 sp17B4;                        /* inferred */
    /* 0x17B8 */ char pad17B8[0x14];                /* maybe part of sp17B4[6]s32 */
    /* 0x17CC */ s16 sp17CC;                        /* inferred */
    /* 0x17CE */ char pad17CE[2];
    /* 0x17D0 */ s32 sp17D0;                        /* inferred */
    /* 0x17D4 */ char pad17D4[0x14];                /* maybe part of sp17D0[6]s32 */
    /* 0x17E8 */ s16 sp17E8;                        /* inferred */
    /* 0x17EA */ char pad17EA[2];
    /* 0x17EC */ s32 sp17EC;                        /* inferred */
    /* 0x17F0 */ char pad17F0[0x14];                /* maybe part of sp17EC[6]s32 */
    /* 0x1804 */ s16 sp1804;                        /* inferred */
    /* 0x1806 */ char pad1806[2];
    /* 0x1808 */ s32 sp1808;                        /* inferred */
    /* 0x180C */ char pad180C[0x14];                /* maybe part of sp1808[6]s32 */
    /* 0x1820 */ s16 sp1820;                        /* inferred */
    /* 0x1822 */ char pad1822[2];
    /* 0x1824 */ s32 sp1824;                        /* inferred */
    /* 0x1828 */ char pad1828[0x14];                /* maybe part of sp1824[6]s32 */
    /* 0x183C */ s16 sp183C;                        /* inferred */
    /* 0x183E */ char pad183E[2];
    /* 0x1840 */ s32 sp1840;
    /* 0x1844 */ char pad1844[0x14];
    /* 0x1858 */ s16 sp1858;
    /* 0x185A */ char pad185A[2];
    /* 0x185C */ s32 sp185C;
    /* 0x1860 */ char pad1860[0x14];
    /* 0x1874 */ s16 sp1874;
    /* 0x1876 */ char pad1876[2];
    /* 0x1878 */ s32 sp1878;
    /* 0x187C */ char pad187C[0x14];
    /* 0x1890 */ s16 sp1890;
    /* 0x1892 */ char pad1892[2];
    /* 0x1894 */ s32 sp1894;
    /* 0x1898 */ char pad1898[0x14];
    /* 0x18AC */ s16 sp18AC;
    /* 0x18AE */ char pad18AE[2];
    /* 0x18B0 */ s32 sp18B0;
    /* 0x18B4 */ char pad18B4[0x14];
    /* 0x18C8 */ s16 sp18C8;
    /* 0x18CA */ char pad18CA[2];
    /* 0x18CC */ s32 sp18CC;
    /* 0x18D0 */ char pad18D0[0x14];
    /* 0x18E4 */ s16 sp18E4;
    /* 0x18E6 */ char pad18E6[2];
    /* 0x18E8 */ s32 sp18E8;
    /* 0x18EC */ char pad18EC[0x14];
    /* 0x1900 */ s16 sp1900;
    /* 0x1902 */ char pad1902[2];
    /* 0x1904 */ s32 sp1904;
    /* 0x1908 */ char pad1908[0x14];
    /* 0x191C */ s16 sp191C;
    /* 0x191E */ char pad191E[2];
    /* 0x1920 */ s32 sp1920;
    /* 0x1924 */ char pad1924[0x14];
    /* 0x1938 */ s16 sp1938;
    /* 0x193A */ char pad193A[2];
    /* 0x193C */ s32 sp193C;
    /* 0x1940 */ char pad1940[0x14];
    /* 0x1954 */ s16 sp1954;
    /* 0x1956 */ char pad1956[2];
    /* 0x1958 */ s32 sp1958;
    /* 0x195C */ char pad195C[0x14];
    /* 0x1970 */ s16 sp1970;
    /* 0x1972 */ char pad1972[2];
    /* 0x1974 */ s32 sp1974;
    /* 0x1978 */ char pad1978[0x14];
    /* 0x198C */ s16 sp198C;
    /* 0x198E */ char pad198E[2];
    /* 0x1990 */ s32 sp1990;
    /* 0x1994 */ char pad1994[0x14];
    /* 0x19A8 */ s16 sp19A8;
    /* 0x19AA */ char pad19AA[2];
    /* 0x19AC */ s32 sp19AC;
    /* 0x19B0 */ char pad19B0[0x14];
    /* 0x19C4 */ s16 sp19C4;
    /* 0x19C6 */ char pad19C6[2];
    /* 0x19C8 */ s32 sp19C8;
    /* 0x19CC */ char pad19CC[0x14];
    /* 0x19E0 */ s16 sp19E0;
    /* 0x19E2 */ char pad19E2[2];
    /* 0x19E4 */ s32 sp19E4;
    /* 0x19E8 */ char pad19E8[0x14];
    /* 0x19FC */ s16 sp19FC;
    /* 0x19FE */ char pad19FE[2];
    /* 0x1A00 */ s32 sp1A00;
    /* 0x1A04 */ char pad1A04[0x14];
    /* 0x1A18 */ s16 sp1A18;
    /* 0x1A1A */ char pad1A1A[2];
    /* 0x1A1C */ s32 sp1A1C;
    /* 0x1A20 */ char pad1A20[0x14];
    /* 0x1A34 */ s16 sp1A34;
    /* 0x1A36 */ char pad1A36[2];
    /* 0x1A38 */ s32 sp1A38;
    /* 0x1A3C */ char pad1A3C[0x14];
    /* 0x1A50 */ s16 sp1A50;
    /* 0x1A52 */ char pad1A52[2];
    /* 0x1A54 */ s32 sp1A54;
    /* 0x1A58 */ char pad1A58[0x14];
    /* 0x1A6C */ s16 sp1A6C;
    /* 0x1A6E */ char pad1A6E[2];
    /* 0x1A70 */ s32 sp1A70;                        /* inferred */
    /* 0x1A74 */ char pad1A74[0x14];                /* maybe part of sp1A70[6]s32 */
    /* 0x1A88 */ s16 sp1A88;                        /* inferred */
    /* 0x1A8A */ char pad1A8A[2];
    /* 0x1A8C */ s32 sp1A8C;                        /* inferred */
    /* 0x1A90 */ char pad1A90[0x14];                /* maybe part of sp1A8C[6]s32 */
    /* 0x1AA4 */ s16 sp1AA4;                        /* inferred */
    /* 0x1AA6 */ char pad1AA6[2];
    /* 0x1AA8 */ s32 sp1AA8;                        /* inferred */
    /* 0x1AAC */ char pad1AAC[0x14];                /* maybe part of sp1AA8[6]s32 */
    /* 0x1AC0 */ s16 sp1AC0;                        /* inferred */
    /* 0x1AC2 */ char pad1AC2[2];
    /* 0x1AC4 */ s32 sp1AC4;                        /* inferred */
    /* 0x1AC8 */ char pad1AC8[0x14];                /* maybe part of sp1AC4[6]s32 */
    /* 0x1ADC */ s16 sp1ADC;                        /* inferred */
    /* 0x1ADE */ char pad1ADE[2];
    /* 0x1AE0 */ s32 sp1AE0;                        /* inferred */
    /* 0x1AE4 */ char pad1AE4[0x14];                /* maybe part of sp1AE0[6]s32 */
    /* 0x1AF8 */ s16 sp1AF8;                        /* inferred */
    /* 0x1AFA */ char pad1AFA[2];
    /* 0x1AFC */ s32 sp1AFC;                        /* inferred */
    /* 0x1B00 */ char pad1B00[0x14];                /* maybe part of sp1AFC[6]s32 */
    /* 0x1B14 */ s16 sp1B14;                        /* inferred */
    /* 0x1B16 */ char pad1B16[2];
    /* 0x1B18 */ s32 sp1B18;                        /* inferred */
    /* 0x1B1C */ char pad1B1C[0x14];                /* maybe part of sp1B18[6]s32 */
    /* 0x1B30 */ s16 sp1B30;                        /* inferred */
    /* 0x1B32 */ char pad1B32[2];
    /* 0x1B34 */ s32 sp1B34;                        /* inferred */
    /* 0x1B38 */ char pad1B38[0x14];                /* maybe part of sp1B34[6]s32 */
    /* 0x1B4C */ s16 sp1B4C;                        /* inferred */
    /* 0x1B4E */ char pad1B4E[2];
    /* 0x1B50 */ s32 sp1B50;                        /* inferred */
    /* 0x1B54 */ char pad1B54[0x14];                /* maybe part of sp1B50[6]s32 */
    /* 0x1B68 */ s16 sp1B68;                        /* inferred */
    /* 0x1B6A */ char pad1B6A[2];
    /* 0x1B6C */ s32 sp1B6C;                        /* inferred */
    /* 0x1B70 */ char pad1B70[0x14];                /* maybe part of sp1B6C[6]s32 */
    /* 0x1B84 */ s16 sp1B84;                        /* inferred */
    /* 0x1B86 */ char pad1B86[2];
    /* 0x1B88 */ s32 sp1B88;                        /* inferred */
    /* 0x1B8C */ char pad1B8C[0x14];                /* maybe part of sp1B88[6]s32 */
    /* 0x1BA0 */ s16 sp1BA0;                        /* inferred */
    /* 0x1BA2 */ char pad1BA2[2];
    /* 0x1BA4 */ s32 sp1BA4;                        /* inferred */
    /* 0x1BA8 */ char pad1BA8[0x14];                /* maybe part of sp1BA4[6]s32 */
    /* 0x1BBC */ s16 sp1BBC;                        /* inferred */
    /* 0x1BBE */ char pad1BBE[2];
    /* 0x1BC0 */ s32 sp1BC0;                        /* inferred */
    /* 0x1BC4 */ char pad1BC4[0x14];                /* maybe part of sp1BC0[6]s32 */
    /* 0x1BD8 */ s16 sp1BD8;                        /* inferred */
    /* 0x1BDA */ char pad1BDA[2];
    /* 0x1BDC */ s32 sp1BDC;                        /* inferred */
    /* 0x1BE0 */ char pad1BE0[0x14];                /* maybe part of sp1BDC[6]s32 */
    /* 0x1BF4 */ s16 sp1BF4;                        /* inferred */
    /* 0x1BF6 */ char pad1BF6[2];
    /* 0x1BF8 */ s32 sp1BF8;                        /* inferred */
    /* 0x1BFC */ char pad1BFC[0x14];                /* maybe part of sp1BF8[6]s32 */
    /* 0x1C10 */ s16 sp1C10;                        /* inferred */
    /* 0x1C12 */ char pad1C12[2];
    /* 0x1C14 */ s32 sp1C14;                        /* inferred */
    /* 0x1C18 */ char pad1C18[0x14];                /* maybe part of sp1C14[6]s32 */
    /* 0x1C2C */ s16 sp1C2C;                        /* inferred */
    /* 0x1C2E */ char pad1C2E[2];
    /* 0x1C30 */ s32 sp1C30;                        /* inferred */
    /* 0x1C34 */ char pad1C34[0x14];                /* maybe part of sp1C30[6]s32 */
    /* 0x1C48 */ s16 sp1C48;                        /* inferred */
    /* 0x1C4A */ char pad1C4A[2];
    /* 0x1C4C */ s32 sp1C4C;                        /* inferred */
    /* 0x1C50 */ char pad1C50[0x14];                /* maybe part of sp1C4C[6]s32 */
    /* 0x1C64 */ s16 sp1C64;                        /* inferred */
    /* 0x1C66 */ char pad1C66[2];
    /* 0x1C68 */ s32 sp1C68;                        /* inferred */
    /* 0x1C6C */ char pad1C6C[0x14];                /* maybe part of sp1C68[6]s32 */
    /* 0x1C80 */ s16 sp1C80;                        /* inferred */
    /* 0x1C82 */ char pad1C82[2];
    /* 0x1C84 */ s32 sp1C84;                        /* inferred */
    /* 0x1C88 */ char pad1C88[0x14];                /* maybe part of sp1C84[6]s32 */
    /* 0x1C9C */ s16 sp1C9C;                        /* inferred */
    /* 0x1C9E */ char pad1C9E[2];
    /* 0x1CA0 */ s32 sp1CA0;                        /* inferred */
    /* 0x1CA4 */ char pad1CA4[0x14];                /* maybe part of sp1CA0[6]s32 */
    /* 0x1CB8 */ s16 sp1CB8;                        /* inferred */
    /* 0x1CBA */ char pad1CBA[2];
    /* 0x1CBC */ s32 sp1CBC;                        /* inferred */
    /* 0x1CC0 */ char pad1CC0[0x14];                /* maybe part of sp1CBC[6]s32 */
    /* 0x1CD4 */ s16 sp1CD4;                        /* inferred */
    /* 0x1CD6 */ char pad1CD6[2];
    /* 0x1CD8 */ s32 sp1CD8;                        /* inferred */
    /* 0x1CDC */ char pad1CDC[0x14];                /* maybe part of sp1CD8[6]s32 */
    /* 0x1CF0 */ s16 sp1CF0;                        /* inferred */
    /* 0x1CF2 */ char pad1CF2[2];
    /* 0x1CF4 */ s32 sp1CF4;                        /* inferred */
    /* 0x1CF8 */ char pad1CF8[0x14];                /* maybe part of sp1CF4[6]s32 */
    /* 0x1D0C */ s16 sp1D0C;                        /* inferred */
    /* 0x1D0E */ char pad1D0E[2];
    /* 0x1D10 */ s32 sp1D10;                        /* inferred */
    /* 0x1D14 */ char pad1D14[0x14];                /* maybe part of sp1D10[6]s32 */
    /* 0x1D28 */ s16 sp1D28;                        /* inferred */
    /* 0x1D2A */ char pad1D2A[2];
    /* 0x1D2C */ s32 sp1D2C;                        /* inferred */
    /* 0x1D30 */ char pad1D30[0x14];                /* maybe part of sp1D2C[6]s32 */
    /* 0x1D44 */ s16 sp1D44;                        /* inferred */
    /* 0x1D46 */ char pad1D46[2];
    /* 0x1D48 */ s32 sp1D48;                        /* inferred */
    /* 0x1D4C */ char pad1D4C[0x14];                /* maybe part of sp1D48[6]s32 */
    /* 0x1D60 */ s16 sp1D60;                        /* inferred */
    /* 0x1D62 */ char pad1D62[2];
    /* 0x1D64 */ s32 sp1D64;                        /* inferred */
    /* 0x1D68 */ char pad1D68[0x14];                /* maybe part of sp1D64[6]s32 */
    /* 0x1D7C */ s16 sp1D7C;                        /* inferred */
    /* 0x1D7E */ char pad1D7E[2];
    /* 0x1D80 */ s32 sp1D80;                        /* inferred */
    /* 0x1D84 */ char pad1D84[0x14];                /* maybe part of sp1D80[6]s32 */
    /* 0x1D98 */ s16 sp1D98;                        /* inferred */
    /* 0x1D9A */ char pad1D9A[2];
    /* 0x1D9C */ s32 sp1D9C;                        /* inferred */
    /* 0x1DA0 */ char pad1DA0[0x14];                /* maybe part of sp1D9C[6]s32 */
    /* 0x1DB4 */ s16 sp1DB4;                        /* inferred */
    /* 0x1DB6 */ char pad1DB6[2];
    /* 0x1DB8 */ s32 sp1DB8;                        /* inferred */
    /* 0x1DBC */ char pad1DBC[0x14];                /* maybe part of sp1DB8[6]s32 */
    /* 0x1DD0 */ s16 sp1DD0;                        /* inferred */
    /* 0x1DD2 */ char pad1DD2[2];
    /* 0x1DD4 */ s32 sp1DD4;                        /* inferred */
    /* 0x1DD8 */ char pad1DD8[0x14];                /* maybe part of sp1DD4[6]s32 */
    /* 0x1DEC */ s16 sp1DEC;                        /* inferred */
    /* 0x1DEE */ char pad1DEE[2];
    /* 0x1DF0 */ s32 sp1DF0;                        /* inferred */
    /* 0x1DF4 */ char pad1DF4[0x14];                /* maybe part of sp1DF0[6]s32 */
    /* 0x1E08 */ s16 sp1E08;                        /* inferred */
    /* 0x1E0A */ char pad1E0A[2];
    /* 0x1E0C */ s32 sp1E0C;                        /* inferred */
    /* 0x1E10 */ char pad1E10[0x14];                /* maybe part of sp1E0C[6]s32 */
    /* 0x1E24 */ s16 sp1E24;                        /* inferred */
    /* 0x1E26 */ char pad1E26[2];
    /* 0x1E28 */ s32 sp1E28;                        /* inferred */
    /* 0x1E2C */ char pad1E2C[0x14];                /* maybe part of sp1E28[6]s32 */
    /* 0x1E40 */ s16 sp1E40;                        /* inferred */
    /* 0x1E42 */ char pad1E42[2];
    /* 0x1E44 */ s32 sp1E44;                        /* inferred */
    /* 0x1E48 */ char pad1E48[0x14];                /* maybe part of sp1E44[6]s32 */
    /* 0x1E5C */ s16 sp1E5C;                        /* inferred */
    /* 0x1E5E */ char pad1E5E[2];
    /* 0x1E60 */ s32 sp1E60;                        /* inferred */
    /* 0x1E64 */ char pad1E64[0x14];                /* maybe part of sp1E60[6]s32 */
    /* 0x1E78 */ s16 sp1E78;                        /* inferred */
    /* 0x1E7A */ char pad1E7A[2];
    /* 0x1E7C */ s32 sp1E7C;                        /* inferred */
    /* 0x1E80 */ char pad1E80[0x14];                /* maybe part of sp1E7C[6]s32 */
    /* 0x1E94 */ s16 sp1E94;                        /* inferred */
    /* 0x1E96 */ char pad1E96[2];
    /* 0x1E98 */ s32 sp1E98;                        /* inferred */
    /* 0x1E9C */ char pad1E9C[0x14];                /* maybe part of sp1E98[6]s32 */
    /* 0x1EB0 */ s16 sp1EB0;                        /* inferred */
    /* 0x1EB2 */ char pad1EB2[2];
    /* 0x1EB4 */ s32 sp1EB4;                        /* inferred */
    /* 0x1EB8 */ char pad1EB8[0x14];                /* maybe part of sp1EB4[6]s32 */
    /* 0x1ECC */ s16 sp1ECC;                        /* inferred */
    /* 0x1ECE */ char pad1ECE[2];
    /* 0x1ED0 */ s32 sp1ED0;                        /* inferred */
    /* 0x1ED4 */ char pad1ED4[0x14];                /* maybe part of sp1ED0[6]s32 */
    /* 0x1EE8 */ s16 sp1EE8;                        /* inferred */
    /* 0x1EEA */ char pad1EEA[2];
    /* 0x1EEC */ s32 sp1EEC;                        /* inferred */
    /* 0x1EF0 */ char pad1EF0[0x14];                /* maybe part of sp1EEC[6]s32 */
    /* 0x1F04 */ s16 sp1F04;                        /* inferred */
    /* 0x1F06 */ char pad1F06[2];
    /* 0x1F08 */ s32 sp1F08;                        /* inferred */
    /* 0x1F0C */ char pad1F0C[0x14];                /* maybe part of sp1F08[6]s32 */
    /* 0x1F20 */ s16 sp1F20;                        /* inferred */
    /* 0x1F22 */ char pad1F22[2];
    /* 0x1F24 */ s32 sp1F24;                        /* inferred */
    /* 0x1F28 */ char pad1F28[0x14];                /* maybe part of sp1F24[6]s32 */
    /* 0x1F3C */ s16 sp1F3C;                        /* inferred */
    /* 0x1F3E */ char pad1F3E[2];
    /* 0x1F40 */ s32 sp1F40;                        /* inferred */
    /* 0x1F44 */ char pad1F44[0x14];                /* maybe part of sp1F40[6]s32 */
    /* 0x1F58 */ s16 sp1F58;                        /* inferred */
    /* 0x1F5A */ char pad1F5A[2];
    /* 0x1F5C */ s32 sp1F5C;                        /* inferred */
    /* 0x1F60 */ char pad1F60[0x14];                /* maybe part of sp1F5C[6]s32 */
    /* 0x1F74 */ s16 sp1F74;                        /* inferred */
    /* 0x1F76 */ char pad1F76[2];
    /* 0x1F78 */ s32 sp1F78;                        /* inferred */
    /* 0x1F7C */ char pad1F7C[0x14];                /* maybe part of sp1F78[6]s32 */
    /* 0x1F90 */ s16 sp1F90;                        /* inferred */
    /* 0x1F92 */ char pad1F92[2];
    /* 0x1F94 */ s32 sp1F94;                        /* inferred */
    /* 0x1F98 */ char pad1F98[0x14];                /* maybe part of sp1F94[6]s32 */
    /* 0x1FAC */ s16 sp1FAC;                        /* inferred */
    /* 0x1FAE */ char pad1FAE[2];
    /* 0x1FB0 */ s32 sp1FB0;                        /* inferred */
    /* 0x1FB4 */ char pad1FB4[0x14];                /* maybe part of sp1FB0[6]s32 */
    /* 0x1FC8 */ s16 sp1FC8;                        /* inferred */
    /* 0x1FCA */ char pad1FCA[2];
    /* 0x1FCC */ s32 sp1FCC;                        /* inferred */
    /* 0x1FD0 */ char pad1FD0[0x14];                /* maybe part of sp1FCC[6]s32 */
    /* 0x1FE4 */ s16 sp1FE4;                        /* inferred */
    /* 0x1FE6 */ char pad1FE6[2];
    /* 0x1FE8 */ s32 sp1FE8;                        /* inferred */
    /* 0x1FEC */ char pad1FEC[0x14];                /* maybe part of sp1FE8[6]s32 */
    /* 0x2000 */ s16 sp2000;                        /* inferred */
    /* 0x2002 */ char pad2002[2];
    /* 0x2004 */ s32 sp2004;                        /* inferred */
    /* 0x2008 */ char pad2008[0x14];                /* maybe part of sp2004[6]s32 */
    /* 0x201C */ s16 sp201C;                        /* inferred */
    /* 0x201E */ char pad201E[2];
    /* 0x2020 */ s32 sp2020;                        /* inferred */
    /* 0x2024 */ char pad2024[0x14];                /* maybe part of sp2020[6]s32 */
    /* 0x2038 */ s16 sp2038;                        /* inferred */
    /* 0x203A */ char pad203A[2];
    /* 0x203C */ s32 sp203C;                        /* inferred */
    /* 0x2040 */ char pad2040[0x14];                /* maybe part of sp203C[6]s32 */
    /* 0x2054 */ s16 sp2054;                        /* inferred */
    /* 0x2056 */ char pad2056[2];
    /* 0x2058 */ s32 sp2058;                        /* inferred */
    /* 0x205C */ char pad205C[0x14];                /* maybe part of sp2058[6]s32 */
    /* 0x2070 */ s16 sp2070;                        /* inferred */
    /* 0x2072 */ char pad2072[2];
    /* 0x2074 */ s32 sp2074;                        /* inferred */
    /* 0x2078 */ char pad2078[0x14];                /* maybe part of sp2074[6]s32 */
    /* 0x208C */ s16 sp208C;                        /* inferred */
    /* 0x208E */ char pad208E[2];
    /* 0x2090 */ s32 sp2090;                        /* inferred */
    /* 0x2094 */ char pad2094[0x14];                /* maybe part of sp2090[6]s32 */
    /* 0x20A8 */ s16 sp20A8;                        /* inferred */
    /* 0x20AA */ char pad20AA[2];
    /* 0x20AC */ s32 sp20AC;                        /* inferred */
    /* 0x20B0 */ char pad20B0[0x14];                /* maybe part of sp20AC[6]s32 */
    /* 0x20C4 */ s16 sp20C4;                        /* inferred */
    /* 0x20C6 */ char pad20C6[2];
    /* 0x20C8 */ s32 sp20C8;                        /* inferred */
    /* 0x20CC */ char pad20CC[0x14];                /* maybe part of sp20C8[6]s32 */
    /* 0x20E0 */ s16 sp20E0;                        /* inferred */
    /* 0x20E2 */ char pad20E2[2];
    /* 0x20E4 */ s32 sp20E4;                        /* inferred */
    /* 0x20E8 */ char pad20E8[0x14];                /* maybe part of sp20E4[6]s32 */
    /* 0x20FC */ s16 sp20FC;                        /* inferred */
    /* 0x20FE */ char pad20FE[2];
    /* 0x2100 */ s32 sp2100;                        /* inferred */
    /* 0x2104 */ char pad2104[0x14];                /* maybe part of sp2100[6]s32 */
    /* 0x2118 */ s16 sp2118;                        /* inferred */
    /* 0x211A */ char pad211A[2];
    /* 0x211C */ s32 sp211C;                        /* inferred */
    /* 0x2120 */ char pad2120[0x14];                /* maybe part of sp211C[6]s32 */
    /* 0x2134 */ s16 sp2134;                        /* inferred */
    /* 0x2136 */ char pad2136[2];
    /* 0x2138 */ s32 sp2138;                        /* inferred */
    /* 0x213C */ char pad213C[0x14];                /* maybe part of sp2138[6]s32 */
    /* 0x2150 */ s16 sp2150;                        /* inferred */
    /* 0x2152 */ char pad2152[2];
    /* 0x2154 */ s32 sp2154;                        /* inferred */
    /* 0x2158 */ char pad2158[0x14];                /* maybe part of sp2154[6]s32 */
    /* 0x216C */ s16 sp216C;                        /* inferred */
    /* 0x216E */ char pad216E[2];
    /* 0x2170 */ s32 sp2170;                        /* inferred */
    /* 0x2174 */ char pad2174[0x14];                /* maybe part of sp2170[6]s32 */
    /* 0x2188 */ s16 sp2188;                        /* inferred */
    /* 0x218A */ char pad218A[2];
    /* 0x218C */ s32 sp218C;                        /* inferred */
    /* 0x2190 */ char pad2190[0x14];                /* maybe part of sp218C[6]s32 */
    /* 0x21A4 */ s16 sp21A4;                        /* inferred */
    /* 0x21A6 */ char pad21A6[2];
    /* 0x21A8 */ s32 sp21A8;                        /* inferred */
    /* 0x21AC */ char pad21AC[0x14];                /* maybe part of sp21A8[6]s32 */
    /* 0x21C0 */ s16 sp21C0;                        /* inferred */
    /* 0x21C2 */ char pad21C2[2];
    /* 0x21C4 */ s32 sp21C4;                        /* inferred */
    /* 0x21C8 */ char pad21C8[0x14];                /* maybe part of sp21C4[6]s32 */
    /* 0x21DC */ s16 sp21DC;                        /* inferred */
    /* 0x21DE */ char pad21DE[2];
    /* 0x21E0 */ s32 sp21E0;                        /* inferred */
    /* 0x21E4 */ char pad21E4[0x14];                /* maybe part of sp21E0[6]s32 */
    /* 0x21F8 */ s16 sp21F8;                        /* inferred */
    /* 0x21FA */ char pad21FA[2];
    /* 0x21FC */ s32 sp21FC;                        /* inferred */
    /* 0x2200 */ char pad2200[0x14];                /* maybe part of sp21FC[6]s32 */
    /* 0x2214 */ s16 sp2214;                        /* inferred */
    /* 0x2216 */ char pad2216[2];
    /* 0x2218 */ s32 sp2218;                        /* inferred */
    /* 0x221C */ char pad221C[0x14];                /* maybe part of sp2218[6]s32 */
    /* 0x2230 */ s16 sp2230;                        /* inferred */
    /* 0x2232 */ char pad2232[2];
    /* 0x2234 */ s32 sp2234;                        /* inferred */
    /* 0x2238 */ char pad2238[0x14];                /* maybe part of sp2234[6]s32 */
    /* 0x224C */ s16 sp224C;                        /* inferred */
    /* 0x224E */ char pad224E[2];
    /* 0x2250 */ s32 sp2250;                        /* inferred */
    /* 0x2254 */ char pad2254[0x14];                /* maybe part of sp2250[6]s32 */
    /* 0x2268 */ s16 sp2268;                        /* inferred */
    /* 0x226A */ char pad226A[2];
    /* 0x226C */ s32 sp226C;                        /* inferred */
    /* 0x2270 */ char pad2270[0x14];                /* maybe part of sp226C[6]s32 */
    /* 0x2284 */ s16 sp2284;                        /* inferred */
    /* 0x2286 */ char pad2286[2];
    /* 0x2288 */ s32 sp2288;                        /* inferred */
    /* 0x228C */ char pad228C[0x14];                /* maybe part of sp2288[6]s32 */
    /* 0x22A0 */ s16 sp22A0;                        /* inferred */
    /* 0x22A2 */ char pad22A2[2];
    /* 0x22A4 */ s32 sp22A4;                        /* inferred */
    /* 0x22A8 */ char pad22A8[0x14];                /* maybe part of sp22A4[6]s32 */
    /* 0x22BC */ s16 sp22BC;                        /* inferred */
    /* 0x22BE */ char pad22BE[2];
    /* 0x22C0 */ s32 sp22C0;                        /* inferred */
    /* 0x22C4 */ char pad22C4[0x14];                /* maybe part of sp22C0[6]s32 */
    /* 0x22D8 */ s16 sp22D8;                        /* inferred */
    /* 0x22DA */ char pad22DA[2];
    /* 0x22DC */ s32 sp22DC;                        /* inferred */
    /* 0x22E0 */ char pad22E0[0x14];                /* maybe part of sp22DC[6]s32 */
    /* 0x22F4 */ s16 sp22F4;                        /* inferred */
    /* 0x22F6 */ char pad22F6[2];
    /* 0x22F8 */ s32 sp22F8;                        /* inferred */
    /* 0x22FC */ char pad22FC[0x14];                /* maybe part of sp22F8[6]s32 */
    /* 0x2310 */ s16 sp2310;                        /* inferred */
    /* 0x2312 */ char pad2312[2];
    /* 0x2314 */ s32 sp2314;                        /* inferred */
    /* 0x2318 */ char pad2318[0x14];                /* maybe part of sp2314[6]s32 */
    /* 0x232C */ s16 sp232C;                        /* inferred */
    /* 0x232E */ char pad232E[2];
    /* 0x2330 */ s32 sp2330;                        /* inferred */
    /* 0x2334 */ char pad2334[0x14];                /* maybe part of sp2330[6]s32 */
    /* 0x2348 */ s16 sp2348;                        /* inferred */
    /* 0x234A */ char pad234A[2];
    /* 0x234C */ s32 sp234C;                        /* inferred */
    /* 0x2350 */ char pad2350[0x14];                /* maybe part of sp234C[6]s32 */
    /* 0x2364 */ s16 sp2364;                        /* inferred */
    /* 0x2366 */ char pad2366[2];
    /* 0x2368 */ s32 sp2368;                        /* inferred */
    /* 0x236C */ char pad236C[0x14];                /* maybe part of sp2368[6]s32 */
    /* 0x2380 */ s16 sp2380;                        /* inferred */
    /* 0x2382 */ char pad2382[2];
    /* 0x2384 */ s32 sp2384;                        /* inferred */
    /* 0x2388 */ char pad2388[0x14];                /* maybe part of sp2384[6]s32 */
    /* 0x239C */ s16 sp239C;                        /* inferred */
    /* 0x239E */ char pad239E[2];
    /* 0x23A0 */ s32 sp23A0;                        /* inferred */
    /* 0x23A4 */ char pad23A4[0x14];                /* maybe part of sp23A0[6]s32 */
    /* 0x23B8 */ s16 sp23B8;                        /* inferred */
    /* 0x23BA */ char pad23BA[2];
    /* 0x23BC */ s32 sp23BC;                        /* inferred */
    /* 0x23C0 */ char pad23C0[0x14];                /* maybe part of sp23BC[6]s32 */
    /* 0x23D4 */ s16 sp23D4;                        /* inferred */
    /* 0x23D6 */ char pad23D6[2];
    /* 0x23D8 */ s32 sp23D8;                        /* inferred */
    /* 0x23DC */ char pad23DC[0x14];                /* maybe part of sp23D8[6]s32 */
    /* 0x23F0 */ s16 sp23F0;                        /* inferred */
    /* 0x23F2 */ char pad23F2[2];
    /* 0x23F4 */ s32 sp23F4;                        /* inferred */
    /* 0x23F8 */ char pad23F8[0x14];                /* maybe part of sp23F4[6]s32 */
    /* 0x240C */ s16 sp240C;                        /* inferred */
    /* 0x240E */ char pad240E[2];
    /* 0x2410 */ s32 sp2410;                        /* inferred */
    /* 0x2414 */ char pad2414[0x14];                /* maybe part of sp2410[6]s32 */
    /* 0x2428 */ s16 sp2428;                        /* inferred */
    /* 0x242A */ char pad242A[2];
    /* 0x242C */ s32 sp242C;                        /* inferred */
    /* 0x2430 */ char pad2430[0x14];                /* maybe part of sp242C[6]s32 */
    /* 0x2444 */ s16 sp2444;                        /* inferred */
    /* 0x2446 */ char pad2446[2];
    /* 0x2448 */ s32 sp2448;                        /* inferred */
    /* 0x244C */ char pad244C[0x14];                /* maybe part of sp2448[6]s32 */
    /* 0x2460 */ s16 sp2460;                        /* inferred */
    /* 0x2462 */ char pad2462[2];
    /* 0x2464 */ s32 sp2464;                        /* inferred */
    /* 0x2468 */ char pad2468[0x14];                /* maybe part of sp2464[6]s32 */
    /* 0x247C */ s16 sp247C;                        /* inferred */
    /* 0x247E */ char pad247E[2];
    /* 0x2480 */ s32 sp2480;                        /* inferred */
    /* 0x2484 */ char pad2484[0x14];                /* maybe part of sp2480[6]s32 */
    /* 0x2498 */ s16 sp2498;                        /* inferred */
    /* 0x249A */ char pad249A[2];
    /* 0x249C */ s32 sp249C;                        /* inferred */
    /* 0x24A0 */ char pad24A0[0x14];                /* maybe part of sp249C[6]s32 */
    /* 0x24B4 */ s16 sp24B4;                        /* inferred */
    /* 0x24B6 */ char pad24B6[2];
    /* 0x24B8 */ s32 sp24B8;                        /* inferred */
    /* 0x24BC */ char pad24BC[0x14];                /* maybe part of sp24B8[6]s32 */
    /* 0x24D0 */ s16 sp24D0;                        /* inferred */
    /* 0x24D2 */ char pad24D2[2];
    /* 0x24D4 */ s32 sp24D4;                        /* inferred */
    /* 0x24D8 */ char pad24D8[0x14];                /* maybe part of sp24D4[6]s32 */
    /* 0x24EC */ s16 sp24EC;                        /* inferred */
    /* 0x24EE */ char pad24EE[2];
    /* 0x24F0 */ s32 sp24F0;                        /* inferred */
    /* 0x24F4 */ char pad24F4[0x14];                /* maybe part of sp24F0[6]s32 */
    /* 0x2508 */ s16 sp2508;                        /* inferred */
    /* 0x250A */ char pad250A[2];
    /* 0x250C */ s32 sp250C;                        /* inferred */
    /* 0x2510 */ char pad2510[0x14];                /* maybe part of sp250C[6]s32 */
    /* 0x2524 */ s16 sp2524;                        /* inferred */
    /* 0x2526 */ char pad2526[2];
    /* 0x2528 */ s32 sp2528;                        /* inferred */
    /* 0x252C */ char pad252C[0x14];                /* maybe part of sp2528[6]s32 */
    /* 0x2540 */ s16 sp2540;                        /* inferred */
    /* 0x2542 */ char pad2542[2];
    /* 0x2544 */ s32 sp2544;                        /* inferred */
    /* 0x2548 */ char pad2548[0x14];                /* maybe part of sp2544[6]s32 */
    /* 0x255C */ s16 sp255C;                        /* inferred */
    /* 0x255E */ char pad255E[2];
    /* 0x2560 */ s32 sp2560;                        /* inferred */
    /* 0x2564 */ char pad2564[0x14];                /* maybe part of sp2560[6]s32 */
    /* 0x2578 */ s16 sp2578;                        /* inferred */
    /* 0x257A */ char pad257A[2];
    /* 0x257C */ s32 sp257C;                        /* inferred */
    /* 0x2580 */ char pad2580[0x14];                /* maybe part of sp257C[6]s32 */
    /* 0x2594 */ s16 sp2594;                        /* inferred */
    /* 0x2596 */ char pad2596[2];
    /* 0x2598 */ s32 sp2598;                        /* inferred */
    /* 0x259C */ char pad259C[0x14];                /* maybe part of sp2598[6]s32 */
    /* 0x25B0 */ s16 sp25B0;                        /* inferred */
    /* 0x25B2 */ char pad25B2[2];
    /* 0x25B4 */ s32 sp25B4;                        /* inferred */
    /* 0x25B8 */ char pad25B8[0x14];                /* maybe part of sp25B4[6]s32 */
    /* 0x25CC */ s16 sp25CC;                        /* inferred */
    /* 0x25CE */ char pad25CE[2];
    /* 0x25D0 */ s32 sp25D0;                        /* inferred */
    /* 0x25D4 */ char pad25D4[0x14];                /* maybe part of sp25D0[6]s32 */
    /* 0x25E8 */ s16 sp25E8;                        /* inferred */
    /* 0x25EA */ char pad25EA[2];
    /* 0x25EC */ s32 sp25EC;                        /* inferred */
    /* 0x25F0 */ char pad25F0[0x14];                /* maybe part of sp25EC[6]s32 */
    /* 0x2604 */ s16 sp2604;                        /* inferred */
    /* 0x2606 */ char pad2606[2];
    /* 0x2608 */ s32 sp2608;                        /* inferred */
    /* 0x260C */ char pad260C[0x14];                /* maybe part of sp2608[6]s32 */
    /* 0x2620 */ s16 sp2620;                        /* inferred */
    /* 0x2622 */ char pad2622[2];
    /* 0x2624 */ s32 sp2624;                        /* inferred */
    /* 0x2628 */ char pad2628[0x14];                /* maybe part of sp2624[6]s32 */
    /* 0x263C */ s16 sp263C;                        /* inferred */
    /* 0x263E */ char pad263E[2];
    /* 0x2640 */ s32 sp2640;                        /* inferred */
    /* 0x2644 */ char pad2644[0x14];                /* maybe part of sp2640[6]s32 */
    /* 0x2658 */ s16 sp2658;                        /* inferred */
    /* 0x265A */ char pad265A[2];
    /* 0x265C */ s32 sp265C;                        /* inferred */
    /* 0x2660 */ char pad2660[0x14];                /* maybe part of sp265C[6]s32 */
    /* 0x2674 */ s16 sp2674;                        /* inferred */
    /* 0x2676 */ char pad2676[2];
    /* 0x2678 */ s32 sp2678;                        /* inferred */
    /* 0x267C */ char pad267C[0x14];                /* maybe part of sp2678[6]s32 */
    /* 0x2690 */ s16 sp2690;                        /* inferred */
    /* 0x2692 */ char pad2692[2];
    /* 0x2694 */ s32 sp2694;                        /* inferred */
    /* 0x2698 */ char pad2698[0x14];                /* maybe part of sp2694[6]s32 */
    /* 0x26AC */ s16 sp26AC;                        /* inferred */
    /* 0x26AE */ char pad26AE[2];
    /* 0x26B0 */ s32 sp26B0;                        /* inferred */
    /* 0x26B4 */ char pad26B4[0x14];                /* maybe part of sp26B0[6]s32 */
    /* 0x26C8 */ s16 sp26C8;                        /* inferred */
    /* 0x26CA */ char pad26CA[2];
    /* 0x26CC */ s32 sp26CC;                        /* inferred */
    /* 0x26D0 */ char pad26D0[0x14];                /* maybe part of sp26CC[6]s32 */
    /* 0x26E4 */ s16 sp26E4;                        /* inferred */
    /* 0x26E6 */ char pad26E6[2];
    /* 0x26E8 */ s32 sp26E8;                        /* inferred */
    /* 0x26EC */ char pad26EC[0x14];                /* maybe part of sp26E8[6]s32 */
    /* 0x2700 */ s16 sp2700;                        /* inferred */
    /* 0x2702 */ char pad2702[2];
    /* 0x2704 */ s32 sp2704;                        /* inferred */
    /* 0x2708 */ char pad2708[0x14];                /* maybe part of sp2704[6]s32 */
    /* 0x271C */ s16 sp271C;                        /* inferred */
    /* 0x271E */ char pad271E[2];
    /* 0x2720 */ s32 sp2720;                        /* inferred */
    /* 0x2724 */ char pad2724[0x14];                /* maybe part of sp2720[6]s32 */
    /* 0x2738 */ s16 sp2738;                        /* inferred */
    /* 0x273A */ char pad273A[2];
    /* 0x273C */ s32 sp273C;                        /* inferred */
    /* 0x2740 */ char pad2740[0x14];                /* maybe part of sp273C[6]s32 */
    /* 0x2754 */ s16 sp2754;                        /* inferred */
    /* 0x2756 */ char pad2756[2];
    /* 0x2758 */ s32 sp2758;                        /* inferred */
    /* 0x275C */ char pad275C[0x14];                /* maybe part of sp2758[6]s32 */
    /* 0x2770 */ s16 sp2770;                        /* inferred */
    /* 0x2772 */ char pad2772[2];
    /* 0x2774 */ s32 sp2774;                        /* inferred */
    /* 0x2778 */ char pad2778[0x14];                /* maybe part of sp2774[6]s32 */
    /* 0x278C */ s16 sp278C;                        /* inferred */
    /* 0x278E */ char pad278E[2];
    /* 0x2790 */ s32 sp2790;                        /* inferred */
    /* 0x2794 */ char pad2794[0x14];                /* maybe part of sp2790[6]s32 */
    /* 0x27A8 */ s16 sp27A8;                        /* inferred */
    /* 0x27AA */ char pad27AA[2];
    /* 0x27AC */ s32 sp27AC;                        /* inferred */
    /* 0x27B0 */ char pad27B0[0x14];                /* maybe part of sp27AC[6]s32 */
    /* 0x27C4 */ s16 sp27C4;                        /* inferred */
    /* 0x27C6 */ char pad27C6[2];
    /* 0x27C8 */ s32 sp27C8;                        /* inferred */
    /* 0x27CC */ char pad27CC[0x14];                /* maybe part of sp27C8[6]s32 */
    /* 0x27E0 */ s16 sp27E0;                        /* inferred */
    /* 0x27E2 */ char pad27E2[2];
    /* 0x27E4 */ s32 sp27E4;                        /* inferred */
    /* 0x27E8 */ char pad27E8[0x14];                /* maybe part of sp27E4[6]s32 */
    /* 0x27FC */ s16 sp27FC;                        /* inferred */
    /* 0x27FE */ char pad27FE[2];
    /* 0x2800 */ s32 sp2800;                        /* inferred */
    /* 0x2804 */ char pad2804[0x14];                /* maybe part of sp2800[6]s32 */
    /* 0x2818 */ s16 sp2818;                        /* inferred */
    /* 0x281A */ char pad281A[2];
    /* 0x281C */ s32 sp281C;                        /* inferred */
    /* 0x2820 */ char pad2820[0x14];                /* maybe part of sp281C[6]s32 */
    /* 0x2834 */ s16 sp2834;                        /* inferred */
    /* 0x2836 */ char pad2836[2];
    /* 0x2838 */ s32 sp2838;                        /* inferred */
    /* 0x283C */ char pad283C[0x14];                /* maybe part of sp2838[6]s32 */
    /* 0x2850 */ s16 sp2850;                        /* inferred */
    /* 0x2852 */ char pad2852[2];
    /* 0x2854 */ s32 sp2854;                        /* inferred */
    /* 0x2858 */ char pad2858[0x14];                /* maybe part of sp2854[6]s32 */
    /* 0x286C */ s16 sp286C;                        /* inferred */
    /* 0x286E */ char pad286E[2];
    /* 0x2870 */ s32 sp2870;                        /* inferred */
    /* 0x2874 */ char pad2874[0x14];                /* maybe part of sp2870[6]s32 */
    /* 0x2888 */ s16 sp2888;                        /* inferred */
    /* 0x288A */ char pad288A[2];
    /* 0x288C */ s32 sp288C;                        /* inferred */
    /* 0x2890 */ char pad2890[0x14];                /* maybe part of sp288C[6]s32 */
    /* 0x28A4 */ s16 sp28A4;                        /* inferred */
    /* 0x28A6 */ char pad28A6[2];
    /* 0x28A8 */ s32 sp28A8;                        /* inferred */
    /* 0x28AC */ char pad28AC[0x14];                /* maybe part of sp28A8[6]s32 */
    /* 0x28C0 */ s16 sp28C0;                        /* inferred */
    /* 0x28C2 */ char pad28C2[2];
    /* 0x28C4 */ s32 sp28C4;                        /* inferred */
    /* 0x28C8 */ char pad28C8[0x14];                /* maybe part of sp28C4[6]s32 */
    /* 0x28DC */ s16 sp28DC;                        /* inferred */
    /* 0x28DE */ char pad28DE[2];
    /* 0x28E0 */ s32 sp28E0;                        /* inferred */
    /* 0x28E4 */ char pad28E4[0x14];                /* maybe part of sp28E0[6]s32 */
    /* 0x28F8 */ s16 sp28F8;                        /* inferred */
    /* 0x28FA */ char pad28FA[2];
    /* 0x28FC */ s32 sp28FC;                        /* inferred */
    /* 0x2900 */ char pad2900[0x14];                /* maybe part of sp28FC[6]s32 */
    /* 0x2914 */ s16 sp2914;                        /* inferred */
    /* 0x2916 */ char pad2916[2];
    /* 0x2918 */ s32 sp2918;                        /* inferred */
    /* 0x291C */ char pad291C[0x14];                /* maybe part of sp2918[6]s32 */
    /* 0x2930 */ s16 sp2930;                        /* inferred */
    /* 0x2932 */ char pad2932[2];
    /* 0x2934 */ s32 sp2934;                        /* inferred */
    /* 0x2938 */ char pad2938[0x14];                /* maybe part of sp2934[6]s32 */
    /* 0x294C */ s16 sp294C;                        /* inferred */
    /* 0x294E */ char pad294E[2];
    /* 0x2950 */ s32 sp2950;                        /* inferred */
    /* 0x2954 */ char pad2954[0x14];                /* maybe part of sp2950[6]s32 */
    /* 0x2968 */ s16 sp2968;                        /* inferred */
    /* 0x296A */ char pad296A[2];
    /* 0x296C */ s32 sp296C;                        /* inferred */
    /* 0x2970 */ char pad2970[0x14];                /* maybe part of sp296C[6]s32 */
    /* 0x2984 */ s16 sp2984;                        /* inferred */
    /* 0x2986 */ char pad2986[2];
    /* 0x2988 */ s32 sp2988;                        /* inferred */
    /* 0x298C */ char pad298C[0x14];                /* maybe part of sp2988[6]s32 */
    /* 0x29A0 */ s16 sp29A0;                        /* inferred */
    /* 0x29A2 */ char pad29A2[2];
    /* 0x29A4 */ s32 sp29A4;                        /* inferred */
    /* 0x29A8 */ char pad29A8[0x14];                /* maybe part of sp29A4[6]s32 */
    /* 0x29BC */ s16 sp29BC;                        /* inferred */
    /* 0x29BE */ char pad29BE[2];
    /* 0x29C0 */ s32 sp29C0;                        /* inferred */
    /* 0x29C4 */ char pad29C4[0x14];                /* maybe part of sp29C0[6]s32 */
    /* 0x29D8 */ s16 sp29D8;                        /* inferred */
    /* 0x29DA */ char pad29DA[2];
    /* 0x29DC */ s32 sp29DC;                        /* inferred */
    /* 0x29E0 */ char pad29E0[0x14];                /* maybe part of sp29DC[6]s32 */
    /* 0x29F4 */ s16 sp29F4;                        /* inferred */
    /* 0x29F6 */ char pad29F6[2];
    /* 0x29F8 */ s32 sp29F8;                        /* inferred */
    /* 0x29FC */ char pad29FC[0x14];                /* maybe part of sp29F8[6]s32 */
    /* 0x2A10 */ s16 sp2A10;                        /* inferred */
    /* 0x2A12 */ char pad2A12[2];
    /* 0x2A14 */ s32 sp2A14;                        /* inferred */
    /* 0x2A18 */ char pad2A18[0x14];                /* maybe part of sp2A14[6]s32 */
    /* 0x2A2C */ s16 sp2A2C;                        /* inferred */
    /* 0x2A2E */ char pad2A2E[2];
    /* 0x2A30 */ s32 sp2A30;                        /* inferred */
    /* 0x2A34 */ char pad2A34[0x14];                /* maybe part of sp2A30[6]s32 */
    /* 0x2A48 */ s16 sp2A48;                        /* inferred */
    /* 0x2A4A */ char pad2A4A[2];
    /* 0x2A4C */ s32 sp2A4C;                        /* inferred */
    /* 0x2A50 */ char pad2A50[0x14];                /* maybe part of sp2A4C[6]s32 */
    /* 0x2A64 */ s16 sp2A64;                        /* inferred */
    /* 0x2A66 */ char pad2A66[2];
    /* 0x2A68 */ s32 sp2A68;                        /* inferred */
    /* 0x2A6C */ char pad2A6C[0x14];                /* maybe part of sp2A68[6]s32 */
    /* 0x2A80 */ s16 sp2A80;                        /* inferred */
    /* 0x2A82 */ char pad2A82[2];
    /* 0x2A84 */ s32 sp2A84;                        /* inferred */
    /* 0x2A88 */ char pad2A88[0x14];                /* maybe part of sp2A84[6]s32 */
    /* 0x2A9C */ s16 sp2A9C;                        /* inferred */
    /* 0x2A9E */ char pad2A9E[2];
    /* 0x2AA0 */ s32 sp2AA0;                        /* inferred */
    /* 0x2AA4 */ char pad2AA4[0x14];                /* maybe part of sp2AA0[6]s32 */
    /* 0x2AB8 */ s16 sp2AB8;                        /* inferred */
    /* 0x2ABA */ char pad2ABA[2];
    /* 0x2ABC */ s32 sp2ABC;                        /* inferred */
    /* 0x2AC0 */ char pad2AC0[0x14];                /* maybe part of sp2ABC[6]s32 */
    /* 0x2AD4 */ s16 sp2AD4;                        /* inferred */
    /* 0x2AD6 */ char pad2AD6[2];
    /* 0x2AD8 */ s32 sp2AD8;                        /* inferred */
    /* 0x2ADC */ char pad2ADC[0x14];                /* maybe part of sp2AD8[6]s32 */
    /* 0x2AF0 */ s16 sp2AF0;                        /* inferred */
    /* 0x2AF2 */ char pad2AF2[2];
    /* 0x2AF4 */ s32 sp2AF4;                        /* inferred */
    /* 0x2AF8 */ char pad2AF8[0x14];                /* maybe part of sp2AF4[6]s32 */
    /* 0x2B0C */ s16 sp2B0C;                        /* inferred */
    /* 0x2B0E */ char pad2B0E[2];
    /* 0x2B10 */ s32 sp2B10;                        /* inferred */
    /* 0x2B14 */ char pad2B14[0x14];                /* maybe part of sp2B10[6]s32 */
    /* 0x2B28 */ s16 sp2B28;                        /* inferred */
    /* 0x2B2A */ char pad2B2A[2];
    /* 0x2B2C */ s32 sp2B2C;                        /* inferred */
    /* 0x2B30 */ char pad2B30[0x14];                /* maybe part of sp2B2C[6]s32 */
    /* 0x2B44 */ s16 sp2B44;                        /* inferred */
    /* 0x2B46 */ char pad2B46[2];
    /* 0x2B48 */ s32 sp2B48;                        /* inferred */
    /* 0x2B4C */ char pad2B4C[0x14];                /* maybe part of sp2B48[6]s32 */
    /* 0x2B60 */ s16 sp2B60;                        /* inferred */
    /* 0x2B62 */ char pad2B62[2];
    /* 0x2B64 */ s32 sp2B64;                        /* inferred */
    /* 0x2B68 */ char pad2B68[0x14];                /* maybe part of sp2B64[6]s32 */
    /* 0x2B7C */ s16 sp2B7C;                        /* inferred */
    /* 0x2B7E */ char pad2B7E[2];
    /* 0x2B80 */ s32 sp2B80;                        /* inferred */
    /* 0x2B84 */ char pad2B84[0x14];                /* maybe part of sp2B80[6]s32 */
    /* 0x2B98 */ s16 sp2B98;                        /* inferred */
    /* 0x2B9A */ char pad2B9A[2];
    /* 0x2B9C */ s32 sp2B9C;                        /* inferred */
    /* 0x2BA0 */ char pad2BA0[0x14];                /* maybe part of sp2B9C[6]s32 */
    /* 0x2BB4 */ s16 sp2BB4;                        /* inferred */
    /* 0x2BB6 */ char pad2BB6[2];
    /* 0x2BB8 */ s32 sp2BB8;                        /* inferred */
    /* 0x2BBC */ char pad2BBC[0x14];                /* maybe part of sp2BB8[6]s32 */
    /* 0x2BD0 */ s16 sp2BD0;                        /* inferred */
    /* 0x2BD2 */ char pad2BD2[2];
    /* 0x2BD4 */ s32 sp2BD4;                        /* inferred */
    /* 0x2BD8 */ char pad2BD8[0x14];                /* maybe part of sp2BD4[6]s32 */
    /* 0x2BEC */ s16 sp2BEC;                        /* inferred */
    /* 0x2BEE */ char pad2BEE[2];
    /* 0x2BF0 */ s32 sp2BF0;                          /* inferred */
    /* 0x2BF4 */ s32 sp2BF4;                        /* inferred */
    /* 0x2BF8 */ char pad2BF8[0x18];                /* maybe part of sp2BF4[7]s32 */
    /* 0x2C10 */ s32 sp2C10;                          /* inferred */
    /* 0x2C14 */ s32 sp2C14;                        /* inferred */
    /* 0x2C18 */ char pad2C18[0x18];                /* maybe part of sp2C14[7]s32 */
    /* 0x2C30 */ s32 sp2C30;                          /* inferred */
    /* 0x2C34 */ s32 sp2C34;                        /* inferred */
    /* 0x2C38 */ char pad2C38[0x18];                /* maybe part of sp2C34[7]s32 */
    /* 0x2C50 */ s32 sp2C50;                          /* inferred */
    /* 0x2C54 */ s32 sp2C54;                        /* inferred */
    /* 0x2C58 */ char pad2C58[0x18];
    /* 0x2C70 */ s32 sp2C70;
    /* 0x2C74 */ s32 sp2C74;
    /* 0x2C78 */ char pad2C78[0x18];
    /* 0x2C90 */ s32 sp2C90;
    /* 0x2C94 */ s32 sp2C94;
    /* 0x2C98 */ char pad2C98[0x18];
    /* 0x2CB0 */ s32 sp2CB0;                          /* inferred */
    /* 0x2CB4 */ s32 sp2CB4;                        /* inferred */
    /* 0x2CB8 */ char pad2CB8[0x18];
    /* 0x2CD0 */ s32 sp2CD0;
    /* 0x2CD4 */ s32 sp2CD4;
    /* 0x2CD8 */ char pad2CD8[0x18];
    /* 0x2CF0 */ s32 sp2CF0;                          /* inferred */
    /* 0x2CF4 */ s32 sp2CF4;                        /* inferred */
    /* 0x2CF8 */ char pad2CF8[0x18];                /* maybe part of sp2CF4[7]s32 */
    /* 0x2D10 */ s32 sp2D10;                          /* inferred */
    /* 0x2D14 */ s32 sp2D14;                        /* inferred */
    /* 0x2D18 */ char pad2D18[0x18];                /* maybe part of sp2D14[7]s32 */
    /* 0x2D30 */ s32 sp2D30;                          /* inferred */
    /* 0x2D34 */ s32 sp2D34;                        /* inferred */
    /* 0x2D38 */ char pad2D38[0x18];
    /* 0x2D50 */ s32 sp2D50;
    /* 0x2D54 */ s32 sp2D54;
    /* 0x2D58 */ char pad2D58[0x18];
    /* 0x2D70 */ s32 sp2D70;                          /* inferred */
    /* 0x2D74 */ s32 sp2D74;                        /* inferred */
    /* 0x2D78 */ char pad2D78[0x18];                /* maybe part of sp2D74[7]s32 */
    /* 0x2D90 */ s32 sp2D90;                          /* inferred */
    /* 0x2D94 */ s32 sp2D94;                        /* inferred */
    /* 0x2D98 */ char pad2D98[0x18];                /* maybe part of sp2D94[7]s32 */
    /* 0x2DB0 */ s32 sp2DB0;                          /* inferred */
    /* 0x2DB4 */ s32 sp2DB4;                        /* inferred */
    /* 0x2DB8 */ char pad2DB8[0x18];                /* maybe part of sp2DB4[7]s32 */
    /* 0x2DD0 */ s32 sp2DD0;                          /* inferred */
    /* 0x2DD4 */ s32 sp2DD4;                        /* inferred */
    /* 0x2DD8 */ char pad2DD8[0x18];                /* maybe part of sp2DD4[7]s32 */
    /* 0x2DF0 */ s32 sp2DF0;                          /* inferred */
    /* 0x2DF4 */ s32 sp2DF4;                        /* inferred */
    /* 0x2DF8 */ char pad2DF8[0x18];                /* maybe part of sp2DF4[7]s32 */
    /* 0x2E10 */ s32 sp2E10;                          /* inferred */
    /* 0x2E14 */ s32 sp2E14;                        /* inferred */
    /* 0x2E18 */ char pad2E18[0x18];                /* maybe part of sp2E14[7]s32 */
    /* 0x2E30 */ s32 sp2E30;                          /* inferred */
    /* 0x2E34 */ s32 sp2E34;                        /* inferred */
    /* 0x2E38 */ char pad2E38[0x18];                /* maybe part of sp2E34[7]s32 */
    /* 0x2E50 */ s32 sp2E50;                          /* inferred */
    /* 0x2E54 */ s32 sp2E54;                        /* inferred */
    /* 0x2E58 */ char pad2E58[0x18];
};                                                  /* size = 0x2E70 */
