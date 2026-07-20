#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlMain.h"
#include "Battle/btlOrder.h"
#include "Battle/btlUnit.h"
#include "Battle/btlPacket.h"
#include "Battle/btlFormation.h"
#include "Battle/btlVoice.h"
#include "Graphics/Effect/effMisc.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/Battle/Data/datCalc.h"
#include "temporary.h"
extern u32 func_002e4430();

typedef struct BtlEnemyRecord
{
    u8 pad_00[0x22];
    s16 field_22;
    u8 pad_24[2];
    s16 field_26;
    u8 pad_28[0xc0];
} BtlEnemyRecord;


#define BTLACTION_IDMAX 0xFFFFFFF
/* Retail action scratch remains intentionally opaque until packet-result layouts are named. */
#define ACTION_U8(action, offset) (*(u8*)((u8*)(action) + (offset)))
#define ACTION_U16(action, offset) (*(u16*)((u8*)(action) + (offset)))
#define ACTION_S16(action, offset) (*(s16*)((u8*)(action) + (offset)))
#define ACTION_U32(action, offset) (*(u32*)((u8*)(action) + (offset)))
#define BATTLE_U16(offset) (*(u16*)((u8*)gBtl + (offset)))

/* Packet constructors not yet assigned public subsystem names. */
BtlPacket* FUN_002819d0();
BtlPacket* FUN_00282130();
BtlPacket* FUN_002822b0();
BtlPacket* FUN_00282650();
BtlPacket* FUN_002843e0(BtlUnit* unit, u16 id);
void FUN_00175130(u16 id);
s32 FUN_002fcf50(BtlAction* action);
BtlPacket* FUN_00284200();
BtlPacket* FUN_00284c90();
BtlPacket* FUN_00285d30();
BtlPacket* FUN_00285690();
BtlPacket* FUN_002864a0();
BtlPacket* FUN_002886e0();
BtlPacket* FUN_00288950();
BtlPacket* FUN_002bac00();
BtlPacket* FUN_002bd230(BtlUnit* unit, u32 a, u32 b);
BtlPacket* FUN_002bd480(BtlUnit* unit);
BtlPacket* FUN_002bd590(BtlUnit* unit, u16 id);
BtlPacket* FUN_002bd690(BtlUnit* unit, u16 id);
BtlPacket* FUN_002bd850(BtlUnit* unit, s16 id);
BtlPacket* func_002bd780(BtlUnit* unit, u16 id);
BtlPacket* FUN_002bdbd0(BtlUnit* source, BtlUnit* target, s32 id, u32 a, u32 b, u32 c, u32 d, void* result);
BtlPacket* FUN_002baf90(u32 id, BtlUnit* source, BtlUnit* target, u32 a, u32 b);
BtlPacket* FUN_002bddd0(void);
BtlPacket* FUN_002dd100(u32 a, u32 b, u32 c);
BtlPacket* FUN_002d7e20(BtlAction* action, BtlAction* target, void* result, u32 a, u32 b);
extern f32 D_00693300[];
s64 FUN_002dc670(BtlAction* action);
u32 FUN_002dc130(BtlAction* action);
BtlPacket* FUN_002dd5e0();
BtlPacket* FUN_002e2be0();
BtlPacket* func_002e3fe0(u16 voiceId);
u32 FUN_002e4310();
BtlPacket* FUN_0027dc00();
BtlPacket* FUN_0029fa50();
BtlPacket* FUN_002a1080();
BtlPacket* FUN_002a16c0();
BtlPacket* FUN_002d7fb0(BtlAction* action, u32 arg);
BtlPacket* FUN_002e40d0();
BtlPacket* FUN_002e41d0();
u32 FUN_002e43a0();
BtlAction* FUN_0029ad20();
BtlPacket* FUN_002a1db0();
BtlPacket* FUN_002bc7e0();
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0956;
extern u16 DAT_007e0958;
extern u8* iGpffffb708;
extern BtlCommandRecord* iGpffffb710;
extern BtlEnemyRecord* iGpffffb728;
extern f32 uGpffff8088;
extern f32 uGpffff8390;
extern f32 uGpffff83a4;
extern RwV3d D_00697880;

u32 FUN_002d5bf0(BtlUnit* unit);
u32 FUN_002d6370(s16 commandId);
void FUN_002fd8a0(BtlAction* action);
u8 FUN_003093a0(DatUnit* unit);
u16 FUN_003082f0(DatUnit* unit, u64 id);
void FUN_004c6c60(RwV3d* dst, const RwV3d* src, const RwMatrix* matrix);

void FUN_002899e0(BtlAction* action);
void FUN_00289b50(BtlAction* action);
u32 FUN_00289f40(BtlAction* action);
u16 FUN_0028a0f0(BtlAction* action);
u32 FUN_0028a200(BtlAction* action);
u32 FUN_0028a3e0(BtlAction* action);
void FUN_0028a540(BtlAction* action, u64 id, u16* out1, u16* out2, u16* out3, u16* out4);


void btlActionInitStateNon(BtlAction* action);
void btlActionUpdateStateNon(BtlAction* action);
void btlActionInitStateStandBy(BtlAction* action);
void btlActionUpdateStateStandBy(BtlAction* action);
void btlActionInitStateStart(BtlAction* action);
void btlActionUpdateStateStart(BtlAction* action);
void btlActionInitStateStartHome(BtlAction* action);
void btlActionUpdateStateStartHome(BtlAction* action);
void btlActionInitStateChangeFormation(BtlAction* action);
void btlActionUpdateStateChangeFormation(BtlAction* action);
void btlActionInitStateCommand(BtlAction* action);
void btlActionUpdateStateCommand(BtlAction* action);
void btlActionInitStateTarget(BtlAction* action);
void btlActionUpdateStateTarget(BtlAction* action);
void btlActionInitStateAnalyze(BtlAction* action);
void btlActionUpdateStateAnalyze(BtlAction* action);
void btlActionInitStateAI(BtlAction* action);
void btlActionUpdateStateAI(BtlAction* action);
void btlActionInitStateAuto(BtlAction* action);
void btlActionUpdateStateAuto(BtlAction* action);
void btlActionInitStateSupport(BtlAction* action);
void btlActionUpdateStateSupport(BtlAction* action);
void btlActionInitStateBad(BtlAction* action);
void btlActionUpdateStateBad(BtlAction* action);
void btlActionInitStateReady(BtlAction* action);
void btlActionUpdateStateReady(BtlAction* action);
void btlActionInitStateMoveTarget(BtlAction* action);
void btlActionUpdateStateMoveTarget(BtlAction* action);
void btlActionInitStateMoveHome(BtlAction* action);
void btlActionUpdateStateMoveHome(BtlAction* action);
void btlActionInitStateAttack(BtlAction* action);
void btlActionUpdateStateAttack(BtlAction* action);
void btlActionInitStateSkill(BtlAction* action);
void btlActionUpdateStateSkill(BtlAction* action);
void btlActionInitStateReinforce(BtlAction* action);
void btlActionUpdateStateReinforce(BtlAction* action);
void btlActionInitStateSummon(BtlAction* action);
void btlActionUpdateStateSummon(BtlAction* action);
void btlActionInitStateAssist(BtlAction* action);
void btlActionUpdateStateAssist(BtlAction* action);
void btlActionInitStateEvent(BtlAction* action);
void btlActionUpdateStateEvent(BtlAction* action);
void btlActionInitStateError(BtlAction* action);
void btlActionUpdateStateError(BtlAction* action);
void btlActionInitStateEndure(BtlAction* action);
void btlActionUpdateStateEndure(BtlAction* action);
void btlActionInitStateWait(BtlAction* action);
void btlActionUpdateStateWait(BtlAction* action);
void btlActionInitStatePersona(BtlAction* action);
void btlActionUpdateStatePersona(BtlAction* action);
void btlActionInitStateBadDamage(BtlAction* action);
void btlActionUpdateStateBadDamage(BtlAction* action);
void btlActionInitStateEscapeMes(BtlAction* action);
void btlActionUpdateStateEscapeMes(BtlAction* action);
void btlActionInitStateEscape(BtlAction* action);
void btlActionUpdateStateEscape(BtlAction* action);
void btlActionInitStateRoundUpMes(BtlAction* action);
void btlActionUpdateStateRoundUpMes(BtlAction* action);
void btlActionInitStateRoundUp(BtlAction* action);
void btlActionUpdateStateRoundUp(BtlAction* action);
void btlActionInitStatePacket(BtlAction* action);
void btlActionUpdateStatePacket(BtlAction* action);
void btlActionInitStateEnd(BtlAction* action);
void btlActionUpdateStateEnd(BtlAction* action);
void btlActionInitStateEndHome(BtlAction* action);
void btlActionUpdateStateEndHome(BtlAction* action);
void btlActionInitStateDead(BtlAction* action);
void btlActionUpdateStateDead(BtlAction* action);
void btlActionInitStateExit(BtlAction* action);
void btlActionUpdateStateExit(BtlAction* action);
void btlActionInitStateTest(BtlAction* action);
void btlActionUpdateStateTest(BtlAction* action);

void btlActionSetStateWithDelay(BtlAction* action, u16 btlState, u16 delay);
void btlAction00299e50(BtlAction* action);
void FUN_002dc5e0();
void FUN_001fdd40();
u16 FUN_002bff60(BtlAction* action, BtlTarget* target, u16 commandId, u32 param_4);
u32 FUN_002c0970(BtlTarget* target);
u32 FUN_002e4330(BtlAction* action);
u32 FUN_002e43a0();
BtlAction* FUN_002c0880(BtlTarget* target);
void FUN_002c08a0(BtlTarget* target, BtlAction* action);
u32 FUN_002c08c0(BtlTarget* target);
u32 FUN_002c7250(BtlTarget* target);
void FUN_002c70d0(BtlAction* action, BtlTarget* target);
u32 FUN_002c7280(BtlTarget* target);
BtlPacket* FUN_002db740(BtlAction* action, u16 param_2, u32 param_3, u32 param_4, u32 param_5);
u16 FUN_00308930(DatUnit* unit);

// 12 bytes
typedef struct
{
    void (*init)(BtlAction* action);   // 0x00
    void (*update)(BtlAction* action); // 0x04
    const char* name;                  // 0x08
} BtlActionStateEntry;

// 00693410
static const BtlActionStateEntry sActionStateTable[] =
{
    {btlActionInitStateNon, btlActionUpdateStateNon, "NON"},
    {btlActionInitStateStandBy, btlActionUpdateStateStandBy, "STANDBY"},
    {btlActionInitStateStart, btlActionUpdateStateStart, "START"},
    {btlActionInitStateStartHome, btlActionUpdateStateStartHome, "START HOME"},
    {btlActionInitStateChangeFormation, btlActionUpdateStateChangeFormation, "CHANGE FORMATION"},
    {btlActionInitStateCommand, btlActionUpdateStateCommand, "COMMAND"},
    {btlActionInitStateTarget, btlActionUpdateStateTarget, "TARGET"},
    {btlActionInitStateAnalyze, btlActionUpdateStateAnalyze, "ANALYZE"},
    {btlActionInitStateAI, btlActionUpdateStateAI, "AI"},
    {btlActionInitStateAuto, btlActionUpdateStateAuto, "AUTO"},
    {btlActionInitStateSupport, btlActionUpdateStateSupport, "SUPPORT"},
    {btlActionInitStateBad, btlActionUpdateStateBad, "BAD"},
    {btlActionInitStateReady, btlActionUpdateStateReady, "READY"},
    {btlActionInitStateMoveTarget, btlActionUpdateStateMoveTarget, "MOVE TARGET"},
    {btlActionInitStateMoveHome, btlActionUpdateStateMoveHome, "MOVE HOME"},
    {btlActionInitStateAttack, btlActionUpdateStateAttack, "ATTACK"},
    {btlActionInitStateSkill, btlActionUpdateStateSkill, "SKILL"},
    {btlActionInitStateReinforce, btlActionUpdateStateReinforce, "REINFORCE"},
    {btlActionInitStateSummon, btlActionUpdateStateSummon, "SUMMON"},
    {btlActionInitStateAssist, btlActionUpdateStateAssist, "ASSIST"},
    {btlActionInitStateEvent, btlActionUpdateStateEvent, "EVENT"},
    {btlActionInitStateError, btlActionUpdateStateError, "ERROR"},
    {btlActionInitStateEndure, btlActionUpdateStateEndure, "ENDURE"},
    {btlActionInitStateWait, btlActionUpdateStateWait, "WAIT"},
    {btlActionInitStatePersona, btlActionUpdateStatePersona, "PERSONA"},
    {btlActionInitStateBadDamage, btlActionUpdateStateBadDamage, "BAD DAMAGE"},
    {btlActionInitStateEscapeMes, btlActionUpdateStateEscapeMes, "ESCAPE MES"},
    {btlActionInitStateEscape, btlActionUpdateStateEscape, "ESCAPE"},
    {btlActionInitStateRoundUpMes, btlActionUpdateStateRoundUpMes, "ROUNDUP MES"},
    {btlActionInitStateRoundUp, btlActionUpdateStateRoundUp, "ROUNDUP"},
    {btlActionInitStatePacket, btlActionUpdateStatePacket, "PACKET"},
    {btlActionInitStateEnd, btlActionUpdateStateEnd, "END"},
    {btlActionInitStateEndHome, btlActionUpdateStateEndHome, "END HOME"},
    {btlActionInitStateDead, btlActionUpdateStateDead, "DEAD"},
    {btlActionInitStateExit, btlActionUpdateStateExit, "EXIT"},
    {btlActionInitStateTest, btlActionUpdateStateTest, "TEST"}
};

