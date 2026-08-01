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


static SflResourceManager* sSflRes; // DAT_007ce2f0
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

static void sflResLoadRaster(u32 request, s32 fileIndex, u32* destination)
{
    u32 fileSize;
    void* file;

    file = H_Cdvd_ArchiveGetFile((void*)request, fileIndex, &fileSize);
    *destination = (u32)bpTexCreateTmxRaster(file);
}

static void sflResCopyFile(u32 request, s32 fileIndex, u32* destination)
{
    u32 fileSize;
    void* file;
    void* copy;

    file = H_Cdvd_ArchiveGetFile((void*)request, fileIndex, &fileSize);
    copy = (*DAT_00960178)(fileSize, 0x40000);
    if (copy != NULL && file != NULL) {
        memcpy(copy, file, fileSize);
    }
    *destination = (u32)copy;
}









// FUN_0020d7d0
void sflResInit(SflResourceManager* work)
{
    K_ASSERT(sSflRes == NULL, 0x6c);
    work->requestFlags = 0;
    work->loadedFlags = 0;
    sSflRes = work;
}

/* Removing this loses FUN_0020d820 (MATCH nd0 -> MISMATCH nd2) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0020d820 MATCHING
void sflResUpdate(void)
{
    SflResourceManager* work;
    void* file;
    void* copy;
    u32 fileSize;
    s32 i;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    if ((work->requestFlags & 1) != 0) {
        if (((~work->loadedFlags) & 2) == 0) {
            goto first_check;
        }
        if (H_Cdvd_IsFileLoaded(
                (void*)work->baseRequest) == 0)
            goto first_clear;
            for (i = 0; i < 0xf; i++) {
                switch (i) {
                case 0:
                    work->baseRasters[0] =
                        (u32)bpTexCreateTmxRaster(H_Cdvd_ArchiveGetFile(
                            (void*)work->baseRequest,
                            i, &fileSize));
                    break;
                case 1:
                    work->baseRasters[1] =
                        (u32)bpTexCreateTmxRaster(H_Cdvd_ArchiveGetFile(
                            (void*)work->baseRequest,
                            i, &fileSize));
                    break;
                case 2:
                    work->baseRasters[2] =
                        (u32)bpTexCreateTmxRaster(H_Cdvd_ArchiveGetFile(
                            (void*)work->baseRequest,
                            i, &fileSize));
                    break;
                case 3: {
                    void* file;
                    void* caseCopy;
                    file = H_Cdvd_ArchiveGetFile(
                        (void*)work->baseRequest,
                        i, &fileSize);
                    caseCopy = (*DAT_00960178)(fileSize, 0x40000);
                    work->baseSpriteData = (u32)caseCopy;
                    memcpy(caseCopy, file, *(volatile /* Removing this function's qualifier batch loses sflResUpdate (MATCH nd0 -> MISMATCH nd31, size 1980 -> 1980) - measured W170. */ u32*)&fileSize);
                    break;
                }
                case 4:
                    work->baseRasters[3] =
                        (u32)bpTexCreateTmxRaster(H_Cdvd_ArchiveGetFile(
                            (void*)work->baseRequest,
                            i, &fileSize));
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10: {
                    void* file;
                    file = H_Cdvd_ArchiveGetFile(
                        (void*)work->baseRequest,
                        i, &fileSize);
                    K_ASSERT(i - 5 >= 0, 0xa2);
                    K_ASSERT(i - 5 < 6, 0xa3);
                    work->baseSecondaryRasters[i - 5] =
                        (u32)bpTexCreateTmxRaster(file);
                    break;
                }
                case 11:
                    func_0021b4a0(H_Cdvd_ArchiveGetFile(
                        (void*)work->baseRequest,
                        i, &fileSize));
                    break;
                case 12:
                    work->baseRasters[4] =
                        (u32)bpTexCreateTmxRaster(H_Cdvd_ArchiveGetFile(
                            (void*)work->baseRequest,
                            i, &fileSize));
                    break;
                case 13: {
                    void* file;
                    void* copy;
                    file = H_Cdvd_ArchiveGetFile(
                        (void*)work->baseRequest,
                        i, &fileSize);
                    copy = (*DAT_00960178)(fileSize, 0x40000);
                    memcpy(copy, file, *(volatile /* Removing this function's qualifier batch loses sflResUpdate (MATCH nd0 -> MISMATCH nd31, size 1980 -> 1980) - measured W170. */ u32*)&fileSize);
                    work->baseDataFiles[0] = (u32)copy;
                    break;
                }
                case 14: {
                    void* file;
                    void* copy;
                    file = H_Cdvd_ArchiveGetFile(
                        (void*)work->baseRequest,
                        i, &fileSize);
                    copy = (*DAT_00960178)(fileSize, 0x40000);
                    memcpy(copy, file, *(volatile /* Removing this function's qualifier batch loses sflResUpdate (MATCH nd0 -> MISMATCH nd31, size 1980 -> 1980) - measured W170. */ u32*)&fileSize);
                    work->baseDataFiles[1] = (u32)copy;
                    break;
                }
                default:
                    K_ASSERT(0, 0xbb);
                    break;
                }
            }
            H_Cdvd_Destroy((void*)work->baseRequest);
            work->loadedFlags |= 2;
            goto first_clear;
    first_check:
        K_ASSERT((work->loadedFlags & 2) != 0, 0xc6);
    first_clear:
        if ((work->loadedFlags & 2) != 0) {
            work->requestFlags &= ~1u;
        }
    }
    if ((work->requestFlags & 2) != 0) {
        if (H_Cdvd_IsFileLoaded((void*)work->groundRequest) != 0) {
            K_ASSERT(((~work->loadedFlags) & 1) != 0, 0xd2);
            sflResLoadGroundRasters(
                *(void**)((u8*)work->groundRequest + 0x110));
            H_Cdvd_Destroy((void*)work->groundRequest);
            work->loadedFlags |= 1;
            work->requestFlags &= ~2u;
        }
    }
    if ((work->requestFlags & 4) != 0) {
        s32 j;
        if (((~work->loadedFlags) & 4) == 0) {
            goto four_check;
        }
        if (H_Cdvd_IsFileLoaded((void*)work->effectRequest) == 0) {
            goto four_done;
        }
        for (j = 0; j < 6; j++) {
            switch (j) {
            case 0:
                work->effectRasters[0] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            case 1:
                work->effectRasters[1] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            case 2:
                work->effectRasters[2] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            case 3:
                work->effectRasters[3] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            case 4:
                work->effectRasters[4] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            case 5:
                work->effectRasters[5] = (u32)bpTexCreateTmxRaster(
                    H_Cdvd_ArchiveGetFile(
                        (void*)work->effectRequest, j, &fileSize));
                break;
            default:
                K_ASSERT(0, 0xfe);
                break;
            }
        }
        H_Cdvd_Destroy((void*)work->effectRequest);
        work->loadedFlags |= 4;
        goto four_done;
    four_check:
        K_ASSERT((work->loadedFlags & 4) != 0, 0x109);
    four_done:
        if ((work->loadedFlags & 4) != 0) {
            work->requestFlags &= ~4u;
        }
    }
    if ((work->requestFlags & 8) != 0 &&
        H_Cdvd_IsFileLoaded((void*)work->tutorialRequest) != 0) {
        s32 k;
        for (k = 0; k < 2; k++) {
            switch (k) {
            case 0:
                file = H_Cdvd_ArchiveGetFile(
                    (void*)work->tutorialRequest, k, &fileSize);
                work->tutorialFiles[0] =
                    (u32)(*DAT_00960178)(fileSize, 0x40000);
                memcpy((void*)work->tutorialFiles[0], file, (s32)fileSize);
                break;
            case 1:
                file = H_Cdvd_ArchiveGetFile(
                    (void*)work->tutorialRequest, k, &fileSize);
                work->tutorialFiles[1] =
                    (u32)(*DAT_00960178)(fileSize, 0x40000);
                memcpy((void*)work->tutorialFiles[1], file, (s32)fileSize);
                break;
            }
            H_Cdvd_Destroy((void*)work->tutorialRequest);
            work->loadedFlags |= 8;
            work->requestFlags &= ~8u;
        }
    }
    if ((work->requestFlags & 0x10) != 0 &&
        H_Cdvd_IsFileLoaded((void*)work->personaChangeRequest) != 0) {
        work->personaChangeSprite = (u32)func_0021c9f0(
            *(void**)((u8*)work->personaChangeRequest + 0x110));
        H_Cdvd_Destroy((void*)work->personaChangeRequest);
        work->loadedFlags |= 0x10;
        work->requestFlags &= ~0x10u;
    }
}
#pragma opt_loop_invariants reset

