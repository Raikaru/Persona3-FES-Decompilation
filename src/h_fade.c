#include "h_fade.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "libm.h"

typedef struct FadeDayEpl FadeDayEpl;
typedef struct FadeDayTmx FadeDayTmx;
typedef struct HSfdAsyncEntry HSfdAsyncEntry;

extern const f32 DAT_007caf38;
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
typedef struct HFadeRwGlobals
{
    u8 pad[0x88];
    RwReal zBufferNear;
    RwReal zBufferFar;
    RwRenderStateSetFunc setRenderState;
    RwRenderStateGetFunc getRenderState;
    u8 unkData[0x08];
    RwIm2DRenderPrimitiveFunction fpIm2DRenderPrimitive;
} HFadeRwGlobals;



extern FadeDayEpl* func_0034fcd0(const void* eplBlob);
extern void func_0034fcf0(FadeDayEpl* epl);
extern void func_0034fd30(FadeDayEpl* epl);
extern void func_0034fd70(FadeDayEpl* epl, s32 layer);
extern void func_0034fdf0(FadeDayEpl* epl, const RwV3d* position);
extern void func_0034ff70(FadeDayEpl* epl, f32 scalar);
extern void func_0034ff90(FadeDayEpl* epl, const RwRGBA* color);
extern void* func_0010c1a0(void* param_1, const char* path, ...);
extern void* func_0010c3a0(void* stream, u32* finished, u32 param_3);
extern void func_001140d0(u32 rgba, s32 width, s32 height, const FadeDayTmx* texture,
                           f32 depthOffset, f32 x, f32 y);
extern void func_004d0f00(void* resource);

static s16 sFadeType;                  // 007cdf08
static s16 sFadeCounter;               // 007cdf04
static s16 sFadeDuration;              // 007cdf00. In frames
static s16 sFadeState;                 // 007cdefc
static u8 sFadeRed;                    // 007cdef8
static u8 sbssPadRed[3];
static u8 sFadeGreen;                  // 007cdef4
static u8 sbssPadGreen[3];
static u8 sFadeBlue;                   // 007cdef0
static s16 sFadeDayEplAlphaFrame;      // 007cdeec
static HSfdAsyncEntry* sFadeDayTmxRequest; // 007cdee8
static FadeDayTmx* sFadeDayTmx;        // 007cdee4
static FadeDayEpl* sFadeDayEpl;        // 007cdee0
static KwlnTask* sMaestroInTask;       // 007cdedc
static KwlnTask* sMaestroOutTask;      // 007cded8
static u32 sFadeActive;                // 007cded4

static HCdvd* cdvds[8]; // 007e39d0

static void H_Fade_Anim();
static void H_Fade_Transition();
static void H_Fade_White();
static void H_Fade_Day();
static void H_Fade_Custom();

// FUN_00107020
void H_Fade_ReadPak()
{
    HCdvd* cdvd;

    cdvd = H_Cdvd_Request("camp/fade_pak.pak", HCDVD_FILEARCHIVE);
    cdvds[0] = cdvd;
    H_Cdvd_ReadSync(cdvd);
}

// FUN_00107060
void H_Fade_Main()
{
    RwRenderStateSetFunc* setRenderState;

    setRenderState = &rwGlobals.device.setRenderState;

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    if (sFadeActive)
    {
        switch (sFadeType)
        {
            case HFADE_ANMLR:   // fallthrough
            case HFADE_ANMTIME: // fallthrough
            case HFADE_ANMAREA: // fallthrough
            case HFADE_ANMMOVE: H_Fade_Anim(); break;

            case HFADE_TRANSITION:  H_Fade_Transition(); break;
            case HFADE_TRANSITION2: H_Fade_Transition(); break;

            case HFADE_WHITE:  H_Fade_White();  break;
            case HFADE_DAY:    H_Fade_Day();    break;
            case HFADE_CUSTOM: H_Fade_Custom();
        }
    }
}

// FUN_001071b0
void H_Fade_Clear()
{
    if (sFadeActive)
    {
        sFadeActive = false;

        if (sMaestroOutTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
            sMaestroOutTask = NULL;
        }
    }
}

