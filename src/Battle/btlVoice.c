#include "Battle/btlVoice.h"
#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Battle/btlOrder.h"
#include "Battle/btlCamera.h"
#include "Battle/btlFormation.h"
#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/Battle/Data/datUnit.h"
#include "Kernel/Kwln/kwlnTask.h"
typedef struct
{
  u32 result;
  u32 state;
  u16 voiceId;
} BtlVoicePacketA03Work;

typedef struct
{
  u16 arg0;
  u16 arg1;
  u16 arg2;
  u16 flags;
  u32 state;
} BtlVoicePacketA04Work;

typedef struct
{
  u16 arg0;
  u16 arg1;
  u16 state;
} BtlVoicePacketC00Work;

typedef struct
{
  u16 voiceId;
} BtlVoicePacketC03Work;

typedef struct
{
  u32 arg0;
  u32 arg1;
  u32 arg2;
  u16 state;
} BtlVoicePacketC06Work;

typedef struct
{
  u32 voiceId;
  u32 param;
} BtlVoicePacketC09Work;

typedef struct
{
  u16 voiceId;
} BtlVoicePacketC0BWork;

typedef struct
{
  s16 frame;
  u32 state;
} BtlVoicePacketWaitWork;

typedef struct
{
  s16 frame;
} BtlVoicePacketC0AWork;

typedef struct
{
  s8 genus;
  u8 pad;
  u16 charId;
} BtlVoiceUnitEntry;

typedef struct
{
  f32 x;
  f32 z;
} VoiceXZ;
typedef struct
{
    s16 values[3];
} VoiceSlots;
typedef struct
{
    s16 values[2];
} VoiceSlotPair;
typedef struct
{
  f32 values[4];
} VoicePositions;



extern u32 btlVoice002e2a60(void* work);

// FUN_002e2be0
BtlPacket* btlVoice002e2be0(BtlAction* action, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    BtlPacket* packet;
    BtlVoicePacket002e2be0* work;

    packet = btlPacketCreate(BTLVOICE_PACKET_UNK01, sizeof(BtlVoicePacket002e2be0));

    packet->updateFunc = btlVoice002e2a60;

    work = (BtlVoicePacket002e2be0*)packet->workData;

    work->action = action;
    work->unk_04 = param_2;
    work->unk_08 = param_3;
    work->unk_0c = param_4;
    work->unk_10 = param_5;
    work->unk_14 = 0;

    return packet;
}

/* 2F battle runtime slice recovered from next_2f00_2fff_dump.c. */

#include "Battle/btlVoice.h"
#include "Utils.h"

#define CONCAT13(a, b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#define CONCAT44(a, b) ((((u64)(u32)(a)) << 32) | (u32)(b))

extern u8 DAT_0069a110[];
extern u8 DAT_0069a150[];
extern u8 DAT_0069a190[];
extern u8 DAT_0069a1d0[];
extern u8 DAT_0069a1d2[];
extern u8 DAT_0069a210[];
#pragma alias DAT_0069a210_abs DAT_0069a210
extern u8 DAT_0069a210_abs[];
extern s16 D_00699e60[];
extern s16 D_00699eb0[];
extern s16 D_00699f00[];
extern s16 D_00699f50[];
extern s16 D_00699f90[];
extern u8 DAT_0069a470[];
extern u8 DAT_0069a4f0[];
extern u8 DAT_0069a550[];
extern u8 DAT_0069a5c8[];
extern u32 DAT_0069a5cc;
extern u32 DAT_0069a5d0;
extern const char DAT_0069a5b8[];
extern u8 DAT_0069a5d8[];
extern u32 DAT_0069a5e0;
extern u8 DAT_0069a608[];
extern u32 DAT_0069a610;
extern u8 DAT_0069a618[];
extern u32 DAT_0069a61c;
extern u32 DAT_0069a620;
extern u8 DAT_0069a628[];
extern u8 DAT_0069a638[];
extern u8 DAT_0069a648[];
extern f32 D_00697880[];
extern const u8 D_006978B0[];
extern const u8 D_00699FE0[];
extern const u8 D_00699FF0[];
#pragma alias voiceStream115Both DAT_00699d80
#pragma alias voiceStream115First DAT_00699d90
#pragma alias voiceStream115Second DAT_00699da0
extern const char voiceStream115Both[];
extern const char voiceStream115First[];
extern const char voiceStream115Second[];
extern const u8 D_0069A368[];
#pragma alias voicePartyCameraStarts DAT_0069a3a0
#pragma alias voicePartyCameraEnds DAT_0069a3d0
#pragma alias voicePartyCameraTargets DAT_0069a400
#pragma alias voicePartyCameraUps DAT_0069a430
#pragma alias voicePartyCameraDurations DAT_0069a458
extern RwV3d voicePartyCameraStarts[];
extern RwV3d voicePartyCameraEnds[];
extern RwV3d voicePartyCameraTargets[];
extern RwV3d voicePartyCameraUps[];
extern f32 voicePartyCameraDurations[];
#pragma alias voiceCameraStart66 DAT_0069a250
#pragma alias voiceCameraEnd66 DAT_0069a270
#pragma alias voiceCameraTarget66 DAT_0069a290
#pragma alias voiceCameraUp66 DAT_0069a2b0
extern const RwV3d voiceCameraStart66;
extern const RwV3d voiceCameraEnd66;
extern const RwV3d voiceCameraTarget66;
extern const RwV3d voiceCameraUp66;
extern const u8 D_0069A2D0[];
extern const u8 D_0069A2F0[];
extern const u8 D_0069A310[];
extern const u8 D_0069A330[];
extern u32 DAT_0069a650;
extern u8 DAT_0069a658[];
extern u32 DAT_0069a65c;
extern u32 DAT_0069a660;
extern u8 DAT_0069a668[];
extern u8 DAT_0069a678[];
extern u8 DAT_0069a690[];
extern u32 DAT_0069a698;
extern u8 DAT_0069a6b0[];
extern u32 DAT_0069a6b4;
extern u32 DAT_0069a6b8;
extern u8 DAT_0069a6d0[];
extern u8 DAT_0069a6f0[];
extern u8 DAT_006a0000[];
extern u8 DAT_007cc970;
extern u32 DAT_007cc9e0;
extern u32 DAT_007cc9e2;
extern u32 DAT_007cc9e4;
extern s16 DAT_007cc9e8[3];
extern s16 DAT_007cc9f0;
extern s16 DAT_007cc9f2;
extern s16 DAT_007cc9f4;
extern u32 DAT_007ce3ec;
extern u32 DAT_007ce4bc;
extern u32 DAT_007ce4d0;
extern u8* iGpffffb6fc;
#pragma alias iGpffffb6fc_ptr DAT_007ce3ec
extern u8* iGpffffb6fc_ptr;
#define iGpffffb6fc ((u8*)DAT_007ce3ec)
extern u32 iGpffffb708;
extern u32 gp0xffff9c80;
extern u32 uGpffff82dc;
extern u32 uGpffff82e0;
#pragma alias uGpffff82dc_f32_voice uGpffff82dc
extern f32 uGpffff82dc_f32_voice;
#pragma alias uGpffff82e0_f32_voice uGpffff82e0
extern f32 uGpffff82e0_f32_voice;
extern s16 uGpffff9cd0;
extern s16 uGpffff9cd2;
extern s16 uGpffff9cd4;
extern s16 uGpffff9cd8;
extern s16 uGpffff9cda;
extern s16 uGpffff9cdc;
extern s16 uGpffff9ce0;
extern s16 uGpffff9ce2;
extern s16 uGpffff9ce4;
extern s16 uGpffff9ce8;
extern s16 uGpffff9cea;
extern s16 uGpffff9cec;
extern u64 FUN_001757f0();
extern u64 FUN_0017b220();
extern u64 FUN_001fdd40();
extern u64 FUN_0027ce50();
extern u64 FUN_0027e390();
extern u64 FUN_0027ed20();
extern u64 FUN_0027f410();
extern u64 FUN_0027f650();
extern u64 FUN_0027f730();
extern u64 FUN_0027f930();
extern u64 FUN_0027fe90();
extern u64 FUN_00280050();
extern u64 FUN_00280480();
extern f32 FUN_002812d0(BtlUnit* unit, BtlUnit* target, s32 id);
extern u64 FUN_002822b0();
extern u64 FUN_002831c0();
extern s16 FUN_002835e0(f32 param_1, u32 param_2, u16 param_3);
extern u64 FUN_00284200();
extern u64 FUN_00285690();
extern u64 FUN_00285d30();
extern u64 FUN_00287490();
extern u64 FUN_00287510();
extern u64 FUN_00287580();
extern u64 FUN_00287b20();
extern u64 FUN_002889c0();
extern u64 FUN_00288f80();
extern u64 FUN_00289650();
extern BtlAction* FUN_0029a1d0();
extern u64 FUN_0029a2c0();
extern u64 FUN_0029a320();
extern u64 FUN_0029ad20();
#pragma alias btlActionCurrent FUN_0029ad20
extern BtlAction* btlActionCurrent(void);
extern u64 FUN_0029ea60();
extern u64 FUN_0029ec00();
extern u64 FUN_0029ec50();
extern u64 FUN_0029ec80();
extern u64 FUN_0029f4b0();
extern BtlPacket* FUN_0029fa50(u32 param);
extern u64 FUN_002a0050();
extern BtlPacket* FUN_002a1080(s32 param, s16 mode);
extern u64 FUN_002a1280();
extern BtlPacket* FUN_002a16c0(s32 param);
extern u64 FUN_002a1b00();
extern u64 FUN_002a1db0();
extern void FUN_002a2170(void *param_1, const f32 *param_2);
extern void FUN_002a2290(void *param_1, const f32 *param_2, const f32 *param_3, int param_4);
extern void FUN_002a3110(void *param_1, float param_2);
extern u64 FUN_002a3b40();
extern u64 FUN_002a3d70();
extern void FUN_002a3e80(float param_1, u8 *param_2,
                         u8 *param_3, u8 *param_4, u32 param_5);
extern void FUN_002a4690(void *param_1, const void *param_2, const void *param_3, const void *axis);
extern u64 FUN_002b71e0();
extern u64 FUN_002b8d60();
extern u64 FUN_002b8f90();
extern u64 FUN_002b9030();
extern u64 FUN_002b90d0();
extern u64 FUN_002bac00();
extern u64 FUN_002baf90();
extern u64 FUN_002bb2f0();
extern u64 FUN_002bb6f0();
extern u64 FUN_002bc7e0();
extern u64 FUN_002bc890();
extern u64 FUN_002bd480();
extern u64 FUN_002bd590();
extern u64 FUN_002bd850();
extern u64 FUN_002bdbd0();
extern u64 FUN_002c3770();
extern u64 FUN_002d1d00();
extern void FUN_002d2280();
extern u64 FUN_002d5dc0();
extern u32 FUN_002d5e10();
extern u32 FUN_002d6370(s16 commandId);
extern u64 FUN_002d6620();
extern u64 FUN_002d7890();
extern u64 FUN_002d7e20();
extern u64 FUN_002db740();
extern u64 FUN_002db800();
extern u64 FUN_002db890();
extern u64 FUN_002dce90();
extern u64 FUN_002dd100();
extern u64 FUN_002dd4a0();
extern u64 FUN_002dd5e0();
extern u64 FUN_002dd690();
extern u64 FUN_002dd760();
extern u64 FUN_002e4220();
extern u32 FUN_002e4250();
extern u64 FUN_002f87e0();
extern u64 FUN_002f8810();
extern void FUN_002fddb0(BtlUnit* unit, RwV3d* position);
extern u64 FUN_002ff540();
extern u32 FUN_002ffbc0();
extern u64 FUN_002ffd90();
extern u64 FUN_002ffdc0();
extern u64 FUN_002ffdf0();
extern u64 FUN_00300100();
extern u64 FUN_00300560();
extern u64 FUN_00301540();
extern u64 FUN_00301750();
extern u64 FUN_00302380();
extern u64 FUN_0030b5a0();
extern void FUN_00352c50(u32 param_1, u32 param_2, u32 param_3);
extern u64 FUN_00357fd0();
extern u32 FUN_0035c090();
extern u64 FUN_00395170();
extern u32 FUN_003951d0();
extern float FUN_004c69f0(void* dst, const void* src);
extern u64 FUN_00521408();
extern u64 FUN_00523ac8();
u32 func_002f6c20(void);
void func_002e4220(u32 initFunc, u32 updateFunc, u32 action);
void func_002f3a80(BtlAction* action);
u32 func_002f43a0(BtlAction* action);
void func_002f4410(BtlAction* unused);
u32 func_002f4480(BtlAction* action);
void* func_002b8f90(s32 param);
void func_002b9030(void* object);
void func_002b90d0(void* object, void* file);
BtlPacket* func_002baf90(void* object, BtlUnit* source,
                         BtlUnit* target, u16 param, u32 flags);
BtlPacket* func_002bc890(u8* data, u16 param);
void* func_002f87e0(u16 index);
 #pragma alias DAT_007ce3ec_ptr_voice DAT_007ce3ec
 extern u8* DAT_007ce3ec_ptr_voice;
 #pragma alias FUN_002b8f90_u32_voice FUN_002b8f90
 extern u32 FUN_002b8f90_u32_voice(u16 param);
 #pragma alias FUN_002f87e0_u32_voice FUN_002f87e0
 extern u32 FUN_002f87e0_u32_voice(u16 index);
 #pragma alias FUN_002b8d60_u32_voice FUN_002b8d60
 extern u32 FUN_002b8d60_u32_voice(u32 mode, u32 flags);
 #pragma alias FUN_002baf90_u32_voice FUN_002baf90
 extern u32 FUN_002baf90_u32_voice(u32 object, u32 source,
                                     u32 target, u16 param, u32 flags);
 #pragma alias FUN_00284200_u32_voice FUN_00284200
 extern u32 FUN_00284200_u32_voice(u32, u32, u32, u32, u32);
 #pragma alias FUN_0027fe90_u32_voice FUN_0027fe90
 extern u32 FUN_0027fe90_u32_voice(u32, u32, u32, u32);
 #pragma alias FUN_002a3b40_u32_voice FUN_002a3b40
 extern u32 FUN_002a3b40_u32_voice(u32, u32);
 #pragma alias FUN_002b90d0_voice FUN_002b90d0
 extern void FUN_002b90d0_voice(u32 object, u32 file);
 #pragma alias FUN_0027ed20_voice FUN_0027ed20
 extern void FUN_0027ed20_voice(u32 packet, u32 mode);
 #pragma alias FUN_002bc950_u32_voice FUN_002bc950
 extern u32 FUN_002bc950_u32_voice();
 #pragma alias FUN_00284200_packet_voice FUN_00284200
 extern BtlPacket* FUN_00284200_packet_voice(f32, BtlUnit*, u16, u16, u16);
 #pragma alias FUN_002b8d60_packet_voice FUN_002b8d60
 extern BtlPacket* FUN_002b8d60_packet_voice(u16, u16);
 #pragma alias FUN_0027fe90_packet_voice FUN_0027fe90
 extern BtlPacket* FUN_0027fe90_packet_voice(BtlUnit*, const void*, const void*, const void*);
 #pragma alias FUN_002a3b40_packet_voice FUN_002a3b40
 extern BtlPacket* FUN_002a3b40_packet_voice(void*, u32);
 #pragma alias FUN_002baf90_packet_voice FUN_002baf90
 extern BtlPacket* FUN_002baf90_packet_voice(void*, BtlUnit*, BtlUnit*, u16, u32);
#pragma alias FUN_002d1d00_packet_voice FUN_002d1d00
extern BtlPacket* FUN_002d1d00_packet_voice(BtlAction*, u16, const char*);
#pragma alias FUN_002bac00_packet_voice FUN_002bac00
extern BtlPacket* FUN_002bac00_packet_voice(u32, void*, u16);
#pragma alias FUN_0029ec00_u32_voice FUN_0029ec00
extern u32 FUN_0029ec00_u32_voice(s32);
#pragma alias FUN_0029ec50_u32_voice FUN_0029ec50
extern u32 FUN_0029ec50_u32_voice(s32);
 
 
#pragma alias FUN_002d7e20_packet_voice FUN_002d7e20
extern BtlPacket* FUN_002d7e20_packet_voice(BtlAction*, BtlAction*, void*, u16, u16);
 
#pragma alias FUN_002dd690_packet_voice FUN_002dd690
extern BtlPacket* FUN_002dd690_packet_voice(u16 channel, const char* streamName);
#pragma alias FUN_002bd590_packet_voice FUN_002bd590
extern BtlPacket* FUN_002bd590_packet_voice(BtlUnit* unit, u16 id);
#pragma alias FUN_002bc7e0_packet_voice FUN_002bc7e0
extern BtlPacket* FUN_002bc7e0_packet_voice(u16 type);
#pragma alias FUN_002a3d70_packet_voice FUN_002a3d70
extern BtlPacket* FUN_002a3d70_packet_voice(BtlAction*, const RwV3d*, const RwV3d*, const RwV3d*, const RwV3d*, f32);
#pragma alias FUN_002dd4a0_packet_voice FUN_002dd4a0
extern BtlPacket* FUN_002dd4a0_packet_voice(u16, u16);
#pragma alias FUN_002dd5e0_packet_voice FUN_002dd5e0
extern BtlPacket* FUN_002dd5e0_packet_voice(u16);
#pragma alias FUN_002bd850_packet_voice FUN_002bd850
extern BtlPacket* FUN_002bd850_packet_voice(BtlUnit*, s16);
#pragma alias FUN_002db890_packet_voice FUN_002db890
extern BtlPacket* FUN_002db890_packet_voice(void);
#pragma alias FUN_002db800_packet_voice FUN_002db800
extern BtlPacket* FUN_002db800_packet_voice(u16, u32);
#pragma alias FUN_002dd760_packet_voice FUN_002dd760
extern BtlPacket* FUN_002dd760_packet_voice(u16, void*, u32);
#pragma alias FUN_0027f410_packet_voice FUN_0027f410
extern BtlPacket* FUN_0027f410_packet_voice(u32, u32);
#pragma alias FUN_002dd830_packet_voice FUN_002dd830
extern BtlPacket* FUN_002dd830_packet_voice(BtlUnit*, u16, u16, u16);
#pragma alias FUN_002f8810_ptr_voice FUN_002f8810
extern void* FUN_002f8810_ptr_voice(void);
#pragma alias FUN_002822b0_packet_voice FUN_002822b0
extern BtlPacket* FUN_002822b0_packet_voice(BtlUnit*, RwV3d*, u32);
#pragma alias FUN_00285d30_packet_voice FUN_00285d30
extern BtlPacket* FUN_00285d30_packet_voice(BtlUnit*, u32, u16, u16, u8, u8);
#pragma alias FUN_00285690_packet_voice FUN_00285690
extern BtlPacket* FUN_00285690_packet_voice(BtlUnit*, u16, u16);
#pragma alias FUN_0029f4b0_packet_voice FUN_0029f4b0
extern BtlPacket* FUN_0029f4b0_packet_voice(u32, u32, u32);
#pragma alias FUN_002a0050_packet_voice FUN_002a0050
extern BtlPacket* FUN_002a0050_packet_voice(BtlPacket*, u32, u32, u32, u32);
#pragma alias FUN_002a1280_packet_voice FUN_002a1280
extern BtlPacket* FUN_002a1280_packet_voice(BtlPacket*, u32);
#pragma alias FUN_002bb2f0_packet_voice FUN_002bb2f0
extern BtlPacket* FUN_002bb2f0_packet_voice(u32, BtlUnit*, u32, u64, u32);
#pragma alias FUN_002dd100_packet_voice FUN_002dd100
extern BtlPacket* FUN_002dd100_packet_voice(u32, u32, u32);
#pragma alias FUN_002a1db0_packet_voice FUN_002a1db0
extern BtlPacket* FUN_002a1db0_packet_voice(u32);
#pragma alias FUN_002a1b00_packet_voice FUN_002a1b00
extern BtlPacket* FUN_002a1b00_packet_voice(BtlAction*, s16, s32);
#pragma alias FUN_002a1b00_voice FUN_002a1b00
extern void FUN_002a1b00_voice(s32, s16, s32);
#pragma alias FUN_002d4e10_u16_voice FUN_002d4e10
extern u16 FUN_002d4e10_u16_voice(u16, u32);


// FUN_002f0580
s32 func_002f0580(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        FUN_00352c50(0, 0, 0);
        return 0;
    }

    return 1;
}

// FUN_002f05f0 NONMATCHING
void func_002f05f0(BtlAction *action)
{
    BtlAction* current;
    BtlUnit* childUnit;
    BtlPacket* packet;
    BtlPacket* rootPacket;
    u64 actionUID;
    u64 rootUID;
    BtlPacket* voicePacket;
    BtlPacket* effectPacket;
    void* object;
    void* file;
    struct {
        u8 pad[0x20];
        RwV3d position;
        u32 gap;
        BtlUnit* units[3];
    } scratch;
    u32 value0;
    u32 value1;
    u32 voiceData;
    s16 voiceId;
    s16 childId;
    u32 i;

    voiceId = *(s16*)((u8*)action + 0x6e);
    actionUID = action->uid;

    object = func_002b8f90(0);
    file = func_002f87e0(6);
    func_002b90d0(object, file);

    packet = FUN_002bd590_packet_voice(action->unit, voiceId);
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 3);
    

    rootPacket = FUN_00284200_packet_voice(1.0f, action->unit, 0, 0, 1);
    rootPacket->actionUID = actionUID;
    btlPacketRegister(rootPacket, 1);
    rootUID = rootPacket->uid;

    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    packet = FUN_0027fe90_packet_voice(action->unit, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    packet = FUN_002a3b40_packet_voice(action, 0x11);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    FUN_002fddb0(action->unit, &scratch.position);
    packet = FUN_002822b0_packet_voice(action->unit, &scratch.position, 0);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);
    for (current = *(BtlAction**)(DAT_007ce3ec + 0x14c);
         current != NULL;
         current = current->prev) {
        if ((current != action) && ((current->unk_1a & 1) != 0)) {
            packet = FUN_00285d30_packet_voice(current->unit, 0xffffff, 0, 0, 2, 0);
            packet->unk_00 = 4;
            packet->parentUID = rootUID;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, 0);
        }
    }

    FUN_0029ea60(voiceId, &value1, &value0);
    packet = FUN_0029f4b0_packet_voice(value1, value0, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = (BtlPacket*)FUN_0029ec00(voiceId);
    FUN_0029ec80(voiceId, &value1, &value0);
    packet = FUN_002a0050_packet_voice(packet, value1, value0, 0x10, 0);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = (BtlPacket*)FUN_0029ec50(voiceId);
    packet = FUN_002a1280_packet_voice(packet, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);
    packet = FUN_002a1b00_packet_voice(action, 0, 0x10);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    for (i = 0; i < 3; i++) {
        childId = action->target.unk_3e[i];
        voiceData = (u32)FUN_002ff540(*(u32*)(DAT_007ce3ec + 0xbbc), childId);
        childUnit = ((BtlAction*)FUN_00289650(1, childId, voiceData))->unit;
        scratch.units[i] = childUnit;
        FUN_002889c0(childUnit, childId);

        voicePacket = FUN_00285690_packet_voice(childUnit, childId, 0x17e);
        voicePacket->unk_00 = 4;
        voicePacket->parentUID = rootUID;
        voicePacket->preUpdateDelay = 0x1e;
        voicePacket->actionUID = actionUID;
        btlPacketRegister(voicePacket, 1);

        packet = FUN_00285d30_packet_voice(childUnit, 0xffffffffu, 0, 0, 1, 1);
        packet->unk_00 = 4;
        packet->parentUID = voicePacket->uid;
        packet->preUpdateDelay = 1;
        packet->actionUID = actionUID;
        btlPacketRegister(packet, 1);
    }

    FUN_00352c50((u32)scratch.units[0], (u32)scratch.units[1], (u32)scratch.units[2]);
    FUN_002b71e0();
    scratch.position.x = 0.0f;
    scratch.position.y = -1000.0f;
    scratch.position.z = 0.0f;
    for (i = 0; i < 3; i++) {
        FUN_0027f650((u32)scratch.units[i], &scratch.position);
    }

    packet = FUN_002bb2f0_packet_voice(*(u32*)(DAT_007ce3ec + 0xca8),
                                       action->unit, 0, voicePacket->uid, 0x300);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002dd100_packet_voice(10, 2, 5);
    packet->unk_00 = 4;
    packet->parentUID = rootUID;
    btlPacketRegister(packet, 1);

    effectPacket = FUN_002baf90_packet_voice(object, action->unit, action->unit, 0, 0x200);
    effectPacket->unk_00 = 4;
    effectPacket->parentUID = voicePacket->uid;
    effectPacket->actionUID = actionUID;
    btlPacketRegister(effectPacket, 2);

    packet = FUN_0027f410_packet_voice(0x2efd20, (u32)action->unit);
    packet->unk_00 = 5;
    packet->parentUID = effectPacket->uid;
    packet->preUpdateDelay = 0x78;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = effectPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002a3b40_packet_voice(action, 0x25);
    packet->unk_00 = 4;
    packet->parentUID = effectPacket->uid;
    packet->postUpdateDelay = 0x1e;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    for (current = *(BtlAction**)(DAT_007ce3ec + 0x14c);
         current != NULL;
         current = current->prev) {
        if ((current != action) && ((current->unk_1a & 1) != 0)) {
            packet = FUN_00285d30_packet_voice(current->unit, 0xffffffffu, 0, 0, 1, 0);
            packet->unk_00 = 4;
            packet->parentUID = effectPacket->uid;
            packet->actionUID = actionUID;
            btlPacketRegister(packet, 0);
        }
    }

    FUN_001fdd40();
    packet = FUN_0029fa50(0x10);
    packet->unk_47 &= ~0x20;
    packet->parentUID = effectPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002a1080(0x10, 0);
    packet->unk_47 &= ~0x20;
    packet->parentUID = effectPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002a16c0(0x10);
    packet->unk_47 &= ~0x20;
    packet->parentUID = effectPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 1);

    packet = FUN_002a1db0_packet_voice(8);
    packet->unk_47 &= ~0x20;
    packet->parentUID = effectPacket->uid;
    packet->actionUID = actionUID;
    btlPacketRegister(packet, 0);

    func_002b9030(object);
}

// FUN_002f0e30
s32 func_002f0e30(BtlAction* action)
{
    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        FUN_00352c50(0, 0, 0);
        return 0;
    }

    return 1;
}

// FUN_002f0ea0 NONMATCHING
void func_002f0ea0(u64 *param_1)

{
  /* Caller-specific return width: retail consumes only the s32 result in this path. */
  extern s32 FUN_0030b5a0();
  u16 sVar1;
  u32 bVar2;
  u8 *puVar3;
  int iVar4;
  u8 *puVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  BtlPacket* packet;
  u32 uVar9;
  s32 lVar10;
  s32 uVar11;
  s32 uVar12;
  int iVar13;
  int iVar14;
  int initialPacket;
  
  uVar11 = (u32)*(u16 *)(iGpffffb6fc + 0xb50);
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  uVar12 = 0;
  iVar14 = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    lVar10 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0);
    if (lVar10 == 0) {
      sVar1 = *(short *)(iVar4 + 0xa4);
      if (((sVar1 == 0x118) || (sVar1 == 0x117)) || (sVar1 == 0x116)) {
        uVar12 = uVar12 + 1 & 0xffff;
      }
      else if (sVar1 == 0x10d) {
        iVar14 = iVar4;
      }
    }
  }
  bVar2 = uVar12 == uVar11;
  uVar6 = FUN_002b8f90_u32_voice(0);
  uVar7 = FUN_002b8f90_u32_voice(0);
  if (uVar11 == 1) {
    uVar8 = FUN_002f87e0_u32_voice(2);
    FUN_002b90d0(uVar6,uVar8);
  }
  else {
    uVar8 = FUN_002f87e0_u32_voice(3);
    FUN_002b90d0(uVar6,uVar8);
  }
  if (!bVar2) {
    uVar8 = FUN_002f87e0_u32_voice(4);
    FUN_002b90d0(uVar7,uVar8);
  }
  else {
    uVar8 = FUN_002f87e0_u32_voice(5);
    FUN_002b90d0(uVar7,uVar8);
  }
  iVar4 = 0;
  uVar8 = 0;
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar4 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)*(u32 *)(iVar4 + 0x30),0x12,0,2);
    *(u16 *)((int)uVar8 + 0x48) = 2;
    *(u64 *)((int)uVar8 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  initialPacket = (int)uVar8;
  uVar9 = (u32)FUN_002f8810_ptr_voice();
  uVar9 = (u32)FUN_002dd760_packet_voice(3,(void *)uVar9,0);
  *(u16 *)((int)uVar9 + 0x48) = 2;
  *(u64 *)((int)uVar9 + 0x60) = *param_1;
  FUN_0027ed20(uVar9,1);
  puVar3 = (u8 *)FUN_002b8d60_packet_voice(3,0xfff);
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(initialPacket + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20((u32)puVar3,1);
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar4 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = (u32)FUN_0027fe90_packet_voice((BtlUnit *)*(u32 *)(iVar4 + 0x30),0,(const void *)0x6978b0,0);
    puVar3 = (u8 *)uVar8;
    *puVar3 = 4;
    *(u64 *)(puVar3 + 8) = *(u64 *)(initialPacket + 0x58);
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  uVar8 = (u32)FUN_002a3b40_packet_voice(0,1);
  puVar3 = (u8 *)uVar8;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(initialPacket + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar8,0);
  packet = FUN_002baf90_packet_voice((void*)uVar6, (BtlUnit*)*(u32 *)(iVar4 + 0x30), (BtlUnit*)*(u32 *)(iVar4 + 0x30), 0, 0x200);
  *(u64 *)((u8 *)packet + 0x60) = *param_1;
  FUN_0027ed20((u32)packet,2);
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar13 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = (u32)FUN_002baf90_packet_voice((void *)uVar6,(BtlUnit *)*(u32 *)(iVar13 + 0x30),(BtlUnit *)*(u32 *)(iVar13 + 0x30),1,0x200);
    puVar3 = (u8 *)uVar8;
    *puVar3 = 5;
    *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
    *(u16 *)(puVar3 + 0x48) = 0x37;
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,2);
    uVar8 = (u32)FUN_00285d30_packet_voice((BtlUnit *)*(u32 *)(iVar13 + 0x30),0xffffff,6,0,4,0);
    puVar3 = (u8 *)uVar8;
    *puVar3 = 5;
    *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
    *(u16 *)(puVar3 + 0x48) = 0x41;
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  if (!bVar2) {
    uVar8 = (u32)FUN_0027f410_packet_voice(0x2efdb0,iVar14);
    *(u8 *)uVar8 = 4;
    *(u64 *)((u8 *)uVar8 + 8) = *(u64 *)(iVar4 + 0x58);
    FUN_0027ed20(uVar8,1);
    lVar10 = (s32)btlActionCurrent();
    if (lVar10 != 0) {
      *(u16 *)((int)lVar10 + 0x18) = *(u16 *)((int)lVar10 + 0x18) | 8;
    }
  }
  uVar8 = (u32)FUN_002baf90_packet_voice((void *)uVar7,(BtlUnit *)iVar14,(BtlUnit *)iVar14,0,0x200);
  puVar3 = (u8 *)uVar8;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar8,2);
  if ((!bVar2) && (*(int *)(iGpffffb6fc + 0xb60) == 0)) {
    puVar5 = (u8 *)FUN_002db890_packet_voice();
    *puVar5 = 5;
    *(u64 *)(puVar5 + 8) = *(u64 *)(puVar3 + 0x58);
    *(u16 *)(puVar5 + 0x48) = 0x41;
    FUN_0027ed20((u32)puVar5,1);
    puVar5 = (u8 *)FUN_002db800_packet_voice(0x20,0x31);
    *puVar5 = 5;
    *(u64 *)(puVar5 + 8) = *(u64 *)(puVar3 + 0x58);
    *(u16 *)(puVar5 + 0x48) = 0x41;
    FUN_0027ed20((u32)puVar5,1);
    *(u32 *)(iGpffffb6fc + 0xb60) = 1;
  }
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x400000;
  *(u16 *)(iGpffffb6fc + 0x18) = *(u16 *)(iGpffffb6fc + 0x18) | 7;
  FUN_002b9030(uVar7);
  FUN_002b9030(uVar6);
  return;
}

