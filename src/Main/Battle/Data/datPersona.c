#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "temporary.h"
#include "Kosaka/k_assert.h"

// FUN_001732f0
u8 datPersonaGetLevel(DatPersonaWork* persona)
{
    return persona->level;
}

// FUN_00173300
u8 datPersonaGetLevelByPcId(u16 pcId)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);
    return persona->level;
}

// FUN_00173330
u32 datPersonaGetNextExp(DatPersonaWork* persona)
{
    return persona->nextExp;
}

u32 func_00176210(DatPersonaWork* persona, u16 level);
u32 FUN_00175410(void);
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u8* DAT_007ce430;
extern u8* DAT_007ce434;
extern f32 DAT_007caed4;
extern f32 DAT_007caed8;
extern f32 DAT_007caedc;
extern f32 DAT_007cada8;
extern void func_00175ce0(DatPersonaWork* persona, u8* result);
extern void* FUN_0017cd30(void* persona);

u32 FUN_00176600(DatPersonaWork* persona);
u32 FUN_00176680(DatPersonaWork* persona, u16 personaId);
void FUN_00176da0(DatPersonaWork* persona);
void FUN_00176fb0(u16 personaId, u16* skills, s32* skillCount);
s32 FUN_001770d0(u16 personaId, s16 skillId);
s16 FUN_001748c0(void);
DatPersonaWork* FUN_001749a0(s16 heroPersonaIdx);
u32 FUN_00174c10(s16 heroPersonaIdx);
DatPersonaWork* FUN_00174e70(u16 personaId);
u8 FUN_00175200(s16 heroPersonaIdx);
u16 FUN_001752b0(void);

// FUN_00173340
void datPersona00173340(DatPersonaWork* persona)
{
    func_00176210(persona, (u16)(persona->level + 1));
}

// FUN_00173370
u16* datPersonaGetSkills(DatPersonaWork* persona)
{
    return persona->skills;
}

// FUN_00173380
u16* datPersonaGetSkillsByPcId(u16 pcId)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    return persona->skills;
}

// FUN_00173580
u16 datPersonaGetTotalStat(DatPersonaWork* persona, u16 statId)
{
    s16 naturalStat;
    s16 bonusStat;
    s8 stat3;
    s16 total;

    K_ASSERT(statId < PERSONA_STAT_MAX, 316);

    naturalStat = persona->naturalStats[statId];
    bonusStat = datPersonaGetBonusStat(persona, statId);
    stat3 = datPersonaGetStat3(persona, statId);
    total = naturalStat + bonusStat + stat3;

    if (total >= 99)
    {
        total = 99;
    }

    return (u8)total;
}

// was probably inlined
u8 datPersonaGetNaturalStat(DatPersonaWork* persona, u16 statId)
{
    K_ASSERT(statId < PERSONA_STAT_MAX, 316);

    return persona->naturalStats[statId];
}

// FUN_00173b00
s8 datPersonaGetBonusStat(DatPersonaWork* persona, u16 statId)
{
    K_ASSERT(statId < PERSONA_STAT_MAX, 454);

    return persona->bonusStats[statId];
}

// FUN_00173b60
void datPersonaSetBonusStatByPcId(u16 pcId, u16 statId, u8 amount)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    persona->bonusStats[statId] = amount;
}

// FUN_00173bb0
void datPersonaAddToBonusStatByPcId(u16 pcId, u16 statId, s8 amount)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    persona->bonusStats[statId] += amount;
}

// FUN_00173c00
s8 datPersonaGetStat3(DatPersonaWork* persona, u16 statId)
{
    K_ASSERT(statId < PERSONA_STAT_MAX, 503);

    return persona->stats3[statId];
}

// FUN_00174650
u16 datPersonaAddToNaturalStat(DatPersonaWork* persona, u16 statId, s8 amount)
{
    s16 naturalStat;
    s16 statTotal;

    K_ASSERT(statId < PERSONA_STAT_MAX, 722);

    naturalStat = (s16)(u16)persona->naturalStats[statId];
    statTotal = naturalStat + amount;
    if (statTotal > 99)
    {
        statTotal = 99;
    }
    else if (statTotal < 0)
    {
        statTotal = 0;
    }


    persona->naturalStats[statId] = statTotal;

    return (u8)statTotal;
}

