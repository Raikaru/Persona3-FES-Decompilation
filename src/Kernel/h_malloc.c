#include "Kernel/h_malloc.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

extern s32 func_0050d3a0(void);
extern void func_0050d3f0(void);
extern void kwlnTaskPrintTrees(void);

#define H_FREE_ERROR ((HFreeCallback*)0x0096017c)

HHeapAlloc* gHeapAllocs; // 007ce04c
u32 gHeapEnd;            // 007ce048
u32 gHeapAllocCount;     // 007ce044
u32 gHeapCursor;         // 007ce040

// FUN_00191a10
void H_Free(void* memory)
{
    HHeapAlloc* allocs;
    u32 i;
    u32 count;
    HHeapAlloc* alloc;
    s32 intr;

    if ((u32)memory < (u32)gHeapAllocs)
    {
        (*H_FREE_ERROR)(memory);
    }
    else if (gHeapEnd < (u32)memory)
    {
        (*H_FREE_ERROR)(memory);
    }
    else
    {
        intr = func_0050d3a0();
        allocs = gHeapAllocs;
        i = 0;
        count = gHeapAllocCount;

        goto check;

    loop:
        alloc = &allocs[i];
        if (memory == alloc->memory)
        {
            alloc->memory = NULL;
            alloc->size = 0;
            goto done;
        }

        i++;

    check:
        if (i < count)
        {
            goto loop;
        }

    done:
        if (intr != 0)
        {
            func_0050d3f0();
        }
    }
}

// FUN_00191af0 NONMATCHING
void* H_Malloc(size_t size)
{
    s32 intr;
    u32 alignedSize;
    u32 heapCursor;
    u32 allocEnd;
    u32 newAllocEnd;
    u32 i;
    u32 count;
    HHeapAlloc* allocs;
    HHeapAlloc* alloc;

    intr = func_0050d3a0();
    alignedSize = (size + 0xf) & ~0xf;
    heapCursor = (u32)(gHeapAllocs + gHeapAllocCount);

retry:
    allocs = gHeapAllocs;
    newAllocEnd = heapCursor + alignedSize;
    count = gHeapAllocCount;

    for (i = 0; i < count; i++)
    {
        alloc = &allocs[i];
        if (alloc->size != 0)
        {
            allocEnd = (u32)alloc->memory + alloc->size;
            if (heapCursor == (u32)alloc->memory)
            {
                goto overlap;
            }

            if ((u32)alloc->memory < heapCursor)
            {
                if (heapCursor < allocEnd)
                {
                    goto overlap;
                }
            }
            else
            {
                if (allocEnd < newAllocEnd)
                {
                    goto overlap;
                }

                if ((u32)alloc->memory < newAllocEnd)
                {
                    goto overlap;
                }
            }
        }
    }

    allocEnd = heapCursor;

overlap:
    if (allocEnd != heapCursor)
    {
        goto advanceHeap;
    }

    for (i = 0; i < count; i++)
    {
        alloc = &allocs[i];
        if (alloc->size == 0)
        {
            alloc->memory = (void*)allocEnd;
            alloc->size = alignedSize;
            goto allocated;
        }
    }

    printf("malloc error\n");
    K_Assert("h_malloc.c", 157);

allocated:
    if (intr != 0)
    {
        func_0050d3f0();
    }

    if (allocEnd + alignedSize >= gHeapEnd)
    {
        printf("malloc error\n");
        K_Assert("h_malloc.c", 213);
    }

    return (void*)allocEnd;

advanceHeap:
    heapCursor = allocEnd;
    if (heapCursor + alignedSize < gHeapEnd)
    {
        goto retry;
    }

    kwlnTaskPrintTrees();
    printf("malloc error\n");
    K_Assert("h_malloc.c", 227);
    goto retry;
}

// FUN_00191d10
void* H_Calloc(u32 count, size_t size)
{
    void* memory;

    memory = H_Malloc(size * count);
    memset(memory, 0, size * count);

    return memory;
}

