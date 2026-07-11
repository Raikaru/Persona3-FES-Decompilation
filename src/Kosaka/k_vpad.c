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
extern volatile f32 DAT_007cb144;
extern volatile f32 DAT_007caf24;


static f32 sVPadMoveSpeed;

// FUN_001e05b0 NONMATCHING
void* K_VPad_UpdateTask(KwlnTask* task)
{
    VPadWork* work;
    RwCamera* camera;
    RwFrame* cameraFrame;
    RwFrame* playerFrame;
    RwMatrix cameraMat;
    RwMatrix playerMat;
    RwMatrix rotateMat;
    RwV3d axis;
    HPad* pad;
    u16 buttons;
    f32 moveX;
    f32 moveY;
    f32 rightX;
    f32 rightY;
    f32 playerHeading;
    f32 cameraHeading;
    f32 inputHeading;
    f32 movement;
    f32 speed;
    s32 animation;
    s32 heading;
    s32 rotated;
    s32 forceAnimation;
    s32 stationary;
    s32 cameraInput;

    work = (VPadWork*)task->workData;
    camera = kwlnGetMainCamera();

    if (work->cameraTask != NULL && kwlnTaskExists(work->cameraTask) != true)
    {
        work->cameraTask = NULL;
        work->cameraHeading = func_001a5aa0(func_004cb2f0((void*)camera->object.object.parent));
    }

    if (work->state == 5)
    {
        return KWLNTASK_STOP;
    }
    if (work->state == 2)
    {
        if (kwlnTaskExists(work->eventTask) != true)
        {
            func_001e1300(K_Field_Get()->playerPadTask, 0);
            K_FldEvent_001cd650(K_Field_Get()->eventTask, false);
            work->state = 1;
        }
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 0)
    {
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    if (work->state != 1 || work->controlMode == 1 || work->controlFlags == 1)
    {
        return KWLNTASK_CONTINUE;
    }

    pad = &gPads[HPAD_PORT_1];
    buttons = pad->btn[0].pressed;
    moveY = (f32)(u8)pad->lstickY - 128.0f;
    if ((buttons & HPAD_BTN_UP) != 0)
    {
        moveY = -128.0f;
    }
    else if ((buttons & HPAD_BTN_DOWN) != 0)
    {
        moveY = 128.0f;
    }
    moveX = (f32)(u8)pad->lstickX - 128.0f;
    if ((buttons & HPAD_BTN_LEFT) != 0)
    {
        moveX = -128.0f;
    }
    else if ((buttons & HPAD_BTN_RIGHT) != 0)
    {
        moveX = 128.0f;
    }
    rightY = (f32)(u8)pad->rstickY - 128.0f;
    rightX = (f32)(u8)pad->rstickX - 128.0f;
    cameraInput = 0;

    if ((buttons & (HPAD_BTN_R2 | HPAD_BTN_R1)) != 0 || rightX > 48.0f)
    {
        cameraInput = 1;
        if (K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
        {
            if ((buttons & (HPAD_BTN_R2 | HPAD_BTN_R1)) != 0 &&
                (buttons & HPAD_BTN_CIRCLE) != 0 && work->cameraTask == NULL)
            {
                work->cameraHeading -= 90.0f;
                if (work->cameraHeading < 0.0f)
                {
                    work->cameraHeading += 360.0f;
                }
                heading = (s32)work->cameraHeading;
                work->cameraTask = func_001d6630(task, 10, heading);
                /* Continue with movement processing after starting camera task. */
            }
            else if ((buttons & (HPAD_BTN_R2 | HPAD_BTN_R1)) == 0 ||
                     (buttons & HPAD_BTN_CIRCLE) == 0)
            {
                f32 cameraSpeed;

                cameraSpeed = -1.0f;
                if (datGetFlag(0x189) == true)
                {
                    cameraSpeed = -cameraSpeed;
                }
                func_001d5e30(K_Field_Get()->cameraCtlTask, cameraSpeed);
                /* Continue with movement processing after updating camera pan. */
            }
        }
    }
    else if ((buttons & (HPAD_BTN_L2 | HPAD_BTN_L1)) != 0 || rightX < -48.0f)
    {
        cameraInput = 1;
        if (K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
        {
            if ((buttons & (HPAD_BTN_L2 | HPAD_BTN_L1)) != 0 &&
                (buttons & HPAD_BTN_CIRCLE) != 0 && work->cameraTask == NULL)
            {
                work->cameraHeading += 90.0f;
                if (work->cameraHeading >= 360.0f)
                {
                    work->cameraHeading -= 360.0f;
                }
                heading = (s32)work->cameraHeading;
                work->cameraTask = func_001d6630(task, 10, heading);
                /* Continue with movement processing after starting camera task. */
            }
            else if ((buttons & (HPAD_BTN_L2 | HPAD_BTN_L1)) == 0 ||
                     (buttons & HPAD_BTN_CIRCLE) == 0)
            {
                f32 cameraSpeed;

                cameraSpeed = 1.0f;
                if (datGetFlag(0x189) == true)
                {
                    cameraSpeed = -cameraSpeed;
                }
                func_001d5e30(K_Field_Get()->cameraCtlTask, cameraSpeed);
                /* Continue with movement processing after updating camera pan. */
            }
        }
    }
    if (cameraInput == 0 && (buttons & HPAD_BTN_CROSS) == 0 &&
        (pad->btn[0].justPressed & HPAD_BTN_CIRCLE) != 0 &&
        K_FldCamera_GetType(K_Field_Get()->cameraCtlTask) == FLDCAMERA_TYPE_0)
    {
        work->cameraTask = func_001d6270(task, 10, -1);
        return KWLNTASK_CONTINUE;
    }

    stationary = moveX >= -48.0f && moveX <= 48.0f && moveY >= -48.0f && moveY <= 48.0f;

    if (stationary)
    {
        forceAnimation = 0;
        if (work->stationaryFrames < 4)
        {
            work->stationaryFrames++;
            return KWLNTASK_CONTINUE;
        }
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
        if (mdlAnimGetId(work->mdl, 0) >= 6 && work->mdl->animSlots[0].anim.isAnimEnd == 1)
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
        return KWLNTASK_CONTINUE;
    }

    cameraFrame = (RwFrame*)camera->object.object.parent;
    cameraMat = *RwFrameGetLTM(cameraFrame);
    playerFrame = mdlGetClumpFrame(work->mdl);
    playerMat = *RwFrameGetLTM(playerFrame);
    func_004c2fb0(&cameraMat, &cameraMat);
    cameraHeading = -func_0052ea18(cameraMat.up.x, cameraMat.right.x) * 180.0f / 3.14159265f;
    func_004c2fb0(&playerMat, &playerMat);
    playerHeading = -func_0052ea18(playerMat.up.x, playerMat.right.x) * 180.0f / 3.14159265f;
    inputHeading = func_001b02c0(0, 0);

    if (cameraHeading < 0.0f)
    {
        cameraHeading += 360.0f;
    }
    if (playerHeading < 0.0f)
    {
        playerHeading += 360.0f;
    }
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 0.0f;
    rotateMat.right.x = 1.0f;
    rotateMat.right.y = 0.0f;
    rotateMat.right.z = 0.0f;
    rotateMat.up.x = 0.0f;
    rotateMat.up.y = 1.0f;
    rotateMat.up.z = 0.0f;
    rotateMat.at.x = 0.0f;
    rotateMat.at.y = 0.0f;
    rotateMat.at.z = 1.0f;
    rotateMat.pos.x = 0.0f;
    rotateMat.pos.y = 0.0f;
    rotateMat.pos.z = 0.0f;
    rotateMat.flags = 0x20003;
    rotateMat.pad1 = 0;
    rotateMat.pad2 = 0;
    rotateMat.pad3 = 0;
    RwMatrixRotate(&rotateMat, &axis, cameraHeading, rwCOMBINEPOSTCONCAT);
    RwMatrixRotate(&rotateMat, &axis, inputHeading, rwCOMBINEPOSTCONCAT);
    rotated = func_001e1590(work->rotateTask, &rotateMat, playerHeading, cameraHeading + inputHeading);
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
    K_FldFrame_CtlUpdateMdlMat(work->collisCtlTask, &rotateMat);

    if (moveX >= -48.0f && moveX <= 48.0f)
    {
        moveX = 0.0f;
    }
    if (moveY >= -48.0f && moveY <= 48.0f)
    {
        moveY = 0.0f;
    }
    movement = sqrtf(moveX * moveX + moveY * moveY);

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
        speed = 13.0f * sinf((movement / 128.0f) * (3.14159265f * 0.5f));
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
        work->moveTimer = 0;
        work->stationaryFrames = 0;
    }
    else
    {
        work->moveTimer = 0;
        work->stationaryFrames = 0;
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
asm void* func_001e1840(void)
{
    .set noreorder
    addiu $v0, $gp, -0x4a38
    jr $ra
    nop
}