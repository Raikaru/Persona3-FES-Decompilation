#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#pragma alias FUN_003952d0_y2 FUN_003952d0_y2
#pragma alias FUN_0038d6f0_y2 FUN_0038d6f0_y2
#pragma alias FUN_0036f500_y2 FUN_0036f500_y2

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

/* Removing this loses scrComu0035f360 (MATCH nd0 -> MISMATCH nd16) - measured W161. */
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

/* Removing this loses scrComu0035ff80 (MATCH nd0 -> MISMATCH nd7); loses scrComu00360020 (MATCH nd0 -> MISMATCH nd7) - measured W161. */
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

// FUN_00360110
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
    scrSetIntReturnVal(bVar1 + 2);
    return 1;
}

// FUN_00360250
u32 scrComu00360250(void)
{
    datGetActiveSocialLinkPtr();
    FUN_00173040(sDat007ce5d4);
    return 1;
}

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
/* Removing this worsens scrComu00360ed0 (nd67 -> nd113) - measured W161. */
#pragma opt_common_subs off
// FUN_00360ed0 NONMATCHING. Checks a comu event's availability condition ('objtype' 0..2)
u32 scrComu00360ed0(int param_1)
{
    char cVar1;
    u8 bVar2;
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
        switch (cVar1) {
        case 0:
            result = 1;
            break;
        case 1:
            value = FUN_0038d6f0(*(short*)(param_1 + 8));
            result = *(short*)(param_1 + 10) == value;
            break;
        case 2:
            bVar2 = *(u8*)(param_1 + 0xe);
            if (bVar2 >= 3) {
                result = 0;
                break;
            }
            if (bVar2 == 2) {
                goto SelectFlag2;
            }
            if (bVar2 == 1) {
                goto SelectFlag1;
            }
            if (bVar2 == 0) {
                goto SelectFlag0;
            }
            goto SelectFlagDefault;
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
            break;
        default:
            printf("ASSERT!! Comp flag Invalid Value!! objtype =%d\n", *(u32*)(param_1 + 0x38));
            memset(param_1 + 8, 0, 8);
            result = 1;
            break;
        }
    }
    return result;
}
#pragma pop



typedef int code(...);
typedef struct {
  u64 xy;
  f32 z;
} EvtPosition65430;
typedef u8 bool;
#pragma alias FUN_00393e30_evt_main FUN_00393e30
extern void FUN_00393e30_evt_main(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,code *(*param_6)(int));