// FUN_00174710
u16 datPersonaAddToNaturalStatHeroPersona(u16 heroPersonaIdx, u16 statId, s8 amount)
{
    s16 naturalStat;
    s16 statTotal;
    DatPersonaWork* heroPersona = datPersonaGetHeroPersona(heroPersonaIdx);

    K_ASSERT(heroPersona != NULL, 747);
    K_ASSERT(statId < PERSONA_STAT_MAX, 722);

    naturalStat = (s16)(u16)heroPersona->naturalStats[statId];
    statTotal = naturalStat + amount;
    if (statTotal > 99)
    {
        statTotal = 99;
    }
    else if (statTotal < 0)
    {
        statTotal = 0;
    }


    heroPersona->naturalStats[statId] = statTotal;

    return (u8)statTotal;
}

// FUN_00174800
DatPersonaWork* datPersonaGetByPcId(u16 pcId)
{
    DatPersonaWork* persona;
    DatPc* pcsNoReserved;
    u32 idx;

    if (IS_HERO(pcId))
    {
        persona = datPersonaGetHeroPersona(gGlobalWork.heroPersona.equippedPersona);
    }
    else 
    {
        K_ASSERT(pcId < PC_MAX, 779);

        idx = pcId - PC_YUKARI;
        pcsNoReserved = &gPcs[PC_YUKARI];
        persona = &pcsNoReserved[idx].persona;
    }

    K_ASSERT(persona != NULL, 783);

    return persona;
}

// FUN_00174960
u8 datPersonaHeroPersonaValid(s16 heroPersonaIdx)
{
    return (gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) != 0;
}

// FUN_00174a90
DatPersonaWork* datPersonaGetHeroPersona(s16 heroPersonaIdx)
{
    if (heroPersonaIdx < 0 || heroPersonaIdx >= (u16)FUN_00175410())
    {
        K_ASSERT(0, 848);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        return NULL;
    }

    return &gGlobalWork.heroPersona.personas[heroPersonaIdx];
}

// FUN_001748c0 NONMATCHING
s16 FUN_001748c0(void)
{
    u32 personaIdx;

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            return -1;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) == 0)
        {
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    return (s16)personaIdx;
}

// FUN_001749a0 NONMATCHING
DatPersonaWork* FUN_001749a0(s16 personaId)
{
    u32 personaIdx;
    s16 foundIdx;

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            foundIdx = -1;
            break;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0 &&
            gGlobalWork.heroPersona.personas[personaIdx].id == (u16)personaId)
        {
            foundIdx = (s16)personaIdx;
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    if (foundIdx == -1)
    {
        return NULL;
    }

    return datPersonaGetHeroPersona(foundIdx);
}

// FUN_00174b40 NONMATCHING
void FUN_00174b40(s16 personaId)
{
    u32 personaIdx;
    s16 foundIdx;

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            foundIdx = -1;
            break;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0 &&
            gGlobalWork.heroPersona.personas[personaIdx].id == (u16)personaId)
        {
            foundIdx = (s16)personaIdx;
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    FUN_00174c10(foundIdx);
}

// FUN_00174c10 NONMATCHING
u32 FUN_00174c10(s16 heroPersonaIdx)
{
    s16 selectedPersonaId;
    u32 personaIdx;

    if (heroPersonaIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)heroPersonaIdx)
    {
        K_ASSERT(false, 0x369);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        return 0;
    }

    selectedPersonaId = (s16)FUN_001752b0();
    for (; heroPersonaIdx < 0xb; heroPersonaIdx++)
    {
        memcpy(&gGlobalWork.heroPersona.personas[heroPersonaIdx],
               &gGlobalWork.heroPersona.personas[heroPersonaIdx + 1], 0x34);
    }
    memset(&gGlobalWork.heroPersona.personas[11], 0, 0x34);

    for (personaIdx = 0;
         personaIdx < (FUN_00175410() & 0xffff);
         personaIdx = (personaIdx + 1) & 0xffff)
    {
        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0 &&
            gGlobalWork.heroPersona.personas[personaIdx].id == (u16)selectedPersonaId)
        {
            selectedPersonaId = (s16)personaIdx;
            goto selected_persona_found;
        }
    }

    selectedPersonaId = -1;

selected_persona_found:
    if (selectedPersonaId != -1)
    {
        FUN_00175200(selectedPersonaId);
    }

    return 1;
}

// FUN_00174e20
DatPersonaWork* FUN_00174e20(u16 personaId)
{
    DatPersonaWork* persona;

    persona = FUN_00174e70(personaId);
    if (persona == NULL)
    {
        K_ASSERT(false, 0x38c);
    }

    return persona;
}

