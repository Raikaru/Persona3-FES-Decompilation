#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBcmPanel; // puGpffffb618
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
extern u32 D_00960090[];
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern u32 D_0096009C[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
#pragma alias D_00960090_fn D_00960090
#pragma alias D_0096009C_fn D_0096009C
extern void (*D_00960090_fn)(u32, u32);
extern void (*D_0096009C_fn)(u32*, u32, u32, u32, u32);
extern void RpSkyRenderStateSet(u32, void*);
extern void* FUN_00198590(void);
void FUN_00226320();
void FUN_00222d60();
void FUN_0021e380();
void FUN_0022c210();
void FUN_00222b90();
void FUN_002230e0();
u32 FUN_0021c450();
u32 FUN_0021cd00();
void FUN_0021d890();
void FUN_0021d950(void* destination, const u8* color);
void FUN_0021d8e0(void* destination, const f32* rect);
void FUN_0022c210();
void FUN_00224860();
void FUN_00225670();
void FUN_00227d10();
void FUN_00238980();
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin);
void FUN_00238dc0(void* destination, s32 count, u32 value, s32 mode, const f32* layout);
void FUN_0022e780(u32*, u32);
void FUN_0022e900(u32*, s32);
void FUN_0022e9a0(u32*, s32);
void FUN_0022ea40(u32*, u32);
void FUN_0022ecb0(u8*, u8*, f32);
extern void FUN_003b1360();
extern u32 FUN_00239140(s32);
extern void FUN_003b0d70(u32 resource, s32 x, s32 y);
extern void FUN_003b0e20(u32 resource, u32 color);
extern void FUN_0021dd60(void* destination, const u8* colors);
extern f32 fGpffff83e8;
extern u32 RpRandom(void);
extern void bppPanelDrawParameterLayout(void* work);
u32 FUN_0022e850(u32);
void FUN_0022eb30(u32* object, u32 value, u32 colour);
extern s32 sprintf(char* buffer, const char* format, ...);
extern s32 strlen(const char* string);
extern void K_Assert(const char* file, s32 line);
extern f32 D_0068E380[];
extern f32 D_0068E3BC[];
extern u8 D_0068E4B0[];
extern u8 D_0068E4D8[];
extern f32 D_007CB0D4;
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);
extern f32 D_0068E4F0[];
extern f32 D_0068E460[];
extern f32 D_0068E490[];
void FUN_0021e170(u8*, const f32*, const f32*, const f32*);
void FUN_0022f1c0(u32*, u64);
void FUN_0022f3b0(u32*);
void FUN_0022fa80(u32*);
void FUN_0022C210();
static u8* bcm_panel_record(u32 index);










/*
 * The command panel stores all of its render records in one work area.  The
 * retail code uses the records as packed byte arrays; keeping the addressing
 * in these small helpers makes the state-machine routines below considerably
 * easier to audit than a collection of magic pointer casts.
 */
static inline u8* bcm_panel_bytes(void)
{
    return (u8*)sBcmPanel;
}

static u32 bcm_panel_read(u32 offset)
{
    return *(u32*)(bcm_panel_bytes() + offset);
}

static void bcm_panel_write(u32 offset, u32 value)
{
    *(u32*)(bcm_panel_bytes() + offset) = value;
}

static u8* bcm_panel_record(u32 index)
{
    return bcm_panel_bytes() + 0x4660 + index * 0x420;
}

static u8* bcm_panel_overlay(u32 index)
{
    return bcm_panel_bytes() + 0x6080 + index * 0x110;
}

static inline void bcm_panel_set_resource(u8* dst, u32 resource, u32 id)
{
    u32 table;
    table = FUN_0021c3f0(resource);
    FUN_0021d3b0(dst, FUN_0021cca0(table, id));
}

static void bcm_panel_set_colour(u8* dst, u32 colour)
{
    *(u32*)(dst + 0x18c4) = colour;
    *(u32*)(dst + 0x18c8) = (colour ^ 0xffffffffu) & 0x00ffffffu;
    *(u32*)(dst + 0x18cc) = ((colour ^ 0xffffffffu) & 0x00ffffffu) | 0xff000000u;
}

static void bcm_panel_layout_record(u8* record, u32 row, u32 alpha)
{
    /* The four command quads are laid out on a 48-pixel baseline. */
    *(u32*)(record + 0x18d0) = 0x424c0000u + row * 48u;
    *(u32*)(record + 0x18d4) = 0x41980000u;
    *(u32*)(record + 0x18d8) = 0x432b0000u + row * 48u;
    *(u32*)(record + 0x18dc) = 0x41980000u;
    bcm_panel_set_colour(record, (alpha & 0xffu) | 0xffffff00u);
}

static void bcm_panel_refresh_records(void)
{
    u32 i;
    u32 count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 state = *(u32*)record;
        if (state == 0 || state == 2) {
            bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        } else if (state == 1) {
            bcm_panel_set_resource(record + 0x10, 0, 0x29);
            bcm_panel_set_resource(record + 0x110, 0, 0x29);
            bcm_panel_set_resource(record + 0x210, 0, 0x2a);
            bcm_panel_set_resource(record + 0x310, 0, 0x2a);
        }
    }
}

/* Removing this loses FUN_002230e0 (MATCH nd0 -> MISMATCH nd19) - measured W302. */


















#define BCM_29_STATE(...) (*setStatePtr)(__VA_ARGS__)
#define BCM_29_QUAD(...) (*setQuadPtr)(__VA_ARGS__)
#define BCM_29_STATE2(...) (*setStatePtr2)(__VA_ARGS__)
#undef BCM_29_STATE
#undef BCM_29_STATE2
#undef BCM_29_QUAD


#define BCM_2AE_STATE(...) (*pRender)(__VA_ARGS__)
#define BCM_2AE_QUAD(...) (*pQuad)(__VA_ARGS__)
#undef BCM_2AE_STATE
#undef BCM_2AE_QUAD





















