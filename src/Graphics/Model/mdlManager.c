#include "Graphics/Model/mdlManager.h"
#include "Graphics/Model/mdlFile.h"
#include "rw/rpworld.h"
#include "rw/rphanim.h"
#include "temporary.h"
#include "h_cdvd.h"

f32 gFrameDuration = (1.0f / 30.0f);   // 007cadd4. 33.3ms. Not sure where to place this

static Model* sMdlListTails[MODEL_TYPE_MAX]; // 009571f0. Tails of each model type
typedef struct MdlShortVec8 {
    short values[8];
} MdlShortVec8;
typedef struct MdlShortVec10 {
    short values[10];
} MdlShortVec10;

void mdlStreamInit(Model* mdl);
void mdlStreamSetRmdFileMemory(Model* mdl, const MdlRmdFileMemory* rmd);
void mdlStreamRequestCdvd(Model* mdl, const char* path);
void mdlStreamDestroy(Model* mdl);
void mdl003196d0(Model* mdl, u16 wpnIdx, s32 value);
void mdl00319900(Model* mdl, u32 value);
extern RtAnimAnimation DAT_009571d0;
#pragma alias DAT_009571d0_abs DAT_009571d0
extern u8 DAT_009571d0_abs[];
extern u8 DAT_0069abb8[];
extern void* jtbl_00960178[];

extern RwMatrix* FUN_004c2f30(RwMatrix* dst, const RwMatrix* left, const RwMatrix* right);
extern RwV3d* FUN_004c6be0(RwV3d* dst, const RwV3d* src, const RwMatrix* matrix);
extern s32 func_001a6c00(void* object, const char* name);
extern char DAT_007cca08[1];
#pragma alias DAT_007cca08_abs DAT_007cca08
extern char DAT_007cca08_abs[];
extern const char DAT_0069b210[];
extern char DAT_007cca18[1];
extern char DAT_007cca10[1];
#define MDL_PATH_FORMAT(addr) (DAT_0069b210 + ((addr) - 0x69b210))
void* FUN_00491cc0(RpClump* clump);
void FUN_00491ea0(RpClump* clump);
void* FUN_001a7570(RpClump* clump);
void FUN_001a7710(void* object);
void FUN_001ef340(Model* mdl);
void FUN_004cb6e0(void* object, void (*callback)(void), void* data);
void FUN_001a7170(RpClump* clump, RpHAnimHierarchy* hierarchy);
RpHAnimHierarchy* FUN_00466480(RpHAnimHierarchy* hierarchy, u32 flags, u32 value, s32 index);
void* func_0031d700(void* resource);
void func_00320290(void* resource);
void* func_0031e0b0(void* resource);
void func_00313230(MdlAnimSlot* slot);
void func_003132c0(u8* slot);
void func_00313be0(MdlAnimEntryTable* table);
void func_00313e60(void* data);
void func_003143c0(u8* state, RpClump* clump);
void func_00314d30(void* state);
void func_00314730(u8* state, f32 frame);
#pragma alias func_00314730_ptrfirst func_00314730
void func_00314730_ptrfirst(u8* state, f32 frame);
void func_00314850(RpClump* clump, void* state, s16 id, u16 blendFrameCount, u16 flags);
void func_003138e0(MdlAnim* anim, s16 id, u16 blendFrameCount, u16 flags);
void* func_00313490(MdlAnimSlot* slot, void* hierarchy);
u32 func_00318620(Model* mdl, u16 slotIdx, s16 id);
void func_003196f0(Model* mdl, u16 wpnIdx);
void func_003197c0(Model* mdl, RwMatrix* matrix);
u32 func_0031b220(Model* mdl);
u32 func_0031ebe0(void* data);
void func_0031ded0(void* data);
void func_0031ee80(void* dst, const void* src);
void func_0031eee0(void* data);
void func_0031eeb0(void* data);
void func_0031dda0(void* data, const RwV3d* scale);
void func_0031d9c0(void* data, Model* mdl);
void func_0031ef80(void* data, s16 id, u16 blendFrameCount);
void FUN_004cb7f0(RwFrame* frame, const RwMatrix* matrix, u32 flags);
void FUN_004b74c0(f32 frame, RtAnimInterpolator* interpolator);
#pragma alias func_004b74c0_typed func_004b74c0
extern void func_004b74c0_typed(f32 frame, void* interpolator);
#pragma alias func_004b74c0_frame FUN_004b74c0
extern void func_004b74c0_frame(f32 frame, u32 interpolator);
#pragma alias func_004b74c0_ptrfirst FUN_004b74c0
extern void func_004b74c0_ptrfirst(u32 interpolator, f32 frame);
#pragma alias func_004b7240_frame FUN_004b7240
extern u32 func_004b7240_frame(f32 frame, u32 interpolator);
#pragma alias func_00320640_frame FUN_00320640
extern void func_00320640_frame(u32 arg0, f32 frame, u32 interpolator);
extern f32 func_00320810(void* animation);
void func_00316970(Model* mdl);
u32 func_003115a0(void* param_1, u32* param_2);
u32 func_00318d10(u8* mdl, u32 slot, u32* matrix);
void func_00311480(MdlAnimResourceSet* resources, Model* mdl);
extern void func_004932c0(u32 object, u32 arg1, u32 arg2);
#pragma alias func_004916d0_typed func_004916d0
extern void func_004916d0_typed(u64 object, void* callback, void* data);
#pragma alias func_004916d0_callback func_004916d0
extern void func_004916d0_callback(RpClump* object, void (*callback)(void), void* data);
void func_0031f5c0(void* data);

/* Removing this loses FUN_00311310 (MATCH nd0 -> MISMATCH nd178) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00311310
MdlAnimEntryTable* mdlCreateAnimEntryTable(u16 animCount)
{
    MdlAnimEntryTable* table;
    u32 size;
    u32 i;
    f32 one;
    u32 matrixFlags;

    size = animCount * sizeof(MdlAnimEntry) + sizeof(MdlAnimEntryTable);
    table = (MdlAnimEntryTable*)RwMalloc(size, rwMEMHINTDUR_GLOBAL);
    memset(table, 0, size);

    table->entries = (MdlAnimEntry*)((u8*)table + sizeof(MdlAnimEntryTable));
    table->count = animCount;

    one = 1.0f;
    matrixFlags = rwMATRIXINTERNALIDENTITY | rwMATRIXTYPEORTHONORMAL;
    for (i = 0; i < table->count; i++)
    {
        table->entries[i].identityMat.right.x = table->entries[i].identityMat.up.y =
            table->entries[i].identityMat.at.z = one;
        table->entries[i].identityMat.right.y = table->entries[i].identityMat.right.z =
            table->entries[i].identityMat.up.x = 0.0f;
        table->entries[i].identityMat.up.z = table->entries[i].identityMat.at.x =
            table->entries[i].identityMat.at.y = 0.0f;
        table->entries[i].identityMat.pos.x = table->entries[i].identityMat.pos.y =
            table->entries[i].identityMat.pos.z = 0.0f;
        table->entries[i].identityMat.flags |= matrixFlags;
    }

    table->unk_06 = 1;

    return table;
}
#pragma opt_loop_invariants off

void FUN_0048a2a0(void);

// FUN_00311610
void* mdl00311610(void* param_1)
{
    FUN_0048a2a0();
    return param_1;
}

void FUN_004916d0();
u64 FUN_00316410(u64 param_1);

// FUN_003164c0
void mdl003164c0(void* param_1)
{
    FUN_004916d0(param_1, (void(*)())FUN_00316410, 0);
}

// FUN_00316690
Model* mdlInit(u16 type, u16 id)
{
    Model* mdl;
    u32 i;
    volatile /* Removing this qualifier loses mdlInit (MATCH nd0 -> MISMATCH nd8, size 628 -> 628) - measured W170. */ RwRGBA* color;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    Model* tail;

    mdl = ((void* (*)(u32, u32))jtbl_00960178[0])(sizeof(Model), rwMEMHINTDUR_GLOBAL);
    memset(mdl, 0, sizeof(Model));

    mdl->flags = MDL_FLAG_FOG | MDL_FLAG_ZTEST | MDL_FLAG_ZWRITE;
    mdl->color.r = 0xff;
    mdl->color.g = 0xff;
    mdl->color.b = 0xff;
    mdl->color.a = 0xff;
    color = &mdl->color;
    red = color->r;
    green = color->g;
    blue = color->b;
    alpha = color->a;
    mdl->runtimeData.animationData[0x22] = red;
    mdl->runtimeData.animationData[0x23] = green;
    mdl->runtimeData.animationData[0x24] = blue;
    mdl->runtimeData.animationData[0x25] = alpha;
    mdl->type = type;
    mdl->id = id;
    mdl->gsAlpha1Reg = 0x44;
    mdl->gsTest1Reg = 0x717fb;

    RwMatrixSetIdentity(&mdl->mat);
    RwMatrixSetIdentity(&mdl->identityMat);
    mdl->scale.x = 1.0f;
    mdl->scale.y = 1.0f;
    mdl->scale.z = 1.0f;
    *(u16*)((u8*)mdl + 0x418) = 2;

    for (i = 0; i < 4; i++)
    {
        func_00313230(&mdl->animSlots[i]);
    }
    *(u32*)((u8*)mdl + 0x360) = 0;

    *(u8*)((u8*)mdl + 0x366) = 1;
    *(s16*)((u8*)mdl + 0x368) = -1;
    *(f32*)((u8*)mdl + 0x36c) = 1.0f;
    memset((u8*)mdl + 0x380, 0, 8);
    *(u8*)((u8*)mdl + 0x382) = 1;
    *(f32*)((u8*)mdl + 0x384) = 1.0f;
    *(u8*)((u8*)mdl + 0x388) = 0;
    *(u32*)((u8*)mdl + 0x39c) = 0;
    *(u32*)((u8*)mdl + 0x3a0) = 0;
    *(u32*)((u8*)mdl + 0x3a4) = 0;
    *(u8*)((u8*)mdl + 0x3a8) = 0xa0;
    *(u8*)((u8*)mdl + 0x3a9) = 0xa0;
    *(u8*)((u8*)mdl + 0x3aa) = 0;

    func_0031eeb0(mdl->runtimeData.animationData);

    for (i = 0; i < 5; i++)
    {
        mdl003196d0(mdl, i, -1);
    }

    tail = sMdlListTails[type];
    mdl->next = NULL;
    if (tail != NULL)
    {
        tail->next = mdl;
        mdl->prev = tail;
    }
    else
    {
        mdl->prev = NULL;
    }
    sMdlListTails[type] = mdl;

    return mdl;
}

#pragma push
/* Removing this loses FUN_00316910 (MATCH nd0 -> MISMATCH nd26) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00316910. Search a model in list by its type, id and flags. Set 'flags' to 0 if no flag filter
Model* mdlSearch(u16 type, u16 id, u16 flags)
{
    Model* mdl;
    u16 modelType;
    u16 modelId;
    u16 modelFlags;

    modelType = type;
    modelId = id;
    modelFlags = flags;
    mdl = sMdlListTails[modelType];

    while (mdl != NULL)
    {
        if (mdl->id == modelId)
        {
            if (modelFlags == 0 || (mdl->flags & modelFlags) != 0)
            {
                break;
            }
        }

        mdl = mdl->prev;
    }

    return mdl;
}
#pragma pop

// FUN_00316b40
Model* mdlCreateFromPath(u16 type, u16 id, const char* path, u32 readMode)
{
    Model* mdl;

    mdl = mdlInit(type, id);

    if (readMode & MDL_READSYNC)
    {
        mdl->flags |= MDL_FLAG_STREAMSYNC;
    }

    mdlStreamInit(mdl);
    mdlStreamRequestCdvd(mdl, path);

    mdlStreamRead(mdl);

    return mdl;
}

// FUN_00316bd0. Create a model with a loaded .RMD file in memory
Model* mdlCreateFromRmdMemory(u16 type, u16 id, void* rmdMemory, u32 rmdSize, u32 readMode)
{
    Model* mdl;
    MdlRmdFileMemory rmd;

    mdl = mdlInit(type, id);

    if (readMode & MDL_READSYNC)
    {
        mdl->flags |= MDL_FLAG_STREAMSYNC;
    }

    mdlStreamInit(mdl);

    rmd.memory = rmdMemory;
    rmd.size = rmdSize;
    mdlStreamSetRmdFileMemory(mdl, &rmd);

    mdlStreamRead(mdl);

    return mdl;
}

/* W323 measured mdlCreateAndResolvePath opt_loop_invariants on: nd202 -> nd191; object 356/368. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00316e00 NONMATCHING
Model* mdlCreateAndResolvePath(u16 type, u16 id, u32 readMode)
{
    Model* mdl;
    char path[0x100];

    mdl = sMdlListTails[type];
    while (mdl != NULL && mdl->id != id)
    {
        mdl = mdl->prev;
    }
    if (mdl == NULL)
    {
        mdlFileResolvePackPath(type, id, path);
        mdl = mdlInit(type, id);

        if (readMode & MDL_READSYNC)
        {
            mdl->flags |= MDL_FLAG_STREAMSYNC;
        }

        mdlStreamInit(mdl);
        mdlStreamRequestCdvd(mdl, path);
        mdlStreamRead(mdl);

        if (mdlFileIsTypePac(type))
        {
            mdl00319900(mdl, true);
        }
    }
    else
    {
        mdl = mdlInit(type, id);

        if (readMode & MDL_READSYNC)
        {
            mdl->flags |= MDL_FLAG_STREAMSYNC;
        }

        mdl->flags |= MDL_FLAG_STREAMUNK1;
        mdlStreamRead(mdl);
    }

    return mdl;
}
#pragma pop

// FUN_00316f70
u32 mdlStreamRead(Model* mdl)
{
    Model* source;
    u32 modelId;
    if (mdl->flags & MDL_FLAG_STREAMDONE)
    {
        return true;
    }

    if ((mdl->flags & MDL_FLAG_STREAMUNK1) == 0)
    {
        if (!func_0031b220(mdl))
        {
            return false;
        }

        if (!func_0031ebe0(mdl->runtimeData.animationData))
        {
            return false;
        }

        mdlStreamDestroy(mdl);
        func_00316970(mdl);
    }
    else
    {
        if (!func_0031ebe0(mdl->runtimeData.animationData))
        {
            return false;
        }
        modelId = mdl->id;
        source = sMdlListTails[mdl->type];
        while (source != NULL)
        {
            if (source->id == modelId)
            {
                if (source->flags & MDL_FLAG_STREAMDONE)
                {
                    break;
                }
            }

            source = source->prev;
        }
        if (source == NULL)
        {
            return false;
        }

        mdlCopy(source, mdl);
        mdl->flags &= ~MDL_FLAG_STREAMUNK1;
    }

    mdl->flags |= MDL_FLAG_STREAMDONE;
    return true;
}

// FUN_003170c0 NONMATCHING
void mdlCopy(const Model* src, Model* dst)
{
    const MdlAnim* srcAnim;
    MdlAnim* dstAnim;
    MdlAnimResourceSet* resources;
    MdlAnimResourceSet* clonedResources;
    void* data;
    u32 i;
    u32 j;
    RpHAnimHierarchy* hierarchy;
    RpClump* clump;

    if (src->clump != NULL)
    {
        dst->clump = FUN_00491cc0(src->clump);
        dst->unk_e0 = FUN_001a7570(dst->clump);
    }

    for (i = 0; i < 4; i++)
    {
        if (mdlAnim003185b0((Model*)src, i))
        {
            srcAnim = &src->animSlots[i].anim;
            dstAnim = &dst->animSlots[i].anim;
            srcAnim->table->unk_06++;
            dstAnim->table = srcAnim->table;

            if ((srcAnim->flags & 2) == 0)
            {
                clump = dst->clump;
                hierarchy = NULL;
                FUN_004cb6e0(*(void**)((u8*)clump + 4), (void(*)())func_003115a0,
                              &hierarchy);
                dst->animSlots[i].anim.hierarchy = hierarchy;
                FUN_004916d0(clump, mdl00311610, 0);
                FUN_001a7170(clump, dst->animSlots[i].anim.hierarchy);
                dst->animSlots[i].anim.hierarchy->flags |= 0x3000;
            }
            else
            {
                dstAnim->flags |= 2;
                dstAnim->hierarchy = FUN_00466480(dst->animSlots[0].anim.hierarchy, 0,
                                                   dst->animSlots[0].anim.hierarchy->flags, -1);
            }
        }

        resources = src->animSlots[i].anim.resources;
        if (resources != NULL)
        {
            clonedResources = RwMalloc(resources->count * 8 + 0x34, rwMEMHINTDUR_GLOBAL);
            memset(clonedResources, 0, resources->count * 8 + 0x34);
            clonedResources->count = resources->count;
            clonedResources->primary = (void**)((u8*)clonedResources + 0x34);
            clonedResources->secondary = clonedResources->primary + resources->count;

            for (j = 0; j < resources->count; j++)
            {
                if (resources->primary[j] != NULL)
                {
                    clonedResources->primary[j] = func_0031d700(resources->primary[j]);
                }

                if (resources->secondary[j] != NULL)
                {
                    clonedResources->secondary[j] = func_0031e0b0(resources->secondary[j]);
                }
            }

            dst->animSlots[i].anim.resources = clonedResources;
        }
    }

    if (src->unk_35c != NULL)
    {
        (*(u16*)((u8*)src->unk_35c + 6))++;
        dst->unk_35c = src->unk_35c;
    }

    data = *(void**)((u8*)src + 0x37c);
    if (data != NULL)
    {
        (*(u16*)((u8*)data + 0xe))++;
        *(void**)((u8*)dst + 0x37c) = data;
        func_003143c0((u8*)dst + 0x364, dst->clump);
        *(u8*)((u8*)dst + 0x366) = 1;
    }

    data = src->runtimeData.refCountedData;
    if (data != NULL)
    {
        (*(u16*)((u8*)data + 2))++;
        dst->runtimeData.refCountedData = data;
    }

    if (src->runtimeData.motionData != NULL)
    {
        dst->runtimeData.motionData = func_0031d700(src->runtimeData.motionData);
        func_0031ded0(dst->runtimeData.motionData);
    }

    func_0031ee80(dst->runtimeData.animationData, src->runtimeData.animationData);

    if (mdlAnim003185b0(dst, 0))
    {
        mdlAnimSet(dst, 0, 0, 0, MDLANIM_FLAG_LOOP);
    }
}

// FUN_00317450
Model* mdlClone(const Model* mdl)
{
    Model* clone;

    clone = mdlInit(mdl->type, mdl->id);

    if (mdl->flags & MDL_FLAG_STREAMDONE)
    {
        mdlCopy(mdl, clone);

        clone->flags |= MDL_FLAG_STREAMDONE;
    }
    else
    {
        clone->flags |= MDL_FLAG_STREAMUNK1;
    }

    return clone;
}

// FUN_003174e0
void mdlDestroy(Model* mdl)
{
    void* data;
    u32 i;

    if (mdl->clump != NULL)
    {
        FUN_00491ea0(mdl->clump);
    }

    for (i = 0; i < 4; i++)
    {
        func_003132c0((u8*)&mdl->animSlots[i]);
    }

    if (mdl->unk_35c != NULL)
    {
        func_00313be0(mdl->unk_35c);
        mdl->unk_35c = NULL;
    }

    data = *(void**)((u8*)mdl + 0x37c);
    if (data != NULL)
    {
        func_00313e60(data);
        *(u32*)&mdl->unkData2[0x1c] = 0;
    }

    data = mdl->runtimeData.refCountedData;
    if (data != NULL)
    {
        *(u16*)((u8*)data + 2) = *(u16*)((u8*)data + 2) - 1;
        if (*(u16*)((u8*)data + 2) == 0)
        {
            RwFree(*(void**)((u8*)data + 4));
        }
    }
    if (mdl->unk_e0 != NULL)
    {
        FUN_001a7710(mdl->unk_e0);
    }

    for (i = 0; i < 5; i++)
    {
        if ((*(u8*)((u8*)mdl + i * sizeof(MdlAttachedWpn) + 0x3b4) & 1) != 0 &&
            *(Model**)((u8*)mdl + i * sizeof(MdlAttachedWpn) + 0x3b8) != NULL)
        {
            func_003196f0(mdl, i);
        }
    }

    FUN_001ef340(mdl);

    if (mdl->runtimeData.motionData != NULL)
    {
        func_0031d790(mdl->runtimeData.motionData);
    }
    func_0031eee0(mdl->runtimeData.animationData);

    if (mdl->prev != NULL)
    {
        mdl->prev->next = mdl->next;
    }
    if (mdl->next != NULL)
    {
        mdl->next->prev = mdl->prev;
    }
    else
    {
        sMdlListTails[mdl->type] = mdl->prev;
    }

    RwFree(mdl);
}

// FUN_00317730 NONMATCHING
void mdl00317730(Model* mdl)
{
    RwMatrix matrix;
    void* hierarchy;
    Model* wpnMdl;
    MdlAnimResourceSet* resources;
    RwFrame* frame;
    u32 i;

    if (mdl->flags & MDL_FLAG_STREAMDONE)
    {
        frame = *(RwFrame**)((u8*)mdl->clump + 4);
        FUN_004c2f30(&matrix, &mdl->identityMat, (const RwMatrix*)mdl);
        FUN_004cb7f0(frame, &matrix, 0);
        func_003197c0(mdl, &matrix);

        hierarchy = NULL;
        if (mdlLookAtIsActive(mdl))
        {
            mdlLookAtSetTargetScale(mdl, &mdl->scale);
        }
        for (i = 0; i < 4; i++)
        {
            if (mdlAnim003185b0(mdl, i))
            {
                hierarchy = func_00313490(&mdl->animSlots[i], hierarchy);
            }
        }

        func_00314d30((u8*)mdl + 0x364);
        if (mdl->runtimeData.motionData != NULL)
        {
            func_0031dda0(mdl->runtimeData.motionData, &mdl->scale);
            func_0031d9c0(mdl->runtimeData.motionData, mdl);
        }
        for (i = 0; i < 4; i++)
        {
            resources = mdl->animSlots[i].anim.resources;
            if (resources != NULL)
            {
                func_00311480(resources, mdl);
            }
        }
        func_0031f5c0(mdl->runtimeData.animationData);

        for (i = 0; i < 5; i++)
        {
            wpnMdl = mdl->attachedWpns[i].wpnMdl;
            if ((mdl->attachedWpns[i].flags & 1) != 0 && wpnMdl != NULL &&
                mdl00319770(mdl, i))
            {
                *(RwMatrix*)((u8*)wpnMdl + 0x40) = mdl->identityMat;
                if (mdl->attachedWpns[i].unk_08 == -1)
                {
                    wpnMdl->mat = mdl->mat;
                }
                else
                {
                    func_00318d10((u8*)mdl, mdl->attachedWpns[i].unk_08, (u32*)mdlGetMatrix(wpnMdl));
                }

                mdlAnimSetSpeed(wpnMdl, 0, mdl->animSlots[0].anim.speed);
                mdl00317730(wpnMdl);
            }
        }
    }
}

// FUN_003182d0 NONMATCHING
u32 mdlAnimSet(Model* mdl, u16 slotIdx, s16 id, u16 blendFrameCount, u16 flags)
{
    MdlAnim* anim;
    MdlAnimEntry* entry;
    u32 i;

    if (!func_00318620(mdl, slotIdx, id))
    {
        return true;
    }

    anim = &mdl->animSlots[slotIdx].anim;
    if (slotIdx == 0)
    {
        if (id < 0 || anim->table == NULL || id >= anim->table->count ||
            anim->table->entries[id].rtAnim == NULL ||
            anim->table->entries[id].rtAnim == &DAT_009571d0)
        {
            RwMatrixSetIdentity(&mdl->identityMat);
        }
        else
        {
            entry = &anim->table->entries[id];
            mdl->identityMat = entry->identityMat;
        }

        func_00314850(mdl->clump, (u8*)mdl + 0x364, id, blendFrameCount, flags);
    }

    func_003138e0(anim, id, blendFrameCount, flags);

    if (*(void**)mdl->runtimeData.animationData != NULL && (flags & 0x40) == 0 && slotIdx == 0)
    {
        func_0031ef80(mdl->runtimeData.animationData, id, blendFrameCount);
    }

    for (i = 0; i < 5; i++)
    {
        if ((mdl->attachedWpns[i].flags & 1) != 0 && mdl->attachedWpns[i].wpnMdl != NULL &&
            mdl00319770(mdl, i))
        {
            mdlAnimSet(mdl->attachedWpns[i].wpnMdl, 0, id, blendFrameCount, flags);
        }
    }

    return true;
}

// FUN_00318540
s16 mdlAnimGetId(Model* mdl, u16 slotIdx)
{
    if (mdlAnim003185b0(mdl, slotIdx))
    {
        return mdl->animSlots[slotIdx].anim.id;
    }

    return -1;
}

// FUN_003185b0
u32 mdlAnim003185b0(Model* mdl, u16 slotIdx)
{
    if (slotIdx == 0)
    {
        if (mdl->animSlots[0].anim.table == NULL && mdl->unk_35c == NULL)
        {
            return false;
        }
    }
    else
    {
        if (mdl->animSlots[slotIdx].anim.table == NULL)
        {
            return false;
        }
    }
    
    return true;
}

// FUN_00318770
void mdlAnim00318770(Model* mdl, u16 slotIdx, f32 frame)
{
    MdlAnimEntryTable* table;
    RpHAnimHierarchy* hierarchy;
    s16 id;
    f32 scaledFrame;
    u8* state;

    scaledFrame = gFrameDuration * frame;
    id = mdl->animSlots[slotIdx].anim.id;
    if (id >= 0)
    {
        table = mdl->animSlots[slotIdx].anim.table;
        if (table != NULL && id < table->count &&
            table->entries[id].rtAnim != NULL &&
            table->entries[id].rtAnim != (RtAnimAnimation*)DAT_009571d0_abs)
        {
            hierarchy = mdl->animSlots[slotIdx].anim.hierarchy;
            FUN_004b74c0(scaledFrame, ((volatile /* Removing this qualifier loses mdlAnim00318770 (MATCH nd0 -> MISMATCH nd8, size 256 -> 256) - measured W170. */ RpHAnimHierarchy*)hierarchy)->currentAnim);
            mdl->animSlots[slotIdx].anim.flags |= MDLANIM_FLAG_FRAMESET;
        }
    }

    if (slotIdx == 0)
    {
        state = (u8*)mdl + 0x364;
        func_00314730_ptrfirst(state, scaledFrame);
    }
}

// FUN_00318870
f32 mdlAnimGetDurationInFrame(Model* mdl, u16 slotIdx)
{
    f32 duration;

    if (mdl->animSlots[slotIdx].anim.id < 0)
    {
        duration = 0.0f;
    }
    else
    {
        if (mdl->animSlots[slotIdx].anim.hierarchy == NULL ||
           (mdl->animSlots[slotIdx].anim.hierarchy->currentAnim == NULL))
        {
            duration = 0.0f;
        }
        else
        {
            if (mdl->animSlots[slotIdx].anim.hierarchy->currentAnim->pCurrentAnim == NULL)
            {
                duration = 0.0f;
            }
            else
            {
                duration = mdl->animSlots[slotIdx].anim.hierarchy->currentAnim->pCurrentAnim->duration;
            }
        }
    }

    return duration / gFrameDuration;
}

// FUN_00318910
f32 mdlAnimGetDurationInFrameById(Model* mdl, u16 slotIdx, s16 animId)
{
    f32 duration;

    if (mdl->animSlots[slotIdx].anim.hierarchy == NULL)
    {
        duration = 0.0f;
    }
    else
    {
        duration = mdl->animSlots[slotIdx].anim.table->entries[animId].rtAnim->duration;
    }

    return duration / gFrameDuration;
}

// FUN_00318990
f32 mdlAnimGetCurrentFrame(Model* mdl, u16 slotIdx)
{
    f32 currTime;

    if (mdl->animSlots[slotIdx].anim.id < 0)
    {
        currTime = 0.0f;
    }
    else
    {
        currTime = mdl->animSlots[slotIdx].anim.currTime;
    }

    return currTime / gFrameDuration;
}

// FUN_003189f0
void mdlAnimSetSpeed(Model* mdl, u16 slotIdx, f32 speed)
{
    mdl->animSlots[slotIdx].anim.speed = speed;

    if (slotIdx == 0)
    {
        *(f32*)((u8*)mdl + 0x36c) = speed;
    }
}

// FUN_00318a30
void mdlTranslate(Model* mdl, const RwV3d* translation, RwOpCombineType combineOp)
{
    RwMatrixTranslate(&mdl->mat, translation, combineOp);
}

