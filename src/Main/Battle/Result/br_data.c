#include "Main/Battle/Result/br_data.h"




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
int func_001fbfa0(int param_1,int param_2,int param_3,u16 param_4,int param_5,long param_6);
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
#pragma alias psGpffffb754_sda psGpffffb754
extern u16* psGpffffb754_sda __attribute__((section(".sdata")));
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




/* W389 measured sflResult001f9e90 opt_propagation off: nd 318 -> 317; object 572/576 -> 572/576. */
#define FUN_00182c50 FUN_00182c50_typed
#define FUN_001831e0 FUN_001831e0_typed
#define FUN_0016da50 FUN_0016da50_typed
#undef FUN_00182c50
#undef FUN_001831e0
#undef FUN_0016da50


/* W389 measured func_001faea0 opt_common_subs off: nd 325 -> 303; object 652/656 -> 656/656. */


// FUN_001FB1F0


void func_001fb1f0(DatPersonaWork* persona, u16* output, s32* outputCount)
{
    u16* skills;
    s32 skillCount;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    s32 i;
    s32 outputSize;
    s32 j;

    skills = datPersonaGetSkills(persona);
    skillCount = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    outputSize = 0;
    for (i = 0; i < indexCount; i++, current += 4)
    {
        switch (current[1])
        {
        case 1:
            j = 0;
            while (j < skillCount)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == skillCount)
            {
                K_ASSERT(outputSize < 8, 0x5b);
                output[outputSize] = *(u16*)(current + 2);
                outputSize++;
            }
            break;
        }
        if (outputSize == 8)
            break;
    }
    *outputCount = outputSize;
}
// FUN_001FB3F0
#pragma optimization_level 2
/* Removing this loses FUN_001fb3f0 (MATCH nd0 -> MISMATCH nd137) - measured W161. */
#pragma opt_loop_invariants on
void func_001fb3f0(int param_1,int param_2,int param_3,int *param_4,int *param_5)
{
    int param_3_p = param_3;
    s32 first;
    s32 last;
    s32 foundStart;
    s32 upperBound;
    s32 i;
    u8 *entry;

  upperBound = param_2 + param_3_p;
  i = 0;
  foundStart = 0;
  /* Removing this barrier loses func_001fb3f0 (MATCH nd0 -> MISMATCH nd2) - measured W164. */
  asm ("" : "+r"(i));
  while (1) {
    entry = (u8 *)(param_1 + i * 10);
    if ((*(u16 *)(entry + 2) == 0) &&
        (*(u16 *)(entry + 4) == 0) &&
        (*(u16 *)(entry + 6) == 0) &&
        (*(u16 *)(entry + 8) == 0)) {
      break;
    }
    if ((param_2 < (int)(u32)*entry) &&
        ((int)(u32)*entry <= upperBound)) {
      if (!foundStart) {
        first = i;
        foundStart = 1;
      }
      last = i;
    }
    i = i + 1;
  }
  if (foundStart) {
    *param_4 = first;
    *param_5 = (last + 1) - first;
  } else {
    *param_4 = 0;
    *param_5 = 0;
  }
}
#pragma opt_loop_invariants off
#pragma optimization_level 2
/* Removing this loses FUN_001fb4b0 (MATCH nd0 -> MISMATCH nd118) - measured W161. */
// FUN_001FB4B0
#pragma opt_loop_invariants on


void func_001fb4b0(void* entries, s32 capacity, s32 lowerBound, s32 range,
                   s32* firstIndex, s32* indexCount)
{
  s32 upperBound;
  int i;
  int first;
  int last;
  s32 foundStart;
  s32 foundRange;
  u32 value;
  u8* entry;

  upperBound = lowerBound + range;
  first = 0;
  foundStart = 0;
  foundRange = 0;
  i = 0;
  while (i < capacity) {
    entry = (u8*)entries + i * 4;
    if (((s8*)entry)[1] == 0) {
      break;
    }
    value = (u32)*entry;
    if (lowerBound < (int)value) {
      if (!foundStart) {
        foundStart = 1;
        first = i;
        last = i;
      }
      if ((int)value <= upperBound) {
        foundRange = 1;
        last = i;
      }
    }
    i = i + 1;
  }
  if (foundRange) {
    *firstIndex = first;
    *indexCount = (last + 1) - first;
  } else {
    *firstIndex = first;
    *indexCount = 0;
  }
}
#pragma opt_loop_invariants off
#pragma optimization_level 3
/* W418 fb560 probes (baseline nd 758/object 1140, window 1296):
 * schedule off: nd 762/object 1324 (over-window), rejected.
 * structured loop: nd 743/object 1128 (ORDER), rejected.
 * structured loop + nested status calls: nd 736/object 1120 (ORDER), rejected.
 * structured loop + inverted fallback: nd 749/object 1128 (ORDER closed), retained.
 * inverted fallback + nested status: nd 751/object 1120, rejected.
 * fallback switch: nd 754/object 1132, rejected.
 * branch-first inverted: nd 704/object 1012 (rate 69.57% vs 66.49%), rejected by size loophole.
 * input alias and declaration swaps (0/1, 0/2, 0/3, 2/4, 3/4): nd 749/object 1128, no gain.
 */
