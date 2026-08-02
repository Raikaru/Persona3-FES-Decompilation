#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "Main/Social/sfl_psel.h"

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
extern u32 func_0020c500(float, void*);
extern void func_0020c400(u32, void*, const float*, float*);
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
#pragma alias FUN_005225a8_pb FUN_005225a8
extern void FUN_005225a8_pb(const char* format, ...);
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
#pragma alias pbResultMsgDD0_abs DAT_00684d70
extern const char pbResultMsgDD0_abs[];
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



/* Removing this loses FUN_001f9680 (MATCH nd0 -> MISMATCH nd57) - measured W161. */





#define FUN_00182c50 FUN_00182c50_typed
#define FUN_001831e0 FUN_001831e0_typed
#define FUN_0016da50 FUN_0016da50_typed
#undef FUN_00182c50
#undef FUN_001831e0
#undef FUN_0016da50




/* Removing this loses FUN_001fb4b0 (MATCH nd0 -> MISMATCH nd118) - measured W161. */




/* Removing this loses FUN_001fc230 (MATCH nd0 -> MISMATCH nd78) - measured W161. */

// Retail uses separate 12-entry effect/skill result arrays and passes their counts to the selected dispatcher.
// FUN_001FC720


u32 func_001fc720(u8* event)
{
    s32 in_v1;
    s32 in_s0;
    u32 result;
    u16 effectResults[12];
    u32 skillResults[12];
    s32 effectCount;
    s32 skillCount;

    if (in_v1 / 3 < in_v1)
        return 0;

    if ((~*(u16*)event & 4) == 0)
        FUN_0019d3f0((u32)DAT_00684d60, 0xaa);

    func_001fc980(event, effectResults, &effectCount);
    func_001fcb30(event, skillResults, &skillCount);
    if (in_s0 <= in_s0 * 30 / 100 && skillCount != 0)
    {
        func_001fd350(event, skillResults, skillCount);
        result = 1;
    }
    else if (effectCount != 0)
    {
        func_001fce20(event, effectResults, effectCount);
        result = 1;
    }
    else if (in_s0 >= in_s0 * 30 / 100 && skillCount != 0)
    {
        func_001fd350(event, skillResults, skillCount);
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
// FUN_001FC870

int func_001fc870(u8* event, void* target)
{
    s32 raw;
    s32 delta;
    s32 level;
    s32 half;
    f32 amount;

    raw = FUN_0030bc50(target);
    amount = (f32)(u32)raw;

    level = FUN_00173300(*(u16*)(event + 2)) & 0xff;
    delta = *(u8*)((u8*)target + 6) - level;
    if (delta < -10)
        delta = -10;
    if (delta > 10)
        delta = 10;

    amount *= *(f32*)(DAT_00684d70 + (delta + 10) * 4);
    if (amount < 1.0f)
        amount = 1.0f;
    FUN_001f9e90(*(u16*)(event + 2), (s32)amount);
    return (s32)amount;
}
// FUN_001FC980 NONMATCHING


void func_001fc980(u8* event, u16* result, s32* count)
{
    extern void FUN_0017be10(s16 param_1, s16 param_2, s16 param_3,
                             int param_4, void* param_5, void* param_6,
                             void* param_7);
    extern u16 FUN_0017bb40(s32 id);
    DatPersonaWork* persona;
    u16* skills;
    s32 skillCount;
    s32 skill;
    u32 resultCount;
    s32 i;
    s32 hp;
    u32 sp;
    u32 status;
    s16 id;

    persona = datPersonaGetByPcId(*(u16*)(event + 2));
    skills = datPersonaGetSkills(persona);
    skillCount = datPersonaCountValidSkills(persona);
    resultCount = 0;
    for (i = 0; i < skillCount; i++)
    {
        skill = skills[i];
        if (FUN_00300af0(skill) == 0)
            continue;
        if (FUN_0017b660(*(s16*)(event + 2), skill) != 0)
            continue;
        switch ((u16)skill)
        {
        case 0xc0:
        case 0xc1:
        case 0xc2:
            id = *(s16*)(event + 2);
            FUN_0017be10(id, id, skill, 0,
                         &hp, &sp, &status);
            FUN_005225a8(DAT_00684d70 + 0x60, hp, sp, status);
            if (hp > 0 && FUN_0017bb40(skill) == 0)
            {
                result[resultCount] = skill;
                resultCount++;
            }
            break;
        default:
            continue;
        }
    }
    *count = resultCount;
    FUN_005225a8(DAT_00684d70 + 0x80, resultCount);
}
// FUN_001FCB30 NONMATCHING
void func_001fcb30(u8* event, u32* result, s32* count)
{
    s32 skill;
    s32 resultCount;
    s32 i;
    u32 skillId;
    s32 hp;
    u32 sp;
    u32 status;

    resultCount = 0;
    for (i = 0; i < 0xc; i++)
    {
        skill = FUN_001706c0(*(s16*)(event + 2), (s16)i);
        if (skill != 0)
        {
            skill = FUN_00170670(*(s16*)(event + 2), (s16)i);
            skillId = FUN_00170e90((u16)skill);
            if (FUN_0017b4e0(*(u16*)(skillId + 8)) != 0)
            {
                FUN_0017be10(*(s16*)(event + 2), *(s16*)(event + 2),
                             *(u16*)(skillId + 8), 1, &hp, &sp, &status);
                FUN_005225a8(DAT_00684d70 + 0x60, hp, sp, status);
                if (hp > 0)
                {
                    switch (skill)
                    {
                    case 0xfa1:
                    case 0xfa2:
                        result[resultCount] = FUN_00170670(*(s16*)(event + 2), (s16)i) & 0xffff;
                        resultCount++;
                        break;
                    }
                }
            }
        }
    }
    *count = resultCount;
    FUN_005225a8(0x684e00, resultCount);
}


// FUN_001FCCC0
void func_001fccc0(u8* src, u8* dst, u32 skillId)
{
    u16 skill;
    u32 entry;
    s32 event_id;
    s32 i;
    s16 currentSkill;

    entry = FUN_00170e90((s16)skillId);
    skill = *(u16*)(entry + 8);
    if (FUN_0017b4e0(skill) == 0)
        FUN_0019d3f0((u32)(DAT_00684d60 - 0x10), 0x23a);

    FUN_0017b860(*(s16*)(dst + 2), *(s16*)(src + 2), skill, 1);
    for (i = 0; i < 0xc; i++) {
        event_id = *(s16*)(src + 2);
        currentSkill = FUN_001706c0(event_id, (s16)i);
        if (currentSkill != 0) {
            event_id = *(s16*)(src + 2);
            if (skillId == (FUN_00170670(event_id, (s16)i) & 0xffff))
                break;
        }
    }
    if (i >= 0xc)
        FUN_0019d3f0((u32)(DAT_00684d60 - 0x10), 0x249);
    event_id = *(s16*)(src + 2);
    currentSkill = FUN_001706c0(event_id, (s16)i);
    event_id = *(s16*)(src + 2);
    FUN_00170710(event_id, (s16)i, (s16)(currentSkill - 1));
}
// FUN_001FCE20 NONMATCHING


void func_001fce20(u8* param_1,u16 *param_2,int param_3)



{

  u16 uVar1;

  int iVar2;

  int sVar3;

  int sVar4;

  u32 uVar5;

  u32 uVar6;

  int lVar7;

  int lVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;
  int iVar13;


  u16 auStack_50 [8];

  u16 auStack_40 [8];

  int aiStack_30 [9];

  u8 auStack_c [4];

  u8 auStack_8 [4];

  int iStack_4;

  

  if (param_3 == 0) {

    FUN_0019d3f0(0x684d60,0x29b);

  }

  iVar13 = (int)param_1;

  if (param_3 == 1) {

    uVar1 = *param_2;

    lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),uVar1);

    if (lVar7 != 0) {

      FUN_0019d3f0(0x684d60,0x215);

    }

    sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),uVar1);

    FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0);

    sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),uVar1);

    switch (sVar4) {
    case 1:
      sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));
      FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
      break;
    case 2:
      sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));
      FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
      break;
    }
  }

  else {

    uVar5 = FUN_002ffd70(param_1);

    uVar6 = FUN_002ffdf0(param_1);

    iVar10 = 0;

    iVar9 = 0;

    for (iVar11 = 0; iVar11 < param_3; iVar11 = iVar11 + 1) {

      uVar1 = param_2[iVar11];

      lVar7 = FUN_0017c070(uVar1);

      if (lVar7 == 0) {

        auStack_40[iVar10] = uVar1;

        iVar10 = iVar10 + 1;

      }

      else {

        auStack_50[iVar9] = uVar1;

        iVar9 = iVar9 + 1;

      }

    }

    for (iVar11 = 0; iVar11 < iVar10; iVar11 = iVar11 + 1) {

      FUN_0017be10(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),auStack_40[iVar11],0,

                   &iStack_4,auStack_8,auStack_c);

      aiStack_30[iVar11] = ((uVar5 & 0xffff) + iStack_4) - (uVar6 & 0xffff);

    }

    lVar7 = FUN_0051e0e0(aiStack_30[0]);

    iVar11 = 0;

    for (iVar12 = 1; iVar12 < iVar10; iVar12 = iVar12 + 1) {

      iVar2 = aiStack_30[iVar12];

      lVar8 = FUN_0051e0e0(iVar2);

      if (lVar8 < lVar7) {

        lVar7 = FUN_0051e0e0(iVar2);

        iVar11 = iVar12;

      }

    }

    uVar1 = auStack_40[iVar11];

    FUN_0017be10(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0,&iStack_4,auStack_8

                 ,auStack_c);

    iStack_4 = iStack_4 + (uVar5 & 0xffff);

    if (((int)(((uVar6 & 0xffff) * 0x50) / 100) < iStack_4) || (iVar9 == 0)) {

      lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),uVar1);

      if (lVar7 != 0) {

        FUN_0019d3f0(0x684d60,0x215);

      }

      sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),uVar1);

      FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0);

      sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),uVar1);

      switch (sVar4) {
      case 1:
        sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));
        FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
        break;
      case 2:
        sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));
        FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
        break;
      }

    }

    else {

      lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),auStack_50[0]);

      if (lVar7 != 0) {

        FUN_0019d3f0(0x684d60,0x215);

      }

      sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),auStack_50[0]);

      FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),auStack_50[0],0);

      sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),auStack_50[0]);

      switch (sVar4) {
      case 1:
        sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));
        FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
        break;
      case 2:
        sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));
        FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);
        break;
      }

    }

  }

  return;

}
// FUN_001FD350 NONMATCHING


