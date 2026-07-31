#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "temporary.h"
#include "Kosaka/k_assert.h"

#pragma alias FUN_00175ca0_y2 FUN_00175ca0



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

// FUN_00175ca0_y2
s32 FUN_00175ca0_y2(DatPersonaWork* persona)
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
#pragma opt_loop_invariants reset

// FUN_00177270
void FUN_00177270(void)
{
    return;
}


#include "Main/Battle/Data/datCalc.h"

#pragma alias func_001754a0_y2 func_001754a0_y2
#pragma alias FUN_00173280_y2 FUN_00173280_y2


/* GP-relative data pointers used by the retail Persona tables. */
extern u8* iGpffffb7f4;
extern u8* iGpffffb730;
extern u8* iGpffffb734;
extern u8* iGpffffb740;
extern u8* iGpffffb2e4;
extern u8 D_007FD6C8[];
extern u8 D_00833E80[];

extern void func_00306d90(s32 channel, u16 skillId);
extern s32 FUN_00175ca0(DatPersonaWork* persona);
extern s8 FUN_00173c60(DatPersonaWork* persona, u16 statId);

static inline void assertStat(u16 statId, s32 line)
{
    K_ASSERT(statId < PERSONA_STAT_MAX, line);
}

static inline s16 personaEquipmentBonus(u16 owner, s16 equipmentIdx, u16 statId)
{
    u16 itemId = 0;
    u8* itemTable = NULL;

    if (equipmentIdx < 0)
    {
        return 0;
    }
    if (owner == 0xFFFF)
    {
        itemId = *(u16*)(D_00833E80 + equipmentIdx * sizeof(DatEquipment));
    }
    else if (owner == 1)
    {
        itemId = gGlobalWork.heroEquip.equipments[equipmentIdx].id;
    }
    else if (owner < 0x100)
    {
        itemId = gPcs[owner].equipments[equipmentIdx].id;
    }
    else
    {
        itemTable = D_007FD6C8 + owner * sizeof(DatPc);
        itemId = *(u16*)(itemTable + equipmentIdx * sizeof(DatEquipment));
    }

    if (itemId < 3000 || itemId > 3999)
    {
        return 0;
    }

    itemTable = iGpffffb2e4 + (itemId - 3000) * 0x24;
    return *(s16*)(itemTable + 4 + statId * 2);
}

static inline u16 personaEquipmentOwner(DatPersonaWork* persona)
{
    u16 owner;

    if (FUN_00175ca0(persona) == 0)
    {
        return 1;
    }

    owner = persona->id;
    K_ASSERT(owner >= 0xC0 && owner <= 0xDF, 0x234);
    return *(u16*)(iGpffffb740 + owner * 0x26E - 0x1D280);
}

static inline s16 personaEquipmentIndex(u16 owner)
{
    if (owner == 1)
    {
        return gGlobalWork.heroEquip.equipmentsIdx[3];
    }
    if (owner < PC_MAX)
    {
        return gPcs[owner].equipmentsIdx[3];
    }
    return -1;
}

static inline s16 personaEquipmentEffects(u16 owner, u16 statId)
{
    s16 total = 0;

    switch (statId)
    {
    case 0:
        total += datCalcCountEquipmentWithEffectById(owner, 0);
        total += datCalcCountEquipmentWithEffectById(owner, 2) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 3) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 4) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 5) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x83) * 10;
        break;
    case 1:
        total += datCalcCountEquipmentWithEffectById(owner, 0xB);
        total += datCalcCountEquipmentWithEffectById(owner, 0xC) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0xD) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0xE) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0xF) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x85) * 10;
        break;
    case 2:
        total += datCalcCountEquipmentWithEffectById(owner, 6);
        total += datCalcCountEquipmentWithEffectById(owner, 7) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 8) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 9) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0xA) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x84) * 10;
        break;
    case 3:
        total += datCalcCountEquipmentWithEffectById(owner, 0x10);
        total += datCalcCountEquipmentWithEffectById(owner, 0x11) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0x12) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0x13) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0x14) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x86) * 10;
        break;
    case 4:
        total += datCalcCountEquipmentWithEffectById(owner, 0x15);
        total += datCalcCountEquipmentWithEffectById(owner, 0x16) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0x17) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0x18) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0x19) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x87) * 10;
        break;
    }

    total += datCalcCountEquipmentWithEffectById(owner, 0x88);
    total += datCalcCountEquipmentWithEffectById(owner, 0x89) * 2;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8A) * 3;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8B) * 4;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8C) * 5;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8D) * 10;
    return total;
}

// FUN_00173220
u8* FUN_00173220(s32 personaId)
{
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x18);
    id = personaId;
    return iGpffffb7f4 + id * 0x11;
}

// FUN_00173280
u8 FUN_00173280(s32 personaId)
{
    u8* table;
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x26);
    table = iGpffffb730;
    id = personaId;
    return table[id * 0xE + 2];
}

/* Removing this loses FUN_001733b0 (MATCH nd0 -> MISMATCH nd37) - measured W161. */
#pragma optimization_level 1
// FUN_001733B0
void FUN_001733b0(DatPersonaWork* persona, s32 skillIdx)
{
    K_ASSERT(persona->id < 0x100, 0x115);
    K_ASSERT((u16)skillIdx < 0x10, 0x116);
    {
        u8* skillTable = iGpffffb734 + persona->id * 0x20;
        func_00306d90(0, *(u16*)(skillTable + (u16)skillIdx * 2));
    }
}
#pragma optimization_level 2
// FUN_00173460
void FUN_00173460(u16 pcId, s32 skillIdx)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    K_ASSERT(persona->id < 0x100, 0x115);
    K_ASSERT((u16)skillIdx < 0x10, 0x116);
    func_00306d90(0, ((struct { u16 skills[0x10]; }*)iGpffffb734)[persona->id].skills[(u16)skillIdx]);
}

// FUN_00173510
u8 FUN_00173510(u16 pcId, u16 statId)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    return persona->naturalStats[statId];
}