// FUN_001919c0. Initialize the retail heap allocation table.
void H_Malloc_Init(void* table, u32 size)
{
    u32 i;
    HHeapAlloc* entries;

    gHeapAllocs = (HHeapAlloc*)table;
    gHeapEnd = (u32)table + size;
    gHeapAllocCount = 500;
    entries = (HHeapAlloc*)table;
    for (i = 0; i < gHeapAllocCount; i++)
    {
        entries[i].memory = NULL;
        entries[i].size = 0;
    }
    gHeapCursor = 0;
}
typedef void* (*HmallocAllocator)(u32, u32, u32);
typedef void (*HmallocReleaser)(void*);
typedef s32 (*HmallocStepCallback)(void);

extern u32 D_00960184[];
extern u32 jtbl_0096017C[];
extern const char D_005E4C80[];
extern const char D_005E4C60[];
extern u8 D_0083BB30[];
extern const char D_005E4CE0[];
extern const char D_005E4D10[];
extern const char D_005E4D30[];
extern const char D_005E4D60[];
extern const char D_005E4E20[];
extern const char D_005E4E70[];
#define HMALLOC_ENGINE_ALLOC(count, size, flags) \
    (*(HmallocAllocator*)D_00960184)((count), (size), (flags))
#define HMALLOC_ENGINE_FREE(memory) \
    (*(HmallocReleaser*)jtbl_0096017C)((memory))
#define HMALLOC_STEP_TABLE ((HmallocStepCallback*)0x005e4d00)

extern void func_004f1e20(u64 source, void* bytes, u16* header);
extern void func_004d5000(void* packet, u32 size);
extern void func_0016cfe0(s32 group, s32 value);
extern void func_0016d090(s32 group, s32 value);
extern void func_0016d160(s32 group, s32 value);
extern void func_0016f1f0(u32 id, s32 enabled);
extern void func_00521408(void* dst, u32 value, u32 size);
extern void func_00176680(void* dst, u16 id);
extern void func_0017cd30(void* entry);
extern s32 func_001016b0(void* resource);
extern void func_00521250(void* allocator, u32 width, u32 height);
extern void func_0016c2f0(void);
extern void* func_00100d80(void* descriptor, s32 flags);
extern void func_0017d7f0(s32 mode);

static u32 sHmallocInputWords[0x100];
static u32 sHmallocInputBits[0x20];
static u8 sHmallocInputRecords[0x34 * 0x100];
static void* sHmallocResourceA;
static void* sHmallocResourceB;
static void* sHmallocResourceC;
static void* sHmallocResourceD;
static u32 sHmallocResourceReady;
static u32 sHmallocResourceMode;
static u32 sHmallocResourceFlag;
static void* sHmallocControllerTask;

extern void func_00104d10(u64 matrix, const f32* values, f32 value);
extern u32 func_004214e0(void* task, s32 mode);
extern void func_004215b0(u32 handle, u32 command);
extern void func_00421650(u32 handle);
extern s32 func_00510e30(void);
extern s32 func_00509ed0(const char* path);
extern s32 func_0050a100(s32 file, void* entry);
extern void func_00509f98(s32 file);
extern s32 func_00524128(const char* path, const char* name);
extern s32 func_00420340(void* task, s32 flags);
extern void func_0035f060();

static void hmallocInitTilePacket(u64 texture, u64 packet, u64 source, s32 a3,
                                   s32 a4, s32 a5, s32 a6, s32 a7, s32 a8,
                                   s32 a9, s32 a10);
static void hmallocEmitCommands(u64 texture, u64 packet, u64 source, s32 a3,
                                 s32 a4, s32 a5, s32 a6, s32 a7, s32 a8,
                                 s32 a9, s32 a10);
static void hmallocPackHeader(u64* out, u32 a1, s32 a2, u32 a3, u32 a4,
                              u32 a5, u32 a6);
static void hmallocPackDescriptor(u32* out, u64 address, s32 a2, s32 a3,
                                  s32 a4, s32 a5, s32 a6, u32 a7);
static void hmallocWriteImage(u32* out, u32 image, u32 a2, u32 a3);
static void hmallocWriteTile(u32* out, u32 a1, u32 image, u32 a3);
static void hmallocWriteScale(u32* out, u32 x, u32 y);
static void hmallocWriteSolid(u32* out, u32 value);

