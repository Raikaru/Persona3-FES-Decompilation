#include "Camp/h_camp.h"
#include "h_cdvd.h"
#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "Kernel/Kwln/kwlnTask.h"

/* Camp persona display control state (0x12c bytes, matching the retail task work area). */
typedef struct CampPersonaDispCtlWork
{
    u32 state;
    u32 personaId;
    u32 reserved08;
    u32 mode;
    f32 alpha;
    f32 slideStep;
    f32 slidePosition;
    f32 depth;
    void* parseRequest;
    HCdvd* cdvd;
    void* resource;
    char path[0x100];
} CampPersonaDispCtlWork;

typedef struct CampTextureParserWork
{
    void* stream;
    HCdvd* cdvd;
} CampTextureParserWork;

typedef struct CampCommuRootWork
{
    u8 padding[0x150];
    void* cdvd;
} CampCommuRootWork;

extern void* (*DAT_00960184)(u32 elementCount, u32 elementSize, u32 hint);
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void (*jtbl_0096017C)(void* memory);
extern const char D_005DB190[];
extern const char D_005DB1B0[];
extern const char D_005DB1D0[];
extern const char D_005DB1F0[];
extern const char D_005DB210[];

#pragma alias campMainSocialLevelFresh datGetSocialLinkLevel
extern s8 campMainSocialLevelFresh(s16 socialLink);
extern void* func_0010c3a0(void* stream, u32* wasReady, s32* byteCount);
extern void func_004d0f00(void* resource);
extern void h_campPersonaDestroyDispCtlDrawTask(KwlnTask* task);
extern void* func_00133780(KwlnTask* task);
extern void FUN_00114450(f32 alpha, u32 mode, u32 color,
                         f32 slidePosition, f32 depth, u32 width,
                         u32 height, void* resource);
extern s32 printf(const char* format, ...);
extern KwlnTask* FUN_00133d30(void* stream, HCdvd* cdvd);
extern u32 func_0018b700(void* animation);


// FUN_001339A0
KwlnTask* FUN_001339a0(KwlnTask* parent, u32 priority, f32 alpha,
                       u32 personaId, u32 mode)
{
    f32 savedAlpha;
    CampPersonaDispCtlWork* work;
    KwlnTask* task;

    savedAlpha = alpha;
    work = (CampPersonaDispCtlWork*)(*DAT_00960184_abs)(1, 0x12c, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005DB190, priority, func_00133780,
                          h_campPersonaDestroyDispCtlDrawTask, work);
    if (task == NULL) {
        return NULL;
    }
    work->personaId = personaId;
    work->mode = mode;
    work->alpha = savedAlpha;
    return task;
}

// FUN_00133A80
void FUN_00133a80(KwlnTask* task)
{
    CampPersonaDispCtlWork* work;

    work = (CampPersonaDispCtlWork*)task->workData;
    if (work->state == 3 && work->personaId != 0) {
        if (work->slidePosition != 60.0f) {
            work->slidePosition -= work->slideStep;
            work->slideStep += 5.0f;
            if (work->slidePosition < 60.0f) {
                work->slidePosition = 60.0f;
            }
        }
        FUN_00114450(work->alpha, work->mode, 0x4FA4FF19,
                     work->slidePosition, work->depth, 0x280, 0x280,
                     work->resource);
    }
}

// FUN_00133B40
void FUN_00133b40(KwlnTask* task, u32 mode)
{
    CampPersonaDispCtlWork* work;

    work = (CampPersonaDispCtlWork*)task->workData;
    work->mode = (work->mode & 0xffffff00) | (mode & 0xff);
}

// FUN_00133B70
u32 FUN_00133b70(KwlnTask* task)
{
    CampPersonaDispCtlWork* work;

    work = (CampPersonaDispCtlWork*)task->workData;
    return work->mode;
}

// FUN_00133B80
void FUN_00133b80(KwlnTask* task, u32 personaId, u32 mode)
{
    CampPersonaDispCtlWork* work;

    work = (CampPersonaDispCtlWork*)task->workData;
    if (work->personaId != personaId || work->mode != mode) {
        if (work->parseRequest != NULL) {
            FUN_00133d30(work->parseRequest, work->cdvd);
            work->parseRequest = NULL;
            work->cdvd = NULL;
            work->resource = NULL;
        } else {
            if (work->cdvd != NULL) {
                H_Cdvd_Destroy(work->cdvd);
                work->cdvd = NULL;
            }
            if (work->resource != NULL) {
                func_004d0f00(work->resource);
                work->resource = NULL;
            }
        }
        work->mode = mode;
        work->personaId = personaId;
        work->state = 0;
    }
}

