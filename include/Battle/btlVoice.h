#ifndef BTLVOICE_H
#define BTLVOICE_H

#include "Utils.h"
#include "Battle/btlPacket.h"

typedef struct BtlPacket BtlPacket;
typedef struct BtlAction BtlAction;
typedef struct BtlUnit BtlUnit;
typedef struct BtlTargetResult BtlTargetResult;

typedef enum
{
    BTLVOICE_PACKET_UNK01 = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_VOICE, 1)
} BtlVoicePacket;

// 24 bytes
typedef struct BtlVoicePacket002e2be0
{
    BtlAction* action; // 0x00
    s16 unk_04;        // 0x04
    u8 unkData1[2];
    s32 unk_08;        // 0x08
    s32 unk_0c;        // 0x0c
    s16 unk_10;        // 0x10
    u8 unkData2[2];
    s32 unk_14;        // 0x14
} BtlVoicePacket002e2be0;

BtlPacket* btlVoice002e2be0(BtlAction* action, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
BtlPacket* func_002e2ec0(u16 voiceId);
void func_002e2f80(void);
BtlPacket* func_002e30a0(u16 arg0, u16 arg1, u16 arg2, u16 flags);
void func_002e32a0(BtlAction* action, BtlAction* target, u32 id);
void func_002ea780(BtlAction* action);
u32 func_002eee20(BtlAction* action, f32* position);
u32 func_002f1b60(BtlAction* action, f32* position);
s16 func_002e33f0(BtlAction* action);
void func_002f3670(BtlAction* action);
void func_002f3760(void);
u32 func_002f6ab0(BtlAction* action);
u32 func_002f6bc0(void);
s32 func_002f6c50(u16 charId);
void func_002eeb70(BtlAction* action);
void func_002ef5a0(void);
void func_002efb40(BtlUnit* unit);
void func_002f3840(void);
void func_002f39b0(BtlAction* action);
void func_002f4890(BtlAction* action);
void func_002f4950(void);
void func_002f4c00(BtlAction* action);
void func_002f4ce0(void);
void func_002ec190(BtlAction* source, BtlAction* target, BtlTargetResult* result);
void func_002f5bf0(BtlAction* source, BtlAction* target, BtlTargetResult* result);
void func_002faa50(BtlAction* source, BtlAction* target, BtlTargetResult* result);

#endif