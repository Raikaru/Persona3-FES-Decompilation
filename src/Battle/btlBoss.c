#include "Battle/btlBoss.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Battle/btlVoice.h"
#include "Battle/btlCamera.h"
#include "Kosaka/k_assert.h"
#include "Battle/battle.h"
#include "h_cdvd.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
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
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce3f4;
extern u8* DAT_007ce42c;
extern u8* DAT_007ce4b4;
extern u32 DAT_007ce508;
extern u32 DAT_007ce50a;
extern u32 DAT_007ce50c;
extern u32 DAT_007ce4d0;
extern u32 DAT_0069aa50[];
extern code DAT_0096008c;
extern code DAT_00960090;
extern code DAT_00960094;
extern code DAT_009600a0;

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

// FUN_002f88c0
u32 func_002f88c0()
{
    __asm__ volatile (
      ".set noreorder ;"
      ".word 0x27BDFFF0 ;"
      ".word 0xFFBF0000 ;"
      ".word 0x8F84B6FC ;"
      ".word 0x8C820BBC ;"
      ".word 0x94430008 ;"
      ".word 0x240201A8 ;"
      ".word 0x1062004D ;"
      ".word 0x00000000 ;"
      ".word 0x240201A6 ;"
      ".word 0x10620044 ;"
      ".word 0x00000000 ;"
      ".word 0x240201A4 ;"
      ".word 0x1062001E ;"
      ".word 0x00000000 ;"
      ".word 0x240201A0 ;"
      ".word 0x10620003 ;"
      ".word 0x00000000 ;"
      ".word 0x10000047 ;"
      ".word 0x00000000 ;"
      ".word 0x8C860158 ;"
      ".word 0x24040114 ;"
      ".word 0x24030113 ;"
      ".word 0x24020100 ;"
      ".word 0x1000000E ;"
      ".word 0x00000000 ;"
      ".word 0x94C500A4 ;"
      ".word 0x10A40007 ;"
      ".word 0x00000000 ;"
      ".word 0x10A30005 ;"
      ".word 0x00000000 ;"
      ".word 0x10A20006 ;"
      ".word 0x00000000 ;"
      ".word 0x10000004 ;"
      ".word 0x00000000 ;"
      ".word 0x64020001 ;"
      ".word 0x10000005 ;"
      ".word 0x00000000 ;"
      ".word 0x8CC60A34 ;"
      ".word 0x14C0FFF2 ;"
      ".word 0x00000000 ;"
      ".word 0x0000102D ;"
      ".word 0x10000030 ;"
      ".word 0x00000000 ;"
      ".word 0x8C860158 ;"
      ".word 0x24030115 ;"
      ".word 0x24040105 ;"
      ".word 0x24050106 ;"
      ".word 0x10000019 ;"
      ".word 0x00000000 ;"
      ".word 0x94C200A4 ;"
      ".word 0x1045000E ;"
      ".word 0x00000000 ;"
      ".word 0x1044000C ;"
      ".word 0x00000000 ;"
      ".word 0x10430003 ;"
      ".word 0x00000000 ;"
      ".word 0x1000000F ;"
      ".word 0x00000000 ;"
      ".word 0x8CC2009C ;"
      ".word 0x30420008 ;"
      ".word 0x1040000B ;"
      ".word 0x00000000 ;"
      ".word 0x0000102D ;"
      ".word 0x1000000C ;"
      ".word 0x00000000 ;"
      ".word 0x8CC2009C ;"
      ".word 0x30420008 ;"
      ".word 0x10400004 ;"
      ".word 0x00000000 ;"
      ".word 0x64020001 ;"
      ".word 0x10000005 ;"
      ".word 0x00000000 ;"
      ".word 0x8CC60A34 ;"
      ".word 0x14C0FFE7 ;"
      ".word 0x00000000 ;"
      ".word 0x0000102D ;"
      ".word 0x1000000D ;"
      ".word 0x00000000 ;"
      ".word 0x0C0BB2B0 ;"
      ".word 0x00000000 ;"
      ".word 0x38420001 ;"
      ".word 0x0002102B ;"
      ".word 0x10000007 ;"
      ".word 0x00000000 ;"
      ".word 0x8C820B54 ;"
      ".word 0x38420001 ;"
      ".word 0x2C420001 ;"
      ".word 0x10000002 ;"
      ".word 0x00000000 ;"
      ".word 0x0000102D ;"
      ".word 0xDFBF0000 ;"
      ".word 0x27BD0010 ;"
      ".set reorder");
}

// FUN_002f8a40
u32 func_002f8a40(BtlUnit* unit)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x8F82B6FC ; .word 0x8C420BBC ; .word 0x94420008 ; .word 0x240301B4 ; .word 0x10430109 ; .word 0x00000000 ; .word 0x240301B3 ; .word 0x10430103 ;\n"
      ".word 0x00000000 ; .word 0x240301B2 ; .word 0x10430100 ; .word 0x00000000 ; .word 0x240301B1 ; .word 0x104300FD ; .word 0x00000000 ; .word 0x240301B0 ;\n"
      ".word 0x104300FA ; .word 0x00000000 ; .word 0x240301AF ; .word 0x104300F7 ; .word 0x00000000 ; .word 0x240301AE ; .word 0x104300F1 ; .word 0x00000000 ;\n"
      ".word 0x240301AD ; .word 0x104300DC ; .word 0x00000000 ; .word 0x240301AC ; .word 0x104300D4 ; .word 0x00000000 ; .word 0x240301AB ; .word 0x104300CE ;\n"
      ".word 0x00000000 ; .word 0x240301AA ; .word 0x104300C8 ; .word 0x00000000 ; .word 0x240301A9 ; .word 0x104300C2 ; .word 0x00000000 ; .word 0x240301A8 ;\n"
      ".word 0x104300AD ; .word 0x00000000 ; .word 0x240301A7 ; .word 0x104300A7 ; .word 0x00000000 ; .word 0x240301A6 ; .word 0x10430092 ; .word 0x00000000 ;\n"
      ".word 0x240301A5 ; .word 0x1043007D ; .word 0x00000000 ; .word 0x240301A4 ; .word 0x10430061 ; .word 0x00000000 ; .word 0x240301A3 ; .word 0x1043004C ;\n"
      ".word 0x00000000 ; .word 0x240301A2 ; .word 0x10430037 ; .word 0x00000000 ; .word 0x240301A1 ; .word 0x1043001E ; .word 0x00000000 ; .word 0x240301A0 ;\n"
      ".word 0x10430009 ; .word 0x00000000 ; .word 0x240301C8 ; .word 0x10430003 ; .word 0x00000000 ; .word 0x100000CD ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".word 0x100000CB ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ;\n"
      ".word 0x00000000 ; .word 0x948400A4 ; .word 0x24030100 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x0000102D ; .word 0x100000B9 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000000E ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020102 ; .word 0x10620006 ; .word 0x00000000 ; .word 0x24020101 ;\n"
      ".word 0x10620003 ; .word 0x00000000 ; .word 0x10000004 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".word 0x100000A3 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ;\n"
      ".word 0x00000000 ; .word 0x948400A4 ; .word 0x24030103 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x0000102D ; .word 0x10000091 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ; .word 0x948400A4 ; .word 0x24030104 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000003 ;\n"
      ".word 0x00000000 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000007F ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ;\n"
      ".word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000011 ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020106 ; .word 0x10620009 ;\n"
      ".word 0x00000000 ; .word 0x24020105 ; .word 0x10620006 ; .word 0x00000000 ; .word 0x24020115 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000004 ;\n"
      ".word 0x00000000 ; .word 0x24020001 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000066 ; .word 0x00000000 ; .word 0x908300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ; .word 0x948400A4 ; .word 0x24030107 ;\n"
      ".word 0x10830003 ; .word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000054 ;\n"
      ".word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ;\n"
      ".word 0x948400A4 ; .word 0x2403010A ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x10000042 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000003F ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ;\n"
      ".word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ; .word 0x948400A4 ; .word 0x2403010D ; .word 0x10830003 ;\n"
      ".word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000002D ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000002A ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000027 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000024 ;\n"
      ".word 0x00000000 ; .word 0x908200A2 ; .word 0x38420001 ; .word 0x2C420001 ; .word 0x1000001F ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ;\n"
      ".word 0x10620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ; .word 0x948400A4 ; .word 0x24030112 ; .word 0x10830003 ;\n"
      ".word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000000D ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000000A ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000007 ; .word 0x00000000 ; .word 0x908200A2 ; .word 0x38420001 ;\n"
      ".word 0x2C420001 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".set reorder");
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

