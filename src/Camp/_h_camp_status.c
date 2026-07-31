#include "Camp/_h_camp_status.h"
#include "Camp/h_camp.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "libm.h"
#include "rw/rwplcore.h"

void* h_campStatusUpdatePcStatusRootTask(KwlnTask*);
void* FUN_001311d0(KwlnTask*);
void FUN_001124b0();
extern void (*jtbl_0096017C)(void* memory);
extern void (*jtbl_007B5AF0[6])();
extern void* (*DAT_00960184)(u32 elementCount, u32 elementSize,
                             u32 heapFlags);
extern s32 FUN_001159f0();
#pragma alias campStatusDrawSpriteCall FUN_001159f0
extern s32 campStatusDrawSpriteCall(u32 parent, void* resource, s32 frame,
                                    u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campStatusDrawSpriteCallXY FUN_001159f0
extern s32 campStatusDrawSpriteCallXY(u32 parent, void* resource, s32 frame,
                                      f32 x, f32 y, u32 alpha, f32 scale);
#pragma alias campStatusDrawFadeSprite FUN_001159f0
extern s32 campStatusDrawFadeSprite(f32 x, f32 y, f32 alpha, void* resource,
                                    s32 frame, s32 fade);
#pragma alias campStatusDrawSpritePackedCall FUN_001159f0
extern s32 campStatusDrawSpritePackedCall(f32 x, f32 y, u32 parent,
                                          void* resource, s32 frame,
                                          u8 alpha, f32 scale);
#pragma alias campStatusDrawSprite3Call FUN_001159f0
extern void campStatusDrawSprite3Call(f32 x, f32 y, u32 parent);
#pragma alias campStatusDrawSprite4Call FUN_001159f0
extern void campStatusDrawSprite4Call(f32 x, f32 y, f32 alpha, s32 digit);
#pragma alias campStatusDrawSpriteFadeCall FUN_00115ad0
extern void campStatusDrawSpriteFadeCall(u32 parent, void* resource, s32 frame,
                                         u32 alpha, f32 x, f32 y, f32 scale,
                                         u32 fade);
/* Fade XY order: h_campStatusDrawSp nd637/1020B -> nd591/1024B. */
#pragma alias campStatusDrawSpriteFadeXYCall FUN_00115ad0
extern void campStatusDrawSpriteFadeXYCall(u32 parent, void* resource,
                                           s32 frame, f32 x, f32 y,
                                           u32 alpha, f32 scale, u32 fade);
#pragma alias campStatusDrawGaugeCall FUN_00113a30
extern void campStatusDrawGaugeCall(f32 scale, f32 x, f32 y, u32 color,
                                    s32 width, s32 height);
#pragma alias campStatusDrawTextCall FUN_003b32d0
extern void campStatusDrawTextCall(f32 scale, s32 x, s32 y, s32 color,
                                   s32 font, s32 alignment, const char* text,
                                   s32 maxWidth, s32 shadow);
#pragma alias campStatusDrawFooterText FUN_0040eb50
extern s32 campStatusDrawFooterText(f32 scale, s32 x, s32 y, u8 color,
                                    s16 font, const char* text, s32 maxWidth);

extern s32 FUN_001120a0();
#pragma alias campStatusGetFont FUN_001120a0
extern void* campStatusGetFont(s32 font);
extern s32 FUN_00113a30();
extern s32 FUN_00114450();
extern s32 FUN_0011bba0();
extern s32 FUN_0011e380();
extern s32 FUN_0011d3a0();
extern s32 FUN_0010a4e0();
extern s32 FUN_0010c1a0();
extern s32 FUN_0010c3a0();
extern s32 FUN_00174800();
extern s32 FUN_0016c860();
extern s32 FUN_0016d2f0();
extern s32 FUN_00177280();
extern s32 FUN_001772f0();
extern s32 FUN_00177360();
extern s32 FUN_00173220();
extern s32 FUN_00173280();
extern s32 FUN_001733b0();
extern s32 FUN_00173340();
extern s32 FUN_00173330();
extern s32 FUN_00173580();
extern s32 FUN_00173660();
extern s32 FUN_00198590();
extern s32 FUN_00195290();
extern s32 FUN_00194b20();
extern s32 FUN_001158b0();
extern s32 FUN_001127d0();
extern s32 FUN_00115980();
extern s32 FUN_001126b0();
extern s32 FUN_00112740();
extern s32 FUN_00128140();
extern s32 FUN_001281e0();
extern s32 FUN_00128480();
extern s32 FUN_00128720();
extern s32 FUN_00128c40();
extern s32 FUN_00129160();
extern s32 FUN_001293b0();
extern s32 FUN_00129b30();
extern s32 FUN_0012a560();
extern s32 FUN_0012ac60();
extern s32 FUN_001339a0();
#pragma alias campStatusCreatePersonaChild FUN_001339a0
extern KwlnTask* campStatusCreatePersonaChild(KwlnTask* parent,
                                              u32 priority, u32 personaId,
                                              u32 mode, f32 alpha);
extern s32 FUN_00133a80();
extern void FUN_00133b80(KwlnTask* task, u32 personaId, u32 mode);
extern s32 FUN_00121de0();
extern s32 FUN_00122710();
extern s32 FUN_00127af0(KwlnTask* task);
extern KwlnTask* FUN_00127b00(KwlnTask* task, s32 resource, f32 unused,
                              CampVec2 packed, s32 mode, s32 selected);
extern s32 FUN_00127ad0(KwlnTask* task);
extern s32 FUN_00128030(KwlnTask* task);
extern KwlnTask* FUN_00128040(KwlnTask* task, s32 resource, f32 unused,
                              CampVec2 packed, s32 mode, s32 selected);
extern void FUN_00127ab0(KwlnTask* task);
extern void FUN_00127ff0(KwlnTask* task);
extern void FUN_00128010(KwlnTask* task);
extern void FUN_003b32d0();
extern void FUN_00523ac8();
extern void* DAT_00833B90;
extern void* DAT_00833B94;
extern void* DAT_00833B98;
#pragma alias DAT_00833B90_abs DAT_00833B90
extern u8 DAT_00833B90_abs[];
#pragma alias DAT_00833B98_abs DAT_00833B98
extern u8 DAT_00833B98_abs[];
#pragma alias DAT_00833B88_abs DAT_00833B88
extern u8 DAT_00833B88_abs[];
extern void* DAT_00833B74;
extern void* DAT_00833BA0;
extern char gp0xffff897c[];
extern f32 DAT_007caf38;
extern void* DAT_00833B88;
extern void* FUN_00177790(s16 pcId);
extern void* func_00112420(void* source);
extern u32 FUN_001344B0();
extern u32 FUN_00134900();
extern void FUN_00124e60(CampVec2 position, f32 alpha, void* persona,
                         s32 fade);
extern void FUN_00124fd0(CampVec2 position, f32 alpha, void* persona,
                         s32 fade);
extern const char D_005DB140[];
extern const char D_005DB050[];
extern const char D_005DB080[];
extern const char D_005DB0A0[];
extern const char D_005DB030[];
extern void* FUN_00125d70(KwlnTask* task);
void h_campStatusDrawPanelFrame(u32 parent, CampVec2 position, s32 alpha);
extern const char D_005DB158[];
extern const char D_005DACB0[];
extern const char D_005DB170[];
extern void* func_0010c1a0();
extern void* func_0010c3a0();
extern int printf(const char* format, ...);
extern void FUN_00174c10();
extern void FUN_00175200();
extern u32 FUN_003c7430();
extern u32 FUN_003c74e0();
extern u32 FUN_003c7560();
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();

typedef struct CampStatusWork
{
    s32 state;
    s32 selectedScreen;
    s32 timer;
    s32 command;
    s32 alpha;
    KwlnTask* child;
    s32 transitionTimer;
    s32 inputResult;
    s32 unused20;
    KwlnTask* partsTask;
    void* resource;
    s32 scrollY;
    s32 appearance;
    s32 reserved34;
    s16 openingTimer;
    s16 mode;
    s16 closeTimer;
    s16 detailTimer;
} CampStatusWork;

extern KwlnTask* DAT_007cdf50;
extern KwlnTask* DAT_007cdf54;
extern KwlnTask* DAT_007cdf58;
extern KwlnTask* DAT_007cdf5c;
extern KwlnTask* DAT_007cdf60;
extern s32 DAT_007cdf64;
extern s32 DAT_007cdf68;
extern u16 DAT_007e094e;
extern u16 DAT_007e0958;
extern u16 DAT_007e0952;
extern u16 DAT_007e095a;

extern void FUN_0012b300(CampVec2 position, f32 scale, void* persona,
                         u8 alpha);
extern void FUN_0012b300_s32(CampVec2 position, f32 scale, void* persona,
                             s32 alpha);
#pragma alias FUN_0012b300_s32 FUN_0012b300
extern void FUN_0012b860_s32(CampVec2 position, f32 scale, void* currentStats,
                             void* persona, s32 alpha);
#pragma alias FUN_0012b860_s32 FUN_0012b860
extern void FUN_0012bce0_s32(CampVec2 position, f32 scale, void* unused,
                             void* persona, s32 alpha);
#pragma alias FUN_0012bce0_s32 FUN_0012bce0
extern void FUN_0012bfb0_s32(CampVec2 position, f32 scale, void* currentStats,
                             void* persona, s32 alpha);
#pragma alias FUN_0012bfb0_s32 FUN_0012bfb0

void h_campStatusRenderStatIcon(CampVec2 position, f32 scale,
                                s32 stat, s32 alpha);
void h_campStatusDrawStatLabels(CampVec2 position, f32 scale,
                                void* persona, s32 alpha);
void h_campStatusDrawStatValues(CampVec2 position, f32 scale,
                                void* bonus, void* persona, s32 alpha);
void h_campStatusDrawSkillValues(CampVec2 position, f32 scale,
                                 void* bonus, void* persona, s32 alpha);
void h_campStatusDrawRankValue(CampVec2 position, f32 scale, s32 row,
                               s32 value, s32 extra, s32 alpha);
void h_campStatusDrawEquipment(CampVec2 position, f32 scale,
                               void* bonus, void* persona, s32 alpha);
typedef struct CampStatusParticle
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    s8 alpha;
} CampStatusParticle;

static s32 sCampStatusScrollX;

static inline s32 campStatusClampFade(s32 fade)
{
    if (fade < 0) {
        return 0;
    }
    if (fade > 0xff) {
        return 0xff;
    }
    return fade;
}

static inline void campStatusDrawDigit(f32 alpha, f32 x, f32 y, s32 digit)
{
    FUN_001120a0(2);
    campStatusDrawSprite4Call(x, y, alpha, digit);
}

static void campStatusDrawNumber(f32 alpha, f32 x, f32 y, u32 value)
{
    if (value >= 100) {
        campStatusDrawDigit(alpha, x, y, value / 100);
        value %= 100;
    }
    if (value >= 10) {
        campStatusDrawDigit(alpha, x + 15.0f, y, value / 10);
        value %= 10;
    }
    campStatusDrawDigit(alpha, x + 30.0f, y, value);
}

static inline void campStatusDrawParticle(f32 texture, f32 x, f32 y, s8 alpha,
                                   s32 slot)
{
    CampStatusParticle* particle;

    particle = (CampStatusParticle*)FUN_001158b0(0, DAT_00833B90, slot);
    *(f32*)((u8*)particle + 0x2c) = texture;
    particle->x = x;
    particle->y = y;
    particle->alpha = alpha;
    FUN_001127d0(particle, 1);
    FUN_00115980(particle);
}
// FUN_001230C0 NONMATCHING
void* h_campStatusUpdatePcStatusRootTask(KwlnTask* task)
{
    CampStatusWork* work;
    s32 result;
    CampVec2 packed;

    work = task->workData;
    switch (work->state) {
    case 0:
        packed.x = 0.0f;
        packed.y = 0.0f;
        sCampStatusScrollX = 0x140;
        work->selectedScreen = 0;
        work->child = FUN_00127b00(task, 0x18be, 0.0f, packed, 1, 0);
        work->timer = 0x1e;
        work->alpha = 0;
        work->state = 1;
        break;
    case 1:
        if (work->alpha != 0) {
            work->alpha -= 5;
            if (work->alpha < 0) {
                work->alpha = 0;
            }
        }
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha, (f32)sCampStatusScrollX,
                                 0.0f, 104.0f);
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha,
                                 (f32)(sCampStatusScrollX + 0x280),
                                 0.0f, 104.0f);
        sCampStatusScrollX--;
        if (sCampStatusScrollX < -400) {
            sCampStatusScrollX += 0x280;
        }
        result = work->selectedScreen == 0
               ? FUN_00127af0(work->child)
               : FUN_00128030(work->child);
        if (result == -1) {
            if (work->selectedScreen == 1) {
                FUN_00127ff0(work->child);
            } else {
                FUN_00127ab0(work->child);
            }
            work->state = 4;
        } else if (result == 1) {
            work->inputResult = 0;
            work->state = 2;
        }
        break;
    case 2:
        if (work->alpha != 0) {
            work->alpha -= 5;
            if (work->alpha < 0) {
                work->alpha = 0;
            }
        }
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha, (f32)sCampStatusScrollX,
                                 0.0f, 104.0f);
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha,
                                 (f32)(sCampStatusScrollX + 0x280),
                                 0.0f, 104.0f);
        sCampStatusScrollX--;
        if (sCampStatusScrollX < -400) {
            sCampStatusScrollX += 0x280;
        }
        if (work->selectedScreen == 1) {
            FUN_00128010(work->child);
            packed.x = 0.0f;
            packed.y = 0.0f;
            work->selectedScreen = 0;
            work->child = FUN_00127b00(task, 0x18be, 0.0f, packed, 1, 1);
        } else {
            FUN_00127ad0(work->child);
            packed.x = 0.0f;
            packed.y = 0.0f;
            work->selectedScreen = 1;
            work->child = FUN_00128040(task, 0x18be, 0.0f, packed, 1, 0);
        }
        work->state = 1;
        break;
    case 4:
        if (work->alpha != 0xff) {
            work->alpha += 5;
            if (work->alpha > 0xff) {
                work->alpha = 0xff;
            }
        }
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha, (f32)sCampStatusScrollX,
                                 0.0f, 104.0f);
        campStatusDrawSpriteCall((u32)task, *(void**)DAT_00833B98_abs, 0x1e,
                                 (u8)work->alpha,
                                 (f32)(sCampStatusScrollX + 0x280),
                                 0.0f, 104.0f);
        sCampStatusScrollX--;
        if (sCampStatusScrollX < -400) {
            sCampStatusScrollX += 0x280;
        }
        if (FUN_00195290(work->child) == 3) {
            return KWLNTASK_STOP;
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}

void h_campStatusDrawStatus(CampVec2 position, CampVec2 unused,
                             f32 alpha, s16 pcId, s32 fade);
void h_campStatusDrawStatusTransition(CampVec2 position, f32 alpha,
                                       s16 pcId, s32 phase);
void h_campStatusDrawSp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade);
// FUN_00123640
void h_campStatusDrawScreen(CampVec2 position, CampVec2 otherPosition,
                            f32 alpha, s16 pcId, s32 mode,
                            s32 phase, s32 fade)
{
    if (mode == 1) {
        goto drawStatus;
    }
    switch (mode) {
    case 0:
        h_campStatusDrawStatusTransition(position, alpha, pcId, phase);
        break;
    default:
        goto done;
    }
    goto done;
drawStatus:
    h_campStatusDrawStatus(position, otherPosition, alpha, pcId, fade);
done:;
}

// FUN_001236A0 NONMATCHING
void h_campStatusDrawHp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade)
{
    char text[0x100];
    s32 bright;
    s32 val;
    s32 drewHundreds;
    f32 dx;
    f32 dy;
    u32 parent;
    void* font;

    FUN_00523ac8(text, gp0xffff897c, FUN_00177790(pcId));
    bright = 0xff - fade;
    campStatusDrawTextCall(alpha - 1.0f, (s32)(position.x + 125.0f),
                           (s32)(position.y + 36.0f),
                           bright | 0xffffff00, 10, 1, text, 0x10, 0x78);
    if (barOffset != 0) {
        campStatusDrawGaugeCall(alpha - 1.0f, position.y + 196.0f +
                                (f32)(0x4c - barOffset),
                                position.x + 59.0f, 0xffffff00, barOffset, 10);
    }
    dy = (70.0f + position.y) - 12.0f;
    /* Separator */
    campStatusDrawSpriteCall(parent, DAT_00833B90, 4, (u32)(u8)fade,
                             position.x + 85.0f, dy, alpha);
    /* Draw current HP digits */
    val = datGetHp(pcId);
    dx = position.x + 79.0f;
    drewHundreds = 0;
    if (val >= 100) {
        drewHundreds = 1;
        font = campStatusGetFont(2);
        campStatusDrawSpriteCall(parent, font, val / 100 + 0xb,
                                 (u32)(u8)fade, dx, dy, alpha);
        val %= 100;
        dx += 15.0f;
    }
    if (val >= 10 || drewHundreds != 0) {
        font = campStatusGetFont(2);
        campStatusDrawSpriteCall(parent, font, val / 10 + 0xb,
                                 (u32)(u8)fade, dx, dy, alpha);
        val %= 10;
        dx += 15.0f;
    }
    font = campStatusGetFont(2);
    campStatusDrawSpriteCall(parent, font, val + 0xb,
                             (u32)(u8)fade, dx, dy, alpha);
    /* Draw max HP digits */
    val = datGetMaxHp(pcId);
    dx = position.x + 138.0f;
    drewHundreds = 0;
    if (val >= 100) {
        drewHundreds = 1;
        font = campStatusGetFont(2);
        campStatusDrawSpriteFadeCall(parent, font, val / 100 + 0xb,
                                     (u32)(u8)fade, dx, dy, alpha, 0x66);
        val %= 100;
        dx += 15.0f;
    }
    if (val >= 10 || drewHundreds != 0) {
        font = campStatusGetFont(2);
        campStatusDrawSpriteFadeCall(parent, font, val / 10 + 0xb,
                                     (u32)(u8)fade, dx, dy, alpha, 0x66);
        val %= 10;
        dx += 15.0f;
    }
    font = campStatusGetFont(2);
    campStatusDrawSpriteFadeCall(parent, font, val + 0xb,
                                 (u32)(u8)fade, dx, dy, alpha, 0x66);
}

