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
extern u8 DAT_0069a470[];
extern u8 DAT_0069a4f0[];
extern u8 DAT_0069a550[];
extern u8 DAT_0069a5c8[];
extern u32 DAT_0069a5cc;
extern u32 DAT_0069a5d0;
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
extern u64 FUN_002812d0();
extern u64 FUN_002822b0();
extern u64 FUN_002831c0();
extern u64 FUN_002835e0();
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
extern u64 FUN_002e4250();
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
extern u64 FUN_0035c090();
extern u64 FUN_00395170();
extern u64 FUN_003951d0();
extern u64 FUN_004c69f0();
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
void func_002f05f0(u64 *param_1)

{
  u16 uVar1;
  u64 *puVar2;
  u32 uVar3;
  int iVar4;
  u8 *puVar5;
  int iVar6;
  u8 *puVar7;
  u64 uVar8;
  u64 uVar9;
  short sVar10;
  u64 uVar11;
  u64 uVar12;
  u64 unaff_s5;
  short sVar13;
  u32 auStack_20018 [32754];
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 auStack_18 [4];
  u32 uStack_8;
  u32 uStack_4;
  
  uVar1 = *(u16 *)((int)param_1 + 0x6e);
  uVar12 = *param_1;
  uVar8 = FUN_002b8f90(0);
  uVar9 = FUN_002f87e0(6);
  FUN_002b90d0(uVar8,uVar9);
  uVar9 = FUN_002bd590(*(u32 *)(param_1 + 6),uVar1);
  *(u64 *)((int)uVar9 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,3);
  uVar9 = FUN_00284200(0x3f800000,*(u32 *)(param_1 + 6),0,0,1);
  iVar4 = (int)uVar9;
  *(u64 *)(iVar4 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  uVar11 = *(u64 *)(iVar4 + 0x58);
  uVar9 = FUN_002b8d60(3,0xfff);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_0027fe90(*(u32 *)(param_1 + 6),0,0x6978b0,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_002a3b40(0,1);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_002a3b40(param_1,0x11);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_002822b0(*(u32 *)(param_1 + 6),&uStack_28,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  for (puVar2 = *(u64 **)(DAT_007ce3ec + 0x14c); puVar2 != (u64 *)0x0;
      puVar2 = *(u64 **)(puVar2 + 0x95)) {
    if ((param_1 != puVar2) && ((*(u16 *)((int)puVar2 + 0x1a) & 1) != 0)) {
      uVar9 = FUN_00285d30(*(u32 *)(puVar2 + 6),0xffffff,0,0,2,0);
      puVar5 = (u8 *)uVar9;
      *puVar5 = 4;
      *(u64 *)(puVar5 + 8) = *(u64 *)(iVar4 + 0x58);
      *(u64 *)(puVar5 + 0x60) = uVar12;
      FUN_0027ed20(uVar9,0);
    }
  }
  FUN_0029ea60(uVar1,&uStack_4,&uStack_8);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = uVar11;
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_0029ec00(uVar1);
  FUN_0029ec80(uVar1,&uStack_4,&uStack_8);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = uVar11;
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_0029ec50(uVar1);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = uVar11;
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = uVar11;
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  sVar13 = 0;
  for (sVar10 = 0; sVar10 < 3; sVar10 = sVar10 + 1) {
    uVar1 = *(u16 *)((int)param_1 + sVar10 * 2 + 0x76);
    uVar9 = FUN_002ff540(*(u32 *)(DAT_007ce3ec + 0xbbc),uVar1);
    uVar3 = *(u32 *)(iVar6 + 0x30);
    auStack_18[sVar13] = uVar3;
    sVar13 = sVar13 + 1;
    FUN_002889c0(uVar3,uVar1);
    unaff_s5 = FUN_00285690(uVar3,uVar1,0x17e);
    puVar5 = (u8 *)unaff_s5;
    *puVar5 = 4;
    *(u64 *)(puVar5 + 8) = uVar11;
    *(u16 *)(puVar5 + 0x48) = 0x1e;
    *(u64 *)(puVar5 + 0x60) = uVar12;
    FUN_0027ed20(unaff_s5,1);
    uVar9 = FUN_00285d30(uVar3,0xffffffffffffffff,0,0,1,1);
    puVar7 = (u8 *)uVar9;
    *puVar7 = 4;
    *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
    *(u16 *)(puVar7 + 0x48) = 1;
    *(u64 *)(puVar7 + 0x60) = uVar12;
    FUN_0027ed20(uVar9);
  }
  FUN_00352c50(auStack_18[0],auStack_18[1],auStack_18[2]);
  FUN_002b71e0();
  uStack_28 = 0;
  uStack_24 = 0xc47a0000;
  uStack_20 = 0;
  for (sVar10 = 0; sVar10 < 3; sVar10 = sVar10 + 1) {
    FUN_0027f650(auStack_18[sVar10],&uStack_28);
  }
  uVar9 = FUN_002bb2f0(*(u32 *)(DAT_007ce3ec + 0xca8),*(u32 *)(param_1 + 6),0,
                       *(u64 *)((int)unaff_s5 + 0x58),0x300);
  *(u8 *)uVar9 = 4;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(iVar4 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002dd100(10,2,5);
  *(u8 *)uVar9 = 4;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(iVar4 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002baf90(uVar8,*(u32 *)(param_1 + 6),*(u32 *)(param_1 + 6),0,0x200);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)((int)unaff_s5 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,2);
  uVar9 = FUN_0027f410(0x2efd20,*(u32 *)(param_1 + 6));
  puVar7 = (u8 *)uVar9;
  *puVar7 = 5;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  *(u16 *)(puVar7 + 0x48) = 0x78;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002b8d60(3,0xfff);
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002a3b40(param_1,0x25);
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  *(u16 *)(puVar7 + 0x4a) = 0x1e;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  for (puVar2 = *(u64 **)(DAT_007ce3ec + 0x14c); puVar2 != (u64 *)0x0;
      puVar2 = *(u64 **)(puVar2 + 0x95)) {
    if ((param_1 != puVar2) && ((*(u16 *)((int)puVar2 + 0x1a) & 1) != 0)) {
      uVar9 = FUN_00285d30(*(u32 *)(puVar2 + 6),0xffffffffffffffff,0,0,1,0);
      puVar7 = (u8 *)uVar9;
      *puVar7 = 4;
      *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
      *(u64 *)(puVar7 + 0x60) = uVar12;
      FUN_0027ed20(uVar9,0);
    }
  }
  FUN_001fdd40();
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,1);
  puVar7 = (u8 *)uVar9;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar7[0x47] = puVar7[0x47] & 0xdf;
  *(u64 *)(puVar7 + 0x60) = uVar12;
  FUN_0027ed20(uVar9,0);
  FUN_002b9030(uVar8);
  return;
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
  short sVar1;
  u32 bVar2;
  u8 *puVar3;
  int iVar4;
  u8 *puVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  u64 uVar9;
  s32 lVar10;
  u32 uVar11;
  u32 uVar12;
  int iVar13;
  int iVar14;
  
  uVar11 = (u32)*(u16 *)(iGpffffb6fc + 0xb50);
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  uVar12 = 0;
  iVar14 = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    lVar10 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0);
    iVar13 = iVar14;
    if (lVar10 == 0) {
      sVar1 = *(short *)(iVar4 + 0xa4);
      if (((sVar1 == 0x118) || (sVar1 == 0x117)) || (sVar1 == 0x116)) {
        uVar12 = uVar12 + 1 & 0xffff;
      }
      else {
        iVar13 = iVar4;
        if (sVar1 != 0x10d) {
          iVar13 = iVar14;
        }
      }
    }
    iVar14 = iVar13;
  }
  bVar2 = uVar12 != uVar11;
  uVar6 = FUN_002b8f90(0);
  uVar7 = FUN_002b8f90(0);
  if (uVar11 == 1) {
    uVar8 = FUN_002f87e0(2);
    FUN_002b90d0(uVar6,uVar8);
  }
  else {
    uVar8 = FUN_002f87e0(3);
    FUN_002b90d0(uVar6,uVar8);
  }
  if (bVar2) {
    uVar8 = FUN_002f87e0(4);
    FUN_002b90d0(uVar7,uVar8);
  }
  else {
    uVar8 = FUN_002f87e0(5);
    FUN_002b90d0(uVar7,uVar8);
  }
  iVar4 = 0;
  uVar8 = 0;
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar4 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = FUN_00284200(0x3f800000,*(u32 *)(iVar4 + 0x30),0x12,0,2);
    *(u16 *)((int)uVar8 + 0x48) = 2;
    *(u64 *)((int)uVar8 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  uVar9 = FUN_002f8810();
  uVar9 = FUN_002dd760(3,uVar9,0);
  *(u16 *)((int)uVar9 + 0x48) = 2;
  *(u64 *)((int)uVar9 + 0x60) = *param_1;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002b8d60(3,0xfff);
  puVar3 = (u8 *)uVar9;
  *puVar3 = 4;
  iVar13 = (int)uVar8;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar13 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar9,1);
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar4 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = FUN_0027fe90(*(u32 *)(iVar4 + 0x30),0,0x6978b0,0);
    puVar3 = (u8 *)uVar8;
    *puVar3 = 4;
    *(u64 *)(puVar3 + 8) = *(u64 *)(iVar13 + 0x58);
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  uVar8 = FUN_002a3b40(0,1);
  puVar3 = (u8 *)uVar8;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar13 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar8,0);
  uVar8 = FUN_002baf90(uVar6,*(u32 *)(iVar4 + 0x30),*(u32 *)(iVar4 + 0x30),0,0x200);
  iVar4 = (int)uVar8;
  *(u64 *)(iVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar8,2);
  for (uVar12 = 0; uVar12 < uVar11; uVar12 = uVar12 + 1 & 0xffff) {
    iVar13 = *(int *)(iGpffffb6fc + uVar12 * 4 + 0xb44);
    uVar8 = FUN_002baf90(uVar6,*(u32 *)(iVar13 + 0x30),*(u32 *)(iVar13 + 0x30),1,0x200
                        );
    puVar3 = (u8 *)uVar8;
    *puVar3 = 5;
    *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
    *(u16 *)(puVar3 + 0x48) = 0x37;
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,2);
    uVar8 = FUN_00285d30(*(u32 *)(iVar13 + 0x30),0xffffff,6,0,4,0);
    puVar3 = (u8 *)uVar8;
    *puVar3 = 5;
    *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
    *(u16 *)(puVar3 + 0x48) = 0x41;
    *(u64 *)(puVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar8,1);
  }
  if (!bVar2) {
    uVar8 = FUN_0027f410(0x2efdb0,iVar14);
    *(u8 *)uVar8 = 4;
    *(u64 *)((u8 *)uVar8 + 8) = *(u64 *)(iVar4 + 0x58);
    FUN_0027ed20(uVar8,1);
    lVar10 = FUN_0029ad20();
    if (lVar10 != 0) {
      *(u16 *)((int)lVar10 + 0x18) = *(u16 *)((int)lVar10 + 0x18) | 8;
    }
  }
  uVar8 = FUN_002baf90(uVar7,iVar14,iVar14,0,0x200);
  puVar3 = (u8 *)uVar8;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar4 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar8,2);
  if ((!bVar2) && (*(int *)(iGpffffb6fc + 0xb60) == 0)) {
    uVar8 = FUN_002db890();
    puVar5 = (u8 *)uVar8;
    *puVar5 = 5;
    *(u64 *)(puVar5 + 8) = *(u64 *)(puVar3 + 0x58);
    *(u16 *)(puVar5 + 0x48) = 0x41;
    FUN_0027ed20(uVar8,1);
    uVar8 = FUN_002db800(0x20,0x31);
    puVar5 = (u8 *)uVar8;
    *puVar5 = 5;
    *(u64 *)(puVar5 + 8) = *(u64 *)(puVar3 + 0x58);
    *(u16 *)(puVar5 + 0x48) = 0x41;
    FUN_0027ed20(uVar8,1);
    *(u32 *)(iGpffffb6fc + 0xb60) = 1;
  }
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x400000;
  *(u16 *)(iGpffffb6fc + 0x18) = *(u16 *)(iGpffffb6fc + 0x18) | 7;
  FUN_002b9030(uVar7);
  FUN_002b9030(uVar6);
  return;
}

// FUN_002f14a0 NONMATCHING
u32 func_002f14a0(u64 *param_1)

