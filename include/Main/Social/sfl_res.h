#ifndef SFL_RES_H
#define SFL_RES_H

#include "Utils.h"

void sflResDrawIndexedMesh(u32* work, const f32* vertices);
void sflResSetSpriteScale(void* work, const f32* value);
void sflResSetSpritePosition(void* work, const f32* value);
void sflResGetSpritePosition(const void* work, f32* value);
void sflResSetSpriteRotation(void* work, const f32* value);
void sflRes0020d6c0(void* work);
void sflRes0020d710(u32* work);
void sflRes0020d770(void* work, f32 value);
void sflResInit(void* work);
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
