#include "Main/g_data.h"
#include "Main/Battle/Data/datCalc.h"
#include "Kosaka/k_assert.h"
#include "Script/scrTraceCode.h"
#include "temporary.h"

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

void FUN_00172890();
void FUN_00172e10();

// FUN_0016f3e0
void FUN_0016f3e0(u32 idx, u32 value)
{
    K_ASSERT((s32)idx < 128, 2007);

    gGlobalWork.unk_0083a4dc[idx] = value;
}

// FUN_0016f380
u32 FUN_0016f380(u32 idx)
{
    K_ASSERT((s32)idx < 128, 2001);

    return gGlobalWork.unk_0083a4dc[idx];
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

// FUN_0016d2f0 NONMATCHING
u32 datGetExpUntilNextLevel(s16 pcId)
{
    u32 nextExpTmp;
    u32 nextExp = gGlobalWork.heroStatus.nextExp;
    DatPersonaWork* persona;
    u8 i;

    if (!IS_HERO(pcId))
    {
        persona = datPersonaGetByPcId(pcId);
        K_ASSERT(persona != NULL, 622);

        nextExp = datPersonaGetNextExp(persona);
    }

    for (i = 0; i < ARRAY_SIZE(sPlayerExpThreshold); i++)
    {
        if (nextExp < sPlayerExpThreshold[i]) break;
    }

    if (i == MAX_CHARACTER_LEVEL)
    {
        nextExp = 0;
    }

    K_ASSERT(i != 0 && i < MAX_CHARACTER_LEVEL, 876);

    nextExp = sPlayerExpThreshold[i];
    nextExpTmp = gGlobalWork.heroStatus.nextExp;

    nextExp -= nextExpTmp;

    return nextExp;
}

// FUN_0016d560 NONMATCHING
u8 datDidCharacterLevelUp(s16 pcId, u32 expGain)
{
    u8 level;
    u8 i;
    u8 count;

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.nextExp += expGain;
        count = 0;

        for (i = 0; i < ARRAY_SIZE(sPlayerExpThreshold); i++)
        {
            if (gGlobalWork.heroStatus.nextExp < sPlayerExpThreshold[i]) break;
            
            count++;
        }

        if (i == MAX_CHARACTER_LEVEL)
            count = MAX_CHARACTER_LEVEL;
    }
    else 
    {
        K_ASSERT(false, 901);
    }

    level = datGetLevel(pcId);

    return count != level;
}

// FUN_0016dad0 NONMATCHING
void datSetAiTactic(s16 pcId, u8 aiTacticId)
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
s8 datGetAiTactic(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroUnit.aiTactic;
    }

    return gPcs[pcId].unit.aiTactic;
}

// FUN_0016d6b0 NONMATCHING
void datSetPhysicalCondition(s16 pcId, u16 physicalCondition)
{
    u16 currentPhysicalCondition = gGlobalWork.heroStatus.physicalState.physicalCondition;
    u16 oldFatigueCounter;

    if (!IS_HERO(pcId))
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

    if (currentPhysicalCondition == PHYSICAL_CONDITION_TIRED && 
        physicalCondition != PHYSICAL_CONDITION_TIRED)
    {
        oldFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;

        if (!IS_HERO(pcId))
        {
            oldFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
        }

        datSetFatigueCounter(pcId, oldFatigueCounter);
    }

    currentPhysicalCondition = physicalCondition;

    if (!IS_HERO(pcId))
    {
        gPcs[pcId].physicalState.physicalCondition = physicalCondition;
        currentPhysicalCondition = gGlobalWork.heroStatus.physicalState.physicalCondition;
    }

    gGlobalWork.heroStatus.physicalState.physicalCondition = currentPhysicalCondition;
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
void datSetHp(s16 pcId, u16 hp)
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
void datSetSp(s16 pcId, u16 sp)
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

// FUN_0016eb80 NONMATCHING
u32 datScrCmd_SAVE_PARTY()
{
    s16 i;
    DatGlobal* globalWork;
    s16* savedIds;

    i = 0;
    globalWork = &gGlobalWork; // TODO: should be a1 instead of a2
    savedIds = sSavedPartyIds; // TODO: should be v1 instead of a1
    for (; i < 4; i++)
    {
        savedIds[i] = globalWork->partyIds[i];
    }

    return true;
}

// FUN_0016ebe0 NONMATCHING
u32 datScrCmd_RESTORE_PARTY()
{
    s16 i;
    s16* savedIds;
    DatGlobal* globalWork;

    i = 0;
    savedIds = sSavedPartyIds; // TODO: should be a1 instead of a2
    globalWork = &gGlobalWork; // TODO: should be v1 instead of a1
    for (; i < 4; i++)
    {
        globalWork->partyIds[i] = savedIds[i];
    }

    return true;
}

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

// FUN_0016cfe0 NONMATCHING
void datSetAcademicPoint(s16 pcId, u16 academicPoint)
{
    K_ASSERT(academicPoint > SOCIAL_STAT_MIN_POINT && academicPoint < SOCIAL_STAT_MAX_POINT, 797);

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.socialStats.academicPoint = academicPoint;
        return;
    }

    gPcs[pcId].socialStats.academicPoint = academicPoint;
}

