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
    u8 reserved08[8];          /* +0x08 */
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

typedef struct CampEquipmentResourceRecord
{
    u8 reserved00[8];
    u16 itemId;                  /* +0x08 */
} CampEquipmentResourceRecord;

static u16 campEquipmentResourceItem(const void* resource)
{
    return ((const CampEquipmentResourceRecord*)resource)->itemId;
}

static f32 campTextureAsFloat(const CampEquipmentDrawItem* item)
{
    union
    {
        u32 bits;
        f32 value;
    } textureValue;

    textureValue.bits = (u32)item->texture;
    return textureValue.value;
}

static f32 campPackedX(u64 position)
{
    return (f32)(u32)position;
}

static f32 campPackedY(u64 position)
{
    return (f32)(u32)(position >> 32);
}

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
extern void FUN_001159f0(f32 first, ...);
extern void FUN_00115ad0(f32 first, ...);
extern void FUN_00115bc0(f32 first, ...);
extern void FUN_00113a30(f32 first, ...);
extern void FUN_003c7e20(void* texture, s32 x, s32 y, u32 color, u32 font,
                         u32 alignment, u32 style, u32 value);
extern void FUN_003b2cb0(void* texture, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth, u32 shadow);
extern void FUN_003b32d0(void* texture, s32 x, s32 y, s32 color, u32 font,
                         u32 alignment, const char* text, u32 maxWidth, u32 shadow);
extern int sprintf(char* buffer, const char* format, ...);
extern void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame);
extern void qsort(void* base, u32 count, u32 width,
                  int (*compare)(const void*, const void*));
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
    u16 indices[300];
    s32 count = 0;
    s32 scan = 0;
    s32 outCount;
    s32 index;
    s32 category;
    u32 categoryMask;
    s16 selected;
    s16 candidate;

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

    outCount = 0;
    selected = datGetEquipmentIdx(pcId, equipmentType);
    work->entries[0].itemId = datGetEquipmentId(pcId, selected);
    work->entries[0].categoryMask = func_0016f720(pcId, selected);
    work->entries[0].equipmentClass = (u8)func_00171250((s16)work->entries[0].itemId);
    work->entries[0].effect = datGetEquipmentEffect(pcId, selected);
    work->entries[0].slotType = func_0016f810(pcId, selected);
    work->entries[0].sourceIndex = selected;
    campEquipmentSetStats(&work->entries[0], pcId, selected);
    outCount++;

    index = 0;
    while (index < count) {
        candidate = (s16)indices[index];
        if (datGetEquipmentId(1, candidate) != 0) {
            categoryMask = func_001712d0((s16)datGetEquipmentId(1, candidate));
            if ((categoryMask & (0x20u << ((pcId - 1) & 31))) != 0 &&
                (s16)func_00171250((s16)datGetEquipmentId(1, candidate)) == equipmentType &&
                candidate != datGetEquipmentIdx(1, equipmentType)) {
                work->entries[outCount].itemId = datGetEquipmentId(1, candidate);
                work->entries[outCount].categoryMask = func_0016f720(1, indices[index]);
                work->entries[outCount].equipmentClass =
                    (u8)func_00171250((s16)work->entries[outCount].itemId);
                work->entries[outCount].effect = datGetEquipmentEffect(1, indices[index]);
                work->entries[outCount].slotType = func_0016f810(1, indices[index]);
                work->entries[outCount].sourceIndex = indices[index];
                campEquipmentSetStats(&work->entries[outCount], 1, indices[index]);
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

// FUN_0013c6a0
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
    asm volatile("addiu %0, $0, 1" : "=r" (one));
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
    s32 scanIndex;
    s32 recordCount = 0;

    for (scanIndex = 0; scanIndex < 300; scanIndex++) {
        if (datGetEquipmentId(1, scanIndex) != 0) {
            candidateIndices[candidateCount++] = (u16)scanIndex;
        }
    }
    if (candidateCount > 1) {
        qsort(candidateIndices, candidateCount, sizeof(candidateIndices[0]),
              campCompareEquipmentIndex);
    }

    for (scanIndex = 0; scanIndex < 0x14; scanIndex++) {
        if (datGetEquipmentId(-1, scanIndex) != 0) {
            CampEquipmentEntry* entry = campEquipmentEntry(work, recordCount++);
            campEquipmentPopulate(entry, -1, scanIndex);
            entry->categoryMask = campEquipmentFirstCategory((s16)entry->itemId);
            entry->sourceIndex = scanIndex + 0x1000;
            entry->ownedFlag = 1;
            entry->availableFlag = 1;
        }
    }
    for (scanIndex = 0; scanIndex < candidateCount; scanIndex++) {
        s16 candidate = (s16)candidateIndices[scanIndex];
        CampEquipmentEntry* entry;
        s32 slot;

        if (datGetEquipmentId(1, candidate) == 0) {
            continue;
        }
        entry = campEquipmentEntry(work, recordCount++);
        campEquipmentPopulateWithCategory(entry, 1, candidate,
                                          campFirstSetBit(func_0016f720(1, candidate)));
        entry->ownedFlag = 0;
        entry->availableFlag = 1;
        for (slot = 0; slot < 4; slot++) {
            if (candidate == datGetEquipmentIdx(1, (s16)slot)) {
                entry->availableFlag = 0;
                break;
            }
        }
    }
    campEquipmentClearCategoryCounts(work);
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

// FUN_0013cf80 NONMATCHING
void FUN_0013cf80(s16 pcId, CampEquipmentWork* work)
{
    s32 category;
    s32 equipmentType;
    s32 recordCount = 0;

    for (category = 0; category < 0x15; category++) {
        work->categoryCounts[category] = recordCount;
        for (equipmentType = 0; equipmentType < 4; equipmentType++) {
            if ((func_0016f720(pcId, equipmentType) & (1u << category)) != 0) {
                CampEquipmentEntry* entry = campEquipmentEntry(work, recordCount++);
                campEquipmentPopulateWithCategory(entry, pcId, equipmentType, category);
            }
        }
    }
    work->entryCount = recordCount;
}

// FUN_0013d1a0 NONMATCHING

void FUN_0013d1a0(void* texture,u64 position,CampEquipmentWork* work,s32 alpha)

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
    FUN_001159f0(originX + 2.0,originY + 6.0 + (float)(work->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 496.0,originY + 6.0 + (float)(work->selectedEntry * 0x1a),
                 texture);
  }
  xBase = originY + 6.0;
  FUN_001159f0(originX + 511.0,xBase,texture);
  rowIndex = work->entryCount + -5;
  if (rowIndex < 1) {
    rowIndex = 0;
  }
  else {
    rowIndex = (work->firstVisibleEntry * 0x59) / rowIndex;
  }
  FUN_001159f0(originX + 511.0,xBase + (float)rowIndex + 4.0,texture);
  rowIndex = 0;
  xRow = originX + 15.0;
  color = 0xffU - alpha | 0xffffff00;
  yValue = originY + 9.0;
  xIcon = originX + 288.0;
  yBase = originY + 16.0;
  xValue = originX + 325.0;
  xBase = originX + 341.0;
  xMarker = originX + 357.0;
  do {
    if ((4 < rowIndex) ||
       (entryIndex = rowIndex + work->firstVisibleEntry, work->entryCount <= entryIndex)) {
      return;
    }
    if (rowIndex == work->selectedEntry) {
      textureIndex = rowIndex * 0x1a;
      FUN_001159f0(xRow,(originY + 2.0 + (float)textureIndex) - 1.0,texture);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b2cb0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)textureIndex + 1.0 + 1.0),color,6,1,
                   textBuffer,0x10,0);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013dd14;
          }
          else {
            H_Maestro_001120a0(1);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013dd14:
            H_Maestro_001120a0(1);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(1);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013ddc4;
            yValue3 = yValue + (float)textureIndex;
            FUN_001159f0(xIcon,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013d8a8;
            }
            else {
              H_Maestro_001120a0(1);
              FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013d8a8:
              H_Maestro_001120a0(1);
              FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0;
            H_Maestro_001120a0(1);
            FUN_001159f0(xMarker,yValue2,texture);
            FUN_001159f0(originX + 404.0,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013da24;
            }
            else {
              H_Maestro_001120a0(1);
              FUN_001159f0(originX + 441.0,yValue2,texture);
LAB_0013da24:
              H_Maestro_001120a0(1);
              FUN_001159f0(originX + 457.0,yValue2,texture);
            }
            H_Maestro_001120a0(1);
            FUN_001159f0(originX + 473.0,yValue2,texture);
            goto LAB_0013ddc4;
          }
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013db80;
          }
          else {
            H_Maestro_001120a0(1);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013db80:
            H_Maestro_001120a0(1);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(1);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
      }
LAB_0013ddc4:
      ;
      FUN_003c7e20(texture,(int)(originX + 10.0),(int)(originY + 200.0),color,1,10,1,
                   (u32)campEquipmentEffectAndId(campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)));
    }
    else {
      textureIndex = rowIndex * 0x1a;
      FUN_00115bc0(xRow,(originY + 2.0 + (float)textureIndex) - 1.0,texture);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b2cb0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)textureIndex + 1.0),color,10,1,textBuffer,
                   0x10,0);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013e5e4;
          }
          else {
            H_Maestro_001120a0(2);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013e5e4:
            H_Maestro_001120a0(2);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(2);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013e694;
            yValue3 = yValue + (float)textureIndex;
            FUN_001159f0(xIcon,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013e178;
            }
            else {
              H_Maestro_001120a0(2);
              FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013e178:
              H_Maestro_001120a0(2);
              FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0;
            H_Maestro_001120a0(2);
            FUN_001159f0(xMarker,yValue2,texture);
            FUN_001159f0(originX + 404.0,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013e2f4;
            }
            else {
              H_Maestro_001120a0(2);
              FUN_001159f0(originX + 441.0,yValue2,texture);
LAB_0013e2f4:
              H_Maestro_001120a0(2);
              FUN_001159f0(originX + 457.0,yValue2,texture);
            }
            H_Maestro_001120a0(2);
            FUN_001159f0(originX + 473.0,yValue2,texture);
            goto LAB_0013e694;
          }
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013e450;
          }
          else {
            H_Maestro_001120a0(2);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013e450:
            H_Maestro_001120a0(2);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(2);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
      }
    }
