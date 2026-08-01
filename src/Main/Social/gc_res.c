#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "h_cdvd.h"
#include "Main/Battle/Panel/bp_tex.h"




extern int sprintf(char* buffer, const char* format, ...);
extern char* strcpy(char* destination, const char* source);
extern void func_004cde90(void* raster);

/* The GC resource task owns this private work area (DAT_007ce2fc). */
typedef struct GcResPair
{
    u32 flags;
    s32 majorId;
    s32 minorId;
    void* raster;
    u32 refs;
} GcResPair;
typedef struct GcResPairAtWork
{
    u8 reserved00[0x4c];
    u32 flags;
    s32 majorId;
    s32 minorId;
    void* raster;
    u32 refs;
} GcResPairAtWork;

typedef struct GcResPersona
{
    u32 flags;
    s16 id;
    u16 pad06;
    void* raster;
    u32 refs;
} GcResPersona;

typedef struct GcResRequest
{
    u32 flags;
    u32 state;
    void* cdvd;
    u8 reserved0c[0x104];
    u32 type;
    u32 slot;
    u8 reserved118[0xc];
} GcResRequest;

typedef struct GcResWork
{
    u32 flags;
    void* cardRaster;
    void* miscRaster;
    u32 loadedFlags;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8 reserved1c[4];
    void* cardResources[7];
    void* miscResources[2];
    u32 unk44;
    u32 pendingCount;
    GcResPair pairs[0x10];
    GcResPersona personas[0x10];
    GcResRequest requests[0x20];
} GcResWork;

static u8* sGcRes;

#define GC_U32(base, offset) (*(u32*)((u8*)(base) + (offset)))
#define GC_S16(base, offset) (*(s16*)((u8*)(base) + (offset)))
#define GC_PTR(base, offset) (*(void**)((u8*)(base) + (offset)))
#define GC_PAIR(base, index) ((u8*)(base) + 0x4c + (index) * 0x14)
#define GC_PERSONA(base, index) ((u8*)(base) + 0x18c + (index) * 0x10)
#define GC_REQUEST(base, index) ((u8*)(base) + 0x28c + (index) * 0x124)


static u8* gcResRequire(void)
{
    K_ASSERT(sGcRes != NULL, 0x7c);
    return sGcRes;
}
s32 func_0021ac90(s32 majorId, s32 minorId);
void* func_0021ad40(s32 majorId, s32 minorId);
void func_0021ae30(s32 majorId, s32 minorId);
s32 func_0021af30(void);
u32 func_0021afe0(s16 id);
void* func_0021b080(s16 id);
s32 func_0021b150(void);
void func_0021b1f0(s16 id);
void* func_0021b2d0(void);

// FUN_00219C90
void func_00219c90(void* work)
{
    GcResWork* typedWork;
    s32 i;

    K_ASSERT(sGcRes == NULL, 0x95);
    typedWork = (GcResWork*)work;
    typedWork->flags = 0;
    typedWork->unk14 = 0;
    typedWork->unk18 = 0;
    typedWork->loadedFlags = 0;
    typedWork->unk10 = 0;
    typedWork->cardRaster = NULL;
    typedWork->miscRaster = NULL;
    typedWork->unk44 = 0;
    typedWork->pendingCount = 0;
    for (i = 0; i < 0x20; i++) {
        ((GcResRequest*)GC_REQUEST(typedWork, i))->flags = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((GcResPair*)GC_PAIR(typedWork, i))->flags = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((GcResPersona*)GC_PERSONA(typedWork, i))->flags = 0;
    }
    sGcRes = (u8*)typedWork;
}

