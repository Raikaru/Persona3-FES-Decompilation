#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_shadow.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Graphics/Model/mdlManager.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "rw/rwcore.h"
#include "rw/rwplcore.h"
#include "temporary.h"

#include "Kosaka/k_window.h"
#include "h_dbprt.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
extern u32 D_00960184_y2[];
extern void (*D_0096017c)(void* memory);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u32 uGpffffb450;
extern u32 uGpffffb454;
extern u32 gp0xffff9460;
extern u32 gp0xffff9464;
extern u32 gp0xffff9468;
extern u32 gp0xffff946c;
extern u32 gp0xffff9470;
extern u32 gp0xffff9474;
extern u32 gp0xffff9478;
extern u32 gp0xffff947c;
extern u32 gp0xffff9480;
extern u8 gp0xffff9484;
extern const char gp0xffff9488[];
extern const char gp0xffff9490[];
extern const char gp0xffff9498[];
extern const char gp0xffff94a0[];
extern const char gp0xffff94a8[];
extern const char gp0xffff94b0[];
extern const char gp0xffff94b8[];
extern u32 uGpffff94c4;
extern void func_00524270_y2(void* destination, const void* source);
extern s32 func_00524388(const char* text);
extern f32 func_00530da0(f32 value);
extern void func_0019d3f0(const char* file, s32 line);
extern void func_00494cc0(void* colorData);
extern void func_001e7a60(void* renderData);
extern void* func_001a1550(KwlnTask* task);
extern f32 func_001e7c20(s32 scale);
extern void func_001e7b10(void* quad, f32 scale);
extern void func_004933d0(void* renderLayout);
extern void func_00493370(void* renderLayout, s32 state);
extern f32 func_001a4600(void* camera);
extern u32 func_00195790(void);
extern void func_004d7f60(s32 state, u32 value);
extern void (*D_00960090)(u32 state, u32 value);
extern RwCamera* kwlnGetMainCamera_y2(void);
typedef struct KWindowQuad
{
    RwV3d vertex[4];
} KWindowQuad;
typedef struct KWindowQuadStore
{
    u8 unknown00[0x14];
    KWindowQuad* quad;
} KWindowQuadStore;
typedef struct KWindowRenderLayout
{
    u8 unknown00[0x30];
    RwRGBA* tileColors;
    u8 unknown34[0x28];
    KWindowQuadStore* quadStore;
} KWindowRenderLayout;
typedef struct KWindowRenderData
{
    u8 unknown00[0x18];
    KWindowRenderLayout* layout;
} KWindowRenderData;
typedef void (*KWindowEntryCallback)(void* value);
typedef struct KWindowEntry
{
    s32 id;                         /* 0x000 */
    s32 type;                       /* 0x004 */
    char name[0x100];               /* 0x008 */
    char text[0x100];               /* 0x108 */
    s32 intValue;                   /* 0x208 */
    f32 floatValue;                 /* 0x20c */
    s32 minValue;                   /* 0x210 */
    s32 maxValue;                   /* 0x214 */
    s32 flags;                      /* 0x218 */
    KWindowEntryCallback callback;  /* 0x21c */
    void* callbackValue;            /* 0x220 */
    struct KWindowEntry* previous;  /* 0x224 */
    struct KWindowEntry* next;      /* 0x228 */
} KWindowEntry;
typedef struct KWindowManagerWork
{
    s32 state;                      /* 0x00 */
    u32 flags;                      /* 0x04 */
    s32 mode;                       /* 0x08 */
    u32 request;                    /* 0x0c */
    s32 x;                          /* 0x10 */
    s32 y;                          /* 0x14 */
    s32 width;                      /* 0x18 */
    s32 height;                     /* 0x1c */
    void* renderData;               /* 0x20 */
    void* colorData;                /* 0x24 */
    KwlnTask* windowTask;           /* 0x28 */
    s32 firstVisible;               /* 0x2c */
    s32 cursor;                     /* 0x30 */
    s32 visibleRows;                /* 0x34 */
    s32 entryCount;                 /* 0x38 */
    KWindowEntry* entries;          /* 0x3c */
    s32 nextId;                     /* 0x40 */
} KWindowManagerWork;
typedef struct KWindowEntryDescriptor
{
    const char* name;
    s32 type;
    const char* text;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    KWindowEntryCallback callback;
} KWindowEntryDescriptor;
extern void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...);
extern void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA color, const char* fmt, ...);
#pragma alias H_Dbprt_FmtCol3D_f32 H_Dbprt_FmtCol3D
extern void H_Dbprt_FmtCol3D_f32(RwV2d pos, RwRGBA color, const char* fmt, f32 value);
extern void func_00524270_y2(void* destination, const void* source);
extern void (*D_0096017c)(void* object);
#pragma alias D_0096017c_abs D_0096017c
extern u32 D_0096017c_abs[];
extern const char D_00678AF8[];
extern const char D_00678B08[];
extern const char D_00678B18[];
extern const char D_00678B30[];
static const char sKWindowValueLabel[] = "%s";
static const char sKWindowType2Label[] = "off";
static const char sKWindowType3Label[] = "%d";
static const char sKWindowType4Label[] = "%.2f";
static const char sKWindowTextLabel[] = "%s";
void* func_001a2a80(KwlnTask* task);
void func_001a3a60(KwlnTask* task);
void func_001a44a0(KwlnTask* task);
KwlnTask* func_001a3b10(KwlnTask* parent, u32 width, u32 height, u32 mode);
void func_001a3c30(KwlnTask* task);
u32 func_001a3f20(KwlnTask* task, const char* name);
char* func_001a4010(KwlnTask* task, s32 id);
void func_001a4050(KwlnTask* task, u32 id, KWindowEntryCallback callback);
void func_001a4090(KwlnTask* task, u32 id, const char* text);
void func_001a4110(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue, s32 flags);
s32* func_001a41b0(KwlnTask* task, u32 id);
void func_001a41f0(KwlnTask* task, u32 id, s32 value);
void func_001a4260(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue);
KWindowEntry* func_001a4330(KwlnTask* task, s32 id);
s32 func_001a4510(KwlnTask* task);
static inline void KWindow_ApplyValueDelta(KWindowEntry* entry, s32 delta,
                                    f32 floatDelta)
{
    f32 value;

    if (entry == NULL)
    {
        return;
    }

    if (entry->type == 4)
    {
        value = entry->floatValue + floatDelta;
        if (value < (f32)entry->minValue)
        {
            value = (f32)entry->maxValue;
        }
        else if (value > (f32)entry->maxValue)
        {
            value = (f32)entry->minValue;
        }
        entry->floatValue = value;
    }
    else if (entry->type == 3)
    {
        entry->intValue += delta;
        if (entry->intValue < entry->minValue)
        {
            entry->intValue = entry->maxValue;
        }
        else if (entry->intValue > entry->maxValue)
        {
            entry->intValue = entry->minValue;
        }
    }
    else if (entry->type == 2)
    {
        entry->intValue = (entry->intValue == 1) ? 0 : 1;
    }
}


#pragma alias D_0096017c_y2 D_0096017c
#pragma alias D_00960184_y2 D_00960184_y2
#pragma alias func_00524270_y2 func_00524270_y2
#pragma alias kwlnGetMainCamera_y2 kwlnGetMainCamera_y2


extern RpLight* func_00198580();
extern RwRGBAReal* func_0019fd70();
extern RwMatrix* func_0019fda0();
extern s32 func_001a7660(void* param);
extern s32 func_001a76e0(void* param);
extern void func_001a8b10(u32* param);
extern void func_001b3e50(RwCamera* camera, void* fieldData);
extern void func_001b4720(RwCamera* camera, void* fieldData);
extern void func_001bd950();
extern void func_00317a20(Model* mdl);
extern s32 func_00318ed0(Model* mdl, s32 param, RwV3d* position);
extern void func_00319230(Model* mdl, s32 param);
extern void func_0034fd30(Model* mdl);
extern void func_001b56f0(void* fieldData, const void* color);
extern void func_001b5950(void* fieldData, const void* position);
extern void func_001b5990(void* fieldData, const void* position);
extern void func_001b59c0(void* fieldData, const void* position);
extern void func_001b5a00(void* fieldData, const void* position);
extern void* func_001e78c0(s32 width, s32 height);
extern void func_001e7aa0(void* work, s32 index, void* data);
extern void* func_00494be0(void);
extern void func_004c31b0(f32 angle, RwMatrix* matrix, const RwV3d* axis, RwOpCombineType combineOp);
extern void func_004cb270(void* cameraData);
extern void* func_004d0f00(void* resource);
extern void* func_004d1110(void* manager, void* object);
extern void* func_004d1170(void* manager, void* object);
extern void* func_004d11f0(void);
extern void func_00524270(void* texture, void* object);
extern void* D_00960184[];
extern void func_005225a8();
extern void* D_0096017c_y2[];
void func_001a0040(u32 visible, u32 updateField);
u32 func_001a02c0();
extern void func_0034fd70(Model* mdl, s32 param);
extern void func_0034fdf0(Model* mdl, RwV3d* position);
extern void func_00521408(void* dst, s32 value, u32 size);
extern void func_004944b0(RpLight* light, const RwRGBAReal* color);
extern void func_0049c3d0(RpWorld* world, RpLight* light);
extern void func_0049c480(RpWorld* world, RpLight* light);
s32 func_0019db10(KwlnTask* task);
s32 func_0019de80(KwlnTask* task);
#pragma alias uGpffffb3dc gCurrWorldIdx
extern u32 uGpffffb3dc;
s32 func_0019e1f0(const void* charPtr1, const void* charPtr2);
extern u32 gUnk_008668f0[];
extern f32 fGpffff80e0;
extern f32 fGpffff8084;
extern u8 DAT_007ce0e8;
extern u8 DAT_007ce0ec;
extern u8 DAT_007ce0f0;
extern u8 DAT_007ce0f4;

typedef struct SceneDrawObject
{
    u8 unk_00[0x10];
    u8 data[0x40];
    u8 type;
} SceneDrawObject;

#define SCENEDRAW_RESRC_PTR(resource, type, offset) (*(type**)((u8*)(resource) + (offset)))
#define SCENEDRAW_RESRC_COLOR(resource, offset)     ((RwRGBAReal*)((u8*)(resource) + (offset)))
#define SCENEDRAW_RESRC_MATRIX(resource, offset)    ((RwMatrix*)((u8*)(resource) + (offset)))

#define SCENEDRAW_RESRC_FLAG_VISIBLE         0x00000002
#define SCENEDRAW_RESRC_FLAG_DRAW_BASE        0x20000000
#define SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT     0x80000000
#define SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY 0x40000000
#define SCENEDRAW_RESRC_FLAG_PERSONA          0x00010000
#define SCENEDRAW_RESRC_TYPE_MODELFLD2        11
#define SCENEDRAW_MAX_SORTED_MODELS            64

