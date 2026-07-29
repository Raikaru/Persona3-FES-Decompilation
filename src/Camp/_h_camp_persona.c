#include "Camp/_h_camp_persona.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "libm.h"
#include "rw/rwplcore.h"
#include "Camp/h_camp.h"

void* FUN_00122940(KwlnTask*);
void FUN_00133d30();
void H_Cdvd_Destroy();
void FUN_004d0f00();
extern void (*jtbl_0096017C)(void* memory);
extern s32 FUN_00174800();
extern void FUN_00124e00(CampVec2 position, CampVec2 otherPosition,
                         f32 alpha, void* persona,
                         s32 mode, s32 frame, s32 fade);
extern void* FUN_00173220(u16 personaId);
extern u8 FUN_00173280(s32 personaId);
extern s32 FUN_00176600(void* persona);
extern s32 FUN_00177790();
extern s32 FUN_001120a0();
extern s32 FUN_001159f0(f32 x, f32 y, f32 alpha, ...);
#pragma alias campPersonaDrawSprite FUN_001159f0
extern void campPersonaDrawSprite(void* parent, void* resource, s32 frame,
                                  f32 x, f32 y, u8 alpha, f32 scale);
extern void (*DAT_00960090)(s32 state, s32 value);
extern f32 FUN_001126b0(void* particle);
extern f32 FUN_00112740(void* particle);
extern s32 FUN_00114450(f32 x, f32 y, f32 z, s32 a, s32 b, s32 c,
                        s32 d);
extern s32 FUN_0011bba0(s32 a, s32 b, f32 z, s32 c, s32 d);
extern s32 FUN_001158b0();
extern s32 FUN_001127d0();
extern s32 FUN_00115980();
extern void FUN_003b32d0();
#pragma alias campPersonaDrawTextCall FUN_003b32d0
extern s32 campPersonaDrawTextCall(f32 scale, s32 x, s32 y, s32 color,
                                   s32 font, s32 alignment, const char* text,
                                   s32 maxWidth, s32 shadow);
extern void FUN_00523ac8();
extern KwlnTask* DAT_007cdf60;
extern s32 DAT_007cdf68;
extern void* DAT_00833B78;
extern void* DAT_00833B88;
extern void* DAT_00833B90;
extern void* DAT_00833B74;
extern void* DAT_00833BA0;
#pragma alias DAT_00833B78_abs DAT_00833B78
extern u8 DAT_00833B78_abs[];
#pragma alias DAT_00833B88_abs DAT_00833B88
extern u8 DAT_00833B88_abs[];
#pragma alias DAT_00833B90_abs DAT_00833B90
extern u8 DAT_00833B90_abs[];
#pragma alias DAT_00833B74_abs DAT_00833B74
extern u8 DAT_00833B74_abs[];
#pragma alias DAT_00833BA0_abs DAT_00833BA0
extern u8 DAT_00833BA0_abs[];
extern char gp0xffff897c[];
extern void* h_campUpdatePanelTransition(KwlnTask* task);


typedef struct CampPersonaKaniWork
{
    s32 state;
    s32 reserved04;
    s32 timer;
    s32 command;
    void* persona;
    s32 visible;
    s16 personaId;
    s16 screen;
} CampPersonaKaniWork;

// FUN_00122fd0. Destroy callback of the "h_camp_persona_kani_control" task
void h_campPersonaDestroyKaniControlTask(KwlnTask* task)
{
    RwFree(task->workData);
}

// FUN_00123000
KwlnTask* h_campPersonaCreateKaniControlTask(KwlnTask* parent, u32 param_2)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x1c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "h_camp_persona_kani_control", 0x18c1, FUN_00122940, h_campPersonaDestroyKaniControlTask, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = 0;
    workData[4] = param_2;
    *(u16*)((int)workData + 0x18) = 1;
    return task;
}