// FUN_00219D90
void func_00219d90(void)
{
    GcResWork* work;
    GcResRequest* request;
    s32 i;

    if (sGcRes != NULL) {
        goto have_work;
    }
    K_ASSERT(false, 0x7c);
have_work:
    work = (GcResWork*)sGcRes;
    i = 0;
    goto check_loop;

body:
    request = &work->requests[i];
    if (((~request->flags) & 1) != 0) {
        goto increment;
    }
    switch (request->state) {
    case 0:
        goto assert_state0;
    case 1:
        goto process;
    case 2:
        goto assert_state2;
    default:
        goto increment;
    }

assert_state0:
    K_ASSERT(false, 0xc1);
    goto increment;

process:
    if (H_Cdvd_IsFileLoaded((HCdvd*)request->cdvd) == 0) {
        goto increment;
    }
    switch (request->type) {
    case 2:
        goto misc;
    case 0:
        goto pair;
    case 1:
        goto persona;
    default:
        goto set_state;
    }

misc:
    switch (request->slot) {
    case 0:
        goto misc_slot0;
    case 1:
        goto misc_slot1;
    default:
        goto set_state;
    }

misc_slot0:
    K_ASSERT(((~work->loadedFlags) & 1) != 0, 0xcf);
    work->cardRaster =
        bpTexCreateTmxRaster(((HCdvd*)request->cdvd)->fileMemory);
    work->loadedFlags |= 1;
    H_Cdvd_Destroy((HCdvd*)request->cdvd);
    request->flags &= ~1u;
    goto set_state;

misc_slot1:
    K_ASSERT(((~work->loadedFlags) & 2) != 0, 0xd6);
    work->miscRaster =
        bpTexCreateTmxRaster(((HCdvd*)request->cdvd)->fileMemory);
    work->loadedFlags |= 2;
    work->pendingCount = 1;
    work->flags &= ~4u;
    H_Cdvd_Destroy((HCdvd*)request->cdvd);
    request->flags &= ~1u;
    goto set_state;

pair:
    K_ASSERT(((~GC_U32(GC_PAIR(work, request->slot), 0)) & 2) != 0, 0xe3);
    GC_PTR(GC_PAIR(work, request->slot), 0x0c) =
        bpTexCreateTmxRaster(((HCdvd*)request->cdvd)->fileMemory);
    GC_U32(GC_PAIR(work, request->slot), 0) |= 2;
    H_Cdvd_Destroy((HCdvd*)request->cdvd);
    request->flags &= ~1u;
    goto set_state;

persona:
    K_ASSERT(((~GC_U32(GC_PERSONA(work, request->slot), 0)) & 2) != 0, 0xeb);
    GC_PTR(GC_PERSONA(work, request->slot), 0x08) =
        bpTexCreateTmxRaster(((HCdvd*)request->cdvd)->fileMemory);
    GC_U32(GC_PERSONA(work, request->slot), 0) |= 2;
    H_Cdvd_Destroy((HCdvd*)request->cdvd);
    request->flags &= ~1u;

set_state:
    request->state = 2;
    goto increment;

assert_state2:
    K_ASSERT(false, 0xf8);

increment:
    i++;
check_loop:
    if (i < 0x20) {
        goto body;
    }
}

// FUN_0021A120
u32 func_0021a120(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x20; i++) {
        if ((GC_U32(GC_REQUEST(work, i), 0x00) & 1) != 0) {
            break;
        }
    }
    return i < 0x20;
}

// FUN_0021A1B0
void func_0021a1b0(void)
{
    GcResWork* work;
    u8* record;
    u32 flags;
    s32 i;
    s32 j;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = (GcResWork*)sGcRes;
    if ((work->loadedFlags & 1) != 0) {
        func_004cde90(work->cardRaster);
    }
    if ((work->loadedFlags & 2) != 0) {
        func_004cde90(work->miscRaster);
    }
    if ((work->loadedFlags & 4) != 0) {
        for (i = 0; i < 7; i++) {
            func_004cde90(GC_PTR((u8*)work + i * 4, 0x20));
        }
    }
    if ((work->loadedFlags & 8) != 0) {
        for (i = 0; i < 2; i++) {
            func_004cde90(GC_PTR((u8*)work + i * 4, 0x3c));
        }
    }
    for (j = 0; j < 0x10; j++) {
        record = GC_PAIR(work, j);
        flags = GC_U32(record, 0x00);
        if (((~flags) & 1) == 0) {
            K_ASSERT((flags & 2) != 0, 0x12f);
            func_004cde90(GC_PTR(record, 0x0c));
        }
    }
    for (j = 0; j < 0x10; j++) {
        record = GC_PERSONA(work, j);
        flags = GC_U32(record, 0x00);
        if (((~flags) & 1) == 0) {
            K_ASSERT((flags & 2) != 0, 0x138);
            func_004cde90(GC_PTR(record, 0x08));
        }
    }
    sGcRes = NULL;
}