// FUN_00174e70 NONMATCHING
DatPersonaWork* FUN_00174e70(u16 personaId)
{
    u32 personaIdx;
    DatPersonaWork* persona;

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            persona = NULL;
            break;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) == 0)
        {
            persona = &gGlobalWork.heroPersona.personas[personaIdx];
            FUN_00176680(persona, personaId);
            persona->flags &= 0xc;
            persona->flags |= PERSONA_FLAG_VALID;
            FUN_0017cd30(persona);
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    return persona;
}

// FUN_00174fb0 NONMATCHING
u8 FUN_00174fb0(DatPersonaWork* source)
{
    u32 personaIdx;
    DatPersonaWork* persona;

    K_ASSERT(source != NULL, 0x3b0);
    K_ASSERT(source->id != 0 && source->id <= 0xff, 0x3b1);

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            persona = NULL;
            break;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) == 0)
        {
            persona = &gGlobalWork.heroPersona.personas[personaIdx];
            memcpy(persona, source, 0x34);
            persona->flags &= 0xc;
            persona->flags |= PERSONA_FLAG_VALID;
            FUN_0017cd30(persona);
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    return persona != NULL;
}

// FUN_00175130 NONMATCHING
void FUN_00175130(s16 personaId)
{
    u32 personaIdx;
    s16 foundIdx;

    personaIdx = 0;
    while (true)
    {
        if ((FUN_00175410() & 0xffff) <= personaIdx)
        {
            foundIdx = -1;
            break;
        }

        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0 &&
            gGlobalWork.heroPersona.personas[personaIdx].id == (u16)personaId)
        {
            foundIdx = (s16)personaIdx;
            break;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    FUN_00175200(foundIdx);
}

// FUN_00175200 NONMATCHING
u8 FUN_00175200(s16 heroPersonaIdx)
{
    u8 valid;
    s16 selectedIdx;

    if (heroPersonaIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)heroPersonaIdx)
    {
        K_ASSERT(false, 0x3ca);
    }

    valid = (gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) != 0;
    selectedIdx = heroPersonaIdx;
    if (!valid)
    {
        selectedIdx = gGlobalWork.heroPersona.equippedPersona;
    }

    gGlobalWork.heroPersona.equippedPersona = selectedIdx;
    return valid;
}

// FUN_001752b0 NONMATCHING
u16 FUN_001752b0(void)
{
    s16 heroPersonaIdx;

    heroPersonaIdx = gGlobalWork.heroPersona.equippedPersona;
    if (heroPersonaIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)heroPersonaIdx)
    {
        K_ASSERT(false, 0x3dd);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        K_ASSERT(false, 0x3de);
    }

    return gGlobalWork.heroPersona.personas[heroPersonaIdx].id;
}

// FUN_00175360 NONMATCHING
s16 FUN_00175360(void)
{
    s16 heroPersonaIdx;

    heroPersonaIdx = gGlobalWork.heroPersona.equippedPersona;
    if (heroPersonaIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)heroPersonaIdx)
    {
        K_ASSERT(false, 0x3e8);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        K_ASSERT(false, 0x3e9);
    }

    return heroPersonaIdx;
}

// FUN_00175410
u32 FUN_00175410(void)
{
    u32 modeFlags;

    modeFlags = gGlobalWork.flags[0x90];
    if (modeFlags & 4)
    {
        return 0xc;
    }
    if (modeFlags & 2)
    {
        return 10;
    }
    if (modeFlags & 1)
    {
        return 9;
    }
    if (modeFlags & 0x2000)
    {
        return 8;
    }
    if (modeFlags & 0x1000)
    {
        return 6;
    }

    return 4;
}

// FUN_001754a0 NONMATCHING
void func_001754a0(u16 mode)
{
    u32 modeFlags;

    modeFlags = gGlobalWork.flags[0x90] & 0xffffcff8;
    switch (mode & 0xffff)
    {
        case 0:
            break;
        case 1:
            modeFlags |= 0x1000;
            break;
        case 2:
            modeFlags |= 0x3000;
            break;
        case 3:
            modeFlags |= 0x3001;
            break;
        case 4:
            modeFlags |= 0x3003;
            break;
        case 5:
            modeFlags |= 0x3007;
            break;
        default:
            K_ASSERT(false, 0x42a);
            break;
    }

    gGlobalWork.flags[0x90] = modeFlags;
}

