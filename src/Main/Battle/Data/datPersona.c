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

#pragma alias func_00176210_u16 func_00176210
extern u32 func_00176210_u16(DatPersonaWork* persona, u16 level);
u32 FUN_00175410(void);
u32 FUN_0017d800(void);
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u8* DAT_007ce430;
extern u8* DAT_007ce434;
extern f32 DAT_007caed4;
extern f32 DAT_007caed8;
extern f32 DAT_007caedc;
extern f32 DAT_007cada8;
extern void FUN_00521408(void* destination, s32 value, u32 size);
extern void func_00175ce0(DatPersonaWork* persona, u8* result);
extern void* FUN_0017cd30(void* persona);

u32 FUN_00176600(DatPersonaWork* persona);
void FUN_00176680(DatPersonaWork* persona, u16 personaId);
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
    func_00176210_u16(persona, (u16)(persona->level + 1));
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

// FUN_001748c0
s16 FUN_001748c0(void)
{
    u32 personaIdx;
    DatPersonaWork* persona;

    personaIdx = 0;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        persona = &gGlobalWork.heroPersona.personas[(u16)personaIdx];
        if ((persona->flags & PERSONA_FLAG_VALID) == 0)
        {
            return (s16)personaIdx;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    return -1;
}

// FUN_001749a0
DatPersonaWork* FUN_001749a0(s16 personaId)
{
    s16 foundIdx;
    u32 personaIdx;
    s32 targetPersonaId;
    u8* personaBase;

    personaIdx = 0;
    targetPersonaId = personaId;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) != 0 &&
            *(u16*)(personaBase + 0x9ae) == targetPersonaId)
        {
            foundIdx = (s16)personaIdx;
            goto found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundIdx = -1;

found:
    if (foundIdx == -1)
    {
        return NULL;
    }

    return datPersonaGetHeroPersona(foundIdx);
}
// FUN_00174b40
void FUN_00174b40(s16 personaId)
{
    s16 foundPersonaId;
    u32 personaIdx;
    s32 targetPersonaId;
    u8* personaBase;

    personaIdx = 0;
    targetPersonaId = personaId;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) != 0 &&
            *(u16*)(personaBase + 0x9ae) == targetPersonaId)
        {
            foundPersonaId = (s16)personaIdx;
            goto found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundPersonaId = -1;

found:
    FUN_00174c10(foundPersonaId);
}
// FUN_00174c10
u32 FUN_00174c10(s16 heroPersonaIdx)
{
    s16 selectedPersonaId;
    s16 foundPersonaIdx;
    s32 targetPersonaId;
    u32 personaIdx;
    u8* personaBase;

    if (heroPersonaIdx < 0 || heroPersonaIdx >= (s32)(FUN_00175410() & 0xffff))
    {
        K_ASSERT(false, 0x369);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        return 0;
    }

    selectedPersonaId = (s16)FUN_001752b0();
    heroPersonaIdx = (s16)heroPersonaIdx;
    for (; heroPersonaIdx < 0xb; heroPersonaIdx++)
    {
        memcpy(&gGlobalWork.heroPersona.personas[heroPersonaIdx],
               &gGlobalWork.heroPersona.personas[heroPersonaIdx + 1], 0x34);
    }
    memset(&gGlobalWork.heroPersona.personas[11], 0, 0x34);
    personaIdx = 0;
    targetPersonaId = (s16)selectedPersonaId;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) != 0 &&
            *(u16*)(personaBase + 0x9ae) == targetPersonaId)
        {
            foundPersonaIdx = (s16)personaIdx;
            goto selected_persona_found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundPersonaIdx = -1;

selected_persona_found:
    if (foundPersonaIdx != -1)
    {
        FUN_00175200(foundPersonaIdx);
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

// FUN_00174e70
DatPersonaWork* FUN_00174e70(u16 personaId)
{
    s16 foundPersonaIdx;
    u32 personaIdx;
    u8* personaBase;
    DatPersonaWork* persona;

    personaIdx = 0;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) == 0)
        {
            foundPersonaIdx = (s16)personaIdx;
            goto found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundPersonaIdx = -1;

found:
    if (foundPersonaIdx == -1)
    {
        return NULL;
    }

    persona = &gGlobalWork.heroPersona.personas[foundPersonaIdx];
    FUN_00176680(persona, personaId);
    gGlobalWork.heroPersona.personas[foundPersonaIdx].flags &= 0xc;
    gGlobalWork.heroPersona.personas[foundPersonaIdx].flags |= PERSONA_FLAG_VALID;
    FUN_0017cd30(persona);
    return persona;
}

// FUN_00174fb0
u8 FUN_00174fb0(DatPersonaWork* source)
{
    s16 foundPersonaIdx;
    u32 personaIdx;
    u8* personaBase;
    DatPersonaWork* persona;

    K_ASSERT(source != NULL, 0x3b0);
    K_ASSERT(source->id != 0 && source->id < 0x100, 0x3b1);

    personaIdx = 0;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) == 0)
        {
            foundPersonaIdx = (s16)personaIdx;
            goto found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundPersonaIdx = -1;

found:
    if (foundPersonaIdx == -1)
    {
        return 0;
    }

    persona = &gGlobalWork.heroPersona.personas[foundPersonaIdx];
    memcpy(persona, source, 0x34);
    gGlobalWork.heroPersona.personas[foundPersonaIdx].flags &= 0xc;
    gGlobalWork.heroPersona.personas[foundPersonaIdx].flags |= PERSONA_FLAG_VALID;
    FUN_0017cd30(persona);
    return 1;
}