// FUN_0021a3a0
void* func_0021a3a0(void)
{
    u8* work;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    K_ASSERT((GC_U32(work, 0x0c) & 1) != 0, 0x143);
    return GC_PTR(work, 0x04);
}

// FUN_0021a410
void* func_0021a410(void)
{
    u8* work;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    K_ASSERT((GC_U32(work, 0x0c) & 2) != 0, 0x14b);
    return GC_PTR(work, 0x08);
}

// FUN_0021A480
void* func_0021a480(s32 majorId, s32 minorId)
{
    GcResWork* work;
    GcResPairAtWork* record;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = (GcResWork*)sGcRes;
    for (i = 0; i < 0x10; i++) {
        record = (GcResPairAtWork*)((u8*)work + i * 0x14);
        if (record->majorId == majorId && record->minorId == minorId) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x15a);
    K_ASSERT((work->pairs[i].flags & 2) != 0, 0x15b);
    return work->pairs[i].raster;
}

// FUN_0021A590
void* func_0021a590(s16 id)
{
    const u8* work;
    const u8* record;
    u8* scaledIndex;
    s32 recordOffset;
    u32 target;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    i = 0;
    target = (u16)id;
    while (i < 0x10) {
        record = work + i * 0x10;
        if ((u16)GC_S16(record, 0x190) == target) {
            break;
        }
        i++;
    }
    K_ASSERT(i < 0x10, 0x16a);
    recordOffset = i * 0x10;
    record = (const u8*)(recordOffset + (s32)work);
    K_ASSERT((GC_U32(record, 0x18c) & 2) != 0, 0x16c);
    scaledIndex = (u8*)(i * 0x10);
    return GC_PTR((u32)scaledIndex + (u32)work, 0x194);
}

// FUN_0021A670
void func_0021a670(s32 majorId, s32 minorId)
{
    u8* record;

    K_ASSERT(sGcRes != NULL, 0x7c);
    record = (u8*)func_0021ad40(majorId, minorId);
    K_ASSERT(GC_U32(record, 0x10) != 0, 0x177);
    GC_U32(record, 0x10)--;
    if (GC_U32(record, 0x10) == 0) {
        K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x180);
        func_004cde90(GC_PTR(record, 0x0c));
        GC_U32(record, 0x00) &= ~2u;
        GC_U32(record, 0x00) &= ~1u;
    }
}

// FUN_0021A760
void func_0021a760(s16 id)
{
    u8* record;

    K_ASSERT(sGcRes != NULL, 0x7c);
    record = (u8*)func_0021b080(id);
    K_ASSERT(GC_U32(record, 0x0c) != 0, 0x18e);
    GC_U32(record, 0x0c)--;
    if (GC_U32(record, 0x0c) == 0) {
        K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x197);
        func_004cde90(GC_PTR(record, 0x08));
        GC_U32(record, 0x00) &= ~2u;
        GC_U32(record, 0x00) &= ~1u;
    }
}

// FUN_0021A840
void func_0021a840(void)
{
    GcResWork* work;
    GcResRequest* request;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = (GcResWork*)sGcRes;
    if ((work->flags & 4) != 0) {
        K_ASSERT(work->pendingCount != 0, 0x1ca);
        work->pendingCount++;
    } else {
        work->flags |= 4;
        request = (GcResRequest*)func_0021b2d0();
        request->type = 2;
        request->slot = 1;
        request->cdvd = H_Cdvd_Request("card/misc/w_c00.tmx", HCDVD_FILENORMAL);
        request->state = 1;
        request->flags |= 1;
    }
}