// FUN_001755c0 NONMATCHING
u32 func_001755c0(void)
{
    u32 personaCount;

    personaCount = FUN_00175410();
    switch (personaCount)
    {
        case 4:
            return 0;
        case 6:
            return 1;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 4;
        case 0xc:
            return 5;
        default:
            K_ASSERT(false, 0x43e);
            return 0xffff;
    }
}

// FUN_001756f0 NONMATCHING
s16 FUN_001756f0(void)
{
    u16 personaCount;
    u16 personaIdx;
    s16 validCount;

    personaCount = (u16)FUN_00175410();
    validCount = 0;
    for (personaIdx = 0; personaIdx < personaCount; personaIdx++)
    {
        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0)
        {
            validCount++;
        }
    }

    return validCount;
}
// FUN_001757f0
void datPersonaClearHeroPersonas()
{
    memset(gGlobalWork.heroPersona.personas, 0, sizeof(gGlobalWork.heroPersona.personas));
}
// FUN_00175820 NONMATCHING
u32 func_00175820(u16 mode, u16 personaId)
{
    s16 selectedIdx;
    u32 personaIdx;
    DatPersonaWork* persona;
    u32 maxPersonaCount;

    selectedIdx = gGlobalWork.heroPersona.equippedPersona;
    mode &= 0xffff;
    if (mode != 1)
    {
        if (mode == 1)
        {
            s16 equippedIdx;

            equippedIdx = gGlobalWork.heroPersona.equippedPersona;
            if (equippedIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)equippedIdx)
            {
                K_ASSERT(false, 0x350);
            }

            if ((gGlobalWork.heroPersona.personas[equippedIdx].flags & PERSONA_FLAG_VALID) == 0)
            {
                persona = NULL;
            }
            else
            {
                persona = &gGlobalWork.heroPersona.personas[equippedIdx];
            }
        }
        else
        {
            K_ASSERT(mode <= 10, 0x30b);
            persona = &gPcs[mode].persona;
        }

        K_ASSERT(persona != NULL, 0x30f);
        FUN_00176680(persona, personaId);
        persona->flags = PERSONA_FLAG_VALID;
        return 1;
    }

    selectedIdx = FUN_001748c0();
    if (selectedIdx == -1)
    {
        persona = NULL;
    }
    else
    {
        persona = &gGlobalWork.heroPersona.personas[selectedIdx];
        FUN_00176680(persona, personaId);
        persona->flags &= 0xc;
        persona->flags |= PERSONA_FLAG_VALID;
        FUN_0017cd30(persona);
    }

    K_ASSERT(persona != NULL, 0x38c);

    for (personaIdx = 0;
         personaIdx < (FUN_00175410() & 0xffff);
         personaIdx = (personaIdx + 1) & 0xffff)
    {
        if ((gGlobalWork.heroPersona.personas[personaIdx].flags & PERSONA_FLAG_VALID) != 0 &&
            gGlobalWork.heroPersona.personas[personaIdx].id == (u16)(s16)personaId)
        {
            selectedIdx = (s16)personaIdx;
            goto selected_idx_found;
        }
    }

    selectedIdx = -1;

selected_idx_found:
    if (selectedIdx >= 0)
    {
        u32 modeFlags;

        modeFlags = gGlobalWork.flags[0x90];
        if (modeFlags & 4)
        {
            maxPersonaCount = 0xc;
        }
        else if (modeFlags & 2)
        {
            maxPersonaCount = 10;
        }
        else if (modeFlags & 1)
        {
            maxPersonaCount = 9;
        }
        else if (modeFlags & 0x2000)
        {
            maxPersonaCount = 8;
        }
        else if (modeFlags & 0x1000)
        {
            maxPersonaCount = 6;
        }
        else
        {
            maxPersonaCount = 4;
        }

        if ((s32)selectedIdx >= (s32)maxPersonaCount)
        {
            K_ASSERT(false, 0x486);
        }
    }

    if (selectedIdx < 0 || (FUN_00175410() & 0xffff) <= (u16)selectedIdx)
    {
        K_ASSERT(false, 0x3ca);
    }

    if ((gGlobalWork.heroPersona.personas[selectedIdx].flags & PERSONA_FLAG_VALID) != 0)
    {
        gGlobalWork.heroPersona.equippedPersona = selectedIdx;
    }

    return 1;
}

// FUN_00175CE0 NONMATCHING


void func_00175ce0(DatPersonaWork* param_1,u8* param_2)