// FUN_00123B70 NONMATCHING
void h_campStatusDrawSp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade)
{
    s32 val;
    s32 hundreds;
    u32 parent;
    void* font;
    f32 y;
    f32 x;
    s32 fade8;

    if (barOffset != 0) {
        campStatusDrawGaugeCall(alpha - 1.0f,
                                position.x + 196.0f +
                                    (f32)(0x4c - barOffset),
                                (87.0f + position.y) - 12.0f,
                                0xffffff00, barOffset, 10);
    }
    y = position.y;
    x = position.x + 195.0f;
    fade8 = (u8)fade;
    /* Separator */
    campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B90_abs, 5,
                               x, (87.0f + y) - 12.0f, fade8, alpha);
    /* Draw current SP digits */
    val = datGetSp((s32)(s16)pcId);
    hundreds = 0;
    if (val >= 100) {
        hundreds = 1;
        font = campStatusGetFont(2);
        campStatusDrawSpriteCallXY(parent, font, val / 100 + 0xb,
                                   position.x + 79.0f,
                                   (85.0f + y) - 12.0f, (u8)fade, alpha);
        val %= 100;
    }
    if (val >= 10 || hundreds != 0) {
        font = campStatusGetFont(2);
        campStatusDrawSpriteCallXY(parent, font, val / 10 + 0xb,
                                   (position.x + 79.0f) + 15.0f,
                                   (85.0f + y) - 12.0f, (u8)fade, alpha);
        val %= 10;
    }
    font = campStatusGetFont(2);
    campStatusDrawSpriteCallXY(parent, font, val + 0xb,
                               (position.x + 79.0f) + 30.0f,
                               (85.0f + y) - 12.0f, (u8)fade, alpha);
    /* Draw max SP digits */
    val = func_0016c670((s32)(s16)pcId);
    hundreds = 0;
    if (val >= 100) {
        hundreds = 1;
        font = campStatusGetFont(2);
        campStatusDrawSpriteFadeXYCall(
            parent, font, val / 100 + 0xb, position.x + 138.0f, y,
            (u8)fade, alpha, 0x66);
        val %= 100;
    }
    if (val >= 10 || hundreds != 0) {
        font = campStatusGetFont(2);
        campStatusDrawSpriteFadeXYCall(
            parent, font, val / 10 + 0xb,
            (position.x + 138.0f) + 15.0f, y, (u8)fade, alpha, 0x66);
        val %= 10;
    }
    font = campStatusGetFont(2);
    campStatusDrawSpriteFadeXYCall(
        parent, font, val + 0xb, (position.x + 138.0f) + 30.0f, y,
        (u8)fade, alpha, 0x66);
}

// FUN_00123F80
void h_campStatusDrawPhysicalCondition(CampVec2 position, f32 alpha,
                                        s16 pcId, s32 fade)
{
    u32 parent;
    s32 icon;
    s32 bright;
    icon = 0x2B;
    bright = fade;
    switch (datGetPhysicalCondition(pcId)) {
    case 0: icon = 0x0B; break;
    case 1: icon = 0x0D; break;
    case 2: icon = 0x0C; break;
    case 3: icon = 0x10; break;
    case 4: icon = 0x0E; break;
    case 5: icon = 0x0F; break;
    default: break;
    }
    campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B90_abs, icon,
                               position.x + 184.0f,
                               (position.y + 88.0f) - 12.0f,
                               (u8)bright, alpha);
}

// FUN_00124090 NONMATCHING
void h_campStatusDrawBadStatus(CampVec2 position, f32 alpha, s16 pcId,
                               s32 fade)
{
    s32 i;
    u32 offset;
    s32 angle;
    f32 radius;
    f32 sine;
    f32 cosine;
    s8 particleAlpha;
    u32 badStatus;

    badStatus = datGetBadStatusNoDown(pcId);
    if ((badStatus & 0x80) == 0) {
        return;
    }
    DAT_007cdf64++;
    if (DAT_007cdf64 >= 100) {
        DAT_007cdf64 = 0;
    }
    for (i = 0; i < 12; i++) {
        offset = (DAT_007cdf64 + i * 15) % 100;
        if (offset <= 50) {
            continue;
        }
        angle = (i / 3) * 40;
        radius = (f32)(angle / 4 + 40);
        sine = sinf((DAT_007caf38 * radius) / 180.0f);
        cosine = cosf((DAT_007caf38 * radius) / 180.0f);
        radius = (f32)((offset - 50) * 50 / 50);
        if (offset - 50 < 10) {
            particleAlpha = (s8)(-1 - ((offset - 50) * 0xff) / 10);
        } else if (offset - 50 < 40) {
            particleAlpha = 0;
        } else {
            particleAlpha = (s8)(((offset - 90) * 0xff) / 10);
        }
        campStatusDrawParticle(alpha, position.x + 265.0f +
                               radius * cosine,
                               position.y - 13.0f - radius * sine,
                               particleAlpha, i % 3 + 7);
    }
}

// FUN_00124370 NONMATCHING
void h_campStatusDrawStatusTransition(CampVec2 position, f32 alpha,
                                       s16 pcId, s32 phase)
{
    s32 fade;
    s32 hpFade;
    s32 spFade;
    s32 effectFade;
    s32 hpBarOffset;
    s32 spBarOffset;
    s32 hpScaled;
    s32 maxHp;
    s32 spScaled;
    s32 maxSp;
    s32 ratio;
    s32 level;
    f32 slide;
    f32 transitionX;

    CampVec2 transitionPosition;
    void* font;

    if (phase < 3) {
        fade = 0xff - (phase * 0xff) / 3;
        slide = (f32)(((3 - phase) * 0x14) / 3);
    } else {
        fade = 0;
        slide = 0.0f;
    }
    transitionX = position.x - slide;
    campStatusDrawSpriteCall(0, DAT_00833B90, 0, fade,
                             transitionX + 22.0f,
                             (39.0f + position.y) - 12.0f, alpha);

    if (phase != 0) {
        if (phase < 4) {
            fade = 0xff - ((phase - 1) * 0xff) / 3;
            slide = (f32)(((4 - phase) * 0x28) / 3);
        } else {
            fade = 0;
            slide = 0.0f;
        }
        transitionX = position.x - slide;
    }


    if (phase > 3) {

        fade = phase < 9 ? 0xff - ((phase - 4) * 0xff) / 4 : 0;
        if (datGetLevel(pcId) >= 10) {
            font = campStatusGetFont(2);
            level = datGetLevel(pcId);
            campStatusDrawSpriteCall(0, font, level / 10 + 0xb, fade,
                                     transitionX + 81.0f,
                                     ((52.0f + position.y) - 1.0f) - 12.0f,
                                     alpha);
        }
        font = campStatusGetFont(2);
        level = datGetLevel(pcId);
        campStatusDrawSpriteCall(0, font, level % 10 + 0xb, fade,
                                 transitionX + 96.0f,
                                 ((52.0f + position.y) - 1.0f) - 12.0f,
                                 alpha);
    }

    if (phase > 3) {
        if (phase < 9) {
            fade = 0xff - ((phase - 4) * 0xff) / 4;
            slide = (f32)(((9 - phase) * 0x28) / 4);
        } else {
            fade = 0;
            slide = 0.0f;
        }
        transitionPosition = position;
        transitionPosition.x -= slide;
    }


    if (phase > 5) {
        if (phase < 11) {
            fade = 0xff - ((phase - 6) * 0xff) / 4;
            slide = (f32)(((11 - phase) * 0x28) / 4);
        } else {
            fade = 0;
            slide = 0.0f;
        }
        transitionPosition = position;
        transitionPosition.x -= slide;
    }

    if (phase > 10) {
        if (phase < 15) {
            hpFade = 0xff - ((phase - 11) * 0xff) / 4;
        } else {
            hpFade = 0;
        }
        if (phase < 15) {
            hpScaled = (s32)(u32)datGetHp(pcId) * 0x4c;
            maxHp = (s32)(u32)datGetMaxHp(pcId);
            ratio = hpScaled / maxHp;
            hpBarOffset = (ratio * (phase - 11)) / 4;
            if (ratio < hpBarOffset) {
                hpBarOffset = ratio;
            }
            hpBarOffset = 0x4c - hpBarOffset;
        } else {
            hpScaled = (s32)(u32)datGetHp(pcId) * 0x4c;
            maxHp = (s32)(u32)datGetMaxHp(pcId);
            hpBarOffset = 0x4c - hpScaled / maxHp;
        }
        h_campStatusDrawHp(transitionPosition, alpha, pcId,
                           hpBarOffset, hpFade);
    }

    if (phase > 14) {
        if (phase < 19) {
            spFade = 0xff - ((phase - 15) * 0xff) / 4;
        } else {
            spFade = 0;
        }
        if (phase < 19) {
            spScaled = (s32)(u32)datGetSp(pcId) * 0x4c;
            maxSp = (s32)(u32)func_0016c670(pcId);
            ratio = spScaled / maxSp;
            spBarOffset = (ratio * (phase - 15)) / 4;
            if (ratio < spBarOffset) {
                spBarOffset = ratio;
            }
            spBarOffset = 0x4c - spBarOffset;
        } else {
            spScaled = (s32)(u32)datGetSp(pcId) * 0x4c;
            maxSp = (s32)(u32)func_0016c670(pcId);
            spBarOffset = 0x4c - spScaled / maxSp;
        }
        h_campStatusDrawSp(transitionPosition, alpha, pcId,
                           spBarOffset, spFade);
        if (phase < 19) {
            spFade = 0xff - ((phase - 15) * 0xff) / 4;
        } else {
            spFade = 0;
        }
        h_campStatusDrawPhysicalCondition(transitionPosition, alpha,
                                          pcId, spFade);
    }

    if (phase > 15) {
        if (phase < 20) {
            effectFade = 0xff - ((phase - 16) * 0xff) / 4;
        } else {
            effectFade = 0;
        }
        h_campStatusDrawBadStatus(transitionPosition, alpha, pcId,
                                  effectFade);
    }
}

// FUN_00124B30 NONMATCHING
void h_campStatusDrawStatus(CampVec2 position, CampVec2 unused,
                            f32 alpha, s16 pcId, s32 fade)
{
    u32 parent;
    void* font;
    s32 level;
    s32 hpBarOffset;
    s32 spBarOffset;

    campStatusDrawSpriteCall(parent, *(void**)DAT_00833B90_abs, 0, (u8)fade,
                             position.x + 22.0f,
                             position.y + 27.0f - 12.0f, alpha);
    if ((u8)datGetLevel(pcId) >= 10) {
        font = (void*)H_Maestro_001120a0(2);
        level = (u8)datGetLevel(pcId);
        campStatusDrawSpriteCall(parent, font, level / 10 + 0xb, (u8)fade,
                                 position.x + 81.0f,
                                 position.y + 40.0f - 1.0f - 12.0f, alpha);
    }
    font = (void*)H_Maestro_001120a0(2);
    level = (u8)datGetLevel(pcId);
    campStatusDrawSpriteCall(parent, font, level % 10 + 0xb, (u8)fade,
                             position.x + 96.0f,
                             position.y + 40.0f - 1.0f - 12.0f, alpha);

    hpBarOffset = 0x4c - (datGetHp(pcId) * 0x4c) / datGetMaxHp(pcId);
    h_campStatusDrawHp(position, alpha, pcId, hpBarOffset, fade);
    spBarOffset = 0x4c - (datGetSp(pcId) * 0x4c) / func_0016c670(pcId);
    h_campStatusDrawSp(position, alpha, pcId, spBarOffset, fade);
    h_campStatusDrawPhysicalCondition(position, alpha, pcId, fade);
    h_campStatusDrawBadStatus(position, alpha, pcId, fade);
}

// FUN_00123540. Destroy callback of the "H_CampPcStatusRoot" task
void h_campStatusDestroyPcStatusRootTask(KwlnTask* task)
{
    RwFree(task->workData);
}

// FUN_00123570
KwlnTask* h_campStatusCreatePcStatusRootTask(KwlnTask* parent, u32 priority, short param_3)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x24, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampPcStatusRoot", priority, h_campStatusUpdatePcStatusRootTask, h_campStatusDestroyPcStatusRootTask, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = param_3;
    return task;
}

// FUN_001335d0. Destroy callback of the "H_CampStatusPersonaDraw" task
void h_campStatusDestroyPersonaDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x58) != 0) {
            FUN_001124b0(*(int*)((int)workData + i * 4 + 0x58));
        }
        *(int*)((int)workData + i * 4 + 0x58) = 0;
    }
    if (workData[0x19] != 0) {
        RwFree((void*)workData[0x19]);
    }
    workData[0x19] = 0;
    if (workData[0x1a] != 0) {
        RwFree((void*)workData[0x1a]);
    }
    workData[0x1a] = 0;
    if (workData[0x14] != 0) {
        H_Cdvd_Destroy((HCdvd*)workData[0x14]);
    }
    workData[0x14] = 0;
    RwFree(workData);
}

// FUN_001336b0
KwlnTask* h_campStatusCreatePersonaDrawTask(KwlnTask* parent, u32 priority, CampVec2 param_3, u16 param_4)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x6c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampStatusPersonaDraw", priority, FUN_001311d0, h_campStatusDestroyPersonaDrawTask, workData);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((int)workData + 0x10) = param_3;
    *(u16*)((int)workData + 0x18) = param_4;
    return task;
}

// FUN_001266e0. Destroy callback of the "H_PcStatusParts00" task
void h_campStatusDestroyPcStatusPartsTask(KwlnTask* task)
{
    RwFree(task->workData);
}
extern void* DAT_00833B98;
extern int sprintf(char* buffer, const char* format, ...);

typedef struct CampStatusSprite
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[3];
    s16 value;
    u8 reserved1e[0x0e];
    f32 scale;
} CampStatusSprite;

typedef s32 (*CampStatusRawSpriteFn)(void* parent, void* resource,
                                     s32 frame, u32 alpha, f32 x, f32 y,
                                     f32 scale);

static inline void campStatusDrawSprite(void* resource, s32 frame, f32 x, f32 y,
                                 f32 scale, s32 alpha)
{
    CampStatusRawSpriteFn draw;

    draw = (CampStatusRawSpriteFn)FUN_001159f0;
    draw((void*)(u32)0x42c80000, resource, frame, (u32)alpha, x, y,
         scale);
}

static inline void campStatusDrawBar(f32 scale, f32 x, f32 y, u8 alpha,
                              s32 frame, s32 value)
{
    CampStatusSprite* sprite;

    sprite = (CampStatusSprite*)(u32)FUN_001158b0(0, DAT_00833B98, frame);
    sprite->scale = scale;
    sprite->x = x;
    sprite->y = y;
    sprite->alpha = alpha;
    sprite->value = (s16)((value * 0xe3) / 99);
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
}

static void campStatusDrawValue(f32 scale, f32 x, f32 y,
                                u8 alpha, s32 value)
{
    campStatusDrawBar(scale, x, y, alpha, 0x18, value);
}

