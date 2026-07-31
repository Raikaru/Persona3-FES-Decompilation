#include "Kosaka/Field/k_enemy.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "temporary.h"




// FUN_001d4360
HCdvd* K_FldEnemy_RequestTable(void)
{
    char buffer[128];

    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        sprintf(buffer, "field/table/enemy.bin");
    }
    else
    {
        sprintf(buffer, "field/table/enemy_aegis.bin");
    }

    if (H_Cdvd_FileExists(buffer))
    {
        return H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }
    // Retail falls through with H_Cdvd_FileExists' false (zero) result in the return register.
}

#include "Kosaka/Field/k_unit.h"
#include "Kosaka/k_misc.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_encount.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Scene/resrcManager.h"
#include "Scene/mt_scene.h"
#include "Battle/battle.h"
#include "Main/Battle/Data/datUnit.h"
 
 

extern void func_001956d0(void* resource, u32 flags, u32 value);
extern void* DAT_0096017c[];
extern void* DAT_00960184[];
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
extern u8* DAT_007ce294;
extern u8 DAT_0086be80[0x2700];
extern void* DAT_0086b180[0x310];
extern u8 DAT_0086e580[0x114];
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
extern u8* func_001b9120(void);
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
extern u16 func_003b6030(u32 id, u32 mode, void* model);
extern u16 func_003b65d0(u16 id, void* table);
extern void* func_003b5d10(u16 resourceId);
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
extern f32 RwV3dLength(const RwV3d* value);
extern u32 func_00488f30(void);
extern void* func_00431670(u32 parent, s32 index, void* unit);
extern void* func_0044ad20(u32 parent, s32 index);
extern void func_00434f60();
extern void func_00452010(RwV3d* value);
extern f32 func_004c6ac0(const RwV3d* value);
extern void func_004cb420(u64 left, u64 right);
extern f32 func_0052e878(f32 value);
extern u32 func_00523ac8(char* buffer, const char* path, ...);
extern void func_0019d400(const char* file, s32 line, s32 value);
extern void func_00521250(void* dst, const void* src, u32 size);
extern u32 func_001008b0(const char* path);
extern void* func_00100d80(const char* path, u32 mode);
extern void func_00100ec0(void* object);
extern void func_001023a0(void* object);
extern u32 func_001016b0(void);
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
extern void* func_00316e00(u32 type, u32 id, u32 mode);
extern u32 func_001c65e0(FldUnit* unit);
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
extern void K_Abort(const char* message, const char* file, s32 line);
extern void K_Assert(const char* file, s32 line);

FldUnitMdl gFldUnitsPcMdl[FLDUNIT_PC_MAX]; // 00871ea0
FldUnit gFldUnitsPc[FLDUNIT_PC_MAX];       // 008717a0

FldUnit gFldUnitsEc[FLDUNIT_EC_MAX];  // 0086eda0. Enemies
static u32 sFldUnitsEcCount;          // 007ce28c

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

typedef struct FldUnitNode
{
    Resrc base;
    RwV3d pos;
} FldUnitNode;

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
    return RwV3dLength(&delta);
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

// FUN_001d43e0
u32 func_001d43e0(void* object)
{
    HCdvd* cdvd;
    u32 fileSize;
    void* fileMemory;

    if (func_001016b0() == 0)
    {
        return 0;
    }
    cdvd = (HCdvd*)object;
    DAT_007ce290 = DAT_00871ec0;
    fileSize = ((volatile /* Removing this function's qualifier batch loses func_001d43e0 (MATCH nd0 -> MISMATCH nd4, size 120 -> 120) - measured W170. */ HCdvd*)cdvd)->fileSize;
    fileMemory = ((volatile /* Removing this function's qualifier batch loses func_001d43e0 (MATCH nd0 -> MISMATCH nd4, size 120 -> 120) - measured W170. */ HCdvd*)cdvd)->fileMemory;
    func_00521250(DAT_00871ec0, fileMemory, fileSize);
    DAT_007ce294 = DAT_007ce290 + 0x180;
    func_00100ec0(cdvd);
    return 1;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