// FUN_002f8fd0
s16 func_002f8fd0(BtlUnit* unit, s16 id)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFF0 ; .word 0xFFBF0000 ; .word 0x8F86B6FC ; .word 0x8CC20BBC ; .word 0x94430008 ; .word 0x240201B4 ; .word 0x106200EC ; .word 0x00000000 ;\n"
      ".word 0x240201A8 ; .word 0x106200C7 ; .word 0x00000000 ; .word 0x240201A6 ; .word 0x10620090 ; .word 0x00000000 ; .word 0x240201A5 ; .word 0x1062006B ;\n"
      ".word 0x00000000 ; .word 0x240201A3 ; .word 0x1062004C ; .word 0x00000000 ; .word 0x240201A2 ; .word 0x10620029 ; .word 0x00000000 ; .word 0x240201A1 ;\n"
      ".word 0x10620003 ; .word 0x00000000 ; .word 0x10000101 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ;\n"
      ".word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x10000018 ; .word 0x00000000 ; .word 0x00051C3C ; .word 0x00031C3F ; .word 0x24020170 ; .word 0x10620005 ;\n"
      ".word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x1000000F ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020102 ; .word 0x10620006 ;\n"
      ".word 0x00000000 ; .word 0x24020101 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000004 ; .word 0x00000000 ; .word 0x64020017 ; .word 0x10000003 ;\n"
      ".word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000120 ; .word 0x00000000 ; .word 0x908300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x10000015 ; .word 0x00000000 ; .word 0x00051C3C ;\n"
      ".word 0x00031C3F ; .word 0x24020163 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x1000000C ; .word 0x00000000 ;\n"
      ".word 0x948300A4 ; .word 0x24020103 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000004 ; .word 0x00000000 ; .word 0x64020017 ; .word 0x10000003 ;\n"
      ".word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000100 ; .word 0x00000000 ; .word 0x908300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x948300A4 ;\n"
      ".word 0x24020104 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000009 ; .word 0x00000000 ; .word 0x00A0202D ; .word 0x0C0B58DC ; .word 0x00000000 ;\n"
      ".word 0x10400004 ; .word 0x00000000 ; .word 0x64020018 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x0002143C ;\n"
      ".word 0x0002143F ; .word 0x100000E4 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ;\n"
      ".word 0x3042FFFF ; .word 0x10000017 ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020107 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000F ;\n"
      ".word 0x00000000 ; .word 0x00051C3C ; .word 0x00031C3F ; .word 0x2402016B ; .word 0x14620004 ; .word 0x00000000 ; .word 0x64020017 ; .word 0x10000009 ;\n"
      ".word 0x00000000 ; .word 0x2402016C ; .word 0x14620004 ; .word 0x00000000 ; .word 0x64020019 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3402FFFF ;\n"
      ".word 0x3042FFFF ; .word 0x0002143C ; .word 0x0002143F ; .word 0x100000C2 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620005 ;\n"
      ".word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x10000029 ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x2402010A ; .word 0x14620023 ;\n"
      ".word 0x00000000 ; .word 0x00051C3C ; .word 0x00031C3F ; .word 0x24020090 ; .word 0x1062001B ; .word 0x00000000 ; .word 0x2402008E ; .word 0x10620018 ;\n"
      ".word 0x00000000 ; .word 0x2402008D ; .word 0x10620015 ; .word 0x00000000 ; .word 0x24020083 ; .word 0x10620012 ; .word 0x00000000 ; .word 0x24020080 ;\n"
      ".word 0x1062000F ; .word 0x00000000 ; .word 0x2402007F ; .word 0x1062000C ; .word 0x00000000 ; .word 0x24020077 ; .word 0x10620009 ; .word 0x00000000 ;\n"
      ".word 0x24020075 ; .word 0x10620006 ; .word 0x00000000 ; .word 0x24020073 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000004 ; .word 0x00000000 ;\n"
      ".word 0x64020018 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000008E ;\n"
      ".word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x10000017 ;\n"
      ".word 0x00000000 ; .word 0x948300A4 ; .word 0x2402010D ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000F ; .word 0x00000000 ; .word 0x00051C3C ;\n"
      ".word 0x00031C3F ; .word 0x24020134 ; .word 0x1462000A ; .word 0x00000000 ; .word 0x8CC20B54 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x64020007 ;\n"
      ".word 0x10000006 ; .word 0x00000000 ; .word 0x64020015 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ; .word 0x0002143C ;\n"
      ".word 0x0002143F ; .word 0x1000006C ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ;\n"
      ".word 0x3042FFFF ; .word 0x1000001E ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x240200F1 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3402FFFF ;\n"
      ".word 0x3042FFFF ; .word 0x10000016 ; .word 0x00000000 ; .word 0x00051C3C ; .word 0x00031C3F ; .word 0x24020126 ; .word 0x1062000C ; .word 0x00000000 ;\n"
      ".word 0x24020128 ; .word 0x10620009 ; .word 0x00000000 ; .word 0x24020127 ; .word 0x10620006 ; .word 0x00000000 ; .word 0x24020125 ; .word 0x10620003 ;\n"
      ".word 0x00000000 ; .word 0x10000004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3402FFFF ; .word 0x3042FFFF ;\n"
      ".word 0x0002143C ; .word 0x0002143F ; .word 0x10000043 ; .word 0x00000000 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x1462003E ; .word 0x00000000 ;\n"
      ".word 0x948600A4 ; .word 0x24C3FF6B ; .word 0x2C610008 ; .word 0x10200039 ; .word 0x00000000 ; .word 0x3C04007C ; .word 0x24848C90 ; .word 0x00031880 ;\n"
      ".word 0x00641821 ; .word 0x8C630000 ; .word 0x00600008 ; .word 0x00000000 ; .word 0x24C3FF6B ; .word 0x3063FFFF ; .word 0x0000482D ; .word 0x000320C0 ;\n"
      ".word 0x8F83B7B4 ; .word 0x00644021 ; .word 0x00053C3C ; .word 0x00073C3F ; .word 0x24060003 ; .word 0x24050002 ; .word 0x1000001F ; .word 0x00000000 ;\n"
      ".word 0x3123FFFF ; .word 0x00031840 ; .word 0x01031821 ; .word 0x94630000 ; .word 0x14E30017 ; .word 0x00000000 ; .word 0x10860012 ; .word 0x00000000 ;\n"
      ".word 0x1085000D ; .word 0x00000000 ; .word 0x10820008 ; .word 0x00000000 ; .word 0x10800003 ; .word 0x00000000 ; .word 0x1000000D ; .word 0x00000000 ;\n"
      ".word 0x24020004 ; .word 0x10000014 ; .word 0x00000000 ; .word 0x24020007 ; .word 0x10000011 ; .word 0x00000000 ; .word 0x24020017 ; .word 0x1000000E ;\n"
      ".word 0x00000000 ; .word 0x24020018 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x25230001 ; .word 0x3069FFFF ; .word 0x3124FFFF ; .word 0x28830004 ;\n"
      ".word 0x1460FFDF ; .word 0x00000000 ; .word 0x24020007 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0xDFBF0000 ; .word 0x27BD0010 ;\n"
      ".set reorder");
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

// FUN_002f9c10
u32 func_002f9c10(BtlAction* action)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFF0 ; .word 0xFFBF0000 ; .word 0x8F82B6FC ; .word 0x8C420BBC ; .word 0x94420008 ; .word 0x2442FE60 ; .word 0x2C410015 ; .word 0x1020017F ;\n"
      ".word 0x00000000 ; .word 0x3C03007C ; .word 0x24638CB0 ; .word 0x00021080 ; .word 0x00431021 ; .word 0x8C420000 ; .word 0x00400008 ; .word 0x00000000 ;\n"
      ".word 0x9482001A ; .word 0x30420001 ; .word 0x10400013 ; .word 0x00000000 ; .word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x1462000E ;\n"
      ".word 0x00000000 ; .word 0x948300A4 ; .word 0x24020100 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C82009C ;\n"
      ".word 0x34420100 ; .word 0xAC82009C ; .word 0x34420040 ; .word 0xAC82009C ; .word 0x34420400 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x10000160 ;\n"
      ".word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x10400016 ; .word 0x00000000 ; .word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ;\n"
      ".word 0x14620011 ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020102 ; .word 0x10620006 ; .word 0x00000000 ; .word 0x24020101 ; .word 0x10620003 ;\n"
      ".word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C830A2C ; .word 0x94620000 ; .word 0x34420040 ; .word 0xA4620000 ; .word 0x8C82009C ;\n"
      ".word 0x34420100 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x10000144 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x10400013 ;\n"
      ".word 0x00000000 ; .word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x1462000E ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020103 ;\n"
      ".word 0x10620003 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C82009C ; .word 0x34420100 ; .word 0xAC82009C ; .word 0x34420040 ;\n"
      ".word 0xAC82009C ; .word 0x34420400 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x1000012B ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ;\n"
      ".word 0x10400013 ; .word 0x00000000 ; .word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x1462000E ; .word 0x00000000 ; .word 0x948300A4 ;\n"
      ".word 0x24020104 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C82009C ; .word 0x34420100 ; .word 0xAC82009C ;\n"
      ".word 0x34420040 ; .word 0xAC82009C ; .word 0x34420400 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x10000112 ; .word 0x00000000 ; .word 0x0C0BA9E0 ;\n"
      ".word 0x00000000 ; .word 0x24020001 ; .word 0x1000010D ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x10400013 ; .word 0x00000000 ;\n"
      ".word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x1462000E ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x24020107 ; .word 0x10620003 ;\n"
      ".word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C82009C ; .word 0x34420100 ; .word 0xAC82009C ; .word 0x34420040 ; .word 0xAC82009C ;\n"
      ".word 0x34420400 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x100000F4 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x10400016 ;\n"
      ".word 0x00000000 ; .word 0x8C840030 ; .word 0x908300A2 ; .word 0x24020001 ; .word 0x14620011 ; .word 0x00000000 ; .word 0x948300A4 ; .word 0x2402010A ;\n"
      ".word 0x10620006 ; .word 0x00000000 ; .word 0x24020109 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8C830A2C ;\n"
      ".word 0x94620000 ; .word 0x34420040 ; .word 0xA4620000 ; .word 0x8C82009C ; .word 0x34420100 ; .word 0xAC82009C ; .word 0x24020001 ; .word 0x100000D8 ;\n"
      ".word 0x00000000 ; .word 0x0C0BBADC ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100000D3 ; .word 0x00000000 ; .word 0x9486001A ; .word 0x30C20001 ;\n"
      ".word 0x10400027 ; .word 0x00000000 ; .word 0x8C850030 ; .word 0x90A300A2 ; .word 0x24020001 ; .word 0x14620022 ; .word 0x00000000 ; .word 0x94A300A4 ;\n"
      ".word 0x24020118 ; .word 0x10620017 ; .word 0x00000000 ; .word 0x24020117 ; .word 0x10620014 ; .word 0x00000000 ; .word 0x24020116 ; .word 0x10620011 ;\n"
      ".word 0x00000000 ; .word 0x2402010D ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000013 ; .word 0x00000000 ; .word 0x30C2FFF7 ; .word 0xA482001A ;\n"
      ".word 0x8CA2009C ; .word 0x34420100 ; .word 0xACA2009C ; .word 0x34420040 ; .word 0xACA2009C ; .word 0x34420400 ; .word 0xACA2009C ; .word 0x10000008 ;\n"
      ".word 0x00000000 ; .word 0x8CA30A2C ; .word 0x94620000 ; .word 0x34420040 ; .word 0xA4620000 ; .word 0x8CA2009C ; .word 0x34420100 ; .word 0xACA2009C ;\n"
      ".word 0x24020001 ; .word 0x100000A6 ; .word 0x00000000 ; .word 0x9485001A ; .word 0x30A20001 ; .word 0x104000A1 ; .word 0x00000000 ; .word 0x8C860030 ;\n"
      ".word 0x90C300A2 ; .word 0x24020001 ; .word 0x1462009C ; .word 0x00000000 ; .word 0x94C300A4 ; .word 0x24020108 ; .word 0x10620003 ; .word 0x00000000 ;\n"
      ".word 0x1000000A ; .word 0x00000000 ; .word 0x34A20010 ; .word 0xA482001A ; .word 0x8CC2009C ; .word 0x34420100 ; .word 0xACC2009C ; .word 0x34420040 ;\n"
      ".word 0xACC2009C ; .word 0x34420080 ; .word 0xACC2009C ; .word 0x94C300A4 ; .word 0x24020108 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000087 ;\n"
      ".word 0x00000000 ; .word 0x00C0202D ; .word 0x240500D2 ; .word 0x0C0A23E0 ; .word 0x00000000 ; .word 0x10000081 ; .word 0x00000000 ; .word 0x9485001A ;\n"
      ".word 0x30A20001 ; .word 0x1040007D ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C300A2 ; .word 0x24020001 ; .word 0x14620078 ; .word 0x00000000 ;\n"
      ".word 0x94C300A4 ; .word 0x2402010F ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ; .word 0x34A20010 ; .word 0xA482001A ;\n"
      ".word 0x8CC2009C ; .word 0x34420100 ; .word 0xACC2009C ; .word 0x34420040 ; .word 0xACC2009C ; .word 0x34420080 ; .word 0xACC2009C ; .word 0x94C300A4 ;\n"
      ".word 0x2402010F ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000063 ; .word 0x00000000 ; .word 0x00C0202D ; .word 0x240500D1 ; .word 0x0C0A23E0 ;\n"
      ".word 0x00000000 ; .word 0x1000005D ; .word 0x00000000 ; .word 0x9485001A ; .word 0x30A20001 ; .word 0x10400059 ; .word 0x00000000 ; .word 0x8C860030 ;\n"
      ".word 0x90C300A2 ; .word 0x24020001 ; .word 0x14620054 ; .word 0x00000000 ; .word 0x94C300A4 ; .word 0x24020110 ; .word 0x10620003 ; .word 0x00000000 ;\n"
      ".word 0x1000000A ; .word 0x00000000 ; .word 0x34A20010 ; .word 0xA482001A ; .word 0x8CC2009C ; .word 0x34420100 ; .word 0xACC2009C ; .word 0x34420040 ;\n"
      ".word 0xACC2009C ; .word 0x34420080 ; .word 0xACC2009C ; .word 0x94C300A4 ; .word 0x24020110 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000003F ;\n"
      ".word 0x00000000 ; .word 0x00C0202D ; .word 0x240500D0 ; .word 0x0C0A23E0 ; .word 0x00000000 ; .word 0x10000039 ; .word 0x00000000 ; .word 0x9482001A ;\n"
      ".word 0x30420001 ; .word 0x1040001A ; .word 0x00000000 ; .word 0x8C850030 ; .word 0x90A300A2 ; .word 0x24020001 ; .word 0x14620015 ; .word 0x00000000 ;\n"
      ".word 0x94A300A4 ; .word 0x24020111 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000F ; .word 0x00000000 ; .word 0x8CA2009C ; .word 0x34420100 ;\n"
      ".word 0xACA2009C ; .word 0x34420040 ; .word 0xACA2009C ; .word 0x8CA30A2C ; .word 0x94620000 ; .word 0x34420040 ; .word 0xA4620000 ; .word 0x8CA2009C ;\n"
      ".word 0x34420400 ; .word 0xACA2009C ; .word 0x0C0A68B0 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x1000001A ; .word 0x00000000 ; .word 0x0C0BCD9C ;\n"
      ".word 0x00000000 ; .word 0x24020001 ; .word 0x10000015 ; .word 0x00000000 ; .word 0x0C0BD124 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000010 ;\n"
      ".word 0x00000000 ; .word 0x0C0BD224 ; .word 0x00000000 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x0C0BD300 ; .word 0x00000000 ; .word 0x10000007 ;\n"
      ".word 0x00000000 ; .word 0x0C0BD4CC ; .word 0x00000000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x0C0BD660 ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".word 0xDFBF0000 ; .word 0x27BD0010 ;\n"
      ".set reorder");
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

