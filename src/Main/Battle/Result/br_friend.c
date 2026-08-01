#include "Main/Battle/Result/br_friend.h"




// TODO


#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "Main/Social/sfl_psel.h"

#pragma alias func_0020c500_y2 func_0020c500
#pragma alias func_0020c400_y2 func_0020c400
#pragma alias sflResSetSpriteScale_y2 sflResSetSpriteScale
#pragma alias sflResSetSpriteRotation_y2 sflResSetSpriteRotation
#pragma alias sflResult001f99f0_y2 sflResult001f99f0
#pragma alias sflResult001f9100_y2 sflResult001f9100
#pragma alias sflResSetSpritePosition_y2 sflResSetSpritePosition
#pragma alias func_00175ce0_y2 func_00175ce0_y2
#pragma alias func_001761b0_y2 func_001761b0_y2
#pragma alias func_00176100_y2 func_00176100_y2
#pragma alias func_001fbdf0_y2 func_001fbdf0_y2
#pragma alias func_001fbfa0_y2 func_001fbfa0_y2
#pragma alias func_001fb4b0_y2 func_001fb4b0_y2
#pragma alias DAT_007ce430_y2 DAT_007ce430_y2
#pragma alias sflResult001f9770_y2 sflResult001f9770_y2
#pragma alias sflResult001f9800_y2 sflResult001f9800_y2
#pragma alias sflResult001f9890_y2 sflResult001f9890_y2
#pragma alias sflResult001f9630_y2 sflResult001f9630_y2
#pragma alias func_00209d00_y2 func_00209d00_y2
#pragma alias func_004bdde0_y2 func_004bdde0_y2
#pragma alias datGetMaxHp_y2 datGetMaxHp_y2


static u32* sSflResult; // iGpffffb5f0 / puGpffffb5f0

extern void brRoot001f1df0(u16* members, s32* count);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern void FUN_001f6e80(void);







extern u8* func_00209d00(void);
extern void func_0021a670(u32, u32);
extern void func_0021a760(u16);
extern u32 func_0020c500_y2(float, void*);
extern void func_0020c400_y2(u32, void*, const float*, float*);
extern void func_004bdde0(float, float*, const float*, u32);
extern void func_001f6630(void);
extern void func_001f7210(void);
extern void func_0034ff90(u32, const u8*);
extern void func_0034ff70(u32, float);
extern void func_0034fdf0(u32, const float*);
extern void func_0034fe30(float, u32, float, float);
extern void func_0034fd30(u32);
extern void func_0034fd70(u32, u32);
extern void datSetFlag(s32, u8);
extern u32 func_001761b0(DatPersonaWork*);
extern void func_00175ce0(DatPersonaWork*, u8*);
extern void func_00176100(DatPersonaWork*, u8*);
extern void func_001fb4b0(void*, s32, s32, s32, s32*, s32*);
extern u32 func_001fba70(u16);
extern void func_00176840(DatPersonaWork*, u16);
extern void func_001768e0(DatPersonaWork*, u16);
extern u8* iGpffffb740;

extern u8* iGpffffb730;
void func_001fa0d0(void);
void func_001fa450(void);
void func_001fa4f0(u32 param_1);
u32 func_001faea0(void);
void func_001fb130(u64 param_1,u64 param_2);
void func_001fb1b0(u64 param_1,u64 param_2);
void func_001fb1f0(DatPersonaWork* persona, u16* output, s32* outputCount);
void func_001fb3f0(int param_1,int param_2,int param_3,int *param_4,int *param_5);
u16 func_001fb560(u32 param_1);
u32 func_001fba70(u16 param_1);
int func_001fbca0(u16 param_1);
u8 * func_001fbd50(u16 param_1,int param_2);
int func_001fbdf0(s32 start, s32 end, s32 amount, s32 category, s32 scaleMode);
int func_001fbfa0(int param_1,int param_2,int param_3,short param_4,int param_5,long param_6);
void func_001fc1f0(void);
u8 func_001fc230(DatPersonaWork* persona);
u32 func_001fc3c0(DatPersonaWork* persona);
u32 func_001fc590(u8* event, void* target);
u32 func_001fc720(u8* persona);
int func_001fc870(u8* event, void* target);
void func_001fc980(u8* event, u16* result, s32* count);
void func_001fcb30(u8* event, u32* result, s32* count);
void func_001fccc0(u8* src, u8* dst, u32 skill);
void func_001fce20(u8* persona, u16* skills, s32 count);
void func_001fd350(u8* persona, u32* skills, s32 count);
extern s16 FUN_001706c0(s16 pcId, s16 index);
extern u8* pbGpffffb758;
extern u16* puGpffffb74c;
extern u16* puGpffffb730;
extern u16* puGpffffb750;
extern u16* psGpffffb754;
extern char gp0xffff9700[];
extern char gp0xffff9708[];
extern char gp0xffff9710[];
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u8* DAT_007ce430;