{

  u16 uVar1;

  u8 bVar2;

  short sVar3;

  u16 uVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar7;

  int iVar8;

  u16 uVar9;

  u16 *puVar10;

  u32 uVar11;

  char *pcVar12;

  u16 auStack_10 [8];

  

  iVar7 = (int)param_1;

  uVar1 = *(u16 *)(iVar7 + 2);

  if ((uVar1 == 0) || (0xff < uVar1)) {

    FUN_0019d3f0(0x5e3278,0x4c1);

  }

  FUN_00521408(param_2,0,0x28);

  for (uVar11 = 0; uVar11 < 5; uVar11 = uVar11 + 1 & 0xffff) {

    if (4 < uVar11) {

      FUN_0019d3f0(0x5e3278,0x13c);

    }

    iVar8 = iVar7 + uVar11;

    puVar10 = auStack_10 + uVar11;

    *puVar10 = (u16)*(u8 *)(iVar8 + 0x1c);

    if (4 < uVar11) {

      FUN_0019d3f0(0x5e3278,0x1c6);

    }

    *puVar10 = *puVar10 + (short)*(char *)(iVar8 + 0x21);

    if (4 < uVar11) {

      FUN_0019d3f0(0x5e3278,0x1f7);

    }

    *puVar10 = *puVar10 + (short)*(char *)(iVar8 + 0x26);

  }

  uVar5 = *(u8 *)(iVar7 + 4) + 1;

  uVar11 = *(u32 *)(iVar7 + 8);

  do {

    uVar6 = func_00176210(param_1,uVar5);

    if ((uVar11 < uVar6) || (99 < uVar5)) {

      return;

    }

    uVar4 = *(u16 *)(iVar7 + 2);

    if ((uVar4 < 0xc0) || (0xdf < uVar4)) {

      bVar2 = false;

    }

    else {

      bVar2 = true;

    }

    pcVar12 = (char *)param_2;

    if (bVar2) {

      if ((uVar4 < 0xc0) || (0xdf < uVar4)) {

        FUN_0019d3f0(0x5e3278,0x4f3);

      }

      iVar8 = (int)DAT_007ce430 + (*(u16 *)(iVar7 + 2) - 0xc0) * 0x26e;

      if (1 < uVar5) {

        for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1 & 0xffff) {

          uVar4 = auStack_10[uVar6];

          if ((u32)(u8)pcVar12[uVar6 + 0x22] + (u32)uVar4 < 99) {

            pcVar12[uVar6 + 0x22] =

                 pcVar12[uVar6 + 0x22] + *(char *)(iVar8 + uVar5 * 5 + uVar6 + 0x7a);

            if (99 < (u32)(u8)pcVar12[uVar6 + 0x22] + (u32)uVar4) {

              pcVar12[uVar6 + 0x22] = 'c' - (char)uVar4;

            }

          }

        }

      }

    }

    else {

      for (uVar4 = 0; uVar4 < 3; uVar4 = uVar4 + 1) {

        sVar3 = 0;

        for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1 & 0xffff) {

          if ((u32)(u8)pcVar12[uVar6 + 0x22] + (u32)auStack_10[uVar6] < 99) {

            sVar3 = sVar3 + (u16)*(u8 *)((u32)uVar1 * 0x46 + DAT_007ce428 + uVar6);

          }

        }

        if (sVar3 != 0) {

          sVar3 = FUN_002ffbc0();

          uVar9 = 0;

          for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1 & 0xffff) {

            if ((u32)(u8)pcVar12[uVar6 + 0x22] + (u32)auStack_10[uVar6] < 99) {

              uVar9 = uVar9 + *(u8 *)((u32)uVar1 * 0x46 + DAT_007ce428 + uVar6);

              if ((u16)(sVar3 + 1U) <= uVar9) {

                pcVar12[uVar6 + 0x22] = pcVar12[uVar6 + 0x22] + 1;

                break;

              }

            }

          }

        }

      }

    }

    uVar5 = uVar5 + 1 & 0xffff;

    *pcVar12 = *pcVar12 + '\x01';

  } while( true );

}
// FUN_00176100 NONMATCHING


void func_00176100(DatPersonaWork* param_1,u8* param_2)