// FUN_002fa510
void func_002fa510(BtlAction* action, s32 mode)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFE0 ; .word 0xFFBF0010 ; .word 0x7FB00000 ; .word 0x0080802D ; .word 0x8F83B6FC ; .word 0x8C630BBC ; .word 0x94640008 ; .word 0x240301B4 ;\n"
      ".word 0x10830124 ; .word 0x00000000 ; .word 0x240301B3 ; .word 0x108300FD ; .word 0x00000000 ; .word 0x240301B2 ; .word 0x108300FA ; .word 0x00000000 ;\n"
      ".word 0x240301B1 ; .word 0x108300F7 ; .word 0x00000000 ; .word 0x240301AC ; .word 0x108300CC ; .word 0x00000000 ; .word 0x240301A8 ; .word 0x108300A0 ;\n"
      ".word 0x00000000 ; .word 0x240301A7 ; .word 0x1083007C ; .word 0x00000000 ; .word 0x240301A6 ; .word 0x10830057 ; .word 0x00000000 ; .word 0x240301A4 ;\n"
      ".word 0x10830024 ; .word 0x00000000 ; .word 0x240301A1 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000125 ; .word 0x00000000 ; .word 0x9603001A ;\n"
      ".word 0x30630001 ; .word 0x10600121 ; .word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ; .word 0x1483011C ; .word 0x00000000 ;\n"
      ".word 0x94C400A4 ; .word 0x24030102 ; .word 0x10830006 ; .word 0x00000000 ; .word 0x24030101 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000113 ;\n"
      ".word 0x00000000 ; .word 0x24030001 ; .word 0x14A30110 ; .word 0x00000000 ; .word 0x3C04002F ; .word 0x24849C20 ; .word 0x3C05002F ; .word 0x24A59F10 ;\n"
      ".word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x10000107 ; .word 0x00000000 ; .word 0x9603001A ; .word 0x30630001 ; .word 0x10600103 ;\n"
      ".word 0x00000000 ; .word 0x8E040030 ; .word 0x908300A2 ; .word 0x24060001 ; .word 0x146600FE ; .word 0x00000000 ; .word 0x948400A4 ; .word 0x24030106 ;\n"
      ".word 0x10830014 ; .word 0x00000000 ; .word 0x24030105 ; .word 0x10830011 ; .word 0x00000000 ; .word 0x24030115 ; .word 0x10830003 ; .word 0x00000000 ;\n"
      ".word 0x100000F2 ; .word 0x00000000 ; .word 0x14A600F0 ; .word 0x00000000 ; .word 0x3C04002F ; .word 0x2484ABF0 ; .word 0x3C05002F ; .word 0x24A5B250 ;\n"
      ".word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x100000E7 ; .word 0x00000000 ; .word 0x14A000E5 ; .word 0x00000000 ; .word 0x0C0B9094 ;\n"
      ".word 0x00000000 ; .word 0x10400002 ; .word 0x00000000 ; .word 0x0000802D ; .word 0x3C04002F ; .word 0x2484BA50 ; .word 0x3C05002F ; .word 0x24A5BEC0 ;\n"
      ".word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x100000D7 ; .word 0x00000000 ; .word 0x9603001A ; .word 0x30630001 ; .word 0x106000D3 ;\n"
      ".word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ; .word 0x148300CE ; .word 0x00000000 ; .word 0x94C400A4 ; .word 0x2403010A ;\n"
      ".word 0x10830006 ; .word 0x00000000 ; .word 0x24030109 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x100000C5 ; .word 0x00000000 ; .word 0x24030001 ;\n"
      ".word 0x14A300C2 ; .word 0x00000000 ; .word 0x0C0B9094 ; .word 0x00000000 ; .word 0x144000BE ; .word 0x00000000 ; .word 0x3C04002F ; .word 0x2484E640 ;\n"
      ".word 0x3C05002F ; .word 0x24A5EA10 ; .word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x100000B5 ; .word 0x00000000 ; .word 0x9603001A ;\n"
      ".word 0x30630001 ; .word 0x106000B1 ; .word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ; .word 0x148300AC ; .word 0x00000000 ;\n"
      ".word 0x94C400A4 ; .word 0x2403010C ; .word 0x10830006 ; .word 0x00000000 ; .word 0x2403010B ; .word 0x10830003 ; .word 0x00000000 ; .word 0x100000A3 ;\n"
      ".word 0x00000000 ; .word 0x10A000A1 ; .word 0x00000000 ; .word 0x0C0B9094 ; .word 0x00000000 ; .word 0x1440009D ; .word 0x00000000 ; .word 0x3C04002F ;\n"
      ".word 0x2484F000 ; .word 0x3C05002F ; .word 0x24A5F250 ; .word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x10000094 ; .word 0x00000000 ;\n"
      ".word 0x9603001A ; .word 0x30630001 ; .word 0x10600090 ; .word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ; .word 0x1483008B ;\n"
      ".word 0x00000000 ; .word 0x94C400A4 ; .word 0x24030118 ; .word 0x10830009 ; .word 0x00000000 ; .word 0x24030117 ; .word 0x10830006 ; .word 0x00000000 ;\n"
      ".word 0x24030116 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x1000007F ; .word 0x00000000 ; .word 0x24030001 ; .word 0x14A3007C ; .word 0x00000000 ;\n"
      ".word 0x8F84B6FC ; .word 0x94830B50 ; .word 0x00031080 ; .word 0x00441021 ; .word 0xAC500B44 ; .word 0x24630001 ; .word 0x8F82B6FC ; .word 0xA4430B50 ;\n"
      ".word 0x3C04002F ; .word 0x24840EA0 ; .word 0x3C05002F ; .word 0x24A514A0 ; .word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x1000006B ;\n"
      ".word 0x00000000 ; .word 0x9603001A ; .word 0x30630001 ; .word 0x10600067 ; .word 0x00000000 ; .word 0x8E030030 ; .word 0x906400A2 ; .word 0x24030001 ;\n"
      ".word 0x14830062 ; .word 0x00000000 ; .word 0x0C0B9094 ; .word 0x00000000 ; .word 0x1440005E ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x94420B48 ;\n"
      ".word 0x00021880 ; .word 0x3C02006A ; .word 0x2442A1D0 ; .word 0x00431021 ; .word 0x94420000 ; .word 0x1440000A ; .word 0x00000000 ; .word 0x3C04002F ;\n"
      ".word 0x24843320 ; .word 0x3C05002F ; .word 0x24A53520 ; .word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x1000004C ; .word 0x00000000 ;\n"
      ".word 0x3C04002F ; .word 0x24842B90 ; .word 0x3C05002F ; .word 0x24A53190 ; .word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x10000043 ;\n"
      ".word 0x00000000 ; .word 0x9603001A ; .word 0x30630001 ; .word 0x1060003F ; .word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ;\n"
      ".word 0x1483003A ; .word 0x00000000 ; .word 0x94C300A4 ; .word 0x2463FF15 ; .word 0x2C610006 ; .word 0x10200035 ; .word 0x00000000 ; .word 0x3C04007C ;\n"
      ".word 0x24848D10 ; .word 0x00031880 ; .word 0x00641821 ; .word 0x8C630000 ; .word 0x00600008 ; .word 0x00000000 ; .word 0x10A0002C ; .word 0x00000000 ;\n"
      ".word 0x0C0B9094 ; .word 0x00000000 ; .word 0x14400028 ; .word 0x00000000 ; .word 0x3C04002F ; .word 0x24845660 ; .word 0x3C05002F ; .word 0x24A55870 ;\n"
      ".word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0x1000001F ; .word 0x00000000 ; .word 0x9603001A ; .word 0x30630001 ; .word 0x1060001B ;\n"
      ".word 0x00000000 ; .word 0x8E060030 ; .word 0x90C400A2 ; .word 0x24030001 ; .word 0x14830016 ; .word 0x00000000 ; .word 0x94C400A4 ; .word 0x240300F1 ;\n"
      ".word 0x10830003 ; .word 0x00000000 ; .word 0x10000010 ; .word 0x00000000 ; .word 0x10A0000E ; .word 0x00000000 ; .word 0x0C0B9094 ; .word 0x00000000 ;\n"
      ".word 0x1440000A ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0xAC400B4C ; .word 0x3C04002F ; .word 0x24846840 ; .word 0x3C05002F ; .word 0x24A56AB0 ;\n"
      ".word 0x0200302D ; .word 0x0C0B9088 ; .word 0x00000000 ; .word 0xDFBF0010 ; .word 0x7BB00000 ; .word 0x27BD0020 ;\n"
      ".set reorder");
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
// FUN_002faab0
void func_002faab0()
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFE0 ; .word 0xFFBF0010 ; .word 0x7FB00000 ; .word 0x8F85B6FC ; .word 0x8CA30BBC ; .word 0x94640008 ; .word 0x240301B4 ; .word 0x10830043 ;\n"
      ".word 0x00000000 ; .word 0x240301AC ; .word 0x1083002A ; .word 0x00000000 ; .word 0x240301A8 ; .word 0x10830023 ; .word 0x00000000 ; .word 0x240301A5 ;\n"
      ".word 0x1083000A ; .word 0x00000000 ; .word 0x240301A4 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000057 ; .word 0x00000000 ; .word 0x0C0BAA90 ;\n"
      ".word 0x00000000 ; .word 0x10000053 ; .word 0x00000000 ; .word 0x8CA60158 ; .word 0x24050107 ; .word 0x1000000F ; .word 0x00000000 ; .word 0x94C300A4 ;\n"
      ".word 0x10650003 ; .word 0x00000000 ; .word 0x10000009 ; .word 0x00000000 ; .word 0x8CC409F4 ; .word 0x90830388 ; .word 0x34630008 ; .word 0xA0830388 ;\n"
      ".word 0x8F83B6FC ; .word 0xAC600B4C ; .word 0x8CC309F4 ; .word 0xA060041D ; .word 0x8CC60A34 ; .word 0x14C0FFF1 ; .word 0x00000000 ; .word 0x1000003D ;\n"
      ".word 0x00000000 ; .word 0x0C0BBD68 ; .word 0x00000000 ; .word 0x10000039 ; .word 0x00000000 ; .word 0x8CA60158 ; .word 0x24050111 ; .word 0x1000000F ;\n"
      ".word 0x00000000 ; .word 0x94C300A4 ; .word 0x10650003 ; .word 0x00000000 ; .word 0x10000009 ; .word 0x00000000 ; .word 0x8CC409F4 ; .word 0x90830388 ;\n"
      ".word 0x34630008 ; .word 0xA0830388 ; .word 0x8F83B6FC ; .word 0xAC600B50 ; .word 0x8CC309F4 ; .word 0xA060041D ; .word 0x8CC60A34 ; .word 0x14C0FFF1 ;\n"
      ".word 0x00000000 ; .word 0x10000023 ; .word 0x00000000 ; .word 0x8CB00158 ; .word 0x1000001E ; .word 0x00000000 ; .word 0x960400A4 ; .word 0x240300F2 ;\n"
      ".word 0x10830003 ; .word 0x00000000 ; .word 0x10000017 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0B4FF8 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0000282D ; .word 0x0C0A0C70 ; .word 0x00000000 ; .word 0x820709E8 ; .word 0x0200202D ; .word 0x860509E0 ; .word 0x0000302D ; .word 0xC60C09E4 ;\n"
      ".word 0x0C0A0B50 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0A1D44 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x3C050095 ; .word 0x24A57180 ;\n"
      ".word 0x0C09FD94 ; .word 0x00000000 ; .word 0x8E100A34 ; .word 0x1600FFE2 ; .word 0x00000000 ; .word 0xDFBF0010 ; .word 0x7BB00000 ; .word 0x27BD0020 ;\n"
      ".set reorder");
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

