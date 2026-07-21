#include "Battle/btlBoss.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Battle/btlVoice.h"
#include "Battle/btlCamera.h"
#include "Kosaka/k_assert.h"
#include "Battle/battle.h"
#include "h_cdvd.h"
#include "Script/scrScriptProcess.h"
#include "rw/rwcore.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
#pragma alias scrCreateTaskFromHeader_2 scrCreateTaskFromHeader
extern KwlnTask* scrCreateTaskFromHeader_2(u32 priority, ScrHeader* header);
extern void FUN_0035c1a0(KwlnTask* task, s32 value);
extern void* FUN_0035ae10(KwlnTask* task);
extern void FUN_003a4220(s32 handle, s32 arg_2, u32 value);
extern u32 FUN_001778b0(u32 value);
extern void FUN_00195550(KwlnTask* parent, KwlnTask* child);
u32 FUN_002fcaa0(int param_1,u32 *param_2);
u32 FUN_002fcf50(int param_1);
u32 FUN_002fd060(BtlAction* action);
u32 FUN_002fd160(BtlAction* action);
u32 FUN_002fd2e0(int param_1,u16 param_2);
u32 FUN_002fd4a0(void);
u8 FUN_002fd500(void);
void FUN_002fd520(int param_1);
u32 FUN_002fd660(void);
u32 FUN_002fd7c0(void);
void FUN_002fd820(void);
void FUN_002fd8a0(int param_1);
u32 FUN_002fdb70(void);
u32 FUN_002fdb90(void);
s32 FUN_002fdbb0(BtlAction* param_1,BtlUnit* param_2);
u8 FUN_002fdcb0(int param_1);
u32 FUN_002fdcf0(int param_1,int param_2);
code FUN_002fded0(s16 param_1);
u8 FUN_002fdfa0(void);
u32 FUN_002fdfe0(int param_1);
void FUN_002fe0b0(float param_1,u8 *param_2,u64 param_3,u64 param_4,  u64 param_5);
void FUN_002fe780(float param_1,u8 *param_2,u8 *param_3,u64 param_4,u64 param_5);
u32 FUN_002fed10(int param_1);
u8 FUN_00301750(int datUnit, u32 flag);
u32 FUN_002d6370(s16 commandId);
u32 FUN_003088b0(u16 commandId);
s32 FUN_002d6290(void);
s32 FUN_002d63b0(BtlUnit* unit, s32 commandId, s32 param_3);
extern f32 DAT_007caee4;
extern f32 DAT_007caf58;
extern f32 DAT_007caf5c;
extern f32 DAT_007caf60;
extern f32 DAT_007caf64;
extern f32 DAT_007ca4e4;
extern f32 DAT_007ca564;
extern u32 DAT_007cc970;
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce3f4;
extern u8* iGpffffb6fc;
extern u8* DAT_007ce42c;
extern u8* DAT_007ce4b4;
extern u32 DAT_007ce508;
extern u32 DAT_007ce50a;
extern u32 DAT_007ce50c;
extern u32 DAT_007ce4d0;
extern u32 DAT_0069aa50[];
extern f32 DAT_0096008c;
extern void (*DAT_00960090)(...);
extern void (*DAT_00960094)(...);
extern void (*DAT_009600a0)(...);
extern void* kwlnGetMainCamera(void);
extern void* FUN_004e3630(void);

extern const BtlCameraStateEntry gBtlBossCameraStateEntries[][BTLCAMERA_STATE_MAX];

extern void* func_002b8f90(s32 param_1);
extern void func_002b96e0(void* object, void* archiveEntry);
extern void* func_002f87e0(u16 index);
extern void func_00100ec0(void* resource);
extern void* H_Cdvd_ArchiveGetFile(HCdvd* cdvd, s32 fileIdx, u32* fileSize);
extern void func_002b9030(void* resource);
extern u32 func_002ecac0(void);
extern s32 func_002d6370(s32 id);
extern void func_0029a2c0(void);
extern s32 FUN_00195460(s32 task);

// FUN_002f7dc0
void btlBossInitEncounterResources()
{
    switch (gBtl->startInfo.enmUnits->encountId)
    {
        case 0x1a7:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(5));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(6));
            break;

        case 0x1a8:
            *(s16*)((u8*)gBtl + 0xb50) = 0;
            *(u32*)((u8*)gBtl + 0xb54) = 0;
            break;

        case 0x1a9:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            break;

        case 0x1aa:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            break;

        case 0x1ab:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            break;

        case 0x1ac:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(2));
            break;

        case 0x1ad:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(2));
            break;

        case 0x1ae:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            *(void**)((u8*)gBtl + 0xb50) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb50), func_002f87e0(6));
            break;

        case 0x1af:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            break;

        case 0x1b0:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(3));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(5));
            *(void**)((u8*)gBtl + 0xb50) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb50), func_002f87e0(6));
            break;

        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(4));
            *(void**)((u8*)gBtl + 0xb48) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb48), func_002f87e0(5));
            *(void**)((u8*)gBtl + 0xb4c) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb4c), func_002f87e0(6));
            break;

        case 0x1b4:
            *(void**)((u8*)gBtl + 0xb44) = func_002b8f90(2);
            func_002b96e0(*(void**)((u8*)gBtl + 0xb44), func_002f87e0(5));
            break;

        default:
            break;
    }
}

// FUN_002f8840
const BtlCameraStateEntry* btlBossGetCameraStateEntry(u16 cameraState)
{
    const BtlCameraStateEntry* entry;
    s16 bossCameraSet;

    if (!(gBtl->unk_10 & 0x10))
    {
        return NULL;
    }

    bossCameraSet = *(s16*)((u8*)gBtl + 0xb84);
    entry = &gBtlBossCameraStateEntries[bossCameraSet][cameraState];

    if (entry->init == NULL && entry->update == NULL)
    {
        return NULL;
    }

    return entry;
}

extern void FUN_002b2060(int param_1);
extern void FUN_002a5f40(BtlCamera* camera);
extern void FUN_002b4f40(int param_1);
extern void FUN_002b4db0_float(float param_1);
extern f32 fGpffff8108;

// FUN_002e7320
void FUN_002e7320(BtlCamera* camera)
{
}

// FUN_002e7680
void FUN_002e7680(int param_1)
{
    FUN_002b2060(param_1);
}

// FUN_002e7880
void FUN_002e7880(BtlCamera* camera)
{
}

// FUN_002e5040
void FUN_002e5040(BtlCamera* camera)
{
    FUN_002a5f40(camera);
}

// FUN_002e8c80
void FUN_002e8c80(BtlCamera* camera)
{
}

// FUN_002e8d20
void FUN_002e8d20(int param_1)
{
    FUN_002b4f40(param_1);
}

// FUN_002e8d40
void FUN_002e8d40(BtlCamera* camera)
{
    FUN_002b4db0_float(fGpffff8108);
}

// FUN_002f9710
void btlBossInitLoadPakPacket(void* work)
{
    u16 encountId;

    encountId = gBtl->startInfo.enmUnits->encountId;

    if (encountId == 0x1b4)
    {
        goto encount_1b4;
    }

    if (encountId == 0x1b3)
    {
        goto encount_1b3;
    }

    if (encountId == 0x1b2)
    {
        goto encount_1b2;
    }

    if (encountId == 0x1b1)
    {
        goto encount_1b1;
    }

    if (encountId == 0x1b0)
    {
        goto encount_1b0;
    }

    if (encountId == 0x1af)
    {
        goto encount_1af;
    }

    if (encountId == 0x1ae)
    {
        goto encount_1ae;
    }

    if (encountId == 0x1ad)
    {
        goto encount_1ad;
    }

    if (encountId == 0x1ac)
    {
        goto encount_1ac;
    }

    if (encountId == 0x1ab)
    {
        goto encount_1ab;
    }

    if (encountId == 0x1aa)
    {
        goto encount_1aa;
    }

    if (encountId == 0x1a9)
    {
        goto encount_1a9;
    }

    if (encountId == 0x1a8)
    {
        goto encount_1a8;
    }

    if (encountId == 0x1a7)
    {
        goto encount_1a7;
    }

    if (encountId == 0x1a6)
    {
        goto encount_1a6;
    }

    if (encountId == 0x1a5)
    {
        goto encount_1a5;
    }

    if (encountId == 0x1a4)
    {
        goto encount_1a4;
    }

    if (encountId == 0x1a3)
    {
        goto encount_1a3;
    }

    if (encountId == 0x1a2)
    {
        goto encount_1a2;
    }

    if (encountId == 0x1a1)
    {
        goto encount_1a1;
    }

    if (encountId == 0x1a0)
    {
        goto encount_1a0;
    }

    switch (encountId)
    {
        case 0x1c8:
            goto encount_1c8;

        default:
            goto done;
    }

encount_1c8:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1C8.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a0:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A0.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a1:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A1.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a2:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A2.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a3:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A3.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a4:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A4.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a5:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A5.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a6:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A6.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a7:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A7.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a8:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A8.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1a9:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1A9.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1aa:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AA.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1ab:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AB.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1ac:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AC.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1ad:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AD.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1ae:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AE.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1af:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1AF.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1b0:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1B0.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1b1:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1B1.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1b2:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1B2.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1b3:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1B3.pak", HCDVD_FILEARCHIVE);
    goto done;

encount_1b4:
    gBtl->bossPakCdvd = H_Cdvd_Request("snd_benc/boss/e1B4.pak", HCDVD_FILEARCHIVE);

done:
    return;
}

