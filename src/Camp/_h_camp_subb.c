#include "Utils.h"
#include "Main/Game/game_support.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datPersona.h"

/*
 * Camp equipment records are 0x24 bytes.  The work object keeps 0x15 category
 * counters at +0x0c, records at +0x64, and its list cursor at the tail.
 * Keeping these offsets in one layout makes the rendering code auditable.
 */
typedef struct CampEquipmentEntry
{
    u32 itemId;                 /* +0x00 */
    s32 sourceIndex;            /* +0x04 */
    u8 reserved08[4];           /* +0x08 */
    u32 ownedFlag;              /* +0x0c */
    u32 availableFlag;          /* +0x10 */
    u32 categoryMask;           /* +0x14 */
    u8 effect;                  /* +0x18 */
    u8 slotType;                /* +0x19 */
    u8 equipmentClass;          /* +0x1a */
    u8 reserved1b;              /* +0x1b */
    u16 valueA;                 /* +0x1c */
    u16 valueB;                 /* +0x1e */
    u16 valueC;                 /* +0x20 */
    u16 valueD;                 /* +0x22 */
} CampEquipmentEntry;
typedef struct CampEquipmentTargetEntry
{
    u32 itemId;
    s32 sourceIndex;
    u8 reserved08[0x0c];
    u32 categoryMask;
    u8 effect;
    u8 slotType;
    u8 equipmentClass;
    u8 reserved1b;
    u16 valueA;
    u16 valueB;
    u16 valueC;
    u16 valueD;
} CampEquipmentTargetEntry;

typedef struct CampEquipmentSlotAtBase
{
    u8 reserved00[0x64];
    CampEquipmentTargetEntry entry;
} CampEquipmentSlotAtBase;


typedef struct CampEquipmentRecord24
{
    u8 reserved00[0x68];
    s32 sourceIndex;
} CampEquipmentRecord24;

typedef struct CampEquipmentWork
{
    u8 reserved00[0x0c];
    u32 categoryCounts[0x15];   /* +0x0c */
    u32 reserved60;             /* +0x60 */
    CampEquipmentEntry entries[0x15]; /* +0x64 */
    u8 reservedTail[0x2d64 - 0x64 - 0x24 * 0x15];
    s32 entryCount;             /* +0x2d64 */
    s32 selectedEntry;          /* +0x2d68 */
    s32 firstVisibleEntry;      /* +0x2d6c */
} CampEquipmentWork;

typedef struct CampEquipmentWork24View
{
    u8 reserved00[0x2d64];
    s32 entryCount;
    s32 selectedEntry;
    s32 firstVisibleEntry;
} CampEquipmentWork24View;

typedef struct CampEquipmentPanelWork
{
    u8 reserved00[0x1c];
    s32 visibleCount;           /* +0x1c */
    u8 reserved20[0x30];
    s32 listCount;              /* +0x50 */
    s32 selectedSlot;           /* +0x54 */
    s32 highlightedSlot;        /* +0x58 */
    u8 reserved5c[0x48];
    CampEquipmentWork* equipmentList;       /* +0xa4 */
    CampEquipmentWork* equipmentListAlt;    /* +0xa8 */
    CampEquipmentWork* equipmentListDetail; /* +0xac */
    u8 reservedB0[0x0c];
    u8* drawBuffer;             /* +0xbc */
    u8* statusBuffer;           /* +0xc0 */
} CampEquipmentPanelWork;

typedef struct CampEquipmentDetailEntry
{
    u32 itemId;                 /* +0x00 */
    u32 value;                  /* +0x04 */
} CampEquipmentDetailEntry;

typedef struct CampEquipmentDetailWork
{
    u8 reserved00[0x0c];
    CampEquipmentDetailEntry entries[0x12c];
    s32 entryCount;             /* +0x96c */
    s32 selectedEntry;          /* +0x970 */
    s32 firstVisibleEntry;      /* +0x974 */
} CampEquipmentDetailWork;

typedef struct CampEquipmentMenuWork
{
    u8 reserved00[0x0c];
    u32 categoryValues[4];       /* +0x0c */
    u8 reserved1c[0x38];
    s32 selectedSlot;            /* +0x54 */
    s32 highlightedSlot;         /* +0x58 */
    u8 reserved5c[0x48];
    CampEquipmentDetailWork* detailList; /* +0xa4 */
    CampEquipmentWork* equipmentList;    /* +0xa8 */
    CampEquipmentWork* equipmentListAlt; /* +0xac */
} CampEquipmentMenuWork;

static CampEquipmentDetailEntry* campDetailEntry(CampEquipmentDetailWork* work, s32 index)
{
    return &work->entries[index];
}
static s16 campMenuCategoryValue(const CampEquipmentMenuWork* menu, s32 index)
{
    return *(const s16*)((const u8*)menu + 0x0c + index * 4);
}

typedef struct CampEquipmentDrawItem
{
    u8 reserved00[0x24];
    void* texture;                /* +0x24 */
    u8 reserved28[0x10];
    f32 x;                        /* +0x38 */
    f32 y;                        /* +0x3c */
    u32 alpha;                    /* +0x40 */
} CampEquipmentDrawItem;

static CampEquipmentEntry* campEquipmentEntry(CampEquipmentWork* work, s32 index)
{
    return &work->entries[index];
}
static u32 campEquipmentEffectAndId(const CampEquipmentEntry* entry)
{
    return ((u32)entry->effect << 16) | (entry->itemId & 0xffff);
}

typedef struct CampPair
{
    f32 x;
    f32 y;
} CampPair;

typedef struct CampEquipmentResourceRecord
{
    u8 reserved00[8];
    u16 itemId;                  /* +0x08 */
} CampEquipmentResourceRecord;

static u16 campEquipmentResourceItem(const void* resource)
{
    return ((const CampEquipmentResourceRecord*)resource)->itemId;
}

#define campTextureAsFloat(item) (*(f32*)&(item)->texture)

static f32 campPackedX(u64 position)
{
    return (f32)(u32)position;
}

static f32 campPackedY(u64 position)
{
    return (f32)(u32)(position >> 32);
}

static inline u32 campSubbFloatBits(f32 value)
{
    union
    {
        f32 value;
        u32 bits;
    } converted;
    converted.value = value;
    return converted.bits;
}

#define CAMP_SUBB_PAIR_FLOAT_HIGH(high, low) \
    (((u64)campSubbFloatBits(high) << 32) | (u32)(low))
#define CAMP_SUBB_PAIR_FLOATS(high, low) \
    (((u64)campSubbFloatBits(high) << 32) | campSubbFloatBits(low))

/* Canonical APIs recovered in Main/g_data.c and datPersona.c. */
extern void* H_Maestro_001120a0(s32 font);
extern void* func_00170e90(s16 id);
extern void* func_00170ed0(s16 id, s32* category);
extern const char* func_00171110(s16 id, s16 field);
extern u32 func_00171250(s16 id);
extern u16 func_001712d0(s16 id);
extern const char* FUN_00173220(u16 personaId);
extern const char* FUN_00177790(s16 id);
extern u32 FUN_0016c470(u16 id);
extern u32 FUN_0016c4f0(u16 id);
extern u32 FUN_0016c570(u16 id);
extern u32 FUN_0016c5f0(u16 id);

