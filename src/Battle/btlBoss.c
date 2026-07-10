#include "Battle/btlBoss.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Kosaka/k_assert.h"
#include "Battle/battle.h"
#include "h_cdvd.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
u32 FUN_002fcaa0(int param_1,u32 *param_2);
u32 FUN_002fcf50(int param_1);
u32 FUN_002fd060(int param_1);
u32 FUN_002fd160(int param_1);
u8 FUN_002fd220(int param_1,int param_2);
u32 FUN_002fd2e0(int param_1,u16 param_2);
u32 FUN_002fd4a0(void);
u8 FUN_002fd500(void);
void FUN_002fd520(int param_1);
u64 FUN_002fd660(void);
u32 FUN_002fd7c0(void);
void FUN_002fd820(void);
void FUN_002fd8a0(int param_1);
u8 FUN_002fdb70(void);
u8 FUN_002fdb90(void);
u8 FUN_002fdbb0(int param_1,u64 param_2);
u8 FUN_002fdcb0(int param_1);
u32 FUN_002fdcf0(int param_1,int param_2);
u8 FUN_002fdd40(long param_1,long param_2);
void FUN_002fddb0(int param_1,float *param_2);
u64 FUN_002fde40(void);
u32 FUN_002fded0(short param_1);
u8 FUN_002fdfa0(void);
u32 FUN_002fdfe0(int param_1);
void FUN_002fe0b0(float param_1,u8 *param_2,u64 param_3,u64 param_4,  u64 param_5);
void FUN_002fe780(float param_1,u8 *param_2,u8 *param_3,u64 param_4,u64 param_5);
u32 FUN_002fed10(int param_1);
extern f32 DAT_007caee4;
extern f32 DAT_007caf58;
extern f32 DAT_007caf5c;
extern f32 DAT_007caf60;
extern f32 DAT_007caf64;
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce42c;
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
extern void* func_002f87e0(s32 index);
extern void func_00100ec0(void* resource);
extern void* H_Cdvd_ArchiveGetFile(HCdvd* cdvd, s32 fileIdx, u32* fileSize);
extern void func_002b9030(void* resource);
extern s32 func_002ecac0(void);
extern s32 func_002d6370(s32 id);
extern void func_0029a2c0(void);

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

static u16 btlBossGetEncounterId()
{
    return *(u16*)(*(u8**)((u8*)gBtl + 0xbbc) + 8);
}

static BtlUnit* btlBossGetEnemyHead()
{
    return *(BtlUnit**)((u8*)gBtl + 0x158);
}

static void btlBossReleaseResource(u32 offset)
{
    void* resource;

    resource = *(void**)((u8*)gBtl + offset);
    func_002b9030(resource);
    *(void**)((u8*)gBtl + offset) = NULL;
}