// FUN_002f9b60
u32 btlBossUpdateLoadPakPacket(void* work)
{
    if (gBtl->bossPakCdvd == NULL)
    {
        return 1;
    }

    if (H_Cdvd_IsFileLoaded(gBtl->bossPakCdvd))
    {
        btlBossInitEncounterResources();

        return 1;
    }

    return 0;
}

// FUN_002f9bc0
BtlPacket* btlBossCreateLoadPakPacket()
{
    BtlPacket* packet;

    packet = btlPacketCreate(BTLBOSS_PACKET_LOADPAK, 0);

    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = btlBossInitLoadPakPacket;
    packet->updateFunc = btlBossUpdateLoadPakPacket;

    return packet;
}

static inline u16 btlBossGetEncounterId()
{
    return *(u16*)(*(u8**)((u8*)gBtl + 0xbbc) + 8);
}
static u16 btlBossGetEncounterIdCall()
{
    return *(u16*)(*(u8**)((u8*)gBtl + 0xbbc) + 8);
}

static BtlUnit* btlBossGetEnemyHead()
{
    return *(BtlUnit**)((u8*)gBtl + 0x158);
}


// FUN_002f8460
void func_002f8460()
{
    u16 encounterId;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
        case 0x1a7:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1a9:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1aa:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1ab:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1ac:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            break;
        case 0x1ad:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            break;
        case 0x1ae:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb50));
            *(void**)(DAT_007ce3ec + 0xb50) = NULL;
            break;
        case 0x1af:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1b0:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb50));
            *(void**)(DAT_007ce3ec + 0xb50) = NULL;
            break;
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb48));
            *(void**)(DAT_007ce3ec + 0xb48) = NULL;
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb4c));
            *(void**)(DAT_007ce3ec + 0xb4c) = NULL;
            break;
        case 0x1b4:
            func_002b9030(*(void**)(DAT_007ce3ec + 0xb44));
            *(void**)(DAT_007ce3ec + 0xb44) = NULL;
            break;
        default:
            break;
    }
}

// FUN_002f8790
void func_002f8790()
{
    if (gBtl->bossPakCdvd != NULL)
    {
        func_002f8460();
        func_00100ec0(gBtl->bossPakCdvd);
        gBtl->bossPakCdvd = NULL;
    }
}

// FUN_002f87e0
void* func_002f87e0(u16 index)
{
    u32 fileSize;

    return H_Cdvd_ArchiveGetFile(gBtl->bossPakCdvd, index, &fileSize);
}

// FUN_002f8810
void* func_002f8810()
{
    u32 fileSize;

    return H_Cdvd_ArchiveGetFile(gBtl->bossPakCdvd, 0, &fileSize);
}

// FUN_002f88c0 NONMATCHING
u32 func_002f88c0()
{
    BtlUnit* unit;
    u16 encounterId;
    u16 charId;
    u32 result;

    encounterId = btlBossGetEncounterId();
    switch (encounterId)
    {
        case 0x1a0:
            unit = *(BtlUnit**)((u8*)gBtl + 0x158);
loop_12:
            if (unit == NULL)
            {
                result = 0;
            }
            else
            {
                charId = unit->charId;
                switch (charId)
                {
                    case 0x114:
                    case 0x113:
                        result = 1;
                        break;
                    default:
                    case 0x100:
                        unit = unit->next;
                        goto loop_12;
                }
            }
            return result;
        case 0x1a4:
            unit = *(BtlUnit**)((u8*)gBtl + 0x158);
loop_25:
            if (unit == NULL)
            {
                result = 0;
            }
            else
            {
                charId = unit->charId;
                switch (charId)
                {
                    case 0x115:
                        if (unit->flags3 & 8)
                        {
                            result = 0;
                        }
                        else
                        {
                            unit = unit->next;
                            goto loop_25;
                        }
                        break;
                    case 0x106:
                    case 0x105:
                        if (unit->flags3 & 8)
                        {
                            result = 1;
                        }
                        else
                        {
                            unit = unit->next;
                            goto loop_25;
                        }
                        break;
                }
            }
            return result;
        case 0x1a6:
            return func_002ecac0() != 1;
        case 0x1a8:
            return *(u32*)((u8*)gBtl + 0xb54) == 1;
        default:
            return 0;
    }
}

// FUN_002f8a40 NONMATCHING
u32 func_002f8a40(BtlUnit* unit)
{
    u32 encounterId;

    encounterId = btlBossGetEncounterId();
    if (encounterId == 0x1b4) goto block_1b4;
    if (encounterId == 0x1b3) goto block_zero_1b3;
    if (encounterId == 0x1b2) goto block_zero_1b2;
    if (encounterId == 0x1b1) goto block_zero_1b1;
    if (encounterId == 0x1b0) goto block_zero_1b0;
    if (encounterId == 0x1af) goto block_zero_1af;
    if (encounterId == 0x1ae) goto block_zero_1ae;
    if (encounterId == 0x1ad) goto block_1ad;
    if (encounterId == 0x1ac) goto block_1ac;
    if (encounterId == 0x1ab) goto block_zero_1ab;
    if (encounterId == 0x1aa) goto block_zero_1aa;
    if (encounterId == 0x1a9) goto block_zero_1a9;
    if (encounterId == 0x1a8) goto block_1a8;
    if (encounterId == 0x1a7) goto block_zero_1a7;
    if (encounterId == 0x1a6) goto block_1a6;
    if (encounterId == 0x1a5) goto block_1a5;
    if (encounterId == 0x1a4) goto block_1a4;
    if (encounterId == 0x1a3) goto block_1a3;
    if (encounterId == 0x1a2) goto block_1a2;
    if (encounterId == 0x1a1) goto block_1a1;
    if (encounterId == 0x1a0) goto block_1a0;
    if (encounterId == 0x1c8) goto block_1c8;
    goto block_default;

block_1c8:
    return 0;

block_1a0:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x100)
        {
            return 1;
        }
    }
    return 0;

block_1a1:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x102 || unit->charId == 0x101)
        {
            return 1;
        }
    }
    return 0;

block_1a2:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x103)
        {
            return 1;
        }
    }
    return 0;

block_1a3:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x104)
        {
            return 1;
        }
    }
    return 0;

block_1a4:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x106 ||
            unit->charId == 0x105 ||
            unit->charId == 0x115)
        {
            return 1;
        }
    }
    return 0;

block_1a5:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x107)
        {
            return 1;
        }
    }
    return 0;

block_1a6:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x10a)
        {
            return 1;
        }
    }
    return 0;

block_zero_1a7:
    return 0;

block_1a8:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x10d)
        {
            return 1;
        }
    }
    return 0;

block_zero_1a9:
    return 0;

block_zero_1aa:
    return 0;

block_zero_1ab:
    return 0;

block_1ac:
    return unit->genus == 1;

block_1ad:
    if (unit->genus == 1)
    {
        if (unit->charId == 0x112)
        {
            return 1;
        }
    }
    return 0;

block_zero_1ae:
    return 0;

block_zero_1af:
    return 0;

block_zero_1b0:
    return 0;

block_zero_1b1:
    return 0;

block_zero_1b2:
    return 0;

block_zero_1b3:
    return 0;

block_1b4:
    return unit->genus == 1;

block_default:
    return 0;
}

// FUN_002f8ea0
u32 func_002f8ea0(BtlUnit* unit, RwV3d* target)
{
    (void)unit;
    (void)target;
    return 0;
}

// FUN_002f8eb0
s16 func_002f8eb0(BtlUnit* unit, s16 index)
{
    s8 value;
    u16 result;

    switch (btlBossGetEncounterId())
    {
        case 0x1ae:
            if (unit->genus == 1)
            {
                goto check_character;
            }
            result = -1;
            goto return_result;

check_character:
            if (unit->charId == 0x126)
            {
                goto read_value;
            }
            result = -1;
            goto return_result;

read_value:
            K_ASSERT(index < 0x1d0, 417);
            value = DAT_007ce3f4[index * 2];
            switch (value)
            {
                case 0:
                    result = 4;
                    break;
                case 1:
                    result = 5;
                    break;
                case 2:
                    result = 6;
                    break;
                default:
                    result = -1;
                    break;
            }
return_result:
            return result;
        default:
            return -1;
    }
}