// FUN_00173660
u8 FUN_00173660(DatPersonaWork* persona, u16 statId)
{
    s16 natural;
    s16 bonus;
    s16 third;
    s16 total;
    s8 equipment;

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    natural = persona->naturalStats[statId];
    bonus = datPersonaGetBonusStat(persona, statId);
    third = datPersonaGetStat3(persona, statId);
    equipment = FUN_00173c60(persona, statId);
    total = natural + bonus + third + equipment;
    if (total > 99)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_00173780
u8 FUN_00173780(u16 heroPersonaIdx, u16 statId)
{
    DatPersonaWork* persona;
    s16 natural;
    s16 bonus;
    s16 third;
    s16 total;
    s8 equipment;

    persona = datPersonaGetHeroPersona(heroPersonaIdx);
    K_ASSERT(persona != NULL, 0x192);
    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    natural = persona->naturalStats[statId];
    bonus = datPersonaGetBonusStat(persona, statId);
    third = datPersonaGetStat3(persona, statId);
    equipment = FUN_00173c60(persona, statId);
    total = natural + bonus + third + equipment;
    if (total > 99)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_001738D0
u8 FUN_001738d0(u16 pcId, u16 statId)
{
    DatPersonaWork* persona;
    s16 natural;
    s16 bonus;
    s16 third;
    s16 total;
    s8 equipment;

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    natural = persona->naturalStats[statId];
    bonus = datPersonaGetBonusStat(persona, statId);
    third = datPersonaGetStat3(persona, statId);
    equipment = FUN_00173c60(persona, statId);
    total = natural + bonus + third + equipment;
    if (total > 99)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_00173A00
s16 FUN_00173a00(DatPersonaWork* persona, u16 statId)
{
    s16 natural;
    s16 bonus;
    s8 third;
    s16 total;

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x1A7);
    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    natural = persona->naturalStats[statId];
    bonus = datPersonaGetBonusStat(persona, statId);
    third = datPersonaGetStat3(persona, statId);
    total = natural + bonus + third;
    if (total >= 99)
    {
        total = 99;
    }
    return total;
}

// FUN_00173C60 NONMATCHING
s8 FUN_00173c60(DatPersonaWork* persona, u16 statId)
{
    s16 total;
    s16 equipmentIdx;
    u16 owner;

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x22D);
    total = 0;
    if (FUN_00175ca0(persona) != 0)
    {
        owner = persona->id;
        K_ASSERT(owner >= 0xC0 && owner <= 0xDF, 0x234);
        owner = *(u16*)(iGpffffb740 + owner * 0x26E - 0x1D280);
    }
    else
    {
        owner = 1;
    }
    K_ASSERT(owner < 0xB, 0x239);
    if (owner == 1)
    {
        equipmentIdx = gGlobalWork.heroEquip.equipmentsIdx[3];
    }
    else if (owner < PC_MAX)
    {
        equipmentIdx = gPcs[owner].equipmentsIdx[3];
    }
    else
    {
        equipmentIdx = -1;
    }
    if (equipmentIdx >= 0)
    {
        u16 itemId = 0;
        u8* itemTable = NULL;

        if (owner == 0xFFFF)
        {
            itemId = *(u16*)(D_00833E80 + equipmentIdx * sizeof(DatEquipment));
        }
        else if (owner == 1)
        {
            itemId = gGlobalWork.heroEquip.equipments[equipmentIdx].id;
        }
        else if (owner < 0x100)
        {
            itemId = gPcs[owner].equipments[equipmentIdx].id;
        }
        else
        {
            itemTable = D_007FD6C8 + owner * sizeof(DatPc);
            itemId = *(u16*)(itemTable + equipmentIdx * sizeof(DatEquipment));
        }
        if (itemId >= 3000 && itemId <= 3999)
        {
            itemTable = iGpffffb2e4 + (itemId - 3000) * 0x24;
            switch (statId)
            {
            case 0:
                total += *(s16*)(itemTable + 4);
                break;
            case 1:
                total += *(s16*)(itemTable + 6);
                break;
            case 2:
                total += *(s16*)(itemTable + 8);
                break;
            case 3:
                total += *(s16*)(itemTable + 0xA);
                break;
            case 4:
                total += *(s16*)(itemTable + 0xC);
                break;
            }
        }
    }
    switch (statId)
    {
    case 0:
        total += datCalcCountEquipmentWithEffectById(owner, 0);
        total += datCalcCountEquipmentWithEffectById(owner, 2) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 3) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 4) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 5) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x83) * 10;
        break;
    case 1:
        total += datCalcCountEquipmentWithEffectById(owner, 0xB);
        total += datCalcCountEquipmentWithEffectById(owner, 0xC) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0xD) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0xE) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0xF) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x85) * 10;
        break;
    case 2:
        total += datCalcCountEquipmentWithEffectById(owner, 6);
        total += datCalcCountEquipmentWithEffectById(owner, 7) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 8) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 9) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0xA) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x84) * 10;
        break;
    case 3:
        total += datCalcCountEquipmentWithEffectById(owner, 0x10);
        total += datCalcCountEquipmentWithEffectById(owner, 0x11) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0x12) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0x13) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0x14) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x86) * 10;
        break;
    case 4:
        total += datCalcCountEquipmentWithEffectById(owner, 0x15);
        total += datCalcCountEquipmentWithEffectById(owner, 0x16) * 2;
        total += datCalcCountEquipmentWithEffectById(owner, 0x17) * 3;
        total += datCalcCountEquipmentWithEffectById(owner, 0x18) * 4;
        total += datCalcCountEquipmentWithEffectById(owner, 0x19) * 5;
        total += datCalcCountEquipmentWithEffectById(owner, 0x87) * 10;
        break;
    }
    total += datCalcCountEquipmentWithEffectById(owner, 0x88);
    total += datCalcCountEquipmentWithEffectById(owner, 0x89) * 2;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8A) * 3;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8B) * 4;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8C) * 5;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8D) * 10;
    return total;
}


#include "Script/scrTraceCode.h"
#include "datCalendar.h"

#pragma alias FUN_0019d3f0_y2 FUN_0019d3f0
#pragma alias FUN_00521250_y2 FUN_00521250
#pragma alias FUN_00523ac8_y2 FUN_00523ac8
#pragma alias scrGetIntPara_y2 scrGetIntPara