extern s16 FUN_0016c920(u16 id);
extern u32 FUN_0016c970(u16 id);
extern const char* FUN_0017b100(u16 id);
extern s32 FUN_0017bf70(u16 id);
extern s8 FUN_0017bfa0(u16 id, u8 field);
#pragma alias campDrawSprite FUN_001159f0
extern void campDrawSprite(void* parent, void* resource, s32 frame,
                           u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campDrawSpriteDirect FUN_001159f0
extern void campDrawSpriteDirect(f32 x, f32 y, f32 scale);
#pragma alias campDrawSpriteDigit FUN_00115ad0
extern void campDrawSpriteDigit(void* parent, void* resource, s32 frame,
                                u32 alpha, f32 x, f32 y, f32 scale);
extern void campDrawGauge(f32 scale, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
#pragma alias campDrawGauge FUN_00113a30
#pragma alias campDrawTextAlt FUN_003b32d0
extern void campDrawTextAlt(s32 x, s32 y, u32 color, f32 scale,
                            u32 font, u32 alignment, const char* text,
                            u32 maxWidth, u32 shadow);
#pragma alias campDrawSpriteAlt FUN_00115bc0
extern void campDrawSpriteAlt(void* parent, void* resource, s32 frame,
                              u32 alpha, s32 red, s32 green, s32 blue,
                              f32 x, f32 y, f32 scale);
#pragma alias campDrawText FUN_003b2cb0
extern void campDrawText(f32 scale, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
#pragma alias campDrawValue FUN_003c7e20
extern void campDrawValue(f32 scale, s32 x, s32 y, u32 color, u32 font,
                          u32 alignment, u32 style, u32 value);
extern s32 FUN_0012df50(u32 mask);
extern void* DAT_00833A50[];
extern void* DAT_00833B70;
extern void FUN_003c7e20(void* texture, s32 x, s32 y, u32 color, u32 font,
                         u32 alignment, u32 style, u32 value);
extern void FUN_003b2cb0(void* texture, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
extern int sprintf(char* buffer, const char* format, ...);
extern void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame);
extern void qsort(void* base, u32 count, u32 width,
                  int (*compare)(const void*, const void*));
static void campEquipmentDrawFixed(f32 scale, u32 alpha, s32 frame,
                                   f32 x, f32 y)
{
    campDrawSprite((void*)(u32)scale, DAT_00833A50[0], frame, alpha,
                   x, y, scale);
}

static void campEquipmentDrawAtlas(f32 scale, u32 alpha, s32 frame,
                                   f32 x, f32 y)
{
    campDrawSprite((void*)(u32)scale, DAT_00833B70, frame, alpha,
                   x, y, scale);
}

static void campEquipmentDrawAlt(f32 scale, u32 alpha, s32 frame,
                                 f32 x, f32 y)
{
    campDrawSpriteAlt((void*)(u32)scale, DAT_00833B70, frame, alpha,
                      0x20, 0x43, 0x78, x, y, scale);
}

static void campEquipmentDrawDigit(f32 scale, u32 alpha, s32 font,
                                   s32 frame, f32 x, f32 y)
{
    campDrawSprite((void*)(u32)scale, H_Maestro_001120a0(font), frame, alpha,
                   x, y, scale);
}
extern char DAT_007cb66c[];
extern u16 DAT_007cdf94;

static int campCompareEquipmentIndex(const void* left, const void* right)
{
    u16 leftIndex = *(const u16*)left;
    u16 rightIndex = *(const u16*)right;
    u16 leftId = datGetEquipmentId(1, leftIndex);
    u16 rightId = datGetEquipmentId(1, rightIndex);

    if (leftId < rightId) {
        return -1;
    }
    if (leftId > rightId) {
        return 1;
    }
    return 0;
}


static u32 campFirstSetBit(u32 mask)
{
    u32 bit;

    for (bit = 0; bit < 32; bit++) {
        if ((mask & (1u << bit)) != 0) {
            return bit;
        }
    }
    return 0;
}

static u32 campEquipmentFirstCategory(s16 equipmentId)
{
    s32 category;
    u32* values = (u32*)func_00170ed0(equipmentId, &category);
    u32 categoryMask;

    if (category == 3) {
        categoryMask = values[0];
    } else if (category == 2 || category == 1 || category == 0) {
        categoryMask = values[1];
    } else {
        return 0;
    }
    return campFirstSetBit(categoryMask);
}


static void campEquipmentSetStats(CampEquipmentEntry* entry, s16 pcId, s32 equipmentIndex)
{
    switch (entry->equipmentClass) {
    case 0:
        entry->valueA = func_0016f9f0(pcId, equipmentIndex);
        entry->valueB = func_0016fae0(pcId, equipmentIndex);
        break;
    case 1:
        entry->valueC = func_0016fbd0(pcId, equipmentIndex);
        break;
    case 2:
        entry->valueD = func_0016fcc0(pcId, equipmentIndex);
        break;
    default:
        break;
    }
}

static void campEquipmentPopulate(CampEquipmentEntry* entry, s16 pcId,
                                   s32 equipmentIndex)
{
    entry->itemId = datGetEquipmentId(pcId, equipmentIndex);
    entry->categoryMask = func_0016f720(pcId, equipmentIndex);
    entry->equipmentClass = (u8)func_00171250((s16)entry->itemId);
    entry->effect = datGetEquipmentEffect(pcId, equipmentIndex);
    entry->slotType = func_0016f810(pcId, equipmentIndex);
    entry->sourceIndex = equipmentIndex;
    campEquipmentSetStats(entry, pcId, equipmentIndex);
}

static void campEquipmentPopulateWithCategory(CampEquipmentEntry* entry, s16 pcId,
                                              s32 equipmentIndex, u32 category)
{
    campEquipmentPopulate(entry, pcId, equipmentIndex);
    entry->categoryMask = category;
}

static void campEquipmentClearCategoryCounts(CampEquipmentWork* work)
{
    s32 category;
    for (category = 0; category < 0x15; category++) {
        work->categoryCounts[category] = 0;
    }
}

// FUN_0013c240 NONMATCHING
void FUN_0013c240(CampEquipmentWork* work, s16 pcId, s16 equipmentType)
{
    u16 indices[304];
    s32 count = 0;
    s32 scan = 0;
    s32 outCount;
    s32 index;
    s32 category;
    s16 selected;
    s16 candidate;
    u32 categoryBit;
    s32 expectedType;

    while (scan < 300) {
        if (datGetEquipmentId(1, scan) != 0) {
            indices[count] = (u16)scan;
            count++;
        }
        scan++;
    }
    if (count >= 2) {
        qsort(indices, count, 2, campCompareEquipmentIndex);
    }

    categoryBit = 0x20u << ((pcId - 1) & 31);
    outCount = 0;
    selected = datGetEquipmentIdx(pcId, equipmentType);
    work->entries[0].itemId = datGetEquipmentId(pcId, selected);
    work->entries[0].categoryMask = func_0016f720(pcId, selected);
    work->entries[0].equipmentClass = (u8)func_00171250((s16)work->entries[0].itemId);
    work->entries[0].effect = datGetEquipmentEffect(pcId, selected);
    work->entries[0].slotType = func_0016f810(pcId, selected);
    work->entries[0].sourceIndex = selected;
    switch (work->entries[0].equipmentClass) {
    case 0:
        work->entries[0].valueA = func_0016f9f0(pcId, selected);
        work->entries[0].valueB = func_0016fae0(pcId, selected);
        break;
    case 1:
        work->entries[0].valueC = func_0016fbd0(pcId, selected);
        break;
    case 2:
        work->entries[0].valueD = func_0016fcc0(pcId, selected);
        break;
    default:
        break;
    }
    outCount++;

    expectedType = equipmentType;
    index = 0;
    while (index < count) {
        u32 categoryMask;
        candidate = (s16)indices[index];
        if (datGetEquipmentId(1, candidate) != 0) {
            categoryMask = func_001712d0((s16)datGetEquipmentId(1, candidate));
            if ((categoryMask & categoryBit) != 0 &&
                (s16)func_00171250((s16)datGetEquipmentId(1, candidate)) == expectedType &&
                candidate != datGetEquipmentIdx(1, equipmentType)) {
                work->entries[outCount].itemId = datGetEquipmentId(1, candidate);
                work->entries[outCount].categoryMask = func_0016f720(1, indices[index]);
                work->entries[outCount].equipmentClass =
                    (u8)func_00171250((s16)work->entries[outCount].itemId);
                work->entries[outCount].effect = datGetEquipmentEffect(1, indices[index]);
                work->entries[outCount].slotType = func_0016f810(1, indices[index]);
                work->entries[outCount].sourceIndex = indices[index];
                switch (work->entries[outCount].equipmentClass) {
                case 0:
                    work->entries[outCount].valueA =
                        func_0016f9f0(1, indices[index]);
                    work->entries[outCount].valueB =
                        func_0016fae0(1, indices[index]);
                    break;
                case 1:
                    work->entries[outCount].valueC =
                        func_0016fbd0(1, indices[index]);
                    break;
                case 2:
                    work->entries[outCount].valueD =
                        func_0016fcc0(1, indices[index]);
                    break;
                default:
                    break;
                }
                outCount++;
            }
        }
        index++;
    }
    category = 0;
    while (category < 0x15) {
        work->categoryCounts[category] = 0;
        category++;
    }
    work->entryCount = outCount;
}

// FUN_0013c6a0 NONMATCHING
u32 FUN_0013c6a0(s16 equipmentId)
{
    s32 category;
    u32* values = (u32*)func_00170ed0(equipmentId, &category);
    u32 categoryMask;
    s32 bit;
    s32 one;

    if (category == 3) {
        goto category3;
    }
    if (category == 2) {
        goto category2;
    }
    if (category == 1) {
        goto category1;
    }
    switch (category) {
    case 0:
        goto category0;
    default:
        goto invalid;
    }

category0:
    categoryMask = values[1];
    goto found;
category1:
    categoryMask = values[1];
    goto found;
category2:
    categoryMask = values[1];
    goto found;
category3:
    categoryMask = values[0];
    goto found;
invalid:
    return 0;
found:
    bit = 0;
    one = 1;
    for (; bit < 32; bit++) {
        if ((categoryMask & (one << bit)) != 0) {
            return bit;
        }
    }
    return 0;
}

// FUN_0013c780 NONMATCHING
void FUN_0013c780(CampEquipmentWork* work)
{
    u16 candidateIndices[304];
    s32 candidateCount = 0;
    s32 scanIndex = 0;
    s32 recordCount;
    s32 index;
    s32 category;
    s16 candidate;
    CampEquipmentEntry* entry;
    u16* candidatePtr;
    u8* classPtr;
    u32* availablePtr;
    u32* categoryCounts;
    u32 categoryMask;

    while (scanIndex < 300) {
        if (datGetEquipmentId(1, scanIndex) != 0) {
            candidateIndices[candidateCount] = (u16)scanIndex;
            candidateCount++;
        }
        scanIndex++;
    }
    if (candidateCount >= 2) {
        qsort(candidateIndices, candidateCount, 2, campCompareEquipmentIndex);
    }
    recordCount = 0;

    scanIndex = 0;
    while (scanIndex < 0x14) {
        if (datGetEquipmentId(-1, scanIndex) != 0) {
            entry = &work->entries[recordCount];
            classPtr = &entry->equipmentClass;
            entry->itemId = datGetEquipmentId(-1, scanIndex);
            entry->categoryMask = FUN_0013c6a0((s16)entry->itemId);
            *classPtr = (u8)func_00171250((s16)entry->itemId);
            entry->effect = datGetEquipmentEffect(-1, scanIndex);
            entry->slotType = func_0016f810(-1, scanIndex);
            entry->sourceIndex = scanIndex + 0x1000;
            entry->ownedFlag = 1;
            entry->availableFlag = 1;
            switch (*classPtr) {
            case 0:
                entry->valueA = func_0016f9f0(-1, scanIndex);
                entry->valueB = func_0016fae0(-1, scanIndex);
                break;
            case 1:
                entry->valueC = func_0016fbd0(-1, scanIndex);
                break;
            case 2:
                entry->valueD = func_0016fcc0(-1, scanIndex);
                break;
            default:
                break;
            }
            recordCount++;
        }
        scanIndex++;
    }

    categoryCounts = work->categoryCounts;
    categoryCounts[0] = recordCount;
    index = 0;
    while (index < candidateCount) {
        candidatePtr = &candidateIndices[index];
        candidate = (s16)*candidatePtr;
        if (datGetEquipmentId(1, candidate) != 0) {
            entry = &work->entries[recordCount];
            availablePtr = &entry->availableFlag;
            classPtr = &entry->equipmentClass;
            candidatePtr = &candidateIndices[index];
            entry->itemId = datGetEquipmentId(1, (s16)*candidatePtr);
            categoryMask = func_0016f720(1, (s16)*candidatePtr);
            category = 0;
            while (category < 0x15) {
                if ((categoryMask & (1u << category)) != 0) {
                    entry->categoryMask = category;
                    break;
                }
                category++;
            }
            *classPtr = (u8)func_00171250((s16)entry->itemId);
            entry->effect = datGetEquipmentEffect(1, (s16)*candidatePtr);
            entry->slotType = func_0016f810(1, (s16)*candidatePtr);
            entry->sourceIndex = *candidatePtr;
            entry->ownedFlag = 0;
            *availablePtr = 1;
            if (candidate == datGetEquipmentIdx(1, 0) ||
                candidate == datGetEquipmentIdx(1, 1) ||
                candidate == datGetEquipmentIdx(1, 2) ||
                candidate == datGetEquipmentIdx(1, 3)) {
                *availablePtr = 0;
            }
            switch (*classPtr) {
            case 0:
                entry->valueA = func_0016f9f0(1, (s16)*candidatePtr);
                entry->valueB = func_0016fae0(1, (s16)*candidatePtr);
                break;
            case 1:
                entry->valueC = func_0016fbd0(1, (s16)*candidatePtr);
                break;
            case 2:
                entry->valueD = func_0016fcc0(1, (s16)*candidatePtr);
                break;
            default:
                break;
            }
            recordCount++;
        }
        index++;
    }

    category = 0;
    while (category < 0x15) {
        categoryCounts[category] = 0;
        category++;
    }
    work->entryCount = recordCount;
}

// FUN_0013cc90 NONMATCHING
void FUN_0013cc90(CampEquipmentWork* work)
{
    u16 indices[300];
    s32 count = 0;
    s32 scan = 0;
    s32 recordCount = 0;
    s32 index;
    s32 category;
    s16 candidate;
    u32 mask;
    CampEquipmentEntry* entry;
    u16* candidatePtr;

    while (scan < 300) {
        if (datGetEquipmentId(1, scan) != 0) {
            indices[count] = (u16)scan;
            count++;
        }
        scan++;
    }
    if (count >= 2) {
        qsort(indices, count, 2, campCompareEquipmentIndex);
    }

    index = 0;
    while (index < count) {
        candidatePtr = &indices[index];
        candidate = (s16)*candidatePtr;
        if (datGetEquipmentId(1, candidate) != 0) {
            entry = &work->entries[recordCount];
            entry->itemId = datGetEquipmentId(1, candidate);
            category = 0;
            mask = func_0016f720(1, candidate);
            while (category < 0x15) {
                if ((mask & (1u << category)) != 0) {
                    entry->categoryMask = category;
                    break;
                }
                category++;
            }
            entry->equipmentClass = (u8)func_00171250((s16)entry->itemId);
            entry->effect = datGetEquipmentEffect(1, candidate);
            entry->slotType = func_0016f810(1, candidate);
            entry->sourceIndex = candidate;
            switch (entry->equipmentClass) {
            case 0:
                entry->valueA = func_0016f9f0(1, candidate);
                entry->valueB = func_0016fae0(1, candidate);
                break;
            case 1:
                entry->valueC = func_0016fbd0(1, candidate);
                break;
            case 2:
                entry->valueD = func_0016fcc0(1, candidate);
                break;
            default:
                break;
            }
            recordCount++;
        }
        index++;
    }

    category = 0;
    while (category < 0x15) {
        work->categoryCounts[category] = 0;
        category++;
    }
    work->entryCount = recordCount;
}

// FUN_0013cf80
void FUN_0013cf80(u64 pcId, CampEquipmentWork* work)
{
    s32 equipmentType;
    s32 recordCount = 0;
    s32 category;
    u32 categoryBit;
    CampEquipmentSlotAtBase* slot;
    CampEquipmentTargetEntry* entry;
    u8* classPtr;

    for (category = 0; category < 0x15; category++) {
        *(u32*)(category * 4 + (u8*)work + 0x0c) = recordCount;
        categoryBit = 1u << category;
        for (equipmentType = 0; equipmentType < 4; equipmentType++) {
            if ((func_0016f720(pcId, equipmentType) & categoryBit) != 0) {
                slot = (CampEquipmentSlotAtBase*)(recordCount * 9 * 4 +
                                                  (u8*)work);
                entry = &slot->entry;
                entry->itemId = datGetEquipmentId(pcId, equipmentType);
                slot->entry.categoryMask = category;
                classPtr = &slot->entry.equipmentClass;
                *classPtr = (u8)func_00171250((s16)entry->itemId);
                slot->entry.effect = datGetEquipmentEffect(pcId, equipmentType);
                slot->entry.slotType = func_0016f810(pcId, equipmentType);
                slot->entry.sourceIndex = equipmentType;
                switch (*classPtr) {
                case 0:
                    *(u16*)((u8*)work + recordCount * 9 * 4 + 0x80) =
                        func_0016f9f0(pcId, equipmentType);
                    *(u16*)((u8*)work + recordCount * 9 * 4 + 0x82) =
                        func_0016fae0(pcId, equipmentType);
                    break;
                case 1:
                    slot->entry.valueC = func_0016fbd0(pcId, equipmentType);
                    break;
                case 2:
                    slot->entry.valueD = func_0016fcc0(pcId, equipmentType);
                    break;
                case 3:
                    break;
                default:
                    break;
                }
                recordCount++;
            }
        }
    }
    work->entryCount = recordCount;
}
 
#pragma optimization_level 2
// Inline macro overrides: expand helpers to direct campDrawSprite calls.
#undef campEquipmentDrawFixed
#define campEquipmentDrawFixed(scale,alpha,frame,x,y) \
    campDrawSprite((void*)(u32)(scale),DAT_00833A50[0],(frame),(u32)(alpha),(x),(y),(scale))
#undef campEquipmentDrawAtlas
#define campEquipmentDrawAtlas(scale,alpha,frame,x,y) \
    campDrawSprite((void*)(u32)(scale),DAT_00833B70,(frame),(u32)(alpha),(x),(y),(scale))
#undef campEquipmentDrawAlt
#define campEquipmentDrawAlt(scale,alpha,frame,x,y) \
    campDrawSpriteAlt((void*)(u32)(scale),DAT_00833B70,(frame),(u32)(alpha),0x20,0x43,0x78,(x),(y),(scale))
#undef campEquipmentDrawDigit
#define campEquipmentDrawDigit(scale,alpha,font,frame,x,y) \
    campDrawSprite((void*)(u32)(scale),H_Maestro_001120a0(font),(frame),(u32)(alpha),(x),(y),(scale))
#define campEquipmentEntry(work,index) (&(work)->entries[(index)])
 
// FUN_0013d1a0 NONMATCHING

void FUN_0013d1a0(f32 texture,u64 position,CampEquipmentWork* work,s32 alpha)

{
  char category;
  u16 value;
  u32 color;
  const char* textValue;
  int rowIndex;
  s32 entryIndex;
  int textureIndex;
  float xBase;
  float xMarker;
  float yBase;
  float xValue;
  float yValue;
  float xIcon;
  float xRow;
  float yValue2;
  float yValue3;
  float originX;
  float originY;
  char textBuffer[256];
  
  originX = campPackedX(position);
  originY = campPackedY(position);
  if (work->entryCount != 0) {
    campEquipmentDrawFixed(texture, (u32)alpha, 0x19, originX + 2.0f,
                           originY + 6.0f + (f32)(work->selectedEntry * 0x1a));
    campEquipmentDrawFixed(texture, (u32)alpha, 0x18, originX + 496.0f,
                           originY + 6.0f + (f32)(work->selectedEntry * 0x1a));
  }
  xBase = originY + 6.0f;
    campEquipmentDrawFixed(texture, (u32)alpha, 0x1a, originX + 511.0f, xBase);
  rowIndex = work->entryCount + -5;
  if (rowIndex < 1) {
    rowIndex = 0;
  }
  else {
    rowIndex = (work->firstVisibleEntry * 0x59) / rowIndex;
  }
    campEquipmentDrawFixed(texture, (u32)alpha, 0x20, originX + 511.0f,
                           xBase + (f32)rowIndex + 4.0f);
  rowIndex = 0;
  xRow = originX + 15.0f;
  color = 0xffU - alpha | 0xffffff00;
  yValue = originY + 9.0f;
  xIcon = originX + 288.0f;
  yBase = originY + 16.0f;
  xValue = originX + 325.0f;
  xBase = originX + 341.0f;
  xMarker = originX + 357.0f;
  do {
    if ((4 < rowIndex) ||
       (entryIndex = rowIndex + work->firstVisibleEntry, work->entryCount <= entryIndex)) {
      return;
    }
    if (rowIndex == work->selectedEntry) {
      textureIndex = rowIndex * 0x1a;
      campEquipmentDrawAtlas(texture, (u32)alpha,
                             campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass * 2 + 1,
                             xRow, (originY + 2.0f + (f32)textureIndex) - 1.0f);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      campDrawText(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)textureIndex + 1.0f + 1.0f),color,6,1,
                   textBuffer,0x10,0);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          campDrawSpriteDirect(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013dd14;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013dd14:
            campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013ddc4;
            yValue3 = yValue + (float)textureIndex;
            campEquipmentDrawFixed(texture, (u32)alpha, 0x2f, xIcon, yValue3);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013d8a8;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                     xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013d8a8:
              campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                     xBase, (yBase + (f32)textureIndex) - 3.0f);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0f;
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                   xMarker, yValue2);
            campEquipmentDrawFixed(texture, (u32)alpha, 0x35, originX + 404.0f, yValue3);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013da24;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                     originX + 441.0f, yValue2);
LAB_0013da24:
              campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                     originX + 457.0f, yValue2);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                   originX + 473.0f, yValue2);
            goto LAB_0013ddc4;
          }
          campEquipmentDrawFixed(texture, (u32)alpha, 0x31, xIcon,
                                 yValue + (f32)textureIndex);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013db80;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013db80:
            campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
      }