// FUN_002f14a0 NONMATCHING
u32 func_002f14a0(BtlAction* action)
{
    u16 actionIndex;
    u16 count;
    BtlAction* cleanupAction;
    BtlAction* current;
    BtlPacket* packet;
    u16 cleanupIndex;
    count = *(u16*)(iGpffffb6fc + 0xb50);
    for (actionIndex = 0; (actionIndex & 0xffff) < count;
         actionIndex = (actionIndex + 1) & 0xffff)
    {
        current = *(BtlAction**)(iGpffffb6fc + (actionIndex & 0xffff) * 4 + 0xb44);
        if (current != btlActionCurrent())
        {
            if ((current->unit->flags3 & BTLUNIT_FLAG3_ENDURE) != 0)
            {
                return 1;
            }
        }
        else
        {
            current->unit->flags3 &= ~BTLUNIT_FLAG3_ENDURE;
        }
    }

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        for (cleanupIndex = 0; (cleanupIndex & 0xffff) < count;
             cleanupIndex = (cleanupIndex + 1) & 0xffff)
        {
            cleanupAction = *(BtlAction**)(iGpffffb6fc + (cleanupIndex & 0xffff) * 4 + 0xb44);
            FUN_002d7890(cleanupAction, 0);
            FUN_0029a320(cleanupAction);
        }
        *(u16*)(iGpffffb6fc + 0xb50) = 0;
        gBtl->flags |= 0x2000000;
        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002f1680
void func_002f1680(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];
  
  puVar6 = (u32*)DAT_0069a110;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&uGpffff9cd0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0xc3020000;
      uStack_10.raw[2] = 0x43480000;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(iGpffffb6fc + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x108:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3960000;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

/* Removing this loses FUN_002f1810 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f1810
void func_002f1810(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0x108:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f19d0
void func_002f19d0(void)
{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];

  puVar6 = (u32*)DAT_0069a150;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&uGpffff9cd8;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0xc3020000;
      uStack_10.raw[2] = 0x43480000;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(iGpffffb6fc + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x10f:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3960000;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

// FUN_002f1b60
u32 func_002f1b60(BtlAction* action, f32* position)
{
  BtlUnit* unit;
  BtlUnit* target;
  RwV3d sourcePosition;
  RwV3d targetPosition;
  RwV3d direction;
  u16 moveId;
  f32 distance;
  u32 result;

  unit = action->unit;
  if (unit->genus != UNIT_GENUS_EC) {
    result = 0;
  }
  else {
    if (unit->charId != 0x10f) {
      result = 0;
    }
    else {
      if (action->target.targetedCount != 1) {
        result = 0;
      }
      else {
        if (action->target.commandId != 2) {
          result = 0;
        }
        else {
          if ((*(u8 *)(iGpffffb708 + action->target.specificId * 0x2c) & 2) == 0) {
            result = 0;
          }
          else {
            target = action->target.targetedActions[0]->unit;
            FUN_00280050(unit, &sourcePosition);
            FUN_00280480(target, unit, &targetPosition);
            direction.x = sourcePosition.x - targetPosition.x;
            direction.z = sourcePosition.z - targetPosition.z;
            direction.y = 0.0f;
            FUN_004c69f0(&direction, &direction);
            if (FUN_002d5e10(action) != 0) {
              moveId = 0xb;
            }
            else {
              moveId = 4;
            }
            distance = FUN_002812d0(unit, target, moveId);
            direction.x *= distance;
            direction.y *= distance;
            direction.z *= distance;
            position[0] = targetPosition.x + direction.x;
            position[1] = targetPosition.y + direction.y;
            position[2] = targetPosition.z + direction.z;
            result = 1;
          }
        }
      }
    }
  }
  return result;
}

/* Removing this loses FUN_002f1d40 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f1d40
void func_002f1d40(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0x10f:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f1f00
void func_002f1f00(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];
  
  puVar6 = (u32*)DAT_0069a190;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&uGpffff9ce0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0xc3020000;
      uStack_10.raw[2] = 0x43480000;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(iGpffffb6fc + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x110:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3960000;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

/* Removing this loses FUN_002f2090 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f2090
void func_002f2090(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0x110:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f2250
void func_002f2250(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];
  puVar6 = (u32*)DAT_0069a210;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&uGpffff9ce8;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(iGpffffb6fc_ptr + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0x43160000;
      uStack_10.raw[2] = 0x43fa0000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(iGpffffb6fc_ptr + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    uStack_10.raw[0] = 0;
    uStack_10.raw[2] = 0xc3fa0000;
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

// FUN_002f23d0
u32 func_002f23d0(int param_1)

{
  FUN_00302380(*(u32 *)(param_1 + 0xa2c),0x4000000,1);
  *(u32 *)(iGpffffb6fc + 0xb50) = 1;
  return 1;
}

// FUN_002f2410
u32 func_002f2410(int param_1)

{
  FUN_00301540(*(u32 *)(param_1 + 0xa2c),0xb);
  *(u32 *)(iGpffffb6fc + 0xb50) = 0;
  return 1;
}

void func_002f2550(BtlAction* action);
u32 func_002f2840(BtlAction* action);

void func_002f2890(BtlAction* param_1);
u32 func_002f2b40(BtlAction* action);

// FUN_002f2450
void func_002f2450(u32 param_1)

{
  *(u32 *)(iGpffffb6fc + 0xb4c) = *(u32 *)(param_1 + 0x20);
  FUN_002e4220((u32)func_002f2550,(u32)func_002f2840,param_1);
  return;
}

// FUN_002f2490
void func_002f2490(u32 param_1)

{
  FUN_002e4220((u32)func_002f2890,(u32)func_002f2b40,param_1);
  return;
}

// FUN_002f24d0
u32 func_002f24d0(void)

{
  char cVar1;
  
  cVar1 = FUN_00301750(*(u32 *)(*(int *)(iGpffffb6fc + 0x158) + 0xa2c),0xb);
  return '\0' < cVar1;
}

// FUN_002f2510
int func_002f2510(int param_1)

{
  int* frame;
  int previous;
  int current;
  int result;

  frame = (int *)(iGpffffb6fc + 0xb4c);
  previous = *frame;
  current = *(int *)(param_1 + 0x20);
  if (current >= previous) {
    result = current - previous;
  }
  else {
    *frame = current;
    result = 0;
  }
  return result;
}
// FUN_002f2550 NONMATCHING
void func_002f2550(BtlAction* action)
{
  BtlUnit* unit;
  void* object;
  BtlPacket* actionPacket;
  BtlPacket* packet;
  BtlPacket* parent;

  unit = gBtl->unitLists[UNIT_GENUS_EC].head;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(3));
  packet = FUN_002bd590_packet_voice(unit, 0x66);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 3);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->preUpdateDelay = 3;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002bc7e0_packet_voice(8);
  packet->preUpdateDelay = 3;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002a3d70_packet_voice(*(BtlAction**)(DAT_007ce3ec + 0x148),
                                     &voiceCameraStart66, &voiceCameraEnd66,
                                     &voiceCameraTarget66, &voiceCameraUp66,
                                     uGpffff82e0_f32_voice);
  packet->preUpdateDelay = 3;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  parent = FUN_002dd4a0_packet_voice(0x66, 0);
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  actionPacket = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  actionPacket->unk_00 = 4;
  actionPacket->parentUID = parent->uid;
  actionPacket->actionUID = action->uid;
  btlPacketRegister(actionPacket, 2);
  packet = FUN_002dd5e0_packet_voice(0);
  packet->unk_00 = 5;
  packet->parentUID = actionPacket->uid;
  btlPacketRegister(packet, 1);
  actionPacket = FUN_002baf90_packet_voice(object, unit, unit, 1, 0x200);
  actionPacket->unk_00 = 4;
  actionPacket->parentUID = parent->uid;
  actionPacket->actionUID = action->uid;
  btlPacketRegister(actionPacket, 2);
  packet = FUN_002dd5e0_packet_voice(1);
  packet->unk_00 = 5;
  packet->parentUID = actionPacket->uid;
  btlPacketRegister(packet, 1);
  parent = FUN_002bd850_packet_voice(unit, 0x45);
  parent->postUpdateWaits[0].type = 5;
  parent->postUpdateWaits[0].value = actionPacket->uid;
  parent->preUpdateDelay = 0x9b;
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 3);
  packet = FUN_0027f410_packet_voice((u32)func_002f23d0, (u32)unit);
  packet->unk_00 = 5;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  func_002b9030(object);
}

// FUN_002f2840
u32 func_002f2840(BtlAction* action)
{
  u64 lVar1;

  lVar1 = FUN_0027e390(action->uid,0x3fffffffffffffff);
  return lVar1 != 0;

}
// FUN_002f2890
void func_002f2890(BtlAction* action)
{
  BtlUnit* unit;
  void* object;
  BtlPacket* actionPacket;
  BtlPacket* packet;
  BtlPacket* parent;
  u32 index;
  unit = gBtl->unitLists[UNIT_GENUS_EC].head;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(4));
  {
    BtlPacket* introPacket;
    introPacket = FUN_002bd590_packet_voice(unit, 0x67);
    introPacket->actionUID = action->uid;
    btlPacketRegister(introPacket, 3);
  }
  {
    BtlPacket* introPacket;
    introPacket = FUN_002b8d60_packet_voice(3, 0xfff);
    introPacket->preUpdateDelay = 3;
    introPacket->actionUID = action->uid;
    btlPacketRegister(introPacket, 0);
  }
  {
    BtlPacket* introPacket;
    introPacket = FUN_002bc7e0_packet_voice(8);
    introPacket->preUpdateDelay = 3;
    introPacket->actionUID = action->uid;
    btlPacketRegister(introPacket, 0);
  }
  index = (FUN_002ffbc0(100) < 0x32) * 0xc;
  {
    BtlPacket* introPacket;
    introPacket = FUN_002a3d70_packet_voice(*(BtlAction**)(DAT_007ce3ec + 0x148),
                                           (const RwV3d*)(D_0069A2D0 + index),
                                           (const RwV3d*)(D_0069A2F0 + index),
                                           (const RwV3d*)(D_0069A310 + index),
                                           (const RwV3d*)(D_0069A330 + index),
                                           uGpffff82dc_f32_voice);
    introPacket->preUpdateDelay = 3;
    introPacket->actionUID = action->uid;
    btlPacketRegister(introPacket, 0);
  }
  parent = FUN_002dd4a0_packet_voice(0x67, 0);
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  actionPacket = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  actionPacket->unk_00 = 4;
  actionPacket->parentUID = parent->uid;
  actionPacket->actionUID = action->uid;
  btlPacketRegister(actionPacket, 2);
  {
    BtlPacket* waitPacket;
    waitPacket = FUN_002dd5e0_packet_voice(0);
    waitPacket->unk_00 = 5;
    waitPacket->parentUID = actionPacket->uid;
    btlPacketRegister(waitPacket, 1);
  }
  packet = FUN_002bd850_packet_voice(unit, 0x47);
  packet->postUpdateWaits[0].type = 5;
  packet->postUpdateWaits[0].value = actionPacket->uid;
  packet->actionUID = action->uid;
  packet->preUpdateDelay = 0x28;
  btlPacketRegister(packet, 3);
  {
    BtlPacket* waitPacket;
    waitPacket = FUN_0027f410_packet_voice((u32)func_002f2410,
                                           (u32)unit);
    waitPacket->unk_00 = 5;
    waitPacket->parentUID = packet->uid;
    waitPacket->actionUID = action->uid;
    btlPacketRegister(waitPacket, 1);
  }
  func_002b9030(object);
}

#pragma optimization_level 2
// FUN_002f2b40
u32 func_002f2b40(BtlAction* action)
{
  u64 lVar1;

  lVar1 = FUN_0027e390(action->uid,0x3fffffffffffffff);
  return lVar1 != 0;
}

// FUN_002f2b90 NONMATCHING
void func_002f2b90(u64 param_1)

{
  u16 uVar1;
  short sVar2;
  int iVar3;
  u8 *puVar4;
  u8 *puVar5;
  u8 *puVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u64 *puVar10;
  u64 uVar11;
  u8 auStack_90 [136];
  u32 uStack_8;
  u32 uStack_4;
  
  puVar10 = (u64 *)param_1;
  uVar11 = *puVar10;
  sVar2 = FUN_002835e0(1.0f,*(u32 *)(puVar10 + 6),0x17);
  uVar1 = *(u16 *)(DAT_0069a1d2 + (u32)*(u16 *)(iGpffffb6fc + 0xb48) * 4);
  uVar7 = FUN_002b8f90_u32_voice(0);
  uVar8 = FUN_002b8f90_u32_voice(1);
  uVar9 = FUN_002f87e0_u32_voice(5);
  FUN_002b90d0(uVar7,uVar9);
  uVar9 = (u32)FUN_002d1d00_packet_voice((BtlAction*)param_1,2,(const char*)0x69a350);
  iVar3 = (int)uVar9;
  *(u16 *)(iVar3 + 0x48) = 0x1e;
  *(u64 *)(iVar3 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,0);
  uVar9 = (u32)FUN_002a3b40_packet_voice(0,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(iVar3 + 0x58);
  *(u16 *)(puVar4 + 0x48) = 0x10;
  FUN_0027ed20(uVar9,0);
  uVar9 = (u32)FUN_002bb2f0_packet_voice(uVar7,(BtlUnit*)*(u32 *)(puVar10 + 6),sVar2 + 6,0,0x200);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,2);
  uVar9 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit*)*(u32 *)(puVar10 + 6),0x17,0,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u16 *)(puVar5 + 0x48) = 4;
  *(u64 *)(puVar5 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,1);
  uVar9 = (u32)FUN_002b8d60_packet_voice(3,0xfff);
  *(u8 *)uVar9 = 4;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(puVar5 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = (u32)FUN_002bd590_packet_voice((BtlUnit*)*(u32 *)(puVar10 + 6),uVar1);
  puVar6 = (u8 *)uVar9;
  *puVar6 = 4;
  *(u64 *)(puVar6 + 8) = *(u64 *)(puVar5 + 0x58);
  *(u64 *)(puVar6 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,3);
  FUN_0029ea60(uVar1,&uStack_4,&uStack_8);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_0029ec00_u32_voice(uVar1);
  FUN_0029ec80(uVar1,&uStack_4,&uStack_8);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_0029ec50_u32_voice(uVar1);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  FUN_002bb6f0(uVar1,auStack_90);
  uVar9 = (u32)FUN_002bac00_packet_voice(uVar8,auStack_90,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(short *)(puVar5 + 0x48) = sVar2;
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  uVar9 = (u32)FUN_002dd4a0_packet_voice(uVar1,0);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar5 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = (u32)FUN_002baf90_packet_voice((void*)uVar8,(BtlUnit*)*(u32 *)(puVar10 + 6),(BtlUnit*)*(u32 *)(puVar10 + 6),0,0);
  puVar6 = (u8 *)uVar9;
  *puVar6 = 4;
  *(u64 *)(puVar6 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar6[0x10] = 4;
  *(u64 *)(puVar6 + 0x18) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar6 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,2);
  uVar9 = (u32)FUN_002dd5e0_packet_voice(0);
  *(u8 *)uVar9 = 5;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(puVar6 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = (u32)FUN_002baf90_packet_voice((void*)uVar8,(BtlUnit*)*(u32 *)(puVar10 + 6),(BtlUnit*)*(u32 *)(puVar10 + 6),1,0);
  puVar6 = (u8 *)uVar9;
  *puVar6 = 4;
  *(u64 *)(puVar6 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar6[0x10] = 4;
  *(u64 *)(puVar6 + 0x18) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar6 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,2);
  uVar9 = (u32)FUN_002dd5e0_packet_voice(1);
  *(u8 *)uVar9 = 5;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(puVar6 + 0x58);
  FUN_0027ed20(uVar9,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 0xb;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar6 + 0x58);
  *(u64 *)(puVar4 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 0xb;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar6 + 0x58);
  *(u64 *)(puVar4 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 0xb;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar6 + 0x58);
  *(u64 *)(puVar4 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 0xb;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar6 + 0x58);
  *(u64 *)(puVar4 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,0);
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x400000;
  *(u16 *)(iGpffffb6fc + 0x18) = *(u16 *)(iGpffffb6fc + 0x18) | 7;
  FUN_002b9030(uVar8);
  FUN_002b9030(uVar7);
  return;
}

// FUN_002f3190
u32 func_002f3190(BtlAction* action)
{
  u16 uVar1;
  int iVar2;
  u64 uVar4;

  if (FUN_0027e390(action->uid,0x3fffffffffffffff) == 0) {
    *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfff7ffff;
    iVar2 = *(int *)((u8 *)action->unit + 0xa2c);
    uVar1 = *(u16 *)(DAT_0069a1d0 + (u32)*(u16 *)(iGpffffb6fc + 0xb48) * 4);
    FUN_002889c0(action->unit,uVar1);
    *(u16 *)(iVar2 + 2) = uVar1;
    *(u16 *)(iVar2 + 4) = uVar1;
    uVar4 = FUN_002ffdf0(iVar2);
    FUN_002ffd90(iVar2,uVar4);
    uVar4 = FUN_00300100(iVar2);
    FUN_002ffdc0(iVar2,uVar4);
    FUN_00300560(iVar2,0xffffff);
    FUN_0017b220(uVar1);
    FUN_0027ce50();
    FUN_00301540(iVar2,0xd);
    FUN_00301540(iVar2,0xe);
    FUN_00301540(iVar2,0xf);
    FUN_00301540(iVar2,0x10);
    FUN_002831c0(action->unit,6);
    *(u16 *)(iGpffffb6fc + 0xb48) = *(u16 *)(iGpffffb6fc + 0xb48) + 1;
    FUN_001fdd40();
    return 0;
  }
  return 1;
}

// FUN_002f3320
void func_002f3320(BtlAction* action)
{
  BtlUnit* unit;
  void* object;
  BtlPacket* parent;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  gBtl->flags |= 0x80000;
  unit = action->unit;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(6));
  packet = FUN_002dd690_packet_voice(3, (const char*)D_0069A368);
  btlPacketRegister(packet, 1);
  parent = FUN_00284200_packet_voice(1.0f, unit, 0x12, 0, 2);
  parent->preUpdateDelay = 2;
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(1, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(unit, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}

// FUN_002f3520
u32 func_002f3520(BtlAction* action)
{
    BtlPacket* packet;

    if (action != btlActionCurrent())
    {
        if ((action->unit->flags3 & BTLUNIT_FLAG3_ENDURE) != 0)
        {
            return 1;
        }
    }
    else
    {
        action->unit->flags3 &= ~BTLUNIT_FLAG3_ENDURE;
    }

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        FUN_002d7890(action, 0);
        FUN_0029a320(action);
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002f3670
void func_002f3670(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0) {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_PC) {
            switch (unit->charId) {
            case 1:
                datPersonaClearHeroPersonas();
                FUN_00174e20(0xbf);
                FUN_00175130(0xbf);
                btlUnitInitPersona(unit, 0xbf);
                datCalcClearBadStatus(unit->datUnit, 0xffffff);
                break;
            }
        } else if (unit->genus == UNIT_GENUS_EC) {
            switch (unit->charId) {
            case 0x112:
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x40;
                unit->flags3 |= 0x400;
                break;
            }
        }
    }
}

// FUN_002f3760
void func_002f3760(void)
{
    BtlUnit* unit;
    RwV3d position;

    position.y = 0.0f;
    for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
         unit != NULL; unit = unit->next) {
        if (unit->charId == 1) {
            position.x = 0.0f;
            position.z = 500.0f;
            unit->unk_9f0 = 0;
        } else {
            position.x = 0.0f;
            position.z = 0.0f;
        }
        FUN_002d2280(&unit->unk_94, &unit->unk_96, (f32*)&position);
        btlUnitSetPos(unit, &position);
    }

    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        position.x = 0.0f;
        position.z = -500.0f;
        FUN_002d2280(&unit->unk_94, &unit->unk_96, (f32*)&position);
        btlUnitSetPos(unit, &position);
    }
}

/* Removing this loses FUN_002f3840 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f3840
void func_002f3840(void)
{
    BtlUnit* source;
    BtlUnit* target;
    void* object;
    BtlUnit* unit;
    BtlPacket* packet;

    FUN_002dce90();
    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(3));

    source = gBtl->actionList.head->unit;
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x112:
            target = unit;
            break;
        }
    }

    packet = btlFormation002b8d60(3, 0xfff);
    packet->preUpdateDelay = 3;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);

    packet = btlCameraCreateSetStatePacket(NULL, 1);
    packet->preUpdateDelay = 3;
    btlPacketRegister(packet, BTLPACKET_TYPE_0);

    packet = func_002baf90(object, source, target, 0, 0x200);
    btlPacketRegister(packet, BTLPACKET_TYPE_3D);

    packet = func_002bc890((u8*)&gp0xffff9c80, 0xc);
    packet->preUpdateDelay = 0xe5;
    btlPacketRegister(packet, BTLPACKET_TYPE_1);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f39b0
void func_002f39b0(BtlAction* action)
{
    BtlAction* currentAction;
    BtlUnit* unit;
    u16* phase;

    currentAction = btlOrderGetActionPlaying();
    if (currentAction != NULL) {
        if (currentAction->target.specificId == 0x157) {
            func_002e4220((u32)func_002f4410, (u32)func_002f4480,
                          (u32)action);
        } else {
            unit = currentAction->unit;
            if (unit->genus == UNIT_GENUS_EC && unit->charId == 0x112) {
                phase = (u16*)((u8*)gBtl + 0xb48);
                if (*phase == 0) {
                    (*phase)++;
                } else {
                    func_002e4220((u32)func_002f3a80,
                                  (u32)func_002f43a0, (u32)action);
                }
            }
        }
    }
}

// FUN_002f3a80 NONMATCHING
void func_002f3a80(BtlAction* param_1)

{
  u8 *puVar1;
  u8 *puVar2;
  u8 *puVar3;
  u8 *puVar4;
  u8 *puVar5;
  u64 uVar6;
  u32 uVar7;
  int iVar8;
  short sVar9;
  u32 uVar10;
  u32 uVar11;
  int iVar12;
  u64 *puVar13;
  u64 uVar14;
  u16 uVar15;
  u64 uVar16;
  u8 auStack_d0 [128];
  u32 stackData[4];
  int aiStack_28 [4];
  int aiStack_18 [4];
  u32 uStack_8;
  u32 uStack_4;
  
  iVar12 = 2;
  if (*(short *)(iGpffffb6fc + 0xb48) == 2) {
    sVar9 = 0x62;
    uVar15 = 0x11b;
    aiStack_18[0] = 0x1cf;
    aiStack_18[1] = 0x1d7;
    aiStack_18[2] = 0x1d2;
    aiStack_28[2] = 0xffffffff;
    iVar12 = 1;
  }
  else if (*(short *)(iGpffffb6fc + 0xb48) == 1) {
    sVar9 = 0x61;
    uVar15 = 0x11a;
    aiStack_18[0] = 0x1d4;
    aiStack_18[1] = 0x1d3;
    aiStack_18[2] = 0x1d1;
    aiStack_28[2] = 0xffffffff;
    iVar12 = 0;
  }
  else {
    sVar9 = 0x6c;
    uVar15 = 0x11c;
    aiStack_18[0] = 0x1d6;
    aiStack_18[1] = 0x1d0;
    aiStack_18[2] = 0xffffffff;
    aiStack_28[2] = 0x386;
  }
  aiStack_28[1] = 0xffffffff;
  aiStack_28[0] = -1;
  *(short *)(iGpffffb6fc + 0xb48) = *(short *)(iGpffffb6fc + 0xb48) + 1;
  puVar13 = (u64 *)param_1;
  uVar14 = *puVar13;
  *(u16 *)((int)puVar13 + 0x6c) = 2;
  *(short *)((int)puVar13 + 0x6e) = sVar9;
  FUN_002c3770(param_1,0);
  FUN_002d6620(param_1);
  uVar6 = FUN_002b8f90(1);
  uVar7 = FUN_002b8d60(3,0xfff);
  *(u16 *)((int)uVar7 + 0x48) = 0;
  *(u64 *)((int)uVar7 + 0x60) = *puVar13;
  FUN_0027ed20(uVar7,0);
  iVar8 = iVar12 * 0xc;
  uVar7 = (u32)FUN_002a3d70_packet_voice(*(BtlAction**)(iGpffffb6fc + 0x148),
                       voicePartyCameraStarts + iVar12,
                       voicePartyCameraEnds + iVar12,
                       voicePartyCameraTargets + iVar12,
                       voicePartyCameraUps + iVar12,
                       voicePartyCameraDurations[iVar12] / 30.0f);
  *(u16 *)((int)uVar7 + 0x48) = 0;
  *(u64 *)((int)uVar7 + 0x60) = *puVar13;
  FUN_0027ed20(uVar7,0);
  uVar16 = 0;
  uVar11 = 0;
  do {
    if (2 < uVar11) {
      FUN_0029ea60(sVar9,&uStack_4,&uStack_8);
      puVar1 = (u8 *)uVar16;
      *puVar1 = 4;
      iVar12 = (int)uVar7;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar16,1);
      uVar7 = FUN_0029ec00(sVar9);
      FUN_0029ec80(sVar9,&uStack_4,&uStack_8);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      uVar7 = FUN_0029ec50(sVar9);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      FUN_002bb6f0(sVar9,auStack_d0);
      uVar7 = FUN_002bac00(uVar6,auStack_d0,0);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u16 *)(puVar1 + 0x48) = 0;
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      uVar7 = FUN_002dd4a0(sVar9,0);
      puVar2 = (u8 *)uVar7;
      *puVar2 = 4;
      *(u64 *)(puVar2 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar2 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      uVar7 = FUN_002baf90(uVar6,*(u32 *)(puVar13 + 6),*(u32 *)(puVar13 + 6),0,0);
      puVar3 = (u8 *)uVar7;
      *puVar3 = 4;
      *(u64 *)(puVar3 + 8) = *(u64 *)(puVar1 + 0x58);
      puVar3[0x10] = 4;
      *(u64 *)(puVar3 + 0x18) = *(u64 *)(puVar2 + 0x58);
      *(u64 *)(puVar3 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,2);
      uVar16 = FUN_002dd5e0(0);
      puVar4 = (u8 *)uVar16;
      *puVar4 = 5;
      *(u64 *)(puVar4 + 8) = *(u64 *)(puVar3 + 0x58);
      *(u64 *)(puVar4 + 0x60) = uVar14;
      FUN_0027ed20(uVar16,1);
      for (uVar11 = 0; uVar11 < *(u16 *)((int)puVar13 + 0x6a); uVar11 = uVar11 + 1 & 0xffff) {
        iVar12 = *(int *)((int)puVar13 + uVar11 * 4 + 0x38);
        uVar7 = FUN_002bd480(*(u32 *)(iVar12 + 0x30));
        *(u64 *)((int)uVar7 + 0x60) = uVar14;
        FUN_0027ed20(uVar7,1);
        uVar7 = FUN_002baf90(uVar6,*(u32 *)(iVar12 + 0x30),*(u32 *)(iVar12 + 0x30),1,0
                            );
        puVar3 = (u8 *)uVar7;
        *puVar3 = 4;
        *(u64 *)(puVar3 + 8) = *(u64 *)(puVar1 + 0x58);
        puVar3[0x10] = 4;
        *(u64 *)(puVar3 + 0x18) = *(u64 *)(puVar2 + 0x58);
        *(u64 *)(puVar3 + 0x60) = uVar14;
        FUN_0027ed20(uVar7,2);
        uVar16 = FUN_002dd5e0(1);
        puVar4 = (u8 *)uVar16;
        *puVar4 = 5;
        *(u64 *)(puVar4 + 8) = *(u64 *)(puVar3 + 0x58);
        *(u64 *)(puVar4 + 0x60) = uVar14;
        FUN_0027ed20(uVar16,1);
        uVar10 = 0;
        while( true ) {
          if (*(u8 *)(iVar12 + 200) <= uVar10) break;
          uVar16 = FUN_00284200(1.0f,*(u32 *)(iVar12 + 0x30),
                                *(u8 *)(iVar12 + uVar10 * 0x1c + 0xf8),0,0);
          puVar4 = (u8 *)uVar16;
          *puVar4 = 0xb;
          *(u64 *)(puVar4 + 8) = *(u64 *)(puVar3 + 0x58);
          *(u64 *)(puVar4 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,1);
          if (uVar10 == 0) {
            uVar16 = FUN_002bd850(*(u32 *)(iVar12 + 0x30),uVar15);
            puVar5 = (u8 *)uVar16;
            *puVar5 = 0xb;
            *(u64 *)(puVar5 + 8) = *(u64 *)(puVar3 + 0x58);
            *(u64 *)(puVar5 + 0x60) = uVar14;
            FUN_0027ed20(uVar16,3);
          }
          iVar8 = iVar12 + uVar10 * 0x1c + 0xe0;
          uVar16 = FUN_002bdbd0(*(u32 *)(puVar13 + 6),*(u32 *)(iVar12 + 0x30),
                                *(u16 *)((int)puVar13 + 0x6e),*(u16 *)(iVar12 + 0xcc),
                                *(u16 *)(iVar12 + 0xce),uVar10,*(u8 *)(iVar12 + 200),
                                iVar8);
          puVar5 = (u8 *)uVar16;
          *puVar5 = 5;
          *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
          *(u64 *)(puVar5 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,3);
          uVar16 = FUN_002d7e20(param_1,iVar12,iVar8,*(u16 *)(iVar12 + 0xcc),
                                *(u16 *)(iVar12 + 0xce));
          puVar5 = (u8 *)uVar16;
          *puVar5 = 5;
          *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
          *(u64 *)(puVar5 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,1);
          uVar10 = uVar10 + 1 & 0xffff;
        }
        if (sVar9 == 0x61) {
          uVar16 = FUN_00284200(1.0f,*(u32 *)(iVar12 + 0x30),10,0,0);
          puVar4 = (u8 *)uVar16;
          *puVar4 = 5;
          *(u64 *)(puVar4 + 8) = *(u64 *)(puVar3 + 0x58);
          *(u16 *)(puVar4 + 0x48) = 0xa1;
          *(u64 *)(puVar4 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,1);
          FUN_002d5dc0(stackData);
          stackData[3] = 0x100000;
          uVar16 = FUN_002d7e20(param_1,iVar12,stackData,1,1);
          puVar3 = (u8 *)uVar16;
          *puVar3 = 4;
          *(u64 *)(puVar3 + 8) = *(u64 *)(puVar4 + 0x58);
          *(u64 *)(puVar3 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,1);
        }
      }
      puVar1 = (u8 *)uVar16;
      *puVar1 = 0xb;
      iVar12 = (int)uVar7;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar16,1);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 0xb;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 0xb;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,1);
      puVar1 = (u8 *)uVar7;
      *puVar1 = 0xb;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar12 + 0x58);
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,0);
      FUN_002b9030(uVar6);
      return;
    }
    if (aiStack_18[uVar11] == -1) {
      if (aiStack_28[uVar11] != -1) {
        uVar7 = (u32)func_002e30a0(*(u16 *)(iGpffffb6fc + 0xb02),2,0x386,1);
        goto LAB_002f3d0c;
      }
    }
    else {
      uVar7 = FUN_002db740(param_1,0x1f,aiStack_18[uVar11],0,1);
LAB_002f3d0c:
      puVar1 = (u8 *)uVar7;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = uVar16;
      *(u16 *)(puVar1 + 0x48) = 0;
      *(u64 *)(puVar1 + 0x60) = uVar14;
      FUN_0027ed20(uVar7,0);
      uVar16 = *(u64 *)(puVar1 + 0x58);
    }
    uVar11 = uVar11 + 1 & 0xffff;
  } while( true );
}

// FUN_002f43a0
u32 func_002f43a0(BtlAction* action)
{
    BtlPacket* packet;

    packet = btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX);
    if (packet == NULL)
    {
        gBtl->flags &= ~0x80000;
        return 0;
    }

    return 1;
}

/* Removing this loses FUN_002f4410 (MATCH nd0 -> MISMATCH nd46) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f4410
void func_002f4410(BtlAction* unused)
{
    u8* node;
    u16 wantedId;
    BtlAction* action;

    wantedId = 0x112;
    node = *(u8**)(DAT_007ce3ec + 0x158);
    while (node != NULL)
    {
        if (*(u16*)(node + 0xa4) == wantedId)
        {
            break;
        }
        node = *(u8**)(node + 0xa34);
    }

    action = FUN_0029a1d0();
    FUN_002d7890(action, 0);
}
#pragma opt_loop_invariants off

// FUN_002f4480
u32 func_002f4480(BtlAction* action)
{
    return 0;
}

// FUN_002f4490
void func_002f4490(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0)
    {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC)
        {
            switch (unit->charId)
            {
            case 0x126:
                action->unk_1a |= 0x10;
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x40;
                unit->flags3 |= 0x80;
                btlOrderAddAction(action);
                break;
            }

            switch (unit->charId)
            {
            case 0x126:
                btlUnitInitPersona(unit, 7);
                break;
            }
        }
    }
}

// FUN_002f4540
void func_002f4540(void)
{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];

  puVar6 = (u32*)DAT_0069a470;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&DAT_007cc9e0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0xc3020000;
      uStack_10.raw[2] = 0x43480000;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(DAT_007ce3ec + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x126:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3960000;
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

/* Removing this loses FUN_002f46d0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f46d0
void func_002f46d0(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0x126:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f4890
void func_002f4890(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0)
    {
        unit = action->unit;
        if (unit->genus != UNIT_GENUS_EC)
        {
            action->unk_18 |= 0x40;
        }
        else
        {
            switch (unit->charId)
            {
            case 0xe9:
                action->unk_1a |= 0x10;
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x40;
                unit->flags3 |= 0x80;
            }
            switch (unit->charId)
            {
            case 0xe9:
                FUN_00288f80(unit, 0xd3);
            }
        }
    }
}

// FUN_002f4950
void func_002f4950(void)
{
    RwV3d position;
    BtlUnit* unit;

    position.y = 0.0f;
    for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
         unit != NULL; unit = unit->next)
    {
        if (unit->charId == 1)
        {
            position.x = 0.0f;
            position.z = 300.0f;
            unit->unk_9f0 = 0;
        }
        FUN_002d2280(&unit->unk_94, &unit->unk_96, (f32*)&position);
        btlUnitSetPos(unit, &position);
    }
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next)
    {
        switch (unit->charId)
        {
        case 0xe9:
            position.x = 0.0f;
            position.z = -300.0f;
        }
        FUN_002d2280(&unit->unk_94, &unit->unk_96, (f32*)&position);
        btlUnitSetPos(unit, &position);
    }
}

/* Removing this loses FUN_002f4a40 (MATCH nd0 -> MISMATCH nd12) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f4a40
void func_002f4a40(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0xe9:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off
// FUN_002f4c00
void func_002f4c00(BtlAction* action)
{
    BtlUnit* unit;

    if (((action->unk_1a & 1) != 0) &&
        (unit = action->unit, unit->genus == UNIT_GENUS_EC))
    {
        switch (unit->charId)
        {
        case 0xea:
            action->unk_1a |= 0x10;
            unit->flags3 |= 0x100;
            unit->flags3 |= 0x40;
            unit->flags3 |= 0x80;
            *(u32*)((u8*)gBtl + 0xb54) = 1;
            *(u32*)((u8*)gBtl + 0xb58) = 0xe1;
            FUN_00521408((u8*)gBtl + 0xb5c, 0, 0x16);
            *(u16*)((u8*)gBtl + 0xb5e) = 1;
        }
        switch (unit->charId)
        {
        case 0xea:
            FUN_00288f80(unit, 6);
        }
    }
}

// FUN_002f4ce0
void func_002f4ce0(void)
{
    VoiceXZ positions[3] = {{-350.0f, 50.0f}, {130.0f, 200.0f},
                            {350.0f, 50.0f}};
    RwV3d position;
    VoiceSlots slots;
    BtlUnit* primaryUnit;
    BtlUnit* secondaryUnit;
    s16 index;
    VoiceXZ* selected;

    slots = *(VoiceSlots*)DAT_007cc9e8;
    index = 0;
    position.y = 0.0f;
    for (primaryUnit = gBtl->unitLists[UNIT_GENUS_PC].head;
         primaryUnit != NULL; primaryUnit = primaryUnit->next)
    {
        if (primaryUnit->charId == 1)
        {
            position.x = -130.0f;
            position.z = 200.0f;
            primaryUnit->unk_9f0 = 1;
        }
        else
        {
            selected = &positions[index];
            position.x = selected->x;
            position.z = selected->z;
            primaryUnit->unk_9f0 = slots.values[index];
            index++;
        }
        FUN_002d2280(&primaryUnit->unk_94, &primaryUnit->unk_96,
                     (f32*)&position);
        btlUnitSetPos(primaryUnit, &position);
    }
    for (secondaryUnit = gBtl->unitLists[UNIT_GENUS_EC].head;
         secondaryUnit != NULL; secondaryUnit = secondaryUnit->next)
    {
        switch (secondaryUnit->charId)
        {
        case 0xea:
            position.x = 0.0f;
            position.z = -300.0f;
        }
        FUN_002d2280(&secondaryUnit->unk_94, &secondaryUnit->unk_96,
                     (f32*)&position);
        btlUnitSetPos(secondaryUnit, &position);
    }
}

/* Removing this loses FUN_002f4e70 (MATCH nd0 -> MISMATCH nd12) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002f4e70
void func_002f4e70(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(2));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0xea:
      target = unit;
      break;
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f5030 NONMATCHING
void func_002f5030(int param_1)

{
  u16 uVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u16 uVar7;
  int aiStack_20 [4];
  int aiStack_10 [4];
  
  uVar7 = 0xffff;
  uVar4 = 0;
  for (iVar2 = *(int *)(DAT_007ce3ec + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    uVar1 = *(u16 *)(iVar2 + 0xa4);
    if ((*(u32 *)(DAT_007ce3ec + 0xb54) != (u32)uVar1) && (uVar1 != 9)) {
      aiStack_10[uVar4] = iVar2;
      uVar1 = *(u16 *)(DAT_007ce3ec + (u32)uVar1 * 2 + 0xb5c);
      if (uVar1 < uVar7) {
        uVar7 = uVar1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
  }
  if (uVar4 != 0) {
    uVar6 = 0;
    for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1 & 0xffff) {
      if (*(u16 *)(DAT_007ce3ec + (u32)*(u16 *)(aiStack_10[uVar5] + 0xa4) * 2 + 0xb5c) <=
          uVar7) {
        aiStack_20[uVar6] = aiStack_10[uVar5];
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
    if (uVar6 != 0) {
      iVar2 = FUN_002ffbc0();
      iVar2 = aiStack_20[iVar2];
      if (*(short *)((u32)*(u16 *)(iVar2 + 0xa4) * 2 + DAT_007ce3ec + 0xb5c) == 0) {
        *(u16 *)(param_1 + 0x18) = *(u16 *)(param_1 + 0x18) & 0xffbf;
        FUN_0017b220(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
      }
      *(u32 *)(DAT_007ce3ec + 0xb54) = (u32)*(u16 *)(iVar2 + 0xa4);
      iVar3 = (u32)*(u16 *)(iVar2 + 0xa4) * 2 + DAT_007ce3ec;
      *(short *)(iVar3 + 0xb5c) = *(short *)(iVar3 + 0xb5c) + 1;
      switch(*(u16 *)(iVar2 + 0xa4)) {
      case 1:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe1;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 0x129;
        break;
      case 2:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe0;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 0x12a;
        break;
      case 4:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe2;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 299;
        break;
      case 5:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe3;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 300;
        break;
      case 7:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe4;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 0x12d;
        break;
      case 8:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe5;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 0x12e;
        break;
      case 9:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe7;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) =
             *(u16 *)(*(int *)(param_1 + 0x30) + 0xa4);
        break;
      case 10:
        *(u32 *)(DAT_007ce3ec + 0xb58) = 0xe6;
        *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4) = 0x12f;
      }
    }
  }
  return;
}

// FUN_002f5320
u32 func_002f5320(void)

{
  return *(u32 *)(DAT_007ce3ec + 0xb58);
}

// FUN_002f5330
void func_002f5330(int param_1)

{
  typedef struct VoiceParam {
    u8 padding[0x1a];
    u16 flags;
  } VoiceParam;
  int iVar1;
  u16 flags;
  u16 kind;
  u32 uVar2;
  VoiceParam *work;
  
  work = (VoiceParam *)param_1;
  flags = work->flags;
  if (((flags & 1) != 0) &&
     (iVar1 = *(int *)(param_1 + 0x30), *(u8 *)(iVar1 + 0xa2) == '\x01')) {
    kind = *(u16 *)(iVar1 + 0xa4);
    switch(kind) {
    case 0xeb:
    case 0xec:
    case 0xed:
    case 0xee:
    case 0xef:
    case 0xf0:
      work->flags = flags | 0x10;
      *(u32 *)(iVar1 + 0x9c) |= 0x100;
      *(u32 *)(iVar1 + 0x9c) |= 0x40;
      *(u32 *)(iVar1 + 0x9c) |= 0x80;
      **(u16 **)(iVar1 + 0xa2c) = **(u16 **)(iVar1 + 0xa2c) | 0x40;
    }
    kind = *(u16 *)(iVar1 + 0xa4);
    switch(kind) {
    case 0xeb:
      FUN_00288f80(iVar1,0xcb);
      break;
    case 0xed:
      FUN_00288f80(iVar1,0xc7);
      break;
    case 0xef:
      FUN_00288f80(iVar1,0xc1);
      break;
    case 0xec:
      FUN_00288f80(iVar1,0xcd);
      break;
    case 0xee:
      FUN_00288f80(iVar1,0xcf);
      break;
    case 0xf0:
      FUN_00288f80(iVar1,0xc5);
    }
  }
  return;
}

// FUN_002f5490
void func_002f5490(void)
{
  BtlUnit* unit;
  RwV3d position;

  position.y = 0.0f;
  for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
       unit != NULL; unit = unit->next) {
    if (*(u16 *)(*(u8 **)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b2) {
      switch (unit->charId) {
      case 1:
        position.x = 150.0f;
        position.z = 300.0f;
        unit->unk_9f0 = 1;
        break;
      case 9:
        position.x = -150.0f;
        position.z = 300.0f;
        unit->unk_9f0 = 0;
        break;
      }
    }
    else {
      switch (unit->charId) {
      case 1:
        position.x = -150.0f;
        position.z = 300.0f;
        unit->unk_9f0 = 0;
        break;
      case 9:
        position.x = 150.0f;
        position.z = 300.0f;
        unit->unk_9f0 = 1;
        break;
      }
    }
    FUN_002d2280(&unit->unk_94, &unit->unk_96, &position);
    btlUnitSetPos(unit, &position);
  }
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0xeb:
    case 0xee:
    case 0xef:
      position.x = -150.0f;
      position.z = -300.0f;
      break;
    case 0xec:
    case 0xed:
    case 0xf0:
      position.x = 150.0f;
      position.z = -300.0f;
      break;
    }
    FUN_002d2280(&unit->unk_94, &unit->unk_96, &position);
    btlUnitSetPos(unit, &position);
  }
}

// FUN_002f5660
void func_002f5660(BtlAction* action)
{
  BtlUnit* unit;
  void* object;
  BtlPacket* parent;
  BtlPacket* packet;
  u32 state;

  gBtl->flags &= ~0x02000000;
  gBtl->flags |= 0x80000;
  unit = action->unit;
  switch (unit->charId) {
  case 0xeb:
  case 0xed:
  case 0xef:
    state = 2;
    break;
  case 0xec:
  case 0xee:
  case 0xf0:
    state = 3;
    break;
  }
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(state));
  parent = FUN_00284200_packet_voice(1.0f, unit, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(1, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(unit, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}

// FUN_002f5870
u32 func_002f5870(BtlAction* action)
{
    BtlPacket* packet;

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        FUN_002d7890(action, 0);
        FUN_0029a320(action);
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002f5980
void func_002f5980(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0) {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC) {
            switch (unit->charId) {
            case 0xf1:
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x40;
                unit->flags3 |= 0x400;
                unit->flags3 |= 0x2000;
                break;
            case 0xf2:
                unit->datUnit->flags |= 0x40;
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x40;
                unit->flags3 &= ~8;
                action->unk_1a &= ~8;
                unit->flags3 |= 0x400;
                unit->flags3 |= 0x2000;
                FUN_0029a320(action);
                *(u32 *)(DAT_007ce3ec + 0xb50) = 0;
                break;
            }
        }
    }
    return;
}

// FUN_002f5a70
void func_002f5a70(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];
  
  puVar6 = (u32*)DAT_0069a550;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&DAT_007cc9f0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0x43160000;
      uStack_10.raw[2] = 0x43fa0000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(DAT_007ce3ec + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    uStack_10.raw[0] = 0;
    uStack_10.raw[2] = 0xc3fa0000;
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

void func_002f6840(BtlAction* action);
u32 func_002f6ab0(BtlAction* action);

// FUN_002f5bf0 NONMATCHING
void func_002f5bf0(BtlAction* param_1,BtlAction* param_2,BtlTargetResult* param_3)

{
  u32 bVar1;
  int iVar2;
  s32 hpDelta;
  BtlUnit* sourceUnit;
  u16 *puVar3;
  s32 lVar4;
  BtlAction* unaff_s0;
  
  bVar1 = false;
  sourceUnit = param_1->unit;
  if (sourceUnit->genus == 1) {
    if (sourceUnit->charId == 0xf1) {
      if ((*(u16 *)((int)param_3 + 0x1a) & 0x100) != 0) {
        unaff_s0 = param_1;
        bVar1 = true;
      }
      if ((*(u16 *)((int)param_3 + 0x1a) & 0x200) != 0) {
        *(u32 *)(DAT_007ce3ec + 0xb48) = 1;
        for (iVar2 = *(int *)(DAT_007ce3ec + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
          if (*(u16 *)(iVar2 + 0xa4) == 0xf2) {
            *(u32 *)(DAT_007ce3ec + 0xb50) = 1;
            *(u16 *)(DAT_007ce3ec + 0xb54) = 0;
            *(u16 *)(DAT_007ce3ec + 0xb56) = 10;
            *(u16 *)(DAT_007ce3ec + 0xb58) = 0;
          }
        }
        puVar3 = (u16*)param_1->unit->datUnit;
        *puVar3 = *puVar3 | 0x40;
      }
      goto LAB_002f5d34;
    }
  }
  sourceUnit = param_2->unit;
  if (sourceUnit->genus == 1) {
    if (sourceUnit->charId == 0xf1) {
      hpDelta = param_3->hpDelta;
      if (hpDelta < 0) {
        if (*(int *)(DAT_007ce3ec + 0xb48) == 1) {
          if (-hpDelta < *(int *)(DAT_007ce3ec + 0xb4c)) {
            *(int *)(DAT_007ce3ec + 0xb4c) = *(int *)(DAT_007ce3ec + 0xb4c) + hpDelta;
          }
          else {
            *(int *)(DAT_007ce3ec + 0xb4c) = 0;
            unaff_s0 = param_2;
            bVar1 = true;
          }
        }
      }
    }
  }
LAB_002f5d34:
  if ((bVar1) && (lVar4 = FUN_002e4250(), lVar4 == 0)) {
    FUN_002e4220(func_002f6840,func_002f6ab0,unaff_s0);
  }
  return;
}

// FUN_002f5d80 NONMATCHING
void func_002f5d80(u32 param_1)

{
  /* Caller-specific return widths: this path consumes the narrow integer results. */
  extern u32 FUN_0027f930();
  extern s32 FUN_00287580();
  u32 bVar1;
  int iVar2;
  s32 lVar3;
  int iVar4;
  float fVar5;
  u32 uVar6;
  u32 cVar7;
  u32 uStack_4;
  
  iVar4 = (int)param_1;
  if (((*(char *)(iVar4 + 0xa2) == '\x01') && (*(short *)(iVar4 + 0xa4) == 0xf1)) &&
     ((*(u32 *)(iVar4 + 0x98) & 2) != 0)) {
    for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
      if (*(short *)(iVar4 + 0xa4) == 0xf2) {
        bVar1 = *(short *)(DAT_007ce3ec + 0xb54) == 0;
        if (!bVar1) {
          *(short *)(DAT_007ce3ec + 0xb54) = *(short *)(DAT_007ce3ec + 0xb54) + -1;
        }
        uStack_4 = 0xffffffff;
        if (*(int *)(DAT_007ce3ec + 0xb50) == 0) {
          if (bVar1) {
            if (*(u16 *)(DAT_007ce3ec + 0xb58) >= *(u16 *)(DAT_007ce3ec + 0xb56)) {
              bVar1 = false;
            }
            else {
              fVar5 = ((float)*(u16 *)(DAT_007ce3ec + 0xb58) * 255.0f) /
                      (float)*(u16 *)(DAT_007ce3ec + 0xb56);
              if (fVar5 < 2.1474836e+09f) {
                cVar7 = (char)(int)fVar5;
              }
              else {
                cVar7 = (char)(int)(fVar5 - 2.1474836e+09f);
              }
              uStack_4 = CONCAT13(-1 - cVar7,0xffffff);
              *(short *)(DAT_007ce3ec + 0xb58) = *(short *)(DAT_007ce3ec + 0xb58) + 1;
              bVar1 = true;
            }
          }
          else {
            bVar1 = true;
          }
        }
        else if (bVar1) {
          if (*(u16 *)(DAT_007ce3ec + 0xb58) < *(u16 *)(DAT_007ce3ec + 0xb56)) {
            fVar5 = ((float)*(u16 *)(DAT_007ce3ec + 0xb58) * 255.0f) /
                    (float)*(u16 *)(DAT_007ce3ec + 0xb56);
            if (fVar5 < 2.1474836e+09f) {
              uVar6 = (u8)(int)fVar5;
            }
            else {
              uVar6 = (u8)(int)(fVar5 - 2.1474836e+09f);
            }
            uStack_4 = CONCAT13(uVar6,0xffffff);
            *(short *)(DAT_007ce3ec + 0xb58) = *(short *)(DAT_007ce3ec + 0xb58) + 1;
          }
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        iVar2 = FUN_0027f930(param_1);
        if (((bVar1) && (lVar3 = FUN_00287580(param_1), lVar3 != 0)) &&
           (*(char *)(iVar2 + 3) != '\0')) {
          FUN_0027f730(iVar4,uStack_4);
          FUN_00287490(iVar4);
          return;
        }
        FUN_00287510(iVar4);
        return;
      }
    }
  }
}

// FUN_002f6120 NONMATCHING
void func_002f6120(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* parent;
  BtlUnit* unit;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(4));
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 0xf1:
      target = unit;
      break;
    }
  }
  packet = FUN_002dd690_packet_voice(3, DAT_0069a5b8);
  btlPacketRegister(packet, 1);
  parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  btlPacketRegister(packet, 2);
  packet = func_002bc890(&DAT_007cc970, 0x18);
  packet->preUpdateDelay = 200;
  btlPacketRegister(packet, 1);
  func_002b9030(object);
}

