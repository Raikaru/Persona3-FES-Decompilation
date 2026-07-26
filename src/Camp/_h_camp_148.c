/* Camp retail slice 0x148000-0x14F7D0. */
#include "Camp/h_camp.h"
#include "Main/Game/game_support.h"
#include "Main/g_data.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

/* Ghidra's decompiler uses fixed-width aliases for the EE types. */
typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef struct CampPair
{
    f32 x;
    f32 y;
} CampPair;
typedef union CampBits
{
    u64 u;
    f32 f[2];
} CampBits;

/* CONCAT44 packs IEEE-754 words, not numeric float casts. */
static inline u32 campFloatBits(f32 value)
{
    union { f32 f; u32 u; } bits;
    bits.f = value;
    return bits.u;
}
#define CAMP_PAIR_WORDS(high, low) ((((u64)(u32)(high)) << 32) | (u32)(low))
#define CAMP_PAIR_FLOAT_HIGH(high, low) (((u64)campFloatBits(high) << 32) | (u32)(low))
#define CAMP_PAIR_WORD_HIGH(high, low) ((((u64)(u32)(high)) << 32) | campFloatBits(low))
#define CAMP_PAIR_FLOATS(high, low) (((u64)campFloatBits(high) << 32) | campFloatBits(low))
#define CAMP_DRAW_CALC_FIRST(depth, target, mode, xval, yval, delta) \
    do { \
        pair.x = (xval); \
        pair.y = (yval); \
        temp.u = *(u64*)&pair; \
        temp.f[0] = temp.f[0] + (delta); \
        campDrawTransition((depth), (target), 0, 2, (mode), \
                           temp.u, *(u64*)&pair, 0, 0, 0, 0); \
    } while (0)
#define CAMP_DRAW_CALC_SECOND(depth, target, mode, xval, yval, delta) \
    do { \
        pair.x = (xval); \
        pair.y = (yval); \
        temp.u = *(u64*)&pair; \
        pair.x = pair.x + (delta); \
        campDrawTransition((depth), (target), 0, 2, (mode), \
                           temp.u, *(u64*)&pair, 0, 0, 0, 0); \
    } while (0)

#define CAMP_DRAW_CALC_FIRST_AT(tmp, depth, target, mode, xval, yval, delta) \
    do { \
        pair.x = (xval); \
        pair.y = (yval); \
        (tmp).u = *(u64*)&pair; \
        (tmp).f[0] = (tmp).f[0] + (delta); \
        campDrawTransition((depth), (target), 0, 2, (mode), \
                           (tmp).u, *(u64*)&pair, 0, 0, 0, 0); \
    } while (0)
#define CAMP_DRAW_CALC_SECOND_AT(tmp, depth, target, mode, xval, yval, delta) \
    do { \
        pair.x = (xval); \
        pair.y = (yval); \
        (tmp).u = *(u64*)&pair; \
        pair.x = pair.x + (delta); \
        campDrawTransition((depth), (target), 0, 2, (mode), \
                           (tmp).u, *(u64*)&pair, 0, 0, 0, 0); \
    } while (0)
#define CAMP_DRAW_CALC_FIRST_AT_TILE(tmp, depth, target, mode, xval, yval, delta, tile) \
    do { \
        pair.x = (xval); \
        pair.y = (yval); \
        (tmp).u = *(u64*)&pair; \
        (tmp).f[0] = (tmp).f[0] + (delta); \
        campDrawTransition((depth), (target), 0, 2, (mode), \
                           (tmp).u, *(u64*)&pair, 0, (tile), 0, 0); \
    } while (0)

extern s16 DAT_005e3b5e[];
extern s32 DAT_005e3b64;
extern void* DAT_007cdf50;
extern void* DAT_007cdf54;
extern void* DAT_007cdf58;
extern u8* DAT_007cdf5c;
extern u8* DAT_007cdf60;
extern s32 DAT_007cdf90;
extern u16 DAT_007cdf94;
typedef struct CampSocialLinkRecord
{
    s16 first;
    s16 second;
    s32 flag;
    s16 type;
    s16 reserved0a;
} CampSocialLinkRecord;
extern CampSocialLinkRecord* DAT_007cdfb8;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_00833a50[];
#pragma alias DAT_00833a50_abs DAT_00833a50
extern u8 DAT_00833a50_abs[];
extern void* DAT_00833b78;
extern s32 (*DAT_00960184)();
#pragma alias DAT_00960184_abs DAT_00960184
extern u8 DAT_00960184_abs[];
extern u8 DAT_005dbc50[];
extern u8 DAT_005dbc60[];
#pragma alias campAlloc DAT_00960184
extern void* (*campAlloc[])(u32, u32, u32);
extern void campDrawSprite(void* parent, void* resource, s32 frame,
                           u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campDrawSprite FUN_001159f0
#pragma alias campDrawSpriteX FUN_001159f0
extern void campDrawSpriteX(void* parent, void* resource, s32 frame,
                            f32 x, u32 alpha, f32 y, f32 scale);
#pragma alias campDrawSpriteXY FUN_001159f0
extern void campDrawSpriteXY(void* parent, void* resource, s32 frame,
                             f32 x, f32 y, u32 alpha, f32 scale);
#pragma alias campTaskCreate FUN_00194b20
extern KwlnTask* campTaskCreate(KwlnTask*, const char*, u32,
                                void* (*)(KwlnTask*), void (*)(KwlnTask*),
                                void*);
extern void campDrawTransition(f32 depth, void* transition, s32 drawMode,
                               s32 positionMode, s32 alphaMode,
                               u64 start, u64 end, s32 param0, s32 tile,
                               s32 startFrame, s32 endFrame);
#pragma alias campDrawTransition func_0018bc10
#pragma alias campDrawItemFrameAlias FUN_0014EF60
extern void campDrawItemFrameAlias(int param_1);
extern void h_campItemDestroyNewItemTask(KwlnTask* task);

extern u32 FUN_00100d80();
extern u32 FUN_001016b0();
extern u64 FUN_00102100();
extern u32 FUN_00103c30();
extern u32 FUN_00103cb0();
extern u32 FUN_0010a4e0();
extern u32 FUN_0010c1a0(int param_1, u32 param_2, int param_3, int param_4,
                        int param_5, int param_6, int param_7, int param_8);
extern u32 FUN_0010c3a0();
extern u32 FUN_00111f30();
extern u32 FUN_00112420();
extern u32 FUN_001127d0();
extern void FUN_00113a30(f32 depth, f32 x, f32 y, u32 color, s32 width, s32 height);
extern s32 FUN_00114450(f32 x, f32 y, f32 z, s32 a, u32 b, u32 c, u32 d);
extern u32 FUN_001158b0();
extern u32 FUN_00115980();
extern u32 FUN_001159f0();
extern u32 FUN_0011abd0();
extern s32 FUN_0011bba0(s32 a, s32 b, f32 z, s32 c, s32 d);
extern u32 FUN_0011da80();
extern u32 FUN_0011e380();
extern u32 FUN_00121de0();
extern u32 FUN_00122710();
extern u32 FUN_0013bce0();
extern u32 FUN_0013be50();
extern void FUN_0013e710(CampPair position, f32 alpha, void* work, s32 fade);
extern void FUN_00140e30(CampPair position, f32 alpha, void* work, s32 fade);
extern u32 FUN_00141590();
extern u32 FUN_00141660();
extern u32 FUN_00141fb0();
extern u32 FUN_00142930();
extern u32 FUN_001432f0();
extern u32 FUN_00143a00();
extern u32 FUN_00143ee0();
extern u32 FUN_00144910();
extern u32 FUN_00145350();
extern u32 FUN_00145520();
extern u32 FUN_00146710();
extern u32 FUN_001474f0();
extern u32 FUN_00154f70();
extern u32 FUN_00155710();
extern u32 FUN_00156140();
extern u32 FUN_00156e80();
extern u32 FUN_00159900();
extern u32 FUN_0016cb80();
extern u32 FUN_0016dd60();
extern u32 FUN_0016f190();
extern u32 FUN_0016f1f0();
extern u32 FUN_00173580();
extern u32 FUN_00174960();
extern u64 FUN_00174a90();
extern u32 FUN_0017ae30();
extern u32 FUN_0017bb40();
extern u32 FUN_0017bbb0();
extern u32 FUN_0017bf70();
extern u32 FUN_0017bfa0();
extern u32 FUN_0017d800();
extern u32 FUN_0017d830();
// FUN_001482F0 NONMATCHING
void h_campDrawStatusOverview(int param_1)
{
    CampPair pair;
    CampBits tmp[10];
    s32 i;

    pair.x = 379.0f;
    pair.y = 12.0f;
    tmp[0].u = *(u64*)&pair;
    tmp[0].f[0] += 0.0f;
    pair.x = 13.0f;
    pair.y = 27.0f;
    tmp[1].u = *(u64*)&pair;
    tmp[1].f[0] += 0.0f;
    pair.x = 112.0f;
    tmp[2].u = *(u64*)&pair;
    tmp[2].f[0] += 0.0f;
    pair.x = 135.0f;
    tmp[3].u = *(u64*)&pair;
    tmp[3].f[0] += 0.0f;
    pair.x = 278.0f;
    tmp[4].u = *(u64*)&pair;
    tmp[4].f[0] += 0.0f;
    pair.x = 301.0f;
    tmp[5].u = *(u64*)&pair;
    tmp[5].f[0] += 0.0f;

    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0)), 0, 2, 2,
                  tmp[0].u, tmp[0].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x44), 0, 2, 2,
                  tmp[1].u, tmp[1].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x88), 0, 2, 2,
                  tmp[2].u, tmp[2].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0xcc), 0, 2, 2,
                  tmp[3].u, tmp[3].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x110), 0, 2, 2,
                  tmp[4].u, tmp[4].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x154), 0, 2, 2,
                  tmp[5].u, tmp[5].u, 0, 0, 0, 10);
    for (i = 0; i < 4; i++) {
        if (*(s32*)(param_1 + 0x1c) - 1 < i) {
            *(u32*)(*(u32*)(param_1 + 0xc0) + i * 0x44 + 0x2ac) = 0;
        } else {
            pair.x = 30.0f;
            pair.y = 64.0f + (f32)(i * 0x55);
            tmp[8 + (i & 1)].u = *(u64*)&pair;
            tmp[8 + (i & 1)].f[0] += 0.0f;
            func_0018bc10(100.0f,
                          (void*)(*(u32*)(param_1 + 0xc0) + (i + 10) * 0x44),
                          0, 2, 2, tmp[8 + (i & 1)].u, tmp[8 + (i & 1)].u,
                          0, 0, 0, 10);
        }
    }
    pair.x = 104.0f;
    pair.y = 61.0f;
    tmp[6].u = *(u64*)&pair;
    tmp[6].f[0] += 0.0f;
    pair.x = 124.0f;
    pair.y = 219.0f;
    tmp[7].u = *(u64*)&pair;
    tmp[7].f[0] += 0.0f;
    pair.x = 226.0f;
    pair.y = 415.0f;
    tmp[8].u = *(u64*)&pair;
    tmp[8].f[0] += 0.0f;
    pair.x = 439.0f;
    pair.y = 415.0f;
    tmp[9].u = *(u64*)&pair;
    tmp[9].f[0] += 0.0f;
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x550), 0, 2, 2,
                  tmp[6].u, tmp[6].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x594), 0, 2, 2,
                  tmp[7].u, tmp[7].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x83c), 0, 2, 2,
                  tmp[8].u, tmp[8].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x880), 0, 2, 2,
                  tmp[9].u, tmp[9].u, 0, 0, 0, 10);
}
// FUN_00148880 NONMATCHING
void h_campDrawListEntry(int param_1,int param_2,int param_3)
{
    register void* parent;
    switch (param_2) {
    case 0:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x2c,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 1:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x21,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 2:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x24,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 3:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x28,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 4:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x24,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 5:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 0), 0x23,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 10:
    case 11:
    case 12:
    case 13:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 4), 5,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 0x14:
        FUN_0013e710(*(CampPair*)((u8*)param_1 + 0x38),
                     *(f32*)(param_1 + 0x24),
                     (void*)*(u32*)(param_3 + 0xa8), *(s32*)(param_1 + 0x40));
        break;
    case 0x15:
        break;
    case 0x1f:
        campDrawSprite(parent, (void*)*(void**)(DAT_00833a50_abs + 8), 8,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        campDrawSpriteX(parent, (void*)*(void**)(DAT_00833a50_abs + 8), 4,
                        *(f32*)(param_1 + 0x38) + 16.0f,
                        *(u8*)(param_1 + 0x40),
                        *(f32*)(param_1 + 0x3c), *(f32*)(param_1 + 0x24));
        break;
    case 0x20:
        campDrawSpriteX(parent, (void*)*(void**)(DAT_00833a50_abs + 0x154), 5,
                        *(f32*)(param_1 + 0x38) + 20.0f,
                        *(u8*)(param_1 + 0x40),
                        *(f32*)(param_1 + 0x3c), *(f32*)(param_1 + 0x24));
        campDrawSpriteXY(parent, (void*)*(void**)(DAT_00833a50_abs + 0x154), 9,
                         *(f32*)(param_1 + 0x38) + 97.0f,
                         (*(f32*)(param_1 + 0x3c) + 389.0f) - 415.0f,
                         *(u8*)(param_1 + 0x40), *(f32*)(param_1 + 0x24));
        campDrawSpriteX(parent, (void*)*(void**)(DAT_00833a50_abs + 0x154), 3,
                        *(f32*)(param_1 + 0x38) + 122.0f,
                        *(u8*)(param_1 + 0x40),
                        *(f32*)(param_1 + 0x3c), *(f32*)(param_1 + 0x24));
        break;
    default:
        break;
    }
}

