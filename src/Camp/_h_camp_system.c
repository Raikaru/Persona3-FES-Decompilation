#include "Utils.h"
#include "Main/Game/game_support.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

typedef int bool;
#ifndef UINT32_C
#define UINT32_C(x) x##u
#endif
#ifndef UINT64_C
#define UINT64_C(x) x##ull
#endif
extern void *memcpy(void *dst, const void *src, u32 size);
void FUN_004d0f00();
void FUN_001124b0();
void H_Cdvd_Destroy();
void FUN_003c7dd0();
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
extern void *(*DAT_00960184)(u32 elementCount, u32 elementSize, u32 heapFlags);
extern const char D_005DBD00[];
extern const char D_005E3E70[];
extern void* h_campUpdateSystemMenuTask(KwlnTask* task);
extern u32 FUN_0017d800(void);
extern KwlnTask *FUN_00194B20(KwlnTask *parent, const char *name, u32 priority, KwlnTaskUpdateFunc update, KwlnTaskDestroyFunc destroy, void *workData);
// FUN_00154770. Destroy callback of the "H_CampSystemMenuDraw" task
void h_campSystemDestroyMenuDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
    if (workData[8] != 0) {
        FUN_004d0f00(workData[8]);
    }
    if (workData[5] != 0) {
        FUN_001124b0(workData[5]);
    }
    workData[5] = 0;
    if (workData[6] != 0) {
        FUN_001124b0(workData[6]);
    }
    workData[6] = 0;
    if (workData[3] != 0) {
        RwFree((void*)workData[3]);
    }
    workData[3] = 0;
    if (workData[4] != 0) {
        RwFree((void*)workData[4]);
    }
    workData[4] = 0;
    FUN_003c7dd0(8);
    FUN_003c7dd0(0xc);
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x24) != 0) {
            H_Cdvd_Destroy(*(int*)((int)workData + i * 4 + 0x24));
        }
        *(int*)((int)workData + i * 4 + 0x24) = 0;
    }
    RwFree(workData);
}

// FUN_001548A0
KwlnTask *FUN_001548a0(KwlnTask *parent, u32 priority)
{
    KwlnTask *task;
    void *work;

    work = (*DAT_00960184_abs)(1, 0x17c, 0x40000);
    if (work == NULL) {
        return NULL;
    }

    task = FUN_00194B20(parent, D_005DBD00, priority,
                        h_campUpdateSystemMenuTask,
                        h_campSystemDestroyMenuDrawTask, work);
    if (task == NULL) {
        return NULL;
    }

    if (FUN_0017d800() != 0) {
        *(u32 *)((u8 *)work + 4) = 4;
    }

    return task;
}


/* Camp system menu work (FUN_0015B330/FUN_0015B430), 0x17c bytes. */
typedef struct CampMenuEntry
{
    u32 state;
    u32 enabled;
    u32 drawMode;
    u8 unknown0c[0x0c];
    u32 progress;
    u32 progressLimit;
    u32 progressTarget;
    u32 color;
    u8 unknown28[0x10];
    f32 x;
    f32 y;
    u32 alpha;
} CampMenuEntry;
typedef union CampMenuAnimPair
{
    u64 q;
    f32 f[2];
} CampMenuAnimPair;
typedef struct CampMenuScratch
{
    u32 words[0x1e];
    CampMenuAnimPair shifted;
    CampMenuAnimPair pair;
    u32 tail[2];
} CampMenuScratch;
typedef struct CampMenuWork
{
    u32 state;
    u32 unknown04;
    u32 unknown08;
    u32 allocation10;
    u32 entriesAddress;
    u32 archiveBlob0;
    u32 archiveBlob1;
    u32 request;
    u32 requestResult;
    u32 cdvdMain;
    u32 cdvdStatus;
    u32 cdvdSystem;
    u32 entriesReady;
    u8 unknown34[0x120];
    u32 selectedPanel;
    u32 panelFlags[7];
    u32 fadeStep;
    u32 unknown178;
} CampMenuWork;
typedef char CampMenuEntrySizeCheck[(sizeof(CampMenuEntry) == 0x44) ? 1 : -1];
typedef char CampMenuWorkSizeCheck[(sizeof(CampMenuWork) == 0x17c) ? 1 : -1];
#define CAMP_MENU_ENTRY_COUNT 100
#define CAMP_MENU_ENTRY_SIZE 0x44
#define CAMP_MENU_PTR32(address) ((void *)(uintptr_t)(address))
#define CAMP_MENU_CONST_PTR(address) ((const char *)(uintptr_t)(address))
static inline CampMenuWork *camp_menu_work(KwlnTask *task)
{
    return (CampMenuWork *)task->workData;
}
static inline CampMenuEntry *camp_menu_entry(CampMenuWork *work, s32 index)
{
    return (CampMenuEntry *)((u8 *)CAMP_MENU_PTR32(work->entriesAddress) +
                             index * CAMP_MENU_ENTRY_SIZE);
}
static inline void *camp_menu_record(CampMenuWork *work, u32 offset)
{
    return (u8 *)CAMP_MENU_PTR32(work->entriesAddress) + offset;
}
static inline u32 camp_menu_address(const void *pointer)
{
    return (u32)(uintptr_t)pointer;
}

/* Item-list work used by FUN_0015C520/FUN_0015C840/FUN_0015CE50. */
static inline uintptr_t camp_list_base_address(u32 base)
{
    return (uintptr_t)(u32)base;
}
static inline u32 camp_list_load_u32(uintptr_t base, size_t offset)
{
    return *(const u32 *)(base + offset);
}
static inline s32 camp_list_load_s32(uintptr_t base, size_t offset)
{
    return *(const s32 *)(base + offset);
}
static inline u16 camp_list_load_u16(uintptr_t base, size_t offset)
{
    return *(const u16 *)(base + offset);
}
static inline void camp_list_store_u32(uintptr_t base, size_t offset, u32 value)
{
    *(u32 *)(base + offset) = value;
}
static f32 camp_list_bits_to_float(u32 bits)
{
    union { u32 bits; f32 value; } converter; converter.bits = bits; return converter.value;
}
static u32 camp_list_float_to_bits(f32 value)
{
    union { u32 bits; f32 value; } converter; converter.value = value; return converter.bits;
}
static u64 camp_list_pack_f32(f32 high, f32 low)
{
    return ((u64)camp_list_float_to_bits(high) << 32) | camp_list_float_to_bits(low);
}
static f32 camp_list_packed_low_f32(u64 packed)
{
    return camp_list_bits_to_float((u32)packed);
}
static f32 camp_list_packed_high_f32(u64 packed)
{
    return camp_list_bits_to_float((u32)(packed >> 32));
}
#define CAMP_LIST_CONST_PTR(address) ((const char *)(uintptr_t)(address))
typedef struct CampC520ListEntry
{
    u8 unknown00[0x0c];
    u32 itemId;
    u32 unknown10;
    s16 mode;
    u8 unknown16[2];
    s32 spCost;
    s32 hpCost;
} CampC520ListEntry;
#pragma alias campC520PartyId FUN_0016DD60
extern u64 campC520PartyId(s32 index);
#pragma alias campC520NearHero FUN_001C7CE0
extern s32 campC520NearHero(s32 owner);

/* Camp draw/animation work used by FUN_0015E150..FUN_00160800. */
typedef struct CampDrawRecord
{
    u32 unknown00;
    u32 active;
    u32 unknown08;
    u32 unknown0c;
    u32 unknown10;
    u32 unknown14;
    s32 progress;
    s32 unknown1c;
    s32 target;
    u32 owner;
    u32 unknown28;
    u32 unknown2c;
    u32 unknown30;
    u32 unknown34;
    f32 x;
    f32 y;
    u32 alpha;
} CampDrawRecord;
typedef struct CampDrawWork
{
    s32 state;
    s32 unknown04;
    s32 unknown08;
    s32 frame;
    s32 unknown10;
    s32 unknown14;
    s32 cursor;
    u32 archive0;
    u32 archive1;
    u32 archive2;
    u32 entryPool;
    s16 selectedKind;
    u16 selectedKindPad;
    u32 imageArchive;
    u32 unknown34;
    u32 records;
    s32 partyIds[4];
    s32 partyCount;
    u8 unknown050[0x104];
    s32 transitionFlag;
    u32 partyAnimations[7];
    s32 alpha;
} CampDrawWork;
typedef struct CampDrawSprite { u8 bytes[0x30]; } CampDrawSprite;
typedef char CampDrawRecordSizeCheck[(sizeof(CampDrawRecord) == 0x44) ? 1 : -1];
typedef char CampDrawWorkSizeCheck[(sizeof(CampDrawWork) == 0x178) ? 1 : -1];
static inline u32 camp_draw_load_u32(const void *base, size_t offset)
{
    return *(const u32 *)((const u8 *)base + offset);
}
static inline u64 camp_draw_load_u64(const void *base, size_t offset)
{
    return *(const u64 *)((const u8 *)base + offset);
}
static inline void camp_draw_store_u32(void *base, size_t offset, u32 value)
{
    *(u32 *)((u8 *)base + offset) = value;
}
static inline u16 camp_draw_load_u16(const void *base, size_t offset)
{
    return *(const u16 *)((const u8 *)base + offset);
}
static inline void camp_draw_store_u16(void *base, size_t offset, u16 value)
{
    *(u16 *)((u8 *)base + offset) = value;
}
static inline u8 camp_draw_load_u8(const void *base, size_t offset)
{
    return *((const u8 *)base + offset);
}
static inline void camp_draw_store_u8(void *base, size_t offset, u8 value)
{
    *((u8 *)base + offset) = value;
}
static inline f32 camp_draw_load_f32(const void *base, size_t offset)
{
    return *(const f32 *)((const u8 *)base + offset);
}
static inline void camp_draw_store_f32(void *base, size_t offset, f32 value)
{
    *(f32 *)((u8 *)base + offset) = value;
}
static inline u32 camp_draw_f32_bits(f32 value)
{
    union {
        f32 value;
        u32 bits;
    } converter;
    converter.value = value;
    return converter.bits;
}
static inline u64 camp_draw_concat44_words(u32 high, u32 low)
{
    return ((u64)high << 32) | low;
}
static inline u64 camp_draw_concat44_f32(f32 high, f32 low)
{
    return camp_draw_concat44_words(camp_draw_f32_bits(high), camp_draw_f32_bits(low));
}
static inline u64 camp_draw_record_xy(const CampDrawRecord *record)
{
    return camp_draw_concat44_f32(record->y, record->x);
}
static inline void *camp_draw_ptr_add(void *base, size_t offset)
{
    return (void *)((u8 *)base + offset);
}
static inline void *camp_draw_ptr32(u32 address)
{
    return (void *)(uintptr_t)address;
}
static inline u32 camp_draw_addr32(const void *address)
{
    return (u32)(uintptr_t)address;
}
static inline CampDrawWork *camp_draw_task_work(KwlnTask *task)
{
    return task == NULL ? NULL : (CampDrawWork *)task->workData;
}
static inline CampDrawRecord *camp_draw_state_records(CampDrawWork *work)
{
    return (CampDrawRecord *)camp_draw_ptr32(work->records);
}