extern u8* iGpffffb738;
extern int iGpffffb75c;
extern int iGpffffb760;
#pragma alias sflResultMsgC28_abs DAT_00684c28
#pragma alias sflResultMsgC40_abs DAT_00684c40
#pragma alias sflResultMsgC60_abs DAT_00684c60
#pragma alias sflResultMsgC70_abs DAT_00684c70
#pragma alias sflResultMsgC80_abs DAT_00684c80
#pragma alias sflResultMsgC90_abs DAT_00684c90
#pragma alias sflResultMsgCA0_abs DAT_00684ca0
#pragma alias sflResultMsgCD0_abs DAT_00684cd0
#pragma alias sflResultMsgCE0_abs DAT_00684ce0
#pragma alias sflResultMsgCF8_abs DAT_00684cf8
#pragma alias sflResultMsgD08_abs DAT_00684d08
#pragma alias sflResultMsgD20_abs DAT_00684d20
#pragma alias sflResultMsgD30_abs DAT_00684d30
#pragma alias sflResultMsgD40_abs DAT_00684d40
extern const char sflResultMsgC28_abs[];
extern const char sflResultMsgC40_abs[];
extern const char sflResultMsgC60_abs[];
extern const char sflResultMsgC70_abs[];
extern const char sflResultMsgC80_abs[];
extern const char sflResultMsgC90_abs[];
extern const char sflResultMsgCA0_abs[];
extern const char sflResultMsgCD0_abs[];
extern const char sflResultMsgCE0_abs[];
extern const char sflResultMsgCF8_abs[];
extern const char sflResultMsgD08_abs[];
extern const char sflResultMsgD20_abs[];
extern const char sflResultMsgD30_abs[];
extern const char sflResultMsgD40_abs[];
#pragma alias sflResultAssertBA8_abs DAT_00684ba8
extern const char sflResultAssertBA8_abs[];
extern int iGpffffb764;
extern int iGpffffb768;
extern int iGpffffb76c;
extern int iGpffffb770;
extern int iGpffffb774;
extern int iGpffffb778;
extern u8* iGpffffb7ac;
extern u8* iGpffffb7b8;
extern f32 fGpffff8070;
extern f32 fGpffff83b0;
extern f32 fGpffff83b4;
extern u8* pcGpffffb75c;
extern u8* pcGpffffb760;
extern u8* pcGpffffb764;
extern u8* pcGpffffb768;
extern u8* pcGpffffb76c;
extern u8* pcGpffffb770;
extern u8* pcGpffffb774;
extern u8* pcGpffffb778;
extern u8 DAT_00684d70[];
#pragma alias DAT_00684d60 DAT_00684d70
extern u8 DAT_00684d60[];
#pragma alias FUN_00182c50_typed FUN_00182c50
extern void FUN_00182c50_typed(s16 skill, u8* dst);
extern void FUN_001831e0_typed(s16 slot, u32 index, u8* dst);

#pragma alias FUN_0016da50_typed FUN_0016da50
extern void FUN_0016da50_typed(s16 slot, s16 type, s16 index);


/* W389 measured sflResult001f9170 opt_lifetimes on: nd 471 -> 465; object 1212/1216 -> 1212/1216. */

/* Removing this loses FUN_001f9680 (MATCH nd0 -> MISMATCH nd57) - measured W161. */



// FUN_001f9d70
void sflResult001f9d70(u16 index)
{
    switch (index) {
    case 2: datSetFlag(0x1211, 1); break;
    case 3: datSetFlag(0x1212, 1); break;
    case 4: datSetFlag(0x1213, 1); break;
    case 5: datSetFlag(0x1214, 1); break;
    case 7: datSetFlag(0x1216, 1); break;
    case 8: datSetFlag(0x1217, 1); break;
    case 9: datSetFlag(0x1218, 1); break;
    case 10: datSetFlag(0x1219, 1); break;
    default: K_ASSERT(false, 0x49); break;
    }
}

/* W389 measured sflResult001f9e90 opt_propagation off: nd 318 -> 317; object 572/576 -> 572/576. */
#pragma push
#pragma opt_propagation off
// FUN_001f9e90 NONMATCHING
void sflResult001f9e90(u16 owner, s32 exp)
{
    DatPersonaWork* persona;
    u8 growth[40];
    s32 skillOffset;
    s32 skillCount;
    s32 i;
    u8 level;
    u8 ownerType;

    K_ASSERT(exp >= 0, 0x5e);
    FUN_005225a8(0x684bb8, owner);
    K_ASSERT(owner >= 2 && owner <= 10, 0x6f);
    level = datGetLevel(owner);
    persona = datPersonaGetByPcId(owner);
    K_ASSERT(persona != NULL, 0x75);
    datPersonaAddExp(persona, exp);
    if (func_001761b0(persona) == 0) {
        return;
    }
    func_00175ce0(persona, growth);
    skillOffset = (persona->id - 0xc0) * 0x26e;
    ownerType = *((u8*)persona + 4);
    func_001fb4b0(iGpffffb740 + skillOffset + 4, 0x20,
                 ownerType, growth[0], &skillOffset, &skillCount);
    func_00176100(persona, growth);
    for (i = 0; i < skillCount; i++) {
        u8* skill = iGpffffb740 + (persona->id - 0xc0) * 0x26e +
                    4 + skillOffset * 4 + i * 4;
        if (skill[1] == 1) {
            FUN_005225a8(0x684bc8, *(u16*)(skill + 2));
            func_00176840(persona, *(u16*)(skill + 2));
        } else if (skill[1] == 2) {
            FUN_005225a8(0x684be0, *(u16*)(skill + 2));
            func_001768e0(persona, *(u16*)(skill + 2));
        }
    }
    FUN_005225a8(0x684bf8, owner, level);
    (void)level;
}
#pragma opt_propagation reset
#pragma pop
#define FUN_00182c50 FUN_00182c50_typed
#define FUN_001831e0 FUN_001831e0_typed
#define FUN_0016da50 FUN_0016da50_typed
// FUN_001FA0D0


