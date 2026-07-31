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
    u8 reserved08[4];
    u32 ownedFlag;
    u32 availableFlag;
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
    s32 value;                  /* +0x04 */
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

static inline CampEquipmentDetailEntry* campDetailEntry(CampEquipmentDetailWork* work, s32 index)
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

static inline CampEquipmentEntry* campEquipmentEntry(CampEquipmentWork* work, s32 index)
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
typedef union CampBits
{
    u64 u;
    f32 f[2];
} CampBits;

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
extern DatPersonaWork* datPersonaGetHeroPersona(s16 index);
extern void* func_00170ed0(s16 id, s32* category);
extern const char* func_00171110(s16 id, s16 field);
extern u32 func_00171250(s16 id);
extern u16 func_001712d0(s16 id);
extern const char* FUN_00173220(u16 personaId);
extern DatPersonaWork* FUN_00174a90(s16 id);
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
                           u8 alpha, f32 x, f32 y, f32 scale);
#pragma alias campDrawSpriteX FUN_001159f0
extern void campDrawSpriteX(void* parent, void* resource, s32 frame,
                            f32 x, u8 alpha, f32 y, f32 scale);
#pragma alias campDrawSpriteXY FUN_001159f0
extern void campDrawSpriteXY(void* parent, void* resource, s32 frame,
                             f32 x, f32 y, u8 alpha, f32 scale);
#pragma alias campDrawSpriteDirect FUN_001159f0
extern void campDrawSpriteDirect(f32 x, f32 y, f32 scale);
#pragma alias campDrawSpriteDetail FUN_001159f0
extern void campDrawSpriteDetail(f32 x, f32 y, void* texture);
#pragma alias campDrawSpriteDetailAlt FUN_00115bc0
extern void campDrawSpriteDetailAlt(f32 x, f32 y, void* texture);
#pragma alias campDrawSpriteDigit FUN_00115ad0
extern void campDrawSpriteDigit(void* parent, void* resource, s32 frame,
                                u8 alpha, f32 x, f32 y, f32 scale);
