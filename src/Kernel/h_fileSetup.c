#include "Kernel/h_malloc.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

extern const u32 D_005E4D80[];







extern s32 func_0050d3a0(void);
extern void func_0050d3f0(void);
extern void kwlnTaskPrintTrees(void);

#define H_FREE_ERROR ((HFreeCallback*)0x0096017c)

HHeapAlloc* gHeapAllocs; // 007ce04c
u32 gHeapEnd;            // 007ce048
u32 gHeapAllocCount;     // 007ce044
u32 gHeapCursor;         // 007ce040



typedef void* (*HmallocAllocator)(u32, u32, u32);
typedef void (*HmallocReleaser)(void*);
typedef s32 (*HmallocStepCallback)(void);

extern u8 D_00846F00[];
extern u32 D_00960184[];
extern u32 jtbl_0096017C[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u8 jtbl_0096017C_abs[];
extern const char D_005E4C80[];
extern const char D_005E4C60[];
extern const char D_005E4CA0[];
extern const char D_005E4CC0[];
extern u8 D_0083BB30[];
#pragma alias D_0083BB30_abs D_0083BB30
extern u8 D_0083BB30_abs[];
extern u8 D_0083AB30[];
#pragma alias D_0083AB30_abs D_0083AB30
extern u8 D_0083AB30_abs[];
extern const char D_005E4CE0[];
extern const f32 D_005E4D00;
extern const f32 D_005E4D04;
extern const f32 D_005E4D08;
extern const f32 D_005E4D0C;
extern const f32 D_005E4D20;
extern const f32 D_005E4D24;
extern const f32 D_005E4D28;
extern const f32 D_005E4D2C;
extern const char D_005E4D10[];
extern const char D_005E4D30[];
extern const char D_005E4D60[];
extern const char D_005E4E20[];
extern const char D_005E4E38[];
extern const char D_005E4E48[];
extern const char D_005E4E58[];
extern const char D_005E4E70[];
extern const u16 D_007E094E;
extern const u16 D_007E0952;
#define HMALLOC_ENGINE_ALLOC(count, size, flags) \
    (*(HmallocAllocator*)D_00960184_abs)((count), (size), (flags))
#define HMALLOC_ENGINE_FREE(memory) \
    (*(HmallocReleaser*)jtbl_0096017C_abs)((memory))
#define HMALLOC_STEP_TABLE ((HmallocStepCallback*)0x005e4d00)
#define HMALLOC_GLOBAL_FLOAT_VALUES ((const f32*)0x007cc0d8)
#define HMALLOC_GLOBAL_IMAGE_VALUES ((const f32*)0x007cc0e0)

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

extern void func_00104d10(u64 matrix, const f32* values, u32 value);
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

static void hmallocInitTilePacket(u32 texture, u32 packet, u32 source, s32 a3,
                                   s32 a4, s32 a5, s32 a6, s32 a7, s32 a8,
                                   s32 a9, s32 a10);
static void hmallocInitTilePacket32(u32 texture, void* packet, u32 source,
                                    s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                                    s32 a8, s32 a9);
static void hmallocEmitCommands(u32 texture, u32 packet, u32 source, s32 a3,
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



static void hmallocInitTilePacket32(u32 texture, void* packet, u32 source,
                                    s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                                    s32 a8, s32 a9)
{
    hmallocInitTilePacket(texture, (u32)(uintptr_t)packet, source,
                          a3, a4, a5, a6, a7, a8, a9, 0);
}














// FUN_001927B0
static s32 hmallocTaskUpdateC(void* task)
{
    u32* work;
    HmallocStepCallback callbacks[4];
    f32 callback0;
    f32 callback1;
    f32 callback2;
    f32 callback3;

    work = *(u32**)((u8*)task + 0x3c);
    callback0 = D_005E4D00;
    callback1 = D_005E4D04;
    callback2 = D_005E4D08;
    callback3 = D_005E4D0C;
    __asm__ ("" : : "f"(callback0), "f"(callback1), "f"(callback2), "f"(callback3) : "memory");
    ((f32*)callbacks)[0] = callback0;
    ((f32*)callbacks)[1] = callback1;
    ((f32*)callbacks)[2] = callback2;
    ((f32*)callbacks)[3] = callback3;
    switch (work[0])
    {
        case 0:
            if (callbacks[work[1]] == NULL)
            {
                return -1;
            }
            work[2] = (u32)callbacks[work[1]]();
            work[0] += 1;
            break;
        case 1:
            if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
            {
                work[1] += 1;
                work[0] = 0;
            }
            break;
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

// FUN_00192980
static s32 hmallocTaskUpdateD(void* task)
{
    u32* work;
    HmallocStepCallback callbacks[4];
    f32 callback0;
    f32 callback1;
    f32 callback2;
    f32 callback3;

    work = *(u32**)((u8*)task + 0x3c);
    callback0 = D_005E4D20;
    callback1 = D_005E4D24;
    callback2 = D_005E4D28;
    callback3 = D_005E4D2C;
    __asm__ ("" : : "f"(callback0), "f"(callback1), "f"(callback2), "f"(callback3) : "memory");
    ((f32*)callbacks)[0] = callback0;
    ((f32*)callbacks)[1] = callback1;
    ((f32*)callbacks)[2] = callback2;
    ((f32*)callbacks)[3] = callback3;
    switch (work[0])
    {
        case 0:
            if (callbacks[work[1]] == NULL)
            {
                return -1;
            }
            work[2] = (u32)callbacks[work[1]]();
            work[0] += 1;
            break;
        case 1:
            if (kwlnTaskGetState((void*)(uintptr_t)work[2]) == 3)
            {
                work[1] += 1;
                work[0] = 0;
            }
            break;
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
    f32 value0;
    f32 value1;
    union
    {
        f32 f;
        u32 u;
    } values[4];
    void* workMemory;
    void* created;

    work = *(u32**)((u8*)task + 0x3c);
    state = work[0];
    switch (state)
    {
        case 0:
            work[0] = 1;
            break;
        case 1:
            value0 = HMALLOC_GLOBAL_FLOAT_VALUES[0];
            value1 = HMALLOC_GLOBAL_FLOAT_VALUES[1];
            values[0].f = value0;
            values[1].f = value1;
            if ((D_007E094E & 0x40) != 0)
            {
                switch (work[1])
                {
                    case 0:
                        workMemory = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
                        if (workMemory == NULL)
                        {
                            created = NULL;
                        }
                        else
                        {
                            created = kwlnTaskCreateWithAutoPriority(
                                NULL, 0x106f, D_005E4D10,
                                (KwlnTaskUpdateFunc)hmallocTaskUpdateC,
                                (KwlnTaskDestroyFunc)hmallocTaskDestroyC, workMemory);
                            if (created != NULL)
                            {
                                func_0017d7f0(0);
                            }
                        }
                        work[2] = (u32)(uintptr_t)created;
                        break;
                    default:
                        workMemory = HMALLOC_ENGINE_ALLOC(1, 0xc, 0x40000);
                        if (workMemory == NULL)
                        {
                            created = NULL;
                        }
                        else
                        {
                            created = kwlnTaskCreateWithAutoPriority(
                                NULL, 0x106f, D_005E4D30,
                                (KwlnTaskUpdateFunc)hmallocTaskUpdateD,
                                (KwlnTaskDestroyFunc)hmallocTaskDestroyD, workMemory);
                            if (created != NULL)
                            {
                                func_0017d7f0(1);
                            }
                        }
                        work[2] = (u32)(uintptr_t)created;
                        break;
                }
                work[0] = 2;
            }
            else
            {
                u32 flags = D_007E0952;
                if ((flags & 0x1000) != 0)
                {
                    work[1] = work[1] + 1;
                    work[1] &= 1;
                }
                else if ((flags & 0x4000) != 0)
                {
                    work[1] = work[1] + 1;
                    work[1] &= 1;
                }
            }
            values[2].u = 0x40800000;
            values[3].u = 0x40800000;
            func_00104d10(*(u64*)&values[2], HMALLOC_GLOBAL_IMAGE_VALUES,
                          values[work[1]].u);
            break;
        case 2:
            if (kwlnTaskGetState((void*)(uintptr_t)work[2]) != 3)
                break;
            return -1;
    }
    return 0;
}

// FUN_00192DB0
static void hmallocTaskDestroyE(void* task)
{
    HMALLOC_ENGINE_FREE(*(void**)((u8*)task + 0x3c));
}

// FUN_00192DE0
void* hmallocCreateTaskE(void)
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

// FUN_00192E70 NONMATCHING
static void hmallocApplyInputTable(void)
{
    u32 copied[0x28];
    u8 entry[0x34];
    u32 value;
    s32 word;
    s32 bit;
    s32 i;
    s32 j;
    u16* records;
    void* resourceA;
    const u32* config;
    u32* dst;
    u32* bitWord;
    s32 copyCount;
    u32 first;
    u32 second;

    config = D_005E4D80;
    dst = copied;
    copyCount = 0x14;
    do
    {
        first = config[0];
        second = config[1];
        config += 2;
        copyCount--;
        dst[0] = first;
        dst[1] = second;
        dst += 2;
    } while (copyCount > 0);
    resourceA = sHmallocResourceA;
    func_0016cfe0(1, *(s16*)((u8*)resourceA + 0x3c));
    func_0016d090(1, *(s16*)((u8*)resourceA + 0x3e));
    func_0016d160(1, *(s16*)((u8*)resourceA + 0x40));

    for (i = 0; i < 0x100; i++)
    {
        value = copied[i];
        if (value == 0)
            break;
        word = (s32)value >> 5;
        if ((s32)value < 0)
            word = ((s32)value + 0x1f) >> 5;
        bitWord = (u32*)sHmallocResourceC + word;
        bit = value & 0x1f;
        if ((s32)value < 0 && bit != 0)
            bit -= 0x20;
        func_0016f1f0(value,
                      ((1u << bit) & *bitWord) != 0);
    }

    records = (u16*)sHmallocResourceB;
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
    HmallocAllocator allocator;
    u32 state;
    work = *(u32**)((u8*)task + 0x3c);
    state = work[0];
    allocator = (HmallocAllocator)(uintptr_t)D_00960184_abs;
    if (state == 3)
    {
        goto stateThree;
    }
    if (state == 1)
    {
        goto stateOne;
    }
    if (state == 0)
    {
        goto stateZero;
    }
    goto done;

stateZero:
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
    sHmallocResourceA = (*allocator)(1, 0x50, 0x40000);
    sHmallocResourceB = (*allocator)(1, 0x3400, 0x40000);
    sHmallocResourceC = (*allocator)(1, 0x2c0, 0x40000);
    sHmallocResourceD = (*allocator)(1, 0x2c, 0x40000);
    sHmallocResourceMode = 0;
    sHmallocResourceReady = 1;
    work[2] = (u32)(uintptr_t)func_00420340(task, 0);
    work[0] = 1;
    goto done;

stateOne:
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
    goto done;

stateThree:
    return -1;

done:
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

// FUN_001934F0
static s32 hmallocTaskUpdateG(void* task)
{
    u32* work;
    s32 status;
    s32 file;
    s32 i;

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

        case 2:
            break;

        case 3:
        {
            u8 entryB[272];
            u8 entryA[64];
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
                        file = func_00509ed0(D_005E4E38);
                        if (file >= 0)
                        {
                            work[1] = 0;
                            for (i = 0; i < 0x14; i++)
                            {
                                if (func_0050a100(file, entryA) > 0)
                                {
                                    work[1] += 1;
                                    if (func_00524128(D_005E4E48,
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
                            func_004215b0(work[0x507], 0x18);
                            work[0] = 4;
                        }
                        else
                        {
                            func_004215b0(work[0x507], 0x1a);
                        }
                    }
                    else if (status == 5 || status == 0x10 ||
                             status == 0x11 || status == 0x12 ||
                             status == 0x13 || (u32)(status - 0xfd) < 3)
                    {
                        func_004215b0(work[0x507], 0x1a);
                        work[6] = 0;
                    }
                }
            }
            break;
        }

        case 4:
            work[0] = 5;
            work[5] = 0;
            work[4] = 0;
            break;

        case 5:
        {
            u8 entryB[272];
            u8 entryA[64];
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
                    file = func_00509ed0(D_005E4E38);
                    if (file >= 0)
                    {
                        work[1] = 0;
                        for (i = 0; i < 0x14; i++)
                        {
                            if (func_0050a100(file, entryA) > 0)
                            {
                                work[1] += 1;
                                if (func_00524128(D_005E4E58,
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
                         status == 0x13 || (u32)(status - 0xfd) < 3)
                {
                    func_004215b0(work[0x507], 0x1b);
                    work[6] = 0;
                }
            }
            break;
        }
    }
    return 0;
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
