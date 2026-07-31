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
#include "Main/Battle/Data/datPersona.h"
#include "temporary.h"
extern u32 func_002e4430();
f32 FUN_002d1ed0(const RwV3d* a, const RwV3d* b);
extern const char D_00693318[];
#pragma alias D_00693318_abs D_00693318
extern const char D_00693318_abs[];

typedef struct BtlEnemyMoveSpeed
{
    u16 speedIndex;
    s16 field_02;
} BtlEnemyMoveSpeed;

typedef struct BtlEnemyRecord
{
    u8 pad_00[0x22];
    s16 field_22;
    BtlEnemyMoveSpeed moveSpeed[2];
    u8 pad_2c[0xbc];
} BtlEnemyRecord;


#define BTLACTION_IDMAX 0xFFFFFFF
/* Retail action scratch remains intentionally opaque until packet-result layouts are named. */
#define ACTION_U8(action, offset) (*(u8*)((u8*)(action) + (offset)))
#define ACTION_U16(action, offset) (*(u16*)((u8*)(action) + (offset)))
#define ACTION_S16(action, offset) (*(s16*)((u8*)(action) + (offset)))
#define ACTION_S32(action, offset) (*(s32*)((u8*)(action) + (offset)))
#define ACTION_U64(action, offset) (*(u64*)((u8*)(action) + (offset)))
#define ACTION_U32(action, offset) (*(u32*)((u8*)(action) + (offset)))
#define BATTLE_U16(offset) (*(u16*)((u8*)gBtl + (offset)))
typedef struct BtlActionTargetEntry
{
    u32 statusFlags;
    u8 pad_04[0x0e];
    u16 flags;
    u8 pad_14[8];
} BtlActionTargetEntry;

typedef struct BtlActionTargetView
{
    u8 pad_00[0xe8];
    BtlActionTargetEntry entries[12];
} BtlActionTargetView;

#pragma alias FUN_002819d0_btlAction FUN_002819d0
extern BtlPacket* FUN_002819d0_btlAction(BtlUnit*, const RwV3d*, f32, u32);
#pragma alias FUN_00282d40_btlAction FUN_00282d40
extern void FUN_00282d40_btlAction(f32, BtlUnit*, s16, u32, s8);
#pragma alias FUN_002835e0_btlAction FUN_002835e0
extern s16 FUN_002835e0_btlAction(f32, BtlUnit*, u16);
#pragma alias FUN_002838d0_btlAction FUN_002838d0
extern u16 FUN_002838d0_btlAction(f32, BtlUnit*, u16);
/* Packet constructors not yet assigned public subsystem names. */
BtlPacket* FUN_002819d0();
BtlPacket* FUN_00282130();
BtlPacket* FUN_002822b0();
BtlPacket* FUN_00282650();
BtlPacket* FUN_002843e0(BtlUnit* unit, u16 id);
void FUN_00175130(s16 id);
#pragma alias FUN_00175130_btlAction FUN_00175130
extern void FUN_00175130_btlAction(u16 id);
#pragma alias btlUnitCreateAnimPacketSignedId btlUnitCreateAnimPacket
extern BtlPacket* btlUnitCreateAnimPacketSignedId(BtlUnit* unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);
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
u32 FUN_002dbb00(BtlUnit* unit);
void FUN_002e2d00(u16 result);
BtlPacket* FUN_002bd850(BtlUnit* unit, s16 id);
BtlPacket* func_002bd780(BtlUnit* unit, u16 id);
BtlPacket* FUN_002bdbd0(BtlUnit* source, BtlUnit* target, s32 id, u32 a, u32 b, u32 c, u32 d, void* result);
BtlPacket* FUN_002baf90(u32 id, BtlUnit* source, BtlUnit* target, u32 a, u32 b);
BtlPacket* FUN_002bddd0(void);
BtlPacket* FUN_002dd100(u32 a, u32 b, u32 c);
BtlPacket* FUN_002d7e20(BtlAction* action, BtlAction* target, void* result, u32 a, u32 b);
extern f32 D_00693300[];
extern s16 D_00690E20[];
s16 FUN_002dc670(BtlAction* action);
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
BtlPacket* FUN_002bc950(u32 a, u32 b, u32 c);
BtlPacket* FUN_002e3c80(void);
BtlPacket* FUN_002d8090(BtlAction* action);
BtlPacket* FUN_002dd690(u32 a, u32 b);
BtlPacket* FUN_002a1db0();
BtlPacket* FUN_002dd4a0(u16 param_1, u16 param_2);
void FUN_002b9030(u32 param_1);
BtlPacket* FUN_002e38a0(u16 a);
BtlPacket* FUN_002b8f40(u32 a);
BtlPacket* FUN_002b8d60(u32 a, u32 b);
BtlPacket* FUN_002a3b40(BtlAction* action, u32 a);
BtlPacket* FUN_002bc7e0();
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0956;
extern u16 DAT_007e0958;
BtlPacket* func_002e3b50(u32 a, u32 b, u32 c);
BtlPacket* func_002e3990(void);
BtlPacket* func_002e3d10(void);
BtlPacket* func_002e3a90(void);
void func_002b9600(void* values);
u64 func_002b9640(u8* data);
void func_002bb6f0(u16 id, void* data);
u32 FUN_0029a380(BtlAction* action);
void FUN_001fef90(u16 charId);
u32 FUN_001ff100(void);
u32 FUN_001ff120(void);
void FUN_001ff140(void);
void FUN_001ff370(void);
u32 func_002d1a70(void);
extern u8* iGpffffb708;
extern BtlCommandRecord* iGpffffb710;
extern BtlEnemyRecord* iGpffffb728;
extern f32 uGpffff8088;
extern f32 uGpffff8390;
extern f32 uGpffff83a4;
extern RwV3d D_00697880;
extern f32 DAT_007cb050[];

u32 FUN_002d5bf0(BtlUnit* unit);
u32 FUN_002d6370(s16 commandId);
void FUN_002fd8a0(BtlAction* action);
u8 FUN_003093a0(DatUnit* unit);
s32 FUN_003082f0(DatUnit* unit, u32 id);
void FUN_004c6c60(RwV3d* dst, const RwV3d* src, const RwMatrix* matrix);

void FUN_002899e0(BtlAction* action);
void FUN_00289b50(BtlAction* action);
u32 FUN_00289f40(BtlAction* action);
u16 FUN_0028a0f0(BtlAction* action);
u32 FUN_0028a200(BtlAction* action);
u32 FUN_0028a3e0(BtlAction* action);
void FUN_0028a540(BtlAction* action, u32 id, u16* out1, u16* out2, u16* out3, u16* out4);


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
void FUN_002a3a90();
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
u32 FUN_002b8f90(u16 param_1);
BtlPacket* FUN_002d8330(BtlAction* action);
void func_0029ea60(u16 param_1, u32* param_2, u32* param_3);
BtlPacket* func_0029f4b0(u32 param_1, u32 param_2, u32 param_3);
void* func_0029ec00(u16 param_1);
void func_0029ec80(u16 param_1, u32* param_2, u32* param_3);
BtlPacket* func_002a0050(void* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5);
void* func_0029ec50(u16 param_1);
BtlPacket* func_002a1280(void* param_1, u32 param_2);
BtlPacket* func_002a1b00(BtlAction* action, u16 param_2, u32 param_3);
void func_002bb6f0(u16 param_1, void* param_2);
BtlPacket* func_0027f2f0(void);
extern u64 FUN_0027f940();
extern void FUN_002d3e00(BtlUnit* unit, RwV3d* outPos);
extern void FUN_002b77c0(BtlUnit* unit);
extern void FUN_00287490(BtlUnit* unit);
extern void bpRoot001fe270(void* param);
extern void bpRoot001fe2e0(void* param);
extern u32 FUN_0016f190(u32 id);
extern void FUN_002ddbe0(void);
extern BtlAction* btlActionFindByUnit(BtlUnit* unit);
extern u16 func_00170760(s16 pcId, s16 index);
extern void func_00170860(s16 pcId, s16 index, u16 value);
BtlPacket* FUN_0027dc80();
extern f32 FUN_004c6ac0(RwV3d* vec);
extern f32 FUN_004c69f0(RwV3d* dst, const RwV3d* src);
BtlPacket* func_002bb2f0(u32 param_1, BtlUnit* unit, u32 param_3, u64 param_4, u16 param_5);
u32 FUN_002fdb70(void);
u32 FUN_002fdb90(void);
u32 FUN_002fde40(BtlAction* action, f32* position);
extern s32 FUN_002d63b0(BtlUnit* unit, s32 param_2, s32 param_3);
extern s64 func_00284040(BtlUnit* a, BtlUnit* b, s16 c, s32 d);
void* FUN_00289650(u32 param_1, u16 param_2, u32 param_3);
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags);
BtlPacket* btlUnit00285d30(BtlUnit* unit, u32 targetCol, s16 param_3, s16 param_4, u8 mode, u8 flags);

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
    BtlPacket* movePacket;
    BtlAction* current;
    BtlUnit* unit;
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
            FUN_002fd8a0(current);
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
        switch (current->currState)
        {
        case BTLACTION_STATE_STANDBY:
        case BTLACTION_STATE_COMMAND:
        case BTLACTION_STATE_TARGET:
            if (btlActionIdleWeaponAnim(current) != 0 ||
                (gBtl->flags & BTL_FLAG_MULTIENEMY) == 0)
            {
                continue;
            }
            break;
        default:
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
                if (iGpffffb728[unitId].moveSpeed[0].field_02 == 1)
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

/* W306: opt_loop_invariants on is required for FUN_0028a3e0 (with nd66, without nd66 -> nd0); measured against the fresh W306 baseline. */
#pragma opt_loop_invariants on
// FUN_0028a3e0
u32 FUN_0028a3e0(BtlAction* action)
{
    switch (action->unit->genus)
    {
    case 0:
    {
        BtlAction* target;
        s32 targetedCount;
        u16 i;
        u16 j;
        s32 count;

        for (i = 0, targetedCount = action->target.targetedCount; i < targetedCount; i++)
        {
            target = action->target.targetedActions[i];
            count = ACTION_U8(target, 0xc8);
            for (j = 0; j < count; j++)
            {
                if (((BtlActionTargetView*)target)->entries[j].statusFlags & 0x100000)
                {
                    return true;
                }
            }
        }
        break;
    }
    case 1:
    {
        BtlAction* target;
        u16 i;
        u16 j;
        s32 count;
        s32 targetedCount;

        i = 0;
        targetedCount = action->target.targetedCount;
        for (; i < targetedCount; i++)
        {
            target = action->target.targetedActions[i];
            count = ACTION_U8(target, 0xc8);
            for (j = 0; j < count; j++)
            {
                if (((BtlActionTargetView*)target)->entries[j].flags & 4)
                {
                    return true;
                }
            }
        }
        break;
    }
    default:
        break;
    }

    return false;
}
#pragma opt_loop_invariants reset

// FUN_0028a540
void FUN_0028a540(BtlAction* action, u32 id, u16* out1, u16* out2, u16* out3, u16* out4)
{
    u16 itemId = (u16)id;
    s16 type;
    u8 variant;
    BtlUnit* unit;

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
        switch (variant)
        {
        case 2:
            *out1 = 0xf;
            *out2 = 0x12;
            *out3 = 0x15;
            *out4 = 0x18;
            break;
        case 3:
            *out1 = 0x10;
            *out2 = 0x13;
            *out3 = 0x16;
            *out4 = 0x19;
            break;
        case 1:
        default:
            *out1 = 0xe;
            *out2 = 0x11;
            *out3 = 0x14;
            *out4 = 0x17;
            break;
        }
        return;
    }

    type = (s16)FUN_003082f0(unit->datUnit, (u32)id);
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
    case 1:
    case 4:
    case 5:
    default:
        *out1 = 0;
        *out2 = 1;
        *out3 = 7;
        *out4 = 9;
        break;
    }
}

// FUN_0028a780
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
        packet = FUN_002a1db0(0);
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
    s16 var_2;

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
    if (unit->genus == UNIT_GENUS_PC)
    {
        if (ACTION_S16(gBtl, 0xa38) != -1 &&
            ((u32)(ACTION_S16(gBtl, 0xa3a) >> 1) >= (FUN_002d4e10(2, 0x80000) & 0xffff)) &&
            ACTION_S16(gBtl, 0xa38) != FUN_002b7060() &&
            FUN_00300580(unit->datUnit, 0x180000) == 0)
        {
            btlActionSetStateWithDelay(action, BTLACTION_STATE_CHANGEFORMA, 1);
            return;
        }
        var_2 = 1;
    }
    else
    {
        var_2 = 0;
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
    if (var_2 != 0)
    {
        if (unit->genus == 0 && unit->datUnit->aiTactic == 0xA)
        {
            u32 rootH;
            u8 buf[4];
            u32 posX, posY;
            u32 animLen;
            BtlPacket* pkt;
            BtlPacket* pktB;
            
            btlAction0028a780(action);
            rootH = FUN_002b8f90(0);
            func_002bb6f0(0x156, buf);
            pktB = FUN_002bac00(rootH, (s8*)buf, 0);
            pktB->actionUID = action->uid;
            btlPacketRegister(pktB, BTLPACKET_TYPE_1);
            
            pkt = FUN_002dd4a0(0x156, 0);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            func_0029ea60(0x156, &posX, &posY);
            pkt = func_0029f4b0(posX, posY, 0x10);
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            {
                void* area = func_0029ec00(0x156);
                func_0029ec80(0x156, &posX, &posY);
                pkt = func_002a0050(area, posX, posY, 0x10, 0);
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            }
            
            {
                void* hitArea = func_0029ec50(0x156);
                pkt = func_002a1280(hitArea, 0x10);
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            }
            
            pkt = FUN_002a3b40(action, 9);
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            {
                s16 weaponId = unit->genus == 0 ? 0x88 : 0x89;
                pkt = FUN_002bd850(unit, weaponId);
                ACTION_S16(pkt, 0x48) += 0x12;
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_3D);
            }
            {
                /* This caller needs the u16 second-argument ABI; the later skill caller needs u32. */
                extern s64 FUN_002838d0(BtlUnit* unit, u16 a, f32 b);
                animLen = (u32)(s16)FUN_002838d0(unit, 0xc, 1.0f);
            }
            
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            pktB = FUN_00284200(unit, 0xc, 6, 4, 1.0f);
            ACTION_S16(pktB, 0x4a) = animLen + 6;
            pktB->actionUID = action->uid;
            btlPacketRegister(pktB, BTLPACKET_TYPE_1);
            
            pkt = FUN_002baf90(rootH, unit, unit, 1, 0);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            pkt->preUpdateWait.type = 4;
            pkt->preUpdateWait.value = pktB->uid;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_2D);
            
            pkt = FUN_002dd5e0(1);
            pkt->unk_00 = 5;
            pkt->parentUID = pktB->uid;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            {
                u32 extraWork[12];
                FUN_002d5dc0(extraWork);
                extraWork[2] = 0x100;
                
                pkt = FUN_002d7e20(action, action, extraWork, 1, 1);
                pkt->unk_00 = 5;
                pkt->parentUID = pktB->uid;
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            }
            
            pkt = FUN_002a3b40(action, 0x1b);
            ACTION_S16(pkt, 0x48) = (animLen + 6) - (animLen + 6) / 4;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            pkt = FUN_002843e0(unit, 6);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            ACTION_S16(pkt, 0x4a) = 0x18;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            pkt = FUN_0029fa50(0x10);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            pkt->unk_47 &= ~0x20;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            pkt = FUN_002a1080(0x10, 0);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            pkt->unk_47 &= ~0x20;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            pkt = FUN_002a16c0(0x10);
            pkt->unk_00 = 4;
            pkt->parentUID = pktB->uid;
            pkt->unk_47 &= ~0x20;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            
            FUN_002b9030(rootH);
            
            gBtl->flags |= 0x400000;
            BATTLE_U16(0x18) |= 4;
        }
    }
}
/* W212: transferring 00297760's early-return cascade holds nd907/1480 (window 1488). Narrow u16 stat/message/table contracts improve nd907 to nd285 but grow to 1504, so were reverted; residual first differs at offset 48, a common-exit branch displaced by the 8-byte deficit. */
// FUN_0028b230 NONMATCHING
void btlActionUpdateStateStart(BtlAction* action)
{
    BtlPacket* packet;
BtlPacket* result;
    BtlPacket* chain;
    BtlTargetResult work;
    s32 stat;
    u32 messageId;
    u32 tableIndex;
    s16 voice;
    if (gBtl->flags & 0x80000)
        return;
    if (btlPacketCountById(0x700))
        return;
    if (btlPacketCountById(0x504))
        return;
    if (btlPacketCountById(0x506))
        return;
    if (btlPacketCountById(0x301))
        return;
    if (btlPacketCountById(0x104))
        return;
    if (action->passiveSkillsFlags != 0)
    {
        btlAction0028a780(action);
        FUN_002d5dc0(&work);
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
            work.hpDelta = stat * 100 / 5000;
            action->passiveSkillsFlags &= ~1;
        }
        else if (action->passiveSkillsFlags & 2)
        {
            messageId = 0x224;
            voice = 0xb;
            tableIndex = 0x2f;
            work.hpDelta = stat * 100 / 0x9c4;
            action->passiveSkillsFlags &= ~2;
        }
        else if (action->passiveSkillsFlags & 4)
        {
            messageId = 0x225;
            voice = 0xb;
            tableIndex = 0x30;
            work.hpDelta = stat * 100 / 0x682;
            action->passiveSkillsFlags &= ~4;
        }
        else if (action->passiveSkillsFlags & 8)
        {
            messageId = 0x226;
            voice = 0xb;
            tableIndex = 0x30;
            work.spDelta = 3;
            action->passiveSkillsFlags &= ~8;
        }
        else if (action->passiveSkillsFlags & 0x10)
        {
            messageId = 0x227;
            voice = 0xb;
            tableIndex = 0x30;
            work.spDelta = 5;
            action->passiveSkillsFlags &= ~0x10;
        }
        else if (action->passiveSkillsFlags & 0x20)
        {
            messageId = 0x228;
            voice = 0xb;
            tableIndex = 0x30;
            work.spDelta = 7;
            action->passiveSkillsFlags &= ~0x20;
        }
        else if (action->passiveSkillsFlags & 0x40)
        {
            messageId = 0x25f;
            voice = 10;
            tableIndex = 0x39;
            work.hpDelta = stat * 100 / 0x4e2;
            action->passiveSkillsFlags &= ~0x40;
        }
        else if (action->passiveSkillsFlags & 0x80)
        {
            messageId = 0x260;
            voice = 10;
            tableIndex = 0x39;
            work.hpDelta = stat * 100 / 0x4e2;
            action->passiveSkillsFlags &= ~0x80;
        }
        if (work.hpDelta != 0 || work.spDelta != 0)
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
            result = FUN_002d7e20(action, action, &work, 1, 1);
            result->unk_00 = 0xb;
            result->parentUID = chain->uid;
            result->actionUID = action->uid;
            btlPacketRegister(result, BTLPACKET_TYPE_1);
            packet = FUN_002bdbd0(action->unit, action->unit, -1, 0, 0, 0, 1, &work);
            packet->unk_00 = 4;
            packet->parentUID = result->uid;
            packet->unk_47 &= ~0x20;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            if (work.hpDelta != 0)
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
    if ((s8)FUN_00302f50(action->unit->datUnit) >= 0)
    {
        btlActionSetState(action, BTLACTION_STATE_SUPPORT);
    }
    else if (FUN_002dc070(action))
    {
        btlActionSetState(action, BTLACTION_STATE_BAD);
    }
    else
    {
        btlActionSetState(action, BTLACTION_STATE_STARTHOME);
    }
}

// FUN_0028b800
void btlActionInitStateStartHome(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit = action->unit;
    RwV3d homePos;
    u16 allowMove;
    u16 speedIndex;
    BtlEnemyRecord* enemyRecords;
    u16 unitId;
    u8 genus;
    BtlUnit* moveUnit;

    if ((gBtl->flags & 0x2000) && (action->unk_1a & 1) && unit->genus == UNIT_GENUS_PC)
    {
        action->unk_14 = BTLACTION_STATE_AUTO;
    }
    if (FUN_0029a3e0(action) != 0)
    {
        btlActionSetState(action, action->unk_14);
        return;
    }
    btlUnit0027f7c0(unit, &homePos, NULL, NULL);
    if (FUN_002d1ed0(&unit->pos, &homePos) > 75.0f)
    {
        speedIndex = 2;
        allowMove = !(iGpffffb708[(u32)action->target.specificId * 0x2c] & 2);
        moveUnit = action->unit;
        unitId = moveUnit->datUnit->id;
        genus = moveUnit->genus;
        switch (genus)
        {
        case UNIT_GENUS_PC:
            break;
        case UNIT_GENUS_EC:
            enemyRecords = iGpffffb728;
            speedIndex = enemyRecords[unitId].moveSpeed[allowMove].speedIndex;
            break;
        default:
            break;
        }
        packet = btlUnitCreateMovePacket(moveUnit, &homePos, D_00693300[speedIndex], 0);
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
    BtlAction* iter;

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
        for (iter = gBtl->actionList.tail; iter != NULL; iter = iter->prev)
        {
        }
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
        for (iter = gBtl->actionList.tail; iter != NULL; iter = iter->prev)
        {
        }
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
    int specificId = action->target.specificId;
    union {
        BtlAction* selected;
        u16 i;
    } scratch;
    BtlPacket* packet;

    if (action->target.commandId == 4)
    {
        FUN_002bfcb0(action, (BtlTarget*)action->unkData3, 2, 0, 0);
        if (specificId == 0)
        {
            specificId = -1;
        }
    }
    else if (ACTION_U8(gBtl, 0x16fc + specificId * 0x2c) == 1 ||
             ACTION_U8(gBtl, 0x16fc + specificId * 0x2c) == 2)
    {
        FUN_002bfcb0(action, (BtlTarget*)action->unkData3,
                      ACTION_U8(gBtl, 0x16fd + specificId * 0x2c),
                      ACTION_U8(gBtl, 0x16fe + specificId * 0x2c), 0);
    }
    else
    {
        FUN_002bff60(action, (BtlTarget*)action->unkData3, specificId, 0);
    }
    FUN_002c0970((BtlTarget*)action->unkData3);
    if (ACTION_U8(gBtl, 0x16fc + action->target.specificId * 0x2c) == 1 ||
        ACTION_U8(gBtl, 0x16fc + action->target.specificId * 0x2c) == 2)
    {
        scratch.selected = NULL;
        for (scratch.i = 0; scratch.i < action->target.targetedCount; scratch.i++)
        {
            FUN_001fe7f0(action->target.targetedActions[scratch.i]->unit->id);
        }
    }
    else
    {
        FUN_002c0ac0(action, (BtlTarget*)action->unkData3);
        scratch.selected = FUN_002c0880((BtlTarget*)action->unkData3);
        FUN_001fe7f0(scratch.selected->unit->id);
    }
    FUN_001fe810(specificId);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_TARGET);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    FUN_001fef50();
    FUN_002899e0(action);
    if (scratch.selected != NULL)
    {
        btlPacketRegister(btlUnitCreateLookAtUnitPacket(NULL, scratch.selected->unit, BTLUNIT_LOOKAT_FLAG_ALLPLAYER), BTLPACKET_TYPE_1);
        btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(scratch.selected->unit, 0), BTLPACKET_TYPE_1);
    }
}
// FUN_0028c590 NONMATCHING
void btlActionUpdateStateTarget(BtlAction* action)
{
    BtlTarget* work = (BtlTarget*)action->unkData3;
    BtlAction* selected;
    BtlPacket* packet;
    BtlAction* iter;
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
        for (iter = gBtl->actionList.tail; iter != NULL; iter = iter->prev)
        {
        }
        btlActionSetState(action, BTLACTION_STATE_READY);
    }
}