{

  int param_1_i = (int)param_1;

  u32 uVar1;

  

  if ((*(u16 *)(param_1_i + 2) == 0) || (0xff < *(u16 *)(param_1_i + 2))) {

    FUN_0019d3f0(0x5e3278,0x552);

  }

  *(char *)(param_1_i + 4) = *(char *)(param_1_i + 4) + *param_2;

  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1 & 0xffff) {

    *(char *)(param_1_i + uVar1 + 0x1c) = *(char *)(param_1_i + uVar1 + 0x1c) + param_2[uVar1 + 0x22];

  }

  return;

}
// FUN_001761B0 NONMATCHING


u8 func_001761b0(DatPersonaWork* param_1)



{

  int param_1_i = (int)param_1;

  u8 bVar1;

  u32 uVar2;

  

  if (*(u8 *)(param_1_i + 4) < 99) {

    uVar2 = func_00176210(param_1,*(u8 *)(param_1_i + 4) + 1);

    bVar1 = uVar2 <= *(u32 *)(param_1_i + 8);

  }

  else {

    bVar1 = false;

  }

  return bVar1;

}
// FUN_00176210 NONMATCHING






u32 func_00176210(DatPersonaWork* param_1,u16 param_2)



{

  int param_1_i = (int)param_1;

  u16 uVar1;

  u8 bVar2;

  long lVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  

  if ((param_2 & 0xffff) < 2) {

    iVar4 = 0;

  }

  else {

    if (99 < (param_2 & 0xffff)) {

      param_2 = 99;

    }

    uVar1 = *(u16 *)(param_1_i + 2);

    if ((uVar1 < 0xc0) || (0xdf < uVar1)) {

      bVar2 = false;

    }

    else {

      bVar2 = true;

    }

    if (bVar2) {

      if ((uVar1 < 0xc0) || (0xdf < uVar1)) {

        FUN_0019d3f0(0x5e3278,0x5a4);

      }

      uVar1 = *(u16 *)((u32)*(u16 *)(param_1_i + 2) * 0x26e + DAT_007ce430 + -0x1d280);

      if ((uVar1 < 2) || (10 < uVar1)) {

        FUN_0019d3f0(0x5e3278,0x5a6);

      }

      iVar4 = *(int *)((param_2 & 0xffff) * 4 + (u32)uVar1 * 0x188 + (int)DAT_007ce434 + -0x318);

    }

    else {

      if (0xff < uVar1) {

        FUN_0019d3f0(0x5e3278,0x599);

      }

      fVar6 = (float)param_2;

      fVar5 = (float)*(u8 *)((u32)*(u16 *)(param_1_i + 2) * 0xe + DAT_007ce420 + 3);

      lVar3 = FUN_0017d800();

      if (lVar3 == 0) {

        iVar4 = (int)(((DAT_007caed8 + 0.0) - DAT_007caed4 * fVar5) *

                      fVar6 * DAT_007cada8 * fVar6 * fVar6 + 10.0);

      }

      else {

        iVar4 = (int)((2.5 - DAT_007caedc * fVar5) * fVar6 * DAT_007cada8 * fVar6 * fVar6 + 10.0);

      }

    }

  }

  return iVar4;

}
// FUN_001764b0
void datPersonaAddExp(DatPersonaWork* persona, s32 exp)
{
    K_ASSERT(exp >= 0, 1458);

    persona->nextExp += exp;
}

// FUN_00176510 NONMATCHING
void datPersonaMoveValidSkillsOnTop(DatPersonaWork* persona)
{
    s32 skillIdx;
    s32 nextSkillIdx;
    u16* skillSlot;

    K_ASSERT(persona != NULL, 1478);

    skillIdx = 0;
    nextSkillIdx = 0;
    while (skillIdx < PERSONA_MAX_SKILLS)
    {
        skillSlot = &persona->skills[skillIdx];
        if (*skillSlot == SKILL_SLASH_ATTACK)
        {
            nextSkillIdx = skillIdx + 1;

            while (nextSkillIdx < PERSONA_MAX_SKILLS &&
                   persona->skills[nextSkillIdx] == SKILL_SLASH_ATTACK)
            {
                nextSkillIdx++;
            }

            if (nextSkillIdx == PERSONA_MAX_SKILLS)
            {
                return;
            }
        }

        if (skillIdx != nextSkillIdx)
        {
            if (nextSkillIdx < PERSONA_MAX_SKILLS)
            {
                *skillSlot = persona->skills[nextSkillIdx];
            }
            else
            {
                *skillSlot = SKILL_SLASH_ATTACK;
            }
        }
        skillIdx++;
        nextSkillIdx++;
    }
}