// FUN_00318a50
void mdlRotate(Model* mdl, const RwV3d* axis, f32 angle, RwOpCombineType combineOp)
{
    RwMatrixRotate(&mdl->mat, axis, angle, combineOp);
}

void FUN_004c3760(void);

// FUN_00318a70
void mdl00318a70(void)
{
    FUN_004c3760();
}

// FUN_00318a90
void mdlScale(Model* mdl, const RwV3d* scale, RwOpCombineType combineOp)
{
    mdl->scale = *scale;

    RwMatrixScale(&mdl->mat, scale, combineOp);
}

// FUN_00318ad0
void mdlSetColor(Model* mdl, const RwRGBA* color)
{
    mdl->color = *color;
}

// FUN_00318b00
RwRGBA* mdlGetColor(Model* mdl)
{
    return &mdl->color;
}

// FUN_00318b60
RwMatrix* mdlGetMatrix(Model* mdl)
{
    return &mdl->mat;
}

// FUN_00318b70
RwFrame* mdlGetClumpFrame(Model* mdl)
{
    return (RwFrame*)mdl->clump->object.parent;
}

// FUN_00318b80
RpClump* mdlGetClump(Model* mdl)
{
    return mdl->clump;
}

// FUN_00319010
void mdlEnableFullShadow(Model* mdl)
{
    mdl->flags |= MDL_FLAG_FULLSHADOW;
}

// FUN_00319030
void mdlDisableFullShadow(Model* mdl)
{
    mdl->flags &= ~MDL_FLAG_FULLSHADOW;
}

// FUN_00319050
void mdl00319050(Model* mdl)
{
    mdl->flags |= MDL_FLAG_UNK20;
}

// FUN_00319070
void mdl00319070(Model* mdl)
{
    mdl->flags &= ~MDL_FLAG_UNK20;
}

// FUN_00319090
void mdlLookAtSetBlendRotFactor(Model* mdl, f32 blendRotFactor)
{
    mdl->animSlots[0].lookAt.blendRotFactor = blendRotFactor;
}

// FUN_003190a0
void mdlLookAtSetMaxAngles(Model* mdl, f32 maxPitchAngle, f32 maxYawAngle)
{
    mdl->animSlots[0].lookAt.maxPitchAngle = maxPitchAngle;
    mdl->animSlots[0].lookAt.maxYawAngle = maxYawAngle;
}

// FUN_003190b0
void mdlLookAtSetTargetPosXYZ(Model* mdl, const RwV3d* target)
{
    mdl->animSlots[0].lookAt.flags |= MDLLOOKAT_FLAG_XYZ;
    mdl->animSlots[0].lookAt.flags &= ~(MDLLOOKAT_FLAG_XYZCS | MDLLOOKAT_FLAG_XY);
    mdl->animSlots[0].lookAt.flags &= ~MDLLOOKAT_FLAG_NOTARGET;

    mdl->animSlots[0].lookAt.targetPos = *target;
}

// FUN_00319100
void mdlLookAtSetTargetPosXYZCS(Model* mdl, const RwV3d* target)
{
    mdl->animSlots[0].lookAt.flags |= MDLLOOKAT_FLAG_XYZCS;
    mdl->animSlots[0].lookAt.flags &= ~(MDLLOOKAT_FLAG_XYZ | MDLLOOKAT_FLAG_XY);
    mdl->animSlots[0].lookAt.flags &= ~MDLLOOKAT_FLAG_NOTARGET;

    mdl->animSlots[0].lookAt.targetPos = *target;
}

// FUN_00319150
void mdlLookAtSetTargetPosXY(Model* mdl, f32 xTarget, f32 yTarget)
{
    mdl->animSlots[0].lookAt.flags |= MDLLOOKAT_FLAG_XY;
    mdl->animSlots[0].lookAt.flags &= ~(MDLLOOKAT_FLAG_XYZCS | MDLLOOKAT_FLAG_XYZ);
    mdl->animSlots[0].lookAt.flags &= ~MDLLOOKAT_FLAG_NOTARGET;

    mdl->animSlots[0].lookAt.targetPos.x = xTarget;
    mdl->animSlots[0].lookAt.targetPos.y = yTarget;
}

// FUN_00319190
void mdlLookAtDisableTarget(Model* mdl)
{
    mdl->animSlots[0].lookAt.flags |= MDLLOOKAT_FLAG_NOTARGET;
}

// FUN_003191b0
void mdl003191b0(Model* mdl)
{
    mdl->animSlots[0].lookAt.flags |= MDLLOOKAT_FLAG_UNK200;
}

// FUN_003191d0
u8 mdlLookAtIsActive(Model* mdl)
{
    return (mdl->animSlots[0].lookAt.flags & (MDLLOOKAT_FLAG_XYZCS |
                                              MDLLOOKAT_FLAG_XYZ   |
                                              MDLLOOKAT_FLAG_XY    | 
                                              MDLLOOKAT_FLAG_NOTARGET)) != 0;
}

// FUN_003191f0
void mdlLookAtSetFlags(Model* mdl, u16 flags)
{
    mdl->animSlots[0].lookAt.flags = flags;
}

// FUN_00319200
u16 mdlLookAtGetFlags(Model* mdl)
{
    return mdl->animSlots[0].lookAt.flags;
}

// FUN_00319210
void mdlLookAtSetTargetScale(Model* mdl, const RwV3d* scale)
{
    mdl->animSlots[0].lookAt.targetScale = *scale;
}

// FUN_003196d0
void mdl003196d0(Model* mdl, u16 wpnIdx, s32 value)
{
    mdl->attachedWpns[wpnIdx].unk_08 = value;
}

// FUN_00319770
u32 mdl00319770(Model* mdl, u16 wpnIdx)
{
    Model* wpnMdl;

    wpnMdl = mdl->attachedWpns[wpnIdx].wpnMdl;
    if (wpnMdl == NULL)
    {
        return true;
    }

    return mdlStreamRead(wpnMdl);
}

// FUN_00319840
void mdlStreamInit(Model* mdl)
{
    MdlStream* stream;

    stream = RwMalloc(sizeof(MdlStream), rwMEMHINTDUR_GLOBAL);
    mdl->stream = stream;
    memset(stream, 0, sizeof(MdlStream));
}

// FUN_003198a0
void mdlStreamSetRmdFileMemory(Model* mdl, const MdlRmdFileMemory* rmd)
{
    MdlStream* stream;
    stream = mdl->stream;

    stream->rmd.memory = rmd->memory;
    stream->rmd.size = rmd->size;
}

// FUN_003198c0
void mdlStreamRequestCdvd(Model* mdl, const char* path)
{
    MdlStream* stream;
    stream = mdl->stream;

    stream->cdvd = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    stream->rws = NULL;
}

// FUN_00319900
void mdl00319900(Model* mdl, u32 value)
{
    mdl->stream->isInPacFile = value;
}

// FUN_00319910
void mdlStreamDestroy(Model* mdl)
{
    if (mdl->stream->unk_0c != NULL)
    {
        RwFree(mdl->stream->unk_0c);
    }

    RwFree(mdl->stream);
    mdl->stream = NULL;
}


/* ---- Recovered range 0x311480-0x31D4F0 (Ghidra reference, pending match) ---- */
typedef struct MdlAnimResourceEntry
{
    void* resource;
    u8 flags;
    u8 unk_05[3];
} MdlAnimResourceEntry;

typedef int (*code)(...);
typedef u8 bool;
#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef CONCAT11
#define CONCAT11(hi, lo) ((u16)((((u16)(u8)(hi)) << 8) | (u8)(lo)))
#endif
extern s32 DAT_0096012c;
extern u8 LAB_00464760;
extern f32 DAT_009571c0;
extern f32 DAT_009571c4;
#pragma alias DAT_009571c0_abs DAT_009571c0
extern u8 DAT_009571c0_abs[];
#pragma alias DAT_009571c4_abs DAT_009571c4
extern u8 DAT_009571c4_abs[];
extern float fGpffff80d0;
extern float fGpffff80f4;
extern float fGpffff814c;
extern float fGpffff8048;
extern float fGpffff8118;
extern float fGpffff8050;
extern float fGpffff8054;
extern float fGpffff8058;
extern float fGpffff8150;
extern float fGpffff8154;
extern float fGpffff8158;
extern s32 DAT_009571b8;
extern float* DAT_009571bc;
extern code DAT_009571b0;
extern s32 DAT_009571b4;
#pragma alias DAT_009571b0_abs DAT_009571b0
extern code DAT_009571b0_abs[];
#pragma alias DAT_009571b4_abs DAT_009571b4
extern u8 DAT_009571b4_abs[];
#pragma alias DAT_009571b8_abs DAT_009571b8
extern u8 DAT_009571b8_abs[];
#pragma alias DAT_009571bc_abs DAT_009571bc
extern u8 DAT_009571bc_abs[];
extern float fGpffff80e4;
extern char gp0xffff9d10;
extern u8 LAB_003131f8;
extern f32 DAT_007cada4;
extern void (*DAT_0096017c[])(...);
extern u8 LAB_0031379c;
extern u8 LAB_00313790;
extern u8 LAB_00313b48;
extern u8 LAB_00314020;
extern u8 LAB_00314060;
#pragma alias LAB_00314020_abs LAB_00314020
extern u8 LAB_00314020_abs[];
#pragma alias LAB_00314060_abs LAB_00314060
extern u8 LAB_00314060_abs[];
extern u8 LAB_0031494c;
extern u8 LAB_003140a0;
extern u8 LAB_003140b0;
#pragma alias LAB_003140a0_abs LAB_003140a0
extern u8 LAB_003140a0_abs[];
#pragma alias LAB_003140b0_abs LAB_003140b0
extern u8 LAB_003140b0_abs[];
extern f32 DAT_007cadd4;
extern f32 DAT_007caf0c;
extern f32 DAT_007caf10;
extern f32 DAT_007cad38;
extern f32 DAT_007cae08;
extern f32 DAT_007cad40;
extern f32 DAT_007cad44;
extern f32 DAT_007caed0;
extern u32 DAT_007cada0;
extern void (*DAT_00960090[])(...);
 #pragma alias DAT_00960090_abs DAT_00960090
 extern u8 DAT_00960090_abs[];
extern void (*DAT_00960094[])(...);
extern u32 DAT_00960070;
extern f32 DAT_007caf08;
extern void* (*DAT_00960178[])(...);
extern u32 DAT_0069aee0;
extern u32 DAT_0069aee2;
extern u32 DAT_0069aee4;
extern u8 LAB_0031b594;
extern u8 gp0xffff9d20;
extern u32 DAT_0069af00;
extern u32 DAT_0069b190;
#pragma alias DAT_0069b190_abs DAT_0069b190
extern u8 DAT_0069b190_abs[];
extern u8 LAB_0031bfb8;
extern u32 DAT_0069b1b0;
#pragma alias DAT_0069b1b0_abs DAT_0069b1b0
extern u8 DAT_0069b1b0_abs[];
extern u32 DAT_0069b0d0;
#pragma alias DAT_0069b0d0_abs DAT_0069b0d0
extern u8 DAT_0069b0d0_abs[];
extern u32 DAT_0069b1c0;
#pragma alias DAT_0069b1c0_abs DAT_0069b1c0
extern u8 DAT_0069b1c0_abs[];
extern u32 DAT_0069b1d0;
#pragma alias DAT_0069b1d0_abs DAT_0069b1d0
extern u8 DAT_0069b1d0_abs[];
extern u32 DAT_0069b1e0;
#pragma alias DAT_0069b1e0_abs DAT_0069b1e0
extern u8 DAT_0069b1e0_abs[];
extern void* PTR_PTR_0069ae80[];
extern void* RpMaterialGetUserDataArray(void* material,int data);
extern char* RpUserDataArrayGetName(void* userData);
extern int RpUserDataArrayGetFormat(void* userData);
extern f32 func_0052e9e8(f32 value);
#pragma alias func_0052ea18_typed func_0052ea18
extern f32 func_0052ea18_typed(f32 x, f32 y);
u32 func_00311640(RtAnimInterpolator* param_2, RtAnimInterpolator* param_3,
                  RtAnimInterpolator* param_4, f32 param_1);
u32 func_00311730(u32 *param_1,u16 *param_2,u16 *param_3,int param_4);
void func_00312c70(u8* param_1,int param_2);
void func_00312d40(u8* param_1,u8* param_2);
void func_00312e80(int param_1);
u32 func_00312f90(u32 param_1);
u32 func_00313090(u32 param_1,u32 param_2);
void func_00313ca0(int *param_1,u32 param_2);
int func_00313f40(int param_1,void* param_2);
void* func_00313fe0(void* param_1,u32 *param_2);
void* func_003140c0(void* param_1,u16 *param_2);
void* func_00314170(void* param_1, void* param_2);
u32 func_003142b0(void* param_1);
void* func_00314510(void* param_1);
u32 func_00314650(u32 param_1);
void* func_00315010(void* object, void* data);
u32 func_00315090(RwMatrix* param_1,u16 *param_2,u16 param_3,int param_4);
void func_003151d0(Model* param_1);
void func_00315c20(int param_1);
Model* func_00315ed0(Model* param_1);
u32 func_00315f50(void* param_1,u32 *param_2);
void func_00316320(u64 param_1,u32* param_2,u16 param_3);
u32 func_00316360(void* param_1,u32 *param_2);
void func_003164f0(int param_1,int param_2);
void* func_003165e0(void* param_1);
Model* func_00316c70(u16 param_1,u16 param_2,void* param_3,u32 param_4);
void func_003176c0(Model* param_1);
u32 func_003186e0(int param_1,u32 param_2,short param_3);
void func_00318b10(u32 *param_1);
u32 func_00318b90(u32 param_1);
u32 func_00318d10(u8* param_1,u32 param_2,u32* param_3);
bool func_00318ed0(u8* param_1,u32 param_2,RwV3d *param_3);
u32 func_00318fc0(int param_1);
void func_00319230(int param_1,u16 param_2);
void func_00319490(int param_1,u32 param_2,u16 param_3,u16 param_4,u32 param_5);
void func_003195f0(int param_1,u32 param_2,Model* param_3);
u32 func_00319970(Model* param_1);
int func_0031aad0(Model* param_1);
void func_0031b470(void);
void func_0031b4a0(char* param_1,u16 param_2);
u32 func_0031b680(int param_1,int param_2,int *param_3,int *param_4);
void func_0031b820(u32 param_1,u32 param_2);
#pragma alias func_0031b680_u32ptr func_0031b680
extern u32 func_0031b680_u32ptr(int param_1,int param_2,u32 *param_3,u32 *param_4);
u32 func_0031be80(u32 param_1);
void func_0031c000(char* param_1,u32 param_2);
u32 func_0031c1d0(int param_1);
u32 func_0031c7e0(int param_1);
u32 func_0031c820(u16 param_1,u16 param_2,char* param_3);
void FUN_0031e4d0(int *param_1,u16 param_2,u16 param_3);

// FUN_00311480


void func_00311480(MdlAnimResourceSet* param_1,Model* param_2)
{
  int iVar1;
  u8 *p;

  p = (u8 *)param_1;
  iVar1 = *(int *)(p + 0x18);
  if (*(int *)(p + 0x1c) != iVar1) {
    if (iVar1 != 0) {
      func_0031df80(iVar1);
    }
    if (*(int *)(p + 0x1c) != 0) {
      func_0031ded0((void *)*(int *)(p + 0x1c));
    }
    *(u32 *)(p + 0x18) = *(u32 *)(p + 0x1c);
  }

  if ((*(int *)(p + 0x18) != 0) && (*(u16 *)(p + 0x30) == 0)) {
    func_0031dda0((void *)*(int *)(p + 0x18), (const RwV3d *)(p + 8));
    func_0031d9c0((void *)*(int *)(p + 0x18), param_2);
  }

  if (*(int *)(p + 0x2c) != 0) {
    iVar1 = *(int *)(p + 0x24);
    if (iVar1 != 0) {
      func_0031e2c0(iVar1);
    }
    if (*(int *)(p + 0x28) != 0) {
      func_0031e270(*(int *)(p + 0x28), param_2);
    }
    *(u32 *)(p + 0x24) = *(u32 *)(p + 0x28);
    *(u32 *)(p + 0x2c) = 0;
  }

  if ((*(int *)(p + 0x24) != 0) && (*(u16 *)(p + 0x30) == 0)) {
    func_0031e1b0(*(int *)(p + 0x24), param_2);
  }

  if (*(u16 *)(p + 0x30) > 0) {
    *(u16 *)(p + 0x30) = *(u16 *)(p + 0x30) + -1;
  }
}




// FUN_003115A0


u32 func_003115a0(void* param_1, u32* param_2)
{
    u32 value;

    value = func_00466710();
    if (value != 0)
    {
        goto store_value;
    }
    func_004cb6e0(param_1, (void (*)())func_003115a0, param_2);
    return (u32)param_1;
store_value:
    *param_2 = value;
    return 0;
}




// FUN_00311640
u32 func_00311640(RtAnimInterpolator* param_2, RtAnimInterpolator* param_3,
                  RtAnimInterpolator* param_4, f32 param_1)
{
    s32 frame;
    s32 offset2;
    s32 offset3;
    s32 offset4;
    f32 alpha;
    u8* out;
    u8* in1;
    u8* in2;
    u8* in2Out;
    offset2 = param_2->offsetInParent;
    offset3 = param_3->offsetInParent;
    offset4 = param_4->offsetInParent;
    for (frame = offset2; frame < param_2->numNodes + param_2->offsetInParent; frame++)
    {
        in2 = (u8*)(param_4->currentInterpKeyFrameSize * (frame - offset4) -
                     (0u - (u32)param_4)) + 0x4c;
        out = (u8*)(param_2->currentInterpKeyFrameSize * (frame - offset2) -
                    (0u - (u32)param_2));
        in1 = (u8*)(param_3->currentInterpKeyFrameSize * (frame - offset3) -
                    (0u - (u32)param_3));
        alpha = *(f32*)(in2 + 0x30);
        param_2->keyFrameBlendCB(out + 0x4c, in1 + 0x4c, in2,
                                 param_1 * alpha);
    }
    return 1;
}




// Matrix callback storage is contiguous to preserve all RenderWare matrix fields.
#pragma opt_propagation off
// FUN_00311730 NONMATCHING


u32 func_00311730(u32 *param_1,u16 *param_2,u16 *param_3,int param_4)