// FUN_00133C40
void* FUN_00133c40(KwlnTask* task)
{
    CampTextureParserWork* work;
    u32 wasReady;
    void* resource;

    work = (CampTextureParserWork*)task->workData;
    resource = func_0010c3a0(work->stream, &wasReady, NULL);
    if (wasReady != 0) {
        if (work->cdvd != NULL) {
            printf(D_005DB1B0, work->cdvd->path);
        } else {
            printf(D_005DB1D0);
        }
        if (resource != NULL) {
            func_004d0f00(resource);
        }
        if (work->cdvd != NULL) {
            H_Cdvd_Destroy(work->cdvd);
        }
        return KWLNTASK_STOP;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00133D00
void FUN_00133d00(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_00133D30
KwlnTask* FUN_00133d30(void* stream, HCdvd* cdvd)
{
    KwlnTask* task;
    CampTextureParserWork* work;

    work = (CampTextureParserWork*)(*DAT_00960184_abs)(1, 8, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf, FUN_00133c40,
                          FUN_00133d00, work);
    if (task == NULL) {
        return NULL;
    }
    if (cdvd != NULL) {
        printf(D_005DB210, cdvd->path);
    }
    work->stream = stream;
    work->cdvd = cdvd;
    return task;
}


/* ---- Camp slice continuation ---- */

#include "Utils.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_maestro.h"
extern void* H_Maestro_001120a0(s32 font);

/*
 * Camp's list renderer uses a 0x44-byte record.  The animation setup code
 * fills the interpolation fields at 0x28..0x34; these callbacks consume the
 * settled position, sprite scale, and alpha fields below.
 */
typedef struct CampMainDrawItem
{
    u32 owner;             /* 0x00 */
    u32 active;            /* 0x04 */
    void* resource0;       /* 0x08 */
    void* resource1;       /* 0x0c */
    void* resource2;       /* 0x10 */
    void* resource3;       /* 0x14 */
    u32 progress;          /* 0x18 */
    u32 startFrame;        /* 0x1c */
    u32 endFrame;          /* 0x20 */
    f32 spriteScale;       /* 0x24 */
    f32 startX;            /* 0x28 */
    f32 startY;            /* 0x2c */
    f32 scrollX;           /* 0x30 */
    f32 scrollY;           /* 0x34 */
    f32 x;                 /* 0x38 */
    f32 y;                 /* 0x3c */
    u32 alpha;             /* 0x40 */
} CampMainDrawItem;

/* The sprite list node allocated by FUN_001158b0. */
typedef struct CampMainSpriteNode
{
    void* next;            /* 0x00 */
    void* previous;        /* 0x04 */
    void* resource;        /* 0x08 */
    s32 frame;             /* 0x0c */
    f32 x;                 /* 0x10 */
    f32 y;                 /* 0x14 */
    u8 alpha;              /* 0x18 */
    u8 reserved19[0x0f];   /* 0x19..0x27 */
    u16 reserved28;        /* 0x28 */
    u16 rotation;          /* 0x2a */
    f32 spriteScale;       /* 0x2c */
} CampMainSpriteNode;

extern CampMainSpriteNode* FUN_001158b0(void* owner, void* resource, s32 frame);
extern void FUN_001127d0(CampMainSpriteNode* node, u32 enabled);
extern void FUN_00115980(void* node);
extern void FUN_001159f0(void* ignored, void* resource, s32 frame, u32 alpha,
                         f32 x, f32 y, f32 spriteScale);
extern void FUN_0012b860(u64 packedPosition, u64 auxiliaryPosition,
                         DatPersonaWork* persona, u32 alpha, f32 spriteScale);
extern void FUN_00125b40(u64 packedPosition, u64 auxiliaryPosition,
                         DatPersonaWork* persona, u32 alpha, f32 spriteScale);
extern const char* FUN_00173220(u16 personaId);
extern void FUN_003b2cb0(f32 scale, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
extern void FUN_003b2f90(f32 scale, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
extern int sprintf(char* buffer, const char* format, ...);
extern void* D_00833BA4;
extern void* D_00833B44;
extern void* D_00833B48;
extern void* D_00833B58;
extern char gp0xffff897c[];

/* Pack the two f32 coordinates exactly as the retail ld/sd pair does. */
typedef union CampMainPackedPosition
{
    struct
    {
        f32 x;
        f32 y;
    } coordinates;
    RwV2d vector;
    u64 value;
} CampMainPackedPosition;
typedef struct CampMainQuadPosition
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} CampMainQuadPosition;
typedef struct CampMainListEntry
{
    s32 itemId;
    s32 cursor;
} CampMainListEntry;

static u64 campMainPackPosition(f32 x, f32 y)
{
    CampMainPackedPosition position;

    position.coordinates.x = x;
    position.coordinates.y = y;
    return position.value;
}

static inline void* campMainResource(const void* resources, s32 index)
{
    return ((void* const*)resources)[index];
}

static inline void campMainDrawSprite(const CampMainDrawItem* item, void* resource,
                               s32 frame, f32 x, f32 y)
{
    FUN_001159f0(NULL, resource, frame, (u8)item->alpha, x, y,
                 item->spriteScale);
}
static void campMainDrawSpriteParent(void* parent,
                                     const CampMainDrawItem* item,
                                     void* resource, s32 frame,
                                     f32 x, f32 y)
{
    FUN_001159f0(parent, resource, frame, (u8)item->alpha, x, y,
                 item->spriteScale);
}

static void campMainQueueSprite(const CampMainDrawItem* item, void* resource,
                                s32 frame, f32 x, f32 y)
{
    CampMainSpriteNode* node;

    node = FUN_001158b0(NULL, resource, frame);
    node->spriteScale = item->spriteScale;
    node->x = x;
    node->y = y;
    node->alpha = (u8)item->alpha;
    FUN_001127d0(node, 1);
    FUN_00115980(node);
}

static void campMainDrawFontDigit(const CampMainDrawItem* item, s32 font,
                                  s32 digit, f32 x, f32 y)
{
    void* fontResource;

    fontResource = H_Maestro_001120a0(font);
    campMainDrawSprite(item, fontResource, digit + 11, x, y);
}

static void campMainDrawPersonaRow(const CampMainDrawItem* item,
                                   const void* resources, const s16* personaIds,
                                   s32 row, s32 selected)
{
    DatPersonaWork* persona;
    u8 level;
    s32 tens;
    s32 ones;
    s32 equippedPersona;
    s32 font;

    persona = datPersonaGetHeroPersona(personaIds[row]);
    if (row == selected) {
        campMainDrawSprite(item, campMainResource(resources, 1), 8,
                           item->x + 112.0f, item->y + 64.0f);
        font = 1;
    } else {
        equippedPersona = datGetPersonaId(1);
        if (persona->id == (u16)equippedPersona) {
            campMainDrawSprite(item, campMainResource(resources, 0), 5,
                               item->x + 112.0f, item->y + 64.0f);
        } else {
            campMainDrawSprite(item, campMainResource(resources, 1), 7,
                               item->x + 112.0f, item->y + 64.0f);
        }
        font = 2;
    }

    level = persona->level;
    if (level >= 10) {
        tens = level / 10;
        campMainDrawFontDigit(item, font, tens, item->x + 88.0f,
                              item->y + 12.0f);
    }
    ones = level % 10;
    campMainDrawFontDigit(item, font, ones, item->x + 104.0f,
                          item->y + 12.0f);
}

/* Reconstructed all mode branches, scrolling, persona labels, highlights,
 * and level digits from the retail instruction sequence.
 * Remaining differences are MWCC register coloring and outlined helpers. */
// FUN_00133E10 NONMATCHING
void FUN_00133E10(CampMainDrawItem* item,
                  const void* resources, s32 mode,
                  const s16* personaIds, s16 selected)
{
    void* parent;
    DatPersonaWork* persona;
    const char* personaName;
    char text[0x100];
    s32 personaIndex;
    s32 level;
    s32 digit;
    s32 equippedPersona;
    void* fontResource;
    u32 textColor;

    switch (mode) {
    case 0:
        {
            CampMainSpriteNode* node;

            node = FUN_001158b0(NULL, campMainResource(resources, 0), 0);
            node->spriteScale = item->spriteScale;
            node->x = item->x + 250.0f;
            node->y = item->y;
            node->alpha = (u8)item->alpha;
            FUN_001127d0(node, 1);
            FUN_00115980(node);

            node = FUN_001158b0(NULL, campMainResource(resources, 0), 0);
            node->spriteScale = item->spriteScale;
            node->x = item->x + (f32)0x2ee + 250.0f;
            node->y = item->y;
            node->alpha = (u8)item->alpha;
            FUN_001127d0(node, 1);
            FUN_00115980(node);
        }
        item->scrollX -= 1.0f;
        if (item->scrollX < -750.0f) {
            item->scrollX += 750.0f;
        }
        break;
    case 0x1b:
        FUN_001159f0(parent, campMainResource(resources, 0), 4,
                     (u8)item->alpha, item->x, item->y,
                     item->spriteScale);
        break;
    case 0x1c:
        FUN_001159f0(parent, campMainResource(resources, 2), 0,
                     (u8)item->alpha, item->x, item->y,
                     item->spriteScale);
        FUN_001159f0(parent, campMainResource(resources, 2), 1,
                     (u8)item->alpha, item->x + 16.0f, item->y,
                     item->spriteScale);
        FUN_001159f0(parent, D_00833BA4, 1,
                     (u8)item->alpha, item->x + 431.0f, item->y,
                     item->spriteScale);
        FUN_001159f0(parent, D_00833BA4, 3,
                     (u8)item->alpha, item->x + 527.0f, item->y,
                     item->spriteScale);
        FUN_001159f0(parent, D_00833BA4, 4,
                     (u8)item->alpha, item->x + 336.0f, item->y,
                     item->spriteScale);
        break;
    case 0x1d:
        break;
    default:
        if (mode < 0x0e) {
            personaIndex = mode - 1;
            persona = datPersonaGetHeroPersona(personaIds[personaIndex]);
            personaName = FUN_00173220(persona->id);
            sprintf(text, gp0xffff897c, personaName);
            textColor = (0xffU - item->alpha) | 0xffffff00U;
            FUN_003b2cb0(100.0f, (s32)item->x, (s32)item->y,
                         (s32)textColor, 10, 1, text, 0x10, 0);
        } else {
            personaIndex = mode - 0x0e;
            persona = datPersonaGetHeroPersona(personaIds[personaIndex]);
            if (personaIndex == (s32)selected) {
                FUN_001159f0(parent, campMainResource(resources, 1), 8,
                             (u8)item->alpha, item->x + 60.0f,
                             item->y + 3.0f, item->spriteScale);
                level = persona->level;
                if (level >= 10) {
                    digit = level / 10;
                    fontResource = H_Maestro_001120a0(1);
                    FUN_001159f0(parent, fontResource, digit + 11,
                                 (u8)item->alpha, item->x + 88.0f,
                                 item->y + 12.0f, item->spriteScale);
                }
                digit = level % 10;
                fontResource = H_Maestro_001120a0(1);
                FUN_001159f0(parent, fontResource, digit + 11,
                             (u8)item->alpha, item->x + 104.0f,
                             item->y + 12.0f, item->spriteScale);
            } else {
                equippedPersona = datGetPersonaId(1);
                if (persona->id == (u16)equippedPersona) {
                    FUN_001159f0(parent, campMainResource(resources, 0), 5,
                                 (u8)item->alpha, item->x + 60.0f,
                                 item->y + 3.0f, item->spriteScale);
                } else {
                    FUN_001159f0(parent, campMainResource(resources, 1), 7,
                                 (u8)item->alpha, item->x + 60.0f,
                                 item->y + 3.0f, item->spriteScale);
                }
                level = persona->level;
                if (level >= 10) {
                    digit = level / 10;
                    fontResource = H_Maestro_001120a0(2);
                    FUN_001159f0(parent, fontResource, digit + 11,
                                 (u8)item->alpha, item->x + 88.0f,
                                 item->y + 12.0f, item->spriteScale);
                }
                digit = level % 10;
                fontResource = H_Maestro_001120a0(2);
                FUN_001159f0(parent, fontResource, digit + 11,
                             (u8)item->alpha, item->x + 104.0f,
                             item->y + 12.0f, item->spriteScale);
            }
        }
        break;
    }
}


// FUN_001344B0
u32 FUN_001344B0(CampMainDrawItem* items, const void* resources,
                 const s16* personaIds, s16 selected)
{
    s32 i;
    u32 complete;
    CampMainDrawItem* item;

    complete = 1;
    for (i = 0; i < 100; i++) {
        item = (CampMainDrawItem*)((u8*)items + i * 0x44);
        if (item->active != 0) {
            if (func_0018b700(item) != 0) {
                FUN_00133E10(item, resources, i, personaIds, selected);
            }
            if (((CampMainDrawItem*)((u8*)items + i * 0x44))->progress !=
                ((CampMainDrawItem*)((u8*)items + i * 0x44))->endFrame) {
                complete = 0;
            }
        }
    }
    return complete;
}

static void campMainDrawPersonaCard(const CampMainDrawItem* item,
                                    const s16* personaIds, s32 personaIndex,
                                    f32 xOffset, f32 yOffset)
{
    DatPersonaWork* persona;
    u64 position;

    persona = datPersonaGetHeroPersona(personaIds[personaIndex]);
    position = campMainPackPosition(item->x + xOffset, item->y + yOffset);
    FUN_0012b860(position, 0, persona, (u8)item->alpha,
                 item->spriteScale);
    position = campMainPackPosition(item->x + xOffset + 12.0f,
                                    item->y + yOffset + 96.0f);
    FUN_00125b40(position, position, persona, (u8)item->alpha,
                 item->spriteScale);
}

#pragma alias FUN_001345B0_s16 FUN_001345B0
extern void FUN_001345B0_s16(CampMainDrawItem* item, const void* resources,
                             s32 mode, const s16* personaIds,
                             s16 personaIndex, s16 alternatePersonaIndex);
// FUN_001345B0 NONMATCHING
void FUN_001345B0(CampMainDrawItem* item, const void* resources, s32 mode,
                  const s16* personaIds, s16 personaIndex,
                  s16 alternatePersonaIndex)
{
    DatPersonaWork* persona;
    CampMainPackedPosition packed;

    switch (mode) {
    case 0:
        persona = datPersonaGetHeroPersona(personaIds[personaIndex]);
        packed.vector = *(RwV2d*)&item->x;
        FUN_0012b860(packed.value, 0, persona, (u8)item->alpha,
                     item->spriteScale);
        packed.coordinates.x = item->x + 12.0f;
        packed.coordinates.y = item->y + 96.0f;
        FUN_00125b40(packed.value, packed.value, persona,
                     (u8)item->alpha, item->spriteScale);
        break;
    case 1:
        persona = datPersonaGetHeroPersona(personaIds[alternatePersonaIndex]);
        packed.vector = *(RwV2d*)&item->x;
        FUN_0012b860(packed.value, 0, persona, (u8)item->alpha,
                     item->spriteScale);
        packed.coordinates.x = item->x + 12.0f;
        packed.coordinates.y = item->y + 96.0f;
        FUN_00125b40(packed.value, packed.value, persona,
                     (u8)item->alpha, item->spriteScale);
        break;
    case 2:
        FUN_001159f0(NULL, ((void* const*)resources)[0], 2,
                     item->alpha, item->x, item->y, item->spriteScale);
        break;
    case 3:
        FUN_001159f0(NULL, ((void* const*)resources)[0], 3,
                     item->alpha, item->x, item->y, item->spriteScale);
        break;
    case 4:
        FUN_001159f0(NULL, ((void* const*)resources)[0], 1,
                     item->alpha, item->x, item->y, item->spriteScale);
        break;
    case 5:
        FUN_001159f0(NULL, ((void* const*)resources)[0], 0,
                     item->alpha, item->x, item->y, item->spriteScale);
        FUN_001159f0(NULL, ((void* const*)resources)[2], 2,
                     item->alpha, item->x + 76.0f - 60.0f,
                     item->y, item->spriteScale);
        FUN_001159f0(NULL, D_00833BA4, 2,
                     item->alpha, item->x + 493.0f - 60.0f,
                     item->y, item->spriteScale);
        FUN_001159f0(NULL, D_00833BA4, 3,
                     item->alpha, item->x + 587.0f - 60.0f,
                     item->y, item->spriteScale);
        break;
    default:
        break;
    }
}

// FUN_00134900
u32 FUN_00134900(CampMainDrawItem* items, const void* resources,
                 const s16* personaIds, s16 selected, s16 personaIndex)
{
    s32 i;
    u32 complete;
    CampMainDrawItem* item;

    complete = 1;
    for (i = 0; i < 10; i++) {
        item = (CampMainDrawItem*)((u8*)items + i * 0x44);
        if (item->active != 0) {
            if (func_0018b700(item) != 0) {
                FUN_001345B0_s16(item, resources, i, personaIds,
                                 selected, personaIndex);
            }
            if (((CampMainDrawItem*)((u8*)items + i * 0x44))->progress !=
                ((CampMainDrawItem*)((u8*)items + i * 0x44))->endFrame) {
                complete = 0;
            }
        }
    }
    return complete;
}


/* ---- Camp slice continuation ---- */

#include "Camp/h_camp.h"
#include "Main/g_data.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "rw/rwplcore.h"

extern void* FUN_00133c40(KwlnTask* task);
extern void FUN_00133d00(KwlnTask* task);
extern void* FUN_0010c1a0(void* owner, const char* path, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                          s32 arg9, s32 arg10, const char* resourcePath,
                          s32 resourceId);
extern void* FUN_0010c3a0(void* resource, s32* size, s32 mode);
extern void FUN_003c7d80(s32 slot, void* memory);
extern void FUN_004d0f00(void* resource);
extern void FUN_005225a8(const char* message, ...);
extern void FUN_00523ac8(char* dst, const char* format, ...);
extern void* FUN_00172160(s32 id);
extern void* FUN_001717c0(s32 id);
extern u32 FUN_0016e100(s16 id);
extern s32 FUN_0016f190(s32 id);
extern void FUN_0010a4e0(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void FUN_00136820(f32 alpha, u64 packedPosition, const s32* entries,
                         s32 count, s32 offset, s32 selected, s32 mode,
                         s32 frame, s32 extra);
extern void FUN_00138e80(f32 alpha, u64 packedPosition, const s32* entries,
                         s32 count, s32 offset, s32 selected, s32 menuFlags,
                         s32 mode, s32 frame, s32 extra0, s32 extra1);
extern int printf(const char* format, ...);

extern const char D_005DBA00[];
extern const char D_005DBA20[];
extern const char D_005DBAE0[];
extern const char D_005DBA38[];
extern const char D_005DB1F0[];
extern const char D_005DBA50[];
extern const char D_005DBA70[];
extern const char D_005DBA80[];
extern const char D_005DBAA0[];
extern const char D_005DBAC0[];
extern const char D_005DB210[];
extern const char D_005DBBC0[];
extern const char D_005DBBF0[];
extern const char* D_005DB940[];
extern const char* D_005DB998[];
extern const char D_005E3220[];
extern const u16 D_005DBB00[];

extern s16 DAT_00833A60[9];
extern void* DAT_00833A80[0x17];
#pragma alias DAT_00833A80_abs DAT_00833A80
extern u8 DAT_00833A80_abs[];
extern void* DAT_00833B40[0x0b];
#pragma alias DAT_00833B40_abs DAT_00833B40
extern u8 DAT_00833B40_abs[];
extern u32 DAT_00833AD8;
extern KwlnTask* DAT_007cdf50;
extern u32 DAT_007cdf6c;
extern u32 DAT_007cdf70;
extern u32 DAT_007cdf74;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e095a;


static inline void h_campQueueResourceTaskForCurrent(void* resource, void* archive)
{
    KwlnTask* task;
    u32* work;

    work = (u32*)RwCalloc(1, 8, 0x40000);
    if (work == NULL) {
        return;
    }
    task = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                          FUN_00133c40, FUN_00133d00, work);
    if (task == NULL) {
        return;
    }
    if (archive != NULL) {
        printf(D_005DB210, ((HCdvd*)archive)->path);
    }
    work[0] = (u32)resource;
    work[1] = (u32)archive;
}

static void h_campBuildCardPath(char* path, s32 entry, s32 cardIndex)
{
    u16 cardId;
    void* knownText;

    if (entry == 0 || entry == 0x1d) {
        cardId = (u16)DAT_00833A60[cardIndex];
    } else {
        cardId = D_005DBB00[entry * 3 + cardIndex];
    }
    knownText = FUN_00172160(entry);
    if (knownText == NULL) {
        knownText = FUN_001717c0(entry);
    }
    if (knownText == NULL) {
        FUN_00523ac8(path, D_005DBBF0, cardId);
    } else {
        FUN_00523ac8(path, D_005DBBC0, cardId);
    }
}


static void h_campDestroyRequestAndResource(u32* work,
                                             u32 requestIndex,
                                             u32 resourceIndex)
{
    HCdvd* request;
    void* resource;

    request = (HCdvd*)work[requestIndex];
    if (request != NULL) {
        H_Cdvd_Destroy(request);
        work[requestIndex] = 0;
    }
    resource = (void*)work[resourceIndex];
    if (resource != NULL) {
        FUN_004d0f00(resource);
        work[resourceIndex] = 0;
    }
}

#pragma opt_loop_invariants on
//
// FUN_00134a10
void* FUN_00134a10(KwlnTask* task)
{
    u32* work;
    u32 archiveSize;
    s32 i;
    void* resource;
    s32 resourceSize;
    void* source;

    work = (u32*)task->workData;
    switch (work[0]) {
    case 0:
        work[0x30] = (u32)H_Cdvd_Request(D_005DBA00, 1);
        work[0] = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd*)work[0x30])) {
            {
                s32 index;
                for (index = 0; index < 0x0b; index++) {
                    source = H_Cdvd_ArchiveGetFile((HCdvd*)work[0x30],
                                                    index, &archiveSize);
                    work[0x34 + index] = (u32)func_00112420(source);
                }
            }
            work[0] = 2;
        }
        break;
    case 2:
        {
            u32 ready;
            s32 index;
            ready = 1;
            for (index = 0; index < 0x0b; index++) {
                if (!H_Maestro_00111f30((s16*)work[0x34 + index])) {
                    ready = 0;
                }
            }
            if (ready != 0) {
                {
                    s32 copyIndex;
                    for (copyIndex = 0; copyIndex < 0x0b; copyIndex++) {
                        ((void**)DAT_00833B40_abs)[copyIndex] =
                            (void*)work[0x34 + copyIndex];
                    }
                }
                H_Cdvd_Destroy((HCdvd*)work[0x30]);
                work[0x30] = 0;
                work[0] = 3;
            }
        }
        break;
    case 3:
        work[0x30] = (u32)H_Cdvd_Request(D_005DBA20, 1);
        work[0] = 4;
        break;
    case 4:
        if (H_Cdvd_IsFileLoaded((HCdvd*)work[0x30])) {
            {
                s32 index;
                for (index = 0; index < 0x17; index++) {
                    work[2 + index] = (u32)FUN_0010c1a0(
                        NULL, D_005DB940[index], 0, 0, 0, 0, 0, 0,
                        0, 0, D_005DBA38, 0xcb);
                }
            }
            work[0] = 5;
        }
        break;
    case 5:
        {
            u32 ready;
            s32 index;
            ready = 1;
            for (index = 0; index < 0x17; index++) {
                if (work[0x19 + index] == 0) {
                    resource = FUN_0010c3a0((void*)work[2 + index],
                                            &resourceSize, 0);
                    work[0x19 + index] = (u32)resource;
                    if (resourceSize == 0) {
                        ready = 0;
                        work[0x19 + index] = 0;
                        ((void**)DAT_00833A80_abs)[index] = NULL;
                    } else {
                        work[2 + index] = 0;
                        ((void**)DAT_00833A80_abs)[index] =
                            (void*)work[0x19 + index];
                        FUN_005225a8(D_005DBA50, index);
                    }
                }
            }
            if (ready != 0) {
                work[1] = 0x17;
                FUN_005225a8(D_005DBA70);
                H_Cdvd_Destroy((HCdvd*)work[0x30]);
                work[0x30] = 0;
                FUN_005225a8(D_005DBA80);
                work[0] = 9;
            }
        }
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
    return KWLNTASK_CONTINUE;
}
#pragma opt_loop_invariants off

// FUN_00134d80 NONMATCHING
void FUN_00134d80(KwlnTask* task)
{
    u32* work;
    u32 i;
    s32 state;
    void* resource;
    void* archive;
    void* record;
    KwlnTask* queued;

    work = (u32*)task->workData;
    for (i = 0; i < 0x17; i++) {
        resource = (void*)work[0x19 + i];
        if (resource != NULL) {
            FUN_004d0f00(resource);
            work[0x19 + i] = 0;
        }
        DAT_00833A80[i] = NULL;
    }
    for (i = 0; i < 0x0b; i++) {
        resource = (void*)work[0x34 + i];
        if (resource != NULL) {
            func_001124b0(resource);
        }
        DAT_00833B40[i] = NULL;
    }

    state = (s32)work[0];
    if (state == 5) {
        for (i = 0; i < 0x17; i++) {
            resource = (void*)work[2 + i];
            if (resource == NULL) {
                continue;
            }
            printf(D_005DBAA0, i);
            if (i == 0x2c) {
                archive = (void*)work[0x30];
                record = RwCalloc(1, 8, 0x40000);
                if (record != NULL) {
                    queued = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                                            FUN_00133c40, FUN_00133d00,
                                            record);
                    if (queued != NULL) {
                        if (archive != NULL) {
                            printf(D_005DB210, ((HCdvd*)archive)->path);
                        }
                        ((u32*)record)[0] = (u32)resource;
                        ((u32*)record)[1] = (u32)archive;
                    }
                }
                work[0x30] = 0;
            } else {
                record = RwCalloc(1, 8, 0x40000);
                if (record != NULL) {
                    queued = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                                            FUN_00133c40, FUN_00133d00,
                                            record);
                    if (queued != NULL) {
                        ((u32*)record)[0] = (u32)resource;
                        ((u32*)record)[1] = 0;
                    }
                }
            }
        }
        FUN_005225a8(D_005DBAC0);
        archive = (void*)work[0x30];
        if (archive != NULL) {
            H_Cdvd_Destroy((HCdvd*)archive);
            work[0x30] = 0;
        }
    } else if (state == 9) {
        archive = (void*)work[0x30];
        if (archive != NULL) {
            H_Cdvd_Destroy((HCdvd*)archive);
            work[0x30] = 0;
        }
    } else if (state < 6) {
        archive = (void*)work[0x30];
        if (archive != NULL) {
            H_Cdvd_Destroy((HCdvd*)archive);
            work[0x30] = 0;
        }
    } else {
        resource = (void*)work[work[1] + 2];
        if (resource == NULL) {
            archive = (void*)work[0x30];
            if (archive != NULL) {
                H_Cdvd_Destroy((HCdvd*)archive);
                work[0x30] = 0;
            }
        } else {
            archive = (void*)work[0x30];
            h_campQueueResourceTaskForCurrent(resource, archive);
            work[0x30] = 0;
        }
    }
    RwFree(work);
}

