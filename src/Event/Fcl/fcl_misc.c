#include "temporary.h"
/* FUSION_GLOBALS */
extern int *piGpffffb98c;
typedef int (*code)(...);
/* FUSION_EXACT_PROTOS */
u32 FUN_003c8b50();
extern void FUN_003c9240(int *);
extern u64 FUN_003c9290(int *,u64,u64);
extern s8 FUN_003c9340(int *);
extern void FUN_003c9390(int *);
extern u32 FUN_003c9460(int *);
#pragma alias fclMisc9240Call FUN_003c9240
extern void fclMisc9240Call(int *);
#pragma alias fclMisc9290Call FUN_003c9290
extern u64 fclMisc9290Call(int *,u64,u64);
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
typedef struct FclMiscVec4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} FclMiscVec4;
typedef union FclMiscColor
{
    f32 packed;
    u8 channel[4];
} FclMiscColor;
typedef union FclMiscPair
{
    FclMiscVec2 vec;
    u64 bits;
} FclMiscPair;
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
#pragma alias DAT_006a3e18_abs DAT_006a3e18
extern char DAT_006a3e18_abs[];
extern u32 DAT_006a3f70;
extern u32 DAT_006a3f88;
extern u32 DAT_006a3f8c;
extern u32 DAT_006a3f90;
extern u32 DAT_006a41e8;
extern u32 DAT_006a41f8;
#pragma alias DAT_006a41e8_abs DAT_006a41e8
extern u8 DAT_006a41e8_abs[];
#pragma alias DAT_006a41f8_abs DAT_006a41f8
extern u8 DAT_006a41f8_abs[];
#pragma alias fclMiscInitialRotation DAT_006a4218
extern u64 fclMiscInitialRotation[];
#pragma alias fclMiscInitialRotationZ DAT_006a4220
extern f32 fclMiscInitialRotationZ[];
#pragma alias fclMiscInitialTranslation DAT_006a4228
extern u64 fclMiscInitialTranslation[];
#pragma alias fclMiscInitialTranslationZ DAT_006a4230
extern f32 fclMiscInitialTranslationZ[];
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

extern u32 LAB_003c84bc;
extern u32 LAB_003cf728;
extern u32 LAB_003cf7a4;
extern u32 LAB_003cf9d8;
extern u8 * PTR_LAB_006a4060;
extern u8 * PTR_s_facility_pss_battle_pak_006a4040;
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
#pragma alias fclMiscC31b0Call FUN_004c31b0
extern void fclMiscC31b0Call(f32, void *, void *, s32);
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