/* Retail globals shared by these translated slices. */
#pragma alias campC520PreviousMode DAT_00836ba8
extern s16 campC520PreviousMode;
#pragma alias campC520SetMode FUN_00175200
extern void campC520SetMode(s16 mode);
#pragma alias campC520GetHp FUN_0016C4F0
extern s32 campC520GetHp(s32 arg0);
#pragma alias campC520GetSp FUN_0016C570
extern s32 campC520GetSp(s32 arg0);
extern u32 uGpffffb29c;
extern u32 uGpffffb288;
extern KwlnTask *iGpffffb258;
extern KwlnTask *iGpffffb270;
extern KwlnTask *iGpffffb26c;
extern void *uGpffffb260;
extern void *uGpffffb264;
extern void *uGpffffb268;
extern u32 DAT_00833b78;
#pragma alias DAT_00833a50_abs DAT_00833a50
extern u8 DAT_00833a50_abs[];
#pragma alias DAT_00833a54_abs DAT_00833a54
extern u8 DAT_00833a54_abs[];
#pragma alias DAT_00833a58_abs DAT_00833a58
extern u8 DAT_00833a58_abs[];
#pragma alias DAT_00833b78_abs DAT_00833b78
extern u8 DAT_00833b78_abs[];
extern void *DAT_00833a50;
extern void *DAT_00833a54;
extern void *DAT_00833a58;
extern u16 DAT_00836ba8;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e0958;
extern u16 DAT_007e095a;
extern s32 DAT_007cdf8c;
extern void *(*DAT_00960184)(u32 elementCount, u32 elementSize, u32 heapFlags);
extern const char D_005DBD20[];

extern void FUN_0018bc10(f32 first, void *animation, s32 start,
                         s32 end, s32 mode, u64 startValues,
                         u64 endValues, u32 param8, u32 param9);
/* Explicit unresolved retail API declarations. */
extern void *FUN_0010c1a0(u32 mode, const char *path, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern s32 FUN_0010c3a0(void *request, u32 *loaded, u64 arg3);
extern void *FUN_00100d80(const char *path, u32 mode);
extern void *FUN_00100d80(const char *path, u32 mode);
extern s32 FUN_001016b0(void *cdvd);
extern void *FUN_00102100(void *cdvd, s32 fileIndex, u32 *fileSize);
extern void *FUN_00112420(void *source);
extern s32 FUN_00111f30(void *maestroBlob);
extern void FUN_003c7d80(s32 slot, u64 textureId);
typedef struct CampD8Object
{
    u8 unknown00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 unknown19[0x13];
    f32 drawContext;
} CampD8Object;
#pragma alias campD8MakeSprite FUN_001158B0
extern CampD8Object *campD8MakeSprite(u32 parent, void *resource, u32 frame);
#pragma alias campD8SetSprite FUN_001127D0
extern void campD8SetSprite(CampD8Object *object, s32 mode);
#pragma alias campD8SubmitSprite FUN_00115980
extern void campD8SubmitSprite(CampD8Object *object);
extern void FUN_00113a30(f32 x, f32 y, f32 z, u32 color, s32 width, s32 height);
extern void FUN_00155830(void *record, void *blobPair, s32 index, u32 selectedPanel, const u32 *panelFlags);
extern void FUN_001599f0(void *record, void *blobPair, s32 category, u32 selectedPage, u32 subPage);
extern u32 FUN_0016f190(s32 flag);
extern void FUN_0010a4e0(s32 arg0, s32 arg1, s32 arg2, ...);
extern void FUN_00103c30(u16 arg0, u16 arg1, u16 arg2, u16 arg3);
extern void FUN_0016f1f0(s32 flag, u8 enabled);
extern void FUN_00103cb0(void);
extern u32 FUN_0017d800(void);
extern KwlnTask *FUN_00194B20(KwlnTask *parent, const char *name, u32 priority, KwlnTaskUpdateFunc update, KwlnTaskDestroyFunc destroy, void *workData);
extern u32 FUN_00119F10(KwlnTask *task, u32 arg1);
extern void FUN_00175200(u16 mode);
extern void *FUN_0017B660(u32 mode, u32 itemId);
extern void FUN_0017B860(u32 mode, u64 owner, u32 itemId, u32 arg3);
extern s16 FUN_0016DD60(s32 arg0);
extern void *FUN_001C7CE0(u64 owner);
extern void *FUN_0017BC20(u32 mode, u64 owner, u32 itemId, u32 arg3);
extern s16 FUN_0016C4F0(s32 arg0);
extern void FUN_0016CF40(s32 arg0, s16 value);
extern s16 FUN_0016C570(s32 arg0);
extern void FUN_0016CF90(s32 arg0, s16 value);
extern void *FUN_00174960(u16 arg0);
extern void *FUN_00174A90(u16 arg0);
extern u8 FUN_00173660(uintptr_t arg0, s32 arg1);
extern s16 FUN_0017B480(u16 arg0);
extern s16 FUN_0017B500(u32 arg0, u16 arg1);
extern u32 FUN_0017B5B0(u32 arg0, u16 arg1);
extern s32 FUN_0017B4E0(u32 itemId);
extern s16 FUN_0017BB40(u32 value);
extern void FUN_001159F0(f32 x, f32 y, u32 drawContext);
extern void FUN_00115BC0(f32 x, f32 y, u32 drawContext);
extern void FUN_00115AD0(f32 x, f32 y, u32 drawContext);
extern void FUN_0017D2E0(u16 arg0);
extern u64 FUN_0030BB40(u16 arg0);
extern u32 FUN_00523AC8(void *dst, u32 stringId, u64 arg2);
extern void FUN_003B32D0(u32 drawContext, s32 x, s32 y, u32 color, s32 font, s32 flags, void *text, s32 width, s32 height);
extern void FUN_001120A0(s32 arg0);
extern void FUN_003c7e20(u32 drawContext, s32 x, s32 y, u32 color, s32 arg4, s32 arg5, s32 arg6);
extern u64 FUN_001158B0(u32 arg0, void *archive, u32 size);
extern void FUN_001127D0(u64 object, s32 arg1);
extern void FUN_00115980(u64 object);
extern void FUN_0011DA80(u32 arg0, void *object);
extern void FUN_00121DE0(void *object, u32 arg1);
extern void FUN_00122710(void *object, u32 arg1);
extern s32 FUN_0011E380(void *object, u32 arg1);
extern void FUN_0011BBA0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4);
extern void FUN_00114450(f32 arg0, f32 arg1, f32 arg2, s32 arg3,
                         u32 arg4, u32 arg5, u32 arg6);
extern void FUN_0011ABD0(u32 count, u32 visible, void *first, void *selected);
extern u8 FUN_0016C470(u16 arg0);
extern u64 FUN_0016C970(u16 arg0);
extern s16 FUN_0016C920(u16 arg0);
extern u32 FUN_0016C670(u16 arg0);
extern u32 FUN_0016C5F0(u16 arg0);
extern u64 FUN_00177790(u16 arg0);

void *FUN_0015B430(KwlnTask *task);
void FUN_0015C520(void *list, s32 ownerMode);
void FUN_0015C840(void *list);
void FUN_0015CE50(u64 packedPosition, f32 drawContext, void *list, s32 alpha);
void FUN_0015D8E0(u64 packedPosition, f32 drawContext, u8 alpha);
void FUN_0015DA70(void *work);
void FUN_0015E150(CampDrawWork *work);
void FUN_0015E6E0(CampDrawWork *work);
void FUN_0015EE40(CampDrawWork *work, s32 changedIndex);
void FUN_0015F320(CampDrawWork *work);
void FUN_0015FA90(CampDrawRecord *record, s32 recordIndex, CampDrawWork *work);


// FUN_0015B330
u32 FUN_0015B330(void *entries, void *blobPair,
                 u32 category, u32 selectedPage)
{
    s32 index;
    u32 allReady = 1;

    for (index = 0; index < CAMP_MENU_ENTRY_COUNT; index++) {
        CampMenuEntry *entry = (CampMenuEntry *)((u8 *)entries +
                                                       index * CAMP_MENU_ENTRY_SIZE);
        if (entry->enabled != 0) {
            if (func_0018b700(entry) != 0) {
                FUN_001599f0(entry, blobPair, index, category, selectedPage);
            }
            if (((CampMenuEntry *)((u8 *)entries +
                                  index * CAMP_MENU_ENTRY_SIZE))->progress !=
                ((CampMenuEntry *)((u8 *)entries +
                                  index * CAMP_MENU_ENTRY_SIZE))->progressTarget) {
                allReady = 0;
            }
        }
    }
    return allReady;
}

/*
 * Retail stores each animation endpoint as adjacent float pairs on the stack.
 * The state 6 and state 9 setup paths now preserve those copies and offsets.
 * This restores the missing add/subtract float operations and all panel calls.
 * The reconstructed object is larger and has a higher normalized diff for now.
 * Keep this marker NONMATCHING until register layout and dispatch scheduling converge.
 */
