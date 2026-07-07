#include "Battle/btlSound.h"
#include "Battle/battle.h"
#include "Battle/btlPacket.h"
#include "Main/g_data.h"
#include "h_snd.h"
#include "h_cdvd.h"
#include "temporary.h"

void H_Snd_FUN_00109ae0(s32 param_1, void* param_2, u32 param_3, void* param_4, u32 param_5, void* param_6, u32 param_7);
u32 H_Snd_FUN_00109df0();
void H_Snd_FUN_0010a0e0(s16 param_1, s16 param_2);

// FUN_002dcd30
void btlSoundPlayBgm()
{
    BtlEncountTable* encount;

    if (gBtl->flags & BTL_FLAG_UNK40)
    {
        encount = &gEncountTbl[gBtl->startInfo.enmUnits->encountId];

        switch (encount->bgm)
        {
            case BTLENCOUNT_BGM_FULLMOON:     H_Snd_PlayBgm(HSND_BGM_MASTER_OF_SHADOW, 1);    break;
            case BTLENCOUNT_BGM_STREGA:       H_Snd_PlayBgm(HSND_BGM_UNAVOIDABLE_BATTLE, 1);  break;
            case BTLENCOUNT_BGM_TARTARUSBOSS: H_Snd_PlayBgm(HSND_BGM_MASTER_OF_TARTARUS, 1);  break;
            case BTLENCOUNT_BGM_NYX:          H_Snd_PlayBgm(HSND_BGM_BURN_MY_DREAD_LAST, 1);  break;
            case BTLENCOUNT_BGM_NYXAVATAR:    H_Snd_PlayBgm(HSND_BGM_BATTLE_HYMN_OF_SOUL, 1); break;
            case BTLENCOUNT_BGM_SEES:         H_Snd_PlayBgm(HSND_BGM_HEARTFUL_CRY, 1);        break;
            case BTLENCOUNT_BGM_EREBUS:       H_Snd_PlayBgm(HSND_BGM_DARKNESS, 1);            break;

            default:
                if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                {
                    H_Snd_PlayBgm(HSND_BGM_MASS_DESTRUCTION, 1);
                }
                else
                {
                    H_Snd_PlayBgm(HSND_BGM_MASS_DESTRUCTION_FES, 1);
                }
        }
    }
}

// FUN_002dd270
void btlSoundInitSkillSEPacket(void* work)
{
    BtlSoundPacketSkillSE* packet;
    char buffer[128];

    packet = (BtlSoundPacketSkillSE*)work;

    if (!(packet->flags & BTLSOUND_SKILLSE_FLAG_UNK01))
    {
        sprintf(buffer, "%s%03X.se", "skill/", packet->skillId);
        packet->cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }
    else
    {
        packet->cdvd = NULL;
    }

    packet->state = 1;
    packet->timer = 0;
}

// FUN_002dd2f0
u32 btlSoundUpdateSkillSEPacket(void* work)
{
    BtlSoundPacketSkillSE* packet;
    char buffer[128];
    void* file1;
    void* file2;
    void* file3;
    u32 file1Size;
    u32 file2Size;
    u32 file3Size;
    s32 i;

    packet = (BtlSoundPacketSkillSE*)work;

    if (packet->cdvd == NULL)
    {
        sprintf(buffer, "%s%03X.se", "skill/", packet->skillId);
        packet->cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }

    asm volatile("lhu $3, 6(%0)" : : "r" (packet));
    asm volatile("addiu $4, $0, 2");
    asm volatile("beq $3, $4, state2");
    asm volatile("addiu $2, $0, 1");
    asm volatile("beq $3, $2, state1");
    asm volatile("b increment");

state1:
    if (!H_Cdvd_IsFileLoaded(packet->cdvd))
    {
        return false;
    }

    H_Snd_FUN_0010a0e0(2, 4);

    for (i = 5; i <= 9; i++)
    {
        H_Snd_FUN_0010a0e0(2, i);
    }

    file1 = H_Cdvd_ArchiveGetFile(packet->cdvd, 0, &file1Size);
    file2 = H_Cdvd_ArchiveGetFile(packet->cdvd, 1, &file2Size);
    file3 = H_Cdvd_ArchiveGetFile(packet->cdvd, 2, &file3Size);

    H_Snd_FUN_00109ae0(2, file1, file1Size, file2, file2Size, file3, file3Size);

    packet->state = 2;
    goto increment;

state2:
    if (!H_Snd_FUN_00109df0())
    {
        return false;
    }

    H_Cdvd_Destroy(packet->cdvd);
    return true;

increment:
    packet->timer++;

    return false;
}

// FUN_002dd4a0
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = btlPacketCreate(BTLSOUND_PACKET_SKILLSE, sizeof(BtlSoundPacketSkillSE));

    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = btlSoundInitSkillSEPacket;
    packet->updateFunc = btlSoundUpdateSkillSEPacket;

    work = (BtlSoundPacketSkillSE*)packet->workData;

    work->skillId = skillId;
    work->flags = flags;

    return packet;
}