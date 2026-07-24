#include "Main/g_data.h"
#include "Main/Battle/Data/datPersona.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

typedef unsigned long long u64;
typedef int bool;
#define true 1
#define false 0

extern void* memcpy(void* dst, const void* src, u32 size);
extern void* memset(void* dst, u8 value, u32 size);
extern int memcmp(const void* left, const void* right, u32 size);
extern void qsort(void* base, u32 count, u32 width, int (*compare)(const void*, const void*));
extern int printf(const char* fmt, ...);
extern int sprintf(char* dst, const char* fmt, ...);
extern void FUN_00521250(void* dst, const void* src, u32 size);
extern void FUN_00523ac8(void* dst, const void* format, ...);
extern u8 DAT_00833bb0[];
extern u8 DAT_00833bd0[];
extern u8 DAT_00833bf0[];
extern u8 DAT_00836212[];
extern char gp0xffff9388[1];
extern const char D_007cc078[];
extern const char D_005e3820[];
extern void FUN_0019d3f0(u32 file, u32 line);
extern void FUN_00521408(void* dst, s32 value, u32 size);
extern void func_001828d0(s16 id, void* record);
extern void func_001830c0(void* record);
extern s32 FUN_003082f0(s32 category, u32 id);
extern s32 FUN_003086f0(void* record, u64 id);
extern void FUN_003086c0(void* record, u64 value);
extern void FUN_003083f0(void* record, u64 value);
extern s32 FUN_00306610(u64 value, void* left, void* right, u64 extra);
extern s32 FUN_003068d0(u64 value, void* left, void* right, u64 extra);
extern void FUN_00306bc0(u64 value, void* left, void* right, u64 a, u64 b, u64 c, u64 d);
extern s16 FUN_00403740(s16 id);
extern u64 FUN_00403920(s16 id, u64 value);
extern u64 FUN_003f33d0(s32 category, s32 value);
extern void FUN_003eff00(s32 index, void* out);
extern void* FUN_00300af0(void);
extern void* FUN_00403130(void);
extern void* FUN_00403220(void);
extern void* FUN_001bff20(void);
void FUN_00179360(u32 saveType, u32 id, u32 size, const void* data);
void FUN_0017a430(u32 saveType, u32 id, u32 size, const void* data);
u32 FUN_0017d7b0(void);
int FUN_0017c2f0(const u32* left, const u32* right);
u32 FUN_0017d450(s32 index, const void* date);

extern u32 D_00960178[];
extern u32 D_0096017C[];
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
extern u8 D_00834010[];
extern u8 D_00833994[];
extern s32 D_005e3840[][2];
extern s32 D_005e3844[][2];
extern u32 D_0083a21c[];
extern u8 DAT_0083a718[];
extern u8 DAT_00836200[];
extern u32 DAT_007ce00c;
extern s8* puGpffffb704;
extern u8 D_0083A6FC[];
extern const char D_005e3098[];
extern u8 DAT_00836e1c[];
extern u32 gSpecialStatusMessage;
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce420;
extern u8* DAT_007ce42c;
extern void* DAT_007ce050;
extern void* DAT_007ce054;
extern void* DAT_007ce058;
extern void* DAT_007ce05c;

extern u8* DAT_007ce4a0;

#define PTR8(addr) ((u8*)(addr))
#define PTR16(addr) ((u16*)(addr))
#define PTR32(addr) ((u32*)(addr))
#define PTRP(addr) (*(u8**)(addr))
#define U8(addr) (*PTR8(addr))
#define U16(addr) (*PTR16(addr))
#define U32(addr) (*PTR32(addr))
#define ALLOCATE(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184_abs)(count, size, flags)
#define ALLOCATE_SMALL(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960178)(count, size, flags)
#define RELEASE(memory) (*(void (**)(void*))D_0096017C)(memory)

/* The retail data tables are deliberately kept at their original addresses. */
typedef struct ResourceEntry
{
    u16 id;
    u16 reserved;
    u8 data[0x10];
} ResourceEntry;

typedef struct PairCounter
{
    s16 key;
    s16 keyHigh;
    s16 id;
    s16 remaining;
} PairCounter;

typedef struct DateRecord
{
    u8 month;
    u8 day;
    s16 year;
    s32 serial;
} DateRecord;

static ResourceEntry* resource_entries(void)
{
    return (ResourceEntry*)PTRP(0x00836794);
}

static s16* resource_levels(void)
{
    return (s16*)PTRP(0x00836798);
}

static u8* compendium_record(s32 id)
{
    return PTR8(0x00836e1c) + id * 0x34;
}

static u8* code_list(void)
{
    return PTR8(0x008367a7);
}

static u32* bit_list(void)
{
    return PTR32(0x0083a8c4);
}

static u32* pair_bits(void)
{
    return PTR32(0x0083a8f0);
}

static PairCounter* pair_counters(void)
{
    return (PairCounter*)PTR8(0x0083a734);
}

static DateRecord* date_records(void)
{
    return (DateRecord*)PTR8(0x0083a834);
}

static s32 bit_index(s32 value)
{
    if (value < 0) return 0;
    return value >> 5;
}

static u32 bit_mask(s32 value)
{
    return 1u << (value & 31);
}

#define SAVE_CHUNK(cursor, id_value, chunk_size, source) \
    do { \
        id = (id_value); \
        FUN_00521250((cursor), &id, 4); \
        size = (chunk_size); \
        FUN_00521250((cursor) + 4, &size, 4); \
        FUN_00521250((cursor) + 8, (source), size); \
        (cursor) += size + 8; \
    } while (0)
#define SAVE_AT(base, offset, id_value, chunk_size, source) \
    do { \
        id = (id_value); \
        FUN_00521250((base) + (offset), &id, 4); \
        size = (chunk_size); \
        FUN_00521250((base) + (offset) + 4, &size, 4); \
        FUN_00521250((base) + (offset) + 8, (source), size); \
    } while (0)

// FUN_00177d40
void FUN_00177d40(void)
{
    void* (**allocator)(u32, u32, u32);

    allocator = (void* (**)(u32, u32, u32))D_00960184;
    PTRP(0x00836794) = (u8*)(*allocator)(300, 0x14, 0x40000);
    PTRP(0x00836798) = (u8*)(*allocator)(300, 2, 0x40000);
}