// FUN_0015B430 NONMATCHING
void *FUN_0015B430(KwlnTask *task)
{
    CampMenuWork *work = camp_menu_work(task);
    s32 systemReady;
    s32 index;
    u32 selected;
    u32 allReady;
    bool inputHeld;
    CampMenuScratch scratch;
    void *fileData;

    /* The retail fade rectangle uses 100.0f, 20.0f and an encoded colour. */
    FUN_00113a30(100.0f, 0.0f, 20.0f,
                 ((work->fadeStep * 0xffu) / 10u) | 0x72b5ff00u,
                 0x280, 0x19a);

    switch (work->state) {
    case 0:
        if (iGpffffb258 == NULL) {
            systemReady = -1;
        } else {
            /* Retail dereferences the task's +0x3c work pointer directly. */
            systemReady = (camp_menu_work(iGpffffb258)->state == 3);
        }
        if (systemReady != 1) {
            return 0;
        }

        if (FUN_0017d800() != 0) {
            work->request = camp_menu_address(FUN_0010c1a0(
                0, (const char *)(D_005E3E70 - 0x8e20), 0, 0, 0, 0, 0, 0));
        } else {
            work->request = camp_menu_address(FUN_0010c1a0(
                0, (const char *)(D_005E3E70 - 0x8dd0), 0, 0, 0, 0, 0, 0));
        }
        work->allocation10 = camp_menu_address(func_0018b6d0(10));
        work->entriesAddress = camp_menu_address(func_0018b6d0(CAMP_MENU_ENTRY_COUNT));
        work->cdvdMain = camp_menu_address(FUN_00100d80(
            CAMP_MENU_CONST_PTR(0x0059bca0), 0));
        work->cdvdStatus = camp_menu_address(FUN_00100d80(
            CAMP_MENU_CONST_PTR(0x0059bcc0), 0));
        work->cdvdSystem = camp_menu_address(FUN_00100d80(
            CAMP_MENU_CONST_PTR(0x0059bce0), 1));
        work->state = 1;
        break;

    case 1:
        if (work->requestResult == 0) {
            scratch.words[0] = 0;
            work->requestResult = (u32)FUN_0010c3a0(
                CAMP_MENU_PTR32(work->request), &scratch.words[0], 0);
            if (scratch.words[0] == 0) {
                work->requestResult = 0;
                return 0;
            }
        }
        if (FUN_001016b0(CAMP_MENU_PTR32(work->cdvdMain)) != 0 &&
            FUN_001016b0(CAMP_MENU_PTR32(work->cdvdStatus)) != 0 &&
            FUN_001016b0(CAMP_MENU_PTR32(work->cdvdSystem)) != 0) {
            FUN_003c7d80(0x0c,
                *(u32 *)((u8 *)CAMP_MENU_PTR32(work->cdvdMain) + 0x110));
            FUN_003c7d80(0x08,
                *(u32 *)((u8 *)CAMP_MENU_PTR32(work->cdvdStatus) + 0x110));
            fileData = FUN_00102100(CAMP_MENU_PTR32(work->cdvdSystem), 0,
                                    &scratch.tail[0]);
            work->archiveBlob0 = camp_menu_address(FUN_00112420(fileData));
            fileData = FUN_00102100(CAMP_MENU_PTR32(work->cdvdSystem), 1,
                                    &scratch.tail[0]);
            work->archiveBlob1 = camp_menu_address(FUN_00112420(fileData));
            work->state = 2;
        }
        break;

    case 2:
        if (FUN_00111f30(CAMP_MENU_PTR32(work->archiveBlob0)) != 0 &&
            FUN_00111f30(CAMP_MENU_PTR32(work->archiveBlob1)) != 0) {
            work->state = 6;
        }
        break;

    case 6:
        work->selectedPanel = 0;
        scratch.pair.f[0] = 21.0f;
        scratch.pair.f[1] = 215.0f;
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] -= 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x000),
                     0, 2, 1, scratch.shifted.q, scratch.pair.q, 0, 0);
        scratch.pair.f[0] = 50.0f;
        scratch.pair.f[1] = 263.0f;
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] -= 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x044),
                     0, 2, 1, scratch.shifted.q, scratch.pair.q, 0, 0);
        scratch.pair.f[0] = 87.0f;
        scratch.pair.f[1] = 92.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x088),
                     0, 2, 1, scratch.pair.q, scratch.pair.q, 0, 0);
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] -= 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x0cc),
                     0, 2, 1, scratch.shifted.q, scratch.pair.q, 0, 0);
        scratch.pair.f[0] = 388.0f;
        scratch.pair.f[1] = 92.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x110),
                     0, 2, 1, scratch.pair.q, scratch.pair.q, 0, 0);
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] -= 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x154),
                     0, 2, 1, scratch.shifted.q, scratch.pair.q, 0, 0);
        scratch.pair.f[0] = 95.0f;
        scratch.pair.f[1] = 93.0f;
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] += 200.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x198),
                     0, 2, 1, scratch.shifted.q, scratch.pair.q, 0, 0);
        for (index = 0; index < 7; index++) {
            work->panelFlags[index] = FUN_0016f190(index + 0x183);
        }
        scratch.pair.f[0] = 392.0f;
        scratch.pair.f[1] = 385.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x1a4c),
                     0, 2, 1, scratch.pair.q, scratch.pair.q, 0, 0);
        work->entriesReady = 0;
        work->state = 7;
        break;

    case 7:
        work->state = 8;
        selected = work->selectedPanel;
        for (index = 0; index < CAMP_MENU_ENTRY_COUNT; index++) {
            CampMenuEntry *entry = camp_menu_entry(work, index);
            if (entry->enabled != 0 && func_0018b700(entry) != 0) {
                FUN_00155830(entry, &work->archiveBlob0, index, selected,
                              work->panelFlags);
            }
        }
        break;

    case 8:
        work->fadeStep = work->fadeStep + 1;
        if (work->fadeStep > 10) {
            work->fadeStep = 10;
        }

        if (work->entriesReady != 0) {
            if ((DAT_007e094e & 0x40) == 0) {
                if ((DAT_007e094e & 0x20) == 0) {
                    inputHeld = ((DAT_007e0952 & 0x1000) != 0) ||
                                ((DAT_007e095a & 0x1000) != 0);
                    if (inputHeld) {
                        if (work->selectedPanel == 0) {
                            if ((DAT_007e094e & 0x1000) != 0 ||
                                (DAT_007e0958 & 0x1000) != 0) {
                                FUN_0010a4e0(0, 0, 0, 0);
                                work->selectedPanel = 7;
                            }
                        } else {
                            FUN_0010a4e0(0, 0, 0, 0);
                            work->selectedPanel = work->selectedPanel - 1;
                        }
                    } else if ((DAT_007e0952 & 0x4000) == 0 &&
                               (DAT_007e095a & 0x4000) == 0) {
                        if ((DAT_007e094e & 0x2000) == 0 &&
                            (DAT_007e0958 & 0x2000) == 0) {
                            if (((DAT_007e094e & 0x8000) != 0 ||
                                 (DAT_007e0958 & 0x8000) != 0) &&
                                work->selectedPanel != 7) {
                                if (work->panelFlags[work->selectedPanel] == 0) {
                                    FUN_0010a4e0(0, 0, 0, 5);
                                }
                                if (work->selectedPanel == 0 &&
                                    work->panelFlags[0] == 0) {
                                    FUN_00103c30(10, 0x96, 10, 0);
                                }
                                work->panelFlags[work->selectedPanel] = 1;
                            }
                        } else if (work->selectedPanel != 7 &&
                                   work->panelFlags[work->selectedPanel] != 0) {
                            FUN_0010a4e0(0, 0, 0, 5);
                            work->panelFlags[work->selectedPanel] = 0;
                        }
                    } else if (work->selectedPanel == 7) {
                        if ((DAT_007e094e & 0x4000) != 0 ||
                            (DAT_007e0958 & 0x4000) != 0) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            work->selectedPanel = 0;
                        }
                    } else {
                        FUN_0010a4e0(0, 0, 0, 0);
                        work->selectedPanel = work->selectedPanel + 1;
                    }
                } else {
                    FUN_0010a4e0(0, 0, 0, 2);
                    work->state = 9;
                }
            } else if (work->selectedPanel == 7) {
                FUN_0010a4e0(0, 0, 0, 1);
                for (index = 0; index < 7; index++) {
                    if (index == 2) {
                        if (work->panelFlags[1] == 0) {
                            FUN_0016f1f0(0x185, 0);
                        } else {
                            FUN_0016f1f0(0x185, (u8)work->panelFlags[2]);
                        }
                    } else {
                        FUN_0016f1f0(index + 0x183, (u8)work->panelFlags[index]);
                    }
                }
                if (FUN_0016f190(0x183) == 0) {
                    FUN_00103cb0();
                }
                uGpffffb288 = 1;
                work->state = 9;
            }
        }

        selected = work->selectedPanel;
        allReady = 1;
        for (index = 0; index < CAMP_MENU_ENTRY_COUNT; index++) {
            CampMenuEntry *entry = camp_menu_entry(work, index);
            if (entry->enabled != 0) {
                if (func_0018b700(entry) != 0) {
                    FUN_00155830(entry, &work->archiveBlob0, index, selected,
                                  work->panelFlags);
                }
                if (entry->progress != entry->progressTarget) {
                    allReady = 0;
                }
            }
        }
        work->entriesReady = allReady;
        break;

    case 9:
        selected = work->selectedPanel;
        for (index = 0; index < CAMP_MENU_ENTRY_COUNT; index++) {
            CampMenuEntry *entry = camp_menu_entry(work, index);
            if (entry->enabled != 0 && func_0018b700(entry) != 0) {
                FUN_00155830(entry, &work->archiveBlob0, index, selected,
                              work->panelFlags);
            }
        }
        scratch.pair.f[0] = 21.0f;
        scratch.pair.f[1] = 215.0f;
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] += 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x000),
                     0, 2, 2, scratch.pair.q, scratch.shifted.q, 0, 0);
        scratch.pair.f[0] = 50.0f;
        scratch.pair.f[1] = 263.0f;
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] += 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x044),
                     0, 2, 2, scratch.pair.q, scratch.shifted.q, 0, 0);
        scratch.pair.f[0] = 87.0f;
        scratch.pair.f[1] = 92.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x088),
                     0, 2, 2, scratch.pair.q, scratch.pair.q, 0, 0);
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] += 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x0cc),
                     0, 2, 2, scratch.pair.q, scratch.shifted.q, 0, 0);
        scratch.pair.f[0] = 388.0f;
        scratch.pair.f[1] = 92.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x110),
                     0, 2, 2, scratch.pair.q, scratch.pair.q, 0, 0);
        scratch.shifted = scratch.pair;
        scratch.shifted.f[1] += 600.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x154),
                     0, 2, 2, scratch.pair.q, scratch.shifted.q, 0, 0);
        scratch.pair.f[0] = 95.0f;
        scratch.pair.f[1] = 93.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x198),
                     0, 2, 2, scratch.pair.q, scratch.pair.q, 0, 0);
        work->state = 10;
        scratch.pair.f[0] = 392.0f;
        scratch.pair.f[1] = 385.0f;
        FUN_0018bc10(100.0f, camp_menu_record(work, 0x1a4c),
                     0, 2, 2, scratch.pair.q, scratch.pair.q, 0, 0);
        break;

    case 10:
        if (work->fadeStep == 0) {
            work->fadeStep = 0;
        } else {
            work->fadeStep = work->fadeStep - 1;
        }
        selected = work->selectedPanel;
        allReady = 1;
        for (index = 0; index < CAMP_MENU_ENTRY_COUNT; index++) {
            CampMenuEntry *entry = camp_menu_entry(work, index);
            if (entry->enabled != 0) {
                if (func_0018b700(entry) != 0) {
                    FUN_00155830(entry, &work->archiveBlob0, index, selected,
                                  work->panelFlags);
                }
                if (entry->progress != entry->progressTarget) {
                    allReady = 0;
                }
            }
        }
        if (allReady != 0) {
            return (void *)(uintptr_t)0xffffffffu;
        }
        break;
    }

    return 0;
}