LAB_0013e694:
    rowIndex = rowIndex + 1;
  } while( true );
}



// FUN_0013e710 NONMATCHING

void FUN_0013e710(void* texture,u64 position,CampEquipmentWork* work,s32 alpha)

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
    FUN_001159f0(originX + 2.0,originY + 6.0 + (float)(work->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 496.0,originY + 6.0 + (float)(work->selectedEntry * 0x1a),
                 texture);
  }
  xBase = originY + 6.0;
  FUN_001159f0(originX + 511.0,xBase,texture);
  rowIndex = work->entryCount + -5;
  if (rowIndex < 1) {
    rowIndex = 0;
  }
  else {
    rowIndex = (work->firstVisibleEntry * 0x59) / rowIndex;
  }
  FUN_001159f0(originX + 511.0,xBase + (float)rowIndex + 4.0,texture);
  rowIndex = 0;
  xRow = originX + 15.0;
  color = 0xffU - alpha | 0xffffff00;
  yValue = originY + 9.0;
  xIcon = originX + 288.0;
  yBase = originY + 16.0;
  xValue = originX + 325.0;
  xBase = originX + 341.0;
  xMarker = originX + 357.0;
  do {
    if ((4 < rowIndex) ||
       (entryIndex = rowIndex + work->firstVisibleEntry, work->entryCount <= entryIndex)) {
      return;
    }
    if (rowIndex == work->selectedEntry) {
      textureIndex = rowIndex * 0x1a;
      FUN_001159f0(xRow,(originY + 2.0 + (float)textureIndex) - 1.0,texture);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)textureIndex + 1.0 + 1.0),color,6,1,
                   textBuffer,0x10,0x78);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013f2a0;
          }
          else {
            H_Maestro_001120a0(1);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013f2a0:
            H_Maestro_001120a0(1);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(1);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013f350;
            yValue3 = yValue + (float)textureIndex;
            FUN_001159f0(xIcon,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013ee34;
            }
            else {
              H_Maestro_001120a0(1);
              FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013ee34:
              H_Maestro_001120a0(1);
              FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0;
            H_Maestro_001120a0(1);
            FUN_001159f0(xMarker,yValue2,texture);
            FUN_001159f0(originX + 404.0,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013efb0;
            }
            else {
              H_Maestro_001120a0(1);
              FUN_001159f0(originX + 441.0,yValue2,texture);
LAB_0013efb0:
              H_Maestro_001120a0(1);
              FUN_001159f0(originX + 457.0,yValue2,texture);
            }
            H_Maestro_001120a0(1);
            FUN_001159f0(originX + 473.0,yValue2,texture);
            goto LAB_0013f350;
          }
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013f10c;
          }
          else {
            H_Maestro_001120a0(1);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013f10c:
            H_Maestro_001120a0(1);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(1);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
      }