// FUN_00191D70 NONMATCHING
void hmallocPrepareTilePacket(u64 source, u64 owner, s32 tileIndex, s32 tileCount)
{
    u16 header[2];
    u8 headerBytes[4];

    func_004f1e20(source, headerBytes, header);
    if ((u32)(tileCount * 0x10) < 0x1c1)
    {
        hmallocInitTilePacket(header[0] & 0x3fff, (u64)0x846f00, owner,
                              0, 0, tileIndex << 4, tileCount * 0x10,
                              0, 0, 0, 0);
    }
    else
    {
        hmallocInitTilePacket(header[0] & 0x3fff, (u64)0x846f00, owner,
                              0, 0, tileIndex << 4, 0x1c0,
                              0, 0, 0, 0);
    }
    func_004d5000((void*)0x846f00, 0x102);
}

// FUN_00191E60
static void hmallocInitTilePacket(u64 texture, u64 packet, u64 source, s32 a3,
                                   s32 a4, s32 a5, s32 a6, s32 a7, s32 a8,
                                   s32 a9, s32 a10)
{
    hmallocEmitCommands(texture, packet, source, 0x400, a3, a4, a5, a6,
                         a7, a8, a9);
}

// FUN_00191EC0 NONMATCHING
static void hmallocEmitCommands(u64 texture, u64 packet, u64 source, s32 a3,
                                 s32 a4, s32 a5, s32 a6, s32 a7, s32 a8,
                                 s32 a9, s32 a10)
{
    u8* command;
    s32 rowCount;
    s32 i;
    s32 stride;
    u32 imageOffset;
    s32 blockCount;

    command = (u8*)(uintptr_t)packet;
    a7 >>= 4;
    hmallocPackHeader((u64*)command, 0, 0, 0, 1, 0, 3);
    hmallocPackDescriptor((u32*)(command + 0x10), 0xe, 1, 0, 0, 0, 0, 2);

    rowCount = a6 + 0x3f;
    if (rowCount < 0)
    {
        rowCount = a6 + 0x7e;
    }
    rowCount = (rowCount >> 6) * 0x40;
    hmallocWriteImage((u32*)(command + 0x20), (u32)texture,
                      (s64)((a6 + 0x3f) >> 6), 0);
    hmallocWriteScale((u32*)(command + 0x30), 0x10, (u32)(a7 << 4));

    command += 0x40;
    imageOffset = (u32)source + (u32)(a8 >> 4) * (u32)a3 *
                  (u32)(a7 + (u32)(a10 >> 4)) + (u32)a3 * (u32)(a9 >> 4);
    blockCount = a6 * 0x400;
    if (blockCount < 0)
    {
        blockCount += 0xf;
    }
    stride = blockCount >> 4;
    for (i = 0; i < (a6 >> 4); i++)
    {
        hmallocPackHeader((u64*)command, 0, 0, 0, 1, 0, 4);
        hmallocPackDescriptor((u32*)(command + 0x10), 0xe, 1, 0, 0, 0,
                              0, 2);
        hmallocWriteTile((u32*)(command + 0x20), 0,
                         (u32)(a4 + i * 0x10), (s64)a5);
        hmallocWriteSolid((u32*)(command + 0x30), 0);
        hmallocPackDescriptor((u32*)(command + 0x40), 0, 0, 2, 0, 0,
                              i == ((a6 >> 4) - 1), (u32)stride);
        hmallocPackHeader((u64*)(command + 0x50), 0,
                          imageOffset & 0x0fffffff, 0, 3, 0,
                          (u64)stride);
        command += 0x60;
        imageOffset += (u32)a3 * (u32)a7 + (u32)a3 * (u32)(a10 >> 4);
    }
    hmallocPackHeader((u64*)command, 0, 0, 0, 0, 7, 0);
}

// FUN_00192160
static void hmallocPackHeader(u64* out, u32 a1, s32 a2, u32 a3, u32 a4,
                              u32 a5, u32 a6)
{
    u64 packet;

    packet = ((u64)a1 << 0x3f) |
             ((u64)(u32)(a2 & ~0xf) << 0x20) |
             ((u64)a3 << 0x1f) |
             ((u64)a4 << 0x1c) |
             ((u64)a5 << 0x1a) |
             (u64)a6;
    *out = packet;
}