// FUN_00177db0 NONMATCHING
void* FUN_00177db0(u32 saveType, s32* saveSize)
{
    u8* buffer;
    u8* cursor;
    u8 header[0x34];
    u32 id;
    u32 size;
    u8 checksum;
    u32 chunkOffset;
    u32 i;
    u32 today;
    u32 month;
    u32 day;

    U32(0x0083a6ec) = ((u32*)D_00960184_abs)[0];
    U32(0x0083a6f0) = ((u32*)D_00960184_abs)[1];
    U32(0x0083a6f4) = (u32)FUN_001bff20();
    buffer = (u8*)ALLOCATE(1, 0x20000, 0x40000);
    chunkOffset = 0;
    memcpy(buffer, &saveType, 4);

    memset(header, 0, sizeof(header));
    *(u16*)(header + 0) = U16(0x0083679c);
    *(u16*)(header + 2) = U8(0x0083679e);
    *(u32*)(header + 4) = U32(0x0083a598);
    today = U32(0x00836268);
    month = 0;
    day = 0;
    while (day < 99)
    {
        if (today < PTR32(0x005dc050)[day]) break;
        month = (month + 1) & 0xff;
        day = (day + 1) & 0xff;
    }
    if (day >= 99) month = 99;
    header[8] = (u8)month;
    header[9] = (U32(0x0083a47c) & 0x2000000) != 0 ? 2 :
                ((U32(0x0083a47c) & 0x20000) != 0 ? 1 : 0);
    header[10] = (u8)FUN_0017d7b0();
    header[11] = (u8)U32(0x0083a6ec);
    for (i = 0; i < 0x12; i++)
        header[0x0c + i] = DAT_00836200[i];
    for (i = 0; i < 0x12; i++)
        header[0x1e + i] = DAT_00836200[0x12 + i];
    header[0x30] = (u8)((u32*)D_00960184_abs)[0];
    header[0x31] = (u8)((u32*)D_00960184_abs)[1];

    memcpy(buffer + 4, header, sizeof(header));
    SAVE_AT(buffer, 0x38, 1, 0x24, PTR8(0x00836200));
    SAVE_AT(buffer, 0x64, 2, 0x50, PTR8(0x00836224));
    SAVE_AT(buffer, 0xbc, 3, 0x508, PTR8(0x00836274));
    SAVE_AT(buffer, 0x5cc, 4, 0x10, PTR8(0x0083677c));
    SAVE_AT(buffer, 0x5e4, 5, 8, PTR8(0x0083678c));
    SAVE_AT(buffer, 0x5f4, 6, 0x1770, PTRP(0x00836794));
    SAVE_AT(buffer, 0x1d6c, 7, 0x258, PTRP(0x00836798));
    SAVE_AT(buffer, 0x1fcc, 8, 2, PTR8(0x0083679c));
    SAVE_AT(buffer, 0x1fd6, 9, 1, PTR8(0x0083679e));
    SAVE_AT(buffer, 0x1fdf, 10, 4, PTR8(0x008367a0));
    SAVE_AT(buffer, 0x1fe7, 11, 2, PTR8(0x008367a4));
    SAVE_AT(buffer, 0x1fef, 12, 1, PTR8(0x008367a6));
    SAVE_AT(buffer, 0x1ff5, 13, 0x400, PTR8(0x008367a7));
    SAVE_AT(buffer, 0x2406, 14, 2, PTR8(0x00836ba8));
    SAVE_AT(buffer, 0x2410, 15, 0x270, PTR8(0x00836bac));
    SAVE_AT(buffer, 0x2688, 16, 0x3400, PTR8(0x00836e1c));
    SAVE_AT(buffer, 0x5a90, 17, 0x2c0, PTR8(0x0083a21c));
    SAVE_AT(buffer, 0x5d58, 18, 4, PTR8(0x0083a6dc));
    SAVE_AT(buffer, 0x5d64, 19, 8, PTR8(0x0083a6e0));
    SAVE_AT(buffer, 0x5d74, 20, 4, PTR8(0x0083a6e8));
    SAVE_AT(buffer, 0x5d80, 21, 4, PTR8(0x0083a6ec));
    SAVE_AT(buffer, 0x5d8c, 22, 4, PTR8(0x0083a6f0));
    SAVE_AT(buffer, 0x5d98, 23, 4, PTR8(0x0083a6f4));
    SAVE_AT(buffer, 0x5da4, 24, 0x2c, PTR8(0x0083a8c4));
    SAVE_AT(buffer, 0x5dd8, 25, 0x200, PTR8(0x0083a4dc));
    SAVE_AT(buffer, 0x5fe0, 26, 0x1c, PTR8(0x0083a6fc));
    SAVE_AT(buffer, 0x6004, 27, 0x10, PTR8(0x0083a718));
    SAVE_AT(buffer, 0x601c, 28, 8, PTR8(0x0083a728));
    SAVE_AT(buffer, 0x602c, 29, 4, PTR8(0x0083a730));
    SAVE_AT(buffer, 0x6038, 30, 0x100, PTR8(0x0083a734));
    SAVE_AT(buffer, 0x6140, 31, 0x90, PTR8(0x0083a834));
    SAVE_AT(buffer, 0x61d8, 0x21, 0x1a8, PTR8(0x0083a8f0));
    SAVE_AT(buffer, 0x6388, 0x22, 1, PTR8(0x0083679e));
    SAVE_AT(buffer, 0x6391, 0x23, 4, PTR8(0x0083aa98));
    SAVE_AT(buffer, 0x639d, 0x24, 4, PTR8(0x0083a6f8));
    chunkOffset += 0x63a9;
    cursor = buffer + 0x63a9;

    for (i = 0; i < 10; i++)
    {
        u32 base = 0x100 + i * 0x100;
        u32 sourceAddress = 0x00834010 + i * 0x364;
        SAVE_CHUNK(cursor, base, 4, PTR8(sourceAddress));
        SAVE_CHUNK(cursor, base + 1, 0x50, PTR8(sourceAddress + 4));
        SAVE_CHUNK(cursor, base + 2, 8, PTR8(sourceAddress + 0x54));
        SAVE_CHUNK(cursor, base + 3, 0x50, PTR8(sourceAddress + 0x5c));
        SAVE_CHUNK(cursor, base + 4, 0x30, PTR8(sourceAddress + 0xac));
        SAVE_CHUNK(cursor, base + 5, 0x34, PTR8(sourceAddress + 0xdc));
        SAVE_CHUNK(cursor, base + 6, 0x10, PTR8(sourceAddress + 0x110));
        SAVE_CHUNK(cursor, base + 7, 0x10, PTR8(sourceAddress + 0x120));
        SAVE_CHUNK(cursor, base + 8, 0x50, PTR8(sourceAddress + 0x130));
        SAVE_CHUNK(cursor, base + 9, 0x190, PTR8(sourceAddress + 0x180));
        SAVE_CHUNK(cursor, base + 10, 0x50, PTR8(sourceAddress + 0x310));
        SAVE_CHUNK(cursor, base + 11, 4, PTR8(sourceAddress + 0x360));
        chunkOffset += 0x3c4;
    }
    SAVE_CHUNK(cursor, 0x1000, 400, PTR8(0x00833e80));
    SAVE_CHUNK(cursor, 0x1001, 600, PTR8(0x00833c20));
    checksum = 0;
    for (i = 0; i < chunkOffset + 0x3c0; i++)
        checksum = (u8)(checksum + buffer[0x38 + i]);
    SAVE_CHUNK(cursor, 0x2000, 1, &checksum);
    {
        u32 end = 0xffffffff;
        memcpy(cursor, &end, 4);
        cursor += 4;
    }
    if (saveSize != NULL) *saveSize = (s32)(cursor - buffer);
    printf("save image size %d\n", (s32)(cursor - buffer));
    return buffer;
}