// FUN_002f8fd0 NONMATCHING
s16 func_002f8fd0(BtlUnit* unit, s16 id)
{
    u16 encounterId;
    u16 charId;
    u16 value;
    u32 i;

    encounterId = btlBossGetEncounterId();
    charId = unit->genus == 1 ? unit->charId : 0;
    if (charId == 0)
    {
        return -1;
    }

    if (encounterId == 0x1b4 && charId == 0xf1)
    {
        return (id == 0x126 || id == 0x128 || id == 0x127 || id == 0x125) ? 0 : -1;
    }
    if (encounterId == 0x1a8 && charId == 0x10d && id == 0x134)
    {
        return *(u32*)((u8*)gBtl + 0xb54) == 0 ? 7 : 0x15;
    }
    if (encounterId == 0x1a6 && charId == 0x10a &&
        (id == 0x90 || id == 0x8e || id == 0x8d || id == 0x83 ||
         id == 0x80 || id == 0x7f || id == 0x77 || id == 0x75 || id == 0x73))
    {
        return 0x18;
    }
    if (encounterId == 0x1a5 && charId == 0x107)
    {
        if (id == 0x16b)
        {
            return 0x17;
        }
        if (id == 0x16c)
        {
            return 0x19;
        }
        return -1;
    }
    if (encounterId == 0x1a3 && charId == 0x104 &&
        func_002d6370(id) != 0)
    {
        return 0x18;
    }
    if (encounterId == 0x1a2 && charId == 0x103 && id == 0x163)
    {
        return 0x17;
    }
    if (encounterId == 0x1a1 &&
        (charId == 0x102 || charId == 0x101) && id == 0x170)
    {
        return 0x17;
    }
    if (charId >= 0x95 && charId <= 0x9c)
    {
        for (i = 0; i < 4; i++)
        {
            value = *(u16*)(DAT_007ce4b4 + (charId - 0x95) * 8 + i * 2);
            if (id == value)
            {
                return i == 3 ? 0x18 : i == 2 ? 0x17 : i == 1 ? 7 : 4;
            }
        }
        return 7;
    }
    return -1;
}

// FUN_002f9560
s16 func_002f9560(BtlUnit* unit, u16* flags)
{
    s16 result;
    u16 encounterId;
    void* resource;

    encounterId = btlBossGetEncounterId();
    switch (encounterId)
    {
        case 0x1a5:
            goto encounter_1a5;
        case 0x1a8:
            goto encounter_1a8;
        default:
            goto return_default;
    }

encounter_1a5:
    if (unit->genus == 1)
    {
        goto encounter_1a5_char;
    }
    result = -1;
    goto return_1a5;

encounter_1a5_char:
    if (unit->charId == 0x107)
    {
        goto encounter_1a5_flags;
    }
    result = -1;
    goto return_1a5;

encounter_1a5_flags:
    if (flags[1] != 0x17)
    {
        goto encounter_1a5_resource;
    }
    result = 0;
    goto return_1a5;

encounter_1a5_resource:
    resource = encounterId == 0x1a5
        ? *(void**)((u8*)gBtl + 0xb44)
        : NULL;
    if (resource != NULL)
    {
        result = 0xc;
    }
    else
    {
        result = -1;
    }
    goto return_1a5;

return_1a5:
    goto return_1a5_common;

return_1a5_common:
    return result;

encounter_1a8:
    if (unit->genus == 1)
    {
        goto encounter_1a8_char;
    }
    result = -1;
    goto return_1a8;

encounter_1a8_char:
    if (unit->charId == 0x10d)
    {
        goto encounter_1a8_flags;
    }
    result = -1;
    goto return_1a8;

encounter_1a8_flags:
    if (flags[1] == 0x19)
    {
        result = 0;
    }
    else
    {
        result = -1;
    }
    goto return_1a8;

return_1a8:
    goto return_1a8_common;

return_1a8_common:
    return result;

return_default:
    return -1;
}

// FUN_002f9690
s16 func_002f9690(BtlUnit* unit)
{
    u16 encounterId;

    encounterId = btlBossGetEncounterId();
    switch (encounterId)
    {
        case 0x1af:
        case 0x1b0:
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            break;
        default:
            goto return_minus_one;
    }
    if (unit->genus != 1)
    {
        goto return_minus_one;
    }
    return 0;

return_minus_one:
    return -1;
}

extern void func_00288f80(BtlUnit* unit, s32 value);
extern void func_002f4490(void);
extern void func_002f5330(void);
extern void func_002f5980(void);
extern void func_002e4220(u32 begin, u32 end, void* action);
extern s32 func_002e4250(void);
extern void func_002d3fe0(BtlUnit* unit);
extern void func_002831c0(BtlUnit* unit, s32 value);
extern void func_00282d40(f32 value, BtlUnit* unit, s16 value2, s32 value3, s8 value4);
extern void func_00287510(BtlUnit* unit);
extern void func_0027f650(BtlUnit* unit, u32 value);
extern void func_002eaa40(void);

// FUN_002f9c10 NONMATCHING
u32 func_002f9c10(BtlAction* action)
{
    BtlUnit* unit;
    u16 encounterId;
    u16 charId;

    encounterId = btlBossGetEncounterId();
    unit = action->unit;
    charId = unit->charId;

    switch (encounterId)
    {
        case 0x1a0:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x100)
            {
                unit->flags3 |= 0x540;
            }
            return 1;
        case 0x1a1:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
                (charId == 0x102 || charId == 0x101))
            {
                *(u16*)unit->datUnit |= 0x40;
                unit->flags3 |= 0x100;
            }
            return 1;
        case 0x1a2:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x103)
            {
                unit->flags3 |= 0x540;
            }
            return 1;
        case 0x1a3:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x104)
            {
                unit->flags3 |= 0x540;
            }
            return 1;
        case 0x1a4:
            func_002ea780(action);
            return 1;
        case 0x1a5:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x107)
            {
                unit->flags3 |= 0x540;
            }
            return 1;
        case 0x1a6:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
                (charId == 0x10a || charId == 0x109))
            {
                *(u16*)unit->datUnit |= 0x40;
                unit->flags3 |= 0x100;
            }
            return 1;
        case 0x1a7:
            func_002eeb70(action);
            return 1;
        case 0x1a8:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1)
            {
                if (charId == 0x118 || charId == 0x117 || charId == 0x116)
                {
                    *(u16*)unit->datUnit |= 0x40;
                    unit->flags3 |= 0x100;
                }
                else if (charId == 0x10d)
                {
                    action->unk_1a &= ~8;
                    unit->flags3 |= 0x540;
                }
            }
            return 1;
        case 0x1a9:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x108)
            {
                action->unk_1a |= 0x10;
                unit->flags3 |= 0x1c0;
                func_00288f80(unit, 0xd2);
            }
            return 0;
        case 0x1aa:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x10f)
            {
                action->unk_1a |= 0x10;
                unit->flags3 |= 0x1c0;
                func_00288f80(unit, 0xd1);
            }
            return 0;
        case 0x1ab:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x110)
            {
                action->unk_1a |= 0x10;
                unit->flags3 |= 0x1c0;
                func_00288f80(unit, 0xd0);
            }
            return 0;
        case 0x1ac:
            if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0x111)
            {
                unit->flags3 |= 0x500;
                *(u16*)unit->datUnit |= 0x40;
                unit->flags3 |= 0x400;
                func_0029a2c0();
            }
            return 1;
        case 0x1ad:
            func_002f3670(action);
            return 1;
        case 0x1ae:
            func_002f4490();
            return 1;
        case 0x1af:
            func_002f4890(action);
            return 0;
        case 0x1b0:
            func_002f4c00(action);
            return 0;
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            func_002f5330();
            return 0;
        case 0x1b4:
            func_002f5980();
            return 0;
        default:
            return 0;
    }
}

// FUN_002fa240
u32 func_002fa240(void)
{
    switch (btlBossGetEncounterId())
    {
        case 0x1c8: func_002e9170(); return 1;
        case 0x1a0: func_002e92c0(); return 1;
        case 0x1a1: func_002e9950(); return 1;
        case 0x1a2: func_002ea060(); return 1;
        case 0x1a3: func_002ea400(); return 1;
        case 0x1a4: func_002ea860(); return 1;
        case 0x1a5: func_002ec000(); return 1;
        case 0x1a6: func_002ec5c0(); return 1;
        case 0x1a7: func_002eec60(); return 1;
        case 0x1a8: func_002ef360(); return 1;
        case 0x1a9: func_002f1680(); return 1;
        case 0x1aa: func_002f19d0(); return 1;
        case 0x1ab: func_002f1f00(); return 1;
        case 0x1ac: func_002f2250(); return 1;
        case 0x1ad: func_002f3760(); return 1;
        case 0x1ae: func_002f4540(); return 1;
        case 0x1af: func_002f4950(); return 1;
        case 0x1b0: func_002f4ce0(); return 1;
        case 0x1b1:
        case 0x1b2:
        case 0x1b3: func_002f5490(); return 1;
        case 0x1b4: func_002f5a70(); return 1;
        default: return 0;
    }
}

