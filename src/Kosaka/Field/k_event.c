#include "Kosaka/Field/k_event.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_majorIds.h"
#include "Kosaka/Field/k_minorIds.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Graphics/Model/mdlManager.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_snd.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_field.h"
#include "h_cdvd.h"
#include "Main/Game/game_support.h"

#include "Kosaka/k_misc.h"
#include "Kosaka/Field/k_encount.h"
extern void func_001956d0(void* resource, u32 flags, u32 value);
extern void* DAT_0096017c_y2[];
extern u32* PTR_DAT_007cd540;
extern u16* puGpffffa850;
extern s32* piGpffffa850;
extern u32 uGpffffb59c;
extern s32 iGpffffb598;
extern f32* iGpffffb5a0;
extern void* uGpffffb52c;
extern void* uGpffffb590;
extern f32 fGpffff8248;
extern u8 gp0xffff95d0[8];
extern u8* DAT_007ce290;
extern u32 DAT_007ce280;
extern u32 DAT_007ce284;
extern u32 DAT_007ce288;
extern u8* DAT_007ce294_y2;
extern void* DAT_0086b180[0x310];
extern u32 DAT_0086e690;
extern u32 DAT_0086e694;
extern u8 DAT_00871ec0[0x200];
extern char s__field_script_reserve_xxx_006837af[];
extern RwV3d DAT_00683780[];
extern RwV3d DAT_00683910;
extern RwV3d DAT_00683920;
extern const char D_00683930[];
extern const char D_00683940[];
extern u64 DAT_00683960;
extern u32 DAT_00683968;
extern u64 DAT_00683970;
extern u32 DAT_00683978;
extern u64 DAT_00683980;
extern u32 DAT_00683988;
extern u64 DAT_00683990;
extern u32 DAT_00683998;
extern const char DAT_006839a0[];
extern const char DAT_006839c0[];
extern const char DAT_006839d8[];
extern const char DAT_006839f0[];
extern const char DAT_00683a10[];
extern void* DAT_0086bdc0[0x10];
extern u32 func_001a02c0(void);
extern u32 func_001a0310(void);
extern u8* func_001b9120_y2(void);
extern u32 func_001bff20(void);
extern u32 func_001d7300(u32 major, u16 minor, u32 area);
extern u16 func_001d75f0(u32 major, u16 minor, u32 area);
extern u16 func_001d76e0(u32 major, u16 minor, u32 area);
extern u16 func_001d77d0(u32 major, u16 minor, u16 area);
#pragma alias func_001d77d0_u32 func_001d77d0
extern u32 func_001d77d0_u32(u32 major, u32 minor, u16 area);
#pragma alias func_001d1db0_u32 func_001d1db0
extern void func_001d1db0_u32(void* work, const void* source, u32 resourceId);
extern u16* func_001d78c0(u32 major, u32 minor, u16 area);
extern FldUnit* func_001cf940(u32 encounter, void* unit);
extern u32 func_001cfdd0(u32 index);
extern void* func_001cd9a0(u32 charId);
extern u16 func_003b65d0(u16 id, void* table);
extern void* func_00318b60(void* model);
extern s32 func_00318ed0(void* model, s32 index, RwV3d* position);
extern u64 func_00318b70(void* model);
extern void func_00318a30(void* dst, void* src, u32 count);
extern void func_00318a50(void* src, void* dst, void* value, u32 count);
extern void func_00318a90(void* model, void* value, u32 count);
extern void func_00319230(void* model, u32 value);
extern void func_00318ad0(void* model, void* value);
extern void* func_00318b00(void* model);
extern void func_003174e0(void* model);
extern void* func_00317450(void* value);
extern void func_00317730(void* model);
extern void func_003182d0(void* model, u32 slot, u32 anim, u32 blend, u32 flags);
extern f32 func_00318910(void* model, u32 slot, u32 anim);
extern void func_00318770(void* model, u32 slot, f32 value);
extern void func_0031c1d0(void* model);
extern void func_00319190(void* model);
extern u32 func_0016f190(u32 flag);
extern u32 func_0016ef30(void);
extern u32 func_0017d920(void);
extern u32 func_0017da40(void);
extern u32 func_0017e480(u32 a, u32 b, u32 c, u32 d);
extern void func_003b7090(u16 resourceId);
extern void func_004c2f10(u64 value);
extern f32 RwV3dLength_y2(const RwV3d* value);
extern u32 func_00488f30(void);
extern void* func_00431670(u32 parent, s32 index, void* unit);
extern void* func_0044ad20(u32 parent, s32 index);
extern void func_00434f60();
extern void func_00452010(RwV3d* value);
extern f32 func_004c6ac0_y2(const RwV3d* value);
extern void func_004cb420(u64 left, u64 right);
extern f32 func_0052e878(f32 value);
extern u32 func_00523ac8_y2(char* buffer, const char* path, ...);
extern void func_0019d400(const char* file, s32 line, s32 value);
extern void func_00521250_y2(void* dst, const void* src, u32 size);
extern void func_00100ec0_y2(void* object);
extern void func_001023a0(void* object);
extern u32 func_001016b0_y2(void);
extern u32 func_0017d800(void);
extern void func_00195020(void* task);
extern void func_0019c2f0(void* task, u32 value);
extern KwlnTask* func_001a60d0(KwlnTask* parentTask, Model* mdl,
                               u32 targetAlpha, s32 frames);
extern u32 func_00195460(void);
#pragma alias func_00195460_marker func_00195460
extern u32 func_00195460_marker(u32 marker);
extern void func_001ad870(void* task, u32 flags);
extern void func_001add40(void* task);
extern void func_001ad8c0(f32 value, void* task);
#pragma alias func_001ad8c0_reordered func_001ad8c0
extern void func_001ad8c0_reordered(KwlnTask* task, f32 value);
extern f32 func_001ad8b0(void* task);
extern u32 func_001ad930(void* task);
extern void* func_001a91b0(void* task, const RwV3d* pos);
extern void func_001a92d0(void* task, void* handle, const RwV3d* pos);
extern void func_001a9390(void* task, void* handle, u32 value);
extern void func_001a9400(void* task, void* handle);
extern void func_001a0150(u16 resourceId, u32 value);
extern void* func_001dd460(u32 parent, u32 mode, u32 id);
extern void func_001dd5f0(void* task, void* model);
extern void func_001dd5e0(void* task, u32 value);
extern void* func_001af930(u32 parent, void* resource);
extern KwlnTask* func_00194b80(KwlnTask* parent, u32 priority,
                               const char* name, void* update,
                               void* destroy, void* work);
extern void* func_001828d0(s16 id, void* dst);
extern void* func_00182d90(s16 id, u32 mode, u8 value, void* dst);
extern u32 func_00316f70(void* model);
extern u32 func_001c65e0_y2(FldUnit* unit);
extern void func_001d0bc0(void* output, u32 count);
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern u32 func_00319770(Model* model, u16 slot);
extern u32 func_001c0040(void);
extern void func_001a0dc0(u16 resourceId, u32 value);
extern KwlnTask* func_001d3c40(KwlnTask* parent, u32 model);
#pragma alias func_001d3c40_ptr func_001d3c40
extern KwlnTask* func_001d3c40_ptr(KwlnTask* parent, Model* model);
extern KwlnTask* func_001d40e0(KwlnTask* parent, FldUnit* unit);
extern u32 func_0016c970(s16 pcId);
extern u16 func_0016c4f0(s16 pcId);
extern u32 func_0016c5f0(s16 pcId);
extern void func_0016cf40(s16 pcId, s64 value);
extern void func_001adc20(KwlnTask* collisCtlTask, const RwV3d* position);
extern s32 func_001dde00(s32 value);
extern u32 func_001a01c0(void);
extern void func_004350e0(s32 parent, s32 enabled);
extern void func_001adff0(KwlnTask* collisCtlTask,
                          const RwV3d* axis,
                          f32 angle);
extern void K_Assert(const char* file, s32 line);
FldUnitMdl gFldUnitsPcMdl[FLDUNIT_PC_MAX]; // 00871ea0
FldUnit gFldUnitsPc[FLDUNIT_PC_MAX];       // 008717a0
FldUnit gFldUnitsEc[FLDUNIT_EC_MAX];  // 0086eda0. Enemies
static u32 sFldUnitsEcCount;          // 007ce28c
static inline void FldUnit_SetPcFormationPosition(s32 index,
                                                    FldUnit* unit,
                                                    RwMatrix* reference,
                                                    const RwV3d* fieldPosition)
{
    RwV3d offset;
    RwV3d position;
    KwlnTask* collisCtlTask;

    collisCtlTask = ((ResrcModelChar*)unit->resrc)->collisCtlTask;
    switch (index)
    {
    case 0:
        func_001adc20(collisCtlTask, fieldPosition);
        break;
    case 1:
        position = reference->pos;
        offset = reference->right;
        RwV3dNormalize(&offset, &offset);
        position.x += offset.x * 120.0f;
        position.y += offset.y * 120.0f;
        position.z += offset.z * 120.0f;
        func_001adc20(collisCtlTask, &position);
        break;
    case 2:
        position = reference->pos;
        offset = reference->right;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 120.0f;
        position.y += offset.y * 120.0f;
        position.z += offset.z * 120.0f;
        func_001adc20(collisCtlTask, &position);
        break;
    case 3:
        position = reference->pos;
        offset = reference->at;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 150.0f;
        position.y += offset.y * 150.0f;
        position.z += offset.z * 150.0f;
        func_001adc20(collisCtlTask, &position);
        break;
    }
}
static inline void FldUnit_SetPcDungeonPosition(s32 index,
                                                 FldUnit* unit,
                                                 RwMatrix* reference,
                                                 RwV3d* axis)
{
    RwV3d position;
    RwV3d offset;
    KwlnTask* task;
    f32 angle;

    task = ((ResrcModelChar*)unit->resrc)->collisCtlTask;
    angle = *(f32*)((u8*)unit->unk_168 + 0x10c);
    switch (index)
    {
    case 0:
        func_001adff0(task, axis, angle);
        func_001adc20(task, (const RwV3d*)((u8*)unit->unk_168 + 0x100));
        break;
    case 1:
        position = reference->pos;
        offset = reference->right;
        RwV3dNormalize(&offset, &offset);
        position.x += offset.x * 90.0f;
        position.y += offset.y * 90.0f;
        position.z += offset.z * 90.0f;
        offset = reference->at;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 70.0f;
        position.y += offset.y * 70.0f;
        position.z += offset.z * 70.0f;
        func_001adff0(task, axis, angle);
        func_001adc20(task, &position);
        break;
    case 2:
        position = reference->pos;
        offset = reference->right;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 90.0f;
        position.y += offset.y * 90.0f;
        position.z += offset.z * 90.0f;
        offset = reference->at;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 70.0f;
        position.y += offset.y * 70.0f;
        position.z += offset.z * 70.0f;
        func_001adff0(task, axis, angle);
        func_001adc20(task, &position);
        break;
    case 3:
        position = reference->pos;
        offset = reference->at;
        RwV3dNormalize(&offset, &offset);
        offset.x = -offset.x;
        offset.y = -offset.y;
        offset.z = -offset.z;
        position.x += offset.x * 150.0f;
        position.y += offset.y * 150.0f;
        position.z += offset.z * 150.0f;
        func_001adff0(task, axis, angle);
        func_001adc20(task, &position);
        break;
    }
}
typedef struct FldUnitNode
{
    Resrc base;
    RwV3d pos;
} FldUnitNode;


#pragma alias DAT_0086b180_y2 DAT_0086b180
#pragma alias DAT_0096017c_y2 DAT_0096017c
#pragma alias DAT_007ce294_y2 DAT_007ce294
#pragma alias func_001b9120_y2 func_001b9120
#pragma alias RwV3dLength_y2 RwV3dLength
#pragma alias func_004c6ac0_y2 func_004c6ac0
#pragma alias func_00523ac8_y2 func_00523ac8
#pragma alias func_00521250_y2 func_00521250
#pragma alias func_00100ec0_y2 func_00100ec0
#pragma alias func_001016b0_y2 func_001016b0
#pragma alias func_001c65e0_y2 func_001c65e0


KwlnTask* K_FldEvent_CreateDrawCmdTask(KwlnTask* fldEventTask);

extern void FUN_003b2cb0(f32 param_1, s32 param_2, s32 param_3, s32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9);
#pragma alias FUN_00318770_k_event_typed FUN_00318770
extern void FUN_00318770_k_event_typed(u32 model, u32 slot, f32 frame);
#pragma alias memset_k_event_typed memset
extern void* memset_k_event_typed(void* dst, s32 value, u32 size);
extern f32 acosf(f32 x);
#pragma alias sDegreesPerRadian D_007CAFA0
extern f32 sDegreesPerRadian;

extern const char D_006836F0[];
extern const char D_00683710[];
extern u32 func_002ff790(void* object);
extern s16 D_006836B0[];
extern f32 DAT_007caefc;
#pragma alias DAT_0086b180_abs DAT_0086b180_y2
extern u8 DAT_0086b180_abs[];
extern f32 func_004c6ac0(const RwV3d* vector);
extern s32 func_001c6dd0(const FldUnit* unit, f32 maxDist);
u32 K_FldEvent_IsPosWithinFov(const RwMatrix* viewerMat,
                               const RwV3d* targetPos,
                               f32 fov);

extern void* func_001b9120(void);
extern u32 func_001b0910(void);
extern u32 func_001008b0(const char* path);
extern void* func_00100d80(const char* path, u32 mode);
extern u32 func_001016b0(void* resource);
extern void* func_001021c0(const char* path, s32* size);
extern void func_00100ec0(void* resource);
extern void* func_001d8d80(void* script);
extern u32 func_001d8d50(void* list);
extern void* func_001d8d60(void* list, u32 index);
extern u32 func_0043a230(s32 index);
extern void* func_00316e00(u32 type, u32 id, u32 mode);
extern u16 func_003b6030(u32 id, u32 mode, void* model);
extern void* func_003b5d10(u16 resourceId);
extern void* DAT_00960184[];
extern void (*DAT_0096017c[])(void*);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern u32 DAT_0096017c_abs[];
extern u8 D_0086B180[];
extern RwV3d D_008717D0;
extern u8 DAT_0086be80[0x2700];
#pragma alias DAT_0086eda0_units DAT_0086eda0
extern FldUnit DAT_0086eda0_units[];
extern u8 DAT_0086e580[0x114];
extern const char D_00683730[];
extern void func_0019d3f0(const char* file, s32 line);
extern u32 gTraceCode;
extern u32 gFldScrMemory;
extern u32 gFldScrSize;
extern u32 DAT_007ce294;
extern u32 D_007CE284;
extern u32 D_007CE274;
#pragma alias D_008717E8_abs D_008717E8
extern u8 D_008717E8_abs[];
#pragma alias D_008717F0_abs D_008717F0
extern u8 D_008717F0_abs[];
#pragma alias D_008717F4_abs D_008717F4
extern u8 D_008717F4_abs[];
#pragma alias D_00871914_abs D_00871914
extern u8 D_00871914_abs[];
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];

extern u32 func_00523ac8(void* buffer, const char* format, ...);
extern u32 func_00521250(void* dst, u32 src, u32 size);
extern void K_Abort(const char* message, const char* file, s32 line);
extern void func_001c80c0(void);
extern u32 func_001c6080(void);
extern u32 func_001c65e0(const FldUnit* unit);
extern void* func_001c6a20(const FldUnit* unit, f32 maxDist, f32 fov);
extern FldUnit* func_001c6f50(const FldUnit* unit, f32 fov, f32 maxDist);
extern void func_001cd790(KwlnTask* task, u32 value);
extern void func_001ce880(void);
extern u32 func_001ce960(void);
extern u32 func_001d00b0(void);

static s32 FldEvent_GridCoord(f32 value)
{
    s32 cell;

    cell = (s32)((value + 400.0f) / 800.0f);
    if (cell < 0)
    {
        return (cell + 3) >> 2;
    }
    return cell >> 2;
}

