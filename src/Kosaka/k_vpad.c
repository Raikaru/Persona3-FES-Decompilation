#include "Kosaka/k_vpad.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_fldCamera.h"
#include "Kosaka/Field/k_event.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "h_pad.h"
#include "libm.h"
/* Retail addresses the controller state by absolute address. */
#pragma alias gPads_abs gPads
extern u8 gPads_abs[];

extern void func_001d5e30(KwlnTask* cameraTask, f32 amount);
extern KwlnTask* func_001d6270(KwlnTask* parent, s32 mode, s32 duration);
extern KwlnTask* func_001d6630(KwlnTask* parent, s32 mode, s32 heading);
extern f32 func_001a5aa0(void* cameraData);
extern void* func_004cb2f0(void* camera);
extern f32 func_004c2fb0(const RwMatrix* matrix1, const RwMatrix* matrix2);
extern f32 func_0052ea18(f32 x, f32 y);
extern f32 func_001b02c0(s32 arg1, s32 arg2);
extern s32 func_001de630(s32 type);
extern s32 func_001ded40(s32 type);
extern s32 func_001dde00(s32 type);
extern s32 func_001df450();
extern f32 sqrtf(f32 value);
extern void func_001e1300(KwlnTask* task, s32 arg);
extern void func_001e1360(KwlnTask* task, s32 arg);
extern f32 func_001e13c0(void);
extern s32 func_001e1590(KwlnTask* rotateTask, const RwMatrix* matrix, f32 playerHeading, f32 inputHeading);
extern f32 D_007CE230;
extern RwV3d D_00683D78;
extern f32 D_007CE82C;
extern f32 D_007CE834;
extern f32 D_007CAF38;
extern u32 D_007CE2B8;

extern volatile /* Removing this file's qualifier batch loses 1 MATCH(es) and worsens 0 other function(s) - measured W170. */ f32 DAT_007cb144;
extern volatile /* Removing this file's qualifier batch loses 1 MATCH(es) and worsens 0 other function(s) - measured W170. */ f32 DAT_007caf24;


static f32 sVPadMoveSpeed;