{
  u16 uVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  s32 lVar5;
  u64 uVar6;
  u32 uVar7;
  
  uVar1 = *(u16 *)(iGpffffb6fc + 0xb50);
  uVar7 = 0;
  do {
    if (uVar1 <= uVar7) {
      lVar5 = FUN_0027e390(*param_1,0x3fffffffffffffff);
      if (lVar5 == 0) {
        *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfff7ffff;
        for (uVar7 = 0; uVar7 < uVar1; uVar7 = uVar7 + 1 & 0xffff) {
          uVar4 = *(u32 *)(iGpffffb6fc + uVar7 * 4 + 0xb44);
          FUN_002d7890(uVar4,0);
          FUN_0029a320(uVar4);
        }
        *(u16 *)(iGpffffb6fc + 0xb50) = 0;
        *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x2000000;
        FUN_0027ed20(uVar6,1);
        FUN_0027ed20(uVar6,1);
        FUN_0027ed20(uVar6,1);
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
      return uVar4;
    }
    iVar2 = *(int *)(iGpffffb6fc + uVar7 * 4 + 0xb44);
    iVar3 = FUN_0029ad20();
    if (iVar2 == iVar3) {
      *(u32 *)(*(int *)(iVar2 + 0x30) + 0x9c) =
           *(u32 *)(*(int *)(iVar2 + 0x30) + 0x9c) & 0xffffffef;
    }
    else if ((*(u32 *)(*(int *)(iVar2 + 0x30) + 0x9c) & 0x10) != 0) {
      return 1;
    }
    uVar7 = uVar7 + 1 & 0xffff;
  } while( true );
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

 #pragma schedule on
 #pragma optimization_level 1
// FUN_002f1810 NONMATCHING
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
  packet = FUN_0027fe90_packet_voice(target, NULL, (const void*)0x6978b0, NULL);
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
 #pragma schedule on
 #pragma optimization_level 2

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

// FUN_002f1b60 NONMATCHING
u32 func_002f1b60(BtlAction* param_1,float *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  s32 lVar4;
  int iVar5;
  float fVar6;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float afStack_10 [2];
  float fStack_8;
  
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0x30);
  if (*(char *)(iVar1 + 0xa2) == '\x01') {
    if (*(short *)(iVar1 + 0xa4) == 0x10f) {
      if (*(short *)(iVar5 + 0x6a) == 1) {
        if (*(short *)(iVar5 + 0x6c) == 2) {
          if ((*(u8 *)(iGpffffb708 +
                        ((u32)*(u16 *)(iVar5 + 0x6e) * 10 + (u32)*(u16 *)(iVar5 + 0x6e)) * 4
                        ) & 2) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(u32 *)(*(int *)(iVar5 + 0x38) + 0x30);
            FUN_00280050(iVar1,afStack_10);
            FUN_00280480(uVar3,iVar1,&fStack_20);
            fStack_30 = afStack_10[0] - fStack_20;
            fStack_28 = fStack_8 - fStack_18;
            fStack_2c = 0.0;
            FUN_004c69f0(&fStack_30,&fStack_30);
            lVar4 = FUN_002d5e10(param_1);
            if (lVar4 == 0) {
              uVar2 = 4;
            }
            else {
              uVar2 = 0xb;
            }
            fVar6 = (float)FUN_002812d0(iVar1,uVar3,uVar2);
            *param_2 = fStack_20 + fStack_30 * fVar6;
            param_2[1] = fStack_1c + fStack_2c * fVar6;
            param_2[2] = fStack_18 + fStack_28 * fVar6;
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

// FUN_002f1d40 NONMATCHING
void func_002f1d40(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x10f) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

// FUN_002f2090 NONMATCHING
void func_002f2090(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x110) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

void func_002f2550(u64* param_1);
u32 func_002f2840(u64* param_1);

void func_002f2890(u64* param_1);
u32 func_002f2b40(u64* param_1);

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
void func_002f2550(u64 *param_1)

{
  u32 uVar1;
  int iVar2;
  u8 *puVar3;
  u64 uVar4;
  u64 uVar5;
  
  uVar1 = *(u32 *)(iGpffffb6fc + 0x158);
  uVar4 = FUN_002b8f90(0);
  uVar5 = FUN_002f87e0(3);
  FUN_002b90d0(uVar4,uVar5);
  uVar5 = FUN_002bd590(uVar1,0x66);
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,3);
  uVar5 = FUN_002b8d60(3,0xfff);
  *(u16 *)((int)uVar5 + 0x48) = 3;
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002bc7e0(8);
  *(u16 *)((int)uVar5 + 0x48) = 3;
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002a3d70(uGpffff82e0,*(u32 *)(iGpffffb6fc + 0x148),0x69a250,0x69a270,0x69a290,
                       0x69a2b0);
  *(u16 *)((int)uVar5 + 0x48) = 3;
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002dd4a0(0x66,0);
  iVar2 = (int)uVar5;
  *(u64 *)(iVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002baf90(uVar4,uVar1,uVar1,0,0x200);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  uVar5 = FUN_002dd5e0(0);
  *(u8 *)uVar5 = 5;
  *(u64 *)((u8 *)uVar5 + 8) = *(u64 *)(puVar3 + 0x58);
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002baf90(uVar4,uVar1,uVar1,1,0x200);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  uVar5 = FUN_002dd5e0(1);
  *(u8 *)uVar5 = 5;
  *(u64 *)((u8 *)uVar5 + 8) = *(u64 *)(puVar3 + 0x58);
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002bd850(uVar1,0x45);
  iVar2 = (int)uVar5;
  *(u8 *)(iVar2 + 0x20) = 5;
  *(u64 *)(iVar2 + 0x28) = *(u64 *)(puVar3 + 0x58);
  *(u16 *)(iVar2 + 0x48) = 0x9b;
  *(u64 *)(iVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,3);
  uVar5 = FUN_0027f410(0x2f23d0,uVar1);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 5;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  FUN_002b9030(uVar4);
  return;
}

// FUN_002f2840
u32 func_002f2840(u64 *param_1)

{
  u64 lVar1;
  
  lVar1 = FUN_0027e390(*param_1,0x3fffffffffffffff);
  return lVar1 != 0;
}

// FUN_002f2890 NONMATCHING
void func_002f2890(u64 *param_1)

{
  u32 uVar1;
  u8 *puVar2;
  u64 uVar3;
  u64 uVar4;
  u32 uVar5;
  u64 uVar6;
  int iVar7;
  
  uVar1 = *(u32 *)(iGpffffb6fc + 0x158);
  uVar3 = FUN_002b8f90(0);
  uVar4 = FUN_002f87e0(4);
  FUN_002b90d0(uVar3,uVar4);
  uVar4 = FUN_002bd590(uVar1,0x67);
  *(u64 *)((int)uVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,3);
  uVar4 = FUN_002b8d60(3,0xfff);
  *(u16 *)((int)uVar4 + 0x48) = 3;
  *(u64 *)((int)uVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,0);
  uVar4 = FUN_002bc7e0(8);
  *(u16 *)((int)uVar4 + 0x48) = 3;
  *(u64 *)((int)uVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,0);
  uVar5 = FUN_002ffbc0(100);
  iVar7 = (u32)(uVar5 < 0x32) * 0xc;
  uVar4 = FUN_002a3d70(uGpffff82dc,*(u32 *)(iGpffffb6fc + 0x148),iVar7 + 0x69a2d0,
                       iVar7 + 0x69a2f0,iVar7 + 0x69a310,iVar7 + 0x69a330);
  *(u16 *)((int)uVar4 + 0x48) = 3;
  *(u64 *)((int)uVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,0);
  uVar4 = FUN_002dd4a0(0x67,0);
  *(u64 *)((int)uVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,1);
  uVar6 = FUN_002baf90(uVar3,uVar1,uVar1,0,0x200);
  puVar2 = (u8 *)uVar6;
  *puVar2 = 4;
  *(u64 *)(puVar2 + 8) = *(u64 *)((int)uVar4 + 0x58);
  *(u64 *)(puVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,2);
  uVar4 = FUN_002dd5e0(0);
  *(u8 *)uVar4 = 5;
  *(u64 *)((u8 *)uVar4 + 8) = *(u64 *)(puVar2 + 0x58);
  FUN_0027ed20(uVar4,1);
  uVar4 = FUN_002bd850(uVar1,0x47);
  iVar7 = (int)uVar4;
  *(u8 *)(iVar7 + 0x20) = 5;
  *(u64 *)(iVar7 + 0x28) = *(u64 *)(puVar2 + 0x58);
  *(u64 *)(iVar7 + 0x60) = *param_1;
  *(u16 *)(iVar7 + 0x48) = 0x28;
  FUN_0027ed20(uVar4,3);
  uVar4 = FUN_0027f410(0x2f2410,uVar1);
  puVar2 = (u8 *)uVar4;
  *puVar2 = 5;
  *(u64 *)(puVar2 + 8) = *(u64 *)(iVar7 + 0x58);
  *(u64 *)(puVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar4,1);
  FUN_002b9030(uVar3);
  return;
}

// FUN_002f2b40
u32 func_002f2b40(u64 *param_1)

{
  u64 lVar1;
  
  lVar1 = FUN_0027e390(*param_1,0x3fffffffffffffff);
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
  u64 uVar7;
  u64 uVar8;
  u64 uVar9;
  u64 *puVar10;
  u64 uVar11;
  u8 auStack_90 [136];
  u32 uStack_8;
  u32 uStack_4;
  
  puVar10 = (u64 *)param_1;
  uVar11 = *puVar10;
  sVar2 = FUN_002835e0(0x3f800000,*(u32 *)(puVar10 + 6),0x17);
  uVar1 = *(u16 *)(DAT_0069a1d2 + (u32)*(u16 *)(iGpffffb6fc + 0xb48) * 4);
  uVar7 = FUN_002b8f90(0);
  uVar8 = FUN_002b8f90(1);
  uVar9 = FUN_002f87e0(5);
  FUN_002b90d0(uVar7,uVar9);
  uVar9 = FUN_002d1d00(param_1,2,0x69a350);
  iVar3 = (int)uVar9;
  *(u16 *)(iVar3 + 0x48) = 0x1e;
  *(u64 *)(iVar3 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_002a3b40(0,1);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(iVar3 + 0x58);
  *(u16 *)(puVar4 + 0x48) = 0x10;
  FUN_0027ed20(uVar9,0);
  uVar9 = FUN_002bb2f0(uVar7,*(u32 *)(puVar10 + 6),sVar2 + 6,0,0x200);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,2);
  uVar9 = FUN_00284200(0x3f800000,*(u32 *)(puVar10 + 6),0x17,0,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u16 *)(puVar5 + 0x48) = 4;
  *(u64 *)(puVar5 + 0x60) = *puVar10;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar9 = 4;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(puVar5 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002bd590(*(u32 *)(puVar10 + 6),uVar1);
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
  uVar9 = FUN_0029ec00(uVar1);
  FUN_0029ec80(uVar1,&uStack_4,&uStack_8);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_0029ec50(uVar1);
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
  uVar9 = FUN_002bac00(uVar8,auStack_90,0);
  puVar5 = (u8 *)uVar9;
  *puVar5 = 4;
  *(u64 *)(puVar5 + 8) = *(u64 *)(puVar4 + 0x58);
  *(short *)(puVar5 + 0x48) = sVar2;
  *(u64 *)(puVar5 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002dd4a0(uVar1,0);
  puVar4 = (u8 *)uVar9;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(puVar5 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002baf90(uVar8,*(u32 *)(puVar10 + 6),*(u32 *)(puVar10 + 6),0,0);
  puVar6 = (u8 *)uVar9;
  *puVar6 = 4;
  *(u64 *)(puVar6 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar6[0x10] = 4;
  *(u64 *)(puVar6 + 0x18) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar6 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,2);
  uVar9 = FUN_002dd5e0(0);
  *(u8 *)uVar9 = 5;
  *(u64 *)((u8 *)uVar9 + 8) = *(u64 *)(puVar6 + 0x58);
  FUN_0027ed20(uVar9,1);
  uVar9 = FUN_002baf90(uVar8,*(u32 *)(puVar10 + 6),*(u32 *)(puVar10 + 6),1,0);
  puVar6 = (u8 *)uVar9;
  *puVar6 = 4;
  *(u64 *)(puVar6 + 8) = *(u64 *)(puVar5 + 0x58);
  puVar6[0x10] = 4;
  *(u64 *)(puVar6 + 0x18) = *(u64 *)(puVar4 + 0x58);
  *(u64 *)(puVar6 + 0x60) = uVar11;
  FUN_0027ed20(uVar9,2);
  uVar9 = FUN_002dd5e0(1);
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

// FUN_002f3190 NONMATCHING
u32 func_002f3190(u64 *param_1)

{
  u16 uVar1;
  int iVar2;
  s32 lVar3;
  u64 uVar4;
  
  lVar3 = FUN_0027e390(*param_1,0x3fffffffffffffff);
  if (lVar3 == 0) {
    *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfff7ffff;
    iVar2 = *(int *)(*(int *)(param_1 + 6) + 0xa2c);
    uVar1 = *(u16 *)(DAT_0069a1d0 + (u32)*(u16 *)(iGpffffb6fc + 0xb48) * 4);
    FUN_002889c0(*(int *)(param_1 + 6),uVar1);
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
    FUN_002831c0(*(u32 *)(param_1 + 6),6);
    *(short *)(iGpffffb6fc + 0xb48) = *(short *)(iGpffffb6fc + 0xb48) + 1;
    FUN_001fdd40();
  }
  return lVar3 != 0;
}

// FUN_002f3320 NONMATCHING
void func_002f3320(u64 *param_1)

{
  u32 uVar1;
  int iVar2;
  u8 *puVar3;
  u64 uVar4;
  u64 uVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  uVar1 = *(u32 *)(param_1 + 6);
  uVar4 = FUN_002b8f90(0);
  uVar5 = FUN_002f87e0(6);
  FUN_002b90d0(uVar4,uVar5);
  uVar5 = FUN_002dd690(3,0x69a368);
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_00284200(0x3f800000,uVar1,0x12,0,2);
  iVar2 = (int)uVar5;
  *(u16 *)(iVar2 + 0x48) = 2;
  *(u64 *)(iVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002b8d60(1,0xfff);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_0027fe90(uVar1,0,0x6978b0,0);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002a3b40(0,1);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002baf90(uVar4,uVar1,uVar1,0,0x200);
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  FUN_002b9030(uVar4);
  return;
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
  u8 auStack_50 [12];
  u32 uStack_44;
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
  uVar7 = FUN_002a3d70(*(float *)(iVar12 * 4 + 0x69a458) / 30.0,*(u32 *)(iGpffffb6fc + 0x148)
                       ,iVar8 + 0x69a3a0,iVar8 + 0x69a3d0,iVar8 + 0x69a400,iVar8 + 0x69a430);
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
          uVar16 = FUN_00284200(0x3f800000,*(u32 *)(iVar12 + 0x30),
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
          uVar16 = FUN_00284200(0x3f800000,*(u32 *)(iVar12 + 0x30),10,0,0);
          puVar4 = (u8 *)uVar16;
          *puVar4 = 5;
          *(u64 *)(puVar4 + 8) = *(u64 *)(puVar3 + 0x58);
          *(u16 *)(puVar4 + 0x48) = 0xa1;
          *(u64 *)(puVar4 + 0x60) = uVar14;
          FUN_0027ed20(uVar16,1);
          FUN_002d5dc0(auStack_50);
          uStack_44 = 0x100000;
          uVar16 = FUN_002d7e20(param_1,iVar12,auStack_50,1,1);
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

// FUN_002f46d0 NONMATCHING
void func_002f46d0(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x126) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

 #pragma schedule on
 #pragma optimization_level 1
// FUN_002f4a40 NONMATCHING
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
  packet = FUN_0027fe90_packet_voice(target, NULL, (const void*)0x6978b0, NULL);
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
 #pragma schedule on

 #pragma optimization_level 2
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

 #pragma schedule on
 #pragma optimization_level 1
// FUN_002f4e70 NONMATCHING
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
  packet = FUN_0027fe90_packet_voice(target, NULL, (const void*)0x6978b0, NULL);
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
 #pragma schedule on
 #pragma optimization_level 2

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

// FUN_002f5490 NONMATCHING
void func_002f5490(void)

{
  int iVar1;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_c = 0;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b2) {
      if (*(short *)(iVar1 + 0xa4) == 9) {
        uStack_10 = 0xc3160000;
        uStack_8 = 0x43960000;
        *(u8 *)(iVar1 + 0x9f0) = 0;
      }
      else if (*(short *)(iVar1 + 0xa4) == 1) {
        uStack_10 = 0x43160000;
        uStack_8 = 0x43960000;
        *(u8 *)(iVar1 + 0x9f0) = 1;
      }
    }
    else if (*(short *)(iVar1 + 0xa4) == 9) {
      uStack_10 = 0x43160000;
      uStack_8 = 0x43960000;
      *(u8 *)(iVar1 + 0x9f0) = 1;
    }
    else if (*(short *)(iVar1 + 0xa4) == 1) {
      uStack_10 = 0xc3160000;
      uStack_8 = 0x43960000;
      *(u8 *)(iVar1 + 0x9f0) = 0;
    }
    FUN_002d2280(iVar1 + 0x94,iVar1 + 0x96,&uStack_10);
    FUN_0027f650(iVar1,&uStack_10);
  }
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    switch(*(u16 *)(iVar1 + 0xa4)) {
    case 0xeb:
    case 0xee:
    case 0xef:
      uStack_10 = 0xc3160000;
      uStack_8 = 0xc3960000;
      break;
    case 0xec:
    case 0xed:
    case 0xf0:
      uStack_10 = 0x43160000;
      uStack_8 = 0xc3960000;
    }
    FUN_002d2280(iVar1 + 0x94,iVar1 + 0x96,&uStack_10);
    FUN_0027f650(iVar1,&uStack_10);
  }
  return;
}

// FUN_002f5660 NONMATCHING
void func_002f5660(u64 *param_1)

{
  int iVar1;
  int iVar2;
  u8 *puVar3;
  u64 uVar4;
  u64 uVar5;
  u16 unaff_s0_lo;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  iVar1 = *(int *)(param_1 + 6);
  switch(*(u16 *)(iVar1 + 0xa4)) {
  case 0xeb:
  case 0xed:
  case 0xef:
    unaff_s0_lo = 2;
    break;
  case 0xec:
  case 0xee:
  case 0xf0:
    unaff_s0_lo = 3;
  }
  uVar4 = FUN_002b8f90(0);
  uVar5 = FUN_002f87e0(unaff_s0_lo);
  FUN_002b90d0(uVar4,uVar5);
  uVar5 = FUN_00284200(0x3f800000,iVar1,0x12,0,2);
  iVar2 = (int)uVar5;
  *(u16 *)(iVar2 + 0x48) = 3;
  *(u64 *)(iVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002b8d60(1,0xfff);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_0027fe90(iVar1,0,0x6978b0,0);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002a3b40(0,1);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002baf90(uVar4,iVar1,iVar1,0,0x200);
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  FUN_002b9030(uVar4);
  return;
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

// FUN_002f5bf0 NONMATCHING
void func_002f5bf0(BtlAction* param_1,BtlAction* param_2,BtlTargetResult* param_3)

{
  u32 bVar1;
  int iVar2;
  u16 *puVar3;
  s32 lVar4;
  BtlAction* unaff_s0;
  
  bVar1 = false;
  iVar2 = *(int *)((int)param_1 + 0x30);
  if (*(char *)(iVar2 + 0xa2) == '\x01') {
    if (*(short *)(iVar2 + 0xa4) == 0xf1) {
      bVar1 = (*(u16 *)((int)param_3 + 0x1a) & 0x100) != 0;
      if (bVar1) {
        unaff_s0 = param_1;
      }
      if ((*(u16 *)((int)param_3 + 0x1a) & 0x200) != 0) {
        *(u32 *)(DAT_007ce3ec + 0xb48) = 1;
        for (iVar2 = *(int *)(DAT_007ce3ec + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
          if (*(short *)(iVar2 + 0xa4) == 0xf2) {
            *(u32 *)(DAT_007ce3ec + 0xb50) = 1;
            *(u16 *)(DAT_007ce3ec + 0xb54) = 0;
            *(u16 *)(DAT_007ce3ec + 0xb56) = 10;
            *(u16 *)(DAT_007ce3ec + 0xb58) = 0;
          }
        }
        puVar3 = *(u16 **)(*(int *)((int)param_1 + 0x30) + 0xa2c);
        *puVar3 = *puVar3 | 0x40;
      }
      goto LAB_002f5d34;
    }
  }
  iVar2 = *(int *)((int)param_2 + 0x30);
  if (*(char *)(iVar2 + 0xa2) == '\x01') {
    if (*(short *)(iVar2 + 0xa4) == 0xf1) {
      iVar2 = param_3->hpDelta;
      if (iVar2 < 0) {
        if (*(int *)(DAT_007ce3ec + 0xb48) == 1) {
          if (-iVar2 < *(int *)(DAT_007ce3ec + 0xb4c)) {
            *(int *)(DAT_007ce3ec + 0xb4c) = *(int *)(DAT_007ce3ec + 0xb4c) + iVar2;
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
    FUN_002e4220(0x2f6840,0x2f6ab0,unaff_s0);
  }
  return;
}

// FUN_002f5d80 NONMATCHING
void func_002f5d80(u64 param_1)

{
  u32 bVar1;
  int iVar2;
  s32 lVar3;
  int iVar4;
  float fVar5;
  u8 uVar6;
  char cVar7;
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
            if (*(u16 *)(DAT_007ce3ec + 0xb58) < *(u16 *)(DAT_007ce3ec + 0xb56)) {
              fVar5 = ((float)*(u16 *)(DAT_007ce3ec + 0xb58) * 255.0) /
                      (float)*(u16 *)(DAT_007ce3ec + 0xb56);
              if (fVar5 < 2.1474836e+09) {
                cVar7 = (char)(int)fVar5;
              }
              else {
                cVar7 = (char)(int)(fVar5 - 2.1474836e+09);
              }
              uStack_4 = CONCAT13(-1 - cVar7,0xffffff);
              *(short *)(DAT_007ce3ec + 0xb58) = *(short *)(DAT_007ce3ec + 0xb58) + 1;
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = true;
          }
        }
        else if (bVar1) {
          if (*(u16 *)(DAT_007ce3ec + 0xb58) < *(u16 *)(DAT_007ce3ec + 0xb56)) {
            fVar5 = ((float)*(u16 *)(DAT_007ce3ec + 0xb58) * 255.0) /
                    (float)*(u16 *)(DAT_007ce3ec + 0xb56);
            if (fVar5 < 2.1474836e+09) {
              uVar6 = (u8)(int)fVar5;
            }
            else {
              uVar6 = (u8)(int)(fVar5 - 2.1474836e+09);
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
  return;
}

// FUN_002f6120 NONMATCHING
void func_002f6120(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(4);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0xf1) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x69a5b8);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  uVar3 = FUN_002bc890(0x7cc970,0x18);
  *(u16 *)((int)uVar3 + 0x48) = 200;
  FUN_0027ed20(uVar3,1);
  FUN_002b9030(uVar2);
  return;
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
      u64 xy = *(volatile u64 *)DAT_0069a5c8;
      f32 z = *(volatile f32 *)(DAT_0069a5c8 + 8);
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
      u64 xy = *(volatile u64 *)DAT_0069a5d8;
      f32 z = *(volatile f32 *)(DAT_0069a5d8 + 8);
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
    u64 xy = *(volatile u64 *)DAT_0069a608;
    f32 z = *(volatile f32 *)(DAT_0069a608 + 8);
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
    u64 xy = *(volatile u64 *)DAT_0069a648;
    f32 z = *(volatile f32 *)(DAT_0069a648 + 8);
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

// FUN_002f6840 NONMATCHING
void func_002f6840(u64 *param_1)

{
  u32 uVar1;
  u64 uVar2;
  u64 uVar3;
  s32 lVar4;
  int iVar5;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  uVar1 = *(u32 *)(param_1 + 6);
  if (*(int *)(DAT_007ce3ec + 0xb4c) < 1) {
    iVar5 = 3;
  }
  else {
    iVar5 = 2;
  }
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(iVar5);
  FUN_002b90d0(uVar2,uVar3);
  uVar3 = FUN_002b8d60(1,0xfff);
  *(u64 *)((int)uVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u64 *)((int)uVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,uVar1,uVar1,0,0x200);
  *(u64 *)((int)uVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar3,2);
  uVar3 = FUN_002baf90(uVar2,uVar1,uVar1,1,0x200);
  *(u64 *)((int)uVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar3,2);
  if (iVar5 == 3) {
    for (iVar5 = *(int *)(DAT_007ce3ec + 0x158); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xa34)) {
      if (*(short *)(iVar5 + 0xa4) == 0xf2) {
        *(u32 *)(DAT_007ce3ec + 0xb50) = 0;
        *(u16 *)(DAT_007ce3ec + 0xb54) = 0x1e;
        *(u16 *)(DAT_007ce3ec + 0xb56) = 4;
        *(u16 *)(DAT_007ce3ec + 0xb58) = 0;
      }
    }
    uVar3 = FUN_002f8810();
    uVar3 = FUN_002dd760(3,uVar3,4);
    *(u16 *)((int)uVar3 + 0x48) = 0x1e;
    FUN_0027ed20(uVar3,1);
    lVar4 = FUN_003951d0(0x15ff);
    if (lVar4 == 0) {
      FUN_00395170(0x15ff);
      uVar3 = FUN_002db890();
      *(u16 *)((int)uVar3 + 0x48) = 0;
      FUN_0027ed20(uVar3,1);
      uVar3 = FUN_002db800(0x20,0x1de);
      *(u16 *)((int)uVar3 + 0x48) = 0;
      FUN_0027ed20(uVar3,1);
    }
  }
  FUN_002b9030(uVar2);
  return;
}

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

// FUN_002f6e00 NONMATCHING
void func_002f6e00(void)

{
  u16 sVar1;
  u32 uVar2;
  u8 auStack_40 [64];
  
  FUN_00521408(DAT_007ce3ec + 0xb14,0,0x74);
  *(u16 *)(DAT_007ce3ec + 0xb84) = 0;
  sVar1 = *(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);
  if (sVar1 == 0x1b4) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffffbff;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x55a4;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1b3) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x5190;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1b2) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4d7c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1b1) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4968;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1b0) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4554;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1af) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x4140;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1ae) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x3d2c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1ad) {
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
  }
  else if (sVar1 == 0x1ac) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x3504;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1ab) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x30f0;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1aa) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x2cdc;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a9) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x28c8;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a8) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x24b4;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a7) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x20a0;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a6) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1c8c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a5) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1878;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a4) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1464;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a3) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x1050;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a2) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0xc3c;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a1) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x828;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1a0) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 2;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 8;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x80;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc + 0x414;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x200000;
  }
  else if (sVar1 == 0x1c8) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffeffff;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfbffffff;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x40;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 1;
    *(u32 *)(DAT_007ce3ec + 0x10) = *(u32 *)(DAT_007ce3ec + 0x10) | 0x10;
    *(int *)(DAT_007ce3ec + 0xb18) = DAT_007ce4bc;
    *(u16 *)(DAT_007ce3ec + 0xb84) = 1;
  }
  FUN_00523ac8(auStack_40,0x69a710,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
  uVar2 = FUN_0035c090(DAT_007ce4d0,auStack_40);
  *(u32 *)(DAT_007ce3ec + 0xb1c) = uVar2;
  FUN_00523ac8(auStack_40,0x69a730,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
  uVar2 = FUN_0035c090(DAT_007ce4d0,auStack_40);
  *(u32 *)(DAT_007ce3ec + 0xb20) = uVar2;
  FUN_00523ac8(auStack_40,0x69a750,*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8));
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

extern u32 DAT_00697c80;
extern u32 DAT_00697c84;
extern u32 DAT_00697c88;
extern u32 DAT_00697c8c;
extern u32 DAT_00697c9c;
extern u32 DAT_00697ca0;
extern u32 DAT_00697ca4;
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
extern u8 DAT_0069a000[];
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
extern u32 DAT_007cc9a0;
extern u32 DAT_007cc9a2;
extern u32 DAT_007cc9a4;
extern u32 DAT_007cc9a8;
extern u32 DAT_007cc9aa;
extern u32 DAT_007cc9ac;
extern u32 DAT_007cc9b0;
extern u32 DAT_007cc9b2;
extern u32 DAT_007cc9b4;
extern u32 DAT_007cc9b8;
extern u32 DAT_007cc9ba;
extern u32 DAT_007cc9bc;
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
extern u64 FUN_0027f710();
extern u64 FUN_0027f730();
extern u64 FUN_0027fcf0();
extern u64 FUN_0027fe90();
extern u64 FUN_0027ffb0();
extern u64 FUN_00280050();
extern u64 FUN_00280130();
extern u64 FUN_00280480();
extern u64 FUN_00280870();
extern u64 FUN_002812d0();
extern u64 FUN_002822b0();
extern u64 FUN_00282bc0();
extern u64 FUN_00282c30();
extern void FUN_00282d40(f32 speed, BtlUnit* unit, s16 id, u32 blend, s8 mode);
extern void FUN_00282d40_call(BtlUnit* unit, s16 id, u32 blend, s8 mode,
                              f32 speed);
#pragma alias FUN_00282d40_call FUN_00282d40
extern u64 FUN_002831c0();
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
extern u64 FUN_002d1f30();
extern u64 FUN_002d1fd0();
extern void FUN_002d2280();
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
extern u64 FUN_002ffd70();
extern u64 FUN_002ffd90();
extern u64 FUN_002ffdf0();
extern u64 FUN_003004f0();
extern u64 FUN_00300560();
extern u64 FUN_00300580();
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
extern u64 FUN_003195f0();
extern u64 FUN_00351bb0();
extern void FUN_00352c50(u32 param_1, u32 param_2, u32 param_3);
extern u64 FUN_00357fd0();
extern u64 FUN_00395170();
extern u64 FUN_004be1e0();
extern u64 FUN_004be310();
extern u64 FUN_004c31b0();
extern u64 FUN_004c69f0();
extern u64 FUN_004c6b20();
extern void FUN_004c6be0(float* out, const RwV3d* basis, void* source);
extern u64 FUN_004c6c60();
extern u64 FUN_00521408();
extern u64 FUN_0052e930();
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
u32 func_002e4520(int param_1,u32 param_2,u64 param_3);
u32 func_002e4720(u16 param_1);
u32 func_002e47a0(BtlAction* action, s32 skillId);
u32 func_002e4910(BtlAction* action, s32 skillId);
void func_002e4a30(void);
void func_002e4a40(u64 param_1);
void func_002e4f50(BtlCamera* camera);
void func_002e5040(void);
void func_002e5060(u64 param_1);
void func_002e58a0(u64 param_1);
f32 func_002e6130(BtlUnit* param_1,BtlUnit* param_2,float* param_3,float* param_4);
void func_002e6a20(BtlCamera* camera, float weight);
void func_002e70b0(BtlCamera* camera);
void func_002e71c0(int param_1);
void func_002e7210(BtlCamera* camera);
void func_002e7320(void);
void func_002e7330(u64 param_1);
void func_002e7680(void);
void func_002e76a0(BtlCamera* camera);
void func_002e7710(BtlCamera* camera);
void func_002e77c0(BtlCamera* camera);
void func_002e7810(int param_1);
void func_002e7880(void);
void func_002e7890(u64 param_1);
void func_002e7db0(u64 param_1);
void func_002e82b0(u64 param_1);
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
void func_002e9c20(u64 *param_1);
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
void func_002eba50(u64 *param_1);
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
void func_002ecc60(s32 param_1,s32 param_2);
u32 func_002ecf80(int param_1);
void func_002ed350(void);
u32 func_002ed360(u64 *param_1);
void func_002ee640(u64 *param_1);
u32 func_002eea10(s32 param_1);
void func_002eeb70(BtlAction* action);
void func_002eec60(void);
u32 func_002eee20(BtlAction* param_1,float *param_2);
void func_002ef000(u64 *param_1);
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
    value = *(volatile u16*)(entry + 0xc);
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
u32 func_002e4520(int param_1,u32 param_2,u64 param_3)

{
  u32 uVar1;
  s32 lVar2;
  u8 *pbVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  
  if ((s32)param_2 < 1) {
    uVar1 = 0;
  }
  else {
    pbVar3 = (u8 *)(DAT_007ce3f8 + (int)param_2 * 0x2c);
    if ((*pbVar3 & 8) == 0) {
      uVar1 = 0;
    }
    else {
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
      if (uVar4 == *(u16 *)(param_1 + 0x6a)) {
        uVar1 = 4;
      }
      else {
        uVar1 = 0;
      }
    }
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
  u32 uVar9;
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
  if (iVar1 == 0) {
    bVar3 = true;
  }
  else {
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
LAB_002e4af0:
  iVar2 = *(int *)(iVar1 + 0x30);
  fVar6 = *(float *)(iVar2 + 0x90);
  fVar7 = *(float *)(iVar2 + 0x2c);
  if ((*(short *)(DAT_007ce3ec + 0x104) == 9) &&
     (*(int *)(DAT_007ce3ec + 0xb7c) == *(int *)(iVar1 + 8))) {
    if (*(int *)(DAT_007ce3ec + 0xb80) != 0) {
    }
  }
  else {
    *(u32 *)(DAT_007ce3ec + 0xb7c) = *(u32 *)(iVar1 + 8);
    *(u32 *)(DAT_007ce3ec + 0xb80) = 0;
    if (*(char *)(iVar2 + 0xa2) == '\0') {
      FUN_00280870(2,1,&fStack_10,0,0,1);
      FUN_0027ffb0(iVar2,afStack_20);
      afStack_20[1] = 0.0;
      fStack_c = 0.0;
      fStack_40 = afStack_20[0] - fStack_10;
      fStack_3c = 0.0;
      fStack_38 = afStack_20[2] - fStack_8;
      fVar8 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
      fVar8 = DAT_007cad50 * fVar8;
      fStack_10 = fStack_10 + fStack_40 * fVar8;
      fStack_c = fStack_c + fStack_3c * fVar8;
      fStack_8 = fStack_8 + fStack_38 * fVar8;
      fStack_30 = afStack_20[0];
      fStack_2c = DAT_007cad54 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_2c + 0.0;
      fStack_28 = afStack_20[2];
      fVar8 = (float)FUN_0052e930(*(float *)(iVar5 + 0xb8) * 0.5);
      fVar8 = (fVar6 * fVar7 * 5.5) / fVar8;
      fStack_40 = fStack_30 - fStack_10;
      fStack_3c = fStack_2c - fStack_c;
      fStack_38 = fStack_28 - fStack_8;
      FUN_004c69f0(&fStack_40,&fStack_40);
      fStack_64 = fStack_40 * fVar8 + fStack_30 + 0.0;
      fStack_60 = fStack_3c * fVar8 + fStack_2c + 0.0;
      fStack_5c = fStack_38 * fVar8 + fStack_28 + 0.0;
    }
    else {
      if ((*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) &&
         (lVar4 = FUN_002f6330(param_1), lVar4 != 0)) {
        return;
      }
      FUN_00280870(2,1,afStack_20,&fStack_4,0,1);
      FUN_00280130(iVar2,&fStack_10);
      fStack_64 = fStack_80;
      fStack_60 = fStack_7c;
      fStack_5c = fStack_78;
      fVar6 = fStack_4 * 1.25;
      if (fStack_4 * 1.25 <= fStack_7c) {
        fVar6 = fStack_60;
      }
      fStack_60 = fVar6;
    }
    fVar6 = (float)FUN_002d1f30(auStack_74,auStack_58);
    if ((fVar6 <= DAT_007cad58) || (!bVar3)) {
      if (fStack_7c < 25.0) {
        fStack_7c = 25.0;
      }
      if (fStack_60 < 25.0) {
        fStack_60 = 25.0;
      }
      if (bVar3) {
        uVar9 = 0x40200000;
      }
      else {
        uVar9 = 0x3fa00000;
      }
    }
    else {
      if ((*(char *)(iVar2 + 0xa2) == '\x01') &&
         (lVar4 = FUN_0030c3a0(*(u32 *)(iVar2 + 0xa2c)), lVar4 != 0)) {
        FUN_002b6070(0x40100000,0x40000000,param_1);
      }
      else {
        FUN_002b6460(param_1);
      }
      *(u32 *)(DAT_007ce3ec + 0xb80) = 1;
    }
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
void func_002e5060(u64 param_1)

{
  u32 bVar1;
  short sVar2;
  u16 uVar3;
  int iVar4;
  s32 lVar5;
  u32 uVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  u32 uVar10;
  u32 uVar11;
  float fVar12;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  int iStack_ec;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  u8 auStack_d4 [16];
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  u8 auStack_90 [64];
  u8 auStack_50 [16];
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
  
  if ((*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) &&
     (lVar5 = FUN_002f6510(), lVar5 != 0)) {
    return;
  }
  iVar7 = (int)param_1;
  iVar4 = *(int *)(iVar7 + 0xe0);
  if (iVar4 == 0) {
    bVar1 = true;
  }
  else {
    if (*(char *)(*(int *)(iVar4 + 0x30) + 0xa2) == '\0') {
      if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1d) || (*(short *)(DAT_007ce3ec + 0x104) == 0x1c))
      {
        bVar1 = false;
        goto LAB_002e5140;
      }
    }
    else if ((*(short *)(DAT_007ce3ec + 0x104) == 0x1f) ||
            (*(short *)(DAT_007ce3ec + 0x104) == 0x12)) {
      bVar1 = false;
      goto LAB_002e5140;
    }
    bVar1 = true;
  }
LAB_002e5140:
  iVar4 = *(int *)(iVar4 + 0x30);
  FUN_0027ffb0(iVar4,&fStack_40);
  lVar5 = FUN_0030c3a0(*(u32 *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x30) + 0xa2c));
  if ((lVar5 == 0) || (!bVar1)) {
    fStack_3c = (fStack_3c + 0.0) -
                DAT_007cad20 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
    iVar4 = FUN_002ffbc0(2);
    iVar4 = *(int *)(DAT_007ce3ec + 0xb18) + iVar4 * 0x34;
    if (!bVar1) {
    }
    else {
      fStack_e0 = *(float *)(iVar4 + 0x1a8);
      fStack_dc = *(float *)(iVar4 + 0x1ac);
      fStack_d8 = *(float *)(iVar4 + 0x1b0);
    }
    fStack_c4 = fStack_e0;
    fStack_c0 = fStack_dc;
    fStack_bc = fStack_d8;
    FUN_004be310(auStack_d4,&fStack_b8,&fStack_110);
    fVar8 = DAT_007cad7c;
    fVar12 = DAT_007cadd0;
    if (iStack_ec == 0) {
      fVar12 = DAT_007cad7c * fStack_f0;
      fVar8 = fVar12 * fVar12;
      fVar8 = fVar8 * fVar12 *
              (fVar8 * (fVar8 * (fVar8 * (fVar8 * (DAT_007cad34 * fVar8 + DAT_007cad38 + 0.0) +
                                         DAT_007cad3c + 0.0) + DAT_007cad40 + 0.0) +
                       DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar12 + 0.0;
      fStack_f0 = DAT_007cadd0 * fStack_f0;
      fVar12 = fStack_f0 * fStack_f0;
      fVar12 = fVar12 * fStack_f0 *
               (fVar12 * (fVar12 * (fVar12 * (fVar12 * (DAT_007cad34 * fVar12 + DAT_007cad38 + 0.0)
                                             + DAT_007cad3c + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fStack_f0 + 0.0;
    }
    fStack_b8 = fStack_100 * fVar12 + fStack_110 * fVar8 + 0.0;
    fStack_b4 = fStack_fc * fVar12 + fStack_10c * fVar8 + 0.0;
    fStack_b0 = fStack_f8 * fVar12 + fStack_108 * fVar8 + 0.0;
    fStack_ac = fStack_104 * fVar8 + fStack_f4 * fVar12;
    fStack_a0 = fStack_b8;
    fStack_9c = fStack_b4;
    fStack_98 = fStack_b0;
    fStack_94 = fStack_ac;
    if (bVar1) {
      FUN_00351bb0(8);
    }
  }
  else {
    if (((*(short *)(iVar4 + 0xa4) == 0x110) || (*(short *)(iVar4 + 0xa4) == 0x10b)) &&
       (sVar2 = FUN_00282c30(iVar4), sVar2 != 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      fStack_3c = *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.25 + fStack_3c + 0.0;
    }
    lVar5 = FUN_002d6290(*(u32 *)(iVar7 + 0xe0));
    if (lVar5 == 0) {
      uVar3 = FUN_002d1600(*(int *)(iVar7 + 0xe0) + 0x38);
      FUN_00280870(uVar3,1,auStack_50,0,0,1);
    }
    else {
      FUN_0027ffb0(*(u32 *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x38) + 0x30),auStack_50);
    }
    FUN_002d1de0(&fStack_a0,&fStack_40,auStack_50);
    FUN_004be1e0(&fStack_20,0x697890,1,&fStack_a0);
    if (bVar1) {
      fVar8 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
      fVar12 = fVar8 * 2.75;
      fVar8 = fVar8 * 2.25;
      uVar6 = FUN_00357fd0(0);
      if ((uVar6 & 1) == 0) {
        uVar11 = 0xc1f00000;
      }
      else {
        uVar11 = 0x41f00000;
      }
    }
    else {
      fVar8 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
      fVar12 = DAT_007cadc8 * fVar8;
      fVar8 = DAT_007cadcc * fVar8;
      lVar5 = FUN_002ffbc0(3);
      if (lVar5 == 1) {
        uVar11 = 0xc1f00000;
      }
      else if (lVar5 == 0) {
        uVar11 = 0x41f00000;
      }
      else {
        uVar11 = 0;
      }
    }
    if (bVar1) {
      uVar10 = 0xc2200000;
    }
    else {
      lVar5 = FUN_002ffbc0(3);
      if (lVar5 == 1) {
        uVar10 = 0xc1700000;
      }
      else if (lVar5 == 0) {
        uVar10 = 0x41700000;
      }
      else {
        uVar10 = 0;
      }
    }
    FUN_004c31b0(uVar10,auStack_90,0x697870,0);
    FUN_004c31b0(uVar11,auStack_90,0x697880,2);
    FUN_004c6c60(&fStack_10,&fStack_20,auStack_90);
    fVar9 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar7 + 0xb8) * 0.5);
    fVar12 = fVar12 / fVar9;
    fStack_10 = fStack_10 * fVar12;
    fStack_c = fStack_c * fVar12;
    fStack_8 = fStack_8 * fVar12;
    fStack_30 = fStack_40;
    fStack_2c = fStack_3c;
    fStack_28 = fStack_38;
    fStack_e0 = fStack_40 + fStack_10;
    fStack_dc = fStack_3c + fStack_c;
    fStack_d8 = fStack_38 + fStack_8;
    fVar12 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar7 + 0xb8) * 0.5);
    fVar8 = fVar8 / fVar12;
    fStack_10 = fStack_20 * fVar8;
    fStack_c = fStack_1c * fVar8;
    fStack_8 = fStack_18 * fVar8;
    fStack_30 = fStack_40;
    fStack_2c = fStack_3c;
    fStack_28 = fStack_38;
    fStack_c4 = fStack_40 + fStack_10;
    fStack_c0 = fStack_3c + fStack_c;
    fStack_bc = fStack_38 + fStack_8;
    if (fStack_dc < 25.0) {
      fStack_dc = 25.0;
    }
    if (fStack_c0 < 25.0) {
      fStack_c0 = 25.0;
    }
  }
  return;
}

// FUN_002e58a0 NONMATCHING
void func_002e58a0(u64 param_1)

{
  u32 bVar1;
  char cVar2;
  u32 bVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  u32 uStack_100;
  u32 uStack_fc;
  u32 uStack_f8;
  u8 auStack_f4 [16];
  u32 uStack_e4;
  u32 uStack_e0;
  u32 uStack_dc;
  u8 auStack_d8 [24];
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  u32 uStack_94;
  u32 uStack_90;
  u32 uStack_8c;
  u32 uStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  u32 uStack_78;
  u32 uStack_74;
  u32 uStack_70;
  u32 uStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
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
  
  iVar5 = (int)param_1;
  iVar4 = *(int *)(iVar5 + 0xe0);
  if ((iVar4 != 0) && (iVar8 = *(int *)(iVar4 + 0x30), *(char *)(iVar8 + 0xa2) == '\0')) {
    for (uVar6 = 0; iVar4 = *(int *)(iVar5 + 0xe0), uVar6 < *(u16 *)(iVar4 + 0x6a);
        uVar6 = uVar6 + 1 & 0xffff) {
      iVar4 = *(int *)(*(int *)(iVar4 + uVar6 * 4 + 0x38) + 0x30);
      if (*(char *)(iVar4 + 0xa2) == '\x01') {
        FUN_0027fcf0(iVar4,iVar8 + 4);
      }
    }
  }
  if (iVar4 == 0) {
    bVar3 = true;
  }
  else {
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
LAB_002e59dc:
  iVar4 = *(int *)(iVar4 + 0x30);
  bVar1 = *(char *)(iVar4 + 0xa2) != '\0';
  if (bVar1) {
    iVar8 = *(int *)(*(int *)(*(int *)(iVar5 + 0xe0) + 0x38) + 0x30);
    iVar7 = iVar4;
  }
  else {
    iVar7 = *(int *)(*(int *)(*(int *)(iVar5 + 0xe0) + 0x38) + 0x30);
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
  }
  else if ((*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) && (cVar2 == '\0')) {
    uStack_100 = DAT_00697c84;
    uStack_fc = DAT_00697c88;
    uStack_f8 = DAT_00697c8c;
    uStack_e4 = DAT_00697c9c;
    uStack_e0 = DAT_00697ca0;
    uStack_dc = DAT_00697ca4;
    iVar4 = (int)DAT_00697c80;
  }
  else {
    FUN_00280050(iVar8,&fStack_10);
    FUN_00280050(iVar7,&fStack_20);
    fVar13 = *(float *)(iVar8 + 0x90) * *(float *)(iVar8 + 0x2c);
    fVar11 = *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x2c) * 0.5 + fStack_c + 0.0;
    fVar12 = *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) * 0.5 + fStack_1c + 0.0;
    fStack_50 = fStack_10 - fStack_20;
    fStack_4c = fStack_c - fStack_1c;
    fStack_48 = fStack_8 - fStack_18;
    fVar9 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
    fVar9 = DAT_007cad84 * fVar9;
    fStack_30 = fStack_50 * fVar9 + fStack_20;
    fStack_2c = fStack_4c * fVar9 + fStack_1c;
    fStack_28 = fStack_48 * fVar9 + fStack_18;
    fStack_a8 = *(float *)(iVar5 + 0x9c) - fStack_30;
    fStack_a4 = *(float *)(iVar5 + 0xa4) - fStack_28;
    FUN_004c6b20(&fStack_a8,&fStack_a8);
    fStack_b0 = fStack_48;
    fStack_ac = -fStack_50;
    fVar9 = fStack_48 * fStack_a8 + fStack_ac * fStack_a4;
    if (bVar1) {
      fVar10 = 2.5;
    }
    else {
      fVar10 = 1.5;
    }
    fVar10 = fVar10 * fVar13;
    if (0.0 <= fVar9) {
      fStack_40 = fStack_48 * fVar10 + fStack_10 + 0.0;
      fStack_38 = (fStack_8 + 0.0) - fStack_50 * fVar10;
    }
    else {
      fStack_40 = (fStack_10 + 0.0) - fStack_48 * fVar10;
      fStack_38 = fStack_50 * fVar10 + fStack_8 + 0.0;
    }
    fStack_3c = fVar11;
    if (bVar1) {
      fStack_2c = (fStack_2c + 0.0) - DAT_007cad84 * fVar12;
      fVar11 = 3.5;
    }
    else {
      if (fVar11 < fVar12) {
        fStack_2c = (fStack_2c + 0.0) - DAT_007cad84 * fVar12;
      }
      else {
        fStack_2c = DAT_007cad20 * fVar12 + fStack_2c + 0.0;
        fStack_3c = (fStack_c + 0.0) - DAT_007cad20 * fVar11;
      }
      fVar11 = 2.5;
    }
    FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_78);
    fStack_c0 = fStack_30;
    fStack_bc = fStack_28;
    fStack_b8 = fStack_40;
    fStack_b4 = fStack_38;
    fStack_58 = fStack_10;
    fStack_54 = fStack_8;
    fVar12 = (float)FUN_002d1fd0(&fStack_c0,&fStack_b8,&fStack_58,&fStack_60);
    fStack_40 = fStack_60;
    fStack_38 = fStack_5c;
    fVar10 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
    fVar10 = (fVar12 + fVar11 * fVar13) / fVar10;
    fStack_50 = fStack_50 * fVar10;
    fStack_4c = fStack_4c * fVar10;
    fStack_48 = fStack_48 * fVar10;
    if (fVar9 < 0.0) {
      fVar9 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
      fVar9 = fVar10 * fVar9 * 0.21875 * 1.25;
      fStack_68 = fStack_50;
      fStack_64 = fStack_48;
      FUN_004c6b20(&fStack_68,&fStack_68);
      fStack_40 = fStack_64 * fVar9 + fStack_40 + 0.0;
      fStack_38 = (fStack_38 + 0.0) - fStack_68 * fVar9;
    }
    fStack_84 = fStack_40 + fStack_50;
    fStack_80 = fStack_3c + fStack_4c;
    fStack_7c = fStack_38 + fStack_48;
    if (fStack_80 < 25.0) {
      fStack_80 = 25.0;
    }
    fVar9 = (float)FUN_002d1f30(&uStack_94,&uStack_78);
    if (((!bVar1) || (DAT_007cad58 < fVar9)) && (bVar3)) {
      uStack_94 = uStack_78;
      uStack_90 = uStack_74;
      uStack_8c = uStack_70;
      uStack_88 = uStack_6c;
      FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_78);
      fVar10 = fVar10 + 200.0;
      fStack_50 = fStack_50 * fVar10;
      fStack_4c = fStack_4c * fVar10;
      fStack_48 = fStack_48 * fVar10;
      fStack_a0 = fStack_40 + fStack_50;
      fStack_9c = fStack_3c + fStack_4c;
      fStack_98 = fStack_38 + fStack_48;
      if (fStack_9c < 25.0) {
        fStack_9c = 25.0;
      }
      FUN_00351bb0(8);
    }
  }
  return;
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
    if (sVar1 == 0xf1) {
      *(float *)(iVar3 + 4) =
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.5f + *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadb8 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 6.0f;
    }
    else if ((((((sVar1 == 0x128) || (sVar1 == 0x125)) || (sVar1 == 0x124)) ||
              ((sVar1 == 0x123 || (sVar1 == 0x122)))) ||
             ((sVar1 == 0x121 || ((sVar1 == 0x120 || (sVar1 == 0x11f)))))) ||
            ((sVar1 == 0x11e ||
             ((((sVar1 == 0x11d || (sVar1 == 0x11c)) || (sVar1 == 0x11b)) ||
              ((sVar1 == 0x11a || (sVar1 == 0x111)))))))) {
      *(float *)(iVar3 + 4) =
           *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) * 0.5f + *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadb8 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 6.0f;
    }
    else if (sVar1 == 0x10d) {
      *(float *)(iVar3 + 4) =
           DAT_007cad78 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad20 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
    }
    else if (sVar1 == 0x10a) {
      *(float *)(iVar3 + 4) =
           DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
    }
    else if (sVar1 == 0x107) {
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
    }
    else if (sVar1 == 0x115) {
      *(float *)(iVar3 + 4) =
           DAT_007cad88 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
    }
    else if (sVar1 == 0x106) {
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad78 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
    }
    else if (sVar1 == 0x105) {
      *(float *)(iVar3 + 4) =
           DAT_007cad78 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad84 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.5f;
    }
    else if (sVar1 == 0x104) {
      *(float *)(iVar3 + 4) =
           DAT_007cad54 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad80 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 5.0f;
    }
    else if (sVar1 == 0x103) {
      *(float *)(iVar3 + 4) =
           DAT_007cad84 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cada4 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
    }
    else if ((sVar1 == 0x102) || (sVar1 == 0x101)) {
      *(float *)(iVar3 + 4) =
           DAT_007cada4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cad20 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
    }
    else if (sVar1 == 0x100) {
      *(float *)(iVar3 + 4) =
           DAT_007cad20 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) * 0.125f;
      fVar6 = 4.5f;
    }
    else {
      *(float *)(iVar3 + 4) =
           DAT_007cad20 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) +
           *(float *)(iVar3 + 4) + 0.0f;
      *(float *)(iVar2 + 4) =
           (*(float *)(iVar2 + 4) + 0.0f) -
           DAT_007cadbc * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c);
      fVar6 = 4.0f;
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
      *(u32 *)(iVar2 + 4) = 0x432a0000;
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
      *(u32 *)(iVar2 + 4) = 0x432a0000;
      fVar6 = 6.0f;
    }
  }
  else {
    fVar6 = 4.5f;
  }
  return fVar6;
}

