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
extern void FUN_0019d3f0(u32 file, u32 line);
extern void func_001828d0(u16 id, void* record);
extern void func_001830c0(void* record);
extern s16 FUN_003082f0(s32 category, u64 id);
extern u64 FUN_003086f0(void* record, u64 id);
extern void FUN_003086c0(void* record, u64 value);
extern void FUN_003083f0(void* record, u64 value);
extern u64 FUN_00306610(u64 value, void* left, void* right, u64 extra);
extern u64 FUN_003068d0(u64 value, void* left, void* right, u64 extra);
extern void FUN_00306bc0(u64 value, void* left, void* right, u64 a, u64 b, u64 c, u64 d);
extern s16 FUN_00403740(u16 id);
extern u64 FUN_00403920(u16 id, u64 value);
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
extern u8 DAT_0083a718[];

#define PTR8(addr) ((u8*)(addr))
#define PTR16(addr) ((u16*)(addr))
#define PTR32(addr) ((u32*)(addr))
#define PTRP(addr) (*(u8**)(addr))
#define U8(addr) (*PTR8(addr))
#define U16(addr) (*PTR16(addr))
#define U32(addr) (*PTR32(addr))
#define ALLOCATE(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184)(count, size, flags)
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

static void save_chunk(u8** cursor, u32 id, u32 size, const void* source)
{
    memcpy(*cursor, &id, 4);
    memcpy(*cursor + 4, &size, 4);
    memcpy(*cursor + 8, source, size);
    *cursor += size + 8;
}

// FUN_00177d40 NONMATCHING
void FUN_00177d40(void)
{
    PTRP(0x00836794) = (u8*)ALLOCATE(300, 0x14, 0x40000);
    PTRP(0x00836798) = (u8*)ALLOCATE(300, 2, 0x40000);
}