void func_001fa0d0(void)
{
    u32 uVar3;
    u8* pcVar2;
    u8 auStack_20[32];

    for (uVar3 = 0; (int)uVar3 < 0xb; uVar3 = uVar3 + 1) {
        switch (uVar3) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
            switch (uVar3 & 0xffff) {
            case 2:
                pcVar2 = pcGpffffb75c;
                break;
            case 3:
                pcVar2 = pcGpffffb760;
                break;
            case 4:
                pcVar2 = pcGpffffb764;
                break;
            case 5:
                pcVar2 = pcGpffffb768;
                break;
            case 7:
                pcVar2 = pcGpffffb76c;
                break;
            case 8:
                pcVar2 = pcGpffffb770;
                break;
            case 9:
                pcVar2 = pcGpffffb774;
                break;
            case 10:
                pcVar2 = pcGpffffb778;
                break;
            default:
                FUN_0019d3f0(sflResultAssertBA8_abs, 0x35);
                pcVar2 = (u8*)0;
                break;
            }
            if (*pcVar2 != '\0') {
                FUN_0019d3f0(sflResultAssertBA8_abs, 200);
            }
            if (*(u16*)(pcVar2 + 2) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 2), auStack_20);
                FUN_001831e0((s16)uVar3, 0, auStack_20);
                FUN_0016da50((s16)uVar3, 0, 0);
            }
            if (*(u16*)(pcVar2 + 4) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 4), auStack_20);
                FUN_001831e0((s16)uVar3, 1, auStack_20);
                FUN_0016da50((s16)uVar3, 1, 1);
            }
            if (*(u16*)(pcVar2 + 6) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 6), auStack_20);
                FUN_001831e0((s16)uVar3, 2, auStack_20);
                FUN_0016da50((s16)uVar3, 2, 2);
            }
            if (*(u16*)(pcVar2 + 8) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 8), auStack_20);
                FUN_001831e0((s16)uVar3, 3, auStack_20);
                FUN_0016da50((s16)uVar3, 3, 3);
            }
            break;
        case 6:
            FUN_00182c50(0xfe, auStack_20);
            FUN_001831e0((s16)uVar3, 0, auStack_20);
            FUN_0016da50((s16)uVar3, 0, 0);
            FUN_00182c50(0x43f, auStack_20);
            FUN_001831e0((s16)uVar3, 1, auStack_20);
            FUN_0016da50((s16)uVar3, 1, 1);
            FUN_00182c50(0x821, auStack_20);
            FUN_001831e0((s16)uVar3, 2, auStack_20);
            FUN_0016da50((s16)uVar3, 2, 2);
            FUN_00182c50(0xc47, auStack_20);
            FUN_001831e0((s16)uVar3, 3, auStack_20);
            FUN_0016da50((s16)uVar3, 3, 3);
        }
    }
}
#undef FUN_00182c50
#undef FUN_001831e0
#undef FUN_0016da50


// FUN_001fa450
void func_001fa450(void)



{

  int lVar1;

  

  lVar1 = FUN_0017d800();

  if (lVar1 == 0) {

    FUN_005225a8("brfUpdateFriendEquip\n");

    func_001fa4f0(2);

    func_001fa4f0(3);

    func_001fa4f0(4);

    func_001fa4f0(5);

    func_001fa4f0(7);

    func_001fa4f0(8);

    func_001fa4f0(9);

    func_001fa4f0(10);

  }

  return;

}
// FUN_001FA4F0 NONMATCHING


void func_001fa4f0(u32 param_1)



