#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
int func_0016dbc0(short, int*);
char func_0016df30(short);
void func_00171110(short, short);
char datGetSocialLinkLevel(short);
void datPersonaAddToNaturalStatHeroPersona(u16, u16, char);
void datSetActiveSocialLink(short);
void datPersonaAddToBonusStatByPcId();
int datGetActiveSocialLinkPtr();

int scrGetIntPara();
int FUN_0016dce0(short);
int datSocialLinkLevelIsNotZero(short);
void scrSetIntReturnVal();
void FUN_0016e2b0(short, int);
int FUN_001717c0();
int FUN_00172160();
void FUN_0016e410(short, char);
int FUN_003bded0();
int FUN_0035f140();
int FUN_00172f70();
u32 FUN_00173220(u16);
void FUN_003a4220();
void FUN_00171c40();
void FUN_00172200();
short FUN_00175360();
int FUN_003be8e0();
u32 FUN_003c3f40();
int FUN_00173780(u16, u16);
extern u8 DAT_00958400[];
extern u8 DAT_0095841e[];

s32 scrGetCmdTimer();
s32 scrGetMesHandleIdx();
void FUN_0016dfb0(short);
int FUN_00172990();
int adminiGetNowSeqId();
int adminiGetNextSeqId();
void adminiChangeSeq();
int FUN_003c33c0();
void FUN_001728d0();
int FUN_003bffa0();
short datGetAcademicPoint(short);
short datGetCharmPoint(short);
short datGetCouragePoint(short);
short datGetAcademicLevel(short);
short datGetCharmLevel(short);
short datGetCourageLevel(short);
void datSetAcademicPoint(short, short);
void datSetCharmPoint(short, short);
void datSetCouragePoint(short, short);
const char* h_camp_getAcademicLevelString(short);
const char* h_camp_getCharmLevelString(short);
const char* h_camp_getCourageLevelString(short);
void FUN_003a4270();
void FUN_003a4010();
u32 clndGetCurrentMonth();
u32 clndGetCurrentDay();
int FUN_003beab0();
int FUN_003beb10();
u32 ComuData_FUN_003c4210();
u32 FUN_003c43f0();
void FUN_00176fb0(u16, u16*, int*);
u32 FUN_0030bb40();
u32 FUN_0030bbb0(u8);
u32 FUN_003c3f80();
void FUN_00173040();
int FUN_003beca0();
int FUN_003bee80();
u32 FUN_003a2090();
u32 FUN_003c2350();
u32 FUN_0039b8b0();
u32 kwlnTaskExists();
void FUN_00395350();
void FUN_003952d0();
int FUN_003951d0();
u32 FUN_0038d6f0(short);
int FUN_0036f500();
u16 FUN_001752b0();
void FUN_00172e50();
void printf();
void memset();
extern s16 DAT_007cca60;
extern s16 DAT_007cca62;
extern s16 DAT_007cca64;
extern s16 DAT_007cca66;
extern u8* DAT_007ce420;

static int sDat007ce5ac;   // DAT_007ce5ac
static int sDat007ce5b0;   // DAT_007ce5b0
static u32 sDat007ce5b4;   // DAT_007ce5b4
static int sDat007ce5b8;   // DAT_007ce5b8
static u32 sDat007ce5bc;   // uGpffffb8cc
static u32 sDat007ce5c0;   // uGpffffb8d0
static u32 sDat007ce5c4;   // uGpffffb8d4
static int sDat007ce5c8;   // iGpffffb8d8
static int sDat007ce5cc;   // iGpffffb8dc
static int sDat007ce5d0;   // iGpffffb8e0
static u32 sDat007ce5d4; // DAT_007ce5d4
static int sDat007ce5a8; // DAT_007ce5a8

// FUN_00360280
u32 scrComu00360280(void)
{
    char uVar1;
    int uVar2;
    int lVar3;

    uVar2 = scrGetIntPara(0);
    lVar3 = FUN_0016dce0(uVar2);
    K_ASSERT(lVar3 != 0, 0x293);
    uVar1 = datGetSocialLinkLevel(uVar2);
    scrSetIntReturnVal(uVar1);
    return 1;
}