// FUN_0028c9f0
void btlActionInitStateAnalyze(BtlAction* action)
{
    action->movedAwayFromHome = true;
}
#pragma opt_loop_invariants on
// FUN_0028ca00 NONMATCHING
void btlActionUpdateStateAnalyze(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit;
    BtlUnit* unit2;
    BtlAction* targetAction;
    u32 unitId;
    s32 result;

    if (btlPacketCountById(0x800) != 0)
    {
        return;
    }
    switch (action->movedAwayFromHome)
    {
        case 1:
            unitId = FUN_002db690();
            unit = btlUnitFindFromId(unitId);
            if (unit != NULL && datCalcIsDead(unit->datUnit, 0) == 0 &&
                (unit->flags3 & 8))
            {
                if (FUN_0016f190(0x140) != 0)
                {
                    bpRoot001fe2e0((void*)unitId);
                }
                else if (FUN_0016f190(0x141) != 0)
                {
                    bpRoot001fe270((void*)unitId);
                }

                targetAction = btlActionFindByUnit(unit);
                btlAction0028a780(action);
                packet = FUN_002b8d60(3, 0xfff);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                packet = FUN_002a3b40(targetAction, 3);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                FUN_002dba80();
                FUN_002ddbe0();
                if (FUN_002d1a70() == 1)
                {
                    gBtl->flags &= ~0x4000;
                    FUN_001ff350();
                }
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
                unit2 = btlUnitFindFromId(FUN_002db690());
                if (unit2 != NULL)
                {
                    result = FUN_002dbb00(unit2);
                    if (result >= 0)
                    {
                        FUN_002e2d00(result);
                    }
                    action->movedAwayFromHome = 3;
                }
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

#pragma opt_loop_invariants reset
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
    BtlUnit* unit = action->unit;
    u8 status;
    s32 work[4];
    s32 messageId = 0;
    s32 special = 0;

    if (btlPacketCountById(0x506) != 0)
    {
        return;
    }
    status = FUN_00302f50(unit->datUnit);
    switch (status)
    {
        case 0: case 1: messageId = unit->genus == UNIT_GENUS_PC ? 0x16 : 0x17; FUN_00301540(unit->datUnit, 0); FUN_00301540(unit->datUnit, 1); break;
        case 2: case 4: messageId = unit->genus == UNIT_GENUS_PC ? 0x18 : 0x19; FUN_00301540(unit->datUnit, 4); FUN_00301540(unit->datUnit, 2); break;
        case 3: messageId = unit->genus == UNIT_GENUS_PC ? 0x1a : 0x1b; FUN_00301540(unit->datUnit, 3); break;
        case 5: messageId = unit->genus == UNIT_GENUS_PC ? 0x1c : 0x1d; FUN_00301540(unit->datUnit, 5); break;
        case 6: messageId = unit->genus == UNIT_GENUS_PC ? 0x1e : 0x1f; FUN_00301540(unit->datUnit, 6); break;
        case 7: messageId = unit->genus == UNIT_GENUS_PC ? 0x20 : 0x21; FUN_00301540(unit->datUnit, 7); break;
        case 8: messageId = unit->genus == UNIT_GENUS_PC ? 0x22 : 0x23; FUN_00301540(unit->datUnit, 8); break;
        case 9: messageId = unit->genus == UNIT_GENUS_PC ? 0x24 : 0x25; FUN_00301540(unit->datUnit, 9); special = 1; break;
        case 10: messageId = unit->genus == UNIT_GENUS_PC ? 0x26 : 0x27; FUN_00301540(unit->datUnit, 10); break;
        case 11: messageId = unit->genus == UNIT_GENUS_PC ? 0x46 : 0x47; FUN_00301540(unit->datUnit, 11); break;
        case 13: messageId = unit->genus == UNIT_GENUS_PC ? 0x5a : 0x5b; FUN_00301540(unit->datUnit, 13); break;
        case 14: messageId = unit->genus == UNIT_GENUS_PC ? 0x5c : 0x5d; FUN_00301540(unit->datUnit, 14); break;
        case 15: messageId = unit->genus == UNIT_GENUS_PC ? 0x5e : 0x5f; FUN_00301540(unit->datUnit, 15); break;
        case 16: messageId = unit->genus == UNIT_GENUS_PC ? 0x60 : 0x61; FUN_00301540(unit->datUnit, 16); break;
    }
    if (messageId == 0)
    {
        if (FUN_002dc070(action))
        {
            btlActionSetState(action, BTLACTION_STATE_BAD);
        }
        else
        {
            btlActionSetState(action, BTLACTION_STATE_STARTHOME);
        }
        return;
    }
    btlAction0028a780(action);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = FUN_002bd850(unit, messageId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    if (special)
    {
        FUN_002d5dc0(work);
        work[0] = -((FUN_002ffd70(unit->datUnit) & 0xffff) - 1);
        if (work[0] >= 0) work[0] = 0;
        work[1] = -((FUN_002ffd80(unit->datUnit) & 0xffff) - 1);
        if (work[1] >= 0) work[1] = 0;
        packet = FUN_002d7e20(action, action, work, 1, 1);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return;
    }
}

// FUN_0028d560
void btlActionInitStateBad(BtlAction* action)
{
    FUN_002dc5e0();
    action->movedAwayFromHome = true;
    action->unk_488 = 0;
}
/* Retail reconstruction covers the guard, down-status packet sequence, result dispatch, and moved-home state paths at 0x28d5e8-0x28dbc0. */
// FUN_0028d5a0 NONMATCHING
void btlActionUpdateStateBad(BtlAction* action)
{
    BtlPacket* packet;
    BtlPacket* cameraPacket;
    BtlPacket* animPacket;
    u32 badStatus;
    s32 work[7];
    s32 result;
    s32 playAnim;
    s32 threshold;
    BtlUnit* unit;
    s16 messageId;

    if (btlPacketCountById(0x506) != 0)
    {
        return;
    }
    if (btlPacketCountById(0x105) != 0)
    {
        return;
    }
    btlAction0028a780(action);
    badStatus = FUN_00300550(action->unit->datUnit);
    if (FUN_00300580(action->unit->datUnit, UNIT_BADSTATUS_DOWN) != 0 && action->unk_488 == 0)
    {
        playAnim = 1;
        if ((FUN_003005a0(action->unit->datUnit) & 0xffff) == 3)
        {
            if (datGetFlag(0x1319) != 0)
            {
                threshold = 10;
            }
            else
            {
                threshold = 0x1e;
            }
            if ((s32)datCalcRand(0x64) < threshold)
            {
                playAnim = 0;
            }
        }
        cameraPacket = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
        cameraPacket->actionUID = action->uid;
        btlPacketRegister(cameraPacket, BTLPACKET_TYPE_0);
        if (playAnim != 0)
        {
            animPacket = btlUnitCreateAnimPacket(action->unit, 10, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
            animPacket->unk_00 = 4;
            animPacket->parentUID = cameraPacket->uid;
            animPacket->preUpdateDelay = 0x1e;
            animPacket->actionUID = action->uid;
            btlPacketRegister(animPacket, BTLPACKET_TYPE_1);
            packet = btlVoice002e2be0(action, 8, 0, 0, 0);
            packet->unk_00 = 4;
            packet->parentUID = animPacket->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            FUN_002d5dc0(work);
            work[3] = 0x100000;
            packet = FUN_002d7e20(action, action, work, 1, 1);
            packet->unk_00 = 4;
            packet->parentUID = animPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_00284c90(action->unit);
            packet->unk_00 = 4;
            packet->parentUID = animPacket->uid;
            packet->postUpdateDelay = 0xc;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002db740(action, 0x14, 0, 0, 0);
            packet->unk_00 = 4;
            packet->parentUID = animPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        else
        {
            unit = action->unit;
            if (unit->genus == UNIT_GENUS_PC)
            {
                messageId = 0xa2;
            }
            else
            {
                messageId = 0xa3;
            }
            packet = FUN_002bd850(unit, messageId);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            packet = FUN_002db740(action, 0x15, 0, 0, 0);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        btlPacketRegister(btlUnitCreateLookAtUnitPacket(NULL, action->unit, 1), BTLPACKET_TYPE_1);
        btlPacketRegister(btlUnitCreateLookAtDeactivatePacket(action->unit, 0), BTLPACKET_TYPE_1);
        action->unk_18 |= 0x200;
        action->movedAwayFromHome = 0;
        action->unk_488 = 1;
        return;
    }
    result = FUN_002dc180(action);
    if (result != 0)
    {
        packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        FUN_002d5dc0(work);
        if (result & 0x100)
        {
            work[2] = 0x200;
            packet = btlVoice002e2be0(action, 0x16, 0, 0, 0);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        work[3] = result;
        packet = FUN_002d7e20(action, action, work, 1, 1);
        packet->preUpdateDelay = 0x12;
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
            btlPacketRegister(packet, BTLPACKET_TYPE_3D);
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
                packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_OWN);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                packet = FUN_002bd850(action->unit, result);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_3D);
            }
            packet = FUN_002db740(action, 0x1e, 0, 0, 0);
            packet->preUpdateDelay = 0x25;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            if (badStatus == 0x10 && action->unk_28 == 0 && ACTION_U8(action, 0x29) == 0)
            {
                ACTION_U8(action, 0x29) = datCalcRand(1) + 2;
            }
            btlActionSetState(action, BTLACTION_STATE_READY);
            return;
        }
    }
    if (FUN_002dc130(action) != 0)
    {
        btlActionSetState(action, BTLACTION_STATE_BADDMG);
    }
    else
    {
        btlActionSetState(action, BTLACTION_STATE_PACKET);
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
        case 6:
            if (action->unit->genus == UNIT_GENUS_PC && action->unit->charId != 1)
            {
                btlActionSetState(action, BTLACTION_STATE_ESCAPEMES);
            }
            else
            {
                btlActionSetState(action, BTLACTION_STATE_ESCAPE);
            }
            break;
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
    BtlAction* target;
    BtlAction* victim;
    BtlUnit* actionUnit;
    BtlUnit* victimUnit;
    BtlUnit* personaUnit;
    RwV3d spC0;
    RwV3d spB0;
    RwV3d spA0;
    RwV3d sp90;
    RwV3d sp80;
    RwV3d sp70;
    f32 distance;
    f32 extraOffset;
    f32 moveSpeed;
    u16 specificId;
    u16 someFlag;
    u16 isSkillType;
    u16 isFirstSpecial;
    BtlPacket* packet;
    RwV3d spE0;
    RwV3d spD0;
    RwV3d sp120;
    RwV3d sp110;
    RwV3d sp100;
    u32 localFlag;
    s32 personaActionType;
    u8* battleStateTable;

    (void)&spC0;
    (void)&spB0;
    (void)&spA0;
    (void)&sp90;
    spB0.x = 1.0f;
    spC0.x = 0.0f;
    (void)&sp80;
    (void)&sp70;

    target = action->target.targetedActions[0];
    victim = target;
    specificId = action->target.specificId;
    localFlag = 1;
    someFlag = 1;
    isSkillType = 0;
    isFirstSpecial = 0;
    actionUnit = action->unit;

    packet = FUN_002886e0(NULL, actionUnit, 3);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_00288950(actionUnit, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    action->unk_18 |= 0x200;

    battleStateTable = iGpffffb708;
    if ((battleStateTable[(u32)specificId * 0x2c] & 2) != 0)
    {
        if (actionUnit->genus == UNIT_GENUS_PC)
        {
            if (FUN_0028a0f0(action) != 0)
            {
                if (FUN_002fdb70() != 0)
                {
                    goto position_section;
                }
                someFlag = 0;
                goto unified_end;
            }
            goto genus_dispatch;
        }
        else
        {
            goto genus_dispatch;
        }
    }
    else
    {
        goto specificid_invalid;
    }

position_section:
    {
        f32 checkDist;

        victimUnit = target->unit;
        actionUnit = action->unit;

        FUN_0027ffb0(actionUnit, &spE0);
        FUN_00280480(victimUnit, actionUnit, &spD0);

        checkDist = FUN_002d1ed0(&spE0, &spD0);

        if (checkDist > 500.0f)
        {
            isSkillType = someFlag;
            someFlag = 0;
            goto unified_end;
        }
        extraOffset = checkDist;
        goto unified_end;
    }

genus_dispatch:
    if (actionUnit->genus == UNIT_GENUS_EC)
    {
        if (FUN_002fde40(action, (f32*)&sp120) != 0)
        {
            localFlag = 0;
            goto unified_end;
        }
    }
    goto distance_section;

distance_section:
    {
        u16 distanceType;

        victimUnit = target->unit;
        if (FUN_002d5e10(action) == 0)
        {
            distanceType = (specificId == 11) ? 11 : 4;
        }
        else
        {
            distanceType = 11;
        }

        distance = FUN_002812d0(actionUnit, victimUnit, distanceType);
        extraOffset = distance;

        if ((action->unk_18 & 0x4000) != 0)
        {
            isFirstSpecial = 1;
        }
        goto final_dispatch;
    }

unified_end:
    if ((action->unk_18 & 0x4000) != 0)
    {
        isFirstSpecial = 1;
    }
    goto final_dispatch;

specificid_invalid:
    actionUnit = action->unit;
    if (actionUnit->genus == someFlag)
    {
        goto persona_dispatch_genus_match;
    }
    if (actionUnit->genus == UNIT_GENUS_PC)
    {
        goto genus0_action;
    }
    goto final_dispatch;

persona_dispatch_genus_match:
    victim = action->target.targetedActions[0];
    if (victim == NULL)
    {
        goto final_dispatch;
    }
    /* fall through */

genus0_action:
    victimUnit = target->unit;
    personaUnit = victimUnit->personaUnit;
    personaActionType = func_002d6290(action);

    func_00284040(personaUnit, victimUnit, (s16)specificId, personaActionType);

    personaActionType = FUN_002d63b0(personaUnit, specificId, personaActionType);

    FUN_0027ffb0(victimUnit, &spE0);
    FUN_00280480(victimUnit->personaUnit, victimUnit, &spD0);
    moveSpeed = FUN_002d1ed0(&spE0, &spD0);
    {
        f32 vz = victimUnit->pos.z;
        f32 vy = victimUnit->pos.y;
        f32 pz = victimUnit->personaUnit->pos.z;
        f32 py = victimUnit->personaUnit->pos.y;
        (void)vz;
        (void)vy;
        (void)pz;
        (void)py;
    }

    if (personaActionType == 0)
    {
        goto check_boss_flag2;
    }

    if (FUN_002fdb90() == 0)
    {
        goto check_boss_flag2;
    }
    goto position_check_thresholds;

check_boss_flag2:

position_check_thresholds:
    if (moveSpeed >= 300.0f)
    {
        extraOffset = moveSpeed - 300.0f;
        if (extraOffset >= 200.0f)
        {
            goto compute_vector_offset;
        }
        action->unk_18 |= 0x10;
        someFlag = 0;
        goto final_dispatch;
    }
    goto check_boss_flag2;

check_distance_threshold:
    {
        f32 vz2 = victimUnit->pos.z;
        f32 vy2 = victimUnit->pos.y;
        f32 pz2 = victimUnit->personaUnit->pos.z;
        f32 py2 = victimUnit->personaUnit->pos.y;
        (void)vz2;
        (void)vy2;
        (void)pz2;
        (void)py2;
    }
    goto compute_vector_offset;

compute_vector_offset:
    {
        FUN_0027f940(personaUnit, victimUnit, actionUnit, (s32)(u32)personaActionType, &sp110, NULL, 2);

        spE0.x = sp110.x - spE0.x;
        spE0.y = 0.0f;
        spE0.z = sp110.z - spE0.z;

        FUN_004c6ac0(&spE0);
        extraOffset = extraOffset + moveSpeed;

        if (extraOffset > moveSpeed)
        {
            action->unk_18 |= 0x10;
            someFlag = 0;
        }
        goto final_dispatch;
    }

final_dispatch:
    {
        u16 field_6E;

        if (someFlag != 0)
        {
            btlAction0028a780(action);
        }

        field_6E = action->target.specificId;
        if ((iGpffffb708[(u32)field_6E * 0x2c] & 2) == 0)
        {
            isSkillType = 1;
        }
        else
        {
            isSkillType = 0;
        }

        actionUnit = action->unit;
        {
            u8 unitGenus;
            u32* datUnitPtr;

            datUnitPtr = (u32*)actionUnit->datUnit;
            {
                u16 recordField2 = *(u16*)((u8*)datUnitPtr + 2);
                (void)recordField2;
            }

            unitGenus = actionUnit->genus;

            if (unitGenus == UNIT_GENUS_EC)
            {
                goto enemy_action;
            }
            if (unitGenus == UNIT_GENUS_PC)
            {
                goto pc_action;
            }
            goto no_special_action;
        }
    }

enemy_action:
    {
        actionUnit = action->unit;
        {
            BtlEnemyRecord* enemyEntry = &iGpffffb728[actionUnit->datUnit->id];
            (void)enemyEntry;
        }
        goto enemy_packet_dispatch;
    }

pc_action:
    goto enemy_packet_dispatch;

no_special_action:
    goto enemy_packet_dispatch;

enemy_packet_dispatch:
    {
        actionUnit = action->unit;
        {
            u16 enemyId2 = actionUnit->datUnit->id;
            (void)enemyId2;
        }

        {
            u16 flagsOffset = action->target.specificId;
            u16 commandField2;
            commandField2 = *(u16*)((u8*)iGpffffb710 + (u32)flagsOffset * sizeof(BtlCommandRecord) + 2);
            (void)commandField2;
        }

        if (isFirstSpecial == 1)
        {
            goto create_posrotcol_packet;
        }

        if (isSkillType == 0)
        {
            packet = btlUnitCreateMoveToUnitPacket(actionUnit, victimUnit, extraOffset, moveSpeed, someFlag | 0x40);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
            goto camera_dispatch;
        }
    }

create_posrotcol_packet:
    {
        if (victim == NULL)
        {
            victim = action->target.targetedActions[0];
        }

        if (victim != NULL)
        {
            FUN_0027ffb0(victimUnit, &spE0);
            FUN_00280480(actionUnit, victimUnit, &spD0);

            sp100.x = spE0.x - spD0.x;
            sp100.z = spE0.z - spD0.z;
            sp100.y = 0.0f;

            FUN_004c69f0(&sp100, &sp100);

            sp110.x = spD0.x + sp100.x * (extraOffset + 50.0f);
            sp110.z = spD0.z + sp100.z * (extraOffset + 50.0f);
            sp110.y = spD0.y + sp100.y * (extraOffset + 50.0f);
            sp110.y = victimUnit->pos.y + 8.0f;

            packet = btlUnitCreatePosRotColPacket(victimUnit, &sp110, NULL, NULL);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);

            extraOffset = extraOffset * uGpffff8088;
            someFlag |= 8;
        }
        else
        {
            extraOffset = extraOffset * 1.25f;
        }

        spA0.x = extraOffset;

        if (localFlag == 1)
        {
            packet = btlUnitCreateMoveToUnitPacket(actionUnit, victimUnit, extraOffset, moveSpeed, someFlag | 0x40);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
            goto camera_dispatch;
        }

        {
            f32 distFromHome = FUN_002d1ed0(&actionUnit->pos, &sp120);
            sp90.x = distFromHome;
            if (distFromHome <= 75.0f)
            {
                goto camera_dispatch;
            }
        }

        packet = btlUnitCreateMoveToUnitPacket(actionUnit, victimUnit, extraOffset, moveSpeed, someFlag);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
    }

camera_dispatch:
    if (packet == NULL && isSkillType != 0)
    {
        if (isFirstSpecial != 0)
        {
            goto do_camera_packet_0x13;
        }
        goto do_camera_packet_0x12;
    }

    if (isFirstSpecial != 0)
    {
        goto do_camera_packet_0x13;
    }

    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_MOVETARGET);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    goto epilogue;

do_camera_packet_0x12:
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_MOVETARGET);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    goto epilogue;

do_camera_packet_0x13:
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_MOVETARET_A);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);

epilogue:
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

/* W111: reconstructed MoveHome, RoundUpMes, and RoundUp packet/state paths from retail. */
// FUN_0028e7f0
void btlActionInitStateMoveHome(BtlAction* action)
{
    BtlUnit* unit = action->unit;
    BtlPacket* packet;
    RwV3d homePos;
    u16 commandId;
    u16 nextState;
    u16 allowMove;
    u16 unitDatId;
    u16 speedIdx;
    u8 genus;
    f32 speed;
    BtlUnit* moveUnit;
    BtlEnemyRecord* enemyRecords;

    if ((gBtl->flags & 0x400000) && (BATTLE_U16(0x18) & 2))
    {
        commandId = action->target.commandId;
        switch (commandId)
        {
        case 1:
            nextState = BTLACTION_STATE_ATTACK;
            break;
        case 2:
        case 3:
            nextState = BTLACTION_STATE_SKILL;
            break;
        case 9:
            nextState = BTLACTION_STATE_SUMMON;
            break;
        default:
            nextState = BTLACTION_STATE_NON;
            break;
        }
        btlActionSetState(action, nextState);
        return;
    }

    btlUnit0027f7c0(unit, &homePos, NULL, NULL);
    if (FUN_002d1ed0(&unit->pos, &homePos) > 75.0f)
    {
        btlAction0028a780(action);
        speedIdx = 2;
        allowMove = !(iGpffffb708[(u32)action->target.specificId * 0x2c] & 2);
        moveUnit = action->unit;
        unitDatId = moveUnit->datUnit->id;
        genus = moveUnit->genus;
        switch (genus)
        {
        case UNIT_GENUS_PC:
            break;
        case UNIT_GENUS_EC:
            enemyRecords = iGpffffb728;
            speedIdx = enemyRecords[unitDatId].moveSpeed[allowMove].speedIndex;
            break;
        default:
            break;
        }
        speed = D_00693300[speedIdx];
        speed *= uGpffff8088;
        packet = btlUnitCreateMovePacket(moveUnit, &homePos, speed, 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_MOVEHOME);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
    }
    else
    {
        commandId = action->target.commandId;
        switch (commandId)
        {
        case 1:
            nextState = BTLACTION_STATE_ATTACK;
            break;
        case 2:
        case 3:
            nextState = BTLACTION_STATE_SKILL;
            break;
        case 9:
            nextState = BTLACTION_STATE_SUMMON;
            break;
        default:
            nextState = BTLACTION_STATE_NON;
            break;
        }
        btlActionSetState(action, nextState);
    }
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
extern BtlPacket* func_002b7bd0(BtlUnit*, BtlUnit*, u16, f32);

// FUN_0028eb50 NONMATCHING
void btlActionUpdateStateAttack(BtlAction* action)
{
    BtlAction* victim;
    BtlAction* basis;
    BtlPacket* packet;
    BtlPacket* animPacket;
    BtlPacket* subHitPacket;
    /* Per-caller ABI declarations: the RoundUp caller intentionally uses a float-first signature. */
    extern BtlPacket* FUN_00284200(BtlUnit*, u16, u32, u32, f32);
    extern s64 FUN_002835e0(BtlUnit*, u16, f32);
    extern s16 FUN_00283750(BtlUnit*, u16, f32);
    extern s64 FUN_002838d0(BtlUnit*, u16, f32);
    extern s64 FUN_00283c70(BtlUnit*, u16);
    extern s64 FUN_00283e40(BtlUnit*, u16);
    extern s16* FUN_00283fe0(BtlUnit*, u16);
    extern s32 FUN_002f8eb0(BtlUnit*, u16);
    extern u16 FUN_00308c60(DatUnit*);
    extern u16 FUN_00308ed0(DatUnit*);
    u64 actionUID;
    u64 sp260;
    u64 sp258;
    u32 workBuf[4];
    s16 sp190;
    s16 sp180;
    s16 sp1D0;
    s16 sp1C0;
    s16 sp1B0;
    s16 sp1AE;
    s16 sp1E0;
    s16 sp2BE, sp2BC, sp2BA, sp2B8;
    s32 sp240;
    s32 sp230;
    s32 sp220;
    s32 sp210;
    s32 sp200;
    s32 sp1F0;
    s32 sp160;
    s32 weaponType;
    s32 var_17;
    s32 var_21;
    s32 subHit;
    s32 var_30_2;
    s32 spC0;
    s32 spB0;
    s16* sp17C;
    void* sp270;
    u8 groupCount;
    u8 hitCount;
    u8 sp120;
    u8 unk1f0;
    u8* result;
    f32 var_f20;
    f32 var_f22;
    f32 var_f21;

    btlAction0028a780(action);
    actionUID = action->uid;
    sp260 = 0;
    sp1C0 = 0;
    sp258 = 0;
    sp190 = -1;
    sp180 = -1;
    unk1f0 = (action->unk_18 & 0x4000) != 0;
    var_f20 = unk1f0 ? 1.75f : 1.0f;
    victim = action->target.targetedActions[0];
    basis = ACTION_U32(victim, 0xd4) != 0 ? action : victim;
    if (ACTION_U32(victim, 0xd0) != 0 && action->unit->genus != basis->unit->genus)
    {
        sp1F0 = 1;
    }
    else
    {
        sp1F0 = 0;
    }
    btlPacketRegister(FUN_002bd590(action->unit, action->target.specificId), BTLPACKET_TYPE_2D);
    packet = btlUnitCreateRotateTowardUnitPacket(action->unit, victim->unit, 0);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    sp1D0 = 0;
    groupCount = ACTION_U8(victim, 0xc8);
    hitCount = unk1f0 ? 1 : ACTION_U8(victim, 0xc9);
    sp120 = unk1f0 ? 1 : (FUN_00308f80(action->unit->datUnit) & 0xFF);
    var_f22 = (f32)ACTION_U32(victim, 0xe0) / (f32)hitCount;
    if (ACTION_U16(victim, 0xce) & 6)
    {
        var_f22 *= *(f32*)((u8*)gBtl - 0x7c64);
    }
    var_f21 = 0.0f;
    packet = FUN_002bd480(basis->unit);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    weaponType = FUN_00308c60(action->unit->datUnit) & 0xFF;
    if (action->unit->genus == 0)
    {
        u16 charId = action->unit->charId;
        if (charId == 1)
        {
            sp270 = (u8*)gBtl - 0x482C + weaponType * 8;
        }
        else
        {
            sp270 = (u8*)gBtl - 0x4828 + (charId - 2) * 8;
        }
    }
    else
    {
        sp270 = (u8*)gBtl - 0x67C8;
    }
    {
        u32 sp110 = (ACTION_U32(victim, 0xe8) & 0x100000) != 0;
        u32 sp100 = (ACTION_U16(victim, 0xce) & 6) != 0;
        if (FUN_0028a0f0(action) && (unk1f0 || (!sp100 && !sp110)))
        {
            packet = btlCameraCreateSetStatePacket(action, 0xB);
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }
        packet = btlUnitCreateLookAtUnitPacket(NULL, victim->unit, 3);
        packet->actionUID = actionUID;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (!(ACTION_U16(victim, 0xfa) & 4))
        {
            packet = btlUnitCreateLookAtUnitPacket(victim->unit, action->unit, 0);
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        packet = btlUnitCreateLookAtDeactivatePacket(action->unit, 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        action->unk_18 |= 0x200;
        sp240 = 0;
        for (sp240 = 0; sp240 < groupCount; sp240++)
        {
            u16 resultFlags;
            sp230 = 4;
            var_21 = 0;
            result = (u8*)victim + 0xe0 + sp240 * 0x1c;
            resultFlags = ACTION_U16(result, 0x1a);
            for (var_21 = 0; var_21 < hitCount; var_21++)
            {
                s32 animResult;
                sp160 = 1;
                if (!(resultFlags & 4))
                {
                    if (action->unit->genus == 0)
                    {
                        if (weaponType != 7)
                        {
                            var_17 = *(u8*)((u8*)gBtl - 0x486C + weaponType * 3 + var_21 + 0x18);
                            if (ACTION_U16(victim, 0xcc) & 4)
                            {
                                u16 charId2 = action->unit->charId;
                                switch (charId2)
                                {
                                    case 4:
                                        var_17 = 6;
                                        break;
                                    case 7:
                                        var_17 = 5;
                                        break;
                                    case 8:
                                        var_17 = 5;
                                        break;
                                    default:
                                        if (charId2 == 1 && (FUN_00308c60(action->unit->datUnit) & 0xFF) == 3)
                                        {
                                            var_17 = 5;
                                        }
                                        break;
                                }
                            }
                        }
                        else
                        {
                            s32 wt;
                            sp190 = 2;
                            wt = FUN_003093a0(action->unit->datUnit) & 0xFF;
                            switch (wt)
                            {
                                case 2:
                                    var_17 = 5;
                                    sp180 = 0xD;
                                    break;
                                case 3:
                                    var_17 = 6;
                                    sp180 = 0xE;
                                    break;
                                default:
                                case 1:
                                    var_17 = 4;
                                    sp180 = 0xC;
                                    break;
                            }
                        }
                    }
                    else
                    {
                        var_17 = (s16)FUN_002f8eb0(action->unit, action->target.specificId);
                        if (var_17 == -1)
                        {
                            var_17 = 4;
                        }
                    }
                }
                else
                {
                    var_17 = 0xB;
                }
                if (var_17 != 6 && var_17 != 5 && var_17 != 4)
                {
                    sp17C = NULL;
                    sp210 = 0;
                    sp220 = 1;
                }
                else
                {
                    sp17C = FUN_00283fe0(action->unit, (u16)var_17);
                    if (sp17C == NULL)
                    {
                        sp210 = (s16)FUN_00283e40(action->unit, (u16)var_17);
                    }
                    else
                    {
                        sp210 = 0;
                    }
                    sp220 = (s16)FUN_00283c70(action->unit, (u16)var_17);
                }
                if (sp17C == NULL)
                {
                    var_30_2 = (s16)FUN_002835e0(action->unit, (u16)var_17, var_f20);
                }
                else
                {
                    var_30_2 = *sp17C;
                }
                var_30_2 += sp230;
                animPacket = btlUnitCreateAnimPacket(action->unit, (u16)var_17, (u16)sp230, var_f20,
                                                     var_17 == 0xB ? 2 : 0);
                animPacket->preUpdateDelay = sp1D0;
                animPacket->actionUID = actionUID;
                btlPacketRegister(animPacket, BTLPACKET_TYPE_1);
                if (sp240 == 0 && var_21 == 0 && (sp100 || sp110) && !unk1f0)
                {
                    if (action->unit->genus == 0)
                    {
                        if (sp110)
                        {
                            packet = func_002b7bd0(action->unit, victim->unit, 3, 400.0f);
                            packet->unk_00 = 5;
                            packet->parentUID = animPacket->uid;
                            packet->actionUID = actionUID;
                            btlPacketRegister(packet, BTLPACKET_TYPE_0);
                        }
                        packet = btlCameraCreateSetStatePacket(action, 0xC);
                        packet->unk_00 = 5;
                        packet->parentUID = animPacket->uid;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_0);
                    }
                    else if (sp110)
                    {
                        packet = btlCameraCreateSetStatePacket(action, 0xD);
                        packet->unk_00 = 5;
                        packet->parentUID = animPacket->uid;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_0);
                        *(u32*)((u8*)gBtl + 0xc) |= 0x400000;
                        *(u16*)((u8*)gBtl + 0x18) |= 0xE;
                    }
                    else if (FUN_0028a0f0(action))
                    {
                        packet = btlCameraCreateSetStatePacket(action, 0xB);
                        packet->unk_00 = 5;
                        packet->parentUID = animPacket->uid;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_0);
                    }
                    else
                    {
                        packet = btlCameraCreateSetStatePacket(action, 0xA);
                        packet->unk_00 = 5;
                        packet->parentUID = animPacket->uid;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_0);
                    }
                }
                FUN_0028a540(action, action->target.specificId, (u16*)&sp2BE, (u16*)&sp2BC, (u16*)&sp2BA, (u16*)&sp2B8);
                packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc24 + sp2BE * 4), action->unit, victim->unit, 0, 0);
                packet->unk_00 = 5;
                packet->parentUID = animPacket->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                if (sp240 == 0 && var_21 == 0 && !FUN_0028a0f0(action) && !sp100 && !sp110 && !unk1f0)
                {
                    packet = btlCameraCreateSetStatePacket(action, 0xA);
                    packet->unk_00 = 5;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = var_30_2 < 0xF ? 0 : var_30_2 - 0xF;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_0);
                }
                if (var_21 == hitCount - 1 ||
                    (spC0 = *(s16*)((u8*)sp270 + var_21 * 4), spC0 == -1))
                {
                    spC0 = (s16)FUN_002838d0(action->unit, (u16)var_17, var_f20);
                }
                spC0 = (s16)(spC0 + (s16)sp230);
                sp1D0 += spC0;
                if (var_21 == hitCount - 1 ||
                    (sp230 = *(s8*)((u8*)sp270 + var_21 * 4 + 2), sp230 == -1))
                {
                    sp230 = 4;
                }
                if (var_30_2 < (s16)spC0)
                {
                    sp1E0 = (s16)(*(f32*)((u8*)gBtl - 0x7c64) * (f32)((s16)spC0 - var_30_2));
                }
                else
                {
                    sp1E0 = 0;
                }
                if (ACTION_U32(victim, 0xd0) != 0 || ACTION_U32(victim, 0xd4) != 0)
                {
                    sp1E0 += 0xC;
                }
                if (ACTION_U32(victim, 0xd4) != 0 && ACTION_U16(victim, 0xcc) != 0x400)
                {
                    sp220 = 1;
                }
                else if (ACTION_U16(victim, 0xcc) == 0x400)
                {
                    sp220 = 1;
                    sp160 = 0;
                }
                if ((ACTION_U16(victim, 0xcc) & 4) || (resultFlags & 4))
                {
                    sp160 = 0;
                }
                if (resultFlags & 4)
                {
                    spB0 = var_30_2 >= 7 ? var_30_2 - 6 : 0;
                    animResult = FUN_00283750(action->unit, (u16)var_17, var_f20);
                    if (action->unit->genus == 0)
                    {
                        packet = btlCameraCreateSetStatePacket(action, 0xE);
                        packet->unk_00 = 4;
                        packet->parentUID = animPacket->uid;
                        packet->preUpdateDelay = (s16)spB0;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_0);
                    }
                    packet = FUN_002dd100(0xC, 2, 9);
                    packet->unk_00 = 4;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = (s16)animResult >= 9 ? (s16)animResult - 8 : 0;
                    packet->actionUID = action->uid;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xcf8), action->unit, action->unit, 1, 0);
                    packet->unk_00 = 4;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = (s16)animResult;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                    packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xcf0), action->unit, action->unit, 1, 0);
                    packet->unk_00 = 4;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = (s16)spB0;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                    FUN_002d5dc0(workBuf);
                    workBuf[2] = 0x100000;
                    packet = FUN_002d7e20(action, action, workBuf, 1, 1);
                    packet->unk_00 = 4;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = (s16)(spC0 - (spC0 >> 2));
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    if (action->unit->genus == 1 && !unk1f0)
                    {
                        packet = FUN_002db740(victim, 0x18, 0, 0, 0);
                        packet->unk_00 = 4;
                        packet->parentUID = packet->uid;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                    packet = func_0027f2f0();
                    packet->unk_00 = 5;
                    packet->parentUID = animPacket->uid;
                    packet->preUpdateDelay = (s16)spC0;
                    packet->postUpdateDelay = 0xC;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    if (!unk1f0)
                    {
                        packet = btlVoice002e2be0(action, 0xA, 0, 0, 0);
                        packet->unk_00 = 4;
                        packet->parentUID = packet->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                    *(u32*)((u8*)gBtl + 0xc) |= 0x400000;
                    *(u16*)((u8*)gBtl + 0x18) |= 0xF;
                }
                for (subHit = 0; subHit < sp220; subHit++)
                {
                    sp200 = (s8)ACTION_U8(result, 0x18);
                    if ((sp200 == 0x12 || sp200 == 8) &&
                        (var_21 != hitCount - 1 || subHit != sp220 - 1))
                    {
                        sp200 = 2;
                    }
                    subHitPacket = btlUnitCreateAnimPacket(basis->unit, (u16)(s16)sp200, 0, 1.0f, 0);
                    subHitPacket->unk_00 = 4;
                    subHitPacket->parentUID = animPacket->uid;
                    if (sp200 != -3 && sp200 != 0x16)
                    {
                        subHitPacket->preUpdateDelay = var_30_2;
                    }
                    else
                    {
                        subHitPacket->preUpdateDelay = var_30_2 >= 7 ? var_30_2 - 6 : 0;
                    }
                    if (ACTION_U32(victim, 0xd4) != 0)
                    {
                        subHitPacket->preUpdateDelay += 5;
                    }
                    subHitPacket->actionUID = actionUID;
                    btlPacketRegister(subHitPacket, BTLPACKET_TYPE_1);
                    sp260 = subHitPacket->uid;
                    if (sp240 == 0 && var_21 == 0 && subHit == 0)
                    {
                        sp258 = sp260;
                    }
                    if ((ACTION_U16(victim, 0xcc) & 4) && !(resultFlags & 4) && !unk1f0)
                    {
                        packet = btlVoice002e2be0(action, 0x18, 0, 0, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                    if (subHit != sp220 - 1 || var_21 != hitCount - 1)
                    {
                        if (*(u32*)((u8*)gBtl + 0xc) & 0x10)
                        {
                            var_f21 += var_f22 / (f32)sp220;
                        }
                        packet = FUN_002bd230(basis->unit, 0, (u32)(s16)var_f21);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        packet->unk_47 &= ~0x20;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
                    }
                    if (ACTION_U32(victim, 0xd4) != 0)
                    {
                        u32 d4Pool = FUN_002fd160(victim);
                        if (d4Pool == 0)
                        {
                            d4Pool = *(u32*)((u8*)gBtl + 0xc8c);
                        }
                        packet = FUN_002baf90(d4Pool, action->unit, victim->unit, 1, 0);
                        packet->unk_00 = 4;
                        packet->parentUID = animPacket->uid;
                        packet->preUpdateDelay = (s16)var_30_2 + 5;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                        packet = FUN_002dd100(0xD, 2, 6);
                        packet->unk_00 = 4;
                        packet->parentUID = animPacket->uid;
                        packet->preUpdateDelay = (s16)var_30_2 + 5;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                    if (ACTION_U16(victim, 0xcc) == 0x400)
                    {
                        packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc90), action->unit, basis->unit, 1, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                        packet = FUN_002dd100(0xC, 2, 7);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                        sp1C0 = 0xA;
                    }
                    if (sp190 >= 0 && sp180 >= 0)
                    {
                        packet = FUN_002dd100(0xC, (u32)(u16)sp190, (u32)(u16)sp180);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                        sp190 = -1;
                        sp180 = -1;
                    }
                    if (sp160)
                    {
                        if ((sp110 || sp100) && hitCount == sp120 &&
                            subHit == sp220 - 1 && var_21 == hitCount - 1)
                        {
                            packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc58), action->unit, basis->unit, 1, 0);
                            packet->unk_00 = 5;
                            packet->parentUID = subHitPacket->uid;
                            packet->actionUID = actionUID;
                            btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                        }
                        else if (hitCount >= 2 && (var_21 != 0 || subHit != 0))
                        {
                            packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc54), action->unit, basis->unit, 1, 0);
                            packet->unk_00 = 5;
                            packet->parentUID = subHitPacket->uid;
                            btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                            if (!sp110 && !sp100)
                            {
                                packet = btlCameraCreateSetStatePacket(action, 0xF);
                                packet->unk_00 = 5;
                                packet->parentUID = subHitPacket->uid;
                                btlPacketRegister(packet, BTLPACKET_TYPE_0);
                            }
                        }
                        packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc24 + sp2BE * 4), action->unit, basis->unit, 1, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                        if (action->unit->genus == 0)
                        {
                            s32 val6 = 0;
                            u16 charId3 = action->unit->charId;
                            sp1AE = 0;
                            switch (charId3)
                            {
                                case 4:
                                    if (var_21 == 2 && subHit == sp220 - 1)
                                    {
                                        val6 = 4;
                                    }
                                    break;
                                case 8:
                                    if (var_21 == 1 && subHit == sp220 - 1)
                                    {
                                        val6 = 4;
                                    }
                                    break;
                                case 9:
                                    if (var_21 == 1 && subHit == sp220 - 1)
                                    {
                                        val6 = 4;
                                    }
                                    break;
                            }
                            if ((s16)val6 == 0)
                            {
                                u16 ed0 = FUN_00308ed0(action->unit->datUnit) & 0xFFFF;
                                val6 = *(s16*)((u8*)D_00690E20 + ed0 * 2);
                            }
                            if (sp1AE >= 0 && (s16)val6 >= 0)
                            {
                                packet = FUN_002dd100(0xA, (u32)(u16)sp1AE, (u32)(u16)val6);
                                packet->unk_00 = 5;
                                packet->parentUID = subHitPacket->uid;
                                btlPacketRegister(packet, BTLPACKET_TYPE_1);
                            }
                        }
                        else
                        {
                            sp1AE = 0;
                        }
                        packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc4c), action->unit, basis->unit, 1, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = subHitPacket->uid;
                        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                        if (var_21 == hitCount - 1 && subHit == sp220 - 1 && (ACTION_U16(victim, 0xce) & 6))
                        {
                            packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc24 + sp2BC * 4), action->unit, basis->unit, 1, 0);
                            packet->unk_00 = 5;
                            packet->parentUID = subHitPacket->uid;
                            btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                            packet = FUN_002dd100(0xC, 0, 9);
                            packet->unk_00 = 5;
                            packet->parentUID = subHitPacket->uid;
                            btlPacketRegister(packet, BTLPACKET_TYPE_1);
                        }
                        if (subHit == sp220 - 1 && var_21 == hitCount - 1)
                        {
                            sp1B0 = -1;
                            if (ACTION_U16(victim, 0xce) & 6)
                            {
                                sp1B0 = sp2B8;
                            }
                            else if (hitCount >= 2 || (action->unit->genus == 0 && FUN_0028a0f0(action)))
                            {
                                sp1B0 = sp2BA;
                            }
                            if (sp1B0 >= 0)
                            {
                                packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xc24 + sp1B0 * 4), action->unit, basis->unit, 1, 0);
                                packet->unk_00 = 5;
                                packet->parentUID = subHitPacket->uid;
                                btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                            }
                        }
                    }
                    packet = btlUnitCreateRotateTowardUnitPacket(victim->unit, action->unit, 2);
                    packet->unk_00 = 5;
                    packet->parentUID = sp260;
                    packet->unk_47 &= ~0x20;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    if (subHit != sp220 - 1)
                    {
                        s32 delayDelta;
                        if (sp17C != NULL)
                        {
                            delayDelta = sp17C[subHit * 2 + 1] - sp17C[subHit * 2];
                        }
                        else
                        {
                            delayDelta = sp210;
                        }
                        if (var_f20 != 1.0f)
                        {
                            delayDelta = (s32)((f32)delayDelta / var_f20);
                        }
                        var_30_2 += delayDelta;
                        if (delayDelta < sp1E0)
                        {
                            sp1E0 -= (s16)delayDelta;
                        }
                        else
                        {
                            sp1E0 = 0;
                        }
                    }
                }
            }
            if ((ACTION_U32(result, 0x8) & 0x100000) && !unk1f0)
            {
                BtlPacket* tailPacket = FUN_00282130(basis->unit, 0x10);
                tailPacket->unk_00 = 5;
                tailPacket->parentUID = sp260;
                tailPacket->preUpdateDelay = 1;
                tailPacket->postUpdateDelay = 0xC;
                tailPacket->actionUID = actionUID;
                btlPacketRegister(tailPacket, BTLPACKET_TYPE_1);
                if (ACTION_U32(victim, 0xd0) == 0)
                {
                    packet = FUN_002baf90(*(u32*)((u8*)gBtl + 0xcf4), basis->unit, basis->unit, 1, 0);
                    packet->unk_00 = 5;
                    packet->parentUID = tailPacket->uid;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_3D);
                }
                packet = FUN_00284c90(basis->unit);
                packet->unk_00 = 5;
                packet->parentUID = tailPacket->uid;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            packet = FUN_002d7e20(action, basis, result, ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce));
            packet->unk_00 = 5;
            packet->parentUID = sp260;
            packet->preUpdateDelay = sp1C0;
            packet->postUpdateDelay = sp1E0;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002d8090(victim);
            packet->unk_00 = 5;
            packet->parentUID = sp260;
            packet->preUpdateDelay = sp1C0;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            if (sp240 == groupCount - 1)
            {
                packet = FUN_002d8090(action);
                packet->unk_00 = 5;
                packet->parentUID = sp260;
                packet->preUpdateDelay = sp1C0;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            if (sp240 == 0 && !(action->unk_18 & 4))
            {
                packet = FUN_002d7fb0(action, ACTION_U8(action, 0xca));
                packet->unk_00 = 5;
                packet->parentUID = sp260;
                packet->preUpdateDelay = sp1C0;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
            if (sp240 == groupCount - 1)
            {
                s16 wd = ACTION_S16(action, 0xdc);
                if (wd != 0)
                {
                    packet = FUN_002bd850(action->unit, wd);
                    packet->unk_00 = 5;
                    packet->parentUID = sp260;
                    packet->unk_47 &= ~0x20;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
                }
                else
                {
                    s16 vwd = ACTION_S16(victim, 0xdc);
                    if (vwd != 0)
                    {
                        packet = FUN_002bd850(victim->unit, vwd);
                        packet->unk_00 = 5;
                        packet->parentUID = sp260;
                        packet->unk_47 &= ~0x20;
                        packet->actionUID = actionUID;
                        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
                    }
                }
            }
            packet = FUN_002bdbd0(action->unit, basis->unit, action->target.specificId,
                                  ACTION_U16(victim, 0xcc), ACTION_U16(victim, 0xce), 0, 1, result);
            packet->unk_00 = 5;
            packet->parentUID = subHitPacket->uid;
            packet->preUpdateDelay = sp1C0;
            packet->unk_47 &= ~0x20;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            if (sp240 == 0 && ACTION_U32(result, 0) != 0)
            {
                packet = FUN_002bd230(basis->unit, 0, 0);
                packet->unk_00 = 5;
                packet->parentUID = subHitPacket->uid;
                packet->preUpdateDelay = sp1C0;
                packet->unk_47 &= ~0x20;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            }
            if (!unk1f0 && basis->unit->genus == 1)
            {
                if (sp1F0 > 0)
                {
                    if (action->unit->genus == 0)
                    {
                        u32 checkVal = FUN_002d4e10(2, 0x80000) & 0xffff;
                        if ((s32)action->unk_28 <= 0 && action->unit->charId != 1 && FUN_002ffbc0(0x64) < 0x32)
                        {
                            u32 hasOverride = 0;
                            if (action->unit->genus != 0)
                            {
                                hasOverride = 0;
                            }
                            else
                            {
                                s32 gBtVal = *(s32*)((u8*)gBtl + 0xa38);
                                if (gBtVal != -1)
                                {
                                    s32 diff = (s16)(checkVal - sp1F0);
                                    if (diff <= 0)
                                    {
                                        u32 chk2 = FUN_002d4e10(2, 0x80000) & 0xffff;
                                        if ((*(s16*)((u8*)gBtl + 0xa3a) >> 1) >= chk2)
                                        {
                                            s16 personaId = *(s16*)((u8*)gBtl + 0xa38);
                                            if (personaId != (s16)FUN_002b7060())
                                            {
                                                hasOverride = 1;
                                            }
                                        }
                                    }
                                    else if ((*(s16*)((u8*)gBtl + 0xa3a) >> 1) >= diff)
                                    {
                                        hasOverride = 1;
                                    }
                                }
                            }
                            if (hasOverride)
                            {
                                packet = FUN_002db740(action, 0x16, sp1F0, 0, 0);
                                packet->unk_00 = 5;
                                packet->parentUID = sp260;
                                packet->actionUID = actionUID;
                                btlPacketRegister(packet, BTLPACKET_TYPE_1);
                            }
                            else
                            {
                                packet = btlVoice002e2be0(action, 0xD, sp1F0, 0, 0);
                                packet->unk_00 = 5;
                                packet->parentUID = sp260;
                                btlPacketRegister(packet, BTLPACKET_TYPE_1);
                            }
                        }
                    }
                }
                else if (ACTION_U32(result, 0x8) & 0x100000)
                {
                    packet = FUN_002db740(action, 0x17, ACTION_U16(victim, 0xce), 0, 0);
                    packet->unk_00 = 5;
                    packet->parentUID = sp260;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                }
                else if (sp1F0 == 0)
                {
                    if (func_002d6130(action))
                    {
                        packet = btlVoice002e2be0(action, 0xE, 0, 0, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = sp260;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                    else if (func_002d6210(action) == 1 && func_002d5f50(action) == 0)
                    {
                        u16 targetId = FUN_003082f0(action->unit->datUnit, action->target.specificId);
                        packet = btlVoice002e2be0(action, 0xF, (s32)(s16)targetId, 0, 0);
                        packet->unk_00 = 5;
                        packet->parentUID = sp260;
                        btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    }
                }
            }
            if (ACTION_U16(result, 0x1a) & 1)
            {
                FUN_002d5dc0(workBuf);
                workBuf[3] = 0x100000;
                packet = FUN_002d7e20(victim, victim, workBuf, 1, 1);
                packet->unk_00 = 4;
                packet->parentUID = sp258;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
                if (ACTION_U16(result, 0x1a) & 2)
                {
                    packet = FUN_00284200(victim->unit, 10, 0, 0, 1.0f);
                    packet->unk_00 = 4;
                    packet->parentUID = sp258;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                    packet = FUN_00284c90(victim->unit);
                    packet->unk_00 = 4;
                    packet->parentUID = sp258;
                    packet->actionUID = actionUID;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                }
            }
        }
        if (FUN_002dc130(action))
        {
            btlActionSetState(action, BTLACTION_STATE_PERSONA);
            return;
        }
        {
            s32 subState = ACTION_S32(action, 0x6c);
            if (subState == 2 || subState == 3 || subState == 1)
            {
                btlActionSetState(action, BTLACTION_STATE_EXIT);
            }
            else
            {
                btlActionSetState(action, BTLACTION_STATE_EXIT);
            }
        }
    }
}
// FUN_00290bd0
void btlActionInitStateSkill(BtlAction* action)
{
    (void)action;
}


extern u32 func_0027fc80(BtlUnit *);
extern u32 func_00280870(s32, u32, RwV3d *, u32, u32, u32);
extern s64 func_002835e0(BtlUnit *, u16, f32);
/* This skill path keeps the u32 argument live; other callers intentionally use u16. */
extern s64 func_002838d0(BtlUnit *, u32, f32);
extern u16 func_00283a70(BtlUnit *, u32);
extern s64 func_002b7060(u32);
extern s32 func_002b8f90(u32);
extern f32 func_002b9590(BtlUnit *);
extern u64 func_002b9640(u8 *);
extern s32 func_002d1600(BtlTarget *);
extern s32 func_002d4cc0(u16);
extern s32 func_002d4e10(u32, u32);
extern s32 func_002d5bf0(BtlUnit *);
extern s32 func_002d5c70(BtlUnit *);
extern u32 func_002d5dc0(s32 *);
extern s32 func_002d5eb0(BtlAction *);
extern s32 func_002d5f50(BtlAction *);
extern s32 func_002d5fb0(BtlAction *);
extern s32 func_002d6090(BtlAction *);
extern s32 func_002d6130(BtlAction *);
extern s32 func_002d6210(BtlAction *);
extern s32 func_002d6290(BtlAction *);
extern s32 func_002d62d0(BtlAction *);
extern u64 func_002d6370(s16);
extern s32 func_002dc130(BtlAction *);
extern s32 func_002ddc80(u16);
extern s64 func_002f8fd0(BtlUnit *, s16);
extern s64 func_002f9690(BtlUnit *);
extern s32 func_002fcaa0(BtlAction *, u32 *);
extern u32 func_002fd060(BtlAction *);
extern s32 func_002fd160(BtlAction *);
extern s32 func_002fdbb0(BtlAction *, BtlUnit *);
extern s32 func_002fdcb0(BtlUnit *);
extern u32 func_002fddb0(BtlUnit *, RwV3d *);
extern s32 func_002fded0(s16);
extern s64 func_003082f0(DatUnit *, u16);
extern u64 func_00308a50(u16);

extern BtlPacket* func_002d8330(BtlAction*);
extern BtlPacket* btlUnit00286240(BtlUnit*);
extern BtlPacket* btlUnit002860b0(BtlUnit*);
extern BtlPacket* func_002e35d0(u16, u16);
extern BtlPacket* func_002e36f0(void);
extern BtlPacket* func_002e37e0(void);
extern BtlPacket* func_002dd8e0(BtlUnit*);
extern BtlPacket* func_002dd100(u32, u32, u32);
extern BtlPacket* func_002b8900(BtlAction*, u32, u32);
extern BtlPacket* func_002b8b70(BtlUnit*, BtlAction*, BtlAction*, u16);
extern BtlPacket* func_002e3de0(u32, u32);
extern BtlPacket* func_002e3f20(void);
extern BtlPacket* func_002dd690(u16, s8*);
extern BtlPacket* func_002bac00(s32, s8*, u16);
extern BtlPacket* func_002baf90(s32, BtlUnit*, BtlUnit*, u32);
extern BtlPacket* func_002bd480(BtlUnit*, ...);
extern BtlPacket* func_002bd230(BtlUnit*, u32, u32);
extern BtlPacket* btlUnit002843e0(BtlUnit*, u16);
extern BtlPacket* btlUnit00284f50(BtlUnit*, u16, f32, u16);
extern BtlPacket* btlUnit00284c90(BtlUnit*);
extern BtlPacket* btlUnit002857f0(BtlUnit*);
extern BtlPacket* func_002dd5e0(u16);
extern BtlPacket* func_0027f410(u32, BtlAction*);
extern BtlPacket* func_002b7bd0(BtlUnit*, BtlUnit*, u16, f32);
extern BtlPacket* func_0029fa50(u32);
extern BtlPacket* func_002a1080(u32, u16);
extern BtlPacket* func_002a16c0(u32);
extern BtlPacket* func_002a1db0(u32);
extern DatPersonaWork* datPersonaGetByPcId(u16);
extern BtlPacket* func_002dd960(BtlUnit*);
extern BtlPacket* func_002bd590(BtlUnit*, s32);
extern BtlPacket* func_002bd690(BtlUnit*, u16);
extern BtlPacket* func_002bd850(BtlUnit*, s16);
extern BtlPacket* func_002bdbd0(BtlUnit*, BtlUnit*, s32, ...);
extern BtlPacket* func_002d7e20(BtlAction*, BtlAction*, void*, u32, ...);
extern BtlPacket* func_002d8090(BtlAction*);
extern BtlPacket* func_002d7fb0(BtlAction*, u32);
extern BtlPacket* func_002db740(BtlAction*, u16, ...);
/* Skill-state reconstruction is complete; remaining drift is MWCC local-layout codegen. */
// FUN_00290be0 NONMATCHING
void btlActionUpdateStateSkill(BtlAction *action) {
    extern u8 *gp0xffffb714;
    u32 sp53C;
    u32 sp538;
    u32 sp530;
    u32 sp52C;
    u32 sp528;
    RwV3d sp518;
    s32 sp4FC;
    s32 sp4F8;
    s32 sp4F4;
    s32 sp4F0;
    s8 sp470;
    BtlAction *sp460;
    BtlUnit *sp450;
    BtlPacket *sp44C;
    BtlPacket *sp448;
    BtlPacket *sp444;
    BtlPacket *sp440;
    BtlPacket *sp43C;
    s32 sp438;
    u64 sp420;
    u64 sp410;
    u64 sp400;
    s16 sp3F0;
    s16 sp3E0;
    s16 sp3D0;
    s16 sp3C0;                                      /* compiler-managed */
    s32 sp3B0;
    s32 sp3A0;
    s32 sp390;
    s32 sp380;
    u16 sp370;
    u16 sp360;
    u16 sp350;
    u16 sp340;
    u16 sp330;
    u16 sp320;
    u16 sp310;
    u16 sp300;
    s32 sp2F0;
    s32 sp2EC;
    s32 sp2D0;
    s32 sp2C0;
    s32 sp2B0;
    s32 sp2AC;
    s32 sp290;
    s32 sp280;
    s32 sp27C;
    s32 sp260;
    u16 sp250;
    u16 sp240;
    s32 sp230;
    s32 *sp220;
    BtlPacket *sp21C;
    BtlPacket *sp218;
    BtlPacket *sp214;
    s16 sp200;
    void *sp1FC;
    u64 sp1E0;
    u64 sp1D0;
    u64 sp1C0;
    u64 sp1B0;
    u64 sp1A0;
    u64 sp190;
    u64 sp180;
    u64 sp170;
    u64 sp160;
    u64 sp150;
    u64 sp140;
    u64 sp130;
    u64 sp120;
    u64 sp110;
    u64 sp100;
    u64 spF0;
    u64 spE0;
    u64 spD0;
    u64 spC0;
    u64 spB0;
    BtlAction *temp_s2_3;
    BtlAction *temp_v0_64;
    BtlAction *var_a2;
    BtlAction *var_s5_2;
    BtlPacket *temp_v0_101;
    BtlPacket *temp_v0_102;
    BtlPacket *temp_v0_103;
    BtlPacket *temp_v0_104;
    BtlPacket *temp_v0_105;
    BtlPacket *temp_v0_106;
    BtlPacket *temp_v0_107;
    BtlPacket *temp_v0_108;
    BtlPacket *temp_v0_109;
    BtlPacket *temp_v0_10;
    BtlPacket *temp_v0_110;
    BtlPacket *temp_v0_111;
    BtlPacket *temp_v0_112;
    BtlPacket *temp_v0_113;
    BtlPacket *temp_v0_114;
    BtlPacket *temp_v0_115;
    BtlPacket *temp_v0_117;
    BtlPacket *temp_v0_118;
    BtlPacket *temp_v0_119;
    BtlPacket *temp_v0_11;
    BtlPacket *temp_v0_120;
    BtlPacket *temp_v0_121;
    BtlPacket *temp_v0_122;
    BtlPacket *temp_v0_123;
    BtlPacket *temp_v0_125;
    BtlPacket *temp_v0_126;
    BtlPacket *temp_v0_127;
    BtlPacket *temp_v0_128;
    BtlPacket *temp_v0_129;
    BtlPacket *temp_v0_12;
    BtlPacket *temp_v0_130;
    BtlPacket *temp_v0_131;
    BtlPacket *temp_v0_132;
    BtlPacket *temp_v0_133;
    BtlPacket *temp_v0_134;
    BtlPacket *temp_v0_136;
    BtlPacket *temp_v0_137;
    BtlPacket *temp_v0_138;
    BtlPacket *temp_v0_139;
    BtlPacket *temp_v0_13;
    BtlPacket *temp_v0_140;
    BtlPacket *temp_v0_141;
    BtlPacket *temp_v0_142;
    BtlPacket *temp_v0_143;
    BtlPacket *temp_v0_144;
    BtlPacket *temp_v0_145;
    BtlPacket *temp_v0_146;
    BtlPacket *temp_v0_147;
    BtlPacket *temp_v0_148;
    BtlPacket *temp_v0_149;
    BtlPacket *temp_v0_14;
    BtlPacket *temp_v0_150;
    BtlPacket *temp_v0_151;
    BtlPacket *temp_v0_152;
    BtlPacket *temp_v0_153;
    BtlPacket *temp_v0_154;
    BtlPacket *temp_v0_155;
    BtlPacket *temp_v0_156;
    BtlPacket *temp_v0_157;
    BtlPacket *temp_v0_158;
    BtlPacket *temp_v0_159;
    BtlPacket *temp_v0_15;
    BtlPacket *temp_v0_160;
    BtlPacket *temp_v0_161;
    BtlPacket *temp_v0_162;
    BtlPacket *temp_v0_163;
    BtlPacket *temp_v0_164;
    BtlPacket *temp_v0_165;
    BtlPacket *temp_v0_166;
    BtlPacket *temp_v0_167;
    BtlPacket *temp_v0_16;
    BtlPacket *temp_v0_17;
    BtlPacket *temp_v0_18;
    BtlPacket *temp_v0_19;
    BtlPacket *temp_v0_20;
    BtlPacket *temp_v0_21;
    BtlPacket *temp_v0_22;
    BtlPacket *temp_v0_23;
    BtlPacket *temp_v0_24;
    BtlPacket *temp_v0_25;
    BtlPacket *temp_v0_26;
    BtlPacket *temp_v0_27;
    BtlPacket *temp_v0_28;
    BtlPacket *temp_v0_29;
    BtlPacket *temp_v0_32;
    BtlPacket *temp_v0_33;
    BtlPacket *temp_v0_34;
    BtlPacket *temp_v0_35;
    BtlPacket *temp_v0_36;
    BtlPacket *temp_v0_37;
    BtlPacket *temp_v0_38;
    BtlPacket *temp_v0_39;
    BtlPacket *temp_v0_3;
    BtlPacket *temp_v0_40;
    BtlPacket *temp_v0_41;
    BtlPacket *temp_v0_42;
    BtlPacket *temp_v0_43;
    BtlPacket *temp_v0_44;
    BtlPacket *temp_v0_45;
    BtlPacket *temp_v0_46;
    BtlPacket *temp_v0_48;
    BtlPacket *temp_v0_49;
    BtlPacket *temp_v0_4;
    BtlPacket *temp_v0_50;
    BtlPacket *temp_v0_51;
    BtlPacket *temp_v0_52;
    BtlPacket *temp_v0_53;
    BtlPacket *temp_v0_54;
    BtlPacket *temp_v0_55;
    BtlPacket *temp_v0_56;
    BtlPacket *temp_v0_57;
    BtlPacket *temp_v0_58;
    BtlPacket *temp_v0_59;
    BtlPacket *temp_v0_5;
    BtlPacket *temp_v0_60;
    BtlPacket *temp_v0_61;
    BtlPacket *temp_v0_62;
    BtlPacket *temp_v0_63;
    BtlPacket *temp_v0_65;
    BtlPacket *temp_v0_66;
    BtlPacket *temp_v0_67;
    BtlPacket *temp_v0_68;
    BtlPacket *temp_v0_69;
    BtlPacket *temp_v0_6;
    BtlPacket *temp_v0_70;
    BtlPacket *temp_v0_71;
    BtlPacket *temp_v0_72;
    BtlPacket *temp_v0_73;
    BtlPacket *temp_v0_74;
    BtlPacket *temp_v0_75;
    BtlPacket *temp_v0_76;
    BtlPacket *temp_v0_77;
    BtlPacket *temp_v0_78;
    BtlPacket *temp_v0_79;
    BtlPacket *temp_v0_7;
    BtlPacket *temp_v0_80;
    BtlPacket *temp_v0_81;
    BtlPacket *temp_v0_82;
    BtlPacket *temp_v0_83;
    BtlPacket *temp_v0_84;
    BtlPacket *temp_v0_85;
    BtlPacket *temp_v0_86;
    BtlPacket *temp_v0_87;
    BtlPacket *temp_v0_88;
    BtlPacket *temp_v0_89;
    BtlPacket *temp_v0_8;
    BtlPacket *temp_v0_90;
    BtlPacket *temp_v0_91;
    BtlPacket *temp_v0_92;
    BtlPacket *temp_v0_93;
    BtlPacket *temp_v0_94;
    BtlPacket *temp_v0_95;
    BtlPacket *temp_v0_96;
    BtlPacket *temp_v0_97;
    BtlPacket *temp_v0_99;
    BtlPacket *temp_v0_9;
    BtlPacket *var_s1_2;
    BtlPacket *var_s1_3;
    BtlPacket *var_s2_4;
    BtlPacket *var_s3;
    BtlPacket *var_s3_3;
    BtlPacket *var_v0_6;
    BtlUnit *temp_a0;
    BtlUnit *temp_a0_10;
    BtlUnit *temp_a0_13;
    BtlUnit *temp_a0_14;
    BtlUnit *temp_a0_6;
    BtlUnit *temp_a0_8;
    BtlUnit *temp_a1;
    BtlUnit *temp_a1_2;
    BtlUnit *temp_a1_3;
    BtlUnit *temp_a1_4;
    BtlUnit *temp_a1_7;
    BtlUnit *temp_v0;
    BtlUnit *temp_v1_15;
    BtlUnit *var_a2_2;
    f32 temp_f20;
    u64 temp_v0_2;
    u64 var_a1;
    s16 temp_a1_5;
    s16 temp_a1_6;
    s16 temp_s3_4;
    s16 temp_s7;
    s16 temp_v1_11;
    s16 var_s2_2;
    s16 var_v0_12;
    s16 var_v0_4;
    s16 var_v1_2;
    s32 *temp_v0_124;
    s32 temp_a0_2;
    s32 temp_a0_9;
    s32 temp_fp;
    s32 temp_s2;
    s32 temp_s3_3;
    s32 temp_v0_100;
    s32 temp_v0_47;
    s32 temp_v0_98;
    s32 temp_v1_10;
    s32 temp_v1_5;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s64 temp_s3;
    s64 temp_s3_2;
    s64 temp_v0_30;
    s32 temp_v0_31;
    s64 temp_v1_12;
    s64 var_s1;
    s64 var_s2;
    s64 var_s2_3;
    s32 var_v0;
    s64 var_v1;
    s32 var_s6;
    u16 temp_a2;
    u16 temp_v1;
    u16 temp_v1_16;
    u16 temp_v1_2;
    u16 temp_v1_6;
    u16 var_a3;
    u16 var_v1_3;
    u32 temp_a0_12;
    u32 var_v0_5;
    u64 temp_s0;
    u64 temp_s2_2;
    u64 temp_s2_4;
    u64 var_s3_2;
    u64 var_s5;
    u8 temp_v1_14;
    u8 var_a2_3;
    void *temp_a0_11;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_7;
    void *temp_v0_116;
    void *temp_v0_135;
    void *temp_v1_13;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_7;
    void *temp_v1_8;
    void *temp_v1_9;

    u64 saved_reg_s1, saved_reg_s2, saved_reg_s5;
    BtlPacket *saved_reg_s3;
    var_s1 = saved_reg_s1;
    var_s2 = saved_reg_s2;
    var_s3 = saved_reg_s3;
    var_s5 = saved_reg_s5;
    temp_v0 = action->unit;
    var_s6 = (s8) temp_v0->genus;
    sp450 = temp_v0->personaUnit;
    temp_s7 = (s16) action->target.specificId;
    sp460 = action->target.targetedActions[0];
    sp410 = 0;
    sp400 = 0;
    sp390 = 0;
    sp380 = 0;
    sp320 = 0;
    sp3D0 = 0;
    sp3A0 = 0;
    sp2F0 = 0;
    sp2D0 = 0;
    sp2C0 = 0;
    sp2B0 = 0;
    sp2AC = 0;
    sp290 = 0;
    sp280 = 0;
    sp27C = 0;
    sp300 = 6;
    sp1E0 = (*(iGpffffb708 + (temp_s7 * 0x2C)) & 2) != 0;
    temp_v0_2 = (action->unk_1a & 0x10) != 0;
    sp1D0 = temp_v0_2;
    if (temp_v0_2 != 0) {
        sp1D0 = sp1E0 == 0;
    }
    sp1C0 = action->target.commandId == 3;
    sp2EC = func_002d6290(action);
    sp1B0 = func_002d6370(temp_s7);
    sp1A0 = func_00308a50(action->target.originalSpecificId);
    sp440 = NULL;
    temp_s0 = action->uid;
    btlAction0028a780(action);
    sp438 = func_002b8f90(1);
    if (action->unk_18 & 0x100) {
        var_s6 = -1;
    }
    sp310 = 1;
    var_s6 = (s64) ((s64) var_s6 << 0x38) >> 0x38;
    if (var_s6 == 0) {
        temp_a0 = action->unit;
        temp_v1 = temp_a0->charId;
        if ((temp_v1 != 0xA) && (temp_v1 != 3)) {

        } else {
            sp310 = 0x10;
        }
        if ((func_002d5bf0(temp_a0) != 0) || (func_002d5c70(action->unit) != 0)) {
            sp310 = 0x10;
        }
    } else if (var_s6 == 1) {
        temp_v1_2 = action->unit->charId;
        if ((temp_v1_2 != 0xEE) && (temp_v1_2 != 0xE9) && (temp_v1_2 != 0x126) && (temp_v1_2 != 0x110) && (temp_v1_2 != 0x10B)) {

        } else {
            sp310 = 0x10;
        }
    }
    if (var_s6 >= 0) {
        if (sp2EC != 0) {
            temp_v0_3 = btlUnitCreateRotateTowardUnitPacket(action->unit, action->target.targetedActions[0]->unit, 0U);
            temp_v0_3->actionUID = temp_s0;
            btlPacketRegister(temp_v0_3, 0U);
        } else if (var_s6 == 0) {
            func_00280870(func_002d1600(&action->target) & 0xFFFF, 1, &sp518, 0, 0, 1);
            temp_v0_4 = btlUnitCreateRotatePacket(action->unit, &sp518, 0U);
            temp_v0_4->actionUID = temp_s0;
            btlPacketRegister(temp_v0_4, 0U);
        } else if (func_002fdcb0(action->unit) != 0) {
            func_002fddb0(action->unit, &sp518);
            temp_v0_5 = btlUnitCreateRotatePacket(action->unit, &sp518, 0U);
            temp_v0_5->actionUID = temp_s0;
            btlPacketRegister(temp_v0_5, 0U);
        }
        temp_v0_6 = btlUnitCreateLookAtUnitPacket(NULL, action->unit, 3U);
        temp_v0_6->actionUID = action->uid;
        btlPacketRegister(temp_v0_6, 1U);
        temp_v0_7 = btlUnitCreateLookAtDeactivatePacket(action->unit, 0U);
        temp_v0_7->actionUID = action->uid;
        btlPacketRegister(temp_v0_7, 1U);
        action->unk_18 |= 0x200;
        temp_v0_8 = func_002d8330(action);
        temp_v0_8->actionUID = temp_s0;
        btlPacketRegister(temp_v0_8, 1U);
    }
    temp_fp = temp_s7 * 0x1C;
    if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x100) {
        var_v0 = 3;
    } else {
        var_v0 = 1;
    }
    sp190 = (u64) ((s64) (var_v0 << 0x30) >> 0x30);
    if (sp1C0 == 0) {
        temp_v0_9 = func_002bd590(action->unit, temp_s7 & 0xFFFF);
        temp_v0_9->preUpdateDelay = (s16) sp190;
        temp_v0_9->actionUID = temp_s0;
        btlPacketRegister(temp_v0_9, 3U);
    } else {
        temp_v0_10 = func_002bd690(action->unit, action->target.unk_38);
        temp_v0_10->preUpdateDelay = (s16) sp190;
        temp_v0_10->actionUID = temp_s0;
        btlPacketRegister(temp_v0_10, 3U);
    }
    if ((sp1D0 == 1) && (var_s6 != -1)) {
        if ((sp1C0 == 0) && (sp1A0 == 0)) {
            if (var_s6 == 0) {
                if (!(action->unk_18 & 0x40) && ((temp_s2 = func_002ddc80(action->unit->charId), (func_002d5eb0(action) != 0)) || (temp_s2 != 0))) {
                    var_s1 = (s16)func_002e33f0(action);
                    if ((var_s1 != -1) && ((datCalcRand(0x64U) < 0x14U) || (temp_s2 != 0))) {
                        sp2F0 = 1;
                        action->unk_18 |= 0x40;
                    }
                }
            } else if ((var_s6 == 1) && !(action->unk_18 & 0x40)) {
                var_s1 = (s16)func_002e33f0(action);
                if (var_s1 != -1) {
                    sp2F0 = 1;
                    action->unk_18 |= 0x40;
                }
            }
            if (func_002fcaa0(action, &sp528) == 0) {
                temp_v1_3 = (u8*)gBtl;
                sp528 = (*(u32*)((u8*)gBtl + 0xC94));
                sp52C = (*(u32*)((u8*)gBtl + 0xC98));
                sp530 = (*(u32*)((u8*)gBtl + 0xC9C));
            }
            if ((func_002d6370(temp_s7) == 0) && (func_002d5f50(action) == 0)) {
                temp_a0_2 = func_002d1600(&action->target) & 0xFFFF;
                if ((var_s6 == 0) && ((temp_a0_2 & 0xFFFF) == 2)) {
                    sp2D0 = (effMiscRand(NULL) & 1) != 0;
                } else if ((var_s6 == 1) && ((temp_a0_2 & 0xFFFF) == 1)) {
                    sp2D0 = 1;
                }
            }
            if ((func_002fdbb0(action, sp450) != 0) || ((*(u32*)((u8*)gBtl + 0x10)) & 0x40)) {
                sp2D0 = 1;
            }
            if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x4000) {
                sp2D0 = 1;
                sp3A0 = 0xC;
            }
            if ((var_s6 == 0) && (func_002d62d0(action) != 0) && (temp_s7 != 0xEA)) {
                sp280 = 1;
                sp2D0 = 1;
                sp2F0 = 0;
                temp_v0_11 = btlUnitCreateLookAtDeactivatePacket(NULL, 3U);
                temp_v0_11->actionUID = action->uid;
                btlPacketRegister(temp_v0_11, 1U);
                temp_a0_3 = (u8*)gBtl;
                (*(u32*)((u8*)gBtl + 0xC)) = (s32) ((*(u32*)((u8*)gBtl + 0xC)) | 0x400000);
                temp_v1_4 = (u8*)gBtl;
                *(u16*)((u8*)gBtl + 0x18) = (u16)(*(u16*)((u8*)gBtl + 0x18) | 6);
            }
            if ((var_s6 == 0) && (func_002d5fb0(action) != 0)) {
                btlPacketRegister(btlVoice002e2be0(action, 0x10, 0, 0, 0), 1U);
            } else if (sp2F0 != 0) {
                temp_v0_12 = func_002dd960(action->unit);
                temp_v0_12->actionUID = temp_s0;
                btlPacketRegister(temp_v0_12, 1U);
            }
            if (var_s6 == 1) {
                var_v1 = (s64) (func_002f9690(action->unit) << 0x30) >> 0x30;
                if (var_v1 == -1) {
                    var_v1 = 6;
                }
            } else {
                var_v1 = 6;
            }
            temp_v0_13 = btlUnitCreateAnimPacket(action->unit, 0xCU, var_v1 & 0xFFFF, 1.0f, 4U);
            temp_v0_13->actionUID = temp_s0;
            btlPacketRegister(temp_v0_13, 1U);
            var_s3_2 = temp_v0_13->uid;
            if (var_s6 == 0) {
                temp_v0_14 = btlUnit00286240(action->unit);
                temp_v0_14->unk_00 = 4;
                temp_v0_14->parentUID = var_s3_2;
                temp_v0_14->actionUID = temp_s0;
                btlPacketRegister(temp_v0_14, 1U);
                temp_v0_15 = btlUnit002860b0(action->unit);
                temp_v0_15->unk_00 = 4;
                temp_v0_15->parentUID = var_s3_2;
                temp_v0_15->preUpdateDelay = 6;
                temp_v0_15->actionUID = temp_s0;
                btlPacketRegister(temp_v0_15, 1U);
            }
            var_s2_2 = ((s64) (func_002838d0(action->unit, 0xC, 1.0f) << 0x30) >> 0x30) + 6;
            if (var_s6 == 0) {
                var_v0_2 = 0x10;
            } else {
                var_v0_2 = 0x11;
            }
            temp_v0_16 = btlCameraCreateSetStatePacket(action, var_v0_2 & 0xFFFF);
            temp_v0_16->actionUID = temp_s0;
            btlPacketRegister(temp_v0_16, 0U);
            var_s5 = temp_v0_16->uid;
            if (sp2F0 != 0) {
                temp_v0_17 = func_002e35d0(var_s1 & 0xFFFF, sp450->charId);
                temp_v0_17->unk_00 = 4;
                temp_v0_17->parentUID = var_s3_2;
                temp_v0_17->actionUID = temp_s0;
                btlPacketRegister(temp_v0_17, 1U);
                temp_v0_18 = func_002e36f0();
                temp_v0_18->unk_00 = 4;
                temp_v0_18->parentUID = temp_v0_17->uid;
                temp_v0_18->actionUID = temp_s0;
                btlPacketRegister(temp_v0_18, 1U);
                temp_v0_19 = btlVoice002e2be0(action, 0xC, (s32) sp450->charId, 0, 0);
                temp_v0_19->unk_00 = 5;
                temp_v0_19->parentUID = temp_v0_18->uid;
                temp_v0_19->actionUID = temp_s0;
                btlPacketRegister(temp_v0_19, 1U);
                temp_v0_20 = func_002dd100(0xA, 2, 0x12U);
                temp_v0_20->unk_00 = 5;
                temp_v0_20->parentUID = temp_v0_18->uid;
                temp_v0_20->preUpdateDelay = 5;
                temp_v0_20->actionUID = temp_s0;
                btlPacketRegister(temp_v0_20, 1U);
                temp_v0_21 = func_002dd8e0(action->unit);
                temp_v0_21->unk_00 = 4;
                temp_v0_21->parentUID = temp_v0_18->uid;
                temp_v0_21->actionUID = temp_s0;
                btlPacketRegister(temp_v0_21, 1U);
                var_s3_2 = temp_v0_18->uid;
                sp400 = var_s3_2;
                var_s2_2 = 0;
                temp_v0_22 = func_002e37e0();
                temp_v0_22->unk_00 = 4;
                temp_v0_22->parentUID = var_s3_2;
                temp_v0_22->actionUID = temp_s0;
                btlPacketRegister(temp_v0_22, 1U);
            }
            temp_v0_23 = func_002b8900(action, (action->unk_18 & 0x10) != 0, 1);
            temp_v0_23->unk_00 = 4;
            temp_v0_23->parentUID = var_s3_2;
            temp_v0_23->preUpdateDelay = var_s2_2 - (var_s2_2 >> 3);
            temp_v0_23->actionUID = temp_s0;
            btlPacketRegister(temp_v0_23, 0U);
            sp410 = temp_v0_23->uid;
            if (sp2EC != 0) {
                var_a2 = action->target.targetedActions[0];
            } else {
                var_a2 = NULL;
            }
            temp_v0_24 = func_002b8b70(sp450, action, var_a2, temp_s7 & 0xFFFF);
            temp_v0_24->unk_00 = 5;
            temp_v0_24->parentUID = sp410;
            temp_v0_24->actionUID = temp_s0;
            btlPacketRegister(temp_v0_24, 0U);
            if (sp2F0 != 0) {
                temp_v0_25 = btlUnitCreateModelPacket(sp450, sp450->charId, 0x1DU);
                var_s1_2 = temp_v0_25;
                temp_v0_25->unk_00 = 5;
                temp_v0_25->parentUID = sp400;
                temp_v0_25->postUpdateWaits[0].type = 5;
                temp_v0_25->postUpdateWaits[0].value = sp410;
            } else {
                temp_v0_26 = btlUnitCreateModelPacket(sp450, sp450->charId, 0xDU);
                var_s1_2 = temp_v0_26;
                temp_v0_26->preUpdateDelay = var_s2_2;
            }
            var_s1_2->actionUID = temp_s0;
            btlPacketRegister(var_s1_2, 1U);
            temp_v0_27 = func_0027f2f0();
            temp_v0_27->unk_00 = 4;
            temp_v0_27->parentUID = var_s1_2->uid;
            temp_v0_27->preUpdateDelay = 0xC;
            temp_v0_27->actionUID = temp_s0;
            btlPacketRegister(temp_v0_27, 1U);
            temp_v0_28 = func_002bb2f0(sp528, action->unit, 0U, temp_v0_27->uid, 0);
            temp_v0_28->actionUID = temp_s0;
            btlPacketRegister(temp_v0_28, 2U);
            temp_v0_29 = func_002dd100(0xA, 2, 0U);
            temp_v0_29->actionUID = temp_s0;
            btlPacketRegister(temp_v0_29, 1U);
            temp_a1 = action->unit;
            temp_v0_30 = (s16)func_00284040(temp_a1->personaUnit, temp_a1, temp_s7, sp2EC);
            sp3F0 = (s16) temp_v0_30;
            temp_v0_31 = (s64) (func_002835e0(action->unit->personaUnit, temp_v0_30 & 0xFFFF, 1.0f) << 0x30) >> 0x30;
            sp3B0 = (s32) temp_v0_31;
            sp300 = func_00283a70(action->unit, 0xF);
            var_s1 = (s64) var_s1_2->uid;
            temp_v1_5 = temp_v0_31 + 0x12;
            if (sp3A0 < temp_v1_5) {
                var_s2 = temp_v1_5 - sp3A0;
            } else {
                var_s2 = 0;
            }
            temp_v0_32 = btlUnitCreateAnimPacket(action->unit, 0xEU, 0U, 1.0f, 5U);
            temp_v0_32->unk_00 = 4;
            temp_v0_32->parentUID = (u64) var_s1;
            temp_v0_32->actionUID = temp_s0;
            btlPacketRegister(temp_v0_32, 1U);
            temp_s3 = (s64) (func_002835e0(action->unit, 0xEU, 1.0f) << 0x30) >> 0x30;
            temp_v0_33 = func_002bb2f0(sp52C, action->unit, 0U, 0U, 0);
            temp_v0_33->unk_00 = 4;
            temp_v0_33->parentUID = (u64) var_s1;
            temp_v0_33->preUpdateDelay = (s16) temp_s3;
            temp_v0_33->actionUID = temp_s0;
            btlPacketRegister(temp_v0_33, 2U);
            temp_v0_34 = func_002dd100(0xC, 2, sp310);
            temp_v0_34->unk_00 = 4;
            temp_v0_34->parentUID = (u64) var_s1;
            temp_v0_34->preUpdateDelay = (s16) temp_s3;
            temp_v0_34->actionUID = temp_s0;
            btlPacketRegister(temp_v0_34, 1U);
            temp_v0_35 = func_002bb2f0(sp530, action->unit, 0U, 0U, 0);
            temp_v0_35->unk_00 = 4;
            temp_v0_35->parentUID = (u64) var_s1;
            temp_v0_35->actionUID = temp_s0;
            btlPacketRegister(temp_v0_35, 2U);
            temp_v0_36 = func_002dd100(0xD, 2, 2U);
            temp_v0_36->unk_00 = 4;
            temp_v0_36->parentUID = (u64) var_s1;
            temp_v0_36->actionUID = temp_s0;
            btlPacketRegister(temp_v0_36, 1U);
            temp_v0_37 = btlUnit00285d30(action->unit, 0xFF808080U, 0, 0xC, 0, 0);
            temp_v0_37->unk_00 = 4;
            temp_v0_37->parentUID = (u64) var_s1;
            temp_v0_37->actionUID = temp_s0;
            btlPacketRegister(temp_v0_37, 1U);
            temp_v0_38 = btlUnitCreateAnimPacket(sp450, (u16) sp3F0, 0U, 1.0f, 2U);
            var_s3 = temp_v0_38;
            temp_v0_38->unk_00 = 4;
            temp_v0_38->parentUID = (u64) var_s1;
            temp_v0_38->preUpdateDelay = 0xF;
            temp_v0_38->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
            temp_v0_39 = btlUnit00285d30(sp450, func_0027fc80(sp450), 8, 0, 0, 0);
            temp_v0_39->unk_00 = 4;
            temp_v0_39->parentUID = var_s3->uid;
            temp_v0_39->actionUID = temp_s0;
            btlPacketRegister(temp_v0_39, 1U);
            if ((sp2D0 == 1) && (sp280 == 0) && !((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x40)) {
                if (var_s6 == 0) {
                    var_v0_3 = 0x15;
                } else {
                    var_v0_3 = 0x16;
                }
                temp_v0_40 = btlCameraCreateSetStatePacket(action, var_v0_3 & 0xFFFF);
                temp_v0_40->unk_00 = 4;
                temp_v0_40->parentUID = var_s3->uid;
                if (sp3B0 >= sp3A0) {
                    var_v0_4 = sp3B0 - sp3A0;
                } else {
                    var_v0_4 = 0;
                }
                temp_v0_40->preUpdateDelay = var_v0_4;
                temp_v0_40->actionUID = temp_s0;
                btlPacketRegister(temp_v0_40, 0U);
            }
            sp420 = var_s3->uid;
        } else if ((sp1C0 == 0) && (sp1A0 == 1)) {
            temp_v0_41 = btlUnitCreateAnimPacket(action->unit, 0xCU, 6U, 1.0f, 4U);
            temp_v0_41->actionUID = temp_s0;
            btlPacketRegister(temp_v0_41, 1U);
            temp_s2_2 = temp_v0_41->uid;
            temp_s3_2 = (s64) (func_002838d0(action->unit, 0xC, 1.0f) << 0x30) >> 0x30;
            temp_v0_42 = btlCameraCreateSetStatePacket(action, 0x10U);
            temp_v0_42->unk_00 = 4;
            temp_v0_42->parentUID = temp_s2_2;
            temp_v0_42->actionUID = temp_s0;
            btlPacketRegister(temp_v0_42, 0U);
            var_s5 = temp_v0_42->uid;
            temp_v0_43 = func_002e3de0(action->unit->charId, action->target.originalSpecificId);
            temp_v0_43->unk_00 = 4;
            temp_v0_43->parentUID = temp_s2_2;
            temp_v0_43->preUpdateDelay = temp_s3_2 + 6;
            temp_v0_43->actionUID = temp_s0;
            btlPacketRegister(temp_v0_43, 1U);
            temp_v0_44 = func_002e3f20();
            temp_v0_44->unk_00 = 4;
            temp_v0_44->parentUID = temp_v0_43->uid;
            temp_v0_44->preUpdateDelay = 0x17;
            temp_v0_44->actionUID = temp_s0;
            btlPacketRegister(temp_v0_44, 1U);
            temp_v0_45 = func_002dd690(3, (s8 *)(D_00693318_abs + 0x10));
            temp_v0_45->unk_00 = 5;
            temp_v0_45->parentUID = temp_v0_44->uid;
            temp_v0_45->actionUID = temp_s0;
            btlPacketRegister(temp_v0_45, 1U);
            temp_a2 = action->target.originalSpecificId;
            if ((temp_a2 != 0x11D) && (temp_a2 != 0x11C) && (temp_a2 != 0x117) && (temp_a2 != 0x114) && (temp_a2 != 0x113)) {
                sprintf((char*)&sp470, (char *)(D_00693318_abs + 0x20), temp_a2);
                temp_v0_46 = func_002dd690(3, &sp470);
                temp_v0_46->unk_00 = 0xA;
                temp_v0_46->parentUID = 0x400;
                temp_v0_46->preUpdateWait.type = 0xA;
                temp_v0_46->preUpdateWait.value = 0x903;
                temp_v0_46->actionUID = temp_s0;
                btlPacketRegister(temp_v0_46, 1U);
            }
            sp400 = temp_v0_43->uid;
            sp2F0 = 1;
            temp_v1_6 = *((u8*)iGpffffb710 + 2 + temp_fp);
            if (temp_v1_6 & 0x400) {
                sp200 = 0x18;
            } else {
                sp200 = 0x19;
            }
            if (temp_v1_6 & 0x1000) {
                temp_v0_47 = func_002d62d0(action);
                sp27C = temp_v0_47;
                if (temp_v0_47 != 0) {
                    sp280 = 1;
                }
                temp_v0_48 = btlUnitCreateLookAtDeactivatePacket(NULL, 3U);
                temp_v0_48->actionUID = action->uid;
                btlPacketRegister(temp_v0_48, 1U);
                temp_a0_4 = (u8*)gBtl;
                (*(u32*)((u8*)gBtl + 0xC)) = (s32) ((*(u32*)((u8*)gBtl + 0xC)) | 0x400000);
                temp_v1_7 = (u8*)gBtl;
                *(u16*)((u8*)gBtl + 0x18) = (u16)(*(u16*)((u8*)gBtl + 0x18) | 6);
            }
            temp_v0_49 = btlUnitCreateAnimPacket(action->unit, 0x17U, 0U, 1.0f, 2 & 0xFFFF);
            temp_v0_49->unk_00 = 4;
            temp_v0_49->parentUID = sp400;
            temp_v0_49->actionUID = temp_s0;
            btlPacketRegister(temp_v0_49, 1U);
            temp_v0_50 = func_0027f2f0();
            temp_v0_50->unk_00 = 4;
            temp_v0_50->parentUID = temp_v0_49->uid;
            temp_v0_50->preUpdateDelay = 0xC;
            temp_v0_50->actionUID = temp_s0;
            btlPacketRegister(temp_v0_50, 1U);
            temp_v0_51 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xC94)), action->unit, 0U, temp_v0_50->uid, 0);
            temp_v0_51->actionUID = temp_s0;
            btlPacketRegister(temp_v0_51, 2U);
            temp_v0_52 = func_002dd100(0xA, 2, 0U);
            temp_v0_52->actionUID = temp_s0;
            btlPacketRegister(temp_v0_52, 1U);
            temp_v0_53 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xC98)), action->unit, 0U, 0U, 0);
            temp_v0_53->unk_00 = 4;
            temp_v0_53->parentUID = temp_v0_49->uid;
            temp_v0_53->actionUID = temp_s0;
            btlPacketRegister(temp_v0_53, 2U);
            temp_v0_54 = func_002dd100(0xC, 2, sp310);
            temp_v0_54->unk_00 = 4;
            temp_v0_54->parentUID = temp_v0_49->uid;
            temp_v0_54->actionUID = temp_s0;
            btlPacketRegister(temp_v0_54, 1U);
            temp_v0_55 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xC9C)), action->unit, 0U, 0U, 0);
            temp_v0_55->unk_00 = 4;
            temp_v0_55->parentUID = temp_v0_49->uid;
            temp_v0_55->actionUID = temp_s0;
            btlPacketRegister(temp_v0_55, 2U);
            temp_v0_56 = func_002dd100(0xD, 2, 2U);
            temp_v0_56->unk_00 = 4;
            temp_v0_56->parentUID = temp_v0_49->uid;
            temp_v0_56->actionUID = temp_s0;
            btlPacketRegister(temp_v0_56, 1U);
            temp_v0_57 = btlUnitCreateAnimPacket(action->unit, (u16) sp200, 0U, 1.0f, 2U);
            var_s3 = temp_v0_57;
            temp_v0_57->unk_00 = 4;
            temp_v0_57->parentUID = temp_v0_44->uid;
            var_s3->preUpdateDelay = func_002838d0(action->unit, 0x17, 1.0f);
            var_s3->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
            var_s1 = (s64) var_s3->uid;
            var_s2 = (s64) (func_002835e0(action->unit, (u16) sp200, 1.0f) << 0x30) >> 0x30;
            temp_v0_58 = func_0027f2f0();
            sp214 = temp_v0_58;
            temp_v0_58->unk_00 = 4;
            temp_v0_58->parentUID = var_s3->uid;
            temp_v0_58->preUpdateDelay = 0xC;
            temp_v0_58->actionUID = temp_s0;
            btlPacketRegister(temp_v0_58, 1U);
            temp_v0_59 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xC94)), action->unit, 0U, temp_v0_58->uid, 0);
            temp_v0_59->unk_00 = 4;
            temp_v0_59->parentUID = sp400;
            temp_v0_59->actionUID = temp_s0;
            btlPacketRegister(temp_v0_59, 2U);
            temp_v0_60 = func_002dd100(0xA, 2, 0U);
            temp_v0_60->unk_00 = 4;
            temp_v0_60->parentUID = sp400;
            temp_v0_60->actionUID = temp_s0;
            btlPacketRegister(temp_v0_60, 1U);
            temp_v0_61 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xD0C)), action->unit, 0U, 0U, 0);
            temp_v0_61->unk_00 = 4;
            temp_v0_61->parentUID = var_s3->uid;
            temp_v0_61->preUpdateDelay = 0;
            temp_v0_61->actionUID = temp_s0;
            btlPacketRegister(temp_v0_61, 2U);
            temp_v0_62 = func_002dd100(0xE, 2, 3U);
            temp_v0_62->unk_00 = 4;
            temp_v0_62->parentUID = var_s3->uid;
            temp_v0_62->preUpdateDelay = 0;
            temp_v0_62->actionUID = temp_s0;
            btlPacketRegister(temp_v0_62, 1U);
            temp_v0_63 = btlUnit00285d30(action->unit, 0xFF808080U, 0, 0xC, 0, 0);
            temp_v0_63->unk_00 = 4;
            temp_v0_63->parentUID = var_s3->uid;
            temp_v0_63->actionUID = temp_s0;
            btlPacketRegister(temp_v0_63, 1U);
            if (((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x1000) && (sp27C == 0)) {
                temp_v0_64 = action->target.targetedActions[0];
                sp460 = temp_v0_64;
                temp_v0_65 = btlCameraCreateSetStatePacket(action, 0x15U);
                temp_v0_65->unk_00 = 4;
                temp_v0_65->parentUID = (u64) var_s1;
                temp_v0_65->preUpdateDelay = (s16) var_s2;
                temp_v0_65->actionUID = temp_s0;
                btlPacketRegister(temp_v0_65, 0U);
                temp_v0_66 = btlUnitCreateRotateTowardUnitPacket(temp_v0_64->unit, action->unit, 2U);
                temp_v0_66->unk_00 = 4;
                temp_v0_66->parentUID = (u64) var_s1;
                temp_v0_66->preUpdateDelay = (s16) var_s2;
                temp_v0_66->actionUID = temp_s0;
                btlPacketRegister(temp_v0_66, 0U);
            }
            sp410 = var_s3->uid;
        } else if ((sp1C0 == 1) && (sp1A0 == 0)) {
            if ((var_s6 == 0) && (func_002d62d0(action) != 0) && (temp_s7 != 0xEA)) {
                sp280 = 1;
                sp2D0 = 1;
                temp_v0_67 = btlUnitCreateLookAtDeactivatePacket(NULL, 3U);
                temp_v0_67->actionUID = action->uid;
                btlPacketRegister(temp_v0_67, 1U);
                temp_a0_5 = (u8*)gBtl;
                (*(u32*)((u8*)gBtl + 0xC)) = (s32) ((*(u32*)((u8*)gBtl + 0xC)) | 0x400000);
                temp_v1_8 = (u8*)gBtl;
                *(u16*)((u8*)gBtl + 0x18) = (u16)(*(u16*)((u8*)gBtl + 0x18) | 6);
            }
            temp_v0_68 = btlUnitCreateAnimPacket(action->unit, 0x15U, 6U, 1.0f, 0U);
            var_s3 = temp_v0_68;
            temp_v0_68->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
            var_s5 = var_s3->uid;
            var_s1 = 0;
            var_s2 = ((s64) (func_002838d0(action->unit, 0x15, 1.0f) << 0x30) >> 0x30) + 6;
            if (!((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x40)) {
                if (func_002d6290(action) == 1) {
                    temp_v0_69 = func_002b8900(action, 0, 1);
                    temp_v0_69->unk_00 = 4;
                    temp_v0_69->parentUID = var_s3->uid;
                    temp_v0_69->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_69, 0U);
                }
                if (sp2D0 == 0) {
                    temp_v0_70 = btlCameraCreateSetStatePacket(action, 0x15U);
                    temp_v0_70->unk_00 = 4;
                    temp_v0_70->parentUID = var_s3->uid;
                    temp_v0_70->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_70, 0U);
                } else {
                    temp_v0_71 = btlCameraCreateSetStatePacket(action, 0x17U);
                    temp_v0_71->unk_00 = 4;
                    temp_v0_71->parentUID = var_s3->uid;
                    temp_v0_71->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_71, 0U);
                }
            }
            temp_v0_72 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xD04)), action->unit, var_s2 + 6, 0U, 0);
            temp_v0_72->unk_00 = 4;
            temp_v0_72->parentUID = var_s3->uid;
            btlPacketRegister(temp_v0_72, 1U);
        }
    } else if ((sp1D0 == 0) && (var_s6 != -1)) {
        sp2B0 = 1;
        if ((sp1E0 == 1) || (func_002d6370(temp_s7) != 0)) {
            if ((sp1E0 == 1) || (var_s2_3 = (s64) (func_002f8fd0(action->unit, temp_s7) << 0x30) >> 0x30, (var_s2_3 == -1))) {
                var_s2_3 = 4;
            }
            var_a3 = 2;
        } else {
            var_s2_3 = (s64) (func_002f8fd0(action->unit, temp_s7) << 0x30) >> 0x30;
            if (var_s2_3 == -1) {
                var_s2_3 = 7;
            }
            var_a3 = 3;
        }
        temp_a0_6 = action->unit;
        if ((temp_a0_6->genus == 1) && ((*(u16*)((u8*)iGpffffb728 + temp_a0_6->charId * 0xE8 + 0x18)) & 1)) {
            var_a3 = 0;
            sp2AC = 1;
            sp2B0 = 0;
        }
        if (!((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x100)) {
            temp_v0_73 = btlUnitCreateAnimPacket(temp_a0_6, (u16) var_s2_3, 6U, 1.0f, var_a3);
            var_s3 = temp_v0_73;
            temp_v0_73->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
            temp_v0_74 = btlCameraCreateSetStatePacket(action, 0x11U);
            temp_v0_74->unk_00 = 4;
            temp_v0_74->parentUID = var_s3->uid;
            temp_v0_74->actionUID = temp_s0;
            btlPacketRegister(temp_v0_74, 0U);
        } else {
            temp_v0_75 = func_0027f2f0();
            var_s3 = temp_v0_75;
            temp_v0_75->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
        }
        var_s5 = var_s3->uid;
        var_s1 = 0;
        var_s2 = ((s64) (func_002835e0(action->unit, var_s2_3 & 0xFFFF, 1.0f) << 0x30) >> 0x30) + 6;
        if (!((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x40)) {
            temp_v0_76 = func_002b8900(action, (action->unk_18 & 0x10) != 0, 1);
            sp218 = temp_v0_76;
            temp_v0_76->unk_00 = 4;
            temp_v0_76->parentUID = var_s3->uid;
            if (var_s2 >= 0xD) {
                var_v1_2 = var_s2 - 0xC;
            } else {
                var_v1_2 = 0;
            }
            sp218->preUpdateDelay = var_v1_2;
            sp218->actionUID = temp_s0;
            btlPacketRegister(sp218, 0U);
            sp410 = sp218->uid;
            temp_v0_77 = btlCameraCreateSetStatePacket(action, 0x16U);
            temp_v0_77->unk_00 = 4;
            temp_v0_77->parentUID = sp410;
            temp_v0_77->actionUID = temp_s0;
            btlPacketRegister(temp_v0_77, 0U);
        }
        if (sp1E0 == 0) {
            var_v0_5 = func_002fd060(action);
            if (var_v0_5 == 0) {
                var_v0_5 = (*(u32*)((u8*)gBtl + 0xCA8));
            }
            temp_v0_78 = func_002bb2f0(var_v0_5, action->unit, var_s2 + 6, 0U, 0);
            temp_v0_78->unk_00 = 4;
            temp_v0_78->parentUID = var_s3->uid;
            btlPacketRegister(temp_v0_78, 1U);
            temp_v0_79 = func_002dd100(0xA, 2, 5U);
            temp_v0_79->unk_00 = 4;
            temp_v0_79->parentUID = var_s3->uid;
            btlPacketRegister(temp_v0_79, 1U);
        }
    } else {
        var_s5 = 0;
        var_s1 = 0;
        var_s2 = 0;
        if (action->unk_18 & 0x100) {
            temp_v0_80 = func_002e35d0(6, (*(u16*)((u8*)datPersonaGetByPcId(6) + 2)));
            sp21C = temp_v0_80;
            temp_v0_80->unk_00 = 4;
            temp_v0_80->parentUID = (u64) saved_reg_s3;
            temp_v0_80->actionUID = temp_s0;
            btlPacketRegister(temp_v0_80, 1U);
            temp_v0_81 = func_002e36f0();
            temp_v0_81->unk_00 = 4;
            temp_v0_81->parentUID = sp21C->uid;
            temp_v0_81->actionUID = temp_s0;
            btlPacketRegister(temp_v0_81, 1U);
            temp_v0_82 = func_002dd690(3, (s8 *)(D_00693318_abs + 0x30));
            temp_v0_82->unk_00 = 5;
            temp_v0_82->parentUID = temp_v0_81->uid;
            temp_v0_82->actionUID = temp_s0;
            btlPacketRegister(temp_v0_82, 1U);
            var_s1 = (s64) temp_v0_81->uid;
            temp_v0_83 = func_002e37e0();
            temp_v0_83->unk_00 = 4;
            temp_v0_83->parentUID = (u64) var_s1;
            temp_v0_83->actionUID = temp_s0;
            btlPacketRegister(temp_v0_83, 1U);
            temp_v0_84 = btlCameraCreateSetStatePacket(action, 4U);
            temp_v0_84->unk_00 = 4;
            temp_v0_84->parentUID = (u64) var_s1;
            temp_v0_84->preUpdateDelay = 4;
            temp_v0_84->actionUID = temp_s0;
            btlPacketRegister(temp_v0_84, 0U);
            sp280 = 1;
            temp_v0_85 = btlUnitCreateLookAtDeactivatePacket(NULL, 3U);
            temp_v0_85->actionUID = action->uid;
            btlPacketRegister(temp_v0_85, 1U);
            temp_a0_7 = (u8*)gBtl;
            (*(u32*)((u8*)gBtl + 0xC)) = (s32) ((*(u32*)((u8*)gBtl + 0xC)) | 0x400000);
            temp_v1_9 = (u8*)gBtl;
            *(u16*)((u8*)gBtl + 0x18) = (u16)(*(u16*)((u8*)gBtl + 0x18) | 6);
        } else {
            temp_v0_86 = btlCameraCreateSetStatePacket(action, 0x25U);
            temp_v0_86->actionUID = temp_s0;
            btlPacketRegister(temp_v0_86, 0U);
        }
    }
    sp250 = temp_s7 & 0xFFFF;
    func_0029ea60(sp250, &sp53C, &sp538);
    temp_v0_87 = func_0029f4b0(sp53C, sp538, 0x10U);
    temp_v0_87->unk_00 = 4;
    temp_v0_87->parentUID = var_s5;
    temp_v0_87->actionUID = temp_s0;
    btlPacketRegister(temp_v0_87, 1U);
    sp1FC = func_0029ec00(sp250);
    func_0029ec80(sp250, &sp53C, &sp538);
    temp_v0_88 = func_002a0050(sp1FC, sp53C, sp538, 0x10U, 0);
    temp_v0_88->unk_00 = 4;
    temp_v0_88->parentUID = var_s5;
    temp_v0_88->actionUID = temp_s0;
    btlPacketRegister(temp_v0_88, 1U);
    sp240 = temp_s7 & 0xFFFF;
    temp_v0_89 = func_002a1280(func_0029ec50(sp240), 0x10U);
    temp_v0_89->unk_00 = 4;
    temp_v0_89->parentUID = var_s5;
    temp_v0_89->actionUID = temp_s0;
    btlPacketRegister(temp_v0_89, 1U);
    temp_v0_90 = func_002a1b00(action, sp240, 8U);
    temp_v0_90->unk_00 = 4;
    temp_v0_90->parentUID = var_s5;
    temp_v0_90->actionUID = temp_s0;
    btlPacketRegister(temp_v0_90, 1U);
    func_002bb6f0(sp240, &sp470);
    if (sp2F0 != 0) {
        temp_v0_91 = func_0027f2f0();
        temp_v0_91->unk_00 = 4;
        temp_v0_91->parentUID = (u64) var_s1;
        temp_v0_91->preUpdateDelay = (s16) var_s2;
        btlPacketRegister(temp_v0_91, 1U);
        temp_v0_92 = func_002bac00(sp438, &sp470, 1);
        sp44C = temp_v0_92;
        temp_v0_92->unk_00 = 5;
        temp_v0_92->parentUID = sp400;
        temp_v0_92->postUpdateWaits[0].type = 5;
        temp_v0_92->postUpdateWaits[0].value = temp_v0_91->uid;
        temp_v0_92->actionUID = temp_s0;
        btlPacketRegister(temp_v0_92, 1U);
        temp_v0_93 = btlSoundCreateSkillSEPacket(sp250, 1U);
        sp448 = temp_v0_93;
        temp_v0_93->unk_00 = 5;
        temp_v0_93->parentUID = sp400;
        btlPacketRegister(temp_v0_93, 1U);
    } else {
        temp_v0_94 = func_002bac00(sp438, &sp470, 0);
        sp44C = temp_v0_94;
        temp_v0_94->unk_00 = 4;
        temp_v0_94->parentUID = (u64) var_s1;
        temp_v0_94->preUpdateDelay = (s16) var_s2;
        temp_v0_94->actionUID = temp_s0;
        btlPacketRegister(temp_v0_94, 1U);
        temp_v0_95 = btlSoundCreateSkillSEPacket(sp250, 0U);
        sp448 = temp_v0_95;
        temp_v0_95->unk_00 = 4;
        temp_v0_95->parentUID = sp44C->uid;
        btlPacketRegister(temp_v0_95, 1U);
    }
    if (action->target.targetedCount == 1) {
        var_a2_2 = sp460->unit;
    } else {
        var_a2_2 = action->unit;
    }
    temp_v0_96 = func_002baf90(sp438, action->unit, var_a2_2, 0);
    var_s1_3 = temp_v0_96;
    temp_v0_96->unk_00 = 4;
    temp_v0_96->parentUID = sp44C->uid;
    temp_v0_96->preUpdateWait.type = 4;
    temp_v0_96->preUpdateWait.value = sp448->uid;
    if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x80) {
        var_s1_3->actionUID = temp_s0;
    }
    btlPacketRegister(var_s1_3, 2U);
    sp180 = (u64) var_s1_3->uid;
    temp_v0_97 = func_002dd5e0(0);
    temp_v0_97->unk_00 = 5;
    temp_v0_97->parentUID = var_s1_3->uid;
    btlPacketRegister(temp_v0_97, 1U);
    temp_v0_98 = func_002fded0(temp_s7);
    if (temp_v0_98 != 0) {
        temp_v0_99 = func_0027f410(temp_v0_98, action);
        temp_v0_99->unk_00 = 5;
        temp_v0_99->parentUID = var_s1_3->uid;
        btlPacketRegister(temp_v0_99, 1U);
    }
    sp444 = NULL;
    sp3E0 = 0x1E;
    sp330 = 0;
    sp170 = func_002d4cc0(sp250) & 0xFFFF;
    sp3C0 = 0;
    sp370 = 0;
    sp260 = temp_s7;
loop_306:
    sp230 = (s32) sp370;
    if ((s32) sp370 < (s32) action->target.targetedCount) {
        temp_s2_3 = action->target.targetedActions[sp370];
        sp350 = (u16) ACTION_U8(temp_s2_3, 0xc8);
        sp340 = 0;
        sp160 = func_002b9640(&ACTION_U8(temp_s2_3, 0xc8));
        temp_v1_10 = ACTION_U32(temp_s2_3, 0xd4);
        if (temp_v1_10 != 0) {
            var_s5_2 = action;
        } else {
            var_s5_2 = temp_s2_3;
        }
        temp_v0_100 = ACTION_U32(temp_s2_3, 0xd0);
        if ((temp_v0_100 != 0) && (action->unit->genus != var_s5_2->unit->genus)) {
            sp390 += 1;
        }
        if (ACTION_U32(temp_s2_3, 0xcc + sp350 * 0x1c) & 0x100000) {
            sp380 += 1;
            sp320 |= ACTION_U16(temp_s2_3, 0xce);
        }
        temp_a0_8 = var_s5_2->unit;
        var_a2_3 = temp_a0_8->genus;
        var_a1 = 1;
        sp150 = 1;
        if (var_a2_3 == 1) {
            var_a2_3 = temp_a0_8->charId * 0x4C;
            var_a1 = (*(gp0xffffb714 + var_a2_3) & 1) == 0;
            sp150 = var_a1;
        }
        if ((temp_v0_100 != 0) || (temp_v1_10 != 0)) {
            sp3E0 = 0x2D;
        }
        temp_v0_101 = func_002bd480(temp_a0_8, var_a1, var_a2_3);
        temp_v0_101->actionUID = temp_s0;
        btlPacketRegister(temp_v0_101, 1U);
        if ((ACTION_U16(temp_s2_3, 0xcc) != 0x400) && (ACTION_U32(temp_s2_3, 0xd4) != 1)) {
            var_s1_3 = func_002baf90(sp438, action->unit, var_s5_2->unit, 1);
            if (sp444 == NULL) {
                if (!((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x2000)) {
                    var_s1_3->unk_00 = 4;
                    var_s1_3->parentUID = sp44C->uid;
                    var_s1_3->preUpdateWait.type = 4;
                    var_s1_3->preUpdateWait.value = sp448->uid;
                } else {
                    var_s1_3->unk_00 = 4;
                    var_s1_3->parentUID = (u64) sp180;
                }
                var_s1_3->preUpdateDelay = (s16) sp330;
            } else {
                var_s1_3->unk_00 = 4;
                var_s1_3->parentUID = sp444->uid;
            }
            if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x80) {
                var_s1_3->actionUID = temp_s0;
            }
            btlPacketRegister(var_s1_3, 2U);
            temp_v0_102 = func_002dd5e0(1);
            temp_v0_102->unk_00 = 5;
            temp_v0_102->parentUID = var_s1_3->uid;
            btlPacketRegister(temp_v0_102, 1U);
        } else {
            temp_v0_103 = func_002baf90(sp438, action->unit, var_s5_2->unit, 1);
            var_s1_3 = temp_v0_103;
            temp_v0_103->unk_00 = 4;
            temp_v0_103->parentUID = sp44C->uid;
            temp_v0_103->preUpdateWait.type = 4;
            temp_v0_103->preUpdateWait.value = sp448->uid;
            temp_v0_103->preUpdateDelay = (s16) sp330;
            if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x80) {
                var_s1_3->actionUID = temp_s0;
            }
            btlPacketRegister(var_s1_3, 2U);
            if ((ACTION_U16(temp_s2_3, 0xcc) != 0x400) && (ACTION_U32(temp_s2_3, 0xd4) == 1) && (sp230 == 0)) {
                temp_v0_104 = func_002baf90(sp438, action->unit, var_s5_2->unit, 1);
                sp43C = temp_v0_104;
                temp_v0_104->unk_00 = 5;
                temp_v0_104->parentUID = var_s1_3->uid;
                if ((ACTION_U32(temp_s2_3, 0xd4) != 0) && ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 8)) {
                    sp43C->preUpdateDelay = 8;
                }
                sp43C->actionUID = temp_s0;
                btlPacketRegister(sp43C, 2U);
                temp_v0_105 = func_002dd5e0(1);
                temp_v0_105->unk_00 = 5;
                temp_v0_105->parentUID = sp43C->uid;
                btlPacketRegister(temp_v0_105, 1U);
            }
        }
        if (sp2EC != 0) {
            temp_v0_106 = btlUnitCreateLookAtUnitPacket(NULL, var_s5_2->unit, 3U);
            temp_v0_106->unk_00 = 5;
            temp_v0_106->parentUID = var_s1_3->uid;
            temp_v0_106->actionUID = action->uid;
            btlPacketRegister(temp_v0_106, 1U);
            if (var_s5_2 != action) {
                temp_v0_107 = btlUnitCreateLookAtUnitPacket(var_s5_2->unit, action->unit, 0U);
                temp_v0_107->unk_00 = 5;
                temp_v0_107->parentUID = var_s1_3->uid;
                temp_v0_107->actionUID = action->uid;
                btlPacketRegister(temp_v0_107, 1U);
            } else {
                temp_v0_108 = btlUnitCreateLookAtDeactivatePacket(var_s5_2->unit, 0U);
                temp_v0_108->unk_00 = 5;
                temp_v0_108->parentUID = var_s1_3->uid;
                temp_v0_108->actionUID = action->uid;
                btlPacketRegister(temp_v0_108, 1U);
            }
            action->unk_18 |= 0x200;
        } else if ((sp230 == 0) && (var_s6 == 0)) {
            temp_a0_9 = func_002d1600(&action->target) & 0xFFFF;
            if (temp_a0_9 == 2) {
                func_00280870(temp_a0_9, 1, &sp518, 0, 0, 1);
                temp_v0_109 = btlUnitCreateLookAtPacket(NULL, &sp518, 1U);
                temp_v0_109->unk_00 = 5;
                temp_v0_109->parentUID = var_s1_3->uid;
                temp_v0_109->actionUID = action->uid;
                btlPacketRegister(temp_v0_109, 1U);
            }
        }
        if (sp280 == 1) {
            if ((sp444 == NULL) && (var_s6 != -1)) {
                if ((sp1D0 == 1) && (sp1A0 == 0) && (sp1C0 == 0)) {
                    temp_v0_110 = btlUnit00285d30(sp450, 0U, 0, 0, 0, 0);
                    temp_v0_110->unk_00 = 5;
                    temp_v0_110->parentUID = var_s1_3->uid;
                    temp_v0_110->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_110, 0U);
                }
                if (sp2B0 == 0) {
                    var_v0_6 = btlUnit002843e0(action->unit, sp300);
                } else {
                    var_v0_6 = btlUnit00284f50(action->unit, 0, 1.0f, 0);
                }
                var_v0_6->unk_00 = 5;
                var_v0_6->parentUID = var_s1_3->uid;
                var_v0_6->actionUID = temp_s0;
                btlPacketRegister(var_v0_6, 1U);
                temp_v0_111 = btlUnit00285d30(action->unit, -1U, 0, 0, 0, 0);
                temp_v0_111->unk_00 = 5;
                temp_v0_111->parentUID = var_s1_3->uid;
                temp_v0_111->actionUID = temp_s0;
                btlPacketRegister(temp_v0_111, 1U);
            }
            if (var_s5_2 != action) {
                temp_v0_112 = btlUnitCreateRotateTowardUnitPacket(var_s5_2->unit, action->unit, 2U);
                temp_v0_112->unk_00 = 5;
                temp_v0_112->parentUID = var_s1_3->uid;
                temp_v0_112->actionUID = temp_s0;
                btlPacketRegister(temp_v0_112, 0U);
            }
            temp_v0_113 = btlCameraCreateSetStatePacket(var_s5_2, 0x18U);
            sp444 = temp_v0_113;
            temp_v0_113->unk_00 = 5;
            temp_v0_113->parentUID = var_s1_3->uid;
            temp_v0_113->postUpdateWaits[0].type = 0xB;
            temp_v0_113->postUpdateWaits[0].value = var_s1_3->uid;
            temp_v0_113->postUpdateDelay = 0x12;
            temp_v0_113->actionUID = temp_s0;
            btlPacketRegister(temp_v0_113, 0U);
        }
        if (ACTION_U32(temp_s2_3, 0xd4) != 0) {
            var_v0_7 = func_002fd160(temp_s2_3);
            if (var_v0_7 == 0) {
                var_v0_7 = (*(u32*)((u8*)gBtl + 0xC8C));
            }
            sp440 = func_002baf90(var_v0_7, action->unit, temp_s2_3->unit, 1);
            if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 4) {
                sp440->unk_00 = 0xB;
                sp440->parentUID = var_s1_3->uid;
            } else {
                sp440->unk_00 = 5;
                sp440->parentUID = (u64) sp180;
            }
            btlPacketRegister(sp440, 1U);
            temp_v0_114 = func_002dd100(0xD, 2, 6U);
            temp_v0_114->unk_00 = 5;
            temp_v0_114->parentUID = sp440->uid;
            btlPacketRegister(temp_v0_114, 1U);
        }
        var_v1_3 = ACTION_U16(temp_s2_3, 0xcc);
        if (var_v1_3 == 0x400) {
            sp440 = func_002baf90((*(u32*)((u8*)gBtl + 0xC90)), action->unit, var_s5_2->unit, 1);
            if ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 4) {
                sp440->unk_00 = 0xB;
                sp440->parentUID = var_s1_3->uid;
            } else {
                sp440->unk_00 = 5;
                sp440->parentUID = (u64) sp180;
            }
            btlPacketRegister(sp440, 1U);
            temp_v0_115 = func_002dd100(0xC, 2, 7U);
            temp_v0_115->unk_00 = 5;
            temp_v0_115->parentUID = sp440->uid;
            var_v1_3 = (u16) (u32) btlPacketRegister(temp_v0_115, 1U);
            sp3D0 = 0xA;
        }
        sp360 = 0;
        sp140 = (u64) sp350;
        sp130 = sp350 - 1;
        sp120 = sp3D0 + 0x2B;