LAB_0013ddc4:
      ;
      campDrawValue(texture,(int)(originX + 10.0f),(int)(originY + 200.0f),color,1,10,1,
                   (u32)campEquipmentEffectAndId(campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)));
    }
    else {
      textureIndex = rowIndex * 0x1a;
      campEquipmentDrawAlt(texture, (u32)alpha,
                           campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass * 2,
                           xRow, (originY + 2.0f + (f32)textureIndex) - 1.0f);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      campDrawText(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)textureIndex + 1.0f),color,10,1,textBuffer,
                   0x10,0);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          campDrawSpriteDirect(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013e5e4;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013e5e4:
            campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013e694;
            yValue3 = yValue + (float)textureIndex;
            campEquipmentDrawFixed(texture, (u32)alpha, 0x2e, xIcon, yValue3);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013e178;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                     xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013e178:
              campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                     xBase, (yBase + (f32)textureIndex) - 3.0f);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0f;
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                   xMarker, yValue2);
            campEquipmentDrawFixed(texture, (u32)alpha, 0x34, originX + 404.0f, yValue3);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013e2f4;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                     originX + 441.0f, yValue2);
LAB_0013e2f4:
              campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                     originX + 457.0f, yValue2);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                   originX + 473.0f, yValue2);
            goto LAB_0013e694;
          }
          campEquipmentDrawFixed(texture, (u32)alpha, 0x30, xIcon,
                                 yValue + (f32)textureIndex);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013e450;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013e450:
            campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
      }
    }
LAB_0013e694:
    rowIndex = rowIndex + 1;
  } while( true );
}
#undef campEquipmentDrawFixed
#undef campEquipmentDrawAtlas
#undef campEquipmentDrawAlt
#undef campEquipmentDrawDigit
#undef campEquipmentEntry
 
#define campEquipmentDrawFixed(texture,alpha,frame,x,y) \
  campDrawSprite(parent,DAT_00833A50[0],(frame),(alpha),(x),(y),(texture))
#define campEquipmentDrawAtlas(texture,alpha,frame,x,y) \
  campDrawSprite(parent,DAT_00833B70,(frame),(alpha),(x),(y),(texture))
#define campEquipmentDrawAlt(texture,alpha,frame,x,y) \
  campDrawSpriteAlt(parent,DAT_00833B70,(frame),(alpha),0x20,0x43,0x78,(x),(y),(texture))
#define campEquipmentDrawDigit(texture,alpha,font,frame,x,y) \
  campDrawSprite(parent,H_Maestro_001120a0(font),(frame),(alpha),(x),(y),(texture))



// Reconstructed the retail equipment-row sprite dispatch and float-pair ABI.
// Each sprite, atlas, alternate-color, and digit call now carries its full
// resource, frame, alpha, position, and scale argument sequence.
// Retail retains an implicit parent pointer in a callee-saved register that
// is not represented by the current source signature; the remaining mismatch
// is therefore retained while preserving the recovered branch and frame logic.
// FUN_0013e710 NONMATCHING

void FUN_0013e710(CampPair position,f32 texture,CampEquipmentWork* work,s32 alpha)

{
  register void* parent;
  char textBuffer[256];
  char category;
  u16 value;
  u32 colorBase;
  u32 color;
  u32 categoryMask;
  s32 style;
  const char* textValue;
  int rowIndex;
  s32 entryIndex;
  int textureIndex;
  s32 valueX;
  s32 valueY;
  float xBase;
  float xMarker;
  float yBase;
  float xValue;
  float yValue;
  float xIcon;
  float xRow;
  float yValue2;
  float xSecondaryIcon;
  float xSecondaryHundreds;
  float xSecondaryTens;
  float xSecondaryOnes;
  float digitY;
  float yValue3;
  float originX;
  float originY;
  
  originX = position.x;
  originY = position.y;
  colorBase = 0xffU - alpha;
  if (work->entryCount != 0) {
    campEquipmentDrawFixed(texture, (u32)alpha, 0x19, originX + 2.0f,
                           originY + 6.0f + (f32)(work->selectedEntry * 0x1a));
    campEquipmentDrawFixed(texture, (u32)alpha, 0x18, originX + 496.0f,
                           originY + 6.0f + (f32)(work->selectedEntry * 0x1a));
  }
  xBase = originY + 6.0f;
  campEquipmentDrawFixed(texture, (u32)alpha, 0x1a, originX + 511.0f, xBase);
  rowIndex = work->entryCount + -5;
  if (rowIndex < 1) {
    rowIndex = 0;
  }
  else {
    rowIndex = (work->firstVisibleEntry * 0x59) / rowIndex;
  }
  campEquipmentDrawFixed(texture, (u32)alpha, 0x20, originX + 511.0f,
                         xBase + (f32)rowIndex + 4.0f);
  rowIndex = 0;
  xRow = originX + 15.0f;
  color = colorBase | 0xffffff00;
  yValue = originY + 9.0f;
  xIcon = originX + 288.0f;
  yBase = originY + 16.0f;
  xValue = originX + 325.0f;
  xBase = originX + 341.0f;
  xMarker = originX + 357.0f;
  xSecondaryIcon = originX + 404.0f;
  xSecondaryHundreds = originX + 441.0f;
  xSecondaryTens = originX + 457.0f;
  xSecondaryOnes = originX + 473.0f;
  valueX = (s32)(originX + 10.0f + 14.0f);
  valueY = (s32)((originY + 200.0f) - 40.0f);
  do {
    if ((4 < rowIndex) ||
       (entryIndex = rowIndex + work->firstVisibleEntry, work->entryCount <= entryIndex)) {
      return;
    }
    if (rowIndex == work->selectedEntry) {
      textureIndex = rowIndex * 0x1a;
      categoryMask = work->entries[work->firstVisibleEntry + rowIndex].categoryMask;
      style = 9;
      switch (categoryMask) {
      case 0:
      case 8:
        style = 0;
        break;
      case 1:
      case 9:
        style = 1;
        break;
      case 2:
      case 10:
        style = 2;
        break;
      case 3:
      case 11:
        style = 3;
        break;
      case 4:
      case 12:
        style = 4;
        break;
      case 5:
      case 13:
        style = 5;
        break;
      case 6:
      case 14:
        style = 6;
        break;
      case 7:
      case 15:
        style = 7;
        break;
      case 16:
        style = 9;
        break;
      case 17:
        style = 10;
        break;
      case 18:
        style = 11;
        break;
      case 19:
        style = 13;
        break;
      case 20:
        style = 14;
        break;
      default:
        break;
      }
      campEquipmentDrawAtlas(texture, (u32)alpha, style * 2 + 1,
                             xRow, (originY + 2.0f + (f32)textureIndex) - 1.0f);
      textValue = func_00171110((s16)work->entries[work->firstVisibleEntry + rowIndex].itemId,
                                 (s16)work->entries[work->firstVisibleEntry + rowIndex].slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      campDrawText(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)textureIndex + 1.0f + 1.0f),color,6,1,
                   textBuffer,0x10,0x78);
      category = work->entries[work->firstVisibleEntry + rowIndex].equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          campEquipmentDrawFixed(texture, (u32)alpha, 0x33, xIcon,
                                 yValue + (f32)textureIndex);
          value = work->entries[work->firstVisibleEntry + rowIndex].valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013f2a0;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013f2a0:
            campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013f350;
            yValue3 = yValue + (float)textureIndex;
            campEquipmentDrawFixed(texture, (u32)alpha, 0x2f, xIcon, yValue3);
            digitY = (yBase + (f32)textureIndex) - 3.0f;
            value = work->entries[work->firstVisibleEntry + rowIndex].valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013ee34;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                     xValue, digitY);
LAB_0013ee34:
              campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                     xBase, digitY);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                   xMarker, digitY);
            campEquipmentDrawFixed(texture, (u32)alpha, 0x35, xSecondaryIcon, yValue3);
            value = work->entries[work->firstVisibleEntry + rowIndex].valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013efb0;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                     xSecondaryHundreds, digitY);