// FUN_002f6330
u32 func_002f6330(void *param_1)
{
  struct {
    u64 firstPositionXY;
    f32 firstPositionZ;
    u8 firstTransform[16];
    RwV3d secondPosition;
    u8 secondTransform[16];
  } work;
  u8 *action = (u8 *)param_1;
  int unit = *(int *)(*(int *)(action + 0xe0) + 0x30);

  if (*(u8 *)(unit + 0xa2) != 1) {
    return 0;
  }
  if (*(u16 *)(unit + 0xa4) != 0xf1) {
    return 0;
  }

  if ((FUN_00357fd0(0) & 1) != 0) {
    FUN_002a4690(work.firstTransform, DAT_0069a5c8,
                 DAT_0069a5c8 + 0x20, D_00697880);
    {
      u64 xy = *(volatile /* Removing this function's qualifier batch loses func_002f6330 (MATCH nd0 -> MISMATCH nd10, size 480 -> 480) - measured W170. */ u64 *)DAT_0069a5c8;
      f32 z = *(volatile /* Removing this function's qualifier batch loses func_002f6330 (MATCH nd0 -> MISMATCH nd10, size 480 -> 480) - measured W170. */ f32 *)(DAT_0069a5c8 + 8);
      work.firstPositionXY = xy;
      work.firstPositionZ = z;
    }
    FUN_002a4690(work.secondTransform, DAT_0069a5d8,
                 DAT_0069a5d8 + 0x20, D_00697880);
    work.secondPosition = *(RwV3d *)DAT_0069a5d8;
  } else {
    FUN_002a4690(work.secondTransform, DAT_0069a5c8,
                 DAT_0069a5c8 + 0x20, D_00697880);
    work.secondPosition = *(RwV3d *)DAT_0069a5c8;
    FUN_002a4690(work.firstTransform, DAT_0069a5d8,
                 DAT_0069a5d8 + 0x20, D_00697880);
    {
      u64 xy = *(volatile /* Removing this function's qualifier batch loses func_002f6330 (MATCH nd0 -> MISMATCH nd10, size 480 -> 480) - measured W170. */ u64 *)DAT_0069a5d8;
      f32 z = *(volatile /* Removing this function's qualifier batch loses func_002f6330 (MATCH nd0 -> MISMATCH nd10, size 480 -> 480) - measured W170. */ f32 *)(DAT_0069a5d8 + 8);
      work.firstPositionXY = xy;
      work.firstPositionZ = z;
    }
  }

  FUN_002a2290(action, (f32 *)&work.firstPositionXY,
                (f32 *)&work.secondPosition, 1);
  FUN_002a3110(action, 5.0f);
  FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(action + 0xe0),
                0, 0, 8);
  *(u32 *)(DAT_007ce3ec + 0xb80) = 1;
  return 1;
}

// FUN_002f6510
u32 func_002f6510(void *param_1)
{
  struct {
    u64 firstPositionXY;
    f32 firstPositionZ;
    u8 firstTransform[16];
    RwV3d secondPosition;
    u8 secondTransform[16];
  } work;
  u8 *action = (u8 *)param_1;
  int encounter = *(int *)(DAT_007ce3ec + 0xb5c);
  float distance;
  u32 result;
  u32 special;

  if (encounter == 0x126) goto encounter126;
  if (encounter == 0x128) goto encounterGroup;
  if (encounter == 0x127) goto encounterGroup;
  switch (encounter) {
  case 0x125:
    goto encounterGroup;
  default:
    goto encounterOther;
  }

encounterGroup:
  FUN_002a4690(work.firstTransform, DAT_0069a608,
               DAT_0069a628, D_00697880);
  {
    u64 xy = *(volatile /* Removing this function's qualifier batch loses func_002f6510 (MATCH nd0 -> MISMATCH nd10, size 816 -> 816) - measured W170. */ u64 *)DAT_0069a608;
    f32 z = *(volatile /* Removing this function's qualifier batch loses func_002f6510 (MATCH nd0 -> MISMATCH nd10, size 816 -> 816) - measured W170. */ f32 *)(DAT_0069a608 + 8);
    work.firstPositionXY = xy;
    work.firstPositionZ = z;
  }
  FUN_002a4690(work.secondTransform, DAT_0069a618,
               DAT_0069a638, D_00697880);
  work.secondPosition = *(RwV3d *)DAT_0069a618;
  distance = 2.0f;
  special = 1;
  result = special;
  goto apply;

encounter126:
  FUN_002a4690(work.firstTransform, DAT_0069a648,
               DAT_0069a668, D_00697880);
  {
    u64 xy = *(volatile /* Removing this function's qualifier batch loses func_002f6510 (MATCH nd0 -> MISMATCH nd10, size 816 -> 816) - measured W170. */ u64 *)DAT_0069a648;
    f32 z = *(volatile /* Removing this function's qualifier batch loses func_002f6510 (MATCH nd0 -> MISMATCH nd10, size 816 -> 816) - measured W170. */ f32 *)(DAT_0069a648 + 8);
    work.firstPositionXY = xy;
    work.firstPositionZ = z;
  }
  FUN_002a4690(work.secondTransform, DAT_0069a658,
               DAT_0069a678, D_00697880);
  work.secondPosition = *(RwV3d *)DAT_0069a658;
  distance = 2.0f;
  special = 1;
  result = special;
  goto apply;

encounterOther:
  {
    u16 index;
    int offset;
    u8 *position;
    if (FUN_002d6370(*(s16 *)(*(int *)(action + 0xe0) + 0x6e)) == 1 &&
        func_002f6c20() == 0) {
      index = 0;
    } else {
      index = 1;
    }
    offset = index * 0xc;
    position = DAT_0069a690 + offset;
    FUN_002a4690(work.firstTransform, position,
                 DAT_0069a6d0 + offset, D_00697880);
    *(RwV3d *)&work.firstPositionXY = *(RwV3d *)position;
    position = DAT_0069a6b0 + offset;
    FUN_002a4690(work.secondTransform, position,
                 DAT_0069a6f0 + offset, D_00697880);
    work.secondPosition = *(RwV3d *)position;
  }
  distance = 3.0f;
  special = 0;
  result = 1;

apply:
  if (result) {
    FUN_002a2290((void *)(DAT_007ce3ec + 0x20),
                 (f32 *)&work.firstPositionXY, (f32 *)&work.secondPosition, 1);
    FUN_002a3110((void *)(DAT_007ce3ec + 0x20), distance);
    if (special) {
      FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(action + 0xe0),
                   0, 0, 0x40);
    } else {
      FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(action + 0xe0),
                   0, 0, 1);
    }
  }
  *(u32 *)(DAT_007ce3ec + 0xb5c) = 0xffffffff;
  return result;
}

#pragma opt_loop_invariants on
// FUN_002f6840
void func_002f6840(BtlAction* action)
{
  BtlUnit* unit;
  BtlUnit* iter;
  void* object;
  BtlPacket* packet;
  void* stream;
  s32 mode;
  s32 result;

  gBtl->flags &= ~0x02000000;
  gBtl->flags |= 0x80000;
  unit = action->unit;
  if (*(s32*)(DAT_007ce3ec + 0xb4c) > 0) {
    mode = 2;
  } else {
    mode = 3;
  }
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(mode));
  packet = FUN_002b8d60_packet_voice(1, 0xfff);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 1, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  if (mode == 3) {
    for (iter = gBtl->unitLists[UNIT_GENUS_EC].head;
         iter != NULL; iter = iter->next) {
      if (iter->charId == 0xf2) {
        *(u32*)(DAT_007ce3ec + 0xb50) = 0;
        *(u16*)(DAT_007ce3ec + 0xb54) = 0x1e;
        *(u16*)(DAT_007ce3ec + 0xb56) = 4;
        *(u16*)(DAT_007ce3ec + 0xb58) = 0;
      }
    }
    stream = FUN_002f8810_ptr_voice();
    packet = FUN_002dd760_packet_voice(3, stream, 4);
    packet->preUpdateDelay = 0x1e;
    btlPacketRegister(packet, 1);
    result = FUN_003951d0(0x15ff);
    if (result == 0) {
      FUN_00395170(0x15ff);
      packet = FUN_002db890_packet_voice();
      packet->preUpdateDelay = 0;
      btlPacketRegister(packet, 1);
      packet = FUN_002db800_packet_voice(0x20, 0x1de);
      packet->preUpdateDelay = 0;
      btlPacketRegister(packet, 1);
    }
  }
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002f6ab0
u32 func_002f6ab0(BtlAction* action)
{
    BtlPacket* packet;
    u32 result;

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        *(u32*)(DAT_007ce3ec + 0xb48) = 0;
        action->unit->datUnit->flags &= ~0x40;
        *(u32*)(DAT_007ce3ec + 0xc) &= ~0x80000;
        *(u32*)(DAT_007ce3ec + 0xc) |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        result = 0;
    }
    else
    {
        result = 1;
    }
    return result;
}

// FUN_002f6bc0
u32 func_002f6bc0(void)
{
    *(u32*)(DAT_007ce3ec + 0xb50) = 0;
    *(u16*)(DAT_007ce3ec + 0xb54) = 0x28;
    *(u16*)(DAT_007ce3ec + 0xb56) = 0;
    *(u16*)(DAT_007ce3ec + 0xb58) = 0;
    return 1;
}

// FUN_002f6bf0
void func_002f6bf0(u32 param_1)

{
  if (*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
    *(u32 *)(DAT_007ce3ec + 0xb48) = 0;
    *(u32 *)(DAT_007ce3ec + 0xb4c) = param_1;
  }
  return;
}

// FUN_002f6c20
u32 func_002f6c20(void)