// FUN_0020dfe0
u32 sflResIsBaseArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return (sSflRes)->requestFlags & 1;
}

// FUN_0020e030
void sflResShutdown(void)
{
    SflResourceManager* work;
    s32 i18_1;
    s32 i18_2;
    s32 i18_3;
    s32 i16_1;
    s32 i16_2;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    if ((work->loadedFlags & 8) == 0) {
        goto skip_8;
    }
    sflResDestroyTutorialFiles();
skip_8:
    if ((work->loadedFlags & 2) == 0) {
        goto skip_2;
    }
    {
        u32* callbacks;
        callbacks = (u32*)DAT_0096017c;
        ((void (*)(void*))callbacks[0])((void*)work->baseSpriteData);
        for (i18_1 = 0; i18_1 < 5; i18_1++) {
            func_004cde90((void*)*(u32*)((u32)work + i18_1 * sizeof(u32) +
                (u32)&((SflResourceManager*)0)->baseRasters));
        }
        for (i18_2 = 0; i18_2 < 6; i18_2++) {
            func_004cde90((void*)*(u32*)((u32)work + i18_2 * sizeof(u32) +
                (u32)&((SflResourceManager*)0)->baseSecondaryRasters));
        }
        for (i18_3 = 0; i18_3 < 2; i18_3++) {
            ((void (*)(void*))callbacks[0])(
                (void*)*(u32*)((u32)work + i18_3 * sizeof(u32) +
                    (u32)&((SflResourceManager*)0)->baseDataFiles));
        }
    }
skip_2:
    if ((work->loadedFlags & 1) == 0) {
        goto skip_1;
    }
    for (i16_1 = 0; i16_1 < 3; i16_1++) {
        func_004cde90((void*)*(u32*)((u32)work + i16_1 * sizeof(u32) +
            (u32)&((SflResourceManager*)0)->groundRasters));
    }
skip_1:
    if ((work->loadedFlags & 4) == 0) {
        goto skip_4;
    }
    for (i16_2 = 0; i16_2 < 6; i16_2++) {
        func_004cde90((void*)*(u32*)((u32)work + i16_2 * sizeof(u32) +
            (u32)&((SflResourceManager*)0)->effectRasters));
    }
skip_4:
    if ((work->loadedFlags & 0x10) != 0) {
        sflResDestroyPersonaChangeSprite();
    }
    sSflRes = NULL;
}