// FUN_002fa510 NONMATCHING
void func_002fa510(BtlAction* action, s32 mode)
{
    u16 encounterId;
    BtlUnit* unit;
    u16 charId;
    u16 slot;

    encounterId = btlBossGetEncounterId();
    unit = action->unit;
    charId = unit->charId;
    if (encounterId == 0x1b4)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 && charId == 0xf1 &&
            mode != 0 && func_002e4250() == 0)
        {
            *(void**)((u8*)gBtl + 0xb4c) = NULL;
            func_002e4220(0x2f6840, 0x2f6ab0, action);
        }
    }
    else if (encounterId == 0x1b1 || encounterId == 0x1b2 || encounterId == 0x1b3)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
            (charId >= 0xeb && charId <= 0xf0) &&
            mode != 0 && func_002e4250() == 0)
        {
            func_002e4220(0x2f5660, 0x2f5870, action);
        }
    }
    else if (encounterId == 0x1ac)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
            func_002e4250() == 0)
        {
            if (*(s16*)((u8*)0x0069a1d0 + *(u16*)((u8*)gBtl + 0xb48) * 4) == 0)
            {
                func_002e4220(0x2f3320, 0x2f3520, action);
            }
            else
            {
                func_002e4220(0x2f2b90, 0x2f3190, action);
            }
        }
    }
    else if (encounterId == 0x1a8)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
            (charId == 0x118 || charId == 0x117 || charId == 0x116) && mode == 1)
        {
            slot = *(u16*)((u8*)gBtl + 0xb50);
            *(BtlAction**)((u8*)gBtl + 0xb44 + slot * 4) = action;
            *(u16*)((u8*)gBtl + 0xb50) = slot + 1;
            func_002e4220(0x2f0ea0, 0x2f14a0, action);
        }
    }
    else if (encounterId == 0x1a7)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
            (charId == 0x10c || charId == 0x10b) &&
            mode != 0 && func_002e4250() == 0)
        {
            func_002e4220(0x2ef000, 0x2ef250, action);
        }
    }
    else if (encounterId == 0x1a6)
    {
        if ((action->unk_1a & 1) != 0 && unit->genus == 1 &&
            (charId == 0x10a || charId == 0x109) &&
            mode == 1 && func_002e4250() == 0)
        {
            func_002e4220(0x2ee640, 0x2eea10, action);
        }
    }
    else if (encounterId == 0x1a4 && (action->unk_1a & 1) != 0 && unit->genus == 1)
    {
        if (charId == 0x106 || charId == 0x105)
        {
            if (mode == 0)
            {
                if (func_002e4250() != 0)
                {
                    action = NULL;
                }
                func_002e4220(0x2eba50, 0x2ebec0, action);
            }
        }
        else if (charId == 0x115 && mode == 1)
        {
            func_002e4220(0x2eabf0, 0x2eb250, action);
        }
    }
    else if (encounterId == 0x1a1 && (action->unk_1a & 1) != 0 &&
             unit->genus == 1 && (charId == 0x102 || charId == 0x101) && mode == 1)
    {
        func_002e4220(0x2e9c20, 0x2e9f10, action);
    }
}


// FUN_002faa50
void func_002faa50(BtlAction* source, BtlAction* target, BtlTargetResult* result)
{
    switch (btlBossGetEncounterId())
    {
        case 0x1a5:
            func_002ec190(source, target, result);
            break;

        case 0x1b4:
            func_002f5bf0(source, target, result);
            break;
    }
}
// FUN_002faab0 NONMATCHING
void func_002faab0()
{
    BtlUnit* unit;
    u16 encounterId;
    u8* model;

    encounterId = btlBossGetEncounterId();
    if (encounterId == 0x1b4)
    {
        for (unit = btlBossGetEnemyHead(); unit != NULL; unit = unit->next)
        {
            if (unit->charId == 0xf2)
            {
                func_002d3fe0(unit);
                func_002831c0(unit, 0);
                func_00282d40(unit->unk_9e4, unit, unit->unk_9e0, 0, unit->unk_9e8);
                func_00287510(unit);
                func_0027f650(unit, 0x957180);
            }
        }
    }
    else if (encounterId == 0x1ac)
    {
        for (unit = btlBossGetEnemyHead(); unit != NULL; unit = unit->next)
        {
            if (unit->charId == 0x111)
            {
                model = (u8*)unit->mdl;
                model[0x388] |= 8;
                *(u32*)((u8*)gBtl + 0xb50) = 0;
                model[0x41d] = 0;
            }
        }
    }
    else if (encounterId == 0x1a8)
    {
        func_002ef5a0();
    }
    else if (encounterId == 0x1a5)
    {
        for (unit = btlBossGetEnemyHead(); unit != NULL; unit = unit->next)
        {
            if (unit->charId == 0x107)
            {
                model = (u8*)unit->mdl;
                model[0x388] |= 8;
                *(u32*)((u8*)gBtl + 0xb4c) = 0;
                model[0x41d] = 0;
            }
        }
    }
    else if (encounterId == 0x1a4)
    {
        func_002eaa40();
    }
}

extern void func_0029a690(s32 value);
extern void func_0029a470(void* value);
extern void func_002b90d0(void* object, void* archiveEntry);
extern void* func_002baf90(void* object, u32 value1, u32 value2, s32 value3, u32 value4);
extern void func_0027ed20(void* object, s32 value);
extern void func_002ef670(void);
extern void func_002ec790(void);
extern void func_002e9ac0(void);
extern void func_002e9450(void);
extern s32 func_00300580(u32 persona, s32 value);
extern s32 func_00301750(u32 persona, s32 value);
extern s32 func_0030b5e0(u32 persona);

typedef struct BtlBossAnimRecord
{
    u16 unk_0;
    BtlUnitAnimBounds bounds;
} BtlBossAnimRecord;

extern BtlUnitAnimBounds DAT_0069A0E8;
extern BtlUnitAnimBounds DAT_0069A5A8;
extern BtlBossAnimRecord* D_007CE4C0;

static u32 btlBossCreateModePacket(u16 archiveIndex)
{
    void* object;
    void* file;
    void* work;
    void* generated;
    u32 fileSize;
    u32 mode;

    object = func_002b8f90(0);
    file = H_Cdvd_ArchiveGetFile(gBtl->bossPakCdvd, archiveIndex, &fileSize);
    func_002b90d0(object, file);
    work = *(void**)((u8*)gBtl + 0x148);
    mode = *(u32*)((u8*)work + 0x30);
    generated = func_002baf90(object, mode, mode, 0, 0x200);
    func_0027ed20(generated, 2);
    func_002b9030(object);
    return 1;
}

// FUN_002fac80
void func_002fac80()
{
    func_0029a690(0);
    func_0029a470(*(void**)((u8*)gBtl + 0x148));
}

// FUN_002facc0 NONMATCHING
u32 func_002facc0()
{
    switch (btlBossGetEncounterIdCall())
    {
        case 0x1b4: return btlBossCreateModePacket(1);
        case 0x1b1:
        case 0x1b2:
        case 0x1b3: return btlBossCreateModePacket(1);
        case 0x1b0: return btlBossCreateModePacket(1);
        case 0x1af: return btlBossCreateModePacket(1);
        case 0x1ae: return btlBossCreateModePacket(1);
        case 0x1ad: return btlBossCreateModePacket(1);
        case 0x1ac: return btlBossCreateModePacket(1);
        case 0x1ab: return btlBossCreateModePacket(1);
        case 0x1aa: return btlBossCreateModePacket(1);
        case 0x1a9: return btlBossCreateModePacket(1);
        case 0x1a8: func_002ef670(); return 1;
        case 0x1a7: return btlBossCreateModePacket(1);
        case 0x1a6: func_002ec790(); return 1;
        case 0x1a5: return btlBossCreateModePacket(1);
        case 0x1a4: return btlBossCreateModePacket(1);
        case 0x1a3: return btlBossCreateModePacket(1);
        case 0x1a2: return btlBossCreateModePacket(1);
        case 0x1a1: func_002e9ac0(); return 1;
        case 0x1a0: func_002e9450(); return 1;
        case 0x1c8: return btlBossCreateModePacket(0);
        default: return 0;
    }
}

// FUN_002fb690
u32 func_002fb690()
{
    u16 encounterId = btlBossGetEncounterId();

    if (encounterId == 0x1b4) goto encounter_1b4;
    if (encounterId == 0x1b0) goto encounter_1b0;
    if (encounterId == 0x1af) goto encounter_1af;
    if (encounterId == 0x1ae) goto encounter_1ae;
    if (encounterId == 0x1ad) goto encounter_1ad;
    if (encounterId == 0x1ab) goto encounter_1ab;
    if (encounterId == 0x1aa) goto encounter_1aa;
    if (encounterId == 0x1a9) goto encounter_1a9;
    if (encounterId == 0x1a8) goto encounter_1a8;
    if (encounterId == 0x1a5) goto encounter_1a5;
    if (encounterId == 0x1a3) goto encounter_1a3;
    if (encounterId == 0x1a2) goto encounter_1a2;
    switch (encounterId)
    {
        case 0x1a0:
            goto encounter_1a0;
        default:
            goto encounter_default;
    }

encounter_1a0:
    func_002e95f0();
    return 1;
encounter_1a2:
    func_002ea210();
    return 1;
encounter_1a3:
    func_002ea590();
    return 1;
encounter_1a5:
    func_002ec2c0();
    return 1;
encounter_1a8:
    func_002ef7e0();
    return 1;
encounter_1a9:
    func_002f1810();
    return 1;
encounter_1aa:
    func_002f1d40();
    return 1;
encounter_1ab:
    func_002f2090();
    return 1;
encounter_1ad:
    func_002f3840();
    return 1;
encounter_1ae:
    func_002f46d0();
    return 1;
encounter_1af:
    func_002f4a40();
    return 1;
encounter_1b0:
    func_002f4e70();
    return 1;
encounter_1b4:
    func_002f6120();
    return 1;
encounter_default:
    return 0;
}

