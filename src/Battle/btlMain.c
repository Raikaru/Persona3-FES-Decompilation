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

void FUN_003b5ab0();
#pragma alias btlMainDrawColorOverlay btlMain0029e4b0


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0029ee20(u32 param_1);
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
BtlPacket* FUN_0029f4b0(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_0029f760(float *param_1);
BtlPacket* FUN_0029fa50(u32 param_1);
u32 FUN_0029faa0(BtlMainColorWork *param_1);
BtlPacket* FUN_002a0050(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u16 param_5);
u32 FUN_002a0440(float *param_1);
BtlPacket* FUN_002a1080(s32 param_1, s16 param_2);
u8 FUN_002a10e0(BtlMainLerpWork *param_1);
BtlPacket* FUN_002a1280(u32 param_1,u32 param_2);
u8 FUN_002a1400(float *param_1);
BtlPacket* FUN_002a16c0(s32 param_1);
u32 FUN_002a1710(int *param_1);
void FUN_002a1b00(s32 param_1,s16 param_2,s32 param_3);
u32 FUN_002a1b70(u32 *param_1);
void FUN_002a1db0(s32 param_1);
void FUN_002a1e00(float *param_2,float *param_3,float *param_4,float param_1);
extern void FUN_002a1e00_typed(f32* out, f32* first, f32* second, f32 weight);
u32 FUN_002a2050(u16 *param_1,f32 *param_2,f32 *param_3);
void FUN_002a2170(u16 *param_1,f32 *param_2);
void FUN_002a2290(u16 *param_1,f32 *param_2,f32 *param_3,u16 param_4);
void FUN_002a2660(u16 *ring,u32 rec0,u32 rec1,u32 rec2,u32 rec3,u16 flags);
void FUN_002a2a20(u8* param_2,f32* param_3,f32 param_1);
void FUN_002a2b50(u8* param_2, f32* param_3, f32 param_1);
void FUN_002a2c40(u8* param_2,f32* param_3,f32 param_1);
u32 FUN_002a2ed0(u8* param_1,f32* param_2,f32* param_3);
u32 FUN_002a3010(u8* param_2,f32 param_1);
void FUN_002a3110(u8* param_2,float param_1);
void FUN_002a3160(u8* param_2,float param_1);
extern f32 DAT_00693850[];
extern f32 DAT_00693854[];
extern f32 DAT_00693858[];
extern f32 DAT_0069385c[];
extern f32 DAT_00693860[];
extern f32 DAT_00693864[];
extern f32 DAT_00693868[];
extern f32 DAT_00697880;
extern f32 DAT_00697888;
extern f32 DAT_00697884;
#pragma alias DAT_00697880_abs DAT_00697880
extern f32 DAT_00697880_abs[];
extern f32 DAT_007caee8;
extern f32 DAT_007caf08;
extern f32 DAT_007caf88;
extern f32 DAT_007cafbc;
extern u8 DAT_007cc970;
extern u8 DAT_007cc972;
extern u8 DAT_007cc971;
extern u8 DAT_007ce4f9;
extern u8 DAT_007ce4fa;
extern u8 DAT_007ce4fb;
extern u8 DAT_007cc973;
extern u8* DAT_007ce3ec;
extern f32 DAT_00957180;
extern f32 DAT_00957184;
extern f32 DAT_00957188;
#pragma alias DAT_00957180_abs DAT_00957180
#pragma alias DAT_00957184_abs DAT_00957184
#pragma alias DAT_00957188_abs DAT_00957188
extern u8 DAT_00957180_abs[];
extern u8 DAT_00957184_abs[];
extern u8 DAT_00957188_abs[];
extern u32 DAT_009572b0;
extern u32 DAT_009572b4;
extern u32 DAT_009572b8;
extern u32 DAT_009572bc;
extern u32 DAT_009572c0;
extern u32 DAT_009572c4;
extern u32 DAT_009572c8;
extern u32 DAT_009572cc;
extern u32 DAT_009572d0;
extern f32 _DAT_0069386c[];
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
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
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
#pragma alias DAT_00960090_abs DAT_00960090
extern void (*DAT_00960090_abs[])(u32 state, u32 value);
#pragma alias DAT_009600A0_abs DAT_009600A0
extern void (*DAT_009600A0_abs[])(u32 primitive, void* vertices, u32 count);

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


static void btlMainRegisterDependentPacket(BtlPacket* packet, u8 type, u64 parentUID)
{
    packet->unk_00 = 4;
    packet->parentUID = parentUID;
    btlPacketRegister(packet, type);
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
    DatUnit* enemy;
    Model* model;
    u64 modelPacketUID;
    u64 targetMask;
    u32 encountFlags;
    u16 battleMode;
    u16 threshold;
    u32 i;
    u32 j;
    u32 useSpecialFormation;
    modelPacketUID = 0;
    i = 0;
    while (i < 4 && gBtl->startInfo.partyUnits[i] != ((void*)0))
    {
        u16 charId = gBtl->startInfo.partyUnits[i]->base.unit->id;
        action = FUN_00289650(0, charId);
        unit = action->unit;
        model = FUN_00316910(unit->genus + 1, charId, 0);
        unit->mdl = model;
        if (model == ((void*)0))
        {
            packet = FUN_00285690(unit, charId, 0x36);
            packet->unk_00 = 4;
            packet->parentUID = modelPacketUID;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            modelPacketUID = packet->uid;
        }
        else
        {
            unit->flags2 |= 2;
            unit->flags2 |= 8;
            unit->resTypeId = FUN_003b6000(charId, model);
            FUN_001a0590(unit->resTypeId, 1);
            FUN_00287b20(unit, 1);
            FUN_002831c0(unit, 0);
            FUN_00282d40(unit->unk_9e4, unit, unit->unk_9e0, 0, unit->unk_9e8);
            FUN_00282bc0(unit);
            if (*(s32*)((u8*)unit->mdl + 0x3f8) == 0)
            {
                FUN_0031c7e0();
            }
            FUN_00287b20(unit, 4);
            FUN_00287490(unit);
        }
        i++;
    }
    gBtl->unk_ba4 = i;
    enemy = gBtl->startInfo.enmUnits->base.unit;
    for (i = 0; i < 6; i++, enemy++)
    {
        if (enemy->id != 0 && FUN_0030b5a0(enemy, 0) == 0)
        {
            FUN_00289650(1, enemy->id, enemy);
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
    if ((encountFlags & 0x20) != 0)
    {
        if ((encountFlags & 0x10) != 0)
        {
            FUN_0029a690(1);
        }
        else
        {
            FUN_002fac80();
            (*(u16*)((u8*)gBtl + (0x1a))) = 0;
        }
    }
    else
    {
        battleMode = FUN_002d50c0();
        (*(u16*)((u8*)gBtl + (0x1a))) = battleMode;
        if (battleMode == 0)
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
        else if (battleMode == 2)
        {
            FUN_0029a690(1);
            gBtl->order.flags |= 4;
            if ((encountFlags & 0x200) == 0)
            {
                FUN_001febf0(1);
                gBtl->flags |= 0x100000;
            }
        }
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
/* W389 measured: opt_loop_invariants on nd754->753, object 1744/1760 -> 1744/1760. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0029b760 NONMATCHING
u32 btlMainUpdateStateUnitCreate(BtlStateWork* work)
{
    BtlUnit* unitA;
    BtlUnit* unit;
    BtlPacket* movePacket;
    BtlPacket* packet;
    RwV3d unitPos;
    RtQuat unitRot;
    RwV3d homePos;
    RwV3d direction;
    RtQuat baseRot;
    u8 hasSkill24d;
    u8 hasSkill24e;
    u8 hasSkill24f;
    u16 genus;
    u32 encountIndex;
    if (btlPacketCount() == 0 && FUN_001fec30() == 0)
    {
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
        for (unitA = gBtl->unitLists[genus].head; unitA != ((void*)0); unitA = unitA->next)
        {
            FUN_002d3e00(unitA, 0);
            btlUnit0027f7c0(unitA, ((void*)0), (RwV3d*)&baseRot, ((void*)0));
            FUN_0027f680(unitA, &baseRot);
        }
    }
    FUN_00280870(2, 0, &homePos, 0, 0, 1);
    {
        BtlUnit* unit;
    for (unit = gBtl->unitLists[0].head; unit != ((void*)0); unit = unit->next)
    {
        FUN_00287490(unit);
        if (FUN_0030b5a0(unit->datUnit, 0) != 0)
        {
            FUN_003004f0(unit->datUnit, 0x80000);
            FUN_002ffd90(unit->datUnit, 0);
            unit->flags3 |= (1 << 0);
            FUN_002831c0(unit, 0);
            btlPacketRegister(FUN_002dd960(unit), BTLPACKET_TYPE_1);
            btlPacketRegister(FUN_00284200(1.0f, unit, 0x12, 0, 2), BTLPACKET_TYPE_1);
            btlPacketRegister(FUN_00284d80(unit, FUN_002838d0(1.0f, unit, 0x12)), BTLPACKET_TYPE_1);
            btlPacketRegister(FUN_002dd8e0(unit), BTLPACKET_TYPE_1);
        }
        else if (gBtl->unk_ba4 > 1 && (gBtl->unk_10 & 1) == 0)
        {
            btlUnit0027f7c0(unit, &unitPos, ((void*)0), (RwV3d*)&unitRot);
            direction.x = unitPos.x - homePos.x;
            direction.y = unitPos.y - homePos.y;
            direction.z = unitPos.z - homePos.z;
            FUN_004c69f0(&direction, &direction);
            direction.x = direction.x * 150.0f + homePos.x;
            direction.y = direction.y * 150.0f + homePos.y;
            direction.z = direction.z * 150.0f + homePos.z;
            btlUnitSetPos(unit, &direction);
            movePacket = FUN_002819d0(DAT_007cad78, unit, &unitPos, 8);
            btlPacketRegister(movePacket, BTLPACKET_TYPE_1);
            packet = FUN_002822b0(unit, &unitRot, 0);
            packet->unk_00 = 4;
            packet->parentUID = movePacket->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
            if (FUN_00300580(unit->datUnit, 0xfffff) == 0 && FUN_0030b5e0(unit->datUnit) == 0)
            {
                packet = FUN_00284200(1.0f, unit, 0x10, 4, 0);
                packet->unk_00 = 4;
                packet->parentUID = movePacket->uid;
                (*(u16*)((u8*)(packet) + (0x48))) = 4;
                btlPacketRegister(packet, BTLPACKET_TYPE_1);
            }
        }
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
    return BTL_STATE_NULL;
}
#pragma pop
#pragma opt_loop_invariants reset

/* W389 measured: opt_lifetimes on + opt_propagation off with existing opt_loop_invariants on nd470->455, object 692/720 -> 672/720. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
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
    u32 firstUnit;
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
                {
                    u16 enemyCount;
                    BtlUnit* countUnit;
                    enemyCount = 0;
                    for (countUnit = gBtl->unitLists[1].head;
                         countUnit != ((void*)0);
                         countUnit = countUnit->next)
                    {
                        enemyCount++;
                    }

                    (*(u8*)((u8*)(formationPacket) + (0x10))) = 5;
                    (*(u64*)((u8*)(formationPacket) + (0x18))) = formationPacketUID;
                    (*(u16*)((u8*)(formationPacket) + (0x48))) = enemyCount < 4 ? 8 : 4;
                }
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
#pragma pop
#pragma opt_propagation reset
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
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
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    dependentPacket = FUN_002dd4a0(0x1b7, 0);
    dependentPacket->unk_00 = 4;
    dependentPacket->parentUID = packet->uid;
    btlPacketRegister(dependentPacket, BTLPACKET_TYPE_1);
    dependentPacket->actionUID = action->uid;

    FUN_0029ea60(0x1b7, &paramA, &paramB);
    packet = FUN_0029f4b0(paramA, paramB, 0x10);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    color = FUN_0029ec00(0x1b7);
    FUN_0029ec80(0x1b7, &paramA, &paramB);
    packet = FUN_002a0050(color, paramA, paramB, 0x10, 0);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    spellPacket = FUN_002baf90(spellContext, action->unit, action->unit, 0, 0);
    spellPacket->unk_00 = 4;
    spellPacket->parentUID = dependentPacket->uid;
    btlPacketRegister(spellPacket, BTLPACKET_TYPE_2D);
    spellPacket->actionUID = action->uid;
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
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);

        dependentPacket = FUN_002baf90(spellContext, unit, unit, 1, 0);
        dependentPacket->unk_00 = 4;
        dependentPacket->parentUID = spellPacket->uid;
        btlPacketRegister(dependentPacket, BTLPACKET_TYPE_2D);
        BTL_PACKET_U8(dependentPacket, 0x10) = 4;
        BTL_PACKET_U64(dependentPacket, 0x18) = previousUID;
        dependentPacket->actionUID = action->uid;

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
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_0);
        previousUID = packet->uid;

        if ((recovery.flags & 0x80000) != 0 && (unit->flags3 & 0x200) != 0)
        {
            packet = FUN_00284200(1.0f, unit, 0x13, 0, 0);
            BTL_PACKET_U8(packet, 0x00) = 0xb;
            packet->parentUID = dependentPacket->uid;
            packet->actionUID = action->uid;
            btlPacketRegister(packet, BTLPACKET_TYPE_1);
        }

        packet = FUN_002d7e20(unitAction, unitAction, &recovery, 1, 1);
        BTL_PACKET_U8(packet, 0x00) = 0xb;
        packet->parentUID = dependentPacket->uid;
        packet->actionUID = action->uid;
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        if (recovery.hpDelta != 0)
        {
            dependentPacket = FUN_002bd230(unit, 0, 0);
            dependentPacket->unk_00 = 4;
            dependentPacket->parentUID = packet->uid;
            btlPacketRegister(dependentPacket, BTLPACKET_TYPE_3D);
            BTL_PACKET_U8(dependentPacket, 0x47) &= 0xdf;
        }
        dependentPacket = FUN_002bdbd0(unit, unit, BTL_UIDMAX, 0, 0, 0, 1, &recovery);
        dependentPacket->unk_00 = 4;
        dependentPacket->parentUID = packet->uid;
        btlPacketRegister(dependentPacket, BTLPACKET_TYPE_3D);
        BTL_PACKET_U8(dependentPacket, 0x47) &= 0xdf;
    }

    packet = FUN_0029fa50(0x10);
    BTL_PACKET_U8(packet, 0x00) = 4;
    packet->parentUID = previousUID;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a1080(0x10, 0);
    BTL_PACKET_U8(packet, 0x00) = 4;
    packet->parentUID = previousUID;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = FUN_002a16c0(0x10);
    BTL_PACKET_U8(packet, 0x00) = 4;
    packet->parentUID = previousUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
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
    u32 forceConditionChange;
    u64 lastPacketUID;
    forceConditionChange = 0;
    if (FUN_0016f190(0x172) != 0)
    {
        return;
    }
    sickUnitCount = 0;
    for (unit = gBtl->unitLists[0].head; unit != ((void*)0); unit = unit->next)
    {
        unitId = unit->datUnit->id;
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
        unitId = unit->datUnit->id;
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
                case 4:
                    if ((u16)(FUN_0017b170() + 10) > FUN_002ffbc0(100) && unitId != 3)
                    {
                        newCondition = 5;
                    }
                    break;
                case 5:
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
    cameraPacket->actionUID = action->uid;
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
    switch (newCondition)
    {
        case 0:
        case 1:
        case 2:
            conditionPacket = 0x10;
            messagePacket = 0x12;
            break;
        case 3:
            conditionPacket = 0x12;
            messagePacket = 0x13;
            break;
        case 4:
            conditionPacket = 0x10;
            messagePacket = 0x12;
            break;
        case 5:
            conditionPacket = 0x10;
            messagePacket = 0x12;
            break;
    }
    packet = FUN_002e2be0(action, messagePacket, 0, 0, 0);
    (*(u8*)((u8*)(packet) + (0x00))) = 5;
    packet->parentUID = cameraPacket->uid;
    lastPacketUID = packet->uid;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    packet = FUN_002db740(action, conditionPacket, 0, 0, 1);
    packet->unk_00 = 4;
    packet->parentUID = lastPacketUID;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
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

// FUN_0029e4b0
void btlMainDrawColorOverlay(void)
{
    RwSky2DVertex vertices[5];
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;

    if (*(f32*)((u8*)gBtl + 0x240) <= 0.0f)
    {
        return;
    }

    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    {
        void (**setRenderState)(u32 state, u32 value) =
            (void (**)(u32 state, u32 value))DAT_00960090_abs;
        (*setRenderState)(0xc, 1);
        (*setRenderState)(0xe, 0);
        (*setRenderState)(1, 0);
        (*setRenderState)(6, 0);
        (*setRenderState)(8, 0);
        (*setRenderState)(7, 2);
    }

    red = ((s32)(*(f32*)((u8*)gBtl + 0x234) * 255.0f + 0.5f)) & 0xff;
    green = ((s32)(*(f32*)((u8*)gBtl + 0x238) * 255.0f + 0.5f)) & 0xff;
    blue = ((s32)(*(f32*)((u8*)gBtl + 0x23c) * 255.0f + 0.5f)) & 0xff;
    alpha = ((s32)(*(f32*)((u8*)gBtl + 0x240) * 255.0f + 0.5f)) & 0xff;

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[1].u.els.scrVertex.x = 0.0f;
    vertices[1].u.els.scrVertex.y = 448.0f;
    vertices[2].u.els.scrVertex.x = 640.0f;
    vertices[2].u.els.scrVertex.y = 0.0f;
    vertices[3].u.els.scrVertex.x = 640.0f;
    vertices[3].u.els.scrVertex.y = 448.0f;
    vertices[0].u.els.color.r = (f32)red;
    vertices[0].u.els.color.g = (f32)green;
    vertices[0].u.els.color.b = (f32)blue;
    vertices[0].u.els.color.a = (f32)alpha;
    vertices[1].u.els.color.r = (f32)red;
    vertices[1].u.els.color.g = (f32)green;
    vertices[1].u.els.color.b = (f32)blue;
    vertices[1].u.els.color.a = (f32)alpha;
    vertices[2].u.els.color.r = (f32)red;
    vertices[2].u.els.color.g = (f32)green;
    vertices[2].u.els.color.b = (f32)blue;
    vertices[2].u.els.color.a = (f32)alpha;
    vertices[3].u.els.color.r = (f32)red;
    vertices[3].u.els.color.g = (f32)green;
    vertices[3].u.els.color.b = (f32)blue;
    vertices[3].u.els.color.a = (f32)alpha;

    (*DAT_009600A0_abs)(4, vertices, 4);
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

// FUN_0029ea60
void FUN_0029ea60(u32 index, u32* colorA, u32* colorB)
{
    u32 offset;
    u8* entry;
    u32 value;
    u8 rgba[4];

    offset = (index & 0xffff) * 0x1c;
    entry = iGpffffb710 + 8;
    entry += offset;
    value = *(u32*)entry;
    if ((value & 0xff000000) != 0)
    {
        *colorA = value;
    }
    else
    {
        rgba[0] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x194) * 255.0f + 0.5f);
        rgba[1] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x198) * 255.0f + 0.5f);
        rgba[2] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x19c) * 255.0f + 0.5f);
        rgba[3] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1a0) * 255.0f + 0.5f);
        *colorA = *(u32*)rgba;
    }

    entry = iGpffffb710 + 0xc;
    entry += offset;
    value = *(u32*)entry;
    if ((value & 0xff000000) != 0)
    {
        *colorB = value;
    }
    else
    {
        rgba[0] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1a4) * 255.0f + 0.5f);
        rgba[1] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1a8) * 255.0f + 0.5f);
        rgba[2] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1ac) * 255.0f + 0.5f);
        rgba[3] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1b0) * 255.0f + 0.5f);
        *colorB = *(u32*)rgba;
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

// FUN_0029ec80
void FUN_0029ec80(u32 index, u32* colorA, u32* colorB)
{
    u32 offset;
    u8* entry;
    u32 value;
    u8 rgba[4];

    offset = (index & 0xffff) * 0x1c;
    entry = iGpffffb710 + 0x10;
    entry += offset;
    value = *(u32*)entry;
    if ((value & 0xff000000) != 0)
    {
        *colorA = value;
    }
    else
    {
        rgba[0] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1f4) * 255.0f + 0.5f);
        rgba[1] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1f8) * 255.0f + 0.5f);
        rgba[2] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x1fc) * 255.0f + 0.5f);
        rgba[3] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x200) * 255.0f + 0.5f);
        *colorA = *(u32*)rgba;
    }

    entry = iGpffffb710 + 0x14;
    entry += offset;
    value = *(u32*)entry;
    if ((value & 0xff000000) != 0)
    {
        *colorB = value;
    }
    else
    {
        rgba[0] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x204) * 255.0f + 0.5f);
        rgba[1] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x208) * 255.0f + 0.5f);
        rgba[2] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x20c) * 255.0f + 0.5f);
        rgba[3] = (u8)(s32)(*(f32*)((u8*)gBtl + 0x210) * 255.0f + 0.5f);
        *colorB = *(u32*)rgba;
    }
}

/* Recovered battle-misc harvest: 0x0029EE20-0x002A3160 */
// FUN_0029EE20 NONMATCHING






void FUN_0029ee20(u32 unitHandle)
{
  char mode;
  float clampY;
  u32 *packet;
  int iVar4;
  u64 *matrixWords;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  RwMatrix matrix;
  RwV3d unitPos;
  RwV3d targetPos;
  RwV3d direction;
  RwV3d cross;

  if (((*(u32 *)(DAT_007ce3ec + 0xc) & 2) != 0) &&

     (iVar4 = (int)unitHandle, *(short *)(iVar4 + 0x9f2) != 0)) {

    mode = *(char *)(iVar4 + 0xa2);

    switch (mode) {
    case '\0':
    case '\x01':
      unitPos = *(RwV3d *)(iVar4 + 0x54);
      FUN_0027ffb0(unitHandle,&targetPos);
      clampY = targetPos.y + 5.0f;
      if (!(clampY < unitPos.y)) {
        unitPos.y = clampY;
      }
      direction.x = targetPos.x - unitPos.x;
      direction.y = targetPos.y - unitPos.y;
      direction.z = targetPos.z - unitPos.z;
      FUN_004c69f0(&direction,&direction);
      matrix.at = direction;
      cross.x = DAT_00697884 * direction.z - DAT_00697888 * direction.y;
      cross.y = DAT_00697888 * direction.x - DAT_00697880_abs[0] * direction.z;
      cross.z = DAT_00697880_abs[0] * direction.y - DAT_00697884 * direction.x;
      FUN_004c69f0(&cross,&cross);
      matrix.right = cross;
      matrix.up.x = direction.y * cross.z - direction.z * cross.y;
      matrix.up.y = direction.z * cross.x - direction.x * cross.z;
      matrix.up.z = direction.x * cross.y - direction.y * cross.x;
      matrix.pos = unitPos;
      packet = (u32 *)FUN_001a07f0(*(u16 *)(iVar4 + 0x9f2));
      uVar8 = *(u32 *)(iVar4 + 0x74);
      uVar6 = *(u32 *)(iVar4 + 0x78);
      uVar7 = *(u32 *)(iVar4 + 0x7c);
      *packet = *(u32 *)(iVar4 + 0x70);
      packet[1] = uVar8;
      packet[2] = uVar6;
      packet[3] = uVar7;
      packet = (u32 *)FUN_001a08e0(*(u16 *)(iVar4 + 0x9f2));
      matrixWords = (u64 *)&matrix;
      iVar4 = 8;
      do {
        uVar6 = *(u32 *)matrixWords;
        uVar7 = *(u32 *)((int)matrixWords + 4);
        matrixWords = matrixWords + 1;
        iVar4 = iVar4 + -1;
        *packet = uVar6;
        packet[1] = uVar7;
        packet = packet + 2;
      } while (0 < iVar4);
      break;
    case '\x02':
      FUN_004c31b0(0xc2b40000,&matrix,0x697870,0);
      packet = (u32 *)FUN_001a0700(*(u16 *)(iVar4 + 0x9f2));
      ((f32 *)packet)[0] = DAT_00693850[0];
      ((f32 *)packet)[1] = DAT_00693854[0];
      ((f32 *)packet)[2] = DAT_00693858[0];
      ((f32 *)packet)[3] = DAT_0069385c[0];
      packet = (u32 *)FUN_001a07f0(*(u16 *)(iVar4 + 0x9f2));
      ((f32 *)packet)[0] = DAT_00693860[0];
      ((f32 *)packet)[1] = DAT_00693864[0];
      ((f32 *)packet)[2] = DAT_00693868[0];
      ((f32 *)packet)[3] = _DAT_0069386c[0];
      packet = (u32 *)FUN_001a08e0(*(u16 *)(iVar4 + 0x9f2));
      matrixWords = (u64 *)&matrix;
      iVar4 = 8;
      do {
        uVar6 = *(u32 *)matrixWords;
        uVar7 = *(u32 *)((int)matrixWords + 4);
        matrixWords = matrixWords + 1;
        iVar4 = iVar4 + -1;
        *packet = uVar6;
        packet[1] = uVar7;
        packet = packet + 2;
      } while (0 < iVar4);
      break;
    }

  }

  return;

}

// FUN_0029F150 NONMATCHING


u32 FUN_0029f150(float *colorLerp)
{

  u32 done;

  float *colorDst;


  float t;

  float invT;
  float firstX;
  float firstY;
  float firstZ;
  float firstW;
  float secondX;
  float secondY;
  float secondZ;
  float secondW;


  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    done = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    done = 1;

  }

  else {
  u32 duration;
  RwRGBAReal color;

  if (*(u32 *)(colorLerp + 0x19) == 0) {

      colorDst = (float *)FUN_0019fd40();
      *(RwRGBAReal *)(colorLerp + 0x10) = *(RwRGBAReal *)colorDst;

      colorDst = (float *)FUN_0019fd70();
      *(RwRGBAReal *)(colorLerp + 0x14) = *(RwRGBAReal *)colorDst;

      colorLerp[8] = colorLerp[0x10] * *colorLerp;

      colorLerp[9] = colorLerp[0x11] * colorLerp[1];

      colorLerp[10] = colorLerp[0x12] * colorLerp[2];

      colorLerp[0xb] = colorLerp[0x13] * colorLerp[3];

      colorLerp[0xc] = colorLerp[0x14] * colorLerp[4];

      colorLerp[0xd] = colorLerp[0x15] * colorLerp[5];

      colorLerp[0xe] = colorLerp[0x16] * colorLerp[6];

      colorLerp[0xf] = colorLerp[0x17] * colorLerp[7];

    }
    duration = *(u32 *)(colorLerp + 0x18);

    if (*(u32 *)(colorLerp + 0x19) < duration) {
      t = (float)*(u32 *)(colorLerp + 0x19) / (float)duration;

      invT = 1.0f - t;

      firstX = colorLerp[0x10] * invT;
      firstY = colorLerp[0x11] * invT;
      firstZ = colorLerp[0x12] * invT;
      firstW = colorLerp[0x13] * invT;
      secondX = colorLerp[8] * t;
      secondY = colorLerp[9] * t;
      secondZ = colorLerp[10] * t;
      secondW = colorLerp[0xb] * t;
      color.r = firstX + secondX;
      color.g = firstY + secondY;
      color.b = firstZ + secondZ;
      color.a = firstW + secondW;
      colorDst = (float *)FUN_0019fd40();
      *(RwRGBAReal *)colorDst = color;

      firstX = colorLerp[0x14] * invT;
      firstY = colorLerp[0x15] * invT;
      firstZ = colorLerp[0x16] * invT;
      firstW = colorLerp[0x17] * invT;
      secondX = colorLerp[0xc] * t;
      secondY = colorLerp[0xd] * t;
      secondZ = colorLerp[0xe] * t;
      secondW = colorLerp[0xf] * t;
      color.r = firstX + secondX;
      color.g = firstY + secondY;
      color.b = firstZ + secondZ;
      color.a = firstW + secondW;
      colorDst = (float *)FUN_0019fd70();
      *(RwRGBAReal *)colorDst = color;

      *(u32 *)(colorLerp + 0x19) = *(u32 *)(colorLerp + 0x19) + 1;
      done = 0;

    }

    else {

      colorDst = (float *)FUN_0019fd40();
      *(RwRGBAReal *)colorDst = *(RwRGBAReal *)(colorLerp + 8);

      colorDst = (float *)FUN_0019fd70();
      *(RwRGBAReal *)colorDst = *(RwRGBAReal *)(colorLerp + 0xc);

      done = 1;

    }

  }

  return done;

}

// FUN_0029F4B0
BtlPacket* FUN_0029f4b0(u32 param_1,u32 param_2,u32 param_3)
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
    return (BtlPacket*)packet;
}

/* W389 measured: opt_lifetimes on nd852->804, object 1408/1456 -> 1408/1456. */
// FUN_0029F760 NONMATCHING


u32 FUN_0029f760(float *colorLerp)
{


  RwRGBAReal *colorPtr;
  RwRGBAReal color;
  u32 done;
  float t;
  float invT;
  float firstX;
  float firstY;
  float firstZ;
  float firstW;
  float secondX;
  float secondY;
  float secondZ;
  float secondW;



  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 2) == 0) {

    done = 1;

  }

  else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x2000000) == 0) {

    done = 1;

  }

  else {

    if (*(u32 *)(colorLerp + 9) == 0) {

      colorPtr = (RwRGBAReal *)FUN_0019fd40();
      *(RwRGBAReal *)colorLerp = *colorPtr;
      colorPtr = (RwRGBAReal *)FUN_0019fd70();
      *(RwRGBAReal *)(colorLerp + 4) = *colorPtr;

    }


    if (*(u32 *)(colorLerp + 9) < *(u32 *)(colorLerp + 8)) {
      t = (float)*(u32 *)(colorLerp + 9) / (float)*(u32 *)(colorLerp + 8);
      invT = 1.0f - t;
      firstX = colorLerp[0] * invT;
      firstY = colorLerp[1] * invT;
      firstZ = colorLerp[2] * invT;
      firstW = colorLerp[3] * invT;
      secondX = *(float *)(DAT_007ce3ec + 0x194) * t;
      secondY = *(float *)(DAT_007ce3ec + 0x198) * t;
      secondZ = *(float *)(DAT_007ce3ec + 0x19c) * t;
      secondW = *(float *)(DAT_007ce3ec + 0x1a0) * t;
      color.r = firstX + secondX;
      color.g = firstY + secondY;
      color.b = firstZ + secondZ;
      color.a = firstW + secondW;
      colorPtr = (RwRGBAReal *)FUN_0019fd40();
      *colorPtr = color;

      firstX = colorLerp[4] * invT;
      firstY = colorLerp[5] * invT;
      firstZ = colorLerp[6] * invT;
      firstW = colorLerp[7] * invT;
      secondX = *(float *)(DAT_007ce3ec + 0x1a4) * t;
      secondY = *(float *)(DAT_007ce3ec + 0x1a8) * t;
      secondZ = *(float *)(DAT_007ce3ec + 0x1ac) * t;
      secondW = *(float *)(DAT_007ce3ec + 0x1b0) * t;
      color.r = firstX + secondX;
      color.g = firstY + secondY;
      color.b = firstZ + secondZ;
      color.a = firstW + secondW;
      colorPtr = (RwRGBAReal *)FUN_0019fd70();
      *colorPtr = color;

      *(u32 *)(colorLerp + 9) = *(u32 *)(colorLerp + 9) + 1;

      done = 0;

    }

    else {

      colorPtr = (RwRGBAReal *)FUN_0019fd40();
      *colorPtr = *(RwRGBAReal *)(DAT_007ce3ec + 0x194);
      colorPtr = (RwRGBAReal *)FUN_0019fd70();
      *colorPtr = *(RwRGBAReal *)(DAT_007ce3ec + 0x1a4);

      done = 1;

    }

  }

  return done;

}
/* W389 measured: opt_loop_invariants on + opt_propagation off with existing opt_common_subs on nd2367->2325, object 3088/3136 -> 3000/3136. */
// FUN_0029FA50