loop_302:
        spB0 = (u64) sp360;
        if ((s32) var_v1_3 < sp140) {
            temp_v0_116 = (u8*)temp_s2_3 + sp360 * 0x1C;
            sp110 = (u64) temp_v0_116;
            sp100 = (u64) ((u8*)temp_v0_116 + 0xF8);
            temp_v0_117 = btlUnitCreateAnimPacket(var_s5_2->unit, (u16) ACTION_U8(temp_s2_3, 0xf8 + sp360 * 0x1c), 0U, 1.0f, 0U);
            var_s3 = temp_v0_117;
            temp_v0_117->unk_00 = 0xB;
            temp_v0_117->parentUID = var_s1_3->uid;
            temp_v0_117->preUpdateDelay = (s16) sp340;
            if ((ACTION_U32(temp_s2_3, 0xd4) != 0) && ((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 8)) {
                var_s3->preUpdateDelay += 8;
            }
            var_s3->actionUID = temp_s0;
            btlPacketRegister(var_s3, 1U);
            if ((spB0 == sp130) && (ACTION_U32(temp_s2_3, 0xe8 + sp360 * 0x1c) & 0x100000)) {
                if (sp150 != 0) {
                    if (sp2EC != 0) {
                        if (sp410 != 0) {
                            temp_f20 = 100.0f * func_002b9590(var_s5_2->unit);
                            if (func_002d6370(temp_s7) != 0) {
                                var_v0_8 = 3;
                            } else {
                                var_v0_8 = 2;
                            }
                            temp_v0_118 = func_002b7bd0(action->unit, var_s5_2->unit, var_v0_8 & 0xFFFF, temp_f20);
                            temp_v0_118->unk_00 = 5;
                            temp_v0_118->parentUID = sp410;
                            temp_v0_118->actionUID = temp_s0;
                            btlPacketRegister(temp_v0_118, 0U);
                        }
                        temp_a1_2 = var_s5_2->unit;
                        temp_v0_119 = func_002baf90((*(u32*)((u8*)gBtl + 0xD00)), temp_a1_2, temp_a1_2, 1);
                        temp_v0_119->unk_00 = 5;
                        temp_v0_119->parentUID = var_s3->uid;
                        temp_v0_119->preUpdateDelay = 1;
                        temp_v0_119->actionUID = temp_s0;
                        btlPacketRegister(temp_v0_119, 2U);
                    } else {
                        temp_a1_3 = var_s5_2->unit;
                        temp_v0_120 = func_002baf90((*(u32*)((u8*)gBtl + 0xCFC)), temp_a1_3, temp_a1_3, 1);
                        temp_v0_120->unk_00 = 5;
                        temp_v0_120->parentUID = var_s3->uid;
                        temp_v0_120->preUpdateDelay = 1;
                        temp_v0_120->actionUID = temp_s0;
                        btlPacketRegister(temp_v0_120, 2U);
                    }
                    if (ACTION_U32(temp_s2_3, 0xd0) == 0) {
                        temp_a1_4 = var_s5_2->unit;
                        temp_v0_121 = func_002baf90((*(u32*)((u8*)gBtl + 0xCF8)), temp_a1_4, temp_a1_4, 1);
                        temp_v0_121->unk_00 = 5;
                        temp_v0_121->parentUID = var_s3->uid;
                        temp_v0_121->preUpdateDelay = 0x10;
                        temp_v0_121->actionUID = temp_s0;
                        btlPacketRegister(temp_v0_121, 2U);
                    }
                }
                temp_v0_122 = btlUnit00284c90(var_s5_2->unit);
                temp_v0_122->unk_00 = 5;
                temp_v0_122->parentUID = var_s3->uid;
                temp_v0_122->actionUID = temp_s0;
                btlPacketRegister(temp_v0_122, 1U);
            }
            if ((sp280 == 0) && ((ACTION_U8(temp_s2_3, 0xf8 + sp360 * 0x1c) != -1) || (temp_s2_3->unit->genus != action->unit->genus)) && (datCalcChkBadStatus(temp_s2_3->unit->datUnit, 0x180000U) == 0)) {
                temp_v0_123 = btlUnitCreateRotateTowardUnitPacket(temp_s2_3->unit, action->unit, 2U);
                if ((ACTION_U32(temp_s2_3, 0xd4) != 0) && (sp440 != NULL)) {
                    temp_v0_123->unk_00 = 5;
                    temp_v0_123->parentUID = sp440->uid;
                } else {
                    temp_v0_123->unk_00 = 5;
                    temp_v0_123->parentUID = var_s3->uid;
                }
                temp_v0_123->unk_47 &= 0xDF;
                temp_v0_123->actionUID = temp_s0;
                btlPacketRegister(temp_v0_123, 1U);
            }
            temp_v0_124 = (void*)((u8*)temp_s2_3 + sp360 * 0x1C + 0xE0);
            sp220 = temp_v0_124;
            temp_v0_125 = func_002d7e20(action, var_s5_2, temp_v0_124, ACTION_U16(temp_s2_3, 0xcc));
            temp_v0_125->unk_00 = 5;
            temp_v0_125->parentUID = var_s3->uid;
            temp_v0_125->preUpdateDelay = sp3D0;
            temp_v0_125->actionUID = temp_s0;
            btlPacketRegister(temp_v0_125, 1U);
            temp_v0_126 = func_002d8090(temp_s2_3);
            temp_v0_126->unk_00 = 5;
            temp_v0_126->parentUID = var_s3->uid;
            temp_v0_126->preUpdateDelay = sp3D0;
            temp_v0_126->actionUID = temp_s0;
            btlPacketRegister(temp_v0_126, 1U);
            if ((sp230 == (action->target.targetedCount - 1)) && (spB0 == (ACTION_U8(temp_s2_3, 0xc8) - 1))) {
                temp_v0_127 = func_002d8090(action);
                temp_v0_127->unk_00 = 5;
                temp_v0_127->parentUID = var_s3->uid;
                temp_v0_127->preUpdateDelay = sp3D0;
                temp_v0_127->actionUID = temp_s0;
                btlPacketRegister(temp_v0_127, 1U);
            }
            if ((sp230 == 0) && (spB0 == 0) && !(action->unk_18 & 4)) {
                temp_v0_128 = func_002d7fb0(action, ACTION_U8(action, 0xca));
                temp_v0_128->unk_00 = 5;
                temp_v0_128->parentUID = var_s3->uid;
                temp_v0_128->preUpdateDelay = sp3D0;
                temp_v0_128->actionUID = temp_s0;
                btlPacketRegister(temp_v0_128, 1U);
            }
            if (spB0 == (ACTION_U8(temp_s2_3, 0xc8) - 1)) {
                temp_a1_5 = ACTION_S16(action, 0xDC);
                if (temp_a1_5 != 0) {
                    temp_v0_129 = func_002bd850(action->unit, temp_a1_5);
                    temp_v0_129->unk_00 = 5;
                    temp_v0_129->parentUID = var_s3->uid;
                    temp_v0_129->unk_47 &= 0xDF;
                    temp_v0_129->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_129, 3U);
                } else {
                    temp_a1_6 = ACTION_U32(temp_s2_3, 0xdc);
                    if (temp_a1_6 != 0) {
                        temp_v0_130 = func_002bd850(temp_s2_3->unit, temp_a1_6);
                        temp_v0_130->unk_00 = 5;
                        temp_v0_130->parentUID = var_s3->uid;
                        temp_v0_130->unk_47 &= 0xDF;
                        temp_v0_130->actionUID = temp_s0;
                        btlPacketRegister(temp_v0_130, 3U);
                    }
                }
            }
            if ((spB0 == 0) && ((*(s32*)((u8*)temp_s2_3 + 0xe0 + sp360 * 0x1c)) != 0)) {
                temp_v0_131 = func_002bd230(var_s5_2->unit, 0, 0);
                temp_v0_131->unk_00 = 5;
                temp_v0_131->parentUID = var_s3->uid;
                temp_v0_131->preUpdateDelay = sp3D0;
                temp_v0_131->unk_47 &= 0xDF;
                temp_v0_131->actionUID = temp_s0;
                btlPacketRegister(temp_v0_131, 3U);
            }
            spF0 = sp110 + 0xFA;
            if (ACTION_U16(temp_s2_3, 0xfa + sp360 * 0x1c) & 1) {
                func_002d5dc0(&sp4F0);
                sp4FC = 0x100000;
                temp_v0_132 = func_002d7e20(temp_s2_3, temp_s2_3, &sp4F0, 1U, 1U);
                temp_v0_132->unk_00 = 4;
                temp_v0_132->parentUID = var_s3->uid;
                temp_v0_132->actionUID = temp_s0;
                btlPacketRegister(temp_v0_132, 1U);
                if (ACTION_U16(temp_s2_3, 0xfa + sp360 * 0x1c) & 2) {
                    temp_v0_133 = btlUnitCreateAnimPacket(temp_s2_3->unit, 0xAU, 0U, 1.0f, 0U);
                    temp_v0_133->unk_00 = 4;
                    temp_v0_133->parentUID = var_s3->uid;
                    temp_v0_133->actionUID = temp_s0;
                    btlPacketRegister(temp_v0_133, 1U);
                }
                temp_v0_134 = btlUnit00284c90(temp_s2_3->unit);
                temp_v0_134->unk_00 = 4;
                temp_v0_134->parentUID = var_s3->uid;
                temp_v0_134->actionUID = temp_s0;
                btlPacketRegister(temp_v0_134, 1U);
            }
            if (ACTION_U16(temp_s2_3, 0xfa + sp360 * 0x1c) & 0x20) {
                sp2C0 = 1;
                (*(u16*)((u8*)gBtl + 0x1C)) = 3;
            }
            if (ACTION_U16(temp_s2_3, 0xfa + sp360 * 0x1c) & 0x40) {
                sp290 = 1;
            }
            temp_v0_135 = (u8*)temp_s2_3 + sp360 * 0x1C;
            spE0 = (u64) temp_v0_135;
            temp_v0_136 = func_002bdbd0(action->unit, var_s5_2->unit, sp260, ACTION_U16(temp_s2_3, 0xcc), ACTION_U16(temp_s2_3, 0xce), sp360, sp350, (u8*)temp_s2_3 + 0xe0 + sp360 * 0x1c);
            temp_v0_136->unk_00 = 5;
            temp_v0_136->parentUID = var_s3->uid;
            temp_v0_136->preUpdateDelay = sp3D0;
            temp_v0_136->unk_47 &= 0xDF;
            temp_v0_136->actionUID = temp_s0;
            var_v1_3 = (u16) (u32) btlPacketRegister(temp_v0_136, 3U);
            spD0 = (u64) ((u8*)temp_v0_135 + 0xF4);
            if ((ACTION_S16(temp_s2_3, 0xf4 + sp360 * 0x1c) > 0) || (ACTION_S16(temp_s2_3, 0xf6 + sp360 * 0x1c) > 0)) {
                spC0 = (u64) ((s64) ((s64) sp120 << 0x30) >> 0x30);
                func_002d5dc0(&sp4F0);
                sp4F0 = (s32) ACTION_S16(temp_s2_3, 0xf4 + sp360 * 0x1c);
                sp4F4 = (s32) ACTION_S16(temp_s2_3, 0xf6 + sp360 * 0x1c);
                temp_v0_137 = func_002d7e20(action, action, &sp4F0, 1U, 1U);
                temp_v0_137->unk_00 = 4;
                temp_v0_137->parentUID = var_s3->uid;
                temp_v0_137->preUpdateDelay = (s16) spC0;
                temp_v0_137->actionUID = temp_s0;
                btlPacketRegister(temp_v0_137, 1U);
                temp_a0_10 = action->unit;
                temp_v0_138 = func_002bdbd0(temp_a0_10, temp_a0_10, -1, 1U, 1U, sp360, sp350, &sp4F0);
                temp_v0_138->unk_00 = 4;
                temp_v0_138->parentUID = var_s3->uid;
                temp_v0_138->preUpdateDelay = (s16) spC0;
                temp_v0_138->actionUID = temp_s0;
                var_v1_3 = (u16) (u32) btlPacketRegister(temp_v0_138, 3U);
                if (sp4F0 != 0) {
                    if (spB0 == 0) {
                        temp_v0_139 = func_002bd480(action->unit);
                        temp_v0_139->actionUID = temp_s0;
                        btlPacketRegister(temp_v0_139, 1U);
                    }
                    temp_v0_140 = func_002bd230(action->unit, 0, 0);
                    temp_v0_140->unk_00 = 4;
                    temp_v0_140->parentUID = var_s3->uid;
                    temp_v0_140->preUpdateDelay = (s16) spC0;
                    temp_v0_140->actionUID = temp_s0;
                    var_v1_3 = (u16) (u32) btlPacketRegister(temp_v0_140, 3U);
                }
            }
            sp340 += 7;
            sp360 += 1;
            goto loop_302;
        }
        if (sp3C0 < (s32) sp340) {
            sp3C0 = sp340;
        }
        sp330 += sp170;
        sp370 += 1;
        goto loop_306;
    }
    temp_s2_4 = var_s3->uid;
    temp_v1_11 = ACTION_S16(action, 0xDE);
    if (temp_v1_11 != -1) {
        temp_v0_141 = func_002db740(action, temp_v1_11 & 0xFFFF, 0, 0);
        temp_v0_141->unk_00 = 5;
        temp_v0_141->parentUID = temp_s2_4;
        temp_v0_141->preUpdateDelay = (s16) sp3C0;
        temp_v0_141->actionUID = temp_s0;
        btlPacketRegister(temp_v0_141, 1U);
    } else if (sp390 > 0) {
        if (var_s6 == 0) {
            temp_s3_3 = func_002d4e10(2, 0x80000) & 0xFFFF;
            if (((s32) action->unk_28 <= 0) && (action->unit->charId != 1) && (datCalcRand(0x64U) < 0x32U)) {
                if (action->unit->genus != 0) {
                    var_v0_9 = 0;
                } else {
                    temp_a0_11 = (u8*)gBtl;
                    if ((*(s16*)((u8*)gBtl + 0xA38)) != -1) {
                        temp_v1_12 = (s64) ((temp_s3_3 - sp390) << 0x30) >> 0x30;
                        if (temp_v1_12 <= 0) {
                            temp_a0_12 = func_002d4e10(2, 0x80000) & 0xFFFF;
                            temp_v1_13 = (u8*)gBtl;
                            if (((u32) ((s16) (*(s16*)((u8*)gBtl + 0xA3A)) >> 1) >= temp_a0_12) && (temp_s3_4 = (*(s16*)((u8*)gBtl + 0xA38)), (temp_s3_4 != ((s64) (func_002b7060(temp_a0_12) << 0x30) >> 0x30)))) {
                                var_v0_9 = 1;
                            } else {
                                goto block_323;
                            }
                        } else if (((s16) (*(s16*)((u8*)gBtl + 0xA3A)) >> 1) >= temp_v1_12) {
                            var_v0_9 = 1;
                        } else {
                            goto block_323;
                        }
                    } else {
block_323:
                        var_v0_9 = 0;
                    }
                }
                if (var_v0_9 != 0) {
                    goto block_325;
                }
                temp_v0_142 = btlVoice002e2be0(action, 0xD, sp390, 0, 0);
                temp_v0_142->unk_00 = 5;
                temp_v0_142->parentUID = temp_s2_4;
                temp_v0_142->preUpdateDelay = (s16) sp3C0;
                btlPacketRegister(temp_v0_142, 1U);
            } else {
block_325:
                temp_v0_143 = func_002db740(action, 0x16, sp390, 0);
                temp_v0_143->unk_00 = 5;
                temp_v0_143->parentUID = temp_s2_4;
                temp_v0_143->preUpdateDelay = (s16) sp3C0;
                temp_v0_143->actionUID = temp_s0;
                btlPacketRegister(temp_v0_143, 1U);
            }
        }
    } else if ((sp380 > 0) && (temp_v1_14 = ACTION_U8(action, 0xca), ((temp_v1_14 & 1) != 0)) && !(temp_v1_14 & 2)) {
        temp_v0_144 = func_002db740(action, 0x17, (s32) sp320, 0);
        temp_v0_144->unk_00 = 5;
        temp_v0_144->parentUID = temp_s2_4;
        temp_v0_144->preUpdateDelay = (s16) sp3C0;
        temp_v0_144->actionUID = temp_s0;
        btlPacketRegister(temp_v0_144, 1U);
    } else if ((sp2EC != 0) && (action->unit->charId == 1) && (var_s6 == 0) && (func_002d5fb0(action) != 0) && (func_002d6090(action) == 0)) {
        temp_v0_145 = btlVoice002e2be0(action->target.targetedActions[0], 0x11, 0, 0, 0);
        temp_v0_145->unk_00 = 5;
        temp_v0_145->parentUID = temp_s2_4;
        temp_v0_145->preUpdateDelay = (s16) sp3C0;
        btlPacketRegister(temp_v0_145, 1U);
    } else if (sp390 == 0) {
        if (func_002d6130(action) != 0) {
            temp_v0_146 = btlVoice002e2be0(action, 0xE, 0, 0, 0);
            temp_v0_146->unk_00 = 5;
            temp_v0_146->parentUID = temp_s2_4;
            temp_v0_146->preUpdateDelay = (s16) sp3C0;
            btlPacketRegister(temp_v0_146, 1U);
        } else if ((func_002d6210(action) == 1) && (func_002d5f50(action) == 0) && (sp290 == 0)) {
            temp_v0_147 = btlVoice002e2be0(action, 0xF, (s16)func_003082f0(action->unit->datUnit, sp250), 0, 0);
            temp_v0_147->unk_00 = 5;
            temp_v0_147->parentUID = temp_s2_4;
            temp_v0_147->preUpdateDelay = (s16) sp3C0;
            btlPacketRegister(temp_v0_147, 1U);
        }
    }
    if (sp290 != 0) {
        if (sp280 == 1) {
            temp_v0_148 = btlCameraCreateSetStatePacket(action, 0x17U);
            sp444 = temp_v0_148;
            temp_v0_148->unk_00 = 0xB;
            temp_v0_148->parentUID = var_s1_3->uid;
            temp_v0_148->preUpdateDelay = 0x18;
            temp_v0_148->actionUID = temp_s0;
            btlPacketRegister(temp_v0_148, 0U);
        }
        if (action->unit->genus == 0) {
            func_002d5dc0(&sp4F0);
            sp4F0 = -((datCalcGetHp(action->unit->datUnit) & 0xFFFF) - 1);
            var_s2_4 = func_002d7e20(action, action, &sp4F0, 1U, 1U);
            if (sp280 == 1) {
                var_s2_4->unk_00 = 4;
                var_s2_4->parentUID = sp444->uid;
            } else {
                var_s2_4->unk_00 = 0xB;
                var_s2_4->parentUID = var_s1_3->uid;
            }
            var_s2_4->actionUID = temp_s0;
            btlPacketRegister(var_s2_4, 1U);
            temp_a0_13 = action->unit;
            temp_v0_149 = func_002bdbd0(temp_a0_13, temp_a0_13, -1, 0U);
            temp_v0_149->unk_00 = 4;
            temp_v0_149->parentUID = var_s2_4->uid;
            temp_v0_149->unk_47 &= 0xDF;
            temp_v0_149->actionUID = temp_s0;
            btlPacketRegister(temp_v0_149, 3U);
            temp_v0_150 = func_002bd230(action->unit, 0, 0);
            temp_v0_150->unk_00 = 4;
            temp_v0_150->parentUID = var_s2_4->uid;
            temp_v0_150->unk_47 &= 0xDF;
            temp_v0_150->actionUID = temp_s0;
            btlPacketRegister(temp_v0_150, 3U);
        } else {
            func_002d5dc0(&sp4F0);
            sp4F8 = 0x80000;
            var_s2_4 = func_002d7e20(action, action, &sp4F0, 1U, 1U);
            if (sp280 == 1) {
                var_s2_4->unk_00 = 4;
                var_s2_4->parentUID = sp444->uid;
            } else {
                var_s2_4->unk_00 = 0xB;
                var_s2_4->parentUID = var_s1_3->uid;
            }
            var_s2_4->actionUID = temp_s0;
            btlPacketRegister(var_s2_4, 1U);
        }
        if (sp2AC == 0) {
            if (sp2B0 == 0) {
                var_s3_3 = btlUnit002843e0(action->unit, sp300);
            } else {
                var_s3_3 = btlUnit00284f50(action->unit, 0, 1.0f, 0);
            }
            var_s3_3->unk_00 = 4;
            var_s3_3->parentUID = var_s2_4->uid;
            var_s3_3->actionUID = temp_s0;
            btlPacketRegister(var_s3_3, 1U);
        } else {
            temp_v0_151 = btlUnit00284c90(action->unit);
            var_s3_3 = temp_v0_151;
            temp_v0_151->unk_00 = 4;
            temp_v0_151->parentUID = var_s2_4->uid;
            temp_v0_151->actionUID = temp_s0;
            btlPacketRegister(var_s3_3, 1U);
        }
        temp_a0_14 = action->unit;
        if (temp_a0_14->flags3 & 0x20) {
            temp_v0_152 = func_0027f2f0();
            temp_v0_152->unk_00 = 4;
            temp_v0_152->parentUID = var_s2_4->uid;
            temp_v0_152->postUpdateDelay = 0x3C;
            temp_v0_152->actionUID = temp_s0;
            btlPacketRegister(temp_v0_152, 1U);
        } else {
            temp_v0_153 = btlUnit00285d30(temp_a0_14, 0xFFFFFFU, 6, 0, 0, 0);
            temp_v0_153->unk_00 = 4;
            temp_v0_153->parentUID = var_s2_4->uid;
            temp_v0_153->actionUID = temp_s0;
            btlPacketRegister(temp_v0_153, 1U);
            temp_a1_7 = action->unit;
            temp_v0_154 = func_002baf90((*(u32*)((u8*)gBtl + 0xCB0)), temp_a1_7, temp_a1_7, 0);
            temp_v0_154->unk_00 = 4;
            temp_v0_154->parentUID = var_s2_4->uid;
            temp_v0_154->actionUID = temp_s0;
            btlPacketRegister(temp_v0_154, 2U);
            temp_v0_155 = func_002dd100(0xA, 2, 8U);
            temp_v0_155->unk_00 = 4;
            temp_v0_155->parentUID = var_s2_4->uid;
            temp_v0_155->actionUID = temp_s0;
            btlPacketRegister(temp_v0_155, 1U);
            temp_v1_15 = action->unit;
            temp_v1_15->flags3 |= 0x100;
        }
    } else if (sp2AC == 0) {
        if (sp2B0 == 0) {
            var_s3_3 = btlUnit002843e0(action->unit, sp300);
        } else {
            var_s3_3 = btlUnit00284f50(action->unit, 0, 1.0f, 0);
        }
        var_s3_3->unk_00 = 0xB;
        var_s3_3->parentUID = var_s1_3->uid;
        if (var_s6 == 0) {
            var_s3_3->preUpdateDelay = sp3E0;
        } else {
            var_s3_3->preUpdateDelay = 8;
            var_s3_3->postUpdateDelay = sp3E0;
        }
        var_s3_3->actionUID = temp_s0;
        btlPacketRegister(var_s3_3, 1U);
    } else {
        temp_v0_156 = btlUnit00284c90(action->unit);
        var_s3_3 = temp_v0_156;
        temp_v0_156->unk_00 = 0xB;
        temp_v0_156->parentUID = var_s1_3->uid;
        temp_v0_156->preUpdateDelay = sp3E0;
        temp_v0_156->actionUID = temp_s0;
        btlPacketRegister(var_s3_3, 1U);
    }
    temp_v0_157 = func_0029fa50(0x10);
    temp_v0_157->unk_00 = 4;
    temp_v0_157->parentUID = var_s3_3->uid;
    temp_v0_157->unk_47 &= 0xDF;
    temp_v0_157->actionUID = temp_s0;
    btlPacketRegister(temp_v0_157, 1U);
    if (sp2C0 != 0) {
        var_v0_10 = 2;
    } else {
        var_v0_10 = 0;
    }
    temp_v0_158 = func_002a1080(0x10, var_v0_10 & 0xFFFF);
    temp_v0_158->unk_00 = 4;
    temp_v0_158->parentUID = var_s3_3->uid;
    temp_v0_158->unk_47 &= 0xDF;
    temp_v0_158->actionUID = temp_s0;
    btlPacketRegister(temp_v0_158, 1U);
    temp_v0_159 = func_002a16c0(0x10);
    temp_v0_159->unk_00 = 4;
    temp_v0_159->parentUID = var_s3_3->uid;
    temp_v0_159->unk_47 &= 0xDF;
    temp_v0_159->actionUID = temp_s0;
    btlPacketRegister(temp_v0_159, 1U);
    temp_v0_160 = func_002a1db0(8);
    temp_v0_160->unk_00 = 4;
    temp_v0_160->parentUID = var_s1_3->uid;
    temp_v0_160->unk_47 &= 0xDF;
    temp_v0_160->actionUID = temp_s0;
    btlPacketRegister(temp_v0_160, 0U);
    if ((sp1D0 == 1) && (var_s6 != -1) && (sp1C0 == 0)) {
        if (sp2D0 == 0) {
            if (!((*(u16*)((u8*)iGpffffb710 + temp_fp + 2)) & 0x40)) {
                if (var_s6 == 0) {
                    var_v0_11 = 0x15;
                } else {
                    var_v0_11 = 0x16;
                }
                temp_v0_161 = btlCameraCreateSetStatePacket(action, var_v0_11 & 0xFFFF);
                temp_v0_161->unk_00 = 5;
                temp_v0_161->parentUID = sp410;
                temp_v0_161->actionUID = temp_s0;
                btlPacketRegister(temp_v0_161, 0U);
            }
        } else {
            temp_v0_162 = btlCameraCreateSetStatePacket(action, 0x19U);
            temp_v0_162->unk_00 = 5;
            temp_v0_162->parentUID = sp410;
            temp_v0_162->actionUID = temp_s0;
            btlPacketRegister(temp_v0_162, 0U);
        }
        if (sp2C0 == 0) {
            temp_v0_163 = btlUnit00285d30(action->unit, -1U, 0, 0xC, 0, 0);
            temp_v0_163->unk_00 = 0xB;
            temp_v0_163->parentUID = var_s1_3->uid;
            temp_v0_163->actionUID = temp_s0;
            btlPacketRegister(temp_v0_163, 1U);
        }
        if (sp1A0 == 0) {
            temp_v0_164 = btlUnit00285d30(sp450, 0xFFFFFFU, 8, 0, 0, 0);
            temp_v0_164->unk_00 = 0xB;
            temp_v0_164->parentUID = var_s1_3->uid;
            if (sp2EC != 0) {
                if (sp1B0 == 0) {
                    goto block_394;
                }
                var_v0_12 = 7;
            } else {
block_394:
                var_v0_12 = 0xF;
            }
            temp_v0_164->preUpdateDelay = var_v0_12;
            temp_v0_164->actionUID = temp_s0;
            btlPacketRegister(temp_v0_164, 1U);
            temp_v0_165 = func_002bb2f0((*(u32*)((u8*)gBtl + 0xCEC)), sp450, (u32) sp3B0, 0U, 0);
            temp_v0_165->unk_00 = 4;
            temp_v0_165->parentUID = sp420;
            temp_v0_165->actionUID = temp_s0;
            btlPacketRegister(temp_v0_165, 2U);
            temp_v0_166 = btlUnit002857f0(sp450);
            temp_v0_166->unk_00 = 4;
            temp_v0_166->parentUID = temp_v0_164->uid;
            temp_v0_166->preUpdateDelay = 1;
            temp_v0_166->actionUID = temp_s0;
            btlPacketRegister(temp_v0_166, 1U);
        }
    }
    if (sp2C0 == 1) {
        temp_v0_167 = btlCreateSetFlagsPacket(0x80U);
        temp_v0_167->unk_00 = 4;
        temp_v0_167->parentUID = var_s1_3->uid;
        temp_v0_167->preUpdateDelay = 0xC;
        temp_v0_167->actionUID = temp_s0;
        btlPacketRegister(temp_v0_167, 1U);
    }
    func_002b9030(sp438);
    if (func_002dc130(action) != 0) {
        btlActionSetState(action, BTLACTION_STATE_BADDMG);
    } else {
        btlActionSetState(action, BTLACTION_STATE_PACKET);
    }
}
/* Warning: struct Model is not defined (only forward-declared) */

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
    u16 state;

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
        packet = FUN_002864a0(action->unit, action->unit->charId, 0x10);
        packet->unk_00 = 4;
        packet->parentUID = root->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    btlUnitAnimate(action->unit, -1, 0xc, 1.0f, 3);
    FUN_002b77c0(action->unit);
    btlUnit0027f7c0(action->unit, &pos, NULL, &direction);
    packet = FUN_002864a0(action->unit, action->unit->charId, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    FUN_00287b20(action->unit, 1);
    FUN_002d3e00(action->unit, &destination);
    FUN_00287490(action->unit);
    packet = FUN_00285d30(action->unit, -1, 0xc, 0, 3, 1);
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    ACTION_U16(packet, 0x48) = 1;
    ACTION_U16(packet, 0x4a) = 0x2d;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    destination.x = pos.x - direction.x;
    destination.y = pos.y - direction.y;
    destination.z = pos.z - direction.z;
    FUN_004c69f0(&destination, &destination);
    destination.x = pos.x + destination.x * 300.0f;
    destination.y = pos.y + destination.y * 300.0f;
    destination.z = pos.z + destination.z * 300.0f;
    btlUnitSetPos(action->unit, &destination);
    packet = FUN_002819d0_btlAction(action->unit, &destination, 0.5f, 0);
    packet->unk_00 = 4;
    packet->parentUID = root->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    switch (action->target.commandId)
    {
        case 1:
        case 2:
        case 3:
            state = BTLACTION_STATE_PACKET;
            break;
        default:
            state = BTLACTION_STATE_PACKET;
            break;
    }
    btlActionSetState(action, state);
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
    BtlPacket* castAnim;
    BtlPacket* camPacket;
    BtlPacket* castChain;
    BtlPacket* savedSE;
    BtlPacket* packet2;
    BtlPacket* tailPacket;
    BtlPacket* resourcePacket;
    BtlPacket* modelPacket;
    BtlPacket* waitPacket;
    u32 formation;
    u64 actionUID;
    void* handle;
    s16 specificId;
    s16 castDelay;
    u32 outA;
    u32 outB;
    char stackBufE0[0x88];
    u32 didFormationSetup;
    u64 chainUID;
    u16 i;
    u16 childId;
    u16 state;
    BtlAction* child;
    BtlUnit* childUnit;

    specificId = action->target.specificId;
    actionUID = action->uid;
    btlAction0028a780(action);
    formation = FUN_002b8f90(1);

    packet = FUN_002bd590(action->unit, specificId);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);

    packet = FUN_002d8330(action);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002d7fb0(action, 0);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    castAnim = btlUnitCreateAnimPacket(action->unit, 7, 6, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
    castAnim->actionUID = actionUID;
    btlPacketRegister(castAnim, BTLPACKET_TYPE_1);

    camPacket = btlCameraCreateSetStatePacket(action, 0x11);
    camPacket->unk_00 = 4;
    camPacket->parentUID = castAnim->uid;
    camPacket->actionUID = actionUID;
    btlPacketRegister(camPacket, BTLPACKET_TYPE_0);

    castDelay = func_002835e0(action->unit, 7, 1.0f);

    func_0029ea60(specificId, &outB, &outA);
    packet = func_0029f4b0(outB, outA, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    handle = func_0029ec00(specificId);
    func_0029ec80(specificId, &outB, &outA);
    packet = func_002a0050(handle, outB, outA, 0x10, 0);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    handle = func_0029ec50(specificId);
    packet = func_002a1280(handle, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = func_002a1b00(action, specificId, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    func_002bb6f0(specificId, stackBufE0);
    castChain = FUN_002bac00(formation, stackBufE0, 0);
    castChain->unk_00 = 4;
    castChain->parentUID = 0;
    castChain->preUpdateDelay = castDelay + 6;
    castChain->actionUID = actionUID;
    btlPacketRegister(castChain, BTLPACKET_TYPE_1);

    savedSE = btlSoundCreateSkillSEPacket(specificId, 0);
    savedSE->unk_00 = 4;
    savedSE->parentUID = castChain->uid;
    savedSE->actionUID = actionUID;
    btlPacketRegister(savedSE, BTLPACKET_TYPE_1);

    packet2 = FUN_002baf90(formation, action->unit, action->unit, 0, 0);
    packet2->unk_00 = 4;
    packet2->parentUID = castChain->uid;
    packet2->preUpdateWait.type = 4;
    packet2->preUpdateWait.value = savedSE->uid;
    btlPacketRegister(packet2, BTLPACKET_TYPE_3D);

    waitPacket = FUN_002dd5e0(0);
    waitPacket->unk_00 = 5;
    waitPacket->parentUID = packet2->uid;
    btlPacketRegister(waitPacket, BTLPACKET_TYPE_1);

    chainUID = castChain->uid;

    tailPacket = func_0027f2f0();
    tailPacket->unk_00 = 4;
    tailPacket->parentUID = chainUID;
    tailPacket->preUpdateDelay = 0x18;
    tailPacket->actionUID = actionUID;
    btlPacketRegister(tailPacket, BTLPACKET_TYPE_1);

    packet = func_002bb2f0(ACTION_U32(gBtl, 0xca8), action->unit, 0, tailPacket->uid, 0x100);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002dd100(0xa, 2, 5);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    didFormationSetup = 0;
    for (i = 0; i < 3; i++)
    {
        childId = action->target.unk_3e[i];
        if (childId == 0)
        {
            continue;
        }
        child = (BtlAction*)FUN_00289650(1, childId, 0);
        childUnit = child->unit;
        childUnit->datUnit = (DatUnit*)FUN_002ff540(ACTION_U32(gBtl, 0xbbc), childId);
        FUN_002889c0(childUnit, childId);
        if (!didFormationSetup)
        {
            packet = btlFormation002b8f40(0);
            packet->unk_00 = 4;
            packet->parentUID = savedSE->uid;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);

            if ((iGpffffb710[(s16)action->target.specificId].flags & 0x40) == 0)
            {
                packet = FUN_002bc7e0(8);
                packet->unk_00 = 4;
                packet->parentUID = savedSE->uid;
                packet->actionUID = actionUID;
                btlPacketRegister(packet, BTLPACKET_TYPE_0);

                camPacket = btlCameraCreateSetStatePacket(action, 0x26);
                camPacket->unk_00 = 4;
                camPacket->parentUID = savedSE->uid;
                camPacket->actionUID = actionUID;
                btlPacketRegister(camPacket, BTLPACKET_TYPE_0);
            }
            didFormationSetup = 1;
        }
        modelPacket = btlUnitCreateModelPacket(childUnit, childId, 0x7e);
        modelPacket->unk_00 = 4;
        modelPacket->parentUID = chainUID;
        modelPacket->actionUID = actionUID;
        btlPacketRegister(modelPacket, BTLPACKET_TYPE_1);

        resourcePacket = FUN_002864a0(childUnit, childId, 0x10);
        resourcePacket->unk_00 = 4;
        resourcePacket->parentUID = modelPacket->uid;
        btlPacketRegister(resourcePacket, BTLPACKET_TYPE_1);

        waitPacket = FUN_002baf90(formation, action->unit, childUnit, 1, 0x100);
        waitPacket->unk_00 = 4;
        waitPacket->parentUID = resourcePacket->uid;
        waitPacket->preUpdateWait.type = 4;
        waitPacket->preUpdateWait.value = savedSE->uid;
        waitPacket->actionUID = actionUID;
        btlPacketRegister(waitPacket, BTLPACKET_TYPE_3D);

        packet = FUN_002dd5e0(1);
        packet->unk_00 = 5;
        packet->parentUID = waitPacket->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        packet = btlUnit00285d30(childUnit, 0xe0ffffff, 0xc, 0, 3, 1);
        packet->unk_00 = 4;
        packet->parentUID = resourcePacket->uid;
        packet->preUpdateWait.type = 0xb;
        packet->preUpdateWait.value = waitPacket->uid;
        packet->preUpdateDelay = 1;
        packet->actionUID = actionUID;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        chainUID = resourcePacket->uid;
    }

    packet = FUN_002db740(action, 5, 0, 0, 0);
    packet->unk_00 = 0xb;
    packet->parentUID = chainUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    FUN_001fdd40();

    packet = FUN_0029fa50(0x10);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->unk_47 &= ~0x20;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a1080(0x10, 0);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->unk_47 &= ~0x20;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a16c0(0x10);
    packet->unk_00 = 4;
    packet->parentUID = castAnim->uid;
    packet->unk_47 &= ~0x20;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a1db0(8);
    packet->unk_00 = 4;
    packet->parentUID = chainUID;
    packet->unk_47 &= ~0x20;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);

    func_002b9030(formation);

    if (FUN_002dc130(action))
    {
        btlActionSetState(action, BTLACTION_STATE_BADDMG);
        return;
    }
    if (action->target.commandId == 2 || action->target.commandId == 3 || action->target.commandId == 1)
    {
        state = BTLACTION_STATE_PACKET;
    }
    else
    {
        state = BTLACTION_STATE_PACKET;
    }
    btlActionSetState(action, state);
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
    BtlPacket* animPacket;
    u16 animation;
    u16 table;
    u16 cameraState;
    u16 duration;
    u16 state;
    u32 isCommand3;
    u64 actionUID;
    f32 one = 1.0f;

    btlAction0028a780(action);
    isCommand3 = action->target.commandId == 3;
    actionUID = action->uid;
    if (!isCommand3)
    {
        packet = FUN_002bd590(action->unit, action->target.specificId);
        packet->actionUID = actionUID;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    }
    else
    {
        packet = FUN_002bd690(action->unit, action->target.unk_38);
        packet->actionUID = actionUID;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    }

    if (action->unit->genus == UNIT_GENUS_PC)
    {
        if (!isCommand3)
        {
            animation = 0xc;
            table = 0x1c;
        }
        else
        {
            animation = 0x15;
            table = 0x38;
        }
        cameraState = BTLCAMERA_STATE_SKILLRECITE_P;
        duration = FUN_002838d0_btlAction(one, action->unit, animation);
    }
    else
    {
        animation = FUN_002d6370(action->target.specificId) != 0 ? 4 : 7;
        table = 0x21;
        cameraState = BTLCAMERA_STATE_SKILLRECITE_E;
        duration = FUN_002835e0_btlAction(one, action->unit, animation);
    }

    animPacket = btlUnitCreateAnimPacketSignedId(action->unit, animation, 6, one, BTLUNIT_ANIM_MODE_ONCE);
    ACTION_U16(animPacket, 0x4a) = duration + 6;
    animPacket->actionUID = actionUID;
    btlPacketRegister(animPacket, BTLPACKET_TYPE_1);

    packet = func_002bb2f0(ACTION_U32(gBtl, 0xc24 + table * 4), action->unit, 0, animPacket->uid, 0x100);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_3D);

    packet = btlCameraCreateSetStatePacket(action, cameraState);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);

    packet = FUN_002bd850(action->unit, ACTION_U16(action, 0xdc));
    packet->unk_00 = 4;
    packet->parentUID = animPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);

    packet = FUN_002d7fb0(action, 0);
    packet->unk_00 = 4;
    packet->parentUID = animPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    if (FUN_002dc130(action))
    {
        btlActionSetState(action, BTLACTION_STATE_BADDMG);
        return;
    }
    switch (action->target.commandId)
    {
    case 1:
    case 3:
    case 2:
        state = BTLACTION_STATE_PACKET;
        break;
    default:
        state = BTLACTION_STATE_PACKET;
        break;
    }
    btlActionSetState(action, state);
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
/* W212: template 00297760 suggested restoring actionUID writes after two packet constructors; the honest probe grew 788 to 804 bytes but regressed nd507 to nd548 (window 880), so it was reverted. Residual starts at frame 0x50 versus retail 0x80, confirming broader missing packet-chain structure. */
// FUN_00295fa0 NONMATCHING
void btlActionUpdateStateEndure(BtlAction* action)
{
    BtlPacket* packet;
    BtlPacket* root;
    BtlPacket* barrier;
    BtlPacket* animPacket;
    BtlPacket* messagePacket;
    BtlUnit* unit;
    s32 work[4];
    u16 skillId;
    s16 messageId;
    u16 count;

    unit = action->unit;

    if (btlPacketCountById(0xff03) != 0)
    {
        return;
    }
    skillId = ACTION_U16(action, 0x460);
    barrier = FUN_0027dc00(0x80000);
    barrier->actionUID = action->uid;
    btlPacketRegister(barrier, BTLPACKET_TYPE_0);
    if (skillId == 0x1b6)
    {
        messageId = 0xdf;
    }
    else if (skillId == 0x23c)
    {
        messageId = unit->genus == UNIT_GENUS_PC ? 0x42 : 0x43;
    }
    else
    {
        messageId = unit->genus == UNIT_GENUS_PC ? 0x40 : 0x41;
    }
    messagePacket = FUN_002bd850(unit, messageId);
    ACTION_U16(messagePacket, 0x48) = 8;
    messagePacket->actionUID = action->uid;
    btlPacketRegister(messagePacket, BTLPACKET_TYPE_2D);
    animPacket = FUN_00284c90(unit);
    animPacket->actionUID = action->uid;
    btlPacketRegister(animPacket, BTLPACKET_TYPE_1);
    if (skillId == 0x23c)
    {
        count = func_00170760((s16)unit->datUnit->id, 0xfc7);
        func_00170860((s16)unit->datUnit->id, 0xfc7, count - 1);
        FUN_002d5dc0(work);
        work[0] = (FUN_002ffdf0(unit->datUnit) & 0xffff) -
                  (FUN_002ffd70(unit->datUnit) & 0xffff);
        root = FUN_002d7e20(action, action, work, 1, 1);
        root->unk_00 = 4;
        root->parentUID = animPacket->uid;
        root->actionUID = action->uid;
        btlPacketRegister(root, BTLPACKET_TYPE_1);
        packet = FUN_002bd480(unit);
        packet->unk_00 = 4;
        packet->parentUID = animPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002bdbd0(unit, unit, -1, 0, 0, 0, 1, work);
        packet->unk_00 = 4;
        packet->parentUID = animPacket->uid;
        packet->unk_47 &= ~0x20;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
        packet = FUN_002bd230(unit, 0, 0);
        packet->unk_00 = 4;
        packet->parentUID = animPacket->uid;
        packet->unk_47 &= ~0x20;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
        packet = FUN_002baf90(ACTION_U32(gBtl, 0xce0), unit, unit, 1, 0);
        packet->unk_00 = 4;
        packet->parentUID = animPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
    }
    barrier = FUN_0027dc80(0x80000);
    barrier->unk_00 = 4;
    barrier->parentUID = messagePacket->uid;
    barrier->actionUID = action->uid;
    btlPacketRegister(barrier, BTLPACKET_TYPE_0);
    btlActionSetState(action, BTLACTION_STATE_STANDBY);
}