// FUN_00177db0 NONMATCHING
void* FUN_00177db0(u32 saveType, s32* saveSize)
{
    u8* buffer;
    u8* cursor;
    u8 header[0x34];
    u8 checksum;
    u32 i;
    static const u32 baseIds[] =
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    };
    static const u32 baseSizes[] =
    {
        0x24, 0x50, 0x508, 0x10, 8, 6000, 600, 2, 1, 4, 2, 1, 0x400,
        2, 0x270, 0x3400, 0x2c0, 4, 8, 4, 4, 4, 4, 0x2c, 0x200, 0x1c,
        0x10, 8, 4, 0x100, 0x90,
    };
    static const u32 baseSources[] =
    {
        0x00836200, 0x00836224, 0x00836274, 0x0083677c, 0x0083678c,
        0, 0, 0x0083679c, 0x0083679e, 0x008367a0, 0x008367a4,
        0x008367a6, 0x008367a7, 0x00836ba8, 0x00836bac, 0x00836e1c,
        0x0083a21c, 0x0083a6dc, 0x0083a6e0, 0x0083a6e8, 0x0083a6ec,
        0x0083a6f0, 0x0083a6f4, 0x0083a8c4, 0x0083a4dc, 0x0083a6fc,
        0x0083a718, 0x0083a728, 0x0083a730, 0x0083a734, 0x0083a834,
    };
    u8* resourceTable = PTRP(0x00836794);
    u8* levelTable = PTRP(0x00836798);

    buffer = (u8*)ALLOCATE(1, 0x20000, 0x40000);
    if (buffer == NULL)
    {
        if (saveSize != NULL) *saveSize = 0;
        return NULL;
    }

    memset(header, 0, sizeof(header));
    memcpy(header, PTR8(0x0083679c), 4);
    memcpy(header + 4, PTR8(0x0083a598), 4);
    memcpy(header + 8, PTR8(0x00836200), 0x24);
    header[0x2c] = (u8)FUN_0017d7b0();
    header[0x2d] = (U32(0x0083a47c) & 0x2000000) != 0 ? 2 :
                   ((U32(0x0083a47c) & 0x20000) != 0 ? 1 : 0);
    header[0x2e] = (u8)FUN_001bff20();
    header[0x2f] = (u8)U32(0x0083a6ec);
    header[0x30] = (u8)U32(0x0083a6f0);
    checksum = 0;
    for (i = 0; i < 0x32; i++) checksum = (u8)(checksum + header[i]);
    header[0x31] = checksum;

    memcpy(buffer, &saveType, 4);
    cursor = buffer + 4;
    memcpy(cursor, header, sizeof(header));
    cursor += sizeof(header);

    for (i = 0; i < ARRAY_SIZE(baseIds); i++)
    {
        const void* source = (const void*)(baseSources[i]);
        if (i == 5) source = resourceTable;
        if (i == 6) source = levelTable;
        save_chunk(&cursor, baseIds[i], baseSizes[i], source);
    }
    save_chunk(&cursor, 0x21, 0x1a8, PTR8(0x0083a8f0));
    save_chunk(&cursor, 0x22, 1, PTR8(0x0083679e));
    save_chunk(&cursor, 0x23, 4, PTR8(0x0083aa98));
    save_chunk(&cursor, 0x24, 4, PTR8(0x0083a6f8));

    for (i = 0; i < 10; i++)
    {
        u32 base = 0x100 + i * 0x100;
        u32 source = 0x00834010 + i * 0x364;
        save_chunk(&cursor, base,       4,    PTR8(source));
        save_chunk(&cursor, base + 1,   0x50, PTR8(source + 4));
        save_chunk(&cursor, base + 2,   8,    PTR8(source + 0x54));
        save_chunk(&cursor, base + 3,   0x50, PTR8(source + 0x5c));
        save_chunk(&cursor, base + 4,   0x30, PTR8(source + 0xac));
        save_chunk(&cursor, base + 5,   0x34, PTR8(source + 0xdc));
        save_chunk(&cursor, base + 6,   0x10, PTR8(source + 0x110));
        save_chunk(&cursor, base + 7,   0x10, PTR8(source + 0x120));
        save_chunk(&cursor, base + 8,   0x50, PTR8(source + 0x130));
        save_chunk(&cursor, base + 9,   0x190, PTR8(source + 0x180));
        save_chunk(&cursor, base + 10,  0x50, PTR8(source + 0x310));
        save_chunk(&cursor, base + 11,  4,    PTR8(source + 0x360));
    }
    save_chunk(&cursor, 0x1000, 400, PTR8(0x00833e80));
    save_chunk(&cursor, 0x1001, 600, PTR8(0x00833c20));
    checksum = 0;
    for (i = 0; i < (u32)(cursor - (buffer + 0x38)); i++) checksum = (u8)(checksum + buffer[0x38 + i]);
    save_chunk(&cursor, 0x2000, 1, &checksum);
    {
        u32 end = 0xffffffff;
        memcpy(cursor, &end, 4);
        cursor += 4;
    }

    if (saveSize != NULL) *saveSize = (s32)(cursor - buffer);
    printf("save image size %d\n", (s32)(cursor - buffer));
    return buffer;
}

// FUN_00179030 NONMATCHING
void FUN_00179030(u32 saveType, s32 stream)
{
    u8* cursor = (u8*)stream;
    u32 id;
    u32 size;

    if (saveType > 1) cursor += 0x34;
    for (;;)
    {
        memcpy(&id, cursor, 4);
        if (id == 0xffffffff || id == 0x2000) break;
        memcpy(&size, cursor + 4, 4);
        cursor += 8;
        if (U32(0x007ce00c) == 0)
            FUN_00179360(saveType, id, size, cursor);
        else
            FUN_0017a430(saveType, id, size, cursor);
        cursor += size;
    }

    if (U32(0x007ce00c) == 0)
    {
        memset(PTR8(0x00833bb0), 0, 0x12);
        memset(PTR8(0x00833bd0), 0, 0x12);
        memset(PTR8(0x00833bf0), 0, 0x24);
        memcpy(PTR8(0x00833bb0), PTR8(0x00836200), 0x12);
        memcpy(PTR8(0x00833bd0), PTR8(0x00836212), 0x12);
    }
}