/* Retail offsets 0x148c10-0x1496dc: comparison draws retain one packed
 * start coordinate per call and recompute the -100.0f x shift in place. */
// FUN_00148C10 NONMATCHING
void h_campDrawStatusComparison(int param_1)
{
    CampPair pair;
    CampBits start;
    CampBits sp48;
    CampBits sp50;
    CampBits sp58;
    CampBits sp60;
    CampBits sp68;
    CampBits sp70;
    CampBits sp78;
    CampBits sp80;
    CampBits sp88;
    CampBits sp90;
    CampBits sp98;
    CampBits spa0;
    CampBits spa8;
    CampBits spb0;
    CampBits spb8;
    CampBits spc0;
    CampBits spc8;
    CampBits spd0;
    CampBits spd8;
    CampBits spe0;
    CampBits spe8;
    s32 iVar1;
    f32 fVar2;

    pair.x = 379.0f;
    pair.y = 12.0f;
    start.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    campDrawTransition(100.0f, (void*)(*(u32*)(param_1 + 0xc0)), 0, 2, 2,
                       start.u, *(u64*)&pair, 0, 0, 0, 10);

    pair.x = 13.0f;
    pair.y = 27.0f;
    sp48.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x44),
                  0, 2, 2, sp48.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 112.0f;
    pair.y = 27.0f;
    sp50.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x88),
                  0, 2, 2, sp50.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 135.0f;
    pair.y = 27.0f;
    sp58.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0xcc),
                  0, 2, 2, sp58.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 278.0f;
    pair.y = 27.0f;
    sp60.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x110),
                  0, 2, 2, sp60.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 301.0f;
    pair.y = 27.0f;
    sp68.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x154),
                  0, 2, 2, sp68.u, *(u64*)&pair, 0, 0, 0, 10);

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
        if (*(int *)(param_1 + 0x1c) + -1 < iVar1) {
            *(u32 *)(*(int *)(param_1 + 0xc0) + iVar1 * 0x44 + 0x2ac) = 0;
        }
        else {
            fVar2 = (float)(iVar1 * 0x55) + 64.0f;
            pair.x = 30.0f;
            pair.y = fVar2;
            sp70.u = *(u64*)&pair;
            pair.x = pair.x + (-100.0f);
            func_0018bc10(100.0f,
                          (void*)(*(int *)(param_1 + 0xc0) +
                                  (iVar1 + 10) * 0x44),
                          0, 2, 2, sp70.u, *(u64*)&pair, 0, 0, 0, 10);
        }
    }

    pair.x = 104.0f;
    pair.y = 61.0f;
    sp78.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x550),
                  0, 2, 2, sp78.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 124.0f;
    pair.y = 219.0f;
    sp80.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x594),
                  0, 2, 2, sp80.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 226.0f;
    pair.y = 415.0f;
    sp88.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x83c),
                  0, 2, 2, sp88.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 339.0f;
    pair.y = 415.0f;
    sp90.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc0) + 0x880),
                  0, 2, 2, sp90.u, *(u64*)&pair, 0, 0, 0, 10);

    pair.x = 481.0f;
    pair.y = 12.0f;
    sp98.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4)),
                  0, 2, 1, sp98.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 113.0f;
    pair.y = 27.0f;
    spa0.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x44),
                  0, 2, 1, spa0.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 212.0f;
    pair.y = 27.0f;
    spa8.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x88),
                  0, 2, 1, spa8.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 235.0f;
    pair.y = 27.0f;
    spb0.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0xcc),
                  0, 2, 1, spb0.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 373.0f;
    pair.y = 27.0f;
    spb8.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x110),
                  0, 2, 1, spb8.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 401.0f;
    pair.y = 27.0f;
    spc0.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x154),
                  0, 2, 1, spc0.u, *(u64*)&pair, 0, 0, 0, 10);

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
        if (*(int *)(param_1 + 0x1c) + -1 < iVar1) {
            *(u32 *)(*(int *)(param_1 + 0xc4) + iVar1 * 0x44 + 0x2ac) = 0;
        }
        else {
            fVar2 = (float)(iVar1 * 0x55) + 64.0f;
            pair.x = 710.0f;
            pair.y = fVar2;
            spc8.u = *(u64*)&pair;
            pair.x = pair.x + (-100.0f);
            func_0018bc10(100.0f,
                          (void*)(*(int *)(param_1 + 0xc4) +
                                  (iVar1 + 10) * 0x44),
                          0, 2, 1, spc8.u, *(u64*)&pair, 0, 0, 0, 10);
        }
    }

    pair.x = 147.0f;
    pair.y = 61.0f;
    spd0.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x550),
                  0, 2, 1, spd0.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 167.0f;
    pair.y = 219.0f;
    spd8.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x594),
                  0, 2, 1, spd8.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 326.0f;
    pair.y = 415.0f;
    spe0.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x7f8),
                  0, 2, 1, spe0.u, *(u64*)&pair, 0, 0, 0, 10);
    pair.x = 661.0f;
    pair.y = 415.0f;
    spe8.u = *(u64*)&pair;
    pair.x = pair.x + (-100.0f);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x83c),
                  0, 2, 1, spe8.u, *(u64*)&pair, 0, 0, 0, 10);
}

/* Reconstructed retail aggregate temporaries and per-entry coordinate updates.
 * The original decompiler output passed packed constants directly, losing the
 * contiguous stack-pair writes visible in retail.  The aggregate copy/update
 * sequence and the repeated loop calls survive without any volatile qualifier
 * (measured: dropping volatile improved normalized_diff by 359 with the file's
 * MATCH count unchanged), so plain locals are used here.
 * The resulting instruction layout remains NONMATCHING, but retains the
 * recovered second-loop entry update rather than silently omitting it. */
// FUN_001496F0 NONMATCHING
void h_campDrawPersonaOverview(int param_1)
{
  CampBits sp128;
  CampPair pair;
  CampBits sp118;
  CampBits sp110;
  CampBits sp108;
  CampBits sp100;
  CampBits spf8;
  CampBits spf0;
  CampBits spe8;
  CampBits spe0;
  CampBits spd8;
  CampBits spd0;
  CampBits spc8;
  CampBits spc0;
  CampBits spb8;
  CampBits spb0;
  CampBits spa8;
  CampBits spa0;
  CampBits sp98;
  CampBits sp90;
  CampBits sp88;
  CampBits sp80;
  CampBits sp78;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;

  CAMP_DRAW_CALC_FIRST_AT(sp128, 100.0f, (void*)(*(u32 *)(param_1 + 0xbc)), 1,
                       40.0f, 12.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(sp78, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x44), 1,
                       219.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(sp80, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0xcc), 1,
                       317.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(sp88, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x110), 1,
                       340.5f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(sp90, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x154), 1,
                       477.5f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(sp98, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x198), 1,
                       227.0f, 61.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spa0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1dc), 1,
                       247.5f, 219.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spa8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x220), 1,
                       559.0f, 67.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spb0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x7f8), 1,
                       126.0f, 415.0f, 100.0f);

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (iVar3 < *(int *)(param_1 + 0x1c)) {
      fVar5 = (float)(iVar3 * 0x55) + 62.0f;
      iVar4 = iVar3 * 10;
      CAMP_DRAW_CALC_FIRST_AT(spb0, 100.0f,
                              (void*)(*(int *)(param_1 + 0xbc) + (iVar4 + 0x1e) * 0x44), 1,
                              fVar5 + 8.0f, 65.0f, 100.0f);
      pair.x = fVar5 + 31.0f;
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar4 + 0x1f) * 0x44), 0, 2, 1, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
      pair.x = fVar5 + 45.0f;
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar4 + 0x20) * 0x44), 0, 2, 1, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
      pair.x = fVar5 + 64.0f;
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar4 + 0x21) * 0x44), 0, 2, 1, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
      iVar2 = iVar3 * 0x2a8;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x948) = 0;
      pair.x = fVar5 + 2.0f;
      pair.y = 14.0f;
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar4 + 0x22) * 0x44), 0, 2, 0, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x950) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x994) = 0;
    }
    else {
      iVar2 = iVar3 * 0x2a8;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x7fc) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x840) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x884) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x8c8) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x90c) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x950) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x994) = 0;
    }
  }
  CAMP_DRAW_CALC_FIRST_AT(spc8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1298), 1,
                       322.0f, 415.0f, 100.0f);
  *(u32 *)(*(int *)(param_1 + 0xbc) + 0x12e0) = 0;
  CAMP_DRAW_CALC_FIRST_AT(spb8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1364), 1,
                       217.0f, 415.0f, 100.0f);

  CAMP_DRAW_CALC_FIRST_AT(spc0, 100.0f, (void*)(*(u32 *)(param_1 + 0xc4)), 2,
                       281.0f, 12.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spb0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x44), 2,
                       -87.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spc8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x88), 2,
                       28.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spa8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0xcc), 2,
                       35.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spd0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x110), 2,
                       173.0f, 27.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spa0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x154), 2,
                       201.0f, 27.0f, 100.0f);
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (*(int *)(param_1 + 0x1c) + -1 < iVar3) {
      *(u32 *)(*(int *)(param_1 + 0xc4) + iVar3 * 0x44 + 0x2ac) = 0;
    }
    else {
      fVar5 = (float)(iVar3 * 0x55) + 64.0f;
      *(u32 *)(*(int *)(param_1 + 0xc4) + iVar3 * 0x44 + 0x2e8) = 0;
      pair.x = 610.0f;
      pair.y = fVar5;
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + (iVar3 + 10) * 0x44), 0, 2, 0, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
      func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc4) + (iVar3 + 11) * 0x44), 0, 2, 0, *(u64*)&pair, *(u64*)&pair, 0, 10, 0, 0);
    }
  }
  CAMP_DRAW_CALC_FIRST_AT(spd8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x550), 2,
                       -53.0f, 61.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spe0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x7f8), 2,
                       126.0f, 415.0f, 100.0f);
  CAMP_DRAW_CALC_FIRST_AT(spe8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x83c), 2,
                       461.0f, 415.0f, 100.0f);
}

/* Reconstructed the retail transition aggregates and full equipment-entry
 * dispatch, including per-entry packed-coordinate updates and inactive-slot
 * clears.  The recovered calls intentionally preserve the contiguous pair
 * updates and stack-passed tile values visible in retail.  This increases
 * source coverage and object size toward the retail window, although the
 * instruction schedule remains NONMATCHING. */
// FUN_0014A490 NONMATCHING
void h_campDrawPersonaEquipment(int param_1)
{
  CampBits sp68;
  CampPair pair;
  CampBits spb0;
  CampBits spb8;
  CampBits spc0;
  CampBits spc8;
  CampBits spd0;
  CampBits spe0;
  CampBits spe8;
  CampBits spf0;
  CampBits spf8;
  CampBits sp100;
  CampBits sp108;
  CampBits sp110;
  CampBits sp118;
  CampBits spa8;
  CampBits spa0;
  CampBits sp98;
  CampBits sp90;
  CampBits sp88;
  CampBits sp80;
  CampBits sp78;
  CampBits sp70;
  int iVar2;
  int iVar3;
  float fVar4;

  CAMP_DRAW_CALC_FIRST_AT_TILE(sp68, 100.0f, (void*)(*(u32 *)(param_1 + 0xbc)), 2, 40.0f, 12.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp70, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x44), 2, 219.0f, 27.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp78, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0xcc), 2, 318.0f, 27.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp80, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x110), 2, 341.0f, 27.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp88, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x154), 2, 484.0f, 27.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp90, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x198), 2, 507.0f, 27.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp98, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1dc), 2, 227.0f, 61.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(spa0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x220), 2, 247.0f, 219.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(spa8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x7f8), 2, 558.0f, 67.0f, 100.0f, 10);
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (iVar3 < *(int *)(param_1 + 0x1c)) {
      fVar4 = (float)(iVar3 * 0x55) + 62.0f;
      iVar2 = iVar3 * 10;
      CAMP_DRAW_CALC_FIRST_AT_TILE(spb0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar2 + 0x1e) * 0x44), 2, 65.0f, fVar4 + 8.0f, 0.0f, 4);
      CAMP_DRAW_CALC_FIRST_AT_TILE(spb8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar2 + 0x1f) * 0x44), 2, 65.0f, fVar4 + 31.0f, 0.0f, 4);
      CAMP_DRAW_CALC_FIRST_AT_TILE(spc0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar2 + 0x20) * 0x44), 2, 65.0f, fVar4 + 45.0f, 0.0f, 4);
      CAMP_DRAW_CALC_FIRST_AT_TILE(spc8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar2 + 0x21) * 0x44), 2, 65.0f, fVar4 + 64.0f, 0.0f, 4);
      CAMP_DRAW_CALC_FIRST_AT_TILE(spd0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + (iVar2 + 0x22) * 0x44), 2, 14.0f, fVar4 + 2.0f, 0.0f, 2);
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar3 * 0x2a8 + 0x950) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar3 * 0x2a8 + 0x994) = 0;
    }
    else {
      iVar2 = iVar3 * 0x2a8;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x7fc) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x840) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x884) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x8c8) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x90c) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x950) = 0;
      *(u32 *)(*(int *)(param_1 + 0xbc) + iVar2 + 0x994) = 0;
    }
  }
  CAMP_DRAW_CALC_FIRST_AT_TILE(spe0, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1298), 2, 62.0f, 415.0f, 100.0f, 10);
  *(u32 *)(*(int *)(param_1 + 0xbc) + 0x12e0) = 0;
  CAMP_DRAW_CALC_FIRST_AT_TILE(spe8, 100.0f, (void*)(*(int *)(param_1 + 0xbc) + 0x1364), 2, 239.0f, 415.0f, 100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(spf0, 100.0f, (void*)(*(u32 *)(param_1 + 0xc4)), 1, 381.0f, 12.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(spf8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x44), 1, 13.0f, 27.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp100, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x88), 1, 112.0f, 27.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp108, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0xcc), 1, 135.0f, 27.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp110, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x110), 1, 273.0f, 27.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp118, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x154), 1, 301.0f, 27.0f, -100.0f, 10);
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (*(int *)(param_1 + 0x1c) + -1 < iVar3) {
      *(u32 *)(*(int *)(param_1 + 0xc4) + iVar3 * 0x44 + 0x2ac) = 0;
    }
    else {
      fVar4 = (float)(iVar3 * 0x55) + 64.0f;
      CAMP_DRAW_CALC_FIRST_AT_TILE(spe0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + (iVar3 + 10) * 0x44), 0, 610.0f, fVar4, -610.0f, 10);
      *(u32 *)(*(int *)(param_1 + 0xc4) + iVar3 * 0x44 + 0x2e8) = 0;
    }
  }
  CAMP_DRAW_CALC_FIRST_AT_TILE(spf0, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x550), 1, 47.0f, 61.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(spf8, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x594), 1, 67.0f, 219.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp100, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x7f8), 1, 226.0f, 415.0f, -100.0f, 10);
  CAMP_DRAW_CALC_FIRST_AT_TILE(sp108, 100.0f, (void*)(*(int *)(param_1 + 0xc4) + 0x83c), 1, 561.0f, 415.0f, -100.0f, 10);
}