LAB_0013efb0:
              campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                     xSecondaryTens, digitY);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                   xSecondaryOnes, digitY);
            goto LAB_0013f350;
          }
          campEquipmentDrawFixed(texture, (u32)alpha, 0x31, xIcon,
                                 yValue + (f32)textureIndex);
          value = work->entries[work->firstVisibleEntry + rowIndex].valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013f10c;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 1, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013f10c:
            campEquipmentDrawDigit(texture, (u32)alpha, 1, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 1, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
      }
LAB_0013f350:
      ;
      campDrawValue(texture,valueX,valueY,color,
                    1,10,1,(u32)(((u32)work->entries[work->firstVisibleEntry + rowIndex].effect << 16) |
                                 (work->entries[work->firstVisibleEntry + rowIndex].itemId & 0xffff)));
    }
    else {
      textureIndex = rowIndex * 0x1a;
      categoryMask = work->entries[work->firstVisibleEntry + rowIndex].categoryMask;
      style = 9;
      switch (categoryMask) {
      case 0:
      case 8:
        style = 0;
        break;
      case 1:
      case 9:
        style = 1;
        break;
      case 2:
      case 10:
        style = 2;
        break;
      case 3:
      case 11:
        style = 3;
        break;
      case 4:
      case 12:
        style = 4;
        break;
      case 5:
      case 13:
        style = 5;
        break;
      case 6:
      case 14:
        style = 6;
        break;
      case 7:
      case 15:
        style = 7;
        break;
      case 16:
        style = 9;
        break;
      case 17:
        style = 10;
        break;
      case 18:
        style = 11;
        break;
      case 19:
      case 20:
        style = 13;
        break;
      default:
        break;
      }
      campEquipmentDrawAlt(texture, (u32)alpha, style * 2,
                           xRow, (originY + 2.0f + (f32)textureIndex) - 1.0f);
      ;
      textValue = func_00171110((s16)work->entries[work->firstVisibleEntry + rowIndex].itemId,
                                (s16)work->entries[work->firstVisibleEntry + rowIndex].slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      campDrawText(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)textureIndex + 1.0f),color,10,1,textBuffer,
                   0x10,0x78);
      category = work->entries[work->firstVisibleEntry + rowIndex].equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          campEquipmentDrawFixed(texture, (u32)alpha, 0x32, xIcon,
                                 yValue + (f32)textureIndex);
          value = work->entries[work->firstVisibleEntry + rowIndex].valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013fb70;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013fb70:
            campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013fc20;
            yValue3 = yValue + (float)textureIndex;
            campEquipmentDrawFixed(texture, (u32)alpha, 0x2e, xIcon, yValue3);
            digitY = (yBase + (f32)textureIndex) - 3.0f;
            value = work->entries[work->firstVisibleEntry + rowIndex].valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013f704;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                     xValue, digitY);
LAB_0013f704:
              campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                     xBase, digitY);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                   xMarker, digitY);
            campEquipmentDrawFixed(texture, (u32)alpha, 0x34, xSecondaryIcon, yValue3);
            value = work->entries[work->firstVisibleEntry + rowIndex].valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013f880;
            }
            else {
              campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                     xSecondaryHundreds, digitY);
LAB_0013f880:
              campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                     xSecondaryTens, digitY);
            }
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                   xSecondaryOnes, digitY);
            goto LAB_0013fc20;
          }
          campEquipmentDrawFixed(texture, (u32)alpha, 0x30, xIcon,
                                 yValue + (f32)textureIndex);
          value = work->entries[work->firstVisibleEntry + rowIndex].valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013f9dc;
          }
          else {
            campEquipmentDrawDigit(texture, (u32)alpha, 2, value / 100 + 0xb,
                                   xValue, (yBase + (f32)textureIndex) - 3.0f);
LAB_0013f9dc:
            campEquipmentDrawDigit(texture, (u32)alpha, 2, (value % 100) / 10 + 0xb,
                                   xBase, (yBase + (f32)textureIndex) - 3.0f);
          }
          campEquipmentDrawDigit(texture, (u32)alpha, 2, value % 10 + 0xb,
                                 xMarker, (yBase + (f32)textureIndex) - 3.0f);
        }
      }
    }
LAB_0013fc20:
    rowIndex = rowIndex + 1;
  } while( true );
}
#undef campEquipmentDrawFixed
#undef campEquipmentDrawAtlas
#undef campEquipmentDrawAlt
#undef campEquipmentDrawDigit



// FUN_0013fca0 NONMATCHING

void FUN_0013fca0(f32 texture,u64 position,CampEquipmentWork* work,s32 alpha)
{
    register void* parent;
    CampEquipmentEntry* selectedEquipment;
    const char* textValue;
    u32 categoryMask;
    u32 color;
    u16 value;
    s32 frame;
    s32 hadHundreds;
    char category;
    f32 originX;
    f32 originY;
    f32 digitY;
    char textBuffer[256];

    selectedEquipment = &work->entries[work->firstVisibleEntry + work->selectedEntry];
    categoryMask = selectedEquipment->categoryMask;
    frame = 0x1a;
    switch (categoryMask) {
    case 0:
    case 8:
        frame = 0;
        break;
    case 1:
    case 9:
        frame = 2;
        break;
    case 2:
    case 10:
        frame = 4;
        break;
    case 3:
    case 11:
        frame = 6;
        break;
    case 4:
    case 12:
        frame = 8;
        break;
    case 5:
    case 13:
        frame = 10;
        break;
    case 6:
    case 14:
        frame = 12;
        break;
    case 7:
    case 15:
        frame = 14;
        break;
    case 16:
        frame = 18;
        break;
    case 17:
        frame = 20;
        break;
    case 18:
        frame = 22;
        break;
    case 19:
    case 20:
        frame = 26;
        break;
    default:
        break;
    }

    originX = (f32)(u32)position;
    originY = (f32)(u32)(position >> 32);
    campDrawSprite(parent, DAT_00833B70, frame + 1, (u32)alpha,
                   originX + 15.0f, originY + 1.0f, texture);
    textValue = func_00171110((s16)selectedEquipment->itemId,
                               (s16)selectedEquipment->slotType);
    sprintf(textBuffer, DAT_007cb66c, textValue);
    color = (0xffU - alpha) | 0xffffff00;
    campDrawText(texture, (s32)(originX + 55.0f),
                 (s32)(originY + 12.0f), color, 10, 1, textBuffer, 0x10, 0);

    category = selectedEquipment->equipmentClass;
    digitY = originY + 13.0f;
    if (category == 3) {
        return;
    }
    if (category == 2) {
        campDrawSprite(parent, DAT_00833A50[0], 0x32, (u32)alpha,
                       originX + 288.0f, originY + 9.0f, texture);
        value = selectedEquipment->valueD;
        hadHundreds = 0;
        if (value >= 100) {
            hadHundreds = 1;
            campDrawSprite(parent, H_Maestro_001120a0(2),
                                value / 100 + 0xb, (u32)alpha,
                                originX + 325.0f, digitY, texture);
            value %= 100;
        }
        if (value >= 10 || hadHundreds != 0) {
            campDrawSprite(parent, H_Maestro_001120a0(2),
                                value / 10 + 0xb, (u32)alpha,
                                originX + 341.0f, digitY, texture);
        }
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value % 10 + 0xb, (u32)alpha,
                            originX + 357.0f, digitY, texture);
        return;
    }
    if (category == 1) {
        campDrawSprite(parent, DAT_00833A50[0], 0x30, (u32)alpha,
                       originX + 288.0f, originY + 9.0f, texture);
        value = selectedEquipment->valueC;
        hadHundreds = 0;
        if (value >= 100) {
            hadHundreds = 1;
            campDrawSprite(parent, H_Maestro_001120a0(2),
                                value / 100 + 0xb, (u32)alpha,
                                originX + 325.0f, digitY, texture);
            value %= 100;
        }
        if (value >= 10 || hadHundreds != 0) {
            campDrawSprite(parent, H_Maestro_001120a0(2),
                                value / 10 + 0xb, (u32)alpha,
                                originX + 341.0f, digitY, texture);
        }
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value % 10 + 0xb, (u32)alpha,
                            originX + 357.0f, digitY, texture);
        return;
    }
    if (category != 0) {
        return;
    }

    campDrawSprite(parent, DAT_00833A50[0], 0x2e, (u32)alpha,
                   originX + 288.0f, originY + 9.0f, texture);
    value = selectedEquipment->valueA;
    hadHundreds = 0;
    if (value >= 100) {
        hadHundreds = 1;
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value / 100 + 0xb, (u32)alpha,
                            originX + 325.0f, digitY, texture);
        value %= 100;
    }
    if (value >= 10 || hadHundreds != 0) {
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value / 10 + 0xb, (u32)alpha,
                            originX + 341.0f, digitY, texture);
    }
    campDrawSprite(parent, H_Maestro_001120a0(2),
                        value % 10 + 0xb, (u32)alpha,
                        originX + 357.0f, digitY, texture);
    campDrawSprite(parent, DAT_00833A50[0], 0x34, (u32)alpha,
                   originX + 404.0f, originY + 9.0f, texture);
    value = selectedEquipment->valueB;
    hadHundreds = 0;
    if (value >= 100) {
        hadHundreds = 1;
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value / 100 + 0xb, (u32)alpha,
                            originX + 441.0f, digitY, texture);
        value %= 100;
    }
    if (value >= 10 || hadHundreds != 0) {
        campDrawSprite(parent, H_Maestro_001120a0(2),
                            value / 10 + 0xb, (u32)alpha,
                            originX + 457.0f, digitY, texture);
    }
    campDrawSprite(parent, H_Maestro_001120a0(2),
                        value % 10 + 0xb, (u32)alpha,
                        originX + 473.0f, digitY, texture);
}