// FUN_00133900. Destroy callback of the "CampPersonaDispCtlDraw" task
void h_campPersonaDestroyDispCtlDrawTask(KwlnTask* task)
{
    int* workData;

    workData = (int*)task->workData;
    if (workData[8] != 0) {
        FUN_00133d30(workData[8], workData[9]);
        workData[8] = 0;
        workData[9] = 0;
        workData[0xa] = 0;
    } else {
        if (workData[9] != 0) {
            H_Cdvd_Destroy(workData[9]);
            workData[9] = 0;
        }
        if (workData[0xa] != 0) {
            FUN_004d0f00(workData[0xa]);
            workData[0xa] = 0;
        }
    }
    RwFree(workData);
}

// FUN_00122630
void FUN_00122630(KwlnTask* task)
{
    RwFree(task->workData);
}

// FUN_00122660
KwlnTask* FUN_00122660(KwlnTask* parent)
{
    CampPanelTransitionWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(*work), 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampPanelTransition", 0x18C1,
                          h_campUpdatePanelTransition, FUN_00122630, work);
    if (task == NULL) {
        return NULL;
    }
    work->unused_0c = 0;
    work->drawId = 1;
    return task;
}

// FUN_00122710
u32 FUN_00122710(KwlnTask* task, u32 command)
{
    CampPanelTransitionWork* work;

    work = task->workData;
    switch (command) {
    case 0:
        work->state = 5;
        break;
    case 1:
        switch (work->unused_0c) {
        case 0:
            work->state = 1;
            break;
        case 1:
        case 10:
        case 14:
            break;
        case 2:
            work->state = 3;
            break;
        case 3:
            work->state = 13;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
        case 13:
        case 15:
        case 16:
            work->state = 3;
            break;
        }
        break;
    case 2:
        switch (work->unused_0c) {
        case 0:
        case 2:
        case 10:
        case 11:
        case 12:
            break;
        case 1:
            work->state = 5;
            break;
        case 3:
            work->state = 11;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 13:
            work->state = 3;
            break;
        }
        break;
    case 3:
        switch (work->unused_0c) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 10:
        case 11:
        case 12:
            break;
        case 2:
            work->state = 9;
            break;
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 13:
            work->state = 3;
            break;
        }
        break;
    case 4:
    case 5:
    case 6:
        switch (work->unused_0c) {
        case 0:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            break;
        case 1:
            work->state = 5;
            break;
        case 2:
            work->state = 5;
            break;
        case 3:
            work->state = 5;
            break;
        }
        break;
    case 7:
    case 8:
    case 9:
    case 15:
    case 16:
        switch (work->unused_0c) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        case 1:
            work->state = 5;
            break;
        }
        break;
    case 10:
    case 11:
    case 12:
    case 14:
        break;
    case 13:
        switch (work->unused_0c) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        case 1:
            work->state = 7;
            break;
        }
        break;
    }
    work->unused_0c = command;
    return 1;
}

