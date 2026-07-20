#include "Battle/battle.h"
#include "Main/g_data.h"
#include "Battle/btlFade.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Scene/mt_scene.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_fade.h"
#include "temporary.h"
#include "Battle/btlAction.h"
#include "Battle/btlFormation.h"
#include "Battle/btlUnit.h"
#include "rw/rwcore.h"
#include "rw/rtquat.h"

/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0029ee20(u64 param_1);
typedef struct BtlMainColorWork BtlMainColorWork;
typedef struct BtlMainLerpWork
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 target0;
    f32 target1;
    f32 target2;
    f32 target3;
    u32 totalFrames;
    u32 currentFrame;
} BtlMainLerpWork;
#define CONCAT13(a, b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
u32 FUN_0029f150(float *param_1);
void FUN_0029f4b0(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_0029f760(float *param_1);
BtlPacket* FUN_0029fa50(u32 param_1);
u32 FUN_0029faa0(BtlMainColorWork *param_1);
void FUN_002a0050(u32 param_1,u32 param_2,u32 param_3,float param_4,u16 param_5);
u32 FUN_002a0440(float *param_1);
BtlPacket* FUN_002a1080(s32 param_1, s16 param_2);
u8 FUN_002a10e0(BtlMainLerpWork *param_1);
void FUN_002a1280(u32 param_1,u32 param_2);
u8 FUN_002a1400(float *param_1);
BtlPacket* FUN_002a16c0(s32 param_1);
u32 FUN_002a1710(int *param_1);
void FUN_002a1b00(s32 param_1,s16 param_2,s32 param_3);
u32 FUN_002a1b70(u32 *param_1);
void FUN_002a1db0(s32 param_1);
void FUN_002a1e00(float param_1,float *param_2,float *param_3,float *param_4);
u32 FUN_002a2050(u16 *param_1,f32 *param_2,f32 *param_3);
void FUN_002a2170(u16 *param_1,f32 *param_2);
void FUN_002a2290(u16 *param_1,long param_2,long param_3,u16 param_4);
void FUN_002a2660(u16 *param_1,long param_2,long param_3,long param_4,long param_5,u16 param_6  );
void FUN_002a2a20(u8* param_2,f32* param_3,f32 param_1);
void FUN_002a2b50(u8* param_2, f32* param_3, f32 param_1);
void FUN_002a2c40(u8* param_2,f32* param_3,f32 param_1);
u32 FUN_002a2ed0(u8* param_1,f32* param_2,f32* param_3);
u32 FUN_002a3010(u8* param_2,f32 param_1);
void FUN_002a3110(u8* param_2,float param_1);
void FUN_002a3160(u8* param_2,float param_1);
extern u32 DAT_00693850;
extern u32 DAT_00693854;
extern u32 DAT_00693858;
extern u32 DAT_0069385c;
extern u32 DAT_00693860;
extern u32 DAT_00693864;
extern u32 DAT_00693868;
extern f32 DAT_00697880;
extern f32 DAT_00697888;
extern f32 DAT_00697884;
extern f32 DAT_007caee8;
extern f32 DAT_007caf08;
extern f32 DAT_007caf88;
extern f32 DAT_007cafbc;
extern u32 DAT_007cc970;
extern u32 DAT_007cc972;
extern u8 DAT_007cc971;
extern u8 DAT_007ce4f9;
extern u8 DAT_007ce4fa;
extern u8 DAT_007ce4fb;
extern u32 DAT_007cc973;
extern u8* DAT_007ce3ec;
extern f32 DAT_00957180;
extern f32 DAT_00957184;
extern f32 DAT_00957188;
#pragma alias DAT_00957180_abs DAT_00957180
#pragma alias DAT_00957184_abs DAT_00957184
#pragma alias DAT_00957188_abs DAT_00957188
extern f32 DAT_00957180_abs[];
extern f32 DAT_00957184_abs[];
extern f32 DAT_00957188_abs[];
extern u32 DAT_009572b0;
extern u32 DAT_009572b4;
extern u32 DAT_009572b8;
extern u32 DAT_009572bc;
extern u32 DAT_009572c0;
extern u32 DAT_009572c4;
extern u32 DAT_009572c8;
extern u32 DAT_009572cc;
extern u32 DAT_009572d0;
extern u32 _DAT_0069386c;
extern f32 fGpffff8044;
extern f32 fGpffff804c;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8048;
extern f32 fGpffff8050;
extern f32 fGpffff805c;
extern f32 fGpffff8118;
extern f32 fGpffff82c8;
extern f32 fGpffff83d0;
extern f32 fGpffff83d4;
extern f32 fGpffff83d8;
extern int iGpffffb6fc;
extern u8 bGpffffb808;
extern u8 bGpffffb809;
extern u8 bGpffffb80a;
extern u8 bGpffffb80b;
extern int iGpffffb708;

#define BTL_U16(offset) (*(u16*)((u8*)gBtl + (offset)))
#define BTL_U32(offset) (*(u32*)((u8*)gBtl + (offset)))
#define BTL_PACKET_U8(packet, offset) (*(u8*)((u8*)(packet) + (offset)))
#define BTL_PACKET_U16(packet, offset) (*(u16*)((u8*)(packet) + (offset)))
#define BTL_PACKET_U64(packet, offset) (*(u64*)((u8*)(packet) + (offset)))

typedef struct BtlMainRecovery
{
    s32 hpDelta;
    s32 spDelta;
    u32 flags;
} BtlMainRecovery;

struct BtlMainColorWork
{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u16 unk_68;
    u16 unk_6a;
};

extern u8 DAT_007ce4f8[4];
extern u8* iGpffffb710;
extern f32 fGpffff8218;
extern f32 fGpffff82cc;
extern f32 fGpffff81e8;
extern RwV3d D_00697870;
extern f32 D_00697880[];
extern RwRGBAReal D_00693850;
extern RwRGBAReal D_00693860;
extern RwSky2DVertex DAT_00957270;
extern f32 DAT_009572B0[8];
extern u32 DAT_009572D0;
extern void (*DAT_00960090)(u32 state, u32 value);
extern void (*DAT_009600A0)(u32 primitive, void* vertices, u32 count);

RwRGBAReal* func_0019fd70(void);
RwMatrix* func_0019fda0(void);
RwRGBAReal* func_001a09d0(void);
void* func_001a0700(u16 resTypeId);
void* func_001a07f0(u16 resTypeId);
void* func_001a08e0(u16 resTypeId);
RwMatrix* func_001a0a50(void);
void func_0019f8f0(const RwRGBAReal* color);
void FUN_004c9d70(f32 value, void* data);

extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0956;
extern u16 DAT_007e0958;
extern const u16 D_007E094C;
extern const u16 D_007E094E;
extern const u16 D_007E0956;
extern const u16 D_007E0958;
extern void* DAT_007ce4f4;
extern void* DAT_007cad78;
extern char DAT_006935c0[];

void FUN_001a0410();
u32 FUN_0016f190(s32 bit);
u16 FUN_0016c920();
u16 FUN_0016c9f0();
void FUN_0016d6b0();
u32 FUN_0017d800();
u16 FUN_0017b170();
void FUN_0016f1f0();
DatUnit* FUN_0016cd60(s16 pcId);
void FUN_001a0590();
void* FUN_001f1ae0();
void FUN_001fec50();
u32 FUN_001fec30();
u32 FUN_001feec0();
void FUN_001febf0();
void FUN_001ff370();
void FUN_001ff350();
void FUN_001ff390();

BtlAction* FUN_00289650();
BtlPacket* FUN_002e2ec0();
BtlPacket* FUN_002e2a10();
BtlPacket* FUN_002f9bc0();
BtlPacket* FUN_00285690();
BtlPacket* FUN_00285d30();
BtlPacket* FUN_002819d0(void* param_1, BtlUnit* unit, const RwV3d* pos, u16 param_4);
BtlPacket* FUN_002822b0(BtlUnit* unit, const RtQuat* rot, u32 param_3);
BtlPacket* FUN_00284200(f32 param_1, BtlUnit* unit, u16 param_3, u16 param_4, u16 param_5);
BtlPacket* FUN_00284d80(BtlUnit* unit, u16 param_2);
BtlPacket* FUN_002dd960();
BtlPacket* FUN_002dd8e0();
BtlPacket* FUN_002bb2f0();
BtlPacket* FUN_002bc680();
BtlPacket* FUN_002bfc00();
BtlPacket* FUN_002dbfe0();
BtlPacket* FUN_002db740();
BtlPacket* FUN_002b8d60();
BtlPacket* FUN_002b8f90();
BtlPacket* FUN_002bac00();
BtlPacket* FUN_002dd4a0();
BtlPacket* FUN_002baf90();
BtlPacket* FUN_002dd5e0();
BtlPacket* FUN_002bd480();
BtlPacket* FUN_002d7e20(BtlAction* action, BtlAction* param_2, BtlMainRecovery* recovery, u32 param_4, u32 param_5);
BtlPacket* FUN_002bd230();
BtlPacket* FUN_002bdbd0();
BtlPacket* FUN_002e2be0();
BtlPacket* FUN_002db890();
BtlPacket* FUN_002bc7e0();
BtlPacket* FUN_002dd100();

Model* FUN_00316910();
u16 FUN_003b6000();
u64 FUN_00306e80();
u16 FUN_00308120();
u32 FUN_0030b5a0();
u32 FUN_0030b5e0();
u32 FUN_00300580();
u32 FUN_003005e0();
void FUN_00300560();
void FUN_003004f0();
void FUN_00300410();
void FUN_00300480();
void FUN_00302380();
void FUN_00301690(u32 param_1);
void* FUN_00198590(void);

void FUN_0029dfc0(void);
void FUN_00287b20();
void FUN_002831c0();
void FUN_00282d40(f32 param_1, BtlUnit* unit, s16 param_3, u32 param_4, s8 param_5);
void FUN_00282bc0();
void FUN_0031c7e0();
void FUN_0027f680(BtlUnit* unit, const RtQuat* rot);
u32 FUN_003009a0();
BtlPacket* FUN_002a3b40();
void FUN_00287490();
void FUN_00287510();
void FUN_002b71e0();
u16 FUN_002d50c0();
void FUN_0029a690();
void FUN_0029a470();
void FUN_0029a750();
u16 FUN_002ffbc0();
BtlAction* FUN_0029ad20();
BtlAction* FUN_0029ad50();
void FUN_0029abe0();
void FUN_002fac80();
u16 FUN_002d4cf0();
u16 FUN_002ffcc0();
void FUN_002dcd30();
u32 FUN_002d1a70();
void FUN_002d1a10();
void FUN_002d3e00();
void FUN_00280870(u32 param_1, u32 param_2, RwV3d* pos, u32 param_4, u32 param_5, u32 param_6);
void FUN_004c69f0(RwV3d* dst, const RwV3d* src);
void FUN_002ffd90();
u16 FUN_002838d0(f32 param_1, BtlUnit* unit, u16 param_3);
void FUN_002ff2f0();
void FUN_002bfc70();
u32 FUN_002ff320();
void FUN_002faab0();
void FUN_0029b070();
void FUN_00521408();
u32 FUN_002d4ed0();
u32 FUN_002d5550();
u32 FUN_0027d560();
void FUN_003c72d0(void* param_1);
void FUN_003c7430();
void FUN_003c7560();
void FUN_003c74e0();
void FUN_002bb6f0();
void FUN_0029ea60(u32 index, u32* colorA, u32* colorB);
s32 FUN_0029ec00(s32 index);
void FUN_0029ec80(u32 index, u32* colorA, u32* colorB);
s32 FUN_0029ec50(s32 index);
BtlAction* FUN_0029a1d0();
void FUN_002d5dc0();
u32 FUN_002ffdf0();
u32 FUN_00300100();
u16 FUN_002ffd70();
u16 FUN_002ffd80();
void FUN_002b9030();
u32 FUN_002fd7c0();
void FUN_002ddbe0();
void FUN_002a4c50();
void FUN_002bf650();
void FUN_002ffdc0();
void FUN_00299d60();
void FUN_0048d480(void* curve,s32 mode,f32 time,RwV3d* dst,void* aux);

static u16 btlMainGetDatUnitId(const DatUnit* datUnit)
{
    return *(const u16*)((const u8*)datUnit + 2);
}

static void btlMainRegisterDependentPacket(BtlPacket* packet, u8 type, u64 parentUID)
{
    packet->unk_00 = 4;
    packet->parentUID = parentUID;
    btlPacketRegister(packet, type);
}

static void btlMainSetPacketAction(BtlPacket* packet, const BtlAction* action)
{
    packet->actionUID = action->uid;
}

void btlSound002dced0(u16 param_1);
void btlSound002dcf80(s32 param_1, u16 param_2);
void btlBoss002f6e00();
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
void FUN_0029e3c0(void);
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
BtlPacket* func_002e2ec0(u16 voiceId);
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
}
// FUN_0029b0f0
u32 btlMainUpdateStateNon(BtlStateWork* work)
{
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
    BtlPacket* scenePacket;
    BtlPacket* soundPacket;
    s32 loadSound;
    if (btlMainTryLoadFinishScene() != 0 && btlPacketCount() == 0)
    {
        FUN_001a0410(1);
        FUN_0029dfc0();
        switch (datGetFlag(0x141))
        {
        default:
            loadSound = 0;
            break;
        case 0:
            loadSound = 1;
            break;
        }
        scenePacket = func_002e2ec0(loadSound);
        btlPacketRegister(scenePacket, BTLPACKET_TYPE_1);
        soundPacket = FUN_002e2a10();
        soundPacket->unk_00 = 4;
        soundPacket->parentUID = scenePacket->uid;
        btlPacketRegister(soundPacket, BTLPACKET_TYPE_1);
        btlPacketRegister(FUN_002f9bc0(), BTLPACKET_TYPE_1);
        return BTL_STATE_UNITCREATE;
    }
    return BTL_STATE_NULL;
}