// FUN_002facc0
u32 func_002facc0()
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFA0 ; .word 0xFFBF0010 ; .word 0x7FB00000 ; .word 0x8F82B6FC ; .word 0x8C420BBC ; .word 0x94420008 ; .word 0x240301B4 ; .word 0x10430242 ;\n"
      ".word 0x00000000 ; .word 0x240301B3 ; .word 0x1043021E ; .word 0x00000000 ; .word 0x240301B2 ; .word 0x1043021B ; .word 0x00000000 ; .word 0x240301B1 ;\n"
      ".word 0x10430218 ; .word 0x00000000 ; .word 0x240301B0 ; .word 0x104301F4 ; .word 0x00000000 ; .word 0x240301AF ; .word 0x104301D0 ; .word 0x00000000 ;\n"
      ".word 0x240301AE ; .word 0x104301AC ; .word 0x00000000 ; .word 0x240301AD ; .word 0x10430188 ; .word 0x00000000 ; .word 0x240301AC ; .word 0x10430164 ;\n"
      ".word 0x00000000 ; .word 0x240301AB ; .word 0x10430141 ; .word 0x00000000 ; .word 0x240301AA ; .word 0x1043011E ; .word 0x00000000 ; .word 0x240301A9 ;\n"
      ".word 0x104300FB ; .word 0x00000000 ; .word 0x240301A8 ; .word 0x104300F3 ; .word 0x00000000 ; .word 0x240301A7 ; .word 0x104300CF ; .word 0x00000000 ;\n"
      ".word 0x240301A6 ; .word 0x104300C7 ; .word 0x00000000 ; .word 0x240301A5 ; .word 0x104300A3 ; .word 0x00000000 ; .word 0x240301A4 ; .word 0x1043007F ;\n"
      ".word 0x00000000 ; .word 0x240301A3 ; .word 0x1043005B ; .word 0x00000000 ; .word 0x240301A2 ; .word 0x10430037 ; .word 0x00000000 ; .word 0x240301A1 ;\n"
      ".word 0x1043002F ; .word 0x00000000 ; .word 0x240301A0 ; .word 0x10430027 ; .word 0x00000000 ; .word 0x240301C8 ; .word 0x10430003 ; .word 0x00000000 ;\n"
      ".word 0x10000222 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ;\n"
      ".word 0x0000282D ; .word 0x27A6005C ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ;\n"
      ".word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ;\n"
      ".word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ;\n"
      ".word 0x24020001 ; .word 0x10000202 ; .word 0x00000000 ; .word 0x0C0BA514 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100001FD ; .word 0x00000000 ;\n"
      ".word 0x0C0BA6B0 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100001F8 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ;\n"
      ".word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60058 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ;\n"
      ".word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ;\n"
      ".word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100001D7 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ;\n"
      ".word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60054 ; .word 0x0C040840 ; .word 0x00000000 ;\n"
      ".word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ;\n"
      ".word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ;\n"
      ".word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100001B6 ; .word 0x00000000 ; .word 0x0000202D ;\n"
      ".word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60050 ; .word 0x0C040840 ;\n"
      ".word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ;\n"
      ".word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ;\n"
      ".word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000195 ; .word 0x00000000 ;\n"
      ".word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A6004C ;\n"
      ".word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ;\n"
      ".word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ;\n"
      ".word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000174 ;\n"
      ".word 0x00000000 ; .word 0x0C0BB1E4 ; .word 0x00000000 ; .word 0x24020001 ; .word 0x1000016F ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ;\n"
      ".word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60048 ; .word 0x0C040840 ; .word 0x00000000 ;\n"
      ".word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ;\n"
      ".word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ;\n"
      ".word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x1000014E ; .word 0x00000000 ; .word 0x0C0BBD9C ;\n"
      ".word 0x00000000 ; .word 0x24020001 ; .word 0x10000149 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ;\n"
      ".word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60044 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ;\n"
      ".word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ;\n"
      ".word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0C0AE40C ; .word 0x00000000 ; .word 0x10000128 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ;\n"
      ".word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60040 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ;\n"
      ".word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ;\n"
      ".word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0C0AE40C ; .word 0x00000000 ; .word 0x10000108 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ;\n"
      ".word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A6003C ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ;\n"
      ".word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ;\n"
      ".word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0C0AE40C ; .word 0x00000000 ; .word 0x100000E8 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ;\n"
      ".word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60038 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ;\n"
      ".word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ;\n"
      ".word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100000C8 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ;\n"
      ".word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60034 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ;\n"
      ".word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ;\n"
      ".word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x100000A7 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ;\n"
      ".word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60030 ; .word 0x0C040840 ; .word 0x00000000 ;\n"
      ".word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ;\n"
      ".word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ;\n"
      ".word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000086 ; .word 0x00000000 ; .word 0x0000202D ;\n"
      ".word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A6002C ; .word 0x0C040840 ;\n"
      ".word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ;\n"
      ".word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ;\n"
      ".word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000065 ; .word 0x00000000 ;\n"
      ".word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ; .word 0x27A60028 ;\n"
      ".word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C420148 ;\n"
      ".word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ; .word 0x0040202D ;\n"
      ".word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10000044 ;\n"
      ".word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ; .word 0x24050001 ;\n"
      ".word 0x27A60024 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ; .word 0x8F82B6FC ;\n"
      ".word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ; .word 0x00000000 ;\n"
      ".word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ; .word 0x24020001 ;\n"
      ".word 0x10000023 ; .word 0x00000000 ; .word 0x0000202D ; .word 0x0C0AE3E4 ; .word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x8C440B14 ;\n"
      ".word 0x24050001 ; .word 0x27A60020 ; .word 0x0C040840 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0040282D ; .word 0x0C0AE434 ; .word 0x00000000 ;\n"
      ".word 0x8F82B6FC ; .word 0x8C420148 ; .word 0x8C450030 ; .word 0x0200202D ; .word 0x00A0302D ; .word 0x0000382D ; .word 0x24080200 ; .word 0x0C0AEBE4 ;\n"
      ".word 0x00000000 ; .word 0x0040202D ; .word 0x24050002 ; .word 0x0C09FB48 ; .word 0x00000000 ; .word 0x0200202D ; .word 0x0C0AE40C ; .word 0x00000000 ;\n"
      ".word 0x24020001 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0xDFBF0010 ; .word 0x7BB00000 ; .word 0x27BD0060 ;\n"
      ".set reorder");
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

