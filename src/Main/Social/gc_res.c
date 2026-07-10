#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "h_cdvd.h"
#include "Main/Battle/Panel/bp_tex.h"

extern int sprintf(char* buffer, const char* format, ...);
extern char* strcpy(char* destination, const char* source);
extern void func_004cde90(void* raster);

/* The GC resource task owns this private work area (DAT_007ce2fc). */
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

// FUN_00219C90 NONMATCHING
void func_00219c90(void* work)
{
    s32 i;

    K_ASSERT(sGcRes == NULL, 0x95);
    GC_U32(work, 0x00) = 0;
    GC_U32(work, 0x14) = 0;
    GC_U32(work, 0x18) = 0;
    GC_U32(work, 0x0c) = 0;
    GC_U32(work, 0x10) = 0;
    GC_U32(work, 0x04) = 0;
    GC_U32(work, 0x08) = 0;
    GC_U32(work, 0x44) = 0;
    GC_U32(work, 0x48) = 0;
    for (i = 0; i < 0x20; i++) {
        GC_U32(work, 0x28c + i * 0x124) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        GC_U32(work, 0x4c + i * 0x14) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        GC_U32(work, 0x18c + i * 0x10) = 0;
    }
    sGcRes = (u8*)work;
}

// FUN_00219D90 NONMATCHING
void func_00219d90(void)
{
    u8* work;
    u8* request;
    u8* record;
    HCdvd* cdvd;
    u32 flags;
    u32 state;
    u32 type;
    u32 slot;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x20; i++) {
        request = GC_REQUEST(work, i);
        flags = GC_U32(request, 0x00);
        if ((flags & 1) == 0) {
            continue;
        }

        state = GC_U32(request, 0x04);
        if (state == 2) {
            K_ASSERT(false, 0xf8);
            continue;
        }
        if (state == 0) {
            K_ASSERT(false, 0xc1);
            continue;
        }
        if (state != 1) {
            continue;
        }
        cdvd = (HCdvd*)GC_PTR(request, 0x08);
        if (H_Cdvd_IsFileLoaded(cdvd) == 0) {
            continue;
        }

        type = GC_U32(request, 0x110);
        slot = GC_U32(request, 0x114);
        if (type == 1) {
            record = GC_PERSONA(work, slot);
            K_ASSERT((GC_U32(record, 0x00) & 2) == 0, 0xeb);
            GC_PTR(record, 0x08) = bpTexCreateTmxRaster(cdvd->fileMemory);
            GC_U32(record, 0x00) |= 2;
        } else if (type == 0) {
            record = GC_PAIR(work, slot);
            K_ASSERT((GC_U32(record, 0x00) & 2) == 0, 0xe3);
            GC_PTR(record, 0x0c) = bpTexCreateTmxRaster(cdvd->fileMemory);
            GC_U32(record, 0x00) |= 2;
        } else if (type == 2) {
            if (slot == 1) {
                K_ASSERT((GC_U32(work, 0x0c) & 2) == 0, 0xd6);
                GC_PTR(work, 0x08) = bpTexCreateTmxRaster(cdvd->fileMemory);
                GC_U32(work, 0x0c) |= 2;
                GC_U32(work, 0x48) = 1;
                GC_U32(work, 0x00) &= ~4u;
            } else if (slot == 0) {
                K_ASSERT((GC_U32(work, 0x0c) & 1) == 0, 0xcf);
                GC_PTR(work, 0x04) = bpTexCreateTmxRaster(cdvd->fileMemory);
                GC_U32(work, 0x0c) |= 1;
                GC_U32(work, 0x00) &= ~4u;
            } else {
                GC_U32(request, 0x04) = 2;
                continue;
            }
        } else {
            GC_U32(request, 0x04) = 2;
            continue;
        }

        H_Cdvd_Destroy(cdvd);
        GC_U32(request, 0x00) &= ~1u;
        GC_U32(request, 0x04) = 2;
    }
}

// FUN_0021A120 NONMATCHING
u32 func_0021a120(void)
{
    u8* work;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x20; i++) {
        if ((GC_U32(GC_REQUEST(work, i), 0x00) & 1) != 0) {
            return true;
        }
    }
    return false;
}

// FUN_0021A1B0 NONMATCHING
void func_0021a1b0(void)
{
    u8* work;
    u8* record;
    u32 flags;
    s32 i;

    work = gcResRequire();
    flags = GC_U32(work, 0x0c);
    if ((flags & 1) != 0) {
        func_004cde90(GC_PTR(work, 0x04));
    }
    if ((flags & 2) != 0) {
        func_004cde90(GC_PTR(work, 0x08));
    }
    if ((flags & 4) != 0) {
        for (i = 0; i < 7; i++) {
            func_004cde90(GC_PTR(work, 0x20 + i * 4));
        }
    }
    if ((flags & 8) != 0) {
        for (i = 0; i < 2; i++) {
            func_004cde90(GC_PTR(work, 0x3c + i * 4));
        }
    }
    for (i = 0; i < 0x10; i++) {
        record = GC_PAIR(work, i);
        flags = GC_U32(record, 0x00);
        if ((flags & 1) != 0) {
            K_ASSERT((flags & 2) != 0, 0x12f);
            func_004cde90(GC_PTR(record, 0x0c));
        }
    }
    for (i = 0; i < 0x10; i++) {
        record = GC_PERSONA(work, i);
        flags = GC_U32(record, 0x00);
        if ((flags & 1) != 0) {
            K_ASSERT((flags & 2) != 0, 0x138);
            func_004cde90(GC_PTR(record, 0x08));
        }
    }
    sGcRes = NULL;
}