// FUN_0029b280 NONMATCHING
void btlMainInitStateUnitCreate(BtlStateWork* work)
{
    BtlAction* action;
    BtlUnit* unit;
    BtlPacket* packet;
    BtlEncountTable* encount;
    DatUnitEc* enemy;
    Model* model;
    u64 modelPacketUID;
    u64 targetMask;
    u32 encountFlags;
    u16 battleMode;
    u16 threshold;
    u32 i;
    u32 j;
    u8 useSpecialFormation;
    modelPacketUID = 0;
    i = 0;
    while (i < 4 && gBtl->startInfo.partyUnits[i] != ((void*)0))
    {
        u16 charId = *(u16*)((u8*)gBtl->startInfo.partyUnits[i] + 6);
        unit = action->unit;
        model = FUN_00316910(unit->genus + 1, charId, 0);
        unit->mdl = model;
        if (model == ((void*)0))
        {
            packet = FUN_00285690(unit, charId, 0x36);
            btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, modelPacketUID);
            modelPacketUID = packet->uid;
        }
        else
        {
            unit->flags2 |= 2;
            unit->flags2 |= 8;
            unit->resTypeId = FUN_003b6000(charId, model);
            FUN_001a0590(unit->resTypeId, 1);
            FUN_002831c0(unit, 0);
            FUN_00282d40(unit->unk_9e4, unit, unit->unk_9e0, 0, unit->unk_9e8);
            FUN_00282bc0(unit);
            if (*(s32*)((u8*)unit->mdl + 0x3f8) == 0)
            {
                FUN_0031c7e0();
            }
            FUN_00287490(unit);
        }
        i++;
    }
    gBtl->unk_ba4 = i;
    enemy = gBtl->startInfo.enmUnits;
    for (i = 0; i < 6; i++, enemy = (DatUnitEc*)((u8*)enemy + 0x3c))
    {
        if (btlMainGetDatUnitId((DatUnit*)enemy) != 0 && FUN_0030b5a0(enemy, 0) == 0)
        {
        }
    }
    FUN_002b71e0();
    if ((gBtl->flags & 0x100) == 0)
    {
        return;
    }
    encount = &gEncountTbl[*(u16*)((u8*)gBtl->startInfo.enmUnits + 8)];
    encountFlags = *(u32*)encount;
    useSpecialFormation = 0;
    if ((encountFlags & 0x20) == 0)
    {
        battleMode = FUN_002d50c0();
        (*(u16*)((u8*)gBtl + (0x1a))) = battleMode;
        if (battleMode == 2)
        {
            FUN_0029a690(1);
            gBtl->order.flags |= 4;
            if ((encountFlags & 0x200) == 0)
            {
                FUN_001febf0(1);
                gBtl->flags |= 0x100000;
            }
        }
        else if (battleMode == 1)
        {
            FUN_0029a690(0);
            FUN_0029a470(gBtl->actionList.head);
            gBtl->order.flags |= 2;
            if ((encountFlags & 0x200) == 0)
            {
                FUN_001febf0(0);
                gBtl->flags |= 0x100000;
            }
            useSpecialFormation = 1;
        }
        else if (battleMode == 0)
        {
            FUN_0029a750();
            if ((gBtl->startInfo.unk_00 & 4) != 0)
            {
                for (j = 0; j < FUN_002ffbc0(0xc); j++)
                {
                    FUN_0029abe0(FUN_0029ad20());
                }
            }
        }
    }
    else if ((encountFlags & 0x10) == 0)
    {
        FUN_002fac80();
        (*(u16*)((u8*)gBtl + (0x1a))) = 0;
    }
    else
    {
        FUN_0029a690(1);
    }
    if ((gBtl->startInfo.unk_00 & 8) != 0)
    {
        useSpecialFormation = 1;
    }
    if (useSpecialFormation != 0 && (encountFlags & 0x100) == 0)
    {
        threshold = FUN_002d4cf0(1, 0);
        targetMask = FUN_00308120(0x3FFFFFFFFFFFFFFF, 2);
        for (unit = gBtl->unitLists[1].head; unit != ((void*)0); unit = unit->next)
        {
            if (unit->datUnit != ((void*)0) && (FUN_00306e80(unit->datUnit, targetMask) & 0x27000000) == 0 &&
                (u16)(FUN_002ffcc0(unit->datUnit) + 2) <= threshold && FUN_002ffbc0(100) < 0x21)
            {
                FUN_003004f0(unit->datUnit, 2);
            }
        }
    }
}
// FUN_0029b760 NONMATCHING
u32 btlMainUpdateStateUnitCreate(BtlStateWork* work)
{
    BtlUnit* unit;
    BtlPacket* movePacket;
    BtlPacket* packet;
    RwV3d homePos;
    RwV3d unitPos;
    RwV3d targetPos;
    RwV3d direction;
    RtQuat unitRot;
    RtQuat baseRot;
    u8 hasSkill24d;
    u8 hasSkill24e;
    u8 hasSkill24f;
    u32 genus;
    u32 encountIndex;
    if (btlPacketCount() != 0 || FUN_001fec30() != 0)
    {
        return BTL_STATE_NULL;
    }
    FUN_002dcd30();
    if (FUN_001feec0() == 0 && FUN_002d1a70() == 1)
    {
        gBtl->flags |= 0x4000;
        FUN_001ff370();
    }
    else
    {
        gBtl->flags &= ~0x4000;
        FUN_002d1a10();
    }
    for (genus = 0; genus < 2; genus++)
    {
        for (unit = gBtl->unitLists[genus].head; unit != ((void*)0); unit = unit->next)
        {
            FUN_002d3e00(unit, 0);
            btlUnit0027f7c0(unit, ((void*)0), (RwV3d*)&baseRot, ((void*)0));
            FUN_0027f680(unit, &baseRot);
        }
    }
    FUN_00280870(2, 0, &homePos, 0, 0, 1);
    for (unit = gBtl->unitLists[0].head; unit != ((void*)0); unit = unit->next)
    {
        FUN_00287490(unit);
        if (FUN_0030b5a0(unit->datUnit, 0) == 0 && gBtl->unk_ba4 > 1 && (gBtl->unk_10 & 1) == 0)
        {
            btlUnit0027f7c0(unit, &unitPos, ((void*)0), (RwV3d*)&unitRot);
            direction.x = unitPos.x - homePos.x;
            direction.y = unitPos.y - homePos.y;
            direction.z = unitPos.z - homePos.z;
            FUN_004c69f0(&direction, &direction);
            targetPos.x = direction.x * 150.0f + homePos.x;
            targetPos.y = direction.y * 150.0f + homePos.y;
            targetPos.z = direction.z * 150.0f + homePos.z;
            btlUnitSetPos(unit, &targetPos);
            movePacket = FUN_002819d0(DAT_007cad78, unit, &unitPos, 8);
            btlPacketRegister(movePacket, BTLPACKET_TYPE_1);
            packet = FUN_002822b0(unit, &unitRot, 0);
            btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, movePacket->uid);
            if (FUN_00300580(unit->datUnit, 0xfffff) == 0 && FUN_0030b5e0(unit->datUnit) == 0)
            {
                packet = FUN_00284200(1.0f, unit, 0x10, 4, 0);
                btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, movePacket->uid);
                (*(u16*)((u8*)(packet) + (0x48))) = 4;
            }
        }
        else if (FUN_0030b5a0(unit->datUnit, 0) != 0)
        {
            FUN_003004f0(unit->datUnit, 0x80000);
            FUN_002ffd90(unit->datUnit, 0);
            unit->flags3 |= (1 << 0);
            FUN_002831c0(unit, 0);
            btlPacketRegister(FUN_00284200(1.0f, unit, 0x12, 0, 2), BTLPACKET_TYPE_1);
            btlPacketRegister(FUN_00284d80(unit, FUN_002838d0(1.0f, unit, 0x12)), BTLPACKET_TYPE_1);
        }
    }
    for (genus = 0; genus < 2; genus++)
    {
        hasSkill24d = 0;
        hasSkill24e = 0;
        hasSkill24f = 0;
        for (unit = gBtl->unitLists[genus].head; unit != ((void*)0); unit = unit->next)
        {
            if (unit->datUnit != ((void*)0))
            {
                hasSkill24d |= FUN_003005e0(unit->datUnit, 0x24d) != 0;
                hasSkill24e |= FUN_003005e0(unit->datUnit, 0x24e) != 0;
                hasSkill24f |= FUN_003005e0(unit->datUnit, 0x24f) != 0;
            }
        }
        for (unit = gBtl->unitLists[genus].head; unit != ((void*)0); unit = unit->next)
        {
            if (unit->datUnit == ((void*)0))
            {
                continue;
            }
            if (FUN_003005e0(unit->datUnit, 0x22d) != 0 || FUN_003009a0(unit->datUnit, 0xb4) != 0 || hasSkill24e)
            {
                FUN_00302380(unit->datUnit, 5, 1);
            }
            if (FUN_003005e0(unit->datUnit, 0x22e) != 0 || FUN_003009a0(unit->datUnit, 0xb5) != 0 || hasSkill24d)
            {
                FUN_00302380(unit->datUnit, 0x40, 1);
            }
            if (FUN_003005e0(unit->datUnit, 0x22f) != 0 || FUN_003009a0(unit->datUnit, 0xb6) != 0 || hasSkill24f)
            {
                FUN_00302380(unit->datUnit, 0x110, 1);
            }
            *(u16*)unit->datUnit &= 0xfbf7;
        }
    }
    encountIndex = *(u16*)((u8*)gBtl->startInfo.enmUnits + 8);
    if (gEncountTbl[encountIndex].enmIds[0] != 0 && gEncountTbl[encountIndex].enmIds[1] != 0)
    {
        (*(u16*)((u8*)gBtl + (0xbe0))) = gEncountTbl[encountIndex].enmIds[0];
        (*(u32*)((u8*)gBtl + (0xbe4))) = gEncountTbl[encountIndex].enmIds[1];
        (*(u32*)((u8*)gBtl + (0xbf8))) = 1;
    }
    btlPacketRegister(FUN_002a3b40(((void*)0), 2), BTLPACKET_TYPE_0);
    if ((gBtl->unk_10 & 1) == 0)
    {
        FUN_002ff2f0();
    }
    FUN_002bfc70(0);
    FUN_002bfc50(0);
    return BTL_STATE_UNITLOAD;
}

// FUN_0029be40 NONMATCHING
void btlMainInitStateUnitLoad(BtlStateWork* work)
{
    BtlUnit* unit;
    BtlPacket* modelPacket;
    BtlPacket* formationPacket;
    BtlPacket* packet;
    u64 modelPacketUID;
    u64 formationPacketUID;
    u64 lastPacketUID;
    u16 enemyCount;
    u8 firstUnit;
    enemyCount = 0;
    for (unit = gBtl->unitLists[1].head; unit != ((void*)0); unit = unit->next)
    {
        enemyCount++;
    }
    firstUnit = 1;
    modelPacketUID = 0;
    formationPacketUID = 0;
    for (unit = gBtl->unitLists[1].head; unit != ((void*)0); unit = unit->next)
    {
        modelPacket = FUN_00285690(unit, unit->charId, 0x3e);
        btlMainRegisterDependentPacket(modelPacket, BTLPACKET_TYPE_1, modelPacketUID);
        modelPacketUID = modelPacket->uid;
        if ((gBtl->unk_10 & 1) == 0)
        {
            formationPacket = FUN_002bb2f0(DAT_007ce4f4, unit, 0, 0, 0);
            btlMainRegisterDependentPacket(formationPacket, BTLPACKET_TYPE_2D, modelPacket->uid);
            if (firstUnit != 0)
            {
                (*(u16*)((u8*)(formationPacket) + (0x48))) = 1;
            }
            else
            {
                (*(u8*)((u8*)(formationPacket) + (0x10))) = 5;
                (*(u64*)((u8*)(formationPacket) + (0x18))) = formationPacketUID;
                (*(u16*)((u8*)(formationPacket) + (0x48))) = enemyCount < 4 ? 8 : 4;
            }
            formationPacketUID = formationPacket->uid;
            packet = FUN_00285d30(unit, 0x3FFFFFFFFFFFFFFF, 8, 0, 3, 1);
            btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, modelPacket->uid);
            (*(u8*)((u8*)(packet) + (0x10))) = 5;
            (*(u64*)((u8*)(packet) + (0x18))) = formationPacketUID;
            (*(u16*)((u8*)(packet) + (0x48))) = 0x1d;
        }
        else
        {
            packet = FUN_00285d30(unit, 0x3FFFFFFFFFFFFFFF, 0, 0, 3, 1);
            btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, modelPacket->uid);
            (*(u16*)((u8*)(packet) + (0x48))) = 2;
            formationPacketUID = packet->uid;
        }
        firstUnit = 0;
    }
    packet = FUN_002bc680();
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, modelPacketUID);
    lastPacketUID = packet->uid;
    packet = FUN_002bfc00();
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, lastPacketUID);
    lastPacketUID = packet->uid;
    packet = FUN_002dbfe0(FUN_0016f190(0x141) == 0);
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, lastPacketUID);
}
// FUN_0029c110
u32 btlMainUpdateStateUnitLoad(BtlStateWork* work)
{
    BtlUnit* unit;
    u32 state;
    if ((gBtl->flags & 0x100000) != 0 && FUN_002ff320() != 1)
    {
        FUN_001fec50();
        gBtl->flags &= ~0x100000;
    }
    if (btlPacketCount() == 0 && (gBtl->flags & 0x100000) == 0)
    {
        if (FUN_001feec0() == 0)
        {
            btlPacketRegister(FUN_002db740(gBtl->actionList.head, 0, 0, 0, 0), BTLPACKET_TYPE_1);
        }
        for (unit = gBtl->unitLists[1].head; unit != ((void*)0); unit = unit->next)
        {
            if ((unit->flags3 & (1 << 3)) != 0)
            {
                FUN_00287490(unit);
            }
            else
            {
                FUN_00287510(unit);
            }
        }
        FUN_002faab0();
        state = BTL_STATE_START;
    }
    else
    {
        state = BTL_STATE_NULL;
    }
    return state;
}