// FUN_0020e200
void sflResRequestBaseArchive(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work->loadedFlags & 2) != 0, 0x180);
    K_ASSERT((~work->requestFlags & 1) != 0, 0x181);
    work->baseRequest = (u32)H_Cdvd_Request(sSflBaseArchivePath, 1);
    work->requestFlags |= 1;
}

// FUN_0020e2c0
void sflResRequestGroundArchive(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work->loadedFlags & 1) != 0, 0x18a);
    K_ASSERT((~work->requestFlags & 2) != 0, 0x18b);
    work->groundRequest = (u32)H_Cdvd_Request(sSflGroundArchivePath, 0);
    work->requestFlags |= 2;
}

// FUN_0020e380
u32 sflResIsGroundArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return (sSflRes)->requestFlags & 2;
}

// FUN_0020e3d0
void sflResRequestEffectArchive(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);;
    work = sSflRes;
    K_ASSERT((~work->loadedFlags & 4) != 0, 0x19b);
    K_ASSERT((~work->requestFlags & 4) != 0, 0x19c);
    if (datGetScenarioMode() != 0) {
        work->effectRequest =
            (u32)H_Cdvd_Request(sSflEpisodeAigisEffectArchivePath, 1);
    } else {
        work->effectRequest = (u32)H_Cdvd_Request(sSflEffectArchivePath, 1);
    }
    work->requestFlags |= 4;
}

