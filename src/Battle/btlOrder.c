#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "temporary.h"
extern u8 gp0xffff9918[8];
extern u32 datCalcRand(u32 max);
extern u32 FUN_00300c90(void* calc, u32 field);

// FUN_0029a250
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action)
{
    BtlAction* curr;
    s32 i;

    for (i = 0; i < arrSize; i++)
    {
        curr = *actions;
        if (curr != action)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (i == arrSize)
    {
        return false;
    }

    for (; i < arrSize - 1; i++)
    {
        *actions = *(actions + 1);
        actions++;
    }

    *actions = NULL;

    return true;
}

// FUN_0029a2c0
u32 btlOrderAddAction(BtlAction* action)
{
    BtlAction** actions;
    BtlAction* curr;
    u32 i;

    actions = gBtl->order.actions;
    for (i = 0; i < BTL_MAXACTIONS; i++)
    {
        curr = *actions;
        if (curr != NULL)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (i == BTL_MAXACTIONS)
    {
        return false;
    }

    *actions = action;

    return true;
}
// FUN_0029a320
u32 FUN_0029a320(BtlAction* action)
{
    BtlAction** actions;
    u32 removed;

    actions = gBtl->order.actions;
    removed = 0;
    while (btlOrderRemoveAction(actions, BTL_MAXACTIONS, action) == 1)
    {
        removed = 1;
    }
    return removed;
}

// FUN_0029a380
u32 FUN_0029a380(BtlAction* action)
{
    BtlAction** actions;
    u32 i;

    actions = gBtl->order.actions2;
    i = 0;
    while (i < BTL_MAXACTIONS)
    {
        if (*actions == NULL)
        {
            break;
        }
        actions++;
        i++;
    }

    if (i == BTL_MAXACTIONS)
    {
        return 0;
    }

    *actions = action;
    return 1;
}
// FUN_0029a3e0
u32 FUN_0029a3e0(BtlAction* action)
{
    if (action->unk_28 != 0 || *(u8*)((u8*)action + 0x29) != 0)
    {
        return 1;
    }

    if ((gBtl->flags & BTL_FLAG2_UNK08) == 0)
    {
        return 1;
    }

    if ((action->unk_18 & 4) == 0 &&
        gBtl->order.actions2[BTLORDER_CURRENT] != NULL &&
        gBtl->order.actions2[BTLORDER_CURRENT] == action)
    {
        return 1;
    }

    return gBtl->order.actions[1] == action;
}

// FUN_0029a470
u32 FUN_0029a470(BtlAction* action)
{
    BtlAction** actions;
    u32 i;

    actions = gBtl->order.actions;
    i = 0;
    while (i < BTL_MAXACTIONS)
    {
        if (*actions == action)
        {
            break;
        }
        actions++;
        i++;
    }

    if (i == BTL_MAXACTIONS)
    {
        return 0;
    }

    while ((s32)i > 0)
    {
        *actions = *(actions - 1);
        actions--;
        i--;
    }
    *actions = action;

    return 1;
}

// FUN_0029a4f0
u32 FUN_0029a4f0(BtlAction* action)
{
    BtlAction** actions;
    u32 i;

    actions = gBtl->order.actions;
    i = 0;
    while (i < BTL_MAXACTIONS)
    {
        if (*actions == action)
        {
            break;
        }
        actions++;
        i++;
    }

    if (i == BTL_MAXACTIONS)
    {
        return 0;
    }

    while (i < BTL_MAXACTIONS - 1)
    {
        if (actions[1] == NULL)
        {
            break;
        }
        *actions = *(actions + 1);
        actions++;
        i++;
    }
    *actions = action;

    return 1;
}

// FUN_0029a570
void FUN_0029a570(void)
{
    u32 count;
    BtlAction** scan;
    BtlAction** actions;
    u32 i;
    u32 swapped;

    scan = gBtl->order.actions;
    count = 0;
    while (count < BTL_MAXACTIONS)
    {
        if (*scan == NULL)
        {
            break;
        }
        scan++;
        count++;
    }

    do
    {
        swapped = 0;
        actions = gBtl->order.actions;
        i = 0;
        while (i < count - 1)
        {
            BtlAction* first;
            BtlAction* second;
            u16 firstValue;
            u16 secondValue;

            first = *actions;
            second = actions[1];
            if (first != NULL && second != NULL)
            {
                firstValue = (u8)FUN_00300c90(first->unit->datUnit, 3);
                secondValue = (u8)FUN_00300c90(second->unit->datUnit, 3);
                if (firstValue < secondValue)
                {
                    *actions = second;
                    actions[1] = first;
                    swapped = 1;
                }
            }
            i++;
            actions++;
        }
    } while (swapped != 0);
}

#pragma opt_loop_invariants on
/* Removing this worsens FUN_0029a690 (nd5 -> nd109) - measured W161. */
// The residual is limited to MWCCPS2 register coloring/scheduling; logical control flow and object size match retail.
// FUN_0029a690 NONMATCHING
void FUN_0029a690(u16 genus)
{
    u32 count;
    BtlAction** scan;
    u32 swapped;
    u32 i;
    BtlAction** actions;
    scan = gBtl->order.actions;
    count = 0;
    while (count < BTL_MAXACTIONS)
    {
        if (*scan == NULL)
        {
            break;
        }
        scan++;
        count++;
    }

    do
    {
        swapped = 0;
        actions = gBtl->order.actions;
        i = 0;
        while (i < count - 1)
        {
            BtlAction* first;
            BtlAction* second;
            u8 firstGenus;
            u8 secondGenus;

            first = *actions;
            second = actions[1];
            if (first != NULL && second != NULL)
            {
                firstGenus = first->unit->genus;
                secondGenus = second->unit->genus;
                if (firstGenus != secondGenus && firstGenus != genus)
                {
                    *actions = second;
                    actions[1] = first;
                    swapped = 1;
                }
            }
            i++;
            actions++;
        }
    } while (swapped != 0);
}
#pragma opt_loop_invariants off
/* Removing this worsens FUN_0029a750 (nd120 -> nd774) - measured W161. */
// The residual is limited to MWCCPS2 register coloring/scheduling; logical control flow and object size match retail.
// FUN_0029a750 NONMATCHING
void FUN_0029a750(void)
{
    u16 playerCount;
    u16 enemyCount;
    BtlAction** actions;
    BtlUnit* unit;
    u16 enemyWeightTotal;
    u16 i;
    u16 playerOrdered;
    u16 enemyOrdered;
    u16 j;
    u16 actionCount;
    u16 count;
    u16 playerWeightTotal;
    struct
    {
        BtlAction* action;
        u8 weight;
    } playerActions[BTL_MAXACTIONS];
    struct
    {
        BtlAction* action;
        u8 weight;
    } enemyActions[BTL_MAXACTIONS];
    BtlAction* orderedPlayers[BTL_MAXACTIONS];
    BtlAction* orderedEnemies[BTL_MAXACTIONS];
    BtlAction* action;
    u16 outputCount;

    FUN_0029a570();
    actions = gBtl->order.actions;
    playerCount = 0;
    enemyWeightTotal = 0;
    enemyCount = 0;
    playerWeightTotal = 0;
    actionCount = 0;
    count = 0;
    while (count < BTL_MAXACTIONS)
    {
        action = actions[count];
        if (action == NULL)
        {
            break;
        }
        if (gBtl->actionList.head != action)
        {
            unit = action->unit;
            switch (unit->genus)
            {
            case UNIT_GENUS_PC:
                playerActions[playerCount].action = action;
                playerActions[playerCount].weight = gp0xffff9918[playerCount];
                playerWeightTotal += playerActions[playerCount].weight;
                playerCount++;
                break;
            case UNIT_GENUS_EC:
                enemyActions[enemyCount].action = action;
                enemyActions[enemyCount].weight = 10;
                enemyWeightTotal += enemyActions[enemyCount].weight;
                enemyCount++;
                break;
            }
            actionCount++;
        }
        count++;
    }

    playerOrdered = 0;
    for (i = 0; i < playerCount; i++)
    {
        u16 randomValue;

        randomValue = (u16)datCalcRand(playerWeightTotal);
        for (j = 0; j < playerCount; j++)
        {
            u8 weight;

            weight = playerActions[j].weight;
            if (weight > 0 && randomValue < weight)
            {
                playerWeightTotal -= weight;
                orderedPlayers[playerOrdered] = playerActions[j].action;
                playerActions[j].weight = 0;
                playerOrdered++;
                break;
            }
            randomValue = (u16)(randomValue - weight);
        }
    }

    enemyOrdered = 0;
    for (i = 0; i < enemyCount; i++)
    {
        u16 randomValue;

        randomValue = (u16)datCalcRand(enemyWeightTotal);
        for (j = 0; j < enemyCount; j++)
        {
            u8 weight;

            weight = enemyActions[j].weight;
            if (weight > 0 && randomValue < weight)
            {
                enemyWeightTotal -= weight;
                orderedEnemies[enemyOrdered] = enemyActions[j].action;
                enemyActions[j].weight = 0;
                enemyOrdered++;
                break;
            }
            randomValue = (u16)(randomValue - weight);
        }
    }

    playerOrdered = 0;
    enemyOrdered = 0;
    actions[0] = gBtl->actionList.head;
    outputCount = 1;
    for (i = 0; i < actionCount; i++)
    {
        if (playerOrdered < playerCount && enemyOrdered < enemyCount)
        {
            u32 randomValue;
            u16 threshold;
            s16 tmp;

            tmp = (i == 0) ? 0x32 : (((i & 1) != 0) ? 0x50 : 0x14);
            threshold = tmp;

            randomValue = datCalcRand(100);
            if (randomValue < threshold)
            {
                action = orderedPlayers[playerOrdered++];
            }
            else
            {
                action = orderedEnemies[enemyOrdered++];
            }
        }
        else if (playerOrdered < playerCount)
        {
            action = orderedPlayers[playerOrdered++];
        }
        else if (enemyOrdered < enemyCount)
        {
            action = orderedEnemies[enemyOrdered++];
        }

        actions[outputCount++] = action;
    }

    for (i = outputCount; i < BTL_MAXACTIONS; i++)
    {
        actions[i] = NULL;
    }
}
#pragma opt_loop_invariants reset
static inline void btlOrderFinishAction(BtlAction* action)
{
    if ((action->unk_18 & 4) != 0)
    {
        btlOrderRemoveAction(gBtl->order.actions2, BTL_MAXACTIONS, action);
        action->unk_18 &= ~4;
    }
    else if ((gBtl->flags & BTL_FLAG2_UNK08) != 0)
    {
        gBtl->order.prevActionPlaying = action;
        FUN_0029a4f0(action);
    }

    gBtl->order.flags |= 8;
}

// FUN_0029abe0
void FUN_0029abe0(BtlAction* action)
{
    btlOrderFinishAction(action);
}

// FUN_0029ac70
void FUN_0029ac70(BtlAction* action)
{
    if ((action->unk_18 & 4) != 0)
    {
        btlOrderFinishAction(action);
    }
    else
    {
        gBtl->order.flags |= 8;
    }
}
// FUN_0029adf0
u32 FUN_0029adf0(BtlAction* action)
{
    BtlAction** actions;
    u32 i;

    actions = gBtl->order.actions2;
    for (i = 0; i < BTL_MAXACTIONS; i++)
    {
        if (*actions == action)
        {
            return 1;
        }
        actions++;
    }

    return 0;
}

// FUN_0029ae40
void btlOrder0029ae40(void)
{
    u16 flags;
    BtlAction** actions;

    flags = gBtl->order.flags;
    if ((flags & 1) == 0)
    {
        return;
    }
    if ((gBtl->flags & 0x80000) != 0)
    {
        return;
    }
    if ((flags & 8) == 0)
    {
        return;
    }

    actions = gBtl->order.actions2;
    if (actions[BTLORDER_CURRENT] != NULL)
    {
        if (actions[BTLORDER_CURRENT]->currState == BTLACTION_STATE_STANDBY)
        {
            actions[BTLORDER_CURRENT]->unk_18 |= 4;
            btlActionSetState(actions[BTLORDER_CURRENT],
                              actions[BTLORDER_CURRENT]->unk_16);
            gBtl->order.turnNo++;
            gBtl->order.flags &= ~8;
        }
    }
    else
    {
        actions = gBtl->order.actions;
        if (gBtl->order.turnNo != 0)
        {
            if ((flags & 2) != 0 &&
                actions[0]->unit->genus == UNIT_GENUS_EC)
            {
                FUN_0029a750();
                actions = gBtl->order.actions;
                gBtl->order.flags &= ~2;
            }

            if ((gBtl->order.flags & 4) != 0 &&
                actions[0]->unit->genus == UNIT_GENUS_PC)
            {
                FUN_0029a750();
                actions = gBtl->order.actions;
                gBtl->order.flags &= ~4;
            }
        }

        if (actions[0] == NULL)
        {
            return;
        }
        if (actions[0]->currState != BTLACTION_STATE_STANDBY)
        {
            return;
        }
        {
            if (actions[0]->unit->genus == UNIT_GENUS_PC)
            {
                if ((gBtl->flags & 0x2000) != 0)
                {
                    actions[0]->unk_14 = 9;
                }
                else if (gBtl->actionList.head == actions[0])
                {
                    actions[0]->unk_14 = 5;
                }
                else
                {
                    actions[0]->unk_14 = 8;
                }
            }
            else
            {
                actions[0]->unk_14 = 8;
            }

            btlActionSetState(actions[0], 2);
            gBtl->order.flags &= ~8;
            gBtl->order.turnNo++;
        }
    }
}

// FUN_0029b040
void FUN_0029b040(void)
{
    gBtl->order.flags |= 8;
    gBtl->order.flags |= 1;
}

// FUN_0029b070
void FUN_0029b070(void)
{
    gBtl->order.flags &= ~1;
}

// FUN_0029ad20
BtlAction* btlOrderGetActionPlaying()
{
    BtlAction** actions;

    actions = gBtl->order.actions2;
    if (actions[BTLORDER_CURRENT] == NULL)
    {
        actions = gBtl->order.actions;
    }

    return *actions;
}

// FUN_0029ad50
BtlAction* btlOrderGetPrevActionPlaying()
{
    return gBtl->order.prevActionPlaying;
}

// FUN_0029ad60
BtlAction* btlOrderGetActionByIdx(u16 idx)
{
    if (idx >= BTL_MAXACTIONS)
    {
        return NULL;
    }

    return gBtl->order.actions[idx];
}

// FUN_0029ada0
BtlUnit* btlOrderGetUnitByIdx(u16 idx)
{
    BtlAction* action;

    if (idx >= BTL_MAXACTIONS)
    {
        action = NULL;
    }
    else
    {
        action = gBtl->order.actions[idx];
    }

    if (action == NULL)
    {
        return NULL;
    }

    return action->unit;
}

// FUN_0029b090
void btlOrderInit()
{
    memset(&gBtl->order, 0, sizeof(BtlOrder));
}
// FUN_0029b0c0
u32 FUN_0029b0c0(BtlAction* action)
{
    return !((action->unk_18 & 4) != 0);
}