// FUN_00122940 NONMATCHING
void* FUN_00122940(KwlnTask* task)
{
    s32 alpha;
    f32 displacement;
    CampVec2 position;
    CampVec2 otherPosition;
    CampPersonaKaniWork* work;

    work = task->workData;
    work->persona = (void*)FUN_00174800(work->personaId);
    switch (work->state) {
    case 0:
        if (work->visible != 0) {
            switch (work->screen) {
            case 0:
                position.x = 12.0f;
                position.y = 96.0f;
                otherPosition = position;
                FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, 0);
                break;
            case 1:
                position.x = 30.0f;
                position.y = 219.0f;
                otherPosition = position;
                FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, 0);
                break;
            }
        }
        break;
    case 1:
        work->state = 2;
        work->timer = 0;
        break;
    case 2:
        if (++work->timer == 30) {
            work->screen = 0;
            work->state = 0;
        }
        position.x = 30.0f;
        position.y = 219.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 0, work->timer, 0);
        work->visible = 1;
        break;
    case 3:
        work->state = 4;
        work->timer = 0;
        break;
    case 4:
        if (++work->timer == 20) {
            work->visible = 1;
            work->state = 0;
            work->screen = 0;
        }
        alpha = 0xFF - work->timer * 0xFF / 20;
        position.x = 30.0f;
        position.y = 219.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, alpha);
        break;
    case 5:
        if (work->visible == 0) {
            work->state = 0;
        } else {
            work->timer = 0;
            position.x = 30.0f;
            position.y = 219.0f;
            otherPosition = position;
            FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, 0);
            work->state = 6;
        }
        break;
    case 6:
        if (++work->timer == 20) {
            work->visible = 0;
            work->state = 0;
            work->screen = 0;
        }
        position.x = 30.0f;
        position.y = 219.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0,
                      work->timer * 0xFF / 20);
        break;
    case 7:
        if (work->visible == 0) {
            work->state = 0;
        } else {
            work->timer = 0;
            position.x = 30.0f;
            position.y = 219.0f;
            otherPosition = position;
            FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, 0);
            work->state = 8;
        }
        break;
    case 8:
        if (++work->timer == 8) {
            work->visible = 0;
            work->state = 0;
            work->screen = 0;
        }
        displacement = 30.0f;
        alpha = 0;
        if (work->timer > 2) {
            displacement += (work->timer - 2) * 80.0f;
            alpha = (work->timer - 2) * 0xFF / 5;
        }
        position.x = displacement;
        position.y = 219.0f;
        otherPosition.x = 30.0f;
        otherPosition.y = 219.0f;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, alpha);
        break;
    case 9:
        work->state = 10;
        work->timer = 0;
        /* fall through */
    case 10:
        if (++work->timer == 10) {
            work->visible = 1;
            work->state = 0;
            work->screen = 1;
        }
        displacement = 12.0f + (10 - work->timer) * 40.0f;
        position.x = displacement;
        position.y = 96.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0,
                      0xFF - work->timer * 0xFF / 10);
        break;
    case 11:
        work->state = 12;
        work->timer = 0;
        /* fall through */
    case 12:
        if (++work->timer == 10) {
            work->visible = 0;
            work->state = 0;
            work->screen = 1;
        }
        displacement = 12.0f + work->timer * 80.0f;
        position.x = displacement;
        position.y = 96.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0,
                      work->timer * 0xFF / 10);
        break;
    case 13:
        work->state = 14;
        work->timer = 0;
        /* fall through */
    case 14:
        if (++work->timer == 20) {
            work->visible = 1;
            work->state = 0;
            work->screen = 0;
        }
        alpha = work->timer * 0xFF / 20;
        position.x = 12.0f;
        position.y = 96.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0, alpha);
        position.x = 30.0f;
        position.y = 219.0f;
        otherPosition = position;
        FUN_00124e00(position, otherPosition, 100.0f, work->persona, 1, 0,
                     0xFF - alpha);
        break;
    }
    return KWLNTASK_CONTINUE;
}
typedef struct CampPersonaTransitionWork
{
    s32 state;
    s16 mode;
    s16 timer;
} CampPersonaTransitionWork;

typedef struct CampPersonaParticle
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    s8 alpha;
    u8 reserved19[0xf];
    u16 scaleX;
    u16 scaleY;
    f32 drawAlpha;
} CampPersonaParticle;

static s32 campPersonaClampFade(s32 fade)
{
    if (fade < 0) {
        return 0;
    }
    if (fade > 0xff) {
        return 0xff;
    }
    return fade;
}

static void campPersonaDrawDigit(f32 alpha, f32 x, f32 y, s32 digit)
{
    FUN_001120a0(2);
    FUN_001159f0(x, y, alpha, digit);
}

static void campPersonaDrawLevel(f32 alpha, f32 x, f32 y, void* persona, s32 fade)
{
    u8 level;
    s32 bright;

    if (persona == NULL) {
        return;
    }
    level = *((u8*)persona + 4);
    bright = campPersonaClampFade(fade);
    if (level < 10) {
        campPersonaDrawDigit(alpha, x + 75.0f, y + 127.0f, level);
    } else {
        campPersonaDrawDigit(alpha, x + 67.0f, y + 127.0f, level / 10);
        campPersonaDrawDigit(alpha, x + 82.0f, y + 127.0f, level % 10);
    }
}