// FUN_0019d410
void* K_SceneDraw_UpdateDrwOpcFldTask(KwlnTask* drwOpcFldTask)
{
    ResrcFld* fld;
    Field* field;

    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    field = K_Field_Get();
    if (*(s32*)((u8*)field + 0x34) == 0)
    {
        func_001bd950();
    }

    while (fld != NULL)
    {
        if (fld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
        {
            func_001b3e50(kwlnGetMainCamera(), fld->unk_160);
        }

        fld = (ResrcFld*)fld->base.next;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0019d4a0
void* K_SceneDraw_UpdateDrwTrnsFldTask(KwlnTask* drwTrnsFldTask)
{
    ResrcFld* fld;

    if (gMtScene->fldMajorId < 200)
    {
        fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
        while (fld != NULL)
        {
            if (fld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
            {
                func_001b4720(kwlnGetMainCamera(), fld->unk_160);
            }

            fld = (ResrcFld*)fld->base.next;
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0019d530
void* K_SceneDraw_UpdateDrwTrnsFldSrtTask(KwlnTask* drwTrnsFldSrtTask)
{
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;

    if (gUnk_008668f0[0] == 0)
    {
        return KWLNTASK_CONTINUE;
    }

    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;

    func_004944b0(kwlnGetAmbientLight(), K_Scene_GetFldAmbLightColor());
    func_004944b0(kwlnGetDirectionalLight(), (const RwRGBAReal*)func_0019fd70());
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     (const RwMatrix*)func_0019fda0(),
                     rwCOMBINEREPLACE);
    kwlnGetDirectionalLight()->object.object.flags = 3;
    kwlnGetDirectionalLight();

    func_0049c480(kwlnGetWorld(gCurrWorldIdx), func_00198580());
    if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
    {
        func_001a8b10(gUnk_008668f0);
        RwCameraEndUpdate(kwlnGetMainCamera());
    }

    func_0049c3d0(kwlnGetWorld(gCurrWorldIdx), func_00198580());
    func_004944b0(kwlnGetAmbientLight(), &ambientColor);
    func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     &directionalMatrix,
                     rwCOMBINEREPLACE);
    kwlnGetDirectionalLight()->object.object.flags = 3;
    kwlnGetDirectionalLight();

    return KWLNTASK_CONTINUE;
}

// FUN_0019d780
void* K_SceneDraw_UpdateDrwOpcFldObjTask(KwlnTask* drwOpcFldObjTask)
{
    ResrcModelFld* modelFld;
    ResrcModelFld* modelFld2;
    ResrcFld* fld;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;

    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    modelFld2 = (ResrcModelFld*)MT_Scene_GetResListHead(SCENEDRAW_RESRC_TYPE_MODELFLD2);
    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);

    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;

    if (fld == NULL)
    {
        return KWLNTASK_CONTINUE;
    }

    func_0049c480(kwlnGetWorld(gCurrWorldIdx), func_00198580());
    func_004944b0(kwlnGetAmbientLight(), K_Scene_GetFldAmbLightColor());
    func_004944b0(kwlnGetDirectionalLight(), (const RwRGBAReal*)func_0019fd70());
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     (const RwMatrix*)func_0019fda0(),
                     rwCOMBINEREPLACE);

    if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
    {
        while (modelFld != NULL)
        {
            if (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
            {
                if (func_001a7660(modelFld->mdl->unk_e0) == 0)
                {
                    func_00317a20(modelFld->mdl);
                    if (SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c) != NULL &&
                        (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                    {
                        func_00317a20(SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c));
                    }
                }
            }

            modelFld = (ResrcModelFld*)modelFld->base.next;
        }

        RwCameraEndUpdate(kwlnGetMainCamera());
    }
    else
    {
        K_Assert("k_sceneDraw.c", 0x100);
    }

    func_0049c3d0(kwlnGetWorld(gCurrWorldIdx), func_00198580());
    func_004944b0(kwlnGetAmbientLight(), &ambientColor);
    func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     &directionalMatrix,
                     rwCOMBINEREPLACE);

    while (modelFld2 != NULL)
    {
        if (modelFld2->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
        {
            func_0034fd30(modelFld2->mdl);
            func_0034fd70(modelFld2->mdl, 3);
        }

        modelFld2 = (ResrcModelFld*)modelFld2->base.next;
    }

    if (gMtScene->fldMajorId >= 200)
    {
        fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
        while (fld != NULL)
        {
            if (fld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
            {
                func_001b4720(kwlnGetMainCamera(), fld->unk_160);
            }

            fld = (ResrcFld*)fld->base.next;
        }

        func_0019de80(drwOpcFldObjTask);
        func_0019db10(drwOpcFldObjTask);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0019db10
s32 func_0019db10(KwlnTask* task)
{
    ResrcModelFld* modelFld;
    ResrcFld* fld;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRenderStateSetFunc* setRenderState;

    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;

    if (fld == NULL)
    {
        return 0;
    }
    
        func_0049c480(kwlnGetWorld(uGpffffb3dc), func_00198580());
        func_004944b0(kwlnGetAmbientLight(), K_Scene_GetFldAmbLightColor());
        func_004944b0(kwlnGetDirectionalLight(), (const RwRGBAReal*)func_0019fd70());
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         (const RwMatrix*)func_0019fda0(),
                         rwCOMBINEREPLACE);

        if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
        {
            if (uGpffffb3dc == 1)
            {
                setRenderState = &rwGlobals.device.setRenderState;
                (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
                (*setRenderState)(rwRENDERSTATEFOGCOLOR,
                                  (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
                (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)true);
            }

            while (modelFld != NULL)
            {
                if (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
                {
                    if (func_001a7660(modelFld->mdl->unk_e0) == 1)
                    {
                        func_00317a20(modelFld->mdl);
                        if (SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c) != NULL &&
                            (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                        {
                            func_00317a20(SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c));
                        }
                    }
                }

                modelFld = (ResrcModelFld*)modelFld->base.next;
            }

            RwCameraEndUpdate(kwlnGetMainCamera());
        }
        else
        {
            K_Assert("k_sceneDraw.c", 0x151);
        }

        func_0049c3d0(kwlnGetWorld(uGpffffb3dc), func_00198580());
        func_004944b0(kwlnGetAmbientLight(), &ambientColor);
        func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         &directionalMatrix,
                         rwCOMBINEREPLACE);
    return 0;
}

// FUN_0019de40
void* K_SceneDraw_UpdateDrwTrnsFldObjTask(KwlnTask* drwTrnsFldObjTask)
{
    if (gMtScene->fldMajorId < 200)
    {
        func_0019db10(drwTrnsFldObjTask);
    }

    return KWLNTASK_CONTINUE;
}
// FUN_0019de80
s32 func_0019de80(KwlnTask* task)
{
    ResrcModelFld* modelFld;
    ResrcFld* fld;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRenderStateSetFunc* setRenderState;

    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;

    if (fld == NULL)
    {
        return 0;
    }
        func_0049c480(kwlnGetWorld(uGpffffb3dc), func_00198580());
        func_004944b0(kwlnGetAmbientLight(), K_Scene_GetFldAmbLightColor());
        func_004944b0(kwlnGetDirectionalLight(), (const RwRGBAReal*)func_0019fd70());
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         (const RwMatrix*)func_0019fda0(),
                         rwCOMBINEREPLACE);

        if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
        {
            if (uGpffffb3dc == 1)
            {
                setRenderState = &rwGlobals.device.setRenderState;
                (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
                (*setRenderState)(rwRENDERSTATEFOGCOLOR,
                                  (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
                (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)true);
            }

            while (modelFld != NULL)
            {
                if (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
                {
                    if (func_001a76e0(modelFld->mdl->unk_e0) == 1)
                    {
                        func_00317a20(modelFld->mdl);
                        if (SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c) != NULL &&
                            (modelFld->base.flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                        {
                            func_00317a20(SCENEDRAW_RESRC_PTR(modelFld, Model, 0x12c));
                        }
                    }
                }

                modelFld = (ResrcModelFld*)modelFld->base.next;
            }

            RwCameraEndUpdate(kwlnGetMainCamera());
        }
        else
        {
            K_Assert("k_sceneDraw.c", 0x198);
        }

        func_0049c3d0(kwlnGetWorld(uGpffffb3dc), func_00198580());
        func_004944b0(kwlnGetAmbientLight(), &ambientColor);
        func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         &directionalMatrix,
                         rwCOMBINEREPLACE);

    return 0;
}
// FUN_0019e1b0
void* K_SceneDraw_UpdateDrwTrnsFldObjPCTask(KwlnTask* drwTrnsFldObjPCTask)
{
    if (gMtScene->fldMajorId < 200)
    {
        func_0019de80(drwTrnsFldObjPCTask);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0019e1f0
s32 func_0019e1f0(const void* charPtr1, const void* charPtr2)
{
    RwFrame* cameraFrame;
    const ResrcModelChar* char1;
    const ResrcModelChar* char2;
    RwV3d diffToCam1;
    RwV3d diffToCam2;
    RwV3d cameraPos;

    cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    cameraPos = RwFrameGetLTM(cameraFrame)->pos;

    char1 = *(const ResrcModelChar**)charPtr1;
    char2 = *(const ResrcModelChar**)charPtr2;

    diffToCam1.x = mdlGetMatrix(char1->mdl)->pos.x - cameraPos.x;
    diffToCam1.y = mdlGetMatrix(char1->mdl)->pos.y - cameraPos.y;
    diffToCam1.z = mdlGetMatrix(char1->mdl)->pos.z - cameraPos.z;

    diffToCam2.x = mdlGetMatrix(char2->mdl)->pos.x - cameraPos.x;
    diffToCam2.y = mdlGetMatrix(char2->mdl)->pos.y - cameraPos.y;
    diffToCam2.z = mdlGetMatrix(char2->mdl)->pos.z - cameraPos.z;

    return (s32)(RwV3dLength(&diffToCam1) - RwV3dLength(&diffToCam2));
}

#pragma push
/* Removing this worsens K_SceneDraw_UpdateDrwChrMdlTask (nd1774 -> nd1777) - measured W161. */
#pragma opt_common_subs on
// FUN_0019e330 NONMATCHING
void* K_SceneDraw_UpdateDrwChrMdlTask(KwlnTask* drwChrMdlTask)
{
    ResrcModelChar* charRes;
    ResrcModelChar* charList[SCENEDRAW_MAX_SORTED_MODELS] = { NULL };
    ResrcModelNpc* npcRes;
    ResrcModelNpc* npcList;
    Resrc* modelUnk;
    ResrcLightNpc* npcLight;
    ResrcLightChar* charLight;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRGBAReal secondaryDirectionalColor;
    RwMatrix secondaryDirectionalMatrix;
    RwV3d position;
    s32 charCount;
    s32 i;
    s32 slot;
    u32 flags;

    charRes = (ResrcModelChar*)MT_Scene_GetResListHead(RESRC_TYPE_MODELCHAR);
    npcList = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    modelUnk = MT_Scene_GetResListHead(RESRC_TYPE_MODELUNK);
    npcLight = (ResrcLightNpc*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    charLight = (ResrcLightChar*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);

    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;
    secondaryDirectionalColor = func_00198580()->color;
    secondaryDirectionalMatrix = ((RwFrame*)func_00198580()->object.object.parent)->modelling;

    charCount = 0;
    while (charRes != NULL)
    {
        if ((u32)charCount >= SCENEDRAW_MAX_SORTED_MODELS)
        {
            K_Assert("k_sceneDraw.c", 0x1d7);
        }

        charList[charCount] = charRes;
        charRes = (ResrcModelChar*)charRes->base.next;
        charCount++;
    }

    if (gMtScene->shouldSortChars == true)
    {
        qsort(charList, charCount, sizeof(charList[0]), func_0019e1f0);
    }

    for (i = charCount - 1; i >= 0; i--)
    {
        func_004944b0(kwlnGetAmbientLight(), &charLight->ambientColor);
        func_004944b0(func_00198580(), &charLight->directionalColor);
        func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(charLight, 0x160));
        RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                         SCENEDRAW_RESRC_MATRIX(charLight, 0x120),
                         rwCOMBINEREPLACE);
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         SCENEDRAW_RESRC_MATRIX(charLight, 0x170),
                         rwCOMBINEREPLACE);

        charRes = charList[i];
        flags = charRes->base.flags;
        if (flags & SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT)
        {
            func_004944b0(kwlnGetAmbientLight(), SCENEDRAW_RESRC_COLOR(charRes, 0x12c));
            func_004944b0(func_00198580(), SCENEDRAW_RESRC_COLOR(charRes, 0x13c));
            func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(charRes, 0x190));
            RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(charRes, 0x150),
                             rwCOMBINEREPLACE);
            RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(charRes, 0x1a0),
                             rwCOMBINEREPLACE);
        }
        else if (flags & SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY)
        {
            func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(charRes, 0x190));
            RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(charRes, 0x1a0),
                             rwCOMBINEREPLACE);
        }
        else
        {
            func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(charLight, 0x160));
            RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(charLight, 0x170),
                             rwCOMBINEREPLACE);
        }

        if (flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
        {
            if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
            {
                func_00317a20(charRes->mdl);
                if (charRes->baseMdl != NULL && (flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                {
                    func_00317a20(charRes->baseMdl);
                }

                for (slot = 0; slot < 3; slot++)
                {
                    if (SCENEDRAW_RESRC_PTR(charRes, Model, 0x100 + slot * sizeof(Model*)) != NULL)
                    {
                        if (func_00318ed0(charRes->mdl, 2, &position) == 0)
                        {
                            position = mdlGetMatrix(charRes->mdl)->pos;
                            position.y += 175.0f;
                        }

                        func_0034fdf0(SCENEDRAW_RESRC_PTR(charRes, Model, 0x100 + slot * sizeof(Model*)), &position);
                        func_0034fd70(SCENEDRAW_RESRC_PTR(charRes, Model, 0x100 + slot * sizeof(Model*)), 5);
                    }
                }

                RwCameraEndUpdate(kwlnGetMainCamera());
            }
            else
            {
                K_Assert("k_sceneDraw.c", 0x225);
            }
        }
    }

    if (npcList != NULL)
    {
        func_004944b0(kwlnGetAmbientLight(), &npcLight->ambColor);
        func_004944b0(func_00198580(), &npcLight->dirColor);
        func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(npcLight, 0x160));
        RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                         SCENEDRAW_RESRC_MATRIX(npcLight, 0x120),
                         rwCOMBINEREPLACE);
        RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                         SCENEDRAW_RESRC_MATRIX(npcLight, 0x170),
                         rwCOMBINEREPLACE);

        if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
        {
            npcRes = npcList;
            while (npcRes != NULL)
            {
                if (mdlGetColor(npcRes->mdl)->a == 255)
                {
                    flags = npcRes->base.flags;
                    if (!(flags & SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT) &&
                        (flags & SCENEDRAW_RESRC_FLAG_VISIBLE))
                    {
                        func_00317a20(npcRes->mdl);
                        if (npcRes->baseMdl != NULL && (flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                        {
                            func_00317a20(npcRes->baseMdl);
                        }

                        for (slot = 0; slot < 3; slot++)
                        {
                            if (SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)) != NULL)
                            {
                                if (func_00318ed0(npcRes->mdl, 2, &position) == 0)
                                {
                                    position = mdlGetMatrix(npcRes->mdl)->pos;
                                    position.y += 175.0f;
                                }

                                func_0034fdf0(SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)), &position);
                                func_0034fd70(SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)), 5);
                            }
                        }
                    }
                }

                npcRes = (ResrcModelNpc*)npcRes->base.next;
            }

            RwCameraEndUpdate(kwlnGetMainCamera());
        }
        else
        {
            K_Assert("k_sceneDraw.c", 0x262);
        }
    }

    npcRes = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    while (npcRes != NULL)
    {
        if (mdlGetColor(npcRes->mdl)->a == 255)
        {
            flags = npcRes->base.flags;
            if ((flags & SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT) &&
                (flags & SCENEDRAW_RESRC_FLAG_VISIBLE))
            {
                func_004944b0(kwlnGetAmbientLight(), SCENEDRAW_RESRC_COLOR(npcRes, 0x12c));
                func_004944b0(func_00198580(), SCENEDRAW_RESRC_COLOR(npcRes, 0x13c));
                func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(npcRes, 0x190));
                RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(npcRes, 0x150),
                                 rwCOMBINEREPLACE);
                RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(npcRes, 0x1a0),
                                 rwCOMBINEREPLACE);

                if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
                {
                    func_00317a20(npcRes->mdl);
                    if (npcRes->baseMdl != NULL && (flags & SCENEDRAW_RESRC_FLAG_DRAW_BASE))
                    {
                        func_00317a20(npcRes->baseMdl);
                    }

                    for (slot = 0; slot < 3; slot++)
                    {
                        if (SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)) != NULL)
                        {
                            if (func_00318ed0(npcRes->mdl, 2, &position) == 0)
                            {
                                position = mdlGetMatrix(npcRes->mdl)->pos;
                                position.y += 175.0f;
                            }

                            func_0034fdf0(SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)), &position);
                            func_0034fd70(SCENEDRAW_RESRC_PTR(npcRes, Model, 0x100 + slot * sizeof(Model*)), 5);
                        }
                    }

                    RwCameraEndUpdate(kwlnGetMainCamera());
                }
                else
                {
                    K_Assert("k_sceneDraw.c", 0x299);
                }
            }
        }

        npcRes = (ResrcModelNpc*)npcRes->base.next;
    }

    while (modelUnk != NULL)
    {
        flags = modelUnk->flags;
        if ((flags & SCENEDRAW_RESRC_FLAG_VISIBLE) &&
            (flags & SCENEDRAW_RESRC_FLAG_PERSONA))
        {
            func_004944b0(kwlnGetAmbientLight(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x11c));
            func_004944b0(func_00198580(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x12c));
            func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x180));
            RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(modelUnk, 0x140),
                             rwCOMBINEREPLACE);
            RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(modelUnk, 0x190),
                             rwCOMBINEREPLACE);

            if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
            {
                func_00319230(SCENEDRAW_RESRC_PTR(modelUnk, Model, 0x118), 3);
                func_00317a20(SCENEDRAW_RESRC_PTR(modelUnk, Model, 0x118));
                RwCameraEndUpdate(kwlnGetMainCamera());
            }
            else
            {
                K_Assert("k_sceneDraw.c", 0x2b7);
            }
        }

        modelUnk = modelUnk->next;
    }

    func_004944b0(kwlnGetAmbientLight(), &ambientColor);
    func_004944b0(func_00198580(), &secondaryDirectionalColor);
    func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
    RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                     &secondaryDirectionalMatrix,
                     rwCOMBINEREPLACE);
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     &directionalMatrix,
                     rwCOMBINEREPLACE);

    return KWLNTASK_CONTINUE;
}
/* Closes the `#pragma push` / `opt_common_subs on` opened above
 * K_SceneDraw_UpdateDrwChrMdlTask.  Measured W418: closing here is metric-neutral
 * for every other function in this file, while leaving the scope open let the knob
 * govern the remaining 2603 lines of the translation unit. */