// FUN_002e6a20 NONMATCHING
void func_002e6a20(BtlCamera* camera, float weight)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  u8 auStack_e4 [16];
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  u8 auStack_c8 [24];
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  u8 auStack_90 [16];
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
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
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)camera;
  iVar5 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 0xe0) + 0x38) + 0x30);
  fVar6 = func_002e6130((BtlUnit*)(uintptr_t)iVar5,(BtlUnit*)(uintptr_t)iVar1,&fStack_10,&fStack_20);
  fVar8 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fStack_a8 = *(float *)(iVar2 + 0x9c) - fStack_10;
  fStack_a4 = *(float *)(iVar2 + 0xa4) - fStack_8;
  FUN_004c6b20(&fStack_a8,&fStack_a8);
  if (*(char *)(iVar5 + 0xa2) == '\0') {
    FUN_002d1de0(auStack_90,&fStack_10,&fStack_20);
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_90);
    fStack_50 = fStack_50 * fVar8;
    fStack_4c = fStack_4c * fVar8;
    fStack_48 = fStack_48 * fVar8;
    fStack_20 = fStack_20 + fStack_50;
    fStack_1c = fStack_1c + fStack_4c;
    fStack_18 = fStack_18 + fStack_48;
    fStack_60 = fStack_10 - fStack_20;
    fStack_5c = fStack_c - fStack_1c;
    fStack_58 = fStack_8 - fStack_18;
    fStack_38 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_30 = fStack_10;
    fStack_28 = fStack_8;
    fVar8 = *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c) * 1.25;
    fStack_38 = DAT_007cad88 * fStack_38;
    fStack_40 = fStack_60 * fStack_38;
    fStack_3c = fStack_5c * fStack_38;
    fStack_38 = fStack_58 * fStack_38;
    fVar7 = fStack_c;
    iVar4 = iVar5;
    iVar5 = iVar1;
  }
  else {
    FUN_002d1de0(auStack_90,&fStack_20,&fStack_10);
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_90);
    fStack_50 = fStack_50 * fVar7;
    fStack_4c = fStack_4c * fVar7;
    fStack_48 = fStack_48 * fVar7;
    fStack_10 = fStack_10 + fStack_50;
    fStack_c = fStack_c + fStack_4c;
    fStack_8 = fStack_8 + fStack_48;
    fStack_60 = fStack_10 - fStack_20;
    fStack_5c = fStack_c - fStack_1c;
    fStack_58 = fStack_8 - fStack_18;
    fStack_38 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_30 = fStack_20;
    fStack_28 = fStack_18;
    fVar8 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5;
    fStack_38 = DAT_007cad50 * fStack_38;
    fStack_40 = fStack_60 * fStack_38;
    fStack_3c = fStack_5c * fStack_38;
    fStack_38 = fStack_58 * fStack_38;
    fVar7 = fStack_1c;
    iVar4 = iVar1;
  }
  fStack_40 = fStack_40 + fStack_20;
  fStack_3c = fStack_3c + fStack_1c;
  fStack_38 = fStack_38 + fStack_18;
  fStack_b0 = fStack_58;
  fStack_ac = -fStack_60;
  if (0.0 <= fStack_58 * fStack_a8 + fStack_ac * fStack_a4) {
    fStack_70 = fStack_58 * fVar8 + fStack_30 + 0.0;
    fStack_68 = (fStack_28 + 0.0) - fStack_60 * fVar8;
  }
  else {
    fStack_70 = (fStack_30 + 0.0) - fStack_58 * fVar8;
    fStack_68 = fStack_60 * fVar8 + fStack_28 + 0.0;
  }
  fVar8 = fStack_28;
  FUN_004be1e0(&fStack_60,0x6978a0,1,auStack_c8);
  fStack_a0 = fStack_40;
  fStack_9c = fStack_38;
  fStack_98 = fStack_70;
  fStack_94 = fStack_68;
  fStack_78 = fStack_30;
  fStack_74 = fVar8;
  fVar8 = (float)FUN_002d1fd0(&fStack_a0,&fStack_98,&fStack_78,&fStack_80);
  fVar8 = fVar6 * *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) + fVar8 + 0.0;
  fStack_70 = fStack_80;
  fStack_68 = fStack_7c;
  fStack_6c = fVar7;
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar6 = 100.0;
  if (100.0 <= fVar8 / fVar7) {
    fVar6 = fVar8 / fVar7;
  }
  fStack_60 = fStack_60 * fVar6;
  fStack_5c = fStack_5c * fVar6;
  fStack_58 = fStack_58 * fVar6;
  fStack_d4 = fStack_70 + fStack_60;
  fStack_d0 = fStack_6c + fStack_5c;
  fStack_cc = fStack_68 + fStack_58;
  if (fStack_d0 < 22.5) {
    fStack_d0 = 22.5;
  }
  fVar6 = (float)FUN_002d1f30(auStack_e4,auStack_c8);
  if (DAT_007cadc4 < fVar6) {
    uVar3 = 3;
  }
  else {
    uVar3 = 0x33;
  }
  if (weight == 0.0) {
    FUN_004be1e0(&fStack_60,0x6978a0,1,auStack_e4);
    fStack_60 = fStack_60 * 150.0;
    fStack_5c = fStack_5c * 150.0;
    fStack_58 = fStack_58 * 150.0;
    fStack_d4 = fStack_f0 + fStack_60;
    fStack_d0 = fStack_ec + fStack_5c;
    fStack_cc = fStack_e8 + fStack_58;
    if (fStack_d0 < 22.5) {
      fStack_d0 = 22.5;
    }
  }
  else {
  }
  return;
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
void func_002e7330(u64 param_1)