// FUN_00179030
void FUN_00179030(u32 saveType, void* stream)
{
    u8* cursor = (u8*)stream;
    u32 id;
    u32 size;

    if (saveType >= 2) cursor += 0x34;
    for (;;)
    {
        memcpy(&id, cursor, 4);
        printf((const char*)D_005e3820, id);
        if (id == 0xffffffff || id == 0x2000) break;
        memcpy(&size, cursor + 4, 4);
        cursor += 8;
        if (DAT_007ce00c != 0)
            FUN_0017a430(saveType, id, size, cursor);
        else
            FUN_00179360(saveType, id, size, cursor);
        cursor += size;
    }
    if (DAT_007ce00c == 0)
    {
        FUN_00521408(DAT_00833bb0, 0, 0x12);
        FUN_00521408(DAT_00833bd0, 0, 0x12);
        FUN_00521408(DAT_00833bf0, 0, 0x24);
        FUN_00521250(DAT_00833bb0, DAT_00836200, 0x12);
        FUN_00521250(DAT_00833bd0, DAT_00836212, 0x12);
        FUN_00523ac8(DAT_00833bf0, gp0xffff9388, DAT_00833bd0, DAT_00833bb0);
    }
}
 
// FUN_001791d0 NONMATCHING
bool FUN_001791d0(u32 saveType, const void* stream, s32 streamSize)
{
    const u8* start = (const u8*)stream;
    const u8* cursor = (const u8*)stream;
    u32 id;
    u32 size;
    u32 consumed;
    u32 limit;
    u32 checksum;
    u32 i;
    u8 stored;

    if (streamSize < 0x1000) return false;
    if (saveType >= 2)
    {
        cursor += 0x34;
        start = cursor;
    }
    if (saveType < 3) return true;
    consumed = 0;
    limit = (u32)(streamSize - 0x34);
    for (;;)
    {
        memcpy(&id, cursor, 4);
        if (id == 0xffffffff) return false;
        if (id == 0x2000)
        {
            checksum = 0;
            for (i = 0; i < consumed; i++)
                checksum = (checksum + start[i]) & 0xff;
            memcpy(&size, cursor + 4, 4);
            memcpy(&stored, cursor + 8, 1);
            return (((u8)checksum ^ stored) == 0);
        }
        memcpy(&size, cursor + 4, 4);
        if (size == 0) return false;
        cursor += 8 + size;
        consumed += 8 + size;
        if (consumed < limit) continue;
        return false;
    }
}


// FUN_00179360 NONMATCHING
void FUN_00179360(u32 saveType, u32 id, u32 size, const void* data)
{
    u8* destination = NULL;
    u32 index;
    (void)saveType;
    if (id == 0x1000 && size == 400) destination = PTR8(0x00833e80);
    else if (id == 0x1001 && size == 600) destination = PTR8(0x00833c20);
    else if (id >= 0x100 && id <= 0xa0b)
    {
        index = (id >> 8) - 1;
        switch (id & 0xff)
        {
            case 0: if (size == 4) destination = PTR8(0x00834010 + index * 0x364); break;
            case 1: if (size == 0x50) destination = PTR8(0x00834014 + index * 0x364); break;
            case 2: if (size == 8) destination = PTR8(0x00834064 + index * 0x364); break;
            case 3: if (size == 0x50) destination = PTR8(0x0083406c + index * 0x364); break;
            case 4: if (size == 0x30) destination = PTR8(0x008340bc + index * 0x364); break;
            case 5: if (size == 0x34) destination = PTR8(0x008340ec + index * 0x364); break;
            case 6: if (size == 0x10) destination = PTR8(0x00834120 + index * 0x364); break;
            case 7: if (size == 0x10) destination = PTR8(0x00834130 + index * 0x364); break;
            case 8: if (size == 0x50) destination = PTR8(0x00834140 + index * 0x364); break;
            case 9: if (size == 0x190) destination = PTR8(0x00834190 + index * 0x364); break;
            case 10: if (size == 0x50) destination = PTR8(0x00834320 + index * 0x364); break;
            case 11: if (size == 4) destination = PTR8(0x00834370 + index * 0x364); break;
        }
    }
    else if (id >= 1 && id <= 0x35)
    {
        static const u32 sizes[] = { 0, 0x24, 0x50, 0x508, 0x10, 8, 6000, 600, 2, 1, 4,
            2, 1, 0x400, 2, 0x270, 0x3400, 0x2c0, 4, 8, 4, 4, 4, 4, 0x2c, 0x200,
            0x1c, 0x10, 8, 4, 0x100, 0x90, 0, 0x1a8, 1, 4 };
        static const u32 addrs[] = { 0, 0x00836200, 0x00836224, 0x00836274, 0x0083677c,
            0x0083678c, 0, 0, 0x0083679c, 0x0083679e, 0x008367a0, 0x008367a4, 0x008367a6,
            0x008367a7, 0x00836ba8, 0x00836bac, 0x00836e1c, 0x0083a21c, 0x0083a6dc,
            0x0083a6e0, 0x0083a6e8, 0x0083a6ec, 0x0083a6f0, 0x0083a6f4, 0x0083a8c4,
            0x0083a4dc, 0x0083a6fc, 0x0083a718, 0x0083a728, 0x0083a730, 0x0083a734,
            0x0083a834 };
        if (id < ARRAY_SIZE(sizes) && size == sizes[id])
        {
            destination = PTR8(addrs[id]);
            if (id == 6) destination = PTRP(0x00836794);
            if (id == 7) destination = PTRP(0x00836798);
        }
    }
    if (destination != NULL) memcpy(destination, data, size);
}