static inline s32 campStatusGetDisplayedValue(void* persona, void* bonus,
                                       s32 index, s32 useSkillAccessors)
{
    s32 value;

    if (useSkillAccessors != 0) {
        value = FUN_00173580(persona, index) & 0xff;
    } else {
        value = FUN_00173660(persona, index) & 0xff;
    }
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

#define campStatusDrawDigitRow(x, y, scale, bonus, persona, alpha, index, \
                               useSkillAccessors) \
{ \
    u32 rowValue; \
    void* rowResource; \
    if ((useSkillAccessors) != 0) { \
        rowValue = FUN_00173580((persona), (index)) & 0xff; \
    } else { \
        rowValue = FUN_00173660((persona), (index)) & 0xff; \
    } \
    if ((bonus) != NULL) { \
        rowValue += *((u8*)(bonus) + 0x38 + (index)); \
    } \
    if (rowValue >= 10) { \
        rowResource = campStatusGetFont(2); \
        campStatusDrawSpriteCallXY(parent, rowResource, \
                                   rowValue / 10 + 0xb, \
                                   (x) + 69.0f, \
                                   (y) + 131.0f + \
                                       (f32)((index) * 19) - 25.0f, \
                                   (u8)(alpha), (scale)); \
    } \
    rowResource = campStatusGetFont(2); \
    campStatusDrawSpriteCallXY(parent, rowResource, \
                               rowValue % 10 + 0xb, \
                               (x) + 85.0f, \
                               (y) + 131.0f + \
                                   (f32)((index) * 19) - 25.0f, \
                               (u8)(alpha), (scale)); \
}

static inline void campStatusDrawDigits(CampVec2 position, f32 scale,
                                        void* bonus, void* persona,
                                        s32 alpha, s32 useSkillAccessors)
{
    u32 parent;
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 0, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 1, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 2, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 3, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 4, useSkillAccessors);
}

static void campStatusDrawStats(CampVec2 position, f32 scale, void* persona,
                                u8 alpha, u8 drawCurrent)
{
    s32 i;
    s32 value;
    s32 current;

    for (i = 0; i < 5; i++) {
        value = FUN_00173660(persona, i) & 0xff;
        current = 0;
        if (drawCurrent != 0) {
            current = *((u8*)persona + 0x38 + i);
        }
        h_campStatusDrawRankValue(position, scale, i, value, current, alpha);
    }
}

static void campStatusDrawExp(CampVec2 position, f32 scale, void* bonus,
                              void* persona, u8 alpha)
{
    char text[0x100];
    s32 current;
    s32 next;

    h_campStatusDrawEquipment(position, scale, bonus, persona, alpha);
    campStatusDrawSprite(DAT_00833B90, 0x11, position.x + 33.0f,
                         position.y + 278.0f, scale, alpha);
    campStatusDrawSprite(DAT_00833B90, 0x22, position.x + 287.0f,
                         position.y + 280.0f, scale, alpha);
    if (*((u8*)persona + 4) == 0x63) {
        sprintf(text, "%d", 0);
    } else {
        current = FUN_00173340(persona);
        next = FUN_00173330(persona);
        sprintf(text, "%d", current - next);
    }
    FUN_0040eb50((s32)(position.x + 287.0f), (s32)(position.y + 280.0f),
                 (u8)(0xff - alpha), 4, text, 1);
}

// FUN_0012B300 NONMATCHING
void FUN_0012b300(CampVec2 position, f32 scale, void* persona, u8 alpha)
{
    s32 i;
    s32 value;
    char text[0x100];

    for (i = 0; i < 9; i++) {
        h_campStatusRenderStatIcon(position, scale, i, alpha);
    }
    h_campStatusDrawStatLabels(position, scale, persona, alpha);
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x12, alpha,
                             position.x + 30.0f,
                             (125.0f + position.y) - 25.0f, scale);
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x13, alpha,
                             position.x + 30.0f,
                             (184.0f + position.y) - 25.0f, scale);
    h_campStatusDrawStatValues(position, scale, NULL, persona, alpha);
    for (i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            value = FUN_00173660(persona, 0) & 0xff;
            break;
        case 1:
            value = FUN_00173660(persona, 1) & 0xff;
            break;
        case 2:
            value = FUN_00173660(persona, 2) & 0xff;
            break;
        case 3:
            value = FUN_00173660(persona, 3) & 0xff;
            break;
        case 4:
            value = FUN_00173660(persona, 4) & 0xff;
            break;
        }
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x14, alpha,
                                 position.x + 104.0f,
                                 position.y + 104.0f +
                                     (f32)(i * 11), scale);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x15, alpha,
                                 position.x + 333.0f,
                                 position.y + 104.0f +
                                     (f32)(i * 11), scale);
        campStatusDrawBar(scale, position.x + 108.0f,
                          position.y + 105.0f + (f32)(i * 11),
                          alpha, 0x18, value);
    }
    h_campStatusDrawEquipment(position, scale, NULL, persona, alpha);
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B90, 0x11, alpha,
                             position.x + 33.0f,
                             position.y + 278.0f, scale);
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B90, 0x22, alpha,
                             position.x + 287.0f,
                             position.y + 280.0f, scale);
    if (*((u8*)persona + 4) == 0x63) {
        sprintf(text, "%d", 0);
    } else {
        value = FUN_00173340(persona);
        i = FUN_00173330(persona);
        sprintf(text, "%d", value - i);
    }
    FUN_0040eb50((s32)(position.x + 287.0f), (s32)(position.y + 280.0f),
                 (u8)(0xff - alpha), 4, text, 1);
}

// FUN_0012B860 NONMATCHING
void FUN_0012b860_s32(CampVec2 position, f32 scale, void* currentStats,
                      void* persona, s32 alpha)
{
    u32 i;
    s32 value;
    s32 current;
    struct {
        char text[0x100];
        CampVec2 footerPosition;
        CampVec2 headerPosition;
    } locals;

    for (i = 0; i < 9; i++) {
        h_campStatusRenderStatIcon(position, scale, i, alpha);
    }
    h_campStatusDrawStatLabels(position, scale, persona, alpha);
    {
        u32 spriteParent;
        f32 headerY;
        f32 headerX;
        locals.headerPosition = position;
        headerX = locals.headerPosition.x + 30.0f;
        headerY = locals.headerPosition.y;
        campStatusDrawSpriteCall(spriteParent, DAT_00833B98, 0x12,
                                 (u8)alpha, headerX,
                                 (125.0f + headerY) - 25.0f, scale);
        campStatusDrawSpriteCall(spriteParent, DAT_00833B98, 0x13,
                                 (u8)alpha, headerX,
                                 (184.0f + headerY) - 25.0f, scale);
    }
    h_campStatusDrawStatValues(position, scale, currentStats, persona, alpha);
    for (i = 0; i < 5; i++) {
        switch (i) {
        case 0: value = FUN_00173660(persona, 0) & 0xff; break;
        case 1: value = FUN_00173660(persona, 1) & 0xff; break;
        case 2: value = FUN_00173660(persona, 2) & 0xff; break;
        case 3: value = FUN_00173660(persona, 3) & 0xff; break;
        case 4: value = FUN_00173660(persona, 4) & 0xff; break;
        }
        current = 0;
        if (currentStats != NULL) {
            switch (i) {
            case 0: current = *((u8*)currentStats + 0x38); break;
            case 1: current = *((u8*)currentStats + 0x39); break;
            case 2: current = *((u8*)currentStats + 0x3a); break;
            case 3: current = *((u8*)currentStats + 0x3b); break;
            case 4: current = *((u8*)currentStats + 0x3c); break;
        }
        }
        h_campStatusDrawRankValue(position, scale, i, value, current, alpha);
    }
    h_campStatusDrawEquipment(position, scale, currentStats, persona, alpha);
    {
        u32 footerParent;
        f32 footerY;
        f32 footerX;
        locals.footerPosition = position;
        locals.footerPosition.x += 12.0f;
        locals.footerPosition.y += 96.0f;
        footerX = locals.footerPosition.x + 21.0f;
        footerY = locals.footerPosition.y + 182.0f;
        campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x11, (u8)alpha,
                                 footerX, footerY, scale);
        campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x22, (u8)alpha,
                                 locals.footerPosition.x + (f32)0x113,
                                 footerY, scale);
        {
            f32 textX = footerX + 254.0f;
            f32 textY = footerY + 2.0f;
            if (*((u8*)persona + 4) == 0x63) {
                sprintf(locals.text, "%d", 0);
            } else {
                value = FUN_00173340(persona);
                current = FUN_00173330(persona);
                sprintf(locals.text, "%d", value - current);
            }
            FUN_0040eb50((s32)textX, (s32)textY, (u8)(0xff - alpha), 4,
                         locals.text, 1);
        }
    }
}
// FUN_0012BCE0 NONMATCHING
void FUN_0012bce0(CampVec2 position, f32 scale, void* unused,
                  void* persona, u8 alpha)
{
    s32 i;
    s32 value;
    s32 current;
    char text[0x100];
    u32 headerParent;
    u32 footerParent;

    (void)unused;
    for (i = 0; i < 9; i++) {
        h_campStatusRenderStatIcon(position, scale, i, alpha);
    }
    h_campStatusDrawStatLabels(position, scale, persona, alpha);
    campStatusDrawSpriteCall(headerParent, DAT_00833B98, 0x12, alpha,
                             position.x + 30.0f,
                             (125.0f + position.y) - 25.0f, scale);
    campStatusDrawSpriteCall(headerParent, DAT_00833B98, 0x13, alpha,
                             position.x + 30.0f,
                             (184.0f + position.y) - 25.0f, scale);
    campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x11, alpha,
                             position.x + 33.0f, position.y + 278.0f, scale);
    campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x22, alpha,
                             position.x + 287.0f, position.y + 280.0f, scale);
    if (*((u8*)persona + 4) == 0x63) {
        sprintf(text, "%d", 0);
    } else {
        value = FUN_00173340(persona);
        current = FUN_00173330(persona);
        sprintf(text, "%d", value - current);
    }
    FUN_0040eb50((s32)(position.x + 287.0f), (s32)(position.y + 280.0f),
                 (u8)(0xff - alpha), 4, text, 1);
}

// FUN_0012BFB0 NONMATCHING
void FUN_0012bfb0_s32(CampVec2 position, f32 scale, void* currentStats,
                      void* persona, s32 alpha)
{
    u32 i;
    s32 value;
    s32 current;
    struct {
        char text[0x100];
        CampVec2 footerPosition;
        CampVec2 headerPosition;
    } locals;

    for (i = 0; i < 9; i++) {
        h_campStatusRenderStatIcon(position, scale, i, alpha);
    }
    h_campStatusDrawStatLabels(position, scale, persona, alpha);
    {
        u32 spriteParent;
        f32 headerY;
        f32 headerX;
        locals.headerPosition = position;
        headerX = locals.headerPosition.x + 30.0f;
        headerY = locals.headerPosition.y;
        campStatusDrawSpriteCall(spriteParent, DAT_00833B98, 0x12,
                                 (u8)alpha, headerX,
                                 (125.0f + headerY) - 25.0f, scale);
        campStatusDrawSpriteCall(spriteParent, DAT_00833B98, 0x13,
                                 (u8)alpha, headerX,
                                 (184.0f + headerY) - 25.0f, scale);
    }
    h_campStatusDrawSkillValues(position, scale, currentStats, persona,
                                alpha);
    for (i = 0; i < 5; i++) {
        switch (i) {
        case 0: value = FUN_00173580(persona, 0) & 0xff; break;
        case 1: value = FUN_00173580(persona, 1) & 0xff; break;
        case 2: value = FUN_00173580(persona, 2) & 0xff; break;
        case 3: value = FUN_00173580(persona, 3) & 0xff; break;
        case 4: value = FUN_00173580(persona, 4) & 0xff; break;
        }
        current = 0;
        if (currentStats != NULL) {
            switch (i) {
            case 0: current = *((u8*)currentStats + 0x38); break;
            case 1: current = *((u8*)currentStats + 0x39); break;
            case 2: current = *((u8*)currentStats + 0x3a); break;
            case 3: current = *((u8*)currentStats + 0x3b); break;
            case 4: current = *((u8*)currentStats + 0x3c); break;
        }
        }
        h_campStatusDrawRankValue(position, scale, i, value, current, alpha);
    }
    h_campStatusDrawEquipment(position, scale, currentStats, persona, alpha);
    {
        u32 footerParent;
        f32 footerY;
        f32 footerX;
        locals.footerPosition = position;
        locals.footerPosition.x += 12.0f;
        locals.footerPosition.y += 96.0f;
        footerX = locals.footerPosition.x + 21.0f;
        footerY = locals.footerPosition.y + 182.0f;
        campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x11, (u8)alpha,
                                 footerX, footerY, scale);
        campStatusDrawSpriteCall(footerParent, DAT_00833B90, 0x22, (u8)alpha,
                                 locals.footerPosition.x + (f32)0x113,
                                 footerY, scale);
        {
            f32 textX = footerX + 254.0f;
            f32 textY = footerY + 2.0f;
            if (*((u8*)persona + 4) == 0x63) {
                sprintf(locals.text, "%d", 0);
            } else {
                value = FUN_00173340(persona);
                current = FUN_00173330(persona);
                sprintf(locals.text, "%d", value - current);
            }
            FUN_0040eb50((s32)textX, (s32)textY, (u8)(0xff - alpha), 4,
                         locals.text, 1);
        }
    }
}
/*
 * Status-screen renderer and transition tasks.
 *
 * The retail status UI keeps two small task work areas: the first owns the
 * archive/texture used by the PC status parts task, while the second drives
 * the animated stat panel.  Keep the offsets explicit here; these layouts are
 * shared with the callbacks registered by the surrounding camp code.
 */
typedef struct CampStatusPartsWork
{
    u32 state;                 /* 0x00 */
    f32 x;                     /* 0x04 */
    f32 y;                     /* 0x08 */
    s16 alpha;                 /* 0x0c */
    s16 mode;                  /* 0x0e */
    s16 screen;                /* 0x10 */
    s16 detailFrame;           /* 0x12 */
    u32 flags;                 /* 0x14 */
    u32 ready;                 /* 0x18 */
    s32 result;                /* 0x1c */
    u32 reserved20[6];         /* 0x20..0x34 */
    void* ownedResource;       /* 0x38 */
    void* archive;             /* 0x3c */
    void* parsedResource;      /* 0x40 */
    f32 scrollY;               /* 0x44 */
} CampStatusPartsWork;

typedef struct CampStatusPanelWork
{
    u32 state;                 /* 0x00 */
    f32 x;                     /* 0x04 */
    f32 y;                     /* 0x08 */
    s16 alpha;                 /* 0x0c */
    s16 priorityMode;          /* 0x0e */
    s16 animationFrame;        /* 0x10 */
    s16 panelMode;             /* 0x12 */
    s32 result;                /* 0x14 */
    u32 ready;                 /* 0x18 */
    KwlnTask* child;           /* 0x1c */
} CampStatusPanelWork;

typedef struct CampStatusVertex
{
    RwV3d position;
    f32 cameraZ;
    f32 u;
    f32 v;
    f32 recipZ;
    f32 pad0;
    RwRGBAReal color;
    RwV3d normal;
    f32 pad1;
} CampStatusVertex;

extern void (*DAT_00960090)(u32 state, u32 value);
extern void (*DAT_009600A0)(u32 primitive, CampStatusVertex* vertices,
                            s32 vertexCount);
extern f32 DAT_00960088;
#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];
#pragma alias DAT_009600A0_abs DAT_009600A0
extern u8 DAT_009600A0_abs[];
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern s32 FUN_00198590();
extern void (*jtbl_007B5B60[9])();
extern void* DAT_00833B98;
extern s32 iGpffffb7fc;
extern const void* gp0xffff8978;
extern const void* gp0xffff8980;
extern s32 FUN_00100ec0();
extern s32 FUN_004d0f00();
extern s32 FUN_001fc230();
extern s32 FUN_001fc3c0();
extern s32 FUN_001fb1f0();
extern void FUN_003b32d0();
#pragma alias FUN_003b32d0_typed FUN_003b32d0
extern void FUN_003b32d0_typed(f32 depth, s32 x, s32 y, s32 color, s32 font,
                                s32 alignment, const char* text, s32 maxWidth,
                                s32 shadow);
extern void FUN_00523ac8();

static void h_campStatusDrawQuad(f32 x, f32 y, f32 width, f32 height,
                                  u32 texture, s32 alpha)
{
    CampStatusVertex vertices[4];
    void* camera;
    f32 recipZ;
    s32 i;

    camera = (void*)FUN_00198590();
    recipZ = 1.0f / *((f32*)camera + 0x20);
    (*DAT_00960090)(6, 1);
    (*DAT_00960090)(7, 2);
    (*DAT_00960090)(8, 1);
    (*DAT_00960090)(11, 6);
    (*DAT_00960090)(10, 5);
    (*DAT_00960090)(9, 2);
    (*DAT_00960090)(12, 1);
    (*DAT_00960090)(2, 4);
    for (i = 0; i < 4; i++) {
        vertices[i].position.z = DAT_00960088 - x;
        vertices[i].recipZ = recipZ;
        vertices[i].color.r = 255.0f;
        vertices[i].color.g = 255.0f;
        vertices[i].color.b = 255.0f;
        vertices[i].color.a = (f32)alpha;
    }
    vertices[0].position.x = x;
    vertices[0].position.y = y;
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;
    vertices[1].position.x = x + width;
    vertices[1].position.y = y;
    vertices[1].u = 1.0f;
    vertices[1].v = 0.0f;
    vertices[2].position.x = x;
    vertices[2].position.y = y + height;
    vertices[2].u = 0.0f;
    vertices[2].v = 1.0f;
    vertices[3].position.x = x + width;
    vertices[3].position.y = y + height;
    vertices[3].u = 1.0f;
    vertices[3].v = 1.0f;
    (*DAT_00960090)(1, texture);
    (*DAT_009600A0)(4, vertices, 4);
}

