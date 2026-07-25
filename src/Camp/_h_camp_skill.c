#include "Camp/_h_camp_skill.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_maestro.h"

extern u32 DAT_00833a50[];

// workData[0xc] holds the "camp/camp_skil.pak" cdvd handle.
// FUN_001616d0. Destroy callback of the "H_NewCampSkillDraw" (skill screen) task
void h_campSkillDestroySkillDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
    if (workData[0xe] != 0) {
        RwFree((void*)workData[0xe]);
    }
    workData[0xe] = 0;
    if (workData[0xa] != 0) {
        RwFree((void*)workData[0xa]);
    }
    workData[0xa] = 0;
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x1c) != 0) {
            FUN_001124b0((void*)*(int*)((int)workData + i * 4 + 0x1c));
        }
        *(int*)((int)workData + i * 4 + 0x1c) = 0;
        DAT_00833a50[i] = 0;
    }
    if (workData[0xc] != 0) {
        H_Cdvd_Destroy((HCdvd*)workData[0xc]);
    }
    workData[0xc] = 0;
    RwFree(workData);
}

typedef struct CampSkillVec2
{
    f32 x;
    f32 y;
} CampSkillVec2;

typedef struct CampSkillRecord
{
    u8 reserved00[4];
    u32 enabled;          /* 0x04 */
    u8 reserved08[0x1c];
    f32 depth;           /* 0x24 */
    u8 reserved28[8];
    f32 animation;        /* 0x30 */
    f32 animationTail;    /* 0x34 */
    f32 x;                /* 0x38 */
    f32 y;                /* 0x3c */
    u32 alpha;            /* 0x40 */
} CampSkillRecord;

typedef struct CampSkillOuterWork
{
    u32 state;            /* 0x00 */
    u32 displayMode;      /* 0x04 */
    u32 reserved08;       /* 0x08 */
    s16 pcId;             /* 0x0c */
    s16 reserved0e;       /* 0x0e */
    u32 frame;            /* 0x10 */
    KwlnTask* child;      /* 0x14 */
    u8 reserved18[0x0c];
    f32 scrollX;          /* 0x24 */
    f32 scrollY;          /* 0x28 */
    u32 scrolling;        /* 0x2c */
} CampSkillOuterWork;

typedef struct CampSkillInnerWork
{
    u32 state;            /* 0x00 */
    u32 displayMode;      /* 0x04 */
    s16 pcId;             /* 0x08 */
    s16 reserved0a;       /* 0x0a */
    u32 command;          /* 0x0c */
    s32 category;         /* 0x10 */
    u32 commandFlags;     /* 0x14 */
    HCdvd* archive;       /* 0x18 */
    void* archiveParser;  /* 0x1c */
    void* resource0;      /* 0x20 */
    void* resource1;      /* 0x24 */
    void* parserState;    /* 0x28 */
    CampSkillRecord* listRecords;   /* 0x2c */
    CampSkillRecord* detailRecords; /* 0x30 */
    u8* detailData;       /* 0x34 */
} CampSkillInnerWork;

typedef struct CampSkillSelectorWork
{
    u32 state;            /* 0x00 */
    u32 displayMode;      /* 0x04 */
    s16 pcId;             /* 0x08 */
    s16 reserved0a;       /* 0x0a */
    u8 reserved0c[4];
    u32 frame;            /* 0x10 */
    KwlnTask* child;      /* 0x14 */
    u8 reserved1c[8];
    s16 characterIds[9];    /* 0x24 */
    s16 reserved36;         /* 0x36 */
    s16 count;              /* 0x38 */
    s16 selected;           /* 0x3a */
    u32 transition;         /* 0x3c */
    f32 scrollX;            /* 0x40 */
    f32 scrollY;            /* 0x44 */
} CampSkillSelectorWork;

extern KwlnTask* DAT_007cdf54;
extern KwlnTask* DAT_007cdf58;
extern KwlnTask* DAT_007cdf88;
extern void* DAT_00833B70;
#pragma alias DAT_00833B70_abs DAT_00833B70
extern u8 DAT_00833B70_abs[];
extern void* DAT_00833B94;
extern void* DAT_00833BA0;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e0958;
extern u16 DAT_007e095a;

extern void* FUN_00160800(KwlnTask* task);
extern void FUN_00122630(KwlnTask* task);
extern void* FUN_00122940(KwlnTask* task);
extern void h_campPersonaDestroyKaniControlTask(KwlnTask* task);
extern void* FUN_00167f10(KwlnTask* task);
extern s32 FUN_00167f30(KwlnTask* task);
extern KwlnTask* FUN_00167f40(u32 first, ...);
extern void FUN_00167ef0(KwlnTask* task);
extern s32 FUN_001685b0(KwlnTask* task);
extern s32 FUN_001685d0(KwlnTask* task);
extern void FUN_001685e0(KwlnTask* task, s32 command);
extern s32 FUN_00168770(void);
extern s32 FUN_00195020(KwlnTask* task);
extern s32 FUN_00195290(KwlnTask* task);
extern void* FUN_0010c1a0(void* first, ...);
extern void* FUN_0010c3a0(void* first, ...);
extern void* FUN_0018b6d0(s32 count);
extern s32 FUN_0018b700(void* record);
extern void FUN_0018bc10(f32 first, void* animation, s32 start,
                         s32 end, s32 mode, u64 startValues,
                         u64 endValues, u32 param8, u32 param9);
extern void FUN_001159f0(f32 first, ...);
extern void FUN_00115bc0(f32 first, ...);
extern void FUN_001140d0(s32 color, s32 width, s32 height, void* parser,
                         f32 depth, f32 x, f32 y);
extern void FUN_003b2cb0(f32 first, ...);
extern void FUN_003b32d0(f32 first, ...);
extern void FUN_003c7e20(f32 first, ...);
extern void FUN_00523ac8(void* first, ...);
extern u32 FUN_0017d800(void);
extern u32 FUN_00174800(u32 pcId);
extern s32 FUN_0012df50(u32 typeMask);
extern void FUN_0012e170(void* atlas, s32 baseTile, CampSkillVec2 position,
                         s32 scale, s32 red, s32 green, s32 blue, s32 alpha,
                         s32 value, s32 digits);
extern void FUN_0013c240(void* data, s16 pcId, s16 category);
extern void FUN_00177c10(s16 pcId, s16 equipment);
extern void* FUN_001158b0(void* owner, void* atlas, s32 tile);
extern void FUN_001127d0(void* sprite, s32 enabled);
extern void FUN_00115980(void* sprite);
extern void FUN_0010a4e0(s32 first, ...);
extern void FUN_004d0f00(void* parser);
extern void (*jtbl_0096017C)(void* memory);
 #pragma alias jtbl_0096017C_abs jtbl_0096017C
 extern void (*jtbl_0096017C_abs[])(...);

extern KwlnTask* FUN_00166a50(KwlnTask* parent, u32 priority, s16 pcId,
                              u32 mode, u32 displayMode);
extern s32 FUN_00166c00(KwlnTask* task);
extern void FUN_00166c30(KwlnTask* task);
extern void FUN_00166c50(KwlnTask* task);


static void* campSkillWord(void* ptr, s32 offset)
{
    return *(void**)((u8*)ptr + offset);
}

static u32 campSkillU32(const void* ptr, s32 offset)
{
    return *(const u32*)((const u8*)ptr + offset);
}

static void campSkillSetU32(void* ptr, s32 offset, u32 value)
{
    *(u32*)((u8*)ptr + offset) = value;
}

static s16 campSkillS16(const void* ptr, s32 offset)
{
    return *(const s16*)((const u8*)ptr + offset);
}

static void campSkillSetS16(void* ptr, s32 offset, s16 value)
{
    *(s16*)((u8*)ptr + offset) = value;
}

static f32 campSkillFloat(const void* ptr, s32 offset)
{
    return *(const f32*)((const u8*)ptr + offset);
}

static void campSkillSetFloat(void* ptr, s32 offset, f32 value)
{
    *(f32*)((u8*)ptr + offset) = value;
}

typedef void (*CampSkillSpriteCall)(void* owner, void* atlas, s32 tile,
                                    u32 alpha, f32 x, f32 y, f32 depth);
typedef void (*CampSkillTintSpriteCall)(void* owner, void* atlas, s32 tile,
                                        u32 alpha, u32 red, u32 green,
                                        u32 blue, f32 x, f32 y, f32 depth);
typedef void (*CampSkillTextCall)(f32 depth, s32 x, s32 y, s32 color,
                                  s32 font, s32 alignment, const char* text,
                                  s32 maxWidth, s32 shadow);
typedef void (*CampSkillValueCall)(f32 depth, s32 x, s32 y, s32 color,
                                   s32 style, s32 font, s32 alignment,
                                   u32 value);

#pragma alias FUN_001159f0_typed FUN_001159f0
extern void FUN_001159f0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                f32 x, f32 y, f32 depth);
#pragma alias FUN_00115bc0_typed FUN_00115bc0
extern void FUN_00115bc0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                u32 red, u32 green, u32 blue, f32 x, f32 y,
                                f32 depth);