// FUN_0029c250
void btlMainInitStateStart(BtlStateWork* work)
{
    if (gBtl->unk_10 & 1)
    {
        btlFadeStart(3);
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
}
// FUN_0029c340
u32 btlMainUpdateStateAction(BtlStateWork* work)
{
    BtlUnit* unit;
    u16 aliveCount;
    u16 unitCount;
    BtlUnit* unit2;
    u16 battleMode;
    if ((gBtl->flags & 0x80) != 0)
    {
        FUN_0029b070();
        FUN_001ff390();
        FUN_001ff350();
        {
            battleMode = BTL_U16(0x1c);
            switch (battleMode)
            {
            case 1:
            case 3:
                if (battleMode != 3)
                {
                    if (FUN_002d4ed0(FUN_0029ad20()) == 1)
                    {
                        BTL_U32(0xbdc) |= 1;
                    }
                }
                else
                {
                    FUN_00521408((u8*)gBtl + 0xbdc, 0, 0x44);
                }
                unitCount = 0;
                aliveCount = 0;
                for (unit = gBtl->unitLists[0].tail; unit != NULL; unit = unit->prev)
                {
                    if (FUN_0030b5a0(unit->datUnit, 0) != 0)
                    {
                        unitCount++;
                    }
                    else
                    {
                        *(u16*)((u8*)gBtl + 0xc00 + aliveCount * sizeof(u16)) = *(u16*)((u8*)unit->datUnit + 2);
                        aliveCount++;
                        unitCount++;
                    }
                }
                BTL_U32(0xc08) = aliveCount;
                BTL_U32(0xc0c) = unitCount;
                BTL_U32(0xc1c) = *(u16*)((u8*)gBtl + 0xb9a);
                if ((s32)*(u16*)((u8*)gBtl + 0xb9a) > 0)
                {
                    BTL_U32(0xc14) = (u32)((s32)BTL_U32(0xc14) / (s32)*(u16*)((u8*)gBtl + 0xb9a));
                }
                BTL_U32(0xc18) = FUN_002d5550();
                for (unit2 = gBtl->unitLists[0].tail; unit2 != NULL; unit2 = unit2->prev)
                {
                    if (unit2->datUnit != NULL)
                    {
                        FUN_00300560(unit2->datUnit, 0xfff7ff7f);
                    }
                }
                BTL_U32(0xd28) = (u32)FUN_001f1ae0((u8*)gBtl + 0xbdc);
                battleMode = BTL_U16(0x1c);
                if (battleMode == 1)
                {
                    return (gBtl->unk_10 & 2) != 0 ? BTL_STATE_ENEMYDEAD : BTL_STATE_WIN;
                }
            case 2:
                if (battleMode == 2)
                {
                    return FUN_0027d560() != 0 ? BTL_STATE_REVIVALMES : BTL_STATE_LOSE;
                }
                return BTL_STATE_FADEOUT;
            }
        }
    }
    return BTL_STATE_NULL;
}
// FUN_0029c5d0
void btlMainInitStateRevivalMes(BtlStateWork* work)
{
    BtlPacket* packet;
    BtlAction* action;
    action = gBtl->actionList.head;
    FUN_003c72d0(DAT_006935c0);
    FUN_003c7430(1);
    FUN_003c7560(0);
    FUN_003c74e0(0);
    packet = btlFormation002b8d60(3, 0xfff);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    btlPacketRegister(FUN_002a3b40(((void*)0), 0x24), BTLPACKET_TYPE_0);
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

// FUN_0029c700 NONMATCHING
void btlMainInitStateRevival(BtlStateWork* work)
{
    BtlAction* action;
    BtlAction* unitAction;
    BtlUnit* unit;
    BtlPacket* spellPacket;
    BtlPacket* spellContext;
    BtlPacket* dependentPacket;
    BtlPacket* packet;
    BtlMainRecovery recovery;
    u8 skillData[0x80];
    u32 paramA;
    u32 paramB;
    u32 color;
    u64 previousUID;

    action = gBtl->actionList.head;
    previousUID = 0;
    spellContext = FUN_002b8f90(0);
    FUN_002bb6f0(0x1b7, skillData);
    packet = FUN_002bac00(spellContext, skillData, 0);
    btlMainSetPacketAction(packet, action);
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    dependentPacket = FUN_002dd4a0(0x1b7, 0);
    btlMainRegisterDependentPacket(dependentPacket, BTLPACKET_TYPE_1, packet->uid);
    btlMainSetPacketAction(dependentPacket, action);

    FUN_0029ea60(0x1b7, &paramA, &paramB);
    btlMainSetPacketAction(packet, action);
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    color = FUN_0029ec00(0x1b7);
    FUN_0029ec80(0x1b7, &paramA, &paramB);
    btlMainSetPacketAction(packet, action);
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    btlMainSetPacketAction(packet, action);
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    spellPacket = FUN_002baf90(spellContext, action->unit, action->unit, 0, 0);
    btlMainRegisterDependentPacket(spellPacket, BTLPACKET_TYPE_2D, dependentPacket->uid);
    btlMainSetPacketAction(spellPacket, action);
    dependentPacket = FUN_002dd5e0(0);
    BTL_PACKET_U8(dependentPacket, 0x00) = 5;
    dependentPacket->parentUID = spellPacket->uid;
    btlPacketRegister(dependentPacket, BTLPACKET_TYPE_1);

    for (unit = gBtl->unitLists[0].head; unit != NULL; unit = unit->next)
    {
        unitAction = FUN_0029a1d0(unit);
        FUN_002d5dc0(&recovery);
        recovery.hpDelta = FUN_002ffdf0(unit->datUnit) - FUN_002ffd70(unit->datUnit);
        recovery.spDelta = FUN_00300100(unit->datUnit) - FUN_002ffd80(unit->datUnit);
        if (FUN_0030b5a0(unit->datUnit, 0) != 0)
        {
            recovery.flags = 0x80000;
        }

        packet = FUN_002bd480(unit);
        btlMainSetPacketAction(packet, action);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        dependentPacket = FUN_002baf90(spellContext, unit, unit, 1, 0);
        btlMainRegisterDependentPacket(dependentPacket, BTLPACKET_TYPE_2D, spellPacket->uid);
        BTL_PACKET_U8(dependentPacket, 0x10) = 4;
        BTL_PACKET_U64(dependentPacket, 0x18) = previousUID;
        btlMainSetPacketAction(dependentPacket, action);

        packet = FUN_002dd5e0(1);
        BTL_PACKET_U8(packet, 0x00) = 5;
        packet->parentUID = dependentPacket->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        packet = FUN_002a3b40(unitAction, 0x17);
        BTL_PACKET_U8(packet, 0x00) = 5;
        packet->parentUID = dependentPacket->uid;
        BTL_PACKET_U8(packet, 0x20) = 0xb;
        BTL_PACKET_U64(packet, 0x28) = dependentPacket->uid;
        BTL_PACKET_U16(packet, 0x4a) = 0x12;
        btlMainSetPacketAction(packet, action);
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        previousUID = packet->uid;

        if ((recovery.flags & 0x80000) != 0 && (unit->flags3 & 0x200) != 0)
        {
            packet = FUN_00284200(1.0f, unit, 0x13, 0, 0);
            BTL_PACKET_U8(packet, 0x00) = 0xb;
            packet->parentUID = dependentPacket->uid;
            btlMainSetPacketAction(packet, action);
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }

        packet = FUN_002d7e20(unitAction, unitAction, &recovery, 1, 1);
        BTL_PACKET_U8(packet, 0x00) = 0xb;
        packet->parentUID = dependentPacket->uid;
        btlMainSetPacketAction(packet, action);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (recovery.hpDelta != 0)
        {
            dependentPacket = FUN_002bd230(unit, 0, 0);
            btlMainRegisterDependentPacket(dependentPacket, BTLPACKET_TYPE_3D, packet->uid);
            BTL_PACKET_U8(dependentPacket, 0x47) &= 0xdf;
        }
        dependentPacket = FUN_002bdbd0(unit, unit, BTL_UIDMAX, 0, 0, 0, 1, &recovery);
        btlMainRegisterDependentPacket(dependentPacket, BTLPACKET_TYPE_3D, packet->uid);
        BTL_PACKET_U8(dependentPacket, 0x47) &= 0xdf;
    }

    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, previousUID);
    btlMainSetPacketAction(packet, action);
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, previousUID);
    btlMainSetPacketAction(packet, action);
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, previousUID);
    btlMainSetPacketAction(packet, action);
    FUN_002b9030(spellContext);
}
// FUN_0029ccd0
u32 btlMainUpdateStateRevival(BtlStateWork* work)
{
    BtlAction* action;
    u16 revivalCount;
    action = gBtl->actionList.head;
    if (btlPacketFindFirstByActionUID(action->uid, 0x3FFFFFFFFFFFFFFF) == ((void*)0))
    {
        revivalCount = func_00170760((s16)action->unit->datUnit->id, 0xfc8);
        func_00170860((s16)action->unit->datUnit->id, 0xfc8, revivalCount - 1);
        FUN_002bfc50(0);
        FUN_0029b040();
        if (FUN_002fd7c0() == 1)
        {
            FUN_001ff370();
        }
        gBtl->flags &= ~0x80;
        btlPacketRegister(FUN_002a3b40(action, 0x1f), BTLPACKET_TYPE_0);
        return BTL_STATE_ACTION;
    }
    return BTL_STATE_NULL;
}
// FUN_0029ce90
void btlMainInitStateWin(BtlStateWork* work)
{
    BtlAction* winner;
    BtlAction* action;
    BtlPacket* packet;

    winner = FUN_0029ad20();
    if ((winner->unk_18 & 4) != 0)
    {
        winner = FUN_0029ad50();
    }
    if (winner == NULL || winner->unit->genus == UNIT_GENUS_EC)
    {
        winner = gBtl->actionList.head;
    }

    work->winPacketFrame = 0x18;
    work->winAnimFrame = FUN_002838d0(1.0f, winner->unit, 0x14);
    work->winInputSeen = 0;
    work->winWaitFrames = winner == gBtl->actionList.head ? 0x30 : 0x18;

    for (action = gBtl->actionList.tail; action != NULL; action = action->prev)
    {
        if ((action->unk_1a & 1) != 0 && action->unit->genus == UNIT_GENUS_EC &&
            FUN_0030b5a0(action->unit->datUnit, 0) != 0)
        {
            packet = btlUnit00286320(action->unit);
            packet->actionUID = winner->uid;
            BTL_PACKET_U16(packet, 0x48) = work->winPacketFrame;
            btlPacketRegister(packet, BTLPACKET_TYPE_0);
        }
    }

    packet = FUN_002db740(winner, 0xf, 0, 0, 3);
    BTL_PACKET_U16(packet, 0x48) = work->winPacketFrame;
    packet->actionUID = winner->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002e2be0(winner, 7, 0, 0, 0);
    BTL_PACKET_U16(packet, 0x48) = work->winPacketFrame;
    packet->actionUID = winner->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_00284200(1.0f, winner->unit, 0x14, 0, 2);
    BTL_PACKET_U16(packet, 0x48) = work->winPacketFrame;
    packet->actionUID = winner->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
    packet = FUN_002a3b40(winner, 0x20);
    BTL_PACKET_U16(packet, 0x48) = work->winPacketFrame;
    packet->actionUID = winner->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);
}
// FUN_0029d0d0
u32 btlMainUpdateStateWin(BtlStateWork* work)
{
    BtlPacket* packet;

    if (work->stateTimer > work->winPacketFrame + work->winWaitFrames &&
        work->winInputSeen == 0)
    {
        if ((D_007E094C & 0x10) != 0)
        {
            goto win_input;
        }
        else if ((D_007E0956 & 0x10) != 0)
        {
            goto win_input;
        }
        else if ((D_007E094E & 0x40) != 0)
        {
            goto win_input;
        }
        else if ((D_007E0958 & 0x40) != 0)
        {
            goto win_input;
        }
        else
        {
            goto win_done;
        }
    }
    goto win_done;

win_input:
    packet = FUN_002db890();
    BTL_PACKET_U16(packet, 0x4a) = 0xc;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    FUN_002ddbe0();
    work->winInputSeen = 1;

win_done:
    if (btlPacketCount() == 0 &&
        (work->winInputSeen != 0 ||
         work->stateTimer >= work->winPacketFrame + work->winAnimFrame))
    {
        return BTL_STATE_CONDITION;
    }
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
    u32 state;

    if (btlPacketCount() == 0)
    {
        gBtl->flags &= ~0x80000;
        state = (gBtl->flags & 0x80) != 0 ? BTL_STATE_FADEOUT : BTL_STATE_ACTION;
    }
    else
    {
        state = BTL_STATE_NULL;
    }

    return state;
}

// FUN_0029d1f0 NONMATCHING
void btlMainInitStateCondition(BtlStateWork* work)
{
    BtlUnit* unit;
    BtlUnit* changedUnit;
    BtlAction* action;
    BtlPacket* cameraPacket;
    BtlPacket* packet;
    u16 unitId;
    u16 oldCondition;
    u16 newCondition;
    u16 conditionPacket;
    u16 messagePacket;
    u16 sickUnitCount;
    u32 threshold;
    u8 forceConditionChange;
    u64 lastPacketUID;
    forceConditionChange = 0;
    if (FUN_0016f190(0x172) != 0)
    {
        return;
    }
    sickUnitCount = 0;
    for (unit = gBtl->unitLists[0].head; unit != ((void*)0); unit = unit->next)
    {
        unitId = btlMainGetDatUnitId(unit->datUnit);
        oldCondition = FUN_0016c920(unitId);
        if (FUN_0017d800() == 0 && oldCondition != 5 && oldCondition != 4 && oldCondition != 3)
        {
            FUN_0016ca90(unitId, 0x3FFFFFFFFFFFFFFF);
        }
        if (FUN_0030b5a0(unit->datUnit, 0) == 0 && oldCondition == 5)
        {
            sickUnitCount++;
        }
    }
    if (sickUnitCount != 0 && FUN_002ffbc0(100) < 10)
    {
        FUN_002ffbc0(sickUnitCount);
        forceConditionChange = 1;
    }
    changedUnit = ((void*)0);
    newCondition = 0;
    for (unit = gBtl->unitLists[0].head; unit != ((void*)0); unit = unit->next)
    {
        unitId = btlMainGetDatUnitId(unit->datUnit);
        oldCondition = FUN_0016c920(unitId);
        newCondition = oldCondition;
        if (FUN_0030b5a0(unit->datUnit, 0) == 0)
        {
            switch (oldCondition)
            {
                case 0:
                case 1:
                case 2:
                    if (FUN_0016c9f0(unitId) == 0)
                    {
                        newCondition = 3;
                    }
                case 3:
                    if (forceConditionChange != 0)
                    {
                        if (oldCondition == 3)
                        {
                            threshold = 0x3c;
                        }
                        else if (oldCondition == 2)
                        {
                            threshold = 5;
                        }
                        else if (oldCondition == 1)
                        {
                            threshold = 10;
                        }
                        else
                        {
                            threshold = 0x19;
                        }
                        if (threshold != 0 && FUN_002ffbc0(100) < threshold && unitId != 3)
                        {
                            newCondition = 5;
                        }
                    }
                    break;
                case 4:
                    if (FUN_002ffbc0(100) < (u16)(FUN_0017b170() + 10) && unitId != 3)
                    {
                        newCondition = 5;
                    }
                    break;
            }
        }
        if (newCondition != oldCondition)
        {
            FUN_0016d6b0(unitId, newCondition);
            changedUnit = unit;
            break;
        }
    }
    if (changedUnit == ((void*)0))
    {
        return;
    }
    action = FUN_0029a1d0(changedUnit);
    cameraPacket = FUN_002a3b40(action, 0x21);
    btlMainSetPacketAction(cameraPacket, action);
    (*(u16*)((u8*)(cameraPacket) + (0x48))) = 8;
    btlPacketRegister(cameraPacket, BTLPACKET_TYPE_0);
    packet = FUN_002bc7e0(8);
    (*(u8*)((u8*)(packet) + (0x00))) = 5;
    packet->parentUID = cameraPacket->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_00284200(1.0f, changedUnit, 3, 0, 1);
    (*(u8*)((u8*)(packet) + (0x00))) = 5;
    packet->parentUID = cameraPacket->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002dd100(0xe, 2, 9);
    (*(u8*)((u8*)(packet) + (0x00))) = 5;
    packet->parentUID = cameraPacket->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    if (newCondition == 3)
    {
        conditionPacket = 0x12;
        messagePacket = 0x13;
    }
    else
    {
        conditionPacket = 0x10;
        messagePacket = 0x12;
    }
    packet = FUN_002e2be0(action, messagePacket, 0, 0, 0);
    (*(u8*)((u8*)(packet) + (0x00))) = 5;
    packet->parentUID = cameraPacket->uid;
    lastPacketUID = packet->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002db740(action, conditionPacket, 0, 0, 1);
    btlMainRegisterDependentPacket(packet, BTLPACKET_TYPE_1, lastPacketUID);
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
}
// FUN_0029d730
u32 btlMainUpdateStateLose(BtlStateWork* work)
{
    if (work->stateTimer > 30)
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
    BtlUnit* unit;
    BtlAction* action;
    DatUnit* data;
    u16 value;
    u16 index;
    u32 flags;

    if (BTL_U16(0x1c) == 1)
    {
        for (unit = gBtl->unitLists[0].head; unit != NULL; unit = unit->next)
        {
            if (unit->datUnit == NULL)
            {
                continue;
            }
            if (FUN_003005e0(unit->datUnit, 0x25e) != 0)
            {
                FUN_002ffd90(unit->datUnit, FUN_002ffdf0(unit->datUnit));
                FUN_002ffdc0(unit->datUnit, FUN_00300100(unit->datUnit));
            }
            else if (FUN_003005e0(unit->datUnit, 0x25d) != 0)
            {
                value = FUN_002ffdf0(unit->datUnit);
                FUN_00300410(unit->datUnit, value * 100 / 0x4e2);
                value = FUN_00300100(unit->datUnit);
                FUN_00300480(unit->datUnit, value * 100 / 0x4e2);
            }
        }
    }

    FUN_002a4c50();
    FUN_002bf650();
    flags = BTL_U32(0xc20);
    if (flags != 0)
    {
        value = BTL_U16(0x1c);
        if (value == 1)
        {
            if ((flags & 1) != 0)
            {
                FUN_0016f1f0(0x1001, 1);
            }
            if ((BTL_U32(0xc20) & 2) != 0)
            {
                FUN_0016f1f0(0x1002, 1);
            }
            if ((BTL_U32(0xc20) & 4) != 0)
            {
                FUN_0016f1f0(0x1003, 1);
            }
            if ((BTL_U32(0xc20) & 8) != 0)
            {
                FUN_0016f1f0(0x1004, 1);
            }
        }
    }

    for (unit = gBtl->unitLists[0].head; unit != NULL; unit = unit->next)
    {
        if (unit->datUnit != NULL)
        {
            FUN_00301690((u32)unit->datUnit);
        }
    }

    index = 1;
    while (index <= 10)
    {
        data = (DatUnit*)FUN_0016cd60(index);
        switch (data->aiTactic)
        {
        case 7:
        case 10:
            data->aiTactic = 1;
            break;
        default:
            if (FUN_0016f190(0x187) == 0)
            {
                data->aiTactic = 1;
            }
            break;
        }
        index++;
    }

    for (action = gBtl->actionList.tail; action != NULL; action = action->prev)
    {
        u16 state = action->currState;
        if (state != BTLACTION_STATE_EXIT)
        {
            FUN_00299d60(action, BTLACTION_STATE_EXIT);
        }
    }
    btlPacket0027e4d0();
}