// FUN_00135120 NONMATCHING
void FUN_00135120(KwlnTask* task)
{
    u32* work;
    void* resource;
    void* oldRequest;
    void* record;
    KwlnTask* queued;
    const u16* cardTable;
    void* knownText;
    s32 selected;
    char path[256];

    work = (u32*)task->workData;
    iGpffffb280 = 0;
    resource = (void*)work[0x59];
    if (resource != NULL) {
        oldRequest = (void*)work[0x56];
        record = RwCalloc(1, 8, 0x40000);
        if (record != NULL) {
            queued = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                                    FUN_00133c40, FUN_00133d00, record);
            if (queued != NULL) {
                if (oldRequest != NULL) {
                    printf(D_005DB210, ((HCdvd*)oldRequest)->path);
                }
                ((u32*)record)[0] = (u32)resource;
                ((u32*)record)[1] = (u32)oldRequest;
            }
        }
        work[0x59] = 0;
        work[0x56] = 0;
    } else {
        oldRequest = (void*)work[0x56];
        if (oldRequest != NULL) {
            H_Cdvd_Destroy((HCdvd*)oldRequest);
            work[0x56] = 0;
        }
        resource = (void*)work[0x5b];
        if (resource != NULL) {
            FUN_004d0f00(resource);
            work[0x5b] = 0;
        }
    }

    selected = (s32)work[work[1] + work[2] + 8];
    if (selected == 0) {
        goto zero_card;
    }
    if (selected == 0x1d) {
        goto zero_card;
    }

    cardTable = D_005DBB00 + selected * 3;
    if (cardTable[work[5]] == 0) {
        goto done;
    }
    knownText = FUN_00172160(selected);
    if (knownText != NULL) {
        goto known_nonzero;
    }
    knownText = FUN_001717c0(selected);
    if (knownText == NULL) {
        goto fallback_nonzero;
    }
known_nonzero:
    sprintf(path, D_005DBBC0,
            (D_005DBB00 + selected * 3)[work[5]]);
    goto request_nonzero;
fallback_nonzero:
    sprintf(path, D_005DBBF0,
            (D_005DBB00 + selected * 3)[work[5]]);
request_nonzero:
    work[0x56] = (u32)H_Cdvd_Request(path, 0);
    goto done;

zero_card:
    if (DAT_00833A60[work[5]] == 0) {
        work[0x56] = 0;
        goto done;
    }
    knownText = FUN_00172160(selected);
    if (knownText != NULL) {
        goto known_zero;
    }
    knownText = FUN_001717c0(selected);
    if (knownText == NULL) {
        goto fallback_zero;
    }
known_zero:
    sprintf(path, D_005DBBC0, DAT_00833A60[work[5]]);
    goto request_zero;
fallback_zero:
    sprintf(path, D_005DBBF0, DAT_00833A60[work[5]]);
request_zero:
    work[0x56] = (u32)H_Cdvd_Request(path, 0);
done:
    ;
}

// FUN_00135460
void FUN_00135460(KwlnTask* task)
{
    u32* work;
    void* resource;
    void* oldRequest;
    void* record;
    KwlnTask* queued;
    s8 cardType;
    s16 selected;

    work = (u32*)task->workData;
    iGpffffb284 = 0;
    resource = (void*)work[0x5a];
    if (resource != NULL) {
        oldRequest = (void*)work[0x57];
        record = RwCalloc(1, 8, 0x40000);
        if (record != NULL) {
            queued = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                                    FUN_00133c40, FUN_00133d00, record);
            if (queued != NULL) {
                if (oldRequest != NULL) {
                    printf(D_005DB210, ((HCdvd*)oldRequest)->path);
                }
                ((u32*)record)[0] = (u32)resource;
                ((u32*)record)[1] = (u32)oldRequest;
            }
        }
        work[0x5a] = 0;
        work[0x57] = 0;
    } else {
        oldRequest = (void*)work[0x57];
        if (oldRequest != NULL) {
            H_Cdvd_Destroy((HCdvd*)oldRequest);
            work[0x57] = 0;
        }
        resource = (void*)work[0x5c];
        if (resource != NULL) {
            FUN_004d0f00(resource);
            work[0x5c] = 0;
        }
    }
    selected = (s16)work[work[1] + work[2] + 8];
    cardType = (s8)func_0016df30(selected);
    work[0x57] = (u32)H_Cdvd_Request(D_005DB998[(s32)cardType], 0);
}

// FUN_001355c0 NONMATCHING
void* FUN_001355c0(KwlnTask* task)
{
    u32* work;
    u32 i;
    u32 j;
    s32 current;
    s32 next;
    s32 available;
    s32 resourceSize;
    s32 index;
    s32 key;
    void* knownText;
    void* resource;
    char path[256];

    work = (u32*)task->workData;
    switch (work[0]) {
    case 0:
        if (H_Cdvd_IsFileLoaded((HCdvd*)work[0x54])) {
            FUN_003c7d80(0x0b, ((HCdvd*)work[0x54])->fileMemory);
            index = 0;
            for (j = 0; j < 9; j++) {
                if (j == 5) {
                    if (FUN_0016f190(0x1a) != 0) {
                        DAT_00833A60[index++] = 7;
                    }
                } else if (j != 7 && FUN_0016f190((s32)j + 0x150) != 0) {
                    switch (j) {
                    case 0: DAT_00833A60[index++] = 2; break;
                    case 1: DAT_00833A60[index++] = 3; break;
                    case 2: DAT_00833A60[index++] = 4; break;
                    case 3: DAT_00833A60[index++] = 5; break;
                    case 4: DAT_00833A60[index++] = 6; break;
                    case 6: DAT_00833A60[index++] = 8; break;
                    case 8: DAT_00833A60[index++] = 10; break;
                    }
                }
            }
            if (FUN_0016f190(0x157) != 0) {
                DAT_00833A60[index++] = 9;
            }
            if (index != 9) {
                DAT_00833A60[index] = 0;
            }
            work[0] = 2;
        }
        break;
    case 2:
        if (h_campRequestRootMenuTransition(DAT_007cdf50, 7) == 0) {
            return KWLNTASK_CONTINUE;
        }
        if (work[0x5d] == 0) {
            work[0x5d] = (u32)RwCalloc(1, 0xf8, 0x40000);
            if (work[0x5d] != 0) {
                work[0x5d] = (u32)kwlnTaskCreateWithAutoPriority(
                    task, 0x106f, D_005DBAE0, FUN_00134a10,
                    FUN_00134d80, (void*)work[0x5d]);
            }
            index = 0;
            for (j = 0; j < 0x1e; j++) {
                work[8 + j] = (u32)-1;
                if (FUN_0016e100((s16)j) != 0) {
                    work[8 + index] = j;
                    index++;
                }
            }
            work[4] = index;
            for (i = 0, j = 0; i < work[4]; i++, j = i) {
                while (j + 1 < work[4]) {
                    current = (s32)work[8 + i];
                    next = (s32)work[8 + j + 1];
                    j++;
                    key = (s8)D_005E3220[next];
                    if (key < (s8)D_005E3220[current]) {
                        work[8 + i] = (u32)next;
                        work[8 + j] = (u32)current;
                    }
                }
            }
        }
        work[0] = 3;
        break;
    case 3:
        if (((u32*)DAT_007cdf50->workData)[4] != 0) {
            work[0] = 4;
        }
        break;
    case 4:
        if (((u32*)((KwlnTask*)work[0x5d])->workData)[0] < 3) {
            return KWLNTASK_CONTINUE;
        }
        work[3]++;
        if (work[3] > 0x1e) {
            work[0] = 5;
        }
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 0, (s32)work[3], 0);
        break;
    case 5:
        if ((DAT_007e094e & 0x20) != 0) {
            FUN_0010a4e0(0, 0, 0, 2);
            return KWLNTASK_STOP;
        }
        if ((DAT_007e0952 & 0x40) == 0) {
            h_campUpdatePagedCursor(work[4], 5,
                                    (s32*)&work[2], (s32*)&work[1]);
        } else if ((s32)work[work[2] + work[1] + 8] != -1) {
            FUN_0010a4e0(0, 0, 0, 1);
            DAT_007cdf6c = (u32)-200;
            FUN_0010a4e0(0, 0, 0, 1);
            work[0] = 6;
        }
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 1, 0, 0);
        break;
    case 6:
        if (DAT_00833AD8 != 0) {
            if (work[0x5b] != 0) {
                FUN_004d0f00((void*)work[0x5b]);
                work[0x5b] = 0;
                DAT_007cdf70 = 0;
            }
            if (work[0x5c] != 0) {
                FUN_004d0f00((void*)work[0x5c]);
                work[0x5c] = 0;
                DAT_007cdf74 = 0;
            }
            work[0] = 7;
        }
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 2, 0, 0);
        break;
    case 7:
        work[5] = 0;
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 2, 0, 0);
        work[0] = 8;
        break;
    case 8:
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 2, 0, 0);
        if (h_campRequestRootMenuTransition(DAT_007cdf50, 8) == 0) {
            return KWLNTASK_CONTINUE;
        }
        FUN_00135460(task);
        FUN_00135120(task);
        work[3] = 0;
        work[0] = 9;
        break;
    case 9:
        if (((u32*)((KwlnTask*)work[0x5d])->workData)[0] < 9) {
            return KWLNTASK_CONTINUE;
        }
        if (((u32*)DAT_007cdf50->workData)[4] != 0) {
            work[0] = 0x0b;
        }
        FUN_00136820(100.0f, 0, (s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], 2, 0, 0);
        break;
    case 10:
        if ((DAT_007e094e & 0x20) != 0) {
            FUN_0010a4e0(0, 0, 0, 2);
            work[0] = 2;
        }
        FUN_00138e80(100.0f, 0, (const s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], (s32)work[5], 0,
                     (s32)work[3], (s32)work[6], 0);
        if ((s32)work[3] > 9 && (s32)work[6] < 10) {
            work[6]++;
        }
        break;
    case 0x0b:
        if ((s32)work[3] < 0x14) {
            work[3]++;
        }
        if (work[0x57] != 0) {
            if (work[0x5a] == 0) {
                if (H_Cdvd_IsFileLoaded((HCdvd*)work[0x57])) {
                    s8 cardType;
                    cardType = (s8)func_0016df30(
                        (s16)work[work[1] + work[2] + 8]);
                    work[0x5a] = (u32)FUN_0010c1a0(
                        NULL, D_005DB998[(s32)cardType], 0, 0, 0, 0, 0, 0,
                        0, 0, D_005DBA38, 0x2ea);
                }
            } else {
                resourceSize = 0;
                resource = FUN_0010c3a0((void*)work[0x5a],
                                        &resourceSize, 0);
                work[0x5c] = (u32)resource;
                if (resourceSize == 0) {
                    DAT_007cdf74 = 0;
                } else {
                    work[7] = 0;
                    work[0x5a] = 0;
                    DAT_007cdf74 = (u32)resource;
                    H_Cdvd_Destroy((HCdvd*)work[0x57]);
                    work[0x57] = 0;
                }
            }
        }
        if (work[0x56] != 0) {
            if (work[0x59] == 0) {
                if (H_Cdvd_IsFileLoaded((HCdvd*)work[0x56])) {
                    current = (s32)work[work[1] + work[2] + 8];
                    if (current == 0 || current == 0x1d) {
                        knownText = FUN_00172160(current);
                        if (knownText == NULL) {
                            knownText = FUN_001717c0(current);
                        }
                        if (knownText != NULL) {
                            sprintf(path, D_005DBBC0,
                                    (u16)DAT_00833A60[work[5]]);
                        } else {
                            sprintf(path, D_005DBBF0,
                                    (u16)DAT_00833A60[work[5]]);
                        }
                    } else {
                        knownText = FUN_00172160(current);
                        if (knownText == NULL) {
                            knownText = FUN_001717c0(current);
                        }
                        if (knownText != NULL) {
                            sprintf(path, D_005DBBC0,
                                    D_005DBB00[current * 3 + work[5]]);
                        } else {
                            sprintf(path, D_005DBBF0,
                                    D_005DBB00[current * 3 + work[5]]);
                        }
                    }
                    work[0x59] = (u32)FUN_0010c1a0(
                        NULL, path, 0, 0, 0, 0, 0, 0,
                        0, 0, D_005DBA38, 0x313);
                }
            } else {
                resourceSize = 0;
                resource = FUN_0010c3a0((void*)work[0x59],
                                        &resourceSize, 0);
                work[0x5b] = (u32)resource;
                if (resourceSize == 0) {
                    DAT_007cdf70 = 0;
                } else {
                    work[6] = 0;
                    work[0x59] = 0;
                    DAT_007cdf70 = (u32)resource;
                    H_Cdvd_Destroy((HCdvd*)work[0x56]);
                    work[0x56] = 0;
                }
            }
        }

        index = (s32)work[1] + (s32)work[2];
        current = (s32)work[8 + index];
        available = 0;
        if (current == 0) {
            for (i = 0; i < 9 && DAT_00833A60[i] != 0; i++) {
                available++;
            }
        } else if (current == 0x1d) {
            for (i = 0; i < 8 && DAT_00833A60[i] != 0; i++) {
                available++;
            }
        } else {
            for (i = 0; i < 3 && D_005DBB00[current * 3 + i] != 0; i++) {
                available++;
            }
        }

        if ((DAT_007e0952 & 4) == 0) {
            if ((DAT_007e0952 & 8) == 0) {
                if ((DAT_007e0952 & 0x1000) == 0 &&
                    (DAT_007e095a & 0x1000) == 0) {
                    if ((DAT_007e0952 & 0x4000) == 0 &&
                        (DAT_007e095a & 0x4000) == 0) {
                        if ((DAT_007e094e & 0x20) != 0) {
                            FUN_0010a4e0(0, 0, 0, 2);
                            work[0] = 2;
                        } else if ((s32)work[5] < available - 1) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            work[5]++;
                            FUN_00135120(task);
                        }
                    } else if (work[5] != 0) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work[5]--;
                        FUN_00135120(task);
                    }
                }
            } else {
                if ((s32)work[4] < 6) {
                    current = (s32)work[1];
                    work[1] = (u32)(current + 1);
                    if (current + 1 == (s32)work[4]) {
                        work[2] = 0;
                        work[1] = 0;
                        if (work[4] != 1) {
                            FUN_0010a4e0(0, 0, 0, 0);
                        }
                    }
                } else {
                    FUN_0010a4e0(0, 0, 0, 0);
                    current = (s32)work[1];
                    if (current == 3) {
                        if ((s32)work[2] + 5 < (s32)work[4]) {
                            work[2]++;
                        } else {
                            work[1] = 4;
                        }
                    } else if (current == 4) {
                        work[2] = 0;
                        work[1] = 0;
                    } else {
                        work[1] = (u32)(current + 1);
                    }
                }
                if (index != (s32)work[1] + (s32)work[2]) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    work[5] = 0;
                    FUN_00135460(task);
                    FUN_00135120(task);
                    work[3] = 0;
                }
            }
        } else {
            current = (s32)work[1];
            if (current == 1) {
                if (work[2] == 0) {
                    work[1]--;
                } else {
                    work[2]--;
                }
            } else if (current == 0) {
                if ((s32)work[4] < 5) {
                    work[2] = 0;
                    work[1] = work[4] - 1;
                } else {
                    work[1] = 4;
                    work[2] = work[4] - 5;
                }
            } else {
                work[1]--;
            }
            if (index != (s32)work[1] + (s32)work[2]) {
                FUN_0010a4e0(0, 0, 0, 0);
                work[5] = 0;
                FUN_00135460(task);
                FUN_00135120(task);
                work[3] = 0;
            }
        }

        FUN_00138e80(100.0f, 0, (const s32*)&work[8], (s32)work[4],
                     (s32)work[2], (s32)work[1], (s32)work[5], 0,
                     (s32)work[3], 0, 0);
        if ((s32)work[3] > 9 && (s32)work[6] < 10) {
            work[6]++;
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}