// FUN_002fb860 NONMATCHING
u16 func_002fb860(BtlUnit* unit, u16 index)
{
    u16 encounterId;
    u16 charId;
    u8* table;
    u16 value;

    encounterId = btlBossGetEncounterId();
    if (unit->genus != 1)
    {
        return 0xffff;
    }
    charId = unit->charId;
    table = NULL;
    switch (encounterId)
    {
        case 0x1a0: if (charId == 0x100) table = (u8*)0x00699bf0; break;
        case 0x1a1:
            if (charId == 0x102) table = (u8*)0x00699c3a;
            else if (charId == 0x101) table = (u8*)0x00699c20;
            break;
        case 0x1a2: if (charId == 0x103) table = (u8*)0x00699c90; break;
        case 0x1a3: if (charId == 0x104) table = (u8*)0x00699ce0; break;
        case 0x1a4:
            if (charId == 0x115) table = (u8*)0x00699d64;
            else if (charId == 0x106) table = (u8*)0x00699d4a;
            else if (charId == 0x105) table = (u8*)0x00699d30;
            break;
        case 0x1a5:
            if (charId == 0x107)
            {
                if ((index == 0x11 || index == 3 || index == 0) &&
                    *(void**)((u8*)gBtl + 0xb44) != NULL)
                {
                    *(u32*)((u8*)gBtl + 0xb4c) = 1;
                    return 0xf;
                }
                if (*(void**)((u8*)gBtl + 0xb44) == NULL)
                {
                    *(u32*)((u8*)gBtl + 0xb4c) = 0;
                }
                table = (u8*)0x00699dd0;
            }
            break;
        case 0x1a6:
            if (charId == 0x10a) table = (u8*)0x00699e3a;
            else if (charId == 0x109)
            {
                if ((index == 9 || index == 0x11 || index == 3 || index == 0) &&
                    *(u32*)((u8*)gBtl + 0xb50) == 1)
                {
                    return 6;
                }
                table = (u8*)0x00699e20;
            }
            else if (charId == 0xe8 || charId == 0xe7 || charId == 0xe6 ||
                     charId == 0xe5 || charId == 0xe4 || charId == 0xe3 ||
                     charId == 0xe2)
            {
                return 0xffff;
            }
            break;
        case 0x1a7:
            if (charId == 0x10c) table = (u8*)0x0069a03a;
            else if (charId == 0x10b) table = (u8*)0x0069a020;
            break;
        case 0x1a8:
            if (charId == 0x127 || charId == 0x119)
            {
                if (index == 3 && func_00300580(*(u32*)unit->datUnit, 0x400) != 0)
                {
                    return 0xf;
                }
                table = (u8*)0x0069a0ce;
            }
            else if (charId == 0x118 || charId == 0x117 || charId == 0x116)
            {
                table = (u8*)0x0069a0b4;
            }
            else if (charId == 0x10d)
            {
                table = *(u32*)((u8*)gBtl + 0xb54) == 0
                    ? (u8*)0x0069a080 : (u8*)0x0069a09a;
            }
            break;
        case 0x1a9: if (charId == 0x108) table = (u8*)0x0069a130; break;
        case 0x1aa: if (charId == 0x10f) table = (u8*)0x0069a170; break;
        case 0x1ab: if (charId == 0x110) table = (u8*)0x0069a1b0; break;
        case 0x1ac:
            if ((index == 0x11 || index == 3 || index == 0) &&
                func_00301750(*(u32*)unit->datUnit, 0xb) > 0)
            {
                *(u32*)((u8*)gBtl + 0xb50) = 1;
                return 0xf;
            }
            if (func_00301750(*(u32*)unit->datUnit, 0xb) == 0)
            {
                *(u32*)((u8*)gBtl + 0xb50) = 0;
            }
            table = (u8*)0x0069a230;
            break;
        case 0x1ad: if (charId == 0x112) table = (u8*)0x0069a380; break;
        case 0x1ae: if (charId == 0x126) table = (u8*)0x0069a490; break;
        case 0x1af: if (charId == 0xe9) table = (u8*)0x0069a4d0; break;
        case 0x1b0: if (charId == 0xea) table = (u8*)0x0069a510; break;
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            if (charId >= 0xeb && charId <= 0xf0) table = (u8*)0x0069a530;
            break;
        case 0x1b4:
            if (charId == 0xf1)
            {
                if (*(u32*)((u8*)gBtl + 0xb48) == 0)
                {
                    if (index == 2 && func_0030b5e0(*(u32*)unit->datUnit) != 0)
                    {
                        return 6;
                    }
                    table = (u8*)0x0069a570;
                }
                else
                {
                    table = (u8*)0x0069a58a;
                }
            }
            break;
        default:
            break;
    }
    if (table == NULL)
    {
        return 0xffff;
    }
    value = table[index];
    return value;
}

static inline BtlUnitAnimBounds* btlBossGetSpecialAnim1A8(BtlUnit* unit)
{
    if (unit->genus != 1)
    {
        return NULL;
    }
    if (unit->charId != 0x10d)
    {
        return NULL;
    }
    if (*(u32*)((u8*)gBtl + 0xb54) == 1)
    {
        return &DAT_0069A0E8;
    }
    return NULL;
}

static inline BtlUnitAnimBounds* btlBossGetSpecialAnim1B4(BtlUnit* unit)
{
    u32 resource;

    if (unit->genus != 1)
    {
        return NULL;
    }
    if (unit->charId != 0xf1)
    {
        return NULL;
    }
    resource = btlBossGetEncounterId() == 0x1b4
        ? *(u32*)((u8*)gBtl + 0xb48)
        : 0;
    if (resource == 1)
    {
        return &DAT_0069A5A8;
    }
    return NULL;
}

// FUN_002fc410
BtlUnitAnimBounds* func_002fc410(BtlUnit* unit)
{
    switch (btlBossGetEncounterId())
    {
    case 0x1a8:
        return btlBossGetSpecialAnim1A8(unit);
    case 0x1b4:
        return btlBossGetSpecialAnim1B4(unit);
    default:
        return NULL;
    }
}

// FUN_002fc520
BtlUnitAnimBounds* func_002fc520(BtlUnit* unit)
{
    s16 animation;

    if (unit->genus != 1)
    {
        return NULL;
    }
    animation = func_002f6c50(unit->charId);
    if (animation == -1)
    {
        return NULL;
    }
    switch (animation)
    {
    case 0x14:
    case 0x15:
        return NULL;
    default:
        return &D_007CE4C0[animation].bounds;
    }
}

// FUN_002fc5d0 NONMATCHING
f32 func_002fc5d0(BtlUnit* unit, BtlUnit* target, s32 animation)
{
    u16 charId;
    f32 base;

    if ((gBtl->flags & 0x200000) == 0 || target->genus != 1)
    {
        return -1.0f;
    }
    base = target->sphereRadius * target->scale;
    charId = target->charId;
    if (unit->genus == 2 && charId == 0xf1)
    {
        return (animation == 2 || animation == 0) ? base + 500.0f : -1.0f;
    }
    if (animation != 0xb && animation != 6 && animation != 5 && animation != 4)
    {
        return -1.0f;
    }
    switch (charId)
    {
        case 0xf1: return base + 950.0f;
        case 0x128: case 0x125: case 0x124: case 0x123: case 0x122:
        case 0x121: case 0x120: case 0x11f: case 0x11e: case 0x11d:
        case 0x11c: case 0x11b: case 0x11a: case 0x111: return base + 375.0f;
        case 0x110: case 0x10f: return -1.0f;
        case 0x10d: return base + 100.0f;
        case 0x10c: case 0x10b: return -1.0f;
        case 0x10a: return base + 200.0f;
        case 0x109: return base;
        case 0x108: return -1.0f;
        case 0x107: return base + 125.0f;
        case 0x115: return base + 50.0f;
        case 0x106: return base + 175.0f;
        case 0x105: case 0x104: return base + 150.0f;
        case 0x103: case 0x102: case 0x101: return base + 100.0f;
        case 0x100: return base + 150.0f;
        default: return -1.0f;
    }
}

/* Recovered battle-misc harvest: 0x002FCAA0-0x002FED10 */
// FUN_002FCAA0 NONMATCHING


u32 FUN_002fcaa0(int param_1,u32 *param_2)



{

  u16 sVar1;

  u32 uVar2;

  

  switch(*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8)) {

  case 0x1a7:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) == 1) {

      sVar1 = *(u16 *)(*(int *)(param_1 + 0x30) + 0xa4);

      switch (sVar1)
      {
        case 0x10c:
        case 0x10b:
          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

          uVar2 = 1;
          break;

        default:
          uVar2 = 0;
          break;
      }

    }

    else {

      uVar2 = 0;

    }

    break;

  default:

    uVar2 = 0;

    break;

  case 0x1a9:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x108) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1aa:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x10f) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1ab:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x110) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1ae:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x126) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1af:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xe9) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1b0:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xea) {

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        }

        else {

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

    break;

  case 0x1b1:

  case 0x1b2:

  case 0x1b3:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

      if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

        switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

        case 0xeb:

        case 0xec:

        case 0xed:

        case 0xee:

        case 0xef:

        case 0xf0:

          *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

          param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

          param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

          break;

        default:

          uVar2 = 0;

        }

      }

      else {

        uVar2 = 0;

      }

    }

  }

  return uVar2;

}