// FUN_0014B210 NONMATCHING
void h_campDrawPersonaList(int param_1)
{
    CampPair pair;
    CampBits temp;
    s32 i;

    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0)), 1,
                          379.0f, 12.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x44), 1,
                          13.0f, 27.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x88), 1,
                          112.0f, 27.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0xcc), 1,
                          135.0f, 27.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x110), 1,
                          278.0f, 27.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x154), 1,
                          301.0f, 27.0f, -100.0f);
    for (i = 0; i < 4; i++) {
        if (*(s32*)(param_1 + 0x1c) - 1 < i)
            *(u32*)(*(u32*)(param_1 + 0xc0) + i * 0x44 + 0x2ac) = 0;
        else
            CAMP_DRAW_CALC_SECOND(100.0f,
                                  (void*)(*(u32*)(param_1 + 0xc0) + (i + 10) * 0x44),
                                  1, 30.0f, 64.0f + (f32)(i * 0x55), -100.0f);
    }
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x550), 1,
                          104.0f, 61.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x594), 1,
                          124.0f, 219.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x83c), 1,
                          226.0f, 415.0f, -100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc0) + 0x880), 1,
                          439.0f, 415.0f, -100.0f);

    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4)), 2,
                          381.0f, 12.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x44), 2,
                          13.0f, 27.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x88), 2,
                          112.0f, 27.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0xcc), 2,
                          135.0f, 27.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x110), 2,
                          273.0f, 27.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x154), 2,
                          301.0f, 27.0f, 100.0f);
    for (i = 0; i < 4; i++) {
        if (*(s32*)(param_1 + 0x1c) - 1 < i)
            *(u32*)(*(u32*)(param_1 + 0xc4) + i * 0x44 + 0x2ac) = 0;
        else
            CAMP_DRAW_CALC_SECOND(100.0f,
                                  (void*)(*(u32*)(param_1 + 0xc4) + (i + 10) * 0x44),
                                  2, 610.0f, 64.0f + (f32)(i * 0x55), 100.0f);
    }
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x550), 2,
                          47.0f, 61.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x594), 2,
                          67.0f, 263.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x7f8), 2,
                          226.0f, 415.0f, 100.0f);
    CAMP_DRAW_CALC_SECOND(100.0f, (void*)(*(u32*)(param_1 + 0xc4) + 0x83c), 2,
                          561.0f, 415.0f, 100.0f);
}

// FUN_0014BCE0 NONMATCHING
void h_campDrawSocialList(int param_1)
{
    CampPair pair;
    CampBits tmp[12];
    s32 i;
    f32 y;

    pair.x = 13.0f;
    pair.y = 27.0f;
    tmp[0].u = *(u64*)&pair;
    tmp[1].u = tmp[0].u;
    tmp[1].f[0] += 0.0f;
    pair.x = 112.0f;
    tmp[2].u = *(u64*)&pair;
    tmp[3].u = tmp[2].u;
    tmp[3].f[0] += 0.0f;
    pair.x = 135.0f;
    tmp[4].u = *(u64*)&pair;
    tmp[5].u = tmp[4].u;
    tmp[5].f[0] += 0.0f;
    pair.x = 272.0f;
    tmp[6].u = *(u64*)&pair;
    tmp[7].u = tmp[6].u;
    tmp[7].f[0] += 0.0f;
    pair.x = 301.0f;
    tmp[8].u = *(u64*)&pair;
    tmp[9].u = tmp[8].u;
    tmp[9].f[0] += 0.0f;
    pair.x = 381.0f;
    pair.y = 12.0f;
    tmp[10].u = *(u64*)&pair;
    tmp[11].u = tmp[10].u;
    tmp[11].f[0] += 0.0f;

    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4)), 0, 2, 2,
                  tmp[11].u, tmp[10].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x44), 0, 2, 2,
                  tmp[1].u, tmp[0].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x88), 0, 2, 2,
                  tmp[3].u, tmp[2].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0xcc), 0, 2, 2,
                  tmp[5].u, tmp[4].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x110), 0, 2, 2,
                  tmp[7].u, tmp[6].u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x154), 0, 2, 2,
                  tmp[9].u, tmp[8].u, 0, 0, 0, 10);
    for (i = 0; i < 4; i++) {
        if (*(s32*)(param_1 + 0x1c) - 1 < i) {
            *(u32*)(*(u32 *)(param_1 + 0xc4) + i * 0x44 + 0x2ac) = 0;
        } else {
            y = (f32)(i * 0x55) + 64.0f;
            pair.x = 610.0f;
            pair.y = y;
            tmp[10].u = *(u64*)&pair;
            tmp[11].u = tmp[10].u;
            tmp[11].f[0] += 0.0f;
            func_0018bc10(100.0f,
                          (void*)(*(u32 *)(param_1 + 0xc4) + (i + 10) * 0x44),
                          0, 2, 2, tmp[11].u, tmp[10].u, 0, 0, 0, 10);
        }
    }
    pair.x = 47.0f;
    pair.y = 61.0f;
    tmp[0].u = *(u64*)&pair;
    tmp[1].u = tmp[0].u;
    tmp[1].f[0] += 0.0f;
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x550), 0, 2, 2,
                  tmp[1].u, tmp[0].u, 0, 0, 0, 10);
    pair.x = 272.0f;
    pair.y = 219.0f;
    tmp[2].u = *(u64*)&pair;
    tmp[3].u = tmp[2].u;
    tmp[3].f[0] += 0.0f;
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x594), 0, 2, 2,
                  tmp[3].u, tmp[2].u, 0, 0, 0, 10);
    pair.x = 226.0f;
    pair.y = 415.0f;
    tmp[4].u = *(u64*)&pair;
    tmp[5].u = tmp[4].u;
    tmp[5].f[0] += 0.0f;
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x7f8), 0, 2, 2,
                  tmp[5].u, tmp[4].u, 0, 0, 0, 10);
    pair.x = 561.0f;
    pair.y = 415.0f;
    tmp[6].u = *(u64*)&pair;
    tmp[7].u = tmp[6].u;
    tmp[7].f[0] += 0.0f;
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc4) + 0x83c), 0, 2, 2,
                  tmp[7].u, tmp[6].u, 0, 0, 0, 10);
}

