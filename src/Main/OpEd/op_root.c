#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Camp/h_camp.h"
#include "Main/OpEd/op_res.h"

static u32* sOpRoot; // DAT_007ce388
static u32 D_007cdffc;
static u32 D_007ce00c;

void FUN_00265030(void);
u32 FUN_00420340(u32 value, u32 mode);
int H_Snd_GetCurrentBgmId(void);
u8 H_Snd_PlayBgm(s16 id, s32 unused);
void FUN_00269f50(void);
void opMenu0026c710(void);
void opWait0026e000(void);
void opMenu0026cc90(void);
void opTitle00268e20(void);
void FUN_002720c0(void);
void H_Snd_StopBgm(void);
void opResDestroyTitle(void);
void opWait0026ebf0(void);
void opMenu0026da10(void);
void opResRequestLogo(void);
void opLogo00269d10(void);
void opTitle002673f0(void);
void opWait0026dd60(void);
void opMenu0026a280(void);
void FUN_00271d70(void);
void opResShutdown(void);
void H_Free(void* memory);
void opLogo0026a0f0(void);
u32 opLogo0026a1e0(void);
void opLogo00269d50(void);
void opResUpdate(void);
u32 opResCheckRequestTitle(void);
void opResRequestTitle(void);
u32 opResCheckRequestLogo(void);
void opResRequestLogo(void);
void opResDestroyLogo(void);
void opTitle002692d0(void);
void opTitle002694b0(void);
void opTitle00269550(void);
void opTitle002695b0(void);
u32 opTitle00269640(void);
void opTitle00267430(void);
void opMenu0026a2c0(void);
void opMenu0026d430(void);
void opMenu0026dbd0(void);

// FUN_00265b30
void opRoot00265b30(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    work = sOpRoot;
    D_007cdffc = 0;
    D_007ce00c = 0;
    v = FUN_00420340(work[2], 0);
    work[4] = v;
    *work |= 2;
    work[1] = 0xb;
}

// FUN_00265bb0
void opRoot00265bb0(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    work = sOpRoot;
    v = (u32)FUN_0015C460((KwlnTask*)work[2]);
    work[6] = v;
    *work |= 4;
    work[1] = 0xe;
}

// FUN_00265dc0
u32 opRoot00265dc0(void)
{
    FUN_00265030();
    K_ASSERT(sOpRoot != NULL, 0x9a);
    if ((*sOpRoot & 1) != 0) {
        return 0;
    }
    return -1;
}

// FUN_00266060
void opRoot00266060(void)
{
    int base;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    base = (int)sOpRoot;
    if (H_Snd_GetCurrentBgmId() != 0x36) {
        H_Snd_PlayBgm(0x36, 1);
    }
    *(u32*)(base + 0x4524) = 0;
    *(u32*)(base + 4) = 9;
}

// FUN_002660d0
void opRoot002660d0(void)
{
    int base;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    base = (int)sOpRoot;
    if (H_Snd_GetCurrentBgmId() != 0x36) {
        H_Snd_PlayBgm(0x36, 1);
    }
    *(u32*)(base + 0x4524) = 0;
    *(u32*)(base + 4) = 0x11;
}

// FUN_00265e30
u32 opRoot00265e30(void)
{
    u32* puVar1;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    puVar1 = sOpRoot;
    if (puVar1[1] != 5 && (~*puVar1 & 1) == 0)
    {
        FUN_00269f50();
        if (puVar1[1] != 0xb)
            opMenu0026c710();
        opWait0026e000();
        if (puVar1[1] != 0xb)
        {
            opMenu0026cc90();
            opTitle00268e20();
        }
        FUN_002720c0();
    }
    return 0;
}
 
// FUN_00265ef0
void opRoot00265ef0(int param_1)
{
    K_ASSERT(sOpRoot != NULL, 0x9a);
    opLogo00269d10();
    opTitle002673f0();
    opWait0026dd60();
    opMenu0026a280();
    FUN_00271d70();
    opResDestroyTitle();
    opResShutdown();
    sOpRoot = NULL;
    H_Free(*(void**)(param_1 + 0x3c));
}

extern u16 DAT_007e094e;
extern u16 DAT_007e094c;
extern u16 DAT_007e0952;
extern u16 DAT_007e0956;
extern u16 DAT_007e095a;
extern u32 DAT_007ce018;
extern u8 DAT_007ce384;
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e094c_abs DAT_007e094c
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0956_abs DAT_007e0956
#pragma alias DAT_007e095a_abs DAT_007e095a
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e094c_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0956_abs[];
extern u8 DAT_007e095a_abs[];
extern u32 FUN_00108710(void);
extern u32 FUN_001938e0(u32 mode);
extern u32 FUN_00195290(u32 handle);
extern u32 FUN_00195460(u32 handle);
extern u32 FUN_0010bc20(u32 value, u32 mode);
extern u32 FUN_001928d0(void);
extern u32 FUN_00192aa0(void);