/* ---- Camp slice continuation ---- */

#include "Utils.h"
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"

/* Camp social-card carousel helpers.  The retail code uses packed f32 pairs
 * and a shared sprite queue; these layouts expose only the fields touched by
 * this module while keeping the asynchronous resource ownership explicit. */
typedef union CampCarouselPackedPosition
{
    struct { f32 x; f32 y; } value;
    u64 packed;
} CampCarouselPackedPosition;

typedef struct CampCardWork
{
    u8 opaque[0x150];
    void* iconResource;
    void* cardResources[2];
    void* archive;
    u8 reserved[0x1a0 - 0x15c];
} CampCardWork;

typedef struct CampCardSprite
{
    u8 opaque00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 opaque19[0x13];
    f32 spriteScale;
} CampCardSprite;

extern void* (*DAT_00960184)(u32 count, u32 size, u32 heap);
extern void (*jtbl_0096017C)(void* work);
extern void* DAT_00833B40[0x0b];
extern void* DAT_00833B48;
extern void* DAT_00833B4C;
extern void* DAT_00833B50;
extern void* DAT_00833B54;
extern void* DAT_00833B68;
#pragma alias DAT_00833B48_abs DAT_00833B48
extern u8 DAT_00833B48_abs[];
#pragma alias DAT_00833B68_abs DAT_00833B68
extern u8 DAT_00833B68_abs[];
#pragma alias D_00833BA4_abs D_00833BA4
extern u8 D_00833BA4_abs[];
extern void* DAT_00833A50[];
extern void* DAT_00833A80[];
extern s16 DAT_00833A60[];
extern s32 DAT_007cdf9c;
extern u32 DAT_007cdf70;
extern u32 DAT_007cdf74;
extern u32 DAT_007cdf6c;
extern u32 DAT_00833AD8;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e095a;
extern s32 iGpffffb280;
extern s32 iGpffffb27c;
extern s32 iGpffffb2a0;
extern s32 iGpffffb2a8;
extern s32 iGpffffb284;
extern const s8 DAT_005E3220[];
extern const char* D_005D80E4[];
extern const u16 D_005DBB00[];
extern const s16 D_005D7004[];
extern const s16 D_005D7006[];
extern const s16 D_005D6FEE[];
extern const s16 D_005D72AA[];
extern char gp0xffff897c[];
extern void* DAT_00833B68;
extern void* DAT_00833BA4;

extern void* FUN_001158B0(void* owner, void* resource, s32 frame);
extern void FUN_001127D0(void* sprite, s32 enabled);
extern void FUN_00115980(void* sprite);
extern void FUN_001159F0();
#pragma alias hCampMainCardFrameResource D_00833B58
extern u8 hCampMainCardFrameResource[];
#pragma alias hCampMainSocialFrameResource D_00833B44
extern u8 hCampMainSocialFrameResource[];
#pragma alias hCampMainCardIconResource D_00833B64
extern u8 hCampMainCardIconResource[];
#pragma alias hCampMainCardGlowResource D_00833B5C
extern u8 hCampMainCardGlowResource[];
#pragma alias hCampMainDrawSprite7 FUN_001159F0
extern void hCampMainDrawSprite7(void* parent, void* resource, s32 frame,
                                 u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias hCampMainDrawSprite3 FUN_001159F0
extern void hCampMainDrawSprite3(f32 x, f32 y, f32 scale);
#pragma alias hCampMainDrawSpriteAlt10 FUN_00115BC0
extern void hCampMainDrawSpriteAlt10(void* parent, void* resource, s32 frame,
                                     u32 alpha, s32 red, s32 green, s32 blue,
                                     f32 x, f32 y, f32 scale);
#pragma alias hCampMainDrawSpriteFade FUN_00115AD0
extern void hCampMainDrawSpriteFade(void* parent, void* resource, s32 frame,
                                    u32 alpha, f32 x, f32 y, f32 scale,
                                    u32 fade);
#pragma alias hCampMainDrawSpriteAlt3 FUN_00115BC0
extern void hCampMainDrawSpriteAlt3(f32 x, f32 y, f32 scale);
#pragma alias hCampMainDrawQuad7 FUN_001140D0
extern void hCampMainDrawQuad7(f32 depth, f32 x, f32 y, u32 color,
                               s32 width, s32 height, const void* textureState);
#pragma alias hCampMainDrawQuad6 FUN_001140D0
extern void hCampMainDrawQuad6(f32 depth, f32 x, f32 y, u32 color,
                               s32 width, s32 height);
#pragma alias hCampMainDrawTexQuadPtr FUN_00114E70
extern void hCampMainDrawTexQuadPtr(f32 depth, f32 x, f32 y,
                                    f32 textureX, f32 textureY, s32 orientation,
                                    u32 color, s32 width, s32 height,
                                    const void* textureDimensions);
 #pragma alias hCampMainDrawTexQuad FUN_00114E70
 extern void hCampMainDrawTexQuad(f32 depth, f32 x, f32 y,
                                  f32 textureX, f32 textureY, s32 orientation,
                                  u32 color, s32 width, s32 height, s32 textureDimensions);
#pragma alias hCampMainDrawSpriteAlpha FUN_001368A0
extern void hCampMainDrawSpriteAlpha(f32 alpha, u64 position, u8 drawAlpha);
#pragma alias hCampMainDrawValue FUN_003C7E20
extern void hCampMainDrawValue(f32 scale, s32 x, s32 y, u32 color,
                               u32 font, u32 alignment, u32 style, u32 value);
#pragma alias hCampMainDrawValueGlyph FUN_003C7E50
extern void hCampMainDrawValueGlyph(f32 scale, s32 x, s32 y, u32 color,
                                    u32 font, u32 alignment, u32 style,
                                    u32 value, u32 value2);
#pragma alias hCampMainDrawText FUN_003B2F90
extern void hCampMainDrawText(f32 scale, s32 x, s32 y, u32 color,
                              u32 font, u32 alignment, const char* text,
                              u32 maxWidth, s32 shadow);
extern void FUN_00115BC0();
extern void FUN_00115AD0();
extern void FUN_001140D0();
extern void FUN_00114E70();
extern void FUN_003B2F90();
extern void FUN_003C7E20();
extern void FUN_003C7E50();
extern void FUN_003C7DD0(s32 slot);
extern void FUN_001120A0(s32 font);
extern void FUN_005225A8();
extern void FUN_00523AC8();
extern s32 FUN_0016DBA0(s16 id);
extern void* FUN_0016E100(s16 id);
extern s32 FUN_0016F190(s32 id);
extern void* FUN_00172160(s32 id);
extern void* FUN_001717C0(s32 id);
extern s16 FUN_001775A0();
extern void* FUN_00194B20();
extern void* FUN_00194B80();
extern void* FUN_00100D80();
extern void FUN_00100EC0();
extern void* FUN_001016B0();
extern void* FUN_00102100();
extern void* FUN_00112420();
extern void FUN_001124B0();
extern s32 FUN_0011E380();
extern s32 FUN_0011ABD0();
extern void FUN_0010A4E0();
extern s32 FUN_0016DF30(s16 id);
extern s16 FUN_0016DD60(s32 slot);
extern s32 FUN_001C7CE0(s16 id);
extern s64 FUN_0017BC20();
extern s64 FUN_0017B860();
extern KwlnTask* FUN_001355C0(KwlnTask* task);
extern void FUN_00134D80(KwlnTask* task);
extern void FUN_00133C40(KwlnTask* task);
extern void FUN_00133D00(KwlnTask* task);

extern void func_004d0f00(void* resource);
extern void FUN_00136a10(f32 alpha, u64 position, s32 id, s32 selected, s32 textAlpha);
extern void FUN_00137300(f32 alpha, u64 position, s32 id, s32 selected, s32 textAlpha, s32 frame);
extern void FUN_001368a0(f32 alpha, u64 position, u8 drawAlpha);
extern void FUN_00137580(f32 alpha, u64 position, const s32* entries, s32 count, s32 offset, s32 selected, s32 frame);
extern void FUN_001380e0(f32 alpha, u64 position, const s32* entries, s32 count, s32 offset, s32 selected, s32 frame);
extern void FUN_001387b0(f32 alpha, u64 position, const s32* entries, s32 count, s32 offset, s32 selected, s32 frame);

static CampCarouselPackedPosition campCarouselUnpackPosition(u64 packed)
{
    CampCarouselPackedPosition p;
    p.packed = packed;
    return p;
}

static u64 campCarouselPackPosition(f32 x, f32 y)
{
    CampCarouselPackedPosition p;
    p.value.x = x;
    p.value.y = y;
    return p.packed;
}

static CampCardSprite* campQueueCardSprite(void* resource, s32 frame,
                                             f32 scale, f32 x, f32 y, u8 alpha)
{
    CampCardSprite* sprite;

    sprite = (CampCardSprite*)FUN_001158B0(NULL, resource, frame);
    if (sprite == NULL) {
        return NULL;
    }
    sprite->spriteScale = scale;
    sprite->x = x;
    sprite->y = y;
    sprite->alpha = alpha;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);
    return sprite;
}

static void campDrawCardSprite(void* resource, s32 frame, f32 scale,
                               f32 x, f32 y, s32 alpha)
{
    hCampMainDrawSprite7(NULL, resource, frame, (u32)alpha, x, y, scale);
}

static void campDrawCardText(f32 scale, f32 x, f32 y, u32 color,
                             s32 font, const char* text)
{
    (void)scale;
    FUN_003B2F90(100.0f, (s32)x, (s32)y, color, font, 1, text, 0x10, -1);
}

// FUN_001365B0 NONMATCHING
void FUN_001365b0(KwlnTask* task)
{
    u8* work;
    s32 i;
    u8* slot;
    void** pendingPtr;
    void** requestPtr;
    void* pending;
    void* request;
    void* record;
    KwlnTask* queued;

    work = (u8*)task->workData;
    iGpffffb280 = 0;
    iGpffffb284 = 0;
    for (i = 0; i < 2; i++) {
        slot = work + i * 4;
        pendingPtr = (void**)(slot + 0x164);
        pending = *pendingPtr;
        if (pending != NULL) {
            requestPtr = (void**)(slot + 0x158);
            request = *requestPtr;
            record = RwCalloc(1, 8, 0x40000);
            if (record != NULL) {
                queued = kwlnTaskCreate(NULL, D_005DB1F0, 0x18bf,
                                        FUN_00133c40, FUN_00133d00, record);
                if (queued != NULL) {
                    if (request != NULL) {
                        printf(D_005DB210, ((HCdvd*)request)->path);
                    }
                    ((u32*)record)[0] = (u32)pending;
                    ((u32*)record)[1] = (u32)request;
                }
            }
            *pendingPtr = NULL;
            *requestPtr = NULL;
        } else {
            requestPtr = (void**)(slot + 0x158);
            request = *requestPtr;
            if (request != NULL) {
                H_Cdvd_Destroy((HCdvd*)request);
                *requestPtr = NULL;
            }
            pending = *(void**)(slot + 0x16c);
            if (pending != NULL) {
                FUN_004d0f00(pending);
                *(void**)(slot + 0x16c) = NULL;
            }
        }
    }
    request = *(void**)(work + 0x150);
    if (request != NULL) {
        H_Cdvd_Destroy((HCdvd*)request);
        *(void**)(work + 0x150) = NULL;
    }
    FUN_003C7DD0(0x0b);
    (*jtbl_0096017C)(work);
}
// FUN_00136750 NONMATCHING
KwlnTask* FUN_00136750(KwlnTask* parent, u32 priority)
{
    KwlnTask* task;
    CampCommuRootWork* work;

    work = (CampCommuRootWork*)(*DAT_00960184_abs)(1, 0x1a0, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampCommuRoot", priority,
                              (void* (*)(KwlnTask*))FUN_001355C0,
                              (void (*)(KwlnTask*))FUN_001365b0, work);
    if (task == NULL) {
        return NULL;
    }
    work->cdvd = H_Cdvd_Request("camp_comu.pak", 0);
    return task;
}

// FUN_00136820
void FUN_00136820(f32 alpha, u64 position, const s32* entries, s32 count,
                  s32 offset, s32 selected, s32 mode, s32 frame, s32 extra)
{
    volatile u64 savedPosition;

    savedPosition = position;
    switch (mode) {
    case 0:
        FUN_00137580(alpha, position, entries, count, offset, selected, frame);
        break;
    case 1:
        FUN_001380e0(alpha, position, entries, count, offset, selected, extra);
        break;
    case 2:
        FUN_001387b0(alpha, position, entries, count, offset, selected, extra);
        break;
    }
}


// FUN_001368A0 NONMATCHING
void FUN_001368a0(f32 alpha, u64 position, u8 drawAlpha)
{
    CampCarouselPackedPosition p;
    CampCardSprite* sprite;
    f32 x;
    f32 y;

    p.packed = position;
    y = p.value.y;
    sprite = (CampCardSprite*)FUN_001158B0(NULL, DAT_00833B40[0], 1);
    sprite->spriteScale = alpha;
    x = (p.value.x + 318.0f) - 100.0f;
    sprite->x = x;
    y += 20.0f;
    sprite->y = y + (f32)DAT_007cdf9c;
    sprite->alpha = drawAlpha;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);

    sprite = (CampCardSprite*)FUN_001158B0(NULL, DAT_00833B40[0], 1);
    sprite->spriteScale = alpha;
    sprite->x = x;
    y = 100.0f + (y + ((f32)0x3ee + (f32)DAT_007cdf9c));
    sprite->y = y;
    sprite->alpha = drawAlpha;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);

    DAT_007cdf9c--;
    if (DAT_007cdf9c < -0x452) {
        DAT_007cdf9c += 0x452;
    }
}
#pragma alias campMainSocialFrameResourceAbs D_00833B44
extern u8 campMainSocialFrameResourceAbs[];
#pragma alias campMainSocialIconResourceAbs D_00833B48
extern u8 campMainSocialIconResourceAbs[];
#define D_00833B44 (*(void**)campMainSocialFrameResourceAbs)
#define D_00833B48 (*(void**)campMainSocialIconResourceAbs)