#define SOCIAL_LINK_COUNT 30
#define SOCIAL_DATA_POINTS_OFFSET 0xD2
#define SOCIAL_DATA_COUNTER_OFFSET 0xD6
extern u8* FUN_00172c50(s16* outValue);
extern s32 FUN_00172660(s32 socialLink);
extern void FUN_00172a20(u32 value);
extern u8 D_008364BC[];
extern s32 D_008364F4[];
extern s32 D_008365F4[];
extern u8 D_008366F4[];
extern u8 D_00836734[];
extern u8 D_00836752[];
extern s16 D_0083679C[];
extern u8 D_0083A34C[];
extern s32 func_003951d0(s32 resourceId);
extern void func_00395170(s32 resourceId);
extern void func_003951a0(s32 resourceId);
extern s16* func_003bddd0(void);
extern u8* func_003beb10(s32 socialLink);
extern void func_0017ad90(void);
extern void func_0017ac60(u32 packedData);
extern void func_001828d0(s16 itemId, void* itemData);
extern void func_001831e0(s16 pcId, s16 slot, const void* itemData);


// 005dc050
static const u32 sPlayerExpThreshold[MAX_CHARACTER_LEVEL] = 
{
    0, 20, 47, 99, 185, 312, 490, 726, 1030,
    1410, 1873, 2429, 3085, 3851, 4735, 5744, 6888, 8174,
    9612, 11210, 12975, 14917, 17043, 19363, 21885, 24616, 27566,
    30742, 34154, 37810, 41717, 45885, 50321, 55035, 60035, 65328,
    70924, 76830, 83056, 89610, 96499, 103733, 111319, 119267, 127585,
    136280, 145362, 154838, // ! 005dc110 !
};

static const s16 academicLevelThreshold[6] = { 0, 20, 80, 140, 200, 260 }; // 005e3068
static const s16 charmLevelThreshold[6] =    { 0, 15, 30, 45, 65, 80 };    // 005e3078
static const s16 courageLevelThreshold[6] =  { 0, 15, 30, 45, 65, 80 };    // 005e3088

// 005e4150
static const char* physicalConditionsString[13] = 
{
    "You recovered from your cold.",
    "Your cold is not gone yet...",
    "Your cold worsened because you're tired.",
    "You've caught a cold.",
    "You've become tired.",
    "You're not tired anymore.",
    "Your condition improved because you rested.",
    "Your condition has improved.",
    "You are no longer in great condition.",
    "You're still tired",
    "You're no longer sick because you rested.",
    "You're no longer tired because you rested.",
    "The medicine cured your illness."
};

static s16 sSavedPartyIds[4]; // 007cdfa8
static u32 sScenarioMode;     // 007cdfa4. See enum 'ScenarioMode'

DatGlobal gGlobalWork; // 00836200
DatPc gPcs[PC_MAX];    // 00833948

void func_00177410(u8*, u8*);
void func_001774e0(void);
extern const char D_005E3098[];
extern const char D_005E3260[];
extern u32 gSpecialStatusMessage;
extern u8 DAT_00833bb0[];
extern u8 DAT_00833bd0[];
extern u8 DAT_00833bf0[];
extern u8 DAT_00836200[];
#pragma alias DAT_00836200_u32 DAT_00836200
extern u32 DAT_00836200_u32;
extern u8 DAT_00836212[];
extern u8* PTR_s_Aigis_005e35ec;
extern u8* PTR_s_Aigis_005e379c;
extern u8* PTR_s_Aigis_005e37dc;
extern u8* PTR_s_Metis_005e3790;
extern u8* PTR_s_Metis_005e37d0;
extern u8* PTR_s_Metis_005e35e0;
extern u8* D_005E35E0[];
extern u8* D_005E35EC[];
extern u8* D_005E3790[];
extern u8* D_005E379C[];
extern u8* D_005E37D0[];
extern u8* D_005E37DC[];
extern u8 D_007FD6CC[];
extern u8 D_007FD6D0[];
extern u8 D_007FD6D1[];
extern u8 D_007FD6D2[];
extern u8 D_007FD6D4[];
extern u8 D_007FD6D6[];
extern u8 D_007FD6D8[];
extern u8 D_008339A4[];
extern u8 D_008339A8[];
extern u8 D_008339AC[];
extern u8 D_008339AD[];
extern u8 D_008339AE[];
extern u8 D_008339B0[];
extern u8 D_008339B2[];
extern u8 D_008339B4[];
extern u8 D_008339F4[];
extern u8 D_00834010[];
extern u8 D_00834120[];
extern u8 DAT_00830000_a[];
extern u8 DAT_00830000_b[];
extern u8 DAT_00830000_c[];
extern u8 D_007CBFA0;
extern u8 D_008339F6[];
extern u8 D_00833A78[];
extern u8 D_00833C58[];
extern u8 D_00833C5A[];
extern u8 D_00833E84[];
extern u8 D_00833E88[];
extern u8 D_00833E89[];
extern u8 D_00833E8A[];
extern u8 D_00833E8C[];
extern u8 D_00833E8E[];
extern u8 D_00833E90[];
extern u8 D_00836458[];
extern u8 D_00836498[];

extern void func_001754a0_y2(u32 value);

void FUN_00172890(void);
void FUN_00172e10(void);
extern u8 D_005DC1B4[];
extern s8 D_005E3220[];
extern s16 D_005E3240[];
extern u8 D_00831CE0[];
extern u8 D_007FD858[];
extern u8 D_007FD85A[];
extern u8 D_005DDDC0[];
extern u8 D_005DABF0[];
extern u8 D_005D6C70[];
extern u8 D_005D6C80[];
extern u8 D_005DE8E0[];
extern u8 D_005DE880[];
extern u8 D_005DE040[];
extern u8 D_00836773[];
extern u8* D_007CDFB4;
extern u8* D_007CDFBC;
extern u8* D_007CDFC0;
extern u8* D_007CDFC4;
extern u8* D_007CDFC8;
extern u8* D_007CDFCC;
extern u8* D_007CDFD0;
extern u8* D_007CDFD4;
extern u8* D_007CDFD8;
extern u8* D_007CDFDC;
extern u8* D_007CDFE4;