#pragma pop

// FUN_0019ee40
s32 K_SceneDraw_CompareNpcDistToCamera(const void* npcPtr1, const void* npcPtr2)
{
    RwFrame* camFrame;
    const ResrcModelNpc* npc1;
    const ResrcModelNpc* npc2;
    RwV3d diffToCam1;
    RwV3d diffToCam2;
    RwV3d camPos;

    camFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    camPos = RwFrameGetLTM(camFrame)->pos;

    npc1 = *(const ResrcModelNpc**)npcPtr1;
    npc2 = *(const ResrcModelNpc**)npcPtr2;

    diffToCam1.x = mdlGetMatrix(npc1->mdl)->pos.x - camPos.x;
    diffToCam1.y = mdlGetMatrix(npc1->mdl)->pos.y - camPos.y;
    diffToCam1.z = mdlGetMatrix(npc1->mdl)->pos.z - camPos.z;

    diffToCam2.x = mdlGetMatrix(npc2->mdl)->pos.x - camPos.x;
    diffToCam2.y = mdlGetMatrix(npc2->mdl)->pos.y - camPos.y;
    diffToCam2.z = mdlGetMatrix(npc2->mdl)->pos.z - camPos.z;

    return (s32)(RwV3dLength(&diffToCam1) - RwV3dLength(&diffToCam2));
}

// W415 census negative: direct R_MIPS_26 calls are 50/50 with retail after resolving RwFrameTransform to 0x004cb7f0; the SDK symbol remains unmappable, so no call edit is justified.
// FUN_0019ef80 NONMATCHING
void* K_SceneDraw_UpdateDrwTrnsNpcSrtTask(KwlnTask* drwTrnsNpcSrtTask)
{
    ResrcModelNpc* npcRes;
    ResrcModelNpc** npcEntry;
    ResrcLightNpc* npcLight;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRGBAReal secondaryDirectionalColor;
    RwMatrix secondaryDirectionalMatrix;
    RwV3d position;
    s32 npcCount;
    s32 slot;
    u32 flags;
    ResrcModelNpc* npcList[SCENEDRAW_MAX_SORTED_MODELS];

    npcRes = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    npcLight = (ResrcLightNpc*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;
    secondaryDirectionalColor = func_00198580()->color;
    secondaryDirectionalMatrix = ((RwFrame*)func_00198580()->object.object.parent)->modelling;
    func_00521408(npcList, 0, sizeof(npcList));

    npcCount = 0;
    while (npcRes != NULL)
    {
        if (mdlGetColor(npcRes->mdl)->a < 255)
        {
            npcList[npcCount] = npcRes;
            npcCount++;
        }

        npcRes = (ResrcModelNpc*)npcRes->base.next;
    }

    if (gMtScene->shouldSortNpcs == true)
    {
        qsort(npcList, npcCount, sizeof(npcList[0]), K_SceneDraw_CompareNpcDistToCamera);
    }

    for (npcCount--; npcCount >= 0; npcCount--)
    {
        npcEntry = &npcList[npcCount];
        flags = (*npcEntry)->base.flags;
        if (flags & SCENEDRAW_RESRC_FLAG_VISIBLE)
        {
            if (flags & SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT)
            {
                func_004944b0(kwlnGetAmbientLight(), SCENEDRAW_RESRC_COLOR(*npcEntry, 0x12c));
                func_004944b0(func_00198580(), SCENEDRAW_RESRC_COLOR(*npcEntry, 0x13c));
                func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(*npcEntry, 0x190));
                RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(*npcEntry, 0x150),
                                 rwCOMBINEREPLACE);
                RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(*npcEntry, 0x1a0),
                                 rwCOMBINEREPLACE);
            }
            else
            {
                func_004944b0(kwlnGetAmbientLight(), &npcLight->ambColor);
                func_004944b0(func_00198580(), &npcLight->dirColor);
                func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(npcLight, 0x160));
                RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(npcLight, 0x120),
                                 rwCOMBINEREPLACE);
                RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                                 SCENEDRAW_RESRC_MATRIX(npcLight, 0x170),
                                 rwCOMBINEREPLACE);
            }

            if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
            {
                func_00317a20((*npcEntry)->mdl);
                for (slot = 0; slot < 3; slot++)
                {
                    if (SCENEDRAW_RESRC_PTR(*npcEntry, Model, 0x100 + slot * sizeof(Model*)) != NULL)
                    {
                        if (func_00318ed0((*npcEntry)->mdl, 2, &position) == 0)
                        {
                            position = mdlGetMatrix((*npcEntry)->mdl)->pos;
                            position.y += 175.0f;
                        }

                        func_0034fdf0(SCENEDRAW_RESRC_PTR(*npcEntry, Model, 0x100 + slot * sizeof(Model*)), &position);
                        func_0034fd70(SCENEDRAW_RESRC_PTR(*npcEntry, Model, 0x100 + slot * sizeof(Model*)), 5);
                    }
                }

                RwCameraEndUpdate(kwlnGetMainCamera());
            }
            else
            {
                K_Assert("k_sceneDraw.c", 0x335);
            }
        }
    }

    func_004944b0(kwlnGetAmbientLight(), &ambientColor);
    func_004944b0(func_00198580(), &secondaryDirectionalColor);
    func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
    RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                     &secondaryDirectionalMatrix,
                     rwCOMBINEREPLACE);
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     &directionalMatrix,
                     rwCOMBINEREPLACE);

    return KWLNTASK_CONTINUE;
}

