#include "Main/Social/sfl_res.h"
#include "h_cdvd.h"
#include "Main/g_data.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static u32* sSflRes; // DAT_007ce2f0
extern char DAT_0068e1c0[];
extern char DAT_0068e1e0[];
extern char DAT_0068e130[];
extern char DAT_0068e150[];
extern char DAT_0068e170[];
extern char DAT_0068e1a0[];
extern f32 DAT_0068e108[];
extern void* (*DAT_00960178)(u32 size, u32 heap);
extern void (*DAT_0096017c)(void* memory);
extern void (*DAT_00960090)(u32 state, u32 value);
extern u16 D_00875A90[];
extern void* func_004c38c0(void);
extern void func_004c31b0(f32 angle, void* matrix, const void* axis, u32 combine);
extern void func_004c3880(void* matrix);
extern void func_004f1ed0(void* vertices, u32 count, void* matrix, u32 stride);
extern void func_004f1fd0(u32 primitive, void* indices, u32 count);
extern void func_004f1f80(void);
extern void func_004cde90(void* resource);
extern void func_0021b4a0(void* resource);
extern void* bpTexCreateTmxRaster(void* tmxMemory);
extern void* memcpy(void* destination, const void* source, u32 size);
void sflRes0020e800(void* resource);
void sflRes0020ea80(void);
void sflRes0020ecc0(void);


static void sflResRequire(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
}

static void sflResLoadRaster(u32* work, s32 requestIndex, s32 fileIndex, s32 destinationIndex)
{
    u32 fileSize;
    void* file;

    file = H_Cdvd_ArchiveGetFile((void*)work[requestIndex], fileIndex, &fileSize);
    work[destinationIndex] = (u32)bpTexCreateTmxRaster(file);
}

static void sflResCopyFile(u32* work, s32 requestIndex, s32 fileIndex, s32 destinationIndex)
{
    u32 fileSize;
    void* file;
    void* copy;

    file = H_Cdvd_ArchiveGetFile((void*)work[requestIndex], fileIndex, &fileSize);
    copy = (*DAT_00960178)(fileSize, 0x40000);
    if (copy != NULL && file != NULL) {
        memcpy(copy, file, fileSize);
    }
    work[destinationIndex] = (u32)copy;
}

// FUN_0020d500 NONMATCHING
void sflRes0020d500(u32* work, const f32* vertices)
{
    f32 rotated[3];
    void* matrix;

    matrix = NULL;
    rotated[0] = DAT_0068e108[0];
    rotated[1] = DAT_0068e108[1];
    rotated[2] = DAT_0068e108[2];
    if ((*work & 1) != 0) {
        matrix = func_004c38c0();
        memcpy(matrix, vertices, 0x40);
        func_004c31b0(180.0f, matrix, rotated, 1);
        vertices = (const f32*)matrix;
    }
    func_004f1ed0(work + 1, 0x44, (void*)vertices, 3);
    DAT_00960090(1, 0);
    func_004f1fd0(3, D_00875A90, 0x138);
    func_004f1f80();
    if (matrix != NULL) {
        func_004c3880(matrix);
    }
}

// FUN_0020d630 NONMATCHING
void sflRes0020d630(void* work, const f32* value)
{
    f32* dst;

    dst = (f32*)((u8*)work + 0x2c);
    dst[0] = value[0];
    dst[1] = value[1];
    dst[2] = value[2];
}

// FUN_0020d650 NONMATCHING
void sflRes0020d650(void* work, const f32* value)
{
    f32* dst;

    dst = (f32*)((u8*)work + 0x20);
    dst[0] = value[0];
    dst[1] = value[1];
    dst[2] = value[2];
}

// FUN_0020d670 NONMATCHING
void sflRes0020d670(const void* work, f32* value)
{
    const f32* src;

    src = (const f32*)((const u8*)work + 0x20);
    value[0] = src[0];
    value[1] = src[1];
    value[2] = src[2];
}

// FUN_0020d690 NONMATCHING
void sflRes0020d690(void* work, const f32* value)
{
    f32* dst;

    dst = (f32*)((u8*)work + 0x10);
    dst[0] = value[0];
    dst[1] = value[1];
    dst[2] = value[2];
    dst[3] = value[3];
}

// FUN_0020d6c0
void sflRes0020d6c0(void* work)
{
    K_ASSERT(*(u32*)((u8*)work + 4) == 0, 0x677);
    *(u32*)((u8*)work + 0x170) |= 1;
}

// FUN_0020d710
void sflRes0020d710(u32* work)
{
    K_ASSERT(work[1] == 0, 0x67e);
    work[0x5c] |= 2;
    work[0] |= 2;
}

// FUN_0020d770 NONMATCHING
void sflRes0020d770(u32 value, void* work)
{
    K_ASSERT(*(u32*)((u8*)work + 4) == 1, 0x686);
    *(u32*)((u8*)work + 0x328) = value;
}