{
  int iVar1;
  char cVar2;
  u16 uVar3;
  u32 uVar4;
  s32 lVar5;
  u64 uVar6;
  int iVar7;
  u8 *unaff_s1_lo;
  
  iVar7 = (int)param_1;
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
    if (lVar5 == 0) {
      uVar3 = *(u16 *)(iVar1 + 0xa4);
    }
    else {
      uVar3 = 3;
    }
    switch(uVar3) {
    case 1:
      uVar4 = FUN_00308c60(*(u32 *)(iVar1 + 0xa2c));
      unaff_s1_lo = (u8 *)((uVar4 & 0xff) * 0xf4 + 0x697cc0);
      break;
    case 2:
      unaff_s1_lo = (u8 *)0x698460;
      break;
    case 3:
      cVar2 = FUN_003093a0(*(u32 *)(iVar1 + 0xa2c));
      if (cVar2 == '\x03') {
        unaff_s1_lo = (u8 *)0x698748;
      }
      else if (cVar2 == '\x02') {
        if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
          unaff_s1_lo = (u8 *)0x698e40;
        }
        else {
          unaff_s1_lo = (u8 *)0x698654;
        }
      }
      else if (cVar2 == '\x01') {
        unaff_s1_lo = (u8 *)0x698560;
      }
      break;
    case 4:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
        unaff_s1_lo = (u8 *)0x698f40;
      }
      else {
        unaff_s1_lo = (u8 *)0x698840;
      }
      break;
    case 5:
      unaff_s1_lo = (u8 *)0x698940;
      break;
    case 7:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
        unaff_s1_lo = (u8 *)0x699040;
      }
      else {
        unaff_s1_lo = (u8 *)0x698a40;
      }
      break;
    case 8:
      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {
        unaff_s1_lo = (u8 *)0x699140;
      }
      else {
        unaff_s1_lo = (u8 *)0x698b40;
      }
      break;
    case 9:
      unaff_s1_lo = (u8 *)0x698c40;
      break;
    case 10:
      unaff_s1_lo = DAT_00698d40;
    }
    if (lVar5 == 0) {
      uVar6 = 9;
    }
    else {
      uVar6 = 5;
    }
    FUN_002b6bf0(iVar7 + 0xec,*(int *)(iVar7 + 0xe0),*(u32 *)(*(int *)(iVar7 + 0xe0) + 0x38),
                 unaff_s1_lo,uVar6);
  }
  lVar5 = FUN_002b6cd0(iVar7 + 0xec);
  if (lVar5 != 0) {
    if (*(short *)((int)lVar5 + 0x1c) == 1) {
      *(u32 *)(iVar7 + 0x110) = 1;
    }
    else {
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

// FUN_002e7890 NONMATCHING
void func_002e7890(u64 param_1)
{
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
  f32 startTransform[5];
  f32 endTransform[5];
  RwV3d startPosition;
  RwV3d endPosition;

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
    randomIndex = FUN_002ffbc0(2);
    voiceType = unit->unk_9f0;
    voiceData = base + (voiceType * 0x68) +
                ((randomIndex & 0xffff) * 0x34) + 4;
    btlVoicePlayCameraVoice(voiceData, startTransform, endTransform,
                             &startPosition, &endPosition);
    FUN_002a3e80(0.0f, (u8 *)work->action, 0, 0, 0x40);
    break;
  case 6:
    action = work->action;
    if ((action->unk_1a & 1) == 0)
      break;
    if (unit->genus == 0)
      voiceData = base + 0x3ac + 4;
    else {
      randomIndex = FUN_002ffbc0(2);
      voiceData = base + ((randomIndex & 0xffff) * 0x34) + 0x20c + 4;
    }
    btlVoicePlayCameraVoice(voiceData, startTransform, endTransform,
                             &startPosition, &endPosition);
    FUN_002a3e80(0.0f, (u8 *)work->action, 0, 0, 0x40);
    break;
  }
}


// FUN_002e7db0 NONMATCHING
void func_002e7db0(u64 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  u32 uStack_d4;
  u32 uStack_d0;
  u32 uStack_cc;
  u32 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  u32 uStack_b8;
  u32 uStack_b4;
  u32 uStack_b0;
  u32 uStack_ac;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float afStack_78 [2];
  u64 uStack_70;
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
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar2 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  FUN_0027ffb0(iVar1,&fStack_10);
  FUN_0027ffb0(iVar2,&fStack_20);
  fVar5 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
  if (450.0 <= fVar5 * 0.5 + fStack_c + 0.0) {
    fStack_c = (fStack_c + 0.0) - DAT_007cad20 * fVar5;
  }
  fStack_50 = fStack_10 - fStack_20;
  fStack_4c = fStack_c - fStack_1c;
  fStack_48 = fStack_8 - fStack_18;
  fVar5 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fStack_98 = *(float *)(iVar3 + 0x9c) - fStack_10;
  fStack_94 = *(float *)(iVar3 + 0xa4) - fStack_8;
  FUN_004c6b20(&fStack_98,&fStack_98);
  fVar5 = DAT_007cad88 * fVar5;
  fStack_40 = fStack_50 * fVar5 + fStack_20;
  fStack_3c = fStack_4c * fVar5 + fStack_1c;
  fStack_38 = fStack_48 * fVar5 + fStack_18;
  fStack_30 = fStack_20;
  fStack_28 = fStack_18;
  fVar5 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 1.5;
  fStack_a0 = fStack_48;
  fStack_9c = -fStack_50;
  fVar7 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
  fStack_5c = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25 + fStack_1c + 0.0;
  if (0.0 <= fVar7) {
    fStack_60 = fStack_48 * fVar5 + fStack_20 + 0.0;
    fStack_58 = (fStack_18 + 0.0) - fStack_50 * fVar5;
  }
  else {
    fStack_60 = (fStack_20 + 0.0) - fStack_48 * fVar5;
    fStack_58 = fStack_50 * fVar5 + fStack_18 + 0.0;
  }
  uStack_70 = CONCAT44(fStack_4c,fStack_50);
  fStack_68 = fStack_48;
  FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_d4);
  fStack_90 = fStack_40;
  fStack_8c = fStack_38;
  fStack_88 = fStack_60;
  fStack_84 = fStack_58;
  afStack_78[0] = fStack_30;
  fVar5 = (float)FUN_002d1fd0(&fStack_90,&fStack_88,afStack_78,&fStack_80);
  fVar6 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 3.5 + fVar5 + 0.0;
  fStack_60 = fStack_80;
  fStack_5c = fStack_1c;
  fStack_58 = fStack_7c;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar5 = 500.0;
  if (500.0 <= fVar6 / fVar4) {
    fVar5 = fVar6 / fVar4;
  }
  fVar4 = fVar5 - 15.0;
  if (0.0 <= fVar7) {
    fVar7 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
    fStack_60 = (fStack_60 + 0.0) - fStack_68 * fVar7;
    fStack_58 = (float)uStack_70 * fVar7 + fStack_58 + 0.0;
  }
  fStack_5c = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25 + fStack_1c + 0.0;
  fStack_e0 = fStack_60 + fStack_50 * fVar4;
  fStack_dc = fStack_5c + fStack_4c * fVar4;
  fStack_d8 = fStack_58 + fStack_48 * fVar4;
  uStack_b8 = uStack_d4;
  uStack_b4 = uStack_d0;
  uStack_b0 = uStack_cc;
  uStack_ac = uStack_c8;
  fVar5 = fVar5 + 85.0;
  fStack_c4 = fStack_50 * fVar5 + fStack_60 + 0.0;
  fStack_c0 = fStack_4c * fVar5 + fStack_5c + 0.0;
  fStack_bc = fStack_48 * fVar5 + fStack_58 + 0.0;
  if (fStack_dc < 25.0) {
    fStack_dc = 25.0;
  }
  if (fStack_c0 < 25.0) {
    fStack_c0 = 25.0;
  }
  return;
}