// FUN_0017a430
void FUN_0017a430(u32 saveType, u32 id, u32 size, const void* data)
{
    (void)saveType;
    switch (id)
    {
        case 1: break;
        case 2:
            if (DAT_007ce050 != NULL && size == 0x50)
                FUN_00521250(DAT_007ce050, data, 0x50);
            break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        case 10: break;
        case 11: break;
        case 12: break;
        case 13: break;
        case 14: break;
        case 15: break;
        case 16:
            if (DAT_007ce054 != NULL && size == 0x3400)
                FUN_00521250(DAT_007ce054, data, size);
            break;
        case 17:
            if (DAT_007ce058 != NULL && size == 0x2c0)
                FUN_00521250(DAT_007ce058, data, size);
            break;
        case 18: break;
        case 19: break;
        case 20: break;
        case 21: break;
        case 22: break;
        case 23: break;
        case 24:
            if (size == 0x2c)
                FUN_00521250(DAT_007ce05c, data, size);
            break;
        case 25: break;
        case 26: break;
        case 27: break;
        case 28: break;
        case 29: break;
        case 30: break;
        case 31: break;
        case 32: break;
        case 33: break;
        case 34: break;
        case 35: break;
        case 36: break;
        case 0x100: break;
        case 0x200: break;
        case 0x300: break;
        case 0x400: break;
        case 0x500: break;
        case 0x600: break;
        case 0x700: break;
        case 0x800: break;
        case 0x900: break;
        case 0xa00: break;
        case 0x101: break;
        case 0x201: break;
        case 0x301: break;
        case 0x401: break;
        case 0x501: break;
        case 0x601: break;
        case 0x701: break;
        case 0x801: break;
        case 0x901: break;
        case 0xa01: break;
        case 0x102: break;
        case 0x202: break;
        case 0x302: break;
        case 0x402: break;
        case 0x502: break;
        case 0x602: break;
        case 0x702: break;
        case 0x802: break;
        case 0x902: break;
        case 0xa02: break;
        case 0x103: break;
        case 0x203: break;
        case 0x303: break;
        case 0x403: break;
        case 0x503: break;
        case 0x603: break;
        case 0x703: break;
        case 0x803: break;
        case 0x903: break;
        case 0xa03: break;
        case 0x104: break;
        case 0x204: break;
        case 0x304: break;
        case 0x404: break;
        case 0x504: break;
        case 0x604: break;
        case 0x704: break;
        case 0x804: break;
        case 0x904: break;
        case 0xa04: break;
        case 0x105: break;
        case 0x205: break;
        case 0x305: break;
        case 0x405: break;
        case 0x505: break;
        case 0x605: break;
        case 0x705: break;
        case 0x805: break;
        case 0x905: break;
        case 0xa05: break;
        case 0x106: break;
        case 0x206: break;
        case 0x306: break;
        case 0x406: break;
        case 0x506: break;
        case 0x606: break;
        case 0x706: break;
        case 0x806: break;
        case 0x906: break;
        case 0xa06: break;
        case 0x107: break;
        case 0x207: break;
        case 0x307: break;
        case 0x407: break;
        case 0x507: break;
        case 0x607: break;
        case 0x707: break;
        case 0x807: break;
        case 0x907: break;
        case 0xa07: break;
        case 0x108: break;
        case 0x208: break;
        case 0x308: break;
        case 0x408: break;
        case 0x508: break;
        case 0x608: break;
        case 0x708: break;
        case 0x808: break;
        case 0x908: break;
        case 0xa08: break;
        case 0x109: break;
        case 0x209: break;
        case 0x309: break;
        case 0x409: break;
        case 0x509: break;
        case 0x609: break;
        case 0x709: break;
        case 0x809: break;
        case 0x909: break;
        case 0xa09: break;
        case 0x10a: break;
        case 0x20a: break;
        case 0x30a: break;
        case 0x40a: break;
        case 0x50a: break;
        case 0x60a: break;
        case 0x70a: break;
        case 0x80a: break;
        case 0x90a: break;
        case 0xa0a: break;
        case 0x10b: break;
        case 0x20b: break;
        case 0x30b: break;
        case 0x40b: break;
        case 0x50b: break;
        case 0x60b: break;
        case 0x70b: break;
        case 0x80b: break;
        case 0x90b: break;
        case 0xa0b: break;
        case 0x1000: break;
        case 0x1001: break;
        default: break;
    }
}

// FUN_0017ac60 NONMATCHING
void FUN_0017ac60(u32 code)
{
    u8* list = code_list();
    u8 bytes[4];
    u32 i;
    memcpy(bytes, &code, 4);
    for (i = 0; i < 0x100; i++)
    {
        if (list[i * 4] != 0 && memcmp(list + i * 4, bytes, 3) == 0)
        {
            for (; i < 0xff; i++) memcpy(list + i * 4, list + (i + 1) * 4, 4);
            U8(0x00836ba3) = 0;
        }
    }
    for (i = 0; i < 0x100 && list[i * 4] != 0; i++) { }
    if (i < 0x100) memcpy(list + i * 4, bytes, 4);
}

#pragma optimization_level 1
// FUN_0017ad90
void FUN_0017ad90(void)
{
    s32 i;
    s32 offset;
    u8* base;
    u8* previous;

    i = 0;
    base = DAT_00836200;
    while (i < 0x100)
    {
        offset = i * 4;
        if (*(u8*)((u32)base + (u32)offset + 0x5a7) == 0)
        {
            if (i == 0) return;
            previous = DAT_00836200 + 0x5a3;
            *(u8*)((u32)previous + (u32)offset) = 0;
            return;
        }
        i++;
    }
}
#pragma optimization_level 2

// FUN_0017adf0
void FUN_0017adf0(void)
{
    s32 i;
    u8* base;

    i = 0;
    base = DAT_00836200;
    while (i < 0x100)
    {
        *(u8*)((u32)base + (u32)(i * 4) + 0x5a7) = 0;
        i++;
    }
}

// FUN_0017ae30
u8* FUN_0017ae30(s32 index)
{
    u8* base = DAT_00836200;
    return base + index * 4 + 0x5a7;
}