// FUN_002fb860
u16 func_002fb860(BtlUnit* unit, u16 index)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFD0 ; .word 0xFFBF0020 ; .word 0x7FB10010 ; .word 0x7FB00000 ; .word 0x0080882D ; .word 0x00A0802D ; .word 0x8F82B6FC ; .word 0x8C430BBC ;\n"
      ".word 0x94650008 ; .word 0x24A3FE60 ; .word 0x2C610015 ; .word 0x102002D9 ; .word 0x00000000 ; .word 0x3C04007C ; .word 0x24848D50 ; .word 0x00031880 ;\n"
      ".word 0x00641821 ; .word 0x8C630000 ; .word 0x00600008 ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x24020100 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ;\n"
      ".word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429BF0 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ;\n"
      ".word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x100002BA ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x24020103 ; .word 0x10620003 ; .word 0x00000000 ;\n"
      ".word 0x1000000A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429C90 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ;\n"
      ".word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x100002A1 ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ;\n"
      ".word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000001D ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x24020102 ; .word 0x1062000F ;\n"
      ".word 0x00000000 ; .word 0x24020101 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000013 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ;\n"
      ".word 0x24429C20 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000000B ; .word 0x00000000 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x24429C3A ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x1000027C ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ;\n"
      ".word 0x1000000F ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x24020104 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000008 ;\n"
      ".word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429CE0 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ;\n"
      ".word 0x10000265 ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000029 ;\n"
      ".word 0x00000000 ; .word 0x962300A4 ; .word 0x24020115 ; .word 0x1062001B ; .word 0x00000000 ; .word 0x24020106 ; .word 0x1062000F ; .word 0x00000000 ;\n"
      ".word 0x24020105 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000001C ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429D30 ;\n"
      ".word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000014 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ;\n"
      ".word 0x24429D4A ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000000B ; .word 0x00000000 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x24429D64 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x10000234 ; .word 0x00000000 ; .word 0x922400A2 ; .word 0x24030001 ; .word 0x10830004 ; .word 0x00000000 ; .word 0x2402FFFF ;\n"
      ".word 0x10000032 ; .word 0x00000000 ; .word 0x962400A4 ; .word 0x24030107 ; .word 0x10830004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000002B ;\n"
      ".word 0x00000000 ; .word 0x3204FFFF ; .word 0x24030011 ; .word 0x10830008 ; .word 0x00000000 ; .word 0x24030003 ; .word 0x10830005 ; .word 0x00000000 ;\n"
      ".word 0x10800003 ; .word 0x00000000 ; .word 0x1000000F ; .word 0x00000000 ; .word 0x240301A5 ; .word 0x14A30004 ; .word 0x00000000 ; .word 0x8C430B44 ;\n"
      ".word 0x10000002 ; .word 0x00000000 ; .word 0x0000182D ; .word 0x10600006 ; .word 0x00000000 ; .word 0x24030001 ; .word 0xAC430B4C ; .word 0x2402000F ;\n"
      ".word 0x10000012 ; .word 0x00000000 ; .word 0x240301A5 ; .word 0x14A30004 ; .word 0x00000000 ; .word 0x8C430B44 ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x0000182D ; .word 0x14600002 ; .word 0x00000000 ; .word 0xAC400B4C ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429DD0 ; .word 0x00431021 ;\n"
      ".word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x100001FA ; .word 0x00000000 ; .word 0x922400A2 ; .word 0x24030001 ; .word 0x10830004 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000004A ; .word 0x00000000 ; .word 0x962400A4 ; .word 0x240300E8 ; .word 0x10830042 ; .word 0x00000000 ;\n"
      ".word 0x240300E7 ; .word 0x1083003F ; .word 0x00000000 ; .word 0x240300E6 ; .word 0x1083003C ; .word 0x00000000 ; .word 0x240300E5 ; .word 0x10830039 ;\n"
      ".word 0x00000000 ; .word 0x240300E4 ; .word 0x10830036 ; .word 0x00000000 ; .word 0x240300E3 ; .word 0x10830033 ; .word 0x00000000 ; .word 0x240300E2 ;\n"
      ".word 0x10830030 ; .word 0x00000000 ; .word 0x2403010A ; .word 0x10830024 ; .word 0x00000000 ; .word 0x24030109 ; .word 0x10830003 ; .word 0x00000000 ;\n"
      ".word 0x1000002B ; .word 0x00000000 ; .word 0x3204FFFF ; .word 0x24030009 ; .word 0x1083000B ; .word 0x00000000 ; .word 0x24030011 ; .word 0x10830008 ;\n"
      ".word 0x00000000 ; .word 0x24030003 ; .word 0x10830005 ; .word 0x00000000 ; .word 0x10800003 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x8C430B50 ; .word 0x24020001 ; .word 0x14620004 ; .word 0x00000000 ; .word 0x24020006 ; .word 0x10000017 ; .word 0x00000000 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x24429E20 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000000E ; .word 0x00000000 ;\n"
      ".word 0x3203FFFF ; .word 0x3C02006A ; .word 0x24429E3A ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000005 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x100001A8 ; .word 0x00000000 ; .word 0x922300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000001D ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x2402010C ;\n"
      ".word 0x1062000F ; .word 0x00000000 ; .word 0x2402010B ; .word 0x10620003 ; .word 0x00000000 ; .word 0x10000013 ; .word 0x00000000 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x2442A020 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000000B ; .word 0x00000000 ;\n"
      ".word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A03A ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000183 ; .word 0x00000000 ; .word 0x922400A2 ; .word 0x24030001 ; .word 0x10830004 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x1000004B ; .word 0x00000000 ; .word 0x962400A4 ; .word 0x24030127 ; .word 0x10830030 ; .word 0x00000000 ; .word 0x24030119 ;\n"
      ".word 0x1083002D ; .word 0x00000000 ; .word 0x24030118 ; .word 0x10830021 ; .word 0x00000000 ; .word 0x24030117 ; .word 0x1083001E ; .word 0x00000000 ;\n"
      ".word 0x24030116 ; .word 0x1083001B ; .word 0x00000000 ; .word 0x2403010D ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000035 ; .word 0x00000000 ;\n"
      ".word 0x8C420B54 ; .word 0x1440000A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A080 ; .word 0x00431021 ; .word 0x90420000 ;\n"
      ".word 0x0002143C ; .word 0x0002143F ; .word 0x1000002A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A09A ; .word 0x00431021 ;\n"
      ".word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000021 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A0B4 ;\n"
      ".word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000018 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x24020003 ;\n"
      ".word 0x1462000A ; .word 0x00000000 ; .word 0x8E240A2C ; .word 0x24050400 ; .word 0x0C0C0160 ; .word 0x00000000 ; .word 0x10400004 ; .word 0x00000000 ;\n"
      ".word 0x2402000F ; .word 0x1000000B ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A0CE ; .word 0x00431021 ; .word 0x90420000 ;\n"
      ".word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000130 ; .word 0x00000000 ; .word 0x922300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000029 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x24020011 ;\n"
      ".word 0x10620008 ; .word 0x00000000 ; .word 0x24020003 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x10600003 ; .word 0x00000000 ; .word 0x1000000F ;\n"
      ".word 0x00000000 ; .word 0x8E240A2C ; .word 0x2405000B ; .word 0x0C0C05D4 ; .word 0x00000000 ; .word 0x0002163C ; .word 0x0002163F ; .word 0x18400007 ;\n"
      ".word 0x00000000 ; .word 0x24030001 ; .word 0x8F82B6FC ; .word 0xAC430B50 ; .word 0x2402000F ; .word 0x10000010 ; .word 0x00000000 ; .word 0x8E240A2C ;\n"
      ".word 0x2405000B ; .word 0x0C0C05D4 ; .word 0x00000000 ; .word 0x14400003 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0xAC400B50 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x2442A230 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x100000FF ; .word 0x00000000 ;\n"
      ".word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000000F ; .word 0x00000000 ; .word 0x962300A4 ;\n"
      ".word 0x24020112 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000008 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ;\n"
      ".word 0x2442A380 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x100000E8 ; .word 0x00000000 ; .word 0x922300A2 ;\n"
      ".word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x24020108 ;\n"
      ".word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A130 ; .word 0x00431021 ;\n"
      ".word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x100000CF ; .word 0x00000000 ;\n"
      ".word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ;\n"
      ".word 0x2402010F ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A170 ;\n"
      ".word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x100000B6 ;\n"
      ".word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ;\n"
      ".word 0x962300A4 ; .word 0x24020110 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ;\n"
      ".word 0x2442A1B0 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ;\n"
      ".word 0x1000009D ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000011 ;\n"
      ".word 0x00000000 ; .word 0x962300A4 ; .word 0x24020126 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ; .word 0x3203FFFF ;\n"
      ".word 0x3C02006A ; .word 0x2442A490 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x10000084 ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ; .word 0x2402FFFF ;\n"
      ".word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x240200E9 ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ; .word 0x00000000 ;\n"
      ".word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A4D0 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x1000006B ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x10000011 ; .word 0x00000000 ; .word 0x962300A4 ; .word 0x240200EA ; .word 0x10620003 ; .word 0x00000000 ; .word 0x1000000A ;\n"
      ".word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A510 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ;\n"
      ".word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000052 ; .word 0x00000000 ; .word 0x922300A2 ; .word 0x24020001 ; .word 0x10620004 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000017 ; .word 0x00000000 ; .word 0x962200A4 ; .word 0x2442FF15 ; .word 0x2C410006 ; .word 0x10200011 ;\n"
      ".word 0x00000000 ; .word 0x3C03007C ; .word 0x24638D30 ; .word 0x00021080 ; .word 0x00431021 ; .word 0x8C420000 ; .word 0x00400008 ; .word 0x00000000 ;\n"
      ".word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A530 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000033 ; .word 0x00000000 ; .word 0x922400A2 ; .word 0x24030001 ; .word 0x10830004 ; .word 0x00000000 ;\n"
      ".word 0x2402FFFF ; .word 0x10000029 ; .word 0x00000000 ; .word 0x962400A4 ; .word 0x240300F1 ; .word 0x10830003 ; .word 0x00000000 ; .word 0x10000022 ;\n"
      ".word 0x00000000 ; .word 0x8C420B48 ; .word 0x14400016 ; .word 0x00000000 ; .word 0x3203FFFF ; .word 0x24020002 ; .word 0x14620009 ; .word 0x00000000 ;\n"
      ".word 0x8E240A2C ; .word 0x0C0C2D78 ; .word 0x00000000 ; .word 0x10400004 ; .word 0x00000000 ; .word 0x24020006 ; .word 0x10000014 ; .word 0x00000000 ;\n"
      ".word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A570 ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ; .word 0x1000000B ;\n"
      ".word 0x00000000 ; .word 0x3203FFFF ; .word 0x3C02006A ; .word 0x2442A58A ; .word 0x00431021 ; .word 0x90420000 ; .word 0x0002143C ; .word 0x0002143F ;\n"
      ".word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0x10000002 ; .word 0x00000000 ; .word 0x2402FFFF ; .word 0xDFBF0020 ; .word 0x7BB10010 ;\n"
      ".word 0x7BB00000 ; .word 0x27BD0030 ;\n"
      ".set reorder");
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

// FUN_002fc5d0
f32 func_002fc5d0(BtlUnit* unit, BtlUnit* target, s32 animation)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x8F82B6FC ; .word 0x8C43000C ; .word 0x3C020020 ; .word 0x00621024 ; .word 0x14400005 ; .word 0x00000000 ; .word 0x3C02BF80 ; .word 0x44820000 ;\n"
      ".word 0x10000128 ; .word 0x00000000 ; .word 0x90A300A2 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3C02BF80 ; .word 0x44820000 ;\n"
      ".word 0x10000120 ; .word 0x00000000 ; .word 0x908200A2 ; .word 0x24040002 ; .word 0x1444001A ; .word 0x00000000 ; .word 0x94A300A4 ; .word 0x240200F1 ;\n"
      ".word 0x10620003 ; .word 0x00000000 ; .word 0x10000014 ; .word 0x00000000 ; .word 0x30C2FFFF ; .word 0x10440007 ; .word 0x00000000 ; .word 0x10400005 ;\n"
      ".word 0x00000000 ; .word 0x3C02BF80 ; .word 0x44820000 ; .word 0x1000010D ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C0243FA ;\n"
      ".word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x10000103 ; .word 0x00000000 ; .word 0x30C3FFFF ;\n"
      ".word 0x2402000B ; .word 0x1062000E ; .word 0x00000000 ; .word 0x24020006 ; .word 0x1062000B ; .word 0x00000000 ; .word 0x24020005 ; .word 0x10620008 ;\n"
      ".word 0x00000000 ; .word 0x24020004 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x3C02BF80 ; .word 0x44820000 ; .word 0x100000F2 ; .word 0x00000000 ;\n"
      ".word 0x94A200A4 ; .word 0x240300F1 ; .word 0x104300DE ; .word 0x00000000 ; .word 0x240301AF ; .word 0x104300E9 ; .word 0x00000000 ; .word 0x24030126 ;\n"
      ".word 0x104300E6 ; .word 0x00000000 ; .word 0x24030112 ; .word 0x104300E3 ; .word 0x00000000 ; .word 0x24030128 ; .word 0x104300C6 ; .word 0x00000000 ;\n"
      ".word 0x24030125 ; .word 0x104300C3 ; .word 0x00000000 ; .word 0x24030124 ; .word 0x104300C0 ; .word 0x00000000 ; .word 0x24030123 ; .word 0x104300BD ;\n"
      ".word 0x00000000 ; .word 0x24030122 ; .word 0x104300BA ; .word 0x00000000 ; .word 0x24030121 ; .word 0x104300B7 ; .word 0x00000000 ; .word 0x24030120 ;\n"
      ".word 0x104300B4 ; .word 0x00000000 ; .word 0x2403011F ; .word 0x104300B1 ; .word 0x00000000 ; .word 0x2403011E ; .word 0x104300AE ; .word 0x00000000 ;\n"
      ".word 0x2403011D ; .word 0x104300AB ; .word 0x00000000 ; .word 0x2403011C ; .word 0x104300A8 ; .word 0x00000000 ; .word 0x2403011B ; .word 0x104300A5 ;\n"
      ".word 0x00000000 ; .word 0x2403011A ; .word 0x104300A2 ; .word 0x00000000 ; .word 0x24030111 ; .word 0x1043009F ; .word 0x00000000 ; .word 0x24030110 ;\n"
      ".word 0x104300B6 ; .word 0x00000000 ; .word 0x2403010F ; .word 0x104300B3 ; .word 0x00000000 ; .word 0x2403010D ; .word 0x1043008C ; .word 0x00000000 ;\n"
      ".word 0x2403010C ; .word 0x104300AD ; .word 0x00000000 ; .word 0x2403010B ; .word 0x104300AA ; .word 0x00000000 ; .word 0x2403010A ; .word 0x10430079 ;\n"
      ".word 0x00000000 ; .word 0x24030109 ; .word 0x10430071 ; .word 0x00000000 ; .word 0x24030108 ; .word 0x104300A1 ; .word 0x00000000 ; .word 0x24030107 ;\n"
      ".word 0x10430061 ; .word 0x00000000 ; .word 0x24030115 ; .word 0x10430054 ; .word 0x00000000 ; .word 0x24030106 ; .word 0x10430047 ; .word 0x00000000 ;\n"
      ".word 0x24030105 ; .word 0x1043003A ; .word 0x00000000 ; .word 0x24030104 ; .word 0x1043002D ; .word 0x00000000 ; .word 0x24030103 ; .word 0x10430020 ;\n"
      ".word 0x00000000 ; .word 0x24030102 ; .word 0x10430013 ; .word 0x00000000 ; .word 0x24030101 ; .word 0x10430010 ; .word 0x00000000 ; .word 0x24030100 ;\n"
      ".word 0x10430003 ; .word 0x00000000 ; .word 0x10000084 ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C024316 ; .word 0x44820800 ;\n"
      ".word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x1000007C ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ;\n"
      ".word 0x3C0242C8 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x10000072 ; .word 0x00000000 ;\n"
      ".word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C0242C8 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ;\n"
      ".word 0x10000068 ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C024316 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ;\n"
      ".word 0x46010018 ; .word 0x4602181C ; .word 0x1000005E ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C024316 ; .word 0x44820800 ;\n"
      ".word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x10000054 ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ;\n"
      ".word 0x3C02432F ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x1000004A ; .word 0x00000000 ;\n"
      ".word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C024248 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ;\n"
      ".word 0x10000040 ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C0242FA ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ;\n"
      ".word 0x46010018 ; .word 0x4602181C ; .word 0x10000036 ; .word 0x00000000 ; .word 0xC4A10090 ; .word 0xC4A0002C ; .word 0x46000802 ; .word 0x10000031 ;\n"
      ".word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C024348 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ;\n"
      ".word 0x4602181C ; .word 0x10000027 ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C0242C8 ; .word 0x44820800 ; .word 0x44800000 ;\n"
      ".word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x1000001D ; .word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x24020177 ;\n"
      ".word 0x44820000 ; .word 0x00000000 ; .word 0x46800060 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x4602181C ; .word 0x10000011 ;\n"
      ".word 0x00000000 ; .word 0xC4A30090 ; .word 0xC4A2002C ; .word 0x3C0243E1 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ;\n"
      ".word 0x4602185C ; .word 0x3C0242C8 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46010000 ; .word 0x10000003 ; .word 0x00000000 ; .word 0x3C02BF80 ;\n"
      ".word 0x44820000 ;\n"
      ".set reorder");
}