#undef FUN_003c8400
// FUN_003C8400 NONMATCHING
u32 FUN_003c8400(u32 param_1,int param_2)
{
  u32 lVar2;
  int iVar4;
  int iVar3;
  u32 *puVar5;
  int iVar6;

  if (param_1 == 0) {
    FUN_0019d3f0("fclMisc.c",0x396);
  }
  if ((param_2 < 0) || (0xb < param_2)) {
    FUN_0019d3f0("fclMisc.c",0x397);
  }
  iVar6 = (int)param_1;
  puVar5 = (u32 *)(iVar6 + param_2 * 0xc + 0x1c);
  if ((*puVar5 & 2) == 0) {
    for (iVar3 = *(int *)(*(int *)(iVar6 + 0x18) + 4);
         iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
      iVar4 = *(int *)(iVar3 + 0x14);
      if (*(int *)(iVar4 + 4) == param_2) goto LAB_003c84bc;
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
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#undef FUN_003c8550
// FUN_003C8550


u64 FUN_003c8550(u8 *param_1)
{
  register u8 *context;
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
    register int *pContext;

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
// FUN_003C8B50 NONMATCHING


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

      if ((*(u32 *)(iVar5 + 0x14) & 1 << (uVar1 & 0x1f)) == 0) {

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
    fclMisc9390Call((int *)(param_2 + 0x10));
    if (fclMisc9340Call((int *)(param_2 + 0x10)) == 0) {
      fclMisc9460DirectCall((int *)(param_2 + 0x10));
    }


  }



  *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) | 4;
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
#pragma push
/* Removing this worsens FUN_003c9000 (nd10 -> nd72) - measured W161. */
#pragma opt_rebuildconditionals off
// FUN_003C9000 NONMATCHING


void FUN_003c9000(int param_4, int param_5, f32 param_1, u32 param_6,
                  f32 param_2, f32 param_3, int param_7, u32 param_8)



{

  u32 uVar1;

  int iVar2;

  u32 offset;
  u16 uVar3;
  f32 scaled;

  

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

    scaled = 4096.0f * param_2;
    if (2.1474836e+09f <= scaled) {
      goto param2_large;
    }
    uVar3 = (u16)(int)scaled;
    goto param2_done;
param2_large:
    uVar3 = (u16)((u32)(int)(scaled - 2.1474836e+09f) | 0x80000000);
param2_done:
    *(u16 *)(iVar2 + 0x28) = uVar3;

    scaled = 4096.0f * param_3;
    if (2.1474836e+09f <= scaled) {
      goto param3_large;
    }
    uVar3 = (u16)(int)scaled;
    goto param3_done;
param3_large:
    uVar3 = (u16)((u32)(int)(scaled - 2.1474836e+09f) | 0x80000000);
param3_done:
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
// FUN_003C9570 NONMATCHING


void FUN_003c9570(u64 param_1)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int aiStack_30 [8];

  int aiStack_10 [4];

  

  iVar2 = 0;

  piVar8 = (int *)&DAT_006a3f70;

  piVar7 = aiStack_30;

  iVar6 = 3;

  do {

    iVar3 = *piVar8;

    iVar4 = piVar8[1];

    piVar8 = piVar8 + 2;

    iVar6 = iVar6 + -1;

    *piVar7 = iVar3;

    piVar7[1] = iVar4;

    piVar7 = piVar7 + 2;

  } while (0 < iVar6);

  aiStack_10[0] = DAT_006a3f88;

  aiStack_10[1] = DAT_006a3f8c;

  aiStack_10[2] = DAT_006a3f90;

  iVar6 = FUN_003af380();

  bVar1 = (short)iVar6 != -1;

  if (bVar1) {

    iVar3 = FUN_003af390();

  }

  else {

    iVar2 = FUN_003af390();

    iVar6 = aiStack_30[iVar2 * 2];

    iVar3 = aiStack_30[iVar2 * 2 + 1];

  }

  iVar4 = FUN_003af360();

  if ((short)iVar4 == -1) {

    iVar4 = 0x140 - (iVar6 >> 1);

  }

  iVar5 = FUN_003af370();

  if ((short)iVar5 == -1) {

    iVar5 = 0xe0 - (iVar3 * 0x19 >> 1);

  }

  if (bVar1) {

    FUN_003a3ce0(param_1,iVar4 << 4,iVar5 << 3);

    FUN_003a8650(param_1,iVar4 << 4,iVar5 << 3,0,iVar6 << 4,iVar3 * 200);

  }

  else {

    FUN_003a3ce0(param_1,0x4d0,0x4e0);

    iVar2 = aiStack_10[iVar2];

    FUN_003a8650(param_1,0,0x408,0,0x2800,iVar2 << 3);

    FUN_003a6a80(param_1,0x254,iVar2 + 0x71);

  }

  return;

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
// FUN_003C9850 NONMATCHING


u64 FUN_003c9850(u64 param_1,long param_2,u16 param_3,u16 param_4)



{

  u8 *puVar1;

  u32 uVar2;

  u64 uVar3;

  int iVar4;

  u32 *puVar5;

  u8 **ppuVar6;

  int *piVar7;

  u32 auStack_60 [16];

  int aiStack_20 [8];

  

  if ((param_2 < 0) || (4 < param_2)) {

    FUN_0019d3f0("fclMisc.c",0x661);

  }

  ppuVar6 = &PTR_s_facility_pss_battle_pak_006a4040;

  piVar7 = aiStack_20;

  iVar4 = 5;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *piVar7 = (int)puVar1;

    piVar7 = piVar7 + 1;

  } while (0 < iVar4);

  ppuVar6 = &PTR_LAB_006a4060;

  puVar5 = auStack_60;

  iVar4 = 0xf;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *puVar5 = (u32)puVar1;

    puVar5 = puVar5 + 1;

  } while (0 < iVar4);

  uVar2 = (*DAT_00960178)(0xec,0x40000);

  FUN_00521408(uVar2,0,0xec);

  piVar7 = (int *)uVar2;

  piVar7[1] = 1;

  iVar4 = (int)param_2;

  *piVar7 = iVar4;

  piVar7[0x33] = aiStack_20[iVar4];

  FUN_00521250(piVar7 + 0x37,auStack_60 + iVar4 * 3,0xc);

  *(u16 *)(piVar7 + 3) = param_3;

  *(u16 *)((int)piVar7 + 0xe) = param_4;

  if ((short)piVar7[3] < 1) {

    *(u16 *)(piVar7 + 3) = 1;

  }

  if (*(short *)((int)piVar7 + 0xe) < 1) {

    *(u16 *)((int)piVar7 + 0xe) = 1;

  }

  piVar7[6] = -1;

  uVar3 = FUN_00194b20(param_1,0x6a40a0,10,0x3ca230,0x3ca6b0,uVar2);

  FUN_00194b20(uVar3,0x6a40b0,0x1070,0x3ca610,0,uVar2);

  FUN_00194b20(uVar3,0x6a40c0,0x18aa,0x3ca660,0,uVar2);

  iVar4 = FUN_001339a0(0,uVar3,0x1488,0,0xffffffffffffffff);

  piVar7[0x31] = iVar4;

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x67c);

  FUN_005225a8(0x6a40d8);

  FUN_001052b0(0x6a40d8);

  return uVar3;

}
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#undef FUN_003c9cd0
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
          return 0;
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
// FUN_003CA780 NONMATCHING


u64

FUN_003ca780(u32 param_1,u32 param_2,float param_3,float param_4,int param_5,

            int param_6,u32 param_7,u32 param_8,u16 param_9,u16 param_10

            ,u32 param_11)



{

  int iVar1;

  u32 uVar2;

  u16 uVar3;

  

  uVar2 = FUN_001158b0(0,param_11,param_8);

  iVar1 = (int)uVar2;

  *(float *)(iVar1 + 0x10) = (float)param_5;

  *(float *)(iVar1 + 0x14) = (float)param_6;

  *(u32 *)(iVar1 + 0x2c) = param_1;

  *(char *)(iVar1 + 0x19) = -1 - (char)param_7;

  *(char *)(iVar1 + 0x30) = (char)((u32)param_7 >> 0x18);

  *(char *)(iVar1 + 0x31) = (char)((u32)param_7 >> 0x10);

  *(char *)(iVar1 + 0x32) = (char)((u32)param_7 >> 8);

  *(u16 *)(iVar1 + 0x24) = param_9;

  *(u16 *)(iVar1 + 0x26) = param_10;

  *(u32 *)(iVar1 + 0x20) = param_2;

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

  FUN_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return 0;

}
#define FUN_003ca780(...) fclMiscCa780Call(__VA_ARGS__)
#undef FUN_003ca960
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

  

  pfVar2 = (float *)0x8;

  pfVar3 = &stackPair.vec.x;

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

      lVar5 = (int)*(short *)(param_1 + 0x14) - (int)*(short *)(param_1 + 0x16);

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
// FUN_003CACC0 NONMATCHING


void FUN_003cacc0(int param_1)



{

  short sVar1;

  int iVar2;

  short *psVar3;

  short *psVar4;

  int iVar5;
  long lVar6;


  

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

    lVar6 = (long)(iVar5 + 1);

  }

  if ((long)*(char *)(param_1 + 0xe8) == (long)iVar5) {

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
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#undef FUN_003cb050
#pragma push
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

      FUN_0040ec50(0,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_18,0,0x17,0x3cb050

                  );

      FUN_00523ac8(auStack_18,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_18,1,0x1b,

                   0x3cb050);

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
    FUN_003cacc0((int)piVar8 + 0x12);

    if ((*(u16 *)((int)piVar8 + 0x22) != 0) && (piVar8[0x1b] != 0)) {

      uVar6 = FUN_0016deb0(*(u8 *)

                            ((u32)*(u16 *)((int)piVar8 + 0x22) * 0xe + iGpffffb730 + 2));

      uVar4 = FUN_0016dba0(uVar6);

      FUN_003ca780(0,0,1.0f,1.0f,0x169,0xc9,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,0

                   ,0,piVar8[0x36]);

      FUN_00523ac8(auStack_10,&gp0xffffaa10,uVar4);

      FUN_0040ec50(0,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_10,0,0x17,0x3cb050

                  );

      FUN_00523ac8(auStack_10,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_10,1,0x1b,

                   0x3cb050);

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

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;


  u16 uVar1;

  int lVar7;

  struct {
    u64 pad;
    u16 values[16];
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
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = auStack_28[iVar6 + 0xc];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x32,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 0xe],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x36,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = auStack_28[iVar6 + 0xc];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x33,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 0xe],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x37,0,0,param_1[0x34]);
  
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
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = auStack_28[iVar6 + 8];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x32,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 10],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x36,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = auStack_28[iVar6 + 8];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x33,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 10],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x37,0,0,param_1[0x34]);
  
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
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = auStack_28[iVar6 + 4];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x46,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 6],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x48,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = auStack_28[iVar6 + 4];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x45,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 6],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x47,0,0,param_1[0x34]);
  
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
  
      if ((char)param_1[0x3a] != lVar7) {
  
        uVar1 = auStack_28[iVar6];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x46,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x35,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x48,0,0,param_1[0x34]);
  
      }
  
      else {
  
        uVar1 = auStack_28[iVar6];
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     0x45,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,auStack_28[iVar6 + 2],10,
  
                     *(s16 *)((char *)param_1 + 0x12) | -0x100,0x34,0,0,param_1[0x34]);
  
        FUN_003ca780(0,0,1.0f,1.0f,uVar1,10,*(s16 *)((char *)param_1 + 0x12) | -0x100,
  
                     iVar6 * 2 + 0x47,0,0,param_1[0x34]);
  
      }
  
      lVar7 = (long)(iVar6 + 1);
  
    }
  
  } break; default: FUN_003ca780(0,0,1.0f,1.0f,0xc1,8,*(s16 *)((char *)param_1 + 0x12) | -0x100,0x14,0,0,
  
               param_1[0x34]); break; }

  return;

}
#undef auStack_28
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)
#undef FUN_003ccc40
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

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | 0xff00,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | 0xff00,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | 0xff00,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,3,0,0,
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
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | 0xff00,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | 0xff00,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    switch (iVar1) { case 0: case 1: case 3: FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | 0xff00,3,0,
                 0,*(int *)(context + 0xd4)); break; case 2: case 4: FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | 0xff00,0x15,
                 0,0,*(int *)(context + 0xd0));
    FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | 0xff00,
                 0x16,0,0,*(int *)(context + 0xd0)); break; }
  }
  return;
}
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)
// Retail sibling at 0x3cd0a0: standalone jr $ra nullsub.
// FUN_003CD0A0
void FUN_003cd0a0(void)
{
}