{

  u16 uVar1;

  u32 uVar2;

  code *pcVar3;

  u64 uVar4;

  float *pfVar5;

  u32 uVar6;

  long lVar7;

  u32 uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  float *pfVar12;

  float *pfVar13;

  bool bVar14;

  int iVar15;

  float *pfVar16;

  u32 *puVar17;

  u32 uVar18;

  int iVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;
  float qxx;
  float qyy;
  float qzz;
  float qyz;
  float qzx;
  float qxy;
  float qwx;
  float qwy;
  float qwz;

  int iStack_3a0;

  float quat380[4];
  float quat370[4];
  float quat360[4];
  float slerpWork[10];
  float quat320[4];

  RwMatrix rotation;

  u8 auStack_2d0 [64];

  u8 auStack_290 [64];

  u8 auStack_250 [16];

  u8 auStack_240 [48];

  RwMatrix matrix210;

  float afStack_1d0 [16];

  float afStack_190 [17];

  u32 auStack_14c [31];

  u32 auStack_d0 [16];

  u32 uStack_c4;

  u32 uStack_c0;

  u32 uStack_bc;

  u32 uStack_b8;

  u32 uStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  u32 uStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  float afStack_90 [16];

  RwV3d vector50;
  RwV3d vector40;
  RwV3d vector30;
  RwV3d vector20;
  RwV3d vector10;

  

#define fStack_210 matrix210.right.x
#define fStack_20c matrix210.right.y
#define fStack_208 matrix210.right.z
#define uStack_204 matrix210.flags
#define fStack_200 matrix210.up.x
#define fStack_1fc matrix210.up.y
#define fStack_1f8 matrix210.up.z
#define fStack_1f0 matrix210.at.x
#define fStack_1ec matrix210.at.y
#define fStack_1e8 matrix210.at.z
#define uStack_1e0 (*(u32*)&matrix210.pos.x)
#define uStack_1dc (*(u32*)&matrix210.pos.y)
#define uStack_1d8 (*(u32*)&matrix210.pos.z)
#define fStack_310 rotation.right.x
#define fStack_30c rotation.right.y
#define fStack_308 rotation.right.z
#define uStack_304 rotation.flags
#define fStack_300 rotation.up.x
#define fStack_2fc rotation.up.y
#define fStack_2f8 rotation.up.z
#define fStack_2f0 rotation.at.x
#define fStack_2ec rotation.at.y
#define fStack_2e8 rotation.at.z
#define fStack_2e0 rotation.pos.x
#define fStack_2dc rotation.pos.y
#define fStack_2d8 rotation.pos.z
#define fStack_380 quat380[0]
#define fStack_37c quat380[1]
#define fStack_378 quat380[2]
#define fStack_374 quat380[3]
#define fStack_370 quat370[0]
#define fStack_36c quat370[1]
#define fStack_368 quat370[2]
#define fStack_364 quat370[3]
#define fStack_360 quat360[0]
#define fStack_35c quat360[1]
#define fStack_358 quat360[2]
#define fStack_354 quat360[3]
#define fStack_350 slerpWork[0]
#define fStack_34c slerpWork[1]
#define fStack_348 slerpWork[2]
#define fStack_344 slerpWork[3]
#define fStack_340 slerpWork[4]
#define fStack_33c slerpWork[5]
#define fStack_338 slerpWork[6]
#define fStack_334 slerpWork[7]
#define fStack_330 slerpWork[8]
#define iStack_32c (*(s32*)&slerpWork[9])
#define fStack_320 quat320[0]
#define fStack_31c quat320[1]
#define fStack_318 quat320[2]
#define fStack_314 quat320[3]
#define fStack_50 vector50.x
#define fStack_4c vector50.y
#define fStack_48 vector50.z
#define fStack_40 vector40.x
#define fStack_3c vector40.y
#define fStack_38 vector40.z
#define fStack_30 vector30.x
#define fStack_2c vector30.y
#define fStack_28 vector30.z
#define fStack_20 vector20.x
#define fStack_1c vector20.y
#define fStack_18 vector20.z
#define uStack_10 (*(u32*)&vector10.x)
#define uStack_c (*(u32*)&vector10.y)
#define uStack_8 (*(u32*)&vector10.z)

  bVar14 = false;

  uVar6 = 0;

  uVar2 = *param_1;

  if (((uVar2 & 1) == 0) || (param_1[7] == 0xffffffff)) {

    if ((uVar2 & 0x4000) == 0) {

      bVar14 = true;

      uVar6 = param_1[5];

      pfVar16 = afStack_90;

    }

    else {

      auStack_d0[10] = 0x3f800000;

      auStack_d0[5] = 0x3f800000;

      auStack_d0[0] = 0x3f800000;

      auStack_d0[4] = 0;

      auStack_d0[2] = 0;

      auStack_d0[1] = 0;

      auStack_d0[9] = 0;

      auStack_d0[8] = 0;

      auStack_d0[6] = 0;

      auStack_d0[14] = 0;

      auStack_d0[13] = 0;

      auStack_d0[12] = 0;

      auStack_d0[3] |= 0x20003;

      pfVar16 = (float *)auStack_d0;

      if ((uVar2 & 0x2000) != 0) {

        bVar14 = true;

        uVar6 = param_1[5];

      }

    }

  }

  else {

    pfVar16 = (float *)(*(int *)(param_1[6] + 8) + param_1[7] * 0x40);

    if (((uVar2 & 0x2000) != 0) && ((uVar2 & 0x4000) != 0)) {

      bVar14 = true;

      uVar6 = *(u32 *)(param_1[6] + 0x14);

    }

  }

  if (bVar14) {

    if ((uVar6 == 0) || (iVar11 = *(int *)(uVar6 + 4), iVar11 == 0)) {

      afStack_90[10] = 1.0f;

      afStack_90[5] = 1.0f;

      afStack_90[0] = 1.0f;

      afStack_90[4] = 0.0f;

      afStack_90[2] = 0.0f;

      afStack_90[1] = 0.0f;

      afStack_90[9] = 0.0f;
      afStack_90[8] = 0.0f;

      afStack_90[6] = 0.0f;

      afStack_90[14] = 0.0f;
      afStack_90[13] = 0.0f;
      afStack_90[12] = 0.0f;

      *(u32*)&afStack_90[3] |= 0x20003;

    }

    else {

      lVar7 = func_004cae30(iVar11);

      if (lVar7 == 0) {

        pfVar5 = (float *)func_004cb2f0(iVar11);

        pfVar12 = afStack_90;

        iVar11 = 8;

        do {

          *(u32*)pfVar12 = *(u32*)pfVar5;

          *(u32*)(pfVar12 + 1) = *(u32*)(pfVar5 + 1);

          pfVar12 = pfVar12 + 2;
          iVar11 = iVar11 + -1;

        } while (0 < iVar11);

      }

      else {

        pfVar12 = (float *)(iVar11 + 0x10);

        pfVar5 = afStack_90;

        iVar15 = 8;

        do {

          *(u32*)pfVar5 = *(u32*)pfVar12;

          *(u32*)(pfVar5 + 1) = *(u32*)(pfVar12 + 1);

          pfVar12 = pfVar12 + 2;

          iVar15 = iVar15 + -1;

          pfVar5 = pfVar5 + 2;

        } while (0 < iVar15);

        for (iVar11 = *(int *)(iVar11 + 4); iVar11 != 0; iVar11 = *(int *)(iVar11 + 4)) {

          pfVar12 = afStack_90;

          pfVar5 = afStack_1d0;

          iVar15 = 4;

          do {

            *(unsigned __int128*)pfVar5 = *(unsigned __int128*)pfVar12;

            pfVar12 = pfVar12 + 4;

            iVar15 = iVar15 + -1;

            pfVar5 = pfVar5 + 4;

          } while (0 < iVar15);

          FUN_004c2f30((RwMatrix*)afStack_90,(RwMatrix*)afStack_1d0,(RwMatrix*)(iVar11 + 0x10));

        }

      }

    }

  }

  uVar6 = uVar2 & 0x2000;

  if ((uVar6 != 0) && ((*(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) & 3) == 0)) {

    *(int *)(*(int *)(param_1[5] + 0xa0) + 8) = DAT_0096012c;

    *(int **)(*(int *)(param_1[5] + 0xa0) + 0xc) = (int *)&DAT_0096012c;

    *(int *)(DAT_0096012c + 4) = *(int *)(param_1[5] + 0xa0) + 8;

    iVar11 = *(int *)(param_1[5] + 0xa0);

    DAT_0096012c = iVar11 + 8;

    *(u8 *)(iVar11 + 3) = *(u8 *)(iVar11 + 3) | 2;

  }

  uVar8 = param_1[8];

  pcVar3 = *(code **)(uVar8 + 0x3c);

  iVar11 = *(int *)(uVar8 + 0x24);

  puVar17 = auStack_14c;

  uVar18 = param_1[4];

  pfVar5 = (float *)param_1[2];

  iVar15 = uVar8 + 0x4c;

  for (iVar19 = 0; iVar19 < (int)param_1[1]; iVar19 = iVar19 + 1) {

    if (pcVar3 != (code *)&LAB_00464760) {

      (*pcVar3)(&fStack_210,iVar15);

    }

    else {

      fVar22 = *(float *)(iVar15 + 8);

      fVar23 = *(float *)(iVar15 + 0xc);

      fVar20 = *(float *)(iVar15 + 0x10);

      fVar21 = *(float *)(iVar15 + 0x14);

      qxx = fVar22 * fVar22;
      qyy = fVar23 * fVar23;
      qzz = fVar20 * fVar20;
      qyz = fVar23 * fVar20;
      qzx = fVar20 * fVar22;
      qxy = fVar22 * fVar23;
      qwx = fVar21 * fVar22;
      qwy = fVar21 * fVar23;
      qwz = fVar21 * fVar20;
      fStack_210 = 1.0f - (qyy + qzz) * 2.0f;
      fStack_20c = (qxy + qwz) * 2.0f;
      fStack_208 = (qzx - qwy) * 2.0f;
      fStack_200 = (qxy - qwz) * 2.0f;
      fStack_1fc = 1.0f - (qxx + qzz) * 2.0f;
      fStack_1f8 = (qyz + qwx) * 2.0f;
      fStack_1f0 = (qzx + qwy) * 2.0f;
      fStack_1ec = (qyz - qwx) * 2.0f;
      fStack_1e8 = 1.0f - (qxx + qyy) * 2.0f;

      uStack_204 = 3;

      uStack_1e0 = *(u32 *)(iVar15 + 0x18);

      uStack_1dc = *(u32 *)(iVar15 + 0x1c);

      uStack_1d8 = *(u32 *)(iVar15 + 0x20);

    }

    if (*(int *)(param_1[4] + iVar19 * 0x10) != 0x1389) {
      goto non_special_matrix;
    }

    else {

      if ((param_4 == 0) && ((*param_3 & 0x400) == 0)) {

        *param_3 = *param_3 | 0x600;

      }

      bVar14 = false;

      fStack_30 = 1.0f / *(float *)(param_3 + 0x18);

      fStack_2c = 1.0f / *(float *)(param_3 + 0x1a);

      fStack_28 = 1.0f / *(float *)(param_3 + 0x1c);

      if ((*param_2 & 0x10) != 0) {

        fStack_30 = fStack_30 * (1.0f / *(f32*)DAT_009571c0_abs);

        fVar20 = (1.0f / *(f32*)DAT_009571c0_abs) * *(f32*)DAT_009571c4_abs;

        fStack_2c = fStack_2c * fVar20;

        fStack_28 = fStack_28 * fVar20;

      }

      pfVar13 = afStack_190;

      iVar9 = 8;

      pfVar12 = pfVar16;

      do {

        fVar20 = *pfVar12;

        fVar21 = pfVar12[1];

        pfVar12 = pfVar12 + 2;

        iVar9 = iVar9 + -1;

        *pfVar13 = fVar20;

        pfVar13[1] = fVar21;

        pfVar13 = pfVar13 + 2;

      } while (0 < iVar9);

      RwMatrixScale((RwMatrix*)afStack_190,&vector30,1);

      FUN_004c2f30((RwMatrix*)&fStack_310,(RwMatrix*)&fStack_210,(RwMatrix*)afStack_190);

      fStack_20 = fStack_2e0;

      fStack_1c = fStack_2dc;

      fStack_18 = fStack_2d8;

      if (param_4 == 0) {

        RwMatrixScale((RwMatrix*)&fStack_310,&vector30,1);

        uStack_10 = 0;

        uStack_c = 0x3f800000;

        uStack_8 = 0;

        RwMatrixRotate((RwMatrix*)auStack_290,(RwV3d*)&uStack_10,180.0f,0);

        uStack_10 = 0;

        uStack_c = 0;

        uStack_8 = 0x3f800000;

        RwMatrixRotate((RwMatrix*)auStack_290,(const RwV3d*)&uStack_10,-90.0f,2);

        FUN_004c2f30((RwMatrix*)auStack_250,(RwMatrix*)auStack_290,(RwMatrix*)afStack_90);

        uVar1 = *param_3;

        if ((uVar1 & 0x100) != 0) {
          goto use_existing_rotation;
        }
        {

          if ((uVar1 & 0x80) != 0) {
            goto direct_rotation;
          }
          {

            iStack_3a0 = 1;

            if ((uVar1 & 0x40) == 0) {

              fStack_30 = -*(float *)(param_3 + 0x1e);

              fStack_2c = -*(float *)(param_3 + 0x20);

              fStack_28 = -*(float *)(param_3 + 0x22);

            }

            else {

              fStack_30 = fStack_20 - *(float *)(param_3 + 0x1e);

              fStack_2c = fStack_1c - *(float *)(param_3 + 0x20);

              fStack_28 = fStack_18 - *(float *)(param_3 + 0x22);

            }

            RwV3dNormalize(&vector30,&vector30);

            func_004c32a0(auStack_2d0,afStack_90);

            func_004c6c60(&vector30,&vector30,auStack_2d0);

            RwV3dNormalize(&vector30,&vector30);

            fStack_50 = 0.0f;

            fStack_4c = 0.0f;

            fStack_48 = -100.0f;

            FUN_004c6be0(&vector50,&vector50,(const RwMatrix*)afStack_190);

            fStack_40 = fStack_20 - fStack_50;

            fStack_3c = fStack_1c - fStack_4c;

            fStack_38 = fStack_18 - fStack_48;

            func_004c6c60(&vector40,&vector40,auStack_2d0);

            RwV3dNormalize(&vector40,&vector40);

            fVar20 = (float)func_0052e9e8(fStack_3c);

            fVar23 = fGpffff80d0 * fVar20 - 90.0f;

            fVar20 = (float)func_0052ea18_typed(fStack_40,fStack_38);

            fVar22 = fGpffff80d0 * fVar20 + 180.0f;

            fVar20 = (float)func_0052e9e8(fStack_2c);

            fVar21 = fGpffff80d0 * fVar20 - 90.0f;

            fVar20 = (float)func_0052ea18_typed(fStack_30,fStack_28);

            fVar20 = fGpffff80d0 * fVar20;

            for (fVar21 = fVar21 - fVar23; fVar21 < 0.0f; fVar21 = fVar21 + 360.0f) {

            }

            for (; 360.0f < fVar21; fVar21 = fVar21 - 360.0f) {

            }

            fVar24 = *(float *)(param_3 + 4);

            if ((fVar24 < fVar21) && (fVar21 < 360.0f - fVar24)) {

              if (180.0f <= fVar21) {

                fVar24 = 360.0f - fVar24;

              }

              bVar14 = true;

              fVar21 = fVar24;

            }

            RwMatrixRotate((RwMatrix*)auStack_290,(const RwV3d*)auStack_240,-(fVar21 + fVar23),0);

            for (fVar20 = (fVar20 + 180.0f) - fVar22; fVar20 < 0.0f; fVar20 = fVar20 + 360.0f) {

            }

            for (; 360.0f < fVar20; fVar20 = fVar20 - 360.0f) {

            }

            fVar21 = *(float *)(param_3 + 6);

            if ((fVar21 < fVar20) && (fVar20 < 360.0f - fVar21)) {

              if (180.0f <= fVar20) {

                fVar21 = 360.0f - fVar21;

              }

              bVar14 = true;

              fVar20 = fVar21;

            }

            RwMatrixRotate((RwMatrix*)auStack_290,(const RwV3d*)auStack_250,fVar20 + fVar22,2);

          }
          goto finished_direct_rotation;
direct_rotation:
          iStack_3a0 = 0;
          uStack_10 = 0x3f800000;
          uStack_c = 0;
          uStack_8 = 0;
          RwMatrixRotate((RwMatrix*)auStack_290,(const RwV3d*)&uStack_10,*(float *)(param_3 + 0x1e),0);
          uStack_10 = 0;
          uStack_c = 0x3f800000;
          uStack_8 = 0;
          RwMatrixRotate((RwMatrix*)auStack_290,(const RwV3d*)&uStack_10,*(float *)(param_3 + 0x20),2);
finished_direct_rotation:

          FUN_004c2f30((RwMatrix*)pfVar5,(RwMatrix*)auStack_250,(RwMatrix*)auStack_290);

          RtQuatConvertFromMatrix((RtQuat*)quat320,(const RwMatrix*)pfVar5);

          if (((*param_3 & 0x1000) == 0) || (!bVar14)) {

            *param_3 = *param_3 & 0xf7ff;

          }

          else {

            if ((*param_3 & 0x800) == 0) {

              *(float *)(param_3 + 0x10) = fStack_320;

              *(float *)(param_3 + 0x12) = fStack_31c;

              *(float *)(param_3 + 0x14) = fStack_318;

              *(float *)(param_3 + 0x16) = fStack_314;

            }

            *param_3 = *param_3 | 0x800;

          }

          if ((*param_3 & 0x800) != 0) {

            fStack_320 = *(float *)(param_3 + 0x10);

            fStack_31c = *(float *)(param_3 + 0x12);

            fStack_318 = *(float *)(param_3 + 0x14);

            fStack_314 = *(float *)(param_3 + 0x16);

          }
        }
        goto finished_rotation_setup;
use_existing_rotation:
        RtQuatConvertFromMatrix((RtQuat*)quat320,(const RwMatrix*)&fStack_310);
finished_rotation_setup:

        if ((*param_3 & 0x200) != 0) {

          RtQuatConvertFromMatrix((RtQuat*)(param_3 + 8),(const RwMatrix*)&fStack_310);

          *param_3 = *param_3 & 0xfdff;

          if ((*param_3 & 0x100) != 0) {

            *param_3 = *param_3 & 0xfe1f;

            *param_3 = *param_3 & 0xfbff;

            *param_3 = *param_3 & 0xf7ff;

          }

        }

        else {

          if ((*param_3 & 0x100) != 0) {

            fVar20 = *(float *)(param_3 + 0xe) * fStack_314 +

                     *(float *)(param_3 + 0xc) * fStack_318 +

                     *(float *)(param_3 + 8) * fStack_320 + *(float *)(param_3 + 10) * fStack_31c;

            if (fVar20 < 0.0f) {

              fVar20 = *(float *)(param_3 + 0xe) * -fStack_314 +

                       *(float *)(param_3 + 0xc) * -fStack_318 +

                       *(float *)(param_3 + 8) * -fStack_320 +

                       *(float *)(param_3 + 10) * -fStack_31c;

            }

            fVar20 = (float)func_0052e9e8(fVar20);

            if (fVar20 * 2.0f < fGpffff80f4) {

              *param_3 = *param_3 & 0xfe1f;

              *param_3 = *param_3 & 0xfbff;

            }

            *param_3 = *param_3 & 0xf7ff;

          }

          fStack_370 = *(float *)(param_3 + 8);

          fStack_36c = *(float *)(param_3 + 10);

          fStack_368 = *(float *)(param_3 + 0xc);

          fStack_364 = *(float *)(param_3 + 0xe);

          func_004be310(quat370,quat320,slerpWork);

          fVar20 = *(float *)(param_3 + 2);

          if (fVar20 <= 0.0f) {

            fStack_360 = fStack_370;

            fStack_35c = fStack_36c;

            fStack_358 = fStack_368;

            fStack_354 = fStack_364;

          }

          else if (1.0f <= fVar20) {

            fStack_360 = fStack_320;

            fStack_35c = fStack_31c;

            fStack_358 = fStack_318;

            fStack_354 = fStack_314;

          }

          else {

            fVar21 = 1.0f - fVar20;

            if (iStack_32c == 0) {

              fVar21 = fVar21 * fStack_330;

              fVar22 = fVar21 * fVar21;

              fVar21 = fVar22 * fVar21 *

                       (fVar22 * (fVar22 * (fVar22 * (fVar22 * (fGpffff814c * fVar22 +

                                                               fGpffff8048) +

                                                     fGpffff8118) + fGpffff8050) +

                                 fGpffff8054) + fGpffff8058) + fVar21;

              fVar20 = fVar20 * fStack_330;

              fVar22 = fVar20 * fVar20;

              fVar20 = fVar22 * fVar20 *

                       (fVar22 * (fVar22 * (fVar22 * (fVar22 * (fGpffff814c * fVar22 +

                                                               fGpffff8048) +

                                                     fGpffff8118) + fGpffff8050) +

                                 fGpffff8054) + fGpffff8058) + fVar20;

            }

            fStack_360 = fStack_340 * fVar20 + fStack_350 * fVar21;

            fStack_35c = fStack_33c * fVar20 + fStack_34c * fVar21;

            fStack_358 = fStack_338 * fVar20 + fStack_348 * fVar21;

            fStack_354 = fStack_344 * fVar21 + fStack_334 * fVar20;

          }

          if (((*param_3 & 0x2000) == 0) || (iStack_3a0 == 0)) {

            *(float *)(param_3 + 8) = fStack_360;

            *(float *)(param_3 + 10) = fStack_35c;

            *(float *)(param_3 + 0xc) = fStack_358;

            *(float *)(param_3 + 0xe) = fStack_354;

          }

          else {

            RtQuatConvertFromMatrix((RtQuat*)quat380,(const RwMatrix*)&fStack_310);

            fVar20 = fStack_374 * fStack_354 +

                     fStack_378 * fStack_358 + fStack_380 * fStack_360 + fStack_37c * fStack_35c;

            if (fVar20 < 0.0f) {

              fVar20 = fStack_374 * -fStack_354 +

                       fStack_378 * -fStack_358 +

                       fStack_380 * -fStack_360 + fStack_37c * -fStack_35c;

            }

            fVar20 = (float)func_0052e9e8(fVar20);

            if (fVar20 * 2.0f <= fGpffff8150 * *(float *)(param_3 + 6)) {

              *(float *)(param_3 + 8) = fStack_360;

              *(float *)(param_3 + 10) = fStack_35c;

              *(float *)(param_3 + 0xc) = fStack_358;

              *(float *)(param_3 + 0xe) = fStack_354;

            }

            else {

              fVar20 = 1.0f - fGpffff8154 / (fVar20 * 2.0f);

              func_004be310(quat360,quat380,slerpWork);

              if (fVar20 <= 0.0f) {

                *(float *)(param_3 + 8) = fStack_360;

                *(float *)(param_3 + 10) = fStack_35c;

                *(float *)(param_3 + 0xc) = fStack_358;

                *(float *)(param_3 + 0xe) = fStack_354;

              }

              else if (1.0f <= fVar20) {

                *(float *)(param_3 + 8) = fStack_380;

                *(float *)(param_3 + 10) = fStack_37c;

                *(float *)(param_3 + 0xc) = fStack_378;

                *(float *)(param_3 + 0xe) = fStack_374;

              }

              else {

                fVar21 = 1.0f - fVar20;

                if (iStack_32c == 0) {

                  fVar21 = fVar21 * fStack_330;

                  fVar22 = fVar21 * fVar21;

                  fVar21 = fVar22 * fVar21 *

                           (fVar22 * (fVar22 * (fVar22 * (fVar22 * (fGpffff8158 * fVar22 +

                                                                   fGpffff8048) +

                                                         fGpffff8118) + fGpffff8050) +

                                     fGpffff8054) + fGpffff8058) + fVar21;

                  fVar20 = fVar20 * fStack_330;

                  fVar22 = fVar20 * fVar20;

                  fVar20 = fVar22 * fVar20 *

                           (fVar22 * (fVar22 * (fVar22 * (fVar22 * (fGpffff8158 * fVar22 +

                                                                   fGpffff8048) +

                                                         fGpffff8118) + fGpffff8050) +

                                     fGpffff8054) + fGpffff8058) + fVar20;

                }

                *(float *)(param_3 + 8) = fStack_350 * fVar21;

                *(float *)(param_3 + 10) = fStack_34c * fVar21;

                *(float *)(param_3 + 0xc) = fStack_348 * fVar21;

                *(float *)(param_3 + 8) = fStack_340 * fVar20 + *(float *)(param_3 + 8);

                *(float *)(param_3 + 10) = fStack_33c * fVar20 + *(float *)(param_3 + 10);

                *(float *)(param_3 + 0xc) = fStack_338 * fVar20 + *(float *)(param_3 + 0xc);

                *(float *)(param_3 + 0xe) = fStack_344 * fVar21 + fStack_334 * fVar20;

              }

            }

          }

        }

      }

      if (param_4 == 0) {

        fVar24 = *(float *)(param_3 + 10);

        fVar26 = *(float *)(param_3 + 8);

        fVar25 = *(float *)(param_3 + 0xc);

        fVar22 = *(float *)(param_3 + 0xe);

        fVar21 = 2.0f / (fVar22 * fVar22 + fVar25 * fVar25 + fVar26 * fVar26 + fVar24 * fVar24);

        fVar23 = fVar26 * fVar21;

        fVar20 = fVar24 * fVar21;

        fVar21 = fVar25 * fVar21;

        *pfVar5 = 1.0f - (fVar24 * fVar20 + fVar25 * fVar21);

        pfVar5[1] = fVar26 * fVar20 + fVar21 * fVar22;

        pfVar5[2] = fVar25 * fVar23 - fVar20 * fVar22;

        pfVar5[4] = fVar26 * fVar20 - fVar21 * fVar22;

        pfVar5[5] = 1.0f - (fVar25 * fVar21 + fVar26 * fVar23);

        pfVar5[6] = fVar24 * fVar21 + fVar23 * fVar22;

        pfVar5[8] = fVar25 * fVar23 + fVar20 * fVar22;

        pfVar5[9] = fVar24 * fVar21 - fVar23 * fVar22;

        pfVar5[10] = 1.0f - (fVar26 * fVar23 + fVar24 * fVar20);

        pfVar5[0xc] = 0.0f;

        pfVar5[0xd] = 0.0f;

        pfVar5[0xe] = 0.0f;

        pfVar5[3] = 4.2039e-45f;

        fStack_30 = *(float *)(param_3 + 0x18);

        fStack_2c = *(float *)(param_3 + 0x1a);

        fStack_28 = *(float *)(param_3 + 0x1c);

        if ((*param_2 & 0x10) != 0) {

          fStack_30 = fStack_30 * *(f32*)DAT_009571c0_abs;

          fStack_2c = fStack_2c * *(f32*)DAT_009571c0_abs * *(f32*)DAT_009571c4_abs;

          fStack_28 = fStack_28 * *(f32*)DAT_009571c0_abs * *(f32*)DAT_009571c4_abs;

        }

        RwMatrixScale((RwMatrix*)pfVar5,&vector30,1);

        pfVar5[0xc] = fStack_20;

        pfVar5[0xd] = fStack_1c;

        pfVar5[0xe] = fStack_18;

      }

      else {

        fVar24 = *(float *)(param_3 + 10);

        fVar26 = *(float *)(param_3 + 8);

        fVar25 = *(float *)(param_3 + 0xc);

        fVar22 = *(float *)(param_3 + 0xe);

        fVar21 = 2.0f / (fVar22 * fVar22 + fVar25 * fVar25 + fVar26 * fVar26 + fVar24 * fVar24);

        fVar23 = fVar26 * fVar21;

        fVar20 = fVar24 * fVar21;

        fVar21 = fVar25 * fVar21;

        fStack_310 = 1.0f - (fVar24 * fVar20 + fVar25 * fVar21);

        fStack_30c = fVar26 * fVar20 + fVar21 * fVar22;

        fStack_308 = fVar25 * fVar23 - fVar20 * fVar22;

        fStack_300 = fVar26 * fVar20 - fVar21 * fVar22;

        fStack_2fc = 1.0f - (fVar25 * fVar21 + fVar26 * fVar23);

        fStack_2f8 = fVar24 * fVar21 + fVar23 * fVar22;

        fStack_2f0 = fVar25 * fVar23 + fVar20 * fVar22;

        fStack_2ec = fVar24 * fVar21 - fVar23 * fVar22;

        fStack_2e8 = 1.0f - (fVar26 * fVar23 + fVar24 * fVar20);

        fStack_2e0 = 0.0f;

        fStack_2dc = 0.0f;

        fStack_2d8 = 0.0f;

        uStack_304 = 3;

        fStack_30 = *(float *)(param_3 + 0x18);

        fStack_2c = *(float *)(param_3 + 0x1a);

        fStack_28 = *(float *)(param_3 + 0x1c);

        if ((*param_2 & 0x10) != 0) {

          fStack_30 = fStack_30 * *(f32*)DAT_009571c0_abs;

          fStack_2c = fStack_2c * *(f32*)DAT_009571c0_abs * *(f32*)DAT_009571c4_abs;

          fStack_28 = fStack_28 * *(f32*)DAT_009571c0_abs * *(f32*)DAT_009571c4_abs;

        }

        RwMatrixScale((RwMatrix*)&fStack_310,&vector30,1);

        fStack_2e0 = fStack_20;

        fStack_2dc = fStack_1c;

        fStack_2d8 = fStack_18;

        FUN_004c2f30((RwMatrix*)pfVar5,(RwMatrix*)&fStack_310,(RwMatrix*)param_4);

      }

      if (((*(int *)(uVar18 + 0xc) != 0) &&

          (iVar9 = *(int *)(*(int *)(uVar18 + 0xc) + 4), iVar9 != 0)) &&

         ((*(u8 *)(*(int *)(iVar9 + 0xa0) + 3) & 1) != 0)) {

        func_004cf4c0();

      }

    }
    goto special_matrix_done;
non_special_matrix:
    FUN_004c2f30((RwMatrix*)pfVar5,(RwMatrix*)&fStack_210,(RwMatrix*)pfVar16);
special_matrix_done:

    iVar9 = *(int *)(uVar18 + 0xc);

    if (iVar9 != 0) {

      if ((uVar2 & 0x1000) != 0) {

        pfVar13 = &fStack_210;

        pfVar12 = (float *)(iVar9 + 0x10);

        iVar10 = 8;

        do {

          fVar20 = *pfVar13;

          fVar21 = pfVar13[1];

          pfVar13 = pfVar13 + 2;

          iVar10 = iVar10 + -1;

          *pfVar12 = fVar20;

          pfVar12[1] = fVar21;

          pfVar12 = pfVar12 + 2;

        } while (0 < iVar10);

        if (uVar6 == 0) {

          func_004cb270(iVar9);

        }

      }

      if (uVar6 != 0) {

        if ((uVar2 & 0x4000) != 0) {

          FUN_004c2f30((RwMatrix*)(iVar9 + 0x50),(RwMatrix*)pfVar5,(RwMatrix*)afStack_90);

        }

        else {

          pfVar13 = (float *)(iVar9 + 0x50);

          iVar10 = 8;

          pfVar12 = pfVar5;

          do {

            fVar20 = *pfVar12;

            fVar21 = pfVar12[1];

            pfVar12 = pfVar12 + 2;

            iVar10 = iVar10 + -1;

            *pfVar13 = fVar20;

            pfVar13[1] = fVar21;

            pfVar13 = pfVar13 + 2;

          } while (0 < iVar10);

        }

        *(u8 *)(iVar9 + 3) = *(u8 *)(iVar9 + 3) & 0xfb | 8;

      }

    }

    uVar8 = *(u32 *)(uVar18 + 8) & 3;

    pfVar12 = pfVar16;

    if (uVar8 != 3) {

      pfVar12 = pfVar5;

      if (uVar8 == 2) {

        *puVar17 = (u32)pfVar16;

        puVar17 = puVar17 + 1;

      }

      else if (uVar8 == 1) {

        puVar17 = puVar17 + -1;

        pfVar12 = (float *)*puVar17;

      }

      else if (uVar8 != 0) {

        pfVar12 = pfVar16;

      }

    }

    pfVar16 = pfVar12;

    iVar15 = iVar15 + iVar11;

    pfVar5 = pfVar5 + 0x10;

    uVar18 = uVar18 + 0x10;

  }

  return 1;

}
#undef fStack_210
#undef fStack_20c
#undef fStack_208
#undef uStack_204
#undef fStack_200
#undef fStack_1fc
#undef fStack_1f8
#undef fStack_1f0
#undef fStack_1ec
#undef fStack_1e8
#undef uStack_1e0
#undef uStack_1dc
#undef uStack_1d8
#undef fStack_310
#undef fStack_30c
#undef fStack_308
#undef uStack_304
#undef fStack_300
#undef fStack_2fc
#undef fStack_2f8
#undef fStack_2f0
#undef fStack_2ec
#undef fStack_2e8
#undef fStack_2e0
#undef fStack_2dc
#undef fStack_2d8
#undef fStack_380
#undef fStack_37c
#undef fStack_378
#undef fStack_374
#undef fStack_370
#undef fStack_36c
#undef fStack_368
#undef fStack_364
#undef fStack_360
#undef fStack_35c
#undef fStack_358
#undef fStack_354
#undef fStack_350
#undef fStack_34c
#undef fStack_348
#undef fStack_344
#undef fStack_340
#undef fStack_33c
#undef fStack_338
#undef fStack_334
#undef fStack_330
#undef iStack_32c
#undef fStack_320
#undef fStack_31c
#undef fStack_318
#undef fStack_314
#undef fStack_50
#undef fStack_4c
#undef fStack_48
#undef fStack_40
#undef fStack_3c
#undef fStack_38
#undef fStack_30
#undef fStack_2c
#undef fStack_28
#undef fStack_20
#undef fStack_1c
#undef fStack_18
#undef uStack_10
#undef uStack_c
#undef uStack_8




#pragma opt_propagation reset
// FUN_00312C70


void func_00312c70(u8* param_1,int param_2)



{

  if (*(s32*)DAT_009571b8_abs == param_2) {

    *(float *)(param_2 + 0x18) = *(float *)(param_2 + 0x18) * *(*(float**)DAT_009571bc_abs);

    *(float *)(param_2 + 0x1c) = *(float *)(param_2 + 0x1c) * (*(float**)DAT_009571bc_abs)[1];

    *(float *)(param_2 + 0x20) = *(float *)(param_2 + 0x20) * (*(float**)DAT_009571bc_abs)[2];

  }

  (*DAT_009571b0_abs)(param_1,param_2);

  if (*(s32*)DAT_009571b4_abs == param_2) {

    RwMatrixScale((RwMatrix*)param_1,(const RwV3d*)*(float**)DAT_009571bc_abs,1);

  }

  return;

}




// FUN_00312D40


void func_00312d40(u8* param_1,u8* param_2)



{

  int iVar1;

  int iVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  

  iVar3 = (int)param_2;

  pfVar6 = (float *)(iVar3 + 0x34);

  iVar1 = *(int *)(param_1 + 0x20);

  if (iVar1 != 0) {

    *(u32*)DAT_009571b0_abs = *(u32 *)(iVar1 + 0x3c);

    *(code *)(iVar1 + 0x3c) = (code)func_00312c70;

    iVar4 = *(int *)(param_1 + 0x20);
    iVar5 = *(int *)(iVar4 + 0x24);
    *(s32*)DAT_009571b4_abs = iVar4 + 0x4c;
    *(s32*)DAT_009571b4_abs += iVar5 * *(int *)pfVar6;
    if (*(float *)(iVar3 + 8) != 0.0f) {
      *(s32*)DAT_009571b8_abs = *(s32*)DAT_009571b4_abs;
    }
    else {
      *(s32*)DAT_009571b8_abs = 0;
    }

    *(float**)DAT_009571bc_abs = pfVar6 + 1;
    *(f32*)DAT_009571c0_abs = pfVar6[4];
    *(f32*)DAT_009571c4_abs = pfVar6[5];
    if ((*(u16 *)(iVar3 + 0x4c) & 0x1e0) != 0) {

      func_00311730((u32*)param_1,(u16*)param_2,(u16*)(param_2 + 0x4c),0);

      *(u16 *)(iVar3 + 0x4c) = *(u16 *)(iVar3 + 0x4c) | 0x4000;

    }

    else {

      func_00466ef0(param_1);

      *(u16 *)(iVar3 + 0x4c) = *(u16 *)(iVar3 + 0x4c) & 0xbfff;

    }

    *(u32 *)(*(int *)(param_1 + 0x20) + 0x3c) = *(u32*)DAT_009571b0_abs;

  }

  return;

}




// FUN_00312E80


void func_00312e80(int param_1)



{

  u32 uVar1;
  u32 uVar2;

  

  uVar2 = func_00469030();

  switch(uVar2) {
  case 1:
    uVar1 = func_0046a890(0x10021);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  case 2:
    uVar1 = func_0046a890(0x10022);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  case 3:
    uVar1 = func_0046a890(0x10023);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  case 4:
    uVar1 = func_0046a890(0x10024);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  case 5:
    uVar1 = func_0046a890(0x1002a);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  case 6:
    uVar1 = func_0046a890(0x1002b);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  default:
    uVar1 = func_0046a890(0x10020);
    *(u32 *)(param_1 + 8) = uVar1;
    break;
  }

  return;

}




// FUN_00312F90