static u8* FldEvent_MapCell(const RwV3d* position)
{
    s32 x;
    s32 z;

    x = FldEvent_GridCoord(position->x);
    z = FldEvent_GridCoord(position->z);
    return (u8*)0x0086b180 + x * 0xc4 + z * 0x310;
}

static u32 FldEvent_IsSceneBlocked(void)
{
    s32 major;
    s32 minor;

    major = gMtScene->fldMajorId;
    minor = gMtScene->fldMinorId;
    if (major == 4 || major == 5 || major == 6 || major == 7 || major == 8 ||
        major == 9 || major == 10 || major == 12 || major == 14 ||
        major == 33 || major == 39)
    {
        return true;
    }
    if ((major == 26 && (minor == 51 || minor == 52 || minor == 53)) ||
        (major == 27 && minor == 50) ||
        (major == 32 && (minor == 1 || minor == 2)) ||
        (major == 35 && minor == 1) ||
        (major == 37 && minor == 1))
    {
        return true;
    }
    return false;
}

// FUN_001c5ee0
u16 K_FldEvent_FindFldHitAt(const RwV3d* heroPos, ResrcFldHit** fldHitDst)
{
    u16 resTypeId;
    ResrcFldHit* hit;
    const RwV3d* tri[3];
    RwV3d normal;
    static const RwV3d sFldHitNormal = {0.0f, 1.0f, 0.0f}; // 006836c0

    resTypeId = -1;
    hit = (ResrcFldHit*)MT_Scene_GetResListHead(RESRC_TYPE_FLDHIT);

    if (K_Scene_001a0250() == true)
    {
        return -1;
    }

    while (hit != NULL)
    {
        normal = sFldHitNormal;

        tri[0] = &hit->vertices[0];
        tri[1] = &hit->vertices[1];
        tri[2] = &hit->vertices[2];
        if (K_FldFrame_IsPointInTriangle(heroPos, tri, &normal) == true)
        {
            if ((heroPos->y < tri[0]->y + 100.0f) && (heroPos->y > tri[0]->y - 100.0f))
            {
                resTypeId = hit->base.resTypeId;
                *fldHitDst = hit;
                break;
            }
        }

        tri[0] = &hit->vertices[1];
        tri[1] = &hit->vertices[2];
        tri[2] = &hit->vertices[3];
        if (K_FldFrame_IsPointInTriangle(heroPos, tri, &normal) == true)
        {
            if ((heroPos->y < tri[0]->y + 100.0f) && (heroPos->y > tri[0]->y - 100.0f))
            {
                resTypeId = hit->base.resTypeId;
                *fldHitDst = hit;
                break;
            }
        }

        hit = (ResrcFldHit*)hit->base.next;
    }  

    return resTypeId;
}

// FUN_001c6080
u32 func_001c6080(void)
{
    MtScene* scene;
    s32 major;
    u32 result;

    result = 1;
    scene = gMtScene;
    major = scene->fldMajorId;
    if (major == 4 || major == 5 || major == 6 || major == 7 || major == 8 ||
        major == 9 || major == 10 || major == 12 || major == 14 ||
        major == 0x21 || major == 0x27)
    {
        goto blocked;
    }
    if (major == 0x1A && scene->fldMinorId == 0x33)
    {
        goto blocked;
    }
    if (major == 0x1A && scene->fldMinorId == 0x34)
    {
        goto blocked;
    }
    if (major == 0x1A && scene->fldMinorId == 0x35)
    {
        goto blocked;
    }
    if (major == 0x1B && scene->fldMinorId == 0x32)
    {
        goto blocked;
    }
    if (major == 0x20 && scene->fldMinorId == 1)
    {
        goto blocked;
    }
    if (major == 0x20 && scene->fldMinorId == 2)
    {
        goto blocked;
    }
    if (major == 0x23 && scene->fldMinorId == 1)
    {
        goto blocked;
    }
    if (major == 0x25 && scene->fldMinorId == 1)
    {
        goto blocked;
    }
    goto done;

blocked:
    result = 0;
done:
    return result;
}

// FUN_001c6200
u32 K_FldEvent_IsPosWithinFov(const RwMatrix* viewerMat, const RwV3d* targetPos, f32 fov)
{
    u32 isWithinFov;
    RwV3d viewDir;
    RwV3d targetDir;
    RwV3d forward = {0.0f, 0.0f, 1.0f};
    f32 viewAngle;
    f32 halfFov;
    f32 targetAngle;

    isWithinFov = false;
    halfFov = fov / 2.0f;

    RwV3dNormalize(&viewDir, &viewerMat->at);

    targetDir.x = targetPos->x - viewerMat->pos.x;
    targetDir.y = targetPos->y - viewerMat->pos.y;
    targetDir.z = targetPos->z - viewerMat->pos.z;
    RwV3dNormalize(&targetDir, &targetDir);

    viewAngle = sDegreesPerRadian * acosf((viewDir.x * forward.x) +
                                         (viewDir.y * forward.y) +
                                         (viewDir.z * forward.z));
    if (viewDir.x < 0.0f)
    {
        viewAngle *= -1.0f;
    }
    viewAngle += 180.0f;

    targetAngle = sDegreesPerRadian * acosf((targetDir.x * forward.x) +
                                           (targetDir.y * forward.y) +
                                           (targetDir.z * forward.z));
    if (targetDir.x < 0.0f)
    {
        targetAngle *= -1.0f;
    }
    targetAngle += 180.0f;

    if (!(viewAngle + halfFov <= 360.0f))
    {
        if ((viewAngle - halfFov <= targetAngle) || !((viewAngle + halfFov) - 360.0f < targetAngle))
        {
            isWithinFov = true;
        }
    }
    else
    {
        if (viewAngle - halfFov < 0.0f)
        {
            if (!(viewAngle + halfFov < targetAngle) || ((viewAngle - halfFov) + 360.0f <= targetAngle))
            {
                isWithinFov = true;
            }
        }
        else if (!(viewAngle + halfFov < targetAngle) && (viewAngle - halfFov <= targetAngle))
        {
            isWithinFov = true;
        }
    }

    return isWithinFov;
}

// Reconstructed cell search, nearest-distance filtering, and collision raycast.
// Residual MWCC register/control-flow ordering remains; 744B object vs 768B retail window.
// FUN_001c6450
u32 func_001c6450(const RwMatrix* viewerMat,
                  const RwV3d* targetPos,
                  f32 fov,
                  f32 maxDist)
{
    RwV3d delta;
    RwV3d line[2];
    RwV3d hitPoint;
    s32 result;
    u32 rayResult;

    result = false;
    if (K_FldEvent_IsPosWithinFov(viewerMat, targetPos, fov) != true)
    {
        goto done;
    }
    delta.x = targetPos->x - viewerMat->pos.x;
    delta.y = targetPos->y - viewerMat->pos.y;
    delta.z = targetPos->z - viewerMat->pos.z;
    if (RwV3dLength(&delta) >= maxDist)
    {
        goto done;
    }

    line[0] = viewerMat->pos;
    line[1] = *targetPos;
    line[0].y += 100.0f;
    line[1].y += 100.0f;
    if (K_FldFrame_Raycast(line, &hitPoint) == true)
    {
        return false;
    }

    hitPoint = line[0];
    line[0] = line[1];
    line[1] = hitPoint;
    rayResult = K_FldFrame_Raycast(line, &hitPoint);
    result = true;
    if (rayResult == true)
    {
        return false;
    }
done:
    return result;
}

#pragma push
/* Removing this loses FUN_001c65e0 (MATCH nd0 -> MISMATCH nd169) - measured W161. */
#pragma opt_rebuildconditionals off
#pragma opt_loop_invariants on
// FUN_001c65e0 MATCHING
u32 func_001c65e0(const FldUnit* unit)
{
    s32 i;
    s32 j;
    s32 active;
    s32 sum;
    s32 average;
    u32 result;
    u32 expected;
    u32 valid;
    const FldUnit* target;
    target = unit;
    result = true;
    expected = result;
    if (datGetFlag(0xc65) == expected)
    {
        return expected;
    }
    sum = 0;
    active = 0;
    {
        FldUnit* units;
        i = 0;
        units = gFldUnitsPc;
        for (; i < FLDUNIT_PC_MAX; i++)
        {
            valid = false;
            if (units[i].genusBase != NULL && units[i].resrc != NULL)
            {
                valid = true;
            }
            valid = valid != false;
            if (valid == 1)
            {
                sum += units[i].unk_184;
                active++;
            }
        }
    }

    average = sum / active;
    for (j = 0; D_006836B0[j * 2] != -1; j++)
    {
        if (average <= D_006836B0[j * 2])
        {
            if ((average - target->unk_184) < D_006836B0[j * 2 + 1])
            {
                goto done;
            }
            result = false;
            goto done;
        }
    }
done:
    return result;
}
#pragma pop
// W419: moving z initialization after viewer-position setup improved
// func_001c6720 from 260/744 to 245/744; the base-pointer form reached
// 244/744. Explicit pointer-entry/while and do-while probes regressed to
// 300/748 and 285/748 respectively; rejected.
// W419: the same z setup reorder improved func_001c6a20 from 350/820 to
// 336/820; explicit do-while and declaration permutations made no further
// improvement.
// FUN_001c6720 NONMATCHING
void* func_001c6720(const FldUnit* unit, f32 maxDist)
{
    FldUnit* result;
    const RwV3d* viewerPosX;
    FldUnit* candidate;
    const RwV3d* viewerPosZ;
    RwMatrix* viewerMat;
    RwV3d delta;
    RwV3d line[2];
    RwV3d hitPoint;
    s32 rawX;
    s32 i;
    s32 x;
    f32 nearest;
    f32 distance;
    s32 rawZ;
    s32 z;
    u8* cell;
    u8* base;

    result = NULL;
    nearest = DAT_007caefc;
    viewerPosX = &mdlGetMatrix(unit->mdl)->pos;
    x = 0;
    if (K_Scene_001a0250() != false)
    {
        rawX = (s32)((s32)(viewerPosX->x + 400.0f) / 800.0f);
        x = rawX >> 2;
        if (rawX < 0)
        {
            x = (rawX + 3) >> 2;
        }
    }

    viewerPosZ = &mdlGetMatrix(unit->mdl)->pos;
    z = 0;
    if (K_Scene_001a0250() != false)
    {
        rawZ = (s32)((s32)(viewerPosZ->z + 400.0f) / 800.0f);
        z = rawZ >> 2;
        if (rawZ < 0)
        {
            z = (rawZ + 3) >> 2;
        }
    }

    i = 0;
    base = DAT_0086b180_abs + z * 0x310;
    cell = base + x * 0xc4;
    for (; ; i++)
    {
        candidate = *(FldUnit**)(cell + i * 4);
        if (candidate == NULL)
        {
            break;
        }
        if (candidate->genusBase != NULL)
        {
            viewerMat = mdlGetMatrix(candidate->mdl);
            delta.x = viewerMat->pos.x -
                      mdlGetMatrix(unit->mdl)->pos.x;
            delta.y = mdlGetMatrix(candidate->mdl)->pos.y -
                      mdlGetMatrix(unit->mdl)->pos.y;
            delta.z = mdlGetMatrix(candidate->mdl)->pos.z -
                      mdlGetMatrix(unit->mdl)->pos.z;
            distance = RwV3dLength(&delta);
            if (distance < maxDist && distance < nearest)
            {
                line[0] = mdlGetMatrix(unit->mdl)->pos;
                viewerMat = mdlGetMatrix(candidate->mdl);
                line[1] = viewerMat->pos;
                line[0].y += 100.0f;
                line[1].y += 100.0f;
                if (K_FldFrame_Raycast(line, &hitPoint) == false)
                {
                    result = candidate;
                    nearest = distance;
                }
            }
        }
    }
    return result;
}

// FUN_001c6a20 NONMATCHING
void* func_001c6a20(const FldUnit* unit, f32 maxDist, f32 fov)
{
    FldUnit* result;
    FldUnit* candidate;
    FldUnit** entry;
    RwMatrix* viewerMat;
    RwV3d delta;
    RwV3d line[2];
    RwV3d hitPoint;
    const RwV3d* viewerPos;
    f32 nearest;
    f32 distance;
    s32 rawX;
    s32 x;
    s32 rawZ;
    s32 z;
    s32 i;
    u8* cell;

    result = NULL;
    nearest = DAT_007caefc;
    viewerPos = &mdlGetMatrix(unit->mdl)->pos;
    x = 0;
    if (K_Scene_001a0250() != false)
    {
        rawX = (s32)((s32)(viewerPos->x + 400.0f) / 800.0f);
        x = rawX >> 2;
        if (rawX < 0)
        {
            x = (rawX + 3) >> 2;
        }
    }

    viewerPos = &mdlGetMatrix(unit->mdl)->pos;
    z = 0;
    if (K_Scene_001a0250() != false)
    {
        rawZ = (s32)((s32)(viewerPos->z + 400.0f) / 800.0f);
        z = rawZ >> 2;
        if (rawZ < 0)
        {
            z = (rawZ + 3) >> 2;
        }
    }

    i = 0;
    cell = D_0086B180 + z * 0x310 + x * 0xc4;
    entry = (FldUnit**)(cell + i * 4);
    candidate = *entry;
    while (candidate != NULL)
    {
        if (candidate->genusBase != NULL)
        {
            viewerMat = mdlGetMatrix(unit->mdl);
            if (K_FldEvent_IsPosWithinFov(viewerMat,
                                           &mdlGetMatrix(candidate->mdl)->pos,
                                           fov) != false)
            {
                delta.x = mdlGetMatrix(candidate->mdl)->pos.x -
                          mdlGetMatrix(unit->mdl)->pos.x;
                delta.y = mdlGetMatrix(candidate->mdl)->pos.y -
                          mdlGetMatrix(unit->mdl)->pos.y;
                delta.z = mdlGetMatrix(candidate->mdl)->pos.z -
                          mdlGetMatrix(unit->mdl)->pos.z;

                line[0] = mdlGetMatrix(unit->mdl)->pos;
                line[1] = mdlGetMatrix(candidate->mdl)->pos;
                line[0].y += 100.0f;
                line[1].y += 100.0f;
                if (K_FldFrame_Raycast(line, &hitPoint) == false)
                {
                    distance = RwV3dLength(&delta);
                    if (distance < maxDist && distance < nearest)
                    {
                        result = *entry;
                        nearest = distance;
                }
            }
        }
        }
        i++;
        entry = (FldUnit**)(cell + i * 4);
        candidate = *entry;
    }
    return result;
}

// FUN_001c6d70
FldUnit* func_001c6d70(const FldUnit* unit, f32 maxDist)
{
    FldUnit* result;
    s32 index;

    result = NULL;
    index = func_001c6dd0(unit, maxDist);
    if (index > -1)
    {
        result = &gFldUnitsPc[index];
    }
    return result;
}

// FUN_001c6dd0
s32 func_001c6dd0(const FldUnit* unit, f32 maxDist)
{
    RwV3d delta;
    f32 nearest;
    s32 i;
    s32 nearestIndex;

    nearest = DAT_007caefc;
    nearestIndex = -1;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        FldUnit* candidate;
        DatUnitGenusBase** genusBase;
        Model** candidateModel;

        candidate = &gFldUnitsPc[i];
        if (unit == candidate)
        {
            continue;
        }
        genusBase = &candidate->genusBase;
        if (*genusBase == NULL)
        {
            continue;
        }
        candidateModel = &candidate->mdl;
        delta.x = mdlGetMatrix(candidate->mdl)->pos.x -
                  mdlGetMatrix(unit->mdl)->pos.x;
        {
            f32 candidateY;

            candidateY = mdlGetMatrix(*candidateModel)->pos.y;
            delta.y = candidateY - mdlGetMatrix(unit->mdl)->pos.y;
        }
        {
            f32 candidateZ;

            candidateZ = mdlGetMatrix(*candidateModel)->pos.z;
            delta.z = candidateZ - mdlGetMatrix(unit->mdl)->pos.z;
        }
        if (func_002ff790(*genusBase) == true)
        {
            continue;
        }
        {
            f32 distance;

            distance = RwV3dLength(&delta);
            if (distance < maxDist && distance < nearest)
            {
                nearestIndex = i;
                nearest = distance;
            }
        }
    }
    return nearestIndex;
}