// FUN_00175130
void FUN_00175130(s16 personaId)
{
    s16 foundPersonaId;
    u32 personaIdx;
    s32 targetPersonaId;
    u8* personaBase;

    personaIdx = 0;
    targetPersonaId = personaId;
    while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
    {
        personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
        if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) != 0 &&
            *(u16*)(personaBase + 0x9ae) == targetPersonaId)
        {
            foundPersonaId = (s16)personaIdx;
            goto found;
        }

        personaIdx = (personaIdx + 1) & 0xffff;
    }

    foundPersonaId = -1;

found:
    FUN_00175200(foundPersonaId);
}

// FUN_00175200
u8 FUN_00175200(s16 heroPersonaIdx)
{

    if (heroPersonaIdx >= 0 && heroPersonaIdx < (u16)FUN_00175410())
    {
    }
    else
    {
        K_ASSERT(false, 0x3ca);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        return 0;
    }

    gGlobalWork.heroPersona.equippedPersona = heroPersonaIdx;
    return 1;
}

// FUN_001752b0
u16 FUN_001752b0(void)
{
    s16 heroPersonaIdx;

    heroPersonaIdx = gGlobalWork.heroPersona.equippedPersona;
    if (heroPersonaIdx >= 0 && heroPersonaIdx < (u16)FUN_00175410())
    {
    }
    else
    {
        K_ASSERT(false, 0x3dd);
    }

    if ((gGlobalWork.heroPersona.personas[heroPersonaIdx].flags & PERSONA_FLAG_VALID) == 0)
    {
        K_ASSERT(false, 0x3de);
    }

    return gGlobalWork.heroPersona.personas[heroPersonaIdx].id;
}