LAB_0013f350:
      ;
      FUN_003c7e20(texture,(int)(originX + 10.0 + 14.0),(int)((originY + 200.0) - 40.0),color,
                   1,10,1,(u32)campEquipmentEffectAndId(campEquipmentEntry(work, work->firstVisibleEntry + rowIndex))
                  );
    }
    else {
      textureIndex = rowIndex * 0x1a;
      FUN_00115bc0(xRow,(originY + 2.0 + (float)textureIndex) - 1.0,texture);
      ;
      textValue = func_00171110((s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->itemId,(s16)campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->slotType);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)textureIndex + 1.0),color,10,1,textBuffer,
                   0x10,0x78);
      category = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->equipmentClass;
      if (category != '\x03') {
        if (category == '\x02') {
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueD;
          if (value < 100) {
            if (9 < value) goto LAB_0013fb70;
          }
          else {
            H_Maestro_001120a0(2);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013fb70:
            H_Maestro_001120a0(2);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(2);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
        else {
          if (category != '\x01') {
            if (category != '\0') goto LAB_0013fc20;
            yValue3 = yValue + (float)textureIndex;
            FUN_001159f0(xIcon,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueA;
            if (value < 100) {
              if (9 < value) goto LAB_0013f704;
            }
            else {
              H_Maestro_001120a0(2);
              FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013f704:
              H_Maestro_001120a0(2);
              FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
            }
            yValue2 = (yBase + (float)(rowIndex * 0x1a)) - 3.0;
            H_Maestro_001120a0(2);
            FUN_001159f0(xMarker,yValue2,texture);
            FUN_001159f0(originX + 404.0,yValue3,texture);
            value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueB;
            if (value < 100) {
              if (9 < value) goto LAB_0013f880;
            }
            else {
              H_Maestro_001120a0(2);
              FUN_001159f0(originX + 441.0,yValue2,texture);
LAB_0013f880:
              H_Maestro_001120a0(2);
              FUN_001159f0(originX + 457.0,yValue2,texture);
            }
            H_Maestro_001120a0(2);
            FUN_001159f0(originX + 473.0,yValue2,texture);
            goto LAB_0013fc20;
          }
          FUN_001159f0(xIcon,yValue + (float)textureIndex,texture);
          value = campEquipmentEntry(work, work->firstVisibleEntry + rowIndex)->valueC;
          if (value < 100) {
            if (9 < value) goto LAB_0013f9dc;
          }
          else {
            H_Maestro_001120a0(2);
            FUN_001159f0(xValue,(yBase + (float)textureIndex) - 3.0,texture);
LAB_0013f9dc:
            H_Maestro_001120a0(2);
            FUN_001159f0(xBase,(yBase + (float)textureIndex) - 3.0,texture);
          }
          H_Maestro_001120a0(2);
          FUN_001159f0(xMarker,(yBase + (float)textureIndex) - 3.0,texture);
        }
      }
    }
LAB_0013fc20:
    rowIndex = rowIndex + 1;
  } while( true );
}



// FUN_0013fca0 NONMATCHING

void FUN_0013fca0(void* texture,u64 position,CampEquipmentWork* work,s32 alpha)

{
  char category;
  u16 value;
  int entryIndex;
  const char* textValue;
  CampEquipmentEntry* selectedEquipment;
  float panelY;
  float panelBase;
  float originX;
  float originY;
  char textBuffer[256];
  
  entryIndex = work->selectedEntry;
  switch(campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->categoryMask) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
        break;
  }
  originY = campPackedY(position);
  originX = campPackedX(position);
  FUN_001159f0(originX + 15.0,(originY + 2.0) - 1.0,texture);
  selectedEquipment = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex);
  textValue = func_00171110((s16)selectedEquipment->itemId,
                             (s16)selectedEquipment->slotType);
  sprintf(textBuffer,DAT_007cb66c,textValue);
  FUN_003b2cb0(texture,(int)((float)(int)originX + 55.0),
               (int)((float)(int)originY + 11.0 + 1.0),0xffU - alpha | 0xffffff00,10,1,
               textBuffer,0x10,0);
  category = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->equipmentClass;
  if (category == '\x03') {
    return;
  }
  if (category == '\x02') {
    FUN_001159f0(originX + 288.0,originY + 9.0,texture);
    value = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->valueD;
    if (value < 100) {
      if (value < 10) goto LAB_0014062c;
    }
    else {
      H_Maestro_001120a0(2);
      FUN_001159f0(originX + 325.0,(originY + 16.0) - 3.0,texture);
    }
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 341.0,(originY + 16.0) - 3.0,texture);
LAB_0014062c:
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 357.0,(originY + 16.0) - 3.0,texture);
    return;
  }
  if (category == '\x01') {
    FUN_001159f0(originX + 288.0,originY + 9.0,texture);
    value = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->valueC;
    if (value < 100) {
      if (value < 10) goto LAB_00140450;
    }
    else {
      H_Maestro_001120a0(2);
      FUN_001159f0(originX + 325.0,(originY + 16.0) - 3.0,texture);
    }
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 341.0,(originY + 16.0) - 3.0,texture);
LAB_00140450:
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 357.0,(originY + 16.0) - 3.0,texture);
    return;
  }
  if (category != '\0') {
    return;
  }
  panelY = originY + 9.0;
  FUN_001159f0(originX + 288.0,panelY,texture);
  value = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->valueA;
  if (value < 100) {
    if (9 < value) goto LAB_0014008c;
  }
  else {
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 325.0,(originY + 16.0) - 3.0,texture);
LAB_0014008c:
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 341.0,(originY + 16.0) - 3.0,texture);
  }
  panelBase = (originY + 16.0) - 3.0;
  H_Maestro_001120a0(2);
  FUN_001159f0(originX + 357.0,panelBase,texture);
  FUN_001159f0(originX + 404.0,panelY,texture);
  value = campEquipmentEntry(work, work->firstVisibleEntry + entryIndex)->valueB;
  if (value < 100) {
    if (value < 10) goto LAB_00140290;
  }
  else {
    H_Maestro_001120a0(2);
    FUN_001159f0(originX + 441.0,panelBase,texture);
  }
  H_Maestro_001120a0(2);
  FUN_001159f0(originX + 457.0,panelBase,texture);