// FUN_002f8460 NONMATCHING
void func_002f8460()
{
    switch (btlBossGetEncounterId())
    {
        case 0x1a7:
        case 0x1a9:
        case 0x1aa:
        case 0x1ab:
            btlBossReleaseResource(0xb44);
            btlBossReleaseResource(0xb48);
            btlBossReleaseResource(0xb4c);
            break;
        case 0x1ac:
        case 0x1ad:
            btlBossReleaseResource(0xb44);
            break;
        case 0x1ae:
        case 0x1b0:
            btlBossReleaseResource(0xb44);
            btlBossReleaseResource(0xb48);
            btlBossReleaseResource(0xb4c);
            btlBossReleaseResource(0xb50);
            break;
        case 0x1af:
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            btlBossReleaseResource(0xb44);
            btlBossReleaseResource(0xb48);
            btlBossReleaseResource(0xb4c);
            break;
        case 0x1b4:
            btlBossReleaseResource(0xb44);
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

// FUN_002f87e0 NONMATCHING
void* func_002f87e0(s32 index)
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

    encounterId = btlBossGetEncounterId();
    if (encounterId == 0x1a8)
    {
        return *(u32*)((u8*)gBtl + 0xb54) == 1;
    }
    if (encounterId == 0x1a6)
    {
        return func_002ecac0() != 1;
    }
    if (encounterId == 0x1a4)
    {
        for (unit = btlBossGetEnemyHead(); unit != NULL; unit = unit->next)
        {
            if (unit->charId == 0x106 || unit->charId == 0x105)
            {
                if ((unit->flags3 & 8) != 0)
                {
                    return 1;
                }
            }
            else if (unit->charId == 0x115 && (unit->flags3 & 8) != 0)
            {
                return 0;
            }
        }
        return 0;
    }
    if (encounterId == 0x1a0)
    {
        for (unit = btlBossGetEnemyHead(); unit != NULL; unit = unit->next)
        {
            if (unit->charId == 0x114 || unit->charId == 0x113)
            {
                return 1;
            }
        }
    }
    return 0;
}

// FUN_002f8a40 NONMATCHING
u32 func_002f8a40(BtlUnit* unit)
{
    u16 encounterId;

    encounterId = btlBossGetEncounterId();
    switch (encounterId)
    {
        case 0x1b4:
        case 0x1ac:
            return unit->genus == 1;
        case 0x1ad:
            return unit->genus == 1 && unit->charId == 0x112;
        case 0x1a8:
            return unit->genus == 1 && unit->charId == 0x10d;
        case 0x1a6:
            return unit->genus == 1 && unit->charId == 0x10a;
        case 0x1a5:
            return unit->genus == 1 && unit->charId == 0x107;
        case 0x1a4:
            return unit->genus == 1 &&
                   (unit->charId == 0x106 || unit->charId == 0x105 ||
                    unit->charId == 0x115);
        case 0x1a3:
            return unit->genus == 1 && unit->charId == 0x104;
        case 0x1a2:
            return unit->genus == 1 && unit->charId == 0x103;
        case 0x1a1:
            return unit->genus == 1 &&
                   (unit->charId == 0x102 || unit->charId == 0x101);
        case 0x1a0:
            return unit->genus == 1 && unit->charId == 0x100;
        default:
            return 0;
    }
}

// FUN_002f8ea0
u32 func_002f8ea0(BtlUnit* unit, RwV3d* target)
{
    (void)unit;
    (void)target;
    return 0;
}

// FUN_002f8eb0 NONMATCHING
s16 func_002f8eb0(BtlUnit* unit, s16 index)
{
    s8 value;

    if (btlBossGetEncounterId() != 0x1ae ||
        unit->genus != 1 || unit->charId != 0x126)
    {
        return -1;
    }

    K_ASSERT((u16)index < 0x1d0, 417);
    value = *(s8*)((u8*)0x007CE3F4 + (u16)index * 2);
    if (value == 2)
    {
        return 6;
    }
    if (value == 1)
    {
        return 5;
    }
    if (value == 0)
    {
        return 4;
    }
    return -1;
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
            value = *(u16*)((u8*)0x007CE4B4 + (charId - 0x95) * 8 + i * 2);
            if (id == value)
            {
                return i == 3 ? 0x18 : i == 2 ? 0x17 : i == 1 ? 7 : 4;
            }
        }
        return 7;
    }
    return -1;
}

// FUN_002f9560 NONMATCHING
s16 func_002f9560(BtlUnit* unit, u16* flags)
{
    u16 encounterId;

    encounterId = btlBossGetEncounterId();
    if (encounterId == 0x1a8 && unit->genus == 1 && unit->charId == 0x10d)
    {
        return flags[1] == 0x19 ? 0 : -1;
    }
    if (encounterId == 0x1a5 && unit->genus == 1 && unit->charId == 0x107)
    {
        if (flags[1] == 0x17)
        {
            return 0;
        }
        return *(void**)((u8*)gBtl + 0xb44) == NULL ? -1 : 0xc;
    }
    return -1;
}

// FUN_002f9690 NONMATCHING
s16 func_002f9690(BtlUnit* unit)
{
    u16 encounterId;

    encounterId = btlBossGetEncounterId();
    return (encounterId >= 0x1af && encounterId <= 0x1b3 &&
            unit->genus == 1) ? 0 : -1;
}

extern void func_002ea780(void);
extern void func_002eeb70(void);
extern void func_00288f80(BtlUnit* unit, s32 value);
extern void func_002f3670(void);
extern void func_002f4490(void);
extern void func_002f4890(void);
extern void func_002f4c00(void);
extern void func_002f5330(void);
extern void func_002f5980(void);
extern void func_002e4220(u32 begin, u32 end, void* action);
extern s32 func_002e4250(void);
extern void func_002f5bf0(void);
extern void func_002ec190(void);
extern void func_002d3fe0(BtlUnit* unit);
extern void func_002831c0(BtlUnit* unit, s32 value);
extern void func_00282d40(f32 value, BtlUnit* unit, s16 value2, s32 value3, s8 value4);
extern void func_00287510(BtlUnit* unit);
extern void func_0027f650(BtlUnit* unit, u32 value);
extern void func_002ef5a0(void);
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
            func_002ea780();
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
            func_002eeb70();
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
            func_002f3670();
            return 1;
        case 0x1ae:
            func_002f4490();
            return 1;
        case 0x1af:
            func_002f4890();
            return 0;
        case 0x1b0:
            func_002f4c00();
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