#pragma alias FUN_003b32d0_typed FUN_003b32d0
extern void FUN_003b32d0_typed(f32 depth, s32 x, s32 y, s32 color, s32 font,
                                s32 alignment, const char* text, s32 maxWidth,
                                s32 shadow);
#pragma alias FUN_003b2cb0_typed FUN_003b2cb0
extern void FUN_003b2cb0_typed(f32 depth, s32 x, s32 y, s32 color, s32 font,
                                s32 alignment, const char* text, s32 maxWidth,
                                s32 shadow);
#pragma alias FUN_003c7e20_typed FUN_003c7e20
extern void FUN_003c7e20_typed(f32 depth, s32 x, s32 y, s32 color, s32 style,
                                s32 font, s32 alignment, u32 value);

static void campSkillDrawSprite(const CampSkillRecord* record, void* atlas,
                                s32 tile, f32 x, f32 y)
{
    FUN_001159f0_typed(NULL, atlas, tile, record->alpha,
                                        x, y, record->depth);
}

static void campSkillDrawTintedSprite(const CampSkillRecord* record,
                                      void* atlas, s32 tile, f32 x, f32 y,
                                      u32 red, u32 green, u32 blue)
{
    FUN_00115bc0_typed(
        NULL, atlas, tile, record->alpha, red, green, blue, x, y,
        record->depth);
}

static void campSkillDrawText(const CampSkillRecord* record, s32 x, s32 y,
                              s32 color, s32 font, const char* text,
                              s32 shadow)
{
    FUN_003b32d0_typed(
        record->depth, x, y, color, font, 1, text, 0x10, shadow);
}

static void campSkillDrawSmallText(const CampSkillRecord* record, s32 x,
                                   s32 y, s32 color, s32 font,
                                   const char* text, s32 shadow)
{
    FUN_003b2cb0_typed(
        record->depth, x, y, color, font, 1, text, 0x10, shadow);
}

static void campSkillDrawNumberColor(const CampSkillRecord* record,
                                     void* atlas, f32 x, f32 y, s32 red,
                                     s32 green, s32 blue, s32 value, s32 digits)
{
    CampSkillVec2 position;

    position.x = x;
    position.y = y;
    FUN_0012e170(atlas, 0xb, position, (s32)record->depth, red, green, blue,
                 (s32)record->alpha, value, digits);
}

static void campSkillDrawNumber(const CampSkillRecord* record, void* atlas,
                                f32 x, f32 y, s32 value, s32 digits)
{
    campSkillDrawNumberColor(record, atlas, x, y, 0xff, 0xff, 0xff, value,
                             digits);
}

static s32 campSkillDrawColor(const CampSkillRecord* record)
{
    return (s32)((0xffU - record->alpha) | 0xffffff00U);
}

static void campSkillDrawEquipmentRow(CampSkillRecord* record,
                                      CampSkillInnerWork* work, s32 category)
{
    s16 pcId;
    s16 equipment;
    u16 id;
    u8 effect;
    s32 style;
    s32 value;
    s32 valueA;
    s32 valueB;
    s32 selected;
    u8 alpha;
    char text[0x100];
    void* atlas;
    void* glyphs;

    pcId = work->pcId;
    equipment = datGetEquipmentIdx(pcId, (s16)category);
    id = datGetEquipmentId(pcId, equipment);
    effect = func_0016f810(pcId, equipment);
    style = FUN_0012df50((u32)func_0016f720(pcId, equipment));
    value = (s32)func_00171110(id, effect);
    selected = work->category == category && work->commandFlags == 0;
    alpha = (u8)record->alpha;
    atlas = DAT_00833B94;
    glyphs = DAT_00833B70;

    campSkillDrawSprite(record, atlas, 0x24, record->x - 15.0f,
                        record->y + 4.0f);
    if (selected) {
        campSkillDrawSprite(record, atlas, 0x2a, record->x - 15.0f,
                            record->y - 3.0f);
        campSkillDrawTintedSprite(record, glyphs, style * 2, record->x,
                                  record->y, 0x20, 0x43, 0x78);
    } else {
        campSkillDrawSprite(record, glyphs, style * 2 + 1, record->x,
                            record->y);
    }
    sprintf(text, "%d", value);
    campSkillDrawText(record, (s32)(record->x + 40.0f),
                      (s32)(record->y + 11.0f), campSkillDrawColor(record),
                      selected ? 10 : 6, text, 0x76);

    if (category == 0) {
        campSkillDrawSprite(record, DAT_00833B94, selected ? 0x26 : 0x20,
                            record->x + 247.0f, record->y + 7.0f);
        valueA = (s32)func_0016f9f0(pcId, equipment);
        valueB = (s32)func_0016fae0(pcId, equipment);
        campSkillDrawNumber(record,
                            (void*)H_Maestro_001120a0(selected ? 2 : 1),
                            record->x + 284.0f, record->y + 14.0f, valueA, 3);
        campSkillDrawSprite(record, DAT_00833B94, 0x27,
                            record->x + 348.0f, record->y + 7.0f);
        campSkillDrawNumber(record,
                            (void*)H_Maestro_001120a0(selected ? 2 : 1),
                            record->x + 385.0f, record->y + 14.0f, valueB, 3);
    } else if (category == 1) {
        campSkillDrawSprite(record, DAT_00833B94, selected ? 0x28 : 0x22,
                            record->x + 247.0f, record->y + 7.0f);
        valueA = (s32)func_0016fbd0(pcId, equipment);
        campSkillDrawNumber(record, (void*)H_Maestro_001120a0(selected ? 2 : 1),
                            record->x + 284.0f, record->y + 14.0f, valueA, 3);
    } else if (category == 2) {
        campSkillDrawSprite(record, DAT_00833B94, selected ? 0x29 : 0x23,
                            record->x + 247.0f, record->y + 7.0f);
        valueA = (s32)func_0016fcc0(pcId, equipment);
        campSkillDrawNumber(record, (void*)H_Maestro_001120a0(selected ? 2 : 1),
                            record->x + 284.0f, record->y + 14.0f, valueA, 3);
    }
    (void)alpha;
}

static void campSkillDrawSkillAnimatedTail(CampSkillRecord* record,
                                            CampSkillInnerWork* work)
{
    s32 color;
    f32 wrappedY;

    color = campSkillDrawColor(record);
    FUN_001140d0(color, 0x200, 0x400, work->archiveParser, record->depth,
                 record->x, record->y);
    if (record->y < -616.0f) {
        wrappedY = record->y + 1064.0f;
        FUN_001140d0(color, 0x200, 0x400, work->archiveParser,
                     record->depth, record->x, wrappedY);
    }
    record->animationTail -= 1.0f;
    if (record->animationTail < -1064.0f) {
        record->animationTail = 0.0f;
    }
}

static void campSkillDrawSkillDecorations(CampSkillRecord* record,
                                           CampSkillInnerWork* work)
{
    if (work->commandFlags != 0) {
        campSkillDrawSprite(record, DAT_00833BA0, 8, record->x + 182.0f,
                            record->y);
        campSkillDrawSprite(record, DAT_00833BA0, 4, record->x + 342.0f,
                            record->y);
    } else {
        campSkillDrawSprite(record, DAT_00833BA0, 4, record->x + 232.0f,
                            record->y);
        campSkillDrawSprite(record, DAT_00833BA0, 2, record->x + 451.0f,
                            record->y);
    }
    campSkillDrawSprite(record, DAT_00833BA0, 1, record->x + 561.0f,
                        record->y);
}