u32 func_00312f90(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 lVar3;
    u32 uVar4;
    int iVar5;
    int iVar6;

    iVar5 = (int)param_1;
    iVar1 = *(int *)(iVar5 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_0048a2c0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_0048a3d0(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    if (param_1 != 0) {
        uVar2 = func_0046a890(0x1001f);
        *(u32 *)(iVar5 + 0x6c) = uVar2;
        iVar5 = *(int *)(iVar5 + 0x18);
        iVar1 = *(int *)(iVar5 + 0x24);
        for (iVar6 = 0; iVar6 < iVar1; iVar6 = iVar6 + 1) {
            func_00312e80(*(u32 *)(*(int *)(iVar5 + 0x20) + iVar6 * 4));
        }
        return param_1;
    }

    return param_1;
}




// FUN_00313090 NONMATCHING


u32 func_00313090(u32 param_1,u32 param_2)



{

  int *piVar1;

  u8 *puVar2;

  int iVar3;

  u16 *puVar4;

  short sVar5;

  

  puVar4 = (u16 *)param_2;

  sVar5 = *(short *)(puVar4 + 2);

  piVar1 = *(int **)(puVar4 + 0x16);

  if (piVar1 != (int *)0x0) {



    if ((((s64)(u32)*(u16 *)(piVar1 + 1) > (s64)sVar5) &&

        (puVar2 = *(u8 **)((u8 *)(sVar5 * 0x50) + (*piVar1 + 0x40)),

        puVar2 != (u8 *)0x0)) && (puVar2 != (u8 *)&DAT_009571d0)) {

      if ((*puVar4 & 1) == 0) {

        if (((s64)(u32)*(u16 *)(piVar1 + 1) > (s64)sVar5) && ((s64)sVar5 >= 0)) {

          func_004b74c0_ptrfirst(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),
                      *(f32 *)(puVar2 + 0xc));

          *(u8 *)(puVar4 + 1) = 1;

        }

      }

      else {

        iVar3 = *(int *)(puVar4 + 0x18);

        if (iVar3 != 0) {

          if (*(int *)(iVar3 + 0x18) != 0) {

            func_0031dce0(*(int *)(iVar3 + 0x18));

          }

          if (*(int *)(iVar3 + 0x24) != 0) {

            func_0031e210(*(int *)(iVar3 + 0x24));

          }

        }

        func_004b7010(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),0,0);

        *(float *)(puVar4 + 6) = fGpffff80e4 * *(float *)(puVar4 + 4);

        func_004b74c0_ptrfirst(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),*(f32 *)(puVar4 + 6));

        func_004b7010(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),func_00313090,param_2);

      }

      goto LAB_003131f8;

    }

  }

  if ((*puVar4 & 1) != 0) {

    *(u32 *)(puVar4 + 6) = 0;


  }

LAB_003131f8:

  if (*(code **)(puVar4 + 0x4a) != (code *)0x0) {

    (*(code *)(puVar4 + 0x4a))(*(u32 *)(puVar4 + 0x4c));

  }

  return param_1;

}




// FUN_00313230


void func_00313230(MdlAnimSlot* param_1)
{

  int iVar1;

  

  memset(param_1,0,0x9c);

  iVar1 = (int)param_1;

  *(u8 *)(iVar1 + 2) = 1;

  param_1->anim.id = -1;

  *(u32 *)(iVar1 + 8) = 0x3f800000;

  *(u32 *)(iVar1 + 0xc) = 0;

  param_1->anim.oldId = -1;

  *(u32 *)(iVar1 + 0x1c) = 0x3f800000;

  param_1->lookAt.blendRotFactor = DAT_007cada4;

  *(u32 *)(iVar1 + 0x5c) = 0;

  *(u32 *)(iVar1 + 0x60) = 0;

  *(u32 *)(iVar1 + 100) = 0;

  *(u32 *)(iVar1 + 0x68) = 0x3f800000;

  *(u32 *)(iVar1 + 0x54) = 0x428c0000;

  *(u32 *)(iVar1 + 0x58) = 0x42a00000;

  *(u16 *)(iVar1 + 0x4c) = 0;

  *(u32 *)(iVar1 + 0x7c) = 0x3f800000;

  *(u32 *)(iVar1 + 0x80) = 0x3f800000;

  *(u32 *)(iVar1 + 0x84) = 0x3f800000;

  return;

}




// FUN_003132C0 NONMATCHING


void func_003132c0(u8* param_1)
{

  u32 *puVar1;

  int *piVar2;

  u8 *puVar3;

  int iVar4;

  u32 uVar5;

  

  puVar1 = *(u32 **)(param_1 + 0x18);

  if (puVar1 != (u32 *)0x0) {

    for (uVar5 = 0; uVar5 < *puVar1; uVar5 = uVar5 + 1) {

      if (*(int *)(puVar1[5] + uVar5 * 4) != 0) {

        func_0031d790();

      }

      if (*(int *)(puVar1[8] + uVar5 * 4) != 0) {

        func_0031e130();

      }

    }

    (*DAT_0096017c)(puVar1);

    *(u32 *)(param_1 + 0x18) = 0;

  }

  if (*(int *)(param_1 + 0x12) != 0) {

    func_004b6eb0();

    *(u16 *)(param_1 + 0x12) = 0;

  }

  if (*(int *)(param_1 + 0x14) != 0) {

    func_004b6eb0();

    *(u16 *)(param_1 + 0x14) = 0;

  }

  piVar2 = *(int **)(param_1 + 0x16);

  if (piVar2 != (int *)0x0) {

    *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

    if (*(short *)((int)piVar2 + 6) == 0) {

      for (uVar5 = 0; uVar5 < *(u16 *)(piVar2 + 1); uVar5 = uVar5 + 1 & 0xffff) {

        iVar4 = *piVar2 + uVar5 * 0x50;

        puVar3 = *(u8 **)(iVar4 + 0x40);

        if (((puVar3 != (u8 *)0x0) && ((*(u32 *)(iVar4 + 0x44) & 1) == 0)) &&

           (puVar3 != (u8 *)&DAT_009571d0)) {

          func_004b6980();

        }

      }

      (*DAT_0096017c)(piVar2);

    }

    *(u16 *)(param_1 + 0x16) = 0;

  }

  if (((*param_1 & 2) != 0) && (*(int *)(param_1 + 0x10) != 0)) {

    func_004663d0();

    *(u16 *)(param_1 + 0x10) = 0;

  }

  return;

}




// FUN_00313490 NONMATCHING








void* func_00313490(MdlAnimSlot* param_1,void* param_2)
{

  u16 uVar1;

  int *piVar2;

  u8 *puVar3;

  u16 *puVar4;

  float fVar5;

  

  puVar4 = (u16 *)param_1;

  uVar1 = puVar4[2];

  if ((short)uVar1 < 0) {

    return param_2;

  }

  if ((u8)puVar4[1] == '\x01') {

    func_00466ef0(*(u32 *)(puVar4 + 0x10));

    return param_2;

  }

  fVar5 = fGpffff80e4 * *(float *)(puVar4 + 4);

  if ((fVar5 <= 0.0f) && ((*puVar4 & 6) == 0)) goto LAB_0031379c;

  if (*(float *)(puVar4 + 0xe) >= 1.0f) {

    piVar2 = *(int **)(puVar4 + 0x16);

    if (((piVar2 == (int *)0x0) || ((u32)*(u16 *)(piVar2 + 1) <= (s32)(s16)uVar1)) ||

       ((puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)uVar1 * 0x50), puVar3 == (u8 *)0x0

        || (puVar3 == (u8 *)&DAT_009571d0)))) {

      if (((piVar2 == (int *)0x0) || ((u32)*(u16 *)(piVar2 + 1) <= (s32)(s16)uVar1))

         || (*(u8 **)((short)uVar1 * 0x50 + *piVar2 + 0x40) != (u8 *)&DAT_009571d0)) {

        *(float *)(puVar4 + 6) = *(float *)(puVar4 + 6) + fVar5;

      }

    }

    else {

      func_004b7240_frame(fVar5,*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20));

    }

  }

  else {

    piVar2 = *(int **)(puVar4 + 0x16);

    if ((piVar2 != (int *)0x0) && ((s32)(s16)uVar1 < (u32)*(u16 *)(piVar2 + 1))) {

      puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)uVar1 * 0x50);

      if ((puVar3 != (u8 *)0x0) &&

         ((((puVar3 != (u8 *)&DAT_009571d0) &&

           ((s32)(s16)puVar4[8] < (u32)*(u16 *)(piVar2 + 1))) &&

          ((puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)puVar4[8] * 0x50),

           puVar3 != (u8 *)0x0 && (puVar3 != (u8 *)&DAT_009571d0)))))) {

        func_004b7510(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),*(u32 *)(puVar4 + 0x12),

                     *(u32 *)(puVar4 + 0x14));

        fVar5 = *(float *)(puVar4 + 0xe) + 1.0f / (float)puVar4[0xc];

        *(float *)(puVar4 + 0xe) = fVar5;

        if (1.0f <= fVar5) {

          func_004b6ec0(*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),

                       **(u32 **)(puVar4 + 0x14));

        }

        goto LAB_00313790;

      }

    }

    *(float *)(puVar4 + 0xe) = *(float *)(puVar4 + 0xe) + 1.0f / (float)puVar4[0xc];

  }

LAB_00313790:

  *puVar4 = *puVar4 & 0xfffb;

LAB_0031379c:

  piVar2 = *(int **)(puVar4 + 0x16);

  if (((piVar2 != (int *)0x0) && ((s32)(s16)uVar1 < (u32)*(u16 *)(piVar2 + 1))) &&

     ((puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)uVar1 * 0x50), puVar3 != (u8 *)0x0 &&

      (puVar3 != (u8 *)&DAT_009571d0)))) {

    if (((*puVar4 & 2) != 0) && (param_2 != 0)) {

      func_00311640((RtAnimInterpolator*)*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),
                    (RtAnimInterpolator*)*(u32 *)(*(int *)((int)param_2 + 0x20) + 0x20),
                    (RtAnimInterpolator*)*(u32 *)(*(int *)(puVar4 + 0x10) + 0x20),
                    1.0f);

    }

    if ((*puVar4 & 0x10) != 0) {

      func_00312d40((u8*)(*(u32 *)(puVar4 + 0x10)),(u8*)param_1);

    }

    else {

      if ((puVar4[0x26] & 0x1e0) == 0) {

        func_00466ef0(*(u32 *)(puVar4 + 0x10));

        puVar4[0x26] = puVar4[0x26] & 0xbfff;

      }

      else {

        func_00311730((u32*)(*(u32 *)(puVar4 + 0x10)),(u16*)param_1,(u16*)(puVar4 + 0x26),0);

        puVar4[0x26] = puVar4[0x26] | 0x4000;

      }

    }

    *(u32 *)(puVar4 + 6) = *(u32 *)(*(int *)(*(int *)(puVar4 + 0x10) + 0x20) + 4);

  }

  return param_1;

}




// FUN_003138E0 NONMATCHING


void func_003138e0(MdlAnim* param_1,s16 param_2,u16 param_3,u16 param_4)
{

  u16 uVar1;

  int *piVar2;

  u8 *puVar3;

  int iVar4;

  u32 uVar5;

  u16 *puVar6;

  

  puVar6 = (u16 *)param_1;

  *puVar6 = *puVar6 & 0xfffe;

  *puVar6 = *puVar6 | param_4 & 1;

  *(u8 *)(puVar6 + 1) = 0;

  if (param_3 != 0) {

    uVar1 = puVar6[2];

    if ((long)(short)uVar1 != -1) {

      piVar2 = *(int **)(puVar6 + 0x16);

      if ((piVar2 != (int *)0x0) && ((long)(short)uVar1 < (long)(u32)*(u16 *)(piVar2 + 1))) {

        puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)uVar1 * 0x50);

        if ((puVar3 != (u8 *)0x0) &&

           (((puVar3 != (u8 *)&DAT_009571d0 && (piVar2 != (int *)0x0)) &&

            ((long)(short)param_2 < (long)(u32)*(u16 *)(piVar2 + 1))))) {

          puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)param_2 * 0x50);

          if ((puVar3 != (u8 *)0x0) && (puVar3 != (u8 *)&DAT_009571d0)) {

            if (*(int *)(puVar6 + 0x12) == 0) {

              uVar5 = func_004b6e10(*(u32 *)(*(int *)(puVar6 + 0x10) + 4),

                                   *(u32 *)(*(int *)(*(int *)(puVar6 + 0x10) + 0x20) + 0x20))

              ;

              *(u32 *)(puVar6 + 0x12) = uVar5;

            }

            if (*(int *)(puVar6 + 0x14) == 0) {

              uVar5 = func_004b6e10(*(u32 *)(*(int *)(puVar6 + 0x10) + 4),

                                   *(u32 *)(*(int *)(*(int *)(puVar6 + 0x10) + 0x20) + 0x20))

              ;

              *(u32 *)(puVar6 + 0x14) = uVar5;

            }

            func_004b6ec0(*(u32 *)(puVar6 + 0x12),

                         *(u32 *)((short)puVar6[2] * 0x50 + **(int **)(puVar6 + 0x16) + 0x40)

                        );

            func_004b6ec0(*(u32 *)(puVar6 + 0x14),

                         *(u32 *)((short)param_2 * 0x50 + **(int **)(puVar6 + 0x16) + 0x40));

            func_004b7020(*(u32 *)(puVar6 + 0x12),

                         *(u32 *)(*(int *)(puVar6 + 0x10) + 0x20));

            puVar6[8] = puVar6[2];

            *(u32 *)(puVar6 + 10) = *(u32 *)(puVar6 + 6);

            puVar6[0xc] = param_3;

            *(f32 *)(puVar6 + 0xe) = 0.0f;


            goto LAB_00313b48;

          }

        }

      }

    }

  }

  piVar2 = *(int **)(puVar6 + 0x16);

  if ((piVar2 != (int *)0x0) &&

     ((((long)(short)param_2 < (long)(u32)*(u16 *)(piVar2 + 1) &&

       (puVar3 = *(u8 **)(*piVar2 + 0x40 + (short)param_2 * 0x50), puVar3 != (u8 *)0x0

       )) && (puVar3 != (u8 *)&DAT_009571d0)))) {

    func_004b6ec0(*(u32 *)(*(int *)(puVar6 + 0x10) + 0x20));

    func_004b74c0(0,*(u32 *)(*(int *)(puVar6 + 0x10) + 0x20));

    func_004b7010(*(u32 *)(*(int *)(puVar6 + 0x10) + 0x20),0x313090,param_1);

  }

  puVar6[0xc] = 0;

  *(f32 *)(puVar6 + 0xe) = 1.0f;


LAB_00313b48:

  puVar6[0x26] = puVar6[0x26] & 0xf7ff;

  iVar4 = *(int *)(puVar6 + 0x18);

  if (iVar4 != 0) {

    *(u32 *)(iVar4 + 0x1c) = *(u32 *)(*(int *)(iVar4 + 0x14) + (short)param_2 * 4);

    if ((param_4 & 0x20) == 0) {

      uVar5 = *(u32 *)(*(int *)(iVar4 + 0x20) + (short)param_2 * 4);

    }

    else {

      uVar5 = 0;

    }

    *(u32 *)(iVar4 + 0x28) = uVar5;

    *(u32 *)(iVar4 + 0x2c) = 1;

    *(u16 *)(iVar4 + 0x30) = param_3;

  }

  *(u32 *)(puVar6 + 6) = 0;


  puVar6[2] = param_2;

  return;

}



// FUN_00313BE0


void func_00313be0(MdlAnimEntryTable* table)
{
    u16 i;

    table->unk_06--;
    if (table->unk_06 == 0) {
        for (i = 0; i < table->count; i++) {
            MdlAnimResourceEntry* entry;

            entry = (MdlAnimResourceEntry*)table->entries;
            entry += i;

            if ((entry->resource != NULL) && ((entry->flags & 1) == 0)) {
                func_00320290(entry->resource);
            }
        }

        (*DAT_0096017c)(table);
    }
}




// FUN_00313CA0 NONMATCHING


void func_00313ca0(int *param_1,u32 param_2)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  u8 *puVar5;

  int lVar6;

  int iVar7;

  float fVar8;

  u32 uVar9;

  

  if ((int *)*param_1 != (int *)0x0) {

    iVar7 = (int)param_2;

    sVar1 = *(short *)(iVar7 + 4);

    lVar6 = (int)sVar1;

    if (-1 < lVar6) {

      iVar2 = *(int *)*param_1;

      iVar3 = *(int *)(iVar2 + sVar1 * 8);

      if (*(float *)(iVar7 + 0x1c) < 1.0f) {

        iVar2 = *(int *)(iVar2 + *(short *)(iVar7 + 0x10) * 8);

        if (iVar2 != 0) {

          func_003204a0(*(u32 *)(iVar7 + 0x14),0,iVar2,iVar3);

        }

        else {

          if (iVar3 != 0) {

            func_00320640_frame(0,1.0f - *(float *)(iVar7 + 0x1c),iVar3);

          }

        }

        param_1[1] = iVar3;

      }

      else {

        if (iVar3 == 0) {

          if (param_1[1] != 0) {

            func_00320770();

          }

        }

        else {

          piVar4 = *(int **)(iVar7 + 0x2c);

          if ((((piVar4 == (int *)0x0) || ((u32)*(u16 *)(piVar4 + 1) <= (u32)lVar6)) ||

              (puVar5 = *(u8 **)(*piVar4 + 0x40 + (sVar1 * 4 + (int)sVar1) * 0x10),

              puVar5 == (u8 *)0x0)) || (puVar5 == (u8 *)&DAT_009571d0)) {

            func_00320380(*(u32 *)(iVar7 + 0xc),iVar3);

            fVar8 = func_00320810((void*)iVar3);

            if (fVar8 < *(float *)(iVar7 + 0xc)) {

              func_00313090(0,param_2);

            }

          }

          else {

            if (lVar6 < 0) {

              uVar9 = 0;

            }

            else {

              uVar9 = *(u32 *)(iVar7 + 0xc);

            }

            func_00320380(uVar9,iVar3);

          }

        }

        param_1[1] = iVar3;

      }

    }

  }

  return;

}




// FUN_00313E60


void func_00313e60(void* param_1)
{
  void *piVar1;
  int *piVar2;

  s32 uVar3;

  piVar2 = (int *)param_1;

  *(u16 *)((int)piVar2 + 0xe) = *(u16 *)((int)piVar2 + 0xe) + -1;

  if (*(u16 *)((int)piVar2 + 0xe) == 0) {
    if (piVar2[2] != 0) {
      func_004c20b0((void *)piVar2[2]);
    }

    if (piVar2[1] != 0) {
      func_004b78b0((void *)piVar2[1]);
    }

    for (uVar3 = 0; (uVar3 & 0xffff) < *(u16 *)(piVar2 + 3); uVar3 = uVar3 + 1 & 0xffff) {
      piVar1 = (void *)*piVar2;
      piVar1 = (void *)((u8 *)piVar1 + (u16)uVar3 * 8);

      if ((*(int *)piVar1 != 0) &&
          ((*(u8 *)((u8 *)piVar1 + 4) & 1) == 0)) {
        func_004b78b0(*(void **)piVar1);
      }
    }

    (*DAT_0096017c)(param_1);
  }

  return;
}




#pragma push
#pragma opt_propagation off
// FUN_00313F40


int func_00313f40(int param_1, void* param_2)
{
  int *piVar1;
  void* list;
  list = param_2;
  piVar1 = (int *)func_004c21d0(list);
  while (piVar1 != (int *)func_004c21e0(list)) {
    if (param_1 == *piVar1) {
      return param_1;
    }
    piVar1++;
  }

  *(int *)func_004c1e70(list,0) = param_1;
  return param_1;
}
#pragma pop




// FUN_00313FE0


void* func_00313fe0(void* param_1,u32 *param_2)
{
  func_004932c0(*(u32 *)((u8 *)param_1 + 0x18), *param_2, param_2[1]);
  return param_1;
}

// FUN_00314020
void FUN_00314020(f32* param_1, f32* param_2)
{
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
}

// FUN_00314060
void FUN_00314060(f32* param_1, f32* param_2)
{
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
}

// FUN_003140A0
void FUN_003140a0(void)
{
}

// FUN_003140B0
void FUN_003140b0(void)
{
}

// FUN_003140C0


void* func_003140c0(void* param_1,u16 *param_2)



{
  s16 rawIndex;
  u16 count;
  s64 lVar2;
  int *piVar1;
  rawIndex = (s16)param_2[2];
  piVar1 = *(int **)(param_2 + 0xc);
  if (piVar1 != (int *)0x0) {
    lVar2 = (s64)rawIndex;
    count = *(u16 *)(piVar1 + 3);
    if ((((lVar2 < (s64)(u32)count) &&
          (*(int *)(*piVar1 + rawIndex * 8) != 0)) && ((*param_2 & 1) == 0)) &&
        ((lVar2 < (s64)(u32)count && (0 <= rawIndex)))) {
      func_004b74c0_typed(*(f32 *)(*(int *)param_1 + 0xc),param_1);
      *(u8 *)(param_2 + 1) = 1;
    }
  }


  return param_1;

}



// FUN_00314170 NONMATCHING


void* func_00314170(void* param_1, void* param_2)



{

  int *piVar1;

  long lVar2;

  u16 *puVar3;

  int *piVar4;

  

  piVar4 = (int *)param_1;
  func_004b6ec0(param_1,*piVar4);
  piVar4[0x10] = (int)&LAB_00314020;
  piVar4[0x11] = (int)&LAB_00314060;


  if (param_2 != 0) {

    puVar3 = (u16 *)param_2;

    piVar1 = *(int **)(puVar3 + 0xc);

    if ((((piVar1 == (int *)0x0) || ((long)(u32)*(u16 *)(piVar1 + 3) <= (long)(short)puVar3[2])

         ) || (*(int *)(*piVar1 + (short)puVar3[2] * 8) == 0)) || ((*puVar3 & 1) == 0)) {

      piVar1 = *(int **)(puVar3 + 0xc);
      if (piVar1 != (int *)0x0) {

        lVar2 = (long)(short)puVar3[2];
        if ((((lVar2 < (long)(u32)*(u16 *)(piVar1 + 3)) &&
              (*(int *)(*piVar1 + (short)puVar3[2] * 8) != 0)) &&
             ((*puVar3 & 1) == 0)) &&
            ((lVar2 < (long)(u32)*(u16 *)(piVar1 + 3) &&
              (0 <= (short)puVar3[2])))) {

          func_004b74c0_typed(*(f32 *)(*piVar4 + 0xc),param_1);
          *(u8 *)(puVar3 + 1) = 1;
        }
      }
      return param_1;

    }

  }

  return param_1;

}



// FUN_003142B0
u32 func_003142b0(void* param_1)
{
    s32 iVar2;
    s32 iVar1;
    s32 uVar3;
    char* uVar4;
    s32 lVar5;
    s32 iVar6;
    void* iVar7;

    iVar1 = RpMaterialGetUserDataArrayCount();
    uVar3 = 0;
    while (uVar3 < iVar1)
    {
        iVar7 = RpMaterialGetUserDataArray(param_1, uVar3);
        uVar4 = RpUserDataArrayGetName(iVar7);
        if (strcmp(uVar4, DAT_007cca08) == 0)
        {
            iVar2 = func_0048ef30(iVar7);
            iVar6 = 0;
            while (iVar6 < iVar2)
            {
                lVar5 = RpUserDataArrayGetFormat(iVar7);
                if (lVar5 == 3)
                {
                    return (u32)func_0048ef80(iVar7, iVar6);
                }
                iVar6++;
            }
        }
        uVar3++;
    }
    return 0;
}




// FUN_003143C0


void func_003143c0(u8* param_1,RpClump* param_2)
{

  u32 uVar1;

  u32 *puVar2;

  u32 *puVar3;

  u32 userData;
  u32 animation;

  struct {
    code callback;
    u32 value;
  } callbackData;

  

  if ((*(int *)(param_1 + 0x18) != 0) &&

     (*(u32 *)(param_1 + 0xc) = 0, *(int *)(*(int *)(param_1 + 0x18) + 8) == 0)) {

    uVar1 = func_004c1d50(4,0);

    callbackData.callback = (code)func_00313f40;
    callbackData.value = uVar1;

    func_004916d0_callback(param_2,(void (*)(void))func_00313fe0,&callbackData);

    *(u32 *)(*(int *)(param_1 + 0x18) + 8) = uVar1;

    for (puVar2 = (u32 *)func_004c21d0(*(u32 *)(*(int *)(param_1 + 0x18) + 8));

        puVar3 = (u32 *)func_004c21e0(*(u32 *)(*(int *)(param_1 + 0x18) + 8)),

        puVar2 != puVar3; puVar2 = puVar2 + 1) {

      userData = func_003142b0((void*)*puVar2);

      if (((userData != 0) && (func_00524670(userData,&gp0xffff9d10,5) == 0)) &&

         (animation = func_004b97b0(*puVar2,0), animation != 0)) {

        func_004b7010(animation,func_00314170,0);

        *(u8 **)((int)animation + 0x40) = LAB_00314020_abs;

        *(u8 **)((int)animation + 0x44) = LAB_00314060_abs;

      }

    }

  }

  return;

}




// FUN_00314510
void* func_00314510(void* param_1)
{
  int iVar1;
  int iVar2;
  int iVar5;
  int bVar3;
  s32 lVar4;

  iVar1 = *(int *)((u8*)param_1 + 0x18);
  if (iVar1 == 0) {
    return param_1;
  }
  lVar4 = func_0048a2c0(iVar1);
  if (lVar4 != 0) {
    bVar3 = false;
    iVar2 = *(int *)((u8*)iVar1 + 0x24);
    iVar5 = 0;
    while ((iVar5 < iVar2 && (!bVar3))) {
      lVar4 = func_00469030(*(u32 *)(*(int *)((u8*)iVar1 + 0x20) + iVar5 * 4));
      if (lVar4 != 0) {
        bVar3 = true;
      }
      iVar5 = iVar5 + 1;
    }
    lVar4 = func_0048a480(param_1);
    if (((lVar4 == 2) || (lVar4 == 1)) || ((lVar4 != 3 && (lVar4 != 0)))) {
      if (bVar3) {
        func_0048a3f0(param_1,2);
      }
      else {
        func_0048a3f0(param_1,1);
      }
    }
  }
  else {
    func_00468dc0(param_1);
  }
  return param_1;
}




// FUN_00314650