// FUN_0021A920
void func_0021a920(s32 majorId, s32 minorId)
{
    s32 index;
    GcResWork* work;
    GcResPair* record;
    GcResRequest* request;
    char prefix[16];
    char path[256];
    char suffix;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = (GcResWork*)sGcRes;
    if (func_0021ac90(majorId, minorId) != false) {
        func_0021ae30(majorId, minorId);
        return;
    }

    index = func_0021af30();
    record = &work->pairs[index];
    record->majorId = majorId;
    record->minorId = minorId;
    record->raster = NULL;
    record->refs = 1;
    record->flags |= 1;

    request = (GcResRequest*)func_0021b2d0();
    request->type = 0;
    request->slot = index;
    switch (majorId) {
    case 0:
        strcpy(prefix, "sword");
        break;
    case 1:
        strcpy(prefix, "coin");
        break;
    case 2:
        strcpy(prefix, "wand");
        break;
    case 3:
        strcpy(prefix, "cup");
        break;
    default:
        break;
    }
    if (record->minorId < 0xb) {
        sprintf(path, "card/sarcana/%s_c%02d.tmx", prefix, record->minorId);
    } else {
        switch (record->minorId) {
        case 0xb:
            suffix = 'p';
            break;
        case 0xc:
            suffix = 'n';
            break;
        case 0xd:
            suffix = 'q';
            break;
        case 0xe:
            suffix = 'k';
            break;
        default:
            break;
        }
        sprintf(path, "card/sarcana/%s_c0%c.tmx", prefix, suffix);
    }
    request->cdvd = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    request->state = 1;
    request->flags |= 1;
}

// FUN_0021ab80
void func_0021ab80(s16 id)
{
    u8* work;
    u8* record;
    u8* request;
    char path[256];
    s32 index;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    if (func_0021afe0(id) != false) {
        func_0021b1f0(id);
        return;
    }

    index = func_0021b150();
    record = GC_PERSONA(work, index);
    GC_U32(record, 0x00) |= 1;
    GC_S16(record, 0x04) = id;
    GC_PTR(record, 0x08) = NULL;
    GC_U32(record, 0x0c) = 1;

    request = (u8*)func_0021b2d0();
    GC_U32(request, 0x110) = 1;
    GC_U32(request, 0x114) = (u32)index;
    sprintf(path, "card/persona/i_prc%03x.tmx", (u32)((u16)id));
    GC_PTR(request, 0x08) = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    GC_U32(request, 0x04) = 1;
    GC_U32(request, 0x00) |= 1;
}

// FUN_0021AC90
s32 func_0021ac90(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x10; i++) {
        record = work + i * 0x14;
        if (((~GC_U32(record, 0x4c)) & 1) == 0 &&
            GC_U32(record, 0x54) == (u32)minorId &&
            GC_U32(record, 0x50) == (u32)majorId) {
            break;
        }
    }
    return i < 0x10;
}

// FUN_0021AD40
void* func_0021ad40(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x10; i++) {
        record = work + i * 0x14;
        if (((~GC_U32(record, 0x4c)) & 1) == 0 &&
            GC_U32(record, 0x54) == (u32)minorId &&
            GC_U32(record, 0x50) == (u32)majorId) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x262);
    return GC_PAIR(work, i);
}

// FUN_0021AE30
void func_0021ae30(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x10; i++) {
        record = work + i * 0x14;
        if (((~GC_U32(record, 0x4c)) & 1) == 0 &&
            GC_U32(record, 0x54) == (u32)minorId &&
            GC_U32(record, 0x50) == (u32)majorId) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x262);
    record = work + i * 0x14;
    GC_U32(record, 0x5c)++;
}

// FUN_0021AF30
s32 func_0021af30(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x10; i++) {
        if (((~GC_U32(GC_PAIR(work, i), 0x00)) & 1) != 0) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x27a);
    return i;
}

// FUN_0021AFE0
u32 func_0021afe0(s16 id)
{
    u8* work;
    u8* record;
    u32 target;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    i = 0;
    target = (u16)id;
    while (i < 0x10) {
        record = work + i * 0x10;
        if (((~GC_U32(record, 0x18c)) & 1) == 0 &&
            (u16)GC_S16(record, 0x190) == target) {
            break;
        }
        i++;
    }
    return i < 0x10;
}

// FUN_0021B080
void* func_0021b080(s16 id)
{
    u8* work;
    u8* record;
    u32 target;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    i = 0;
    target = (u16)id;
    while (i < 0x10) {
        record = work + i * 0x10;
        if (((~GC_U32(record, 0x18c)) & 1) == 0 &&
            (u16)GC_S16(record, 0x190) == target) {
            break;
        }
        i++;
    }
    K_ASSERT(i < 0x10, 0x29f);
    return GC_PERSONA(work, i);
}