// FUN_003604a0
u32 scrComu003604a0(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2d2);
    lVar2 = scrGetIntPara(1);
    K_ASSERT(lVar2 >= 0, 0x2d6);
    lVar3 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_0016e2b0(uVar1, lVar2);
    return 1;
}

// FUN_00360300
u32 scrComu00360300(void)
{
    int uVar1;
    int lVar2;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2a1);
    lVar2 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar2 == 0) {
        scrSetIntReturnVal(0);
        return 1;
    }
    lVar2 = FUN_001717c0(uVar1);
    if (lVar2 == 1) {
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// FUN_003603d0
u32 scrComu003603d0(void)
{
    int uVar1;
    int lVar2;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2b9);
    lVar2 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar2 == 0) {
        scrSetIntReturnVal(0);
        return 1;
    }
    lVar2 = FUN_00172160(uVar1);
    if (lVar2 == 1) {
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// FUN_00360570
u32 scrComu00360570(void)
{
    char cVar1;
    int uVar2;
    int lVar3;

    uVar2 = scrGetIntPara(0);
    lVar3 = FUN_0016dce0(uVar2);
    K_ASSERT(lVar3 != 0, 0x2ea);
    lVar3 = datSocialLinkLevelIsNotZero(uVar2);
    if (lVar3 == 0) {
        return 1;
    }
    cVar1 = datGetSocialLinkLevel(uVar2);
    if (cVar1 > 0 && cVar1 < 10) {
        FUN_0016e410(uVar2, cVar1 + 1);
    }
    return 1;
}

// FUN_003608e0
u32 scrComu003608e0(void)
{
    int uVar1;
    int lVar2;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x367);
    lVar2 = datSocialLinkLevelIsNotZero(uVar1);
    K_ASSERT(lVar2 != 0, 0x36a);
    scrSetIntReturnVal(FUN_003bded0(uVar1));
    return 1;
}