// FUN_0020e4c0
u32 sflResIsEffectArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);;
    return (sSflRes)->requestFlags & 4;
}

// FUN_0020e510
void* sflResGetBaseRaster(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 2) != 0, 0x1b7);
    return (void*)work->baseRasters[index];
}

// FUN_0020e590
void* sflResGetGroundRaster(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 1) != 0, 0x1be);
    return (void*)work->groundRasters[index];
}

// FUN_0020e610
void* sflResGetBaseSecondaryRaster(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 2) != 0, 0x1c5);
    return (void*)work->baseSecondaryRasters[index];
}

// FUN_0020e690
void* sflResGetEffectRaster(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 4) != 0, 0x1cc);
    return (void*)work->effectRasters[index];
}

// FUN_0020e710
void* sflResGetBaseDataFile(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 2) != 0, 0x1d3);
    return (void*)work->baseDataFiles[index];
}

// FUN_0020e790
void* sflResGetBaseSpriteData(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 2) != 0, 0x1da);
    return (void*)work->baseSpriteData;
}

// FUN_0020e800
void sflResLoadGroundRasters(void* resource)
{
    SflResourceManager* work;
    u8* data;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((~work->loadedFlags & 1) != 0, 0x1e3);
    K_ASSERT(*(u16*)((u8*)resource + 4) == 3, 0x1e7);
    data = (u8*)resource + 8;
    work->groundRasters[0] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)data);
    work->groundRasters[1] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)(data + 8));
    work->groundRasters[2] = (u32)bpTexCreateTmxRaster(
        (u8*)resource + *(s32*)(data + 0x10));
    work->loadedFlags |= 1;
}

// FUN_0020ea00
void* sflResGetTutorialFile(s32 index)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((work->loadedFlags & 8) != 0, 0x203);
    return (void*)work->tutorialFiles[index];
}

// FUN_0020e9b0
u32 sflResIsTutorialArchivePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return (sSflRes)->requestFlags & 8;
}

// FUN_0020ea80
void sflResDestroyTutorialFiles(void)
{
    SflResourceManager* work;
    int i;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT(work->loadedFlags & 8, 0x20c);
    for (i = 0; i < 2; i++) {
        RwFree((void*)*(u32*)((u32)work + i * sizeof(u32) +
            (u32)&((SflResourceManager*)0)->tutorialFiles));
    }
    work->loadedFlags &= 0xfffffff7;
}

// FUN_0020ec00
u32 sflResIsPersonaChangeSpritePending(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return (sSflRes)->requestFlags & 0x10;
}

void FUN_0021cc20();

// FUN_0020ec50
u32 sflResGetPersonaChangeSprite(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT(work->loadedFlags & 0x10, 0x22a);
    return work->personaChangeSprite;
}

// FUN_0020ecc0
void sflResDestroyPersonaChangeSprite(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT(work->loadedFlags & 0x10, 0x232);
    FUN_0021cc20((void*)work->personaChangeSprite);
    work->loadedFlags &= 0xffffffef;
}

// FUN_0020e8f0
void sflResRequestTutorialArchive(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((~work->loadedFlags & 8) != 0, 0x1f2);
    K_ASSERT((~work->requestFlags & 8) != 0, 0x1f3);
    work->tutorialRequest =
        (u32)(uintptr_t)H_Cdvd_Request(sSflTutorialArchivePath, 1);
    work->requestFlags |= 8;
}

// FUN_0020eb40
void sflResRequestPersonaChangeSprite(void)
{
    SflResourceManager* work;

    K_ASSERT(sSflRes != NULL, 0x65);
    work = sSflRes;
    K_ASSERT((~work->requestFlags & 0x10) != 0, 0x218);
    K_ASSERT((~work->loadedFlags & 0x10) != 0, 0x219);
    work->personaChangeRequest =
        (u32)(uintptr_t)H_Cdvd_Request(sSflPersonaChangeSpritePath, 0);
    work->requestFlags |= 0x10;
}