#undef FUN_003cd0b0
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

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | 0xff00,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | 0xff00,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | 0xff00,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,3,0,0,
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
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | 0xff00,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | 0xff00,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    if ((iVar1 == 4) || (iVar1 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | 0xff00,0x15,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | 0xff00,
                   0x16,0,0,*(int *)(context + 0xd0));
    }
    else if (((iVar1 == 3) || (iVar1 == 1)) || (iVar1 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | 0xff00,3,0,0,
                   *(int *)(context + 0xd4));
    }
  }

  if (*(int *)(context + 0xd4) != 0) {
    FUN_003ca780(0,0,1.0f,1.0f,0x1d4,0x1a1,*(s16 *)(context + 0x12) | 0xff00,0xd,
                 0,0,*(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x231,0x1a1,*(s16 *)(context + 0x12) | 0xff00,0xe,
                 0,0,*(int *)(context + 0xd4));
  }
  return;
}
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
// Retail sibling at 0x3cd590: standalone jr $ra nullsub.
// FUN_003CD590
void FUN_003cd590(void)
{
}
#undef FUN_003cd5a0
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

  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x165,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,0,0,0,*(int *)(context + 0xd0));
  FUN_003ca780(0,-35.0f,1.0f,1.0f,-0x61,0xbd,
               *(s16 *)(context + 0x12) | 0xff00,1,-0x104,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x25,*(s16 *)(context + 0x12) | 0xff00,5,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0x16b,0x25,*(s16 *)(context + 0x12) | 0xff00,6,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0x62,*(s16 *)(context + 0x12) | 0xff00,4,0,0,
               *(int *)(context + 0xd0));
  FUN_003ca780(0,0,1.0f,1.0f,0,0,*(s16 *)(context + 0x12) | 0xff00,3,0,0,
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
    FUN_003ca780(0,0,1.0f,1.0f,0xaa,8,*(s16 *)(context + 0x12) | 0xff00,0,0,0,
                 *(int *)(context + 0xd4));
    FUN_003ca780(0,0,1.0f,1.0f,0x178,8,*(s16 *)(context + 0x12) | 0xff00,1,0,0,
                 *(int *)(context + 0xd4));
  }

  if (*(s16 *)(context + 0xea) == 1) {
    iVar1 = *(int *)context;
    if ((iVar1 == 4) || (iVar1 == 2)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x16,0xc,*(s16 *)(context + 0x12) | 0xff00,0x15,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x21b,0xc,*(s16 *)(context + 0x12) | 0xff00,
                   0x16,0,0,*(int *)(context + 0xd0));
    }
    else if (((iVar1 == 3) || (iVar1 == 1)) || (iVar1 == 0)) {
      FUN_003ca780(0,0,1.0f,1.0f,0x2a,0xc,*(s16 *)(context + 0x12) | 0xff00,2,0,0,
                   *(int *)(context + 0xd4));
      FUN_003ca780(0,0,1.0f,1.0f,0x207,0xc,*(s16 *)(context + 0x12) | 0xff00,3,0,0,
                   *(int *)(context + 0xd4));
    }
  }
  return;
}
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
// FUN_003CDA60 NONMATCHING