static void campPersonaDrawName(f32 alpha, f32 x, f32 y, void* persona, s32 fade)
{
    char text[0x100];
    void* name;
    s32 bright;

    if (persona == NULL) {
        return;
    }
    name = FUN_00173220(*(u16*)((u8*)persona + 2));
    FUN_00523ac8(text, (void*)0x7cb66c, name);
    bright = campPersonaClampFade(fade);
    FUN_003b32d0(alpha, (s32)(x + 111.0f), (s32)(y + 122.0f),
                 bright | 0xffffff00, 10, 1, text, 0x10, 0x74);
}

static void campPersonaDrawEffectParticle(f32 alpha, f32 x, f32 y,
                                           s32 slot, s32 scale)
{
    CampPersonaParticle* particle;

    particle = (CampPersonaParticle*)FUN_001158b0(0, DAT_00833B90, slot);
    if (particle == NULL) {
        return;
    }
    *(void**)((u8*)particle + 0x2c) = DAT_00833B90;
    particle->x = x;
    particle->y = y;
    particle->alpha = (s8)campPersonaClampFade((s32)alpha);
    particle->scaleX = (u16)scale;
    particle->scaleY = (u16)scale;
    FUN_001127d0(particle, 0);
    FUN_00115980(particle);
}

// FUN_00124E00
void FUN_00124e00(CampVec2 position, CampVec2 otherPosition, f32 alpha,
                  void* persona, s32 mode, s32 frame, s32 fade)
{
    if (mode == 1) {
        goto drawStatus;
    }
    switch (mode) {
    case 0:
        FUN_00125740(position, alpha, persona, frame);
        break;
    default:
        goto done;
    }
    goto done;
drawStatus:
    FUN_00125b40(position, otherPosition, alpha, persona, fade);
done:;
}

// FUN_00124E60
void FUN_00124e60(CampVec2 position, f32 alpha, void* persona, s32 fade)
{
    u8 level;
    void* parent;

    level = *((u8*)persona + 4);
    if (level >= 10) {
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                 level / 10 + 0xb,
                                 position.x + 67.0f,
                                 position.y + 127.0f, fade, alpha);
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                 *((u8*)((int)persona + 4)) % 10 + 0xb,
                                 position.x + 82.0f,
                                 position.y + 127.0f, fade, alpha);
    } else {
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                 level % 10 + 0xb,
                                 position.x + 75.0f,
                                 position.y + 127.0f, fade, alpha);
    }
}