// FUN_002fa240 NONMATCHING
u32 func_002fa240()
{
    switch (btlBossGetEncounterId())
    {
        case 0x1b4: func_002f5a70(); return 1;
        case 0x1b1:
        case 0x1b2:
        case 0x1b3: func_002f5490(); return 1;
        case 0x1b0: func_002f4ce0(); return 1;
        case 0x1af: func_002f4950(); return 1;
        case 0x1ae: func_002f4540(); return 1;
        case 0x1ad: func_002f3760(); return 1;
        case 0x1ac: func_002f2250(); return 1;
        case 0x1ab: func_002f1f00(); return 1;
        case 0x1aa: func_002f19d0(); return 1;
        case 0x1a9: func_002f1680(); return 1;
        case 0x1a8: func_002ef360(); return 1;
        case 0x1a7: func_002eec60(); return 1;
        case 0x1a6: func_002ec5c0(); return 1;
        case 0x1a5: func_002ec000(); return 1;
        case 0x1a4: func_002ea860(); return 1;
        case 0x1a3: func_002ea400(); return 1;
        case 0x1a2: func_002ea060(); return 1;
        case 0x1a1: func_002e9950(); return 1;
        case 0x1a0: func_002e92c0(); return 1;
        case 0x1c8: func_002e9170(); return 1;
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

// FUN_002faa50 NONMATCHING
void func_002faa50()
{
    if (btlBossGetEncounterId() == 0x1b4)
    {
        func_002f5bf0();
    }
    else if (btlBossGetEncounterId() == 0x1a5)
    {
        func_002ec190();
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
extern s16 func_002f6c50(u16 charId);
extern s32 func_00300580(u32 persona, s32 value);
extern s32 func_00301750(u32 persona, s32 value);
extern s32 func_0030b5e0(u32 persona);

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
    switch (btlBossGetEncounterId())
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

// FUN_002fb690 NONMATCHING
u32 func_002fb690()
{
    switch (btlBossGetEncounterId())
    {
        case 0x1b4: func_002f6120(); return 1;
        case 0x1b0: func_002f4e70(); return 1;
        case 0x1af: func_002f4a40(); return 1;
        case 0x1ae: func_002f46d0(); return 1;
        case 0x1ad: func_002f3840(); return 1;
        case 0x1ab: func_002f2090(); return 1;
        case 0x1aa: func_002f1d40(); return 1;
        case 0x1a9: func_002f1810(); return 1;
        case 0x1a8: func_002ef7e0(); return 1;
        case 0x1a5: func_002ec2c0(); return 1;
        case 0x1a3: func_002ea590(); return 1;
        case 0x1a2: func_002ea210(); return 1;
        case 0x1a0: func_002e95f0(); return 1;
        default: return 0;
    }
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

// FUN_002fc410 NONMATCHING
void* func_002fc410(BtlUnit* unit)
{
    if (btlBossGetEncounterId() == 0x1b4 && unit->genus == 1 && unit->charId == 0xf1 &&
        *(u32*)((u8*)gBtl + 0xb48) == 1)
    {
        return (void*)0x0069a5a8;
    }
    if (btlBossGetEncounterId() == 0x1a8 && unit->genus == 1 && unit->charId == 0x10d &&
        *(u32*)((u8*)gBtl + 0xb54) == 1)
    {
        return (void*)0x0069a0e8;
    }
    return NULL;
}

// FUN_002fc520 NONMATCHING
void* func_002fc520(BtlUnit* unit)
{
    s16 animation;

    if (unit->genus != 1)
    {
        return NULL;
    }
    animation = func_002f6c50(unit->charId);
    if (animation == -1 || animation == 0x15 || animation == 0x14)
    {
        return NULL;
    }
    return (u8*)(*(u32*)0x007CE4C0) + animation * 0xc + 2;
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
        case 0xf1: return base + 550.0f;
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

  short sVar1;

  u32 uVar2;

  

  switch(*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8)) {

  case 0x1a7:

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      sVar1 = *(short *)(*(int *)(param_1 + 0x30) + 0xa4);

      if ((sVar1 == 0x10c) || (sVar1 == 0x10b)) {

        *param_2 = *(u32 *)(DAT_007ce3ec + 0xb44);

        param_2[1] = *(u32 *)(DAT_007ce3ec + 0xb48);

        param_2[2] = *(u32 *)(DAT_007ce3ec + 0xb4c);

        uVar2 = 1;

      }

      else {

        uVar2 = 0;

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

// FUN_002FCF50 NONMATCHING


u32 FUN_002fcf50(int param_1)



{

  short sVar1;

  u32 uVar2;

  

  sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

  if (sVar1 == 0x1b0) {

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xea) {

        uVar2 = *(u32 *)(DAT_007ce3ec + 0xb50);

      }

      else {

        uVar2 = 0;

      }

    }

    else {

      uVar2 = 0;

    }

  }

  else if (sVar1 == 0x1ae) {

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x126) {

        uVar2 = *(u32 *)(DAT_007ce3ec + 0xb50);

      }

      else {

        uVar2 = 0;

      }

    }

    else {

      uVar2 = 0;

    }

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}

// FUN_002FD060 NONMATCHING


u32 FUN_002fd060(int param_1)



{

  short sVar1;

  u32 uVar2;

  

  sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

  if (sVar1 == 0x1b4) {

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xf1) {

        uVar2 = *(u32 *)(DAT_007ce3ec + 0xb44);

      }

      else {

        uVar2 = 0;

      }

    }

    else {

      uVar2 = 0;

    }

  }

  else if (sVar1 == 0x1ad) {

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      if (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x112) {

        uVar2 = *(u32 *)(DAT_007ce3ec + 0xb44);

      }

      else {

        uVar2 = 0;

      }

    }

    else {

      uVar2 = 0;

    }

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}

// FUN_002FD160 NONMATCHING


u32 FUN_002fd160(int param_1)



{

  char cVar1;

  u32 uVar2;

  

  if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1ac) {

    if ((*(u16 *)(param_1 + 0x1a) & 1) == 0) {

      uVar2 = 0;

    }

    else if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01') {

      cVar1 = FUN_00301750(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),0xb);

      if (cVar1 < '\x01') {

        uVar2 = 0;

      }

      else {

        uVar2 = *(u32 *)(DAT_007ce3ec + 0xb44);

      }

    }

    else {

      uVar2 = 0;

    }

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}

