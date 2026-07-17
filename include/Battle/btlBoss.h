#ifndef BTLBOSS_H
#define BTLBOSS_H

#include "Utils.h"
#include "Battle/btlPacket.h"
#include "Battle/btlUnit.h"

#ifndef BTLPACKET_MODULE_BOSS
#define BTLPACKET_MODULE_BOSS 14
#endif

typedef struct BtlCameraStateEntry BtlCameraStateEntry;
typedef struct BtlAction BtlAction;

typedef enum
{
    BTLBOSS_PACKET_LOADPAK = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_BOSS, 0)
} BtlBossPacket;

const BtlCameraStateEntry* btlBossGetCameraStateEntry(u16 cameraState);

BtlPacket* btlBossCreateLoadPakPacket();
u32 func_002fa240(void);
u32 FUN_002fd220(BtlAction* action, BtlAction* target);
u32 FUN_002fde40(BtlAction* action, f32* position);
u32 FUN_002fdfe0(int camera);
u8 FUN_002fdd40(BtlUnit* first, BtlUnit* second);
void FUN_002fddb0(BtlUnit* unit, RwV3d* position);
BtlUnitAnimBounds* func_002fc410(BtlUnit* unit);
BtlUnitAnimBounds* func_002fc520(BtlUnit* unit);

#endif