// FUN_0020d7d0
void sflRes0020d7d0(void* value)
{
    u32* work;

    K_ASSERT(sSflRes == NULL, 0x6c);
    work = (u32*)value;
    work[0] = 0;
    work[1] = 0;
    sSflRes = work;
}

// FUN_0020d820 NONMATCHING
void sflRes0020d820(void)
{
    u32* work;
    s32 i;

    sflResRequire();
    work = sSflRes;
    if ((*work & 1) != 0) {
        if ((work[1] & 2) == 0 && H_Cdvd_IsFileLoaded((void*)work[0x1a]) != 0) {
            for (i = 0; i < 0xf; i++) {
                switch (i) {
                case 0:
                    sflResLoadRaster(work, 0x1a, i, 5);
                    break;
                case 1:
                    sflResLoadRaster(work, 0x1a, i, 6);
                    break;
                case 2:
                    sflResLoadRaster(work, 0x1a, i, 7);
                    break;
                case 3:
                    sflResCopyFile(work, 0x1a, i, 0x16);
                    break;
                case 4:
                    sflResLoadRaster(work, 0x1a, i, 8);
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    sflResLoadRaster(work, 0x1a, i, i + 5);
                    break;
                case 11: {
                    u32 fileSize;
                    void* file = H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize);
                    func_0021b4a0(file);
                    break;
                }
                case 12:
                    sflResLoadRaster(work, 0x1a, i, 9);
                    break;
                case 13:
                    sflResCopyFile(work, 0x1a, i, 0x1e);
                    break;
                case 14:
                    sflResCopyFile(work, 0x1a, i, 0x1f);
                    break;
                default:
                    K_ASSERT(0, 0xbb);
                    break;
                }
            }
            H_Cdvd_Destroy((void*)work[0x1a]);
            work[1] |= 2;
        }
        if ((work[1] & 2) != 0) {
            *work &= ~1u;
        }
    }
    if ((*work & 2) != 0 && H_Cdvd_IsFileLoaded((void*)work[0x19]) != 0) {
        sflRes0020e800(*(void**)((u8*)work[0x19] + 0x110));
        H_Cdvd_Destroy((void*)work[0x19]);
        work[1] |= 1;
        *work &= ~2u;
    }
    if ((*work & 4) != 0) {
        if ((work[1] & 4) == 0 && H_Cdvd_IsFileLoaded((void*)work[0x1b]) != 0) {
            for (i = 0; i < 6; i++) {
                sflResLoadRaster(work, 0x1b, i, i + 0x10);
            }
            H_Cdvd_Destroy((void*)work[0x1b]);
            work[1] |= 4;
            *work &= ~4u;
        }
    }
    if ((*work & 8) != 0 && H_Cdvd_IsFileLoaded((void*)work[0x1c]) != 0) {
        sflResCopyFile(work, 0x1c, 0, 0x17);
        sflResCopyFile(work, 0x1c, 1, 0x18);
        H_Cdvd_Destroy((void*)work[0x1c]);
        work[1] |= 8;
        *work &= ~8u;
    }
    if ((*work & 0x10) != 0 && H_Cdvd_IsFileLoaded((void*)work[0x1d]) != 0) {
        work[0x20] = (u32)bpTexCreateTmxRaster(
            *(void**)((u8*)work[0x1d] + 0x110));
        H_Cdvd_Destroy((void*)work[0x1d]);
        work[1] |= 0x10;
        *work &= ~0x10u;
    }
}

// FUN_0020dfe0 NONMATCHING
u32 sflRes0020dfe0(void)
{
    sflResRequire();
    return *sSflRes & 1;
}

// FUN_0020e030 NONMATCHING
void sflRes0020e030(void)
{
    u32* work;
    s32 i;

    sflResRequire();
    work = sSflRes;
    if ((work[1] & 8) != 0) {
        sflRes0020ea80();
    }
    if ((work[1] & 2) != 0) {
        if (work[0x16] != 0) {
            DAT_0096017c((void*)work[0x16]);
        }
        for (i = 0; i < 5; i++) {
            func_004cde90((void*)work[i + 5]);
        }
        for (i = 0; i < 6; i++) {
            func_004cde90((void*)work[i + 10]);
        }
        for (i = 0; i < 2; i++) {
            DAT_0096017c((void*)work[i + 0x1e]);
        }
    }
    if ((work[1] & 1) != 0) {
        for (i = 0; i < 3; i++) {
            func_004cde90((void*)work[i + 2]);
        }
    }
    if ((work[1] & 4) != 0) {
        for (i = 0; i < 6; i++) {
            func_004cde90((void*)work[i + 0x10]);
        }
    }
    if ((work[1] & 0x10) != 0) {
        sflRes0020ecc0();
    }
    sSflRes = NULL;
}