// FUN_0017ae50
u32 FUN_0017ae50(s32 id)
{
    s32 i;
    ResourceEntry* entries;
    u16 target;
    u16* levels;

    if (((u16)id & 0x8000) != 0) id = ((ResourceEntry*)PTRP(0x00836794))[(u16)id].id;
    target = (u16)id;
    if (target >= 4000)
    {
        levels = (u16*)PTRP(0x00836798);
        if (levels[(s16)id - 4000] != 0) return 1;
    }
    else
    {
        i = 0;
        entries = (ResourceEntry*)PTRP(0x00836794);
        while (i < 300)
        {
            if (entries[i].id == target) return 1;
            i++;
        }
    }
    return 0;
}

// FUN_0017af20
void FUN_0017af20(u16 id)
{
    u8 record[0x20];
    u16* levels;

    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    if (id >= 4000)
    {
        levels = (u16*)PTRP(0x00836798);
        func_00170860(1, (s16)id, levels[(s16)id - 4000] + 1);
    }
    else
    {
        func_001828d0((s16)id, record);
        func_001830c0(record);
    }
}

// FUN_0017afd0
u32 FUN_0017afd0(u16 id)
{
    s32 i;
    ResourceEntry* entries;
    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    if (id >= 4000) return 1;
    i = 0;
    entries = (ResourceEntry*)PTRP(0x00836794);
    while (i < 300)
    {
        if (entries[i].id == 0) return 1;
        i++;
    }
    return 0;
}

// FUN_0017b070
void FUN_0017b070(u32 id)
{
    u16 value = (u16)id;

    if ((value & 0x8000) != 0)
    {
        ((ResourceEntry*)PTRP(0x00836794))[value & 0x7fff].id = 0;
    }
    else
    {
        s16 signedId = (s16)id;
        s32 levelAddress;
        u16* level;
        levelAddress = signedId * 2;
        levelAddress = ((u32)PTRP(0x00836798) - 0x1f40) + levelAddress;
        level = (u16*)levelAddress;
        if (*level != 0)
        {
            func_00170860(1, signedId, *level - 1);
        }
    }
}

// FUN_0017b100
void FUN_0017b100(u16 id)
{
    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    func_00171110(id, 2);
}

// FUN_0017b180
u32 FUN_0017b180(s32 amount)
{
    u32 totalBtl;

    totalBtl = gGlobalWork.totalBtl + amount;
    gGlobalWork.totalBtl = totalBtl;
    return totalBtl;
}

// FUN_0017b1a0
void FUN_0017b1a0(void)
{
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 11; i++) *(u32*)(base + i * 4 + 0x46c4) = 0;
}

// FUN_0017b1e0
void FUN_0017b1e0(u32 id)
{
    s32 key = id & 0xffff;
    u32 mask = 1u << (key & 31);
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    bits[index] |= mask;
}
// FUN_0017b220
void FUN_0017b220(u32 id)
{
    s32 key = id & 0xffff;
    u32 mask = 1u << (key & 31);
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    bits[index] &= ~mask;
}

// FUN_0017b260
u32 FUN_0017b260(u32 id)
{
    s32 key = id & 0xffff;
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    u32 mask = 1u << (key & 31);
    u32 result = bits[index];
    return result & mask;
}

// FUN_0017b2a0
void FUN_0017b2a0(void)
{
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 0x6a; i++) *(u32*)(base + i * 4 + 0x46f0) = 0;
}

// FUN_0017b2e0
void FUN_0017b2e0(u32 personaId, u32 slot, s32 enabled)
{
    u32 persona = personaId & 0xffff;
    u32 slotValue;
    u32 index;
    u32 wordIndex;
    u32 mask;

    if ((s32)persona >= 0x150) FUN_0019d3f0((u32)D_005e3098, 0x1631);
    slotValue = slot & 0xffff;
    if ((s32)slotValue >= 10) FUN_0019d3f0((u32)D_005e3098, 0x1632);
    index = slotValue + persona * 10;
    wordIndex = index >> 5;
    mask = 1u << (index & 31);
    if (enabled != 0)
        ((u32*)(DAT_00836200 + 0x46f0))[wordIndex] |= mask;
    else
        ((u32*)(DAT_00836200 + 0x46f0))[wordIndex] &= ~mask;
}

// FUN_0017b3d0
bool FUN_0017b3d0(u32 personaId, u32 slot)
{
    u32 index;
    s32 wordIndex;
    u32* bits;
    u32 mask;
    u32 result;
    if ((s32)(personaId & 0xffff) >= 0x150) FUN_0019d3f0((u32)D_005e3098, 0x1644);
    if ((s32)(slot & 0xffff) >= 10) FUN_0019d3f0((u32)D_005e3098, 0x1645);
    index = (slot & 0xffff) + (personaId & 0xffff) * 10;
    wordIndex = index >> 5;
    bits = (u32*)(DAT_00836200 + 0x46f0);
    mask = 1u << (index & 31);
    result = bits[wordIndex];
    return (result & mask) != 0;
}

// FUN_0017b480
s8 FUN_0017b480(s32 id)
{
    u16 check;
    check = id;
    if ((s32)check >= 0x270) FUN_0019d3f0((u32)D_005e3098, 0x166b);
    return puGpffffb704[(id & 0xffff) * 2 + 1];
}

// FUN_0017b500
void FUN_0017b500(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }
    FUN_003086c0(record, value);
}

// FUN_0017b5b0
void FUN_0017b5b0(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }
    FUN_003083f0(record, value);
}

// FUN_0017b660
s32 FUN_0017b660(s16 player, u64 id)
{
    u8* record;
    s32 index;
    u32* word;
    u32 mask;

    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }

    if (U16(record + 2) == 0 || (s32)U16(record + 2) >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x16aa);

    switch (id & 0xffff)
    {
    case 0x19f:
        index = D_005e3840[U16(record + 2)][0];
        word = D_0083a21c + index / 32;
        mask = 1u << (index % 32);
        return (*word & mask) != 0 ? 4 : 0;
    case 0x1a9:
        index = D_005e3844[U16(record + 2)][0];
        word = D_0083a21c + index / 32;
        mask = 1u << (index % 32);
        return (*word & mask) != 0 ? 4 : 0;
    default:
        return FUN_003086f0(record, id);
    }
}