BtlPacket* FUN_0029fa50(u32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x601, 0x28);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_0029f760;
    *(u32*)((u8*)packet->workData + 0x20) = param_1;
    return packet;
}
#pragma push
#pragma opt_lifetimes on
// FUN_0029FAA0 NONMATCHING


u32 FUN_0029faa0(BtlMainColorWork *param_1)



{


  f32 lightValueA;

  u32 uVar3;

  f32 lightValueB;

  u32 uVar4;

  int iVar5;

  u_long128 *matrixDst;
  u_long128 *matrixSrc;

  BtlMainColorWork *colorWork;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  RwRGBAReal color;

  RwMatrix matrix;

  

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

      *(RwRGBAReal *)&colorWork->unk_10 =
          *(RwRGBAReal *)(DAT_007ce3ec + 0x224);

      *(RwRGBAReal *)&colorWork->unk_30 =
          *(RwRGBAReal *)(iVar5 + 0x1c4);

      *(RwRGBAReal *)&colorWork->unk_50 =
          *(RwRGBAReal *)(iVar5 + 0x1d4);

      *(RwRGBAReal *)DAT_009572B0 =
          *(RwRGBAReal *)(iVar5 + 0x194);
      *(RwRGBAReal *)(DAT_009572B0 + 4) =
          *(RwRGBAReal *)(iVar5 + 0x1a4);

      fVar14 = *(float *)(iVar5 + 0x1b8);

      fVar15 = *(float *)(iVar5 + 0x1b4);

      fVar13 = *(float *)(iVar5 + 0x1bc);

      fVar12 = *(float *)(iVar5 + 0x1c0);

      fVar9 = 2.0f / (fVar12 * fVar12 + fVar13 * fVar13 + fVar15 * fVar15 + fVar14 * fVar14);

      fVar10 = fVar15 * fVar9;

      fVar11 = fVar14 * fVar9;

      fVar9 = fVar13 * fVar9;

      matrix.right.x = 1.0f - (fVar14 * fVar11 + fVar13 * fVar9);
      matrix.right.y = fVar15 * fVar11 + fVar9 * fVar12;
      matrix.right.z = fVar13 * fVar10 - fVar11 * fVar12;
      matrix.up.x = fVar15 * fVar11 - fVar9 * fVar12;
      matrix.up.y = 1.0f - (fVar13 * fVar9 + fVar15 * fVar10);
      matrix.up.z = fVar14 * fVar9 + fVar10 * fVar12;
      matrix.at.x = fVar13 * fVar10 + fVar11 * fVar12;
      matrix.at.y = fVar14 * fVar9 - fVar10 * fVar12;
      matrix.at.z = 1.0f - (fVar15 * fVar10 + fVar14 * fVar11);
      matrix.pos.x = 0.0f;
      matrix.pos.y = 0.0f;
      matrix.pos.z = 0.0f;
      matrix.flags = 3;
      matrixSrc = (u_long128*)&matrix;
      matrixDst = (u_long128*)&DAT_00957270;

      iVar5 = 4;

      do {
        *matrixDst++ = *matrixSrc++;
        iVar5 = iVar5 + -1;
        lightValueA = DAT_007cafbc;
        lightValueB = DAT_007caee8;
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

              if ((colorWork->unk_68 & 1) != 0) {

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3a9) = 0;

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3aa) = 6;

              }

              else {

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3a9) = 0x50;

                *(u8 *)(*(int *)(iVar5 + 0x9f4) + 0x3aa) = 4;

              }

              *(f32 *)(*(int *)(iVar5 + 0x9f4) + 0x3ac) = lightValueA;

              *(f32 *)(*(int *)(iVar5 + 0x9f4) + 0x3b0) = lightValueB;
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

      color.r = colorWork->unk_10 * fVar16 + colorWork->r * fVar15;
      color.g = colorWork->unk_14 * fVar16 + colorWork->g * fVar15;
      color.b = colorWork->b * fVar15 + colorWork->unk_18 * fVar16;
      color.a = 1.0f;
      *(float *)(DAT_007ce3ec + 0x224) = color.r;
      *(float *)(iVar5 + 0x228) = color.g;
      *(float *)(iVar5 + 0x22c) = color.b;
      *(float *)(iVar5 + 0x230) = color.a;
      FUN_0019f8f0(&color);

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
#pragma pop
#pragma opt_lifetimes reset