// FUN_00124FD0 NONMATCHING
void FUN_00124fd0(CampVec2 position, f32 alpha, void* persona, s32 fade)
{
    char text[0x100];
    CampPersonaParticle* particle;
    s32 bright;
    f32 x;
    f32 y;
    f32 scale;
    void* parent;
    void (*setRenderState)(s32 state, s32 value);

    bright = 0xff - fade;
    FUN_00523ac8(text, gp0xffff897c,
                 FUN_00173220(*(u16*)((u8*)persona + 2)));
    campPersonaDrawTextCall(alpha, (s32)(position.x + 111.0f),
                 (s32)(position.y + 122.0f),
                 (u32)(bright | 0xffffff00), 10, 1, text, 0x10, 0x74);
    if (FUN_00176600(persona) == 0) {
        return;
    }
    setRenderState = DAT_00960090;

    setRenderState(6, 1);
    setRenderState(7, 2);
    setRenderState(8, 1);
    setRenderState(9, 1);
    setRenderState(12, 1);
    setRenderState(11, 6);
    setRenderState(10, 5);
    setRenderState(2, 4);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717fb);

    x = position.x + 272.0f;
    y = position.y + 110.0f;
    campPersonaDrawSprite(parent, DAT_00833B90, 0x1a,
                          (u8)fade, x, y, alpha);

    setRenderState(6, 0);
    setRenderState(8, 1);
    if (fade == 0) {
        particle = (CampPersonaParticle*)FUN_001158b0(0, DAT_00833B90, 0x1b);
        particle->drawAlpha = alpha;
        particle->x = position.x + 276.0f;
        particle->y = position.y + 112.0f;
        particle->alpha = (s8)fade;
        FUN_001127d0(particle, 0);
        FUN_00115980(particle);

        setRenderState(6, 1);
        setRenderState(8, 0);

        DAT_007cdf68++;
        if (DAT_007cdf68 >= 20) {
            DAT_007cdf68 = 0;
        }
        RpSkyRenderStateSet(2, 0x48);
        RpSkyRenderStateSet(3, 0x71801);

        bright = DAT_007cdf68;
        particle = (CampPersonaParticle*)FUN_001158b0(0, DAT_00833B90, 0x1c);
        particle->drawAlpha = alpha;
        particle->x = position.x + 276.0f;
        particle->y = position.y + 112.0f;
        particle->alpha = 0;
        particle->reserved19[0] = (u8)((bright << 7) / 10 + 0x7f);
        particle->scaleX = 0x1000;
        particle->scaleY = 0x1000;
        FUN_001127d0(particle, 0);
        FUN_00115980(particle);

        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717fb);

        bright = DAT_007cdf68 >= 11 ? 20 - DAT_007cdf68 : DAT_007cdf68;
        scale = (f32)((10 - bright) * 0x518 / 10) + (f32)0xc18;
        particle = (CampPersonaParticle*)FUN_001158b0(0, DAT_00833B90, 0x1e);
        particle->drawAlpha = alpha;
        particle->alpha = 0;
        particle->reserved19[0] = (u8)(bright * 0x66 / 10 + 0x66);
        particle->scaleX = (u16)scale;
        particle->scaleY = (u16)scale;
        x = position.x + 276.0f;
        y = position.y + 112.0f;
        x = 19.0f + x - FUN_001126b0(particle) / 2.0f;
        y = 15.0f + y - FUN_00112740(particle) / 2.0f;
        particle->x = x;
        particle->y = y;
        FUN_001127d0(particle, 0);
        FUN_00115980(particle);

        bright = DAT_007cdf68 >= 11 ? 20 - DAT_007cdf68 : DAT_007cdf68;
        scale = (f32)(bright * 0x518 / 10) + (f32)0xc18;
        particle = (CampPersonaParticle*)FUN_001158b0(0, DAT_00833B90, 0x1d);
        particle->drawAlpha = alpha;
        particle->alpha = 0;
        particle->reserved19[0] =
            (u8)((10 - bright) * 0x66 / 10 + 0x66);
        particle->scaleX = (u16)scale;
        particle->scaleY = (u16)scale;
        x = position.x + 276.0f;
        y = position.y + 112.0f;
        x = 19.0f + x - FUN_001126b0(particle) / 2.0f;
        y = 15.0f + y - FUN_00112740(particle) / 2.0f;
        particle->x = x;
        particle->y = y;
        FUN_001127d0(particle, 0);
        FUN_00115980(particle);
    }
}
// FUN_00125740 NONMATCHING
void FUN_00125740(CampVec2 position, f32 alpha, void* persona,
                  s32 frame)
{
    s16 localFrame;
    s16 shortFrame;
    s32 bright;
    f32 slide;
    CampVec2 originalPosition;
    CampVec2 iconPosition;
    CampVec2 levelPosition;
    CampVec2 fadePosition;
    void* parent;
    shortFrame = (s16)frame;

    if (shortFrame < 15) {
        return;
    }
    localFrame = shortFrame - 15;
    bright = 0;
    slide = 0.0f;
    if (localFrame < 3) {
        bright = 0xff - (localFrame * 0xff) / 3;
        slide = (f32)(((3 - localFrame) * 0x14) / 3);
    }
    originalPosition = position;
    position.x -= slide;
    campPersonaDrawSprite(parent, DAT_00833B90, 1,
                          position.x + 22.0f,
                          position.y + 117.0f, (u8)bright, alpha);
    if (localFrame > 0) {
        if (localFrame < 5) {
            bright = 0xff - ((localFrame - 1) * 0xff) / 4;
            slide = (f32)(((5 - localFrame) * 0x3c) / 4);
            iconPosition = originalPosition;
            iconPosition.x -= slide;
        } else {
            bright = 0;
            iconPosition = originalPosition;
        }
        campPersonaDrawSprite(parent, DAT_00833B88,
                              FUN_00173280(*(u16*)((u8*)persona + 2)) - 1,
                              iconPosition.x + 105.0f, iconPosition.y + 142.0f,
                              (u8)bright, alpha);
    }
    if (localFrame > 4) {
        {
            u8 level;

            levelPosition = originalPosition;
            level = *((u8*)persona + 4);
            if (level >= 10) {
                campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                      level / 10 + 0xb,
                                      levelPosition.x + 67.0f,
                                      levelPosition.y + 127.0f, bright, alpha);
                campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                      level % 10 + 0xb,
                                      levelPosition.x + 82.0f,
                                      levelPosition.y + 127.0f, bright, alpha);
            } else {
                campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                                      level % 10 + 0xb,
                                      levelPosition.x + 75.0f,
                                      levelPosition.y + 127.0f, bright, alpha);
            }
        }
    }
    if (localFrame > 5) {
        if (localFrame < 9) {
            bright = 0xff - ((localFrame - 6) * 0xff) / 3;
        } else {
            bright = 0;
        }
        fadePosition = originalPosition;
        FUN_00124fd0(fadePosition, alpha, persona, bright);
    }
}