// FUN_002e82b0 NONMATCHING
void func_002e82b0(u64 param_1)

{
  short sVar1;
  u16 uVar2;
  u32 uVar3;
  int iVar4;
  u32 uVar5;
  s32 lVar6;
  int iVar7;
  u32 uStack_c0;
  u32 uStack_bc;
  u32 uStack_b8;
  u8 auStack_b4 [16];
  u32 uStack_a4;
  u32 uStack_a0;
  u32 uStack_9c;
  u8 auStack_98 [24];
  u32 uStack_80;
  u32 uStack_7c;
  u32 uStack_78;
  u8 auStack_74 [16];
  u32 uStack_64;
  u32 uStack_60;
  u32 uStack_5c;
  u8 auStack_58 [24];
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u8 auStack_34 [16];
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u8 auStack_18 [24];
  
  uVar2 = FUN_002a7830();
  iVar7 = (int)param_1;
  *(u16 *)(iVar7 + 0x110) = uVar2;
  uVar5 = FUN_002d1600(*(int *)(iVar7 + 0xe0) + 0x38);
  *(u32 *)(iVar7 + 0x120) = 0;
  if ((*(u16 *)(*(int *)(iVar7 + 0xe0) + 0x1a) & 0x10) != 0) {
    iVar4 = *(int *)(*(int *)(iVar7 + 0xe0) + 0x30);
    switch(*(u16 *)(iVar4 + 0xa4)) {
    case 0xe9:
    case 0xea:
    case 0xeb:
    case 0xec:
    case 0xed:
    case 0xee:
    case 0xef:
    case 0xf0:
      FUN_002880e0(*(u32 *)(iVar4 + 0xa00),0);
      *(u32 *)(iVar7 + 0x120) =
           *(u32 *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x30) + 0xa00);
      *(u16 *)(iVar7 + 0x124) = 1;
      break;
    default:
      FUN_002880e0(*(u32 *)(iVar4 + 0xa00),1);
    }
  }
  switch(*(u16 *)(iVar7 + 0x110)) {
  case 1:
    if ((*(u16 *)(*(int *)(iVar7 + 0xe0) + 0x1a) & 0x10) == 0) {
      func_002e4a40(param_1);
    }
    else {
      FUN_002ac540(param_1);
    }
    break;
  case 2:
    if ((uVar5 & 2) == 0) {
      func_002e7db0(param_1);
      return;
    }
  case 4:
    if ((uVar5 & 2) == 0) {
      lVar6 = FUN_0030c3a0(*(u32 *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x30) + 0xa2c));
      if ((lVar6 == 0) || (lVar6 = FUN_00289f40(*(u32 *)(iVar7 + 0xe0)), lVar6 == 0)) {
        func_002e7db0(param_1);
      }
      else {
        func_002e6a20((BtlCamera*)param_1,0.75f);
      }
    }
    else {
switchD_002e8398_caseD_3:
      if ((uVar5 & 2) == 0) {
switchD_002e8398_caseD_6:
        if ((*(u16 *)(*(int *)(iVar7 + 0xe0) + 0x1a) & 1) != 0) {
          if (*(char *)(*(int *)(*(int *)(iVar7 + 0xe0) + 0x30) + 0xa2) == '\0') {
            iVar4 = *(int *)(DAT_007ce3ec + 0xb18);
            uStack_80 = *(u32 *)(iVar4 + 0x3b0);
            uStack_7c = *(u32 *)(iVar4 + 0x3b4);
            uStack_78 = *(u32 *)(iVar4 + 0x3b8);
            uStack_64 = *(u32 *)(iVar4 + 0x3c8);
            uStack_60 = *(u32 *)(iVar4 + 0x3cc);
            uStack_5c = *(u32 *)(iVar4 + 0x3d0);
            sVar1 = *(short *)(iVar4 + 0x3ac);
          }
          else {
            uVar3 = FUN_002ffbc0(2);
            iVar4 = *(int *)(DAT_007ce3ec + 0xb18) + (uVar3 & 0xffff) * 0x34;
            uStack_c0 = *(u32 *)(iVar4 + 0x210);
            uStack_bc = *(u32 *)(iVar4 + 0x214);
            uStack_b8 = *(u32 *)(iVar4 + 0x218);
            uStack_a4 = *(u32 *)(iVar4 + 0x228);
            uStack_a0 = *(u32 *)(iVar4 + 0x22c);
            uStack_9c = *(u32 *)(iVar4 + 0x230);
            sVar1 = *(short *)(iVar4 + 0x20c);
          }
        }
      }
      else {
        uVar3 = FUN_002ffbc0(2);
        iVar4 = *(int *)(DAT_007ce3ec + 0xb18) + (uVar3 & 0xffff) * 0x34;
        uStack_40 = *(u32 *)(iVar4 + 0x1a8);
        uStack_3c = *(u32 *)(iVar4 + 0x1ac);
        uStack_38 = *(u32 *)(iVar4 + 0x1b0);
        uStack_24 = *(u32 *)(iVar4 + 0x1c0);
        uStack_20 = *(u32 *)(iVar4 + 0x1c4);
        uStack_1c = *(u32 *)(iVar4 + 0x1c8);
        sVar1 = *(short *)(iVar4 + 0x1a4);
      }
    }
    break;
  case 3:
  case 5:
    goto switchD_002e8398_caseD_3;
  case 6:
    goto switchD_002e8398_caseD_6;
  }
  return;
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