// FUN_001c6f50 NONMATCHING
FldUnit* func_001c6f50(const FldUnit* unit, f32 fov, f32 maxDist)
{
    Model** candidateModel;
    RwV3d delta;
    f32 nearest;
    f32 distance;
    s32 i;
    FldUnit* nearestUnit;

    nearest = DAT_007caefc;
    nearestUnit = NULL;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        FldUnit* candidate;

        candidate = &gFldUnitsPc[i];
        if (unit == candidate || candidate->genusBase == NULL)
        {
            continue;
        }
        if (func_002ff790(candidate->genusBase) == true)
        {
            continue;
        }
        candidateModel = &candidate->mdl;
        if (K_FldEvent_IsPosWithinFov(mdlGetMatrix(unit->mdl),
                                       &mdlGetMatrix(*candidateModel)->pos,
                                       fov) == false)
        {
            continue;
        }
        delta.x = mdlGetMatrix(*candidateModel)->pos.x - mdlGetMatrix(unit->mdl)->pos.x;
        delta.y = mdlGetMatrix(*candidateModel)->pos.y - mdlGetMatrix(unit->mdl)->pos.y;
        delta.z = mdlGetMatrix(*candidateModel)->pos.z - mdlGetMatrix(unit->mdl)->pos.z;
        distance = RwV3dLength(&delta);
        if (distance < maxDist && distance < nearest)
        {
            nearest = distance;
            nearestUnit = candidate;
        }
    }
    return nearestUnit;
}

// FUN_001c7130
u32 K_FldEvent_IsUnitWithinDistOfHero(const FldUnit* fldUnit, f32 maxDist)
{
    return K_FldEvent_AreUnitsWithinDist(fldUnit, &gFldUnitsPc[FLDUNIT_PC_HERO], maxDist);
}
// FUN_001c7160
u32 K_FldEvent_AreUnitsWithinDist(const FldUnit* fldUnitA, const FldUnit* fldUnitB, f32 maxDist)
{
    u32 withinDist;

    withinDist = false;
    if (fldUnitA->genusBase != NULL && fldUnitB->genusBase != NULL)
    {
        withinDist = K_FldEvent_ArePosWithinDist(&mdlGetMatrix(fldUnitA->mdl)->pos,
                                                 &mdlGetMatrix(fldUnitB->mdl)->pos,
                                                 maxDist);
    }

    return withinDist;
}

// FUN_001c71f0
u32 K_FldEvent_ArePosWithinDist(const RwV3d* posA, const RwV3d* posB, f32 maxDist)
{
    RwV3d diff;
    u32 withinDist;

    withinDist = false;

    diff.x = posA->x - posB->x;
    diff.y = posA->y - posB->y;
    diff.z = posA->z - posB->z;

    if (RwV3dLength(&diff) < maxDist)
    {
        withinDist = true;
    }

    return withinDist;
}

// FUN_001c7270 NONMATCHING
void* func_001c7270(const FldUnit* unit, f32 maxDist)
{
    RwV3d* viewerPos;
    u8* cell;
    void** objectSlot;
    RwV3d delta;
    s32 i;
    s32 rawX;
    s32 rawZ;
    s32 x;
    s32 z;
    s32 offset;

    viewerPos = &mdlGetMatrix(unit->mdl)->pos;
    x = 0;
    if (K_Scene_001a0250() != false)
    {
        rawX = (s32)(viewerPos->x + 400.0f) / 800.0f;
        x = rawX >> 2;
        if (rawX < 0)
        {
            x = (rawX + 3) >> 2;
        }
    }
    viewerPos = &mdlGetMatrix(unit->mdl)->pos;
    z = 0;
    if (K_Scene_001a0250() != false)
    {
        rawZ = (s32)(viewerPos->z + 400.0f) / 800.0f;
        z = rawZ >> 2;
        if (rawZ < 0)
        {
            z = (rawZ + 3) >> 2;
        }
    }
    cell = DAT_0086b180_abs + z * 0x310 + x * 0xc4;
    i = 0;
    offset = 0;
    while (*(void**)(cell + 0x60 + offset) != NULL)
    {
        objectSlot = (void**)(cell + 0x60 + offset);
        delta.x = *(f32*)((u8*)*objectSlot + 0x10c) -
                  mdlGetMatrix(unit->mdl)->pos.x;
        delta.y = *(f32*)((u8*)*objectSlot + 0x110) -
                  mdlGetMatrix(unit->mdl)->pos.y;
        delta.z = *(f32*)((u8*)*objectSlot + 0x114) -
                  mdlGetMatrix(unit->mdl)->pos.z;
        if (func_004c6ac0(&delta) < maxDist)
        {
            return *(void**)(cell + 0x1e0 + offset);
        }
        i++;
        offset += sizeof(void*);
    }
    return NULL;
}

// FUN_001c74c0
ResrcModelNpc* K_FldEvent_FindInteractableNpc()
{
    ResrcModelNpc* npc;
    ResrcModelNpc* interactableNpc;
    RwV3d lookAtPos;
    RwV3d distDiff;
    u32 isWithinFov;
    s32 currAnimId;

    npc = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    interactableNpc = NULL;
    while (npc != NULL)
    {
        isWithinFov = K_FldEvent_IsPosWithinFov(mdlGetMatrix(gFldUnitsPc[FLDUNIT_PC_HERO].mdl),
                                                &mdlGetMatrix(npc->mdl)->pos,
                                                120.0f);
        if (isWithinFov == true)
        {
            distDiff.x = mdlGetMatrix(npc->mdl)->pos.x - mdlGetMatrix(gFldUnitsPc[FLDUNIT_PC_HERO].mdl)->pos.x;
            distDiff.y = mdlGetMatrix(npc->mdl)->pos.y - mdlGetMatrix(gFldUnitsPc[FLDUNIT_PC_HERO].mdl)->pos.y;
            distDiff.z = mdlGetMatrix(npc->mdl)->pos.z - mdlGetMatrix(gFldUnitsPc[FLDUNIT_PC_HERO].mdl)->pos.z;

            if (RwV3dLength(&distDiff) < 200.0f)
            {
                lookAtPos = mdlGetMatrix(gFldUnitsPc[FLDUNIT_PC_HERO].mdl)->pos;
                lookAtPos.y += 140.0f;

                mdlLookAtSetTargetPosXYZ(npc->mdl, &lookAtPos);
                mdlLookAtSetFlags(npc->mdl, mdlLookAtGetFlags(npc->mdl) | MDLLOOKAT_FLAG_UNK1000);

                if (interactableNpc == NULL)
                {
                    interactableNpc = npc;
                }

                if (gMtScene->fldMajorId == FLD_MAJOR_DORM)
                {
                    currAnimId = mdlAnimGetId(npc->mdl, 0);
                    if (currAnimId >= 4)
                    {
                        if (currAnimId % 2 == 0)
                        {
                            mdlAnimSet(npc->mdl, 0, currAnimId + 1, 7, MDLANIM_FLAG_LOOP);
                        }
                    }
                }
            }
            else
            {
                mdlLookAtDisableTarget(npc->mdl);

                if (gMtScene->fldMajorId == FLD_MAJOR_DORM)
                {
                    currAnimId = mdlAnimGetId(npc->mdl, 0);
                    if (currAnimId >= 4)
                    {
                        if (currAnimId % 2 == 1)
                        {
                            mdlAnimSet(npc->mdl, 0, currAnimId - 1, 7, MDLANIM_FLAG_LOOP);
                        }
                    }
                }
            }
        }
        else
        {
            mdlLookAtDisableTarget(npc->mdl);

            if (gMtScene->fldMajorId == FLD_MAJOR_DORM)
            {
                currAnimId = mdlAnimGetId(npc->mdl, 0);
                if (currAnimId >= 4)
                {
                    if (currAnimId % 2 == 1)
                    {
                        mdlAnimSet(npc->mdl, 0, currAnimId - 1, 7, MDLANIM_FLAG_LOOP);
                    }
                }
            }
        }

        npc = (ResrcModelNpc*)npc->base.next;
    }

    return interactableNpc;
}

/* W415 negative probes: moving 001d8d60 ahead of 001d8d50 via found/sentinel/do-while loop forms raised nd 334 to 385, 391, 398, 434, 461, 482, 485, or 489; baseline retained. */
// FUN_001c7830 NONMATCHING
void func_001c7830(void* output, void* script)
{
    s32 i;
    u32 hidden;
    void* list;
    FldUnit* unit;
    RwV3d delta;
    f32 distance;
    u32 count;
    u32* out;

    list = func_001d8d80(script);
    out = (u32*)output;
    memset_k_event_typed(out, 0, 0x34);
    out[1] = (u32)gFldUnitsPc[0].genusBase;
    out[5] = *(u32*)((u8*)script + 0x48);
    count = 1;
    hidden = 0;
    for (i = 1; i < FLDUNIT_PC_MAX; i++)
    {
        unit = &gFldUnitsPc[i];
        if (unit->genusBase == NULL)
        {
            continue;
        }
        if (list != NULL)
        {
            u32 j;
            u32 listCount = func_001d8d50(list);

            for (j = 0; j < listCount; j++)
            {
                if (func_001d8d60(list, j) == unit)
                {
                    break;
                }
            }
            if (j == listCount && func_0043a230(i) == 1)
            {
                continue;
            }
        }
        delta.x = mdlGetMatrix(unit->mdl)->pos.x - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.x;
        delta.y = mdlGetMatrix(unit->mdl)->pos.y - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.y;
        delta.z = mdlGetMatrix(unit->mdl)->pos.z - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.z;
        distance = RwV3dLength(&delta);
        if (gMtScene->fldMajorId == 0x33 && gMtScene->fldMinorId == 1)
        {
            distance = 0.0f;
        }
        if (distance < 2000.0f)
        {
            *(u16*)((u8*)unit->genusBase + 10) |= 1;
            out[count++] = (u32)unit->genusBase;
        }
        else
        {
            if (hidden < 3)
            {
                *(u16*)((u8*)unit->genusBase + 10) &= (u16)~1;
                *(void**)((u8*)out + 0x1c + hidden * 8) = unit->genusBase;
                *(f32*)((u8*)out + 0x20 + hidden * 8) = distance;
                hidden++;
            }
            else
            {
                *(u16*)((u8*)unit->genusBase + 10) |= 1;
                out[count++] = (u32)unit->genusBase;
            }
        }
    }
}

// FUN_001c7b10
u32 K_FldEvent_IsUnitHero(const FldUnit* fldUnit)
{
    return fldUnit == &gFldUnitsPc[FLDUNIT_PC_HERO];
}

// FUN_001c7b30. Temp name ? First condition is weird
u32 K_FldEvent_IsUnitNearFldHit(const FldUnit* unit)
{
    u32 isNear;
    ResrcFldHit* hit;
    RwV3d unitPos;
    const RwV3d* tri[3];
    RwV3d normal;
    static const RwV3d sFldHitNormal = {0.0f, 1.0f, 0.0f}; // 006836e0

    isNear = false;
    hit = (ResrcFldHit*)MT_Scene_GetResListHead(RESRC_TYPE_FLDHIT);

    if (!K_Scene_001a0250())
    {
        return false;
    }

    unitPos = mdlGetMatrix(unit->mdl)->pos;
    while (hit != NULL)
    {
        normal = sFldHitNormal;

        tri[0] = &hit->vertices[0];
        tri[1] = &hit->vertices[1];
        tri[2] = &hit->vertices[2];
        if (K_FldFrame_IsPointInTriangle(&unitPos, tri, &normal) == true)
        {
            if ((unitPos.y < tri[0]->y + 100.0f) && (unitPos.y > tri[0]->y - 100.0f))
            {
                isNear = true;
                break;
            }
        }

        tri[0] = &hit->vertices[1];
        tri[1] = &hit->vertices[2];
        tri[2] = &hit->vertices[3];
        if (K_FldFrame_IsPointInTriangle(&unitPos, tri, &normal) == true)
        {
            if ((unitPos.y < tri[0]->y + 100.0f) && (unitPos.y > tri[0]->y - 100.0f))
            {
                isNear = true;
                break;
            }
        }

        hit = (ResrcFldHit*)hit->base.next;
    }  

    return isNear;
}

// FUN_001c7ce0. Temp name maybe
u32 K_FldEvent_IsCharNearHeroBeforeBtl(u32 charId)
{
    u32 ret;
    s32 i;
    FldUnit* currUnit;
    RwV3d distDiff;
    u32 isNear;
    u32 fldMajor;

    ret = false;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        currUnit = &gFldUnitsPc[i];

        if (currUnit->genusBase != NULL &&
           (charId == currUnit->charId))
        {
            isNear = false;

            distDiff.x = gFldUnitsPc[FLDUNIT_PC_HERO].matBeforeBtl.pos.x - currUnit->matBeforeBtl.pos.x;
            distDiff.y = gFldUnitsPc[FLDUNIT_PC_HERO].matBeforeBtl.pos.y - currUnit->matBeforeBtl.pos.y;
            distDiff.z = gFldUnitsPc[FLDUNIT_PC_HERO].matBeforeBtl.pos.z - currUnit->matBeforeBtl.pos.z;

            if (RwV3dLength(&distDiff) < 1600.0f)
            {
                isNear = true;
            }

            if (isNear == true)
            {
                ret = true;
                break;
            }
        }
    }

    fldMajor = gMtScene->fldMajorId;
    if (fldMajor == FLD_MAJOR_ADAMAH && gMtScene->fldMinorId == 0x33  ||
       (fldMajor == FLD_MAJOR_ADAMAH && gMtScene->fldMinorId == 0x34) ||
       (fldMajor == FLD_MAJOR_ADAMAH && gMtScene->fldMinorId == 0x35) ||
       (fldMajor == FLD_MAJOR_DUNGEON && gMtScene->fldMinorId == FLD_MINOR_DUNGEON_FIRST_FLOOR))
    {
        ret = true;
    }

    return ret;
}

// FUN_001c7e70
u32 func_001c7e70(u16 resourceId, u16 variant)
{
    char path[128];
    void* loaded;

    if ((s32)resourceId == -1)
    {
        return false;
    }
    if (func_001b0910() == false)
    {
        func_00523ac8(path, D_006836F0, resourceId, variant);
        if (func_001008b0(path) == 0)
        {
            return false;
        }
        loaded = func_00100d80(path, 0);
        return (u32)loaded;
    }
    return true;
}

/* W415: retail has no zero comparison before either copy; both memcpy destinations are loaded through K_Field_Get, restoring the two 0x001b9120 calls (nd207->202). Direct/alias helper probes were nd207-neutral; retaining null guards was nd247/object432 over the 416-byte window. */
/* W419: outer/cache gotos plus direct allocator stores and volatile cache-size dereferences reduce 001c7f20 to nd66/object416 (previous nd202/object416); residual is confined to the CDVD path. */
/* W419 MATCH: CDVD field alias plus volatile allocator/memcpy size loads reproduce the retail CDVD path at 416/416 (nd0). */
// FUN_001c7f20
u32 func_001c7f20(void* resource)
{
    char path[76];
    void* source;
    u32 size;
    HCdvd* cdvd = (HCdvd*)resource;

    if (cdvd == NULL)
    {
        return true;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(cdvd) == false)
        {
            goto failed;
        }
        func_001c80c0();
        *(s32*)((u8*)K_Field_Get() + 0x1144) = cdvd->fileSize / 0x2c;
        *(void**)((u8*)K_Field_Get() + 0x1148) =
            ((void* (*)(u32, u32, u32))DAT_00960184[0])(
                1, *(volatile u32*)&cdvd->fileSize, 0x40000);
        memcpy(*(void**)((u8*)K_Field_Get() + 0x1148),
               cdvd->fileMemory, *(volatile u32*)&cdvd->fileSize);
        H_Cdvd_Destroy(cdvd);
        return true;
    }
    sprintf(path, D_00683710, gMtScene->fldMajorId, gMtScene->fldMinorId);
    source = H_Cdvd_CacheFindFile(path, (u32*)&size);
    if (source == NULL)
    {
        goto success;
    }
    func_001c80c0();
    *(s32*)((u8*)K_Field_Get() + 0x1144) = size / 0x2c;
    *(void**)((u8*)K_Field_Get() + 0x1148) =
        ((void* (*)(u32, u32, u32))DAT_00960184[0])(
            1, *(volatile u32*)&size, 0x40000);
    memcpy(*(void**)((u8*)K_Field_Get() + 0x1148),
           source, *(volatile u32*)&size);
