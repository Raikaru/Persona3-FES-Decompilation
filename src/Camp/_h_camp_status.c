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
/* opt_common_subs off: default/on nd703/1056B -> off nd664/1096B; retained. */

void h_campStatusDrawStatus(CampVec2 position, CampVec2 unused,
                             f32 alpha, s16 pcId, s32 fade);
void h_campStatusDrawStatusTransition(CampVec2 position, f32 alpha,
                                       s16 pcId, s32 phase);
void h_campStatusDrawSp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade);

/* opt_common_subs off: default/on nd767/1048B -> off nd765/1040B; retained. */

/* opt_common_subs off: default/on nd591/1024B -> off nd363/1016B; retained. */









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

/* opt_loop_invariants on: off nd897/1192B -> on nd755/1232B; retained. */

/* opt_loop_invariants on: off nd449/604B -> on nd391/612B; retained. */

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


/* Retail panel frame: seventeen status sprites, two footer sprites, and the
 * formatted footer text, with resource and frame selections from retail. */






void h_campStatusRenderMode(CampVec2 position, f32 scale, void* persona,
                            s32 mode, s32 frame, s32 alpha);
/* opt_common_subs off: default/on nd634/920B -> off nd614/944B; retained. */






void h_campStatusDrawTransition(CampVec2 position, f32 scale,
                                void* persona, s32 frame);
void h_campStatusDrawEntering(CampVec2 position, f32 scale,
                              void* persona, s32 frame);
void h_campStatusDrawSteady(CampVec2 position, f32 scale,
                            void* persona, s32 alpha);







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


/* opt_loop_invariants on: off nd1115/1508B -> on nd1088/1520B; retained. */
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




/* Retail 0x1313e0 uses the direct child-create call; case 1 reloads archive
 * state at 0x13132c/0x131368/0x1313a4, and case 3 reloads records at
 * 0x131504/0x1315f0/0x13169c/0x1316e8. */