{

  u8 bVar1;

  u8 bVar2;

  short sVar3;

  u16 uVar4;

  u32 uVar5;

  int iVar6;

  s32 lVar7;

  u32 uVar8;

  u32 uVar10;

  s16 uVar9;

  u32 uVar11;

  u8 bVar12;

  u8 bVar13;

  int iVar14;

  u16 unaff_s7_lo;

  u16 unaff_s8_lo;

  u32 uStack_a0;

  u32 uStack_90;

  u32 uStack_80;

  u32 uStack_70;

  u16 uStack_60;

  u16 uStack_50;

  int iStack_30;

  u8 auStack_20 [24];

  int iStack_8;

  int iStack_4;

  

  uVar10 = param_1 & 0xffff;

  switch((int)uVar10) {

  default:

    FUN_0019d3f0(sflResultAssertBA8_abs,0x136);

    break;

  case 2:

  case 3:

  case 4:

  case 5:

  case 7:

  case 8:

  case 9:

  case 10:

    break;

  }

  uVar9 = (u16)param_1;

  uVar5 = FUN_0016c470(uVar9);

  uVar5 = uVar5 & 0xff;

  iVar6 = FUN_00177d10(uVar10);

  if (iVar6 < (int)uVar5) {

    switch((int)uVar10) {

    default:

      FUN_0019d3f0(sflResultAssertBA8_abs,0x35);

      iVar14 = 0;

      break;

    case 2:

      iVar14 = iGpffffb75c;

      break;

    case 3:

      iVar14 = iGpffffb760;

      break;

    case 4:

      iVar14 = iGpffffb764;

      break;

    case 5:

      iVar14 = iGpffffb768;

      break;

    case 7:

      iVar14 = iGpffffb76c;

      break;

    case 8:

      iVar14 = iGpffffb770;

      break;

    case 9:

      iVar14 = iGpffffb774;

      break;

    case 10:

      iVar14 = iGpffffb778;

    }

    func_001fb3f0(iVar14,iVar6,uVar5 - iVar6,&iStack_4,&iStack_8);

    iVar14 = iVar14 + iStack_4 * 10;

    uVar11 = 0;

    sVar3 = FUN_0016cb80(uVar9,0);

    bVar1 = sVar3 != -1;

    if (bVar1) {

      unaff_s7_lo = FUN_0016f630(uVar9);

      iVar6 = FUN_00170d60(unaff_s7_lo);

      uStack_70 = (u32)*(u16 *)(iVar6 + 0x20);

    }

    sVar3 = FUN_0016cb80(uVar9,1);

    bVar12 = bVar1;

    if (sVar3 != -1) {

      unaff_s8_lo = FUN_0016f630(uVar9);

      iVar6 = FUN_00170da0(unaff_s8_lo);

      uStack_80 = (u32)*(u16 *)(iVar6 + 0x16);

      bVar12 = 2;

    }

    sVar3 = FUN_0016cb80(uVar9,2);

    if (sVar3 != -1) {

      uStack_50 = FUN_0016f630(uVar9);

      iVar6 = FUN_00170df0(uStack_50);

      uStack_90 = (u32)*(u16 *)(iVar6 + 0x16);

      bVar12 = bVar12 | 4;

    }

    sVar3 = FUN_0016cb80(uVar9,3);

    if (sVar3 != -1) {

      uStack_60 = FUN_0016f630(uVar9);

      iVar6 = FUN_00170e40(uStack_60);

      uStack_a0 = (u32)*(u16 *)(iVar6 + 0x14);

      bVar12 = bVar12 | 8;

    }

    bVar2 = bVar1;

    bVar13 = bVar12;

    for (iStack_30 = 0; iStack_30 < iStack_8; iStack_30 = iStack_30 + 1) {

      if (*(short *)(iVar14 + 2) != 0) {

        iVar6 = FUN_00170d60(*(short *)(iVar14 + 2));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x20);

        if (bVar2) {

          if ((int)uStack_70 < (int)uVar8) {

            unaff_s7_lo = *(u16 *)(iVar14 + 2);

            uVar11 = uVar11 | 1;

            uStack_70 = uVar8;

          }

        }

        else {

          unaff_s7_lo = *(u16 *)(iVar14 + 2);

          bVar2 = true;

          uVar11 = uVar11 | 1;

          uStack_70 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 4) != 0) {

        iVar6 = FUN_00170da0(*(short *)(iVar14 + 4));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x16);

        if ((bVar13 & 2) == 0) {

          unaff_s8_lo = *(u16 *)(iVar14 + 4);

          bVar13 = bVar13 | 2;

          uVar11 = uVar11 | 2;

          uStack_80 = uVar8;

        }

        else if ((int)uStack_80 < (int)uVar8) {

          unaff_s8_lo = *(u16 *)(iVar14 + 4);

          uVar11 = uVar11 | 2;

          uStack_80 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 6) != 0) {

        iVar6 = FUN_00170df0(*(short *)(iVar14 + 6));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x16);

        if ((bVar13 & 4) == 0) {

          uStack_50 = *(u16 *)(iVar14 + 6);

          bVar13 = bVar13 | 4;

          uVar11 = uVar11 | 4;

          uStack_90 = uVar8;

        }

        else if ((int)uStack_90 < (int)uVar8) {

          uStack_50 = *(u16 *)(iVar14 + 6);

          uVar11 = uVar11 | 4;

          uStack_90 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 8) != 0) {

        iVar6 = FUN_00170e40(*(short *)(iVar14 + 8));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x14);

        if ((bVar13 & 8) == 0) {

          uStack_60 = *(u16 *)(iVar14 + 8);

          bVar13 = bVar13 | 8;

          uVar11 = uVar11 | 8;

          uStack_a0 = uVar8;

        }

        else if ((int)uStack_a0 < (int)uVar8) {

          uStack_60 = *(u16 *)(iVar14 + 8);

          uVar11 = uVar11 | 8;

          uStack_a0 = uVar8;

        }

      }

      iVar14 = iVar14 + 10;

    }

    if ((uVar11 & 1) != 0) {

      FUN_00182c50(unaff_s7_lo,auStack_20);

      if (bVar1) {

        uVar4 = FUN_0016cb80(uVar9,0);

        lVar7 = func_00177ca0(uVar10,0);

        if (lVar7 != 0) {

          func_00177b90(param_1,0,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,0);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x1df);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 2) != 0) {

      FUN_00182c50(unaff_s8_lo,auStack_20);

      if ((bVar12 & 2) != 0) {

        uVar4 = FUN_0016cb80(uVar9,1);

        lVar7 = func_00177ca0(uVar10,1);

        if (lVar7 != 0) {

          func_00177b90(param_1,1,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,1);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x1f7);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 4) != 0) {

      FUN_00182c50(uStack_50,auStack_20);

      if ((bVar12 & 4) != 0) {

        uVar4 = FUN_0016cb80(uVar9,2);

        lVar7 = func_00177ca0(uVar10,2);

        if (lVar7 != 0) {

          func_00177b90(param_1,2,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,2);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x210);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 8) != 0) {

      FUN_00182c50(uStack_60,auStack_20);

      if ((bVar12 & 8) != 0) {

        uVar4 = FUN_0016cb80(uVar9,3);

        lVar7 = func_00177ca0(uVar10,3);

        if (lVar7 != 0) {

          func_00177b90(param_1,3,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,3);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x229);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if (uVar11 != 0) {

      FUN_001f9d70(param_1);

    }

    FUN_00177ce0(uVar10,uVar5);

  }

  return;

}
/* W389 measured func_001faea0 opt_common_subs off: nd 325 -> 303; object 652/656 -> 656/656. */
#pragma push
#pragma opt_common_subs off
// FUN_001FAEA0 NONMATCHING