extern u16 func_00300100(DatUnit* unit);
extern u32 FUN_00173280_y2(u16 personaId);
extern void FUN_00171B50(s16 socialLink);
extern void FUN_00171C40(s16 socialLink, s32 value);
extern void FUN_00171E90(s16 socialLink, s32 value);
extern void FUN_00172200(s32 socialLink, s32 value);
#pragma alias FUN_00172200_s16 FUN_00172200
extern void FUN_00172200_s16(s16 socialLink, s32 value);
extern void FUN_001723A0(s16 socialLink, s32 rank, s32 enabled);
extern void FUN_001724A0(s16 socialLink, s32 rank, s32 enabled);
extern f32 FUN_003BDB80(void);
extern u8* FUN_003BDD90();
extern u32 FUN_00488F30(void);
extern void FUN_005225A8();
extern s16 func_00171060(s16 id);

u16 func_0016cc00(s16 pcId);
u16 func_0016ccb0(s16 pcId);
u8 func_0016d280(s32 exp);
u32 func_0016dce0(s16 socialLink);
s8 func_0016dd20(s16 socialLink);
void func_0016ddd0(s32 index);
u8 func_0016de50(s32 index);
s16 func_0016deb0(s16 arcana);
void func_0016dfb0(s16 socialLink);
s16 func_0016e190(s32 socialLink);
void func_0016e2b0(s16 socialLink, s32 amount);
void func_0016e410(s16 socialLink, s8 level);
void func_0016e5f0(s32 socialLink, s8 progress);
#pragma alias func_0016e5f0_call func_0016e5f0
extern void func_0016e5f0_call(s16 socialLink, s8 progress);
void func_0016e670(s16 socialLink);
void func_0016e7a0(s16 socialLink, s16 day);
s16 func_0016e850(s16 socialLink);
s32 func_0016ea40(s32 amount);
u32 func_0016ea80(void);
u32 func_0016ecd0(void);
u8* func_00170620(s16 pcId, s16 index);
u16 func_00170670(s16 pcId, s16 index);
s16 func_001706c0(s16 pcId, s16 index);
void func_00170710(s16 pcId, s16 index, u16 value);
u16 func_00170a40(s16 pcId, s16 index);
s16 func_00170ab0(s16 pcId, s16 index);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
u32 func_00170c00(s16 pcId, s16 index, s16 delta);
void* func_00170d60(s16 id);
void* func_00170da0(s16 id);
void* func_00170df0(s16 id);
void* func_00170e40(s16 id);
u32 func_00171250(s16 id);
u16 func_001712d0(s16 id);
void func_00171390(u32 flag);
s32 func_001714b0(s32 index);
s32 func_001714d0(s32 index);
s32 func_001714f0(s32 index);
f32 func_00171510(s16 row, s16 column);
u8 func_00171550(s16 unused1, s16 unused2, u16 index);
u32 func_001715f0(s16 id);






static inline u8 datGetLevel_impl(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetLevel(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];
    return datCalcGetLevel(&pc[pcId - 2].unit);
}










static inline u32 datGetNextExp_impl(s16 pcId)
{
    DatPersonaWork* persona;

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.nextExp;
    }

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(persona != NULL, 622);
    return datPersonaGetNextExp(persona);
}

static inline u8 func_0016d280_impl(s32 exp)
{
    u8 index;
    u8 level;
    const u32* thresholds;

    level = 0;
    index = 0;
    thresholds = sPlayerExpThreshold;
    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)thresholds[index])
        {
            return level;
        }
        level++;
        index++;
    }
    return MAX_CHARACTER_LEVEL;
}



















/* W357 measured optimization_level 1: without nd8/object96 (MISMATCH), with nd0/object96 (MATCH); retained. */


























































/* Removing this loses FUN_0016d280 (MATCH nd0 -> MISMATCH nd19) - measured W161. */




/* Removing this loses FUN_0016deb0 (MATCH nd0 -> MISMATCH nd47) - measured W161. */








/* Removing this loses FUN_0016ea80 (MATCH nd0 -> MISMATCH nd18) - measured W161. */





static inline u16 func_00170760_impl(s16 pcId, s16 index)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;

    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this inline-helper qualifier loses func_00170c00 (MATCH nd0 -> MISMATCH nd15, size 348 -> 348) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        return *(u16*)(address - 8000);
    }
    if (pcId == -1)
    {
        return *(u16*)(D_00831CE0 + index * 2);
    }
    if (pcId < 0x100)
    {
        goto invalid;
    }

    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            return *(u16*)(D_007FD85A + pcId * 0x364 + i * 4);
        }
    }
    return 0;
invalid:
    return 0;
}









static inline void* func_00170d60_impl(s16 id)
{
    if (id < 1000)
    {
        return D_007CDFE4 + id * 0x28;
    }
    return NULL;
}

static inline void* func_00170da0_impl(s16 id)
{
    if (id >= 1000 && id < 2000)
    {
        return D_007CDFDC + (id - 1000) * 0x20;
    }
    return NULL;
}

static inline void* func_00170df0_impl(s16 id)
{
    if (id >= 2000 && id < 3000)
    {
        return D_007CDFD8 + (id - 2000) * 0x20;
    }
    return NULL;
}

static inline void* func_00170e40_impl(s16 id)
{
    if (id >= 3000 && id < 4000)
    {
        return D_007CDFD4 + (id - 3000) * 0x24;
    }
    return NULL;
}

static inline void* func_00170e90_impl(s16 id)
{
    if (id >= 3000)
    {
        return D_007CDFCC + (id - 4000) * 0x1c;
    }
    return NULL;
}

static inline void* func_00170ed0_impl(s16 id, s32* category)
{
    if (id < 1000)
    {
        *category = 0;
        return func_00170d60_impl(id);
    }
    if (id < 2000)
    {
        *category = 1;
        return func_00170da0_impl(id);
    }
    if (id < 3000)
    {
        *category = 2;
        return func_00170df0_impl(id);
    }
    if (id < 4000)
    {
        *category = 3;
        return func_00170e40_impl(id);
    }

    *category = 4;
    return func_00170e90_impl(id);
}



















#pragma alias datIncrementSocialLinkCounter FUN_001718b0

#pragma alias datDecreaseSocialLinkPoints FUN_00171960

#pragma alias datGetSocialLinkPoints FUN_00171ac0

#pragma alias datResetSocialLinkPoints FUN_00171b50


#pragma alias datSetSocialLinkCounter FUN_00171e90





#pragma alias datSetSocialLinkRankUnlocked FUN_001723a0

