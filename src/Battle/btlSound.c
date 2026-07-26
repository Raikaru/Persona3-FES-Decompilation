#include "Battle/btlSound.h"
#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Battle/btlPacket.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datCalc.h"
#include "h_snd.h"
#include "h_cdvd.h"
#include "temporary.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_002dd8e0(u32 param_1);
void FUN_002dd960(u32 param_1);
u32 FUN_002dddc0(int param_1);
u32 FUN_002ddf10(int param_1);
u32 FUN_002de030(int param_1);
u32 FUN_002de150(int param_1);
u32 FUN_002de2a0(int param_1);
u32 FUN_002de3c0(int param_1);
u32 FUN_002de4e0(int param_1);
u32 FUN_002ded60(int param_1);
u32 FUN_002defe0(int param_1);
u32 FUN_002e0350(int param_1);
u32 FUN_002e0540(int param_1);
int FUN_002e0620(int param_1,int param_2);
u32 FUN_002e0f70(int param_1, int param_2, int param_3);
u32 FUN_002e12d0(int param_1);
u32 FUN_002e1500(int param_1,u32 param_2);
u32 FUN_002e1bf0(int param_1);
u32 FUN_002e1cd0(int param_1);
u32 FUN_002e1df0(int param_1);
u32 FUN_002e1f10(int param_1);
u32 FUN_002e2030(int param_1);
u32 FUN_002e2110(int param_1);
u32 FUN_002e22a0(int param_1);
u32 FUN_002e2410(int param_1);
u32 FUN_002e2560(int param_1);
u32 FUN_002e2630(int param_1);
u32 FUN_002e2680(int param_1);
u32 FUN_002e2920(int *param_1);
void FUN_002e2a10(void);
u32 FUN_002e2a60(int *param_1);
extern char gp0xffff9c90[5];
extern char DAT_00697bb0[15];
extern char DAT_00697bc0[];
extern u32 DAT_00697be0;
extern u32 DAT_00697be4;
extern u32 DAT_00697be8;
extern u8 DAT_00697BE0_abs[];
#pragma alias DAT_00697BE0_abs DAT_00697BE0
extern u8 DAT_00697BE8_abs[];
#pragma alias DAT_00697BE8_abs DAT_00697BE8
extern u8 DAT_00697BEC_abs[];
#pragma alias DAT_00697BEC_abs DAT_00697BEC
extern u8 DAT_00697BF4_abs[];
#pragma alias DAT_00697BF4_abs DAT_00697BF4
extern u8 DAT_00697BF8_abs[];
#pragma alias DAT_00697BF8_abs DAT_00697BF8
extern u8 DAT_00697BFC_abs[];
#pragma alias DAT_00697BFC_abs DAT_00697BFC
extern u8 DAT_00697be4_abs[];
#pragma alias DAT_00697be4_abs DAT_00697be4
extern u32 DAT_00697bec;
extern u32 DAT_00697bf4;
extern u32 DAT_00697bf8;
extern u32 DAT_00697bfc;
extern u32 DAT_00697c00;
extern u8 DAT_00697c00_abs[];
#pragma alias DAT_00697c00_abs DAT_00697c00
extern code DAT_00697c10[];
extern u8* DAT_007ce3ec;
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern char LAB_002dd8b0[];
extern char LAB_002dd930[];
extern code* PTR_LAB_007b87e0;
extern int iGpffffb6fc;

extern u32 func_00523ac8(void* buffer, const void* format, ...);
extern u32 func_00524388(const char* text);
extern u32 func_0053c268(s32 channel);
extern void* (*jtbl_00960178)(u32 size, u32 heap);
extern s32 func_0016f190(u32 flag);
extern u32 func_00357fd0(void* state);
extern u32 func_00300580(void* unit, u32 flags);
extern u32 func_0030b5a0(void* unit, u32 flags);
extern u32 func_002ffd70(void* unit);
extern u32 func_0017d800(void);
extern u32 func_002ffbc0(u32 max);
extern u32 func_002ffdf0(void* unit);
extern u32 func_002d4e10(u32 genusMask, u32 flags);
extern void func_0031f6d0(void* model, u16 a, u16 b, u16 c);
extern void func_001024a0(void* source, const char* path, s32 flags, void* callback);
extern void* func_001016b0(void* resource);
extern void* func_00102100(void* resource, s32 index, u32* size);
extern void func_00100ec0(void* resource);
extern u32 effMiscRand(void* state);
extern s32 DAT_00697BE0;
extern s32 DAT_00697BE4;
extern s32 DAT_00697BE8;
extern s32 DAT_00697BEC;
extern s32 DAT_00697BF4;
extern s32 DAT_00697BF8;
extern s32 DAT_00697BFC;
extern s32 DAT_00697C00;
extern s32 DAT_00697C10[];
extern s32 DAT_00697BD8[];
extern s32 DAT_007CE4FC;
extern s32 DAT_007CE500;
extern s32 iGpffffb80c;
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
    BtlSoundPacketSkillSE* packet = (BtlSoundPacketSkillSE*)work;
    char buffer[128];
    void* file1;
    void* file2;
    void* file3;
    u32 file1Size;
    u32 file2Size;
    u32 file3Size;
    s32 i;

    if (packet->cdvd == NULL)
    {
        sprintf(buffer, "%s%03X.se", "skill/", packet->skillId);
        packet->cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }

    switch (packet->state)
    {
    case 1:
        if (!H_Cdvd_IsFileLoaded(packet->cdvd))
        {
            return 0;
        }

        H_Snd_FUN_0010a0e0(2, 4);
        for (i = 5; i <= 9; i++)
        {
            H_Snd_FUN_0010a0e0(2, (s16)i);
        }

        file1 = H_Cdvd_ArchiveGetFile(packet->cdvd, 0, &file1Size);
        file2 = H_Cdvd_ArchiveGetFile(packet->cdvd, 1, &file2Size);
        file3 = H_Cdvd_ArchiveGetFile(packet->cdvd, 2, &file3Size);
        H_Snd_FUN_00109ae0(2, file1, file1Size, file2, file2Size, file3, file3Size);
        packet->state = 2;
        break;
    case 2:
        if (!H_Snd_FUN_00109df0(2))
        {
            return 0;
        }

        H_Cdvd_Destroy(packet->cdvd);
        return 1;
    }

    packet->timer++;
    return 0;
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
/* The following packet producers share the battle sound channel table at
 * Battle+0xa90.  Keep the work layouts byte-oriented: these packets are
 * allocated by the retail scheduler and are not C structs elsewhere. */
typedef struct BtlSoundThreeCueWork
{
    u16 channel;
    u16 pad;
    u32 streamData;
    u32 parameter;
} BtlSoundThreeCueWork;
typedef struct BtlSoundThreeCueWorkView
{
    s16 channel;
    void* streamData;
    s16 parameter;
} BtlSoundThreeCueWorkView;

static u8 btlSoundHasFlag(s32 flag)
{
    return flag != -1 && datGetFlag(flag) != 0;
}

static BtlUnit* btlSoundActionUnit(const BtlAction* action)
{
    return action == NULL ? NULL : action->unit;
}

static s32 btlSoundActionGenus(const BtlAction* action)
{
    BtlUnit* unit = btlSoundActionUnit(action);
    return unit == NULL ? -1 : unit->genus;
}

