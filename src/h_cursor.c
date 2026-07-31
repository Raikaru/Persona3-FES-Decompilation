#include "h_cursor.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern f32 DAT_00960088;
typedef struct HCursorGlobalsOverlay
{
    u8 unk[0x88];
    f32 value;
} HCursorGlobalsOverlay;

// FUN_00100230 NONMATCHING
void* H_Cursor_UpdateTask(KwlnTask* hcursorTask)
{
    RwRenderStateSetFunc* setRenderState;
    HCursorWork* work;
    HCursorWork* indexedWork;
    RwIm2DVertex* vertex;
    f32 recipZ;
    s16 i;
    HCursorGlobalsOverlay* globals;

    work = (HCursorWork*)hcursorTask->workData;

    setRenderState = (RwRenderStateSetFunc*)(rwGlobals_abs + 0x90);

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDDESTCOLOR);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);

    if (!work->shouldDraw)
    {
        return KWLNTASK_CONTINUE;
    }

    switch (work->state)
    {
        case HCURSOR_STATE_INIT: // fallthrough
        case HCURSOR_STATE_UPDATE:
            recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
            i = 0;
            for (; i < 4; i++)
            {
                globals = (HCursorGlobalsOverlay*)rwGlobals_abs;
                vertex = &work->vertices[i];

                vertex->u.els.scrVertex.z = globals->value - work->zOffset;
                vertex->u.els.recipZ = recipZ;
                indexedWork = (HCursorWork*)((RwRGBA*)work + i);
                vertex->u.els.color.r = (f32)indexedWork->colors[0].r;
                vertex->u.els.color.g = (f32)indexedWork->colors[0].g;
                vertex->u.els.color.b = (f32)indexedWork->colors[0].b;
                vertex->u.els.color.a = (f32)indexedWork->colors[0].a;
            }

            work->vertices[0].u.els.scrVertex.x = work->pos.x;
            work->vertices[0].u.els.scrVertex.y = work->pos.y;

            work->vertices[1].u.els.scrVertex.x = work->pos.x + work->rect.w;
            work->vertices[1].u.els.scrVertex.y = work->pos.y;

            work->vertices[2].u.els.scrVertex.x = work->pos.x;
            work->vertices[2].u.els.scrVertex.y = work->pos.y + work->rect.h;

            work->vertices[3].u.els.scrVertex.x = work->pos.x + work->rect.w;
            work->vertices[3].u.els.scrVertex.y = work->pos.y + work->rect.h;

            (*((RwIm2DRenderPrimitiveFunction*)(rwGlobals_abs + 0xa0)))(rwPRIMTYPETRISTRIP, work->vertices, 4);

            work->state = HCURSOR_STATE_UPDATE;
            break;

        case HCURSOR_STATE_STOP: return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00100570
u32* H_Cursor_GetShouldDraw(KwlnTask* hcursorTask)
{
    return &((HCursorWork*)hcursorTask->workData)->shouldDraw;
}

// FUN_00100580
void H_Cursor_DestroyTask(KwlnTask* hcursorTask)
{
    RwFree(hcursorTask->workData);
}

// FUN_001005b0
KwlnTask* H_Cursor_CreateTask(KwlnTask* parent, f32 zOffset, RwV2d pos, RwRect rect, RwRGBA color)
{
    HCursorWork* work;
    KwlnTask* task;
    RwRect _rect;

    _rect = rect;

    work = RwCalloc(1, sizeof(HCursorWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          "H CURSOR Draw",
                          6335,
                          H_Cursor_UpdateTask,
                          H_Cursor_DestroyTask,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    work->zOffset = zOffset;
    work->pos = pos;
    work->rect = _rect;
    work->colors[0] = color;
    work->colors[1] = color;
    work->colors[2] = color;
    work->colors[3] = color;
    work->shouldDraw = true;

    return task;
}

// FUN_00100710
void H_Cursor_SetPos(KwlnTask* hcursorTask, RwV2d pos)
{
    ((HCursorWork*)hcursorTask->workData)->pos = pos;
}

// FUN_00100740
void H_Cursor_SetRect(KwlnTask* hcursorTask, RwRect rect)
{
    ((HCursorWork*)hcursorTask->workData)->rect = rect;
}

// FUN_00100770
void H_Cursor_SetZOffset(KwlnTask* hcursorTask, f32 zOffset)
{
    ((HCursorWork*)hcursorTask->workData)->zOffset = zOffset;
}

// FUN_00100780
void H_Cursor_SetColor(KwlnTask* hcursorTask, RwRGBA color)
{
    HCursorWork* work;
    work = (HCursorWork*)hcursorTask->workData;

    work->colors[0] = color;
    work->colors[1] = color;
    work->colors[2] = color;
    work->colors[3] = color;
}
