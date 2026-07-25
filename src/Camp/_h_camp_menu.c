#include "Utils.h"
#include "Main/Game/game_support.h"

/*
 * Camp's menu renderer stores one draw record per sprite.  The records are
 * allocated by the screen-specific tasks, so this file deliberately keeps the
 * unknown prefix opaque while documenting the fields used by these callbacks.
 */
typedef struct CampMenuDrawItem
{
    u8 reserved00[0x24];
    union
    {
        u32 texture;
        f32 scale;
    };
    u8 reserved28[0xc];
    f32 progress;
    f32 x;
    f32 y;
    u32 alpha;
} CampMenuDrawItem;

extern void* FUN_001120a0();
extern s32 FUN_001158b0();
extern s32 FUN_00115980();
extern s32 FUN_001159f0();
#pragma alias campMenuDrawSprite FUN_001159f0
extern void campMenuDrawSprite(u32 parent, const void* resource, s32 frame,
                               u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campMenuDrawSpriteAlt FUN_00115bc0
extern void campMenuDrawSpriteAlt(u32 parent, const void* resource, s32 frame,
                                  u32 alpha, s32 red, s32 green, s32 blue,
                                  f32 x, f32 y, f32 scale);
extern f32 fGpffff80c4;
extern void* DAT_00833B70;
extern s32 FUN_00115ad0();
#pragma alias campMenuDrawSpriteDigits FUN_00115ad0
extern void campMenuDrawSpriteDigits(u32 parent, const void* resource, s32 frame,
                                     u32 alpha, u32 extraAlpha,
                                     f32 x, f32 y, f32 scale);
extern void FUN_001140d0(f32 depth, f32 x, f32 y, u32 color, s32 width,
                         s32 height, const void* textureState);
extern s32 FUN_001127d0();
extern void* FUN_0016f190();
extern void* FUN_0017c670();
extern s32 FUN_0017d800();
extern s32 FUN_0017c6c0();
extern s32 FUN_0017c6e0();
extern u32 FUN_0017d8b0();
extern s32 FUN_0017dae0();
extern s32 FUN_0017da40();
extern s32 FUN_0017db40();
extern s32 FUN_0017ae30();
extern s32 FUN_0012df50(u32 mask);
extern s32 FUN_00170ed0();
extern s32 FUN_00171110();
extern s32 FUN_00171250();
extern s32 FUN_00173220();
extern s32 FUN_0030c220();
/* Typed ABI aliases keep the scale in f12 instead of treating it as a ninth integer argument. */
#pragma alias FUN_003b2cb0_typed FUN_003b2cb0
extern s32 FUN_003b2cb0_typed(f32 scale, s32 x, s32 y, s32 color,
                              s32 font, s32 alignment, const char* text,
                              s32 maxWidth, s32 shadow);
#pragma alias FUN_0040eb50_typed FUN_0040eb50
extern s32 FUN_0040eb50_typed(f32 scale, s32 x, s32 y, u8 color, s16 font,
                              const char* text, s32 maxWidth);
extern s32 FUN_003b2cb0();
extern s32 FUN_003b32d0();
extern s32 FUN_003c3fe0();
extern s32 FUN_003c7e20();
extern s32 FUN_00403380();
extern s32 FUN_00403740();
extern s32 FUN_00403800();
extern s32 FUN_00403830();
extern void* FUN_00403880();
extern s32 FUN_00403900();
extern s32 FUN_0040eb50();
extern s32 FUN_00523ac8();
extern short DAT_005e3b5e[];
extern u32 DAT_007ce4ec;
extern char gp0xffff8988[];
extern char gp0xffff8990[];
extern s16 iGpffffb2c8[];
extern char gp0xffff897c[];
extern u32 DAT_0083aaa0[];
extern void* DAT_00833BA0;
extern u32 uGpffff8884;

static inline f32 campDrawX(const CampMenuDrawItem* item)
{
    return item->x;
}

static inline f32 campDrawY(const CampMenuDrawItem* item)
{
    return item->y;
}

static inline u32 campDrawAlpha(const CampMenuDrawItem* item)
{
    return (0xffU - item->alpha) | 0xffffff00U;
}
static inline u32 campDrawAlpha8(const CampMenuDrawItem* item)
{
    return *(const u8*)((const u8*)item + 0x40);
}

static inline void campSprite(const CampMenuDrawItem* item, f32 x, f32 y)
{
    campMenuDrawSprite(0, NULL, 0, item->alpha, x, y, item->scale);
}

static inline void campSpriteAlt(const CampMenuDrawItem* item, f32 x, f32 y)
{
    campMenuDrawSpriteAlt(0, NULL, 0, item->alpha, 0x20, 0x43, 0x78,
                          x, y, item->scale);
}

static inline void campText(const CampMenuDrawItem* item, f32 x, f32 y,
                            const char* text, s32 font, s32 width)
{
    FUN_003b32d0(item->scale, (s32)x, (s32)y, campDrawAlpha(item), font, 1,
                 text, 0x10, width);
}

static inline void campDrawPanel(const CampMenuDrawItem* item)
{
    campSprite(item, campDrawX(item), campDrawY(item));
}

static inline void campDrawRows(const CampMenuDrawItem* item, s32 count, f32 spacing)
{
    s32 i;
    for (i = 0; i < count; i++) {
        campSprite(item, campDrawX(item), campDrawY(item) + (f32)i * spacing);
    }
}

/* The first callback is a small jump-table dispatcher in retail.  Keeping the
 * cases explicit makes the mode contract visible while preserving the same
 * draw helpers used by the screen callbacks below. */
// FUN_00154970 NONMATCHING
void FUN_00154970(register CampMenuDrawItem* item,
                  register const char** labels, s32 mode, s32 first,
                  s32 count)
{
    s32 i;
    u32 color;
    register u32 parent;

    switch (mode) {
    case 0:
        color = (0xffU - item->alpha) | 0xffffff00U;
        FUN_001140d0(item->scale, item->x - 50.0f, item->y, color,
                     0x1cc, 0x399, (const void*)(uintptr_t)first);
        FUN_001140d0(item->scale, item->x - 50.0f,
                     item->y + 1000.0f, color, 0x1cc, 0x399,
                     (const void*)(uintptr_t)first);
        item->progress -= 1.0f;
        if (item->progress < -1000.0f) {
            item->progress += 1000.0f;
        }
        break;

    case 2:
        campMenuDrawSprite(parent, *labels, 0xd, campDrawAlpha8(item),
                           item->x, item->y, item->scale);
        break;

    case 1:
        for (i = 0; i < 6; i++) {
            campMenuDrawSprite(parent, *labels, 0xe,
                               campDrawAlpha8(item), item->x,
                               item->y + (f32)(i * 0x11), item->scale);
        }
        break;

    case 3:
        if (FUN_0017d800() != 0) {
            for (i = 0; i < 6; i++) {
                if (i == count) {
                    campMenuDrawSprite(parent, *labels, i,
                                       campDrawAlpha8(item), item->x,
                                       item->y + (f32)(i * 0x11),
                                       item->scale);
                } else if (i < 4) {
                    campMenuDrawSpriteDigits(parent, *labels, i + 6,
                                             0x80, campDrawAlpha8(item),
                                             item->x,
                                             item->y + (f32)(i * 0x11),
                                             item->scale);
                } else {
                    campMenuDrawSprite(parent, *labels, i,
                                       campDrawAlpha8(item), item->x,
                                       item->y + (f32)(i * 0x11),
                                       item->scale);
                }
            }
        } else {
            for (i = 0; i < 6; i++) {
                campMenuDrawSprite(parent, *labels, i,
                                   campDrawAlpha8(item), item->x,
                                   item->y + (f32)(i * 0x11),
                                   item->scale);
            }
        }
        break;

    case 4:
        {
            u8* work = (u8*)(uintptr_t)FUN_001158b0(0, *labels, 0x19);
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = item->x;
            *(f32*)(work + 0x14) = item->y + 200.0f;
            *(u8*)(work + 0x18) = campDrawAlpha8(item);
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0((u32)(uintptr_t)work, 1);
            FUN_00115980((u32)(uintptr_t)work);
        }
        break;

    case 5:
        {
            u8* work = (u8*)(uintptr_t)FUN_001158b0(0, *labels, 0xf);
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = item->x;
            *(f32*)(work + 0x14) = item->y + 200.0f;
            *(u8*)(work + 0x18) = campDrawAlpha8(item);
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0((u32)(uintptr_t)work, 1);
            FUN_00115980((u32)(uintptr_t)work);
        }
        break;

    case 6:
        campMenuDrawSprite(parent, labels[1], count + 2,
                           campDrawAlpha8(item), item->x, item->y,
                           item->scale);
        break;

    case 7:
        campMenuDrawSprite(parent, labels[1], 0,
                           campDrawAlpha8(item), item->x, item->y,
                           item->scale);
        campMenuDrawSprite(parent, labels[1], 0,
                           campDrawAlpha8(item),
                           (item->x + 408.0f) - 392.0f,
                           (item->y + (f32)0x181) - (f32)0x181,
                           item->scale);
        campMenuDrawSprite(parent, labels[1], 0,
                           campDrawAlpha8(item), item->x + 102.0f,
                           (item->y + (f32)0x19f) - (f32)0x181,
                           item->scale);
        campMenuDrawSprite(parent, DAT_00833BA0, 1,
                           campDrawAlpha8(item),
                           (item->x + (f32)0x231) - 392.0f,
                           (item->y + (f32)0x19f) - (f32)0x181,
                           item->scale);
        break;

    default:
        break;
    }
}

// FUN_00154F70
u32 FUN_00154F70(CampMenuDrawItem* items, const char** labels, s32 count,
                 s32 first)
{
    s32 i;
    u32 complete = 1;

    for (i = 0; i < 10; i++) {
        CampMenuDrawItem* item = (CampMenuDrawItem*)((u8*)items + i * 0x44);
        if (*(u32*)((u8*)item + 4) != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00154970(item, labels, i, count, first);
            }
            if (*(u32*)((int)items + i * 0x44 + 0x18) !=
                *(u32*)((int)items + i * 0x44 + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}

#pragma opt_loop_invariants on
// FUN_00155070 NONMATCHING
void FUN_00155070(CampMenuDrawItem* item, const char** labels, s32 mode, s32 first,
                  s32 count, s32 page, s32 selected)
{
    s32 i;
    u32 alpha = campDrawAlpha(item);

    switch (mode) {
    case 99:
        campSprite(item, campDrawX(item), campDrawY(item));
        campSprite(item, campDrawX(item) + 16.0f, campDrawY(item));
        campSprite(item, campDrawX(item) + 530.0f, campDrawY(item) + 30.0f);
        break;
    case 6:
        campSprite(item, campDrawX(item), campDrawY(item));
        campSprite(item, campDrawX(item), campDrawY(item) + 4.0f +
                   (count > 8 ? (f32)((page << 6) / (count - 8)) : 0.0f));
        break;
    case 5:
        for (i = 0; i < 8 && page + i < count; i++) {
            campText(item, campDrawX(item), campDrawY(item) + (f32)(i * 0x23 + 3),
                     labels[page + i], i == selected ? 6 : 10, 0x78);
        }
        break;
    case 4:
        campDrawRows(item, 8, 0x23);
        campSprite(item, campDrawX(item), campDrawY(item) + (f32)(selected * 0x23));
        break;
    case 3:
        {
            u32 id = (u32)FUN_001158b0(0, *labels, 0x11);
            u8* work = (u8*)id;
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = campDrawX(item);
            *(f32*)(work + 0x14) = campDrawY(item);
            work[0x18] = (u8)item->alpha;
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0(id, 1);
            FUN_00115980(id);
        }
        break;
    case 2:
        if (page + selected < count) {
            for (i = 0; i < 6; i++) {
                campText(item, campDrawX(item), campDrawY(item) + (f32)(i * 0x18),
                         labels[page + selected], 10, 0x78);
            }
        }
        break;
    case 1:
        campSprite(item, campDrawX(item) + 236.0f, campDrawY(item) - 9.0f);
        if (page + selected < count) {
            campText(item, campDrawX(item), campDrawY(item) + 2.0f,
                     labels[page + selected], 6, 0x76);
        }
        break;
    case 0:
        campDrawPanel(item);
        break;
    default:
        break;
    }
    (void)alpha;
    (void)first;
}
#pragma opt_loop_invariants off

// FUN_00155710
u32 FUN_00155710(CampMenuDrawItem* items, const char** labels, s32 count, s32 first,
                 s32 page, s32 selected)
{
    s32 i;
    u32 complete = 1;

    for (i = 0; i < 100; i++) {
        CampMenuDrawItem* item = (CampMenuDrawItem*)((u8*)items + i * 0x44);
        if (*(u32*)((u8*)item + 4) != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00155070(item, labels, i, count, first, page, selected);
            }
            if (*(u32*)((int)items + i * 0x44 + 0x18) !=
                *(u32*)((int)items + i * 0x44 + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}

// FUN_00155830 NONMATCHING
void FUN_00155830(CampMenuDrawItem* item, const char** labels, s32 mode, s32 selected,
                  const s32* enabled)
{
    s32 i;
    s32 row;

    if (mode == 99) {
        campMenuDrawSprite(0, labels[1], 0, item->alpha,
                           item->x, item->y, item->scale);
        campMenuDrawSprite(0, labels[1], 0x0d, item->alpha,
                           item->x + 16.0f, item->y, item->scale);
        campMenuDrawSprite(0, labels[1], selected + 0x0f, item->alpha,
                           item->x - 204.0f, item->y, item->scale);
        campMenuDrawSprite(0, labels[1], 0, item->alpha,
                           item->x + 102.0f, item->y + 30.0f,
                           item->scale);
        campMenuDrawSprite(0, labels[1], 1, item->alpha,
                           item->x + 169.0f, item->y + 30.0f,
                           item->scale);
        return;
    }
    if (mode == 6) {
        for (i = 0; i < 8; i++) {
            row = i * 0x21;
            if (i == selected) {
                if (i == 5) {
                    campMenuDrawSprite(0, *labels, 0x95, item->alpha,
                                       item->x, item->y + (f32)row,
                                       item->scale);
                    campMenuDrawSprite(0, *labels, 0x96, item->alpha,
                                       item->x + 135.0f,
                                       item->y + (f32)(i * 0x21),
                                       item->scale);
                } else {
                    campMenuDrawSprite(0, *labels,
                                       i < 6 ? i + 0x91 : i + 0x90,
                                       item->alpha, item->x,
                                       item->y + (f32)(i * 0x21),
                                       item->scale);
                }
            } else if (i == 5) {
                campMenuDrawSprite(0, *labels, 0x8c, item->alpha,
                                   item->x, item->y + (f32)(i * 0x21),
                                   item->scale);
                campMenuDrawSprite(0, *labels, 0x8d, item->alpha,
                                   item->x + 135.0f,
                                   item->y + (f32)(i * 0x21),
                                   item->scale);
            } else {
                campMenuDrawSprite(0, *labels,
                                   i < 6 ? i + 0x88 : i + 0x87,
                                   item->alpha, item->x,
                                   item->y + (f32)(i * 0x21),
                                   item->scale);
            }
        }
        return;
    }
    if (mode == 5) {
        for (i = 0; i < 7; i++) {
            if (i == 2 && enabled[1] == 0) {
                continue;
            }
            if (enabled[i] != 0) {
                campMenuDrawSprite(0, *labels, 0x9c, item->alpha,
                                   item->x, item->y + (f32)(i * 0x21),
                                   item->scale);
            } else {
                campMenuDrawSprite(0, *labels, 0x9d, item->alpha,
                                   item->x + 44.0f,
                                   item->y + (f32)(i * 0x21),
                                   item->scale);
            }
        }
        if (selected == 7) {
            campMenuDrawSprite(0, *labels, 0xa5, item->alpha,
                               item->x, item->y + 231.0f, item->scale);
        } else {
            campMenuDrawSprite(0, *labels, 0xa6, item->alpha,
                               item->x, item->y + 231.0f, item->scale);
        }
        return;
    }
    if (mode == 4) {
        for (i = 0; i < 7; i++) {
            campMenuDrawSprite(0, *labels,
                               i == 2 && enabled[1] == 0 ? 0x9b : 0x9a,
                               item->alpha, item->x,
                               item->y + (f32)(i * 0x21), item->scale);
        }
        return;
    }
    if (mode == 3) {
        campMenuDrawSprite(0, *labels, 0x99, item->alpha,
                           item->x, item->y + (f32)(selected * 0x21),
                           item->scale);
        return;
    }
    if (mode == 2) {
        for (i = 0; i < 8; i++) {
            campMenuDrawSprite(0, *labels, 0x0e, item->alpha,
                               item->x, item->y + (f32)(i * 0x21),
                               item->scale);
            campMenuDrawSprite(0, *labels, 0x0e, item->alpha,
                               item->x + 292.0f,
                               item->y + (f32)(i * 0x21), item->scale);
        }
        return;
    }
    if (mode == 1 || mode == 0) {
        u32 id = (u32)FUN_001158b0(0, *labels,
                                    mode == 1 ? 0x14 : 0x1e);
        u8* work = (u8*)id;
        *(u32*)(work + 0x2c) = item->texture;
        *(f32*)(work + 0x10) = item->x;
        *(f32*)(work + 0x14) = item->y;
        work[0x18] = (u8)item->alpha;
        *(f32*)(work + 0x20) = -90.0f;
        FUN_001127d0(id, 1);
        FUN_00115980(id);
    }
}

// FUN_00156140
u32 FUN_00156140(CampMenuDrawItem* items, const char** labels, s32 count,
                 const s32* enabled)
{
    s32 i;
    u32 complete = 1;

    for (i = 0; i < 100; i++) {
        CampMenuDrawItem* item = (CampMenuDrawItem*)((u8*)items + i * 0x44);
        if (*(u32*)((u8*)item + 4) != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00155830(item, labels, i, count, enabled);
            }
            if (*(u32*)((int)items + i * 0x44 + 0x18) !=
                *(u32*)((int)items + i * 0x44 + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}

static inline void campDrawPersonaName(CampMenuDrawItem* item, s32 personaId, s32 selected)
{
    u8 text[0x100];
    void* record = FUN_0016f190(personaId + 0x13d0);
    if (record == NULL) {
        campSprite(item, campDrawX(item) + 99.0f,
                   campDrawY(item) + 15.0f + (f32)(selected * 0x23));
        return;
    }
    FUN_00523ac8(text, 0x7cb66c, DAT_007ce4ec +
                 (personaId + 0x110) * 0x13);
    campText(item, campDrawX(item) + 35.0f,
             campDrawY(item) + 14.0f + (f32)(selected * 0x23),
             (const char*)text, 10, 0);
}

// FUN_00156240 NONMATCHING
void FUN_00156240(CampMenuDrawItem* item, const char** labels, s32 mode, s32 personaBase,
                  s32 selected)
{
    s32 i;

    switch (mode) {
    case 99:
        campSprite(item, campDrawX(item), campDrawY(item));
        campSprite(item, campDrawX(item) + 16.0f, campDrawY(item));
        campSprite(item, campDrawX(item) + 530.0f, campDrawY(item) + 30.0f);
        break;
    case 6:
        for (i = 0; i < 8; i++) {
            campDrawPersonaName(item, personaBase + i, i == selected ? 1 : 0);
        }
        break;
    case 5:
        campSprite(item, campDrawX(item), campDrawY(item) + (f32)(selected * 0x23));
        break;
    case 4:
        campDrawRows(item, 8, 0x23);
        campSprite(item, campDrawX(item) + 271.0f, campDrawY(item) + 175.0f);
        campSprite(item, campDrawX(item) + 271.0f,
                   campDrawY(item) + 179.0f + (f32)((personaBase << 6) / 10));
        break;
    case 3:
        {
            u32 id = (u32)FUN_001158b0(0, *labels, 0x12);
            u8* work = (u8*)id;
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = campDrawX(item);
            *(f32*)(work + 0x14) = campDrawY(item);
            work[0x18] = (u8)item->alpha;
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0(id, 1);
            FUN_00115980(id);
            id = (u32)FUN_001158b0(0, *labels, 0xa8);
            work = (u8*)id;
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = campDrawX(item);
            *(f32*)(work + 0x14) = campDrawY(item) - 235.0f;
            work[0x18] = (u8)item->alpha;
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0(id, 1);
            FUN_00115980(id);
        }
        break;
    case 2:
        if (FUN_0016f190(personaBase + selected + 0x13d0) != NULL) {
            FUN_003c7e20(item->texture, (s32)campDrawX(item), (s32)campDrawY(item),
                         campDrawAlpha(item), 1, 10, 8, personaBase + selected);
        }
        break;
    case 1:
        campDrawRows(item, 2, 0x1d);
        campSprite(item, campDrawX(item) + 239.0f, campDrawY(item));
        if (FUN_0016f190(personaBase + 0x13d0) == NULL) {
            campSprite(item, campDrawX(item) + 94.0f, campDrawY(item) + 40.0f);
        }
        break;
    case 0:
        campDrawPanel(item);
        break;
    default:
        break;
    }
}

// FUN_00156E80
u32 FUN_00156E80(CampMenuDrawItem* items, const char** labels, s32 count,
                 s32 personaBase)
{
    s32 i;
    u32 complete = 1;

    for (i = 0; i < 100; i++) {
        CampMenuDrawItem* item = (CampMenuDrawItem*)((u8*)items + i * 0x44);
        if (*(u32*)((u8*)item + 4) != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00156240(item, labels, i, count, personaBase);
            }
            if (*(u32*)((int)items + i * 0x44 + 0x18) !=
                *(u32*)((int)items + i * 0x44 + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}

static void campDrawSkillDigits(CampMenuDrawItem* item, s32 value, s32 row,
                                s32 selected)
{
    s32 hundreds = value / 100;
    s32 tens = (value / 10) % 10;
    s32 ones = value % 10;
    f32 x = campDrawX(item) + 40.0f;
    f32 y = campDrawY(item) + (f32)(row * 0x23);

    FUN_001120a0(selected ? 1 : 2);
    campSpriteAlt(item, x, y);
    if (hundreds != 0) {
        FUN_001120a0(selected ? 1 : 2);
        campSpriteAlt(item, x + 16.0f, y);
    }
    if (tens != 0 || hundreds != 0) {
        FUN_001120a0(selected ? 1 : 2);
        campSpriteAlt(item, x + 32.0f, y);
    }
    (void)ones;
}

static void campDrawItemStatus(CampMenuDrawItem* item, s32 itemId)
{
    u8 text[0x110];
    void* record = FUN_0017c670(itemId);
    f32 x = campDrawX(item);
    f32 y = campDrawY(item);
    s32 i;

    if (record == NULL) {
        campDrawRows(item, 5, 0x17);
        return;
    }

    /*
     * The item table uses the byte at +6 to distinguish consumables,
     * equipment, and key items.  The three paths have different name/icon
     * sources, but all share the five-star rating strip below.
     */
    {
        u16 dataId = *(u16*)record;
        u8 category = *((u8*)record + 6);
        s32 width;
        if (category == 3) {
            FUN_00523ac8(text, 0x7cb674, *(u32*)((u8*)record + 8));
            width = FUN_0040eb50(item->texture, (s32)x, (s32)(y + 13.0f),
                                 campDrawAlpha(item), 3, text, 8);
            campSprite(item, x + (f32)width + 3.0f, y);
        } else if (category == 0) {
            if (FUN_00171250(dataId) == 4) {
                campSprite(item, x, y);
                FUN_00523ac8(text, 0x7cb66c,
                             FUN_00171110(dataId, *((s8*)record + 10)));
                width = FUN_003b2cb0(item->texture, (s32)(x + 35.0f),
                                     (s32)(y + 11.0f), campDrawAlpha(item),
                                     6, 1, text, 0x11, 0);
                campSprite(item, x + 35.0f + (f32)width + 6.0f, y + 7.0f);
                if (*((u8*)record + 7) >= 10) {
                    FUN_001120a0(1);
                    campSprite(item, x + 35.0f + (f32)width + 31.0f, y + 12.0f);
                }
            } else {
                s32 valueKind;
                u32 value = 0;
                u32* values = (u32*)FUN_00170ed0(dataId, &valueKind);
                if (values != NULL) {
                    if (valueKind == 3) {
                        value = values[0];
                    } else {
                        value = values[1];
                    }
                }
                FUN_0012df50(value);
                campSprite(item, x, y);
                FUN_00523ac8(text, 0x7cb66c,
                             FUN_00171110(dataId, *((s8*)record + 10)));
                width = FUN_003b2cb0(item->texture, (s32)(x + 35.0f),
                                     (s32)(y + 11.0f), campDrawAlpha(item),
                                     6, 1, text, 0x11, 0);
                campSprite(item, x + 35.0f + (f32)width + 6.0f, y + 7.0f);
                if (*((u8*)record + 7) >= 10) {
                    FUN_001120a0(1);
                    campSprite(item, x + 35.0f + (f32)width + 31.0f, y + 12.0f);
                }
            }
        }

        for (i = 0; i < 5; i++) {
            if (FUN_00403900(dataId) < i + 1) {
                campSprite(item, x + 380.0f + (f32)(i * 0x17), y + 7.0f);
            } else {
                campSprite(item, x + 380.0f + (f32)(i * 0x17), y + 7.0f);
            }
        }
    }
}

// FUN_00156F80 NONMATCHING
void FUN_00156F80(CampMenuDrawItem* item, const char** labels, s32 mode, s32 selected)
{
    register u32 parent;
    s32 i;
    s32 width;
    s32 valueKind;
    s32 value;
    s32 frame;
    s32 valueA;
    s32 valueB;
    s32 valueC;
    s32 valueU;
    u16 dataId;
    u8 category;
    u32 alpha;
    u32* values;
    void* record;
    void* itemRecord;
    f32 fade;
    u32 fadeAlpha;
    u8 text[0x110];
    switch (mode) {
    case 0:
        parent = (u32)FUN_001158b0(0, *labels, 0x13);
        {
            u8* work = (u8*)parent;
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = item->x;
            *(f32*)(work + 0x14) = item->y;
            work[0x18] = (u8)item->alpha;
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0(parent, 1);
            FUN_00115980(parent);
        }
        break;
    case 1:
        parent = (u32)FUN_001158b0(0, *labels, 0x1b);
        {
            u8* work = (u8*)parent;
            *(u32*)(work + 0x2c) = item->texture;
            *(f32*)(work + 0x10) = item->x;
            *(f32*)(work + 0x14) = item->y;
            work[0x18] = (u8)item->alpha;
            *(f32*)(work + 0x20) = -90.0f;
            FUN_001127d0(parent, 1);
            FUN_00115980(parent);
        }
        break;
    case 2:
        campMenuDrawSprite(parent, *labels, 0x31, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 3:
        campMenuDrawSprite(parent, *labels, 0x2e, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 4:
        campMenuDrawSprite(parent, *labels, 0x2f, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 5:
        campMenuDrawSprite(parent, *labels, 0x30, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 6:
        for (i = 0; i < 3; i++) {
            campMenuDrawSprite(parent, *labels, 0x36, item->alpha,
                               item->x, item->y + (f32)(i * 0x23),
                               item->scale);
            campMenuDrawSprite(parent, *labels, 0x37, item->alpha,
                               107.0f + item->x - 50.0f,
                               item->y + (f32)(i * 0x23), item->scale);
            campMenuDrawSprite(parent, *labels, 0x37, item->alpha,
                               item->x + 483.0f,
                               item->y + (f32)(i * 0x23), item->scale);
            campMenuDrawSprite(parent, *labels, 0x0e, item->alpha,
                               item->x + 570.0f,
                               item->y + (f32)(i * 0x23) + 1.0f,
                               item->scale);
        }
        break;
    case 7:
        campMenuDrawSprite(parent, *labels, 0x25, item->alpha,
                           item->x, item->y + (f32)(selected * 0x23),
                           item->scale);
        campMenuDrawSprite(parent, *labels, 0x26, item->alpha,
                           107.0f + item->x - 50.0f,
                           item->y + (f32)(selected * 0x23), item->scale);
        campMenuDrawSprite(parent, *labels, 0x27, item->alpha,
                           item->x + 483.0f,
                           item->y + (f32)(selected * 0x23), item->scale);
        break;
    case 8:
        alpha = (0xffU - item->alpha) | 0xffffff00U;
        for (i = 0; i < 3; i++) {
            record = FUN_0017c670(i);
            if (record == NULL) {
                frame = i == selected ? 0xa4 : 0x1d;
                campMenuDrawSprite(parent, *labels, frame, item->alpha,
                                   384.0f + item->x - 60.0f,
                                   item->y + 1.0f + (f32)(i * 0x23),
                                   item->scale);
                continue;
            }
            if (i == selected) {
                if (FUN_00403380(*(u16*)record) == 2) {
                    campMenuDrawSprite(parent, *labels, 0xa3, item->alpha,
                                       540.0f + item->x - 60.0f, 101.0f + item->y + (f32)(i * 0x23) - 108.0f,
                                       item->scale);
                } else {
                    valueB = (s16)FUN_00403800(*(u16*)record);
                    if (valueB != 0) {
                        if (valueB >= 10) {
                            campMenuDrawSpriteAlt(parent,
                                FUN_001120a0(1), valueB / 10 + 0xb,
                                item->alpha, 0xff, 0xbe, 0x5f,
                                       544.0f + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                        }
                        campMenuDrawSpriteAlt(parent,
                            FUN_001120a0(1), valueB % 10 + 0xb,
                            item->alpha, 0xff, 0xbe, 0x5f,
                            (f32)575 + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                        campMenuDrawSpriteAlt(parent, *labels, 0x24,
                            item->alpha, 0xff, 0xbe, 0x5f,
                            (f32)575 + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                        valueC = (s16)FUN_00403830(*(u16*)record);
                        if (valueC >= 10) {
                            campMenuDrawSpriteAlt(parent,
                                FUN_001120a0(1), valueC / 10 + 0xb,
                                item->alpha, 0xff, 0xbe, 0x5f,
                                (f32)586 + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                            campMenuDrawSpriteAlt(parent,
                                FUN_001120a0(1), valueC % 10 + 0xb,
                                item->alpha, 0xff, 0xbe, 0x5f,
                                (f32)602 + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                        } else {
                            campMenuDrawSpriteAlt(parent,
                                FUN_001120a0(1), valueC + 0xb,
                                item->alpha, 0xff, 0xbe, 0x5f,
                                (f32)586 + item->x - 60.0f, item->y + (f32)(i * 0x23), item->scale);
                        }
                    } else {
                        campMenuDrawSprite(parent, *labels, 0xa7,
                                           item->alpha, 540.0f + item->x - 60.0f,
                                           101.0f + item->y + (f32)(i * 0x23) - 108.0f, item->scale);
                    }
                }
                valueA = (s16)FUN_00403740(*(u16*)record);
                if (valueA >= 100) {
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA / 100 + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x, item->y + (f32)(i * 0x23), item->scale);
                    valueA %= 100;
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA / 10 + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x + 16.0f, item->y + (f32)(i * 0x23), item->scale);
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA % 10 + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x + 32.0f, item->y + (f32)(i * 0x23), item->scale);
                } else if (valueA >= 10) {
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA / 10 + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x + 7.0f, item->y + (f32)(i * 0x23), item->scale);
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA % 10 + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x + 7.0f + 16.0f, item->y + (f32)(i * 0x23), item->scale);
                } else {
                    campMenuDrawSpriteAlt(parent, FUN_001120a0(1),
                        valueA + 0xb, item->alpha, 0xff, 0xbe, 0x5f,
                        item->x + 14.0f, item->y + (f32)(i * 0x23), item->scale);
                }
                FUN_0017c6c0((s32)item->x + 60, (s32)(item->y + (f32)(i * 0x23) - 2.0f),
                             item->texture, alpha, 1, 6, *(u16*)record);
            } else {
                if (FUN_00403380(*(u16*)record) == 2) {
                    campMenuDrawSprite(parent, *labels, 0xa3, item->alpha,
                                       540.0f + item->x - 60.0f, 101.0f + item->y + (f32)(i * 0x23) - 108.0f,
                                       item->scale);
                } else {
                    valueB = (s16)FUN_00403800(*(u16*)record);
                    if (valueB != 0) {
                        fade = 255.0f -
                               fGpffff80c4 * (f32)(0xffU - item->alpha);
                        fadeAlpha = (u8)(s32)fade;
                        if (valueB >= 10) {
                            campMenuDrawSprite(parent,
                                FUN_001120a0(2), valueB / 10 + 0xb,
                                fadeAlpha, 544.0f + item->x - 60.0f, item->y + (f32)(i * 0x23),
                                item->scale);
                        }
                        fade = 255.0f -
                               fGpffff80c4 * (f32)(0xffU - item->alpha);
                        fadeAlpha = (u8)(s32)fade;
                        campMenuDrawSprite(parent,
                            FUN_001120a0(2), valueB % 10 + 0xb,
                            fadeAlpha, 620.0f + item->x - 120.0f, item->y + (f32)(i * 0x23),
                                item->scale);
                        campMenuDrawSprite(parent, *labels, 0x23,
                            item->alpha, (f32)575 + item->x - 60.0f, item->y + (f32)(i * 0x23),
                            item->scale);
                        valueC = (s16)FUN_00403830(*(u16*)record);
                        if (valueC >= 10) {
                            fade = 255.0f -
                                   fGpffff80c4 * (f32)(0xffU - item->alpha);
                            fadeAlpha = (u8)(s32)fade;
                            campMenuDrawSprite(parent,
                                FUN_001120a0(2), valueC / 10 + 0xb,
                                fadeAlpha, (f32)586 + item->x - 60.0f, item->y + (f32)(i * 0x23),
                                item->scale);
                            fade = 255.0f -
                                   fGpffff80c4 * (f32)(0xffU - item->alpha);
                            fadeAlpha = (u8)(s32)fade;
                            campMenuDrawSprite(parent,
                                FUN_001120a0(2), valueC % 10 + 0xb,
                                fadeAlpha, (f32)602 + item->x - 60.0f, item->y + (f32)(i * 0x23),
                                item->scale);
                        } else {
                            fade = 255.0f -
                                   fGpffff80c4 * (f32)(0xffU - item->alpha);
                            fadeAlpha = (u8)(s32)fade;
                            campMenuDrawSprite(parent,
                                FUN_001120a0(2), valueC + 0xb,
                                fadeAlpha, (f32)586 + item->x - 60.0f, item->y + (f32)(i * 0x23),
                                item->scale);
                        }
                    } else {
                        campMenuDrawSprite(parent, *labels, 0xa7,
                                           item->alpha, 540.0f + item->x - 60.0f,
                                           101.0f + item->y + (f32)(i * 0x23) - 108.0f, item->scale);
                    }
                }
                valueA = (s16)FUN_00403740(*(u16*)record);
                if (valueA >= 100) {
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA / 100 + 0xb, fadeAlpha,
                        item->x, item->y + (f32)(i * 0x23), item->scale);
                    valueA %= 100;
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA / 10 + 0xb, fadeAlpha,
                        item->x + 16.0f, item->y + (f32)(i * 0x23), item->scale);
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA % 10 + 0xb, fadeAlpha,
                        item->x + 32.0f, item->y + (f32)(i * 0x23), item->scale);
                } else if (valueA >= 10) {
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA / 10 + 0xb, fadeAlpha,
                        item->x + 7.0f, item->y + (f32)(i * 0x23), item->scale);
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA % 10 + 0xb, fadeAlpha,
                        item->x + 7.0f + 16.0f, item->y + (f32)(i * 0x23), item->scale);
                } else {
                    fade = 255.0f -
                           fGpffff80c4 * (f32)(0xffU - item->alpha);
                    fadeAlpha = (u8)(s32)fade;
                    campMenuDrawSprite(parent, FUN_001120a0(2),
                        valueA + 0xb, fadeAlpha,
                        item->x + 14.0f, item->y + (f32)(i * 0x23), item->scale);
                }
                FUN_0017c6c0((s32)item->x + 60, (s32)(item->y + (f32)(i * 0x23) - 2.0f),
                             item->texture, alpha, 1, 10, *(u16*)record);
            }
        }
        break;
    case 9:
        campMenuDrawSprite(parent, *labels, 0x2d, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 10:
        alpha = (0xffU - item->alpha) | 0xffffff00U;
        record = FUN_0017c670(selected);
        if (record != NULL) {
            FUN_0017c6e0((s32)item->x, (s32)(item->y - 2.0f - 3.0f),
                         (s32)item->scale, alpha, 1, 10, *(u16*)record);
        }
        break;
    case 11:
        campMenuDrawSprite(parent, *labels, 0x2c, item->alpha,
                           item->x, item->y, item->scale);
        break;
    case 12:
        campMenuDrawSprite(parent, *labels, 0x32, item->alpha,
                           item->x, item->y, item->scale);
        campMenuDrawSprite(parent, *labels, 0xa0, item->alpha,
                           424.0f + item->x - 59.0f, item->y, item->scale);
        break;
    case 13:
        alpha = (0xffU - item->alpha) | 0xffffff00U;
        itemRecord = FUN_0017c670(selected);
        record = itemRecord;
        if (record == NULL) {
            for (i = 0; i < 5; i++) {
                frame = i + 1 > 0 ? 0xa1 : 0xa2;
                campMenuDrawSprite(parent, *labels, frame, item->alpha,
                    item->x + 499.0f - 119.0f + (f32)(i * 0x17),
                    item->y + 340.0f - 333.0f, item->scale);
            }
        }
        dataId = *(u16*)record;
        record = FUN_00403880(dataId);
        category = *((u8*)record + 6);
        if (category == 0) {
            dataId = *((u16*)record + 4);
            if (FUN_00171250(dataId) == 4) {
                campMenuDrawSprite(parent, DAT_00833B70, 0x1b,
                                   item->alpha, item->x, item->y,
                                   item->scale);
            } else {
                values = (u32*)FUN_00170ed0(dataId, &valueKind);
                valueU = 0;
                if (values != NULL) {
                    valueU = valueKind == 3 ? values[0] : values[1];
                }
                frame = FUN_0012df50(valueU) * 2 + 1;
                campMenuDrawSprite(parent, DAT_00833B70, frame,
                                   item->alpha, item->x, item->y,
                                   item->scale);
            }
            FUN_00523ac8(text, 0x7cb66c,
                         FUN_00171110(dataId, *((s8*)record + 10)));
            width = FUN_003b2cb0_typed(item->scale,
                                       (s32)(154.0f + item->x - 119.0f),
                                       (s32)(9.0f + item->y + 2.0f), alpha,
                                       6, 1, (const char*)text, 0x11, 0);
            campMenuDrawSprite(parent, *labels, 0x33, item->alpha,
                               154.0f + item->x - 119.0f + (f32)width + 6.0f,
                               340.0f + item->y - 333.0f, item->scale);
            value = *((u8*)record + 7);
            if (value >= 10) {
                campMenuDrawSprite(parent, FUN_001120a0(1),
                                   value / 10 + 0xb, item->alpha,
                                   154.0f + item->x - 119.0f + (f32)width + 6.0f + 16.0f + 5.0f + 10.0f,
                                   13.0f + item->y - 1.0f, item->scale);
                campMenuDrawSprite(parent, FUN_001120a0(1),
                                   value % 10 + 0xb, item->alpha,
                                   154.0f + item->x - 119.0f + (f32)width + 6.0f + 16.0f + 5.0f + 10.0f + 16.0f,
                                   13.0f + item->y - 1.0f, item->scale);
            } else {
                campMenuDrawSprite(parent, FUN_001120a0(1),
                                   value + 0xb, item->alpha,
                                   154.0f + item->x - 119.0f + (f32)width + 6.0f + 16.0f + 5.0f + 10.0f,
                                   13.0f + item->y - 1.0f, item->scale);
            }
        } else if (category == 3) {
            FUN_00523ac8(text, 0x7cb67c, *((u32*)record + 2));
            width = FUN_0040eb50_typed(item->scale, (s32)item->x,
                                       (s32)(item->y + 16.0f),
                                       (u8)alpha, 3, (const char*)text, 8);
            campMenuDrawSprite(parent, *labels, 0x35, item->alpha,
                               item->x + 3.0f + (f32)width,
                               item->y + 340.0f - 333.0f, item->scale);
        }
        for (i = 0; i < 5; i++) {
            if (FUN_00403900(*(u16*)itemRecord) >= i + 1) {
                campMenuDrawSprite(parent, *labels, 0xa1, item->alpha,
                    item->x + 499.0f - 119.0f + (f32)(i * 0x17),
                    item->y + 340.0f - 333.0f, item->scale);
            } else {
                campMenuDrawSprite(parent, *labels, 0xa2, item->alpha,
                    item->x + 499.0f - 119.0f + (f32)(i * 0x17),
                    item->y + 340.0f - 333.0f, item->scale);
            }
        }
        break;
    case 99:
        campMenuDrawSprite(parent, *(labels + 1), 0, item->alpha,
                           item->x, item->y, item->scale);
        campMenuDrawSprite(parent, *(labels + 1), 0xa, item->alpha,
                           item->x + 47.0f - 31.0f, item->y, item->scale);
        campMenuDrawSprite(parent, DAT_00833BA0, 1, item->alpha,
                           item->x + 561.0f - 31.0f, item->y + 31.0f - 1.0f,
                           item->scale);
    default:
        break;
    }
}
// FUN_00159900
u32 FUN_00159900(CampMenuDrawItem* items, const char** labels, s32 count)
{
    s32 i;
    u32 complete = 1;

    for (i = 0; i < 100; i++) {
        CampMenuDrawItem* item = (CampMenuDrawItem*)((u8*)items + i * 0x44);
        if (*(u32*)((u8*)item + 4) != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00156F80(item, labels, i, count);
            }
            if (*(u32*)((int)items + i * 0x44 + 0x18) !=
                *(u32*)((int)items + i * 0x44 + 0x20)) {
                complete = 0;
            }
        }
    }
    return complete;
}


static void campDrawSkillDescription(CampMenuDrawItem* item, s32 skillId, s32 selected)
{
    u8 text[0x100];
    void* skill = (void*)FUN_0017d8b0(skillId, 1);
    FUN_00523ac8(text, 0x7cb66c, skill);
    campText(item, campDrawX(item), campDrawY(item) + 12.0f,
             (const char*)text, selected ? 6 : 10, 0x78);
}


// FUN_001599F0 NONMATCHING
void FUN_001599F0(CampMenuDrawItem* item, const char** labels, s32 mode, s32 category,
                  s32 selected)
{
    register u32 parent;
    s32 i;
    u8 text[0x100];
    u32 workId;

    switch (mode) {
    case 0:
        {
            workId = (u32)FUN_001158b0(0, *labels, 0x10);
            {
                u8* work;
                work = (u8*)workId;
                *(u32*)(work + 0x2c) = item->texture;
                *(f32*)(work + 0x10) = campDrawX(item);
                *(f32*)(work + 0x14) = campDrawY(item);
                work[0x18] = (u8)item->alpha;
                *(f32*)(work + 0x20) = -90.0f;
            }
            FUN_001127d0(workId, 1);
            FUN_00115980(workId);
        }
        break;
    case 1:
        campMenuDrawSprite(0, *labels, 0x1a, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            campMenuDrawSprite(parent, *labels, 0x2a, item->alpha,
                               campDrawX(item),
                               campDrawY(item) + (f32)(i * 28),
                               item->scale);
        }
        break;
    case 3:
        campMenuDrawSprite(parent, *labels, 0x39, item->alpha,
                           campDrawX(item) + 242.0f,
                           campDrawY(item) - 11.0f, item->scale);
        if (category < 10) {
            campMenuDrawSprite(parent, FUN_001120a0(1), category + 0xb,
                               item->alpha, campDrawX(item) + 16.0f,
                               campDrawY(item), item->scale);
        } else {
            campMenuDrawSprite(parent, FUN_001120a0(1), category / 10 + 0xb,
                               item->alpha, campDrawX(item),
                               campDrawY(item), item->scale);
            campMenuDrawSprite(parent, FUN_001120a0(1), category % 10 + 0xb,
                               item->alpha, campDrawX(item) + 16.0f,
                               campDrawY(item), item->scale);
        }
        campMenuDrawSprite(parent, *labels, 0x44, item->alpha,
                           campDrawX(item) + 34.0f,
                           campDrawY(item) - 2.0f, item->scale);
        if (selected >= 10) {
            campMenuDrawSprite(parent, FUN_001120a0(1), selected / 10 + 0xb,
                               item->alpha, campDrawX(item) + 52.0f,
                               campDrawY(item), item->scale);
            campMenuDrawSprite(parent, FUN_001120a0(1), selected % 10 + 0xb,
                               item->alpha, campDrawX(item) + 68.0f,
                               campDrawY(item), item->scale);
        } else {
            campMenuDrawSprite(parent, FUN_001120a0(1), selected + 0xb,
                               item->alpha, campDrawX(item) + 52.0f,
                               campDrawY(item), item->scale);
        }
        campMenuDrawSprite(parent, *labels, 0x42, item->alpha,
                           campDrawX(item) + 93.0f,
                           campDrawY(item) - 2.0f, item->scale);
        {
            s32 val = FUN_0017dae0(FUN_0017d8b0(category, selected));
            s32 spriteType = 0x40;
            if (val < 7) {
                switch (val) {
                case 0: spriteType = 0x41; break;
                case 1: spriteType = 0x3b; break;
                case 2: spriteType = 0x3c; break;
                case 3: spriteType = 0x3d; break;
                case 4: spriteType = 0x3e; break;
                case 5: spriteType = 0x3f; break;
                case 6: spriteType = 0x40; break;
                }
            }
            campMenuDrawSprite(parent, *labels, spriteType, item->alpha,
                               campDrawX(item) + 104.0f,
                               campDrawY(item) - 2.0f, item->scale);
            campMenuDrawSprite(parent, *labels, 0x43, item->alpha,
                               campDrawX(item) + 128.0f,
                               campDrawY(item) - 2.0f, item->scale);
        }
        break;
    case 4:
        {
            s16* record;
            u32 alpha = campDrawAlpha(item);
            s32 row = 0;
            s32 j;
            for (j = 0; j < 9999; j++) {
                record = (s16*)((u8*)iGpffffb2c8 + j * 0xc);
                if (record[0] == 0) {
                    break;
                }
                if (record[0] == category && record[1] == selected) {
                    int available = record[2] == 0;
                    if (!available && FUN_0016f190() != NULL) {
                        available = 1;
                    }
                    if (record[0] == 3 && record[4] == 0x13) {
                        available = 1;
                    }
                    if (available) {
                        FUN_00523ac8(text, gp0xffff897c, DAT_0083aaa0[record[4]]);
                        FUN_003b32d0(0, (s32)campDrawX(item),
                                     (s32)(campDrawY(item) + (f32)(row * 0x1c) + 2.0f),
                                     alpha, 10, 1, text, 0x10, 0);
                        row++;
                    }
                }
            }
            for (j = 0; j < 0x100; j++) {
                u8* learned = (u8*)FUN_0017ae30(j);
                if (learned == NULL || learned[0] == 0) {
                    break;
                }
                if (learned[0] == category && learned[1] == selected) {
                    FUN_00524270(text, uGpffff8884);
                    FUN_00523e68(text, FUN_003c3fe0(learned[2]));
                    FUN_003b32d0(0, (s32)campDrawX(item),
                                 (s32)(campDrawY(item) + (f32)(row * 0x1c) + 2.0f),
                                 alpha, 10, 1, text, 0x10, 0);
                    row++;
                }
            }
        }
        break;
    case 5:
        campMenuDrawSprite(0, *labels, 0x4a, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        campMenuDrawSprite(0, *labels, 0x4b, item->alpha,
                           (f32)0x23e + campDrawX(item) - (f32)0x145,
                           campDrawY(item), item->scale);
        break;
    case 6:
        if (category < 4) {
            FUN_00523ac8(text, gp0xffff8988);
        } else {
            FUN_00523ac8(text, gp0xffff8990);
        }
        {
            f32 digitX = campDrawX(item) + 65.0f;
            f32 digitY = campDrawY(item);
            for (i = 0; i < 4; i++) {
                s32 digit = -1;
                if (text[i] == '0') digit = 0;
                else if (text[i] == '1') digit = 1;
                else if (text[i] == '2') digit = 2;
                else if (text[i] == '3') digit = 3;
                else if (text[i] == '4') digit = 4;
                else if (text[i] == '5') digit = 5;
                else if (text[i] == '6') digit = 6;
                else if (text[i] == '7') digit = 7;
                else if (text[i] == '8') digit = 8;
                else if (text[i] == '9') digit = 9;
                if (digit != -1) {
                    campMenuDrawSpriteAlt(0, *labels, digit + 0x7c,
                        item->alpha, 0xdc, 0xf3, 0xff,
                        digitX, digitY - 1.0f, item->scale);
                }
                digitX += 17.0f;
            }
        }
        campMenuDrawSprite(0, *labels, 0x4c, item->alpha,
                           campDrawX(item) + 40.0f,
                           campDrawY(item) + 49.0f - 51.0f - 1.0f,
                           item->scale);
        if (category >= 10) {
            f32 catY = campDrawY(item) - 1.0f;
            campMenuDrawSprite(0, *labels, category / 10 + 0x7c,
                item->alpha, campDrawX(item), catY, item->scale);
            campMenuDrawSprite(0, *labels, category % 10 + 0x7c,
                item->alpha, campDrawX(item) + 17.0f, catY, item->scale);
        }
        break;
    case 7:
        campMenuDrawSprite(parent, *labels, 0x55, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 8:
        campMenuDrawSprite(parent, *labels, 0x54, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 9:
        campMenuDrawSprite(parent, *labels, 0x4e, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 10:
        campMenuDrawSprite(parent, *labels, 0x4f, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 11:
        campMenuDrawSprite(parent, *labels, 0x50, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 12:
        campMenuDrawSprite(parent, *labels, 0x51, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 13:
        campMenuDrawSprite(parent, *labels, 0x52, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 14:
        campMenuDrawSprite(parent, *labels, 0x53, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        break;
    case 15:
        for (i = 0; i < 6; i++) {
            campMenuDrawSprite(0, *labels, 0x56, item->alpha,
                               campDrawX(item),
                               campDrawY(item) + (f32)(i * 0x2c),
                               item->scale);
            campMenuDrawSprite(0, *labels, 0x56, item->alpha,
                               campDrawX(item) + (f32)0x265 - 326.0f,
                               campDrawY(item) + (f32)(i * 0x2c),
                               item->scale);
        }
        for (i = 1; i < 0x2b; i++) {
            campMenuDrawSprite(0, *labels, 0x58, item->alpha,
                campDrawX(item) + (f32)(((i - 1) % 7) * 0x29) + (f32)0x147 - 326.0f,
                campDrawY(item) + (f32)(((i - 1) / 7) * 0x2c) + (f32)0x66 - 102.0f,
                item->scale);
        }
        break;
    case 16:
        {
            s32 first = (s32)FUN_0017dae0(FUN_0017d8b0(category, 1));
            s32 count = DAT_005e3b5e[category];
            for (i = 1; i <= count; i++) {
                s32 slot = first + i - 1;
                campMenuDrawSprite(parent, *labels, 0x59, item->alpha,
                    campDrawX(item) + (f32)((slot % 7) * 0x29),
                    campDrawY(item) + (f32)((slot / 7) * 0x2c),
                    item->scale);
            }
            campMenuDrawSprite(parent, *labels, 0x56, item->alpha,
                campDrawX(item) - 1.0f, campDrawY(item) - 1.0f,
                item->scale);
        }
        break;
    case 17:
        if (category == (s32)FUN_0017d920()) {
            s32 start = (s32)FUN_0017dae0(FUN_0017d8b0(category, 1));
            start += FUN_0017da40() - 1;
            campMenuDrawSprite(parent, *labels, 0x5a, item->alpha,
                campDrawX(item) + (f32)((start % 7) * 0x29),
                campDrawY(item) + (f32)((start / 7) * 0x2c),
                item->scale);
        }
        break;
    case 18:
        {
            s32 start = (s32)FUN_0017dae0(FUN_0017d8b0(category, 1));
            s32 slot = start + selected - 1;
            campMenuDrawSprite(parent, *labels, 0x49, item->alpha,
                campDrawX(item) + (f32)((slot % 7) * 0x29),
                campDrawY(item) + (f32)((slot / 7) * 0x2c),
                item->scale);
        }
        break;
    case 19:
        {
            s32 count = DAT_005e3b5e[category];
            s32 first = (s32)FUN_0017dae0(FUN_0017d8b0(selected, 1));
            for (i = 1; i <= count; i++) {
                s32 slot = first + i - 1;
                f32 x = campDrawX(item) + (f32)((slot % 7) * 0x29);
                f32 y = campDrawY(item) + (f32)((slot / 7) * 0x2c);
                void* skill = (void*)FUN_0017d8b0(selected, i);
                s32 kind = FUN_00181b50(skill);
                if (kind == 0x1d || kind == 6 || kind == 0x0e || kind == 0x16) {
                    campSprite(item, x, y);
                } else {
                    campSpriteAlt(item, x, y);
                }
            }
        }
        break;
    case 20:
        {
            s32 count = DAT_005e3b5e[category];
            s32 first = (s32)FUN_0017dae0(FUN_0017d8b0(selected, 1));
            for (i = 1; i <= count; i++) {
                s32 slot = first + i - 1;
                f32 x = campDrawX(item) + (f32)((slot % 7) * 0x29);
                f32 y = campDrawY(item) + (f32)((slot / 7) * 0x2c);
                void* skill = (void*)FUN_0017d8b0(selected, i);
                s32 kind = FUN_00181b50(skill);
                if (kind == 0x1d || kind == 6 || kind == 0x0e || kind == 0x16) {
                    campSprite(item, x, y);
                }
            }
        }
        break;
    case 99:
        campMenuDrawSprite(parent, *(labels + 1), 0, item->alpha,
                           campDrawX(item), campDrawY(item), item->scale);
        campMenuDrawSprite(parent, *(labels + 1), 9, item->alpha,
                           campDrawX(item) + 16.0f, campDrawY(item),
                           item->scale);
        campMenuDrawSprite(parent, DAT_00833BA0, 1, item->alpha,
                           campDrawX(item) + 530.0f, campDrawY(item) + 30.0f,
                           item->scale);
        break;
    default:
        if (mode > 0x14 && mode < 0x35) {
            campMenuDrawSprite(parent, *labels, 0x57, item->alpha,
                               campDrawX(item), campDrawY(item),
                               item->scale);
        }
        break;
    }
}
