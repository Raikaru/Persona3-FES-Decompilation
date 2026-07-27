#include "Main/Social/sfl_res.h"
#include "h_cdvd.h"
#include "Main/g_data.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#pragma alias sflResDrawIndexedMesh FUN_0020d500
#pragma alias sflResSetSpriteScale FUN_0020D630
#pragma alias sflResSetSpritePosition FUN_0020D650
#pragma alias sflResGetSpritePosition FUN_0020D670
#pragma alias sflResSetSpriteRotation FUN_0020d690
#pragma alias sflResInit FUN_0020d7d0
#pragma alias sflResUpdate FUN_0020d820
#pragma alias sflResIsBaseArchivePending FUN_0020dfe0
#pragma alias sflResShutdown FUN_0020e030
#pragma alias sflResRequestBaseArchive FUN_0020e200
#pragma alias sflResRequestGroundArchive FUN_0020e2c0
#pragma alias sflResIsGroundArchivePending FUN_0020e380
#pragma alias sflResRequestEffectArchive FUN_0020e3d0
#pragma alias sflResIsEffectArchivePending FUN_0020e4c0
#pragma alias sflResGetBaseRaster FUN_0020e510
#pragma alias sflResGetGroundRaster FUN_0020e590
#pragma alias sflResGetBaseSecondaryRaster FUN_0020e610
#pragma alias sflResGetEffectRaster FUN_0020e690
#pragma alias sflResGetBaseDataFile FUN_0020e710
#pragma alias sflResGetBaseSpriteData FUN_0020e790
#pragma alias sflResLoadGroundRasters FUN_0020e800
#pragma alias sflResGetTutorialFile FUN_0020ea00
#pragma alias sflResIsTutorialArchivePending FUN_0020e9b0
#pragma alias sflResDestroyTutorialFiles FUN_0020ea80
#pragma alias sflResIsPersonaChangeSpritePending FUN_0020ec00
#pragma alias sflResGetPersonaChangeSprite FUN_0020ec50
#pragma alias sflResDestroyPersonaChangeSprite FUN_0020ecc0
#pragma alias sflResRequestTutorialArchive FUN_0020e8f0
#pragma alias sflResRequestPersonaChangeSprite FUN_0020eb40
#pragma alias sSflBaseArchivePath DAT_0068e130
#pragma alias sSflGroundArchivePath DAT_0068e150
#pragma alias sSflEpisodeAigisEffectArchivePath DAT_0068e170
#pragma alias sSflEffectArchivePath DAT_0068e1a0
#pragma alias sSflTutorialArchivePath DAT_0068e1c0
#pragma alias sSflPersonaChangeSpritePath DAT_0068e1e0


static u32* sSflRes; // DAT_007ce2f0
extern char sSflTutorialArchivePath[];
extern char sSflPersonaChangeSpritePath[];
extern char sSflBaseArchivePath[];
extern char sSflGroundArchivePath[];
extern char sSflEpisodeAigisEffectArchivePath[];
extern char sSflEffectArchivePath[];

extern const RwV3d DAT_0068e108;
extern void* (*DAT_00960178[])(u32 size, u32 heap);
extern void (*DAT_0096017c[])(void* memory);
extern void (*DAT_00960090[])(u32 state, u32 value);
extern u16 D_00875A90[];
extern void* func_004c38c0(void);
extern RwMatrix* func_004c31b0(RwMatrix* matrix, const RwV3d* axis, f32 angle, u32 combine);
extern void func_004c3880(void* matrix);
extern void func_004f1ed0(void* vertices, u32 count, void* matrix, u32 stride);
extern void func_004f1fd0(u32 primitive, void* indices, u32 count);
extern void func_004f1f80(void);
extern void func_004cde90(void* resource);
extern void func_0021b4a0(void* resource);
extern void* bpTexCreateTmxRaster(void* tmxMemory);
extern void* func_0021c9f0(void* tmxMemory);
extern void* memcpy(void* destination, const void* source, u32 size);
void sflResLoadGroundRasters(void* resource);
void sflResDestroyTutorialFiles(void);
void sflResDestroyPersonaChangeSprite(void);



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

