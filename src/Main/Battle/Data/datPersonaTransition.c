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
    s16 total = 0;
    s16 equipmentIdx;
    u16 owner;

    K_ASSERT(statId < PERSONA_STAT_MAX, 0x22D);
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
    if ((u16)(u32)persona == 1)
    {
        equipmentIdx = gGlobalWork.heroEquip.equipmentsIdx[3];
    }
    else if ((u16)(u32)persona < PC_MAX)
    {
        equipmentIdx = gPcs[(u16)(u32)persona].equipmentsIdx[3];
    }
    else
    {
        equipmentIdx = -1;
    }
    if (equipmentIdx >= 0)
    {
        u16 itemId = 0;
        u8* itemTable = NULL;

        if ((u16)(u32)persona == 0xFFFF)
        {
            itemId = *(u16*)(D_00833E80 + equipmentIdx * sizeof(DatEquipment));
        }
        else if ((u16)(u32)persona == 1)
        {
            itemId = gGlobalWork.heroEquip.equipments[equipmentIdx].id;
        }
        else if ((u16)(u32)persona < 0x100)
        {
            itemId = gPcs[(u16)(u32)persona].equipments[equipmentIdx].id;
        }
        else
        {
            itemTable = D_007FD6C8 + (u16)(u32)persona * sizeof(DatPc);
            itemId = *(u16*)(itemTable + equipmentIdx * sizeof(DatEquipment));
        }
        if (itemId >= 3000 && itemId <= 3999)
        {
            itemTable = iGpffffb2e4 + (itemId - 3000) * 0x24;
            total += *(s16*)(itemTable + 4 + statId * 2);
        }
    }
    switch (statId)
    {
    case 0:
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0);
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 2) * 2;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 3) * 3;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 4) * 4;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 5) * 5;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x83) * 10;
        break;
    case 1:
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xB);
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xC) * 2;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xD) * 3;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xE) * 4;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xF) * 5;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x85) * 10;
        break;
    case 2:
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 6);
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 7) * 2;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 8) * 3;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 9) * 4;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0xA) * 5;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x84) * 10;
        break;
    case 3:
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x10);
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x11) * 2;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x12) * 3;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x13) * 4;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x14) * 5;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x86) * 10;
        break;
    case 4:
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x15);
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x16) * 2;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x17) * 3;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x18) * 4;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x19) * 5;
        total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x87) * 10;
        break;
    }
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x88);
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x89) * 2;
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x8A) * 3;
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x8B) * 4;
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x8C) * 5;
    total += datCalcCountEquipmentWithEffectById((u16)(u32)persona, 0x8D) * 10;
    return total;
}