/* Recovered battle-misc harvest: 0x002FCAA0-0x002FED10 */
// FUN_002FCAA0


u32 FUN_002fcaa0(int param_1,u32 *param_2)



{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x8F83B6FC ; .word 0x8C620BBC ; .word 0x94420008 ; .word 0x2442FE59 ; .word 0x2C41000D ; .word 0x10200122 ; .word 0x00000000 ; .word 0x3C06007C ;\n"
      ".word 0x24C68DD0 ; .word 0x00021080 ; .word 0x00461021 ; .word 0x8C420000 ; .word 0x00400008 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ;\n"
      ".word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000001E ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ;\n"
      ".word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000016 ; .word 0x00000000 ; .word 0x94C400A4 ; .word 0x2402010C ; .word 0x10820006 ;\n"
      ".word 0x00000000 ; .word 0x2402010B ; .word 0x10820003 ; .word 0x00000000 ; .word 0x1000000C ; .word 0x00000000 ; .word 0x8C620B44 ; .word 0xACA20000 ;\n"
      ".word 0x8F82B6FC ; .word 0x8C420B48 ; .word 0xACA20004 ; .word 0x8F82B6FC ; .word 0x8C420B4C ; .word 0xACA20008 ; .word 0x24020001 ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x0000102D ; .word 0x100000F6 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x14400004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000001A ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ; .word 0x10820004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x10000012 ; .word 0x00000000 ; .word 0x94C600A4 ; .word 0x24040108 ; .word 0x10C40003 ; .word 0x00000000 ; .word 0x1000000B ;\n"
      ".word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ; .word 0x8F83B6FC ; .word 0x8C630B4C ;\n"
      ".word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x100000D4 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ;\n"
      ".word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000001A ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ;\n"
      ".word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000012 ; .word 0x00000000 ; .word 0x94C600A4 ; .word 0x2404010F ; .word 0x10C40003 ;\n"
      ".word 0x00000000 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ;\n"
      ".word 0x8F83B6FC ; .word 0x8C630B4C ; .word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x100000B2 ; .word 0x00000000 ;\n"
      ".word 0x9482001A ; .word 0x30420001 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000001A ; .word 0x00000000 ; .word 0x8C860030 ;\n"
      ".word 0x90C400A2 ; .word 0x24020001 ; .word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000012 ; .word 0x00000000 ; .word 0x94C600A4 ;\n"
      ".word 0x24040110 ; .word 0x10C40003 ; .word 0x00000000 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ;\n"
      ".word 0x8C630B48 ; .word 0xACA30004 ; .word 0x8F83B6FC ; .word 0x8C630B4C ; .word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".word 0x10000090 ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000001A ;\n"
      ".word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ; .word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000012 ;\n"
      ".word 0x00000000 ; .word 0x94C600A4 ; .word 0x24040126 ; .word 0x10C40003 ; .word 0x00000000 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x8C630B44 ;\n"
      ".word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ; .word 0x8F83B6FC ; .word 0x8C630B4C ; .word 0xACA30008 ; .word 0x10000002 ;\n"
      ".word 0x00000000 ; .word 0x0000102D ; .word 0x1000006E ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ; .word 0x14400004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000001A ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ; .word 0x10820004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x10000012 ; .word 0x00000000 ; .word 0x94C600A4 ; .word 0x240400E9 ; .word 0x10C40003 ; .word 0x00000000 ; .word 0x1000000B ;\n"
      ".word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ; .word 0x8F83B6FC ; .word 0x8C630B4C ;\n"
      ".word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000004C ; .word 0x00000000 ; .word 0x9482001A ; .word 0x30420001 ;\n"
      ".word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000001A ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C400A2 ; .word 0x24020001 ;\n"
      ".word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000012 ; .word 0x00000000 ; .word 0x94C600A4 ; .word 0x240400EA ; .word 0x10C40003 ;\n"
      ".word 0x00000000 ; .word 0x1000000B ; .word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ;\n"
      ".word 0x8F83B6FC ; .word 0x8C630B4C ; .word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x1000002A ; .word 0x00000000 ;\n"
      ".word 0x9482001A ; .word 0x30420001 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000020 ; .word 0x00000000 ; .word 0x8C860030 ;\n"
      ".word 0x90C400A2 ; .word 0x24020001 ; .word 0x10820004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000018 ; .word 0x00000000 ; .word 0x94C400A4 ;\n"
      ".word 0x2484FF15 ; .word 0x2C810006 ; .word 0x10200012 ; .word 0x00000000 ; .word 0x3C06007C ; .word 0x24C68DB0 ; .word 0x00042080 ; .word 0x00862021 ;\n"
      ".word 0x8C840000 ; .word 0x00800008 ; .word 0x00000000 ; .word 0x8C630B44 ; .word 0xACA30000 ; .word 0x8F83B6FC ; .word 0x8C630B48 ; .word 0xACA30004 ;\n"
      ".word 0x8F83B6FC ; .word 0x8C630B4C ; .word 0xACA30008 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000002 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ;\n"
      ".set reorder");
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

// FUN_002FD2E0


u32 FUN_002fd2e0(int param_1,u16 param_2)
{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFB0 ; .word 0xFFBF0040 ; .word 0x7FB30030 ; .word 0x7FB20020 ; .word 0x7FB10010 ; .word 0x7FB00000 ; .word 0x0080902D ; .word 0x00A0882D ;\n"
      ".word 0x3222FFFF ; .word 0x00021080 ; .word 0x8F87B6FC ; .word 0x00472821 ; .word 0x8CA30B2C ; .word 0x8C820008 ; .word 0x14620008 ; .word 0x00000000 ;\n"
      ".word 0x8CA30B38 ; .word 0x8E420020 ; .word 0x14620004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000052 ; .word 0x00000000 ; .word 0x3223FFFF ;\n"
      ".word 0x24020002 ; .word 0x1062001A ; .word 0x00000000 ; .word 0x24020001 ; .word 0x1062000E ; .word 0x00000000 ; .word 0x10600003 ; .word 0x00000000 ;\n"
      ".word 0x1000001A ; .word 0x00000000 ; .word 0x8CE60B1C ; .word 0x2402FFFF ; .word 0x14C20004 ; .word 0x00000000 ; .word 0x0000102D ; .word 0x10000040 ;\n"
      ".word 0x00000000 ; .word 0x10000011 ; .word 0x00000000 ; .word 0x8CE60B20 ; .word 0x2402FFFF ; .word 0x14C20004 ; .word 0x00000000 ; .word 0x0000102D ;\n"
      ".word 0x10000037 ; .word 0x00000000 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x8CE60B24 ; .word 0x2402FFFF ; .word 0x14C20004 ; .word 0x00000000 ;\n"
      ".word 0x0000102D ; .word 0x1000002E ; .word 0x00000000 ; .word 0x8CE20D18 ; .word 0x8C420020 ; .word 0x2444FFFF ; .word 0x8F85B7E0 ; .word 0x0C0D6ED0 ;\n"
      ".word 0x00000000 ; .word 0x0040802D ; .word 0x8F82B6FC ; .word 0x0200202D ; .word 0x8C450148 ; .word 0x0C0D7068 ; .word 0x00000000 ; .word 0x0200202D ;\n"
      ".word 0x0C0D6B84 ; .word 0x00000000 ; .word 0x0040982D ; .word 0x8C4200CC ; .word 0x04400009 ; .word 0x00000000 ; .word 0x24040001 ; .word 0x0C05DE2C ;\n"
      ".word 0x00000000 ; .word 0x8E6400CC ; .word 0x0000282D ; .word 0x0040302D ; .word 0x0C0E9088 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0x8C440D18 ;\n"
      ".word 0x0200282D ; .word 0x0C065554 ; .word 0x00000000 ; .word 0x8F82B6FC ; .word 0xAC500B28 ; .word 0x3222FFFF ; .word 0x00022080 ; .word 0x8E430008 ;\n"
      ".word 0x8F82B6FC ; .word 0x00821021 ; .word 0xAC430B2C ; .word 0x8E430020 ; .word 0x8F82B6FC ; .word 0x00821021 ; .word 0xAC430B38 ; .word 0x24020001 ;\n"
      ".word 0xDFBF0040 ; .word 0x7BB30030 ; .word 0x7BB20020 ; .word 0x7BB10010 ; .word 0x7BB00000 ; .word 0x27BD0050 ;\n"
      ".set reorder");
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

// FUN_002FD8A0
void FUN_002fd8a0(int param_1)