static s32 btlSoundActionCharId(const BtlAction* action)
{
    BtlUnit* unit = btlSoundActionUnit(action);
    return unit == NULL ? -1 : unit->charId;
}

// FUN_002dce90
void func_002dce90(void)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        H_Snd_StopBgm();
    }
}

// FUN_002dced0
void btlSound002dced0(u16 fadeDuration)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        H_Snd_StopBgmFade(fadeDuration);
    }
}

// FUN_002dcf10
void FUN_002dcf10(void)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        func_00109f60(2, 0);
        func_00109f60(3, 0);
        func_00109f60(4, 0);
        H_Snd_StopBgm();
    }
}

// FUN_002dcf80
void btlSound002dcf80(s16 channel, s32 fadeFrames)
{
    func_0010a100(channel, 0, (u16)fadeFrames);
}

// FUN_002dcfb0
void func_002dcfb0(u16* work)
{
    uintptr_t address;
    u8* slot;

    address = (u32)work[0] * 6;
    address += (uintptr_t)gBtl;
    slot = (u8*)address;
    if (*(s16*)(slot + 0xa94) != work[1] || *(s16*)(slot + 0xa96) != work[2])
    {
        H_Snd_FUN_0010a0e0(1, (s16)work[0]);
    }
}

// FUN_002dd020
u32 func_002dd020(u16* work)
{
    u16 channel;
    u16 expectedCue;
    uintptr_t address;
    u8* slot;
    expectedCue = work[1];
    channel = work[0];
    address = (u32)channel * 6;
    address += (uintptr_t)gBtl;
    slot = (u8*)address;
    if (*(s16*)(slot + 0xa94) != expectedCue || *(s16*)(slot + 0xa96) != work[2])
    {
        func_0010a4e0(1, (s16)channel, (s16)expectedCue, (s16)work[2]);
        {
            u16 value;
            u32 base;

            value = work[1];
            base = (u32)gBtl;
            ((u16*)((u8*)base + 0xa94))[work[0] * 3] = value;
        }
        {
            u16 value;
            u32 base;

            value = work[2];
            base = (u32)gBtl;
            ((u16*)((u8*)base + 0xa96))[work[0] * 3] = value;
        }
        {
            u32 base;

            base = (u32)gBtl;
            ((u8*)((u8*)base + 0xa98))[work[0] * 6] = 0;
        }
    }
    return 1;
}

// FUN_002dd100
void func_002dd100(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet = btlPacketCreate(0x902, 6);
    u16* work;

    packet->initFunc = (BtlPacketInitFunc)func_002dcfb0;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd020;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}

// FUN_002dd180
void func_002dd180(u16* work)
{
    H_Snd_FUN_0010a0e0(0, (s16)*work);
}

// FUN_002dd1b0
u32 func_002dd1b0(s16* work)
{
    func_0010a4e0(0, work[0], work[1], work[2]);
    return 1;
}

// FUN_002dd1f0
void func_002dd1f0(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet = btlPacketCreate(0x901, 6);
    u16* work;

    packet->initFunc = (BtlPacketInitFunc)func_002dd180;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd1b0;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}

// FUN_002dd510
u32 func_002dd510(u16* work)
{
    u16 state = *work;

    switch (state)
    {
    case 0:
        func_0010a4e0(2, 4, 0, (s16)state);
        break;
    case 1:
        if (*(s8*)((u8*)gBtl + 0xa92) == -1)
        {
            u16 nextState;
            func_0010a4e0(2, *(s16*)((u8*)gBtl + 0xa90), 0, (s16)state);
            *(u8*)((u8*)gBtl + 0xa92) = 0;
            nextState = ++(*(u16*)((u8*)gBtl + 0xa90));
            if (nextState >= 9)
            {
                *(u16*)((u8*)gBtl + 0xa90) = 5;
            }
        }
        break;
    default:
        break;
    }
    return 1;
}

// FUN_002dd5e0
void func_002dd5e0(u16 state)
{
    BtlPacket* packet = btlPacketCreate(0x904, 2);
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd510;
    *(u16*)packet->workData = state;
}

// FUN_002dd630
u32 func_002dd630(u16* work)
{
    char path[512];
    func_00523ac8(path, gp0xffff9c90, DAT_00697bb0,
                  *(u32*)(work + 2));
    func_0010a370((s16)*work, path);
    return 1;
}

// FUN_002dd690
BtlPacket* func_002dd690(u16 channel, const char* streamName)
{
    u32 length = func_00524388(streamName);
    BtlPacket* packet = btlPacketCreate(0x905, length + 8);
    u8* work;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd630;
    work = (u8*)packet->workData;
    *(u16*)work = channel;
    *(char**)(work + 4) = (char*)(work + 8);
    strcpy((char*)work + 8, streamName);
    return packet;
}

// FUN_002dd720
u32 func_002dd720(BtlSoundThreeCueWorkView* work)
{
    volatile s16* parameterPtr = &work->parameter;
    func_0010a240(work->channel, work->streamData, *parameterPtr);
    return 1;
}

// FUN_002dd760
void func_002dd760(u16 channel, void* streamData, u32 parameter)
{
    BtlPacket* packet = btlPacketCreate(0x907, 0xc);
    BtlSoundThreeCueWork* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd720;
    work = (BtlSoundThreeCueWork*)packet->workData;
    work->channel = channel;
    work->streamData = (u32)(uintptr_t)streamData;
    work->parameter = parameter;
}

// FUN_002dd7d0
u32 func_002dd7d0(u16* work)
{
    BtlUnit* unit = *(BtlUnit**)work;
    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) == 0)
    {
        return 1;
    }
    func_0031f6d0((u8*)unit->mdl + 0x3f8,
                  work[2], work[3], work[4]);
    return 1;
}

// FUN_002dd830
void func_002dd830(BtlUnit* unit, u16 a, u16 b, u16 c)
{
    BtlPacket* packet = btlPacketCreate(0x908, 0xc);
    void* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd7d0;
    work = packet->workData;
    *(BtlUnit**)work = unit;
    *(u16*)((u8*)work + 4) = a;
    *(u16*)((u8*)work + 6) = b;
    *(u16*)((u8*)work + 8) = c;
}

// FUN_002DD8B0 (retail callback; no standalone inventory marker)
u32 func_002DD8B0(void** work)
{
    BtlUnit* unit = (BtlUnit*)work[0];
    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) != 0)
    {
        u16* flags = (u16*)((u8*)unit->mdl + 0x3fe);
        *flags |= 0x20;
    }
    return 1;
}
// FUN_002dd9b0
void func_002dd9b0(void)
{
    char path[256];
    void* (**allocate)(u32 size, u32 heap);
    u32 state;
    void* memory;

    allocate = (void* (**)(u32, u32))DAT_00960178_abs;
    memory = (*allocate)(0xacc, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c2, 1);
    func_001024a0((void*)(uintptr_t)3, path, 0, memory);
    goto btlSound_status1;
btlSound_retry1:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)3, path, 0, memory);
    }
btlSound_status1:
    state = func_0053c268(3);
    if (state != 3)
    {
        goto btlSound_retry1;
    }
    DAT_007CE4FC = 1;

    memory = (*allocate)(0x540, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c3, 1);
    func_001024a0((void*)(uintptr_t)4, path, 0, memory);
    goto btlSound_status2;