// FUN_00161D90 NONMATCHING
#pragma schedule on
void FUN_00161d90(void* recordData, s32 index, CampSkillInnerWork* work)
{
    CampSkillRecord* record;
    s16 equipment;
    u16 id;
    u8 effect;
    s32 style;
    s32 value;
    s32 valueA;
    s32 valueB;
    void* atlas;
    void* glyphs;
    char text[0x120];
    CampSkillVec2 position;

    record = (CampSkillRecord*)recordData;
    switch (index) {
    case 2:
    {
        /* -- category 0 -- */
        equipment = datGetEquipmentIdx(work->pcId, 0);
        valueA = (s32)func_0016f9f0(work->pcId, equipment);
        equipment = datGetEquipmentIdx(work->pcId, 0);
        valueB = (s32)func_0016fae0(work->pcId, equipment);
        FUN_001159f0_typed(recordData, DAT_00833B94, 0x24, record->alpha, record->x - 15.0f, record->y + 4.0f, record->depth);
        if (work->category == 0 && work->commandFlags == 0)
        {
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x2a, record->alpha, record->x - 15.0f, record->y - 3.0f, record->depth);
            equipment = datGetEquipmentIdx(work->pcId, 0);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_00115bc0_typed(recordData, DAT_00833B70, style * 2, record->alpha, 0x20, 0x43, 0x78, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               10, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x26, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(2), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x27, record->alpha, record->x + 348.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 385.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(2), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueB, 3);
        }
        else
        {
            equipment = datGetEquipmentIdx(work->pcId, 0);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_001159f0_typed(recordData, DAT_00833B70, style * 2 + 1, record->alpha, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x20, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(1), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x21, record->alpha, record->x + 348.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 385.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(1), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueB, 3);
        }
        break;
    }
    case 3:
    {
        /* -- category 1 -- */
        equipment = datGetEquipmentIdx(work->pcId, 1);
        valueA = (s32)func_0016fbd0(work->pcId, equipment);
        FUN_001159f0_typed(recordData, DAT_00833B94, 0x24, record->alpha, record->x - 15.0f, record->y + 4.0f, record->depth);
        if (work->category == 1 && work->commandFlags == 0)
        {
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x2a, record->alpha, record->x - 15.0f, record->y - 3.0f, record->depth);
            equipment = datGetEquipmentIdx(work->pcId, 1);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_00115bc0_typed(recordData, DAT_00833B70, style * 2, record->alpha, 0x20, 0x43, 0x78, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               10, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x28, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(2), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
        }
        else
        {
            equipment = datGetEquipmentIdx(work->pcId, 1);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_001159f0_typed(recordData, DAT_00833B70, style * 2 + 1, record->alpha, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x22, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(1), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
        }
        break;
    }
    case 4:
    {
        /* -- category 2 -- */
        equipment = datGetEquipmentIdx(work->pcId, 2);
        valueA = (s32)func_0016fcc0(work->pcId, equipment);
        FUN_001159f0_typed(recordData, DAT_00833B94, 0x24, record->alpha, record->x - 15.0f, record->y + 4.0f, record->depth);
        if (work->category == 2 && work->commandFlags == 0)
        {
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x2a, record->alpha, record->x - 15.0f, record->y - 3.0f, record->depth);
            equipment = datGetEquipmentIdx(work->pcId, 2);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_00115bc0_typed(recordData, DAT_00833B70, style * 2, record->alpha, 0x20, 0x43, 0x78, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               10, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x29, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(2), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
        }
        else
        {
            equipment = datGetEquipmentIdx(work->pcId, 2);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_001159f0_typed(recordData, DAT_00833B70, style * 2 + 1, record->alpha, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text + 0x20, 0x10, 0x76);

            FUN_001159f0_typed(recordData, DAT_00833B94, 0x23, record->alpha, record->x + 247.0f, record->y + 7.0f, record->depth);
            position.x = record->x + 284.0f;
            position.y = record->y + 14.0f;
            FUN_0012e170((void*)H_Maestro_001120a0(1), 0xb, position,
                         (s32)record->depth, 0xff, 0xff, 0xff,
                         (s32)record->alpha, valueA, 3);
        }
        break;
    }
    case 5:
    {
        /* -- category 3 -- */
        FUN_001159f0_typed(recordData, DAT_00833B94, 0x24, record->alpha, record->x - 15.0f, record->y + 4.0f, record->depth);
        if (work->category == 3 && work->commandFlags == 0)
        {
            FUN_001159f0_typed(recordData, DAT_00833B94, 0x2a, record->alpha, record->x - 15.0f, record->y - 3.0f, record->depth);
            equipment = datGetEquipmentIdx(work->pcId, 3);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_00115bc0_typed(recordData, DAT_00833B70, style * 2, record->alpha, 0x20, 0x43, 0x78, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               10, 1, text + 0x20, 0x10, 0x76);
        }
        else
        {
            equipment = datGetEquipmentIdx(work->pcId, 3);
            style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
            FUN_001159f0_typed(recordData, DAT_00833B70, style * 2 + 1, record->alpha, record->x, record->y, record->depth);
            id = datGetEquipmentId(work->pcId, equipment);
            effect = func_0016f810(work->pcId, equipment);
            value = (s32)func_00171110(id, effect);
            sprintf(text + 0x20, "%d", value);
            FUN_003b32d0_typed(record->depth, (s32)(record->x + 40.0f),
                               (s32)(record->y + 11.0f),
                               (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text + 0x20, 0x10, 0x76);
        }
        break;
    }
    case 0:
    {
        s32 color;
        color = (s32)((255 - record->alpha) | 0xffffff00);
        FUN_001140d0(color, 0x200, 0x400, work->archiveParser, record->depth, record->x, record->y);
        if (record->y < -616.0f) {
            FUN_001140d0(color, 0x200, 0x400, work->archiveParser, record->depth, record->x, record->y + 1064.0f);
        }
        record->animationTail -= 1.0f;
        if (record->animationTail < -1064.0f) {
            record->animationTail = 0.0f;
        }
        break;
    }
    case 7:
        FUN_001159f0_typed(recordData, work->resource0, 1, record->alpha, record->x, record->y, record->depth);
        break;
    case 8:
        if (work->commandFlags != 0) {
            FUN_001159f0_typed(recordData, DAT_00833BA0, 8, record->alpha, record->x + 182.0f, record->y, record->depth);
            FUN_001159f0_typed(recordData, DAT_00833BA0, 4, record->alpha, record->x + 342.0f, record->y, record->depth);
            FUN_001159f0_typed(recordData, DAT_00833BA0, 1, record->alpha, record->x + 561.0f, record->y, record->depth);
        } else {
            FUN_001159f0_typed(recordData, DAT_00833BA0, 4, record->alpha, record->x + 232.0f, record->y, record->depth);
            FUN_001159f0_typed(recordData, DAT_00833BA0, 2, record->alpha, record->x + 451.0f, record->y, record->depth);
            FUN_001159f0_typed(recordData, DAT_00833BA0, 1, record->alpha, record->x + 561.0f, record->y, record->depth);
        }
        break;
    case 1:
    case 6:
        break;
    }
}
#pragma schedule off

static u8* campSkillDetailEntry(const CampSkillInnerWork* work, s32 index)
{
    return work->detailData + index * 0x24;
}

#pragma push
// FUN_00163330 NONMATCHING
#pragma optimization_level 3
#pragma schedule on
void FUN_00163330(void* recordData, s32 index, CampSkillInnerWork* work)
{
    CampSkillRecord* record;
    u8 colourState[0x30];
    s32 selectedRow;
    s32 font;
    s32 tileUpDown[6][4];
    CampSkillVec2 position;
    CampSkillVec2 position2;
    char text[0x100];

    colourState[0] = colourState[1] = colourState[2] = colourState[3] = 0xff;
    colourState[4] = colourState[5] = colourState[6] = colourState[7] = 0xff;
    colourState[8] = colourState[9] = colourState[10] = colourState[11] = 0xff;
    colourState[12] = colourState[13] = colourState[14] = colourState[15] = 0xff;
    colourState[16] = colourState[17] = colourState[18] = colourState[19] = 0xff;
    record = (CampSkillRecord*)recordData;
    switch (index) {
    case 0:
        FUN_001159f0_typed(recordData, work->resource1, 0x17, record->alpha,
                           record->x, record->y, record->depth);
        break;
    case 1:
    {
        (void)datGetEquipmentIdx(work->pcId, (s16)work->category);
        switch (work->category) {
        case 0:
            FUN_001159f0_typed(recordData, work->resource1, 0x12, record->alpha,
                               record->x, record->y, record->depth);
            FUN_001159f0_typed(recordData, work->resource1, 0x15, record->alpha,
                               record->x + 89.0f, record->y, record->depth);
            break;
        case 1:
            FUN_001159f0_typed(recordData, work->resource1, 0x13, record->alpha,
                               record->x + 4.0f, record->y, record->depth);
            break;
        case 2:
            FUN_001159f0_typed(recordData, work->resource1, 0x14, record->alpha,
                               record->x + 4.0f, record->y, record->depth);
            break;
        }
        break;
    }
    case 2:
    {
        s16 equipment;
        s32 style;
        u16 id;
        u8 effect;
        s32 valueA;

        equipment = datGetEquipmentIdx(work->pcId, (s16)work->category);
        style = FUN_0012df50((u32)func_0016f720(work->pcId, equipment));
        id = datGetEquipmentId(work->pcId, equipment);
        effect = func_0016f810(work->pcId, equipment);
        sprintf(text, "%d", (s32)func_00171110(id, effect));

        switch (work->category) {
        case 0:
            FUN_001159f0_typed(recordData, work->resource1, 0x18, record->alpha,
                               record->x, record->y, record->depth);
            FUN_001159f0_typed(recordData, work->resource1, 0, record->alpha,
                               record->x + 19.0f, record->y + 6.0f, record->depth);
            FUN_001159f0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2 + 1, record->alpha,
                               record->x + 130.0f, record->y + 1.0f, record->depth);
            FUN_003b2cb0_typed(record->depth, (s32)(record->x + 170.0f),
                               (s32)(record->y + 10.0f), (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text, 0x10, 0);
            {
                void* numAtlas = (void*)H_Maestro_001120a0(1);
                valueA = (s32)func_0016f9f0(work->pcId, equipment);
                position.x = record->x + 434.0f;
                position.y = record->y + 15.0f;
                FUN_0012e170(numAtlas, 0xb, position,
                             (s32)record->depth, 0xff, 0xff, 0xff, (s32)record->alpha,
                             valueA, 3);
                numAtlas = (void*)H_Maestro_001120a0(1);
                valueA = (s32)func_0016fae0(work->pcId, equipment);
                position.x = record->x + 525.0f;
                FUN_0012e170(numAtlas, 0xb, position,
                             (s32)record->depth, 0xff, 0xff, 0xff, (s32)record->alpha,
                             valueA, 3);
            }
            break;
        case 1:
            FUN_001159f0_typed(recordData, work->resource1, 0x18, record->alpha,
                               record->x, record->y, record->depth);
            FUN_001159f0_typed(recordData, work->resource1, 2, record->alpha,
                               record->x + 19.0f, record->y + 6.0f, record->depth);
            FUN_001159f0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2 + 1, record->alpha,
                               record->x + 130.0f, record->y + 1.0f, record->depth);
            FUN_003b2cb0_typed(record->depth, (s32)(record->x + 170.0f),
                               (s32)(record->y + 10.0f), (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text, 0x10, 0);
            {
                void* numAtlas = (void*)H_Maestro_001120a0(1);
                valueA = (s32)func_0016fbd0(work->pcId, equipment);
                position.x = record->x + 434.0f;
                position.y = record->y + 15.0f;
                FUN_0012e170(numAtlas, 0xb, position,
                             (s32)record->depth, 0xff, 0xff, 0xff, (s32)record->alpha,
                             valueA, 3);
            }
            break;
        case 2:
            FUN_001159f0_typed(recordData, work->resource1, 0x18, record->alpha,
                               record->x, record->y, record->depth);
            FUN_001159f0_typed(recordData, work->resource1, 4, record->alpha,
                               record->x + 19.0f, record->y + 6.0f, record->depth);
            FUN_001159f0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2 + 1, record->alpha,
                               record->x + 130.0f, record->y + 1.0f, record->depth);
            FUN_003b2cb0_typed(record->depth, (s32)(record->x + 170.0f),
                               (s32)(record->y + 10.0f), (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text, 0x10, 0);
            {
                void* numAtlas = (void*)H_Maestro_001120a0(1);
                valueA = (s32)func_0016fcc0(work->pcId, equipment);
                position.x = record->x + 434.0f;
                position.y = record->y + 15.0f;
                FUN_0012e170(numAtlas, 0xb, position,
                             (s32)record->depth, 0xff, 0xff, 0xff, (s32)record->alpha,
                             valueA, 3);
            }
            break;
        case 3:
            FUN_001159f0_typed(recordData, work->resource1, 0x18, record->alpha,
                               record->x, record->y, record->depth);
            FUN_001159f0_typed(recordData, work->resource1, 6, record->alpha,
                               record->x + 19.0f, record->y + 6.0f, record->depth);
            FUN_001159f0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2 + 1, record->alpha,
                               record->x + 130.0f, record->y + 1.0f, record->depth);
            FUN_003b2cb0_typed(record->depth, (s32)(record->x + 170.0f),
                               (s32)(record->y + 10.0f), (s32)((0xffU - record->alpha) | 0xffffff00U),
                               6, 1, text, 0x10, 0);
            break;
        }
        break;
    }
    case 3:
    {
        s32 row;
        s32 count;
        s32 first;
        s32 selected;
        s32 scrollbar;
        s32 baselineA;
        s32 baselineB;
        s16 equipment;
        u8* data;
        void* atlas;

        data = work->detailData;
        count = *(s32*)(data + 0x2d64);
        selected = *(s32*)(data + 0x2d68);
        first = *(s32*)(data + 0x2d6c);
        atlas = work->resource1;

        FUN_001159f0_typed(recordData, atlas, 0x27, record->alpha,
                           record->x + 483.0f, record->y + 1.0f, record->depth);
        scrollbar = (count > 5) ? (first * 90) / (count - 5) : 0;
        FUN_001159f0_typed(recordData, atlas, 0x28, record->alpha,
                           record->x + 483.0f, record->y + 3.0f + (f32)scrollbar,
                           record->depth);

        baselineA = 0;
        baselineB = 0;
        if (work->category >= 0 && work->category <= 2) {
            equipment = datGetEquipmentIdx(work->pcId, (s16)work->category);
            if (work->category == 0) {
                baselineA = func_0016f9f0(work->pcId, equipment);
                baselineB = func_0016fae0(work->pcId, equipment);
            } else if (work->category == 1) {
                baselineA = func_0016fbd0(work->pcId, equipment);
            } else {
                baselineA = func_0016fcc0(work->pcId, equipment);
            }
        }

        for (row = 0; row < 5; row++) {
            s32 item;
            s32 style;
            s32 rowOffset;
            s32 value;
            u16 id;
            u8 effect;
            u8* entry;
            s32 tileUp;
            s32 tileDown;

            item = first + row;
            if (item >= count) {
                continue;
            }
            entry = (u8*)(work->detailData + item * 0x24);
            style = FUN_0012df50(*(u32*)(entry + 0x78));
            id = *(u16*)(entry + 0x64);
            effect = *(u8*)(entry + 0x7d);
            value = (s32)func_00171110(id, effect);
            sprintf(text, "%d", value);
            rowOffset = row * 26;
            selectedRow = selected == row;
            font = selectedRow ? 6 : 10;
            tileUp = selectedRow ? 0x1e : 0x1f;
            tileDown = selectedRow ? 0x20 : 0x21;
            tileUpDown[row][0] = tileUp;
            tileUpDown[row][1] = tileDown;
            tileUpDown[row][2] = font;
            tileUpDown[row][3] = selectedRow;

            if (selectedRow) {
                FUN_001159f0_typed(recordData, atlas, 0x25, record->alpha,
                                   record->x, record->y + (f32)rowOffset,
                                   record->depth);
                FUN_001159f0_typed(recordData, atlas, 0x26, record->alpha,
                                   record->x + 470.0f, record->y + (f32)rowOffset,
                                   record->depth);
            } else {
                FUN_00115bc0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2, record->alpha,
                                   0x20, 0x43, 0x78, record->x + 13.0f,
                                   record->y - 5.0f + (f32)rowOffset, record->depth);
            }
            FUN_001159f0_typed(recordData, *(void**)DAT_00833B70_abs, style * 2 + (selectedRow ? 1 : 0),
                               record->alpha, record->x + 13.0f,
                               record->y - 5.0f + (f32)rowOffset, record->depth);

            FUN_003b2cb0_typed(record->depth, (s32)(record->x + 53.0f),
                               (s32)(record->y + 9.0f + (f32)rowOffset),
                               (s32)((0xffU - record->alpha) | 0xffffff00U), font, 1, text, 0x10, 0);

            if (work->category == 0) {
                u16 statA = *(u16*)(entry + 0x80);
                u16 statB = *(u16*)(entry + 0x82);
                void* numAtlas;

                position2.x = record->x + 317.0f;
                position2.y = record->y + 9.0f + (f32)rowOffset;
                if ((s32)statA != baselineA) {
                    if (statA > baselineA) {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][0],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    } else {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][1],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    }
                }
                numAtlas = (void*)H_Maestro_001120a0(tileUpDown[row][3] ? 1 : 2);
                {
                    u8 r = 0xff, g = 0xff, b = 0xff;
                    if (tileUpDown[row][3] && (s32)statA > baselineA) {
                        r = 0xf3; g = 0xb3; b = 0xbd;
                    }
                    colourState[0] = r;
                    colourState[1] = g;
                    colourState[2] = b;
                    FUN_0012e170(numAtlas, 0xb, position2,
                                 (s32)record->depth,
                                 colourState[0], colourState[1], colourState[2],
                                 (s32)record->alpha, statA, 3);
                    selectedRow = tileUpDown[row][3];
                    font = tileUpDown[row][2];
                }

                position2.x = record->x + 408.0f;
                if ((s32)statB != baselineB) {
                    if (statB > baselineB) {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][0],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    } else {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][1],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    }
                }
                numAtlas = (void*)H_Maestro_001120a0(tileUpDown[row][3] ? 1 : 2);
                {
                    u8 r = 0xff, g = 0xff, b = 0xff;
                    if (tileUpDown[row][3] && (s32)statB > baselineB) {
                        r = 0xf3; g = 0xb3; b = 0xbd;
                    }
                    colourState[3] = (u8)(r & font);
                    colourState[4] = g;
                    colourState[5] = b;
                    FUN_0012e170(numAtlas, 0xb, position2,
                                 (s32)record->depth,
                                 colourState[3], colourState[4], colourState[5],
                                 (s32)record->alpha, statB, 3);
                    selectedRow = tileUpDown[row][3];
                    font = tileUpDown[row][2];
                }
            } else if (work->category == 1) {
                u16 statA = *(u16*)(entry + 0x84);
                void* numAtlas;

                position2.x = record->x + 317.0f;
                position2.y = record->y + 9.0f + (f32)rowOffset;
                if ((s32)statA != baselineA) {
                    if (statA > baselineA) {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][0],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    } else {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][1],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    }
                }
                numAtlas = (void*)H_Maestro_001120a0(tileUpDown[row][3] ? 1 : 2);
                {
                    u8 r = 0xff, g = 0xff, b = 0xff;
                    if (tileUpDown[row][3] && (s32)statA > baselineA) {
                        r = 0xf3; g = 0xb3; b = 0xbd;
                    }
                    colourState[6] = r;
                    colourState[7] = g;
                    colourState[8] = b;
                    FUN_0012e170(numAtlas, 0xb, position2,
                                 (s32)record->depth,
                                 colourState[6], colourState[7], colourState[8],
                                 (s32)record->alpha, statA, 3);
                    selectedRow = tileUpDown[row][3];
                    font = tileUpDown[row][2];
                }
            } else if (work->category == 2) {
                u16 statA = *(u16*)(entry + 0x86);
                void* numAtlas;

                position2.x = record->x + 317.0f;
                position2.y = record->y + 9.0f + (f32)rowOffset;
                if ((s32)statA != baselineA) {
                    if (statA > baselineA) {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][0],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    } else {
                        FUN_001159f0_typed(recordData, work->resource1, tileUpDown[row][1],
                                           record->alpha, position2.x + 49.0f,
                                           position2.y - 3.0f, record->depth);
                    }
                }
                numAtlas = (void*)H_Maestro_001120a0(tileUpDown[row][3] ? 1 : 2);
                {
                    u8 r = 0xff, g = 0xff, b = 0xff;
                    if (tileUpDown[row][3] && (s32)statA > baselineA) {
                        r = 0xf3; g = 0xb3; b = 0xbd;
                    }
                    colourState[9] = r;
                    colourState[10] = g;
                    colourState[11] = b;
                    FUN_0012e170(numAtlas, 0xb, position2,
                                 (s32)record->depth,
                                 colourState[9], colourState[10], colourState[11],
                                 (s32)record->alpha, statA, 3);
                    selectedRow = tileUpDown[row][3];
                    font = tileUpDown[row][2];
                }
            }
        }
        break;
    }
    case 4:
    {
        u8* sprite;

        sprite = (u8*)FUN_001158b0(NULL, work->resource1, 0x1b);
        *(f32*)(sprite + 0x2c) = record->depth;
        *(f32*)(sprite + 0x10) = record->x;
        *(f32*)(sprite + 0x14) = record->y;
        *(u8*)(sprite + 0x18) = (u8)record->alpha;
        *(f32*)(sprite + 0x20) = -45.0f;
        FUN_001127d0(sprite, 1);
        FUN_00115980(sprite);
        break;
    }
    case 6:
    {
        u8* data;
        u8* entry;
        s32 selected;
        s32 first;
        u32 packed;

        data = work->detailData;
        selected = *(s32*)(data + 0x2d68);
        first = *(s32*)(data + 0x2d6c);
        entry = (u8*)(work->detailData + (first + selected) * 0x24);
        packed = (u32)*(u16*)(entry + 0x64) |
                 ((u32)*(u8*)(entry + 0x7c) << 16);
        FUN_003c7e20_typed(
            record->depth, (s32)record->x, (s32)record->y,
            (s32)((0xffU - record->alpha) | 0xffffff00U), 1, 10, 1, packed);
        break;
    }
    case 7:
        FUN_001159f0_typed(recordData, work->resource1, 0x24, record->alpha,
                           record->x, record->y, record->depth);
        FUN_001159f0_typed(recordData, work->resource1, 0x23, record->alpha,
                           record->x + 15.0f, record->y - 5.0f, record->depth);
        break;
    case 5:
        break;
    }
}
#pragma pop


