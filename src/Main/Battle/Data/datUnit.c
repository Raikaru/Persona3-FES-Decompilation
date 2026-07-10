#include "Main/g_data.h"
#include "Battle/battle.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#include "Main/Battle/Data/datCalc.h"

extern u8* DAT_007CE410;
extern void func_00301540(DatUnit* unit, u8 index);

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

// FUN_002ff3e0 NONMATCHING
DatUnitEc* datUnitCreateEc(u16 encountId)
{
    u16 i;
    u16 count;
    BtlEncountTable* encount;
    DatUnitEc* ec;
    u16 j;
    u16 k;

    count = 0; // regswap (s1 but should be s0)
    i = 0;
    encount = &gEncountTbl[encountId];
    for (; i < 5; i++)
    {
        if (encount->enmIds[i] != 0) // TODO: addu v0, v1, v0 instead of addu v0, v0, v1
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
    for (k = 0; k < 5; k++)
    {
        encount = &gEncountTbl[encountId]; // TODO: addu v1, s1, v0 instead of addu v1, v0, s0

        if (encount->enmIds[k] != 0) // TODO: addu v0, v1, v0 instead of addu v0, v0, v1
        {
            datUnitInit(&ec->base.unit[j], UNIT_GENUS_EC, encount->enmIds[k]);

            j++;
        }
    }

    return ec;
}

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

// FUN_002ff790 NONMATCHING
u32 func_002ff790(DatUnitGenusBase* genusBase)
{
    u16 i;

    if (genusBase->genus == UNIT_GENUS_EC)
    {
        for (i = 0; i < 6; i++)
        {
            DatUnit* unit = &genusBase->unit[i];

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


// FUN_002ff890 NONMATCHING
u32 datUnitInit(DatUnit* unit, u8 genus, u16 id)
{
    u8* enemy;
    u16 enemyFlags;
    u16 i;

    if (genus == UNIT_GENUS_EC)
    {
        K_ASSERT(id <= 0x14f, 0xd9);

        enemy = DAT_007CE410 + id * 0x3e;
        enemyFlags = *(u16*)enemy;
        unit->flags = UNIT_FLAG_ENEMY;
        unit->level = enemy[3];
        unit->hp = *(u16*)(enemy + 4);
        unit->sp = *(u16*)(enemy + 6);
        unit->bad = 0;

        if (enemyFlags & 8)
        {
            unit->flags |= 0x10;
        }
        if (enemyFlags & 0x10)
        {
            unit->flags |= 0x20;
        }
        if (enemyFlags & 0x100)
        {
            unit->flags |= 0x80;
        }
        if (enemyFlags & 0x200)
        {
            unit->flags |= 0x100;
        }

        for (i = 0; i < 8; i++)
        {
            u16 skill = *(u16*)(enemy + i * 2 + 0xe);

            if (skill == 0x220 || skill == 0x221 || skill == 0x222)
            {
                unit->flags |= 0x200;
            }
        }
    }
    else if (genus == UNIT_GENUS_PC)
    {
        K_ASSERT(id <= 10, 0xd3);
        unit->flags &= ~(UNIT_FLAG_ENEMY | 0x10 | 0x20);
    }
    else
    {
        K_ASSERT(0, 0xfd);
    }

    for (i = 0; i < 0x15; i++)
    {
        func_00301540(unit, (u8)i);
    }

    unit->id = id;
    unit->id2 = id;
    unit->flags |= UNIT_FLAG_ACTIVE;

    return true;
}

// FUN_002ffb00 NONMATCHING
void func_002ffb00(DatUnitGenusBase* genusBase)
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

            if (condition == 0 || condition == 1 || condition == 2)
            {
                datSetPhysicalCondition(pcId, 3);
            }
        }
    }
}