// FUN_001791d0 NONMATCHING
bool FUN_001791d0(u32 saveType, s32 stream, s32 streamSize)
{
    u8* cursor;
    u32 id;
    u32 size;
    u32 consumed = 0;
    u8 checksum = 0;
    u8 stored;
    u32 i;

    if (streamSize < 0x1000) return false;
    cursor = (u8*)stream + (saveType > 1 ? 0x34 : 0);
    if (saveType < 3) return true;
    while (consumed < (u32)(streamSize - 0x34))
    {
        memcpy(&id, cursor, 4);
        if (id == 0xffffffff) return false;
        memcpy(&size, cursor + 4, 4);
        if (size == 0) return false;
        if (id == 0x2000)
        {
            memcpy(&stored, cursor + 8, 1);
            return checksum == stored;
        }
        for (i = 0; i < size; i++) checksum = (u8)(checksum + cursor[8 + i]);
        cursor += 8 + size;
        consumed += 8 + size;
    }
    return false;
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

// FUN_0017a430 NONMATCHING
void FUN_0017a430(u32 saveType, u32 id, u32 size, const void* data)
{
    (void)saveType;
    if (id == 0x18 && size == 0x2c) memcpy(PTRP(0x007ce05c), data, size);
    else if (id == 0x11 && size == 0x2c0 && PTRP(0x007ce058) != NULL) memcpy(PTRP(0x007ce058), data, size);
    else if (id == 0x10 && size == 0x3400 && PTRP(0x007ce054) != NULL) memcpy(PTRP(0x007ce054), data, size);
    else if (id == 2 && size == 0x50 && PTRP(0x007ce050) != NULL) memcpy(PTRP(0x007ce050), data, size);
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

// FUN_0017ad90 NONMATCHING
void FUN_0017ad90(void)
{
    s32 i;
    u8* list = code_list();
    for (i = 0; i < 0x100 && list[i * 4] != 0; i++) { }
    if (i > 0) list[i * 4 - 1] = 0;
}

// FUN_0017adf0 NONMATCHING
void FUN_0017adf0(void)
{
    s32 i;
    u8* list = code_list();
    for (i = 0; i < 0x100; i++) list[i * 4] = 0;
}

// FUN_0017ae30 NONMATCHING
u8* FUN_0017ae30(s32 index)
{
    return code_list() + index * 4;
}

// FUN_0017ae50 NONMATCHING
u32 FUN_0017ae50(u16 id)
{
    s32 i;
    if (id & 0x8000) id = resource_entries()[id & 0x7fff].id;
    if (id < 4000)
    {
        for (i = 0; i < 300; i++) if (resource_entries()[i].id == id) return 1;
    }
    else if (id >= 8000 && id < 8300 && resource_levels()[id - 8000] != 0)
    {
        return 1;
    }
    return 0;
}

// FUN_0017af20 NONMATCHING
void FUN_0017af20(u16 id)
{
    u8 record[0x20];
    if (id & 0x8000) id = resource_entries()[id & 0x7fff].id;
    if (id < 4000)
    {
        func_001828d0(id, record);
        func_001830c0(record);
    }
    else if (id >= 8000 && id < 8300)
    {
        func_00170860(1, id, resource_levels()[id - 8000] + 1);
    }
}

// FUN_0017afd0 NONMATCHING
u32 FUN_0017afd0(u16 id)
{
    s32 i;
    if (id & 0x8000) id = resource_entries()[id & 0x7fff].id;
    if (id < 4000)
    {
        for (i = 0; i < 300; i++) if (resource_entries()[i].id == 0) return 1;
        return 0;
    }
    return 1;
}

// FUN_0017b070 NONMATCHING
void FUN_0017b070(u32 id)
{
    if ((id & 0x8000) == 0)
    {
        if (id >= 8000 && id < 8300 && resource_levels()[id - 8000] != 0)
            func_00170860(1, id, resource_levels()[id - 8000] - 1);
    }
    else
    {
        resource_entries()[id & 0x7fff].id = 0;
    }
}

// FUN_0017b100 NONMATCHING
void FUN_0017b100(u16 id)
{
    if (id & 0x8000) id = resource_entries()[id & 0x7fff].id;
    func_00171110(id, 2);
}

// FUN_0017b180 NONMATCHING
void FUN_0017b180(s32 amount)
{
    U32(0x0083a6e8) += amount;
}

// FUN_0017b1a0 NONMATCHING
void FUN_0017b1a0(void)
{
    memset(PTR8(0x0083a8c4), 0, 0x2c);
}

// FUN_0017b1e0 NONMATCHING
void FUN_0017b1e0(u32 id)
{
    bit_list()[((id & 0xffff) >> 5)] |= bit_mask(id);
}

// FUN_0017b220 NONMATCHING
void FUN_0017b220(u32 id)
{
    bit_list()[((id & 0xffff) >> 5)] &= ~bit_mask(id);
}

// FUN_0017b260 NONMATCHING
u32 FUN_0017b260(u32 id)
{
    return bit_list()[((id & 0xffff) >> 5)] & bit_mask(id);
}

// FUN_0017b2a0 NONMATCHING
void FUN_0017b2a0(void)
{
    memset(PTR8(0x0083a8f0), 0, 0x1a8);
}

// FUN_0017b2e0 NONMATCHING
void FUN_0017b2e0(u32 personaId, u32 slot, s32 enabled)
{
    u32 index;
    if ((personaId & 0xffff) > 0x14f) FUN_0019d3f0(0x5e3098, 0x1631);
    if ((slot & 0xffff) > 9) FUN_0019d3f0(0x5e3098, 0x1632);
    index = (slot & 0xffff) + (personaId & 0xffff) * 10;
    if (enabled == 0) pair_bits()[index >> 5] &= ~bit_mask(index);
    else pair_bits()[index >> 5] |= bit_mask(index);
}

// FUN_0017b3d0 NONMATCHING
bool FUN_0017b3d0(u32 personaId, u32 slot)
{
    u32 index;
    if ((personaId & 0xffff) > 0x14f) FUN_0019d3f0(0x5e3098, 0x1644);
    if ((slot & 0xffff) > 9) FUN_0019d3f0(0x5e3098, 0x1645);
    index = (slot & 0xffff) + (personaId & 0xffff) * 10;
    return (pair_bits()[index >> 5] & bit_mask(index)) != 0;
}

// FUN_0017b480 NONMATCHING
u8 FUN_0017b480(u16 id)
{
    if (id > 0x26f) FUN_0019d3f0(0x5e3098, 0x166b);
    return PTRP(0x007ce3f4)[id * 2 + 1];
}

// FUN_0017b500 NONMATCHING
void FUN_0017b500(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = PTR8(0x00836224);
    else
    {
        if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1);
        record = PTR8(0x00834014 + (player - 2) * 0x364);
    }
    FUN_003086c0(record, value);
}

// FUN_0017b5b0 NONMATCHING
void FUN_0017b5b0(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = PTR8(0x00836224);
    else
    {
        if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1);
        record = PTR8(0x00834014 + (player - 2) * 0x364);
    }
    FUN_003083f0(record, value);
}