// FUN_0019f470
void* K_SceneDraw_UpdateDrwPrsnaMdlTask(KwlnTask* drwPrsnaMdlTask)
{
    Resrc* modelUnk;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRGBAReal secondaryDirectionalColor;
    RwMatrix secondaryDirectionalMatrix;
    u32 flags;

    modelUnk = MT_Scene_GetResListHead(RESRC_TYPE_MODELUNK);
    ambientColor = kwlnGetAmbientLight()->color;
    directionalColor = kwlnGetDirectionalLight()->color;
    directionalMatrix = ((RwFrame*)kwlnGetDirectionalLight()->object.object.parent)->modelling;
    secondaryDirectionalColor = func_00198580()->color;
    secondaryDirectionalMatrix = ((RwFrame*)func_00198580()->object.object.parent)->modelling;

    while (modelUnk != NULL)
    {
        flags = modelUnk->flags;
        if ((flags & SCENEDRAW_RESRC_FLAG_VISIBLE) &&
            !(flags & SCENEDRAW_RESRC_FLAG_PERSONA))
        {
            func_004944b0(kwlnGetAmbientLight(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x11c));
            func_004944b0(func_00198580(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x12c));
            func_004944b0(kwlnGetDirectionalLight(), SCENEDRAW_RESRC_COLOR(modelUnk, 0x180));
            RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(modelUnk, 0x140),
                             rwCOMBINEREPLACE);
            RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                             SCENEDRAW_RESRC_MATRIX(modelUnk, 0x190),
                             rwCOMBINEREPLACE);

            if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
            {
                func_00319230(*(Model**)((u32*)modelUnk + 70), 3);
                func_00317a20(*(Model**)((s32)modelUnk + 0x118));
                RwCameraEndUpdate(kwlnGetMainCamera());
            }
            else
            {
                K_Assert("k_sceneDraw.c", 0x36b);
            }
        }

        modelUnk = modelUnk->next;
    }

    func_004944b0(kwlnGetAmbientLight(), &ambientColor);
    func_004944b0(func_00198580(), &secondaryDirectionalColor);
    func_004944b0(kwlnGetDirectionalLight(), &directionalColor);
    RwFrameTransform((RwFrame*)func_00198580()->object.object.parent,
                     &secondaryDirectionalMatrix,
                     rwCOMBINEREPLACE);
    RwFrameTransform((RwFrame*)kwlnGetDirectionalLight()->object.object.parent,
                     &directionalMatrix,
                     rwCOMBINEREPLACE);

    return KWLNTASK_CONTINUE;
}

// FUN_0019f730
KwlnTask* K_SceneDraw_CreateTasks(KwlnTask* rootProcTask)
{
    KwlnTask* sceneDrawTask;

    sceneDrawTask = kwlnTaskCreateWithAutoPriority(rootProcTask, 10, "scene draw CTL", NULL, NULL, NULL);

    FldShadow_CreateShadowMapTask(sceneDrawTask);
    kwlnTaskCreate(sceneDrawTask, "draw opac field", 2070, K_SceneDraw_UpdateDrwOpcFldTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw opac field object", 2071, K_SceneDraw_UpdateDrwOpcFldObjTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw character model", 2084, K_SceneDraw_UpdateDrwChrMdlTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw trans field obj preChar", 2095, K_SceneDraw_UpdateDrwTrnsFldObjPCTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw persona model", 4168, K_SceneDraw_UpdateDrwPrsnaMdlTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw trans field object", 4172, K_SceneDraw_UpdateDrwTrnsFldObjTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw trans field", 4173, K_SceneDraw_UpdateDrwTrnsFldTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw trans field(sort)", 4183, K_SceneDraw_UpdateDrwTrnsFldSrtTask, NULL, NULL);
    kwlnTaskCreate(sceneDrawTask, "draw trans NPC(sort)", 4183, K_SceneDraw_UpdateDrwTrnsNpcSrtTask, NULL, NULL);

    return sceneDrawTask;
}

// FUN_0019f8f0
void func_0019f8f0(const RwRGBAReal* color)
{
    ResrcFld* fld;
    RwRGBA clearColor;
    u32 fogColor;
    s32 clearRed;
    s32 clearGreen;
    s32 clearBlue;
    s32 clearAlpha;
    s32 fogRed;
    s32 fogGreen;
    s32 fogBlue;
    s32 fogAlpha;

    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    while (fld != NULL)
    {
        func_001b56f0(fld->unk_160, color);
        fld = (ResrcFld*)fld->base.next;
    }

    if ((color->r <= 0.0f && color->g <= 0.0f && color->b <= 0.0f) || color->a <= 0.0f)
    {
        func_001a0040(0, 1);
    }
    else
    {
        func_001a0040(1, 1);
    }

    clearColor = *kwlnGetClearColor();
    fogColor = ((u32)DAT_007ce0f4 << 24) |
               ((u32)DAT_007ce0e8 << 16) |
               ((u32)DAT_007ce0ec << 8) |
               (u32)DAT_007ce0f0;

    clearRed = (s32)((f32)clearColor.r * color->r);
    clearGreen = (s32)((f32)clearColor.g * color->g);
    clearBlue = (s32)((f32)clearColor.b * color->b);
    clearAlpha = (s32)((f32)clearColor.a * color->a);

    if ((u32)clearAlpha > 0xff) clearAlpha = 0xff;
    if ((u32)clearBlue > 0xff) clearBlue = 0xff;
    if ((u32)clearGreen > 0xff) clearGreen = 0xff;
    if ((u32)clearRed > 0xff) clearRed = 0xff;
    kwlnSetClearColor((u8)clearRed, (u8)clearGreen, (u8)clearBlue, (u8)clearAlpha);

    fogRed = (s32)((f32)((fogColor >> 16) & 0xff) * color->r);
    fogGreen = (s32)((f32)((fogColor >> 8) & 0xff) * color->g);
    fogBlue = (s32)((f32)(fogColor & 0xff) * color->b);
    fogAlpha = (s32)((f32)((fogColor >> 24) & 0xff) * color->a);

    if ((u32)fogRed > 0xff) fogRed = 0xff;
    gFogRed = (u8)fogRed;
    if ((u32)fogGreen > 0xff) fogGreen = 0xff;
    gFogGreen = (u8)fogGreen;
    if ((u32)fogBlue > 0xff) fogBlue = 0xff;
    gFogBlue = (u8)fogBlue;
    if ((u32)fogAlpha > 0xff) fogAlpha = 0xff;
    gFogAlpha = (u8)fogAlpha;
}

// FUN_0019fd40
RwRGBAReal* K_Scene_GetFldAmbLightColor()
{
    ResrcFld* res;

    res = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    return &res->ambLightColor;
}

// FUN_0019fd70
RwRGBAReal* func_0019fd70()
{
    ResrcFld* res;

    res = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    return &res->dirLightColor;
}

// FUN_0019fda0
RwMatrix* func_0019fda0()
{
    ResrcFld* res;

    res = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    return &res->dirLightMat;
}

// FUN_0019fdd0
void func_0019fdd0(const void* position)
{
    MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    func_001b5950(gMtScene->fldFilterTask, position);
}
// FUN_0019fe20
void func_0019fe20(const void* position)
{
    MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    func_001b5990(gMtScene->fldFilterTask, position);
}

// FUN_0019fe70
void func_0019fe70(const void* position)
{
    MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    func_001b59c0(gMtScene->fldFilterTask, position);
}

// FUN_0019fec0
void func_0019fec0(const void* position)
{
    MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    func_001b5a00(gMtScene->fldFilterTask, position);
}

// FUN_0019ff10
void func_0019ff10()
{
    Resrc* res;
    RwRGBAReal* ambientColor;
    RwRGBAReal* directionalColor;
    RwMatrix* directionalMatrix;
    f32 ambientValue;
    f32 directionalValue;
    RwV3d axis;
    res = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    ambientColor = (RwRGBAReal*)((u8*)res + 0x100);
    res = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    directionalColor = (RwRGBAReal*)((u8*)res + 0x110);
    res = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    directionalMatrix = (RwMatrix*)((u8*)res + 0x120);
    ambientValue = fGpffff80e0;
    directionalValue = 0.5f;

    ambientColor->r = ambientValue;
    ambientColor->g = ambientValue;
    ambientColor->b = ambientValue;
    ambientColor->a = 0.0f;
    directionalColor->r = directionalValue;
    directionalColor->g = directionalValue;
    directionalColor->b = directionalValue;
    directionalColor->a = 0.0f;
    RwMatrixSetIdentity(directionalMatrix);

    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    func_004c31b0(-180.0f, directionalMatrix, &axis, rwCOMBINEPOSTCONCAT);
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    func_004c31b0(-45.0f, directionalMatrix, &axis, rwCOMBINEPOSTCONCAT);
}

// FUN_001a0040 NONMATCHING
void func_001a0040(u32 visible, u32 updateField)
{
    Resrc* fld;
    Resrc* modelFld;
    Field* field;

    fld = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    modelFld = MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    while (fld != NULL)
    {
        if (visible == 1)
        {
            fld->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
            field = K_Field_Get();
            *(u32*)((u8*)field + 0x34) = 0;
        }
        else
        {
            fld->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
            field = K_Field_Get();
            *(u32*)((u8*)field + 0x34) = 1;
        }
        fld = fld->next;
    }

    if (updateField == 1)
    {
        while (modelFld != NULL)
        {
            if (visible == 1)
            {
                modelFld->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
            }
            else
            {
                modelFld->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
            }
            modelFld = modelFld->next;
        }
    }
}

// FUN_001a0150
void func_001a0150(u16 resTypeId, u32 visible)
{
    Resrc* res;

    res = MT_Scene_GetRes(resTypeId);
    if (res != NULL)
    {
        if (visible == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
        }
    }
}

// FUN_001a01c0
u32 func_001a01c0()
{
    if (K_Scene_001a0250() == 1)
    {
        return true;
    }
    if (func_001a02c0() == 1)
    {
        return true;
    }
    if (gMtScene->fldMajorId >= 30 && gMtScene->fldMajorId <= 38)
    {
        return true;
    }
    return false;
}

// FUN_001a0250
u32 K_Scene_001a0250()
{
    s32 fldMajor;

    fldMajor = gMtScene->fldMajorId;

    if ((fldMajor >= 21 && fldMajor <= 28 && gMtScene->fldMinorId == 0) ||
        (fldMajor >= 41 && fldMajor <= 48 && gMtScene->fldMinorId == 0))
    {
        return true;
    }

    return false;
}

// FUN_001a02c0
u32 func_001a02c0()
{
    s32 fldMajor;

    fldMajor = gMtScene->fldMajorId;
    if ((fldMajor >= 51 && fldMajor <= 58) || (fldMajor >= 71 && fldMajor <= 78))
    {
        return true;
    }

    return false;
}

// FUN_001a0310
u32 func_001a0310()
{
    if ((gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 3) ||
        (gMtScene->fldMajorId == 32 && gMtScene->fldMinorId == 2) ||
        (gMtScene->fldMajorId == 26 && gMtScene->fldMinorId == 51) ||
        (gMtScene->fldMajorId == 26 && gMtScene->fldMinorId == 52) ||
        (gMtScene->fldMajorId == 26 && gMtScene->fldMinorId == 53) ||
        (gMtScene->fldMajorId == 37 && gMtScene->fldMinorId == 1) ||
        (gMtScene->fldMajorId == 35 && gMtScene->fldMinorId == 1) ||
        gMtScene->fldMajorId == 4 ||
        gMtScene->fldMajorId == 5)
    {
        return true;
    }

    return false;
}

// FUN_001a0410
void K_Scene_SetShouldSortChars(u32 shouldSortChars)
{
    gMtScene->shouldSortChars = shouldSortChars;
}

// FUN_001a0420
void K_Scene_SetShouldSortNpcs(u32 shouldSortNpcs)
{
    gMtScene->shouldSortNpcs = shouldSortNpcs;
}

// FUN_001a0430
void func_001a0430(u16 resTypeId, u32 customLight)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1) res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
    }
}
// FUN_001a0590
void func_001a0590(u16 resTypeId, u32 directionalOnly)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1) res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
    }
}