// FUN_00136A10 NONMATCHING
void FUN_00136a10(f32 alpha, u64 position, s32 id, s32 selected, s32 textAlpha)
{
    void* parent;
    CampCarouselPackedPosition p;
    s32 socialLevel;
    s32 i;
    s32 frame;
    u32 color;
    char text[0x100];

    p.packed = position;
    color = 0xffU - (u32)textAlpha;
    if (selected != 0) {
        socialLevel = datGetSocialLinkLevel((s16)id);
        if (socialLevel != 10) {
            hCampMainDrawSprite7(parent, D_00833B44, 0x2c, (u8)textAlpha,
                         p.value.x + 84.0f, p.value.y + 34.0f, alpha);
            hCampMainDrawSprite7(parent, H_Maestro_001120a0(1),
                         datGetSocialLinkLevel((s16)id) + 0xb,
                         (u8)textAlpha, p.value.x + 146.0f,
                         p.value.y + 35.0f, alpha);
        } else {
            hCampMainDrawSprite7(parent, D_00833B44, 0x2e, (u8)textAlpha,
                         p.value.x + 87.0f, p.value.y + 29.0f, alpha);
        }
        hCampMainDrawSprite7(parent, D_00833B44, 0x2f, (u8)textAlpha,
                     p.value.x + 83.0f, p.value.y + 47.0f, alpha);
        frame = (DAT_005E3220[id] - 1) * 2 + 1;
        hCampMainDrawSprite7(parent, D_00833B44, frame, (u8)textAlpha,
                     p.value.x + 84.0f, p.value.y + 46.0f, alpha);
        socialLevel = campMainSocialLevelFresh((s16)id);
        sprintf(text, gp0xffff897c,
                D_005D80E4[id * 10 + socialLevel]);
        FUN_003b2f90(100.0f, (s32)p.value.x + 0xad,
                     (s32)((f32)((s32)p.value.y + 0x35) + 2.0f), color | 0xffffff00U,
                     6, 1, text, 0x10, -1);
    } else {
        socialLevel = datGetSocialLinkLevel((s16)id);
        if (socialLevel != 10) {
            hCampMainDrawSprite7(parent, D_00833B44, 0x2d, (u8)textAlpha,
                         p.value.x + 84.0f, p.value.y + 34.0f, alpha);
            hCampMainDrawSprite7(parent, H_Maestro_001120a0(2),
                         datGetSocialLinkLevel((s16)id) + 0xb,
                         (u8)textAlpha, p.value.x + 146.0f,
                         p.value.y + 35.0f, alpha);
        } else {
            hCampMainDrawSprite7(parent, D_00833B44, 0x2e, (u8)textAlpha,
                         p.value.x + 87.0f, p.value.y + 29.0f, alpha);
        }
        socialLevel = campMainSocialLevelFresh((s16)id);
        if (socialLevel != 10) {
            hCampMainDrawSpriteAlt10(parent, D_00833B44, 0x30, (u8)textAlpha,
                         0x4f, 0xa4, 0xff, p.value.x + 83.0f,
                         p.value.y + 47.0f, alpha);
        } else {
            hCampMainDrawSprite7(parent, D_00833B44, 0x2f, (u8)textAlpha,
                         p.value.x + 83.0f, p.value.y + 47.0f, alpha);
        }
        socialLevel = datGetSocialLinkLevel((s16)id);
        if (socialLevel != 10) {
            frame = (DAT_005E3220[id] - 1) * 2;
        } else {
            frame = (DAT_005E3220[id] - 1) * 2 + 1;
        }
        hCampMainDrawSprite7(parent, D_00833B44, frame, (u8)textAlpha,
                     p.value.x + 84.0f, p.value.y + 46.0f, alpha);
        socialLevel = datGetSocialLinkLevel((s16)id);
        sprintf(text, gp0xffff897c,
                D_005D80E4[id * 10 + socialLevel]);
        FUN_003b2f90(100.0f, (s32)p.value.x + 0xad,
                     (s32)((f32)((s32)p.value.y + 0x35) + 2.0f), color | 0xffffff00U,
                     10, 1, text, 0x10, -1);
    }
    if (FUN_00172160(id) != NULL) {
        if (selected != 0) {
            hCampMainDrawSprite7(parent, D_00833B48, 0x10,
                         (u8)textAlpha, p.value.x + 165.0f,
                         p.value.y + 34.0f, alpha);
        } else {
            hCampMainDrawSprite7(parent, D_00833B48, 6,
                         (u8)textAlpha, p.value.x + 165.0f,
                         p.value.y + 34.0f, alpha);
        }
        return;
    }
    if (FUN_001717C0(id) != NULL) {
        if (selected != 0) {
            hCampMainDrawSprite7(parent, D_00833B48, 0xf,
                         (u8)textAlpha, p.value.x + 165.0f,
                         p.value.y + 34.0f, alpha);
        } else {
            hCampMainDrawSprite7(parent, D_00833B48, 5,
                         (u8)textAlpha, p.value.x + 165.0f,
                         p.value.y + 34.0f, alpha);
        }
        return;
    }
    socialLevel = datGetSocialLinkLevel((s16)id);
    if (selected != 0) {
        frame = 0x12;
        socialLevel = 0x14;
    } else {
        frame = 0x11;
        if (socialLevel != 10) {
            socialLevel = 0x13;
        } else {
            socialLevel = 0x14;
        }
    }
    hCampMainDrawSprite7(parent, D_00833B48, frame, (u8)textAlpha,
                 p.value.x + 165.0f, p.value.y + 34.0f, alpha);
    for (i = 0; i < datGetSocialLinkLevel((s16)id); i++) {
        hCampMainDrawSprite7(parent, D_00833B48, socialLevel, (u8)textAlpha,
                     p.value.x + 174.0f + i * 17.0f,
                     p.value.y + 37.0f, alpha);
    }
}
#undef D_00833B44
#undef D_00833B48

/* Draw the common five-card carousel frame used by all three modes. */
static void campDrawCarousel(f32 alpha, u64 position, const s32* entries,
                             s32 count, s32 offset, s32 selected,
                             s32 frame, u8 finalAlpha)
{
    CampCarouselPackedPosition p;
    s32 i;
    s32 visible;
    s32 index;
    s32 id;
    s32 fade;

    p = campCarouselUnpackPosition(position);
    campDrawCardSprite(DAT_00833B48, 0, alpha, p.value.x, p.value.y, finalAlpha);
    for (i = 0; i < 5; i++) {
        index = offset + i;
        if (index >= count) {
            break;
        }
        id = entries[index];
        visible = frame - i * 3;
        if (visible < 0) {
            continue;
        }
        fade = visible < 8 ? ((8 - visible) * 0xff) / 8 : 0;
        if (visible < 8) {
            fade = 0xff - fade;
        } else {
            fade = 0xff;
        }
        campDrawCardSprite(DAT_00833B48, 0xd, alpha,
                           p.value.x + 73.0f + i * 64.0f,
                           p.value.y + 49.0f + i * 64.0f, fade);
        FUN_00136a10(alpha, campCarouselPackPosition(p.value.x + i * 64.0f,
                                             p.value.y + i * 64.0f), id,
                     i == selected, fade);
        FUN_00137300(alpha, campCarouselPackPosition(p.value.x + i * 64.0f,
                                              p.value.y + i * 64.0f), id,
                     i == selected, fade, 0);
    }
    if (count < 10) {
        FUN_001368a0(alpha, position, (u8)((10 - count) * 0xff / 10));
    }
}

// FUN_00137300 NONMATCHING
void FUN_00137300(f32 alpha, u64 position, s32 id, s32 selected,
                  s32 textAlpha, s32 frame)
{
    CampCarouselPackedPosition p;
    void* resource;
    s32 kind;
    u32 color;

    (void)selected;
    (void)frame;
    p.packed = position;
    FUN_00172160(id);
    kind = (u8)DAT_005E3220[id] - 1;
    resource = DAT_00833A80[kind];
    if (resource == NULL) {
        return;
    }
    color = (0xffU - (u32)textAlpha) | 0xffffff00U;
    if (FUN_001717C0(id) == NULL) {
        hCampMainDrawQuad7(alpha, p.value.x + 24.0f, p.value.y + 23.0f,
                     color, 0x40, 0x40, resource);
    } else {
        hCampMainDrawTexQuadPtr(alpha, p.value.x + 24.0f, p.value.y + 23.0f,
                     1.0f, 1.0f, 2, color, 0x40, 0x40, resource);
    }
    if (FUN_00172160(id) != NULL) {
        campDrawCardSprite(DAT_00833B54, 0, alpha,
                           p.value.x + 10.0f, p.value.y + 5.0f, textAlpha);
    } else if (FUN_001717C0(id) != NULL) {
        campDrawCardSprite(DAT_00833B50, 0, alpha,
                           p.value.x + 24.0f, p.value.y + 10.0f, textAlpha);
    } else if (FUN_0016DBA0((s16)id) == '\n') {
        campDrawCardSprite(DAT_00833B4C, 0, alpha,
                           p.value.x + 24.0f, p.value.y + 10.0f, textAlpha);
    }
}

// FUN_00137580 NONMATCHING
void FUN_00137580(f32 alpha, u64 position, const s32* entries, s32 count,
                  s32 offset, s32 selected, s32 frame)
{
    CampMainPackedPosition input;
    volatile CampMainPackedPosition local;
    CampMainQuadPosition headerStage;
    CampMainQuadPosition rowStage;
    CampMainQuadPosition footerStage;
    CampMainSpriteNode* sprite;
    s32 i;
    s32 start;
    s32 slot;
    s32 visibleCount;
    s32 visible;
    s32 id;
    s32 fade;
    s32 rotation;
    f32 x;
    f32 y;
    f32 inputX;
    f32 inputY;

    input.value = position;
    inputX = input.coordinates.x;
    inputY = input.coordinates.y;
    local.value = 0;
    headerStage.x = 0.0f;
    headerStage.y = 0.0f;
    headerStage.z = alpha;
    headerStage.w = 0.0f;
    FUN_001159f0(NULL, DAT_00833B48, 0, 0,
                 55.0f + headerStage.x,
                 headerStage.y + 36.0f, headerStage.z);
    if (frame < 0x17) {
        for (i = 0; i < 5; i++) {
            visible = frame - i * 3;
            local.coordinates.y = inputY + i * 64.0f + 49.0f;
            if (visible < 0) {
                continue;
            }
            if (visible < 8) {
                local.coordinates.x = 0.0f;
                fade = (8 - visible) * 25;
                local.coordinates.y += (f32)fade;
                rowStage.x = local.coordinates.x;
                rowStage.y = local.coordinates.y;
                rowStage.z = alpha;
                rowStage.w = (f32)visible;
                rotation = visible * 0x1000 / 8;
                if (rotation != 0) {
                    sprite = FUN_001158b0(NULL, DAT_00833B48, 0xd);
                    sprite->spriteScale = alpha;
                    sprite->x = rowStage.x;
                    sprite->y = rowStage.y + 24.0f;
                    sprite->rotation = (u16)rotation;
                    sprite->alpha = 0;
                    FUN_001127D0(sprite, 1);
                    FUN_00115980(sprite);
                } else {
                    FUN_001159f0(NULL, DAT_00833B48, 0xd, 0,
                                 rowStage.x,
                                 rowStage.y + 24.0f, rowStage.z);
                }
            } else {
                local.coordinates.x = inputX;
                rowStage.x = local.coordinates.x;
                rowStage.y = local.coordinates.y;
                rowStage.z = alpha;
                rowStage.w = (f32)visible;
                sprite = FUN_001158b0(NULL, DAT_00833B48, 0xd);
                sprite->spriteScale = alpha;
                sprite->x = rowStage.x;
                sprite->y = rowStage.y + 24.0f;
                sprite->rotation = 0x1000;
                sprite->alpha = 0;
                FUN_001127D0(sprite, 1);
                FUN_00115980(sprite);
            }
        }
    } else {
        for (i = 0; i < 5; i++) {
            local.coordinates.x = inputX;
            local.coordinates.y = inputY + i * 64.0f + 49.0f;
            sprite = FUN_001158b0(NULL, DAT_00833B48, 0xd);
            sprite->spriteScale = alpha;
            sprite->x = local.coordinates.x;
            sprite->y = local.coordinates.y + 24.0f;
            sprite->rotation = 0x1000;
            sprite->alpha = 0;
            FUN_001127D0(sprite, 1);
            FUN_00115980(sprite);
        }
    }

    if (frame < 10) {
        fade = (10 - frame) * 0xff / 10;
        local.coordinates.x = (f32)(-(10 - frame) * 640 / 10);
        local.coordinates.y = 0.0f;
        sprite = FUN_001158b0(NULL, DAT_00833B40, 1);
        sprite->spriteScale = alpha;
        sprite->x = 218.0f + local.coordinates.x;
        sprite->y = local.coordinates.y + 20.0f;
        sprite->rotation = 0x1f40;
        sprite->alpha = (u8)fade;
        FUN_001127D0(sprite, 1);
        FUN_00115980(sprite);
    } else {
        local.value = 0;
        FUN_001368a0(alpha, local.value, 0);
    }

    visibleCount = count;
    if (count == 4) {
        start = 0;
    } else if (count == 3) {
        start = 1;
    } else if (count == 2 || count == 1) {
        start = 2;
    } else if (count == 0) {
        start = 0;
        visibleCount = 0;
    } else {
        start = 0;
        visibleCount = 5;
    }
    for (slot = 0; slot < visibleCount; slot++) {
        id = entries[offset + slot];
        i = slot + start;
        visible = frame - (i * 3 + 8);
        local.coordinates.x = inputX;
        local.coordinates.y = inputY + i * 64.0f + 49.0f;
        if (visible > 0 && visible < 8) {
            fade = (8 - visible) * 0xff / 8;
            if (slot == selected) {
                FUN_001159f0(NULL, DAT_00833B48, 0xe, (u32)fade,
                             local.coordinates.x,
                             local.coordinates.y + 24.0f, alpha);
                FUN_00136a10(alpha, local.value, id, 1, fade);
                FUN_00137300(alpha, local.value, id, 1, fade, 0);
            } else {
                FUN_00136a10(alpha, local.value, id, 0, fade);
                FUN_00137300(alpha, local.value, id, 0, fade, 0);
            }
        } else if (visible >= 8) {
            if (slot == selected) {
                FUN_001159f0(NULL, DAT_00833B48, 0xe, 0,
                             local.coordinates.x,
                             local.coordinates.y + 24.0f, alpha);
                FUN_00136a10(alpha, local.value, id, 1, 0);
                FUN_00137300(alpha, local.value, id, 1, 0, 0);
            } else {
                FUN_00136a10(alpha, local.value, id, 0, 0);
                FUN_00137300(alpha, local.value, id, 0, 0, 0);
            }
        }
    }

    if (frame < 10) {
        fade = (10 - frame) * 0xff / 10;
    } else {
        fade = 0;
    }
    x = inputX + 600.0f;
    y = inputY;
    FUN_001159f0(NULL, DAT_00833B48, 0xb, (u32)fade,
                 x, y + 308.0f, alpha - 1.0f);
    FUN_001159f0(NULL, DAT_00833B48, 0xc, (u32)fade,
                 x, y + 402.0f, alpha - 1.0f);
    if (count > 5) {
        rotation = offset * 59 / (count - 5);
    } else {
        rotation = 0;
    }
    FUN_001159f0(NULL, DAT_00833B48, 0xa, (u32)fade,
                 inputX + 597.0f, inputY + 311.0f + (f32)rotation,
                 alpha - 1.0f);
    FUN_001159f0(NULL, DAT_00833B48, 8, (u32)fade,
                 inputX + 598.0f, inputY + 318.0f + (f32)rotation,
                 alpha - 1.0f);
    FUN_001159f0(NULL, DAT_00833B48, 9, (u32)fade,
                 inputX + 598.0f, inputY + 331.0f + (f32)rotation,
                 alpha - 1.0f);
    FUN_001159f0(NULL, DAT_00833B48, 8, (u32)fade,
                 inputX + 598.0f, inputY + 318.0f + (f32)rotation,
                 alpha - 1.0f);
    FUN_001159f0(NULL, DAT_00833B48, 9, (u32)fade,
                 inputX + 598.0f, inputY + 331.0f + (f32)rotation,
                 alpha - 1.0f);

    if (frame < 10) {
        fade = (10 - frame) * 0xff / 10;
        footerStage.x = (f32)(-(10 - frame) * 640 / 10);
        footerStage.y = 0.0f;
        footerStage.z = alpha;
        footerStage.w = (f32)fade;
    } else {
        fade = 0;
        footerStage.x = 0.0f;
        footerStage.y = 0.0f;
        footerStage.z = alpha;
        footerStage.w = 0.0f;
    }
    sprite = FUN_001158b0(NULL, DAT_00833B40, 0);
    sprite->spriteScale = footerStage.z;
    sprite->x = 289.0f + footerStage.x;
    sprite->y = footerStage.y - 33.0f;
    sprite->alpha = (u8)fade;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);
}
// FUN_001380E0 NONMATCHING
void FUN_001380e0(f32 alpha, u64 position, const s32* entries, s32 count,
                  s32 offset, s32 selected, s32 frame)
{
    CampMainPackedPosition input;
    f32 inputX;
    f32 inputY;
    CampMainQuadPosition header;
    CampMainQuadPosition row;
    CampMainQuadPosition footer;
    CampMainQuadPosition copied;
    CampMainQuadPosition local;
    CampMainPackedPosition packed;
    CampMainSpriteNode* sprite;
    s32 i;
    s32 start;
    s32 visibleCount;
    s32 id;
    f32 x;
    f32 y;
    s32 fade;

    input.value = position;
    inputX = input.coordinates.x;
    inputY = input.coordinates.y;
    local.x = 0.0f;
    local.y = 0.0f;
    local.z = 0.0f;
    local.w = 0.0f;
    copied = local;
    header = copied;
    FUN_001159f0(NULL, DAT_00833B48, 0, 0,
                 55.0f + copied.x, 36.0f + copied.y, alpha);
    for (i = 0; i < 5; i++) {
        local.y = inputY + (f32)i * 64.0f + 49.0f;
        header.x = local.x;
        header.y = local.y;
        header.z = alpha;
        header.w = (f32)frame;
        sprite = FUN_001158b0(NULL, DAT_00833B48, 0xd);
        sprite->spriteScale = header.z;
        sprite->x = header.x;
        sprite->y = header.y + 24.0f;
        sprite->rotation = 0x1000;
        sprite->alpha = (u8)frame;
        FUN_001127D0(sprite, 1);
        FUN_00115980(sprite);
    }
    local.x = 0.0f;
    local.y = 0.0f;
    FUN_001368a0(alpha, *(u64*)&local, 0);

    visibleCount = count;
    switch (count) {
    case 0:
        start = 0;
        visibleCount = 0;
        break;
    case 1:
    case 2:
        start = 2;
        break;
    case 3:
        start = 1;
        break;
    case 4:
        start = 0;
        break;
    default:
        start = 0;
        visibleCount = 5;
        break;
    }
    for (i = 0; i < visibleCount; i++) {
        id = entries[offset + i];
        local.y = inputY + (f32)(i + start) * 64.0f + 49.0f;
        row.x = local.x;
        row.y = local.y;
        row.z = alpha;
        row.w = 0.0f;
        packed.coordinates.x = row.x;
        packed.coordinates.y = row.y;
        x = packed.coordinates.x;
        y = packed.coordinates.y + 24.0f;
        if (i == selected) {
            FUN_001159f0(NULL, DAT_00833B48, 0xe, 0, x, y, row.z);
            FUN_00136a10(row.z, packed.value, id, 1, 0);
            FUN_00137300(row.z, packed.value, id, 1, 0, (s32)row.w);
        } else {
            FUN_00136a10(row.z, packed.value, id, 0, 0);
            FUN_00137300(row.z, packed.value, id, 0, 0, (s32)row.w);
        }
    }

    footer.x = inputX;
    footer.y = inputY;
    footer.z = alpha - 1.0f;
    footer.w = 0.0f;
    FUN_001159f0(NULL, DAT_00833B48, 0xb, 0,
                 footer.x + 600.0f, footer.y + 308.0f, footer.z);
    FUN_001159f0(NULL, DAT_00833B48, 0xc, 0,
                 footer.x + 600.0f, footer.y + 402.0f, footer.z);
    fade = 0;
    if (count > 5) {
        fade = offset * 59 / (count - 5);
    }
    FUN_001159f0(NULL, DAT_00833B48, 0xa, 0,
                 footer.x + 597.0f, footer.y + 311.0f + (f32)fade,
                 footer.z);
    FUN_001159f0(NULL, DAT_00833B48, 8, 0,
                 footer.x + 598.0f, footer.y + 318.0f + (f32)fade,
                 footer.z);
    FUN_001159f0(NULL, DAT_00833B48, 9, 0,
                 footer.x + 598.0f, footer.y + 331.0f + (f32)fade,
                 footer.z);

    sprite = FUN_001158b0(NULL, DAT_00833B40, 0);
    sprite->spriteScale = alpha;
    sprite->x = 97.0f;
    sprite->y = -33.0f;
    sprite->alpha = 0;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);
    FUN_001159f0(NULL, DAT_00833B68, 0, 0, 36.0f, 415.0f, alpha);
    FUN_001159f0(NULL, DAT_00833B68, 6, 0, 80.0f, 415.0f, alpha);
    FUN_001159f0(NULL, D_00833BA4, 1, 0, 465.0f, 415.0f, alpha);
    FUN_001159f0(NULL, D_00833BA4, 3, 0, 561.0f, 415.0f, alpha);
}