// FUN_00175360
s16 FUN_00175360(void)
{
    s16 heroPersonaIdx;

    heroPersonaIdx = gGlobalWork.heroPersona.equippedPersona;
    if (heroPersonaIdx >= 0 && heroPersonaIdx < (u16)FUN_00175410())
    {
    }
    else
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

// FUN_001754a0
void func_001754a0(u16 mode)
{

    gGlobalWork.flags[0x90] &= ~0x1000;
    gGlobalWork.flags[0x90] &= ~0x2000;
    gGlobalWork.flags[0x90] &= ~1;
    gGlobalWork.flags[0x90] &= ~2;
    gGlobalWork.flags[0x90] &= ~4;

    switch (mode & 0xffff)
    {
        case 0:
            break;
        case 1:
            gGlobalWork.flags[0x90] |= 0x1000;
            break;
        case 2:
            gGlobalWork.flags[0x90] |= 0x1000;
            gGlobalWork.flags[0x90] |= 0x2000;
            break;
        case 3:
            gGlobalWork.flags[0x90] |= 0x1000;
            gGlobalWork.flags[0x90] |= 0x2000;
            gGlobalWork.flags[0x90] |= 1;
            break;
        case 4:
            gGlobalWork.flags[0x90] |= 0x1000;
            gGlobalWork.flags[0x90] |= 0x2000;
            gGlobalWork.flags[0x90] |= 1;
            gGlobalWork.flags[0x90] |= 2;
            break;
        case 5:
            gGlobalWork.flags[0x90] |= 0x1000;
            gGlobalWork.flags[0x90] |= 0x2000;
            gGlobalWork.flags[0x90] |= 1;
            gGlobalWork.flags[0x90] |= 2;
            gGlobalWork.flags[0x90] |= 4;
            break;
        default:
            K_ASSERT(false, 0x42a);
            break;
    }
}

// FUN_001755c0
u32 func_001755c0(void)
{
    u32 modeFlags;
    u16 personaCount;

    modeFlags = gGlobalWork.flags[0x90];
    if (modeFlags & 4)
    {
        personaCount = 0xc;
    }
    else if (modeFlags & 2)
    {
        personaCount = 10;
    }
    else if (modeFlags & 1)
    {
        personaCount = 9;
    }
    else if (modeFlags & 0x2000)
    {
        personaCount = 8;
    }
    else if (modeFlags & 0x1000)
    {
        personaCount = 6;
    }
    else
    {
        personaCount = 4;
    }

    switch ((u16)personaCount)
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

/* Removing this loses FUN_001756f0 (MATCH nd0 -> MISMATCH nd37) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001756f0
u16 FUN_001756f0(void)
{
    u16 validCount;
    u32 modeFlags;
    u16 maxPersonaCount;
    s32 personaCount;
    u16 personaIdx;
    u8 valid;

    validCount = 0;
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
    personaIdx = 0;
    personaCount = (u16)maxPersonaCount;
    for (; personaIdx < personaCount; personaIdx++)
    {
        valid = (gGlobalWork.heroPersona.personas[(s16)personaIdx].flags &
                 PERSONA_FLAG_VALID) != 0;
        if (valid)
        {
            validCount++;
        }
    }

    return validCount;
}
#pragma opt_loop_invariants off
// FUN_001757f0
void datPersonaClearHeroPersonas()
{
    memset(gGlobalWork.heroPersona.personas, 0, sizeof(gGlobalWork.heroPersona.personas));
}
// FUN_00175820
u32 func_00175820(u16 mode, u16 personaId)
{
    DatPersonaWork* persona;
    DatPc* pcsNoReserved;
    s16 selectedIdx;
    u16 maxPersonaCount;
    u32 personaIdx;
    s32 targetPersonaId;
    u8* personaBase;

    mode &= 0xffff;
    if (mode == 1)
    {
        selectedIdx = FUN_001748c0();
        if (selectedIdx == -1)
        {
            persona = NULL;
        }
        else
        {
            persona = &gGlobalWork.heroPersona.personas[selectedIdx];
            FUN_00176680(persona, personaId);
            gGlobalWork.heroPersona.personas[selectedIdx].flags &= 0xc;
            gGlobalWork.heroPersona.personas[selectedIdx].flags |= PERSONA_FLAG_VALID;
            FUN_0017cd30(persona);
        }

        K_ASSERT(persona != NULL, 0x38c);
        personaIdx = 0;
        targetPersonaId = (s16)personaId;
        while ((s32)(personaIdx & 0xffff) < (s32)(FUN_00175410() & 0xffff))
        {
            personaBase = (u8*)&gGlobalWork + (u16)personaIdx * sizeof(DatPersonaWork);
            if ((*(u16*)(personaBase + 0x9ac) & PERSONA_FLAG_VALID) != 0 &&
                *(u16*)(personaBase + 0x9ae) == targetPersonaId)
            {
                selectedIdx = (s16)personaIdx;
                goto selected_idx_found;
            }

            personaIdx = (personaIdx + 1) & 0xffff;
        }

        selectedIdx = -1;

selected_idx_found:
        if (selectedIdx >= 0)
        {
            u32 modeFlags = gGlobalWork.flags[0x90];

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

            if ((s32)selectedIdx < (u16)maxPersonaCount)
            {
                goto selected_idx_valid;
            }
        }

        K_ASSERT(false, 0x486);

selected_idx_valid:

        if (selectedIdx < 0 || selectedIdx >= (s32)(FUN_00175410() & 0xffff))
        {
            K_ASSERT(false, 0x3ca);
        }

        if ((gGlobalWork.heroPersona.personas[selectedIdx].flags &
             PERSONA_FLAG_VALID) != 0)
        {
            gGlobalWork.heroPersona.equippedPersona = selectedIdx;
        }
    }
    else
    {
        if (mode == 1)
        {
            selectedIdx = gGlobalWork.heroPersona.equippedPersona;
            if (selectedIdx < 0 || selectedIdx >= (s32)(FUN_00175410() & 0xffff))
            {
                K_ASSERT(false, 0x350);
            }

            persona = (gGlobalWork.heroPersona.personas[selectedIdx].flags &
                       PERSONA_FLAG_VALID) != 0
                          ? &gGlobalWork.heroPersona.personas[selectedIdx]
                          : NULL;
        }
        else
        {
            K_ASSERT(mode < 11, 0x30b);
            pcsNoReserved = &gPcs[PC_YUKARI];
            persona = &pcsNoReserved[mode - PC_YUKARI].persona;
        }

        K_ASSERT(persona != NULL, 0x30f);
        FUN_00176680(persona, personaId);
        persona->flags = PERSONA_FLAG_VALID;
    }

    return 1;
}
#pragma push
/* Removing this worsens FUN_00175ce0 (nd675 -> nd724) - measured W161. */
#pragma opt_loop_invariants on

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
  u16 uVar11;
  u32 nextExp;
  char *pcVar12;
  u16 auStack_10[8];

  iVar7 = (int)param_1;
  uVar1 = *(u16 *)(iVar7 + 2);
  K_ASSERT(uVar1 != 0 && uVar1 < 0x100, 0x4c1);
  FUN_00521408(param_2,0,0x28);
  for (uVar11 = 0; uVar11 < 5; uVar11 = uVar11 + 1) {
    if (4 < uVar11) {
      K_ASSERT(false,0x13c);
    }
    iVar8 = iVar7 + uVar11;
    puVar10 = auStack_10 + uVar11;
    *puVar10 = (u16)*(u8 *)(iVar8 + 0x1c);
    if (4 < uVar11) {
      K_ASSERT(false,0x1c6);
    }
    *puVar10 = *puVar10 + (short)*(char *)(iVar8 + 0x21);
    if (4 < uVar11) {
      K_ASSERT(false,0x1f7);
    }
    *puVar10 = *puVar10 + (short)*(char *)(iVar8 + 0x26);
  }
  uVar5 = *(u8 *)(iVar7 + 4) + 1;
  nextExp = *(u32 *)(iVar7 + 8);
  while ((nextExp >= func_00176210_u16(param_1,uVar5)) && (uVar5 <= 99)) {
    uVar4 = *(u16 *)(iVar7 + 2);
    if ((uVar4 < 0xc0) || (0xdf < uVar4)) {
      bVar2 = false;
    } else {
      bVar2 = true;
    }
    pcVar12 = (char *)param_2;
    if (bVar2) {
      if ((uVar4 < 0xc0) || (0xdf < uVar4)) {
        K_ASSERT(false,0x4f3);
      }
      iVar8 = (int)DAT_007ce430 + (uVar4 - 0xc0) * 0x26e;
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
    } else {
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
  }
}
#pragma pop
// FUN_00176100


void func_00176100(DatPersonaWork* persona, u8* result)



{
    s32 statIdx;
    u8* growthStat;
    u8* naturalStat;

    if (persona->id != 0 && persona->id < 0x100)
    {
    }
    else
    {
        K_ASSERT(false, 0x552);
    }
    persona->level += result[0];
    for (statIdx = 0; (s32)(statIdx & 0xffff) < PERSONA_STAT_MAX; statIdx = (statIdx + 1) & 0xffff)
    {
        growthStat = result + (statIdx & 0xffff) + 0x22;
        naturalStat = persona->naturalStats + (statIdx & 0xffff);
        *naturalStat += *growthStat;
    }
}
// FUN_001761B0


u8 func_001761b0(DatPersonaWork* param_1)



{
    if (param_1->level >= 99)
    {
        return false;
    }
    return func_00176210_u16(param_1, (u16)(param_1->level + 1)) <= param_1->nextExp;

}
// FUN_00176210 NONMATCHING






u32 func_00176210(DatPersonaWork* persona, u16 level)
{
    s32 persona_i = (s32)persona;
    f32 levelF;
    f32 growthF;
    s32 result;
    u32 scenario;

    if ((level & 0xffff) < 2)
    {
        result = 0;
    }
    else
    {
        if (99 < (level & 0xffff))
        {
            level = 99;
        }

        if ((*(u16*)(persona_i + 2) >= 0xc0) &&
            (*(u16*)(persona_i + 2) < 0xe0))
        {
            scenario = 1;
        }
        else
        {
            scenario = 0;
        }

        if (scenario == 0)
        {
            K_ASSERT(*(u16*)(persona_i + 2) < 0x100, 0x599);
            levelF = (f32)level;
            growthF = (f32)DAT_007ce420[(u32)*(u16*)(persona_i + 2) * 0xe + 3];

            if (FUN_0017d800() == 0)
            {
                result = (s32)(((DAT_007caed8 + 0.0f) -
                                DAT_007caed4 * growthF) *
                               (DAT_007cada8 * levelF * levelF * levelF) + 10.0f);
            }
            else
            {
                result = (s32)((2.5f - DAT_007caedc * growthF) *
                               (DAT_007cada8 * levelF * levelF * levelF) + 10.0f);
            }
        }
        else
        {
            s32 scenarioLevel;

            K_ASSERT((*(u16*)(persona_i + 2) >= 0xc0) &&
                     (*(u16*)(persona_i + 2) <= 0xdf), 0x5a4);
            scenarioLevel =
                *(u16*)((u32)*(u16*)(persona_i + 2) * 0x26e +
                         DAT_007ce430 - 0x1d280);
            K_ASSERT(scenarioLevel > 1 && scenarioLevel < 0xb, 0x5a6);
            result = *(s32*)((u32)scenarioLevel * 0x188 + DAT_007ce434 +
                             (u32)(level & 0xffff) * 4 - 0x318);
        }
    }

    return result;
}
// FUN_001764b0
void datPersonaAddExp(DatPersonaWork* persona, s32 exp)
{
    K_ASSERT(exp >= 0, 1458);

    persona->nextExp += exp;
}

/* Removing this loses FUN_00176510 (MATCH nd0 -> MISMATCH nd76) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00176510
void datPersonaMoveValidSkillsOnTop(DatPersonaWork* persona)
{
    DatPersonaWork* persona_p = persona;
    s32 skillIdx;
    s32 nextSkillIdx;
    s32 maxSkills;

    K_ASSERT(persona_p != NULL, 1478);
    maxSkills = PERSONA_MAX_SKILLS;
    skillIdx = 0;
    nextSkillIdx = 0;
    while (skillIdx < maxSkills)
    {
        if (persona_p->skills[skillIdx] == SKILL_SLASH_ATTACK)
        {
            nextSkillIdx = skillIdx + 1;

            while (nextSkillIdx < maxSkills)
            {
                if (persona_p->skills[nextSkillIdx] != SKILL_SLASH_ATTACK)
                {
                    break;
                }
                nextSkillIdx++;
            }

            if (nextSkillIdx == maxSkills)
            {
                return;
            }
        }

        if (skillIdx != nextSkillIdx)
        {
            if (nextSkillIdx < maxSkills)
            {
                persona_p->skills[skillIdx] = persona_p->skills[nextSkillIdx];
            }
            else
            {
                persona_p->skills[skillIdx] = SKILL_SLASH_ATTACK;
            }
        }
        skillIdx++;
        nextSkillIdx++;
    }
}
#pragma opt_loop_invariants off

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

/* Removing this loses FUN_001768e0 (MATCH nd0 -> MISMATCH nd28) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001768e0
u8 datPersonaResetSkill(DatPersonaWork* persona, u16 skillId)
{
    u16 skillId_p = skillId;
    DatPersonaWork* personaWork = persona;
    s32 skillIdx;

    K_ASSERT(personaWork != NULL && skillId_p != SKILL_SLASH_ATTACK, 1560);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        if (personaWork->skills[skillIdx] == skillId)
        {
            personaWork->skills[skillIdx] = SKILL_SLASH_ATTACK;
            datPersonaMoveValidSkillsOnTop(personaWork);
            return true;
        }
    }

    return false;
}
#pragma opt_loop_invariants off

/* Removing this loses FUN_00176990 (MATCH nd0 -> MISMATCH nd25) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00176990
s32 datPersonaFindSkillIdx(DatPersonaWork* persona, u16 skillId)
{
    s32 skillIdx;

    K_ASSERT(persona != NULL && skillId != SKILL_SLASH_ATTACK, 1588);

    for (skillIdx = 0; skillIdx < PERSONA_MAX_SKILLS; skillIdx++)
    {
        if (persona->skills[skillIdx] == skillId)
        {
            return skillIdx;
        }
    }

    return -1;
}
#pragma opt_loop_invariants off

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

// FUN_00176600
u32 FUN_00176600(DatPersonaWork* persona)
{
    K_ASSERT(persona != NULL, 1497);

    if (persona->flags & PERSONA_FLAG_HEART_ITEM)
    {
        if (persona->flags & 8)
        {
            return 2;
        }
        return 1;
    }
    return 0;
}

// FUN_00176680
void FUN_00176680(DatPersonaWork* persona, u16 personaId)
{
    u8 statData[0x28];
    u8* personaData;
    u32 personaOffset;
    u32 statIdx;
    u8 level;
    u8* statBytes;
    u8* personaBytes;

    K_ASSERT(persona != NULL, 1515);
    K_ASSERT(personaId != 0 && personaId < 0x100, 1516);

    personaOffset = (u32)(u16)personaId * 0x0e;
    personaData = DAT_007ce420 + personaOffset;
    persona->id = personaId;
    persona->level = personaData[3];
    *((u8*)persona + 5) = personaData[9];
    *(u32*)((u8*)persona + 0x30) = 0;
    persona->nextExp = func_00176210_u16(persona, personaData[3]);
    *(u32*)((u8*)persona + 0x2c) = 0;
    memcpy(persona->naturalStats, DAT_007ce420 + personaOffset + 4, 5);
    memset(persona->bonusStats, 0, 5);
    memset(persona->stats3, 0, 5);
    memset(persona->skills, 0, 0x10);

    func_00175ce0(persona, statData);

    K_ASSERT(persona->id != 0 && persona->id < 0x100, 1362);
    level = persona->level;
    persona->level = level + statData[0];
    statIdx = 0;
    while ((s32)(statIdx & 0xffff) < PERSONA_STAT_MAX)
    {
        statBytes = statData + (u16)statIdx;
        personaBytes = (u8*)persona + (u16)statIdx;
        personaBytes[0x1c] += statBytes[0x22];
        statIdx = (statIdx + 1) & 0xffff;
    }

    FUN_00176da0(persona);
}

// FUN_00176ac0
u64 FUN_00176ac0(DatPersonaWork* persona, DatPersonaWork* const* personas, s32 personaCount)
{
    s32 totals[PERSONA_STAT_MAX * 2];
    s32* total_p;
    u8* stat_p;
    u8* stat_dest;
    s32 statIdx;
    s32 personaIdx;
    s32 statIdx2;
    s32 statDelta;
    u32 currentStat;

    K_ASSERT(persona != NULL && personas != NULL && personaCount != 0, 1671);
    FUN_00521408(totals, 0, 0x28);

    for (statIdx = 0; statIdx < PERSONA_STAT_MAX; statIdx++)
    {
        personaIdx = 0;
        total_p = &totals[statIdx * 2];
        for (; personaIdx < personaCount; personaIdx++)
        {
            total_p[0] += personas[personaIdx]->bonusStats[statIdx];
            total_p[1] += (u8)personas[personaIdx]->stats3[statIdx];
        }
    }

    for (statIdx2 = 0; statIdx2 < PERSONA_STAT_MAX; statIdx2++)
    {
        total_p = &totals[statIdx2 * 2];
        statDelta = total_p[0] + total_p[1] / (u32)personaCount;
        K_ASSERT(persona != NULL && (u8)statIdx2 < PERSONA_STAT_MAX, 1623);
        stat_p = (u8*)persona + (u8)statIdx2;
        stat_dest = stat_p + 0x26;
        currentStat = stat_p[0x26];
        if (currentStat + statDelta < 100)
        {
            stat_dest[0] = (s8)(currentStat + (u8)statDelta);
        }
        else
        {
            stat_dest[0] = (s8)(currentStat + (u8)(0x63 - currentStat));
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

// FUN_00176da0
void FUN_00176da0(DatPersonaWork* persona)
{
    u16 personaId;
    u8* skillData;
    u16 skillId;
    s32 skillIdx;
    s32 skillSlotIdx;
    u16* skillSlot;
    u32 scenarioPersona;

    personaId = persona->id;
    if (personaId >= 0xc0 && personaId <= 0xdf)
    {
        scenarioPersona = 1;
    }
    else
    {
        scenarioPersona = 0;
    }
    if (scenarioPersona)
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        for (skillIdx = 0; skillIdx < 0x20; skillIdx++)
        {
            if (skillData[skillIdx * 4] == 0 &&
                ((s8*)skillData)[skillIdx * 4 + 1] == 1)
            {
                skillId = *(u16*)(skillData + skillIdx * 4 + 2);
                K_ASSERT(persona != NULL && skillId != 0, 1546);
                for (skillSlotIdx = 0; skillSlotIdx < PERSONA_MAX_SKILLS; skillSlotIdx++)
                {
                    skillSlot = (u16*)((u8*)persona + skillSlotIdx * 2 + 0xc);
                    if (*skillSlot == SKILL_SLASH_ATTACK)
                    {
                        *skillSlot = skillId;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        for (skillIdx = 0; skillIdx < 0x10; skillIdx++)
        {
            if (skillData[skillIdx * 4] == 0 &&
                ((s8*)skillData)[skillIdx * 4 + 1] == 1)
            {
                skillId = *(u16*)(skillData + skillIdx * 4 + 2);
                K_ASSERT(persona != NULL && skillId != 0, 1546);
                for (skillSlotIdx = 0; skillSlotIdx < PERSONA_MAX_SKILLS; skillSlotIdx++)
                {
                    skillSlot = (u16*)((u8*)persona + skillSlotIdx * 2 + 0xc);
                    if (*skillSlot == SKILL_SLASH_ATTACK)
                    {
                        *skillSlot = skillId;
                        break;
                    }
                }
            }
        }
    }
}

/* Removing this loses FUN_00176fb0 (MATCH nd0 -> MISMATCH nd62) - measured W161. */
#pragma opt_loop_invariants on
static inline void datPersonaCollectValidSkills(u8* skillData, u16* skills,
                                                s32* validSkills, s32 skillLimit)
{
    s32 skillIdx;

    for (skillIdx = 0; skillIdx < skillLimit; skillIdx++)
    {
        if (skillData[skillIdx * 4] == 0 &&
            ((s8*)skillData)[skillIdx * 4 + 1] == 1)
        {
            skills[*validSkills] = *(u16*)(skillData + skillIdx * 4 + 2);
            (*validSkills)++;
        }
    }
}

// FUN_00176FB0
void FUN_00176FB0(u16 personaId, u16* skills, s32* skillCount)
{
    u8* skillData;
    s32 validSkills;

    validSkills = 0;
    if (personaId >= 0xc0 && personaId <= 0xdf)
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        datPersonaCollectValidSkills(skillData, skills, &validSkills, 0x20);
    }
    else
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        datPersonaCollectValidSkills(skillData, skills, &validSkills, 0x10);
    }

    *skillCount = validSkills;
}
#pragma opt_loop_invariants off