// FUN_0016d090 NONMATCHING
void datSetCharmPoint(s16 pcId, u16 charmPoint)
{
    K_ASSERT(charmPoint > SOCIAL_STAT_MIN_POINT && charmPoint < SOCIAL_STAT_MAX_POINT, 808);

    if (IS_HERO(pcId))
    {
        datGetCharmLevel(gGlobalWork.heroStatus.socialStats.charmPoint); // ??
        gGlobalWork.heroStatus.socialStats.charmPoint = charmPoint;
        datGetCharmLevel(charmPoint); // ??
        return;
    }

    gPcs[pcId].socialStats.charmPoint = charmPoint;
}

// FUN_0016d160 NONMATCHING
void datSetCouragePoint(s16 pcId, u16 couragePoint)
{
    K_ASSERT(couragePoint > SOCIAL_STAT_MIN_POINT && couragePoint < SOCIAL_STAT_MAX_POINT, 828);

    if (IS_HERO(pcId))
    {
        datGetCourageLevel(gGlobalWork.heroStatus.socialStats.couragePoint); // ??
        gGlobalWork.heroStatus.socialStats.couragePoint = couragePoint;
        datGetCourageLevel(couragePoint); // ??
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

// FUN_0016ca90 NONMATCHING
void FUN_0016ca90(s16 pcId, u16 param_2)
{
    u16 oldFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
    u16 fatigueCounter = gGlobalWork.heroStatus.physicalState.fatigueCounter;
    s32 uVar3;

    if (!IS_HERO(pcId))
    {
        oldFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
        fatigueCounter = gPcs[pcId].physicalState.fatigueCounter;
    }

    uVar3 = fatigueCounter + param_2;

    if (uVar3 < 0)
    {
        uVar3 = 0;
    }
    else if (oldFatigueCounter < uVar3)
    {
        uVar3 = fatigueCounter;
    }

    datSetFatigueCounter(pcId, uVar3);
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

// FUN_0016e100 NONMATCHING
u8 datSocialLinkLevelIsNotZero(u16 socialLink)
{
    K_ASSERT(socialLink > SOCIAL_LINK_SEES && socialLink < SOCIAL_LINK_NYX_TEAM, 1429);

    return gGlobalWork.heroStatus.socialLinkStat[socialLink] > 0;
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
void datSetEquipmentIdx(s16 pcId, s16 equipmentType, u16 equipmentIdx)
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
        p = work->unk_0083a4dc + i;
        *p = 0;
    }
}

// FUN_0016f630
u16 datGetEquipmentId(s16 pcId, u16 equipmentIdx)
{
    // TODO
    
    if (pcId == -1) // ?
    {
        // return (&DAT_00833e80)[equipmentIdx * 10];
    }
    else if (IS_HERO(pcId))
    {
        return gGlobalWork.heroEquip.equipments[equipmentIdx].id;
    }
    else if (pcId <= 255)
    {
        return gPcs[pcId].equipments[equipmentIdx].id;
    }

    // return (&DAT_007fd6c8 + equipmentIdx * 0x14 + pcId * 0x364);
}

// FUN_0016f900 NONMATCHING
u8 datGetEquipmentEffect(s16 pcId, u16 equipmentIdx)
{
    if (pcId == -1)
    {
        // return (&DAT_00833e89)[pcId * 0x14];
    }
    else if (IS_HERO(pcId))
    {
        return gGlobalWork.heroEquip.equipments[equipmentIdx].effect;
    }
    else if (pcId <= 255)
    {
        return gPcs[pcId].equipments[equipmentIdx].effect;
    }

    // return (equpementIdx * 0x14 + pcId * 0x364 + 0x7fd6d1);
}

// FUN_00172890
void FUN_00172890()
{
    // TODO
}

// FUN_00172e10
void FUN_00172e10()
{
    // TODO
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

// FUN_00177280 NONMATCHING
s16 datGetAcademicLevel(s16 academicPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (academicPoint >= academicLevelThreshold[idx])
        {
            return idx + 1;
        }
    }
}

// FUN_001772f0 NONMATCHING
s16 datGetCharmLevel(s16 charmPoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (charmPoint >= charmLevelThreshold[idx])
        {
            return idx + 1;
        }
    }
}

// FUN_00177360 NONMATCHING
s16 datGetCourageLevel(s16 couragePoint)
{
    s16 idx;

    for (idx = 5; ; idx--)
    {
        if (couragePoint >= courageLevelThreshold[idx])
        {
            return idx + 1;
        }
    }
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