void FUN_003cda60(u32 param_1)



{

  u32 uVar1;

  int iVar2;

  u64 uStack_20;

  float fStack_18;

  u64 uStack_10;

  float fStack_8;

  FclMiscColor color;

  

  uStack_10 = fclMiscInitialRotation[0];

  fStack_8 = fclMiscInitialRotationZ[0];

  uStack_20 = fclMiscInitialTranslation[0];

  fStack_18 = fclMiscInitialTranslationZ[0];

  color.packed = DAT_007cd718;

  uVar1 = DAT_00960178_abs[0](0x100,0x40000);

  FUN_00521408(uVar1,0,0x100);

  iVar2 = (int)uVar1;

  *(u16 *)(iVar2 + 0xc) = 0;

  *(u32 *)(iVar2 + 8) = 1;

  fclMiscC31b0Call(180.0f,(void *)(iVar2 + 0x40),&uStack_20,0);

  FUN_004c35d0(iVar2 + 0x40,&uStack_10,2);

  *(u8 *)(iVar2 + 0x80) = color.channel[0];

  *(u8 *)(iVar2 + 0x81) = color.channel[1];

  *(u8 *)(iVar2 + 0x82) = color.channel[2];

  *(u8 *)(iVar2 + 0x83) = color.channel[3];

  FUN_0016bc80(0,*(u16 *)(iVar2 + 0xc),iVar2 + 0x84);

  FUN_0016bdb0(0,*(u16 *)(iVar2 + 0xc),iVar2 + 0x94);

  FUN_00194b20(param_1,0x7cd720,0x147c,0x3ce2a0,0x3cf080,uVar1);

  return;

}
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