{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFFF0 ; .word 0xFFBF0000 ; .word 0x8F83B6FC ; .word 0x8C630BBC ; .word 0x94630008 ; .word 0x2463FE59 ; .word 0x2C61000D ; .word 0x102000A7 ;\n"
      ".word 0x00000000 ; .word 0x3C05007C ; .word 0x24A58E30 ; .word 0x00031880 ; .word 0x00651821 ; .word 0x8C630000 ; .word 0x00600008 ; .word 0x00000000 ;\n"
      ".word 0x9483001A ; .word 0x30630001 ; .word 0x1060009C ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A30097 ;\n"
      ".word 0x00000000 ; .word 0x94C500A4 ; .word 0x2403010C ; .word 0x10A30006 ; .word 0x00000000 ; .word 0x2403010B ; .word 0x10A30003 ; .word 0x00000000 ;\n"
      ".word 0x1000008E ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0x1000008A ; .word 0x00000000 ; .word 0x9483001A ; .word 0x30630001 ;\n"
      ".word 0x10600086 ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A30081 ; .word 0x00000000 ; .word 0x94C500A4 ;\n"
      ".word 0x24030108 ; .word 0x10A30003 ; .word 0x00000000 ; .word 0x1000007B ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0x10000077 ;\n"
      ".word 0x00000000 ; .word 0x9483001A ; .word 0x30630001 ; .word 0x10600073 ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ;\n"
      ".word 0x14A3006E ; .word 0x00000000 ; .word 0x94C500A4 ; .word 0x2403010F ; .word 0x10A30003 ; .word 0x00000000 ; .word 0x10000068 ; .word 0x00000000 ;\n"
      ".word 0x0C0A2618 ; .word 0x00000000 ; .word 0x10000064 ; .word 0x00000000 ; .word 0x9483001A ; .word 0x30630001 ; .word 0x10600060 ; .word 0x00000000 ;\n"
      ".word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A3005B ; .word 0x00000000 ; .word 0x94C500A4 ; .word 0x24030110 ; .word 0x10A30003 ;\n"
      ".word 0x00000000 ; .word 0x10000055 ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0x10000051 ; .word 0x00000000 ; .word 0x9483001A ;\n"
      ".word 0x30630001 ; .word 0x1060004D ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A30048 ; .word 0x00000000 ;\n"
      ".word 0x94C500A4 ; .word 0x24030126 ; .word 0x10A30003 ; .word 0x00000000 ; .word 0x10000042 ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ;\n"
      ".word 0x1000003E ; .word 0x00000000 ; .word 0x9483001A ; .word 0x30630001 ; .word 0x1060003A ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ;\n"
      ".word 0x24030001 ; .word 0x14A30035 ; .word 0x00000000 ; .word 0x94C500A4 ; .word 0x240300E9 ; .word 0x10A30003 ; .word 0x00000000 ; .word 0x1000002F ;\n"
      ".word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0x1000002B ; .word 0x00000000 ; .word 0x9483001A ; .word 0x30630001 ; .word 0x10600027 ;\n"
      ".word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A30022 ; .word 0x00000000 ; .word 0x94C500A4 ; .word 0x240300EA ;\n"
      ".word 0x10A30003 ; .word 0x00000000 ; .word 0x1000001C ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0x10000018 ; .word 0x00000000 ;\n"
      ".word 0x9483001A ; .word 0x30630001 ; .word 0x10600014 ; .word 0x00000000 ; .word 0x8C860030 ; .word 0x90C500A2 ; .word 0x24030001 ; .word 0x14A3000F ;\n"
      ".word 0x00000000 ; .word 0x94C300A4 ; .word 0x2463FF15 ; .word 0x2C610006 ; .word 0x1020000A ; .word 0x00000000 ; .word 0x3C05007C ; .word 0x24A58E10 ;\n"
      ".word 0x00031880 ; .word 0x00651821 ; .word 0x8C630000 ; .word 0x00600008 ; .word 0x00000000 ; .word 0x0C0A2618 ; .word 0x00000000 ; .word 0xDFBF0000 ;\n"
      ".word 0x27BD0010 ;\n"
      ".set reorder");
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





































// FUN_002FE0B0
void FUN_002fe0b0(float param_1,u8 *param_2,u64 param_3,u64 param_4,

                 u64 param_5)



{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFE60 ; .word 0xFFBF0090 ; .word 0x7FB60080 ; .word 0x7FB50070 ; .word 0x7FB40060 ; .word 0x7FB30050 ; .word 0x7FB20040 ; .word 0x7FB10030 ;\n"
      ".word 0x7FB00020 ; .word 0xE7BA0018 ; .word 0xE7B90014 ; .word 0xE7B80010 ; .word 0xE7B7000C ; .word 0xE7B60008 ; .word 0xE7B50004 ; .word 0xE7B40000 ;\n"
      ".word 0x46006686 ; .word 0x0080A02D ; .word 0x00A0982D ; .word 0x00C0902D ; .word 0x00E0882D ; .word 0x0C066164 ; .word 0x00000000 ; .word 0x0040B02D ;\n"
      ".word 0x0C138D8C ; .word 0x00000000 ; .word 0x0040802D ; .word 0xC440000C ; .word 0x46800020 ; .word 0x3C034420 ; .word 0x4483A800 ; .word 0x00000000 ;\n"
      ".word 0x4600AE43 ; .word 0xC4400010 ; .word 0x46800020 ; .word 0x3C0243E0 ; .word 0x4482A000 ; .word 0x00000000 ; .word 0x4600A603 ; .word 0x00000000 ;\n"
      ".word 0x44802800 ; .word 0x00000000 ; .word 0x461A2832 ; .word 0x45000005 ; .word 0x00000000 ; .word 0x46002DC6 ; .word 0x46002D86 ; .word 0x10000013 ;\n"
      ".word 0x00000000 ; .word 0x3C0243A0 ; .word 0x44822000 ; .word 0x00000000 ; .word 0x46002007 ; .word 0xC783826C ; .word 0x46032818 ; .word 0x461A05DC ;\n"
      ".word 0x3C024360 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x46001047 ; .word 0xC7808270 ; .word 0x46002818 ; .word 0x461A0D9C ; .word 0x46032818 ;\n"
      ".word 0x461A255C ; .word 0x46002818 ; .word 0x461A151C ; .word 0x3C150096 ; .word 0x26B50090 ; .word 0x24040007 ; .word 0x24050002 ; .word 0x8EA20000 ;\n"
      ".word 0x0040F809 ; .word 0x00000000 ; .word 0x24040014 ; .word 0x24050001 ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x2404000E ;\n"
      ".word 0x0000282D ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040006 ; .word 0x0000282D ; .word 0x8EA20000 ; .word 0x0040F809 ;\n"
      ".word 0x00000000 ; .word 0x24040008 ; .word 0x0000282D ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040009 ; .word 0x0220282D ;\n"
      ".word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x2404000C ; .word 0x24050001 ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ;\n"
      ".word 0x24040001 ; .word 0x0200282D ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040002 ; .word 0x0260282D ; .word 0x0C135FD8 ;\n"
      ".word 0x00000000 ; .word 0x24040003 ; .word 0x0240282D ; .word 0x0C135FD8 ; .word 0x00000000 ; .word 0x3C020096 ; .word 0xC441008C ; .word 0x3C023F80 ;\n"
      ".word 0x44821000 ; .word 0xC6C00084 ; .word 0x46001003 ; .word 0xE7B700A0 ; .word 0xE7B600A4 ; .word 0xE7A100A8 ; .word 0x92820000 ; .word 0x04400006 ;\n"
      ".word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ;\n"
      ".word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A200C0 ; .word 0x92820001 ; .word 0x04400006 ;\n"
      ".word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ;\n"
      ".word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A200C4 ; .word 0x92820002 ; .word 0x04400006 ;\n"
      ".word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ;\n"
      ".word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A200C8 ; .word 0x92820003 ; .word 0x04400006 ;\n"
      ".word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ;\n"
      ".word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A200CC ; .word 0xE7A000B8 ; .word 0xAFA000B0 ;\n"
      ".word 0xAFA000B4 ; .word 0xE7B700E0 ; .word 0xE7B400E4 ; .word 0xE7A100E8 ; .word 0x92820000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A20100 ; .word 0x92820001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A20104 ; .word 0x92820002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A20108 ; .word 0x92820003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ;\n"
      ".word 0x00000000 ; .word 0x468010A0 ; .word 0x46021080 ; .word 0xE7A2010C ; .word 0xE7A000F8 ; .word 0xAFA000F0 ; .word 0xE7B800F4 ; .word 0xE7B50120 ;\n"
      ".word 0xE7B60124 ; .word 0xE7A10128 ; .word 0x92820000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x46021080 ; .word 0xE7A20140 ; .word 0x92820001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x46021080 ; .word 0xE7A20144 ; .word 0x92820002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x46021080 ; .word 0xE7A20148 ; .word 0x92820003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44821000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44831000 ; .word 0x00000000 ; .word 0x468010A0 ;\n"
      ".word 0x46021080 ; .word 0xE7A2014C ; .word 0xE7A00138 ; .word 0xE7B90130 ; .word 0xAFA00134 ; .word 0xE7B50160 ; .word 0xE7B40164 ; .word 0xE7A10168 ;\n"
      ".word 0x92820000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x46010840 ; .word 0xE7A10180 ;\n"
      ".word 0x92820001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x46010840 ; .word 0xE7A10184 ;\n"
      ".word 0x92820002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x46010840 ; .word 0xE7A10188 ;\n"
      ".word 0x92820003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830800 ; .word 0x00000000 ; .word 0x46800860 ; .word 0x46010840 ; .word 0xE7A1018C ;\n"
      ".word 0xE7A00178 ; .word 0xE7B90170 ; .word 0xE7B80174 ; .word 0x24040004 ; .word 0x27A500A0 ; .word 0x0080302D ; .word 0x3C020096 ; .word 0x8C4200A0 ;\n"
      ".word 0x0040F809 ; .word 0x00000000 ; .word 0x24040001 ; .word 0x0000282D ; .word 0x8EA20000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0xDFBF0090 ;\n"
      ".word 0x7BB60080 ; .word 0x7BB50070 ; .word 0x7BB40060 ; .word 0x7BB30050 ; .word 0x7BB20040 ; .word 0x7BB10030 ; .word 0x7BB00020 ; .word 0xC7BA0018 ;\n"
      ".word 0xC7B90014 ; .word 0xC7B80010 ; .word 0xC7B7000C ; .word 0xC7B60008 ; .word 0xC7B50004 ; .word 0xC7B40000 ; .word 0x27BD01A0 ;\n"
      ".set reorder");
}





























// FUN_002FE780
void FUN_002fe780(float param_1,u8 *param_2,u8 *param_3,u64 param_4,u64 param_5)



{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDF4F0 ; .word 0xFFBF0080 ; .word 0x7FB50070 ; .word 0x7FB40060 ; .word 0x7FB30050 ; .word 0x7FB20040 ; .word 0x7FB10030 ; .word 0x7FB00020 ;\n"
      ".word 0xE7B80010 ; .word 0xE7B7000C ; .word 0xE7B60008 ; .word 0xE7B50004 ; .word 0xE7B40000 ; .word 0x46006586 ; .word 0x0080A02D ; .word 0x00A0982D ;\n"
      ".word 0x00C0902D ; .word 0x00E0882D ; .word 0x0C066164 ; .word 0x00000000 ; .word 0x0040A82D ; .word 0x3C100096 ; .word 0x26100090 ; .word 0x24040007 ;\n"
      ".word 0x24050002 ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040014 ; .word 0x24050001 ; .word 0x8E020000 ; .word 0x0040F809 ;\n"
      ".word 0x00000000 ; .word 0x2404000E ; .word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040006 ; .word 0x0000282D ;\n"
      ".word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040008 ; .word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ;\n"
      ".word 0x2404000C ; .word 0x24050001 ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040001 ; .word 0x0000282D ; .word 0x8E020000 ;\n"
      ".word 0x0040F809 ; .word 0x00000000 ; .word 0x24040002 ; .word 0x0240282D ; .word 0x0C135FD8 ; .word 0x00000000 ; .word 0x24040003 ; .word 0x0220282D ;\n"
      ".word 0x0C135FD8 ; .word 0x00000000 ; .word 0x3C020096 ; .word 0xC455008C ; .word 0x3C023F80 ; .word 0x44820800 ; .word 0xC6A00084 ; .word 0x46000D03 ;\n"
      ".word 0x3C024815 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46000004 ; .word 0x4600B582 ; .word 0x4480B800 ; .word 0x3C0243A0 ; .word 0xAFA20090 ;\n"
      ".word 0x3C024360 ; .word 0xAFA20094 ; .word 0xE7B50098 ; .word 0xE7B400A8 ; .word 0x92820000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ; .word 0xE7A000B0 ; .word 0x92820001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ; .word 0xE7A000B4 ; .word 0x92820002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ; .word 0xE7A000B8 ; .word 0x92820003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ;\n"
      ".word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ; .word 0xE7A000BC ; .word 0x64100001 ; .word 0x0000882D ; .word 0x10000061 ; .word 0x00000000 ;\n"
      ".word 0x4600BB06 ; .word 0x0C14B9B6 ; .word 0x00000000 ; .word 0x3C0243A0 ; .word 0x44821000 ; .word 0x44800800 ; .word 0x00000000 ; .word 0x46020818 ;\n"
      ".word 0x4600B61C ; .word 0x4600BB06 ; .word 0x0C14BA1E ; .word 0x00000000 ; .word 0x3C024360 ; .word 0x44821000 ; .word 0x44800800 ; .word 0x00000000 ;\n"
      ".word 0x46020818 ; .word 0x4600B01C ; .word 0x3202FFFF ; .word 0x00021180 ; .word 0x005D1021 ; .word 0x24440090 ; .word 0xE4980000 ; .word 0xE4800004 ;\n"
      ".word 0xE4950008 ; .word 0xE4940018 ; .word 0x92620000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x46000000 ; .word 0xE4800020 ; .word 0x92620001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x46000000 ; .word 0xE4800024 ; .word 0x92620002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x46000000 ; .word 0xE4800028 ; .word 0x92620003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x46000000 ; .word 0xE480002C ; .word 0x26020001 ; .word 0x3050FFFF ; .word 0xC7808268 ; .word 0x4600BDC0 ; .word 0x26220001 ; .word 0x3051FFFF ;\n"
      ".word 0x3222FFFF ; .word 0x28420028 ; .word 0x1440FF9D ; .word 0x00000000 ; .word 0x3202FFFF ; .word 0x00022180 ; .word 0xC7A000D0 ; .word 0x009D1821 ;\n"
      ".word 0xE4600090 ; .word 0xC7A000D4 ; .word 0xE4600094 ; .word 0x24620098 ; .word 0xC7A000D8 ; .word 0xE4400000 ; .word 0xE4550000 ; .word 0xE47400A8 ;\n"
      ".word 0x92620000 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ; .word 0x009D1021 ;\n"
      ".word 0xE44000B0 ; .word 0x92620001 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ; .word 0x10000008 ;\n"
      ".word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ; .word 0x46000000 ;\n"
      ".word 0x009D1021 ; .word 0xE44000B4 ; .word 0x92620002 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800020 ;\n"
      ".word 0x46000000 ; .word 0x009D1021 ; .word 0xE44000B8 ; .word 0x92620003 ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ;\n"
      ".word 0x46800020 ; .word 0x10000008 ; .word 0x00000000 ; .word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ;\n"
      ".word 0x46800020 ; .word 0x46000000 ; .word 0x009D1021 ; .word 0xE44000BC ; .word 0x24040005 ; .word 0x27A50090 ; .word 0x2406002A ; .word 0x3C020096 ;\n"
      ".word 0x8C4200A0 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0xDFBF0080 ; .word 0x7BB50070 ; .word 0x7BB40060 ; .word 0x7BB30050 ; .word 0x7BB20040 ;\n"
      ".word 0x7BB10030 ; .word 0x7BB00020 ; .word 0xC7B80010 ; .word 0xC7B7000C ; .word 0xC7B60008 ; .word 0xC7B50004 ; .word 0xC7B40000 ; .word 0x27BD0B10 ;\n"
      ".set reorder");
}