/* W323 measured: opt_common_subs off nd423->35, object 684/704; default nd423, 684/704. */
// FUN_002A0050 MATCHING
BtlPacket* FUN_002a0050(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u16 param_5)
{
    float *pfVar1;
    int iVar2;
    union { u32 value; u8 bytes[4]; } packed;

    iVar2 = (int)FUN_0027ec10(0x602, 0x6c);
    *(code **)(iVar2 + 0x6c) = (code *)FUN_002a0440;
    pfVar1 = *(float **)(iVar2 + 0x78);

    packed.value = param_1;
    pfVar1[0] = DAT_007caf08 * (float)packed.bytes[0];
    pfVar1[1] = DAT_007caf08 * (float)packed.bytes[1];
    pfVar1[2] = DAT_007caf08 * (float)packed.bytes[2];
    pfVar1[3] = DAT_007caf08 * (float)packed.bytes[3];

    packed.value = param_2;
    pfVar1[8] = DAT_007caf08 * (float)packed.bytes[0];
    pfVar1[9] = DAT_007caf08 * (float)packed.bytes[1];
    pfVar1[10] = DAT_007caf08 * (float)packed.bytes[2];
    pfVar1[0xb] = DAT_007caf08 * (float)packed.bytes[3];

    packed.value = param_3;
    pfVar1[0x10] = DAT_007caf08 * (float)packed.bytes[0];
    pfVar1[0x11] = DAT_007caf08 * (float)packed.bytes[1];
    pfVar1[0x12] = DAT_007caf08 * (float)packed.bytes[2];
    pfVar1[0x13] = DAT_007caf08 * (float)packed.bytes[3];

    *(u32 *)((u8 *)pfVar1 + 0x60) = param_4;
    *(u16 *)(pfVar1 + 0x1a) = param_5;
    return (BtlPacket*)iVar2;
}