#pragma alias datSetSocialLinkRankAcknowledged FUN_001724a0

#pragma alias datApplyPendingSocialLinkRank FUN_001725a0

#pragma alias datSocialLinkHasPendingRank FUN_00172660

#pragma alias datSocialEventRecordHasData FUN_00172750



/* W357 measured optimization_level 0: without nd10/object24 (MISMATCH), with nd0/object44 (MATCH); window 48; retained. */




#pragma alias datGetSocialEventData FUN_00172990

#pragma alias datSocialEventDataIsLoaded FUN_001729a0

#pragma alias datTryGetSocialEventValue FUN_001729d0


#pragma alias datSetSocialEventMode FUN_00172a20

#pragma alias datSocialEventModeIsActive FUN_00172a30

#pragma alias datSocialLinkUsesRelationshipTable FUN_00172a50






#pragma alias datRecordSocialLinkDate FUN_00172cc0

#pragma alias datGetSocialLinksForToday FUN_00172d70

























// FUN_00175be0
void datInitPersona(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroPersona.equippedPersona = -1;
        memset(gGlobalWork.heroPersona.personas, 0, sizeof(gGlobalWork.heroPersona.personas));

        return;
    }

    pc = &gPcs[2];

    memset(&pc[pcId - 2].persona, 0, sizeof(DatPersonaWork));
}

// FUN_00175c70
void datCompendiumInit()
{
    memset(gGlobalWork.compendium, 0, sizeof(gGlobalWork.compendium));
}


/* Removing this loses FUN_00177280 (MATCH nd0 -> MISMATCH nd26) and 2 more - measured W161. */
#pragma opt_loop_invariants on
// FUN_00177280
s16 datGetAcademicLevel(s16 academicPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (academicLevelThreshold[idx] <= academicPoint)
        {
            return idx + 1;
        }
    }
}

// FUN_001772f0
s16 datGetCharmLevel(s16 charmPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (charmLevelThreshold[idx] <= charmPoint)
        {
            return idx + 1;
        }
    }
}