static void h_campStatusDrawStatIcon(u32 parent, CampVec2 position,
                                      s32 stat, s32 alpha)
{
    static const s32 iconX[9] = { 29, 69, 109, 159, 199, 239, 279, 319, 359 };
    f32 x;
    f32 y;

    if (stat < 0 || stat >= 9) {
        return;
    }
    x = position.x + (f32)iconX[stat];
    y = position.y + 44.0f;
    FUN_001159f0(x, y, parent, DAT_00833B98, stat, alpha & 0xff);
}

static void h_campStatusDrawStatIcons(u32 parent, CampVec2 position,
                                       void* persona, s32 alpha)
{
    static const s32 accessor[9] = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };
    s32 i;

    for (i = 0; i < 9; i++) {
        FUN_001733b0(persona, accessor[i]);
        h_campStatusDrawStatIcon(parent, position, i, alpha);
    }
}

static s32 h_campStatusStatValue(void* persona, void* bonus, s32 index)
{
    s32 value;

    value = (s32)(FUN_00173660(persona, index) & 0xff);
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

static s32 h_campStatusSkillValue(void* persona, void* bonus, s32 index)
{
    s32 value;

    value = (s32)(FUN_00173580(persona, index) & 0xff);
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

static void h_campStatusDrawLabelRow(u32 parent, CampVec2 position,
                                     void* persona, void* bonus, s32 alpha,
                                     s32 useSkillAccessors)
{
    s32 i;
    s32 value;
    s32 x;
    f32 y;

    for (i = 0; i < 5; i++) {
        value = useSkillAccessors
            ? h_campStatusSkillValue(persona, bonus, i)
            : h_campStatusStatValue(persona, bonus, i);
        x = (s32)position.x + 104;
        y = position.y + 129.0f + (f32)(i * 19) - 25.0f;
        FUN_001159f0((f32)x, y, parent, DAT_00833B98, 20, alpha & 0xff);
        FUN_001159f0(position.x + 333.0f, y, parent, DAT_00833B98, 21,
                     alpha & 0xff);
        {
            void* text;
            text = (void*)(u32)FUN_001158b0(0, DAT_00833B98, 0x18);
            *((u32*)text + 11) = parent;
            *((f32*)text + 4) = (f32)x + 4.0f;
            *((f32*)text + 5) = y + 1.0f;
            *((u8*)text + 0x18) = (u8)alpha;
            *((s16*)text + 0x0e) = (s16)((value * 0xe3) / 99);
            FUN_001127d0(text, 1);
            FUN_00115980(text);
        }
    }
}

static void h_campStatusDrawEquipmentSlots(u32 parent, CampVec2 position,
                                            void* persona, void* bonus,
                                            s32 alpha)
{
    u16 equipped[8];
    char text[44];
    s32 i;
    s32 row;
    s32 col;
    s32 item;
    s32 disabled;
    s32 count;

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 4; col++) {
            i = row * 4 + col;
            FUN_001159f0(position.x + 34.0f + (f32)(row * 190),
                         position.y + 316.0f + (f32)(col * 24), parent);
            item = *((u16*)persona + 3 + i);
            if (item == 0) {
                continue;
            }
            disabled = bonus == NULL || *((s16*)((u8*)bonus + 0x3e + i * 2)) == 0;
            FUN_00523ac8(text, gp0xffff897c,
                         iGpffffb7fc + item * 0x13);
            FUN_003b32d0(parent,
                         (s32)position.x + 44 + row * 190,
                         (s32)position.y + 320 + col * 24,
                         disabled ? ((0xff - alpha) | 0x95b9ff00)
                                  : ((0xff - alpha) | 0x77ffcf00),
                         6, 1, text, 0x10, 0x78);
        }
    }
    if (FUN_001fc230(persona) != 0) {
        FUN_001159f0(position.x + 411.0f, position.y + 326.0f, parent);
        FUN_001159f0(position.x + 557.0f, position.y + 326.0f, parent);
        count = FUN_001fc3c0(persona);
        if (count < 10) {
            FUN_001120a0(2);
            FUN_001159f0(position.x + 534.0f, position.y + 328.0f,
                         parent);
        }
        else {
            FUN_001120a0(2);
            FUN_001159f0(position.x + 526.0f, position.y + 328.0f,
                         parent);
            FUN_001120a0(2);
            FUN_001159f0(position.x + 541.0f, position.y + 328.0f,
                         parent);
        }
    }
    count = 0;
    FUN_001fb1f0(persona, equipped, &count);
    if (count > 7) {
        count = 7;
    }
    for (i = 0; i < count; i++) {
        if (equipped[i] != 0) {
            FUN_001159f0(position.x + 414.0f + (f32)((i / 2) * 62),
                         position.y + 340.0f + (f32)((i & 1) * 24), parent);
            FUN_00523ac8(text, gp0xffff897c,
                         iGpffffb7fc + equipped[i] * 0x13);
            FUN_003b32d0(parent,
                         (s32)position.x + 424 + (i / 2) * 62,
                         (s32)position.y + 344 + (i & 1) * 24,
                         (0xff - alpha) | 0x95b9ff00,
                         6, 1, text, 0x10, 0x78);
        }
    }
}

// FUN_00126710 NONMATCHING
#pragma push
/* opt_loop_invariants on: nd281/620B off -> nd147/624B on; retained. */
#pragma opt_loop_invariants on
void h_campStatusDrawViewport(void* texture, CampVec2 position, f32 x,
                              s32 alpha)
{
    CampStatusVertex vertices[4];
    void* camera;
    f32 recipZ;
    s32 i;
    void (**setState)(u32, u32);
    void (**submitVertices)(u32, CampStatusVertex*, s32);
    void* textureWork;

    textureWork = texture;
    camera = (void*)FUN_00198590();
    recipZ = 1.0f / *((f32*)camera + 0x20);
    setState = (void (**)(u32, u32))DAT_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(11, 6);
    (*setState)(10, 5);
    (*setState)(9, 2);
    (*setState)(12, 1);
    (*setState)(2, 4);
    for (i = 0; i < 4; i++) {
        vertices[i].color.r = 255.0f;
        vertices[i].color.g = 255.0f;
        vertices[i].color.b = 255.0f;
        vertices[i].color.a = (f32)alpha;
        vertices[i].position.z = *(f32*)DAT_00960088_abs - x;
        vertices[i].recipZ = recipZ;
    }
    vertices[0].position.x = position.x;
    vertices[0].position.y = position.y;
    vertices[1].position.x = position.x + 512.0f;
    vertices[1].position.y = position.y;
    vertices[2].position.x = position.x;
    vertices[2].position.y = position.y + 1024.0f;
    vertices[3].position.x = position.x + 512.0f;
    vertices[3].position.y = position.y + 1024.0f;
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;
    vertices[1].u = 1.0f;
    vertices[1].v = 0.0f;
    vertices[2].u = 0.0f;
    vertices[2].v = 1.0f;
    vertices[3].u = 1.0f;
    vertices[3].v = 1.0f;
    submitVertices = (void (**)(u32, CampStatusVertex*, s32))DAT_009600A0_abs;
    (*setState)(1, *(u32*)textureWork);
    (*submitVertices)(4, vertices, 4);
    vertices[0].position.y = position.y + 1104.0f;
    vertices[1].position.y = position.y + 1104.0f;
    vertices[2].position.y = position.y + 2128.0f;
    vertices[3].position.y = position.y + 2128.0f;
    (*setState)(1, *(u32*)textureWork);
    (*submitVertices)(4, vertices, 4);
}
#pragma pop


static void h_campStatusDrawPanel(CampStatusPartsWork* work, s32 alpha,
                                  f32 yOffset, void* persona, void* bonus)
{
    CampVec2 position;
    u32 parent;

    position.x = 188.0f - yOffset;
    position.y = work->scrollY;
    h_campStatusDrawViewport(work->parsedResource, position, 105.0f, alpha);
    h_campStatusDrawStatIcons(parent, position, persona, alpha);
    h_campStatusDrawLabelRow(parent, position, persona, bonus, alpha, 0);
    h_campStatusDrawEquipmentSlots(parent, position, persona, bonus, alpha);
}

static inline void h_campStatusResetInput(CampStatusPartsWork* work, s32 mask)
{
    if ((DAT_007e094e & 0x20) != 0) {
        FUN_0010a4e0(0, 0, 0, 2);
        work->result = -1;
    }
    else if ((DAT_007e094e & mask) != 0 ||
             (DAT_007e0958 & mask) != 0) {
        FUN_0010a4e0(0, 0, 0, 0);
        work->result = 1;
    }
}

#pragma opt_common_subs off
// FUN_001269A0 NONMATCHING
void* h_campStatusUpdatePartsTask(KwlnTask* task)
{
    CampStatusPartsWork* work;
    CampVec2 position;
    void* childWork;
    KwlnTask* child;
    s16 screen;
    s32 done;
    s32 alpha;
    s32 frame;

    work = (CampStatusPartsWork*)task->workData;
    switch (work->state) {
    case 0:
        work->scrollY = -20.0f;
        if (FUN_0017d800() != 0) {
            work->archive = (void*)FUN_0010c1a0(
                0, D_005DB050, 0, 0, 0, 0, 0, 0,
                0, 0, D_005DB080, 0x6ef);
        }
        else {
            work->archive = (void*)FUN_0010c1a0(
                0, D_005DB0A0, 0, 0, 0, 0, 0, 0,
                0, 0, D_005DB080, 0x6f1);
        }
        work->state = 1;
        break;
    case 1:
        work->parsedResource = (void*)FUN_0010c3a0(
            work->archive, &done, 0);
        if (done != 0) {
            work->state = 2;
        }
        break;
    case 2:
        if (FUN_0011e380(DAT_007cdf50, 2) != 0) {
            work->state = 3;
        }
        break;
    case 3:
        if (*((s32*)((u8*)DAT_007cdf50->workData + 0x10)) != 0) {
            if (work->screen == 0) {
                work->detailFrame = 0;
                h_campDrawRootMenuEntriesClosing(
                    (CampRootDrawWork*)DAT_007cdf5c->workData, 100.0f);
                *((u32*)DAT_007cdf5c->workData) = 8;
                *((u32*)DAT_007cdf5c->workData + 1) = 0x16;
            }
            else if (work->screen == 1) {
                work->detailFrame = 0;
            }
            screen = work->screen;
            childWork = (*DAT_00960184)(1, 0xc, 0x40000);
            child = NULL;
            if (childWork != NULL) {
                child = (KwlnTask*)FUN_00194b20(
                    task, D_005DB030, 0x18be, FUN_00125d70,
                    h_campStatusDestroyPcStatusPartsTask, childWork);
                if (child != NULL) {
                    *((s16*)((u8*)childWork + 4)) = screen;
                }
            }
            *((KwlnTask**)((u8*)work + 0x24)) = child;
            FUN_00121de0(DAT_007cdf54, 2);
            FUN_00122710(DAT_007cdf58, 2);
            child = *((KwlnTask**)((u8*)work + 0x24));
            *((s32*)((u8*)child->workData + 8)) = work->alpha;
            work->state = 4;
        }
        break;
    case 4:
        if (work->alpha != 0xff) {
            work->alpha += 10;
            if (work->alpha >= 0x100) {
                work->alpha = 0xff;
            }
        }
        if (work->screen != 0) {
            child = *((KwlnTask**)((u8*)work + 0x24));
            *((s32*)((u8*)child->workData + 8)) = work->alpha;
        }
        position.x = 188.0f;
        position.y = work->scrollY;
        if (work->screen == 1) {
            frame = work->detailFrame;
            if (frame != 8) {
                position.x = 188.0f -
                    (f32)(((8 - frame) * 25) / 8);
                h_campStatusDrawViewport(
                    work->parsedResource, position, 105.0f, 0xff);
                work->scrollY -= 1.0f;
                if (work->scrollY < -1104.0f) {
                    work->scrollY = 0.0f;
                }
                position.x = -(f32)(((8 - frame) * 500) / 8);
                position.y = 0.0f;
                alpha = 0xff - (frame * 255) / 8;
                work->detailFrame++;
            }
            else {
                h_campStatusDrawViewport(
                    work->parsedResource, position, 105.0f, 0xff);
                work->scrollY -= 1.0f;
                if (work->scrollY < -1104.0f) {
                    work->scrollY = 0.0f;
                }
                position.x = 0.0f;
                position.y = 0.0f;
                alpha = 0;
                h_campStatusResetInput(work, 0x2000);
            }
            h_campStatusDrawPanelFrame(1, position, alpha);
        }
        else {
            frame = work->detailFrame;
            if (frame == 8) {
                h_campStatusDrawViewport(
                    work->parsedResource, position, 105.0f, 0xff);
                work->scrollY -= 1.0f;
                if (work->scrollY < -1104.0f) {
                    work->scrollY = 0.0f;
                }
            }
            else {
                work->detailFrame++;
            }
            position.x = 0.0f;
            position.y = 0.0f;
            alpha = 0xff - work->alpha;
            h_campStatusDrawPanelFrame(1, position, alpha);
            h_campStatusResetInput(work, 0x2000);
        }
        break;
    case 5:
        if (FUN_0011e380(DAT_007cdf50, 1) != 0) {
            work->state = 6;
        }
        position.x = 188.0f;
        position.y = work->scrollY;
        h_campStatusDrawViewport(
            work->parsedResource, position, 105.0f, 0xff);
        work->scrollY -= 1.0f;
        if (work->scrollY < -1064.0f) {
            work->scrollY = 0.0f;
        }
        position.x = 0.0f;
        position.y = 0.0f;
        h_campStatusDrawPanelFrame(1, position, 0);
        break;
    case 6:
        work->alpha -= 25;
        if (work->alpha < 0) {
            return KWLNTASK_STOP;
        }
        position.x = 188.0f;
        position.y = work->scrollY;
        h_campStatusDrawViewport(
            work->parsedResource, position, 105.0f, 0xff);
        work->scrollY -= 1.0f;
        if (work->scrollY < -1104.0f) {
            work->scrollY = 0.0f;
        }
        position.x = 0.0f;
        position.y = 0.0f;
        h_campStatusDrawPanelFrame(1, position, 0xff - work->alpha);
        break;
    case 7:
        position.x = 188.0f;
        position.y = work->scrollY;
        h_campStatusDrawViewport(
            work->parsedResource, position, 105.0f, 0xff);
        work->scrollY -= 1.0f;
        if (work->scrollY < -1104.0f) {
            work->scrollY = 0.0f;
        }
        position.x = 0.0f;
        position.y = 0.0f;
        h_campStatusDrawPanelFrame(1, position, 0);
        if (*((s32*)((u8*)DAT_007cdf50->workData + 0x10)) != 0) {
            work->detailFrame = 0;
            child = *((KwlnTask**)((u8*)work + 0x24));
            childWork = child->workData;
            *((s16*)((u8*)childWork + 4)) = 2;
            *((s16*)((u8*)childWork + 6)) = 0;
            work->state = 8;
        }
        break;
    case 8:
        work->detailFrame++;
        if (work->detailFrame == 8) {
            return KWLNTASK_STOP;
        }
        position.x = 188.0f -
            (f32)((work->detailFrame * 500) / 8);
        position.y = work->scrollY;
        h_campStatusDrawViewport(
            work->parsedResource, position, 105.0f, 0xff);
        work->scrollY -= 1.0f;
        if (work->scrollY < -1104.0f) {
            work->scrollY = 0.0f;
        }
        position.x = -(f32)((work->detailFrame * 500) / 8);
        position.y = 0.0f;
        alpha = (work->detailFrame * 255) / 8;
        h_campStatusDrawPanelFrame(1, position, alpha);
        break;
    }
    return KWLNTASK_CONTINUE;
}

/* Retail panel frame: seventeen status sprites, two footer sprites, and the
 * formatted footer text, with resource and frame selections from retail. */