u32 func_00314650(u32 param_1)
{
    int iVar1;
    int iVar2;
    u32 lVar3;
    u32 uVar4;
    int iVar5;

    iVar1 = *(int *)((int)param_1 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_0048a2c0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_0048a3d0(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    iVar2 = *(int *)(iVar1 + 0x24);
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
        func_00312e80(*(u32 *)(*(int *)(iVar1 + 0x20) + iVar5 * 4));
    }

    return param_1;
}




// FUN_00314730


void func_00314730(u8* param_2,f32 param_1)
{

  u32 *puVar2;

  u32 uVar1;

  u32 *puVar3;

  u32 lVar4;

  

  if ((*(int *)(param_2 + 0x18) != 0) && (*(int *)(*(int *)(param_2 + 0x18) + 8) != 0)) {

    *(f32 *)(param_2 + 0xc) = param_1;

    *(f32 *)(param_2 + 0x10) = param_1;

    uVar1 = *(u32 *)(*(int *)(param_2 + 0x18) + 8);

    for (puVar2 = (u32 *)func_004c21d0(uVar1); puVar3 = (u32 *)func_004c21e0(uVar1),

        puVar2 != puVar3; puVar2 = puVar2 + 1) {

      lVar4 = func_00469030(*puVar2);

      switch (lVar4) {
      case 5:
      case 6:

        lVar4 = func_004b97b0(*puVar2,0);

        if (lVar4 != 0) {

          func_004b74c0_ptrfirst(lVar4,param_1);

        }

        if ((*(u8 *)(param_2 + 2) != 1) && (lVar4 = func_004b97b0(*puVar2,1), lVar4 != 0)) {

          func_004b74c0_ptrfirst(lVar4,param_1);

        }

        break;

      }

    }

  }

  return;

}




// FUN_00314850 NONMATCHING


void func_00314850(RpClump* param_1,void* param_2,s16 param_3,u16 param_4,u16 param_5)
{

  u16 uVar1;

  int iVar2;

  u32 *puVar3;

  int iVar4;

  u32 *puVar5;

  u32 lVar6;

  u32 lVar7;

  u32 lVar8;

  u16 *puVar9;

  int *piVar10;

  int iVar11;

  

  puVar9 = (u16 *)param_2;

  if (*(int *)(puVar9 + 0xc) == 0) {

    return;

  }

  *puVar9 = *puVar9 & 0xfffe;

  *puVar9 = *puVar9 | param_5 & 1;

  *(u8 *)(puVar9 + 1) = 0;

  puVar9[8] = 0;

  puVar9[9] = 0;

  if (param_4 != 0) {

    uVar1 = puVar9[2];

    if ((((((long)(short)uVar1 != -1) && (piVar10 = *(int **)(puVar9 + 0xc), piVar10 != (int *)0x0))

         && ((long)(short)uVar1 < (long)(u32)*(u16 *)(piVar10 + 3))) &&

        ((*(int *)(*piVar10 + (short)uVar1 * 8) != 0 && (piVar10 != (int *)0x0)))) &&

       (((long)(short)param_3 < (long)(u32)*(u16 *)(piVar10 + 3) &&

        (*(int *)(*piVar10 + (short)param_3 * 8) != 0)))) {

      puVar9[10] = param_4;

      goto LAB_0031494c;

    }

  }

  puVar9[10] = 0;

LAB_0031494c:

  piVar10 = *(int **)(puVar9 + 0xc);

  if (((piVar10 == (int *)0x0) || ((long)(u32)*(u16 *)(piVar10 + 3) <= (long)(short)param_3))

     || (*(int *)(*piVar10 + (short)param_3 * 8) == 0)) {

    iVar2 = piVar10[2];

    for (puVar3 = (u32 *)func_004c21d0(iVar2); puVar5 = (u32 *)func_004c21e0(iVar2),

        puVar3 != puVar5; puVar3 = puVar3 + 1) {

      lVar6 = func_003142b0((void*)*puVar3);

      if ((lVar6 != 0) && (lVar6 = func_004b97b0(*puVar3,1), lVar6 != 0)) {

        func_004b92d0(*(u32 *)lVar6);

        func_004b6eb0(lVar6);

        func_004b97d0(*puVar3,0,1);

      }

    }

  }

  else {

    iVar2 = piVar10[2];

    for (puVar3 = (u32 *)func_004c21d0(iVar2); puVar5 = (u32 *)func_004c21e0(iVar2),

        puVar3 != puVar5; puVar3 = puVar3 + 1) {

      lVar6 = func_00469030(*puVar3);

      if ((lVar6 == 6) || (lVar6 == 5)) {

        func_004699b0(*puVar3,0,0);

      }

      lVar6 = func_003142b0((void*)*puVar3);

      if (lVar6 != 0) {

        lVar7 = func_004b77f0(*(u32 *)((short)param_3 * 8 + **(int **)(puVar9 + 0xc)),lVar6);

        if (lVar7 != 0) {

          lVar6 = func_00524670(lVar6,0x7cca00,5);

          lVar8 = func_004b97b0(*puVar3,1);

          piVar10 = (int *)lVar7;

          if (lVar8 != 0) {

            puVar5 = (u32 *)lVar8;

            func_004b92d0(*puVar5);

            iVar11 = puVar5[0xb];

            iVar4 = func_004b6dd0(lVar7);

            if ((iVar11 != iVar4) || (puVar5[9] != *(int *)(*piVar10 + 4))) {

              func_004b6eb0(lVar8);

              lVar8 = 0;

            }

          }

          if (lVar8 == 0) {

            func_004b96f0(*puVar3,lVar7,1);

            lVar8 = func_004b97b0(*puVar3,1);

          }

          else {

            func_004b6ec0(lVar8,lVar7);

            func_004b9350(lVar7);

          }

          lVar7 = func_004b6dd0(lVar7);

          if (lVar7 == 1) {

            func_00468ea0(*puVar3,5);

          }

          else {

            func_00468ea0(*puVar3,6);

          }

          iVar11 = (int)lVar8;

          if (lVar6 == 0) {

            func_004b7010(lVar8,0x314170,param_2);

            *(u8 **)(iVar11 + 0x40) = &LAB_00314020;

            *(u8 **)(iVar11 + 0x44) = &LAB_00314060;

          }

          else {

            func_004b7010(lVar8,0x3140c0,param_2);

            *(u32 *)(iVar11 + 0x40) = *(u32 *)(*piVar10 + 0x10);

            *(u32 *)(iVar11 + 0x44) = *(u32 *)(*piVar10 + 0x14);

          }

        }

        else {

          lVar6 = func_004b97b0(*puVar3,1);

          if (lVar6 != 0) {

            piVar10 = (int *)lVar6;

            if (*piVar10 != 0) {

              func_004b74c0(0,lVar6);

            }

            piVar10[0x10] = (int)&LAB_003140a0;

            piVar10[0x11] = (int)&LAB_003140b0;

          }

        }

      }

    }

    func_004916d0(param_1,0x314650,0);

    func_004916d0(param_1,0x314510,0);

  }

  puVar9[2] = param_3;

  return;

}




// FUN_00314D30 NONMATCHING


void func_00314d30(void* param_1)
{

  u32 uVar1;

  u32 *puVar2;

  u32 *puVar3;

  u32 lVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  

  iVar5 = (int)param_1;

  if ((*(int *)(iVar5 + 0x18) != 0) && (*(int *)(*(int *)(iVar5 + 0x18) + 8) != 0)) {

    if (*(short *)(iVar5 + 0x14) == 0) {

      fVar7 = DAT_007cadd4 * *(float *)(iVar5 + 8);

    }

    else {

      fVar7 = 0.0;

      *(short *)(iVar5 + 0x14) = *(short *)(iVar5 + 0x14) + -1;

    }

    *(float *)(iVar5 + 0xc) = *(float *)(iVar5 + 0xc) + DAT_007cadd4;

    *(float *)(iVar5 + 0x10) = *(float *)(iVar5 + 0x10) + fVar7;

    uVar1 = *(u32 *)(*(int *)(iVar5 + 0x18) + 8);

    for (puVar2 = (u32 *)func_004c21d0(uVar1); puVar3 = (u32 *)func_004c21e0(uVar1),

        puVar2 != puVar3; puVar2 = puVar2 + 1) {

      lVar4 = func_00469030(*puVar2);

      if ((lVar4 == 6) || (lVar4 == 5)) {

        lVar4 = func_004b97b0(*puVar2,0);

        if (lVar4 != 0) {

          iVar6 = (int)lVar4;

          if ((*(u8 **)(iVar6 + 0x40) == LAB_00314020_abs) &&
             (*(u8 **)(iVar6 + 0x44) == LAB_00314060_abs)) {

            func_004b7240_frame(DAT_007cadd4, lVar4);

          }

          else {

            func_004b74c0_frame(*(f32*)(iVar5 + 0xc), lVar4);

          }

          *(u32 *)(iVar5 + 0xc) = *(u32 *)(iVar6 + 4);

        }

        if (*(char *)(iVar5 + 2) == '\x01') {

          lVar4 = func_004b97b0(*puVar2);

          if (lVar4 != 0) {

            if ((*(u8 **)((int)lVar4 + 0x40) == LAB_00314020_abs) &&
               (*(u8 **)((int)lVar4 + 0x44) == LAB_00314060_abs)) {

              func_004b7010(lVar4,0x314170,param_1);

            }

            else {

              func_004b7010(lVar4,0x3140c0,param_1);

            }

          }

        }

        else {

          lVar4 = func_004b97b0(*puVar2);

          if (lVar4 != 0) {

            iVar6 = (int)lVar4;

            if ((*(u8 **)(iVar6 + 0x40) == LAB_00314020_abs) &&
               (*(u8 **)(iVar6 + 0x44) == LAB_00314060_abs)) {

              func_004b7010(lVar4,0x314170,param_1);

              func_004b7240_frame(fVar7,lVar4);

            }

            else {

              func_004b7010(lVar4,0x3140c0,param_1);

              if ((*(u8 **)(iVar6 + 0x40) != LAB_003140a0_abs) &&
                 (*(u8 **)(iVar6 + 0x44) != LAB_003140b0_abs)) {

                func_004b74c0_frame(*(f32*)(iVar5 + 0x10), lVar4);

              }

            }

            *(u32 *)(iVar5 + 0x10) = *(u32 *)(iVar6 + 4);

          }

        }

        func_004b9370(*puVar2);

      }

    }

  }

  return;

}




// FUN_00315010


void* func_00315010(void* object, void* data)
{
    if (*(void**)((u8*)data + 4) == (void*)func_00466720()) {
        *(void**)data = object;
        return NULL;
    }

    func_004cb6e0(object, (void (*)(void))func_00315010, data);
    return object;
}




/* W323 measured func_00315090 opt_loop_invariants on: nd195 -> nd188; object 292/320. */
#pragma push
#pragma opt_loop_invariants on
/* W323 callback symbol literal nd188 -> nd185. */
// FUN_00315090 NONMATCHING


u32 func_00315090(RwMatrix* param_1,u16 *param_2,u16 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  struct {
    int result;
    int expected;
  } callbackData;

  

  uVar5 = 0;

  while ((uVar5 < *param_2 &&

         ((param_3 & 0xffff) != *(u32 *)(*(int *)(param_2 + 2) + uVar5 * 0x50 + 0x40)))) {

    uVar5 = uVar5 + 1 & 0xffff;

  }

  if (uVar5 != *param_2) {

    iVar7 = *(int *)(param_2 + 2) + uVar5 * 0x50;

    iVar1 = *(int *)(iVar7 + 0x44);

    iVar6 = *(int *)(param_4 + 4);

    iVar2 = func_00466720(iVar6);

    if (iVar1 != iVar2) {

      callbackData.result = 0;
      callbackData.expected = iVar1;
      func_004cb6e0(iVar6,(void *)func_00315010,&callbackData);
      iVar6 = callbackData.result;

    }

    if (iVar6 != 0) {

      uVar4 = func_004cb2f0(iVar6);

      FUN_004c2f30(param_1,(const RwMatrix*)iVar7,(const RwMatrix*)uVar4);

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}
#pragma pop




// FUN_003151D0 NONMATCHING


void func_003151d0(Model* param_1)



{

  u8 bVar1;

  u8 bVar2;

  u32 uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  bool bVar7;

  u32 uVar8;

  int iVar9;

  long lVar10;

  int iVar11;

  bool bVar12;

  u32 uVar13;

  bool bVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fStack_130;

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  float fStack_114;

  float fStack_110;

  float fStack_10c;

  float fStack_108;

  float fStack_104;

  float fStack_100;

  float fStack_fc;

  float fStack_f8;

  float fStack_f4;

  float fStack_f0;

  int iStack_ec;

  RwMatrix lightMatrix;

  u8 auStack_a0 [64];

  u8 auStack_60 [72];

  float fStack_18;

  float fStack_14;

  float fStack_10;

  u32 uStack_8;

  u8 color[4];

  

  iVar11 = (int)param_1;

  bVar1 = *(u8 *)(iVar11 + 0x3a9);

  uVar13 = (u32)bVar1;

  bVar2 = *(u8 *)(iVar11 + 0x3a8);

  if (bVar2 < uVar13) {

    uVar8 = (u32)bVar2 + (u32)*(u8 *)(iVar11 + 0x3aa);

    if (uVar13 < uVar8) {

      *(u8 *)(iVar11 + 0x3a8) = bVar1;

    }

    else {

      *(char *)(iVar11 + 0x3a8) = (char)uVar8;

    }

  }

  else if (uVar13 < bVar2) {

    iVar9 = (u32)bVar2 - (u32)*(u8 *)(iVar11 + 0x3aa);

    if (iVar9 < (int)uVar13) {

      *(u8 *)(iVar11 + 0x3a8) = bVar1;

    }

    else {

      *(char *)(iVar11 + 0x3a8) = (char)iVar9;

    }

  }

  else {

    *(u8 *)(iVar11 + 0x3a8) = bVar1;

  }

  color[0] = 0;
  color[1] = 0;
  color[2] = 0;

  fVar15 = ((float)((u32)*(u8 *)(iVar11 + 0x3a8) * (u32)*(u8 *)(iVar11 + 0xd3)) / 65025.0f) *

           255.0f;

  if (fVar15 < 2.1474836e+09f) {

    color[3] = (char)(int)fVar15;

  }

  else {

    color[3] = (char)(int)(fVar15 - 2.1474836e+09f);

  }

  if (((*(u8 *)(iVar11 + 0x388) & 1) == 0) || ((*(u8 *)(iVar11 + 0x388) & 0x20) != 0)) {

    iVar9 = func_00198580();

    iVar9 = *(int *)(iVar9 + 4);

  }

  else {

    iVar9 = kwlnGetDirectionalLight();

    iVar9 = *(int *)(iVar9 + 4);

  }

  bVar1 = *(u8 *)(iVar11 + 0x388);

  if (((bVar1 & 2) == 0) || ((bVar1 & 0x20) != 0)) {

    RtQuatConvertFromMatrix((RtQuat*)(iVar11 + 0x38c),(const RwMatrix*)(iVar9 + 0x10));

    fStack_18 = *(float *)(iVar9 + 0x30);

    fStack_14 = *(float *)(iVar9 + 0x34);

    fStack_10 = *(float *)(iVar9 + 0x38);

  }

  else {

    if ((bVar1 & 4) == 0) {

      RtQuatConvertFromMatrix((RtQuat*)&fStack_130,(const RwMatrix*)(iVar9 + 0x10));

    }

    else {

      fStack_130 = DAT_007caf0c;

      fStack_12c = 0.0f;

      fStack_128 = 0.0f;

      fStack_124 = DAT_007caf0c;

    }

    fVar15 = *(float *)(iVar11 + 0x398) * fStack_124 +

             *(float *)(iVar11 + 0x394) * fStack_128 +

             *(float *)(iVar11 + 0x38c) * fStack_130 + *(float *)(iVar11 + 0x390) * fStack_12c;

    if (fVar15 < 0.0f) {

      fStack_114 = -fStack_124;

      fStack_120 = -fStack_130;

      fStack_11c = -fStack_12c;

      fStack_118 = -fStack_128;

      fVar15 = *(float *)(iVar11 + 0x398) * fStack_114 +

               *(float *)(iVar11 + 0x394) * fStack_118 +

               *(float *)(iVar11 + 0x38c) * fStack_120 +

               *(float *)(iVar11 + 0x390) * fStack_11c;

    }

    fVar16 = (float)func_0052e9e8(fVar15);

    fVar15 = *(float *)(iVar11 + 0x3ac);

    if (fVar15 < 1.0f) {

      if ((*(float *)(iVar11 + 0x3b0) < fVar16 * 2.0f) &&

         (fVar16 = *(float *)(iVar11 + 0x3b0) / (fVar16 * 2.0f), fVar15 <= fVar16)) {

        fVar15 = fVar16;

      }

      func_004be310(iVar11 + 0x38c,&fStack_130,&fStack_110);

      if (fVar15 <= 0.0f) {

        fStack_120 = *(float *)(iVar11 + 0x38c);

        fStack_11c = *(float *)(iVar11 + 0x390);

        fStack_118 = *(float *)(iVar11 + 0x394);

        fStack_114 = *(float *)(iVar11 + 0x398);

      }

      else if (1.0f <= fVar15) {

        fStack_120 = fStack_130;

        fStack_11c = fStack_12c;

        fStack_118 = fStack_128;

        fStack_114 = fStack_124;

      }

      else {

        fVar16 = 1.0f - fVar15;

        if (iStack_ec == 0) {

          fVar16 = fVar16 * fStack_f0;

          fVar17 = fVar16 * fVar16;

          fVar16 = fVar17 * fVar16 *

                   (fVar17 * (fVar17 * (fVar17 * (fVar17 * (DAT_007caf10 * fVar17 +

                                                           DAT_007cad38) + DAT_007cae08)

                                       + DAT_007cad40) + DAT_007cad44) +

                   DAT_007caed0) + fVar16;

          fVar15 = fVar15 * fStack_f0;

          fVar17 = fVar15 * fVar15;

          fVar15 = fVar17 * fVar15 *

                   (fVar17 * (fVar17 * (fVar17 * (fVar17 * (DAT_007caf10 * fVar17 +

                                                           DAT_007cad38) + DAT_007cae08)

                                       + DAT_007cad40) + DAT_007cad44) +

                   DAT_007caed0) + fVar15;

        }

        fStack_120 = fStack_100 * fVar15 + fStack_110 * fVar16;

        fStack_11c = fStack_fc * fVar15 + fStack_10c * fVar16;

        fStack_118 = fStack_f8 * fVar15 + fStack_108 * fVar16;

        fStack_114 = fStack_104 * fVar16 + fStack_f4 * fVar15;

      }

      *(float *)(iVar11 + 0x38c) = fStack_120;

      *(float *)(iVar11 + 0x390) = fStack_11c;

      *(float *)(iVar11 + 0x394) = fStack_118;

      *(float *)(iVar11 + 0x398) = fStack_114;

    }

    else {

      *(float *)(iVar11 + 0x38c) = fStack_130;

      *(float *)(iVar11 + 0x390) = fStack_12c;

      *(float *)(iVar11 + 0x394) = fStack_128;

      *(float *)(iVar11 + 0x398) = fStack_124;

    }

    RtQuatTransformVectors((RwV3d*)&fStack_18,(const RwV3d*)0x69ab88,1,(const RtQuat*)(iVar11 + 0x38c));

  }

  fVar15 = DAT_007caf0c;

  if (color[3] != '\0') {

    if (0.0f <= fStack_14) {

      *(float *)(iVar11 + 0x38c) = DAT_007caf0c;

      *(u32 *)(iVar11 + 0x390) = 0;

      *(u32 *)(iVar11 + 0x394) = 0;

      *(float *)(iVar11 + 0x398) = fVar15;

      RtQuatTransformVectors((RwV3d*)&fStack_18,(const RwV3d*)0x69ab88,1,(const RtQuat*)(iVar11 + 0x38c));

    }

    fVar15 = *(float *)(iVar11 + 0x39c);

    if (fVar15 != *(float *)(iVar11 + 0x3a0)) {

      *(float *)(iVar11 + 0x39c) =

           *(float *)(iVar11 + 0x3a4) * (*(float *)(iVar11 + 0x3a0) - fVar15) + fVar15;

    }

    fVar15 = *(float *)(iVar11 + 0x39c);

    if (((fStack_14 < 0.0f ? -fStack_14 : fStack_14) < fVar15) &&
        (bVar7 = fStack_14 < 0.0f, fStack_14 = fVar15, bVar7)) {

      fStack_14 = -fVar15;

    }

    lightMatrix.at.z = 1.0f;
    lightMatrix.right.x = 1.0f;
    lightMatrix.right.z = 0.0f;
    lightMatrix.right.y = 0.0f;
    lightMatrix.at.y = 0.0f;
    lightMatrix.at.x = 0.0f;
    lightMatrix.pos.z = 0.0f;
    lightMatrix.pos.y = 0.0f;
    lightMatrix.pos.x = 0.0f;
    lightMatrix.flags = lightMatrix.flags | 0x20003;
    lightMatrix.up.x = -fStack_18 / fStack_14;
    lightMatrix.up.y = DAT_007cada0;
    lightMatrix.up.z = -fStack_10 / fStack_14;

    uVar3 = *(u32 *)(*(int *)(iVar11 + 0xdc) + 4);

    FUN_004c2f30((RwMatrix*)auStack_a0,(const RwMatrix*)(iVar11 + 0x40),(RwMatrix*)param_1);

    FUN_004c2f30((RwMatrix*)auStack_60,(const RwMatrix*)auStack_a0,&lightMatrix);

    func_004cb7f0(uVar3,auStack_60,0);

    if ((*(u16 *)(iVar11 + 0x138) & 0x4000) == 0) {

      func_00466ef0(*(u32 *)(iVar11 + 0x10c));

    }

    else {

      func_00311730((u32*)(*(u32 *)(iVar11 + 0x10c)),(u16*)(iVar11 + 0xec),(u16*)(iVar11 + 0x138),0);

    }

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,0);

    (*DAT_00960094)(0xe,&uStack_8);

    (*DAT_00960090)(0xe,0);

    RpSkyRenderStateSet(2, (void*)0x44);

    func_00316320(*(u32 *)(iVar11 + 0xdc),(u32*)color,(*(u8 *)(iVar11 + 0x388) & 8) != 0);

    iVar9 = *(int *)(iVar11 + 0xe0);

    if (iVar9 == 0) {

      RpSkyRenderStateSet(3, (void*)0x7c01b);

    }

    else if (((*(int *)(iVar9 + 0x10) == 0) && (*(int *)(iVar9 + 0x1c) == 0)) ||

            ((*(u8 *)(iVar11 + 0x388) & 0x80) != 0)) {

      RpSkyRenderStateSet(3, (void*)0x7d7fb);

    }

    else {

      RpSkyRenderStateSet(3, (void*)0x7f08b);

    }

    func_001a88e0(*(u32 *)(iVar11 + 0xdc));

    func_003176c0(param_1);

    for (uVar13 = 0; uVar13 < 5; uVar13 = uVar13 + 1 & 0xffff) {

      iVar9 = iVar11 + uVar13 * 0xc;

      if ((((*(u8 *)(iVar9 + 0x3b4) & 1) != 0) && (*(int *)(iVar9 + 0x3b8) != 0)) &&

         ((lVar10 = mdl00319770(param_1,uVar13), lVar10 != 0 &&

          (iVar9 = *(int *)(iVar9 + 0x3b8), (*(u16 *)(iVar9 + 0xd8) & 2) == 0)))) {

        iVar4 = *(int *)(iVar9 + 0xdc);

        uVar3 = *(u32 *)(iVar4 + 4);

        FUN_004c2f30((RwMatrix*)auStack_a0,(const RwMatrix*)(iVar9 + 0x40),(RwMatrix*)iVar9);

        FUN_004c2f30((RwMatrix*)auStack_60,(const RwMatrix*)auStack_a0,&lightMatrix);

        func_004cb7f0(uVar3,auStack_60,0);

        bVar7 = false;

        bVar14 = false;

        bVar12 = false;

        piVar5 = *(int **)(iVar9 + 0x118);

        if ((piVar5 != (int *)0x0) &&

           ((long)*(short *)(iVar9 + 0xf0) < (long)(u32)*(u16 *)(piVar5 + 1))) {

          bVar12 = true;

        }

        if ((bVar12) && (*(int *)(*piVar5 + *(short *)(iVar9 + 0xf0) * 0x50 + 0x40) != 0)) {

          bVar14 = true;

        }

        if ((bVar14) &&

           (*(u8 **)(*piVar5 + *(short *)(iVar9 + 0xf0) * 0x50 + 0x40) != (u8 *)&DAT_009571d0)) {

          bVar7 = true;

        }

        if (bVar7) {

          func_00466ef0(*(u32 *)(iVar9 + 0x10c));

        }

        func_00316320(iVar4,(u32*)color,(*(u8 *)(iVar9 + 0x388) & 8) != 0);

        iVar6 = *(int *)(iVar11 + 0xe0);

        if (iVar6 == 0) {

          RpSkyRenderStateSet(3, (void*)0x7c01b);

        }

        else if ((*(int *)(iVar6 + 0x10) == 0) && (*(int *)(iVar6 + 0x1c) == 0)) {

          RpSkyRenderStateSet(3, (void*)0x7d7fb);

        }

        else {

          RpSkyRenderStateSet(3, (void*)0x7f08b);

        }

        func_001a88e0(iVar4);

        if (bVar7) {

          func_003176c0((Model*)iVar9);

        }

      }

    }

    (*DAT_00960090)(0xe,uStack_8);

    RpSkyRenderStateSet(3, (void*)0x717fb);

    (*DAT_00960090)(8,1);

  }

  return;

}




// FUN_00315C20 NONMATCHING


void func_00315c20(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  long lVar3;

  int *piVar4;

  u32 uStack_4;

  

  if ((*(u16 *)(param_1 + 0xd8) & 0x400) != 0) {

    mdl003164c0((void*)*(u32 *)(param_1 + 0xdc));

  }

  RpSkyRenderStateSet(2, (void*)100);

  if (((*(u16 *)(param_1 + 0xd8) & 0x200) == 0) || ((*(u16 *)(param_1 + 0xd8) & 0x400) != 0))

  {

    RpSkyRenderStateSet(3, (void*)0x7000f);

  }

  else if (*(u8 *)(param_1 + 0xd3) < 0xc9) {

    RpSkyRenderStateSet(3, (void*)0x7008d);

  }

  else {

    RpSkyRenderStateSet(3, (void*)0x704fd);

  }

  (*DAT_00960090)(6,1);

  (*DAT_00960094)(0xe,&uStack_4);

  (*DAT_00960090)(0xe,0);

  uVar1 = DAT_00960070;

  if ((*(int *)(param_1 + 0xe0) == 0) || ((*(u16 *)(param_1 + 0xd8) & 0x200) != 0)) {

    func_001a88e0(*(u32 *)(param_1 + 0xdc));

  }

  else {

    for (piVar4 = *(int **)(*(int *)(param_1 + 0xe0) + 8); piVar4 != (int *)0x0;

        piVar4 = (int *)piVar4[10]) {

      uVar2 = func_004912b0(*piVar4);

      lVar3 = RwCameraFrustumTestSphere((const RwCamera*)uVar1,(const RwSphere*)uVar2);

      if (lVar3 != 0) {

        (*(code *)(*piVar4 + 0x48))();

      }

    }

  }

  (*DAT_00960090)(0xe,uStack_4);

  if ((*(int *)(param_1 + 0xe0) == 0) || ((*(u16 *)(param_1 + 0xd8) & 0x800) != 0)) {

    RpSkyRenderStateSet(2, (void*)*(u32 *)(param_1 + 0xe4));

    RpSkyRenderStateSet(3, (void*)*(u32 *)(param_1 + 0xe8));

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,0);

    func_001a88e0(*(u32 *)(param_1 + 0xdc));

  }

  else {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,0);

    uVar1 = *(u32 *)(param_1 + 0xe0);

    func_001a7b50(uVar1,0);

    func_001a7fc0(uVar1,0);

    func_001a8140(uVar1,0);

  }

  return;

}




// FUN_00315ED0


Model* func_00315ed0(Model* param_1)



{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  
  iVar1 = *(int *)((int)param_1 + 0x18);
  uVar2 = *(u32 *)(iVar1 + 0x24);
  for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
    func_001b5a30(((u32 *)*(int *)(iVar1 + 0x20))[uVar3]);
  }

  return param_1;

}



// FUN_00315F50 NONMATCHING
u32 func_00315f50(void* param_1,u32 *param_2)



{

  int iVar1;

  u32 uVar2;

  u8 *pbVar3;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;
  RwRGBA color;

  

  iVar1 = *(int *)((int)param_1 + 0x18);

  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 0x40;

  uVar2 = *(u32 *)(iVar1 + 0x24);

  pbVar3 = (u8 *)*param_2;

  fVar12 = DAT_007caf08 * (float)*pbVar3;

  fVar13 = DAT_007caf08 * (float)pbVar3[1];

  fVar10 = DAT_007caf08 * (float)pbVar3[2];

  fVar11 = DAT_007caf08 * (float)pbVar3[3];

  for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1) {

    iVar4 = *(int *)(*(int *)(iVar1 + 0x20) + uVar6 * 4);

    uVar5 = K_Clump_MatUsrDataGetInt(iVar4,0x69aba0);
    color.b = (u8)uVar5;
    color.g = (u8)(uVar5 >> 8);
    color.r = (u8)(uVar5 >> 0x10);
    color.a = (u8)(uVar5 >> 0x18);

    fVar9 = DAT_007caf08 * (float)color.g;
    fVar7 = DAT_007caf08 * (float)color.b;

    fVar8 = fVar11;

    if ((*(u16 *)(param_2 + 1) & 1) == 0) {

      fVar8 = DAT_007caf08 * (float)color.a * fVar11;

    }

    *(char *)(iVar4 + 4) =

         (char)(int)(DAT_007caf08 * (float)color.r * fVar12 * 255.0f + 0.5f);

    *(char *)(iVar4 + 5) = (char)(int)(fVar9 * fVar13 * 255.0f + 0.5f);

    *(char *)(iVar4 + 6) = (char)(int)(fVar7 * fVar10 * 255.0f + 0.5f);

    *(char *)(iVar4 + 7) = (char)(int)(fVar8 * 255.0f + 0.5f);

  }

  return (u32)param_1;

}




// FUN_00316320


void func_00316320(u64 param_1,u32* param_2,u16 param_3)



{

  struct {
    u32* ptr;
    u16 value;
  } context;

  context.ptr = param_2;
  context.value = param_3;
  func_004916d0_typed(param_1, (void *)func_00315f50, &context);
  return;

}




// FUN_00316360


u32 func_00316360(void* param_1,u32 *param_2)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    u32 *entries;

    iVar1 = *(int *)((int)param_1 + 0x18);
    uVar2 = *(u32 *)(iVar1 + 0x24);
    uVar4 = 0;
    while (uVar4 < uVar2)
    {
        entries = *(u32 **)(iVar1 + 0x20);
        uVar3 = K_Clump_MatUsrDataGetInt(entries[uVar4], "per3modelMatColor");
        if (uVar3 >> 0x18 != 0)
        {
            *param_2 = 0;
            return 0;
        }
        uVar4 = uVar4 + 1;
    }
    return (u32)param_1;
}




// FUN_00316410