u32 func_001faea0(void)
{
  u8 uVar1;
  u16 uVar2;
  int lVar3;
  int lVar4;
  int iVar5;
  u32 uVar6;
  u8 auStack_8[8];

  uVar2 = FUN_0035ed20(0);
  lVar3 = FUN_00174800(uVar2);
  lVar4 = FUN_0017d800();
  if ((lVar4 == 0) && (lVar3 != 0)) {
    for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {
      uVar1 = FUN_00173b00(lVar3,uVar6 & 0xffff);
      auStack_8[uVar6] = uVar1;
    }
  }
  iVar5 = (int)lVar3;
  switch(uVar2) {
  case 1:
    lVar4 = FUN_0017d800();
    if ((lVar4 != 0) && (*(u16 *)(iVar5 + 2) == 0xc3)) {
      FUN_00174e20(1);
      FUN_00175130(1);
      FUN_00174b40(*(u16 *)(iVar5 + 2));
    }
    break;
  case 2:
    if (*(u16 *)(iVar5 + 2) == 0xc0) {
      func_001fb130(uVar2,0xc1);
    }
    break;
  case 3:
    if (*(u16 *)(iVar5 + 2) == 0xc2) {
      func_001fb130(uVar2,0xc3);
    }
    break;
  case 4:
    if (*(u16 *)(iVar5 + 2) == 0xc4) {
      func_001fb130(uVar2,0xc5);
    }
    break;
  case 5:
    if (*(u16 *)(iVar5 + 2) == 0xc6) {
      func_001fb130(uVar2,199);
    }
    break;
  case 6:
    if (*(u16 *)(iVar5 + 2) == 200) {
      func_001fb130(uVar2,0xc9);
    }
    break;
  case 7:
    if (*(u16 *)(iVar5 + 2) == 0xca) {
      func_001fb130(uVar2,0xcb);
    }
    break;
  case 8:
    if (*(u16 *)(iVar5 + 2) == 0xcc) {
      func_001fb130(uVar2,0xcd);
    }
  default:
    FUN_0019d3f0(0x684ba8,0x2ca);
    break;
  }
  lVar4 = FUN_0017d800();
  if ((lVar4 == 0) && (lVar3 != 0)) {
    for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {
      FUN_00173b60(uVar2,uVar6 & 0xffff,auStack_8[uVar6]);
    }
  }
  return 1;
}
#pragma opt_common_subs reset
#pragma pop


// FUN_001fb130
void func_001fb130(u64 param_1,u64 param_2)



{

  u16 uVar1;

  u32 uVar2;

  int iVar3;

  

  iVar3 = FUN_00174800();

  uVar1 = *(u8 *)(iVar3 + 4);

  FUN_00175820(param_1,param_2);

  uVar2 = FUN_00174800(param_1);

  uVar2 = func_00176210(uVar2,uVar1);

  FUN_001f9e90(param_1,uVar2);

  return;

}
// FUN_001FB1B0


void func_001fb1b0(u64 param_1,u64 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00174800();

  FUN_001770d0(*(u16 *)(iVar1 + 2),param_2);

  return;

}




// W389 residual nd2: the sole differing instruction is commutative mul.s operand order (retail f0*f1 vs. ours f1*f0); this is a documented compiler floor.
/* W389 measured func_001fbfa0 opt_dead_assignments off: nd 260 -> 219; object 580/592 -> 584/592. */





#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"
#include "Main/Social/sfl_script.h"
#include "h_fade.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"
#pragma alias sflResGetTutorialFileUnchecked FUN_0020ea00
extern void* sflResGetTutorialFileUnchecked();


/*
 * Battle-result tasks deliberately use byte offsets.  The retail work areas
 * are private to the result system and are shared by several child tasks;
 * keeping the offsets here avoids inventing public layouts for those areas.
 */
#define BR_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define BR_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define BR_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define BR_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define BR_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define BR_TASK_WORK(t) ((u8 *)((t)->workData))
#define BR_ROOT_TASK_WORK(t) BR_TASK_WORK(t)
#define BR_SET_STATE(p, s) (BR_U32((p), 0x0c) = (u32)(s))
#define BR_ALLOC2(n, f) (*(void *(**)(u32, u32))jtbl_00960178_abs)((n), (f))
#define BR_FREE(p) (*(void (**)(void *))jtbl_0096017C)((p))

static u8 *sBrRoot;       /* GP-relative -0x4a18 */
static u8 *sBrCard;       /* GP-relative -0x4a14 */
static u8 *sBrReward;     /* GP-relative -0x4a10 */