// FUN_001FB560 NONMATCHING


u16 func_001fb560(u32 param_1)



{

  u8 bVar1;

  u16 uVar2;

  u32 uVar3;

  int iVar4;

  u16 uVar5;

  u32 iVar6;

  u32 uVar7;


  u32 uVar8;

  u32 iVar9;

  u32 uVar10;

  int iVar11;

  u16 *puVar12;

  u8 bVar13;

  u32 unaff_s8_lo;

  u16 auStack_200 [256];

  u16 auStack_220 [16];

  

  FUN_005225a8(sflResultMsgC40_abs,param_1 & 0xffff);

  uVar8 = FUN_0016c7e0(1);

  uVar3 = FUN_0016d280(uVar8);

  uVar3 = uVar3 & 0xff;

  iVar4 = FUN_001749a0(param_1);

  bVar1 = *(u8 *)(iVar4 + 4);

  uVar5 = FUN_001756f0();

  uVar5 = uVar5 & 0xffff;

  for (iVar4 = 0; iVar4 < (int)uVar5; iVar4 = iVar4 + 1) {

    iVar9 = FUN_00174a90((short)iVar4);

    auStack_220[iVar4] = *(u16 *)(iVar9 + 2);

  }

  FUN_005225a8(sflResultMsgC60_abs);

  iVar4 = -1;

  iVar11 = 0;

  iVar9 = 0;

  for (puVar12 = puGpffffb74c;

      (((u32)*puVar12 != 0 || (puVar12[1] != 0)) || ((char)puVar12[2] != '\0'));

      puVar12 = puVar12 + 3) {

    if ((u32)*puVar12 == (param_1 & 0xffff)) {

      if (iVar4 == -1) {

        iVar4 = iVar9;

      }

      iVar11 = iVar11 + 1;

    }

    iVar9 = iVar9 + 1;

  }

  FUN_005225a8(sflResultMsgC70_abs,iVar11);

  bVar13 = false;

  iVar9 = 0;

  while (iVar9 < iVar11) {

    puVar12 = puGpffffb74c + (iVar4 + iVar9) * 3;

    for (iVar6 = 0; (iVar6 < (int)uVar5 && (puVar12[1] != auStack_220[iVar6])); iVar6 = iVar6 + 1) {
    }

    if ((int)uVar5 <= iVar6) {

      FUN_005225a8(&gp0xffff9700,puVar12[1]);

      iVar6 = FUN_00488f30();

      FUN_005225a8(sflResultMsgC80_abs,iVar6 % 100,(char)puVar12[2]);

      if ((u32)(iVar6 % 100) < (u32)(u8)puVar12[2]) {

        FUN_005225a8(&gp0xffff9708);

        unaff_s8_lo = (u32)puVar12[1];

        bVar13 = true;

        break;
      }

      FUN_005225a8(sflResultMsgC90_abs);
    }

    iVar9 = iVar9 + 1;
  }

  if ((bVar13) &&
      (FUN_005225a8(sflResultMsgCA0_abs,*(u8 *)((int)puGpffffb730 + unaff_s8_lo * 0xe + 3),uVar3),
       *(u8 *)((int)puGpffffb730 + unaff_s8_lo * 0xe + 3) <= uVar3)) {

    FUN_005225a8(&gp0xffff9708);

    uVar2 = puVar12[1];
  }
  else {

    FUN_005225a8(sflResultMsgC90_abs);

    FUN_005225a8(sflResultMsgCD0_abs);

    iVar4 = 0;

    puVar12 = puGpffffb730;

    for (uVar7 = 0; (int)uVar7 < 0x100; uVar7 = uVar7 + 1) {

      uVar2 = *puVar12;

      if ((((((uVar2 & 8) == 0) && ((uVar2 & 0x10) == 0)) && ((uVar2 & 4) == 0)) &&
          (((uVar2 & 2) == 0 && (uVar10 = (u32)*(u8 *)((int)puVar12 + 3), bVar1 <= uVar10))))
         && ((uVar10 <= bVar1 + 10 && (uVar10 <= uVar3)))) {

        for (iVar9 = 0; (iVar9 < (int)uVar5 && (uVar7 != auStack_220[iVar9])); iVar9 = iVar9 + 1) {
        }

        if ((int)uVar5 <= iVar9) {

          auStack_200[iVar4] = (u16)uVar7;

          iVar4 = iVar4 + 1;
        }
      }

      puVar12 = puVar12 + 7;
    }

    FUN_005225a8(sflResultMsgCE0_abs,iVar4);

    if (iVar4 != 0) {
      FUN_005225a8(&gp0xffff9708);

      FUN_005225a8(sflResultMsgCF8_abs);

      for (iVar9 = 0; iVar9 < iVar4; iVar9 = iVar9 + 1) {

        FUN_005225a8(&gp0xffff9710,iVar9,auStack_200[iVar9]);
      }

      iVar9 = FUN_00488f30();

      FUN_005225a8(sflResultMsgD08_abs,iVar9 % iVar4);

      uVar2 = auStack_200[iVar9 % iVar4];
    }
    else {

      FUN_005225a8(sflResultMsgC90_abs);

      puVar12 = puGpffffb750;

      for (iVar4 = 0; iVar4 < 0xd; iVar4 = iVar4 + 1) {

        for (iVar9 = 0; (iVar9 < (int)uVar5 && (*puVar12 != auStack_220[iVar9]));
            iVar9 = iVar9 + 1) {
        }

        if ((int)uVar5 <= iVar9) {

          return *puVar12;
        }

        puVar12 = puVar12 + 1;
      }

      FUN_0019d3f0(sflResultMsgC28_abs,0x169);

      uVar2 = 0;
    }
  }

  return uVar2;

}
#pragma optimization_level 2
/* W389 measured func_001fba70 opt_loop_invariants on: nd 283 -> 280; object 556/560 -> 556/560. */
#pragma push
#pragma opt_loop_invariants on
// FUN_001FBA70 NONMATCHING