btlSound_retry2:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)4, path, 0, memory);
    }
btlSound_status2:
    state = func_0053c268(4);
    if (state != 3)
    {
        goto btlSound_retry2;
    }

    allocate = (void* (**)(u32, u32))(*allocate)(0xa0c, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c4, 1);
    func_001024a0((void*)(uintptr_t)5, path, 0, allocate);
    goto btlSound_status3;
btlSound_retry3:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)5, path, 0, allocate);
    }
btlSound_status3:
    state = func_0053c268(5);
    if (state != 3)
    {
        goto btlSound_retry3;
    }
    DAT_007CE500 = 1;
}

// FUN_002ddba0
void func_002ddba0(u32 id)
{
    func_0010a2e0((void*)(uintptr_t)*(u16*)((u8*)gBtl + 0xaf8), 4, id);
}

// FUN_002ddbe0
void func_002ddbe0(void)
{
    func_0010a100(4, 0, 8);
}

// FUN_002ddc10
u32 func_002ddc10(u32 unitId)
{
    u16 id;
    s32 flag;

    id = unitId;
    if (id < 2)
    {
        return 0;
    }
    flag = DAT_00697BD8[id];
    if (flag == -1)
    {
        return 0;
    }
    return datGetFlag(flag);
}

// FUN_002ddc80
u32 func_002ddc80(u16 charId)
{
    u32 result;

    switch (charId)
    {
    case 1:
        result = 0;
        break;
    case 2:
        result = datGetFlag(0x1357) == 0;
        break;
    case 3:
        result = datGetFlag(0x1358) == 0;
        break;
    case 4:
        result = datGetFlag(0x1359) == 0;
        break;
    case 5:
        result = datGetFlag(0x135a) == 0;
        break;
    case 7:
        result = datGetFlag(0x135b) == 0;
        break;
    case 8:
        result = datGetFlag(0x135c) == 0;
        break;
    case 9:
        result = datGetFlag(0x135d) == 0;
        break;
    case 10:
        result = datGetFlag(0x135e) == 0;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

/* Recovered battle-misc harvest: 0x002DD8E0-0x002E2A60 */
// FUN_002DD8E0


void FUN_002dd8e0(u32 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0027ec10(0x909,4);

  *(u8 **)(iVar1 + 0x6c) = (u8 *)LAB_002dd8b0;

  **(u32 **)(iVar1 + 0x78) = param_1;

  return;

}

// FUN_002DD930
int func_002DD930(int* param_1)
{
    int battleWork;

    if ((*(u32*)(*param_1 + 0x98) & 2) != 0)
    {
        battleWork = *(int*)(*param_1 + 0x9f4);
        *(u16*)(battleWork + 0x3fe) &= 0xffdf;
    }

    return 1;
}

// FUN_002DD960


void FUN_002dd960(u32 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0027ec10(0x90a,4);

  *(u8 **)(iVar1 + 0x6c) = (u8 *)LAB_002dd930;

  **(u32 **)(iVar1 + 0x78) = param_1;

  return;

}

// FUN_002DDDC0


u32 FUN_002dddc0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    lVar2 = FUN_0016f190(0x184);
    if (lVar2 == 0) {
        return 0xffffffff;
    }

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x92;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xdc : 0xdb;
        break;
    case 4:
        uVar1 = 0x148;
        break;
    case 5:
        uVar1 = 0x191;
        break;
    case 7:
        uVar1 = 0x1da;
        break;
    case 8:
        uVar1 = 0x223;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45d : 0x26c;
        break;
    case 10:
        uVar1 = 0x2ad;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DDF10


u32 FUN_002ddf10(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x93;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xde : 0xdd;
        break;
    case 4:
        uVar1 = 0x149;
        break;
    case 5:
        uVar1 = 0x192;
        break;
    case 7:
        uVar1 = 0x1db;
        break;
    case 8:
        uVar1 = 0x224;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45e : 0x26d;
        break;
    case 10:
        uVar1 = 0x2ae;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE030


u32 FUN_002de030(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x94;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe0 : 0xdf;
        break;
    case 4:
        uVar1 = 0x14a;
        break;
    case 5:
        uVar1 = 0x193;
        break;
    case 7:
        uVar1 = 0x1dc;
        break;
    case 8:
        uVar1 = 0x225;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45f : 0x26e;
        break;
    case 10:
        uVar1 = 0x2af;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE150


u32 FUN_002de150(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    lVar2 = FUN_0016f190(0x184);
    if (lVar2 == 0) {
        return 0xffffffff;
    }

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xae;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x100 : 0xff;
        break;
    case 4:
        uVar1 = 0x164;
        break;
    case 5:
        uVar1 = 0x1ad;
        break;
    case 7:
        uVar1 = 0x1f6;
        break;
    case 8:
        uVar1 = 0x23f;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x471 : 0x280;
        break;
    case 10:
        uVar1 = 0x2c8;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE2A0


u32 FUN_002de2a0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xb0;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x104 : 0x103;
        break;
    case 4:
        uVar1 = 0x166;
        break;
    case 5:
        uVar1 = 0x1af;
        break;
    case 7:
        uVar1 = 0x20b;
        break;
    case 8:
        uVar1 = 0x233;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x473 : 0x282;
        break;
    case 10:
        uVar1 = 0xffffffff;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE3C0


u32 FUN_002de3c0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xaf;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x102 : 0x101;
        break;
    case 4:
        uVar1 = 0x165;
        break;
    case 5:
        uVar1 = 0x1ae;
        break;
    case 7:
        uVar1 = 0x1f7;
        break;
    case 8:
        uVar1 = 0x240;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x472 : 0x281;
        break;
    case 10:
        uVar1 = 0x2c9;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE4E0 NONMATCHING


u32 FUN_002de4e0(int param_1)



{

  u32 uVar1;

  s32 uVar2;

  s32 uVar3;

  s32 lVar4;

  

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {

    return 0xffffffff;

  }

  if (*(int *)(DAT_007ce3ec + 0x148) == param_1) {
    return 0xffffffff;
  }

  uVar1 = *(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c);

    uVar2 = (u16)FUN_002ffd70(uVar1);

    uVar3 = (u16)FUN_002ffdf0(uVar1);

    uVar2 = ((uVar2 & 0xffff) * 100) / (uVar3 & 0xffff);

    if ((uVar2 > 0x46) && (*(int *)(param_1 + 0x20) < 3)) {
      switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

      case 2:

        if (*(s32 *)DAT_00697BE0_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

        }

        return lVar4 != 0 ? 0x9f : 0x9c;

      case 3:

        if (*(s32 *)DAT_00697be4_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0xf0;
        }
        else {
          uVar1 = 0xed;
        }
        return uVar1;

      case 4:

        if (*(s32 *)DAT_00697BE8_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x155;
        }
        else {
          uVar1 = 0x152;
        }
        return uVar1;

      case 5:

        if (*(s32 *)DAT_00697BEC_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x19e;
        }
        else {
          uVar1 = 0x19b;
        }
        return uVar1;

      case 7:

        if (*(s32 *)DAT_00697BF4_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x1e7;
        }
        else {
          uVar1 = 0x1e4;
        }
        return uVar1;

      case 8:

        if (*(s32 *)DAT_00697BF8_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x230;
        }
        else {
          uVar1 = 0x22d;
        }
        return uVar1;

      case 9:

        lVar4 = FUN_0017d800();

        if (lVar4 == 0) {

          if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x276;

        }

        if (*(s32 *)DAT_00697BFC_abs != -1) {

          FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

        }

        return 0x467;

      case 10:

        if (*(s32 *)DAT_00697c00_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x2ba;
        }
        else {
          uVar1 = 0x2b7;
        }
        return uVar1;

      }
    }
    else {

      if (uVar2 > 0x1e) {
        switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

        case 2:

        if (*(s32 *)DAT_00697BE0_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xa0;
          }
          else {
            uVar1 = 0x9d;
          }
          return uVar1;

        case 3:

        if (*(s32 *)DAT_00697be4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xf1;
          }
          else {
            uVar1 = 0xee;
          }
          return uVar1;

        case 4:

        if (*(s32 *)DAT_00697BE8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x156;
          }
          else {
            uVar1 = 0x153;
          }
          return uVar1;

        case 5:

        if (*(s32 *)DAT_00697BEC_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x19f;
          }
          else {
            uVar1 = 0x19c;
          }
          return uVar1;

        case 7:

        if (*(s32 *)DAT_00697BF4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1e8;
          }
          else {
            uVar1 = 0x1e5;
          }
          return uVar1;

        case 8:

        if (*(s32 *)DAT_00697BF8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x231;
          }
          else {
            uVar1 = 0x22e;
          }
          return uVar1;

        case 9:

          lVar4 = FUN_0017d800();

          if (lVar4 == 0) {

          if (*(s32 *)DAT_00697BFC_abs != -1) {

              FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

            }

            return 0x277;

          }

        if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x468;

        case 10:

        if (*(s32 *)DAT_00697c00_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 699;
          }
          else {
            uVar1 = 0x2b8;
          }
          return uVar1;

        }
      }
      else {

        switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

        case 2:

          if (*(s32 *)DAT_00697BE0_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xa1;
          }
          else {
            uVar1 = 0x9e;
          }
          return uVar1;

        case 3:

          if (*(s32 *)DAT_00697be4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xf2;
          }
          else {
            uVar1 = 0xef;
          }
          return uVar1;

        case 4:

          if (*(s32 *)DAT_00697BE8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x157;
          }
          else {
            uVar1 = 0x154;
          }
          return uVar1;

        case 5:

          if (*(s32 *)DAT_00697BEC_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1a0;
          }
          else {
            uVar1 = 0x19d;
          }
          return uVar1;

        case 7:

          if (*(s32 *)DAT_00697BF4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1e9;
          }
          else {
            uVar1 = 0x1e6;
          }
          return uVar1;

        case 8:

          if (*(s32 *)DAT_00697BF8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x232;
          }
          else {
            uVar1 = 0x22f;
          }
          return uVar1;

        case 9:

          lVar4 = FUN_0017d800();

          if (lVar4 == 0) {

            if (*(s32 *)DAT_00697BFC_abs != -1) {

              FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

            }

            return 0x278;

          }

          if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x469;

        case 10:

          if (*(s32 *)DAT_00697c00_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 700;
          }
          else {
            uVar1 = 0x2b9;
          }
          return uVar1;

        }

      }


    }

    return 0xffffffff;


  return 0xffffffff;

}

#pragma push
#pragma opt_rebuildconditionals on


// FUN_002DED60
u32 FUN_002ded60(int param_1)
{
    u32 uVar1;
    s32 lVar2;
    u8* unit;

    unit = *(u8**)(param_1 + 0x30);
    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }

    switch (*(u16*)(unit + 0xa4))
    {
    case 2:
        if (*(s32*)DAT_00697BE0_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BE0_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xa5 : 0xa4;
        break;
    case 3:
        if (*(s32*)DAT_00697be4_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xf6 : 0xf5;
        break;
    case 4:
        if (*(s32*)DAT_00697BE8_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BE8_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x15b : 0x15a;
        break;
    case 5:
        if (*(s32*)DAT_00697BEC_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BEC_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x1a4 : 0x1a3;
        break;
    case 7:
        if (*(s32*)DAT_00697BF4_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BF4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x1ed : 0x1ec;
        break;
    case 8:
        if (*(s32*)DAT_00697BF8_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BF8_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x236 : 0x235;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        if (lVar2 == 0)
        {
            if (*(s32*)DAT_00697BFC_abs != -1)
            {
                FUN_0016f190(*(s32*)DAT_00697BFC_abs);
            }
            uVar1 = 0x27a;
        }
        else
        {
            if (*(s32*)DAT_00697BFC_abs != -1)
            {
                FUN_0016f190(*(s32*)DAT_00697BFC_abs);
            }
            uVar1 = 0x46a;
        }
        break;
    case 10:
        uVar1 = 0xffffffff;
        break;
    default:
        uVar1 = 0xffffffff;
        break;
    }

    return uVar1;
}
#pragma pop

// FUN_002DEFE0 NONMATCHING


u32 FUN_002defe0(int param_1)



{

  int iVar1;

  s32 lVar2;

  u32 uVar3;

  u16 uVar4;

  int aiStack_30 [12];

  
  lVar2 = FUN_0010a500(4);

  if (lVar2 == 1) {

    return 0xffffffff;

  }

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {

    return 0xffffffff;

  }

  lVar2 = FUN_00300580(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));

  if (lVar2 != 0) {

    return 0xffffffff;

  }

  uVar4 = 0;

  for (iVar1 = *(int *)(DAT_007ce3ec + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {

    lVar2 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c),0);

    if (((lVar2 == 0) && (lVar2 = FUN_00300580(*(u32 *)(iVar1 + 0xa2c),0x180375), lVar2 == 0)

        ) && (*(u16 *)(iVar1 + 0xa4) != 1)) {

      aiStack_30[uVar4] = iVar1;

      uVar4 = uVar4 + 1 & 0xffff;

    }

  }

  if (uVar4 == 0) {

    return -1;

  }

  {

    iVar1 = FUN_002ffbc0();

    iVar1 = aiStack_30[iVar1];

    if (iVar1 == 0) {

      return 0xffffffff;

    }

    switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

    case 1:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0xb1;

        }

        return 0xb2;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x10f;

        }

        return 0x110;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x167;

        }

        return 0x168;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x1b0;

        }

        return 0x1b1;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x1f9;

        }

        return 0x1fa;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x242;

        }

        return 0x243;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (0x31 < uVar3) {

            return 0x47e;

          }

          return 0x47f;

        }

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x283;

        }

        return 0x284;

      case 10:

        return 0xffffffff;

      }

      break;

    case 2:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xb4;

        }

        return 0xb3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x112;

        }

        return 0x111;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x16a;

        }

        return 0x169;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1b3;

        }

        return 0x1b2;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1fc;

        }

        return 0x1fb;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x245;

        }

        return 0x244;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x481;

          }

          return 0x480;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x286;

        }

        return 0x285;

      case 10:

        return 0xffffffff;

      }

      break;

    case 3:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xb6;

        }

        return 0xb5;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x114;

        }

        return 0x113;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x16c;

        }

        return 0x16b;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1b5;

        }

        return 0x1b4;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1fe;

        }

        return 0x1fd;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x247;

        }

        return 0x246;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x483;

          }

          return 0x482;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x288;

        }

        return 0x287;

      case 10:

        return 0xffffffff;

      }

      break;

    case 4:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xb8;

        }

        return 0xb7;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x116;

        }

        return 0x115;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x16e;

        }

        return 0x16d;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1b7;

        }

        return 0x1b6;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x200;

        }

        return 0x1ff;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x249;

        }

        return 0x248;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x485;

          }

          return 0x484;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x28a;

        }

        return 0x289;

      case 10:

        return 0xffffffff;

      }

      break;

    case 5:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xba;

        }

        return 0xb9;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x118;

        }

        return 0x117;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x170;

        }

        return 0x16f;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1b9;

        }

        return 0x1b8;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x202;

        }

        return 0x201;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x24b;

        }

        return 0x24a;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x487;

          }

          return 0x486;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x28c;

        }

        return 0x28b;

      case 10:

        return 0xffffffff;

      }

      break;

    case 7:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xbc;

        }

        return 0xbb;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x11a;

        }

        return 0x119;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x172;

        }

        return 0x171;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1bb;

        }

        return 0x1ba;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x204;

        }

        return 0x203;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x24d;

        }

        return 0x24c;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x489;

          }

          return 0x488;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x28e;

        }

        return 0x28d;

      case 10:

        return 0xffffffff;

      }

      break;

    case 8:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0xbe;

        }

        return 0xbd;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x11c;

        }

        return 0x11b;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x174;

        }

        return 0x173;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x1bd;

        }

        return 0x1bc;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x206;

        }

        return 0x205;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x24f;

        }

        return 0x24e;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x489;

          }

          return 0x488;

        }

        uVar3 = FUN_002ffbc0(100);

        if (uVar3 < 0x32) {

          return 0x290;

        }

        return 0x28f;

      case 10:

        return 0xffffffff;

      }

      break;

    case 9:

      lVar2 = FUN_0017d800();

      if (lVar2 == 0) {

        switch(*(u16 *)(iVar1 + 0xa4)) {

        case 2:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0xc0;

          }

          return 0xbf;

        case 3:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x11e;

          }

          return 0x11d;

        case 4:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x176;

          }

          return 0x175;

        case 5:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x1bf;

          }

          return 0x1be;

        case 7:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x208;

          }

          return 0x207;

        case 8:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x251;

          }

          return 0x250;

        case 9:

          lVar2 = FUN_0017d800();

          if (lVar2 != 0) {

            uVar3 = FUN_002ffbc0(100);

            if (uVar3 < 0x32) {

              return 0x48b;

            }

            return 0x48a;

          }

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x292;

          }

          return 0x291;

        case 10:

          return 0xffffffff;

        }

      }

      else {

        switch(*(u16 *)(iVar1 + 0xa4)) {

        case 2:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0xc4;

          }

          return 0xc3;

        case 3:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x122;

          }

          return 0x121;

        case 4:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x17a;

          }

          return 0x179;

        case 5:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x1c3;

          }

          return 0x1c2;

        case 7:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x20c;

          }

          return 0x20b;

        case 8:

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x255;

          }

          return 0x254;

        case 9:

          lVar2 = FUN_0017d800();

          if (lVar2 != 0) {

            uVar3 = FUN_002ffbc0(100);

            if (uVar3 < 0x32) {

              return 0x481;

            }

            return 0x480;

          }

          uVar3 = FUN_002ffbc0(100);

          if (uVar3 < 0x32) {

            return 0x296;

          }

          return 0x295;

        case 10:

          return 0xffffffff;

        }

      }

      break;

    case 10:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0xc1;

        }

        return 0xc2;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x11f;

        }

        return 0x120;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x177;

        }

        return 0x178;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x1c0;

        }

        return 0x1c1;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x209;

        }

        return 0x20a;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x252;

        }

        return 0x253;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 != 0) {

          uVar3 = FUN_002ffbc0(100);

          if (0x31 < uVar3) {

            return 0x48c;

          }

          return 0x48d;

        }

        uVar3 = FUN_002ffbc0(100);

        if (0x31 < uVar3) {

          return 0x293;

        }

        return 0x294;

      case 10:

        return 0xffffffff;

      }

    }

    return 0xffffffff;

  }

  return 0xffffffff;

}

