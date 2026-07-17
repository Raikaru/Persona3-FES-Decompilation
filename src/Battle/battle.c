#include "Battle/battle.h"
#include "h_cdvd.h"
#include "Battle/btlUnit.h"
#include "Battle/btlAction.h"
#include "Battle/btlFade.h"
#include "Battle/btlVoice.h"
#include "Kosaka/k_data.h"
#include "Kosaka/k_misc.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Script/scrTraceCode.h"
#include "Script/scrScriptProcess.h"
#include "Yajima/y_timeLimit.h"
#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Panel/bp_root.h"
#include "Main/admini.h"
#define datGetLevel datGetLevel_u8
#define datSetFatigueCounter datSetFatigueCounter_u16
#define datSetOldFatigueCounter datSetOldFatigueCounter_u16
#include "Main/g_data.h"
#undef datGetLevel
#undef datSetFatigueCounter
#undef datSetOldFatigueCounter
extern s32 datGetLevel(s16 pcId);
extern void datSetFatigueCounter(s16 pcId, s64 fatigueCounter);
extern void datSetOldFatigueCounter(s16 pcId, s64 fatigueCounter);
#include "g_flags.h"
#include "temporary.h"

#define BTL_CHAR_RESID_BASE 0x100
#define BTL_CHAR_RESID_MAX  0x200

static u64 sUID = 1;                             // 007cc510
static u16 sCurrCharResId = BTL_CHAR_RESID_BASE; // 007cc518

BtlEncountTable* gEncountTbl; // 007ce4a8
static u32 sIsDead;           // 007ce3f0
Battle* gBtl;                 // 007ce3ec. NULL when not in a battle

u32 btlDestroy();
void btlMain0029dfb0(void);
void btlMain0029e370(void);
void func_002879f0(void);
void func_002a4c20(void);
void func_002bb770(void);
void func_002bf980(void);
void func_002db980(void);
void func_002dcd20(void);
void func_002f8790(void);
void func_001f1c20(void* param);
void itfMesMngDestroyHandle(s32 mesHandleIdx);
extern u8 D_00875D00[];
extern const u8 D_00692D40[];
extern const char D_00693280[];
extern u8 D_0068F0F0[];
extern u8 D_0068FA68[];
extern u8 D_0068FA80[];
extern u8 D_0068FAB0[];
extern u32 DAT_007ce4d4;
extern HCdvd* DAT_007ce4d8;
extern u32 DAT_007ce4dc;
extern f32 DAT_007cad60;
extern u16* DAT_007ce490;
extern u8* DAT_007ce408;
extern u8* DAT_007ce40c;
extern u8* DAT_007ce4c4;
extern u8* DAT_007ce4c8;


extern u32 func_0027dcd0(u32* descriptor, u32 synchronous);
extern void func_0027df20(void);
extern void* func_0027e1d0(KwlnTask* task);
extern u32 func_002bfc90(void);
extern u32 func_002fd660(void);
extern u32 func_00300700(DatUnit* unit, u32 id);
extern void func_002b6490(void);
extern void func_002bc6d0(void);
extern void func_002dd9b0(void);
extern void func_00177270(void);

// FUN_0027cb80
u64 btlGetUID()
{
    sUID++;

    if (sUID >= BTL_UIDMAX)
    {
        sUID = 1;
    }

    return sUID;
}

// FUN_0027cbd0
u16 btlFindFreeCharResId()
{
    do
    {
        if (++sCurrCharResId >= BTL_CHAR_RESID_MAX)
        {
            sCurrCharResId = BTL_CHAR_RESID_BASE;
        }
    } while (MT_Scene_GetRes(RESRC_MAKE_TYPEID(sCurrCharResId, RESRC_TYPE_MODELCHAR)) != NULL);

    return sCurrCharResId;
}