// FUN_001a0700
void* func_001a0700(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x12c;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x12c;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x11c;
    }
    return NULL;
}

// FUN_001a07f0
void* func_001a07f0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x180;
    }
    return NULL;
}

// FUN_001a08e0
void* func_001a08e0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1a0;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1a0;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngGetRes(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    return NULL;
}

// FUN_001a09d0
RwRGBAReal* func_001a09d0()
{
    ResrcLightChar* res;

    res = (ResrcLightChar*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        return (RwRGBAReal*)((u8*)res + 0x100);
    }
    return NULL;
}

// FUN_001a0a10
RwRGBAReal* K_Scene_GetCharAmbLightColor()
{
    ResrcLightChar* res;

    res = (ResrcLightChar*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        return &res->directionalColor;
    }

    return NULL;
}

// FUN_001a0a50
RwMatrix* func_001a0a50()
{
    ResrcLightChar* res;

    res = (ResrcLightChar*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        return (RwMatrix*)((u8*)res + 0x120);
    }
    return NULL;
}

// FUN_001a0a90
void K_Scene_InitCharLight()
{
    RwRGBAReal* ambientColor;
    RwRGBAReal* directionalColor;
    RwMatrix* directionalMat;
    RwV4d* unk160;
    RwV4d* unk170;
    Resrc* res;
    f32 ambientValue;
    f32 directionalValue;
    RwV3d axis;

    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        ambientColor = (RwRGBAReal*)((u8*)res + 0x100);
    }
    else
    {
        ambientColor = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        directionalColor = (RwRGBAReal*)((u8*)res + 0x110);
    }
    else
    {
        directionalColor = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        directionalMat = (RwMatrix*)((u8*)res + 0x120);
    }
    else
    {
        directionalMat = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        unk160 = (RwV4d*)((u8*)res + 0x160);
    }
    else
    {
        unk160 = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTCHAR);
    if (res != NULL)
    {
        unk170 = (RwV4d*)((u8*)res + 0x170);
    }
    else
    {
        unk170 = NULL;
    }
    ambientValue = fGpffff80e0;

    ambientColor->r = ambientValue;
    ambientColor->g = ambientValue;
    ambientColor->b = ambientValue;
    ambientColor->a = 0.0f;
    directionalValue = fGpffff8084;
    directionalColor->r = directionalValue;
    directionalColor->g = directionalValue;
    directionalColor->b = directionalValue;
    directionalColor->a = 0.0f;
    unk160->x = 0.0f;
    unk160->y = 0.0f;
    unk160->z = 0.0f;
    unk160->w = 0.0f;
    RwMatrixSetIdentity(directionalMat);
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    func_004c31b0(-180.0f, directionalMat, &axis, rwCOMBINEPOSTCONCAT);
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    func_004c31b0(-45.0f, directionalMat, &axis, rwCOMBINEPOSTCONCAT);
    RwMatrixSetIdentity((RwMatrix*)unk170);
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    func_004c31b0(-180.0f, (RwMatrix*)unk170, &axis, rwCOMBINEPOSTCONCAT);
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    func_004c31b0(-45.0f, (RwMatrix*)unk170, &axis, rwCOMBINEPOSTCONCAT);
}

// FUN_001a0d00
RwRGBAReal* func_001a0d00()
{
    ResrcLightNpc* res;

    res = (ResrcLightNpc*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        return (RwRGBAReal*)((u8*)res + 0x100);
    }
    return NULL;
}

// FUN_001a0d40
RwRGBAReal* func_001a0d40()
{
    ResrcLightNpc* res;

    res = (ResrcLightNpc*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        return (RwRGBAReal*)((u8*)res + 0x110);
    }
    return NULL;
}

// FUN_001a0d80
RwMatrix* func_001a0d80()
{
    ResrcLightNpc* res;

    res = (ResrcLightNpc*)MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        return (RwMatrix*)((u8*)res + 0x120);
    }
    return NULL;
}

// FUN_001a0dc0
void func_001a0dc0(u16 resTypeId, u32 visible)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = resrcMngGetRes(gMtScene->resManager, resTypeId);
    goto setFlags;

done:
    return;

setFlags:
    if (visible == 1)
    {
        res->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
    }
    else
    {
        res->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
    }
}

// FUN_001a0e50
void func_001a0e50(u16 resTypeId, u32 persona)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = resrcMngGetRes(gMtScene->resManager, resTypeId);
    goto setFlags;

done:
    return;

setFlags:
    if (persona == 1)
    {
        res->flags |= SCENEDRAW_RESRC_FLAG_PERSONA;
    }
    else
    {
        res->flags &= ~SCENEDRAW_RESRC_FLAG_PERSONA;
    }
}

// FUN_001a0ee0
void K_Scene_InitNpcLight()
{
    RwRGBAReal* ambientColor;
    RwRGBAReal* directionalColor;
    RwMatrix* directionalMat;
    RwV4d* unk160;
    RwV4d* unk170;
    Resrc* res;
    f32 ambientValue;
    f32 directionalValue;
    RwV3d axis;
    extern f32 fGpffff808c;

    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        ambientColor = (RwRGBAReal*)((u8*)res + 0x100);
    }
    else
    {
        ambientColor = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        directionalColor = (RwRGBAReal*)((u8*)res + 0x110);
    }
    else
    {
        directionalColor = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        directionalMat = (RwMatrix*)((u8*)res + 0x120);
    }
    else
    {
        directionalMat = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        unk160 = (RwV4d*)((u8*)res + 0x160);
    }
    else
    {
        unk160 = NULL;
    }
    res = MT_Scene_GetResListHead(RESRC_TYPE_LIGHTNPC);
    if (res != NULL)
    {
        unk170 = (RwV4d*)((u8*)res + 0x170);
    }
    else
    {
        unk170 = NULL;
    }
    ambientValue = fGpffff808c;

    ambientColor->r = ambientValue;
    ambientColor->g = ambientValue;
    ambientColor->b = ambientValue;
    ambientColor->a = 0.0f;
    directionalValue = 0.5f;
    directionalColor->r = directionalValue;
    directionalColor->g = directionalValue;
    directionalColor->b = directionalValue;
    directionalColor->a = 0.0f;
    unk160->x = 0.0f;
    unk160->y = 0.0f;
    unk160->z = 0.0f;
    unk160->w = 0.0f;
    RwMatrixSetIdentity(directionalMat);
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    RwMatrixRotate(directionalMat, &axis, -180.0f, rwCOMBINEPOSTCONCAT);
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    RwMatrixRotate(directionalMat, &axis, -45.0f, rwCOMBINEPOSTCONCAT);
    RwMatrixSetIdentity((RwMatrix*)unk170);
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    RwMatrixRotate((RwMatrix*)unk170, &axis, -180.0f, rwCOMBINEPOSTCONCAT);
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    RwMatrixRotate((RwMatrix*)unk170, &axis, -45.0f, rwCOMBINEPOSTCONCAT);
}
// FUN_001a1150
u32 func_001a1150()
{
    Resrc* res;
    u32 value;

    res = MT_Scene_GetResListHead(RESRC_TYPE_20);
    value = 0;
    if (res != NULL)
    {
        value = *(u32*)((u8*)res + 0x108);
    }
    return value;
}

// FUN_001a1190
f32 func_001a1190()
{
    Resrc* res;
    f32 value;

    res = MT_Scene_GetResListHead(RESRC_TYPE_20);
    value = 0.0f;
    if (res != NULL)
    {
        value = *(f32*)((u8*)res + 0x104);
    }
    return value;
}

// FUN_001a11d0
u32 func_001a11d0()
{
    Resrc* res;
    u32 value;

    res = MT_Scene_GetResListHead(RESRC_TYPE_20);
    value = (res != NULL);
    if (value != 0)
    {
        value = *(u32*)((u8*)res + 0x100) == 1;
    }
    return value;
}


// FUN_001a1210 NONMATCHING
void func_001a1210(RwCamera* camera, const RwV3d* target, const RwV3d* position, const RwV3d* upVector)
{
    RwV3d defaultUp;
    RwFrame* data;
    RwMatrix* right;
    RwV3d* up;

    up = &defaultUp;
    *(s64*)&defaultUp = *(s64*)0x00678ab8;
    defaultUp.z = *(f32*)0x00678ac0;
    if (upVector != NULL)
    {
        up = (RwV3d*)upVector;
    }

    data = camera->object.object.parent;
    right = &data->modelling;
    data->modelling.pos = *target;
    right->at.x = position->x - data->modelling.pos.x;
    right->at.y = position->y - data->modelling.pos.y;
    right->at.z = position->z - data->modelling.pos.z;
    RwV3dNormalize(&right->at, &right->at);

    right->right.x = right->at.y * up->z - right->at.z * up->y;
    right->right.y = up->x * right->at.z - up->z * right->at.x;
    right->right.z = up->y * right->at.x - up->x * right->at.y;
    RwV3dNormalize(&right->right, &right->right);
    right->up.x = right->at.y * right->right.z - right->at.z * right->right.y;
    right->up.y = right->at.z * right->right.x - right->at.x * right->right.z;
    right->up.z = right->at.x * right->right.y - right->at.y * right->right.x;
    RwV3dNormalize(&right->up, &right->up);
    RwMatrixUpdate(right);
    func_004cb270(data);
}

// FUN_001a13b0
void* func_001a13b0(SceneDrawObject* object, void** listHead)
{
    void* allocation;
    void** tail;
    u8 type;

    type = object->type;
    func_005225a8("draw object", object->data, type);
    if (func_004d1170(func_004d11f0(), object->data) != NULL)
    {
        return object;
    }

    func_004d1110(func_004d11f0(), object);
    allocation = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0x44, 0x40000);
    func_00524270(allocation, object->data);
    if (*listHead == NULL)
    {
        *listHead = allocation;
    }
    else
    {
        tail = (void**)((u8*)*listHead + 0x40);
        while (*tail != NULL)
        {
            tail = (void**)((u8*)*tail + 0x40);
        }
        *tail = allocation;
    }

    return object;
}

// FUN_001a14c0
void func_001a14c0(void* list)
{
    void* next;
    void* manager;
    void* resource;
    void* current;

    current = list;
    while (current != NULL)
    {
        next = *(void**)((u8*)current + 0x40);
        manager = func_004d11f0();
        resource = func_004d1170(manager, current);
        func_004d0f00(resource);
        (*(void (**)(void*))D_0096017c_y2)(current);
        current = next;
    }
}

// FUN_001a1540
void* func_001a1540()
{
    return KWLNTASK_CONTINUE;
}