// FUN_001406d0 NONMATCHING

void FUN_001406d0(void* texture,u64 position,CampEquipmentDetailWork* detail,s32 alpha)

{
  u32 packedValue;
  const char* textValue;
  int entryIndex;
  int variant;
  float panelX;
  float panelY;
  float panelBase;
  float originX;
  float originY;
  char textBuffer[256];
  
  originX = campPackedX(position);
  originY = campPackedY(position);
  if (detail->entryCount != 0) {
    FUN_001159f0(originX + 2.0f,originY + 6.0f + (float)(detail->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 317.0f,originY + 6.0f + (float)(detail->selectedEntry * 0x1a),
                 texture);
  }
  panelX = originX + 331.0f;
  FUN_001159f0(panelX,originY + 6.0f,texture);
  entryIndex = detail->entryCount + -5;
  if (entryIndex < 1) {
    entryIndex = 0;
  }
  else {
    entryIndex = (detail->firstVisibleEntry * 0x59) / entryIndex;
  }
  FUN_001159f0(panelX,originY + 10.0f + (float)entryIndex,texture);
  panelBase = originX + 15.0f;
  packedValue = 0xffU - alpha | 0xffffff00;
  panelY = originY + 16.0f;
  panelX = originX + 293.0f;
  for (entryIndex = 0; (entryIndex < 5 && (entryIndex + detail->firstVisibleEntry < detail->entryCount));
      entryIndex = entryIndex + 1) {
    if (entryIndex == detail->selectedEntry) {
      variant = entryIndex * 0x1a;
      FUN_001159f0(panelBase,(originY + 2.0f + (float)variant) - 1.0f,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)variant + 1.0f + 1.0f),packedValue,6,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(1);
        FUN_001159f0(originX + 277.0f,(panelY + (float)variant) - 3.0f,texture);
      }
      H_Maestro_001120a0(1);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0f,texture);
      FUN_003c7e20(texture,(int)(originX + 10.0f + 14.0f),(int)((originY + 200.0f) - 40.0f),packedValue,
                   1,10,0,campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
    }
    else {
      variant = entryIndex * 0x1a;
      FUN_00115bc0(panelBase,(originY + 2.0f + (float)variant) - 1.0f,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)variant + 1.0f + 1.0f),packedValue,10,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(2);
        FUN_001159f0(originX + 277.0f,(panelY + (float)variant) - 3.0f,texture);
      }
      H_Maestro_001120a0(2);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0f,texture);
    }
  }
  return;
}



// FUN_00140e30 NONMATCHING

void FUN_00140e30(void* texture,u64 position,CampEquipmentDetailWork* detail,s32 alpha)

{
  u32 packedValue;
  const char* textValue;
  int entryIndex;
  int variant;
  float panelX;
  float panelY;
  float panelBase;
  float originX;
  float originY;
  char textBuffer[256];
  
  originX = campPackedX(position);
  originY = campPackedY(position);
  if (detail->entryCount != 0) {
    FUN_001159f0(originX + 2.0f,originY + 6.0f + (float)(detail->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 317.0f,originY + 6.0f + (float)(detail->selectedEntry * 0x1a),
                 texture);
  }
  panelX = originX + 331.0f;
  FUN_001159f0(panelX,originY + 6.0f,texture);
  entryIndex = detail->entryCount + -5;
  if (entryIndex < 1) {
    entryIndex = 0;
  }
  else {
    entryIndex = (detail->firstVisibleEntry * 0x59) / entryIndex;
  }
  FUN_001159f0(panelX,originY + 10.0f + (float)entryIndex,texture);
  panelBase = originX + 15.0f;
  packedValue = 0xffU - alpha | 0xffffff00;
  panelY = originY + 16.0f;
  panelX = originX + 293.0f;
  for (entryIndex = 0; (entryIndex < 5 && (entryIndex + detail->firstVisibleEntry < detail->entryCount));
      entryIndex = entryIndex + 1) {
    if (entryIndex == detail->selectedEntry) {
      variant = entryIndex * 0x1a;
      FUN_001159f0(panelBase,(originY + 2.0f + (float)variant) - 1.0f,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)variant + 1.0f + 1.0f),packedValue,6,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(1);
        FUN_001159f0(originX + 277.0f,(panelY + (float)variant) - 3.0f,texture);
      }
      H_Maestro_001120a0(1);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0f,texture);
      FUN_003c7e20(texture,(int)(originX + 10.0f + 14.0f),(int)((originY + 200.0f) - 40.0f),packedValue,
                   1,10,0,campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
    }
    else {
      variant = entryIndex * 0x1a;
      FUN_00115bc0(panelBase,(originY + 2.0f + (float)variant) - 1.0f,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0f),
                   (int)((float)(int)originY + 11.0f + (float)variant + 1.0f + 1.0f),packedValue,10,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(2);
        FUN_001159f0(originX + 277.0f,(panelY + (float)variant) - 3.0f,texture);
      }
      H_Maestro_001120a0(2);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0f,texture);
    }
  }
  return;
}



static inline uintptr_t add_offset_first(uintptr_t offset, uintptr_t base)
{
    return offset + base;
}

// FUN_00141590

void FUN_00141590(CampEquipmentWork* work)
{
    CampEquipmentWork24View* view = (CampEquipmentWork24View*)work;
    u8* recordAddress;
    s32 firstVisibleEntry;
    s32 selectedEntry;
    s32 lastEntry;
    s32 lastVisibleEntry;

    firstVisibleEntry = view->firstVisibleEntry;
    selectedEntry = view->selectedEntry;
    recordAddress = (u8 *)add_offset_first((firstVisibleEntry + selectedEntry) * 0x24, (uintptr_t)work);
    func_0016fea0(1,
                  ((CampEquipmentRecord24*)recordAddress)->sourceIndex,
                  0);
    FUN_0013cc90(work);
    if (view->entryCount < 5) {
        view->firstVisibleEntry = 0;
        lastEntry = view->entryCount - 1;
        if (lastEntry < selectedEntry) {
            view->selectedEntry = lastEntry;
        } else {
            view->selectedEntry = selectedEntry;
        }
    } else {
        lastVisibleEntry = view->entryCount - 5;
        if (lastVisibleEntry < firstVisibleEntry) {
            view->firstVisibleEntry = lastVisibleEntry;
            view->selectedEntry = selectedEntry;
        }
    }
}



// FUN_00141660 NONMATCHING

void FUN_00141660(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  u64 spriteTopLeft;
  u64 spriteTopLeft2;
  u64 spriteTopLeft3;
  u64 spriteTopLeft4;
  u64 spriteTopLeft5;
  u64 pair0;
  u64 pair1;
  u64 pair2;
  u64 pair3;
  u64 pair4;
  u64 pair5;
  u64 pair6;
  u64 pair7;
  u64 pair8;
  u64 pairEnd;
  pair0 = 0x4140000042b40000;
  pairEnd = 0x4140000042200000;
  pair1 = 0x41d8000043868000;
  pair2 = 0x41d8000043b80000;
  pair3 = 0x41d8000043c38000;
  pair4 = 0x41d8000044058000;
  pair5 = 0x41d80000440b4000;
  pair6 = 0x4274000043310000;
  pair7 = 0x435b000043450000;
  pair8 = 0x4286000043fe0000;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 1, pair0, pairEnd, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 1, pair1, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, pair2, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 1, pair3, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 1, pair4, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 1, pair5, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 1, pair6, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 1, pair7, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 1, pair8, 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0f;
      spriteTopLeft = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x41700000);
      index = row * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 1, spriteTopLeft, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft2 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x41700000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 1, spriteTopLeft2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft3 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x41700000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 1, spriteTopLeft3, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x41700000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 1, spriteTopLeft4, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0xc2100000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 1, spriteTopLeft5, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x950) = 0;
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x994) = 0;
    }
    else {
      index = row * 0x2a8;
      *(u32 *)(work->drawBuffer + index + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + index + 0x840) = 0;
      *(u32 *)(work->drawBuffer + index + 0x884) = 0;
      *(u32 *)(work->drawBuffer + index + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + index + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + index + 0x950) = 0;
      *(u32 *)(work->drawBuffer + index + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800041400000, 0x43cf800042780000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000433d0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  return;
}



// FUN_00141fb0 NONMATCHING

void FUN_00141fb0(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  float slotY;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042200000, 0x4140000042dc0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x88), 0, 2, 1, 0x41d80000435b0000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043630000, 0x4274000043948000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043770000, 0x435b000043948000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x42860000440b8000, 0x4286000044310000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0f;
      if ((row == work->selectedSlot) || (work->selectedSlot == -2)) {
        slotY = 48.0f;
        func_0018bc10(100.0f, (void*)(work->drawBuffer + (row * 10 + 0x24) * 0x44), 0, 2, 1, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x42780000), 0, 0, 0, 0);
      }
      else {
        slotY = 27.0f;
        *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x994) = 0;
      }
      index = row * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x42820000), CAMP_SUBB_PAIR_FLOATS(slotX + 8.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x42820000), CAMP_SUBB_PAIR_FLOATS(slotX + 31.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x42820000), CAMP_SUBB_PAIR_FLOATS(slotX + 45.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x42820000), CAMP_SUBB_PAIR_FLOATS(slotX + 64.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), CAMP_SUBB_PAIR_FLOATS(slotX + 2.0f, slotY + 14.0f), 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x950) = 0;
    }
    else {
      index = row * 0x2a8;
      *(u32 *)(work->drawBuffer + index + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + index + 0x840) = 0;
      *(u32 *)(work->drawBuffer + index + 0x884) = 0;
      *(u32 *)(work->drawBuffer + index + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + index + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + index + 0x950) = 0;
      *(u32 *)(work->drawBuffer + index + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x12dc), 0, 2, 1, 0x43cf800042be0000, 0x43cf800042be0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x13a8), 0, 2, 1, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  return;
}



// FUN_00142930 NONMATCHING

void FUN_00142930(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  float slotY;
  u64 spriteTopLeft2;
  u64 spriteTopLeft3;
  u64 spriteTopLeft4;
  u64 spriteTopLeft5;
  u64 spriteTopLeft6;
  u64 spriteTopLeft7;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042dc0000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d800004404c000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x88), 0, 2, 2, 0x41d800004404c000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043948000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043948000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x4286000044310000, 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0f;
      if ((row == work->selectedSlot) || (work->selectedSlot == -2)) {
        slotY = 48.0f;
        spriteTopLeft2 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x42780000);
        func_0018bc10(100.0f, (void*)(work->drawBuffer + (row * 10 + 0x24) * 0x44), 0, 2, 2, spriteTopLeft2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), 0, 0, 0, 0);
      }
      else {
        slotY = 27.0f;
        *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x994) = 0;
      }
      spriteTopLeft3 = CAMP_SUBB_PAIR_FLOATS(slotX + 8.0f, slotY + 65.0f);
      index = row * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, spriteTopLeft3, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CAMP_SUBB_PAIR_FLOATS(slotX + 31.0f, slotY + 65.0f);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, spriteTopLeft4, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CAMP_SUBB_PAIR_FLOATS(slotX + 45.0f, slotY + 65.0f);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, spriteTopLeft5, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft6 = CAMP_SUBB_PAIR_FLOATS(slotX + 64.0f, slotY + 65.0f);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, spriteTopLeft6, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft7 = CAMP_SUBB_PAIR_FLOATS(slotX + 2.0f, slotY + 14.0f);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, spriteTopLeft7, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x950) = 0;
    }
    else {
      index = row * 0x2a8;
      *(u32 *)(work->drawBuffer + index + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + index + 0x840) = 0;
      *(u32 *)(work->drawBuffer + index + 0x884) = 0;
      *(u32 *)(work->drawBuffer + index + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + index + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + index + 0x950) = 0;
      *(u32 *)(work->drawBuffer + index + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x12dc), 0, 2, 2, 0x43cf800042be0000, 0x43cf800042be0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x13a8), 0, 2, 2, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  return;
}