/* W389 measured: opt_common_subs off + opt_dead_assignments off nd680->592, object 952/1008 -> 1008/1008. */
#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_002A0440 NONMATCHING
u32 FUN_002a0440(float *param_1)



{


  int iVar7;
  u32 uVar9;

  float fVar16;

  float fVar17;

  float fStack[8];

  


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

      fVar14 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1c8);
      fVar8 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1cc);
      fVar10 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1d0);
      param_1[0xc] = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1c4);

      param_1[0xd] = fVar14;

      param_1[0xe] = fVar8;

      param_1[0xf] = fVar10;

      fVar14 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1d8);
      fVar8 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1dc);
      fVar10 = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1e0);
      param_1[0x10] = *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x1d4);

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

          *(float *)(iVar7 + 0x60) = *(float *)(iVar7 + 0x70);

          *(float *)(iVar7 + 100) = *(float *)(iVar7 + 0x74);

          *(float *)(iVar7 + 0x68) = *(float *)(iVar7 + 0x78);

          *(float *)(iVar7 + 0x6c) = *(float *)(iVar7 + 0x7c);

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


    fStack[0] = DAT_007caf08 * (float)DAT_007cc970;

    fStack[1] = DAT_007caf08 * (float)DAT_007cc971;

    fStack[2] = DAT_007caf08 * (float)DAT_007cc972;

    fStack[3] = DAT_007caf08 * (float)DAT_007cc973;

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

      fVar17 = 1.0f - fVar16;

      fStack[4] = *param_1 * fVar17 + fStack[0] * fVar16;

      fStack[5] = param_1[1] * fVar17 + fStack[1] * fVar16;

      fStack[6] = fStack[2] * fVar16 + param_1[2] * fVar17;

      fStack[7] = 1.0f;

      *(float *)(DAT_007ce3ec + 0x224) = fStack[4];

      *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x228) = fStack[5];
      *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x22c) = fStack[6];
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x230) = 0x3f800000;

      FUN_0019f8f0(&fStack[4]);

      fStack[4] = param_1[4] * fVar17 + *(float *)(DAT_007ce3ec + 0x194) * fVar16;

      fStack[5] = param_1[5] * fVar17 + *(float *)(DAT_007ce3ec + 0x198) * fVar16;

      fStack[6] = param_1[6] * fVar17 + *(float *)(DAT_007ce3ec + 0x19c) * fVar16;

      fStack[7] = *(float *)(DAT_007ce3ec + 0x1a0) * fVar16 + param_1[7] * fVar17;

      pfVar4 = (float *)FUN_0019fd40();

      *pfVar4 = fStack[4];

      pfVar4[1] = fStack[5];

      pfVar4[2] = fStack[6];

      pfVar4[3] = fStack[7];

      fStack[4] = param_1[8] * fVar17 + *(float *)(DAT_007ce3ec + 0x1a4) * fVar16;

      fStack[5] = param_1[9] * fVar17 + *(float *)(DAT_007ce3ec + 0x1a8) * fVar16;

      fStack[6] = param_1[10] * fVar17 + *(float *)(DAT_007ce3ec + 0x1ac) * fVar16;

      fStack[7] = *(float *)(DAT_007ce3ec + 0x1b0) * fVar16 + param_1[0xb] * fVar17;

      pfVar4 = (float *)FUN_0019fd70();

      *pfVar4 = fStack[4];

      pfVar4[1] = fStack[5];

      pfVar4[2] = fStack[6];

      pfVar4[3] = fStack[7];

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

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x38) * fVar17 + fStack[0] * fVar16)
                             * 255.0f + 0.5f);

            *(char *)(iVar7 + 0x3d) =

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x39) * fVar17 + fStack[1] * fVar16)
                             * 255.0f + 0.5f);

            *(char *)(iVar7 + 0x3e) =

                 (char)(int)((fVar8 * (float)*(u8 *)(iVar7 + 0x3a) * fVar17 + fStack[2] * fVar16)
                             * 255.0f + 0.5f);

            *(char *)(iVar7 + 0x3f) =

                 (char)(int)((fStack[3] * fVar16 + fVar8 * (float)*(u8 *)(iVar7 + 0x3b) * fVar17)
                             * 255.0f + 0.5f);

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


      FUN_0019f8f0(&fStack[0]);

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      *(float *)(DAT_007ce3ec + 0x224) = fStack[0];

      *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x228) = fStack[1];
      *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x22c) = fStack[2];
      *(float *)((int)(uintptr_t)DAT_007ce3ec + 0x230) = fStack[3];

      puVar6 = (u32 *)FUN_0019fd40();

      uVar15 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x198);
      uVar9 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x19c);
      uVar13 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1a0);
      *puVar6 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x194);

      puVar6[1] = uVar15;

      puVar6[2] = uVar9;

      puVar6[3] = uVar13;

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      puVar6 = (u32 *)FUN_0019fd70();

      uVar15 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1a8);
      uVar9 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1ac);
      uVar13 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1b0);
      *puVar6 = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1a4);

      puVar6[1] = uVar15;

      puVar6[2] = uVar9;

      puVar6[3] = uVar13;

      iVar7 = (int)(uintptr_t)DAT_007ce3ec;

      puVar6 = (u32 *)(DAT_007ce3ec + 0x1f8);

      uVar9 = *(u32 *)(DAT_007ce3ec + 0x1fc);

      uVar13 = *(u32 *)(DAT_007ce3ec + 0x200);

      *(u32 *)(DAT_007ce3ec + 0x1c4) = *(u32 *)(DAT_007ce3ec + 500);

      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1c8) = *puVar6;
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1cc) = uVar9;
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1d0) = uVar13;
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1d4) = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x204);
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1d8) = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x208);
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1dc) = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x20c);
      *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x1e0) = *(u32 *)((int)(uintptr_t)DAT_007ce3ec + 0x210);

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

                     *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3a0) * 1.25f;

                *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3a4) = fVar18;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a8) = 0;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3a9) = 0xa0;

                *(u8 *)(*(int *)(iVar7 + 0x9f4) + 0x3aa) = 6;

                *(u32 *)(*(int *)(iVar7 + 0x9f4) + 0x3ac) = 0x3f800000;

                *(float *)(*(int *)(iVar7 + 0x9f4) + 0x3b0) = fVar19;

                if (1.0f < *(float *)(*(int *)(iVar7 + 0x9f4) + 0x39c)) {

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
#pragma pop
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset

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

/* W389 measured: opt_common_subs off with existing opt_loop_invariants on nd356->309, object 544/576 -> 556/576. */
// FUN_002A10E0


u8 FUN_002a10e0(BtlMainLerpWork *param_1)
{
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    RwV4d results;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    if (param_1->currentFrame == 0)
    {
        global = (u8*)iGpffffb6fc;
        *(RwV4d*)&param_1->target0 = *(RwV4d*)(global + 0x234);
    }

    totalFrames = param_1->totalFrames;
    currentFrame = param_1->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;

        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = param_1->target0 * inverse + param_1->value0 * ratio;
        results.y = param_1->target1 * inverse + param_1->value1 * ratio;
        results.z = param_1->target2 * inverse + param_1->value2 * ratio;
        results.w = param_1->target3 * inverse + param_1->value3 * ratio;
        global = (u8*)iGpffffb6fc;
        *(RwV4d*)(global + 0x234) = results;
    }

    else
    {
        global = (u8*)iGpffffb6fc;
        *(RwV4d*)(global + 0x234) = *(RwV4d*)&param_1->value0;
        return 1;
    }

    param_1->currentFrame++;
    return 0;
}