// FUN_003CE2A0 NONMATCHING
u64 FUN_003ce2a0(u64 param_1)



{

  int iVar1;

  u8 *puVar2;

  short sVar3;

  u8 *puVar4;

  u32 uVar5;

  u64 uVar6;

  long lVar7;

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


      }

    }

  }

  return 0;

}
#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#undef FUN_003cea50
// FUN_003CEA50 NONMATCHING


u64 FUN_003cea50(u16 *param_1)



{

  u32 uVar1;

  u32 uVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  u64 uVar6;

  u64 uVar7;

  long lVar8;

  float *pfVar9;

  u32 *puVar10;

  u32 *puVar11;


  int iVar12;

  float fVar13;

  u32 uVar14;

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

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  u32 uStack_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  u32 uStack_c0;

  u32 uStack_bc;

  u32 uStack_b8;

  u32 auStack_b0 [16];

  u32 uStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_5c;

  u32 uStack_58;

  u32 uStack_54;

  u64 uStack_48;

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  u64 uStack_28;
  float fStack_20;

  float fStack_18;

  float fStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u8 auStack_4 [3];

  u8 bStack_1;

  

  uVar6 = FUN_00198590();

  uVar14 = FUN_001a4600(uVar6);

  iVar4 = FUN_00198560();

  uStack_60 = *(u32 *)(iVar4 + 0x18);

  uStack_5c = *(u32 *)(iVar4 + 0x1c);

  uStack_58 = *(u32 *)(iVar4 + 0x20);

  uStack_54 = *(u32 *)(iVar4 + 0x24);

  iVar4 = FUN_00198570();

  uStack_70 = *(u32 *)(iVar4 + 0x18);

  uStack_6c = *(u32 *)(iVar4 + 0x1c);

  uStack_68 = *(u32 *)(iVar4 + 0x20);

  uStack_64 = *(u32 *)(iVar4 + 0x24);

  iVar4 = FUN_00198590();

  uStack_10 = *(u32 *)(iVar4 + 0x78);

  uStack_c = *(u32 *)(iVar4 + 0x7c);

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

  FUN_001a4580(0x42200000,uVar6);

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

  fStack_f0 = 1.0f - (vStack_100.y * fVar13 + vStack_100.z * fVar15);

  fStack_ec = vStack_100.x * fVar13 + fVar15 * vStack_100.w;

  fStack_e8 = vStack_100.z * fVar16 - fVar13 * vStack_100.w;

  fStack_e0 = vStack_100.x * fVar13 - fVar15 * vStack_100.w;

  fStack_dc = 1.0f - (vStack_100.z * fVar15 + vStack_100.x * fVar16);

  fStack_d8 = vStack_100.y * fVar15 + fVar16 * vStack_100.w;

  fStack_d0 = vStack_100.z * fVar16 + fVar13 * vStack_100.w;

  fStack_cc = vStack_100.y * fVar15 - fVar16 * vStack_100.w;

  fStack_c8 = 1.0f - (vStack_100.x * fVar16 + vStack_100.y * fVar13);

  uStack_c0 = 0;

  uStack_bc = 0;

  uStack_b8 = 0;

  uStack_e4 = 3;

  FUN_004c2f30(&fStack_f0,&fStack_f0,iVar12);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),&fStack_f0,0);

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

  FUN_001a4580(uVar14,uVar6);

  uVar6 = FUN_00198560();

  FUN_004944b0(uVar6,&uStack_60);

  uVar6 = FUN_00198570();

  FUN_004944b0(uVar6,&uStack_70);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),auStack_b0,0);

  iVar4 = FUN_00198570();

  *(u8 *)(iVar4 + 2) = 3;

  FUN_00198570();

  uVar6 = FUN_00198590();

  FUN_004c9d20(uVar6,&uStack_10);

  return 0;

}
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#undef FUN_003cf6c0
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

  

  puVar7 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

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

    puVar7 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

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

    iVar6 = *(int *)(DAT_007ce680 + 0x24) + sVar4 * 0x14;

    puVar7 = (u16 *)(iVar6 + 4);

    *(u32 *)(iVar6 + 8) = *(u32 *)(puVar2 + 2);

    *(u16 *)(iVar6 + 4) = *puVar2;

    *(short *)(iVar6 + 0xc) = sVar4;

    uVar3 = *(u32 *)(iVar6 + 8);

    FUN_00106860(sVar4,(short)((u32)uVar3 >> 0x10),(u16)((u32)uVar3 >> 8) & 0xff,

                 (u16)uVar3 & 0xff);

    FUN_00106ec0(*(u16 *)(iVar6 + 0xc),1);

    FUN_00106f30(*(u16 *)(iVar6 + 0xc),0);

    uVar1 = *puVar7;

    *puVar7 = uVar1 | 1;

    *puVar7 = uVar1 | 3;

    FUN_003c49e0(DAT_007ce680,DAT_007ce680 + 4,param_1);

    sVar5 = sVar4;

  }

  return sVar5;

}
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#undef FUN_003cf960
// FUN_003CF960 NONMATCHING