#pragma push
/* Removing this worsens opRoot00265030 (nd1289 -> nd1679) - measured W161. */
// FUN_00265030 NONMATCHING
void opRoot00265030(void)
{
    u32* w;
    u32 state;
    u32 value;
    int changed;
    typedef struct
    {
        u8 pad[28];
        u8 color[4];
    } ColorWork;
    ColorWork colorWork;
    u32 flags;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    w = sOpRoot;
    flags = *w;

    if ((~flags & 1) != 0)
        return;
    if ((flags & 2) != 0 && FUN_00195460(w[4]) == 0)
        *w &= ~2u;
    if ((*w & 4) != 0 && FUN_00195460(w[6]) == 0)
        *w &= ~4u;

    state = w[1];
    switch (state)
    {
        case 0:
            if (FUN_00108710() != 0 && opResCheckRequestLogo() == 0)
            {
                opLogo0026a0f0();
                w[1] = 1;
            }
            break;
        case 1:
            if (opLogo0026a1e0() == 0)
            {
                FUN_002722e0();
                if (DAT_007ce018 != 0)
                    w[1] = 4;
                else
                    w[1] = 2;
            }
            break;
        case 2:
            w[0x114b] = FUN_001938e0(0);
            w[1] = 3;
            break;
        case 3:
            if (FUN_00195290(w[0x114b]) == 3)
            {
                w[0x114b] = 0;
                DAT_007ce018 = 1;
                w[1] = 4;
            }
            break;
        case 4:
            opResDestroyLogo();
            if (DAT_007ce384 == 0)
            {
                value = FUN_0010bc20(w[2], 0x23);
                w[5] = value;
                DAT_007ce384 = 1;
            }
            else
            {
                value = FUN_0010bc20(w[2], 1);
                w[5] = value;
                DAT_007ce384 = 0;
            }
            w[1] = 5;
            break;
        case 5:
            if (FUN_00195460(w[5]) == 0)
            {
                FUN_00272290();
                opResRequestTitle();
                w[1] = 6;
            }
            break;
        case 6:
            if (opResCheckRequestTitle() == 0)
            {
                FUN_002722e0();
                opTitle002692d0();
                opWait0026e780();
                FUN_001099d0(0x73, 1);
                w[0x1149] = 0;
                w[1] = 8;
            }
            break;
        case 8:
            if (opWait0026ee80() != 0 && opTitle00269640() != 0 && opWait0026ee30() != 0 &&
                (DAT_007e094e & 0x9ff) != 0)
            {
                FUN_00271c10();
                opTitle002695b0();
            }
            else
            {
                switch ((s32)w[0x1149] < 0x1c2)
                {
                    case 0:
                        colorWork.color[0] = 0;
                        colorWork.color[1] = 0;
                        colorWork.color[2] = 0;
                        colorWork.color[3] = 0xff;
                        FUN_00272220(colorWork.color);
                        FUN_00271db0();
                        w[0x114a] = w[1];
                        w[1] = 10;
                        break;
                    case 1:
                        w[0x1149]++;
                        if ((DAT_007e094e & 0x9ff) != 0)
                        {
                            opMenu0026d430();
                            opWait0026edb0();
                            opTitle00269550();
                            w[0x1148] = 0;
                            FUN_0010a4e0(0, 0, 0, 1);
                            FUN_002660d0();
                        }
                        break;
                }
                }
            break;
        case 9:
            if (opMenu0026dcc0() == 0)
            {
                if ((s32)w[0x1149] < 0x1c2)
                {
                    w[0x1149]++;
                    changed = 0;
                    if ((DAT_007e094e & 0x40) != 0)
                    {
                        FUN_0010a4e0(0, 0, 0, 1);
                        value = w[0x1148];
                        switch (value)
                        {
                            case 1:
                                FUN_00266660(0);
                                FUN_00108570();
                                FUN_00108670(5);
                                FUN_001086a0(0x14);
                                w[1] = 7;
                                break;
                            case 0:
                                FUN_00108570();
                                FUN_00108670(5);
                                FUN_001086a0(0x14);
                                FUN_00108f70();
                                w[1] = 0xc;
                                break;
                            case 2:
                                w[1] = 0xf;
                                break;
                            case 3:
                                w[0x1148] = 0;
                                opMenu0026dc20();
                                opMenu0026db30(0);
                                w[1] = 0x11;
                                break;
                        }
                        changed = 1;
                    }
                    if ((DAT_007e094c & 63999) != 0 || (DAT_007e0956 & 63999) != 0)
                        w[0x1149] = 0;
                    if (((*w & 8) == 0 ||
                         (((DAT_007e094c & 0x1000) == 0 && (DAT_007e0956 & 0x1000) == 0 &&
                           (DAT_007e094c & 0x4000) == 0 && (DAT_007e0956 & 0x4000) == 0))) &&
                        !changed)
                    {
                        if ((DAT_007e0952 & 0x1000) == 0 && (DAT_007e095a & 0x1000) == 0)
                        {
                            if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0)
                            {
                                w[0x1148] = ((s32)w[0x1148] < 3) ? w[0x1148] + 1 : 0;
                                if (w[0x1148] == 3) *w |= 8;
                                FUN_0010a4e0(0, 0, 0, 0);
                                opMenu0026da90(w[0x1148]);
                            }
                        }
                        else
                        {
                            w[0x1148] = ((s32)w[0x1148] < 1) ? 3 : w[0x1148] - 1;
                            if (w[0x1148] == 0) *w |= 8;
                            FUN_0010a4e0(0, 0, 0, 0);
                            opMenu0026da90(w[0x1148]);
                        }
                    }
                }
                else
                {
                    colorWork.color[0] = 0;
                    colorWork.color[1] = 0;
                    colorWork.color[2] = 0;
                    colorWork.color[3] = 0xff;
                    FUN_00272220(colorWork.color);
                    FUN_00271db0();
                    w[0x114a] = w[1];
                    w[1] = 10;
                }
            }
            break;
        case 10:
            if (FUN_00271e70() == 0)
                FUN_00265f80();
            break;
        case 7:
            if (FUN_00108710() != 0)
                *w &= ~1u;
            break;
        case 0xc:
            if (FUN_00108710() != 0)
                opRoot00265b30();
            break;
        case 0xb:
            if ((*w & 2) == 0)
            {
                if (D_007cdffc == 0)
                {
                    FUN_001085c0();
                    FUN_00108670(5);
                    FUN_001086a0(0x14);
                    w[1] = 0xd;
                }
                else
                {
                    FUN_00266660(1);
                    *w &= ~1u;
                }
            }
            break;
        case 0xd:
            if (FUN_00108710() != 0)
                opRoot00266060();
            break;
        case 0xf:
            opRoot00265bb0();
            break;
        case 0xe:
            if ((*w & 4) == 0)
                w[1] = 0x10;
            break;
        case 0x10:
            opRoot00266060();
            break;
        case 0x11:
            if (opMenu0026dcc0() == 0)
            {
                if ((s32)w[0x1149] < 0x1c2)
                {
                    w[0x1149]++;
                    changed = 0;
                    if ((DAT_007e094e & 0x40) != 0)
                    {
                        FUN_0010a4e0(0, 0, 0, 1);
                        w[7] = w[0x1148] == 0 ? FUN_001928d0() : FUN_00192aa0();
                        w[1] = 0x12;
                        changed = 1;
                    }
                    if ((DAT_007e094c & 63999) != 0 || (DAT_007e0956 & 63999) != 0)
                        w[0x1149] = 0;
                    if (((*w & 8) == 0 ||
                         (((DAT_007e094c & 0x1000) == 0 && (DAT_007e0956 & 0x1000) == 0 &&
                           (DAT_007e094c & 0x4000) == 0 && (DAT_007e0956 & 0x4000) == 0))) &&
                        !changed)
                    {
                        if ((DAT_007e0952 & 0x1000) == 0 && (DAT_007e095a & 0x1000) == 0)
                        {
                            if ((DAT_007e0952 & 0x4000) != 0 || (DAT_007e095a & 0x4000) != 0)
                            {
                                w[0x1148] = ((s32)w[0x1148] < 1) ? w[0x1148] + 1 : 0;
                                if (w[0x1148] == 1) *w |= 8;
                                FUN_0010a4e0(0, 0, 0, 0);
                                opMenu0026db30(w[0x1148]);
                            }
                        }
                        else
                        {
                            w[0x1148] = ((s32)w[0x1148] < 1) ? 1 : w[0x1148] - 1;
                            if (w[0x1148] == 0) *w |= 8;
                            FUN_0010a4e0(0, 0, 0, 0);
                            opMenu0026db30(w[0x1148]);
                        }
                    }
                }
                else
                {
                    colorWork.color[0] = 0;
                    colorWork.color[1] = 0;
                    colorWork.color[2] = 0;
                    colorWork.color[3] = 0xff;
                    FUN_00272220(colorWork.color);
                    FUN_00271db0();
                    w[0x114a] = w[1];
                    w[1] = 10;
                }
            }
            break;
        case 0x12:
            if (FUN_00195290(w[7]) == 3)
            {
                FUN_00195de0();
                w[0x1148] = 0;
                w[7] = 0;
                opMenu0026dbd0();
                opMenu0026da90(0);
                w[1] = 9;
            }
            break;
    }
    opResUpdate();
    opLogo00269d50();
    opTitle00267430();
    opWait0026ddc0();
    opMenu0026a2c0();
    FUN_00271ec0();
}
#pragma pop

// FUN_00265f80
void opRoot00265f80(void)
{
    u32* root;
    s32 state;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    root = sOpRoot;
    FUN_00108f70();
    opResDestroyTitle();
    state = (s32)root[0x4528 / 4];
    switch (state)
    {
        case 8:
            opWait0026ebf0();
            opTitle002694b0();
            break;
        case 9:
        case 0x11:
            opWait0026ebf0();
            opTitle002694b0();
            opMenu0026da10();
            break;
        default:
            K_ASSERT(false, 0x327);
            break;
    }
    opResRequestLogo();
    root[1] = 0;
}
