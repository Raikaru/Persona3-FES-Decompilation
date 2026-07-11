#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "temporary.h"
extern u8 gp0xffff9918[];
extern u32 datCalcRand(u32 max);
extern u32 FUN_00300c90(void* calc, u32 field);

// FUN_0029a250
u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action)
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
// FUN_0029a320 NONMATCHING
u32 FUN_0029a320(BtlAction* action)
{
    u32 removed;

    removed = 0;
    while (btlOrderRemoveAction(gBtl->order.actions, BTL_MAXACTIONS, action) != 0)
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

// FUN_0029a570 NONMATCHING
void FUN_0029a570(void)
{
    BtlAction** actions;
    u32 count;
    u32 i;
    u32 swapped;

    actions = gBtl->order.actions;
    for (count = 0; count < BTL_MAXACTIONS && actions[count] != NULL; count++)
    {
    }

    do
    {
        swapped = 0;
        for (i = 0; i + 1 < count; i++)
        {
            BtlAction* first;
            BtlAction* second;
            u32 firstValue;
            u32 secondValue;

            first = actions[i];
            second = actions[i + 1];
            if (first == NULL || second == NULL)
            {
                continue;
            }

            firstValue = FUN_00300c90(first->unit->datUnit, 3);
            secondValue = FUN_00300c90(second->unit->datUnit, 3);
            if ((u8)firstValue < (u8)secondValue)
            {
                actions[i] = second;
                actions[i + 1] = first;
                swapped = 1;
            }
        }
    } while (swapped != 0);
}

// FUN_0029a690 NONMATCHING
void FUN_0029a690(u16 genus)
{
    BtlAction** actions;
    u32 count;
    u32 i;
    u32 swapped;

    actions = gBtl->order.actions;
    for (count = 0; count < BTL_MAXACTIONS && actions[count] != NULL; count++)
    {
    }

    do
    {
        swapped = 0;
        for (i = 0; i + 1 < count; i++)
        {
            BtlAction* first;
            BtlAction* second;
            u8 firstGenus;
            u8 secondGenus;

            first = actions[i];
            second = actions[i + 1];
            if (first == NULL || second == NULL)
            {
                continue;
            }

            firstGenus = first->unit->genus;
            secondGenus = second->unit->genus;
            if (firstGenus != secondGenus && firstGenus != (u8)genus)
            {
                actions[i] = second;
                actions[i + 1] = first;
                swapped = 1;
            }
        }
    } while (swapped != 0);
}

// FUN_0029a750 NONMATCHING
void FUN_0029a750(void)
{
    BtlAction** actions;
    BtlAction* playerActions[BTL_MAXACTIONS];
    BtlAction* enemyActions[BTL_MAXACTIONS];
    BtlAction* orderedPlayers[BTL_MAXACTIONS];
    BtlAction* orderedEnemies[BTL_MAXACTIONS];
    u8 playerWeights[BTL_MAXACTIONS];
    u8 enemyWeights[BTL_MAXACTIONS];
    u32 count;
    u32 playerCount;
    u32 enemyCount;
    u32 playerOrdered;
    u32 enemyOrdered;
    u32 playerWeightTotal;
    u32 enemyWeightTotal;
    u32 i;
    u32 j;
    u32 outputCount;

    FUN_0029a570();
    actions = gBtl->order.actions;
    playerCount = 0;
    enemyCount = 0;
    playerWeightTotal = 0;
    enemyWeightTotal = 0;

    for (count = 0; count < BTL_MAXACTIONS && actions[count] != NULL; count++)
    {
        BtlAction* action;
        BtlUnit* unit;

        action = actions[count];
        if (action == gBtl->actionList.head)
        {
            continue;
        }

        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC)
        {
            enemyActions[enemyCount] = action;
            enemyWeights[enemyCount] = 10;
            enemyWeightTotal += enemyWeights[enemyCount];
            enemyCount++;
        }
        else if (unit->genus == UNIT_GENUS_PC)
        {
            playerActions[playerCount] = action;
            playerWeights[playerCount] = gp0xffff9918[playerCount];
            playerWeightTotal += playerWeights[playerCount];
            playerCount++;
        }
    }

    playerOrdered = 0;
    for (i = 0; i < playerCount; i++)
    {
        u16 randomValue;

        randomValue = (u16)datCalcRand((u16)playerWeightTotal);
        for (j = 0; j < playerCount; j++)
        {
            if (playerWeights[j] != 0 && randomValue < playerWeights[j])
            {
                playerWeightTotal -= playerWeights[j];
                orderedPlayers[playerOrdered++] = playerActions[j];
                playerWeights[j] = 0;
                break;
            }
            randomValue = (u16)(randomValue - playerWeights[j]);
        }
    }

    enemyOrdered = 0;
    for (i = 0; i < enemyCount; i++)
    {
        u16 randomValue;

        randomValue = (u16)datCalcRand((u16)enemyWeightTotal);
        for (j = 0; j < enemyCount; j++)
        {
            if (enemyWeights[j] != 0 && randomValue < enemyWeights[j])
            {
                enemyWeightTotal -= enemyWeights[j];
                orderedEnemies[enemyOrdered++] = enemyActions[j];
                enemyWeights[j] = 0;
                break;
            }
            randomValue = (u16)(randomValue - enemyWeights[j]);
        }
    }

    outputCount = 1;
    actions[0] = gBtl->actionList.head;
    playerOrdered = 0;
    enemyOrdered = 0;
    for (i = 1; i < count; i++)
    {
        BtlAction* action;

        if (playerOrdered < playerCount && enemyOrdered < enemyCount)
        {
            u32 threshold;
            u32 randomValue;

            if (i == 1)
            {
                threshold = 0x32;
            }
            else if ((i & 1) != 0)
            {
                threshold = 0x14;
            }
            else
            {
                threshold = 0x50;
            }

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
        else
        {
            action = orderedEnemies[enemyOrdered++];
        }

        actions[i] = action;
        outputCount = i + 1;
    }

    for (i = outputCount; i < BTL_MAXACTIONS; i++)
    {
        actions[i] = NULL;
    }
}

// FUN_0029abe0 NONMATCHING
void FUN_0029abe0(BtlAction* action)
{
    if ((action->unk_18 & 4) == 0)
    {
        if ((gBtl->flags & BTL_FLAG2_UNK08) != 0)
        {
            gBtl->order.prevActionPlaying = action;
            FUN_0029a4f0(action);
        }
    }
    else
    {
        btlOrderRemoveAction(gBtl->order.actions2, BTL_MAXACTIONS, action);
        action->unk_18 &= ~4;
    }

    gBtl->order.flags |= 8;
}

// FUN_0029ac70 NONMATCHING
void FUN_0029ac70(BtlAction* action)
{
    if ((action->unk_18 & 4) == 0)
    {
        gBtl->order.flags |= 8;
    }
    else
    {
        btlOrderRemoveAction(gBtl->order.actions2, BTL_MAXACTIONS, action);
        action->unk_18 &= ~4;
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

// FUN_0029ae40 NONMATCHING
void btlOrder0029ae40(void)
{
    u16 flags;
    BtlAction** actions;
    BtlAction* action;

    flags = gBtl->order.flags;
    if ((flags & 1) == 0 || (gBtl->flags & 0x80000) != 0 || (flags & 8) == 0)
    {
        return;
    }

    action = gBtl->order.actions2[BTLORDER_CURRENT];
    if (action == NULL)
    {
        actions = gBtl->order.actions;
        if (gBtl->order.turnNo != 0)
        {
            if ((gBtl->order.flags & 2) != 0 &&
                actions[0] != NULL && actions[0]->unit->genus == UNIT_GENUS_EC)
            {
                FUN_0029a750();
                actions = gBtl->order.actions;
                gBtl->order.flags &= ~2;
            }

            if ((gBtl->order.flags & 4) != 0 &&
                actions[0] != NULL && actions[0]->unit->genus == UNIT_GENUS_PC)
            {
                FUN_0029a750();
                actions = gBtl->order.actions;
                gBtl->order.flags &= ~4;
            }
        }

        action = actions[0];
        if (action != NULL && action->currState == BTLACTION_STATE_STANDBY)
        {
            if (action->unit->genus == UNIT_GENUS_PC)
            {
                if ((gBtl->flags & 0x2000) == 0)
                {
                    action->unk_14 = (gBtl->actionList.head == action) ? 5 : 8;
                }
                else
                {
                    action->unk_14 = 9;
                }
            }
            else
            {
                action->unk_14 = 8;
            }

            btlActionSetState(action, 2);
            gBtl->order.flags &= ~8;
            gBtl->order.turnNo++;
        }
    }
    else if (action->currState == BTLACTION_STATE_STANDBY)
    {
        action->unk_18 |= 4;
        btlActionSetState(action, action->unk_16);
        gBtl->order.turnNo++;
        gBtl->order.flags &= ~8;
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