success:
    return true;
failed:
    return false;
}

// FUN_001c80c0
void func_001c80c0(void)
{
    if (*(void**)((u8*)func_001b9120() + 0x1148) != NULL)
    {
        *(s32*)((u8*)func_001b9120() + 0x1144) = 0;
        (*(void (**)(void*))DAT_0096017c_abs)(
            *(void**)((u8*)func_001b9120() + 0x1148));
        *(void**)((u8*)func_001b9120() + 0x1148) = NULL;
    }
}

// FUN_001c8120 NONMATCHING
void func_001c8120(void* work)
{
    RwV3d candidates[5];
    RwV3d pcDelta;
    RwV3d ecDelta;
    RwV3d specialDelta;
    RwV3d* candidate;
    FldUnit* targetUnit;
    FldUnit* unit;
    u8* record;
    s32 slot;
    s32 i;
    s32 target;
    s32 j;
    u32 occupied;

    if (K_Scene_001a0250() == false)
    {
        return;
    }

    candidates[0].x = (f32)((s32)((D_008717D0.x + 400.0f) / 800.0f)) * 800.0f;
    candidates[0].y = D_008717D0.y;
    candidates[0].z = (f32)((s32)((D_008717D0.z + 400.0f) / 800.0f)) * 800.0f;
    candidates[1].x = candidates[0].x + 250.0f;
    candidates[1].y = candidates[0].y;
    candidates[1].z = candidates[0].z + 250.0f;
    candidates[2].x = candidates[0].x - 250.0f;
    candidates[2].y = candidates[0].y;
    candidates[2].z = candidates[0].z - 250.0f;
    candidates[3].x = candidates[0].x + 250.0f;
    candidates[3].y = candidates[0].y;
    candidates[3].z = candidates[0].z - 250.0f;
    candidates[4].x = candidates[0].x - 250.0f;
    candidates[4].y = candidates[0].y;
    candidates[4].z = candidates[0].z + 250.0f;

    for (slot = 0; slot < 3; slot++)
    {
        void* entry;

        entry = *(void**)((u8*)work + 0x1c + slot * 8);
        if (entry == NULL || (*(u16*)((u8*)entry + 10) & 1) == 0)
        {
            continue;
        }

        targetUnit = NULL;
        for (i = 1; i < FLDUNIT_PC_MAX; i++)
        {
            unit = &gFldUnitsPc[i];
            if (unit->genusBase != NULL &&
                *(u16*)(*(u8**)((u8*)entry + 4) + 2) == unit->charId)
            {
                targetUnit = unit;
                target = i;
                break;
            }
        }
        if (targetUnit == NULL)
        {
            continue;
        }

        for (i = 0; i < 5; i++)
        {
            candidate = &candidates[i];
            occupied = false;
            for (j = 0; j < FLDUNIT_PC_MAX; j++)
            {
                unit = &gFldUnitsPc[j];
                if (unit->genusBase == NULL || j == target)
                {
                    continue;
                }
                pcDelta.x = candidate->x - unit->matBeforeBtl.pos.x;
                pcDelta.y = candidate->y - unit->matBeforeBtl.pos.y;
                pcDelta.z = candidate->z - unit->matBeforeBtl.pos.z;
                if (RwV3dLength(&pcDelta) < 70.0f)
                {
                    occupied = true;
                    break;
                }
            }

            if (occupied == false)
            {
                for (j = 0; j < 0x18; j++)
                {
                    unit = &DAT_0086eda0_units[j];
                    if (unit->genusBase == NULL)
                    {
                        continue;
                    }
                    pcDelta.x = candidate->x - unit->matBeforeBtl.pos.x;
                    pcDelta.y = candidate->y - unit->matBeforeBtl.pos.y;
                    pcDelta.z = candidate->z - unit->matBeforeBtl.pos.z;
                    if (RwV3dLength(&pcDelta) < 70.0f)
                    {
                        occupied = true;
                        break;
                    }
                }
            }

            if (occupied == false)
            {
                for (j = 0; j < 0x20; j++)
                {
                    record = DAT_0086be80 + j * 0x138;
                    if (*(u32*)record == 0)
                    {
                        continue;
                    }
                    ecDelta.x = candidate->x - *(f32*)(record + 0x10c);
                    ecDelta.y = candidate->y - *(f32*)(record + 0x110);
                    ecDelta.z = candidate->z - *(f32*)(record + 0x114);
                    if (RwV3dLength(&ecDelta) < 70.0f)
                    {
                        occupied = true;
                        break;
                    }
                }
            }

            if (occupied == false && *(u32*)DAT_0086e580 == 1)
            {
                specialDelta.x = candidate->x - *(f32*)(DAT_0086e580 + 0x104);
                specialDelta.y = candidate->y - *(f32*)(DAT_0086e580 + 0x108);
                specialDelta.z = candidate->z - *(f32*)(DAT_0086e580 + 0x10c);
                if (RwV3dLength(&specialDelta) < 70.0f)
                {
                    occupied = true;
                }
            }

            if (occupied == false)
            {
                break;
            }
        }
        if (i == 5)
        {
            func_0019d3f0(D_00683730, 0x502);
        }
        targetUnit->matBeforeBtl.pos = candidates[i];
    }
}

