#include "Main/g_data.h"
#include "Main/Battle/Data/datCalc.h"
#include "Kosaka/k_assert.h"
#include "Script/scrTraceCode.h"
#include "temporary.h"
#include "datCalendar.h"

#define SOCIAL_LINK_COUNT 30
#define SOCIAL_DATA_POINTS_OFFSET 0xD2
#define SOCIAL_DATA_COUNTER_OFFSET 0xD6
extern u8* FUN_00172c50(s16* outValue);
extern s32 FUN_00172660(s32 socialLink);
extern void FUN_00172a20(u32 value);
extern u8 DAT_00836200_ptr[];
extern u8 D_008364BC[];
extern s32 D_008364F4[];
extern s32 D_008365F4[];
extern u8 D_008366F4[];
extern u8 D_00836734[];
extern u8 D_00836752[];
extern s16 D_0083679C[];
extern u8 D_0083A34C[];
extern u8* iGpffffb7f4;
extern u8* iGpffffb730;
extern u8* iGpffffb734;
extern u8* iGpffffb740;
extern u8* iGpffffb2e4;
extern s32 func_003951d0(s32 resourceId);
extern void func_00395170(s32 resourceId);
extern void func_003951a0(s32 resourceId);
extern s16* func_003bddd0(void);
extern u8* func_003beb10(s32 socialLink);
extern void func_0017ad90(void);
extern void func_0017ac60(u32 packedData);
extern void func_001828d0(s16 itemId, void* itemData);
extern void func_001831e0(s16 pcId, s16 slot, const void* itemData);


// 005dc050
static const u32 sPlayerExpThreshold[MAX_CHARACTER_LEVEL] = 
{
    0, 20, 47, 99, 185, 312, 490, 726, 1030,
    1410, 1873, 2429, 3085, 3851, 4735, 5744, 6888, 8174,
    9612, 11210, 12975, 14917, 17043, 19363, 21885, 24616, 27566,
    30742, 34154, 37810, 41717, 45885, 50321, 55035, 60035, 65328,
    70924, 76830, 83056, 89610, 96499, 103733, 111319, 119267, 127585,
    136280, 145362, 154838, // ! 005dc110 !
};

static const s16 academicLevelThreshold[6] = { 0, 20, 80, 140, 200, 260 }; // 005e3068
static const s16 charmLevelThreshold[6] =    { 0, 15, 30, 45, 65, 80 };    // 005e3078
static const s16 courageLevelThreshold[6] =  { 0, 15, 30, 45, 65, 80 };    // 005e3088

// 005e4150
static const char* physicalConditionsString[13] = 
{
    "You recovered from your cold.",
    "Your cold is not gone yet...",
    "Your cold worsened because you're tired.",
    "You've caught a cold.",
    "You've become tired.",
    "You're not tired anymore.",
    "Your condition improved because you rested.",
    "Your condition has improved.",
    "You are no longer in great condition.",
    "You're still tired",
    "You're no longer sick because you rested.",
    "You're no longer tired because you rested.",
    "The medicine cured your illness."
};

static s16 sSavedPartyIds[4]; // 007cdfa8
static u32 sScenarioMode;     // 007cdfa4. See enum 'ScenarioMode'

DatGlobal gGlobalWork; // 00836200
DatPc gPcs[PC_MAX];    // 00833948

void func_00177410(u8*, u8*);
void func_001774e0(void);
extern const char D_005E3098[];
extern const char D_005E3260[];
extern u32 gSpecialStatusMessage;
extern u8 DAT_00833bb0[];
extern u8 DAT_00833bd0[];
extern u8 DAT_00833bf0[];
extern u32 DAT_00836200;
extern u8 DAT_00836212[];
extern u8* PTR_s_Aigis_005e35ec;
extern u8* PTR_s_Aigis_005e379c;
extern u8* PTR_s_Aigis_005e37dc;
extern u8* PTR_s_Metis_005e3790;
extern u8* PTR_s_Metis_005e37d0;
extern u8* PTR_s_Metis_005e35e0;
extern u8* D_005E35E0[];
extern u8* D_005E35EC[];
extern u8* D_005E3790[];
extern u8* D_005E379C[];
extern u8* D_005E37D0[];
extern u8* D_005E37DC[];
extern u8 D_007FD6C8[];
extern u8 D_007FD6CC[];
extern u8 D_007FD6D0[];
extern u8 D_007FD6D1[];
extern u8 D_007FD6D2[];
extern u8 D_007FD6D4[];
extern u8 D_007FD6D6[];
extern u8 D_007FD6D8[];
extern u8 D_008339A4[];
extern u8 D_008339A8[];
extern u8 D_008339AC[];
extern u8 D_008339AD[];
extern u8 D_008339AE[];
extern u8 D_008339B0[];
extern u8 D_008339B2[];
extern u8 D_008339B4[];
extern u8 D_008339F4[];
extern u8 D_00834010[];
extern u8 D_00834120[];
extern u8 DAT_00830000_a[];
extern u8 DAT_00830000_b[];
extern u8 DAT_00830000_c[];
extern u8 D_007CBFA0;
extern u8 D_008339F6[];
extern u8 D_00833A78[];
extern u8 D_00833C58[];
extern u8 D_00833C5A[];
extern u8 D_00833E80[];
extern u8 D_00833E84[];
extern u8 D_00833E88[];
extern u8 D_00833E89[];
extern u8 D_00833E8A[];
extern u8 D_00833E8C[];
extern u8 D_00833E8E[];
extern u8 D_00833E90[];
extern u8 D_00836458[];
extern u8 D_00836498[];

extern void func_001754a0(u32 value);

void FUN_00172890(void);
void FUN_00172e10(void);
extern u8 D_005DC1B4[];
extern s8 D_005E3220[];
extern s16 D_005E3240[];
extern u8 D_00831CE0[];
extern u8 D_007FD858[];
extern u8 D_007FD85A[];
extern u8 D_005DDDC0[];
extern u8 D_005DABF0[];
extern u8 D_005D6C70[];
extern u8 D_005D6C80[];
extern u8 D_005DE8E0[];
extern u8 D_005DE880[];
extern u8 D_005DE040[];
extern u8 D_00836773[];
extern u8* D_007CDFB4;
extern u8* D_007CDFBC;
extern u8* D_007CDFC0;
extern u8* D_007CDFC4;
extern u8* D_007CDFC8;
extern u8* D_007CDFCC;
extern u8* D_007CDFD0;
extern u8* D_007CDFD4;
extern u8* D_007CDFD8;
extern u8* D_007CDFDC;
extern u8* D_007CDFE4;

extern u16 func_00300100(DatUnit* unit);
extern u32 FUN_00173280(u16 personaId);
extern void FUN_00171B50(s16 socialLink);
extern void FUN_00171C40(s16 socialLink, s32 value);
extern void FUN_00171E90(s16 socialLink, s32 value);
extern void FUN_00172200(s32 socialLink, s32 value);
// Call-site alias retains the pre-merge narrow argument ABI.
#pragma alias FUN_00172200_s16 FUN_00172200
extern void FUN_00172200_s16(s16 socialLink, s32 value);
extern void FUN_001723A0(s16 socialLink, s32 rank, s32 enabled);
extern void FUN_001724A0(s16 socialLink, s32 rank, s32 enabled);
extern f32 FUN_003BDB80(void);
extern u8* FUN_003BDD90();
extern u32 FUN_00488F30(void);
extern void FUN_005225A8();
extern s16 func_00171060(s16 id);

u16 func_0016cc00(s16 pcId);
u16 func_0016ccb0(s16 pcId);
u8 func_0016d280(s32 exp);
u32 func_0016dce0(s16 socialLink);
s8 func_0016dd20(s16 socialLink);
void func_0016ddd0(s32 index);
u8 func_0016de50(s32 index);
s16 func_0016deb0(s16 arcana);
void func_0016dfb0(s16 socialLink);
s16 func_0016e190(s32 socialLink);
void func_0016e2b0(s16 socialLink, s32 amount);
void func_0016e410(s16 socialLink, s8 level);
void func_0016e5f0(s32 socialLink, s8 progress);
#pragma alias func_0016e5f0_call func_0016e5f0
extern void func_0016e5f0_call(s16 socialLink, s8 progress);
void func_0016e670(s16 socialLink);
void func_0016e7a0(s16 socialLink, s16 day);
s16 func_0016e850(s16 socialLink);
s32 func_0016ea40(s32 amount);
u32 func_0016ea80(void);
u32 func_0016ecd0(void);
u8* func_00170620(s16 pcId, s16 index);
u16 func_00170670(s16 pcId, s16 index);
s16 func_001706c0(s16 pcId, s16 index);
void func_00170710(s16 pcId, s16 index, u16 value);
u16 func_00170a40(s16 pcId, s16 index);
s16 func_00170ab0(s16 pcId, s16 index);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
u32 func_00170c00(s16 pcId, s16 index, s16 delta);
void* func_00170d60(s16 id);
void* func_00170da0(s16 id);
void* func_00170df0(s16 id);
void* func_00170e40(s16 id);
u32 func_00171250(s16 id);
u16 func_001712d0(s16 id);
void func_00171390(u32 flag);
s32 func_001714b0(s32 index);
s32 func_001714d0(s32 index);
s32 func_001714f0(s32 index);
f32 func_00171510(s16 row, s16 column);
u8 func_00171550(s16 unused1, s16 unused2, u16 index);
u32 func_001715f0(s16 id);

// FUN_0016f3e0
void FUN_0016f3e0(u32 idx, u32 value)
{
    K_ASSERT((s32)idx < 128, 2007);

    gGlobalWork.auxData[idx] = value;
}

// FUN_0016f380
u32 FUN_0016f380(u32 idx)
{
    K_ASSERT((s32)idx < 128, 2001);

    return gGlobalWork.auxData[idx];
}

// FUN_0016c860
u16 datGetPersonaId(s16 pcId)
{
    DatPc* pc;
    s16 equipped;

    if (IS_HERO(pcId))
    {
        equipped = gGlobalWork.heroPersona.equippedPersona;

        K_ASSERT(equipped < 12, 633);

        return gGlobalWork.heroPersona.personas[equipped].id;
    }

    pc = &gPcs[2];

    return pc[pcId - 2].persona.id;
}

// FUN_0016cd60
DatUnit* datGetUnit(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return &gGlobalWork.heroUnit;
    }

    K_ASSERT(pcId < PC_MAX, 737);

    pc = &gPcs[2];

    return &pc[pcId - 2].unit;
}

// FUN_0016cdf0
void datInitUnit(s16 pcId)
{
    u32 idx;
    DatPc* pcsNoReserved;

    if (IS_HERO(pcId))
    {
        memset(&gGlobalWork.heroUnit, 0, sizeof(DatUnit));

        gGlobalWork.heroUnit.id = pcId;
        gGlobalWork.heroUnit.id2 = pcId;
        gGlobalWork.heroUnit.aiTactic = AI_TACTIC_ACT_FREELY;

        return;
    }

    idx = pcId - PC_YUKARI;
    pcsNoReserved = &gPcs[PC_YUKARI];
    memset(&pcsNoReserved[idx].unit, 0, sizeof(DatUnit));

    gPcs[pcId].unit.id = pcId;
    gPcs[pcId].unit.id2 = pcId;
    gPcs[pcId].unit.aiTactic = AI_TACTIC_ACT_FREELY;
}