#pragma opt_loop_invariants on
#pragma opt_common_subs reset
// FUN_001273B0 NONMATCHING
void h_campStatusDrawPanelFrame(u32 parent, CampVec2 position, s32 alpha)
{
    u32 drawParent;
    u32 drawAlpha;
    s16 footerAlpha;
    s16 count;
    s32 inverseAlpha;
    f32 left;
    f32 right;
    f32 top;
    CampVec2 bottomPosition;
    char text[264];

    drawParent = 0x42c80000;
    drawAlpha = (u8)alpha;
    left = position.x + 21.0f;
    right = position.x + 127.0f;
    top = position.y + 49.0f;
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x16, drawAlpha,
                             left, top, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x19, drawAlpha,
                             right, top, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x16, drawAlpha,
                             left, top, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x19, drawAlpha,
                             right, top, 100.0f);

    count = (s16)FUN_00177280(FUN_0016c6f0(parent));
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, count - 1, drawAlpha,
                             position.x + 129.0f, position.y + 72.0f,
                             100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1c, drawAlpha,
                             right, position.y + 63.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1d, drawAlpha,
                             left, position.y + 97.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x17, drawAlpha,
                             left, position.y + 97.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1a, drawAlpha,
                             right, position.y + 97.0f, 100.0f);

    count = (s16)FUN_001772F0(FUN_0016c740(parent));
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, count + 6, drawAlpha,
                             position.x + 129.0f, position.y + 120.0f,
                             100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1c, drawAlpha,
                             right, position.y + 111.0f, 100.0f);
    campStatusDrawSpriteCall(
        drawParent, DAT_00833B94, 0x1d, drawAlpha,
        position.x + 128.0f + (f32)((count - 1) * 20),
        position.y + 111.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x18, drawAlpha,
                             left, position.y + 147.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1b, drawAlpha,
                             right, position.y + 147.0f, 100.0f);

    count = (s16)FUN_00177360(FUN_0016c790(parent));
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, count + 13, drawAlpha,
                             position.x + 129.0f, position.y + 170.0f,
                             100.0f);
    campStatusDrawSpriteCall(drawParent, DAT_00833B94, 0x1c, drawAlpha,
                             right, position.y + 161.0f, 100.0f);
    campStatusDrawSpriteCall(
        drawParent, DAT_00833B94, 0x1d, drawAlpha,
        position.x + 128.0f + (f32)((count - 1) * 20),
        position.y + 161.0f, 100.0f);

    bottomPosition = position;
    footerAlpha = (s16)alpha;
    inverseAlpha = 0xff - footerAlpha;
    campStatusDrawSpriteCall(drawParent, *(void**)DAT_00833B90_abs, 0x11,
                             (u8)footerAlpha,
                             bottomPosition.x + 51.0f,
                             bottomPosition.y + 339.0f, 100.0f);
    campStatusDrawSpriteCall(drawParent, *(void**)DAT_00833B90_abs, 0x22,
                             (u8)footerAlpha,
                             bottomPosition.x + 305.0f,
                             bottomPosition.y + 339.0f, 100.0f);
    FUN_00523ac8(text, gp0xffff8980, FUN_0016d2f0(parent));
    campStatusDrawFooterText(100.0f,
                             (s32)(bottomPosition.x + 305.0f),
                             (s32)(bottomPosition.x + 341.0f),
                             (u8)inverseAlpha, 4, text, 1);
}

#pragma opt_loop_invariants reset
// FUN_00127A40
void h_campStatusDestroyPartsTask(KwlnTask* task)
{
    CampStatusPartsWork* work;

    work = (CampStatusPartsWork*)task->workData;
    if (work->ownedResource != NULL) {
        H_Cdvd_Destroy(work->ownedResource);
        work->ownedResource = NULL;
    }
    if (work->parsedResource != NULL) {
        FUN_004d0f00(work->parsedResource);
        work->parsedResource = NULL;
    }
    RwFree(work);
}

// FUN_00127AB0
void h_campStatusBeginClose(KwlnTask* task)
{
    CampStatusPartsWork* work;

    work = (CampStatusPartsWork*)task->workData;
    work->state = 5;
}

// FUN_00127AD0
void h_campStatusBeginFade(KwlnTask* task)
{
    CampStatusPartsWork* work;

    work = (CampStatusPartsWork*)task->workData;
    work->state = 7;
}

// FUN_00127AF0
s32 h_campStatusGetResult(KwlnTask* task)
{
    CampStatusPartsWork* work;

    work = (CampStatusPartsWork*)task->workData;
    return work->result;
}

// FUN_00127B00
KwlnTask* h_campStatusCreatePartsTask(KwlnTask* parent, u32 priority,
                                      CampVec2 position, s16 mode,
                                      s16 screen)
{
    CampStatusPartsWork* work;
    KwlnTask* task;

    work = (CampStatusPartsWork*)RwCalloc(1, sizeof(CampStatusPartsWork),
                                           0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampPcStatusParts", priority,
                          h_campStatusUpdatePartsTask,
                          h_campStatusDestroyPartsTask, work);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((u8*)work + 4) = position;
    work->reserved20[0] = 1;
    work->mode = mode;
    work->screen = screen;
    *((s32*)DAT_007cdf50->workData + 4) = 0;
    return task;
}

void h_campStatusRenderMode(CampVec2 position, f32 scale, void* persona,
                            s32 mode, s32 frame, s32 alpha);
// FUN_00127C00 NONMATCHING
void* h_campStatusUpdatePanelTask(KwlnTask* task)
{
    CampStatusPanelWork* work;
    CampVec2 position;

    work = (CampStatusPanelWork*)task->workData;
    position.x = 0.0f;
    position.y = 0.0f;
    switch (work->state) {
    case 0:
        if (FUN_0011e380(DAT_007cdf50, 3) != 0) {
            work->child = (KwlnTask*)FUN_001339a0(0x42c80000, task, 0x18bf,
                                                  FUN_0016c860(1), -1);
            work->state = 1;
        }
        break;
    case 1:
        if (*((s32*)((u8*)DAT_007cdf50->workData + 0x10)) != 0) {
            work->animationFrame = 0;
            FUN_00121de0(DAT_007cdf54, 3);
            FUN_00122710(DAT_007cdf58, 3);
            work->state = 2;
        }
        break;
    case 2:
        if (work->child != NULL) {
            FUN_00133a80(work->child);
        }
        if (work->panelMode == 0) {
            if (work->animationFrame < 0x14) {
                work->animationFrame++;
            }
            if (work->animationFrame != 0) {
                h_campStatusRenderMode(position, 100.0f,
                                       (void*)FUN_00174800(1), 0,
                                       work->animationFrame, 0);
            }
            if (work->animationFrame >= 0x14) {
                if ((DAT_007e094e & 0x20) != 0) {
                    FUN_0010a4e0(0, 0, 0, 2);
                    work->result = -1;
                }
                else if ((DAT_007e094e & 0x8000) != 0 ||
                         (DAT_007e0958 & 0x8000) != 0) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    work->result = 1;
                }
            }
        }
        else {
            if (work->alpha == 0xff) {
                work->alpha = 0;
            }
            else {
                work->alpha += 10;
                if (work->alpha > 0xff) {
                    work->alpha = 0xff;
                }
            }
            h_campStatusRenderMode(position, 100.0f,
                                   (void*)FUN_00174800(1), 2, 0,
                                   0xff - work->alpha);
        }
        break;
    case 3:
        work->alpha -= 25;
        if (work->alpha < 0) {
            return KWLNTASK_STOP;
        }
        h_campStatusRenderMode(position, 100.0f,
                               (void*)FUN_00174800(1), 2, 0,
                               0xff - work->alpha);
        break;
    case 4:
        h_campStatusRenderMode(position, 100.0f,
                               (void*)FUN_00174800(1), 2, 0, 0);
        if (*((s32*)((u8*)DAT_007cdf50->workData + 0x10)) != 0) {
            work->animationFrame = 0;
            work->state = 5;
        }
        break;
    case 5:
        work->animationFrame++;
        if (work->animationFrame >= 10) {
            return KWLNTASK_STOP;
        }
        h_campStatusRenderMode(position, 100.0f,
                               (void*)FUN_00174800(1), 1,
                               work->animationFrame, 0);
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00127FC0
void h_campStatusDestroyPanelTask(KwlnTask* task)
{
    CampStatusPanelWork* work;

    work = (CampStatusPanelWork*)task->workData;
    RwFree(task->workData);
}

// FUN_00127FF0
void h_campStatusBeginPanelClose(KwlnTask* task)
{
    CampStatusPanelWork* work;

    work = (CampStatusPanelWork*)task->workData;
    work->alpha = 0xff;
    work->state = 3;
}

// FUN_00128010
void h_campStatusBeginPanelFade(KwlnTask* task)
{
    CampStatusPanelWork* work;

    work = (CampStatusPanelWork*)task->workData;
    work->animationFrame = 0;
    work->state = 4;
}

// FUN_00128030
s32 h_campStatusGetPanelMode(KwlnTask* task)
{
    CampStatusPanelWork* work;

    work = (CampStatusPanelWork*)task->workData;
    return work->result;
}

// FUN_00128040
KwlnTask* h_campStatusCreatePanelTask(KwlnTask* parent, u32 priority,
                                      CampVec2 position, s16 mode,
                                      s16 panelMode)
{
    CampStatusPanelWork* work;
    KwlnTask* task;

    work = (CampStatusPanelWork*)RwCalloc(1, sizeof(CampStatusPanelWork),
                                           0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampStatusParts", priority,
                          h_campStatusUpdatePanelTask,
                          h_campStatusDestroyPanelTask, work);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((u8*)work + 4) = position;
    work->ready = 1;
    work->priorityMode = mode;
    *((s32*)DAT_007cdf50->workData + 4) = 0;
    work->panelMode = panelMode;
    return task;
}

void h_campStatusDrawTransition(CampVec2 position, f32 scale,
                                void* persona, s32 frame);
void h_campStatusDrawEntering(CampVec2 position, f32 scale,
                              void* persona, s32 frame);
void h_campStatusDrawSteady(CampVec2 position, f32 scale,
                            void* persona, s32 alpha);
// FUN_00128140
void h_campStatusRenderMode(CampVec2 position, f32 scale, void* persona,
                            s32 mode, s32 frame, s32 alpha)
{
    switch (mode) {
    case 0:
        h_campStatusDrawTransition(position, scale, persona, frame);
        break;
    case 1:
        h_campStatusDrawEntering(position, scale, persona, frame);
        break;
    case 2:
        h_campStatusDrawSteady(position, scale, persona, alpha);
        break;
    case 3:
        FUN_0012b300_s32(position, scale, persona, alpha);
        break;
    }
}

// FUN_001281E0
void h_campStatusRenderStatIcon(CampVec2 position, f32 scale,
                                s32 stat, s32 alpha)
{
    u32 parent;

    switch (stat) {
    case 0:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 0,
                                   position.x + 29.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 1:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 1,
                                   position.x + 69.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 2:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 2,
                                   position.x + 109.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 3:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 3,
                                   position.x + 159.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 4:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 4,
                                   position.x + 199.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 5:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 5,
                                   position.x + 239.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 6:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 6,
                                   position.x + 279.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 7:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 7,
                                   position.x + 319.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    case 8:
        campStatusDrawSpriteCallXY(parent, *(void**)DAT_00833B98_abs, 8,
                                   position.x + 359.0f, position.y + 44.0f,
                                   (u8)alpha, scale);
        break;
    }
}


// FUN_00128720 NONMATCHING
void h_campStatusDrawStatValues(CampVec2 position, f32 scale, void* bonus,
                                void* persona, s32 alpha)
{
    u32 parent;
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 0, 0);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 1, 0);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 2, 0);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 3, 0);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 4, 0);
}

// FUN_00128480
void h_campStatusDrawStatLabels(CampVec2 position, f32 scale, void* persona,
                                s32 alpha)
{
    u32 parent;
    u32 i;
    s32 value;
    s32 frame;
    f32 x;
    f32 y;

    x = position.x + 32.0f;
    y = position.y + 72.0f;
    for (i = 0; i < 9; i++) {
        switch (i) {
        case 0:
            value = FUN_00173660(persona, 0);
            break;
        case 1:
            value = FUN_00173660(persona, 1);
            break;
        case 2:
            value = FUN_00173660(persona, 2);
            break;
        case 3:
            value = FUN_00173660(persona, 3);
            break;
        case 4:
            value = FUN_00173660(persona, 4);
            break;
        case 5:
            value = FUN_00173660(persona, 5);
            break;
        case 6:
            value = FUN_00173660(persona, 6);
            break;
        case 7:
            value = FUN_00173660(persona, 8);
            break;
        case 8:
            value = FUN_00173660(persona, 9);
            break;
        }
        frame = 15;
        if ((value & 0x4000000) != 0) {
            frame = 13;
        }
        else if ((value & 0x2000000) != 0) {
            frame = 14;
        }
        else if ((value & 0x1000000) != 0) {
            frame = 12;
        }
        else if ((value & 0x10000000) != 0) {
            frame = 11;
        }
        else if ((value & 0x8000000) != 0) {
            frame = 10;
        }
        campStatusDrawSpriteCall(parent, *(void**)DAT_00833B98_abs, frame, (u8)alpha,
                                 x, y, scale);
        if (i == 2) {
            x = 162.0f;
        }
        else {
            x += 40.0f;
        }
    }
}
// FUN_00128C40 NONMATCHING
void h_campStatusDrawSkillValues(CampVec2 position, f32 scale, void* bonus,
                                 void* persona, s32 alpha)
{
    u32 parent;
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 0, 1);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 1, 1);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 2, 1);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 3, 1);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 4, 1);
}

// FUN_00129160 NONMATCHING
void h_campStatusDrawRankValue(CampVec2 position, f32 scale, s32 row,
                               s32 value, s32 extra, s32 alpha)
{
    CampStatusSprite* sprite;
    s32 length;

    (void)scale;
    campStatusDrawSprite3Call(position.x + 104.0f,
                              position.y + 129.0f + (f32)(row * 19) - 25.0f,
                              0x42c80000);
    campStatusDrawSprite3Call(position.x + 333.0f,
                              position.y + 129.0f + (f32)(row * 19) - 25.0f,
                              0x42c80000);
    length = (value * 0xe3) / 99;
    sprite = (CampStatusSprite*)FUN_001158b0(0, DAT_00833B98, 0x18);
    sprite->scale = 100.0f;
    sprite->x = position.x + 108.0f;
    sprite->y = position.y + 130.0f + (f32)(row * 19) - 25.0f;
    sprite->alpha = (u8)alpha;
    sprite->value = (s16)length;
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
    if (extra != 0) {
        sprite = (CampStatusSprite*)FUN_001158b0(0, DAT_00833B98, 0x10);
        sprite->scale = 100.0f;
        sprite->x = position.x + 108.0f + (f32)length + 2.0f;
        sprite->y = position.y + 130.0f + (f32)(row * 19) - 25.0f;
        sprite->alpha = (u8)alpha;
        sprite->value = (s16)((extra * 0xe3) / 99);
        FUN_001127d0(sprite, 1);
        FUN_00115980(sprite);
    }
}

#pragma opt_common_subs off
// FUN_001293B0 NONMATCHING
#pragma push
void h_campStatusDrawEquipment(CampVec2 position, f32 scale,
                               void* bonus, void* persona, s32 alpha)
{
    u32 parent;
    u16* bonusPtr;
    u16 equipped[8];
    char text[44];
    s32 i;
    s32 row;
    s32 col;
    s32 item;
    s32 count;
    u32 disabledColor;
    u32 enabledColor;
    f32 slotX;
    f32 slotY;
    f32 textX;
    f32 textY;
    f32 bonusX;
    f32 bonusY;
    f32 rankX;
    f32 rankY;
    f32 rankCountX;
    f32 rankCountY;
    f32 equippedX;
    f32 equippedY;
    f32 equippedTextX;
    f32 equippedTextY;
    f32 separatorX;
    f32 separatorY;

    parent = 0x42c80000;
    bonusPtr = (bonus != NULL) ? (u16*)((u8*)bonus + 0x3e) : NULL;
    disabledColor = (0xff - (u32)alpha) | 0x95b9ff00;
    enabledColor = (0xff - (u32)alpha) | 0x77ffcf00;
    slotX = position.x + 34.0f;
    slotY = position.y + 316.0f;
    textX = position.x + 44.0f;
    textY = position.y + 323.0f;
    bonusX = position.x + 39.0f;
    bonusY = position.y + 332.0f;
    rankX = position.x + 411.0f;
    rankY = position.y + 326.0f;
    rankCountX = position.x + 534.0f;
    rankCountY = position.y + 328.0f;
    equippedX = position.x + 414.0f;
    equippedY = position.y + 340.0f;
    equippedTextX = position.x + 414.0f;
    equippedTextY = position.y + 347.0f;
    separatorX = position.x + 414.0f;
    separatorY = position.y + 366.0f;

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 4; col++) {
            i = row * 4 + col;
            campStatusDrawSpriteCall(parent, DAT_00833B90, 0x12, (u8)alpha,
                                     slotX + (f32)(row * 190),
                                     slotY + (f32)(col * 24), scale);
            item = *((u16*)persona + 6 + i);
            if (item == 0) {
                continue;
            }
            if (bonusPtr == NULL || *(s16*)((u8*)bonusPtr + i * 2) != 0) {
                campStatusDrawSpriteCall(parent, DAT_00833B90, 0x19,
                                         (u8)alpha,
                                         bonusX + (f32)(row * 190),
                                         bonusY + (f32)(col * 24), scale);
                FUN_00523ac8(text, gp0xffff897c,
                             iGpffffb7fc + item * 0x13);
                FUN_003b32d0_typed(scale, (s32)textX + row * 190,
                             (s32)textY + col * 24,
                             enabledColor, 6, 1, text, 0x10, 0x78);
            }
            else {
                FUN_00523ac8(text, gp0xffff897c,
                             iGpffffb7fc + item * 0x13);
                FUN_003b32d0_typed(scale, (s32)textX + row * 190,
                             (s32)textY + col * 24,
                             disabledColor, 6, 1, text, 0x10, 0x78);
            }
        }
    }
    if (FUN_001fc230(persona) != 0) {
        campStatusDrawSpriteCall(parent, DAT_00833B90, 0x15, (u8)alpha,
                                 rankX, rankY, scale);
        campStatusDrawSpriteCall(parent, DAT_00833B90, 0x17, (u8)alpha,
                                 rankX + 146.0f, rankY, scale);
        count = FUN_001fc3c0(persona);
        if (count >= 10) {
            campStatusDrawSpriteCall(parent, (void*)H_Maestro_001120a0(2),
                                     count / 10 + 0xb, (u8)alpha,
                                     rankCountX - 8.0f, rankCountY, scale);
            campStatusDrawSpriteCall(parent, (void*)H_Maestro_001120a0(2),
                                     count % 10 + 0xb, (u8)alpha,
                                     rankCountX + 7.0f, rankCountY, scale);
        }
        else {
            campStatusDrawSpriteCall(parent, (void*)H_Maestro_001120a0(2),
                                     count % 10 + 0xb, (u8)alpha,
                                     rankCountX, rankCountY, scale);
        }
    }
    count = 0;
    FUN_001fb1f0(persona, equipped, &count);
    if (count > 7) {
        count = 7;
    }
    for (i = 0; i < count; i++) {
        if (equipped[i] != 0) {
            if (i == 0) {
                campStatusDrawSpriteCall(parent, DAT_00833B90, 0x13, (u8)alpha,
                                         equippedX, equippedY, scale);
            }
            FUN_00523ac8(text, gp0xffff897c,
                         iGpffffb7fc + equipped[i] * 0x13);
            FUN_003b32d0_typed(scale, (s32)equippedTextX,
                         (s32)equippedTextY, disabledColor, 6, 1, text,
                         0x10, 0x78);
        }
    }
    for (i = 0; i < count - 1; i++) {
        campStatusDrawSpriteCall(parent, DAT_00833B90, 0x14, (u8)alpha,
                                 separatorX + (f32)((i / 2) * 62),
                                 separatorY + (f32)((i & 1) * 24), scale);
    }
}