// Retail routes the camera aggregate through an aligned 0x60-byte scratch area before copying six quadwords back; this preserves that real data flow even though the wider function remains NONMATCHING.
// FUN_001c8620 NONMATCHING
void* K_FldEvent_UpdateFldEventTask(KwlnTask* fldEventTask)
{
    FldEvent* fldEvent;
    u32* eventWords;
    RwMatrix* heroMat;
    RwMatrix heroMatBuf;
    RwV3d markerPos;
    RwV3d offset;
    RwV3d case4Marker;
    RwV3d case6Marker;
    RwV3d case8Offset;
    RwV3d fovPos;
    RwV3d npcOffset;
    RwV3d idleCheckOffset;
    RwV3d case6UpVec;
    RwMatrix case6MatBuf;
    s32 currentActor;
    s32 taskResult;
    s32 model;
    s32 npc;
    s32 hit;
    s32 i;
    s16 currentArea;
    u32 active;
    u32 allLoaded;
    u8 scriptPath[128];
    struct
    {
        u8 pad[0x90];
        u_long128 eventData[6];
    } eventStack;


#define EVENT_WORD(index) (eventWords[(index)])
#define EVENT_S16(offset) (*(s16*)((u8*)fldEvent + (offset)))
#define EVENT_U16(offset) (*(u16*)((u8*)fldEvent + (offset)))
#define EVENT_U8(offset)  (*(u8*)((u8*)fldEvent + (offset)))
#define FIELD_WORD(offset) (((u32*)K_Field_Get())[(offset) / sizeof(u32)])
#define FIELD_U16(offset) (*(u16*)((u8*)K_Field_Get() + (offset)))
#define DATA_U8(address)  (*(u8*)(address))
#define DATA_U16(address) (*(u16*)(address))
#define DATA_U32(address) (*(u32*)(address))
#define DATA_S32(address) (*(s32*)(address))
    extern void* K_Field_Get();
    extern u16 K_Field_GetMajorId(KwlnTask* fldRootTask);
    extern u16 K_Field_GetMinorId(KwlnTask* fldRootTask);
#define PTR_U32(base, offset) (*(u32*)((u8*)(base) + (offset)))
#define PTR_S16(base, offset) (*(s16*)((u8*)(base) + (offset)))
#define PTR_U16(base, offset) (*(u16*)((u8*)(base) + (offset)))
#define PTR_U8(base, offset) (*(u8*)((u8*)(base) + (offset)))
#define PTR_S32(base, offset) (*(s32*)((u8*)(base) + (offset)))

    /* The surrounding field subsystems still have provisional interfaces. */
    extern s32 FUN_001008b0();
    extern s32 FUN_00100d80();
    extern s32 FUN_00108710();
    extern s32 FUN_00195460();
    extern s32 FUN_0016f190();
    extern s32 FUN_0017d800();
    extern s32 FUN_001a01c0();
    extern s32 FUN_001a0250();
    extern s32 FUN_001b08d0();
    extern s32 FUN_001b0910();
    extern s32 FUN_001b09b0();
    extern s32 FUN_001bffe0();
    extern s32 FUN_001c0010();
    extern s32 FUN_001c0440();
    extern s32 FUN_001c0740();
    extern KwlnTask* FUN_001c1f30(KwlnTask* parentTask, KwlnTask* collisionTask);
    extern s32 FUN_001d8d80();
    extern s32 FUN_001dd600();
    extern s32 FUN_001e7200();
    extern s32 FUN_001e7290();
    extern s32 FUN_002ff260();
    extern s32 FUN_002ff310();
    extern s32 FUN_002ff790();
    extern s32 FUN_00308c60();
    extern s32 FUN_00316f70();
    extern s32 FUN_00318540();
    extern s32 FUN_00318b60();
    extern s32 FUN_00318d10();
    extern s32 FUN_00319770();
    extern s32 FUN_0035bb40();
    extern s32 FUN_0035bc00();
    extern s32 FUN_003b5d10();
    extern s32 FUN_003b5d50();
    extern s32 FUN_003c7850();
    extern s32 FUN_0042ba30();
    extern s32 FUN_004352e0();
    extern s32 FUN_004353f0();
    extern s32 FUN_00453460();
    extern s32 FUN_00453480();
    extern s32 FUN_0045af40();
    extern f32 FUN_00318990();
    extern f32 FUN_004c6ac0();
    extern u32 func_0010a770();

    fldEvent = (FldEvent*)fldEventTask->workData;
    eventWords = (u32*)fldEvent;

    /* Keep the draw-command work in sync even while an interaction owns input. */
    K_FldEvent_001cd650((KwlnTask*)FIELD_WORD(0x08), (&gTraceCode)[1]);

    if (fldEvent->eventType > FLDEVENT_TYPE_INIT && EVENT_WORD(0x19) == 0 &&
        FUN_0045af40() == 0 && EVENT_WORD(4) == 0)
    {
        FUN_00109f60(3, 0);
        FUN_003952d0(0, 0x87, 3);
        FUN_00108570();
        FUN_001086a0(0x5a);
        FUN_00108670(6);
        FUN_00108fd0(0x5a);
        FUN_00396f50(0);
        FUN_003c8f70();
        FUN_003c8f20();
        if (EVENT_WORD(0x18) != 0)
        {
            FUN_00195020(EVENT_WORD(0x18));
        }
        FUN_0016f1f0(0x141d, true);
        fldEvent->eventType = 0x1d;
        EVENT_WORD(4) = true;
    }

    if (EVENT_WORD(0x3e) == 0)
    {
        FUN_004533e0(false);
        EVENT_WORD(0x3e) = -1;
    }
    else if ((s32)EVENT_WORD(0x3e) > 0)
    {
        EVENT_WORD(0x3e)--;
    }
    if ((s32)EVENT_WORD(0x3f) > 0)
    {
        EVENT_WORD(0x3f)--;
    }

    switch (fldEvent->eventType)
    {
        case FLDEVENT_TYPE_INIT:
            EVENT_WORD(5) = FUN_003b5d10(0x400);
            fldEvent->eventType++;
            break;

        case FLDEVENT_TYPE_IDLE:
            if (fldEvent->inputLocked == true || fldEvent->interactionLocked == true)
            {
                break;
            }

            func_001cd790((KwlnTask*)EVENT_WORD(0x17), false);
            EVENT_WORD(0x38) = false;
            if (FUN_00453460() >= 0)
            {
                currentActor = FUN_00453460();
                EVENT_WORD(9) = 0x0086eda0 + currentActor * 0x1c0;
                if (FUN_002ff790(PTR_U32(EVENT_WORD(9), 0x48)) != true)
                {
                    FUN_001c7830(&EVENT_WORD(10), EVENT_WORD(9));
                    EVENT_U16(0x28) |= 1 | 2;
                    if (PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x12) == 0 &&
                        PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x14) == 0)
                    {
                        EVENT_S16(0x40) = (s16)gMtScene->fldMajorId + 200;
                        EVENT_U16(0x42) = 1;
                    }
                    else
                    {
                        EVENT_S16(0x40) = PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x12);
                        EVENT_U16(0x42) = PTR_U16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x14);
                    }
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_003182d0(PTR_U32(EVENT_WORD(9), 0x50), 0, 3, 0, 0);
                    fldEvent->eventType = 4;
                }
                break;
            }

            if ((*(u16*)DAT_007e094e_abs & 0x80) != 0 && func_001c6080() == true)
            {
                FUN_0010a4e0(0, 0, 0, 0);
                EVENT_WORD(0x18) = FUN_0035bb40(10, gFldScrMemory, 2);
                FUN_0035c1a0(EVENT_WORD(0x18), false);
                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                FUN_001d8c60(true);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                FUN_004532d0(true);
                FUN_004350e0(false, true);
                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                break;
            }

            if (FUN_0016f190(0x171) == false && (*(u16*)DAT_007e094e_abs & 0x10) != 0)
            {
                if (FIELD_WORD(0x0c) != 0) { FUN_00195020(FIELD_WORD(0x0c)); FIELD_WORD(0x0c) = 0; }
                if (FIELD_WORD(0x18) != 0) { FUN_00195020(FIELD_WORD(0x18)); FIELD_WORD(0x18) = 0; }
                if (FIELD_WORD(0x28) != 0) { FUN_00195020(FIELD_WORD(0x28)); FIELD_WORD(0x28) = 0; }
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                FUN_001d1860(true);
                FUN_001d1910();
                FUN_001d1b60();
                FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                FUN_004532d0(true);
                FUN_004350e0(false, true);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                FUN_0045a430(true);
                FUN_0045af70(true);
                FUN_001d4180();
                if (FIELD_WORD(0x1200) != 0) FUN_001a9470(FIELD_WORD(0x1200));
                FUN_003c8f70();
                FUN_003c8f20();
                if (FIELD_WORD(0x10d4) != 0)
                {
                    for (i = 0; i < 4; i++)
                    {
                        if (FIELD_WORD(0x10d4 + i * 4) != 0)
                        {
                            FUN_00195020(FIELD_WORD(0x10d4 + i * 4));
                            FIELD_WORD(0x10d4 + i * 4) = 0;
                        }
                    }
                    for (i = 0; i < 0x18; i++)
                    {
                        if (FIELD_WORD(0x10e4 + i * 4) != 0)
                        {
                            FUN_00195020(FIELD_WORD(0x10e4 + i * 4));
                            FIELD_WORD(0x10e4 + i * 4) = 0;
                        }
                    }
                }
                fldEvent->eventType = 0x17;
                break;
            }

            currentArea = FUN_00308c60(PTR_U32((void*)*(u32*)D_008717E8_abs, 4)) & 0xff;
            EVENT_WORD(0x3b) = currentArea;
            EVENT_WORD(0x40) = DAT_007ce294 + currentArea * 0x18;
            EVENT_WORD(9) = (u32)func_001c6a20(
                &gFldUnitsPc[FLDUNIT_PC_HERO],
                *(f32*)((u8*)EVENT_WORD(0x40) + 0x14),
                180.0f);

            /* Near field geometry, map objects, NPCs, and hit volumes all share the idle marker. */
            if (EVENT_WORD(9) == 0 && K_FldEvent_IsUnitNearFldHit(&gFldUnitsPc[FLDUNIT_PC_HERO]) == true)
            {
                if (EVENT_WORD(9) == 0) EVENT_WORD(0x38) = true;
                if ((*(u16*)DAT_007e094e_abs & 0x40) != 0)
                {
                    EVENT_WORD(0x18) = FUN_0035bc00(10, FUN_001bffe0(), FUN_001c0010(), 0);
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d8c60(true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                    if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                    EVENT_WORD(0x38) = false;
                    fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                }
                break;
            }

            active = false;
            if (FUN_001a0250() != false && *(u32*)D_008717E8_abs != 0 && (model = FUN_003b5d10(0x2bff)) != 0)
            {
                offset.x = ((RwMatrix*)FUN_00318b60(PTR_U32((void*)model, 0x104)))->pos.x - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.x;
                offset.y = ((RwMatrix*)FUN_00318b60(PTR_U32((void*)model, 0x104)))->pos.y - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.y;
                offset.z = ((RwMatrix*)FUN_00318b60(PTR_U32((void*)model, 0x104)))->pos.z - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.z;
                active = RwV3dLength(&offset) < 200.0f;
            }
            if (active != false)
            {
                if (EVENT_WORD(9) == 0) EVENT_WORD(0x38) = true;
                if ((*(u16*)DAT_007e094e_abs & 0x40) != 0)
                {
                    EVENT_WORD(0x18) = FUN_0035bc00(10, FUN_001bffe0(), FUN_001c0010(), true);
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d8c60(true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                    if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                    EVENT_WORD(0x38) = false;
                    fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                }
                break;
            }

            heroMat = (RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
            currentActor = FUN_001a0250() != false ? (s32)(heroMat->pos.x + 400.0f) : 0;
            currentArea = FUN_001a0250() != false ? (u32)(s32)(((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.z + 400.0f) : 0;
            currentActor /= 800;
            currentArea = (u32)((s32)currentArea / 800);
            if (currentActor < 0) currentActor = (currentActor + 3) >> 2; else currentActor >>= 2;
            if ((s32)currentArea < 0) currentArea = ((s32)currentArea + 3) >> 2; else currentArea >>= 2;
            model = 0;
            for (i = 0; ; i++)
            {
                npc = *(u32*)(0x0086b180 + i * 4 + currentActor * 0xc4 +
                              currentArea * 0x310 + 0x60);
                if (npc == 0) break;
                if (PTR_U32((void*)npc, 0) != 0)
                {
                    offset.x = *(f32*)((u8*)npc + 0x10c) - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.x;
                    offset.y = *(f32*)((u8*)npc + 0x110) - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.y;
                    offset.z = *(f32*)((u8*)npc + 0x114) - ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.z;
                    if (RwV3dLength(&offset) < 200.0f)
                    {
                        model = *(u32*)(0x0086b1e0 + i * 4 +
                                         currentActor * 0xc4 + currentArea * 0x310);
                        break;
                    }
                }
            }
            D_007CE284 = model;
            if (model != 0 && PTR_U32((void*)model, 4) == 0)
            {
                if (EVENT_WORD(9) == 0) EVENT_WORD(0x38) = true;
                if ((*(u16*)DAT_007e094e_abs & 0x40) != 0)
                {
                    PTR_U32((void*)model, 4) = true;
                    EVENT_WORD(0x18) = FUN_0035bc00(10, gFldScrMemory, gFldScrSize, false);
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d8c60(true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                    if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                    EVENT_WORD(0x38) = false;
                    fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                }
                break;
            }


            npc = (s32)K_FldEvent_FindInteractableNpc();
            EVENT_WORD(7) = npc;
            if (npc != 0 && PTR_U32((void*)npc, 500) != 0)
            {
                EVENT_WORD(0x38) = true;
                if ((*(u16*)DAT_007e094e_abs & 0x40) != 0 && EVENT_WORD(0x3f) == 0)
                {
                    EVENT_WORD(0x38) = false;
                    active = PTR_U32((void*)npc, 500);
                    if (active == 1)
                    {
                        currentActor = PTR_S16((void*)PTR_U32((void*)npc, 0x1f8), 8);
                        if (currentActor != -1)
                        {
                            FUN_003c72d0(FIELD_WORD(0x1154));
                            FUN_003c7430(currentActor);

                            FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                            FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                            EVENT_WORD(8) = FUN_00318540(PTR_U32((void*)npc, 0x128), 0);
                            currentActor = gMtScene->fldMajorId;
                            if ((currentActor == 7 || currentActor == 4) && EVENT_WORD(8) > 3)
                            {
                                FUN_003191f0(PTR_U32((void*)npc, 0x128), FUN_00319200(PTR_U32((void*)npc, 0x128)) & ~0x800);
                            }
                            else
                            {
                                if (currentActor == 7 || currentActor == 4) currentActor = EVENT_WORD(8) + 1;
                                else if (EVENT_WORD(8) == 0) currentActor = 3;
                                else currentActor = EVENT_WORD(8) + 1;
                                FUN_003182d0(PTR_U32((void*)npc, 0x128), 0, currentActor, 7, false);
                            }
                            if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                            if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                            if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                            fldEvent->eventType = 0x15;
                        }
                        else
                        {
                            currentActor = PTR_S16((void*)PTR_U32((void*)npc, 0x1f8), 0xc);
                            if (currentActor != -1)
                            {
                                EVENT_WORD(0x18) = FUN_0035bc00(10, FIELD_WORD(0x114c), FIELD_WORD(0x1150), currentActor);

                                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                                EVENT_WORD(8) = FUN_00318540(PTR_U32((void*)npc, 0x128), 0);
                                currentActor = gMtScene->fldMajorId;
                                if ((currentActor == 7 || currentActor == 4) && EVENT_WORD(8) > 3)
                                {
                                    FUN_003191f0(PTR_U32((void*)npc, 0x128), FUN_00319200(PTR_U32((void*)npc, 0x128)) & ~0x800);
                                }
                                else
                                {
                                    if (currentActor == 7 || currentActor == 4) currentActor = EVENT_WORD(8) + 1;
                                    else if (EVENT_WORD(8) == 0) currentActor = 3;
                                    else currentActor = EVENT_WORD(8) + 1;
                                    FUN_003182d0(PTR_U32((void*)npc, 0x128), 0, currentActor, 7, false);
                                }
                                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                                fldEvent->eventType = 0x16;
                            }
                        }
                    }
                    else if (active == 2)
                    {
                        currentActor = PTR_S16((void*)PTR_U32((void*)npc, 0x1fc), 0x6c);
                        if (currentActor != -1)
                        {
                            FUN_003c72d0(PTR_U32((void*)npc, 0x208));
                            FUN_003c7430(FUN_001b8fd0(PTR_U32((void*)npc, 0x1fc), PTR_U32((void*)npc, 0x200), PTR_U32((void*)npc, 0x204)));

                            FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                            FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                            EVENT_WORD(8) = FUN_00318540(PTR_U32((void*)npc, 0x128), 0);
                            currentActor = gMtScene->fldMajorId;
                            if (currentActor == 7 || currentActor == 4) currentActor = EVENT_WORD(8) + 1;
                            else if (EVENT_WORD(8) == 0) currentActor = 3;
                            else currentActor = EVENT_WORD(8) + 1;
                            FUN_003182d0(PTR_U32((void*)npc, 0x128), 0, currentActor, 7, false);
                            if (PTR_U32((void*)npc, 0x210) != 0) FUN_001dd5e0((void*)PTR_U32((void*)npc, 0x210), true);
                            if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                            if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                            if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                            fldEvent->eventType = 0x15;
                        }
                        else
                        {
                            currentActor = PTR_S32((void*)PTR_U32((void*)npc, 0x1fc), 0x70);
                            if (currentActor != -1)
                            {
                                EVENT_WORD(0x18) = FUN_0035bc00(10, DATA_U32(0x007ce23c), DATA_U32(0x007ce238), currentActor);

                                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                                EVENT_WORD(8) = FUN_00318540(PTR_U32((void*)npc, 0x128), 0);
                                currentActor = gMtScene->fldMajorId;
                                if (currentActor == 7 || currentActor == 4) currentActor = EVENT_WORD(8) + 1;
                                else if (EVENT_WORD(8) == 0) currentActor = 3;
                                else currentActor = EVENT_WORD(8) + 1;
                                FUN_003182d0(PTR_U32((void*)npc, 0x128), 0, currentActor, 7, false);
                                if (PTR_U32((void*)npc, 0x210) != 0) FUN_001dd5e0((void*)PTR_U32((void*)npc, 0x210), true);
                                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                                fldEvent->eventType = 0x16;
                            }
                        }
                    }
                }
                break;
            }

            heroMat = (RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
            hit = K_FldEvent_FindFldHitAt(&heroMat->pos, (ResrcFldHit**)&model);
            if ((u16)hit != 0xffff)
            {
                /* Retail offset 0x1640 re-fetches the field hit table for every access. */
#define HIT_DATA_PTR(offset) ((u8*)FIELD_WORD(0x1148) + ((hit & 0x3ff) * 0x2c) + (offset))
                active = true;
                if (FIELD_WORD(0x1144) <= (u32)(hit & 0x3ff)) FUN_0019d3f0(0x00683730, 0x756);
                for (i = 0; i < 3; i++)
                {
                    currentActor = PTR_S32(HIT_DATA_PTR(0), i * 4);
                    if (currentActor != -1 && FUN_0016f190(currentActor) == false)
                    {
                        active = false;
                        break;
                    }
                }
                if (active != false && PTR_U16(HIT_DATA_PTR(0), 0x0e) != 0 && EVENT_WORD(0x39) != PTR_U16(HIT_DATA_PTR(0), 0x0e))
                {
                    EVENT_WORD(0x39) = PTR_U16(HIT_DATA_PTR(0), 0x0e);
                    FUN_001ddca0();
                }
                if (active != false && PTR_U8(HIT_DATA_PTR(0), 0x0c) == 1)
                {
                    switch (PTR_U32(HIT_DATA_PTR(0), 0x20))
                    {
                        case 4:
                            fovPos.x = (*(f32*)((u8*)model + 0x128) + *(f32*)((u8*)model + 0x140)) * 0.5f;
                            fovPos.y = (*(f32*)((u8*)model + 0x12c) + *(f32*)((u8*)model + 0x144)) * 0.5f;
                            fovPos.z = (*(f32*)((u8*)model + 0x130) + *(f32*)((u8*)model + 0x148)) * 0.5f;
                            break;
                        case 3:
                            fovPos.x = (*(f32*)((u8*)model + 0x134) + *(f32*)((u8*)model + 0x140)) * 0.5f;
                            fovPos.y = (*(f32*)((u8*)model + 0x138) + *(f32*)((u8*)model + 0x144)) * 0.5f;
                            fovPos.z = (*(f32*)((u8*)model + 0x13c) + *(f32*)((u8*)model + 0x148)) * 0.5f;
                            break;
                        case 2:
                            fovPos.x = (*(f32*)((u8*)model + 0x11c) + *(f32*)((u8*)model + 0x134)) * 0.5f;
                            fovPos.y = (*(f32*)((u8*)model + 0x120) + *(f32*)((u8*)model + 0x138)) * 0.5f;
                            fovPos.z = (*(f32*)((u8*)model + 0x124) + *(f32*)((u8*)model + 0x13c)) * 0.5f;
                            break;
                        case 1:
                            fovPos.x = (*(f32*)((u8*)model + 0x11c) + *(f32*)((u8*)model + 0x128)) * 0.5f;
                            fovPos.y = (*(f32*)((u8*)model + 0x120) + *(f32*)((u8*)model + 0x12c)) * 0.5f;
                            fovPos.z = (*(f32*)((u8*)model + 0x124) + *(f32*)((u8*)model + 0x130)) * 0.5f;
                            break;
                        default:
                            fovPos.x = *(f32*)((u8*)model + 0x104);
                            fovPos.y = *(f32*)((u8*)model + 0x108);
                            fovPos.z = *(f32*)((u8*)model + 0x10c);
                            break;
                    }
                    active = K_FldEvent_IsPosWithinFov((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs), &fovPos, 120.0f);
                }
                if (active != false)
                {
                if (PTR_U8(HIT_DATA_PTR(0), 0x0d) != 0) EVENT_WORD(0x38) = true;
                if (PTR_S16(HIT_DATA_PTR(0), 0x10) == -1 &&
                    (PTR_U8(HIT_DATA_PTR(0), 0x0d) == 0 || (*(u16*)DAT_007e094e_abs & 0x40) != 0))
                {
                    EVENT_WORD(6) = 0;
                    if (PTR_S16(HIT_DATA_PTR(0), 0x18) != 0)
                    {
                        EVENT_WORD(6) = FUN_003b5d50(10);
                        while (EVENT_WORD(6) != 0 && PTR_S16((void*)EVENT_WORD(6), 0) != PTR_S16(HIT_DATA_PTR(0), 0x18))
                        {
                            EVENT_WORD(6) = PTR_U32((void*)EVENT_WORD(6), 0xf8);
                        }
                        if (EVENT_WORD(6) != 0)
                        {
                            FUN_003189f0(1.0f, PTR_U32((void*)EVENT_WORD(6), 0x104), 0);
                            FUN_003182d0(PTR_U32((void*)EVENT_WORD(6), 0x104), 0, PTR_U16(HIT_DATA_PTR(0), 0x1a), 0, 0);
                        }
                    }
                    if (PTR_S32(HIT_DATA_PTR(0), 0x1c) != -1) FUN_0010a4e0(0, 6, 2, PTR_U16(HIT_DATA_PTR(0), 0x1c));
                    EVENT_WORD(0x38) = false;
                    EVENT_S16(0x0c) = (s16)hit;
                    fldEvent->eventType = FLDEVENT_TYPE_FLDHIT_INTERACT;
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    break;
                }
                if (PTR_S16(HIT_DATA_PTR(0), 0x10) != -1 &&
                    (PTR_U8(HIT_DATA_PTR(0), 0x0d) == 0 || (*(u16*)DAT_007e094e_abs & 0x40) != 0))
                {
                    EVENT_WORD(0x18) = FUN_0035bc00(10, FIELD_WORD(0x1048), FIELD_WORD(0x104c), PTR_U16(HIT_DATA_PTR(0), 0x10));
                    FUN_001d8c60(true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                    if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                    FUN_00458890();
                    EVENT_WORD(0x38) = false;
                    fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                    break;
                }
                }
            }

            if (EVENT_WORD(0x39) != 0)
            {
                EVENT_WORD(0x39) = 0;
                FUN_001ddca0(-1);
            }
            hit = (s32)func_001c6f50(&gFldUnitsPc[FLDUNIT_PC_HERO], 90.0f, 200.0f);
            if (hit != 0 && FUN_004353f0(hit) == 1)
            {
                if (EVENT_WORD(9) == 0) EVENT_WORD(0x38) = true;
                if ((*(u16*)DAT_007e094e_abs & 0x40) != 0)
                {
                    EVENT_WORD(0x18) = FUN_0035bb40(10, PTR_U32((void*)hit, 0x1b4), 9);
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d8c60(true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), false);
                    if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), false);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                    FUN_00458890();
                    EVENT_WORD(0x38) = false;
                    fldEvent->eventType = FLDEVENT_TYPE_OBJ_INTERACT;
                }
            }
            if (FUN_001a01c0() != false &&
                !((gMtScene->fldMajorId == 0x20 && gMtScene->fldMinorId == 2) ||
                  (gMtScene->fldMajorId == 0x23 && gMtScene->fldMinorId == 1) ||
                  (gMtScene->fldMajorId == 0x25 && gMtScene->fldMinorId == 1) ||
                   gMtScene->fldMajorId == 0x21))
            {
                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                if (FUN_0017d800() == true)
                {
                    FUN_003189f0(2.0f, *(u32*)D_008717F0_abs, 0);
                    EVENT_WORD(0x3a) = false;
                }
                FUN_003182d0(*(u32*)D_008717F0_abs, 0, 4, 0, 0x20);
                EVENT_WORD(0x3b) = FUN_00308c60(PTR_U32((void*)*(u32*)D_008717E8_abs, 4)) & 0xff;
                EVENT_WORD(0x40) = DAT_007ce294 + EVENT_WORD(0x3b) * 0x18;
                FUN_00318770_k_event_typed(*(u32*)D_008717F0_abs, 0,
                                           (f32)PTR_S16((void*)EVENT_WORD(0x40), 0));
                switch (EVENT_WORD(0x3b))
                {
                    case 0: FUN_0010a4e0(1, 8, 1, 0x44); break;
                    case 1: FUN_0010a4e0(1, 8, 1, 0x45); break;
                    case 2: FUN_0010a4e0(1, 8, 1, 0x46); break;
                    case 3: FUN_0010a4e0(1, 8, 1, 0x47); break;
                    case 4: FUN_0010a4e0(1, 8, 1, 0x48); break;
                    case 5:
                    case 6: FUN_0010a4e0(1, 8, 1, 0x49); break;
                    case 7: FUN_0010a4e0(1, 8, 4, 10); break;
                }
                EVENT_WORD(0x41) = PTR_S16((void*)EVENT_WORD(0x40), 4) - PTR_S16((void*)EVENT_WORD(0x40), 0);
                EVENT_WORD(0x43) = EVENT_WORD(0x41) == 0 ? 0 :
                                    (s32)(*(f32*)((u8*)EVENT_WORD(0x40) + 8) / (f32)EVENT_WORD(0x41));
                EVENT_WORD(0x42) = PTR_S16((void*)EVENT_WORD(0x40), 2) - PTR_S16((void*)EVENT_WORD(0x40), 6);
                EVENT_WORD(0x44) = EVENT_WORD(0x42) == 0 ? 0 :
                                    (s32)(*(f32*)((u8*)EVENT_WORD(0x40) + 8) / (f32)EVENT_WORD(0x42));
                heroMat = (RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
                /* Retail re-fetches the matrix for every field, not caching. */
                *(f32*)((u8*)fldEvent + 0x114) = ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.x;
                *(f32*)((u8*)fldEvent + 0x118) = ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.y;
                *(f32*)((u8*)fldEvent + 0x11c) = ((RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs))->pos.z;
                FUN_001d8c60(true);
                EVENT_WORD(0x3d) = FUN_001d5c00((KwlnTask*)FIELD_WORD(4));
                FUN_001d5c10((KwlnTask*)FIELD_WORD(4), true);
                if (FIELD_WORD(0x18) != 0) FUN_00429e90((void*)FIELD_WORD(0x18), true);
                fldEvent->eventType = 8;
            }
            break;

        case FLDEVENT_TYPE_OBJ_INTERACT:
            if (FUN_00195460(EVENT_WORD(0x18)) != true)
            {
                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), false);
                FUN_001d8c60(false);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), false);
                FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), false);
                FUN_004532d0(false);
                FUN_004350e0(false, false);
                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), true);
                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), true);
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), true);
                FUN_00458930();
                EVENT_WORD(0x18) = 0;
                fldEvent->eventType = FLDEVENT_TYPE_IDLE;
            }
            break;

        case FLDEVENT_TYPE_FLDHIT_INTERACT:
            FUN_001baaa0((KwlnTask*)FIELD_WORD(0x00),
                          PTR_U16((u8*)FIELD_WORD(0x1148) + (EVENT_U16(0x0c) & 0x3ff) * 0x2c, 0x12),
                          PTR_U16((u8*)FIELD_WORD(0x1148) + (EVENT_U16(0x0c) & 0x3ff) * 0x2c, 0x14),
                          PTR_U16((u8*)FIELD_WORD(0x1148) + (EVENT_U16(0x0c) & 0x3ff) * 0x2c, 0x16));
            fldEvent->eventType = FLDEVENT_TYPE_DESTROY;
            break;

        case 4:
            if (FUN_00318990(PTR_U32(EVENT_WORD(9), 0x50), 0) >= 13.0f)
            {
                case4Marker = ((RwMatrix*)FUN_00318b60(
                    ((u32*)D_008717F0_abs)[(s8)FUN_00453480() * 0x70]))->pos;
                case4Marker.y += 100.0f;
                taskResult = FUN_001a91b0((KwlnTask*)FIELD_WORD(0x11f4), &case4Marker);
                FUN_001a9390((KwlnTask*)FIELD_WORD(0x11f4), taskResult, 3);
                FUN_00103c30(3, 0xff, 3, 0);
                FUN_0010a4e0(0, 7, 3, 0);
                FUN_003182d0(((u32*)D_008717F0_abs)[(s8)FUN_00453480() * 0x70], 0, 2, 0, 0);
                FUN_0045a430(true);
                FUN_003c8f70();
                FUN_003c8f20();
                fldEvent->eventType = 5;
            }
            break;

        case 5:
            if (FUN_001a93d0((KwlnTask*)FIELD_WORD(0x11f4), -1) > 4)
            {
                FUN_002ff260(false);
                fldEvent->eventType = 9;
            }
            break;

        case 6:
            FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
            FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
            FUN_004532d0(true);
            FUN_004350e0(false, true);
            FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
            FUN_003189f0(0.0f, *(u32*)D_008717F0_abs, 0);
            case6Marker = ((RwMatrix*)FUN_00318b60(PTR_U32(EVENT_WORD(9), 0x50)))->pos;
            case6Marker.y += 50.0f;
            if (FUN_0017d800() == true)
            {
                case6UpVec = *(RwV3d*)0x00683740;
                taskResult = FUN_001a91b0((KwlnTask*)FIELD_WORD(0x1214), &case6Marker);
                case6MatBuf = *(RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
                case6MatBuf.pos.x = 0.0f;
                case6MatBuf.pos.y = 0.0f;
                case6MatBuf.pos.z = 0.0f;
                RwMatrixRotate(&case6MatBuf, &case6UpVec, 180.0f, rwCOMBINEPOSTCONCAT);
                case6MatBuf.pos = case6UpVec;
                FUN_001a9330((KwlnTask*)FIELD_WORD(0x1214), taskResult, &case6MatBuf);
                FUN_001a9390((KwlnTask*)FIELD_WORD(0x1214), taskResult, 3);
            }
            else
            {
                FUN_001a9390((KwlnTask*)FIELD_WORD(0x11f4), FUN_001a91b0((KwlnTask*)FIELD_WORD(0x11f4), &case6Marker), 3);
            }
            FUN_0010a4e0(0, 7, 3, 0);
            FUN_003182d0(PTR_U32(EVENT_WORD(9), 0x50), 0, 2, 0, 0);
            FUN_0045a430(true);
            FUN_003c8f70();
            FUN_003c8f20();
            fldEvent->eventType = 7;
            break;

        case 7:
            if ((FUN_0017d800() == true && FUN_001a93d0((KwlnTask*)FIELD_WORD(0x1214), -1) >= 4) ||
                (FUN_0017d800() != true && FUN_001a93d0((KwlnTask*)FIELD_WORD(0x11f4), -1) >= 5))
            {
                FUN_003189f0(1.0f, *(u32*)D_008717F0_abs, 0);
                FUN_002ff260(false);
                fldEvent->eventType = 9;
            }
            break;

        case 8:
        {
            RwMatrix case8FldHitMat;
            RwV3d case8FldHitLine[2];

            currentActor = (s32)FUN_00318990(*(u32*)D_008717F0_abs, 0);
            heroMat = (RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
            case8Offset = heroMat->at;
            if (currentActor < PTR_S16((void*)EVENT_WORD(0x40), 4))
            {
                offset.x = -case8Offset.x; offset.y = -case8Offset.y; offset.z = -case8Offset.z;
                RwV3dNormalize(&offset, &offset);
                RwV3dScale(&offset, &offset, (f32)EVENT_WORD(0x43));
                FUN_00318a30(*(u32*)D_008717F0_abs, &offset, 2);
            }
            if (currentActor > PTR_S16((void*)EVENT_WORD(0x40), 6))
            {
                RwV3dNormalize(&case8Offset, &case8Offset);
                RwV3dScale(&case8Offset, &case8Offset, (f32)EVENT_WORD(0x44));
                FUN_00318a30(*(u32*)D_008717F0_abs, &case8Offset, 2);
            }
            if (FUN_0017d800() == true && EVENT_WORD(0x3a) == 0 && currentActor > 20)
            {
                FUN_0010a4e0(1, 9, 2, 0xc);
                EVENT_WORD(0x3a) = true;
                if (FUN_00318d10(PTR_U32((void*)*(u32*)D_008717F0_abs, 0x3b8), 300, &markerPos) != 0)
                {
                    FUN_001a9330((KwlnTask*)FIELD_WORD(0x1210), FUN_001a91b0((KwlnTask*)FIELD_WORD(0x1210), &markerPos), &markerPos);
                }
            }
            if (FUN_0017d800() == true &&
                currentActor == PTR_S32((void*)EVENT_WORD(0x100), 0x0c) + 5)
            {
                case8FldHitMat = *(RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
                offset = case8FldHitMat.pos;
                case8Offset = case8FldHitMat.at;
                RwV3dNormalize(&case8Offset, &case8Offset);
                case8Offset.x *= *(f32*)((u8*)EVENT_WORD(0x100) + 0x14) - 50.0f;
                case8Offset.y *= *(f32*)((u8*)EVENT_WORD(0x100) + 0x14) - 50.0f;
                case8Offset.z *= *(f32*)((u8*)EVENT_WORD(0x100) + 0x14) - 50.0f;
                offset.x += case8Offset.x;
                offset.y += case8Offset.y;
                offset.z += case8Offset.z;
                case8FldHitLine[0] = case8FldHitMat.pos;
                case8FldHitLine[1] = offset;
                case8FldHitLine[0].y += 300.0f;
                case8FldHitLine[1].y += 300.0f;
                if (K_FldFrame_Raycast(case8FldHitLine, &markerPos) == false)
                {
                    case8FldHitLine[1] = offset;
                    case8FldHitLine[0] = case8FldHitLine[1];
                    case8FldHitLine[0].y += 1000.0f;
                    case8FldHitLine[1].y -= 1000.0f;
                    if (K_FldFrame_Raycast(case8FldHitLine, &markerPos) == true)
                    {
                        offset.y = markerPos.y;
                    }
                }
                taskResult = FUN_001a91b0((KwlnTask*)FIELD_WORD(0x1218), &offset);
                FUN_001a9390((KwlnTask*)FIELD_WORD(0x1218), taskResult, 3);
            }
            if (currentActor >= PTR_S32((void*)EVENT_WORD(0x40), 0xc) &&
                currentActor < PTR_S32((void*)EVENT_WORD(0x40), 0xc) + 5 && FUN_004352e0() == false)
            {
                model = (s32)func_001c6a20(
                    &gFldUnitsPc[FLDUNIT_PC_HERO],
                    *(f32*)((u8*)EVENT_WORD(0x40) + 0x14),
                    *(f32*)((u8*)EVENT_WORD(0x40) + 0x10));
                EVENT_WORD(9) = (model != 0 && FUN_002ff790(PTR_U32((void*)model, 0x48)) != true) ? model : 0;
                if (EVENT_WORD(9) != 0)
                {
                    if (DATA_U32(0x007ce210) == 0)
                    {
                        FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                        FUN_004532d0(true);
                        FUN_004350e0(false, true);
                        FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                        FUN_001c7830(&EVENT_WORD(10), EVENT_WORD(9));
                        if (FUN_004353f0(EVENT_WORD(9)) == 3 || FUN_004353f0(EVENT_WORD(9)) == 5) EVENT_U16(0x28) |= 2;
                        if (FUN_001d8d80(EVENT_WORD(9)) != 0) EVENT_U16(0x28) |= 4;
                        if (func_001c65e0((const FldUnit*)EVENT_WORD(9)) == 0) EVENT_U16(0x28) |= 8;
                        FUN_001d5c10((KwlnTask*)FIELD_WORD(0x04), EVENT_WORD(0x3d));
                        if (FUN_0017d800() == true) FUN_003189f0(1.0f, *(u32*)D_008717F0_abs, 0);
                        fldEvent->eventType = 6;
                    }
                    else
                    {
                        heroMat = (RwMatrix*)FUN_00318b60(PTR_U32((void*)EVENT_WORD(9), 0x50));
                        markerPos = heroMat->pos;
                        markerPos.y += 50.0f;
                        FUN_0010a4e0(1, 8, 2, 8);
                        FUN_001a91b0((KwlnTask*)FIELD_WORD(0x1204), &markerPos);
                        FUN_001d0110(EVENT_WORD(9));
case8_teardown:
                        if (FUN_0017d800() == true) FUN_003189f0(1.0f, *(u32*)D_008717F0_abs, 0);
                        FUN_003182d0(*(u32*)D_008717F0_abs, 0, FUN_001dde00(true), EVENT_WORD(0x3b) == 6 ? 0 : 4, true);
                        FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), false);
                        FUN_001d8c60(false);
                        FUN_001d5c10((KwlnTask*)FIELD_WORD(0x04), EVENT_WORD(0x3d));
                        if (FIELD_WORD(0x18) != 0) FUN_00429e90((void*)FIELD_WORD(0x18), false);
                        fldEvent->eventType = FLDEVENT_TYPE_IDLE;
                    }
                    break;
                }
            }
            currentArea = FUN_00453460();
            if (currentArea < 0 && currentActor >= PTR_S16((void*)EVENT_WORD(0x40), 2))
            {
                heroMat->pos.x = *(f32*)((u8*)fldEvent + 0x114);
                heroMat->pos.y = *(f32*)((u8*)fldEvent + 0x118);
                heroMat->pos.z = *(f32*)((u8*)fldEvent + 0x11c);
                goto case8_teardown;
            }
            else if (currentArea >= 0)
            {
                EVENT_WORD(9) = 0x0086eda0 + FUN_00453460() * 0x1c0;
                if (FUN_002ff790(PTR_U32(EVENT_WORD(9), 0x48)) != true)
                {
                    FUN_001c7830(&EVENT_WORD(10), EVENT_WORD(9));
                    EVENT_U16(0x28) |= 1 | 2;
                    if (PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x12) == 0 &&
                        PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x14) == 0)
                    {
                        EVENT_S16(0x40) = (s16)gMtScene->fldMajorId + 200;
                        EVENT_U16(0x42) = 1;
                    }
                    else
                    {
                        EVENT_S16(0x40) = PTR_S16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x12);
                        EVENT_U16(0x42) = PTR_U16((void*)PTR_U32(EVENT_WORD(9), 0x4c), 0x14);
                    }
                    FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), true);
                    FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), true);
                    FUN_004532d0(true);
                    FUN_004350e0(false, true);
                    FUN_001da000((KwlnTask*)FIELD_WORD(0x20), true);
                    FUN_003182d0(PTR_U32(EVENT_WORD(9), 0x50), 0, 3, 0, 0);
                    FUN_001d5c10((KwlnTask*)FIELD_WORD(0x04), EVENT_WORD(0x3d));
                    if (FUN_0017d800() == true) FUN_003189f0(1.0f, *(u32*)D_008717F0_abs, 0);
                    fldEvent->eventType = 4;
                }
            }
            break;

            }
        case 9:
            if (FUN_002ff310() == true && func_001d00b0() == true)
            {
                FUN_001c00d0();
                func_001cd790((KwlnTask*)EVENT_WORD(0x17), false);
                if (FIELD_WORD(0x1c) != 0) { FUN_00195020(FIELD_WORD(0x1c)); FIELD_WORD(0x1c) = 0; }
                if (FIELD_WORD(0x18) != 0) { FUN_00195020(FIELD_WORD(0x18)); FIELD_WORD(0x18) = 0; }
                if (FIELD_WORD(0x28) != 0) { FUN_00195020(FIELD_WORD(0x28)); FIELD_WORD(0x28) = 0; }
                if (FIELD_WORD(0x0c) != 0) { FUN_00195020(FIELD_WORD(0x0c)); FIELD_WORD(0x0c) = 0; }
                if (FIELD_WORD(0x04) != 0)
                {
                    FUN_001d68e0(eventStack.eventData, (void*)FIELD_WORD(0x04));
                    {
                        u_long128* dataSrc = eventStack.eventData;
                        u_long128* dataDst = (u_long128*)&EVENT_WORD(0x20);
                        s32 copyCount = 3;
                        do
                        {
                            u_long128 data0 = *dataSrc++;
                            u_long128 data1 = *dataSrc++;
                            copyCount--;
                            *dataDst++ = data0;
                            *dataDst++ = data1;
                        } while (copyCount > 0);
                        }
                    FUN_00195020(FIELD_WORD(0x04));
                    FIELD_WORD(0x04) = 0;
                }
                FUN_001e7410();
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), false);
                FUN_001d4180();
                FUN_00455b50();
                func_001ce880();
                FUN_001d1780(true);
                FUN_001d17f0(true);
                FUN_001d8cf0();
                FUN_001c07f0();
                if (FUN_001a0250() == true || FUN_001a02c0() == true)
                {
                    for (i = 0; i < 9; i++)
                    {
                        if (((u32*)0x0086bdc0)[i] != 0)
                        {
                            FUN_001b3c90(((u32*)0x0086bdc0)[i]);
                            ((u32*)0x0086bdc0)[i] = 0;
                        }
                    }
                }
                FUN_003b5ab0();
                FUN_00350080(2);
                fldEvent->eventType++;
            }
            break;

        case 10:
        case 11:
        case 12:
        case 13:
            fldEvent->eventType++;
            break;

        case 0x0e:
            currentActor = PTR_S16((void*)EVENT_WORD(0x0f), 8);
            if (currentActor == 0x1d5) FUN_0016f1f0(0xdf9, false);
            else if (currentActor == 0x1d4) FUN_0016f1f0(0xdf8, false);
            else if (currentActor == 0x1d3) FUN_0016f1f0(0xdf7, false);
            else if (currentActor == 0x1d2) FUN_0016f1f0(0xdf6, false);
            if (FIELD_WORD(0x10d4) != 0)
            {
                for (i = 0; i < 4; i++)
                {
                    if (FIELD_WORD(0x10d4 + i * 4) != 0)
                    {
                        FUN_00195020(FIELD_WORD(0x10d4 + i * 4));
                        FIELD_WORD(0x10d4 + i * 4) = 0;
                    }
                }
                for (i = 0; i < 0x18; i++)
                {
                    if (FIELD_WORD(0x10e4 + i * 4) != 0)
                    {
                        FUN_00195020(FIELD_WORD(0x10e4 + i * 4));
                        FIELD_WORD(0x10e4 + i * 4) = 0;
                    }
                }
            }
            EVENT_WORD(0x19) = FUN_0027d1d0(&EVENT_WORD(10));
            fldEvent->eventType = 0x0f;
            break;

        case 0x0f:
            if (FUN_00195460(EVENT_WORD(0x19)) != true && FUN_001b08d0() == true && FUN_001b09b0() == true)
            {
                FUN_001b0870(K_Field_GetMajorId((KwlnTask*)FIELD_WORD(0)), K_Field_GetMinorId((KwlnTask*)FIELD_WORD(0)));
                if (FUN_0045af40() == 0)
                {
                    FUN_001b0920();
                    FUN_001b09f0();
                    FUN_00109f60(3, 0);
                    FUN_003952d0(0, 0x87, 3);
                    (&D_007CE274)[2] = 0;
                    if (EVENT_WORD(0x18) != 0) FUN_00195020(EVENT_WORD(0x18));
                    FUN_0016f1f0(0x141d, true);
                    fldEvent->eventType = 0x1e;
                }
                else
                {
                    if (FUN_0045af40() > 0) { FUN_0045a430(false); FUN_0045af70(false); }
                    if (PTR_S16((void*)EVENT_WORD(0x0f), 8) != 0x1fa) { FUN_001d0110(EVENT_WORD(9)); EVENT_WORD(9) = 0; }
                    if (FUN_002ff790(*(u32*)D_008717E8_abs) == true)
                    {
                        FUN_0045a400();
                        FUN_001b0920();
                        FUN_001b09f0();
                        EVENT_WORD(0x18) = FUN_0035bc00(10, gFldScrMemory, gFldScrSize, 1);
                        FUN_0016f1f0(0x141d, true);
                        fldEvent->eventType = 0x1f;
                    }
                    else
                    {
                        for (i = 1; i < 4; i++)
                        {
                            if (((u32*)0x008717e8)[i * 0x70] != 0 && FUN_002ff790(((u32*)0x008717e8)[i * 0x70]) == true && FUN_0016f190(0xc21) == true)
                            {
                                FUN_0016cf40(*(u16*)((u8*)0x00871948 + i * 0x1c0));
                                FUN_0016d9d0(*(u16*)((u8*)0x00871948 + i * 0x1c0), 0x80000);
                            }
                        }
                        FUN_001c03f0();
                        FUN_001d11b0();
                        EVENT_WORD(0x19) = 0;
                        fldEvent->eventType = 0x10;
                    }
                }
            }
            break;

        case 0x10:
            if (FUN_001b08d0() != false)
            {
                currentActor = K_Field_GetMajorId((KwlnTask*)FIELD_WORD(0));
                taskResult = K_Field_GetMinorId((KwlnTask*)FIELD_WORD(0));
                EVENT_WORD(0x1b) =
                    taskResult == -1
                        ? false
                        : FUN_001b0910() == false
                              ? (FUN_00523ac8(scriptPath, 0x006836f0, taskResult, currentActor),
                                 FUN_001008b0(scriptPath) == false
                                     ? false
                                     : FUN_00100d80(scriptPath, false))
                              : true;
                EVENT_WORD(0x1c) = FUN_001e7200(K_Field_GetMinorId((KwlnTask*)FIELD_WORD(0)));
                FIELD_WORD(0x38) |= 0x80000000;
                FUN_003b5760(K_Field_GetMinorId((KwlnTask*)FIELD_WORD(0)),
                             K_Field_GetMajorId((KwlnTask*)FIELD_WORD(0)));
                FUN_003b58c0((s16)FUN_001bab40((KwlnTask*)FIELD_WORD(0)));
                FUN_003b5980((s16)FUN_001bab50((KwlnTask*)FIELD_WORD(0)));
                fldEvent->eventType = 0x11;
            }
            break;

        case 0x11:
            if (FUN_001c7f20(EVENT_WORD(0x1b)) != false)
            {
                EVENT_WORD(0x1b) = 0;
                if (FUN_001e7290(EVENT_WORD(0x1c), K_Field_GetMajorId((KwlnTask*)FIELD_WORD(0))) != false &&
                    FUN_001c0440() != false && FUN_001c0740() != false && FUN_001d12d0() != false && FUN_003b5a10() != false)
                {
                    EVENT_WORD(0x1c) = 0;
                    if (FUN_001dd600() == true) FIELD_WORD(0x28) = (u32)func_0018bff0(fldEventTask);
                    fldEvent->eventType = 0x12;
                }
            }
            break;

        case 0x12:
            if (FUN_001dd600() == true && func_0018c0a0((void*)FIELD_WORD(0x28)) == false) break;
            FUN_00453470(-1);
            FUN_001c8120(&EVENT_WORD(10));
            K_Field_GetMajorId((KwlnTask*)FIELD_WORD(0));
            K_Field_GetMinorId((KwlnTask*)FIELD_WORD(0));
            FUN_001d1360();
            if (FUN_0016f190(0x1411) == true) { FUN_001d38d0((KwlnTask*)FIELD_WORD(0x24), 2); FUN_0016f1f0(0x1411, false); }
            if (EVENT_WORD(9) != 0) { if (FUN_002ff790(EVENT_WORD(0x0f)) == false) FUN_001d39c0((KwlnTask*)FIELD_WORD(0x24)); FUN_001d0110(EVENT_WORD(9)); }
            FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), false);
            FUN_004532d0(false);
            FUN_004350e0(false, false);
            FUN_001da000((KwlnTask*)FIELD_WORD(0x20), false);
            FUN_001d2610();
            FUN_001d2210();
            FUN_001d2a10();
            if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), true);
            FIELD_WORD(4) = FUN_001d5a90((KwlnTask*)FIELD_WORD(0));
            FUN_001d69e0((KwlnTask*)FIELD_WORD(4), &EVENT_WORD(0x20));
            FUN_001d5f30((KwlnTask*)FIELD_WORD(4), *(u32*)D_008717F4_abs);
            if (FUN_001a01c0() == true) FIELD_WORD(0x18) = FUN_00429d40(fldEventTask, *(u64*)(uintptr_t)0x007cc2b0);
            FIELD_WORD(0x1054) = func_0010a770(fldEventTask, 2, 0, 2, 0x1ea, 1);
            fldEvent->eventType = 0x13;
            break;

        case 0x13:
            if (FIELD_WORD(0x18) == 0 || FUN_0042ba30() != false)
            {
                if (FIELD_WORD(0x1054) != 0)
                {
                    if (FUN_0010a720(FIELD_WORD(0x1054)) == false) break;
                    FIELD_WORD(0x1054) = 0;
                }
                FUN_001d5f30((KwlnTask*)FIELD_WORD(4), *(u32*)D_008717F4_abs);
                if (FUN_001a01c0() == true && FIELD_WORD(0x14) == 0) FUN_00429e80((void*)FIELD_WORD(0x18), true);
                FIELD_WORD(0x0c) = FUN_001e1230((KwlnTask*)FIELD_WORD(0), PTR_U32((void*)*(u32*)D_008717F4_abs, 0xf0), *(u32*)D_008717F0_abs);
                FIELD_WORD(0x1c) = (u32)FUN_001c1f30((KwlnTask*)FIELD_WORD(0), (KwlnTask*)PTR_U32((void*)*(u32*)D_008717F4_abs, 0xf0));
                EVENT_WORD(5) = FUN_003b5d10(0x400);
                FUN_001a9850();
                if (gMtScene->fldMajorId == 0x1f)
                {
                    if (FUN_0016f190(0xe39) != false)
                    {
                        FUN_003952d0(0, 0x2cf, 3);
                    }
                    else
                    {
                        FUN_003952d0(0, 0x2d0, 3);
                    }
                }
                FUN_001c0110();
                FUN_004533e0(true);
                FUN_001085c0();
                fldEvent->eventType = 0x14;
            }
            break;

        case 0x14:
            if (FUN_00108710() != false) { EVENT_WORD(0x3e) = 0x96; fldEvent->eventType = FLDEVENT_TYPE_IDLE; }
            break;

        case 0x15:
            FUN_003c7b90();
            currentActor = gMtScene->fldMajorId;
            if (currentActor != 7 && currentActor != 4)
            {
            }
            else if (currentActor == 7 && EVENT_WORD(8) >= 4)
            {
            }
            else if (PTR_U8((void*)PTR_U32((void*)EVENT_WORD(7), 0x128), 0xee) != 1)
            {
            }
            else if (EVENT_WORD(8) == (s16)FUN_00318540(PTR_U32((void*)EVENT_WORD(7), 0x128), 0))
            {
            }
            else
            {
                FUN_003182d0(PTR_U32((void*)EVENT_WORD(7), 0x128), 0, (s16)EVENT_WORD(8), 7, true);
                FUN_005225a8(0x00683750, (s16)FUN_00318540(PTR_U32((void*)EVENT_WORD(7), 0x128), 0));
            }
            if (FUN_003c7850() == false)
            {
                FUN_003c7700();
                FUN_003c77a0();
                currentActor = gMtScene->fldMajorId;
                if (currentActor != 7 && currentActor != 4)
                {
                }
                else if (currentActor == 7 && EVENT_WORD(8) >= 4)
                {
                }
                else if (EVENT_WORD(8) == (s16)FUN_00318540(PTR_U32((void*)EVENT_WORD(7), 0x128), 0))
                {
                }
                else
                {
                    FUN_003182d0(PTR_U32((void*)EVENT_WORD(7), 0x128), 0, (s16)EVENT_WORD(8), 0x10, true);
                }
                if (EVENT_WORD(7) != 0 && PTR_U32((void*)EVENT_WORD(7), 0x210) != 0) FUN_001dd5e0((void*)PTR_U32((void*)EVENT_WORD(7), 0x210), true);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), false);
                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), false);
                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), true);
                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), true);
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), true);
                EVENT_WORD(0x3f) = 10;
                fldEvent->eventType = FLDEVENT_TYPE_IDLE;
            }
            break;

        case 0x16:
            currentActor = gMtScene->fldMajorId;
            if (currentActor == 7 || currentActor == 4)
            {
                if (currentActor == 7 && EVENT_WORD(8) < 4) goto case16_first_action;
                if (currentActor != 4) goto case16_first_action_done;
                if (EVENT_WORD(8) >= 4) goto case16_first_action_done;
            }