extern u8 D_0069DFF0[];
extern u8 D_0069E088[];
extern u8 DAT_006a0000[];
#pragma alias DAT_006a0000_65430_abs DAT_006a0000
extern u8 DAT_006a0000_65430_abs[];
extern u8 DAT_0069ffd0[];
extern u8 DAT_0069dd98[];
extern u8 DAT_0069de20[];
extern int FUN_003b5d10(...);
#pragma alias FUN_003b55b0_evt_main FUN_003b55b0
extern u8 *FUN_003b55b0_evt_main(int param_1);
#pragma alias FUN_003b5d10_evt_main FUN_003b5d10
extern u8 *FUN_003b5d10_evt_main(u16 param_1);
#pragma alias FUN_0039f710_evt_main FUN_0039f710
extern u32 FUN_0039f710_evt_main(int *param_1);
#pragma alias FUN_003bb390_evt FUN_003bb390
extern void FUN_003bb390_evt(float param_1,u32 param_2);
extern u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3);
#pragma alias FUN_004c31b0_evt_main FUN_004c31b0
extern void FUN_004c31b0_evt_main(void *matrix, void *axis, f32 angle, s32 mode);
#pragma alias FUN_004c35d0_evt_main FUN_004c35d0
extern void FUN_004c35d0_evt_main(void *matrix, void *vector, s32 mode);
#pragma alias FUN_004c6c60_evt_main FUN_004c6c60
extern void FUN_004c6c60_evt_main(void *out, void *in, void *matrix);
#pragma alias FUN_003bb010_evt_main FUN_003bb010
extern void FUN_003bb010_evt_main(u16 param_1,u8 param_2);
#pragma alias FUN_003bb1d0_evt_main FUN_003bb1d0
extern void FUN_003bb1d0_evt_main(u16 param_1,s32 param_2,u8 param_3,s8 param_4,s8 param_5);
extern u32 DAT_0069d590;
#pragma alias DAT_0069d590_abs DAT_0069d590
extern s8 DAT_0069d590_abs[];
#pragma alias DAT_0069d580_abs DAT_0069d580
extern s8 DAT_0069d580_abs[];
#pragma alias DAT_0069e068_abs DAT_0069e068
extern s8 DAT_0069e068_abs[];
#pragma alias DAT_0069e078_abs DAT_0069e078
extern s8 DAT_0069e078_abs[];
typedef struct {
  u8 pad_00[0x80];
  s32 count;
  int *head;
  int *tail;
} MtEvtNodeList;
#pragma alias mtEvtInsertPriorityNode FUN_00361b60
extern void mtEvtInsertPriorityNode(int *node, MtEvtNodeList *list);
#pragma alias mtEvtCreateMainTask FUN_0036f3b0
extern void mtEvtCreateMainTask(u64 taskArg,u32 mode);
extern u32 DAT_0069d5c8;
extern u32 DAT_0069d5d0;
extern u32 DAT_0069d5d8;
extern u32 DAT_0069d5e0;
extern u32 DAT_0069d5e8;
extern u32 DAT_0069d5f0;
#pragma alias DAT_0069d5c8_abs DAT_0069d5c8
extern u8 DAT_0069d5c8_abs[];
#pragma alias DAT_0069d5d0_abs DAT_0069d5d0
extern u8 DAT_0069d5d0_abs[];
#pragma alias DAT_0069d5d8_abs DAT_0069d5d8
extern u8 DAT_0069d5d8_abs[];
#pragma alias DAT_0069d5e0_abs DAT_0069d5e0
extern u8 DAT_0069d5e0_abs[];
#pragma alias DAT_0069d5e8_abs DAT_0069d5e8
extern u8 DAT_0069d5e8_abs[];
#pragma alias DAT_0069d5f0_abs DAT_0069d5f0
extern u8 DAT_0069d5f0_abs[];
extern u32 DAT_0069d5f8;
extern u32 DAT_0069d600;
extern u32 DAT_0069d608;
extern u32 DAT_0069d610;
extern u32 DAT_0069d618;
extern u32 DAT_0069d620;
extern u32 DAT_0069d628;
extern u32 DAT_0069d630;
#pragma alias DAT_0069d5f8_abs DAT_0069d5f8
#pragma alias DAT_0069d600_abs DAT_0069d600
#pragma alias DAT_0069d608_abs DAT_0069d608
#pragma alias DAT_0069d610_abs DAT_0069d610
#pragma alias DAT_0069d618_abs DAT_0069d618
#pragma alias DAT_0069d620_abs DAT_0069d620
#pragma alias DAT_0069d628_abs DAT_0069d628
#pragma alias DAT_0069d630_abs DAT_0069d630
extern u8 DAT_0069d5f8_abs[];
extern u8 DAT_0069d600_abs[];
extern u8 DAT_0069d608_abs[];
extern u8 DAT_0069d610_abs[];
extern u8 DAT_0069d618_abs[];
extern u8 DAT_0069d620_abs[];
extern u8 DAT_0069d628_abs[];
extern u8 DAT_0069d630_abs[];
extern f32 FUN_001a1190(void);
extern u64 DAT_0069d6e8;
extern f32 DAT_0069d6f0;
extern u8 DAT_0069d580[];
extern u8 DAT_0069d7a0[];
#pragma alias DAT_0069d6e8_abs DAT_0069d6e8
#pragma alias DAT_0069d6f0_abs DAT_0069d6f0
extern u64 DAT_0069d6e8_abs[];
extern f32 DAT_0069d6f0_abs[];
#pragma alias DAT_0069d700_abs DAT_0069d700
#pragma alias DAT_0069d720_abs DAT_0069d720
extern u8 DAT_0069d700_abs[];
extern u8 DAT_0069d720_abs[];
extern u8 DAT_0069d910;
extern u32 DAT_0069de40;
extern u32 DAT_0069e180;
extern u32 DAT_0069e1a0;
extern u32 DAT_0069e1a2;
#pragma alias DAT_0069e1a2_byte DAT_0069e1a2
extern char DAT_0069e1a2_byte[];
extern u32 DAT_0069e1aa;
extern u32 DAT_0069e420;
extern u32 DAT_0069e422;
extern u32 DAT_006a0270;
extern u32 DAT_006a0bf8;
extern u32 DAT_006a0c00;
extern u32 DAT_007cadc0;
extern u32 DAT_007cadd0;
extern u32 DAT_007cae18;
extern u32 DAT_007cafec;
extern u32 DAT_007cb0cc;
extern u32 DAT_007cb110;
extern u32 DAT_007cb120;
extern u32 DAT_007cb124;
extern u32 DAT_007cca68;
extern u32 DAT_007cca6c;
extern u32 DAT_007ccd20;
extern u32 DAT_007cce48;
extern u32 DAT_007cce4c;
extern u32 DAT_007cce78;
extern u32 DAT_007ccf94;
extern u32 DAT_007cd130;
extern u32 DAT_007cdeac;
extern u32 DAT_007ce5d8;
extern int DAT_007ce5e4;
extern u32 DAT_007ce5e8;
extern u32 DAT_007ce5ec;
extern u32 DAT_007ce5f0;
extern u32 DAT_007ce5f4;
extern u32 DAT_007ce5f8;
extern u32 DAT_007ce5fc;
extern u32 DAT_007ce600;
extern u32 DAT_007ce604;
extern u32 DAT_007ce608;
extern u32 DAT_007ce60c;
extern u32 DAT_007e094c;
extern u32 DAT_007e094e;
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
extern u32 DAT_007e0952;
#pragma alias DAT_007e094c_2390 DAT_007e094c
extern u8 DAT_007e094c_2390[];
#pragma alias DAT_007e0952_2390 DAT_007e0952
extern u8 DAT_007e0952_2390[];
extern u32 DAT_007e095e;
extern u32 DAT_007e095f;
extern u32 DAT_007e0960;
extern u32 DAT_007e0961;
#pragma alias DAT_007e094c_628f0_abs DAT_007e094c
#pragma alias DAT_007e0952_628f0_abs DAT_007e0952
#pragma alias DAT_007e095e_628f0_abs DAT_007e095e
#pragma alias DAT_007e095f_628f0_abs DAT_007e095f
#pragma alias DAT_007e0960_628f0_abs DAT_007e0960
#pragma alias DAT_007e0961_628f0_abs DAT_007e0961
extern u8 DAT_007e094c_628f0_abs[];
extern u8 DAT_007e0952_628f0_abs[];
extern u8 DAT_007e095e_628f0_abs[];
extern u8 DAT_007e095f_628f0_abs[];
extern u8 DAT_007e0960_628f0_abs[];
extern u8 DAT_007e0961_628f0_abs[];
extern u32 DAT_00958470;
extern u32 DAT_009584a4;
extern u32 DAT_009584d0;
extern u32 DAT_009584fc;
extern u32 DAT_0095852c;
extern u32 DAT_0095855c;
extern u32 DAT_00958580;
extern u32 DAT_009585a8;
extern u32 DAT_009585ac;
extern u32 DAT_009585b0;
extern u32 DAT_009585b8;
extern u32 DAT_009585bc;
extern u32 DAT_009585c0;
extern u32 DAT_009585d0;
extern u32 DAT_00958700;
#pragma alias DAT_00958700_abs DAT_00958700
extern u8 DAT_00958700_abs[];
extern u32 DAT_00958704;
extern u32 DAT_00958708;
extern u32 DAT_0095870c;
extern u32 DAT_00958710;
extern u32 DAT_00958714;
extern u32 DAT_00958718;
extern u32 DAT_0095871c;
extern u32 DAT_00958720;
extern u32 DAT_00958724;
extern u32 DAT_00958728;
extern u32 DAT_0095872c;
extern u32 DAT_00958730;
extern u32 DAT_00958734;
extern u32 DAT_00958738;
extern u32 DAT_0095873c;
extern u32 DAT_00958740;
extern u32 DAT_00958744;
extern u32 DAT_00958748;
extern u32 DAT_0095874c;
extern u32 DAT_00958750;
extern u32 DAT_00958754;
extern u32 DAT_00958830;
extern u32 DAT_00958834;
extern u32 DAT_00958838;
extern u32 DAT_00958840;
extern u32 DAT_00958844;
extern u32 DAT_00958848;
extern u32 DAT_00958850;
extern u32 DAT_00958890;
extern u32 DAT_00958894;
extern u32 DAT_00958898;
extern u32 DAT_009588a0;
extern u32 DAT_009588a4;
extern u32 DAT_009588a8;
extern u32 DAT_009588b0;
extern u32 DAT_009588b4;
extern u32 DAT_009588b8;
extern u32 DAT_009588bc;
extern u32 DAT_009588c0;
extern u32 DAT_009588c4;
extern u32 DAT_009588c8;
extern u32 DAT_009588cc;
extern u32 DAT_009588d0;
extern u32 DAT_009588d4;
extern u32 DAT_009588d8;
extern u32 DAT_009588dc;
extern u32 DAT_009588e0;
extern u32 DAT_009588e4;
extern u32 DAT_009588e8;
extern u32 DAT_009588ec;
extern u32 DAT_00958970;
extern u32 DAT_00958978;
extern u32 DAT_0095897a;
extern u32 DAT_0095897c;
extern u32 DAT_0095897e;
extern u32 DAT_00958980;
extern u32 DAT_009589c8;
extern u32 DAT_009589cc;
extern u32 DAT_009589d0;
extern u32 DAT_009589e0;
extern u32 DAT_009589e4;
extern u32 DAT_009589e8;
extern u32 DAT_00958a60;
extern u32 DAT_00958a90;
extern u32 DAT_00960088;
extern u32 DAT_00960090;
extern u32 DAT_009600a0;
extern u32 DAT_0096017c;
extern u32 DAT_00960184;
extern u8 *PTR_DAT_0069d930;
extern u8 *PTR_DAT_0069d960;
extern u8 *PTR_DAT_0069da10;
extern u8 *PTR_DAT_0069da50;
extern u8 *PTR_DAT_0069da60;
extern u8 *PTR_DAT_0069db10;
extern u8 *PTR_DAT_0069ed90;
extern u8 *PTR_DAT_0069ede0;
extern u8 *PTR_DAT_0069ee10;
extern u8 *PTR_DAT_0069ee20;
extern u8 *PTR_DAT_0069ee40;
extern u8 *PTR_DAT_0069ee44;
extern u8 *PTR_DAT_0069ee48;
extern u8 *PTR_DAT_0069ee50;
extern u8 *PTR_DAT_0069ee54;
extern u8 *PTR_DAT_0069ee58;
extern u8 *PTR_DAT_0069eeb0;
extern u8 *PTR_DAT_0069eed0;
extern u8 *PTR_DAT_0069f9a4;
extern u8 *PTR_DAT_0069f9a8;
extern u8 *PTR_DAT_0069f9d8;
extern u8 *PTR_DAT_0069f9e0;
extern u8 *PTR_DAT_0069fa80;
extern u8 *PTR_DAT_006a01c4;
extern u8 *PTR_DAT_007cca5c;
extern u8 *PTR_DAT_007cca88;
extern u8 *PTR_DAT_007ccc50;
extern u8 *PTR_DAT_007ccc58;
extern u8 *PTR_DAT_007ccd8c;
extern u8 *PTR_DAT_007ccda4;
extern u8 *PTR_DAT_007ccdbc;
extern u8 *PTR_DAT_007ccf54;
extern u8 *PTR_DAT_007ccf60;
extern u8 *PTR_DAT_007ccf64;
extern u8 *PTR_DAT_007ccf7c;
extern u8 *PTR_DAT_007ccfa8;
extern u8 *PTR_DAT_007cd230;
extern u8 *PTR_DAT_007cd234;
extern u8 *PTR_DAT_007cd238;
extern u8 *PTR_DAT_007cd23c;
extern u8 *PTR_DAT_007cd25c;
extern u8 *PTR_DAT_007cd2d4;
extern u8 *PTR_DAT_007cd3d0;
extern code PTR_LAB_007ba6f0[];
extern code PTR_LAB_007ba740[];
extern code PTR_LAB_007ba7f0[];
extern code PTR_LAB_007ba810[];
extern code PTR_LAB_007ba830[];
extern code PTR_LAB_007ba850[];
extern code PTR_LAB_007ba9f0[];
extern code PTR_LAB_007baa30[];
extern code PTR_LAB_007baa70[];
extern code PTR_LAB_007baaf0[];
extern code PTR_LAB_007bab30[];
extern u8 *PTR_s_ACTIVE_0069f9dc;
extern u8 *PTR_s_ACTIVE_007ccf14;
extern u8 *PTR_s_ALPHA_0069ee3c;
extern u8 *PTR_s_BEZIER_0069fa84;
extern u8 *PTR_s_CAPTURE_007ccf78;
extern u8 *PTR_s_COMSE_007cd3d4;
extern u8 *PTR_s_CREATE_0069da70;
extern u8 *PTR_s_CREATE_0069ee30;
extern u8 *PTR_s_DELETE_0069ee38;
extern u8 *PTR_s_DIRECT_0069e9c0;
extern u8 *PTR_s_DIRECT_0069f9a0;
extern u8 *PTR_s_DIRECT_0069fa88;
extern u8 *PTR_s_DIRECT_007ccda0;
extern u8 *PTR_s_DIRECT_007cd258;
extern u8 *PTR_s_DISABLE_0069e6c8;
extern u8 *PTR_s_DISPONOFF_007ccaa8;
extern u8 *PTR_s_FADEOUT_0069ee14;
extern u8 *PTR_s_FADEOUT_WAIT_007ccf9c;
extern u8 *PTR_s_FADE_IN_007cce88;
extern u8 *PTR_s_FALSE_007ccdb8;
extern u8 *PTR_s_GAKURYOKU_0069feb0;
extern u8 *PTR_s_HAMETU_006a01cc;
extern u8 *PTR_s_HIRU_SASO_0069d880;
extern u8 *PTR_s_KAIKIN_006a01c0;
extern u8 *PTR_s_KEYFREE_007ccfbc;
extern u8 *PTR_s_KUCHI_0069ee18;
extern u8 *PTR_s_LENGTH_007cd22c;
extern u8 *PTR_s_L_FLAG_NOTUSE_0069e990;
extern u8 *PTR_s_MEPACHI_0069ee1c;
extern u8 *PTR_s_MES_WAIT_007ccf98;
extern u8 *PTR_s_MOVE_D_0069ee34;
extern u8 *PTR_s_MOVE_D_007ccf10;
extern u8 *PTR_s_NORMAL_0069d940;
extern u8 *PTR_s_NORMAL_007ccc60;
extern u8 *PTR_s_NORMAL_007cd2d0;
extern u8 *PTR_s_NOSTOP_007ccfac;
extern u8 *PTR_s_NO_KEYFREE_007ccfb8;
extern u8 *PTR_s_OFFSET_0069e6a0;
extern u8 *PTR_s_RELEASE_0069ee28;
extern u8 *PTR_s_REPEAT_007ccd88;
extern u8 *PTR_s_REVERSE_006a01c8;
extern u8 *PTR_s_SAVE_PROJ_;
extern u8 *PTR_s_SOUTAI_007ccd78;
extern u8 *PTR_s_SPEED_007cd228;
extern u8 *PTR_s_START_0069e100;
extern u8 *PTR_s_START_0069ee24;
extern u8 *PTR_s_START_007ccf50;
extern u32 fGpffff80d0;
extern u32 fGpffff8294;
extern u32 fGpffff8438;
extern u8 gp0xffff9d98;
extern u8 gp0xffff9db8;
extern u8 gp0xffff9dd0;
extern u8 gp0xffff9dd8;
extern u8 gp0xffff9df8;
extern u8 gp0xffff9e48;
extern u8 gp0xffff9e58;
extern u8 gp0xffff9e60;
extern u8 gp0xffff9e98;
extern u8 gp0xffff9ea8;
extern u8 gp0xffff9ec0;
extern u8 gp0xffff9ed8;
extern u8 gp0xffff9ee0;
extern u8 gp0xffff9ef8;
extern u8 gp0xffff9f00;
extern u8 gp0xffff9f08;
extern u8 gp0xffff9f10;
extern u8 gp0xffff9f20;
extern u8 gp0xffff9f30;
extern u8 gp0xffff9f58;
extern u8 gp0xffffa050;
extern u8 gp0xffffa058;
extern u8 gp0xffffa060;
extern u8 gp0xffffa068;
extern u8 gp0xffffa070;
extern u8 gp0xffffa0b8;
extern u8 gp0xffffa130;
extern u8 gp0xffffa134;
extern u8 gp0xffffa138;
extern u8 gp0xffffa140;
extern u8 gp0xffffa148;
extern u8 gp0xffffa150;
extern u8 gp0xffffa350;
extern u8 gp0xffffa3b8;
extern u8 gp0xffffa460;
extern u8 gp0xffffa498;
extern u8 gp0xffffa4a0;
extern u8 gp0xffffa4a8;
extern u8 gp0xffffa4b0;
extern u8 gp0xffffa4c0;
extern u8 gp0xffffa4c8;
extern u8 gp0xffffa4d0;
extern u8 gp0xffffa4d8;
extern u8 gp0xffffa4e8;
extern u8 gp0xffffa4f0;
extern u8 gp0xffffa4f8;
extern u8 gp0xffffa500;
extern u8 gp0xffffa508;
extern u8 gp0xffffa510;
extern u8 gp0xffffa518;
extern u8 gp0xffffa630;
extern u8 gp0xffffa638;
extern u8 gp0xffffa640;
extern u8 gp0xffffa648;
extern u8 gp0xffffa688;
extern u8 gp0xffffa690;
extern u8 gp0xffffa698;
extern u8 gp0xffffa6a0;
extern u32 iGpffffb8f0;
extern u32 iGpffffb904;
extern u32 iGpffffb920;
extern u32 iGpffffb924;
extern char *s_1234567890A_0069f7c0;
extern char *s_ADX_SE_MODE_0069db88;
extern char *s_BATTLE_BLUR_USE__0069ddf0;
extern char *s_BISTA_MODE_0069dca8;
extern char *s_B_UP_CONTROL_SELECT_0069dc10;
extern char *s_CAMERA_CONTROL_TYPE_0069dbd0;
extern char *s_COND_ON_SELECT_0069dd60;
extern char *s_CONFIG_DRAW_STOP_0069dc60;
extern char *s_CONTROL_TYPE_0069db98;
extern char *s_CUSTOM_EVENT_SELECT_0069dd40;
extern char *s_DELETE_FRAME_OK__0069db30;
extern char *s_EFFECT_MODE_0069dc38;
extern char *s_END_STOP_MODE_0069dcd8;
extern char *s_FADE_MODE_0069dcc8;
extern char *s_FADE_TYPE_0069db78;
extern char *s_FIELDOBJ_EDIT_PARAM_0069dd80;
extern char *s_FIELD_EDIT_GO__0069ddc0;
#pragma alias s_FIELD_EDIT_GO_abs s_FIELD_EDIT_GO__0069ddc0
extern u8 s_FIELD_EDIT_GO_abs[];
 