// FUN_0027cc30
void* btlUpdateTask(KwlnTask* btlTask)
{
    if (gBtl->flags & BTL_FLAG_ACTIVE)
    {
        kwlnSetDrawLayer(2);
        btl002d1ac0();
        btlPacketUpdateList(BTLPACKET_TYPE_0);
        btlMainUpdateState();
        btlActionUpdateAll();
        btlOrder0029ae40();
        btlMain0029e420();
        btlUnit00286540();
        btlMsg002db960();
        btlFormation002bf990();
        btlCameraMain();
        btlVoice002e2f20();
        btlSound002dcc40();
        btlPacketUpdateList(BTLPACKET_TYPE_1);
    }
    else
    {
        btlStop();
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0027ccf0
void* btlUpdateDraw3DTask(KwlnTask* btlDraw3DTask)
{
    if (kwlnCameraBeginUpdate() != NULL)
    {
        kwlnSetDrawLayer(2);
        btlPacketUpdateList(BTLPACKET_TYPE_3D);
        btlUnitDrawAll();
        btlEffectDrawAll();
        btlCameraDebugDraw();
        kwlnCameraEndUpdate();
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0027cd70
void* btlUpdateDraw3DFrontTask(KwlnTask* btlDraw3DFrontTask)
{
    kwlnSetDrawLayer(3);
    btlAction002891e0();

    return KWLNTASK_CONTINUE;
}

// FUN_0027cda0
void* btlUpdateDraw2DTask(KwlnTask* btlDraw2DTask)
{
    kwlnSetDrawLayer(5);
    btlPacketUpdateList(BTLPACKET_TYPE_2D);
    btlMain0029e4b0();
    btlFormation002bf9a0();

    return KWLNTASK_CONTINUE;
}

// FUN_0027cdf0
void btlDestroyTask(KwlnTask* btlTask)
{
    btlDestroy();
}

// FUN_0027ced0
void btlCreate()
{
    s32 i;

    sUID = 1;
    sCurrCharResId = BTL_CHAR_RESID_BASE;

    gBtl = RwMalloc(sizeof(Battle), rwMEMHINTDUR_GLOBAL);
    memset(gBtl, 0, sizeof(Battle));

    gBtl->mesHandleIdx = itfMesMngInitialize(gBtlMessageBmd);

    for (i = 0x1540; i <= 0x15bf; i++)
    {
        btlLoadResource(i);
    }

    for (i = 0x15c0; i <= 0x15ff; i++)
    {
        btlLoadResource(i);
    }

    btlTarget002d3d70();
    btlPacket0027edf0();
    btlCamera002a4a70();
    btlSound002dcbc0();
    btlVoice002e2f30();
    btlFormation002bb760();
    btlOrderInit();
    btlMainSetStateNon();
    btlMsg002db8d0();
    btlFormation002bf970();
    datSetFlag(0x1407, true);

    gBtl->flags |= 0x481077c;
}

// FUN_0027d020
u32 btlDestroy()
{
    u8* battleBase;
    u16 i;
    DatUnitGenusBase* genus;
    void* unkTask;

    btlActionDestroyAll();
    func_002879f0();
    btlMain0029e370();
    btlMain0029dfb0();
    func_002bb770();
    func_002e2f80();
    func_002dcd20();
    func_002a4c20();
    func_002db980();
    func_002bf980();
    func_002f8790();
    btlPacketDestroyAll();
    itfMesMngDestroyHandle(gBtl->mesHandleIdx);
    datSetFlag(0x1407, false);

    unkTask = *(void**)((u8*)gBtl + 0xd28);
    if (unkTask != NULL)
    {
        func_001f1c20(unkTask);
    }

    if (gBtl->flags & BTL_FLAG_UNK8000)
    {
        for (i = 0; i < UNIT_GENUS_MAX; i++)
        {
            battleBase = (u8*)gBtl;
            genus = *(DatUnitGenusBase**)(battleBase + (u32)(u16)i * 4 +
                                          0xbac);
            if (genus != NULL)
            {
                datUnitDestroyGenus(genus);
            }
        }

        for (i = 0; i < 3U; i++)
        {
            battleBase = (u8*)gBtl;
            genus = *(DatUnitGenusBase**)(battleBase + (u32)(u16)i * 8 +
                                          0xbc4);
            if (genus != NULL)
            {
                datUnitDestroyGenus(genus);
            }
        }
        datUnitDestroyGenus(&gBtl->startInfo.enmUnits->base);
    }

    if (kwlnTaskGetTaskByName("battle") != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gBtl->btlTask);
    }

    RwFree(gBtl);
    gBtl = NULL;

    return false;
}

// FUN_0027ce10
void btlStop()
{
    if (kwlnTaskGetTaskByName("battle") != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gBtl->btlTask);
    }
}

// FUN_0027d1d0
KwlnTask* btlStart(BtlStartInfo* startInfo)
{
    KwlnTask* btlTask;

    btlCreate();

    gBtl->btlTask = kwlnTaskCreate(NULL,
                                   "battle",
                                   10,
                                   btlUpdateTask,
                                   btlDestroyTask,
                                   NULL);

    kwlnTaskCreate(gBtl->btlTask,
                   "battle_draw_3d",
                   2081,
                   btlUpdateDraw3DTask,
                   NULL,
                   NULL);
    kwlnTaskCreate(gBtl->btlTask,
                   "battle_draw_3d_front",
                   4169,
                   btlUpdateDraw3DFrontTask,
                   NULL,
                   NULL);
    kwlnTaskCreate(gBtl->btlTask,
                   "battle_draw_2d",
                   4207,
                   btlUpdateDraw2DTask,
                   NULL,
                   NULL);

    gBtl->btlPanelTask = bpRootCreateTasks(gBtl->btlTask);
    bpRoot001ff350();

    btlTask = gBtl->btlTask;

    if (startInfo != NULL)
    {
        gBtl->hasNoStartInfo = false;

        memcpy(&gBtl->startInfo, startInfo, sizeof(BtlStartInfo));

        gBtl->fldMajorId = gBtl->startInfo.fldMajorId;
        gBtl->fldMinorId = gBtl->startInfo.fldMinorId;

        btlMainSetState(BTL_STATE_INIT);
    }
    else
    {
        gBtl->hasNoStartInfo = true;

        if (!datGetFlag(FLG_BATTLE_MC))
        {
            btlMainSetState(BTL_STATE_TEST);
        }
        else
        {
            btlMainSetState(BTL_STATE_MC);
        }
    }

    gBtl->flags |= BTL_FLAG_ACTIVE;

    return btlTask;
}

// FUN_0027d5e0
u32 btlScrCmd_CALL_BATTLE()
{
    BtlEncountTable* encount;
    BtlStartInfo startInfo;
    u16 i;
    u16 currPcId;
    u16 encountId;

    btlFadeCreateTask(1);

    encountId = scrGetIntPara(0);
    encount = &gEncountTbl[encountId];

    memset(&startInfo, 0, sizeof(BtlStartInfo));

    startInfo.partyUnits[0] = datUnitCreatePc(PC_HERO);
    for (i = 0; i < 4; i++)
    {
        currPcId = datGetPartyId(i);
        if (currPcId != PC_NONE)
        {
            startInfo.partyUnits[i + 1] = datUnitCreatePc(currPcId);
        }
    }

    startInfo.enmUnits = datUnitCreateEc(encountId);
    
    if (encount->fldMajorId == 0 && encount->fldMinorId == 0)
    {
        startInfo.fldMajorId = 221;
        startInfo.fldMinorId = 1;
    }
    else
    {
        startInfo.fldMajorId = encount->fldMajorId;
        startInfo.fldMinorId = encount->fldMinorId;
    }

    adminiChangeSeq(ADMINI_SEQ_BATTLE, &startInfo, sizeof(BtlStartInfo), false);

    return true;
}

// FUN_0027d730
#pragma optimization_level 1
u32 btlScrCmd_CHK_HERO_DIED_TARTAROS()
{
    u32 scrSize;
    if ((s32)scrGetCmdTimer() > 10)
    {
        if (gBtl != NULL)
        {
            sIsDead = false;
            return false;
        }

        if (!sIsDead)
        {
            if (datCalcIsDead(datGetUnit(PC_HERO), 0))
            {
                datSetFlag(FLG_HERO_DIED, true);

                Y_TimeLimit_Stop();

                scrCreateTaskFromScriptMemory((scrSize = gFldScrSize, 10), gFldScrMemory, scrSize, FLDSCR_DIED_IN_TARTAROS);
                K_Misc_CreateScrShutdownTask(scrGetCurrent()->task);

                sIsDead = true;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}
#pragma optimization_level 2

// FUN_0027d810
u32 btlScrCommand_ENCOUNT_FADE()
{
    btlFadeCreateTask(1);

    return true;
}

// FUN_0027d880
KwlnTask* btlGetTask()
{
    if (gBtl != NULL)
    {
        return gBtl->btlTask;
    }

    return NULL;
}

// FUN_0027d8b0
void btl0027d8b0()
{
    gBtl->flags |= BTL_FLAG_UNK8000;
}

// FUN_0027dbe0
u32 btlUpdateSetFlagsPacket(void* work)
{
    BtlBattleFlagPacket* packet;

    packet = (BtlBattleFlagPacket*)work;

    gBtl->flags |= packet->flags;

    return true;
}

// FUN_0027dc00
BtlPacket* btlCreateSetFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = btlPacketCreate(BTLBATTLE_PACKET_SETFLAGS, sizeof(BtlBattleFlagPacket));

    packet->updateFunc = btlUpdateSetFlagsPacket;

    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}

// FUN_0027dc50
#pragma optimization_level 1
u32 btlUpdateRemoveFlagsPacket(void* work)
{
    BtlBattleFlagPacket* packet;
    Battle* btl;

    btl = gBtl;
    packet = (BtlBattleFlagPacket*)work;

    btl->flags &= ~packet->flags;

    return true;
}
#pragma optimization_level 2

// FUN_0027dc80
BtlPacket* btlCreateRemoveFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = btlPacketCreate(BTLBATTLE_PACKET_REMOVEFLAGS, sizeof(BtlBattleFlagPacket));

    packet->updateFunc = btlUpdateRemoveFlagsPacket;

    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}
// FUN_0027CE50
void func_0027ce50(void)
{
    s32 i;

    for (i = 0x1540; i <= 0x15bf; i++)
    {
        btlLoadResource(i);
    }
    for (i = 0x15c0; i <= 0x15ff; i++)
    {
        btlLoadResource(i);
    }
}

// FUN_0027D380
u32 func_0027d380(void)
{
    BtlAction* action;
    BtlUnit* unit;
    u8 genus;
    s32 alivePc;
    s32 aliveEc;
    s32 deadCount;
    s32 heroAlive;

    *(u16*)((u8*)gBtl + 0x1c) = 0;
    alivePc = 0;
    aliveEc = 0;
    deadCount = 0;
    heroAlive = 1;

    if (func_002bfc90() == 0)
    {
        *(u16*)((u8*)gBtl + 0x1c) = 2;
        return true;
    }

    for (action = gBtl->actionList.tail; action != NULL; action = action->prev)
    {
        if ((action->unk_1a & 1) != 0 && (action->unk_18 & 0x20) == 0)
        {
            unit = action->unit;
            if (datCalcIsDead(unit->datUnit, 0) != 0)
            {
                if (unit->genus == UNIT_GENUS_PC && unit->datUnit->id == PC_HERO)
                {
                    heroAlive = 0;
                }
                deadCount++;
            }
            else
            {
                genus = unit->genus;
                switch (genus)
                {
                case UNIT_GENUS_PC:
                    alivePc++;
                    break;
                case UNIT_GENUS_EC:
                    aliveEc++;
                    break;
                }
            }
        }
    }
    if (heroAlive == 0 || (alivePc == 0 && deadCount != 0))
    {
        *(u16*)((u8*)gBtl + 0x1c) = 2;
        return true;
    }

    if (alivePc == 0)
    {
        *(u16*)((u8*)gBtl + 0x1c) = 3;
        return true;
    }

    if (func_002fd660() != 0)
    {
        *(u16*)((u8*)gBtl + 0x1c) = 1;
        return true;
    }

    if (aliveEc == 0)
    {
        *(u16*)((u8*)gBtl + 0x1c) = 1;
        return true;
    }

    return false;
}

// FUN_0027D560
u32 func_0027d560(void)
{
    if ((gBtl->flags & 0x800000) != 0)
    {
        goto flag_set;
    }
    return false;

flag_set:
    if (func_002bfc90() != 0)
    {
        goto can_check;
    }
    return false;

can_check:
    return func_00300700(gBtl->actionList.head->unit->datUnit, 0xfc8);
}

// FUN_0027D840
u32 func_0027d840(void)
{
    if ((s32)scrGetCmdTimer() > 0)
    {
        return btlFadeAllowsBattleTransition() != 0;
    }
    return false;
}

// FUN_0027D8D0
void func_0027d8d0(void)
{
    DatUnit* unit;
    s32 i;
    s32 bonus;
    s32 value;
    s64 result;
    u16 temp;
    u16 lower;
    u16 upper;
    u32 random;
    u8* rangeBase;
    s32 index;

    for (i = 1; i < 0xb; i++)
    {
        {
            f32 levelFloat;
            f32 fatigue;

            levelFloat = (f32)(u32)datGetLevel((s16)i);
            fatigue = DAT_007cad60 * levelFloat + 0.5f * levelFloat;
            temp = (u16)fatigue;
            value = temp;
        }
        random = datCalcRand(8) & 0xffff;
        random = (random + 1) & 0xffff;
        value = (value + random) & 0xffff;
        rangeBase = (u8*)DAT_007ce490;
        lower = *(u16*)(rangeBase + (u32)i * 4);
        upper = *(u16*)(rangeBase + (u32)i * 4 + 2);
        if (value < lower)
        {
            value = lower;
        }
        else if (upper < value)
        {
            value = upper;
        }

        if (datGetFlag(0xbd2) != 0)
        {
            f32 fatigue;

            fatigue = 2.0f;
            fatigue *= (f32)(u32)value;
            temp = (u16)fatigue;
            value = temp;
        }

        unit = datGetUnit((s16)i);
        bonus = 0;
        if (datCalcHasSkill(unit, 0x20a) != 0)
        {
            bonus += ((value & 0xffff) * 0x14) / 100;
        }
        if (datCalcHasSkill(unit, 0x20b) != 0)
        {
            bonus += ((value & 0xffff) * 0x32) / 100;
        }
        if (datCalcHasSkill(unit, 0x20c) != 0)
        {
            bonus += ((value & 0xffff) * 0x64) / 100;
        }

        result = (s64)(s16)((value + (bonus & 0xffff)) & 0xffff);
        datSetFatigueCounter((s16)i, result);
        datSetOldFatigueCounter((s16)i, result);
    }
}
// FUN_0027DCD0
u32 func_0027dcd0(u32* descriptor, u32 synchronous)
{
    u8* source;
    u32 i;
    u32 size;
    void** output;

    if (DAT_007ce4d8 == NULL)
    {
        if (datGetScenarioMode() != 0)
        {
            DAT_007ce4d8 = H_Cdvd_Request((const char*)(uintptr_t)descriptor[1], HCDVD_FILENORMAL);
        }
        else
        {
            DAT_007ce4d8 = H_Cdvd_Request((const char*)(uintptr_t)descriptor[0], HCDVD_FILENORMAL);
        }
    }

    if (synchronous != 0)
    {
        H_Cdvd_ReadSync(DAT_007ce4d8);
    }
    else if (H_Cdvd_IsFileLoaded(DAT_007ce4d8) == 0)
    {
        return false;
    }

    source = (u8*)DAT_007ce4d8->fileMemory;
    i = 0;
    goto check_output;

process_output:
    size = *(u32*)source;
    *output = D_00875D00 + DAT_007ce4d4;
    DAT_007ce4d4 += ((size >> 4) + ((size & 0xf) != 0)) * 0x10;
    memcpy(*output, source + 4, size);
    source += (((size + 4) >> 4) + (((size + 4) & 0xf) != 0)) * 0x10;
    i++;

check_output:
    output = *(void***)((u8*)descriptor + i * 8 + 8);
    if (output != NULL)
    {
        goto process_output;
    }

    H_Cdvd_Destroy(DAT_007ce4d8);
    DAT_007ce4d8 = NULL;
    return true;
}

// FUN_0027DE40
u32 func_0027de40(u32 all)
{
    s32 temp_3;
    u32 i;

    if (all != 0)
    {
        i = 0;
        while (i < 8)
        {
            func_0027dcd0((u32*)((u8*)D_00692D40 + i * 0xa8), 1);
            i++;
        }
        return true;
    }

    if (func_0027dcd0((u32*)((u8*)D_00692D40 + DAT_007ce4dc * 0xa8), 0) != 0)
    {
        temp_3 = DAT_007ce4dc + 1;
        DAT_007ce4dc = temp_3;
        if (temp_3 == 8)
        {
            return true;
        }
    }

    return false;
}

// FUN_0027DF20
void func_0027df20(void)
{
    u32 i;

    if (datGetScenarioMode() != 0)
    {
        memcpy(DAT_007ce408 + 0x818, DAT_007ce40c + 0x31e, 10);
        memcpy(DAT_007ce408 + 0x822, DAT_007ce40c + 0x328, 10);
        *(u16*)(DAT_007ce408 + 0x82c) = *(u16*)(DAT_007ce40c + 0x332);
        *(u16*)(DAT_007ce408 + 0x82e) = *(s16*)(DAT_007ce40c + 0x334);
        memcpy(DAT_007ce408 + 0x830, DAT_007ce40c + 0x336, 4);
        memcpy(DAT_007ce408 + 0x834, DAT_007ce40c + 0x33a, 4);
        memcpy(DAT_007ce408 + 0x838, DAT_007ce40c + 0x33e, 4);

        for (i = 0; i < 0x17; i++)
        {
            memcpy(DAT_007ce408 + i * 10 + 0x83c, DAT_007ce40c + i * 10 + 0x342, 10);
            memcpy(D_0068F0F0 + i * 0xc + 0x888,
                   D_0068FAB0 + i * 0xc + 0xac8, 0xc);
        }

        memcpy(DAT_007ce40c + 0x95a, DAT_007ce40c, 0x10a);
        memcpy(DAT_007ce4c8 + 0x38, DAT_007ce4c4 + 0x28, 8);
        func_002b6490();

        for (i = 0; i < 0x17; i++)
        {
            memcpy(D_0068FAB0 + i * 0xc + 0x78c,
                   D_0068F0F0 + i * 0xc + 0x618, 0xc);
        }
        memcpy(D_0068FA68, D_0068FA80, 0xc);
        for (i = 0; i < 0x12; i++)
        {
            memcpy(D_0068FAB0 + i * 0x114 + 0xf0,
                   D_0068FAB0 + i * 0x114 + 0x108, 0xc);
        }
    }

    func_00177270();
}

// FUN_0027E180
void func_0027e180(void)
{
    DAT_007ce4d4 = 0;
    DAT_007ce4d8 = NULL;
    DAT_007ce4dc = 0;
    func_0027de40(1);
    func_0027df20();
    func_002bc6d0();
    func_002dd9b0();
}

// FUN_0027E1D0
void* func_0027e1d0(KwlnTask* task)
{
    s32 temp_3;
    s32 var_2;

    if ((func_0027dcd0((u32*)((u8*)D_00692D40 + DAT_007ce4dc * 0xa8), 0) != 0) &&
        (temp_3 = DAT_007ce4dc + 1, DAT_007ce4dc = temp_3, temp_3 == 8))
    {
        var_2 = 1;
    }
    else
    {
        var_2 = 0;
    }

    if (var_2 != 0)
    {
        func_0027df20();
        return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0027E270
KwlnTask* func_0027e270(KwlnTask* parent)
{
    DAT_007ce4d4 = 0;
    DAT_007ce4d8 = NULL;
    DAT_007ce4dc = 0;
    return kwlnTaskCreate(parent, D_00693280, 10, func_0027e1d0, NULL, NULL);
}

// FUN_0027E2C0
KwlnTask* func_0027e2c0(KwlnTask* parent)
{
    DAT_007ce4d4 = 0;
    DAT_007ce4d8 = NULL;
    DAT_007ce4dc = 0;
    return kwlnTaskCreate(parent, D_00693280, 10, func_0027e1d0, NULL, NULL);
}

// FUN_0027E310
BtlPacket* func_0027e310(u64 uid, u64 mask)
{
    BtlPacket* packet;
    Battle* btl;
    u32 i;

    i = 0;
    btl = gBtl;
    while (i < BTLPACKET_TYPE_MAX)
    {
        packet = *(BtlPacket**)((u8*)btl + i * sizeof(BtlPacketList) + 0x174);
        while (packet != NULL)
        {
            if (uid == (packet->uid & mask) &&
                (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
            {
                return packet;
            }
            packet = packet->next;
        }
        i++;
    }

    return NULL;
}