// FUN_0020d500
void sflResDrawIndexedMesh(u32* work, const f32* vertices)
{
    RwV3d axis;
    RwMatrix* matrix;
    u32* destination;
    s32 count;
    const u32* source;
    u32 x;
    u32 y;

    axis = DAT_0068e108;
    if ((*work & 1) != 0) {
        matrix = (RwMatrix*)func_004c38c0();
        count = 8;
        source = (const u32*)vertices;
        destination = (u32*)matrix;
        do {
            x = source[0];
            y = source[1];
            source += 2;
            count -= 1;
            destination[0] = x;
            destination[1] = y;
            destination += 2;
        } while (count > 0);
        func_004c31b0(matrix, &axis, 180.0f, 1);
    } else {
        matrix = (RwMatrix*)vertices;
    }
    func_004f1ed0(work + 1, 0x44, matrix, 3);
    (*DAT_00960090)(1, 0);
    func_004f1fd0(3, D_00875A90, 0x138);
    func_004f1f80();
    if ((*work & 1) != 0) {
        func_004c3880(matrix);
    }
}

// FUN_0020D630
void sflResSetSpriteScale(void* work, const f32* value)
{
    *(RwV3d*)((u8*)work + 0x2c) = *(const RwV3d*)value;
}

// FUN_0020D650
void sflResSetSpritePosition(void* work, const f32* value)
{
    *(RwV3d*)((u8*)work + 0x20) = *(const RwV3d*)value;
}

// FUN_0020D670
void sflResGetSpritePosition(const void* work, f32* value)
{
    *(RwV3d*)value = *(const RwV3d*)((const u8*)work + 0x20);
}