// FUN_0020e200 NONMATCHING
void sflRes0020e200(void)
{
    u32* work;

    sflResRequire();
    work = sSflRes;
    K_ASSERT((work[1] & 2) != 0, 0x180);
    K_ASSERT((*work & 1) == 0, 0x181);
    work[0x1a] = (u32)H_Cdvd_Request(DAT_0068e130, 1);
    *work |= 1;
}

// FUN_0020e2c0 NONMATCHING
void sflRes0020e2c0(void)
{
    u32* work;

    sflResRequire();
    work = sSflRes;
    K_ASSERT((work[1] & 1) != 0, 0x18a);
    K_ASSERT((*work & 2) == 0, 0x18b);
    work[0x19] = (u32)H_Cdvd_Request(DAT_0068e150, 0);
    *work |= 2;
}

// FUN_0020e380 NONMATCHING
u32 sflRes0020e380(void)
{
    sflResRequire();
    return *sSflRes & 2;
}

// FUN_0020e3d0 NONMATCHING
void sflRes0020e3d0(void)
{
    u32* work;
    const char* path;

    sflResRequire();
    work = sSflRes;
    K_ASSERT((work[1] & 4) != 0, 0x19b);
    K_ASSERT((*work & 4) == 0, 0x19c);
    path = datGetScenarioMode() == 0 ? DAT_0068e1a0 : DAT_0068e170;
    work[0x1b] = (u32)H_Cdvd_Request(path, 1);
    *work |= 4;
}

// FUN_0020e4c0 NONMATCHING
u32 sflRes0020e4c0(void)
{
    sflResRequire();
    return *sSflRes & 4;
}

// FUN_0020e510 NONMATCHING
void* sflRes0020e510(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 2) != 0, 0x1b7);
    return (void*)sSflRes[index + 5];
}

// FUN_0020e590 NONMATCHING
void* sflRes0020e590(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 1) != 0, 0x1be);
    return (void*)sSflRes[index + 2];
}

// FUN_0020e610 NONMATCHING
void* sflRes0020e610(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 2) != 0, 0x1c5);
    return (void*)sSflRes[index + 10];
}

// FUN_0020e690 NONMATCHING
void* sflRes0020e690(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 4) != 0, 0x1cc);
    return (void*)sSflRes[index + 16];
}

// FUN_0020e710 NONMATCHING
void* sflRes0020e710(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 2) != 0, 0x1d3);
    return (void*)sSflRes[index + 30];
}

// FUN_0020e790 NONMATCHING
void* sflRes0020e790(void)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 2) != 0, 0x1da);
    return (void*)sSflRes[0x16];
}

// FUN_0020e800 NONMATCHING
void sflRes0020e800(void* resource)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 1) != 0, 0x1e3);
    K_ASSERT(*(s16*)((u8*)resource + 4) == 3, 0x1e7);
    sSflRes[2] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)((u8*)resource + 8));
    sSflRes[3] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)((u8*)resource + 0x10));
    sSflRes[4] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)((u8*)resource + 0x18));
    sSflRes[1] |= 1;
}

// FUN_0020ea00 NONMATCHING
void* sflRes0020ea00(s32 index)
{
    sflResRequire();
    K_ASSERT((sSflRes[1] & 8) != 0, 0x203);
    return (void*)sSflRes[index + 0x17];
}

// FUN_0020e9b0
u32 sflRes0020e9b0(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 8;
}

// FUN_0020ea80
void sflRes0020ea80(void)
{
    int base;
    int i;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 8, 0x20c);
    for (i = 0; i < 2; i++) {
        RwFree(*(void**)(base + i * 4 + 0x5c));
    }
    *(u32*)(base + 4) &= 0xfffffff7;
}

// FUN_0020ec00
u32 sflRes0020ec00(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 0x10;
}

void FUN_0021cc20();

// FUN_0020ec50
u32 sflRes0020ec50(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x22a);
    return *(u32*)(base + 0x80);
}

// FUN_0020ecc0
void sflRes0020ecc0(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x232);
    FUN_0021cc20(*(void**)(base + 0x80));
    *(u32*)(base + 4) &= 0xffffffef;
}

// FUN_0020e8f0
void sflRes0020e8f0(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~puVar1[1] & 8) != 0, 0x1f2);
    K_ASSERT((~*puVar1 & 8) != 0, 0x1f3);
    puVar1[0x1c] = (u32)(uintptr_t)H_Cdvd_Request(DAT_0068e1c0, 1);
    *puVar1 |= 8;
}

// FUN_0020eb40
void sflRes0020eb40(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~*puVar1 & 0x10) != 0, 0x218);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x219);
    puVar1[0x1d] = (u32)(uintptr_t)H_Cdvd_Request(DAT_0068e1e0, 0);
    *puVar1 |= 0x10;
}