u32 func_001fba70(u16 param_1)



{

  int iVar3;

  int iVar6;

  int iVar9;

  int iVar1;

  u32 iVar2;

  u32 lVar4;

  int iVar5;

  u16 *psVar7;

  u8 bVar8;

  u32 unaff_s7;

  int iVar10;

  

  iVar1 = FUN_001749a0();

  iVar9 = 0;

  iVar6 = 0;

  iVar3 = -1;

  psVar7 = psGpffffb754_sda;
  iVar10 = 0;
  while (1) {
    if ((*psVar7 == 0) && (psVar7[1] == 0) && ((u8)psVar7[2] == '\0')) {
      break;
    }
    if (*psVar7 == param_1) {
      if (iVar3 == -1) {
        iVar3 = iVar10;
      }
      iVar9 = iVar9 + 1;
    }
    iVar10 = iVar10 + 1;
    psVar7 = psVar7 + 3;
  }

  FUN_005225a8(sflResultMsgD20_abs,iVar9);

  bVar8 = false;

  iVar6 = 0;

  while (iVar6 < iVar9) {
    iVar5 = iVar3 + iVar6;
    psVar7 = psGpffffb754_sda + iVar5 * 3;
    FUN_005225a8(&gp0xffff9700,psVar7[1]);
    iVar2 = FUN_00488f30();
    FUN_005225a8(sflResultMsgC80_abs,iVar2 % 100,(u8)psVar7[2]);
    if ((u32)(iVar2 % 100) < (u32)*(u8 *)(psVar7 + 2)) {
      FUN_005225a8(&gp0xffff9708);
      unaff_s7 = (u32)(u16)psVar7[1];
      bVar8 = true;
      break;
    }
    FUN_005225a8(sflResultMsgC90_abs);
    iVar6 = iVar6 + 1;
  }
  if (!bVar8) {
    FUN_005225a8(sflResultMsgC90_abs);
    lVar4 = func_001fbca0(*(u8 *)(iVar1 + 4));
    FUN_005225a8(sflResultMsgD30_abs,lVar4);
    if (lVar4 == 0) {
      FUN_0019d3f0(sflResultMsgC28_abs,0x1b3);
    }
    iVar3 = FUN_00488f30();
    iVar3 = iVar3 % lVar4;
    FUN_005225a8(sflResultMsgD40_abs,iVar3);
    iVar3 = (int)func_001fbd50(*(u8 *)(iVar1 + 4),iVar3);
    unaff_s7 = (u32)*(u16 *)(iVar3 + 2);
  }
  return unaff_s7;

}
#pragma opt_loop_invariants reset
#pragma pop