// FUN_001387B0 NONMATCHING
void FUN_001387b0(f32 alpha, u64 position, const s32* entries, s32 count,
                  s32 offset, s32 selected, s32 frame)
{
    CampMainPackedPosition input;
    f32 inputX;
    f32 inputY;
    volatile u64 copied;
    volatile CampMainPackedPosition local;
    CampMainQuadPosition header;
    CampMainQuadPosition row;
    CampMainQuadPosition footer;
    CampMainSpriteNode* sprite;
    void* parent;
    s32 i;
    s32 start;
    s32 visibleCount;
    s32 id;
    f32 x;
    f32 y;
    s32 fade;

    input.value = position;
    inputX = input.coordinates.x;
    inputY = input.coordinates.y;
    local.value = 0;
    copied = local.value;
    FUN_001159f0(NULL, DAT_00833B48, 0, 0,
                 55.0f + *((volatile f32*)&copied),
                 36.0f + *(((volatile f32*)&copied) + 1), alpha);
    for (i = 0; i < 5; i++) {
        local.coordinates.y = inputY + (f32)i * 64.0f + 49.0f;
        header.x = local.coordinates.x;
        header.y = local.coordinates.y;
        header.z = alpha;
        header.w = (f32)frame;
        sprite = FUN_001158b0(NULL, DAT_00833B48, 0xd);
        sprite->spriteScale = header.z;
        sprite->x = header.x;
        sprite->y = header.y + 24.0f;
        sprite->rotation = 0x1000;
        sprite->alpha = (u8)frame;
        FUN_001127D0(sprite, 1);
        FUN_00115980(sprite);
    }
    local.value = 0;
    FUN_001368a0(alpha, local.value, 0);

    visibleCount = count;
    switch (count) {
    case 0:
        start = 0;
        visibleCount = 0;
        break;
    case 1:
    case 2:
        start = 2;
        break;
    case 3:
        start = 1;
        break;
    case 4:
        start = 0;
        break;
    default:
        start = 0;
        visibleCount = 5;
        break;
    }
    for (i = 0; i < visibleCount; i++) {
        id = entries[offset + i];
        local.coordinates.y = inputY + (f32)(i + start) * 64.0f + 49.0f;
        x = local.coordinates.x;
        y = local.coordinates.y + 24.0f;
        if (i == selected) {
            FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 0xe, 0, x, y, alpha);
            FUN_00136a10(alpha, local.value, id, 1, 0);
            FUN_00137300(alpha, local.value, id, 1, 0, 0);
        } else {
            FUN_00136a10(alpha, local.value, id, 0, 0);
            FUN_00137300(alpha, local.value, id, 0, 0, 0);
        }
    }
    x = inputX;
    y = inputY;
    fade = 0;
    FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 0xb, 0,
                 x + 600.0f, y + 308.0f, alpha - 1.0f);
    FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 0xc, 0,
                 x + 600.0f, y + 402.0f, alpha - 1.0f);
    if (count > 5) {
        fade = offset * 59 / (count - 5);
    }
    FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 0xa, 0,
                 x + 597.0f, y + 311.0f + (f32)fade, alpha - 1.0f);
    FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 8, 0,
                 x + 598.0f, y + 318.0f + (f32)fade, alpha - 1.0f);
    FUN_001159f0(parent, *(void**)DAT_00833B48_abs, 9, 0,
                 x + 598.0f, y + 331.0f + (f32)fade, alpha - 1.0f);

    sprite = FUN_001158b0(NULL, DAT_00833B40, 0);
    sprite->spriteScale = alpha;
    sprite->x = 97.0f;
    sprite->y = -33.0f;
    sprite->alpha = 0;
    FUN_001127D0(sprite, 1);
    FUN_00115980(sprite);
    FUN_001159f0(parent, *(void**)DAT_00833B68_abs, 0, 0, 36.0f, 415.0f, alpha);
    FUN_001159f0(parent, *(void**)DAT_00833B68_abs, 6, 0, 80.0f, 415.0f, alpha);
    FUN_001159f0(parent, *(void**)D_00833BA4_abs, 1, 0, 465.0f, 415.0f, alpha);
    FUN_001159f0(parent, *(void**)D_00833BA4_abs, 3, 0, 561.0f, 415.0f, alpha);
}

#pragma alias FUN_00139FC0_call FUN_00139FC0
extern void FUN_00139FC0_call(f32 alpha, u64 position, const s32* entries, u64 unused,
                              s32 offset, s32 selected, s32 menuFlags, s64 frame,
                              s32 transition);
extern void FUN_0013AFD0(f32 alpha, u64 position, const s32* entries, u64 unused,
                         s32 count, s32 offset, s32 transition, s32 transitionHi);

// FUN_00138E80
void FUN_00138E80(f32 alpha, u64 position, const s32* entries,
                  u64 count, s32 offset, s32 selected, s32 menuFlags,
                  s32 mode, s64 frame, s32 extra0, s32 extra1)
{
    volatile u64 savedPosition;
    savedPosition = position;
    switch (mode) {
    case 0:
        FUN_00139FC0_call(alpha, position, entries, count, offset, selected,
                     menuFlags, frame, extra0);
        break;
    case 1:
        FUN_0013AFD0(alpha, position, entries, count, offset, selected,
                     menuFlags, extra1);
        break;
    }
}

// FUN_00138EE0 NONMATCHING
void FUN_00138EE0(f32 alpha, u64 position, s32 id, s32 drawAlpha)
{
    void* parent;
    CampCarouselPackedPosition p;
    void* font;
    s32 kind;

    p.packed = position;
    if (FUN_00172160(id) != NULL || FUN_001717C0(id) != NULL) {
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x16, (u8)drawAlpha,
                                 0x55, 3, 0, p.value.x + 24.0f,
                                 p.value.y + 37.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x17, (u8)drawAlpha,
                                 0x55, 3, 0, p.value.x + 24.0f,
                                 p.value.y + 169.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x16, (u8)drawAlpha,
                                 0x55, 3, 0, p.value.x + 34.0f,
                                 p.value.y + 18.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x17, (u8)drawAlpha,
                                 0xff, 0xff, 0, p.value.x + 34.0f,
                                 p.value.y + 150.0f, alpha);
    } else {
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x16, (u8)drawAlpha,
                                 1, 0x2f, 0x49, p.value.x + 24.0f,
                                 p.value.y + 37.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x17, (u8)drawAlpha,
                                 1, 0x2f, 0x49, p.value.x + 24.0f,
                                 p.value.y + 169.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x16, (u8)drawAlpha,
                                 1, 0x2f, 0x49, p.value.x + 34.0f,
                                 p.value.y + 18.0f, alpha);
        hCampMainDrawSpriteAlt10(parent, *(void**)hCampMainCardFrameResource, 0x17, (u8)drawAlpha,
                                 1, 0x2f, 0x49, p.value.x + 34.0f,
                                 p.value.y + 150.0f, alpha);
    }
    kind = FUN_0016DBA0((s16)id);
    if (kind == 10) {
        hCampMainDrawSprite7(parent, *(void**)hCampMainSocialFrameResource, 0x2e, (u8)drawAlpha,
                             p.value.x + 51.0f, p.value.y + 23.0f, alpha);
    } else {
        hCampMainDrawSprite7(parent, *(void**)hCampMainSocialFrameResource, 0x2c, (u8)drawAlpha,
                             p.value.x + 42.0f, p.value.y + 23.0f, alpha);
        font = H_Maestro_001120a0(1);
        kind = FUN_0016DBA0((s16)id);
        hCampMainDrawSprite7(parent, font, kind + 0xb, (u8)drawAlpha,
                             p.value.x + 105.0f, p.value.y + 24.0f, alpha);
    }
}

// FUN_001392D0 NONMATCHING
void FUN_001392D0(f32 alpha, u64 position, s32 textAlpha, s32 resource)
{
    CampCarouselPackedPosition p;
    void* parent;
    u32 color;
    s32 fade;

    iGpffffb2a8++;
    if (iGpffffb2a8 > 0x13) {
        iGpffffb2a8 = 0;
    }
    if (iGpffffb2a8 >= 0xb) {
        fade = ((0x14 - iGpffffb2a8) * 0x80) / 10;
    }
    if (iGpffffb284 != 0) {
        p.packed = position;
        color = (0xffU - (u32)textAlpha) | 0xffffff00U;
        if (FUN_00172160(resource) != NULL) {
            hCampMainDrawTexQuad(alpha, p.value.x + 28.0f,
                                 p.value.y + 43.0f, 1.0f, 1.0f, 0,
                                 color, 0x62, 0x7e, iGpffffb284);
            hCampMainDrawSprite7(parent, *(void**)hCampMainCardIconResource,
                                 0, (u8)textAlpha, p.value.x + 23.0f,
                                 p.value.y + 33.0f, alpha);
            hCampMainDrawSprite7(parent, *(void**)hCampMainCardFrameResource,
                                 0x28, (u8)textAlpha, p.value.x + 29.0f,
                                 p.value.y + 148.0f, alpha);
        } else if (FUN_001717C0(resource) != NULL) {
            hCampMainDrawTexQuad(alpha, p.value.x + 28.0f,
                                 p.value.y + 43.0f, 1.0f, 1.0f, 2,
                                 color, 0x62, 0x7e, iGpffffb284);
            hCampMainDrawSpriteFade(parent, *(void**)hCampMainCardFrameResource,
                                    0x29, (u8)textAlpha, p.value.x + 24.0f,
                                    p.value.y + 37.0f, alpha,
                                    (u8)(fade + 0x7f));
            hCampMainDrawSpriteFade(parent, *(void**)hCampMainCardFrameResource,
                                    0x2a, (u8)textAlpha, p.value.x + 24.0f,
                                    p.value.y + 169.0f, alpha,
                                    (u8)(fade + 0x7f));
            hCampMainDrawSpriteFade(parent, *(void**)hCampMainCardGlowResource,
                                    0, (u8)textAlpha, p.value.x - 12.0f,
                                    p.value.y - 9.0f, alpha,
                                    (u8)(fade + 0x7f));
            hCampMainDrawSprite7(parent, *(void**)hCampMainCardFrameResource,
                                 0x27, (u8)textAlpha, p.value.x + 29.0f,
                                 p.value.y + 148.0f, alpha);
        } else {
            hCampMainDrawTexQuad(alpha, p.value.x + 28.0f,
                                 p.value.y + 43.0f, 1.0f, 1.0f, 0,
                                 color, 0x62, 0x7e, iGpffffb284);
        }
    }
}

#pragma alias campMainDrawCardSprite FUN_001159F0
extern void campMainDrawCardSprite(void* owner, void* resource, s32 frame,
                                   u32 alpha, f32 x, f32 y, f32 scale);