// FUN_0029db60
u32 btlMainUpdateStateEnd(BtlStateWork* work)
{
    if (gBtl->actionList.tail != ((void*)0))
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
    if (!(gBtl->flags & (1 << 27)) && FUN_001f1f40() == 1)
    {
        K_Fldrc_RequestArchives();
        gBtl->flags |= (1 << 27);
    }
    if (FUN_001f1b00(*(void**)((u8*)gBtl + 0xd28)) != 0)
    {
        return BTL_STATE_NULL;
    }
    FUN_001f1c20(*(void**)((u8*)gBtl + 0xd28));
    *(void**)((u8*)gBtl + 0xd28) = ((void*)0);
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
    if (!(gBtl->flags & (1 << 27)))
    {
        K_Fldrc_RequestArchives();
        gBtl->flags |= (1 << 27);
    }
}
// FUN_0029dd50
u32 btlMainUpdateStateExit(BtlStateWork* work)
{
    if (btlPacketCount() == 0 && FUN_002dba60() == 0)
    {
        FUN_002dcf10();
        gBtl->flags &= ~(1 << 0);
    }
    return BTL_STATE_NULL;
}

// FUN_0029ddb0
void btlMainInitStateTest(BtlStateWork* work)
{
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
}
// FUN_0029de10
u32 btlMainUpdateStateMc(BtlStateWork* work)
{
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

// FUN_0029dfb0
void btlMain0029dfb0(void)
{
}
// FUN_0029dfc0
void FUN_0029dfc0(void)
{
    RwRGBAReal* color;
    RwMatrix* matrix;

    color = K_Scene_GetFldAmbLightColor();
    *(RwRGBAReal*)((u8*)gBtl + 0x194) = *color;
    color = func_0019fd70();
    *(RwRGBAReal*)((u8*)gBtl + 0x1a4) = *color;
    matrix = func_0019fda0();
    RtQuatConvertFromMatrix((RtQuat*)((u8*)gBtl + 0x1b4), matrix);

    *(f32*)((u8*)gBtl + 0x224) = fGpffff8218 * (f32)DAT_007ce4f8[0];
    *(f32*)((u8*)gBtl + 0x228) = fGpffff8218 * (f32)DAT_007ce4f8[1];
    *(f32*)((u8*)gBtl + 0x22c) = fGpffff8218 * (f32)DAT_007ce4f8[2];
    *(f32*)((u8*)gBtl + 0x230) = fGpffff8218 * (f32)DAT_007ce4f8[3];

    color = func_001a09d0();
    *(RwRGBAReal*)((u8*)gBtl + 0x1c4) = *color;
    color = K_Scene_GetCharAmbLightColor();
    *(RwRGBAReal*)((u8*)gBtl + 0x1d4) = *color;
    matrix = func_001a0a50();
    RtQuatConvertFromMatrix((RtQuat*)((u8*)gBtl + 0x1e4), matrix);
    memcpy((u8*)gBtl + 0x1f4, (u8*)gBtl + 0x1c4, 0x30);

    *(f32*)((u8*)gBtl + 0x234) = fGpffff8218 * (f32)DAT_007ce4f8[0];
    *(f32*)((u8*)gBtl + 0x238) = fGpffff8218 * (f32)DAT_007ce4f8[1];
    *(f32*)((u8*)gBtl + 0x23c) = fGpffff8218 * (f32)DAT_007ce4f8[2];
    *(f32*)((u8*)gBtl + 0x240) = fGpffff8218 * (f32)DAT_007ce4f8[3];
    FUN_004c9d70(35.0f, FUN_00198590());
    gBtl->flags |= 0x2000002;
}

void FUN_003b5ab0();

// FUN_0029e370
void btlMain0029e370(void)
{
    FUN_003b5ab0();
}

// FUN_0029e390
void btlMainLoadScene()
{
    MT_Scene_Load(gBtl->fldMajorId, gBtl->fldMinorId);
}
// FUN_0029e3c0
void FUN_0029e3c0(void)
{
    gBtl->flags &= ~2;
    FUN_003b5ab0();
}

// FUN_0029e400
u32 btlMainTryLoadFinishScene()
{
    return MT_Scene_TryLoadFinish();
}
// FUN_0029e420
void btlMain0029e420(void)
{
    Battle* battle;
    RwRGBAReal* color;
    battle = gBtl;
    if ((battle->flags & 2) != 0)
    {
        color = func_001a09d0();
        *color = *(RwRGBAReal*)((u8*)battle + 0x1c4);
        battle = gBtl;
        color = K_Scene_GetCharAmbLightColor();
        *color = *(RwRGBAReal*)((u8*)battle + 0x1d4);
    }
}

// FUN_0029e4b0 NONMATCHING
void btlMain0029e4b0(void)
{
    RwSky2DVertex vertices[4];
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u32 i;

    if (*(f32*)((u8*)gBtl + 0x240) <= 0.0f)
    {
        return;
    }

    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    DAT_00960090(0xc, 1);
    DAT_00960090(0xe, 0);
    DAT_00960090(1, 0);
    DAT_00960090(6, 0);
    DAT_00960090(8, 0);
    DAT_00960090(7, 2);

    red = ((u32)(*(f32*)((u8*)gBtl + 0x234) * 255.0f + 0.5f)) & 0xff;
    green = ((u32)(*(f32*)((u8*)gBtl + 0x238) * 255.0f + 0.5f)) & 0xff;
    blue = ((u32)(*(f32*)((u8*)gBtl + 0x23c) * 255.0f + 0.5f)) & 0xff;
    alpha = ((u32)(*(f32*)((u8*)gBtl + 0x240) * 255.0f + 0.5f)) & 0xff;

    memset(vertices, 0, sizeof(vertices));
    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[1].u.els.scrVertex.x = 0.0f;
    vertices[1].u.els.scrVertex.y = 448.0f;
    vertices[2].u.els.scrVertex.x = 640.0f;
    vertices[2].u.els.scrVertex.y = 0.0f;
    vertices[3].u.els.scrVertex.x = 640.0f;
    vertices[3].u.els.scrVertex.y = 448.0f;
    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.color.r = (f32)red;
        vertices[i].u.els.color.g = (f32)green;
        vertices[i].u.els.color.b = (f32)blue;
        vertices[i].u.els.color.a = (f32)alpha;
    }

    DAT_009600A0(4, vertices, 4);
}
// FUN_0029ea20
void* FUN_0029ea20(void)
{
    return (u8*)gBtl + 0x194;
}

// FUN_0029ea30
void* FUN_0029ea30(void)
{
    return (u8*)gBtl + 0x1c4;
}

// FUN_0029ea40
void* FUN_0029ea40(void)
{
    return (u8*)gBtl + 0x1f4;
}

// FUN_0029ea50
void* FUN_0029ea50(void)
{
    return (u8*)gBtl + 0x224;
}

// FUN_0029ea60 NONMATCHING
void FUN_0029ea60(u32 index, u32* colorA, u32* colorB)
{
    u8* entry;
    u32 value;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;

    entry = iGpffffb710 + (index & 0xffff) * 0x1c;
    value = *(u32*)(entry + 8);
    if ((value & 0xff000000) != 0)
    {
        *colorA = value;
    }
    else
    {
        red = (u32)(*(f32*)((u8*)gBtl + 0x194) * 255.0f + 0.5f);
        green = (u32)(*(f32*)((u8*)gBtl + 0x198) * 255.0f + 0.5f);
        blue = (u32)(*(f32*)((u8*)gBtl + 0x19c) * 255.0f + 0.5f);
        alpha = (u32)(*(f32*)((u8*)gBtl + 0x1a0) * 255.0f + 0.5f);
        *colorA = (red & 0xff) | ((green & 0xff) << 8) |
                  ((blue & 0xff) << 16) | ((alpha & 0xff) << 24);
    }

    value = *(u32*)(entry + 0xc);
    if ((value & 0xff000000) != 0)
    {
        *colorB = value;
    }
    else
    {
        red = (u32)(*(f32*)((u8*)gBtl + 0x1a4) * 255.0f + 0.5f);
        green = (u32)(*(f32*)((u8*)gBtl + 0x1a8) * 255.0f + 0.5f);
        blue = (u32)(*(f32*)((u8*)gBtl + 0x1ac) * 255.0f + 0.5f);
        alpha = (u32)(*(f32*)((u8*)gBtl + 0x1b0) * 255.0f + 0.5f);
        *colorB = (red & 0xff) | ((green & 0xff) << 8) |
                  ((blue & 0xff) << 16) | ((alpha & 0xff) << 24);
    }
}

// FUN_0029ec00
s32 FUN_0029ec00(s32 index)
{
    u32 offset;
    u8* entry;
    s32 value;
    offset = (index & 0xffff) * 0x1c;
    entry = (u8*)((uintptr_t)(iGpffffb710 + 4) + (uintptr_t)offset);
    value = *(s32*)entry;
    if ((value & 0xff000000) != 0)
    {
        value = (value & 0xffffff) | 0xff000000;
    }
    else
    {
        value = 0xffffffff;
    }
    return value;
}

// FUN_0029ec50
s32 FUN_0029ec50(s32 index)
{
    u8* entry;
    entry = (u8 *)(uintptr_t)iGpffffb710;
    entry = (u8 *)(uintptr_t)((index & 0xffff) * 0x1c) + (uintptr_t)entry;
    return *(s32 *)(entry + 0x18);
}

// FUN_0029ec80 NONMATCHING
void FUN_0029ec80(u32 index, u32* colorA, u32* colorB)
{
    u8* entry;
    u32 value;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;

    entry = iGpffffb710 + (index & 0xffff) * 0x1c;
    value = *(u32*)(entry + 0x10);
    if ((value & 0xff000000) != 0)
    {
        *colorA = value;
    }
    else
    {
        red = (u32)(*(f32*)((u8*)gBtl + 0x1f4) * 255.0f + 0.5f);
        green = (u32)(*(f32*)((u8*)gBtl + 0x1f8) * 255.0f + 0.5f);
        blue = (u32)(*(f32*)((u8*)gBtl + 0x1fc) * 255.0f + 0.5f);
        alpha = (u32)(*(f32*)((u8*)gBtl + 0x200) * 255.0f + 0.5f);
        *colorA = (red & 0xff) | ((green & 0xff) << 8) |
                  ((blue & 0xff) << 16) | ((alpha & 0xff) << 24);
    }

    value = *(u32*)(entry + 0x14);
    if ((value & 0xff000000) != 0)
    {
        *colorB = value;
    }
    else
    {
        red = (u32)(*(f32*)((u8*)gBtl + 0x204) * 255.0f + 0.5f);
        green = (u32)(*(f32*)((u8*)gBtl + 0x208) * 255.0f + 0.5f);
        blue = (u32)(*(f32*)((u8*)gBtl + 0x20c) * 255.0f + 0.5f);
        alpha = (u32)(*(f32*)((u8*)gBtl + 0x210) * 255.0f + 0.5f);
        *colorB = (red & 0xff) | ((green & 0xff) << 8) |
                  ((blue & 0xff) << 16) | ((alpha & 0xff) << 24);
    }
}

/* Recovered battle-misc harvest: 0x0029EE20-0x002A3160 */
// FUN_0029EE20 NONMATCHING






void FUN_0029ee20(u64 param_1)



{

  char cVar1;

  float fVar2;

  u32 *puVar3;

  int iVar4;

  u64 *puVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  u64 uStack_90;

  float fStack_88;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  if (((*(u32 *)(DAT_007ce3ec + 0xc) & 2) != 0) &&

     (iVar4 = (int)param_1, *(short *)(iVar4 + 0x9f2) != 0)) {

    cVar1 = *(char *)(iVar4 + 0xa2);

    if (cVar1 == '\x02') {

      FUN_004c31b0(0xc2b40000,&uStack_90,0x697870,0);

      puVar3 = (u32 *)FUN_001a0700(*(u16 *)(iVar4 + 0x9f2));

      uVar8 = DAT_0069385c;

      uVar7 = DAT_00693858;

      uVar6 = DAT_00693854;

      *puVar3 = DAT_00693850;

      puVar3[1] = uVar6;

      puVar3[2] = uVar7;

      puVar3[3] = uVar8;

      puVar3 = (u32 *)FUN_001a07f0(*(u16 *)(iVar4 + 0x9f2));

      uVar8 = _DAT_0069386c;

      uVar7 = DAT_00693868;

      uVar6 = DAT_00693864;

      *puVar3 = DAT_00693860;

      puVar3[1] = uVar6;

      puVar3[2] = uVar7;

      puVar3[3] = uVar8;

      puVar3 = (u32 *)FUN_001a08e0(*(u16 *)(iVar4 + 0x9f2));

      puVar5 = &uStack_90;

      iVar4 = 8;

      do {

        uVar6 = *(u32 *)puVar5;

        uVar7 = *(u32 *)((int)puVar5 + 4);

        puVar5 = puVar5 + 1;

        iVar4 = iVar4 + -1;

        *puVar3 = uVar6;

        puVar3[1] = uVar7;

        puVar3 = puVar3 + 2;

      } while (0 < iVar4);

    }

    else if ((cVar1 == '\x01') || (cVar1 == '\0')) {

      fStack_40 = *(float *)(iVar4 + 0x54);

      fStack_3c = *(float *)(iVar4 + 0x58);

      fStack_38 = *(float *)(iVar4 + 0x5c);

      FUN_0027ffb0(param_1,&fStack_50);

      fVar2 = fStack_4c + 5.0;

      if (fStack_4c + 5.0 < fStack_3c) {

        fVar2 = fStack_3c;

      }

      fStack_3c = fVar2;

      fStack_10 = fStack_50 - fStack_40;
      fStack_c = fStack_4c - fStack_3c;
      fStack_8 = fStack_48 - fStack_38;
      FUN_004c69f0((RwV3d*)&fStack_10,(RwV3d*)&fStack_10);
      fStack_70 = fStack_10;
      fStack_6c = fStack_c;
      fStack_68 = fStack_8;
      fStack_20 = DAT_00697884 * fStack_8 - DAT_00697888 * fStack_c;
      fStack_1c = DAT_00697888 * fStack_10 - DAT_00697880 * fStack_8;
      fStack_18 = DAT_00697880 * fStack_c - DAT_00697884 * fStack_10;
      FUN_004c69f0((RwV3d*)&fStack_20,(RwV3d*)&fStack_20);
      uStack_90 = CONCAT44(fStack_1c,fStack_20);

      fStack_88 = fStack_18;

      fStack_80 = fStack_c * fStack_18 - fStack_8 * fStack_1c;

      fStack_7c = fStack_8 * fStack_20 - fStack_10 * fStack_18;

      fStack_78 = fStack_10 * fStack_1c - fStack_c * fStack_20;

      fStack_30 = fStack_80;

      fStack_2c = fStack_7c;

      fStack_28 = fStack_78;

      puVar3 = (u32 *)FUN_001a07f0(*(u16 *)(iVar4 + 0x9f2));

      uVar8 = *(u32 *)(iVar4 + 0x74);

      uVar6 = *(u32 *)(iVar4 + 0x78);

      uVar7 = *(u32 *)(iVar4 + 0x7c);

      *puVar3 = *(u32 *)(iVar4 + 0x70);

      puVar3[1] = uVar8;

      puVar3[2] = uVar6;

      puVar3[3] = uVar7;

      puVar3 = (u32 *)FUN_001a08e0(*(u16 *)(iVar4 + 0x9f2));

      puVar5 = &uStack_90;

      iVar4 = 8;

      do {

        uVar6 = *(u32 *)puVar5;

        uVar7 = *(u32 *)((int)puVar5 + 4);

        puVar5 = puVar5 + 1;

        iVar4 = iVar4 + -1;

        *puVar3 = uVar6;

        puVar3[1] = uVar7;

        puVar3 = puVar3 + 2;

      } while (0 < iVar4);

    }

  }

  return;

}