// FUN_002E0350
u32 FUN_002e0350(int param_1)
{
    u32 result;
    BtlUnit* unit;

    unit = *(BtlUnit**)(param_1 + 0x30);
    if (unit->genus != 0)
    {
        result = 0xffffffff;
    }
    else
    {
        switch (unit->charId)
        {
        case 2:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0xd7 : 0xd8;
            break;
        case 3:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x135 : 0x136;
            break;
        case 4:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x18d : 0x18e;
            break;
        case 5:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x1d6 : 0x1d7;
            break;
        case 7:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x21f : 0x220;
            break;
        case 8:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x268 : 0x269;
            break;
        case 9:
            if (FUN_0017d800() == 0)
            {
                result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x2a9 : 0x2aa;
            }
            else
            {
                FUN_002ffbc0(100);
                result = 0x4a3;
            }
            break;
        case 10:
            result = 0xffffffff;
            break;
        default:
            result = 0xffffffff;
        }
    }
    return result;
}

// FUN_002E0540


u32 FUN_002e0540(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0xd9;
      break;
    case 3:
      result = 0x146;
      break;
    case 4:
      result = 399;
      break;
    case 5:
      result = 0x1d8;
      break;
    case 7:
      result = 0x221;
      break;
    case 8:
      result = 0x26a;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x4b2 : 0x2ab;
      break;
    case 10:
      result = 0xffffffff;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

// FUN_002E0620 NONMATCHING


int FUN_002e0620(int param_1,int param_2)



{

  u16 sVar1;

  int iVar2;

  u32 lVar3;

  u32 uVar4;

  

  iVar2 = *(int *)(param_1 + 0x30);

  if (*(int *)(iVar2 + 0xa00) == 0) {

    return -1;

  }

  if (*(u8 *)(iVar2 + 0xa2) == 1) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 0x10b: return 0x2f7;
    case 0x10c: return 0x30b;
    case 0x110: return 0x2f8;
    case 0x10f: return 0x30c;
    case 0x108: return 0x321;
    case 0xe9: return 0x46e;
    case 0xea:
      switch (param_2) {
      case 0xc0: return 0x377;
      case 0xc1: return 0x378;
      case 0xc2: return 0x379;
      case 0xc3: return 0x37a;
      case 0xc4: return 0x37b;
      case 0xc5: return 0x37c;
      case 0xc6: return 0x37d;
      case 0xc7: return 0x37e;
      case 0xc8: return 0x37f;
      case 0xc9: return 0x380;
      case 0xca: return 0x381;
      case 0xcb: return 0x382;
      case 0xcc: return 0x383;
      case 0xcd: return 0x384;
      case 0xce: return 0x385;
      case 0xcf: return 0x386;
      case 0xd3: return 0x387;
      default: goto outer_default;
      }
    case 0xeb: return 0x1f2;
    case 0xec: return 0x23b;
    case 0xed: return 0x1a9;
    case 0xee: return 0x2c4;
    case 0xef: return 0xaa;
    case 0xf0: return 0x160;
    default:
outer_default:
      return -1;
    }
  } else {
    if (*(int *)(DAT_007ce3ec + 0x148) == param_1) {
      lVar3 = FUN_0017d800();
      if (lVar3 != 0)
        goto journey_true;
      if (param_2 == 0xa9)
        return 1;
      if (param_2 < 0x92)
        return param_2;
      return param_2 + 0x2ce;
journey_true:
      if (param_2 == 0xa9)
        return 0x388;
      return param_2 + 0x387;
    }
      
      switch(*(u16 *)(iVar2 + 0xa4)) {
      
      default:
      
        return -1;
      
      case 2:
    
        lVar3 = FUN_0016f190(0x1357);
    
        if (lVar3 == 0) {
    
          FUN_0016f1f0(0x1357,1);
    
          return 0xa8;
    
        }
    
        uVar4 = FUN_002ffbc0(100);
    
        if (0x31 < uVar4) {
    
          if (DAT_00697be0 == -1) {
    
            lVar3 = 0;
    
          }
    
          else {
    
            lVar3 = FUN_0016f190();
    
          }
    
          if (lVar3 != 0) {
    
            return 0xa7;
    
          }
    
          return 0xa6;
    
        }
    
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc0) {
    
          return 0xa9;
    
        }
    
        return 0xaa;
      
      case 3:
      
        lVar3 = FUN_0016f190(0x1358);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x1358,1);
      
          return 0xf9;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697be4 == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0xf8;
      
          }
      
          return 0xf7;
      
        }
      
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc2) {
      
          return 0xfa;
      
        }
      
        return 0xfb;
      
      case 4:
      
        lVar3 = FUN_0016f190(0x1359);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x1359,1);
      
          return 0x15e;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697be8 == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0x15d;
      
          }
      
          return 0x15c;
      
        }
      
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc4) {
      
          return 0x15f;
      
        }
      
        return 0x160;
      
      case 5:
      
        lVar3 = FUN_0016f190(0x135a);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135a,1);
      
          return 0x1a7;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697bec == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0x1a6;
      
          }
      
          return 0x1a5;
      
        }
      
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc6) {
      
          return 0x1a8;
      
        }
      
        return 0x1a9;
      
      case 7:
      
        lVar3 = FUN_0016f190(0x135b);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135b,1);
      
          return 0x1f0;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697bf4 == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0x1ef;
      
          }
      
          return 0x1ee;
      
        }
      
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xca) {
      
          return 0x1f1;
      
        }
      
        return 0x1f2;
      
      case 8:
      
        lVar3 = FUN_0016f190(0x135c);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135c,1);
      
          return 0x239;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697bf8 == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0x238;
      
          }
      
          return 0x237;
      
        }
      
        if (*(short *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xcc) {
      
          return 0x23a;
      
        }
      
        return 0x23b;
      
      case 9:
      
        lVar3 = FUN_0016f190(0x135d);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135d,1);
      
          lVar3 = FUN_0017d800();
      
          if (lVar3 != 0) {
      
            return 0x46d;
      
          }
      
          return 0x27c;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 < 0x32) {
      
          lVar3 = FUN_0017d800();
      
          if (lVar3 != 0) {
      
            return 0x46e;
      
          }
      
          return 0x27d;
      
        }
      
        lVar3 = FUN_0017d800();
      
        if (lVar3 == 0) {
      
          if (DAT_00697bfc != -1) {
      
            FUN_0016f190();
      
          }
      
          return 0x27b;
      
        }
      
        if (DAT_00697bfc != -1) {
      
          FUN_0016f190();
      
        }
      
        return 0x46c;
      
      case 10:
      
        lVar3 = FUN_0016f190(0x135e);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135e,1);
      
          return 0x2c3;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (0x31 < uVar4) {
      
          if (DAT_00697c00 == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190();
      
          }
      
          if (lVar3 != 0) {
      
            return 0x2c2;
      
          }
      
          return 0x2c1;
      
        }
      
        return 0x2c4;
      
      } }
}