// FUN_001921D0
static void hmallocPackDescriptor(u32* out, u64 address, s32 a2, s32 a3,
                                   s32 a4, s32 a5, s32 a6, u32 a7)
{
    out[0] = ((u32)a6 << 0xf) | a7;
    out[1] = ((u32)a5 << 0xe) | ((u32)a4 << 0xf) |
             ((u32)a3 << 0x1a) | ((u32)a2 << 0x1c);
    out[2] = (u32)(address & 0xffffffffULL);
    out[3] = (u32)(address >> 0x20);
}

// FUN_00192230
static void hmallocWriteImage(u32* out, u32 image, u32 a2, u32 a3)
{
    u64 value;

    value = ((u64)a3 << 0x38) | ((u64)a2 << 0x30) |
            ((u64)image << 0x20);
    out[0] = (u32)(value & 0xffffffffULL);
    out[1] = (u32)(value >> 0x20);
    out[2] = 0x50;
    out[3] = 0;
}

// FUN_001922A0
static void hmallocWriteTile(u32* out, u32 a1, u32 image, u32 a3)
{
    u64 value;

    value = ((u64)a1 << 0x3b) | ((u64)a3 << 0x30) |
            ((u64)image << 0x20);
    out[0] = (u32)(value & 0xffffffffULL);
    out[1] = (u32)(value >> 0x20);
    out[2] = 0x51;
    out[3] = 0;
}

// FUN_00192310
static void hmallocWriteScale(u32* out, u32 x, u32 y)
{
    u64 value;
    value = ((u64)y << 0x20) | x;
    out[0] = (u32)(value & 0xffffffffULL);
    out[1] = (u32)(value >> 0x20);
    out[2] = 0x52;
    out[3] = 0;
}

// FUN_00192370
static void hmallocWriteSolid(u32* out, u32 value)
{
    u64 packet;
    packet = value;
    out[0] = (u32)(packet & 0xffffffffULL);
    out[1] = 0;
    out[2] = 0x53;
    out[3] = 0;
}

// FUN_001923B0 NONMATCHING
static s32 hmallocTaskUpdateA(void* task)
{
    u32* work;
    void* destination;
    HCdvd* resource;

    work = *(u32**)((u8*)task + 0x3c);
    switch (work[0])
    {
        case 0:
            work[1] = (u32)(uintptr_t)func_00100d80((void*)D_005E4C60, 0);
            work[0] += 1;
            break;
        case 1:
            if (func_001016b0((void*)(uintptr_t)work[1]) == 1)
            {
                destination = (void*)D_0083BB30;
                resource = (HCdvd*)(uintptr_t)work[1];
                func_00521250(destination,
                              (u32)(uintptr_t)resource->fileMemory,
                              resource->fileSize);
                H_Cdvd_Destroy((void*)(uintptr_t)work[1]);
                work[1] = 0;
                func_0016c2f0();
                return -1;
            }
            break;
    }
    return 0;
}

// FUN_00192480
static void hmallocTaskDestroyA(void* task)
{
    u32* work;

    work = *(u32**)((u8*)task + 0x3c);
    if (work[1] != 0)
    {
        H_Cdvd_Destroy((void*)(uintptr_t)work[1]);
        work[1] = 0;
    }
    HMALLOC_ENGINE_FREE(work);
}