// FUN_0029F150 NONMATCHING


u32 FUN_0029f150(float *param_1)



{

  u32 uVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    uVar1 = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    uVar1 = 1;

  }

  else {

    if (param_1[0x19] == 0.0) {

      pfVar2 = (float *)FUN_0019fd40();

      fVar8 = pfVar2[1];

      fVar3 = pfVar2[2];

      fVar4 = pfVar2[3];

      param_1[0x10] = *pfVar2;

      param_1[0x11] = fVar8;

      param_1[0x12] = fVar3;

      param_1[0x13] = fVar4;

      pfVar2 = (float *)FUN_0019fd70();

      fVar8 = pfVar2[1];

      fVar3 = pfVar2[2];

      fVar4 = pfVar2[3];

      param_1[0x14] = *pfVar2;

      param_1[0x15] = fVar8;

      param_1[0x16] = fVar3;

      param_1[0x17] = fVar4;

      param_1[8] = param_1[0x10] * *param_1;

      param_1[9] = param_1[0x11] * param_1[1];

      param_1[10] = param_1[0x12] * param_1[2];

      param_1[0xb] = param_1[0x13] * param_1[3];

      param_1[0xc] = param_1[0x14] * param_1[4];

      param_1[0xd] = param_1[0x15] * param_1[5];

      param_1[0xe] = param_1[0x16] * param_1[6];

      param_1[0xf] = param_1[0x17] * param_1[7];

    }

    if ((u32)param_1[0x19] < (u32)param_1[0x18]) {

      fVar11 = (float)(u32)param_1[0x19] / (float)(u32)param_1[0x18];

      fVar12 = 1.0 - fVar11;

      fVar4 = param_1[0x10];

      fVar8 = param_1[0x11];

      fVar5 = param_1[0x12];

      fVar6 = param_1[0x13];

      fVar10 = param_1[8] * fVar11;

      fVar7 = param_1[9] * fVar11;

      fVar9 = param_1[10] * fVar11;

      fVar3 = param_1[0xb] * fVar11;

      pfVar2 = (float *)FUN_0019fd40();

      *pfVar2 = fVar4 * fVar12 + fVar10;

      pfVar2[1] = fVar8 * fVar12 + fVar7;

      pfVar2[2] = fVar5 * fVar12 + fVar9;

      pfVar2[3] = fVar3 + fVar6 * fVar12;

      fVar3 = param_1[0x14];

      fVar6 = param_1[0xc];

      fVar4 = param_1[0x15];

      fVar7 = param_1[0xd];

      fVar8 = param_1[0x16];

      fVar9 = param_1[0xe];

      fVar5 = param_1[0x17];

      fVar10 = param_1[0xf];

      pfVar2 = (float *)FUN_0019fd70();

      *pfVar2 = fVar3 * fVar12 + fVar6 * fVar11;

      pfVar2[1] = fVar4 * fVar12 + fVar7 * fVar11;

      pfVar2[2] = fVar8 * fVar12 + fVar9 * fVar11;

      pfVar2[3] = fVar5 * fVar12 + fVar10 * fVar11;

      param_1[0x19] = (float)((int)param_1[0x19] + 1);

      uVar1 = 0;

    }

    else {

      pfVar2 = (float *)FUN_0019fd40();

      fVar8 = param_1[9];

      fVar3 = param_1[10];

      fVar4 = param_1[0xb];

      *pfVar2 = param_1[8];

      pfVar2[1] = fVar8;

      pfVar2[2] = fVar3;

      pfVar2[3] = fVar4;

      pfVar2 = (float *)FUN_0019fd70();

      fVar8 = param_1[0xd];

      fVar3 = param_1[0xe];

      fVar4 = param_1[0xf];

      *pfVar2 = param_1[0xc];

      pfVar2[1] = fVar8;

      pfVar2[2] = fVar3;

      pfVar2[3] = fVar4;

      uVar1 = 1;

    }

  }

  return uVar1;

}

// FUN_0029F760 NONMATCHING


u32 FUN_0029f760(float *param_1)



{

  int iVar1;

  float *pfVar2;

  u32 *puVar3;

  float fVar4;

  u32 uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  u32 uVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  u32 uVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    uVar5 = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    uVar5 = 1;

  }

  else {

    if (param_1[9] == 0.0) {

      pfVar2 = (float *)FUN_0019fd40();

      fVar11 = pfVar2[1];

      fVar4 = pfVar2[2];

      fVar6 = pfVar2[3];

      *param_1 = *pfVar2;

      param_1[1] = fVar11;

      param_1[2] = fVar4;

      param_1[3] = fVar6;

      pfVar2 = (float *)FUN_0019fd70();

      fVar11 = pfVar2[1];

      fVar4 = pfVar2[2];

      fVar6 = pfVar2[3];
    iVar1 = (int)(uintptr_t)DAT_007ce3ec;
      param_1[4] = *pfVar2;

      param_1[5] = fVar11;

      param_1[6] = fVar4;

      param_1[7] = fVar6;

    }

    iVar1 = (int)(uintptr_t)DAT_007ce3ec;

    if ((u32)param_1[9] < (u32)param_1[8]) {

      fVar15 = (float)(u32)param_1[9] / (float)(u32)param_1[8];

      fVar16 = 1.0 - fVar15;

      fVar6 = *param_1;

      fVar11 = param_1[1];

      fVar7 = param_1[2];

      fVar8 = param_1[3];

      fVar14 = *(float *)(DAT_007ce3ec + 0x194) * fVar15;

      fVar10 = *(float *)(DAT_007ce3ec + 0x198) * fVar15;

      fVar12 = *(float *)(DAT_007ce3ec + 0x19c) * fVar15;

      fVar4 = *(float *)(DAT_007ce3ec + 0x1a0) * fVar15;

      pfVar2 = (float *)FUN_0019fd40();

      *pfVar2 = fVar6 * fVar16 + fVar14;

      pfVar2[1] = fVar11 * fVar16 + fVar10;

      pfVar2[2] = fVar7 * fVar16 + fVar12;

      pfVar2[3] = fVar4 + fVar8 * fVar16;

      fVar4 = param_1[4];

      fVar8 = *(float *)(DAT_007ce3ec + 0x1a4);

      fVar6 = param_1[5];

      fVar10 = *(float *)(DAT_007ce3ec + 0x1a8);

      fVar11 = param_1[6];

      fVar12 = *(float *)(DAT_007ce3ec + 0x1ac);

      fVar7 = param_1[7];

      fVar14 = *(float *)(DAT_007ce3ec + 0x1b0);

      pfVar2 = (float *)FUN_0019fd70();

      *pfVar2 = fVar4 * fVar16 + fVar8 * fVar15;

      pfVar2[1] = fVar6 * fVar16 + fVar10 * fVar15;

      pfVar2[2] = fVar11 * fVar16 + fVar12 * fVar15;

      pfVar2[3] = fVar7 * fVar16 + fVar14 * fVar15;

      param_1[9] = (float)((int)param_1[9] + 1);

      uVar5 = 0;

    }

    else {

      puVar3 = (u32 *)FUN_0019fd40();

      uVar13 = *(u32 *)(iVar1 + 0x198);

      uVar5 = *(u32 *)(iVar1 + 0x19c);
      iVar1 = (int)(uintptr_t)DAT_007ce3ec;
      uVar9 = *(u32 *)(iVar1 + 0x1a0);

      *puVar3 = *(u32 *)(iVar1 + 0x194);

      puVar3[1] = uVar13;

      puVar3[2] = uVar5;

      puVar3[3] = uVar9;

      iVar1 = (int)(uintptr_t)DAT_007ce3ec;

      puVar3 = (u32 *)FUN_0019fd70();

      uVar13 = *(u32 *)(iVar1 + 0x1a8);

      uVar5 = *(u32 *)(iVar1 + 0x1ac);

      uVar9 = *(u32 *)(iVar1 + 0x1b0);

      *puVar3 = *(u32 *)(iVar1 + 0x1a4);

      puVar3[1] = uVar13;

      puVar3[2] = uVar5;

      puVar3[3] = uVar9;

      uVar5 = 1;

    }

  }

  return uVar5;

}

// FUN_0029FAA0 NONMATCHING


u32 FUN_0029faa0(BtlMainColorWork *param_1)



{

  u64 uVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 *puVar6;

  float *pfVar7;

  BtlMainColorWork *colorWork;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  u32 uStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  u32 uStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    uVar3 = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    uVar3 = 1;
      iVar5 = (int)(uintptr_t)DAT_007ce3ec;
  }

  else {

    colorWork = param_1;

    if (colorWork->unk_64 == 0) {

      colorWork->a = 1.0f;

      iVar5 = (int)(uintptr_t)DAT_007ce3ec;

      fVar10 = *(float *)(DAT_007ce3ec + 0x228);

      fVar11 = *(float *)(DAT_007ce3ec + 0x22c);

      fVar9 = *(float *)(DAT_007ce3ec + 0x230);

      colorWork->unk_10 = *(float *)(DAT_007ce3ec + 0x224);

      colorWork->unk_14 = fVar10;

      colorWork->unk_18 = fVar11;

      colorWork->unk_1c = fVar9;

      fVar10 = *(float *)(iVar5 + 0x1c8);

      fVar11 = *(float *)(iVar5 + 0x1cc);

      fVar9 = *(float *)(iVar5 + 0x1d0);

      colorWork->unk_30 = *(float *)(iVar5 + 0x1c4);

      colorWork->unk_34 = fVar10;

      colorWork->unk_38 = fVar11;

      colorWork->unk_3c = fVar9;

      fVar10 = *(float *)(iVar5 + 0x1d8);

      fVar11 = *(float *)(iVar5 + 0x1dc);

      fVar9 = *(float *)(iVar5 + 0x1e0);

      colorWork->unk_50 = *(float *)(iVar5 + 0x1d4);

      colorWork->unk_54 = fVar10;

      colorWork->unk_58 = fVar11;

      colorWork->unk_5c = fVar9;

      DAT_009572b0 = *(u32 *)(iVar5 + 0x194);

      DAT_009572b4 = *(u32 *)(iVar5 + 0x198);

      DAT_009572b8 = *(u32 *)(iVar5 + 0x19c);

      DAT_009572bc = *(u32 *)(iVar5 + 0x1a0);

      DAT_009572c0 = *(u32 *)(iVar5 + 0x1a4);

      DAT_009572c4 = *(u32 *)(iVar5 + 0x1a8);

      DAT_009572c8 = *(u32 *)(iVar5 + 0x1ac);

      DAT_009572cc = *(u32 *)(iVar5 + 0x1b0);

      fVar14 = *(float *)(iVar5 + 0x1b8);

      fVar15 = *(float *)(iVar5 + 0x1b4);

      fVar13 = *(float *)(iVar5 + 0x1bc);

      fVar12 = *(float *)(iVar5 + 0x1c0);

      fVar9 = 2.0f / (fVar12 * fVar12 + fVar13 * fVar13 + fVar15 * fVar15 + fVar14 * fVar14);

      fVar10 = fVar15 * fVar9;

      fVar11 = fVar14 * fVar9;

      fVar9 = fVar13 * fVar9;

      fStack_40 = 1.0f - (fVar14 * fVar11 + fVar13 * fVar9);

      fStack_3c = fVar15 * fVar11 + fVar9 * fVar12;

      fStack_38 = fVar13 * fVar10 - fVar11 * fVar12;

      fStack_30 = fVar15 * fVar11 - fVar9 * fVar12;

      fStack_2c = 1.0f - (fVar13 * fVar9 + fVar15 * fVar10);

      fStack_28 = fVar14 * fVar9 + fVar10 * fVar12;

      fStack_20 = fVar13 * fVar10 + fVar11 * fVar12;

      fStack_1c = fVar14 * fVar9 - fVar10 * fVar12;

      fStack_18 = 1.0f - (fVar15 * fVar10 + fVar14 * fVar11);
      puVar6 = (u32*)&DAT_00957270;
      uStack_10 = 0;

      uStack_c = 0;

      uStack_8 = 0;

      uStack_34 = 3;

      pfVar7 = &fStack_40;

      puVar6 = (u32*)&DAT_00957270;

      iVar5 = 4;

      do {

        uVar1 = *(u64 *)pfVar7;

        fVar9 = pfVar7[2];

        fVar10 = pfVar7[3];

        pfVar7 = pfVar7 + 4;

        iVar5 = iVar5 + -1;

        *puVar6 = (int)uVar1;

        puVar6[1] = (int)((u32)uVar1 >> 0x20);

        puVar6[2] = fVar9;

        puVar6[3] = fVar10;

        uVar2 = DAT_007cafbc;

        uVar3 = DAT_007caee8;

        puVar6 = puVar6 + 4;

      } while (0 < iVar5);

      DAT_009572d0 = 1;

      if ((colorWork->unk_68 & 4) == 0) {

        for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {

          for (iVar5 = *(int *)(DAT_007ce3ec + uVar4 * 8 + 0x150); iVar5 != 0;

              iVar5 = *(int *)(iVar5 + 0xa34)) {

            if ((*(u32 *)(iVar5 + 0x98) & 2) != 0) {

              *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x388) =

                   *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x388) | 6;

              *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x388) =

                   *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x388) | 0x10;

              if ((colorWork->unk_68 & 1) == 0) {

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3a9) = 0x50;

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3aa) = 4;

              }

              else {

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3a9) = 0;

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3aa) = 6;

              }

              *(u32 *)(*(int *)(iVar5 + 0x9f4) + 0x3ac) = uVar2;

              *(u32 *)(*(int *)(iVar5 + 0x9f4) + 0x3b0) = uVar3;
      iVar5 = (int)(uintptr_t)DAT_007ce3ec;
            }

          }

        }

      }

    }

    iVar5 = (int)(uintptr_t)DAT_007ce3ec;

    if (colorWork->unk_64 < colorWork->unk_60) {

      fVar15 = (float)colorWork->unk_64 / (float)colorWork->unk_60;

      fVar16 = 1.0f - fVar15;

      fStack_50 = colorWork->unk_10 * fVar16 + colorWork->r * fVar15;

      fStack_4c = colorWork->unk_14 * fVar16 + colorWork->g * fVar15;

      fStack_48 = colorWork->b * fVar15 + colorWork->unk_18 * fVar16;

      uStack_44 = 0x3f800000;

      *(float *)(DAT_007ce3ec + 0x224) = fStack_50;

      *(float *)(iVar5 + 0x228) = fStack_4c;

      *(float *)(iVar5 + 0x22c) = fStack_48;

      *(u32 *)(iVar5 + 0x230) = 0x3f800000;

      FUN_0019f8f0(&fStack_50);

      fVar10 = colorWork->unk_34;

      fVar11 = colorWork->unk_38;

      fVar12 = colorWork->unk_3c;

      fVar13 = colorWork->unk_24;

      fVar14 = colorWork->unk_28;

      fVar9 = colorWork->unk_2c;

      *(float *)(DAT_007ce3ec + 0x1c4) = colorWork->unk_30 * fVar16 + colorWork->unk_20 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1c8) = fVar10 * fVar16 + fVar13 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1cc) = fVar11 * fVar16 + fVar14 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1d0) = fVar9 * fVar15 + fVar12 * fVar16;

      fVar9 = colorWork->unk_54;

      fVar10 = colorWork->unk_58;

      fVar11 = colorWork->unk_5c;

      fVar12 = colorWork->unk_44;

      fVar13 = colorWork->unk_48;

      fVar14 = colorWork->unk_4c;

      *(float *)(DAT_007ce3ec + 0x1d4) = colorWork->unk_50 * fVar16 + colorWork->unk_40 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1d8) = fVar9 * fVar16 + fVar12 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1dc) = fVar10 * fVar16 + fVar13 * fVar15;

      *(float *)(DAT_007ce3ec + 0x1e0) = fVar11 * fVar16 + fVar14 * fVar15;
        iVar5 = (int)(uintptr_t)DAT_007ce3ec;
      colorWork->unk_64 = colorWork->unk_64 + 1;

      uVar3 = 0;

    }

    else {

      FUN_0019f8f0(param_1);

      iVar5 = (int)(uintptr_t)DAT_007ce3ec;

      fVar11 = colorWork->g;

      fVar9 = colorWork->b;

      fVar10 = colorWork->a;

      *(float *)(DAT_007ce3ec + 0x224) = colorWork->r;

      *(float *)(iVar5 + 0x228) = fVar11;

      *(float *)(iVar5 + 0x22c) = fVar9;

      *(float *)(iVar5 + 0x230) = fVar10;

      fVar11 = colorWork->unk_24;

      fVar9 = colorWork->unk_28;

      fVar10 = colorWork->unk_2c;

      *(float *)(iVar5 + 0x1c4) = colorWork->unk_20;

      *(float *)(iVar5 + 0x1c8) = fVar11;

      *(float *)(iVar5 + 0x1cc) = fVar9;

      *(float *)(iVar5 + 0x1d0) = fVar10;

      fVar11 = colorWork->unk_44;

      fVar9 = colorWork->unk_48;

      fVar10 = colorWork->unk_4c;

      *(float *)(iVar5 + 0x1d4) = colorWork->unk_40;

      *(float *)(iVar5 + 0x1d8) = fVar11;

      *(float *)(iVar5 + 0x1dc) = fVar9;

      *(float *)(iVar5 + 0x1e0) = fVar10;

      uVar3 = 1;

    }

  }

  return uVar3;

}
// FUN_002A0440 NONMATCHING
u32 FUN_002a0440(float *param_1)