u32 func_00316410(void* param_1)
{
  extern u32 func_00469030(u32);
  extern void func_00469510(u32, u32);
  u8 *interp;
  u32 count;
  u32 index;
  u32 entry;

  interp = *(u8 **)((u8 *)param_1 + 0x18);
  count = *(u32 *)(interp + 0x24);
  for (index = 0; index < count; index++) {
    entry = *(u32 *)(*(u32 **)(interp + 0x20) + index);
    if ((func_00469030(entry) & 2) != 0) {
      func_00469510(entry, 1);
    }
  }
  return (u32)param_1;
}




#pragma push
#pragma opt_loop_invariants on
// FUN_003164F0 NONMATCHING


void func_003164f0(int param_1,int param_2)



{

  u16 uVar1;
  int iVar2;
  int iVar3;
  u16 uVar4;
  float fVar5;
  float in_f5;
  float in_f1;

  
  

  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1) {


    iVar3 = param_2 + uVar1 * 2;
    if (0 < (int)*(u16 *)(iVar3 + 0x198)) {

      if (uVar1 == 0) {

        fVar5 = 1.0f / *(float *)(param_2 + 0x184);
        in_f5 = (1.0f / *(float *)(param_2 + 0x188)) *
                (fVar5 * (*(float *)(param_2 + 0x18c) * *(float *)(param_2 + 0x190)));

        in_f1 = *(float *)(param_2 + 0x18c) * fVar5;

      }

      for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {

        iVar2 = param_1 + uVar4 * 0x9c;

        *(float *)(iVar2 + 0x124) = in_f1;

        *(float *)(iVar2 + 0x128) = in_f5;

        *(float *)(iVar2 + 0x12c) = in_f5;

        *(float *)(iVar2 + 0x130) = *(float *)(param_2 + 0x18c);

        *(float *)(iVar2 + 0x134) = *(float *)(param_2 + 0x190);

        *(u32 *)(iVar2 + 0x120) = (u32)*(u16 *)(iVar3 + 0x198);

        *(u16 *)(iVar2 + 0xec) = *(u16 *)(iVar2 + 0xec) | 0x10;

      }

    }

  }

  return;

}
#pragma pop




#pragma push
/* Removing this loses FUN_003165e0 (MATCH nd0 -> MISMATCH nd51) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003165E0


void* func_003165e0(void* param_1)
{
  int iVar1;
  u32 uVar2;
  int offset;
  int base;
  int iVar3;
  int iVar4;
  u32 uVar5;
  f32 two;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  volatile /* Removing this qualifier loses func_003165e0 (MATCH nd0 -> MISMATCH nd105, size 172 -> 132) - measured W170. */ f32 values[4];

  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 0x18);
  if (iVar1 == 0)
    goto done;

  uVar2 = *(u32 *)(iVar1 + 0x18);
  uVar5 = 0;
  two = 2.0f;
  goto check;

loop:
  offset = uVar5 * 8;
  offset = offset - uVar5;
  offset = offset * 4;
  base = *(int *)(iVar1 + 0x5c);
  iVar3 = base + offset;
  values[0] = *(f32 *)(iVar3 + 4);
  values[1] = *(f32 *)(iVar3 + 8);
  values[2] = *(f32 *)(iVar3 + 0xc);
  values[3] = two * *(f32 *)(iVar3 + 0x10);
  x = values[0];
  y = values[1];
  z = values[2];
  w = values[3];
  *(f32 *)(iVar3 + 4) = x;
  *(f32 *)(iVar3 + 8) = y;
  *(f32 *)(iVar3 + 0xc) = z;
  *(f32 *)(iVar3 + 0x10) = w;
  uVar5 = uVar5 + 1;
check:
  if (uVar5 < uVar2)
    goto loop;

done:
  *(u32 *)(iVar4 + 0x4c) = *(u32 *)(iVar4 + 0x4c) | 2;
  return param_1;
}
#pragma pop




/* W323 measured func_00316970 opt_common_subs off: nd259 -> nd197; object 456/464. */
#pragma push
#pragma opt_common_subs off
/* W323 followups: base pointer nd197 -> nd184; callback symbols nd184 -> nd168; -1 width nd168 -> nd122; hierarchy local nd122 -> nd107; stack-init order nd107 -> nd101. */
// FUN_00316970 NONMATCHING


void func_00316970(Model* param_1)
{

  u32 uVar1;

  int lVar2;

  int iVar3;

  u32 uVar4;

  u32 *pVar6;
  u32 *hierarchy;
  int iVar5;

  u32 uStack_4;

  

  iVar3 = (int)param_1;

  func_004916d0(*(u32 *)(iVar3 + 0xdc),(void *)func_003165e0,0);

  if (*(int *)(iVar3 + 0x37c) != 0) {
    func_003143c0((u8 *)param_1 + 0x364,param_1->clump);

  }

  lVar2 = mdlAnim003185b0(param_1,0);

  if (lVar2 != 0) {

    iVar5 = *(int *)(iVar3 + 0xdc);

    uStack_4 = 0;

    pVar6 = (u32 *)(iVar5 + 4);

    func_004cb6e0(*pVar6,(void *)func_003115a0,&uStack_4);

    *(u32 *)(iVar3 + 0x10c) = uStack_4;

    func_004916d0(iVar5,(void *)mdl00311610);

    func_004916d0(iVar5,(void *)func_00312f90,*pVar6);

    func_001a7170(iVar5,*(u32 *)(iVar3 + 0x10c));

    **(u32 **)(iVar3 + 0x10c) = **(u32 **)(iVar3 + 0x10c) | 0x3000;

    mdlAnimSet(param_1,0,0,0,1);

    for (uVar4 = 1; uVar4 < 4; uVar4 = uVar4 + 1 & 0xffff) {

      iVar5 = iVar3 + uVar4 * 0x9c;

      if (*(int *)(iVar5 + 0x118) != 0) {

        *(u16 *)(iVar5 + 0xec) = *(u16 *)(iVar5 + 0xec) | 2;

        hierarchy = *(u32 **)(iVar3 + 0x10c);
        uVar1 = func_00466480(hierarchy,0,*hierarchy,-1);

        *(u32 *)(iVar5 + 0x10c) = uVar1;

      }

    }

  }

  uVar1 = func_001a7570(*(u32 *)(iVar3 + 0xdc));

  *(u32 *)(iVar3 + 0xe0) = uVar1;

  func_004916d0(*(u32 *)(iVar3 + 0xdc),(void *)func_00315ed0,0);

  if (*(int *)(iVar3 + 0x3f4) != 0) {
    func_0031ded0(*(void **)(iVar3 + 0x3f4));

  }

  return;

}
#pragma pop




// FUN_00316C70 NONMATCHING


Model* func_00316c70(u16 modelType,u16 id,void* archive,u32 readMode)
{
  Model *mdl;
  MdlRmdFileMemory rmd;
  void *data;
  u32 size;
  if (!mdlFileIsTypePac(modelType)) {
    rmd.memory = *(void **)((int)archive + 0x110);
    rmd.size = *(u32 *)((int)archive + 0x118);
    mdl = mdlInit(modelType,id);
    if ((readMode & 1) != 0) {
      mdl->flags |= 0x4000;
    }
    mdlStreamInit(mdl);
    mdlStreamSetRmdFileMemory(mdl,&rmd);
    mdlStreamRead(mdl);
  }
  else {
    data = H_Cdvd_ArchiveGetFile((HCdvd*)archive,0,&size);
    mdl = mdlInit(modelType,id);
    if ((readMode & 1) != 0) {
      mdl->flags |= 0x4000;
    }
    mdlStreamInit(mdl);
    rmd.memory = data;
    rmd.size = size;
    mdlStreamSetRmdFileMemory(mdl,&rmd);
    mdlStreamRead(mdl);
    data = H_Cdvd_ArchiveGetFile((HCdvd*)archive,1,&size);
    func_0031e8d0((int)mdl + 0x3f8,modelType,id,data,size);
  }
  return mdl;
}




// FUN_003176C0


void func_003176c0(Model* mdl)
{
    RwMatrix matrix;
    RwFrame* frame;

    frame = *(RwFrame**)((u8*)mdl->clump + 4);
    RwMatrixMultiply(&matrix, &mdl->identityMat, (const RwMatrix*)mdl);
    func_004cb7f0(frame, &matrix, 0);
    func_003197c0(mdl, &matrix);
}




// FUN_00317A20 NONMATCHING
void FUN_00317a20(Model* param_1)

{
  u16 uVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  u32 uVar10;
  int *piVar11;
  code *stateFn;
  u32 uVar12;
  u32 uVar13;
  int iStack_18;
  u16 uStack_14;
  int iStack_c;
  int iStack_8;
  float red;
  float green;
  float blue;
  float alpha;
  struct {
    u8 r;
    u8 g;
    u8 b;
    char a;
  } color;
  
  iVar8 = (int)param_1;
  if ((*(u16 *)(iVar8 + 0xd8) & 0x1000) != 0) {
    bVar6 = false;
    if ((*(u16 *)(iVar8 + 0xd8) & 4) == 0) {
      FUN_00317730();
    }
    if (((*(u16 *)(iVar8 + 0xd8) & 2) == 0) && (*(u8 *)(iVar8 + 0xd3) > 0)) {
      stateFn = (code *)&DAT_00960090_abs;
      (*stateFn)(6,(*(u16 *)(iVar8 + 0xd8) & 8) != 0);
      (*stateFn)(8,(*(u16 *)(iVar8 + 0xd8) & 0x10) != 0);
      (*stateFn)(0xe,(*(u16 *)(iVar8 + 0xd8) & 0x100) != 0);
      if ((*(u16 *)(iVar8 + 0xd8) & 0x40) != 0) {
        uVar12 = 3;
      }
      else {
        uVar12 = 2;
      }
      (*stateFn)(0x14,uVar12);
      FUN_00313ca0(iVar8 + 0x35c,iVar8 + 0xec);
      iStack_18 = iVar8 + 0xd0;
      uStack_14 = 0;
      FUN_004916d0(*(u32 *)(iVar8 + 0xdc),0x315f50,&iStack_18);
      if (((*(u16 *)(iVar8 + 0xd8) & 0x20) == 0) || (*(u8 *)(iVar8 + 0xd3) == 0xff)) {
        iVar9 = *(int *)(iVar8 + 0xe0);
        if (iVar9 == 0) {
          FUN_004d7f60(2,*(u32 *)(iVar8 + 0xe4));
          FUN_004d7f60(3,*(u32 *)(iVar8 + 0xe8));
          FUN_001a88e0(*(u32 *)(iVar8 + 0xdc));
        }
        else if ((*(u16 *)(iVar8 + 0xd8) & 0x18) == 0x18) {
          FUN_001a7b50(iVar9,1);
          FUN_001a7fc0(iVar9,1);
          FUN_001a8140(iVar9,1);
        }
        else {
          FUN_001a7b50(iVar9,0);
          FUN_001a7fc0(iVar9,0);
          FUN_001a8140(iVar9,0);
        }
      }
      else {
        FUN_00315c20(param_1);
      }
      if (*(int *)(iVar8 + 0x3f4) != 0) {
        bVar5 = true;
        if ((*(u16 *)(iVar8 + 0xd8) & 0x8000) != 0) {
          iStack_8 = 1;
          FUN_004916d0(*(u32 *)(iVar8 + 0xdc),0x316360,&iStack_8);
          if (iStack_8 != 0) {
            bVar5 = false;
          }
        }
        if (bVar5) {
          if ((*(u16 *)(iVar8 + 0xd8) & 0x80) == 0) {
            red = DAT_007caf08 * (float)*(u8 *)(iVar8 + 0xd0);
            green = DAT_007caf08 * (float)*(u8 *)(iVar8 + 0xd1);
            blue = DAT_007caf08 * (float)*(u8 *)(iVar8 + 0xd2);
            alpha = DAT_007caf08 * (float)*(u8 *)(iVar8 + 0xd3);
            red = red * DAT_007caf08 * (float)*(u8 *)(iVar8 + 0x41a);
            green = green * DAT_007caf08 * (float)*(u8 *)(iVar8 + 0x41b);
            blue = blue * DAT_007caf08 * (float)*(u8 *)(iVar8 + 0x41c);
            alpha = alpha * DAT_007caf08 * (float)*(u8 *)(iVar8 + 0x41d);
            color.r = (u8)(int)(red * 255.0f + 0.5f);
            color.g = (u8)(int)(green * 255.0f + 0.5f);
            color.b = (u8)(int)(blue * 255.0f + 0.5f);
            color.a = (char)(int)(alpha * 255.0f + 0.5f);
            FUN_0031dd40(*(u32 *)(iVar8 + 0x3f4),&color.r);
            if (color.a != '\0') {
              FUN_0031dc80(*(u32 *)(iVar8 + 0x3f4),*(u16 *)(iVar8 + 0x418));
            }
          }
          else {
            FUN_0031dc80(*(u32 *)(iVar8 + 0x3f4),*(u16 *)(iVar8 + 0x418));
          }
          bVar6 = true;
        }
      }
      for (uVar10 = 0; uVar10 < 4; uVar10 = uVar10 + 1 & 0xffff) {
        iVar9 = iVar8 + uVar10 * 0x9c;
        piVar11 = (int *)(iVar9 + 0x11c);
        iVar9 = *(int *)(iVar9 + 0x11c);
        if (iVar9 != 0) {
          uVar12 = *(u32 *)(iVar8 + 0x84);
          uVar13 = *(u32 *)(iVar8 + 0x88);
          *(u32 *)(iVar9 + 8) = *(u32 *)(iVar8 + 0x80);
          *(u32 *)(iVar9 + 0xc) = uVar12;
          *(u32 *)(iVar9 + 0x10) = uVar13;
          if ((*(u16 *)(iVar8 + 0xd8) & 0x80) == 0) {
            iVar9 = *piVar11;
            *(RwRGBA *)(iVar9 + 4) = *(RwRGBA *)(iVar8 + 0xd0);
          }
          uVar4 = *(u16 *)(iVar8 + 0x418);
          iVar9 = *piVar11;
          if (*(int *)(iVar9 + 0x18) != 0) {
            FUN_0031dd40(*(int *)(iVar9 + 0x18),iVar9 + 4);
            FUN_0031dc80(*(u32 *)(iVar9 + 0x18),uVar4);
          }
          if (*(int *)(iVar9 + 0x24) != 0) {
            FUN_0031e240(*(int *)(iVar9 + 0x24),iVar9 + 4);
            FUN_0031e1e0(*(u32 *)(iVar9 + 0x24));
          }
          bVar6 = true;
        }
      }
      for (uVar10 = 0; uVar10 < 5; uVar10 = uVar10 + 1 & 0xffff) {
        iVar9 = iVar8 + uVar10 * 0xc;
        if ((((*(u8 *)(iVar9 + 0x3b4) & 1) != 0) &&
            (piVar11 = (int *)(iVar9 + 0x3b8), *(int *)(iVar9 + 0x3b8) != 0)) &&
           (lVar7 = FUN_00319770(param_1,uVar10), lVar7 != 0)) {
          iStack_c = 1;
          FUN_004916d0(*(u32 *)(*piVar11 + 0xdc),0x316360,&iStack_c);
          if (iStack_c == 0) {
            FUN_00318ad0(*piVar11,iVar8 + 0xd0);
            if ((*(u16 *)(iVar8 + 0xd8) & 0x20) == 0) {
              *(u16 *)(*piVar11 + 0xd8) = *(u16 *)(*piVar11 + 0xd8) & 0xffdf;
            }
            else {
              *(u16 *)(*piVar11 + 0xd8) = *(u16 *)(*piVar11 + 0xd8) | 0x20;
            }
            FUN_00317a20((Model*)*piVar11);
          }
        }
      }
    }
    if ((*(u16 *)(iVar8 + 0xd8) & 2) == 0) {
      if ((*(u16 *)(iVar8 + 0xd8) & 1) != 0) {
        FUN_003151d0(param_1);
      }
      if (((*(short *)(iVar8 + 0xd4) != 5) && ((*(u16 *)(iVar8 + 0xd8) & 0x8000) == 0)) &&
         (*(u8 *)(iVar8 + 0xd3) != 0)) {
        if ((*(int *)(iVar8 + 0x35c) != 0) && (*(int *)(iVar8 + 0x360) != 0)) {
          FUN_00320640(0,0x3f800000);
        }
        for (uVar10 = 0; uVar10 < 5; uVar10 = uVar10 + 1 & 0xffff) {
          iVar9 = iVar8 + uVar10 * 0xc;
          if (((((*(u8 *)(iVar9 + 0x3b4) & 1) != 0) && (*(int *)(iVar9 + 0x3b8) != 0)) &&
              (lVar7 = FUN_00319770(param_1,uVar10), lVar7 != 0)) &&
             ((*(int *)(*(int *)(iVar9 + 0x3b8) + 0x35c) != 0 &&
              (*(int *)(*(int *)(iVar9 + 0x3b8) + 0x360) != 0)))) {
            FUN_00320640(0,0x3f800000);
          }
        }
      }
    }
    if ((bVar6) && (*(short *)(iVar8 + 0x418) == 8)) {
      FUN_00321fe0();
    }
  }
  return;
}
























// FUN_00318620


u32 func_00318620(Model* param_1, u16 param_2, s16 param_3)
{
    MdlAnimEntryTable* table;
    int* piVar1;
    s16 id;
    u32 uVar2;

    uVar2 = 0;
    table = param_1->animSlots[param_2].anim.table;
    if (table != NULL && (id = param_3, (s32)id < (s32)(u32)table->count) &&
        table->entries[id].rtAnim != NULL)
    {
        uVar2 = 1;
    }

    if (param_2 == 0 && (piVar1 = *(int **)((u8*)param_1 + 0x35c), piVar1 != NULL) &&
        (s32)param_3 < (s32)(u32)*(u16 *)(piVar1 + 1) &&
        *(int *)(*piVar1 + param_3 * 8) != 0)
    {
        uVar2 = 1;
    }

    return uVar2;
}





// FUN_003186E0


u32 func_003186e0(int param_1, u32 param_2, s16 param_3)
{
    int* piVar1;
    s32 valid;
    u32 result;
    u8* base;
    int offset;

    result = 0;
    valid = 0;
    offset = (param_2 & 0xffff) * 0x9c;
    offset += param_1;
    piVar1 = *(int **)(offset + 0x118);
    if (piVar1 != NULL && (s32)*(u16 *)(piVar1 + 1) > (s32)param_3)
    {
        valid = 1;
    }
    if (valid)
    {
        base = (u8 *)*piVar1;
        offset = param_3 * 0x50;
        offset += (u32)base;
        base = (u8 *)offset;
        if (*(u8 **)(base + 0x40) == (u8 *)&DAT_009571d0)
        {
            result = 1;
        }
    }
    return result;
}




// FUN_00318B10


void func_00318b10(u32 *param_1)



{

  param_1[10] = 0x3f800000;

  param_1[5] = 0x3f800000;

  *param_1 = 0x3f800000;

  param_1[4] = 0;

  param_1[2] = 0;

  param_1[1] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[6] = 0;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  param_1[0xc] = 0;

  param_1[3] = param_1[3] | 0x20003;

  return;

}




// FUN_00318B90 NONMATCHING


u32 func_00318b90(u32 param_1)



{

  int *piVar1;

  u8 *puVar2;

  u32 uVar3;

  int lVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  

  iVar6 = (int)param_1;

  piVar1 = *(int **)(iVar6 + 0x118);

  if ((((piVar1 == (int *)0x0) ||

       ((u32)*(u16 *)(piVar1 + 1) <= (s32)*(short *)(iVar6 + 0xf0))) ||

      (puVar2 = *(u8 **)(*piVar1 + 0x40 + *(short *)(iVar6 + 0xf0) * 0x50),

      puVar2 == (u8 *)0x0)) || (puVar2 == (u8 *)&DAT_009571d0)) {

    uVar3 = 0;

  }

  else {

    func_00466ef0(*(u32 *)(iVar6 + 0x10c));

    for (uVar7 = 0; uVar7 < 5; uVar7 = uVar7 + 1 & 0xffff) {

      iVar5 = iVar6 + uVar7 * 0xc;

      if ((((*(u8 *)(iVar5 + 0x3b4) & 1) != 0) && (*(int *)(iVar5 + 0x3b8) != 0)) &&

         (lVar4 = mdl00319770((Model*)param_1,uVar7), lVar4 != 0)) {

        iVar5 = *(int *)(iVar5 + 0x3b8);

        piVar1 = *(int **)(iVar5 + 0x118);

        if (((piVar1 != (int *)0x0) &&

            ((s32)*(short *)(iVar5 + 0xf0) < (u32)*(u16 *)(piVar1 + 1))) &&

           ((puVar2 = *(u8 **)(*piVar1 + *(short *)(iVar5 + 0xf0) * 0x50 + 0x40),

            puVar2 != (u8 *)0x0 && (puVar2 != (u8 *)&DAT_009571d0)))) {

          func_00466ef0(*(u32 *)(iVar5 + 0x10c));

        }

      }

    }

    uVar3 = 1;

  }

  return uVar3;

}