static inline u8 datGetLevel_impl(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetLevel(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];
    return datCalcGetLevel(&pc[pcId - 2].unit);
}

// FUN_0016c470
u8 datGetLevel(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetLevel(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetLevel(&pc[pcId - 2].unit);
}

// FUN_0016c4f0
u16 datGetHp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetHp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetHp(&pc[pcId - 2].unit);
}

// FUN_0016c570
u16 datGetSp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetSp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetSp(&pc[pcId - 2].unit);
}

// FUN_0016c5f0
u16 datGetMaxHp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetMaxHp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetMaxHp(&pc[pcId - 2].unit);
}

// FUN_0016c910
s16 datGetEquippedPersona()
{
    return gGlobalWork.heroPersona.equippedPersona;
}

// FUN_0016c970
u32 datGetBadStatusNoDown(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetBadStatusNoDown(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetBadStatusNoDown(&pc[pcId - 2].unit);
}

// FUN_0016d8b0
void datSetBadStatus(s16 pcId, u32 flags)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        datCalcSetBadStatus(&gGlobalWork.heroUnit, flags);
        return;
    }

    pc = &gPcs[2];

    datCalcSetBadStatus(&pc[pcId - 2].unit, flags);
}

// FUN_0016d980
void datSetOldFatigueCounter(s16 pcId, u16 oldFatigueCounter)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.oldFatigueCounter = oldFatigueCounter;
        return;
    }

    gPcs[pcId].physicalState.oldFatigueCounter = oldFatigueCounter;
}

// FUN_0016d9d0
void datClearBadStatus(s16 pcId, u32 flags)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        datCalcClearBadStatus(&gGlobalWork.heroUnit, flags);
        return;
    }

    pc = &gPcs[2];

    datCalcClearBadStatus(&pc[pcId - 2].unit, flags);
}

static inline u32 datGetNextExp_impl(s16 pcId)
{
    DatPersonaWork* persona;

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.nextExp;
    }

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(persona != NULL, 622);
    return datPersonaGetNextExp(persona);
}

static inline u8 func_0016d280_impl(s32 exp)
{
    u8 index;
    u8 level;
    const u32* thresholds;

    level = 0;
    index = 0;
    thresholds = sPlayerExpThreshold;
    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)thresholds[index])
        {
            return level;
        }
        level++;
        index++;
    }
    return MAX_CHARACTER_LEVEL;
}

// FUN_0016d2f0
u32 datGetExpUntilNextLevel(s16 pcId)
{
    u8 level;
    u32 nextThreshold;

    if (func_0016d280_impl(datGetNextExp_impl(pcId)) == MAX_CHARACTER_LEVEL)
    {
        return 0;
    }

    level = func_0016d280_impl(datGetNextExp_impl(pcId)) + 1;
    K_ASSERT(level > 0 && level <= MAX_CHARACTER_LEVEL, 876);

    nextThreshold = sPlayerExpThreshold[level - 1];
    return nextThreshold - datGetNextExp_impl(pcId);
}

// FUN_0016d560
u8 datDidCharacterLevelUp(s16 pcId, u32 expGain)
{
    u8 level;
    u8 i;
    u8 count;
    u8 resultCount;
    u8 savedCount;
    s32 exp;
    const u32* thresholds;

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.nextExp += expGain;
        exp = gGlobalWork.heroStatus.nextExp;
        count = 0;
        i = 0;
        thresholds = sPlayerExpThreshold;
        for (; i < MAX_CHARACTER_LEVEL; i++)
        {
            if (exp < (s32)thresholds[i])
            {
                resultCount = count;
                goto saveCount;
            }
            count++;
        }
        resultCount = MAX_CHARACTER_LEVEL;
saveCount:
        savedCount = resultCount;
        goto getLevel;
    }
    else
    {
        K_ASSERT(false, 901);
    }

getLevel:
    level = datGetLevel_impl(pcId);
    if (savedCount != level)
    {
        return true;
    }
    return false;
}

// FUN_0016dad0
void datSetAiTactic(s16 pcId, s16 aiTacticId)
{
    K_ASSERT(aiTacticId < AI_TACTIC_MAX, 999);

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.aiTactic = aiTacticId;
        return;
    }

    gPcs[pcId].unit.aiTactic = aiTacticId;
}

// FUN_0016dd50
s32 datGetMoney()
{
    return gGlobalWork.heroMoney;
}

// FUN_0016dd60
s16 datGetPartyId(s32 idx)
{
    return gGlobalWork.partyIds[idx];
}

// FUN_0016dd80
s32 datGetAiTactic(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroUnit.aiTactic;
    }

    return gPcs[pcId].unit.aiTactic;
}

// FUN_0016d6b0
void datSetPhysicalCondition(s16 pcId, u16 physicalCondition)
{
    u16 currentPhysicalCondition;
    u16 oldFatigueCounter;

    if (IS_HERO(pcId))
    {
        currentPhysicalCondition = gGlobalWork.heroStatus.physicalState.physicalCondition;
    }
    else
    {
        currentPhysicalCondition = gPcs[pcId].physicalState.physicalCondition;
    }

    if (currentPhysicalCondition != physicalCondition)
    {
        switch (physicalCondition)
        {
            case PHYSICAL_CONDITION_GOOD:
                FUN_0016f3e0(pcId + 15, 0);
                break;
            case PHYSICAL_CONDITION_GREAT:
                FUN_0016f3e0(pcId + 15, 1);
                FUN_0016f3e0(pcId + 25, 0);
                break;
            case PHYSICAL_CONDITION_TIRED:
                FUN_0016f3e0(pcId + 15, 50);
                break;
            case PHYSICAL_CONDITION_SICK:
                FUN_0016f3e0(pcId + 15, 60);
                break;
        }
    }

    if (currentPhysicalCondition == PHYSICAL_CONDITION_TIRED && physicalCondition != PHYSICAL_CONDITION_TIRED)
    {
        extern void datSetFatigueCounter(s16, s16);
        if (IS_HERO(pcId))
        {
            oldFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
        }
        else
        {
            oldFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
        }
        datSetFatigueCounter(pcId, oldFatigueCounter);
    }

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.physicalCondition = physicalCondition;
    }
    else
    {
        gPcs[pcId].physicalState.physicalCondition = physicalCondition;
    }
}

// FUN_0016d930
void datSetFatigueCounter(s16 pcId, u16 fatigueCounter)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.fatigueCounter = fatigueCounter;
        return;
    }

    gPcs[pcId].physicalState.fatigueCounter = fatigueCounter;
}

// FUN_0016cf40
void datSetHp(s16 pcId, s16 hp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.hp = hp;
    }
    else
    {
        gPcs[pcId].unit.hp = hp;
    }
}

// FUN_0016cf90
void datSetSp(s16 pcId, s16 sp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.sp = sp;
    }
    else
    {
        gPcs[pcId].unit.sp = sp;
    }
}

// FUN_0016cef0
void datSetLevel(s16 pcId, u8 level)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.level = level;
    }
    else
    {
        K_ASSERT(false, 770);
    }
}

// FUN_0016d230
void datSetNextExp(s16 pcId, u32 nextExp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.nextExp = nextExp;
    }
    else
    {
        K_ASSERT(false, 858);
    }
}

// FUN_0016c9f0
u16 datGetFatigueCounter(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.fatigueCounter;
    }

    return gPcs[pcId].physicalState.fatigueCounter;
}

// FUN_0016ca40
u16 datGetOldFatigueCounter(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
    }

    return gPcs[pcId].physicalState.oldFatigueCounter;
}

// FUN_0016e920
void datSetActiveSocialLink(u16 activeSocialLink)
{
    gGlobalWork.heroStatus.activeSocialLink = activeSocialLink;
}

// FUN_0016e930
void datSetMoney(u32 money)
{
    K_ASSERT(money <= 9999999, 1674);

    gGlobalWork.heroMoney = money;
}

// FUN_0016e990
void datSetPartyId(s32 idx, s16 pcId)
{
    gGlobalWork.partyIds[idx] = pcId;
}

// FUN_0016e9b0
u32 datAddMoney(s32 amount)
{
    s32 finalMoney;

    finalMoney = amount + gGlobalWork.heroMoney;
    if (finalMoney > 9999999)
    {
        finalMoney = 9999999;
    }
    else if (finalMoney < 0)
    {
        finalMoney = 0;
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return finalMoney;
}

/* Removing this loses datScrCmd_SAVE_PARTY (MATCH nd0 -> MISMATCH nd8) - measured W161. */
// FUN_0016eb80
#pragma optimization_level 1
u32 datScrCmd_SAVE_PARTY()
{
    s16 i;
    u32 offset;
    DatGlobal* globalWork;
    s16 value;
    s16* savedIds;

    i = 0;
    globalWork = &gGlobalWork;
    savedIds = sSavedPartyIds;
    for (; i < 4; i++)
    {
        offset = (u32)(s16)i * 2;
        value = *(s16*)((u8*)globalWork + 0x44e0 + offset);
        *(s16*)((u8*)savedIds + offset) = value;
    }

    return true;
}
#pragma optimization_level 2

/* Removing this loses datScrCmd_RESTORE_PARTY (MATCH nd0 -> MISMATCH nd8) - measured W161. */
// FUN_0016ebe0
#pragma optimization_level 1
u32 datScrCmd_RESTORE_PARTY()
{
    s16 i;
    u32 offset;
    s16* savedIds;
    s16 value;
    DatGlobal* globalWork;

    i = 0;
    savedIds = sSavedPartyIds;
    globalWork = &gGlobalWork;
    for (; i < 4; i++)
    {
        offset = (u32)(s16)i * 2;
        value = *(s16*)((u8*)savedIds + offset);
        *(s16*)((u8*)globalWork + 0x44e0 + offset) = value;
    }
    return true;
}
#pragma optimization_level 2

// FUN_0016ec40
u32 datScrCmd_CLEAR_PARTY_ID()
{
    gGlobalWork.partyIds[scrGetIntPara(0)] = PC_NONE;

    return true;
}

// FUN_0016ec80
u32 datScrCmd_GET_PARTY_ID()
{
    scrSetIntReturnVal(gGlobalWork.partyIds[scrGetIntPara(0)]);

    return true;
}

// FUN_0016edd0
u32 datScrCmd_GET_MONEY()
{
    scrSetIntReturnVal(gGlobalWork.heroMoney);

    return true;
}

// FUN_0016ee00
u32 datScrCmd_ADD_MONEY()
{
    s32 baseMoney;
    s32 finalMoney;

    baseMoney = gGlobalWork.heroMoney;
    finalMoney = baseMoney + scrGetIntPara(0);
    if (finalMoney > 9999999)
    {
        finalMoney = 9999999;
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return true;
}

// FUN_0016ee90
u32 datScrCmd_REMOVE_MONEY()
{
    s32 baseMoney;
    s32 finalMoney;

    baseMoney = gGlobalWork.heroMoney;
    if (baseMoney < scrGetIntPara(0))
    {
        finalMoney = 0;
    }
    else
    {
        finalMoney = baseMoney - scrGetIntPara(0);
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return true;
}

// FUN_0016ef20
s16 datGetDaysSinceApr5()
{
    return gGlobalWork.calendarWork.daysSinceApr5;
}

// FUN_0016ef30
u8 datGetTime()
{
    return gGlobalWork.calendarWork.time;
}

// FUN_0016ef40
s16 datGetDaysSkipTarget()
{
    return gGlobalWork.calendarWork.daysSkipTarget;
}

// FUN_0016ef50
u8 datGetTimeSkipTarget()
{
    return gGlobalWork.calendarWork.timeSkipTarget;
}

// FUN_0016ef60
u32 datGetSkipToTarget()
{
    return gGlobalWork.calendarWork.skipToTarget;
}

// FUN_0016cfe0
void datSetAcademicPoint(s16 pcId, s16 academicPoint)
{
    K_ASSERT(academicPoint >= SOCIAL_STAT_MIN_POINT && academicPoint <= SOCIAL_STAT_MAX_POINT, 797);

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.socialStats.academicPoint = academicPoint;
        return;
    }

    gPcs[pcId].socialStats.academicPoint = academicPoint;
}

// FUN_0016d090
void datSetCharmPoint(s16 pcId, s16 charmPoint)
{
    K_ASSERT(charmPoint >= SOCIAL_STAT_MIN_POINT && charmPoint <= SOCIAL_STAT_MAX_POINT, 808);

    if (IS_HERO(pcId))
    {
        datGetCharmLevel(gGlobalWork.heroStatus.socialStats.charmPoint);
        gGlobalWork.heroStatus.socialStats.charmPoint = charmPoint;
        datGetCharmLevel(gGlobalWork.heroStatus.socialStats.charmPoint);
        return;
    }

    gPcs[pcId].socialStats.charmPoint = charmPoint;
}

// FUN_0016d160
void datSetCouragePoint(s16 pcId, s16 couragePoint)
{
    K_ASSERT(couragePoint >= SOCIAL_STAT_MIN_POINT && couragePoint <= SOCIAL_STAT_MAX_POINT, 828);

    if (IS_HERO(pcId))
    {
        datGetCourageLevel(gGlobalWork.heroStatus.socialStats.couragePoint);
        gGlobalWork.heroStatus.socialStats.couragePoint = couragePoint;
        datGetCourageLevel(gGlobalWork.heroStatus.socialStats.couragePoint);
        return;
    }

    gPcs[pcId].socialStats.couragePoint = couragePoint;
}

// FUN_0016c6f0
s16 datGetAcademicPoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.academicPoint;
    }

    return gPcs[pcId].socialStats.academicPoint;
}