// FUN_002FCF50


u32 FUN_002fcf50(int param_1)
{
    u16 encounterId;
    u32 result;
    u32 caseResult;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1ae:
        if ((*(u16*)((u8*)param_1 + 0x1a) & 1) == 0)
            caseResult = 0;
        else
        {
            if (*(u8*)(*(u8**)((u8*)param_1 + 0x30) + 0xa2) != 1)
                caseResult = 0;
            else
            {
                switch (*(u16*)(*(u8**)((u8*)param_1 + 0x30) + 0xa4))
                {
                case 0x126:
                    caseResult = *(u32*)(DAT_007ce3ec + 0xb50);
                    break;
                default:
                    caseResult = 0;
                    break;
                }
            }
        }
        result = caseResult;
        break;
    case 0x1b0:
        if ((*(u16*)((u8*)param_1 + 0x1a) & 1) == 0)
            caseResult = 0;
        else
        {
            if (*(u8*)(*(u8**)((u8*)param_1 + 0x30) + 0xa2) != 1)
                caseResult = 0;
            else
            {
                switch (*(u16*)(*(u8**)((u8*)param_1 + 0x30) + 0xa4))
                {
                case 0xea:
                    caseResult = *(u32*)(DAT_007ce3ec + 0xb50);
                    break;
                default:
                    caseResult = 0;
                    break;
                }
            }
        }
        result = caseResult;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
// FUN_002FD060


u32 FUN_002fd060(BtlAction* action)
{
    u16 encounterId;
    u32 result;
    u32 caseResult;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1ad:
        if ((action->unk_1a & 1) == 0)
            caseResult = 0;
        else
        {
            if (action->unit->genus != UNIT_GENUS_EC)
                caseResult = 0;
            else
            {
                if (action->unit->charId == 0x112)
                    caseResult = *(u32*)(DAT_007ce3ec + 0xb44);
                else
                    caseResult = 0;
            }
        }
        result = caseResult;
        break;
    case 0x1b4:
        if ((action->unk_1a & 1) == 0)
            caseResult = 0;
        else
        {
            if (action->unit->genus != UNIT_GENUS_EC)
                caseResult = 0;
            else
            {
                if (action->unit->charId == 0xf1)
                    caseResult = *(u32*)(DAT_007ce3ec + 0xb44);
                else
                    caseResult = 0;
            }
        }
        result = caseResult;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002FD160


u32 FUN_002fd160(BtlAction* action)
{
    s8 helperResult;
    u32 result;
    u32 caseResult;
    u16 encounterId;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1ac:
        if ((action->unk_1a & 1) == 0)
            caseResult = 0;
        else
        {
            if (action->unit->genus != UNIT_GENUS_EC)
                caseResult = 0;
            else
            {
                helperResult = (s8)FUN_00301750((int)action->unit->datUnit, 0xb);
                if (helperResult > 0)
                    caseResult = *(u32*)(DAT_007ce3ec + 0xb44);
                else
                    caseResult = 0;
            }
        }
        result = caseResult;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002FD220


u32 FUN_002fd220(BtlAction* action, BtlAction* target)
{
    u32 encounterResult;
    u32 result;
    int bossState;
    int helperResult;

    switch (*(u16*)(*(int*)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a5:
        helperResult = FUN_0030af00(
            *(u32*)(*(int*)((int)action + 0x30) + 0xa2c),
            *(u32*)(*(int*)((int)target + 0x30) + 0xa2c));
        if (helperResult == 0)
        {
            encounterResult = 0;
        }
        else
        {
            if (*(u16*)(*(int*)(DAT_007ce3ec + 0xbbc) + 8) == 0x1a5)
            {
                bossState = *(int*)(DAT_007ce3ec + 0xb44);
            }
            else
            {
                bossState = 0;
            }
            if (bossState == 0)
            {
                encounterResult = 0;
            }
            else
            {
                encounterResult = *(int*)(DAT_007ce3ec + 0xb48) == 0;
            }
        }
        result = encounterResult;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002FD2E0 NONMATCHING
u32 FUN_002fd2e0(int param_1, u16 param_2)
{
    int iVar4;
    KwlnTask* task;
    ScrData* scr;

    iVar4 = (int)(uintptr_t)((u8*)gBtl + (u32)param_2 * 4);
    if (*(s32*)(iVar4 + 0xb2c) == *(s32*)(param_1 + 8) &&
        *(s32*)(iVar4 + 0xb38) == *(s32*)(param_1 + 0x20))
    {
        return 0;
    }

    switch (param_2)
    {
    case 0:
        if (*(s32*)((u8*)gBtl + 0xb1c) != -1)
        {
            goto fd2_create;
        }
        return 0;
    case 1:
        if (*(s32*)((u8*)gBtl + 0xb20) != -1)
        {
            goto fd2_create;
        }
        return 0;
    case 2:
        if (*(s32*)((u8*)gBtl + 0xb24) != -1)
        {
            goto fd2_create;
        }
        return 0;
    default:
        break;
    }

fd2_create:
    task = scrCreateTaskFromHeader_2(
        (u32)(*(s32*)(*(u8**)((u8*)gBtl + 0xd18) + 0x20) - 1),
        *(ScrHeader**)DAT_0069aa50);
    FUN_0035c1a0(task, *(s32*)((u8*)gBtl + 0x148));
    scr = (ScrData*)FUN_0035ae10(task);
    if (scr->mesHandleIdx >= 0)
    {
        FUN_003a4220(scr->mesHandleIdx, 0, FUN_001778b0(1));
    }
    FUN_00195550(*(KwlnTask**)((u8*)gBtl + 0xd18), task);
    *(KwlnTask**)((u8*)gBtl + 0xb28) = task;
    *(s32*)((u8*)gBtl + (u32)param_2 * 4 + 0xb2c) =
        *(s32*)(param_1 + 8);
    *(s32*)((u8*)gBtl + (u32)param_2 * 4 + 0xb38) =
        *(s32*)(param_1 + 0x20);
    return 1;
}

// FUN_002FD4A0


u32 FUN_002fd4a0(void)
{
    s32 task;

    task = *(s32*)(DAT_007ce3ec + 0xb28);
    if (task == 0)
    {
        return 0;
    }
    if (FUN_00195460(task) == 0)
    {
        *(u32*)(DAT_007ce3ec + 0xb28) = 0;
        return 0;
    }
    return 1;
}

// FUN_002FD500


u8 FUN_002fd500(void)



{

  return *(int *)(DAT_007ce3ec + 0xb28) != 0;

}

// FUN_002FD520


void FUN_002fd520(int param_1)
{
    BtlUnit* unit;
    u16 encounterId;
    u8* text;
    u8 value;

    unit = (BtlUnit*)param_1;
    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1a5:
        FUN_002ec4b0();
        break;
    case 0x1a6:
        FUN_002ec990();
        break;
    case 0x1a8:
        func_002efb40(unit);
        break;
    case 0x1ac:
        if (unit->genus == 1 && (unit->flags2 & 2) != 0)
        {
            if (*(u32*)(DAT_007ce3ec + 0xb50) != 0)
            {
                text = (u8*)unit->mdl + 0x41d;
                value = *text;
                if (value < 0xdf)
                {
                    *text = value + 0x20;
                }
                else
                {
                    *text = 0xff;
                }
            }
            else
            {
                text = (u8*)unit->mdl + 0x41d;
                if (*text > 0x20)
                {
                    *text -= 0x20;
                }
                else
                {
                    *text = 0;
                }
            }
        }
        break;
    case 0x1b4:
        FUN_002f5d80();
        break;
    default:
        break;
    }
}

// FUN_002FD660


u32 FUN_002fd660(void)
{
    BtlUnit* unit;
    u16 encounterId;
    u32 result;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1a0:
        result = FUN_002e97e0();
        break;
    case 0x1a4:
        for (unit = *(BtlUnit**)(DAT_007ce3ec + 0x158);
             unit != NULL; unit = unit->next)
        {
            switch (unit->charId)
            {
            case 0x105:
            case 0x106:
                if (FUN_0030b5a0(unit->datUnit, 0) == 0)
                {
                    result = 0;
                    goto fd660_1a4_done;
                }
                break;
            default:
                break;
            }
        }
        result = 1;
fd660_1a4_done:
        return result;
    case 0x1a8:
        result = FUN_002ef9d0();
        break;
    case 0x1b4:
        for (unit = *(BtlUnit**)(DAT_007ce3ec + 0x158);
             unit != NULL; unit = unit->next)
        {
            switch (unit->charId)
            {
            case 0xf1:
                if (FUN_0030b5a0(unit->datUnit, 0) == 0)
                {
                    result = 0;
                    goto fd660_1b4_done;
                }
                break;
            default:
                break;
            }
        }
        result = 1;
fd660_1b4_done:
        return result;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002FD7C0


u32 FUN_002fd7c0(void)
{
    void* encounter;
    u16 encounterId;

    encounter = *(void**)(DAT_007ce3ec + 0xbbc);
    if (encounter == NULL) {
        return 0;
    }
    encounterId = *(u16*)((u8*)encounter + 8);
    switch (encounterId) {
    case 0x1c8:
    case 0x1ad:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_002FD820
void FUN_002fd820(void)
{
    u8* work;
    u16 encounterId;

    work = DAT_007ce3ec;
    encounterId = *(u16*)(*(u8**)(work + 0xbbc) + 8);
    switch (encounterId) {
    case 0x1ad:
        if (3 < *(u16*)(work + 0xb48)) {
            FUN_001fece0();
            FUN_001fee20();
        }
        FUN_001fed60();
        FUN_001feda0();
        FUN_001fee60();
        FUN_001fede0();
        break;
    default:
        break;
    }
}

// FUN_002FD8A0 NONMATCHING
void FUN_002fd8a0(int param_1)
{
    u8* data;

    switch (*(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a7:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1)
            {
                switch (*(u16*)(data + 0xa4))
                {
                case 0x10b:
                case 0x10c:
                    FUN_00289860();
                    break;
                default:
                    break;
                }
            }
        }
        break;
    case 0x1a9:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0x108)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1aa:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0x10f)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1ab:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0x110)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1ae:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0x126)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1af:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0xe9)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1b0:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1 && *(u16*)(data + 0xa4) == 0xea)
            {
                FUN_00289860();
            }
        }
        break;
    case 0x1b1:
    case 0x1b2:
    case 0x1b3:
        if ((*(u16*)(param_1 + 0x1a) & 1) != 0)
        {
            data = *(u8**)(param_1 + 0x30);
            if (data[0xa2] == 1)
            {
                switch (*(u16*)(data + 0xa4))
                {
                case 0xeb:
                case 0xec:
                case 0xed:
                case 0xee:
                case 0xef:
                case 0xf0:
                    FUN_00289860();
                    break;
                default:
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

// FUN_002FDB70


u32 FUN_002fdb70(void)



{

  return ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) != 0) ^ 1;

}

// FUN_002FDB90


u32 FUN_002fdb90(void)



{

  return ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) != 0) ^ 1;

}

// FUN_002FDBB0
s32 FUN_002fdbb0(BtlAction* action, BtlUnit* unit)
{
    if ((*(u32*)(DAT_007ce3ec + 0xc) & 0x200000) != 0)
    {
        if ((*(u16*)(DAT_007ce42c + (u32)unit->charId * 0x58) & 1) != 0)
        {
            return !FUN_002d63b0(unit, ((s16*)&action->target)[27],
                                 FUN_002d6290());
        }
        if (FUN_002d6290() == 0 &&
            (*(u16*)(DAT_007ce42c + (u32)unit->charId * 0x58) & 0x20) != 0)
        {
            return 1;
        }
    }
    return 0;
}

// FUN_002FDCB0


u8 FUN_002fdcb0(int param_1)



{

  u8 bVar1;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {

    bVar1 = 0;

  }

  else {

    bVar1 = *(u8 *)(param_1 + 0xa2) == '\x01';

  }

  return bVar1;

}

// FUN_002FDCF0


u32 FUN_002fdcf0(int param_1, int param_2)
{
    u8 value;

    if ((*(u32*)(DAT_007ce3ec + 0xc) & 0x200000) != 0)
    {
        value = *(u8*)(param_1 + 0xa2);
        if (value == 1 && value == *(u8*)(param_2 + 0xa2))
        {
            return 0;
        }
    }
    return 1;
}

// FUN_002FDD40


u8 FUN_002fdd40(BtlUnit* first, BtlUnit* second)
{
    if ((*(u32*)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
    {
        return 0;
    }
    if (first->genus == UNIT_GENUS_EC)
    {
        return 0;
    }
    if (first == second)
    {
        return 0;
    }
    return first->genus == second->genus;
}

// FUN_002FDDB0


void FUN_002fddb0(BtlUnit* unit, RwV3d* position)
{
    position->x = (f32)(unit->unk_94 * 25 - 0x6d6);
    position->y = unit->pos.y;
    position->z = (f32)(unit->unk_96 * 25 - 0x6d6);
    position->z = unit->sphereRadius * unit->scale + 200.0f + position->z;
}

// FUN_002FDE40
u32 FUN_002fde40(BtlAction* action, f32* position)
{
    u16 encounterId;

    if ((*(u32*)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
    {
        return 0;
    }
    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1a7:
        return func_002eee20(action, position);
    case 0x1aa:
        return func_002f1b60(action, position);
    default:
        return 0;
    }
}

// FUN_002FDED0


code FUN_002fded0(s16 param_1)
{
    code result;
    code caseResult;
    u16 encounterId;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1b4:
        /* Source case order is intentional: MWCC emits the retail reverse order. */
        switch (param_1)
        {
        case 0x125:
        case 0x127:
        case 0x128:
        case 0x126:
            *(s32*)(DAT_007ce3ec + 0xb5c) = param_1;
            break;
        default:
            *(s32*)(DAT_007ce3ec + 0xb5c) = -1;
            break;
        }
        switch (param_1)
        {
        case 0x125:
        case 0x127:
        case 0x128:
            caseResult = (code)func_002f6bc0;
            break;
        default:
            caseResult = 0;
            break;
        }
        result = caseResult;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002FDFA0


u8 FUN_002fdfa0(void)
{
    u16 encounterId;

    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
        case 0x1b4:
            return 0;
        default:
            return 1;
    }
}

// FUN_002FDFE0


u32 FUN_002fdfe0(int param_1)
{
    BtlCamera* camera;
    BtlAction* action;
    BtlAction* targetAction;
    u16 encounterId;

    camera = (BtlCamera*)(uintptr_t)param_1;
    encounterId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1b4:
        action = camera->action;
        targetAction = action->target.targetedActions[0];
        if (targetAction != NULL &&
            action->target.targetedCount == 1 &&
            FUN_002d6370((s16)action->target.specificId) == 1 &&
            FUN_003088b0(camera->action->target.specificId) == 0 &&
            targetAction->unit->genus == UNIT_GENUS_EC &&
            targetAction->unit->charId == 0xf1)
            return 1;
        break;
    default:
        break;
    }
    return 0;
}



































// FUN_002FE0B0 NONMATCHING
void FUN_002fe0b0(float param_1, u8* param_2, u64 param_3, u64 param_4,
                  u64 param_5)
{
    u8* camera;
    void* viewport;
    void (**setState)(...);
    u8 padding[0x10];
    u8 vertices[4][0x40];
    f32 scaleX;
    f32 scaleY;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    f32 recipZ;
    u32 value;

    camera = (u8*)kwlnGetMainCamera();
    viewport = FUN_004e3630();
    setState = &DAT_00960090;
    scaleX = 640.0f / (f32)*(s32*)((u8*)viewport + 0xc);
    scaleY = 448.0f / (f32)*(s32*)((u8*)viewport + 0x10);

    left = 0.0f;
    top = 0.0f;
    right = 640.0f;
    bottom = 448.0f;
    if (param_1 != 0.0f)
    {
        left = param_1 * -320.0f + DAT_007caf5c;
        top = param_1 * -224.0f + DAT_007caf60;
        right = param_1 * 320.0f + DAT_007caf5c;
        bottom = param_1 * 224.0f + DAT_007caf60;
    }


    (*setState)(7, 2);
    (*setState)(0x14, 1);
    (*setState)(0xe, 0);
    (*setState)(6, 0);
    (*setState)(8, 0);
    (*setState)(9, param_5);
    (*setState)(0xc, 1);
    (*setState)(1, viewport);
    FUN_004d7f60(2, param_3);
    FUN_004d7f60(3, param_4);
    recipZ = 1.0f / *(f32*)(camera + 0x84);

    *(f32*)(vertices[0] + 0x00) = left;
    *(f32*)(vertices[0] + 0x04) = top;
    *(f32*)(vertices[0] + 0x08) = DAT_0096008c;
    value = param_2[0]; *(f32*)(vertices[0] + 0x20) = (f32)value;
    value = param_2[1]; *(f32*)(vertices[0] + 0x24) = (f32)value;
    value = param_2[2]; *(f32*)(vertices[0] + 0x28) = (f32)value;
    value = param_2[3]; *(f32*)(vertices[0] + 0x2c) = (f32)value;
    *(f32*)(vertices[0] + 0x10) = 0.0f;
    *(f32*)(vertices[0] + 0x14) = 0.0f;
    *(f32*)(vertices[0] + 0x18) = recipZ;

    *(f32*)(vertices[1] + 0x00) = left;
    *(f32*)(vertices[1] + 0x04) = bottom;
    *(f32*)(vertices[1] + 0x08) = DAT_0096008c;
    value = param_2[0]; *(f32*)(vertices[1] + 0x20) = (f32)value;
    value = param_2[1]; *(f32*)(vertices[1] + 0x24) = (f32)value;
    value = param_2[2]; *(f32*)(vertices[1] + 0x28) = (f32)value;
    value = param_2[3]; *(f32*)(vertices[1] + 0x2c) = (f32)value;
    *(f32*)(vertices[1] + 0x10) = 0.0f;
    *(f32*)(vertices[1] + 0x14) = scaleY;
    *(f32*)(vertices[1] + 0x18) = recipZ;

    *(f32*)(vertices[2] + 0x00) = right;
    *(f32*)(vertices[2] + 0x04) = bottom;
    *(f32*)(vertices[2] + 0x08) = DAT_0096008c;
    value = param_2[0]; *(f32*)(vertices[2] + 0x20) = (f32)value;
    value = param_2[1]; *(f32*)(vertices[2] + 0x24) = (f32)value;
    value = param_2[2]; *(f32*)(vertices[2] + 0x28) = (f32)value;
    value = param_2[3]; *(f32*)(vertices[2] + 0x2c) = (f32)value;
    *(f32*)(vertices[2] + 0x10) = scaleX;
    *(f32*)(vertices[2] + 0x14) = 0.0f;
    *(f32*)(vertices[2] + 0x18) = recipZ;

    *(f32*)(vertices[3] + 0x00) = right;
    *(f32*)(vertices[3] + 0x04) = top;
    *(f32*)(vertices[3] + 0x08) = DAT_0096008c;
    value = param_2[0]; *(f32*)(vertices[3] + 0x20) = (f32)value;
    value = param_2[1]; *(f32*)(vertices[3] + 0x24) = (f32)value;
    value = param_2[2]; *(f32*)(vertices[3] + 0x28) = (f32)value;
    value = param_2[3]; *(f32*)(vertices[3] + 0x2c) = (f32)value;
    *(f32*)(vertices[3] + 0x10) = scaleX;
    *(f32*)(vertices[3] + 0x14) = scaleY;
    *(f32*)(vertices[3] + 0x18) = recipZ;

    (*DAT_009600a0)(4, vertices, 4);
    (*setState)(1, 0);
}






























// FUN_002FE780 NONMATCHING
void FUN_002fe780(float param_1,u8 *param_2,u8 *param_3,u64 param_4,u64 param_5)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float afStack_a80 [6];

  float afStack_a68 [4];

  float fStack_a58;

  float fStack_a54;

  float fStack_a40;

  float fStack_a3c;

  float fStack_a38;

  

  iVar2 = FUN_00198590();

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(0x14,1);

  (*DAT_00960090)(0xe,0);

  (*DAT_00960090)(6,0);

  (*DAT_00960090)(8,0);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(1,0);

  FUN_004d7f60(2,param_4);

  FUN_004d7f60(3,param_5);

  fVar7 = 1.0 / *(float *)(iVar2 + 0x84);

  fVar8 = 0.0;

  afStack_a80[0] = 320.0;

  afStack_a80[1] = 224.0;

  afStack_a80[2] = (float)(uintptr_t)DAT_0096008c;

  afStack_a68[2] = (float)*param_2;

  afStack_a68[3] = (float)param_2[1];

  fStack_a58 = (float)param_2[2];

  fStack_a54 = (float)param_2[3];

  uVar3 = 1;

  fVar6 = (float)(uintptr_t)DAT_0096008c;

  afStack_a68[0] = fVar7;

  for (uVar1 = 0; uVar1 < 0x28; uVar1 = uVar1 + 1) {

    fVar4 = (float)FUN_0052e6d8(fVar8);

    fVar5 = (float)FUN_0052e878(fVar8);

    afStack_a80[uVar3 * 0x10] = param_1 * 390.60977 * fVar4 + 320.0;

    afStack_a80[uVar3 * 0x10 + 1] = param_1 * 390.60977 * fVar5 + 224.0;

    afStack_a80[uVar3 * 0x10 + 2] = fVar6;

    afStack_a68[uVar3 * 0x10] = fVar7;

    afStack_a68[uVar3 * 0x10 + 2] = (float)*param_3;

    afStack_a68[uVar3 * 0x10 + 3] = (float)param_3[1];

    afStack_a68[uVar3 * 0x10 + 4] = (float)param_3[2];

    afStack_a68[uVar3 * 0x10 + 5] = (float)param_3[3];

    uVar3 = uVar3 + 1 & 0xffff;

    fVar8 = fVar8 + DAT_007caf58;

  }

  afStack_a80[uVar3 * 0x10] = fStack_a40;

  afStack_a80[uVar3 * 0x10 + 1] = fStack_a3c;

  afStack_a80[uVar3 * 0x10 + 2] = fStack_a38;

  afStack_a80[uVar3 * 0x10 + 2] = fVar6;

  afStack_a68[uVar3 * 0x10] = fVar7;

  afStack_a68[uVar3 * 0x10 + 2] = (float)*param_3;

  afStack_a68[uVar3 * 0x10 + 3] = (float)param_3[1];

  afStack_a68[uVar3 * 0x10 + 4] = (float)param_3[2];

  afStack_a68[uVar3 * 0x10 + 5] = (float)param_3[3];

  (*DAT_009600a0)(5,afStack_a80,0x2a);

  return;

}

// FUN_002FED10 NONMATCHING
u32 FUN_002fed10(int param_1)
{
    struct
    {
        u32 saved[9];
        u8 colors[12];
    } local;
    u32 i;
    u32 result;
    u16* timer;
    u16* counter;
    char* state;
    float progress;
    float value;
    float fade;

    result = 0;
    for (i = 0; i < 7; i++)
    {
        (*DAT_00960094)(DAT_0069aa50[i], &local.saved[i]);
    }

    state = *(char**)((u8*)param_1 + 0x3c);
    if (*state == 3)
    {
        if (FUN_00108710() != 0)
        {
            FUN_001085c0();
            *(u8*)&DAT_007ce508 = 0;
            result = 0xffffffff;
        }
        goto fd10_restore;
    }

    if (*state == 1)
    {
        timer = (u16*)&DAT_007ce50c;
        counter = (u16*)&DAT_007ce50a;
        if (*timer == 0)
        {
            *counter = *counter + 1;
            progress = (float)(s32)*counter / 20.0f;

            (*DAT_00960090)(7, 2);
            (*DAT_00960090)(0x14, 1);
            (*DAT_00960090)(0xe, 0);
            (*DAT_00960090)(6, 0);
            (*DAT_00960090)(8, 0);
            (*DAT_00960090)(0xc, 1);
            (*DAT_00960090)(1, 0);
            FUN_004d7f60(2, 0x44);
            FUN_004d7f60(3, 0x31801);
            FUN_003294d0();

            local.colors[0] = 0xff;
            local.colors[1] = 0xff;
            local.colors[2] = 0xff;
            value = 1.0f - progress * progress * progress * progress * progress * progress;
            value *= 255.0f;
            if (value < 2147483600.0f)
                local.colors[3] = (u8)(s32)value;
            else
                local.colors[3] = (u8)(s32)(value - 2147483600.0f);
            FUN_00358460(local.colors, 0);

            local.colors[4] = 0xff;
            local.colors[5] = 0xff;
            local.colors[6] = 0xff;
            value = (1.0f - progress * progress) * 160.0f;
            if (value < 2147483600.0f)
                local.colors[7] = (u8)(s32)value;
            else
                local.colors[7] = (u8)(s32)(value - 2147483600.0f);

            local.colors[8] = 0xff;
            local.colors[9] = 0xff;
            local.colors[10] = 0xff;
            local.colors[11] = local.colors[3];
            FUN_00329550();

            if (*counter > 0x13)
                *state = 3;
            goto fd10_restore;
        }
        *timer = *timer - 1;
    }

    local.colors[0] = 0xff;
    local.colors[1] = 0xff;
    local.colors[2] = 0xff;

    if (*(s16*)(state + 6) == 1)
        local.colors[3] = 0x10;
    else
        local.colors[3] = 0x18;

    if (*state == 2)
    {
        (*DAT_00960090)(7, 2);
        (*DAT_00960090)(0x14, 1);
        (*DAT_00960090)(0xe, 0);
        (*DAT_00960090)(6, 0);
        (*DAT_00960090)(8, 0);
        (*DAT_00960090)(0xc, 1);
        (*DAT_00960090)(1, 0);
        FUN_004d7f60(2, 0x44);
        FUN_004d7f60(3, 0x31801);
        FUN_002fe0b0(1.0f, (u8*)&DAT_007cc970, 0x44, 0x31801, 1);

        fade = (*(s16*)(state + 6) == 1) ? DAT_007ca4e4 : DAT_007ca564;
        local.colors[0] = 0xff;
        local.colors[1] = 0xff;
        local.colors[2] = 0xff;
        local.colors[3] = (*(s16*)(state + 6) == 1) ? 0x10 : 0x18;
        FUN_002fe0b0(fade, local.colors, 0x44, 0x31801, 2);
        local.colors[3] = 5;
        FUN_002fe0b0(fade, local.colors, 0x48, 0x31801, 2);
        goto fd10_restore;
    }

fd10_restore:
    for (i = 0; i < 7; i++)
    {
        (*DAT_00960090)(DAT_0069aa50[i], local.saved[i]);
    }
    (*DAT_00960090)(1, 0);
    FUN_004d7f60(2, 0x44);
    FUN_004d7f60(3, 0x717fb);
    return result;
}