case16_first_action:
            if (PTR_U8((void*)PTR_U32((void*)EVENT_WORD(7), 0x128), 0xee) != 1)
            {
            }
            else if (EVENT_WORD(8) == (s16)FUN_00318540(PTR_U32((void*)EVENT_WORD(7), 0x128), 0))
            {
            }
            else
            {
                FUN_003182d0(PTR_U32((void*)EVENT_WORD(7), 0x128), 0, (s16)EVENT_WORD(8), 7, true);
            }
case16_first_action_done:
            if (FUN_00195460(EVENT_WORD(0x18)) != true)
            {
                currentActor = gMtScene->fldMajorId;
                if (currentActor == 7 || currentActor == 4)
                {
                    if (currentActor == 7 && EVENT_WORD(8) < 4) goto case16_second_action;
                    if (currentActor != 4) goto case16_second_action_done;
                    if (EVENT_WORD(8) >= 4) goto case16_second_action_done;
                }
case16_second_action:
                if (EVENT_WORD(8) == (s16)FUN_00318540(PTR_U32((void*)EVENT_WORD(7), 0x128), 0))
                {
                }
                else
                {
                    FUN_003182d0(PTR_U32((void*)EVENT_WORD(7), 0x128), 0, (s16)EVENT_WORD(8), 0x10, true);
                }
case16_second_action_done:
                if (EVENT_WORD(7) != 0 && PTR_U32((void*)EVENT_WORD(7), 0x210) != 0) FUN_001dd5e0((void*)PTR_U32((void*)EVENT_WORD(7), 0x210), true);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), false);
                FUN_001e1300((KwlnTask*)FIELD_WORD(0x0c), false);
                EVENT_WORD(0x18) = 0;
                if (FIELD_WORD(0x18) != 0) FUN_00429e80((void*)FIELD_WORD(0x18), true);
                if (FIELD_WORD(0x28) != 0) func_0018c0c0((void*)FIELD_WORD(0x28), true);
                if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), true);
                EVENT_WORD(0x3f) = 10;
                fldEvent->eventType = FLDEVENT_TYPE_IDLE;
            }
            break;

        case 0x17:
            if (FUN_001d1a90() != false && FUN_001d1ce0() != false && func_001d00b0() != false)
            {
                FUN_001956d0((void*)FIELD_WORD(0x1c), 0x20, 2);
                FUN_001956d0((void*)FIELD_WORD(4), 0x20, 2);
                FUN_00455b50();
                FUN_001d1780(true);
                FUN_001d17f0(false);
                EVENT_WORD(0x3b) = FUN_00308c60(PTR_U32((void*)*(u32*)D_008717E8_abs, 4)) & 0xff;
                EVENT_WORD(0x3c) = FUN_0016f630(true, FUN_0016cb80(true, true)) & 0xffff;
                EVENT_WORD(0x1a) = FUN_0011a770(fldEventTask);
                fldEvent->eventType = 0x18;
            }
            break;

        case 0x18:
            if (FUN_00195460(EVENT_WORD(0x1a)) != true)
            {
                if (FUN_0016f190(0x1417) == true)
                {
                    FUN_0016f1f0(0x1417, false);
                    EVENT_WORD(0x18) = FUN_0035bb40(10, gFldScrMemory, 3);
                    fldEvent->eventType = 0x1c;
                }
                else
                {
                    currentArea = FUN_00308c60(PTR_U32((void*)*(u32*)D_008717E8_abs, 4)) & 0xff;
                    currentActor = FUN_0016f630(true, FUN_0016cb80(true, true));
                    active = EVENT_WORD(0x3b) != currentArea;
                    if (active == false)
                    {
                        if (currentActor == 0x439)
                        {
                            if (EVENT_WORD(0x3c) != 0x439) active = true;
                        }
                        else if (EVENT_WORD(0x3c) == 0x439) active = true;
                        if (active == false)
                        {
                            if (currentActor == 0x452)
                            {
                                if (EVENT_WORD(0x3c) != 0x452) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x452) active = true;
                        }
                        if (active == false)
                        {
                            if (currentActor == 0x453)
                            {
                                if (EVENT_WORD(0x3c) != 0x453) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x453) active = true;
                        }
                        if (active == false)
                        {
                            if (currentActor == 0x40e)
                            {
                                if (EVENT_WORD(0x3c) != 0x40e) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x40e) active = true;
                        }
                        if (active == false)
                        {
                            if (currentActor == 0x466)
                            {
                                if (EVENT_WORD(0x3c) != 0x466) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x466) active = true;
                        }
                        if (active == false)
                        {
                            if (currentActor == 0x43d)
                            {
                                if (EVENT_WORD(0x3c) != 0x43d) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x43d) active = true;
                        }
                        if (active == false)
                        {
                            if (currentActor == 0x464)
                            {
                                if (EVENT_WORD(0x3c) != 0x464) active = true;
                            }
                            else if (EVENT_WORD(0x3c) == 0x464) active = true;
                        }
                    }
                    if (active == false)
                    {
                        for (i = 0; i < 5; i++) FUN_003196f0(*(u32*)D_008717F0_abs, i);
                        FUN_004c43b0();
                        FUN_0031c1d0(*(u32*)D_008717F0_abs);
                    }
                    else
                    {
                        FUN_001cd870(false);
                        FUN_004c43b0();
                        *(u32*)D_008717F0_abs = FUN_001cd9a0(true);
                    }
                    fldEvent->eventType = 0x19;
                }
            }
            break;

        case 0x19:
            allLoaded = FUN_00316f70(*(u32*)D_008717F0_abs);
            if (allLoaded != 0)
            {
                for (i = 0; i < 5 && allLoaded != 0; i++) allLoaded = FUN_00319770(*(u32*)D_008717F0_abs, i);
                if (allLoaded != 0)
                {
                    if (FUN_001dd600() == true) FIELD_WORD(0x28) = (u32)func_0018bff0(fldEventTask);
                    if (FIELD_WORD(0x2c) != 0) func_0018eb30((void*)FIELD_WORD(0x2c), true);
                    if ((gMtScene->fldMajorId == 0x20 && gMtScene->fldMinorId == 2) ||
                        (gMtScene->fldMajorId == 0x27 && (gMtScene->fldMinorId == 1 || gMtScene->fldMinorId == 3))) FUN_0030c440();
                    fldEvent->eventType = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (FUN_001dd600() == true && func_0018c0a0((void*)FIELD_WORD(0x28)) == false) break;
            FUN_001d0e50(true);
            FUN_001d19d0();
            if (FUN_001dd600() == true) FUN_001dd8e0();
            FUN_001d1360();
            FUN_001d1c20();
            FUN_001d37f0((KwlnTask*)FIELD_WORD(0x24), false);
            if (FUN_001a01c0() == true) FIELD_WORD(0x18) = FUN_00429d40(fldEventTask, *(u64*)(uintptr_t)0x007cc2b8);
            fldEvent->eventType = 0x1b;
            break;

        case 0x1b:
            if (func_001ce960() != false && func_001d00b0() != false && FUN_001d1a90() != false && FUN_001d1ce0() != false &&
                (FIELD_WORD(0x18) == 0 || FUN_0042ba30() != false))
            {
                EVENT_WORD(5) = FUN_003b5d10(0x400);
                FUN_001c2000((void*)FIELD_WORD(0x1c), PTR_U32((void*)*(u32*)D_008717F4_abs, 0xf0));
                FUN_00195710((void*)FIELD_WORD(0x1c), 0x20, 2);
                FUN_001d5f30((KwlnTask*)FIELD_WORD(4), *(u32*)D_008717F4_abs);
                FUN_00195710((void*)FIELD_WORD(4), 0x20, 2);
                FUN_001d1860(false);
                if (FIELD_WORD(0x18) != 0 && FIELD_WORD(0x14) == 0) FUN_00429e80((void*)FIELD_WORD(0x18), true);
                FUN_0045a430(false);
                FUN_0045af70(false);
                FIELD_WORD(0x0c) = FUN_001e1230((KwlnTask*)FIELD_WORD(0), PTR_U32((void*)*(u32*)D_008717F4_abs, 0xf0), *(u32*)D_008717F0_abs);
                K_FldEvent_001cd650((KwlnTask*)FIELD_WORD(0x08), false);
                FUN_004532d0(false);
                FUN_004350e0(false, false);
                FUN_001da000((KwlnTask*)FIELD_WORD(0x20), false);
                fldEvent->eventType = FLDEVENT_TYPE_IDLE;
            }
            break;

        case 0x1c:
            FUN_00195460(EVENT_WORD(0x18));
            break;

        case 0x1d:
            if (FUN_00108710() != false)
            {
                FUN_0045a400();
                EVENT_WORD(0x18) = FUN_0035bc00(10, gFldScrMemory, gFldScrSize, true);
                fldEvent->eventType = 0x1f;
            }
            break;

        case 0x1e:
            if ((&D_007CE274)[2] < 0x5a)
            {
                FUN_0045a400();
                (&D_007CE274)[2]++;
            }
            else
            {
                EVENT_WORD(0x18) = FUN_0035bc00(10, gFldScrMemory, gFldScrSize, true);
                fldEvent->eventType = 0x1f;
            }
            break;
        case 0x1f:
            break;
        case 0x20:
            /* Retail offset 0x4e60 returns -1 without entering the common completion path. */
            return (void*)-1;
    }
    
    /* Retail offsets 0x4e6c-0x4f0c use the completion flag at event offset 0xe0. */
    if (EVENT_WORD(0xe0) == 1)
    {
        heroMat = (RwMatrix*)FUN_00318b60(*(u32*)D_008717F0_abs);
        markerPos = heroMat->pos;
        markerPos.y += 200.0f;
        if (*(u32*)D_00871914_abs != 0)
        {
            FUN_001dd530((void*)*(u32*)D_00871914_abs, &markerPos);
            FUN_001dd5e0((void*)*(u32*)D_00871914_abs, true);
        }
    }
    else if (*(u32*)D_00871914_abs != 0)
    {
        FUN_001dd5e0((void*)*(u32*)D_00871914_abs, false);
    }

#undef EVENT_WORD
#undef EVENT_S16
#undef EVENT_U16
#undef EVENT_U8
#undef FIELD_WORD
#undef FIELD_U16
#undef DATA_U8
#undef DATA_U16
#undef DATA_U32
#undef DATA_S32
#undef PTR_U32
#undef PTR_S16
#undef PTR_U16
#undef PTR_U8
#undef HIT_DATA_PTR

    return KWLNTASK_CONTINUE;
}