// FUN_0014C290
void h_campDrawSocialEntry(int param_1,int param_2,int param_3)
{
    register void* parent;

    switch (param_2) {
    case 0:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x2d,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 1:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x21,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 2:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x24,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 3:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x22,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 4:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x24,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 5:
        campDrawSprite(parent, (void*)DAT_00833a50[0], 0x29,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 10:
    case 11:
    case 12:
    case 13:
        campDrawSprite(parent, (void*)DAT_00833a50[1], 6,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        break;
    case 0x14:
        FUN_00140e30(*(CampPair*)((u8*)param_1 + 0x38),
                     *(f32*)(param_1 + 0x24),
                     (void*)*(u32*)(param_3 + 0xac), *(s32*)(param_1 + 0x40));
        break;
    case 0x15:
        break;
    case 0x1e:
        campDrawSprite(parent, (void*)DAT_00833a50[2], 8,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        campDrawSpriteX(parent, (void*)DAT_00833a50[2], 4,
                        *(f32*)(param_1 + 0x38) + 16.0f,
                        *(u8*)(param_1 + 0x40),
                        *(f32*)(param_1 + 0x3c), *(f32*)(param_1 + 0x24));
        break;
    case 0x1f:
        campDrawSprite(parent, (void*)DAT_00833a50[0x55], 3,
                       *(u8*)(param_1 + 0x40),
                       *(f32*)(param_1 + 0x38), *(f32*)(param_1 + 0x3c),
                       *(f32*)(param_1 + 0x24));
        campDrawSpriteX(parent, (void*)DAT_00833a50[0x55], 5,
                        (*(f32*)(param_1 + 0x38) - 561.0f) + 459.0f,
                        *(u8*)(param_1 + 0x40),
                        *(f32*)(param_1 + 0x3c), *(f32*)(param_1 + 0x24));
        break;
    default:
        break;
    }
}

#pragma opt_loop_invariants on
// FUN_0014C5C0 NONMATCHING
u32 h_campUpdateNewItemTask(int param_1)

{
  s32 (**alloc_ptr)(u32, u32, u32);
  int alloc_i;
  u32 *puVar1;
  u32 *puVar2;
  s32 bVar3;
  u16 uVar4;
  s16 sVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  s32 lVar11;
  u32 uVar12;
  u32 uVar13;
  int iVar14;
  int *piVar15;
  s16 unaff_s0_lo;
  u32 uVar16;
  int iVar17;
  int iVar18;
  float in_f21;
  float fVar19;
  float unaff_f20;
  u8 auStack_4 [4];
  
  puVar1 = *(u32 **)(param_1 + 0x3c);
  if ((puVar1[0x19] != 0) && (lVar11 = func_0018b700((void*)(puVar1 + 0x18)), lVar11 != 0)) {
    FUN_0013bce0(puVar1[0x28]);
  }
  switch(*puVar1) {
  case 0:
    DAT_007cdf90 = 300;
    lVar11 = FUN_001016b0(puVar1[2]);
    if (lVar11 != 0) {
      uVar6 = FUN_00112420(FUN_00102100(puVar1[2],0,auStack_4));
      puVar1[0x2c] = uVar6;
      uVar6 = FUN_00112420(FUN_00102100(puVar1[2],1,auStack_4));
      puVar1[0x2d] = uVar6;
      uVar6 = FUN_00112420(FUN_00102100(puVar1[2],2,auStack_4));
      puVar1[0x2e] = uVar6;
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        DAT_00833a50[iVar17] = puVar1[iVar17 + 0x2c];
      }
      *puVar1 = 1;
    }
    break;
  case 1:
    lVar11 = FUN_00111f30(puVar1[0x2c]);
    if (((lVar11 != 0) && (lVar11 = FUN_00111f30(puVar1[0x2d]), lVar11 != 0)) &&
       (lVar11 = FUN_00111f30(puVar1[0x2e]), lVar11 != 0)) {
      uVar6 = (u32)func_0018b6d0(0x50);
      puVar1[0x2f] = uVar6;
      uVar6 = (u32)func_0018b6d0(0x28);
      puVar1[0x30] = uVar6;
      uVar6 = (u32)func_0018b6d0(0x28);
      puVar1[0x31] = uVar6;
      alloc_ptr = (s32 (**)(u32, u32, u32))DAT_00960184_abs;
      iVar17 = (*alloc_ptr)(1,0x978,0x40000);
      for (alloc_i = 0; alloc_i < 300; alloc_i = alloc_i + 1) {
        iVar9 = iVar17 + alloc_i * 8;
        *(u32 *)(iVar9 + 0xc) = 0xffffffff;
        *(u32 *)(iVar9 + 0x10) = 0;
      }
      puVar1[0x29] = iVar17;
      iVar17 = (*alloc_ptr)(1,0x2d70,0x40000);
      for (alloc_i = 0; alloc_i < 0x140; alloc_i = alloc_i + 1) {
        iVar9 = iVar17 + alloc_i * 0x24;
        *(u32 *)(iVar9 + 100) = 0xffffffff;
        *(u32 *)(iVar9 + 0x6c) = 0;
        *(u32 *)(iVar9 + 0x68) = 0xffffffff;
        *(u32 *)(iVar9 + 0x70) = 0;
      }
      puVar1[0x2a] = iVar17;
      iVar17 = (*alloc_ptr)(1,0x978,0x40000);
      for (alloc_i = 0; alloc_i < 300; alloc_i = alloc_i + 1) {
        iVar9 = iVar17 + alloc_i * 8;
        *(u32 *)(iVar9 + 0xc) = 0xffffffff;
        *(u32 *)(iVar9 + 0x10) = 0;
      }
      puVar1[0x2b] = iVar17;
      *puVar1 = 3;
    }
    break;
  case 2:
    {
      s32 case2_index;
      s32 case2_value;
      s16 case2_alpha;
      u32 case2_resource;
      case2_index = puVar1[1];
      if (case2_index < 8) {
        if (case2_index > 0) {
          if (case2_index < 8) {
            case2_value = case2_index * 300;
            if (case2_value < 0) {
              case2_value = case2_value + 7;
            }
            in_f21 = (float)(case2_value >> 3);
            unaff_f20 = 0.0f;
            case2_index = case2_index * 0xff;
            if (case2_index < 0) {
              case2_index = case2_index + 7;
            }
            case2_alpha = (s16)(case2_index >> 3);
          }
        }
        else {
          in_f21 = 0.0f;
          unaff_f20 = 0.0f;
          case2_alpha = 0;
        }
        if (DAT_007cdf60 == 0) {
          case2_index = 0;
        }
        else if (**(int **)(DAT_007cdf60 + 0x3c) == 3) {
          case2_index = (*(int **)(DAT_007cdf60 + 0x3c))[3];
        }
        else {
          case2_index = 0;
        }
        if (case2_index != 0) {
          uVar7 = 0xff - (int)case2_alpha;
          uVar16 = uVar7;
          if (0x18 < uVar7) {
            uVar16 = 0x19;
          }
          FUN_00114450(102.0f,in_f21,unaff_f20 + -87.0f,uVar7 | 0xffffff00,
                       uVar16 | 0x4fa4ff00,0x280,0x280);
        }
        FUN_0011bba0(0,0,102.0f,case2_alpha,0);
        case2_index = puVar1[1];
        if (case2_index < 6) {
          fVar19 = (float)((case2_index * 600) / 6);
          uVar13 = FUN_001158b0_typed(0,DAT_00833b78,0);
          case2_resource = uVar13;
          *(float *)(case2_resource + 0x2c) = 101.0f;
          *(float *)(case2_resource + 0x10) = fVar19 + 428.0f;
          *(float *)(case2_resource + 0x14) = 27.0f;
          *(char *)(case2_resource + 0x18) = (char)((case2_index * 0xff) / 6);
          *(u16 *)(case2_resource + 0x28) = 0;
          *(u16 *)(case2_resource + 0x2a) = 0;
          FUN_001127d0(uVar13,1);
          FUN_00115980(uVar13);
        }
        if (puVar1[1] == 0) {
          puVar2 = *(u32 **)(DAT_007cdf5c + 0x3c);
          FUN_0011da80(0x42c80000,puVar2);
          *puVar2 = 9;
          puVar2[1] = 0;
        }
        if (puVar1[1] == 4) {
          FUN_00121de0(DAT_007cdf54,9);
          FUN_00122710(DAT_007cdf58,9);
        }
        puVar1[1] = puVar1[1] + 1;
      }
      else {
        *puVar1 = 0;
      }
    }
    break;
  case 3:
    lVar11 = FUN_0011e380(DAT_007cdf50,9);
    if (lVar11 != 0) {
      iVar17 = puVar1[0x29];
      iVar10 = 0;
      for (iVar9 = 4000; iVar9 < 0x1080; iVar9 = iVar9 + 1) {
        sVar5 = func_00170760(1,(s16)iVar9);
        if (sVar5 != 0) {
          iVar18 = iVar17 + iVar10 * 8;
          *(int *)(iVar18 + 0xc) = iVar9;
          uVar16 = func_00170760(1,(s16)iVar9);
          *(u32 *)(iVar18 + 0x10) = uVar16 & 0xffff;
          iVar10 = iVar10 + 1;
        }
      }
      *(int *)(iVar17 + 0x96c) = iVar10;
      FUN_0013cc90(puVar1[0x2a]);
      iVar17 = puVar1[0x2b];
      iVar9 = 0;
      iVar10 = 0x1389;
      for (iVar18 = 0x1389; iVar18 < 0x1408; iVar18 = iVar18 + 1) {
        lVar11 = FUN_0016f190(iVar18 + -0x1188);
        if (lVar11 != 0) {
          iVar14 = iVar17 + iVar9 * 8;
          *(int *)(iVar14 + 0xc) = iVar10;
          *(u32 *)(iVar14 + 0x10) = 1;
          iVar9 = iVar9 + 1;
        }
        iVar10 = iVar10 + 1;
      }
      *(int *)(iVar17 + 0x96c) = iVar9;
      puVar1[3] = 1;
      puVar1[7] = 1;
      iVar17 = 0;
      while ((iVar17 < 3 && (sVar5 = FUN_0016dd60(iVar17), sVar5 != 0))) {
        sVar5 = FUN_0016dd60(iVar17);
        puVar1[puVar1[7] + 3] = (int)sVar5;
        puVar1[7] = puVar1[7] + 1;
        iVar17 = iVar17 + 1;
      }
      puVar1[0x14] = 0;
      iVar17 = 0;
      while ((iVar17 < 0xc && (lVar11 = FUN_00174960((s16)iVar17), lVar11 != 0))) {
        puVar1[iVar17 + 8] = iVar17;
        puVar1[0x14] = puVar1[0x14] + 1;
        iVar17 = iVar17 + 1;
      }
      FUN_00141660(puVar1);
      func_0018bc10(100.0f, (void*)(puVar1 + 0x18), 0, 2, 1, 0, 0, 0, 0, 0, 10);
      *puVar1 = 4;
    }
    break;
  case 4:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      if ((DAT_007e094e & 0x40) == 0) {
        if ((DAT_007e094e & 0x20) == 0) {
          bVar3 = true;
          if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {
            bVar3 = false;
          }
          if (bVar3) {
            *puVar1 = 0x10;
          }
          else if ((DAT_007e0952 & 0x8000) == 0 && (DAT_007e095a & 0x8000) == 0) {
            iVar17 = puVar1[0x29];
            FUN_0011abd0(*(u32 *)(iVar17 + 0x96c),5,iVar17 + 0x974,iVar17 + 0x970);
          }
          else {
            *puVar1 = 0x1d;
          }
        }
        else {
          FUN_0010a4e0(0,0,0,2);
          func_0018bc10(100.0f, (void*)(puVar1 + 0x18), 0, 2, 2, 0, 0, 0, 0, 0, 10);
          FUN_001432f0(puVar1);
          *puVar1 = 5;
        }
      }
      else {
        iVar17 = puVar1[0x29];
        if (*(int *)(iVar17 + 0x970) < *(int *)(iVar17 + 0x96c)) {
          DAT_007cdf94 = (u16)
                         *(u32 *)
                          ((*(int *)(iVar17 + 0x970) + *(int *)(iVar17 + 0x974)) * 8 + iVar17 + 0xc)
          ;
          iVar17 = (u32)func_00170e90(DAT_007cdf94);
          if ((*(int *)(iVar17 + 4) == 0) || (*(int *)(iVar17 + 4) == 2)) {
            uVar12 = FUN_0017bbb0(*(u16 *)(iVar17 + 8));
            if ((uVar12 & 4) == 0) {
              uVar4 = FUN_0017bb40(*(u16 *)(iVar17 + 8));
              *(u16 *)(puVar1 + 0x17) = uVar4;
              if (*(s16 *)(puVar1 + 0x17) != 3) {
                if (*(s16 *)(puVar1 + 0x17) == 0) {
                  puVar1[0x15] = 0;
                }
                else {
                  puVar1[0x15] = 0xfffffffe;
                }
                *puVar1 = 6;
              }
            }
            else {
              puVar1[0x16] = 0;
              *puVar1 = 9;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,8);
          }
        }
      }
    }
    break;
  case 5:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      return 0xffffffff;
    }
    break;
  case 6:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,10);
    if (lVar11 != 0) {
      FUN_00141fb0(puVar1);
      *puVar1 = 7;
    }
    break;
  case 7:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      iVar17 = puVar1[0x15];
      if ((DAT_007e094e & 0x40) == 0) {
        if ((DAT_007e094e & 0x20) == 0) {
          bVar3 = true;
          if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
            bVar3 = false;
          }
          if (bVar3) {
            if (iVar17 != -2) {
              if (iVar17 == 0) {
                if (((DAT_007e094e & 0x1000) != 0) || ((DAT_007e0958 & 0x1000) != 0)) {
                  puVar1[0x15] = puVar1[7] + -1;
                }
              }
              else {
                puVar1[0x15] = puVar1[0x15] + -1;
              }
            }
          }
          else if (((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) && (iVar17 != -2))
          {
            if (iVar17 == puVar1[7] + -1) {
              if (((DAT_007e094e & 0x4000) != 0) || ((DAT_007e0958 & 0x4000) != 0)) {
                puVar1[0x15] = 0;
              }
            }
            else {
              puVar1[0x15] = puVar1[0x15] + 1;
            }
          }
        }
        else {
          FUN_0010a4e0(0,0,0,2);
          *puVar1 = 8;
        }
      }
      else {
        iVar10 = puVar1[0x29];
        iVar10 = (u32)func_00170e90(*(u16 *)
                               ((*(int *)(iVar10 + 0x970) + *(int *)(iVar10 + 0x974)) * 8 + iVar10 +
                               0xc));
        if (*(int *)(iVar10 + 8) == 0xe9) {
          lVar11 = FUN_001bff50();
          if (lVar11 != 0) {
            iVar17 = puVar1[0x29];
            uVar4 = *(u16 *)
                     ((*(int *)(iVar17 + 0x970) + *(int *)(iVar17 + 0x974)) * 8 + iVar17 + 0xc);
            sVar5 = func_00170760(1,uVar4);
            func_00170860(1,uVar4,sVar5 + -1);
            FUN_0016f1f0(0x1417,1);
            FUN_0010a4e0(0,0,0,1);
            return 0xffffffff;
          }
          FUN_0010a4e0(0,0,0,8);
        }
        else if (*(s16 *)(puVar1 + 0x17) == 0) {
          lVar11 = FUN_0013be50(puVar1[0x29],puVar1[0x15]);
          if (lVar11 == 0) {
            FUN_0010a4e0(0,0,0,8);
          }
          else {
            FUN_0010a4e0(1,0,3,1);
            *puVar1 = 8;
          }
        }
        else {
          lVar11 = FUN_0013be50(puVar1[0x29],puVar1[0x15]);
          if (lVar11 == 0) {
            FUN_0010a4e0(0,0,0,8);
          }
          else {
            FUN_0010a4e0(1,0,3,1);
            *puVar1 = 8;
          }
        }
      }
      if (iVar17 != puVar1[0x15]) {
        FUN_0010a4e0(0,0,0,0);
        FUN_00143a00(puVar1,iVar17);
      }
    }
    break;
  case 8:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,9);
    if (lVar11 != 0) {
      FUN_00142930(puVar1);
      *puVar1 = 4;
    }
    break;
  case 9:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,10);
    if (lVar11 != 0) {
      FUN_00143ee0(puVar1);
      *puVar1 = 10;
    }
    break;
  case 10:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      iVar17 = puVar1[0x16];
      if ((DAT_007e094e & 0x40) == 0) {
        if ((DAT_007e094e & 0x20) == 0) {
          bVar3 = true;
          if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
            bVar3 = false;
          }
          if (bVar3) {
            if (iVar17 == 0) {
              if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
                puVar1[0x16] = puVar1[0x14] + -1;
              }
            }
            else {
              puVar1[0x16] = puVar1[0x16] + -1;
            }
          }
          else if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) {
            if (iVar17 == puVar1[0x14] + -1) {
              if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
                puVar1[0x16] = 0;
              }
            }
            else {
              puVar1[0x16] = puVar1[0x16] + 1;
            }
          }
        }
        else {
          FUN_0010a4e0(0,0,0,2);
          *puVar1 = 0xb;
        }
      }
      else {
        iVar10 = (u32)func_00170e90(DAT_007cdf94);
        uVar13 = FUN_00174a90(*(u16 *)(puVar1 + 0x16));
        bVar3 = false;
        lVar11 = FUN_0017bf70(*(u16 *)(iVar10 + 8));
        if (lVar11 != 0) {
          for (uVar16 = 0; (int)uVar16 < 5; uVar16 = uVar16 + 1) {
            uVar7 = FUN_0017bfa0(*(u16 *)(iVar10 + 8),uVar16 & 0xff);
            uVar7 = uVar7 & 0xff;
            if (uVar7 != 0) {
              uVar8 = FUN_00173580(uVar13,uVar16 & 0xffff);
              uVar8 = uVar8 & 0xff;
              if (uVar8 != 99) {
                if (99 < uVar8 + uVar7) {
                  uVar7 = uVar7 + (uVar8 - 99);
                }
                iVar9 = (int)uVar13 + uVar16;
                *(char *)(iVar9 + 0x21) = *(char *)(iVar9 + 0x21) + (char)uVar7;
                bVar3 = true;
              }
            }
          }
          if (bVar3) {
            iVar10 = puVar1[0x29];
            iVar18 = *(int *)(iVar10 + 0x970) + *(int *)(iVar10 + 0x974);
            iVar9 = iVar18 * 8 + iVar10;
            piVar15 = (int *)(iVar9 + 0x10);
            iVar9 = *(int *)(iVar9 + 0x10);
            if (iVar9 == 1) {
              func_00170860(1,DAT_007cdf94,0);
              for (; iVar18 < *(int *)(iVar10 + 0x96c) + -1; iVar18 = iVar18 + 1) {
                iVar9 = iVar10 + iVar18 * 8;
                *(u32 *)(iVar9 + 0xc) = *(u32 *)(iVar9 + 0x14);
                *(u32 *)(iVar9 + 0x10) = *(u32 *)(iVar9 + 0x18);
              }
              *(u32 *)(*(int *)(iVar10 + 0x96c) * 8 + iVar10 + 0xc) = 0xffffffff;
              *(u32 *)(*(int *)(iVar10 + 0x96c) * 8 + iVar10 + 0x10) = 0;
              iVar9 = *(int *)(iVar10 + 0x96c);
              iVar18 = iVar9 + -1;
              *(int *)(iVar10 + 0x96c) = iVar18;
              if (iVar18 == 0) {
                *(u32 *)(iVar10 + 0x974) = 0;
                *(u32 *)(iVar10 + 0x970) = 0;
              }
              else if (*(int *)(iVar10 + 0x970) < iVar18) {
                if (iVar18 < 5) {
                  *(u32 *)(iVar10 + 0x974) = 0;
                }
                else if (iVar9 + -6 < *(int *)(iVar10 + 0x974)) {
                  *(int *)(iVar10 + 0x974) = iVar9 + -6;
                }
              }
              else {
                *(int *)(iVar10 + 0x970) = iVar9 + -2;
                *(u32 *)(iVar10 + 0x974) = 0;
              }
            }
            else {
              *piVar15 = iVar9 + -1;
              func_00170860(1,DAT_007cdf94,*(u16 *)piVar15);
            }
          }
        }
        if (bVar3) {
          FUN_0010a4e0(1,0,3,1);
          *puVar1 = 0xb;
        }
        else {
          FUN_0010a4e0(0,0,0,8);
        }
      }
      if (puVar1[0x16] != iVar17) {
        FUN_0010a4e0(0,0,0,0);
        FUN_00145350(puVar1,iVar17);
      }
    }
    break;
  case 0xb:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,9);
    if (lVar11 != 0) {
      FUN_00144910(puVar1);
      *puVar1 = 4;
    }
    break;
  case 0xc:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,9);
    if (lVar11 != 0) {
      FUN_001474f0(puVar1);
      *puVar1 = 0xd;
    }
    break;
  case 0xd:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x30] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 4;
    }
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    break;
  case 0xe:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,9);
    if (lVar11 != 0) {
      h_campDrawPersonaOverview((int)puVar1);
      *puVar1 = 0xf;
    }
    break;
  case 0xf:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x31] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 4;
    }
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    break;
  case 0x10:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,0xb);
    if (lVar11 != 0) {
      FUN_00146710(puVar1);
      *puVar1 = 0x11;
    }
    break;
  case 0x11:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 0x12;
    }
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    break;
  case 0x12:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x30] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      if ((DAT_007e094e & 0x20) == 0) {
        if ((DAT_007e0952 & 0x80) == 0) {
          if ((DAT_007e0952 & 0x8000) == 0 && (DAT_007e095a & 0x8000) == 0) {
            if ((DAT_007e0952 & 0x2000) == 0 && (DAT_007e095a & 0x2000) == 0) {
              iVar17 = puVar1[0x2a];
              FUN_0011abd0(*(u32 *)(iVar17 + 0x2d64),5,iVar17 + 0x2d6c,iVar17 + 0x2d68);
            }
            else {
              *puVar1 = 0x19;
            }
          }
          else {
            *puVar1 = 0xc;
          }
        }
        else {
          FUN_0010a4e0(0,0,0,1);
          *puVar1 = 0x16;
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        func_0018bc10(100.0f, (void*)(puVar1 + 0x18), 0, 2, 2, 0, 0, 0, 0, 0, 10);
        h_campDrawStatusOverview((int)puVar1);
        *puVar1 = 0x13;
      }
    }
    break;
  case 0x16:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    iVar17 = puVar1[0x2a];
    lVar11 = (s32)*(int *)((*(int *)(iVar17 + 0x2d6c) + *(int *)(iVar17 + 0x2d68)) * 0x24 + iVar17
                           + 0x68);
    sVar5 = FUN_0016cb80(1,0);
    if ((((lVar11 == sVar5) || (sVar5 = FUN_0016cb80(1,1), lVar11 == sVar5)) ||
        (sVar5 = FUN_0016cb80(1,2), lVar11 == sVar5)) ||
       (sVar5 = FUN_0016cb80(1,3), lVar11 == sVar5)) {
      FUN_003c7430(6);
      *puVar1 = 0x17;
    }
    else {
      FUN_003c7430(5);
      FUN_003c74e0(0);
      FUN_003c7560(0);
      *puVar1 = 0x18;
    }
    break;
  case 0x17:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_003c7850();
    if (lVar11 == 0) {
      FUN_003c7700();
      *puVar1 = 0x12;
    }
    break;
  case 0x18:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_003c7850();
    if (lVar11 == 0) {
      lVar11 = FUN_003c7610();
      if ((lVar11 != 1) && (lVar11 == 0)) {
        FUN_00141590(puVar1[0x2a]);
      }
      FUN_003c7700();
      *puVar1 = 0x12;
    }
    break;
  case 0x13:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x30] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      return 0xffffffff;
    }
    break;
  case 0x14:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,0xb);
    if (lVar11 != 0) {
      h_campDrawPersonaList((int)puVar1);
      *puVar1 = 0x15;
    }
    break;
  case 0x15:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x31] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 0x12;
    }
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    break;
  case 0x19:
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,0xc);
    if (lVar11 != 0) {
      h_campDrawStatusComparison((int)puVar1);
      *puVar1 = 0x1a;
    }
    break;
  case 0x1a:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x30] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x30] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawListEntry(puVar1[0x30] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x30] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 0x1b;
    }
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
    break;
  case 0x1b:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x31] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      if ((DAT_007e094e & 0x20) == 0) {
        bVar3 = true;
        if (((DAT_007e0952 & 0x8000) == 0) && ((DAT_007e095a & 0x8000) == 0)) {
          bVar3 = false;
        }
        if (bVar3) {
          *puVar1 = 0x14;
        }
        else if ((DAT_007e0952 & 0x2000) == 0 && (DAT_007e095a & 0x2000) == 0) {
          iVar17 = puVar1[0x2b];
          FUN_0011abd0(*(u32 *)(iVar17 + 0x96c),5,iVar17 + 0x974,iVar17 + 0x970);
        }
        else {
          *puVar1 = 0xe;
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        func_0018bc10(100.0f, (void*)(puVar1 + 0x18), 0, 2, 2, 0, 0, 0, 0, 0, 10);
        h_campDrawSocialList((int)puVar1);
        *puVar1 = 0x1c;
      }
    }
    break;
  case 0x1c:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44));
        if (lVar11 != 0) {
          h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
        }
        iVar10 = puVar1[0x31] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      return 0xffffffff;
    }
    break;
  case 0x1d:
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44)), lVar11 != 0)) {
        FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
      }
    }
    lVar11 = FUN_0011e380(DAT_007cdf50,0xc);
    if (lVar11 != 0) {
      h_campDrawPersonaEquipment((int)puVar1);
      *puVar1 = 0x1e;
    }
    break;
  case 0x1e:
    bVar3 = true;
    for (iVar17 = 0; iVar17 < 0x50; iVar17 = iVar17 + 1) {
      if (*(int *)(puVar1[0x2f] + iVar17 * 0x44 + 4) != 0) {
        lVar11 = func_0018b700((void*)(puVar1[0x2f] + iVar17 * 0x44));
        if (lVar11 != 0) {
          FUN_00145520(puVar1[0x2f] + iVar17 * 0x44,iVar17,puVar1);
        }
        iVar10 = puVar1[0x2f] + iVar17 * 0x44;
        if (*(int *)(iVar10 + 0x18) != *(int *)(iVar10 + 0x20)) {
          bVar3 = false;
        }
      }
    }
    if (bVar3) {
      *puVar1 = 0x1b;
    }
    for (iVar17 = 0; iVar17 < 0x28; iVar17 = iVar17 + 1) {
      if ((*(int *)(puVar1[0x31] + iVar17 * 0x44 + 4) != 0) &&
         (lVar11 = func_0018b700((void*)(puVar1[0x31] + iVar17 * 0x44)), lVar11 != 0)) {
        h_campDrawSocialEntry(puVar1[0x31] + iVar17 * 0x44,iVar17,(int)puVar1);
      }
    }
  }
  return 0;
}
#pragma opt_loop_invariants off