// FUN_002FD220 NONMATCHING


u8 FUN_002fd220(int param_1,int param_2)



{

  u8 bVar1;

  int iVar2;

  long lVar3;

  

  if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1a5) {

    lVar3 = FUN_0030af00(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),

                         *(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));

    if (lVar3 == 0) {

      bVar1 = 0;

    }

    else {

      if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1a5) {

        iVar2 = *(int *)(DAT_007ce3ec + 0xb44);

      }

      else {

        iVar2 = 0;

      }

      if (iVar2 == 0) {

        bVar1 = 0;

      }

      else {

        bVar1 = *(int *)(DAT_007ce3ec + 0xb48) == 0;

      }

    }

  }

  else {

    bVar1 = 0;

  }

  return bVar1;

}

// FUN_002FD2E0 NONMATCHING


u32 FUN_002fd2e0(int param_1,u16 param_2)



{

  u32 uVar1;

  u64 uVar2;

  u64 uVar3;

  int iVar4;

  

  iVar4 = (int)(uintptr_t)(DAT_007ce3ec + (u32)param_2 * 4);

  if ((*(int *)(iVar4 + 0xb2c) == *(int *)(param_1 + 8)) &&

     (*(int *)(iVar4 + 0xb38) == *(int *)(param_1 + 0x20))) {

    uVar1 = 0;

  }

  else {

    if (param_2 == 2) {

      if (*(int *)(DAT_007ce3ec + 0xb24) == -1) {

        return 0;

      }

    }

    else if (param_2 == 1) {

      if (*(int *)(DAT_007ce3ec + 0xb20) == -1) {

        return 0;

      }

    }

    else if ((param_2 == 0) && (*(int *)(DAT_007ce3ec + 0xb1c) == -1)) {

      return 0;

    }

    uVar2 = FUN_0035bb40(*(int *)(*(int *)(DAT_007ce3ec + 0xd18) + 0x20) + -1,DAT_007ce4d0);

    FUN_0035c1a0(uVar2,*(u32 *)(DAT_007ce3ec + 0x148));

    iVar4 = FUN_0035ae10(uVar2);

    if (-1 < *(int *)(iVar4 + 0xcc)) {

      uVar3 = FUN_001778b0(1);

      FUN_003a4220(*(u32 *)(iVar4 + 0xcc),0,uVar3);

    }

    FUN_00195550(*(u32 *)(DAT_007ce3ec + 0xd18),uVar2);

    *(int *)(DAT_007ce3ec + 0xb28) = (int)uVar2;

    *(u32 *)((u32)param_2 * 4 + DAT_007ce3ec + 0xb2c) = *(u32 *)(param_1 + 8);

    *(u32 *)((u32)param_2 * 4 + DAT_007ce3ec + 0xb38) = *(u32 *)(param_1 + 0x20);

    uVar1 = 1;

  }

  return uVar1;

}