// FUN_002FED10








u32 FUN_002fed10(int param_1)



{
    __asm__ volatile (
      ".set noreorder ;\n"
      ".word 0x27BDFF80 ; .word 0xFFBF0040 ; .word 0x7FB20030 ; .word 0x7FB10020 ; .word 0x7FB00010 ; .word 0xE7B50004 ; .word 0xE7B40000 ; .word 0x0080882D ;\n"
      ".word 0x0000902D ; .word 0x0000802D ; .word 0x1000000D ; .word 0x00000000 ; .word 0x00102080 ; .word 0x3C02006A ; .word 0x2442AA50 ; .word 0x00441821 ;\n"
      ".word 0x009D1021 ; .word 0x8C640000 ; .word 0x24450050 ; .word 0x3C020096 ; .word 0x8C420094 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x26100001 ;\n"
      ".word 0x2E020007 ; .word 0x1440FFF2 ; .word 0x00000000 ; .word 0x8E31003C ; .word 0x92230000 ; .word 0x24020003 ; .word 0x10620102 ; .word 0x00000000 ;\n"
      ".word 0x24020002 ; .word 0x106200CD ; .word 0x00000000 ; .word 0x24020001 ; .word 0x10620005 ; .word 0x00000000 ; .word 0x10600102 ; .word 0x00000000 ;\n"
      ".word 0x10000100 ; .word 0x00000000 ; .word 0x9782B81C ; .word 0x144000C1 ; .word 0x00000000 ; .word 0x9782B81A ; .word 0x24420001 ; .word 0xA782B81A ;\n"
      ".word 0x9782B81A ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800060 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800060 ; .word 0x46010840 ; .word 0x3C0241A0 ;\n"
      ".word 0x44820000 ; .word 0x00000000 ; .word 0x46000D43 ; .word 0x3C100096 ; .word 0x26100090 ; .word 0x24040007 ; .word 0x24050002 ; .word 0x8E020000 ;\n"
      ".word 0x0040F809 ; .word 0x00000000 ; .word 0x24040014 ; .word 0x24050001 ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x2404000E ;\n"
      ".word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040006 ; .word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ;\n"
      ".word 0x00000000 ; .word 0x24040008 ; .word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x2404000C ; .word 0x24050001 ;\n"
      ".word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x24040001 ; .word 0x0000282D ; .word 0x8E020000 ; .word 0x0040F809 ; .word 0x00000000 ;\n"
      ".word 0x24040002 ; .word 0x24050044 ; .word 0x0C135FD8 ; .word 0x00000000 ; .word 0x24040003 ; .word 0x3C020003 ; .word 0x34451801 ; .word 0x0C135FD8 ;\n"
      ".word 0x00000000 ; .word 0x0C0CA534 ; .word 0x00000000 ; .word 0x240200FF ; .word 0xA3A2007C ; .word 0xA3A2007D ; .word 0xA3A2007E ; .word 0x4615AD02 ;\n"
      ".word 0x4614A802 ; .word 0x4600A802 ; .word 0x4600A882 ; .word 0x3C023F80 ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ;\n"
      ".word 0x4602A85D ; .word 0x3C02437F ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46010042 ; .word 0x3C024F00 ; .word 0x44820000 ; .word 0x00000000 ;\n"
      ".word 0x46010036 ; .word 0x45010007 ; .word 0x00000000 ; .word 0x46000824 ; .word 0x44030000 ; .word 0x00000000 ; .word 0x306300FF ; .word 0x10000007 ;\n"
      ".word 0x00000000 ; .word 0x46000801 ; .word 0x46000024 ; .word 0x44030000 ; .word 0x3C028000 ; .word 0x00621825 ; .word 0x306300FF ; .word 0xA3A3007F ;\n"
      ".word 0x27A4007C ; .word 0x0000282D ; .word 0x0C0D6118 ; .word 0x00000000 ; .word 0x240200FF ; .word 0xA3A20078 ; .word 0xA3A20079 ; .word 0xA3A2007A ;\n"
      ".word 0x3C024320 ; .word 0x44820800 ; .word 0x3C023F80 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46140001 ; .word 0x46000842 ; .word 0x3C024F00 ;\n"
      ".word 0x44820000 ; .word 0x00000000 ; .word 0x46010036 ; .word 0x45010007 ; .word 0x00000000 ; .word 0x46000824 ; .word 0x44030000 ; .word 0x00000000 ;\n"
      ".word 0x306300FF ; .word 0x10000007 ; .word 0x00000000 ; .word 0x46000801 ; .word 0x46000024 ; .word 0x44030000 ; .word 0x3C028000 ; .word 0x00621825 ;\n"
      ".word 0x306300FF ; .word 0xA3A3007B ; .word 0x240200FF ; .word 0xA3A20074 ; .word 0xA3A20075 ; .word 0xA3A20076 ; .word 0x93A2007F ; .word 0xA3A20077 ;\n"
      ".word 0x9782B81A ; .word 0x04400006 ; .word 0x00000000 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46800060 ; .word 0x10000008 ; .word 0x00000000 ;\n"
      ".word 0x00021842 ; .word 0x30420001 ; .word 0x00621825 ; .word 0x44830000 ; .word 0x00000000 ; .word 0x46800060 ; .word 0x46010840 ; .word 0x3C024120 ;\n"
      ".word 0x44820000 ; .word 0x00000000 ; .word 0x46000B03 ; .word 0x27A40078 ; .word 0x27A50074 ; .word 0x24060044 ; .word 0x3C020003 ; .word 0x34471801 ;\n"
      ".word 0x0C0BF9E0 ; .word 0x00000000 ; .word 0x0C0CA554 ; .word 0x00000000 ; .word 0x3C023F80 ; .word 0x44826000 ; .word 0x27849C80 ; .word 0x24050054 ;\n"
      ".word 0x3C020003 ; .word 0x34461801 ; .word 0x24070001 ; .word 0x0C0BF82C ; .word 0x00000000 ; .word 0x9782B81A ; .word 0x28420014 ; .word 0x14400041 ;\n"
      ".word 0x00000000 ; .word 0x24020003 ; .word 0xA2220000 ; .word 0x1000003D ; .word 0x00000000 ; .word 0x2442FFFF ; .word 0xA782B81C ; .word 0x3C023F80 ;\n"
      ".word 0x44826000 ; .word 0x27849C80 ; .word 0x24050044 ; .word 0x3C020003 ; .word 0x34461801 ; .word 0x24070001 ; .word 0x0C0BF82C ; .word 0x00000000 ;\n"
      ".word 0x96230006 ; .word 0x24020001 ; .word 0x14620004 ; .word 0x00000000 ; .word 0xC79481F4 ; .word 0x10000002 ; .word 0x00000000 ; .word 0xC7948274 ;\n"
      ".word 0x240200FF ; .word 0xA3A2007C ; .word 0xA3A2007D ; .word 0xA3A2007E ; .word 0x96230006 ; .word 0x24020001 ; .word 0x14620004 ; .word 0x00000000 ;\n"
      ".word 0x24020010 ; .word 0x10000002 ; .word 0x00000000 ; .word 0x24020018 ; .word 0xA3A2007F ; .word 0x4600A306 ; .word 0x27A4007C ; .word 0x24050044 ;\n"
      ".word 0x3C020003 ; .word 0x34461801 ; .word 0x24070002 ; .word 0x0C0BF82C ; .word 0x00000000 ; .word 0x24020005 ; .word 0xA3A2007F ; .word 0x4600A306 ;\n"
      ".word 0x27A4007C ; .word 0x24050048 ; .word 0x3C020003 ; .word 0x34461801 ; .word 0x24070002 ; .word 0x0C0BF82C ; .word 0x00000000 ; .word 0x10000009 ;\n"
      ".word 0x00000000 ; .word 0x0C0421C4 ; .word 0x00000000 ; .word 0x10400005 ; .word 0x00000000 ; .word 0x0C042170 ; .word 0x00000000 ; .word 0xA380B818 ;\n"
      ".word 0x2412FFFF ; .word 0x0000802D ; .word 0x1000000D ; .word 0x00000000 ; .word 0x00102080 ; .word 0x3C02006A ; .word 0x2442AA50 ; .word 0x00441821 ;\n"
      ".word 0x009D1021 ; .word 0x8C640000 ; .word 0x8C450050 ; .word 0x3C020096 ; .word 0x8C420090 ; .word 0x0040F809 ; .word 0x00000000 ; .word 0x26100001 ;\n"
      ".word 0x2E020007 ; .word 0x1440FFF2 ; .word 0x00000000 ; .word 0x24040001 ; .word 0x0000282D ; .word 0x3C020096 ; .word 0x8C420090 ; .word 0x0040F809 ;\n"
      ".word 0x00000000 ; .word 0x24040002 ; .word 0x24050044 ; .word 0x0C135FD8 ; .word 0x00000000 ; .word 0x24040003 ; .word 0x3C020007 ; .word 0x344517FB ;\n"
      ".word 0x0C135FD8 ; .word 0x00000000 ; .word 0x0240102D ; .word 0xDFBF0040 ; .word 0x7BB20030 ; .word 0x7BB10020 ; .word 0x7BB00010 ; .word 0xC7B50004 ;\n"
      ".word 0xC7B40000 ; .word 0x27BD0080 ;\n"
      ".set reorder");
}