static u32 sNextId = 1; // 007cc530

// FUN_00289860
u32 btlActionIdleWeaponAnim(BtlAction* action)
{
    BtlPacket* animPacket;

    if (action->idleWeaponAnimTimer < 0)
    {
        action->idleWeaponAnimTimer = (effMiscRand(NULL) % 240) + 120; // [120;359]
    }

    if (action->idleWeaponAnimTimer == 0)
    {
        if (!btlUnit00282c60(action->unit))
        {
            return false;
        }
        if (datCalcChkBadStatus(action->unit->datUnit, UNIT_BADSTATUS_DOWN))
        {
            return false;
        }
        if (datCalcChkBadStatus(action->unit->datUnit, 0xFFFFF))
        {
            return false;
        }
        if (datCalcIsLowHp(action->unit->datUnit) || datCalcIsDead(action->unit->datUnit, 0))
        {
            return false;
        }

        if (btlUnitGetAnimFrame(action->unit) < 4)
        {
            animPacket = btlUnitCreateAnimPacket(action->unit,
                                                 BTLUNIT_ANIM_IDLEWEAPON,
                                                 4,
                                                 1.0f,
                                                 BTLUNIT_ANIM_MODE_ONCE);
            btlPacketRegister(animPacket, BTLPACKET_TYPE_1);

            action->idleWeaponAnimTimer = -1;
        }

        return true;
    }
    else
    {
        action->idleWeaponAnimTimer--;
    }

    return false;
}

// FUN_002899e0
void FUN_002899e0(BtlAction* action)
{
    BtlAction* current;
    BtlUnit* unit;
    RwV3d target;

    for (current = gBtl->actionList.tail; current != NULL; current = current->prev)
    {
        if ((current->unk_1a & 1) == 0)
        {
            continue;
        }

        unit = current->unit;
        if ((unit->flags3 & BTLUNIT_FLAG3_UNK08) == 0 ||
            btlUnit00282c60(unit) == 0 ||
            btlUnitIsMoving(unit) != 0 ||
            datCalcChkBadStatus(unit->datUnit, 0x100000) != 0 ||
            datCalcChkBadStatus(unit->datUnit, 0xfffff) != 0 ||
            datCalcIsLowHp(unit->datUnit) != 0 ||
            datCalcIsDead(unit->datUnit, 0) != 0)
        {
            continue;
        }

        switch (current->currState)
        {
            case BTLACTION_STATE_STANDBY:
            case BTLACTION_STATE_COMMAND:
            case BTLACTION_STATE_TARGET:
                break;
            default:
                continue;
        }
        if (action == current)
        {
            continue;
        }

        btlUnit0027f7c0(unit, NULL, NULL, &target);
        btlPacketRegister(btlUnitCreateLookAtPacket(unit, &target, 0), BTLPACKET_TYPE_1);
    }
}

// FUN_00289b50 NONMATCHING
void FUN_00289b50(BtlAction* action)
{
    BtlAction* current;
    BtlUnit* unit;
    BtlPacket* movePacket;
    BtlPacket* rotatePacket;
    RwV3d home;
    RwV3d target;
    RwV3d direction;
    RwV3d destination;
    RwMatrix rotation;
    f32 distance;
    f32 angle;
    f32 speed;

    for (current = gBtl->actionList.tail; current != NULL; current = current->prev)
    {
        if ((current->unk_1a & 1) == 0)
        {
            continue;
        }

        unit = current->unit;
        if (unit->genus != 0)
        {
            continue;
        }
        if ((unit->flags3 & BTLUNIT_FLAG3_UNK08) == 0 ||
            btlUnit00282c60(unit) == 0 ||
            btlUnitIsMoving(unit) != 0 ||
            datCalcChkBadStatus(unit->datUnit, 0x100000) != 0 ||
            datCalcChkBadStatus(unit->datUnit, 0xfffff) != 0 ||
            datCalcIsLowHp(unit->datUnit) != 0 ||
            datCalcIsDead(unit->datUnit, 0) != 0)
        {
            continue;
        }
        if (current->currState != BTLACTION_STATE_TARGET &&
            current->currState != BTLACTION_STATE_COMMAND &&
            current->currState != BTLACTION_STATE_STANDBY)
        {
            continue;
        }
        if (btlActionIdleWeaponAnim(current) != 0 ||
            (gBtl->flags & BTL_FLAG_MULTIENEMY) == 0)
        {
            continue;
        }
        if (current->rand != 0)
        {
            current->rand--;
            continue;
        }
        if (current == action || unit->charId == 4)
        {
            continue;
        }

        btlUnit0027f7c0(unit, &home, NULL, &target);
        direction.x = target.x - home.x;
        direction.y = target.y - home.y;
        direction.z = target.z - home.z;
        distance = RwV3dNormalize(&direction, &direction);

        current->unk_34++;
        if ((current->unk_34 & 1) == 0)
        {
            angle = -(effMiscRandFloat(NULL) * 10.0f + 5.0f);
        }
        else
        {
            angle = effMiscRandFloat(NULL) * 10.0f + 5.0f;
        }
        RwMatrixRotate(&rotation, &D_00697880, angle, rwCOMBINEREPLACE);
        FUN_004c6c60(&direction, &direction, &rotation);

        destination.x = target.x + direction.x * distance;
        destination.y = target.y + direction.y * distance;
        destination.z = target.z + direction.z * distance;

        switch (unit->charId)
        {
        case 2:
            speed = uGpffff83a4;
            break;
        case 5:
            speed = uGpffff8390;
            break;
        default:
            speed = uGpffff8088;
            break;
        }

        movePacket = btlUnitCreateMovePacket(unit, &destination, speed, 8);
        movePacket->actionUID = current->uid;
        btlPacketRegister(movePacket, BTLPACKET_TYPE_1);

        rotatePacket = btlUnitCreateRotatePacket(unit, &target, 0);
        rotatePacket->unk_00 = 4;
        rotatePacket->parentUID = movePacket->uid;
        rotatePacket->actionUID = current->uid;
        btlPacketRegister(rotatePacket, BTLPACKET_TYPE_1);

        current->rand = datCalcRand(0xb4) + 0x3c;
    }
}

// FUN_00289f40
u32 FUN_00289f40(BtlAction* action)
{
    u16 specificId;
    u16 unitId;
    u16 validationResult;
    u8 allowed;

    specificId = action->target.specificId;
    validationResult = FUN_002bff60(action, NULL, specificId, 0);
    unitId = action->unit->datUnit->id;
    if (validationResult == 0)
    {
        allowed = iGpffffb708[(u32)specificId * 0x2c];
        if ((allowed & 2) != 0)
        {
            switch (action->unit->genus)
            {
            case 1:
                if (iGpffffb728[unitId].field_22 == 1)
                {
                    return false;
                }
                break;
            default:
                break;
            }
            return true;
        }

        if (FUN_002d6370(specificId) != 0)
        {
            if ((iGpffffb710[specificId].flags & 1) == 0)
            {
                return false;
            }
            switch (action->unit->genus)
            {
            case 0:
            default:
                break;
            case 1:
                if (iGpffffb728[unitId].field_26 == 1)
                {
                    return false;
                }
                break;
            }
            return true;
        }
    }

    return false;
}

// FUN_0028a0f0
u16 FUN_0028a0f0(BtlAction* action)
{
    u16 unitId = action->unit->datUnit->id;
    u8 genus = action->unit->genus;
    u8 weaponType;

    if (genus == 1)
    {
        goto player_unit;
    }
    switch (genus)
    {
    case 0:
        goto enemy_unit;
    default:
        goto no_restriction;
    }

enemy_unit:
    if (unitId == 2 || unitId == 3 || FUN_002d5bf0(action->unit) != 0)
    {
        return 1;
    }
    weaponType = (u8)datCalcGetHeldWeaponType(action->unit->datUnit);
    if (unitId == 1 && (weaponType == 6 || weaponType == 7))
    {
        return 1;
    }
    goto no_restriction;

player_unit:
    if (iGpffffb728[unitId].field_22 == 1)
    {
        return 1;
    }

no_restriction:
    return 0;
}

// FUN_0028a200
u32 FUN_0028a200(BtlAction* action)
{
    BtlAction* root = gBtl->actionList.head;
    BtlAction* current;
    BtlUnit* unit;
    u16 enemyCount;

    if (datCalcIsDead(root->unit->datUnit, 0) != 0 ||
        datCalcChkBadStatus(root->unit->datUnit, 0x100261) != 0)
    {
        return false;
    }
    if (action->unit->genus == 1 &&
        datCalcIsDead(action->unit->datUnit, 0) != 0)
    {
        return false;
    }

    ACTION_U16(gBtl, 0xb98) = 0;
    enemyCount = 0;
    for (current = gBtl->actionList.tail; current != NULL; current = current->prev)
    {
        if ((current->unk_1a & 1) == 0)
        {
            continue;
        }

        unit = current->unit;
        if ((unit->flags3 & BTLUNIT_FLAG3_UNK08) == 0 ||
            datCalcIsDead(unit->datUnit, 0) != 0)
        {
            continue;
        }

        if (unit->genus == 1)
        {
            if (datCalcChkBadStatus(unit->datUnit, 0x100000) == 0)
            {
                return false;
            }
            enemyCount++;
        }
        else if (datCalcChkBadStatus(unit->datUnit, 0x100261) == 0 && root != current)
        {
            *(u32*)((u8*)gBtl + ACTION_U16(gBtl, 0xb98) * 4 + 0xb88) = (u32)current;
            ACTION_U16(gBtl, 0xb98)++;
        }
    }

    if (enemyCount == 0)
    {
        return false;
    }
    return ACTION_U16(gBtl, 0xb98) >= 1;
}