static void h_campStatusDrawBody(u32 parent, CampVec2 position, void* persona,
                                 void* bonus, s32 alpha)
{
    s32 i;
    s32 value;
    s32 x;
    s32 y;
    char text[264];
    void* glyph;
    CampVec2 labelPos;

    h_campStatusDrawStatLabels(position, 0.0f, persona, alpha);
    h_campStatusDrawStatValues(position, 0.0f, bonus, persona, alpha);
    h_campStatusDrawEquipmentSlots(parent, position, persona, bonus, alpha);
    labelPos.x = position.x + 12.0f;
    labelPos.y = position.y + 96.0f;
    FUN_001159f0(labelPos.x + 21.0f, labelPos.y + 182.0f, parent);
    FUN_001159f0(labelPos.x + 296.0f, labelPos.y + 182.0f, parent);
    if (*((char*)persona + 4) != 'c') {
        value = FUN_00173340(persona) - FUN_00173330(persona);
        FUN_00523ac8(text, gp0xffff8978, value);
    }
    else {
        FUN_00523ac8(text, gp0xffff8980);
    }
    FUN_0040eb50(parent, (s32)(labelPos.x + 275.0f),
                 (s32)(labelPos.y + 184.0f), 0xff - alpha, 4, text, 1);
    glyph = (void*)FUN_001158b0(0, DAT_00833B98, 0x18);
    *((u32*)glyph + 11) = parent;
    *((f32*)glyph + 4) = position.x + 108.0f;
    *((f32*)glyph + 5) = position.y + 130.0f;
    *((u8*)glyph + 0x18) = (u8)alpha;
    value = FUN_00173660(persona, 0) & 0xff;
    *((s16*)glyph + 0x0e) = (s16)((value * 0xe3) / 99);
    FUN_001127d0(glyph, 1);
    FUN_00115980(glyph);
    for (i = 0; i < 5; i++) {
        x = (s32)position.x + 104;
        y = (s32)position.y + 129 + i * 19 - 25;
        FUN_001159f0((f32)x, (f32)y, parent);
    }
}

#pragma pop
#pragma opt_common_subs reset
// FUN_00129B30 NONMATCHING
void h_campStatusDrawTransition(CampVec2 position, f32 scale,
                                void* persona, s32 frame)
{
    f32 drawX;
    f32 drawY;
    u32 i;
    u32 row;
    s32 alpha;
    s32 fade;
    s32 rank;
    void* glyph;
    CampVec2 bottomPos;
    CampVec2 drawPos;
    char text[0x100];
    bottomPos = position;
    bottomPos.x += 12.0f;
    bottomPos.y += 96.0f;

    if (frame >= 0) {
    if (frame < 5) {
        drawX = position.x + 300.0f -
                ((f32)frame * 300.0f / 5.0f);
        alpha = 0xff - (frame * 0xff) / 5;
    }
    else {
        drawX = position.x;
        alpha = 0;
    }
    drawY = position.y;
    }
    if (frame >= 15) {
        fade = frame - 15;
        if (fade >= 5) {
            alpha = 0;
        }
        else {
            alpha = 0xff - (fade * 0xff) / 5;
        }
    }
    for (i = 0; i < 9; i++) {
        if ((u32)frame >= i) {
            fade = frame - i;
            if (fade < 10) {
                drawX = position.x + 500.0f -
                        (f32)((fade * 500) / 10);
                alpha = 0xff - (fade * 0xff) / 10;
            }
            else {
                alpha = 0;
            }
            drawY = position.y;
            drawPos.x = drawX;
            drawPos.y = drawY;
            h_campStatusRenderStatIcon(drawPos, scale, i, alpha);
        }
    }
    if (frame >= 3) {
        fade = frame - 3;
        if (fade < 5) {
            alpha = 0xff - (fade * 0xff) / 5;
            drawX = position.x + 100.0f -
                    (f32)((fade * 100) / 5);
        }
        else {
            alpha = 0;
            drawX = position.x;
        }
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B74, 0,
                                 (u8)alpha, 34.0f, 415.0f, 100.0f);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B74, 10,
                                 (u8)alpha, 50.0f, 415.0f, 100.0f);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B74, 11,
                                 (u8)alpha, 212.0f, 415.0f, 100.0f);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833BA0, 1,
                                 (u8)alpha, 561.0f, 415.0f, 100.0f);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833BA0, 5,
                                 (u8)alpha, 361.0f, 415.0f, 100.0f);
        drawPos.x = drawX;
        drawPos.y = position.y;
        h_campStatusDrawStatLabels(drawPos, scale, persona, alpha);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x12,
                                 (u8)alpha, drawX + 30.0f,
                                 (125.0f + position.y) - 25.0f, scale);
        campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x13,
                                 (u8)alpha, drawX + 30.0f,
                                 (184.0f + position.y) - 25.0f, scale);
        drawPos.x = drawX;
        drawPos.y = position.y;
        h_campStatusDrawStatValues(drawPos, scale, NULL, persona, (u8)alpha);
    }
    if (frame >= 5) {
        fade = frame - 5;
        if (fade < 3) {
            alpha = 0xff - (fade * 0xff) / 3;
        }
        else {
            alpha = 0;
        }
        h_campStatusDrawEquipment(position, scale, NULL, persona, alpha);
    }
    for (row = 0; row < 5; row++) {
        if (frame >= 3) {
            fade = frame - 3;
            switch (row) {
            case 0:
                rank = FUN_00173660(persona, 0) & 0xff;
                break;
            case 1:
                rank = FUN_00173660(persona, 1) & 0xff;
                break;
            case 2:
                rank = FUN_00173660(persona, 2) & 0xff;
                break;
            case 3:
                rank = FUN_00173660(persona, 3) & 0xff;
                break;
            case 4:
                rank = FUN_00173660(persona, 4) & 0xff;
                break;
            }
            if (fade < 5) {
                alpha = 0xff - (fade * 0xff) / 5;
                drawX = position.x + 300.0f -
                        (f32)((fade * 300) / 5);
                rank = (rank * fade) / 5;
            }
            else {
                alpha = 0;
                drawX = position.x;
            }
            drawY = position.y + 129.0f + (f32)(row * 19) - 25.0f;
            campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x14,
                                     (u8)alpha, drawX + 104.0f, drawY,
                                     scale);
            campStatusDrawSpriteCall(0x42c80000, DAT_00833B98, 0x15,
                                     (u8)alpha, drawX + 333.0f, drawY,
                                     scale);
            glyph = (void*)FUN_001158b0(0, DAT_00833B98, 0x18);
            *((f32*)glyph + 11) = scale;
            *((f32*)glyph + 4) = drawX + 108.0f;
            *((f32*)glyph + 5) = drawY + 1.0f;
            *((u8*)glyph + 0x18) = (u8)alpha;
            *((s16*)glyph + 0x0e) = (s16)((rank * 0xe3) / 99);
            FUN_001127d0(glyph, 1);
            FUN_00115980(glyph);
        }
    }
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B90, 0x11,
                             (u8)alpha, bottomPos.x + 21.0f,
                             bottomPos.y + 86.0f, scale);
    campStatusDrawSpriteCall(0x42c80000, DAT_00833B90, 0x22,
                             (u8)alpha, bottomPos.x + 275.0f,
                             bottomPos.y + 86.0f, scale);
    bottomPos.y += 88.0f;
    if (*((u8*)persona + 4) == 0x63) {
        FUN_00523ac8(text, gp0xffff8980);
    }
    else {
        rank = FUN_00173340(persona) - FUN_00173330(persona);
        FUN_00523ac8(text, gp0xffff8978, rank);
    }
    FUN_0040eb50(0x42c80000, (s32)bottomPos.x + 275,
                 (s32)bottomPos.y, 0xff - alpha,
                 4, text, 1);
}

// FUN_0012A560 NONMATCHING
void h_campStatusDrawEntering(CampVec2 position, f32 scale,
                              void* persona, s32 frame)
{
    u32 parentTop = 0x42c80000;
    u32 parentBottom = 0x42c80000;
    s32 alpha;
    s32 icon;
    s32 row;
    s32 value;
    s32 length;
    char text[0x100];
    void* glyph;
    CampVec2 drawPosition;
    CampVec2 labelPosition;
    CampVec2 valuePosition;
    CampVec2 equipmentPosition;
    f32 panelX;
    f32 panelY;
    f32 panelBottomY;
    f32 rowLeftX;
    f32 rowRightX;
    f32 rowY;
    f32 glyphX;
    f32 glyphY;
    f32 footerX;
    f32 footerY;
    if (frame >= 5) {
        return;
    }
    position.x += (f32)((frame * 300) / 5);
    drawPosition = position;
    panelX = drawPosition.x + 30.0f;
    panelY = drawPosition.y + 100.0f;
    panelBottomY = drawPosition.y + 159.0f;
    footerX = drawPosition.x + 287.0f;
    footerY = drawPosition.y + 280.0f;
    alpha = (frame * 0xff) / 5;
    for (icon = 0; icon < 9; icon++) {
        h_campStatusRenderStatIcon(drawPosition, scale, icon, alpha);
    }
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 0, alpha,
                             34.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 10, alpha,
                             50.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 11, alpha,
                             212.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833BA0, 1, alpha,
                             561.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833BA0, 5, alpha,
                             361.0f, 415.0f, 100.0f);
    labelPosition = drawPosition;
    h_campStatusDrawStatLabels(labelPosition, scale, persona, alpha);
    campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x12, alpha,
                             panelX, panelY, scale);
    campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x13, alpha,
                             panelX, panelBottomY, scale);
    valuePosition = drawPosition;
    h_campStatusDrawStatValues(valuePosition, scale, NULL, persona, alpha);
    for (row = 0; row < 5; row++) {
        switch (row) {
        case 0:
            value = FUN_00173660(persona, 0) & 0xff;
            break;
        case 1:
            value = FUN_00173660(persona, 1) & 0xff;
            break;
        case 2:
            value = FUN_00173660(persona, 2) & 0xff;
            break;
        case 3:
            value = FUN_00173660(persona, 3) & 0xff;
            break;
        case 4:
            value = FUN_00173660(persona, 4) & 0xff;
            break;
        }
        rowLeftX = valuePosition.x + 104.0f;
        rowRightX = valuePosition.x + 333.0f;
        rowY = valuePosition.y + 129.0f + (f32)(row * 19) - 25.0f;
        campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x14, alpha,
                                 rowLeftX, rowY, scale);
        campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x15, alpha,
                                 rowRightX, rowY, scale);
        glyph = (void*)FUN_001158b0(0, DAT_00833B98, 0x18);
        *((f32*)glyph + 11) = scale;
        glyphX = drawPosition.x + 108.0f;
        glyphY = rowY + 1.0f;
        *((f32*)glyph + 4) = glyphX;
        *((f32*)glyph + 5) = glyphY;
        *((u8*)glyph + 0x18) = (u8)alpha;
        length = (value * 0xe3) / 99;
        *((s16*)glyph + 0x0e) = (s16)length;
        FUN_001127d0(glyph, 1);
        FUN_00115980(glyph);
    }
    equipmentPosition = drawPosition;
    h_campStatusDrawEquipment(equipmentPosition, scale, NULL, persona, alpha);
    campStatusDrawSpriteCall(parentBottom, DAT_00833B90, 0x11, alpha,
                             drawPosition.x + 33.0f,
                             drawPosition.y + 278.0f, scale);
    campStatusDrawSpriteCall(parentBottom, DAT_00833B90, 0x22, alpha,
                             drawPosition.x + 287.0f,
                             drawPosition.y + 278.0f, scale);
    if (*((u8*)persona + 4) == 0x63) {
        FUN_00523ac8(text, gp0xffff8980);
    }
    else {
        value = FUN_00173340(persona) - FUN_00173330(persona);
        FUN_00523ac8(text, gp0xffff8978, value);
    }
    FUN_0040eb50(parentBottom, (s32)footerX, (s32)footerY,
                 0xff - alpha, 4, text, 1);
}
// FUN_0012AC60 NONMATCHING
void h_campStatusDrawSteady(CampVec2 position, f32 scale,
                            void* persona, s32 alpha)
{
    u32 parentTop = 0x42c80000;
    u32 parentBottom = 0x42c80000;
    s32 icon;
    s32 row;
    s32 value;
    s32 length;
    s32 rowOffset;
    f32 rowBaseY;
    f32 rowY;
    f32 rowLeftX;
    f32 rowRightX;
    f32 glyphX;
    f32 glyphY;
    CampVec2 drawPosition;
    CampVec2 labelsPosition;
    CampVec2 valuesPosition;
    CampVec2 equipmentPosition;
    CampVec2 panelPosition;
    CampVec2 footerPosition;
    char text[0x100];
    void* glyph;

    drawPosition = position;
    labelsPosition = drawPosition;
    valuesPosition = drawPosition;
    equipmentPosition = drawPosition;
    panelPosition = labelsPosition;
    panelPosition.x += 30.0f;
    panelPosition.y += 100.0f;
    footerPosition = equipmentPosition;
    footerPosition.x += 287.0f;
    footerPosition.y += 280.0f;
    for (icon = 0; icon < 9; icon++) {
        h_campStatusRenderStatIcon(drawPosition, scale, icon, alpha);
    }
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 0, (u8)alpha,
                             34.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 10, (u8)alpha,
                             50.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833B74, 11, (u8)alpha,
                             212.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833BA0, 1, (u8)alpha,
                             561.0f, 415.0f, 100.0f);
    campStatusDrawSpriteCall(parentTop, DAT_00833BA0, 5, (u8)alpha,
                             361.0f, 415.0f, 100.0f);
    h_campStatusDrawStatLabels(labelsPosition, scale, persona, alpha);
    campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x12, (u8)alpha,
                             panelPosition.x, panelPosition.y, scale);
    panelPosition.y += 59.0f;
    campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x13, (u8)alpha,
                             panelPosition.x, panelPosition.y, scale);
    h_campStatusDrawStatValues(valuesPosition, scale, NULL, persona, alpha);
    for (row = 0; row < 5; row++) {
        rowOffset = row * 19;
        rowBaseY = valuesPosition.y + 129.0f + (f32)rowOffset;
        rowY = rowBaseY - 25.0f;
        rowLeftX = valuesPosition.x + 104.0f;
        rowRightX = valuesPosition.x + 333.0f;
        glyphX = valuesPosition.x + 108.0f;
        glyphY = rowY + 1.0f;
        switch (row) {
        case 0:
            value = FUN_00173660(persona, 0) & 0xff;
            break;
        case 1:
            value = FUN_00173660(persona, 1) & 0xff;
            break;
        case 2:
            value = FUN_00173660(persona, 2) & 0xff;
            break;
        case 3:
            value = FUN_00173660(persona, 3) & 0xff;
            break;
        case 4:
            value = FUN_00173660(persona, 4) & 0xff;
            break;
        }
        campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x14, (u8)alpha,
                                 rowLeftX, rowY, scale);
        campStatusDrawSpriteCall(parentTop, DAT_00833B98, 0x15, (u8)alpha,
                                 rowRightX, rowY, scale);
        glyph = (void*)FUN_001158b0(0, DAT_00833B98, 0x18);
        *((f32*)glyph + 11) = scale;
        *((f32*)glyph + 4) = glyphX;
        *((f32*)glyph + 5) = glyphY;
        *((u8*)glyph + 0x18) = (u8)alpha;
        length = (value * 0xe3) / 99;
        *((s16*)glyph + 0x0e) = (s16)length;
        FUN_001127d0(glyph, 1);
        FUN_00115980(glyph);
    }
    h_campStatusDrawEquipment(equipmentPosition, scale, NULL, persona, alpha);
    campStatusDrawSpriteCall(parentBottom, DAT_00833B90, 0x11, (u8)alpha,
                             drawPosition.x + 33.0f,
                             drawPosition.y + 278.0f, scale);
    campStatusDrawSpriteCall(parentBottom, DAT_00833B90, 0x22, (u8)alpha,
                             footerPosition.x, drawPosition.y + 278.0f,
                             scale);
    if (*((u8*)persona + 4) == 0x63) {
        FUN_00523ac8(text, gp0xffff8980);
    }
    else {
        value = FUN_00173340(persona) - FUN_00173330(persona);
        FUN_00523ac8(text, gp0xffff8978, value);
    }
    FUN_0040eb50(parentBottom, (s32)footerPosition.x,
                 (s32)footerPosition.y, 0xff - alpha, 4, text, 1);
}
/*
 * Persona status draw task.
 *
 * The retail callback owns the asynchronous archive used by the status
 * carousel and keeps the selected hero-persona list in the task work area.
 * The state values below mirror the observed loading, draw, transition, and
 * close phases; offsets are kept explicit because the task is shared with
 * the destroy/create callbacks above.
 */
