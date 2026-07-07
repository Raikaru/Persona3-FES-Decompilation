#include "Battle/btlBoss.h"
#include "Battle/battle.h"
#include "h_cdvd.h"

extern const BtlCameraStateEntry gBtlBossCameraStateEntries[][BTLCAMERA_STATE_MAX];

// FUN_002f7dc0
void btlBoss002f7dc0()
{
    // TODO
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
        return true;
    }

    if (H_Cdvd_IsFileLoaded(gBtl->bossPakCdvd))
    {
        btlBoss002f7dc0();

        return true;
    }

    return false;
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