// FUN_0015C460
KwlnTask *FUN_0015C460(KwlnTask *param_1)
{
    KwlnTask *task;
    void *work;
    u32 value;
    task = param_1;

    work = (*DAT_00960184_abs)(1, 0x17c, 0x40000);
    if (work == NULL) {
        return 0;
    }

    task = FUN_00194B20(param_1, D_005DBD20, 0x18be,
                        (KwlnTaskUpdateFunc)FUN_0015B430,
                        (KwlnTaskDestroyFunc)h_campSystemDestroyMenuDrawTask,
                        work);
    if (task == NULL) {
        return 0;
    }

    value = FUN_00119F10(task, 1);
    *(u32 *)((u8 *)work + 8) = value;
    return task;
}

// FUN_0015C520 NONMATCHING
void FUN_0015C520(void *param_1, s32 param_2)
{
    CampC520ListEntry *entry;
    s32 owner_mode;
    s32 entry_index;
    u32 item_id;
    s16 previous_mode;
    s32 i;
    s32 found_count;
    s16 relation;
    void *result;
    u64 owner;
    s32 hp;
    s32 sp;

    owner_mode = param_2;
    entry_index = *(s32 *)((u8 *)param_1 + 0x7e0) +
                  *(s32 *)((u8 *)param_1 + 0x7e4);
    entry = (CampC520ListEntry *)((u8 *)param_1 + entry_index * 0x14);
    item_id = entry->itemId;
    previous_mode = campC520PreviousMode;
    campC520SetMode(entry->mode);

    result = FUN_0017B660(1, item_id & 0xffffU);
    if (result == NULL) {
        if (owner_mode == -2) {
            FUN_0017B860(1, 1, item_id & 0xffffU, 0);
            i = 0;
            while (i < 3) {
                relation = (s16)campC520PartyId(i);
                if (relation != 0) {
                    owner = campC520PartyId(i);
                    if (campC520NearHero((s32)(s16)owner) != 0) {
                        owner = campC520PartyId(i);
                        result = FUN_0017BC20(1, owner, item_id & 0xffffU, 0);
                        if (result == NULL) {
                            FUN_0017B860(1, owner, item_id & 0xffffU, 0);
                        }
                    }
                }
                i++;
            }
        }
        else if (owner_mode == 0) {
            result = (void *)campC520NearHero(1);
            if ((result != NULL) &&
                (FUN_0017BC20(1, 1, item_id & 0xffffU, 0) == 0)) {
                FUN_0017B860(1, 1, item_id & 0xffffU, 0);
            }
        }
        else {
            found_count = 0;
            i = 0;
            while (i < 3) {
                relation = (s16)campC520PartyId(i);
                if (relation != 0) {
                    found_count++;
                    if (owner_mode == found_count) {
                        owner = campC520PartyId(i);
                        if (campC520NearHero((s32)(s16)owner) != 0) {
                            owner = campC520PartyId(i);
                            result = FUN_0017BC20(1, owner, item_id & 0xffffU, 0);
                            if (result == NULL) {
                                FUN_0017B860(1, owner, item_id & 0xffffU, 0);
                            }
                        }
                        break;
                    }
                }
                i++;
            }
        }

        entry_index *= 0x14;
        hp = campC520GetHp(1);
        FUN_0016CF40(1, (s16)((hp & 0xffff) -
                             *(s32 *)((u8 *)param_1 + entry_index + 0x1c)));
        sp = campC520GetSp(1);
        FUN_0016CF90(1, (s16)((sp & 0xffff) -
                             *(s32 *)((u8 *)param_1 + entry_index + 0x18)));
    }

    campC520SetMode(previous_mode);
}

