#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

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

static void assertStat(u16 statId, s32 line)
{
    K_ASSERT(statId < PERSONA_STAT_MAX, line);
}

static s8 personaEquipmentBonus(u16 owner, s16 equipmentIdx, u16 statId)
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

static u16 personaEquipmentOwner(DatPersonaWork* persona)
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

static s16 personaEquipmentIndex(u16 owner)
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

static s8 personaEquipmentEffects(u16 owner, u16 statId)
{
    static const u16 effects[PERSONA_STAT_MAX][6] = {
        { 0x00, 0x02, 0x03, 0x04, 0x05, 0x83 },
        { 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x85 },
        { 0x06, 0x07, 0x08, 0x09, 0x0A, 0x84 },
        { 0x10, 0x11, 0x12, 0x13, 0x14, 0x86 },
        { 0x15, 0x16, 0x17, 0x18, 0x19, 0x87 }
    };
    static const u8 weights[6] = { 1, 2, 3, 4, 5, 10 };
    s32 total = 0;
    s32 i;

    for (i = 0; i < 6; i++)
    {
        total += datCalcCountEquipmentWithEffectById(owner, effects[statId][i]) * weights[i];
    }
    total += datCalcCountEquipmentWithEffectById(owner, 0x88);
    total += datCalcCountEquipmentWithEffectById(owner, 0x89) * 2;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8A) * 3;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8B) * 4;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8C) * 5;
    total += datCalcCountEquipmentWithEffectById(owner, 0x8D) * 10;
    return (s8)total;
}

// FUN_00173220 NONMATCHING
u8* FUN_00173220(u16 personaId)
{
    K_ASSERT(personaId < 0x100, 0x18);
    return iGpffffb7f4 + personaId * 0x11;
}

// FUN_00173280 NONMATCHING
u8 FUN_00173280(u16 personaId)
{
    K_ASSERT(personaId < 0x100, 0x26);
    return *(u8*)(iGpffffb730 + personaId * 0xE + 2);
}

// FUN_001733B0 NONMATCHING
void FUN_001733b0(DatPersonaWork* persona, u16 skillIdx)
{
    K_ASSERT(persona->id < 0x100, 0x115);
    K_ASSERT(skillIdx < 0x10, 0x116);
    func_00306d90(0, *(u16*)(iGpffffb734 + persona->id * 0x20 + skillIdx * 2));
}

// FUN_00173460 NONMATCHING
void FUN_00173460(u16 pcId, u16 skillIdx)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    K_ASSERT(persona->id < 0x100, 0x115);
    K_ASSERT(skillIdx < 0x10, 0x116);
    func_00306d90(0, *(u16*)(iGpffffb734 + persona->id * 0x20 + skillIdx * 2));
}

// FUN_00173510
u8 FUN_00173510(u16 pcId, u16 statId)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x13C);
    return persona->naturalStats[statId];
}

// FUN_00173660 NONMATCHING
u8 FUN_00173660(DatPersonaWork* persona, u16 statId)
{
    s32 total;

    assertStat(statId, 0x13C);
    total = persona->naturalStats[statId] + datPersonaGetBonusStat(persona, statId) +
            datPersonaGetStat3(persona, statId) + FUN_00173c60(persona, statId);
    if (total >= 100)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_00173780 NONMATCHING
u8 FUN_00173780(u16 heroPersonaIdx, u16 statId)
{
    DatPersonaWork* persona = datPersonaGetHeroPersona(heroPersonaIdx);
    s32 total;

    K_ASSERT(persona != NULL, 0x192);
    assertStat(statId, 0x13C);
    total = persona->naturalStats[statId] + datPersonaGetBonusStat(persona, statId) +
            datPersonaGetStat3(persona, statId) + FUN_00173c60(persona, statId);
    if (total >= 100)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_001738D0 NONMATCHING
u8 FUN_001738d0(u16 pcId, u16 statId)
{
    DatPersonaWork* persona = datPersonaGetByPcId(pcId);
    s32 total;

    assertStat(statId, 0x13C);
    total = persona->naturalStats[statId] + datPersonaGetBonusStat(persona, statId) +
            datPersonaGetStat3(persona, statId) + FUN_00173c60(persona, statId);
    if (total >= 100)
    {
        total = 99;
    }
    else if (total < 0)
    {
        total = 0;
    }
    return (u8)total;
}

// FUN_00173A00 NONMATCHING
s16 FUN_00173a00(DatPersonaWork* persona, u16 statId)
{
    s32 total;

    assertStat(statId, 0x1A7);
    total = persona->naturalStats[statId] + datPersonaGetBonusStat(persona, statId) +
            datPersonaGetStat3(persona, statId);
    if (total >= 99)
    {
        total = 99;
    }
    return total;
}

// FUN_00173C60 NONMATCHING
s8 FUN_00173c60(DatPersonaWork* persona, u16 statId)
{
    u16 owner;
    s16 equipmentIdx;
    s8 total = 0;

    assertStat(statId, 0x22D);
    owner = personaEquipmentOwner(persona);
    K_ASSERT(owner < 0xB, 0x239);
    equipmentIdx = personaEquipmentIndex(owner);
    if (equipmentIdx >= 0)
    {
        total += personaEquipmentBonus(owner, equipmentIdx, statId);
    }
    total += personaEquipmentEffects(owner, statId);
    return total;
}
