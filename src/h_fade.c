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

extern f32 DAT_007caf38;
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


static inline f32 MaestroBig2_mulFirst(f32 left, f32 right)
{
    return right * left;
}

extern FadeDayEpl* func_0034fcd0(const void* eplBlob);
extern void func_0034fcf0(FadeDayEpl* epl);
extern void func_0034fd30(FadeDayEpl* epl);
extern void func_0034fd70(FadeDayEpl* epl, s32 layer);
extern void func_0034fdf0(FadeDayEpl* epl, const RwV3d* position);
extern void func_0034ff70(FadeDayEpl* epl, f32 scalar);
extern void func_0034ff90(FadeDayEpl* epl, const RwRGBA* color);
extern void* func_0010c1a0(void* param_1, const char* path, ...);
extern void* func_0010c3a0(void* stream, u32* finished, u32 param_3);
extern void func_001140d0(f32 depthOffset, u32 rgba, f32 x, f32 y,
                           s32 width, s32 height, const FadeDayTmx* texture);
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
#pragma alias sFadeState_sda sFadeState
extern s16 sFadeState_sda __attribute__((section(".sdata")));

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

/* Removing this loses FUN_001071f0 (MATCH nd0 -> MISMATCH nd144) - measured W161. */
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

/* Removing this loses FUN_001075b0 (MATCH nd0 -> MISMATCH nd176) and 2 more - measured W161. */
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