// FUN_0017b860
s32 FUN_0017b860(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    s32 index;
    u8* left;
    u8* right;

    if (sourcePlayer == 0 || (s32)sourcePlayer >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x16c0);

    switch (id & 0xffff)
    {
    case 0x19f:
        index = D_005e3840[sourcePlayer][0];
        if (index < 0 || index >= 0x1600)
            FUN_0019d3f0((u32)D_005e3098, 0x78d);
        if (index == 0x1376) printf((char*)&gSpecialStatusMessage);
        D_0083a21c[index / 32] |= 1u << (index % 32);
        return 1;
    case 0x1a9:
        index = D_005e3844[sourcePlayer][0];
        if (index < 0 || index >= 0x1600)
            FUN_0019d3f0((u32)D_005e3098, 0x78d);
        if (index == 0x1376) printf((char*)&gSpecialStatusMessage);
        D_0083a21c[index / 32] |= 1u << (index % 32);
        return 1;
    }

    if (player == 1) left = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        left = D_00834010 + (player - 2) * 0x364 + 4;
    }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else
    {
        if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4;
    }

    return FUN_00306610(id, left, right, value);
}

// FUN_0017bb40
u8 FUN_0017bb40(s32 id)
{
    u16 checkedId = id;

    if ((s32)checkedId >= 0x1d0)
        FUN_0019d3f0((u32)D_005e3098, 0x16dd);
    return DAT_007ce3f8[(id & 0xffff) * 0x2c + 8];
}

// FUN_0017bbb0
u8 FUN_0017bbb0(s32 id)
{
    u16 checkedId = id;

    if ((s32)checkedId >= 0x1d0)
        FUN_0019d3f0((u32)D_005e3098, 0x16ec);
    return DAT_007ce3f8[(id & 0xffff) * 0x2c + 9];
}

// FUN_0017bc20
s32 FUN_0017bc20(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    u8* left;
    u8* right;
    u16 condition;

    if (sourcePlayer == 0 || (s32)sourcePlayer >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x1702);

    switch (id & 0xffff)
    {
    case 0x19f:
    case 0x1a9:
        condition = sourcePlayer == 1
            ? *(u16*)(DAT_00836200 + 0x6c)
            : *(u16*)(D_00833994 + sourcePlayer * 0x364);
        return condition == 5 ? 0 : 8;
    }

    if (player == 1) left = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        left = D_00834010 + (player - 2) * 0x364 + 4;
    }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else
    {
        if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4;
    }

    return FUN_003068d0(id, left, right, value);
}

// FUN_0017be10
void FUN_0017be10(s16 player, s16 sourcePlayer, u64 id, u64 a, u64 b, u64 c, u64 d)
{
    u8* left;
    u8* right;
    if (player == 1) left = DAT_00836200 + 0x24;
    else { if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1); left = D_00834010 + (player - 2) * 0x364 + 4; }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else { if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1); right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4; }
    FUN_00306bc0(id, left, right, a, b, c, d);
}

// FUN_0017bfa0
u8 FUN_0017bfa0(s32 id, s32 field)
{
    u8 checkedField = field;
    u32 inRange;
    s32 maskedId;

    if ((s32)checkedField < 0 || (s32)checkedField >= 5)
        FUN_0019d3f0((u32)D_005e3098, 0x173b);
    maskedId = id & 0xffff;
    if (maskedId < 0x1bf)
    {
        inRange = 0;
    }
    else
    {
        if (maskedId > 0x1cf)
        {
            inRange = 0;
        }
        else
        {
            inRange = 1;
        }
    }
    if (inRange == 0) return 0;
    return (DAT_007ce4a0 + maskedId * 5)[(field & 0xff) - 0x8bb];
}

// FUN_0017c070
u32 FUN_0017c070(u32 id)
{
    u8* record;
    u32 offset;
    u32 result;

    if ((s32)(id & 0xffff) >= 0x1d0) return 0;
    offset = (id & 0xffff) * 0x2c;
    record = (u8*)((u32)offset + (u32)DAT_007ce3f8);
    if (record[0x11] == 0xb && *(s16*)(record + 0x12) == 100)
        result = 1;
    else
        result = 0;
    return result;
}

// FUN_0017c0e0
u32 FUN_0017c0e0(u32 id)
{
    u16 flags;
    u32 valid = id < 0x100;

    if (valid == 0) FUN_0019d3f0((u32)D_005e3098, 0x1755);
    flags = *(u16*)(DAT_007ce42c + id * 0x58);
    if (flags & 2) return 2;
    if (flags & 4) return 4;
    if (flags & 8) return 8;
    return 0;
}

// FUN_0017C190


void func_0017c190(void)



{

  FUN_00521408(D_0083A6FC,0,0x1c);

  return;

}
// FUN_0017c1c0
void FUN_0017c1c0(const void* source)
{
    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x176d);
    memcpy(D_0083A6FC, source, 0x1c);
}

// FUN_0017c220
void FUN_0017c220(void* destination)
{
    if (destination == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1775);
    memcpy(destination, D_0083A6FC, 0x1c);
}

// FUN_0017C280


void func_0017c280(void)



{

    u8* entry;
    int i;

    for (i = 0; i < 4; i++)
    {
        entry = DAT_00836200 + i * 4;
        FUN_00521408(entry + 0x4518, 0, 4);
        *(s16*)(entry + 0x4518) = -1;
    }

}
// FUN_0017c2f0
s32 FUN_0017c2f0(const u32* left, const u32* right)
{
    const s16* leftValue = (const s16*)*left;
    const s16* rightValue = (const s16*)*right;
    return FUN_00403740(*leftValue) - FUN_00403740(*rightValue);
}

// FUN_0017c350 NONMATCHING
void FUN_0017c350(void)
{
    s16* source;
    u8** sorted;
    s32 count = 0;
    s32 i;

    source = (s16*)(*(void* (**)(u32, u32))D_00960178)(0x10, 0x40000);
    memcpy(source, PTR8(0x0083a718), 0x10);
    sorted = (u8**)(*(void* (**)(u32, u32))D_00960178)(0x10, 0x40000);
    memset(sorted, 0, 0x10);
    for (i = 0; i < 4; i++)
    {
        if (source[i * 2] != -1)
            sorted[count++] = (u8*)(source + i * 2);
    }
    if (count != 0)
        qsort(sorted, count, 4, (int (*)(const void*, const void*))FUN_0017c2f0);
    for (i = 0; i < 4; i++)
    {
        if (sorted[i] != NULL)
            memcpy(PTR8(0x00836200) + i * 4 + 0x4518, sorted[i], 4);
        else
            *(s16*)(PTR8(0x00836200) + i * 4 + 0x4518) = -1;
    }
    RELEASE(sorted);
    RELEASE(source);
}

