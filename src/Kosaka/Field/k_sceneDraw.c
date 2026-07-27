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
extern void* D_0096017c[];
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
#pragma opt_common_subs off
// FUN_0019e330 NONMATCHING
void* K_SceneDraw_UpdateDrwChrMdlTask(KwlnTask* drwChrMdlTask)
{
    ResrcModelChar* charRes;
    ResrcModelNpc* npcRes;
    ResrcModelNpc* npcList;
    Resrc* modelUnk;
    ResrcLightChar* charLight;
    ResrcLightNpc* npcLight;
    RwRGBAReal ambientColor;
    RwRGBAReal directionalColor;
    RwMatrix directionalMatrix;
    RwRGBAReal secondaryDirectionalColor;
    RwMatrix secondaryDirectionalMatrix;
    Model* slotMdl;
    RwV3d position;
    s32 charCount;
    s32 i;
    s32 slot;
    u32 flags;
    ResrcModelChar* charList[SCENEDRAW_MAX_SORTED_MODELS];

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
    func_00521408(charList, 0, sizeof(charList));

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
#pragma opt_common_subs on
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

// FUN_0019fd40
RwRGBAReal* K_Scene_GetFldAmbLightColor()
{
    ResrcFld* res;

    res = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    return &res->ambLightColor;
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
// FUN_0019f8f0 NONMATCHING
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

    if ((u32)clearAlpha >= 0x100) clearAlpha = 0xff;
    if ((u32)clearBlue >= 0x100) clearBlue = 0xff;
    if ((u32)clearGreen >= 0x100) clearGreen = 0xff;
    if ((u32)clearRed >= 0x100) clearRed = 0xff;
    kwlnSetClearColor((u8)clearRed, (u8)clearGreen, (u8)clearBlue, (u8)clearAlpha);

    fogRed = (s32)((f32)((fogColor >> 16) & 0xff) * color->r);
    fogGreen = (s32)((f32)((fogColor >> 8) & 0xff) * color->g);
    fogBlue = (s32)((f32)(fogColor & 0xff) * color->b);
    fogAlpha = (s32)((f32)((fogColor >> 24) & 0xff) * color->a);

    if ((u32)fogRed >= 0x100) fogRed = 0xff;
    gFogRed = (u8)fogRed;
    if ((u32)fogGreen >= 0x100) fogGreen = 0xff;
    gFogGreen = (u8)fogGreen;
    if ((u32)fogBlue >= 0x100) fogBlue = 0xff;
    gFogBlue = (u8)fogBlue;
    if ((u32)fogAlpha >= 0x100) fogAlpha = 0xff;
    gFogAlpha = (u8)fogAlpha;
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
    right->right.y = right->at.z * up->x - right->at.x * up->z;
    right->right.z = right->at.x * up->y - right->at.y * up->x;
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
        (*(void (**)(void*))D_0096017c)(current);
        current = next;
    }
}

// FUN_001a1540
void* func_001a1540()
{
    return KWLNTASK_CONTINUE;
}