LAB_00140290:
  H_Maestro_001120a0(2);
  FUN_001159f0(originX + 473.0,panelBase,texture);
  return;
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
    FUN_001159f0(originX + 2.0,originY + 6.0 + (float)(detail->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 317.0,originY + 6.0 + (float)(detail->selectedEntry * 0x1a),
                 texture);
  }
  panelX = originX + 331.0;
  FUN_001159f0(panelX,originY + 6.0,texture);
  entryIndex = detail->entryCount + -5;
  if (entryIndex < 1) {
    entryIndex = 0;
  }
  else {
    entryIndex = (detail->firstVisibleEntry * 0x59) / entryIndex;
  }
  FUN_001159f0(panelX,originY + 10.0 + (float)entryIndex,texture);
  panelBase = originX + 15.0;
  packedValue = 0xffU - alpha | 0xffffff00;
  panelY = originY + 16.0;
  panelX = originX + 293.0;
  for (entryIndex = 0; (entryIndex < 5 && (entryIndex + detail->firstVisibleEntry < detail->entryCount));
      entryIndex = entryIndex + 1) {
    if (entryIndex == detail->selectedEntry) {
      variant = entryIndex * 0x1a;
      FUN_001159f0(panelBase,(originY + 2.0 + (float)variant) - 1.0,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)variant + 1.0 + 1.0),packedValue,6,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(1);
        FUN_001159f0(originX + 277.0,(panelY + (float)variant) - 3.0,texture);
      }
      H_Maestro_001120a0(1);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0,texture);
      FUN_003c7e20(texture,(int)(originX + 10.0 + 14.0),(int)((originY + 200.0) - 40.0),packedValue,
                   1,10,0,campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
    }
    else {
      variant = entryIndex * 0x1a;
      FUN_00115bc0(panelBase,(originY + 2.0 + (float)variant) - 1.0,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)variant + 1.0 + 1.0),packedValue,10,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(2);
        FUN_001159f0(originX + 277.0,(panelY + (float)variant) - 3.0,texture);
      }
      H_Maestro_001120a0(2);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0,texture);
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
    FUN_001159f0(originX + 2.0,originY + 6.0 + (float)(detail->selectedEntry * 0x1a),
                 texture);
    FUN_001159f0(originX + 317.0,originY + 6.0 + (float)(detail->selectedEntry * 0x1a),
                 texture);
  }
  panelX = originX + 331.0;
  FUN_001159f0(panelX,originY + 6.0,texture);
  entryIndex = detail->entryCount + -5;
  if (entryIndex < 1) {
    entryIndex = 0;
  }
  else {
    entryIndex = (detail->firstVisibleEntry * 0x59) / entryIndex;
  }
  FUN_001159f0(panelX,originY + 10.0 + (float)entryIndex,texture);
  panelBase = originX + 15.0;
  packedValue = 0xffU - alpha | 0xffffff00;
  panelY = originY + 16.0;
  panelX = originX + 293.0;
  for (entryIndex = 0; (entryIndex < 5 && (entryIndex + detail->firstVisibleEntry < detail->entryCount));
      entryIndex = entryIndex + 1) {
    if (entryIndex == detail->selectedEntry) {
      variant = entryIndex * 0x1a;
      FUN_001159f0(panelBase,(originY + 2.0 + (float)variant) - 1.0,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)variant + 1.0 + 1.0),packedValue,6,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(1);
        FUN_001159f0(originX + 277.0,(panelY + (float)variant) - 3.0,texture);
      }
      H_Maestro_001120a0(1);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0,texture);
      FUN_003c7e20(texture,(int)(originX + 10.0 + 14.0),(int)((originY + 200.0) - 40.0),packedValue,
                   1,10,0,campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
    }
    else {
      variant = entryIndex * 0x1a;
      FUN_00115bc0(panelBase,(originY + 2.0 + (float)variant) - 1.0,texture);
      textValue = FUN_0017b100((u16)campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->itemId);
      sprintf(textBuffer,DAT_007cb66c,textValue);
      FUN_003b32d0(texture,(int)((float)(int)originX + 55.0),
                   (int)((float)(int)originY + 11.0 + (float)variant + 1.0 + 1.0),packedValue,10,1,
                   textBuffer,0x10,0x78);
      if (9 < campDetailEntry(detail, detail->firstVisibleEntry + entryIndex)->value) {
        H_Maestro_001120a0(2);
        FUN_001159f0(originX + 277.0,(panelY + (float)variant) - 3.0,texture);
      }
      H_Maestro_001120a0(2);
      FUN_001159f0(panelX,(panelY + (float)variant) - 3.0,texture);
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
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 1, 0x4140000042b40000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d8000043868000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d8000043b80000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043c38000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000044058000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d80000440b4000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 1, 0x4274000043310000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 1, 0x435b000043450000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 1, 0x4286000043fe0000, 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0;
      spriteTopLeft = CONCAT44(slotX + 8.0,0x41700000);
      index = row * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 1, spriteTopLeft, CONCAT44(slotX + 8.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft2 = CONCAT44(slotX + 31.0,0x41700000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 1, spriteTopLeft2, CONCAT44(slotX + 31.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft3 = CONCAT44(slotX + 45.0,0x41700000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 1, spriteTopLeft3, CONCAT44(slotX + 45.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CONCAT44(slotX + 64.0,0x41700000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 1, spriteTopLeft4, CONCAT44(slotX + 64.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CONCAT44(slotX + 2.0,0xc2100000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 1, spriteTopLeft5, CONCAT44(slotX + 2.0,0x41600000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800041400000, 0x43cf800042780000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000433d0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  return;
}



// FUN_00141fb0 NONMATCHING

void FUN_00141fb0(CampEquipmentPanelWork* work)

{
  int index;
  int row;
  float slotX;
  float slotY;
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042200000, 0x4140000042dc0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x88), 0, 2, 1, 0x41d80000435b0000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043630000, 0x4274000043948000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043770000, 0x435b000043948000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x42860000440b8000, 0x4286000044310000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0;
      if ((row == work->selectedSlot) || (work->selectedSlot == -2)) {
        slotY = 48.0;
        func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row * 10 + 0x24) * 0x44), 0, 2, 1, CONCAT44(slotX + 2.0,0x41600000), CONCAT44(slotX + 2.0,0x42780000), 0, 0, 0, 0);
      }
      else {
        slotY = 27.0;
        *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x994) = 0;
      }
      index = row * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, CONCAT44(slotX + 8.0,0x42820000), CONCAT44(slotX + 8.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, CONCAT44(slotX + 31.0,0x42820000), CONCAT44(slotX + 31.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, CONCAT44(slotX + 45.0,0x42820000), CONCAT44(slotX + 45.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, CONCAT44(slotX + 64.0,0x42820000), CONCAT44(slotX + 64.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, CONCAT44(slotX + 2.0,0x41600000), CONCAT44(slotX + 2.0,slotY + 14.0), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x12dc), 0, 2, 1, 0x43cf800042be0000, 0x43cf800042be0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x13a8), 0, 2, 1, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
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
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042dc0000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d800004404c000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x88), 0, 2, 2, 0x41d800004404c000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043948000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043948000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x4286000044310000, 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0;
      if ((row == work->selectedSlot) || (work->selectedSlot == -2)) {
        slotY = 48.0;
        spriteTopLeft2 = CONCAT44(slotX + 2.0,0x42780000);
        func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row * 10 + 0x24) * 0x44), 0, 2, 2, spriteTopLeft2, CONCAT44(slotX + 2.0,0x41600000), 0, 0, 0, 0);
      }
      else {
        slotY = 27.0;
        *(u32 *)(work->drawBuffer + row * 0x2a8 + 0x994) = 0;
      }
      spriteTopLeft3 = CONCAT44(slotX + 8.0,slotY + 65.0);
      index = row * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, spriteTopLeft3, CONCAT44(slotX + 8.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CONCAT44(slotX + 31.0,slotY + 65.0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, spriteTopLeft4, CONCAT44(slotX + 31.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CONCAT44(slotX + 45.0,slotY + 65.0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, spriteTopLeft5, CONCAT44(slotX + 45.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft6 = CONCAT44(slotX + 64.0,slotY + 65.0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, spriteTopLeft6, CONCAT44(slotX + 64.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft7 = CONCAT44(slotX + 2.0,slotY + 14.0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, spriteTopLeft7, CONCAT44(slotX + 2.0,0x41600000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x12dc), 0, 2, 2, 0x43cf800042be0000, 0x43cf800042be0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x13a8), 0, 2, 2, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  return;
}



// FUN_001432f0 NONMATCHING

void FUN_001432f0(CampEquipmentPanelWork* work)

{
  u64 packedValue;
  int row;
  int entryIndex;
  float slotY;
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 2, 0x4140000042200000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 2, 0x4274000043630000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 2, 0x435b000043770000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 2, 0x42860000440b8000, 0x42860000440b8000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (float)(entryIndex * 0x55) + 62.0;
      row = entryIndex * 10;
      packedValue = CONCAT44(slotY + 8.0,0x42820000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1e) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CONCAT44(slotY + 31.0,0x42820000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1f) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CONCAT44(slotY + 45.0,0x42820000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x20) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CONCAT44(slotY + 64.0,0x42820000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x21) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
      packedValue = CONCAT44(slotY + 2.0,0x41600000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x22) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
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
      panelX = (float)(entryIndex * 0x55) + 62.0;
      if (entryIndex == work->selectedSlot) {
        slotY = 48.0;
        spriteTopLeft8 = CONCAT44(panelX + 2.0,0x42240000);
        func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (entryIndex * 10 + 0x24) * 0x44), 0, 2, 1, spriteTopLeft8, CONCAT44(panelX + 2.0,0x42780000), 0, 0, 0, 0);
      }
      else {
        if (entryIndex != targetSlot) goto LAB_00143e94;
        slotY = 27.0;
        func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (entryIndex * 10 + 0x24) * 0x44), 0, 2, 2, *(u64 *)(work->drawBuffer + entryIndex * 0x2a8 + 0x9c8), CONCAT44(panelX + 2.0,0x42240000), 0, 0, 0, 0);
      }
      row = entryIndex * 0x2a8;
      index = entryIndex * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x830), CONCAT44(panelX + 8.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x874), CONCAT44(panelX + 31.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x8b8), CONCAT44(panelX + 45.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x8fc), CONCAT44(panelX + 64.0,slotY + 65.0), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 0, *(u64 *)(work->drawBuffer + row + 0x940), CONCAT44(panelX + 2.0,slotY + 14.0), 0, 0, 0, 0);
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
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042200000, 0x4140000042dc0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x88), 0, 2, 1, 0x41d80000435b0000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, 0x4274000043630000, 0x4274000043948000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 0, 0x435b000043770000, 0x435b000043948000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, 0x42860000440b8000, 0x4286000044310000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0;
      index = row * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 2, CONCAT44(slotX + 8.0,0x42820000), CONCAT44(slotX + 8.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 2, CONCAT44(slotX + 31.0,0x42820000), CONCAT44(slotX + 31.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 2, CONCAT44(slotX + 45.0,0x42820000), CONCAT44(slotX + 45.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 2, CONCAT44(slotX + 64.0,0x42820000), CONCAT44(slotX + 64.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 2, CONCAT44(slotX + 2.0,0x41600000), CONCAT44(slotX + 2.0,0xc2ac0000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1320), 0, 2, 1, 0x43cf800041d00000, 0x43cf800041d00000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x13a8), 0, 2, 1, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  for (row = 0; row < 0xc; row = row + 1) {
    if (row < work->listCount) {
      if (row == work->highlightedSlot) {
        labelY = 21.0;
      }
      else {
        labelY = 0.0;
      }
      labelX = (float)(row * 0x1d) + 61.0;
      spriteTopLeft7 = CONCAT44(labelX,labelY - 100.0);
      func_0018bc10(0x42ce0000, (void*)(work->drawBuffer + (row + 10) * 0x44), 0, 2, 1, spriteTopLeft7, CONCAT44(labelX,labelY), 0, 0, 0, 0);
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
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 0, 0x4140000042dc0000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d800004404c000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x88), 0, 2, 2, 0x41d800004404c000, 0x41d800004404c000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d80000439f0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043aa8000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000043f20000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d8000043fd8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 0, *(u64 *)(work->drawBuffer + 0x214), 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 0, *(u64 *)(work->drawBuffer + 600), 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 0, *(u64 *)(work->drawBuffer + 0x830), 0x42860000440b8000, 0, 0, 0, 0);
  for (row = 0; row < 4; row = row + 1) {
    if (row < work->visibleCount) {
      slotX = (float)(row * 0x55) + 62.0;
      spriteTopLeft2 = CONCAT44(slotX + 8.0,0xc20c0000);
      index = row * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1e) * 0x44), 0, 2, 1, spriteTopLeft2, CONCAT44(slotX + 8.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft3 = CONCAT44(slotX + 31.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x1f) * 0x44), 0, 2, 1, spriteTopLeft3, CONCAT44(slotX + 31.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft4 = CONCAT44(slotX + 45.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x20) * 0x44), 0, 2, 1, spriteTopLeft4, CONCAT44(slotX + 45.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft5 = CONCAT44(slotX + 64.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x21) * 0x44), 0, 2, 1, spriteTopLeft5, CONCAT44(slotX + 64.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeft6 = CONCAT44(slotX + 2.0,0xc2ac0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (index + 0x22) * 0x44), 0, 2, 1, spriteTopLeft6, CONCAT44(slotX + 2.0,0x41600000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf800042780000, 0x43cf800042780000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1320), 0, 2, 2, 0x43cf800041d00000, 0x43cf800041d00000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000436f0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x13a8), 0, 2, 2, 0x43cf800043e28000, 0x43cf800043e28000, 0, 0, 0, 0);
  for (row = 0; row < 0xc; row = row + 1) {
    if (row < work->listCount) {
      if (row == work->highlightedSlot) {
        labelY = 21.0;
      }
      else {
        labelY = 0.0;
      }
      labelX = (float)(row * 0x1d) + 61.0;
      func_0018bc10(0x42ce0000, (void*)(work->drawBuffer + (row + 10) * 0x44), 0, 2, 2, CONCAT44(labelX,labelY), CONCAT44(labelX,labelY - 100.0), 0, 0, 0, 0);
    }
    else {
      *(u32 *)(work->drawBuffer + row * 0x44 + 0x2ac) = 0;
    }
  }
  return;
}



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



// FUN_00145520 NONMATCHING

void FUN_00145520(CampEquipmentDrawItem* item, s32 menuCode, u8* workData)
{
    CampEquipmentMenuWork* menu = (CampEquipmentMenuWork*)workData;
    DatPersonaWork* persona;
    void* resourceRecord;
    const char* resourceText;
    u16 resourceItemId;
    u32 resourceFlags;
    u32 textColor;
    u32 value;
    u32 denominator;
    u16 statValue;
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
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        FUN_001159f0(item->x, item->y, item->texture);
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
        FUN_001159f0(item->x + 50.0, item->y + 3.0, item->texture);

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
            if (selected != 0) {
                FUN_001159f0(item->x + 9.0, item->y + 9.0, item->texture);
            } else {
                FUN_001159f0(item->x + 8.0, item->y + 8.0, item->texture);
            }
        }
        if (selected != 0) {
            if (persona->level > 9) {
                H_Maestro_001120a0(1);
                FUN_001159f0(item->x + 78.0, item->y + 11.0, item->texture);
            }
            H_Maestro_001120a0(1);
            FUN_001159f0(item->x + 94.0, item->y + 11.0, item->texture);
        } else {
            if (persona->level > 9) {
                H_Maestro_001120a0(2);
                FUN_001159f0(item->x + 78.0, item->y + 11.0, item->texture);
            }
            H_Maestro_001120a0(2);
            FUN_001159f0(item->x + 94.0, item->y + 11.0, item->texture);
        }
        resourceText = FUN_00173220(persona->id);
        textColor = (0xffU - item->alpha) | 0xffffff00;
        FUN_003b2cb0((void*)0x42c80000, (s32)(item->x + 120.0 - 10.0),
                     (s32)(item->y + 10.0), textColor, 10, 1, resourceText,
                     0x10, 0);
        break;
    case 0x1e:
    case 0x28:
    case 0x32:
    case 0x3c:
        statIndex = (menuCode - 0x1e) / 10;
        statValue = (u16)menu->categoryValues[statIndex];
        resourceText = FUN_00177790((s16)statValue);
        textColor = (0xffU - item->alpha) | 0xffffff00;
        sprintf(textBuffer, DAT_007cb66c, resourceText);
        FUN_003b32d0(item->texture, (s32)item->x, (s32)item->y + 3,
                     textColor, 10, 1, textBuffer, 0x10, 0x78);
        break;
    case 0x1f:
    case 0x29:
    case 0x33:
    case 0x3d:
        statIndex = (menuCode - 0x1f) / 10;
        statValue = (u16)menu->categoryValues[statIndex];
        value = FUN_0016c4f0(statValue) & 0xffff;
        rank = value > 99;
        if (rank != 0) {
            H_Maestro_001120a0(2);
            FUN_00115ad0(item->x, item->y, item->texture);
            value %= 100;
        }
        if (value > 9 || rank != 0) {
            H_Maestro_001120a0(2);
            FUN_00115ad0(item->x + 16.0, item->y, item->texture);
        }
        H_Maestro_001120a0(2);
        FUN_00115ad0(item->x + 32.0, item->y, item->texture);
        value = FUN_0016c4f0(statValue) & 0xffff;
        denominator = FUN_0016c5f0(statValue) & 0xffff;
        gaugeWidth = 0x4c - (value * 0x4c) / denominator;
        FUN_001159f0(item->x + 50.0, item->y + 2.0, item->texture);
        FUN_001159f0(item->x + 55.0, item->y + 1.0, item->texture);
        if (gaugeWidth != 0) {
            FUN_00113a30(campTextureAsFloat(item) - 1.0,
                         item->x + 56.0 + (f32)(0x4c - gaugeWidth),
                         item->y + 1.0, 0xffffffffffffff00, gaugeWidth, 10);
        }
        FUN_001159f0(item->x + 55.0, item->y + 1.0, item->texture);
        break;
    case 0x20:
    case 0x2a:
    case 0x34:
    case 0x3e:
        statIndex = (menuCode - 0x20) / 10;
        statValue = (u16)menu->categoryValues[statIndex];
        value = FUN_0016c570(statValue) & 0xffff;
        rank = value > 99;
        if (rank != 0) {
            H_Maestro_001120a0(2);
            FUN_00115ad0(item->x, item->y, item->texture);
            value %= 100;
        }
        if (value > 9 || rank != 0) {
            H_Maestro_001120a0(2);
            FUN_00115ad0(item->x + 16.0, item->y, item->texture);
        }
        H_Maestro_001120a0(2);
        FUN_00115ad0(item->x + 32.0, item->y, item->texture);
        value = FUN_0016c570(statValue) & 0xffff;
        denominator = func_0016c670(statValue) & 0xffff;
        gaugeWidth = 0x4c - (value * 0x4c) / denominator;
        FUN_001159f0(item->x + 50.0, item->y + 2.0, item->texture);
        FUN_001159f0(item->x + 55.0, item->y + 1.0, item->texture);
        if (gaugeWidth != 0) {
            FUN_00113a30(campTextureAsFloat(item) - 1.0,
                         item->x + 56.0 + (f32)(0x4c - gaugeWidth),
                         item->y + 1.0, 0xffffffffffffff00, gaugeWidth, 10);
        }
        FUN_001159f0(item->x + 55.0, item->y + 1.0, item->texture);
        break;
    case 0x21:
    case 0x2b:
    case 0x35:
    case 0x3f:
        statIndex = (menuCode - 0x20) / 10;
        statValue = (u16)menu->categoryValues[statIndex];
        rank = FUN_0016c470(statValue);
        if (rank > 9) {
            H_Maestro_001120a0(2);
            FUN_00115ad0(item->x, item->y, item->texture);
        }
        H_Maestro_001120a0(2);
        FUN_00115ad0(item->x + 16.0, item->y, item->texture);
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
            FUN_001159f0(item->x + 44.0, item->y - 6.0, item->texture);
        }
        break;
    case 0x22:
    case 0x2c:
    case 0x36:
    case 0x40:
        FUN_001159f0(item->x, item->y, item->texture);
        break;
    case 0x23:
    case 0x2d:
    case 0x37:
    case 0x41:
        FUN_001159f0(item->x, item->y, item->texture);
        break;
    case 0x24:
    case 0x2e:
    case 0x38:
    case 0x42:
        FUN_001159f0(item->x, item->y, item->texture);
        break;
    case 0x46:
    case 0x47:
        FUN_001159f0(item->x - 16.0, item->y, item->texture);
        FUN_001159f0(item->x, item->y, item->texture);
        break;
    case 0x48:
        FUN_001159f0(item->x, item->y, item->texture);
        FUN_001159f0(item->x + 16.0, item->y, item->texture);
        break;
    case 0x49:
        FUN_001159f0(item->x + 246.0, item->y, item->texture);
        FUN_001159f0(item->x + 322.0, item->y, item->texture);
        FUN_001159f0(item->x, item->y, item->texture);
        break;
    case 0x4a:
        FUN_001159f0(item->x + 32.0, item->y, item->texture);
        FUN_001159f0(item->x + 108.0, item->y, item->texture);
        break;
    default:
        break;
    }
}



// FUN_00146710 NONMATCHING

void FUN_00146710(CampEquipmentPanelWork* work)

{
  u64 packedValue;
  int row;
  int entryIndex;
  float slotY;
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 2, 0x4140000042200000, 0x41400000c2700000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 2, 0x41d80000435b0000, 0x41d8000042ee0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 2, 0x41d80000439f0000, 0x41d80000435a0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 2, 0x41d8000043aa8000, 0x41d8000043710000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 2, 0x41d8000043f20000, 0x41d8000043c00000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 2, 0x41d8000043fd8000, 0x41d8000043cb8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 2, 0x4274000043630000, 0x4274000042fe0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 2, 0x435b000043770000, 0x435b000043130000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 2, 0x42860000440b8000, 0x4286000043e50000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (float)(entryIndex * 0x55) + 62.0;
      row = entryIndex * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1e) * 0x44), 0, 2, 2, CONCAT44(slotY + 8.0,0x42820000), CONCAT44(slotY + 8.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1f) * 0x44), 0, 2, 2, CONCAT44(slotY + 31.0,0x42820000), CONCAT44(slotY + 31.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x20) * 0x44), 0, 2, 2, CONCAT44(slotY + 45.0,0x42820000), CONCAT44(slotY + 45.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x21) * 0x44), 0, 2, 2, CONCAT44(slotY + 64.0,0x42820000), CONCAT44(slotY + 64.0,0xc20c0000), 0, 0, 0, 0);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x22) * 0x44), 0, 2, 2, CONCAT44(slotY + 2.0,0x41600000), CONCAT44(slotY + 2.0,0xc2ac0000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 2, 0x43cf800042780000, 0x43cf8000c2180000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 2, 0x43cf8000436f0000, 0x43cf8000430b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)work->statusBuffer), 0, 2, 1, 0x4140000043ef8000, 0x4140000043bd8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x44)), 0, 2, 1, 0x41d8000042e20000, 0x41d8000041500000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x88)), 0, 2, 1, 0x41d8000043540000, 0x41d8000042e00000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0xcc)), 0, 2, 1, 0x41d80000436b0000, 0x41d8000043070000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x110)), 0, 2, 1, 0x41d8000043bd0000, 0x41d80000438b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x154)), 0, 2, 1, 0x41d8000043c88000, 0x41d8000043968000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (work->visibleCount + -1 < entryIndex) {
      *(u32 *)(work->statusBuffer + entryIndex * 0x44 + 0x2ac) = 0;
    }
    else {
      packedValue = CONCAT44((float)(entryIndex * 0x55) + 64.0,0x41f00000);
      func_0018bc10(0x42c80000, (void*)(work->statusBuffer + (entryIndex + 10) * 0x44), 0, 2, 1, packedValue, packedValue, 0, 0, 0, 0);
    }
  }
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x550)), 0, 2, 1, 0x42740000434c0000, 0x4274000042d00000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x594)), 0, 2, 1, 0x435b000043600000, 0x435b000042f80000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x83c)), 0, 2, 1, 0x43cf800043a30000, 0x43cf800043620000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x880)), 0, 2, 1, 0x43cf80004406c000, 0x43cf800043db8000, 0, 0, 0, 0);
  return;
}



