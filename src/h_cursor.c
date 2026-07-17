#include "h_cursor.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"

// FUN_00100230 NONMATCHING
void* H_Cursor_UpdateTask(KwlnTask* hcursorTask)
{
    RwRenderStateSetFunc* setRenderState;
    HCursorWork* work;
    RwIm2DVertex* vertex;
    RwRGBA* color;
    f32 recipZ;
    f32 zBufferNear;
    s16 i;

    work = (HCursorWork*)hcursorTask->workData;

    setRenderState = &rwGlobals.device.setRenderState;

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
            zBufferNear = RwIm2DGetNearScreenZ();
            for (; i < 4; i++)
            {
                vertex = &work->vertices[i];
                color = &work->colors[i];

                vertex->u.els.scrVertex.z = zBufferNear - work->zOffset;
                vertex->u.els.recipZ = recipZ;
                vertex->u.els.color.r = (f32)color->r;
                vertex->u.els.color.g = (f32)color->g;
                vertex->u.els.color.b = (f32)color->b;
                vertex->u.els.color.a = (f32)color->a;
            }

            work->vertices[0].u.els.scrVertex.x = work->pos.x;
            work->vertices[0].u.els.scrVertex.y = work->pos.y;

            work->vertices[1].u.els.scrVertex.x = work->pos.x + work->rect.w;
            work->vertices[1].u.els.scrVertex.y = work->pos.y;

            work->vertices[2].u.els.scrVertex.x = work->pos.x;
            work->vertices[2].u.els.scrVertex.y = work->pos.y + work->rect.h;
            
            work->vertices[3].u.els.scrVertex.x = work->pos.x + work->rect.w;
            work->vertices[3].u.els.scrVertex.y = work->pos.y + work->rect.h;

            RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, work->vertices, 4);

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