// FUN_0017b660 NONMATCHING
u64 FUN_0017b660(s16 player, u64 id)
{
    u8* record;
    u32 index;
    if (player == 1) record = PTR8(0x00836224);
    else
    {
        if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1);
        record = PTR8(0x00834014 + (player - 2) * 0x364);
    }
    if (U16(record + 2) == 0 || U16(record + 2) > 10) FUN_0019d3f0(0x5e3098, 0x16aa);
    index = U16(record + 2);
    if ((id & 0xffff) == 0x1a9)
    {
        index = PTR32(0x005e3844)[index];
        return (PTR32(0x0083a21c)[bit_index(index)] & bit_mask(index)) != 0 ? 4 : 0;
    }
    if ((id & 0xffff) == 0x19f)
    {
        index = PTR32(0x005e3840)[index];
        return (PTR32(0x0083a21c)[bit_index(index)] & bit_mask(index)) != 0 ? 4 : 0;
    }
    return FUN_003086f0(record, id);
}

// FUN_0017b860 NONMATCHING
u64 FUN_0017b860(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    u32 index;
    u8* left;
    u8* right;
    if (sourcePlayer == 0 || sourcePlayer > 10) FUN_0019d3f0(0x5e3098, 0x16c0);
    index = PTR32((id & 0xffff) == 0x1a9 ? 0x005e3844 : 0x005e3840)[sourcePlayer];
    if (index > 0x15ff) FUN_0019d3f0(0x5e3098, 0x78d);
    if (index == 0x1376) printf("special status\n");
    PTR32(0x0083a21c)[bit_index(index)] |= bit_mask(index);
    if ((id & 0xffff) == 0x1a9 || (id & 0xffff) == 0x19f) return 1;
    if (player == 1) left = PTR8(0x00836224);
    else { if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1); left = PTR8(0x00834014 + (player - 2) * 0x364); }
    if (sourcePlayer == 1) right = PTR8(0x00836224);
    else { right = PTR8(0x00834014 + (sourcePlayer - 2) * 0x364); }
    return FUN_00306610(id, left, right, value);
}