// FUN_001cd570
void K_FldEvent_DestroyFldEventTask(KwlnTask* fldEventTask)
{
    RwFree(fldEventTask->workData);
}

// FUN_001cd5a0. Create 'field event' and 'draw command' tasks
KwlnTask* K_FldEvent_CreateTasks(KwlnTask* fldRootTask)
{
    KwlnTask* fldEventTask;
    FldEvent* fldEvent;

    fldEvent = (FldEvent*)RwCalloc(1, sizeof(FldEvent), rwMEMHINTDUR_GLOBAL);
    if (fldEvent == NULL)
    {
        return NULL;
    }

    fldEventTask = kwlnTaskCreateWithAutoPriority(fldRootTask, 10, "field event", K_FldEvent_UpdateFldEventTask, K_FldEvent_DestroyFldEventTask, fldEvent);
    
    fldEvent->drawCmdTask = K_FldEvent_CreateDrawCmdTask(fldEventTask);

    return fldEventTask;
}

// FUN_001cd650
void K_FldEvent_001cd650(KwlnTask* fldEventTask, u32 param_2)
{
    if (fldEventTask != NULL)
    {
        ((u32*)fldEventTask->workData)[1] = param_2;
    }
}

// FUN_001cd670
void K_FldEvent_001cd670(KwlnTask* fldEventTask, u32 param_2)
{
    if (fldEventTask != NULL)
    {
        ((u32*)fldEventTask->workData)[2] = param_2;
    }
}