// FUN_0015C840 NONMATCHING
void FUN_0015C840(void *param_1)
{
    const uintptr_t list = (uintptr_t)param_1;
    s16 previous_mode = DAT_00836ba8;
    u32 saved_entry[5];
    u32 candidate_entry[5];
    u32 swap_entry[5];
    s32 entry_count = 0;
    s32 item_index = 0;
    s32 i;
    s32 j;

    for (;;) {
        if (item_index > 0x0b) {
            camp_list_store_u32(list, 0x7dc, (u32)entry_count);

            /* Stable insertion-like ordering by item id.  IDs in 0xc0..0xff
             * sort after all IDs outside that range, matching the branch tree
             * in the retail routine. */
            for (i = 0; i < entry_count; ++i) {
                uintptr_t current = list + (size_t)i * 0x14 + 0x0c;
                memcpy(saved_entry, (const void *)current, sizeof(saved_entry));

                for (j = i + 1; j < entry_count; ++j) {
                    uintptr_t candidate = list + (size_t)j * 0x14 + 0x0c;
                    bool candidate_is_special;
                    bool saved_is_special;

                    memcpy(candidate_entry, (const void *)candidate,
                           sizeof(candidate_entry));
                    candidate_is_special =
                        candidate_entry[0] >= 0xc0U && candidate_entry[0] <= 0xffU;
                    saved_is_special =
                        saved_entry[0] >= 0xc0U && saved_entry[0] <= 0xffU;

                    if (!candidate_is_special) {
                        if (!saved_is_special && candidate_entry[0] < saved_entry[0]) {
                            memcpy(swap_entry, saved_entry, sizeof(swap_entry));
                            memcpy((void *)current, candidate_entry,
                                   sizeof(candidate_entry));
                            memcpy((void *)candidate, swap_entry,
                                   sizeof(swap_entry));
                            memcpy(saved_entry, candidate_entry,
                                   sizeof(candidate_entry));
                        }
                    }
                    else if (!saved_is_special || candidate_entry[0] < saved_entry[0]) {
                        memcpy(swap_entry, saved_entry, sizeof(swap_entry));
                        memcpy((void *)current, candidate_entry,
                               sizeof(candidate_entry));
                        memcpy((void *)candidate, swap_entry, sizeof(swap_entry));
                        memcpy(saved_entry, candidate_entry, sizeof(candidate_entry));
                    }
                }
            }

            FUN_00175200(previous_mode);
            return;
        }

        {
            u16 item = (u16)item_index;
            uintptr_t item_data;

            if (FUN_00174960(item) != (uintptr_t)0) {
                s32 slot;

                item_data = (uintptr_t)FUN_00174A90(item);
                FUN_00175200(item);
                for (slot = 0; slot < 8; ++slot) {
                    uintptr_t slot_address = item_data + (size_t)slot * 2 + 0x0c;
                    u16 item_id = camp_list_load_u16(slot_address, 0);
                    bool found = false;

                    if (item_id != 0) {
                        for (j = 0; j < entry_count; ++j) {
                            uintptr_t entry = list + (size_t)j * 0x14;
                            if (camp_list_load_u32(entry, 0x0c) == (u32)item_id) {
                                uintptr_t old_data;
                                u8 new_quality;
                                u8 old_quality;

                                old_data = (uintptr_t)FUN_00174A90(camp_list_load_u16(entry, 0x14));
                                new_quality = FUN_00173660(item_data, 1);
                                old_quality = FUN_00173660(old_data, 1);
                                if (old_quality < new_quality) {
                                    s16 kind;
                                    camp_list_store_u32(entry, 0x0c, (u32)item_id);
                                    camp_list_store_u32(entry, 0x14, (u32)item_index);
                                    camp_list_store_u32(entry, 0x10,
                                                   (u32)camp_list_load_u16(item_data, 2));

                                    kind = FUN_0017B480(item_id);
                                    if (kind == 2) {
                                        camp_list_store_u32(entry, 0x18, 0);
                                        camp_list_store_u32(entry, 0x1c, 0);
                                    }
                                    else {
                                        kind = FUN_0017B500(1, item_id);
                                        if (kind == 2) {
                                            camp_list_store_u32(entry, 0x18,
                                                   FUN_0017B5B0(1, item_id));
                                            camp_list_store_u32(entry, 0x1c, 0);
                                        }
                                        else if (kind == 1) {
                                            camp_list_store_u32(entry, 0x18, 0);
                                            camp_list_store_u32(entry, 0x1c,
                                                     FUN_0017B5B0(1, item_id));
                                        }
                                    }
                                }
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            uintptr_t entry = list + (size_t)entry_count * 0x14;
                            s16 kind;

                            camp_list_store_u32(entry, 0x0c, (u32)item_id);
                            camp_list_store_u32(entry, 0x14, (u32)item_index);
                            camp_list_store_u32(entry, 0x10,
                                           (u32)camp_list_load_u16(item_data, 2));
                            kind = FUN_0017B480(item_id);
                            if (kind == 2) {
                                camp_list_store_u32(entry, 0x18, 0);
                                camp_list_store_u32(entry, 0x1c, 0);
                            }
                            else {
                                kind = FUN_0017B500(1, item_id);
                                if (kind == 2) {
                                    camp_list_store_u32(entry, 0x18,
                                                   FUN_0017B5B0(1, item_id));
                                    camp_list_store_u32(entry, 0x1c, 0);
                                }
                                else if (kind == 1) {
                                    camp_list_store_u32(entry, 0x18, 0);
                                    camp_list_store_u32(entry, 0x1c,
                                                     FUN_0017B5B0(1, item_id));
                                }
                            }
                            ++entry_count;
                        }
                    }
                }
            }
        }
        ++item_index;
    }
}

// FUN_0015CE50 NONMATCHING
void FUN_0015CE50(u64 param_1, f32 param_2, void *param_3, s32 param_4)
{
    bool has_three_digits;
    u32 color;
    s32 i;
    s32 record_index;
    uintptr_t list;
    u64 text_handle;
    float x;
    float y;
    float row_x;
    float value_x;
    float value_y;
    float value_tens_x;
    float value_units_x;
    float value_suffix_x;
    u8 text_buffer[256];

    list = camp_list_base_address((u32)(uintptr_t)param_3);
    x = camp_list_packed_low_f32(param_1);
    y = camp_list_packed_high_f32(param_1);
    if (camp_list_load_s32(list, 0x7dc) != 0) {
        FUN_001159F0(x + 2.0f,
                     y + 6.0f + (float)(camp_list_load_s32(list, 0x7e0) * 0x1a),
                     param_1);
        FUN_001159F0(x + 317.0f,
                     y + 6.0f + (float)(camp_list_load_s32(list, 0x7e0) * 0x1a),
                     param_1);
    }

    row_x = x + 15.0f;
    color = (0xffU - (u32)param_4) | 0xffffff00U;
    value_x = y + 19.0f;
    value_y = y + 16.0f;
    value_tens_x = x + 256.0f;
    value_units_x = y + 17.0f;
    value_suffix_x = x + 288.0f;

    for (i = 0; i < 5; ++i) {
        record_index = i + camp_list_load_s32(list, 0x7e4);
        if (record_index >= camp_list_load_s32(list, 0x7dc)) {
            break;
        }

        {
            s32 row_offset = i * 0x1a;
            uintptr_t entry = list + (size_t)record_index * 0x14;
            s32 value;

            FUN_0017D2E0(camp_list_load_u16(entry, 0x0c));
            if (i == camp_list_load_s32(list, 0x7e0)) {
                FUN_001159F0(row_x, y + 2.0f + (float)row_offset, param_1);
            }
            else {
                FUN_00115BC0(row_x, y + 2.0f + (float)row_offset, param_1);
            }

            text_handle = FUN_0030BB40(camp_list_load_u16(entry, 0x0c));
            FUN_00523AC8(text_buffer, 0x7cb66c, text_handle);
            FUN_003B32D0(param_1, (int)((float)(int)x + 55.0f),
                         (int)((float)(int)y + 1.0f + (float)row_offset + 14.0f),
                         color, (i == camp_list_load_s32(list, 0x7e0)) ? 6 : 10, 1,
                         text_buffer, 0x10, 0x78);

            value = camp_list_load_s32(entry, 0x18);
            if (value == 0) {
                value = camp_list_load_s32(entry, 0x1c);
            }
            if (value == 0) {
                FUN_001159F0(x + 249.0f, value_x + (float)row_offset, param_1);
            }
            else {
                has_three_digits = value > 99;
                if (has_three_digits) {
                    FUN_001120A0((i == camp_list_load_s32(list, 0x7e0)) ? 1 : 2);
                    FUN_001159F0(x + 240.0f, value_y + (float)row_offset, param_1);
                    value %= 100;
                }
                if ((value > 9) || has_three_digits) {
                    FUN_001120A0((i == camp_list_load_s32(list, 0x7e0)) ? 1 : 2);
                    FUN_001159F0(value_tens_x, value_y + (float)row_offset, param_1);
                }
                FUN_001120A0((i == camp_list_load_s32(list, 0x7e0)) ? 1 : 2);
                FUN_001159F0(x + 272.0f, value_y + (float)row_offset, param_1);

                if (camp_list_load_s32(entry, 0x18) == 0) {
                    if (camp_list_load_s32(entry, 0x1c) != 0) {
                        FUN_001159F0(value_suffix_x, value_units_x +
                                     (float)row_offset, param_1);
                    }
                }
                else {
                    FUN_001159F0(value_suffix_x, value_units_x +
                                 (float)row_offset, param_1);
                }
            }
        }
    }

    record_index = camp_list_load_s32(list, 0x7e4) + camp_list_load_s32(list, 0x7e0);
    if (camp_list_load_u32(list, (size_t)record_index * 0x14 + 0x0c) != 0) {
        FUN_003c7e20(param_1, (int)(x + 54.0f),
                     (int)(((y + 210.0f) - 30.0f) - 20.0f), UINT32_C(0xffffffff), 1, 10, 3);
    }

    if (camp_list_load_s32(list, 0x7dc) != 0) {
        s32 scrollbar_offset;
        float scrollbar_x = (x + 588.0f) - 247.0f;
        FUN_001159F0(scrollbar_x, (y + 30.0f) - 24.0f, param_1);
        scrollbar_offset = camp_list_load_s32(list, 0x7dc) - 5;
        if (scrollbar_offset < 1) {
            scrollbar_offset = 0;
        }
        else {
            scrollbar_offset =
                (camp_list_load_s32(list, 0x7e4) * 0x59) / scrollbar_offset;
        }
        FUN_001159F0(scrollbar_x,
                     (y + 34.0f + (float)scrollbar_offset) - 24.0f,
                     param_1);
    }
}

// FUN_0015D8E0 NONMATCHING
void FUN_0015D8E0(u64 param_1, f32 param_2, u8 param_3)
{
    union
    {
        u64 packed;
        f32 value[2];
    } position;
    CampD8Object *object;
    f32 x;
    f32 y;

    position.packed = param_1;
    x = 218.0f + position.value[1];
    y = 382.0f + position.value[0];
    object = campD8MakeSprite(0, DAT_00833a50, 0x0c);
    object->drawContext = param_2;
    object->x = x + (f32)DAT_007cdf8c;
    object->y = y;
    object->alpha = param_3;
    campD8SetSprite(object, 1);
    campD8SubmitSprite(object);

    if (DAT_007cdf8c < -200) {
        object = campD8MakeSprite(0, DAT_00833a50, 0x0c);
        object->drawContext = param_2;
        object->x = x + (f32)DAT_007cdf8c + 640.0f;
        object->y = y;
        object->alpha = param_3;
        campD8SetSprite(object, 1);
        campD8SubmitSprite(object);
    }

    DAT_007cdf8c = DAT_007cdf8c - 1;
    if ((f32)DAT_007cdf8c < -640.0f) {
        DAT_007cdf8c = (s32)((f32)DAT_007cdf8c + 640.0f);
    }
}
// FUN_0015DA70 NONMATCHING
void FUN_0015DA70(void *param_1)
{
    uintptr_t base;
    s32 i;
    s32 count;

    base = (uintptr_t)(u32)camp_list_load_u32(
        camp_list_base_address((u32)(uintptr_t)param_1), 0x38);
    count = camp_list_load_s32(
        camp_list_base_address((u32)(uintptr_t)param_1), 0x4c);

    FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + 0x44), 0, 2, 1,
                 0x41b00000429e0000ULL, 0x41b0000041e80000ULL, 0, 0);
    FUN_0018bc10(100.0f, (void *)(uintptr_t)base, 0, 2, 1, 0, 0, 0, 0);
    camp_list_store_u32(base, 0x8c, 0);
    FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + 0xcc), 0, 2, 1,
                 0x43cd800043f88000ULL, 0x43cd800043df8000ULL, 0, 0);
    FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + 0x110), 0, 2, 1,
                 0x41c0000043450000ULL, 0x41c0000043770000ULL, 0, 0);

    for (i = 0; i < 4; ++i) {
        if (i < count) {
            float row = (float)(i * 0x55) + 42.0f;
            s32 item_offset = i * 10;

            FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + (size_t)(i + 1) * 0x2a8),
                         0, 2, 1,
                         camp_list_pack_f32(row + 8.0f,
                                       camp_list_bits_to_float(0x41700000)),
                         camp_list_pack_f32(row + 8.0f,
                                       camp_list_bits_to_float(0x42820000)),
                         0, 0);
            FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + (size_t)(item_offset + 0x0b) * 0x44),
            0, 2, 1,
            camp_list_pack_f32(row + 31.0f,
                          camp_list_bits_to_float(0x41700000)),
            camp_list_pack_f32(row + 31.0f,
                          camp_list_bits_to_float(0x42820000)),
            0, 0);
            FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + (size_t)(item_offset + 0x0c) * 0x44),
            0, 2, 1,
            camp_list_pack_f32(row + 45.0f,
                          camp_list_bits_to_float(0x41700000)),
            camp_list_pack_f32(row + 45.0f,
                          camp_list_bits_to_float(0x42820000)),
            0, 0);
            FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + (size_t)(item_offset + 0x0d) * 0x44),
            0, 2, 1,
            camp_list_pack_f32(row + 64.0f,
                          camp_list_bits_to_float(0x41700000)),
            camp_list_pack_f32(row + 64.0f,
                          camp_list_bits_to_float(0x42820000)),
            0, 0);
            FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + (size_t)(item_offset + 0x0e) * 0x44),
            0, 2, 1,
            camp_list_pack_f32(row + 2.0f,
                          camp_list_bits_to_float(0xc2100000)),
            camp_list_pack_f32(row + 2.0f,
                          camp_list_bits_to_float(0x41600000)),
            0, 0);
            camp_list_store_u32(base + (size_t)i * 0x2a8, 0x400, 0);
            camp_list_store_u32(base + (size_t)i * 0x2a8, 0x444, 0);
        }
        else {
            uintptr_t item = base + (size_t)i * 0x2a8;
            camp_list_store_u32(item, 0x2ac, 0);
            camp_list_store_u32(item, 0x2f0, 0);
            camp_list_store_u32(item, 0x334, 0);
            camp_list_store_u32(item, 0x378, 0);
            camp_list_store_u32(item, 0x3bc, 0);
            camp_list_store_u32(item, 0x400, 0);
            camp_list_store_u32(item, 0x444, 0);
        }
    }

    FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + 0xd48), 0, 2, 1,
                 0x43cf8000c2040000ULL, 0x43cf800041880000ULL, 0, 0);
    camp_list_store_u32(base, 0xd90, 0);
    FUN_0018bc10(100.0f, (void *)(uintptr_t)(base + 0xdd0), 0, 2, 1,
                 0x43cf800043db0000ULL, 0x43cf800043f40000ULL, 0, 0);
}

