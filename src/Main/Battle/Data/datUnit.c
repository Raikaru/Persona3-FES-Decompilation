#include "Main/g_data.h"
#include "Battle/battle.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#include "Main/Battle/Data/datCalc.h"

extern u8* DAT_007CE410;
extern void func_00301540(DatUnit* unit, u8 index);

typedef struct DatEnemyUnitInit
{
    u16 flags;
    u8 unknown02;
    u8 level;
    u16 hp;
    u16 sp;
    u8 unknown08[6];
    u16 skills[8];
    u8 unknown1E[32];
} DatEnemyUnitInit;

// FUN_002ff340
DatUnitPc* datUnitCreatePc(u16 pcId)
{
    DatUnitPc* pc;

    pc = RwMalloc(sizeof(DatUnitPc), rwMEMHINTDUR_GLOBAL);
    memset(pc, 0, sizeof(DatUnitPc));

    pc->base.genus = UNIT_GENUS_PC;
    pc->base.count = 1;
    pc->base.unit = datGetUnit(pcId);

    datUnitInit(pc->base.unit, UNIT_GENUS_PC, pcId);

    return pc;
}

#pragma opt_loop_invariants on
// FUN_002ff3e0 NONMATCHING
DatUnitEc* datUnitCreateEc(u16 encountId)
{
    u16 i;
    u16 count;
    DatUnitEc* ec;
    u16 j;
    u16 k;

    count = 0;
    i = 0;
    for (; (u32)(i & 0xFFFF) < 5U; i++)
    {
        if (gEncountTbl[encountId].enmIds[i] != 0)
        {
            count++;
        }
    }

    ec = RwMalloc(sizeof(DatUnitEc), rwMEMHINTDUR_GLOBAL);
    memset(ec, 0, sizeof(DatUnitEc));

    ec->base.genus = UNIT_GENUS_EC;
    ec->base.count = count;
    ec->encountId = encountId;
    ec->base.unit = ec->units;

    j = 0;
    for (k = 0; (u32)(k & 0xFFFF) < 5U; k++)
    {
        if (gEncountTbl[encountId].enmIds[k] != 0)
        {
            datUnitInit(&ec->base.unit[j], UNIT_GENUS_EC, gEncountTbl[encountId].enmIds[k]);

            j++;
        }
    }

    return ec;
}
#pragma opt_loop_invariants off

// FUN_002ff540
DatUnit* datUnitEcAddEnemy(DatUnitEc* ec, u16 id)
{
    u16 i;
    DatUnit* curr;

    K_ASSERT(ec->base.genus == UNIT_GENUS_EC, 100);
    K_ASSERT(ec->base.count < 6, 101);

    for (i = 0; i < 6; i++)
    {
        curr = &ec->base.unit[i];

        if (curr->id == 0)
        {
            datUnitInit(curr, UNIT_GENUS_EC, id);
            ec->base.count++;

            break;
        }
    }

    K_ASSERT(i < 6, 117);

    return curr;
}

// FUN_002ff660
void datUnitEcRemoveEnemy(DatUnitEc* ec, DatUnit* unit)
{
    u16 i;
    DatUnit* curr;

    K_ASSERT(ec->base.genus == UNIT_GENUS_EC, 134);
    K_ASSERT(ec->base.count <= 6, 135);

    for (i = 0; i < 6; i++)
    {
        curr = &ec->base.unit[i];

        if (unit == curr)
        {
            curr->id = 0;
            ec->base.count--;

            break;
        }
    }

    K_ASSERT(i < 6, 147);
}

// FUN_002ff760
void datUnitDestroyGenus(DatUnitGenusBase* genusBase)
{
    RwFree(genusBase);
}

// FUN_002ff790
u32 func_002ff790(DatUnitGenusBase* genusBase)
{
    u16 i;

    if (genusBase->genus == UNIT_GENUS_EC)
    {
        for (i = 0; i < 6; i++)
        {
            DatUnit* unit = genusBase->unit;
            unit += i;

            if (unit->id != 0 && datCalcIsDead(unit, 0) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        K_ASSERT(genusBase->count == 1, 0xb9);

        if (datCalcIsDead(genusBase->unit, 0) == 0)
        {
            return 0;
        }
    }

    return 1;
}


#pragma opt_loop_invariants on
// FUN_002ff890
u32 datUnitInit(DatUnit* unit, u8 genus, u16 id)
{
    u32 i;
    u32 j;

    switch (genus)
    {
    case UNIT_GENUS_PC:
        if ((id & 0xFFFF) >= 0xB) K_Assert(__FILE__, 0xd3);
        unit->flags &= ~UNIT_FLAG_ENEMY;
        unit->flags &= ~0x10;
        unit->flags &= ~0x20;
        break;
    case UNIT_GENUS_EC:
        if ((id & 0xFFFF) >= 0x150) K_Assert(__FILE__, 0xd9);
        unit->flags = UNIT_FLAG_ENEMY;
        unit->level = DAT_007CE410[id * 0x3e + 3];
        unit->hp = *(u16*)((u8*)(uintptr_t)((u32)id * 0x3e) +
                          (uintptr_t)DAT_007CE410 + 4);
        unit->sp = *(u16*)((u8*)(uintptr_t)((u32)id * 0x3e) +
                          (uintptr_t)DAT_007CE410 + 6);
        unit->bad = 0;
        if (*(u16*)(DAT_007CE410 + id * 0x3e) & 8) unit->flags |= 0x10;
        if (*(u16*)(DAT_007CE410 + id * 0x3e) & 0x10) unit->flags |= 0x20;
        if (*(u16*)(DAT_007CE410 + id * 0x3e) & 0x100) unit->flags |= 0x80;
        if (*(u16*)(DAT_007CE410 + id * 0x3e) & 0x200) unit->flags |= 0x100;
        for (i = 0; i < 8; i++)
        {
            u16 skill = ((DatEnemyUnitInit*)DAT_007CE410)[id].skills[i];
            switch (skill)
            {
            case 0x220:
            case 0x221:
            case 0x222:
                unit->flags |= 0x200;
                break;
            }
        }
        break;
    default:
        K_Assert(__FILE__, 0xfd);
        break;
    }
    for (j = 0; j < 0x15; j++) func_00301540(unit, (u8)j);
    unit->id = id;
    unit->id2 = id;
    unit->flags |= UNIT_FLAG_ACTIVE;
    return true;
}
#pragma opt_loop_invariants off

// FUN_002ffb00
u16 func_002ffb00(DatUnitGenusBase* genusBase)
{
    u16 pcId;
    u16 condition;

    if (genusBase->genus == UNIT_GENUS_PC)
    {
        pcId = genusBase->unit->id;
        FUN_0016ca90(pcId, -1);

        if (datGetFatigueCounter(pcId) == 0)
        {
            condition = datGetPhysicalCondition(pcId);
            if (condition == 2) goto improve_condition;
            if (condition == 1) goto improve_condition;
            switch (condition)
            {
            case 0:
                goto improve_condition;
            default:
                goto condition_done;
            }

improve_condition:
            datSetPhysicalCondition(pcId, 3);
        }
condition_done:
        return datGetPhysicalCondition(pcId);
    }
    return 0;
}