// FUN_0016c740
s16 datGetCharmPoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.charmPoint;
    }

    return gPcs[pcId].socialStats.charmPoint;
}

// FUN_0016c790
s16 datGetCouragePoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.couragePoint;
    }

    return gPcs[pcId].socialStats.couragePoint;
}

// FUN_0016ca90
void FUN_0016ca90(s16 pcId, s16 fatigueChange)
{
    extern void datSetFatigueCounter(s16, s16);
    u16 rawFatigueCounter;
    s32 fatigueCounter;
    s32 oldFatigueCounter;
    s32 newFatigueCounter;

    if (IS_HERO(pcId))
    {
        rawFatigueCounter = gGlobalWork.heroStatus.physicalState.fatigueCounter;
    }
    else
    {
        rawFatigueCounter = gPcs[pcId].physicalState.fatigueCounter;
    }
    fatigueCounter = rawFatigueCounter;

    if (IS_HERO(pcId))
    {
        rawFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
    }
    else
    {
        rawFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
    }
    oldFatigueCounter = rawFatigueCounter;

    newFatigueCounter = fatigueCounter + fatigueChange;
    if (newFatigueCounter < 0)
    {
        newFatigueCounter = 0;
    }
    else if (newFatigueCounter > oldFatigueCounter)
    {
        newFatigueCounter = oldFatigueCounter;
    }

    datSetFatigueCounter(pcId, newFatigueCounter);
}

// FUN_0016c7e0
u32 datGetNextExp(s16 pcId)
{
    DatPersonaWork* persona; // per

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.nextExp;
    }

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(persona != NULL, 622);

    return datPersonaGetNextExp(persona);
}

// FUN_0016c920
u16 datGetPhysicalCondition(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.physicalCondition;
    }

    return gPcs[pcId].physicalState.physicalCondition;
}

// FUN_0016dd40
s16 datGetActiveSocialLink()
{
    return gGlobalWork.heroStatus.activeSocialLink;
}

// FUN_00171360
u32 dat00171360(u16 param_1)
{
    if (param_1 < 5000)
    {
        return 0;
    }

    return param_1 < 0x1408;
}

// FUN_001717b0
s16 *datGetActiveSocialLinkPtr()
{
    return &gGlobalWork.heroStatus.activeSocialLink;
}

// FUN_0016dba0
s8 datGetSocialLinkLevel(s16 socialLink)
{
    return gGlobalWork.heroStatus.socialLinkStat[socialLink];
}

// FUN_0016e100
u32 datSocialLinkLevelIsNotZero(s16 socialLink)
{
    u32 isValidSocialLink;

    if (socialLink < SOCIAL_LINK_SEES || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    K_ASSERT(isValidSocialLink, 1429);

    if (gGlobalWork.heroStatus.socialLinkStat[socialLink] <= 0)
    {
        return false;
    }

    return true;
}

// FUN_0016cb80
s16 datGetEquipmentIdx(s16 pcId, s16 equipmentType)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroEquip.equipmentsIdx[equipmentType];
    }

    pc = &gPcs[2];

    return pc[pcId - 2].equipmentsIdx[equipmentType];
}

// FUN_0016da50
void datSetEquipmentIdx(s16 pcId, s16 equipmentType, s16 equipmentIdx)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroEquip.equipmentsIdx[equipmentType] = equipmentIdx;
    }
    else
    {
        gPcs[pcId].equipmentsIdx[equipmentType] = equipmentIdx;
    }
}

// FUN_0016ef70. Updates 'daysSinceApr5' and sets the correct 'FLG_DAY_*' flags
void datSetDaysSinceApr5(s16 daysSinceApr5)
{
    u32 currentWeekDay;

    datSetFlag(FLG_DAY_IS_MONDAY, false);
    datSetFlag(FLG_DAY_IS_TUESDAY, false);
    datSetFlag(FLG_DAY_IS_WEDNESDAY, false);
    datSetFlag(FLG_DAY_IS_THURSDAY, false);
    datSetFlag(FLG_DAY_IS_FRIDAY, false);
    datSetFlag(FLG_DAY_IS_SATURDAY, false);
    datSetFlag(FLG_DAY_IS_SUNDAY, false);
    datSetFlag(FLG_DAY_IS_DAYOFF, false);

    if (daysSinceApr5 != gGlobalWork.calendarWork.daysSinceApr5)
    {
        FUN_00172890(); 
        FUN_00172e10();
        datSetFlag(2444, false);
    }

    gGlobalWork.calendarWork.daysSinceApr5 = daysSinceApr5;

    currentWeekDay = datGetCurrentWeekDay();
    switch (currentWeekDay)
    {
        case CALENDAR_DAY_SUNDAY:    datSetFlag(FLG_DAY_IS_SUNDAY, true);    break;
        case CALENDAR_DAY_MONDAY:    datSetFlag(FLG_DAY_IS_MONDAY, true);    break;
        case CALENDAR_DAY_TUESDAY:   datSetFlag(FLG_DAY_IS_TUESDAY, true);   break;
        case CALENDAR_DAY_WEDNESDAY: datSetFlag(FLG_DAY_IS_WEDNESDAY, true); break;
        case CALENDAR_DAY_THURSDAY:  datSetFlag(FLG_DAY_IS_THURSDAY, true);  break;
        case CALENDAR_DAY_FRIDAY:    datSetFlag(FLG_DAY_IS_FRIDAY, true);    break;
        case CALENDAR_DAY_SATURDAY:  datSetFlag(FLG_DAY_IS_SATURDAY, true);  break;
    }

    if (clndIsHolidayOrSunday())
    {
        datSetFlag(FLG_DAY_IS_DAYOFF, true);
    }
}

// FUN_0016f150
void datSetTime(u8 time)
{
    gGlobalWork.calendarWork.time = time;
}

// FUN_0016f160
void datSetDaysSkipTarget(s16 days)
{
    gGlobalWork.calendarWork.daysSkipTarget = days;
}

// FUN_0016f170
void datSetTimeSkipTarget(s8 time)
{
    gGlobalWork.calendarWork.timeSkipTarget = time;
}

// FUN_0016f180
void datSetSkipToTarget(u32 val)
{
    gGlobalWork.calendarWork.skipToTarget = val;
}

// FUN_0016f190
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (gGlobalWork.flags[idx] & (1 << mask)) != 0;
}

// FUN_0016f1f0. See 'g_flags.h' !!!
void datSetFlag(s32 bit, u8 enabled)
{
    s32 mask;
    s32 idx;

    K_ASSERT(bit >= 0 && bit < FLG_MAX, 1933);

    if (bit == 4982)
    {
        printf("hit \n");
    }

    idx = bit / 32;
    mask = bit % 32;
    mask = 1 << mask;
    
    if (enabled)
    {
        gGlobalWork.flags[idx] |= mask;
        return;
    }

    gGlobalWork.flags[idx] &= ~mask;
}

// FUN_0016f2e0
void datClearFlagAll()
{
    s32 i;
    DatGlobal* work;
    u32* p;

    i = 0;
    work = &gGlobalWork;
    for (; i < FLG_ARR_SIZE; i++)
    {
        p = work->flags + i;
        *p = 0;
    }
}

// FUN_0016f320
void func_0016f320(void)
{
    gGlobalWork.flags[12] |= 0x8;
    gGlobalWork.flags[12] |= 0x10;
    gGlobalWork.flags[12] &= ~0x20;
    gGlobalWork.flags[12] |= 0x40;
    gGlobalWork.flags[12] &= ~0x80;
    gGlobalWork.flags[12] &= ~0x100;
    gGlobalWork.flags[12] &= ~0x200;

    func_001754a0(1);
}

// FUN_0016f450
void dat0016f450(void)
{
    s32 i;
    DatGlobal* work;
    u32* p;

    i = 0;
    work = &gGlobalWork;
    for (; i < 0x7f; i++)
    {
        p = work->auxData + i;
        *p = 0;
    }
}

// FUN_0016f490
s32 func_0016f490(s16 pcId)
{
    s32 count;
    s32 pcValue;

    count = 0;
    pcValue = pcId;
    if (pcValue == -1)
    {
        s32 index;
        DatEquipment* equipment;

        index = 0;
        equipment = (DatEquipment*)D_00833E80;
        for (; index < 20; index++)
        {
            if (equipment[index].id != 0)
            {
                count++;
            }
        }
        return count;
    }

    if (pcValue == 1)
    {
        s32 index;
        DatEquipment* equipment;

        index = 0;
        equipment = gGlobalWork.heroEquip.equipments;
        for (; index < 300; index++)
        {
            if (equipment[index].id != 0)
            {
                count++;
            }
        }
        return count;
    }

    if (pcValue >= 0x100)
    {
        s32 index;
        u8* equipment;

        index = 0;
        equipment = D_00834010 + pcValue * sizeof(DatPc);
        for (; index < 4; index++)
        {
            if (*(u16*)(equipment + index * sizeof(DatEquipment) - 0x36948) != 0)
            {
                count++;
            }
        }
        return count;
    }

    {
        s32 index;
        u8* equipment;

        index = 0;
        equipment = D_00834010 + pcValue * sizeof(DatPc);
        for (; index < 4; index++)
        {
            if (*(u16*)(equipment + index * sizeof(DatEquipment) - 0x66c) != 0)
            {
                count++;
            }
        }
    }

    return count;
}