// FUN_002e92c0 NONMATCHING
void func_002e92c0(void)

{
  short sVar1;
  int iVar2;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_c = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(short *)(iVar2 + 0xa4);
    if (sVar1 == 5) {
      uStack_10 = 0;
      uStack_8 = 0x43c80000;
      *(u8 *)(iVar2 + 0x9f0) = 1;
    }
    else if (sVar1 == 2) {
      uStack_10 = 0x437a0000;
      uStack_8 = 0x43fa0000;
      *(u8 *)(iVar2 + 0x9f0) = 2;
    }
    else if (sVar1 == 1) {
      uStack_10 = 0xc37a0000;
      uStack_8 = 0x43fa0000;
      *(u8 *)(iVar2 + 0x9f0) = 0;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&uStack_10);
    FUN_0027f650(iVar2,&uStack_10);
  }
  for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(short *)(iVar2 + 0xa4);
    if (sVar1 == 0x114) {
      uStack_10 = 0x43480000;
      uStack_8 = 0x42c80000;
    }
    else if (sVar1 == 0x113) {
      uStack_10 = 0xc3480000;
      uStack_8 = 0x42c80000;
    }
    else if (sVar1 == 0x100) {
      uStack_10 = 0;
      uStack_8 = 0xc3c80000;
    }
    FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,&uStack_10);
    FUN_0027f650(iVar2,&uStack_10);
  }
  return;
}

// FUN_002e9450 NONMATCHING
void func_002e9450(void)

{
  short sVar1;
  int iVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar3 = FUN_002b8f90(0);
  uVar4 = FUN_002f87e0(1);
  FUN_002b90d0(uVar3,uVar4);
  iVar10 = 0;
  iVar12 = 0;
  iVar9 = 0;
  iVar7 = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(short *)(iVar2 + 0xa4);
    iVar6 = iVar7;
    iVar8 = iVar2;
    iVar11 = iVar12;
    if (((sVar1 != 5) && (iVar6 = iVar2, iVar8 = iVar9, sVar1 != 2)) &&
       (iVar6 = iVar7, iVar11 = iVar2, sVar1 != 1)) {
      iVar10 = iVar2;
      iVar11 = iVar12;
    }
    iVar12 = iVar11;
    iVar9 = iVar8;
    iVar7 = iVar6;
  }
  iVar6 = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    iVar8 = iVar2;
    if (*(short *)(iVar2 + 0xa4) != 0x100) {
      iVar8 = iVar6;
    }
    iVar6 = iVar8;
  }
  uVar4 = FUN_002bc950(iVar7,iVar9,iVar10);
  FUN_0027ed20(uVar4,1);
  uVar4 = FUN_002baf90(uVar3,iVar12,iVar6,0,0x200);
  FUN_0027ed20(uVar4,2);
  uVar5 = FUN_002bc950(0,0,0);
  *(u8 *)uVar5 = 4;
  *(u64 *)((u8 *)uVar5 + 8) = *(u64 *)((int)uVar4 + 0x58);
  FUN_0027ed20(uVar5,1);
  FUN_002b9030(uVar3);
  return;
}

// FUN_002e95f0 NONMATCHING
void func_002e95f0(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x100) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x699c10);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

// FUN_002e97e0 NONMATCHING
int func_002e97e0(void)

{
  int iVar1;
  s32 lVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  u32 auStack_20 [8];
  
  iVar5 = 0;
  iVar4 = *(int *)(iGpffffb6fc + 0x158);
  do {
    if (iVar4 == 0) {
LAB_002e9848:
      if (iVar5 != 0) {
        FUN_002d5dc0(auStack_20);
        auStack_20[0] = 0xfff00001;
        for (iVar4 = *(int *)(iGpffffb6fc + 0x14c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4a8)) {
          if ((*(u16 *)(iVar4 + 0x1a) & 1) != 0) {
            iVar1 = *(int *)(iVar4 + 0x30);
            if (((*(char *)(iVar1 + 0xa2) == '\x01') && (*(short *)(iVar1 + 0xa4) != 0x100)) &&
               (lVar2 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c),0), lVar2 == 0)) {
              uVar3 = FUN_002d7e20(iVar4,iVar4,auStack_20,1,1);
              FUN_0027ed20(uVar3,1);
              uVar3 = FUN_00284200(0x3f800000,iVar1,2,0,0);
              FUN_0027ed20(uVar3,1);
            }
          }
        }
      }
      return iVar5;
    }
    if ((*(short *)(iVar4 + 0xa4) == 0x100) &&
       (lVar2 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0), lVar2 != 0)) {
      iVar5 = 1;
      goto LAB_002e9848;
    }
    iVar4 = *(int *)(iVar4 + 0xa34);
  } while( true );
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

// FUN_002e9ac0 NONMATCHING
void func_002e9ac0(void)

{
  short sVar1;
  int iVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar3 = FUN_002b8f90(0);
  uVar4 = FUN_002f87e0(1);
  FUN_002b90d0(uVar3,uVar4);
  iVar10 = 0;
  iVar12 = 0;
  iVar9 = 0;
  iVar7 = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
    sVar1 = *(short *)(iVar2 + 0xa4);
    iVar6 = iVar7;
    iVar8 = iVar2;
    iVar11 = iVar12;
    if (((sVar1 != 7) && (iVar6 = iVar2, iVar8 = iVar9, sVar1 != 5)) &&
       (iVar6 = iVar7, iVar11 = iVar2, sVar1 != 1)) {
      iVar10 = iVar2;
      iVar11 = iVar12;
    }
    iVar12 = iVar11;
    iVar9 = iVar8;
    iVar7 = iVar6;
  }
  uVar4 = FUN_002bc950(iVar7,iVar9,iVar10);
  FUN_0027ed20(uVar4,1);
  uVar4 = FUN_002baf90(uVar3,iVar12,iVar12,0,0x200);
  FUN_0027ed20(uVar4,2);
  uVar5 = FUN_002bc950(0,0,0);
  *(u8 *)uVar5 = 4;
  *(u64 *)((u8 *)uVar5 + 8) = *(u64 *)((int)uVar4 + 0x58);
  FUN_0027ed20(uVar5,1);
  FUN_002b9030(uVar3);
  return;
}

// FUN_002e9c20 NONMATCHING
void func_002e9c20(u64 *param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  u8 *puVar4;
  u64 uVar5;
  u64 uVar6;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  iVar1 = *(int *)(param_1 + 6);
  uVar5 = FUN_002b8f90(0);
  if (*(short *)(iVar1 + 0xa4) == 0x102) {
    uVar6 = FUN_002f87e0(3);
    FUN_002b90d0(uVar5,uVar6);
    uVar6 = FUN_002dd690(3,0x699c68);
    FUN_0027ed20(uVar6,1);
  }
  else if (*(short *)(iVar1 + 0xa4) == 0x101) {
    uVar6 = FUN_002f87e0(2);
    FUN_002b90d0(uVar5,uVar6);
    uVar6 = FUN_002dd690(3,0x699c58);
    FUN_0027ed20(uVar6,1);
  }
  uVar6 = FUN_00284200(0x3f800000,iVar1,0x12,0,2);
  iVar3 = (int)uVar6;
  *(u16 *)(iVar3 + 0x48) = 2;
  *(u64 *)(iVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,1);
  uVar6 = FUN_002b8d60(3,0xfff);
  puVar4 = (u8 *)uVar6;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(iVar3 + 0x58);
  *(u64 *)(puVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,1);
  uVar6 = FUN_0027fe90(iVar1,0,0x6978b0,0);
  puVar4 = (u8 *)uVar6;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(iVar3 + 0x58);
  *(u64 *)(puVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,1);
  uVar6 = FUN_002a3b40(0,1);
  puVar4 = (u8 *)uVar6;
  *puVar4 = 4;
  *(u64 *)(puVar4 + 8) = *(u64 *)(iVar3 + 0x58);
  *(u64 *)(puVar4 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,0);
  uVar6 = FUN_002baf90(uVar5,iVar1,iVar1,0,0x200);
  *(u64 *)((int)uVar6 + 0x60) = *param_1;
  FUN_0027ed20(uVar6,2);
  sVar2 = FUN_002d4e10(2,0x80000);
  if (sVar2 == 1) {
    uVar6 = FUN_002db890();
    *(u16 *)((int)uVar6 + 0x48) = 0x2d;
    FUN_0027ed20(uVar6,1);
    uVar6 = FUN_002db800(0x20,0x17);
    *(u16 *)((int)uVar6 + 0x48) = 0x2d;
    FUN_0027ed20(uVar6,1);
  }
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x400000;
  *(u16 *)(iGpffffb6fc + 0x18) = *(u16 *)(iGpffffb6fc + 0x18) | 7;
  FUN_002b9030(uVar5);
  return;
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

// FUN_002ea210 NONMATCHING
void func_002ea210(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x103) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x699cb0);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

// FUN_002ea590 NONMATCHING
void func_002ea590(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x104) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x699d00);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

// FUN_002ea860 NONMATCHING
void func_002ea860(void)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  short sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  u16 auStack_18 [4];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar6 = (u32*)DAT_00699d10;
  puVar5 = auStack_30;
  iVar4 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar4 = iVar4 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar4);
  auStack_18[0] = uGpffff9ca8;
  auStack_18[1] = uGpffff9caa;
  auStack_18[2] = uGpffff9cac;
  sVar7 = 0;
  uStack_c = 0;
  for (iVar4 = *(int *)(iGpffffb6fc + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 1) {
      uStack_10 = 0xc3160000;
      uStack_8 = 0x43e10000;
      *(u8 *)(iVar4 + 0x9f0) = 1;
    }
    else {
      iVar3 = (int)sVar7;
      uStack_10 = auStack_30[iVar3 * 2];
      uStack_8 = auStack_30[iVar3 * 2 + 1];
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[iVar3];
      sVar7 = sVar7 + 1;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar4 = *(int *)(iGpffffb6fc + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    sVar7 = *(short *)(iVar4 + 0xa4);
    if (sVar7 == 0x115) {
      uStack_10 = 0;
      uStack_8 = 0xc3c80000;
    }
    else if (sVar7 == 0x106) {
      uStack_10 = 0x43960000;
      uStack_8 = 0xc3fa0000;
    }
    else if (sVar7 == 0x105) {
      uStack_10 = 0xc3960000;
      uStack_8 = 0xc3c80000;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  return;
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
  short sVar1;
  u64 *puVar2;
  int iVar3;
  u16 uVar4;
  u16 uVar5;
  u16 uVar6;
  int iVar7;
  u8 *puVar8;
  u8 *puVar9;
  u64 uVar10;
  u64 uVar11;
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
  uVar10 = FUN_002b8f90(0);
  FUN_002bb6f0(0x166,auStack_90);
  uVar11 = FUN_002bac00(uVar10,auStack_90,0);
  iVar7 = (int)uVar11;
  *(u64 *)(iVar7 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002dd4a0(0x166,0);
  puVar8 = (u8 *)uVar11;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(iVar7 + 0x58);
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002baf90(uVar10,aiStack_8[0],iVar3,0,0);
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
    uVar11 = FUN_002db890();
    *(u16 *)((int)uVar11 + 0x48) = 0x1e;
    FUN_0027ed20(uVar11,1);
    uVar11 = FUN_002db800(0x20,0x1f);
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
  uVar11 = FUN_002bd590(*(u32 *)(unaff_s2_lo + 6),0x166);
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
  uVar11 = FUN_00284200(0x3f800000,aiStack_8[0],0x18,0,0);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_00284200(0x3f800000,iVar3,0x18,0,0);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002dd830(aiStack_8[0],0xe,0,3);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002b8d60(3,0xfff);
  puVar9 = (u8 *)uVar11;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar9 + 0x60) = *unaff_s2_lo;
  FUN_0027ed20(uVar11,1);
  uVar11 = FUN_002a3b40(0,1);
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
  u64 uVar12;
  u64 uVar13;
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
  uVar12 = FUN_002b8f90(0);
  FUN_002bb6f0(0x165,auStack_90);
  uVar13 = FUN_002bac00(uVar12,auStack_90,0);
  iVar7 = (int)uVar13;
  *(u64 *)(iVar7 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_002dd4a0(0x165,0);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(iVar7 + 0x58);
  FUN_0027ed20(uVar13,1);
  iVar4 = aiStack_8[1];
  uVar13 = FUN_002baf90(uVar12,aiStack_8[0],aiStack_8[1],0,0);
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
  uVar13 = FUN_002b8d60(3,0xfff);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 5;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u16 *)(puVar8 + 0x48) = 3;
  *(u64 *)(puVar8 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_002bd590(*(u32 *)(unaff_s4_lo + 6),0x165);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,3);
  uVar13 = FUN_00284200(0x3f800000,aiStack_8[0],0x17,0,0);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_00284200(0x3f800000,iVar4,0x17,0,0);
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
  uVar13 = FUN_00284200(0x3f800000,aiStack_8[0],0x19,8,1);
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
  uVar13 = FUN_00284200(0x3f800000,iVar4,0x19,8,1);
  puVar11 = (u8 *)uVar13;
  *puVar11 = 4;
  *(u64 *)(puVar11 + 8) = *(u64 *)(puVar10 + 0x58);
  *(u64 *)(puVar11 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,1);
  uVar13 = FUN_002a3b40(0,1);
  puVar10 = (u8 *)uVar13;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar8 + 0x58);
  *(u64 *)(puVar10 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_002b8d60(2,0xfff);
  puVar8 = (u8 *)uVar13;
  *puVar8 = 4;
  *(u64 *)(puVar8 + 8) = *(u64 *)(puVar9 + 0x58);
  *(u64 *)(puVar8 + 0x60) = *unaff_s4_lo;
  FUN_0027ed20(uVar13,0);
  uVar13 = FUN_002a3b40(unaff_s4_lo,0x1f);
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

// FUN_002eba50 NONMATCHING
void func_002eba50(u64 *param_1)

{
  u8 *puVar1;
  s32 lVar2;
  u64 uVar3;
  u64 uVar4;
  int iVar5;
  int unaff_s1_lo;
  u64 uVar6;
  int iVar7;
  u64 unaff_s3;
  u64 *puVar8;
  int unaff_s6_lo;
  int aiStack_10 [4];
  
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xfdffffff;
  *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x80000;
  puVar8 = param_1;
  if (param_1 == (u64 *)0x0) {
    puVar8 = *(u64 **)(iGpffffb6fc + 0x14c);
    while ((puVar8 != (u64 *)0x0 &&
           ((((*(u16 *)((int)puVar8 + 0x1a) & 1) == 0 ||
             (*(char *)(*(int *)(puVar8 + 6) + 0xa2) != '\x01')) ||
            (*(short *)(*(int *)(puVar8 + 6) + 0xa4) != 0x115))))) {
      puVar8 = *(u64 **)(puVar8 + 0x95);
    }
  }
  uVar6 = 0;
  aiStack_10[0] = 0;
  aiStack_10[1] = 0;
  for (iVar5 = *(int *)(iGpffffb6fc + 0x158); iVar7 = aiStack_10[1], iVar5 != 0;
      iVar5 = *(int *)(iVar5 + 0xa34)) {
    lVar2 = FUN_0030b5a0(*(u32 *)(iVar5 + 0xa2c),0);
    if (lVar2 != 0) {
      if (*(short *)(iVar5 + 0xa4) == 0x106) {
        aiStack_10[1] = iVar5;
      }
      else if (*(short *)(iVar5 + 0xa4) == 0x105) {
        aiStack_10[0] = iVar5;
      }
    }
  }
  if ((aiStack_10[0] == 0) || (aiStack_10[1] == 0)) {
    for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
      if (aiStack_10[iVar5] != 0) {
        uVar6 = FUN_00284200(0x3f800000,aiStack_10[iVar5],0x12,0,2);
        FUN_0027ed20(uVar6,1);
      }
    }
  }
  else {
    uVar3 = FUN_002b8f90(0);
    iVar5 = aiStack_10[0];
    if (param_1 == (u64 *)0x0) {
      aiStack_10[2] = aiStack_10[0];
      aiStack_10[3] = iVar7;
      uVar6 = 2;
      uVar4 = FUN_002dd690(3,0x699d80);
      FUN_0027ed20(uVar4,1);
      unaff_s6_lo = iVar7;
      unaff_s1_lo = iVar5;
    }
    else if (*(int *)(puVar8 + 6) == aiStack_10[0]) {
      aiStack_10[2] = aiStack_10[0];
      aiStack_10[3] = 0;
      uVar6 = 3;
      uVar4 = FUN_002dd690(3,0x699d90);
      FUN_0027ed20(uVar4,1);
      unaff_s6_lo = iVar5;
      unaff_s1_lo = iVar5;
    }
    else if (*(int *)(puVar8 + 6) == iVar7) {
      aiStack_10[2] = iVar7;
      aiStack_10[3] = 0;
      uVar6 = 4;
      uVar4 = FUN_002dd690(3,0x699da0);
      FUN_0027ed20(uVar4,1);
      unaff_s6_lo = iVar7;
      unaff_s1_lo = iVar7;
    }
    uVar6 = FUN_002f87e0(uVar6);
    FUN_002b90d0(uVar3,uVar6);
    for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
      if (aiStack_10[iVar5 + 2] != 0) {
        unaff_s3 = FUN_00284200(0x3f800000,aiStack_10[iVar5 + 2],0x12,0,2);
        *(u16 *)((int)unaff_s3 + 0x48) = 3;
        *(u64 *)((int)unaff_s3 + 0x60) = *puVar8;
        FUN_0027ed20(unaff_s3,1);
      }
    }
    uVar6 = FUN_002b8d60(3,0xfff);
    puVar1 = (u8 *)uVar6;
    *puVar1 = 4;
    iVar7 = (int)unaff_s3;
    *(u64 *)(puVar1 + 8) = *(u64 *)(iVar7 + 0x58);
    *(u64 *)(puVar1 + 0x60) = *puVar8;
    FUN_0027ed20(uVar6,1);
    for (iVar5 = *(int *)(iGpffffb6fc + 0x158); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xa34)) {
      uVar6 = FUN_0027fe90(iVar5,0,0x6978b0,0);
      puVar1 = (u8 *)uVar6;
      *puVar1 = 4;
      *(u64 *)(puVar1 + 8) = *(u64 *)(iVar7 + 0x58);
      *(u64 *)(puVar1 + 0x60) = *puVar8;
      FUN_0027ed20(uVar6,1);
    }
    uVar6 = FUN_002a3b40(0,1);
    puVar1 = (u8 *)uVar6;
    *puVar1 = 4;
    *(u64 *)(puVar1 + 8) = *(u64 *)(iVar7 + 0x58);
    *(u64 *)(puVar1 + 0x60) = *puVar8;
    FUN_0027ed20(uVar6,0);
    uVar6 = FUN_002baf90(uVar3,unaff_s1_lo,unaff_s6_lo,0,0x200);
    *(u64 *)((int)uVar6 + 0x60) = *puVar8;
    FUN_0027ed20(uVar6,2);
    FUN_002b9030(uVar3);
  }
  return;
}

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

// FUN_002ec2c0 NONMATCHING
void func_002ec2c0(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(2);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x107) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x699df0);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 3;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

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