// FUN_001432f0 NONMATCHING

void FUN_001432f0(CampEquipmentPanelWork* work)

{
  u64 packedValue;
  int row;
  int entryIndex;
  float slotY;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 2, 0x4140000042200000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 2, 0x4274000043630000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 2, 0x435b000043770000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 2, 0x42860000440b8000, 0x42860000440b8000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (float)(entryIndex * 0x55) + 62.0f;
      row = entryIndex * 10;
      packedValue = CAMP_SUBB_PAIR_FLOAT_HIGH(slotY + 8.0f, 0x42820000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1e) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CAMP_SUBB_PAIR_FLOAT_HIGH(slotY + 31.0f, 0x42820000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1f) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CAMP_SUBB_PAIR_FLOAT_HIGH(slotY + 45.0f, 0x42820000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x20) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CAMP_SUBB_PAIR_FLOAT_HIGH(slotY + 64.0f, 0x42820000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x21) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CAMP_SUBB_PAIR_FLOAT_HIGH(slotY + 2.0f, 0x41600000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x22) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x950) = 0;
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x994) = 0;
    }
    else {
      row = entryIndex * 0x2a8;
      *(u32 *)(work->drawBuffer + row + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + row + 0x840) = 0;
      *(u32 *)(work->drawBuffer + row + 0x884) = 0;
      *(u32 *)(work->drawBuffer + row + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + row + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + row + 0x950) = 0;
      *(u32 *)(work->drawBuffer + row + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  return;
}



// FUN_00143a00 NONMATCHING

void FUN_00143a00(CampEquipmentPanelWork* work,s32 targetSlot)

{
  int index;
  int row;
  int entryIndex;
  float slotY;
  float panelX;
  u64 spriteTopLeft8;
  
  entryIndex = 0;
  do {
    if (3 < entryIndex) {
      return;
    }
    if (entryIndex < work->visibleCount) {
      panelX = (float)(entryIndex * 0x55) + 62.0f;
      if (entryIndex == work->selectedSlot) {
        slotY = 48.0f;
        spriteTopLeft8 = CAMP_SUBB_PAIR_FLOAT_HIGH(panelX + 2.0f, 0x42240000);
        func_0018bc10(100.0f, (void*)(work->drawBuffer + (entryIndex * 10 + 0x24) * 0x44), 0, 2, 1, spriteTopLeft8, CAMP_SUBB_PAIR_FLOAT_HIGH(panelX + 2.0f, 0x42780000), 0, 0, 0, 0);
      }
      else {
        if (entryIndex != targetSlot) goto LAB_00143e94;
        slotY = 27.0f;
        func_0018bc10(100.0f, (void*)(work->drawBuffer + (entryIndex * 10 + 0x24) * 0x44), 0, 2, 2, *(u64 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x9c8), CAMP_SUBB_PAIR_FLOAT_HIGH(panelX + 2.0f, 0x42240000), 0, 0, 0, 0);
      }
      row = entryIndex * 0x2a8;
      index = entryIndex * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x830), CAMP_SUBB_PAIR_FLOATS(panelX + 8.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x874), CAMP_SUBB_PAIR_FLOATS(panelX + 31.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x8b8), CAMP_SUBB_PAIR_FLOATS(panelX + 45.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x8fc), CAMP_SUBB_PAIR_FLOATS(panelX + 64.0f, slotY + 65.0f), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x940), CAMP_SUBB_PAIR_FLOATS(panelX + 2.0f, slotY + 14.0f), 0, 0, 0, 0);
    }
LAB_00143e94:
    entryIndex = entryIndex + 1;
  } while( true );
}



// FUN_00143ee0 NONMATCHING

void FUN_00143ee0(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  u64 spriteTopLeft7;
  u32 labelY;
  u32 labelX;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042200000, 0x4140000042dc0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x88), 0, 2, 1, 0x41d80000435b0000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043630000, 0x4274000043948000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043770000, 0x435b000043948000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x42860000440b8000, 0x4286000044310000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0f;
      index = row * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x42820000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x42820000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x42820000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x42820000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0xc2ac0000), 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x950) = 0;
    }
    else {
      index = row * 0x2a8;
      *(u32 *)(work->drawBuffer + index + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + index + 0x840) = 0;
      *(u32 *)(work->drawBuffer + index + 0x884) = 0;
      *(u32 *)(work->drawBuffer + index + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + index + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + index + 0x950) = 0;
      *(u32 *)(work->drawBuffer + index + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1320), 0, 2, 1, 0x43cf800041d00000, 0x43cf800041d00000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x13a8), 0, 2, 1, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  for (row = 0; row < 0xc; row = row + 1) {
    if (row < work->listCount) {
      if (row == work->highlightedSlot) {
        labelY = 21.0f;
      }
      else {
        labelY = 0.0f;
      }
      labelX = (float)(row * 0x1d) + 61.0f;
      spriteTopLeft7 = CAMP_SUBB_PAIR_FLOATS(labelX, labelY - 100.0f);
      func_0018bc10(103.0f, (void*)(work->drawBuffer + (row + 10) * 0x44), 0, 2, 1, spriteTopLeft7, CAMP_SUBB_PAIR_FLOATS(labelX, labelY), 0, 0, 0, 0);
    }
    else {
      *(u32 *)(work->drawBuffer + row * 0x44 + 0x2ac) = 0;
    }
  }
  return;
}



// FUN_00144910 NONMATCHING

void FUN_00144910(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  u64 spriteTopLeft2;
  u64 spriteTopLeft3;
  u64 spriteTopLeft4;
  u64 spriteTopLeft5;
  u64 spriteTopLeft6;
  u32 labelY;
  u32 labelX;
  
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042dc0000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d800004404c000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x88), 0, 2, 2, 0x41d800004404c000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, *(u64 *)(work->drawBuffer + 0x214), 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 0, *(u64 *)(work->drawBuffer + 600), 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, *(u64 *)(work->drawBuffer + 0x830), 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0f;
      spriteTopLeft2 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0xc20c0000);
      index = row * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 1, spriteTopLeft2, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 8.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft3 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0xc20c0000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 1, spriteTopLeft3, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 31.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0xc20c0000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 1, spriteTopLeft4, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 45.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0xc20c0000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 1, spriteTopLeft5, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 64.0f, 0x42820000), 0, 0, 0, 0);
      spriteTopLeft6 = CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0xc2ac0000);
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 1, spriteTopLeft6, CAMP_SUBB_PAIR_FLOAT_HIGH(slotX + 2.0f, 0x41600000), 0, 0, 0, 0);
      *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x950) = 0;
    }
    else {
      index = row * 0x2a8;
      *(u32 *)(work->drawBuffer + index + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + index + 0x840) = 0;
      *(u32 *)(work->drawBuffer + index + 0x884) = 0;
      *(u32 *)(work->drawBuffer + index + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + index + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + index + 0x950) = 0;
      *(u32 *)(work->drawBuffer + index + 0x994) = 0;
    }
  }
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1320), 0, 2, 2, 0x43cf800041d00000, 0x43cf800041d00000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x13a8), 0, 2, 2, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  for (row = 0; row < 0xc; row = row + 1) {
    if (row < work->listCount) {
      if (row == work->highlightedSlot) {
        labelY = 21.0f;
      }
      else {
        labelY = 0.0f;
      }
      labelX = (float)(row * 0x1d) + 61.0f;
      func_0018bc10(103.0f, (void*)(work->drawBuffer + (row + 10) * 0x44), 0, 2, 2, CAMP_SUBB_PAIR_FLOATS(labelX, labelY), CAMP_SUBB_PAIR_FLOATS(labelX, labelY - 100.0f), 0, 0, 0, 0);
    }
    else {
      *(u32 *)(work->drawBuffer + row * 0x44 + 0x2ac) = 0;
    }
  }
  return;
}



#pragma schedule on
// FUN_00145350 NONMATCHING

void FUN_00145350(CampEquipmentPanelWork* work, s32 hoverSlot)
{
    s32 index;
    f32 x;
    f32 y;
    u64 start;
    u64 end;
    union { u64 u; f32 f[2]; } packed;

    for (index = 0; index < 0xc; index++) {
        if (index < work->listCount) {
            if (index == work->highlightedSlot) {
                y = 21.0f;
                x = (f32)(index * 0x1d) + 61.0f;
                start = *(u64*)(work->drawBuffer + index * 0x44 + 0x2e0);
                packed.f[0] = y;
                packed.f[1] = x;
                end = packed.u;
                func_0018bc10(103.0f,
                              work->drawBuffer + (index + 0xa) * 0x44,
                              0, 2, 0, start, end, 0, 0, 0, 0);
            } else if (index == hoverSlot) {
                y = 0.0f;
                x = (f32)(index * 0x1d) + 61.0f;
                start = *(u64*)(work->drawBuffer + index * 0x44 + 0x2e0);
                packed.f[0] = y;
                packed.f[1] = x;
                end = packed.u;
                func_0018bc10(103.0f,
                              work->drawBuffer + (index + 0xa) * 0x44,
                              0, 2, 0, start, end, 0, 0, 0, 0);
            }
        }
    }
}
#pragma schedule off



// FUN_00145520 NONMATCHING