void func_001fd350(u8* param_1,u32 *param_2,int param_3)



{
  extern void FUN_0017be10(int param_1, int param_2, u16 param_3, int param_4,
                           void* param_5, void* param_6, void* param_7);

  u16 uVar1;

  u32 uVar2;

  int iVar3;

  u16 uVar4;

  u16 uVar5;

  int iVar6;

  s32 lVar7;

  s32 lVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u32 auStack_70 [8];

  u32 auStack_50 [8];

  int aiStack_30 [8];

  u8 auStack_c [4];

  u8 auStack_8 [4];

  int iStack_4;

  

  if (param_3 == 0) {

    FUN_0019d3f0((u32)DAT_00684d60, 0x2fa);

  }

  if (param_3 == 1) {

    func_001fccc0(param_1,param_1,*param_2);

  }

  else {

    uVar4 = FUN_002ffd70(param_1);

    uVar5 = FUN_002ffdf0(param_1);

    iVar6 = 0;

    iVar9 = 0;

    for (iVar10 = 0; iVar10 < param_3; iVar10 = iVar10 + 1) {

      uVar2 = param_2[iVar10];

      iVar11 = FUN_00170e90((short)uVar2);

      lVar7 = FUN_0017c070(*(u16 *)(iVar11 + 8));

      if (lVar7 == 0) {

        auStack_50[iVar6] = uVar2;

        iVar6 = iVar6 + 1;

      }

      else {

        auStack_70[iVar9] = uVar2;

        iVar9 = iVar9 + 1;

      }

    }

    for (iVar10 = 0; iVar10 < iVar6; iVar10 = iVar10 + 1) {

      iVar11 = FUN_00170e90(*(u16 *)(param_2 + iVar10));

      uVar1 = *(u16 *)((int)param_1 + 2);

      FUN_0017be10(uVar1,uVar1,*(u16 *)(iVar11 + 8),1,&iStack_4,auStack_8,auStack_c);

      aiStack_30[iVar10] = ((uVar4 & 0xffff) + iStack_4) - (uVar5 & 0xffff);

    }

    lVar7 = FUN_0051e0e0(aiStack_30[0]);

    iVar10 = 0;

    for (iVar11 = 1; iVar11 < iVar6; iVar11 = iVar11 + 1) {

      iVar3 = aiStack_30[iVar11];

      lVar8 = FUN_0051e0e0(iVar3);

      if (lVar8 < lVar7) {

        lVar7 = FUN_0051e0e0(iVar3);

        iVar10 = iVar11;

      }

    }

    iVar6 = FUN_00170e90(*(u16 *)(param_2 + iVar10));

    uVar1 = *(u16 *)((int)param_1 + 2);

    FUN_0017be10(uVar1,uVar1,*(u16 *)(iVar6 + 8),1,&iStack_4,auStack_8,auStack_c);

    iStack_4 = iStack_4 + (uVar4 & 0xffff);

    if (((int)(((uVar5 & 0xffff) * 0x50) / 100) < iStack_4) || (iVar9 == 0)) {

      func_001fccc0(param_1,param_1,auStack_50[iVar10]);

    }

    else {

      func_001fccc0(param_1,param_1,auStack_70[0]);

    }

  }

  return;

}