// FUN_00360090
u32 scrComu00360090(void)
{
    int lVar1;
    int uStack_4;

    lVar1 = FUN_0035f140();
    K_ASSERT(lVar1 >= 0, 0x23d);
    lVar1 = FUN_00172f70(&uStack_4);
    if (lVar1 == 1) {
        sDat007ce5d4 = uStack_4;
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// FUN_00360b70
u32 scrComu00360b70(void)
{
    int uVar1;
    int lVar2;
    int lVar3;
    int uStack_4;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x3d9);
    lVar2 = FUN_0035f140();
    lVar3 = func_0016dbc0(uVar1, &uStack_4);
    if (lVar3 == 1) {
        if (lVar2 >= 0) {
            FUN_003a4220(lVar2, 0, FUN_00173220((u16)uStack_4));
        }
        scrSetIntReturnVal(uStack_4);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// FUN_00360640
u32 scrComu00360640(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = scrGetIntPara(0);
    lVar2 = scrGetIntPara(1);
    lVar3 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar3 != 0, 0x306);
    lVar3 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_00171c40(uVar1, lVar2 != 0);
    return 1;
}

// FUN_003606f0
u32 scrComu003606f0(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = scrGetIntPara(0);
    lVar2 = scrGetIntPara(1);
    lVar3 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar3 != 0, 0x321);
    lVar3 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_00172200(uVar1, lVar2 != 0);
    return 1;
}

// FUN_0035fbd0
u32 scrComu0035fbd0(void)
{
    int uVar1;
    short uVar2;
    int uVar3;

    uVar3 = scrGetIntPara(0);
    K_ASSERT(uVar3 < 5, 0x186);
    uVar1 = scrGetIntPara(1);
    uVar2 = FUN_00175360();
    datPersonaAddToNaturalStatHeroPersona(uVar2, uVar3 & 0xffff, uVar1);
    return 1;
}

// FUN_0035f680
u32 scrComu0035f680(void)
{
    int uVar1;
    int lVar2;

    uVar1 = scrGetIntPara(0);
    lVar2 = FUN_003be8e0(uVar1, DAT_00958400);
    K_ASSERT(lVar2 != 0, 0xd7);
    datSetActiveSocialLink(uVar1);
    lVar2 = FUN_0035f140();
    if (lVar2 >= 0) {
        FUN_003a4220(lVar2, 0, FUN_003c3f40(DAT_0095841e[0]));
    }
    return 1;
}

// FUN_0035fc70
u32 scrComu0035fc70(void)
{
    int uVar1;
    int uVar2;
    int uVar3;

    uVar1 = scrGetIntPara(0);
    uVar2 = scrGetIntPara(1);
    K_ASSERT(uVar2 < 5, 0x19a);
    uVar3 = scrGetIntPara(2);
    datPersonaAddToBonusStatByPcId(uVar1 & 0xffff, uVar2 & 0xffff, uVar3);
    return 1;
}

// FUN_0035fd00
u32 scrComu0035fd00(void)
{
    short uVar2;
    int uVar3;

    uVar3 = scrGetIntPara(0);
    K_ASSERT(uVar3 < 5, 0x1af);
    uVar2 = FUN_00175360();
    scrSetIntReturnVal(FUN_00173780(uVar2, uVar3 & 0xffff) & 0xff);
    return 1;
}

// FUN_0035f170
u32 scrComu0035f170(void)
{
    int uVar1;

    uVar1 = scrGetIntPara(0);
    FUN_0016dfb0(uVar1);
    return 1;
}

// FUN_0035f1b0
u32 scrComu0035f1b0(void)
{
    int uVar1;
    int lVar2;

    uVar1 = scrGetIntPara(0);
    lVar2 = datSocialLinkLevelIsNotZero(uVar1);
    if (lVar2 == 1) {
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// 12 bytes. Wrapped so the table init compiles as mwcc's inline block copy
typedef struct
{
    s16 ids[6];
} ScrComuLinkIds;

static const s16 sReverseLinkIds[6] = { 6, 7, 8, 9, 10, 11 }; // DAT_0069d518

#pragma optimization_level 1
// FUN_0035f210
u32 scrComu0035f210(void)
{
    s16 links[6];
    int i;
    int bestIdx;
    int best;
    int linkId;
    int lVar4;

    *(ScrComuLinkIds*)links = *(ScrComuLinkIds*)sReverseLinkIds;
    bestIdx = -1;
    best = bestIdx;
    for (i = 0; i < 6; i++) {
        linkId = links[i];
        lVar4 = datSocialLinkLevelIsNotZero(linkId);
        if (lVar4 != 0 && FUN_001717c0(linkId) != 1 && FUN_00172160(linkId) != 1 &&
            best < datGetSocialLinkLevel(linkId)) {
            bestIdx = i;
            best = datGetSocialLinkLevel(linkId);
        }
    }
    if (bestIdx == -1) {
        scrSetIntReturnVal(0);
    } else {
        scrSetIntReturnVal(bestIdx + 1);
    }
    return 1;
}
#pragma optimization_level 2

#pragma optimization_level 1
// FUN_0035f360
u32 scrComu0035f360(void)
{
    s16 links[4];
    int i;
    int bestIdx;
    int best;
    int linkId;
    int lVar3;
    s16 link0;
    s16 link1;
    s16 link2;
    s16 link3;

    link0 = DAT_007cca60;
    link1 = DAT_007cca62;
    link2 = DAT_007cca64;
    link3 = DAT_007cca66;
    links[0] = link0;
    links[1] = link1;
    links[2] = link2;
    links[3] = link3;
    bestIdx = -1;
    best = bestIdx;
    for (i = 0; i < 4; i++) {
        linkId = links[i];
        lVar3 = datSocialLinkLevelIsNotZero(linkId);
        if (lVar3 != 0 && FUN_001717c0(linkId) != 1 && FUN_00172160(linkId) != 1 &&
            best < datGetSocialLinkLevel(linkId)) {
            bestIdx = i;
            best = datGetSocialLinkLevel(linkId);
        }
    }
    if (bestIdx == -1) {
        scrSetIntReturnVal(0);
    } else {
        scrSetIntReturnVal(bestIdx + 1);
    }
    return 1;
}
#pragma optimization_level 2

// 28 bytes. Payload for adminiChangeSeq(ADMINI_SEQ_COMU_EVENT?)
typedef struct
{
    u8 unkData[12]; // 0x00
    u32 unk_0c;     // 0x0c
    u32 unk_10;     // 0x10
    u32 unk_14;     // 0x14
} ScrComuEventReq;

// FUN_0035f4a0
u32 scrComu0035f4a0(int* startedFlag)
{
    int data;
    int result;
    int force;
    int idx;
    ScrComuEventReq req;

    idx = 0;
    force = 0;
    data = FUN_00172990();
    if (*startedFlag == 1 && adminiGetNowSeqId() == 0 && adminiGetNextSeqId() == -1) {
        force = 1;
        *startedFlag = 0;
    }
    result = FUN_003c33c0(data, &idx, force);
    if (result == 1) {
        if (idx != 0) {
            data += (idx - 1) * 6;
            req.unk_0c = *(u16*)(data + 0x20);
            req.unk_10 = *(u8*)(data + 0x22);
            req.unk_14 = *(u8*)(data + 0x23);
            *startedFlag = 1;
            adminiChangeSeq(3, &req, 0x1c, 0);
        }
    } else {
        return 0;
    }
    return 1;
}

// FUN_0035f5b0
u32 scrComu0035f5b0(void)
{
    int uVar2;
    int lVar3;
    u8 buf[64];

    uVar2 = scrGetIntPara(0);
    lVar3 = datSocialLinkLevelIsNotZero(uVar2);
    if (lVar3 == 0) {
        return 1;
    }
    if (scrGetCmdTimer() == 0) {
        sDat007ce5ac = 0;
        lVar3 = FUN_003be8e0(uVar2, buf);
        K_ASSERT(lVar3 != 0, 0xbf);
        FUN_001728d0(buf);
    } else {
        if (scrComu0035f4a0(&sDat007ce5ac) == 0) {
            return 1;
        }
    }
    return 0;
}

// FUN_0035f730
u32 scrComu0035f730(void)
{
    if (scrGetCmdTimer() == 0) {
        sDat007ce5b0 = 0;
        FUN_001728d0(DAT_00958400);
    } else {
        if (scrComu0035f4a0(&sDat007ce5b0) == 0) {
            return 1;
        }
    }
    return 0;
}

// FUN_0035f7a0
u32 scrComu0035f7a0(void)
{
    int result;
    ScrComuEventReq req;
    u32 c;
    u32 b;
    u32 a;

    c = 0;
    b = 0;
    a = 0;
    if (scrGetCmdTimer() == 0) {
        result = FUN_003bffa0(&c, &b, &a);
        if (result == 0) {
            return 1;
        } else {
            datSetActiveSocialLink(0xff);
            req.unk_0c = c;
            req.unk_10 = b;
            req.unk_14 = a;
            adminiChangeSeq(3, &req, 0x1c, 0);
        }
    } else {
        if (adminiGetNowSeqId() == 0 && adminiGetNextSeqId() == -1) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

// FUN_0035f880
u32 scrComu0035f880(void)
{
    int oldLevel;
    int newLevel;
    const char* oldStr;
    const char* newStr;
    int statType;
    int points;
    int handle;

    oldLevel = 0;
    newLevel = 0;
    oldStr = NULL;
    newStr = NULL;
    handle = scrGetMesHandleIdx();
    if (handle < 0) {
        return 1;
    }
    statType = scrGetIntPara(0);
    K_ASSERT(statType < 3, 0x139);
    points = scrGetIntPara(1);
    switch (statType) {
    case 2:
        oldLevel = datGetCourageLevel(datGetCouragePoint(1));
        points += datGetCouragePoint(1);
        if (points > 999) {
            points = 999;
        }
        newLevel = datGetCourageLevel(points);
        datSetCouragePoint(1, points);
        break;
    case 0:
        oldLevel = datGetAcademicLevel(datGetAcademicPoint(1));
        points += datGetAcademicPoint(1);
        if (points > 999) {
            points = 999;
        }
        newLevel = datGetAcademicLevel(points);
        datSetAcademicPoint(1, points);
        break;
    case 1:
        oldLevel = datGetCharmLevel(datGetCharmPoint(1));
        points += datGetCharmPoint(1);
        if (points > 999) {
            points = 999;
        }
        newLevel = datGetCharmLevel(points);
        datSetCharmPoint(1, points);
        break;
    }
    if (oldLevel != newLevel) {
        switch (statType) {
        case 2:
            goto Charm;
        case 0:
            goto Academic;
        case 1:
            goto Courage;
        }
        goto Render;

    Charm:
        oldStr = h_camp_getCharmLevelString(oldLevel);
        newStr = h_camp_getCharmLevelString(newLevel);
        goto Render;

    Academic:
        oldStr = h_camp_getAcademicLevelString(oldLevel);
        newStr = h_camp_getAcademicLevelString(newLevel);
        goto Render;

    Courage:
        oldStr = h_camp_getCourageLevelString(oldLevel);
        newStr = h_camp_getCourageLevelString(newLevel);

    Render:
        FUN_003a4220(handle, 0, oldStr);
        FUN_003a4220(handle, 1, newStr);
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

// FUN_0035fd80
u32 scrComu0035fd80(void)
{
    u16 uVar1;

    uVar1 = FUN_001752b0();
    scrSetIntReturnVal(uVar1);
    return 1;
}

// FUN_0035fdb0
u32 scrComu0035fdb0(void)
{
    int uVar1;
    int data;
    int lVar3;
    int i;
    int handle;
    int id;

    handle = scrGetMesHandleIdx();
    K_ASSERT(handle >= 0, 0x1d3);
    lVar3 = FUN_003beab0(clndGetCurrentMonth(), clndGetCurrentDay(), &id);
    if (lVar3 == 1) {
        data = FUN_003beb10(id);
        sDat007ce5b4 = id;
        sDat007ce5b8 = data;
        for (i = 0; i < 4; i++) {
            uVar1 = *(u16*)(data + i * 2 + 4);
            func_00171110((s16)uVar1, 2);
            FUN_003a4270(handle, i, uVar1);
            FUN_003a4270(handle, i + 0xd, 2);
        }
        FUN_003a4220(handle, 4, ComuData_FUN_003c4210(*(u16*)(data + 0x1c)));
        for (i = 0; i < 3; i++) {
            FUN_003a4010(handle, i + 5, *(u32*)(data + i * 4 + 0x10), 0);
        }
        for (i = 0; i < 3; i++) {
            FUN_003a4010(handle, i + 9, *(u8*)(data + i + 0xc), 0);
        }
        scrSetIntReturnVal(1);
    } else {
        scrSetIntReturnVal(0);
    }
    return 1;
}

#pragma optimization_level 1
// FUN_0035ff80
u32 scrComu0035ff80(void)
{
    int lVar1;
    int data;
    int idx;

    K_ASSERT(sDat007ce5b8 != 0, 0x210);
    lVar1 = scrGetIntPara(0);
    K_ASSERT(lVar1 >= 0 && lVar1 < 3, 0x215);
    data = sDat007ce5b8;
    idx = lVar1 * 4;
    scrSetIntReturnVal(*(u32*)(idx + data + 0x10));
    return 1;
}

// FUN_00360020
u32 scrComu00360020(void)
{
    int uVar1;
    int data;
    int idx;

    K_ASSERT(sDat007ce5b8 != 0, 0x223);
    uVar1 = scrGetIntPara(0);
    data = sDat007ce5b8;
    idx = uVar1 * 4;
    FUN_00172e50(sDat007ce5b4, uVar1, *(u32*)(idx + data + 0x10));
    return 1;
}
#pragma optimization_level 2

// FUN_00360110 NONMATCHING
u32 scrComu00360110(void)
{
    int i;
    int bVar1;
    int handle;
    int uVar2;
    int uVar3;
    int d4;
    int slPtr;
    int data;
    int idx;

    slPtr = datGetActiveSocialLinkPtr();
    d4 = sDat007ce5d4;
    data = FUN_003beb10(d4);
    handle = scrGetMesHandleIdx();
    K_ASSERT(handle >= 0, 0x25e);
    bVar1 = *(u8*)(d4 + slPtr + 0x480);
    i = 0;
    goto tail;

loop:
    idx = i * 2;
    uVar3 = *(s16*)(data + idx + 4);
    uVar2 = *(u8*)(data + i + 0xc);
    func_00171110(uVar3, 2);
    FUN_003a4270(handle, idx, (short)uVar3);
    FUN_003a4010(handle, idx + 1, uVar2, 0);
    FUN_003a4270(handle, i + 0xd, 2);
    i++;

tail:
    if (i < bVar1 + 2) {
        goto loop;
    }
    scrSetIntReturnVal();
    return 1;
}

// FUN_00360250
u32 scrComu00360250(void)
{
    datGetActiveSocialLinkPtr();
    FUN_00173040(sDat007ce5d4);
    return 1;
}

#pragma optimization_level 1
// FUN_003607a0
u32 scrComu003607a0(void)
{
    int uVar3;
    int handle;
    int level;
    char uVar2;
    int lVar4;

    uVar3 = scrGetIntPara(0);
    level = 0;
    lVar4 = FUN_0016dce0(uVar3);
    K_ASSERT(lVar4 != 0, 0x33d);
    handle = scrGetMesHandleIdx();
    K_ASSERT(handle >= 0, 0x343);
    if (datSocialLinkLevelIsNotZero(uVar3) == 1) {
        level = datGetSocialLinkLevel(uVar3);
    }
    FUN_003a4220(handle, 0, FUN_003c3f80(uVar3));
    uVar2 = func_0016df30(uVar3);
    FUN_003a4220(handle, 1, FUN_0030bbb0(uVar2));
    FUN_003a4010(handle, 2, level, 0);
    return 1;
}
#pragma optimization_level 2

// FUN_00360990
u32 scrComu00360990(void)
{
    int uVar1;
    int uVar2;

    uVar1 = scrGetIntPara(0);
    uVar2 = scrGetIntPara(1);
    if (scrGetCmdTimer() == 0) {
        sDat007ce5bc = FUN_003a2090(0, uVar1, uVar2, 0x400);
    } else {
        if (kwlnTaskExists(sDat007ce5bc) == 0) {
            sDat007ce5bc = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00360a40
u32 scrComu00360a40(void)
{
    if (scrGetCmdTimer() == 0) {
        sDat007ce5c0 = FUN_003c2350(0, 0xc00);
    } else {
        if (kwlnTaskExists(sDat007ce5c0) == 0) {
            sDat007ce5c0 = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00360ab0
u32 scrComu00360ab0(void)
{
    int lVar1;
    u8 buf[128];

    lVar1 = FUN_003beca0(buf);
    if (lVar1 == 0) {
        scrSetIntReturnVal(0);
    } else {
        scrSetIntReturnVal(1);
    }
    return 1;
}

// FUN_00360b00
u32 scrComu00360b00(void)
{
    if (scrGetCmdTimer() == 0) {
        sDat007ce5c4 = FUN_0039b8b0(0, 0xc00);
    } else {
        if (kwlnTaskExists(sDat007ce5c4) == 0) {
            sDat007ce5c4 = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00360c50
u32 scrComu00360c50(void)
{
    int uVar1;
    int uVar2;
    int uVar3;

    uVar1 = scrGetIntPara(0);
    uVar2 = scrGetIntPara(1);
    uVar3 = scrGetIntPara(2);
    switch (uVar1) {
    case 0:
        FUN_003952d0(0, uVar3, uVar2 + 3);
        break;
    case 1:
        FUN_00395350(uVar2 + 3, 0);
        break;
    }
    return 1;
}

// FUN_00360cf0
u32 scrComu00360cf0(void)
{
    int uVar1;

    uVar1 = scrGetIntPara(0);
    sDat007ce5c8 = 0;
    sDat007ce5cc = FUN_003bee80(uVar1, &sDat007ce5d0);
    scrSetIntReturnVal(sDat007ce5d0);
    return 1;
}

// FUN_00360d40
u32 scrComu00360d40(void)
{
    int personaId;
    int blankSkillIdx;
    int handle;
    u16 skills[14];
    int skillCount;
    int learnedSkillIdx;

    personaId = *(u16*)(sDat007ce5cc + sDat007ce5c8 * 2);
    handle = scrGetMesHandleIdx();
    K_ASSERT(handle >= 0, 0x424);
    K_ASSERT(sDat007ce5d0 > sDat007ce5c8, 0x427);
    FUN_003a4010(handle, 0, DAT_007ce420[personaId * 0xe + 3], 0);
    FUN_003a4220(handle, 1, FUN_00173220(personaId));
    for (blankSkillIdx = 0; blankSkillIdx < 3; blankSkillIdx++) {
        FUN_003a4220(handle, blankSkillIdx + 2, FUN_003c43f0());
    }
    FUN_00176fb0(personaId, skills, &skillCount);
    for (learnedSkillIdx = 0; learnedSkillIdx < skillCount; learnedSkillIdx++) {
        FUN_003a4220(handle, learnedSkillIdx + 2, FUN_0030bb40(skills[learnedSkillIdx]));
    }
    sDat007ce5c8++;
    return 1;
}

#pragma push
#pragma opt_common_subs off
// FUN_00360ed0 NONMATCHING. Checks a comu event's availability condition ('objtype' 0..2)
u32 scrComu00360ed0(int param_1)
{
    char cVar1;
    int bVar2;
    u32 value;
    int lVar5;
    int flag;
    u32 result;

    flag = 0;
    lVar5 = FUN_0036f500(*(u32*)(param_1 + 0x38));
    if (lVar5 == 0) {
        result = 1;
    } else {
        cVar1 = *(char*)(param_1 + 0xc);
        if (cVar1 == 2) goto ObjCase2;
        if (cVar1 == 1) goto ObjCase1;
        if (cVar1 == 0) goto ObjCase0;
        goto ObjDefault;

ObjCase0:
        result = 1;
        goto ObjDone;

ObjCase1:
        value = FUN_0038d6f0(*(short*)(param_1 + 8));
        result = *(short*)(param_1 + 10) == value;
        goto ObjDone;

ObjCase2:
        bVar2 = *(u8*)(param_1 + 0xe);
        if (bVar2 >= 3) {
            result = 0;
            goto ObjDone;
        }
        switch (bVar2) {
        case 1:
            goto SelectFlag1;
        case 0:
            goto SelectFlag0;
        case 2:
            goto SelectFlag2;
        default:
            goto SelectFlagDefault;
        }
SelectFlagDefault:
        goto CheckFlagValue;
SelectFlag0:
        goto CheckFlagValue;
SelectFlag1:
        flag = 0x400;
        goto CheckFlagValue;
SelectFlag2:
        flag = 0x1000;
CheckFlagValue:
        if (*(short*)(param_1 + 10) == 0) {
            result = FUN_003951d0(*(short*)(param_1 + 8) + flag) == 0;
        } else {
            result = FUN_003951d0(*(short*)(param_1 + 8) + flag) == 1;
        }
        goto ObjDone;

ObjDefault:
        printf("ASSERT!! Comp flag Invalid Value!! objtype =%d\n", *(u32*)(param_1 + 0x38));
        memset(param_1 + 8, 0, 8);
        result = 1;
ObjDone:
    return result;
}
#pragma pop