/* W419 negative: swapping func_001a1550 owner/work declarations left nd2042/object2844/window3104 and the 0x80/s5..s0 prologue unchanged. */
// FUN_001a1550 NONMATCHING
void* func_001a1550(KwlnTask* task)
{
    KwlnTask* owner;
    KWindowTaskWork* work;

    owner = task;
    work = (KWindowTaskWork*)owner->workData;
    switch (work->state)
    {
        case 0:
        {
            f32 tileColor;
            s32 i;
            KWindowQuad* quad;
            u8* tile;

            work->renderData = func_001e78c0(5, 0x48);
            work->colorDataA = func_00494be0();
            ((RwRGBA*)((u8*)work->colorDataA + 4))->r = work->colorA.r;
            ((RwRGBA*)((u8*)work->colorDataA + 4))->g = work->colorA.g;
            ((RwRGBA*)((u8*)work->colorDataA + 4))->b = work->colorA.b;
            ((RwRGBA*)((u8*)work->colorDataA + 4))->a = work->colorA.a;
            work->colorDataB = func_00494be0();

            work->alphaStep = (f32)(s32)work->colorB.a;
            work->colorB.a = 0;
            ((RwRGBA*)((u8*)work->colorDataB + 4))->r = work->colorB.r;
            ((RwRGBA*)((u8*)work->colorDataB + 4))->g = work->colorB.g;
            ((RwRGBA*)((u8*)work->colorDataB + 4))->b = work->colorB.b;
            ((RwRGBA*)((u8*)work->colorDataB + 4))->a = work->colorB.a;

            tileColor = *(f32*)((u8*)&gp0xffff9460 - 4);
            i = 0;
            while (i < 4)
            {
                func_001e7aa0(work->renderData, i, work->colorDataA);
                tile = (u8*)((KWindowRenderData*)work->renderData)->layout->tileColors + i * 16;
                tile[0] = ((u8*)&tileColor)[0];
                tile[1] = ((u8*)&tileColor)[1];
                tile[2] = ((u8*)&tileColor)[2];
                tile[3] = ((u8*)&tileColor)[3];
                tile[4] = ((u8*)&tileColor)[0];
                tile[5] = ((u8*)&tileColor)[1];
                tile[6] = ((u8*)&tileColor)[2];
                tile[7] = ((u8*)&tileColor)[3];
                tile[8] = ((u8*)&tileColor)[0];
                tile[9] = ((u8*)&tileColor)[1];
                tile[10] = ((u8*)&tileColor)[2];
                tile[11] = ((u8*)&tileColor)[3];
                tile[12] = ((u8*)&tileColor)[0];
                tile[13] = ((u8*)&tileColor)[1];
                tile[14] = ((u8*)&tileColor)[2];
                tile[15] = ((u8*)&tileColor)[3];
                quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad + i;
                quad->vertex[0].x = 0.0f;
                quad->vertex[0].y = 0.0f;
                quad->vertex[1].x = 0.0f;
                quad->vertex[1].y = 0.0f;
                quad->vertex[2].x = 0.0f;
                quad->vertex[2].y = 0.0f;
                quad->vertex[3].x = 0.0f;
                quad->vertex[3].y = 0.0f;
                func_001e7b10(quad, func_001e7c20(-16));
                i++;
            }

            func_001e7aa0(work->renderData, 4, work->colorDataB);
            tile = (u8*)((KWindowRenderData*)work->renderData)->layout->tileColors + 0x40;
            tile[0] = ((u8*)&tileColor)[0];
            tile[1] = ((u8*)&tileColor)[1];
            tile[2] = ((u8*)&tileColor)[2];
            tile[3] = ((u8*)&tileColor)[3];
            tile[4] = ((u8*)&tileColor)[0];
            tile[5] = ((u8*)&tileColor)[1];
            tile[6] = ((u8*)&tileColor)[2];
            tile[7] = ((u8*)&tileColor)[3];
            tile[8] = ((u8*)&tileColor)[0];
            tile[9] = ((u8*)&tileColor)[1];
            tile[10] = ((u8*)&tileColor)[2];
            tile[11] = ((u8*)&tileColor)[3];
            tile[12] = ((u8*)&tileColor)[0];
            tile[13] = ((u8*)&tileColor)[1];
            tile[14] = ((u8*)&tileColor)[2];
            tile[15] = ((u8*)&tileColor)[3];
            quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad + 4;
            quad->vertex[0].x = (f32)work->rect.x;
            quad->vertex[0].y = (f32)work->rect.y;
            quad->vertex[1].x = (f32)(work->rect.x + work->rect.w);
            quad->vertex[1].y = (f32)work->rect.y;
            quad->vertex[2].x = (f32)work->rect.x;
            quad->vertex[2].y = (f32)(work->rect.y + work->rect.h);
            quad->vertex[3].x = (f32)(work->rect.x + work->rect.w);
            quad->vertex[3].y = (f32)(work->rect.y + work->rect.h);
            func_001e7b10(quad, func_001e7c20(-32));
            func_004933d0(((KWindowRenderData*)work->renderData)->layout);
            work->horizontalOffset = 0.0f;
            work->verticalOffset = 0.0f;
            work->horizontalInset = 0.0f;
            work->verticalInset = 0.0f;
            work->state = 1;
            break;
        }

        case 1:
        {
            KWindowRenderData* renderData;
            KWindowQuad* quad;

            renderData = (KWindowRenderData*)work->renderData;
            func_00493370(renderData->layout, 2);
            if (work->horizontalOffset >= (f32)work->rect.w)
            {
                work->horizontalOffset = (f32)work->rect.w;
                work->state++;
            }
            quad = renderData->layout->quadStore->quad;
            quad[0].vertex[0].x = (f32)work->rect.x;
            quad[0].vertex[0].y = (f32)work->rect.y;
            quad[0].vertex[1].x = (f32)work->rect.x + work->horizontalOffset;
            quad[0].vertex[1].y = (f32)work->rect.y;
            quad[0].vertex[2].x = (f32)work->rect.x;
            quad[0].vertex[2].y = (f32)(work->rect.y + 2);
            quad[0].vertex[3].x = (f32)work->rect.x + work->horizontalOffset;
            quad[0].vertex[3].y = (f32)(work->rect.y + 2);
            func_001e7b10(&quad[0], func_001e7c20(-16));
            work->horizontalOffset += (f32)work->rect.w / 2.0f;
            func_004933d0(renderData->layout);
            break;
        }

        case 2:
        {
            KWindowRenderData* renderData;
            KWindowQuad* quad;

            renderData = (KWindowRenderData*)work->renderData;
            func_00493370(renderData->layout, 2);
            if (work->verticalOffset >= (f32)work->rect.h)
            {
                work->verticalOffset = (f32)work->rect.h;
                work->state++;
            }
            quad = renderData->layout->quadStore->quad + 1;
            quad->vertex[0].x = (f32)(work->rect.x + work->rect.w - 2);
            quad->vertex[0].y = (f32)work->rect.y;
            quad->vertex[1].x = (f32)(work->rect.x + work->rect.w);
            quad->vertex[1].y = (f32)work->rect.y;
            quad->vertex[2].x = (f32)(work->rect.x + work->rect.w - 2);
            quad->vertex[2].y = (f32)work->rect.y + work->verticalOffset;
            quad->vertex[3].x = (f32)(work->rect.x + work->rect.w);
            quad->vertex[3].y = (f32)work->rect.y + work->verticalOffset;
            func_001e7b10(quad, func_001e7c20(-16));
            work->verticalOffset += (f32)work->rect.h / 2.0f;
            func_004933d0(renderData->layout);
            break;
        }

        case 3:
        {
            KWindowRenderData* renderData;
            KWindowQuad* quad;

            renderData = (KWindowRenderData*)work->renderData;
            func_00493370(renderData->layout, 2);
            if (work->horizontalInset >= (f32)work->rect.w)
            {
                work->horizontalInset = (f32)work->rect.w;
                work->state++;
            }
            quad = renderData->layout->quadStore->quad + 2;
            quad->vertex[0].x = (f32)work->rect.x;
            quad->vertex[0].y = (f32)(work->rect.y + work->rect.h - 2);
            quad->vertex[1].x = (f32)work->rect.x + work->horizontalInset;
            quad->vertex[1].y = (f32)(work->rect.y + work->rect.h - 2);
            quad->vertex[2].x = (f32)work->rect.x;
            quad->vertex[2].y = (f32)(work->rect.y + work->rect.h);
            quad->vertex[3].x = (f32)work->rect.x + work->horizontalInset;
            quad->vertex[3].y = (f32)(work->rect.y + work->rect.h);
            func_001e7b10(quad, func_001e7c20(-16));
            work->horizontalInset += (f32)work->rect.w / 2.0f;
            func_004933d0(renderData->layout);
            break;
        }

        case 4:
        {
            KWindowRenderData* renderData;
            KWindowQuad* quad;

            renderData = (KWindowRenderData*)work->renderData;
            func_00493370(renderData->layout, 2);
            if (work->verticalInset >= (f32)work->rect.h)
            {
                work->verticalInset = (f32)work->rect.h;
                work->state++;
            }
            quad = renderData->layout->quadStore->quad + 3;
            quad->vertex[0].x = (f32)work->rect.x;
            quad->vertex[0].y = (f32)work->rect.y + work->rect.h - work->verticalInset;
            quad->vertex[1].x = (f32)(work->rect.x + 2);
            quad->vertex[1].y = (f32)work->rect.y + work->rect.h - work->verticalInset;
            quad->vertex[2].x = (f32)work->rect.x;
            quad->vertex[2].y = (f32)(work->rect.y + work->rect.h);
            quad->vertex[3].x = (f32)(work->rect.x + 2);
            quad->vertex[3].y = (f32)(work->rect.y + work->rect.h);
            func_001e7b10(quad, func_001e7c20(-16));
            work->verticalInset += (f32)work->rect.h / 2.0f;
            func_004933d0(renderData->layout);
            break;
        }

        case 5:
        {
            s32 alpha;
            f32 alphaValue;
            RwRGBA* colorB;

            if (work->colorB.a < (u8)work->alphaStep)
            {
                alpha = work->colorB.a;
                // colorB.a is u8, so alpha is never negative; use a plain float cast.
                alphaValue = (f32)alpha;
            }
            else
            {
                work->colorB.a = (u8)work->alphaStep;
                work->state++;
            }
            colorB = (RwRGBA*)((u8*)work->colorDataB + 4);
            colorB->r = work->colorB.r;
            colorB->g = work->colorB.g;
            colorB->b = work->colorB.b;
            colorB->a = work->colorB.a;
            break;
        }

        case 6:
            func_001a23e0(owner, &work->rect);
            work->state++;
            break;

        case 7:
        {
            RwRGBA* colorA;
            RwRGBA* colorB;
            colorA = (RwRGBA*)((u8*)work->colorDataA + 4);
            colorB = (RwRGBA*)((u8*)work->colorDataB + 4);
            if (work->colorB.a > 0)
            {
                work->colorB.a--;
            }
            if (work->colorA.a > 0)
            {
                work->colorA.a--;
            }
            colorA->r = work->colorA.r;
            colorA->g = work->colorA.g;
            colorA->b = work->colorA.b;
            colorA->a = work->colorA.a;
            colorB->r = work->colorB.r;
            colorB->g = work->colorB.g;
            colorB->b = work->colorB.b;
            colorB->a = work->colorB.a;
            if (work->colorA.a == 0 && work->colorB.a == 0)
            {
                work->state++;
            }
            break;
        }

        case 8:
            return KWLNTASK_STOP;
    }

    if (work->fieldOfView != func_001a4600(kwlnGetMainCamera_y2()))
    {
        func_001a23e0(owner, &work->rect);
    }
    if (func_00195790() == 1 && work->request == 1)
    {
        void (**stateFunc)(u32 state, u32 value);

        stateFunc = (void (**)(u32, u32))D_00960090_abs;
        (*stateFunc)(6, 0);
        (*stateFunc)(8, 0);
        func_004d7f60(2, 0x44);
        func_004d7f60(3, 0x717fb);
        (*(void (**)(void))((u8*)work->renderData + 0x48))();
    }
    return KWLNTASK_CONTINUE;
}


 

