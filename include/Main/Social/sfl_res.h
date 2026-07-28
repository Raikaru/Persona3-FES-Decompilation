#ifndef SFL_RES_H
#define SFL_RES_H

#include "Utils.h"

/*
 * Layout recovered from every observed SflResourceManager access in the
 * source tree. All fields are four-byte words in the original code; handles
 * remain u32 so the recovered layer preserves the observed lw/sw width and
 * does not silently impose host pointer semantics. No unobserved gaps occur.
 */
typedef struct SflResourceManager
{
    u32 requestFlags;                  // 0x00
    u32 loadedFlags;                   // 0x04
    u32 groundRasters[3];              // 0x08
    u32 baseRasters[5];                // 0x14
    u32 baseSecondaryRasters[6];       // 0x28
    u32 effectRasters[6];              // 0x40
    u32 baseSpriteData;                // 0x58
    u32 tutorialFiles[2];              // 0x5c
    u32 groundRequest;                 // 0x64
    u32 baseRequest;                   // 0x68
    u32 effectRequest;                 // 0x6c
    u32 tutorialRequest;               // 0x70
    u32 personaChangeRequest;          // 0x74
    u32 baseDataFiles[2];              // 0x78
    u32 personaChangeSprite;           // 0x80
} SflResourceManager;

typedef char SflResourceManager_size_must_be_0x84[
    sizeof(SflResourceManager) == 0x84 ? 1 : -1];

void sflResDrawIndexedMesh(u32* work, const f32* vertices);
void sflResSetSpriteScale(void* work, const f32* value);
void sflResSetSpritePosition(void* work, const f32* value);
void sflResGetSpritePosition(const void* work, f32* value);
void sflResSetSpriteRotation(void* work, const f32* value);
void sflRes0020d6c0(void* work);
void sflRes0020d710(u32* work);
void sflRes0020d770(void* work, f32 value);
void sflResInit(SflResourceManager* work);
void sflResUpdate(void);
u32 sflResIsBaseArchivePending(void);
void sflResShutdown(void);
void sflResRequestBaseArchive(void);
void sflResRequestGroundArchive(void);
u32 sflResIsGroundArchivePending(void);
void sflResRequestEffectArchive(void);
u32 sflResIsEffectArchivePending(void);
void* sflResGetBaseRaster(s32 index);
void* sflResGetGroundRaster(s32 index);
void* sflResGetBaseSecondaryRaster(s32 index);
void* sflResGetEffectRaster(s32 index);
void* sflResGetBaseDataFile(s32 index);
void* sflResGetBaseSpriteData(void);
void sflResLoadGroundRasters(void* resource);
void sflResRequestTutorialArchive(void);
u32 sflResIsTutorialArchivePending(void);
void* sflResGetTutorialFile(s32 index);
void sflResDestroyTutorialFiles(void);
void sflResRequestPersonaChangeSprite(void);
u32 sflResIsPersonaChangeSpritePending(void);
u32 sflResGetPersonaChangeSprite(void);
void sflResDestroyPersonaChangeSprite(void);

#endif