// FUN_0021B150
s32 func_0021b150(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x10; i++) {
        if (((~GC_U32(GC_PERSONA(work, i), 0x00)) & 1) != 0) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x2af);
    return i;
}

// FUN_0021B1F0
void func_0021b1f0(s16 id)
{
    u8* work;
    u8* record;
    u32 target;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    i = 0;
    target = (u16)id;
    while (i < 0x10) {
        record = work + i * 0x10;
        if (((~GC_U32(record, 0x18c)) & 1) == 0 &&
            (u16)GC_S16(record, 0x190) == target) {
            break;
        }
        i++;
    }
    K_ASSERT(i < 0x10, 0x29f);
    record = work + i * 0x10;
    GC_U32(record, 0x198)++;
}

// FUN_0021B2D0
void* func_0021b2d0(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    for (i = 0; i < 0x20; i++) {
        if (((~GC_U32(GC_REQUEST(work, i), 0x00)) & 1) != 0) {
            break;
        }
    }
    K_ASSERT(i < 0x20, 0x2d0);
    return GC_REQUEST(work, i);
}

// FUN_0021B3A0
void* func_0021b3a0(s32 index)
{
    u8* work;
    u8* scaledIndex;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    K_ASSERT((GC_U32(work, 0x0c) & 4) != 0, 0x2eb);
    scaledIndex = (u8*)(index * 4);
    return GC_PTR((u32)scaledIndex + (u32)work, 0x20);
}

// FUN_0021B420
void* func_0021b420(s32 index)
{
    u8* work;
    u8* scaledIndex;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = sGcRes;
    K_ASSERT((GC_U32(work, 0x0c) & 8) != 0, 0x2f3);
    scaledIndex = (u8*)(index * 4);
    return GC_PTR((u32)scaledIndex + (u32)work, 0x3c);
}

/* Removing this worsens FUN_0021b4a0 (nd114 -> nd116) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0021B4A0
void func_0021b4a0(u8* resource)
{
    GcResWork* work;
    u8* data;
    s32 i;
    s32 j;
    u32 entry;

    K_ASSERT(sGcRes != NULL, 0x7c);
    work = (GcResWork*)sGcRes;
    K_ASSERT(((~work->loadedFlags) & 4) != 0, 0x317);
    K_ASSERT(((~work->loadedFlags) & 8) != 0, 0x318);
    K_ASSERT(((~work->loadedFlags) & 1) != 0, 0x319);
    K_ASSERT(*(u16*)((u8*)resource + 4) == 10, 0x31a);

    for (i = 0; i < 7; i++) {
        entry = i * 8;
        entry += (u32)resource;
        work->cardResources[i] =
            bpTexCreateTmxRaster(resource + *(s32*)(entry + 8));
    }
    data = resource + 8;
    work->cardRaster =
        bpTexCreateTmxRaster(resource + *(s32*)(resource + 0x40));
    for (j = 0; j < 2; j++) {
        work->miscResources[j] =
            bpTexCreateTmxRaster(resource + *(s32*)(data + j * 8 + 0x40));
    }
    work->loadedFlags |= 1;
    work->loadedFlags |= 4;
    work->loadedFlags |= 8;
}
#pragma opt_loop_invariants reset


#pragma alias bseInit FUN_0021b650
#pragma alias bseShutdown FUN_0021b660
#pragma alias bseRequestSelection FUN_0021b670
#pragma alias bseIsSelectionPending FUN_0021b6f0
#pragma alias bseWasSelectionCancelled FUN_0021b740
#pragma alias bseGetSelectionResult FUN_0021b7c0
#pragma alias bseCancelSelection FUN_0021b830
#pragma alias bseCompleteSelection FUN_0021b8b0


static u32* sBseWork; // DAT_007ce300

extern void bpRoot001fe510(u32 request);
extern void FUN_0010a4e0(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern int printf(const char* format, ...);

// FUN_0021b650
void bseInit(u32* param_1)
{
    *param_1 = 0;
    sBseWork = param_1;
}

// FUN_0021b660
void bseShutdown(void)
{
    sBseWork = NULL;
}