// FUN_002FD4A0 NONMATCHING


u32 FUN_002fd4a0(void)



{

  u32 uVar1;

  long lVar2;

  

  if (*(int *)(DAT_007ce3ec + 0xb28) == 0) {

    uVar1 = 0;

  }

  else {

    lVar2 = FUN_00195460();

    if (lVar2 == 0) {

      *(u32 *)(DAT_007ce3ec + 0xb28) = 0;

      uVar1 = 0;

    }

    else {

      uVar1 = 1;

    }

  }

  return uVar1;

}

// FUN_002FD500


u8 FUN_002fd500(void)



{

  return *(int *)(DAT_007ce3ec + 0xb28) != 0;

}

// FUN_002FD520 NONMATCHING


void FUN_002fd520(int param_1)



{

  u8 bVar1;

  short sVar2;

  char *pcVar3;

  

  sVar2 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

  if (sVar2 == 0x1b4) {

    FUN_002f5d80();

  }

  else if (sVar2 == 0x1ac) {

    if ((*(char *)(param_1 + 0xa2) == '\x01') && ((*(u32 *)(param_1 + 0x98) & 2) != 0)) {

      if (*(int *)(DAT_007ce3ec + 0xb50) == 0) {

        pcVar3 = (char *)(*(int *)(param_1 + 0x9f4) + 0x41d);

        bVar1 = *(u8 *)(*(int *)(param_1 + 0x9f4) + 0x41d);

        if (bVar1 < 0x21) {

          *pcVar3 = '\0';

        }

        else {

          *pcVar3 = bVar1 - 0x20;

        }

      }

      else {

        pcVar3 = (char *)(*(int *)(param_1 + 0x9f4) + 0x41d);

        bVar1 = *(u8 *)(*(int *)(param_1 + 0x9f4) + 0x41d);

        if (bVar1 < 0xdf) {

          *pcVar3 = bVar1 + 0x20;

        }

        else {

          *pcVar3 = -1;

        }

      }

    }

  }

  else if (sVar2 == 0x1a8) {

    FUN_002efb40();

  }

  else if (sVar2 == 0x1a6) {

    FUN_002ec990();

  }

  else if (sVar2 == 0x1a5) {

    FUN_002ec4b0();

  }

  return;

}

// FUN_002FD660 NONMATCHING


u64 FUN_002fd660(void)



{

  short sVar1;

  long lVar2;

  u64 uVar3;

  int iVar4;

  

  sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

  if (sVar1 == 0x1b4) {

    for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {

      if ((*(short *)(iVar4 + 0xa4) == 0xf1) &&

         (lVar2 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0), lVar2 == 0)) {

        return 0;

      }

    }

    uVar3 = 1;

  }

  else if (sVar1 == 0x1a8) {

    uVar3 = FUN_002ef9d0();

  }

  else if (sVar1 == 0x1a4) {

    for (iVar4 = *(int *)(DAT_007ce3ec + 0x158); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xa34)) {

      if (((*(short *)(iVar4 + 0xa4) == 0x106) || (*(short *)(iVar4 + 0xa4) == 0x105)) &&

         (lVar2 = FUN_0030b5a0(*(u32 *)(iVar4 + 0xa2c),0), lVar2 == 0)) {

        return 0;

      }

    }

    uVar3 = 1;

  }

  else if (sVar1 == 0x1a0) {

    uVar3 = FUN_002e97e0();

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

// FUN_002FD7C0 NONMATCHING


u32 FUN_002fd7c0(void)



{

  short sVar1;

  u32 uVar2;

  

  if (*(int *)(DAT_007ce3ec + 0xbbc) == 0) {

    uVar2 = 0;

  }

  else {

    sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

    if ((sVar1 == 0x1ad) || (sVar1 == 0x1c8)) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

    }

  }

  return uVar2;

}

// FUN_002FD820 NONMATCHING


void FUN_002fd820(void)



{

  if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1ad) {

    if (3 < *(u16 *)(DAT_007ce3ec + 0xb48)) {

      FUN_001fece0();

      FUN_001fee20();

    }

    FUN_001fed60();

    FUN_001feda0();

    FUN_001fee60();

    FUN_001fede0();

  }

  return;

}

// FUN_002FD8A0 NONMATCHING


void FUN_002fd8a0(int param_1)