static void campSkillStartPanelPersona(KwlnTask* parent, s16 pcId)
{
    CampPanelTransitionWork* panelWork;
    u32* personaWork;

    panelWork = (CampPanelTransitionWork*)RwCalloc(1, 0x18, 0x40000);
    if (panelWork != NULL) {
        DAT_007cdf54 = kwlnTaskCreate(parent, "H_CampSkillPanel",
                                      0x18c1, h_campUpdatePanelTransition,
                                      FUN_00122630, panelWork);
        if (DAT_007cdf54 != NULL) {
            panelWork->drawId = pcId;
        } else {
            RwFree(panelWork);
        }
    }
    personaWork = (u32*)RwCalloc(1, 0x1c, 0x40000);
    if (personaWork != NULL) {
        DAT_007cdf58 = kwlnTaskCreate(parent, "H_CampSkillPersona",
                                      0x18c1, FUN_00122940,
                                      h_campPersonaDestroyKaniControlTask,
                                      personaWork);
        if (DAT_007cdf58 != NULL) {
            personaWork[4] = FUN_00174800((u32)(u16)pcId);
            *(s16*)((u8*)personaWork + 0x18) = pcId;
        } else {
            RwFree(personaWork);
        }
    }
}

static void campSkillScroll(f32* x, f32* y)
{
    FUN_001159f0(*x, *y, 0x42c80000);
    if (*x < 0.0f) {
        FUN_001159f0(*x + 640.0f, *y, 0x42c80000);
    }
    *x -= 1.0f;
    if (*x < -640.0f) {
        *x += 640.0f;
    }
}