#pragma optimization_level 1
// FUN_0017c4e0
bool FUN_0017c4e0(s16 value)
{
    struct CalendarSlot
    {
        s16 value;
        s16 unused;
    };
    struct CalendarWork
    {
        u8 unused[0x4518];
        struct CalendarSlot slots[3];
    };
    s32 i = 0;
    struct CalendarSlot* slot;
    struct CalendarWork* work = (struct CalendarWork*)DAT_00836200;
    u8* candidateBase;
    s32 empty = -1;

    while (i < 3)
    {
        candidateBase = (u8*)((u32)work + (u32)(i * 4));
        if (*(s16*)(candidateBase + 0x4518) == empty)
        {
            slot = (struct CalendarSlot*)(candidateBase + 0x4518);
            FUN_00521408(slot, 0, 4);
            goto found;
        }
        i++;
    }
    slot = NULL;
found:
    if (slot == NULL) return false;
    slot->value = value;
    FUN_0017c350();
    return true;
}
#pragma optimization_level 2

// FUN_0017c590
void FUN_0017c590(s16 value)
{
    struct CalendarSlot
    {
        s16 value;
        s16 unused;
    };
    struct CalendarWork
    {
        u8 unused[0x4518];
        struct CalendarSlot slots[3];
    };
    s32 i = 0;
    s32 target = value;
    struct CalendarWork* work = (struct CalendarWork*)DAT_00836200;

    while (i < 3)
    {
        struct CalendarSlot* slot = &work->slots[i];
        if (slot->value == target)
        {
            slot->value = -1;
            break;
        }
        i++;
    }
    FUN_0017c350();
}

// FUN_0017c610
s16* FUN_0017c610(s16 value)
{
    struct CalendarEntry
    {
        u8 unused[0x4518];
        s16 value;
    };
    s32 i = 0;
    s32 target = value;
    struct CalendarEntry* data = (struct CalendarEntry*)DAT_00836200;

    for (; i < 3; i++)
    {
        struct CalendarEntry* entry = (struct CalendarEntry*)((u8*)data + i * 4);
        if (entry->value == target)
            return &entry->value;
    }
    return NULL;
}

// FUN_0017c670
s16* FUN_0017c670(s32 index)
{
    s32 offset = index * 4;

    if (*(s16*)(DAT_0083a718 + offset) != -1)
        return (s16*)(DAT_00836200 + offset + 0x4518);
    return NULL;
}

#pragma opt_loop_invariants on
// FUN_0017c700
s32 FUN_0017c700(void)
{
    s32 count = 0;
    s32 sentinel = -1;
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 3; i++)
    {
        s32 value = *(s16*)(base + i * 4 + 0x4518);
        if (value != sentinel) count++;
    }
    return count;
}
#pragma opt_loop_invariants off

// FUN_0017c750
void FUN_0017c750(u64 value)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        u8* entry = DAT_00836200 + i * 4;
        if (*(s16*)(entry + 0x4518) != -1 &&
            FUN_00403920(*(s16*)(entry + 0x4518), value) != 0)
        {
            s16* counter = (s16*)(entry + 0x451a);
            s16 current = *counter;
            if (current < 0x7d01) *counter = current + 1;
        }
    }
}

// FUN_0017c7f0
void FUN_0017c7f0(s32 index, u8 value)
{
    if (index < 0 || index >= 8) FUN_0019d3f0((u32)D_005e3098, 0x180f);
    DAT_00836200[0x4528 + index] = value;
}

// FUN_0017c860
u8 FUN_0017c860(s32 index)
{
    if (index < 0 || index >= 8) FUN_0019d3f0((u32)D_005e3098, 0x1814);
    return DAT_00836200[0x4528 + index];
}

// FUN_0017c960
void FUN_0017c960(const void* record)
{
    const u8* source = (const u8*)record;
    s32 id;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x182b);
    id = *(const u16*)(source + 2);
    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x182c);
    memcpy(DAT_00836200 + *(const u16*)(source + 2) * 0x34 + 0xc1c, source, 0x34);
}

// FUN_0017ca10 NONMATCHING
s32 FUN_0017ca10(const void* record)
{
    const u8* source = (const u8*)record;
    u8* stored;
    s32 id;
    s32 i;

    if (record == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1837);
    id = *(const u16*)(source + 2);
    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1838);
    stored = DAT_00836200 + id * 0x34 + 0xc1c;
    if ((*(const u16*)stored & 1) == 0) return -1;
    if (*(const u16*)stored != *(const u16*)source) return 1;
    if (stored[4] != source[4]) return 1;
    if (*(const u32*)(stored + 8) != *(const u32*)(source + 8)) return 1;
    for (i = 0; i < 5; i++)
        if (stored[0x1c + i] != source[0x1c + i]) return 1;
    for (i = 0; i < 5; i++)
        if ((s8)stored[0x21 + i] != (s8)source[0x21 + i]) return 1;
    for (i = 0; i < 5; i++)
        if ((s8)stored[0x26 + i] != (s8)source[0x26 + i]) return 1;
    for (i = 0; i < 8; i++)
        if (*(const u16*)(stored + 0xc + i * 2) != *(const u16*)(source + 0xc + i * 2)) return 1;
    return 0;
}

// FUN_0017cd30
void* FUN_0017cd30(void* record)
{
    u8* source = (u8*)record;
    u8* definition;
    u8* stored;
    s32 id;
    s32 storedId;
    u16 flags;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1861);
    id = *(u16*)(source + 2);
    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1862);
    id = *(u16*)(source + 2);
    definition = DAT_007ce420 + id * 0xe;
    flags = *(u16*)definition;
    if (flags & 8) return source;
    if (flags & 0x20) return source;

    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1821);
    if ((*(u16*)(DAT_00836e1c + id * 0x34) & 1) != 0)
        stored = DAT_00836200 + id * 0x34 + 0xc1c;
    else
        stored = NULL;
    if (stored != NULL) return stored;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x182b);
    storedId = *(u16*)(source + 2);
    if (storedId < 0 || storedId >= 0x100)
        FUN_0019d3f0((u32)D_005e3098, 0x182c);
    memcpy(DAT_00836200 + *(u16*)(source + 2) * 0x34 + 0xc1c, source, 0x34);
    return NULL;
}

// FUN_0017cf00
s32 FUN_0017cf00(void)
{
    s32 id;
    s32 valid;
    s32 definitionId;
    s32 eligible;
    u8* stored;
    u8* definitions;

    valid = 0;
    id = 0;
    while (id < 0x100)
    {
        if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1821);
        stored = DAT_00836200 + id * 0x34;
        if ((*(u16*)(stored + 0xc1c) & 1) != 0)
            stored = stored + 0xc1c;
        else
            stored = NULL;
        if (stored != NULL) valid++;
        id++;
    }

    eligible = 0;
    definitionId = 0;
    definitions = DAT_007ce420;
    while (definitionId < 0x100)
    {
        u16 flags = *(u16*)(definitions + definitionId * 0xe);
        if ((flags & 8) == 0 && (flags & 0x20) == 0) eligible++;
        definitionId++;
    }
    return valid * 100 / eligible;
}