// FUN_0017bb40 NONMATCHING
u8 FUN_0017bb40(u16 id)
{
    if (id > 0x1cf) FUN_0019d3f0(0x5e3098, 0x16dd);
    return PTRP(0x007ce3f8)[id * 0x2c + 8];
}

// FUN_0017bbb0 NONMATCHING
u8 FUN_0017bbb0(u16 id)
{
    if (id > 0x1cf) FUN_0019d3f0(0x5e3098, 0x16ec);
    return PTRP(0x007ce3f8)[id * 0x2c + 9];
}

// FUN_0017bc20 NONMATCHING
u64 FUN_0017bc20(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    u8* left;
    u8* right;
    s16 condition;
    if (sourcePlayer == 0 || sourcePlayer > 10) FUN_0019d3f0(0x5e3098, 0x1702);
    if ((id & 0xffff) == 0x1a9 || (id & 0xffff) == 0x19f)
    {
        condition = sourcePlayer == 1 ? (s16)U16(0x0083626c) : *(s16*)(0x00833994 + sourcePlayer * 0x364);
        return condition == 5 ? 0 : 8;
    }
    if (player == 1) left = PTR8(0x00836224);
    else { if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1); left = PTR8(0x00834014 + (player - 2) * 0x364); }
    if (sourcePlayer == 1) right = PTR8(0x00836224);
    else right = PTR8(0x00834014 + (sourcePlayer - 2) * 0x364);
    return FUN_003068d0(id, left, right, value);
}

// FUN_0017be10 NONMATCHING
void FUN_0017be10(s16 player, s16 sourcePlayer, u64 id, u64 a, u64 b, u64 c, u64 d)
{
    u8* left;
    u8* right;
    if (player == 1) left = PTR8(0x00836224);
    else { if (player > 10) FUN_0019d3f0(0x5e3098, 0x2e1); left = PTR8(0x00834014 + (player - 2) * 0x364); }
    if (sourcePlayer == 1) right = PTR8(0x00836224);
    else { if (sourcePlayer > 10) FUN_0019d3f0(0x5e3098, 0x2e1); right = PTR8(0x00834014 + (sourcePlayer - 2) * 0x364); }
    FUN_00306bc0(id, left, right, a, b, c, d);
}

// FUN_0017bfa0 NONMATCHING
u8 FUN_0017bfa0(u32 id, u8 field)
{
    u8* table;
    if (field > 4) FUN_0019d3f0(0x5e3098, 0x173b);
    id &= 0xffff;
    if (id < 0x1bf || id >= 0x1d0) return 0;
    table = PTRP(0x007ce4a0);
    if (table == NULL) return 0;
    return table[id * 5 + field - 0x8bb];
}

// FUN_0017c070 NONMATCHING
u32 FUN_0017c070(u32 id)
{
    u8* record;
    if ((id & 0xffff) >= 0x1d0) return 0;
    record = PTRP(0x007ce3f8) + (id & 0xffff) * 0x2c;
    return record[0x11] == 0xb && *(u16*)(record + 0x12) == 100;
}

// FUN_0017c0e0 NONMATCHING
u32 FUN_0017c0e0(u32 id)
{
    u16 flags;
    if (id > 0xff) FUN_0019d3f0(0x5e3098, 0x1755);
    flags = U16(PTRP(0x007ce42c) + id * 0x58);
    if (flags & 2) return 2;
    if (flags & 4) return 4;
    if (flags & 8) return 8;
    return 0;
}