// FUN_00176840
u8 datPersonaSetSkill(DatPersonaWork* persona, u16 skillId)
{
    s32 skillIdx;
    u16* skillSlot;

    K_ASSERT(persona != NULL && skillId != SKILL_SLASH_ATTACK, 1546);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        skillSlot = &persona->skills[skillIdx];
        if (*skillSlot == SKILL_SLASH_ATTACK)
        {
            *skillSlot = skillId;
            return true;
        }
    }

    return false;
}

// FUN_001768e0 NONMATCHING
u8 datPersonaResetSkill(DatPersonaWork* persona, u16 skillId)
{
    u16 skillId_p = skillId;
    DatPersonaWork* personaWork = persona;
    s32 skillIdx;

    K_ASSERT(personaWork != NULL && skillId_p != SKILL_SLASH_ATTACK, 1560);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        if (skillId == personaWork->skills[skillIdx])
        {
            personaWork->skills[skillIdx] = SKILL_SLASH_ATTACK;
            datPersonaMoveValidSkillsOnTop(personaWork);
            return true;
        }
    }

    return false;
}

// FUN_00176990 NONMATCHING
s32 datPersonaFindSkillIdx(DatPersonaWork* persona, u16 skillId)
{
    s32 skillIdx;

    K_ASSERT(persona != NULL && skillId != SKILL_SLASH_ATTACK, 1588);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        if (skillId == persona->skills[skillIdx])
        {
            return skillIdx;
        }
    }

    return -1;
}

// FUN_00175ca0
s32 FUN_00175ca0(DatPersonaWork* persona)
{
    s32 result;

    if (persona->id >= 0xc0 && persona->id <= 0xdf)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}

// FUN_00176a30
u32 datPersonaCountValidSkills(DatPersonaWork* persona)
{
    s32 skillIdx;
    u16* skillSlot;
    u32 validSkills = 0;

    K_ASSERT(persona != NULL, 1601);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        skillSlot = &persona->skills[skillIdx];
        if (*skillSlot != SKILL_SLASH_ATTACK)
            validSkills++;
    }

    return validSkills;
}

// FUN_00176600 NONMATCHING
u32 FUN_00176600(DatPersonaWork* persona)
{
    K_ASSERT(persona != NULL, 1497);

    if ((persona->flags & PERSONA_FLAG_HEART_ITEM) == 0)
    {
        return 0;
    }

    if ((persona->flags & 8) == 0)
    {
        return 1;
    }

    return 2;
}

// FUN_00176680 NONMATCHING
u32 FUN_00176680(DatPersonaWork* persona, u16 personaId)
{
    u8* personaData;
    s8 statData[0x28];
    u32 statIdx;

    K_ASSERT(persona != NULL, 1515);
    K_ASSERT(personaId != 0 && personaId <= 0xff, 1516);

    personaData = DAT_007ce420 + (u32)personaId * 0x0e;
    persona->id = personaId;
    persona->level = personaData[3];
    *(u32*)((u8*)persona + 0x30) = 0;
    persona->nextExp = func_00176210(persona, personaData[3]);
    *(u32*)((u8*)persona + 0x2c) = 0;
    memcpy(persona->naturalStats, personaData + 4, 5);
    memset(persona->bonusStats, 0, 5);
    memset(persona->stats3, 0, 5);
    memset(persona->skills, 0, 0x10);

    func_00175ce0(persona, (u8*)statData);

    K_ASSERT(persona->id != 0 && persona->id <= 0xff, 1362);
    persona->level += statData[0];
    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        persona->naturalStats[statIdx] += statData[0x22 + statIdx];
    }

    FUN_00176da0(persona);
    return 1;
}

// FUN_00176ac0 NONMATCHING
u64 FUN_00176ac0(DatPersonaWork* persona, DatPersonaWork* const* personas, s32 personaCount)
{
    s32 bonusTotals[PERSONA_STAT_MAX] = {0};
    s32 stat3Totals[PERSONA_STAT_MAX] = {0};
    s32 statIdx;
    s32 personaIdx;
    s32 statDelta;
    u32 currentStat;

    K_ASSERT(persona != NULL && personas != NULL && personaCount != 0, 1671);

    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        for (personaIdx = 0; personaIdx < personaCount; personaIdx++)
        {
            bonusTotals[statIdx] += personas[personaIdx]->bonusStats[statIdx];
            stat3Totals[statIdx] += (u8)personas[personaIdx]->stats3[statIdx];
        }
    }

    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        statDelta = bonusTotals[statIdx] + stat3Totals[statIdx] / personaCount;
        K_ASSERT(persona != NULL && statIdx < PERSONA_STAT_MAX, 1623);
        currentStat = (u8)persona->stats3[statIdx];
        if (currentStat + statDelta < 100)
        {
            persona->stats3[statIdx] = (s8)(currentStat + statDelta);
        }
        else
        {
            persona->stats3[statIdx] = 99;
        }
    }
    return 0;
}