// FUN_001fbca0
int func_001fbca0(u16 param_1)
{
  u8* entry;
  int count;
  int target;
  u8 lower;

  count = 0;
  entry = pbGpffffb758;
  target = param_1;

check_entry:
  lower = *entry;
  if (lower != 0) goto inspect_entry;
  if (entry[1] != 0) goto inspect_entry;
  if (*(u16*)(entry + 2) == 0) goto done;

inspect_entry:
  if (target < lower) goto next_entry;
  if (target >= entry[1]) goto next_entry;
  FUN_005225a8("%d <= %d < %d\n", lower, target, entry[1]);
  count++;

next_entry:
  entry += 4;
  goto check_entry;

done:
  return count;
}


// FUN_001fbd50
u8* func_001fbd50(u16 param_1, int param_2)
{
  u8* entry;
  int matchIndex;
  int target;

  entry = pbGpffffb758;
  matchIndex = 0;
  target = param_1;

check_entry:
  if (*entry != 0) goto inspect_entry;
  if (entry[1] != 0) goto inspect_entry;
  if (*(u16*)(entry + 2) == 0) goto no_match;

inspect_entry:
  if (target >= *entry) {
    if (target < entry[1]) {
      if (matchIndex == param_2) return entry;
      matchIndex++;
    }
  }
  entry += 4;
  goto check_entry;

no_match:
  K_ASSERT(false, 0x1f3);
  return NULL;
}
static inline f32 brDataMul(f32 left, f32 right)
{
    return left * right;
}

// W389 residual nd2: the sole differing instruction is commutative mul.s operand order (retail f0*f1 vs. ours f1*f0); this is a documented compiler floor.
// W419 measured: brDataMul((f32)amount, value) with a volatile load flips mul.s to retail order; nd2/432 -> nd0/432.
// FUN_001FBDF0


int func_001fbdf0(s32 start, s32 end, s32 amount, s32 category, s32 scaleMode)
{
    u32* flags;
    f32 value;
    f32 factor;
    s32 i;
    s32 result;

    flags = (u32*)(iGpffffb7b8 + category * 0x1c);
    switch (scaleMode)
    {
    case 1:
        factor = fGpffff83b0;
        break;
    case 2:
        factor = fGpffff83b4;
        break;
    case 3:
        factor = 1.0f;
        break;
    case 4:
        factor = fGpffff8070;
        break;
    default:
        K_ASSERT(false, 0x21e);
        break;
    }

    if ((*flags & 0x80) != 0)
    {
        result = (s32)((f32)amount * factor);
    }
    else
    {
        i = end - start;
        if (!(i < 10))
            i = 0x14;
        else if (i < -9)
            i = 0;
        else
            i += 10;
        K_ASSERT(i >= 0 && i < 0x15, 0x20b);
        value = *(volatile f32*)(iGpffffb7ac + i * 4);
        value = brDataMul((f32)amount, value);
        result = (s32)(factor * value);
    }
    if (result > 0xffff)
        result = 0xffff;
    return result;
}
/* W389 measured func_001fbfa0 opt_dead_assignments off: nd 260 -> 219; object 580/592 -> 584/592. */
#pragma push
#pragma opt_dead_assignments off
// FUN_001FBFA0 NONMATCHING


int func_001fbfa0(int param_1,int param_2,int param_3,u16 param_4,int param_5,long param_6)