// FUN_002E0F70


u32 FUN_002e0f70(int param_1, int param_2, int param_3)
{
    u32 category;

    if (*(u8*)(*(int*)(param_1 + 0x30) + 0xa2) != 0)
        return 0xffffffff;
    if (*(int*)(DAT_007ce3ec + 0x148) == param_1)
        return 0xffffffff;

    category = func_002d4e10(2, 0x80000) & 0xffff;
    switch (category)
    {
    case 4:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc5;
        case 3: return 0x123;
        case 4: return 0x17b;
        case 5: return 0x1c4;
        case 7: return 0x20d;
        case 8: return 0x256;
        case 9:
            if (FUN_0017d800() != 0) return 0x490;
            return 0x297;
        case 10: return 0xffffffff;
        }
        break;
    case 3:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc6;
        case 3: return 0x124;
        case 4: return 0x17c;
        case 5: return 0x1c5;
        case 7: return 0x20e;
        case 8: return 0x257;
        case 9:
            if (FUN_0017d800() != 0) return 0x491;
            return 0x298;
        case 10: return 0xffffffff;
        }
        break;
    case 2:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc7;
        case 3: return 0x125;
        case 4: return 0x17d;
        case 5: return 0x1c6;
        case 7: return 0x20f;
        case 8: return 0x258;
        case 9:
            if (FUN_0017d800() != 0) return 0x492;
            return 0x299;
        case 10: return 0xffffffff;
        }
        break;
    case 1:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc8;
        case 3: return 0x126;
        case 4: return 0x17e;
        case 5: return 0x1c7;
        case 7: return 0x210;
        case 8: return 0x259;
        case 9:
            if (FUN_0017d800() != 0) return 0x493;
            return 0x29a;
        case 10: return 0xffffffff;
        }
        break;
    }
    return 0xffffffff;
}