// FUN_001924D0
static void* hmallocCreateTaskA(void* parent)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 0x106f, D_005E4C80, (KwlnTaskUpdateFunc)hmallocTaskUpdateA, (KwlnTaskDestroyFunc)hmallocTaskDestroyA, work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_00192570 NONMATCHING
static s32 hmallocTaskUpdateB(void* task)
{
    u32* work;
    u32* resourceA;
    u32* resourceB;

    work = *(u32**)((u8*)task + 0x3c);
    if (work[0] == 0)
    {
        work[1] = (u32)(uintptr_t)func_00100d80((void*)0x5e4ca0, 0);
        work[2] = (u32)(uintptr_t)func_00100d80((void*)0x5e4cc0, 0);
        work[0] += 1;
    }
    else if (work[0] == 1)
    {
        if (func_001016b0((void*)(uintptr_t)work[1]) == 1 &&
            func_001016b0((void*)(uintptr_t)work[2]) == 1)
        {
            resourceA = (u32*)(uintptr_t)work[1];
            resourceB = (u32*)(uintptr_t)work[2];
            func_00521250((void*)0x83bb30,
                          *(u32*)((u8*)resourceA + 0x110),
                          *(u32*)((u8*)resourceA + 0x118));
            func_00521250((void*)0x83ab30,
                          *(u32*)((u8*)resourceB + 0x110),
                          *(u32*)((u8*)resourceB + 0x118));
            H_Cdvd_Destroy((void*)(uintptr_t)work[1]);
            work[1] = 0;
            H_Cdvd_Destroy((void*)(uintptr_t)work[2]);
            work[2] = 0;
            func_0016c2f0();
            return -1;
        }
    }
    return 0;
}

// FUN_001926A0
static void hmallocTaskDestroyB(void* task)
{
    u32* work;

    work = *(u32**)((u8*)task + 0x3c);
    if (work[1] != 0)
    {
        H_Cdvd_Destroy((void*)(uintptr_t)work[1]);
        work[1] = 0;
    }
    if (work[2] != 0)
    {
        H_Cdvd_Destroy((void*)(uintptr_t)work[2]);
        work[2] = 0;
    }
    HMALLOC_ENGINE_FREE(work);
}

// FUN_00192710
static void* hmallocCreateTaskB(void* parent)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 0x106f, D_005E4CE0, (KwlnTaskUpdateFunc)hmallocTaskUpdateB, (KwlnTaskDestroyFunc)hmallocTaskDestroyB, work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_001927B0 NONMATCHING
static s32 hmallocTaskUpdateC(void* task)
{
    u32* work;
    HmallocStepCallback callbacks[4];

    work = *(u32**)((u8*)task + 0x3c);
    ((f32*)callbacks)[0] = ((const f32*)0x005e4d00)[0];
    ((f32*)callbacks)[1] = ((const f32*)0x005e4d00)[1];
    ((f32*)callbacks)[2] = ((const f32*)0x005e4d00)[2];
    ((f32*)callbacks)[3] = ((const f32*)0x005e4d00)[3];
    if (work[0] == 0)
    {
        if (callbacks[work[1]] == NULL)
        {
            return -1;
        }
        work[2] = (u32)callbacks[work[1]]();
        work[0] += 1;
    }
    else if (work[0] == 1)
    {
        if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
        {
            work[1] += 1;
            work[0] = 0;
        }
    }
    return 0;
}

// FUN_001928A0
static void hmallocTaskDestroyC(void* task)
{
    HMALLOC_ENGINE_FREE(*(void**)((u8*)task + 0x3c));
}

// FUN_001928D0
static void* hmallocCreateTaskC(void)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(NULL, 0x106f, D_005E4D10, (KwlnTaskUpdateFunc)hmallocTaskUpdateC, (KwlnTaskDestroyFunc)hmallocTaskDestroyC, work);
    if (task == NULL)
    {
        return NULL;
    }
    func_0017d7f0(0);
    return task;
}

// FUN_00192980 NONMATCHING
static s32 hmallocTaskUpdateD(void* task)
{
    u32* work;
    HmallocStepCallback callbacks[4];
    work = *(u32**)((u8*)task + 0x3c);
    ((f32*)callbacks)[0] = ((const f32*)0x005e4d20)[0];
    ((f32*)callbacks)[1] = ((const f32*)0x005e4d20)[1];
    ((f32*)callbacks)[2] = ((const f32*)0x005e4d20)[2];
    ((f32*)callbacks)[3] = ((const f32*)0x005e4d20)[3];
    if (work[0] == 0)
    {
        if (callbacks[work[1]] == NULL)
        {
            return -1;
        }
        work[2] = (u32)callbacks[work[1]]();
        work[0] += 1;
    }
    else if (work[0] == 1)
    {
        if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
        {
            work[1] += 1;
            work[0] = 0;
        }
    }
    return 0;
}

// FUN_00192A70
static void hmallocTaskDestroyD(void* task)
{
    HMALLOC_ENGINE_FREE(*(void**)((u8*)task + 0x3c));
}