// FUN_002A1280
BtlPacket* FUN_002a1280(u32 param_1,u32 param_2)
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
    return (BtlPacket*)packet;
}

#pragma opt_common_subs off
// FUN_002A1400
u8 FUN_002a1400(float *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  u32 duration;
  u32 counter;
  RwRGBAReal output;
  RwRGBAReal target;

  if (*(u32 *)(param_1 + 5) == 0) {
    *(RwRGBAReal *)param_1 = *(RwRGBAReal *)(iGpffffb6fc + 0x234);
  }

  target.r = fGpffff8218 * (float)bGpffffb808;
  target.g = fGpffff8218 * (float)bGpffffb809;
  target.b = fGpffff8218 * (float)bGpffffb80a;
  target.a = fGpffff8218 * (float)bGpffffb80b;
  duration = *(u32 *)(param_1 + 4);
  counter = *(u32 *)(param_1 + 5);
  if (counter < duration) {
    fVar5 = (float)counter / (float)duration;
    fVar7 = 1.0f - fVar5;
    fVar6 = param_1[1];
    fVar2 = param_1[2];
    fVar3 = param_1[3];
    output.r = *param_1 * fVar7 + target.r * fVar5;
    output.g = fVar6 * fVar7 + target.g * fVar5;
    output.b = fVar2 * fVar7 + target.b * fVar5;
    output.a = fVar3 * fVar7 + target.a * fVar5;
    *(RwRGBAReal *)(iGpffffb6fc + 0x234) = output;
  }
  else {
    *(RwRGBAReal *)(iGpffffb6fc + 0x234) = target;
    return 1;
  }
  *(u32 *)(param_1 + 5) = *(u32 *)(param_1 + 5) + 1;
  return 0;
}
#pragma opt_common_subs reset