// FUN_0020d690
void sflResSetSpriteRotation(void* work, const f32* value)
{
    *(RwV4d*)((u8*)work + 0x10) = *(const RwV4d*)value;
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

// FUN_0020d770
void sflRes0020d770(void* work, f32 value)
{
    K_ASSERT(*(u32*)((u8*)work + 4) == 1, 0x686);
    *(f32*)((u8*)work + 0x328) = value;
}

// FUN_0020d7d0
void sflResInit(void* value)
{
    u32* work;

    K_ASSERT(sSflRes == NULL, 0x6c);
    work = (u32*)value;
    work[0] = 0;
    work[1] = 0;
    sSflRes = work;
}

/* Removing this loses FUN_0020d820 (MATCH nd0 -> MISMATCH nd2) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0020d820 MATCHING
void sflResUpdate(void)
{
    u32* work;
    void* file;
    void* copy;
    u32 fileSize;
    s32 i;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    if ((*work & 1) != 0) {
        if (((~work[1]) & 2) == 0) {
            goto first_check;
        }
        if (H_Cdvd_IsFileLoaded((void*)work[0x1a]) == 0)
            goto first_clear;
            for (i = 0; i < 0xf; i++) {
                switch (i) {
                case 0:
                    work[5] = (u32)bpTexCreateTmxRaster(
                        H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize));
                    break;
                case 1:
                    work[6] = (u32)bpTexCreateTmxRaster(
                        H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize));
                    break;
                case 2:
                    work[7] = (u32)bpTexCreateTmxRaster(
                        H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize));
                    break;
                case 3: {
                    void* file;
                    void* caseCopy;
                    file = H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize);
                    caseCopy = (*DAT_00960178)(fileSize, 0x40000);
                    work[0x16] = (u32)caseCopy;
                    memcpy(caseCopy, file, *(volatile u32*)&fileSize);
                    break;
                }
                case 4:
                    work[8] = (u32)bpTexCreateTmxRaster(
                        H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize));
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10: {
                    void* file;
                    file = H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize);
                    K_ASSERT(i - 5 >= 0, 0xa2);
                    K_ASSERT(i - 5 < 6, 0xa3);
                    *(work + 5 + i) = (u32)bpTexCreateTmxRaster(file);
                    break;
                }
                case 11:
                    func_0021b4a0(H_Cdvd_ArchiveGetFile(
                        (void*)work[0x1a], i, &fileSize));
                    break;
                case 12:
                    work[9] = (u32)bpTexCreateTmxRaster(
                        H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize));
                    break;
                case 13: {
                    void* file;
                    void* copy;
                    file = H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize);
                    copy = (*DAT_00960178)(fileSize, 0x40000);
                    memcpy(copy, file, *(volatile u32*)&fileSize);
                    work[0x1e] = (u32)copy;
                    break;
                }
                case 14: {
                    void* file;
                    void* copy;
                    file = H_Cdvd_ArchiveGetFile((void*)work[0x1a], i, &fileSize);
                    copy = (*DAT_00960178)(fileSize, 0x40000);
                    memcpy(copy, file, *(volatile u32*)&fileSize);
                    work[0x1f] = (u32)copy;
                    break;
                }
                default:
                    K_ASSERT(0, 0xbb);
                    break;
                }
            }
            H_Cdvd_Destroy((void*)work[0x1a]);
            work[1] |= 2;
            goto first_clear;
    first_check:
        K_ASSERT((work[1] & 2) != 0, 0xc6);
    first_clear:
        if ((work[1] & 2) != 0) {
            *work &= ~1u;
        }
    }
    if ((*work & 2) != 0) {
        if (H_Cdvd_IsFileLoaded((void*)work[0x19]) != 0) {
            K_ASSERT(((~work[1]) & 1) != 0, 0xd2);
            sflResLoadGroundRasters(*(void**)((u8*)work[0x19] + 0x110));
            H_Cdvd_Destroy((void*)work[0x19]);
            work[1] |= 1;
            *work &= ~2u;
        }
    }
    if ((*work & 4) != 0) {
        s32 j;
        if (((~work[1]) & 4) == 0) {
            goto four_check;
        }
        if (H_Cdvd_IsFileLoaded((void*)work[0x1b]) == 0) {
            goto four_done;
        }
        for (j = 0; j < 6; j++) {
            switch (j) {
            case 0:
                work[0x10] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            case 1:
                work[0x11] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            case 2:
                work[0x12] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            case 3:
                work[0x13] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            case 4:
                work[0x14] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            case 5:
                work[0x15] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile((void*)work[0x1b], j, &fileSize));
                break;
            default:
                K_ASSERT(0, 0xfe);
                break;
            }
        }
        H_Cdvd_Destroy((void*)work[0x1b]);
        work[1] |= 4;
        goto four_done;
    four_check:
        K_ASSERT((work[1] & 4) != 0, 0x109);
    four_done:
        if ((work[1] & 4) != 0) {
            *work &= ~4u;
        }
    }
    if ((*work & 8) != 0 && H_Cdvd_IsFileLoaded((void*)work[0x1c]) != 0) {
        s32 k;
        for (k = 0; k < 2; k++) {
            switch (k) {
            case 0:
                file = H_Cdvd_ArchiveGetFile((void*)work[0x1c], k, &fileSize);
                work[0x17] = (u32)(*DAT_00960178)(fileSize, 0x40000);
                memcpy((void*)work[0x17], file, (s32)fileSize);
                break;
            case 1:
                file = H_Cdvd_ArchiveGetFile((void*)work[0x1c], k, &fileSize);
                work[0x18] = (u32)(*DAT_00960178)(fileSize, 0x40000);
                memcpy((void*)work[0x18], file, (s32)fileSize);
                break;
            }
            H_Cdvd_Destroy((void*)work[0x1c]);
            work[1] |= 8;
            *work &= ~8u;
        }
    }
    if ((*work & 0x10) != 0 && H_Cdvd_IsFileLoaded((void*)work[0x1d]) != 0) {
        work[0x20] = (u32)func_0021c9f0(
            *(void**)((u8*)work[0x1d] + 0x110));
        H_Cdvd_Destroy((void*)work[0x1d]);
        work[1] |= 0x10;
        *work &= ~0x10u;
    }
}
#pragma opt_loop_invariants off

// FUN_0020dfe0
u32 sflResIsBaseArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return *sSflRes & 1;
}

// FUN_0020e030
void sflResShutdown(void)
{
    u32* work;
    s32 i18_1;
    s32 i18_2;
    s32 i18_3;
    s32 i16_1;
    s32 i16_2;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    if ((work[1] & 8) == 0) {
        goto skip_8;
    }
    sflResDestroyTutorialFiles();
skip_8:
    if ((work[1] & 2) == 0) {
        goto skip_2;
    }
    {
        u32* callbacks;
        callbacks = (u32*)DAT_0096017c;
        ((void (*)(void*))callbacks[0])((void*)work[0x16]);
        for (i18_1 = 0; i18_1 < 5; i18_1++) {
            func_004cde90((void*)*((void**)((u8*)work + i18_1 * 4 + 0x14)));
        }
        for (i18_2 = 0; i18_2 < 6; i18_2++) {
            func_004cde90((void*)*((void**)((u8*)work + i18_2 * 4 + 0x28)));
        }
        for (i18_3 = 0; i18_3 < 2; i18_3++) {
            ((void (*)(void*))callbacks[0])(*((void**)((u8*)work + i18_3 * 4 + 0x78)));
        }
    }
skip_2:
    if ((work[1] & 1) == 0) {
        goto skip_1;
    }
    for (i16_1 = 0; i16_1 < 3; i16_1++) {
        func_004cde90((void*)*((void**)((u8*)work + i16_1 * 4 + 8)));
    }
skip_1:
    if ((work[1] & 4) == 0) {
        goto skip_4;
    }
    for (i16_2 = 0; i16_2 < 6; i16_2++) {
        func_004cde90((void*)*((void**)((u8*)work + i16_2 * 4 + 0x40)));
    }
skip_4:
    if ((work[1] & 0x10) != 0) {
        sflResDestroyPersonaChangeSprite();
    }
    sSflRes = NULL;
}

// FUN_0020e200
void sflResRequestBaseArchive(void)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work[1] & 2) != 0, 0x180);
    K_ASSERT((~*work & 1) != 0, 0x181);
    work[0x1a] = (u32)H_Cdvd_Request(sSflBaseArchivePath, 1);
    *work |= 1;
}

// FUN_0020e2c0
void sflResRequestGroundArchive(void)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work[1] & 1) != 0, 0x18a);
    K_ASSERT((~*work & 2) != 0, 0x18b);
    work[0x19] = (u32)H_Cdvd_Request(sSflGroundArchivePath, 0);
    *work |= 2;
}

// FUN_0020e380
u32 sflResIsGroundArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return *sSflRes & 2;
}

// FUN_0020e3d0
void sflResRequestEffectArchive(void)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work[1] & 4) != 0, 0x19b);
    K_ASSERT((~*work & 4) != 0, 0x19c);
    if (datGetScenarioMode() != 0) {
        work[0x1b] = (u32)H_Cdvd_Request(sSflEpisodeAigisEffectArchivePath, 1);
    } else {
        work[0x1b] = (u32)H_Cdvd_Request(sSflEffectArchivePath, 1);
    }
    *work |= 4;
}

// FUN_0020e4c0
u32 sflResIsEffectArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return *sSflRes & 4;
}

// FUN_0020e510
void* sflResGetBaseRaster(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 2) != 0, 0x1b7);
    return (void*)work[index + 5];
}

// FUN_0020e590
void* sflResGetGroundRaster(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 1) != 0, 0x1be);
    return (void*)work[index + 2];
}

// FUN_0020e610
void* sflResGetBaseSecondaryRaster(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 2) != 0, 0x1c5);
    return (void*)work[index + 10];
}

// FUN_0020e690
void* sflResGetEffectRaster(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 4) != 0, 0x1cc);
    return (void*)work[index + 16];
}

// FUN_0020e710
void* sflResGetBaseDataFile(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 2) != 0, 0x1d3);
    return (void*)work[index + 30];
}

// FUN_0020e790
void* sflResGetBaseSpriteData(void)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 2) != 0, 0x1da);
    return (void*)work[0x16];
}

// FUN_0020e800
void sflResLoadGroundRasters(void* resource)
{
    u32* work;
    u8* data;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((~work[1] & 1) != 0, 0x1e3);
    K_ASSERT(*(u16*)((u8*)resource + 4) == 3, 0x1e7);
    data = (u8*)resource + 8;
    work[2] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)data);
    work[3] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)(data + 8));
    work[4] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)(data + 0x10));
    work[1] |= 1;
}

// FUN_0020ea00
void* sflResGetTutorialFile(s32 index)
{
    u32* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work[1] & 8) != 0, 0x203);
    return (void*)work[index + 0x17];
}

// FUN_0020e9b0
u32 sflResIsTutorialArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 8;
}

// FUN_0020ea80
void sflResDestroyTutorialFiles(void)
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
u32 sflResIsPersonaChangeSpritePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 0x10;
}

void FUN_0021cc20();

// FUN_0020ec50
u32 sflResGetPersonaChangeSprite(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x22a);
    return *(u32*)(base + 0x80);
}

// FUN_0020ecc0
void sflResDestroyPersonaChangeSprite(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x232);
    FUN_0021cc20(*(void**)(base + 0x80));
    *(u32*)(base + 4) &= 0xffffffef;
}

// FUN_0020e8f0
void sflResRequestTutorialArchive(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~puVar1[1] & 8) != 0, 0x1f2);
    K_ASSERT((~*puVar1 & 8) != 0, 0x1f3);
    puVar1[0x1c] = (u32)(uintptr_t)H_Cdvd_Request(sSflTutorialArchivePath, 1);
    *puVar1 |= 8;
}

// FUN_0020eb40
void sflResRequestPersonaChangeSprite(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~*puVar1 & 0x10) != 0, 0x218);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x219);
    puVar1[0x1d] = (u32)(uintptr_t)H_Cdvd_Request(sSflPersonaChangeSpritePath, 0);
    *puVar1 |= 0x10;
}