// FUN_001474f0 NONMATCHING

void FUN_001474f0(CampEquipmentPanelWork* work)

{
  u64 packedValue;
  int row;
  int entryIndex;
  float slotY;
  u64 spriteTopLeftA;
  u64 spriteTopLeftB;
  u64 spriteTopLeftC;
  u64 spriteTopLeftD;
  u64 spriteTopLeftE;
  
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer), 0, 2, 1, 0x41400000c2700000, 0x4140000042200000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x44), 0, 2, 1, 0x41d8000042ee0000, 0x41d80000435b0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0xcc), 0, 2, 1, 0x41d80000435a0000, 0x41d80000439f0000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x110), 0, 2, 1, 0x41d8000043710000, 0x41d8000043aa8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x154), 0, 2, 1, 0x41d8000043c00000, 0x41d8000043f20000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x198), 0, 2, 1, 0x41d8000043cb8000, 0x41d8000043fd8000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1dc), 0, 2, 1, 0x4274000042fe0000, 0x4274000043630000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x220), 0, 2, 1, 0x435b000043130000, 0x435b000043770000, 0, 0, 0, 0);
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x7f8), 0, 2, 1, 0x4286000043e50000, 0x42860000440b8000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (entryIndex < work->visibleCount) {
      slotY = (float)(entryIndex * 0x55) + 62.0;
      spriteTopLeftA = CONCAT44(slotY + 8.0,0xc20c0000);
      row = entryIndex * 10;
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1e) * 0x44), 0, 2, 1, spriteTopLeftA, CONCAT44(slotY + 8.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeftB = CONCAT44(slotY + 31.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x1f) * 0x44), 0, 2, 1, spriteTopLeftB, CONCAT44(slotY + 31.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeftC = CONCAT44(slotY + 45.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x20) * 0x44), 0, 2, 1, spriteTopLeftC, CONCAT44(slotY + 45.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeftD = CONCAT44(slotY + 64.0,0xc20c0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x21) * 0x44), 0, 2, 1, spriteTopLeftD, CONCAT44(slotY + 64.0,0x42820000), 0, 0, 0, 0);
      spriteTopLeftE = CONCAT44(slotY + 2.0,0xc2ac0000);
      func_0018bc10(0x42c80000, (void*)(work->drawBuffer + (row + 0x22) * 0x44), 0, 2, 1, spriteTopLeftE, CONCAT44(slotY + 2.0,0x41600000), 0, 0, 0, 0);
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
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1298), 0, 2, 1, 0x43cf8000c2180000, 0x43cf800042780000, 0, 0, 0, 0);
  *(u32 *)(work->drawBuffer + 0x12e0) = 0;
  func_0018bc10(0x42c80000, (void*)(work->drawBuffer + 0x1364), 0, 2, 1, 0x43cf8000430b0000, 0x43cf8000436f0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)work->statusBuffer), 0, 2, 2, 0x4140000043bd8000, 0x4140000043ef8000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x44)), 0, 2, 2, 0x41d8000041500000, 0x41d8000042e20000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x88)), 0, 2, 2, 0x41d8000042e00000, 0x41d8000043540000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0xcc)), 0, 2, 2, 0x41d8000043070000, 0x41d80000436b0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x110)), 0, 2, 2, 0x41d80000438b0000, 0x41d8000043bd0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x154)), 0, 2, 2, 0x41d8000043968000, 0x41d8000043c88000, 0, 0, 0, 0);
  for (entryIndex = 0; entryIndex < 4; entryIndex = entryIndex + 1) {
    if (work->visibleCount + -1 < entryIndex) {
      *(u32 *)(work->statusBuffer + entryIndex * 0x44 + 0x2ac) = 0;
    }
    else {
      packedValue = CONCAT44((float)(entryIndex * 0x55) + 64.0,0x41f00000);
      func_0018bc10(0x42c80000, (void*)(work->statusBuffer + (entryIndex + 10) * 0x44), 0, 2, 2, packedValue, packedValue, 0, 0, 0, 0);
    }
  }
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x550)), 0, 2, 2, 0x4274000042d00000, 0x42740000434c0000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x594)), 0, 2, 2, 0x435b000042f80000, 0x435b000043600000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x83c)), 0, 2, 2, 0x43cf800043620000, 0x43cf800043a30000, 0, 0, 0, 0);
  func_0018bc10(100.0f, (void*)((u32)(work->statusBuffer + 0x880)), 0, 2, 2, 0x43cf800043db8000, 0x43cf80004406c000, 0, 0, 0, 0);
  return;
}