// FUN_0016f630
u16 datGetEquipmentId(s16 pcId, s32 equipmentIdx)
{
    s32 offset;
    u8* equipment;

    if (pcId == -1)
    {
        offset = equipmentIdx * 0x14;
        return *(u16*)(D_00833E80 + offset);
    }
    else if (IS_HERO(pcId))
    {
        offset = equipmentIdx * 0x14;
        equipment = (u8*)gGlobalWork.heroEquip.equipments;
        return *(u16*)(equipment + offset);
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6C8 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339A4 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f720
u32 func_0016f720(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u32*)(D_00833E84 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].type;
    }
    else if (pcId >= 0x100)
    {
        return *(u32*)(D_007FD6CC + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u32*)(D_008339A8 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f810
u8 func_0016f810(s16 pcId, s32 equipmentIdx)
{
    u8* base;

    if (pcId == -1)
    {
        return *(u8*)(D_00833E88 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx * 0x14 + 8];
    }
    else if (pcId >= 0x100)
    {
        return *(u8*)(D_007FD6D0 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u8*)(D_008339AC + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f900
u8 datGetEquipmentEffect(s16 pcId, s32 equipmentIdx)
{
    u8* base;

    if (pcId == -1)
    {
        return *(u8*)(D_00833E89 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx * 0x14 + 9];
    }
    else if (pcId >= 0x100)
    {
        return *(u8*)(D_007FD6D1 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u8*)(D_008339AD + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f9f0
u16 func_0016f9f0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8A + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].firstStat;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D2 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339AE + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fae0
u16 func_0016fae0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8C + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].secondStat;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D4 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B0 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fbd0
u16 func_0016fbd0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8E + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].unk_0e;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D6 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B2 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fcc0
u16 func_0016fcc0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E90 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].unk_10;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D8 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B4 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fdb0
DatEquipment* func_0016fdb0(s16 pcId, s32 equipmentIdx)
{
    s32 pcIndex;

    if (pcId == -1)
    {
        return (DatEquipment*)(D_00833E80 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        return &gGlobalWork.heroEquip.equipments[equipmentIdx];
    }
    else if (pcId >= 0x100)
    {
        pcIndex = pcId - 0x102;
        return (DatEquipment*)((u8*)D_00834010 + pcIndex * 0x364 +
                               equipmentIdx * 0x14 + 0x180);
    }

    pcIndex = pcId - 2;
    return (DatEquipment*)((u8*)D_00834010 + pcIndex * 0x364 +
                           equipmentIdx * 0x14 + 0x5c);
}

// FUN_0016fea0
void func_0016fea0(s16 pcId, s32 equipmentIdx, u16 id)
{
    u8* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E80 + equipmentIdx * 0x14) = id;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        *(u16*)&base[equipmentIdx * 0x14] = id;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6C8 + pcId * 0x364 + equipmentIdx * 0x14) = id;
    }
    else
    {
        *(u16*)(D_008339A4 + pcId * 0x364 + equipmentIdx * 0x14) = id;
    }
}

// FUN_0016ff90
void func_0016ff90(s16 pcId, s32 equipmentIdx, u32 type)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u32*)(D_00833E84 + equipmentIdx * 0x14) = type;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].type = type;
    }
    else if (pcId >= 0x100)
    {
        *(u32*)(D_007FD6CC + pcId * 0x364 + equipmentIdx * 0x14) = type;
    }
    else
    {
        *(u32*)(D_008339A8 + pcId * 0x364 + equipmentIdx * 0x14) = type;
    }
}

// FUN_00170080
void func_00170080(s16 pcId, s32 equipmentIdx, u8 value)
{
    u8* base;

    if (pcId == -1)
    {
        *(u8*)(D_00833E88 + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        base[equipmentIdx * 0x14 + 8] = value;
    }
    else if (pcId >= 0x100)
    {
        *(u8*)(D_007FD6D0 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u8*)(D_008339AC + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170170
void func_00170170(s16 pcId, s32 equipmentIdx, u8 effect)
{
    u8* base;

    if (pcId == -1)
    {
        *(u8*)(D_00833E89 + equipmentIdx * 0x14) = effect;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        base[equipmentIdx * 0x14 + 9] = effect;
    }
    else if (pcId >= 0x100)
    {
        *(u8*)(D_007FD6D1 + pcId * 0x364 + equipmentIdx * 0x14) = effect;
    }
    else
    {
        *(u8*)(D_008339AD + pcId * 0x364 + equipmentIdx * 0x14) = effect;
    }
}

// FUN_00170260
void func_00170260(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8A + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].firstStat = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D2 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339AE + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170350
void func_00170350(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8C + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].secondStat = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D4 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B0 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170440
void func_00170440(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8E + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].unk_0e = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D6 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B2 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170530
void func_00170530(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E90 + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].unk_10 = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D8 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B4 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_0016c670
u16 func_0016c670(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return func_00300100(&gGlobalWork.heroUnit);
    }

    return func_00300100(&gPcs[pcId - 2].unit);
}

// FUN_0016cc00
u16 func_0016cc00(s16 pcId)
{
    u8 level;

    if (IS_HERO(pcId))
    {
        level = datCalcGetLevel(&gGlobalWork.heroUnit);
    }
    else
    {
        DatPc* pc = &gPcs[2];
        level = datCalcGetLevel(&pc[pcId - 2].unit);
    }

    return *(u16*)(D_005DC1B4 + level * 0x2c + pcId * 4);
}

// FUN_0016ccb0
u16 func_0016ccb0(s16 pcId)
{
    u8 level;

    if (IS_HERO(pcId))
    {
        level = datCalcGetLevel(&gGlobalWork.heroUnit);
    }
    else
    {
        DatPc* pc = &gPcs[2];
        level = datCalcGetLevel(&pc[pcId - 2].unit);
    }

    return *(u16*)(D_005DC1B4 + level * 0x2c + pcId * 4);
}


/* Removing this loses FUN_0016d280 (MATCH nd0 -> MISMATCH nd19) - measured W161. */
// FUN_0016d280
#pragma opt_loop_invariants on
u8 func_0016d280(s32 exp)
{
    u8 level = 0;
    u8 index = 0;

    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)sPlayerExpThreshold[index])
        {
            return level;
        }
        level++;
        index++;
    }

    return MAX_CHARACTER_LEVEL;
}
#pragma opt_loop_invariants off

/* Removing this loses FUN_0016dbc0 (MATCH nd0 -> MISMATCH nd108) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0016dbc0
u8 func_0016dbc0(s16 socialLink, u32* personaId)
{
    s8 arcana;
    u32 found = false;
    u8 bestLevel = 0;
    s32 bestPersonaId = -1;
    u16 i;

    arcana = (s8)func_0016df30(socialLink);
    for (i = 0; i < 12; i++)
    {
        DatPersonaWork* persona;
        u8 personaArcana;

        if (!datPersonaHeroPersonaValid(i))
        {
            continue;
        }

        persona = datPersonaGetHeroPersona(i);
        personaArcana = (u8)FUN_00173280(persona->id);
        if (personaArcana != arcana ||
            bestLevel >= persona->level)
        {
            continue;
        }

        found = true;
        bestPersonaId = persona->id;
        bestLevel = persona->level;
    }

    if (found == true)
    {
        *personaId = bestPersonaId;
        return true;
    }

    return false;
}
#pragma opt_loop_invariants off

// FUN_0016dce0
u32 func_0016dce0(s16 socialLink)
{
    if (socialLink < 0 || socialLink >= 30)
    {
        return false;
    }
    return true;
}

// FUN_0016dd20
s8 func_0016dd20(s16 socialLink)
{
    return gGlobalWork.heroStatus.socialLinkData[0x78 + socialLink];
}

// FUN_0016ddd0
void func_0016ddd0(s32 index)
{
    u8* value;

    K_ASSERT(index < 8 && index >= 0, 1257);
    value = D_00836773 + index;
    if (*value < 200)
    {
        *value += 1;
    }
    else
    {
        *value = 200;
    }
}

// FUN_0016de50
u8 func_0016de50(s32 index)
{
    K_ASSERT(index < 8 && index >= 0, 1290);

    return gGlobalWork.heroStatus.socialLinkData[0x4df + index];
}

/* Removing this loses FUN_0016deb0 (MATCH nd0 -> MISMATCH nd47) - measured W161. */
// FUN_0016deb0
#pragma opt_loop_invariants on
s16 func_0016deb0(s16 arcana)
{
    s32 socialLink;
    s32 bestLevel;
    s16 bestLink;

    bestLevel = -1;
    bestLink = bestLevel;
    for (socialLink = 0; socialLink < 30; socialLink++)
    {
        if (D_005E3220[socialLink] == arcana &&
            bestLevel < gGlobalWork.heroStatus.socialLinkStat[socialLink])
        {
            bestLink = socialLink;
            bestLevel = gGlobalWork.heroStatus.socialLinkStat[socialLink];
        }
    }

    return bestLink;
}
#pragma opt_loop_invariants off

// FUN_0016df30
s8 func_0016df30(s16 socialLink)
{
    u32 valid;

    if (socialLink < 0 || socialLink >= 30)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    if (!valid)
    {
        FUN_0019d3f0((u32)D_005E3098, 0x54b);
    }

    return ((s8*)D_005E3220)[socialLink];
}

#pragma opt_propagation off
// FUN_0016dfb0
void func_0016dfb0(s16 socialLink)
{
    s32 rank;
    s16 finalSocialLink;
    s16 socialLinkValue;
    u32 valid;

    if (socialLink < 0 || socialLink >= 30)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 1370);
    if (datSocialLinkLevelIsNotZero(socialLink) != true)
    {
        func_0016e410(socialLink, 1);
        socialLinkValue = socialLink;
        FUN_00171E90(socialLinkValue, 0);
        FUN_00171C40(socialLinkValue, 0);
        FUN_00172200_s16(socialLinkValue, 0);
        for (rank = 1; rank <= 10; rank++)
        {
            FUN_001724A0(socialLinkValue, rank, false);
            FUN_001723A0(socialLinkValue, rank, false);
        }
        finalSocialLink = socialLink;
        FUN_001723A0(finalSocialLink, 1, true);
        FUN_001724A0(finalSocialLink, 1, true);
    }
}
#pragma opt_propagation on