typedef union CampStatusPackedPosition
{
    struct
    {
        f32 x;
        f32 y;
    } coordinates;
    u64 value;
} CampStatusPackedPosition;
#pragma alias campStatusDrawStatsPacked FUN_0012b860
extern void campStatusDrawStatsPacked(CampStatusPackedPosition position,
                                      f32 scale, void* currentStats,
                                      void* persona, s32 alpha);
#pragma alias campStatusDrawSkillsPacked FUN_0012bce0
extern void campStatusDrawSkillsPacked(CampStatusPackedPosition position,
                                       f32 scale, void* unused,
                                       void* persona, s32 alpha);
#pragma alias campStatusDrawRanksPacked FUN_0012bfb0
extern void campStatusDrawRanksPacked(CampStatusPackedPosition position,
                                      f32 scale, void* currentStats,
                                      void* persona, s32 alpha);
#pragma alias campStatusDrawPersonaTopPacked FUN_00124e60
extern void campStatusDrawPersonaTopPacked(CampStatusPackedPosition position,
                                           f32 alpha, void* persona, s32 fade);
#pragma alias campStatusDrawPersonaBottomPacked FUN_00124fd0
extern void campStatusDrawPersonaBottomPacked(
    CampStatusPackedPosition position, f32 alpha, void* persona, s32 fade);

typedef s32 (*CampStatusSpriteDrawFn)(void* parent, void* resource,
                                      s32 frame, u32 alpha, f32 x, f32 y,
                                      f32 scale);
typedef KwlnTask* (*CampStatusPersonaChildCreateFn)(KwlnTask* parent,
                                                    u32 priority,
                                                    u32 personaId, u32 mode,
                                                    f32 alpha);

#define campStatusAnimateRecord(records, index, alphaMode, start, end, \
                                startFrame, endFrame) \
    func_0018bc10(100.0f, (u8*)(records) + (index) * 0x44, 0, 2, \
                  (alphaMode), *(u64*)&(start), *(u64*)&(end), \
                  0, 0, (startFrame), (endFrame))

#define campStatusSetListPosition(position, row, selected, alternate) \
    do { \
        (position).x = (alternate) != 0 ? -11.0f : 119.0f; \
        (position).y = (alternate) != 0 ? 63.0f : 73.0f; \
        (position).y += (f32)((row) * 29); \
        if ((selected) != 0) (position).x += 21.0f; \
    } while (0)

static inline CampVec2 campStatusListPosition(s32 row, s32 selected, s32 alternate)
{
    CampVec2 position;

    position.x = alternate != 0 ? -11.0f : 119.0f;
    position.y = alternate != 0 ? 63.0f : 73.0f;
    position.y += (f32)(row * 29);
    if (selected != 0) {
        position.x += 21.0f;
    }
    return position;
}

static inline void campStatusInitializePersonaList(void* records, s32 selected,
                                            s32 count)
{
    CampVec2 zero;
    CampVec2 position;
    CampVec2 start;
    s32 i;

    zero.x = 0.0f;
    zero.y = 0.0f;
    campStatusAnimateRecord(records, 0, 1, zero, zero, 5, 5);
    for (i = 0; i < count; i++) {
        campStatusSetListPosition(position, i, i == selected, 0);
        start = position;
        start.x -= 600.0f;
        campStatusAnimateRecord(records, i + 1, 1, start, position, 0, 10);
        campStatusSetListPosition(position, i, i == selected, 1);
        start = position;
        start.x -= 600.0f;
        campStatusAnimateRecord(records, i + 14, 1, start, position, 0, 6);
    }
    position.x = 497.0f;
    position.y = 26.0f;
    start = position;
    start.x += 600.0f;
    campStatusAnimateRecord(records, 27, 1, start, position, 0, 10);
    position.x = 34.0f;
    position.y = 415.0f;
    start = position;
    start.x += 600.0f;
    campStatusAnimateRecord(records, 28, 1, start, position, 0, 10);
}

static inline void campStatusClosePersonaList(void* records, s32 selected, s32 count)
{
    CampVec2 position;
    s32 i;

    position.x = *((f32*)((u8*)records + 0x38));
    position.y = *((f32*)((u8*)records + 0x3c));
    campStatusAnimateRecord(records, 0, 2, position, position, 5, 5);
    for (i = 0; i < count; i++) {
        campStatusSetListPosition(position, i, i == selected, 0);
        campStatusAnimateRecord(records, i + 1, 2, position, position, 0,
                                10);
        campStatusSetListPosition(position, i, i == selected, 1);
        campStatusAnimateRecord(records, i + 14, 2, position, position, 0,
                                6);
    }
    position.x = 497.0f;
    position.y = 26.0f;
    campStatusAnimateRecord(records, 27, 2, position, position, 0, 10);
    position.x = 34.0f;
    position.y = 415.0f;
    campStatusAnimateRecord(records, 28, 2, position, position, 0, 10);
}

static inline void campStatusAnimateSelection(void* records, s32 oldSelected,
                                       s32 selected)
{
    CampVec2 start;
    CampVec2 end;

    campStatusSetListPosition(start, oldSelected, 1, 0);
    campStatusSetListPosition(end, oldSelected, 0, 0);
    campStatusAnimateRecord(records, oldSelected + 1, 0, start, end, 0, 2);
    campStatusSetListPosition(start, oldSelected, 1, 1);
    campStatusSetListPosition(end, oldSelected, 0, 1);
    campStatusAnimateRecord(records, oldSelected + 14, 0, start, end, 0, 2);
    campStatusSetListPosition(start, selected, 0, 0);
    campStatusSetListPosition(end, selected, 1, 0);
    campStatusAnimateRecord(records, selected + 1, 0, start, end, 0, 2);
    campStatusSetListPosition(start, selected, 0, 1);
    campStatusSetListPosition(end, selected, 1, 1);
    campStatusAnimateRecord(records, selected + 14, 0, start, end, 0, 2);
}

static inline void campStatusInitializeDetail(void* records, s32 alphaMode)
{
    CampVec2 position;

    position.x = 0.0f;
    position.y = 0.0f;
    campStatusAnimateRecord(records, 0, alphaMode, position, position, 0,
                            10);
    position.x = 42.0f;
    position.y = 12.0f;
    campStatusAnimateRecord(records, 2, alphaMode, position, position, 0, 8);
    position.x = 519.0f;
    position.y = 12.0f;
    campStatusAnimateRecord(records, 3, alphaMode, position, position, 0, 8);
    position.x = 170.0f;
    position.y = 8.0f;
    campStatusAnimateRecord(records, 4, alphaMode, position, position, 0, 8);
    position.x = 34.0f;
    position.y = 415.0f;
    campStatusAnimateRecord(records, 5, alphaMode, position, position, 0, 8);
}

static inline void campStatusAnimateDetailSelection(void* records)
{
    CampVec2 zero;

    zero.x = 0.0f;
    zero.y = 0.0f;
    campStatusAnimateRecord(records, 0, 1, zero, zero, 0, 10);
    campStatusAnimateRecord(records, 1, 2, zero, zero, 0, 10);
}

static inline void campStatusUpdatePersonaChild(u8* work, s32 selected)
{
    KwlnTask* child;
    u32 personaId;

    child = *(KwlnTask**)(work + 0x54);
    personaId = *(u16*)(work + 0x1a + selected * 2);
    FUN_00133b80(child, personaId, (u32)-1);
    FUN_00133a80(child);
}

static inline void campStatusDrawMain(u8* work, s32 selected)
{
    u32 result;

    campStatusUpdatePersonaChild(work, selected);
    result = FUN_001344B0(*(void**)(work + 0x64), work + 0x58,
                          work + 0x32, (s16)selected);
    *(u32*)(work + 0x4c) = result;
}
static inline void campStatusDrawMainDiscardResult(u8* work, s32 selected)
{
    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
}

static inline void campStatusDrawDetail(u8* work, s32 selected, s32 previous)
{
    u32 result;

    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
    result = FUN_00134900(*(void**)(work + 0x68), work + 0x58,
                          work + 0x32, (s16)selected, (s16)previous);
    *(u32*)(work + 0x4c) = result;
}

static inline void campStatusDrawDetailDiscardResult(u8* work, s32 selected,
                                              s32 previous)
{
    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
    FUN_00134900(*(void**)(work + 0x68), work + 0x58, work + 0x32,
                 (s16)selected, (s16)previous);
}

static inline void campStatusRebuildPersonaList(u8* work)
{
    DatPersonaWork* persona;
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 12; i++) {
        *(u16*)(work + 0x1a + count * 2) = 0;
        if (datPersonaHeroPersonaValid((s16)i) != 0) {
            persona = datPersonaGetHeroPersona((s16)i);
            printf(D_005DB158, persona->id);
            *(u16*)(work + 0x1a + count * 2) = persona->id;
            *(u16*)(work + 0x32 + count * 2) = (u16)i;
            count++;
        }
    }
    *(s16*)(work + 0x4a) = (s16)count;
    if (*(s32*)(work + 0x4) >= count) {
        *(s32*)(work + 0x4) = count - 1;
    }
}

static inline void campStatusResetPersonaAnimations(void* records)
{
    u8* record;
    s32 i;

    for (i = 0; i < 12; i++) {
        record = (u8*)records + i * 0x44;
        *(u32*)(record + 0x48) = 0;
        *(u32*)(record + 0x3bc) = 0;
    }
}

// FUN_00133180
void FUN_00133180(CampStatusPackedPosition position, f32 alpha, void* unused,
                  void* currentStats, s32 fade)
{
    CampStatusPackedPosition firstSpritePosition;
    CampStatusPackedPosition secondSpritePosition;
    u32 parent;
    void* secondResource;
    s32 drawAlpha;
    s32 arcanaFrame;

    drawAlpha = 0xff - fade;
    campStatusDrawStatsPacked(position, alpha, unused, currentStats, drawAlpha);
    position.coordinates.x += 12.0f;
    position.coordinates.y += 96.0f;
    firstSpritePosition = position;
    campStatusDrawSpritePackedCall(
        firstSpritePosition.coordinates.x + 22.0f,
        firstSpritePosition.coordinates.y + 117.0f, parent,
        *(void**)DAT_00833B90_abs, 1, (u8)drawAlpha, alpha);
    secondSpritePosition = position;
    secondResource = *(void**)DAT_00833B88_abs;
    arcanaFrame =
        (FUN_00173280(*(u16*)((u8*)currentStats + 2)) & 0xff) - 1;
    campStatusDrawSpritePackedCall(
        secondSpritePosition.coordinates.x + 105.0f,
        secondSpritePosition.coordinates.y + 142.0f, parent,
        secondResource, arcanaFrame, (u8)drawAlpha, alpha);
    campStatusDrawPersonaTopPacked(position, alpha, currentStats, drawAlpha);
    campStatusDrawPersonaBottomPacked(position, alpha, currentStats, drawAlpha);
}

// FUN_001332F0
void FUN_001332f0(CampStatusPackedPosition position, f32 alpha, void* unused,
                  void* persona, s32 fade)
{
    CampStatusPackedPosition firstSpritePosition;
    CampStatusPackedPosition secondSpritePosition;
    u32 parent;
    void* secondResource;
    s32 drawAlpha;
    s32 arcanaFrame;

    drawAlpha = 0xff - fade;
    campStatusDrawSkillsPacked(position, alpha, unused, persona, drawAlpha);
    position.coordinates.x += 12.0f;
    position.coordinates.y += 96.0f;
    firstSpritePosition = position;
    campStatusDrawSpritePackedCall(
        firstSpritePosition.coordinates.x + 22.0f,
        firstSpritePosition.coordinates.y + 117.0f, parent,
        *(void**)DAT_00833B90_abs, 1, (u8)drawAlpha, alpha);
    secondSpritePosition = position;
    secondResource = *(void**)DAT_00833B88_abs;
    arcanaFrame =
        (FUN_00173280(*(u16*)((u8*)persona + 2)) & 0xff) - 1;
    campStatusDrawSpritePackedCall(
        secondSpritePosition.coordinates.x + 105.0f,
        secondSpritePosition.coordinates.y + 142.0f, parent,
        secondResource, arcanaFrame, (u8)drawAlpha, alpha);
    campStatusDrawPersonaTopPacked(position, alpha, persona, drawAlpha);
    campStatusDrawPersonaBottomPacked(position, alpha, persona, drawAlpha);
}

// FUN_00133460
void FUN_00133460(CampStatusPackedPosition position, f32 alpha, void* unused,
                  void* persona, s32 fade)
{
    CampStatusPackedPosition firstSpritePosition;
    CampStatusPackedPosition secondSpritePosition;
    u32 parent;
    void* secondResource;
    s32 drawAlpha;
    s32 arcanaFrame;

    drawAlpha = 0xff - fade;
    campStatusDrawRanksPacked(position, alpha, unused, persona, drawAlpha);
    position.coordinates.x += 12.0f;
    position.coordinates.y += 96.0f;
    firstSpritePosition = position;
    campStatusDrawSpritePackedCall(
        firstSpritePosition.coordinates.x + 22.0f,
        firstSpritePosition.coordinates.y + 117.0f, parent,
        *(void**)DAT_00833B90_abs, 1, (u8)drawAlpha, alpha);
    secondSpritePosition = position;
    secondResource = *(void**)DAT_00833B88_abs;
    arcanaFrame = (FUN_00173280(*(u16*)((u8*)persona + 2)) & 0xff) - 1;
    campStatusDrawSpritePackedCall(
        secondSpritePosition.coordinates.x + 105.0f,
        secondSpritePosition.coordinates.y + 142.0f, parent,
        secondResource, arcanaFrame, (u8)drawAlpha, alpha);
    campStatusDrawPersonaTopPacked(position, alpha, persona, drawAlpha);
    campStatusDrawPersonaBottomPacked(position, alpha, persona, drawAlpha);
}

/* Retail 0x1313e0 uses the direct child-create call; case 1 reloads archive
 * state at 0x13132c/0x131368/0x1313a4, and case 3 reloads records at
 * 0x131504/0x1315f0/0x13169c/0x1316e8. */