// Template probe: reversing the two top-level branches to match func_00318ed0
// retained 420/448 bytes but regressed normalized diff 268 -> 287; reverted.
/* W323 measured func_00318d10 opt_loop_invariants on: nd268 -> nd266; object 420/448. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00318D10 NONMATCHING


u32 func_00318d10(u8* param_1,u32 param_2,u32* param_3)
{
  u16 *puVar1;
  u32 uVar2;
  int iVar3;
  u32 uVar4;
  u32 *puVar5;
  u32 uVar6;
  int lVar7;
  int iVar8;
  u32 uVar9;
  int iVar10;
  int iVar11;
  struct {
    int result;
    int expected;
  } callbackData;

  puVar1 = *(u16 **)(param_1 + 0x3f0);
  if (puVar1 == (u16 *)0x0) {
    lVar7 = func_001a69a0(*(u32 *)(param_1 + 0xdc),0x69abb8,param_2);
    if (lVar7 == 0) {
      uVar4 = 0;
    }
    else {
      puVar5 = (u32 *)func_004cb2f0(lVar7);
      iVar8 = 8;
      do {
        uVar4 = *puVar5;
        uVar2 = puVar5[1];
        puVar5 = puVar5 + 2;
        iVar8 = iVar8 + -1;
        *param_3 = uVar4;
        param_3[1] = uVar2;
        param_3 = param_3 + 2;
      } while (0 < iVar8);
      uVar4 = 1;
    }
  }
  else {
    uVar9 = 0;
    while ((uVar9 < *puVar1 &&
           ((param_2 & 0xffff) != *(u32 *)(*(int *)(puVar1 + 2) + uVar9 * 0x50 + 0x40)))) {
      uVar9 = uVar9 + 1 & 0xffff;
    }
    if (uVar9 == *puVar1) {
      uVar4 = 0;
    }
    else {
      iVar11 = *(int *)(puVar1 + 2) + uVar9 * 0x50;
      iVar8 = *(int *)(iVar11 + 0x44);
      iVar10 = *(int *)(*(int *)(param_1 + 0xdc) + 4);
      iVar3 = func_00466720(iVar10);
      if (iVar8 != iVar3) {
        callbackData.result = 0;
        callbackData.expected = iVar8;
        func_004cb6e0(iVar10,0x315010,&callbackData);
        iVar10 = callbackData.result;
      }
      if (iVar10 == 0) {
        uVar4 = 0;
      }
      else {
        uVar6 = func_004cb2f0(iVar10);
        FUN_004c2f30((RwMatrix*)param_3,(const RwMatrix*)iVar11,(const RwMatrix*)uVar6);
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}
#pragma pop




// FUN_00318ED0


bool func_00318ed0(u8* param_1,u32 param_2,RwV3d *param_3)



{

  u32 uVar1;

  u32 uVar2;

  u32 *puVar3;

  u32 lVar4;

  u32 *puVar6;

  int iVar5;

  RwMatrix matrix;

  

  if (*(int *)(param_1 + 0x3f0) != 0) {

    lVar4 = func_00315090(&matrix,(u16 *)*(int *)(param_1 + 0x3f0),param_2 & 0xffff,
                         *(int *)(param_1 + 0xdc));

  }
  else {

    lVar4 = func_001a69a0(*(u32 *)(param_1 + 0xdc),DAT_0069abb8,param_2);

    if (lVar4 == 0) {

      lVar4 = 0;

    }
    else {

      puVar3 = (u32 *)func_004cb2f0(lVar4);

      puVar6 = (u32 *)&matrix;

      iVar5 = 8;

      do {

        uVar1 = *puVar3;

        uVar2 = puVar3[1];

        puVar3 = puVar3 + 2;

        iVar5 = iVar5 + -1;

        *puVar6 = uVar1;

        puVar6[1] = uVar2;

        puVar6 = puVar6 + 2;

      } while (0 < iVar5);

      lVar4 = 1;

    }

  }

  if (lVar4 == 0) {
    return false;
  }

    *param_3 = matrix.pos;

  return true;

}




// FUN_00318FC0


u32 func_00318fc0(int param_1)



{

  u16* ptr;

  ptr = *(u16 **)(param_1 + 0x3f0);
  if (ptr != NULL) {
    return (u32)*ptr;
  }
  return func_001a6c00(*(void **)(param_1 + 0xdc), (const char *)DAT_0069abb8);
}




// FUN_00319230


void func_00319230(int param_1, u16 param_2)
{
    int iVar1;
    s32 uVar2;

    *(u16 *)(param_1 + 0x418) = param_2;
    for (uVar2 = 0; (uVar2 & 0xffff) < 5; uVar2 = uVar2 + 1 & 0xffff)
    {
        iVar1 = param_1 + (u16)uVar2 * 0xc;
        if ((*(u8 *)(iVar1 + 0x3b4) & 1) != 0 &&
            (iVar1 = *(int *)(iVar1 + 0x3b8), iVar1 != 0))
        {
            *(u16 *)(iVar1 + 0x418) = param_2;
        }
    }
}




// FUN_003192A0


void func_003192a0(int parent, u32 slotIdx, u16 type, u16 id, const char* path,
                   u32 readMode)
{
    Model* mdl;
    Model* slotBase;
    u8* offset;

    mdl = mdlInit(type, id);

    if (readMode & MDL_READSYNC)
    {
        mdl->flags |= MDL_FLAG_STREAMSYNC;
    }

    mdlStreamInit(mdl);
    mdlStreamRequestCdvd(mdl, path);
    mdlStreamRead(mdl);

    offset = (u8*)((u16)slotIdx * sizeof(MdlAttachedWpn));
    slotBase = (Model*)(offset + parent);
    slotBase->attachedWpns[0].wpnMdl = mdl;
    mdl->flags |= 4;
    slotBase->attachedWpns[0].wpnMdl->flags |= 0x8000;
    slotBase->attachedWpns[0].flags |= 1;
}




// FUN_00319390


void func_00319390(int param_1,u32 param_2,u16 param_3,u16 param_4,u32 param_5,
                 u32 param_6,u32 param_7)



{

  Model* uVar1;

  int iVar2;

  MdlRmdFileMemory rmd;

  u8* offset;

  uVar1 = mdlInit(param_3,param_4);

  iVar2 = (int)uVar1;

  if ((param_7 & 1) != 0) {

    *(u16 *)(iVar2 + 0xd8) = *(u16 *)(iVar2 + 0xd8) | 0x4000;

  }

  mdlStreamInit(uVar1);

  rmd.memory = (void*)param_5;
  rmd.size = param_6;
  mdlStreamSetRmdFileMemory(uVar1, &rmd);

  mdlStreamRead(uVar1);

  offset = (u8*)((param_2 & 0xffff) * 0xc);
  param_1 = (int)(offset + param_1);

  *(int *)(param_1 + 0x3b8) = iVar2;

  *(u16 *)(iVar2 + 0xd8) = *(u16 *)(iVar2 + 0xd8) | 4;

  *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) =

       *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) | 0x8000;

  *(u8 *)(param_1 + 0x3b4) = *(u8 *)(param_1 + 0x3b4) | 1;

  return;

}




// FUN_00319490 NONMATCHING


void func_00319490(int param_1,u32 param_2,u16 param_3,u16 param_4,u32 param_5)



{

  long lVar1;

  Model* uVar2;

  int iVar3;

  char auStack_100[256];

  

  lVar1 = (long)(void*)mdlSearch(param_3,param_4,0);

  if (lVar1 != 0) {

    uVar2 = mdlInit(param_3,param_4);

    iVar3 = (int)uVar2;

    if ((param_5 & 1) != 0) {

      *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 0x4000;

    }

    *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 0x2000;

    mdlStreamRead(uVar2);

  }

  else {

    mdlFileResolvePackPath(param_3,param_4,auStack_100);

    uVar2 = mdlCreateFromPath(param_3,param_4,auStack_100,param_5);

    lVar1 = mdlFileIsTypePac(param_3);

    if (lVar1 != 0) {

      mdl00319900(uVar2,1);

    }

  }

  param_1 = (param_2 & 0xffff) * 0xc + param_1;

  iVar3 = (int)uVar2;

  *(int *)(param_1 + 0x3b8) = iVar3;

  *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 4;

  *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) =

       *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) | 0x8000;

  *(u8 *)(param_1 + 0x3b4) = *(u8 *)(param_1 + 0x3b4) | 1;

  return;

}




// FUN_003195F0


void func_003195f0(int param_1,u32 param_2,Model* param_3)



{

  Model* uVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = (int)param_3;

  uVar1 = mdlInit(*(u16 *)(iVar2 + 0xd4),*(u16 *)(iVar2 + 0xd6));

  iVar3 = (int)uVar1;

  if ((*(u16 *)(iVar2 + 0xd8) & 0x1000) != 0) {
    mdlCopy(param_3,uVar1);
    *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 0x1000;
  }
  else {
    *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 0x2000;
  }

  iVar2 = (param_2 & 0xffff) * 0xc;
  iVar2 += param_1;
  param_1 = iVar2;
  *(int *)(param_1 + 0x3b8) = iVar3;

  *(u16 *)(iVar3 + 0xd8) = *(u16 *)(iVar3 + 0xd8) | 4;

  *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) =

       *(u16 *)(*(int *)(param_1 + 0x3b8) + 0xd8) | 0x8000;

  *(u8 *)(param_1 + 0x3b4) = *(u8 *)(param_1 + 0x3b4) | 1;

  return;

}




// FUN_003196F0


void func_003196f0(Model* param_1, u16 param_2)
{
    int iVar1;
    int iVar2;
    int* pWpnMdl;

    iVar1 = (int)(u8*)param_1;
    iVar2 = (param_2 & 0xffff) * 0xc;
    iVar1 = iVar2;
    iVar1 += (int)(u8*)param_1;
    pWpnMdl = (int*)(iVar1 + 0x3b8);
    if (*pWpnMdl != 0)
    {
        mdlDestroy((Model*)*pWpnMdl);
        *pWpnMdl = 0;
        iVar2 = iVar2 + (int)(u8*)param_1;
        *(u8*)(iVar2 + 0x3b4) = *(u8*)(iVar2 + 0x3b4) & 0xfe;
    }
}




/* Required for Mdl matrix aggregate copy under MWCCPS2 b210 (without: nd32). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_003197C0


void func_003197c0(Model* param_1, RwMatrix* param_2)
{
    u16 uVar6;
    int iVar3;

    uVar6 = 0;
    for (; uVar6 < 5; uVar6++)
    {
        iVar3 = (int)param_1->attachedWpns[uVar6].wpnMdl;
        if (iVar3 != 0)
        {
            *(RwMatrix *)((u8 *)(u32)iVar3 + 0x90) = *param_2;
        }
    }
}
#pragma pop
    



/* W323 measured func_00319970 opt_loop_invariants on: nd3132 -> nd3045; object 4304/4448. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00319970 NONMATCHING


u32 func_00319970(Model* param_1)



{

  u16 uVar1;

  int *piVar2;

  u16 uVar3;

  int iVar4;

  u32 uVar5;

  int *piVar6;

  int iVar7;

  u16 uVar8;

  void* uVar9;

  u32 lVar10;

  int iVar11;

  int iVar12;

  u16 *puVar13;

  u32 *puVar14;

  int iStack_50;

  u32 uStack_4c;

  u16 uStack_30;

  u16 uStack_2e;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  int iStack_10;

  int iStack_c;

  u16 uStack_6;

  u16 uStack_4;

  
  u16 uStack_2;

  

  iVar12 = (int)param_1;

  piVar2 = *(int **)(iVar12 + 0x428);

  uStack_2 = 0x20;

  for (uVar8 = 0; uVar8 < 4; uVar8 = uVar8 + 1 & 0xffff) {

    *(u16 *)((int)piVar2 + uVar8 * 2 + 0x20) = 0x20;

  }

  while ((lVar10 = func_004c1970(*piVar2,&iStack_50), uVar1 = uStack_2, lVar10 != 0 &&

         (iStack_50 != 0))) {

    if (iStack_50 == -0xf0fff1f) {

      iVar4 = piVar2[0xe];

      iVar11 = *(int *)(*piVar2 + 0xc);

      if (*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) *

                            4 + 0x11c) == 0) {

        iVar7 = (u32)uStack_2 * 8 + 0x34;

        uVar9 = (*DAT_00960178)(iVar7,0x40000);

        memset(uVar9,0,iVar7);

        puVar14 = (u32 *)uVar9;

        *puVar14 = (u32)uVar1;

        puVar14[5] = (u32)(puVar14 + 0xd);

        puVar14[8] = (u32)(puVar14 + 0xd + uVar1);

        *(u32 **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) *

                            4 + 0x11c) = puVar14;

      }

      uVar5 = func_0031dff0(iVar4 + iVar11,uStack_4c);

      *(u32 *)

       (*(int *)(*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                   (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x11c) + 0x20) +

       (u32)*(u16 *)((int)piVar2 + 0x1e) * 4) = uVar5;

      func_004c5620(*piVar2,uStack_4c);
    }

    else if (iStack_50 == -0xf0fff20) {

      func_004c5250(*piVar2,&uStack_30,0x14);

      func_004c5620(*piVar2,uStack_28);

      uVar1 = uStack_2;

      iVar4 = piVar2[0xe];

      iVar11 = *(int *)(*piVar2 + 0xc);

      if ((*(int *)(iVar12 + 0xdc) == 0) && (piVar2[5] == 0)) {

        if (*(int *)(iVar12 + 0x3f4) == 0) {

          uVar5 = func_0031d6b0();

          *(u32 *)(iVar12 + 0x3f4) = uVar5;

        }

        uVar5 = *(u32 *)(iVar12 + 0x3f4);

      }

      else {

        if (*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7))

                              * 4 + 0x11c) == 0) {

          iVar7 = (u32)uStack_2 * 8 + 0x34;

          uVar9 = (*DAT_00960178)(iVar7,0x40000);

          memset(uVar9,0,iVar7);

          puVar14 = (u32 *)uVar9;

          *puVar14 = (u32)uVar1;

          puVar14[5] = (u32)(puVar14 + 0xd);

          puVar14[8] = (u32)(puVar14 + 0xd + uVar1);

          *(u32 **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7))

                              * 4 + 0x11c) = puVar14;

        }

        if (*(int *)(*(int *)(*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                                (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x11c) + 0x14)

                    + (u32)*(u16 *)((int)piVar2 + 0x1e) * 4) == 0) {

          uVar5 = func_0031d6b0();

          *(u32 *)

           (*(int *)(*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                       (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x11c) + 0x14) +

           (u32)*(u16 *)((int)piVar2 + 0x1e) * 4) = uVar5;

        }

        uVar5 = *(u32 *)

                 (*(int *)(*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                             (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x11c) + 0x14) +

                 (u32)*(u16 *)((int)piVar2 + 0x1e) * 4);

      }

      uVar9 = (void *)func_0031d7e0(uVar5,iVar4 + iVar11,uStack_2c,uStack_30,uStack_24);

      uVar8 = (u32)uStack_30;

      while (uVar8 = uVar8 + 1 & 0xffff, uVar8 < uStack_2e + 1) {

        func_0031d900(uVar5,uVar9,uVar8);

      }

      func_004c5620(*piVar2,uStack_2c);
    }

    else if (iStack_50 == -0xf0fff10) {

      func_004c5250(*piVar2,&uStack_2,uStack_4c);

      *(u16 *)((int)piVar2 + (u32)*(u16 *)(piVar2 + 7) * 2 + 0x20) = uStack_2;
    }

    else if (iStack_50 == -0xf0ffffa) {

      iVar4 = *piVar2;

      func_004c5250(iVar4,&uStack_6,2);

      iVar11 = (int)(*DAT_00960178)((u32)uStack_6 * 0x50 + 8,0x40000);

      puVar13 = (u16 *)(iVar11 + (u32)uStack_6 * 0x50);

      *puVar13 = uStack_6;

      puVar13[1] = 1;

      *(int *)(puVar13 + 2) = iVar11;

      for (uVar8 = 0; uVar8 < uStack_6; uVar8 = uVar8 + 1 & 0xffff) {

        iVar11 = uVar8 * 0x50;

        func_004c5250(iVar4,*(int *)(puVar13 + 2) + iVar11 + 0x40,4);

        func_004c5250(iVar4,*(int *)(puVar13 + 2) + iVar11 + 0x44,4);

        func_004c5250(iVar4,*(int *)(puVar13 + 2) + iVar11,0x40);

      }

      *(u16 **)(iVar12 + 0x3f0) = puVar13;
    }

    else if (iStack_50 == -0xf0fff90) {

      uVar9 = (*DAT_00960178)(0x2b8,0x40000);

      func_004c5250(*piVar2,uVar9,uStack_4c);

      func_003164f0((int)param_1,(int)uVar9);

      (*DAT_0096017c)(uVar9);
    }

    else if ((((iStack_50 == -0xf0fff7e) || (iStack_50 == -0xf0fff7d)) || (iStack_50 == -0xf0fff7f))
            || (iStack_50 == -0xf0fff80)) {

      if ((*(u16 *)(iVar12 + 0xd8) & 0x4000) == 0) {

        piVar6 = (int *)(*DAT_00960178)(0x10,0x40000);

        iStack_10 = piVar2[0xe] + *(int *)(*piVar2 + 0xc);

        iStack_c = piVar2[0xf] - *(int *)(*piVar2 + 0xc);

        *piVar6 = iStack_50;

        *(u16 *)(piVar6 + 1) = *(u16 *)((int)piVar2 + 0x1e);

        iVar4 = func_004c58a0(3,1,&iStack_10);

        piVar6[2] = iVar4;

        func_004c5620(*piVar2,uStack_4c);

        piVar6[3] = piVar2[6];

        piVar2[6] = (int)piVar6;

      }

      else {

        if (*(int *)(iVar12 + 0x35c) == 0) {

          iVar4 = (u32)uStack_2 * 8 + 8;

          uVar9 = (*DAT_00960178)(iVar4,0x40000);

          memset(uVar9,0,iVar4);

          piVar6 = (int *)uVar9;

          *piVar6 = (int)(piVar6 + 2);

          *(u16 *)(piVar6 + 1) = uVar1;

          *(u16 *)((int)piVar6 + 6) = 1;

          *(int **)(iVar12 + 0x35c) = piVar6;

        }

        if (*(int *)(**(int **)(iVar12 + 0x35c) + (u32)*(u16 *)((int)piVar2 + 0x1e) * 8) == 0) {

          uVar5 = func_00320230();

          *(u32 *)(**(int **)(iVar12 + 0x35c) + (u32)*(u16 *)((int)piVar2 + 0x1e) * 8) =

               uVar5;

        }

        func_00320880(*piVar2,*(u32 *)

                              (**(int **)(iVar12 + 0x35c) +

                              (u32)*(u16 *)((int)piVar2 + 0x1e) * 8),iStack_50,

                     *(u32 *)(iVar12 + 0xdc));

      }
    }

    else if (iStack_50 == -0xf0ffffd) {

      if ((*(u16 *)(iVar12 + 0xd8) & 0x4000) == 0) {

        func_004c5250(*piVar2,&uStack_4,uStack_4c);

        if (piVar2[*(u16 *)(piVar2 + 7) + 10] == 0) {

          iVar4 = (int)(*DAT_00960178)((u32)uStack_2 << 1,0x40000);

          piVar2[*(u16 *)(piVar2 + 7) + 10] = iVar4;

          for (uVar8 = 0; uVar8 < uStack_2; uVar8 = uVar8 + 1 & 0xffff) {

            *(u16 *)(piVar2[*(u16 *)(piVar2 + 7) + 10] + uVar8 * 2) = 0xffff;

          }

        }

        *(u16 *)

         (piVar2[*(u16 *)(piVar2 + 7) + 10] + (u32)*(u16 *)((int)piVar2 + 0x1e) * 2) =

             uStack_4;

      }

      else {

        func_004c5250(*piVar2,&uStack_4,uStack_4c);

        uVar3 = uStack_4;

        uVar1 = *(u16 *)((int)piVar2 + 0x1e);

        piVar6 = *(int **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                    (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x118);

        iVar4 = *piVar6;

        iVar11 = *(int *)(iVar4 + (u32)uStack_4 * 0x50 + 0x40);

        if (iVar11 != 0) {

          *(int *)(iVar4 + (u32)uVar1 * 0x50 + 0x40) = iVar11;

        }

        iVar4 = *piVar6 + (u32)uVar1 * 0x50;

        *(u32 *)(iVar4 + 0x44) = *(u32 *)(iVar4 + 0x44) | 1;

        piVar6 = *(int **)(iVar12 + 0x35c);

        if ((piVar6 != (int *)0x0) && (uStack_4 < *(u16 *)(piVar6 + 1))) {

          iVar4 = *(int *)(*piVar6 + (u32)uStack_4 * 8);

          if (iVar4 != 0) {

            iVar11 = (u32)*(u16 *)((int)piVar2 + 0x1e) * 8;

            *(int *)(*piVar6 + iVar11) = iVar4;

            iVar11 = *piVar6 + iVar11;

            *(u8 *)(iVar11 + 4) = *(u8 *)(iVar11 + 4) | 1;

          }

        }

        piVar6 = *(int **)(iVar12 + 0x37c);

        if ((piVar6 != (int *)0x0) && (uStack_4 < *(u16 *)(piVar6 + 3))) {

          iVar4 = *(int *)(*piVar6 + (u32)uStack_4 * 8);

          if (iVar4 != 0) {

            iVar11 = (u32)*(u16 *)((int)piVar2 + 0x1e) * 8;

            *(int *)(*piVar6 + iVar11) = iVar4;

            iVar11 = *piVar6 + iVar11;

            *(u8 *)(iVar11 + 4) = *(u8 *)(iVar11 + 4) | 1;

          }

        }

        iVar4 = *(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                  (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x11c);

        if (iVar4 != 0) {

          uVar1 = *(u16 *)((int)piVar2 + 0x1e);

          if (*(int *)(*(int *)(iVar4 + 0x14) + (u32)uStack_4 * 4) != 0) {

            uVar5 = (u32)(void*)func_0031d700((void*)*(int *)(*(int *)(iVar4 + 0x14) + (u32)uStack_4 * 4));

            *(u32 *)(*(int *)(iVar4 + 0x14) + (u32)uVar1 * 4) = uVar5;

          }

          if (*(int *)(*(int *)(iVar4 + 0x20) + (u32)uVar3 * 4) != 0) {

            uVar5 = (u32)(void*)func_0031e0b0((void*)*(int *)(*(int *)(iVar4 + 0x20) + (u32)uVar3 * 4));

            *(u32 *)(*(int *)(iVar4 + 0x20) + (u32)uVar1 * 4) = uVar5;

          }

        }

      }
    }

    else if (iStack_50 == -0xf0ffffe) {

      *(short *)(piVar2 + 7) = (short)piVar2[7] + 1;

      *(u16 *)((int)piVar2 + 0x1e) = 0;

      func_004c5620(*piVar2,uStack_4c);
    }

    else if (iStack_50 == -0xf0ffffc) {

      *(short *)((int)piVar2 + 0x1e) = *(short *)((int)piVar2 + 0x1e) + 1;

      func_004c5620(*piVar2,uStack_4c);
    }

    else if (iStack_50 == -0xf0ffffb) {

      if (*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) *

                            4 + 0x118) == 0) {


        uVar5 = (u32)(void*)mdlCreateAnimEntryTable(uStack_2);
        *(u32 *)

         (iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) * 4 +

         0x118) = uVar5;

      }

      func_004c5250(*piVar2,**(int **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 -

                                               (u32)*(u16 *)(piVar2 + 7)) * 4 + 0x118) +

                           (u32)*(u16 *)((int)piVar2 + 0x1e) * 0x50,uStack_4c);
    }

    else if (iStack_50 == -0xf0fffff) {

      if (*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) *

                            4 + 0x118) == 0) {

        uVar5 = (u32)(void*)mdlCreateAnimEntryTable(uStack_2);

        *(u32 *)

         (iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) * 4 +

         0x118) = uVar5;

      }

      *(u8 **)

       (**(int **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) *

                            4 + 0x118) + (u32)*(u16 *)((int)piVar2 + 0x1e) * 0x50 + 0x40) =

           (u8 *)&DAT_009571d0;

      func_004c5620(*piVar2,uStack_4c);

    }

    else if (iStack_50 != 0x1e) {

      if (iStack_50 == 0x10) {

        if ((*(u16 *)(iVar12 + 0xd8) & 0x4000) == 0) {

          if (((*(int *)(iVar12 + 0xdc) == 0) && (piVar2[5] == 0)) && (piVar2[4] == 0)) {

            iStack_10 = piVar2[0xe] + *(int *)(*piVar2 + 0xc);

            iStack_c = piVar2[0xf] - *(int *)(*piVar2 + 0xc);

            iVar4 = func_004c58a0(3,1,&iStack_10);

            piVar2[5] = iVar4;

          }

          func_004c5620(*piVar2,uStack_4c);

        }

        else if (*(int *)(iVar12 + 0xdc) == 0) {

          uVar5 = func_004920a0(*piVar2);

          *(u32 *)(iVar12 + 0xdc) = uVar5;

        }

      }

      else if (iStack_50 == 0x2b) {

        if ((*(u16 *)(iVar12 + 0xd8) & 0x4000) != 0) {

          if (*(int *)(iVar12 + 0x37c) == 0) {

            iVar4 = (u32)uStack_2 * 8 + 0x10;

            uVar9 = (*DAT_00960178)(iVar4,0x40000);

            memset(uVar9,0,iVar4);

            piVar6 = (int *)uVar9;

            *piVar6 = (int)(piVar6 + 4);

            *(u16 *)(piVar6 + 3) = uVar1;

            *(u16 *)((int)piVar6 + 0xe) = 1;

            *(int **)(iVar12 + 0x37c) = piVar6;

          }

          uVar9 = (void *)func_004b79d0(0x77e4e0,*piVar2);

          if (*(int *)(iVar12 + 0xdc) == 0) {

            *(int *)(*(int *)(iVar12 + 0x37c) + 4) = (int)uVar9;

            func_004b7760(0x77e4e0,uVar9);

          }

          else {

            *(int *)(**(int **)(iVar12 + 0x37c) + (u32)*(u16 *)((int)piVar2 + 0x1e) * 8) =

                 (int)uVar9;

          }

        }

        else {

          if ((piVar2[5] == 0) && (piVar2[4] == 0)) {

            iStack_10 = piVar2[0xe] + *(int *)(*piVar2 + 0xc);

            iStack_c = piVar2[0xf] - *(int *)(*piVar2 + 0xc);

            uVar9 = (void *)func_004c58a0(3,1,&iStack_10);

            iVar4 = func_0010c1a0(7,0,0,0,uVar9,0,0,0);

            piVar2[2] = iVar4;

          }

          else {

            if (piVar2[3] == 0) {

              uVar9 = (*DAT_00960178)((u32)uStack_2 << 2,0x40000);

              piVar2[3] = (int)uVar9;

              memset(uVar9,0,(u32)uStack_2 << 2);

            }

            iStack_10 = piVar2[0xe] + *(int *)(*piVar2 + 0xc);

            iStack_c = piVar2[0xf] - *(int *)(*piVar2 + 0xc);

            uVar9 = (void *)func_004c58a0(3,1,&iStack_10);

            uVar5 = func_0010c1a0(7,0,0,0,uVar9,0,0,0);

            *(u32 *)(piVar2[3] + (u32)*(u16 *)((int)piVar2 + 0x1e) * 4) = uVar5;

          }

          func_004c5620(*piVar2,uStack_4c);

        }

      }

      else if (iStack_50 == 0x1b) {

        if (*(int *)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7))

                              * 4 + 0x118) == 0) {

          uVar5 = (u32)(void*)mdlCreateAnimEntryTable(uStack_2);

          *(u32 *)

           (iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7)) * 4 +

           0x118) = uVar5;

        }

        uVar5 = func_004b6a40(*piVar2);

        *(u32 *)

         (**(int **)(iVar12 + ((u32)*(u16 *)(piVar2 + 7) * 0x28 - (u32)*(u16 *)(piVar2 + 7))

                              * 4 + 0x118) + (u32)*(u16 *)((int)piVar2 + 0x1e) * 0x50 + 0x40) =

             uVar5;

      }

      else if (iStack_50 == 0x23) {

        uVar9 = (void *)func_004bda10(*piVar2);

        func_004d0dc0(uVar9,0x1a13b0,piVar2 + 0x10);

        func_004d0d10(uVar9);

      }

      else if (iStack_50 == 0x16) {

        if ((*(u16 *)(iVar12 + 0xd8) & 0x4000) != 0) {

          uVar9 = (void *)func_004c8680(*piVar2);

          func_004d0dc0(uVar9,0x1a13b0,piVar2 + 0x10);

          func_004d0d10(uVar9);

        }

        else {

          iStack_10 = piVar2[0xe] + *(int *)(*piVar2 + 0xc);

          iStack_c = piVar2[0xf] - *(int *)(*piVar2 + 0xc);

          uVar9 = (void *)func_004c58a0(3,1,&iStack_10);

          iVar4 = func_0010c1a0(8,0,0,0,uVar9,0,0,0);

          piVar2[1] = iVar4;

          func_004c5620(*piVar2,uStack_4c);

        }

      }

      else {

        func_004c5620(*piVar2,uStack_4c);

      }

    }

  }

  return 1;

}
#pragma pop




// FUN_0031AAD0 NONMATCHING


int func_0031aad0(Model* param_1)



{

  u16 uVar1;

  int iVar2;

  u32 *puVar3;

  bool bVar4;

  bool bVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  void* uVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  int *piVar14;

  u32 uVar15;

  int iVar16;

  u32 *puVar17;

  u32 uVar18;

  int iVar19;

  int iStack_8;

  u32 uStack_4;

  

  iVar2 = (int)param_1->stream;

  iVar16 = 1;

  bVar4 = true;

  bVar5 = true;

  if (*(int *)(iVar2 + 4) != 0) {

    uVar8 = func_0010c3a0(*(int *)(iVar2 + 4),&iStack_8,&uStack_4);

    if (iStack_8 == 1) {

      func_004d0dc0(uVar8,0x1a13b0,iVar2 + 0x40);

      func_004d0d10(uVar8);

      func_004c5780(uStack_4,0);

      *(u32 *)(iVar2 + 4) = 0;

    }

    else {

      bVar4 = false;

      iVar16 = 0;

    }

  }

  if (*(int *)(iVar2 + 8) != 0) {

    uVar8 = func_0010c3a0(*(int *)(iVar2 + 8),&iStack_8,&uStack_4);

    if (iStack_8 == 1) {

      if (*(int **)(param_1->unkData2 + 0x1c) == 0) {

        uVar1 = *(u16 *)(iVar2 + 0x20);

        iVar12 = (u32)uVar1 * 8 + 0x10;

        uVar9 = (*DAT_00960178)(iVar12,0x40000);

        memset(uVar9,0,iVar12);

        piVar14 = (int *)uVar9;

        *piVar14 = (int)(piVar14 + 4);

        *(u16 *)(piVar14 + 3) = uVar1;

        *(u16 *)((int)piVar14 + 0xe) = 1;

        *(int **)(param_1->unkData2 + 0x1c) = piVar14;

      }

      (*(int **)(param_1->unkData2 + 0x1c))[1] = (int)uVar8;

      func_004b7760(0x77e4e0,uVar8);

      func_004c5780(uStack_4,0);

      *(u32 *)(iVar2 + 8) = 0;

    }

    else {

      iVar16 = 0;

      bVar5 = false;

    }

  }

  if (*(int *)(iVar2 + 0xc) != 0) {

    for (uVar18 = 0; uVar18 < *(u16 *)(iVar2 + 0x20); uVar18 = uVar18 + 1) {

      iVar12 = *(int *)(*(int *)(iVar2 + 0xc) + uVar18 * 4);

      if (iVar12 != 0) {

        uVar6 = func_0010c3a0(iVar12,&iStack_8,&uStack_4);

        if (iStack_8 == 1) {

          if (*(int **)(param_1->unkData2 + 0x1c) == 0) {

            uVar1 = *(u16 *)(iVar2 + 0x20);

            iVar12 = (u32)uVar1 * 8 + 0x10;

            uVar8 = (u64)(u32)(*DAT_00960178)(iVar12,0x40000);

            memset((void *)(u32)uVar8,0,iVar12);

            piVar14 = (int *)uVar8;

            *piVar14 = (int)(piVar14 + 4);

            *(u16 *)(piVar14 + 3) = uVar1;

            *(u16 *)((int)piVar14 + 0xe) = 1;

            *(int **)(param_1->unkData2 + 0x1c) = piVar14;

          }

          *(u32 *)(**(int **)(param_1->unkData2 + 0x1c) + (uVar18 & 0xffff) * 8) = uVar6;

          func_004c5780(uStack_4,0);

          *(u32 *)(*(int *)(iVar2 + 0xc) + uVar18 * 4) = 0;

        }

        else {

          iVar16 = 0;

        }

      }

    }

  }

  iVar12 = *(int *)(iVar2 + 0x14);

  if ((iVar12 != 0) || (*(int *)(iVar2 + 0x10) != 0)) {

    if ((bVar4) && (bVar5)) {

      if (iVar12 == 0) {

        uVar6 = func_0010c3a0(*(u32 *)(iVar2 + 0x10),&iStack_8,&uStack_4);

        if (iStack_8 == 1) {

          param_1->clump = (RpClump *)uVar6;

          func_004c5780(uStack_4,0);

          *(u32 *)(iVar2 + 0x10) = 0;

        }

        else {

          iVar16 = 0;

        }

      }

      else {

        uVar6 = func_0010c1a0(2,0,0,0,iVar12,0,0,0);

        *(u32 *)(iVar2 + 0x10) = uVar6;

        *(u32 *)(iVar2 + 0x14) = 0;

        iVar16 = 0;

      }

    }

    else {

      iVar16 = 0;

    }

  }

  puVar17 = *(u32 **)(iVar2 + 0x18);

  if (puVar17 != (u32 *)0x0) {

    if (param_1->clump != NULL) {

      while (puVar17 != (u32 *)0x0) {

        if (param_1->unk_35c == NULL) {

          uVar1 = *(u16 *)(iVar2 + 0x20);

          iVar12 = (u32)uVar1 * 8 + 8;

          uVar8 = (u64)(u32)(*DAT_00960178)(iVar12,0x40000);

          memset((void *)(u32)uVar8,0,iVar12);

          piVar14 = (int *)uVar8;

          *piVar14 = (int)(piVar14 + 2);

          *(u16 *)(piVar14 + 1) = uVar1;

          *(u16 *)((int)piVar14 + 6) = 1;

          param_1->unk_35c = piVar14;

        }

        if (*(int *)(*(int *)param_1->unk_35c + (u32)*(u16 *)(puVar17 + 1) * 8) == 0) {

          uVar6 = func_00320230();

          *(u32 *)(*(int *)param_1->unk_35c + (u32)*(u16 *)(puVar17 + 1) * 8) = uVar6;

        }

        func_00320880(puVar17[2],

                     *(u32 *)

                      (*(int *)param_1->unk_35c + (u32)*(u16 *)(puVar17 + 1) * 8),*puVar17,

                     (u32)param_1->clump);

        func_004c5780(puVar17[2],0);

        puVar3 = (u32 *)puVar17[3];

        (*DAT_0096017c)(puVar17);

        puVar17 = puVar3;

      }

      *(u32 *)(iVar2 + 0x18) = 0;

    }

    else {

      iVar16 = 0;

    }

  }

  if (iVar16 == 1) {

    for (uVar18 = 0; uVar18 < 4; uVar18 = uVar18 + 1) {

      iVar12 = iVar2 + uVar18 * 4;

      if (*(int *)(iVar12 + 0x28) != 0) {

        iVar19 = (int)param_1 + uVar18 * 0x9c;

        for (uVar15 = 0; uVar15 < *(u16 *)(iVar2 + uVar18 * 2 + 0x20); uVar15 = uVar15 + 1) {

          uVar1 = *(u16 *)(*(int *)(iVar12 + 0x28) + uVar15 * 2);

          if (uVar1 != 0xffff) {

            piVar14 = *(int **)(iVar19 + 0x118);

            iVar10 = *piVar14;

            iVar11 = *(int *)(iVar10 + (u32)uVar1 * 0x50 + 0x40);

            if (iVar11 != 0) {

              *(int *)(iVar10 + (uVar15 & 0xffff) * 0x50 + 0x40) = iVar11;

            }

            uVar13 = uVar15 & 0xffff;

            iVar10 = *piVar14 + uVar13 * 0x50;

            *(u32 *)(iVar10 + 0x44) = *(u32 *)(iVar10 + 0x44) | 1;

            if (uVar18 == 0) {

              piVar14 = (int *)param_1->unk_35c;

              uVar7 = (u32)uVar1;

              if (((piVar14 != (int *)0x0) &&

                  ((long)(short)uVar1 < (long)(u32)*(u16 *)(piVar14 + 1))) &&

                 (iVar10 = *piVar14, *(int *)(iVar10 + (short)uVar1 * 8) != 0)) {

                *(u32 *)(iVar10 + uVar13 * 8) = *(u32 *)(iVar10 + uVar7 * 8);

                iVar10 = *piVar14 + uVar13 * 8;

                *(u8 *)(iVar10 + 4) = *(u8 *)(iVar10 + 4) | 1;

              }

              piVar14 = *(int **)(param_1->unkData2 + 0x1c);

              if (((piVar14 != (int *)0x0) &&

                  ((long)(short)uVar1 < (long)(u32)*(u16 *)(piVar14 + 3))) &&

                 (iVar10 = *piVar14, *(int *)(iVar10 + (short)uVar1 * 8) != 0)) {

                iVar11 = (uVar15 & 0xffff) * 8;

                *(u32 *)(iVar10 + iVar11) = *(u32 *)(iVar10 + uVar7 * 8);

                iVar11 = *piVar14 + iVar11;

                *(u8 *)(iVar11 + 4) = *(u8 *)(iVar11 + 4) | 1;

              }

              iVar10 = *(int *)(iVar19 + 0x11c);

              if (iVar10 != 0) {

                if (*(int *)(*(int *)(iVar10 + 0x14) + uVar7 * 4) != 0) {

                  uVar6 = (u32)(void*)func_0031d700((void*)*(int *)(*(int *)(iVar10 + 0x14) + uVar7 * 4));

                  *(u32 *)(*(int *)(iVar10 + 0x14) + uVar13 * 4) = uVar6;

                }

                if (*(int *)(*(int *)(iVar10 + 0x20) + uVar7 * 4) != 0) {

                  uVar6 = (u32)(void*)func_0031e0b0((void*)*(int *)(*(int *)(iVar10 + 0x20) + uVar7 * 4));

                  *(u32 *)(*(int *)(iVar10 + 0x20) + uVar13 * 4) = uVar6;

                }

              }

            }

          }

        }

        (*DAT_0096017c)(*(u32 *)(iVar12 + 0x28));

      }

    }

  }

  return iVar16;

}




// FUN_0031B220


u32 func_0031b220(Model* param_1)
{

  int *piVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u32 lVar5;

  int iVar6;

  int iStack_4;

  

  iVar6 = (int)param_1;

  piVar1 = *(int **)(iVar6 + 0x428);

  if (piVar1 == (int *)0x0) {

    return 1;

  }

  else {

    uVar2 = 0;

    switch(*(u8 *)(piVar1 + 0x12)) {

    case '\0':

      if (piVar1[0x11] != 0) {

        if ((*(u16 *)(iVar6 + 0xd8) & 0x4000) != 0) {

          H_Cdvd_ReadSync((HCdvd*)piVar1[0x11]);

        }

        lVar5 = H_Cdvd_IsFileLoaded((HCdvd*)piVar1[0x11]);

        if (lVar5 == 0) {
          goto switch_end;
        }


        if (piVar1[0x13] == 0) {

          piVar1[0xe] = *(int *)(piVar1[0x11] + 0x110);

          piVar1[0xf] = *(int *)(piVar1[0x11] + 0x118);

        }

        else {

          iVar3 = (int)H_Cdvd_ArchiveGetFile((HCdvd*)piVar1[0x11],0,(u32 *)&iStack_4);

          piVar1[0xe] = iVar3;

          piVar1[0xf] = iStack_4;

          uVar4 = (u32)H_Cdvd_ArchiveGetFile((HCdvd*)piVar1[0x11],1,(u32 *)&iStack_4);

          func_0031e8d0(iVar6 + 0x3f8,*(u16 *)(iVar6 + 0xd4),*(u16 *)(iVar6 + 0xd6),

                       uVar4,iStack_4);

        }

        *(u8 *)(piVar1 + 0x12) = 2;

      }

      if (*piVar1 == 0) {

        iVar3 = func_004c58a0(3,1,piVar1 + 0xe);

        *piVar1 = iVar3;

        *(u8 *)(piVar1 + 0x12) = 2;

      }

    case '\x01':

      if (*(u8 *)(piVar1 + 0x12) != 1) goto switchD_0031b278_caseD_2;

      for (;;) {

        lVar5 = func_0031aad0(param_1);

        if (lVar5 == 0) {
          goto switch_end;
        }

        *(u8 *)(piVar1 + 0x12) = 2;

switchD_0031b278_caseD_2:

        lVar5 = func_00319970(param_1);

        if (lVar5 != 0) {

          *(u8 *)(piVar1 + 0x12) = 3;

          break;

        }

        *(u8 *)(piVar1 + 0x12) = 1;

      }

      if ((*(u16 *)(iVar6 + 0xd8) & 0x4000) == 0) goto switchD_0031b278_caseD_3;

      *(u8 *)(piVar1 + 0x12) = 4;

      goto switchD_0031b278_caseD_4;



    case '\x02':

      goto switchD_0031b278_caseD_2;

    case '\x03':

switchD_0031b278_caseD_3:

      lVar5 = func_0031aad0(param_1);

      if (lVar5 == 0) {
        goto switch_end;
      }

      *(u8 *)(piVar1 + 0x12) = 4;

    case '\x04':

switchD_0031b278_caseD_4:

      if (piVar1[0x10] != 0) {

        func_001a14c0(piVar1[0x10]);

      }

      func_004c5780(*piVar1,piVar1 + 0xe);

      if (piVar1[0x11] != 0) {

        H_Cdvd_Destroy((HCdvd*)piVar1[0x11]);

      }

      *(u8 *)(piVar1 + 0x12) = 5;

    case '\x05':

      uVar2 = 1;

    }

  }

switch_end:
  return uVar2;

}




// FUN_0031B470


void func_0031b470(void)



{

  memset(sMdlListTails, 0, sizeof(sMdlListTails));

  return;

}




/* W323 measured func_0031b4a0 opt_loop_invariants on: nd293 -> nd266; object 472/480. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0031B4A0 NONMATCHING


void func_0031b4a0(char* param_1,u16 param_2)



{

  bool bVar1;

  short sVar2;

  int lVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  

  bVar1 = false;

  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {

    iVar5 = iVar6 * 6;

    lVar3 = datGetFlag(*(u16 *)((u8 *)&DAT_0069aee0 + iVar5));

    if ((lVar3 == 1) && (param_2 == *(u16 *)((u8 *)&DAT_0069aee2 + iVar5))) {
      param_2 = *(u16 *)((u8 *)&DAT_0069aee4 + iVar5);

      break;

    }

  }

  uVar4 = 0;

  do {

    if (0xbd < uVar4) {

LAB_0031b594:

      if (bVar1) {

        sVar2 = datGetDaysSinceApr5();

        if (sVar2 < 0x39) {

          sprintf(param_1, (const char*)0x69b080, &gp0xffff9d20,param_2);

        }

        else if (sVar2 < 0xb3) {

          sprintf(param_1, (const char*)0x69b0a0, &gp0xffff9d20,param_2);

        }

        else {

          sprintf(param_1, (const char*)0x69b080, &gp0xffff9d20,param_2);

        }

      }

      else {

        sprintf(param_1, (const char*)0x69b0c0, &gp0xffff9d20,param_2);

      }

      return;

    }

    if (param_2 == *(u16 *)((u8 *)&DAT_0069af00 + uVar4 * 2)) {

      bVar1 = true;

      goto LAB_0031b594;

    }

    if (param_2 < *(u16 *)((u8 *)&DAT_0069af00 + uVar4 * 2)) goto LAB_0031b594;

    uVar4 = uVar4 + 1;

  } while( true );

}
#pragma pop




// FUN_0031B680 NONMATCHING


u32 func_0031b680(int param_1,int param_2,int *param_3,int *param_4)
{
  short sVar1;
  u32 uVar2;
  int iVar3;

  if (param_1 != 5) {
    uVar2 = 0;
  }
  else {
    iVar3 = (int)param_2;
    if ((param_2 < 60000) || (0xeac3 < param_2)) {
      if ((param_2 < 0xeac4) || (0xeb27 < param_2)) {
        if ((param_2 < 0xeb28) || (0xeb8b < param_2)) {
          if ((param_2 < 0xeb8c) || (0xebef < param_2)) {
            uVar2 = 0;
          }
          else {
            sVar1 = datGetPartyId(2);
            *param_3 = (int)sVar1;
            *param_4 = iVar3 % 100;
            uVar2 = 1;
          }
        }
        else {
          sVar1 = datGetPartyId(1);
          *param_3 = (int)sVar1;
          *param_4 = iVar3 % 100;
          uVar2 = 1;
        }
      }
      else {
        sVar1 = datGetPartyId(0);
        *param_3 = (int)sVar1;
        *param_4 = iVar3 % 100;
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
      *param_3 = 1;
      *param_4 = iVar3 % 100;
    }
  }
  return uVar2;
}




// FUN_0031B820 NONMATCHING


void func_0031b820(u32 param_1,u32 param_2)



{

  bool bVar1;

  char cVar2;

  u16 uVar3;

  int sVar4;

  u32 uVar5;

  int lVar6;

  int sVar7;

  char auStack_100[256];

  

  bVar1 = false;

  uVar3 = datGetEquipmentIdx((short)param_2,0);

  sVar4 = datGetEquipmentId((short)param_2,uVar3);

  switch(param_2) {

  default:

    return;

  case 1:

    uVar5 = datGetUnit(1);

    cVar2 = datCalcGetHeldWeaponType(uVar5);

    if ((cVar2 == '\x03') || (cVar2 == '\a')) {

      lVar6 = (int)mdlSearch(7,sVar4,0);

      if (lVar6 == 0) {

        if (cVar2 != '\a') {

          sprintf(auStack_100, (const char*)0x69b0f0, &gp0xffff9d20,sVar4);

        }

        else {

          sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar4);

        }

        func_003192a0(param_1,3,7,sVar4,auStack_100,0);

      }

      else {

        func_00319490(param_1,3,7,sVar4,0);

      }

      sVar7 = sVar4 + 1000;

      lVar6 = (int)mdlSearch(7,sVar7,0);

      if (lVar6 == 0) {

        if (cVar2 != '\a') {

          sprintf(auStack_100, (const char*)0x69b130, &gp0xffff9d20,sVar4);

        }

        else {

          sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar4);

        }

        func_003192a0(param_1,4,7,sVar7,auStack_100,0);

        bVar1 = true;

      }

      else {

        func_00319490(param_1,4,7,sVar7,0);

        bVar1 = true;

      }

    }

    else {

      func_00319490(param_1,3,10,sVar4,0);

    }

    break;

  case 2:

    func_00319490(param_1,3,7,sVar4,0);

    break;

  case 3:

    lVar6 = (int)mdlSearch(7,sVar4,0);

    if (lVar6 == 0) {

      sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar4);

      func_003192a0(param_1,3,7,sVar4,auStack_100,0);

    }

    else {

      func_00319490(param_1,3,7,sVar4,0);

    }

    sVar7 = sVar4 + 1000;

    lVar6 = (int)mdlSearch(7,sVar7,0);

    if (lVar6 == 0) {

      sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar4);

      func_003192a0(param_1,4,7,sVar7,auStack_100,0);

    }

    else {

      func_00319490(param_1,4,7,sVar7,0);

    }

    bVar1 = true;

    break;

  case 4:

    func_00319490(param_1,3,7,sVar4,0);

    break;

  case 5:

    func_00319490(param_1,3,7,sVar4,0);

    break;

  case 7:

    lVar6 = (int)mdlSearch(7,sVar4,0);

    if (lVar6 == 0) {

      sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar4);

      func_003192a0(param_1,3,7,sVar4,auStack_100,0);

    }

    else {

      func_00319490(param_1,3,7,sVar4,0);

    }

    sVar7 = sVar4 + 1000;

    lVar6 = (int)mdlSearch(7,sVar7,0);

    if (lVar6 == 0) {

      sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar4);

      func_003192a0(param_1,4,7,sVar7,auStack_100,0);

    }

    else {

      func_00319490(param_1,4,7,sVar7,0);

    }

    bVar1 = true;

    break;

  case 8:

    func_00319490(param_1,3,7,sVar4,0);

    break;

  case 9:

    lVar6 = datGetScenarioMode();

    if (lVar6 != 0) {

      lVar6 = (int)mdlSearch(7,sVar4,0);

      if (lVar6 == 0) {

        sprintf(auStack_100, (const char*)0x69b170, &gp0xffff9d20,sVar4);

        func_003192a0(param_1,3,7,sVar4,auStack_100,0);

      }

      else {

        func_00319490(param_1,3,7,sVar4,0);

      }

    }

    else {

      func_00319490(param_1,3,7,sVar4,0);

    }

    break;

  case 10:

    func_00319490(param_1,3,7,sVar4,0);

  }

  mdl003196d0((Model*)param_1,3,500);

  if (bVar1) {

    mdl003196d0((Model*)param_1,4,0x1f5);

  }

  return;

}




// FUN_0031BE80


u32 func_0031be80(u32 param_1)
{
  short sVar1;
  short sVar2;
  int bVar4;
  u32 uVar5;
  int lVar6;
  int iVar8;
  int iVar7;
  short *psVar9;
  short *psVar10;
  int sVar3;
  u16 asStack_20[12];
  u32 iStack_8;
  u32 iStack_4;

  iStack_8 = 0;
  iStack_4 = 0;
  iVar8 = (int)param_1;
  lVar6 = func_0031b680_u32ptr(*(u16 *)(iVar8 + 0xd4), *(u16 *)(iVar8 + 0xd6),
                              &iStack_8, &iStack_4);
  if (lVar6 == 1) {
    if ((iStack_8 != 0) && (iStack_4 != 0)) {
      func_0031b820(param_1, iStack_8);
      uVar5 = 1;
    } else {
      uVar5 = 0;
    }
  } else {
    sVar3 = *(u16 *)(iVar8 + 0xd6);
    *(MdlShortVec10 *)((u8 *)asStack_20) =
        *(MdlShortVec10 *)((u8 *)DAT_0069b190_abs);
    if (*(u16 *)(iVar8 + 0xd4) != 5) {
      bVar4 = 0;
    } else {
      for (iVar8 = 0; iVar8 < 0x14; iVar8 = iVar8 + 1) {
        if (sVar3 == asStack_20[iVar8]) {
          if (asStack_20[iVar8] != 0x3e6) {
            iStack_8 = iVar8 + 1;
          } else {
            iStack_8 = 9;
          }
          bVar4 = 1;
          goto LAB_0031bfb8;
        }
      }
      bVar4 = 0;
    }
LAB_0031bfb8:
    if (bVar4 == 1) {
      func_0031b820(param_1, iStack_8);
      uVar5 = 1;
    } else {
      uVar5 = 0;
    }
  }
  return uVar5;
}
// FUN_0031C000


void func_0031c000(char* param_1,u32 param_2)



{


  u8 uVar3;

  u32 lVar4;

  u32 uVar5;



  short auStack_20 [12];

  int iStack_4;

  int iStack_8;

  u32 uVar9;

  

  uVar9 = param_2 & 0xffff;

  iStack_4 = 0;

  iStack_8 = 0;

  lVar4 = func_0031b680(5,uVar9,&iStack_4,&iStack_8);

  if (lVar4 == 1) {

    if (iStack_4 >= 0xb) {

      K_Assert((const char*)DAT_0069b1c0_abs,0x1a7);

    }

    if (iStack_4 == 0) {

      sprintf(param_1, (const char*)DAT_0069b1d0_abs, &gp0xffff9d20);

      return;

    }

    if ((iStack_4 == 1) && (iStack_8 == 2)) {

      *(MdlShortVec8 *)((u8 *)auStack_20) =
          *(MdlShortVec8 *)((u8 *)DAT_0069b1b0_abs);

      uVar5 = datGetUnit(1);

      uVar3 = datCalcGetHeldWeaponType(uVar5);

      if (uVar3 >= 8) {

        K_Assert((const char*)DAT_0069b1c0_abs,0x1bc);

      }

      lVar4 = datGetScenarioMode();

      if (lVar4 != 0) {

        uVar9 = 0x91;

      }

      else {

        uVar9 = (u16)auStack_20[uVar3];

      }

      printf((const char*)DAT_0069b1e0_abs,uVar9);

    }

    else if ((iStack_4 == 9) && (lVar4 = datGetScenarioMode(), lVar4 != 0)) {

      uVar9 = 0x3e6;

    }

    else {

      uVar9 = *(u16 *)(DAT_0069b0d0_abs + iStack_4 * 2);

    }

  }

  func_0031b4a0(param_1,uVar9);

  return;

}




/* W323 measured func_0031c1d0 opt_common_subs off: nd1055 -> nd889; object 1544/1552. */
#pragma push
#pragma opt_common_subs off
// FUN_0031C1D0 NONMATCHING