// FUN_002ec5c0 NONMATCHING
void func_002ec5c0(void)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  short sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  u16 auStack_18 [4];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar6 = (u32*)DAT_00699e00;
  puVar5 = auStack_30;
  iVar4 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar4 = iVar4 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar4);
  auStack_18[0] = DAT_007cc9a8;
  auStack_18[1] = DAT_007cc9aa;
  auStack_18[2] = DAT_007cc9ac;
  sVar7 = 0;
  uStack_c = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 1) {
      uStack_10 = 0x43160000;
      uStack_8 = 0x44098000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      uStack_10 = auStack_30[iVar3 * 2];
      uStack_8 = auStack_30[iVar3 * 2 + 1];
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[iVar3];
      sVar7 = sVar7 + 1;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 0x10a) {
      uStack_10 = 0x43c80000;
      uStack_8 = 0xc3960000;
    }
    else if (*(short *)(iVar4 + 0xa4) == 0x109) {
      uStack_10 = 0xc3c80000;
      uStack_8 = 0xc3960000;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  return;
}

// FUN_002ec790 NONMATCHING
void func_002ec790(void)

{
  u8 *puVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = 0;
  iVar6 = 0;
  for (iVar9 = *(int *)(DAT_007ce3ec + 0x158); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0xa34)) {
    iVar5 = iVar6;
    iVar7 = iVar9;
    if ((*(short *)(iVar9 + 0xa4) != 0x10a) &&
       (iVar5 = iVar9, iVar7 = iVar8, *(short *)(iVar9 + 0xa4) != 0x109)) {
      iVar5 = iVar6;
    }
    iVar8 = iVar7;
    iVar6 = iVar5;
  }
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(1);
  FUN_002b90d0(uVar2,uVar3);
  uVar3 = FUN_002baf90(uVar2,iVar8,iVar6,0,0x200);
  FUN_0027ed20(uVar3,2);
  uVar4 = FUN_002dd830(iVar8,10,0,6);
  puVar1 = (u8 *)uVar4;
  *puVar1 = 5;
  iVar9 = (int)uVar3;
  *(u64 *)(puVar1 + 8) = *(u64 *)(iVar9 + 0x58);
  *(u16 *)(puVar1 + 0x48) = 0x40;
  FUN_0027ed20(uVar4,1);
  uVar3 = FUN_002dd830(iVar8,0xc,0,7);
  puVar1 = (u8 *)uVar3;
  *puVar1 = 5;
  *(u64 *)(puVar1 + 8) = *(u64 *)(iVar9 + 0x58);
  *(u16 *)(puVar1 + 0x48) = 0x84;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027f410(0x2ecbe0,iVar6);
  puVar1 = (u8 *)uVar3;
  *puVar1 = 5;
  *(u64 *)(puVar1 + 8) = *(u64 *)(iVar9 + 0x58);
  *(u16 *)(puVar1 + 0x48) = 0x8c;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar6,0,0,1);
  puVar1 = (u8 *)uVar3;
  *puVar1 = 5;
  *(u64 *)(puVar1 + 8) = *(u64 *)(iVar9 + 0x58);
  *(u16 *)(puVar1 + 0x48) = 0x8c;
  FUN_0027ed20(uVar3,1);
  FUN_002b9030(uVar2);
  return;
}

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
void func_002ecc60(s32 param_1,s32 param_2)

{
  short sVar1;
  s32 lVar2;
  u16 *puVar3;
  u16 uVar4;
  u32 uVar5;
  int unaff_s3_lo;
  u16 uVar6;
  float fVar7;
  float fVar8;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [2];
  float fStack_28;
  float afStack_24 [2];
  float fStack_1c;
  float afStack_10 [2];
  float fStack_8;
  
  sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xb44) + 0xa4);
  if (sVar1 == 0xe6) {
    unaff_s3_lo = 0x699f90;
  }
  else if (sVar1 == 0xe5) {
    unaff_s3_lo = 0x699f50;
  }
  else if (sVar1 == 0xe4) {
    unaff_s3_lo = 0x699f00;
  }
  else if (sVar1 == 0xe3) {
    unaff_s3_lo = 0x699eb0;
  }
  else if (sVar1 == 0xe2) {
    unaff_s3_lo = 0x699e60;
  }
  uVar4 = 0xffff;
  lVar2 = FUN_00318ed0(*(u32 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0x9f4),0x15,afStack_10);
  uVar6 = uVar4;
  if (lVar2 != 0) {
    uVar5 = 0;
    fVar8 = afStack_10[0];
    while( true ) {
      puVar3 = (u16 *)(unaff_s3_lo + uVar5 * 8);
      uVar6 = 0xffff;
      if (puVar3[2] == -1) break;
      lVar2 = FUN_00318ed0(*(u32 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0x9f4),*puVar3,
                           afStack_30);
      if ((lVar2 != 0) &&
         (lVar2 = FUN_00318ed0(*(u32 *)(*(int *)(DAT_007ce3ec + 0xb44) + 0x9f4),puVar3[1],
                               afStack_24), lVar2 != 0)) {
        fStack_50 = (afStack_24[0] + afStack_30[0] + 0.0) / 3.0 - 0.0;
        fStack_4c = (fStack_1c + fStack_28 + 0.0) / 3.0 - 0.0;
        FUN_004c6b20(&fStack_50,&fStack_50);
        fStack_48 = afStack_30[0] - 0.0;
        fStack_44 = fStack_28 - 0.0;
        FUN_004c6b20(&fStack_48,&fStack_48);
        fStack_40 = afStack_24[0] - 0.0;
        fStack_3c = fStack_1c - 0.0;
        FUN_004c6b20(&fStack_40,&fStack_40);
        fStack_38 = fVar8 - 0.0;
        fStack_34 = fStack_8 - 0.0;
        FUN_004c6b20(&fStack_38,&fStack_38);
        fVar7 = fStack_50 * fStack_38 + fStack_4c * fStack_34;
        if ((fStack_50 * fStack_48 + fStack_4c * fStack_44 <= fVar7) &&
           (fStack_50 * fStack_40 + fStack_4c * fStack_3c <= fVar7)) {
          uVar4 = puVar3[2];
          uVar6 = *(u16 *)(uVar5 * 8 + unaff_s3_lo + 6);
          break;
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    }
  }
  if (param_1 != 0) {
    *(u16 *)param_1 = uVar4;
  }
  if (param_2 != 0) {
    *(u16 *)param_2 = uVar6;
  }
  return;
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
  func_002ecc60((s32)&stack.sStack_2,(s32)&stack.sStack_4);
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
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 auStack_18 [4];
  u32 uStack_8;
  u32 uStack_4;
  
  puVar16 = (u64 *)param_1;
  uVar18 = *puVar16;
  sVar22 = *(short *)(DAT_007ce3ec + 0xb58);
  if (sVar22 == 0) { for (iVar6 = *(int *)(DAT_007ce3ec + 0x158); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xa34)) {
    if (*(short *)(iVar6 + 0xa4) == 0x10a) {
      lVar13 = FUN_0030b5a0(*(u32 *)(iVar6 + 0xa2c),0);
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
  if (sVar22 == 0x172) {
    unaff_s2 = 0xe6;
  }
  else if (sVar22 == 0x171) {
    unaff_s2 = 0xe5;
  }
  else if (sVar22 == 0x16f) {
    unaff_s2 = 0xe4;
  }
  else if (sVar22 == 0x16e) {
    unaff_s2 = 0xe3;
  }
  else if (sVar22 == 0x16d) {
    unaff_s2 = 0xe2;
  }
  *(u16 *)(DAT_007ce3ec + 0xb56) = 0;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb44) = uVar5;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb48) = uVar5;
  uVar5 = FUN_002875a0(1);
  *(u32 *)(DAT_007ce3ec + 0xb4c) = uVar5;
  *(short *)(*(int *)(DAT_007ce3ec + 0xb44) + 0xa4) = (short)unaff_s2;
  *(u16 *)(*(int *)(DAT_007ce3ec + 0xb48) + 0xa4) = 0xe7;
  *(u16 *)(*(int *)(DAT_007ce3ec + 0xb4c) + 0xa4) = 0xe8;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb44),&uStack_28);
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb48),&uStack_28);
  FUN_0027f650(*(u32 *)(DAT_007ce3ec + 0xb4c),&uStack_28);
  FUN_0027f710(0x3f000000,*(u32 *)(DAT_007ce3ec + 0xb44));
  FUN_0027f710(0x3f000000,*(u32 *)(DAT_007ce3ec + 0xb48));
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
  uVar15 = FUN_00284200(0x3f800000,*(u32 *)(puVar16 + 6),7,6,0);
  iVar6 = (int)uVar15;
  *(u64 *)(iVar6 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,1);
  uVar15 = FUN_002b8d60(3,0xfff);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  uVar15 = FUN_002a3b40(0,1);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  uVar15 = FUN_002a3b40(param_1,0x11);
  puVar7 = (u8 *)uVar15;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar18;
  FUN_0027ed20(uVar15,0);
  sVar4 = FUN_002838d0(0x3f800000,*(u32 *)(puVar16 + 6),0x18);
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
  uStack_38 = DAT_007cafd4;
  uStack_34 = DAT_007cafd8;
  uStack_30 = DAT_007cafdc;
  uStack_48 = DAT_007cafe0;
  uStack_44 = DAT_007cafe4;
  uStack_40 = DAT_007cafe8;
  uVar14 = FUN_002a3d70(0x3f800000,param_1,0,0,&uStack_38,&uStack_48);
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
  *(u16 *)(DAT_007ce3ec + 0xb58) = 2; } else if (sVar22 == 2) { FUN_00352c50(*(u32 *)(DAT_007ce3ec + 0xb48),*(u32 *)(DAT_007ce3ec + 0xb44),
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
        uVar14 = FUN_00284200(0x3f800000,*(u32 *)(iVar2 + 0x30),
                              *(u8 *)(iVar2 + iVar19 * 0x1c + 0xf8),0,0);
        puVar7 = (u8 *)uVar14;
        *puVar7 = 0xb;
        *(u64 *)(puVar7 + 8) = *(u64 *)(iVar11 + 0x58);
        *(u64 *)(puVar7 + 0x60) = uVar18;
        FUN_0027ed20(uVar14,1);
        if (((uVar17 == 0) && (uVar20 == 0)) && (*(short *)(DAT_007ce3ec + 0xb62) != -1)) {
          uVar14 = FUN_002bd850(*(u32 *)(puVar16 + 6));
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
  } } else if (sVar22 == 3) { FUN_00352c50(*(u32 *)(DAT_007ce3ec + 0xb48),*(u32 *)(DAT_007ce3ec + 0xb44),
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
  } }
  return 1;
}

// FUN_002ee640 NONMATCHING
void func_002ee640(u64 *param_1)

