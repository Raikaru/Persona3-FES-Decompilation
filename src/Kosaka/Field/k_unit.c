#include "Kosaka/Field/k_unit.h"
#include "Kosaka/k_misc.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_encount.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Scene/resrcManager.h"
#include "Scene/mt_scene.h"
#include "Battle/battle.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datUnit.h"
 
#include "h_cdvd.h"
 

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
#pragma opt_loop_invariants on

// FUN_001CD8E0
void func_001cd8e0(void)
{
    s32 i;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        gFldUnitsPc[i].unk_44 = 1;
        gFldUnitsPcMdl[i].mdl = NULL;
        gFldUnitsPcMdl[i].type = 0;
        gFldUnitsPcMdl[i].id = 0;
    }
}
#pragma opt_loop_invariants off

// FUN_001cd870
void K_FldUnit_DestroyPcMdl(s32 unitId)
{
    if (gFldUnitsPcMdl[unitId].mdl != NULL)
    {
        mdlDestroy(gFldUnitsPcMdl[unitId].mdl);
        
        gFldUnitsPcMdl[unitId].mdl = NULL;
        gFldUnitsPcMdl[unitId].type = 0;
        gFldUnitsPcMdl[unitId].id = 0;
    }
}

// FUN_001cd940
FldUnit* K_FldUnit_FindFreePc()
{
    FldUnit* units;
    FldUnit* free;
    FldUnit* curr;
    s32 i;

    free = NULL;
    i = 0;
    units = gFldUnitsPc;
    for (; i < FLDUNIT_PC_MAX; i++)
    {
        curr = &units[i];
        if (curr->genusBase == NULL)
        {
            free = curr;
            break;
        }
    }

    return free;
}

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
// FUN_001cd9a0 NONMATCHING
void* func_001cd9a0(u32 charId)
{
    s32 i;
    s32 slot;

    slot = 0;
    for (i = 0; i < 3; i++)
    {
        if ((u32)(u16)datGetPartyId(i) == (u16)charId)
        {
            slot = i + 1;
            break;
        }
    }

    switch (charId)
    {
    case 1:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (func_0017d800() == true &&
            (PTR_DAT_007cd540[0] == 4 || PTR_DAT_007cd540[0] == 5))
        {
            type = 9;
            id = 0x1400;
        }
        else if (func_001a0310() == true)
        {
            type = 9;
            id = 0x104;
        }
        else if ((PTR_DAT_007cd540[0] == 7 &&
                  PTR_DAT_007cd540[1] == 6 &&
                  (func_0016ef30() & 0xff) == 8) ||
                 (PTR_DAT_007cd540[0] == 8 &&
                  PTR_DAT_007cd540[1] == 1 &&
                  (func_0016ef30() & 0xff) == 8) ||
                 (PTR_DAT_007cd540[0] == 9 &&
                  PTR_DAT_007cd540[1] == 1 &&
                  (func_0016ef30() & 0xff) == 8))
        {
            type = 9;
            id = 0x104;
        }
        else if (PTR_DAT_007cd540[0] == 33)
        {
            type = 9;
            id = 0x106;
        }
        else if (func_001a01c0() == true ||
                 (PTR_DAT_007cd540[0] == 21 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 22 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 22 && PTR_DAT_007cd540[1] == 51) ||
                 (PTR_DAT_007cd540[0] == 23 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 23 && PTR_DAT_007cd540[1] == 51) ||
                 (PTR_DAT_007cd540[0] == 24 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 24 && PTR_DAT_007cd540[1] == 51) ||
                 (PTR_DAT_007cd540[0] == 25 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 26 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 27 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 41 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 42 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 43 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 44 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 45 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 46 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 47 && PTR_DAT_007cd540[1] == 50) ||
                 (PTR_DAT_007cd540[0] == 39 && PTR_DAT_007cd540[1] == 1) ||
                 (PTR_DAT_007cd540[0] == 39 && PTR_DAT_007cd540[1] == 2) ||
                 (PTR_DAT_007cd540[0] == 39 && PTR_DAT_007cd540[1] == 3))
        {
            type = 1;
            id = 1;
        }
        else if (PTR_DAT_007cd540[0] == 7 && func_0016f190(0xe00) == true)
        {
            type = 9;
            id = 0x105;
        }
        else if (PTR_DAT_007cd540[0] == 6 && func_0016f190(0xe60) == true)
        {
            type = 9;
            id = 0x104;
        }
        else if (PTR_DAT_007cd540[0] == 14 && PTR_DAT_007cd540[1] == 5)
        {
            type = 9;
            id = 0x107;
        }
        else if (PTR_DAT_007cd540[0] == 14 &&
                 func_0016ef30() == 6 &&
                 ((func_0017d920() == 11 && func_0017da40() == 18) ||
                  (func_0017d920() == 11 && func_0017da40() == 19)))
        {
            type = 9;
            id = 0x108;
        }
        else if (func_0016f190(0xa89) == true)
        {
            type = 9;
            if (func_0017e480(6, 1, 9, 0x1e) == true)
            {
                id = 0x103;
            }
            else
            {
                id = 0x102;
            }
        }
        else
        {
            type = 9;
            if (func_0017e480(6, 1, 9, 0x1e) == true)
            {
                id = 0x101;
            }
            else
            {
                id = 0x100;
            }
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    case 2:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (PTR_DAT_007cd540[0] == 6 || PTR_DAT_007cd540[0] == 7)
        {
            type = 9;
            id = 0x200;
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    case 5:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (PTR_DAT_007cd540[0] == 14 && PTR_DAT_007cd540[1] == 5)
        {
            type = 9;
            id = 0x502;
        }
        else if (func_0016f190(0xc2f) == true)
        {
            type = 9;
            id = 0x500;
        }
        else if (PTR_DAT_007cd540[0] == 33)
        {
            type = 9;
            id = 0x501;
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    case 7:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (PTR_DAT_007cd540[0] == 14 && PTR_DAT_007cd540[1] == 5)
        {
            type = 9;
            id = 0x700;
        }
        else if (PTR_DAT_007cd540[0] == 33)
        {
            type = 9;
            id = 0x701;
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    case 10:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (PTR_DAT_007cd540[0] == 14 && PTR_DAT_007cd540[1] == 5)
        {
            type = 9;
            id = 0xd00;
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    case 13:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        if (PTR_DAT_007cd540[0] == 14 && PTR_DAT_007cd540[1] == 5)
        {
            type = 9;
            id = 0xd00;
        }
        return FldUnit_LoadPcModel(slot, type, id);
        }
    default:
        {
            u16 type = 1;
            u16 id = (u16)charId;
        return FldUnit_LoadPcModel(slot, type, id);
        }
    }
}

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

// FUN_001CE880 NONMATCHING
void func_001ce880(void)
{
    s32 i;
    s32 j;
    s32 hasResources;
    FldUnit* unit;
    Model* model;
    Model* weapon;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        hasResources = false;
        unit = &gFldUnitsPc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            hasResources = true;
        }
        hasResources = (hasResources != 0);
        if (hasResources)
        {
            for (j = 0; j < 5; j++)
            {
                model = unit->mdl;
                weapon = model->attachedWpns[j].wpnMdl;
                if (weapon != NULL)
                {
                    func_00319230(weapon,
                                  *(u16*)((u8*)unit + 0x19e + j * sizeof(u16)));
                }
            }
        }
    }
}

/* Removing this worsens FUN_001ce960 (nd2894 -> nd3129) - measured W161. */
#pragma opt_loop_invariants on
// Retail offsets 0x000-0x2f0 re-fetch gFldUnitsPc fields; 0x478-0x4b0 and 0x8d8-0x930 copy matrices inline; 0x52c-0x79c and 0x9d8-0xe44 expand formation/dungeon dispatches.
// FUN_001CE960 NONMATCHING
u32 func_001ce960(void)
{
    s32 i;
    s32 j;
    s32 partyCount;
    s32 orientation;
    u16 resourceId;
    u8* field;
    u8* cell;
    u8 partyPositions[0x330];
    FldUnit* unit;
    ResrcModelChar* resource;
    HCdvd* cdvd;
    RwMatrix* reference;
    RwV3d fieldPosition;
    RwV3d scale;
    RwV3d fixedPosition;
    RwV3d axis;
    void* (*allocate)(u32 count, u32 size, u32 flags);
    Model* weapon;

    axis = DAT_00683910;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        if (gFldUnitsPc[i].genusBase == NULL ||
            gFldUnitsPc[i].resrc != NULL)
        {
            continue;
        }
        if (func_00316f70(gFldUnitsPc[i].mdl) == false)
        {
            return false;
        }
        for (j = 0; j < 5; j++)
        {
            if (func_00319770(gFldUnitsPc[i].mdl, (u16)j) == false)
            {
                return false;
            }
        }
        if (gFldUnitsPc[i].scrCdvd == NULL)
        {
            continue;
        }
        if (H_Cdvd_IsFileLoaded(gFldUnitsPc[i].scrCdvd) == false)
        {
            return false;
        }
        allocate = (void* (*)(u32, u32, u32))DAT_00960184[0];
        gFldUnitsPc[i].unk_1b4 =
            allocate(1, gFldUnitsPc[i].scrCdvd->fileSize, 0x40000);
        *(u32*)((u8*)&gFldUnitsPc[i] + 0x1b8) =
            gFldUnitsPc[i].scrCdvd->fileSize;
        memcpy(gFldUnitsPc[i].unk_1b4,
               gFldUnitsPc[i].scrCdvd->fileMemory,
               gFldUnitsPc[i].scrCdvd->fileSize);
        H_Cdvd_Destroy(gFldUnitsPc[i].scrCdvd);
        gFldUnitsPc[i].scrCdvd = NULL;
        for (j = 0; j < 5; j++)
        {
            weapon = *(Model**)((u8*)gFldUnitsPc[i].mdl + 0x3b8 + j * 0xc);
            if (weapon != NULL)
            {
                *(u16*)((u8*)&gFldUnitsPc[i] + 0x19e + j * sizeof(u16)) =
                    *(u16*)((u8*)weapon + 0x418);
                func_00319230(
                    *(Model**)((u8*)gFldUnitsPc[i].mdl + 0x3b8 + j * 0xc),
                    3);
            }
        }
    }

    reference = (RwMatrix*)func_004c38c0();
    if (reference == NULL)
    {
        return false;
    }
    fixedPosition = DAT_00683920;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        if (gFldUnitsPc[i].genusBase == NULL ||
            gFldUnitsPc[i].resrc != NULL)
        {
            continue;
        }
        resourceId = func_003b6030((u32)i, 1, gFldUnitsPc[i].mdl);
        gFldUnitsPc[i].resrc =
            (ResrcModelChar*)func_003b5d10(resourceId);
        if (gFldUnitsPc[i].resrc == NULL)
        {
            return false;
        }
        if (i == 0)
        {
            func_001ad8c0(60.0f, gFldUnitsPc[i].resrc->collisCtlTask);
        }
        else
        {
            func_001ad8c0(35.0f, gFldUnitsPc[i].resrc->collisCtlTask);
        }
        gFldUnitsPc[i].resrc->baseMdl =
            (Model*)func_00317450(uGpffffb52c);
        scale.x = func_001ad8b0(gFldUnitsPc[i].resrc->collisCtlTask);
        scale.y = scale.x;
        scale.z = scale.x;
        func_00318a90(gFldUnitsPc[i].resrc->baseMdl, &scale, 2);
        func_004cb420(func_00318b70(gFldUnitsPc[i].mdl),
                      func_00318b70(gFldUnitsPc[i].resrc->baseMdl));
        func_00317730(gFldUnitsPc[i].resrc->baseMdl);

        if (K_Scene_001a0250() == 1)
        {
            field = func_001b9120();
            fieldPosition.x = (f32)(u8)field[0x3c] * 72.0f;
            fieldPosition.y = 2.0f;
            field = func_001b9120();
            fieldPosition.z = (f32)(u8)field[0x3d] * 72.0f;
            field = (u8*)mdlGetMatrix(gFldUnitsPc[0].resrc->mdl);
            cell = (u8*)reference;
            for (j = 0; j < 8; j++)
            {
                *(f32*)cell = *(f32*)field;
                *(f32*)(cell + 4) = *(f32*)(field + 4);
                field += 8;
                cell += 8;
            }
            field = func_001b9120();
            orientation = (u8)field[0x3d] << 8;
            field = func_001b9120();
            orientation += (u8)field[0x3c] << 4;
            cell = func_001b9120();
            orientation = (u8)cell[orientation + 0x4e] + 2;
            orientation &= ~3;
            func_001adff0(gFldUnitsPc[i].resrc->collisCtlTask,
                          &axis, (f32)orientation * 90.0f);
            if (func_001c0040() == 4)
            {
                if (i == 0)
                {
                    func_001adc20(gFldUnitsPc[i].resrc->collisCtlTask,
                                  &fieldPosition);
                }
                else
                {
                    partyCount = 0;
                    for (j = 0; j < 3; j++)
                    {
                        if (datGetPartyId(j) > 0)
                        {
                            partyCount++;
                        }
                    }
                    func_001d0bc0(partyPositions, (u32)partyCount);
                    func_001adc20(
                        gFldUnitsPc[i].resrc->collisCtlTask,
                        (const RwV3d*)(partyPositions +
                            (i - 1) * 0x110 + 0x190));
                }
            }
            else
            {
                switch (i)
                {
                case 0:
                    func_001adc20(gFldUnitsPc[i].resrc->collisCtlTask,
                                  &fieldPosition);
                    break;
                case 1:
                    {
                        RwV3d position;
                        RwV3d offset;
                        position = reference->pos;
                        offset = reference->right;
                        RwV3dNormalize(&offset, &offset);
                        position.x += offset.x * 120.0f;
                        position.y += offset.y * 120.0f;
                        position.z += offset.z * 120.0f;
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                case 2:
                    {
                        RwV3d position;
                        RwV3d offset;
                        position = reference->pos;
                        offset = reference->right;
                        RwV3dNormalize(&offset, &offset);
                        offset.x = -offset.x;
                        offset.y = -offset.y;
                        offset.z = -offset.z;
                        position.x += offset.x * 120.0f;
                        position.y += offset.y * 120.0f;
                        position.z += offset.z * 120.0f;
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                case 3:
                    {
                        RwV3d position;
                        RwV3d offset;
                        position = reference->pos;
                        offset = reference->at;
                        RwV3dNormalize(&offset, &offset);
                        offset.x = -offset.x;
                        offset.y = -offset.y;
                        offset.z = -offset.z;
                        position.x += offset.x * 150.0f;
                        position.y += offset.y * 150.0f;
                        position.z += offset.z * 150.0f;
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                }
            }
        }
        else
        {
            if (gFldUnitsPc[i].unk_168 == NULL)
            {
                func_001adc20(gFldUnitsPc[i].resrc->collisCtlTask,
                              &fixedPosition);
                RwMatrixUpdate(mdlGetMatrix(gFldUnitsPc[i].mdl));
                func_003182d0(
                    gFldUnitsPc[i].mdl, 0,
                    (u32)func_001dde00(gFldUnitsPc[i].charId), 0, 1);
            }
            else
            {
                field = (u8*)mdlGetMatrix(gFldUnitsPc[0].resrc->mdl);
                cell = (u8*)reference;
                for (j = 0; j < 8; j++)
                {
                    *(f32*)cell = *(f32*)field;
                    *(f32*)(cell + 4) = *(f32*)(field + 4);
                    field += 8;
                    cell += 8;
                }
                if (func_002ff790(gFldUnitsPc[i].genusBase) == false)
                {
                    func_003182d0(
                        gFldUnitsPc[i].mdl, 0,
                        (u32)func_001dde00(gFldUnitsPc[i].charId), 0, 1);
                }
                else
                {
                    func_003182d0(gFldUnitsPc[i].mdl, 0, 0x15, 0, 0);
                    func_00318770(
                        gFldUnitsPc[i].mdl, 0,
                        func_00318910(gFldUnitsPc[i].mdl, 0, 0x15) - 10.0f);
                }
                switch (i)
                {
                case 0:
                    func_001adff0(
                        gFldUnitsPc[i].resrc->collisCtlTask, &axis,
                        *(f32*)((u8*)gFldUnitsPc[i].unk_168 + 0x10c));
                    func_001adc20(
                        gFldUnitsPc[i].resrc->collisCtlTask,
                        (const RwV3d*)((u8*)gFldUnitsPc[i].unk_168 + 0x100));
                    break;
                case 1:
                    {
                        RwV3d position;
                        RwV3d offset;
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
                        func_001adff0(
                            gFldUnitsPc[i].resrc->collisCtlTask, &axis,
                            *(f32*)((u8*)gFldUnitsPc[i].unk_168 + 0x10c));
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                case 2:
                    {
                        RwV3d position;
                        RwV3d offset;
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
                        func_001adff0(
                            gFldUnitsPc[i].resrc->collisCtlTask, &axis,
                            *(f32*)((u8*)gFldUnitsPc[i].unk_168 + 0x10c));
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                case 3:
                    {
                        RwV3d position;
                        RwV3d offset;
                        position = reference->pos;
                        offset = reference->at;
                        RwV3dNormalize(&offset, &offset);
                        offset.x = -offset.x;
                        offset.y = -offset.y;
                        offset.z = -offset.z;
                        position.x += offset.x * 150.0f;
                        position.y += offset.y * 150.0f;
                        position.z += offset.z * 150.0f;
                        func_001adff0(
                            gFldUnitsPc[i].resrc->collisCtlTask, &axis,
                            *(f32*)((u8*)gFldUnitsPc[i].unk_168 + 0x10c));
                        func_001adc20(
                            gFldUnitsPc[i].resrc->collisCtlTask, &position);
                    }
                    break;
                }
            }
            func_001a01c0();
        }

        if (i != 0)
        {
            gFldUnitsPc[i].unk_170 =
                (KwlnTask*)func_001af930(0, gFldUnitsPc[i].resrc);
            gFldUnitsPc[i].unk_16c =
                (KwlnTask*)func_00431670(0, i, &gFldUnitsPc[i]);
        }
        gFldUnitsPc[i].unk_180 =
            func_001d40e0(NULL, &gFldUnitsPc[i]);
        RwMatrixUpdate(mdlGetMatrix(gFldUnitsPc[i].mdl));
        func_001a0dc0(resourceId, 1);
        func_001ad870(gFldUnitsPc[i].resrc->collisCtlTask,
                      0x40000000);
    }
    if ((PTR_DAT_007cd540[0] == 0xE && PTR_DAT_007cd540[1] == 5) ||
        K_Scene_001a0250() == 1)
    {
        func_00434f60(0);
    }
    else
    {
        func_00434f60();
    }
    if (func_001c0040() == 4)
    {
        func_004350e0(0, 1);
    }
    func_004c3880(reference);
    return true;
}
#pragma opt_loop_invariants off
// FUN_001CF940 NONMATCHING
FldUnit* func_001cf940(u32 encounter, void* unitData)
{
    s32 i;
    s32 count;
    s32 levelSum;
    u16 enemyId;
    u16 tier;
    FldUnit* unit;
    FldUnit* current;
    DatUnitEc* enemy;
    const u8* spawn;
    char message[0x100];

    unit = NULL;
    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        current = &gFldUnitsEc[i];
        if (current->genusBase == NULL)
        {
            unit = current;
            break;
        }
    }
    if (unit == NULL)
    {
        return NULL;
    }

    enemyId = (u16)encounter;
    enemy = datUnitCreateEc(enemyId);
    unit->genusBase = (DatUnitGenusBase*)enemy;
    unit->encount = &gEncountTbl[enemyId];
    unit->charId = 0;
    count = enemy->base.count;
    if (count >= 4)
    {
        unit->scaleIdx = 3;
    }
    else if (count >= 2)
    {
        unit->scaleIdx = 2;
    }
    else if (count == 1)
    {
        unit->scaleIdx = 1;
    }

    tier = (u16)(encounter >> 16);
    if (tier == 4)
    {
        unit->unk_18c = 3;
    }
    else if (tier == 2)
    {
        unit->unk_18c = 2;
    }
    else if (tier == 1)
    {
        if (PTR_DAT_007cd540[0] == 0x33 && PTR_DAT_007cd540[1] == 1)
        {
            unit->unk_18c = 5;
        }
        else
        {
            unit->unk_18c = 1;
        }
    }
    else
    {
        func_00523ac8(message, D_00683930, encounter);
        func_0019d400(D_00683940, 0x430, 0);
        unit->unk_18c = 1;
    }

    unit->mdl = mdlCreateAndResolvePath(MODEL_TYPE_FLDCHAR,
                                        enemyId, MDL_READASYNC);
    spawn = (const u8*)unitData;
    memcpy((u8*)unit + 0x58, spawn, 0x110);
    unit->unk_168 = &unit->unk_58;
    unit->xGrid = (s16)((*(const f32*)(spawn + 0x100) + 400.0f) /
                        800.0f);
    unit->zGrid = (s16)((*(const f32*)(spawn + 0x108) + 400.0f) /
                        800.0f);

    levelSum = 0;
    for (i = 0; i < count; i++)
    {
        levelSum += enemy->units[i].level;
    }
    if (count != 0)
    {
        unit->unk_184 = levelSum / count;
    }
    if (unit->unk_18c == 3)
    {
        unit->unk_184 = 1000;
    }
    sFldUnitsEcCount++;
    return unit;
}

// FUN_001CFDD0 NONMATCHING
u32 func_001cfdd0(u32 index)
{
    FldUnit* unit;
    ResrcModelChar* resource;
    u16 resourceId;
    RwV3d axis;
    Model* baseModel;

    unit = &gFldUnitsEc[index];
    if (unit->genusBase == NULL || unit->resrc != NULL)
    {
        return true;
    }
    if (func_00316f70(unit->mdl) == false)
    {
        return false;
    }

    resourceId = func_003b6030((u32)index + 100, 0, unit->mdl);
    resource = (ResrcModelChar*)func_003b5d10(resourceId);
    unit->resrc = resource;
    if (resource == NULL)
    {
        return false;
    }
    mdlAnimSet(unit->mdl, 0, 0, 0, MDLANIM_FLAG_LOOP);
    func_00318a90(unit->mdl, &DAT_00683780[unit->scaleIdx], 2);
    RwMatrixUpdate(mdlGetMatrix(unit->mdl));

    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    func_001adff0(resource->collisCtlTask, &axis,
                  *(f32*)((u8*)unit->unk_168 + 0x10c));
    func_001adc20(resource->collisCtlTask,
                  (const RwV3d*)((u8*)unit->unk_168 + 0x100));
    func_001a0dc0(resourceId, 1);
    func_001ad870(resource->collisCtlTask, 0x40000000);
    func_001ad8c0(35.0f, resource->collisCtlTask);

    baseModel = (Model*)func_00317450(uGpffffb52c);
    resource->baseMdl = baseModel;
    {
        RwV3d scale;
        f32 radius;

        radius = func_001ad8b0(resource->collisCtlTask);
        scale.x = radius;
        scale.y = radius;
        scale.z = radius;
        func_00318a90(baseModel, &scale, 2);
    }
    func_004cb420(func_00318b70(unit->mdl),
                  func_00318b70(resource->baseMdl));
    func_00317730(resource->baseMdl);
    unit->unk_170 = (KwlnTask*)func_001af930(0, resource);
    unit->unk_16c = (KwlnTask*)func_0044ad20(0, (s32)(s8)index);
    if (unit->unk_18c == 2)
    {
        unit->unk_178 = func_001d3c40(
            NULL, *(u32*)((u8*)resource->mdl + 0x128));
    }
    if (func_001c65e0(unit) == false)
    {
        unit->unk_174 = (KwlnTask*)func_001dd460(0, 5, 0x1058);
        func_001dd5f0(unit->unk_174, unit->mdl);
        func_001dd5e0(unit->unk_174, 1);
    }
    return true;
}

// FUN_001D00B0
u32 func_001d00b0(void)
{
    s32 i;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        if (func_001cfdd0((u32)i) == false)
        {
            return false;
        }
    }
    return true;
}

// FUN_001cfc50
FldUnit* K_FldUnit_CreateReaper(u32 unused, const RwV3d* spawnPos)
{
    FldUnit* units;
    FldUnit* curr;
    FldUnit* unit;
    s32 i;

    unit = NULL;
    i = 0;
    units = gFldUnitsEc;
    for (; i < FLDUNIT_EC_MAX; i++)
    {
        curr = &units[i];
        if (curr->genusBase == NULL)
        {
            unit = curr;
            break;
        }
    }

    if (datGetFlag(5141) == true)
    {
        return NULL;
    }
    else if (unit == NULL)
    {
        return NULL;
    }

    unit->genusBase = (DatUnitGenusBase*)datUnitCreateEc(BTLENCOUNT_REAPER);
    unit->encount = &gEncountTbl[BTLENCOUNT_REAPER];
    unit->unk_18c = 4;
    unit->scaleIdx = 0;
    unit->charId = 0;
    unit->mdl = mdlCreateAndResolvePath(MODEL_TYPE_ENEMYSYMBOL, 3, MDL_READASYNC);
    unit->spawnPos = *spawnPos;
    unit->unk_168 = &unit->unk_58;
    unit->xGrid = (spawnPos->x + 400.0f) / 800.0f;
    unit->zGrid = (spawnPos->z + 400.0f) / 800.0f;
    unit->unk_184 = 1000;

    sFldUnitsEcCount++;

    return unit;
}

// FUN_001d0110
void K_FldUnit_Destroy(FldUnit* unit)
{
    if (unit->genusBase == NULL)
    {
        return;
    }

    datUnitDestroyGenus(unit->genusBase);

    if (unit->resrc != NULL)
    {
        func_003b7090(unit->resrc->base.resTypeId);
    }

    if (unit->mdl != NULL)
    {
        if (unit->charId == 0 || unit->unk_44 == 1)
        {
            K_Misc_CreateDelayMdlFreeTask(unit->mdl);
        }
    }

    if (unit->unk_16c != NULL)
    {
        kwlnTaskDestroyWithHierarchy(unit->unk_16c);
    }
    if (unit->unk_170 != NULL)
    {
        kwlnTaskDestroyWithHierarchy(unit->unk_170);
    }
    if (unit->unk_1b4 != NULL)
    {
        ((void (*)(void*))DAT_0096017c[0])(unit->unk_1b4);
    }
    if (unit->unk_174 != NULL)
    {
        kwlnTaskDestroyWithHierarchy(unit->unk_174);
    }
    if (unit->unk_178 != NULL)
    {
        kwlnTaskDestroyWithHierarchy(unit->unk_178);
    }
    if (unit->unk_180 != NULL)
    {
        kwlnTaskDestroyWithHierarchy(unit->unk_180);
    }

    unit->genusBase = NULL;
    unit->mdl = NULL;
    unit->resrc = NULL;
    unit->unk_16c = NULL;
    unit->unk_170 = NULL;
    unit->unk_1b4 = NULL;
    unit->unk_174 = NULL;
    unit->unk_178 = NULL;
    unit->unk_180 = NULL;

    if (unit->unk_18c != 0)
    {
        sFldUnitsEcCount--;
    }

    memset((u8*)unit + 0x198, 0, 5);
    func_001d2a10();
}

// FUN_001d0270
void func_001d0270(void)
{
    s32 i;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        if (*(void**)((u8*)gFldUnitsPc + i * sizeof(FldUnit) + 0x16c) != NULL)
        {
            func_001956d0(*(void**)((u8*)gFldUnitsPc + i * sizeof(FldUnit) + 0x16c),
                          0x20, 0);
        }
    }
    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        if (*(void**)((u8*)gFldUnitsEc + i * sizeof(FldUnit) + 0x16c) != NULL)
        {
            func_001956d0(*(void**)((u8*)gFldUnitsEc + i * sizeof(FldUnit) + 0x16c),
                          0x20, 0);
        }
    }
}

// FUN_001d0330
void K_FldUnit_DestroyAllPc()
{
    s32 i;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        K_FldUnit_Destroy(&gFldUnitsPc[i]);
    }
}