// FUN_002A16C0


BtlPacket* FUN_002a16c0(s32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x605, 0x18);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a1400;
    *(s32*)((u8*)packet->workData + 0x10) = param_1;
    return packet;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_dead_assignments off
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
  RwRGBA color;
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
        fVar9 = (1.0f - (float)(u32)param_1[2] / (float)(u32)param_1[1]) * 255.0f;
        uVar8 = (u8)(u32)fVar9;
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
            color = *(RwRGBA *)(iVar2 + 0x30);
            color.a = uVar8;
            FUN_0027f730(iVar2,*(u32 *)&color);
          }
        }
      }
      for (uVar4 = 0; uVar4 < *(u16 *)(iVar1 + 0x6a); uVar4 = uVar4 + 1 & 0xffff) {
        iVar2 = *(int *)(*(int *)(iVar1 + uVar4 * 4 + 0x38) + 0x30);
        color = *(RwRGBA *)(iVar2 + 0x30);
        color.a = 0xff;
        FUN_0027f730(iVar2,*(u32 *)&color);
      }
      param_1[2] = param_1[2] + 1;
    }
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}
#pragma pop
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset

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

#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// FUN_002A1B70 NONMATCHING


u32 FUN_002a1b70(u32 *fade)
{
  int unit;
  u32 done;
  u32 alpha;
  u32 team;
  float ratio;
  u32 colorWord;
  if (((*(u32 *)(iGpffffb6fc + 0xc) & 0x400000) == 0) ||
     ((*(u16 *)(iGpffffb6fc + 0x18) & 0x10) == 0)) {
    done = 1;
    if (fade[1] < *fade) {
      ratio = ((float)fade[1] / (float)*fade) * 255.0f;
      alpha = (u32)ratio & 0xff;
      done = 0;
    }
    else {
      alpha = 0xff;
    }
    for (team = 0; team < 2; team = team + 1 & 0xffff) {
      for (unit = *(int *)(iGpffffb6fc + team * 8 + 0x150); unit != 0;
          unit = *(int *)(unit + 0xa34)) {
        if (((*(short *)(unit + 0x9f2) != 0) && ((*(u32 *)(unit + 0x9c) & 1) == 0)) &&
           (*(u8 *)(unit + 0x33) < alpha)) {
          colorWord = ((((u32)((char)alpha) & 0xffu) << 24) | ((u32)(*(u32 *)(unit + 0x30) & 0x00ffffffu) & 0x00ffffffu));
          FUN_0027f730(unit,colorWord);
        }
      }
    }
    fade[1] = fade[1] + 1;
  }
  else {
    done = 1;
  }
  return done;
}
#pragma pop
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset

// FUN_002A1DB0


void FUN_002a1db0(s32 param_1)
{
    BtlPacket* packet;
    packet = btlPacketCreate(0x607, 8);
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002a1b70;
    *(s32*)packet->workData = param_1;
}

/* W414/W421 evidence: baseline verify nd4 at 592/592 (rate 0.006757).
 * The ordered jal sequence is identical on both sides: FUN_004be310 only;
 * no missing/extra call is present.  Splitting each quintic into
 * sequential Horner statements keeps the retail constant-load/accumulator
 * order.  The two residuals are one commutative product-order defect:
 * +368 ours madd.s $f20,$f1,$f0 versus retail madd.s $f20,$f0,$f1;
 * +428 ours madd.s $f21,$f1,$f0 versus retail madd.s $f21,$f0,$f1.
 * Both destinations match and both source pairs are swapped. */
static inline f32 btlMainMulFirst(f32 left, f32 right)
{
    return left * right;
}

// FUN_002A1E00


void FUN_002a1e00(float *param_2,float *param_3,float *param_4,float param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *out;
  float *first;
  float *second;
  struct {
    float values[9];
    u32 mode;
  } interpolation;

  out = param_2;
  first = param_3;
  second = param_4;
  fVar5 = 1.0f - param_1;
  fVar1 = first[1] * fVar5;
  fVar2 = first[2] * fVar5;
  fVar3 = second[1] * param_1;
  fVar4 = second[2] * param_1;
  *out = *first * fVar5 + *second * param_1;
  out[1] = fVar1 + fVar3;
  out[2] = fVar2 + fVar4;
  FUN_004be310(first + 3,second + 3,interpolation.values);
  if (param_1 <= 0.0f) {
    *(RwV4d*)(out + 3) = *(RwV4d*)(first + 3);
  }
  else if (1.0f <= param_1) {
    *(RwV4d*)(out + 3) = *(RwV4d*)(second + 3);
  }
  else {
    if (interpolation.mode == 0) {
      fVar5 = fVar5 * interpolation.values[8];
      fVar2 = fVar5 * fVar5;
      fVar1 = fGpffff8044 * fVar2 + fGpffff8048 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff804c + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8050 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8054 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8058 + 0.0f;
      fVar5 = btlMainMulFirst(fVar2 * fVar5, fVar1) + fVar5 + 0.0f;
      param_1 = param_1 * interpolation.values[8];
      fVar2 = param_1 * param_1;
      fVar1 = fGpffff8044 * fVar2 + fGpffff8048 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff804c + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8050 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8054 + 0.0f;
      fVar1 = fVar2 * fVar1 + fGpffff8058 + 0.0f;
      param_1 = btlMainMulFirst(fVar2 * param_1, fVar1) + param_1 + 0.0f;
    }
    out[3] = interpolation.values[0] * fVar5;
    out[4] = interpolation.values[1] * fVar5;
    out[5] = interpolation.values[2] * fVar5;
    out[3] = interpolation.values[4] * param_1 + out[3] + 0.0f;
    out[4] = interpolation.values[5] * param_1 + out[4] + 0.0f;
    out[5] = interpolation.values[6] * param_1 + out[5] + 0.0f;
    out[6] = interpolation.values[3] * fVar5 + interpolation.values[7] * param_1;
  }
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

// FUN_002A2290


void FUN_002a2290(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4)
{
    u16 index;
    u16 index0;
    u16 index1;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 work[7];

    *param_1 = param_4;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index0 = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                FUN_0048d370(*(u32*)((u8*)param_1 + 0x98), index0, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
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
        index0++;
        if (index0 >= 4)
        {
            index0 = 0;
        }
        param_1[0x3c] = index0;
        param_1[0x3b]++;
    }

    FUN_002a1e00_typed(work, param_2, param_3, fGpffff82c8);
    if (param_1[0x3b] < 4)
    {
        index1 = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                FUN_0048d370(*(u32*)((u8*)param_1 + 0x98), index1, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index1++;
        if (index1 >= 4)
        {
            index1 = 0;
        }
        param_1[0x3c] = index1;
        param_1[0x3b]++;
    }

    FUN_002a1e00_typed(work, param_2, param_3, fGpffff805c);
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                FUN_0048d370(*(u32*)((u8*)param_1 + 0x98), index, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }

    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_3[0];
            value3 = param_3[1];
            value1 = param_3[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                FUN_0048d370(*(u32*)((u8*)param_1 + 0x98), index, param_3);
            }
        }
        source = param_3 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
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

// FUN_002A2660 NONMATCHING


void FUN_002a2660(u16 *ring,u32 rec0,u32 rec1,u32 rec2,u32 rec3,u16 flags)
{
  u16 slot;
  u32 *record;
  u32 word1;
  u32 word2;
  u32 word4;
  u32 word5;
  u32 word6;

  *ring = flags;
  ring[0x3a] = 0;
  ring[0x3b] = 0;
  ring[0x3c] = 0;
  *(u32 *)((u8 *)ring + 0x80) = 0;
  *(u32 *)((u8 *)ring + 0x7c) = 0;

  if (ring[0x3b] < 4) {
    slot = ring[0x3c];
    record = (u32 *)rec0;
    if (rec0 != 0) {
      word1 = record[1];
      word2 = record[2];
      *(u32 *)(ring + (u32)slot * 0xe + 2) = *record;
      *(u32 *)(ring + (u32)slot * 0xe + 4) = word1;
      *(u32 *)(ring + (u32)slot * 0xe + 6) = word2;
      if ((*ring & 1) == 0) {
        FUN_0048d370(*(u32 *)(ring + 0x4c),slot,rec0);
      }
    }
    word4 = record[4];
    word5 = record[5];
    word6 = record[6];
    *(u32 *)(ring + (u32)slot * 0xe + 8) = record[3];
    *(u32 *)(ring + (u32)slot * 0xe + 10) = word4;
    *(u32 *)(ring + (u32)slot * 0xe + 0xc) = word5;
    *(u32 *)(ring + (u32)slot * 0xe + 0xe) = word6;
    slot = slot + 1;
    if (3 < slot) {
      slot = 0;
    }
    ring[0x3c] = slot;
    ring[0x3b] = ring[0x3b] + 1;
  }

  if (ring[0x3b] < 4) {
    slot = ring[0x3c];
    record = (u32 *)rec1;
    if (rec1 != 0) {
      word1 = record[1];
      word2 = record[2];
      *(u32 *)(ring + (u32)slot * 0xe + 2) = *record;
      *(u32 *)(ring + (u32)slot * 0xe + 4) = word1;
      *(u32 *)(ring + (u32)slot * 0xe + 6) = word2;
      if ((*ring & 1) == 0) {
        FUN_0048d370(*(u32 *)(ring + 0x4c),slot,rec1);
      }
    }
    word4 = record[4];
    word5 = record[5];
    word6 = record[6];
    *(u32 *)(ring + (u32)slot * 0xe + 8) = record[3];
    *(u32 *)(ring + (u32)slot * 0xe + 10) = word4;
    *(u32 *)(ring + (u32)slot * 0xe + 0xc) = word5;
    *(u32 *)(ring + (u32)slot * 0xe + 0xe) = word6;
    slot = slot + 1;
    if (3 < slot) {
      slot = 0;
    }
    ring[0x3c] = slot;
    ring[0x3b] = ring[0x3b] + 1;
  }

  if (ring[0x3b] < 4) {
    slot = ring[0x3c];
    record = (u32 *)rec2;
    if (rec2 != 0) {
      word1 = record[1];
      word2 = record[2];
      *(u32 *)(ring + (u32)slot * 0xe + 2) = *record;
      *(u32 *)(ring + (u32)slot * 0xe + 4) = word1;
      *(u32 *)(ring + (u32)slot * 0xe + 6) = word2;
      if ((*ring & 1) == 0) {
        FUN_0048d370(*(u32 *)(ring + 0x4c),slot,rec2);
      }
    }
    word4 = record[4];
    word5 = record[5];
    word6 = record[6];
    *(u32 *)(ring + (u32)slot * 0xe + 8) = record[3];
    *(u32 *)(ring + (u32)slot * 0xe + 10) = word4;
    *(u32 *)(ring + (u32)slot * 0xe + 0xc) = word5;
    *(u32 *)(ring + (u32)slot * 0xe + 0xe) = word6;
    slot = slot + 1;
    if (3 < slot) {
      slot = 0;
    }
    ring[0x3c] = slot;
    ring[0x3b] = ring[0x3b] + 1;
  }

  if (ring[0x3b] < 4) {
    slot = ring[0x3c];
    record = (u32 *)rec3;
    if (rec3 != 0) {
      word1 = record[1];
      word2 = record[2];
      *(u32 *)(ring + (u32)slot * 0xe + 2) = *record;
      *(u32 *)(ring + (u32)slot * 0xe + 4) = word1;
      *(u32 *)(ring + (u32)slot * 0xe + 6) = word2;
      if ((*ring & 1) == 0) {
        FUN_0048d370(*(u32 *)(ring + 0x4c),slot,rec3);
      }
    }
    word4 = record[4];
    word5 = record[5];
    word6 = record[6];
    *(u32 *)(ring + (u32)slot * 0xe + 8) = record[3];
    *(u32 *)(ring + (u32)slot * 0xe + 10) = word4;
    *(u32 *)(ring + (u32)slot * 0xe + 0xc) = word5;
    *(u32 *)(ring + (u32)slot * 0xe + 0xe) = word6;
    slot = slot + 1;
    if (3 < slot) {
      slot = 0;
    }
    ring[0x3c] = slot;
    ring[0x3b] = ring[0x3b] + 1;
  }
}

static inline u8* btlMainAddFirst(u8* base, u32 offset)
{
    return base + offset;
}

// FUN_002A2A20 NONMATCHING


/* BtlCore2 W419 negative: 2a2a20 _abs address spellings held nd63 at 296B; scalar direct spelling worsened nd63->151 and shrank to 284B. W442 natural u16 increments reduce nd63->59 at 296B. */
void FUN_002a2a20(u8* curve,f32* outPos,f32 t)
{
  u32 keyAddr;
  u16 i;
  u16 startIndex;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float tSquared;
  float originZ;
  float basis[4];
  fVar6 = 1.0f - t;
  fVar7 = fVar6 * fVar6;
  basis[0] = fVar6 * fVar7;
  basis[1] = t * fVar7 * 3.0f;
  tSquared = t * t;
  basis[2] = fVar6 * tSquared * 3.0f;
  basis[3] = t * tSquared;
  startIndex = *(u16 *)(curve + 0x74);
  fVar4 = *(f32 *)DAT_00957180_abs;
  fVar5 = *(f32 *)DAT_00957184_abs;
  originZ = *(f32 *)DAT_00957188_abs;
  *outPos = fVar4;
  outPos[1] = fVar5;
  outPos[2] = originZ;
  for (i = 0; i < 4; i++) {
    fVar6 = *(float *)((u8 *)basis + (u32)i * 4 + 0);
    keyAddr = (u32)startIndex * 0x1c;
    keyAddr = (u32)btlMainAddFirst(curve, keyAddr);
    fVar4 = *(float *)(keyAddr + 8) * fVar6;
    fVar5 = *(float *)(keyAddr + 0xc) * fVar6;
    fVar7 = *(float *)(keyAddr + 4);
    *outPos = *outPos + fVar7 * fVar6 + 0.0f;
    outPos[1] = outPos[1] + fVar4;
    outPos[2] = outPos[2] + fVar5;
    startIndex++;
    if (startIndex >= 4) {
      startIndex = 0;
    }
  }
  return;
}

/* Recovered battle-misc harvest: 0x0029F4B0-0x002A16C0 */




















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


void FUN_002a2c40(u8* curve,f32* outPos,f32 t)
{
  u8* nextKey;
  u16 nextIndex;
  u16 startIndex;
  float fVar4;
  float fVar5;
  float segmentLength;
  struct {
    float values[9];
    int mode;
  } interpolation;
  startIndex = *(u16 *)(curve + 0x74);
  segmentLength = fGpffff82c8;
  for (; !(t < segmentLength); t = t - segmentLength) {
    startIndex++;
  }
  t = t / segmentLength;
  if (startIndex >= 4) {
    startIndex = startIndex & 3;
  }
  nextIndex = startIndex + 1 & 0xffff;
  if (nextIndex >= 4) {
    nextIndex = startIndex + 1 & 3;
  }
  nextKey = curve + nextIndex * 0x1c + 0x10;
  curve = curve + startIndex * 0x1c + 0x10;
  FUN_004be310((float *)curve,(float *)nextKey,interpolation.values);
  if (t <= 0.0f) {
    *(RwV4d*)outPos = *(RwV4d*)curve;
  }
  else if (1.0f <= t) {
    *(RwV4d*)outPos = *(RwV4d*)nextKey;
  }
  else {
    fVar4 = 1.0f - t;
    if (interpolation.mode == 0) {
      fVar4 = fVar4 * interpolation.values[8];
      fVar5 = fVar4 * fVar4;
      fVar4 = fVar5 * fVar4 *
              (fVar5 * (fVar5 * (fVar5 * (fVar5 * (fGpffff83d4 * fVar5 + fGpffff8048 + 0.0f) +
                                         fGpffff8118 + 0.0f) + fGpffff8050 + 0.0f) + fGpffff8054 + 0.0f
                       ) + fGpffff83d8 + 0.0f) + fVar4 + 0.0f;
      t = t * interpolation.values[8];
      fVar5 = t * t;
      t = fVar5 * t *
                (fVar5 * (fVar5 * (fVar5 * (fVar5 * (fGpffff83d4 * fVar5 + fGpffff8048 + 0.0f) +
                                           fGpffff8118 + 0.0f) + fGpffff8050 + 0.0f) +
                         fGpffff8054 + 0.0f) + fGpffff83d8 + 0.0f) + t + 0.0f;
    }
    *outPos = interpolation.values[0] * fVar4;
    outPos[1] = interpolation.values[1] * fVar4;
    outPos[2] = interpolation.values[2] * fVar4;
    *outPos = interpolation.values[4] * t + *outPos + 0.0f;
    outPos[1] = interpolation.values[5] * t + outPos[1] + 0.0f;
    outPos[2] = interpolation.values[6] * t + outPos[2] + 0.0f;
    outPos[3] = interpolation.values[3] * fVar4 + interpolation.values[7] * t;
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
        curve = *(void* *)(param_1 + 0x98);
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