{

  int iVar7;

  u32 uVar9;

  float fVar16;

  float fVar17;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;
  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  iVar7 = (int)(uintptr_t)DAT_007ce3ec;

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    uVar9 = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    uVar9 = 1;

  }

  else {

    if (*(u32 *)((u8 *)param_1 + 0x54) == 0) {
      float fVar8;
      float fVar10;
      float fVar14;
      float *pfVar4;
      u32 uVar5;

      fVar14 = *(float *)(DAT_007ce3ec + 0x228);

      fVar8 = *(float *)(DAT_007ce3ec + 0x22c);

      fVar10 = *(float *)(DAT_007ce3ec + 0x230);

      *param_1 = *(float *)(DAT_007ce3ec + 0x224);

      param_1[1] = fVar14;

      param_1[2] = fVar8;

      param_1[3] = fVar10;

      fVar14 = *(float *)(iVar7 + 0x1c8);

      fVar8 = *(float *)(iVar7 + 0x1cc);

      fVar10 = *(float *)(iVar7 + 0x1d0);

      param_1[0xc] = *(float *)(iVar7 + 0x1c4);

      param_1[0xd] = fVar14;

      param_1[0xe] = fVar8;

      param_1[0xf] = fVar10;

      fVar14 = *(float *)(iVar7 + 0x1d8);

      fVar8 = *(float *)(iVar7 + 0x1dc);

      fVar10 = *(float *)(iVar7 + 0x1e0);

      param_1[0x10] = *(float *)(iVar7 + 0x1d4);

      param_1[0x11] = fVar14;

      param_1[0x12] = fVar8;

      param_1[0x13] = fVar10;

      pfVar4 = (float *)FUN_0019fd40();

      fVar14 = pfVar4[1];

      fVar8 = pfVar4[2];

      fVar10 = pfVar4[3];

      param_1[4] = *pfVar4;

      param_1[5] = fVar14;

      param_1[6] = fVar8;

      param_1[7] = fVar10;

      pfVar4 = (float *)FUN_0019fd70();

      fVar14 = pfVar4[1];

      fVar8 = pfVar4[2];

      fVar10 = pfVar4[3];

      param_1[8] = *pfVar4;

      param_1[9] = fVar14;

      param_1[10] = fVar8;

      param_1[0xb] = fVar10;

      for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {

        for (iVar7 = *(int *)(DAT_007ce3ec + uVar5 * 8 + 0x150); iVar7 != 0;

            iVar7 = *(int *)(iVar7 + 0xa34)) {

          *(u8 *)(iVar7 + 0x38) = *(u8 *)(iVar7 + 0x3c);

          *(u8 *)(iVar7 + 0x39) = *(u8 *)(iVar7 + 0x3d);

          *(u8 *)(iVar7 + 0x3a) = *(u8 *)(iVar7 + 0x3e);

          *(u8 *)(iVar7 + 0x3b) = *(u8 *)(iVar7 + 0x3f);

          *(u32 *)(iVar7 + 0x60) = *(u32 *)(iVar7 + 0x70);

          *(u32 *)(iVar7 + 100) = *(u32 *)(iVar7 + 0x74);

          *(u32 *)(iVar7 + 0x68) = *(u32 *)(iVar7 + 0x78);

          *(u32 *)(iVar7 + 0x6c) = *(u32 *)(iVar7 + 0x7c);

          if (((*(u16 *)((u8 *)param_1 + 0x58) & 4) == 0) && ((*(u32 *)(iVar7 + 0x98) & 2) != 0)) {

            *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) =

                 *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) | 2;

            *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) =

                 *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) & 0xeb;

            *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a9) = 0;

            *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3aa) =

                 *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a8);

            if (*(u32 *)((u8 *)param_1 + 0x50) != 0) {

              *(char *)(*(int *)(iVar7 + 0x9f4) + 0x3aa) =

                   (char)((int)(u32)*(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3aa) /
                         (int)*(u32 *)((u8 *)param_1 + 0x50)
                         );

            }

          }

        }

      }

    }


    fStack_20 = DAT_007caf08 * (float)DAT_007cc970;

    fStack_1c = DAT_007caf08 * (float)DAT_007cc971;

    fStack_18 = DAT_007caf08 * (float)DAT_007cc972;

    fStack_14 = DAT_007caf08 * (float)DAT_007cc973;

    if (*(u32 *)((u8 *)param_1 + 0x54) < *(u32 *)((u8 *)param_1 + 0x50)) {
      u32 uVar5;
      int iVar7;
      iVar7 = (int)(uintptr_t)DAT_007ce3ec;
      {
        float fVar8;
        float fVar10;
        float fVar11;
        float fVar12;
        float fVar14;
        float *pfVar4;


      fVar16 = (float)*(u32 *)((u8 *)param_1 + 0x54) / (float)*(u32 *)((u8 *)param_1 + 0x50);

      fVar17 = 1.0 - fVar16;

      fStack_10 = *param_1 * fVar17 + fStack_20 * fVar16;

      fStack_c = param_1[1] * fVar17 + fStack_1c * fVar16;

      fStack_8 = fStack_18 * fVar16 + param_1[2] * fVar17;

      fStack_4 = 1.0;

      *(float *)(DAT_007ce3ec + 0x224) = fStack_10;

      *(float *)(iVar7 + 0x228) = fStack_c;

      *(float *)(iVar7 + 0x22c) = fStack_8;

      *(u32 *)(iVar7 + 0x230) = 0x3f800000;

      FUN_0019f8f0(&fStack_10);

      fStack_10 = param_1[4] * fVar17 + *(float *)(DAT_007ce3ec + 0x194) * fVar16;

      fStack_c = param_1[5] * fVar17 + *(float *)(DAT_007ce3ec + 0x198) * fVar16;

      fStack_8 = param_1[6] * fVar17 + *(float *)(DAT_007ce3ec + 0x19c) * fVar16;

      fStack_4 = *(float *)(DAT_007ce3ec + 0x1a0) * fVar16 + param_1[7] * fVar17;

      pfVar4 = (float *)FUN_0019fd40();

      *pfVar4 = fStack_10;

      pfVar4[1] = fStack_c;

      pfVar4[2] = fStack_8;

      pfVar4[3] = fStack_4;

      fStack_10 = param_1[8] * fVar17 + *(float *)(DAT_007ce3ec + 0x1a4) * fVar16;

      fStack_c = param_1[9] * fVar17 + *(float *)(DAT_007ce3ec + 0x1a8) * fVar16;

      fStack_8 = param_1[10] * fVar17 + *(float *)(DAT_007ce3ec + 0x1ac) * fVar16;

      fStack_4 = *(float *)(DAT_007ce3ec + 0x1b0) * fVar16 + param_1[0xb] * fVar17;

      pfVar4 = (float *)FUN_0019fd70();

      *pfVar4 = fStack_10;

      pfVar4[1] = fStack_c;

      pfVar4[2] = fStack_8;

      pfVar4[3] = fStack_4;

      fVar10 = param_1[0xd];

      fVar14 = param_1[0xe];

      fVar11 = param_1[0xf];

      pfVar4 = (float *)(DAT_007ce3ec + 0x1f8);

      fVar12 = *(float *)(DAT_007ce3ec + 0x1fc);

      fVar8 = *(float *)(DAT_007ce3ec + 0x200);

      *(float *)(DAT_007ce3ec + 0x1c4) =

           param_1[0xc] * fVar17 + *(float *)(DAT_007ce3ec + 500) * fVar16;

      *(float *)(DAT_007ce3ec + 0x1c8) = fVar10 * fVar17 + *pfVar4 * fVar16;

      *(float *)(DAT_007ce3ec + 0x1cc) = fVar14 * fVar17 + fVar12 * fVar16;

      *(float *)(DAT_007ce3ec + 0x1d0) = fVar8 * fVar16 + fVar11 * fVar17;

      fVar10 = param_1[0x11];

      fVar14 = param_1[0x12];

      fVar11 = param_1[0x13];

      pfVar4 = (float *)(DAT_007ce3ec + 0x208);

      fVar12 = *(float *)(DAT_007ce3ec + 0x20c);

      fVar8 = *(float *)(DAT_007ce3ec + 0x210);

      *(float *)(DAT_007ce3ec + 0x1d4) =

           param_1[0x10] * fVar17 + *(float *)(DAT_007ce3ec + 0x204) * fVar16;

      *(float *)(DAT_007ce3ec + 0x1d8) = fVar10 * fVar17 + *pfVar4 * fVar16;

      *(float *)(DAT_007ce3ec + 0x1dc) = fVar14 * fVar17 + fVar12 * fVar16;

      *(float *)(DAT_007ce3ec + 0x1e0) = fVar8 * fVar16 + fVar11 * fVar17;

      }
      {
        float fVar8;

      fVar8 = DAT_007caf08;

      if ((*(u16 *)((u8 *)param_1 + 0x58) & 2) == 0) {

        for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {

          for (iVar7 = *(int *)(DAT_007ce3ec + uVar5 * 8 + 0x150); iVar7 != 0;

              iVar7 = *(int *)(iVar7 + 0xa34)) {

            *(char *)(iVar7 + 0x3c) =

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x38) * fVar17 + fStack_20 * fVar16)

                             * 255.0 + 0.5);

            *(char *)(iVar7 + 0x3d) =

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x39) * fVar17 + fStack_1c * fVar16)

                             * 255.0 + 0.5);

            *(char *)(iVar7 + 0x3e) =

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x3a) * fVar17 + fStack_18 * fVar16)

                             * 255.0 + 0.5);

            *(char *)(iVar7 + 0x3f) =

                 (char)(int)((fStack_14 * fVar16 + fVar8 * (float)*(u8 *)(iVar7 + 0x3b) * fVar17)

                             * 255.0 + 0.5);

            *(float *)(iVar7 + 0x70) = *(float *)(iVar7 + 0x60) * fVar17;

            *(float *)(iVar7 + 0x74) = *(float *)(iVar7 + 100) * fVar17;

            *(float *)(iVar7 + 0x78) = *(float *)(iVar7 + 0x68) * fVar17;
            *(float *)(iVar7 + 0x7c) = *(float *)(iVar7 + 0x6c) * fVar17;

          }

        }

      }
      *(u32 *)((u8 *)param_1 + 0x54) = *(u32 *)((u8 *)param_1 + 0x54) + 1;

      uVar9 = 0;

      }
    }

    else {
      u32 *puVar6;
      int iVar7;
      u32 uVar15;
      u32 uVar13;

      float fVar8;
      float fVar10;
      float fVar11;
      float fVar12;
      float fVar14;
      float fVar18;
      float fVar19;


      FUN_0019f8f0(&fStack_20);

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      *(float *)(DAT_007ce3ec + 0x224) = fStack_20;

      *(float *)(iVar7 + 0x228) = fStack_1c;

      *(float *)(iVar7 + 0x22c) = fStack_18;

      *(float *)(iVar7 + 0x230) = fStack_14;

      puVar6 = (u32 *)FUN_0019fd40();

      uVar15 = *(u32 *)(iVar7 + 0x198);

      uVar9 = *(u32 *)(iVar7 + 0x19c);
      uVar13 = *(u32 *)(iVar7 + 0x1a0);

      *puVar6 = *(u32 *)(iVar7 + 0x194);

      puVar6[1] = uVar15;

      puVar6[2] = uVar9;

      puVar6[3] = uVar13;

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      puVar6 = (u32 *)FUN_0019fd70();

      uVar15 = *(u32 *)(iVar7 + 0x1a8);

      uVar9 = *(u32 *)(iVar7 + 0x1ac);
      uVar13 = *(u32 *)(iVar7 + 0x1b0);

      *puVar6 = *(u32 *)(iVar7 + 0x1a4);

      puVar6[1] = uVar15;

      puVar6[2] = uVar9;

      puVar6[3] = uVar13;

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      puVar6 = (u32 *)(DAT_007ce3ec + 0x1f8);

      uVar9 = *(u32 *)(DAT_007ce3ec + 0x1fc);

      uVar13 = *(u32 *)(DAT_007ce3ec + 0x200);

      *(u32 *)(DAT_007ce3ec + 0x1c4) = *(u32 *)(DAT_007ce3ec + 500);

      *(u32 *)(iVar7 + 0x1c8) = *puVar6;

      *(u32 *)(iVar7 + 0x1cc) = uVar9;

      *(u32 *)(iVar7 + 0x1d0) = uVar13;

      *(u32 *)(iVar7 + 0x1d4) = *(u32 *)(iVar7 + 0x204);

      *(u32 *)(iVar7 + 0x1d8) = *(u32 *)(iVar7 + 0x208);

      *(u32 *)(iVar7 + 0x1dc) = *(u32 *)(iVar7 + 0x20c);

      *(u32 *)(iVar7 + 0x1e0) = *(u32 *)(iVar7 + 0x210);

      if ((*(u16 *)((u8 *)param_1 + 0x58) & 2) == 0) {
        u32 uVar5;
        u8 bVar1;
        u8 bVar2;
        u8 bVar3;

        fVar8 = DAT_007caf08 * (float)DAT_007ce4f8[0];

        fVar10 = DAT_007caf08 * (float)DAT_007ce4f9;

        fVar14 = DAT_007caf08 * (float)DAT_007ce4fa;

        fVar11 = DAT_007caf08 * (float)DAT_007ce4fb;

        for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {

          for (iVar7 = *(int *)(DAT_007ce3ec + uVar5 * 8 + 0x150); bVar3 = DAT_007cc973,

              bVar2 = DAT_007cc972, bVar1 = DAT_007cc971, iVar7 != 0;

              iVar7 = *(int *)(iVar7 + 0xa34)) {

            *(u8 *)(iVar7 + 0x3c) = DAT_007cc970;

            *(u8 *)(iVar7 + 0x3d) = bVar1;

            *(u8 *)(iVar7 + 0x3e) = bVar2;

            *(u8 *)(iVar7 + 0x3f) = bVar3;

            *(float *)(iVar7 + 0x70) = fVar8;

            *(float *)(iVar7 + 0x74) = fVar10;

            *(float *)(iVar7 + 0x78) = fVar14;

            *(float *)(iVar7 + 0x7c) = fVar11;

          }

      }
      }

      fVar18 = DAT_007caf88;
      fVar19 = DAT_007caee8;

      if ((*(u16 *)((u8 *)param_1 + 0x58) & 4) == 0) {
        u32 uVar5;
        u8 bVar1;
        u8 bVar2;
        u8 bVar3;

        for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {

          for (iVar7 = *(int *)(DAT_007ce3ec + uVar5 * 8 + 0x150); iVar7 != 0;

              iVar7 = *(int *)(iVar7 + 0xa34)) {

            if ((*(u32 *)(iVar7 + 0x98) & 2) != 0) {

              bVar1 = *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388);

              if ((bVar1 & 0x10) == 0) {

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) = bVar1 & 0xfa;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) =

                     *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x388) | 2;

                *(float *)(*(int *)(iVar7 + 0x9f4) + 0x39c) =

                     *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3a0) * 1.25;

                *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3a4) = fVar18;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a8) = 0;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a9) = 0xa0;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3aa) = 6;

                *(u32 *)(*(int *)(iVar7 + 0x9f4) + 0x3ac) = 0x3f800000;

                *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3b0) = fVar19;

                if (1.0 < *(float *)(*(int *)(iVar7 + 0x9f4) + 0x39c)) {

                  *(u32 *)(*(int *)(iVar7 + 0x9f4) + 0x39c) = 0x3f800000;

                }

              }

            }

          }

        }

      }

      uVar9 = 1;

    }

  }

  return uVar9;

}
// FUN_002A10E0 NONMATCHING