// FUN_001311D0 NONMATCHING
void* FUN_001311d0(KwlnTask* task)
{
    u8* work;

    work = (u8*)task->workData;
    switch (*(u32*)work) {
    case 0:
    {
        HCdvd* cdvd;
        DatPersonaWork* persona;
        s32 count;
        s32 i;

        if (h_campRequestRootMenuTransition(DAT_007cdf50, 4) == 0) {
            return KWLNTASK_CONTINUE;
        }
        *(void**)(work + 0x64) = func_0018b6d0(100);
        *(void**)(work + 0x68) = func_0018b6d0(10);
        cdvd = H_Cdvd_Request(D_005DB140, HCDVD_FILEARCHIVE);
        *(HCdvd**)(work + 0x50) = cdvd;
        count = 0;
        for (i = 0; i < 12; i++) {
            *(u16*)(work + 0x1a + count * 2) = 0;
            if (datPersonaHeroPersonaValid((s16)i) != 0) {
                persona = datPersonaGetHeroPersona((s16)i);
                printf(D_005DB158, persona->id);
                *(u16*)(work + 0x1a + count * 2) = persona->id;
                *(u16*)(work + 0x32 + count * 2) = (u16)i;
                count++;
            }
        }
        *(s16*)(work + 0x4a) = (s16)count;
        *(u32*)work = 1;
        break;
    }
    case 1:
    {
        HCdvd* cdvd;
        u32 fileSize;

        cdvd = *(HCdvd**)(work + 0x50);
        if (H_Cdvd_IsFileLoaded(cdvd) == 0) {
            return KWLNTASK_CONTINUE;
        }
        *(void**)(work + 0x58) = func_00112420(
            H_Cdvd_ArchiveGetFile(*(HCdvd**)(work + 0x50), 0, &fileSize));
        *(void**)(work + 0x5c) = func_00112420(
            H_Cdvd_ArchiveGetFile(*(HCdvd**)(work + 0x50), 1, &fileSize));
        *(void**)(work + 0x60) = func_00112420(
            H_Cdvd_ArchiveGetFile(*(HCdvd**)(work + 0x50), 2, &fileSize));
        *(KwlnTask**)(work + 0x54) =
            campStatusCreatePersonaChild(
                task, 0x18bf, *(u16*)(work + 0x1a), (u32)-1, 100.0f);
        *(u32*)work = 2;
        break;
    }
    case 2:
    {
        void** resources;

        resources = (void**)(work + 0x58);
        if (H_Maestro_00111f30((s16*)resources[0]) == 0 ||
            H_Maestro_00111f30((s16*)resources[1]) == 0 ||
            H_Maestro_00111f30((s16*)resources[2]) == 0) {
            return KWLNTASK_CONTINUE;
        }
        *(u32*)work = 3;
        break;
    }
    case 3:
    {
        CampVec2 position;
        CampVec2 start;
        s32 i;

        position.x = 0.0f;
        position.y = 0.0f;
        start = position;
        func_0018bc10(100.0f, *(void**)(work + 0x64), 0, 2, 1,
                      *(u64*)&start, *(u64*)&position, 0, 0, 5, 5);
        for (i = 0; i < *(s16*)(work + 0x4a); i++) {
            position.x = 119.0f;
            position.y = 73.0f + (f32)(i * 29);
            if (i == *(s32*)(work + 0x4)) {
                position.x += 21.0f;
            }
            start = position;
            start.x -= 600.0f;
            func_0018bc10(100.0f,
                          (u8*)*(void**)(work + 0x64) +
                              (i + 1) * 0x44,
                          0, 2, 1, *(u64*)&start, *(u64*)&position,
                          0, 0, 0, 10);
            position.x = -11.0f;
            position.y = 63.0f + (f32)(i * 29);
            if (i == *(s32*)(work + 0x4)) {
                position.x += 21.0f;
            }
            start = position;
            start.x -= 600.0f;
            func_0018bc10(100.0f,
                          (u8*)*(void**)(work + 0x64) +
                              (i + 14) * 0x44,
                          0, 2, 1, *(u64*)&start, *(u64*)&position,
                          0, 0, 0, 6);
        }
        position.x = 497.0f;
        position.y = 26.0f;
        start = position;
        start.x += 600.0f;
        func_0018bc10(100.0f,
                      (u8*)*(void**)(work + 0x64) + 27 * 0x44,
                      0, 2, 1, *(u64*)&start, *(u64*)&position,
                      0, 0, 0, 10);
        position.x = 34.0f;
        position.y = 415.0f;
        start = position;
        start.x += 600.0f;
        func_0018bc10(100.0f,
                      (u8*)*(void**)(work + 0x64) + 28 * 0x44,
                      0, 2, 1, *(u64*)&start, *(u64*)&position,
                      0, 0, 0, 10);
        *(u32*)work = 4;
        break;
    }
    case 4:
    {
        void* primaryRecords;
        u32 input;
        s32 selected;
        s32 count;

        primaryRecords = *(void**)(work + 0x64);
        selected = *(s32*)(work + 0x4);
        count = *(s16*)(work + 0x4a);
        if (*(u32*)(work + 0x4c) != 0) {
            input = (u32)DAT_007e094e;
            if ((input & 0x40) != 0) {
                FUN_0010a4e0(0, 0, 0, 1);
                *(u32*)work = 7;
            } else if ((input & 0x80) != 0) {
                FUN_0010a4e0(0, 0, 0, 1);
                *(u32*)work = 11;
            } else if ((input & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                *(u32*)work = 5;
            } else {

                s32 oldSelected;
                s32 changed;
                u32 held;
                oldSelected = selected;
                changed = 0;
                held = ((u32)DAT_007e0952 & 0x1000) != 0 ||
                       ((u32)DAT_007e095a & 0x1000) != 0;
                if (held != 0) {
                    if (selected != 0) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        selected--;
                        changed = 1;
                    } else if (((input & 0x1000) != 0) ||
                               (((u32)DAT_007e0958 & 0x1000) != 0 &&
                                count != 1)) {
                        if (count != 1) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            selected = count - 1;
                            changed = 1;
                        }
                    }
                } else {
                    held = ((u32)DAT_007e0952 & 0x4000) != 0 ||
                           ((u32)DAT_007e095a & 0x4000) != 0;
                    if (held != 0) {
                        if (selected != count - 1) {
                            FUN_0010a4e0(0, 0, 0, 0);
                            selected++;
                            changed = 1;
                        } else if (((input & 0x4000) != 0) ||
                                   ((u32)DAT_007e0958 & 0x4000) != 0) {
                            if (count != 1) {
                                FUN_0010a4e0(0, 0, 0, 0);
                                selected = 0;
                                changed = 1;
                            }
                        }
                    }
                }
                if (changed != 0) {
                    *(s32*)(work + 0x4) = selected;
                    campStatusAnimateSelection(primaryRecords, oldSelected,
                                               selected);
                }
            }
        }
        campStatusDrawMain(work, selected);
        break;
    }
    case 5:
    {
        void* primaryRecords;
        s32 selected;
        s32 count;

        primaryRecords = *(void**)(work + 0x64);
        selected = *(s32*)(work + 0x4);
        count = *(s16*)(work + 0x4a);
        campStatusClosePersonaList(primaryRecords, selected, count);
        FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                     (s16)selected);
        *(u32*)work = 6;
        break;
    }
    case 6:
    {
        void* primaryRecords;
        s32 selected;
        s32 result;

        primaryRecords = *(void**)(work + 0x64);
        selected = *(s32*)(work + 0x4);
        result = FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                              (s16)selected);
        if (result != 0) {
            return KWLNTASK_STOP;
        }
        break;
    }
    case 7:
    {
        void* primaryRecords;
        void* detailRecords;
        s32 selected;
        s32 count;

        primaryRecords = *(void**)(work + 0x64);
        detailRecords = *(void**)(work + 0x68);
        selected = *(s32*)(work + 0x4);
        count = *(s16*)(work + 0x4a);
        if (h_campRequestRootMenuTransition(DAT_007cdf50, 5) != 0) {
            campStatusClosePersonaList(primaryRecords, selected, count);
            campStatusInitializeDetail(detailRecords, 1);
            *(u32*)(work + 0x8) = 0;
            *(u32*)(work + 0x4c) = 0;
            *(u32*)work = 8;
        }
        campStatusDrawMainDiscardResult(work, selected);
        break;
    }
    case 8:
    {
        void* detailRecords;
        s32 selected;
        s32 previous;
        s32 count;
        u32 input;
        s32 changed;

        detailRecords = *(void**)(work + 0x68);
        selected = *(s32*)(work + 0x4);
        previous = *(s32*)(work + 0xc);
        count = *(s16*)(work + 0x4a);
        if (*(u32*)(work + 0x4c) != 0) {
            *(s32*)(work + 0xc) = selected;
            previous = selected;
            input = (u32)DAT_007e094e;
            changed = 0;
            if ((input & 0x40) != 0) {
                FUN_0010a4e0(0, 0, 0, 1);
                *(u32*)work = 14;
            } else if ((input & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                *(u32*)work = 9;
            } else {
                if ((input & 0x4) != 0) {
                    if (selected != 0) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        selected--;
                        changed = 1;
                    } else if (count != 1) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        selected = count - 1;
                        changed = 1;
                    }
                } else if ((input & 0x8) != 0) {
                    if (selected != count - 1) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        selected++;
                        changed = 1;
                    } else if (count != 1) {
                        FUN_0010a4e0(0, 0, 0, 0);
                        selected = 0;
                        changed = 1;
                    }
                }
            }
            if (changed != 0) {
                *(s32*)(work + 0x4) = selected;
            }
            *(u32*)(work + 0x4c) = 0;
            if (selected != *(s32*)(work + 0xc)) {
                campStatusAnimateDetailSelection(detailRecords);
            }
        }
        campStatusDrawDetail(work, selected, previous);
        break;
    }
    case 9:
    {
        void* primaryRecords;
        void* detailRecords;
        s32 selected;
        s32 previous;
        s32 count;

        primaryRecords = *(void**)(work + 0x64);
        detailRecords = *(void**)(work + 0x68);
        selected = *(s32*)(work + 0x4);
        previous = *(s32*)(work + 0xc);
        count = *(s16*)(work + 0x4a);
        if (h_campRequestRootMenuTransition(DAT_007cdf50, 4) != 0) {
            campStatusInitializePersonaList(primaryRecords, selected, count);
            campStatusInitializeDetail(detailRecords, 2);
            *(u32*)(work + 0x8) = 0;
            *(u32*)(work + 0x4c) = 0;
            *(u32*)work = 10;
        }
        campStatusUpdatePersonaChild(work, selected);
        FUN_00134900(*(void**)(work + 0x68), work + 0x58, work + 0x32,
                     (s16)selected, (s16)previous);
        break;
    }
    case 10:
    {
        void* primaryRecords;
        KwlnTask* child;
        s32 selected;
        s32 previous;
        s32 result;
        u32 personaId;

        primaryRecords = *(void**)(work + 0x64);
        child = *(KwlnTask**)(work + 0x54);
        selected = *(s32*)(work + 0x4);
        previous = *(s32*)(work + 0xc);
        result = FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                              (s16)selected);
        if (result != 0) {
            *(u32*)work = 4;
        }
        personaId = *(u16*)(work + 0x1a + selected * 2);
        FUN_00133b80(child, personaId, (u32)-1);
        FUN_00133a80(child);
        FUN_00134900(*(void**)(work + 0x68), work + 0x58, work + 0x32,
                     (s16)selected, (s16)previous);
        break;
    }
    case 11:
    {
        void* primaryRecords;
        KwlnTask* child;
        s32 selected;
        u32 personaId;

        primaryRecords = *(void**)(work + 0x64);
        child = *(KwlnTask**)(work + 0x54);
        selected = *(s32*)(work + 0x4);
        FUN_00133a80(child);
        FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                     (s16)selected);
        personaId = *(u16*)(work + 0x32 + selected * 2);
        if (personaId == (u16)datGetEquippedPersona(1)) {
            FUN_003c7430(2);
            *(u32*)work = 13;
        } else {
            FUN_003c7430(1);
            FUN_003c74e0(0);
            FUN_003c7560(0);
            *(u32*)work = 12;
        }
        break;
    }
    case 12:
    {
        void* primaryRecords;
        KwlnTask* child;
        CampVec2 position;
        CampVec2 start;
        s32 selected;
        s32 count;
        s32 result;
        s32 i;

        primaryRecords = *(void**)(work + 0x64);
        child = *(KwlnTask**)(work + 0x54);
        selected = *(s32*)(work + 0x4);
        count = *(s16*)(work + 0x4a);
        FUN_00133a80(child);
        FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                     (s16)selected);
        if (FUN_003c7850() != 0) {
            break;
        }
        result = FUN_003c7610();
        if (result == 0) {
            FUN_00174c10(*(u16*)(work + 0x32 + selected * 2));
            campStatusRebuildPersonaList(work);
            primaryRecords = *(void**)(work + 0x64);
            campStatusResetPersonaAnimations(primaryRecords);
            selected = *(s32*)(work + 0x4);
            count = *(s16*)(work + 0x4a);
            for (i = 0; i < count; i++) {
                position.x = 119.0f;
                position.y = 73.0f + (f32)(i * 29);
                if (i == selected) {
                    position.x += 21.0f;
                }
                start = position;
                start.x -= 600.0f;
                campStatusAnimateRecord(primaryRecords, i + 1, 1, start,
                                        position, 0, 10);
            }
            for (i = 0; i < count; i++) {
                position.x = -11.0f;
                position.y = 63.0f + (f32)(i * 29);
                if (i == selected) {
                    position.x += 21.0f;
                }
                start = position;
                start.x -= 600.0f;
                campStatusAnimateRecord(primaryRecords, i + 14, 1, start,
                                        position, 0, 6);
            }
        }
        FUN_003c7700();
        *(u32*)work = 4;
        break;
    }
    case 13:
    {
        void* primaryRecords;
        KwlnTask* child;

        primaryRecords = *(void**)(work + 0x64);
        child = *(KwlnTask**)(work + 0x54);
        FUN_00133a80(child);
        FUN_001344B0(primaryRecords, work + 0x58, work + 0x32,
                     *(s16*)(work + 0x4));
        if (FUN_003c7850() == 0) {
            FUN_003c7700();
            *(u32*)work = 4;
        }
        break;
    }
    case 14:
    {
        void* detailRecords;
        KwlnTask* child;
        s32 selected;
        s32 previous;
        u32 personaId;

        detailRecords = *(void**)(work + 0x68);
        child = *(KwlnTask**)(work + 0x54);
        selected = *(s32*)(work + 0x4);
        previous = *(s32*)(work + 0xc);
        personaId = *(u16*)(work + 0x1a + selected * 2);
        FUN_00133b80(child, personaId, (u32)-1);
        FUN_00133a80(child);
        FUN_00134900(detailRecords, work + 0x58, work + 0x32,
                     (s16)selected, (s16)previous);
        FUN_003c7430(3);
        FUN_003c74e0(0);
        FUN_003c7560(0);
        *(u32*)work = 15;
        break;
    }
    case 15:
    {
        void* detailRecords;
        KwlnTask* child;
        s32 selected;
        s32 result;
        u32 personaId;

        detailRecords = *(void**)(work + 0x68);
        child = *(KwlnTask**)(work + 0x54);
        selected = *(s32*)(work + 0x4);
        personaId = *(u16*)(work + 0x1a + selected * 2);
        FUN_00133b80(child, personaId, (u32)-1);
        FUN_00133a80(child);
        FUN_00134900(detailRecords, work + 0x58, work + 0x32,
                     (s16)selected, *(s16*)(work + 0xc));
        if (FUN_003c7850() != 0) {
            break;
        }
        result = FUN_003c7610();
        if (result == 0) {
            FUN_0010a4e0(0, 0, 2, 4);
            FUN_00175200(*(u16*)(work + 0x32 + selected * 2));
            h_campReplacePersonaTextureControlResource(datGetPersonaId(1));
            FUN_003c7700();
            *(u32*)work = 8;
        }
        break;
    }
    default:
        return KWLNTASK_CONTINUE;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00133780
void* func_00133780(KwlnTask* task)
{
    u8* work;
    u32 wasReady;
    HCdvd* cdvd;
    work = (u8*)task->workData;
    switch (*(u32*)work) {
    case 0:
        if (*(u32*)(work + 4) != 0) {
            sprintf((char*)(work + 0x2c), D_005DACB0,
                    *(u32*)(work + 4));
            cdvd = H_Cdvd_Request((char*)(work + 0x2c), HCDVD_FILENORMAL);
            *(HCdvd**)(work + 0x24) = cdvd;
            *(u32*)work = 1;
            *(f32*)(work + 0x18) = 700.0f;
            *(f32*)(work + 0x1c) = -117.0f;
            *(f32*)(work + 0x14) = 10.0f;
        } else {
            *(u32*)work = 3;
        }
        break;

    case 1:
        cdvd = *(HCdvd**)(work + 0x24);
        if (H_Cdvd_IsFileLoaded(cdvd) != 0) {
            *(void**)(work + 0x20) = func_0010c1a0(
                NULL, (char*)(work + 0x2c), 0, 0, 0, 0, 0, 0, 0, 0,
                D_005DB170, 0x3c0);
            *(u32*)work = 2;
        }
        break;

    case 2:
        *(void**)(work + 0x28) =
            func_0010c3a0(*(void**)(work + 0x20), &wasReady, NULL);
        if (wasReady != 0) {
            *(void**)(work + 0x20) = NULL;
            cdvd = *(HCdvd**)(work + 0x24);
            H_Cdvd_Destroy(cdvd);
            *(HCdvd**)(work + 0x24) = NULL;
            *(u32*)work = 3;
        }
        break;

    case 3:
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}