// FUN_00192AA0
static void* hmallocCreateTaskD(void)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(NULL, 0x106f, D_005E4D30, (KwlnTaskUpdateFunc)hmallocTaskUpdateD, (KwlnTaskDestroyFunc)hmallocTaskDestroyD, work);
    if (task == NULL)
    {
        return NULL;
    }
    func_0017d7f0(1);
    return task;
}

// FUN_00192B50 NONMATCHING
static s32 hmallocTaskUpdateE(void* task)
{
    u32* work;
    u32 state;
    u32 flags;
    f32 values[4];
    void* created;
    void* parent;

    work = *(u32**)((u8*)task + 0x3c);
    state = work[0];
    if (state == 2)
    {
        if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
        {
            return -1;
        }
    }
    else if (state == 1)
    {
        values[0] = *(f32*)0x7e93e8;
        values[1] = *(f32*)0x7e93ec;
        if ((*(u16*)0x7e094e & 0x40) != 0)
        {
            if (work[1] == 0)
            {
                created = hmallocCreateTaskC();
            }
            else
            {
                created = hmallocCreateTaskD();
            }
            work[2] = (u32)(uintptr_t)created;
            work[0] = 2;
        }
        else
        {
            flags = *(u16*)0x7e0952;
            if ((flags & 0x1000) != 0 || (flags & 0x4000) != 0)
            {
                work[1] = (work[1] + 1) & 1;
            }
        }
        values[2] = 0x40800000;
        values[3] = 0x40800000;
        parent = (void*)0x4080000040800000ULL;
        (void)parent;
        func_00104d10((u64)0x4080000040800000ULL,
                      (const f32*)0x7e93f0, values[work[1]]);
    }
    else if (state == 0)
    {
        work[0] = 1;
    }
    return 0;
}

// FUN_00192DB0
static void hmallocTaskDestroyE(void* task)
{
    HMALLOC_ENGINE_FREE(*(void**)((u8*)task + 0x3c));
}

