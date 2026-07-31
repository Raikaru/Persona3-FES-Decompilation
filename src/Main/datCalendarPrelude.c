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
extern const char D_005e3278[];
extern u8 DAT_00836e1c[];
extern u8 DAT_00836ba3[];
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
#define ALLOCATE(count, size, flags) (*(void* (**)(u32, u32, u32))(D_00960184_abs + 0x184))(count, size, flags)
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

#define SAVE_AT(base, offset, id_value, chunk_size, source) \
    do { \
        id = (id_value); \
        FUN_00521250((base) + (offset), &id, 4); \
        size = (chunk_size); \
        FUN_00521250((base) + (offset) + 4, &size, 4); \
        FUN_00521250((base) + (offset) + 8, (source), size); \
    } while (0)



 


/* Reconstructed dispatch/copy bodies from retail byte window 0x179360..0x17a430; no unjustified bytes. */



/* Removing this loses FUN_0017ad90 (MATCH nd0 -> MISMATCH nd5) - measured W161. */































/* Removing this loses FUN_0017c4e0 (MATCH nd0 -> MISMATCH nd22) - measured W161. */




/* Removing this loses FUN_0017c700 (MATCH nd0 -> MISMATCH nd21) - measured W161. */










typedef union PairKey
{
    f32 value;
    struct
    {
        u16 low;
        u16 high;
    } parts;
} PairKey;






/* W212: first divergence is the prologue (ours 0x60-byte frame, retail 0x50).
 * Replacing the addressed u8[8] with a u64 aggregate measured identically
 * (nd228, 440/448) and was reverted; FUN_0017cd30 has no comparable date cascade. */




/* Removing this loses FUN_0017d7c0 (MATCH nd0 -> MISMATCH nd12) - measured W161. */


