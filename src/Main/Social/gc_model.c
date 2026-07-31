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


/* Removing this loses FUN_0020d820 (MATCH nd0 -> MISMATCH nd2) - measured W161. */



















void FUN_0021cc20();