// FUN_0021A3A0 NONMATCHING
void* func_0021a3a0(void)
{
    u8* work;

    work = gcResRequire();
    K_ASSERT((GC_U32(work, 0x0c) & 1) != 0, 0x143);
    return GC_PTR(work, 0x04);
}

// FUN_0021A410 NONMATCHING
void* func_0021a410(void)
{
    u8* work;

    work = gcResRequire();
    K_ASSERT((GC_U32(work, 0x0c) & 2) != 0, 0x14b);
    return GC_PTR(work, 0x08);
}

// FUN_0021A480 NONMATCHING
void* func_0021a480(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PAIR(work, i);
        if (GC_U32(record, 0x04) == (u32)majorId &&
            GC_U32(record, 0x08) == (u32)minorId) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x15a);
    record = GC_PAIR(work, i);
    K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x15b);
    return GC_PTR(record, 0x0c);
}

// FUN_0021A590 NONMATCHING
void* func_0021a590(s16 id)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PERSONA(work, i);
        if (GC_S16(record, 0x04) == id) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x16a);
    record = GC_PERSONA(work, i);
    K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x16c);
    return GC_PTR(record, 0x08);
}

// FUN_0021A670 NONMATCHING
void func_0021a670(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    u32 refs;

    work = gcResRequire();
    record = (u8*)func_0021ad40(majorId, minorId);
    refs = GC_U32(record, 0x10);
    K_ASSERT(refs != 0, 0x177);
    refs--;
    GC_U32(record, 0x10) = refs;
    if (refs == 0) {
        K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x180);
        func_004cde90(GC_PTR(record, 0x0c));
        GC_U32(record, 0x00) &= ~3u;
    }
    (void)work;
}

// FUN_0021A760 NONMATCHING
void func_0021a760(s16 id)
{
    u8* work;
    u8* record;
    u32 refs;

    work = gcResRequire();
    record = (u8*)func_0021b080(id);
    refs = GC_U32(record, 0x0c);
    K_ASSERT(refs != 0, 0x18e);
    refs--;
    GC_U32(record, 0x0c) = refs;
    if (refs == 0) {
        K_ASSERT((GC_U32(record, 0x00) & 2) != 0, 0x197);
        func_004cde90(GC_PTR(record, 0x08));
        GC_U32(record, 0x00) &= ~3u;
    }
    (void)work;
}

// FUN_0021A840 NONMATCHING
void func_0021a840(void)
{
    u8* work;
    u8* request;
    u32 flags;

    work = gcResRequire();
    flags = GC_U32(work, 0x00);
    if ((flags & 4) == 0) {
        GC_U32(work, 0x00) = flags | 4;
        request = (u8*)func_0021b2d0();
        GC_U32(request, 0x110) = 2;
        GC_U32(request, 0x114) = 1;
        GC_PTR(request, 0x08) = H_Cdvd_Request("card/misc/w_c00.tmx", HCDVD_FILENORMAL);
        GC_U32(request, 0x04) = 1;
        GC_U32(request, 0x00) |= 1;
    } else {
        K_ASSERT(GC_U32(work, 0x48) != 0, 0x1ca);
        GC_U32(work, 0x48)++;
    }
}

// FUN_0021A920 NONMATCHING
void func_0021a920(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    u8* request;
    char prefix[16];
    char path[256];
    char suffix;
    s32 index;

    work = gcResRequire();
    if (func_0021ac90(majorId, minorId) != false) {
        func_0021ae30(majorId, minorId);
        return;
    }

    index = func_0021af30();
    record = GC_PAIR(work, index);
    GC_U32(record, 0x04) = (u32)majorId;
    GC_U32(record, 0x08) = (u32)minorId;
    GC_U32(record, 0x0c) = 0;
    GC_U32(record, 0x10) = 1;
    GC_U32(record, 0x00) |= 1;

    request = (u8*)func_0021b2d0();
    GC_U32(request, 0x110) = 0;
    GC_U32(request, 0x114) = (u32)index;
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
        prefix[0] = '\0';
        break;
    }
    if (minorId < 0xb) {
        sprintf(path, "card/sarcana/%s_c%02d.tmx", prefix, minorId);
    } else {
        suffix = '\0';
        switch (minorId) {
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
    GC_PTR(request, 0x08) = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    GC_U32(request, 0x04) = 1;
    GC_U32(request, 0x00) |= 1;
}

// FUN_0021AB80 NONMATCHING
void func_0021ab80(s16 id)
{
    u8* work;
    u8* record;
    u8* request;
    char path[256];
    s32 index;

    work = gcResRequire();
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

// FUN_0021AC90 NONMATCHING
s32 func_0021ac90(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PAIR(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 &&
            GC_U32(record, 0x08) == (u32)minorId &&
            GC_U32(record, 0x04) == (u32)majorId) {
            return true;
        }
    }
    return false;
}

// FUN_0021AD40 NONMATCHING
void* func_0021ad40(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PAIR(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 &&
            GC_U32(record, 0x08) == (u32)minorId &&
            GC_U32(record, 0x04) == (u32)majorId) {
            return record;
        }
    }
    K_ASSERT(false, 0x262);
    return GC_PAIR(work, i);
}