// FUN_0014EE80
KwlnTask* h_campCreateNewItemTask(KwlnTask* parent, u32 priority)
{
    KwlnTask* task;
    void* allocation;

    allocation = (*campAlloc)(1, 0xc8, 0x40000);
    if (allocation == NULL) {
        return NULL;
    }
    task = campTaskCreate(parent, (const char*)DAT_005dbc50, priority,
                          (void* (*)(KwlnTask*))h_campUpdateNewItemTask,
                          h_campItemDestroyNewItemTask, allocation);
    if (task == NULL) {
        return NULL;
    }
    *(u32*)((u8*)allocation + 8) = FUN_00100d80(DAT_005dbc60, 1);
    *(u32*)allocation = 2;
    return task;
}

// FUN_0014EF60 NONMATCHING
void h_campDrawItemFrame(int param_1)
{
    f32 fVar1;
    CampBits start;
    CampBits end;

    start.f[0] = 47.0f;
    start.f[1] = -14.0f;
    func_0018bc10(100.0f, (void*)(*(u32 *)(param_1 + 0xc)), 0, 2, 1,
                  start.u, start.u, 0, 0, 0, 10);
    fVar1 = (f32)(*(int *)(param_1 + 4) * 0x21) + 124.0f;
    end.f[0] = 590.0f;
    end.f[1] = fVar1 - 300.0f;
    start.f[0] = 590.0f;
    start.f[1] = fVar1;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x88), 0, 2, 1,
                  end.u, start.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x44), 0, 2, 1,
                  start.u, end.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0xcc), 0, 2, 1,
                  CAMP_PAIR_FLOATS(126.0f, 703.0f),
                  CAMP_PAIR_FLOATS(126.0f, 402.0f), 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x150) = 0;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x110), 0, 2, 0,
                  CAMP_PAIR_FLOATS(-285.0f, 321.0f),
                  CAMP_PAIR_FLOATS(15.0f, 321.0f), 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x194) = 0;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x154), 0, 2, 1,
                  CAMP_PAIR_FLOATS(-176.0f, 354.0f),
                  CAMP_PAIR_FLOATS(124.0f, 354.0f), 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x194) = 0;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x198), 0, 2, 1,
                  CAMP_PAIR_FLOATS(384.0f, 47.0f),
                  CAMP_PAIR_FLOATS(384.0f, 47.0f), 0, 0, 0, 10);
    start.f[0] = 392.0f;
    start.f[1] = 384.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x1dc), 0, 2, 1,
                  start.u, start.u, 0, 0, 0, 10);
}

// FUN_0014F320 NONMATCHING
void h_campDrawItemFrameSelected(int param_1)
{
    CampBits pair;
    CampBits first;
    CampBits second;

    pair.u = *(u64 *)(*(int *)(param_1 + 0xc) + 0x30);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc)), 0, 2, 2,
                  pair.u, pair.u, 0, 0, 0, 10);
    first.f[0] = 590.0f;
    first.f[1] = (f32)(*(int *)(param_1 + 4) * 0x21) + 124.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x88), 0, 2, 2,
                  first.u, first.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x44), 0, 2, 2,
                  CAMP_PAIR_FLOATS(125.0f, 394.0f),
                  CAMP_PAIR_FLOATS(125.0f, 394.0f), 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0xcc), 0, 2, 2,
                  CAMP_PAIR_FLOATS(126.0f, 402.0f),
                  CAMP_PAIR_FLOATS(126.0f, 402.0f), 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x150) = 0;
    first.f[0] = 321.0f;
    first.f[1] = 126.0f;
    second.f[0] = 321.0f;
    second.f[1] = 614.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x110), 0, 2, 2,
                  first.u, second.u, 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x194) = 0;
    first.f[0] = 354.0f;
    first.f[1] = 124.0f;
    second.f[0] = 354.0f;
    second.f[1] = 726.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x154), 0, 2, 2,
                  first.u, second.u, 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x194) = 0;
    first.f[0] = 47.0f;
    first.f[1] = 384.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x198), 0, 2, 2,
                  first.u, first.u, 0, 0, 0, 10);
    *(u32 *)(*(int *)(param_1 + 0xc) + 0x194) = 0;
    first.f[0] = 392.0f;
    first.f[1] = 384.0f;
    func_0018bc10(100.0f, (void*)(*(int *)(param_1 + 0xc) + 0x1dc), 0, 2, 2,
                  first.u, first.u, 0, 0, 0, 10);
}