/* W420 sine temporary plus mixed-order mulFirst: nd30,obj1728/window1728 (rate 0.017361) -> nd28,obj1728/window1728 (rate 0.016204). */
/* W421 row classification: verify nd28, object1728/window1728, rate0.016204.
 * Offsets 0x650/0x654/0x658/0x660/0x664/0x668 are
 * mflo $a1 / mflo $a2; sra $v1,$a1,1 / sra $a1,$a2,1;
 * bgez $a1,0x108188 / bgez $a2,0x108188; addiu $v0,$a1,1 / addiu $v0,$a2,1;
 * sra $v1,$v0,1 / sra $a1,$v0,1; and negu $v0,$v1 / negu $v1,$a1.
 * Offsets 0x66c/0x670/0x674/0x678/0x67c are
 * mtc1 $v0,$f0 / addiu $v0,$zero,-0x60; nop / subu $v0,$v0,$a1;
 * cvt.s.w $f13,$f0 / mtc1 $v1,$f0; addiu $v0,$zero,-0x60 / nop;
 * subu $v0,$v0,$v1 / cvt.s.w $f13,$f0. Offset 0x694 is
 * addiu $a1,$a1,0x280 / addiu $a1,$a2,0x280 (candidate / retail):
 * travel/halfTravel register colouring and argument setup. */

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
    switch (sFadeState_sda)
    {
        case HFADE_STATE_INIT_OUT:
            sFadeState_sda = HFADE_STATE_OUT;
            sFadeCounter = 0;
            // fallthrough

        case HFADE_STATE_OUT:
            sFadeCounter++;
            if (sFadeCounter == sFadeDuration)
            {
                sFadeState_sda = HFADE_STATE_HOLD;
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
            sFadeState_sda = HFADE_STATE_MAESTROIN;
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
                sFadeState_sda = HFADE_STATE_IN;
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
        s32 halfTravel;
        s32 travel;
        if (sFadeState_sda == HFADE_STATE_IN)
        {
            f32 degrees;
            f32 sine;
            s32 alphaByte;

            if (sFadeCounter != 0)
            {
                degrees = (sFadeCounter * 90) / sFadeDuration;
            }
            else
            {
                degrees = 90.0f;
            }

            sine = sinf((DAT_007caf38 * degrees) / 180.0f);
            alphaByte = (s32)MaestroBig2_mulFirst(255.0f, sine);
            packedColor = (u32)alphaByte | 0x00242000;
        }
        else
        {
            packedColor = 0x002420FF;
        }

        travel = ((sFadeDuration - sFadeCounter) * 5000) / sFadeDuration;
        halfTravel = travel / 2;
        func_001140d0(99.0f, packedColor, (f32)-halfTravel,
                      (f32)(-96 - halfTravel), travel + 640, travel + 640, sFadeDayTmx);
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
    i = 0;
    red = (f32)sFadeRed;
    green = (f32)sFadeGreen;
    blue = (f32)sFadeBlue;
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


#include "h_snd.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "temporary.h"

#define HSND_CHANNEL_COUNT 6
#define HSND_SLOT_COUNT    6
typedef struct HsndBackendControl
{
    u32 flags;               /* 0x00 */
    u32 voiceCount;          /* 0x04 */
    u32 timeout;             /* 0x08 */
    u32 padC;                /* 0x0C */
    u32 pending;             /* 0x10 */
    u8 class;                /* 0x14 */
    u8 pad15[3];
    u32 data18;              /* 0x18 */
    u32 data1C;              /* 0x1C */
    u32 data20;              /* 0x20 */
    u32 data24;              /* 0x24 */
} HsndBackendControl;



static HsndChannel sChannels[16];
static HsndSlotWork sSlotWork[HSND_SLOT_COUNT];
#pragma alias sSlotWork_alt sSlotWork
extern u8 sSlotWork_alt[];
static HsndBackendControl sBackendControls[HSND_CHANNEL_COUNT];
static s16 sBgmRestartCountdown;
 #pragma alias sBgmRestartCountdown_alt sBgmRestartCountdown
 extern s16 sBgmRestartCountdown_alt[];
static void* sChannelData0[HSND_CHANNEL_COUNT];
static void* sChannelData1[HSND_CHANNEL_COUNT];
static void* sChannelData2[HSND_CHANNEL_COUNT];
static void* sChannelData3[HSND_CHANNEL_COUNT];
static u8 sChannelMap[HSND_CHANNEL_COUNT][8];

/* Retail D_005D4014: BGM id is the direct 12-byte-record index. */
static const char* const sBgmAdxStrings[116][3] =
{
    {"01.ADX", NULL, NULL},
    {"01.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"19.ADX", NULL, NULL},
    {"20.ADX", NULL, NULL},
    {"21.ADX", NULL, NULL},
    {"22.ADX", NULL, NULL},
    {"23.ADX", NULL, NULL},
    {"24.ADX", NULL, NULL},
    {"25.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"27.ADX", NULL, NULL},
    {"28.ADX", NULL, NULL},
    {"29.ADX", NULL, NULL},
    {"30.ADX", NULL, NULL},
    {"31.ADX", NULL, NULL},
    {"32.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"35.ADX", NULL, NULL},
    {"36.ADX", NULL, NULL},
    {"37.ADX", NULL, NULL},
    {"38.ADX", NULL, NULL},
    {"39.ADX", NULL, NULL},
    {"40.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"43.ADX", NULL, NULL},
    {"44.ADX", NULL, NULL},
    {"45.ADX", NULL, NULL},
    {"46.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"50.ADX", NULL, NULL},
    {"51.ADX", NULL, NULL},
    {"52.ADX", NULL, NULL},
    {"53.ADX", NULL, NULL},
    {"54.ADX", NULL, NULL},
    {"55.ADX", NULL, NULL},
    {"56.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"60.ADX", NULL, NULL},
    {"61.ADX", NULL, NULL},
    {"62.ADX", NULL, NULL},
    {"63.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"70.ADX", NULL, NULL},
    {"71.ADX", NULL, NULL},
    {"72.ADX", NULL, NULL},
    {"73.ADX", NULL, NULL},
    {"74.ADX", NULL, NULL},
    {"75.ADX", NULL, NULL},
    {"76.ADX", NULL, NULL},
    {"77.ADX", NULL, NULL},
    {"78.ADX", NULL, NULL},
    {"79.ADX", NULL, NULL},
    {"80.ADX", NULL, NULL},
    {"81.ADX", NULL, NULL},
    {"82.ADX", NULL, NULL},
    {"83.ADX", NULL, NULL},
    {"84.ADX", NULL, NULL},
    {"85.ADX", NULL, NULL},
    {"86.ADX", NULL, NULL},
    {"87.ADX", NULL, NULL},
    {"88.ADX", NULL, NULL},
    {"89.ADX", NULL, NULL},
    {"90.ADX", NULL, NULL},
    {"91.ADX", NULL, NULL},
    {"92.ADX", NULL, NULL},
    {"93.ADX", NULL, NULL},
    {"94.ADX", NULL, NULL},
    {"95.ADX", NULL, NULL},
    {"96.ADX", NULL, NULL},
    {"97.ADX", NULL, NULL},
    {"98.ADX", NULL, NULL},
    {"99.ADX", NULL, NULL},
    {"100.ADX", NULL, NULL},
    {"101.ADX", NULL, NULL},
    {"102.ADX", NULL, NULL},
    {"103.ADX", NULL, NULL},
    {"104.ADX", NULL, NULL},
    {"105.ADX", NULL, NULL},
    {"106.ADX", NULL, NULL},
    {"107.ADX", NULL, NULL},
    {"108.ADX", NULL, NULL},
    {"109.ADX", NULL, NULL},
    {"110.ADX", NULL, NULL},
    {"111.ADX", NULL, NULL},
    {"112.ADX", NULL, NULL},
    {"113.ADX", NULL, NULL},
    {"114.ADX", NULL, NULL},
    {"115.ADX", NULL, NULL},
};

/* ACSSND entry points used by the retail sound state machine. */
typedef struct HsndInitParams
{
    f32 outputLevel;
    u32 enabled;
    u32 initialized;
    u32 reserved;
} HsndInitParams;

static HsndInitParams sSndInitParams;

extern const f32 DAT_007cad28;
extern void func_0057f768(void* params);
extern void func_0054cfe8(void);
extern void func_0054d468(void);
extern void func_005497b0(s32 frames);
extern void* func_0054d080(void* control);
extern void func_0054d250(void* handle, s32 value);
extern void func_0054d2e0(void* handle, s32 value);
extern void func_0054d4b8(s32 value);
extern void func_0054d4f0(s32 value);
extern void func_0054d528(s32 value);
extern void* func_0054d030(void* control, void* data0, void* data1);
extern void func_0054d220(void* handle, s32 frames);
extern void func_0054d238(void* handle, s32 value);
extern void func_0054d2b0(void* handle, s32 parameter);
extern u32 D_00960178[];
 #pragma alias H_Snd_FUN_00109df0_s16 H_Snd_FUN_00109df0
 extern u32 H_Snd_FUN_00109df0_s16(s16 slotIndex);

#define HSND_BACKEND_ALLOC(context, flags) \
    (*(void* (**)(void*, u32))D_00960178)((context), (flags))

// opt_loop_invariants on: func_00108740 normalized_diff 472 -> 451, object 1080/1152; off restores 472.
#pragma opt_loop_invariants on
// FUN_00108740 NONMATCHING
void func_00108740(void)
{
    void* context;
    void* backendData;
    void* (*backendAlloc)(void*, u32);
    s32 i;
    HsndSlotWork* slotWork;

    sSndInitParams.outputLevel = DAT_007cad28;
    sSndInitParams.enabled = true;
    sSndInitParams.initialized = true;
    sSndInitParams.reserved = 0;
    func_0057f768(&sSndInitParams);
    func_0054cfe8();
    func_0054d468();
    func_005497b0(30);

    memset(&sBackendControls[0], 0, sizeof(HsndBackendControl));
    sBackendControls[0].class = 1;
    sBackendControls[0].data18 = 0;
    sBackendControls[0].data1C = 0;
    sBackendControls[0].data20 = 0;
    sBackendControls[0].flags = 3;
    sBackendControls[0].voiceCount = 2;
    sBackendControls[0].timeout = 0xBB80;
    sBackendControls[0].pending = 1;
    context = func_0054d080(&sBackendControls[0]);
    backendAlloc = (void* (*)(void*, u32))D_00960178;
    backendData = backendAlloc(context, 0x40000);
    sChannelData0[0] = backendData;
    sChannelData1[0] = context;
    sChannels[0].handle = func_0054d030(&sBackendControls[0], backendData, context);
    func_0054d238(sChannels[0].handle, true);
    func_0054d220(sChannels[0].handle, 30);
    func_0054d2b0(sChannels[0].handle, 0x23);
    func_0054d250(sChannels[0].handle, 0xF);
    func_0054d528(0x3C);
    func_0054d4b8(0xF);
    func_0054d4f0(0xB4);
    func_0054d2e0(sChannels[0].handle, 10);

    memset(&sBackendControls[2], 0, sizeof(HsndBackendControl));
    sBackendControls[2].class = 2;
    sBackendControls[2].data18 = 0;
    sBackendControls[2].data1C = 0;
    sBackendControls[2].data20 = 0;
    sBackendControls[2].flags = 3;
    sBackendControls[2].voiceCount = 1;
    sBackendControls[2].timeout = 0x5DC0;
    sBackendControls[2].pending = 1;
    context = func_0054d080(&sBackendControls[2]);
    sChannelData0[2] = backendAlloc(context, 0x40000);
    sChannelData1[2] = context;
    sChannels[2].handle = NULL;

    memset(&sBackendControls[3], 0, sizeof(HsndBackendControl));
    sBackendControls[3].class = 3;
    sBackendControls[3].data18 = 0;
    sBackendControls[3].data1C = 0;
    sBackendControls[3].data20 = 0;
    sBackendControls[3].flags = 2;
    sBackendControls[3].voiceCount = 2;
    sBackendControls[3].timeout = 0x5DC0;
    sBackendControls[3].pending = 1;
    context = func_0054d080(&sBackendControls[3]);
    sChannelData0[3] = backendAlloc(context, 0x40000);
    sChannelData1[3] = context;

    sChannels[3].handle = NULL;
    memset(&sBackendControls[4], 0, sizeof(HsndBackendControl));
    sBackendControls[4].class = 3;
    sBackendControls[4].data18 = 0;
    sBackendControls[4].data1C = 0;
    sBackendControls[4].data20 = 0;
    sBackendControls[4].flags = 2;
    sBackendControls[4].voiceCount = 2;
    sBackendControls[4].timeout = 0x5DC0;
    sBackendControls[4].pending = 1;
    context = func_0054d080(&sBackendControls[4]);
    sChannelData0[4] = backendAlloc(context, 0x40000);
    sChannelData1[4] = context;

    sChannels[4].handle = NULL;
    slotWork = sSlotWork;
    for (i = 0; i < HSND_SLOT_COUNT; i++)
    {
        slotWork[i].state = 0;
        slotWork[i].completed = false;
    }
    for (i = 0; i < 16; i++)
    {
        sChannels[i].active = false;
        sChannels[i].previousId = 0;
        sChannels[i].state = HSND_CHANNEL_INACTIVE;
        sChannels[i].resetId = HSND_BGM_NONE;
    }
    sBgmRestartCountdown = 0;
}
#pragma opt_loop_invariants reset

extern void func_00540ec0(void);
extern void func_0051db00(s32 group, s32 left, s32 right, s32 rear);
extern void func_0054d060(void* handle);
extern void* func_0054d030(void* control, void* data0, void* data1);
extern void func_0054d0a0(void* handle, const char* name);
extern void func_0054d0b8(void* handle, void* data, s16 id);
extern void func_0054d0d0(void* handle, void* data0, void* data1);
extern void func_0054d0e8(void* handle, void* data, s32 parameter);
extern void func_0054d100(void* handle);
extern void func_0054d118(void* handle, s32 value);
extern s32 func_0054d130(void* handle);
extern s32 func_0054d148(void* handle);
extern void func_0054d1a8(void* handle, s32 value);
extern void func_0054d208(void* handle, s32 enabled);
extern void func_0054d220(void* handle, s32 frames);
extern void func_0054d238(void* handle, s32 value);
extern void func_0054d2b0(void* handle, s32 parameter);
extern void func_0054d328(void* handle);
extern void func_0054d3a8(void* handle, s32 value);
extern void func_00102530(void* handle, const char* name);
extern void func_001025c0(void* handle, const char* name);
extern void func_001024a0(void* source, const char* name, s32 flags, void* callback);
extern s32 func_0053c268(void* source);
extern void func_0010d6f0(s16 param1, s16 param2);
extern void func_0010d7b0(s16 param1, s16 param2, void* data0, u32 data0Size,
                           void* data1, u32 data1Size, void* data2, u32 data2Size);
extern s32 func_0010d910(s16 param1);
extern void func_0010da70(s16 bank, s16 cue);
extern void func_0010db60(s32 bank, s32 cue, s32 variant, s32 pan);
extern char D_007E39F0[];
extern u32 D_00960184[];
#define HSND_ALLOC(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184)(count, size, flags)

static HsndChannel* H_Snd_GetChannel(s32 index)
{
    if (index < 0 || index >= HSND_CHANNEL_COUNT)
    {
        return NULL;
    }

    return &sChannels[index];
}

static void H_Snd_ClearChannel(HsndChannel* channel)
{
    channel->active = false;
    channel->state = HSND_CHANNEL_INACTIVE;
    channel->id = HSND_BGM_NONE;
}

static void H_Snd_ApplyChannelFade(HsndChannel* channel, s32 frames)
{
    if (channel->handle != NULL)
    {
        func_0054d220(channel->handle, frames);
    }
}

// FUN_00108BC0
void func_00108bc0(void)
{
    func_00540ec0();
    func_0051db00(3, 0x80, 0x7F, 0x7F);

    {
        s16 i;

        for (i = 0; i < HSND_SLOT_COUNT; i++)
        {
            func_00108e80(&sSlotWork[i]);
        }
    }

    if (sChannels[0].active != false)
    {
        if (sChannels[0].gate != false && sBgmRestartCountdown_alt[0] != 0)
        {
            sBgmRestartCountdown_alt[0]--;
            if (sBgmRestartCountdown_alt[0] == 0)
            {
                func_0054d118(sChannels[0].handle, true);
            }
        }

        func_0054d3a8(sChannels[0].handle, false);
        {
            s32 status = func_0054d148(sChannels[0].handle);
            if (status == 3)
            {
                sChannels[0].active = false;
            }
            else if (status == 4)
            {
                func_00109070(0);
                H_Snd_00109180(0);
                func_0054d208(sChannels[0].handle, true);
            }
        }
    }

    {
        s32 i;
        s16 compareIndex;
        HsndChannel* channel;
        void** handle;
        s32 status;
        s16* state;

        compareIndex = 2;
        for (i = compareIndex; compareIndex < HSND_SLOT_COUNT; )
        {
            channel = &sChannels[compareIndex];
            if (channel->active != false)
            {
                handle = &channel->handle;
                status = func_0054d148(*handle);
                if (status == 3)
                {
                    channel->active = false;
                }
                else if (status == 4)
                {
                    func_00109070((s16)i);
                    H_Snd_00109180((s16)i);
                    func_0054d208(*handle, true);
                }
                else
                {
                    state = &channel->state;
                    switch (*state)
                    {
                        case HSND_CHANNEL_PLAYING:
                            func_0054d100(*handle);
                            *state = HSND_CHANNEL_STARTING;
                            break;

                        case HSND_CHANNEL_RELEASING:
                            H_Snd_00109180((s16)i);
                            *state = HSND_CHANNEL_STARTING;
                            break;
                    }
                }
            }
            {
                s16 next = (s16)(i + 1);
                i = next;
                compareIndex = (s16)i;
            }
        }
    }
}








/* Retail 0x1091A4-0x109994: reconstructed BGM and backend dispatch logic from retail instructions. */