// FUN_001d0390
void K_FldUnit_DestroyAllEc()
{
    s32 i;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        K_FldUnit_Destroy(&gFldUnitsEc[i]);
    }
}

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

/* Removing this worsens FUN_001d03f0 (nd506 -> nd517) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001d03f0 NONMATCHING
void func_001d03f0(u16 charId)
{
    u8* modelNode;
    FldUnit* unit;
    u8* cache;
    Model* cachedModel;
    s32 i;
    s16 pcId;
    u32 sceneMode;

    modelNode = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_14);
    if (modelNode != NULL || (charId & 0xffff) != 0xffff)
    {
        while (modelNode != NULL &&
               ((*(u16*)modelNode & 0x3ff) != (charId & 0xffff)))
        {
            modelNode = *(u8**)(modelNode + 0xf8);
        }
    }

    unit = K_FldUnit_FindFreePc();
    if (unit != NULL)
    {
        unit->genusBase = (DatUnitGenusBase*)datUnitCreatePc(1);
        unit->mdl = (Model*)func_001cd9a0(1);
        unit->charId = 1;
        unit->unk_44 = 0;
        unit->unk_184 = datPersonaGetLevelByPcId(1) & 0xff;
        unit->unk_188 = datGetLevel(1) & 0xff;
        unit->unk_174 = (KwlnTask*)func_001dd460(0, 0, 0x106f);
        unit->unk_168 = modelNode;
    }

    sceneMode = func_001a0310();
    if (sceneMode == 1 ||
        (PTR_DAT_007cd540[0] == 8 && PTR_DAT_007cd540[1] == 3))
    {
        for (i = 0; i < 3; i++)
        {
            cache = (u8*)gFldUnitsPcMdl + i * 8;
            cachedModel = *(Model**)(cache + 0xc);
            if (cachedModel != NULL)
            {
                mdlDestroy(cachedModel);
                *(Model**)(cache + 0xc) = NULL;
                *(u16*)(cache + 8) = 0;
                *(u16*)(cache + 0xa) = 0;
            }
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            pcId = (s16)datGetPartyId(i);
            if (pcId > 0)
            {
                if ((datGetBadStatusNoDown(pcId) & 0x80000) != 0 &&
                    datGetFlag(0xc21) == 1)
                {
                    datSetHp(pcId, 1);
                    datClearBadStatus(pcId, 0x80000);
                }
                unit = K_FldUnit_FindFreePc();
                if (unit != NULL)
                {
                    unit->genusBase = (DatUnitGenusBase*)datUnitCreatePc(
                        (u16)pcId);
                    unit->mdl = (Model*)func_001cd9a0((u16)pcId);
                    unit->charId = (u16)pcId;
                    unit->unk_44 = 0;
                    unit->unk_184 =
                        datPersonaGetLevelByPcId((u16)pcId) & 0xff;
                    if (pcId == 1)
                    {
                        unit->unk_188 = datGetLevel(pcId) & 0xff;
                        unit->unk_174 =
                            (KwlnTask*)func_001dd460(0, 0, 0x106f);
                    }
                    else
                    {
                        unit->scrCdvd = (HCdvd*)func_00100d80(
                            s__field_script_reserve_xxx_006837af +
                                (u16)pcId * 0x20 + 1,
                            0);
                    }
                    unit->unk_168 = modelNode;
                }
            }
            else
            {
                cache = (u8*)gFldUnitsPcMdl + i * 8;
                cachedModel = *(Model**)(cache + 0xc);
                if (cachedModel != NULL)
                {
                    mdlDestroy(cachedModel);
                    *(Model**)(cache + 0xc) = NULL;
                    *(u16*)(cache + 8) = 0;
                    *(u16*)(cache + 0xa) = 0;
                }
            }
        }
    }
}
#pragma opt_loop_invariants off

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

// FUN_001d0720 NONMATCHING
s32 func_001d0720(s32 targetCount)
{
    s32 spawned;
    s32 major;
    u16* values;
    u16 gridId;
    u32 area;
    u8* entry;
    s32* ptr;

    spawned = 0;
    if (datGetFlag(0x1415) == 1)
    {
        return spawned;
    }
    ptr = (s32*)PTR_DAT_007cd540;
    major = ptr[0];
    if (major >= 0x14)
    {
        if (major >= 0x1d)
        {
            if (major < 0x28)
            {
                goto spawn;
            }
            if (major >= 0x31)
            {
                goto spawn;
            }
        }
        if (ptr[1] != 0)
        {
            goto done;
        }
    }

spawn:
    values = (u16*)PTR_DAT_007cd540;
    while ((entry = (u8*)func_001d0880(spawned, targetCount)) != NULL)
    {
        gridId = func_001bff20();
        area = func_001d7300(values[0], values[2], gridId);
        if (values[0] == 0x33 && values[2] == 1)
        {
            area = ((u32)spawned + 0x1d2) | 0x10000;
        }
        if ((area & 0xffff) == 0xffff)
        {
            K_Assert(D_00683940, 0x57c);
            area = 1;
        }
        func_001cf940(area, entry);
        spawned++;
    }
done:
    return spawned;
}

/* Removing this worsens FUN_001d0880 (nd485 -> nd512) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001d0880 NONMATCHING
u8* func_001d0880(s32 ordinal, s32 targetCount)
{
    u8* node;
    u8* best;
    RwV3d heroPos;
    RwV3d* nodePos;
    RwMatrix* modelMatrix;
    RwV3d delta;
    f32 bestDistance;
    f32 distance;
    f32 threshold;
    s32 index;
    s32 bestIndex;
    u32 sceneMode;
    u32 distanceMode;

    node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_15);
    best = NULL;
    bestIndex = 0;
    func_001bff20();
    distanceMode = func_001c0040();
    threshold = (distanceMode == 3 || distanceMode == 1) ? 1500.0f : 2000.0f;
    sceneMode = K_Scene_001a0250();
    if (sceneMode == 1)
    {
        if (func_001d0e40() < (u32)targetCount)
        {
            heroPos = mdlGetMatrix(gFldUnitsPc[0].mdl)->pos;
            bestDistance = 1.1754944e-38f;
            node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_15);
            while (node != NULL)
            {
                nodePos = FldUnit_NodePos(node);
                for (index = 0; index < FLDUNIT_PC_MAX; index++)
                {
                    if (gFldUnitsPc[index].genusBase != NULL && gFldUnitsPc[index].resrc != NULL)
                    {
                        modelMatrix = mdlGetMatrix(gFldUnitsPc[index].mdl);
                        delta.x = nodePos->x - modelMatrix->pos.x;
                        delta.y = nodePos->y - modelMatrix->pos.y;
                        delta.z = nodePos->z - modelMatrix->pos.z;
                        if (RwV3dLength(&delta) < threshold)
                        {
                            break;
                        }
                    }
                }
                if (index == FLDUNIT_PC_MAX)
                {
                    if (func_001d0e40() == 0)
                    {
                        return node;
                    }
                    distance = 1.1754944e-38f;
                    bestIndex = 0;
                    for (index = 0; index < FLDUNIT_EC_MAX; index++)
                    {
                        if (gFldUnitsEc[index].genusBase != NULL)
                        {
                            distance = FldUnit_NodeDistance(nodePos,
                                &mdlGetMatrix(gFldUnitsEc[index].mdl)->pos);
                            if (distance < threshold)
                            {
                                break;
                            }
                            if (distance > bestDistance)
                            {
                                bestDistance = distance;
                                best = node;
                                bestIndex = index;
                            }
                        }
                    }
                    if (index == FLDUNIT_EC_MAX && best == NULL)
                    {
                        best = node;
                    }
                }
                node = *(u8**)(node + 0xf8);
            }
            (void)bestIndex;
            return best;
        }
    }
    else
    {
        index = 0;
        best = NULL;
        while (node != NULL)
        {
            if (index == ordinal)
            {
                best = node;
                break;
            }
            node = *(u8**)(node + 0xf8);
            index++;
        }
        return best;
    }
    return NULL;
}
#pragma opt_loop_invariants off

// FUN_001d0bc0
void func_001d0bc0(void* output, u32 count)
{
    u8* node;
    u8* dst;
    RwV3d nodePos;
    RwV3d delta;
    f32 distance;
    f32 bestDistance;
    u32 i;
    u32 k;
    u32 j;
    u8* selectedDst;
    u8* node2;
    typedef struct
    {
        u32 data[0x44];
    } SpawnCopy;

    node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_15);
    i = 0;
    memset(output, 0, 0x330);
    if (K_Scene_001a0250() == 1)
    {
        while (node != NULL)
        {
            i++;
            node = *(u8**)(node + 0xf8);
        }
        if (i < count)
        {
            K_Assert(__FILE__, 0x60d);
        }
        for (k = 0; k < count; k++)
        {
            bestDistance = 1.1754944e-38f;
            node2 = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_15);
            selectedDst = (u8*)output + k * 0x110;
            while (node2 != NULL)
            {
                nodePos = *FldUnit_NodePos(node2);
                delta.x = nodePos.x - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.x;
                delta.y = nodePos.y - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.y;
                delta.z = nodePos.z - mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.z;
                distance = func_004c6ac0(&delta);
                for (j = 0; j < k; j++)
                {
                    dst = (u8*)output + j * 0x110;
                    delta.x = nodePos.x - *(f32*)(dst + 0x100);
                    delta.y = nodePos.y - *(f32*)(dst + 0x104);
                    delta.z = nodePos.z - *(f32*)(dst + 0x108);
                    distance += func_004c6ac0(&delta);
                }
                if (distance > bestDistance)
                {
                    bestDistance = distance;
                    *(SpawnCopy*)selectedDst = *(SpawnCopy*)node2;
                }
                node2 = *(u8**)(node2 + 0xf8);
            }
        }
    }
}

// FUN_001d0e40
u32 func_001d0e40(void)
{
    return uGpffffb59c;
}

// FUN_001d0e50 NONMATCHING
void func_001d0e50(s32 isDungeon)
{
    s32 i;
    FldUnit* unit;
    DatUnitGenusBase** genusBase;
    Model** model;
    ResrcModelChar** resource;
    u16 resourceId;
    RwMatrix* modelMatrix;
    RwV3d light;
    RwV3d scale;

    for (i = isDungeon ? 0 : 1; i < FLDUNIT_PC_MAX; i++)
    {
        unit = &gFldUnitsPc[i];
        genusBase = &unit->genusBase;
        if (*genusBase != NULL)
        {
            model = &unit->mdl;
            resource = &unit->resrc;
            resourceId = func_003b6030(i, 1, *model);
            *resource = (ResrcModelChar*)func_003b5d10(resourceId);
            modelMatrix = (RwMatrix*)func_00318b60(*model);
            *modelMatrix = unit->matBeforeBtl;
            func_004c2f10((u64)func_00318b60(*model));
            func_001a0dc0(resourceId, 1);
            func_001ad870((*resource)->collisCtlTask, 0x40000000);
            func_001add40((*resource)->collisCtlTask);
            if (i == 0)
            {
                func_001ad8c0(60.0f, (*resource)->collisCtlTask);
            }
            else
            {
                func_001ad8c0(35.0f, (*resource)->collisCtlTask);
            }
            (*resource)->baseMdl = (Model*)func_00317450(uGpffffb52c);
            light.x = func_001ad8b0((*resource)->collisCtlTask);
            light.y = light.x;
            light.z = light.x;
            scale = light;
            func_00318a90((*resource)->baseMdl, &scale, 2);
            func_004cb420(func_00318b70(*model),
                         func_00318b70((*resource)->baseMdl));
            func_00317730((*resource)->baseMdl);
            if (func_002ff790(*genusBase) == 0)
            {
                func_003182d0(*model, 0,
                              func_001dde00(gFldUnitsPc[i].charId), 0, 1);
            }
            if (i != 0)
            {
                gFldUnitsPc[i].unk_170 =
                    (KwlnTask*)func_001af930(0, *resource);
                gFldUnitsPc[i].unk_16c =
                    (KwlnTask*)func_00431670(0, i, &gFldUnitsPc[i]);
            }
            gFldUnitsPc[i].unk_180 =
                (KwlnTask*)func_001d40e0(0, &gFldUnitsPc[i]);
            if (i == 0)
            {
                gFldUnitsPc[i].unk_174 =
                    (KwlnTask*)func_001dd460(0, 0, 0x106f);
            }
        }
    }
    if (K_Scene_001a0250() == 1)
    {
        func_00434f60(0);
    }
    else
    {
        func_00434f60();
    }
}

// FUN_001d11b0
void func_001d11b0(void)
{
    s32 i;
    s32 kind;
    FldUnit* unit;

    i = 0;
    while (i < FLDUNIT_EC_MAX)
    {
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL)
        {
            kind = unit->unk_18c;
            switch (kind)
            {
                case 5:
                case 1:
                    unit->mdl = (Model*)func_00316e00(8, 1, 0);
                    break;
                case 2:
                    unit->mdl = (Model*)func_00316e00(8, 2, 0);
                    break;
                case 4:
                    unit->mdl = (Model*)func_00316e00(8, 3, 0);
                    break;
                case 3:
                    unit->mdl = (Model*)func_00316e00(8, 4, 0);
                    break;
            }
        }
        i++;
    }
}

// FUN_001d12d0
u32 func_001d12d0(void)
{
    s32 i;
    FldUnit* unit;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL && func_00316f70(unit->mdl) == 0)
        {
            return 0;
        }
    }
    return 1;
}

/* Removing this worsens FUN_001d1360 (nd448 -> nd516) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001d1360
void func_001d1360(void)
{
    s32 i;
    u16 resourceId;
    ResrcModelChar** resource;
    FldUnit* unit;
    Model** model;
    KwlnTask** taskSlot;
    RwV3d light;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL)
        {
            model = &unit->mdl;
            resourceId = func_003b6030((u16)(i + 100), 0, unit->mdl);
            resource = &unit->resrc;
            *resource = (ResrcModelChar*)func_003b5d10(resourceId);
            func_00318a90(*model, &DAT_00683780[unit->scaleIdx], 2);
            *(RwMatrix*)func_00318b60(*model) = unit->matBeforeBtl;
            func_004c2f10(func_00318b70(*model));
            func_001a0dc0((*resource)->base.resTypeId, 1);
            func_001ad870((*resource)->collisCtlTask, 0x40000000);
            func_001add40((*resource)->collisCtlTask);
            func_001ad8c0_reordered((*resource)->collisCtlTask, 35.0f);
            (*resource)->baseMdl = (Model*)func_00317450(uGpffffb52c);
            light.z = func_001ad8b0((*resource)->collisCtlTask);
            light.y = light.z;
            light.x = light.z;
            func_00318a90((*resource)->baseMdl, &light, 2);
            func_004cb420(func_00318b70(*model),
                          func_00318b70((*resource)->baseMdl));
            func_00317730((*resource)->baseMdl);
            unit->unk_170 = (KwlnTask*)func_001af930(0, *resource);
            unit->unk_16c = (KwlnTask*)func_0044ad20(0, (s32)(s8)i);
            if (unit->unk_18c == 2)
            {
                taskSlot = &unit->unk_178;
                if (unit->unk_178 == NULL)
                {
                    *taskSlot = (KwlnTask*)func_001d3c40_ptr(
                        NULL, (*resource)->mdl);
                }
            }
            if (func_001c65e0(unit) == 0)
            {
                gFldUnitsEc[i].unk_174 =
                    (KwlnTask*)func_001dd460(0, 5, 0x1058);
                func_001dd5f0(gFldUnitsEc[i].unk_174, *model);
                func_001dd5e0(gFldUnitsEc[i].unk_174, 1);
            }
        }
    }
    func_001d2a10();
}
#pragma opt_loop_invariants off
// FUN_001d1640
void func_001d1640(FldUnit* unit, s32 destroyModel)
{
    u32 valid;

    valid = unit->genusBase != NULL;
    if (valid != 0)
    {
        valid = unit->resrc != NULL;
    }
    if (valid != 0)
    {
        unit->matBeforeBtl = *mdlGetMatrix(unit->mdl);
        func_003b7090(unit->resrc->base.resTypeId);
        unit->resrc = NULL;
        if (unit->mdl != NULL && destroyModel == 1)
        {
            mdlDestroy(unit->mdl);
            unit->mdl = NULL;
        }
        if (unit->unk_16c != NULL) { func_00195020(unit->unk_16c); unit->unk_16c = NULL; }
        if (unit->unk_170 != NULL) { func_00195020(unit->unk_170); unit->unk_170 = NULL; }
        if (unit->unk_178 != NULL) { func_00195020(unit->unk_178); unit->unk_178 = NULL; }
        if (unit->unk_180 != NULL) { func_00195020(unit->unk_180); unit->unk_180 = NULL; }
        if (unit->unk_174 != NULL) { func_00195020(unit->unk_174); unit->unk_174 = NULL; }
    }
    }

// FUN_001d1780
void func_001d1780(s32 includeHero)
{
    s32 i;

    for (i = includeHero ? 0 : 1; i < FLDUNIT_PC_MAX; i++)
    {
        func_001d1640(&gFldUnitsPc[i], 0);
    }
}

// FUN_001d17f0
void func_001d17f0(s32 destroyModel)
{
    s32 i;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        func_001d1640(&gFldUnitsEc[i], destroyModel);
    }
}

// FUN_001d1860
void func_001d1860(u32 value)
{
    s32 i;
    FldUnit* unit;
    u32 valid;
    u32 predicate;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsPc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            func_0019c2f0(unit->resrc->renderTexShadowTask, value);
        }
    }
}


// FUN_001d1910
void func_001d1910(void)
{
    s32 i;
    s32 offset;
    FldUnit* unit;
    FldUnit* unit2;
    u32 valid;
    u32 predicate;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsPc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            offset = i * sizeof(FldUnit);
            unit2 = (FldUnit*)((int)gFldUnitsPc + offset);
            func_001a60d0(0, unit2->mdl, 0, 1);
            unit2->unk_17c = 0;
        }
    }
}
// FUN_001d19d0
void func_001d19d0(void)
{
    s32 i;
    s32 offset;
    FldUnit* unit;
    u32 valid;
    u32 predicate;

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsPc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            offset = i * sizeof(FldUnit);
            unit = (FldUnit*)((int)gFldUnitsPc + offset);
            unit->unk_17c = 0;
            func_001a60d0(0, unit->mdl, 0xff, 1);
        }
    }
}

// FUN_001d1a90
u32 func_001d1a90(void)
{
    s32 i;
    FldUnit* unit;
    u32 markerValue;
    u32* marker;
    u32 valid;
    u32 predicate;
    u32 result;

    result = 1;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsPc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            marker = &unit->unk_17c;
            markerValue = *marker;
            if (markerValue == 0)
            {
                continue;
            }
            if (func_00195460_marker(markerValue) == 1)
            {
                result = 0;
            }
            else
            {
                *marker = 0;
            }
        }
    }
    return result;
}
// FUN_001d1b60
void func_001d1b60(void)
{
    s32 i;
    s32 offset;
    FldUnit* unit;
    FldUnit* unit2;
    u32 valid;
    u32 predicate;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            offset = i * sizeof(FldUnit);
            unit2 = (FldUnit*)((int)gFldUnitsEc + offset);
            unit2->unk_17c = 0;
            func_001a60d0(0, unit2->mdl, 0, 1);
        }
    }
}

// FUN_001d1c20
void func_001d1c20(void)
{
    s32 i;
    s32 offset;
    FldUnit* unit;
    FldUnit* unit2;
    u32 valid;
    u32 predicate;

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            offset = i * sizeof(FldUnit);
            unit2 = (FldUnit*)((int)gFldUnitsEc + offset);
            unit2->unk_17c = 0;
            func_001a60d0(0, unit2->mdl, 0xff, 1);
        }
    }
}

// FUN_001d1ce0
u32 func_001d1ce0(void)
{
    s32 i;
    FldUnit* unit;
    u32 markerValue;
    u32* marker;
    u32 valid;
    u32 predicate;
    u32 result;

    result = 1;
    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        valid = 0;
        unit = &gFldUnitsEc[i];
        if (unit->genusBase != NULL && unit->resrc != NULL)
        {
            valid = 1;
        }
        predicate = valid > 0;
        if (predicate == 1)
        {
            marker = &unit->unk_17c;
            markerValue = *marker;
            if (markerValue != 0)
            {
                if (func_00195460_marker(markerValue) == 1)
                {
                    result = 0;
                }
                else
                {
                    *marker = 0;
                }
            }
        }
    }
    return result;
}

// FUN_001d1db0 NONMATCHING
void func_001d1db0(void* work, const void* source, u16 resourceId)
{
    u8* dst;
    const u8* src;
    u8* modelResource;
    u8* scene;
    u8 materialFlag;
    void* table;
    u16 modelId;
    RwV3d gridPos;

    if (work == NULL)
    {
        return;
    }
    dst = (u8*)work;
    src = (const u8*)source;
    materialFlag = *(u8*)(*(u32*)(dst + 0x11c) + 7);
    scene = func_001b9120();
    table = func_00317450((void*)*(u32*)(scene + 0x11ec + ((materialFlag & 1) != 0) * 4));
    modelId = func_003b65d0(resourceId, table);
    *(u16*)(dst + 8) = modelId;
    modelResource = (u8*)func_003b5d10(modelId);
    func_00319230((void*)*(u32*)(modelResource + 0x104), 3);
    func_00318a50(*(void**)(dst + 0x10c), *(void**)(modelResource + 0x104),
                   (void*)&DAT_00683960, 2);
    func_00318a30(*(void**)(modelResource + 0x104), (void*)(src + 0x100), 2);
    table = func_00317450(uGpffffb52c);
    *(u32*)(modelResource + 0x12c) = (u32)table;
    func_00318a50(*(void**)(dst + 0x10c), table, (void*)&DAT_00683960, 2);
    func_00318a90(table, (void*)&DAT_00683970, 2);
    func_00318a30(table, (void*)(src + 0x100), 2);
    *(u32*)(dst + 0x134) = (u32)table;
    func_00317730(table);
    gridPos.x = *(f32*)(src + 0x100);
    gridPos.y = *(f32*)(src + 0x108);
    scene = func_001b9120();
    *(u32*)(modelResource + 0x100) = (u32)func_003b5d10(
        *(u16*)(scene + (s32)((gridPos.y + 400.0f) / 800.0f) * 0x100 +
                       (s32)((gridPos.x + 400.0f) / 800.0f) * 0x10 + 0x4c));
    func_001a0150(modelId, 1);
    iGpffffb598++;
}

// FUN_001d1fa0
void func_001d1fa0(void)
{
    u8* spawn;
    u32 area;
    u32 count;
    s32 index;
    u16* model;
    u8* record;
    u8* candidate;
    s32 slot;
    u8* base;
    u16 spawnId;
    typedef struct
    {
        u32 data[0x44];
    } SpawnCopy;

    area = func_001bff20();
    memset(DAT_0086be80, 0, 0x2700);
    iGpffffb598 = 0;
    count = func_001d77d0_u32(*puGpffffa850, puGpffffa850[2], area);
    switch (func_001c0040())
    {
        case 0:
        case 1:
            break;
        case 2:
            count = 10;
            break;
        case 3:
        case 4:
            break;
    }
    if (count == 0)
    {
        return;
    }
    index = 0;
    while ((spawn = (u8*)func_001d2300(index, count)) != NULL)
    {
        model = func_001d78c0(*puGpffffa850, puGpffffa850[2], area);
        if (model == NULL)
        {
            K_Assert(D_00683940, 0x85c);
        }
        record = NULL;
        slot = 0;
        base = DAT_0086be80;
        while (slot < 0x20)
        {
            candidate = base + slot * 0x138;
            if (*(u32*)candidate == 0)
            {
                record = candidate;
                break;
            }
            slot++;
        }
        *(u32*)record = 1;
        *(u32*)(record + 0x11c) = (u32)model;
        *(SpawnCopy*)(record + 0x0c) = *(SpawnCopy*)spawn;
        func_001d1db0_u32(record, spawn, 0x3fe - index);
        spawnId = model[1];
        if (spawnId < 5000)
        {
            if (spawnId >= 4000)
            {
                func_001828d0(spawnId, record + 0x120);
            }
            else
            {
                if (*(u8*)((u8*)model + 5) == 0)
                {
                    func_001828d0(spawnId, record + 0x120);
                }
                else
                {
                    func_00182d90(spawnId, 2,
                                   *(u8*)((u8*)model + 5), record + 0x120);
                }
            }
        }
        index++;
    }
}

// FUN_001d2210
void func_001d2210(void)
{
    s32 i;
    u8* record;

    for (i = 0; i < 0x20; i++)
    {
        record = DAT_0086be80 + i * 0x138;
        if (*(u32*)record != 0)
        {
            func_001d1db0(record, record + 0x0c, *(u16*)(record + 8) & 0x3ff);
        }
    }
    func_001d2a10();
}

// FUN_001d22a0
void func_001d22a0(void* work)
{
    u8* record;

    record = (u8*)work;
    func_003b7090(*(u16*)(record + 8));
    memset(record, 0, 0x0c);
    iGpffffb598--;
    func_001d2a10();
}

/* Removing this worsens FUN_001d2300 (nd502 -> nd511) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001d2300 NONMATCHING
u8* func_001d2300(s32 ordinal, s32 maxCount)
{
    u8* node;
    u8* best;
    RwV3d heroPos;
    RwV3d delta;
    f32 distance;
    f32 bestDistance;
    s32 i;
    s32 slot;

    node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_16);
    K_FldDungeon_GetCurrentFloor();
    best = NULL;
    if (K_Scene_001a0250() == 1)
    {
        if (iGpffffb598 >= maxCount)
        {
            return NULL;
        }
        heroPos.x = mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.x;
        heroPos.y = mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.y;
        heroPos.z = mdlGetMatrix(gFldUnitsPc[0].mdl)->pos.z;
        bestDistance = 1.1754944e-38f;
        while (node != NULL)
        {
            RwV3d* pos = &((FldUnitNode*)node)->pos;
            delta.x = pos->x - heroPos.x;
            delta.y = pos->y - heroPos.y;
            delta.z = pos->z - heroPos.z;
            distance = RwV3dLength(&delta);
            if (distance >= 500.0f)
            {
                if (*(u32*)DAT_0086e580 == 1)
                {
                    delta.x = pos->x - *(f32*)(DAT_0086e580 + 0x104);
                    delta.y = pos->y - *(f32*)(DAT_0086e580 + 0x108);
                    delta.z = pos->z - *(f32*)(DAT_0086e580 + 0x10c);
                    if (RwV3dLength(&delta) < 500.0f)
                    {
                        node = *(u8**)(node + 0xf8);
                        continue;
                    }
                }
                bestDistance = 1.1754944e-38f;
                for (i = 0; i < 0x20; i++)
                {
                    u8* record = DAT_0086be80 + i * 0x138;
                    if (*(u32*)record != 0)
                    {
                        delta.x = pos->x - *(f32*)(record + 0x10c);
                        delta.y = pos->y - *(f32*)(record + 0x110);
                        delta.z = pos->z - *(f32*)(record + 0x114);
                        distance = RwV3dLength(&delta);
                        if (distance < 100.0f)
                        {
                            bestDistance = -1.0f;
                            break;
                        }
                        bestDistance += distance;
                    }
                }
                if (bestDistance >= 0.0f && (best == NULL || distance > bestDistance))
                {
                    best = node;
                }
            }
            node = *(u8**)(node + 0xf8);
        }
        return best;
    }
    for (slot = 0; node != NULL && slot != ordinal; slot++)
    {
        node = *(u8**)(node + 0xf8);
    }
    return node;
}
#pragma opt_loop_invariants off

// FUN_001d2610 NONMATCHING
void func_001d2610(void)
{
    u32 chance;
    s32 count;
    s32 retries;
    s32 selected;
    u8* node;
    u8* dst;
    RwV3d heroPos;
    RwV3d pos;
    RwV3d delta;
    ResrcModelChar* resource;
    Model* model;
    u16 resourceId;
    u8* scene;

    if (K_Scene_001a0250() == 0 && func_001a02c0() == 0)
    {
        return;
    }
    if (*(u32*)DAT_0086e580 == 0)
    {
        if (K_Scene_001a0250() == 0)
        {
            scene = func_001b9120();
            *(u16*)(scene + 0x44) = 100;
        }
        chance = func_00488f30();
        scene = func_001b9120();
        if ((chance % 100) >= *(u16*)(scene + 0x44))
        {
            *(u32*)DAT_0086e580 = 2;
        }
        else
        {
            count = 0;
            node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_17);
            while (node != NULL)
            {
                count++;
                node = *(u8**)(node + 0xf8);
            }
            retries = 0;
            while (*(u32*)DAT_0086e580 == 0)
            {
                if (count < 1)
                {
                    *(u32*)DAT_0086e580 = 2;
                }
                else
                {
                    selected = func_00488f30() % count;
                    node = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_17);
                    while (selected-- > 0)
                    {
                        node = *(u8**)(node + 0xf8);
                    }
                    heroPos = mdlGetMatrix(gFldUnitsPc[0].mdl)->pos;
                    pos = *FldUnit_NodePos(node);
                    delta.x = heroPos.x - pos.x;
                    delta.y = heroPos.y - pos.y;
                    delta.z = heroPos.z - pos.z;
                    if (RwV3dLength(&delta) > 500.0f)
                    {
                        memcpy(DAT_0086e580 + 4, node, 0x110);
                        *(u32*)DAT_0086e580 = 1;
                    }
                }
                if (retries++ > 10)
                {
                    *(u32*)DAT_0086e580 = 2;
                }
            }
        }
    }
    if (*(u32*)DAT_0086e580 == 1)
    {
        resourceId = func_003b65d0(0x3ff, func_00317450(uGpffffb590));
        resource = (ResrcModelChar*)func_003b5d10(resourceId);
        func_00319230((void*)*(u32*)((u8*)resource->mdl + 0x104), 3);
        func_00318a50(&DAT_0086e690, *(void**)((u8*)resource->mdl + 0x104),
                      (void*)&DAT_00683980, 2);
        func_00318a30(*(void**)((u8*)resource->mdl + 0x104), DAT_0086e580 + 0x104, 2);
        *(u32*)((u8*)resource->mdl + 0x12c) = (u32)func_00317450(uGpffffb52c);
        func_00318a50(&DAT_0086e690, (void*)*(u32*)((u8*)resource->mdl + 0x12c),
                      (void*)&DAT_00683980, 2);
        func_00318a90((void*)*(u32*)((u8*)resource->mdl + 0x12c),
                      (void*)&DAT_00683990, 2);
        func_00318a30((void*)*(u32*)((u8*)resource->mdl + 0x12c), DAT_0086e580 + 0x104, 2);
        DAT_0086e694 = *(u32*)((u8*)resource->mdl + 0x12c);
        func_00317730((void*)DAT_0086e694);
        pos.x = *(f32*)(DAT_0086e580 + 0x104) + 400.0f;
        pos.z = *(f32*)(DAT_0086e580 + 0x10c) + 400.0f;
        scene = func_001b9120();
        *(u32*)((u8*)resource->mdl + 0x100) = (u32)func_003b5d10(
            *(u16*)(scene + (s32)(pos.z / 800.0f) * 0x100 +
                           (s32)(pos.x / 800.0f) * 0x10 + 0x4c));
        func_001a0150(resourceId, 1);
    }
}

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

// FUN_001d2a10 NONMATCHING
void func_001d2a10(void)
{
    s32 i;
    s32 j;
    s32 k;
    s32 dir;
    s32 slot;
    s32 gridX;
    s32 gridZ;
    s32 kind;
    f32 extent;
    f32 recordExtent;
    f32 x;
    f32 z;
    RwMatrix* matrix;
    u8* unit;
    u8* record;
    u8* reaper;
    void** cell;

    memset(DAT_0086b180, 0, 0xc40);
    if (piGpffffa850[0] == -1)
    {
        return;
    }
    if (K_Scene_001a0250() == 0)
    {
        slot = 0;
        for (i = 0; i < FLDUNIT_EC_MAX; i++)
        {
            if (gFldUnitsEc[i].genusBase != NULL)
            {
                if (slot >= 0x18) { K_ASSERT(0, 0xa47); break; }
                DAT_0086b180[slot++] = &gFldUnitsEc[i];
            }
        }
        slot = 0;
        for (i = 0; i < 0x20; i++)
        {
            record = DAT_0086be80 + i * 0x138;
            if (*(u32*)record == 1)
            {
                if (slot >= 0x18) { K_ASSERT(0, 0xa52); break; }
                DAT_0086b180[0x18 + slot++] = record;
            }
        }
        if (*(u32*)DAT_0086e580 == 1)
        {
            DAT_0086b180[0x30] = DAT_0086e580;
        }
        return;
    }
    recordExtent = -80.0f;
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 4; i++)
        {
            cell = &DAT_0086b180[j * 0xc4 / 4 + i * 0x310 / 4];
            slot = 0;
            for (k = 0; k < FLDUNIT_EC_MAX; k++)
            {
                unit = (u8*)&gFldUnitsEc[k];
                if (K_Scene_001a0250() != 0 &&
                    gFldUnitsEc[k].genusBase != NULL)
                {
                    kind = gFldUnitsEc[k].unk_18c;
                    if (K_Scene_001a0250() != 0 && kind != 4)
                    {
                        extent = iGpffffb5a0[kind * 0x10] * (kind == 3 ? 3.0f : 2.0f);
                        matrix = mdlGetMatrix(gFldUnitsEc[k].mdl);
                        x = matrix->pos.x - extent;
                        z = matrix->pos.z;
                        for (dir = 0; dir < 3; dir++)
                        {
                            gridX = FldUnit_GridCoord(x + extent * dir);
                            gridZ = FldUnit_GridCoord(z);
                            if (K_Scene_001a0250() != 0 &&
                                gridX == i && gridZ == j)
                            {
                                if (slot >= 0x18) { K_ASSERT(0, 0xa47); break; }
                                cell[slot++] = unit;
                                break;
                            }
                        }
                    }
                }
            }
            slot = 0;
            for (k = 0; k < 0x20; k++)
            {
                record = DAT_0086be80 + k * 0x138;
                if (K_Scene_001a0250() != 0 && *(u32*)record != 0)
                {
                    x = *(f32*)(record + 0x10c) + recordExtent;
                    z = *(f32*)(record + 0x114) + recordExtent;
                    for (dir = 0; dir < 3; dir++)
                    {
                        gridX = FldUnit_GridCoord(
                            x - dir * recordExtent);
                        gridZ = FldUnit_GridCoord(z);
                        if (K_Scene_001a0250() != 0 &&
                            gridX == i && gridZ == j)
                        {
                            if (slot >= 0x18) { K_ASSERT(0, 0xa52); break; }
                            cell[0x18 + slot++] = record;
                            break;
                        }
                    }
                }
            }
            if (K_Scene_001a0250() != 0 &&
                *(u32*)DAT_0086e580 == 1 &&
                FldUnit_GridCoord(*(f32*)(DAT_0086e580 + 0x104)) == i &&
                FldUnit_GridCoord(*(f32*)(DAT_0086e580 + 0x10c)) == j)
            {
                cell[0x30] = DAT_0086e580;
            }
        }
    }
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 4; i++)
        {
            cell = &DAT_0086b180[j * 0xc4 / 4 + i * 0x310 / 4];
            for (k = 0; k < FLDUNIT_EC_MAX; k++)
            {
                if (gFldUnitsEc[k].genusBase != NULL && gFldUnitsEc[k].unk_18c == 4)
                {
                    slot = 0;
                    while (slot < 0x18 && cell[slot] != NULL) slot++;
                    if (slot < 0x18) cell[slot] = &gFldUnitsEc[k];
                    break;
                }
            }
        }
    }
    (void)reaper;
}

/* Removing this worsens FUN_001d32a0 (nd588 -> nd637) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001d32a0 NONMATCHING
void* func_001d32a0(KwlnTask* task)
{
    s32* work;
    s32 state;
    s32 i;
    s32 count;
    s32 encounterMode;
    u32 area;
    u16 grid;
    u32 available;
    RwV3d spawnPos;
    RwV3d spawnPosCopy;

    work = (s32*)task->workData;
    if (piGpffffa850[0] == 0xe && piGpffffa850[1] == 5)
    {
        return NULL;
    }
    if (work[1] == 1)
    {
        return NULL;
    }
    if (work[2] == 1)
    {
        return NULL;
    }
    state = work[0];
    switch (state)
    {
    case 0:
        if (K_Scene_001a0250() == 1)
        {
            count = 0;
            for (i = 0; i < 0x10; i++)
            {
                s32 j;
                for (j = 0; j < 0x10; j++)
                {
                    if (func_001b9120()[i * 0x100 + j * 0x10 + 0x48] == 1) count++;
                }
            }
            work[3] = count * 10;
        }
        uGpffffb59c = 0;
        grid = func_001bff20();
        available = func_001d75f0((u16)piGpffffa850[0], (u16)piGpffffa850[1], grid);
        encounterMode = func_001c0040();
        switch (encounterMode)
        {
        case 0:
            available = 0;
            func_001d38d0(task, 1);
            break;
        case 1:
        case 2:
        case 3:
            available <<= 1;
            if (available > 0x12) available = 0x12;
            func_001d38d0(task, 2);
            break;
        case 4:
            break;
        }
        func_001d0720(available);
        work[0]++;
        break;
    case 1:
        for (i = 0; i < FLDUNIT_EC_MAX; i++)
        {
            if (func_001cfdd0(i) == 0)
            {
                break;
            }
        }
        if (i == FLDUNIT_EC_MAX)
        {
            func_001d2a10();
            work[0]++;
        }
        break;
    case 2:
        grid = func_001bff20();
        available = func_001d76e0((u16)piGpffffa850[0], (u16)piGpffffa850[1], grid);
        if (func_001c0040() != 4)
        {
            available = 0;
        }
        if (uGpffffb59c < available && func_001d0720(available) > 0)
        {
            work[0] = 1;
        }
        if (work[3] != 0 && work[3] < work[4] / 0x1e && work[5] == 0)
        {
            func_00452010(&spawnPos);
            spawnPosCopy = spawnPos;
        }
        if (work[3] != 0 && work[3] < work[4] / 0x1e && work[5] == 0)
        {
            work[0] = 1;
        }
        else
        {
            work[4]++;
        }
        if (work[3] != 0 && work[3] < work[4] / 0x1e && work[5] == 0)
        {
            K_FldUnit_CreateReaper(1, &spawnPosCopy);
            datSetFlag(0x1423, 1);
            work[5]++;
            work[0] = 1;
        }
        break;
    }
    (void)area;
    return NULL;
}
#pragma opt_loop_invariants off

// FUN_001d36c0
void func_001d36c0(KwlnTask* task)
{
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001d36f0
KwlnTask* func_001d36f0(KwlnTask* parent)
{
    s32* work;
    KwlnTask* task;

    work = (s32*)((void* (*)(u32, u32, u32))DAT_00960184[0])(1, 0x18, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)func_00194b80(parent, 10, DAT_006839a0,
                                    func_001d32a0, func_001d36c0, work);
    datSetFlag(0x1423, 0);
    return task;
}

// FUN_001d3790
u32 func_001d3790(KwlnTask* task)
{
    s32* work;

    work = (s32*)task->workData;
    if (piGpffffa850[0] == 0xe && piGpffffa850[1] == 5)
    {
        return 1;
    }
    if (work[0] == 2)
    {
        return 1;
    }
    return 0;
}

// FUN_001d37f0
void func_001d37f0(KwlnTask* task, u32 value)
{
    if (task != NULL)
    {
        ((s32*)task->workData)[1] = value;
    }
}

// FUN_001d3810
void func_001d3810(KwlnTask* task, u32 value)
{
    if (task != NULL)
    {
        ((s32*)task->workData)[2] = value;
    }
}

#pragma push
// FUN_001d3830
s32 func_001d3830(KwlnTask* task)
{
    s32 remaining;
    s32 result;

    result = -1;
    if (((s32*)task->workData)[3] == 0)
    {
        result = -1;
    }
    else
    {
        remaining = func_001d38a0(task);
        if (remaining == 0)
        {
            result = 2;
        }
        else if (remaining < 0x3c)
        {
            result = 1;
        }
    }
    return result;
}
#pragma pop

// FUN_001d38a0
s32 func_001d38a0(KwlnTask* task)
{
    s32* work;
    s32 remaining;

    work = (s32*)task->workData;
    remaining = work[3];
    remaining -= (s32)((u32)work[4] / 0x1e);
    return remaining < 0 ? 0 : remaining;
}

// FUN_001d38d0
void func_001d38d0(KwlnTask* task, s32 multiplier)
{
    s32* work;
    typedef struct KUnitGridValue
    {
        u8 reserved[0x48];
        u8 value;
    } KUnitGridValue;
    s32 i;
    s32 j;
    s32 count;
    s32 rowOffset;

    work = (s32*)task->workData;
    if (K_Scene_001a0250() == 1)
    {
        i = 0;
        count = 0;
        while (i < 0x10)
        {
            j = 0;
            rowOffset = i * 0x100;
            while (j < 0x10)
            {
                KUnitGridValue* gridValue;

                gridValue = (KUnitGridValue*)((u32)rowOffset +
                                             (u32)func_001b9120());
                gridValue = (KUnitGridValue*)((u8*)gridValue + j * 0x10);
                if (gridValue->value == 1)
                {
                    count++;
                }
                j++;
            }
            i++;
        }
        if ((u32)(count * multiplier) < (u32)work[3])
        {
            work[3] = count * multiplier;
        }
    }
}

#pragma push
#pragma opt_propagation off
// FUN_001d39c0
void func_001d39c0(KwlnTask* task)
{
    s32* work;
    RwV3d spawnPos;
    RwV3d* spawnPosPtr;
    RwV3d position;
    f32 x;
    f32 y;
    f32 z;

    work = (s32*)task->workData;
    func_00452010(&position);
    spawnPosPtr = &spawnPos;
    x = position.x;
    y = position.y;
    z = position.z;
    spawnPos.x = x;
    spawnPos.y = y;
    spawnPos.z = z;
    K_FldUnit_CreateReaper(1, spawnPosPtr);
    work[5]++;
    work[0] = 1;
}
#pragma pop

// FUN_001d3a30
void* func_001d3a30(KwlnTask* task)
{
    s32* work;
    f32 phase;
    RwRGBA color;

    work = (s32*)task->workData;
    phase = func_0052e878(fGpffff8248 * (f32)work[2] / 30.0f);
    color.r = (u8)(phase * 100.0f + 120.0f);
    color.g = (u8)(80.0f - phase * 30.0f);
    color.b = (u8)(phase * 40.0f + 120.0f);
    color.a = 0xff;
    work[2]++;
    if (work[2] > 0x1e) work[2] = 0;
    func_00318ad0((void*)work[1], &color);
    return NULL;
}

// FUN_001d3c10
void func_001d3c10(KwlnTask* task)
{
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001d3c40
KwlnTask* func_001d3c40(KwlnTask* parent, u32 model)
{
    s32* work;
    KwlnTask* task;

    work = (s32*)((void* (*)(u32, u32, u32))DAT_00960184[0])(1, 0x0c, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)func_00194b80(parent, 10, DAT_006839c0,
                                    func_001d3a30, func_001d3c10, work);
    work[1] = model;
    return task;
}

// FUN_001d3ce0
void* func_001d3ce0(KwlnTask* task)
{
    s32* work;
    RwV3d pos;
    RwRGBA colors[2];
    u32 status;
    u32 now;
    u32 deadline;
    u32 hp;
    s32 damage;
    s32 finalDamage;
    s16 pcId;
    u8* scene;
    s8* colorSrc;
    s8* colorDst;
    s32 i;
    s8 color0;
    s8 color1;

    u8* colorData;
    work = (s32*)task->workData;
    colorSrc = (s8*)gp0xffff95d0;
    colorDst = (s8*)colors;
    i = 4;
    do
    {
        color0 = colorSrc[0];
        color1 = colorSrc[1];
        colorSrc += 2;
        i--;
        colorDst[0] = color0;
        colorDst[1] = color1;
        colorDst += 2;
    } while (i > 0);
    status = func_0016c970((s16)((FldUnit*)work[1])->charId);
    if ((status & 0x80) != 0 &&
        !(piGpffffa850[0] == 0x20 && piGpffffa850[1] == 2) &&
        !(piGpffffa850[0] == 0x27 && piGpffffa850[1] == 3))
    {
        if (work[2] == 0)
        {
            if (func_00318ed0(((FldUnit*)work[1])->mdl, 2, &pos) == 0)
            {
                pos = ((RwMatrix*)func_00318b60(((FldUnit*)work[1])->mdl))->pos;
                pos.y += 200.0f;
            }
            scene = func_001b9120();
            work[3] = (s32)func_001a91b0(*(void**)(scene + 0x11f8), &pos);
            scene = func_001b9120();
            func_001a9390(*(void**)(scene + 0x11f8), (void*)work[3], 3);
            work[4] = func_001ad930(((FldUnit*)work[1])->resrc->collisCtlTask);
            work[2] = 1;
            goto done;
        }
        if (func_00318ed0(((FldUnit*)work[1])->mdl, 2, &pos) == 0)
        {
            pos = ((RwMatrix*)func_00318b60(((FldUnit*)work[1])->mdl))->pos;
            pos.y += 200.0f;
        }
        deadline = (u32)work[4] + 0x960;
        now = func_001ad930(((FldUnit*)work[1])->resrc->collisCtlTask);
        if (deadline < now)
        {
            hp = func_0016c5f0((s16)((FldUnit*)work[1])->charId);
            damage = (s32)(f32)hp;
            damage = (s32)((f32)damage / 20.0f);
            if (damage < 1) damage = 1;
            finalDamage = (s32)func_0016c4f0((s16)((FldUnit*)work[1])->charId) - damage;
            pcId = (s16)((FldUnit*)work[1])->charId;
            if (finalDamage < 1) finalDamage = 1;
            func_0016cf40(pcId, (s16)finalDamage);
            work[4] = func_001ad930(
                ((FldUnit*)work[1])->resrc->collisCtlTask);
        }
        {
            RwRGBA sourceColor;
            colorData = (u8*)func_00318b00(((FldUnit*)work[1])->mdl);
            sourceColor = *(RwRGBA*)colorData;
            colors[1].a = sourceColor.a;
        }
        func_00318ad0(((FldUnit*)work[1])->mdl, &colors[1]);
        scene = func_001b9120();
        func_001a92d0(*(void**)(scene + 0x11f8), (void*)work[3], &pos);
    }
    else
    {
        {
            RwRGBA sourceColor;
            colorData = (u8*)func_00318b00(((FldUnit*)work[1])->mdl);
            sourceColor = *(RwRGBA*)colorData;
            colors[0].a = sourceColor.a;
        }
        func_00318ad0(((FldUnit*)work[1])->mdl, &colors[0]);
        if (work[2] == 1)
        {
            work[2] = 0;
            scene = func_001b9120();
            func_001a9400(*(void**)(scene + 0x11f8), (void*)work[3]);
        }
    }
done:
    return NULL;
}

// FUN_001d40b0
void func_001d40b0(KwlnTask* task)
{
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001d40e0
KwlnTask* func_001d40e0(KwlnTask* parent, FldUnit* unit)
{
    s32* work;
    KwlnTask* task;

    work = (s32*)((void* (*)(u32, u32, u32))DAT_00960184[0])(1, 0x14, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)func_00194b80(parent, 10, DAT_006839d8,
                                    func_001d3ce0, func_001d40b0, work);
    work[1] = (s32)unit;
    return task;
}

// FUN_001d4180 NONMATCHING
void func_001d4180(void)
{
    s32 i;
    u32 hasResources;
    s32* work;
    u8* scene;
    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        hasResources = false;
        {
            FldUnit* unit;

            unit = &gFldUnitsPc[i];
            if (unit->genusBase != NULL && unit->resrc != NULL)
            {
                hasResources = true;
            }
        }
        hasResources = (hasResources != 0);
        if (hasResources)
        {
            KwlnTask** taskSlot;

            taskSlot = &gFldUnitsPc[i].unk_180;
            if (*taskSlot != NULL)
            {
                work = (s32*)(*taskSlot)->workData;
                if (work[2] == 1)
                {
                    work[2] = 0;
                    scene = func_001b9120();
                    func_001a9400(*(void**)(scene + 0x11f8), (void*)work[3]);
                }
                if (*taskSlot != NULL)
                {
                    func_00195020(gFldUnitsPc[i].unk_180);
                    gFldUnitsPc[i].unk_180 = NULL;
                }
            }
        }
    }
}

// FUN_001d4290
void func_001d4290(void)
{
    char path[128];
    HCdvd* object;
    u32 fileSize;
    void* fileMemory;

    if (func_0017d800() == 0)
    {
        func_00523ac8(path, DAT_006839f0);
    }
    else
    {
        func_00523ac8(path, DAT_00683a10);
    }
    if (func_001008b0(path) != 0)
    {
        object = (HCdvd*)func_00100d80(path, 0);
        func_001023a0(object);
        DAT_007ce290 = DAT_00871ec0;
        fileSize = ((volatile /* Removing this function's qualifier batch loses func_001d4290 (MATCH nd0 -> MISMATCH nd4, size 200 -> 200) - measured W170. */ HCdvd*)object)->fileSize;
        fileMemory = ((volatile /* Removing this function's qualifier batch loses func_001d4290 (MATCH nd0 -> MISMATCH nd4, size 200 -> 200) - measured W170. */ HCdvd*)object)->fileMemory;
        func_00521250(DAT_00871ec0, fileMemory, fileSize);
        DAT_007ce294 = DAT_007ce290 + 0x180;
        func_00100ec0(object);
    }
}
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