// FUN_00296310
void btlActionInitStateWait(BtlAction* action)
{
    (void)action;
}
// FUN_00296320
void btlActionUpdateStateWait(BtlAction* action)
{
    BtlPacket* packet;

    switch (action->target.commandId)
    {
        case 7:
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
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            }
            else
            {
                packet = func_002bd780(action->unit, action->target.commandId);
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            }
            packet = btlVoice002e2be0(action, 0x1a, 0, 0, 0);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            break;
        case 8:
        case 11:
            break;
        default:
            K_Assert(D_00693318_abs, 0x1bae);
            break;
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

// FUN_00297480
void btlActionInitStatePersona(BtlAction* action)
{
    BtlPacket* packet;
    BtlPacket* root;
    s32 table;
    u16 personaId;
    BtlUnit* personaUnit;

    btlAction0028a780(action);
    packet = func_002bd780(action->unit, action->target.commandId);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    packet = btlCameraCreateSetStatePacket(action, BTLCAMERA_STATE_PERSONA);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    if (action->unit->genus == UNIT_GENUS_PC)
    {
        packet = FUN_002843e0(action->unit, 6);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    else
    {
        packet = btlUnitCreateAnimPacket(action->unit, 0x17, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
    }
    packet = btlVoice002e2be0(action, 0x19, 0, 0, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    if (action->unit->genus != UNIT_GENUS_PC)
    {
        goto persona_init_done;
    }
    FUN_00175130_btlAction(*(u16*)action->target.unkData1);
    personaId = *(volatile u16*)action->target.unkData1;
    personaUnit = (BtlUnit*)*(volatile BtlUnit**)&action->unit;
    btlUnitInitPersona(personaUnit, personaId);
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
    btlPacketRegister(packet, BTLPACKET_TYPE_2D);
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
// FUN_00297760
void btlActionUpdateStateBadDamage(BtlAction* action)
{
    BtlPacket* root;
    BtlPacket* packet;
    BtlUnit* unit;
    BtlTargetResult work;
    s32 damage;
    u32 badStatus;
    s64 actionUID;
    u16 state;

    if (btlPacketCountById(0x700))
    {
        return;
    }
    if (btlPacketCountById(0x506))
    {
        return;
    }
    if (btlPacketCountById(0x507))
    {
        return;
    }
    if (btlPacketCountById(0x301))
    {
        return;
    }

    unit = action->unit;
    badStatus = datCalcGetBadStatus(unit->datUnit);
    actionUID = action->uid;
    switch (badStatus & 0xfffff)
    {
    case 0x80:
        FUN_002d5dc0(&work);
        damage = FUN_002dc670(action);
        work.hpDelta = damage;
        if (damage < 0)
        {
            root = FUN_002d7e20(action, action, &work, 1, 1);
            btlPacketRegister(root, BTLPACKET_TYPE_1);
            packet = FUN_002bd480(unit);
            packet->unk_00 = 4;
            packet->parentUID = root->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002bdbd0(unit, unit, -1, 0, 0, 0, 1, &work);
            packet->unk_00 = 4;
            packet->parentUID = root->uid;
            packet->unk_47 &= ~0x20;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            packet = FUN_002bd230(unit, 0, 0);
            packet->unk_00 = 4;
            packet->parentUID = root->uid;
            packet->unk_47 &= ~0x20;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            packet = btlUnitCreateAnimPacketSignedId(action->unit, BTLUNIT_ANIM_RESNULLIFIED, 0, 1.0f, BTLUNIT_ANIM_MODE_ONCE);
            packet->unk_00 = 4;
            packet->parentUID = root->uid;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002dd100(10, 6, 0xc);
            packet->unk_00 = 4;
            packet->parentUID = root->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        switch (action->target.commandId)
        {
        case 1:
        case 3:
        case 2:
            state = BTLACTION_STATE_PACKET;
            break;
        default:
            state = BTLACTION_STATE_PACKET;
            break;
        }
        btlActionSetState(action, state);
        break;
    default:
        switch (action->target.commandId)
        {
        case 1:
        case 3:
        case 2:
            state = BTLACTION_STATE_PACKET;
            break;
        default:
            state = BTLACTION_STATE_PACKET;
            break;
        }
        btlActionSetState(action, state);
        break;
    }
}
// FUN_00297a50
u32 FUN_00297a50(BtlAction* action)
{
    return ACTION_U32(action, 0x48c);
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
// FUN_00296660
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
    if (action->movedAwayFromHome == 1)
    {
        if (*(s16*)action->unkData4 == 0)
        {
            FUN_001ff160(action->unit->charId);
            *(s16*)action->unkData4 = -1;
        }
        else if (*(s16*)action->unkData4 > 0)
        {
            *(s16*)action->unkData4 -= 1;
        }
    }
    if (action->unk_488 == 0)
    {
        if (*(s16*)action->unkData4 != -1)
        {
            return;
        }
        if (FUN_001ff2b0() == 0)
        {
            return;
        }
        FUN_001ff2f0();
        packet = FUN_002e41d0();
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (FUN_002d1a70() == 1)
        {
            gBtl->flags |= 0x4000;
            FUN_001ff370();
        }
        action->unk_488 = 1;
        return;
    }
    if (FUN_001ff2d0() == 0)
    {
        btlActionSetState(action, BTLACTION_STATE_ESCAPE);
    }
    else
    {
        btlPacketRegister(btlVoice002e2be0(action, 3, 0, 0, 0), BTLPACKET_TYPE_1);
        action->unk_18 |= 0x80;
        btlActionSetState(action, action->unk_14);
    }
}

BtlPacket* func_002bfb50(void);
BtlPacket* func_002bfae0(void);
BtlPacket* func_002dd1f0(u32 a, u32 b, u32 c);
s32 func_0030c2a0(DatUnit* unit);
void func_00280050(BtlUnit* unit, RwV3d* dst);
s32 func_002d4cc0(u16 unitId);
u64 func_002b9640(u8* data);
BtlPacket* func_002a1db0(u32 a);
extern RwV3d D_006978A0;

// FUN_00296880
void btlActionInitStateEscape(BtlAction* action)
{
    (void)action;
}
// FUN_00296890 NONMATCHING
void btlActionUpdateStateEscape(BtlAction* action)
{
    BtlAction* current;
    BtlAction* escapeActions[10];
    BtlUnit* unit;
    BtlUnit* currentUnit;
    BtlPacket* rootPacket;
    BtlPacket* packet;
    BtlPacket* movePacket;
    RwV3d sphereCenter;
    RwV3d direction;
    RwV3d rotation;
    RwV3d destination;
    u16 count;
    u16 i;
    u16 mode;
    u16 hasDownEnemy;

    btlAction0028a780(action);
    rootPacket = func_002bd780(action->unit, action->target.commandId);
    rootPacket->actionUID = action->uid;
    btlPacketRegister(rootPacket, BTLPACKET_TYPE_3D);

    mode = 0;
    hasDownEnemy = 0;
    count = 0;
    unit = action->unit;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
        if (unit->charId == 1)
        {
            hasDownEnemy = 1;
            current = gBtl->actionList.tail;
            while (current != NULL)
            {
                currentUnit = current->unit;
                if ((current->unk_1a & 1) != 0 &&
                    currentUnit->genus == UNIT_GENUS_EC &&
                    currentUnit->datUnit != NULL &&
                    datCalcChkBadStatus(currentUnit->datUnit, UNIT_BADSTATUS_DOWN) == 0)
                {
                    hasDownEnemy = 0;
                    break;
                }
                current = current->prev;
            }

            if (func_0030c2a0(unit->datUnit) != 0 ||
                hasDownEnemy != 0 ||
                gBtl->order.flags == 1)
            {
                mode |= 4;
            }
            else
            {
                mode |= 2;
            }

            current = gBtl->actionList.tail;
            while (current != NULL)
            {
                currentUnit = current->unit;
                if ((current->unk_1a & 1) != 0 &&
                    currentUnit->genus == UNIT_GENUS_PC &&
                    datCalcIsDead(currentUnit->datUnit, 0) == 0)
                {
                    if ((mode & 2) != 0 && current != action)
                    {
                        current->unk_18 |= 0x8000;
                    }
                    escapeActions[count] = current;
                    count++;
                }
                current = current->prev;
            }

            if ((gBtl->order.flags & 2) != 0)
            {
                FUN_0029a750();
                gBtl->order.flags &= ~2;
            }
            mode |= 1;
        }
        else
        {
            count = 1;
            action->unk_18 |= 0x20;
            action->unk_1a &= ~8;
        }
        break;

    case UNIT_GENUS_EC:
        count = 1;
        action->unk_18 |= 0x20;
        action->unk_1a &= ~8;
        break;
    }

    if ((mode & 2) == 0)
        {
        if ((mode & 1) == 0)
        {
            packet = btlCameraCreateSetStatePacket(action, 9);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }
        else
        {
            packet = btlCameraCreateSetStatePacket(action, 7);
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }

        if (unit->genus == UNIT_GENUS_PC)
        {
            packet = func_002dd1f0(0xf, 2, 0);
            packet->unk_00 = 5;
            packet->parentUID = rootPacket->uid;
            packet->preUpdateDelay = 0x20;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

            if ((mode & 4) == 0)
            {
                if (action->oldState == 0x1a)
                {
                    movePacket = btlVoice002e2be0(action, 2, 0, 0, 0);
                    movePacket->actionUID = action->uid;
                    btlPacketRegister(movePacket, BTLPACKET_TYPE_1);
                    packet = FUN_002db740(action, 3, 0, 0, 0);
                    packet->unk_00 = 4;
                    packet->parentUID = movePacket->uid;
                    packet->actionUID = action->uid;
                    btlPacketRegister(packet, BTLPACKET_TYPE_1);
                }
            }
            else
            {
                packet = func_002bfb50();
                packet->unk_00 = 5;
                packet->parentUID = rootPacket->uid;
                packet->preUpdateDelay = 0x16;
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
        }
        else
        {
            packet = func_002dd100(0xc, 2, 0x16);
            packet->unk_00 = 5;
            packet->parentUID = rootPacket->uid;
            packet->preUpdateDelay = 0x1c;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

            packet = FUN_002db740(action, 4, 0, 0, 0);
            packet->actionUID = action->uid;
            packet->preUpdateDelay = 0xc;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }

        for (i = 0; i < count; i++)
        {
            current = escapeActions[i];
            currentUnit = current->unit;
            btlUnitGetSphereWorldCenter(currentUnit, &sphereCenter);
            btlUnit0027f7c0(currentUnit, NULL, &rotation, NULL);
            RtQuatTransformVectors(&direction, &D_006978A0, 1, (RtQuat*)&rotation);
            if (unit->genus == UNIT_GENUS_PC)
            {
                direction.x *= 500.0f;
                direction.y *= 500.0f;
                direction.z *= 500.0f;
                destination.x = sphereCenter.x + direction.x;
                destination.y = sphereCenter.y + direction.y;
                destination.z = sphereCenter.z + direction.z;
                movePacket = btlUnitCreateMovePacket(currentUnit, &destination, 0.5f, 0);
            }
            else
            {
                if (iGpffffb728[currentUnit->charId].field_22 != 1)
                {
                    direction.x *= 129.6f;
                    direction.y *= 129.6f;
                    direction.z *= 129.6f;
                    destination.x = sphereCenter.x + direction.x;
                    destination.y = sphereCenter.y + direction.y;
                    destination.z = sphereCenter.z + direction.z;
                }
                else
                {
                    destination = sphereCenter;
                }
                movePacket = btlUnitCreateMovePacket(currentUnit, &destination, 0.2f, 4);
            }
            movePacket->unk_00 = 5;
            movePacket->parentUID = rootPacket->uid;
            movePacket->preUpdateDelay = 0x16;
            movePacket->actionUID = action->uid;
            btlPacketRegister(movePacket, BTLPACKET_TYPE_1);

            packet = btlUnit00285d30(currentUnit, 0xffffff, 8, 0, 4, 0);
            packet->unk_00 = 5;
            packet->parentUID = movePacket->uid;
            packet->preUpdateDelay = 0xc;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }

        if ((mode & 4) != 0)
        {
            packet = btlCreateSetFlagsPacket(0x80);
            packet->unk_00 = 4;
            packet->parentUID = movePacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            *(u32*)((u8*)gBtl + 0x1c) = 3;
        }
    }
    else
    {
        packet = btlCameraCreateSetStatePacket(action, 7);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);

        packet = func_002bfb50();
        packet->unk_00 = 5;
        packet->parentUID = rootPacket->uid;
        packet->preUpdateDelay = 0x16;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        for (i = 0; i < count; i++)
        {
            current = escapeActions[i];
            currentUnit = current->unit;
            btlUnitGetSphereWorldCenter(currentUnit, &sphereCenter);
            btlUnit0027f7c0(currentUnit, NULL, &rotation, NULL);
            RtQuatTransformVectors(&direction, &D_006978A0, 1, (RtQuat*)&rotation);
            direction.x *= 500.0f;
            direction.y *= 500.0f;
            direction.z *= 500.0f;
            destination.x = sphereCenter.x + direction.x;
            destination.y = sphereCenter.y + direction.y;
            destination.z = sphereCenter.z + direction.z;
            movePacket = btlUnitCreateMovePacket(currentUnit, &destination, 0.5f, 8);
            movePacket->unk_00 = 5;
            movePacket->parentUID = rootPacket->uid;
            movePacket->preUpdateDelay = 0xb;
            movePacket->actionUID = action->uid;
            btlPacketRegister(movePacket, BTLPACKET_TYPE_1);

            packet = btlUnit00285d30(currentUnit, 0xffffff, 8, 0, 4, 0);
            packet->unk_00 = 5;
            packet->parentUID = movePacket->uid;
            packet->preUpdateDelay = 0xc;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }

        packet = func_002bfae0();
        packet->unk_00 = 4;
        packet->parentUID = rootPacket->uid;
        packet->preUpdateDelay = 0xc;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        packet = FUN_002bd850(action->unit, 0xd8);
        packet->unk_00 = 4;
        packet->parentUID = rootPacket->uid;
        packet->preUpdateDelay = 4;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);

        packet = FUN_002db740(action, 2, 0, 0, 2);
        packet->unk_00 = 4;
        packet->parentUID = rootPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        for (i = 0; i < count; i++)
        {
            current = escapeActions[i];
            currentUnit = current->unit;
            func_00280050(currentUnit, &sphereCenter);
            btlUnit0027f7c0(currentUnit, NULL, &rotation, NULL);
            RtQuatTransformVectors(&direction, &D_006978A0, 1, (RtQuat*)&rotation);
            direction.x *= 250.0f;
            direction.y *= 250.0f;
            direction.z *= 250.0f;
            destination.x = sphereCenter.x + direction.x;
            destination.y = sphereCenter.y + direction.y;
            destination.z = sphereCenter.z + direction.z;

            movePacket = btlUnitCreateMovePacket(currentUnit, &destination, 1.0f, 9);
            movePacket->unk_00 = 4;
            movePacket->parentUID = rootPacket->uid;
            movePacket->actionUID = action->uid;
            btlPacketRegister(movePacket, BTLPACKET_TYPE_1);

            unit = (BtlUnit*)btlUnitCreateMovePacket(currentUnit, &destination, 0.5f, 0x18);
            ((BtlPacket*)unit)->unk_00 = 4;
            ((BtlPacket*)unit)->parentUID = movePacket->uid;
            ((BtlPacket*)unit)->actionUID = action->uid;
            btlPacketRegister((BtlPacket*)unit, BTLPACKET_TYPE_1);

            packet = btlUnitCreateRotatePacket(currentUnit, NULL, 0x20);
            packet->unk_00 = 4;
            packet->parentUID = ((BtlPacket*)unit)->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

            packet = btlUnit00285d30(currentUnit, (u32)-1, 4, 0, 4, 0);
            packet->unk_00 = 4;
            packet->parentUID = rootPacket->uid;
            packet->preUpdateDelay = 0xc;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
    }

    packet = FUN_002d7fb0(action, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    btlActionSetState(action, BTLACTION_STATE_PACKET);
}

// FUN_00297a60 NONMATCHING
void btlActionInitStateRoundUpMes(BtlAction* action)
{
    BtlPacket* pkt;
    BtlPacket* rootPkt;
    BtlAction* selected;
    BtlAction* candidate;
    BtlUnit* unit;
    u16 i;
    u16 count;
    u32 changeForm;
    u16 speedIdx;
    RwV3d homePos;

    selected = NULL;
    unit = action->unit;
    if (unit->genus == UNIT_GENUS_PC)
    {
        candidate = action;
    }
    else
    {
        candidate = action->target.targetedActions[0];
    }
    if (candidate != NULL)
    {
        count = ACTION_U16(gBtl, 0xb98);
        for (i = 0; i < count; i++)
        {
            if (*(void**)((u8*)gBtl + 0xb88 + i * 4) == candidate)
            {
                selected = candidate;
                break;
            }
        }
    }
    if (selected == NULL)
    {
        selected = (void*)*(u32*)((u8*)gBtl + 0xb88 +
                                 (FUN_002ffbc0(ACTION_U16(gBtl, 0xb98)) & 0xffff) * 4);
    }

    pkt = FUN_002e38a0(ACTION_U16(selected->unit, 0xa4));
    pkt->actionUID = action->uid;
    btlPacketRegister(pkt, BTLPACKET_TYPE_1);

    if (*(u32*)((u8*)gBtl + 0x148) != 0)
    {
        pkt = FUN_002886e0(0, *(BtlUnit**)((*(u32*)((u8*)gBtl + 0x148)) + 0x30), 1);
        pkt->actionUID = action->uid;
        btlPacketRegister(pkt, BTLPACKET_TYPE_1);
    }
    if (*(u32*)((u8*)gBtl + 0x148) != 0)
    {
        pkt = FUN_00288950(*(BtlUnit**)((*(u32*)((u8*)gBtl + 0x148)) + 0x30), 0);
        pkt->actionUID = action->uid;
        btlPacketRegister(pkt, BTLPACKET_TYPE_1);
    }

    changeForm = 0;
    if (unit->genus == UNIT_GENUS_PC)
    {
        if (ACTION_S16(gBtl, 0xa38) != -1 &&
            ((u32)(ACTION_S16(gBtl, 0xa3a) >> 1) >= (FUN_002d4e10(2, 0x80000) & 0xffff)) &&
            ACTION_S16(gBtl, 0xa38) != FUN_002b7060())
        {
            changeForm = 1;
        }
    }

    if (changeForm != 0)
    {
        rootPkt = FUN_002b8f40(1);
        rootPkt->actionUID = action->uid;
        btlPacketRegister(rootPkt, BTLPACKET_TYPE_0);

        selected = *(void**)((u8*)gBtl + 0x150);
        while (selected != NULL)
        {
            if (FUN_00300580(ACTION_U32(selected->unit, 0xa2c), 0x180000) == 0 &&
                FUN_0030b5a0(ACTION_U32(selected->unit, 0xa2c), 0) == 0)
            {
                pkt = FUN_002819d0_btlAction((BtlUnit*)selected, 0, D_00693300[0], 24);
                pkt->unk_00 = 4;
                pkt->parentUID = rootPkt->uid;
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            }
            selected = *(void**)((u8*)selected + 0xa34);
        }
    }
    else
    {
        pkt = FUN_002b8d60(2, 0xfff);
        pkt->actionUID = action->uid;
        btlPacketRegister(pkt, BTLPACKET_TYPE_0);

        if ((gBtl->flags & 0x40000000) && (ACTION_U16(gBtl, 0x18) & 2))
        {
            pkt = FUN_002b8d60(1, 0xfff);
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_0);
        }
        else
        {
            u32 allowMove;
            u16 unitDatId;
            u8 genus;

            btlUnit0027f7c0(unit, &homePos, NULL, NULL);
            if (FUN_002d1ed0(&unit->pos, &homePos) > 75.0f)
            {
                if (FUN_00300580(unit->datUnit, 0x180000) == 0)
                {
                    allowMove = !(iGpffffb708[(u32)action->target.specificId * 0x2c] & 2);
                    unitDatId = unit->datUnit->id;
                    genus = unit->genus;
                    if (genus == UNIT_GENUS_EC)
                    {
                        speedIdx = iGpffffb728[unitDatId].moveSpeed[allowMove].speedIndex;
                    }
                    else
                    {
                        speedIdx = 0;
                    }
                    pkt = FUN_002819d0_btlAction((BtlUnit*)selected, 0, D_00693300[speedIdx], 24);
                    pkt->actionUID = action->uid;
                    btlPacketRegister(pkt, BTLPACKET_TYPE_1);
                }
            }

            pkt = FUN_002822b0(unit, &homePos, 0);
            pkt->unk_00 = 4;
            pkt->actionUID = action->uid;
            btlPacketRegister(pkt, BTLPACKET_TYPE_1);
        }
    }

    if ((gBtl->flags & 0x40000000) && (ACTION_U16(gBtl, 0x18) & 2))
    {
        selected = *(void**)((u8*)gBtl + 0x14c);
        while (selected != NULL)
        {
            if ((ACTION_U16(selected, 0x1a) & 1) &&
                FUN_0030b5a0(ACTION_U32(selected->unit, 0xa2c), 0) == 0)
            {
                pkt = FUN_002843e0(selected->unit, 0);
                pkt->actionUID = action->uid;
                btlPacketRegister(pkt, BTLPACKET_TYPE_1);
            }
            selected = *(void**)((u8*)selected + 0x4a8);
        }
    }

    pkt = FUN_002a1db0(0);
    pkt->actionUID = action->uid;
    btlPacketRegister(pkt, BTLPACKET_TYPE_0);

    pkt = FUN_002a3b40(action, 6);
    pkt->actionUID = action->uid;
    btlPacketRegister(pkt, BTLPACKET_TYPE_0);

    gBtl->flags &= 0xffbfffff;
    ACTION_U16(gBtl, 0x18) = 0;

    if (FUN_002d1a70() == 1)
    {
        gBtl->flags &= ~0x4000;
        FUN_001ff350();
    }

    action->movedAwayFromHome = (u32)selected;
    action->unk_488 = 0;
    ACTION_U32(action, 0x48c) = 0;
    ACTION_U16(action, 0x490) = 0x12;
}
// FUN_00298060 NONMATCHING
void btlActionUpdateStateRoundUpMes(BtlAction* action)
{
    BtlPacket* packet;
    BtlPacket* callbackPacket;
    BtlAction* selected = (BtlAction*)action->movedAwayFromHome;
    u16 partyIds[3];
    f32 setup[16];
    u32 i;
    u32 special;
    s16 timer;

    if (action->unk_488 == 0)
    {
        if (btlPacketCountById(0xc03) != 0)
        {
            return;
        }
        i = 0;
        while (i < ACTION_U16(gBtl, 0xb98))
        {
            partyIds[i] = ((BtlAction*)ACTION_U32(gBtl, 0xb88 + i * 4))->unit->charId;
            i++;
        }
        while (i < 3)
        {
            partyIds[i] = 0;
            i++;
        }
        packet = func_002e3b50(partyIds[0], partyIds[1], partyIds[2]);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = func_002e3990();
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = btlVoice002e2be0(selected, 4, 0, 0, 0);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002dd100(10, 2, 0x12);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        callbackPacket = func_0027f410((u32)btlActionInitStateRoundUpMes, action);
        btlPacketRegister(callbackPacket, BTLPACKET_TYPE_1);

        setup[0] = DAT_007cb050[0];
        setup[1] = DAT_007cb050[1];
        setup[2] = DAT_007cb050[2];
        setup[3] = 3;
        setup[4] = DAT_007cb050[3];
        setup[5] = DAT_007cb050[4];
        setup[6] = DAT_007cb050[5];
        setup[8] = DAT_007cb050[6];
        setup[9] = DAT_007cb050[7];
        setup[10] = DAT_007cb050[8];
        setup[12] = DAT_007cb050[9];
        setup[13] = DAT_007cb050[10];
        setup[14] = DAT_007cb050[11];
        func_002b9600(setup);
        packet = func_002bb2f0(ACTION_U32(gBtl, 0xd10), action->unit, 0,
                               callbackPacket->uid, 0xc000);
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
        action->unk_488 = 1;
    }

    timer = ACTION_S16(action, 0x490);
    if (timer == 0)
    {
        FUN_001fef90(selected->unit->charId);
        ACTION_S16(action, 0x490) = -1;
    }
    else if (timer > 0)
    {
        ACTION_S16(action, 0x490) = timer - 1;
    }
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) != NULL)
    {
        return;
    }
    if (ACTION_U32(action, 0x48c) != 0)
    {
        goto set_state;
    }
    if (FUN_001ff100() == 0)
    {
        return;
    }

    special = 0;
    if (FUN_001ff120() == 0)
    {
        packet = FUN_002d7fb0(action, 2);
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        ACTION_U32(gBtl->camera.action, 0x494) = ACTION_U32(action, 0x484);
        gBtl->camera.action->unk_16 = 0x1d;
        FUN_0029a380(gBtl->camera.action);
    }
    else
    {
        packet = btlVoice002e2be0(selected, 6, 0, 0, 0);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = func_002e3d10();
        packet->unk_00 = 0xa;
        ACTION_U16(packet, 8) = 0xc06;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        special = 1;
    }

    FUN_001ff140();
    packet = func_002e3a90();
    if (special != 0)
    {
        packet->actionUID = action->uid;
    }
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_00288950(NULL, 1);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    action->unk_18 &= ~8;
    if (func_002d1a70() == 1)
    {
        gBtl->flags |= 0x4000;
        FUN_001ff370();
        action->unk_488 = 1;
        return;
    }
set_state:
    btlActionSetState(action, BTLACTION_STATE_ROUNDUP);
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
    /* Retail passes the scalar in f12 here, unlike the unit-first callers of this symbol. */
    extern BtlPacket* FUN_00284200(f32, BtlUnit*, u16, u16, u16);
    BtlPacket* packet;
    BtlPacket* skillPacket;
    BtlPacket* voicePacket;
    BtlAction* target;
    BtlAction* current;
    u32 rootH;
    u32 stackBuf[3];
    u16 i;
    u16 j;
    u32 posX;
    u32 posY;

    u32 mode;
    u8 workBuf[0x100];
    u32 extraWork[4];
    BtlAction* basis;

    rootH = FUN_002b8f90(1);
    for (current = gBtl->actionList.tail; current != NULL; current = current->prev)
    {
        if (current->unk_28 != 0)
        {
            FUN_002d7fb0(current, 2);
        }
    }
    for (j = 0; j < 3; j++)
    {
        stackBuf[j] = 0;
    }
    for (j = 0; j < ACTION_U16(gBtl, 0xb98) && j < 3; j++)
    {
        stackBuf[j] = ACTION_U32(gBtl, 0xb88 + j * 4);
    }

    packet = FUN_002bc950(stackBuf[0], stackBuf[1], stackBuf[2]);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002e3c80();
    packet->unk_00 = 0xa;
    ACTION_U16(packet, 8) = 0xc06;
    ACTION_U8(packet, 0x10) = 0xa;
    ACTION_U16(packet, 0x18) = 0xc05;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    voicePacket = btlVoice002e2be0((BtlAction*)ACTION_U32(action, 0x494), 5, 0, 0, 0);
    voicePacket->unk_00 = 5;
    voicePacket->parentUID = packet->uid;
    voicePacket->actionUID = action->uid;
    btlPacketRegister(voicePacket, BTLPACKET_TYPE_1);

    voicePacket = FUN_002dd690(3, 0x693358);
    voicePacket->unk_00 = 5;
    voicePacket->parentUID = packet->uid;
    voicePacket->actionUID = action->uid;
    btlPacketRegister(voicePacket, BTLPACKET_TYPE_1);
    func_002bb6f0(action->target.specificId, workBuf);
    packet = FUN_002bac00(rootH, (s8*)workBuf, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    basis = action->target.targetedCount != 0 ? action->target.targetedActions[0] : action;
    packet = FUN_002baf90(rootH, action->unit, basis->unit, 0, 0);
    packet->unk_00 = 4;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002dd100(0xc, 2, ACTION_U32(action, 0x498) ? 0x13 : 0x14);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    mode = (u32)func_002d4cc0(0);
    mode += (u32)func_002b9640((u8*)action + 0xc8);
    if (mode == 0xffffffff)
    {
        extraWork[0] = mode;
    }


    for (i = 0; i < action->target.targetedCount; i++)
    {
        target = action->target.targetedActions[i];
        if (target == NULL)
        {
            continue;
        }

        skillPacket = FUN_002bd480(target->unit);
        skillPacket->actionUID = action->uid;
        btlPacketRegister(skillPacket, BTLPACKET_TYPE_1);

        packet = FUN_002baf90(rootH, action->unit, target->unit, 1, 0);
        packet->unk_00 = 0xb;
        packet->parentUID = skillPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_3D);
        packet = FUN_002baf90(rootH, action->unit, target->unit, 1, 0);
        packet->unk_00 = 4;
        packet->parentUID = skillPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002dd100(10, 0, 4);
        packet->parentUID = skillPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002baf90(rootH, action->unit, target->unit, 1, 0);
        packet->unk_00 = 4;
        packet->parentUID = skillPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);


        for (j = 0; j < ACTION_U8(target, 0xc8); j++)
        {
            u8* result = (u8*)target + 0xe0 + j * 0x1c;

            packet = FUN_002bdbd0(action->unit, target->unit, action->target.specificId,
                                  ACTION_U16(target, 0xcc), ACTION_U16(target, 0xce), j,
                                  ACTION_U8(target, 0xc8), result);
            packet->parentUID = skillPacket->uid;
            packet->unk_47 &= ~0x20;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);

            packet = FUN_00284200(1.0f, target->unit, ACTION_U8(target, 0xc8) - 1, 0, 0);
            packet->unk_00 = 0xb;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

            packet = FUN_002bd230(target->unit, 0, 0);
            packet->unk_00 = 5;
            packet->parentUID = skillPacket->uid;
            packet->unk_47 &= ~0x20;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_2D);
            packet = FUN_00282650(target->unit, action->unit, 2);
            packet->unk_00 = 5;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002d7e20(action, target, result,
                                  ACTION_U16(target, 0xcc), ACTION_U16(target, 0xce));
            packet->unk_00 = 5;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002d8090(target);
            packet->unk_00 = 5;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_002d8090(action);
            packet->unk_00 = 5;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            FUN_002d5dc0(extraWork);
            packet = FUN_002d7e20(target, target, extraWork, 1, 1);
            packet->unk_00 = 4;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_00284200(1.0f, target->unit, 10, 0, 0);
            packet->unk_00 = 4;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            packet = FUN_00284c90(target->unit);
            packet->unk_00 = 4;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

        }

        {
            func_0029ea60(target->uid, &posX, &posY);

            packet = func_0029f4b0(posX, posY, 0x10);
            packet->unk_00 = 4;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);

            {
                void* area = func_0029ec00(target->uid);
                func_0029ec80(target->uid, &posX, &posY);

                packet = func_002a0050(area, posX, posY, 0x10, 0);
                packet->unk_00 = 4;
                packet->parentUID = skillPacket->uid;
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }

            {
                void* hitArea = func_0029ec50(target->uid);
                packet = func_002a1280(hitArea, 0x10);
                packet->unk_00 = 4;
                packet->parentUID = skillPacket->uid;
                packet->actionUID = action->uid;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }

            packet = func_002a1b00(action, target->uid, 0x10);
            packet->unk_00 = 4;
            packet->parentUID = skillPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }
        btlPacketRegister(packet, BTLPACKET_TYPE_2D);
    }

    packet = FUN_0029fa50(0x10);
    packet->unk_00 = 4;
    packet->unk_47 &= ~0x20;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a1080(0x10, 0);
    packet->unk_00 = 4;
    packet->parentUID = skillPacket->uid;
    packet->unk_47 &= ~0x20;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a16c0(0x10);
    packet->unk_00 = 4;
    packet->parentUID = skillPacket->uid;
    packet->unk_47 &= ~0x20;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002a1db0(8);
    packet->unk_00 = 4;
    packet->parentUID = skillPacket->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002bc950(0, 0, 0);
    packet->unk_00 = 4;
    packet->parentUID = packet->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    FUN_002b9030(rootH);
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