// FUN_0017d030
u32 FUN_0017d030(void)
{
    return U32(0x0083a730);
}

// FUN_0017d040
void FUN_0017d040(void)
{
    U32(0x0083a730) = *(u32*)(D_0083A6FC + 0x34) + 1;
}

typedef union PairKey
{
    f32 value;
    struct
    {
        u16 low;
        u16 high;
    } parts;
} PairKey;

// FUN_0017d060
PairCounter* FUN_0017d060(PairKey key, u16 id, s16 value)
{
    struct PairCounterU
    {
        PairKey key;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    s32 j;
    u32 keyValue = key.parts.low;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterU* freeEntry;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL)
    {
        if (found->key.parts.high != key.parts.high)
        {
            found->key = key;
            found->remaining = value;
        }
        return (PairCounter*)found;
    }

    j = 0;
    work = (struct PairCounterWork*)DAT_00836200;
    while (j < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(j * 8));
        if (*(u16*)(entryBase + 0x4538) == 0)
        {
            freeEntry = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_free_entry;
        }
        j++;
    }
    freeEntry = NULL;
found_free_entry:
    if (freeEntry == NULL)
    {
        FUN_0019d3f0((u32)D_005e3098, 0x18c5);
    }
    freeEntry->key = key;
    freeEntry->id = id;
    freeEntry->remaining = value;
    return (PairCounter*)freeEntry;
}

// FUN_0017d1a0
u32 FUN_0017d1a0(u32 key, u16 id, s16 amount)
{
    struct PairCounterU
    {
        u16 key;
        u16 keyHigh;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    u32 keyValue = *(u16*)&key;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL)
    {
        s16 remaining = (s16)(found->remaining - amount);
        if (remaining < 0) remaining = 0;
        found->remaining = remaining;
        return found->remaining;
    }
    return 0xffffffff;
}

// FUN_0017d250
u32 FUN_0017d250(u32 key, u16 id)
{
    struct PairCounterU
    {
        u16 key;
        u16 keyHigh;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    u32 keyValue = *(u16*)&key;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL) return found->remaining;
    return 0xffffffff;
}

// FUN_0017d2e0
s8 FUN_0017d2e0(u32 id)
{
    s32 index;
    u16 check;

    index = (s16)FUN_003082f0(0, id);
    {
        s8 values[0x13] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 10, 10, 10, 10, 10, 10, 10, 10
        };
        if (index == -1)
        {
            check = id;
            if ((s32)check >= 0x270)
                FUN_0019d3f0((u32)D_005e3098, 0x166b);
            if (puGpffffb704[(id & 0xffff) * 2 + 1] == 2)
                return 0xc;
        }
        return values[index];
    }
}

// FUN_0017d3c0
void FUN_0017d3c0(void)
{
    struct DateTemplate
    {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
    };
    extern const volatile struct DateTemplate D_005e38c0;
    volatile struct DateTemplate template;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 i;

    a = D_005e38c0.a;
    b = D_005e38c0.b;
    c = D_005e38c0.c;
    d = D_005e38c0.d;
    template.a = a;
    template.b = b;
    template.c = c;
    template.d = d;
    i = 0;
    while (i < 9)
    {
        memcpy(DAT_00836200 + i * 0x10 + 0x4634, (const void*)&template, 0x10);
        i++;
    }
}

// FUN_0017d450 NONMATCHING
u32 FUN_0017d450(s32 index, const void* date)
{
    u8 current[8];
    s32 newer = 0;

    if (date == NULL) FUN_0019d3f0(0x5e3098, 0x1933);
    if (index >= 5) return 0;
    memcpy(current, DAT_00836200 + index * 0x10 + 0x4634, 8);
    if (index == 3) return 0;
    if (index == 4)
        return current[1] < ((const u8*)date)[1];
    if (current[0] < ((const u8*)date)[0])
        newer = 1;
    if (newer == 0 && current[0] == ((const u8*)date)[0])
    {
        if (current[1] < ((const u8*)date)[1])
            newer = 1;
        if (newer == 0 && current[1] == ((const u8*)date)[1])
        {
            if (*(const s16*)(current + 2) != *(const s16*)((const u8*)date + 2))
                newer = 1;
            if (newer == 0 && *(const u32*)(current + 4) != *(const u32*)((const u8*)date + 4))
                newer = 1;
        }
    }
    if (newer != 0)
    {
        if (FUN_003f33d0(index, 4) != 0) return 1;
        memcpy(DAT_00836200 + (index * 2 + 1) * 8 + 0x4634, current, 8);
        memcpy(DAT_00836200 + index * 0x10 + 0x4634, date, 8);
    }
    return 0;
}

// FUN_0017d610
u32 FUN_0017d610(u32 index)
{
    u8 date[8];
    u32 doubled;
    u32 result;

    if ((s32)index <= 4) goto valid_index;
    result = 0;
    goto done;
valid_index:
    FUN_003eff00(index, date);
    if (FUN_0017d450(index, date) != 0)
    {
        doubled = index * 2;
        index = (u32)(DAT_00836200 + index * 0x10 + 0x4634);
        memcpy(DAT_00836200 + (doubled + 1) * 8 + 0x4634, (void*)index, 8);
        memcpy((void*)index, date, 8);
        result = 1;
    }
    else
    {
        result = 0;
    }
done:
    return result;
}

// FUN_0017d700
void FUN_0017d700(s32 index, s32 slot, void* date)
{
    if (date == NULL) FUN_0019d3f0((u32)D_005e3098, 0x197f);
    memcpy(date, DAT_00836200 + ((index << 1) + slot) * 8 + 0x4634, 8);
}

// FUN_0017d7b0
u32 FUN_0017d7b0(void)
{
    return U32(0x0083aa98);
}

#pragma optimization_level 1
// FUN_0017d7c0
void FUN_0017d7c0(u32 value)
{
    U32(0x0083aa98) = value;
    if (U32(0x0083aa98) > 99)
        U32(0x0083aa98) = 99;
}
#pragma optimization_level 2

// FUN_0017d810
u32 FUN_0017d810(void)
{
    return U32(0x0083a6f8);
}

// FUN_0017d820
void FUN_0017d820(u32 value)
{
    U32(0x0083a6f8) = value;
}