extern void campDrawGauge(f32 scale, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
#pragma alias campDrawGauge FUN_00113a30
#pragma alias campDrawTextAlt FUN_003b32d0
extern void campDrawTextAlt(s32 x, s32 y, u32 color, f32 scale,
                            u32 font, u32 alignment, const char* text,
                            u32 maxWidth, u32 shadow);
#pragma alias campDrawTextAltScale FUN_003b32d0
extern void campDrawTextAltScale(f32 scale, s32 x, s32 y, u32 color,
                                 u32 font, u32 alignment, const char* text,
                                 u32 maxWidth, u32 shadow);
#pragma alias campDrawTextAltXScale FUN_003b32d0
extern void campDrawTextAltXScale(s32 x, f32 scale, s32 y, u32 color,
                                  u32 font, u32 alignment,
                                  const char* text, u32 maxWidth,
                                  u32 shadow);
#pragma alias campDrawSpriteAlt FUN_00115bc0
extern void campDrawSpriteAlt(void* parent, void* resource, s32 frame,
                              u8 alpha, s32 red, s32 green, s32 blue,
                              f32 x, f32 y, f32 scale);
#pragma alias campDrawSpriteAltX FUN_00115bc0
extern void campDrawSpriteAltX(void* parent, void* resource, s32 frame,
                               u8 alpha, f32 x, s32 red, s32 green,
                               s32 blue, f32 y, f32 scale);
#pragma alias campDrawText FUN_003b2cb0
extern void campDrawText(f32 scale, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
#pragma alias campDrawValue FUN_003c7e20
extern void campDrawValue(f32 scale, s32 x, s32 y, u32 color, u32 font,
                          u32 alignment, u32 style, u32 value);
#pragma alias campDrawValueXY FUN_003c7e20
extern void campDrawValueXY(s32 x, s32 y, f32 scale, u32 color, u32 font,
                            u32 alignment, u32 style, u32 value);
extern s32 FUN_0012df50(u32 mask);
extern void* DAT_00833A50[];
extern void* DAT_00833B70;
#pragma alias DAT_00833B70_abs DAT_00833B70
extern u8 DAT_00833B70_abs[];
#pragma alias campDetailFormat DAT_007cb66c
extern char campDetailFormat;
extern void FUN_003c7e20(void* texture, s32 x, s32 y, u32 color, u32 font,
                         u32 alignment, u32 style, u32 value);
extern void FUN_003b2cb0(void* texture, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth,
                         u32 shadow);
extern int sprintf(char* buffer, const char* format, ...);
#pragma alias campDrawEquipmentDetailList FUN_001406d0
extern void campDrawEquipmentDetailList(CampPair position, f32 texture,
                                        CampEquipmentDetailWork* detail,
                                        s32 alpha);
#pragma alias campDrawEquipmentDetailListAlt FUN_00140e30
extern void campDrawEquipmentDetailListAlt(CampPair position, f32 texture,
                                           CampEquipmentDetailWork* detail,
                                           s32 alpha);
extern void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame);
/* Reordered ABI alias; W310 measured FUN_00141660 nd274 -> nd0 and FUN_00145350 nd339 -> nd335 (canonical prototype nd274). */
#pragma alias func_0018bc10_buffirst FUN_0018bc10
extern void func_0018bc10_buffirst(void* transition, f32 depth,
                                   s32 drawMode, s32 positionMode,
                                   s32 alphaMode, u64 start, u64 end,
                                   s32 param0, s32 tile, s32 startFrame,
                                   s32 endFrame);
extern void qsort(void* base, u32 count, u32 width,
                  int (*compare)(const void*, const void*));
static inline void campEquipmentDrawFixed(f32 scale, u32 alpha, s32 frame,
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

static inline void campEquipmentDrawDigit(f32 scale, u32 alpha, s32 font,
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




 
// Inline macro overrides: expand helpers to direct campDrawSprite calls.
#undef campEquipmentDrawFixed
#define campEquipmentDrawFixed(scale,alpha,frame,x,y) \
    campDrawSprite(parent,DAT_00833A50[0],(frame),(u32)(alpha),(x),(y),(scale))
#undef campEquipmentDrawAtlas
#define campEquipmentDrawAtlas(scale,alpha,frame,x,y) \
    campDrawSprite(parent,DAT_00833B70,(frame),(u32)(alpha),(x),(y),(scale))
#undef campEquipmentDrawAlt
#define campEquipmentDrawAlt(scale,alpha,frame,x,y) \
    campDrawSpriteAlt(parent,DAT_00833B70,(frame),(u32)(alpha),0x20,0x43,0x78,(x),(y),(scale))
#undef campEquipmentDrawDigit
#define campEquipmentDrawDigit(scale,alpha,font,frame,x,y) \
    campDrawSprite(parent,H_Maestro_001120a0(font),(frame),(u32)(alpha),(x),(y),(scale))
#define campEquipmentEntry(work,index) (&(work)->entries[(index)])
 
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



#undef campEquipmentDrawFixed
#undef campEquipmentDrawAtlas
#undef campEquipmentDrawAlt
#undef campEquipmentDrawDigit












static inline uintptr_t add_offset_first(uintptr_t offset, uintptr_t base)
{
    return offset + base;
}




#define func_0018bc10(depth, transition, drawMode, positionMode, alphaMode, start, end, param0, tile, startFrame, endFrame) \
  func_0018bc10_buffirst((transition), (depth), (drawMode), (positionMode), (alphaMode), (start), (end), (param0), (tile), (startFrame), (endFrame))
#undef func_0018bc10





















/* Schedule-off + typed buffer locals; W310 with pragma on: nd338/416B, off: nd110/452B; the retained 28B over the alias-only 424B baseline are retail-aligned instructions (fndiff, no padding). */
#pragma schedule off
#define func_0018bc10(depth, transition, drawMode, positionMode, alphaMode, start, end, param0, tile, startFrame, endFrame) \
  func_0018bc10_buffirst((transition), (depth), (drawMode), (positionMode), (alphaMode), (start), (end), (param0), (tile), (startFrame), (endFrame))

#undef func_0018bc10
#pragma schedule off






/* Retail reconstruction from FUN_00146710 offsets +0x1c..+0xddc; pairSlots maps the measured draw/status temporaries at +0x68..+0x128. */



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