u32 FUN_003cf960(int param_1,u16 param_2)



{

  u8 bVar1;

  short sVar2;

  u32 uVar3;

  u16 *puVar4;

  int iVar5;

  

  puVar4 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

  iVar5 = 0;

  do {

    if (2 < iVar5) {

      sVar2 = -1;

LAB_003cf9d8:

      if (sVar2 == -1) {

        uVar3 = FUN_003c4910(DAT_007ce680,0,0x14);

        puVar4 = *(u16 **)((int)uVar3 + 0x14);

        *(int *)(puVar4 + 2) = param_1;

        *puVar4 = param_2 & 0xff00 | 3;

      }

      else {

        iVar5 = sVar2 * 0x14 + *(int *)(DAT_007ce680 + 0x24);

        bVar1 = *(u8 *)(iVar5 + 4);

        *(u16 *)(iVar5 + 4) = (u16)bVar1;

        *(u16 *)(iVar5 + 4) = (u16)bVar1 | param_2 & 0xff00;

        FUN_005225a8(0x7cd728,0x6a4270,0x1b6);

        FUN_005225a8(0x6a42f0,sVar2);

        FUN_001052b0(0x6a42f0,sVar2);

        uVar3 = 0;

      }

      return uVar3;

    }

    if (((*puVar4 & 1) != 0) && (*(int *)(puVar4 + 2) == param_1)) {

      sVar2 = (short)iVar5;

      goto LAB_003cf9d8;

    }

    puVar4 = puVar4 + 10;

    iVar5 = iVar5 + 1;

  } while( 1 );

}
#define FUN_003cf960(...) ((u32 (*)(...))FUN_003cf960)(__VA_ARGS__)
#undef FUN_003cfb50
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

  

  puVar8 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

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