// FUN_002E12D0
u32 FUN_002e12d0(int param_1)
{
  u32 uVar1;
  u32 lVar2;
  u32 uVar3;

  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) != 0) {
    return 0xffffffff;
  }

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
  case 2:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0xd5 : 0xd6;
    break;
  case 3:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x133 : 0x134;
    break;
  case 4:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x18b : 0x18c;
    break;
  case 5:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x1d4 : 0x1d5;
    break;
  case 7:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x21d : 0x21e;
    break;
  case 8:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x266 : 0x267;
    break;
  case 9:
    lVar2 = FUN_0017d800();
    if (lVar2 == 0) {
      uVar3 = FUN_002ffbc0(100);
      uVar1 = uVar3 >= 0x32 ? 0x2a7 : 0x2a8;
    } else {
      uVar3 = FUN_002ffbc0(100);
      uVar1 = uVar3 >= 0x32 ? 0x4a0 : 0x4a1;
    }
    break;
  case 10:
    uVar1 = 0xffffffff;
    break;
  default:
    uVar1 = 0xffffffff;
  }

  return uVar1;
}

// FUN_002E1500


u32 FUN_002e1500(int param_1, u32 param_2)
{
    BtlUnit* unit = *(BtlUnit**)(param_1 + 0x30);

    if (unit->genus != 0)
    {
        return 0xffffffff;
    }

    switch (param_2)
    {
        case 0:
            switch (unit->charId)
            {
            case 2:
                return 0xcb;
            case 3:
                return 0x129;
            case 4:
                return 0x181;
            case 5:
                return 0x1ca;
            case 7:
                return 0x213;
            case 8:
                return 0x25c;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x496;
                }
                return 0x29d;
            case 10:
                return 0xffffffff;
            }
            break;
        case 1:
            switch (unit->charId)
            {
            case 2:
                return 0xcc;
            case 3:
                return 0x12a;
            case 4:
                return 0x182;
            case 5:
                return 0x1cb;
            case 7:
                return 0x214;
            case 8:
                return 0x25d;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x497;
                }
                return 0x29e;
            case 10:
                return 0xffffffff;
            }
            break;
        case 2:
            switch (unit->charId)
            {
            case 2:
                return 0xcd;
            case 3:
                return 0x12b;
            case 4:
                return 0x183;
            case 5:
                return 0x1cc;
            case 7:
                return 0x215;
            case 8:
                return 0x25e;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x498;
                }
                return 0x29f;
            case 10:
                return 0xffffffff;
            }
            break;
        case 3:
            switch (unit->charId)
            {
            case 2:
                return 0xce;
            case 3:
                return 0x12c;
            case 4:
                return 0x184;
            case 5:
                return 0x1cd;
            case 7:
                return 0x216;
            case 8:
                return 0x25f;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x499;
                }
                return 0x2a0;
            case 10:
                return 0xffffffff;
            }
            break;
        case 4:
            switch (unit->charId)
            {
            case 2:
                return 0xcf;
            case 3:
                return 0x12d;
            case 4:
                return 0x185;
            case 5:
                return 0x1ce;
            case 7:
                return 0x217;
            case 8:
                return 0x260;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49a;
                }
                return 0x2a1;
            case 10:
                return 0xffffffff;
            }
            break;
        case 5:
            switch (unit->charId)
            {
            case 2:
                return 0xd1;
            case 3:
                return 0x12f;
            case 4:
                return 0x187;
            case 5:
                return 0x1d0;
            case 7:
                return 0x219;
            case 8:
                return 0x262;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49c;
                }
                return 0x2a3;
            case 10:
                return 0xffffffff;
            }
            break;
        case 6:
            switch (unit->charId)
            {
            case 2:
                return 0xd0;
            case 3:
                return 0x12e;
            case 4:
                return 0x186;
            case 5:
                return 0x1cf;
            case 7:
                return 0x218;
            case 8:
                return 0x261;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49b;
                }
                return 0x2a2;
            case 10:
                return 0xffffffff;
            }
            break;
        case 7:
            switch (unit->charId)
            {
            case 2:
                return 0xd4;
            case 3:
                return 0x132;
            case 4:
                return 0x18a;
            case 5:
                return 0x1d3;
            case 7:
                return 0x21c;
            case 8:
                return 0x265;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49f;
                }
                return 0x2a6;
            case 10:
                return 0xffffffff;
            }
            break;
        case 8:
            switch (unit->charId)
            {
            case 2:
                return 0xd2;
            case 3:
                return 0x130;
            case 4:
                return 0x188;
            case 5:
                return 0x1d1;
            case 7:
                return 0x21a;
            case 8:
                return 0x263;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49d;
                }
                return 0x2a4;
            case 10:
                return 0xffffffff;
            }
            break;
        case 9:
            switch (unit->charId)
            {
            case 2:
                return 0xd3;
            case 3:
                return 0x131;
            case 4:
                return 0x189;
            case 5:
                return 0x1d2;
            case 7:
                return 0x21b;
            case 8:
                return 0x264;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49e;
                }
                return 0x2a5;
            case 10:
                return 0xffffffff;
            }
            break;
        }

    return 0xffffffff;
}