{
  u32 uVar1;
  
  if (*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
    uVar1 = *(u32 *)(DAT_007ce3ec + 0xb48);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_002f6c50
s32 func_002f6c50(u16 charId)
{
    s32 animation;

    switch (charId)
    {
    case 0x100: animation = 0; break;
    case 0x101: animation = 1; break;
    case 0x102: animation = 2; break;
    case 0x103: animation = 3; break;
    case 0x104: animation = 4; break;
    case 0x105: animation = 5; break;
    case 0x106: animation = 6; break;
    case 0x107: animation = 8; break;
    case 0x108: animation = 0xe; break;
    case 0x109: animation = 9; break;
    case 0x10a: animation = 0xa; break;
    case 0x10b: animation = 0xb; break;
    case 0x10c: animation = 0xc; break;
    case 0x10d: animation = 0xd; break;
    case 0x10f: animation = 0xf; break;
    case 0x110: animation = 0x10; break;
    case 0x112: animation = 0x12; break;
    case 0x115: animation = 7; break;
    case 0x111:
    case 0x11a:
    case 0x11b:
    case 0x11c:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x128:
        animation = 0x11;
        break;
    case 0x126: animation = 0x13; break;
    case 0x116:
    case 0x117:
    case 0x118:
        animation = 0x14;
        break;
    case 0x119:
    case 0x127:
        animation = 0x15;
        break;
    case 0xe9: animation = 0x16; break;
    case 0xea: animation = 0x17; break;
    case 0xeb: animation = 0x18; break;
    case 0xec: animation = 0x19; break;
    case 0xed: animation = 0x1a; break;
    case 0xee: animation = 0x1b; break;
    case 0xef: animation = 0x1c; break;
    case 0xf0: animation = 0x1d; break;
    case 0xf1: animation = 0x1e; break;
    default: animation = -1; break;
    }
    return animation;
}

// FUN_002f6e00 MATCHING
void func_002f6e00(void)

{
  u16 sVar1;
  u32 uVar2;
  u8 auStack_40 [64];
  
  FUN_00521408(DAT_007ce3ec + 0xb14,0,0x74);
  *(u16 *)(DAT_007ce3ec + 0xb84) = 0;
  sVar1 = *(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);
  switch (sVar1) {
  case 0x1c8: goto L_1c8;
  case 0x1a0: goto L_1a0;
  case 0x1a1: goto L_1a1;
  case 0x1a2: goto L_1a2;
  case 0x1a3: goto L_1a3;
  case 0x1a4: goto L_1a4;
  case 0x1a5: goto L_1a5;
  case 0x1a6: goto L_1a6;
  case 0x1a7: goto L_1a7;
  case 0x1a8: goto L_1a8;
  case 0x1a9: goto L_1a9;
  case 0x1aa: goto L_1aa;
  case 0x1ab: goto L_1ab;
  case 0x1ac: goto L_1ac;
  case 0x1ad: goto L_1ad;
  case 0x1ae: goto L_1ae;
  case 0x1af: goto L_1af;
  case 0x1b0: goto L_1b0;
  case 0x1b1: goto L_1b1;
  case 0x1b2: goto L_1b2;
  case 0x1b3: goto L_1b3;
  case 0x1b4: goto L_1b4;
  default: goto L_done;
  }
L_1c8:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x40;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc;
    *(u16 *)(DAT_007ce3ec + 0xb84) = 1;
  goto L_done;
L_1a0:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x414;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a1:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x828;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a2:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0xc3c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a3:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1050;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a4:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1464;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a5:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1878;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a6:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1c8c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a7:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x20a0;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a8:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x24b4;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1a9:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x28c8;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1aa:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x2cdc;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1ab:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x30f0;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1ac:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x3504;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1ad:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x20;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffffbff;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x3918;
    *(u16 *)(DAT_007ce3ec + 0xb84) = 2;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1ae:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x3d2c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1af:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4140;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1b0:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4554;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1b1:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4968;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1b2:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4d7c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1b3:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x5190;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_1b4:
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffffbff;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x55a4;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  goto L_done;
L_done:
  FUN_00523ac8(auStack_40,DAT_006a0000 - 0x58f0,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
  uVar2 = FUN_0035c090(DAT_007ce4d0,auStack_40);
  *(u32 *)(DAT_007ce3ec + 0xb1c) = uVar2;
  FUN_00523ac8(auStack_40,DAT_006a0000 - 0x58d0,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
  uVar2 = FUN_0035c090(DAT_007ce4d0,auStack_40);
  *(u32 *)(DAT_007ce3ec + 0xb20) = uVar2;
  FUN_00523ac8(auStack_40,DAT_006a0000 - 0x58b0,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
  uVar2 = FUN_0035c090(DAT_007ce4d0,auStack_40);
  *(u32 *)(DAT_007ce3ec + 0xb24) = uVar2;
  *(u32 *)(DAT_007ce3ec + 0xb28) = 0;
  return;
}

/* 2E battle voice/runtime slice recovered from next_2e00_2eff_dump.c. */

#include "Battle/btlVoice.h"
#include "Utils.h"

typedef u8 undefined1; typedef u16 undefined2; typedef u32 undefined4; typedef u64 undefined8;
typedef u8 undefined; typedef u32 uint3;
typedef u64 (*code)();
#define CONCAT44(a, b) ((((u64)(u32)(a)) << 32) | (u32)(b))
typedef struct {
  f32 x;
  f32 y;
  f32 z;
} VoiceVector;

extern s16 DAT_00697c80;
extern f32 DAT_00697c84;
extern f32 DAT_00697c88;
extern f32 DAT_00697c8c;
extern f32 DAT_00697c90;
extern f32 DAT_00697c9c;
extern f32 DAT_00697ca0;
extern f32 DAT_00697ca4;
extern f32 DAT_00697ca8;
#pragma alias voiceCameraPathsPlayer DAT_00697cc0
#pragma alias voiceCameraPathType2 DAT_00698460
#pragma alias voiceCameraPathType3_1 DAT_00698560
#pragma alias voiceCameraPathType3_2 DAT_00698654
#pragma alias voiceCameraPathType3_3 DAT_00698748
#pragma alias voiceCameraPathType3_2Special DAT_00698e40
#pragma alias voiceCameraPathType4 DAT_00698840
#pragma alias voiceCameraPathType4Special DAT_00698f40
#pragma alias voiceCameraPathType5 DAT_00698940
#pragma alias voiceCameraPathType7 DAT_00698a40
#pragma alias voiceCameraPathType7Special DAT_00699040
#pragma alias voiceCameraPathType8 DAT_00698b40
#pragma alias voiceCameraPathType8Special DAT_00699140
#pragma alias voiceCameraPathType9 DAT_00698c40
extern u8 voiceCameraPathsPlayer[];
extern u8 voiceCameraPathType2[];
extern u8 voiceCameraPathType3_1[];
extern u8 voiceCameraPathType3_2[];
extern u8 voiceCameraPathType3_3[];
extern u8 voiceCameraPathType3_2Special[];
extern u8 voiceCameraPathType4[];
extern u8 voiceCameraPathType4Special[];
extern u8 voiceCameraPathType5[];
extern u8 voiceCameraPathType7[];
extern u8 voiceCameraPathType7Special[];
extern u8 voiceCameraPathType8[];
extern u8 voiceCameraPathType8Special[];
extern u8 voiceCameraPathType9[];
extern u8 DAT_00698d40[];
extern s16 DAT_00699240[];
extern f32 DAT_00699244[];
extern f32 DAT_00699248[];
extern f32 DAT_0069924c[];
extern f32 DAT_00699250[];
extern f32 DAT_0069925c[];
extern f32 DAT_00699260[];
extern f32 DAT_00699264[];
extern f32 DAT_00699268[];
extern u32 DAT_00699be0;
extern u32 DAT_00699be4;
extern u32 DAT_00699be8;
extern u32 DAT_00699bec;
extern f32 DAT_00699c80;
extern f32 DAT_00699c84;
extern f32 DAT_00699c88;
extern f32 DAT_00699c8c;
#pragma alias DAT_00699c80_abs DAT_00699c80
#pragma alias DAT_00699c84_abs DAT_00699c84
#pragma alias DAT_00699c88_abs DAT_00699c88
#pragma alias DAT_00699c8c_abs DAT_00699c8c
extern u8 DAT_00699c80_abs[];
extern u8 DAT_00699c84_abs[];
extern u8 DAT_00699c88_abs[];
extern u8 DAT_00699c8c_abs[];
extern u8 DAT_00699cc0[];
extern u8 DAT_00699d10[];
extern u8 DAT_00699db0[];
extern u8 DAT_00699e00[];
extern const char DAT_00699c10[];
extern const char DAT_00699cb0[];
extern const char DAT_00699d00[];
extern const char DAT_00699df0[];
extern const char DAT_0069a0f8[];
extern u8 DAT_0069a000[];
#pragma alias DAT_0069a000_abs DAT_0069a000
extern u32 DAT_0069a000_abs[];
extern u8 DAT_0069a060[];
extern f32 DAT_007cad20;
extern f32 DAT_007cad34;
extern f32 DAT_007cad38;
extern f32 DAT_007cad3c;
extern f32 DAT_007cad40;
extern f32 DAT_007cad44;
extern f32 DAT_007cad48;
extern f32 DAT_007cad50;
extern f32 DAT_007cad54;
extern f32 DAT_007cad58;
extern f32 DAT_007cad5c;
extern f32 DAT_007cad60;
extern f32 DAT_007cad78;
extern f32 DAT_007cad7c;
extern f32 DAT_007cad80;
extern f32 DAT_007cad84;
extern f32 DAT_007cad88;
extern f32 DAT_007cada4;
extern f32 DAT_007cadb4;
extern f32 DAT_007cadb8;
extern f32 DAT_007cadbc;
extern f32 DAT_007cadc4;
extern f32 DAT_007cadc8;
extern f32 DAT_007cadcc;
extern f32 DAT_007cadd0;
extern f32 DAT_007cafbc;
extern f32 DAT_007cafd4;
extern f32 DAT_007cafd8;
extern f32 DAT_007cafdc;
extern f32 DAT_007cafe0;
extern f32 DAT_007cafe4;
extern f32 DAT_007cafe8;
extern f32 DAT_007cafec;
extern RwV3d D_00697890;
extern RwV3d D_006978A0;
#pragma alias D_006978A0_abs D_006978A0
extern RwV3d D_006978A0_abs[];
extern u32 DAT_007cc9a0;
extern u32 DAT_007cc9a2;
extern u32 DAT_007cc9a4;
extern u32 DAT_007cc9a8;
extern u32 DAT_007cc9aa;
extern u32 DAT_007cc9ac;
extern u32 DAT_007cc9b0;
extern u32 DAT_007cc9b2;
extern u32 DAT_007cc9b4;
 #pragma alias DAT_007cc9b0_s16 DAT_007cc9b0
 extern s16 DAT_007cc9b0_s16;
 #pragma alias DAT_007cc9b2_s16 DAT_007cc9b2
 extern s16 DAT_007cc9b2_s16;
 #pragma alias DAT_007cc9b4_s16 DAT_007cc9b4
 extern s16 DAT_007cc9b4_s16;
#pragma alias DAT_007cc9b8_s16 DAT_007cc9b8
extern s16 DAT_007cc9b8_s16;
#pragma alias DAT_007cc9ba_s16 DAT_007cc9ba
extern s16 DAT_007cc9ba_s16;
#pragma alias DAT_007cc9bc_s16 DAT_007cc9bc
extern s16 DAT_007cc9bc_s16;
extern u32 DAT_007ce3ec;
extern u32 DAT_007ce3f8;
extern u32 DAT_007ce418;
extern u16 DAT_007e094e[];
extern u16 DAT_007e0958[];
extern void (*DAT_0096017c[])(u32 handle);
extern u32 iGpffffb70c;
extern u32 iGpffffb810;
extern float uGpffff8108;
extern u32 uGpffffb21c;
extern s16 uGpffff9c98;
#pragma alias gp0xffff9c98 uGpffff9c98
extern s16 gp0xffff9c98;
#pragma alias gp0xffff9c9a uGpffff9c9a
extern s16 gp0xffff9c9a;
extern s16 uGpffff9c9a;
extern s16 uGpffff9ca0;
extern s16 uGpffff9ca2;
extern s16 uGpffff9ca4;
extern s16 uGpffff9ca8;
extern s16 uGpffff9caa;
extern s16 uGpffff9cac;
extern u64 FUN_0010a100();
extern u64 FUN_0010a2e0();
extern s32 FUN_0010a500(s16 param);
extern u32 FUN_0010a720();
extern u32 FUN_0010a770();
extern u32 FUN_001166a0();
extern u32 FUN_00116760();
extern void FUN_00116780(u32 handle);
extern void FUN_001167a0(u32 handle);
extern u32 FUN_001167c0(u32 handle, s32 mode);
extern u32 FUN_00116e20();
extern u32 FUN_00116ed0();
extern void FUN_00116ef0(u32 handle);
extern s32 FUN_00116f10(u32 handle);
extern s32 FUN_00116f20(u32 handle);
extern u32 FUN_00116f30(u32 handle);
extern void FUN_00116f50(u32 handle);
extern u32 FUN_001192b0();
extern u32 FUN_00119380();
extern void FUN_001193a0(u32 handle);
extern u32 FUN_001193c0(u32 handle);
extern void FUN_0017b2e0(u16 charId, u16 index, s32 enabled);
extern u64 FUN_0017b3d0(u16 voiceId,u16 index);
extern u32 FUN_0018b360();
extern void FUN_0018b380(KwlnTask* task);
extern s32 FUN_0018b5f0(KwlnTask* task);
extern u32 FUN_0018b620();
extern u32 FUN_0018efb0();
extern u32 FUN_0018f060();
extern void FUN_0018f080(u32 handle);
extern s32 FUN_0018f0a0(u32 handle);
extern s32 FUN_0018f0b0(u32 handle);
extern u32 FUN_0018f0c0(u32 handle);
extern void FUN_0018f0e0(u32 handle);
extern u64 FUN_00195020();
extern u64 FUN_00195290();
extern u64 FUN_001fdd40();
extern u64 FUN_001ff3d0();
extern u64 FUN_001ff3f0();
extern u64 FUN_001ff410();
extern u64 FUN_0027e390();
extern u64 FUN_0027ec10();
extern u64 FUN_0027ed20();
extern u64 FUN_0027f410();
extern u64 FUN_0027f650();
extern u64 FUN_0027f680();
extern u64 FUN_0027f710(f32 param_1, u32 param_2);
extern u64 FUN_0027f730();
extern u64 FUN_0027fcf0();
extern u64 FUN_0027fe90();
extern u64 FUN_0027ffb0();
extern u64 FUN_00280050();
extern u64 FUN_00280130();
extern u64 FUN_00280480();
extern u64 FUN_00280870();
#pragma alias FUN_00280870_btlVoice_typed FUN_00280870
extern f32 FUN_00280870_btlVoice_typed(u32 mode, u32 flags, RwV3d* position,
                                        f32* value1, f32* value2, u32 option);
#pragma alias FUN_0027ffb0_btlVoice_typed FUN_0027ffb0
extern void FUN_0027ffb0_btlVoice_typed(BtlUnit* unit, RwV3d* position);
#pragma alias FUN_00280130_btlVoice_typed FUN_00280130
extern void FUN_00280130_btlVoice_typed(BtlUnit* unit, RwV3d* position);
#pragma alias FUN_002b6070_btlVoice_typed FUN_002b6070
extern void FUN_002b6070_btlVoice_typed(BtlCamera* camera, f32 param1,
                                         f32 param2);
#pragma alias FUN_002b6460_btlVoice_typed FUN_002b6460
extern void FUN_002b6460_btlVoice_typed(BtlCamera* camera);
extern f32 FUN_002812d0(BtlUnit* unit, BtlUnit* target, s32 id);
extern u64 FUN_002822b0();
extern u64 FUN_00282bc0();
extern u64 FUN_00282c30();
extern void FUN_00282d40(f32 speed, BtlUnit* unit, s16 id, u32 blend, s8 mode);
extern void FUN_00282d40_call(BtlUnit* unit, s16 id, u32 blend, s8 mode,
                              f32 speed);
#pragma alias FUN_00282d40_call FUN_00282d40
extern u64 FUN_002831c0();
/* Broad declarations in this block intentionally coexist with caller-local result-width aliases below. */
extern u64 FUN_002838d0();
extern u64 FUN_00283c50(f32 value, u32 handle);
extern u64 FUN_00284200();
extern u64 FUN_002843e0();
extern u64 FUN_00284c90();
extern u64 FUN_00285690();
extern u64 FUN_00285d30();
extern u64 FUN_00285e50();
extern u64 FUN_00285f20();
extern u64 FUN_00287510();
extern u64 FUN_002875a0();
extern u64 FUN_002878d0();
extern void FUN_002880e0(u32 unit, u16 mode);
extern u64 FUN_002889c0();
extern u64 FUN_00288f80();
extern u64 FUN_00289f40();
extern BtlAction* FUN_0029a1d0();
extern u64 FUN_0029a2c0();
extern u64 FUN_0029a320();
extern u64 FUN_0029ad20();
extern u64 FUN_0029ea60();
extern u64 FUN_0029ec00();
extern u64 FUN_0029ec50();
extern u64 FUN_0029ec80();
extern void FUN_002a2170(void *param_1, const f32 *param_2);
extern s32 FUN_002a3750(BtlCamera* camera, u32 unit);
extern u64 FUN_002a3b40();
extern u64 FUN_002a3d70();
extern void FUN_002a4470(f32* dst, f32* src);
extern void FUN_002a44b0(f32* dst, f32* src);
extern void FUN_002a44f0(f32* dst, f32* src);
extern void FUN_002a54f0(BtlCamera* camera, u32 closeView,
                         s32 nearScale, s32 farScale);
extern u64 FUN_002a5f40();
extern u64 FUN_002a7830();
extern u64 FUN_002ac540();
extern u64 FUN_002af960();
extern u64 FUN_002b0210();
extern void FUN_002b0280(f32 weight, BtlCamera* camera, u32 arg2, u32 arg3);
extern u64 FUN_002b1e00();
extern u64 FUN_002b2060();
extern u64 FUN_002b2800();
extern u64 FUN_002b2880();
extern void FUN_002b4db0(float);
extern u64 FUN_002b4f40();
extern u64 FUN_002b6070();
extern u64 FUN_002b6460();
extern u64 FUN_002b6bf0();
extern u64 FUN_002b6cd0();
extern u64 FUN_002b71e0();
extern u64 FUN_002b8d60();
extern u64 FUN_002b8f90();
extern u64 FUN_002b9030();
extern u64 FUN_002b90d0();
extern u64 FUN_002bac00();
extern u64 FUN_002baf90();
extern u64 FUN_002bb2f0();
extern u64 FUN_002bb6f0();
extern u64 FUN_002bc950();
extern u64 FUN_002bd480();
extern u64 FUN_002bd590();
extern u64 FUN_002bd850();
extern u64 FUN_002bdbd0();
extern void FUN_002bfcb0(BtlAction* action, void* target, u8 arg2,
                         u8 arg3, u16 value);
extern u64 FUN_002c09f0();
extern u32 FUN_002c1ce0(BtlAction* action, u32 param);
extern u64 FUN_002c3770();
extern u16 FUN_002d1600();
extern u64 FUN_002d1de0();
#pragma alias FUN_002d1de0_btlVoice_typed FUN_002d1de0
extern void FUN_002d1de0_btlVoice_typed(RtQuat* out, const RwV3d* from,
                                         const RwV3d* to);
extern float FUN_002d1f30(const void* first, const void* second);
#pragma alias FUN_002d1f30_btlVoice_typed FUN_002d1f30
extern f32 FUN_002d1f30_btlVoice_typed(const f32* first, const f32* second);
extern float FUN_002d1fd0(void* from, void* to, void* eye, void* out);
extern float FUN_004c69f0(void* dst, const void* src);
extern u64 FUN_002d3e00();
extern u64 FUN_002d3fe0();
extern u64 FUN_002d4e10();
extern u64 FUN_002d5bf0();
extern u64 FUN_002d5dc0();
extern u32 FUN_002d5e10();
extern u64 FUN_002d6290();
extern u64 FUN_002d6620();
extern u64 FUN_002d7890();
extern u64 FUN_002d7e20();
extern u64 FUN_002d8090();
extern u64 FUN_002db800();
extern u64 FUN_002db890();
extern u64 FUN_002dd100();
extern u64 FUN_002dd4a0();
extern u64 FUN_002dd5e0();
extern u64 FUN_002dd690();
extern u64 FUN_002dd760();
extern u64 FUN_002dd830();
extern u64 FUN_002e2a60();
extern u64 FUN_002f6330();
extern u64 FUN_002f6510();
extern u64 FUN_002f87e0();
extern u64 FUN_002f8810();
extern u64 FUN_002f88c0();
extern u64 FUN_002f8a40();
extern u32 FUN_002fd2e0(u32 param_1, u16 param_2);
extern u32 FUN_002fd4a0(void);
extern u32 FUN_002fd500(void);
extern u64 FUN_002fdbb0();
extern u64 FUN_002fdfa0();
extern u64 FUN_002ff540();
extern u32 FUN_002ffbc0();
#pragma alias FUN_002ffbc0_btlVoice_typed FUN_002ffbc0
extern u32 FUN_002ffbc0_btlVoice_typed(u32 max);
#pragma alias FUN_00351bb0_btlVoice_typed FUN_00351bb0
extern u32 FUN_00351bb0_btlVoice_typed(u16 mode);
extern u64 FUN_002ffd70();
extern u64 FUN_002ffd90();
extern u64 FUN_002ffdf0();
extern u64 FUN_003004f0();
extern u64 FUN_00300560();
extern u64 FUN_00300580();
/* These spellings intentionally select different return widths at their respective call sites. */
extern u64 FUN_00301ca0();
extern u32 func_00301ca0();
extern u64 FUN_003068d0();
extern s16 FUN_003082f0(DatUnit* unit, u32 id);
extern u64 FUN_00308930();
extern u32 FUN_00308a50(u16 id);
extern u64 FUN_00308c60();
extern u64 FUN_003093a0();
extern u64 FUN_0030b5a0();
extern u32 FUN_0030c3a0();
extern u64 FUN_00318540();
extern s32 FUN_00318d10();
extern u64 FUN_00318ed0();
#pragma alias FUN_00318ed0_btlVoice_typed FUN_00318ed0
extern s32 FUN_00318ed0_btlVoice_typed(u32 model, s32 id, f32* out);
extern u64 FUN_003195f0();
extern u64 FUN_00351bb0();
extern void FUN_00352c50(u32 param_1, u32 param_2, u32 param_3);
extern u64 FUN_00357fd0();
#pragma alias FUN_00357fd0_btlVoice_typed FUN_00357fd0
extern u32 FUN_00357fd0_btlVoice_typed(u32 seed);
extern u64 FUN_00395170();
extern u64 FUN_004be1e0();
#pragma alias FUN_004be1e0_btlVoice_typed FUN_004be1e0
extern void FUN_004be1e0_btlVoice_typed(RwV3d* out, const RwV3d* basis,
                                         s32 count, const RtQuat* source);
#pragma alias FUN_004c6b20_btlVoice_typed FUN_004c6b20
extern void FUN_004c6b20_btlVoice_typed(f32* out, const f32* in);
#pragma alias FUN_00280050_btlVoice_typed FUN_00280050
extern void FUN_00280050_btlVoice_typed(BtlUnit* unit, RwV3d* position);
extern u64 FUN_004be310();
#pragma alias FUN_004be310_btlVoice_typed FUN_004be310
extern void FUN_004be310_btlVoice_typed(const void* first, const void* second,
                                        void* out);
extern u64 FUN_004c31b0(float param_1, void* param_2, u32 param_3, u32 param_4);
extern float FUN_004c69f0(void* dst, const void* src);
extern u64 FUN_004c6b20();
extern void FUN_004c6be0(float* out, const RwV3d* basis, void* source);
extern u64 FUN_004c6c60();
#pragma alias FUN_004c6c60_btlVoice_typed FUN_004c6c60
extern void FUN_004c6c60_btlVoice_typed(RwV3d* out, const RwV3d* src,
                                         const RwMatrix* matrix);
extern u64 FUN_00521408();
extern float FUN_0052e930(float x);
u32 func_002e2c70(u16 *param_1);
u32 func_002e2cb0(u16 param_1);
void func_002e2d00(u16 param_1);
void func_002e2d40(void);
u32 func_002e2d70(BtlVoicePacketA03Work* work);
void func_002e2f20(void);
void func_002e2f30(void);
u32 func_002e3010(BtlVoicePacketA04Work* work);
char * func_002e3120(int param_1);
u64 func_002e3350(BtlAction* action,s16 index);
s16 func_002e33f0(BtlAction* action);
void func_002e3560(u16 *param_1);
u32 func_002e35a0(void);
void func_002e35d0(u16 param_1,u16 param_2);
u32 func_002e3650(BtlVoicePacketWaitWork* work);
void func_002e36f0(void);
u32 func_002e3740(BtlVoicePacketWaitWork* work);
void func_002e37e0(void);
void func_002e3830(u16 *param_1);
u32 func_002e3870(void);
void func_002e38a0(u16 param_1);
u32 func_002e3900(BtlVoicePacketWaitWork* work);
void func_002e3990(void);
u32 func_002e39e0(BtlVoicePacketWaitWork* work);
void func_002e3a90(void);
void func_002e3ae0(u64 param_1);
u32 func_002e3b20(void);
void func_002e3b50(u32 param_1,u32 param_2,u32 param_3);
u32 func_002e3be0(BtlVoicePacketWaitWork* work);
void func_002e3c80(void);
u32 func_002e3cd0(void* work);
void func_002e3d10(void);
void func_002e3d50(int param_1);
u32 func_002e3db0(void);
void func_002e3de0(u32 param_1,u32 param_2);
u32 func_002e3e60(BtlVoicePacketC0AWork* work);
void func_002e3f20(void);
void func_002e3f70(u16 *param_1);
u32 func_002e3fb0(void);
void func_002e3fe0(u16 param_1);
u32 func_002e4040(BtlVoicePacketWaitWork* work);
void func_002e40d0(void);
u32 func_002e4120(BtlVoicePacketWaitWork* work);
void func_002e41d0(void);
void func_002e4220(u32 param_1,u32 param_2,u32 param_3);
void func_002e4240(u32 param_1);
u32 func_002e4250(void);
u32 func_002e4290(u32 param_1);
void func_002e42e0(u32 param_1);
void func_002e4310(void);
u32 func_002e4330(u32 param_1);
s32 func_002e43a0(void);
u32 func_002e4430(BtlAction* action, s32 skillId);
u32 func_002e4520(int param_1,u32 param_2,u32 param_3);
u32 func_002e4720(u16 param_1);
u32 func_002e47a0(BtlAction* action, s32 skillId);
u32 func_002e4910(BtlAction* action, s32 skillId);
void func_002e4a30(void);
void func_002e4a40(u64 param_1);
#pragma alias func_002e4a40_camera func_002e4a40
extern void func_002e4a40_camera(BtlCamera* camera);
void func_002e4f50(BtlCamera* camera);
void func_002e5040(void);
void func_002e5060(BtlCamera* camera);
void func_002e58a0(BtlCamera* param_1);
f32 func_002e6130(BtlUnit* param_1,BtlUnit* param_2,float* param_3,float* param_4);
void func_002e6a20(BtlCamera* camera, float weight);
void func_002e70b0(BtlCamera* camera);
void func_002e71c0(int param_1);
void func_002e7210(BtlCamera* camera);
void func_002e7320(void);
void func_002e7330(int param_1);
void func_002e7680(void);
void func_002e76a0(BtlCamera* camera);
void func_002e7710(BtlCamera* camera);
void func_002e77c0(BtlCamera* camera);
void func_002e7810(int param_1);
void func_002e7880(void);
void func_002e7890(u32 param_1);
void func_002e7db0(BtlCamera* param_1);
void func_002e82b0(BtlCamera* camera);
void func_002e87b0(BtlCamera* camera);
void func_002e8820(BtlCamera* camera);
void func_002e8a40(BtlCamera* camera);
void func_002e8c80(void);
void func_002e8c90(int param_1);
void func_002e8d20(void);
void func_002e8d40(void);
void func_002e8d70(void *param_1);
void func_002e8e20(void);
void func_002e8f40(void);
void func_002e9060(void);
void func_002e9170(void);
void func_002e92c0(void);
void func_002e9450(void);
void func_002e95f0(void);
int func_002e97e0(void);
void func_002e9950(void);
void func_002e9ac0(void);
void func_002e9c20(BtlAction* action);
u32 func_002e9f10(BtlAction* action);
void func_002ea060(void);
void func_002ea210(void);
void func_002ea400(void);
void func_002ea590(void);
void func_002ea860(void);
void func_002eaa40(void);
void func_002eab70(void);
void func_002eabb0(void);
void func_002eabf0(void);
u32 func_002eb250(BtlAction* action);
void func_002eb2c0(void);
u32 func_002eb9e0(BtlAction* action);
void func_002eba50(BtlAction* action);
u32 func_002ebec0(BtlAction* action);
void func_002ec000(void);
void func_002ec2c0(void);
void func_002ec4b0(BtlUnit* unit);
void func_002ec560(u32 param_1);
u32 func_002ec590(void);
void func_002ec5c0(void);
void func_002ec790(void);
void func_002ec990(BtlUnit* unit);
u32 func_002ecac0(void);
u32 func_002ecb30(BtlAction* action, s16 selection);
u32 func_002ecbe0(void);
u32 func_002ecc20(void);
void func_002ecc60(s16 *param_1, s16 *param_2);
u32 func_002ecf80(int param_1);
void func_002ed350(void);
u32 func_002ed360(u64 *param_1);
void func_002ee640(BtlAction* action);
u32 func_002eea10(BtlAction* action);
void func_002eeb70(BtlAction* action);
void func_002eec60(void);
u32 func_002eee20(BtlAction* param_1,float *param_2);
void func_002ef000(BtlAction* action);
u32 func_002ef250(BtlAction* action);
void func_002ef360(void);
void func_002ef5a0(void);
void func_002ef670(void);
void func_002ef7e0(void);
int func_002ef9d0(void);
void func_002efb40(BtlUnit* unit);
void func_002efc90(u32 param_1);
void func_002efcd0(u32 param_1);
u32 func_002efd10(void);
u32 func_002efd20(BtlUnit* unit);
u32 func_002efdb0(BtlUnit* unit);
void func_002efe50(u64 *param_1);
// FUN_002e2c70
u32 func_002e2c70(u16 *param_1)

{
  FUN_0010a2e0(*(u16 *)(iGpffffb6fc + 0xaf8),4,*param_1);
  return 1;
}

// FUN_002e2cb0
u32 func_002e2cb0(u16 param_1)

{
  BtlPacket* packet;

  packet = btlPacketCreate(0xa02, 2);
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e2c70;
  *(u16*)packet->workData = param_1;
  return (u32)packet;
}

// FUN_002e2d00
void func_002e2d00(u16 param_1)

{
  FUN_0010a2e0(*(u16 *)(iGpffffb6fc + 0xb02),2,param_1);
  return;
}

// FUN_002e2d40
void func_002e2d40(void)

{
  FUN_0010a100(2,0,8);
  return;
}

// FUN_002e2d70
u32 func_002e2d70(BtlVoicePacketA03Work* work)
{
  u32 result;
  u16 code;

  if (work->state == 0) {
    if (work->voiceId == 0) {
      code = 0x1c3;
    } else {
      code = 0x1c4;
    }
    switch (code) {
    case 0x1c3:
      *(u16 *)(iGpffffb6fc + 0xb02) = 4;
      break;
    case 0x1c4:
      *(u16 *)(iGpffffb6fc + 0xb02) = 5;
      break;
    }
    if (iGpffffb810 == 0) {
      *(u32 *)(iGpffffb6fc + 0xb04) = 0;
      result = FUN_0010a770(*(u32 *)(iGpffffb6fc + 0xd18),
                            *(u16 *)(iGpffffb6fc + 0xb02),
                            *(u32 *)(iGpffffb6fc + 0xb04),
                            2, code, 1);
    } else {
      result = 0;
    }
    work->result = result;
    work->state = 1;
  }
  if (work->result != 0) {
    if ((*(u16 *)(iGpffffb6fc + 0xb00) & 1) != 0) {
      result = 1;
    } else if (FUN_0010a720(work->result) != 0) {
      *(u16 *)(iGpffffb6fc + 0xb00) =
          *(u16 *)(iGpffffb6fc + 0xb00) | 1;
      result = 1;
    } else {
      result = 0;
    }
    return result != 0;
  }
  return 1;
}

// FUN_002e2ec0
BtlPacket* func_002e2ec0(u16 voiceId)
{
  BtlPacket* packet;
  BtlVoicePacketA03Work* work;

  packet = btlPacketCreate(0xa03, sizeof(BtlVoicePacketA03Work));
  packet->unk_47 &= 0xfe;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e2d70;
  work = (BtlVoicePacketA03Work*)packet->workData;
  work->voiceId = voiceId;
  work->result = 0;
  work->state = 0;
  return packet;
}

// FUN_002e2f20
void func_002e2f20(void)

{
  return;
}

// FUN_002e2f30
void func_002e2f30(void)

{
  FUN_00521408(iGpffffb6fc + 0xaf4,0,0x14);
  *(u16 *)(iGpffffb6fc + 0xaf8) = 3;
  *(u16 *)(iGpffffb6fc + 0xb02) = 0;
  uGpffffb21c = 1;
  return;
}

// FUN_002e2f80
void func_002e2f80(void)
{
  u32 handle;

  handle = *(u32 *)(iGpffffb6fc + 0xafc);
  if (handle != 0) {
    DAT_0096017c[0](handle);
    *(u32 *)(iGpffffb6fc + 0xafc) = 0;
    *(u16 *)(iGpffffb6fc + 0xaf6) &= 0xfffe;
  }
  handle = *(u32 *)(iGpffffb6fc + 0xb04);
  if (handle != 0) {
    DAT_0096017c[0](handle);
    *(u32 *)(iGpffffb6fc + 0xb04) = 0;
    *(u16 *)(iGpffffb6fc + 0xb00) &= 0xfffe;
  }
  uGpffffb21c = 0;
}

// FUN_002e3010
u32 func_002e3010(BtlVoicePacketA04Work* work)
{
  u32 result;
  s32 status;

  if (work->state == 0) {
    FUN_0010a2e0(work->arg0,work->arg1,work->arg2);
    work->state = 1;
  }
  if ((work->flags & 1) == 0) {
    goto result_one;
  }
  status = FUN_0010a500((s16)work->arg1);
  if (status != 1) {
    goto result_one;
  }
  result = 0;
  goto done;

result_one:
  result = 1;
done:
  return result;
}

// FUN_002e30a0
BtlPacket* func_002e30a0(u16 arg0, u16 arg1, u16 arg2, u16 flags)
{
  BtlPacket* packet;
  BtlVoicePacketA04Work* work;

  packet = btlPacketCreate(0xa04, sizeof(BtlVoicePacketA04Work));
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3010;
  work = (BtlVoicePacketA04Work*)packet->workData;
  work->arg0 = arg0;
  work->arg1 = arg1;
  work->arg2 = arg2;
  work->flags = flags;
  work->state = 0;
  return packet;
}

// FUN_002e3120 NONMATCHING
char * func_002e3120(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  char *pcVar6;
  
  for (uVar5 = 0; uVar5 < 0xc; uVar5 = uVar5 + 1 & 0xffff) {
    iVar3 = (int)iGpffffb6fc + uVar5 * 4;
    if (*(char *)(iVar3 + 0xa60) != -1) {
      iVar4 = *(int *)(iGpffffb6fc + *(char *)(iVar3 + 0xa60) * 8 + 0x154);
      while ((iVar4 != 0 &&
             ((*(int *)(iVar4 + 0xa2c) == 0 ||
              (*(short *)(iVar3 + 0xa62) != *(short *)(*(int *)(iVar4 + 0xa2c) + 4)))))) {
        iVar4 = *(int *)(iVar4 + 0xa30);
      }
      if (iVar4 == 0) {
        *(u8 *)(iVar3 + 0xa60) = 0xff;
        *(u16 *)(iGpffffb6fc + uVar5 * 4 + 0xa62) = 0;
      }
    }
  }
  pcVar6 = (char *)0x0;
  cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0xa2);
  sVar2 = *(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 4);
  uVar5 = 0;
  while( true ) {
    if (0xb < uVar5) {
      FUN_00521408(pcVar6,0,4);
      *pcVar6 = cVar1;
      *(short *)(pcVar6 + 2) = sVar2;
      return pcVar6;
    }
    iVar3 = (int)iGpffffb6fc + uVar5 * 4;
    if ((*(char *)(iVar3 + 0xa60) == cVar1) && (*(short *)(iVar3 + 0xa62) == sVar2)) break;
    if ((pcVar6 == (char *)0x0) && (*(char *)(iVar3 + 0xa60) == -1)) {
      pcVar6 = (char *)(iVar3 + 0xa60);
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  return (char *)(iVar3 + 0xa60);
}

// FUN_002e32a0
void func_002e32a0(BtlAction* action, BtlAction* target, u32 id)
{
  s16 index;
  BtlVoiceUnitEntry* entry;

  if (target->unit->genus == UNIT_GENUS_EC) {
    entry = (BtlVoiceUnitEntry*)func_002e3120((int)target);
    index = FUN_003082f0(action->unit->datUnit, id);
    if ((index != -1) && (index < 10)) {
      FUN_0017b2e0(entry->charId, index, 1);
    }
  }
}

// FUN_002e3350
u64 func_002e3350(BtlAction* action,s16 index)
{
  BtlUnit* unit;
  u8* entry;
  u64 result;

  unit = action->unit;
  if (unit->genus != 1) {
    result = 1;
  }
  else {
    entry = (u8*)func_002e3120((int)action);
    if (!((index != -1) && (index < 10))) {
      result = 1;
    }
    else if (index == 7) {
      result = 1;
    }
    else {
      result = FUN_0017b3d0(*(u16 *)(entry + 2),index);
    }
  }
  return result;
}

// FUN_002e33f0
s16 func_002e33f0(BtlAction* action)
{
    BtlUnit* unit;

    unit = action->unit;
    if (unit->genus == UNIT_GENUS_EC)
    {
        switch (unit->charId)
        {
        case 0x10b:
        case 0x110: return 0xf;
        case 0x10c:
        case 0x10f: return 0x10;
        case 0x108: return 0x11;
        case 0x126: return 0x67;
        case 0xe9: return 0xe9;
        case 0xea: return 0xea;
        case 0xeb: return 7;
        case 0xec: return 8;
        case 0xed: return 5;
        case 0xee: return 10;
        case 0xef: return 2;
        case 0xf0: return 4;
        default: return -1;
        }
    }
    return unit->charId;
}

// FUN_002e3560
void func_002e3560(u16 *param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_001166a0(*(u32 *)(iGpffffb6fc + 0xd18),*param_1,param_1[1]);
  *(u32 *)(iGpffffb6fc + 0xd20) = uVar1;
  return;
}

// FUN_002e35a0
u32 func_002e35a0(void)

{
  s32 lVar1;
  
  lVar1 = FUN_00116760(*(u32 *)(iGpffffb6fc + 0xd20));
  return lVar1 == 1;
}

// FUN_002e35d0
void func_002e35d0(u16 arg0,u16 arg1)
{
  BtlPacket* packet;
  BtlVoicePacketC00Work* work;

  packet = btlPacketCreate(0xc00,sizeof(BtlVoicePacketC00Work));
  packet->unk_47 &= 0xee;
  packet->initFunc = (BtlPacketInitFunc)func_002e3560;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e35a0;
  work = (BtlVoicePacketC00Work*)packet->workData;
  work->arg0 = arg0;
  work->arg1 = arg1;
  work->state = 0;
}

// FUN_002e3650
u32 func_002e3650(BtlVoicePacketWaitWork* work)
{
  s32 endFrame;

  if (work->state == 0) {
    FUN_00116780(*(u32 *)(iGpffffb6fc + 0xd20));
    work->state = 1;
  }
  else {
    endFrame = FUN_001167c0(*(u32 *)(iGpffffb6fc + 0xd20),0);
    if (endFrame <= work->frame + 0x1b) {
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e36f0
void func_002e36f0(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc01,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3650;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e3740
u32 func_002e3740(BtlVoicePacketWaitWork* work)
{
  s32 endFrame;

  if (work->state == 0) {
    FUN_001167a0(*(u32 *)(iGpffffb6fc + 0xd20));
    work->state = 1;
  }
  else {
    endFrame = FUN_001167c0(*(u32 *)(iGpffffb6fc + 0xd20),1);
    if (endFrame <= work->frame) {
      *(u32 *)(iGpffffb6fc + 0xd20) = 0;
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e37e0
void func_002e37e0(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc02,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3740;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e3830
void func_002e3830(u16 *param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_00116e20(*(u32 *)(iGpffffb6fc + 0xd18),*param_1);
  *(u32 *)(iGpffffb6fc + 0xd20) = uVar1;
  return;
}

// FUN_002e3870
u32 func_002e3870(void)

{
  s32 lVar1;
  
  lVar1 = FUN_00116ed0(*(u32 *)(iGpffffb6fc + 0xd20));
  return lVar1 == 1;
}

// FUN_002e38a0
void func_002e38a0(u16 voiceId)
{
  BtlPacket* packet;
  BtlVoicePacketC03Work* work;

  packet = btlPacketCreate(0xc03,sizeof(BtlVoicePacketC03Work));
  packet->unk_47 &= 0xee;
  packet->initFunc = (BtlPacketInitFunc)func_002e3830;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3870;
  work = (BtlVoicePacketC03Work*)packet->workData;
  work->voiceId = voiceId;
}

// FUN_002e3900
u32 func_002e3900(BtlVoicePacketWaitWork* work)
{
  if (work->state == 0) {
    FUN_00116ef0(*(u32*)((u8*)gBtl + 0xd20));
    work->state = 1;
  }
  else {
    if (FUN_00116f30(*(u32*)((u8*)gBtl + 0xd20)) != 0) {
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e3990
void func_002e3990(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc04,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3900;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e39e0
u32 func_002e39e0(BtlVoicePacketWaitWork* work)
{
  s32 endFrame;

  if (work->state == 0) {
    FUN_00116f50(*(u32 *)(iGpffffb6fc + 0xd20));
    work->state = 1;
    work->frame = FUN_00116f20(*(u32 *)(iGpffffb6fc + 0xd20));
  }
  else {
    endFrame = FUN_00116f10(*(u32 *)(iGpffffb6fc + 0xd20));
    if (endFrame <= work->frame) {
      *(u32 *)(iGpffffb6fc + 0xd20) = 0;
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e3a90
void func_002e3a90(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc05,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e39e0;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e3ae0
void func_002e3ae0(u64 param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_001192b0(*(u32 *)(iGpffffb6fc + 0xd18),param_1);
  *(u32 *)(iGpffffb6fc + 0xd24) = uVar1;
  return;
}

// FUN_002e3b20
u32 func_002e3b20(void)

{
  s32 lVar1;
  
  lVar1 = FUN_00119380(*(u32 *)(iGpffffb6fc + 0xd24));
  return lVar1 == 1;
}

// FUN_002e3b50
void func_002e3b50(u32 arg0,u32 arg1,u32 arg2)
{
  BtlPacket* packet;
  BtlVoicePacketC06Work* work;

  packet = btlPacketCreate(0xc06,sizeof(BtlVoicePacketC06Work));
  packet->unk_47 &= 0xee;
  packet->initFunc = (BtlPacketInitFunc)func_002e3ae0;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3b20;
  work = (BtlVoicePacketC06Work*)packet->workData;
  work->arg0 = arg0 & 0xffff;
  work->arg1 = arg1 & 0xffff;
  work->arg2 = arg2 & 0xffff;
  work->state = 0;
}

// FUN_002e3be0
u32 func_002e3be0(BtlVoicePacketWaitWork* work)
{
  s32 endFrame;

  if (work->state == 0) {
    FUN_001193a0(*(u32 *)(iGpffffb6fc + 0xd24));
    work->state = 1;
  }
  else {
    endFrame = FUN_001193c0(*(u32 *)(iGpffffb6fc + 0xd24));
    if (endFrame <= work->frame + 0xc) {
      *(u32 *)(iGpffffb6fc + 0xd24) = 0;
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e3c80
void func_002e3c80(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc07,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3be0;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e3cd0
u32 func_002e3cd0(void* work)

{
  FUN_00195020(*(u32 *)(iGpffffb6fc + 0xd24));
  *(u32 *)(iGpffffb6fc + 0xd24) = 0;
  return 1;
}

// FUN_002e3d10
void func_002e3d10(void)
{
  BtlPacket* packet;

  packet = btlPacketCreate(0xc08,0);
  packet->unk_47 &= 0xee;
  packet->updateFunc = func_002e3cd0;
}

// FUN_002e3d50
void func_002e3d50(int param_1)

{
  u32 playbackHandle;
  int voiceId;
  u8 *voiceEntry;
  u32 params[2];

  voiceEntry = (u8 *)(uintptr_t)iGpffffb70c;
  voiceId = *(int *)(param_1 + 4);
  voiceEntry = (u8 *)(uintptr_t)(voiceId * 6) + (uintptr_t)voiceEntry;
  params[0] = (u32)*(u16 *)(voiceEntry - 0x65e);
  params[1] = (u32)*(u16 *)(voiceEntry - 0x65c);
  playbackHandle = FUN_0018b620(*(u32 *)(iGpffffb6fc + 0xd18), voiceId, params);
  *(u32 *)(iGpffffb6fc + 0xd20) = playbackHandle;
  return;
}

// FUN_002e3db0
u32 func_002e3db0(void)

{
  s32 lVar1;
  
  lVar1 = FUN_0018b360(*(u32 *)(iGpffffb6fc + 0xd20));
  return lVar1 == 1;
}

// FUN_002e3de0
void func_002e3de0(u32 voiceId,u32 param)
{
  BtlPacket* packet;
  BtlVoicePacketC09Work* work;

  packet = btlPacketCreate(0xc09,sizeof(BtlVoicePacketC09Work));
  packet->unk_47 &= 0xee;
  packet->initFunc = (BtlPacketInitFunc)func_002e3d50;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3db0;
  work = (BtlVoicePacketC09Work*)packet->workData;
  work->voiceId = voiceId & 0xffff;
  work->param = param & 0xffff;
}

// FUN_002e3e60
u32 func_002e3e60(BtlVoicePacketC0AWork* work)
{
    if (work->frame == 0)
    {
        FUN_0018b380((KwlnTask*)(uintptr_t)*(u32*)(iGpffffb6fc + 0xd20));
    }
    else
    {
        switch (kwlnTaskGetState(
            (KwlnTask*)(uintptr_t)*(u32*)(iGpffffb6fc + 0xd20)))
        {
            case KWLNTASK_STATE_STAGED:
                break;
            case KWLNTASK_STATE_RUNNING:
                if (FUN_0018b5f0(
                        (KwlnTask*)(uintptr_t)*(u32*)(iGpffffb6fc + 0xd20)) >= 30)
                {
                    *(u32*)(iGpffffb6fc + 0xd20) = 0;
                    return 1;
                }
                break;
        }
    }

    work->frame++;
    return 0;
}

// FUN_002e3f20
void func_002e3f20(void)
{
    BtlPacket* packet;
    BtlVoicePacketC0AWork* work;

    packet = btlPacketCreate(0xc0a, sizeof(BtlVoicePacketC0AWork));
    packet->unk_47 &= 0xee;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002e3e60;
    work = (BtlVoicePacketC0AWork*)packet->workData;
    work->frame = 0;
}

// FUN_002e3f70
void func_002e3f70(u16 *param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_0018efb0(*(u32 *)(iGpffffb6fc + 0xd18),*param_1);
  *(u32 *)(iGpffffb6fc + 0xd20) = uVar1;
  return;
}

// FUN_002e3fb0
u32 func_002e3fb0(void)

{
  s32 lVar1;
  
  lVar1 = FUN_0018f060(*(u32 *)(iGpffffb6fc + 0xd20));
  return lVar1 == 1;
}

// FUN_002e3fe0
void func_002e3fe0(u16 voiceId)
{
  BtlPacket* packet;
  BtlVoicePacketC0BWork* work;

  packet = btlPacketCreate(0xc0b,sizeof(BtlVoicePacketC0BWork));
  packet->unk_47 &= 0xee;
  packet->initFunc = (BtlPacketInitFunc)func_002e3f70;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e3fb0;
  work = (BtlVoicePacketC0BWork*)packet->workData;
  work->voiceId = voiceId;
}

// FUN_002e4040
u32 func_002e4040(BtlVoicePacketWaitWork* work)
{
  if (work->state == 0) {
    FUN_0018f080(*(u32*)((u8*)gBtl + 0xd20));
    work->state = 1;
  }
  else {
    if (FUN_0018f0c0(*(u32*)((u8*)gBtl + 0xd20)) != 0) {
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e40d0
void func_002e40d0(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc0c,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e4040;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e4120
u32 func_002e4120(BtlVoicePacketWaitWork* work)
{
  s32 endFrame;

  if (work->state == 0) {
    FUN_0018f0e0(*(u32 *)(DAT_007ce3ec + 0xd20));
    work->state = 1;
    work->frame = FUN_0018f0b0(*(u32 *)(DAT_007ce3ec + 0xd20));
  }
  else {
    endFrame = FUN_0018f0a0(*(u32 *)(DAT_007ce3ec + 0xd20));
    if (endFrame <= work->frame) {
      *(u32 *)(DAT_007ce3ec + 0xd20) = 0;
      return 1;
    }
  }
  work->frame++;
  return 0;
}

// FUN_002e41d0
void func_002e41d0(void)
{
  BtlPacket* packet;
  BtlVoicePacketWaitWork* work;

  packet = btlPacketCreate(0xc0d,sizeof(BtlVoicePacketWaitWork));
  packet->unk_47 &= 0xee;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002e4120;
  work = (BtlVoicePacketWaitWork*)packet->workData;
  work->state = 0;
  work->frame = 0;
}

// FUN_002e4220
void func_002e4220(u32 param_1,u32 param_2,u32 param_3)

{
  *(u32 *)(DAT_007ce3ec + 0xb08) = param_1;
  *(u32 *)(DAT_007ce3ec + 0xb0c) = param_2;
  *(u32 *)(DAT_007ce3ec + 0xb10) = param_3;
  return;
}

// FUN_002e4240
void func_002e4240(u32 param_1)

{
  *(u32 *)(DAT_007ce3ec + 0xb10) = param_1;
  return;
}

// FUN_002e4250
u32 func_002e4250(void)

{
  u32 uVar1;
  
  if ((*(int *)(DAT_007ce3ec + 0xb08) != 0) ||
      (*(int *)(DAT_007ce3ec + 0xb0c) != 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_002e4290
u32 func_002e4290(u32 param_1)
{
  return FUN_002fd2e0(param_1, 0);
}

// FUN_002e42c0
void func_002e42c0(void)
{
  FUN_002fd4a0();
}

// FUN_002e42e0
void func_002e42e0(u32 param_1)
{
  FUN_002fd2e0(param_1, 1);
}

// FUN_002e4310
void func_002e4310(void)
{
  FUN_002fd4a0();
}

// FUN_002e4330
u32 func_002e4330(u32 param_1)

{
  void (*callback)(u32);

  if (FUN_002fd500() == 0) {
    callback = *(void (**)(u32))(DAT_007ce3ec + 0xb08);
    if (callback != NULL) {
      callback(*(u32 *)(DAT_007ce3ec + 0xb10));
      return 1;
    }
  }
  return FUN_002fd2e0(param_1, 2);
}

// FUN_002e43a0
s32 func_002e43a0(void)

{
  s32 (*callback)(u32);
  s32 result;

  result = 0;
  if (FUN_002fd500() == 0) {
    callback = *(s32 (**)(u32))(DAT_007ce3ec + 0xb0c);
    if (callback != NULL) {
      result = callback(*(u32 *)(DAT_007ce3ec + 0xb10));
      if (result == 0) {
        *(u32 *)(DAT_007ce3ec + 0xb08) = 0;
        *(u32 *)(DAT_007ce3ec + 0xb0c) = 0;
        *(u32 *)(DAT_007ce3ec + 0xb10) = 0;
      }
    }
  }
  if (result == 0) {
    result = FUN_002fd4a0();
  }
  return result;
}

// FUN_002e4430
u32 func_002e4430(BtlAction* action, s32 skillId)
{
    u8* entry;
    s32 offset;
    u16 value;
    struct
    {
        u8 data[0x38];
        u16 count;
    } target;

    if (skillId < 1)
        return 0;
    offset = skillId * 0x2c;
    entry = (u8*)(DAT_007ce3f8 + offset);
    if ((*entry & 8) == 0)
        return 0;
    value = *(volatile /* Removing this qualifier loses func_002e4430 (MATCH nd0 -> MISMATCH nd11, size 240 -> 240) - measured W170. */ u16*)(entry + 0xc);
    FUN_002bfcb0(action, &target, entry[9], entry[10], value);
    if (target.count == 0)
        return 2;
    switch (*(u8*)(offset + DAT_007ce3f8 + 0x24))
    {
    case 6:
        if (FUN_002c1ce0(action, 0) == 0)
            return 6;
        break;
    }
    return 0;
}

// FUN_002e4520 NONMATCHING
u32 func_002e4520(int param_1,u32 param_2,u32 param_3)

{
  /* Caller-specific return widths keep these two results in the retail integer register class. */
  extern u32 FUN_00301ca0();
  extern u32 FUN_003068d0();
  u32 uVar1;
  s32 lVar2;
  u8 *pbVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  
  if ((s32)param_2 >= 1) {
    pbVar3 = (u8 *)(DAT_007ce3f8 + (int)param_2 * 0x2c);
    if ((*pbVar3 & 8) != 0) {
      uVar4 = *(u32 *)(pbVar3 + 0x20);
      if (((uVar4 & 0x3ffffff) != 0) && ((uVar4 & 0xfc000000) == 0)) {
        for (uVar7 = 0; uVar7 < 0x20; uVar7 = uVar7 + 1) {
          uVar5 = 1 << (uVar7 & 0x1f);
          if ((uVar4 & uVar5) != 0) {
            uVar6 = 0;
            while ((uVar6 < *(u16 *)(param_1 + 0x6a) &&
                   (lVar2 = FUN_00301ca0(*(u32 *)
                                          (*(int *)(*(int *)(param_1 + uVar6 * 4 + 0x38) + 0x30) +
                                          0xa2c),uVar5), lVar2 != 0))) {
              uVar6 = uVar6 + 1;
            }
            if (uVar6 != *(u16 *)(param_1 + 0x6a)) break;
          }
        }
        if (uVar7 == 0x20) {
          if ((uVar4 & 0x3000) != 0) {
            return 5;
          }
          return 3;
        }
      }
      uVar4 = 0;
      while (((uVar4 < *(u16 *)(param_1 + 0x6a) &&
              (lVar2 = FUN_003068d0(param_2 & 0xffff,
                                    *(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),
                                    *(u32 *)
                                     (*(int *)(*(int *)(param_1 + uVar4 * 4 + 0x38) + 0x30) + 0xa2c)
                                    ,param_3), lVar2 != 0)) && (lVar2 != 0xffff))) {
        uVar4 = uVar4 + 1;
      }
      if (uVar4 != *(u16 *)(param_1 + 0x6a)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_002e4720
u32 func_002e4720(u16 param_1)

{
  switch (param_1) {
  case 2:
    return 200;
  case 3:
    return 0xc9;
  case 4:
    return 0xca;
  case 5:
    return 0xcb;
  case 6:
    return 0xcc;
  case 7:
    return 0xd9;
  default:
    return 0;
  }
}

// FUN_002e47a0
u32 func_002e47a0(BtlAction* action, s32 skillId)
{
    u8* entry;
    u32 flags;
    u32 i;
    u32 j;
    u32 bit;

    if (skillId < 1)
        return 0;
    entry = (u8*)(DAT_007ce3f8 + skillId * 0x2c);
    if ((*entry & 8) == 0)
        return 0;
    flags = *(u32*)(entry + 0x20);
    if (((flags & 0x3ffffff) != 0) && ((flags & 0xfc000000) == 0))
    {
        for (i = 0; i < 0x20; i++)
        {
            bit = 1 << i;
            if ((flags & bit) != 0)
            {
                for (j = 0; j < action->target.targetedCount; j++)
                {
                    if (func_00301ca0((*(BtlAction**)(action->target.targetedActions + j))->unit->datUnit, bit) == 0)
                        break;
                }
                if (j != action->target.targetedCount)
                    break;
            }
        }
        if (i == 0x20)
        {
            if ((flags & 0x3000) != 0)
                return 7;
            return 3;
        }
    }
    return 0;
}

// FUN_002e4910
u32 func_002e4910(BtlAction* action, s32 skillId)
{
    u8* entry;
    u32 flags;
    u32 bit;
    u32 i;

    if (skillId < 1)
        return 0;
    entry = (u8*)(DAT_007ce3f8 + skillId * 0x2c);
    if ((*entry & 8) == 0)
        return 0;
    flags = *(u32*)(entry + 0x20);
    if (((flags & 0x3ffffff) != 0) && ((flags & 0xfc000000) == 0))
    {
        for (i = 0; i < 0x20; i++)
        {
            bit = 1 << i;
            if (((flags & bit) != 0) &&
                (func_00301ca0(action->unit->datUnit, bit) == 0))
            {
                break;
            }
        }
        if (i == 0x20)
        {
            if ((flags & 0x3000) != 0)
                return 7;
            return 3;
        }
    }
    return 0;
}

// FUN_002e4a30
void func_002e4a30(void)
{
}

// FUN_002e4a40 NONMATCHING
void func_002e4a40(u64 param_1)

{
  int iVar1;
  int iVar2;
  u32 bVar3;
  s32 lVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  u8 auStack_74 [16];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  u8 auStack_58 [24];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float afStack_20 [4];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0xe0);
  if (iVar1 != 0) {
    if (*(char *)(*(int *)(iVar1 + 0x30) + 0xa2) == '\0') {
      if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1d) || (*(short *)(DAT_007ce3ec + 0x104) == 0x1c))
      {
        bVar3 = false;
        goto LAB_002e4af0;
      }
    }
    else if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1f) ||
            (*(short *)(DAT_007ce3ec + 0x104) == 0x12)) {
      bVar3 = false;
      goto LAB_002e4af0;
    }
    bVar3 = true;
  }
  else {
    bVar3 = true;
  }
LAB_002e4af0:
  iVar2 = *(int *)(iVar1 + 0x30);
  fVar6 = *(float *)(iVar2 + 0x90);
  fVar7 = *(float *)(iVar2 + 0x2c);
  if ((*(short *)(DAT_007ce3ec + 0x104) == 9) &&
     (*(int *)(DAT_007ce3ec + 0xb7c) == *(int *)(iVar1 + 8))) {
    if (*(int *)(DAT_007ce3ec + 0xb80) != 0) {
      FUN_002a3e80(0.0f,(u8 *)(uintptr_t)*(u32 *)(iVar5 + 0xe0),0,0,8);
      return;
    }
  }
  else {
    *(u32 *)(DAT_007ce3ec + 0xb7c) = *(u32 *)(iVar1 + 8);
    *(u32 *)(DAT_007ce3ec + 0xb80) = 0;
    FUN_002a4470((f32 *)auStack_58,(f32 *)((u8 *)param_1 + 0x9c));
    if (*(char *)(iVar2 + 0xa2) == '\0') {
      FUN_00280870_btlVoice_typed(2,1,(RwV3d *)&fStack_10,0,0,1);
      FUN_0027ffb0_btlVoice_typed((BtlUnit *)iVar2,(RwV3d *)afStack_20);
      afStack_20[1] = 0.0f;
      fStack_c = 0.0f;
      fStack_40 = afStack_20[0] - fStack_10;
      fStack_3c = 0.0f;
      fStack_38 = afStack_20[2] - fStack_8;
      fVar8 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
      fVar8 = DAT_007cad50 * fVar8;
      fStack_10 = fStack_10 + fStack_40 * fVar8;
      fStack_c = fStack_c + fStack_3c * fVar8;
      fStack_8 = fStack_8 + fStack_38 * fVar8;
      fStack_30 = afStack_20[0];
      fStack_2c = DAT_007cad54 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_2c + 0.0f;
      fStack_28 = afStack_20[2];
      fVar8 = (float)FUN_0052e930(*(float *)(iVar5 + 0xb8) * 0.5f);
      fVar8 = (fVar6 * fVar7 * 5.5f) / fVar8;
      fStack_40 = fStack_30 - fStack_10;
      fStack_3c = fStack_2c - fStack_c;
      fStack_38 = fStack_28 - fStack_8;
      FUN_004c69f0(&fStack_40,&fStack_40);
      fStack_64 = fStack_40 * fVar8 + fStack_30 + 0.0f;
      fStack_60 = fStack_3c * fVar8 + fStack_2c + 0.0f;
      fStack_5c = fStack_38 * fVar8 + fStack_28 + 0.0f;
      FUN_002a4690(auStack_74,&fStack_80,&fStack_64,D_00697880);
    }
    else {
      if ((*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) &&
         (lVar4 = FUN_002f6330(param_1), lVar4 != 0)) {
        return;
      }
      FUN_00280870_btlVoice_typed(2,1,(RwV3d *)afStack_20,&fStack_4,0,1);
      FUN_00280130_btlVoice_typed((BtlUnit *)iVar2,(RwV3d *)&fStack_10);
      fStack_64 = fStack_80;
      fStack_60 = fStack_7c;
      fStack_5c = fStack_78;
      fVar6 = fStack_4 * 1.25f;
      if (fStack_4 * 1.25f <= fStack_7c) {
        fVar6 = fStack_60;
      }
      fStack_60 = fVar6;
    }
    FUN_002a4690(auStack_74,&fStack_80,&fStack_64,D_00697880);
    fVar9 = FUN_002d1f30_btlVoice_typed((f32 *)auStack_74, (f32 *)&fStack_80);
    if ((fVar9 > DAT_007cad58) && bVar3) {
      if ((*(char *)(iVar2 + 0xa2) == '\x01') &&
         (lVar4 = FUN_0030c3a0(*(u32 *)(iVar2 + 0xa2c)), lVar4 != 0)) {
        FUN_002b6070_btlVoice_typed((BtlCamera *)param_1,2.25f,2.0f);
      }
      else {
        FUN_002b6460_btlVoice_typed((BtlCamera *)param_1);
      }
      FUN_002a3e80(0.0f,(u8 *)(uintptr_t)*(u32 *)(iVar5 + 0xe0),0,0,8);
      *(u32 *)(DAT_007ce3ec + 0xb80) = 1;
    }
    if (fStack_7c < 25.0f) {
      fStack_7c = 25.0f;
    }
    if (fStack_60 < 25.0f) {
      fStack_60 = 25.0f;
    }
    FUN_002a2290((BtlCamera *)param_1, &fStack_80, &fStack_64, 1);
    FUN_002a3110((BtlCamera *)param_1, bVar3 ? 2.5f : 1.25f);
    }
  return;
}

// FUN_002e4f50
void func_002e4f50(BtlCamera* camera)
{
    BtlAction* action;
    u32 closeView;

    action = camera->action;
    if (action == NULL)
    {
        closeView = 1;
        goto checkSpecificId;
    }

    if (action->unit->genus == UNIT_GENUS_PC)
    {
        switch (*(u16*)(DAT_007ce3ec + 0x104))
        {
        case BTLCAMERA_STATE_COMMAND:
        case BTLCAMERA_STATE_TARGET:
            closeView = 0;
            goto checkSpecificId;
        }
    }
    else
    {
        switch (*(u16*)(DAT_007ce3ec + 0x104))
        {
        case BTLCAMERA_STATE_MOVETARGET:
        case BTLCAMERA_STATE_RESET:
            closeView = 0;
            goto checkSpecificId;
        }
    }

    closeView = 1;

checkSpecificId:
    if (FUN_00308a50(action->target.originalSpecificId) != 0)
        closeView = 1;

    FUN_002a54f0(camera, closeView, 10, 10);
}

// FUN_002e5040
void func_002e5040(void)

{
  FUN_002a5f40();
  return;
}

// FUN_002e5060 NONMATCHING
void func_002e5060(BtlCamera* camera)
{
  BtlAction *action;
  BtlUnit *unit;
  BtlUnit *targetUnit;
  u8 *voiceData;
  u16 state;
  u16 charId;
  u16 targetId;
  u32 usePreset;
  u32 useLargeOffset;
  s32 result;
  s32 index;
  s16 kind;
  f32 angleA;
  f32 angleB;
  f32 radius;
  f32 width;
  f32 height;
  f32 scale;
  f32 factorA;
  f32 factorB;
  f32 curve;
  f32 poly;
  f32 tmp;
  RwV3d position;
  RwV3d start;
  RwV3d end;
  RwV3d direction;
  RwV3d transformed;
  RwV3d output;
  RtQuat startRot;
  RtQuat endRot;
  RtQuat blendRot;
  RwMatrix matrix;
  f32 blend[10];

  if ((*(u16 *)(*(u32 *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) &&
      (FUN_002f6510() != 0)) {
    return;
  }

  action = camera->action;
  if (action == 0) {
    usePreset = 1;
  } else if (action->unit->genus == 0) {
    state = *(u16 *)(DAT_007ce3ec + 0x104);
    if ((state == 0x1d) || (state == 0x1c)) {
      usePreset = 0;
    } else {
      usePreset = 1;
    }
  } else {
    state = *(u16 *)(DAT_007ce3ec + 0x104);
    if ((state == 0x1f) || (state == 0x12)) {
      usePreset = 0;
    } else {
      usePreset = 1;
    }
  }

  unit = action->unit;
  FUN_0027ffb0_btlVoice_typed(unit, (RwV3d *)&position);
  result = FUN_0030c3a0(unit->datUnit);
  if ((result != 0) && (usePreset != 0)) {
    charId = unit->charId;
    if (((charId == 0x110) || (charId == 0x10b)) &&
        ((kind = (s16)FUN_00282c30(unit)), kind != 4)) {
      useLargeOffset = 1;
    } else {
      useLargeOffset = 0;
    }
    if (useLargeOffset == 0) {
      position.y = unit->unk_8c * unit->scale * 0.25f +
                   position.y + 0.0f;
    }
    result = FUN_002d6290(action);
    if (result == 0) {
      targetId = FUN_002d1600((u8 *)action + 0x38);
      FUN_00280870_btlVoice_typed(targetId, 1, &end, 0, 0, 1);
    } else {
      targetUnit = action->target.targetedActions[0]->unit;
      FUN_0027ffb0_btlVoice_typed(targetUnit, (RwV3d *)&end);
    }
    FUN_002d1de0_btlVoice_typed(&startRot, &position, &end);
    FUN_004be1e0_btlVoice_typed(&direction, &D_006978A0, 1, &startRot);
    radius = unit->sphereRadius * unit->scale;
    if (useLargeOffset != 0) {
      width = radius * 2.75f;
      height = radius * 2.25f;
    } else {
      width = DAT_007cadc8 * radius;
      height = DAT_007cadcc * radius;
    }
    if (useLargeOffset != 0) {
      if (((u32)FUN_00357fd0(0) & 1) == 0) {
        angleA = -30.0f;
      } else {
        angleA = 30.0f;
      }
    } else {
      result = FUN_002ffbc0_btlVoice_typed(3);
      if (result == 1) {
        angleA = -30.0f;
      } else if (result == 0) {
        angleA = 30.0f;
      } else {
        angleA = 0.0f;
      }
    }
    if (useLargeOffset != 0) {
      angleB = -40.0f;
    } else {
      result = FUN_002ffbc0_btlVoice_typed(3);
      if (result == 1) {
        angleB = -15.0f;
      } else if (result == 0) {
        angleB = 15.0f;
      } else {
        angleB = 0.0f;
      }
    }
    FUN_004c31b0(angleB, &matrix, 0x697870, 0);
    FUN_004c31b0(angleA, &matrix, 0x697880, 2);
    FUN_004c6c60_btlVoice_typed(&transformed, &direction, &matrix);
    scale = (f32)FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    scale = width / scale;
    transformed.x = transformed.x * scale;
    transformed.y = transformed.y * scale;
    transformed.z = transformed.z * scale;
    start.x = position.x + transformed.x;
    start.y = position.y + transformed.y;
    start.z = position.z + transformed.z;
    scale = (f32)FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    scale = height / scale;
    output.x = direction.x * scale;
    output.y = direction.y * scale;
    output.z = direction.z * scale;
    end.x = position.x + output.x;
    end.y = position.y + output.y;
    end.z = position.z + output.z;
    FUN_002a4690(&endRot, &start, &position, D_00697880);
    FUN_002a4690(&blendRot, &end, &position, D_00697880);
    FUN_002a3e80(0.0f, (u8 *)action, 0, 0, 1);
    if (start.y < 25.0f) {
      start.y = 25.0f;
    }
    if (end.y < 25.0f) {
      end.y = 25.0f;
    }
    FUN_002a2290(camera, (f32 *)&start, (f32 *)&end, 1);
    FUN_002a3110(camera, 2.0f);
    return;
  }

  position.y = (position.y + 0.0f) -
               DAT_007cad20 * unit->unk_8c * unit->scale;
  index = (s32)FUN_002ffbc0_btlVoice_typed(2);
  voiceData = (u8 *)(*(u32 *)(DAT_007ce3ec + 0xb18) +
                     index * 0x34 + 0x1a4);
  if (usePreset != 0) {
    FUN_002a4690(&startRot, voiceData + 4, voiceData + 0x10,
                 D_00697880);
    start = *(RwV3d *)(voiceData + 4);
  } else {
    FUN_002a4470((f32 *)&start, (f32 *)&camera->pos);
  }
  FUN_002a4690(&endRot, &start, &position, D_00697880);
  end = start;
  FUN_004be310_btlVoice_typed((f32 *)&startRot, (f32 *)&endRot, blend);
  factorA = DAT_007cad7c;
  factorB = DAT_007cadd0;
  if (blend[9] == 0.0f) {
    tmp = DAT_007cad7c * blend[8];
    curve = tmp * tmp;
    poly = DAT_007cad34 * curve + DAT_007cad38 + 0.0f;
    poly = curve * poly + DAT_007cad3c + 0.0f;
    poly = curve * poly + DAT_007cad40 + 0.0f;
    poly = curve * poly + DAT_007cad44 + 0.0f;
    poly = curve * poly + DAT_007cad48 + 0.0f;
    factorA = curve * tmp;
    factorA = factorA * poly + tmp + 0.0f;
    tmp = DAT_007cadd0 * blend[8];
    curve = tmp * tmp;
    poly = DAT_007cad34 * curve + DAT_007cad38 + 0.0f;
    poly = curve * poly + DAT_007cad3c + 0.0f;
    poly = curve * poly + DAT_007cad40 + 0.0f;
    poly = curve * poly + DAT_007cad44 + 0.0f;
    poly = curve * poly + DAT_007cad48 + 0.0f;
    factorB = curve * tmp;
    factorB = factorB * poly + tmp + 0.0f;
  }
  blendRot.imag.x = blend[0] * factorA + blend[4] * factorB;
  blendRot.imag.y = blend[1] * factorA + blend[5] * factorB;
  blendRot.imag.z = blend[2] * factorA + blend[6] * factorB;
  if (usePreset != 0) {
    FUN_00351bb0_btlVoice_typed(8);
  }
  FUN_002a2290(camera, (f32 *)&start, (f32 *)&end, 1);
  FUN_002a3110(camera, 2.0f);
  return;
}

// FUN_002e58a0 NONMATCHING
void func_002e58a0(BtlCamera* param_1)

{
  u32 bVar1;
  char cVar2;
  u32 bVar3;
  int iVar4;
  u32 uVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  RwV3d specPos1;
  RtQuat specQuat1;
  RwV3d specPos2;
  RtQuat specQuat2;
  float targetXZ[2];
  float cameraXZ[2];
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  RwV3d camPos;
  RtQuat quatCopy;
  RwV3d finalPos;
  RtQuat quat;
  float normTmp[2];
  float d1Out[2];
  float partPos[2];
  RwV3d dir;
  RwV3d camOff;
  RwV3d target;
  RwV3d pos2;
  RwV3d pos1;
  float fStack_d8;
  float fStack_dc;

  iVar4 = *(int *)((int)param_1 + 0xe0);
  if ((iVar4 != 0) && (iVar8 = *(int *)(iVar4 + 0x30), *(char *)(iVar8 + 0xa2) == '\0')) {
    for (uVar6 = 0; iVar4 = *(int *)((int)param_1 + 0xe0), uVar6 < *(u16 *)(iVar4 + 0x6a);
        uVar6 = uVar6 + 1 & 0xffff) {
      iVar4 = *(int *)(*(int *)(iVar4 + uVar6 * 4 + 0x38) + 0x30);
      if (*(char *)(iVar4 + 0xa2) == '\x01') {
        FUN_0027fcf0(iVar4,iVar8 + 4);
      }
    }
  }
  if (iVar4 != 0) {
    if (*(char *)(*(int *)(iVar4 + 0x30) + 0xa2) == '\0') {
      if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1d) || (*(short *)(DAT_007ce3ec + 0x104) == 0x1c))
      {
        bVar3 = false;
        goto LAB_002e59dc;
      }
    }
    else if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1f) ||
            (*(short *)(DAT_007ce3ec + 0x104) == 0x12)) {
      bVar3 = false;
      goto LAB_002e59dc;
    }
    bVar3 = true;
  }
  else {
    bVar3 = true;
  }
LAB_002e59dc:
  iVar4 = *(int *)(iVar4 + 0x30);
  bVar1 = *(char *)(iVar4 + 0xa2) != '\0';
  if (bVar1) {
    iVar8 = *(int *)(*(int *)(*(int *)((int)param_1 + 0xe0) + 0x38) + 0x30);
    iVar7 = iVar4;
  }
  else {
    iVar7 = *(int *)(*(int *)(*(int *)((int)param_1 + 0xe0) + 0x38) + 0x30);
    iVar8 = iVar4;
  }
  cVar2 = *(char *)(iVar8 + 0xa2);
  if (cVar2 == *(char *)(iVar7 + 0xa2)) {
    if (cVar2 == '\0') {
      func_002e8e20();
    }
    else {
      func_002e8f40();
    }
    return;
  }
  if ((*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) && (cVar2 == '\0')) {
    FUN_002a4690(&specQuat1,&DAT_00697c84,&DAT_00697c90,D_00697880);
    specPos1.x = DAT_00697c84;
    specPos1.y = DAT_00697c88;
    specPos1.z = DAT_00697c8c;
    FUN_002a4690(&specQuat2,&DAT_00697c9c,&DAT_00697ca8,D_00697880);
    specPos2.x = DAT_00697c9c;
    specPos2.y = DAT_00697ca0;
    specPos2.z = DAT_00697ca4;
    fVar10 = (float)DAT_00697c80 / 30.0f;
    FUN_002a2290((void *)(DAT_007ce3ec + 0x20),(f32 *)&specPos1,(f32 *)&specPos2,1);
    FUN_002a3110((void *)(DAT_007ce3ec + 0x20),fVar10);
    return;
  }
  FUN_002a4470((f32 *)&camPos,(f32 *)&param_1->pos);
  FUN_00280050_btlVoice_typed((BtlUnit *)iVar8,&pos1);
  FUN_00280050_btlVoice_typed((BtlUnit *)iVar7,&pos2);
  fVar13 = *(float *)(iVar8 + 0x90) * *(float *)(iVar8 + 0x2c);
  fVar11 = *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x2c) * 0.5f + pos1.y + 0.0f;
  fVar12 = *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) * 0.5f + pos2.y + 0.0f;
  dir.x = pos1.x - pos2.x;
  dir.y = pos1.y - pos2.y;
  dir.z = pos1.z - pos2.z;
  fVar9 = (float)FUN_004c69f0(&dir,&dir);
  fVar9 = DAT_007cad84 * fVar9;
  target.x = dir.x * fVar9 + pos2.x;
  target.y = dir.y * fVar9 + pos2.y;
  target.z = dir.z * fVar9 + pos2.z;
  fStack_d8 = param_1->pos.x - target.x;
  fStack_dc = param_1->pos.z - target.z;
  FUN_004c6b20_btlVoice_typed(&fStack_d8,&fStack_d8);
  fStack_ac = -dir.x;
  fVar9 = dir.z * fStack_d8 + fStack_ac * fStack_dc;
  if (bVar1) {
    fVar10 = 2.5f;
  }
  else {
    fVar10 = 1.5f;
  }
  fVar10 = fVar10 * fVar13;
  if (0.0f <= fVar9) {
    camOff.x = dir.z * fVar10 + pos1.x + 0.0f;
    camOff.z = (pos1.z + 0.0f) - dir.x * fVar10;
  }
  else {
    camOff.x = (pos1.x + 0.0f) - dir.z * fVar10;
    camOff.z = dir.x * fVar10 + pos1.z + 0.0f;
  }
  camOff.y = fVar11;
  if (bVar1) {
    target.y = (target.y + 0.0f) - DAT_007cad84 * fVar12;
    fVar11 = 3.5f;
  }
  else {
    if (fVar11 >= fVar12) {
      target.y = DAT_007cad20 * fVar12 + target.y + 0.0f;
      camOff.y = (pos1.y + 0.0f) - DAT_007cad20 * fVar11;
    }
    else {
      target.y = (target.y + 0.0f) - DAT_007cad84 * fVar12;
    }
    fVar11 = 2.5f;
  }
  FUN_002a4690(&quat,&camOff,&target,D_00697880);
  FUN_004be1e0_btlVoice_typed(&dir,(const RwV3d *)&D_006978A0,1,&quat);
  targetXZ[0] = target.x;
  targetXZ[1] = target.z;
  cameraXZ[0] = camOff.x;
  cameraXZ[1] = camOff.z;
  partPos[0] = pos1.x;
  partPos[1] = pos1.z;
  fVar12 = (float)FUN_002d1fd0(targetXZ,cameraXZ,partPos,d1Out);
  camOff.x = d1Out[0];
  camOff.z = d1Out[1];
  fVar10 = (fVar12 + fVar11 * fVar13) / (float)FUN_0052e930(DAT_007cad60 * param_1->fovRad * 0.5f);
  dir.x = dir.x * fVar10;
  dir.y = dir.y * fVar10;
  dir.z = dir.z * fVar10;
  if (fVar9 < 0.0f) {
    fVar9 = fVar10 * (float)FUN_0052e930(DAT_007cad60 * param_1->fovRad * 0.5f) * 0.21875f * 1.25f;
    normTmp[0] = dir.x;
    normTmp[1] = dir.z;
    FUN_004c6b20_btlVoice_typed(normTmp,normTmp);
    camOff.x = normTmp[1] * fVar9 + camOff.x + 0.0f;
    camOff.z = (camOff.z + 0.0f) - normTmp[0] * fVar9;
  }
  finalPos.x = camOff.x + dir.x;
  finalPos.y = camOff.y + dir.y;
  finalPos.z = camOff.z + dir.z;
  if (finalPos.y < 25.0f) {
    finalPos.y = 25.0f;
  }
  fVar9 = FUN_002d1f30_btlVoice_typed((const f32 *)&quatCopy, (const f32 *)&quat);
  if (((!bVar1) || (DAT_007cad58 < fVar9)) && (bVar3)) {
    quatCopy = quat;
    FUN_004be1e0_btlVoice_typed(&dir,(const RwV3d *)&D_006978A0,1,&quat);
    fVar10 = fVar10 + 200.0f;
    dir.x = dir.x * fVar10;
    dir.y = dir.y * fVar10;
    dir.z = dir.z * fVar10;
    camPos.x = camOff.x + dir.x;
    camPos.y = camOff.y + dir.y;
    camPos.z = camOff.z + dir.z;
    if (camPos.y < 25.0f) {
      camPos.y = 25.0f;
    }
    FUN_00351bb0_btlVoice_typed(8);
  }
  FUN_002a2290((void *)param_1,(f32 *)&camPos,(f32 *)&finalPos,1);
  FUN_002a3110((void *)param_1,1.5f);
}

// FUN_002e6130 NONMATCHING
f32 func_002e6130(BtlUnit* param_1,BtlUnit* param_2,float* param_3,float* param_4)
{
  u16 sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  f32 fVar6;
  FUN_00280130(param_1,param_3);
  FUN_00280130(param_2,param_4);
  iVar5 = (int)param_1;
  iVar4 = (int)param_2;
  iVar2 = (int)param_4;
  iVar3 = (int)param_3;
  if ((*(u8 *)(iVar5 + 0xa2) == '\0') && (*(u8 *)(iVar4 + 0xa2) == '\1')) {
    sVar1 = *(u16 *)(iVar4 + 0xa4);
    switch (sVar1) {
    case 0x100:
      *(float *)(iVar3 + 4) =
           DAT_007cad20 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.125f;
      fVar6 = 4.5f;
      break;
    case 0x101:
    case 0x102:
      *(float *)(iVar3 + 4) =
           DAT_007cada4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad20 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
      break;
    case 0x103:
      *(float *)(iVar3 + 4) =
           DAT_007cad84 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cada4 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
      break;
    case 0x104:
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad80 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
      break;
    case 0x105:
      *(float *)(iVar3 + 4) =
           DAT_007cad78 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
      break;
    case 0x106:
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad78 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
      break;
    case 0x115:
      *(float *)(iVar3 + 4) =
           DAT_007cad88 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
      break;
    case 0x107:
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
      break;
    case 0x10a:
      *(float *)(iVar3 + 4) =
           DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
      break;
    case 0x10d:
      *(float *)(iVar3 + 4) =
           DAT_007cad78 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad20 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
      break;
    case 0x111:
    case 0x11a:
    case 0x11b:
    case 0x11c:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x128:
      *(float *)(iVar3 + 4) =
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.5f + *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadb8 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 6.0f;
      break;
    case 0xf1:
      *(float *)(iVar3 + 4) =
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.5f + *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadb8 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 6.0f;
      break;
    default:
      *(float *)(iVar3 + 4) =
           DAT_007cad20 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadbc * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
      break;
    }
  }
  else if ((*(u8 *)(iVar5 + 0xa2) == '\1') && (*(u8 *)(iVar4 + 0xa2) == '\0')) {
    switch(*(u16 *)(iVar5 + 0xa4)) {
    case 0x101:
    case 0x102:
      *(float *)(iVar3 + 4) =
           DAT_007cad5c * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.5f + *(float *)(iVar2 + 4) + 0.0f;
      fVar6 = 5.5f;
      break;
    case 0x103:
      *(float *)(iVar3 + 4) =
           (*(float *)(iVar3 + 4) + 0.0f) -
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.25f;
      *(float *)(iVar2 + 4) =
           DAT_007cadb4 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) +
           *(float *)(iVar2 + 4) + 0.0f;
      fVar6 = 5.5f;
      break;
    case 0x104:
      *(float *)(iVar3 + 4) =
           (*(float *)(iVar3 + 4) + 0.0f) - *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.5f
      ;
      *(float *)(iVar2 + 4) = 170.0f;
      fVar6 = 6.5f;
      break;
    case 0x105:
      *(float *)(iVar3 + 4) =
           (*(float *)(iVar3 + 4) + 0.0f) -
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.25f;
      *(float *)(iVar2 + 4) =
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.5f + *(float *)(iVar2 + 4) + 0.0f;
      fVar6 = 6.0f;
      break;
    default:
      *(float *)(iVar3 + 4) =
           DAT_007cad5c * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.5f + *(float *)(iVar2 + 4) + 0.0f;
      fVar6 = 5.5f;
      break;
    case 0x107:
      *(float *)(iVar3 + 4) =
           (*(float *)(iVar3 + 4) + 0.0f) -
           DAT_007cad20 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c);
      *(float *)(iVar2 + 4) =
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.25f + *(float *)(iVar2 + 4) + 0.0f;
      fVar6 = 6.0f;
      break;
    case 0x10a:
      *(float *)(iVar3 + 4) =
           (*(float *)(iVar3 + 4) + 0.0f) -
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.25f;
      *(float *)(iVar2 + 4) = 170.0f;
      fVar6 = 6.0f;
    }
  }
  else {
    fVar6 = 4.5f;
  }
  return fVar6;
}

typedef struct
{
  RwV3d pos;
  RtQuat rot;
} BtlVoicePose6a20;

#pragma alias FUN_002d1de0_6a20 FUN_002d1de0
extern void FUN_002d1de0_6a20(RtQuat* out, const RwV3d* from,
                              const RwV3d* to);
#pragma alias FUN_002a4690_6a20 FUN_002a4690
extern void FUN_002a4690_6a20(RtQuat* out, const RwV3d* from,
                              const RwV3d* to, const RwV3d* config);
#pragma alias FUN_004be1e0_6a20 FUN_004be1e0
extern void FUN_004be1e0_6a20(RwV3d* out, const RwV3d* basis, s32 count,
                              const RtQuat* source);
#pragma alias FUN_004c6b20_6a20 FUN_004c6b20
extern void FUN_004c6b20_6a20(f32* out, const f32* in);
#pragma alias FUN_004c69f0_6a20 FUN_004c69f0
extern f32 FUN_004c69f0_6a20(RwV3d* out, const RwV3d* in);
#pragma alias FUN_002d1f30_6a20 FUN_002d1f30
extern f32 FUN_002d1f30_6a20(const RtQuat* first, const RtQuat* second);
#pragma alias FUN_0052e930_6a20 FUN_0052e930
extern f32 FUN_0052e930_6a20(f32 angle);
#pragma alias FUN_002a44f0_6a20 FUN_002a44f0
extern void FUN_002a44f0_6a20(f32* first, f32* second);
#pragma alias FUN_002a4470_6a20 FUN_002a4470
extern void FUN_002a4470_6a20(f32* dst, f32* src);

/* Retail 0x00-0x67f: reconstruct the paired-unit quaternion, projection, and playback paths; 1644/1680 bytes emitted, with no unjustified bytes. */
// FUN_002e6a20 NONMATCHING
void func_002e6a20(BtlCamera* camera, float weight)
{
  typedef struct
  {
    RwV3d first;
    RwV3d second;
    RwV3d rotated;
    RwV3d delta;
    RwV3d lateral;
    RwV3d base;
    RwV3d camera;
    RwV3d target;
    BtlVoicePose6a20 pose;
    RtQuat rotation;
    RtQuat aim;
    f32 viewXZ[2];
    f32 fromXZ[2];
    f32 toXZ[2];
    f32 eyeXZ[2];
    f32 projected[2];
    f32 firstRadius;
    f32 secondRadius;
    f32 distance;
    f32 scale;
    f32 projection;
    f32 fovScale;
    f32 sideDot;
    f32 quatDot;
    f32 temp0;
    f32 temp1;
    f32 temp2;
    f32 temp3;
  } VoiceWork;
  VoiceWork work;
  BtlUnit* firstUnit;
  BtlUnit* secondUnit;
  BtlUnit* selectedUnit;
  u32 mode;

  firstUnit = camera->action->unit;
  secondUnit = camera->action->target.targetedActions[0]->unit;
  work.distance = func_002e6130(firstUnit, secondUnit,
                                (f32*)&work.first, (f32*)&work.second);
  work.firstRadius = firstUnit->sphereRadius * firstUnit->scale;
  work.secondRadius = secondUnit->sphereRadius * secondUnit->scale;
  work.viewXZ[0] = camera->pos.x - work.first.x;
  work.viewXZ[1] = camera->pos.z - work.first.z;
  FUN_004c6b20_6a20(work.viewXZ, work.viewXZ);

  if (firstUnit->genus == 0) {
    FUN_002d1de0_6a20(&work.rotation, &work.first, &work.second);
    FUN_004be1e0_6a20(&work.rotated, D_006978A0_abs,
                      1, &work.rotation);
    work.rotated.x = work.rotated.x * work.secondRadius;
    work.rotated.y = work.rotated.y * work.secondRadius;
    work.rotated.z = work.rotated.z * work.secondRadius;
    work.second.x = work.second.x + work.rotated.x;
    work.second.y = work.second.y + work.rotated.y;
    work.second.z = work.second.z + work.rotated.z;
    work.delta.x = work.first.x - work.second.x;
    work.delta.y = work.first.y - work.second.y;
    work.delta.z = work.first.z - work.second.z;
    work.base = work.first;
    work.scale = firstUnit->sphereRadius * firstUnit->scale * 1.25f;
    work.temp0 = work.secondRadius;
    selectedUnit = secondUnit;
  }
  else {
    FUN_002d1de0_6a20(&work.rotation, &work.second, &work.first);
    FUN_004be1e0_6a20(&work.rotated, D_006978A0_abs,
                      1, &work.rotation);
    work.rotated.x = work.rotated.x * work.firstRadius;
    work.rotated.y = work.rotated.y * work.firstRadius;
    work.rotated.z = work.rotated.z * work.firstRadius;
    work.first.x = work.first.x + work.rotated.x;
    work.first.y = work.first.y + work.rotated.y;
    work.first.z = work.first.z + work.rotated.z;
    work.delta.x = work.first.x - work.second.x;
    work.delta.y = work.first.y - work.second.y;
    work.delta.z = work.first.z - work.second.z;
    work.base = work.second;
    work.scale = secondUnit->sphereRadius * secondUnit->scale * 0.5f;
    work.temp0 = work.firstRadius;
    selectedUnit = firstUnit;
  }

  work.scale = work.scale * DAT_007cad88;
  FUN_004c69f0_6a20(&work.delta, &work.delta);
  work.delta.x = work.delta.x * work.scale;
  work.delta.y = work.delta.y * work.scale;
  work.delta.z = work.delta.z * work.scale;
  work.base.x = work.base.x + work.delta.x;
  work.base.y = work.base.y + work.delta.y;
  work.base.z = work.base.z + work.delta.z;
  work.lateral.x = work.delta.z;
  work.lateral.y = 0.0f;
  work.lateral.z = -work.delta.x;
  work.sideDot = work.lateral.x * work.viewXZ[0] +
                 work.lateral.z * work.viewXZ[1];
  if (work.sideDot >= 0.0f) {
    work.camera.x = work.base.x + work.lateral.x * work.temp0;
    work.camera.z = work.base.z - work.lateral.z * work.temp0;
  }
  else {
    work.camera.x = work.base.x - work.lateral.x * work.temp0;
    work.camera.z = work.base.z + work.lateral.z * work.temp0;
  }
  work.camera.y = work.base.y;

  FUN_002a4690_6a20(&work.aim, &work.camera, &work.base,
                    (const RwV3d*)D_00697880);
  FUN_004be1e0_6a20(&work.rotated, D_006978A0_abs,
                    1, &work.aim);
  work.fromXZ[0] = work.base.x;
  work.fromXZ[1] = work.base.z;
  work.toXZ[0] = work.camera.x;
  work.toXZ[1] = work.camera.z;
  work.eyeXZ[0] = work.second.x;
  work.eyeXZ[1] = work.second.z;
  work.projected[0] = work.rotated.x;
  work.projected[1] = work.rotated.z;
  work.projection = FUN_002d1fd0(work.fromXZ, work.toXZ, work.eyeXZ,
                                  work.projected);
  work.fovScale = FUN_0052e930_6a20(DAT_007cad60 * camera->fovRad * 0.5f);
  work.temp1 = work.distance * (selectedUnit->sphereRadius *
                                selectedUnit->scale) +
              work.temp0;
  work.projection = work.temp1 / work.fovScale;
  work.scale = 100.0f;
  if (100.0f <= work.projection) {
    work.scale = work.projection;
  }
  work.delta.x = work.rotated.x * work.scale;
  work.delta.y = work.projected[0] * work.scale;
  work.delta.z = work.rotated.z * work.scale;
  work.target.x = work.camera.x + work.delta.x;
  work.target.y = work.camera.y + work.delta.y;
  work.target.z = work.camera.z + work.delta.z;
  if (work.target.y < 22.5f) {
    work.target.y = 22.5f;
  }

  FUN_002a4470_6a20((f32*)&work.pose, (f32*)&camera->pos);
  work.quatDot = FUN_002d1f30_6a20(&work.pose.rot, &work.aim);
  if (DAT_007cadc4 >= work.quatDot) {
    mode = 0x33;
  }
  else {
    FUN_002a44f0_6a20((f32*)&work.pose.pos, (f32*)&work.target);
    mode = 3;
  }
  FUN_002a3e80(50.0f, (u8*)camera->action, (u8*)&selectedUnit->pos,
               (u8*)&work.target, mode);

  if (weight != 0.0f) {
    work.temp3 = weight;
    FUN_002a2290(camera, (f32*)&work.pose.pos, (f32*)&work.target, 1);
    FUN_002a3110(camera, work.temp3);
  }
  else {
    FUN_002a44f0_6a20((f32*)&work.pose.pos, (f32*)&work.target);
    FUN_004be1e0_6a20(&work.rotated,
                      D_006978A0_abs, 1,
                      &work.pose.rot);
    work.rotated.x = work.rotated.x * 150.0f;
    work.rotated.y = work.rotated.y * 150.0f;
    work.rotated.z = work.rotated.z * 150.0f;
    work.target.x = work.pose.pos.x + work.rotated.x;
    work.target.y = work.pose.pos.y + work.rotated.y;
    work.target.z = work.pose.pos.z + work.rotated.z;
    if (work.target.y < 22.5f) {
      work.target.y = 22.5f;
    }
    work.temp2 = 2.0f;
    FUN_002a2290(camera, (f32*)&work.pose.pos, (f32*)&work.target, 1);
    FUN_002a3110(camera, work.temp2);
  }
}
// FUN_002e70b0
void func_002e70b0(BtlCamera* camera)

{
  BtlUnit* unit;
  u16 targetMask;
  
  *(u16 *)(DAT_007ce3ec + 0xb78) = 0;
  unit = camera->action->unit;
  targetMask = FUN_002d1600(&camera->action->target);
  if (unit->genus == 0) {
    if ((targetMask & 1) == 0) {
      if (FUN_002d5e10(camera->action) == 0) {
        func_002e6a20(camera,1.0f);
      }
    }
    else {
      FUN_002af960(camera);
      *(u16 *)(DAT_007ce3ec + 0xb78) = 1;
    }
  }
  else if ((targetMask & 2) == 0) {
    if (FUN_0030c3a0(unit->datUnit) != 0) {
      func_002e6a20(camera,1.0f);
    }
    else {
      FUN_002af960(camera);
      *(u16 *)(DAT_007ce3ec + 0xb78) = 1;
    }
  }
  return;
}

// FUN_002e71c0
void func_002e71c0(int param_1)

{

  if ((*(int *)(param_1 + 0xe0) != 0) &&
      ((*(u16 *)(*(int *)(param_1 + 0xe0) + 0x1a) & 1) != 0)) {
    if (*(u16 *)(DAT_007ce3ec + 0xb78) == 1) {
      FUN_002b0210(param_1);
    }
  }
  return;
}

// FUN_002e7210 MATCHING
void func_002e7210(BtlCamera* camera)
{
    BtlUnit* unit;
    BtlUnit* targetUnit;
    u16 index;

    if ((camera->action != NULL) && ((camera->action->unk_1a & 1) != 0)) {
        if (camera->action != NULL) {
            unit = camera->action->unit;
            if (unit->genus == 0) {
                for (index = 0; index < camera->action->target.targetedCount; index++) {
                    targetUnit = ((BtlAction *)camera->action)->target.targetedActions[index]->unit;
                    if (targetUnit->genus == 1) {
                        FUN_0027fcf0(targetUnit, &unit->pos);
                    }
                }
            }
        }
        if (camera->action->unit->genus == 0) {
            FUN_002b0280(0.0f, camera, 0, 1);
        } else {
            FUN_002b0280(0.0f, camera, 1, 0);
        }
    }
    return;
}

// FUN_002e7320 MATCHING
void func_002e7320(void)
{
    return;
}


// FUN_002e7330 NONMATCHING
void func_002e7330(int param_1)

{
  int iVar1;
  char cVar2;
  u16 uVar3;
  u32 uVar4;
  s32 lVar5;
  u16 uVar6;
  int iVar7;
  u8 *unaff_s1_lo;
  
  iVar7 = param_1;
  lVar5 = FUN_002f8a40(*(u32 *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x38) + 0x30));
  if (lVar5 == 0) {
    FUN_002b1e00(param_1);
  }
  else {
    *(u32 *)(iVar7 + 0x100) = *(u32 *)(*(int *)(iVar7 + 0xe0) + 0x38);
    iVar1 = *(int *)(*(int *)(iVar7 + 0xe0) + 0x30);
    if (*(char *)(iVar1 + 0xa2) != '\0') {
      return;
    }
    lVar5 = FUN_002d5bf0(iVar1);
    if (lVar5 != 0) {
      uVar3 = 3;
    }
    else {
      uVar3 = *(u16 *)(iVar1 + 0xa4);
    }
    switch(uVar3) {
    case 1:
      uVar4 = FUN_00308c60(*(u32 *)(iVar1 + 0xa2c));
      unaff_s1_lo = voiceCameraPathsPlayer + (uVar4 & 0xff) * 0xf4;
      break;
    case 2:
      unaff_s1_lo = voiceCameraPathType2;
      break;
    case 3:
      cVar2 = FUN_003093a0(*(u32 *)(iVar1 + 0xa2c));
      if (cVar2 == '\x03') {
        unaff_s1_lo = voiceCameraPathType3_3;
      }
      else if (cVar2 == '\x02') {
        if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4) {
          unaff_s1_lo = voiceCameraPathType3_2;
        }
        else {
          unaff_s1_lo = voiceCameraPathType3_2Special;
        }
      }
      else if (cVar2 == '\x01') {
        unaff_s1_lo = voiceCameraPathType3_1;
      }
      break;
    case 4:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4) {
        unaff_s1_lo = voiceCameraPathType4;
      }
      else {
        unaff_s1_lo = voiceCameraPathType4Special;
      }
      break;
    case 5:
      unaff_s1_lo = voiceCameraPathType5;
      break;
    case 7:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4) {
        unaff_s1_lo = voiceCameraPathType7;
      }
      else {
        unaff_s1_lo = voiceCameraPathType7Special;
      }
      break;
    case 8:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4) {
        unaff_s1_lo = voiceCameraPathType8;
      }
      else {
        unaff_s1_lo = voiceCameraPathType8Special;
      }
      break;
    case 9:
      unaff_s1_lo = voiceCameraPathType9;
      break;
    case 10:
      unaff_s1_lo = DAT_00698d40;
    }
    if (FUN_002fdfa0(iVar1) != 0) {
      uVar6 = 5;
    }
    else {
      uVar6 = 9;
    }
    FUN_002b6bf0(iVar7 + 0xec,*(int *)(iVar7 + 0xe0),*(u32 *)(*(int *)(iVar7 + 0xe0) + 0x38),
                 unaff_s1_lo,uVar6);
  }
  lVar5 = FUN_002b6cd0(iVar7 + 0xec);
  if (lVar5 != 0) {
    if (*(short *)((int)lVar5 + 0x1c) == 1) {
      FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(u32 *)(iVar7 + 0xe0), 0, 0, 1);
      *(u32 *)(iVar7 + 0x110) = 1;
    }
    else {
      FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(u32 *)(iVar7 + 0xe0), 0, 0, 3);
      *(u32 *)(iVar7 + 0x110) = 0;
    }
  }
  *(u32 *)(iVar7 + 0x114) = 1;
  return;
}

// FUN_002e7680
void func_002e7680(void)

{
  FUN_002b2060();
  return;
}

// FUN_002e76a0
void func_002e76a0(BtlCamera* camera)
{
  BtlAction* action;
  BtlUnit* unit;

  action = camera->action;
  if (action != NULL) {
    *(u32 *)(DAT_007ce3ec + 0xb74) = (u32)action->target.targetedActions[0];
    unit = camera->action->unit;
    if (FUN_0030c3a0(unit->datUnit) == 0) {
      FUN_002b2800(camera);
    }
  }
}

// FUN_002e7710
void func_002e7710(BtlCamera* camera)
{
  BtlAction* action;
  BtlUnit* unit;

  action = camera->action;
  if ((action != NULL) && ((action->unk_1a & 1) != 0)) {
    unit = action->unit;
    if (FUN_0030c3a0(unit->datUnit) != 0) {
      action = camera->action;
      if ((action->target.targetedCount == 1) &&
          (*(BtlAction**)(DAT_007ce3ec + 0xb74) == action->target.targetedActions[0])) {
        func_002e6a20(camera,DAT_007cad50);
      }
    }
    else {
      FUN_002b2880(camera);
    }
  }
}

// FUN_002e77c0
void func_002e77c0(BtlCamera* camera)

{
  BtlAction* action;
  
  action = camera->action;
  if (((action != NULL) && ((action->unk_1a & 1) != 0)) &&
     (action->unit->genus != 0)) {
    func_002e70b0(camera);
  }
  return;
}

// FUN_002e7810
void func_002e7810(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xe0);
  if ((((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) &&
      (*(u8 *)(*(int *)(iVar1 + 0x30) + 0xa2) != '\0')) &&
     (((iVar1 != 0 && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) &&
      (*(u16 *)(DAT_007ce3ec + 0xb78) == 1)))) {
    FUN_002b0210(param_1);
  }
  return;
}

// FUN_002e7880
void func_002e7880(void)
{
}
typedef struct
{
  u8 pad_00[0xe0];
  BtlAction *action;
  u8 pad_e4[0x2c];
  u16 mode;
  u8 pad_112[0xe];
  BtlUnit *unit;
  u16 unk_124;
} BtlVoiceCameraWork;
#pragma alias FUN_002a3e80_short FUN_002a3e80
extern void FUN_002a3e80_short(f32 param_1, u8 *param_2,
                               u8 *param_3, u32 param_4);


static inline void btlVoicePlayCameraVoice(u8 *voiceData,
                                           f32 *startTransform,
                                           f32 *endTransform,
                                           RwV3d *startPosition,
                                           RwV3d *endPosition)
{
  f32 duration;

  FUN_002a4690(startTransform, voiceData + 4, voiceData + 0x10,
               D_00697880);
  *startPosition = *(RwV3d *)(voiceData + 4);
  FUN_002a4690(endTransform, voiceData + 0x1c, voiceData + 0x28,
               D_00697880);
  *endPosition = *(RwV3d *)(voiceData + 0x1c);
  duration = (f32)*(s16 *)voiceData / 30.0f;
  FUN_002a2290((u8 *)DAT_007ce3ec + 0x20,
               (f32 *)startPosition, (f32 *)endPosition, 1);
  FUN_002a3110((u8 *)DAT_007ce3ec + 0x20, duration);
}

/* W212: matched 002e82b0's per-branch playback aggregates plus the retail u32 pointer contract improve nd912/1272 to nd848/1268 (window 1312); residual begins at frame 0xd0 versus retail 0x120. */
// FUN_002e7890 NONMATCHING
void func_002e7890(u32 param_1)
{
  typedef struct {
    RwV3d startPosition;
    f32 startTransform[4];
    RwV3d endPosition;
    f32 endTransform[4];
  } BtlVoicePlayback;
  BtlVoiceCameraWork *work;
  BtlAction *action;
  BtlUnit *unit;
  BtlUnit *persona;
  u16 index;
  u16 mode;
  u8 color[4];
  u8 *base;
  u8 *voiceData;
  s8 voiceType;
  u32 isSpecial;
  u32 randomIndex;

  work = (BtlVoiceCameraWork *)(uintptr_t)param_1;
  action = work->action;
  unit = action->unit;
  persona = unit->personaUnit;

  if ((action != NULL) && (unit->genus == 0)) {
    for (index = 0; index < action->target.targetedCount; index++) {
      BtlUnit *targetUnit = action->target.targetedActions[index]->unit;
      if (targetUnit->genus == 1)
        FUN_0027fcf0(targetUnit, &unit->pos);
    }
  }

  mode = (u16)FUN_002a7830(work);
  work->mode = mode;
  isSpecial = 0;
  if (persona != NULL)
    isSpecial = (u32)FUN_002fdbb0(unit, persona);

  if ((isSpecial != 0) && (mode != 1)) {
    FUN_00287510(persona);
    color[0] = ((u8 *)persona)[0x30];
    color[1] = ((u8 *)persona)[0x31];
    color[2] = ((u8 *)persona)[0x32];
    color[3] = 0;
    FUN_0027f730(persona, *(u32 *)color);
  }
  FUN_002880e0((u32)(uintptr_t)persona, 0);
  base = (u8 *)(uintptr_t)(*(u32 *)((u8 *)DAT_007ce3ec + 0xb18));

  switch (mode) {
  case 0:
  case 1:
  case 2:
  case 4:
    FUN_002ac540(work);
    action = work->action;
    if ((action->target.targetedCount == 1) &&
        (action != action->target.targetedActions[0]) &&
        (action->target.targetedActions[0]->unit->genus == 0)) {
      FUN_002a3e80_short(0.0f, 0, 0, 8);
    }
    break;
  case 3:
  case 5:
    {
    BtlVoicePlayback playbackA;
    randomIndex = FUN_002ffbc0(2);
    voiceType = unit->unk_9f0;
    voiceData = base + (voiceType * 0x68) +
                ((randomIndex & 0xffff) * 0x34) + 4;
    btlVoicePlayCameraVoice(voiceData, playbackA.startTransform,
                            playbackA.endTransform, &playbackA.startPosition,
                            &playbackA.endPosition);
    FUN_002a3e80(0.0f, (u8 *)work->action, 0, 0, 0x40);
    break;
    }
  case 6:
    action = work->action;
    if ((action->unk_1a & 1) == 0)
      break;
    if (unit->genus == 0) {
      BtlVoicePlayback playbackB;
      voiceData = base + 0x3ac + 4;
      btlVoicePlayCameraVoice(voiceData, playbackB.startTransform,
                              playbackB.endTransform, &playbackB.startPosition,
                              &playbackB.endPosition);
    }
    else {
      BtlVoicePlayback playbackC;
      randomIndex = FUN_002ffbc0(2);
      voiceData = base + ((randomIndex & 0xffff) * 0x34) + 0x20c + 4;
      btlVoicePlayCameraVoice(voiceData, playbackC.startTransform,
                              playbackC.endTransform, &playbackC.startPosition,
                              &playbackC.endPosition);
    }
    FUN_002a3e80(0.0f, (u8 *)work->action, 0, 0, 0x40);
    break;
  }
}


/* W212: template 002f6510 confirms aggregate-based camera math, but this target remains an incomplete reconstruction at nd865/1156 (window 1280); residual begins at frame 0xf0 versus retail 0x130 and retail has 124 bytes of real tail code, so no honest local transfer was kept. */
// FUN_002e7db0 NONMATCHING
void func_002e7db0(BtlCamera* param_1)

{
  int iVar1;
  int iVar2;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  RwV3d nearPt;
  RtQuat quat;
  RwV3d farPt;
  RtQuat quatCopy;
  float fStack_90;
  float fStack_94;
  float fStack_98;
  float fStack_9c;
  float fStack_a0;
  float fStack_a4;
  float fStack_a8;
  float fStack_ac;
  float fStack_b0;
  float fStack_b4;
  float fStack_b8;
  float fStack_bc;
  RwV3d dirCopy;
  RwV3d camOff;
  RwV3d dir;
  RwV3d target;
  RwV3d sphere2Copy;
  RwV3d sphere2;
  RwV3d sphere1;

  iVar1 = *(int *)(*(int *)((int)param_1 + 0xe0) + 0x30);
  iVar2 = *(int *)(*(int *)(*(int *)((int)param_1 + 0xe0) + 0x38) + 0x30);
  FUN_0027ffb0_btlVoice_typed((BtlUnit *)iVar1,&sphere1);
  FUN_0027ffb0_btlVoice_typed((BtlUnit *)iVar2,&sphere2);
  fVar5 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
  if (450.0f <= fVar5 * 0.5f + sphere1.y + 0.0f) {
    sphere1.y = (sphere1.y + 0.0f) - DAT_007cad20 * fVar5;
  }
  dir.x = sphere1.x - sphere2.x;
  dir.y = sphere1.y - sphere2.y;
  dir.z = sphere1.z - sphere2.z;
  fVar5 = (float)FUN_004c69f0(&dir,&dir);
  fStack_98 = param_1->pos.x - sphere1.x;
  fStack_9c = param_1->pos.z - sphere1.z;
  FUN_004c6b20_btlVoice_typed(&fStack_98,&fStack_98);
  fVar5 = DAT_007cad88 * fVar5;
  target.x = dir.x * fVar5 + sphere2.x;
  target.y = dir.y * fVar5 + sphere2.y;
  target.z = dir.z * fVar5 + sphere2.z;
  fStack_90 = dir.x;
  fStack_94 = dir.z;
  sphere2Copy.x = sphere2.x;
  sphere2Copy.y = sphere2.y;
  sphere2Copy.z = sphere2.z;
  fVar5 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 1.5f;
  fStack_90 = dir.z;
  fStack_94 = -dir.x;
  fVar7 = fStack_90 * fStack_98 + fStack_94 * fStack_9c;
  camOff.y = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25f + sphere2.y + 0.0f;
  if (0.0f <= fVar7) {
    camOff.x = fStack_90 * fVar5 + sphere2.x + 0.0f;
    camOff.z = (sphere2.z + 0.0f) - dir.x * fVar5;
  }
  else {
    camOff.x = (sphere2.x + 0.0f) - fStack_90 * fVar5;
    camOff.z = dir.x * fVar5 + sphere2.z + 0.0f;
  }
  dirCopy.x = dir.x;
  dirCopy.y = dir.y;
  dirCopy.z = dir.z;
  FUN_002a4690(&quat,&camOff,&target,D_00697880);
  FUN_004be1e0_btlVoice_typed(&dir,(const RwV3d *)&D_006978A0,1,&quat);
  fStack_a0 = target.x;
  fStack_a4 = target.z;
  fStack_a8 = camOff.x;
  fStack_ac = camOff.z;
  fStack_b8 = sphere2Copy.x;
  fStack_bc = sphere2Copy.z;
  FUN_002d1fd0(&fStack_a0,&fStack_a8,&fStack_b8,&fStack_b0);
  fVar6 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 3.5f + fVar5 + 0.0f;
  camOff.x = fStack_b0;
  camOff.y = sphere2Copy.y;
  camOff.z = fStack_b4;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * param_1->fovRad * 0.5f);
  fVar5 = 500.0f;
  if (500.0f <= fVar6 / fVar4) {
    fVar5 = fVar6 / fVar4;
  }
  fVar4 = fVar5 - 15.0f;
  if (0.0f <= fVar7) {
    fVar7 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
    camOff.x = (camOff.x + 0.0f) - dirCopy.z * fVar7;
    camOff.z = dirCopy.x * fVar7 + camOff.z + 0.0f;
  }
  camOff.y = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25f + sphere2.y + 0.0f;
  nearPt.x = camOff.x + dir.x * fVar4;
  nearPt.y = camOff.y + dir.y * fVar4;
  nearPt.z = camOff.z + dir.z * fVar4;
  quatCopy.imag.x = quat.imag.x;
  quatCopy.imag.y = quat.imag.y;
  quatCopy.imag.z = quat.imag.z;
  quatCopy.real = quat.real;
  fVar5 = fVar5 + 85.0f;
  farPt.x = dir.x * fVar5 + camOff.x + 0.0f;
  farPt.y = dir.y * fVar5 + camOff.y + 0.0f;
  farPt.z = dir.z * fVar5 + camOff.z + 0.0f;
  if (nearPt.y < 25.0f) {
    nearPt.y = 25.0f;
  }
  if (farPt.y < 25.0f) {
    farPt.y = 25.0f;
  }
  FUN_002a3e80(50.0f,(u8 *)param_1->action,(u8 *)(iVar1 + 4),(u8 *)(iVar2 + 4),3);
  FUN_002a2290((void *)param_1,(f32 *)&nearPt,(f32 *)&farPt,1);
  FUN_002a3110((void *)param_1,2.0f);
}

/* Retail reconstruction: action/mode dispatch 0x2e82d0-0x2e8464; playback A 0x2e8470-0x2e8584; playback B/C 0x2e8590-0x2e8784. Every added statement maps to these retail ranges; unjustified bytes: 0. */
// FUN_002e82b0
void func_002e82b0(BtlCamera* camera)
{
  typedef struct {
    RwV3d startPosition;
    f32 startTransform[4];
    RwV3d endPosition;
    f32 endTransform[4];
  } BtlVoicePlayback;
  BtlVoiceCameraWork* work;
  u16 modeFlags;

  work = (BtlVoiceCameraWork*)camera;
  work->mode = (u16)FUN_002a7830();
  modeFlags = (u16)FUN_002d1600((u8*)work->action + 0x38);
  work->unit = NULL;
  if ((work->action->unk_1a & 0x10) != 0) {
    switch (work->action->unit->charId) {
    case 0xe9:
    case 0xea:
    case 0xeb:
    case 0xec:
    case 0xed:
    case 0xee:
    case 0xef:
    case 0xf0:
      FUN_002880e0((u32)(uintptr_t)work->action->unit->personaUnit, 0);
      work->unit = work->action->unit->personaUnit;
      work->unk_124 = 1;
      break;
    default:
      FUN_002880e0((u32)(uintptr_t)work->action->unit->personaUnit, 1);
    }
  }

  switch (work->mode) {
  case 1:
    if ((work->action->unk_1a & 0x10) == 0) {
      func_002e4a40_camera(camera);
    }
    else {
      FUN_002ac540(camera);
    }
    break;
  case 2:
    if ((modeFlags & 2) == 0) {
      func_002e7db0(camera);
      return;
    }
  case 4:
    if ((modeFlags & 2) == 0) {
      if ((FUN_0030c3a0(work->action->unit->datUnit) != 0) &&
          (FUN_00289f40(work->action) != 0)) {
        func_002e6a20(camera, 0.75f);
      }
      else {
        func_002e7db0(camera);
      }
      break;
    }
  case 3:
  case 5:
    if ((modeFlags & 2) != 0) {
      BtlVoicePlayback playbackA;
      u32 randomIndex;
      u8* voiceData;
      u8* voiceBase;

      randomIndex = (u16)FUN_002ffbc0(2);
      voiceBase = (u8 *)(*(int *)(iGpffffb6fc + 0xb18));
      randomIndex = randomIndex * 0x34;
      voiceData = voiceBase + randomIndex + 0x1a4;
      btlVoicePlayCameraVoice(voiceData, playbackA.startTransform,
                              playbackA.endTransform, &playbackA.startPosition,
                              &playbackA.endPosition);
      FUN_002a3e80(0.0f, (u8*)work->action, 0, 0, 0x40);
      break;
    }
    goto cameraVoiceState6;
  case 6:
cameraVoiceState6:
    if ((work->action->unk_1a & 1) != 0) {
      if (((u8*)work->action->unit)[0xa2] == 0) {
        BtlVoicePlayback playbackB;
        u8* voiceData;

        voiceData = (u8*)(uintptr_t)(*(u32*)((u8*)DAT_007ce3ec + 0xb18)) +
                    0x3ac;
        btlVoicePlayCameraVoice(voiceData, playbackB.startTransform,
                                playbackB.endTransform,
                                &playbackB.startPosition,
                                &playbackB.endPosition);
      }
      else {
        BtlVoicePlayback playbackC;
        u32 randomIndex;
        u8* voiceData;
        u8* voiceBase;

        randomIndex = (u16)FUN_002ffbc0(2);
        voiceBase = (u8 *)(*(int *)(iGpffffb6fc + 0xb18));
        randomIndex = randomIndex * 0x34;
        voiceData = voiceBase + randomIndex + 0x20c;
        btlVoicePlayCameraVoice(voiceData, playbackC.startTransform,
                                playbackC.endTransform,
                                &playbackC.startPosition,
                                &playbackC.endPosition);
      }
      FUN_002a3e80(0.0f, (u8*)work->action, 0, 0, 0x40);
    }
    break;
  }
}

// FUN_002e87b0
void func_002e87b0(BtlCamera* camera)
{
    typedef struct CameraVoiceWork
    {
        u8 pad_00[0xe0];
        BtlAction* action;
        u8 pad_e4[0x3c];
        u32 unit;
        u16 mode;
    } CameraVoiceWork;
    CameraVoiceWork* work;

    work = (CameraVoiceWork*)camera;
    if (work->unit != 0 &&
        work->action != NULL &&
        (work->action->unk_1a & 1) != 0 &&
        FUN_002a3750(camera, work->unit) != 0)
    {
        FUN_002880e0(work->unit, work->mode);
    }
}

// FUN_002e8820
void func_002e8820(BtlCamera *camera)
{
    struct {
        f32 start[7];
        VoiceVector position;
        f32 end[6];
    } work;
    BtlUnit *unit;
    f32 *voiceData;
    u16 voiceVariant;
    u32 useCurrentPosition;
    u16 mode;

    mode = *(u16 *)(iGpffffb6fc + 0x104);
    switch (mode) {
    case 0x1d:
    case 0x22:
    case 2:
        useCurrentPosition = 0;
        break;
    default:
        useCurrentPosition = 1;
        break;
    }

    voiceVariant = FUN_002f88c0();
    for (unit = *(BtlUnit **)(iGpffffb6fc + 0x158); unit != 0; unit = unit->next) {
        if ((unit->flags3 & 8) != 0 && unit->datUnit != 0 &&
            FUN_00300580(unit->datUnit, 0x100000) != 0) {
            break;
        }
    }

    FUN_002a4470(work.start, (f32 *)&camera->pos);
    if (unit == 0) {
        voiceData = (f32 *)(*(int *)(iGpffffb6fc + 0xb18) +
                            voiceVariant * 0x18 + 0x274);
        FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
        work.position = *(VoiceVector *)voiceData;
    } else {
        voiceData = (f32 *)(*(int *)(iGpffffb6fc + 0xb18) +
                            voiceVariant * 0x18 + 0x2a4);
        FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
        work.position = *(VoiceVector *)voiceData;
    }

    if (useCurrentPosition) {
        FUN_00351bb0(8);
        FUN_002a3e80(0.0f, (u8 *)camera->action, 0, 0, 0x40);
        FUN_002a2170(camera, (f32 *)&work.position);
    } else {
        FUN_002a2290(camera, work.start, (f32 *)&work.position, 1);
        FUN_002a3110(camera, 1.25f);
    }
}

// FUN_002e8a40
void func_002e8a40(BtlCamera* camera)
{
    struct {
        f32 start[7];
        VoiceVector position;
        f32 end[6];
    } work;
    f32* voiceData;
    u16 voiceVariant;
    u32 useCurrentPosition;
    u16 unitType;
    u16 mode;

    mode = *(u16*)(iGpffffb6fc + 0x104);
    switch (mode) {
    case 0x1c:
    case 0x22:
    case 2:
        useCurrentPosition = 0;
        break;
    default:
        useCurrentPosition = 1;
        break;
    }

    voiceVariant = FUN_002f88c0();
    unitType = FUN_002c09f0((u8*)camera->action + 0x88);
    FUN_002a4470(work.start, (f32*)&camera->pos);

    if (unitType == 2) {
        voiceData = (f32*)(*(int*)(iGpffffb6fc + 0xb18) +
                           voiceVariant * 0x18 + 0x2d4);
        FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
        work.position = *(VoiceVector*)voiceData;
    } else if (unitType == 1) {
        voiceData = (f32*)(*(int*)(iGpffffb6fc + 0xb18) +
                           voiceVariant * 0x18 + 0x304);
        FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
        work.position = *(VoiceVector*)voiceData;
    } else {
        voiceData = (f32*)(*(int*)(iGpffffb6fc + 0xb18) +
                           voiceVariant * 0x18 + 0x334);
        FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
        work.position = *(VoiceVector*)voiceData;
    }

    if (useCurrentPosition) {
        FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 0x40);
        FUN_002a2170(camera, (f32*)&work.position);
    } else {
        FUN_002a2290(camera, work.start, (f32*)&work.position, 1);
        FUN_002a3110(camera, 1.0f);
    }
}

// FUN_002e8c80
void func_002e8c80(void)
{
}

// FUN_002e8c90
void func_002e8c90(int param_1)
{
  f32 *voiceData;
  struct {
    VoiceVector position;
    u8 transform[20];
  } work;

  voiceData = (f32 *)(*(int *)(iGpffffb6fc + 0xb18) + 0x37c);
  FUN_002a4690(work.transform, voiceData, voiceData + 3, &D_00697880);
  work.position = *(VoiceVector *)voiceData;
  FUN_002a2170((void *)(iGpffffb6fc + 0x20), (f32 *)&work.position);
  FUN_002a44b0((f32 *)(param_1 + 0x9c), (f32 *)&work.position);
}

// FUN_002e8d20
void func_002e8d20(void)

{
  FUN_002b4f40();
  return;
}

// FUN_002e8d40
void func_002e8d40(void)

{
  FUN_002b4db0(uGpffff8108);
  return;
}

// FUN_002e8d70
void func_002e8d70(void *param_1)
{
  void *action;
  f32 *voiceData;
  struct {
    f32 start[7];
    VoiceVector position;
    f32 end[6];
  } work;

  action = (void *)param_1;
  FUN_002a4470(work.start, (f32 *)((u8 *)param_1 + 0x9c));
  voiceData = (f32 *)(*(int *)(iGpffffb6fc + 0xb18) + 0x364);
  FUN_002a4690(work.end, voiceData, voiceData + 3, &D_00697880);
  work.position = *(VoiceVector *)voiceData;
  FUN_002a2290(action, work.start, (f32 *)&work.position, 1);
  FUN_002a3110(action, 0.75f);
}

// FUN_002e8e20
void func_002e8e20(void)
{
  struct {
    VoiceVector startPosition;
    f32 start[4];
    VoiceVector endPosition;
    f32 end[6];
  } work;
  u32 characterId;
  u8 *voiceData;
  u8 *base;
  float duration;

  characterId = (u16)FUN_002ffbc0(2);
  base = (u8 *)(*(int *)(iGpffffb6fc + 0xb18));
  characterId = characterId * 0x34;
  voiceData = base + characterId + 0x20c;
  FUN_002a4690(work.start, (f32 *)(voiceData + 4),
               (f32 *)(voiceData + 0x10), &D_00697880);
  work.startPosition = *(VoiceVector *)(voiceData + 4);
  FUN_002a4690(work.end, (f32 *)(voiceData + 0x1c),
               (f32 *)(voiceData + 0x28), &D_00697880);
  work.endPosition = *(VoiceVector *)(voiceData + 0x1c);
  duration = (float)*(s16 *)voiceData / 30.0f;
  FUN_002a2290((void *)(iGpffffb6fc + 0x20), (f32 *)&work.startPosition,
               (f32 *)&work.endPosition, 1);
  FUN_002a3110((void *)(iGpffffb6fc + 0x20), duration);
}

// FUN_002e8f40
void func_002e8f40(void)
{
  struct {
    VoiceVector startPosition;
    f32 start[4];
    VoiceVector endPosition;
    f32 end[6];
  } work;
  u32 characterId;
  u8 *voiceData;
  u8 *base;
  float duration;
  characterId = (u16)FUN_002ffbc0(2);
  base = (u8 *)(*(int *)(iGpffffb6fc + 0xb18));
  characterId = characterId * 0x34;
  voiceData = base + characterId + 0x1a4;
  FUN_002a4690(work.start, (f32 *)(voiceData + 4),
               (f32 *)(voiceData + 0x10), &D_00697880);
  work.startPosition = *(VoiceVector *)(voiceData + 4);
  FUN_002a4690(work.end, (f32 *)(voiceData + 0x1c),
               (f32 *)(voiceData + 0x28), &D_00697880);
  work.endPosition = *(VoiceVector *)(voiceData + 0x1c);
  duration = (float)*(s16 *)voiceData / 30.0f;
  FUN_002a2290((void *)(iGpffffb6fc + 0x20), (f32 *)&work.startPosition,
               (f32 *)&work.endPosition, 1);
  FUN_002a3110((void *)(iGpffffb6fc + 0x20), duration);
}

// FUN_002e9060
void func_002e9060(void)
{
  struct {
    VoiceVector startPosition;
    f32 start[4];
    VoiceVector endPosition;
    f32 end[6];
  } work;
  float duration;

  FUN_002a4690(work.start, DAT_00699244, DAT_00699250, &D_00697880);
  work.startPosition = *(VoiceVector *)DAT_00699244;
  FUN_002a4690(work.end, DAT_0069925c, DAT_00699268, &D_00697880);
  work.endPosition = *(VoiceVector *)DAT_0069925c;
  duration = (float)DAT_00699240[0] / 30.0f;
  FUN_002a2290((void *)(iGpffffb6fc + 0x20), (f32 *)&work.startPosition, (f32 *)&work.endPosition, 1);
  FUN_002a3110((void *)(iGpffffb6fc + 0x20), duration);
}

// FUN_002e9170
void func_002e9170(void)
{
    VoiceXZ positions[2] = {{0.0f, -250.0f}, {200.0f, 150.0f}};
    RwV3d position;
    BtlUnit* primaryUnit;
    BtlUnit* secondaryUnit;
    s16 index;
    VoiceXZ* selected;

    position.y = 0.0f;
    for (primaryUnit = gBtl->unitLists[UNIT_GENUS_PC].head;
         primaryUnit != NULL; primaryUnit = primaryUnit->next) {
        if (primaryUnit->charId == 1) {
            position.x = -300.0f;
            position.z = 200.0f;
            primaryUnit->unk_9f0 = 0;
        } else {
            position.x = 0.0f;
            position.z = 0.0f;
        }
        FUN_002d2280(&primaryUnit->unk_94, &primaryUnit->unk_96,
                     (f32*)&position);
        btlUnitSetPos(primaryUnit, &position);
    }

    index = 0;
    for (secondaryUnit = gBtl->unitLists[UNIT_GENUS_EC].head;
         secondaryUnit != NULL; secondaryUnit = secondaryUnit->next) {
        selected = &positions[index];
        position.x = selected->x;
        position.z = selected->z;
        index++;
        FUN_002d2280(&secondaryUnit->unk_94, &secondaryUnit->unk_96,
                     (f32*)&position);
        btlUnitSetPos(secondaryUnit, &position);
    }
}

// FUN_002e92c0
void func_002e92c0(void)

{
  RwV3d position;
  u16 sVar1;
  int iVar2;

  position.y = 0.0f;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 1:
      position.x = -250.0f;
      position.z = 500.0f;
      *(u8 *)(iVar2 + 0x9f0) = 0;
      break;
    case 2:
      position.x = 250.0f;
      position.z = 500.0f;
      *(u8 *)(iVar2 + 0x9f0) = 2;
      break;
    case 5:
      position.x = 0.0f;
      position.z = 400.0f;
      *(u8 *)(iVar2 + 0x9f0) = 1;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&position.x);
    FUN_0027f650(iVar2,&position.x);
  }
  for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 0x100:
      position.x = 0.0f;
      position.z = -400.0f;
      break;
    case 0x113:
      position.x = -200.0f;
      position.z = 100.0f;
      break;
    case 0x114:
      position.x = 200.0f;
      position.z = 100.0f;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&position.x);
    FUN_0027f650(iVar2,&position.x);
  }
  return;
}

#pragma opt_loop_invariants on
// FUN_002e9450
void func_002e9450(void)
{
  BtlUnit* source;
  BtlUnit* target;
  void* object;
  BtlPacket* packet;
  BtlUnit* unit;
  BtlUnit* enemy;
  BtlUnit* arg0;
  BtlUnit* arg1;
  BtlUnit* arg2;
  u32 raw;

  object = (void*)FUN_002b8f90_u32_voice(0);
  func_002b90d0(object, (void*)FUN_002f87e0_u32_voice(1));
  source = NULL;
  arg0 = NULL;
  arg1 = NULL;
  arg2 = NULL;
  target = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 1:
      source = unit;
      break;
    case 2:
      arg0 = unit;
      break;
    case 5:
      arg1 = unit;
      break;
    default:
      arg2 = unit;
      break;
    }
  }
  for (enemy = gBtl->unitLists[UNIT_GENUS_EC].head;
       enemy != NULL; enemy = enemy->next) {
    switch (enemy->charId) {
    case 0x100:
      target = enemy;
      break;
    }
  }
  raw = FUN_002bc950_u32_voice(arg0, arg1, arg2);
  FUN_0027ed20_voice(raw, 1);
  packet = FUN_002baf90_packet_voice(object, source, target, 0, 0x200);
  FUN_0027ed20_voice((u32)packet, 2);
  raw = FUN_002bc950_u32_voice(0, 0, 0);
  *(u8*)raw = 4;
  *(u64*)((u8*)raw + 8) = *(u64*)((u8*)packet + 0x58);
  FUN_0027ed20_voice(raw, 1);
  func_002b9030(object);
}
#pragma opt_loop_invariants off
/* Removing this loses FUN_002e95f0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002e95f0
void func_002e95f0(void)
{
    BtlUnit* target;
    void* object;
    BtlPacket* parent;
    BtlUnit* unit;
    BtlPacket* packet;

    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(2));
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x100:
            target = unit;
            break;
        }
    }
    packet = FUN_002dd690_packet_voice(3, DAT_00699c10);
    btlPacketRegister(packet, 1);
    parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
    parent->preUpdateDelay = 3;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
    btlPacketRegister(packet, 2);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002e97e0
int func_002e97e0(void)
{
  /* Caller-specific return width: retail consumes only the s32 result in this path. */
  extern s32 FUN_0030b5a0();
  BtlUnit* enemy;
  BtlAction* action;
  s32 found;
  BtlUnit* unit;
  BtlPacket* packet;
  u32 data[8];

  found = 0;
  for (enemy = gBtl->unitLists[UNIT_GENUS_EC].head;
       enemy != NULL; enemy = enemy->next) {
    if (enemy->charId == 0x100 &&
        FUN_0030b5a0(enemy->datUnit, 0) != 0) {
      found = 1;
      break;
    }
  }
  if (found != 0) {
    FUN_002d5dc0(data);
    data[0] = 0xfff00001;
    for (action = gBtl->actionList.tail;
         action != NULL; action = action->prev) {
      if ((action->unk_1a & 1) != 0) {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC &&
            unit->charId != 0x100 &&
            FUN_0030b5a0(unit->datUnit, 0) == 0) {
          packet = FUN_002d7e20_packet_voice(action, action, data, 1, 1);
          FUN_0027ed20_voice((u32)packet, 1);
          packet = FUN_00284200_packet_voice(1.0f, unit, 2, 0, 0);
          FUN_0027ed20_voice((u32)packet, 1);
        }
      }
    }
  }
  return found;
}

// FUN_002e9950
void func_002e9950(void)
{
  u16 sVar1;
  int iVar2;
  RwV3d position;
  
  position.y = 0.0f;
  for (iVar2 = *(int *)(iGpffffb6fc_ptr + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 1:
      position.x = -300.0f;
      position.z = 250.0f;
      *(u8 *)(iVar2 + 0x9f0) = 0;
      break;
    case 5:
      position.x = 300.0f;
      position.z = 250.0f;
      *(u8 *)(iVar2 + 0x9f0) = 2;
      break;
    case 7:
      position.x = 0.0f;
      position.z = 350.0f;
      *(u8 *)(iVar2 + 0x9f0) = 1;
      break;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&position);
    FUN_0027f650(iVar2,&position);
  }
  for (iVar2 = *(int *)(iGpffffb6fc_ptr + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 0x101:
      position.x = -250.0f;
      position.z = -350.0f;
      break;
    case 0x102:
      position.x = 250.0f;
      position.z = -350.0f;
      break;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&position);
    FUN_0027f650(iVar2,&position);
  }
}

#pragma opt_loop_invariants on
// FUN_002e9ac0
void func_002e9ac0(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* packet;
  BtlUnit* unit;
  BtlUnit* arg0;
  BtlUnit* arg1;
  BtlUnit* arg2;
  u32 raw;

  object = (void*)FUN_002b8f90_u32_voice(0);
  func_002b90d0(object, (void*)FUN_002f87e0_u32_voice(1));
  target = NULL;
  arg0 = NULL;
  arg1 = NULL;
  arg2 = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 1:
      target = unit;
      break;
    case 5:
      arg0 = unit;
      break;
    case 7:
      arg1 = unit;
      break;
    default:
      arg2 = unit;
      break;
    }
  }
  raw = FUN_002bc950_u32_voice(arg0, arg1, arg2);
  FUN_0027ed20_voice(raw, 1);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  FUN_0027ed20_voice((u32)packet, 2);
  raw = FUN_002bc950_u32_voice(0, 0, 0);
  *(u8*)raw = 4;
  *(u64*)((u8*)raw + 8) = *(u64*)((u8*)packet + 0x58);
  FUN_0027ed20_voice(raw, 1);
  func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002e9c20
void func_002e9c20(BtlAction* action)
{
    BtlUnit* unit;
    void* object;
    BtlPacket* parent;
    BtlPacket* packet;

    *(u32*)((u8*)gBtl + 0xc) &= ~0x02000000;
    *(u32*)((u8*)gBtl + 0xc) |= 0x00080000;
    unit = action->unit;
    object = func_002b8f90(0);
    switch (unit->charId) {
    case 0x101:
        func_002b90d0(object, func_002f87e0(2));
        packet = FUN_002dd690_packet_voice(
            3, (const char*)(DAT_006a0000 - 0x6398));
        btlPacketRegister(packet, 1);
        break;
    case 0x102:
        func_002b90d0(object, func_002f87e0(3));
        packet = FUN_002dd690_packet_voice(
            3, (const char*)(DAT_006a0000 - 0x63a8));
        btlPacketRegister(packet, 1);
        break;
    }
    parent = FUN_00284200_packet_voice(1.0f, unit, 0x12, 0, 2);
    parent->preUpdateDelay = 2;
    parent->actionUID = action->uid;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(unit, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
    packet->actionUID = action->uid;
    btlPacketRegister(packet, 2);
    if (FUN_002d4e10_u16_voice(2, 0x80000) == 1) {
        packet = FUN_002db890_packet_voice();
        packet->preUpdateDelay = 0x2d;
        btlPacketRegister(packet, 1);
        packet = FUN_002db800_packet_voice(0x20, 0x17);
        packet->preUpdateDelay = 0x2d;
        btlPacketRegister(packet, 1);
    }
    *(u32*)((u8*)gBtl + 0xc) |= 0x00400000;
    *(u16*)((u8*)gBtl + 0x18) |= 7;
    func_002b9030(object);
}

// FUN_002e9f10
u32 func_002e9f10(BtlAction* action)
{
    BtlPacket* packet;

    if (action != btlActionCurrent())
    {
        if ((action->unit->flags3 & 0x10) != 0)
        {
            return 1;
        }
    }
    else
    {
        action->unit->flags3 &= ~0x10;
    }

    packet = btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX);
    if (packet == NULL)
    {
        gBtl->flags &= ~0x80000;
        FUN_002d7890(action, 0);
        FUN_0029a320(action);
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002ea060
void func_002ea060(void)
{
  int iVar1;
  int iVar2;
  u16 kind;
  s16 index;
  s16 slotIndex;
  f32 positions[4];
  f32* point;
  RwV3d position;
  VoiceSlotPair slots;
  *(VoicePositions *)positions = *(VoicePositions *)DAT_00699c80_abs;
  slots = *(VoiceSlotPair *)&gp0xffff9c98;
  index = 0;
  position.y = 0.0f;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    kind = *(u16 *)(iVar1 + 0xa4);
    if (kind == 1) {
      position.x = 150.0f;
      position.z = 450.0f;
      *(u8 *)(iVar1 + 0x9f0) = 2;
    }
    else if (kind == 2) {
      position.x = -150.0f;
      position.z = 450.0f;
      *(u8 *)(iVar1 + 0x9f0) = 1;
    }
    else {
      slotIndex = index;
      point = positions + slotIndex * 2;
      position.x = point[0];
      position.z = point[1];
      *(u8 *)(iVar1 + 0x9f0) = slots.values[slotIndex];
      index++;
    }
    FUN_002d2280(iVar1 + 0x94,iVar1 + 0x96,&position);
    FUN_0027f650(iVar1,&position);
  }
  for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    kind = *(u16 *)(iVar2 + 0xa4);
    switch (kind) {
    case 0x103:
      position.x = 0.0f;
      position.z = -300.0f;
      break;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&position);
    FUN_0027f650(iVar2,&position);
  }
}

/* Removing this loses FUN_002ea210 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ea210
void func_002ea210(void)
{
    BtlUnit* target;
    void* object;
    BtlPacket* parent;
    BtlUnit* unit;
    BtlPacket* packet;

    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(2));
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x103:
            target = unit;
            break;
        }
    }
    packet = FUN_002dd690_packet_voice(3, DAT_00699cb0);
    btlPacketRegister(packet, 1);
    parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
    parent->preUpdateDelay = 3;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
    btlPacketRegister(packet, 2);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002ea400
void func_002ea400(void)
{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];

  puVar6 = (u32*)DAT_00699cc0;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&uGpffff9ca0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0x43160000;
      uStack_10.raw[2] = 0x43e10000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(iGpffffb6fc + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x104:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3960000;
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

/* Removing this loses FUN_002ea590 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ea590
void func_002ea590(void)
{
    BtlUnit* target;
    void* object;
    BtlPacket* parent;
    BtlUnit* unit;
    BtlPacket* packet;

    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(2));
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x104:
            target = unit;
            break;
        }
    }
    packet = FUN_002dd690_packet_voice(3, DAT_00699d00);
    btlPacketRegister(packet, 1);
    parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
    parent->preUpdateDelay = 3;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
    btlPacketRegister(packet, 2);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002ea780
void func_002ea780(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0)
    {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC)
        {
            switch (unit->charId)
            {
            case 0x115:
                unit->datUnit->flags |= 0x40;
                unit->flags3 |= 0x400;
                return;
            case 0x105:
                unit->flags3 |= 0x400;
            case 0x106:
                unit->flags3 |= 0x100;
                unit->flags3 |= 0x200;
                unit->flags3 |= 0x40;
                unit->flags3 &= ~8;
                action->unk_1a &= ~8;
                FUN_0029a320(action);
                break;
            default:
                return;
            }
        }
    }
}

// FUN_002ea860
void func_002ea860(void)
{
  typedef struct {
    u32 data[6];
    s16 ids[4];
    RwV3d position;
  } VoicePositionWork;
  typedef struct {
    s16 a;
    s16 b;
    s16 c;
  } VoiceIds;
  VoicePositionWork work;
  u32 uVar1;
  u32 uVar2;
  int iVar4;
  u32 *puVar6;
  u32 *puVar5;
  int copyCount;
  int iVar3;
  s16 sVar7;

  puVar6 = (u32*)DAT_00699d10;
  puVar5 = work.data;
  copyCount = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    copyCount = copyCount + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < copyCount);
  *(VoiceIds *)&work.ids[0] = *(VoiceIds *)&uGpffff9ca8;
  sVar7 = 0;
  work.position.y = 0.0f;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0;
       iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      work.position.x = -150.0f;
      work.position.z = 450.0f;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      iVar3 = (int)sVar7;
      work.position.x = *(f32*)((u8*)&work + iVar3 * 8);
      work.position.z = *(f32*)((u8*)&work + iVar3 * 8 + 4);
      *(u8 *)(iVar4 + 0x9f0) = (u8)work.ids[iVar3];
      sVar7++;
    }
    FUN_002d2280(iVar4 + 0x94, iVar4 + 0x96, &work.position.x);
    FUN_0027f650(iVar4, &work.position.x);
  }
  for (iVar3 = *(int *)(DAT_007ce3ec + 0x158); iVar3 != 0;
       iVar3 = *(int *)(iVar3 + 0xa34)) {
    switch (*(u16 *)(iVar3 + 0xa4)) {
    case 0x105:
      work.position.x = -300.0f;
      work.position.z = -400.0f;
      break;
    case 0x106:
      work.position.x = 300.0f;
      work.position.z = -500.0f;
      break;
    case 0x115:
      work.position.x = 0.0f;
      work.position.z = -400.0f;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar3 + 0x94, iVar3 + 0x96, &work.position.x);
    FUN_0027f650(iVar3, &work.position.x);
  }
}

#pragma opt_propagation off
// FUN_002eaa40
void func_002eaa40(void)
{
    BtlUnit* unit;
    BtlUnit* selected;
    Model* model105;
    Model* model106;
    s8 voiceValue;

    selected = 0;
    model105 = 0;
    model106 = 0;
    for (unit = *(BtlUnit**)(iGpffffb6fc + 0x158);
         unit != 0;
         unit = unit->next)
    {
        if (unit->charId == 0x115)
        {
            goto char115;
        }
        if (unit->charId == 0x106)
        {
            goto char106;
        }
        switch (unit->charId)
        {
        case 0x105:
            goto char105;
        default:
            goto advance;
        }

char105:
        model105 = unit->mdl;
        FUN_002d3fe0(unit);
        goto advance;

char106:
        model106 = unit->mdl;
        FUN_002d3fe0(unit);
        goto advance;

char115:
        selected = unit;

advance:
        ;
    }
    FUN_003195f0(selected->mdl, 0, model105);
    FUN_003195f0(selected->mdl, 1, model106);
    FUN_002831c0(selected, 0);
    voiceValue = selected->unk_9e8;
    FUN_00282d40_call(selected, selected->unk_9e0, 0, voiceValue,
                      selected->unk_9e4);
    FUN_00282bc0(selected);
}
#pragma opt_propagation on

// FUN_002eab70
void func_002eab70(void)

{
  func_002e4220((u32)func_002eabf0,(u32)func_002eb250,0);
  return;
}

// FUN_002eabb0
void func_002eabb0(void)

{
  func_002e4220((u32)func_002eb2c0,(u32)func_002eb9e0,0);
  return;
}

// FUN_002eabf0 NONMATCHING
void func_002eabf0(void)

{
  /* Caller-specific return widths: this path consumes u32 results, not the broad u64 forms. */
  extern u32 FUN_002dd4a0();
  extern u32 FUN_002dd5e0();
  extern u32 FUN_00285f20();
  extern u32 FUN_00285e50();
  short sVar1;
  u64 *puVar2;
  int iVar3;
  u16 uVar4;
  u16 uVar5;
  u16 uVar6;
  int iVar7;
  u8 *puVar8;
  u8 *puVar9;
  u32 uVar10;
  u32 uVar11;
  u32 *puVar12;
  u64 *unaff_s2_lo;
  u8 auStack_90 [136];
  int aiStack_8 [2];
  
  FUN_00395170(0x15f0);
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  aiStack_8[0] = 0;
  aiStack_8[1] = 0;
  for (puVar2 = *(u64 **)(iGpffffb6fc + 0x14c); puVar2 != (u64 *)0x0;
      puVar2 = *(u64 **)(puVar2 + 0x95)) {
    uVar4 = *(u16 *)((int)puVar2 + 0x1a);
    if (((uVar4 & 1) != 0) && (iVar3 = *(int *)(puVar2 + 6), *(char *)(iVar3 + 0xa2) == '\x01')) {
      sVar1 = *(short *)(iVar3 + 0xa4);
      if ((sVar1 == 0x106) || (sVar1 == 0x105)) {
        if ((uVar4 & 8) == 0) {
          *(u32 *)(iVar3 + 0x9c) = *(u32 *)(iVar3 + 0x9c) | 8;
          *(u16 *)((int)puVar2 + 0x1a) = *(u16 *)((int)puVar2 + 0x1a) | 8;
          FUN_0029a2c0(puVar2);
          FUN_002d3e00(iVar3,0);
          FUN_00300560(*(u32 *)(iVar3 + 0xa2c),0xffffff);
          FUN_002831c0(iVar3,6);
        }
        aiStack_8[*(short *)(iVar3 + 0xa4) != 0x105] = iVar3;
      }
      else if ((sVar1 == 0x115) && (unaff_s2_lo = puVar2, (uVar4 & 8) != 0)) {
        *(u32 *)(iVar3 + 0x9c) = *(u32 *)(iVar3 + 0x9c) & 0xfffffff7;
        *(u16 *)((int)puVar2 + 0x1a) = *(u16 *)((int)puVar2 + 0x1a) & 0xfff7;
        FUN_0029a320(puVar2);
        FUN_002d3fe0(iVar3);
        FUN_00300560(*(u32 *)(iVar3 + 0xa2c),0xffffff);
        FUN_002831c0(iVar3,6);
      }
    }
  }
  FUN_001fdd40();
  uVar4 = FUN_002ffd70(*(u32 *)(*(int *)(unaff_s2_lo + 6) + 0xa2c));
  if (uVar4 == 0) {
    uVar4 = 1;
  }
  uVar5 = FUN_002ffdf0(*(u32 *)(aiStack_8[0] + 0xa2c));
  uVar6 = uVar4;
  if (uVar5 < uVar4) {
    uVar6 = uVar5;
  }
  FUN_002ffd90(*(u32 *)(aiStack_8[0] + 0xa2c),uVar6);
  puVar12 = (u32 *)(aiStack_8[1] + 0xa2c);
  uVar6 = FUN_002ffdf0(*(u32 *)(aiStack_8[1] + 0xa2c));
  iVar3 = aiStack_8[1];
  if (uVar6 < uVar4) {
    uVar4 = uVar6;
  }
  FUN_002ffd90(*puVar12,uVar4);
  FUN_002831c0(aiStack_8[0],6);
  FUN_002831c0(iVar3,6);
  func_002e4240((u32)unaff_s2_lo);
  uVar10 = FUN_002b8f90_u32_voice(0);
  FUN_002bb6f0(0x166,auStack_90);
  uVar11 = (u32)FUN_002bac00_packet_voice(uVar10,auStack_90,0);
  iVar7 = (int)uVar11;
  *(u64 *)(iVar7 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002dd4a0(0x166,0);
  puVar8 = (u8 *)uVar11;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(iVar7 + 0x58);
  FUN_0027ed20(uVar11,1);
  uVar11 = (u32)FUN_002baf90_packet_voice((void *)uVar10,(BtlUnit *)aiStack_8[0],(BtlUnit *)iVar3,0,0);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(iVar7 + 0x58);
  puVar9[0x10] = 4;
  *(u64 *)(puVar9 + 0x18) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,2);
  uVar11 = FUN_002dd5e0(0);
  *(u8 *)uVar11 = 5;
  *(u64 *)((u8 *)uVar11 + 8) = *(u64 *)(puVar9 + 0x58);
  FUN_0027ed20(uVar11,1);
  if (*(int *)(iGpffffb6fc + 0xb44) == 0) {
    uVar11 = (u32)FUN_002db890_packet_voice();
    *(u16 *)((int)uVar11 + 0x48) = 0x1e;
    FUN_0027ed20(uVar11,1);
    uVar11 = (u32)FUN_002db800_packet_voice(0x20,0x1f);
    *(u16 *)((int)uVar11 + 0x48) = 0x1e;
    FUN_0027ed20(uVar11,1);
    *(u32 *)(iGpffffb6fc + 0xb44) = 1;
  }
  uVar11 = FUN_00285f20(*(u32 *)(unaff_s2_lo + 6));
  puVar8 = (u8 *)uVar11;
  *puVar8 = 5;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u16 *)(puVar8 + 0x48) = 3;
  *(u64 *)(puVar8 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,0);
  uVar11 = (u32)FUN_002bd590_packet_voice((BtlUnit *)*(u32 *)(unaff_s2_lo + 6),0x166);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,3);
  uVar11 = FUN_00285e50(aiStack_8[0]);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,0);
  iVar3 = aiStack_8[1];
  uVar11 = FUN_00285e50(aiStack_8[1]);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,0);
  uVar11 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)aiStack_8[0],0x18,0,0);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)iVar3,0x18,0,0);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = (u32)FUN_002dd830_packet_voice((BtlUnit *)aiStack_8[0],0xe,0,3);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = (u32)FUN_002b8d60_packet_voice(3,0xfff);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = (u32)FUN_002a3b40_packet_voice(0,1);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,0);
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x400000;
  *(u16 *)(iGpffffb6fc + 0x18) = *(u16 *)(iGpffffb6fc + 0x18) | 7;
  FUN_002b9030(uVar10);
  return;
}