// FUN_00299520
void btlActionInitStateEndHome(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit = action->unit;
    BtlUnit* moveUnit;
    RwV3d homePos;
    u16 allowMove;
    u16 unitId;
    u16 speedIndex;
    BtlEnemyRecord* enemyRecords;

    action->movedAwayFromHome = 0;
    if (datCalcIsDead(unit->datUnit, 0) != 0)
    {
        if ((unit->flags3 & BTLUNIT_FLAG3_UNK40) != 0)
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
    btlUnit0027f7c0(unit, &homePos, NULL, NULL);
    if (action->unit->genus == UNIT_GENUS_PC)
    {
        action->movedAwayFromHome = 1;
    }
    if (FUN_002d1ed0(&unit->pos, &homePos) > 75.0f)
    {
        speedIndex = 2;
        allowMove = !(iGpffffb708[(u32)action->target.specificId * 0x2c] & 2);
        moveUnit = action->unit;
        unitId = moveUnit->datUnit->id;
        switch (moveUnit->genus)
        {
        case UNIT_GENUS_PC:
            break;
        case UNIT_GENUS_EC:
            enemyRecords = iGpffffb728;
            speedIndex = enemyRecords[unitId].moveSpeed[allowMove].speedIndex;
            break;
        default:
            break;
        }
        packet = btlUnitCreateMovePacket(moveUnit, &homePos, D_00693300[speedIndex], 0);
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

// FUN_00299800
void btlActionInitStateDead(BtlAction* action)
{
    BtlPacket* packet;
    BtlUnit* unit;
    u32 flags;

    unit = action->unit;
    FUN_0029a320(action);
    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
        FUN_00301690(unit->datUnit);
        if ((s8)ACTION_U8(unit->datUnit, 0x10) == 10)
        {
            ACTION_U8(unit->datUnit, 0x10) = 1;
        }
        break;
    case UNIT_GENUS_EC:
        FUN_0017c750((s16)unit->charId);
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
                btlPacketRegister(packet, BTLPACKET_TYPE_3D);
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
        break;
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
    BtlUnit* unit;
    DatUnitPc* found;
    u16 i;
    DatUnitGenusBase* group;
    DatUnitPc* current;

    if (action->unk_1a & 1)
    {
        unit = action->unit;
        if (unit->packetCount != 0)
        {
            return;
        }

        switch (unit->genus)
        {
            case UNIT_GENUS_PC:
                if (action->unk_18 & 0x20)
                {
                    found = NULL;
                    for (i = 0; i < 4; i++)
                    {
                        current = *(DatUnitPc**)((u8*)gBtl +
                                                  (u32)(u16)i * 4 +
                                                  0xbac);
                        if (current != NULL && current->base.unit == unit->datUnit)
                        {
                            found = current;
                            break;
                        }
                    }

                    if (found == NULL)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            group = *(DatUnitGenusBase**)((u8*)gBtl +
                                                          (u32)(u16)i * 8 +
                                                          0xbc4);
                            if (group != NULL &&
                                group->unit == unit->datUnit)
                            {
                                found = (DatUnitPc*)group;
                                break;
                            }
                        }
                    }

                    if (found != NULL)
                    {
                        ACTION_U16(found, 0xa) &= ~1;
                    }

                    datCalcClearBadStatus(unit->datUnit, 0xfff7ff7f);
                    FUN_00301690(unit->datUnit);
                    if (unit->datUnit->aiTactic == 10)
                    {
                        unit->datUnit->aiTactic = 1;
                    }
                }
                break;

            case UNIT_GENUS_EC:
                if (datCalcIsDead(unit->datUnit, 0) != 0)
                {
                    datUnitEcRemoveEnemy(gBtl->startInfo.enmUnits,
                                         action->unit->datUnit);
                }
                break;
        }

        FUN_002878d0(action->unit);
        action->unit = NULL;
        action->unk_1a &= ~1;
        FUN_001fdd40();
    }

    btlAction00299e50(action);
    FUN_002a3a90(action);
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