// FUN_001A2170
void func_001a2170(KwlnTask* task)
{
    KWindowTaskWork* work;
    void (**freeSlot)(void*);

    work = (KWindowTaskWork*)task->workData;
    func_00494cc0(work->colorDataA);
    func_00494cc0(work->colorDataB);
    func_001e7a60(work->renderData);
    freeSlot = (void (**)(void*))((u8*)&rwGlobals + 0x17c);
    (*freeSlot)(work->buffer);
    (*freeSlot)(task->workData);
}

// FUN_001A2200
KwlnTask* func_001a2200(KwlnTask* parent, const RwRect* rect, const RwRGBA* colorA, const RwRGBA* colorB)
{
    KwlnTask* task;
    KWindowTaskWork* work;
    void* (**callocFunc)(u32, u32, u32);
    s32* bufferSize;
    void** buffer;

    callocFunc = &((RwGlobals*)rwGlobals_abs)->memFuncs.RwCalloc;
    work = (*callocFunc)(1, sizeof(KWindowTaskWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          0x106F,
                                          "ksk window",
                                          func_001a1550,
                                          func_001a2170,
                                          work);
    work->request = 1;
    work->rect = *rect;
    work->colorA = *colorA;
    work->colorB = *colorB;
    bufferSize = &work->bufferSize;
    *bufferSize = (rect->x / 8) * (rect->y / 8) + 0x20;
    buffer = &work->buffer;
    *buffer = (*callocFunc)(1, *bufferSize, rwMEMHINTDUR_GLOBAL);
    work->bufferAlias = *buffer;

    return task;
}

// FUN_001A2390
u32 func_001a2390(const KwlnTask* task)
{
    const KWindowTaskWork* work;

    work = (const KWindowTaskWork*)task->workData;
    if (work->state == 6)
    {
        goto zero;
    }
    if (work->state != 8)
    {
        goto one;
    }
zero:
    return 0;
one:
    return 1;
}

// FUN_001A23D0
void func_001a23d0(KwlnTask* task, u32 request)
{
    KWindowTaskWork* work;

    work = (KWindowTaskWork*)task->workData;
    work->request = request;
}

// FUN_001A23E0 NONMATCHING
void func_001a23e0(KwlnTask* task, const RwRect* rect)
{
    KWindowTaskWork* work;
    RwRect localRect;

    localRect = *rect;
    work = (KWindowTaskWork*)task->workData;
    if (work->state != 6)
    {
        return;
    }

    func_00493370(((KWindowRenderData*)work->renderData)->layout, 2);

    {
        KWindowQuad* quad;

        quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad;
        quad[0].vertex[0].x = (f32)localRect.x;
        quad[0].vertex[0].y = (f32)localRect.y;
        quad[0].vertex[1].x = (f32)(localRect.x + localRect.w);
        quad[0].vertex[1].y = (f32)localRect.y;
        quad[0].vertex[2].x = (f32)localRect.x;
        quad[0].vertex[2].y = (f32)(localRect.y + 2);
        quad[0].vertex[3].x = (f32)(localRect.x + localRect.w);
        quad[0].vertex[3].y = (f32)(localRect.y + 2);
        func_001e7b10(&quad[0], func_001e7c20(-16));
    }

    {
        KWindowQuad* quad;

        quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad;
        quad[1].vertex[0].x = (f32)(localRect.x + localRect.w - 2);
        quad[1].vertex[0].y = (f32)localRect.y;
        quad[1].vertex[1].x = (f32)(localRect.x + localRect.w);
        quad[1].vertex[1].y = (f32)localRect.y;
        quad[1].vertex[2].x = (f32)(localRect.x + localRect.w - 2);
        quad[1].vertex[2].y = (f32)(localRect.y + 2);
        quad[1].vertex[3].x = (f32)(localRect.x + localRect.w);
        quad[1].vertex[3].y = (f32)(localRect.y + 2);
        func_001e7b10(&quad[1], func_001e7c20(-16));
    }

    {
        KWindowQuad* quad;

        quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad;
        quad[2].vertex[0].x = (f32)localRect.x;
        quad[2].vertex[0].y = (f32)(localRect.y + localRect.h - 2);
        quad[2].vertex[1].x = (f32)(localRect.x + localRect.w);
        quad[2].vertex[1].y = (f32)(localRect.y + localRect.h - 2);
        quad[2].vertex[2].x = (f32)localRect.x;
        quad[2].vertex[2].y = (f32)(localRect.y + localRect.h);
        quad[2].vertex[3].x = (f32)(localRect.x + localRect.w);
        quad[2].vertex[3].y = (f32)(localRect.y + localRect.h);
        func_001e7b10(&quad[2], func_001e7c20(-16));
    }

    {
        KWindowQuad* quad;

        quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad;
        quad[3].vertex[0].x = (f32)localRect.x;
        quad[3].vertex[0].y = (f32)(localRect.y + localRect.h - 2);
        quad[3].vertex[1].x = (f32)(localRect.x + 2);
        quad[3].vertex[1].y = (f32)(localRect.y + localRect.h - 2);
        quad[3].vertex[2].x = (f32)localRect.x;
        quad[3].vertex[2].y = (f32)(localRect.y + localRect.h);
        quad[3].vertex[3].x = (f32)(localRect.x + 2);
        quad[3].vertex[3].y = (f32)(localRect.y + localRect.h);
        func_001e7b10(&quad[3], func_001e7c20(-16));
    }

    {
        KWindowQuad* quad;

        quad = ((KWindowRenderData*)work->renderData)->layout->quadStore->quad;
        quad[4].vertex[0].x = (f32)localRect.x;
        quad[4].vertex[0].y = (f32)localRect.y;
        quad[4].vertex[1].x = (f32)(localRect.x + localRect.w);
        quad[4].vertex[1].y = (f32)localRect.y;
        quad[4].vertex[2].x = (f32)localRect.x;
        quad[4].vertex[2].y = (f32)(localRect.y + localRect.h);
        quad[4].vertex[3].x = (f32)(localRect.x + localRect.w);
        quad[4].vertex[3].y = (f32)(localRect.y + localRect.h);
        func_001e7b10(&quad[4], func_001e7c20(-32));
    }

    func_004933d0(((KWindowRenderData*)work->renderData)->layout);
}
/*
 * The task below owns the small text/value editor used by the debug window.
 * Its work area is deliberately kept separate from KWindowTaskWork above:
 * the retail task stores the manager at KwlnTask::workData and all offsets
 * below are relative to that manager block.
 */








static inline KWindowManagerWork* KWindow_GetManager(KwlnTask* task)
{
    return (KWindowManagerWork*)task->workData;
}

static KWindowEntry* KWindow_GetCurrentEntry(KWindowManagerWork* manager)
{
    KWindowEntry* entry;
    s32 index;

    entry = manager->entries;
    index = manager->firstVisible + manager->cursor;
    if (index < 0 || index >= manager->entryCount)
    {
        return NULL;
    }

    while (index > 0 && entry != NULL)
    {
        entry = entry->next;
        index--;
    }

    return entry;
}

static inline void KWindow_InvokeEntryCallback(KWindowEntry* entry)
{
    void* value;

    if (entry == NULL || entry->callback == NULL)
    {
        return;
    }

    value = NULL;
    if (entry->type == 4)
    {
        value = &entry->floatValue;
    }
    else if (entry->type == 3 || entry->type == 2)
    {
        value = &entry->intValue;
    }
    else if (entry->type == 1)
    {
        value = entry->text;
    }

    if (entry->callbackValue != NULL)
    {
        entry->callback((void*)&value);
    }
    else
    {
        entry->callback(value);
    }
}


static inline void KWindow_MoveDown(KWindowManagerWork* manager)
{
    s32 visible;

    if (manager == NULL || manager->entryCount <= 0)
    {
        return;
    }
    visible = manager->visibleRows;
    if (visible > manager->entryCount)
    {
        visible = manager->entryCount;
    }
    manager->cursor++;
    if (manager->cursor >= visible)
    {
        manager->cursor = visible - 1;
        manager->firstVisible++;
        if (manager->entryCount <
            manager->firstVisible + 1 + visible)
        {
            manager->cursor = 0;
            manager->firstVisible = 0;
        }
    }
}

static inline void KWindow_MoveUp(KWindowManagerWork* manager)
{
    s32 visible;

    if (manager == NULL || manager->entryCount <= 0)
    {
        return;
    }
    visible = manager->visibleRows;
    if (visible > manager->entryCount)
    {
        visible = manager->entryCount;
    }
    manager->cursor--;
    if (manager->cursor < 0)
    {
        manager->cursor = 0;
        manager->firstVisible--;
        if (manager->firstVisible < 0)
        {
            manager->cursor = visible - 1;
            manager->firstVisible = manager->entryCount - visible;
        }
    }
}

static inline void KWindow_SetManagerRender(KWindowManagerWork* manager)
{
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    RwRGBA* colorData;
    RwRGBA* tile;
    s32 i;

    colorData = (RwRGBA*)((u8*)manager->colorData + 4);
    *(u8*)&colorData->r = *(u8*)((u8*)&uGpffff94c4 + 0);
    *(u8*)&colorData->g = *(u8*)((u8*)&uGpffff94c4 + 1);
    *(u8*)&colorData->b = *(u8*)((u8*)&uGpffff94c4 + 2);
    *(u8*)&colorData->a = *(u8*)((u8*)&uGpffff94c4 + 3);
    func_001e7aa0(manager->renderData, 0, manager->colorData);

    renderData = (KWindowRenderData*)manager->renderData;
    layout = renderData->layout;
    tile = layout->tileColors;
    for (i = 0; i < 4; i++)
    {
        tile[i] = *(RwRGBA*)&gp0xffff9460;
    }
    quad = layout->quadStore->quad;
    quad[0].vertex[0].x = 0.0f;
    quad[0].vertex[0].y = 0.0f;
    quad[0].vertex[1].x = 0.0f;
    quad[0].vertex[1].y = 0.0f;
    quad[0].vertex[2].x = 0.0f;
    quad[0].vertex[2].y = 0.0f;
    quad[0].vertex[3].x = 0.0f;
    quad[0].vertex[3].y = 0.0f;
    func_001e7b10(quad, func_001e7c20(-16));
    func_004933d0(layout);
}

static inline void KWindow_DrawSelection(KWindowManagerWork* manager)
{
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    f32 top;
    f32 bottom;
    void (**renderHook)(void);

    if (manager == NULL || manager->renderData == NULL)
    {
        return;
    }
    renderData = (KWindowRenderData*)manager->renderData;
    layout = renderData->layout;
    if (layout == NULL || layout->quadStore == NULL ||
        layout->quadStore->quad == NULL)
    {
        return;
    }
    func_00493370(layout, 2);
    quad = layout->quadStore->quad;
    top = (f32)(manager->y + 2 + manager->cursor * 12);
    bottom = top + 12.0f;
    quad[0].vertex[0].x = (f32)(manager->x + 2);
    quad[0].vertex[0].y = top;
    quad[0].vertex[1].x = (f32)(manager->x + manager->width - 2);
    quad[0].vertex[1].y = top;
    quad[0].vertex[2].x = (f32)(manager->x + 2);
    quad[0].vertex[2].y = bottom;
    quad[0].vertex[3].x = (f32)(manager->x + manager->width - 2);
    quad[0].vertex[3].y = bottom;
    func_001e7b10(quad, func_001e7c20(0xfff0));
    func_004933d0(layout);
    if (D_00960090 != NULL)
    {
        (*D_00960090)(6, 0);
        (*D_00960090)(8, 0);
    }
    func_004d7f60(2, 0x44);
    func_004d7f60(3, 0x717fb);
    renderHook = (void (**)(void))((u8*)manager->renderData + 0x48);
    if (*renderHook != NULL)
    {
        (**renderHook)();
    }
}

// W415 census negative: direct R_MIPS_26 calls are 10/10 with retail after resolving the H_Dbprt helpers; no wrong-callee edit is justified.
// FUN_001A2720 NONMATCHING
void func_001a2720(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    RwV2d position;
    s32 index;
    s32 right;
    s32 textWidth;

    manager = KWindow_GetManager(task);
    entry = manager->entries;
    position.x = (f32)(manager->x + 2);
    position.y = (f32)(manager->y + 2);
    index = 0;
    while (entry != NULL)
    {
        if (index < manager->cursor)
        {
            entry = entry->next;
            index++;
            continue;
        }
        if (index > manager->cursor + manager->visibleRows - 1)
        {
            break;
        }

        H_Dbprt_Fmt3D(position, "%s", entry->name);
        switch (entry->type)
        {
            case 0:
                break;

            case 1:
                textWidth = strlen(entry->text);
                right = manager->x + manager->width - 2 -
                        (textWidth + 1) * 12;
                position.x = (f32)(u32)right;
                H_Dbprt_FmtCol3D(position, *(RwRGBA*)&gp0xffff9480, "%s", entry->text);
                break;

            case 2:
                right = manager->x + manager->width - 2;
                textWidth = strlen(sKWindowType2Label);
                position.x = (f32)(u32)(right - (textWidth + 1) * 12);
                if (entry->intValue == 1)
                {
                    H_Dbprt_FmtCol3D(position, *(RwRGBA*)&gp0xffff9480, "on");
                }
                else
                {
                    H_Dbprt_FmtCol3D(position, *(RwRGBA*)&gp0xffff9480, "off");
                }
                break;

            case 3:
                if (entry->flags == 0)
                {
                    position.x =
                        (f32)(manager->x + manager->width - 0x6e);
                    H_Dbprt_FmtCol3D(position, *(RwRGBA*)&gp0xffff9480, "%d",
                                     entry->intValue);
                }
                else
                {
                    position.x =
                        (f32)(manager->x + manager->width - 0x86);
                    H_Dbprt_FmtCol3D(position, *(RwRGBA*)&gp0xffff9480, "%d",
                                     entry->intValue);
                }
                break;

            case 4:
                position.x =
                    (f32)(manager->x + manager->width - 0x62);
                H_Dbprt_FmtCol3D_f32(position, *(RwRGBA*)&gp0xffff9480, "%.2f",
                                     func_00530da0(entry->floatValue));
                break;
        }

        position.x = (f32)(manager->x + 2);
        position.y += 12.0f;
        entry = entry->next;
        index++;
    }
}

/* W417: moved the state-3 func_001a2720 call ahead of the flag branch to match retail call order; nd3046 -> nd3008 and object 4032/4064. */
/* W417 negative: placing func_001a2720 after KWindow_DrawSelection yielded nd3020; the pre-branch placement above is nd3008. */
// FUN_001A2A80 NONMATCHING
void* func_001a2a80(KwlnTask* task)
{
    KWindowManagerWork* manager;

    manager = KWindow_GetManager(task);
    switch (manager->state)
    {

        case 0:
        {
            if (manager->request == 1)
            {
                manager->state++;
            }
            break;
        }

        case 1:
        {
            if (manager->mode == 1)
            {
                RwRect rect;
                f32 colorA;
                f32 colorB;

                rect.x = manager->x;
                rect.y = manager->y;
                rect.w = manager->width;
                rect.h = manager->height;
                colorA = *(f32*)&gp0xffff9468;
                colorB = *(f32*)&gp0xffff946c;
                manager->windowTask =
                    func_001a2200(task, &rect, (RwRGBA*)&colorA,
                                  (RwRGBA*)&colorB);
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[0] = 0xe3;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[1] = 0x4a;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[2] = 0;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[3] = 0xff;
            }
            else if (manager->mode == 2)
            {
                RwRect rect;
                f32 colorA;
                f32 colorB;

                rect.x = manager->x;
                rect.y = manager->y;
                rect.w = manager->width;
                rect.h = manager->height;
                colorA = *(f32*)&gp0xffff9470;
                colorB = *(f32*)&gp0xffff9474;
                manager->windowTask =
                    func_001a2200(task, &rect, (RwRGBA*)&colorA,
                                  (RwRGBA*)&colorB);
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[0] = 0x54;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[1] = 0;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[2] = 0;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[3] = 0xff;
            }
            else if (manager->mode == 3)
            {
                RwRect rect;
                f32 colorA;
                f32 colorB;

                rect.x = manager->x;
                rect.y = manager->y;
                rect.w = manager->width;
                rect.h = manager->height;
                colorA = *(f32*)&gp0xffff9478;
                colorB = *(f32*)&gp0xffff947c;
                manager->windowTask =
                    func_001a2200(task, &rect, (RwRGBA*)&colorA,
                                  (RwRGBA*)&colorB);
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[0] = 0x40;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[1] = 0x40;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[2] = 0x40;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[3] = 0xff;
            }
            else
            {
                RwRect rect;
                f32 colorA;
                f32 colorB;

                rect.x = manager->x;
                rect.y = manager->y;
                rect.w = manager->width;
                rect.h = manager->height;
                colorA = *(f32*)&gp0xffff9460;
                colorB = *(f32*)&gp0xffff9464;
                manager->windowTask =
                    func_001a2200(task, &rect, (RwRGBA*)&colorA,
                                  (RwRGBA*)&colorB);
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[0] = 0xe3;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[1] = 0x4a;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[2] = 0;
                ((volatile /* Removing this function's qualifier batch worsens func_001a2a80 (NONMATCHING nd2940 -> NONMATCHING nd2995, size 3868 -> 3916) - measured W170. */ u8*)&uGpffff94c4)[3] = 0xff;
            }

            manager->renderData = func_001e78c0(1, 0x48);
            manager->colorData = func_00494be0();
            KWindow_SetManagerRender(manager);
            manager->state++;
            break;
        }

        case 2:
        {
            if (manager->windowTask == NULL ||
                func_001a2390(manager->windowTask) != 1)
            {
                if (manager->windowTask != NULL)
                {
                    func_001a23e0(manager->windowTask,
                                  (RwRect*)&manager->x);
                }
                manager->state++;
            }
            break;
        }

        case 3:
        {
            KWindowEntry* entry;
            u16 input;

            if ((DAT_007e094c & 1) != 0)
            {
                uGpffffb450++;
            }
            else
            {
                uGpffffb450 = 0;
            }
            if ((DAT_007e094c & 2) != 0)
            {
                uGpffffb454++;
            }
            else
            {
                uGpffffb454 = 0;
            }
            if (manager->request != 1 || manager->entryCount == 0)
            {
                break;
            }

            input = DAT_007e0952;
            func_001a2720(task);
            if ((manager->flags & 1) == 0)
            {
                KWindow_DrawSelection(manager);
                if ((input & 0x1000) != 0)
                {
                    KWindow_MoveDown(manager);
                }
                else if ((input & 0x4000) != 0)
                {
                    KWindow_MoveUp(manager);
                }
                else if ((input & 0x2000) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)), 1, 1.0f);
                }
                else if ((input & 0x8000) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)), -1, -1.0f);
                }
                else if ((input & 8) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)), 10, 10.0f);
                }
                else if ((input & 4) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)), -10, -10.0f);
                }
                else if ((input & 2) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)),
                        uGpffffb450 > 0x95 ? 1000 : 100,
                        uGpffffb450 > 0x95 ? 10.0f : 1.0f);
                }
                else if ((input & 1) != 0)
                {
                    KWindow_ApplyValueDelta(
                        func_001a4330(task, func_001a4510(task)),
                        uGpffffb454 > 0x95 ? -1000 : -100,
                        uGpffffb454 > 0x95 ? -10.0f : -1.0f);
                }
                else if ((DAT_007e094e & 0x40) != 0)
                {
                    KWindow_InvokeEntryCallback(
                        func_001a4330(task, func_001a4510(task)));
                }
            }
            else if ((input & 0x1000) != 0)
            {
                KWindow_MoveDown(manager);
            }
            else if ((input & 0x4000) != 0)
            {
                KWindow_MoveUp(manager);
            }
            break;
        }

        case 4:
            break;

        case 5:
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}
 