// FUN_002eb250
u32 func_002eb250(BtlAction* action)
{
    BtlPacket* packet;

    packet = btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX);
    if (packet == NULL)
    {
        gBtl->flags &= ~0x80000;
        return 0;
    }

    return 1;
}

// FUN_002eb2c0 NONMATCHING
void func_002eb2c0(void)

{
  /* Caller-specific return widths: this path consumes u32 results, not the broad u64 forms. */
  extern u32 FUN_002dd4a0();
  extern u32 FUN_002dd5e0();
  extern u32 FUN_00284c90();
  extern u32 FUN_00285e50();
  extern u32 FUN_002843e0();
  extern u32 FUN_00285f20();
  u16 uVar1;
  short sVar2;
  u64 *puVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar7;
  u8 *puVar8;
  u8 *puVar9;
  u8 *puVar10;
  u8 *puVar11;
  u32 uVar12;
  u32 uVar13;
  u64 *unaff_s4_lo;
  u8 auStack_90 [136];
  int aiStack_8 [2];
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  aiStack_8[0] = 0;
  aiStack_8[1] = 0;
  for (puVar3 = *(u64 **)(iGpffffb6fc + 0x14c); puVar3 != (u64 *)0x0;
      puVar3 = *(u64 **)(puVar3 + 0x95)) {
    uVar1 = *(u16 *)((int)puVar3 + 0x1a);
    if (((uVar1 & 1) != 0) && (iVar4 = *(int *)(puVar3 + 6), *(char *)(iVar4 + 0xa2) == '\x01')) {
      sVar2 = *(short *)(iVar4 + 0xa4);
      if ((sVar2 == 0x106) || (sVar2 == 0x105)) {
        if ((uVar1 & 8) != 0) {
          *(u32 *)(iVar4 + 0x9c) = *(u32 *)(iVar4 + 0x9c) & 0xfffffff7;
          *(u16 *)((int)puVar3 + 0x1a) = *(u16 *)((int)puVar3 + 0x1a) & 0xfff7;
          FUN_0029a320(puVar3);
          FUN_002d3fe0(iVar4);
          FUN_00300560(*(u32 *)(iVar4 + 0xa2c),0xffffff);
          FUN_002831c0(iVar4,6);
        }
        aiStack_8[*(short *)(iVar4 + 0xa4) != 0x105] = iVar4;
      }
      else if ((sVar2 == 0x115) && (unaff_s4_lo = puVar3, (uVar1 & 8) == 0)) {
        *(u32 *)(iVar4 + 0x9c) = *(u32 *)(iVar4 + 0x9c) | 8;
        *(u16 *)((int)puVar3 + 0x1a) = *(u16 *)((int)puVar3 + 0x1a) | 8;
        FUN_0029a2c0(puVar3);
        FUN_002d3e00(iVar4,0);
        FUN_00300560(*(u32 *)(iVar4 + 0xa2c),0xffffff);
        FUN_002831c0(iVar4,6);
      }
    }
  }
  FUN_001fdd40();
  uVar5 = FUN_002ffd70(*(u32 *)(aiStack_8[0] + 0xa2c));
  uVar6 = FUN_002ffd70(*(u32 *)(aiStack_8[1] + 0xa2c));
  uVar5 = (int)((uVar5 & 0xffff) + (uVar6 & 0xffff)) >> 1;
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  uVar6 = FUN_002ffdf0(*(u32 *)(*(int *)(unaff_s4_lo + 6) + 0xa2c));
  if ((uVar6 & 0xffff) < uVar5) {
    uVar5 = uVar6 & 0xffff;
  }
  FUN_002ffd90(*(u32 *)(*(int *)(unaff_s4_lo + 6) + 0xa2c),uVar5);
  FUN_002831c0(*(u32 *)(unaff_s4_lo + 6),6);
  func_002e4240((u32)unaff_s4_lo);
  uVar12 = FUN_002b8f90_u32_voice(0);
  FUN_002bb6f0(0x165,auStack_90);
  uVar13 = (u32)FUN_002bac00_packet_voice(uVar12,auStack_90,0);
  iVar7 = (int)uVar13;
  *(u64 *)(iVar7 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_002dd4a0(0x165,0);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(iVar7 + 0x58);
  FUN_0027ed20(uVar13,1);
  iVar4 = aiStack_8[1];
  uVar13 = (u32)FUN_002baf90_packet_voice((void *)uVar12,(BtlUnit *)aiStack_8[0],(BtlUnit *)aiStack_8[1],0,0);
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(iVar7 + 0x58);
  puVar9[0x10] = 4;
  *(u64 *)(puVar9 + 0x18) = *(u64 *)(puVar8 + 0x58);
  FUN_0027ed20(uVar13,2);
  uVar13 = FUN_002dd5e0(0);
  *(u8 *)uVar13 = 5;
  *(u64 *)((u8 *)uVar13 + 8) = *(u64 *)(puVar9 + 0x58);
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_002b8d60_packet_voice(3,0xfff);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 5;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u16 *)(puVar8 + 0x48) = 3;
  *(u64 *)(puVar8 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_002bd590_packet_voice((BtlUnit *)*(u32 *)(unaff_s4_lo + 6),0x165);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,3);
  uVar13 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)aiStack_8[0],0x17,0,0);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)iVar4,0x17,0,0);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_00284c90(aiStack_8[0]);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)aiStack_8[0],0x19,8,1);
  puVar11 = (u8 *)uVar13;
  *puVar11 = 4;
  *(u64 *)(puVar11 + 8) = *(u64 *)(puVar10 + 0x58);
  *(u64 *)(puVar11 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_00284c90(iVar4);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)iVar4,0x19,8,1);
  puVar11 = (u8 *)uVar13;
  *puVar11 = 4;
  *(u64 *)(puVar11 + 8) = *(u64 *)(puVar10 + 0x58);
  *(u64 *)(puVar11 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = (u32)FUN_002a3b40_packet_voice(0,1);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = (u32)FUN_002b8d60_packet_voice(2,0xfff);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u64 *)(puVar8 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = (u32)FUN_002a3b40_packet_voice(unaff_s4_lo,0x1f);
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u16 *)(puVar9 + 0x4a) = 0x1e;
  *(u64 *)(puVar9 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_00285e50(*(u32 *)(unaff_s4_lo + 6));
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_002843e0(*(u32 *)(unaff_s4_lo + 6),0);
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_00285f20(aiStack_8[0]);
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_00285f20(iVar4);
  puVar9 = (u8 *)uVar13;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  FUN_002b9030(uVar12);
  return;
}