extern u32 jtbl_00960178[];
#pragma alias jtbl_00960178_abs jtbl_00960178
extern u8 jtbl_00960178_abs[];
extern u32 jtbl_0096017C[];

/* Result-resource and data helpers not yet described by public headers. */
extern s32 printf(const char *, ...);
extern const char D_006845c0[];
extern const char D_006845d0[];
extern const char D_006845f0[];
 
extern void func_002350f0(void);
extern void func_00278550(void);
extern void func_00275cb0(void);
extern void func_003c77a0(void);
extern void brPersonaShutdown(void);
extern void brPersonaDestroy(void);
extern void brHero00262730(void);
extern void brHero002630e0(void);
extern void func_00234960(void);
extern void func_00233e70(void);
extern void func_00272380(void);
extern void func_00275a80(void);
extern void func_00276920(void);
extern void func_00276d30(void);
extern void func_002362e0(void);
extern void func_00262790(void);
extern void func_00275a90(void);
extern void func_0010a370(s32, const char *);
extern void func_00171390(u32);
extern void func_00174e20(u16);
extern u32 dat00171360(u16);
extern s32 func_0016d280(s32);
extern u32 func_0016f380(u32);
extern void func_0016f3e0(u32, u32);
extern u32 func_00173220(u16);
extern u32 func_00174b40(u16);
extern u32 func_001756f0(void);
extern u32 func_00175410(void);
extern u32 func_00175ce0_y2(DatPersonaWork *, u16 *);
extern u32 func_001761b0_y2(DatPersonaWork *);
extern u32 func_00176100_y2(DatPersonaWork *, u16 *);
extern u32 func_001fbdf0_y2(u32, u32, u32, u32, u32);
extern u32 func_001fbfa0_y2(u32, u32, u32, u32, u32, u32);
extern u32 func_001f9e90(u16, u32);
extern void func_001fb4b0_y2(void *, s32, s32, s32, s32 *, s32 *);
extern u8 *DAT_007ce430_y2;
extern u32 func_001f9680(s32 *);
extern void func_001f9c60(void);
extern u32 func_001f9a80(void);
extern void func_001f98d0(void);
extern void sflResult001f9770_y2(u16 *, s32 *);
extern void sflResult001f9800_y2(u16 *, s32 *);
extern u32 sflResult001f9890_y2(void);
extern void sflResult001f9630_y2(void);
extern void *func_001ef500(void *);

extern void func_00219c90(void *);
extern void func_00239170(void *);
extern void func_0023d7a0(void *);
extern void func_0023d7f0(void);
extern void func_0024da00(void *);
extern void sflCamera0024d110(void *);
extern void func_002534d0(void *);
extern void sflScript00259610(void *);
extern void sflCursor0025a110(void *);
extern void func_00260970(void *);
extern void sflCount0025b4a0(void *);
extern void sflPersonaInit(void *);
extern u32 sflGround0023c350(void);
extern void func_00219d90(void);
extern void func_00215fc0(void);
extern u32 func_00254f20(void);
extern u32 func_00254f70(void);
extern void func_003c72d0(void *);
extern void func_0023d130(void);
extern void func_0023ee50(void);
extern void sflCard00259250(void);
extern u32 sflGround0023d1f0(void);
extern u32 sflCard002592c0(void);
extern u32 sflCard002582b0(void);
extern void sflScript00259640(void);
extern u32 func_00259740(void);
extern u32 sflScript002596f0(void);
extern u32 sflCard00258af0(void);
extern u32 sflCount0025b640(void);
extern void sflCount0025b5f0(void);
extern void sflCursor0025aa70(void);
extern void sflCard00258490(void);
extern u8 *func_00256030(void);
extern void sflCard00258090(void);
extern void sflCard002580e0(void);
extern void func_0023f1d0(void);
extern void func_0023cda0(void);
extern void func_003c74e0(void);
extern u32 sflPanel0023f390(void);
extern u32 sflGround0023d0e0(void);
extern void func_00255fe0(void);
extern void func_002550b0(void);
extern void func_00258300(void);
extern u32 func_003c7610(void);
extern void func_003c7990(s32);
extern u32 func_003c7850(void);
extern u32 func_003c7650(s32);
extern u32 func_003c78d0(void);
extern void func_002594c0(void);
extern u32 sflCard002595c0(void);
extern void func_003c94e0(void *);
extern void func_003c9790(s32);
extern void func_0025b690(void);
extern void func_0025a130(void);
extern void func_0023d8f0(void);
extern void func_0024db90(void);
extern void func_0024dc10(void);
extern void sflCamera0024d1c0(void);
extern void func_00253a40(void);
extern void func_002392d0(void);
extern void sflPersonaUpdate(void);

extern void func_0023b990(void);
extern void func_00254b90(void);
extern void func_0025bbf0(void);
extern void func_0025a440(void);
extern void func_001f64c0(void);
extern void func_002168f0(void);
extern void func_0023e970(void);
extern void sflPersonaShutdown(void *);
extern void sflCount0025b4b0(void);
extern void func_00215aa0(void);
extern void sflPsel00260a10(void);
extern void func_0025a120(void);
extern void func_00259630(void);
extern void sflCard00253560(void);
extern void sflCamera0024d160(void);
extern void func_0024da20(void);
extern void sflPanel0023d870(void);
extern void func_0023d7b0(void);
extern void sflGround00239280(void);
extern void func_0021a1b0(void);