// FUN_0028a3e0 NONMATCHING
u32 FUN_0028a3e0(BtlAction* action)
{
    BtlAction* target;
    u16 i;
    u16 j;
    u8 count;

    if (action->unit->genus == 1)
    {
        for (i = 0; i < action->target.targetedCount; i++)
        {
            target = action->target.targetedActions[i];
            count = ACTION_U8(target, 0xc8);
            for (j = 0; j < count; j++)
            {
                if ((ACTION_U16(target, 0xfa + j * 0x1c) & 4) != 0)
                {
                    return true;
                }
            }
        }
    }
    else if (action->unit->genus == 0)
    {
        for (i = 0; i < action->target.targetedCount; i++)
        {
            target = action->target.targetedActions[i];
            count = ACTION_U8(target, 0xc8);
            for (j = 0; j < count; j++)
            {
                if ((ACTION_U32(target, 0xe8 + j * 0x1c) & 0x100000) != 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

// FUN_0028a540 NONMATCHING
void FUN_0028a540(BtlAction* action, u64 id, u16* out1, u16* out2, u16* out3, u16* out4)
{
    BtlUnit* unit;
    u16 itemId = (u16)id;
    u16 type;
    u8 variant;

    *out1 = 0;
    *out2 = 1;
    *out3 = 7;
    *out4 = 9;

    if ((iGpffffb708[(u32)itemId * 0x2c] & 2) == 0)
    {
        return;
    }

    unit = action->unit;
    if (unit->genus == 0 &&
        (unit->datUnit->id == 3 || FUN_002d5bf0(unit) != 0))
    {
        variant = FUN_003093a0(unit->datUnit);
        if (variant == 3)
        {
            *out1 = 0x10;
            *out2 = 0x13;
            *out3 = 0x16;
            *out4 = 0x19;
        }
        else if (variant == 2)
        {
            *out1 = 0xf;
            *out2 = 0x12;
            *out3 = 0x15;
            *out4 = 0x18;
        }
        else
        {
            *out1 = 0xe;
            *out2 = 0x11;
            *out3 = 0x14;
            *out4 = 0x17;
        }
        return;
    }

    type = FUN_003082f0(unit->datUnit, id);
    switch (type)
    {
    case 0:
    case 3:
        *out1 = 2;
        *out2 = 3;
        *out3 = 6;
        *out4 = 8;
        break;
    case 2:
    case 6:
        *out1 = 4;
        *out2 = 5;
        *out3 = 7;
        *out4 = 9;
        break;
    default:
        break;
    }
}

// FUN_0028a780 NONMATCHING
void btlAction0028a780(BtlAction* action)
{
    BtlAction* current;
    BtlPacket* packet;

    if ((gBtl->flags & 0x400000) == 0)
    {
        return;
    }
    if (BATTLE_U16(0x18) & 0x20)
    {
        packet = btlUnitCreateLookAtDeactivatePacket(NULL, 3);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    if (BATTLE_U16(0x18) & 2)
    {
        packet = btlFormation002b8d60(3, 0xfff);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
    }
    if (BATTLE_U16(0x18) & 1)
    {
        for (current = gBtl->actionList.tail; current != NULL; current = current->prev)
        {
            if ((current->unk_1a & 1) && FUN_0030b5a0(current->unit->datUnit, 0) == 0)
            {
                packet = FUN_002843e0(current->unit, 0);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
        }
    }
    if (BATTLE_U16(0x18) & 0x10)
    {
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    if (BATTLE_U16(0x18) & 8)
    {
        packet = FUN_002bc7e0(8);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    if (BATTLE_U16(0x18) & 4)
    {
        packet = btlCameraCreateSetStatePacket(action, 0x1f);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
    }
    BATTLE_U16(0x18) = 0;
    gBtl->flags &= ~0x400000;
}

// FUN_0028a990
void btlActionInitStateNon(BtlAction* action)
{
    // nothing
}
// FUN_0028a9a0
void btlActionUpdateStateNon(BtlAction* action)
{
    // nothing
}

// FUN_0028a9b0
void btlActionInitStateStandBy(BtlAction* action)
{
    // nothing
}
// FUN_0028a9c0
void btlActionUpdateStateStandBy(BtlAction* action)
{
    BtlUnit* unit;

    unit = action->unit;

    if (unit->flags3 & BTLUNIT_FLAG3_ENDURE)
    {
        btlActionSetState(action, BTLACTION_STATE_ENDURE);
        return;
    }

    if (unit->flags3 & BTLUNIT_FLAG3_DEAD)
    {
        btlActionSetState(action, BTLACTION_STATE_DEAD);
    }
}

// FUN_0028aa20 NONMATCHING
void btlActionInitStateStart(BtlAction* action)
{
    BtlUnit* unit = action->unit;
    u32 flags;

    if (action->unk_18 & 0x8000)
    {
        btlActionSetState(action, BTLACTION_STATE_END);
        return;
    }
    FUN_002d5e00(&action->unkData3[0x40]);
    if (FUN_002e42e0(action) != 0)
    {
        action->evtFunc = FUN_002e4310;
        action->stateAfterEvt = BTLACTION_STATE_START;
        btlActionSetState(action, BTLACTION_STATE_EVENT);
        return;
    }
    if (unit->genus == UNIT_GENUS_PC && ACTION_S16(gBtl, 0xa38) != -1 &&
        ((u32)(ACTION_S16(gBtl, 0xa3a) >> 1) >= (FUN_002d4e10(2, 0x80000) & 0xffff)) &&
        ACTION_S16(gBtl, 0xa38) != FUN_002b7060() && FUN_00300580(unit->datUnit, 0x180000) == 0)
    {
        btlActionSetStateWithDelay(action, BTLACTION_STATE_CHANGEFORMA, 1);
        return;
    }
    flags = gBtl->flags;
    if (FUN_001feec0() == 0 && FUN_002d1a70() == 1)
    {
        gBtl->flags |= 0x4000;
    }
    else
    {
        gBtl->flags &= ~0x4000;
        FUN_002d1a10();
    }
    if (action->unk_28 == 0)
    {
        action->unk_18 |= 0x400;
        action->unk_1a &= ~0x40;
    }
    else if ((ACTION_U32(gBtl, 0x10) & 0x20) == 0)
    {
        FUN_001fef30(unit->genus != UNIT_GENUS_PC);
        btlPacketRegister(btlVoice002e2be0(action, 9, 0, 0, 0), BTLPACKET_TYPE_1);
    }
    action->passiveSkillsFlags = action->unk_28 == 0 && ACTION_U8(action, 0x29) == 0 ?
                                      FUN_00300d80(unit->datUnit) : 0;
    if (action->passiveSkillsFlags == 0 && (flags & 0x80000) == 0)
    {
        btlActionSetState(action, (s8)FUN_00302f50(unit->datUnit) < 0 ?
                                  (FUN_002dc070(action) ? BTLACTION_STATE_BAD : action->unk_14) :
                                  BTLACTION_STATE_SUPPORT);
    }
}
// FUN_0028b230 NONMATCHING
void btlActionUpdateStateStart(BtlAction* action)
{
    BtlPacket* packet;
BtlPacket* result;
    BtlPacket* chain;
    s32 work[2];
    s32 stat;
    u32 messageId;
    u32 tableIndex;
    s16 voice;
    if (!(gBtl->flags & 0x80000) && !btlPacketCountById(0x700) && !btlPacketCountById(0x504) &&
        !btlPacketCountById(0x506) && !btlPacketCountById(0x301) && !btlPacketCountById(0x104))
    {
    if (action->passiveSkillsFlags != 0)
    {
        btlAction0028a780(action);
        FUN_002d5dc0(work);
        messageId = 0;
        tableIndex = 0;
        stat = datCalcGetMaxHp(action->unit->datUnit) & 0xffff;
        FUN_00300100(action->unit->datUnit);
        voice = -1;
        if (action->passiveSkillsFlags & 1)
        {
            messageId = 0x223;
            voice = 0xb;
            tableIndex = 0x2f;
            work[0] = stat * 100 / 5000;
            action->passiveSkillsFlags &= ~1;
        }
        else if (action->passiveSkillsFlags & 2)
        {
            messageId = 0x224;
            voice = 0xb;
            tableIndex = 0x2f;
            work[0] = stat * 100 / 0x9c4;
            action->passiveSkillsFlags &= ~2;
        }
        else if (action->passiveSkillsFlags & 4)
        {
            messageId = 0x225;
            voice = 0xb;
            tableIndex = 0x30;
            work[0] = stat * 100 / 0x682;
            action->passiveSkillsFlags &= ~4;
        }
        else if (action->passiveSkillsFlags & 8)
        {
            messageId = 0x226;
            voice = 0xb;
            tableIndex = 0x30;
            work[1] = 3;
            action->passiveSkillsFlags &= ~8;
        }
        else if (action->passiveSkillsFlags & 0x10)
        {
            messageId = 0x227;
            voice = 0xb;
            tableIndex = 0x30;
            work[1] = 5;
            action->passiveSkillsFlags &= ~0x10;
        }
        else if (action->passiveSkillsFlags & 0x20)
        {
            messageId = 0x228;
            voice = 0xb;
            tableIndex = 0x30;
            work[1] = 7;
            action->passiveSkillsFlags &= ~0x20;
        }
        else if (action->passiveSkillsFlags & 0x40)
        {
            messageId = 0x25f;
            voice = 10;
            tableIndex = 0x39;
            work[0] = stat * 100 / 0x4e2;
            action->passiveSkillsFlags &= ~0x40;
        }
        else if (action->passiveSkillsFlags & 0x80)
        {
            messageId = 0x260;
            voice = 10;
            tableIndex = 0x39;
            work[0] = stat * 100 / 0x4e2;
            action->passiveSkillsFlags &= ~0x80;
        }
        if (work[0] != 0 || work[1] != 0)
        {
            packet = FUN_002bd590(action->unit, messageId);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            packet = FUN_002bd480(action->unit);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            chain = FUN_002baf90(ACTION_U32(gBtl, 0xc24 + tableIndex * 4),
                                 action->unit, action->unit, 1, 0);
            chain->preUpdateDelay = 3;
            chain->actionUID = action->uid;
            btlPacketRegister(chain, BTLPACKET_TYPE_3D);
            if (voice != -1)
            {
                packet = FUN_002dd100(0xc, 2, voice);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            result = FUN_002d7e20(action, action, work, 1, 1);
            result->unk_00 = 0xb;
            result->parentUID = chain->uid;
            result->actionUID = action->uid;
            btlPacketRegister(result, BTLPACKET_TYPE_1);
            packet = FUN_002bdbd0(action->unit, action->unit, -1, 0, 0, 0, 1, work);
            packet->unk_00 = 4;
            packet->parentUID = result->uid;
            packet->unk_47 &= ~0x20;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            if (work[0] != 0)
            {
                packet = FUN_002bd230(action->unit, 0, 0);
                packet->unk_00 = 4;
                packet->parentUID = result->uid;
                packet->unk_47 &= ~0x20;
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_3D);
            }
            packet = btlCameraCreateSetStatePacket(action, 9);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
            return;
        }
    }
    btlActionSetState(action, (s8)FUN_00302f50(action->unit->datUnit) < 0 ?
                              (FUN_002dc070(action) ? BTLACTION_STATE_BAD : BTLACTION_STATE_STARTHOME) :
                              BTLACTION_STATE_SUPPORT);
    }
}

// FUN_0028b800 NONMATCHING
void btlActionInitStateStartHome(BtlAction* action)
{
    BtlPacket* packet;
    RwV3d homePos;

    if ((gBtl->flags & 0x2000) && (action->unk_1a & 1) && action->unit->genus == UNIT_GENUS_PC)
    {
        action->unk_14 = BTLACTION_STATE_AUTO;
    }
    if (FUN_0029a3e0(action) != 0)
    {
        btlActionSetState(action, action->unk_14);
        return;
    }
    btlUnit0027f7c0(action->unit, &homePos, NULL, NULL);
    if (FUN_002d1ed0(&action->unit->pos, &homePos) > 75.0f)
    {
        packet = btlUnitCreateMovePacket(action->unit, &homePos, 2.0f, 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    else
    {
        btlActionSetState(action, action->unk_14);
    }
}
// FUN_0028b9c0
void btlActionUpdateStateStartHome(BtlAction* action)
{
    RwV3d rot;
    BtlPacket* rotPacket;

    if (!btlUnitIsMoving(action->unit))
    {
        btlUnit0027f7c0(action->unit, NULL, NULL, &rot);

        rotPacket = btlUnitCreateRotatePacket(action->unit, &rot, 0);
        rotPacket->actionUID = action->uid;
        btlPacketRegister(rotPacket, BTLPACKET_TYPE_1);

        btlActionSetState(action, action->unk_14);
    }
}

// FUN_0028ba50
void btlActionInitStateChangeFormation(BtlAction* action)
{
    BtlPacket* formPacket1;
    BtlPacket* voicePacket;
    BtlUnit* currUnit;
    u32 hasBadStatus;
    BtlPacket* unitMovePacket;
    BtlPacket* formPacket2;
    BtlPacket* unitPacket1;
    BtlPacket* rotateTowardUnitPacket;
    BtlPacket* cameraStatePacket;

    btlAction0028a780(action);

    formPacket1 = btlFormation002b8f40(1);
    formPacket1->actionUID = action->uid;
    btlPacketRegister(formPacket1, BTLPACKET_TYPE_0);

    if (!action->unk_28)
    {
        voicePacket = btlVoice002e2be0(action, 23, 0, 0, 0);
        btlPacketRegister(voicePacket, BTLPACKET_TYPE_1);
    }

    currUnit = gBtl->unitLists[UNIT_GENUS_PC].head;
    while (currUnit != NULL)
    {
        hasBadStatus = datCalcChkBadStatus(currUnit->datUnit, (UNIT_BADSTATUS_DOWN     |
                                                               UNIT_BADSTATUS_DEAD     |
                                                               UNIT_BADSTATUS_OVERHEAT |
                                                               UNIT_BADSTATUS_SHOCK    |
                                                               UNIT_BADSTATUS_FREEZE   |
                                                               UNIT_BADSTATUS_RAGE     |
                                                               UNIT_BADSTATUS_CHARM));

        if (!hasBadStatus && !datCalcIsDead(currUnit->datUnit, 0))
        {
            unitMovePacket = btlUnitCreateMovePacket(currUnit, NULL, gUnk_007cadd0, 0x18);
            unitMovePacket->unk_00 = 4;
            unitMovePacket->parentUID = formPacket1->uid;
            unitMovePacket->actionUID = action->uid;
            btlPacketRegister(unitMovePacket, BTLPACKET_TYPE_1);
        }

        currUnit = currUnit->next;
    }

    formPacket2 = btlFormation002b8d60(2, 1);
    formPacket2->unk_00 = 4;
    formPacket2->parentUID = formPacket1->uid;
    formPacket2->actionUID = action->uid;
    btlPacketRegister(formPacket2, BTLPACKET_TYPE_0);
    
    currUnit = gBtl->unitLists[UNIT_GENUS_EC].head;
    while (currUnit != NULL)
    {
        if (datCalcIsDead(currUnit->datUnit, 0))
        {
            unitPacket1 = btlUnit00286320(currUnit);
            unitPacket1->unk_00 = 4;
            unitPacket1->parentUID = formPacket1->uid;
            unitPacket1->actionUID = action->uid;
            btlPacketRegister(unitPacket1, BTLPACKET_TYPE_0);
        }
        else
        {
            rotateTowardUnitPacket = btlUnitCreateRotateTowardUnitPacket(currUnit, action->unit, 0x22);
            rotateTowardUnitPacket->unk_00 = 4;
            rotateTowardUnitPacket->parentUID = formPacket1->uid;
            rotateTowardUnitPacket->actionUID = action->uid;
            btlPacketRegister(rotateTowardUnitPacket, BTLPACKET_TYPE_0);
        }

        currUnit = currUnit->next;
    }

    cameraStatePacket = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_CHANGEFORM);
    cameraStatePacket->unk_00 = 4;
    cameraStatePacket->parentUID = formPacket1->uid;
    cameraStatePacket->actionUID = action->uid;
    btlPacketRegister(cameraStatePacket, BTLPACKET_TYPE_0);
}
// FUN_0028bca0
void btlActionUpdateStateChangeFormation(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        btlActionSetState(action, BTLACTION_STATE_START);
    }
}

// FUN_0028bd10
void btlActionInitStateCommand(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit;
    RwV3d rot;

    btlAction0028a780(action);
    if (action->oldState != BTLACTION_STATE_CHANGEFORMA && action->oldState != BTLACTION_STATE_TARGET &&
        action->oldState != BTLACTION_STATE_COMMAND && ACTION_U16(gBtl, 0xf0) != 2)
    {
        btlUnit0027f7c0(action->unit, NULL, NULL, &rot);
        packet = btlUnitCreateRotatePacket(action->unit, &rot, 2);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        for (unit = gBtl->unitLists[UNIT_GENUS_EC].tail; unit != NULL; unit = unit->prev)
        {
            if (!btlUnitIsMoving(unit))
            {
                btlUnit0027f7c0(unit, NULL, NULL, &rot);
                packet = btlUnitCreateRotatePacket(unit, &rot, 2);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
            }
        }
        packet = btlFormation002b8d60(3, 0x8001);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        if (FUN_001feec0() == 0)
        {
            packet = FUN_002db740(action, 0x1d, 0, 0, 0);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
    }
    if (action->unit->genus == UNIT_GENUS_PC)
    {
        packet = btlUnitCreateLookAtUnitPacket(NULL, action->unit, BTLUNIT_LOOKAT_FLAG_ALLENEMY);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    else
    {
        packet = btlUnitCreateLookAtDeactivatePacket(NULL, BTLUNIT_LOOKAT_FLAG_ALLENEMY);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(action->unit, 0), BTLPACKET_TYPE_1);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_COMMAND);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    FUN_002d15a0(&action->target);
    FUN_002bf3f0(action);
    FUN_002899e0(action);
    ACTION_U16(action, 0x484) = 0;
    action->unk_488 = 0;
}
// FUN_0028bf80 NONMATCHING
void btlActionUpdateStateCommand(BtlAction* action)
{
    s16 command;
    u16 effect;
    BtlPacket* packet;

    FUN_00289b50(action);
    FUN_001fef50();
    if (action->unk_488 == 1)
    {
        if (ACTION_U16(action, 0x484) == 0)
        {
            FUN_002bed10();
            action->unk_488 = 0;
        }
        else
        {
            ACTION_U16(action, 0x484)--;
        }
        return;
    }
    if ((DAT_007e094c & 8) == 0 && (DAT_007e0956 & 8) == 0)
    {
        if (gBtl->flags & 0x20000)
        {
            FUN_001fe1a0();
            gBtl->flags &= ~0x20000;
            packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_COMMAND);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }
    }
    else if (FUN_001fe220())
    {
        if (gBtl->flags & 0x20000)
        {
            return;
        }
        FUN_001fe120();
        gBtl->flags |= 0x20000;
        packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_ORDER);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        return;
    }
    command = FUN_002becc0();
    if (command == 8)
    {
        FUN_002d19b0();
        FUN_001fef70();
        FUN_001fea70();
        FUN_002bf650();
        btlActionSetState(action, BTLACTION_STATE_AUTO);
    }
    else if (command == 7)
    {
        FUN_002db420(2);
        btlActionSetState(action, BTLACTION_STATE_ANALYZE);
    }
    else if (command == 5)
    {
        action->unk_18 |= 2;
        FUN_001fef70();
        FUN_001fea70();
        FUN_002bf650();
        btlActionSetState(action, BTLACTION_STATE_READY);
    }
    else if (command == 3)
    {
        effect = 0;
        if (action->target.commandId == 3)
        {
            effect = func_002e4430(action, action->target.specificId, 1);
        }
        else if (action->target.commandId == 1 || action->target.commandId == 2)
        {
            effect = func_002e4430(action, action->target.specificId, 0);
        }
        effect = FUN_002e4720(effect);
        if (effect == 0)
        {
            btlActionSetState(action, BTLACTION_STATE_TARGET);
        }
        else
        {
            FUN_0010a4e0(0, 0xf, 0, 8);
            FUN_002bccd0(action->unit, effect);
            ACTION_U16(action, 0x484) = 0x18;
            action->unk_488 = 1;
        }
    }
}

// FUN_0028c310 NONMATCHING
void btlActionInitStateTarget(BtlAction* action)
{
    BtlTarget* work = (BtlTarget*)action->unkData3;
    BtlAction* selected = NULL;
    BtlPacket* packet;
    u16 specificId = action->target.specificId;
    u8 targetType = ACTION_U8(gBtl, 0x16fc + specificId * 0x2c);

    if (action->target.commandId == 4)
    {
        FUN_002bfcb0(action, work, 2, 0, 0);
        if (specificId == 0)
        {
            specificId = -1;
        }
    }
    else if (targetType == 1 || targetType == 2)
    {
        FUN_002bfcb0(action, work, ACTION_U8(gBtl, 0x16fd + specificId * 0x2c),
                      ACTION_U8(gBtl, 0x16fe + specificId * 0x2c), 0);
    }
    else
    {
        FUN_002bff60(action, work, specificId, 0);
    }
    FUN_002c0970(work);
    if (targetType == 1 || targetType == 2)
    {
        u16 i;
        for (i = 0; i < action->target.targetedCount; i++)
        {
            FUN_001fe7f0(action->target.targetedActions[i]->unit->id);
        }
    }
    else
    {
        FUN_002c0ac0(action, work);
        selected = FUN_002c0880(work);
        FUN_001fe7f0(selected->unit->id);
    }
    FUN_001fe810(specificId);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_TARGET);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    FUN_001fef50();
    FUN_002899e0(action);
    if (selected != NULL)
    {
        btlPacketRegister(btlUnitCreateLookAtUnitPacket(NULL, selected->unit, BTLUNIT_LOOKAT_FLAG_ALLPLAYER), BTLPACKET_TYPE_1);
        btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(selected->unit, 0), BTLPACKET_TYPE_1);
    }
}
// FUN_0028c590 NONMATCHING
void btlActionUpdateStateTarget(BtlAction* action)
{
    BtlTarget* work = (BtlTarget*)action->unkData3;
    BtlAction* selected;
    BtlPacket* packet;
    u16 effect;
    u16 i;
    u8 targetType;

    FUN_00289b50(action);
    if ((DAT_007e094c & 8) == 0 && (DAT_007e0956 & 8) == 0)
    {
        if (gBtl->flags & 0x20000)
        {
            FUN_001fe1a0();
            gBtl->flags &= ~0x20000;
            packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_TARGET);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }
    }
    else if (FUN_001fe220())
    {
        if (gBtl->flags & 0x20000)
        {
            return;
        }
        FUN_001fe120();
        gBtl->flags |= 0x20000;
        packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_ORDER);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        return;
    }
    targetType = ACTION_U8(gBtl, 0x16fc + action->target.specificId * 0x2c);
    if (targetType == 1 || targetType == 2)
    {
        for (i = 0; i < work->targetedCount; i++)
        {
            action->target.targetedActions[i] = work->targetedActions[i];
        }
        action->target.targetedCount = work->targetedCount;
    }
    else
    {
        FUN_002c0070(action, work);
        selected = FUN_002c0880(work);
        action->target.targetedActions[0] = selected;
        action->target.targetedCount = 1;
        FUN_002c08a0(work, selected);
        if (selected->unit->id != FUN_001fe990())
        {
            FUN_001fe970(selected->unit->id);
            btlPacketRegister(btlUnitCreateLookAtUnitPacket(NULL, selected->unit, BTLUNIT_LOOKAT_FLAG_ALLPLAYER), BTLPACKET_TYPE_1);
            btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(selected->unit, 0), BTLPACKET_TYPE_1);
        }
    }
    if ((DAT_007e094e & 0x20) || (DAT_007e0958 & 0x20))
    {
        btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(NULL, BTLUNIT_LOOKAT_FLAG_ALLPLAYER), BTLPACKET_TYPE_1);
        FUN_001fe920();
        FUN_002bed10();
        btlActionSetState(action, BTLACTION_STATE_COMMAND);
        return;
    }
    if ((DAT_007e094e & 0x40) == 0 && (DAT_007e0958 & 0x40) == 0)
    {
        return;
    }
    effect = action->target.commandId == 3 ? FUN_002e4520(action, action->target.specificId, 1) :
             ((action->target.commandId == 1 || action->target.commandId == 2) ? FUN_002e4520(action, action->target.specificId, 0) : 0);
    effect = FUN_002e4720(effect);
    if (effect != 0)
    {
        FUN_0010a4e0(0, 0xf, 0, 8);
        FUN_002bccd0(action->unit, effect);
    }
    else if (action->target.commandId == 4)
    {
        FUN_001fe8d0();
        FUN_002bedd0(action->target.targetedActions[0]);
        btlActionSetState(action, BTLACTION_STATE_COMMAND);
    }
    else
    {
        action->unk_18 |= 2;
        FUN_001fef70();
        FUN_001fea70();
        FUN_001fe8d0();
        FUN_002bf650();
        btlActionSetState(action, BTLACTION_STATE_READY);
    }
}

// FUN_0028c9f0
void btlActionInitStateAnalyze(BtlAction* action)
{
    action->movedAwayFromHome = true;
}
// FUN_0028ca00 NONMATCHING
void btlActionUpdateStateAnalyze(BtlAction* action)
{
    BtlPacket* packet;

    if (btlPacketCountById(0x800) != 0)
    {
        return;
    }
    switch (action->movedAwayFromHome)
    {
        case 1:
            if (btlUnitFindFromId(FUN_002db690()) != NULL)
            {
                FUN_002dba80();
                action->movedAwayFromHome = 2;
            }
            else
            {
                FUN_002dba80();
                action->movedAwayFromHome = 4;
            }
            break;
        case 2:
            if (FUN_001febb0() == 0)
            {
                s32 result = FUN_002dbb00();
                if (result >= 0)
                {
                    FUN_002e2d00(result);
                }
                action->movedAwayFromHome = 3;
            }
            break;
        case 3:
            if ((DAT_007e094e & 0x60) || (DAT_007e0958 & 0x60))
            {
                FUN_001fe350();
                if (FUN_002d1a70() == 1)
                {
                    gBtl->flags |= 0x4000;
                    FUN_001ff370();
                }
                action->movedAwayFromHome = 5;
            }
            break;
        case 4:
            packet = FUN_002db740(action, 10, 0, 0, 0);
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            action->movedAwayFromHome = 6;
            break;
        case 5:
            if (FUN_001febb0() == 0 && FUN_001feb70() == 0)
            {
                action->movedAwayFromHome = 6;
            }
            break;
        case 6:
            FUN_002e2d40();
            if ((action->unk_18 & 4) == 0)
            {
                FUN_001fe4a0();
                FUN_002bed10();
                btlActionSetState(action, action->unk_14);
            }
            else
            {
                gBtl->flags |= 0x400000;
                BATTLE_U16(0x18) |= 0xc;
                btlActionSetState(action, BTLACTION_STATE_PACKET);
            }
            action->movedAwayFromHome = 0;
            break;
    }
}

// FUN_0028cda0
void btlActionInitStateAI(BtlAction* action)
{
    if (action->unit->genus == UNIT_GENUS_PC &&
        *(s8*)&action->unit->datUnit->aiTactic == 7 &&
        FUN_002c08c0((BtlTarget*)action->unkData3) == 0)
    {
        action->unit->datUnit->aiTactic = 1;
        btlPacketRegister(btlVoice002e2be0(action, 0xb, 0, 0, 0), BTLPACKET_TYPE_1);
    }

    btlTargetReset(&action->target);
}
// FUN_0028ce50
void btlActionUpdateStateAI(BtlAction* action)
{
    if (FUN_002c7250(&action->target) == 0)
    {
        FUN_002c70d0(action, &action->target);
    }

    if (FUN_002c7280(&action->target) != 0)
    {
        if ((gBtl->flags & 0x2000) &&
            (gBtl->flags & 0x4000000) &&
            action->unit->genus == UNIT_GENUS_EC &&
            action->target.commandId == 1)
        {
            action->unk_18 |= 0x4000;
        }

        action->unk_18 |= 2;
        btlActionSetState(action, BTLACTION_STATE_READY);
    }
}

// FUN_0028cf20
void btlActionInitStateAuto(BtlAction* action)
{
    btlTargetReset(&action->target);
    FUN_002bff60(action, (BtlTarget*)action->unkData3, 0, 0);
    FUN_002c0970((BtlTarget*)action->unkData3);
}
// FUN_0028cf80
void btlActionUpdateStateAuto(BtlAction* action)
{
    BtlPacket* packet;

    action->target.commandId = 1;
    action->target.specificId = FUN_00308930(action->unit->datUnit);
    action->target.targetedActions[0] = FUN_002c0880((BtlTarget*)action->unkData3);
    action->target.targetedCount = 1;
    FUN_002c08a0((BtlTarget*)action->unkData3, action->target.targetedActions[0]);

    if (action->unit->genus == UNIT_GENUS_PC && action->unit->charId == 1)
    {
        packet = FUN_002db740(action, 1, 0, 0, 0);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }

    if (gBtl->flags & 0x4000000)
    {
        action->unk_18 |= 0x4000;
    }

    action->unk_18 |= 2;
    btlActionSetState(action, BTLACTION_STATE_READY);
}

// FUN_0028d070
void btlActionInitStateSupport(BtlAction* action)
{
    // nothing
}
// FUN_0028d080 NONMATCHING
void btlActionUpdateStateSupport(BtlAction* action)
{
    BtlPacket* packet;
    s32 work[4];
    u8 status;
    u16 messageId = 0;
    u8 special = 0;

    if (btlPacketCountById(0x506) != 0)
    {
        return;
    }
    status = FUN_00302f50(action->unit->datUnit);
    switch (status)
    {
        case 0: case 1: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x16 : 0x17; FUN_00301540(action->unit->datUnit, 0); FUN_00301540(action->unit->datUnit, 1); break;
        case 2: case 4: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x18 : 0x19; FUN_00301540(action->unit->datUnit, 4); FUN_00301540(action->unit->datUnit, 2); break;
        case 3: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x1a : 0x1b; FUN_00301540(action->unit->datUnit, 3); break;
        case 5: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x1c : 0x1d; FUN_00301540(action->unit->datUnit, 5); break;
        case 6: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x1e : 0x1f; FUN_00301540(action->unit->datUnit, 6); break;
        case 7: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x20 : 0x21; FUN_00301540(action->unit->datUnit, 7); break;
        case 8: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x22 : 0x23; FUN_00301540(action->unit->datUnit, 8); break;
        case 9: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x24 : 0x25; FUN_00301540(action->unit->datUnit, 9); special = 1; break;
        case 10: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x26 : 0x27; FUN_00301540(action->unit->datUnit, 10); break;
        case 11: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x46 : 0x47; FUN_00301540(action->unit->datUnit, 11); break;
        case 13: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x5a : 0x5b; FUN_00301540(action->unit->datUnit, 13); break;
        case 14: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x5c : 0x5d; FUN_00301540(action->unit->datUnit, 14); break;
        case 15: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x5e : 0x5f; FUN_00301540(action->unit->datUnit, 15); break;
        case 16: messageId = action->unit->genus == UNIT_GENUS_PC ? 0x60 : 0x61; FUN_00301540(action->unit->datUnit, 16); break;
    }
    if (messageId == 0)
    {
        btlActionSetState(action, FUN_002dc070(action) ? BTLACTION_STATE_BAD : BTLACTION_STATE_STARTHOME);
        return;
    }
    btlAction0028a780(action);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = FUN_002bd850(action->unit, messageId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    if (special)
    {
        FUN_002d5dc0(work);
        work[0] = -((FUN_002ffd70(action->unit->datUnit) & 0xffff) - 1);
        if (work[0] >= 0) work[0] = 0;
        work[1] = -((FUN_002ffd80(action->unit->datUnit) & 0xffff) - 1);
        if (work[1] >= 0) work[1] = 0;
        packet = FUN_002d7e20(action, action, work, 1, 1);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
}

// FUN_0028d560
void btlActionInitStateBad(BtlAction* action)
{
    FUN_002dc5e0();
    action->movedAwayFromHome = true;
    action->unk_488 = 0;
}
// FUN_0028d5a0 NONMATCHING
void btlActionUpdateStateBad(BtlAction* action)
{
    BtlPacket* packet;
    u32 badStatus;
    s32 work[4];
    s32 result;

    if (btlPacketCountById(0x506) != 0 || btlPacketCountById(0x105) != 0)
    {
        return;
    }
    btlAction0028a780(action);
    badStatus = FUN_00300550(action->unit->datUnit);
    if (FUN_00300580(action->unit->datUnit, UNIT_BADSTATUS_DOWN) != 0 && action->unk_488 == 0)
    {
        packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        packet = btlUnitCreateAnimPacket(action->unit, 10, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
        packet->unk_00 = 4;
        packet->parentUID = packet->uid;
        ACTION_U16(packet, 0x48) = 0x1e;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        btlPacketRegister(btlVoice002e2be0(action, 8, 0, 0, 0), BTLPACKET_TYPE_1);
        action->unk_18 |= 0x200;
        action->movedAwayFromHome = 0;
        action->unk_488 = 1;
        return;
    }
    result = FUN_002dc180(action);
    if (result != 0)
    {
        FUN_002d5dc0(work);
        work[3] = result;
        if (result & 0x100)
        {
            work[2] = 0x200;
            btlPacketRegister(btlVoice002e2be0(action, 0x16, 0, 0, 0), BTLPACKET_TYPE_1);
        }
        packet = FUN_002d7e20(action, action, work, 1, 1);
        ACTION_U16(packet, 0x48) = 0x12;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (result & 0x200)
        {
            action->unit->datUnit->aiTactic = 1;
        }
        result = FUN_002dca60(action);
        if (result > 0)
        {
            packet = FUN_002bd850(action->unit, result);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
        }
        return;
    }
    if (action->movedAwayFromHome != 0)
    {
        if ((badStatus & 0x279) == 0)
        {
            btlActionSetStateWithDelay(action, BTLACTION_STATE_STARTHOME, 1);
        }
        else
        {
            FUN_002d1660(action, &action->target, badStatus);
            action->unk_18 |= 2;
            result = FUN_002dc830(action);
            if (result > 0)
            {
                packet = FUN_002bd850(action->unit, result);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            }
            packet = FUN_002db740(action, 0x1e, 0, 0, 0);
            ACTION_U16(packet, 0x48) = 0x25;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            btlActionSetState(action, BTLACTION_STATE_READY);
        }
    }
    else
    {
        btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
    }
}

// FUN_0028dbe0
void btlActionInitStateReady(BtlAction* action)
{
    // nothing
}
// FUN_0028dbf0 NONMATCHING
void btlActionUpdateStateReady(BtlAction* action)
{
    BtlAction* target;
    u16 i;

    if (btlPacketCountById(0x506) != 0)
    {
        return;
    }
    for (i = 0; i < action->target.targetedCount; i++)
    {
        target = action->target.targetedActions[i];
        if (target != action && (target->unk_1a & 1) && FUN_0030b5a0(target->unit->datUnit, 0) == 0 &&
            target->currState != BTLACTION_STATE_STANDBY)
        {
            return;
        }
    }
    if ((action->unk_18 & 4) == 0)
    {
        FUN_002d15e0(action->target.targetedActions);
    }
    action->unk_18 &= ~2;
    switch (action->target.commandId)
    {
        case 1: case 2: case 3: case 9:
            FUN_002d6620(action);
            if (ACTION_U8(gBtl, 0x171c + action->target.specificId * 0x2c) == 10)
            {
                btlActionSetState(action, BTLACTION_STATE_PACKET);
            }
            else if (ACTION_U32(action, 0xd8) == 0)
            {
                if (FUN_00289f40(action) == 0)
                {
                    action->unk_18 |= 0x10;
                    btlActionSetState(action, BTLACTION_STATE_MOVEHOME);
                }
                else
                {
                    action->unk_18 &= ~0x10;
                    btlActionSetState(action, BTLACTION_STATE_MOVETARGET);
                }
            }
            else btlActionSetState(action, BTLACTION_STATE_ERROR);
            break;
        case 5: btlActionSetState(action, BTLACTION_STATE_PERSONA); break;
        case 6: btlActionSetState(action, action->unit->genus == UNIT_GENUS_PC && action->unit->charId != 1 ? BTLACTION_STATE_ESCAPEMES : BTLACTION_STATE_ESCAPE); break;
        case 7: case 8: case 11: btlActionSetState(action, BTLACTION_STATE_WAIT); break;
        case 10: btlActionSetState(action, BTLACTION_STATE_ANALYZE); break;
        case 12: btlActionSetState(action, BTLACTION_STATE_ESCAPE); break;
        default: FUN_0019d3f0((void*)0x693318, 0xaec); break;
    }
    if ((action->target.commandId == 1 || action->target.commandId == 2 || action->target.commandId == 3) &&
        FUN_0028a3e0(action) != 0)
    {
        action->unk_18 |= 8;
    }
    else
    {
        action->unk_18 &= ~8;
    }
}

// FUN_0028df00 NONMATCHING
void btlActionInitStateMoveTarget(BtlAction* action)
{
    BtlAction* target = action->target.targetedActions[0];
    BtlPacket* packet;
    f32 distance;

    packet = btlUnitCreateLookAtUnitPacket(NULL, action->unit, BTLUNIT_LOOKAT_FLAG_ALLPLAYER | BTLUNIT_LOOKAT_FLAG_ALLENEMY);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlUnitCreateLookAtDeactivatePacket(action->unit, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    action->unk_18 |= 0x200;
    if (target == NULL)
    {
        action->unk_18 |= 0x10;
        return;
    }
    distance = FUN_002812d0(action->unit, target->unit, FUN_002d5e10(action) ? 11 : 4);
    if (distance <= 0.0f)
    {
        action->unk_18 |= 0x10;
        return;
    }
    btlAction0028a780(action);
    packet = btlUnitCreateMoveToUnitPacket(action->unit, target->unit, distance, 2.0f,
                                            (action->unk_18 & 0x4000) ? 0x48 : 0x40);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = btlCameraCreateSetStatePacket(action,
                (action->unk_18 & 0x4000) ? BTLCAMERA_STATE_MOVETARET_A : BTLCAMERA_STATE_MOVETARGET);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    action->unk_18 &= ~0x10;
}
// FUN_0028e740
void btlActionUpdateStateMoveTarget(BtlAction* action)
{
    u16 nextState;
    u16 commandId;

    if (btlUnitIsMoving(action->unit) == 0)
    {
        commandId = action->target.commandId;
        if (commandId == 9) goto summon;
        if (commandId == 3) goto skill;
        if (commandId == 2) goto skill;
        switch (commandId)
        {
        case 1:
            goto attack;
        default:
            goto no_action;
        }

attack:
        nextState = BTLACTION_STATE_ATTACK;
        goto set_action;
skill:
        nextState = BTLACTION_STATE_SKILL;
        goto set_action;
summon:
        nextState = BTLACTION_STATE_SUMMON;
        goto set_action;
no_action:
        nextState = BTLACTION_STATE_NON;
set_action:
        btlActionSetState(action, nextState);
    }
}

// FUN_0028e7f0 NONMATCHING
void btlActionInitStateMoveHome(BtlAction* action)
{
    BtlPacket* packet;
    RwV3d homePos;

    if ((gBtl->flags & 0x400000) && (BATTLE_U16(0x18) & 2))
    {
        btlActionUpdateStateMoveTarget(action);
        return;
    }
    btlUnit0027f7c0(action->unit, &homePos, NULL, NULL);
    if (FUN_002d1ed0(&action->unit->pos, &homePos) <= 75.0f)
    {
        btlActionUpdateStateMoveTarget(action);
        return;
    }
    btlAction0028a780(action);
    packet = btlUnitCreateMovePacket(action->unit, &homePos, 2.0f, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_MOVEHOME);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
}
// FUN_0028ea90
void btlActionUpdateStateMoveHome(BtlAction* action)
{
    u16 nextState;
    u16 commandId;

    if (btlUnitIsMoving(action->unit) == 0)
    {
        commandId = action->target.commandId;
        if (commandId == 9) goto summon;
        if (commandId == 3) goto skill;
        if (commandId == 2) goto skill;
        switch (commandId)
        {
        case 1:
            goto attack;
        default:
            goto no_action;
        }

attack:
        nextState = BTLACTION_STATE_ATTACK;
        goto set_action;
skill:
        nextState = BTLACTION_STATE_SKILL;
        goto set_action;
summon:
        nextState = BTLACTION_STATE_SUMMON;
        goto set_action;
no_action:
        nextState = BTLACTION_STATE_NON;
set_action:
        btlActionSetState(action, nextState);
    }
}

// FUN_0028eb40
void btlActionInitStateAttack(BtlAction* action)
{
    (void)action;
}
// FUN_0028eb50 NONMATCHING
void btlActionUpdateStateAttack(BtlAction* action)
{
    BtlAction* victim;
    BtlAction* basis;
    BtlPacket* packet;
    BtlPacket* hitPacket;
    u8 group;
    u8 hit;
    u8 groupCount;
    u8 hitCount;
    f32 speed;

    victim = action->target.targetedActions[0];
    if (victim == NULL)
    {
        btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
        return;
    }
    btlAction0028a780(action);
    speed = (action->unk_18 & 0x4000) ? 1.75f : 1.0f;
    basis = ACTION_U32(victim, 0xd4) != 0 ? action : victim;
    packet = FUN_002bd590(action->unit, action->target.specificId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    packet = btlUnitCreateRotateTowardUnitPacket(action->unit, victim->unit, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    groupCount = ACTION_U8(victim, 0xc8);
    hitCount = (action->unk_18 & 0x4000) ? 1 : groupCount;
    for (group = 0; group < groupCount; group++)
    {
        u8* result = (u8*)victim + 0xe0 + group * 0x1c;
        u16 groupFlags = ACTION_U16(victim, 0xcc);
        u16 resultFlags = ACTION_U16(result, 0x1a);
        u8 attackAnim = resultFlags & 4 ? 11 : 4;
        s16 delay = 0;

        for (hit = 0; hit < hitCount; hit++)
        {
            s16 animLength = btlUnitGetAnimFrame(action->unit);
            packet = btlUnitCreateAnimPacket(action->unit, attackAnim, 4, speed,
                                              attackAnim == 11 ? BTLUNIT_ANIM_MODE_LOOP : BTLUNIT_ANIM_MODE_ONCE);
            ACTION_U16(packet, 0x48) = delay;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            hitPacket = btlUnitCreateAnimPacket(basis->unit, ACTION_U8(result, 0x18), 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
            hitPacket->unk_00 = 4;
            hitPacket->parentUID = packet->uid;
            ACTION_U16(hitPacket, 0x48) = delay;
            hitPacket->actionUID = action->uid;
            btlPacketRegister(hitPacket, BTLPACKET_TYPE_1);
            if ((groupFlags & 4) == 0 && (resultFlags & 4) == 0)
            {
                packet = btlUnitCreateRotateTowardUnitPacket(victim->unit, action->unit, 2);
                packet->unk_00 = 5;
                packet->parentUID = hitPacket->uid;
                packet->unk_47 &= ~0x20;
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            delay += animLength > 0 ? animLength : 4;
        }
        packet = FUN_002d7e20(action, basis, result, ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce));
        ACTION_U16(packet, 0x48) = 0;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002bdbd0(action->unit, basis->unit, action->target.specificId,
                              ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce), group, groupCount, result);
        packet->parentUID = hitPacket->uid;
        packet->unk_47 &= ~0x20;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    }
    btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
}

// FUN_00290bd0
void btlActionInitStateSkill(BtlAction* action)
{
    (void)action;
}
// FUN_00290be0 NONMATCHING
void btlActionUpdateStateSkill(BtlAction* action)
{
    BtlPacket* marker;
    BtlPacket* root;
    BtlPacket* hitPacket;
    BtlAction* victim;
    BtlAction* basis;
    u16 targetIndex;
    u8 hitIndex;
    s16 totalDelay;

    btlAction0028a780(action);
    marker = action->target.commandId == 3 ? FUN_002bd690(action->unit, action->target.unk_38) :
                                             FUN_002bd590(action->unit, action->target.specificId);
    ACTION_U16(marker, 0x48) = 1;
    marker->actionUID = action->uid;
    btlPacketRegister(marker, BTLPACKET_TYPE_2D);
    root = btlUnitCreateAnimPacket(action->unit, 7, 6, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
    root->actionUID = action->uid;
    btlPacketRegister(root, BTLPACKET_TYPE_1);
    marker = btlCameraCreateSetStatePacket(action,
             action->unit->genus == UNIT_GENUS_PC ? BTLCAMERA_STATE_SKILLEXEC_PC : BTLCAMERA_STATE_SKILLEXEC_EC);
    marker->parentUID = root->uid;
    marker->actionUID = action->uid;
    btlPacketRegister(marker, BTLPACKET_TYPE_0);
    action->unk_18 |= 0x200;
    totalDelay = 0;
    for (targetIndex = 0; targetIndex < action->target.targetedCount; targetIndex++)
    {
        u8 hitCount;
        victim = action->target.targetedActions[targetIndex];
        if (victim == NULL)
        {
            continue;
        }
        basis = ACTION_U32(victim, 0xd4) != 0 ? action : victim;
        hitCount = ACTION_U8(victim, 0xc8);
        for (hitIndex = 0; hitIndex < hitCount; hitIndex++)
        {
            u8* result = (u8*)victim + 0xe0 + hitIndex * 0x1c;
            hitPacket = btlUnitCreateAnimPacket(basis->unit, ACTION_U8(result, 0x18), 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
            hitPacket->unk_00 = 0xb;
            hitPacket->parentUID = root->uid;
            ACTION_U16(hitPacket, 0x48) = totalDelay;
            hitPacket->actionUID = action->uid;
            btlPacketRegister(hitPacket, BTLPACKET_TYPE_1);
            marker = FUN_002d7e20(action, basis, result, ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce));
            marker->parentUID = hitPacket->uid;
            ACTION_U16(marker, 0x48) = totalDelay;
            marker->actionUID = action->uid;
            btlPacketRegister(marker, BTLPACKET_TYPE_1);
            marker = FUN_002bdbd0(action->unit, basis->unit, action->target.specificId,
                                  ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce), hitIndex, hitCount, result);
            marker->parentUID = hitPacket->uid;
            ACTION_U16(marker, 0x48) = totalDelay;
            marker->unk_47 &= ~0x20;
            marker->actionUID = action->uid;
            btlPacketRegister(marker, BTLPACKET_TYPE_2D);
            totalDelay += 7;
        }
    }
    marker->parentUID = root->uid;
    marker->actionUID = action->uid;
    btlPacketRegister(marker, BTLPACKET_TYPE_1);
    marker->parentUID = root->uid;
    marker->actionUID = action->uid;
    btlPacketRegister(marker, BTLPACKET_TYPE_1);
    marker->parentUID = root->uid;
    marker->actionUID = action->uid;
    btlPacketRegister(marker, BTLPACKET_TYPE_1);
    btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
}

// FUN_00294d10
void btlActionInitStateReinforce(BtlAction* action)
{
    action->unit->flags3 |= BTLUNIT_FLAG3_UNK08;
    gBtl->unk_a06 &= ~(1 << 0);
}
// FUN_00294d40 NONMATCHING
void btlActionUpdateStateReinforce(BtlAction* action)
{
    BtlPacket* root;
    BtlPacket* packet;
    RwV3d pos;
    RwV3d direction;
    RwV3d destination;

    root = btlVoice002e2be0(action, 0x14, 0, 0, 0);
    btlPacketRegister(root, BTLPACKET_TYPE_1);
    packet = FUN_002db740(action, 6, 0, 0, 2);
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_REINFORCE);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    action->unit->mdl = (Model*)FUN_00316910(action->unit->genus + 1, action->unit->charId, 0);
    if (action->unit->mdl == NULL)
    {
        root = FUN_00285690(action->unit, action->unit->charId, 0x7e);
        root->actionUID = action->uid;
        btlPacketRegister(root, BTLPACKET_TYPE_1);
    }
    else
    {
        action->unit->flags2 |= BTLUNIT_FLAG2_UPDATE | BTLUNIT_FLAG2_DIRTY;
        action->unit->resTypeId = FUN_003b6000(action->unit->charId, action->unit->mdl);
        FUN_001a0590(action->unit->resTypeId, 1);
        FUN_00287b20(action->unit, 1);
        FUN_002831c0(action->unit, 0);
        FUN_00282bc0(action->unit);
    }
    packet = FUN_00285d30(action->unit, -1, 0xc, 0, 3, 1);
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    ACTION_U16(packet, 0x48) = 1;
    ACTION_U16(packet, 0x4a) = 0x2d;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    btlUnit0027f7c0(action->unit, &pos, NULL, &direction);
    destination.x = pos.x + (pos.x - direction.x) * 300.0f;
    destination.y = pos.y;
    destination.z = pos.z + (pos.z - direction.z) * 300.0f;
    packet = btlUnitCreateMovePacket(action->unit, &destination, 0.5f, 0);
    packet->unk_00 = 4;
    packet->parentUID = packet->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    btlActionSetState(action, BTLACTION_STATE_PACKET);
}

// FUN_00295150
void btlActionInitStateSummon(BtlAction* action)
{
    (void)action;
}
// FUN_00295160 NONMATCHING
void btlActionUpdateStateSummon(BtlAction* action)
{
    BtlPacket* packet;
    u16 i;

    packet = FUN_002bd590(action->unit, action->target.specificId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    packet = btlUnitCreateAnimPacket(action->unit, 7, 6, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    for (i = 0; i < 3; i++)
    {
        if (action->target.unk_3e[i] != 0)
        {
            BtlAction* child = (BtlAction*)FUN_00289650(1, action->target.unk_3e[i], 0);
            if (child != NULL && child->unit != NULL)
            {
                child->unit->datUnit = (DatUnit*)FUN_002ff540(ACTION_U32(gBtl, 0xbbc), action->target.unk_3e[i]);
                FUN_002889c0(child->unit, action->target.unk_3e[i]);
            }
        }
    }
    packet = FUN_002db740(action, 5, 0, 0, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    FUN_001fdd40();
    btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
}

// FUN_00295a10
void btlActionInitStateAssist(BtlAction* action)
{
    BtlPacket* packet;

    btlAction0028a780(action);
    FUN_002d15a0(&action->target);
    action->target.commandId = 2;
    action->target.specificId = FUN_002d5bc0();
    FUN_0016f1f0(0x1300, 1);
    FUN_002c3770(action, 0);
    btlAction0028a780(action);
    packet = btlFormation002b8d60(3, 0xfff);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = btlCameraCreateSetStatePacket(action, 0x25);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = FUN_002db740(action, 0xb, 0, 0, 2);
    ACTION_U16(packet, 0x4a) = 100;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    action->unk_18 |= 2;
}
// FUN_00295b20
void btlActionUpdateStateAssist(BtlAction* action)
{
    if (btlPacketCountById(0x506) == 0 && btlPacketCountById(0x800) == 0)
    {
        action->unk_18 |= 0x100;
        btlActionSetState(action, BTLACTION_STATE_READY);
    }
}

// FUN_00295b90
void btlActionInitStateEvent(BtlAction* action)
{
    // nothing
}
// FUN_00295ba0
void btlActionUpdateStateEvent(BtlAction* action)
{
    if (!action->evtFunc())
    {
        btlActionSetState(action, action->stateAfterEvt);
    }
}

// FUN_00295bf0
void btlActionInitStateError(BtlAction* action)
{
    (void)action;
}
// FUN_00295c00 NONMATCHING
void btlActionUpdateStateError(BtlAction* action)
{
    BtlPacket* packet;
    s16 animation;
    s16 duration;
    u32 table;

    btlAction0028a780(action);
    packet = action->target.commandId == 3 ? FUN_002bd690(action->unit, action->target.unk_38) :
                                             FUN_002bd590(action->unit, action->target.specificId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    if (action->unit->genus == UNIT_GENUS_PC)
    {
        animation = action->target.commandId == 3 ? 0x15 : 0xc;
        table = action->target.commandId == 3 ? 0x38 : 0x1c;
        duration = FUN_002838d0(1.0f, action->unit, animation);
    }
    else
    {
        animation = FUN_002d6370(action->target.specificId) == 0 ? 7 : 4;
        table = 0x21;
        duration = FUN_002835e0(1.0f, action->unit, animation);
    }
    packet = btlUnitCreateAnimPacket(action->unit, animation, 6, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
    ACTION_U16(packet, 0x4a) = duration + 6;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002baf90(ACTION_U32(gBtl, 0xc24 + table * 4), action->unit, NULL, 0, packet->uid);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_3D);
    packet = FUN_002bd850(action->unit, ACTION_U16(action, 0xdc));
    packet->unk_00 = 4;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    btlActionSetState(action, FUN_002dc130(action) ? BTLACTION_STATE_BADDMG : BTLACTION_STATE_PACKET);
}

// FUN_00295f00
void btlActionInitStateEndure(BtlAction* action)
{
    u16 skillId;

    action->unit->flags3 &= ~BTLUNIT_FLAG3_ENDURE;

    skillId = *(u16*)&action->unkData3[0x3d8];
    switch (skillId)
    {
        case 0x23b:
            action->unit->datUnit->flags |= 8;
            break;
        case 0x23c:
            action->unit->datUnit->flags |= 0x400;
            break;
    }

    if (*(u16*)&action->unkData3[0x3d8] == 0)
    {
        btlActionSetState(action, BTLACTION_STATE_STANDBY);
    }
}
// FUN_00295fa0 NONMATCHING
void btlActionUpdateStateEndure(BtlAction* action)
{
    BtlPacket* packet;
    s32 work[4];
    u16 skillId;
    u16 messageId;

    if (btlPacketCountById(0xff03) != 0)
    {
        return;
    }
    skillId = ACTION_U16(action, 0x460);
    btlPacketRegister(FUN_0027dc00(0x80000), BTLPACKET_TYPE_0);
    if (skillId == 0x1b6)
    {
        messageId = 0xdf;
    }
    else if (skillId == 0x23c)
    {
        messageId = action->unit->genus == UNIT_GENUS_PC ? 0x42 : 0x43;
    }
    else
    {
        messageId = action->unit->genus == UNIT_GENUS_PC ? 0x40 : 0x41;
    }
    packet = FUN_002bd850(action->unit, messageId);
    ACTION_U16(packet, 0x48) = 8;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    btlPacketRegister(FUN_00284c90(action->unit), BTLPACKET_TYPE_1);
    if (skillId == 0x23c)
    {
        FUN_002d5dc0(work);
        work[0] = (FUN_002ffdf0(action->unit->datUnit) & 0xffff) - (FUN_002ffd70(action->unit->datUnit) & 0xffff);
        packet = FUN_002d7e20(action, action, work, 1, 1);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        btlPacketRegister(FUN_002bdbd0(action->unit, action->unit, -1, 0, 0, 0, 1, work), BTLPACKET_TYPE_2D);
    }
    btlPacketRegister(FUN_0027dc00(0x80000), BTLPACKET_TYPE_0);
    btlActionSetState(action, BTLACTION_STATE_STANDBY);
}

// FUN_00296310
void btlActionInitStateWait(BtlAction* action)
{
    (void)action;
}
// FUN_00296320 NONMATCHING
void btlActionUpdateStateWait(BtlAction* action)
{
    BtlPacket* packet;

    if (action->target.commandId != 11)
    {
        if (action->target.commandId != 8)
        {
            if (action->target.commandId == 7)
            {
                btlAction0028a780(action);
                packet = btlUnitCreateLookAtDeactivatePacket(NULL, 3);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                packet = btlCameraCreateSetStatePacket(action, 9);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                if (ACTION_S16(action, 0xdc) != 0)
                {
                    packet = FUN_002bd850(action->unit, ACTION_S16(action, 0xdc));
                }
                else
                {
                    packet = func_002bd780(action->unit, action->target.commandId);
                }
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
                packet = btlVoice002e2be0(action, 0x1a, 0, 0, 0);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            else
            {
                K_Assert((const char*)0x00693318, 0x1bae);
            }
        }
    }
    btlPacketRegister(FUN_002d7fb0(action, 0), BTLPACKET_TYPE_1);
    if (FUN_002dc130(action) != 0 && action->target.commandId != 8)
    {
        btlActionSetState(action, BTLACTION_STATE_BADDMG);
    }
    else
    {
        btlActionSetState(action, BTLACTION_STATE_PACKET);
    }
}

// FUN_00297480 NONMATCHING
void btlActionInitStatePersona(BtlAction* action)
{
    BtlPacket* packet;
    BtlPacket* root;
    s32 table;

    btlAction0028a780(action);
    packet = func_002bd780(action->unit, action->target.commandId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_PERSONA);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    if (action->unit->genus != UNIT_GENUS_PC)
    {
        goto persona_anim;
    }
    packet = FUN_002843e0(action->unit, 6);
    goto persona_anim_done;
persona_anim:
    packet = btlUnitCreateAnimPacket(action->unit, 0x17, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
persona_anim_done:
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlVoice002e2be0(action, 0x19, 0, 0, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    if (action->unit->genus != UNIT_GENUS_PC)
    {
        goto persona_init_done;
    }
    FUN_00175130(ACTION_U16(action, 0x74));
    btlUnitInitPersona(action->unit, ACTION_U16(action, 0x74));
persona_init_done:
    table = FUN_002fcf50(action);
    if (table == 0)
    {
        table = ACTION_U32(gBtl, 0xca4);
    }
    root = FUN_002baf90(table, action->unit, action->unit, 0, 0);
    ACTION_U16(root, 0x48) = 0xf;
    root->actionUID = action->uid;
    btlPacketRegister(root, BTLPACKET_TYPE_3D);
    packet = FUN_002dd100(10, 2, 4);
    packet->unk_00 = 5;
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    if (action->unit->genus != UNIT_GENUS_PC)
    {
        goto persona_done;
    }
    packet = FUN_002bddd0();
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_3D);
persona_done:
    gBtl->flags |= 0x400000;
    BATTLE_U16(0x18) |= 4;
}
// FUN_002976d0
void btlActionUpdateStatePersona(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        if (action->unit->genus == UNIT_GENUS_PC)
        {
            action->unk_18 &= ~0x400;
        }

        btlActionSetState(action, action->unk_14);
    }
}

// FUN_00297750
void btlActionInitStateBadDamage(BtlAction* action)
{
    (void)action;
}
// FUN_00297760 NONMATCHING
void btlActionUpdateStateBadDamage(BtlAction* action)
{
    BtlPacket* root;
    BtlPacket* packet;
    s32 work;
    s16 damage;

    if (btlPacketCountById(0x700) || btlPacketCountById(0x506) ||
        btlPacketCountById(0x507) || btlPacketCountById(0x301))
    {
        return;
    }
    if ((datCalcGetBadStatus(action->unit->datUnit) & 0xfffff) != 0x80)
    {
        if (action->target.commandId == 2 || action->target.commandId == 3 ||
            action->target.commandId == 1)
        {
            btlActionSetState(action, BTLACTION_STATE_PACKET);
        }
        else
        {
            btlActionSetState(action, BTLACTION_STATE_PACKET);
        }
        return;
    }
    FUN_002d5dc0(&work);
    damage = (s16)FUN_002dc670(action);
    work = damage;
    if (damage < 0)
    {
        root = FUN_002d7e20(action, action, &work, 1, 1);
        btlPacketRegister(root, BTLPACKET_TYPE_1);
        packet = FUN_002bd480(action->unit);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002bdbd0(action->unit, action->unit, -1, 0, 0, 0, 1, &work);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        packet->unk_47 &= ~0x20;
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
        packet = FUN_002bd230(action->unit, 0, 0);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        packet->unk_47 &= ~0x20;
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
        packet = btlUnitCreateAnimPacket(action->unit, BTLUNIT_ANIM_RESNULLIFIED, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002dd100(10, 6, 0xc);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    if (action->target.commandId == 2 || action->target.commandId == 3 ||
        action->target.commandId == 1)
    {
        btlActionSetState(action, BTLACTION_STATE_PACKET);
    }
    else
    {
        btlActionSetState(action, BTLACTION_STATE_PACKET);
    }
}

// FUN_002964f0
void btlActionInitStateEscapeMes(BtlAction* action)
{
    BtlPacket* packet;

    btlAction0028a780(action);
    packet = btlUnitCreateRotateTowardUnitPacket(action->unit, gBtl->actionList.head->unit, 2);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = btlUnitCreateLookAtUnitPacket(gBtl->actionList.head->unit, action->unit, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlUnitCreateLookAtUnitPacket(action->unit, gBtl->actionList.head->unit, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    action->unk_18 |= 0x200;
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_ESCAPEMES);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = func_002e3fe0(action->unit->charId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    if (FUN_002d1a70() == 1)
    {
        gBtl->flags &= ~0x4000;
        FUN_001ff350();
    }
    action->movedAwayFromHome = 0;
    action->unk_488 = 0;
    ACTION_U16(action, 0x48c) = 0xc;
}
// FUN_00296660 NONMATCHING
void btlActionUpdateStateEscapeMes(BtlAction* action)
{
    BtlPacket* packet;

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) != NULL)
    {
        return;
    }
    if (action->movedAwayFromHome == 0)
    {
        btlPacketRegister(FUN_002e40d0(), BTLPACKET_TYPE_1);
        btlPacketRegister(btlVoice002e2be0(action, 1, 0, 0, 0), BTLPACKET_TYPE_1);
        btlPacketRegister(FUN_002dd100(10, 6, 0xb), BTLPACKET_TYPE_1);
        action->movedAwayFromHome = 1;
    }
    if (action->movedAwayFromHome == 1 && ACTION_S16(action, 0x48c) >= 0)
    {
        if (ACTION_S16(action, 0x48c) == 0)
        {
            FUN_001ff160(action->unit->charId);
            ACTION_S16(action, 0x48c) = -1;
        }
        else
        {
            ACTION_S16(action, 0x48c)--;
        }
        return;
    }
    if (action->unk_488 == 0 && FUN_001ff2b0())
    {
        FUN_001ff2f0();
        packet = FUN_002e41d0();
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (FUN_002d1a70() == 1)
        {
            gBtl->flags |= 0x4000;
            FUN_001ff370();
        }
        action->unk_488 = 1;
        return;
    }
    if (action->unk_488 != 0)
    {
        if (FUN_001ff2d0() == 0)
        {
            btlActionSetState(action, BTLACTION_STATE_ESCAPE);
        }
        else
        {
            btlPacketRegister(btlVoice002e2be0(action, 3, 0, 0, 0), BTLPACKET_TYPE_1);
            action->unk_18 |= 0x80;
            btlActionSetState(action, action->target.commandId);
        }
    }
}

// FUN_00296880
void btlActionInitStateEscape(BtlAction* action)
{
    (void)action;
}
// FUN_00296890 NONMATCHING
void btlActionUpdateStateEscape(BtlAction* action)
{
    BtlPacket* root;
    BtlPacket* packet;
    RwV3d destination;
    RwV3d home;

    root = FUN_002bd590(action->unit, action->target.commandId);
    root->actionUID = action->uid;
    btlPacketRegister(root, BTLPACKET_TYPE_2D);
    action->unk_18 |= 0x20;
    action->unk_1a &= ~8;
    btlUnit0027f7c0(action->unit, &home, NULL, NULL);
    destination = action->unit->pos;
    destination.x += (action->unit->pos.x - home.x) * 500.0f;
    destination.z += (action->unit->pos.z - home.z) * 500.0f;
    packet = btlUnitCreateMovePacket(action->unit, &destination, 1.0f, 8);
    packet->unk_00 = 5;
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_00285d30(action->unit, 0xffffff, 8, 0, 4, 0);
    packet->unk_00 = 5;
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002d7fb0(action, 0);
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    btlActionSetState(action, BTLACTION_STATE_PACKET);
}

// FUN_00297a60 NONMATCHING
void btlActionInitStateRoundUpMes(BtlAction* action)
{
    BtlPacket* packet;
    BtlAction* selected = action->unit->genus == UNIT_GENUS_PC ? action : action->target.targetedActions[0];

    if (selected == NULL)
    {
        selected = action;
    }
    packet = btlVoice002e2be0(selected, 0x1d, 0, 0, 0);
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_ROUNDUP);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    action->movedAwayFromHome = (u32)selected;
    action->unk_488 = 0;
    ACTION_U16(action, 0x48c) = 0;
    ACTION_U16(action, 0x490) = 0x12;
}
// FUN_00298060 NONMATCHING
void btlActionUpdateStateRoundUpMes(BtlAction* action)
{
    BtlPacket* packet;
    BtlAction* selected = (BtlAction*)action->movedAwayFromHome;

    if (action->unk_488 == 0)
    {
        if (btlPacketCountById(0xc03) != 0)
        {
            return;
        }
        packet = btlVoice002e2be0(selected, 4, 0, 0, 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        btlPacketRegister(FUN_002dd100(10, 2, 0x12), BTLPACKET_TYPE_1);
        action->unk_488 = 1;
        return;
    }
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        if (ACTION_U16(action, 0x48c) == 0)
        {
            FUN_001ff140();
            action->unk_18 &= ~8;
            ACTION_U16(action, 0x48c) = 1;
        }
        else
        {
            btlActionSetState(action, BTLACTION_STATE_PACKET);
        }
    }
}

// FUN_002984e0
void btlActionInitStateRoundUp(BtlAction* action)
{
    u16 i;

    FUN_002d15a0(&action->target);
    action->target.commandId = 2;
    action->target.specificId = ACTION_U16(gBtl, 0xb98) + 0x13f;
    FUN_002bff60(action, (BtlTarget*)action->unkData3, action->target.specificId, 0);
    i = 0;
    while (i < ACTION_U16(action, 0xc0))
    {
        *(BtlAction**)((int)action + i * 4 + 0x38) = *(BtlAction**)((int)action + i * 4 + 0x88);
        i++;
    }
    action->target.targetedCount = ACTION_U16(action, 0xc0);
    FUN_002d6620(action);
    {
        u32 allInactive = 1;
        u16 j = 0;
        int count = action->target.targetedCount;

        while (j < count)
        {
            BtlAction* target = *((BtlAction**)action + j + 0xe);
            if (ACTION_U32(target, 0xd0) != 0)
            {
                allInactive = 0;
                break;
            }
            j++;
        }
        if (allInactive != 0)
        {
            action->target.specificId = ACTION_U16(gBtl, 0xb98) + 0x14b;
            ACTION_U32(action, 0x498) = 1;
            return;
        }
        ACTION_U32(action, 0x498) = 0;
    }
}
// FUN_00298610 NONMATCHING
void btlActionUpdateStateRoundUp(BtlAction* action)
{
    BtlPacket* root;
    BtlPacket* packet;
    BtlAction* target;
    u16 i;

    root = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_ROUNDUP);
    root->actionUID = action->uid;
    btlPacketRegister(root, BTLPACKET_TYPE_0);
    for (i = 0; i < action->target.targetedCount; i++)
    {
        target = action->target.targetedActions[i];
        if (target == NULL)
        {
            continue;
        }
        packet = FUN_002bd480(target->unit);
        packet->parentUID = root->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002bdbd0(action->unit, target->unit, action->target.specificId,
                              ACTION_U16(target, 0xcc), ACTION_U16(target, 0xce), 0,
                              ACTION_U8(target, 0xc8), (u8*)target + 0xe0);
        packet->parentUID = root->uid;
        packet->unk_47 &= ~0x20;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    }
    btlActionSetState(action, BTLACTION_STATE_PACKET);
}

// FUN_002990f0
void btlActionInitStatePacket(BtlAction* action)
{
    (void)action;
}
// FUN_00299100
void btlActionUpdateStatePacket(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        btlActionSetState(action, BTLACTION_STATE_END);
    }
}

// FUN_00299170
void btlActionInitStateEnd(BtlAction* action)
{
    if (action->unk_18 & 0x4000)
    {
        gBtl->flags |= 0x400000;
        *(u16*)((u8*)gBtl + 0x18) |= 6;
        action->unk_18 &= ~0x4000;
    }
    action->unk_18 &= ~0x100;

    if (action->unk_18 & 0x200)
    {
        gBtl->flags |= 0x400000;
        *(u16*)((u8*)gBtl + 0x18) |= 0x20;
        action->unk_18 &= ~0x200;
    }

    if (FUN_002e4330(action) != 0)
    {
        action->evtFunc = FUN_002e43a0;
        action->stateAfterEvt = BTLACTION_STATE_END;
        btlActionSetState(action, BTLACTION_STATE_EVENT);
    }
    else
    {
        action->unk_18 &= 0xc7ff;
    }
}
// FUN_00299270
void btlActionUpdateStateEnd(BtlAction* action)
{
    if ((gBtl->flags & 0x80) == 0)
    {
        if ((action->unk_18 & 8) && FUN_0028a200(action) != 0)
        {
            if (btlPacketCountById(0x504) != 0)
            {
                return;
            }
            if (btlPacketCountById(0x506) != 0)
            {
                return;
            }
            btlActionSetState(action, 0x1c);
            return;
        }

        if ((action->unk_18 & 0x8004) == 0)
        {
            action->unk_20++;
        }

        if (FUN_0027d380() == 0)
        {
            if ((action->unk_18 & 0x8004) == 0)
            {
                if ((&action->unk_28)[1] > 0)
                {
                    if (action->unk_28 == 0 && datCalcIsDead(action->unit->datUnit, 0) == 0)
                    {
                        (&action->unk_28)[1]--;
                    }
                    else
                    {
                        (&action->unk_28)[1] = 0;
                    }
                }

                if (action->unk_28 == 0 && (&action->unk_28)[1] == 0)
                {
                    FUN_00302d40(action->unit->datUnit);
                    FUN_002dae30(1);
                    FUN_0029abe0(action);
                }
                else
                {
                    FUN_0029ac70(action);
                    FUN_002dae30(0);
                }
            }
            else
            {
                FUN_0029abe0(action);
            }
        }
        else
        {
            gBtl->flags |= 0x80;
        }

        action->unk_18 &= 0x7fff;
        if ((gBtl->flags & 0x80) == 0)
        {
            if ((action->unk_18 & 0x20) == 0)
            {
                btlActionSetState(action, 0x20);
            }
            else
            {
                FUN_0029a320(action);
                if (action->unit->genus == UNIT_GENUS_EC)
                {
                    datCalcSetBadStatus(action->unit->datUnit, 0x80000);
                    datCalcSetHp(action->unit->datUnit, 0);
                }

                if (FUN_0027d380() != 0)
                {
                    gBtl->flags |= 0x80;
                }
                btlActionSetState(action, 0x22);
            }
        }
        else
        {
            if (datCalcIsDead(action->unit->datUnit, 0) != 0)
            {
                FUN_002d7560(action);
                btlActionSetState(action, BTLACTION_STATE_STANDBY);
            }
        }
    }
}

// FUN_00299520 NONMATCHING
void btlActionInitStateEndHome(BtlAction* action)
{
    BtlPacket* packet;
    RwV3d homePos;
    u16 speedIndex;
    u16 allowMove;

    action->movedAwayFromHome = 0;
    if (datCalcIsDead(action->unit->datUnit, 0) != 0)
    {
        if ((action->unit->flags3 & BTLUNIT_FLAG3_UNK40) != 0)
        {
            gBtl->flags |= 0x400000;
            BATTLE_U16(0x18) |= 6;
        }
        btlActionSetState(action, BTLACTION_STATE_STANDBY);
        return;
    }
    if (action == btlOrderGetActionPlaying())
    {
        btlActionSetState(action, BTLACTION_STATE_STANDBY);
        return;
    }
    if ((gBtl->flags & 0x400000) != 0 && (BATTLE_U16(0x18) & 2) != 0)
    {
        return;
    }
    if (datCalcChkBadStatus(action->unit->datUnit, 0x180000) != 0)
    {
        return;
    }
    btlUnit0027f7c0(action->unit, &homePos, NULL, NULL);
    if (FUN_002d1ed0(&action->unit->pos, &homePos) > 75.0f)
    {
        if (action->unit->genus == UNIT_GENUS_PC)
        {
            action->movedAwayFromHome = 1;
        }
        speedIndex = 2;
        if (action->unit->genus == UNIT_GENUS_EC)
        {
            allowMove = (iGpffffb708[(u32)action->target.specificId * 0x2c] & 2) == 0;
            speedIndex = *(u16*)((u8*)iGpffffb728 + action->unit->datUnit->id * 0xe8 +
                                 (u32)allowMove * 4 + 0x24);
        }
        packet = btlUnitCreateMovePacket(action->unit, &homePos, D_00693300[speedIndex], 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        action->movedAwayFromHome = 1;
    }
}
// FUN_00299760
void btlActionUpdateStateEndHome(BtlAction* action)
{
    RwV3d rot;
    BtlPacket* rotPacket;

    if (!btlUnitIsMoving(action->unit))
    {
        if (action->movedAwayFromHome == true)
        {
            btlUnit0027f7c0(action->unit, NULL, NULL, &rot);

            rotPacket = btlUnitCreateRotatePacket(action->unit, &rot, 0);
            rotPacket->actionUID = action->uid;
            btlPacketRegister(rotPacket, BTLPACKET_TYPE_1);
        }

        btlActionSetState(action, BTLACTION_STATE_STANDBY);
    }
}

// FUN_00299800 NONMATCHING
void btlActionInitStateDead(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit;
    u32 flags;

    unit = action->unit;
    FUN_0029a320(action);
    if (unit->genus == 1)
    {
        FUN_0017c750(unit->charId);
        FUN_002d7560(action);
        flags = unit->flags3;
        if ((flags & 0x20) == 0)
        {
            if ((flags & 0x100) == 0)
            {
                packet = FUN_00285d30(unit, 0xffffff, 6, 0, 4, 0);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
                packet = FUN_002baf90(ACTION_U32(gBtl, 0xcb0), unit, unit, 0, 0);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
                packet = FUN_002dd100(10, 2, 8);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
        }
        flags = unit->flags3;
        if ((flags & 0x40) == 0 && (flags & 8) != 0)
        {
            unit->flags3 = flags & ~8;
            FUN_001fdd40();
        }
    }
    else if (unit->genus == 0)
    {
        FUN_00301690(unit->datUnit);
        if (ACTION_U8(unit->datUnit, 0x10) == 10)
        {
            ACTION_U8(unit->datUnit, 0x10) = 1;
        }
    }
}
// FUN_00299990
void btlActionUpdateStateDead(BtlAction* action)
{
    BtlUnit* unit;

    unit = action->unit;
    switch (unit->genus)
    {
        case UNIT_GENUS_PC:
            if (!datCalcIsDead(unit->datUnit, 0))
            {
                unit->flags3 &= ~BTLUNIT_FLAG3_DEAD;

                btlOrderAddAction(action);
                btlActionSetState(action, BTLACTION_STATE_STANDBY);
            }
            break;

        case UNIT_GENUS_EC:
            if (!(unit->flags3 & BTLUNIT_FLAG3_UNK40))
            {
                btlActionSetState(action, BTLACTION_STATE_EXIT);
            }
            else
            {
                if (!datCalcIsDead(unit->datUnit, 0))
                {
                    unit->flags3 &= ~BTLUNIT_FLAG3_DEAD;

                    btlOrderAddAction(action);
                    btlActionSetState(action, BTLACTION_STATE_STANDBY);
                }
            }
    }
}

// FUN_00299aa0
void btlActionInitStateExit(BtlAction* action)
{
    if (action->unk_1a & (1 << 0))
    {
        if (action->unit->flags3 & BTLUNIT_FLAG3_UNK08)
        {
            action->unit->flags3 &= ~BTLUNIT_FLAG3_UNK08;
            FUN_001fdd40();
        }
    }
}
// FUN_00299b00 NONMATCHING
void btlActionUpdateStateExit(BtlAction* action)
{
    BtlUnit* unit = action->unit;

    if (action->unk_1a & 1)
    {
        if (unit->packetCount != 0)
        {
            return;
        }
        if (unit->genus == UNIT_GENUS_PC)
        {
            if (FUN_0030b5a0(unit->datUnit, 0) != 0)
            {
                FUN_002ff660(ACTION_U32(gBtl, 0xbbc), unit->datUnit);
            }
        }
        else if (action->unk_18 & 0x20)
        {
            FUN_00300560(unit->datUnit, 0xfff7ff7f);
            FUN_00301690(unit->datUnit);
            if (ACTION_U8(unit->datUnit, 0x10) == 10)
            {
                ACTION_U8(unit->datUnit, 0x10) = 1;
            }
        }
        FUN_002878d0(unit);
        action->unit = NULL;
        action->unk_1a &= ~1;
        FUN_001fdd40();
    }
    btlAction00299e50(action);
    action->unk_1a |= 2;
}

// FUN_00299d20
void btlActionInitStateTest(BtlAction* action)
{
    // nothing
}
// FUN_00299d30
void btlActionUpdateStateTest(BtlAction* action)
{
    btlActionSetState(action, BTLACTION_STATE_COMMAND);
}

// FUN_00299d60
void btlActionSetState(BtlAction* action, u16 btlState)
{
    action->oldState = action->currState;
    action->currState = btlState;
    action->stateTimer = 0;

    sActionStateTable[btlState].init(action);
}

// FUN_00299db0. 'delay' = number of frames
void btlActionSetStateWithDelay(BtlAction* action, u16 btlState, u16 delay)
{
    if (delay == 0)
    {
        action->pendingState = BTLACTION_STATE_NON;
        action->pendingStateTimer = 0;

        action->oldState = action->currState;
        action->currState = btlState;
        action->stateTimer = 0;

        sActionStateTable[btlState].init(action);

        return;
    }

    action->pendingState = btlState;
    action->pendingStateTimer = delay;
}

// FUN_00299e30
void btlAction00299e30(BtlAction* action)
{
    action->unk_18 |= (1 << 0);
}

// FUN_00299e50
void btlAction00299e50(BtlAction* action)
{
    action->unk_18 &= ~(1 << 0);
}

// FUN_00299e70
void btlActionSetUnit(BtlAction* action, BtlUnit* unit)
{
    action->unit = unit;
    action->unk_1a |= (1 << 0);
}

// FUN_00299e90
BtlAction* btlActionCreate()
{
    BtlAction* action;
    u32 id;

    action = RwMalloc(sizeof(BtlAction), rwMEMHINTDUR_GLOBAL);
    memset(action, 0, sizeof(BtlAction));

    btlTargetInit(&action->target);

    action->pendingState = BTLACTION_STATE_NON;
    action->unk_14 = 8;
    action->uid = btlGetUID();

    if (sNextId >= BTLACTION_IDMAX)
    {
        sNextId = 1;
    }

    id = sNextId;
    sNextId++;
    action->id = id;
    action->idleWeaponAnimTimer = -1;
    action->rand = datCalcRand(60);
    action->next = NULL;

    if (gBtl->actionList.tail != NULL)
    {
        gBtl->actionList.tail->next = action;
        action->prev = gBtl->actionList.tail;
    }
    else 
    {
        action->prev = NULL;
    }
    
    gBtl->actionList.tail = action;

    action->oldState = action->currState;
    action->currState = BTLACTION_STATE_NON;
    action->stateTimer = 0;

    sActionStateTable[BTLACTION_STATE_NON].init(action);

    return action;
}

// FUN_00299fb0
void btlActionUpdateAll()
{
    BtlAction* curr;
    BtlAction* prev;
    u32 canUpdateAction;
    u32 currState;
    u32 pendingState;
    const BtlActionStateEntry* stateEntry;

    curr = gBtl->actionList.tail;
    while (curr != NULL)
    {
        prev = curr->prev;
        canUpdateAction = true;

        if (curr->pendingState != BTLACTION_STATE_NON &&
            curr->pendingStateTimer > 0)
        {
            if (--curr->pendingStateTimer == 0)
            {
                currState = curr->currState;
                pendingState = curr->pendingState;
                curr->oldState = currState;
                curr->currState = pendingState;
                curr->stateTimer = 0;

                sActionStateTable[pendingState].init(curr);

                curr->pendingState = BTLACTION_STATE_NON;
            }
            else 
            {
                canUpdateAction = false;
            }
        }

        if (canUpdateAction && !(curr->unk_1a & (1 << 2)))
        {
            if (curr->unk_18 & (1 << 0))
            {
                stateEntry = &sActionStateTable[curr->currState];
                stateEntry->update(curr);

                curr->stateTimer += 2;
            }
            else if (curr->unk_1a & (1 << 1))
            {
                if (curr->prev != NULL)
                {
                    curr->prev->next = curr->next;
                }

                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
                else 
                {
                    gBtl->actionList.tail = curr->prev;
                }

                RwFree(curr);
            }
        }

        curr = prev;
    }
}

// FUN_0029a140
void btlActionDestroyAll()
{
    BtlAction* currAction;
    BtlAction* prevAction;

    currAction = gBtl->actionList.tail;
    while (currAction != NULL)
    {   
        prevAction = currAction->prev;
        if (prevAction != NULL)
        {
            prevAction->next = currAction->next;
        }

        if (currAction->next != NULL)
        {
            currAction->next->prev = currAction->prev;
        }
        else
        {
            gBtl->actionList.tail = currAction->prev;
        }

        RwFree(currAction);

        currAction = prevAction;
    }
}

// FUN_0029a1d0
BtlAction* btlActionFindByUnit(BtlUnit* unit)
{
    BtlAction* action;

    action = gBtl->actionList.tail;
    while (action != NULL)
    {
        if (action->unit == unit)
        {
            return action;
        }

        action = action->prev;
    }

    return NULL;
}

// FUN_0029a210
BtlAction* btlActionFindById(u32 id)
{
    BtlAction* action;

    action = gBtl->actionList.tail;
    while (action != NULL)
    {
        if (action->id == id)
        {
            return action;
        }

        action = action->prev;
    }

    return NULL;
}