// FUN_002eb9e0
u32 func_002eb9e0(BtlAction* action)
{
    BtlPacket* packet;

    packet = btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX);
    if (packet == NULL)
    {
        gBtl->flags &= ~0x80000;
        return 0;
    }

    return 1;
}

/* W212: template 002ef000 confirms direct packet locals and flag-first setup already used here; target remains nd768/1064 (window 1136). Residual starts at frame 0x70 versus retail 0xa0 and retail has 52 bytes of real tail code, so the deficit is reconstruction rather than a removable staged result. */
// FUN_002eba50 NONMATCHING
void func_002eba50(BtlAction* action)
{
    BtlAction* selected;
    BtlUnit* unit;
    BtlPacket* parent;
    BtlPacket* packet;
    void* object;
    u32 mode;
    int iVar5;
    int aiStack_10[4];

    *(u32*)((u8*)gBtl + 0xc) &= ~0x02000000;
    *(u32*)((u8*)gBtl + 0xc) |= 0x00080000;
    selected = action;
    if (selected == NULL) {
        selected = gBtl->actionList.tail;
        while (selected != NULL &&
               ((selected->unk_1a & 1) == 0 ||
                selected->unit->genus != UNIT_GENUS_EC ||
                selected->unit->charId != 0x115)) {
            selected = selected->prev;
        }
    }
    aiStack_10[0] = 0;
    aiStack_10[1] = 0;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        if (FUN_0030b5a0(unit->datUnit, 0) != 0) {
            if (unit->charId == 0x106) {
                aiStack_10[1] = (int)unit;
            }
            else if (unit->charId == 0x105) {
                aiStack_10[0] = (int)unit;
            }
        }
    }
    if ((aiStack_10[0] == 0) || (aiStack_10[1] == 0)) {
        for (iVar5 = 0; iVar5 < 2; iVar5++) {
            if (aiStack_10[iVar5] != 0) {
                parent = FUN_00284200_packet_voice(
                    1.0f, (BtlUnit*)aiStack_10[iVar5], 0x12, 0, 2);
                btlPacketRegister(parent, 1);
            }
        }
    }
    else {
        object = func_002b8f90(0);
        if (action == NULL) {
            aiStack_10[2] = aiStack_10[0];
            aiStack_10[3] = aiStack_10[1];
            mode = 2;
            packet = FUN_002dd690_packet_voice(3, voiceStream115Both);
            btlPacketRegister(packet, 1);
        }
        else if (selected->unit == (BtlUnit*)aiStack_10[0]) {
            aiStack_10[2] = aiStack_10[0];
            aiStack_10[3] = 0;
            mode = 3;
            packet = FUN_002dd690_packet_voice(3, voiceStream115First);
            btlPacketRegister(packet, 1);
        }
        else {
            aiStack_10[2] = aiStack_10[1];
            aiStack_10[3] = 0;
            mode = 4;
            packet = FUN_002dd690_packet_voice(3, voiceStream115Second);
            btlPacketRegister(packet, 1);
        }
        func_002b90d0(object, func_002f87e0((u16)mode));
        for (iVar5 = 0; iVar5 < 2; iVar5++) {
            if (aiStack_10[iVar5 + 2] != 0) {
                parent = FUN_00284200_packet_voice(
                    1.0f, (BtlUnit*)aiStack_10[iVar5 + 2], 0x12, 0, 2);
                parent->preUpdateDelay = 3;
                parent->actionUID = selected->uid;
                btlPacketRegister(parent, 1);
            }
        }
        packet = FUN_002b8d60_packet_voice(3, 0xfff);
        packet->unk_00 = 4;
        packet->parentUID = parent->uid;
        packet->actionUID = selected->uid;
        btlPacketRegister(packet, 1);
        for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
             unit != NULL; unit = unit->next) {
            packet = FUN_0027fe90_packet_voice(
                unit, NULL, D_006978B0, NULL);
            packet->unk_00 = 4;
            packet->parentUID = parent->uid;
            packet->actionUID = selected->uid;
            btlPacketRegister(packet, 1);
        }
        packet = FUN_002a3b40_packet_voice(NULL, 1);
        packet->unk_00 = 4;
        packet->parentUID = parent->uid;
        packet->actionUID = selected->uid;
        btlPacketRegister(packet, 0);
        packet = FUN_002baf90_packet_voice(
            object, (BtlUnit*)aiStack_10[0], (BtlUnit*)aiStack_10[1], 0, 0x200);
        packet->actionUID = selected->uid;
        btlPacketRegister(packet, 2);
        func_002b9030(object);
    }
}