typedef union CampSkillAnimPair
{
    u64 q;
    f32 f[2];
} CampSkillAnimPair;

static inline void campSkillOpenMain(CampSkillInnerWork* work)
{
    CampSkillAnimPair start;
    CampSkillAnimPair end;
    s32 i;

    if (DAT_007cdf54 != NULL) {
        h_campRequestMenuTransition(DAT_007cdf54, 2);
    }
    if (DAT_007cdf58 != NULL) {
        FUN_00122710(DAT_007cdf58, 2);
    }
    for (i = 0; i < 4; i++) {
        start.f[0] = 15.0f;
        start.f[1] = 47.0f + (f32)(i * 0x24);
        end = start;
        if (work->displayMode != 0) {
            end.f[0] -= 300.0f;
        } else {
            end.f[1] += 300.0f;
        }
        FUN_0018bc10(100.0f, &work->listRecords[i + 2], 0, 2, 1,
                     end.q, start.q, 0, 0);
    }
    start.f[0] = 400.0f;
    start.f[1] = 0.0f;
    FUN_0018bc10(100.0f, &work->listRecords[6], 0, 2, 1,
                 start.q, start.q, 0, 0);

    start.f[0] = 188.0f;
    start.f[1] = 0.0f;
    end = start;
    if (work->displayMode != 0) {
        end.f[0] -= 300.0f;
    } else {
        end.f[1] += 300.0f;
    }
    FUN_0018bc10(100.0f, work->listRecords, 0, 2, 1,
                 end.q, start.q, 0, 0);

    start.f[0] = 358.0f;
    start.f[1] = 36.0f;
    end = start;
    if (work->displayMode != 0) {
        end.f[0] -= 300.0f;
    } else {
        end.f[1] += 300.0f;
    }
    FUN_0018bc10(100.0f, &work->listRecords[7], 0, 2, 1,
                 end.q, start.q, 0, 0);

    start.f[0] = 0.0f;
    start.f[1] = 415.0f;
    end = start;
    if (work->displayMode != 0) {
        end.f[0] -= 300.0f;
    } else {
        end.f[1] += 300.0f;
    }
    FUN_0018bc10(100.0f, &work->listRecords[8], 0, 2, 1,
                 end.q, start.q, 0, 0);
}