extern void func_004c9d70(void *, float);
extern void func_0021a840(void);
extern void func_0024fd10(void *);
extern void func_0024f9f0(void *, const float *);
extern void func_0024da60(void *);
extern void func_0024f090(void *);
extern void func_0024d8d0(void *);
extern void sflCamera0024d2e0(s32, void *);
extern void sflCamera0024d940(void *, void *);
extern void sflCamera0024d9a0(void *, void *);
extern void sflCamera0024d280(void *);
extern void func_0024d4c0(s32);
extern void func_0023c280(void);
extern u8 *func_00209e10(void);
extern u8 *func_00209e20(void);
extern u8 *func_00209e60(void);
extern u8 *func_00209e70(void);
extern u8 *func_00209dc0(void);
extern u8 *func_00209dd0(void);
extern u8 *func_00209d00_y2(void);
extern u8 *func_00209c40(void);
extern u8 *func_00209c80(void);
extern u8 *func_00209cc0(void);
extern u8 *func_00209d40(u8 *);
extern char *func_00209e80(void);
extern char *func_00209e90(void);
extern u32 func_00255130(void);
extern void func_00254e10(void);
extern void *sflCard002537f0(u16);
extern u32 sflCard002536b0(u32, u32);
extern void sflCard00255170(void *);
extern void sflCard00255190(void *);
extern void func_002551b0(void *);
extern void sflCard00253920(void);
extern void sflScript00259690(void *, u32);
extern void sflScript00259b00(u16);
extern void sflScript00259b60(u16);
extern void sflScript00259c10(void);
extern void sflScript00259bc0(void);
extern void sflScript00259c60(u16);
extern void sflScript00259cc0(void);
extern void sflScriptQueueEndCommand(void);
extern void sflScriptQueueWaitCommand(u16 frames);
extern void sflScriptQueueOpenCommand(u16 card);
extern void sflScriptQueueWaitForActionsCommand(void);
extern void sflScriptQueueStartActionsCommand(void);
extern void sflScriptQueueSetCardValueCommand(u16 value);
extern void sflScriptQueueShuffleCommand(void);
extern void func_002595c0(void);
extern void func_002508c0(void *, const float *, s32);
extern void func_0020b250(void *);
extern void func_00209f00(void *);
extern void func_0020c590(void *, u16);
extern void func_0020a800(void *);
extern void func_0020c5f0(void *, u32, u32);
extern void func_0024fd80(void *);
extern f32 func_0020c500(void *, f32);
extern void func_0020c400(void *, const float *, float, float *);
extern void func_0020cc80(void *, const u8 *);
extern void gcPose0024f960(void *, const float *);
extern void sflResSetSpriteScale(void *, const f32 *);
extern void sflResSetSpriteRotation(void *, const f32 *);
extern void func_004bdde0_y2(f32, f32 *, const f32 *, u32);
extern void func_0020ac90(void *);
extern void *sflResGetBaseSpriteData(void);
extern u32 func_0035c250(u32);
extern u32 sflResult001f99f0(void);
extern u32 func_001831e0(s16, s16, const void *);
extern u32 scrForceTraceCode(void *);
extern void K_Fldrc_DestroyArchives(void);
extern void func_00217590(u16);
extern void func_00215b00(void);
extern void scrReleaseScript(void *);
extern void *scrStartScriptFirstPrcd(void *header);
extern void func_0021ab80(u16 id);
extern void func_0021a920(u32 majorId, u32 minorId);
extern char D_00684850[];
extern char D_00684620[];
extern char D_006846CE[];
extern char D_006846DE[];
extern char D_00684718[];
extern char D_00684730[];
extern char D_00684750[];
extern char D_00684770[];
extern char D_00684788[];
extern char D_006847A0[];
extern char D_006847D0[];
extern char D_006847E0[];
extern char D_006847F0[];
extern char D_00684800[];
extern char D_00684810[];
extern char D_00684820[];
extern char D_00684830[];
extern char D_00684840[];
extern char D_00696950[];
extern char D_00696948[];
extern char D_00696964[];
extern char D_00696960[];
extern char D_00696958[];
extern u32 func_00255130(void);
extern void func_00257f10(void);
extern void func_002599c0(u32, u32);
extern void func_00259a60(u32, s32);
extern void sflScript00259970(void);
extern f32 func_00530da0(f32);
extern u32 datGetScenarioMode(void);
extern void sflResRequestBaseArchive(void);
extern u32 func_001f9170(s32);
extern void func_00173660(DatPersonaWork *, s32);
extern u32 func_0021a120(void);
extern void func_00258300(void);
extern void func_002550b0(void);
extern void *func_0034fcd0(void *);
extern u16 datGetMaxHp_y2(s16);
extern void *sflResGetBaseDataFile(s32);
extern u16 func_00170760(s16, s16);
extern void func_00170860(s16, s16, u16);
extern void datSetMoney(u32);
extern void func_001828d0(s16, void *, void *);
#pragma alias func_001828d0_2arg func_001828d0
extern void func_001828d0_2arg(s16, void *);
extern void func_00182d90(s16, s16, u32, void *);
extern void func_00521250(void *, const void *, u32);
extern u32 func_003c7bc0(s32, u32);
extern u32 func_003c7c20(s32, u32, u32);
extern void func_003c7430(s32);
extern void func_0010a4e0(s32, s32, s32, s32);
extern const char *h_camp_getAcademicLevelString(s16);
extern const char *h_camp_getCharmLevelString(s16);
extern const char *h_camp_getCourageLevelString(s16);
extern void func_0021eac0(void *, float);
extern void func_0023f010(void);
extern void func_0023ca10(void);
extern void *kwlnGetMainCamera(void);
extern void func_00255f80(void);
extern void func_0025a7d0(void);
extern void func_0025b4f0(void);
extern void sflPanel0023f3e0(void);
extern void sflCard00259310(void);
extern u32 sflCard002561c0(void *);
extern u32 sflCard002561d0(void *);
extern u32 sflCard00259380(void);
extern void sflResult001f9100(void);
extern void sflResSetSpritePosition(void *, const float *);
extern void func_0034fcf0(void *);
extern u32 D_00684610[];
extern u32 func_001775a0(u32, ...);
extern u32 func_0016c6f0(u32);
extern u32 func_00177280(u32);
extern u32 func_0011a810(u32);
extern u32 func_0016c740(u32);
extern u32 func_001772f0(u32);
extern u32 func_0011a840(u32);
extern u32 func_0016c790(u32);
extern u32 func_00177360(u32);
extern u32 func_0011a870(u32);
extern u32 func_0016c4f0(u32);
extern u32 func_0016c5f0(u32);
extern u32 func_0016c570(u32);
extern u32 func_0016c970(u32);
extern u32 func_0016c920(u32);
extern void func_0016cf40(u32, u32);
extern void func_0016cf90(u32, u32);
extern void func_0016d8b0(u32, u32);
extern void func_0016d6b0(u32, u32);
extern u32 func_00488f30(void);
extern void sflResRequestTutorialArchive(void);
extern u32 func_0016f190(u32);
extern void func_0023f430(void);
extern u32 func_002561c0(void *);
extern u32 func_002561d0(void *);
extern void func_005225a8(const char *, s32, s32);
extern void func_00174800(u32);
extern void func_00174650(u32, u32, u32);
extern void func_0016cfe0(u32, u32);
extern void func_0016d090(u32, u32);
extern void func_0016d160(u32, u32);