/* Removing this loses FUN_002ebec0 (MATCH nd0 -> MISMATCH nd42) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ebec0
u32 func_002ebec0(BtlAction* action)
{
    BtlPacket* packet;
    u8 genus = UNIT_GENUS_EC;
    u16 charId = 0x115;

    if (action == NULL)
    {
        action = gBtl->actionList.tail;
        while (action != NULL)
        {
            if ((action->unk_1a & 1) == 0 ||
                action->unit->genus != genus ||
                action->unit->charId != charId)
            {
                action = action->prev;
            }
            else
            {
                break;
            }
        }
    }

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}
#pragma opt_loop_invariants off

// FUN_002ec000
void func_002ec000(void)
{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar6;
  u32 *puVar5;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  union {
    u32 raw[3];
    f32 vec[3];
  } uStack_10;
  s16 auStack_18[3];

  puVar6 = (u32*)DAT_00699db0;
  puVar5 = auStack_30;
  iVar5 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar5);
  *(VoiceSlots *)auStack_18 = *(VoiceSlots *)&DAT_007cc9a0;
  sVar7 = 0;
  uStack_10.raw[1] = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      uStack_10.raw[0] = 0x43160000;
      uStack_10.raw[2] = 0x43e10000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      uStack_10.vec[0] = *(f32 *)(auStack_30 + ((short)sVar7 * 2));
      uStack_10.vec[2] = *(f32 *)(auStack_30 + ((short)sVar7 * 2) + 1);
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[(short)sVar7];
      sVar7 = (short)((int)sVar7 + 1);
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar6 = *(int *)(DAT_007ce3ec + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    switch (*(u16 *)(iVar6 + 0xa4)) {
    case 0x107:
      uStack_10.raw[0] = 0;
      uStack_10.raw[2] = 0xc3c80000;
      break;
    }
    FUN_002d2280(iVar6 + 0x94,iVar6 + 0x96,&uStack_10);
    FUN_0027f650(iVar6,&uStack_10);
  }
  return;
}

// FUN_002ec190
void func_002ec190(BtlAction* source, BtlAction* target, BtlTargetResult* result)
{
    if (source->unit->genus == UNIT_GENUS_EC &&
        source->unit->charId == 0x107 &&
        (result->flags & 0x80) != 0)
    {
        *(u32*)(DAT_007ce3ec + 0xb44) = 0;
    }

    if (target->unit->genus == UNIT_GENUS_EC && target->unit->charId == 0x107)
    {
        if ((result->statusFlags & 0x100000) != 0)
        {
            *(u32*)(DAT_007ce3ec + 0xb44) = 0;
            *(s16*)(DAT_007ce3ec + 0xb50) = 2;
        }
        else if (result->hpDelta < 0 && func_002ec590() == 1)
        {
            if (*(s16*)(DAT_007ce3ec + 0xb50) < 2)
            {
                (*(s16*)(DAT_007ce3ec + 0xb50))++;
            }
        }

        if (result->hpDelta < 0)
        {
            if (*(s32*)(DAT_007ce3ec + 0xb48) > -result->hpDelta)
            {
                *(s32*)(DAT_007ce3ec + 0xb48) += result->hpDelta;
            }
            else
            {
                *(s32*)(DAT_007ce3ec + 0xb48) = 0;
            }
        }
    }
}

/* Removing this loses FUN_002ec2c0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ec2c0
void func_002ec2c0(void)
{
    BtlUnit* target;
    void* object;
    BtlPacket* parent;
    BtlUnit* unit;
    BtlPacket* packet;

    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(2));
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x107:
            target = unit;
            break;
        }
    }
    packet = FUN_002dd690_packet_voice(3, DAT_00699df0);
    btlPacketRegister(packet, 1);
    parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
    parent->preUpdateDelay = 3;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
    btlPacketRegister(packet, 2);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002ec4b0
void func_002ec4b0(BtlUnit* unit)
{
    if (unit->genus == UNIT_GENUS_EC &&
        unit->charId == 0x107 &&
        (unit->flags2 & 2) != 0)
    {
        if (*(s32*)((u8*)gBtl + 0xb4c) != 0)
        {
            u8* field = (u8*)unit->mdl + 0x41d;
            if (*field < 0xdf)
                *field += 0x20;
            else
                *field = 0xff;
        }
        else
        {
            u8* field = (u8*)unit->mdl + 0x41d;
            if (0x20 < *field)
                *field -= 0x20;
            else
                *field = 0;
        }
    }
}

// FUN_002ec560
void func_002ec560(u32 param_1)

{
  if (*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1a5) {
    *(u32 *)(DAT_007ce3ec + 0xb44) = 1;
    *(u32 *)(DAT_007ce3ec + 0xb48) = param_1;
  }
  return;
}

// FUN_002ec590
u32 func_002ec590(void)

{
  u32 uVar1;
  
  if (*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1a5) {
    uVar1 = *(u32 *)(DAT_007ce3ec + 0xb44);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_002ec5c0
void func_002ec5c0(void)
{
  typedef struct {
    u32 data[6];
    s16 ids[4];
    RwV3d position;
  } VoicePositionWork;
  typedef struct {
    s16 a;
    s16 b;
    s16 c;
  } VoiceIds;
  VoicePositionWork work;
  u32 uVar1;
  u32 uVar2;
  int iVar4;
  u32 *puVar6;
  u32 *puVar5;
  int copyCount;
  int iVar3;
  s16 sVar7;

  puVar6 = (u32*)DAT_00699e00;
  puVar5 = work.data;
  copyCount = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    copyCount = copyCount + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < copyCount);
  *(VoiceIds *)&work.ids[0] = *(VoiceIds *)&DAT_007cc9a8;
  sVar7 = 0;
  work.position.y = 0.0f;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      work.position.x = 150.0f;
      work.position.z = 550.0f;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      work.position.x = *(f32*)((u8*)&work + iVar3 * 8);
      work.position.z = *(f32*)((u8*)&work + iVar3 * 8 + 4);
      *(u8 *)(iVar4 + 0x9f0) = (u8)work.ids[iVar3];
      sVar7++;
    }
    FUN_002d2280(iVar4 + 0x94, iVar4 + 0x96, &work.position.x);
    FUN_0027f650(iVar4, &work.position.x);
  }
  for (iVar3 = *(int *)(DAT_007ce3ec + 0x158); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xa34)) {
    switch (*(u16 *)(iVar3 + 0xa4)) {
    case 0x109:
      work.position.x = -400.0f;
      work.position.z = -300.0f;
      break;
    case 0x10a:
      work.position.x = 400.0f;
      work.position.z = -300.0f;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar3 + 0x94, iVar3 + 0x96, &work.position.x);
    FUN_0027f650(iVar3, &work.position.x);
  }
  return;
}

/* Removing this loses FUN_002ec790 (MATCH nd0 -> MISMATCH nd32) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ec790
void func_002ec790(void)
{
    void* object;
    BtlPacket* parent;
    BtlUnit* iVar8;
    BtlUnit* iVar6;
    BtlUnit* unit;
    BtlPacket* packet;

    iVar8 = NULL;
    iVar6 = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x109:
            iVar6 = unit;
            break;
        case 0x10a:
            iVar8 = unit;
            break;
        }
    }
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(1));
    parent = FUN_002baf90_packet_voice(object, iVar8, iVar6, 0, 0x200);
    btlPacketRegister(parent, 2);
    packet = FUN_002dd830_packet_voice(iVar8, 10, 0, 6);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 0x40;
    btlPacketRegister(packet, 1);
    packet = FUN_002dd830_packet_voice(iVar8, 0xc, 0, 7);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 0x84;
    btlPacketRegister(packet, 1);
    packet = FUN_0027f410_packet_voice((u32)func_002ecbe0, (u32)iVar6);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 0x8c;
    btlPacketRegister(packet, 1);
    packet = FUN_00284200_packet_voice(1.0f, iVar6, 0, 0, 1);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 0x8c;
    btlPacketRegister(packet, 1);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002ec990
void func_002ec990(BtlUnit* unit)
{
  u16 sVar2;
  
  if ((unit->genus == 1) && (unit->charId == 0x109) &&
      ((unit->flags2 & 2) != 0)) {
    sVar2 = (u16)FUN_00318540(unit->mdl, 0);
    if ((*(int *)((u8 *)gBtl + 0xb50) != 0) && (sVar2 == 6)) {
      void *model;
      model = unit->mdl;
      *(u16 *)((u8 *)model + 0xd8) =
          *(u16 *)((u8 *)model + 0xd8) | 0x80;
      if (unit->cols[4].a > 1) {
        u8 bVar1;
        bVar1 = unit->cols[4].a;
        if (bVar1 > 9) {
          unit->cols[4].a = bVar1 - 8;
        } else {
          unit->cols[4].a = 1;
        }
        unit->flags2 = unit->flags2 | 4;
      }
    } else {
      void *model;
      u8 bVar1;
      model = unit->mdl;
      *(u16 *)((u8 *)model + 0xd8) =
          *(u16 *)((u8 *)model + 0xd8) & 0xff7f;
      bVar1 = unit->cols[4].a;
      if (bVar1 < 0xff) {
        if (bVar1 < 0xf7) {
          unit->cols[4].a = bVar1 + 8;
        } else {
          unit->cols[4].a = 0xff;
        }
        unit->flags2 = unit->flags2 | 4;
      }
    }
  }
  return;
}

/* Removing this loses FUN_002ecac0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ecac0
u32 func_002ecac0(void)
{
    BtlUnit* unit;

    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL;
         unit = unit->next)
    {
        if (unit->charId == 0x10a)
            return datCalcIsDead(unit->datUnit, 0) == 0;
    }
    return 0;
}
#pragma opt_loop_invariants off

// FUN_002ecb30
u32 func_002ecb30(BtlAction* action, s16 selection)
{
    u16 specificId;
    s32 result;

    *(u16*)((u8*)gBtl + 0xb54) = selection;
    result = datCalcChkBadStatus(action->unit->datUnit, 4);
    if (result == 0)
    {
        func_002e4220((u32)func_002ed350,
                      (u32)func_002ed360,
                      (u32)action);
    }
    else
    {
        action->target.commandId = 1;
        specificId = FUN_00308930(action->unit->datUnit);
        action->target.specificId = specificId;
        FUN_002c3770(action, 0);
        return 0;
    }
    return 1;
}

// FUN_002ecbe0
u32 func_002ecbe0(void)

{
  BtlAction* action;

  action = FUN_0029a1d0();
  *(u32 *)(DAT_007ce3ec + 0xb50) = 1;
  action->unk_1a &= 0xfff7;
  return 1;
}

// FUN_002ecc20
u32 func_002ecc20(void)

{
  BtlAction* action;

  action = FUN_0029a1d0();
  *(u32 *)(DAT_007ce3ec + 0xb50) = 0;
  action->unk_1a |= 8;
  return 1;
}

// FUN_002ecc60 NONMATCHING
void func_002ecc60(s16 *param_1, s16 *param_2)
{
  typedef struct VoiceRegionLocals {
    RwV2d center;
    RwV2d firstEdge;
    RwV2d secondEdge;
    RwV2d listenerEdge;
    RwV3d firstPoint;
    RwV3d secondPoint;
    u8 pointPadding[8];
    RwV3d listenerPoint;
  } VoiceRegionLocals;
  VoiceRegionLocals stack;
  s16 *table;
  s16 firstResult;
  s16 secondResult;
  u16 index;
  s16 *entry;
  s16 *entryResult;
  u16 command;
  f32 originX = 0.0f;
  f32 originZ = 0.0f;

  command = *(u16 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0xa4);
  switch (command) {
  case 0xe2:
    table = D_00699e60;
    break;
  case 0xe3:
    table = D_00699eb0;
    break;
  case 0xe4:
    table = D_00699f00;
    break;
  case 0xe5:
    table = D_00699f50;
    break;
  case 0xe6:
    table = D_00699f90;
    break;
  }

  firstResult = -1;
  secondResult = firstResult;
  if (FUN_00318ed0_btlVoice_typed(
          *(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x9f4),
          0x15, &stack.listenerPoint.x) != 0) {
    f32 listenerX = stack.listenerPoint.x;
    f32 listenerZ = stack.listenerPoint.z;
    index = 0;
    while ((entry = table + index * 4,
            entryResult = entry + 2,
            *entryResult != -1)) {
      if (FUN_00318ed0_btlVoice_typed(
              *(u32 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0x9f4),
              entry[0], &stack.firstPoint.x) != 0 &&
          FUN_00318ed0_btlVoice_typed(
              *(u32 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0x9f4),
              entry[1], &stack.secondPoint.x) != 0) {
        stack.center.x =
            (originX + stack.firstPoint.x + stack.secondPoint.x) / 3.0f -
            originX;
        stack.center.y =
            (originZ + stack.firstPoint.z + stack.secondPoint.z) / 3.0f -
            originZ;
        FUN_004c6b20_btlVoice_typed(&stack.center.x, &stack.center.x);
        stack.firstEdge.x = stack.firstPoint.x - originX;
        stack.firstEdge.y = stack.firstPoint.z - originZ;
        FUN_004c6b20_btlVoice_typed(&stack.firstEdge.x, &stack.firstEdge.x);
        stack.secondEdge.x = stack.secondPoint.x - originX;
        stack.secondEdge.y = stack.secondPoint.z - originZ;
        FUN_004c6b20_btlVoice_typed(&stack.secondEdge.x, &stack.secondEdge.x);
        stack.listenerEdge.x = listenerX - originX;
        stack.listenerEdge.y = listenerZ - originZ;
        FUN_004c6b20_btlVoice_typed(&stack.listenerEdge.x,
                                    &stack.listenerEdge.x);
        {
          f32 secondDot = stack.center.x * stack.secondEdge.x +
                          stack.center.y * stack.secondEdge.y;
          f32 listenerDot = stack.center.x * stack.listenerEdge.x +
                            stack.center.y * stack.listenerEdge.y;
          f32 firstDot = stack.center.x * stack.firstEdge.x +
                         stack.center.y * stack.firstEdge.y;
          if (firstDot <= secondDot && listenerDot <= secondDot) {
            firstResult = table[index * 4 + 2];
            secondResult = table[index * 4 + 3];
            break;
          }
        }
      }
      index = (index + 1) & 0xffff;
    }
  }
  if (param_1 != 0) {
    *param_1 = firstResult;
  }
  if (param_2 != 0) {
    *param_2 = secondResult;
  }
}

// FUN_002ecf80
u32 func_002ecf80(int param_1)
{
  u16 sVar1;
  s32 lVar2;
  u64 uVar3;
  float* pfVar4;
  f32 value;
  struct {
    u8 auStack_80[48];
    float afStack_50[3];
    u8 pad_44[4];
    u8 auStack_40[24];
    float afStack_28[2];
    float afStack_20[3];
    u8 pad_14[4];
    float afStack_10[3];
    short sStack_4;
    short sStack_2;
  } stack;

  if (((*(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x98) & 2) != 0) &&
     (lVar2 = FUN_00318d10(*(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x9f4),0x14,stack.auStack_80),
     lVar2 != 0)) {
    FUN_004c6be0(stack.afStack_20,&D_00697890,stack.auStack_80);
    stack.afStack_10[0] = stack.afStack_50[0] + stack.afStack_20[0];
    stack.afStack_10[1] = stack.afStack_50[1] + stack.afStack_20[1];
    stack.afStack_10[2] = stack.afStack_50[2] + stack.afStack_20[2];
    FUN_002d1de0(stack.auStack_40,stack.afStack_50,stack.afStack_10);
    FUN_0027f680(*(u32 *)(param_1 + 0x30),stack.auStack_40);
  }
  func_002ecc60(&stack.sStack_2, &stack.sStack_4);
  sVar1 = *(short *)(DAT_007ce3ec + 0xb56);
  switch (sVar1) {
  case 0:
    *(u32 *)(DAT_007ce3ec + 0xb5c) = 0;
    *(u16 *)(DAT_007ce3ec + 0xb56) = 1;
    *(s16 *)(DAT_007ce3ec + 0xb60) = -1;
    *(s16 *)(DAT_007ce3ec + 0xb62) = -1;
    *(u32 *)(DAT_007ce3ec + 0xb64) = 0;
    stack.afStack_28[0] = 405;
    stack.afStack_28[1] = 347;
    FUN_001ff3d0();
    FUN_001ff410(stack.afStack_28);
    break;
  case 1:
    if (*(float *)(DAT_007ce3ec + 0xb5c) < 3.0f) {
      FUN_00283c50(*(float *)(DAT_007ce3ec + 0xb5c),*(u32 *)(DAT_007ce3ec + 0xb44));
      lVar2 = *(u32 *)(DAT_007ce3ec + 0xb48);
      FUN_00283c50(*(float *)(DAT_007ce3ec + 0xb5c),lVar2);
      *(float *)(DAT_007ce3ec + 0xb5c) = *(float *)(DAT_007ce3ec + 0xb5c) + DAT_007cafec;
      if (*(float *)(DAT_007ce3ec + 0xb5c) > 3.0f) {
        *(float *)(DAT_007ce3ec + 0xb5c) = 3.0f;
      }
    }
    else {
      *(u16 *)(DAT_007ce3ec + 0xb56) = 2;
    }
    break;
  case 2:
    if (((DAT_007e094e[0] & 0x40) != 0) || ((DAT_007e0958[0] & 0x40) != 0)) {
      *(u16 *)(DAT_007ce3ec + 0xb56) = 3;
      FUN_001ff3f0();
      uVar3 = FUN_002dd5e0(1);
      FUN_0027ed20(uVar3,1);
    }
    break;
  case 3:
    if (stack.sStack_2 != -1) {
      *(short *)(DAT_007ce3ec + 0xb60) = stack.sStack_2;
      *(u16 *)(DAT_007ce3ec + 0xb62) = stack.sStack_4;
    }
    pfVar4 = (float *)(DAT_007ce3ec + 0xb5c);
    value = *pfVar4;
    if (value > DAT_007cafbc) {
      *pfVar4 = value - DAT_007cafbc;
    }
    else if (*(short *)(DAT_007ce3ec + 0xb60) != -1) {
      *pfVar4 = 0.0f;
    }
    else {
      *pfVar4 = DAT_007cafbc;
    }
    lVar2 = *(u32 *)(DAT_007ce3ec + 0xb44);
    FUN_00283c50(*(float *)(DAT_007ce3ec + 0xb5c),lVar2);
    lVar2 = *(u32 *)(DAT_007ce3ec + 0xb48);
    FUN_00283c50(*(float *)(DAT_007ce3ec + 0xb5c),lVar2);
    if ((*(float *)(DAT_007ce3ec + 0xb5c) == 0.0f) && (*(short *)(DAT_007ce3ec + 0xb60) != -1)) {
      return 1;
    }
    break;
  }
  if (((*(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x98) & 2) != 0) &&
     (*(float *)(DAT_007ce3ec + 0xb64) =
           (*(float *)(DAT_007ce3ec + 0xb5c) / 3.0f) * 0.5f + *(float *)(DAT_007ce3ec + 0xb64) + 0.0f,
     *(float *)(DAT_007ce3ec + 0xb64) >= 1.0f)) {
    uVar3 = FUN_002dd5e0(0);
    FUN_0027ed20(uVar3,1);
    *(u32 *)(DAT_007ce3ec + 0xb64) = 0;
  }
  return 0;
}

// FUN_002ed350
void func_002ed350(void)
{
    *(u16*)((u8*)gBtl + 0xb58) = 0;
}

// FUN_002ed360 NONMATCHING
u32 func_002ed360(u64 *param_1)

{
  /* Caller-specific ABI block: retail consumes the listed narrow results in this dispatcher. */
  extern u32 FUN_002baf90();
  extern s32 FUN_0027e390();
  extern s32 FUN_0030b5a0();
  extern u32 FUN_002b8f90();
  extern u32 FUN_002f87e0();
  extern u32 FUN_002bd480();
  extern u32 FUN_00284200();
  extern u32 FUN_002bd850();
  extern u32 FUN_002bdbd0();
  extern u32 FUN_002d7e20();
  extern u32 FUN_002d8090();
  extern u32 FUN_002f8810();
  extern u32 FUN_002dd760();
  extern u32 FUN_002875a0();
  extern u32 FUN_002bd590();
  extern u32 FUN_0027f410();
  extern u32 FUN_002dd4a0();
  extern u32 FUN_002b8d60();
  extern u32 FUN_002a3b40();
  extern u32 FUN_0029ec00();
  extern u32 FUN_0029ec50();
  extern u32 FUN_00285690();
  extern u32 FUN_00285d30();
  extern u32 FUN_002bb2f0();
  extern u32 FUN_002dd100();
  extern u32 FUN_002a3d70();
  extern u32 FUN_002db890();
  extern u32 FUN_002db800();
  extern s16 FUN_002838d0();
  u8 bVar1;
  int iVar2;
  u32 bVar3;
  u16 sVar4;
  u32 uVar5;
  int iVar6;
  BtlUnit *unitIter;
  u8 *puVar7;
  u8 *puVar8;
  u8 *puVar9;
  u8 *puVar10;
  int iVar11;
  int iVar12;
  s32 lVar13;
  u32 uVar14;
  u32 uVar15;
  u64 *puVar16;
  u32 uVar17;
  u64 uVar18;
  int iVar19;
  u64 unaff_s2;
  u32 uVar20;
  u64 uVar21;
  u16 sVar22;
  u32 auStack_18 [4];
  u32 uStack_8;
  u32 uStack_4;
  f32 uStack_48[3];
  f32 uStack_38[3];
  u32 uStack_28[3];
  
  puVar16 = (u64 *)param_1;
  uVar18 = *puVar16;
  sVar22 = *(short *)(DAT_007ce3ec + 0xb58);
  switch (sVar22) {
  case 0:
    for (unitIter = *(BtlUnit **)(DAT_007ce3ec + 0x158);
         unitIter != NULL; unitIter = unitIter->next) {
    if (unitIter->charId == 0x10a) {
      lVar13 = FUN_0030b5a0(unitIter->datUnit,0);
      if (lVar13 == 0) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      goto LAB_002ed420;
    }
  }
  bVar3 = false;
  LAB_002ed420:
  sVar22 = *(short *)(DAT_007ce3ec + 0xb54);
  switch (*(u16 *)(DAT_007ce3ec + 0xb54)) {
  case 0x16d:
    unaff_s2 = 0xe2;
    break;
  case 0x16e:
    unaff_s2 = 0xe3;
    break;
  case 0x16f:
    unaff_s2 = 0xe4;
    break;
  case 0x171:
    unaff_s2 = 0xe5;
    break;
  case 0x172:
    unaff_s2 = 0xe6;
  }
  *(u16 *)(DAT_007ce3ec + 0xb56) = 0;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb44) = uVar5;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb48) = uVar5;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb4c) = uVar5;
  *(short *)(*(int *)(DAT_007ce3ec + 0xb44) + 0xa4) = unaff_s2;
  *(u16 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0xa4) = 0xe7;
  *(u16 *)(*(int *)(DAT_007ce3ec + 0xb4c) + 0xa4) = 0xe8;
  uStack_28[0] = 0;
  uStack_28[1] = 0;
  uStack_28[2] = 0;
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb44),uStack_28);
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb48),uStack_28);
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb4c),uStack_28);
  FUN_0027f710(0.5f,*(u32 *)(DAT_007ce3ec + 0xb44));
  FUN_0027f710(0.5f,*(u32 *)(DAT_007ce3ec + 0xb48));
  FUN_0027f710((float)*(u16 *)(DAT_007ce418 + 0xd254) / 100.0,
               *(u32 *)(DAT_007ce3ec + 0xb4c));
  *(u32 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0x9d4) = 0;
  *(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x9d4) = 0;
  FUN_00352c50(*(u32 *)(DAT_007ce3ec + 0xb48),*(u32 *)(DAT_007ce3ec + 0xb44),
               *(u32 *)(DAT_007ce3ec + 0xb4c));
  for (uVar17 = 0; uVar17 < 3; uVar17 = uVar17 + 1) {
    uVar5 = FUN_002b8f90(0);
    auStack_18[uVar17] = uVar5;
    uVar14 = FUN_002f87e0(uVar17 + 2 & 0xffff);
    FUN_002b90d0(auStack_18[uVar17],uVar14);
  }
  uVar14 = FUN_002bd590(*(u32 *)(puVar16 + 6),sVar22);
  *(u64 *)((int)uVar14 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,3);
  if (bVar3) {
    uVar14 = FUN_0027f410(0x2ecc20,*(u32 *)(puVar16 + 6));
    *(u64 *)((int)uVar14 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
  }
  uVar14 = FUN_002dd4a0(sVar22,0);
  *(u64 *)((int)uVar14 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar15 = FUN_00284200(1.0f,*(u32 *)(puVar16 + 6),7,6,0);
  iVar6 = (int)uVar15;
  *(u64 *)(iVar6 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar15 = FUN_002b8d60(3,0xfff);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  uVar14 = uVar15;
  uVar15 = FUN_002a3b40(0,1);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)((u8 *)uVar14 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  uVar15 = FUN_002a3b40(param_1,0x11);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)((u8 *)uVar14 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  sVar4 = FUN_002838d0(1.0f,*(u32 *)(puVar16 + 6),0x18);
  uVar21 = *(u64 *)(iVar6 + 0x58);
  FUN_0029ea60(sVar22,&uStack_4,&uStack_8);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar21;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar15 = FUN_0029ec00(sVar22);
  FUN_0029ec80(sVar22,&uStack_4,&uStack_8);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar21;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar15 = FUN_0029ec50(sVar22);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar21;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar21;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar15 = FUN_00285690(*(u32 *)(DAT_007ce3ec + 0xb44),unaff_s2,0x1e);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar21;
  puVar7[0x10] = 4;
  *(u64 *)(puVar7 + 0x18) = *(u64 *)((int)uVar14 + 0x58);
  *(short *)(puVar7 + 0x48) = sVar4 + 6;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar14 = FUN_00285690(*(u32 *)(DAT_007ce3ec + 0xb48),0xe7,0x1e);
  puVar8 = (u8 *)uVar14;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar8 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_00285690(*(u32 *)(DAT_007ce3ec + 0xb4c),0xe8,0x1e);
  puVar9 = (u8 *)uVar14;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_00285d30(*(u32 *)(DAT_007ce3ec + 0xb44),0xffffffffffffffff,0,0,1,1);
  puVar10 = (u8 *)uVar14;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u16 *)(puVar10 + 0x48) = 2;
  *(u64 *)(puVar10 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_00285d30(*(u32 *)(DAT_007ce3ec + 0xb48),0xffffffffffffffff,0,0,1,1);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u16 *)(puVar7 + 0x48) = 2;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_00285d30(*(u32 *)(DAT_007ce3ec + 0xb4c),0xffffffffffffffff,0,0,1,1);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u16 *)(puVar7 + 0x48) = 2;
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_002bb2f0(*(u32 *)(DAT_007ce3ec + 0xca8),*(u32 *)(puVar16 + 6),0,
                        *(u64 *)(puVar9 + 0x58),0x300);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_002dd100(10,2,5);
  *(u8 *)uVar14 = 4;
  *(u64 *)((u8 *)uVar14 + 8) = *(u64 *)(iVar6 + 0x58);
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_002baf90(auStack_18[0],*(u32 *)(puVar16 + 6),*(u32 *)(puVar16 + 6),0,
                        0x200);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar8 + 0x58);
  puVar7[0x10] = 4;
  *(u64 *)(puVar7 + 0x18) = *(u64 *)(puVar9 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,2);
  uVar14 = FUN_002f8810();
  uVar14 = FUN_002dd760(3,uVar14,0);
  *(u8 *)uVar14 = 5;
  *(u64 *)((u8 *)uVar14 + 8) = *(u64 *)(puVar7 + 0x58);
  FUN_0027ed20(uVar14,1);
  if (*(int *)(DAT_007ce3ec + 0xb68) == 0) {
    uVar14 = FUN_002db890();
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x28;
    FUN_0027ed20(uVar14,1);
    uVar14 = FUN_002db800(0x20,0x26);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x28;
    FUN_0027ed20(uVar14,1);
    *(u32 *)(DAT_007ce3ec + 0xb68) = 1;
  }
  else if ((sVar22 == 0x171) && (*(int *)(DAT_007ce3ec + 0xb6c) == 0)) {
    uVar14 = FUN_002db890();
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x34;
    FUN_0027ed20(uVar14,1);
    uVar14 = FUN_002db800(0x20,0x28);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x34;
    FUN_0027ed20(uVar14,1);
    *(u32 *)(DAT_007ce3ec + 0xb6c) = 1;
  }
  else if ((sVar22 == 0x172) && (*(int *)(DAT_007ce3ec + 0xb70) == 0)) {
    uVar14 = FUN_002db890();
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x34;
    FUN_0027ed20(uVar14,1);
    uVar14 = FUN_002db800(0x20,0x29);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u16 *)(puVar8 + 0x48) = 0x34;
    FUN_0027ed20(uVar14,1);
    *(u32 *)(DAT_007ce3ec + 0xb70) = 1;
  }
  uVar14 = FUN_002baf90(auStack_18[1],*(u32 *)(puVar16 + 6),*(u32 *)(puVar16 + 6),0,
                        0x200);
  puVar8 = (u8 *)uVar14;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar8 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,2);
  uStack_38[0] = DAT_007cafd4;
  uStack_38[1] = DAT_007cafd8;
  uStack_38[2] = DAT_007cafdc;
  uStack_48[0] = DAT_007cafe0;
  uStack_48[1] = DAT_007cafe4;
  uStack_48[2] = DAT_007cafe8;
  uVar14 = FUN_002a3d70(1.0f,param_1,0,0,uStack_38,uStack_48);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  uVar14 = FUN_0027f410(0x2ecf80,param_1);
  puVar8 = (u8 *)uVar14;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u16 *)(puVar8 + 0x48) = 0x1a;
  *(u16 *)(puVar8 + 0x4a) = 0x1e;
  *(u64 *)(puVar8 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  if (bVar3) {
    uVar14 = FUN_0027f410(0x2ecbe0,*(u32 *)(puVar16 + 6));
    puVar7 = (u8 *)uVar14;
    *puVar7 = 4;
    *(u64 *)(puVar7 + 8) = *(u64 *)(puVar8 + 0x58);
    *(u64 *)(puVar7 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
  }
  uVar14 = FUN_002baf90(auStack_18[2],*(u32 *)(puVar16 + 6),*(u32 *)(puVar16 + 6),0,
                        0x200);
  puVar7 = (u8 *)uVar14;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,2);
  uVar14 = FUN_002f8810();
  uVar14 = FUN_002dd760(3,uVar14,1);
  puVar8 = (u8 *)uVar14;
  *puVar8 = 5;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar8 + 0x60) = uVar18;
  FUN_0027ed20(uVar14,1);
  puVar8 = (u8 *)uVar14;
  *puVar8 = 5;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar8 + 0x60) = uVar18;
  *(u16 *)(puVar8 + 0x48) = 0x1e;
  FUN_0027ed20(uVar14,1);
  for (uVar17 = 0; uVar17 < 3; uVar17 = uVar17 + 1) {
    FUN_002b9030(auStack_18[uVar17]);
  }
    *(u16 *)(DAT_007ce3ec + 0xb58) = 2;
    break;
  case 2:
    FUN_00352c50(*(u32 *)(DAT_007ce3ec + 0xb48),*(u32 *)(DAT_007ce3ec + 0xb44),
                 *(u32 *)(DAT_007ce3ec + 0xb4c));
  lVar13 = FUN_0027e390(*puVar16,0x3fffffffffffffff);
  if (lVar13 == 0) {
    *(u16 *)((int)puVar16 + 0x6c) = 2;
    *(u16 *)((int)puVar16 + 0x6e) = *(u16 *)(DAT_007ce3ec + 0xb60);
    FUN_002c3770(param_1,0);
    FUN_002d6620(param_1);
    for (uVar17 = 0; uVar17 < 2; uVar17 = uVar17 + 1) {
      uVar5 = FUN_002b8f90(0);
      auStack_18[uVar17] = uVar5;
      uVar14 = FUN_002f87e0(uVar17 + 5 & 0xffff);
      FUN_002b90d0(auStack_18[uVar17],uVar14);
    }
    uVar14 = FUN_002baf90(auStack_18[0],*(u32 *)(puVar16 + 6),*(u32 *)(puVar16 + 6),
                          0,0x200);
    iVar6 = (int)uVar14;
    *(u64 *)(iVar6 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,2);
    puVar7 = (u8 *)uVar14;
    *puVar7 = 5;
    *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
    *(u64 *)(puVar7 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
    sVar22 = 0;
    for (uVar17 = 0; uVar17 < *(u16 *)((int)puVar16 + 0x6a); uVar17 = uVar17 + 1) {
      iVar2 = *(int *)((int)puVar16 + uVar17 * 4 + 0x38);
      bVar1 = *(u8 *)(iVar2 + 200);
      uVar14 = FUN_002bd480(*(u32 *)(iVar2 + 0x30));
      *(u64 *)((int)uVar14 + 0x60) = uVar18;
      FUN_0027ed20(uVar14,1);
      uVar14 = FUN_002baf90(auStack_18[0],*(u32 *)(puVar16 + 6),
                            *(u32 *)(iVar2 + 0x30),1,0x200);
      iVar11 = (int)uVar14;
      *(short *)(iVar11 + 0x48) = sVar22;
      *(u64 *)(iVar11 + 0x60) = uVar18;
      FUN_0027ed20(uVar14,2);
      uVar20 = 0;
      while (uVar20 < (u32)bVar1) {
        iVar19 = (int)uVar20;
        uVar14 = FUN_00284200(1.0f,*(u32 *)(iVar2 + 0x30),
                              *(u8 *)(iVar2 + iVar19 * 0x1c + 0xf8),0,0);
        puVar7 = (u8 *)uVar14;
        *puVar7 = 0xb;
        *(u64 *)(puVar7 + 8) = *(u64 *)(iVar11 + 0x58);
        *(u64 *)(puVar7 + 0x60) = uVar18;
        FUN_0027ed20(uVar14,1);
        if (((uVar17 == 0) && (uVar20 == 0)) && (*(short *)(DAT_007ce3ec + 0xb62) != -1)) {
          uVar14 = FUN_002bd850(*(u32 *)(puVar16 + 6), *(short *)(DAT_007ce3ec + 0xb62));
          puVar8 = (u8 *)uVar14;
          *puVar8 = 0xb;
          *(u64 *)(puVar8 + 8) = *(u64 *)(iVar11 + 0x58);
          *(u64 *)(puVar8 + 0x60) = uVar18;
          FUN_0027ed20(uVar14,3);
        }
        iVar12 = iVar2 + iVar19 * 0x1c + 0xe0;
        uVar14 = FUN_002bdbd0(*(u32 *)(puVar16 + 6),*(u32 *)(iVar2 + 0x30),
                              *(u16 *)((int)puVar16 + 0x6e),*(u16 *)(iVar2 + 0xcc),
                              *(u16 *)(iVar2 + 0xce),uVar20 & 0xffff,(u32)bVar1,iVar12);
        puVar8 = (u8 *)uVar14;
        *puVar8 = 5;
        *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
        *(u64 *)(puVar8 + 0x60) = uVar18;
        FUN_0027ed20(uVar14,3);
        uVar14 = FUN_002d7e20(param_1,iVar2,iVar12,*(u16 *)(iVar2 + 0xcc),
                              *(u16 *)(iVar2 + 0xce));
        puVar8 = (u8 *)uVar14;
        *puVar8 = 5;
        *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
        *(u64 *)(puVar8 + 0x60) = uVar18;
        FUN_0027ed20(uVar14,1);
        uVar14 = FUN_002d8090(iVar2);
        puVar8 = (u8 *)uVar14;
        *puVar8 = 5;
        *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
        *(u64 *)(puVar8 + 0x60) = uVar18;
        FUN_0027ed20(uVar14,1);
        uVar20 = (u32)(iVar19 + 1);
      }
      sVar22 = sVar22 + 1;
    }
    lVar13 = FUN_002baf90(auStack_18[1],*(u32 *)(puVar16 + 6),*(u32 *)(puVar16 + 6),
                          0,0x200);
    puVar7 = (u8 *)lVar13;
    *puVar7 = 4;
    *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
    if (lVar13 != 0) {
      puVar7[0x10] = 4;
      *(u64 *)(puVar7 + 0x18) = *(u64 *)(puVar7 + 0x58);
    }
    *(u64 *)(puVar7 + 0x60) = uVar18;
    FUN_0027ed20(lVar13,2);
    uVar14 = FUN_002f8810();
    uVar14 = FUN_002dd760(3,uVar14,2);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 5;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    *(u64 *)(puVar8 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 4;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    puVar8[0x47] = puVar8[0x47] & 0xdf;
    *(u64 *)(puVar8 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 4;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    puVar8[0x47] = puVar8[0x47] & 0xdf;
    *(u64 *)(puVar8 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 4;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    puVar8[0x47] = puVar8[0x47] & 0xdf;
    *(u64 *)(puVar8 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,1);
    puVar8 = (u8 *)uVar14;
    *puVar8 = 4;
    *(u64 *)(puVar8 + 8) = *(u64 *)(puVar7 + 0x58);
    puVar8[0x47] = puVar8[0x47] & 0xdf;
    *(u64 *)(puVar8 + 0x60) = uVar18;
    FUN_0027ed20(uVar14,0);
    for (uVar17 = 0; uVar17 < 2; uVar17 = uVar17 + 1) {
      FUN_002b9030(auStack_18[uVar17]);
    }
    *(u16 *)(DAT_007ce3ec + 0xb58) = 3;
    }
    break;
  case 3:
    FUN_00352c50(*(u32 *)(DAT_007ce3ec + 0xb48),*(u32 *)(DAT_007ce3ec + 0xb44),
                 *(u32 *)(DAT_007ce3ec + 0xb4c));
  lVar13 = FUN_0027e390(*puVar16,0x3fffffffffffffff);
  if (lVar13 == 0) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfff7ffff;
    FUN_002878d0(*(u32 *)(DAT_007ce3ec + 0xb44));
    FUN_002878d0(*(u32 *)(DAT_007ce3ec + 0xb48));
    FUN_002878d0(*(u32 *)(DAT_007ce3ec + 0xb4c));
    *(u32 *)(DAT_007ce3ec + 0xb44) = 0;
    *(u32 *)(DAT_007ce3ec + 0xb48) = 0;
    *(u32 *)(DAT_007ce3ec + 0xb4c) = 0;
    FUN_00352c50(0,0,0);
    return 0;
    }
    break;
  }
  return 1;
}

/* W212: template 002f3320's packet-local structure is already present. Recasting the unit search as retail's explicit do/while held nd444 but shrank 968 to 960 (window 976), so it was reverted; residual first differs at offset 28 as cyclic saved-register coloring, then at offset 292 in the search dispatch. */
// FUN_002ee640 NONMATCHING
void func_002ee640(BtlAction* action)
{
  BtlUnit* unit;
  BtlUnit* other;
  void* object;
  BtlPacket* parent;
  BtlPacket* packet;

  gBtl->flags &= ~0x02000000;
  gBtl->flags |= 0x00080000;
  unit = action->unit;
  other = NULL;
  unit->packetCount++;
  object = func_002b8f90(0);
  switch (unit->charId) {
  case 0x10a:
    func_002b90d0(object, func_002f87e0(7));
    packet = FUN_002dd690_packet_voice(3, (const char*)D_00699FE0);
    btlPacketRegister(packet, 1);
    break;
  case 0x109:
    func_002b90d0(object, func_002f87e0(8));
    packet = FUN_002dd690_packet_voice(3, (const char*)D_00699FF0);
    btlPacketRegister(packet, 1);
    break;
  }
  if (unit->charId == 0x10a) {
    for (other = gBtl->unitLists[UNIT_GENUS_EC].head;
         other != NULL && other->charId != 0x109;
         other = other->next) {
    }
  }
  parent = FUN_00284200_packet_voice(1.0f, unit, 0x12, 0, 2);
  parent->preUpdateDelay = 2;
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(3, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(unit, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  if (other != NULL) {
    parent = FUN_002baf90_packet_voice(object, other, other, 1, 0x200);
    parent->actionUID = action->uid;
    btlPacketRegister(parent, 2);
    packet = FUN_002dd830_packet_voice(other, 10, 0, 7);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->actionUID = action->uid;
    packet->preUpdateDelay = 0x96;
    btlPacketRegister(packet, 1);
    packet = FUN_0027f410_packet_voice((u32)func_002ecc20, (u32)other);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 8;
    packet->actionUID = action->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_00284200_packet_voice(1.0f, other, 0, 0, 1);
    packet->unk_00 = 5;
    packet->parentUID = parent->uid;
    packet->preUpdateDelay = 8;
    btlPacketRegister(packet, 1);
  }
  func_002b9030(object);
}

// FUN_002eea10
u32 func_002eea10(BtlAction* action)
{
    BtlPacket* packet;

    if (action != btlActionCurrent())
    {
        if ((action->unit->flags3 & BTLUNIT_FLAG3_ENDURE) != 0)
        {
            return 1;
        }
    }
    else
    {
        action->unit->flags3 &= ~BTLUNIT_FLAG3_ENDURE;
    }

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        FUN_002d7890(action, 0);
        FUN_0029a320(action);
        action->unit->packetCount--;
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002eeb70
void func_002eeb70(BtlAction* action)
{
    BtlUnit* unit;

    if ((action->unk_1a & 1) != 0)
    {
        unit = action->unit;
        if (unit->genus == 1)
        {
            switch (unit->charId)
            {
                case 0x10b:
                case 0x10c:
                    action->unk_1a |= 0x10;
                    unit->flags3 |= 0x100;
                    unit->flags3 |= 0x40;
                    unit->flags3 |= 0x80;
                    unit->datUnit->flags |= 0x40;
                    break;
            }
            switch (unit->charId)
            {
                case 0x10b:
                    FUN_00288f80(unit, 0xd0);
                    break;
                case 0x10c:
                    FUN_00288f80(unit, 0xd1);
                    break;
            }
        }
    }
}

// FUN_002eec60
void func_002eec60(void)

{
  typedef struct {
    u32 data[6];
    s16 ids[4];
    RwV3d position;
  } VoicePositionWork;
  typedef struct {
    s16 a;
    s16 b;
    s16 c;
  } VoiceIds;
  VoicePositionWork work;
  u32 uVar1;
  u32 uVar2;
  int iVar4;
  u32 *puVar6;
  u32 *puVar5;
  int copyCount;
  int iVar3;
  s16 sVar7;
  puVar6 = (u32*)DAT_0069a000_abs;

  puVar5 = work.data;
  copyCount = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    copyCount = copyCount + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < copyCount);
  *(VoiceIds *)&work.ids[0] = *(VoiceIds *)&DAT_007cc9b0_s16;
  sVar7 = 0;
  work.position.y = 0.0f;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      work.position.x = 150.0f;
      work.position.z = 350.0f;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      work.position.x = *(f32*)((u8*)&work + iVar3 * 8);
      work.position.z = *(f32*)((u8*)&work + iVar3 * 8 + 4);
      *(u8 *)(iVar4 + 0x9f0) = (u8)work.ids[iVar3];
      sVar7++;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&work.position.x);
    FUN_0027f650(iVar4,&work.position.x);
  }
  for (iVar3 = *(int *)(DAT_007ce3ec + 0x158); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xa34)) {
    switch (*(u16 *)(iVar3 + 0xa4)) {
    case 0x10b:
      work.position.x = -200.0f;
      work.position.z = -350.0f;
      break;
    case 0x10c:
      work.position.x = 200.0f;
      work.position.z = -350.0f;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar3 + 0x94,iVar3 + 0x96,&work.position.x);
    FUN_0027f650(iVar3,&work.position.x);
  }
  return;
}