{

  u32 *puVar1;

  int iVar2;
  int level;

  float fVar5;

  float fVar3;

  float fVar4;


  

  puVar1 = (u32 *)(iGpffffb7b8 + param_5 * 0x1c);

  level = param_2 - param_1;

  if (level >= 10) {

    level = 0x14;

  }

  else {

    if (level < -9) {

      level = 0;

    }

    else {

      level = level + 10;

    }

  }

  if ((level < 0) || (level >= 0x15)) {

    K_ASSERT(false, 0x20b);

  }

  fVar4 = *(float *)(iGpffffb7ac + level * 4);
  fVar5 = 0.0f;

  switch (param_4) {
  case 0x22b:
    fVar5 = 1.0f;
    break;
  case 0x22a:
    fVar5 = 0.5f;
    break;
  case 0x229:
    fVar5 = 0.25f;
    break;
  default:
    K_ASSERT(false, 0x243);
    break;
  }

  switch (param_6) {
  case 1:
    fVar3 = fGpffff83b0;
    break;
  case 2:
    fVar3 = fGpffff83b4;
    break;
  case 3:
    fVar3 = 1.0f;
    break;
  case 4:
    fVar3 = fGpffff8070;
    break;
  default:
    K_ASSERT(false, 0x24e);
    break;
  }

  if ((*puVar1 & 0x80) != 0) {

    fVar4 = (f32)param_3;
    fVar4 = brDataMul(fVar4, fVar5);
    fVar4 = brDataMul(fVar3, fVar4);
    iVar2 = (int)fVar4;

  }
  else {
    fVar4 = brDataMul((f32)param_3, fVar4);
    fVar4 = brDataMul(fVar5, fVar4);
    fVar4 = brDataMul(fVar3, fVar4);
    iVar2 = (int)fVar4;
  }

  if (iVar2 >= 0x10000)
    iVar2 = 0xffff;
  return iVar2;

}
#pragma opt_dead_assignments reset
#pragma pop
// FUN_001FC1F0


void func_001fc1f0(void)
{
    DatPersonaWork* persona;

    persona = datPersonaGetByPcId(1);
    datPersonaAddExp(persona, 0x18);
}
#pragma optimization_level 2
/* Removing this loses FUN_001fc230 (MATCH nd0 -> MISMATCH nd78) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001FC230


u8 func_001fc230(DatPersonaWork* persona)
{
    u16* skills;
    s32 count;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    s32 i;
    s32 j;

    skills = datPersonaGetSkills(persona);
    count = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    for (i = 0; i < indexCount; i++, current += 4)
    {
        if (current[1] == 1)
        {
            j = 0;
            while (j < count)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == count)
                break;
        }
    }
    return i < indexCount;
}
// FUN_001FC3C0
u32 func_001fc3c0(DatPersonaWork* persona)
{
    u16* skills;
    s32 count;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    s32 i;
    s32 j;
    u32 result;

    skills = datPersonaGetSkills(persona);
    count = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    for (i = 0; i < indexCount; i++, current += 4)
    {
        if (current[1] == 1)
        {
            j = 0;
            while (j < count)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == count)
                break;
        }
    }

    if (FUN_00175ca0(persona) != 0)
        result = *(u8*)current;
    else
        result = *(u8*)current + DAT_007ce420[persona->id * 0xe + 3];
    return result;
}
#pragma opt_loop_invariants reset

// FUN_001FC590
u32 func_001fc590(u8* event, void* target)
{
    u32 result = 0;
    s32 damage;
    u32 criticalDamage;
    s32 boosted;
    u16 skill;

    skill = FUN_00308930();
    damage = FUN_00303130(skill, event, target, 1, 1, 1, 0, 1);
    if ((*(u16*)event & 4) == 0) goto branch_zero;
    damage = (s32)((f32)damage * 0.5f);
    criticalDamage = FUN_00488f30();
    if ((u32)(criticalDamage % 500) < 100)
        damage = 0;
    goto after_branch;
branch_zero:
    damage = (s32)((f32)damage * 1.5f);
    criticalDamage = FUN_00488f30();
    if ((u32)(criticalDamage % 500) < 100)
        damage *= 3;
after_branch:

    FUN_00300410(target, damage);
    if (datCalcIsDead(target, 0) != 0)
    {
        if ((*(u16*)event & 4) == 0)
            result = func_001fc870(event, target);
        datCalcClearBadStatus(target, 0x80);
        datCalcSetBadStatus(target, 0x80000);
    }
    return result;
}




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