{
  int iVar1;
  u8 *puVar2;
  int iVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  iVar3 = *(int *)(param_1 + 6);
  iVar6 = 0;
  *(short *)(iVar3 + 0xa0) = *(short *)(iVar3 + 0xa0) + 1;
  uVar4 = FUN_002b8f90(0);
  if (*(short *)(iVar3 + 0xa4) == 0x109) {
    uVar5 = FUN_002f87e0(8);
    FUN_002b90d0(uVar4,uVar5);
    uVar5 = FUN_002dd690(3,0x699ff0);
    FUN_0027ed20(uVar5,1);
  }
  else if (*(short *)(iVar3 + 0xa4) == 0x10a) {
    uVar5 = FUN_002f87e0(7);
    FUN_002b90d0(uVar4,uVar5);
    uVar5 = FUN_002dd690(3,0x699fe0);
    FUN_0027ed20(uVar5,1);
  }
  if (*(short *)(iVar3 + 0xa4) == 0x10a) {
    for (iVar6 = *(int *)(DAT_007ce3ec + 0x158); (iVar6 != 0 && (*(short *)(iVar6 + 0xa4) != 0x109))
        ; iVar6 = *(int *)(iVar6 + 0xa34)) {
    }
  }
  uVar5 = FUN_00284200(0x3f800000,iVar3,0x12,0,2);
  iVar1 = (int)uVar5;
  *(u16 *)(iVar1 + 0x48) = 2;
  *(u64 *)(iVar1 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002b8d60(3,0xfff);
  puVar2 = (u8 *)uVar5;
  *puVar2 = 4;
  *(u64 *)(puVar2 + 8) = *(u64 *)(iVar1 + 0x58);
  *(u64 *)(puVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_0027fe90(iVar3,0,0x6978b0,0);
  puVar2 = (u8 *)uVar5;
  *puVar2 = 4;
  *(u64 *)(puVar2 + 8) = *(u64 *)(iVar1 + 0x58);
  *(u64 *)(puVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002a3b40(0,1);
  puVar2 = (u8 *)uVar5;
  *puVar2 = 4;
  *(u64 *)(puVar2 + 8) = *(u64 *)(iVar1 + 0x58);
  *(u64 *)(puVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002baf90(uVar4,iVar3,iVar3,0,0x200);
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  if (iVar6 != 0) {
    uVar5 = FUN_002baf90(uVar4,iVar6,iVar6,1,0x200);
    iVar3 = (int)uVar5;
    *(u64 *)(iVar3 + 0x60) = *param_1;
    FUN_0027ed20(uVar5,2);
    uVar5 = FUN_002dd830(iVar6,10,0,7);
    puVar2 = (u8 *)uVar5;
    *puVar2 = 5;
    *(u64 *)(puVar2 + 8) = *(u64 *)(iVar3 + 0x58);
    *(u64 *)(puVar2 + 0x60) = *param_1;
    *(u16 *)(puVar2 + 0x48) = 0x96;
    FUN_0027ed20(uVar5,1);
    uVar5 = FUN_0027f410(0x2ecc20,iVar6);
    puVar2 = (u8 *)uVar5;
    *puVar2 = 5;
    *(u64 *)(puVar2 + 8) = *(u64 *)(iVar3 + 0x58);
    *(u16 *)(puVar2 + 0x48) = 8;
    *(u64 *)(puVar2 + 0x60) = *param_1;
    FUN_0027ed20(uVar5,1);
    uVar5 = FUN_00284200(0x3f800000,iVar6,0,0,1);
    puVar2 = (u8 *)uVar5;
    *puVar2 = 5;
    *(u64 *)(puVar2 + 8) = *(u64 *)(iVar3 + 0x58);
    *(u16 *)(puVar2 + 0x48) = 8;
    FUN_0027ed20(uVar5,1);
  }
  FUN_002b9030(uVar4);
  return;
}

// FUN_002eea10 NONMATCHING
u32 func_002eea10(s32 param_1)

{
  s32 lVar1;
  u64 uVar2;
  u64 *puVar3;
  
  lVar1 = FUN_0029ad20();
  puVar3 = (u64 *)param_1;
  if (param_1 == lVar1) {
    *(u32 *)(*(int *)(puVar3 + 6) + 0x9c) = *(u32 *)(*(int *)(puVar3 + 6) + 0x9c) & 0xffffffef;
  }
  else if ((*(u32 *)(*(int *)(puVar3 + 6) + 0x9c) & 0x10) != 0) {
    return true;
  }
  lVar1 = FUN_0027e390(*puVar3,0x3fffffffffffffff);
  if (lVar1 == 0) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfff7ffff;
    FUN_002d7890(param_1,0);
    FUN_0029a320(param_1);
    *(short *)(*(int *)(puVar3 + 6) + 0xa0) = *(short *)(*(int *)(puVar3 + 6) + 0xa0) + -1;
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x2000000;
    FUN_0027ed20(uVar2,1);
    FUN_0027ed20(uVar2,1);
    FUN_0027ed20(uVar2,1);
  }
  return lVar1 != 0;
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

// FUN_002eec60 NONMATCHING
void func_002eec60(void)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  short sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  u16 auStack_18 [4];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar6 = (u32*)DAT_0069a000;
  puVar5 = auStack_30;
  iVar4 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar4 = iVar4 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar4);
  auStack_18[0] = DAT_007cc9b0;
  auStack_18[1] = DAT_007cc9b2;
  auStack_18[2] = DAT_007cc9b4;
  sVar7 = 0;
  uStack_c = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 1) {
      uStack_10 = 0x43160000;
      uStack_8 = 0x43af0000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      uStack_10 = auStack_30[iVar3 * 2];
      uStack_8 = auStack_30[iVar3 * 2 + 1];
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[iVar3];
      sVar7 = sVar7 + 1;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 0x10c) {
      uStack_10 = 0x43480000;
      uStack_8 = 0xc3af0000;
    }
    else if (*(short *)(iVar4 + 0xa4) == 0x10b) {
      uStack_10 = 0xc3480000;
      uStack_8 = 0xc3af0000;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  return;
}

// FUN_002eee20 NONMATCHING
u32 func_002eee20(BtlAction* param_1,float *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  s32 lVar4;
  int iVar5;
  float fVar6;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float afStack_10 [2];
  float fStack_8;
  
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0x30);
  if (*(char *)(iVar1 + 0xa2) == '\x01') {
    if (*(short *)(iVar1 + 0xa4) == 0x10c) {
      if (*(short *)(iVar5 + 0x6a) == 1) {
        if (*(short *)(iVar5 + 0x6c) == 2) {
          if ((*(u8 *)(DAT_007ce3f8 +
                        ((u32)*(u16 *)(iVar5 + 0x6e) * 10 + (u32)*(u16 *)(iVar5 + 0x6e)) * 4
                        ) & 2) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(u32 *)(*(int *)(iVar5 + 0x38) + 0x30);
            FUN_00280050(iVar1,afStack_10);
            FUN_00280480(uVar3,iVar1,&fStack_20);
            fStack_30 = afStack_10[0] - fStack_20;
            fStack_28 = fStack_8 - fStack_18;
            fStack_2c = 0.0;
            FUN_004c69f0(&fStack_30,&fStack_30);
            lVar4 = FUN_002d5e10(param_1);
            if (lVar4 == 0) {
              uVar2 = 4;
            }
            else {
              uVar2 = 0xb;
            }
            fVar6 = (float)FUN_002812d0(iVar1,uVar3,uVar2);
            *param_2 = fStack_20 + fStack_30 * fVar6;
            param_2[1] = fStack_1c + fStack_2c * fVar6;
            param_2[2] = fStack_18 + fStack_28 * fVar6;
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

// FUN_002ef000 NONMATCHING
void func_002ef000(u64 *param_1)

{
  int iVar1;
  int iVar2;
  u8 *puVar3;
  u64 uVar4;
  u64 uVar5;
  u16 unaff_s0_lo;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x80000;
  iVar1 = *(int *)(param_1 + 6);
  if (*(short *)(iVar1 + 0xa4) == 0x10c) {
    unaff_s0_lo = 3;
    uVar4 = func_002e2cb0(0x312);
    *(u16 *)((int)uVar4 + 0x48) = 3;
    FUN_0027ed20(uVar4,1);
  }
  else if (*(short *)(iVar1 + 0xa4) == 0x10b) {
    unaff_s0_lo = 2;
    uVar4 = func_002e2cb0(0x2ff);
    *(u16 *)((int)uVar4 + 0x48) = 3;
    FUN_0027ed20(uVar4,1);
  }
  uVar4 = FUN_002b8f90(0);
  uVar5 = FUN_002f87e0(unaff_s0_lo);
  FUN_002b90d0(uVar4,uVar5);
  uVar5 = FUN_00284200(0x3f800000,iVar1,0x12,0,2);
  iVar2 = (int)uVar5;
  *(u16 *)(iVar2 + 0x48) = 3;
  *(u64 *)(iVar2 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002b8d60(1,0xfff);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_0027fe90(iVar1,0,0x6978b0,0);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,1);
  uVar5 = FUN_002a3b40(0,1);
  puVar3 = (u8 *)uVar5;
  *puVar3 = 4;
  *(u64 *)(puVar3 + 8) = *(u64 *)(iVar2 + 0x58);
  *(u64 *)(puVar3 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,0);
  uVar5 = FUN_002baf90(uVar4,iVar1,iVar1,0,0x200);
  *(u64 *)((int)uVar5 + 0x60) = *param_1;
  FUN_0027ed20(uVar5,2);
  FUN_002b9030(uVar4);
  return;
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

// FUN_002ef360 NONMATCHING
void func_002ef360(void)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  short sVar7;
  u32 auStack_40030 [49158];
  u16 auStack_10018 [32748];
  u32 auStack_30 [6];
  u16 auStack_18 [4];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar6 = (u32*)DAT_0069a060;
  puVar5 = auStack_30;
  iVar4 = 3;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    iVar4 = iVar4 + -1;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
  } while (0 < iVar4);
  auStack_18[0] = DAT_007cc9b8;
  auStack_18[1] = DAT_007cc9ba;
  auStack_18[2] = DAT_007cc9bc;
  sVar7 = 0;
  uStack_c = 0;
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x150); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    if (*(short *)(iVar4 + 0xa4) == 1) {
      uStack_10 = 0x43160000;
      uStack_8 = 0x43fa0000;
      *(u8 *)(iVar4 + 0x9f0) = 2;
    }
    else {
      iVar3 = (int)sVar7;
      uStack_10 = auStack_30[iVar3 * 2];
      uStack_8 = auStack_30[iVar3 * 2 + 1];
      *(char *)(iVar4 + 0x9f0) = (char)auStack_18[iVar3];
      sVar7 = sVar7 + 1;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {
    sVar7 = *(short *)(iVar4 + 0xa4);
    if (sVar7 == 0x127) {
      uStack_10 = 0x437a0000;
      uStack_8 = 0x42c80000;
    }
    else if (sVar7 == 0x119) {
      uStack_10 = 0xc37a0000;
      uStack_8 = 0x42c80000;
    }
    else if (sVar7 == 0x118) {
      uStack_10 = 0x437a0000;
      uStack_8 = 0xc3e10000;
    }
    else if (sVar7 == 0x117) {
      uStack_10 = 0;
      uStack_8 = 0xc3480000;
    }
    else if (sVar7 == 0x116) {
      uStack_10 = 0xc37a0000;
      uStack_8 = 0xc3e10000;
    }
    else if (sVar7 == 0x10d) {
      uStack_10 = 0;
      uStack_8 = 0xc3fa0000;
    }
    FUN_002d2280(iVar4 + 0x94,iVar4 + 0x96,&uStack_10);
    FUN_0027f650(iVar4,&uStack_10);
  }
  return;
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

// FUN_002ef670 NONMATCHING
void func_002ef670(void)

{
  int iVar1;
  int iVar7;
  int iVar6;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  short sVar5;
  int aiStack_10 [3];
  
  uVar2 = FUN_002b8f90(0);
  FUN_002b90d0(uVar2,FUN_002f87e0(1));
  iVar7 = 0;
  aiStack_10[0] = 0;
  aiStack_10[1] = 0;
  aiStack_10[2] = 0;
  sVar5 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc_ptr + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar6 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 1) {
      aiStack_10[2 - sVar5] = iVar1;
      sVar5++;
      iVar6 = iVar7;
    }
    iVar7 = iVar6;
  }
  FUN_0027ed20(FUN_002bc950(aiStack_10[0],aiStack_10[1],aiStack_10[2]),1);
  uVar3 = FUN_002baf90(uVar2,iVar7,iVar7,0,0x200);
  FUN_0027ed20(uVar3,2);
  uVar4 = FUN_002bc950(0,0,0);
  *(u8 *)uVar4 = 4;
  *(u64 *)((u8 *)uVar4 + 8) = *(u64 *)((int)uVar3 + 0x58);
  FUN_0027ed20(uVar4,1);
  FUN_002b9030(uVar2);
  return;
}

// FUN_002ef7e0 NONMATCHING
void func_002ef7e0(void)

{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfdffffff;
  uVar2 = FUN_002b8f90(0);
  uVar3 = FUN_002f87e0(9);
  FUN_002b90d0(uVar2,uVar3);
  iVar5 = 0;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x158); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
    iVar4 = iVar1;
    if (*(short *)(iVar1 + 0xa4) != 0x10d) {
      iVar4 = iVar5;
    }
    iVar5 = iVar4;
  }
  uVar3 = FUN_002dd690(3,0x69a0f8);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_00284200(0x3f800000,iVar5,0x12,0,2);
  iVar1 = (int)uVar3;
  *(u16 *)(iVar1 + 0x48) = 2;
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002b8d60(3,0xfff);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_0027fe90(iVar5,0,0x6978b0,0);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,1);
  uVar3 = FUN_002a3b40(0,1);
  *(u8 *)uVar3 = 4;
  *(u64 *)((u8 *)uVar3 + 8) = *(u64 *)(iVar1 + 0x58);
  FUN_0027ed20(uVar3,0);
  uVar3 = FUN_002baf90(uVar2,iVar5,iVar5,0,0x200);
  FUN_0027ed20(uVar3,2);
  FUN_002b9030(uVar2);
  return;
}

// FUN_002ef9d0 NONMATCHING
int func_002ef9d0(void)

{
  int iVar1;
  s32 lVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  u32 auStack_20 [8];
  
  iVar5 = 0;
  iVar4 = *(int *)(DAT_007ce3ec + 0x158);
  do {
    if (iVar4 == 0) {
LAB_002efa38:
      if (iVar5 != 0) {
        FUN_002d5dc0(auStack_20);
        auStack_20[0] = 0xfff00001;
        for (iVar4 = *(int *)(DAT_007ce3ec + 0x14c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4a8)) {
          if ((*(u16 *)(iVar4 + 0x1a) & 1) != 0) {
            iVar1 = *(int *)(iVar4 + 0x30);
            if (((*(char *)(iVar1 + 0xa2) == '\x01') && (*(short *)(iVar1 + 0xa4) != 0x10d)) &&
               (lVar2 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c),0), lVar2 == 0)) {
              uVar3 = FUN_002d7e20(iVar4,iVar4,auStack_20,1,1);
              FUN_0027ed20(uVar3,1);
              uVar3 = FUN_00284200(0x3f800000,iVar1,2,0,0);
              FUN_0027ed20(uVar3,1);
            }
          }
        }
      }
      return iVar5;
    }
    if ((*(short *)(iVar4 + 0xa4) == 0x10d) &&
       (lVar2 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0), lVar2 != 0)) {
      iVar5 = 1;
      goto LAB_002efa38;
    }
    iVar4 = *(int *)(iVar4 + 0xa34);
  } while( true );
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
  u64 uVar11;
  u64 uVar12;
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
  uVar11 = FUN_002b8f90(0);
  if (sVar2 == 0x119) {
    uVar12 = FUN_002f87e0(7);
    FUN_002b90d0(uVar11,uVar12);
  }
  else {
    uVar12 = FUN_002f87e0(8);
    FUN_002b90d0(uVar11,uVar12);
  }
  uVar12 = FUN_002bd590(*(u32 *)(param_1 + 6),uVar1);
  *(u64 *)((int)uVar12 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,3);
  uVar12 = FUN_00284200(0x3f800000,*(u32 *)(param_1 + 6),7,6,2);
  iVar6 = (int)uVar12;
  *(u64 *)(iVar6 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  sVar5 = FUN_002838d0(0x3f800000,*(u32 *)(param_1 + 6),7);
  uVar13 = *(u64 *)(iVar6 + 0x58);
  uVar12 = FUN_002b8d60(3,0xfff);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = FUN_0027fe90(*(u32 *)(param_1 + 6),0,0x6978b0,0);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = FUN_002a3b40(0,1);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = FUN_002a3b40(param_1,0x11);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,0);
  uVar12 = FUN_002822b0(*(u32 *)(param_1 + 6),&uStack_18,0);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = *(u64 *)(iVar6 + 0x58);
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  for (puVar3 = *(u64 **)(DAT_007ce3ec + 0x14c); puVar3 != (u64 *)0x0;
      puVar3 = *(u64 **)(puVar3 + 0x95)) {
    if ((param_1 != puVar3) && ((*(u16 *)((int)puVar3 + 0x1a) & 1) != 0)) {
      uVar12 = FUN_00285d30(*(u32 *)(puVar3 + 6),0xffffff,0,0,2,0);
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
  uVar12 = FUN_0029ec00(uVar1);
  FUN_0029ec80(uVar1,&uStack_4,&uStack_8);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = FUN_0029ec50(uVar1);
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
  uVar12 = FUN_00285690(uVar4,sVar2,0x7e);
  puVar7 = (u8 *)uVar12;
  *puVar7 = 4;
  *(u64 *)(puVar7 + 8) = uVar13;
  *(short *)(puVar7 + 0x48) = sVar5 + 6;
  *(u64 *)(puVar7 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,1);
  uVar12 = FUN_002baf90(uVar11,*(u32 *)(param_1 + 6),uVar4,0,0x200);
  puVar9 = (u8 *)uVar12;
  *puVar9 = 4;
  *(u64 *)(puVar9 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u64 *)(puVar9 + 0x60) = uVar14;
  FUN_0027ed20(uVar12,2);
  uVar12 = FUN_00285d30(uVar4,0xffffffffffffffff,0,0,1,1);
  puVar10 = (u8 *)uVar12;
  *puVar10 = 4;
  *(u64 *)(puVar10 + 8) = *(u64 *)(puVar7 + 0x58);
  *(u16 *)(puVar10 + 0x48) = 1;
  *(u64 *)(puVar10 + 0x60) = uVar14;
  FUN_0027ed20(uVar12);
  uVar12 = FUN_002a3b40(param_1,0x25);
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
      uVar12 = FUN_00285d30(*(u32 *)(puVar3 + 6),0xffffffffffffffff,0,0,1,0);
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