// FUN_00176c80
u64 FUN_00176c80(DatPersonaWork* persona, DatPersonaWork* source)
{
    u8* personaBytes;
    u8* sourceBytes;
    s32 statIdx;

    K_ASSERT(persona != NULL && source != NULL, 1691);

    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        sourceBytes = (u8*)source + statIdx;
        personaBytes = (u8*)persona + statIdx;
        personaBytes[0x21] = sourceBytes[0x21];
        personaBytes[0x26] = sourceBytes[0x26];
    }
    return 0;
}

// FUN_00176d10
u64 FUN_00176d10(DatPersonaWork* persona, DatPersonaWork* source)
{
    s32 statIdx;

    K_ASSERT(persona != NULL && source != NULL, 1704);

    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        ((DatPersonaWork*)((u8*)persona + statIdx))->stats3[0] =
            ((DatPersonaWork*)((u8*)source + statIdx))->bonusStats[0];
    }
    return 0;
}

// FUN_00176da0 NONMATCHING
void FUN_00176da0(DatPersonaWork* persona)
{
    u16 personaId;
    u8* skillData;
    s16 skillId;
    s32 skillIdx;
    s32 skillSlotIdx;
    s32 skillCount;

    personaId = persona->id;
    if (personaId >= 0xc0 && personaId <= 0xdf)
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        skillCount = 0x20;
    }
    else
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        skillCount = 0x10;
    }

    for (skillIdx = 0; skillIdx < skillCount; skillIdx++)
    {
        if (skillData[skillIdx * 4] == 0 && skillData[skillIdx * 4 + 1] == 1)
        {
            skillId = *(s16*)(skillData + skillIdx * 4 + 2);
            K_ASSERT(persona != NULL && skillId != 0, 1546);
            for (skillSlotIdx = 0; skillSlotIdx < PERSONA_MAX_SKILLS; skillSlotIdx++)
            {
                if (persona->skills[skillSlotIdx] == SKILL_SLASH_ATTACK)
                {
                    persona->skills[skillSlotIdx] = skillId;
                    break;
                }
            }
        }
    }
}

// FUN_00176FB0 NONMATCHING
void FUN_00176FB0(u16 personaId, u16* skills, s32* skillCount)
{
    u8* skillData;
    s32 skillIdx;
    s32 validSkills;
    s32 skillLimit;

    validSkills = 0;
    if (personaId < 0xc0 || personaId > 0xdf)
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        skillLimit = 0x10;
    }
    else
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        skillLimit = 0x20;
    }

    for (skillIdx = 0; skillIdx < skillLimit; skillIdx++)
    {
        if (skillData[skillIdx * 4] == 0 && skillData[skillIdx * 4 + 1] == 1)
        {
            skills[validSkills] = *(u16*)(skillData + skillIdx * 4 + 2);
            validSkills++;
        }
    }

    *skillCount = validSkills;
}

// FUN_001770D0 NONMATCHING
s32 FUN_001770D0(u16 personaId, s16 skillId)
{
    u8* skillData;
    s32 skillIdx;
    s32 skillOrder;
    s32 skillLimit;
    s32 assertLine;

    skillOrder = 0;
    if (personaId < 0xc0 || personaId > 0xdf)
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        skillLimit = 0x10;
        assertLine = 1848;
    }
    else
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        skillLimit = 0x20;
        assertLine = 1829;
    }

    for (skillIdx = 0; skillIdx < skillLimit; skillIdx++)
    {
        if (skillData[skillIdx * 4] != 0 && skillData[skillIdx * 4 + 1] == 1)
        {
            if (skillId == *(s16*)(skillData + skillIdx * 4 + 2))
            {
                break;
            }
            skillOrder++;
        }
    }

    K_ASSERT(skillIdx < 0x10 && skillData[skillIdx * 4 + 1] == 1, assertLine);
    return skillOrder;
}

// FUN_00177270
void FUN_00177270(void)
{
    return;
}