// FUN_0017C190 NONMATCHING


void func_0017c190(void)



{

  FUN_00521408(0x83a6fc,0,0x1c);

  return;

}
// FUN_0017c1c0 NONMATCHING
void FUN_0017c1c0(const void* source)
{
    if (source == NULL) FUN_0019d3f0(0x5e3098, 0x176d);
    memcpy(PTR8(0x0083a6fc), source, 0x1c);
}

// FUN_0017c220 NONMATCHING
void FUN_0017c220(void* destination)
{
    if (destination == NULL) FUN_0019d3f0(0x5e3098, 0x1775);
    memcpy(destination, PTR8(0x0083a6fc), 0x1c);
}

// FUN_0017C280 NONMATCHING


void func_0017c280(void)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

    FUN_00521408(DAT_0083a718 + iVar1 * 4,0,4);

    *(u16 *)(DAT_0083a718 + iVar1 * 4) = 0xffff;

  }

  return;

}
// FUN_0017c2f0 NONMATCHING
s32 FUN_0017c2f0(const u32* left, const u32* right)
{
    return FUN_00403740(*(const u16*)*left) - FUN_00403740(*(const u16*)*right);
}

// FUN_0017c350 NONMATCHING
void FUN_0017c350(void)
{
    s16* source = (s16*)ALLOCATE_SMALL(4, 4, 0x40000);
    s16* sorted = (s16*)ALLOCATE_SMALL(4, 4, 0x40000);
    s32 count = 0;
    s32 i;
    if (source == NULL || sorted == NULL)
    {
        if (source != NULL) RELEASE(source);
        if (sorted != NULL) RELEASE(sorted);
        return;
    }
    memcpy(source, PTR8(0x0083a718), 0x10);
    memset(sorted, 0, 0x10);
    for (i = 0; i < 4; i++) if (source[i] != -1) sorted[count++] = source[i];
    if (count > 1) qsort(sorted, count, 4, (int (*)(const void*, const void*))FUN_0017c2f0);
    for (i = 0; i < 4; i++) *(s16*)(0x0083a718 + i * 4) = sorted[i] == 0 ? -1 : sorted[i];
    RELEASE(sorted);
    RELEASE(source);
}

// FUN_0017c4e0 NONMATCHING
bool FUN_0017c4e0(s16 value)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        if (*(s16*)(0x0083a718 + i * 4) == -1)
        {
            memset(PTR8(0x0083a718 + i * 4), 0, 4);
            *(s16*)(0x0083a718 + i * 4) = value;
            FUN_0017c350();
            return true;
        }
    }
    return false;
}

// FUN_0017c590 NONMATCHING
void FUN_0017c590(s16 value)
{
    s32 i;
    for (i = 0; i < 3; i++) if (*(s16*)(0x0083a718 + i * 4) == value) *(s16*)(0x0083a718 + i * 4) = -1;
    FUN_0017c350();
}

// FUN_0017c610 NONMATCHING
s16* FUN_0017c610(s16 value)
{
    s32 i;
    for (i = 0; i < 3; i++) if (*(s16*)(0x0083a718 + i * 4) == value) return (s16*)(0x0083a718 + i * 4);
    return NULL;
}

// FUN_0017c670 NONMATCHING
s16* FUN_0017c670(s32 index)
{
    if (*(s16*)(0x0083a718 + index * 4) == -1) return NULL;
    return (s16*)(0x0083a718 + index * 4);
}

// FUN_0017c700 NONMATCHING
s32 FUN_0017c700(void)
{
    s32 i;
    s32 count = 0;
    for (i = 0; i < 3; i++) if (*(s16*)(0x0083a718 + i * 4) != -1) count++;
    return count;
}

// FUN_0017c750 NONMATCHING
void FUN_0017c750(u64 value)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        s16* entry = (s16*)(0x0083a718 + i * 4);
        if (*entry != -1 && FUN_00403920(*entry, value) != 0 && entry[1] < 0x7d01) entry[1]++;
    }
}