void FUN_00145520(CampEquipmentDrawItem* item, s32 menuCode, u8* workData)
{
    CampEquipmentMenuWork* menu = (CampEquipmentMenuWork*)workData;
    register void* parent;
    DatPersonaWork* persona;
    void* resourceRecord;
    const char* resourceText;
    u16 resourceItemId;
    u32 resourceFlags;
    u32 textColor;
    u32 value;
    u32 denominator;
    s16 statValue;
    s32 statIndex;
    s32 gaugeWidth;
    s32 selected;
    s32 hasAvailableBonus;
    s32 index;
    s32 rank;
    s16 statType;
    s32 icon;
    char textBuffer[264];

    switch (menuCode) {
    case 0:
        campDrawSprite(parent, DAT_00833A50[0], 0x2b, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 1:
        campDrawSprite(parent, DAT_00833A50[0], 0x27, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 2:
        campDrawSprite(parent, DAT_00833A50[0], 0x21, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 3:
        campDrawSprite(parent, DAT_00833A50[0], 0x24, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 4:
        campDrawSprite(parent, DAT_00833A50[0], 0x22, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 5:
        campDrawSprite(parent, DAT_00833A50[0], 0x24, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 6:
        campDrawSprite(parent, DAT_00833A50[0], 0x23, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 7:
        FUN_001406d0(item->texture, *(u64*)&item->x, menu->detailList,
                     item->alpha);
        break;
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
        persona = datPersonaGetHeroPersona((s16)(menuCode - 10));
        selected = menu->highlightedSlot == menuCode - 10;
        campDrawSprite(parent, DAT_00833A50[1], selected ? 8 : 7,
                       item->alpha, 60.0f + item->x - 10.0f, item->y + 3.0f,
                       campTextureAsFloat(item));
        resourceRecord = func_00170e90(DAT_007cdf94);
        resourceItemId = campEquipmentResourceItem(resourceRecord);
        hasAvailableBonus = 0;
        if (FUN_0017bf70(resourceItemId) != 0) {
            for (index = 0; index < 5; index++) {
                if (FUN_0017bfa0(resourceItemId, (u8)index) != 0 &&
                    datPersonaGetTotalStat(persona, (u16)index) != 99) {
                    hasAvailableBonus = 1;
                }
            }
        }
        if (hasAvailableBonus != 0) {
            campDrawSprite(parent, DAT_00833A50[0], selected ? 0x26 : 0x25,
                           item->alpha, item->x + (selected ? 9.0f : 8.0f),
                           item->y + (selected ? 9.0f : 8.0f),
                           campTextureAsFloat(item));
        }
        if (persona->level > 9) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(selected ? 1 : 2),
                                persona->level / 10 + 0xb, item->alpha,
                               88.0f + item->x - 10.0f, item->y + 11.0f,
                                campTextureAsFloat(item));
        }
        campDrawSpriteDigit(parent, H_Maestro_001120a0(selected ? 1 : 2),
                            persona->level % 10 + 0xb, item->alpha,
                               104.0f + item->x - 10.0f, item->y + 11.0f,
                            campTextureAsFloat(item));
        resourceText = FUN_00173220(persona->id);
        textColor = (0xffU - item->alpha) | 0xffffff00;
        campDrawText(100.0f, (s32)(130.0f + (f32)(s32)item->x - 10.0f),
                     (s32)(item->y + 10.0f), textColor, 10, 1, resourceText,
                     0x10, 0);
        break;
    case 0x1e:
    case 0x28:
    case 0x32:
    case 0x3c:
        statIndex = (menuCode - 0x1e) / 10;
        statValue = campMenuCategoryValue(menu, statIndex);
        resourceText = FUN_00177790(statValue);
        textColor = (0xffU - item->alpha) | 0xffffff00;
        sprintf(textBuffer, DAT_007cb66c, resourceText);
        campDrawTextAlt((s32)item->x, (s32)item->y + 3, textColor,
                        campTextureAsFloat(item), 10, 1, textBuffer, 0x10,
                        0x78);
        break;
    case 0x1f:
    case 0x29:
    case 0x33:
    case 0x3d:
        statIndex = (menuCode - 0x1f) / 10;
        statValue = campMenuCategoryValue(menu, statIndex);
        value = FUN_0016c4f0(statValue) & 0xffff;
        rank = value > 99;
        if (rank != 0) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                                value / 100 + 0xb, item->alpha,
                                item->x, item->y, campTextureAsFloat(item));
            value %= 100;
        }
        if (value > 9 || rank != 0) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                                value / 10 + 0xb, item->alpha,
                                item->x + 16.0f, item->y,
                                campTextureAsFloat(item));
        }
        campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                            value % 10 + 0xb, item->alpha,
                            item->x + 32.0f, item->y,
                            campTextureAsFloat(item));
        value = FUN_0016c4f0(statValue) & 0xffff;
        denominator = FUN_0016c5f0(statValue) & 0xffff;
        gaugeWidth = 0x4c - (value * 0x4c) / denominator;
        campDrawSprite(parent, DAT_00833A50[1], 0xd, item->alpha,
                       item->x + 50.0f, item->y + 2.0f,
                       campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[1], 0xb, item->alpha,
                       item->x + 55.0f, item->y + 1.0f,
                       campTextureAsFloat(item));
        if (gaugeWidth != 0) {
            campDrawGauge(campTextureAsFloat(item) - 1.0f,
                          item->x + 56.0f + ((f32)0x4c - (f32)gaugeWidth),
                          item->y + 1.0f, 0xffffff00U, gaugeWidth, 10);
        }
        campDrawSprite(parent, DAT_00833A50[1], 0xb, item->alpha,
                       item->x + 55.0f, item->y + 1.0f,
                       campTextureAsFloat(item));
        break;
    case 0x20:
    case 0x2a:
    case 0x34:
    case 0x3e:
        statIndex = (menuCode - 0x20) / 10;
        statValue = campMenuCategoryValue(menu, statIndex);
        value = FUN_0016c570(statValue) & 0xffff;
        rank = value > 99;
        if (rank != 0) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                                value / 100 + 0xb, item->alpha,
                                item->x, item->y, campTextureAsFloat(item));
            value %= 100;
        }
        if (value > 9 || rank != 0) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                                value / 10 + 0xb, item->alpha,
                                item->x + 16.0f, item->y,
                                campTextureAsFloat(item));
        }
        campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                            value % 10 + 0xb, item->alpha,
                            item->x + 32.0f, item->y,
                            campTextureAsFloat(item));
        value = FUN_0016c570(statValue) & 0xffff;
        denominator = func_0016c670(statValue) & 0xffff;
        gaugeWidth = 0x4c - (value * 0x4c) / denominator;
        campDrawSprite(parent, DAT_00833A50[1], 0xd, item->alpha,
                       item->x + 50.0f, item->y + 2.0f,
                       campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[1], 0xb, item->alpha,
                       item->x + 55.0f, item->y + 1.0f,
                       campTextureAsFloat(item));
        if (gaugeWidth != 0) {
            campDrawGauge(campTextureAsFloat(item) - 1.0f,
                          item->x + 56.0f + ((f32)0x4c - (f32)gaugeWidth),
                          item->y + 1.0f, 0xffffff00U, gaugeWidth, 10);
        }
        campDrawSprite(parent, DAT_00833A50[1], 0xb, item->alpha,
                       item->x + 55.0f, item->y + 1.0f,
                       campTextureAsFloat(item));
        break;
    case 0x21:
    case 0x2b:
    case 0x35:
    case 0x3f:
        statIndex = (menuCode - 0x20) / 10;
        statValue = campMenuCategoryValue(menu, statIndex);
        rank = FUN_0016c470(statValue);
        if (rank > 9) {
            campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                                rank / 10 + 0xb, item->alpha,
                                item->x, item->y, campTextureAsFloat(item));
        }
        campDrawSpriteDigit(parent, H_Maestro_001120a0(2),
                            rank % 10 + 0xb, item->alpha,
                            item->x + 16.0f, item->y,
                            campTextureAsFloat(item));
        resourceFlags = FUN_0016c970(statValue);
        if ((resourceFlags & 0x80000) != 0) {
            icon = 0xe;
        } else if ((resourceFlags & 0x80) != 0) {
            icon = 0xf;
        } else {
            statType = FUN_0016c920(statValue);
            if (statType == 5) {
                icon = 1;
            } else if (statType == 4) {
                icon = 0;
            } else if (statType == 3) {
                icon = 2;
            } else {
                icon = -1;
            }
        }
        if (icon != -1) {
            campDrawSprite(parent, DAT_00833A50[1], icon, item->alpha,
                           item->x + 44.0f, item->y - 6.0f,
                           campTextureAsFloat(item));
        }
        break;
    case 0x22:
    case 0x2c:
    case 0x36:
    case 0x40:
        campDrawSprite(parent, DAT_00833A50[1], 3, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x23:
    case 0x2d:
    case 0x37:
    case 0x41:
        campDrawSprite(parent, DAT_00833A50[1], 3, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x24:
    case 0x2e:
    case 0x38:
    case 0x42:
        campDrawSprite(parent, DAT_00833A50[1], 4, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x46:
        campDrawSprite(parent, DAT_00833A50[2], 8, item->alpha,
                       item->x - 16.0f, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[2], 1, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x47:
        campDrawSprite(parent, DAT_00833A50[2], 8, item->alpha,
                       item->x - 16.0f, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[2], 2, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x48:
        campDrawSprite(parent, DAT_00833A50[2], 8, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[2], 3, item->alpha,
                       item->x + 16.0f, item->y, campTextureAsFloat(item));
        break;
    case 0x49:
        campDrawSprite(parent, DAT_00833A50[0x55], 0, item->alpha,
                       item->x + 246.0f, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[0x55], 3, item->alpha,
                       item->x + 322.0f, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[0x55], 5, item->alpha,
                       item->x, item->y, campTextureAsFloat(item));
        break;
    case 0x4a:
        campDrawSprite(parent, DAT_00833A50[0x55], 0, item->alpha,
                       item->x + 32.0f, item->y, campTextureAsFloat(item));
        campDrawSprite(parent, DAT_00833A50[0x55], 3, item->alpha,
                       item->x + 108.0f, item->y, campTextureAsFloat(item));
        break;
    default:
        break;
    }
}



/* Retail reconstruction from FUN_00146710 offsets +0x1c..+0xddc; pairSlots maps the measured draw/status temporaries at +0x68..+0x128. */
// FUN_00146710 NONMATCHING

void FUN_00146710(CampEquipmentPanelWork* work)
{
  u64 pair0;
  CampPair base;
  u64 pair25;
  u64 pair24;
  u64 pair23;
  u64 pair22;
  u64 pair21;
  u64 pair20;
  u64 pair19;
  u64 pair18;
  u64 pair17;
  u64 pair16;
  u64 pair15;
  u64 pair14;
  u64 pair13;
  u64 pair12;
  u64 pair11;
  u64 pair10;
  u64 pair9;
  u64 pair8;
  u64 pair7;
  u64 pair6;
  u64 pair5;
  u64 pair4;
  u64 pair3;
  u64 pair2;
  u64 pair1;
  f32 tempFloat;
  s32 row;
  s32 entryIndex;
  f32 slotY;
  struct {
    u64 draw[16];
    u64 status[10];
  } pairSlots;
#define pair0 pairSlots.draw[0]
#define pair1 pairSlots.draw[1]
#define pair2 pairSlots.draw[2]
#define pair3 pairSlots.draw[3]
#define pair4 pairSlots.draw[4]
#define pair5 pairSlots.draw[5]
#define pair6 pairSlots.draw[6]
#define pair7 pairSlots.draw[7]
#define pair8 pairSlots.draw[8]
#define pair9 pairSlots.draw[9]
#define pair10 pairSlots.draw[10]
#define pair11 pairSlots.draw[11]
#define pair12 pairSlots.draw[12]
#define pair13 pairSlots.draw[13]
#define pair14 pairSlots.draw[14]
#define pair15 pairSlots.draw[15]
#define pair16 pairSlots.status[0]
#define pair17 pairSlots.status[1]
#define pair18 pairSlots.status[2]
#define pair19 pairSlots.status[3]
#define pair20 pairSlots.status[4]
#define pair21 pairSlots.status[5]
#define pair22 pairSlots.status[6]
#define pair23 pairSlots.status[7]
#define pair24 pairSlots.status[8]
#define pair25 pairSlots.status[9]


  base.x = 40.0f;
  base.y = 12.0f;
  pair0 = *(u64*)&base;
  *(f32*)&pair0 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 2,
                 pair0, *(u64*)&base, 0, 0, 0, 10);
  base.x = 219.0f;
  base.y = 27.0f;
  pair1 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 2,
                 pair1, *(u64*)&base, 0, 0, 0, 10);
  base.x = 318.0f;
  base.y = 27.0f;
  pair2 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 2,
                 pair2, *(u64*)&base, 0, 0, 0, 10);
  base.x = 341.0f;
  base.y = 27.0f;
  pair3 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 2,
                 pair3, *(u64*)&base, 0, 0, 0, 10);
  base.x = 484.0f;
  base.y = 27.0f;
  pair4 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 2,
                 pair4, *(u64*)&base, 0, 0, 0, 10);
  base.x = 507.0f;
  base.y = 27.0f;
  pair5 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 2,
                 pair5, *(u64*)&base, 0, 0, 0, 10);
  base.x = 227.0f;
  base.y = 61.0f;
  pair6 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 2,
                 pair6, *(u64*)&base, 0, 0, 0, 10);
  base.x = 247.0f;
  base.y = 219.0f;
  pair7 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 2,
                 pair7, *(u64*)&base, 0, 0, 0, 10);
  base.x = 558.0f;
  base.y = 67.0f;
  pair8 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 2,
                 pair8, *(u64*)&base, 0, 0, 0, 10);

  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (f32)(entryIndex * 0x55) + 62.0f;
      base.x = 65.0f;
      base.y = 8.0f + slotY;
      pair9 = *(u64*)&base;
      base.x += -100.0f;
      row = entryIndex * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1e) * 0x44),
                     0, 2, 2, pair9, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 31.0f + slotY;
      pair10 = *(u64*)&base;
      base.x += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1f) * 0x44),
                     0, 2, 2, pair10, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 45.0f + slotY;
      pair11 = *(u64*)&base;
      base.x += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x20) * 0x44),
                     0, 2, 2, pair11, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 64.0f + slotY;
      pair12 = *(u64*)&base;
      base.x += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x21) * 0x44),
                     0, 2, 2, pair12, *(u64*)&base, 0, 0, 0, 10);
      base.x = 14.0f;
      base.y = 2.0f + slotY;
      pair13 = *(u64*)&base;
      base.x += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x22) * 0x44),
                     0, 2, 2, pair13, *(u64*)&base, 0, 0, 0, 10);
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x950) = 0;
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x994) = 0;
    } else {
      row = entryIndex * 0x2a8;
      *(u32 *)(work->drawBuffer + row + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + row + 0x840) = 0;
      *(u32 *)(work->drawBuffer + row + 0x884) = 0;
      *(u32 *)(work->drawBuffer + row + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + row + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + row + 0x950) = 0;
      *(u32 *)(work->drawBuffer + row + 0x994) = 0;
    }
  }

  base.x = 62.0f;
  base.y = (f32)0x19f;
  pair14 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 2,
                 pair14, *(u64*)&base, 0, 0, 0, 10);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  base.x = 239.0f;
  base.y = (f32)0x19f;
  pair15 = *(u64*)&base;
  base.x += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 2,
                 pair15, *(u64*)&base, 0, 0, 0, 10);

  tempFloat = (f32)0x17b;
  base.x = tempFloat;
  base.y = 12.0f;
  pair16 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)work->statusBuffer), 0, 2, 1,
                 *(u64*)&base, pair16, 0, 0, 0, 10);
  base.x = 13.0f;
  base.y = 27.0f;
  pair17 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x44)), 0, 2, 1,
                 *(u64*)&base, pair17, 0, 0, 0, 10);
  base.x = 112.0f;
  base.y = 27.0f;
  pair18 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x88)), 0, 2, 1,
                 *(u64*)&base, pair18, 0, 0, 0, 10);
  base.x = 135.0f;
  base.y = 27.0f;
  pair19 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0xcc)), 0, 2, 1,
                 *(u64*)&base, pair19, 0, 0, 0, 10);
  base.x = 278.0f;
  base.y = 27.0f;
  pair20 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x110)), 0, 2, 1,
                 *(u64*)&base, pair20, 0, 0, 0, 10);
  tempFloat = (f32)0x12d;
  base.x = tempFloat;
  base.y = 27.0f;
  pair21 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x154)), 0, 2, 1,
                 *(u64*)&base, pair21, 0, 0, 0, 10);

  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (work->visibleCount + -1 < entryIndex) {
      *(u32 *)(work->statusBuffer + entryIndex * 0x44 + 0x2ac) = 0;
    } else {
      base.x = 30.0f;
      base.y = (f32)(entryIndex * 0x55) + 64.0f;
      func_0018bc10(100.0f,
                    (void*)(work->statusBuffer + (entryIndex + 10) * 0x44),
                    0, 2, 1, *(u64*)&base, *(u64*)&base, 0, 0, 0, 10);
    }
  }

  base.x = 104.0f;
  base.y = 61.0f;
  pair22 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x550)),
                 0, 2, 1, *(u64*)&base, pair22, 0, 0, 0, 10);
  base.x = 124.0f;
  base.y = 219.0f;
  pair23 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x594)),
                 0, 2, 1, *(u64*)&base, pair23, 0, 0, 0, 10);
  base.x = 226.0f;
  base.y = (f32)0x19f;
  pair24 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x83c)),
                 0, 2, 1, *(u64*)&base, pair24, 0, 0, 0, 10);
  tempFloat = (f32)0x1b7;
  base.x = tempFloat;
  base.y = (f32)0x19f;
  pair25 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x880)),
                 0, 2, 1, *(u64*)&base, pair25, 0, 0, 0, 10);
  return;
}