extern char *s_FIELD_EFFECT_MODE_0069dbf0;
extern char *s_FRAME_SET_OK__0069dda8;
#pragma alias s_FRAME_SET_OK_abs s_FRAME_SET_OK__0069dda8
extern u8 s_FRAME_SET_OK_abs[];
 
extern char *s_HOKAN_MODE_0069db48;
extern char *s_KEYFREE_SELECT_0069dd20;
extern char *s_KOMA_MODE_0069dc28;
extern char *s_MESSAGE_STOP_0069dd08;
extern char *s_MESSAGE_TYPE_0069de08;
#pragma alias s_MESSAGE_TYPE_abs s_MESSAGE_TYPE_0069de08
extern u8 s_MESSAGE_TYPE_abs[];
 
extern char *s_ON_OFF_MODE_0069db58;
extern char *s_PADACT_TYPE_0069dc48;
extern char *s_PATH_APPLY_MODE_0069e6e0;
extern char *s_PRIORITY_0069dcb8;
extern char *s_SELECT_MODE_0069dc98;
extern char *s_STAGE_0069f1b0;
extern char *s_TIMEI_FADE_DOWN_UP_0069dc80;
extern char *s_TRANS_MODE_0069db68;
extern char *s_UNIT_CONTROL_TYPE_0069dbb0;
extern char *s_VOICE_FILE_LOAD__0069ddd0;
#pragma alias s_VOICE_FILE_LOAD_abs s_VOICE_FILE_LOAD__0069ddd0
extern u8 s_VOICE_FILE_LOAD_abs[];
 
