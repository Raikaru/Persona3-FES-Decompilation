#include "Battle/battle.h"
#include "h_cdvd.h"
#include "Battle/btlUnit.h"
#include "Battle/btlAction.h"
#include "Battle/btlFade.h"
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
#include "Main/g_data.h"
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
void func_002e2f80(void);
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

#define BTL_PTR(addr) (*(u8**)(uintptr_t)(addr))
#define BTL_U32(addr) (*(u32*)(uintptr_t)(addr))
#define BTL_F32(addr) (*(f32*)(uintptr_t)(addr))
#define BTL_U16PTR(addr) (*(u16**)(uintptr_t)(addr))

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
extern u32 btlFade002ff310(void);

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

// FUN_0027d020 NONMATCHING
u32 btlDestroy()
{
    u16 i;
    Battle* btl;
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
            btl = gBtl;
            if (*(void**)((u8*)btl + (i & 0xffff) * 4 + 0xbac) != NULL)
            {
                datUnitDestroyGenus(*(DatUnitGenusBase**)((u8*)btl + (i & 0xffff) * 4 + 0xbac));
            }
        }

        for (i = 0; i < 3U; i++)
        {
            btl = gBtl;
            if (*(void**)((u8*)btl + (i & 0xffff) * 8 + 0xbc4) != NULL)
            {
                datUnitDestroyGenus(*(DatUnitGenusBase**)((u8*)btl + (i & 0xffff) * 8 + 0xbc4));
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

                Y_TimeLimit_0045a400();

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
// FUN_0027CE50 NONMATCHING
void func_0027ce50(void)
{
    s32 i;

    for (i = 0x1540; i < 0x15c0; i++)
    {
        btlLoadResource(i);
    }
    for (i = 0x15c0; i < 0x1600; i++)
    {
        btlLoadResource(i);
    }
}

// FUN_0027D380 NONMATCHING
u32 func_0027d380(void)
{
    BtlAction* action;
    u32 aliveEc;
    u32 alivePc;
    u32 deadCount;
    u32 heroAlive;

    *(u16*)((u8*)gBtl + 0x1c) = 0;
    aliveEc = 0;
    alivePc = 0;
    deadCount = 0;
    heroAlive = true;

    if (func_002bfc90() == 0)
    {
        *(u16*)((u8*)gBtl + 0x1c) = 2;
        return true;
    }

    for (action = gBtl->actionList.tail; action != NULL; action = action->prev)
    {
        if ((action->unk_1a & 1) != 0 && (action->unk_18 & 0x20) == 0)
        {
            if (datCalcIsDead(action->unit->datUnit, 0) == 0)
            {
                if (action->unit->genus == UNIT_GENUS_EC)
                {
                    aliveEc++;
                }
                else if (action->unit->genus == UNIT_GENUS_PC)
                {
                    alivePc++;
                }
            }
            else
            {
                if (action->unit->genus == UNIT_GENUS_PC &&
                    action->unit->datUnit->id == PC_HERO)
                {
                    heroAlive = false;
                }
                deadCount++;
            }
        }
    }

    if (heroAlive && (alivePc != 0 || deadCount == 0))
    {
        if (alivePc == 0)
        {
            *(u16*)((u8*)gBtl + 0x1c) = 3;
            return true;
        }

        if (func_002fd660() == 0)
        {
            if (aliveEc == 0)
            {
                *(u16*)((u8*)gBtl + 0x1c) = 1;
                return true;
            }
            return false;
        }

        *(u16*)((u8*)gBtl + 0x1c) = 1;
        return true;
    }

    *(u16*)((u8*)gBtl + 0x1c) = 2;
    return true;
}

// FUN_0027D560 NONMATCHING
u32 func_0027d560(void)
{
    if ((gBtl->flags & 0x800000) == 0 || func_002bfc90() == 0)
    {
        return false;
    }

    return func_00300700(gBtl->actionList.head->unit->datUnit, 0xfc8);
}

// FUN_0027D840 NONMATCHING
u32 func_0027d840(void)
{
    if ((s32)scrGetCmdTimer() < 1)
    {
        return false;
    }

    return btlFade002ff310() != 0;
}

// FUN_0027D8D0 NONMATCHING
void func_0027d8d0(void)
{
    u32 i;
    s32 level;
    f32 fatigue;
    u16 value;
    u16* range;
    DatUnit* unit;
    s16 bonus;
    s16 result;

    for (i = 1; i < 0xb; i++)
    {
        level = datGetLevel((s16)i);
        fatigue = (f32)level * 0.5f + BTL_F32(0x007cad60) * (f32)level;
        value = (u16)(s32)fatigue;
        value = (u16)(value + ((datCalcRand(8) & 0xffff) + 1));
        range = BTL_U16PTR(0x007ce490) + i * 2;
        if (range[0] <= value)
        {
            if (range[1] < value)
            {
                value = range[1];
            }
        }
        else
        {
            value = range[0];
        }

        if (datGetFlag(0xbd2) != 0)
        {
            value = (u16)((s32)value * 2);
        }

        unit = datGetUnit((s16)i);
        bonus = 0;
        if (datCalcHasSkill(unit, 0x20a) != 0)
        {
            bonus += (s16)((value * 0x14) / 100);
        }
        if (datCalcHasSkill(unit, 0x20b) != 0)
        {
            bonus += (s16)((value * 0x32) / 100);
        }
        if (datCalcHasSkill(unit, 0x20c) != 0)
        {
            bonus += (s16)value;
        }
        result = (s16)value + bonus;
        datSetFatigueCounter((s16)i, (u16)result);
        datSetOldFatigueCounter((s16)i, (u16)result);
    }
}

// FUN_0027DCD0 NONMATCHING
u32 func_0027dcd0(u32* descriptor, u32 synchronous)
{
    HCdvd* cdvd;
    const char* path;
    u8* source;
    u32 i;
    u32 size;
    void** output;

    cdvd = (HCdvd*)BTL_PTR(0x007ce4d8);
    if (cdvd == NULL)
    {
        path = (const char*)(uintptr_t)(datGetScenarioMode() != 0 ? descriptor[1] : descriptor[0]);
        cdvd = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        BTL_PTR(0x007ce4d8) = (u8*)cdvd;
    }

    if (synchronous != 0)
    {
        H_Cdvd_ReadSync(cdvd);
    }
    else if (H_Cdvd_IsFileLoaded(cdvd) == 0)
    {
        return false;
    }

    source = (u8*)cdvd->fileMemory;
    for (i = 0; ; i++)
    {
        size = *(u32*)source;
        output = (void**)(uintptr_t)descriptor[i * 2 + 2];
        if (*output == NULL)
        {
            break;
        }

        *output = D_00875D00 + BTL_U32(0x007ce4d4);
        BTL_U32(0x007ce4d4) += ((size >> 4) + ((size & 0xf) != 0)) * 0x10;
        memcpy(*output, source + 4, size);
        source += (((size + 4) >> 4) + (((size + 4) & 0xf) != 0)) * 0x10;
    }

    H_Cdvd_Destroy(cdvd);
    BTL_PTR(0x007ce4d8) = NULL;
    return true;
}

// FUN_0027DE40 NONMATCHING
u32 func_0027de40(u32 all)
{
    u32 i;
    u32 result;
    u32* descriptor;

    if (all != 0)
    {
        for (i = 0; i < 8; i++)
        {
            descriptor = (u32*)((u8*)D_00692D40 + i * 0xa8);
            func_0027dcd0(descriptor, 1);
        }
        return true;
    }

    descriptor = (u32*)((u8*)D_00692D40 + BTL_U32(0x007ce4dc) * 0xa8);
    result = func_0027dcd0(descriptor, 0);
    if (result == 0)
    {
        return false;
    }
    BTL_U32(0x007ce4dc)++;
    return BTL_U32(0x007ce4dc) == 8;
}

// FUN_0027DF20 NONMATCHING
void func_0027df20(void)
{
    u8* data;
    u8* source;
    u32 i;

    if (datGetScenarioMode() != 0)
    {
        data = BTL_PTR(0x007ce408);
        source = BTL_PTR(0x007ce40c);
        memcpy(data + 0x818, source + 0x31e, 10);
        memcpy(data + 0x822, source + 0x328, 10);
        *(u16*)(data + 0x82c) = *(u16*)(source + 0x332);
        *(u16*)(data + 0x82e) = *(u16*)(source + 0x334);
        memcpy(data + 0x830, source + 0x336, 4);
        memcpy(data + 0x834, source + 0x33a, 4);
        memcpy(data + 0x838, source + 0x33e, 4);

        for (i = 0; i < 0x17; i++)
        {
            memcpy(data + i * 10 + 0x83c, source + i * 10 + 0x342, 10);
            memcpy(D_0068F0F0 + i * 0xc + 0x888,
                   D_0068FAB0 + i * 0xc + 0xac8, 0xc);
        }

        memcpy(source + 0x95a, source, 0x10a);
        memcpy(BTL_PTR(0x007ce4c8) + 0x38, BTL_PTR(0x007ce4c4) + 0x28, 8);
        func_002b6490();

        for (i = 0; i < 0x17; i++)
        {
            memcpy(D_0068F0F0 + i * 0xc + 0x618,
                   D_0068FAB0 + i * 0xc + 0x78c, 0xc);
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

// FUN_0027E180 NONMATCHING
void func_0027e180(void)
{
    BTL_U32(0x007ce4d4) = 0;
    BTL_PTR(0x007ce4d8) = NULL;
    BTL_U32(0x007ce4dc) = 0;
    func_0027de40(1);
    func_0027df20();
    func_002bc6d0();
    func_002dd9b0();
}

// FUN_0027E1D0 NONMATCHING
void* func_0027e1d0(KwlnTask* task)
{
    u32 result;

    result = func_0027dcd0((u32*)((u8*)D_00692D40 + BTL_U32(0x007ce4dc) * 0xa8), 0);
    if (result == 0)
    {
        return KWLNTASK_CONTINUE;
    }

    BTL_U32(0x007ce4dc)++;
    if (BTL_U32(0x007ce4dc) != 8)
    {
        return KWLNTASK_CONTINUE;
    }

    func_0027df20();
    return KWLNTASK_STOP;
}

// FUN_0027E270 NONMATCHING
KwlnTask* func_0027e270(KwlnTask* parent)
{
    BTL_U32(0x007ce4d4) = 0;
    BTL_PTR(0x007ce4d8) = NULL;
    BTL_U32(0x007ce4dc) = 0;
    return kwlnTaskCreate(parent, D_00693280, 10, func_0027e1d0, NULL, NULL);
}

// FUN_0027E2C0 NONMATCHING
KwlnTask* func_0027e2c0(KwlnTask* parent)
{
    BTL_U32(0x007ce4d4) = 0;
    BTL_PTR(0x007ce4d8) = NULL;
    BTL_U32(0x007ce4dc) = 0;
    return kwlnTaskCreate(parent, D_00693280, 10, func_0027e1d0, NULL, NULL);
}

// FUN_0027E310 NONMATCHING
BtlPacket* func_0027e310(u64 uid, u64 mask)
{
    BtlPacket* packet;
    u32 i;

    for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
    {
        packet = gBtl->packetLists[i].head;
        while (packet != NULL)
        {
            if (uid == (packet->uid & mask) &&
                (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
            {
                return packet;
            }
            packet = packet->next;
        }
    }

    return NULL;
}