// FUN_00177360
s16 datGetCourageLevel(s16 couragePoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (courageLevelThreshold[idx] <= couragePoint)
        {
            return idx + 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_001773D0
void func_001773d0(void)
{
    DAT_00830000_a[0x3bb0] = 0;
    DAT_00830000_b[0x3bd0] = 0;
    DAT_00830000_c[0x3bf0] = 0;
    func_00177410(&D_007CBFA0, &D_007CBFA0);
}
/* Removing this loses FUN_00177410 (MATCH nd0 -> MISMATCH nd89) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00177410
void func_00177410(u8* param_1,u8* param_2)
{
    extern void FUN_00521408(void*, s32, u32);
    s32 index;
    s8 value;

    FUN_00521408(&gGlobalWork, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_1 + index);
        if (value == '\0')
        {
            break;
        }
        ((u8*)&gGlobalWork)[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_2 + index);
        if (value == '\0')
        {
            break;
        }
        ((u8*)&gGlobalWork)[index + 0x12] = value;
    }

    func_001774e0();
}
#pragma opt_loop_invariants off
// FUN_001774E0


void func_001774e0(void)



{

  FUN_00521408(DAT_00833bb0, 0, 0x12);

  FUN_00521408(DAT_00833bd0, 0, 0x12);

  FUN_00521408(DAT_00833bf0, 0, 0x24);

  FUN_00521250_y2(DAT_00833bb0, &gGlobalWork, 0x12);

  FUN_00521250_y2(DAT_00833bd0, DAT_00836212, 0x12);

  FUN_00523ac8(DAT_00833bf0, &DAT_00836200_u32, DAT_00833bd0, DAT_00833bb0);

  return;

}
// FUN_001775A0


u8* func_001775a0(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            result = DAT_00833bf0;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E35EC[0];
        }
        else if (param_1 == 9)
        {
            result = D_005E35E0[0];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_00177670


u8* func_00177670(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            return DAT_00833bb0;
        }
        else if (param_1 < 0xb)
        {
            result = D_005E3790[param_1];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E379C[0];
        }
        else if (param_1 < 0xb)
        {
            if (param_1 == 9)
            {
                result = D_005E3790[0];
            }
            else
            {
                result = D_005E3790[param_1];
            }
            return result;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_00177790


u8* func_00177790(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            return DAT_00833bd0;
        }
        else if (param_1 < 0xb)
        {
            result = D_005E37D0[param_1];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E37DC[0];
        }
        else if (param_1 < 0xb)
        {
            if (param_1 == 9)
            {
                result = D_005E37D0[0];
            }
            else
            {
                result = D_005E37D0[param_1];
            }
            return result;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_001778B0


u8* func_001778b0(s16 param_1)
{
    u8* result;

    switch (param_1)
    {
    case 1:
        result = func_00177790(param_1);
        break;
    case 2:
        result = func_00177790(param_1);
        break;
    case 3:
        result = func_00177670(param_1);
        break;
    case 4:
        result = func_00177790(param_1);
        break;
    case 5:
        result = func_00177790(param_1);
        break;
    case 6:
        result = func_00177790(param_1);
        break;
    case 7:
        result = func_00177790(param_1);
        break;
    case 8:
        result = func_00177790(param_1);
        break;
    case 9:
        result = func_00177790(param_1);
        break;
    case 10:
        result = func_00177670(param_1);
        break;
    default:
        result = func_00177670(param_1);
        break;
    }
    return result;
}


/* Removing this worsens FUN_001779a0 (nd14 -> nd121) - measured W161. */
/* W389 classification: register-colouring/loop-index allocation floor; six singles and all 15 knob pairs were neutral, declaration-order trial nd19 vs baseline nd14. */
// FUN_001779A0 NONMATCHING
#pragma opt_loop_invariants on
void func_001779a0(void)
{
    s32 valueSlot;
    s32 slot;
    s32 pcIndex;

    for (pcIndex = 0; pcIndex < 10; pcIndex++)
    {
        for (slot = 0; slot < 4; slot++)
        {
            *(u16*)(D_00834010 + pcIndex * sizeof(DatPc) + slot * 0x14 + 0x130) = 0;
        }
        for (valueSlot = 0; valueSlot < 4; valueSlot++)
        {
            *(u32*)(D_00834010 + pcIndex * sizeof(DatPc) + valueSlot * 4 + 0x110) = 0;
        }
    }
}
#pragma opt_loop_invariants reset
// FUN_00177A40
u8 func_00177a40(u32 param_1,int param_2)



{

  return *(u16 *)(D_00833A78 + (param_1 & 0xffff) * sizeof(DatPc) + param_2 * 0x14) != 0;

}




void FUN_00300af0();



void FUN_00403130();


void FUN_00403220();



void FUN_0017d700(s32 param_1, s32 param_2, void *param_3);


void FUN_003d74b0();





/* Camp/data bridge functions at retail 0x001675B0-0x0016C2F0. */
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "h_snd.h"
#include "Utils.h"

typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef int bool;
typedef unsigned long ulong;
typedef struct CampFloatPair
{
    f32 x;
    f32 y;
} CampFloatPair;
typedef struct CampHelpPaths
{
    const char* paths[8];
} CampHelpPaths;
#define CAMP_PTR64(value) ((undefined8)(uintptr_t)(value))

/* Retail globals shared by the Camp bridge state machines. */
extern void (*DAT_0096017c[])(...);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(...);
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
#pragma alias scrGetIntPara_u64 scrGetIntPara_y2
extern u64 scrGetIntPara_u64(s32);
extern void* (*DAT_00960184)();
extern void* (*DAT_00960178)();
#pragma alias DAT_00960178_abs DAT_00960178
extern void* (*DAT_00960178_abs[])(...);
extern f32 DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern void* DAT_007cdf48;
extern void* DAT_007cdf54;
extern void* DAT_007cdf58;
extern void* DAT_007cdf84;
extern void* DAT_007cdf88;
extern s32 DAT_007e094e;
extern s32 DAT_007e0958;
/* Retail accesses these flag words by absolute address. */
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
#pragma alias DAT_007e0958_abs DAT_007e0958
extern u8 DAT_007e0958_abs[];
extern u32 DAT_00833a50[];
extern s32 iGpffffb258;
extern s32 uGpffffb290;
extern s32 uGpffffb28c;
extern s32 iGpffffb28c;

/* Data bridge globals initialized by FUN_0016C010/FUN_0016C2F0. */
typedef struct CampDataBridgeRoot CampDataBridgeRoot;
extern CampDataBridgeRoot* iGpffffb2c0;
#define DAT_007cdfb0 iGpffffb2c0
extern s32* DAT_007cdfb4;
extern s32* DAT_007cdfb8;
extern s32* DAT_007cdfbc;
extern s32* DAT_007cdfc0;
extern s32* DAT_007cdfc4;
extern s32* DAT_007cdfc8;
extern s32* DAT_007cdfcc;
extern s32* DAT_007cdfd0;
extern s32* DAT_007cdfd4;
extern s32* DAT_007cdfd8;
extern s32* DAT_007cdfdc;
extern u8* DAT_007cdfe0;
extern u8* DAT_007cdfe4;
extern void* DAT_007cdfe8;
extern u32 DAT_0083bb30[];
extern u8 DAT_0083bb40;
extern u32 DAT_0083aaa0[0x23];
extern const char* PTR_s_help_datWeaponHelp_bmd_005e31d0[8];
extern char DAT_005dc020[];
extern char DAT_005dbc60[];
extern const void* gp0xffff897c;
extern const void* gp0xffff8998;

/* Unresolved retail helpers. Old-style declarations preserve the mixed-width
 * call ABI recovered from the stripped executable. */
extern u32 FUN_00100d80();
extern u32 FUN_00100ec0();
extern u32 FUN_001016b0();
extern u64 FUN_00102100();
extern u32 FUN_001021c0();
extern u32 FUN_001023a0();
extern u32 FUN_0010a4e0();
extern u32 FUN_00111cb0();
extern u32 FUN_00111d50();
extern u32 FUN_00111dd0();
extern u32 FUN_00111ec0();
extern u32 FUN_00111ee0();
extern u32 FUN_00111f20();
extern u32 FUN_00111f30();
extern u32 FUN_00112420();
extern u32 FUN_001124b0();
extern void FUN_00113a30(f32 depth, f32 x, f32 y, u32 color, s32 width, s32 height);
#pragma alias FUN_00113a30_camp_reordered FUN_00113a30
extern void FUN_00113a30_camp_reordered(u32 color, f32 depth, f32 x,
                                        f32 y, s32 width, s32 height);
extern u32 FUN_00114450();
#pragma alias campDataDrawPersonaSprite FUN_00114450
extern void campDataDrawPersonaSprite(f32 alpha, f32 slidePosition, f32 depth,
                                      s32 mode, u32 color, u32 width,
                                      u32 height, void* resource);
extern void FUN_001159f0(f32 x, f32 y, ...);
#pragma alias FUN_001159f0_typed FUN_001159f0
extern void FUN_001159f0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                f32 x, f32 y, f32 depth);
extern u32 FUN_00115bc0();
#pragma alias FUN_00115bc0_typed FUN_00115bc0
extern void FUN_00115bc0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                u32 red, u32 green, u32 blue, f32 x, f32 y,
                                f32 depth);
#pragma alias campDataDrawSpriteDirect FUN_001159f0
extern void campDataDrawSpriteDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawSpriteAltDirect FUN_00115bc0
extern void campDataDrawSpriteAltDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawDigitsDirect FUN_00115de0
extern void campDataDrawDigitsDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawSpriteFade FUN_001159f0
extern void campDataDrawSpriteFade(f32 x, f32 y, f32 depth,
                                   void* atlas, s32 tile, s32 alpha);
#pragma alias campDataDrawSpriteAltFade FUN_00115bc0
extern void campDataDrawSpriteAltFade(f32 x, f32 y, f32 depth,
                                      void* atlas, s32 tile, s32 alpha,
                                      s32 red, s32 green, s32 blue, s32 flags);