// FUN_00125B40 NONMATCHING
void FUN_00125b40(CampVec2 position, CampVec2 unused, f32 alpha,
                  void* persona, s32 fade)
{
    void* parent;
    f32 drawAlpha;
    void* resource;
    s32 personaId;
    u8 level;
    CampVec2 originalPosition;
    CampVec2 iconPosition;
    CampVec2 levelPosition;
    CampVec2 drawPosition;

    originalPosition = position;
    drawPosition = position;
    drawAlpha = alpha;
    campPersonaDrawSprite(parent, *(void**)DAT_00833B90_abs, 1,
                          drawPosition.x + 22.0f, drawPosition.y + 117.0f,
                          fade, drawAlpha);
    iconPosition = originalPosition;
    resource = *(void**)DAT_00833B88_abs;
    personaId = FUN_00173280(*(u16*)((u8*)persona + 2)) - 1;
    campPersonaDrawSprite(parent, resource, personaId,
                          iconPosition.x + 105.0f, iconPosition.y + 142.0f,
                          fade, alpha);
    levelPosition = originalPosition;
    level = *((u8*)persona + 4);
    if (level >= 10) {
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                              level / 10 + 0xb,
                              levelPosition.x + 67.0f,
                              levelPosition.y + 127.0f, fade, alpha);
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                              level % 10 + 0xb,
                              levelPosition.x + 82.0f,
                              levelPosition.y + 127.0f, fade, alpha);
    }
    else {
        campPersonaDrawSprite(parent, (void*)FUN_001120a0(2),
                              level % 10 + 0xb,
                              levelPosition.x + 75.0f,
                              levelPosition.y + 127.0f, fade, alpha);
    }
    FUN_00124fd0(originalPosition, alpha, persona, fade);
}

static s32 campPersonaTransitionIsReady(void)
{
    if (DAT_007cdf60 == NULL || DAT_007cdf60->workData == NULL) {
        return 0;
    }
    return *((s32*)DAT_007cdf60->workData) == 3;
}