#pragma opt_loop_invariants on
// FUN_001071f0 MATCHING
static void H_Fade_Anim()
{
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 z;
    f32 red;
    f32 green;
    f32 blue;
    f32 alpha;
    s32 i;

    switch (sFadeState)
    {
        case HFADE_STATE_INIT_OUT:
            switch (sFadeType)
            {
                case HFADE_ANMLR:
                    sMaestroOutTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_lr_0a.anm");
                    break;
                case HFADE_ANMTIME:
                    sMaestroOutTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_time_1a.anm");
                    break;
                case HFADE_ANMAREA:
                    sMaestroOutTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_area_2a.anm");
                    break;
                case HFADE_ANMMOVE:
                    sMaestroOutTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_move_4a.anm");
                    break;
            }

            H_Maestro_00111f20(sMaestroOutTask, true);
            sFadeState = HFADE_STATE_MAESTROOUT;
            // fallthrough

        case HFADE_STATE_MAESTROOUT:
            if (H_Maestro_FinishedInit(sMaestroOutTask))
            {
                H_Maestro_RequestDraw(sMaestroOutTask);
                sFadeState = HFADE_STATE_OUT;
            }
            goto anim_return;

        case HFADE_STATE_OUT:
            if (H_Maestro_00111cb0(sMaestroOutTask))
            {
                sFadeState = HFADE_STATE_HOLD;

                if (sMaestroOutTask != NULL)
                {
                    kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                    sMaestroOutTask = NULL;
                }
            }
            goto anim_return;

        case HFADE_STATE_HOLD: goto anim_render;
        
        case HFADE_STATE_INIT_IN: 
            switch (sFadeType)
            {
                case HFADE_ANMLR:
                    sMaestroInTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_lr_0b.anm");
                    break;
                case HFADE_ANMTIME:
                    sMaestroInTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_time_1b.anm");
                    break;
                case HFADE_ANMAREA:
                    sMaestroInTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_area_2b.anm");
                    break;
                case HFADE_ANMMOVE:
                    sMaestroInTask = H_Maestro_CreateTask(NULL, 6325, "camp/fade/if_move_4b.anm");
                    break;
            }
            H_Maestro_SetShouldLoop(sMaestroInTask, false);
            sFadeState = HFADE_STATE_MAESTROIN;
            goto anim_render;

        case HFADE_STATE_IN:
            if (kwlnTaskGetState(sMaestroInTask) != KWLNTASK_STATE_DESTROY)
            {
                goto anim_in_return;
            }
            sFadeActive = false;
            sMaestroInTask = NULL;

anim_in_return:
            return;

        case HFADE_STATE_MAESTROIN:
            if (H_Maestro_FinishedInit(sMaestroInTask))
            {
                H_Maestro_RequestDraw(sMaestroInTask);

                if (sMaestroOutTask != NULL)
                {
                    kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                    sMaestroOutTask = NULL;
                }

                sFadeState = HFADE_STATE_IN;
            }
            goto anim_render;

        default: goto anim_return;
    }

anim_return:
    return;

anim_render:
    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    red = 15.0f;
    green = 31.0f;
    blue = 40.0f;
    alpha = 255.0f;
    i = 0;
    z = ((HFadeRwGlobals*)rwGlobals_abs)->zBufferNear - 100.0f;
    for (; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = red;
        vertices[i].u.els.color.g = green;
        vertices[i].u.els.color.b = blue;
        vertices[i].u.els.color.a = alpha;
    }

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;

    vertices[1].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[1].u.els.scrVertex.y = 0.0f;

    vertices[2].u.els.scrVertex.x = 0.0f;
    vertices[2].u.els.scrVertex.y = SCREEN_HEIGHT;

    vertices[3].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[3].u.els.scrVertex.y = SCREEN_HEIGHT;
    (*((HFadeRwGlobals*)rwGlobals_abs)->setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
    (*((HFadeRwGlobals*)rwGlobals_abs)->fpIm2DRenderPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_001075b0
static void H_Fade_Transition()
{
    RwRenderStateSetFunc* setRenderState;
    RwIm2DVertex vertices[4];
    s16 alpha;
    f32 recipZ;
    f32 z;
    s16 i;

    setRenderState = &rwGlobals.device.setRenderState;

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    switch (sFadeState)
    {
        case HFADE_STATE_INIT_OUT:
            sFadeState = HFADE_STATE_OUT;
            sFadeCounter = 0;
            // fallthrough

        case HFADE_STATE_OUT:
            sFadeCounter++;
            if (sFadeCounter == sFadeDuration)
            {
                sFadeState = HFADE_STATE_HOLD;
            }
            break;

        case HFADE_STATE_HOLD:
            sFadeCounter = sFadeDuration;

            if (sMaestroOutTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                sMaestroOutTask = NULL;
            }

            if (sMaestroInTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroInTask);
                sMaestroInTask = NULL;
            }
            break;

        case HFADE_STATE_INIT_IN:
            if (sMaestroOutTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                sMaestroOutTask = NULL;
            }

            if (sMaestroInTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroInTask);
                sMaestroInTask = NULL;
            }

            sFadeCounter = sFadeDuration;
            sFadeState = HFADE_STATE_IN;
            break;

        case HFADE_STATE_IN:
            sFadeCounter--;
            if (sFadeCounter == 0)
            {
                sFadeActive = false;
            }
            break;
    }

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    alpha = (sFadeCounter * 255) / sFadeDuration;
    i = 0;
    z = RwIm2DGetNearScreenZ() - 100.0f;
    for (; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = 15.0f;
        vertices[i].u.els.color.g = 31.0f;
        vertices[i].u.els.color.b = 40.0f;
        vertices[i].u.els.color.a = (f32)alpha;
    }

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[1].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[1].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.x = 0.0f;
    vertices[2].u.els.scrVertex.y = SCREEN_HEIGHT;
    vertices[3].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[3].u.els.scrVertex.y = SCREEN_HEIGHT;

    (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
    RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants on

// FUN_001078a0
static void H_Fade_White()
{
    RwRenderStateSetFunc* setRenderState;
    RwIm2DVertex vertices[4];
    s16 alpha;
    f32 recipZ;
    s16 i;
    f32 z;
    f32 col;
    setRenderState = &rwGlobals.device.setRenderState;

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    switch (sFadeState)
    {
        case HFADE_STATE_INIT_OUT:
            sFadeState = HFADE_STATE_OUT;
            sFadeCounter = 0;
            // fallthrough
        case HFADE_STATE_OUT:
            sFadeCounter++;
            if (sFadeCounter == sFadeDuration)
            {
                sFadeState = HFADE_STATE_HOLD;
            }
            break;

        case HFADE_STATE_HOLD: break;
        
        case HFADE_STATE_INIT_IN: 
            sFadeCounter = sFadeDuration;
            sFadeState = HFADE_STATE_IN;
            break;

        case HFADE_STATE_IN:
            sFadeCounter--;
            if (sFadeCounter == 0)
            {
                sFadeActive = false;
            }
    }
    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    alpha = (sFadeCounter * 255) / sFadeDuration;
    i = 0;
    z = RwIm2DGetNearScreenZ() - 100.0f;
    col = 255.0f;
    for (; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = col;
        vertices[i].u.els.color.g = col;
        vertices[i].u.els.color.b = col;
        vertices[i].u.els.color.a = (f32)alpha;
    }

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;

    vertices[1].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[1].u.els.scrVertex.y = 0.0f;

    vertices[2].u.els.scrVertex.x = 0.0f;
    vertices[2].u.els.scrVertex.y = SCREEN_HEIGHT;

    vertices[3].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[3].u.els.scrVertex.y = SCREEN_HEIGHT;

    (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
    RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);
}

#pragma opt_loop_invariants on
// FUN_00107b20 NONMATCHING
static void H_Fade_Day()
{
    RwRenderStateSetFunc* setRenderState;
    RwIm2DVertex vertices[4];
    RwV3d origin;
    RwRGBA eplColor;
    u32 fileSizeOut;
    u32 fileSizeIn;
    u32 resourceReady;
    u32 drawDayTexture;
    f32 recipZ;
    f32 z;
    s16 alpha;
    s16 i;

    setRenderState = &((HFadeRwGlobals*)rwGlobals_abs)->setRenderState;

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    drawDayTexture = false;
    switch (sFadeState)
    {
        case HFADE_STATE_INIT_OUT:
            sFadeState = HFADE_STATE_OUT;
            sFadeCounter = 0;
            // fallthrough

        case HFADE_STATE_OUT:
            sFadeCounter++;
            if (sFadeCounter == sFadeDuration)
            {
                sFadeState = HFADE_STATE_HOLD;
            }
            break;

        case HFADE_STATE_HOLD:
            if (sFadeDayEpl == NULL)
            {
                sFadeDayEpl = func_0034fcd0(H_Cdvd_CacheFindFile("camp/camp/I_25.EPL", &fileSizeOut));
                sFadeDayEplAlphaFrame = 0;
            }

            origin.z = 0.0f;
            origin.y = 0.0f;
            origin.x = 0.0f;
            func_0034fdf0(sFadeDayEpl, &origin);
            func_0034ff70(sFadeDayEpl, 1.0f);
            func_0034fd30(sFadeDayEpl);

            eplColor.r = 255;
            eplColor.g = 255;
            eplColor.b = 255;
            if (sFadeDayEplAlphaFrame >= 100)
            {
                eplColor.a = 255;
            }
            else
            {
                sFadeDayEplAlphaFrame++;
                eplColor.a = (u8)((sFadeDayEplAlphaFrame * 255) / 100);
            }
            func_0034ff90(sFadeDayEpl, &eplColor);
            func_0034fd70(sFadeDayEpl, 7);
            sFadeCounter = sFadeDuration;
            break;

        case HFADE_STATE_INIT_IN:
            if (sMaestroOutTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                sMaestroOutTask = NULL;
            }

            if (sMaestroInTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroInTask);
                sMaestroInTask = NULL;
            }

            sFadeCounter = sFadeDuration;
            if (sFadeDayEpl == NULL)
            {
                sFadeDayEpl = func_0034fcd0(H_Cdvd_CacheFindFile("camp/camp/I_25.EPL", &fileSizeIn));
                sFadeDayEplAlphaFrame = 0;
            }

            origin.z = 0.0f;
            origin.y = 0.0f;
            origin.x = 0.0f;
            func_0034fdf0(sFadeDayEpl, &origin);
            func_0034ff70(sFadeDayEpl, 1.0f);
            func_0034fd30(sFadeDayEpl);
            func_0034fd70(sFadeDayEpl, 7);

            if (sFadeDayTmx != NULL)
            {
                func_004d0f00(sFadeDayTmx);
                sFadeDayTmx = NULL;
            }

            sFadeDayTmxRequest = func_0010c1a0(NULL, "camp/camp/i_time25_01.tmx",
                                                 NULL, NULL, NULL, NULL, NULL, NULL,
                                                 NULL, NULL, "h_fade.c", 0x223);
            sFadeState = HFADE_STATE_MAESTROIN;
            break;

        case HFADE_STATE_IN:
            sFadeCounter--;
            if (sFadeCounter == 0)
            {
                func_0034fcf0(sFadeDayEpl);
                sFadeDayEpl = NULL;
                sFadeActive = false;

                if (sFadeDayTmx != NULL)
                {
                    func_004d0f00(sFadeDayTmx);
                }
                sFadeDayTmx = NULL;
            }
            else
            {
                origin.z = 0.0f;
                origin.y = 0.0f;
                origin.x = 0.0f;
                func_0034fdf0(sFadeDayEpl, &origin);
                func_0034ff70(sFadeDayEpl, 1.0f);
                func_0034fd30(sFadeDayEpl);
                drawDayTexture = true;
            }
            break;

        case HFADE_STATE_MAESTROIN:
            origin.z = 0.0f;
            origin.y = 0.0f;
            origin.x = 0.0f;
            func_0034fdf0(sFadeDayEpl, &origin);
            func_0034ff70(sFadeDayEpl, 1.0f);
            func_0034fd30(sFadeDayEpl);
            func_0034fd70(sFadeDayEpl, 7);

            sFadeDayTmx = func_0010c3a0(sFadeDayTmxRequest, &resourceReady, 0);
            if (resourceReady == 0)
            {
                sFadeDayTmx = NULL;
            }
            else
            {
                sFadeDayTmxRequest = NULL;
                sFadeState = HFADE_STATE_IN;
            }
            break;
    }

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    alpha = (sFadeCounter * 255) / sFadeDuration;
    i = 0;
    z = ((HFadeRwGlobals*)rwGlobals_abs)->zBufferNear - 100.0f;
    for (; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = 15.0f;
        vertices[i].u.els.color.g = 31.0f;
        vertices[i].u.els.color.b = 40.0f;
        vertices[i].u.els.color.a = (f32)alpha;
    }

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[1].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[1].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.x = 0.0f;
    vertices[2].u.els.scrVertex.y = SCREEN_HEIGHT;
    vertices[3].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[3].u.els.scrVertex.y = SCREEN_HEIGHT;

    (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
    if (!drawDayTexture)
    {
        (*((HFadeRwGlobals*)rwGlobals_abs)->fpIm2DRenderPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }

    if (drawDayTexture)
    {

    {
        u32 packedColor;
        s32 travel;
        s32 halfTravel;

        if (sFadeState == HFADE_STATE_IN)
        {
            s32 degrees;
            s32 alphaByte;

            if (sFadeCounter != 0)
            {
                degrees = (sFadeCounter * 90) / sFadeDuration;
            }
            else
            {
                degrees = 90;
            }

            alphaByte = (s32)(sinf((DAT_007caf38 * (f32)degrees) / 180.0f) * 255.0f);
            packedColor = (u32)alphaByte | 0x00242000;
        }
        else
        {
            packedColor = 0x002420FF;
        }

        travel = ((sFadeDuration - sFadeCounter) * 5000) / sFadeDuration;
        halfTravel = travel / 2;
        func_001140d0(packedColor, travel + 640, travel + 640, sFadeDayTmx,
                       99.0f, (f32)-halfTravel, (f32)(-96 - halfTravel));
    }
    }
}

#pragma opt_loop_invariants off
// FUN_001081e0 NONMATCHING
static void H_Fade_Custom()
{
    RwRenderStateSetFunc* setRenderState;
    RwIm2DVertex vertices[4];
    f32 alpha;
    f32 recipZ;
    f32 z;
    f32 red;
    f32 green;
    f32 blue;
    s16 i;
    setRenderState = &((HFadeRwGlobals*)rwGlobals_abs)->setRenderState;

    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    switch (sFadeState)
    {
        case HFADE_STATE_INIT_OUT:
            sFadeState = HFADE_STATE_OUT;
            sFadeCounter = 0;
            // fallthrough

        case HFADE_STATE_OUT:
            sFadeCounter++;
            if (sFadeCounter == sFadeDuration)
            {
                sFadeState = HFADE_STATE_HOLD;
            }
            break;

        case HFADE_STATE_HOLD:
            sFadeCounter = sFadeDuration;

            if (sMaestroOutTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                sMaestroOutTask = NULL;
            }

            if (sMaestroInTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroInTask);
                sMaestroInTask = NULL;
            }
            break;

        case HFADE_STATE_INIT_IN:
            if (sMaestroOutTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroOutTask);
                sMaestroOutTask = NULL;
            }

            if (sMaestroInTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(sMaestroInTask);
                sMaestroInTask = NULL;
            }

            sFadeCounter = sFadeDuration;
            sFadeState = HFADE_STATE_IN;
            break;

        case HFADE_STATE_IN:
            sFadeCounter--;
            if (sFadeCounter == 0)
            {
                sFadeActive = false;
            }
            break;
    }
    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    alpha = (f32)((sFadeCounter * 255) / sFadeDuration);
    red = (f32)sFadeRed;
    green = (f32)sFadeGreen;
    blue = (f32)sFadeBlue;
    i = 0;
    z = ((HFadeRwGlobals*)rwGlobals_abs)->zBufferNear - 100.0f;
    for (; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = red;
        vertices[i].u.els.color.g = green;
        vertices[i].u.els.color.b = blue;
        vertices[i].u.els.color.a = alpha;
    }

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[1].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[1].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.x = 0.0f;
    vertices[2].u.els.scrVertex.y = SCREEN_HEIGHT;
    vertices[3].u.els.scrVertex.x = SCREEN_WIDTH;
    vertices[3].u.els.scrVertex.y = SCREEN_HEIGHT;

    (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
    (*((HFadeRwGlobals*)rwGlobals_abs)->fpIm2DRenderPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
}

// FUN_00108570
u32 H_Fade_FadeOut()
{
    if (!sFadeActive)
    {
        sFadeDuration = 15;
        sFadeActive = true;
        sFadeState = HFADE_STATE_INIT_OUT;
        sFadeRed = 0;
        sFadeBlue = 0;
        sFadeGreen = 0;
        sFadeType = HFADE_ANMLR;
    }
    else
    {
        return false;
    }

    return sFadeActive;
}

// FUN_001085c0
u32 H_Fade_FadeIn()
{
    if (sFadeActive && sFadeState == HFADE_STATE_HOLD)
    {
        sFadeDuration = 15;
        sFadeActive = true;
        sFadeState = HFADE_STATE_INIT_IN;

        if (datGetTime() == CALENDAR_TIME_DARK_HOUR && datGetFlag(5138))
        {
            datSetFlag(5138, false);

            sFadeDuration = 40;
            sFadeCounter = 40;
            sFadeType = HFADE_DAY;
        }

        return true;
    }

    return false;
}

// FUN_00108670
void H_Fade_SetType(s16 type)
{
    sFadeType = type;
}

// FUN_00108680
void H_Fade_SetCustomColor(u8 r, u8 g, u8 b)
{
    sFadeRed = r;
    sFadeGreen = g;
    sFadeBlue = b;
}

// FUN_001086a0
void H_Fade_SetDuration(s16 duration)
{
    sFadeDuration = duration;

    if (sFadeCounter > duration)
    {
        sFadeCounter = duration;
    }
}

// FUN_001086d0. Same thing as 'H_Fade_IsFadeOutDone'
u32 H_Fade_IsHolding()
{
    if (sFadeActive && sFadeState == HFADE_STATE_HOLD)
    {
        return true;
    }

    return false;
}

// FUN_00108710. Same thing as 'H_Fade_IsHolding'
u32 H_Fade_IsFadeOutDone()
{
    if (sFadeActive)
    {
        return sFadeState == HFADE_STATE_HOLD;
    }

    return true;
}