// FUN_00139660 NONMATCHING
void FUN_00139660(f32 alpha, u64 position, s32 id, s32 selected,
                  s32 textAlpha)
{
    s32 i;
    s32 rowOffset;
    s16 entryId;
    char text[0x100];
    u32 color;
    CampMainQuadPosition stage0;
    CampMainQuadPosition stage1;
    CampMainQuadPosition stage2;

    color = (0xffU - (u32)textAlpha) | 0xffffff00U;
    if (id == 0) {
        CampCarouselPackedPosition p0;
        s32 textX0;
        s32 textY0;

        p0.packed = position;
        stage0.x = p0.value.x;
        stage0.y = p0.value.y;
        stage0.z = alpha;
        stage0.w = (f32)textAlpha;
        textX0 = (s32)stage0.x + 0x38;
        textY0 = (s32)stage0.y + 0xc2;
        for (i = 0; i < 9; i++) {
            entryId = DAT_00833A60[i];
            if (entryId == 0) {
                return;
            }
            sprintf(text, gp0xffff897c, FUN_001775A0(entryId));
            rowOffset = i * 0x18;
            if (i == selected) {
                campMainDrawCardSprite(NULL, D_00833B58, 0x1b,
                                       (u32)textAlpha, stage0.x + 262.0f,
                                       stage0.y + 189.0f + (f32)rowOffset,
                                       alpha);
                campMainDrawCardSprite(NULL, D_00833B58, 0x1d,
                                       (u32)textAlpha, stage0.x + 35.0f,
                                       stage0.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX0,
                             (s32)(2.0f + (f32)(textY0 + rowOffset)),
                             color, 6, 1, text, 0x10, 0);
            } else {
                campMainDrawCardSprite(NULL, D_00833B58, 0x19,
                                       (u32)textAlpha, stage0.x + 35.0f,
                                       stage0.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX0,
                             (s32)(2.0f + (f32)(textY0 + rowOffset)),
                             color, 10, 1, text, 0x10, 0);
            }
        }
        return;
    }
    if (id == 0x1d) {
        CampCarouselPackedPosition p1;
        s32 textX1;
        s32 textY1;

        p1.packed = position;
        stage1.x = p1.value.x;
        stage1.y = p1.value.y;
        stage1.z = alpha;
        stage1.w = (f32)textAlpha;
        textX1 = (s32)stage1.x + 0x38;
        textY1 = (s32)stage1.y + 0xc2;
        for (i = 0; i < 8; i++) {
            entryId = DAT_00833A60[i];
            if (entryId == 0) {
                return;
            }
            sprintf(text, gp0xffff897c, FUN_001775A0(entryId));
            rowOffset = i * 0x18;
            if (i == selected) {
                campMainDrawCardSprite(NULL, D_00833B58, 0x1b,
                                       (u32)textAlpha, stage1.x + 262.0f,
                                       stage1.y + 189.0f + (f32)rowOffset,
                                       alpha);
                campMainDrawCardSprite(NULL, D_00833B58, 0x1d,
                                       (u32)textAlpha, stage1.x + 35.0f,
                                       stage1.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX1,
                             (s32)(2.0f + (f32)(textY1 + rowOffset)),
                             color, 6, 1, text, 0x10, 0);
            } else {
                campMainDrawCardSprite(NULL, D_00833B58, 0x19,
                                       (u32)textAlpha, stage1.x + 35.0f,
                                       stage1.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX1,
                             (s32)(2.0f + (f32)(textY1 + rowOffset)),
                             color, 10, 1, text, 0x10, 0);
            }
        }
        return;
    }
    {
        CampCarouselPackedPosition p2;
        s32 textX2;
        s32 textY2;

        p2.packed = position;
        stage2.x = p2.value.x;
        stage2.y = p2.value.y;
        stage2.z = alpha;
        stage2.w = (f32)textAlpha;
        textX2 = (s32)stage2.x + 0x38;
        textY2 = (s32)stage2.y + 0xc2;
        for (i = 0; i < 3; i++) {
            entryId = D_005DBB00[id * 3 + i];
            if (entryId == 0) {
                return;
            }
            sprintf(text, gp0xffff897c,
                    FUN_001775A0((s16)entryId));
            rowOffset = i * 0x18;
            if (i == selected) {
                campMainDrawCardSprite(NULL, D_00833B58, 0x1b,
                                       (u32)textAlpha, stage2.x + 262.0f,
                                       stage2.y + 189.0f + (f32)rowOffset,
                                       alpha);
                campMainDrawCardSprite(NULL, D_00833B58, 0x1d,
                                       (u32)textAlpha, stage2.x + 35.0f,
                                       stage2.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX2,
                             (s32)(2.0f + (f32)(textY2 + rowOffset)),
                             color, 6, 1, text, 0x10, 0);
            } else {
                campMainDrawCardSprite(NULL, D_00833B58, 0x19,
                                       (u32)textAlpha, stage2.x + 35.0f,
                                       stage2.y + 196.0f + (f32)rowOffset,
                                       alpha);
                FUN_003b2cb0(100.0f, textX2,
                             (s32)(2.0f + (f32)(textY2 + rowOffset)),
                             color, 10, 1, text, 0x10, 0);
            }
        }
    }
}


/* ---- Camp slice continuation ---- */

#include "Utils.h"
#include "rw/rwcore.h"
#include "rw/rwplcore.h"

/* The six routines below are the Camp carousel renderer and its input/state
 * helpers.  Their retail call graph is intentionally kept explicit: the
 * renderer is shared by the normal and alternate carousel paths, while the
 * late routines own the cursor texture and party-selection transitions. */

typedef struct CampPackedPosition
{
    f32 x;
    f32 y;
} CampPackedPosition;

typedef struct CampSpriteRecord
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[0x13];
    f32 spriteScale;
} CampSpriteRecord;

static inline f32 campPackedX(u64 value)
{
    CampPackedPosition position;
    *(u64*)&position = value;
    return position.x;
}

static inline f32 campPackedY(u64 value)
{
    CampPackedPosition position;
    *(u64*)&position = value;
    return position.y;
}

static inline u64 campPackPosition(f32 x, f32 y)
{
    CampPackedPosition position;
    position.x = x;
    position.y = y;
    return *(u64*)&position;
}

extern void* kwlnGetMainCamera(void);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias D_009600A0_abs D_009600A0
extern u8 D_009600A0_abs[];
#pragma alias D_00960088_abs D_00960088
extern u8 D_00960088_abs[];
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
extern f32 D_00960088;

extern void FUN_00139DC0(f32 param_1);
extern void FUN_001368A0();
extern void FUN_00138EE0(f32 alpha, u64 position, s32 id, s32 unused);
extern void FUN_001392D0(f32 alpha, u64 position, s32 textAlpha, s32 resource);
extern void FUN_00139660(f32 alpha, u64 position, s32 id, s32 selected, s32 textAlpha);
extern void FUN_001140D0();
extern void FUN_001159F0();
static inline void campDrawSprite(void* resource, s32 frame, u32 alpha, f32 x, f32 y, f32 scale)
{
    hCampMainDrawSprite7(NULL, resource, frame, alpha, x, y, scale);
}
extern s32 FUN_0016DBA0(s16 id);
extern void* FUN_00172160(s32 id);
extern void* FUN_001717C0(s32 id);
extern void FUN_003B2F90();
extern void FUN_003C7E20();
extern void FUN_003C7E50();
extern void FUN_00523AC8();
extern s32 sprintf(char* buffer, const char* format, ...);

extern const s8 DAT_005E3220[];
extern const char* D_005D80E4[];
extern const s16 D_005D7004[];
extern const s16 D_005D7006[];
extern const s16 D_005D6FEE[];
extern const s16 D_005D72AA[];
extern const u16 D_005DBB00[];
extern s16 D_00833A60[];
extern void* D_00833B44;
extern void* D_00833B58;
extern void* D_00833B60;
extern void* D_00833B64;
extern void* D_00833B68;
extern void* D_00833BA4;
#pragma alias D_00833B44_abs D_00833B44
extern u8 D_00833B44_abs[];
#pragma alias D_00833B58_abs D_00833B58
extern u8 D_00833B58_abs[];
#pragma alias D_00833B60_abs D_00833B60
extern u8 D_00833B60_abs[];
#pragma alias D_00833B64_abs D_00833B64
extern u8 D_00833B64_abs[];
#pragma alias D_00833B68_abs D_00833B68
extern u8 D_00833B68_abs[];
extern char gp0xffff897c[];
extern s32 iGpffffb280;
extern s32 iGpffffb27c;
extern s32 iGpffffb2a0;
extern void* DAT_00833A50[];

extern void* FUN_001158B0();
extern void FUN_001127D0();
extern void FUN_00115980();
extern s64 FUN_0017BC20();
extern s64 FUN_0017B860();
extern s16 datGetPartyId(s32 index);
extern s32 K_FldEvent_IsCharNearHeroBeforeBtl(s16 id);