// FUN_002E1BF0


u32 FUN_002e1bf0(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0x9a;
      break;
    case 3:
      result = 0xea;
      break;
    case 4:
      result = 0x150;
      break;
    case 5:
      result = 0x199;
      break;
    case 7:
      result = 0x1e2;
      break;
    case 8:
      result = 0x22b;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x465 : 0x274;
      break;
    case 10:
      result = 0x2b5;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

// FUN_002E1CD0


u32 FUN_002e1cd0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x9b;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xec : 0xeb;
        break;
    case 4:
        uVar1 = 0x151;
        break;
    case 5:
        uVar1 = 0x19a;
        break;
    case 7:
        uVar1 = 0x1e3;
        break;
    case 8:
        uVar1 = 0x22c;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x466 : 0x275;
        break;
    case 10:
        uVar1 = 0x2b6;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002E1DF0


u32 FUN_002e1df0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x96;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe3 : 0xe2;
        break;
    case 4:
        uVar1 = 0x14c;
        break;
    case 5:
        uVar1 = 0x195;
        break;
    case 7:
        uVar1 = 0x1de;
        break;
    case 8:
        uVar1 = 0x227;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x461 : 0x270;
        break;
    case 10:
        uVar1 = 0x2b1;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002E1F10


u32 FUN_002e1f10(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x98;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe7 : 0xe6;
        break;
    case 4:
        uVar1 = 0x14e;
        break;
    case 5:
        uVar1 = 0x197;
        break;
    case 7:
        uVar1 = 0x1e0;
        break;
    case 8:
        uVar1 = 0x229;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x463 : 0x272;
        break;
    case 10:
        uVar1 = 0x2b3;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002E2030


u32 FUN_002e2030(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0x95;
      break;
    case 3:
      result = 0xe1;
      break;
    case 4:
      result = 0x14b;
      break;
    case 5:
      result = 0x194;
      break;
    case 7:
      result = 0x1dd;
      break;
    case 8:
      result = 0x226;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x460 : 0x26f;
      break;
    case 10:
      result = 0x2b0;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

// FUN_002E2110


u32 FUN_002e2110(int param_1)
{
    u8* unit = *(u8**)(param_1 + 0x30);

    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }

    if (datGetScenarioMode() == 0)
    {
        switch (effMiscRand(0) % 9)
        {
        case 0: return 0x137;
        case 1: return 0x138;
        case 2: return 0x139;
        case 3: return 0x13a;
        case 4: return 0x13b;
        case 5: return 0x13c;
        case 6: return 0x13d;
        case 7: return 0x13e;
        case 8: return 0x13f;
        }
    }
    else
    {
        switch (effMiscRand(0) & 7)
        {
        case 0: return 0x4a4;
        case 1: return 0x4a5;
        case 2: return 0x4a6;
        case 3: return 0x4a7;
        case 4: return 0x4a8;
        case 5: return 0x4a9;
        case 6: return 0x4aa;
        case 7: return 0x4ab;
        }
    }

    return 0xffffffff;
}

// FUN_002E22A0


u32 FUN_002e22a0(int param_1)
{
  u32 iVar1;
  u32 lVar2;

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  lVar2 = FUN_0017d800();
  if (lVar2 == 0) {
    iVar1 = FUN_00357fd0(0);
    switch (iVar1 % 5) {
    case 0:
      return 0x140;
    case 1:
      return 0x141;
    case 2:
      return 0x142;
    case 3:
      return 0x143;
    case 4:
      return 0x144;
    default:
      break;
    }
  } else {
    iVar1 = FUN_00357fd0(0);
    switch (iVar1 % 5) {
    case 0:
      return 0x4ac;
    case 1:
      return 0x4ad;
    case 2:
      return 0x4ae;
    case 3:
      return 0x4af;
    case 4:
      return 0x4b0;
    default:
      break;
    }
  }
  return 0xffffffff;
}

// FUN_002E2410


u32 FUN_002e2410(int param_1)
{
  int iVar1;
  int iVar2;
  u32 lVar4;
  u32 uVar5;
  int aiStack_30[12];

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  uVar5 = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x14c); iVar2 != 0;
       iVar2 = *(int *)(iVar2 + 0x4a8)) {
    if ((*(u16 *)(iVar2 + 0x1a) & 1) == 0) {
      continue;
    }
    iVar1 = *(int *)(iVar2 + 0x30);
    if (*(u8 *)(iVar1 + 0xa2) != '\0') {
      continue;
    }
    if (*(int *)(iGpffffb6fc + 0x148) == iVar2) {
      continue;
    }
    if (param_1 == iVar2) {
      continue;
    }
    lVar4 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c), 0);
    if (lVar4 != 0) {
      continue;
    }
    lVar4 = FUN_00300580(*(u32 *)(iVar1 + 0xa2c), 0x180375);
    if (lVar4 != 0) {
      continue;
    }
    if (*(u16 *)(iVar1 + 0xa4) == 10) {
      continue;
    }
    aiStack_30[uVar5 & 0xffff] = iVar2;
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if ((u16)uVar5 == 0) {
    return 0xffffffff;
  }
  iVar2 = aiStack_30[FUN_002ffbc0((u16)uVar5)];
  return FUN_002e0f70(iVar2, 0, 0);
}