#include "Main/Battle/Panel/bpp_panel.h"
#include "Main/Battle/Cmd/bpp_main.h"
static u32* sBppMain; // DAT_007ce2f4
void bppMain0020f680(void);
u8* bppMain0020f720(s16 pcId);
#pragma alias bppMain0020f720_u16 bppMain0020f720
extern u8* bppMain0020f720_u16(u16 pcId);

extern void* btlOrderGetActionPlaying(void);
extern u32 func_0029b0c0(void* action);
extern s32 bpMisc001ff5b0(void);
extern s16 func_001ff630(s32 index);
extern void* func_001ff430(u32 id);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u32 datGetBadStatusNoDown(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern u16 datGetPhysicalCondition(s16 pcId);
extern void func_0022c720(void* panel, u16 pcId);
extern void func_0022c850(void* panel);
extern void func_0022c8a0(void* panel);
extern void func_0022df10(void* panel);
extern void func_0022e780(void* panel);
extern void func_0022e900(void* panel, u32 value);
extern void func_0022e9a0(void* panel, u32 value);
extern void func_0022f1c0(void* panel, u32 value);

#define BPP_MAIN_ENTRY_STRIDE 0x1690
#define BPP_MAIN_ENTRY_BASE 0x10

static u8* bppMainEntry(s32 index)
{
    return (u8*)sBppMain + index * BPP_MAIN_ENTRY_STRIDE;
}

static u8* bppMainFindEntry(s16 pcId)
{
    s32 i;
    u8* entry;

    K_ASSERT(sBppMain != NULL, 0x43);
    for (i = 0; i < (s32)sBppMain[0x1694]; i++) {
        entry = bppMainEntry(i);
        if (*(s16*)(entry + 0x14) == pcId) {
            return entry + BPP_MAIN_ENTRY_BASE;
        }
    }
    K_ASSERT(0, 0x19c);
    return NULL;
}

static void bppMainSetDetailForUnit(u32* work, void* unit)
{
    s16 pcId;
    u8* entry;

    if (unit == NULL || *(u8*)((u8*)unit + 0xa2) != 0) {
        return;
    }
    pcId = *(s16*)((u8*)unit + 0xa2c + 2);
    entry = bppMainFindEntry(pcId);
    bppPanelActivateDetail((BppPanelWork*)(entry + 0x20));
    work[0x1696] = (u32)(u16)pcId;
    *work |= 4;
}

static void bppMainClearDetailForUnit(u32* work, void* unit)
{
    s16 pcId;
    u8* entry;

    if (unit == NULL || *(u8*)((u8*)unit + 0xa2) != 0) {
        return;
    }
    pcId = *(s16*)((u8*)unit + 0xa2c + 2);
    entry = bppMainFindEntry(pcId);
    bppPanelDeactivateDetail((BppPanelWork*)(entry + 0x20));
    *work &= ~4u;
}

// FUN_0020ed50
void bppMain0020ed50(u32* work)
{
    work[0] = 0;
    work[0x1694] = 0;
    work[0x1697] = 0;
    work[0x1698] = 0;
    sBppMain = work;
}



/* Removing this worsens bppMain0020edf0 (nd135 -> nd794) - measured W161. */




static inline u8* bppMainLookupEntry(s16 pcId)
{
    s32 i;
    u8* entry;
    u32* work;
    u32 id;
    u8* result;
    s32 count;
    s32 stride;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    i = 0;
    id = (u16)pcId;
    count = (s32)work[0x1694];
    stride = BPP_MAIN_ENTRY_STRIDE;
    for (; i < count; i++) {
        entry = (u8*)work + i * stride;
        result = entry + BPP_MAIN_ENTRY_BASE;
        if (*(u16*)(entry + 0x14) == id) {
            return result;
        }
    }
    K_ASSERT(0, 0x19c);
    return NULL;
}

/* Removing this loses bppMain0020f720 (MATCH nd0 -> MISMATCH nd23); loses bppMain0020f7d0 (MATCH nd0 -> MISMATCH nd28); loses bppMain0020f8b0 (MATCH nd0 -> MISMATCH nd28); loses bppMain0020f9a0 (MATCH nd0 -> MISMATCH nd24); loses bppMain0020fa80 (MATCH nd0 -> MISMATCH nd24); loses bppMain0020fb60 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