#undef pair25
#undef pair24
#undef pair23
#undef pair22
#undef pair21
#undef pair20
#undef pair19
#undef pair18
#undef pair17
#undef pair16
#undef pair15
#undef pair14
#undef pair13
#undef pair12
#undef pair11
#undef pair10
#undef pair9
#undef pair8
#undef pair7
#undef pair6
#undef pair5
#undef pair4
#undef pair3
#undef pair2
#undef pair1
#undef pair0

// FUN_001474f0 NONMATCHING

void FUN_001474f0(CampEquipmentPanelWork* work)

{
  u64 pair0;
  CampPair base;
  u64 pair25;
  u64 pair24;
  u64 pair23;
  u64 pair22;
  u64 pair21;
  u64 pair20;
  u64 pair19;
  u64 pair18;
  u64 pair17;
  u64 pair16;
  u64 pair15;
  u64 pair14;
  u64 pair13;
  u64 pair12;
  u64 pair11;
  u64 pair10;
  u64 pair9;
  u64 pair8;
  u64 pair7;
  u64 pair6;
  u64 pair5;
  u64 pair4;
  u64 pair3;
  u64 pair2;
  u64 pair1;
  f32 tempFloat;
  s32 row;
  s32 entryIndex;
  f32 slotY;

  base.x = 40.0f;
  base.y = 12.0f;
  pair0 = *(u64*)&base;
  *(f32*)&pair0 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer), 0, 2, 1, pair0, *(u64*)&base, 0, 0, 0, 10);
  base.x = 219.0f;
  base.y = 27.0f;
  pair1 = *(u64*)&base;
  *(f32*)&pair1 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x44), 0, 2, 1, pair1, *(u64*)&base, 0, 0, 0, 10);
  base.x = 318.0f;
  base.y = 27.0f;
  pair2 = *(u64*)&base;
  *(f32*)&pair2 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, pair2, *(u64*)&base, 0, 0, 0, 10);
  base.x = (f32)0x155;
  base.y = 27.0f;
  pair3 = *(u64*)&base;
  *(f32*)&pair3 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x110), 0, 2, 1, pair3, *(u64*)&base, 0, 0, 0, 10);
  base.x = 484.0f;
  base.y = 27.0f;
  pair4 = *(u64*)&base;
  *(f32*)&pair4 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x154), 0, 2, 1, pair4, *(u64*)&base, 0, 0, 0, 10);
  base.x = (f32)0x1fb;
  base.y = 27.0f;
  pair5 = *(u64*)&base;
  *(f32*)&pair5 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x198), 0, 2, 1, pair5, *(u64*)&base, 0, 0, 0, 10);
  base.x = 227.0f;
  base.y = 61.0f;
  pair6 = *(u64*)&base;
  *(f32*)&pair6 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1dc), 0, 2, 1, pair6, *(u64*)&base, 0, 0, 0, 10);
  base.x = 247.0f;
  base.y = 219.0f;
  pair7 = *(u64*)&base;
  *(f32*)&pair7 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x220), 0, 2, 1, pair7, *(u64*)&base, 0, 0, 0, 10);
  base.x = (f32)0x22e;
  base.y = 67.0f;
  pair8 = *(u64*)&base;
  *(f32*)&pair8 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x7f8), 0, 2, 1, pair8, *(u64*)&base, 0, 0, 0, 10);

  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (f32)(entryIndex * 0x55) + 62.0f;
      base.x = 65.0f;
      base.y = 8.0f + slotY;
      pair9 = *(u64*)&base;
      *(f32*)&pair9 += -100.0f;
      row = entryIndex * 10;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1e) * 0x44), 0, 2, 1, pair9, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 31.0f + slotY;
      pair10 = *(u64*)&base;
      *(f32*)&pair10 += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x1f) * 0x44), 0, 2, 1, pair10, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 45.0f + slotY;
      pair11 = *(u64*)&base;
      *(f32*)&pair11 += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x20) * 0x44), 0, 2, 1, pair11, *(u64*)&base, 0, 0, 0, 10);
      base.x = 65.0f;
      base.y = 64.0f + slotY;
      pair12 = *(u64*)&base;
      *(f32*)&pair12 += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x21) * 0x44), 0, 2, 1, pair12, *(u64*)&base, 0, 0, 0, 10);
      base.x = 14.0f;
      base.y = 2.0f + slotY;
      pair13 = *(u64*)&base;
      *(f32*)&pair13 += -100.0f;
      func_0018bc10(100.0f, (void*)(work->drawBuffer + (row + 0x22) * 0x44), 0, 2, 1, pair13, *(u64*)&base, 0, 0, 0, 10);
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x950) = 0;
      *(u32 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x994) = 0;
    } else {
      row = entryIndex * 0x2a8;
      *(u32 *)(work->drawBuffer + row + 0x7fc) = 0;
      *(u32 *)(work->drawBuffer + row + 0x840) = 0;
      *(u32 *)(work->drawBuffer + row + 0x884) = 0;
      *(u32 *)(work->drawBuffer + row + 0x8c8) = 0;
      *(u32 *)(work->drawBuffer + row + 0x90c) = 0;
      *(u32 *)(work->drawBuffer + row + 0x950) = 0;
      *(u32 *)(work->drawBuffer + row + 0x994) = 0;
    }
  }

  base.x = 62.0f;
  base.y = (f32)0x19f;
  pair14 = *(u64*)&base;
  *(f32*)&pair14 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, pair14, *(u64*)&base, 0, 0, 0, 10);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  base.x = 239.0f;
  base.y = (f32)0x19f;
  pair15 = *(u64*)&base;
  *(f32*)&pair15 += -100.0f;
  func_0018bc10(100.0f, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, pair15, *(u64*)&base, 0, 0, 0, 10);

  tempFloat = (f32)0x17b;
  base.x = tempFloat;
  base.y = 12.0f;
  pair16 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)work->statusBuffer), 0, 2, 2, *(u64*)&pair16, *(u64*)&base, 0, 0, 0, 10);
  base.x = 13.0f;
  base.y = 27.0f;
  pair17 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x44)), 0, 2, 2, *(u64*)&pair17, *(u64*)&base, 0, 0, 0, 10);
  base.x = 112.0f;
  base.y = 27.0f;
  pair18 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x88)), 0, 2, 2, *(u64*)&pair18, *(u64*)&base, 0, 0, 0, 10);
  base.x = 135.0f;
  base.y = 27.0f;
  pair19 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0xcc)), 0, 2, 2, *(u64*)&pair19, *(u64*)&base, 0, 0, 0, 10);
  base.x = 278.0f;
  base.y = 27.0f;
  pair20 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x110)), 0, 2, 2, *(u64*)&pair20, *(u64*)&base, 0, 0, 0, 10);
  tempFloat = (f32)0x12d;
  base.x = tempFloat;
  base.y = 27.0f;
  pair21 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x154)), 0, 2, 2, *(u64*)&pair21, *(u64*)&base, 0, 0, 0, 10);

  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (work->visibleCount + -1 < entryIndex) {
      *(u32 *)(work->statusBuffer + entryIndex * 0x44 + 0x2ac) = 0;
    } else {
      base.x = 30.0f;
      base.y = 64.0f + (f32)(entryIndex * 0x55);
      func_0018bc10(100.0f, (void*)(work->statusBuffer + (entryIndex + 10) * 0x44), 0, 2, 2, *(u64*)&base, *(u64*)&base, 0, 0, 0, 10);
    }
  }

  base.x = 104.0f;
  base.y = 61.0f;
  pair22 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x550)), 0, 2, 2, *(u64*)&pair22, *(u64*)&base, 0, 0, 0, 10);
  base.x = 124.0f;
  base.y = 219.0f;
  pair23 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x594)), 0, 2, 2, *(u64*)&pair23, *(u64*)&base, 0, 0, 0, 10);
  base.x = 226.0f;
  base.y = (f32)0x19f;
  pair24 = *(u64*)&base;
  base.x += 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x83c)), 0, 2, 2, *(u64*)&pair24, *(u64*)&base, 0, 0, 0, 10);
  tempFloat = (f32)0x1b7;
  base.x = tempFloat;
  base.y = (f32)0x19f;
  pair25 = *(u64*)&base;
  base.x = tempFloat + 100.0f;
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x880)), 0, 2, 2, *(u64*)&pair25, *(u64*)&base, 0, 0, 0, 10);
  return;
}