// FUN_0017c7f0 NONMATCHING
void FUN_0017c7f0(s32 index, u8 value)
{
    if (index < 0 || index > 7) FUN_0019d3f0(0x5e3098, 0x180f);
    PTR8(0x0083a728)[index] = value;
}

// FUN_0017c860 NONMATCHING
u8 FUN_0017c860(s32 index)
{
    if (index < 0 || index > 7) FUN_0019d3f0(0x5e3098, 0x1814);
    return PTR8(0x0083a728)[index];
}

// FUN_0017c960 NONMATCHING
void FUN_0017c960(const void* record)
{
    u16 id;
    if (record == NULL) FUN_0019d3f0(0x5e3098, 0x182b);
    id = *(const u16*)((const u8*)record + 2);
    if (id > 0xff) FUN_0019d3f0(0x5e3098, 0x182c);
    memcpy(compendium_record(id), record, 0x34);
}

// FUN_0017ca10 NONMATCHING
s32 FUN_0017ca10(const void* record)
{
    const u8* source = (const u8*)record;
    const u8* stored;
    u16 id;
    if (record == NULL) FUN_0019d3f0(0x5e3098, 0x1837);
    id = *(const u16*)(source + 2);
    if (id > 0xff) FUN_0019d3f0(0x5e3098, 0x1838);
    stored = compendium_record(id);
    if ((*(const u16*)stored & 1) == 0) return -1;
    if (*(const u16*)stored != *(const u16*)source) return 1;
    if (stored[4] != source[4]) return 1;
    if (*(const u32*)(stored + 8) != *(const u32*)(source + 8)) return 1;
    if (memcmp(stored + 0xc, source + 0xc, 0x10) != 0) return 1;
    if (memcmp(stored + 0x1c, source + 0x1c, 5) != 0) return 1;
    if (memcmp(stored + 0x21, source + 0x21, 5) != 0) return 1;
    if (memcmp(stored + 0x26, source + 0x26, 5) != 0) return 1;
    return 0;
}

// FUN_0017cd30 NONMATCHING
void* FUN_0017cd30(void* record)
{
    u8* source = (u8*)record;
    u16 id;
    u8* definition;
    if (record == NULL) FUN_0019d3f0(0x5e3098, 0x1861);
    id = *(u16*)(source + 2);
    if (id > 0xff) FUN_0019d3f0(0x5e3098, 0x1862);
    definition = PTRP(0x007ce420) + id * 0xe;
    if ((*(u16*)definition & 8) == 0 && (*(u16*)definition & 0x20) == 0)
    {
        if ((U16(0x00836e1c + id * 0x34) & 1) == 0)
        {
            FUN_0017c960(record);
            return NULL;
        }
        return compendium_record(id);
    }
    return record;
}

// FUN_0017cf00 NONMATCHING
s32 FUN_0017cf00(void)
{
    s32 valid = 0;
    s32 eligible = 0;
    s32 i;
    for (i = 0; i < 0x100; i++) if (U16(0x00836e1c + i * 0x34) & 1) valid++;
    for (i = 0; i < 0x100; i++)
    {
        u16 flags = *(u16*)(PTRP(0x007ce420) + i * 0xe);
        if ((flags & 8) == 0 && (flags & 0x20) == 0) eligible++;
    }
    return eligible == 0 ? 0 : valid * 100 / eligible;
}

// FUN_0017d030
u32 FUN_0017d030(void)
{
    return U32(0x0083a730);
}

// FUN_0017d040 NONMATCHING
void FUN_0017d040(void)
{
    U32(0x0083a730)++;
}

// FUN_0017d060 NONMATCHING
PairCounter* FUN_0017d060(u32 key, s16 id, s16 value)
{
    PairCounter* entries = pair_counters();
    s32 i;
    PairCounter* freeEntry = NULL;
    for (i = 0; i < 0x20; i++)
    {
        if (entries[i].key == (s16)key && entries[i].id == id)
        {
            if (entries[i].keyHigh != (s16)(key >> 16))
            {
                entries[i].key = (s16)key;
                entries[i].keyHigh = (s16)(key >> 16);
                entries[i].remaining = value;
            }
            return &entries[i];
        }
        if (freeEntry == NULL && entries[i].id == 0) freeEntry = &entries[i];
    }
    if (freeEntry == NULL)
    {
        FUN_0019d3f0(0x5e3098, 0x18c5);
        return NULL;
    }
    freeEntry->key = (s16)key;
    freeEntry->keyHigh = (s16)(key >> 16);
    freeEntry->id = id;
    freeEntry->remaining = value;
    return freeEntry;
}