// FUN_0016e190
s16 func_0016e190(s32 socialLink)
{
    struct LinkedSocialLink
    {
        s16 socialLink;
        s16 value;
    };
    s32 i;
    s32 socialLinkOffset;
    struct LinkedSocialLink links[2][3] = {
        { { 12, 1 }, { 13, 2 }, { 14, 3 } },
        { { 17, 4 }, { 18, 5 }, { 19, 6 } }
    };
    struct LinkedSocialLink* selectedLinks;

    i = 0;
    socialLinkOffset = socialLink * 3;
    selectedLinks = &links[0][0] + socialLinkOffset;
    for (; i < 3; i++)
    {
        s16 linkedSocialLink;
        u32 valid;

        linkedSocialLink = selectedLinks[i].socialLink;
        if (linkedSocialLink < 0 || linkedSocialLink >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        K_ASSERT(valid, 1429);
        if (((s8*)&gGlobalWork)[linkedSocialLink + 0x76] > 0)
        {
            return (&links[0][0])[i + socialLinkOffset].value;
        }
    }

    return 0;
}

// FUN_0016e2b0 NONMATCHING
void func_0016e2b0(s16 socialLink, s32 amount)
{
    s8* socialLinkBase;
    s8 level;
    u32* progress;
    u32* table;
    u32 personaId;

    socialLinkBase = gGlobalWork.heroStatus.socialLinkStat + socialLink;
    level = socialLinkBase[0];
    if (socialLink < 0 || socialLink >= 30)
    {
        return;
    }
    socialLink = socialLinkBase[0x76];
    if (socialLink <= 0 || socialLink >= 10)
    {
        return;
    }
    if (func_0016dbc0(socialLink, &personaId) == true)
    {
        amount = (s32)((f32)amount * FUN_003BDB80());
    }
    progress = (u32*)((u8*)&gGlobalWork + 0x94 + socialLink * 4);
    *progress += amount;
    table = (u32*)FUN_003BDD90();
    K_ASSERT(table != NULL, 1495);
    if (*progress < table[(u8)level - 1])
    {
        return;
    }
    *progress = table[(u8)level - 1];
    FUN_001723A0(socialLink, level + 1, true);
}
#pragma opt_propagation off
// FUN_0016e410
void func_0016e410(s16 socialLink, s8 level)
{
    extern u8 D_00836294[];
    s16 socialLinkValue;
    s32 levelValue;
    s32 rank;
    u32 valid;
    u32 enabled;
    u32 tableValue;
    u32* tableWords;
    u8* table;

    levelValue = level;
    K_ASSERT(levelValue <= 10, 1516);
    socialLinkValue = socialLink;
    gGlobalWork.heroStatus.socialLinkStat[socialLinkValue] = level;
    FUN_00171B50(socialLinkValue);

    if (levelValue < 2)
    {
        if (socialLinkValue < 0 || socialLinkValue >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        if (valid)
        {
            *(u32*)(D_00836294 + socialLinkValue * 4) = 0;
        }
    }
    if (levelValue > 1 && levelValue <= 10)
    {
        table = FUN_003BDD90(socialLinkValue);
        K_ASSERT(table != NULL, 1528);
        tableWords = (u32*)table;
        tableValue = tableWords[levelValue - 2];
        if (socialLinkValue < 0 || socialLinkValue >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        if (valid)
        {
            *(u32*)(D_00836294 + socialLinkValue * 4) =
                tableValue;
        }
    }

    for (rank = 1; rank <= 10; rank++)
    {
        enabled = false;
        if (rank <= levelValue)
        {
            enabled = true;
        }
        FUN_001723A0(socialLinkValue, rank, enabled);
        FUN_001724A0(socialLinkValue, rank, enabled);
    }
    func_0016e5f0_call(socialLink, 0);
}
#pragma opt_propagation on

// FUN_0016e5f0
void func_0016e5f0(s32 socialLink, s8 progress)
{
    u32 isValidSocialLink;
    s16 index;
    s8* base;
    s8* value;

    index = socialLink;
    if (index < 0 || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    base = (s8*)&gGlobalWork + 0x630c;
    value = base + (s16)socialLink;
    *value = progress;
    if (progress < 0)
    {
        *value = 0;
    }
    if (*value >= 10)
    {
        *value = 9;
    }
}

// FUN_0016e670
void func_0016e670(s16 socialLink)
{
    u32 isValidSocialLink;
    s16 index;
    s8* base;
    s8* progress;

    index = socialLink;
    if (index < 0 || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    if (index < SOCIAL_LINK_SEES || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }
    K_ASSERT(isValidSocialLink, 1429);

    if (gGlobalWork.heroStatus.socialLinkStat[index] <= 0)
    {
        K_ABORT(D_005E3260, 0x620);
        return;
    }
    base = (s8*)&gGlobalWork + 0x10c;
    progress = base + (s64)socialLink;
    *progress += 1;
    if (*progress < 0)
    {
        *progress = 0;
    }
    if (*progress >= 10)
    {
        *progress = 9;
    }
}

// FUN_0016e7a0
void func_0016e7a0(s16 socialLink, s16 day)
{
    u32 isValidSocialLink;

    if (socialLink < 0 || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    if (day < 0)
    {
        ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = 0;
        return;
    }
    if (day <= 360)
    {
        goto dayInRange;
    }
    day = 360;
    ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = day;
    return;

dayInRange:
    ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = day;
}

// FUN_0016e850
s16 func_0016e850(s16 socialLink)
{
    u32 isValidSocialLink;
    s16* dayPtr;
    s16 day;

    if (socialLink < 0 || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    K_ASSERT(isValidSocialLink, 1612);
    dayPtr = ((s16*)((u8*)&gGlobalWork + 0x632a)) + socialLink;
    if (*dayPtr == 0)
    {
        return 0;
    }

    day = datGetDaysSinceApr5() - *dayPtr;
    K_ASSERT(day >= 0, 1620);
    return day;
}

// FUN_0016ea40
s32 func_0016ea40(s32 amount)
{
    s32 total = amount + gGlobalWork.heroMoney;

    if (total > 9999999)
    {
        return 1;
    }
    return -(total < 0);
}

/* Removing this loses FUN_0016ea80 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0016ea80
u32 func_0016ea80(void)
{
    s32 i;
    s32 j;
    s32 found = false;
    s16* slot;

    for (i = 0; i < 3; i++)
    {
        if (gGlobalWork.partyIds[i] == scrGetIntPara(1))
        {
            found = true;
        }
    }

    if (!found)
    {
        for (j = 0; j < 3; j++)
        {
            slot = &gGlobalWork.partyIds[j];
            if (*slot == PC_NONE)
            {
                *slot = scrGetIntPara(1);
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        gGlobalWork.partyIds[3] = scrGetIntPara(1);
    }

    return true;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_0016ecd0 (MATCH nd0 -> MISMATCH nd105) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0016ecd0
u32 func_0016ecd0(void)
{
    s32 i;
    s32 j;
    s16* slot;
    s16 current;

    for (i = 0; i < 4; i++)
    {
        slot = &gGlobalWork.partyIds[i];
        current = *slot;
        if (current == scrGetIntPara(0))
        {
            *slot = PC_NONE;
            break;
        }
    }

    for (j = 0; j < 4; j++)
    {
        if (gGlobalWork.partyIds[j] == PC_NONE)
        {
            for (; j < 3; j++)
            {
                gGlobalWork.partyIds[j] = gGlobalWork.partyIds[j + 1];
            }
            break;
        }
    }

    return true;
}
#pragma opt_loop_invariants off

// FUN_00170620
u8* func_00170620(s16 pcId, s16 index)
{
    return gPcs[pcId - 2].unkData2 + index * 4;
}

// FUN_00170670
u16 func_00170670(s16 pcId, s16 index)
{
    return *(u16*)(D_008339F4 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_001706c0
s16 func_001706c0(s16 pcId, s16 index)
{
    return *(u16*)(D_008339F6 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170710
void func_00170710(s16 pcId, s16 index, u16 value)
{
    *(u16*)(D_008339F6 + pcId * sizeof(DatPc) + index * 4) = value;
}

static inline u16 func_00170760_impl(s16 pcId, s16 index)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;

    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this inline-helper qualifier loses func_00170c00 (MATCH nd0 -> MISMATCH nd15, size 348 -> 348) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        return *(u16*)(address - 8000);
    }
    if (pcId == -1)
    {
        return *(u16*)(D_00831CE0 + index * 2);
    }
    if (pcId < 0x100)
    {
        goto invalid;
    }

    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            return *(u16*)(D_007FD85A + pcId * 0x364 + i * 4);
        }
    }
    return 0;
invalid:
    return 0;
}

// FUN_00170760
u16 func_00170760(s16 pcId, s16 index)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;

    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this qualifier loses func_00170760 (MATCH nd0 -> MISMATCH nd15, size 256 -> 256) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        return *(u16*)(address - 8000);
    }
    if (pcId == -1)
    {
        return *(u16*)(D_00831CE0 + index * 2);
    }
    if (pcId < 0x100)
    {
        goto invalid;
    }

    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            return *(u16*)(D_007FD85A + pcId * 0x364 + i * 4);
        }
    }
    return 0;
invalid:
    return 0;
}


// FUN_00170860 NONMATCHING
void func_00170860(s16 pcId, s16 index, u16 value)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;
    s32 j;

    K_ASSERT(value <= 99, 2341);
    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this qualifier worsens func_00170860 (NONMATCHING nd68 -> NONMATCHING nd83, size 476 -> 476) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        *(u16*)(address - 8000) = value;
        goto done;
    }
    if (pcId == -1)
    {
        *(u16*)(D_00831CE0 + index * 2) = value;
        goto done;
    }
    if (pcId < 0x100)
    {
        goto done;
    }
    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            *(u16*)(D_007FD85A + pcId * 0x364 + i * 4) = value;
            if (value == 0)
            {
                *(u16*)(D_007FD858 + pcId * 0x364 + i * 4) = 0;
            }
            goto done;
        }
    }

    j = 0;
    for (; j < 20; j++)
    {
        if (*(u16*)(idBase + j * 4 - 0x367b8) == 0)
        {
            *(u16*)(D_007FD85A + pcId * 0x364 + j * 4) = value;
            if (value == 0)
            {
                *(u16*)(D_007FD858 + pcId * 0x364 + j * 4) = 0;
            }
            goto done;
        }
    }
done:
    return;
}

// FUN_00170a40
u16 func_00170a40(s16 pcId, s16 index)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    return *(u16*)(D_00833C58 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170ab0
s16 func_00170ab0(s16 pcId, s16 index)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    return *(u16*)(D_00833C5A + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170b20
void func_00170b20(s16 pcId, s16 index, u16 value)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    *(u16*)(D_00833C58 + pcId * sizeof(DatPc) + index * 4) = value;
}

// FUN_00170b90
void func_00170b90(s16 pcId, s16 index, u16 value)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    *(u16*)(D_00833C5A + pcId * sizeof(DatPc) + index * 4) = value;
}

// FUN_00170c00
u32 func_00170c00(s16 pcId, s16 index, s16 delta)
{
    s32 value = func_00170760_impl(pcId, index) + delta;

    if (value >= 99)
    {
        value = 99;
    }
    else if (value < 0)
    {
        value = 0;
    }
    func_00170860(pcId, index, value);
    return value;
}

static inline void* func_00170d60_impl(s16 id)
{
    if (id < 1000)
    {
        return D_007CDFE4 + id * 0x28;
    }
    return NULL;
}

static inline void* func_00170da0_impl(s16 id)
{
    if (id >= 1000 && id < 2000)
    {
        return D_007CDFDC + (id - 1000) * 0x20;
    }
    return NULL;
}

static inline void* func_00170df0_impl(s16 id)
{
    if (id >= 2000 && id < 3000)
    {
        return D_007CDFD8 + (id - 2000) * 0x20;
    }
    return NULL;
}

static inline void* func_00170e40_impl(s16 id)
{
    if (id >= 3000 && id < 4000)
    {
        return D_007CDFD4 + (id - 3000) * 0x24;
    }
    return NULL;
}

static inline void* func_00170e90_impl(s16 id)
{
    if (id >= 3000)
    {
        return D_007CDFCC + (id - 4000) * 0x1c;
    }
    return NULL;
}

static inline void* func_00170ed0_impl(s16 id, s32* category)
{
    if (id < 1000)
    {
        *category = 0;
        return func_00170d60_impl(id);
    }
    if (id < 2000)
    {
        *category = 1;
        return func_00170da0_impl(id);
    }
    if (id < 3000)
    {
        *category = 2;
        return func_00170df0_impl(id);
    }
    if (id < 4000)
    {
        *category = 3;
        return func_00170e40_impl(id);
    }

    *category = 4;
    return func_00170e90_impl(id);
}

// FUN_00170d60
void* func_00170d60(s16 id)
{
    if (id < 1000)
    {
        return D_007CDFE4 + id * 0x28;
    }
    return NULL;
}

// FUN_00170da0
void* func_00170da0(s16 id)
{
    if (id >= 1000 && id < 2000)
    {
        return D_007CDFDC + (id - 1000) * 0x20;
    }
    return NULL;
}

// FUN_00170df0
void* func_00170df0(s16 id)
{
    if (id >= 2000 && id < 3000)
    {
        return D_007CDFD8 + (id - 2000) * 0x20;
    }
    return NULL;
}

// FUN_00170e40
void* func_00170e40(s16 id)
{
    if (id >= 3000 && id < 4000)
    {
        return D_007CDFD4 + (id - 3000) * 0x24;
    }
    return NULL;
}

// FUN_00170e90
void* func_00170e90(s16 id)
{
    if (id >= 3000)
    {
        return D_007CDFCC + (id - 4000) * 0x1c;
    }
    return NULL;
}

// FUN_00170ed0
void* func_00170ed0(s16 id, s32* category)
{
    return func_00170ed0_impl(id, category);
}

// FUN_00171060
s16 func_00171060(s16 id)
{
    id = (s16)id;
    if (id < 1000)
    {
        return id;
    }
    if (id < 2000)
    {
        return id - 1000;
    }
    if (id < 3000)
    {
        return id - 2000;
    }
    if (id < 4000)
    {
        return id - 3000;
    }
    if (id < 5000)
    {
        return id - 4000;
    }
    return id - 5000;
}

// FUN_00171110
const char* func_00171110(s16 id, s16 field)
{
    extern u8 D_005D6C80[];
    s32 idValue = id;
    if (idValue < 1000)
    {
        return *(const char**)((u8*)D_005DDDC0 + idValue * 0x14 + field * 4);
    }
    if (idValue < 2000)
    {
        return *(const char**)((u8*)D_005DABF0 + idValue * 0x14 + field * 4);
    }
    if (idValue < 3000)
    {
        return *(const char**)(D_005D6C80 + idValue * 0x14 + field * 4);
    }
    if (idValue < 4000)
    {
        return ((const char**)D_005DE8E0)[idValue];
    }
    if (idValue < 5000)
    {
        return ((const char**)D_005DE880)[idValue];
    }
    return ((const char**)D_005DE040)[idValue];
}

// FUN_00171250
u32 func_00171250(s16 id)
{
    if (id < 1000)
    {
        return 0;
    }
    if (id < 2000)
    {
        return 1;
    }
    if (id < 3000)
    {
        return 2;
    }
    if (id < 4000)
    {
        return 3;
    }
    return 4;
}

// FUN_001712d0
u16 func_001712d0(s16 id)
{
    s32 category;
    u8* resource = func_00170ed0(id, &category);

    if (category == 3)
    {
        goto category3;
    }
    if (category == 2)
    {
        goto category2;
    }
    if (category == 1)
    {
        goto category1;
    }
    switch (category)
    {
    default:
        goto invalid;
    case 0:
        goto category0;
    }

category0:
    return *(u16*)(resource + 0x22);
category1:
    return *(u16*)(resource + 0x18);
category2:
    return *(u16*)(resource + 0x18);
category3:
    return *(u16*)(resource + 0x16);
invalid:
    return 0;
}

// FUN_00171390
void func_00171390(u32 flag)
{
    s32 index;
    u16 eventFlag;
    u32 valid;

    eventFlag = flag;
    if (eventFlag < 5000)
    {
        valid = false;
    }
    else if (eventFlag >= 0x1408)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    if (!valid)
    {
        FUN_0019d3f0((u32)D_005E3098, 0x9fe);
    }

    index = eventFlag - 0x1188;
    if (index < 0 || index >= 0x1600)
    {
        FUN_0019d3f0((u32)D_005E3098, 0x78d);
    }
    if (index == 0x1376)
    {
        FUN_005225A8(&gSpecialStatusMessage);
    }
    gGlobalWork.flags[((u16)flag - 0x1188) / 32] |=
        1u << (((u16)flag - 0x1188) % 32);
}

// FUN_001714b0
s32 func_001714b0(s32 index)
{
    return (s32)(D_007CDFC4 + index * 0x10);
}

// FUN_001714d0
s32 func_001714d0(s32 index)
{
    return (s32)(D_007CDFC0 + index * 0x20);
}

// FUN_001714f0
s32 func_001714f0(s32 index)
{
    return (s32)(D_007CDFC8 + index * 8);
}

// FUN_00171510
f32 func_00171510(s16 row, s16 column)
{
    return *(f32*)(D_007CDFBC + row * 0x14 + column * 4);
}

// FUN_00171550
u8 func_00171550(s16 unused1, s16 unused2, u16 index)
{
    u32 random = FUN_00488F30() % 100;
    s32 i;
    u32 threshold = 0;
    u8* table;

    i = 0;
    table = D_007CDFB4;
    table += index * 0x20;
    for (; i < 16; i++)
    {
        threshold += table[i * 2];
        if (random <= threshold)
        {
            return (D_007CDFB4 + index * 0x20)[i * 2 + 1];
        }
    }
    return (D_007CDFB4 + index * 0x20)[0x1f];
}

// FUN_001715f0
u32 func_001715f0(s16 id)
{
    s32 category;
    u8* resource;
    s32 tableIndex = 0;

    id = (s16)id;
    if (id >= 4000)
    {
        return 0;
    }

    if (id < 1000)
    {
        category = 0;
    }
    else if (id < 2000)
    {
        category = 1;
    }
    else if (id < 3000)
    {
        category = 2;
    }
    else if (id < 4000)
    {
        category = 3;
    }
    else
    {
        category = 4;
    }

    switch (category)
    {
    case 0:
        resource = func_00170d60_impl(id);
        tableIndex = *(u16*)(resource + 0x14);
        break;
    case 1:
        resource = func_00170da0_impl(id);
        tableIndex = *(u16*)(resource + 0x0c);
        break;
    case 2:
        resource = func_00170df0_impl(id);
        tableIndex = *(u16*)(resource + 0x0c);
        break;
    case 3:
        return 0;
    }

    resource = D_007CDFB4 + tableIndex * 0x20;
    return resource[0] == 'd' ? resource[1] : 0xff;
}

// FUN_001717C0
u8 FUN_001717c0(s32 socialLink)
{
    s32 valid;
    s32 secondValid;
    s32 available;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAD0);
    if (func_003951d0(socialLink + 0x900) == 1)
    {
        goto socialAvailable;
    }
    secondValid = true;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    K_ASSERT(secondValid, 0xAC3);
    available = func_003951d0(socialLink + 0x920) == 1;
    if (available != true)
    {
        goto socialUnavailable;
    }
socialAvailable:
    return true;
socialUnavailable:
    return false;
}

#pragma alias datIncrementSocialLinkCounter FUN_001718b0
// FUN_001718B0
void datIncrementSocialLinkCounter(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;
    u16* counter;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAE0);
    counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
    if (*counter < 0x20)
    {
        (*counter)++;
    }
    else
    {
        *counter = 0x20;
    }
}

#pragma alias datDecreaseSocialLinkPoints FUN_00171960
// FUN_00171960
void datDecreaseSocialLinkPoints(s32 socialLink, s32 points)
{
    struct SocialPointOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
        u8 padding[0xD2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    struct SocialPointOwner* pointOwner;
    s16 selectedSocialLink = 0;
    s16* point;
    s8* levels;
    s32 valid;
    s32 secondValid;
    s8 socialLevel;

    pointOwner = (struct SocialPointOwner*)&gGlobalWork;
    pointOwner = (struct SocialPointOwner*)((socialLink << 1) + (u32)pointOwner);
    point = pointOwner->pointValues;
    if (*point >= 1000)
    {
        return;
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB00);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0x595);
    levels = ((struct SocialPointOwner*)&gGlobalWork)->levels;
    socialLevel = levels[(s16)socialLink];
    if (socialLevel > 0 && socialLevel != 10)
    {
        *point = *point - points;
        if (FUN_00172c50(&selectedSocialLink) != NULL && selectedSocialLink == socialLink)
        {
            *point = 1;
        }
        if (*point < 0)
        {
            *point = 0;
        }
    }
}

#pragma alias datGetSocialLinkPoints FUN_00171ac0
// FUN_00171AC0
s16 datGetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB20);
    return ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink];
}

#pragma alias datResetSocialLinkPoints FUN_00171b50
// FUN_00171B50
void datResetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = &gGlobalWork;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xAF0);
    ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
}

// FUN_00171C40
void FUN_00171c40(s32 socialLink, s32 enabled)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    u16* counter;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB3C);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x900) == 0)
        {
            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAE0);
            counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
            if (*counter < 0x20)
            {
                (*counter)++;
            }
            else
            {
                *counter = 0x20;
            }

            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAF0);
            ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = 0;
            func_00395170(socialLink + 0x900);
        }
        func_00395170(0x987);
    }
    else
    {
        func_003951a0(socialLink + 0x900);
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        K_ASSERT(valid, 0xB2C);
        defaults = func_003bddd0();
        defaultPoints = defaults[socialLink];
        globalWork = &gGlobalWork;
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            secondValid = false;
        }
        else
        {
            secondValid = true;
        }
        K_ASSERT(secondValid, 0xAF0);
        ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
    }
}

#pragma alias datSetSocialLinkCounter FUN_00171e90
// FUN_00171E90
void datSetSocialLinkCounter(s32 socialLink, u16 value)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB58);
    if (value > 0x20)
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = 0x20;
    }
    else
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = value;
    }
}

// FUN_00171F50
void FUN_00171f50(s32 socialLink, s32 enabled)
{
    s32 valid;
    s32 secondValid;
    s32 thirdValid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB9B);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x920) == 0)
        {
            struct SocialDateOwner
            {
                u8 unused[0x12E];
                s16 dates[SOCIAL_LINK_COUNT];
            };
            struct SocialDateOwner* globalWork;

            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                secondValid = false;
            }
            else
            {
                secondValid = true;
            }
            K_ASSERT(secondValid, 0xB76);
            FUN_001718b0(socialLink);
            globalWork = (struct SocialDateOwner*)&gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                thirdValid = false;
            }
            else
            {
                thirdValid = true;
            }
            K_ASSERT(thirdValid, 0xB8B);
            globalWork->dates[socialLink] = D_0083679C[0];
            func_00395170(socialLink + 0x920);
        }
    }
    else
    {
        func_003951a0(socialLink + 0x920);
    }
}

// FUN_001720C0
u16 FUN_001720c0(s32 socialLink, s32* outDate)
{
    struct SocialDateStateOwner
    {
        u8 unused[0x12E];
        s16 dates[SOCIAL_LINK_COUNT];
        u8 padding[0x3C];
        u16 status[SOCIAL_LINK_COUNT];
    };
    struct SocialDateStateOwner* globalWork = (struct SocialDateStateOwner*)&gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBB0);
    *outDate = globalWork->dates[socialLink];
    return globalWork->status[socialLink];
}

// FUN_00172160
u8 FUN_00172160(s32 socialLink)
{
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBDC);
    if (func_003951d0(socialLink + 0x940) == 1)
    {
        return true;
    }
    return false;
}

// FUN_00172200
void FUN_00172200(s32 socialLink, s32 enabled)
{
    struct SocialPointStorage
    {
        u8 unused[0xF2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    s32 valid;
    s32 secondValid;
    s32 thirdValid;
    s16* defaults;
    s16 defaultPoints;
    struct SocialPointStorage* globalWork;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBEB);
    if (enabled == 1)
    {
        func_00395170(socialLink + 0x940);
        func_00395170(0x988);
        return;
    }
    func_003951a0(socialLink + 0x940);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xB3C);
    func_003951a0(socialLink + 0x900);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        thirdValid = false;
    }
    else
    {
        thirdValid = true;
    }
    K_ASSERT(thirdValid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = (struct SocialPointStorage*)&gGlobalWork;
    K_ASSERT(func_0016dce0((s16)socialLink) != 0, 0xAF0);
    globalWork->pointValues[socialLink] = defaultPoints;
}

#pragma alias datSetSocialLinkRankUnlocked FUN_001723a0
// FUN_001723A0
void datSetSocialLinkRankUnlocked(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x400);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC00);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC03);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datSetSocialLinkRankAcknowledged FUN_001724a0
// FUN_001724A0
void datSetSocialLinkRankAcknowledged(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x410);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC17);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC19);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datApplyPendingSocialLinkRank FUN_001725a0
// FUN_001725A0
void datApplyPendingSocialLinkRank(s32 socialLink)
{
    struct SocialLevelOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
    };
    s16 shortSocialLink = socialLink;
    s8* levels = ((struct SocialLevelOwner*)&gGlobalWork)->levels;
    s32 socialLevel = levels[shortSocialLink];
    s32 valid;

    if (shortSocialLink < 0 || shortSocialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC2E);
    if (FUN_00172660(socialLink) == 1)
    {
        func_0016e410((s16)socialLink, socialLevel + 1);
    }
}

#pragma alias datSocialLinkHasPendingRank FUN_00172660
// FUN_00172660
s32 datSocialLinkHasPendingRank(s32 socialLink)
{
    s32 valid;
    s32 rank;
    s32 firstResourceBase;
    s32 secondResourceBase;
    s32 rankOffset;
    s32 secondResource;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC3F);
    rank = 1;
    secondResourceBase = (socialLink << 5) + 0x410;
    firstResourceBase = (socialLink << 5) + 0x400;
    while (rank <= 10)
    {
        rankOffset = rank - 1;
        secondResource = rankOffset + secondResourceBase;
        if (func_003951d0(rankOffset + firstResourceBase) == 1)
        {
            if (func_003951d0(secondResource) == 0)
            {
                return true;
            }
        }
        rank++;
    }
    return false;
}

#pragma alias datSocialEventRecordHasData FUN_00172750
// FUN_00172750
u8 datSocialEventRecordHasData(const u8* data)
{
    if (data[0] == 0xFF && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    if (data[0] == 0 && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    return true;
}

// FUN_001727E0
void FUN_001727e0(void)
{
    ((u32*)D_0083A34C)[0] &= ~0x80;
    ((u32*)D_0083A34C)[0] &= ~0x100;
    ((u32*)D_0083A34C)[0] &= ~0x200;
    ((u32*)D_0083A34C)[0] &= ~0x400;
    ((u32*)D_0083A34C)[0] &= ~0x800;
}

// FUN_00172820
void FUN_00172820(s16 pcId)
{
    (*(u32*)D_0083A34C) |= 0x400;
    datSetPhysicalCondition(1, pcId);
}

/* Removing this loses FUN_00172860 (MATCH nd0 -> MISMATCH nd10) - measured W161. */

#pragma optimization_level 0
// FUN_00172860
u8 FUN_00172860(void)
{
    if ((*(u32*)D_0083A34C & 0x400) != 0)
    {
        return 1;
    }
    return 0;
}
#pragma optimization_level 2




















// FUN_00172890
void FUN_00172890()
{
    btlLoadResource(0x980);
    memset(D_00836458, 0, 0x38);
}

// FUN_001728D0
void FUN_001728d0(const u32* values)
{
    struct SocialDataOwner
    {
        u8 unused[0x1E4];
        s32 data[14];
    };
    struct SocialDataOwner* globalWork = (struct SocialDataOwner*)&gGlobalWork;
    const u32* source;
    u32* destination;
    u32 firstValue;
    u32 secondValue;
    s32 remaining;

    func_003951a0(0x980);
    memset(D_00836458, 0, 0x38);
    func_00395170(0x980);
    destination = (u32*)globalWork->data;
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    FUN_00172a20(0);
    if (globalWork->data[1] <= 4)
    {
        return;
    }
    K_Assert(__FILE__, 0xC9C);
}

#pragma alias datGetSocialEventData FUN_00172990
// FUN_00172990
u32* datGetSocialEventData(void)
{
    return (u32*)D_00836458;
}

#pragma alias datSocialEventDataIsLoaded FUN_001729a0
// FUN_001729A0
u8 datSocialEventDataIsLoaded(void)
{
    return func_003951d0(0x980) == 1;
}

#pragma alias datTryGetSocialEventValue FUN_001729d0
// FUN_001729D0
u8 datTryGetSocialEventValue(u32* outValue)
{
    struct SocialEventData
    {
        u8 unused[0x24];
        u8 value;
    };
    struct SocialEventData* data = (struct SocialEventData*)D_00836458;

    if (data->value != 0xFF)
    {
        *outValue = data->value;
        return true;
    }
    return false;
}

// FUN_00172A10
u8 FUN_00172a10(void)
{
    return D_00836458[8];
}

#pragma alias datSetSocialEventMode FUN_00172a20
// FUN_00172A20
void datSetSocialEventMode(u32 value)
{
    *(u32*)(D_00836458 + 0x10) = value;
}

#pragma alias datSocialEventModeIsActive FUN_00172a30
// FUN_00172A30
u8 datSocialEventModeIsActive(void)
{
    return *(u32*)(D_00836458 + 0x10) == 1;
}

#pragma alias datSocialLinkUsesRelationshipTable FUN_00172a50
// FUN_00172A50
u8 datSocialLinkUsesRelationshipTable(s16 value)
{
    s16 i;
    s32 checkedValue;

    i = 0;
    checkedValue = value;
    while (i < 6)
    {
        if (checkedValue == i + 6)
        {
            return true;
        }
        i++;
    }
    return false;
}

// FUN_00172AB0
void FUN_00172ab0(s16 personaId)
{
    D_00836458[0x38] = 1;
    *(s16*)(D_00836458 + 0x3A) = personaId;
    *(s16*)(D_00836458 + 0x3C) = gGlobalWork.calendarWork.daysSinceApr5;
}

// FUN_00172AE0
void FUN_00172ae0(void)
{
    func_003951a0(0x983);
    memset(D_008364BC, 0, 0x38);
}

// FUN_00172B20
void FUN_00172b20(void)
{
    s16 value;
    if (FUN_00172c50(&value) != 0)
    {
        func_0017ad90();
        func_003951a0(0x983);
        memset(D_008364BC, 0, 0x38);
    }
}

// FUN_00172B80
void FUN_00172b80(s8 first, s8 second, const u32* values)
{
    u32* destination = (u32*)D_008364BC;
    const u32* source;
    s32 remaining;
    u32 packed;
    u32 firstValue;
    u32 secondValue;

    memset(D_008364BC, 0, 0x38);
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    func_00395170(0x983);
    memset(&packed, 0, sizeof(packed));
    ((u8*)&packed)[0] = first;
    ((u8*)&packed)[1] = second;
    ((u8*)&packed)[2] = ((const u8*)values)[0];
    ((u8*)&packed)[3] = ((const u8*)values)[0x1E];
    func_0017ac60(packed);
}

// FUN_00172C50
u8* FUN_00172c50(s16* outValue)
{
    u8* data = D_008364BC;

    if (func_003951d0(0x983) == 1)
    {
        *outValue = data[0];
        return data;
    }
    return NULL;
}

#pragma alias datRecordSocialLinkDate FUN_00172cc0
// FUN_00172CC0
void datRecordSocialLinkDate(s32 socialLink)
{
    s32 valid;
    u32 month;
    u32 day;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xD3F);
    month = clndGetCurrentMonth();
    day = clndGetCurrentDay();
    D_00836734[(s16)socialLink] = (u8)month;
    D_00836752[(s16)socialLink] = (u8)day;
}

#pragma alias datGetSocialLinksForToday FUN_00172d70
// FUN_00172D70
s32 datGetSocialLinksForToday(s32* outSocialLinks)
{
    s32 count = 0;
    u32 month = clndGetCurrentMonth();
    u32 day = clndGetCurrentDay();
    s32 socialLink = 0;
    s8* data = (s8*)DAT_00836200_ptr;

    for (; socialLink < SOCIAL_LINK_COUNT; socialLink++)
    {
        s8* record = data + socialLink;
        if (record[0x534] != month)
        {
            continue;
        }
        if (record[0x552] != day)
        {
            continue;
        }
        outSocialLinks[count] = socialLink;
        count++;
    }
    return count;
}
















// FUN_00172e10
void FUN_00172e10()
{
    memset(D_00836498, 0, 0x24);
}

// FUN_00172E40
u8* FUN_00172e40(void)
{
    extern u8 D_00836498[];
    return D_00836498;
}

// FUN_00172E50
void FUN_00172e50(s32 slot, u8 owner, s32 amount)
{
    s32 remaining = (s32)gGlobalWork.heroMoney - amount;

    K_ASSERT(remaining >= 0, 0xD87);
    if (slot >= 0x40 && slot < 0)
    {
        K_Assert(__FILE__, 0xD8A);
    }
    if (D_008364F4[slot] != 1)
    {
        D_008364F4[slot] = 1;
        D_008365F4[slot] = 0;
        D_008366F4[slot] = owner;
        if (remaining > 9999999)
        {
            remaining = 9999999;
        }
        K_ASSERT((u32)remaining <= 9999999u, 0x68A);
        gGlobalWork.heroMoney = remaining;
    }
}

// FUN_00172F70
u8 FUN_00172f70(s32* outSlot)
{
    s32* records = D_008364F4;
    s32 currentDay = D_0083679C[0];
    s32 slot;

    for (slot = 0; slot < 0x40; slot++)
    {
        s32* recordState = &records[slot];
        if (recordState[0] == 1 && recordState[0x40] == 0)
        {
            const u8* record = func_003beb10(slot);
            if (currentDay >= clndGetDaysSinceStartFromDate(record[2], record[3]))
            {
                *outSlot = slot;
                return true;
            }
        }
    }
    return false;
}

// FUN_00173040
void FUN_00173040(s32 slot)
{
    const u8* record;
    s16 itemId;
    s32* state;
    s32 itemIndex;
    s32 amount;
    s32 itemSlot;
    s32 found;
    s32 itemCount;
    u16 count;
    s32 normalizedCount;
    u8 itemData[0x20];

    record = func_003beb10(slot);
    K_ASSERT(D_008364F4[slot] != 0, 0xDBC);
    state = &D_008365F4[slot];
    K_ASSERT(*state != 1, 0xDBF);
    *state = 1;
    itemCount = D_008366F4[slot];
    for (itemIndex = 0; itemIndex < itemCount + 2; itemIndex++)
    {
        itemId = *(s16*)(record + itemIndex * 2 + 4);
        {
            const u8* itemRecord = record + itemIndex;
            count = itemRecord[0xC];
        }
        if (itemId >= 4000)
        {
            func_00170860(-1, itemId, count);
        }
        else
        {
            func_001828d0(itemId, itemData);
            amount = 0;
            normalizedCount = count & 0xFFFF;
            while (amount < normalizedCount)
            {
                found = 0;
                itemSlot = 0;
                {
                    const u8* itemSlots = D_00833E80;
                    while (itemSlot < 0x14)
                    {
                        if (*(u16*)(itemSlots + itemSlot * 0x14) == 0)
                        {
                            func_001831e0(-1, (s16)itemSlot, itemData);
                            found = 1;
                            break;
                        }
                        itemSlot++;
                    }
                }
                K_ASSERT(found != 0, 0xDE2);
                amount++;
            }
        }
    }
}





// FUN_00175be0
void datInitPersona(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroPersona.equippedPersona = -1;
        memset(gGlobalWork.heroPersona.personas, 0, sizeof(gGlobalWork.heroPersona.personas));

        return;
    }

    pc = &gPcs[2];

    memset(&pc[pcId - 2].persona, 0, sizeof(DatPersonaWork));
}

// FUN_00175c70
void datCompendiumInit()
{
    memset(gGlobalWork.compendium, 0, sizeof(gGlobalWork.compendium));
}

// FUN_0016db70
void datInitSocialLink()
{
    memset(&gGlobalWork.heroStatus.activeSocialLink, 0, 0x508);
}

/* Removing this loses FUN_00177280 (MATCH nd0 -> MISMATCH nd26) and 2 more - measured W161. */
#pragma opt_loop_invariants on
// FUN_00177280
s16 datGetAcademicLevel(s16 academicPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (academicLevelThreshold[idx] <= academicPoint)
        {
            return idx + 1;
        }
    }
}

// FUN_001772f0
s16 datGetCharmLevel(s16 charmPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (charmLevelThreshold[idx] <= charmPoint)
        {
            return idx + 1;
        }
    }
}

// FUN_00177360
s16 datGetCourageLevel(s16 couragePoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (courageLevelThreshold[idx] <= couragePoint)
        {
            return idx + 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_001773D0
void func_001773d0(void)
{
    DAT_00830000_a[0x3bb0] = 0;
    DAT_00830000_b[0x3bd0] = 0;
    DAT_00830000_c[0x3bf0] = 0;
    func_00177410(&D_007CBFA0, &D_007CBFA0);
}
/* Removing this loses FUN_00177410 (MATCH nd0 -> MISMATCH nd89) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00177410
void func_00177410(u8* param_1,u8* param_2)
{
    extern void FUN_00521408(void*, s32, u32);
    s32 index;
    s8 value;

    FUN_00521408(&gGlobalWork, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_1 + index);
        if (value == '\0')
        {
            break;
        }
        ((u8*)&gGlobalWork)[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_2 + index);
        if (value == '\0')
        {
            break;
        }
        ((u8*)&gGlobalWork)[index + 0x12] = value;
    }

    func_001774e0();
}
#pragma opt_loop_invariants off
// FUN_001774E0


void func_001774e0(void)



{

  FUN_00521408(DAT_00833bb0, 0, 0x12);

  FUN_00521408(DAT_00833bd0, 0, 0x12);

  FUN_00521408(DAT_00833bf0, 0, 0x24);

  FUN_00521250(DAT_00833bb0, &gGlobalWork, 0x12);

  FUN_00521250(DAT_00833bd0, DAT_00836212, 0x12);

  FUN_00523ac8(DAT_00833bf0, &DAT_00836200, DAT_00833bd0, DAT_00833bb0);

  return;

}
// FUN_001775A0


u8* func_001775a0(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            result = DAT_00833bf0;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E35EC[0];
        }
        else if (param_1 == 9)
        {
            result = D_005E35E0[0];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_00177670


u8* func_00177670(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            return DAT_00833bb0;
        }
        else if (param_1 < 0xb)
        {
            result = D_005E3790[param_1];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E379C[0];
        }
        else if (param_1 < 0xb)
        {
            if (param_1 == 9)
            {
                result = D_005E3790[0];
            }
            else
            {
                result = D_005E3790[param_1];
            }
            return result;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_00177790


u8* func_00177790(s16 param_1)
{
    u8* result;
    s32 mode;

    mode = FUN_0017d800();
    if (mode == 0)
    {
        if (param_1 == 1)
        {
            return DAT_00833bd0;
        }
        else if (param_1 < 0xb)
        {
            result = D_005E37D0[param_1];
        }
        else
        {
            result = D_005E35E0[param_1];
        }
        return result;
    }
    else
    {
        if (param_1 == 1)
        {
            result = D_005E37DC[0];
        }
        else if (param_1 < 0xb)
        {
            if (param_1 == 9)
            {
                result = D_005E37D0[0];
            }
            else
            {
                result = D_005E37D0[param_1];
            }
            return result;
        }
        else
        {
            result = D_005E35E0[param_1];
        }
    }
    return result;
}
// FUN_001778B0


u8* func_001778b0(s16 param_1)
{
    u8* result;

    switch (param_1)
    {
    case 1:
        result = func_00177790(param_1);
        break;
    case 2:
        result = func_00177790(param_1);
        break;
    case 3:
        result = func_00177670(param_1);
        break;
    case 4:
        result = func_00177790(param_1);
        break;
    case 5:
        result = func_00177790(param_1);
        break;
    case 6:
        result = func_00177790(param_1);
        break;
    case 7:
        result = func_00177790(param_1);
        break;
    case 8:
        result = func_00177790(param_1);
        break;
    case 9:
        result = func_00177790(param_1);
        break;
    case 10:
        result = func_00177670(param_1);
        break;
    default:
        result = func_00177670(param_1);
        break;
    }
    return result;
}


/* Removing this worsens FUN_001779a0 (nd14 -> nd121) - measured W161. */
// FUN_001779A0 NONMATCHING
#pragma opt_loop_invariants on
void func_001779a0(void)
{
    s32 valueSlot;
    s32 slot;
    s32 pcIndex;

    for (pcIndex = 0; pcIndex < 10; pcIndex++)
    {
        for (slot = 0; slot < 4; slot++)
        {
            *(u16*)(D_00834010 + pcIndex * sizeof(DatPc) + slot * 0x14 + 0x130) = 0;
        }
        for (valueSlot = 0; valueSlot < 4; valueSlot++)
        {
            *(u32*)(D_00834010 + pcIndex * sizeof(DatPc) + valueSlot * 4 + 0x110) = 0;
        }
    }
}
#pragma opt_loop_invariants off
// FUN_00177A40
u8 func_00177a40(u32 param_1,int param_2)



{

  return *(u16 *)(D_00833A78 + (param_1 & 0xffff) * sizeof(DatPc) + param_2 * 0x14) != 0;

}
// FUN_00177A90


void* func_00177a90(u16 pcId, s32 index)
{
    s32 adjustedPcId;

    adjustedPcId = pcId - 2;
    if (adjustedPcId < 0 || adjustedPcId >= 10)
    {
        FUN_0019d3f0((u32)D_005E3098, 0xf22);
    }
    if (index < 0 || index >= 4)
    {
        FUN_0019d3f0((u32)D_005E3098, 0xf23);
    }

    return D_00834010 + adjustedPcId * sizeof(DatPc) + index * 0x14 + 0x130;
}
// FUN_00177B50
void func_00177b50(int param_1, int param_2)
{
    u8* base = DAT_00830000_a + 0x3a78;
    *(u16*)(base + param_1 * 0x364 + param_2 * 0x14) = 0;
}
// FUN_00177B90
void func_00177b90(u32 param_1, int param_2, int param_3)
{
    u8* iVar1;

    iVar1 = (u8*)D_00834010 + ((param_1 & 0xffff) - 2) * 0x364;
    FUN_00521250(iVar1 + param_2 * 0x14 + 0x130,
                 iVar1 + param_3 * 0x14 + 0x5c, 0x14);
}
// FUN_00177C10
void func_00177c10(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    *puVar1 |= 1;
}
// FUN_00177C50
void func_00177c50(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    *puVar1 &= ~1;
}
// FUN_00177CA0
u32 func_00177ca0(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    return *puVar1 & 1;
}
// FUN_00177ce0
void dat00177ce0(s32 param_1, u32 param_2)
{
    gPcs[param_1].unk_360 = param_2;
}

// FUN_00177d10
u32 dat00177d10(s32 param_1)
{
    return gPcs[param_1].unk_360;
}

// FUN_0017b160
void datResetTotalBtl()
{
    gGlobalWork.totalBtl = 0;
}

// FUN_0017b170
u32 datGetTotalBtl()
{
    return gGlobalWork.totalBtl;
}

void FUN_00300af0();

// FUN_0017b4e0
void dat0017b4e0(void)
{
    FUN_00300af0();
}

// FUN_0017bf70
u32 dat0017bf70(u16 param_1)
{
    if (param_1 < 0x1bf)
    {
        return 0;
    }

    return param_1 < 0x1d0;
}

void FUN_00403130();

// FUN_0017c6c0
void dat0017c6c0(void)
{
    FUN_00403130();
}

void FUN_00403220();

// FUN_0017c6e0
void dat0017c6e0(void)
{
    FUN_00403220();
}

// FUN_0017c8c0
DatPersonaWork* datGetPersonaByCompendium(s32 idx)
{
    K_ASSERT(idx >= 0 && idx < 256, 6177);

    if (gGlobalWork.compendium[idx].flags & PERSONA_FLAG_VALID)
    {
        return &gGlobalWork.compendium[idx];
    }

    return NULL;
}

void FUN_0017d700(s32 param_1, s32 param_2, void *param_3);

// FUN_0017d6d0
void dat0017d6d0(s32 param_1, void *param_2)
{
    FUN_0017d700(param_1, 1, param_2);
}

void FUN_003d74b0();

// FUN_0017d790
void dat0017d790(void)
{
    FUN_003d74b0();
}

// FUN_0017d7f0
void datSetScenarioMode(u32 scenario)
{
    sScenarioMode = scenario;
}

// FUN_0017d800
u32 datGetScenarioMode()
{
    return sScenarioMode;
}