// FUN_0015E150 NONMATCHING
void FUN_0015E150(CampDrawWork *work)
{
    void *draw;
    f32 x;
    u64 pair;
    s32 i;
    s32 base;

    draw = camp_draw_ptr32(work->records);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x44), 0, 2, 2,
                 UINT64_C(0x41b0000041e80000), UINT64_C(0x41b0000041e80000), 0, 0);
    FUN_0018bc10(100.0f, draw, 0, 2, 2, 0, 0, 0, 0);
    camp_draw_store_u32(draw, 0x8c, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xcc), 0, 2, 2,
                 UINT64_C(0x43cd800043df8000), UINT64_C(0x43cd800043df8000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x110), 0, 2, 2,
                 UINT64_C(0x41c0000043770000), UINT64_C(0x41c0000043770000), 0, 0);

    for (i = 0; i < 4; ++i) {
        if (i < work->partyCount) {
            x = (f32)(i * 0x55) + 42.0f;
            pair = camp_draw_concat44_f32(x + 8.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i + 1) * 0x2a8),
                         0, 2, 2, pair, pair, 0, 0);
            base = i * 10;
            pair = camp_draw_concat44_f32(x + 31.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xb) * 0x44),
                         0, 2, 2, pair, pair, 0, 0);
            pair = camp_draw_concat44_f32(x + 45.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xc) * 0x44),
                         0, 2, 2, pair, pair, 0, 0);
            pair = camp_draw_concat44_f32(x + 64.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xd) * 0x44),
                         0, 2, 2, pair, pair, 0, 0);
            pair = camp_draw_concat44_f32(x + 2.0f, 14.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xe) * 0x44),
                         0, 2, 2, pair, pair, 0, 0);
            camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x400, 0);
            camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x444, 0);
        } else {
            base = i * 0x2a8;
            camp_draw_store_u32(draw, (size_t)base + 0x2ac, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x2f0, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x334, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x378, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x3bc, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x400, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x444, 0);
        }
    }

    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xd48), 0, 2, 2,
                 UINT64_C(0x43cf800041880000), UINT64_C(0x43cf800041880000), 0, 0);
    camp_draw_store_u32(draw, 0xd90, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xdd0), 0, 2, 2,
                 UINT64_C(0x43cf800043f40000), UINT64_C(0x43cf800044068000), 0, 0);
}

// FUN_0015E6E0 NONMATCHING
void FUN_0015E6E0(CampDrawWork *work)
{
    void *draw;
    f32 tailHeight;
    u64 first;
    u64 second;
    s32 i;
    s32 base;

    draw = camp_draw_ptr32(work->records);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x44), 0, 2, 2,
                 UINT64_C(0x41b0000041e80000), UINT64_C(0x41b00000429e0000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x88), 0, 2, 1,
                 UINT64_C(0x41b0000041d80000), UINT64_C(0x41b00000429a0000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xcc), 0, 2, 0,
                 UINT64_C(0x43cd800043df8000), UINT64_C(0x43c9000043fc0000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x110), 0, 2, 0,
                 UINT64_C(0x41c0000043770000), UINT64_C(0x41c00000438c0000), 0, 0);

    for (i = 0; i < 4; ++i) {
        if (i < work->partyCount) {
            if (i == work->cursor || work->cursor == -2) {
                tailHeight = 48.0f;
                first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 14.0f);
                second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 62.0f);
                FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i * 10 + 0x10) * 0x44),
                0, 2, 1, first, second, 0, 0);
            } else {
                tailHeight = 27.0f;
                camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x444, 0);
            }
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 8.0f, 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 8.0f, tailHeight + 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i + 1) * 0x2a8),
                         0, 2, 0, first, second, 0, 0);
            base = i * 10;
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 31.0f, 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 31.0f, tailHeight + 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xb) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 45.0f, 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 45.0f, tailHeight + 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xc) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 64.0f, 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 64.0f, tailHeight + 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xd) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 14.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, tailHeight + 14.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xe) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x400, 0);
        } else {
            base = i * 0x2a8;
            camp_draw_store_u32(draw, (size_t)base + 0x2ac, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x2f0, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x334, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x378, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x3bc, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x400, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x444, 0);
        }
    }

    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xd48), 0, 2, 2,
                 UINT64_C(0x43cf800041880000), UINT64_C(0x43cf800041880000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xd8c), 0, 2, 1,
                 UINT64_C(0x43cf800041880000), UINT64_C(0x43cf800041880000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xdd0), 0, 2, 0,
                 UINT64_C(0x43cf800043f40000), UINT64_C(0x43cf800043f40000), 0, 0);
}

// FUN_0015EE40 NONMATCHING
void FUN_0015EE40(CampDrawWork *work, s32 changedIndex)
{
    void *draw;
    f32 x;
    f32 tailHeight;
    u64 first;
    u64 second;
    s32 i;
    s32 base;

    draw = camp_draw_ptr32(work->records);
    for (i = 0; i < 4; ++i) {
        if (i < work->partyCount) {
        x = (f32)(i * 0x55) + 42.0f;
        if (i == work->cursor) {
            tailHeight = 48.0f;
            first = camp_draw_concat44_f32(x + 2.0f, 41.0f);
            second = camp_draw_concat44_f32(x + 2.0f, 62.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i * 10 + 0x10) * 0x44),
                         0, 2, 1, first, second, 0, 0);
        } else {
            if (i != changedIndex) {
                continue;
            }
            tailHeight = 27.0f;
            first = camp_draw_load_u64(draw, (size_t)i * 0x2a8 + 0x478);
            second = camp_draw_concat44_f32(x + 2.0f, 41.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i * 10 + 0x10) * 0x44),
                         0, 2, 2, first, second, 0, 0);
        }
        base = i * 0x2a8;
        first = camp_draw_load_u64(draw, (size_t)base + 0x2e0);
        second = camp_draw_concat44_f32(x + 8.0f, tailHeight + 65.0f);
        FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i + 1) * 0x2a8),
                     0, 2, 0, first, second, 0, 0);
        base = i * 10;
        first = camp_draw_load_u64(draw, (size_t)(i * 0x2a8) + 0x324);
        second = camp_draw_concat44_f32(x + 31.0f, tailHeight + 65.0f);
        FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xb) * 0x44),
                     0, 2, 0, first, second, 0, 0);
        first = camp_draw_load_u64(draw, (size_t)(i * 0x2a8) + 0x368);
        second = camp_draw_concat44_f32(x + 45.0f, tailHeight + 65.0f);
        FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xc) * 0x44),
                     0, 2, 0, first, second, 0, 0);
        first = camp_draw_load_u64(draw, (size_t)(i * 0x2a8) + 0x3ac);
        second = camp_draw_concat44_f32(x + 64.0f, tailHeight + 65.0f);
        FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xd) * 0x44),
                     0, 2, 0, first, second, 0, 0);
        first = camp_draw_load_u64(draw, (size_t)(i * 0x2a8) + 0x3f0);
        second = camp_draw_concat44_f32(x + 2.0f, tailHeight + 14.0f);
        FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xe) * 0x44),
                     0, 2, 0, first, second, 0, 0);
        }
    }
}

// FUN_0015F320 NONMATCHING
void FUN_0015F320(CampDrawWork *work)
{
    void *draw;
    f32 tailHeight;
    u64 first;
    u64 second;
    s32 i;
    s32 base;

    draw = camp_draw_ptr32(work->records);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x44), 0, 2, 1,
                 UINT64_C(0x41b00000429e0000), UINT64_C(0x41b0000041e80000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x88), 0, 2, 2,
                 UINT64_C(0x41b00000429a0000), UINT64_C(0x41b0000041d80000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xcc), 0, 2, 0,
                 UINT64_C(0x43c9000043fc0000), UINT64_C(0x43cd800043df8000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0x110), 0, 2, 0,
                 UINT64_C(0x41c00000438c0000), UINT64_C(0x41c0000043770000), 0, 0);

    for (i = 0; i < 4; ++i) {
        if (i < work->partyCount) {
            if (i == work->cursor || work->cursor == -2) {
                tailHeight = 48.0f;
                first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 62.0f);
                second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 14.0f);
                FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i * 10 + 0x10) * 0x44),
                0, 2, 2, first, second, 0, 0);
            } else {
                tailHeight = 27.0f;
                camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x444, 0);
            }
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 8.0f, tailHeight + 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 8.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(i + 1) * 0x2a8),
                         0, 2, 0, first, second, 0, 0);
            base = i * 10;
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 31.0f, tailHeight + 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 31.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xb) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 45.0f, tailHeight + 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 45.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xc) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 64.0f, tailHeight + 65.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 64.0f, 65.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xd) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            first = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, tailHeight + 14.0f);
            second = camp_draw_concat44_f32(((f32)(i * 0x55) + 42.0f) + 2.0f, 14.0f);
            FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, (size_t)(base + 0xe) * 0x44),
                         0, 2, 0, first, second, 0, 0);
            camp_draw_store_u32(draw, (size_t)i * 0x2a8 + 0x400, 0);
        } else {
            base = i * 0x2a8;
            camp_draw_store_u32(draw, (size_t)base + 0x2ac, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x2f0, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x334, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x378, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x3bc, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x400, 0);
            camp_draw_store_u32(draw, (size_t)base + 0x444, 0);
        }
    }

    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xd48), 0, 2, 1,
                 UINT64_C(0x43cf800041880000), UINT64_C(0x43cf800041880000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xd8c), 0, 2, 2,
                 UINT64_C(0x43cf800041880000), UINT64_C(0x43cf800041880000), 0, 0);
    FUN_0018bc10(100.0f, camp_draw_ptr_add(draw, 0xdd0), 0, 2, 0,
                 UINT64_C(0x43cf800043f40000), UINT64_C(0x43cf800043f40000), 0, 0);
}

