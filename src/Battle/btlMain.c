#include "Battle/battle.h"
#include "Battle/btlFade.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Scene/mt_scene.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_fade.h"
#include "temporary.h"

void btlSound002dced0(u16 param_1);
void btlSound002dcf80(s32 param_1, u16 param_2);
void btlBoss002f6e00();
void btlFade002ff2d0(u16 param_1);
u32 btl002facc0();
void datAddBattleCount(s32 amount);
void scrClearTextBox(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
void FUN_001f1b60(void* param_1);
u32 FUN_001f1b00(void* param_1);
u32 FUN_001f1b40(void* param_1);
void FUN_001f1b20(void* param_1);
void FUN_001f1c20(void* param_1);
u32 FUN_001f1f40();
u32 FUN_002dba60();
void FUN_002dcf10();
void FUN_002fb690();
void FUN_0029e3c0();
void FUN_002bfc50(s32 param_1);

u32 FUN_001fecc0();
u32 FUN_002e42c0();
u32 FUN_002e4290(BtlAction* action);
void FUN_0029b040();
void FUN_001fdd20();
void FUN_003c7b90();
u32 FUN_003c7850();
u32 FUN_003c7610();
void FUN_001ff3b0();
void btlMainInitStateNon(BtlStateWork* work);
u32 btlMainUpdateStateNon(BtlStateWork* work);
void btlMainInitStateInit(BtlStateWork* work);
u32 btlMainUpdateStateInit(BtlStateWork* work);
void btlMainInitStateSceneSet(BtlStateWork* work);
u32 btlMainUpdateStateSceneSet(BtlStateWork* work);
void btlMainInitStateUnitCreate(BtlStateWork* work);
u32 btlMainUpdateStateUnitCreate(BtlStateWork* work);
void btlMainInitStateUnitLoad(BtlStateWork* work);
u32 btlMainUpdateStateUnitLoad(BtlStateWork* work);
void btlMainInitStateStart(BtlStateWork* work);
u32 btlMainUpdateStateStart(BtlStateWork* work);
void btlMainInitStateAction(BtlStateWork* work);
u32 btlMainUpdateStateAction(BtlStateWork* work);
void btlMainInitStateRevivalMes(BtlStateWork* work);
u32 btlMainUpdateStateRevivalMes(BtlStateWork* work);
void btlMainInitStateRevival(BtlStateWork* work);
u32 btlMainUpdateStateRevival(BtlStateWork* work);
void btlMainInitStateWin(BtlStateWork* work);
u32 btlMainUpdateStateWin(BtlStateWork* work);
void btlMainInitStateEnemyDead(BtlStateWork* work);
u32 btlMainUpdateStateEnemyDead(BtlStateWork* work);
void btlMainInitStateCondition(BtlStateWork* work);
u32 btlMainUpdateStateCondition(BtlStateWork* work);
void btlMainInitStateLose(BtlStateWork* work);
u32 btlMainUpdateStateLose(BtlStateWork* work);
void btlMainInitStateFadeOut(BtlStateWork* work);
u32 btlMainUpdateStateFadeOut(BtlStateWork* work);
void btlMainInitStateEnd(BtlStateWork* work);
u32 btlMainUpdateStateEnd(BtlStateWork* work);
void btlMainInitStateResult(BtlStateWork* work);
u32 btlMainUpdateStateResult(BtlStateWork* work);
void btlMainInitStateExit(BtlStateWork* work);
u32 btlMainUpdateStateExit(BtlStateWork* work);
void btlMainInitStateTest(BtlStateWork* work);
u32 btlMainUpdateStateTest(BtlStateWork* work);
void btlMainInitStateMc(BtlStateWork* work);
u32 btlMainUpdateStateMc(BtlStateWork* work);

// 12 bytes
typedef struct 
{
    void (*init)(BtlStateWork* work);  // 0x00
    u32 (*update)(BtlStateWork* work); // 0x04
    const char* name;                  // 0x08
} BtlStateEntry;

// 00693760
static const BtlStateEntry sBtlStateTable[] =
{
    {NULL, NULL, "NULL"},
    {btlMainInitStateNon, btlMainUpdateStateNon, "NON"},
    {btlMainInitStateInit, btlMainUpdateStateInit, "INIT"},
    {btlMainInitStateSceneSet, btlMainUpdateStateSceneSet, "SCENE_SET"},
    {btlMainInitStateUnitCreate, btlMainUpdateStateUnitCreate, "UNIT_CREATE"},
    {btlMainInitStateUnitLoad, btlMainUpdateStateUnitLoad, "UNIT_LOAD"},
    {btlMainInitStateStart, btlMainUpdateStateStart, "START"},
    {btlMainInitStateAction, btlMainUpdateStateAction, "ACTION"},
    {btlMainInitStateRevivalMes, btlMainUpdateStateRevivalMes, "REVIVAL_MES"},
    {btlMainInitStateRevival, btlMainUpdateStateRevival, "REVIVAL"},
    {btlMainInitStateWin, btlMainUpdateStateWin, "WIN"},
    {btlMainInitStateEnemyDead, btlMainUpdateStateEnemyDead, "ENEMY DEAD"},
    {btlMainInitStateCondition, btlMainUpdateStateCondition, "CONDITION"},
    {btlMainInitStateLose, btlMainUpdateStateLose, "LOSE"},
    {btlMainInitStateFadeOut, btlMainUpdateStateFadeOut, "FADE_OUT"},
    {btlMainInitStateEnd, btlMainUpdateStateEnd, "END"},
    {btlMainInitStateResult, btlMainUpdateStateResult, "RESULT"},
    {btlMainInitStateExit, btlMainUpdateStateExit, "EXIT"},
    {btlMainInitStateTest, btlMainUpdateStateTest, "TEST"},
    {btlMainInitStateMc, btlMainUpdateStateMc, "MC"}
};

// FUN_0029b0e0
void btlMainInitStateNon(BtlStateWork* work)
{
    // nothing
}
// FUN_0029b0f0
u32 btlMainUpdateStateNon(BtlStateWork* work)
{
    // OK
    return BTL_STATE_NULL;
}

// FUN_0029b100
void btlMainInitStateInit(BtlStateWork* work)
{
    btlSound002dcf80(3, 0);
    btlSound002dcf80(4, 0);
    btlSound002dced0(0);
    btlBoss002f6e00();
    datAddBattleCount(1);
}
// FUN_0029b160
u32 btlMainUpdateStateInit(BtlStateWork* work)
{
    // OK
    return BTL_STATE_SCENESET;
}

// FUN_0029b170
void btlMainInitStateSceneSet(BtlStateWork* work)
{
    btlMainLoadScene();
}
// FUN_0029b190
u32 btlMainUpdateStateSceneSet(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029b280
void btlMainInitStateUnitCreate(BtlStateWork* work)
{
    // TODO
}
// FUN_0029b760
u32 btlMainUpdateStateUnitCreate(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029be40
void btlMainInitStateUnitLoad(BtlStateWork* work)
{
    // TODO
}
// FUN_0029c110
u32 btlMainUpdateStateUnitLoad(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029c250
void btlMainInitStateStart(BtlStateWork* work)
{
    if (gBtl->unk_10 & 1)
    {
        btlFade002ff2d0(3);
        btl002facc0();
    }
}
// FUN_0029c290
u32 btlMainUpdateStateStart(BtlStateWork* work)
{
    u32 ret;

    if (FUN_001fecc0() == 0 && btlPacketCount() == 0 && FUN_002e42c0() == 0)
    {
        if (FUN_002e4290(gBtl->actionList.head) != 0)
        {
            ret = BTL_STATE_NULL;
        }
        else
        {
            FUN_0029b040();
            FUN_001fdd20();
            gBtl->flags |= 0x800;
            ret = BTL_STATE_ACTION;
        }
    }
    else
    {
        ret = BTL_STATE_NULL;
    }

    return ret;
}

// FUN_0029c330
void btlMainInitStateAction(BtlStateWork* work)
{
    // nothing
}
// FUN_0029c340
u32 btlMainUpdateStateAction(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029c5d0
void btlMainInitStateRevivalMes(BtlStateWork* work)
{
    // TODO
}
// FUN_0029c680
u32 btlMainUpdateStateRevivalMes(BtlStateWork* work)
{
    u32 ret;

    FUN_003c7b90();
    if (FUN_003c7850() == 0)
    {
        if (FUN_003c7610() == 0)
        {
            FUN_001ff3b0();
            ret = BTL_STATE_REVIVAL;
        }
        else
        {
            gBtl->flags &= ~0x800000;
            ret = BTL_STATE_ACTION;
        }
    }
    else
    {
        ret = BTL_STATE_NULL;
    }

    return ret;
}

// FUN_0029c700
void btlMainInitStateRevival(BtlStateWork* work)
{
    // TODO
}
// FUN_0029ccd0
u32 btlMainUpdateStateRevival(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029ce90
void btlMainInitStateWin(BtlStateWork* work)
{
    // TODO
}
// FUN_0029d0d0
u32 btlMainUpdateStateWin(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029cde0
void btlMainInitStateEnemyDead(BtlStateWork* work)
{
    FUN_002fb690();
    gBtl->flags |= 0x80000;
}
// FUN_0029ce20
u32 btlMainUpdateStateEnemyDead(BtlStateWork* work)
{
    // TODO

    return BTL_STATE_NULL;
}

// FUN_0029d1f0
void btlMainInitStateCondition(BtlStateWork* work)
{
    // TODO
}
// FUN_0029d6e0
u32 btlMainUpdateStateCondition(BtlStateWork* work)
{
    if (btlPacketCount() != 0)
    {
        goto returnNull;
    }

    return BTL_STATE_FADEOUT;

returnNull:
    return BTL_STATE_NULL;
}

// FUN_0029d720
void btlMainInitStateLose(BtlStateWork* work)
{
    // nothing
}
// FUN_0029d730
u32 btlMainUpdateStateLose(BtlStateWork* work)
{
    if (work->stateTimer >= 31)
    {
        return BTL_STATE_FADEOUT;
    }

    return BTL_STATE_NULL;
}

// FUN_0029d760
void btlMainInitStateFadeOut(BtlStateWork* work)
{
    gBtl->flags &= ~0x800;

    if (*(u16*)((u8*)gBtl + 0x1c) != 2)
    {
        if (gBtl->flags & 0x400)
        {
            FUN_001f1b20(*(void**)((u8*)gBtl + 0xd28));
        }
    }
    else
    {
        H_Fade_FadeOut();
        H_Fade_SetType(HFADE_CUSTOM);
        H_Fade_SetCustomColor(0, 0, 0);
        H_Fade_SetDuration(30);
    }
}
// FUN_0029d800
u32 btlMainUpdateStateFadeOut(BtlStateWork* work)
{
    if (*(u16*)((u8*)gBtl + 0x1c) != 2)
    {
        if (FUN_001f1b40(*(void**)((u8*)gBtl + 0xd28)) == 0)
        {
            return BTL_STATE_END;
        }
    }
    else if (H_Fade_IsFadeOutDone() == 1)
    {
        return BTL_STATE_END;
    }

    return BTL_STATE_NULL;
}

// FUN_0029d870
void btlMainInitStateEnd(BtlStateWork* work)
{
    // TODO
}
// FUN_0029db60
u32 btlMainUpdateStateEnd(BtlStateWork* work)
{
    if (gBtl->actionList.tail != NULL)
    {
        return BTL_STATE_NULL;
    }

    FUN_0029e3c0();
    kwlnTaskDestroyWithHierarchy(gBtl->btlPanelTask);
    FUN_002bfc50(1);

    if ((gBtl->flags & 0x400) && *(u16*)((u8*)gBtl + 0x1c) != 2)
    {
        return BTL_STATE_RESULT;
    }

    return BTL_STATE_EXIT;
}

// FUN_0029dbf0
void btlMainInitStateResult(BtlStateWork* work)
{
    FUN_001f1b60(*(void**)((u8*)gBtl + 0xd28));
}
// FUN_0029dc20
u32 btlMainUpdateStateResult(BtlStateWork* work)
{
    if (!(gBtl->flags & BTL_FLAG_EXIT) && FUN_001f1f40() == 1)
    {
        K_Fldrc_RequestArchives();
        gBtl->flags |= BTL_FLAG_EXIT;
    }

    if (FUN_001f1b00(*(void**)((u8*)gBtl + 0xd28)) != 0)
    {
        return BTL_STATE_NULL;
    }

    FUN_001f1c20(*(void**)((u8*)gBtl + 0xd28));
    *(void**)((u8*)gBtl + 0xd28) = NULL;

    if (gBtl->hasNoStartInfo == 1 && (gBtl->flags & 0x400))
    {
        H_Fade_FadeIn();
    }

    return BTL_STATE_EXIT;
}

// FUN_0029dcf0
void btlMainInitStateExit(BtlStateWork* work)
{
    btlPacket0027e4d0();

    if (!(gBtl->flags & BTL_FLAG_EXIT))
    {
        K_Fldrc_RequestArchives();

        gBtl->flags |= BTL_FLAG_EXIT;
    }
}
// FUN_0029dd50
u32 btlMainUpdateStateExit(BtlStateWork* work)
{
    if (btlPacketCount() == 0 && FUN_002dba60() == 0)
    {
        FUN_002dcf10();
        gBtl->flags &= ~BTL_FLAG_ACTIVE;
    }

    return BTL_STATE_NULL;
}

// FUN_0029ddb0
void btlMainInitStateTest(BtlStateWork* work)
{
    // nothing
}
// FUN_0029ddc0
u32 btlMainUpdateStateTest(BtlStateWork* work)
{
    scrClearTextBox(0, 0, 3, 0);
    btlFadeCreateTask(0);

    return BTL_STATE_INIT;
}

// FUN_0029de00
void btlMainInitStateMc(BtlStateWork* work)
{
    // nothing
}
// FUN_0029de10
u32 btlMainUpdateStateMc(BtlStateWork* work)
{
    // OK
    return BTL_STATE_NULL;
}

// FUN_0029de20
void btlMainSetState(u32 state)
{
    gBtl->stateWork.currState = state;
    gBtl->stateWork.stateTimer = 0;
    
    sBtlStateTable[gBtl->stateWork.currState].init(&gBtl->stateWork);
}

// FUN_0029de80
void btlMainUpdateState()
{
    u32 newState;

    if (gBtl->stateWork.stateToSet != BTL_STATE_NULL)
    {
        gBtl->stateWork.currState = gBtl->stateWork.stateToSet;
        gBtl->stateWork.stateTimer = 0;
        sBtlStateTable[gBtl->stateWork.currState].init(&gBtl->stateWork);

        gBtl->stateWork.stateToSet = BTL_STATE_NULL;
    }

    newState = sBtlStateTable[gBtl->stateWork.currState].update(&gBtl->stateWork);

    if (newState != BTL_STATE_NULL)
    {
        gBtl->stateWork.stateToSet = newState;
    }

    gBtl->stateWork.stateTimer++;
}

// FUN_0029df40. Called when 'btlCtx' is allocated
void btlMainSetStateNon()
{
    gBtl->stateWork.currState = BTL_STATE_NON;
    gBtl->stateWork.stateTimer = 0;
    sBtlStateTable[gBtl->stateWork.currState].init(&gBtl->stateWork);

    gBtl->stateWork.stateToSet = BTL_STATE_NULL;
}

// FUN_0029e390
void btlMainLoadScene()
{
    MT_Scene_Load(gBtl->fldMajorId, gBtl->fldMinorId);
}

// FUN_0029e400
u32 btlMainTryLoadFinishScene()
{
    return MT_Scene_TryLoadFinish();
}