void func_001f0990(KwlnTask *);
void func_001f0f40(KwlnTask *);
void func_001f0ff0(void);
u8 *brRoot001f1c50(void);
void func_001f1140(KwlnTask *);
void func_001f13b0(KwlnTask *);
void brRoot001f1e90(KwlnTask *);
void func_001f30d0(KwlnTask *);
void func_001f30f0(KwlnTask *);
void func_001f3270(KwlnTask *);
void func_001f4650(KwlnTask *, const u8 *);
void func_001f4750(KwlnTask *);
u32 func_001f4990(void);
void func_001f4a00(void);
void func_001f53a0(void);
void func_001f54a0(void);
void func_001f5510(void);
void func_001f55e0(void);
void func_001f5650(void);
void func_001f56b0(void);
u32 func_001f5760(u16);
u32 func_001f5810(KwlnTask *);
void func_001f58f0(u8 *);
void func_001f5950(void);
void func_001f59b0(void);
void *func_001f5b20(void);
void func_001f64c0(void);
u32 func_001f65e0(void);
void brRewardAdvanceState(void);
void brRewardAnimateCurrentEntry(void);
void brRewardRegisterEntry(const f32 *);
void func_001f7030(void);
void func_001f70d0(void);
void func_001f7170(void);
#pragma alias func_001f2300_update func_001f2300
extern void *func_001f2300_update(KwlnTask *);
#pragma alias func_001f2fd0_destroy func_001f2fd0
extern void func_001f2fd0_destroy(KwlnTask *);
void *func_001f2f50(KwlnTask *);
void *func_001f2f80(KwlnTask *);
void func_001f2fd0(KwlnTask *);
void func_001f2ff0(KwlnTask *);
u32 func_001f30b0(KwlnTask *);
void *func_001f2300(KwlnTask *);

static void brCopyWords(u8 *dst, const u8 *src, u32 count)
{
    u32 i;
    for (i = 0; i < count; i++) {
        dst[i] = src[i];
    }
}

static u32 brRootFlags(void)
{
    return sBrRoot != NULL ? BR_U32(sBrRoot, 0) : 0;
}

static u32 brCardFlags(void)
{
    return sBrCard != NULL ? BR_U32(sBrCard, 4) : 0;
}

static u32 brRewardFlags(void)
{
    return sBrReward != NULL ? BR_U32(sBrReward, 0) : 0;
}








typedef struct BrRootSetupParams {
    u32 flags;
    struct {
        u16 id;
        u16 pad;
        u32 value;
    } entries[3];
    u32 entryCount;
    u32 field20;
    u16 partyIds[4];
    u32 partyCount;
    u32 field30;
    u32 field34;
    u32 field38;
    u32 field3c;
    u32 field40;
} BrRootSetupParams;













/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */










#pragma opt_propagation reset












/* Retail 0x1f3270-0x1f4648: reconstructed result-card selection and reward dispatch. */






















/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */

#pragma alias brRewardAdvanceState func_001f6a60

#pragma alias brRewardRegisterEntry func_001f6d20

#pragma alias brRewardAnimateCurrentEntry func_001f6e80