// FUN_0015FA90 NONMATCHING
void FUN_0015FA90(CampDrawRecord *record, s32 recordIndex, CampDrawWork *work)
{
    u8 textBuffer[256];
    u8 digitCount;
    u16 itemId;
    u16 itemWord;
    u32 value;
    u32 maximum;
    u32 alpha;
    u64 spriteHandle;
    void *sprite;
    u8 hasHundreds;
    s16 category;
    s32 group;
    s32 barWidth;
    long iconKind;
    u8 *groupBase;
    f32 ownerValue;
    ownerValue = camp_draw_load_f32(record, 0x24);
    if (recordIndex == 0x34) {
        FUN_001159F0(record->x, record->y, record->owner);
        FUN_001159F0(record->x + 73.0f, record->y, record->owner);
    } else if (recordIndex == 0x33) {
        FUN_001159F0(record->x, record->y, record->owner);
        FUN_001159F0(record->x + 16.0f, record->y, record->owner);
    } else if (recordIndex == 0x32) {
        FUN_001159F0(record->x, record->y, record->owner);
        FUN_001159F0(record->x + 16.0f, record->y, record->owner);
    } else if (recordIndex == 0x2e || recordIndex == 0x24 ||
               recordIndex == 0x1a || recordIndex == 0x10) {
        FUN_001159F0(record->x, record->y, record->owner);
    } else if (recordIndex == 0x2d || recordIndex == 0x23 ||
               recordIndex == 0x19 || recordIndex == 0x0f) {
        FUN_001159F0(record->x, record->y, record->owner);
    } else if (recordIndex == 0x2c || recordIndex == 0x22 ||
               recordIndex == 0x18 || recordIndex == 0x0e) {
        FUN_001159F0(record->x, record->y, record->owner);
    } else if (recordIndex == 0x2b || recordIndex == 0x21 ||
               recordIndex == 0x17 || recordIndex == 0x0d) {
        group = ((s32)recordIndex - 0x0c) / 10;
        groupBase = (u8 *)work + group * 4;
        itemId = camp_draw_load_u16(groupBase, 0x3c);
        digitCount = FUN_0016C470(itemId);
        if (digitCount > 9) {
            FUN_001120A0(2);
            FUN_00115AD0(record->x, record->y, record->owner);
        }
        FUN_001120A0(2);
        FUN_00115AD0(record->x + 16.0f, record->y, record->owner);
        if ((FUN_0016C970(itemId) & UINT64_C(0x80000)) != 0) {
            iconKind = 0x0e;
        } else if ((FUN_0016C970(itemId) & UINT64_C(0x80)) != 0) {
            iconKind = 0x0f;
        } else {
            category = FUN_0016C920(itemId);
            if (category == 5) {
                iconKind = 1;
            } else if (category == 4) {
                iconKind = 0;
            } else if (category == 3) {
                iconKind = 2;
            } else {
                iconKind = -1;
            }
        }
        if (iconKind != -1) {
            FUN_001159F0(record->x + 44.0f, record->y - 6.0f, record->owner);
        }
    } else if (recordIndex == 0x2a || recordIndex == 0x20 ||
               recordIndex == 0x16 || recordIndex == 0x0c) {
        group = ((s32)recordIndex - 0x0c) / 10;
        groupBase = (u8 *)work + group * 4;
        itemId = camp_draw_load_u16(groupBase, 0x3c);
        value = FUN_0016C570(itemId) & 0xffff;
        hasHundreds = value > 99;
        if (hasHundreds) {
            FUN_001120A0(2);
            FUN_00115AD0(record->x, record->y, record->owner);
            value %= 100;
        }
        if (value > 9 || hasHundreds) {
            FUN_001120A0(2);
            FUN_00115AD0(record->x + 16.0f, record->y, record->owner);
        }
        FUN_001120A0(2);
        FUN_00115AD0(record->x + 32.0f, record->y, record->owner);
        itemWord = (u16)camp_draw_load_u32(groupBase, 0x3c);
        value = FUN_0016C570(itemWord) & 0xffff;
        maximum = FUN_0016C670(itemWord) & 0xffff;
        barWidth = 0x4c - (s32)((value * 0x4c) / maximum);
        FUN_001159F0(record->x + 50.0f, record->y + 2.0f, record->owner);
        FUN_001159F0(record->x + 55.0f, record->y + 1.0f, record->owner);
        if (barWidth != 0) {
            FUN_00113a30(ownerValue - 1.0f,
                         record->x + 56.0f + (f32)(0x4c - barWidth),
                         record->y + 1.0f, UINT64_C(0xffffffffffffff00), barWidth, 10);
        }
        FUN_001159F0(record->x + 55.0f, record->y + 1.0f, record->owner);
    } else if (recordIndex == 0x29 || recordIndex == 0x1f ||
               recordIndex == 0x15 || recordIndex == 0x0b) {
        group = ((s32)recordIndex - 0x0b) / 10;
        groupBase = (u8 *)work + group * 4;
        itemId = camp_draw_load_u16(groupBase, 0x3c);
        value = FUN_0016C4F0(itemId) & 0xffff;
        hasHundreds = value > 99;
        if (hasHundreds) {
            FUN_001120A0(2);
            FUN_00115AD0(record->x, record->y, record->owner);
            value %= 100;
        }
        if (value > 9 || hasHundreds) {
            FUN_001120A0(2);
            FUN_00115AD0(record->x + 16.0f, record->y, record->owner);
        }
        FUN_001120A0(2);
        FUN_00115AD0(record->x + 32.0f, record->y, record->owner);
        itemWord = (u16)camp_draw_load_u32(groupBase, 0x3c);
        value = FUN_0016C4F0(itemWord) & 0xffff;
        maximum = FUN_0016C5F0(itemWord) & 0xffff;
        barWidth = 0x4c - (s32)((value * 0x4c) / maximum);
        FUN_001159F0(record->x + 50.0f, record->y + 2.0f, record->owner);
        FUN_001159F0(record->x + 55.0f, record->y + 1.0f, record->owner);
        if (barWidth != 0) {
            FUN_00113a30(ownerValue - 1.0f,
                         record->x + 56.0f + (f32)(0x4c - barWidth),
                         record->y + 1.0f, UINT64_C(0xffffffffffffff00), barWidth, 10);
        }
        FUN_001159F0(record->x + 55.0f, record->y + 1.0f, record->owner);
    } else if (recordIndex == 0x28 || recordIndex == 0x1e ||
               recordIndex == 0x14 || recordIndex == 0x0a) {
        group = ((s32)recordIndex - 10) / 10;
        groupBase = (u8 *)work + group * 4;
        alpha = record->alpha;
        spriteHandle = FUN_00177790(camp_draw_load_u16(groupBase, 0x3c));
        FUN_00523AC8(textBuffer, 0x7cb66c, spriteHandle);
        FUN_003B32D0(record->owner, (s32)record->x,
                     (s32)record->y + 3,
                     (u32)(0xffU - alpha) | 0xffffff00U,
                     10, 1, textBuffer, 0x10, 0x78);
    } else if (recordIndex == 0) {
        FUN_0015D8E0(camp_draw_record_xy(record), camp_draw_load_f32(record, 0x24), record->alpha);
    } else if (recordIndex == 4) {
        groupBase = (u8 *)work;
        FUN_0015CE50(camp_draw_record_xy(record), camp_draw_load_f32(record, 0x24),
                     (void *)(uintptr_t)camp_draw_load_u32(groupBase, 0x28), record->alpha);
    } else if (recordIndex == 3) {
        spriteHandle = FUN_001158B0(0, DAT_00833a50, 0x0e);
        sprite = (void *)(uintptr_t)spriteHandle;
        camp_draw_store_u32(sprite, 0x2c, record->owner);
        camp_draw_store_f32(sprite, 0x10, record->x);
        camp_draw_store_f32(sprite, 0x14, record->y);
        camp_draw_store_u8(sprite, 0x18, (u8)record->alpha);
        camp_draw_store_u32(sprite, 0x20, 0xc2340000);
        FUN_001127D0(spriteHandle, 1);
        FUN_00115980(spriteHandle);
    } else if (recordIndex == 2) {
        FUN_001159F0(record->x, record->y, record->owner);
    } else if (recordIndex == 1) {
        FUN_001159F0(record->x, record->y, record->owner);
    }
}