// FUN_00192DE0
static void* hmallocCreateTaskE(void)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(NULL, 0x106f, D_005E4D60, (KwlnTaskUpdateFunc)hmallocTaskUpdateE, (KwlnTaskDestroyFunc)hmallocTaskDestroyE, work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

#define HMALLOC_CONFIG_WORDS ((const u32*)0x005e4d80)

// FUN_00192E70 NONMATCHING
static void hmallocApplyInputTable(void)
{
    u32 copied[0x28];
    u8 entry[0x34];
    u32 value;
    u32 word;
    u32 bit;
    s32 i;
    s32 j;
    u16* records;

    for (i = 0; i < 0x14; i++)
    {
        copied[i * 2] = HMALLOC_CONFIG_WORDS[i * 2];
        copied[i * 2 + 1] = HMALLOC_CONFIG_WORDS[i * 2 + 1];
    }

    if (sHmallocResourceA != NULL)
    {
        func_0016cfe0(1, *(s16*)((u8*)sHmallocResourceA + 0x3c));
        func_0016d090(1, *(s16*)((u8*)sHmallocResourceA + 0x3e));
        func_0016d160(1, *(s16*)((u8*)sHmallocResourceA + 0x40));
    }

    for (i = 0; i < 0x100; i++)
    {
        value = copied[i];
        if (value == 0)
        {
            break;
        }
        word = value;
        if ((s32)value < 0)
        {
            word = value + 0x1f;
        }
        bit = value & 0x1f;
        if ((s32)value < 0 && bit != 0)
        {
            bit -= 0x20;
        }
        func_0016f1f0(value,
                      (1u << (bit & 0x1f) &
                       sHmallocInputBits[((s32)word) >> 5]) != 0);
    }

    records = (u16*)sHmallocResourceB;
    if (records == NULL)
    {
        return;
    }
    for (j = 0; j < 0x100; j++)
    {
        u16* record = (u16*)((u8*)records + j * 0x34);
        if ((*record & 1) != 0)
        {
            func_00521408(entry, 0, 0x34);
            func_00176680(entry, record[1]);
            *(u16*)entry |= 1;
            func_0017cd30(entry);
        }
    }
}

// FUN_00193020 NONMATCHING
static s32 hmallocTaskUpdateF(void* task)
{
    u32* work;
    u32 state;

    work = *(u32**)((u8*)task + 0x3c);
    state = work[0];
    if (state == 3)
    {
        return -1;
    }

    if (state == 1)
    {
        if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
        {
            sHmallocResourceReady = 0;
            if (sHmallocResourceMode == 0)
            {
                if (sHmallocResourceA != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceA);
                }
                if (sHmallocResourceB != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceB);
                }
                if (sHmallocResourceC != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceC);
                }
                if (sHmallocResourceD != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceD);
                }
                sHmallocResourceA = NULL;
                sHmallocResourceB = NULL;
                sHmallocResourceC = NULL;
                sHmallocResourceD = NULL;
                work[1] = (u32)-1;
                work[0] = 3;
            }
            else
            {
                work[1] = 1;
                hmallocApplyInputTable();
                sHmallocResourceMode = 0;
                if (sHmallocResourceA != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceA);
                }
                if (sHmallocResourceB != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceB);
                }
                if (sHmallocResourceC != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceC);
                }
                if (sHmallocResourceD != NULL)
                {
                    HMALLOC_ENGINE_FREE(sHmallocResourceD);
                }
                sHmallocResourceA = NULL;
                sHmallocResourceB = NULL;
                sHmallocResourceC = NULL;
                sHmallocResourceD = NULL;
                work[0] = 3;
            }
        }
    }
    else if (state == 0)
    {
        if (sHmallocResourceA != NULL)
        {
            HMALLOC_ENGINE_FREE(sHmallocResourceA);
        }
        if (sHmallocResourceB != NULL)
        {
            HMALLOC_ENGINE_FREE(sHmallocResourceB);
        }
        if (sHmallocResourceC != NULL)
        {
            HMALLOC_ENGINE_FREE(sHmallocResourceC);
        }
        if (sHmallocResourceD != NULL)
        {
            HMALLOC_ENGINE_FREE(sHmallocResourceD);
        }
        sHmallocResourceA = HMALLOC_ENGINE_ALLOC(1, 0x50, 0x40000);
        sHmallocResourceB = HMALLOC_ENGINE_ALLOC(1, 0x3400, 0x40000);
        sHmallocResourceC = HMALLOC_ENGINE_ALLOC(1, 0x2c0, 0x40000);
        sHmallocResourceD = HMALLOC_ENGINE_ALLOC(1, 0x2c, 0x40000);
        sHmallocResourceMode = 0;
        sHmallocResourceReady = 1;
        work[2] = (u32)(uintptr_t)func_00420340(task, 0);
        work[0] = 1;
    }
    return 0;
}

// FUN_00193320
static void hmallocTaskDestroyF(void* task)
{
    u32* work;

    work = *(u32**)((u8*)task + 0x3c);
    if (sHmallocResourceA != NULL)
    {
        HMALLOC_ENGINE_FREE(sHmallocResourceA);
    }
    if (sHmallocResourceB != NULL)
    {
        HMALLOC_ENGINE_FREE(sHmallocResourceB);
    }
    if (sHmallocResourceC != NULL)
    {
        HMALLOC_ENGINE_FREE(sHmallocResourceC);
    }
    if (sHmallocResourceD != NULL)
    {
        HMALLOC_ENGINE_FREE(sHmallocResourceD);
    }
    HMALLOC_ENGINE_FREE(work);
}

// FUN_001933D0
static s32 hmallocStartController(void)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
    if (work == NULL)
    {
        task = NULL;
    }
    else
    {
        task = kwlnTaskCreateWithAutoPriority(
            NULL, 0x106f, D_005E4E20,
            (KwlnTaskUpdateFunc)hmallocTaskUpdateF,
            (KwlnTaskDestroyFunc)hmallocTaskDestroyF, work);
        if (task == NULL)
        {
            task = NULL;
        }
    }
    sHmallocControllerTask = task;
    return 1;
}