extern char *s_WAIT_MODE_SELECT_0069dcf0;
#pragma alias s_BATTLE_BLUR_USE_abs s_BATTLE_BLUR_USE__0069ddf0
extern u8 s_BATTLE_BLUR_USE_abs[];
extern u32 uGpffff841c;
#pragma alias fGpffff841c_evt uGpffff841c
extern f32 fGpffff841c_evt;
extern s16 uGpffff9d78;
extern s16 uGpffff9d7c;
extern u32 uGpffffa4b8;
extern u32 uGpffffa4bc;
extern u32 uGpffffa628;
extern u32 uGpffffa62c;
extern u32 uGpffffa650;
extern u32 uGpffffa654;
extern u32 uGpffffb8ec;
extern u32 uGpffffb900;
extern u32 uGpffffb924;

bool FUN_0036d320(int param_1);
bool FUN_0036f480(void);
bool FUN_00372c40(u64 param_1);
code * FUN_0036d500(void);
code * FUN_0036d5f0(void);
code * FUN_0036e140(int param_1);
code * FUN_0036e690(int param_1);
code * FUN_0036ed30(int param_1);
code * FUN_0036edd0(void);
code * FUN_0036ee30(void);
float FUN_0038a220(int param_1);
float FUN_0038a900(int param_1);
u8 FUN_003b86c0(f32 param_1, u32 param_2, u32 param_3);
u32 FUN_003b8730(f32 param_1, u16 param_2, void *param_3);
u32 FUN_003b89f0(f32 param_1, u16 param_2, char *param_3, u32 param_4);
int FUN_00361830(int param_1);
int FUN_00361ee0(int param_1,int param_2);
int FUN_00361f20(int param_1);
int FUN_00361f60(int param_1,int param_2);
int FUN_00361fe0(int param_1,int param_2);
int FUN_0036be60(u64 param_1,int param_2,int param_3);
int FUN_0036fda0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00371dd0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00372790(u64 param_1,u64 param_2,u64 param_3);
int FUN_00375000(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037caf0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037d5d0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037e1b0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037ead0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037f3d0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037fae0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00380200(u64 param_1,u64 param_2,u64 param_3);
int FUN_003806f0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00380d70(u64 param_1,u64 param_2,u64 param_3);
int FUN_00381280(u64 param_1,u64 param_2,u64 param_3);
int FUN_003819b0(u64 param_1,u64 param_2,u64 param_3);
int FUN_003820e0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382500(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382840(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382d60(u64 param_1,u64 param_2,u64 param_3);
int FUN_00383360(u64 param_1,u64 param_2,u64 param_3);
int FUN_00383d80(u64 param_1,u64 param_2,u64 param_3);
int FUN_00384370(u64 param_1,u64 param_2,u64 param_3);
int FUN_00384780(u64 param_1,u64 param_2,u64 param_3);
int FUN_00385520(u64 param_1,u64 param_2,u64 param_3);
int FUN_003863c0(void);
int FUN_00388df0(int param_1,int param_2);
int FUN_00361ca0(int param_1,int param_2);
u32 FUN_00361350(int *param_1,int param_2,int param_3);
u32 FUN_00361dd0(int param_1,u32 param_2,u16 param_3,u32 param_4);
long FUN_00374af0(u64 param_1,u64 param_2,u64 param_3);
#pragma alias FUN_00386ae0_evt FUN_00386ae0
extern u32 FUN_00386ae0_evt(u32 param_1,u32 param_2);
long FUN_00386ae0(u64 param_1,u64 param_2);
#pragma alias FUN_0038c540_evt FUN_0038c540
extern void FUN_0038c540_evt(int param_1,int param_2,int param_3,u32 param_4,u32 *param_5,u32 *param_6);
#pragma alias FUN_003b5d10_evt FUN_003b5d10
#pragma alias FUN_003b8310_evt FUN_003b8310
extern u32 FUN_003b8310_evt(u16 param_1,int param_2);
extern u32 FUN_003b5d10_evt(u32 param_1);
#pragma alias FUN_00360ed0_evt FUN_00360ed0
extern u32 FUN_00360ed0_evt(u32 param_1);
#pragma alias FUN_003b9550_evt FUN_003b9550
extern void FUN_003b9550_evt(u32 param_1,u32 param_2);
#pragma alias FUN_00388df0_evt FUN_00388df0
extern u32 FUN_00388df0_evt(u32 param_1,u32 *param_2);
#pragma alias FUN_003b8ff0_evt FUN_003b8ff0
extern u32 FUN_003b8ff0_evt(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_003b9260_evt FUN_003b9260
extern u32 FUN_003b9260_evt(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_003b8ff0_evt_wide FUN_003b8ff0
extern u32 FUN_003b8ff0_evt_wide(float param_1,u32 param_2,u32 param_3,s32 param_4,s32 param_5,u32 param_6,s32 param_7);
#pragma alias FUN_003b9260_evt_wide FUN_003b9260
extern u32 FUN_003b9260_evt_wide(float param_1,u32 param_2,u32 param_3,s32 param_4,s32 param_5,u32 param_6,s32 param_7);
#pragma alias FUN_003b8e10_evt FUN_003b8e10
extern u64 FUN_003b8e10_evt(u16 param_1,u8 param_2,short param_3,u32 param_4);
u64 FUN_003952d0_y2(u64 param_1,int param_2,s16 param_3);
u64 FUN_003952b0(u64 param_1,int param_2);
u64 FUN_003952a0(u64 param_1,int param_2);
u32 FUN_00397870(int param_1,long param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6);
void FUN_00396f50(int param_1);
u32 FUN_00396c70(int param_1,int param_2,int param_3,long param_4,long param_5,long param_6,long param_7,float param_8);
long FUN_0038ab00(int param_1,u64 param_2);
short FUN_0036f640(int param_1);
#pragma alias FUN_0036f640_evt FUN_0036f640
extern int FUN_0036f640_evt(int param_1);
u16 * FUN_00362290(int param_1);
u16 * FUN_00362310(int param_1);
u16 * FUN_00364470(u32 param_1,int param_2);
u16 * FUN_003645c0(u32 param_1,int param_2);
u16 * FUN_003646d0(u32 param_1,int param_2);
u16 * FUN_00364b10(u32 param_1,int param_2);
u16 * FUN_003655f0(u32 param_1,int param_2,int param_3);
u16 * FUN_00366540(u32 param_1,int param_2,int param_3,int param_4);
#pragma alias FUN_00366540_evt_u32 FUN_00366540
extern u32 FUN_00366540_evt_u32(u32 param_1,int param_2,int param_3,int param_4);
u32 FUN_00368d70(u64 param_1,u64 param_2,int param_3);
u32 FUN_0036d470(int param_1);
u32 FUN_0036da10(int param_1);
u32 FUN_0036db20(int param_1);
u32 FUN_0036e260(int param_1);
u32 FUN_0036e2f0(int param_1);
u32 FUN_0036f4c0(void);
u32 FUN_00370230(int param_1,int param_2,int param_3);
u32 FUN_00371710(int param_1,int param_2,int param_3);
u32 FUN_00372260(int param_1,int param_2,int param_3);
u32 FUN_00373700(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00374c90(int param_1,int param_2,int param_3);
u32 FUN_00375350(int param_1,int param_2,int param_3);
u32 FUN_00375590(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_003756e0(int param_1,int param_2,int param_3);
u32 FUN_00375900(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00375a40(int param_1,int param_2,int param_3);
u32 FUN_00375d70(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00375f30(int param_1,int param_2,int param_3);
u32 FUN_003798f0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037a150(int param_1,int param_2,int param_3);
u32 FUN_0037a2b0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037a4d0(int param_1,int param_2,int param_3);
u32 FUN_0037acc0(int param_1,int param_2,int param_3);
u32 FUN_0037afc0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037b2e0(int param_1,int param_2,int param_3);
u32 FUN_0037b5d0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037ba80(int param_1,int param_2,int param_3);
u32 FUN_0037be50(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037c2e0(int param_1,int param_2,int param_3);
u32 FUN_0037d4d0(int param_1,int param_2,int param_3);
u32 FUN_0037df50(int param_1,int param_2,int param_3);
u32 FUN_0037e3f0(int param_1,int param_2,int param_3);
u32 FUN_0037f050(int param_1,int param_2,int param_3);
u32 FUN_0037f5e0(int param_1,int param_2,int param_3);
u32 FUN_0037ff10(int param_1,int param_2,int param_3);
u32 FUN_00380310(int param_1,int param_2,int param_3);
u32 FUN_003809c0(int param_1,int param_2,int param_3);
u32 FUN_003810a0(int param_1,int param_2,int param_3);
u32 FUN_003814d0(int param_1,int param_2,int param_3);
u32 FUN_00381bf0(int param_1,int param_2,int param_3);
u32 FUN_00382320(int param_1,int param_2,int param_3);
u32 FUN_003826f0(int param_1,int param_2,int param_3);
u32 FUN_00382c10(int param_1,int param_2,int param_3);
u32 FUN_00382ec0(int param_1,int param_2,int param_3);
u32 FUN_00383810(int param_1,int param_2,int param_3);
u32 FUN_00384060(int param_1,int param_2,int param_3);
u32 FUN_003844b0(int param_1,int param_2,int param_3);
u32 FUN_003849e0(int param_1,int param_2,int param_3);
u32 FUN_00384d30(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_003851f0(int param_1,int param_2,int param_3);
u32 FUN_00386cd0(void);
u32 FUN_00386e10(int param_1);
u32 FUN_00386e30(int param_1);
u32 FUN_0038a0b0(int param_1);
u32 FUN_0038a4b0(u32 param_1,int param_2,u32 *param_3,u32 *param_4);
u32 FUN_0038d6f0_y2(long param_1);
u32 FUN_0038d980(void);
u32 FUN_0038e860(long param_1,u64 param_2);
#pragma alias FUN_0038e860_i FUN_0038e860
extern u32 FUN_0038e860_i(int param_1,int param_2);
u32 FUN_003670f0(int param_1,int param_2,int param_3);
u64 FUN_00366f90(u64 param_1,u64 param_2,u32 param_3);
u32 FUN_00367190(int param_1,int param_2,int param_3);
u32 FUN_00367440(int param_1,int param_2,int param_3);
u64 FUN_00367230(u64 param_1,u64 param_2,int param_3);
u64 FUN_003674b0(u64 param_1,u64 param_2,u32 *param_3);
u64 FUN_00367a20(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367cb0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367d70(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367e00(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367ec0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368020(u64 param_1,u64 param_2,int param_3);
u64 FUN_003680e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_003682f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_003683a0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368440(u64 param_1,u64 param_2,int param_3);
u64 FUN_003684d0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_003685c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368680(u64 param_1,u64 param_2,int param_3);
u32 FUN_00368710(int param_1,int param_2,int param_3);
u64 FUN_003687b0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368830(u64 param_1,u64 param_2,int param_3);
u64 FUN_003688d0(u64 param_1,u64 param_2,int param_3,int param_4);
u32 FUN_003689c0(int param_1,int param_2,int param_3);
u64 FUN_00368a30(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_00368b00(u64 param_1,int param_2,int param_3);
u64 FUN_00368c10(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368cb0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368f20(u64 param_1,int param_2,u8 *param_3);
u64 FUN_00369320(u64 param_1,int param_2,u64 param_3);
u32 FUN_003698a0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00369a20(int param_1,u64 param_2,int param_3);
u64 FUN_0036be10(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_0036cc30(u64 param_1,u64 param_2,u8 *param_3);
u64 FUN_0036f500_y2(long param_1);
#pragma alias FUN_0036f500_s32 FUN_0036f500_y2
extern s32 FUN_0036f500_s32(long param_1);
u64 FUN_003709d0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003715b0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00379f30(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0037a640(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0037abd0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00385bd0(int param_1,u64 param_2);
u32 FUN_00385cd0(int param_1);
u32 FUN_00385e20(int param_1);
u32 FUN_00385f00(int param_1);
u32 FUN_00385f90(int param_1);
u32 FUN_00386060(int param_1);
u32 FUN_00386130(int param_1,u32 *param_2,u32 *param_3);
u32 FUN_00386230(int param_1,u32 *param_2,u32 *param_3);
u32 FUN_00386310(int param_1);
u64 FUN_00386430(int param_1,short param_2,u32 param_3);
u32 FUN_003865f0(int param_1);
u32 FUN_00386780(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386860(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386940(u32 param_1,int param_2,u32 param_3);
u32 FUN_00386a00(int param_1,u32 param_2);
u64 FUN_0038da10(u16 *param_1);
s8 FUN_0036fa40(int param_1);
u8 FUN_00373590(u64 param_1,u64 param_2,u64 param_3);
void FUN_00361050(int param_1,u32 param_2);
void FUN_00361070(int param_1);
void FUN_00361140(u8 *param_1,u16 *param_2);
#pragma alias FUN_00361140_raw FUN_00361140
extern void FUN_00361140_raw();
void FUN_00361200(int param_1,int param_2);
void FUN_00361270(int param_1);
void FUN_00361890(int *param_1,int param_2);
void FUN_00361980(int param_1);
void FUN_00361b60(int *param_1,int param_2);
void FUN_00361c30(int param_1,int param_2);
void FUN_00361d60(int param_1,u16 param_2,u32 param_3);
void FUN_00362100(void);
void FUN_00362110(void);
void FUN_00362120(int param_1,int param_2,int param_3);
#pragma alias FUN_00362120_evt FUN_00362120
extern void FUN_00362120_evt(int param_1,int param_2,int param_3);
void FUN_00362240(int param_1);
void FUN_00362390(int param_1);
void FUN_003625e0(void);
void FUN_003628f0(void);
void FUN_00362f20(int param_1);
void FUN_00362fa0(int param_1);
void FUN_00362ff0(int param_1);
void FUN_00363030(int *param_1,u16 *param_2,u32 param_3,u8 *param_4);
void FUN_003638e0(int *param_1,int param_2,int param_3,u32 param_4,int param_5);
void FUN_003648e0(int param_1,u32 param_2,int param_3);
void FUN_00364a30(u32 param_1,int param_2);
void FUN_00364e40(u32 param_1,int param_2,int param_3);
void FUN_003650c0(int param_1,u64 param_2,int param_3);
void FUN_00365250(u32 param_1,u64 param_2,int param_3);
void FUN_00365360(u32 param_1,u64 param_2,int param_3);
#pragma alias FUN_003650c0_i FUN_003650c0
#pragma alias FUN_00365250_i FUN_00365250
#pragma alias FUN_00365360_i FUN_00365360
extern void FUN_003650c0_i(int param_1,int param_2,int param_3);
extern void FUN_00365250_i(u32 param_1,int param_2,int param_3);
extern void FUN_00365360_i(u32 param_1,int param_2,int param_3);
void FUN_00365430(int param_1,int param_2);
void FUN_003657e0(int param_1,int param_2);
void FUN_003658b0(u32 param_1,int param_2);
void FUN_00365a40(u32 param_1,int param_2);
void FUN_00365b70(u32 param_1,u32 param_2);
void FUN_00365cd0(u32 param_1,int param_2);
void FUN_00365f80(u32 param_1,u32 param_2);
void FUN_00366210(u32 param_1,int param_2);
void FUN_00366330(u32 param_1,int param_2);
void FUN_003663f0(u32 param_1,int param_2);
void FUN_00366660(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5);
void FUN_00366970(u32 param_1,u32 param_2);
void FUN_00366ac0(u32 param_1,u32 param_2);
void FUN_0036d030(int param_1);
void FUN_0036efb0(void);
void FUN_0036f000(int param_1);
void FUN_0036f260(void);
void FUN_0036f370(int param_1);
void FUN_0036f3b0(u64 param_1,u32 param_2);
void FUN_0036f490(int param_1);
void FUN_0036f4d0(void);
void FUN_0036f5f0(u32 param_1,u16 param_2,u16 param_3,int param_4);
void FUN_0036f680(long param_1,long param_2,int param_3,int param_4,u64 param_5, u16 param_6,u16 param_7);
void FUN_0036f900(u64 param_1,int param_2,int param_3,int param_4,int param_5, u64 param_6,u64 param_7,long param_8,code *param_9);
void FUN_0036fa80(int param_1,int param_2,int param_3,int param_4);
void FUN_003702a0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00371350(int param_1,int param_2,int param_3,int param_4);
void FUN_00371790(u64 param_1,u64 param_2,u32 param_3);
void FUN_003722d0(u64 param_1,u64 param_2,u32 param_3);
void FUN_003747a0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00374d30(u64 param_1,u64 param_2,u32 param_3);
void FUN_003753c0(u64 param_1,u64 param_2,u32 param_3);
void FUN_00375750(u64 param_1,u64 param_2,u32 param_3);
void FUN_00375ab0(u64 param_1,u64 param_2,u32 param_3);
void FUN_003760a0(int param_1,int param_2,u32 param_3,u16 *param_4,int param_5);
void FUN_003797b0(u64 param_1,u64 param_2,int param_3,int param_4);
void FUN_00379c30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a1e0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a560(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a790(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037ad30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037b350(int param_1,int param_2,int param_3,int param_4);
void FUN_0037baf0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037c350(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037cf50(u32 *param_1,u32 *param_2,u32 *param_3);
void FUN_0037cfe0(void);
void FUN_0037d540(int param_1,int param_2,long param_3,int param_4);
void FUN_0037dfc0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037e460(u64 param_1,u64 param_2,u32 param_3);
void FUN_0037f0c0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037f650(u64 param_1,u64 param_2,u32 param_3);
void FUN_0037ff80(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00380380(u64 param_1,u64 param_2,u32 param_3);
void FUN_00380a30(int param_1,int param_2,int param_3,int param_4);
void FUN_00381110(int param_1,int param_2,int param_3,int param_4);
void FUN_00381540(u64 param_1,u64 param_2,u32 param_3);
void FUN_00381c60(u64 param_1,u64 param_2,u32 param_3);
void FUN_00382390(int param_1,int param_2,int param_3,int param_4);
void FUN_00382760(int param_1,int param_2,int param_3,int param_4);
void FUN_00382c80(int param_1,int param_2,int param_3,int param_4);
void FUN_00382f30(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00383880(int param_1,int param_2,int param_3,u64 param_4);
void FUN_003840d0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00384520(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00384a50(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00385260(int param_1,int param_2,int param_3,u64 param_4);
void FUN_003858c0(void);
void FUN_00385990(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, u32 param_6);
void FUN_00385b20(int param_1);
void FUN_00385b90(void);
#pragma alias FUN_00385b90_evt_main FUN_00385b90
extern void FUN_00385b90_evt_main(u32 param_1);
void FUN_00385ba0(void);
void FUN_00386110(u32 *param_1,u32 *param_2);
void FUN_00386210(u32 *param_1,u32 *param_2);
void FUN_00386390(u32 *param_1,u32 *param_2,u32 *param_3,u32 *param_4);
void FUN_00386aa0(void);
void FUN_00386b70(int param_1,int param_2,int param_3);
#pragma alias FUN_00386b70_evt_main FUN_00386b70
extern void FUN_00386b70_evt_main(int param_1,int param_2,int param_3);
#pragma alias FUN_005225a8_evt_main FUN_005225a8
extern void FUN_005225a8_evt_main(void *param_1);
#pragma alias FUN_00195020_evt_main FUN_00195020
extern void FUN_00195020_evt_main(u32 param_1);
void FUN_00386c40(int param_1,int param_2);
void FUN_00386d50(int param_1);
void FUN_00386e20(int param_1,u32 param_2);
void FUN_00386e40(int param_1,u32 param_2);
void FUN_00386e50(void);
void FUN_00386f70(float param_1,float *param_2,float *param_3,u8 *param_4);
void FUN_003877c0(float param_1,int param_2,int param_3,u32 *param_4,u8 *param_5);
void FUN_00388000(float param_1,u32 param_2,float *param_3,float *param_4,u32 *param_5 ,u32 *param_6,u32 *param_7,u8 *param_8,long param_9);
void FUN_00388a40(float param_1,float *param_2,float *param_3,u8 *param_4);
void FUN_00388ff0(int param_1);
void FUN_003890e0(int param_1);
void FUN_003897f0(int param_1);
void FUN_00389b50(int *param_1);
void FUN_00389d80(u64 param_1,u64 param_2);
void FUN_00389f40(void);
void FUN_0038a0c0(int param_1,int param_2);
extern void FUN_001a4580(int param_1,float param_2);
void FUN_0038a140(u32 param_1,u32 *param_2);
void FUN_0038a180(int param_1,int param_2);
void FUN_0038a260(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, u64 param_6,u64 param_7,u64 param_8,u64 param_9);
void FUN_0038a590(int param_1,long param_2);
void FUN_0038a620(int param_1,long param_2);
void FUN_0038a6c0(int param_1);
void FUN_0038a730(int param_1);
void FUN_0038a7c0(u32 *param_1,u32 *param_2);
void FUN_0038a920(int param_1,u16 *param_2,int param_3);
void FUN_0038af70(u16 *param_1);
void FUN_0038b140(long param_1);
void FUN_0038b2c0(u16 *param_1,u32 *param_2,u32 *param_3,u64 param_4, long param_5);
void FUN_0038b550(long param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0038b600(u32 *param_1,u32 *param_2);
void FUN_0038b6e0(u64 param_1,int param_2,int param_3);
void FUN_0038b960(int param_1,long param_2,short param_3);
void FUN_0038bc70(int param_1,short param_2,int param_3);
void FUN_0038c460(long param_1,int param_2,int *param_3,u32 *param_4);
void FUN_0038c540(int param_1,u64 param_2,u64 param_3,u64 param_4, u32 *param_5,u32 *param_6);
void FUN_0038c830(u64 param_1,long param_2);
#pragma alias FUN_00362290_2390 FUN_00362290
extern u16 *FUN_00362290_2390();
#pragma alias FUN_00362310_2390 FUN_00362310
extern u16 *FUN_00362310_2390();
#pragma alias FUN_0038c830_2390 FUN_0038c830
extern void FUN_0038c830_2390(int param_1,int param_2);
void FUN_0038ca00(void);
void FUN_0038ca80(u64 param_1);
void FUN_0038cc10(int param_1,u16 *param_2,long param_3);
void FUN_0038d560(long param_1,long param_2,u32 param_3,u32 *param_4, u32 *param_5,u32 *param_6);
void FUN_0038d6b0(long param_1,u32 param_2);
void FUN_0038d720(int param_1);
void FUN_0038d790(int param_1);
void FUN_0038d840(char *param_1,u8 *param_2,int param_3);
void FUN_0038d910(u64 param_1);
void FUN_0038dad0(u32 param_1,long param_2,u64 param_3);
void FUN_0038e660(u64 param_1,int param_2,int param_3);
void FUN_0038f0f0(u64 param_1);
void FUN_0038f440(int param_1,u64 param_2,int param_3);
void FUN_0038f8c0(long param_1,u64 param_2,long param_3,short param_4);
void FUN_0038fa10(int param_1,u64 param_2);
void FUN_0038ffb0(int param_1,u64 param_2);

// FUN_00361050


void FUN_00361050(int param_1,u32 param_2)



{

  *(u32 *)(param_1 + 0x28) = param_2;

  *(u32 *)(param_1 + 0x24) = 1;

  return;

}


// FUN_00361070


void FUN_00361070(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  u32 *puVar6;

  u32 *puVar5;

  int iVar3;

  u32 *puVar4;

  u32 auStack_60 [24];

  

  puVar4 = (u32 *)param_1;

  uVar1 = *puVar4;

  puVar6 = puVar4 + 0x24a;

  puVar5 = auStack_60;

  iVar3 = 0x17;

  do {

    uVar2 = *puVar6;

    puVar6 = puVar6 + 1;

    iVar3 = iVar3 + -1;

    *puVar5 = uVar2;

    puVar5 = puVar5 + 1;

  } while (0 < iVar3);

  FUN_00521408(param_1,0,0x990);

  *puVar4 = uVar1;

  puVar6 = auStack_60;

  puVar5 = puVar4 + 0x24a;

  iVar3 = 0x17;

  do {

    uVar1 = *puVar6;

    puVar6 = puVar6 + 1;

    iVar3 = iVar3 + -1;

    *puVar5 = uVar1;

    puVar5 = puVar5 + 1;

  } while (0 < iVar3);

  FUN_00386aa0();

  puVar4[1] = puVar4[1] | 1;

  puVar4[3] = 0x21c;

  puVar4[5] = puVar4[3] - 1;

  puVar4[0x23] = 1;

  return;

}


// FUN_00361140


void FUN_00361140(u8 *param_1,u16 *param_2)



{

  u16 *puVar1;

  

  puVar1 = *(u16 **)(param_1 + 0x6c);

  if (puVar1 == (u16 *)0x0) {

    *(u16 **)(param_1 + 0x6c) = param_2;

    *(u16 **)(param_1 + 0x70) = param_2;

    *(u32 *)((int)param_2 + 0x4c) = 0;
    *(u32 *)((int)param_2 + 0x50) = 0;

  }

  else {

    for (; puVar1 != (u16 *)0x0; puVar1 = *(u16 **)(puVar1 + 0x26)) {

      if (*param_2 < *puVar1) {

        if (*(int *)(puVar1 + 0x28) == 0) {

          *(u16 **)(param_1 + 0x6c) = param_2;

          *(u16 **)(puVar1 + 0x28) = param_2;

          *(u32 *)((int)param_2 + 0x50) = 0;

          *(u16 **)(param_2 + 0x26) = puVar1;

        }

        else {

          *(u16 **)(*(int *)(puVar1 + 0x28) + 0x4c) = param_2;

          *(u32 *)(param_2 + 0x28) = *(u32 *)(puVar1 + 0x28);

          *(u16 **)(param_2 + 0x26) = puVar1;

          *(u16 **)(puVar1 + 0x28) = param_2;

        }

        break;

      }

    }

    if (puVar1 == (u16 *)0x0) {

      *(u16 **)(*(int *)(param_1 + 0x70) + 0x4c) = param_2;

      *(u32 *)(param_2 + 0x28) = *(u32 *)(param_1 + 0x70);

      *(u32 *)(param_2 + 0x26) = 0;

      *(u16 **)(param_1 + 0x70) = param_2;

    }

  }

  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

  return;

}


// FUN_00361200


void FUN_00361200(int param_1,int param_2)



{

  if (*(int *)(param_2 + 0x50) == 0) {

    *(u32 *)(param_1 + 0x6c) = *(u32 *)(param_2 + 0x4c);

  }

  else {

    *(u32 *)(*(int *)(param_2 + 0x50) + 0x4c) = *(u32 *)(param_2 + 0x4c);

  }

  if (*(int *)(param_2 + 0x4c) == 0) {

    *(u32 *)(param_1 + 0x70) = *(u32 *)(param_2 + 0x50);

  }

  else {

    *(u32 *)(*(int *)(param_2 + 0x4c) + 0x50) = *(u32 *)(param_2 + 0x50);

  }

  *(u32 *)(param_2 + 0x50) = 0;

  *(u32 *)(param_2 + 0x4c) = 0;

  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;

  return;

}


// FUN_00361270 NONMATCHING


void FUN_00361270(int param_1)
{
  u16 *puVar1;
  int extraout_a0_lo;
  int iVar2;
  u16 *extraout_a1_lo;
  u16 *puVar3;

  iVar2 = (int)param_1;
  if (param_1 != 0) {
    for (puVar3 = *(u16 **)(iVar2 + 0x6c); puVar3 != (u16 *)0x0;
        puVar3 = *(u16 **)(puVar3 + 0x26)) {
      for (puVar1 = *(u16 **)(puVar3 + 0x26); puVar1 != (u16 *)0x0;
          puVar1 = *(u16 **)(puVar1 + 0x26)) {
        if (*puVar3 > *puVar1) {
          if (*(int *)(puVar1 + 0x28) == 0) {
            *(u32 *)(iVar2 + 0x6c) = *(u32 *)(puVar1 + 0x26);
          }
          else {
            *(u32 *)(*(int *)(puVar1 + 0x28) + 0x4c) = *(u32 *)(puVar1 + 0x26);
          }
          if (*(int *)(puVar1 + 0x26) == 0) {
            *(u32 *)(iVar2 + 0x70) = *(u32 *)(puVar1 + 0x28);
          }
          else {
            *(u32 *)(*(int *)(puVar1 + 0x26) + 0x50) = *(u32 *)(puVar1 + 0x28);
          }
          *(u32 *)((int)puVar1 + 0x50) = 0;
          *(u32 *)((int)puVar1 + 0x4c) = 0;
          *(int *)(iVar2 + 0x68) = *(int *)(iVar2 + 0x68) + -1;
          FUN_00361140_raw(iVar2, puVar1);
          iVar2 = extraout_a0_lo;
          puVar3 = extraout_a1_lo;
          break;
        }
      }
    }
  }
  return;
}








// Transferred the matched node-walk shape: hoist the bound once, then advance
// the link before incrementing the counter. This improves nd216 -> nd189 at
// unchanged size 480/480; hidden-argument probes reached 504/480 and were reverted.
















/* W367 pragma probe: opt_loop_invariants on nd 61 -> 36; off nd 61; object 116/128. */


// Two honest branch-layout attempts were measured and reverted: an early return
// from the search loop regressed nd108 -> nd173/size260 -> 264; inverting the
// call test plus an early post-loop return regressed to nd118/size272.
#pragma opt_loop_invariants reset

















/* W367 pragma probe: opt_propagation off nd 1120 -> 1076; on nd 1120; object 1504/1584. */


#pragma opt_propagation reset






/* W367 pragma probe: opt_dead_assignments off nd 1471 -> 1426; on nd 1471; object 2220/2224. Stacked loop invariants exceeded the window (nd 1465, object 2228/2224). */


#pragma opt_dead_assignments reset
/* W367 pragma probe: opt_lifetimes on nd 1957 -> 1953; off nd 1957; object 2828/2960. */


// b210 floor: the only residual is call-argument setup order. At +0xc8/+0xcc,
// retail loads a2 before a0; at +0xec..+0x100, retail loads v0/addiu/andi,
// a3/t0 before a0, while b210 emits the independent a0 load first.
#pragma opt_lifetimes reset

// W295: the "call-argument setup order" here was fixable: retail loads the lh
// (arg3) before the stack fills and the lhu (arg1) last - two volatile-ordered
// temps reproduce it (same lever as FUN_00364470).


/* W367 pragma probe: opt_common_subs off nd 296 -> 280; on nd 296; object 512/528. */


#pragma opt_common_subs reset






extern void FUN_00319090(void *param_1, f32 param_2);



// The first divergence suggests a 0x000ffc00 mask, but that informed spelling
// regressed nd219 -> nd224 and size392 -> 396, so it was reverted.
/* W367 pragma probe: opt_common_subs off nd 239 -> 170; on nd 239; object 400/400. */


// Corrected the case-0 byte contract to u8 (retail lbu). The seven remaining
// differing words are b210 call-argument setup order at +0x8c/+0x90 and
// +0xc8/+0xcc: retail materializes a1 before the independent a0 load.
#pragma opt_common_subs reset




// Caller-specific absolute BYTE-base loads reproduce retail's shared DAT offsets.
// A typed aggregate assignment and early stack-pointer local now reproduce
// retail's load/store staging; five reloc-masked words remain as b210 choices:
// a1 setup, v0/v1 load coloring, and independent store/call setup.
















/* W367 pragma probe: opt_loop_invariants on nd 103 -> 91; off nd 103; object 288/288. */


#pragma opt_loop_invariants reset






/* W367 pragma probe: opt_lifetimes on nd 404 -> 301; off nd 404; object 780/784. */


#pragma opt_lifetimes reset
/* W367 pragma probe: opt_lifetimes on nd 135 -> 125; off nd 135; object 300/336. */


#pragma opt_lifetimes reset
/* W367 stacked probe: opt_loop_invariants + opt_lifetimes nd 451 -> 431; singles 447/436; object 984/992. */


#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset



// Removed an invented cast-only base local so the function uses param_3 directly.
// This improves nd245 -> nd244 at unchanged size348/352; the remaining first
// divergence is saved-register coloring and load/branch scheduling.
/* W367 pragma probe: opt_common_subs off nd 244 -> 212; on nd 244; object 348/352. */


#pragma opt_common_subs reset










/* W367 pragma probe: opt_common_subs off nd 836 -> 766; on nd 836; object 1388/1392. */


#pragma opt_common_subs reset














































/* W367 pragma probe: opt_loop_invariants on nd 296 -> 275; off nd 296; object 996/1024. */


#pragma opt_loop_invariants reset
/* W367 pragma probe: opt_loop_invariants on nd 886 -> 879; off nd 886; object 1396/1408. */


// Removing the decompiler's apparent t0 call-output assignment regressed
// nd224 -> nd234 at unchanged size376/384, so the assignment was restored.
#pragma opt_loop_invariants reset










/* W367 pragma probe: opt_common_subs off nd 72 -> 61; on nd 72; object 744/752. */


#pragma opt_common_subs reset








// b210 floor after an informed type attempt regressed and was reverted: all 22
// remaining words are cyclic saved-register coloring (ours s1/s0/s3/s2 versus
// retail s3/s2/s1/s0), including the dependent moves/sign extensions/branches.


/* W367 pragma probe: opt_common_subs off nd 977 -> 927; on nd 977; object 1564/1568. */


#pragma opt_common_subs reset






/* W367 pragma probe: opt_propagation off nd 1100 -> 1093; on nd 1100; object 1688/1696. */


#pragma opt_propagation reset