#pragma opt_loop_invariants on
// FUN_0014F680
u32 h_campIsSocialLinkAvailable(s32 param_1, s32 param_2)
{
    CampSocialLinkRecord* entry;
    u8* socialEntry;
    s32 second;
    s32 index1;
    s32 index2;

    second = param_2;
    param_2 = (s32)(uintptr_t)DAT_007cdfb8;
    for (index1 = 0; index1 < 9999; index1++) {
        entry = (CampSocialLinkRecord*)(uintptr_t)param_2 + index1;
        if (entry->first == 0) {
            break;
        }
        if ((param_1 == entry->first) && (second == entry->second)) {
            if (entry->flag == 0) {
                return 1;
            }
            if (FUN_0016f190(entry->flag) != 0) {
                return 1;
            }
            param_2 = (s32)(uintptr_t)DAT_007cdfb8;
            entry = (CampSocialLinkRecord*)(uintptr_t)param_2 + index1;
            if ((entry->first == 3) && (entry->type == 0x13)) {
                return 1;
            }
        }
    }
    for (index2 = 0; index2 < 0x100; index2++) {
        socialEntry = (u8*)FUN_0017ae30(index2);
        if (socialEntry[0] == 0) {
            break;
        }
        if ((socialEntry[0] == param_1) && (socialEntry[1] == second)) {
            return 1;
        }
    }
    return 0;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_0014F7D0 NONMATCHING
u32 h_campUpdateSystemMenuTask(int param_1)

{
  u32 uVar2;
  int iVar3;
  s32 lVar4;
  u64 uVar5;
  s32 bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  u64 uStack_118;
  u64 uStack_40;
  u64 uStack_20;
  CampBits pair;
  CampBits tmp70;
  CampBits tmp78;
  CampBits tmp80;
  CampBits tmp88;
  CampBits tmp90;
  CampBits tmp98;
  CampBits tmpa0;
  CampBits tmpa8;
  CampBits tmpb0;
  CampBits tmpb8;
  CampBits tmpc0;
  CampBits tmpc8;
  CampBits tmpd0;
  CampBits tmpd8;
  CampBits tmpe0;
  CampBits tmpe8;
  CampBits tmpf0;
  CampBits tmpf8;
  CampBits tmp100;
  CampBits tmp108;
  CampBits tmp110;
  CampBits tmp118;
  CampBits tmp120;
  CampBits tmp128;
  CampBits tmp130;
  CampBits tmp138;
  CampBits tmp140;
  CampBits tmp148;
  CampBits tmp150;
  CampBits tmp158;
  CampBits tmp160;
  CampBits tmp178;
  CampBits tmp180;
  CampBits tmp188;
  CampBits tmp190;
  CampBits tmp198;
  CampBits tmp1a8;
  int iStack_8;
  u8 auStack_4 [4];
  u32 *puVar1;
  
  puVar1 = *(u32 **)(param_1 + 0x3c);
  switch(*puVar1) {
  case 0:
    lVar4 = FUN_0011e380(DAT_007cdf50,6);
    if (lVar4 == 0) {
      return 0;
    }
    lVar4 = FUN_0017d800();
    if (lVar4 == 0) {
      uVar2 = FUN_0010c1a0(0,0x5db0a0,0,0,0,0,0,0);
      puVar1[7] = uVar2;
    }
    else {
      uVar2 = FUN_0010c1a0(0,0x5db050,0,0,0,0,0,0);
      puVar1[7] = uVar2;
    }
    uVar2 = (u32)func_0018b6d0(10);
    puVar1[3] = uVar2;
    uVar2 = (u32)func_0018b6d0(100);
    puVar1[4] = uVar2;
    uVar2 = FUN_00100d80(0x5dbca0,0);
    puVar1[9] = uVar2;
    uVar2 = FUN_00100d80(0x5dbcc0,0);
    puVar1[10] = uVar2;
    uVar2 = FUN_00100d80(0x5dbce0,1);
    puVar1[0xb] = uVar2;
    *puVar1 = 1;
    break;
  case 1:
    if (puVar1[8] == 0) {
      uVar2 = FUN_0010c3a0(puVar1[7],&iStack_8,0);
      puVar1[8] = uVar2;
      if (iStack_8 == 0) {
        puVar1[8] = 0;
        return 0;
      }
    }
    lVar4 = FUN_001016b0(puVar1[9]);
    if (((lVar4 != 0) && (lVar4 = FUN_001016b0(puVar1[10]), lVar4 != 0)) &&
       (lVar4 = FUN_001016b0(puVar1[0xb]), lVar4 != 0)) {
      FUN_003c7d80(0xc,*(u32 *)(puVar1[9] + 0x110));
      FUN_003c7d80(8,*(u32 *)(puVar1[10] + 0x110));
      uVar5 = FUN_00102100(puVar1[0xb],0,auStack_4);
      uVar2 = FUN_00112420(uVar5);
      puVar1[5] = uVar2;
      uVar5 = FUN_00102100(puVar1[0xb],1,auStack_4);
      uVar2 = FUN_00112420(uVar5);
      puVar1[6] = uVar2;
      *puVar1 = 2;
    }
    break;
  case 2:
    lVar4 = FUN_00111f30(puVar1[5]);
    if ((lVar4 != 0) && (lVar4 = FUN_00111f30(puVar1[6]), lVar4 != 0)) {
      h_campDrawItemFrame((int)puVar1);
      func_0018bc10(100.0f, (void*)(puVar1[3]), 0, 2, 1, 0xc1600000423c0000, 0xc1600000423c0000, 0, 0, 0, 10);
      *puVar1 = 3;
    }
    break;
  case 3:
    if (puVar1[0xc] != 0) {
      if ((DAT_007e094e & 0x40) == 0) {
        if ((DAT_007e094e & 0x20) == 0) {
          bVar6 = true;
          if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
            bVar6 = false;
          }
          if (bVar6) {
            lVar4 = FUN_0017d800();
            if (lVar4 == 0) {
              if (puVar1[1] == 0) {
                if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
                  FUN_0010a4e0(0,0,0,0);
                  puVar1[1] = 5;
                }
              }
              else {
                FUN_0010a4e0(0,0,0,0);
                puVar1[1] = puVar1[1] + -1;
              }
            }
            else if (puVar1[1] == 4) {
              if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[1] = 5;
              }
            }
            else {
              FUN_0010a4e0(0,0,0,0);
              puVar1[1] = puVar1[1] + -1;
            }
          }
          else if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) {
            lVar4 = FUN_0017d800();
            if (lVar4 == 0) {
              if (puVar1[1] == 5) {
                if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
                  FUN_0010a4e0(0,0,0,0);
                  puVar1[1] = 0;
                }
              }
              else {
                FUN_0010a4e0(0,0,0,0);
                puVar1[1] = puVar1[1] + 1;
              }
            }
            else if (puVar1[1] == 5) {
              if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[1] = 4;
              }
            }
            else {
              FUN_0010a4e0(0,0,0,0);
              puVar1[1] = puVar1[1] + 1;
            }
          }
        }
        else {
          FUN_0010a4e0(0,0,0,2);
          *puVar1 = 4;
        }
      }
      else {
        FUN_0010a4e0(0,0,0,1);
        switch(puVar1[1]) {
        case 0:
          *puVar1 = 0x1a;
          break;
        case 1:
          *puVar1 = 0x15;
          break;
        case 2:
          *puVar1 = 0x10;
          break;
        case 3:
          *puVar1 = 0xb;
          break;
        case 4:
          *puVar1 = 6;
          break;
        case 5:
          FUN_003c7430(7);
          FUN_003c74e0(0);
          FUN_003c7560(1);
          *puVar1 = 0x1f;
        }
      }
      fVar10 = (float)(puVar1[1] * 0x21) + 124.0f;
      uStack_20 = CAMP_PAIR_FLOAT_HIGH(fVar10 - 300.0f,0x44138000);
      func_0018bc10(100.0f, (void*)(puVar1[3] + 0x88), 0, 2, 1, uStack_20,
                    CAMP_PAIR_FLOAT_HIGH(fVar10,0x44138000), 0, 0, 0, 10);
    }
    uVar2 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    puVar1[0xc] = uVar2;
    break;
  case 0x1f:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    lVar4 = FUN_003c7850();
    if (lVar4 == 0) {
      lVar4 = FUN_003c7610();
      if (lVar4 == 0) {
        *puVar1 = 0x20;
      }
      else {
        *puVar1 = 3;
      }
      FUN_003c7700();
    }
    break;
  case 0x20:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    puVar1[0x5e] = 0;
    FUN_0016f1f0(0x141d,1);
    *puVar1 = 0x21;
    break;
  case 0x21:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    FUN_00113a30(0.0f,0.0f,0.0f,(puVar1[0x5e] * 0xff) / 10 | 0xf1f2800,0x280,0x1c0);
    iVar3 = puVar1[0x5e];
    puVar1[0x5e] = iVar3 + 1;
    if (9 < iVar3 + 1) {
      puVar1[0x5e] = 10;
      FUN_0017f990();
      FUN_001ba8d0();
    }
    break;
  case 4:
    pair.u = *(u64 *)(puVar1[3] + 0x30);
    func_0018bc10(100.0f, (void*)(puVar1[3]), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    pair.u = CAMP_PAIR_FLOAT_HIGH((float)(puVar1[1] * 0x21) + 124.0f,0x44138000);
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x88), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42fa000043c50000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x44), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42fc000043c90000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0xcc), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    *(u32 *)(puVar1[3] + 0x150) = 0;
    pair.u = 0x4170000043a08000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x110), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    *(u32 *)(puVar1[3] + 0x194) = 0;
    pair.u = 0x42f8000043b18000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x154), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    *(u32 *)(puVar1[3] + 0x194) = 0;
    pair.u = 0x43c08000423c0000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x198), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    *(u32 *)(puVar1[3] + 0x194) = 0;
    pair.u = 0x43c0800043c40000ULL;
    func_0018bc10(100.0f, (void*)(puVar1[3] + 0x1dc), 0, 2, 2, pair.u, pair.u, 0, 0, 0, 10);
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    *puVar1 = 5;
    break;
  case 5:
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      return 0xffffffff;
    }
    iVar3 = puVar1[3];
    *(u32 *)(iVar3 + 0x28) = *(u32 *)(iVar3 + 0x30);
    *(u32 *)(iVar3 + 0x2c) = *(u32 *)(iVar3 + 0x34);
    break;
  case 6:
    puVar1[0x55] = 0;
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    h_campDrawItemFrameSelected((int)puVar1);
    pair.u = 0x4357000041a80000ULL;
    tmp70.u = pair.u;
    tmp70.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 1, tmp70.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x43830000424c0000ULL;
    tmp78.u = pair.u;
    tmp78.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 1, tmp78.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 1, 0x42b8000042ae0000, 0x42b8000042ae0000, 0, 0, 0, 10);
    pair.u = 0x42b8000042ae0000ULL;
    tmp80.u = pair.u;
    tmp80.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 1, tmp80.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 1, 0x42b8000043c20000, 0x42b8000043c20000, 0, 0, 0, 10);
    pair.u = 0x42b8000043c20000ULL;
    tmp88.u = pair.u;
    tmp88.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 1, tmp88.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42ba000042be0000ULL;
    tmp90.u = pair.u;
    tmp90.f[1] += 200.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 1, tmp90.u, pair.u, 0, 0, 0, 10);
    for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
      uVar2 = FUN_0016f190(iVar3 + 0x183);
      puVar1[iVar3 + 0x56] = uVar2;
    }
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 1, 0x43c0800043c40000, 0x43c0800043c40000, 0, 0, 0, 10);
    puVar1[0xc] = 0;
    *puVar1 = 7;
    break;
  case 7:
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      *puVar1 = 8;
    }
    FUN_00156140(puVar1[4],puVar1 + 5,puVar1[0x55],puVar1 + 0x56);
    break;
  case 8:
    if (puVar1[0xc] != 0) {
      if ((DAT_007e094e & 0x40) == 0) {
        if ((DAT_007e094e & 0x20) == 0) {
          bVar6 = true;
          if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
            bVar6 = false;
          }
          if (bVar6) {
            if (puVar1[0x55] == 0) {
              if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[0x55] = 7;
              }
            }
            else {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x55] = puVar1[0x55] + -1;
            }
          }
          else if ((DAT_007e0952 & 0x4000) == 0 && (DAT_007e095a & 0x4000) == 0) {
            if ((DAT_007e094e & 0x2000) == 0 && (DAT_007e0958 & 0x2000) == 0) {
              if (((DAT_007e094e & 0x8000) != 0 || (DAT_007e0958 & 0x8000) != 0) &&
                 (puVar1[0x55] != 7)) {
                if (puVar1[puVar1[0x55] + 0x56] == 0) {
                  FUN_0010a4e0(0,0,0,5);
                }
                if ((puVar1[0x55] == 0) && (puVar1[0x56] == 0)) {
                  FUN_00103c30(10,0x96,10,0);
                }
                puVar1[puVar1[0x55] + 0x56] = 1;
              }
            }
            else if ((puVar1[0x55] != 7) && (puVar1[puVar1[0x55] + 0x56] != 0)) {
              FUN_0010a4e0(0,0,0,5);
              puVar1[puVar1[0x55] + 0x56] = 0;
            }
          }
          else if (puVar1[0x55] == 7) {
            if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x55] = 0;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x55] = puVar1[0x55] + 1;
          }
        }
        else {
          FUN_0010a4e0(0,0,0,2);
          *puVar1 = 9;
        }
      }
      else if (puVar1[0x55] == 7) {
        FUN_0010a4e0(0,0,0,1);
        for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
          if (iVar3 == 2) {
            if (puVar1[0x57] == 0) {
              FUN_0016f1f0(0x185,0);
            }
            else {
              FUN_0016f1f0(0x185,puVar1[0x58]);
            }
          }
          else {
            FUN_0016f1f0(iVar3 + 0x183,puVar1[iVar3 + 0x56]);
          }
        }
        lVar4 = FUN_0016f190(0x183);
        if (lVar4 == 0) {
          FUN_00103cb0();
        }
        *puVar1 = 9;
      }
    }
    uVar2 = FUN_00156140(puVar1[4],puVar1 + 5,puVar1[0x55],puVar1 + 0x56);
    puVar1[0xc] = uVar2;
    break;
  case 9:
    FUN_00156140(puVar1[4],puVar1 + 5,puVar1[0x55],puVar1 + 0x56);
    campDrawItemFrameAlias((int)puVar1);
    pair.u = 0x4357000041a80000ULL;
    tmp98.u = pair.u;
    tmp98.f[1] += 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 2, tmp98.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x43830000424c0000ULL;
    tmpa0.u = pair.u;
    tmpa0.f[1] += 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 2, tmpa0.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 2, 0x42b8000042ae0000, 0x42b8000042ae0000, 0, 0, 0, 10);
    pair.u = 0x42b8000042ae0000ULL;
    tmpa8.u = pair.u;
    tmpa8.f[1] += 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 2, tmpa8.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 2, 0x42b8000043c20000, 0x42b8000043c20000, 0, 0, 0, 10);
    pair.u = 0x42b8000043c20000ULL;
    tmpb0.u = pair.u;
    tmpb0.f[1] += 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 2, tmpb0.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 2, 0x42ba000042be0000, 0x42ba000042be0000, 0, 0, 0, 10);
    *puVar1 = 10;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 2, 0x43c0800043c40000, 0x43c0800043c40000, 0, 0, 0, 10);
    break;
  case 10:
    lVar4 = FUN_00156140(puVar1[4],puVar1 + 5,puVar1[0x55],puVar1 + 0x56);
    if (lVar4 != 0) {
      *puVar1 = 3;
    }
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    break;
  case 0xb:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    h_campDrawItemFrameSelected((int)puVar1);
    puVar1[0x4f] = 0;
    puVar1[0x4e] = 0;
    iVar8 = 0;
    for (iVar3 = 0; iVar3 < 0x40; iVar3 = iVar3 + 1) {
      lVar4 = FUN_0016f190(iVar3 + 0x290);
      if (lVar4 != 0) {
        puVar1[iVar8 + 0xd] = iVar3;
        iVar8 = iVar8 + 1;
      }
    }
    puVar1[0x4d] = iVar8;
    puVar1[0x4f] = 0;
    pair.u = 0x4284000041a80000ULL;
    tmpb8.u = pair.u;
    tmpb8.f[1] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 1, tmpb8.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 1, 0x42c0000042100000, 0x42c0000042100000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 1, 0x4306000042040000, 0x4306000042040000, 0, 0, 0, 10);
    pair.u = 0x43aa800043988000ULL;
    tmpc0.u = pair.u;
    tmpc0.f[0] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 1, tmpc0.u, pair.u, 0, 0, 0, 10);
    fVar10 = (float)(puVar1[0x4f] * 0x23) + 599.0f;
    pair.u = CAMP_PAIR_WORD_HIGH(0x42ae0000,fVar10);
    tmpc8.u = pair.u;
    tmpc8.f[0] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 1, tmpc8.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42be000043b18000ULL;
    tmpd0.u = pair.u;
    tmpd0.f[1] += 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 1, tmpd0.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 1, 0x4383000044190000, 0x4383000044190000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 1, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0xc;
    break;
  case 0xc:
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      *puVar1 = 0xd;
    }
    FUN_00155710(puVar1[4],puVar1 + 5,puVar1 + 0xd,puVar1[0x4d],puVar1[0x4e],puVar1[0x4f]);
    puVar1[0xc] = 0;
    break;
  case 0xd:
    if (puVar1[0xc] != 0) {
      if ((DAT_007e094e & 0x20) == 0) {
        bVar6 = true;
        if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
          bVar6 = false;
        }
        if (bVar6) {
          iVar3 = puVar1[0x4f];
          if ((iVar3 == 0) && (puVar1[0x4e] == 0)) {
            if (((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) &&
               (puVar1[0x4d] != 0)) {
              if ((int)puVar1[0x4d] < 8) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[0x4f] = puVar1[0x4d] + -1;
                puVar1[0x4e] = 0;
              }
              else {
                FUN_0010a4e0(0,0,0,0);
                puVar1[0x4f] = 7;
                puVar1[0x4e] = puVar1[0x4d] + -8;
              }
            }
          }
          else if ((iVar3 == 1) && (puVar1[0x4e] != 0)) {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x4e] = puVar1[0x4e] + -1;
          }
          else if (iVar3 != 0) {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x4f] = puVar1[0x4f] + -1;
          }
        }
        else if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) {
          iVar3 = puVar1[0x4f];
          iVar8 = puVar1[0x4d];
          if (iVar8 == puVar1[0x4e] + iVar3 + 1) {
            if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x4f] = 0;
              puVar1[0x4e] = 0;
            }
          }
          else if ((iVar3 == 6) && (puVar1[0x4e] + 7 < iVar8 + -1)) {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x4e] = puVar1[0x4e] + 1;
          }
          else if ((iVar3 != 7) && (iVar3 < iVar8 + -1)) {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x4f] = puVar1[0x4f] + 1;
          }
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        *puVar1 = 0xe;
      }
    }
    uVar2 = FUN_00155710(puVar1[4],puVar1 + 5,puVar1 + 0xd,puVar1[0x4d],puVar1[0x4e],puVar1[0x4f]);
    puVar1[0xc] = uVar2;
    break;
  case 0xe:
    FUN_00155710(puVar1[4],puVar1 + 5,puVar1 + 0xd,puVar1[0x4d],puVar1[0x4e],puVar1[0x4f]);
    h_campDrawItemFrame((int)puVar1);
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 2, 0x4284000041a80000, 0x4284000041a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 2, 0x42c0000042100000, 0x42c0000042100000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 2, 0x4306000042040000, 0x4306000042040000, 0, 0, 0, 10);
    pair.u = 0x446b400043988000ULL;
    tmpd8.u = pair.u;
    tmpd8.f[0] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 2, tmpd8.u, pair.u, 0, 0, 0, 10);
    uVar5 = CAMP_PAIR_WORD_HIGH(0x42ae0000,(float)(puVar1[0x4f] * 0x23) + 599.0f);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 2, uVar5, uVar5, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 2, 0x42be000043b18000, 0x42be000043b18000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 2, 0x4383000044190000, 0x4383000044190000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 2, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0xf;
    break;
  case 0xf:
    lVar4 = FUN_00155710(puVar1[4],puVar1 + 5,puVar1 + 0xd,puVar1[0x4d],puVar1[0x4e],puVar1[0x4f]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 3;
    }
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    break;
  case 0x10:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    h_campDrawItemFrameSelected((int)puVar1);
    pair.u = CAMP_PAIR_FLOAT_HIGH(66.0f, 0x41a80000U);
    tmpe0.u = pair.u;
    tmpe0.f[0] += 200.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 1, tmpe0.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 1, 0x42b4000042040000, 0x42b4000042040000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 1, 0x433b000042040000, 0x433b000042040000, 0, 0, 0, 10);
    pair.u = CAMP_PAIR_FLOAT_HIGH(368.0f, 0x439a0000U);
    tmpe8.u = pair.u;
    tmpe8.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 1, tmpe8.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 1, 0x42ae000043aa8000, 0x42ae000043aa8000, 0, 0, 0, 10);
    pair.u = CAMP_PAIR_FLOAT_HIGH(87.0f, 0x4415c000U);
    tmpf0.u = pair.u;
    tmpf0.f[1] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 1, tmpf0.u, pair.u, 0, 0, 0, 10);
    pair.u = CAMP_PAIR_FLOAT_HIGH(86.0f, 0x43b00000U);
    tmpf8.u = pair.u;
    tmpf8.f[0] += 200.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 1, tmpf8.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 1, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0x11;
    break;
  case 0x11:
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      *puVar1 = 0x12;
    }
    FUN_00156e80(puVar1[4],puVar1 + 5,puVar1[0x50],puVar1[0x51]);
    puVar1[0xc] = 0;
    break;
  case 0x12:
    if (puVar1[0xc] != 0) {
      if ((DAT_007e094e & 0x20) == 0) {
        bVar6 = true;
        if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
          bVar6 = false;
        }
        if (bVar6) {
          if ((puVar1[0x50] == 0) || (puVar1[0x51] != 1)) {
            if (puVar1[0x51] == 0) {
              if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[0x51] = 7;
                puVar1[0x50] = 10;
              }
            }
            else {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x51] = puVar1[0x51] + -1;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x50] = puVar1[0x50] + -1;
          }
        }
        else if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) {
          if ((puVar1[0x50] == 10) || (puVar1[0x51] != 6)) {
            if (puVar1[0x51] == 7) {
              if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
                FUN_0010a4e0(0,0,0,0);
                puVar1[0x50] = 0;
                puVar1[0x51] = 0;
              }
            }
            else {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x51] = puVar1[0x51] + 1;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x50] = puVar1[0x50] + 1;
          }
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        *puVar1 = 0x13;
      }
    }
    uVar2 = FUN_00156e80(puVar1[4],puVar1 + 5,puVar1[0x50],puVar1[0x51]);
    puVar1[0xc] = uVar2;
    break;
  case 0x13:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    FUN_00156e80(puVar1[4],puVar1 + 5,puVar1[0x50],puVar1[0x51]);
    h_campDrawItemFrame((int)puVar1);
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 2, 0x4284000041a80000, 0x4284000041a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 2, 0x42b4000042040000, 0x42b4000042040000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 2, 0x433b000042040000, 0x433b000042040000, 0, 0, 0, 10);
    pair.u = 0x44720000439a0000ULL;
    tmp100.u = pair.u;
    tmp100.f[0] -= 600.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 2, tmp100.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 2, 0x42ae000043aa8000, 0x42ae000043aa8000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 2, 0x42ae00004415c000, 0x42ae00004415c000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 2, 0x42ac000043b00000, 0x42ac000043b00000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 2, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0x14;
    break;
  case 0x14:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    lVar4 = FUN_00156e80(puVar1[4],puVar1 + 5,puVar1[0x50],puVar1[0x51]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 3;
    }
    break;
  case 0x15:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    puVar1[0x52] = 0;
    h_campDrawItemFrameSelected((int)puVar1);
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 1, 0xc2cc000041b00000, 0x4346000041b00000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 1, 0x428a000041c80000, 0x43b8800041c80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 1, 0x4244000000000000, 0x4244000000000000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 1, 0x4224000043b48000, 0x4224000042740000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 1, 0x42240000440f0000, 0x4224000043880000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 1, 0x4224000044554000, 0x42240000440a4000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 1, 0x42ba000042480000, 0x42ba000042480000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1dc), 0, 2, 1, 0xc34f0000424c0000, 0x42ba0000424c0000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x220), 0, 2, 1, 0x42d8000043820000, 0x42d8000042700000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x264), 0, 2, 1, 0x4379000042480000, 0x4379000042480000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x2a8), 0, 2, 1, 0x4380000042820000, 0x4380000042820000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x2ec), 0, 2, 1, 0x41e80000441ac000, 0x43a48000441ac000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x330), 0, 2, 1, 0x43aa0000426c0000, 0x43aa0000426c0000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x374), 0, 2, 1, 0x43a6800042ee0000, 0x43a6800042ee0000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 1, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0x16;
    break;
  case 0x16:
    FUN_00159900(puVar1[4],puVar1 + 5,puVar1[0x52]);
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 0x17;
    }
    break;
  case 0x17:
    if (puVar1[0xc] != 0) {
      if ((DAT_007e094e & 0x20) == 0) {
        bVar6 = true;
        if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
          bVar6 = false;
        }
        if (bVar6) {
          if (puVar1[0x52] == 0) {
            if ((DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0) {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x52] = 2;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x52] = puVar1[0x52] + -1;
          }
        }
        else if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0) {
          if (puVar1[0x52] == 2) {
            if ((DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0) {
              FUN_0010a4e0(0,0,0,0);
              puVar1[0x52] = 0;
            }
          }
          else {
            FUN_0010a4e0(0,0,0,0);
            puVar1[0x52] = puVar1[0x52] + 1;
          }
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        *puVar1 = 0x18;
      }
    }
    uVar2 = FUN_00159900(puVar1[4],puVar1 + 5,puVar1[0x52]);
    puVar1[0xc] = uVar2;
    break;
  case 0x18:
    FUN_00159900(puVar1[4],puVar1 + 5,puVar1[0x52]);
    h_campDrawItemFrame((int)puVar1);
    pair.u = 0x43f9000041b00000ULL;
    tmp108.u = pair.u;
    tmp108.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 2, tmp108.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x4427400041c80000ULL;
    tmp110.u = pair.u;
    tmp110.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 2, tmp110.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 2, 0x4244000000000000, 0x4244000000000000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 2, 0x4224000042740000, 0x4224000042740000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 2, 0x4224000043880000, 0x4224000043880000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 2, 0x42240000440a4000, 0x42240000440a4000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 2, 0x42ba000042480000, 0x42ba000042480000, 0, 0, 0, 10);
    pair.u = 0x43c48000424c0000ULL;
    tmp118.u = pair.u;
    tmp118.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1dc), 0, 2, 2, tmp118.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x441d4000441ac000ULL;
    tmp120.u = pair.u;
    tmp120.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x2ec), 0, 2, 2, tmp120.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x44200000426c0000ULL;
    tmp128.u = pair.u;
    tmp128.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x330), 0, 2, 2, tmp128.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x441e400042ee0000ULL;
    tmp130.u = pair.u;
    tmp130.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x374), 0, 2, 2, tmp130.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x220), 0, 2, 2, 0x42d8000042700000, 0x42d8000042700000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x264), 0, 2, 2, 0x4379000042480000, 0x4379000042480000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x2a8), 0, 2, 2, 0x4380000042820000, 0x4380000042820000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 2, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    *puVar1 = 0x19;
    break;
  case 0x19:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    lVar4 = FUN_00159900(puVar1[4],puVar1 + 5,puVar1[0x52]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 3;
    }
    break;
  case 0x1a:
    uVar2 = FUN_0017d920();
    puVar1[0x53] = uVar2;
    uVar2 = FUN_0017da40();
    puVar1[0x54] = uVar2;
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    h_campDrawItemFrameSelected((int)puVar1);
    pair.u = 0x43a2000043918000ULL;
    tmp138.u = pair.u;
    tmp138.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 1, tmp138.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x4282000041980000ULL;
    tmp140.u = pair.u;
    tmp140.f[1] += 200.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 1, tmp140.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42c4000042100000ULL;
    tmp148.u = pair.u;
    tmp148.f[1] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 1, tmp148.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42fa000042280000ULL;
    tmp150.u = pair.u;
    tmp150.f[1] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 1, tmp150.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x424c000043c50000ULL;
    tmp158.u = pair.u;
    tmp158.f[1] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 1, tmp158.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 1, 0x42f0000041980000, 0x42f0000041980000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 1, 0x4248000043a28000, 0x4248000043a28000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1dc), 0, 2, 1, 0x42aa000043a30000, 0x42aa000043a30000, 0, 0, 0, 10);
    for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
      fVar10 = (float)(iVar3 * 0x29) + 335.0f;
      pair.u = CAMP_PAIR_WORD_HIGH(0x42a00000,fVar10);
      tmp160.u = pair.u;
      tmp160.f[1] += 100.0f;
      func_0018bc10(100.0f, (void*)(puVar1[4] + (iVar3 + 8) * 0x44), 0, 2, 1, tmp160.u, pair.u, 0, 0, 0, 10);
    }
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x3fc), 0, 2, 1, 0x42cc000043a30000, 0x42cc000043a30000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x440), 0, 2, 1, 0x42ce000043a38000, 0x42ce000043a38000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x484), 0, 2, 1, 0x42ce000043a38000, 0x42ce000043a38000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x4c8), 0, 2, 1, 0xc345000043a38000, 0x42ce000043a38000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x50c), 0, 2, 1, 0x42d4000043a80000, 0x42d4000043a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x550), 0, 2, 1, 0x42e8000043a80000, 0x42e8000043a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 1, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    uVar5 = FUN_0017d8b0(puVar1[0x53],1);
    iVar3 = FUN_0017dae0(uVar5);
    iVar9 = 0;
    for (iVar8 = 1; iVar8 < DAT_005e3b5e[puVar1[0x53]] + 1; iVar8 = iVar8 + 1) {
      lVar4 = h_campIsSocialLinkAvailable(puVar1[0x53],iVar8);
      if (lVar4 != 0) {
        iVar7 = iVar3 + iVar8 + -1;
        uVar5 = CAMP_PAIR_FLOATS((float)((iVar7 / 7) * 0x2c + 0x67),(float)((iVar7 % 7) * 0x29 + 0x147));
        func_0018bc10(100.0f, (void*)(puVar1[4] + (iVar9 + 0x15) * 0x44), 0, 2, 1, uVar5, uVar5, 0, 0, 0, 10);
        iVar9 = iVar9 + 1;
      }
    }
    *puVar1 = 0x1b;
    break;
  case 0x1b:
    FUN_0015B330((void*)puVar1[4],puVar1 + 5,puVar1[0x53],puVar1[0x54]);
    lVar4 = FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 0x1c;
    }
    break;
  case 0x1c:
    if (puVar1[0xc] != 0) {
      iVar8 = FUN_0017d8b0(puVar1[0x53],puVar1[0x54]);
      iVar3 = puVar1[0x53];
      if ((DAT_007e094e & 0x20) == 0) {
        if ((DAT_007e0952 & 8) == 0) {
          if ((DAT_007e0952 & 4) == 0) {
            if ((DAT_007e0952 & 0x1000) == 0 && (DAT_007e095a & 0x1000) == 0) {
              if ((DAT_007e0952 & 0x4000) == 0 && (DAT_007e095a & 0x4000) == 0) {
                if ((DAT_007e0952 & 0x8000) == 0 && (DAT_007e095a & 0x8000) == 0) {
                  if ((DAT_007e0952 & 0x2000) != 0 || (DAT_007e095a & 0x2000) != 0) {
                    FUN_0017d830(iVar8);
                    iVar9 = FUN_0017d8b0(3,DAT_005e3b64);
                    if (iVar8 != iVar9) {
                      FUN_0010a4e0(0,0,0,0);
                      iVar8 = iVar8 + 1;
                    }
                    uVar2 = FUN_0017d830(iVar8);
                    puVar1[0x53] = uVar2;
                    uVar2 = FUN_0017d9c0(iVar8);
                    puVar1[0x54] = uVar2;
                  }
                }
                else {
                  if (iVar8 != 2) {
                    FUN_0010a4e0(0,0,0,0);
                    iVar8 = iVar8 + -1;
                  }
                  uVar2 = FUN_0017d830(iVar8);
                  puVar1[0x53] = uVar2;
                  uVar2 = FUN_0017d9c0(iVar8);
                  puVar1[0x54] = uVar2;
                }
              }
              else {
                FUN_0017d830(iVar8);
                iVar9 = FUN_0017d8b0(3,DAT_005e3b64);
                if (iVar9 < iVar8 + 7) {
                  if (iVar9 != iVar8) {
                    FUN_0010a4e0(0,0,0,0);
                    iVar8 = iVar9;
                  }
                }
                else {
                  FUN_0010a4e0(0,0,0,0);
                  iVar8 = iVar8 + 7;
                }
                uVar2 = FUN_0017d830(iVar8);
                puVar1[0x53] = uVar2;
                uVar2 = FUN_0017d9c0(iVar8);
                puVar1[0x54] = uVar2;
              }
            }
            else {
              if (iVar8 < 7) {
                if (iVar8 != 2) {
                  FUN_0010a4e0(0,0,0,0);
                  iVar8 = 2;
                }
              }
              else {
                FUN_0010a4e0(0,0,0,0);
                iVar8 = iVar8 + -7;
                if (iVar8 < 2) {
                  iVar8 = 2;
                }
              }
              uVar2 = FUN_0017d830(iVar8);
              puVar1[0x53] = uVar2;
              uVar2 = FUN_0017d9c0(iVar8);
              puVar1[0x54] = uVar2;
            }
          }
          else if (iVar3 != 4) {
            FUN_0010a4e0(0,0,0,0);
            iVar8 = puVar1[0x53];
            puVar1[0x53] = iVar8 + -1;
            if (iVar8 + -1 == 0) {
              puVar1[0x53] = 0xc;
            }
            if ((s32)DAT_005e3b5e[puVar1[0x53]] < (s32)(int)puVar1[0x54]) {
              puVar1[0x54] = (int)DAT_005e3b5e[puVar1[0x53]];
            }
            if ((puVar1[0x53] == 4) && ((int)puVar1[0x54] < 7)) {
              puVar1[0x54] = 7;
            }
          }
        }
        else if (iVar3 != 3) {
          FUN_0010a4e0(0,0,0,0);
          iVar8 = puVar1[0x53];
          puVar1[0x53] = iVar8 + 1;
          if (iVar8 + 1 == 0xd) {
            puVar1[0x53] = 1;
          }
          if ((s32)DAT_005e3b5e[puVar1[0x53]] < (s32)(int)puVar1[0x54]) {
            puVar1[0x54] = (int)DAT_005e3b5e[puVar1[0x53]];
          }
          if ((puVar1[0x53] == 4) && ((int)puVar1[0x54] < 7)) {
            puVar1[0x54] = 7;
          }
        }
      }
      else {
        FUN_0010a4e0(0,0,0,2);
        *puVar1 = 0x1d;
      }
      if (iVar3 != puVar1[0x53]) {
        for (iVar3 = 0x15; iVar3 < 0x35; iVar3 = iVar3 + 1) {
          *(u32 *)(puVar1[4] + iVar3 * 0x44 + 4) = 0;
        }
        uVar5 = FUN_0017d8b0(puVar1[0x53],1);
        iVar3 = FUN_0017dae0(uVar5);
        iVar9 = 0;
        for (iVar8 = 1; iVar8 < DAT_005e3b5e[puVar1[0x53]] + 1; iVar8 = iVar8 + 1)
        {
          lVar4 = h_campIsSocialLinkAvailable(puVar1[0x53],iVar8);
          if (lVar4 != 0) {
            iVar7 = iVar3 + iVar8 + -1;
            uVar5 = CAMP_PAIR_FLOATS((float)((iVar7 / 7) * 0x2c + 0x67),(float)((iVar7 % 7) * 0x29 + 0x147))
            ;
            func_0018bc10(100.0f, (void*)(puVar1[4] + (iVar9 + 0x15) * 0x44), 0, 2, 1, uVar5, uVar5, 0, 0, 0, 10);
            iVar9 = iVar9 + 1;
          }
        }
      }
    }
    uVar2 = FUN_0015B330((void*)puVar1[4],puVar1 + 5,puVar1[0x53],puVar1[0x54]);
    puVar1[0xc] = uVar2;
    break;
  case 0x1d:
    h_campDrawItemFrame((int)puVar1);
    FUN_0015B330((void*)puVar1[4],puVar1 + 5,puVar1[0x53],puVar1[0x54]);
    pair.u = 0x441c000043918000ULL;
    tmp178.u = pair.u;
    tmp178.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4]), 0, 2, 2, tmp178.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x4282000041980000ULL;
    tmp180.u = pair.u;
    tmp180.f[0] += 200.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x44), 0, 2, 2, tmp180.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x88), 0, 2, 2, 0x42f0000041980000, 0x42f0000041980000, 0, 0, 0, 10);
    pair.u = 0x42c4000042100000ULL;
    tmp188.u = pair.u;
    tmp188.f[0] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0xcc), 0, 2, 2, tmp188.u, pair.u, 0, 0, 0, 10);
    pair.u = 0x42fa000042280000ULL;
    tmp190.u = pair.u;
    tmp190.f[0] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x110), 0, 2, 2, tmp190.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x154), 0, 2, 2, 0x4248000043a28000, 0x4248000043a28000, 0, 0, 0, 10);
    pair.u = 0x424c000043c50000ULL;
    tmp198.u = pair.u;
    tmp198.f[0] += 100.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x198), 0, 2, 2, tmp198.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1dc), 0, 2, 2, 0x42aa000043a30000, 0x42aa000043a30000, 0, 0, 0, 10);
    for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
      uVar5 = CAMP_PAIR_WORD_HIGH(0x42a00000,(float)(iVar3 * 0x29) + 335.0f);
      func_0018bc10(100.0f, (void*)(puVar1[4] + (iVar3 + 8) * 0x44), 0, 2, 2, uVar5, uVar5, 0, 0, 0, 10);
    }
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x3fc), 0, 2, 2, 0x42cc000043a30000, 0x42cc000043a30000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x440), 0, 2, 2, 0x42ce000043a38000, 0x42ce000043a38000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x484), 0, 2, 2, 0x42ce000043a38000, 0x42ce000043a38000, 0, 0, 0, 10);
    pair.u = 0x43c9800043a38000ULL;
    tmp1a8.u = pair.u;
    tmp1a8.f[0] -= 300.0f;
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x4c8), 0, 2, 2, tmp1a8.u, pair.u, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x50c), 0, 2, 2, 0x42d4000043a80000, 0x42d4000043a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x550), 0, 2, 2, 0x42e8000043a80000, 0x42e8000043a80000, 0, 0, 0, 10);
    func_0018bc10(100.0f, (void*)(puVar1[4] + 0x1a4c), 0, 2, 2, 0x43c0800041f80000, 0x43c0800041f80000, 0, 0, 0, 10);
    uVar5 = FUN_0017d8b0(puVar1[0x53],1);
    iVar3 = FUN_0017dae0(uVar5);
    iVar9 = 0;
    for (iVar8 = 1; iVar8 < DAT_005e3b5e[puVar1[0x53]] + 1; iVar8 = iVar8 + 1) {
      lVar4 = h_campIsSocialLinkAvailable(puVar1[0x53],iVar8);
      if (lVar4 != 0) {
        iVar7 = iVar3 + iVar8 + -1;
        uVar5 = CAMP_PAIR_FLOATS((float)((iVar7 / 7) * 0x2c + 0x67),(float)((iVar7 % 7) * 0x29 + 0x147));
        func_0018bc10(100.0f, (void*)(puVar1[4] + (iVar9 + 0x15) * 0x44), 0, 2, 2, uVar5, uVar5, 0, 0, 0, 10);
        iVar9 = iVar9 + 1;
      }
    }
    *puVar1 = 0x1e;
    break;
  case 0x1e:
    FUN_00154f70(puVar1[3],puVar1 + 5,puVar1[8],puVar1[1]);
    lVar4 = FUN_0015B330((void*)puVar1[4],puVar1 + 5,puVar1[0x53],puVar1[0x54]);
    if (lVar4 != 0) {
      puVar1[0xc] = 0;
      *puVar1 = 3;
    }
    break;
  }
  return 0;
}
#pragma opt_loop_invariants off