extern u32 FUN_00115de0();
extern u32 FUN_00119f10();
#pragma alias campDataCreateTask FUN_00119f10
extern void* campDataCreateTask(void* task, s32 mode);
extern u32 FUN_0011abd0();
extern u32 FUN_00122710();
extern u32 FUN_0012a560(f32, RwV2d, void*, s32);
extern u32 FUN_0012ac60(f32, RwV2d, void*, s32);
extern u32 FUN_00129b30(f32, RwV2d, void*, s32);
extern u32 FUN_0013c240();
extern u32 FUN_0013c780();
extern u32 FUN_0013cf80();
extern u32 FUN_0013d1a0();
extern u32 FUN_0013fca0();
#pragma alias campDataDrawEquipment FUN_0013d1a0
extern void campDataDrawEquipment(f32 depth, CampFloatPair position,
                                  void* work, s32 alpha);
#pragma alias campDataDrawEquipmentAlt FUN_0013fca0
extern void campDataDrawEquipmentAlt(f32 depth, CampFloatPair position,
                                     void* work, s32 alpha);
extern u32 FUN_0016f630();
extern u32 FUN_0016f720();
extern u32 FUN_0016f810();
extern u32 FUN_0016f900();
extern u32 FUN_0016f9f0();
extern u32 FUN_0016fae0();
extern u32 FUN_0016fbd0();
extern u32 FUN_0016fcc0();
extern u32 FUN_0016fea0();
extern u32 FUN_0016ff90();
extern u32 FUN_00170080();
extern u32 FUN_00170170();
extern u32 FUN_00170260();
extern u32 FUN_00170350();
extern u32 FUN_00170440();
extern u32 FUN_00170530();
extern u32 FUN_00170a40();
extern u32 FUN_00170ab0();
extern u32 FUN_00170b20();
extern u32 FUN_00170b90();
extern u32 FUN_00174800();
extern u32 FUN_00177c10();
extern u32 FUN_001830c0();
extern u32 FUN_00194b20();
extern u32 FUN_00195290();
extern void FUN_0019d3f0(const char*, s32);
extern f32 FUN_0021ea00(s32);
extern KwlnTask* FUN_0025f370(KwlnTask* parent, void* battle_data);
extern u32 FUN_0025f570();
extern u32 FUN_0035ed20();
extern u32 FUN_003b2cb0();
#pragma alias campDataDrawTextRaw FUN_003b2cb0
extern s32 campDataDrawTextRaw(f32 scale, s32 x, s32 y, s32 color,
                               s32 font, s32 alignment, const char* text,
                               s32 maxWidth, s32 shadow);
extern u32 FUN_003c7430();
extern u32 FUN_003c74e0();
extern u32 FUN_003c7560();
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();
extern u32 FUN_003c7d80();
extern u32 FUN_003c7e20();
#pragma alias campDataDrawDigits FUN_003c7e20
extern void campDataDrawDigits(f32 depth, s32 x, s32 y, s32 color,
                               s32 style, s32 font, s32 alignment, u32 value);
extern u32 FUN_0040eb50();
#pragma alias campDataDrawText FUN_0040eb50
extern s32 campDataDrawText(f32 scale, s32 x, s32 y, u8 color, s16 font,
                            const char* text, s32 maxWidth);
extern u32 FUN_00521250();
extern u32 FUN_00523ac8_y2();

extern void* func_00133780(KwlnTask* task);
extern void* func_001618a0(KwlnTask* task);
extern void func_00161d60(KwlnTask* task);
extern void* func_00166c70(KwlnTask* task);
extern void h_campPersonaDestroyDispCtlDrawTask(KwlnTask* task);
extern const char D_005DAC70[];
extern const char D_005DAC90[];
extern const char D_005DB190[];
extern const char D_005DBD80[];
extern const char D_005DBED0[];
extern const char D_005DBEE8[];
extern const char D_005DBF00[];
extern const char D_005DBF20[];
extern const char D_005DBF40[];
extern const char D_005DBF70[];
extern const char D_005DBFA0[];
extern const char D_005DBFD0[];
/* These task archive names are addressed absolutely by retail. */
#pragma alias D_005DBF20_abs D_005DBF20
extern u8 D_005DBF20_abs[];
#pragma alias D_005DBF40_abs D_005DBF40
extern u8 D_005DBF40_abs[];
#pragma alias D_005DBF70_abs D_005DBF70
extern u8 D_005DBF70_abs[];
#pragma alias D_005DBFA0_abs D_005DBFA0
extern u8 D_005DBFA0_abs[];
#pragma alias D_005DBFD0_abs D_005DBFD0
extern u8 D_005DBFD0_abs[];
extern const char D_005DC000[];
extern const char D_005E30B0[];
extern const char D_005E31F0[];
extern const char D_005E3200[];

/* Target entry prototypes keep all callbacks visible before their first use. */
void FUN_001675b0(KwlnTask*);
void* FUN_001675e0(KwlnTask*);
void FUN_001678e0(KwlnTask*);
void* FUN_00167930(KwlnTask*);
void FUN_00167ec0(KwlnTask*);
void FUN_00167ef0(KwlnTask*);
void FUN_00167f10(KwlnTask*);
u32 FUN_00167f30(KwlnTask*);
KwlnTask* FUN_00167f40(KwlnTask*, u32, CampFloatPair, u16, u16, u16);
u32 FUN_00168040(void);
u32 FUN_00168100(void);
bool FUN_001681d0(void);
void* FUN_00168220(KwlnTask*);
bool FUN_001685b0(KwlnTask*);
u32 FUN_001685d0(KwlnTask*);
void FUN_001685e0(KwlnTask*, s32);
void FUN_00168720(KwlnTask*);
KwlnTask* FUN_00168770(KwlnTask*, u32);
u32 FUN_00168810(u32);
void FUN_00169040(int);
void FUN_00169110(u16, CampFloatPair, void*, s32);
void FUN_001691F0(u16, CampFloatPair, void*, void*, s32);
undefined4 FUN_00169330(void);
bool FUN_00169420(void);
undefined4 FUN_00169470(KwlnTask*);
void FUN_00169AE0(int);
void FUN_00169B90(void* resources, undefined8 coordinates,
                  void* list, s32 alpha, undefined8 stackArg);