static inline void campSkillCloseMain(CampSkillInnerWork* work)
{
    CampSkillAnimPair pair;
    s32 i;

    for (i = 0; i < 4; i++) {
        pair.f[0] = 15.0f;
        pair.f[1] = 47.0f + (f32)(i * 0x24);
        FUN_0018bc10(100.0f, &work->listRecords[i + 2], 0, 2, 1,
                     pair.q, pair.q, 0, 0);
    }
    pair.f[0] = 400.0f;
    pair.f[1] = 0.0f;
    FUN_0018bc10(100.0f, &work->listRecords[6], 0, 2, 1,
                 pair.q, pair.q, 0, 0);

    pair.f[0] = work->listRecords[0].animation;
    pair.f[1] = work->listRecords[0].animationTail;
    FUN_0018bc10(100.0f, work->listRecords, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 358.0f;
    pair.f[1] = 36.0f;
    FUN_0018bc10(100.0f, &work->listRecords[7], 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 0.0f;
    pair.f[1] = 415.0f;
    FUN_0018bc10(100.0f, &work->listRecords[8], 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    if (DAT_007cdf54 != NULL) {
        h_campRequestMenuTransition(DAT_007cdf54, 0);
    }
}

static inline void campSkillReturnMain(CampSkillInnerWork* work)
{
    CampSkillAnimPair start;
    CampSkillAnimPair end;
    s32 i;

    for (i = 0; i < 4; i++) {
        start.f[0] = 15.0f;
        start.f[1] = 47.0f + (f32)(i * 0x24);
        end = start;
        end.f[0] -= 300.0f;
        FUN_0018bc10(100.0f, &work->listRecords[i + 2], 0, 2, 1,
                     start.q, end.q, 0, 0);
    }
    start.f[0] = 400.0f;
    start.f[1] = 0.0f;
    FUN_0018bc10(100.0f, &work->listRecords[6], 0, 2, 1,
                 start.q, start.q, 0, 0);
    start.f[0] = work->listRecords[0].animation;
    start.f[1] = work->listRecords[0].animationTail;
    end = start;
    end.f[0] -= 300.0f;
    FUN_0018bc10(100.0f, work->listRecords, 0, 2, 1,
                 start.q, end.q, 0, 0);
    start.f[0] = 358.0f;
    start.f[1] = 36.0f;
    end = start;
    end.f[0] -= 300.0f;
    FUN_0018bc10(100.0f, &work->listRecords[7], 0, 2, 1,
                 start.q, end.q, 0, 0);
    start.f[0] = 0.0f;
    start.f[1] = 415.0f;
    end = start;
    end.f[0] -= 300.0f;
    FUN_0018bc10(100.0f, &work->listRecords[8], 0, 2, 1,
                 start.q, end.q, 0, 0);
    if (DAT_007cdf54 != NULL) {
        h_campRequestMenuTransition(DAT_007cdf54, 0);
    }
}

static inline void campSkillOpenDetail(CampSkillInnerWork* work)
{
    CampSkillAnimPair pair;
    s32 i;

    for (i = 0; i < 4; i++) {
        pair.f[0] = 15.0f;
        pair.f[1] = 47.0f + (f32)(i * 0x24);
        FUN_0018bc10(100.0f, &work->listRecords[i + 2], 0, 2, 1,
                     pair.q, pair.q, 0, 0);
    }
    pair.f[0] = 400.0f;
    pair.f[1] = 0.0f;
    FUN_0018bc10(100.0f, &work->listRecords[6], 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = work->listRecords[0].animation;
    pair.f[1] = work->listRecords[0].animationTail;
    FUN_0018bc10(100.0f, work->listRecords, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 358.0f;
    pair.f[1] = 36.0f;
    FUN_0018bc10(100.0f, &work->listRecords[7], 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 0.0f;
    pair.f[1] = 415.0f;
    FUN_0018bc10(100.0f, &work->listRecords[8], 0, 2, 1,
                 pair.q, pair.q, 0, 0);

    pair.f[0] = 19.0f;
    pair.f[1] = 36.0f;
    FUN_0018bc10(100.0f, work->detailRecords, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 419.0f;
    pair.f[1] = 37.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x44, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 0.0f;
    pair.f[1] = 60.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x88, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 117.0f;
    pair.f[1] = 108.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0xcc, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 486.0f;
    pair.f[1] = 364.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x110, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 182.0f;
    pair.f[1] = 242.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x198, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 28.0f;
    pair.f[1] = 421.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x1dc, 0, 2, 1,
                 pair.q, pair.q, 0, 0);
}

static inline void campSkillAnimateDetail(CampSkillInnerWork* work, s32 mode)
{
    CampSkillAnimPair pair;
    s32 i;

    for (i = 0; i < 4; i++) {
        pair.f[0] = 15.0f;
        pair.f[1] = 47.0f + (f32)(i * 0x24);
        FUN_0018bc10(100.0f, &work->listRecords[i + 2], 0, 2, mode,
                     pair.q, pair.q, 0, 0);
    }
    pair.f[0] = 400.0f;
    pair.f[1] = 0.0f;
    FUN_0018bc10(100.0f, &work->listRecords[6], 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = work->listRecords[0].animation;
    pair.f[1] = work->listRecords[0].animationTail;
    FUN_0018bc10(100.0f, work->listRecords, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 358.0f;
    pair.f[1] = 36.0f;
    FUN_0018bc10(100.0f, &work->listRecords[7], 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 0.0f;
    pair.f[1] = 415.0f;
    FUN_0018bc10(100.0f, &work->listRecords[8], 0, 2, mode,
                 pair.q, pair.q, 0, 0);

    pair.f[0] = 19.0f;
    pair.f[1] = 36.0f;
    FUN_0018bc10(100.0f, work->detailRecords, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 419.0f;
    pair.f[1] = 37.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x44, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 0.0f;
    pair.f[1] = 60.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x88, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 117.0f;
    pair.f[1] = 108.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0xcc, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 486.0f;
    pair.f[1] = 364.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x110, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 182.0f;
    pair.f[1] = 242.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x198, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
    pair.f[0] = 28.0f;
    pair.f[1] = 421.0f;
    FUN_0018bc10(100.0f, (u8*)work->detailRecords + 0x1dc, 0, 2, mode,
                 pair.q, pair.q, 0, 0);
}


static inline s32 campSkillUpdateMainRecords(CampSkillInnerWork* work,
                                      s32 drawRecords)
{
    CampSkillRecord* records;
    s32 complete;
    s32 i;

    records = drawRecords == 0 ? work->listRecords : work->detailRecords;
    if (records == NULL) {
        return 1;
    }
    complete = 1;
    for (i = 0; i < 10; i++) {
        CampSkillRecord* record;

        record = &records[i];
        if (record->enabled != 0) {
            if (FUN_0018b700(record) != 0) {
                if (drawRecords == 0) {
                    FUN_00161d90(record, i, work);
                } else {
                    FUN_00163330(record, i, work);
                }
            }
            if (*(s32*)((u8*)record + 0x18) !=
                *(s32*)((u8*)record + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}


static void campSkillFinishChild(KwlnTask* child)
{
    if (child != NULL) {
        kwlnTaskDestroyWithHierarchy(child);
    }
    if (DAT_007cdf54 != NULL) {
        FUN_00195020(DAT_007cdf54);
        DAT_007cdf54 = NULL;
    }
    if (DAT_007cdf58 != NULL) {
        FUN_00195020(DAT_007cdf58);
        DAT_007cdf58 = NULL;
    }
}

// FUN_001617D0
KwlnTask* FUN_001617d0(KwlnTask* parent, u32 priority)
{
    KwlnTask* task;
    CampSkillOuterWork* work;

    work = (CampSkillOuterWork*)RwCalloc(1, 0x50, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_NewCampSkillDraw", priority,
                          FUN_00160800,
                          h_campSkillDestroySkillDrawTask, work);
    if (task == NULL) {
        return NULL;
    }
    *(HCdvd**)((u8*)work + 0x30) =
        H_Cdvd_Request("camp/camp_skil.pak", HCDVD_FILEARCHIVE);
    return task;
}

// FUN_001618A0 NONMATCHING
void* FUN_001618a0(KwlnTask* task)
{
    CampSkillOuterWork* work;
    s32 command;

    work = (CampSkillOuterWork*)task->workData;
    switch (work->state) {
    case 0:
        campSkillStartPanelPersona(task, work->pcId);
        work->displayMode = 0;
        work->child = FUN_00166a50(task, 0x18be, work->pcId, 0, 0);
        work->scrollX = 320.0f;
        work->scrollY = 0.0f;
        work->state = 1;
        break;
    case 1:
        if (DAT_007cdf88 != NULL && FUN_001685d0(DAT_007cdf88) != 0) {
            work->frame = 0;
            work->scrolling = 1;
            work->state = 2;
        }
        break;
    case 2:
        command = work->displayMode == 0
                      ? FUN_00166c00(work->child)
                      : FUN_00167f30(work->child);
        if (command == -1) {
            if (work->displayMode == 0) {
                FUN_00166c30(work->child);
            } else {
                FUN_00167ef0(work->child);
            }
            if (DAT_007cdf88 != NULL) {
                FUN_001685e0(DAT_007cdf88, 3);
            }
            work->scrolling = 0;
            work->state = 5;
        } else if (command == 1) {
            work->state = 3;
        }
        break;
    case 3:
        if (work->displayMode != 0) {
            FUN_00167f10(work->child);
            work->displayMode = 0;
            work->child = FUN_00166a50(task, 0x18be, work->pcId, 0, 1);
        } else {
            FUN_00166c50(work->child);
            work->displayMode = 1;
            work->child = FUN_00167f40(0, task, 0x18be, 0,
                                       work->pcId, 0, 0);
        }
        work->state = 2;
        break;
    case 5:
        if (work->child != NULL && FUN_00195290(work->child) == 3) {
            return KWLNTASK_STOP;
        }
        break;
    }
    if (work->scrolling != 0) {
        work->frame++;
        if (work->frame > 10) {
            work->frame = 10;
        }
        campSkillScroll(&work->scrollX, &work->scrollY);
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00161D60
void FUN_00161d60(KwlnTask* task)
{
    RwFree(task->workData);
}

static inline void campSkillBuildAnimationPath(char* path, s16 pcId)
{
    if (datGetScenarioMode() != 0) {
        if (pcId == 9) {
            sprintf(path, "camp/AGS_camp_fr%02d.pak", pcId);
        } else if (pcId == 3 || pcId == 1) {
            sprintf(path, "camp/AGS_camp_fr03.pak");
        } else {
            sprintf(path, "camp/camp_fr%02d.pak", pcId);
        }
    } else {
        sprintf(path, "camp/camp_fr%02d.pak", pcId);
    }
}

static inline void campSkillPrepareDetail(CampSkillInnerWork* work,
                                          KwlnTask* parentTask)
{
    s32 i;
    u8* data;
    u8* entry;

    *(u32*)((u8*)parentTask->parent->workData + 0x2c) = 0;
    data = (u8*)RwCalloc(1, 0x2d70, 0x40000);
    for (i = 0; i < 0x140; i++) {
        entry = data + i * 0x24;
        *(s32*)(entry + 0x64) = -1;
        *(s32*)(entry + 0x6c) = 0;
        *(s32*)(entry + 0x68) = -1;
        *(s32*)(entry + 0x70) = 0;
    }
    work->detailData = data;
    FUN_001685e0(DAT_007cdf88, 4);
    for (i = 0; i < 10; i++) {
        CampSkillRecord* record;

        record = &work->listRecords[i];
        if (record->enabled != 0 && FUN_0018b700(record) != 0) {
            FUN_00161d90(record, i, work);
        }
    }
    FUN_0013c240(data, work->pcId, (s16)work->category);
    h_campRequestMenuTransition(DAT_007cdf54, 0);
}

static inline void campSkillSwapEquipment(CampSkillInnerWork* work)
{
    s32 row;
    s32 equipment;
    s32 oldEquipment;
    u16 oldId;
    u32 oldType;
    u8 oldColor;
    u8 oldEffect;
    u16 oldFirst;
    u16 oldSecond;
    u16 oldThird;
    u16 oldFourth;

    row = *(s32*)(work->detailData + 0x2d6c) +
          *(s32*)(work->detailData + 0x2d68);
    if (row == 0) {
        return;
    }
    equipment = *(s32*)(work->detailData + row * 0x24 + 0x68);
    oldEquipment = datGetEquipmentIdx(work->pcId, (s16)work->category);

    oldId = datGetEquipmentId(work->pcId, oldEquipment);
    oldType = func_0016f720(work->pcId, oldEquipment);
    oldColor = func_0016f810(work->pcId, oldEquipment);
    oldEffect = datGetEquipmentEffect(work->pcId, oldEquipment);
    oldFirst = func_0016f9f0(work->pcId, oldEquipment);
    oldSecond = func_0016fae0(work->pcId, oldEquipment);
    oldThird = func_0016fbd0(work->pcId, oldEquipment);
    oldFourth = func_0016fcc0(work->pcId, oldEquipment);

    func_0016fea0(work->pcId, oldEquipment,
                  datGetEquipmentId(1, equipment));
    func_0016ff90(work->pcId, oldEquipment,
                  func_0016f720(1, equipment));
    func_00170080(work->pcId, oldEquipment,
                  func_0016f810(1, equipment));
    func_00170170(work->pcId, oldEquipment,
                  datGetEquipmentEffect(1, equipment));
    func_00170260(work->pcId, oldEquipment,
                  func_0016f9f0(1, equipment));
    func_00170350(work->pcId, oldEquipment,
                  func_0016fae0(1, equipment));
    func_00170440(work->pcId, oldEquipment,
                  func_0016fbd0(1, equipment));
    func_00170530(work->pcId, oldEquipment,
                  func_0016fcc0(1, equipment));

    func_0016fea0(1, equipment, oldId);
    func_0016ff90(1, equipment, oldType);
    func_00170080(1, equipment, oldColor);
    func_00170170(1, equipment, oldEffect);
    func_00170260(1, equipment, oldFirst);
    func_00170350(1, equipment, oldSecond);
    func_00170440(1, equipment, oldThird);
    func_00170530(1, equipment, oldFourth);
    FUN_00177c10(work->pcId, (s16)oldEquipment);
}

#pragma push
#pragma schedule on
#pragma optimization_level 2
// FUN_00164920 NONMATCHING
void* FUN_00164920(KwlnTask* task)
{
    CampSkillInnerWork* work;
    char path[0x100];
    u32 fileSize;
    s32 parserReady;
    s32 complete;
    s32 buttons;
    s32 repeatButtons;

    work = (CampSkillInnerWork*)task->workData;
    switch (work->state) {
    case 0:
        if (H_Cdvd_IsFileLoaded(work->archive) != 0) {
            campSkillBuildAnimationPath(path, work->pcId);
            work->parserState = FUN_0010c1a0(
                NULL, path, 0, 0, 0, 0, 0, 0, 0, 0,
                "camp/skill/anm", 0x40c);
            fileSize = 0;
            work->resource0 = func_00112420(
                H_Cdvd_ArchiveGetFile(work->archive, 0, &fileSize));
            work->resource1 = func_00112420(
                H_Cdvd_ArchiveGetFile(work->archive, 1, &fileSize));
            work->state = 1;
        }
        break;
    case 1:
        parserReady = 1;
        if (work->archiveParser == NULL) {
            work->archiveParser = FUN_0010c3a0(work->parserState,
                                               &fileSize, 0);
            if (fileSize == 0) {
                work->archiveParser = NULL;
                parserReady = 0;
            }
        }
        if (H_Maestro_00111f30((s16*)work->resource0) == 0) {
            parserReady = 0;
        }
        if (H_Maestro_00111f30((s16*)work->resource1) == 0) {
            parserReady = 0;
        }
        if (parserReady != 0) {
            if (DAT_007cdf88 != NULL) {
                FUN_001685e0(DAT_007cdf88, 1);
            }
            work->listRecords = (CampSkillRecord*)FUN_0018b6d0(10);
            work->detailRecords = (CampSkillRecord*)FUN_0018b6d0(10);
            work->state = 2;
        }
        break;
    case 2:
        campSkillOpenMain(work);
        work->state = 3;
        break;
    case 3:
        complete = campSkillUpdateMainRecords(work, 0);
        if (complete != 0) {
            buttons = DAT_007e094e;
            if ((buttons & 0x40) != 0) {
                if (work->commandFlags == 0) {
                    FUN_0010a4e0(0, 0, 0, 1);
                    work->state = 9;
                }
            } else if ((buttons & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                work->command = (u32)-1;
                work->state = 8;
            } else {
                repeatButtons = DAT_007e0952;
                if ((repeatButtons & 0x2000) != 0 ||
                    (DAT_007e095a & 0x2000) != 0) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    work->command = 1;
                    work->state = 8;
                } else if (work->commandFlags == 0 &&
                           ((repeatButtons & 0x1000) != 0 ||
                            (DAT_007e095a & 0x1000) != 0)) {
                    if (work->category == 0) {
                        if ((buttons & 0x1000) != 0 ||
                            (DAT_007e0958 & 0x1000) != 0) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            work->category = 3;
                        }
                    } else {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work->category--;
                    }
                } else if (work->commandFlags == 0 &&
                           ((repeatButtons & 0x4000) != 0 ||
                            (DAT_007e095a & 0x4000) != 0)) {
                    if (work->category == 3) {
                        if ((buttons & 0x4000) != 0 ||
                            (DAT_007e0958 & 0x4000) != 0) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            work->category = 0;
                        }
                    } else {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work->category++;
                    }
                } else if (work->commandFlags != 0) {
                    if ((buttons & 4) != 0) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work->command = 3;
                        work->state = 8;
                    } else if ((buttons & 8) != 0) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work->command = 2;
                        work->state = 8;
                    }
                }
            }
        }
        break;
    case 4:
        if (campSkillUpdateMainRecords(work, 0) != 0) {
            campSkillCloseMain(work);
            work->state = 5;
        }
        break;
    case 5:
        if (campSkillUpdateMainRecords(work, 0) != 0) {
            return KWLNTASK_STOP;
        }
        break;
    case 6:
        if (campSkillUpdateMainRecords(work, 0) != 0) {
            campSkillReturnMain(work);
            work->state = 7;
        }
        break;
    case 7:
        if (campSkillUpdateMainRecords(work, 0) != 0) {
            return KWLNTASK_STOP;
        }
        break;
    case 8:
        campSkillUpdateMainRecords(work, 0);
        break;
    case 9:
        campSkillPrepareDetail(work, task);
        campSkillOpenDetail(work);
        work->state = 10;
        break;
    case 10:
        complete = campSkillUpdateMainRecords(work, 0);
        if (complete != 0) {
            work->state = 11;
        }
        campSkillUpdateMainRecords(work, 1);
        break;
    case 11:
        complete = campSkillUpdateMainRecords(work, 1);
        if (complete != 0) {
            buttons = DAT_007e094e;
            if ((buttons & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                work->state = 12;
            } else if ((buttons & 0x40) != 0) {
                FUN_0010a4e0(0, 0, 0, 7);
                campSkillSwapEquipment(work);
                work->state = 12;
            } else if ((buttons & 0x1000) != 0 ||
                       (buttons & 0x4000) != 0 ||
                       (DAT_007e095a & 0x1000) != 0 ||
                       (DAT_007e095a & 0x4000) != 0) {
                if (work->detailData != NULL) {
                    h_campUpdatePagedCursor(
                        *(u32*)(work->detailData + 0x2d64), 5,
                        (s32*)(work->detailData + 0x2d6c),
                        (s32*)(work->detailData + 0x2d68));
                }
            }
        }
        break;
    case 12:
        if (DAT_007cdf54 != NULL) {
            h_campRequestMenuTransition(DAT_007cdf54, 2);
        }
        if (DAT_007cdf88 != NULL) {
            FUN_001685e0(DAT_007cdf88, 1);
        }
        campSkillUpdateMainRecords(work, 1);
        campSkillAnimateDetail(work, 1);
        work->state = 13;
        break;
    case 13:
        complete = campSkillUpdateMainRecords(work, 1);
        if (complete != 0) {
            *(u32*)((u8*)task->parent->workData + 0x2c) = 1;
            if (work->detailData != NULL) {
                RwFree(work->detailData);
                work->detailData = NULL;
            }
            work->state = 3;
        }
        campSkillUpdateMainRecords(work, 0);
        break;
    }
    return KWLNTASK_CONTINUE;
}
#pragma schedule off
#pragma pop

// FUN_001669B0
void FUN_001669b0(KwlnTask* task)
{
    CampSkillInnerWork* work;
    void (**freeMemory)(void*);

    work = (CampSkillInnerWork*)task->workData;
    FUN_004d0f00(work->archiveParser);
    func_001124b0(work->resource0);
    func_001124b0(work->resource1);
    H_Cdvd_Destroy(work->archive);
    freeMemory = (void (**)(void*))jtbl_0096017C_abs;
    (*freeMemory)(work->listRecords);
    (*freeMemory)(work->detailRecords);
    (*freeMemory)(work);
}

// FUN_00166A50
KwlnTask* FUN_00166a50(KwlnTask* parent, u32 priority, s16 pcId,
                       u32 mode, u32 displayMode)
{
    KwlnTask* task;
    CampSkillInnerWork* work;
    s32 signedPcId;
    char path[0x100];

    work = (CampSkillInnerWork*)RwCalloc(1, 0x38, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampSkillDraw", priority,
                          FUN_00164920, FUN_001669b0, work);
    if (task == NULL) {
        return NULL;
    }
    work->commandFlags = mode;
    signedPcId = (s32)pcId;
    *(u32*)((u8*)work + 8) = (u32)signedPcId;
    if (FUN_0017d800() != 0) {
        switch (signedPcId) {
        case 1:
        case 3:
            FUN_00523ac8(path, "camp/AGS_camp_fr03.pak");
            break;
        case 9:
            FUN_00523ac8(path, "camp/AGS_camp_fr%02d.pak", signedPcId);
            break;
        default:
            FUN_00523ac8(path, "camp/camp_fr%02d.pak", signedPcId);
            break;
        }
    } else {
        FUN_00523ac8(path, "camp/camp_fr%02d.pak", signedPcId);
    }
    work->archive = H_Cdvd_Request(path, HCDVD_FILEARCHIVE);
    work->displayMode = displayMode;
    return task;
}

// FUN_00166C00
s32 FUN_00166c00(KwlnTask* task)
{
    CampSkillInnerWork* work;

    work = (CampSkillInnerWork*)task->workData;
    if (work->state == 8) {
        return (s32)work->command;
    }
    return 0;
}

// FUN_00166C30
void FUN_00166c30(KwlnTask* task)
{
    ((CampSkillInnerWork*)task->workData)->state = 4;
}

// FUN_00166C50
void FUN_00166c50(KwlnTask* task)
{
    ((CampSkillInnerWork*)task->workData)->state = 6;
}

static s16 campSkillSelectorCurrentId(CampSkillSelectorWork* work)
{
    if (work->pcId != 0) {
        return work->pcId;
    }
    return work->pcId;
}

static void campSkillSelectorStartChild(KwlnTask* parent,
                                        CampSkillSelectorWork* work,
                                        u32 displayMode)
{
    s16 pcId;
    s16 selectedId;

    pcId = campSkillSelectorCurrentId(work);
    if (work->count == 0) {
        return;
    }
    selectedId = work->characterIds[work->selected];
    campSkillStartPanelPersona(parent, selectedId);
    work->child = FUN_00166a50(parent, 0x18be, selectedId, 1,
                                displayMode);
    work->displayMode = displayMode;
}

static s32 campSkillSelectorCommand(CampSkillSelectorWork* work)
{
    if (work->child == NULL) {
        return 0;
    }
    if (work->displayMode == 0) {
        return FUN_00166c00(work->child);
    }
    return FUN_00167f30(work->child);
}

// FUN_00166C70 NONMATCHING
void* FUN_00166c70(KwlnTask* task)
{
    CampSkillSelectorWork* work;
    s32 command;
    s32 i;
    s16 selectedId;

    work = (CampSkillSelectorWork*)task->workData;
    switch (work->state) {
    case 0:
        work->scrollX = 320.0f;
        work->scrollY = 0.0f;
        work->count = 0;
        work->selected = 0;
        if (datGetFlag(0x142) != 0) {
            work->characterIds[work->count++] = 2;
        }
        if (datGetFlag(0x143) != 0) {
            work->characterIds[work->count++] = 3;
        }
        if (datGetFlag(0x144) != 0) {
            work->characterIds[work->count++] = 4;
        }
        if (datGetFlag(0x145) != 0) {
            work->characterIds[work->count++] = 5;
        }
        if (datGetFlag(0x146) != 0) {
            work->characterIds[work->count++] = 7;
        }
        if (datGetFlag(0x147) != 0) {
            work->characterIds[work->count++] = 8;
        }
        if (datGetFlag(0x148) != 0) {
            work->characterIds[work->count++] = 9;
        }
        if (datGetFlag(0x149) != 0) {
            work->characterIds[work->count++] = 10;
        }
        if (datGetFlag(0x14a) != 0) {
            work->characterIds[work->count++] = 6;
        }
        if (work->count > 0) {
            selectedId = work->characterIds[0];
            campSkillStartPanelPersona(task, selectedId);
            work->child = FUN_00166a50(task, 0x18be, selectedId, 1, 0);
        }
        work->state = 1;
        break;
    case 1:
        if (DAT_007cdf88 != NULL && FUN_001685d0(DAT_007cdf88) != 0) {
            work->transition = 1;
            work->state = 2;
        }
        break;
    case 2:
        command = campSkillSelectorCommand(work);
        if (command == -1) {
            if (work->displayMode != 0) {
                FUN_00167ef0(work->child);
            } else {
                FUN_00166c30(work->child);
            }
            if (DAT_007cdf88 != NULL) {
                FUN_001685e0(DAT_007cdf88, 3);
            }
            work->transition = 0;
            work->state = 5;
        } else if (command == 1) {
            work->state = 3;
        } else if (command == 2 || command == 3) {
            if (work->displayMode != 0) {
                FUN_00167ef0(work->child);
            } else {
                FUN_00166c50(work->child);
            }
            if (command == 2) {
                work->selected++;
                if (work->selected >= work->count) {
                    work->selected = 0;
                }
            } else {
                work->selected--;
                if (work->selected < 0) {
                    work->selected = work->count - 1;
                }
            }
            work->state = 6;
        }
        break;
    case 3:
        selectedId = work->characterIds[work->selected];
        if (work->displayMode != 0) {
            FUN_00167f10(work->child);
            work->displayMode = 0;
            work->child = FUN_00166a50(task, 0x18be, selectedId, 1, 1);
        } else {
            FUN_00166c50(work->child);
            work->displayMode = 1;
            work->child = FUN_00167f40(0, task, 0x18be, 0, selectedId,
                                       0, 0);
        }
        work->state = 2;
        break;
    case 5:
        if (work->child != NULL && FUN_00195290(work->child) == 3) {
            return KWLNTASK_STOP;
        }
        break;
    case 6:
        if (work->child != NULL && FUN_00195290(work->child) == 3) {
            campSkillStartPanelPersona(task,
                                       work->characterIds[work->selected]);
            work->child = FUN_00166a50(
                task, 0x18be, work->characterIds[work->selected], 1, 1);
            work->displayMode = 1;
            work->transition = 1;
            work->state = 2;
        }
        break;
    }
    if (work->transition != 0) {
        for (i = 0; i < 1; i++) {
            campSkillScroll(&work->scrollX, &work->scrollY);
        }
    }
    return KWLNTASK_CONTINUE;
}