// FUN_001cd690
void* K_FldEvent_UpdateDrawCmdTask(KwlnTask* drawCmdTask)
{
    FUN_003b2cb0(0.0f, 0x140, 0xe0, -1, 0, 0, *(u32*)drawCmdTask->workData, 0, 0);

    return KWLNTASK_CONTINUE;
}

// FUN_001cd6e0
void K_FldEvent_DestroyDrawCmdTask(KwlnTask* drawCmdTask)
{
    RwFree(drawCmdTask->workData);
}

// FUN_001cd710
KwlnTask* K_FldEvent_CreateDrawCmdTask(KwlnTask* fldEventTask)
{
    FldDrawCmd* drawCmd;

    drawCmd = (FldDrawCmd*)RwCalloc(1, sizeof(FldDrawCmd), rwMEMHINTDUR_GLOBAL);
    if (drawCmd == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreateWithAutoPriority(fldEventTask, 4207, "draw command", K_FldEvent_UpdateDrawCmdTask, K_FldEvent_DestroyDrawCmdTask, drawCmd);
}


// FUN_001cd790
void func_001cd790(KwlnTask* task, u32 value)
{
    *(u32*)task->workData = value;
}

 
 





static void FldUnit_ClearPcMdlSlot(s32 index)
{
    if (gFldUnitsPcMdl[index].mdl != NULL)
    {
        mdlDestroy(gFldUnitsPcMdl[index].mdl);
        gFldUnitsPcMdl[index].mdl = NULL;
        gFldUnitsPcMdl[index].type = 0;
        gFldUnitsPcMdl[index].id = 0;
    }
}

// FUN_001CD7A0
void func_001cd7a0(void)
{
    memset(gFldUnitsPcMdl, 0, sizeof(gFldUnitsPcMdl));
    memset(gFldUnitsPc, 0, sizeof(gFldUnitsPc));
    memset(gFldUnitsEc, 0, sizeof(gFldUnitsEc));
    sFldUnitsEcCount = 0;
    memset(DAT_0086e580, 0, 0x118);
    memset(DAT_0086be80, 0, 0x2700);
    DAT_007ce288 = 0;
    DAT_007ce284 = 0;
    memset(DAT_0086bdc0, 0, 0x40);
    DAT_007ce280 = 0;
    memset(DAT_0086b180, 0, 0xc40);
}

/* Removing this loses FUN_001cd8e0 (MATCH nd0 -> MISMATCH nd82) - measured W161. */


static inline void* FldUnit_LoadPcModel(s32 slot, u16 type, u16 id)
{
    Model* model;

    model = NULL;
    if (gFldUnitsPcMdl[slot].type == type)
    {
        if (gFldUnitsPcMdl[slot].id == id)
        {
            model = gFldUnitsPcMdl[slot].mdl;
        }
    }
    if (model == NULL)
    {
        model = (Model*)func_00316e00(type, id, 0);
        if (type == 1)
        {
            func_0031c1d0(model);
        }
        if (gFldUnitsPcMdl[slot].mdl != NULL)
        {
            func_003174e0(gFldUnitsPcMdl[slot].mdl);
            gFldUnitsPcMdl[slot].mdl = NULL;
        }
        gFldUnitsPcMdl[slot].mdl = model;
        gFldUnitsPcMdl[slot].type = model->type;
        gFldUnitsPcMdl[slot].id = gFldUnitsPcMdl[slot].mdl->id;
    }
    else
    {
        func_00319190(model);
    }
    return model;
}

// Retail offsets 0x21c-0x464 expand the scenario dispatch; offsets 0x684-0xedc re-fetch each PC model cache field per case.
// The remaining register coloring/layout differences are intentionally NONMATCHING.
// Measured opt_loop_invariants on: nd2603 -> 2599, object 3784/3808; retained (under window).
// Measured opt_propagation off: nd2599 -> 2592, object 3800/3808; stacked opt_loop_invariants on + opt_propagation off: nd2599 -> 2592, object 3800/3808; retained (under window).
#pragma opt_propagation on
#pragma opt_loop_invariants off




/* Removing this worsens FUN_001ce960 (nd2894 -> nd3129) - measured W161. */








static u8* FldUnit_FindModelNode(u16 id)
{
    u8* node;

    node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_14);
    while (node != NULL && ((*(u16*)node & 0x3ff) != id))
    {
        node = *(u8**)(node + 0x1f0);
    }
    return node;
}

static void FldUnit_InitPcUnit(FldUnit* unit, u16 charId, u8* modelNode)
{
    unit->genusBase = (DatUnitGenusBase*)datUnitCreatePc(charId);
    unit->mdl = (Model*)func_001cd9a0(charId);
    unit->charId = charId;
    unit->unk_44 = 0;
    unit->unk_184 = datPersonaGetLevelByPcId(charId) & 0xff;
    unit->unk_168 = modelNode;
    if (charId == 1)
    {
        unit->unk_188 = datGetLevel(1) & 0xff;
        unit->unk_174 = (KwlnTask*)func_001dd460(0, 0, 0x106f);
    }
    else
    {
        unit->scrCdvd = (HCdvd*)func_00100d80(
            s__field_script_reserve_xxx_006837af + charId * 0x20 + 1, 0);
    }
}

// Measured opt_common_subs off: nd506 -> 418, object 812/816; retained (under window).
#pragma opt_common_subs reset


static inline RwV3d* FldUnit_NodePos(u8* node)
{
    return &((FldUnitNode*)node)->pos;
}

static inline f32 FldUnit_NodeDistance(const RwV3d* a, const RwV3d* b)
{
    RwV3d delta;

    delta.x = a->x - b->x;
    delta.y = a->y - b->y;
    delta.z = a->z - b->z;
    return RwV3dLength_y2(&delta);
}


/* Removing this worsens FUN_001d0880 (nd485 -> nd512) - measured W161. */


// Measured opt_loop_invariants on: nd491 -> 418, object 804/864; retained (under window).


/* Removing this worsens FUN_001d1360 (nd448 -> nd516) - measured W161. */













/* Removing this worsens FUN_001d2300 (nd502 -> nd511) - measured W161. */

static inline s32 FldUnit_GridCoord(f32 value)
{
    s32 cell;

    cell = (s32)((s32)(value + 400.0f) / 800);
    if (cell < 0)
    {
        return (cell + 3) >> 2;
    }
    return cell >> 2;
}

// Measured opt_dead_assignments off: nd1517 -> 1499, object 2116/2192; retained (under window).

// Measured opt_lifetimes on: nd425 -> 424, object 1024/1056; stacked opt_loop_invariants on + opt_lifetimes on: nd425 -> 424, object 1024/1056; retained (under window).
/* Removing this worsens FUN_001d32a0 (nd588 -> nd637) - measured W161. */
















// Address-expression probe floor: retained nd7 form; typed byte/base-local and postTask shapes measured worse (nd23, nd62-64, nd171). Residuals are offsets 164/168 (task load/branch register) and 196/200 (clear-address addu/reload versus retail base addu/addiu).
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