undefined4 FUN_0016A030(void);
undefined4 FUN_0016A6A0(void);
f32 FUN_0016ba00(u32, u32);
f32 FUN_0016ba80(u32, u32);
f32 FUN_0016bb00(u32, u32);
f32 FUN_0016bb80(u32, u32);
f32 FUN_0016bc00(u32, u32);
void FUN_0016bc80(u32, u32, f32*);
void FUN_0016bdb0(u32, u32, f32*);
void FUN_0016bee0(u32, u32, void*);
void FUN_0016bf80(u32, u32, void*) __attribute__((aligned(16)));
void FUN_0016c010(void) __attribute__((aligned(16)));
void FUN_0016c1d0(void);
void FUN_0016c2f0(void);
void FUN_0016a700(f32 depth, void* resources, undefined8 coordinates,
                  void* list, s32 alpha);
void FUN_0016af90(f32 depth, void* resources, undefined8 coordinates,
                  void* list, s32 alpha);
#pragma alias campDataDrawListA FUN_0016A700
extern void campDataDrawListA(f32 depth, void* resources, RwV2d coordinates,
                              void* list, s32 alpha);
#pragma alias campDataDrawListB FUN_0016AF90
extern void campDataDrawListB(f32 depth, void* resources, RwV2d coordinates,
                              void* list, s32 alpha);


typedef struct CampBridgeScreenWork
{
    u32 state;          /* 0x00 */
    u32 timer;          /* 0x04 */
    u32 personaId;      /* 0x08 */
    u32 opacity;        /* 0x0c (low halfword used by the fade) */
    u32 fadeTimer;      /* 0x10 (low halfword used by the fade) */
    u32 command;        /* 0x14 */
    u32 active;         /* 0x18 */
    u32 transitionKind; /* 0x1c (low halfword used by the fade) */
    u32 reserved20;     /* 0x20 */
    u32 reserved24;     /* 0x24 */
    u32 childTask;      /* 0x28 */
} CampBridgeScreenWork;

/* Work area for the 0x14-byte state task (the first five words overlap the
 * screen work above but carry different meanings). */
typedef struct CampBridgeStateWork
{
    u32 state;          /* 0x00 */
    u32 mode;           /* 0x04 */
    u32 setupTask;      /* 0x08 */
    u32 activeTask;     /* 0x0c */
    u32 screenMode;     /* 0x10 */
} CampBridgeStateWork;

/* Work area allocated by FUN_00167930 for the persona display child. */
typedef struct CampBridgePersonaDispWork
{
    u32 state;          /* 0x00 */
    u32 personaId;      /* 0x04 */
    u32 reserved08;     /* 0x08 */
    u32 mode;           /* 0x0c */
    f32 alpha;          /* 0x10 */
    f32 slideStep;      /* 0x14 */
    f32 slidePosition;  /* 0x18 */
    f32 depth;          /* 0x1c */
    void* parseRequest; /* 0x20 */
    HCdvd* cdvd;        /* 0x24 */
    void* resource;     /* 0x28 */
} CampBridgePersonaDispWork;

/* Work area allocated by FUN_00168770 (0x1c bytes). */
typedef struct CampBridgeBlendWork
{
    u32 state;       /* 0x00 */
    s32 timer;       /* 0x04 */
    u32 reserved08;  /* 0x08 */
    u32 mode;        /* 0x0c */
    u32 archive;     /* 0x10 */
    u32 sourceTask;  /* 0x14 */
    u32 targetTask;  /* 0x18 */
} CampBridgeBlendWork;


/* Work area used by FUN_00168810/FUN_00169040. */
typedef struct CampTargetLoadWork
{
    u32 state;                 /* +0x00 */
    u32 reserved04;            /* +0x04 */
    s32 frame;                 /* +0x08 */
    u32 drawIdWord;            /* +0x0c (low half is the draw id) */
    void* archive;             /* +0x10 */
    void* resources[2];        /* +0x14 */
    CampTargetList* listA;     /* +0x1c */
    CampTargetList* listB;     /* +0x20 */
    void* childTask;           /* +0x24 */
} CampTargetLoadWork;

/* Work area used by FUN_00169470/FUN_00169AE0. */
typedef struct CampTargetMenuWork
{
    u32 state;                 /* +0x00 */
    s32 frame;                 /* +0x04 */
    u32 reserved08;            /* +0x08 */
    void* archive;             /* +0x0c */
    void* resources[2];        /* +0x10 */
    CampTargetList* list;      /* +0x18 */
    void* childTask;           /* +0x1c */
    u32 result;                /* +0x20 */
} CampTargetMenuWork;

typedef struct CampDataBridgeRecord
{
    s16 axis0;                 /* +0x00 */
    s16 axis1;                 /* +0x02 */
    s16 axis2;                 /* +0x04 */
    s16 axis3;                 /* +0x06 */
    f32 value;                 /* +0x08 */
    u32 reserved0c;            /* +0x0c */
    u16 reserved10;            /* +0x10 */
    s16 helpIndex;             /* +0x12 */
    u32 color0;                /* +0x14 */
    u32 color1;                /* +0x18 */
    u32 reserved1c;            /* +0x1c */
} CampDataBridgeRecord;

typedef struct CampDataBridgeGroup
{
    s32 recordCount;           /* +0x00 */
    s32 auxiliaryCount;        /* +0x04 */
    CampDataBridgeRecord* records; /* +0x08 */
    u8* auxiliaryData;         /* +0x0c */
} CampDataBridgeGroup;

typedef struct CampDataBridgeRoot
{
    CampDataBridgeGroup groups[2];
} CampDataBridgeRoot;






















/* opt_loop_invariants on: baseline nd1045/2096B -> on nd1038/2096B; retained. */

#pragma opt_loop_invariants reset




/* opt_loop_invariants on: baseline nd1082/1628B -> on nd1079/1628B; opt_propagation off nd1070/1600B; stacked nd1045/1596B; retained. */

#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* Existing lifetime/propagation scope: baseline nd555/812B; single probes nd552/812B and nd552/808B; stacked probe nd551/808B; retained. */

/* opt_lifetimes on and opt_propagation off are both active for this draw helper. */

#pragma opt_propagation reset
#pragma opt_lifetimes reset
/* opt_lifetimes on: baseline nd1098/1576B -> on nd1087/1576B; propagation off nd1093/1576B; stacked nd1099/1576B; lifetimes retained. */



/* opt_lifetimes on: baseline nd1526/2180B -> on nd1518/2180B; retained. */

/* opt_propagation off: baseline nd1935/2576B -> off nd1912/2464B; retained. */