// FUN_00139DC0
void FUN_00139DC0(f32 param_1)
{
    struct {
        u8 reserved[0x10];
        f32 positions[6];
        u8 align[8];
        RwIm2DVertex vertices[3];
    } work;
    f32 recipZ;
    f32 z;
    f32* vertex;
    f32* position;
    void* camera;
    void (**renderState)(u32 state, u32 value);
    s32 i;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / *(f32*)((u8*)camera + 0x80);
    renderState = (void (**)(u32, u32))D_00960090_abs;

    (*renderState)(6, 1);
    (*renderState)(7, 2);
    (*renderState)(8, 1);
    (*renderState)(9, 1);
    (*renderState)(0xC, 1);
    (*renderState)(0xB, 6);
    (*renderState)(0xA, 5);
    (*renderState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717FB);

    work.positions[0] = 319.0f;
    work.positions[1] = 448.0f;
    work.positions[2] = 640.0f;
    work.positions[3] = 328.0f;
    work.positions[4] = 640.0f;
    work.positions[5] = 448.0f;
    i = 0;
    z = *(f32*)D_00960088_abs - (param_1 - 1.0f);
    for (; i < 3; i++)
    {
        vertex = (f32*)&work.vertices[i];
        vertex[2] = z;
        vertex[6] = recipZ;
        vertex[8] = 0.0f;
        vertex[9] = 0.0f;
        vertex[10] = 0.0f;
        vertex[11] = 0.0f;
        position = &work.positions[i * 2];
        vertex[0] = position[0];
        vertex[1] = position[1];
    }
    (*renderState)(1, 0);
    (*(void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_abs)
        (rwPRIMTYPETRISTRIP, work.vertices, 3);
}

// FUN_00139FC0 NONMATCHING
void FUN_00139FC0(f32 param_1, u64 param_2, const s32* param_3, u64 param_4,
                  s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9)
{
    CampPackedPosition position;
    const s32* item;
    s32 id;
    s32 i;
    s32 alpha;
    s32 textAlpha;
    s32 mark;
    s32 socialLevel;
    s32 levelId;
    s16 level;
    u16 reward;
    void* hasResource;
    const char* text;
    char textBuffer[304];
    f32 x;
    f32 y;
    f32 rowY;
    u64 shiftedPosition;
    s32 itemOffset;
    s32 stage;

    stage = (s32)param_8;
    FUN_00139DC0(param_1);
    hCampMainDrawSpriteAlpha(param_1, 0, 0);

    position.x = campPackedX(param_2);
    position.y = campPackedY(param_2);
    itemOffset = param_5 + param_6;
    item = param_3 + itemOffset;
    id = *item;

    if (stage > 7)
    {
        if (stage - 8 < 5)
        {
            i = 5 - (stage - 8);
            x = (position.x - (f32)((i * 0xDC) / 5)) - 5.0f;
            y = (f32)((i * 0x32) / 5) + position.y + 10.0f;
            shiftedPosition = campPackPosition(x, y);
            FUN_00138EE0(param_1, shiftedPosition, id, 0);
            x += 5.0f;
            y -= 10.0f;
            shiftedPosition = campPackPosition(x, y);
            FUN_001392D0(param_1, shiftedPosition, 0, DAT_005E3220[id]);
        }
        else
        {
            FUN_00138EE0(param_1, param_2, id, 0);
            FUN_001392D0(param_1, param_2, 0, DAT_005E3220[id]);
        }
    }

    if (stage > 4)
    {
        if (stage - 5 < 5)
        {
            alpha = ((5 - (stage - 5)) * 0xFF) / 5;
        }
        else
        {
            alpha = 0;
        }
        FUN_00139660(param_1, param_2, id, param_7, alpha);
    }

    if (param_9 < 2)
    {
        alpha = 0xFF;
    }
    else if (param_9 < 7)
    {
        alpha = ((7 - (s32)param_9) * 0xFF) / 5;
    }
    else
    {
        alpha = 0;
    }

    if (iGpffffb280 != 0)
    {
        textAlpha = 0xFF - alpha;
        if (textAlpha > 0xB2)
        {
            textAlpha = 0xB2;
        }
        hCampMainDrawQuad6(param_1, 434.0f + position.x - 60.0f, position.y + 109.0f, textAlpha, 300, 300);
    }

    if (param_9 < 5)
    {
        alpha = ((5 - (s32)param_9) * 0xFF) / 5;
    }
    else
    {
        alpha = 0;
    }
    id = *item;
    if (iGpffffb280 != 0)
    {
        hCampMainDrawQuad6(param_1, 420.0f + position.x - 60.0f, position.y + 114.0f,
                     (0xFF - alpha) | 0xFFFFFF00, 300, 300);
        hasResource = FUN_00172160(id);
        if (hasResource == 0)
        {
            hasResource = FUN_001717C0(id);
            if (hasResource != 0)
            {
                campDrawSprite(D_00833B64, 3, (u8)alpha,
                               579.0f + position.x - 60.0f, position.y + 135.0f, param_1);
            }
        }
        else
        {
            campDrawSprite(D_00833B64, 2, (u8)alpha,
                           579.0f + position.x - 60.0f, position.y + 135.0f, param_1);
        }
    }

    if (stage > 1)
    {
        if (stage - 2 < 5)
        {
            alpha = ((5 - (stage - 2)) * 0xFF) / 5;
        }
        else
        {
            alpha = 0;
        }
        id = *item;
        campDrawSprite(D_00833B58, DAT_005E3220[id] - 1, (u8)alpha,
                       200.0f + position.x - 60.0f, position.y + 18.0f, param_1);
        rowY = position.y + 40.0f;
        campDrawSprite(D_00833B58, 0x2B, (u8)alpha,
                       202.0f + position.x - 60.0f, rowY, param_1);
        campDrawSprite(D_00833B58, 0x2C, (u8)alpha,
                       608.0f + position.x - 60.0f, rowY, param_1);
        campDrawSprite(D_00833B44, DAT_005E3220[id] + 0x31, (u8)alpha,
                       207.0f + position.x - 60.0f, position.y + 40.0f, param_1);
        campDrawSprite(D_00833B58, 0x2D, (u8)alpha,
                       291.0f + position.x - 60.0f, position.y + 48.0f, param_1);
    }

    if (stage > 2)
    {
        if (stage - 3 < 5)
        {
            alpha = ((5 - (stage - 3)) * 0xFF) / 5;
        }
        else
        {
            alpha = 0;
        }
        id = *item;
        textAlpha = 0xFF - alpha;
        mark = FUN_0016DBA0((s16)id);
        text = D_005D80E4[id * 10 + mark];
        FUN_00523AC8(textBuffer, gp0xffff897c, text);
        hCampMainDrawText(100.0f, (s32)(57.0f + position.x - 60.0f), (s32)(position.y + 48.0f),
                     textAlpha | 0xFFFFFF00, 6, 1, textBuffer, 0x10, -1);

        mark = FUN_0016DBA0((s16)*item);
        id = *item;
        if (mark != 0)
        {
            hasResource = FUN_001717C0(id);
            if (hasResource == 0)
            {
                hasResource = FUN_00172160(id);
                if (hasResource == 0)
                {
                    hCampMainDrawValue(param_1 - 2.0f, (s32)(position.x + 129.0f),
                                 (s32)(position.y + 65.0f), textAlpha | 0xFFFFFF00,
                                 1, 10, 7, D_005D6FEE[id * 0x0C + mark]);
                }
                else
                {
                    hCampMainDrawValue(param_1 - 2.0f, (s32)(position.x + 129.0f),
                                 (s32)(position.y + 65.0f), textAlpha | 0xFFFFFF00,
                                 1, 10, 7, D_005D7006[id * 0x0C]);
                }
            }
            else
            {
                hCampMainDrawValue(param_1 - 2.0f, (s32)(position.x + 129.0f),
                             (s32)(position.y + 65.0f), textAlpha | 0xFFFFFF00,
                             1, 10, 7, D_005D7004[id * 0x0C]);
            }
        }
    }

    if (stage > 4)
    {
        if (stage - 5 < 5)
        {
            alpha = ((5 - (stage - 5)) * 0xFF) / 5;
        }
        else
        {
            alpha = 0;
        }
        rowY = position.y + 415.0f;
        campDrawSprite(D_00833B68, 0, (u8)alpha,
                       96.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
        campDrawSprite(D_00833B68, 7, (u8)alpha,
                       112.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
        campDrawSprite(D_00833BA4, 3, (u8)alpha,
                       621.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
        campDrawSprite(D_00833BA4, 8, (u8)alpha,
                       487.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
        id = *item;
        if (id == 0 || id == 0x1D)
        {
            mark = FUN_0016DBA0((s16)id);
            level = D_00833A60[param_7];
            rowY = position.y + 334.0f;
            campDrawSprite(D_00833B58, 0x1F, (u8)alpha,
                           332.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
            campDrawSprite(D_00833B58, 0x20, (u8)alpha,
                           667.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
            if (mark != 0)
            {
                hCampMainDrawValueGlyph(param_1 - 2.0f, (s32)(345.0f + position.x - 60.0f),
                             (s32)(position.y + 333.0f), (0xFF - alpha) | 0xFFFFFF00,
                             1, 10, 0, 7, D_005D72AA[level * 10 + mark]);
            }
        }
        else
        {
            mark = FUN_0016DBA0((s16)id);
            reward = D_005DBB00[param_7 + id * 3];
            rowY = position.y + 334.0f;
            campDrawSprite(D_00833B58, 0x1F, (u8)alpha,
                           332.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
            campDrawSprite(D_00833B58, 0x20, (u8)alpha,
                           667.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
            if (mark != 0)
            {
                hCampMainDrawValueGlyph(param_1 - 2.0f, (s32)(345.0f + position.x - 60.0f),
                             (s32)(position.y + 333.0f), (0xFF - alpha) | 0xFFFFFF00,
                             1, 10, 0, 7, D_005D72AA[reward * 10 + mark]);
            }
        }
    }

    if (stage < 5)
    {
        alpha = ((5 - stage) * 0xFF) / 5;
    }
    else
    {
        alpha = 0;
    }
    iGpffffb27c++;
    if (iGpffffb27c > 0x1C0)
    {
        iGpffffb27c = 0;
    }
    x = 636.0f + position.x - 60.0f;
    shiftedPosition = campPackPosition(x, position.y + 199.0f + (f32)iGpffffb27c);
    campDrawSprite(D_00833B60, 0, (u8)alpha,
                   campPackedX(shiftedPosition), campPackedY(shiftedPosition),
                   param_1 - 3.0f);
    campDrawSprite(D_00833B60, 1, (u8)alpha,
                   x, position.y + (f32)iGpffffb27c, param_1 - 3.0f);
    campDrawSprite(D_00833B60, 0, (u8)alpha,
                   x, position.y + 199.0f + (f32)iGpffffb27c - 448.0f,
                   param_1 - 3.0f);
    campDrawSprite(D_00833B60, 1, (u8)alpha,
                   x, position.y + (f32)iGpffffb27c - 448.0f, param_1 - 3.0f);
}

#define D_00833B44 (*(void**)D_00833B44_abs)
#define D_00833B58 (*(void**)D_00833B58_abs)
#define D_00833B60 (*(void**)D_00833B60_abs)
#define D_00833B64 (*(void**)D_00833B64_abs)
#define D_00833B68 (*(void**)D_00833B68_abs)
#define D_00833BA4 (*(void**)D_00833BA4_abs)
// FUN_0013AFD0 NONMATCHING
void FUN_0013AFD0(f32 param_1, u64 param_2, const s32* param_3, u64 param_4,
                  s32 param_5, s32 param_6, s32 param_7, s32 param_8)
{
    CampPackedPosition position;
    const s32* item;
    s32 id;
    s32 alpha;
    s32 mark;
    void* hasResource;
    s16 level;
    u16 reward;
    s32 socialLevel;
    char textBuffer[416];
    const char* text;
    f32 rowY;
    f32 x;

    (void)param_4;
    FUN_00139DC0(param_1);
    hCampMainDrawSpriteAlpha(param_1, 0, 0);

    position.x = campPackedX(param_2);
    position.y = campPackedY(param_2);
    item = param_3 + param_5 + param_6;
    id = *item;
    FUN_00138EE0(param_1, param_2, DAT_005E3220[id], 0);
    FUN_001392D0(param_1, param_2, 0, DAT_005E3220[id]);
    FUN_00139660(param_1, param_2, id, (s32)param_7, 0);
    FUN_00139DC0(param_1);

    if (iGpffffb280 != 0)
    {
        hCampMainDrawQuad6(param_1, 434.0f + position.x - 60.0f, position.y + 109.0f, 0xB2, 300, 300);
    }
    id = *item;
    if (iGpffffb280 != 0)
    {
        hCampMainDrawQuad6(param_1, 420.0f + position.x - 60.0f, position.y + 114.0f,
                     0xFFFFFF00, 300, 300);
        hasResource = FUN_00172160(id);
        if (hasResource == 0)
        {
            hasResource = FUN_001717C0(id);
            if (hasResource != 0)
            {
                campDrawSprite(D_00833B64, 3, 0,
                               579.0f + position.x - 60.0f, position.y + 135.0f, param_1);
            }
        }
        else
        {
            campDrawSprite(D_00833B64, 2, 0,
                           579.0f + position.x - 60.0f, position.y + 135.0f, param_1);
        }
    }

    campDrawSprite(D_00833B58, DAT_005E3220[id] - 1, 0,
                   200.0f + position.x - 60.0f, position.y + 18.0f, param_1);
    rowY = position.y + 40.0f;
    campDrawSprite(D_00833B58, 0x2B, 0,
                   202.0f + position.x - 60.0f, rowY, param_1);
    campDrawSprite(D_00833B58, 0x2C, 0,
                   608.0f + position.x - 60.0f, rowY, param_1);
    campDrawSprite(D_00833B44, DAT_005E3220[id] + 0x31, 0,
                   207.0f + position.x - 60.0f, position.y + 40.0f, param_1);
    campDrawSprite(D_00833B58, 0x2D, 0,
                   291.0f + position.x - 60.0f, position.y + 48.0f, param_1);

    id = *item;
    mark = FUN_0016DBA0((s16)id);
    text = D_005D80E4[id * 10 + mark];
    FUN_00523AC8(textBuffer, gp0xffff897c, text);
    hCampMainDrawText(100.0f, (s32)(57.0f + position.x - 60.0f), (s32)(position.y + 48.0f),
                 0xFFFFFFFF, 6, 1, textBuffer, 0x10, -1);

    rowY = position.y + 415.0f;
    campDrawSprite(D_00833B68, 0, 0,
                   96.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
    campDrawSprite(D_00833B68, 7, 0,
                   112.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
    campDrawSprite(D_00833BA4, 3, 0,
                   621.0f + position.x - 60.0f, rowY, param_1 - 4.0f);
    campDrawSprite(D_00833BA4, 8, 0,
                   487.0f + position.x - 60.0f, rowY, param_1 - 4.0f);

    mark = FUN_0016DBA0((s16)*item);
    id = *item;
    if (mark != 0)
    {
        hasResource = FUN_001717C0(id);
        if (hasResource == 0)
        {
            hasResource = FUN_00172160(id);
            if (hasResource == 0)
            {
                hCampMainDrawValue(param_1 - 2.0f, (s32)(189.0f + position.x - 60.0f),
                             (s32)(position.y + 65.0f), 0xFFFFFFFF, 1, 10, 7,
                             D_005D6FEE[id * 0x0C + mark]);
            }
            else
            {
                hCampMainDrawValue(param_1 - 2.0f, (s32)(189.0f + position.x - 60.0f),
                             (s32)(position.y + 65.0f), 0xFFFFFFFF, 1, 10, 7,
                             D_005D7006[id * 0x0C]);
            }
        }
        else
        {
            hCampMainDrawValue(param_1 - 2.0f, (s32)(189.0f + position.x - 60.0f),
                         (s32)(position.y + 65.0f), 0xFFFFFFFF, 1, 10, 7,
                         D_005D7004[id * 0x0C]);
        }
    }

    id = *item;
    if (id == 0 || id == 0x1D)
    {
        mark = FUN_0016DBA0((s16)id);
        level = D_00833A60[(s32)param_7];
        rowY = position.y + 334.0f;
        campDrawSprite(D_00833B58, 0x1F, 0,
                       332.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
        campDrawSprite(D_00833B58, 0x20, 0,
                       667.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
        if (mark != 0)
        {
            hCampMainDrawValueGlyph(param_1 - 2.0f, (s32)(345.0f + position.x - 60.0f),
                         (s32)(position.y + 333.0f), 0xFFFFFFFF, 1, 10, 0, 7,
                         D_005D72AA[level * 10 + mark]);
        }
    }
    else
    {
        mark = FUN_0016DBA0((s16)id);
        reward = D_005DBB00[(s32)param_7 + id * 3];
        rowY = position.y + 334.0f;
        campDrawSprite(D_00833B58, 0x1F, 0,
                       332.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
        campDrawSprite(D_00833B58, 0x20, 0,
                       667.0f + position.x - 60.0f, rowY, param_1 - 2.0f);
        if (mark != 0)
        {
            hCampMainDrawValueGlyph(param_1 - 2.0f, (s32)(345.0f + position.x - 60.0f),
                         (s32)(position.y + 333.0f), 0xFFFFFFFF, 1, 10, 0, 7,
                         D_005D72AA[reward * 10 + mark]);
        }
    }

    iGpffffb27c++;
    if (iGpffffb27c > 0x1C0)
    {
        iGpffffb27c = 0;
    }
    x = 636.0f + position.x - 60.0f;
    campDrawSprite(D_00833B60, 0, (u8)param_7, x,
                   position.y + 199.0f + (f32)iGpffffb27c, param_1 - 3.0f);
    campDrawSprite(D_00833B60, 1, (u8)param_7, x,
                   position.y + (f32)iGpffffb27c, param_1 - 3.0f);
    campDrawSprite(D_00833B60, 0, (u8)param_7, x,
                   position.y + 199.0f + (f32)iGpffffb27c - 448.0f,
                   param_1 - 3.0f);
    campDrawSprite(D_00833B60, 1, (u8)param_7, x,
                   position.y + (f32)iGpffffb27c - 448.0f, param_1 - 3.0f);
}
#undef D_00833B44
#undef D_00833B58
#undef D_00833B60
#undef D_00833B64
#undef D_00833B68
#undef D_00833BA4

// FUN_0013BCB0
const char* FUN_0013BCB0(s32 param_1, s32 param_2)
{
    return (D_005D80E4 + param_1 * 10)[param_2];
}

// FUN_0013BCE0
void FUN_0013BCE0(u8 param_1)
{
    CampSpriteRecord* firstSprite;
    CampSpriteRecord* secondSprite;
    s32 shifted;
    f32 shiftedPosition;
    f32 position;
    if (iGpffffb2a0 < -100)
    {
        shifted = iGpffffb2a0 + 0x2D0;
        shiftedPosition = (f32)shifted;
        firstSprite = (CampSpriteRecord*)FUN_001158B0(0, DAT_00833A50[0], 0x3A);
        firstSprite->spriteScale = 104.0f;
        firstSprite->x = shiftedPosition;
        firstSprite->y = 309.0f;
        firstSprite->alpha = param_1;
        FUN_001127D0(firstSprite, 1);
        FUN_00115980(firstSprite);
    }

    position = (f32)iGpffffb2a0;
    secondSprite = (CampSpriteRecord*)FUN_001158B0(0, DAT_00833A50[0], 0x3A);
    secondSprite->spriteScale = 104.0f;
    secondSprite->x = position;
    secondSprite->y = 309.0f;
    secondSprite->alpha = param_1;
    FUN_001127D0(secondSprite, 1);
    FUN_00115980(secondSprite);

    iGpffffb2a0--;
    if ((f32)iGpffffb2a0 < -720.0f)
    {
        position = (f32)iGpffffb2a0;
        position += 720.0f;
        iGpffffb2a0 = (s32)position;
    }
}

// FUN_0013BE50 NONMATCHING
s32 FUN_0013BE50(u8* param_1, s32 param_2)
{
    s32 total;
    s32 byteOffset;
    s32 cursor;
    s32 i;
    s32 j;
    s32 count;
    s32 changed;
    s32 itemId;
    u16 partyId;
    void* item;
#define entries ((CampMainListEntry*)(param_1 + 0x0C))

    total = *(s32*)((u8*)param_1 + 0x970) + *(s32*)((u8*)param_1 + 0x974);
    byteOffset = total * 8;
    itemId = *(s32*)(param_1 + byteOffset + 0x0C);
    item = func_00170e90((s16)itemId);
    changed = 0;

    if (param_2 == -2)
    {
        if (FUN_0017BC20(1, 1, *(u16*)((u8*)item + 8), 1) == 0)
        {
            changed = 1;
            FUN_0017B860(1, 1, *(u16*)((u8*)item + 8), 1);
        }
        for (i = 0; i < 3; i++)
        {
            if (datGetPartyId(i) != 0)
            {
                if (K_FldEvent_IsCharNearHeroBeforeBtl(datGetPartyId(i)) != 0)
                {
                    partyId = (u16)datGetPartyId(i);
                    if (FUN_0017BC20(1, partyId, *(u16*)((u8*)item + 8), 1) == 0)
                    {
                        changed = 1;
                        FUN_0017B860(1, partyId, *(u16*)((u8*)item + 8), 1);
                    }
                }
            }
        }
    }
    else if (param_2 == 0)
    {
        if (FUN_0017BC20(1, 1, *(u16*)((u8*)item + 8), 1) == 0)
        {
            changed = 1;
            FUN_0017B860(1, 1, *(u16*)((u8*)item + 8), 1);
        }
    }
    else
    {
        count = 0;
        for (j = 0; j < 3; j++)
        {
            if (datGetPartyId(j) != 0)
            {
                count++;
                if (param_2 == count)
                {
                    if (K_FldEvent_IsCharNearHeroBeforeBtl(datGetPartyId(j)) != 0)
                    {
                        partyId = (u16)datGetPartyId(j);
                        if (FUN_0017BC20(1, partyId, *(u16*)((u8*)item + 8), 1) == 0)
                        {
                            changed = 1;
                            FUN_0017B860(1, partyId, *(u16*)((u8*)item + 8), 1);
                        }
                    }
                    break;
                }
            }
        }
    }

    if (changed != 0)
    {
        cursor = *(s32*)(param_1 + byteOffset + 0x10);
        if (cursor == 1)
        {
            func_00170860(1, (s16)itemId, 0);
            for (i = total; i < *(s32*)((u8*)param_1 + 0x96C) - 1; i++)
            {
                entries[i] = entries[i + 1];
            }
            entries[*(s32*)(param_1 + 0x96C)].itemId = -1;
            entries[*(s32*)(param_1 + 0x96C)].cursor = 0;
            count = *(s32*)((u8*)param_1 + 0x96C) - 1;
            *(s32*)((u8*)param_1 + 0x96C) = count;
            if (count == 0)
            {
                *(s32*)((u8*)param_1 + 0x974) = 0;
                *(s32*)((u8*)param_1 + 0x970) = 0;
            }
            else if (*(s32*)((u8*)param_1 + 0x970) < count)
            {
                if (count < 5)
                {
                    *(s32*)((u8*)param_1 + 0x974) = 0;
                }
                else if (count - 5 < *(s32*)((u8*)param_1 + 0x974))
                {
                    *(s32*)((u8*)param_1 + 0x974) = count - 5;
                }
            }
            else
            {
                *(s32*)((u8*)param_1 + 0x970) = count - 1;
                *(s32*)((u8*)param_1 + 0x974) = 0;
            }
        }
        else
        {
            *(s32*)(param_1 + byteOffset + 0x10) = cursor - 1;
            func_00170860(1, (s16)itemId,
                          *(u16*)(param_1 + byteOffset + 0x10));
        }
    }
    return changed;
#undef entries
}