// FUN_00193460
static s32 hmallocPollController(void)
{
    u32* work;
    s32 state;

    if (kwlnTaskGetState(sHmallocControllerTask) == 3)
    {
        sHmallocControllerTask = NULL;
        return 1;
    }
    work = *(u32**)((u8*)sHmallocControllerTask + 0x3c);
    state = (s32)work[1];
    if (state == 1)
    {
        func_0035f060(1);
    }
    else if (state == -1)
    {
        func_0035f060(0);
    }
    return 0;
}

// FUN_001934F0 NONMATCHING
static s32 hmallocTaskUpdateG(void* task)
{
    u32* work;
    s32 result;
    s32 status;
    s32 file;
    s32 i;
    u8 entryA[64];
    u8 entryB[272];

    work = *(u32**)((u8*)task + 0x3c);
    switch (work[0])
    {
        case 0:
            work[0x507] = func_004214e0(task, 1);
            work[0] = 1;
            work[4] = 0;
            work[5] = 0;
            break;

        case 1:
            func_004215b0(work[0x507], 0x16);
            work[0] = 3;
            work[4] = 0;
            work[6] = 0;
            break;

        case 3:
            if (work[4] == 0)
            {
                status = func_00510e30();
                if (status == 0)
                {
                    work[6] = 1;
                }
                else if (work[6] != 0)
                {
                    if (status == 0x14)
                    {
                        work[6] = 0;
                        file = func_00509ed0((const char*)0x5e4e38);
                        if (file >= 0)
                        {
                            work[1] = 0;
                            for (i = 0; i < 0x14; i++)
                            {
                                if (func_0050a100(file, entryA) > 0)
                                {
                                    work[1] += 1;
                                    if (func_00524128((const char*)0x5e4e48,
                                                      (const char*)entryB) == 0)
                                    {
                                        work[5] = 1;
                                    }
                                }
                            }
                            func_00509f98(file);
                        }
                        if (work[5] == 0)
                        {
                            func_004215b0(work[0x507], 0x1a);
                        }
                        else
                        {
                            func_004215b0(work[0x507], 0x18);
                            work[0] = 4;
                        }
                    }
                    else if (status == 5 || status == 0x10 ||
                             status == 0x11 || status == 0x12 ||
                             status == 0x13 || (status - 0xfd) < 3)
                    {
                        func_004215b0(work[0x507], 0x1a);
                        work[6] = 0;
                    }
                }
            }
            break;

        case 4:
            work[0] = 5;
            work[5] = 0;
            work[4] = 0;
            break;

        case 5:
            status = func_00510e30();
            if (status == 0)
            {
                work[6] = 1;
            }
            else if (work[6] != 0)
            {
                if (status == 0x14)
                {
                    work[6] = 0;
                    file = func_00509ed0((const char*)0x5e4e38);
                    if (file >= 0)
                    {
                        work[1] = 0;
                        for (i = 0; i < 0x14; i++)
                        {
                            if (func_0050a100(file, entryA) > 0)
                            {
                                work[1] += 1;
                                if (func_00524128((const char*)0x5e4e58,
                                                  (const char*)entryB) == 0)
                                {
                                    work[5] = 1;
                                }
                            }
                        }
                        func_00509f98(file);
                    }
                    if (work[5] != 0)
                    {
                        func_00421650(work[0x507]);
                        return -1;
                    }
                    func_004215b0(work[0x507], 0x1b);
                    work[6] = 0;
                }
                else if (status == 5 || status == 0x10 ||
                         status == 0x11 || status == 0x12 ||
                         status == 0x13 || (status - 0xfd) < 3)
                {
                    func_004215b0(work[0x507], 0x1b);
                    work[6] = 0;
                }
            }
            break;
    }
    result = 0;
    return result;
}

// FUN_001938B0
static void hmallocTaskDestroyG(void* task)
{
    HMALLOC_ENGINE_FREE(*(void**)((u8*)task + 0x3c));
}

// FUN_001938E0
static void* hmallocCreateTaskG(void* parent)
{
    void* work;
    void* task;

    work = HMALLOC_ENGINE_ALLOC(1, 0x1420, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 0x106f, D_005E4E70, (KwlnTaskUpdateFunc)hmallocTaskUpdateG, (KwlnTaskDestroyFunc)hmallocTaskDestroyG, work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}