// FUN_001e05b0 NONMATCHING
void* K_VPad_UpdateTask(KwlnTask* task)
{
    VPadWork* work;
    RwMatrix cameraMat;
    RwMatrix playerMat;
    RwV3d axis;
    f32 playerHeading;
    f32 cameraHeading;
    f32 inputHeading;
    f32 movement;
    f32 speed;
    s32 animation;
    s32 rotated;
    s32 forceAnimation;
    work = (VPadWork*)task->workData;
    kwlnGetMainCamera();
    axis = D_00683D78;

    if (work->cameraTask != NULL && kwlnTaskExists(work->cameraTask) != true)
    {
        work->cameraTask = NULL;
        work->cameraHeading =
            func_001a5aa0(func_004cb2f0(kwlnGetMainCamera()->object.object.parent));
    }

    switch (work->state)
    {
    case 0:
        work->state++;
        break;
    case 1:
    {
        RwV3d move = {0};
        RwV3d right = {0};
        s32 value;
        f32 valueF;
        u16 padButtons;

        if (work->controlMode == 1)
        {
            goto state1_done;
        }
        if (work->controlFlags == 1)
        {
            goto state1_done;
        }

        value = *(u8*)(gPads_abs + 0x1f);
        valueF = (f32)(u32)value;
        move.z = valueF - 128.0f;
        padButtons = *(u16*)(gPads_abs + 0xc);
        if ((padButtons & HPAD_BTN_UP) != 0)
        {
            move.z = -128.0f;
        }
        else if ((padButtons & HPAD_BTN_DOWN) != 0)
        {
            move.z = 128.0f;
        }

        value = *(u8*)(gPads_abs + 0x1e);
        valueF = (f32)(u32)value;
        move.x = valueF - 128.0f;
        if ((padButtons & HPAD_BTN_LEFT) != 0)
        {
            move.x = -128.0f;
        }
        else if ((padButtons & HPAD_BTN_RIGHT) != 0)
        {
            move.x = 128.0f;
        }

        value = *(u8*)(gPads_abs + 0x21);
        valueF = (f32)(u32)value;
        right.z = valueF - 128.0f;
        value = *(u8*)(gPads_abs + 0x20);
        valueF = (f32)(u32)value;
        right.x = valueF - 128.0f;

        if ((padButtons & (HPAD_BTN_R2 | HPAD_BTN_R1)) != 0 ||
            right.x > 48.0f)
        {
            if (K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
            {
                if ((*(u16*)(gPads_abs + 0xc) & (HPAD_BTN_R2 | HPAD_BTN_R1)) != 0 &&
                    (*(u16*)(gPads_abs + 0xc) & HPAD_BTN_CIRCLE) != 0)
                {
                    if (work->cameraTask == NULL)
                    {
                        work->cameraHeading -= 90.0f;
                        if (work->cameraHeading < 0.0f)
                        {
                            work->cameraHeading += 360.0f;
                        }
                        work->cameraTask =
                            func_001d6630(task, 10, (s32)work->cameraHeading);
                    }
                }
                else
                {
                    speed = -D_007CE82C;
                    if (datGetFlag(0x189) == true)
                    {
                        speed = -speed;
                    }
                    func_001d5e30(K_Field_Get()->cameraCtlTask, speed);
                }
            }
            goto camera_input_done;
        }
        if ((*(u16*)(gPads_abs + 0xc) & (HPAD_BTN_L2 | HPAD_BTN_L1)) != 0 ||
                 right.x < -48.0f)
        {
            if (K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
            {
                if ((*(u16*)(gPads_abs + 0xc) & (HPAD_BTN_L2 | HPAD_BTN_L1)) != 0 &&
                    (*(u16*)(gPads_abs + 0xc) & HPAD_BTN_CIRCLE) != 0)
                {
                    if (work->cameraTask == NULL)
                    {
                        work->cameraHeading += 90.0f;
                        if (work->cameraHeading >= 360.0f)
                        {
                            work->cameraHeading -= 360.0f;
                        }
                        work->cameraTask =
                            func_001d6630(task, 10, (s32)work->cameraHeading);
                    }
                }
                else
                {
                    speed = D_007CE82C;
                    if (datGetFlag(0x189) == true)
                    {
                        speed = -speed;
                    }
                    func_001d5e30(K_Field_Get()->cameraCtlTask, speed);
                }
            }
            goto camera_input_done;
        }

        if ((*(u16*)(gPads_abs + 0xc) & HPAD_BTN_CROSS) == 0 &&
            (*(u16*)(gPads_abs + 0xe) & HPAD_BTN_CIRCLE) != 0 &&
            K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
        {
            work->cameraTask = func_001d6270(task, 10, -1);
            return KWLNTASK_CONTINUE;
        }

        camera_input_done:
        if (move.z < -48.0f || move.z > 48.0f ||
            move.x < -48.0f || move.x > 48.0f)
        {
            RwMatrix rotateMat;
            cameraMat =
                ((RwFrame*)kwlnGetMainCamera()->object.object.parent)->modelling;
            func_004c2fb0(&cameraMat, &cameraMat);
            cameraHeading =
                180.0f * -func_0052ea18(cameraMat.right.z, cameraMat.right.x) /
                D_007CAF38;
            playerMat = mdlGetClumpFrame(work->mdl)->modelling;
            func_004c2fb0(&playerMat, &playerMat);
            playerHeading =
                180.0f * -func_0052ea18(playerMat.right.z, playerMat.right.x) /
                D_007CAF38;

            if (move.x >= -48.0f && move.x <= 48.0f)
            {
                move.x = 0.0f;
            }
            if (move.z >= -48.0f && move.z <= 48.0f)
            {
                move.z = 0.0f;
            }
            if (cameraHeading < 0.0f)
            {
                cameraHeading += 360.0f;
            }
            if (playerHeading < 0.0f)
            {
                playerHeading += 360.0f;
            }
            if (K_VPad_IsRotating(work->rotateTask) == true)
            {
                return KWLNTASK_CONTINUE;
            }
            inputHeading = func_001b02c0(0, 0);
            RwMatrixSetIdentity(&rotateMat);
            RwMatrixRotate(&rotateMat, &axis, cameraHeading, rwCOMBINEPRECONCAT);
            RwMatrixRotate(&rotateMat, &axis, inputHeading, rwCOMBINEPRECONCAT);
            rotated = func_001e1590(work->rotateTask, &rotateMat,
                                    playerHeading, cameraHeading + inputHeading);
            if (K_VPad_IsRotating(work->rotateTask) == true)
            {
                sVPadMoveSpeed = 0.0f;
                if (rotated != 0)
                {
                    work->moveTimer = 0;
                    work->stationaryFrames = 0;
                }
                return KWLNTASK_CONTINUE;
            }
            speed = 0.0f;
            K_FldFrame_CtlUpdateMdlMat(work->collisCtlTask, &rotateMat);
                movement = RwV3dLength(&move);
                if (movement > 128.0f)
                {
                    movement = 128.0f;
                }
                if (movement < 125.0f)
                {
                    speed = 13.0f;
                }
                else
                {
                    speed = 128.0f * D_007CE834 *
                            sinf((D_007CAF38 * 0.5f * movement) / 128.0f);
                }
                K_FldFrame_CtlMoveForward(speed, work->collisCtlTask);
            sVPadMoveSpeed = speed;
            if (rotated == 0)
            {
                if (speed <= 13.0f)
                {
                    animation = func_001de630(1);
                }
                else
                {
                    animation = func_001ded40(1);
                }
                if (work->animId != animation)
                {
                    if (work->animDebounce < 2)
                    {
                        work->animDebounce++;
                    }
                    else
                    {
                        work->animState = 0;
                        work->animId = (s16)animation;
                        work->animDebounce = 0;
                    }
                }
                if (work->animState == 0)
                {
                    mdlAnimSet(work->mdl, 0, (s16)animation, 6, 1);
                    work->animState = 1;
                }
            }
            work->moveTimer = 0;
            work->stationaryFrames = 0;
        }
        else
        {
            forceAnimation = 0;
            if (work->stationaryFrames < 4)
            {
                work->stationaryFrames++;
            }
            else
            {
                if (work->moveTimer == 0)
                {
                    datSetFlag(0xC35, false);
                    animation = func_001dde00(1);
                    mdlAnimSet(work->mdl, 0, (s16)animation, 4, 1);
                }
                work->moveTimer++;
                if (work->moveTimer == 60)
                {
                    datSetFlag(0xC35, true);
                    work->animState = 1;
                }
                else if (work->moveTimer >= 361)
                {
                    if ((datGetBadStatusNoDown(1) & 0x80) == 0)
                    {
                        forceAnimation = 1;
                    }
                    work->moveTimer = 61;
                }
                if (mdlAnimGetId(work->mdl, 0) >= 6 &&
                    work->mdl->animSlots[0].anim.isAnimEnd == 1)
                {
                    work->animState = 1;
                }
                if (work->animState == 1)
                {
                    animation = func_001dde00(1);
                    mdlAnimSet(work->mdl, 0, (s16)animation, 8, 1);
                    work->animState = 0;
                }
                if (forceAnimation != 0)
                {
                    animation = func_001df450();
                    mdlAnimSet(work->mdl, 0, (s16)animation, 8, 0);
                }
            }
        }
        state1_done:
        break;

    }
    case 2:
        if (kwlnTaskExists(work->eventTask) != true)
        {
            func_001e1300(K_Field_Get()->playerPadTask, 0);
            K_FldEvent_001cd650(K_Field_Get()->eventTask, false);
            work->state = 1;
        }
        break;
    case 5:
        return KWLNTASK_STOP;
    }
    return KWLNTASK_CONTINUE;

}
// FUN_001e1200
void K_VPad_DestroyTask(KwlnTask* rotatePcTask)
{
    RwFree(rotatePcTask->workData);
}

// FUN_001e1230
KwlnTask* K_VPad_CreateTask(KwlnTask* parent, KwlnTask* collisCtlTask, Model* mdl)
{
    KwlnTask* task;
    VPadWork* work;

    work = RwCalloc(1, sizeof(VPadWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "player pad proc",
                                          K_VPad_UpdateTask,
                                          K_VPad_DestroyTask,
                                          work);

    work->collisCtlTask = collisCtlTask;
    work->mdl = mdl;
    work->rotateTask = K_VPad_CreateRotateTask(task, collisCtlTask, mdl);

    return task;
}

// FUN_001e13f0
void* K_VPad_UpdateRotateTask(KwlnTask* rotatePcTask)
{
    static const RwV3d sAxis = { 0.0f, 1.0f, 0.0f }; // 00683da0
    PcRotateWork* work;
    RwV3d axis;

    work = (PcRotateWork*)rotatePcTask->workData;
    axis = sAxis;

    switch (work->state)
    {
        case PCROTATE_STATE_IDLE: break;

        case PCROTATE_STATE_ROTATING:
            work->steps++;

            K_FldFrame_CtlRotate(work->collisCtlTask, &axis, work->angle);

            if (work->steps >= work->maxSteps)
            {
                K_FldFrame_CtlUpdateMdlMat(work->collisCtlTask, &work->mat);
                K_FldEvent_001cd650(K_Field_Get()->eventTask, false);
                work->state = PCROTATE_STATE_IDLE;
            }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001e14b0
void K_VPad_DestroyRotateTask(KwlnTask* rotatePcTask)
{
    RwFree(rotatePcTask->workData);
}

// FUN_001e14e0
KwlnTask* K_VPad_CreateRotateTask(KwlnTask* parent, KwlnTask* collisCtlTask, Model* mdl)
{
    PcRotateWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(PcRotateWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "rotate pc",
                                          K_VPad_UpdateRotateTask,
                                          K_VPad_DestroyRotateTask,
                                          work);

    work->collisCtlTask = collisCtlTask;
    work->mdl = mdl;

    return task;
}

// FUN_001e1820
u32 K_VPad_IsRotating(KwlnTask* rotatePcTask)
{
    return ((PcRotateWork*)rotatePcTask->workData)->state == PCROTATE_STATE_ROTATING;
}
// FUN_001e1300
void func_001e1300(KwlnTask* task, s32 controlMode)
{
    VPadWork* work;
    s16 animation;
    if (task == NULL)
    {
        return;
    }
    work = (VPadWork*)task->workData;
    work->animState = 0;
    work->controlMode = (u32)controlMode;
    animation = (s16)func_001dde00(1);
    mdlAnimSet(work->mdl, 0, animation, 8, 1);
}

// FUN_001e1360
void func_001e1360(KwlnTask* task, s32 controlFlags)
{
    VPadWork* work;
    s16 animation;
    if (task == NULL)
    {
        return;
    }
    work = (VPadWork*)task->workData;
    work->animState = 0;
    work->controlFlags = (u32)controlFlags;
    animation = (s16)func_001dde00(1);
    mdlAnimSet(work->mdl, 0, animation, 8, 1);
}

// FUN_001e13c0
f32 func_001e13c0(void)
{
    f32 speed = sVPadMoveSpeed;
    if (speed <= 0.0f)
    {
        speed = D_007CE230;
    }
    return speed;
}

// FUN_001e1590
s32 func_001e1590(KwlnTask* rotateTask, const RwMatrix* matrix,
                  f32 playerHeading, f32 inputHeading)
{
    PcRotateWork* work;
    f32 direct;
    f32 wrapped;
    s32 maxSteps;
    s32 reverse;
    work = (PcRotateWork*)rotateTask->workData;
    if (work->state == PCROTATE_STATE_ROTATING)
    {
        return 0;
    }
    work->mat = *matrix;

    if (playerHeading > 360.0f)
    {
        playerHeading -= 360.0f;
    }
    *(f32*)((u8*)work + 0x4c) = playerHeading;
    if (inputHeading > 360.0f)
    {
        inputHeading -= 360.0f;
    }
    *(f32*)((u8*)work + 0x50) = inputHeading;
    if (playerHeading < inputHeading)
    {
        if (playerHeading > DAT_007cb144)
        {
            playerHeading = 0.0f;
        }
        if (inputHeading > DAT_007cb144)
        {
            inputHeading = 360.0f;
        }
        if (playerHeading < DAT_007caf24)
        {
            playerHeading = 0.0f;
        }
        if (inputHeading < DAT_007caf24)
        {
            inputHeading = 360.0f;
        }
        direct = inputHeading - playerHeading;
        wrapped = playerHeading + (360.0f - inputHeading);
        reverse = 0;
    }
    else
    {
        if (playerHeading > DAT_007cb144)
        {
            playerHeading = 360.0f;
        }
        if (inputHeading > DAT_007cb144)
        {
            inputHeading = 0.0f;
        }
        if (playerHeading < DAT_007caf24)
        {
            playerHeading = 360.0f;
        }
        if (inputHeading < DAT_007caf24)
        {
            inputHeading = 0.0f;
        }
        direct = playerHeading - inputHeading;
        wrapped = inputHeading + (360.0f - playerHeading);
        reverse = 1;
    }

    if (fabsf(direct) < fabsf(wrapped))
    {
        work->angle = direct;
        if (reverse == 1)
        {
            work->angle *= -1.0f;
        }
    }
    else
    {
        work->angle = wrapped;
        if (reverse == 0)
        {
            work->angle *= -1.0f;
        }
    }

    if (fabsf(work->angle) > 45.0f)
    {
        maxSteps = (s32)fabsf(work->angle) / 30;
        if (maxSteps <= 0)
        {
            maxSteps = 1;
        }
        work->maxSteps = maxSteps;
        work->steps = 0;
        work->angle /= (f32)work->maxSteps;
        work->state = PCROTATE_STATE_ROTATING;
        K_FldEvent_001cd650(K_Field_Get()->eventTask, true);
        return 1;
    }
    return 0;
}

// FUN_001E1840
void* func_001e1840(void)
{
    return &D_007CE2B8;
}