u32 func_0031c1d0(int param_1)



{

  u8 cVar1;

  u16 uVar2;

  int sVar3;


  u32 uVar5;
  int lVar6;

  int iVar7;




  int sVar8;

  char auStack_100[256];

  

  iVar7 = (int)param_1;

  if (*(u16 *)(iVar7 + 0xd4) != 1) return 0;

    uVar2 = datGetEquipmentIdx(*(u16 *)(iVar7 + 0xd6),0);

    sVar3 = datGetEquipmentId(*(u16 *)(iVar7 + 0xd6),uVar2);

    switch(*(u16 *)(iVar7 + 0xd6)) {

    case 1:

      uVar5 = datGetUnit(1);

      cVar1 = datCalcGetHeldWeaponType(uVar5);

      if ((cVar1 == '\x03') || (cVar1 == '\a')) {

        lVar6 = (int)mdlSearch(10,sVar3,0);

        if (lVar6 == 0) {

          if (cVar1 == '\a') {

            sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar3);

          }

          else {

            sprintf(auStack_100, (const char*)0x69b0f0, &gp0xffff9d20,sVar3);

          }

          func_003192a0(param_1,0,10,sVar3,auStack_100,0);

        }

        else {

          func_00319490(param_1,0,10,sVar3,0);

        }

        sVar8 = sVar3 + 1000;

        lVar6 = (int)mdlSearch(10,sVar8,0);

        if (lVar6 == 0) {

          if (cVar1 == '\a') {

            sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar3);

          }

          else {

            sprintf(auStack_100, (const char*)0x69b130, &gp0xffff9d20,sVar3);

          }

          func_003192a0(param_1,1,10,sVar8,auStack_100,0);

        }

        else {

          func_00319490(param_1,1,10,sVar8,0);

        }

      }
      else {
        func_00319490(param_1,0,10,sVar3,0);
      }

      break;

    case 2:

      func_00319490(param_1,0,7,sVar3,0);

      break;

    case 3:

      lVar6 = (int)mdlSearch(7,sVar3,0);

      if (lVar6 == 0) {

        sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar3);

        func_003192a0(param_1,0,7,sVar3,auStack_100,0);

      }

      else {

        func_00319490(param_1,0,7,sVar3,0);

      }

      sVar8 = sVar3 + 1000;

      lVar6 = (int)mdlSearch(7,sVar8,0);

      if (lVar6 == 0) {

        sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar3);

        func_003192a0(param_1,1,7,sVar8,auStack_100,0);

      }

      else {

        func_00319490(param_1,1,7,sVar8,0);

      }

      break;

    case 4:

      func_00319490(param_1,0,7,sVar3,0);

      break;

    case 5:

      func_00319490(param_1,0,7,sVar3,0);

      break;

    case 7:

      lVar6 = (int)mdlSearch(7,sVar3,0);

      if (lVar6 == 0) {

        sprintf(auStack_100, (const char*)0x69b110, &gp0xffff9d20,sVar3);

        func_003192a0(param_1,0,7,sVar3,auStack_100,0);

      }

      else {

        func_00319490(param_1,0,7,sVar3,0);

      }

      sVar8 = sVar3 + 1000;

      lVar6 = (int)mdlSearch(7,sVar8,0);

      if (lVar6 == 0) {

        sprintf(auStack_100, (const char*)0x69b150, &gp0xffff9d20,sVar3);

        func_003192a0(param_1,1,7,sVar8,auStack_100,0);

      }

      else {

        func_00319490(param_1,1,7,sVar8,0);

      }

      break;

    case 8:

      func_00319490(param_1,0,7,sVar3,0);

      break;

    case 9:

      lVar6 = datGetScenarioMode();

      if (lVar6 == 0) {

        func_00319490(param_1,0,7,sVar3,0);

      }

      else {

        lVar6 = (int)mdlSearch(7,sVar3,0);

        if (lVar6 == 0) {

          sprintf(auStack_100, (const char*)0x69b170, &gp0xffff9d20,sVar3);

          func_003192a0(param_1,0,7,sVar3,auStack_100,0);

        }

        else {

          func_00319490(param_1,0,7,sVar3,0);

        }

      }

      break;

    case 10:

      func_00319490(param_1,0,7,sVar3,0);

    }

    mdl003196d0((Model*)param_1,0,500);

    mdl003196d0((Model*)param_1,1,0x1f5);

  return 1;
}
#pragma pop




// FUN_0031C7E0


u32 func_0031c7e0(int param_1)



{
  int iVar1;
  iVar1 = param_1;
  FUN_0031e4d0((int *)(iVar1 + 0x3f8),*(u16 *)(iVar1 + 0xd4),*(u16 *)(iVar1 + 0xd6));

  return 1;

}




// FUN_0031C820 NONMATCHING


u32 func_0031c820(u16 param_1,u16 param_2,char* param_3)



{

  u8 cVar1;

  int uVar2;

  int sVar3;

  u32 lVar4;

  u32 uVar5;

  

  switch(param_1) {


  case 1:

    uVar2 = datGetEquipmentIdx((short)param_2,1);

    sVar3 = datGetEquipmentId((short)param_2,uVar2);

    if (param_2 == 1) {

      lVar4 = datGetScenarioMode();

      if (lVar4 != 0) {
        switch (sVar3) {
        case 0x43d:
          sprintf(param_3, MDL_PATH_FORMAT(0x69b230));
          break;
        case 0x466:
          sprintf(param_3, MDL_PATH_FORMAT(0x69b250));
          break;
        case 0x464:
          sprintf(param_3, MDL_PATH_FORMAT(0x69b270));
          break;
        default:
          lVar4 = datGetFlag(0x2f0);
          if (lVar4 != 1) {
            sprintf(param_3, MDL_PATH_FORMAT(0x69b2b0));
          }
          else {
            sprintf(param_3, MDL_PATH_FORMAT(0x69b290));
          }
          break;
        }
      }
      else {
        uVar5 = datGetUnit(1);
        cVar1 = datCalcGetHeldWeaponType(uVar5);
        if ((((cVar1 == '\0') && (lVar4 = datGetFlag(0x15), lVar4 == 0)) &&
            (lVar4 = datGetFlag(0x1310), lVar4 == 0)) && (lVar4 = func_0031e420(1,1), lVar4 == 0))
        {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b2d0));
        }
        else if (sVar3 == 0x40e) {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b370), 1, cVar1);
        }
        else if (sVar3 == 0x45f) {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b350), 1, cVar1);
        }
        else if (sVar3 == 0x453) {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b330), 1, cVar1);
        }
        else if (sVar3 == 0x452) {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b310), 1, cVar1);
        }
        else if (sVar3 == 0x439) {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b2f0), 1, cVar1);
        }
        else {
          sprintf(param_3, MDL_PATH_FORMAT(0x69b390), 1, cVar1);
        }
      }
    }

    else {

      switch(param_2) {

      default:

        sprintf(param_3, MDL_PATH_FORMAT(0x69b930), DAT_007cca10);

        break;

      case 2:

        if (sVar3 == 0x41e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b450), DAT_007cca10);

        }

        else if (sVar3 == 0x462) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b430), DAT_007cca10);

        }

        else if (sVar3 == 0x45d) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b410), DAT_007cca10);

        }

        else if (sVar3 == 0x459) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b3f0), DAT_007cca10);

        }

        else if (sVar3 == 0x458) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b3d0), DAT_007cca10);

        }

        else if (sVar3 == 0x43a) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b3b0), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b470), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b490), DAT_007cca10);

          }

        }

        break;

      case 3:

        if (sVar3 == 0x464) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b4f0), DAT_007cca10);

        }

        else if (sVar3 == 0x466) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b4d0), DAT_007cca10);

        }

        else if (sVar3 == 0x43d) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b4b0), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b510), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b530), DAT_007cca10);

          }

        }

        break;

      case 4:

        if (sVar3 == 0x41e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b5f0), DAT_007cca10);

        }

        else if (sVar3 == 0x463) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b5d0), DAT_007cca10);

        }

        else if (sVar3 == 0x45e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b5b0), DAT_007cca10);

        }

        else if (sVar3 == 0x45b) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b590), DAT_007cca10);

        }

        else if (sVar3 == 0x45a) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b570), DAT_007cca10);

        }

        else if (sVar3 == 0x43c) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b550), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b610), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b630), DAT_007cca10);

          }

        }

        break;

      case 5:

        if (sVar3 == 0x40e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b6d0), DAT_007cca10);

        }

        else if (sVar3 == 0x460) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b6b0), DAT_007cca10);

        }

        else if (sVar3 == 0x455) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b690), DAT_007cca10);

        }

        else if (sVar3 == 0x454) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b670), DAT_007cca10);

        }

        else if (sVar3 == 0x440) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b650), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b6f0), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b710), DAT_007cca10);

          }

        }

        break;

      case 7:

        if (sVar3 == 0x40e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b7b0), DAT_007cca10);

        }

        else if (sVar3 == 0x461) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b790), DAT_007cca10);

        }

        else if (sVar3 == 0x457) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b770), DAT_007cca10);

        }

        else if (sVar3 == 0x456) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b750), DAT_007cca10);

        }

        else if (sVar3 == 0x43b) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b730), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b7d0), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b7f0), DAT_007cca10);

          }

        }

        break;

      case 8:

        if (sVar3 == 0x40e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b870), DAT_007cca10);

        }

        else if (sVar3 == 0x465) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b850), DAT_007cca10);

        }

        else if (sVar3 == 0x45c) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b830), DAT_007cca10);

        }

        else if (sVar3 == 0x43e) {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b810), DAT_007cca10);

        }

        else {

          lVar4 = datGetScenarioMode();

          if (lVar4 != 0) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b890), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b8b0), DAT_007cca10);

          }

        }

        break;

      case 9:

        lVar4 = datGetScenarioMode();

        if (lVar4 == 0) {

          if (sVar3 != 0x40e) {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b910), DAT_007cca10);

          }

          else {

            sprintf(param_3, MDL_PATH_FORMAT(0x69b8f0), DAT_007cca10);

          }

        }

        else {

          sprintf(param_3, MDL_PATH_FORMAT(0x69b8d0), DAT_007cca10);

        }

      }

    }

    break;

  case 2:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b950), DAT_007cca10,param_2);

    break;

  case 3:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b970), DAT_007cca10,param_2);

    break;

  case 5:

    func_0031c000(param_3,param_2);

    break;

  case 7:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b9b0), DAT_007cca10,param_2);

    break;

  case 8:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b9d0), DAT_007cca10,param_2);

    break;

  case 9:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b210), DAT_007cca10,(int)(u32)param_2 >> 8,param_2 & 0xff);

    break;

  case 10:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b990), DAT_007cca10,param_2);

    break;

  case 0xb:

    sprintf(param_3, MDL_PATH_FORMAT(0x69b9f0), DAT_007cca10,param_2);

    break;

  default:

    sprintf(param_3, DAT_007cca18, DAT_007cca10,

                 *(u32 *)((u8*)PTR_PTR_0069ae80[(u32)param_1 * 2] + (u32)param_2 * 4));

    break;
  }

  return 1;

}