// FUN_002eee20
u32 func_002eee20(BtlAction* action, f32* position)
{
  BtlUnit* unit;
  BtlUnit* target;
  RwV3d sourcePosition;
  RwV3d targetPosition;
  RwV3d direction;
  u16 moveId;
  f32 distance;
  u32 result;

  unit = action->unit;
  if (unit->genus != UNIT_GENUS_EC) {
    result = 0;
  }
  else {
    if (unit->charId != 0x10c) {
      result = 0;
    }
    else {
      if (action->target.targetedCount != 1) {
        result = 0;
      }
      else {
        if (action->target.commandId != 2) {
          result = 0;
        }
        else {
          if ((*(u8 *)(DAT_007ce3f8 + action->target.specificId * 0x2c) & 2) == 0) {
            result = 0;
          }
          else {
            target = action->target.targetedActions[0]->unit;
            FUN_00280050(unit, &sourcePosition);
            FUN_00280480(target, unit, &targetPosition);
            direction.x = sourcePosition.x - targetPosition.x;
            direction.z = sourcePosition.z - targetPosition.z;
            direction.y = 0.0f;
            FUN_004c69f0(&direction, &direction);
            if (FUN_002d5e10(action) != 0) {
              moveId = 0xb;
            }
            else {
              moveId = 4;
            }
            distance = FUN_002812d0(unit, target, moveId);
            direction.x *= distance;
            direction.y *= distance;
            direction.z *= distance;
            position[0] = targetPosition.x + direction.x;
            position[1] = targetPosition.y + direction.y;
            position[2] = targetPosition.z + direction.z;
            result = 1;
          }
        }
      }
    }
  }
  return result;
}

// FUN_002ef000
void func_002ef000(BtlAction* action)
{
  BtlUnit* unit;
  void* object;
  BtlPacket* parent;
  BtlPacket* packet;
  s32 state;

  gBtl->flags &= ~0x02000000;
  gBtl->flags |= 0x00080000;
  unit = action->unit;
  switch (unit->charId) {
  case 0x10b:
    state = 2;
    packet = (BtlPacket*)func_002e2cb0(0x2ff);
    packet->preUpdateDelay = 3;
    btlPacketRegister(packet, 1);
    break;
  case 0x10c:
    state = 3;
    packet = (BtlPacket*)func_002e2cb0(0x312);
    packet->preUpdateDelay = state;
    btlPacketRegister(packet, 1);
    break;
  }
  object = func_002b8f90(0);
  func_002b90d0(object, func_002f87e0(state));
  parent = FUN_00284200_packet_voice(1.0f, unit, 0x12, 0, 2);
  parent->preUpdateDelay = 3;
  parent->actionUID = action->uid;
  btlPacketRegister(parent, 1);
  packet = FUN_002b8d60_packet_voice(1, 0xfff);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_0027fe90_packet_voice(unit, NULL, D_006978B0, NULL);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 1);
  packet = FUN_002a3b40_packet_voice(NULL, 1);
  packet->unk_00 = 4;
  packet->parentUID = parent->uid;
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 0);
  packet = FUN_002baf90_packet_voice(object, unit, unit, 0, 0x200);
  packet->actionUID = action->uid;
  btlPacketRegister(packet, 2);
  func_002b9030(object);
}

// FUN_002ef250
u32 func_002ef250(BtlAction* action)
{
    BtlPacket* packet;

    if (btlPacketFindFirstByActionUID(action->uid, BTL_UIDMAX) == NULL)
    {
        gBtl->flags &= ~0x80000;
        FUN_002d7890(action, 0);
        FUN_0029a320(action);
        gBtl->flags |= 0x2000000;

        packet = FUN_0029fa50(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a1080(0x10, 4);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        packet = FUN_002a16c0(0x10);
        btlPacketRegister(packet, BTLPACKET_TYPE_1);
        return 0;
    }

    return 1;
}

// FUN_002ef360
void func_002ef360(void)
{
  typedef struct {
    u32 data[6];
    s16 ids[4];
    RwV3d position;
  } VoicePositionWork;
  typedef struct {
    s16 a;
    s16 b;
    s16 c;
  } VoiceIds;
  VoicePositionWork work;
  u32 uVar1;
  u32 uVar2;
  int iVar4;
  u32 *puVar6;
  u32 *puVar5;
  int copyCount;
  int iVar3;
  s16 sVar7;

  puVar6 = (u32*)DAT_0069a060;
  puVar5 = work.data;
  copyCount = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    copyCount = copyCount + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < copyCount);
  *(VoiceIds *)&work.ids[0] = *(VoiceIds *)&DAT_007cc9b8_s16;
  sVar7 = 0;
  work.position.y = 0.0f;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0;
       iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(u16 *)(iVar4 + 0xa4) == 1) {
      work.position.x = 150.0f;
      work.position.z = 500.0f;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      work.position.x = *(f32*)((u8*)&work + iVar3 * 8);
      work.position.z = *(f32*)((u8*)&work + iVar3 * 8 + 4);
      *(u8 *)(iVar4 + 0x9f0) = (u8)work.ids[iVar3];
      sVar7++;
    }
    FUN_002d2280(iVar4 + 0x94, iVar4 + 0x96, &work.position.x);
    FUN_0027f650(iVar4, &work.position.x);
  }
  for (iVar3 = *(int *)(DAT_007ce3ec + 0x158); iVar3 != 0;
       iVar3 = *(int *)(iVar3 + 0xa34)) {
    switch (*(u16 *)(iVar3 + 0xa4)) {
    case 0x10d:
      work.position.x = 0.0f;
      work.position.z = -500.0f;
      break;
    case 0x116:
      work.position.x = -250.0f;
      work.position.z = -450.0f;
      break;
    case 0x117:
      work.position.x = 0.0f;
      work.position.z = -200.0f;
      break;
    case 0x118:
      work.position.x = 250.0f;
      work.position.z = -450.0f;
      break;
    case 0x119:
      work.position.x = -250.0f;
      work.position.z = 100.0f;
      break;
    case 0x127:
      work.position.x = 250.0f;
      work.position.z = 100.0f;
      break;
    default:
      break;
    }
    FUN_002d2280(iVar3 + 0x94, iVar3 + 0x96, &work.position.x);
    FUN_0027f650(iVar3, &work.position.x);
  }
}

// FUN_002ef5a0
void func_002ef5a0(void)
{
    BtlUnit* unit;

    for (unit = *(BtlUnit**)(DAT_007ce3ec + 0x158); unit != NULL; unit = unit->next)
    {
        switch (unit->charId)
        {
            case 0x10d:
                FUN_002d3fe0(unit);
                ((u8*)unit->mdl)[0x388] |= 0x20;
                ((u8*)unit->mdl)[0x388] |= 0x80;
                break;
            case 0x119:
                *(u32*)(DAT_007ce3ec + 0xb58) = 0;
                ((u8*)unit->mdl)[0x41d] = 0;
                break;
            case 0x127:
                *(u32*)(DAT_007ce3ec + 0xb5c) = 0;
                ((u8*)unit->mdl)[0x41d] = 0;
                break;
        }
    }
}

#pragma opt_loop_invariants on
// FUN_002ef670
void func_002ef670(void)
{
  BtlUnit* target;
  void* object;
  BtlPacket* packet;
  BtlUnit* unit;
  BtlUnit* args[3];
  s16 count;
  u32 raw;

  object = (void*)FUN_002b8f90_u32_voice(0);
  FUN_002b90d0(object, (void*)FUN_002f87e0_u32_voice(1));
  count = 0;
  target = NULL;
  args[0] = NULL;
  args[1] = NULL;
  args[2] = NULL;
  for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
       unit != NULL; unit = unit->next) {
    switch (unit->charId) {
    case 1:
      target = unit;
      break;
    default:
      args[2 - count] = unit;
      count++;
      break;
    }
  }
  raw = FUN_002bc950_u32_voice(args[0], args[1], args[2]);
  FUN_0027ed20_voice(raw, 1);
  packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
  FUN_0027ed20_voice((u32)packet, 2);
  raw = FUN_002bc950_u32_voice(NULL, NULL, NULL);
  *(u8*)raw = 4;
  *(u64*)((u8*)raw + 8) = *(u64*)((u8*)packet + 0x58);
  FUN_0027ed20_voice(raw, 1);
  FUN_002b9030(object);
}
#pragma opt_loop_invariants off

/* Removing this loses FUN_002ef7e0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002ef7e0
void func_002ef7e0(void)
{
    BtlUnit* target;
    void* object;
    BtlPacket* parent;
    BtlUnit* unit;
    BtlPacket* packet;

    gBtl->flags &= ~0x02000000;
    object = func_002b8f90(0);
    func_002b90d0(object, func_002f87e0(9));
    target = NULL;
    for (unit = gBtl->unitLists[UNIT_GENUS_EC].head;
         unit != NULL; unit = unit->next) {
        switch (unit->charId) {
        case 0x10d:
            target = unit;
            break;
        }
    }
    packet = FUN_002dd690_packet_voice(3, DAT_0069a0f8);
    btlPacketRegister(packet, 1);
    parent = FUN_00284200_packet_voice(1.0f, target, 0x12, 0, 2);
    parent->preUpdateDelay = 2;
    btlPacketRegister(parent, 1);
    packet = FUN_002b8d60_packet_voice(3, 0xfff);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_0027fe90_packet_voice(target, NULL, D_006978B0, NULL);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 1);
    packet = FUN_002a3b40_packet_voice(NULL, 1);
    packet->unk_00 = 4;
    packet->parentUID = parent->uid;
    btlPacketRegister(packet, 0);
    packet = FUN_002baf90_packet_voice(object, target, target, 0, 0x200);
    btlPacketRegister(packet, 2);
    func_002b9030(object);
}
#pragma opt_loop_invariants off

// FUN_002ef9d0
int func_002ef9d0(void)
{
  /* Caller-specific return width: retail consumes only the s32 result in this path. */
  extern s32 FUN_0030b5a0();
  BtlUnit* enemy;
  BtlAction* action;
  s32 found;
  BtlUnit* unit;
  BtlPacket* packet;
  u32 data[8];

  found = 0;
  for (enemy = gBtl->unitLists[UNIT_GENUS_EC].head;
       enemy != NULL; enemy = enemy->next) {
    if (enemy->charId == 0x10d &&
        FUN_0030b5a0(enemy->datUnit, 0) != 0) {
      found = 1;
      break;
    }
  }
  if (found != 0) {
    FUN_002d5dc0(data);
    data[0] = 0xfff00001;
    for (action = gBtl->actionList.tail;
         action != NULL; action = action->prev) {
      if ((action->unk_1a & 1) != 0) {
        unit = action->unit;
        if (unit->genus == UNIT_GENUS_EC &&
            unit->charId != 0x10d &&
            FUN_0030b5a0(unit->datUnit, 0) == 0) {
          packet = FUN_002d7e20_packet_voice(action, action, data, 1, 1);
          FUN_0027ed20_voice((u32)packet, 1);
          packet = FUN_00284200_packet_voice(1.0f, unit, 2, 0, 0);
          FUN_0027ed20_voice((u32)packet, 1);
        }
      }
    }
  }
  return found;
}

// FUN_002efb40
void func_002efb40(BtlUnit* unit)
{
    u8* value;

    if (unit->genus == 1 && (unit->flags2 & 2) != 0)
    {
        switch (unit->charId)
        {
            case 0x119:
            case 0x127:
                if (datCalcChkBadStatus(unit->datUnit, 0x400) != 0)
                {
                    *(u32*)(((unit->charId != 0x119) << 2) + DAT_007ce3ec + 0xb58) = 1;
                }
                else
                {
                    *(u32*)(((unit->charId != 0x119) << 2) + DAT_007ce3ec + 0xb58) = 0;
                }
                if (*(u32*)(((unit->charId != 0x119) << 2) + DAT_007ce3ec + 0xb58) != 0)
                {
                    value = (u8*)unit->mdl + 0x41d;
                    if (*value < 0xdf)
                    {
                        *value += 0x20;
                    }
                    else
                    {
                        *value = 0xff;
                    }
                }
                else
                {
                    value = (u8*)unit->mdl + 0x41d;
                    if (*value > 0x20)
                    {
                        *value -= 0x20;
                    }
                    else
                    {
                        *value = 0;
                    }
                }
                break;
        }
    }
}

// FUN_002efc90
void func_002efc90(u32 param_1)

{
  func_002e4220((u32)func_002efe50,(u32)func_002f0580,param_1);
  return;
}

// FUN_002efcd0
void func_002efcd0(u32 param_1)

{
  func_002e4220((u32)func_002f05f0,(u32)func_002f0e30,param_1);
  return;
}

// FUN_002efd10
u32 func_002efd10(void)

{
  return *(u32 *)(DAT_007ce3ec + 0xb54);
}

// FUN_002efd20
u32 func_002efd20(BtlUnit* unit)

{
  BtlAction* action;
  
  action = FUN_0029a1d0(unit);
  *(u32 *)(DAT_007ce3ec + 0xb54) = 0;
  action->unk_1a &= 0xfff7;
  FUN_00300560(unit->datUnit,0x100000);
  FUN_002831c0(unit,6);
  FUN_002d3fe0(unit);
  if ((unit->flags2 & 2) != 0) {
    *((u8*)unit->mdl + 0x388) |= 0x20;
  }
  return 1;
}

// FUN_002efdb0
u32 func_002efdb0(BtlUnit* unit)

{
  BtlAction* action;
  
  action = FUN_0029a1d0(unit);
  *(u32 *)(DAT_007ce3ec + 0xb54) = 1;
  action->unk_1a |= 8;
  FUN_003004f0(unit->datUnit,0x100000);
  FUN_002831c0(unit,6);
  FUN_002d3e00(unit,0);
  if ((unit->flags2 & 2) != 0) {
    *((u8*)unit->mdl + 0x388) &= 0xdf;
  }
  return 1;
}

// FUN_002efe50 NONMATCHING
void func_002efe50(u64 *param_1)

{
  u16 uVar1;
  short sVar2;
  u64 *puVar3;
  u32 uVar4;
  short sVar5;
  int iVar6;
  u8 *puVar7;
  u64 *puVar8;
  u8 *puVar9;
  u8 *puVar10;
  u32 uVar11;
  u32 uVar12;
  u64 uVar13;
  u64 uVar14;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_8;
  u32 uStack_4;
  
  uVar1 = *(u16 *)((int)param_1 + 0x6e);
  uVar14 = *param_1;
  sVar2 = *(short *)((int)param_1 + 0x76);
  uVar11 = FUN_002b8f90_u32_voice(0);
  if (sVar2 == 0x119) {
    uVar12 = FUN_002f87e0_u32_voice(7);
    FUN_002b90d0(uVar11,uVar12);
  }
  else {
    uVar12 = FUN_002f87e0_u32_voice(8);
    FUN_002b90d0(uVar11,uVar12);
  }
  uVar12 = (u32)FUN_002bd590_packet_voice((BtlUnit *)*(u32 *)(param_1 + 6),uVar1);
  *(u64 *)((int)uVar12 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,3);
  uVar12 = (u32)FUN_00284200_packet_voice(1.0f,(BtlUnit *)*(u32 *)(param_1 + 6),7,6,2);
  iVar6 = (int)uVar12;
  *(u64 *)(iVar6 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  sVar5 = FUN_002838d0(1.0f,*(u32 *)(param_1 + 6),7);
  uVar13 = *(u64 *)(iVar6 + 0x58);
  uVar12 = (u32)FUN_002b8d60_packet_voice(3,0xfff);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = (u32)FUN_0027fe90_packet_voice((BtlUnit *)*(u32 *)(param_1 + 6),0,(const void *)0x6978b0,0);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = (u32)FUN_002a3b40_packet_voice(0,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = (u32)FUN_002a3b40_packet_voice(param_1,0x11);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = (u32)FUN_002822b0_packet_voice((BtlUnit *)*(u32 *)(param_1 + 6),(RwV3d *)&uStack_18,0);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  for (puVar3 = *(u64 **)(DAT_007ce3ec + 0x14c); puVar3 != (u64 *)0x0;
      puVar3 = *(u64 **)(puVar3 + 0x95)) {
    if ((param_1 != puVar3) && ((*(u16 *)((int)puVar3 + 0x1a) & 1) != 0)) {
      uVar12 = (u32)FUN_00285d30_packet_voice((BtlUnit *)*(u32 *)(puVar3 + 6),0xffffff,0,0,2,0);
      puVar7 = (u8 *)uVar12;
      *puVar7 = 4;
      *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
      *(u64 *)(puVar7 + 0x60) = uVar14;
      FUN_0027ed20(uVar12,0);
    }
  }
  FUN_0029ea60(uVar1,&uStack_4,&uStack_8);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = FUN_0029ec00_u32_voice(uVar1);
  FUN_0029ec80(uVar1,&uStack_4,&uStack_8);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = FUN_0029ec50_u32_voice(uVar1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = FUN_002ff540(*(u32 *)(DAT_007ce3ec + 0xbbc),sVar2);
  uVar4 = *(u32 *)(puVar8 + 6);
  FUN_002889c0(uVar4,sVar2);
  FUN_002b71e0();
  uStack_18 = 0;
  uStack_14 = 0xc47a0000;
  uStack_10 = 0;
  FUN_0027f650(uVar4,&uStack_18);
  FUN_00352c50(uVar4,0,0);
  uVar12 = (u32)FUN_00285690_packet_voice((BtlUnit *)uVar4,sVar2,0x7e);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(short *)(puVar7 + 0x48) = sVar5 + 6;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = (u32)FUN_002baf90_packet_voice((void *)uVar11,(BtlUnit *)*(u32 *)(param_1 + 6),(BtlUnit *)uVar4,0,0x200);
  puVar9 = (u8 *)uVar12;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar9 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,2);
  uVar12 = (u32)FUN_00285d30_packet_voice((BtlUnit *)uVar4,0xffffffff,0,0,1,1);
  puVar10 = (u8 *)uVar12;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u16 *)(puVar10 + 0x48) = 1;
  *(u64 *)(puVar10 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = (u32)FUN_002a3b40_packet_voice(param_1,0x25);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u16 *)(puVar7 + 0x4a) = 0x1e;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  for (puVar3 = *(u64 **)(DAT_007ce3ec + 0x14c); puVar3 != (u64 *)0x0;
      puVar3 = *(u64 **)(puVar3 + 0x95)) {
    if (((param_1 != puVar3) && (param_1 != puVar8)) && ((*(u16 *)((int)puVar3 + 0x1a) & 1) != 0)
       ) {
      uVar12 = (u32)FUN_00285d30_packet_voice((BtlUnit *)*(u32 *)(puVar3 + 6),0xffffffff,0,0,1,0);
      puVar7 = (u8 *)uVar12;
      *puVar7 = 4;
      *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
      *(u64 *)(puVar7 + 0x60) = uVar14;
      FUN_0027ed20(uVar12,0);
    }
  }
  FUN_001fdd40();
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar9 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  FUN_002b9030(uVar11);
  return;
}