// FUN_0021AE30 NONMATCHING
void func_0021ae30(s32 majorId, s32 minorId)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PAIR(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 &&
            GC_U32(record, 0x08) == (u32)minorId &&
            GC_U32(record, 0x04) == (u32)majorId) {
            GC_U32(record, 0x10)++;
            return;
        }
    }
    K_ASSERT(false, 0x262);
}

// FUN_0021AF30 NONMATCHING
s32 func_0021af30(void)
{
    u8* work;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        if ((GC_U32(GC_PAIR(work, i), 0x00) & 1) == 0) {
            return i;
        }
    }
    K_ASSERT(false, 0x27a);
    return i;
}

// FUN_0021AFE0 NONMATCHING
u32 func_0021afe0(s16 id)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PERSONA(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 && GC_S16(record, 0x04) == id) {
            return true;
        }
    }
    return false;
}

// FUN_0021B080 NONMATCHING
void* func_0021b080(s16 id)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PERSONA(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 && GC_S16(record, 0x04) == id) {
            return record;
        }
    }
    K_ASSERT(false, 0x29f);
    return GC_PERSONA(work, i);
}

// FUN_0021B150 NONMATCHING
s32 func_0021b150(void)
{
    u8* work;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        if ((GC_U32(GC_PERSONA(work, i), 0x00) & 1) == 0) {
            return i;
        }
    }
    K_ASSERT(false, 0x2af);
    return i;
}

// FUN_0021B1F0 NONMATCHING
void func_0021b1f0(s16 id)
{
    u8* work;
    u8* record;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x10; i++) {
        record = GC_PERSONA(work, i);
        if ((GC_U32(record, 0x00) & 1) != 0 && GC_S16(record, 0x04) == id) {
            GC_U32(record, 0x0c)++;
            return;
        }
    }
    K_ASSERT(false, 0x29f);
}

// FUN_0021B2D0 NONMATCHING
void* func_0021b2d0(void)
{
    u8* work;
    s32 i;

    work = gcResRequire();
    for (i = 0; i < 0x20; i++) {
        if ((GC_U32(GC_REQUEST(work, i), 0x00) & 1) == 0) {
            return GC_REQUEST(work, i);
        }
    }
    K_ASSERT(false, 0x2d0);
    return GC_REQUEST(work, i);
}

// FUN_0021B3A0 NONMATCHING
void* func_0021b3a0(s32 index)
{
    u8* work;

    work = gcResRequire();
    K_ASSERT((GC_U32(work, 0x0c) & 4) != 0, 0x2eb);
    return GC_PTR(work, 0x20 + index * 4);
}

// FUN_0021B420 NONMATCHING
void* func_0021b420(s32 index)
{
    u8* work;

    work = gcResRequire();
    K_ASSERT((GC_U32(work, 0x0c) & 8) != 0, 0x2f3);
    return GC_PTR(work, 0x3c + index * 4);
}

// FUN_0021B4A0 NONMATCHING
void func_0021b4a0(void* resource)
{
    u8* work;
    u8* data;
    s32 i;
    s32 offset;

    work = gcResRequire();
    K_ASSERT((GC_U32(work, 0x0c) & 4) != 0, 0x317);
    K_ASSERT((GC_U32(work, 0x0c) & 8) != 0, 0x318);
    K_ASSERT((GC_U32(work, 0x0c) & 1) != 0, 0x319);
    K_ASSERT(*(s16*)((u8*)resource + 4) == 10, 0x31a);

    data = (u8*)resource;
    for (i = 0; i < 7; i++) {
        offset = *(s32*)(data + i * 8 + 8);
        GC_PTR(work, 0x20 + i * 4) = bpTexCreateTmxRaster(data + offset);
    }
    offset = *(s32*)(data + 0x40);
    GC_PTR(work, 0x04) = bpTexCreateTmxRaster(data + offset);
    for (i = 0; i < 2; i++) {
        offset = *(s32*)(data + i * 8 + 0x48);
        GC_PTR(work, 0x3c + i * 4) = bpTexCreateTmxRaster(data + offset);
    }
    GC_U32(work, 0x0c) |= 0xd;
}