// FUN_00160800 NONMATCHING
void *FUN_00160800(KwlnTask *task)
{
    CampDrawWork *work;
    CampDrawRecord *record;
    KwlnTask *otherTask;
    void *entryPool;
    void *entry;
    CampD8Object *sprite;
    void *ready;
    u32 temp;
    u16 inputLatch;
    u16 itemId;
    s16 itemResult;
    s32 i;
    s32 j;
    s32 oldCursor;
    s32 allDone;
    s32 hasInput;
    s32 itemCount;
    s32 itemIndex;
    s32 itemBase;
    u32 value;
    u32 value2;
    u32 fadedAlpha;
    f32 verticalOffset;
    f32 displacement;

    work = (CampDrawWork *)camp_draw_ptr32((u32)(uintptr_t)task->workData);
    switch (work->state) {
    case 0:
        uGpffffb29c = 0;
        if (iGpffffb270 == NULL) {
            ready = NULL;
        } else {
            ready = iGpffffb270->workData;
            if (*(u32 *)ready != 3) {
                ready = NULL;
            } else {
                ready = *(void **)((u8 *)ready + 0x0c);
            }
        }
        if (ready != NULL) {
            FUN_00114450(102.0f, 0.0f, -87.0f, -1,
                         0x4fa4ff19, 0x280, 0x280);
        }
        FUN_0011BBA0(0.0f, 0.0f, 102.0f, 0, 0);
        sprite = campD8MakeSprite(0, *(void **)DAT_00833b78_abs, 0);
        camp_draw_store_u32(sprite, 0x2c, 0x42ca0000);
        camp_draw_store_u32(sprite, 0x10, 0x43d60000);
        camp_draw_store_u32(sprite, 0x14, 0x41d80000);
        camp_draw_store_u8(sprite, 0x18, 0);
        camp_draw_store_u16(sprite, 0x28, 0);
        camp_draw_store_u16(sprite, 0x2a, 0);
        campD8SetSprite(sprite, 1);
        campD8SubmitSprite(sprite);
        work->records = (u32)(uintptr_t)func_0018b6d0(0x3c);
        work->state = 1;
        work->partyIds[0] = 1;
        work->partyCount = 1;
        for (i = 0; i < 3 && FUN_0016DD60(i) != 0; ++i) {
            work->partyIds[work->partyCount] = FUN_0016DD60(i);
            ++work->partyCount;
        }
        work->frame = 0;
        break;

    case 1:
        i = work->frame;
        if (i == 10) {
            work->state = 2;
        } else {
            if (i < 9) {
                s16 fade = 0;
                if (i >= 3) {
                    displacement = (f32)(((i - 3) * 400) / 5);
                    fade = (s16)(((i - 3) * 0xff) / 5);
                } else {
                    verticalOffset = 0.0f;
                }
                if (iGpffffb270 == NULL) {
                    ready = NULL;
                } else {
                    ready = iGpffffb270->workData;
                    if (*(u32 *)ready != 3) {
                        ready = NULL;
                    } else {
                        ready = *(void **)((u8 *)ready + 0x0c);
                    }
                }
                if (ready != NULL) {
                    fadedAlpha = 0xffU - (s32)fade;
                    value2 = fadedAlpha;
                    if (fadedAlpha > 0x18) {
                        value2 = 0x19;
                    }
                    FUN_00114450(102.0f, displacement, verticalOffset - 87.0f,
                                 fadedAlpha | 0xffffff00U,
                                 value2 | 0x4fa4ff00U, 0x280, 0x280);
                }
                FUN_0011BBA0(0.0f, 0.0f, 102.0f, fade, 0);
                sprite = campD8MakeSprite(0, *(void **)DAT_00833b78_abs, 0);
                camp_draw_store_u32(sprite, 0x2c, 0x42ca0000);
                camp_draw_store_f32(sprite, 0x10, displacement + 428.0f);
                camp_draw_store_f32(sprite, 0x14, verticalOffset + 27.0f);
                camp_draw_store_u8(sprite, 0x18, (u8)fade);
                camp_draw_store_u16(sprite, 0x28, 0);
                camp_draw_store_u16(sprite, 0x2a, 0);
                campD8SetSprite(sprite, 1);
                campD8SubmitSprite(sprite);
                if (i == 0) {
                    otherTask = iGpffffb26c;
                    entry = camp_draw_ptr32((u32)(uintptr_t)otherTask->workData);
                    FUN_0011DA80(0x42c80000, entry);
                    camp_draw_store_u32(entry, 0, 9);
                    camp_draw_store_u32(entry, 4, 0);
                }
                if (i == 4) {
                    FUN_00121DE0(uGpffffb264, 0x0d);
                    FUN_00122710(uGpffffb268, 0x0d);
                }
            }
            work->frame = i + 1;
        }
        break;

    case 2:
        if (FUN_001016b0(camp_draw_ptr32(work->imageArchive)) != 0) {
            work->archive0 = (u32)(uintptr_t)FUN_00112420(FUN_00102100(camp_draw_ptr32(work->imageArchive), 0, &temp));
            work->archive1 = (u32)(uintptr_t)FUN_00112420(FUN_00102100(camp_draw_ptr32(work->imageArchive), 1, &temp));
            work->archive2 = (u32)(uintptr_t)FUN_00112420(FUN_00102100(camp_draw_ptr32(work->imageArchive), 2, &temp));
            entryPool = (*DAT_00960184_abs)(1, 0x7f0, 0x40000);
            for (i = 0; i < 100; ++i) {
                camp_draw_store_u32((u8 *)entryPool + i * 0x14, 0x0c, 0);
                camp_draw_store_u32((u8 *)entryPool + i * 0x14, 0x10, 0);
            }
            work->entryPool = camp_draw_addr32(entryPool);
            FUN_0015C840(entryPool);
            *(void **)DAT_00833a50_abs = camp_draw_ptr32(work->archive0);
            *(void **)DAT_00833a54_abs = camp_draw_ptr32(work->archive1);
            *(void **)DAT_00833a58_abs = camp_draw_ptr32(work->archive2);
            work->state = 3;
        }
        break;

    case 3:
        if (FUN_00111f30(camp_draw_ptr32(work->archive0)) != 0 &&
            FUN_00111f30(camp_draw_ptr32(work->archive1)) != 0 &&
            FUN_00111f30(camp_draw_ptr32(work->archive2)) != 0) {
            work->state = 4;
        }
        break;

    case 4:
        if (FUN_0011e380(uGpffffb260, 0x0d) != 0) {
            FUN_0015DA70(work);
            work->state = 5;
        }
        break;

    case 5:
        allDone = 1;
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0) {
                if (func_0018b700(record) != 0) {
                    FUN_0015FA90(record, i, work);
                }
                if (record->progress != record->target) {
                    allDone = 0;
                }
            }
        }
        if (allDone != 0) {
            work->state = 6;
        }
        break;

    case 6:
        allDone = 1;
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0) {
                if (func_0018b700(record) != 0) {
                    FUN_0015FA90(record, i, work);
                }
                if (record->progress != record->target) {
                    allDone = 0;
                }
            }
        }
        if (allDone != 0 && (DAT_007e094e & 0x20) == 0) {
            if ((DAT_007e094e & 0x40) == 0) {
                entryPool = camp_draw_ptr32(work->entryPool);
                FUN_0011ABD0(camp_draw_load_u32(entryPool, 0x7dc), 5,
                             (u8 *)entryPool + 0x7e4, (u8 *)entryPool + 0x7e0);
            } else {
                entryPool = camp_draw_ptr32(work->entryPool);
                itemIndex = (s32)camp_draw_load_u32(entryPool, 0x7e0);
                itemCount = (s32)camp_draw_load_u32(entryPool, 0x7dc);
                itemBase = (s32)camp_draw_load_u32(entryPool, 0x7e4);
                if (itemIndex < itemCount) {
                    entry = (u8 *)entryPool + (itemIndex + itemBase) * 0x14;
                    value = camp_draw_load_u32(entry, 0x0c);
                    inputLatch = DAT_00836ba8;
                    FUN_00175200(camp_draw_load_u16(entry, 0x14));
                    itemResult = FUN_0017B480((u16)value);
                    if (itemResult == 2 || FUN_0017B660(1, (u16)value) != 0 ||
                        FUN_0017B4E0((u16)value) != 1) {
                        FUN_0010a4e0(0, 0, 0, 8);
                    } else {
                        FUN_0010a4e0(0, 0, 0);
                        work->selectedKind = (s16)FUN_0017BB40((u16)value);
                        if (work->selectedKind != 3) {
                            if (work->selectedKind == 0) {
                                work->cursor = 0;
                            } else {
                                work->cursor = -2;
                            }
                            work->state = 8;
                        }
                    }
                    FUN_00175200(inputLatch);
                }
            }
        } else if (allDone != 0 && (DAT_007e094e & 0x20) != 0) {
            FUN_0010a4e0(0, 0, 0, 2);
            FUN_0015E150(work);
            work->state = 7;
        }
        break;

    case 7:
        allDone = 1;
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0) {
                if (func_0018b700(record) != 0) {
                    FUN_0015FA90(record, i, work);
                }
                if (record->progress != record->target) {
                    allDone = 0;
                }
            }
        }
        if (allDone != 0) {
            return (void*)0xffffffff;
        }
        break;

    case 8:
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0 && func_0018b700(record) != 0) {
                FUN_0015FA90(record, i, work);
            }
        }
        if (FUN_0011e380(uGpffffb260, 0x0e) != 0) {
            FUN_0015E6E0(work);
            work->state = 9;
        }
        break;

    case 9:
        allDone = 1;
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0) {
                if (func_0018b700(record) != 0) {
                    FUN_0015FA90(record, i, work);
                }
                if (record->progress != record->target) {
                    allDone = 0;
                }
            }
        }
        if (allDone == 0) {
            break;
        }
        oldCursor = work->cursor;
        if ((DAT_007e094e & 0x20) == 0) {
            if ((DAT_007e094e & 0x40) == 0) {
                hasInput = ((DAT_007e0952 & 0x1000) != 0) ||
                           ((DAT_007e095a & 0x1000) != 0);
                if (hasInput) {
                    if (work->cursor != -2) {
                        if (work->cursor == 0) {
                            if ((DAT_007e094e & 0x1000) != 0 ||
                                (DAT_007e0958 & 0x1000) != 0) {
                                FUN_0010a4e0(0, 0, 0);
                                work->cursor = work->partyCount - 1;
                            }
                        } else {
                            FUN_0010a4e0(0, 0, 0);
                            --work->cursor;
                        }
                    }
                } else if (((DAT_007e0952 & 0x4000) != 0 ||
                            (DAT_007e095a & 0x4000) != 0) &&
                           work->cursor != -2) {
                    if (work->cursor == work->partyCount - 1) {
                        if ((DAT_007e094e & 0x4000) != 0 ||
                            (DAT_007e0958 & 0x4000) != 0) {
                            FUN_0010a4e0(0, 0, 0);
                            work->cursor = 0;
                        }
                    } else {
                        FUN_0010a4e0(0, 0, 0);
                        ++work->cursor;
                    }
                }
            } else {
                entryPool = camp_draw_ptr32(work->entryPool);
                itemIndex = (s32)camp_draw_load_u32(entryPool, 0x7e0);
                itemBase = (s32)camp_draw_load_u32(entryPool, 0x7e4);
                entry = (u8 *)entryPool + (itemIndex + itemBase) * 0x14;
                itemId = (u16)(camp_draw_load_u32(entry, 0x0c) & 0xffff);
                if (work->selectedKind == 0) {
                    value = (u32)work->partyIds[work->cursor];
                    if (campC520NearHero(value) == 0 ||
                        FUN_0017BC20(1, (s16)value, itemId, 0) != 0) {
                        FUN_0010a4e0(0, 0, 0, 8);
                    } else {
                        FUN_0010a4e0(1, 0, 3, 1);
                        FUN_0015C520(entryPool, work->cursor);
                        work->state = 10;
                    }
                } else {
                    hasInput = 0;
                    for (j = 0; j < work->partyCount; ++j) {
                        value = (u32)work->partyIds[j];
                        if (campC520NearHero(value) != 0 &&
                            FUN_0017BC20(1, (s16)value, itemId, 0) == 0) {
                            hasInput = 1;
                        }
                    }
                    if (hasInput != 0) {
                        FUN_0010a4e0(1, 0, 3, 1);
                        FUN_0015C520(entryPool, -2);
                        work->state = 10;
                    } else {
                        FUN_0010a4e0(0, 0, 0, 8);
                    }
                }
            }
        } else {
            FUN_0010a4e0(0, 0, 0, 2);
            work->state = 10;
        }
        if (oldCursor != work->cursor) {
            FUN_0015EE40(work, oldCursor);
        }
        break;

    case 10:
        for (i = 0; i < 0x3c; ++i) {
            record = &camp_draw_state_records(work)[i];
            if (record->active != 0 && func_0018b700(record) != 0) {
                FUN_0015FA90(record, i, work);
            }
        }
        if (FUN_0011e380(uGpffffb260, 0x0d) != 0) {
            FUN_0015F320(work);
            work->state = 6;
        }
        break;
    }
    return 0;
}