// FUN_002E2560


u32 FUN_002e2560(int param_1)
{
  u32 result;
  BtlUnit* unit;

  if (FUN_0010a500(4) == 1) {
    result = 0xffffffff;
  } else {
    unit = *(BtlUnit**)(param_1 + 0x30);
    if (unit->genus != 0) {
      result = 0xffffffff;
    } else {
      switch (unit->charId) {
      case 2:
        result = (u32)FUN_002ffbc0(100) >= 50 ? 0xd7 : 0xd8;
        break;
      case 3:
        result = 0x136;
        break;
      default:
        result = 0xffffffff;
        break;
      }
    }
  }
  return result;
}

// FUN_002E2630
u32 FUN_002e2630(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 1) {
    goto default_case;
  }
  switch (unit->charId) {
  case 0x126:
    result = 0x33c;
    break;
default_case:
  default:
    result = 0xffffffff;
    break;
  }
  return result;
}

 
// FUN_002E2680


u32 FUN_002e2680(int param_1)
{
    u32 result;
    u32 rand;
    s32 flagResult;
    u8* unit;
    s8* record;

    unit = *(u8**)(param_1 + 0x30);
    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }
    record = *(s8**)(unit + 0xa2c);
    if (record == 0)
    {
        return 0xffffffff;
    }
    if (record[0x10] == 9)
    {
        return 0xffffffff;
    }

    switch (*(u16*)(unit + 0xa4))
    {
    case 2:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x443 : 0x444;
        break;
    case 3:
        if (*(s32*)DAT_00697be4_abs == -1)
            flagResult = 0;
        else
            flagResult = FUN_0016f190(*(s32*)DAT_00697be4_abs);
        if (flagResult == 0)
            goto c3_zero;
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x449 : 0x44a;
        goto c3_done;
c3_zero:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x447 : 0x448;
c3_done:
        break;
    case 4:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x44d : 0x44e;
        break;
    case 5:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x451 : 0x452;
        break;
    case 7:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x453 : 0x454;
        break;
    case 8:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x459 : 0x45a;
        break;
    case 9:
        if (FUN_0017d800() != 0)
            goto c9_fes;
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x45b : 0x45c;
        goto c9_done;
c9_fes:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x4b3 : 0x4b4;
c9_done:
        break;
    case 10:
        result = 0xffffffff;
        break;
    default:
        result = 0xffffffff;
        break;
    }

    return result;
}

// FUN_002E2920


u32 FUN_002e2920(int *param_1)
{
    u32 uVar1;
    int iVar2;
    s32 lVar3;

    if (param_1[1] == 0)
    {
        if (iGpffffb80c == 0)
        {
            uVar1 = (*DAT_00960178_abs)(0xacc, 0x40000);
            *(u32*)(iGpffffb6fc + 0xafc) = uVar1;
            iVar2 = FUN_0010a770(
                *(u32*)(iGpffffb6fc + 0xd18),
                *(u16*)(iGpffffb6fc + 0xaf8),
                *(u32*)(iGpffffb6fc + 0xafc),
                4, 0x1c2, 1);
            *param_1 = iVar2;
        }
        else
        {
            *param_1 = 0;
        }
        param_1[1] = 1;
    }

    if (*param_1 != 0)
    {
        lVar3 = FUN_0010a720(*param_1);
        if (lVar3 != 0)
        {
            *(u16*)(iGpffffb6fc + 0xaf6) |= 1;
            uVar1 = 1;
        }
        else
        {
            goto sound_failed;
        }
    }
    else
    {
        *(u16*)(iGpffffb6fc + 0xaf6) |= 1;
        uVar1 = 1;
    }
    goto sound_done;

sound_failed:
    uVar1 = 0;

sound_done:
    return uVar1;
}

// FUN_002E2A10
void FUN_002e2a10(void)
{
    BtlPacket* packet;
    void* work;

    packet = btlPacketCreate(0xa00, 8);
    packet->unk_47 &= 0xfe;
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002e2920;
    work = packet->workData;
    *(u32*)work = 0;
    *(u32*)((u8*)work + 4) = 0;
}

// FUN_002E2A60


u32 FUN_002e2a60(int *param_1)



{

  int iVar1;

  u32 uVar2;

s32 lVar3;

  

  if ((*(u16 *)(iGpffffb6fc + 0xaf6) & 1) == 0) {

    return 1;

  }

  iVar1 = *param_1;

  if (param_1[5] == 0) {

    if ((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1a) & 1) == 0)) {

      return 1;

    }

    uVar2 = DAT_00697c10[*(u16 *)(param_1 + 1)]
             (iVar1,param_1[2],param_1[3]);

    if (uVar2 == 0xffffffff) {

      return 1;

    }

    FUN_0010a2e0(*(u16 *)(iGpffffb6fc + 0xaf8),4,uVar2 & 0xffff);

    param_1[5] = 1;

  }

  else {

    lVar3 = FUN_0010a500(4);

    if (lVar3 != 1) {

      if ((iVar1 != 0) && ((*(u32 *)(*(int *)(iVar1 + 0x30) + 0x98) & 2) != 0)) {

        iVar1 = *(int *)(*(int *)(iVar1 + 0x30) + 0x9f4);

        *(u16 *)(iVar1 + 0x3fe) = *(u16 *)(iVar1 + 0x3fe) | 0x20;

      }

      return 1;

    }

  }

  if (((param_1[5] == 1) && (iVar1 != 0)) && ((*(u32 *)(*(int *)(iVar1 + 0x30) + 0x98) & 2) != 0))

  {

    iVar1 = *(int *)(*(int *)(iVar1 + 0x30) + 0x9f4);

    *(u16 *)(iVar1 + 0x3fe) = *(u16 *)(iVar1 + 0x3fe) & 0xffdf;

  }

  return 0;

}