u8 FUN_002a10e0(BtlMainLerpWork *param_1)
{
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 results[4];
    f32 target0;
    f32 target1;
    f32 target2;
    f32 target3;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    if (param_1->currentFrame == 0)
    {
        global = (u8*)iGpffffb6fc;
        target0 = *(f32*)(global + 0x234);
        target1 = *(f32*)(global + 0x238);
        target2 = *(f32*)(global + 0x23c);
        target3 = *(f32*)(global + 0x240);
        param_1->target0 = target0;
        param_1->target1 = target1;
        param_1->target2 = target2;
        param_1->target3 = target3;
    }

    totalFrames = param_1->totalFrames;
    currentFrame = param_1->currentFrame;
    if (currentFrame < totalFrames)
    {
        if ((s32)currentFrame >= 0)
        {
            currentFloat = (f32)currentFrame;
        }
        else
        {
            currentFloat = (f32)(currentFrame >> 1);
            currentFloat += currentFloat;
        }

        if ((s32)totalFrames >= 0)
        {
            totalFloat = (f32)totalFrames;
        }
        else
        {
            totalFloat = (f32)(totalFrames >> 1);
            totalFloat += totalFloat;
        }

        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results[0] = param_1->target0 * inverse + param_1->value0 * ratio;
        results[1] = param_1->target1 * inverse + param_1->value1 * ratio;
        results[2] = param_1->target2 * inverse + param_1->value2 * ratio;
        results[3] = param_1->target3 * inverse + param_1->value3 * ratio;
        global = (u8*)iGpffffb6fc;
        *(f32*)(global + 0x234) = results[0];
        *(f32*)(global + 0x238) = results[1];
        *(f32*)(global + 0x23c) = results[2];
        *(f32*)(global + 0x240) = results[3];
        param_1->currentFrame++;
        return 0;
    }

    global = (u8*)iGpffffb6fc;
    *(f32*)(global + 0x234) = param_1->value0;
    *(f32*)(global + 0x238) = param_1->value1;
    *(f32*)(global + 0x23c) = param_1->value2;
    *(f32*)(global + 0x240) = param_1->value3;
    return 1;
}













// FUN_002A1400 NONMATCHING
u8 FUN_002a1400(float *param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  if (param_1[5] == 0.0) {

    fVar6 = *(float *)(iGpffffb6fc + 0x238);

    fVar1 = *(float *)(iGpffffb6fc + 0x23c);

    fVar4 = *(float *)(iGpffffb6fc + 0x240);

    *param_1 = *(float *)(iGpffffb6fc + 0x234);

    param_1[1] = fVar6;

    param_1[2] = fVar1;

    param_1[3] = fVar4;

  }

  fVar1 = param_1[4];

  fVar4 = param_1[5];

  if ((u32)fVar1 <= (u32)fVar4) {

    *(float *)(iGpffffb6fc + 0x234) = fGpffff8218 * (float)bGpffffb808;

    *(float *)(iGpffffb6fc + 0x238) = fGpffff8218 * (float)bGpffffb809;

    *(float *)(iGpffffb6fc + 0x23c) = fGpffff8218 * (float)bGpffffb80a;

    *(float *)(iGpffffb6fc + 0x240) = fGpffff8218 * (float)bGpffffb80b;

  }

  else {

    fVar5 = (float)(u32)fVar4 / (float)(u32)fVar1;

    fVar7 = 1.0 - fVar5;

    fVar6 = param_1[1];

    fVar2 = param_1[2];

    fVar3 = param_1[3];

    *(float *)(iGpffffb6fc + 0x234) = *param_1 * fVar7 + fGpffff8218 * (float)bGpffffb808 * fVar5;

    *(float *)(iGpffffb6fc + 0x238) = fVar6 * fVar7 + fGpffff8218 * (float)bGpffffb809 * fVar5;

    *(float *)(iGpffffb6fc + 0x23c) = fVar2 * fVar7 + fGpffff8218 * (float)bGpffffb80a * fVar5;

    *(float *)(iGpffffb6fc + 0x240) = fVar3 * fVar7 + fGpffff8218 * (float)bGpffffb80b * fVar5;

    param_1[5] = (float)((int)param_1[5] + 1);

  }

  return (u32)fVar1 <= (u32)fVar4;

}

// FUN_002A1710 NONMATCHING


u32 FUN_002a1710(int *param_1)
{
  int iVar1;
  int iVar2;
  u8 bVar3;
  u32 uVar4;
  long lVar5;
  u32 uVar6;
  u32 uVar7;
  u8 uVar8;
  float fVar9;
  u32 uStack_8;
  u32 uStack_4;
  uVar7 = 1;
  iVar1 = *param_1;
  if ((*(u32 *)(iGpffffb6fc + 0x10) & 8) == 0) {
    if (*(char *)(((u32)*(u16 *)(param_1 + 3) * 10 + (u32)*(u16 *)(param_1 + 3)) * 4 +
                  iGpffffb708 + 0x11) == '\x10') {
      uVar7 = 1;
    }
    else if ((*(u16 *)(iVar1 + 0x6a) < 2) && (*(char *)(*(int *)(iVar1 + 0x30) + 0xa2) != '\0'))
    {
      uVar7 = 1;
    }
    else {
      lVar5 = FUN_002d6290(iVar1);
      if (lVar5 == 0) {
        uVar4 = 3;
      }
      else {
        uVar4 = 1 << (*(u8 *)(*(int *)(iVar1 + 0x30) + 0xa2) & 0x1f) & 0xffff;
      }
      if (*(char *)(*(int *)(iVar1 + 0x30) + 0xa2) == '\0') {
        bVar3 = 1;
        for (uVar6 = 0; uVar6 < *(u16 *)(iVar1 + 0x6a); uVar6 = uVar6 + 1 & 0xffff) {
          if (*(char *)(*(int *)(*(int *)(iVar1 + uVar6 * 4 + 0x38) + 0x30) + 0xa2) != '\0') {
            bVar3 = 0;
            break;
          }
        }
        if (bVar3) {
          return 1;
        }
      }
      if ((u32)param_1[2] < (u32)param_1[1]) {
        fVar9 = (1.0 - (float)(u32)param_1[2] / (float)(u32)param_1[1]) * 255.0;
        if (2.1474836e+09 <= fVar9) {
          fVar9 = fVar9 - 2.1474836e+09;
        }
        uVar8 = (u8)(int)fVar9;
        uVar7 = 0;
      }
      else {
        uVar8 = 0;
      }
      for (uVar6 = 0; uVar6 < 2; uVar6 = uVar6 + 1 & 0xffff) {
        for (iVar2 = *(int *)(iGpffffb6fc + uVar6 * 8 + 0x150); iVar2 != 0;
            iVar2 = *(int *)(iVar2 + 0xa34)) {
          if (((((uVar4 & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0) &&
               (*(short *)(iVar2 + 0x9f2) != 0)) && ((*(u32 *)(iVar2 + 0x9c) & 1) == 0)) &&
             (iVar2 != *(int *)(iVar1 + 0x30))) {
            uStack_4 = ((((u32)(uVar8) & 0xffu) << 24) | ((u32)(*(u32 *)(iVar2 + 0x30) & 0x00ffffffu) & 0x00ffffffu));
            FUN_0027f730(iVar2,uStack_4);
          }
        }
      }
      for (uVar4 = 0; uVar4 < *(u16 *)(iVar1 + 0x6a); uVar4 = uVar4 + 1 & 0xffff) {
        iVar2 = *(int *)(*(int *)(iVar1 + uVar4 * 4 + 0x38) + 0x30);
        uStack_8 = ((((u32)(0xff) & 0xffu) << 24) | ((u32)(*(u32 *)(iVar2 + 0x30) & 0x00ffffffu) & 0x00ffffffu));
        FUN_0027f730(iVar2,uStack_8);
      }
      param_1[2] = param_1[2] + 1;
    }
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}

// FUN_002A1B00


void FUN_002a1b00(s32 param_1,s16 param_2,s32 param_3)
{
    BtlPacket* packet;
    u8* work;
    packet = btlPacketCreate(0x606, 0x10);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a1710;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = param_1;
    *(s32*)(work + 4) = param_3;
    *(s16*)(work + 0xc) = param_2;
    *(s32*)(work + 8) = 0;
}

// FUN_002A1B70 NONMATCHING


u32 FUN_002a1b70(u32 *param_1)
{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  float fVar5;
  u32 uStack_4;
  if (((*(u32 *)(iGpffffb6fc + 0xc) & 0x400000) == 0) ||
     ((*(u16 *)(iGpffffb6fc + 0x18) & 0x10) == 0)) {
    uVar2 = 1;
    if (param_1[1] < *param_1) {
      fVar5 = ((float)param_1[1] / (float)*param_1) * 255.0;
      if (2.1474836e+09 <= fVar5) {
        fVar5 = fVar5 - 2.1474836e+09;
      }
      uVar3 = (int)fVar5 & 0xff;
      uVar2 = 0;
    }
    else {
      uVar3 = 0xff;
    }
    for (uVar4 = 0; uVar4 < 2; uVar4 = uVar4 + 1 & 0xffff) {
      for (iVar1 = *(int *)(iGpffffb6fc + uVar4 * 8 + 0x150); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0xa34)) {
        if (((*(short *)(iVar1 + 0x9f2) != 0) && ((*(u32 *)(iVar1 + 0x9c) & 1) == 0)) &&
           (*(u8 *)(iVar1 + 0x33) < uVar3)) {
          uStack_4 = ((((u32)((char)uVar3) & 0xffu) << 24) | ((u32)(*(u32 *)(iVar1 + 0x30) & 0x00ffffffu) & 0x00ffffffu));
          FUN_0027f730(iVar1,uStack_4);
        }
      }
    }
    param_1[1] = param_1[1] + 1;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

// FUN_002A1DB0


void FUN_002a1db0(s32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x607, 8);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a1b70;
    *(s32*)packet->workData = param_1;
}

// FUN_002A1E00 NONMATCHING


void FUN_002a1e00(float param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  int iStack_c;

  

  fVar5 = 1.0 - param_1;

  fVar1 = param_3[1];

  fVar2 = param_3[2];

  fVar3 = param_4[1];

  fVar4 = param_4[2];

  *param_2 = *param_3 * fVar5 + *param_4 * param_1;

  param_2[1] = fVar1 * fVar5 + fVar3 * param_1;

  param_2[2] = fVar2 * fVar5 + fVar4 * param_1;

  FUN_004be310(param_3 + 3,param_4 + 3,&fStack_30);

  if (param_1 <= 0.0) {

    fVar3 = param_3[4];

    fVar1 = param_3[5];

    fVar2 = param_3[6];

    param_2[3] = param_3[3];

    param_2[4] = fVar3;

    param_2[5] = fVar1;

    param_2[6] = fVar2;

  }

  else if (1.0 <= param_1) {

    fVar3 = param_4[4];

    fVar1 = param_4[5];

    fVar2 = param_4[6];

    param_2[3] = param_4[3];

    param_2[4] = fVar3;

    param_2[5] = fVar1;

    param_2[6] = fVar2;

  }

  else {

    if (iStack_c == 0) {

      fVar5 = fVar5 * fStack_10;

      fVar1 = fVar5 * fVar5;

      fVar5 = fVar1 * fVar5 *

              (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fGpffff8044 * fVar1 + fGpffff8048 + 0.0) +

                                         fGpffff804c + 0.0) + fGpffff8050 + 0.0) + fGpffff8054 + 0.0

                       ) + fGpffff8058 + 0.0) + fVar5 + 0.0;

      param_1 = param_1 * fStack_10;

      fVar1 = param_1 * param_1;

      param_1 = fVar1 * param_1 *

                (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fGpffff8044 * fVar1 + fGpffff8048 + 0.0) +

                                           fGpffff804c + 0.0) + fGpffff8050 + 0.0) +

                         fGpffff8054 + 0.0) + fGpffff8058 + 0.0) + param_1 + 0.0;

    }

    param_2[3] = fStack_30 * fVar5;

    param_2[4] = fStack_2c * fVar5;

    param_2[5] = fStack_28 * fVar5;

    param_2[3] = fStack_20 * param_1 + param_2[3] + 0.0;

    param_2[4] = fStack_1c * param_1 + param_2[4] + 0.0;

    param_2[5] = fStack_18 * param_1 + param_2[5] + 0.0;

    param_2[6] = fStack_24 * fVar5 + fStack_14 * param_1;

  }

  return;

}

// FUN_002A2050


u32 FUN_002a2050(u16 *param_1,f32 *param_2,f32 *param_3)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    if (param_1[0x3b] >= 4)
    {
        return 0;
    }
    index = param_1[0x3c];
    if (param_2 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 4);
        value2 = param_2[0];
        value3 = param_2[1];
        value1 = param_2[2];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value1;
        if ((*param_1 & 1) == 0)
        {
            FUN_0048d370(*(u32*)(param_1 + 0x4c), index, param_2);
        }
    }
    if (param_3 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 0x10);
        value2 = param_3[0];
        value3 = param_3[1];
        value4 = param_3[2];
        value1 = param_3[3];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value4;
        entry[3] = value1;
    }
    index++;
    if (index >= 4)
    {
        index = 0;
    }
    param_1[0x3c] = index;
    param_1[0x3b]++;
    return 1;
}

// FUN_002A2170


void FUN_002a2170(u16 *param_1,f32 *param_2)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    *param_1 = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                FUN_0048d370(*(u32*)((u8*)param_1 + 0x98), index, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }
}

// FUN_002A2290 NONMATCHING


void FUN_002a2290(u16 *param_1,long param_2,long param_3,u16 param_4)