// FUN_00125D70 NONMATCHING
void* FUN_00125d70(KwlnTask* task)
{
    void* parent;
    CampPersonaTransitionWork* work;
    s32 fade;
    f32 x;
    f32 y;
    CampPersonaParticle* particle;

    work = task->workData;
    if (work->state == 1) {
        goto process;
    }
    if (work->state != 0) {
        return KWLNTASK_CONTINUE;
    }
    work->timer = 0;
    work->state = 1;
process:

    if (work->mode == 0) {
        if (work->timer < 5) {
            if (DAT_007cdf60 != NULL &&
                DAT_007cdf60->workData != NULL &&
                *((s32*)DAT_007cdf60->workData) == 3) {
                FUN_00114450(102.0f, 0.0f, -87.0f, -1,
                             0x4fa4ff19, 0x280, 0x280);
            }
            FUN_0011bba0(0, 0, 102.0f, 0, 0);
            particle = (CampPersonaParticle*)FUN_001158b0(
                0, *(void**)DAT_00833B78_abs, 0);
            particle->drawAlpha = 101.0f;
            particle->x = 428.0f;
            particle->y = 27.0f;
            particle->alpha = 0;
            particle->scaleX = 0;
            particle->scaleY = 0;
            FUN_001127d0(particle, 1);
            FUN_00115980(particle);
        }
        if (work->timer > 4 && work->timer < 20) {
            fade = ((work->timer - 5) * 800) / 15;
            if (DAT_007cdf60 != NULL &&
                DAT_007cdf60->workData != NULL &&
                *((s32*)DAT_007cdf60->workData) == 3) {
                FUN_00114450(102.0f, (f32)-fade, (f32)fade - 87.0f,
                             -1, 0x4fa4ff19, 0x280, 0x280);
            }
            FUN_0011bba0(0, 0, 102.0f, (u16)fade, 0);
        }
        if (work->timer > 14) {
            fade = campPersonaClampFade((20 - work->timer) * 0xff / 5);
            x = 428.0f + (f32)(((work->timer - 15) * 21) / 10);
            y = 27.0f + (f32)(((work->timer - 15) * 2) / 10);
            particle = (CampPersonaParticle*)FUN_001158b0(
                0, *(void**)DAT_00833B78_abs, 0);
            if (particle != NULL) {
                particle->drawAlpha = 101.0f;
                particle->x = x;
                particle->y = y;
                particle->alpha = (s8)fade;
                particle->scaleX = 0xe28;
                particle->scaleY = 0xe28;
                FUN_001127d0(particle, 1);
                FUN_00115980(particle);
            }
            campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 0,
                                  34.0f, 415.0f, (u8)fade, 100.0f);
            campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 9,
                                  50.0f, 415.0f, (u8)fade, 100.0f);
            campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 11,
                                  194.0f, 415.0f, (u8)fade, 100.0f);
            campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 1,
                                  561.0f, 415.0f, (u8)fade, 100.0f);
            campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 4,
                                  382.0f, 415.0f, (u8)fade, 100.0f);
        }
        if (work->timer < 20) {
            work->timer++;
        } else {
            work->state = 2;
        }
    } else if (work->mode == 1) {
        fade = work->timer == 8 ? 0 : 0xff - (work->timer * 0xff) / 8;
        particle = (CampPersonaParticle*)FUN_001158b0(
            0, *(void**)DAT_00833B78_abs, 0);
        if (particle != NULL) {
            particle->drawAlpha = 101.0f;
            particle->x = 449.0f;
            particle->y = 29.0f;
            particle->alpha = (s8)fade;
            particle->scaleX = 0xe28;
            particle->scaleY = 0xe28;
            FUN_001127d0(particle, 1);
            FUN_00115980(particle);
        }
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 0,
                              34.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 9,
                              50.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 11,
                              194.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 1,
                              561.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 4,
                              382.0f, 415.0f, (u8)fade, 100.0f);
        if (work->timer < 8) {
            work->timer++;
        } else {
            work->state = 2;
        }
    } else if (work->mode == 2 && work->timer != 8) {
        fade = (work->timer * 0xff) / 8;
        particle = (CampPersonaParticle*)FUN_001158b0(
            0, *(void**)DAT_00833B78_abs, 0);
        if (particle != NULL) {
            particle->drawAlpha = 101.0f;
            particle->x = 449.0f;
            particle->y = 29.0f;
            particle->alpha = (s8)fade;
            particle->scaleX = 0xe28;
            particle->scaleY = 0xe28;
            FUN_001127d0(particle, 1);
            FUN_00115980(particle);
        }
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 0,
                              34.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 9,
                              50.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833B74_abs, 11,
                              194.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 1,
                              561.0f, 415.0f, (u8)fade, 100.0f);
        campPersonaDrawSprite(parent, *(void**)DAT_00833BA0_abs, 4,
                              382.0f, 415.0f, (u8)fade, 100.0f);
        work->timer++;
    }
    return KWLNTASK_CONTINUE;
}