{

  short sVar1;

  

  switch(*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8)) {

  case 0x1a7:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       ((sVar1 = *(short *)(*(int *)(param_1 + 0x30) + 0xa4), sVar1 == 0x10c || (sVar1 == 0x10b))))

    {

      FUN_00289860();

    }

    break;

  case 0x1a9:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x108)) {

      FUN_00289860();

    }

    break;

  case 0x1aa:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x10f)) {

      FUN_00289860();

    }

    break;

  case 0x1ab:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x110)) {

      FUN_00289860();

    }

    break;

  case 0x1ae:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0x126)) {

      FUN_00289860();

    }

    break;

  case 0x1af:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xe9)) {

      FUN_00289860();

    }

    break;

  case 0x1b0:

    if ((((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

        (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) &&

       (*(short *)(*(int *)(param_1 + 0x30) + 0xa4) == 0xea)) {

      FUN_00289860();

    }

    break;

  case 0x1b1:

  case 0x1b2:

  case 0x1b3:

    if (((*(u16 *)(param_1 + 0x1a) & 1) != 0) &&

       (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\x01')) {

      switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

      case 0xeb:

      case 0xec:

      case 0xed:

      case 0xee:

      case 0xef:

      case 0xf0:

        FUN_00289860();

      }

    }

  }

  return;

}

// FUN_002FDB70 NONMATCHING


u8 FUN_002fdb70(void)



{

  return (*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0;

}

// FUN_002FDB90 NONMATCHING


u8 FUN_002fdb90(void)



{

  return (*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0;

}

// FUN_002FDBB0 NONMATCHING


u8 FUN_002fdbb0(int param_1,u64 param_2)



{

  u16 uVar1;

  u64 uVar2;

  long lVar3;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) != 0) {

    uVar1 = *(u16 *)((int)param_2 + 0xa4);

    if ((*(u16 *)(DAT_007ce42c + ((u32)uVar1 * 10 + (u32)uVar1) * 8) & 1) != 0) {

      uVar2 = FUN_002d6290();

      lVar3 = FUN_002d63b0(param_2,*(u16 *)(param_1 + 0x6e),uVar2);

      return lVar3 == 0;

    }

    lVar3 = FUN_002d6290();

    if ((lVar3 == 0) &&

       (uVar1 = *(u16 *)((int)param_2 + 0xa4),

       (*(u16 *)(DAT_007ce42c + ((u32)uVar1 * 10 + (u32)uVar1) * 8) & 0x20) != 0)) {

      return 1;

    }

  }

  return 0;

}

// FUN_002FDCB0 NONMATCHING


u8 FUN_002fdcb0(int param_1)



{

  u8 bVar1;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {

    bVar1 = 0;

  }

  else {

    bVar1 = *(char *)(param_1 + 0xa2) == '\x01';

  }

  return bVar1;

}

// FUN_002FDCF0 NONMATCHING


u32 FUN_002fdcf0(int param_1,int param_2)



{

  u32 uVar1;

  

  if ((((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) || (*(char *)(param_1 + 0xa2) != '\x01'))

     || (*(char *)(param_2 + 0xa2) != '\x01')) {

    uVar1 = 1;

  }

  else {

    uVar1 = 0;

  }

  return uVar1;

}

// FUN_002FDD40 NONMATCHING


u8 FUN_002fdd40(long param_1,long param_2)



{

  char cVar1;

  u8 bVar2;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {

    bVar2 = 0;

  }

  else {

    cVar1 = *(char *)((int)param_1 + 0xa2);

    if (cVar1 == '\x01') {

      bVar2 = 0;

    }

    else if (param_1 == param_2) {

      bVar2 = 0;

    }

    else {

      bVar2 = cVar1 == *(char *)((int)param_2 + 0xa2);

    }

  }

  return bVar2;

}

// FUN_002FDDB0 NONMATCHING


void FUN_002fddb0(int param_1,float *param_2)



{

  *param_2 = (float)(*(short *)(param_1 + 0x94) * 0x19 + -0x6d6);

  param_2[1] = *(float *)(param_1 + 8);

  param_2[2] = (float)(*(short *)(param_1 + 0x96) * 0x19 + -0x6d6);

  param_2[2] = param_2[2] + *(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x2c) + 200.0;

  return;

}

// FUN_002FDE40 NONMATCHING


u64 FUN_002fde40(void)



{

  short sVar1;

  u64 uVar2;

  

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {

    uVar2 = 0;

  }

  else {

    sVar1 = *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);

    if (sVar1 == 0x1aa) {

      uVar2 = FUN_002f1b60();

    }

    else if (sVar1 == 0x1a7) {

      uVar2 = FUN_002eee20();

    }

    else {

      uVar2 = 0;

    }

  }

  return uVar2;

}

// FUN_002FDED0 NONMATCHING


u32 FUN_002fded0(short param_1)



{

  u32 uVar1;

  

  if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {

    if ((((param_1 == 0x126) || (param_1 == 0x128)) || (param_1 == 0x127)) || (param_1 == 0x125)) {

      *(int *)(DAT_007ce3ec + 0xb5c) = (int)param_1;

    }

    else {

      *(u32 *)(DAT_007ce3ec + 0xb5c) = 0xffffffff;

    }

    if (((param_1 == 0x128) || (param_1 == 0x127)) || (param_1 == 0x125)) {

      uVar1 = 0x2f6bc0;

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

// FUN_002FDFA0 NONMATCHING


u8 FUN_002fdfa0(void)



{

  return *(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4;

}

// FUN_002FDFE0 NONMATCHING


u32 FUN_002fdfe0(int param_1)



{

  int iVar1;

  int iVar2;

  long lVar3;

  

  if (*(short *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) == 0x1b4) {

    iVar1 = *(int *)(param_1 + 0xe0);

    iVar2 = *(int *)(iVar1 + 0x38);

    if ((((iVar2 != 0) && (*(short *)(iVar1 + 0x6a) == 1)) &&

        (lVar3 = FUN_002d6370(*(u16 *)(iVar1 + 0x6e)), lVar3 == 1)) &&

       (((lVar3 = FUN_003088b0(*(u16 *)(*(int *)(param_1 + 0xe0) + 0x6e)), lVar3 == 0 &&

         (iVar1 = *(int *)(iVar2 + 0x30), *(char *)(iVar1 + 0xa2) == '\x01')) &&

        (*(short *)(iVar1 + 0xa4) == 0xf1)))) {

      return 1;

    }

  }

  return 0;

}





































// FUN_002FE0B0 NONMATCHING
void FUN_002fe0b0(float param_1,u8 *param_2,u64 param_3,u64 param_4,

                 u64 param_5)



{

  int iVar1;

  u64 uVar2;

  float fVar3;

  float fVar4;

  float fStack_100;

  float fStack_fc;

  u32 uStack_f8;

  u32 uStack_f0;

  u32 uStack_ec;

  float fStack_e8;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_c0;

  float fStack_bc;

  u32 uStack_b8;

  u32 uStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_80;

  float fStack_7c;

  u32 uStack_78;

  float fStack_70;

  u32 uStack_6c;

  float fStack_68;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_40;

  float fStack_3c;

  u32 uStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  iVar1 = FUN_00198590();

  uVar2 = FUN_004e3630();

  fStack_80 = 640.0;

  fStack_70 = 640.0 / (float)*(int *)((int)uVar2 + 0xc);

  fStack_bc = 448.0;

  fStack_ac = 448.0 / (float)*(int *)((int)uVar2 + 0x10);

  if (param_1 == 0.0) {

    fVar3 = 0.0;

    fVar4 = 0.0;

  }

  else {

    fVar3 = param_1 * -320.0 + DAT_007caf5c + 0.0;

    fVar4 = param_1 * -224.0 + DAT_007caf60 + 0.0;

    fStack_80 = param_1 * 320.0 + DAT_007caf5c + 0.0;

    fStack_bc = param_1 * 224.0 + DAT_007caf60 + 0.0;

  }

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(0x14,1);

  (*DAT_00960090)(0xe,0);

  (*DAT_00960090)(6,0);

  (*DAT_00960090)(8,0);

  (*DAT_00960090)(9,param_5);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(1,uVar2);

  FUN_004d7f60(2,param_3);

  FUN_004d7f60(3,param_4);

  fStack_e8 = 1.0 / *(float *)(iVar1 + 0x84);

  uStack_f8 = (u32)(uintptr_t)DAT_0096008c;

  fStack_e0 = (float)*param_2;

  fStack_dc = (float)param_2[1];

  fStack_d8 = (float)param_2[2];

  fStack_d4 = (float)param_2[3];

  uStack_f0 = 0;

  uStack_ec = 0;

  uStack_b8 = (u32)(uintptr_t)DAT_0096008c;

  fStack_a0 = (float)*param_2;

  fStack_9c = (float)param_2[1];

  fStack_98 = (float)param_2[2];

  fStack_94 = (float)param_2[3];

  uStack_b0 = 0;

  uStack_78 = (u32)(uintptr_t)DAT_0096008c;

  fStack_60 = (float)*param_2;

  fStack_5c = (float)param_2[1];

  fStack_58 = (float)param_2[2];

  fStack_54 = (float)param_2[3];

  uStack_6c = 0;

  uStack_38 = (u32)(uintptr_t)DAT_0096008c;

  fStack_20 = (float)*param_2;

  fStack_1c = (float)param_2[1];

  fStack_18 = (float)param_2[2];

  fStack_14 = (float)param_2[3];

  fStack_100 = fVar3;

  fStack_fc = fVar4;

  fStack_c0 = fVar3;

  fStack_a8 = fStack_e8;

  fStack_7c = fVar4;

  fStack_68 = fStack_e8;

  fStack_40 = fStack_80;

  fStack_3c = fStack_bc;

  fStack_30 = fStack_70;

  fStack_2c = fStack_ac;

  fStack_28 = fStack_e8;

  (*DAT_009600a0)(4,&fStack_100,4);

  (*DAT_00960090)(1,0);

  return;

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

  char cVar1;

  char *pcVar2;

  long lVar3;

  u32 uVar4;

  u32 uVar5;

  float fVar6;

  float fVar7;

  u32 uVar8;

  u32 auStack_30 [9];

  u8 uStack_c;

  u8 uStack_b;

  u8 uStack_a;

  u8 uStack_9;

  u8 uStack_8;

  u8 uStack_7;

  u8 uStack_6;

  u8 uStack_5;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  uVar5 = 0;

  for (uVar4 = 0; uVar4 < 7; uVar4 = uVar4 + 1) {

    (*DAT_00960094)(DAT_0069aa50[uVar4],auStack_30 + uVar4);

  }

  pcVar2 = *(char **)(param_1 + 0x3c);

  cVar1 = *pcVar2;

  if (cVar1 == '\x03') {

    lVar3 = FUN_00108710();

    if (lVar3 != 0) {

      FUN_001085c0();

      DAT_007ce508 = 0;

      uVar5 = 0xffffffff;

    }

    goto LAB_002ff1b4;

  }

  if (cVar1 != '\x02') {

    if (cVar1 != '\x01') goto LAB_002ff1b4;

    if (DAT_007ce50c == 0) {

      DAT_007ce50a = DAT_007ce50a + 1;

      fVar7 = (float)DAT_007ce50a / 20.0;

      (*DAT_00960090)(7,2);

      (*DAT_00960090)(0x14,1);

      (*DAT_00960090)(0xe,0);

      (*DAT_00960090)(6,0);

      (*DAT_00960090)(8,0);

      (*DAT_00960090)(0xc,1);

      (*DAT_00960090)(1,0);

      FUN_004d7f60(2,0x44);

      FUN_004d7f60(3,0x31801);

      FUN_003294d0();

      uStack_4 = 0xff;

      uStack_3 = 0xff;

      uStack_2 = 0xff;

      fVar6 = (1.0 - fVar7 * fVar7 * fVar7 * fVar7 * fVar7 * fVar7) * 255.0;

      if (fVar6 < 2.1474836e+09) {

        uStack_1 = (u8)(int)fVar6;

      }

      else {

        uStack_1 = (u8)(int)(fVar6 - 2.1474836e+09);

      }

      FUN_00358460(&uStack_4,0);

      uStack_8 = 0xff;

      uStack_7 = 0xff;

      uStack_6 = 0xff;

      fVar6 = (1.0 - fVar7 * fVar7) * 160.0;

      if (fVar6 < 2.1474836e+09) {

        uStack_5 = (u8)(int)fVar6;

      }

      else {

        uStack_5 = (u8)(int)(fVar6 - 2.1474836e+09);

      }

      uStack_c = 0xff;

      uStack_b = 0xff;

      uStack_a = 0xff;

      uStack_9 = uStack_1;


      FUN_00329550();


      if (0x13 < DAT_007ce50a) {

        *pcVar2 = '\x03';

      }

      goto LAB_002ff1b4;

    }

    DAT_007ce50c = DAT_007ce50c + -1;

  }


  uVar8 = DAT_007caf64;

  if (*(short *)(pcVar2 + 6) == 1) {

    uVar8 = DAT_007caee4;

  }

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  if (*(short *)(pcVar2 + 6) == 1) {

    uStack_1 = 0x10;

  }

  else {

    uStack_1 = 0x18;

  }


  uStack_1 = 5;


LAB_002ff1b4:

  for (uVar4 = 0; uVar4 < 7; uVar4 = uVar4 + 1) {

    (*DAT_00960090)(DAT_0069aa50[uVar4],auStack_30[uVar4]);

  }

  (*DAT_00960090)(1,0);

  FUN_004d7f60(2,0x44);

  FUN_004d7f60(3,0x717fb);

  return uVar5;

}