{

  u16 uVar1;

  u32 *puVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  *param_1 = param_4;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_2;

    if (param_2 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_2);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }


  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    if ((u8*)0 != (u8 *)0x20) {

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = uStack_20;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uStack_1c;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uStack_18;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c));

      }

    }

    if ((u8*)0 != (u8 *)0x14) {

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = uStack_14;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uStack_10;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uStack_c;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uStack_8;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }


  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    if ((u8*)0 != (u8 *)0x20) {

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = uStack_20;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uStack_1c;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uStack_18;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c));

      }

    }

    if ((u8*)0 != (u8 *)0x14) {

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = uStack_14;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uStack_10;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uStack_c;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uStack_8;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_3;

    if (param_3 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_3);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  return;

}

// FUN_002A2660 NONMATCHING


void FUN_002a2660(u16 *param_1,long param_2,long param_3,long param_4,long param_5,u16 param_6

                 )



{

  u16 uVar1;

  u32 *puVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  

  *param_1 = param_6;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_2;

    if (param_2 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_2);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_3;

    if (param_3 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_3);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_4;

    if (param_4 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_4);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  if (param_1[0x3b] < 4) {

    uVar1 = param_1[0x3c];

    puVar2 = (u32 *)param_5;

    if (param_5 != 0) {

      uVar3 = puVar2[1];

      uVar4 = puVar2[2];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 2) = *puVar2;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 4) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 6) = uVar4;

      if ((*param_1 & 1) == 0) {

        FUN_0048d370(*(u32 *)(param_1 + 0x4c),uVar1,param_5);

      }

    }

    if (puVar2 + 3 != (u32 *)0x0) {

      uVar5 = puVar2[4];

      uVar3 = puVar2[5];

      uVar4 = puVar2[6];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 8) = puVar2[3];

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 10) = uVar5;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xc) = uVar3;

      *(u32 *)(param_1 + (u32)uVar1 * 0xe + 0xe) = uVar4;

    }

    uVar1 = uVar1 + 1;

    if (3 < uVar1) {

      uVar1 = 0;

    }

    param_1[0x3c] = uVar1;

    param_1[0x3b] = param_1[0x3b] + 1;

  }

  return;

}

// FUN_002A2A20 NONMATCHING


void FUN_002a2a20(u8* param_2,f32* param_3,f32 param_1)
{
  u8* iVar1;
  u16 uVar3;
  u16 uVar2;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float afStack_10 [4];
  fVar6 = 1.0f - param_1;
  fVar7 = fVar6 * fVar6;
  afStack_10[0] = fVar6 * fVar7;
  afStack_10[1] = param_1 * fVar7 * 3.0f;
  fVar8 = param_1 * param_1;
  afStack_10[2] = fVar6 * fVar8 * 3.0f;
  afStack_10[3] = param_1 * fVar8;
  uVar2 = *(u16 *)(param_2 + 0x74);
  fVar4 = *(f32*)0x00957180;
  fVar5 = *(f32*)0x00957184;
  fVar9 = *(f32*)0x00957188;
  *param_3 = fVar4;
  param_3[1] = fVar5;
  param_3[2] = fVar9;
  for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1 & 0xffff) {
    fVar6 = afStack_10[uVar3];
    iVar1 = param_2 + uVar2 * 0x1c;
    fVar4 = *(float *)(iVar1 + 8);
    fVar5 = *(float *)(iVar1 + 0xc);
    *param_3 = *(float *)(iVar1 + 4) * fVar6 + *param_3 + 0.0f;
    param_3[1] = param_3[1] + fVar4 * fVar6;
    param_3[2] = param_3[2] + fVar5 * fVar6;
    uVar2 = uVar2 + 1 & 0xffff;
    if (3 < uVar2) {
      uVar2 = 0;
    }
  }
  return;
}

// FUN_002A2B50


void FUN_002a2b50(u8* param_2, f32* param_3, f32 param_1)
{
    u16 currentIndex;
    u16 nextIndex;
    u32 currentAddress;
    u32 nextAddress;
    f32 currentX;
    f32 currentY;
    f32 currentZ;
    f32 nextX;
    f32 nextY;
    f32 nextZ;
    f32 blend;
    f32 period;
    currentIndex = *(u16*)(param_2 + 0x74);
    period = fGpffff82c8;
    while (param_1 >= period)
    {
        currentIndex++;
        param_1 -= period;
    }
    param_1 /= period;
    if (currentIndex >= 4)
    {
        currentIndex &= 3;
    }
    nextIndex = currentIndex + 1;
    if (nextIndex >= 4)
    {
        nextIndex &= 3;
    }
    blend = 1.0f - param_1;
    currentAddress = (u32)currentIndex * 0x1c;
    currentAddress = currentAddress + (u32)param_2;
    currentY = *(f32*)(currentAddress + 8);
    currentY = currentY * blend;
    currentZ = *(f32*)(currentAddress + 0xc);
    currentZ = currentZ * blend;
    nextAddress = (u32)nextIndex * 0x1c;
    nextAddress = nextAddress + (u32)param_2;
    nextY = *(f32*)(nextAddress + 8);
    nextY = nextY * param_1;
    nextZ = *(f32*)(nextAddress + 0xc);
    nextZ = nextZ * param_1;
    currentX = *(f32*)(currentAddress + 4);
    nextX = *(f32*)(nextAddress + 4);
    param_3[0] = currentX * blend + nextX * param_1;
    param_3[1] = currentY + nextY;
    param_3[2] = currentZ + nextZ;
}

// FUN_002A2C40 NONMATCHING


void FUN_002a2c40(u8* param_2,f32* param_3,f32 param_1)
{
  u8* iVar1;
  u32 uVar2;
  u32 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  uVar3 = (u32)*(u16 *)(param_2 + 0x74);
  for (; fGpffff82c8 <= param_1; param_1 = param_1 - fGpffff82c8) {
    uVar3 = uVar3 + 1 & 0xffff;
  }
  param_1 = param_1 / fGpffff82c8;
  if (3 < uVar3) {
    uVar3 = uVar3 & 3;
  }
  uVar2 = uVar3 + 1 & 0xffff;
  if (3 < uVar2) {
    uVar2 = uVar3 + 1 & 3;
  }
  iVar1 = param_2 + uVar2 * 0x1c;
  param_2 = param_2 + uVar3 * 0x1c;
  FUN_004be310((float *)(param_2 + 0x10),(float *)(iVar1 + 0x10),&fStack_30);
  if (param_1 <= 0.0) {
    fVar6 = *(float *)(param_2 + 0x14);
    fVar4 = *(float *)(param_2 + 0x18);
    fVar5 = *(float *)(param_2 + 0x1c);
    *param_3 = *(float *)(param_2 + 0x10);
    param_3[1] = fVar6;
    param_3[2] = fVar4;
    param_3[3] = fVar5;
  }
  else if (1.0 <= param_1) {
    fVar6 = *(float *)(iVar1 + 0x14);
    fVar4 = *(float *)(iVar1 + 0x18);
    fVar5 = *(float *)(iVar1 + 0x1c);
    *param_3 = *(float *)(iVar1 + 0x10);
    param_3[1] = fVar6;
    param_3[2] = fVar4;
    param_3[3] = fVar5;
  }
  else {
    fVar4 = 1.0 - param_1;
    if (iStack_c == 0) {
      fVar4 = fVar4 * fStack_10;
      fVar5 = fVar4 * fVar4;
      fVar4 = fVar5 * fVar4 *
              (fVar5 * (fVar5 * (fVar5 * (fVar5 * (fGpffff83d4 * fVar5 + fGpffff8048 + 0.0) +
                                         fGpffff8118 + 0.0) + fGpffff8050 + 0.0) + fGpffff8054 + 0.0
                       ) + fGpffff83d8 + 0.0) + fVar4 + 0.0;
      param_1 = param_1 * fStack_10;
      fVar5 = param_1 * param_1;
      param_1 = fVar5 * param_1 *
                (fVar5 * (fVar5 * (fVar5 * (fVar5 * (fGpffff83d4 * fVar5 + fGpffff8048 + 0.0) +
                                           fGpffff8118 + 0.0) + fGpffff8050 + 0.0) +
                         fGpffff8054 + 0.0) + fGpffff83d8 + 0.0) + param_1 + 0.0;
    }
    *param_3 = fStack_30 * fVar4;
    param_3[1] = fStack_2c * fVar4;
    param_3[2] = fStack_28 * fVar4;
    *param_3 = fStack_20 * param_1 + *param_3 + 0.0;
    param_3[1] = fStack_1c * param_1 + param_3[1] + 0.0;
    param_3[2] = fStack_18 * param_1 + param_3[2] + 0.0;
    param_3[3] = fStack_24 * fVar4 + fStack_14 * param_1;
  }
  return;
}

// FUN_002A2ED0


u32 FUN_002a2ed0(u8* param_1,f32* param_2,f32* param_3)
{
    void* curve;
    u16 frame;
    u16 index;
    u8* entry;
    frame = *(u16*)(param_1 + 0x76);
    if (0 < frame)
    {
        goto has_frame;
    }
    return 0;
has_frame:
    if (frame < 2)
    {
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV3d *)param_2 = *(RwV3d *)(entry + 4);
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV4d *)param_3 = *(RwV4d *)(entry + 0x10);
        return 0;
    }
    if (frame < 4)
    {
        FUN_002a2b50(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else if ((*(u16*)param_1 & 1) != 0)
    {
        FUN_002a2a20(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else
    {
        curve = *(void* volatile *)(param_1 + 0x98);
        FUN_0048d480((void*)curve, 0xa,
                     *(f32*)(param_1 + 0x7c),
                     (RwV3d *)param_2, ((void*)0));
    }
    FUN_002a2c40(param_1, param_3, *(f32*)(param_1 + 0x7c));
    return 1;
}

// FUN_002A3010


u32 FUN_002a3010(u8* param_2,f32 param_1)
{
    u16 frame;
    u16 counter;
    u32 result;
    f32 value;
    frame = *(u16*)(param_2 + 0x76);
    if (frame < 2)
    {
        *(u32*)(param_2 + 0x7c) = 0;
        return 0;
    }
    value = *(f32*)(param_2 + 0x7c) + param_1;
    if (frame < 3)
    {
        if (!(value < fGpffff82c8))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 1;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 1;
        }
    }
    else if (frame < 4)
    {
        if (!(value < fGpffff805c))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 2;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 2;
        }
    }
    else if (!(value < fGpffff83d0))
    {
        value = value - 1.0f;
        *(u16*)(param_2 + 0x76) = frame - 3;
        *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 3;
    }
    counter = *(u16*)(param_2 + 0x74);
    if (counter >= 4)
    {
        *(u16*)(param_2 + 0x74) = counter & 3;
    }
    *(f32*)(param_2 + 0x7c) = value;
    result = 1;
    return result;
}

// FUN_002A3110


void FUN_002a3110(u8* param_2,float param_1)
{
    *(f32*)(param_2 + 0x84) = (param_1 * 2.0f * 60.0f) / 2.0f;
    *(u32*)(param_2 + 0x94) = 0x3f000000;
    *(u16*)param_2 = *(u16*)param_2 & 0xfffd;
    *(u16*)param_2 = *(u16*)param_2 | 4;
}

// FUN_002A3160


void FUN_002a3160(u8* param_2,float param_1)
{
    *(f32*)(param_2 + 0x84) = (param_1 * 60.0f) / 2.0f;
    *(u16*)param_2 = *(u16*)param_2 & 0xfffd;
    *(u16*)param_2 = *(u16*)param_2 & 0xfffb;
}

/* Recovered battle-misc harvest: 0x0029F4B0-0x002A16C0 */




















// FUN_0029F4B0
void FUN_0029f4b0(u32 param_1,u32 param_2,u32 param_3)
{
    float *color;
    int packet;
    union { u32 value; u8 bytes[4]; } packed;

    packet = FUN_0027ec10(0x600, 0x68);
    *(code **)(packet + 0x6c) = (code *)FUN_0029f150;
    color = *(float **)(packet + 0x78);
    packed.value = param_1;
    color[0] = DAT_007caf08 * (float)packed.bytes[0];
    color[1] = DAT_007caf08 * (float)packed.bytes[1];
    color[2] = DAT_007caf08 * (float)packed.bytes[2];
    color[3] = DAT_007caf08 * (float)packed.bytes[3];
    packed.value = param_2;
    color[4] = DAT_007caf08 * (float)packed.bytes[0];
    color[5] = DAT_007caf08 * (float)packed.bytes[1];
    color[6] = DAT_007caf08 * (float)packed.bytes[2];
    color[7] = DAT_007caf08 * (float)packed.bytes[3];
    *(u32*)((u8*)color + 0x60) = param_3;
}

// FUN_0029FA50


BtlPacket* FUN_0029fa50(u32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x601, 0x28);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_0029f760;
    *(u32*)((u8*)packet->workData + 0x20) = param_1;
    return packet;
}





























// FUN_002A0050 NONMATCHING
void FUN_002a0050(u32 param_1,u32 param_2,u32 param_3,float param_4,u16 param_5)



{

  float *pfVar1;

  int iVar2;

  

  iVar2 = (int)FUN_0027ec10(0x602,0x6c);


  pfVar1 = *(float **)(iVar2 + 0x78);

  *pfVar1 = DAT_007caf08 * (float)(param_1 & 0xff);

  pfVar1[1] = DAT_007caf08 * (float)(param_1 >> 8 & 0xff);

  pfVar1[2] = DAT_007caf08 * (float)(param_1 >> 0x10 & 0xff);

  pfVar1[3] = DAT_007caf08 * (float)(param_1 >> 0x18);

  pfVar1[8] = DAT_007caf08 * (float)(param_2 & 0xff);

  pfVar1[9] = DAT_007caf08 * (float)(param_2 >> 8 & 0xff);

  pfVar1[10] = DAT_007caf08 * (float)(param_2 >> 0x10 & 0xff);

  pfVar1[0xb] = DAT_007caf08 * (float)(param_2 >> 0x18);

  pfVar1[0x10] = DAT_007caf08 * (float)(param_3 & 0xff);

  pfVar1[0x11] = DAT_007caf08 * (float)(param_3 >> 8 & 0xff);

  pfVar1[0x12] = DAT_007caf08 * (float)(param_3 >> 0x10 & 0xff);

  pfVar1[0x13] = DAT_007caf08 * (float)(param_3 >> 0x18);

  pfVar1[0x18] = param_4;

  *(u16 *)(pfVar1 + 0x1a) = param_5;

  return;

}

// FUN_002A1080


BtlPacket* FUN_002a1080(s32 param_1, s16 param_2)
{
    BtlPacket* packet;
    u8* work;
    packet = btlPacketCreate(0x603, 0x5c);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a0440;
    work = (u8*)packet->workData;
    *(s32*)(work + 0x50) = param_1;
    *(s16*)(work + 0x58) = param_2;
    return packet;
}













// FUN_002A1280
void FUN_002a1280(u32 param_1,u32 param_2)
{
    float *color;
    u32 packed;
    int packet;
    packet = (int)FUN_0027ec10(0x604, 0x28);
    *(code **)(packet + 0x6c) = (code *)FUN_002a10e0;
    color = *(float **)(packet + 0x78);
    packed = param_1;
    color[0] = fGpffff8218 * (float)((u8*)&packed)[0];
    color[1] = fGpffff8218 * (float)((u8*)&packed)[1];
    color[2] = fGpffff8218 * (float)((u8*)&packed)[2];
    color[3] = fGpffff8218 * (float)((u8*)&packed)[3];
    *(u32*)((u8*)color + 0x20) = param_2;
}

// FUN_002A16C0


BtlPacket* FUN_002a16c0(s32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x605, 0x18);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a1400;
    *(s32*)((u8*)packet->workData + 0x10) = param_1;
    return packet;
}