// FUN_001A3A60
void func_001a3a60(KwlnTask* task)
{
    KWindowManagerWork* manager;

    manager = (KWindowManagerWork*)task->workData;
    func_001a44a0(task);
    if (manager->colorData != NULL)
    {
        func_00494cc0(manager->colorData);
    }
    if (manager->renderData != NULL)
    {
        func_001e7a60(manager->renderData);
    }
    (*(void (**)(void*))D_0096017c_abs)(task->workData);
}

// FUN_001A3AE0
KwlnTask* func_001a3ae0(KwlnTask* parent, u32 width, u32 height, u32 unused)
{
    (void)unused;
    return func_001a3b10(parent, width, height, 0);
}

// FUN_001A3B10
KwlnTask* func_001a3b10(KwlnTask* parent, u32 width, u32 height, u32 mode)
{
    KWindowManagerWork* manager;
    KwlnTask* task;

    manager = (KWindowManagerWork*)RwCalloc(1, sizeof(KWindowManagerWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (manager == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          0x106f,
                                          D_00678AF8,
                                          func_001a2a80,
                                          func_001a3a60,
                                          manager);
    manager->x = (s32)width;
    manager->y = (s32)height;
    manager->width = 0x80;
    manager->height = 0x80;
    manager->visibleRows = 10;
    manager->mode = (s32)mode;
    return task;
}

// FUN_001A3BE0
void func_001a3be0(KwlnTask* task, u32 flags)
{
    ((KWindowManagerWork*)task->workData)->flags = flags;
}

// FUN_001A3BF0
void func_001a3bf0(KwlnTask* task, u32 request)
{
    KWindowManagerWork* manager;

    manager = (KWindowManagerWork*)task->workData;
    manager->request = request;
    if (manager->windowTask != NULL)
    {
        func_001a23d0(manager->windowTask, request);
    }
}

// FUN_001A3C30
void func_001a3c30(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    u32 maxWidth;
    s32 width;
    s32 height;
    s32 lineCount;

    manager = (KWindowManagerWork*)task->workData;
    entry = manager->entries;
    maxWidth = 0;
    while (entry != NULL)
    {
        width = strlen(entry->name);
        switch (entry->type)
        {
            case 0:
                break;
            case 1:
                width += strlen(entry->text) + 1;
                break;
            case 2:
                width += strlen((const char*)&gp0xffff9484) + 1;
                break;
            case 3:
                if (entry->flags == 0)
                {
                    width += 9;
                }
                else
                {
                    width += 11;
                }
                break;
            case 4:
                width += 8;
                break;
        }
        if (maxWidth < (u32)width)
        {
            maxWidth = (u32)width;
        }
        entry = entry->next;
    }

    manager->width = maxWidth * 12 + 4;
    lineCount = manager->entryCount * 12 + 4;
    height = manager->visibleRows * 12 + 4;
    manager->height = height;
    if (lineCount < height)
    {
        manager->height = lineCount;
    }
    if (manager->windowTask != NULL)
    {
        func_001a23e0(manager->windowTask, (RwRect*)&manager->x);
    }
}

// FUN_001A3DC0
void func_001a3dc0(KwlnTask* task, const KWindowEntryDescriptor* descriptors,
                   u32 count)
{
    u32 i;
    u32 id;

    i = 0;
    while (i < count)
    {
        id = func_001a3f20(task, descriptors->name);
        switch (descriptors->type)
        {
            case 0:
                break;
            case 1:
                func_001a4090(task, id, descriptors->text);
                break;
            case 2:
                func_001a41f0(task, id, descriptors->value0);
                break;
            case 3:
                func_001a4110(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2,
                              descriptors->value3);
                break;
            case 4:
                func_001a4260(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2);
                break;
        }
        if (descriptors->callback != NULL)
        {
            func_001a4050(task, id, descriptors->callback);
        }
        i++;
        descriptors++;
    }
}