/* Removing this loses FUN_001770d0 (MATCH nd0 -> MISMATCH nd84) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001770D0 MATCHING
s32 FUN_001770D0(u16 personaId, u16 skillId)
{
    u8* skillData;
    s32 skillIdx;
    s32 skillOffset;
    s32 skillOrder;

    skillOrder = 0;
    if (personaId >= 0xc0 && personaId <= 0xdf)
    {
        skillData = DAT_007ce430 + (personaId - 0xc0) * 0x26e + 4;
        for (skillIdx = 0; skillIdx < 0x20; skillIdx++)
        {
            if (skillData[skillIdx * 4] != 0 &&
                ((s8*)skillData)[skillIdx * 4 + 1] == 1)
            {
                if ((u16)skillId == *(u16*)(skillData + skillIdx * 4 + 2))
                {
                    break;
                }
                skillOrder++;
            }
        }

        if (skillIdx >= 0x10)
        {
            goto firstAssert;
        }
        skillOffset = skillIdx * 4;
        if (*(s8*)(skillOffset + (u32)skillData + 1) == 1)
        {
            goto firstAssertDone;
        }
firstAssert:
        K_Assert(__FILE__, 1829);
firstAssertDone:
        ;
    }
    else
    {
        skillData = DAT_007ce428 + (u32)personaId * 0x46 + 6;
        for (skillIdx = 0; skillIdx < 0x10; skillIdx++)
        {
            if (skillData[skillIdx * 4] != 0 &&
                ((s8*)skillData)[skillIdx * 4 + 1] == 1)
            {
                if ((u16)skillId == *(u16*)(skillData + skillIdx * 4 + 2))
                {
                    break;
                }
                skillOrder++;
            }
        }

        if (skillIdx >= 0x10)
        {
            goto secondAssert;
        }
        skillOffset = skillIdx * 4;
        if (*(s8*)(skillOffset + (u32)skillData + 1) == 1)
        {
            goto secondAssertDone;
        }
secondAssert:
        K_Assert(__FILE__, 1848);
secondAssertDone:
        ;
    }

    return skillOrder;
}
#pragma opt_loop_invariants off

// FUN_00177270
void FUN_00177270(void)
{
    return;
}