// FUN_0017d1a0 NONMATCHING
u32 FUN_0017d1a0(s16 key, s16 id, s16 amount)
{
    s32 i;
    PairCounter* entries = pair_counters();
    for (i = 0; i < 0x20; i++)
    {
        if (entries[i].key == key && entries[i].id == id)
        {
            s16 remaining = entries[i].remaining - amount;
            if (remaining < 0) remaining = 0;
            entries[i].remaining = remaining;
            return (u16)remaining;
        }
    }
    return 0xffffffff;
}

// FUN_0017d250 NONMATCHING
u32 FUN_0017d250(s16 key, s16 id)
{
    s32 i;
    PairCounter* entries = pair_counters();
    for (i = 0; i < 0x20; i++) if (entries[i].key == key && entries[i].id == id) return (u16)entries[i].remaining;
    return 0xffffffff;
}

// FUN_0017d2e0 NONMATCHING
u8 FUN_0017d2e0(u64 id)
{
    u8* values = PTR8(0x005e38a0);
    s16 index = FUN_003082f0(0, id);
    if (index < 0)
    {
        if (*(u8*)(PTRP(0x007ce3f4) + ((u16)id & 0xffff) * 2 + 1) == 2) return 0xc;
        return values[0];
    }
    return values[index < 0x13 ? index : 0];
}

// FUN_0017d3c0 NONMATCHING
void FUN_0017d3c0(void)
{
    s32 i;
    for (i = 0; i < 9; i++) memcpy(PTR8(0x0083a834 + i * 0x10), PTR8(0x005e38c0), 0x10);
}

// FUN_0017d450 NONMATCHING
u32 FUN_0017d450(s32 index, const void* date)
{
    u8* current;
    u8 newer;
    if (date == NULL) FUN_0019d3f0(0x5e3098, 0x1933);
    if (index >= 5) return 0;
    current = PTR8(0x0083a834 + index * 0x10);
    if (index == 3) return 0;
    if (index == 4) return current[1] < ((const u8*)date)[1];
    newer = current[0] < ((const u8*)date)[0];
    if (!newer && current[0] == ((const u8*)date)[0])
    {
        newer = current[1] < ((const u8*)date)[1];
        if (!newer && current[1] == ((const u8*)date)[1])
        {
            newer = *(const s16*)(current + 2) != *(const s16*)((const u8*)date + 2);
            if (!newer) newer = *(const u32*)(current + 4) != *(const u32*)((const u8*)date + 4);
        }
    }
    if (newer)
    {
        if (FUN_003f33d0(index, 4) != 0) return 1;
        memcpy(PTR8(0x0083a834 + (index * 2 + 1) * 8), current, 8);
        memcpy(current, date, 8);
    }
    return 0;
}

// FUN_0017d610 NONMATCHING
u32 FUN_0017d610(s32 index)
{
    u8 date[8];
    if (index >= 5) return 0;
    FUN_003eff00(index, date);
    if (FUN_0017d450(index, date) == 0) return 0;
    memcpy(PTR8(0x0083a834 + (index * 2 + 1) * 8), PTR8(0x0083a834 + index * 0x10), 8);
    memcpy(PTR8(0x0083a834 + index * 0x10), date, 8);
    return 1;
}

// FUN_0017d700 NONMATCHING
void FUN_0017d700(s32 index, s32 slot, const void* date)
{
    if (date == NULL) FUN_0019d3f0(0x5e3098, 0x197f);
    memcpy(PTR8(0x0083a834 + (index * 2 + slot) * 8), date, 8);
}

// FUN_0017d7b0
u32 FUN_0017d7b0(void)
{
    return U32(0x0083aa98);
}

// FUN_0017d7c0 NONMATCHING
void FUN_0017d7c0(u32 value)
{
    U32(0x0083aa98) = value > 99 ? 99 : value;
}

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
