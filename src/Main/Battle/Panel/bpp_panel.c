#include "Main/Battle/Panel/bpp_panel.h"
#include "Kosaka/k_assert.h"

#pragma alias RpSkyRenderStateSet_void RpSkyRenderStateSet
extern void RpSkyRenderStateSet_void(u32, void*);
#pragma alias bppPanelDrawParameterLayout_void bppPanelDrawParameterLayout
extern void bppPanelDrawParameterLayout_void(void* work);
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
extern u32 D_00960090[];
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
#pragma alias D_0096009C_fn D_0096009C
extern void (*D_0096009C_fn)(u32*, u32, u32, u32, u32);
extern void* FUN_00198590(void);
u32 FUN_0021c450();
u32 FUN_0021cd00();
void FUN_0021d890();
void FUN_0021d950(void* destination, const u8* color);
void FUN_0021d8e0(void* destination, const f32* rect);
void FUN_0022e780(u32*, u32);
void FUN_0022e900(u32*, s32);
void FUN_0022e9a0(u32*, s32);
void FUN_0022ea40(u32*, u32);
void FUN_0022ecb0(u8*, u8*, f32);
extern u32 RpRandom(void);
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


#define BPP_PANEL_QUAD_OFFSET 0x1060
#define BPP_PANEL_QUAD_SIZE 0x100

typedef void (*BppPanelSetRenderState)(s32 property, u32 value);
typedef void (*BppPanelRenderQuad)(void* quad, s32 layer, s32 group, s32 pass, s32 blend);
extern u32 D_00960090[];
extern u32 D_0096009c[];
#define BPP_PANEL_SET_RENDER_STATE (*setRenderState)
#define BPP_PANEL_RENDER_QUAD (*renderQuad)

extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void RpSkyRenderStateSet(s32 state, u32 value);

// FUN_0022C850
void FUN_0022c850(u32* object)
{
    K_ASSERT((object[0] & 1) != 0, 0x1b3);
    object[0] = 0;
}

// The retail routine keeps separate color paths for each animation flag.
// Preserve the bounded-index fixed colors before the interpolated paths.
// This restores the missing flag-0x100 interpolation and color snapshots.
// MWCCPS2 retains a different branch layout, so the function stays pending.
// W418 width negatives: FUN_0022C8A0 first color-loop j s16 nd4183/5656B -> 4184/5672B; second color-loop j s16 -> 4182/5672B (near-flat rate, rejected).
// FUN_0022C8A0 NONMATCHING
void FUN_0022c8a0(u32* object_param)
{
    u32 table3;
    u8* object;
    u32 table5;
    f32 rect[4];
    u8 color[4];
    u8 colorTmp[4];
    u32 color1;
    u32 color2;
    u32 color3;
    f32 pos1X, pos1Y;
    f32 pos2X, pos2Y;
    f32 pos3X, pos3Y;
    f32 colorF;
    s32 colorI;

    object = (u8*)object_param;
    K_ASSERT((*(u32*)object & 1) != 0, 0x1cd);
    table3 = FUN_0021c3f0(3);
    {

    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0x10) {
            *(s32*)(object + 0x844) += 1;
        } else {
            *(u32*)object &= ~0x20u;
        }
    }
    if (*(u32*)object & 0x40) {
        if (*(s32*)(object + 0x848) < 8) {
            *(s32*)(object + 0x848) += 1;
        } else {
            *(u32*)object &= ~0x40u;
        }
    } else if (*(u32*)object & 0x80) {
        if (*(s32*)(object + 0x848) < 8) {
            *(s32*)(object + 0x848) += 1;
        } else {
            *(u32*)object &= ~0x80u;
        }
    }
    if (!(*(u32*)object & 8) && (*(u32*)object & 0x100)) {
        if (*(s32*)(object + 0x84c) < 0x14) {
            *(s32*)(object + 0x84c) += 1;
        } else {
            *(u32*)object &= ~0x100u;
        }
    }

    if (*(u32*)object & 0x10) {
        if (*(u32*)object & 0x40) {
            f32 t = (f32)*(s32*)(object + 0x848) / 8.0f;
            *(f32*)(object + 0x518) = -60.0f * t + 30.0f * t * t;
        } else {
            *(f32*)(object + 0x518) = -30.0f;
        }
        *(s32*)(object + 0x51c) = 0;
    } else if (*(u32*)object & 0x80) {
        f32 t = (f32)*(s32*)(object + 0x848) / 8.0f;
        f32 f3 = t * *(f32*)(object + 0x854);
        *(f32*)(object + 0x518) = 60.0f * f3 - 30.0f * f3 * f3 - 30.0f;
        *(s32*)(object + 0x51c) = 0;
    } else {
        *(f32*)(object + 0x518) = 0.0f;
        *(s32*)(object + 0x51c) = 0;
    }

    {
        f32 g;
        f32 blendF3;
        blendF3 = *(f32*)(object + 0x850);
        g = 1.0f - (2.0f * blendF3 - blendF3 * blendF3);
        *(f32*)(object + 0x520) = 180.0f * g;
        *(f32*)(object + 0x524) = -80.0f * g;
    }

    pos1X = *(f32*)(object + 0x520) + *(f32*)(object + 0x510) + *(f32*)(object + 0x518);
    pos1Y = *(f32*)(object + 0x524) + *(f32*)(object + 0x514) + *(f32*)(object + 0x51c);

    pos2X = 0.0f;
    pos2Y = 0.0f;
    pos3X = 0.0f;
    pos3Y = 0.0f;
    /* Retail 0x22cba0-0x22ccb0 keeps the second corner's trig sequence in
     * both index branches; do not sink it into a shared tail. */
    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            f32 magA = D_0068E380[*(s32*)(object + 0x844)];
            pos2X = magA * cosf(D_007CB0D4);
            pos2Y = -magA * sinf(D_007CB0D4);
            {
                f32 magB = D_0068E3BC[*(s32*)(object + 0x844)];
                pos3X = magB * cosf(D_007CB0D4);
                pos3Y = -magB * sinf(D_007CB0D4);
            }
        } else {
            K_ASSERT((*(s32*)(object + 0x844) - 1) < 0x10, 0x233);
            {
                f32 magB = D_0068E3BC[*(s32*)(object + 0x844)];
                pos3X = magB * cosf(D_007CB0D4);
                pos3Y = -magB * sinf(D_007CB0D4);
            }
        }
    }
    pos2X += pos1X;
    pos2Y += pos1Y;
    pos3X += pos1X;
    pos3Y += pos1Y;

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        color[0] = 0xff;
        color[1] = 0xe1;
        color[2] = 0xb9;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            /* Native u8 casts measured 5920B/5744B (+264B for this batch);
             * retail retains the explicit unsigned-conversion expansions. */
            /* Retail 0x484-0x578: the conversion remains runtime-valued in
             * the retail path even though this branch's color is constant. */
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844) + 50.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844);
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844);
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            color[3] = 0xff;
        } else {
            f32 t2 = (f32)(*(s32*)(object + 0x844) - 0xa) / 6.0f;
            f32 f3 = 1.0f - t2;
            colorF = 255.0f + -205.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            color[3] = 0xff;
        }
    } else if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0x8c;
        color[2] = 0x46;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x100) {
        f32 t3 = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t3;
        color[0] = 0xff;
        colorF = 255.0f + -115.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -185.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        color[3] = 0xff;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color1 = *(u32*)color;

    if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0x8c;
        color[2] = 0x46;
        color[3] = 0xff;
    } else if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        /* reuse color[] as computed for color1 */
    } else if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            color[0] = 0x32;
            color[1] = 0;
            color[2] = 0;
            color[3] = 0xff;
        } else {
            color[0] = 0x32;
            color[1] = 0;
            color[2] = 0;
            color[3] = 0xff;
        }
    } else if (*(u32*)object & 0x100) {
        f32 t = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t;
        color[0] = 0xff;
        colorF = 255.0f + -65.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -125.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        colorF = 255.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[3] = (u8)colorI;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color2 = *(u32*)color;
    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            /* Retail 0xa3c-0xb84: keep the float-to-byte conversions and
             * retain the animation blend for the alpha byte. */
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844) + 200.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844);
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = (f32)*(s32*)(object + 0x844) -
                (f32)*(s32*)(object + 0x844);
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            colorF = 255.0f * *(f32*)(object + 0x850);
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[3] = (u8)colorI;
        } else {
            f32 t = (f32)(*(s32*)(object + 0x844) - 0xa) / 6.0f;
            f32 f3 = 1.0f - t;
            colorF = 255.0f + -55.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            colorF = 255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[3] = (u8)colorI;
        }
    } else if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0xbe;
        color[2] = 0x82;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x100) {
        f32 t = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t;
        color[0] = 0xff;
        colorF = 255.0f + -65.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -125.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        colorF = 255.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[3] = (u8)colorI;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color3 = *(u32*)color;
    {
        void* resource = (void*)FUN_0021cca0(FUN_0021c450(*(u16*)(object + 4)), 0);
        rect[0] = 30.0f + pos2X;
        rect[1] = 15.0f + pos2Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x10, rect);
    }

    if (*(u32*)object & 4) {
        s32 idx = *(s32*)(object + 0x830);
        colorTmp[0] = D_0068E4B0[idx * 3 + 0];
        colorTmp[1] = D_0068E4B0[idx * 3 + 1];
        colorTmp[2] = D_0068E4B0[idx * 3 + 2];
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    if (*(u32*)object & 0x200) {
        colorTmp[3] = (u8)(colorTmp[3] * 80 / 100);
    }
    FUN_0021d950(object + 0x10, colorTmp);

    {
        void* resource = (void*)FUN_0021cca0(FUN_0021c450(*(u16*)(object + 4)), 1);
        rect[0] = pos2X;
        rect[1] = pos2Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x110, rect);
        FUN_0021d8e0(object + 0x210, rect);
        rect[0] = 30.0f + pos3X;
        rect[1] = 15.0f + pos3Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x310, rect);
        FUN_0021d8e0(object + 0x410, rect);
    }
    }

    FUN_0021d950(object + 0x110, (u8*)&color1);
    FUN_0021d950(object + 0x310, (u8*)&color2);
    FUN_0021d950(object + 0x210, (u8*)&color3);
    FUN_0021d950(object + 0x410, (u8*)&color3);



    table5 = FUN_0021c3f0(5);
    {
        void* resource = (void*)FUN_0021cca0(table5, 2);
        rect[0] = 65.0f + pos1X;
        rect[1] = 83.0f + pos1Y;
        rect[2] = (f32)((*(s32*)((u8*)resource + 0xc) * *(s32*)(object + 0x834)) /
                         *(s32*)(object + 0x838));
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0xe60, rect);
    }

    {
        void* resource = (void*)FUN_0021cca0(table5, 3);
        rect[0] = pos1X;
        rect[1] = 89.0f + pos1Y;
        rect[2] = (f32)((*(s32*)((u8*)resource + 0xc) * *(s32*)(object + 0x83c)) /
                         *(s32*)(object + 0x840));
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0xf60, rect);
    }

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0xd7;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0x91;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    FUN_0021d950(object + 0xf60, colorTmp);
    rect[0] = 102.0f + pos1X + 2.0f;
    rect[1] = 72.0f + pos1Y;
    FUN_0022eb30((u32*)(object + 0x860), *(u32*)(object + 0x834), (u32)(size_t)rect);

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0x78;
        colorTmp[1] = 0x78;
        colorTmp[2] = 0x78;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    {
        s32 j;
        for (j = 0; j < 3; ++j) {
            FUN_0021d950(object + j * 0x100 + 0x860, colorTmp);
        }
    }

    rect[0] = pos3X;
    rect[1] = 22.0f + pos3Y;
    FUN_0022eb30((u32*)(object + 0xb60), *(u32*)(object + 0x83c), (u32)(size_t)rect);

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0x78;
        colorTmp[1] = 0x78;
        colorTmp[2] = 0x78;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    {
        s32 j;
        for (j = 0; j < 3; ++j) {
            FUN_0021d950(object + j * 0x100 + 0xb60, colorTmp);
        }
    }

    if (*(u32*)object & 2) {
        s32 idx;
        u32 resourceId = FUN_0022e850(*(u32*)(object + 0x528));
        {
            void* resource = (void*)FUN_0021cca0(table3, resourceId);
            rect[0] = 116.0f + pos1X;
            rect[1] = 43.0f + pos1Y;
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(object + 0x530, rect);
        }
 
        idx = 0;
        if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
            if (*(s32*)(object + 0x528) < 6) {
                switch (*(s32*)(object + 0x528)) {
                case 0:
                    K_ASSERT(0, 0x369);
                    idx = 0;
                    break;
                case 1:
                    idx = 0;
                    break;
                case 2:
                    idx = 1;
                    break;
                case 3:
                    idx = 2;
                    break;
                case 4:
                    idx = 3;
                    break;
                case 5:
                    idx = 4;
                    break;
                }
            }
            colorTmp[0] = D_0068E4D8[idx * 3 + 0];
            colorTmp[1] = D_0068E4D8[idx * 3 + 1];
            colorTmp[2] = D_0068E4D8[idx * 3 + 2];
            colorTmp[3] = 0xff;
        } else {
            colorTmp[0] = 0xff;
            colorTmp[1] = 0xff;
            colorTmp[2] = 0xff;
            colorTmp[3] = 0xff;
        }
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    FUN_0021d950(object + 0x530, colorTmp);
    {
        void* resource = (void*)FUN_0021cca0(table3, 0xa);
        rect[0] = 60.0f + pos1X;
        rect[1] = 79.0f + pos1Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x630, rect);
        FUN_0021d8e0(object + 0x730, rect);
    }
    FUN_0021d950(object + 0x630, (u8*)&color1);
    FUN_0021d950(object + 0x730, (u8*)&color3);

    if (*(u32*)object & 4) {
        FUN_0022fa80((u32*)object);
    }
}

// W212: matched-sibling vtable transfer changed nd 1383 -> 1343 and
// reached the 2160/2160 window. The first residual is a saved-register
// bank mismatch at +0x20 (ours object in s3, retail s4); declaration
// ordering cannot safely solve the cascading allocation difference.
// FUN_0022DF10 NONMATCHING
void FUN_0022df10(u32* object)
{
    void (**setState)(u32, u32);
    u32 table3;
    u32 table5;
    u32 text;
    u32 resource;

    K_ASSERT((object[0] & 1) != 0, 0x390);
    table3 = FUN_0021c3f0(3);
    table5 = FUN_0021c3f0(5);
    text = FUN_0021c450(*(u16*)((u8*)object + 4));
    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(0x14, 2);
    (*setState)(8, 0);
    (*setState)(6, 0);
    (*setState)(1, FUN_0021cce0(FUN_0021cca0(text, 1)));

    if ((object[0] & 0x20) != 0) {
        RpSkyRenderStateSet_void(3, (void*)0x717fb);
        RpSkyRenderStateSet_void(2, (void*)0x44);
        D_0096009C_fn((u32*)((u8*)object + 0x310), 4, 0, 1, 2);
        D_0096009C_fn((u32*)((u8*)object + 0x310), 4, 0, 2, 3);

        if (!((object[0] & 4) != 0 && object[0x20c] == 8)) {
            RpSkyRenderStateSet_void(3, (void*)0x717fb);
            RpSkyRenderStateSet_void(2, (void*)0x44);
            D_0096009C_fn((u32*)((u8*)object + 0x410), 4, 0, 1, 2);
            D_0096009C_fn((u32*)((u8*)object + 0x410), 4, 0, 2, 3);
        }
    }
    RpSkyRenderStateSet_void(3, (void*)0x717fb);
    RpSkyRenderStateSet_void(2, (void*)0x44);
    D_0096009C_fn((u32*)((u8*)object + 0x110), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x110), 4, 0, 2, 3);

    if ((object[0] & 0x20) == 0) {
        goto check210_flag8;
    }
    if ((object[0] & 4) == 0) {
        goto draw210;
    }
    if (object[0x20c] != 8) {
        goto draw210;
    }
check210_flag8:
    if ((object[0] & 8) != 0) {
        goto draw210;
    }
    if ((object[0] & 0x100) == 0) {
        goto skip210;
    }
draw210:
    RpSkyRenderStateSet_void(3, (void*)0x71801);
    RpSkyRenderStateSet_void(2, (void*)0x48);
    D_0096009C_fn((u32*)((u8*)object + 0x210), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x210), 4, 0, 2, 3);
skip210:

    RpSkyRenderStateSet_void(3, (void*)0x717fb);
    RpSkyRenderStateSet_void(2, (void*)0x44);
    (*setState)(1, FUN_0021cce0(FUN_0021cca0(text, 0)));
    D_0096009C_fn((u32*)((u8*)object + 0x10), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x10), 4, 0, 2, 3);

    resource = FUN_0021cca0(table3, 0xa);
    (*setState)(1, FUN_0021cce0(resource));
    D_0096009C_fn((u32*)((u8*)object + 0x630), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x630), 4, 0, 2, 3);

    if ((object[0] & 0x20) == 0) {
        goto check730_flag8;
    }
    if ((object[0] & 4) == 0) {
        goto draw730;
    }
    if (object[0x20c] != 8) {
        goto draw730;
    }
check730_flag8:
    if ((object[0] & 8) != 0) {
        goto draw730;
    }
    if ((object[0] & 0x100) == 0) {
        goto skip730;
    }
draw730:
    RpSkyRenderStateSet_void(3, (void*)0x71801);
    RpSkyRenderStateSet_void(2, (void*)0x48);
    D_0096009C_fn((u32*)((u8*)object + 0x730), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x730), 4, 0, 2, 3);
skip730:

    RpSkyRenderStateSet_void(3, (void*)0x717fb);
    RpSkyRenderStateSet_void(2, (void*)0x44);
    resource = FUN_0021cca0(table3, 0);
    (*setState)(1, FUN_0021cce0(resource));
    D_0096009C_fn((u32*)((u8*)object + 0x860), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x860), 4, 0, 2, 3);
    D_0096009C_fn((u32*)((u8*)object + 0x960), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0x960), 4, 0, 2, 3);
    D_0096009C_fn((u32*)((u8*)object + 0xa60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xa60), 4, 0, 2, 3);
    D_0096009C_fn((u32*)((u8*)object + 0xb60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xb60), 4, 0, 2, 3);
    D_0096009C_fn((u32*)((u8*)object + 0xc60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xc60), 4, 0, 2, 3);
    D_0096009C_fn((u32*)((u8*)object + 0xd60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xd60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 2);
    (*setState)(1, FUN_0021cce0(resource));
    D_0096009C_fn((u32*)((u8*)object + 0xe60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xe60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 3);
    (*setState)(1, FUN_0021cce0(resource));
    D_0096009C_fn((u32*)((u8*)object + 0xf60), 4, 0, 1, 2);
    D_0096009C_fn((u32*)((u8*)object + 0xf60), 4, 0, 2, 3);

    if ((object[0] & 2) != 0) {
        resource = FUN_0021cca0(table3, FUN_0022e850(object[0x14a]));
        (*setState)(1, FUN_0021cce0(resource));
        D_0096009C_fn((u32*)((u8*)object + 0x530), 4, 0, 1, 2);
        D_0096009C_fn((u32*)((u8*)object + 0x530), 4, 0, 2, 3);
    }
    if ((object[0] & 4) != 0) {
        bppPanelDrawParameterLayout_void((void*)object);
    }
}

// FUN_0022E780
void FUN_0022e780(u32* object, u32 command)
{
    u32* panel;
    u32 table;
    u32 mapped;
    u32 style;

    panel = object;
    style = command;
    panel[0x14a] = style;
    table = FUN_0021c3f0(3);
    switch (style) {
    case 0:
        panel[0] &= ~2u;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        mapped = FUN_0022e850(panel[0x14a]);
        FUN_0021d3b0(panel + 0x14c,
                     FUN_0021cca0(table, mapped));
        panel[0] |= 2;
        break;
    }
}

// FUN_0022E850
u32 FUN_0022e850(u32 command)
{
    switch (command) {
    case 1:
        return 0xd;
    case 2:
        return 0xc;
    case 3:
        return 0xe;
    case 4:
        return 0xf;
    case 5:
        return 0x10;
    default:
        K_ASSERT(0, 0x42d);
        return 0;
    }
}

// FUN_0022E900
void FUN_0022e900(u32* object, s32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 2);
    *(u32*)((u8*)object + 0x834) = value;
    FUN_0022ea40((u32*)((u8*)object + 0x860), value);
    denominator = (f32)*(s32*)((u8*)object + 0x838);
    scale = (f32)value / denominator;
    FUN_0022ecb0((u8*)object + 0xe60, resource, scale);
}

// FUN_0022E9A0
void FUN_0022e9a0(u32* object, s32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 3);
    *(u32*)((u8*)object + 0x83c) = value;
    FUN_0022ea40((u32*)((u8*)object + 0xb60), value);
    denominator = (f32)*(s32*)((u8*)object + 0x840);
    scale = (f32)value / denominator;
    FUN_0022ecb0((u8*)object + 0xf60, resource, scale);
}

// FUN_0022EA40
void FUN_0022ea40(u32* object, u32 value)
{
    char text[0x100];
    u32 table;
    s32 i;
    s32 length;

    table = FUN_0021c3f0(3);
    sprintf(text, "%d", value);
    length = strlen(text);
    if (length > 3) {
        K_Assert("bpp_panel.c", 0x45a);
    }
    for (i = 0; i < length; ++i) {
        u32 resource;

        resource = FUN_0021cca0(table, text[length - 1 - i] - '0');
        FUN_0021d3b0((u8*)object + i * 0x100, resource);
    }
}

// FUN_0022EB30
void FUN_0022eb30(u32* object, u32 value, u32 colour)
{
    f32 rect[4];
    char text[0x100];
    u32 table;
    s32 i;
    s32 length;

    table = FUN_0021c3f0(3);
    sprintf(text, "%d", value);
    length = strlen(text);
    if (length > 3) {
        K_Assert("bpp_panel.c", 0x471);
    }
    for (i = 0; i < length; ++i) {
        u32 resource;

        resource = FUN_0021cca0(table, text[length - 1 - i] - '0');
        rect[0] = *(f32*)colour + (f32)((2 - i) * 16);
        rect[1] = *(f32*)(colour + 4);
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0((u8*)object + i * 0x100, rect);
    }
    for (; length < 3; ++length) {
        rect[0] = *(f32*)colour;
        rect[1] = *(f32*)(colour + 4);
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        FUN_0021d8e0((u8*)object + length * 0x100, rect);
    }
}

// FUN_0022ECB0
void FUN_0022ecb0(u8* destination, u8* source, f32 scale)
{
    f32 values[4];
    f32 factor;
    f32 converted;
    u32 value;
    u8* depth;

    factor = 1.0f / *(f32*)((u8*)FUN_00198590() + 0x80);
    FUN_0021cd00(source, values);
    values[2] = values[0] + scale * (values[2] - values[0]);

    *(f32*)(destination + 0x10) = values[0];
    *(f32*)(destination + 0x14) = values[1];
    *(f32*)(destination + 0x18) = factor;
    depth = (u8*)D_00960090 - 8;
    *(f32*)(destination + 0x08) = *(f32*)depth;

    value = source[0x1c];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x20) = converted;
    value = source[0x1d];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x24) = converted;
    value = source[0x1e];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x28) = converted;
    value = source[0x1f];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x2c) = converted;

    *(f32*)(destination + 0x50) = values[2];
    *(f32*)(destination + 0x54) = values[1];
    *(f32*)(destination + 0x58) = factor;
    *(f32*)(destination + 0x48) = *(f32*)depth;

    value = source[0x20];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x60) = converted;
    value = source[0x21];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x64) = converted;
    value = source[0x22];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x68) = converted;
    value = source[0x23];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x6c) = converted;

    *(f32*)(destination + 0x90) = values[2];
    *(f32*)(destination + 0x94) = values[3];
    *(f32*)(destination + 0x98) = factor;
    *(f32*)(destination + 0x88) = *(f32*)depth;

    value = source[0x24];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa0) = converted;
    value = source[0x25];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa4) = converted;
    value = source[0x26];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa8) = converted;
    value = source[0x27];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xac) = converted;

    *(f32*)(destination + 0xd0) = values[0];
    *(f32*)(destination + 0xd4) = values[3];
    *(f32*)(destination + 0xd8) = factor;
    *(f32*)(destination + 0xc8) = *(f32*)depth;

    value = source[0x28];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe0) = converted;
    value = source[0x29];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe4) = converted;
    value = source[0x2a];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe8) = converted;
    value = source[0x2b];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xec) = converted;
}

// FUN_0022F1C0
void FUN_0022f1c0(u32* object, u64 event)
{
    u32 status;
    u64 code;

    status = object[0];
    if ((status & 4) != 0) {
        object[0] = status & ~4u;
    }
    if ((event & 0x80000) != 0) {
        object[0x20c] = 8;
        object[0] |= 4;
    } else {
        code = (event << 0x2c) >> 0x2c;
        switch (code) {
        case 1:
            object[0x20c] = 0;
            object[0] |= 4;
            break;
        case 2:
            object[0x20c] = 1;
            object[0] |= 4;
            break;
        case 4:
            object[0x20c] = 2;
            object[0] |= 4;
            break;
        case 8:
            object[0x20c] = 3;
            object[0] |= 4;
            break;
        case 0x10:
            object[0x20c] = 4;
            object[0] |= 4;
            break;
        case 0x20:
            object[0x20c] = 5;
            object[0] |= 4;
            break;
        case 0x40:
            object[0x20c] = 6;
            object[0] |= 4;
            break;
        case 0x80:
            object[0x20c] = 7;
            object[0] |= 4;
            break;
        case 0x200:
            object[0x20c] = 10;
            object[0] |= 4;
            break;
        }
    }
    if ((object[0] & 4) != 0) {
        FUN_0022f3b0(object);
    }
}

// W418 width negative: FUN_0022F3B0 i s16 nd1087/1724B -> 1279/1876B (over 1744B); reverted.
// FUN_0022F3B0 NONMATCHING
void FUN_0022f3b0(u32* object)
{
    u8* bytes;
    u8* dst;
    u32 table;
    u32 state;
    u32 resource;
    u32 randVal;
    s32 i;
    f32 rect[4];

    bytes = (u8*)object;
    table = FUN_0021c3f0(4);
    state = object[0x20c];

    switch (state) {
    case 0:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0);
        for (i = 0; i < 3; ++i) {
            FUN_0021d3b0(dst + i * 0x100, resource);
        }
        *(u32*)(dst + 0x30c) = 0;
        break;

    case 1:
        dst = bytes + 0x1060;
        for (i = 0; i < 3; ++i) {
            u8* slot = dst + i * 0x200;
            resource = FUN_0021cca0(table, 1);
            FUN_0021d3b0(slot, resource);
            resource = FUN_0021cca0(table, 2);
            FUN_0021d3b0(slot + 0x100, resource);
        }
        *(u32*)(dst + 0x60c) = 0;
        break;

    case 2:
        dst = bytes + 0x1060;
        for (i = 0; i < 3; ++i) {
            u8* slot = dst + i * 0x100;
            randVal = RpRandom() % 5;
            switch (randVal) {
            case 4: resource = FUN_0021cca0(table, 7); break;
            case 3: resource = FUN_0021cca0(table, 6); break;
            case 2: resource = FUN_0021cca0(table, 5); break;
            case 1: resource = FUN_0021cca0(table, 4); break;
            case 0: resource = FUN_0021cca0(table, 3); break;
            }
            FUN_0021d3b0(slot, resource);
            *(u32*)(dst + i * 4 + 0x300) = (i * 3 * 4) / 3;
        }
        *(u32*)(dst + 0x30c) = 0;
        break;

    case 3:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 8);
        FUN_0021d3b0(dst, resource);
        FUN_0021d3b0(dst + 0x100, resource);
        FUN_0021cd00(resource, rect);
        {
            f32 tmp = rect[0];
            rect[0] = rect[2];
            rect[2] = tmp;
        }
        FUN_0021eae0(dst + 0x100, rect);
        randVal = RpRandom() % 30;
        *(u32*)(dst + 0x20c) = randVal;
        for (i = 0; i < 2; ++i) {
            s32 value = randVal + (i * 15 * 2) / 2;
            *(u32*)(dst + 0x200 + i * 4) = value;
            *(u32*)(dst + 0x200 + i * 4) = value % 30;
        }
        break;

    case 4:
    case 10:
        dst = bytes + 0x1060;
        for (i = 0; i < 2; ++i) {
            u8* slot = dst + i;
            u8 bit = (u8)(RpRandom() & 1);
            *slot = bit;
            if (bit == 1) {
                resource = FUN_0021cca0(table, 9);
            } else if (bit == 0) {
                resource = FUN_0021cca0(table, 9);
            }
            FUN_0021d3b0(dst + i * 0x100, resource);
            *(u32*)(dst + i * 4 + 0x200) = (i * 3 * 4) / 2;
        }
        *(u32*)(dst + 0x20c) = 0;
        break;

    case 5:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0xb);
        FUN_0021d3b0(dst, resource);
        FUN_0021d3b0(dst + 0x100, resource);
        resource = FUN_0021cca0(table, 0xc);
        for (i = 0; i < 3; ++i) {
            *(u8*)(dst + i) = (u8)i;
            FUN_0021d3b0(dst + i * 0x100 + 0x200, resource);
            *(u32*)(dst + i * 4 + 0x500) = (i * 5 * 8) / 3;
        }
        *(u32*)(dst + 0x510) = 0;
        break;

    case 6:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0xd);
        FUN_0021d3b0(dst, resource);
        resource = FUN_0021cca0(table, 0xe);
        FUN_0021d3b0(dst + 0x100, resource);
        resource = FUN_0021cca0(table, 0xe);
        FUN_0021d3b0(dst + 0x200, resource);
        randVal = RpRandom() % 20;
        *(u32*)(dst + 0x300) = randVal;
        break;

    case 7:
        dst = bytes + 0x1060;
        for (i = 0; i < 4; ++i) {
            u8* slot = dst + i;
            u8 bit1 = (u8)(RpRandom() & 1);
            u8 bit2 = (u8)(RpRandom() & 1);
            u8 bit3;
            *(slot + 0x410) = bit1;
            *(slot + 0x414) = bit2;
            bit3 = (u8)(RpRandom() & 1);
            *(slot + 0x418) = bit3;
            if (bit1 == 1) {
                resource = FUN_0021cca0(table, 0x10);
            } else if (bit1 == 0) {
                resource = FUN_0021cca0(table, 0xf);
            }
            FUN_0021d3b0(dst + i * 0x100, resource);
            *(u32*)(dst + i * 4 + 0x400) = (i * 5 * 8) / 4;
        }
        *(u32*)(dst + 0x41c) = 0;
        break;

    case 8:
        resource = FUN_0021cca0(table, 0x11);
        FUN_0021d3b0(bytes + 0x1060, resource);
        break;

    case 9:
        resource = FUN_0021cca0(table, 0);
        FUN_0021d3b0(bytes + 0x1060, resource);
        break;
    }
}

// Partially reconstructed. Retail dispatches on the state at byte 0x830
// (object[0x20c]) through an 11-entry jump table at 0x7b77e0, decoded from the
// retail ELF as [0x22fb44, 0x230078, 0x2305e4, 0x230bf0, 0x231108, 0x2316d8,
// 0x231c7c, 0x2328a4, 0x232d70, 0x232dd8, 0x231108] - ten distinct bodies with
// cases 4 and 10 sharing one. Each case opens by bumping its own animation
// counter or fetching its own panel resource; those verified openings are
// implemented here. The case bodies themselves (panel layout, sinf/cosf corner
// rotation, alpha threshold chains) are still unrecovered and are the bulk of
// the 13344-byte window.
/* W415 census negative: retail's missing six sine/cosine pairs are one second-pair recomputation in each case-1 phase and cases 2, 3, 4, and 5. A minimal six-pair probe reached 113 calls and nd10336 but grew 13344 to 13488 bytes (144 bytes over the window), so it was reverted; no soft-double glue was present to fund the required saving. */
/* W418 negative probe: case-0 i narrowed u32->s16 regressed nd10216/13344B -> nd10408/13432B (over the 13344B window); reverted. */
/* W418 width negatives for FUN_0022FA80: case2 i/j/k s16 -> nd10373/10299/10295 with object 13416/13360/13360B; case3 i/j -> nd10288/10419 with object 13392/13440B; case4 i -> nd10304/13424B; case5 i -> nd10314/13392B; case6 i -> nd10385/13488B; case7 i -> nd10357/13400B. All were worse or over the 13344B window; reverted. */
// FUN_0022FA80 NONMATCHING
void FUN_0022fa80(u32* object)
{
    u8* bytes;
    u32 i;
    u32 table;
    u32 state;
    f32 offset_x;
    f32 offset_y;
    union {
        struct {
            f32 values[12];
            u8 reserved[28];
            u8 rgba[4];
        } active;
    } scratch;
#define rect_work scratch.active.values
#define colour scratch.active.rgba
#define rect scratch.active.values
#define rect0 scratch.active.values
#define rect1 (scratch.active.values + 4)
#define rect2 (scratch.active.values + 8)

    bytes = (u8*)object;
    offset_x = *(f32*)(bytes + 0x510) + *(f32*)(bytes + 0x518) + *(f32*)(bytes + 0x520);
    offset_y = *(f32*)(bytes + 0x514) + *(f32*)(bytes + 0x51c) + *(f32*)(bytes + 0x524);
    table = FUN_0021c3f0(4);
    state = object[0x20c];
    switch (state) {
    case 0:
    {
        u8* base;
        u32 resource;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x136c) = *(u32*)(bytes + 0x136c) + 1;

        // Initialize 3 slot counters
        for (i = 0; i < 3; i++) {
            u32 val = *(u32*)(base + 0x30c) + i * 10;
            *(u32*)(base + i * 4 + 0x300) = val % 30;
        }

        // Alpha threshold chain for 3 slots
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x300);
            f32 t = val / 30.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) {
                    alpha = 1.0f;
                }
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }

            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Corner rotation and draw
        resource = FUN_0021cca0(table, 0);
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            for (i = 0; i < 3; i++) {
                f32 x0, y0, x1, y1;

                x0 = D_0068E4F0[i * 4 + 0];
                y0 = D_0068E4F0[i * 4 + 1];
                x1 = D_0068E4F0[i * 4 + 2];
                y1 = D_0068E4F0[i * 4 + 3];

                rect_work[0] = pos_x + x0;
                rect_work[1] = pos_y + y0;
                rect_work[2] = pos_x + x1;
                rect_work[3] = pos_y + y1;
                rect_work[4] = pos_x + x1;
                rect_work[5] = pos_y + y1;
                rect_work[6] = pos_x + x0;
                rect_work[7] = pos_y + y0;

                rect_work[8] = 255.0f * x1;
                rect_work[9] = 255.0f * y1;
                rect_work[10] = 255.0f * x0;
                rect_work[11] = 255.0f * y0;

                FUN_0021e170(base + i * 256, rect_work, rect_work + 4, rect_work + 8);
            }
        }
        break;
    }
    case 1:
    {
        u8* base;
        u32 resource;
        u32 s3, s4;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x166c) = *(u32*)(bytes + 0x166c) + 1;

        // First loop: process 3 slots (counter at base + t0*4 + 0x600)
        for (i = 0; i < 3; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x600) + 1;
            *(u32*)(base + i * 4 + 0x600) = cnt % 10;
        }

        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;

        // Alpha write for 3 slots with 2 sub-slots each
        for (s3 = 0; s3 < 3; s3++) {
            for (s4 = 0; s4 < 2; s4++) {
                f32 cnt_f = (f32)*(u32*)(base + s3 * 4 + 0x600);
                f32 t = cnt_f / 10.0f;
                f32 alpha;

                if (t <= 0.6f) {
                    alpha = t / 0.6f;
                } else if (t <= 0.7f) {
                    alpha = 1.0f;
                } else {
                    alpha = (1.0f - t) / (1.0f - 0.7f);
                }
                if (alpha < 0.0f) {
                    alpha = 0.0f;
                }
                if (s4 == 1) {
                    alpha = alpha * 15.0f / 100.0f;
                }
                colour[3] = (u8)(s32)(alpha * 255.0f);
                FUN_0021d950(base + (s3 * 2 + s4) * 256, colour);
            }
        }

        // Draw phase with rotation for 3 slots
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            resource = FUN_0021cca0(table, 1);
            for (s3 = 0; s3 < 3; s3++) {
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + s3 * 4 + 0x600);
                t = (t + 1.0f) / 10.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E490[s3 * 4 + 0];
                y0 = D_0068E490[s3 * 4 + 1];
                x1 = D_0068E490[s3 * 4 + 2];
                y1 = D_0068E490[s3 * 4 + 3];
                x2 = x1;
                y2 = y1;
                x3 = x0;
                y3 = y0;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                sinf(angle);
                cosf(angle);
                FUN_0021e170(base + s3 * 512, rect0, rect1, rect2);
            }
        }

        // Second draw phase
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            resource = FUN_0021cca0(table, 2);
            for (s3 = 0; s3 < 3; s3++) {
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + s3 * 4 + 0x600);
                t = (t + 1.0f) / 10.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E460[s3 * 4 + 0];
                y0 = D_0068E460[s3 * 4 + 1];
                x1 = D_0068E460[s3 * 4 + 2];
                y1 = D_0068E460[s3 * 4 + 3];
                x2 = x1;
                y2 = y1;
                x3 = x0;
                y3 = y0;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                sinf(angle);
                cosf(angle);
                FUN_0021e170(base + s3 * 512 + 256, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 2:
    {
        u8* base;
        u32 resource;
        u32 i;
        u32 j;
        u32 k;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1374) = *(u32*)(bytes + 0x1374) + 1;

        // Slot reset loop: counter check, random type assignment, collision avoidance, resource dispatch
        for (i = 0; i < 3; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x300) + 1;
            *(u32*)(base + i * 4 + 0x300) = cnt;
            if (cnt >= 12) {
                u32 type_byte;
                u32 flag;

                type_byte = RpRandom() % 5;
                *(base + i + 0x30c) = (u8)type_byte;
                flag = RpRandom() & 3;

                // Collision avoidance: ensure unique type across slots
                for (j = 0; j < 3; j++) {
                    for (k = 0; k < 3; k++) {
                        if (k == i) continue;
                        if (*(base + k + 0x30f) == flag) {
                            flag++;
                            k = 0xFFFFFFFF;
                            continue;
                        }
                    }
                }

                if (flag >= 6) {
                    K_Assert("bcm_panel.c", 0x6e2);
                }
                *(base + i + 0x30f) = (u8)flag;

                // Resource dispatch based on type byte (0-4) at 0x30c
                switch (type_byte) {
                    case 0: resource = FUN_0021cca0(table, 3); break;
                    case 1: resource = FUN_0021cca0(table, 4); break;
                    case 2: resource = FUN_0021cca0(table, 5); break;
                    case 3: resource = FUN_0021cca0(table, 6); break;
                    case 4: resource = FUN_0021cca0(table, 7); break;
                }
                FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)resource);

                cnt = cnt % 12;
                *(u32*)(base + i * 4 + 0x300) = cnt;
            }
        }

        // Alpha threshold chain for 3 slots (threshold 12)
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x300);
            f32 t = val / 12.0f;
            f32 alpha;

            if (t <= 0.0f) {
                alpha = 0.0f;
            } else if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) {
                    alpha = 1.0f;
                }
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Draw section with type-based resource dispatch and corner rotation
        {
            f32 pos_x = 90.0f + offset_x;
            f32 pos_y = 40.0f + offset_y;
            for (i = 0; i < 3; i++) {
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;
                u32 type;

                type = *(base + i + 0x30f);
                switch (type) {
                    case 0: resource = FUN_0021cca0(table, 3); break;
                    case 1: resource = FUN_0021cca0(table, 4); break;
                    case 2: resource = FUN_0021cca0(table, 5); break;
                    case 3: resource = FUN_0021cca0(table, 6); break;
                    case 4: resource = FUN_0021cca0(table, 7); break;
                }

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + i * 4 + 0x300);
                t = (t + 1.0f) / 12.0f;
                angle = 0.0f;  // retail uses sinf(0)/cosf(0) for non-rotating draw
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E4F0[i * 4 + 0];
                y0 = D_0068E4F0[i * 4 + 1];
                x1 = D_0068E4F0[i * 4 + 2];
                y1 = D_0068E4F0[i * 4 + 3];
                x2 = D_0068E4F0[i * 4 + 2];
                y2 = D_0068E4F0[i * 4 + 3];
                x3 = D_0068E4F0[i * 4 + 0];
                y3 = D_0068E4F0[i * 4 + 1];

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;

                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                sinf(angle);
                cosf(angle);
                FUN_0021e170(base + i * 256, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 3:
    {
        u8* base = bytes + 0x1060;
        u32 resource;
        u32 i;
        u32 j;
        f32 pos_x0, pos_y0;
        f32 pos_x1, pos_y1;
        f32 size_w, size_h;

        resource = FUN_0021cca0(table, 8);
        *(u32*)(bytes + 0x126c) = *(u32*)(bytes + 0x126c) + 1;

        // First loop: initialize 2 slots with counters at base + i*4 + 0x200
        for (i = 0; i < 2; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x200) + 1;
            *(u32*)(base + i * 4 + 0x200) = cnt;
            if (cnt >= 30) {
                *(base + i + 0x208) = (u8)RpRandom();
                cnt = cnt % 30;
                *(u32*)(base + i * 4 + 0x200) = cnt;
            }
        }

        // Position constants
        pos_x0 = 80.0f + offset_x;  // f22
        pos_y0 = 15.0f + offset_y;  // f21
        pos_x1 = 40.0f + offset_x;  // f20
        pos_y1 = 10.0f + offset_y;  // f31

        // Outer loop: two slots
        for (i = 0; i < 2; i++) {
            f32 cnt_f;
            f32 t;
            f32 scale_x, scale_y;
            f32 cx, cy;
            f32 f26, f25;
            f32 angle;
            f32 s, c;
            f32 tmp;

            cnt_f = (f32)*(u32*)(base + i * 4 + 0x200);
            t = cnt_f / 30.0f;

            if (i == 0) {
                rect[0] = pos_x0; rect[1] = pos_y0;
                f26 = pos_x0;
                f25 = pos_y0 + (f32)((u32*)resource)[4];
            } else {
                rect[0] = pos_x1; rect[1] = pos_y1;
                f26 = pos_x1 + (f32)((u32*)resource)[3];
                f25 = pos_y1 + (f32)((u32*)resource)[4];
            }
            size_w = (f32)((u32*)resource)[3];
            size_h = (f32)((u32*)resource)[4];
            rect[2] = rect[0] + size_w; rect[3] = rect[1];
            rect[4] = rect[2]; rect[5] = rect[1] + size_h;
            rect[6] = rect[0]; rect[7] = rect[5];

            // Make relative to (f26, f25)
            cx = f26;
            cy = f25;
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] -= cx;
                rect[j * 2 + 1] -= cy;
            }

            // Scale
            if (i == 0) {
                scale_x = cnt_f + cnt_f * t * 0.5f;
                scale_y = scale_x;
            } else {
                scale_x = cnt_f + cnt_f * t * 0.25f;
                scale_y = scale_x;
            }
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] *= scale_x;
                rect[j * 2 + 1] *= scale_y;
            }

            // Rotation angle from random byte
            {
                f32 rand_f = (f32)(s32)(s8)*(base + i + 0x208);
                angle = rand_f * 40.0f / 256.0f / 360.0f;
                angle = angle * 2.0f * 3.14159265f;
            }

            // Rotate 4 corners
            s = sinf(angle);
            c = cosf(angle);
            for (j = 0; j < 4; j++) {
                f32 x = rect[j * 2 + 0];
                f32 y = rect[j * 2 + 1];
                rect[j * 2 + 0] = x * c - y * s;
                rect[j * 2 + 1] = x * s + y * c;
            }

            // Add back (cx, cy)
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] += cx;
                rect[j * 2 + 1] += cy;
            }

            // Draw rect
            sinf(angle);
            cosf(angle);
            FUN_0021d890(base + i * 256, rect);

            // Alpha computation based on counter
            {
                f32 alpha;
                if (cnt_f < 7.0f) {
                    alpha = cnt_f / 7.0f;
                } else if (cnt_f < 20.0f) {
                    alpha = 1.0f;
                } else {
                    alpha = 1.0f - (cnt_f - 20.0f) / 10.0f;
                }
                colour[0] = 0xFF;
                colour[1] = 0xFF;
                colour[2] = 0xFF;
                colour[3] = (u8)(s32)(alpha * 255.0f);
                FUN_0021d950(base + i * 256, colour);
            }
        }
        break;
    }
    case 4:
    case 10:
    {
        u8* base;
        u32 i;
        u32 resource;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x126c) = *(u32*)(bytes + 0x126c) + 1;

        // 2-slot resource assignment
        for (i = 0; i < 2; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x200) + 1;
            *(u32*)(base + i * 4 + 0x200) = cnt;
            if (cnt >= 12) {
                u32 rtype;
                u32 flag;
                u32 inner;

                flag = RpRandom() & 1;
                *(base + i + 0x208) = (u8)flag;
                rtype = RpRandom() % 3;

                // Collision avoidance: ensure unique type among slots
                for (inner = 0; inner < 2; inner++) {
                    if (inner == i) continue;
                    if (*(base + inner + 0x20a) == rtype) {
                        rtype++;
                        inner = 0xFFFFFFFF; // restart search
                        continue;
                    }
                }
                if (rtype >= 3) {
                    K_Assert("bcm_panel.c", 0x7d3);
                }

                *(base + i + 0x20a) = (u8)rtype;
                if (flag == 1) {
                    resource = FUN_0021cca0(table, 9);
                } else if (flag == 0) {
                    resource = FUN_0021cca0(table, 10);
                }
                FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)resource);

                cnt = cnt % 12;
                *(u32*)(base + i * 4 + 0x200) = cnt;
            }
        }

        // Color setup
        if (object[0x20c] == 4) {
            colour[0] = 0xFF; colour[1] = 0xFF;
            colour[2] = 0xFF; colour[3] = 0xFF;
        } else {
            colour[0] = 120; colour[1] = 30;
            colour[2] = 30;  colour[3] = 0xFF;
        }

        // Colour write with alpha computation (from current draw)
        colour[0] = 0xFF; colour[1] = 0xFF;
        colour[2] = 0xFF; colour[3] = 0xFF;
        for (i = 0; i < 2; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x200);
            f32 t = val / 12.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) alpha = 1.0f;
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Draw section: corner rotation and draw with sinf/cosf
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            for (i = 0; i < 2; i++) {
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                u32 flag;

                flag = *(base + i + 0x208);
                if (flag == 1) {
                    resource = FUN_0021cca0(table, 9);
                } else if (flag == 0) {
                    resource = FUN_0021cca0(table, 10);
                }

                t = (f32)*(u32*)(base + i * 4 + 0x200);
                t = (t + 1.0f) / 12.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E4F0[i * 4 + 0];
                y0 = D_0068E4F0[i * 4 + 1];
                x1 = D_0068E4F0[i * 4 + 2];
                y1 = D_0068E4F0[i * 4 + 3];
                x2 = x1;
                y2 = y1;
                x3 = x0;
                y3 = y0;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                sinf(angle);
                cosf(angle);
                FUN_0021e170(base + i * 256, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 5:
    {
        u8* base;
        u32 i;
        u32 resource;
        u32 slot_resource;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1570) = *(u32*)(bytes + 0x1570) + 1;

        // Initial resource and rect draw
        resource = FUN_0021cca0(table, 11);
        rect[0] = 80.0f + offset_x;
        rect[1] = 19.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(base, rect);
        FUN_0021d8e0(base + 256, rect);

        // 3-slot resource assignment
        for (i = 0; i < 3; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x500) + 1;
            *(u32*)(base + i * 4 + 0x500) = cnt;
            if (cnt >= 40) {
                u32 rtype;
                u32 inner;

                // Per-slot alpha write (retail pattern: alpha before resource fetch)
                {
                    f32 a = (f32)cnt / 40.0f;
                    f32 alpha;
                    if (a > 0.7f) {
                        alpha = (1.0f - a) / (1.0f - 0.7f);
                    } else if (a > 0.6f) {
                        alpha = 1.0f;
                    } else {
                        alpha = a / 0.6f;
                    }
                    if (alpha < 0.0f) alpha = 0.0f;
                    colour[0] = 0xFF; colour[1] = 0xFF;
                    colour[2] = 0xFF; colour[3] = (u8)(s32)(alpha * 255.0f);
                    FUN_0021d950(base + i * 256, colour);
                }

                // Fetch the slot resource after the alpha write.
                slot_resource = FUN_0021cca0(table, 12);
                rtype = RpRandom() % 6;

                // Collision avoidance
                for (inner = 0; inner < 3; inner++) {
                    if (inner == i) continue;
                    if (*(base + inner + 0x50c) == rtype) {
                        rtype++;
                        inner = 0xFFFFFFFF;
                        continue;
                    }
                }

                if (rtype >= 6) {
                    K_Assert("bcm_panel.c", 0x7d3);
                }
                *(base + i + 0x50c) = (u8)rtype;

                FUN_0021d3b0(base + i * 256 + 0x200, (u8*)(uintptr_t)slot_resource);

                cnt = cnt % 40;
                *(u32*)(base + i * 4 + 0x500) = cnt;
            }
        }

        // Colour write with alpha computation
        colour[0] = 0xFF; colour[1] = 0xFF;
        colour[2] = 0xFF; colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x500);
            f32 t = val / 40.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) alpha = 1.0f;
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Draw section: corner rotation with sinf/cosf
        {
            f32 pos_x = 80.0f + offset_x;
            f32 pos_y = 19.0f + offset_y;
            resource = FUN_0021cca0(table, 12);
            {
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + 4 + 0x500);
                t = (t + 1.0f) / 40.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = 0.0f;
                y0 = 0.0f;
                x1 = w;
                y1 = 0.0f;
                x2 = w;
                y2 = h;
                x3 = 0.0f;
                y3 = h;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;

                rect2[0] = 255.0f * w;
                rect2[1] = 255.0f * h;
                rect2[2] = 255.0f * 0.0f;
                rect2[3] = 255.0f * 0.0f;

                sinf(angle);
                cosf(angle);
                FUN_0021e170(base, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 6:
    {
        u8* base;
        u32 resource;
        u32 i;
        f32 counter_f;
        f32 pos_x, pos_y;
        f32 cx, cy;
        f32 angle;
        f32 s0, c0;
        f32 t_val;
        f32 size_w, size_h;
        f32 alpha;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1360) = *(u32*)(bytes + 0x1360) + 1;
        *(u32*)(bytes + 0x1360) = *(u32*)(bytes + 0x1360) % 20;
        counter_f = (f32)*(u32*)(bytes + 0x1360);

        resource = FUN_0021cca0(table, 13);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // -- Slot 0 position --
        if ((u32)counter_f < 2) {
            pos_x = 80.0f + 5.0f + offset_x;
            pos_y = 6.0f + offset_y;
        } else if ((u32)counter_f < 12) {
            pos_x = 80.0f + offset_x;
            pos_y = 13.0f + offset_y;
        } else {
            pos_x = 80.0f + offset_x;
            pos_y = 13.0f + offset_y;
        }

        rect[0] = pos_x; rect[1] = pos_y;
        rect[2] = pos_x + size_w; rect[3] = pos_y;
        rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
        rect[6] = pos_x; rect[7] = pos_y + size_h;

        cx = (rect[0] + rect[2]) * 0.5f;
        cy = (rect[1] + rect[5]) * 0.5f;
        for (i = 0; i < 4; i++) {
            rect[i * 2 + 0] -= cx;
            rect[i * 2 + 1] -= cy;
        }

        // Angle from counter
        if ((u32)counter_f < 2) {
            t_val = 0.0f;
        } else if ((u32)counter_f < 12) {
            t_val = (f32)((u32)counter_f - 2) / 10.0f;
        } else if ((u32)counter_f < 18) {
            t_val = 1.0f;
        } else {
            t_val = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
        }

        angle = (1.0f - t_val) * 3.14159265f;

        // Corner pair 0-1
        s0 = sinf(angle);
        c0 = cosf(angle);
        {
            f32 x0 = rect[0] * c0 - rect[1] * s0;
            f32 y0 = rect[0] * s0 + rect[1] * c0;
            f32 x1 = rect[2] * c0 - rect[3] * s0;
            f32 y1 = rect[2] * s0 + rect[3] * c0;
            rect[0] = x0; rect[1] = y0;
            rect[2] = x1; rect[3] = y1;
        }

        // Corner pair 2-3
        s0 = sinf(angle);
        c0 = cosf(angle);
        // Corner pair 2-3
        {
            f32 x2 = rect[4] * c0 - rect[5] * s0;
            f32 y2 = rect[4] * s0 + rect[5] * c0;
            f32 x3 = rect[6] * c0 - rect[7] * s0;
            f32 y3 = rect[6] * s0 + rect[7] * c0;
            rect[4] = x2; rect[5] = y2;
            rect[6] = x3; rect[7] = y3;
        }

        for (i = 0; i < 4; i++) {
            rect[i * 2 + 0] += cx;
            rect[i * 2 + 1] += cy;
        }

        FUN_0021d890(base, rect);

        // Slot 0 alpha
        if ((u32)counter_f < 2) {
            alpha = 0.0f;
        } else if ((u32)counter_f < 12) {
            alpha = 1.0f - (f32)((u32)counter_f - 2) / 10.0f;
        } else if ((u32)counter_f < 18) {
            alpha = 1.0f;
        } else {
            alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
        }
        if (alpha < 0.0f) alpha = 0.0f;
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = (u8)(s32)(alpha * 255.0f);
        FUN_0021d950(base, colour);

        // -- Slots 1 and 2 --
        resource = FUN_0021cca0(table, 14);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // Slot 1
        {
            f32 t_s1;
            if ((u32)counter_f < 6) {
                t_s1 = 0.0f;
            } else if ((u32)counter_f < 15) {
                t_s1 = (f32)((u32)counter_f - 6) / 9.0f;
            } else if ((u32)counter_f < 18) {
                t_s1 = 1.0f;
            } else {
                t_s1 = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }

            angle = (1.0f - t_s1) * 3.14159265f;
            pos_x = 100.0f + offset_x;
            pos_y = 30.0f + offset_y;

            rect[0] = pos_x; rect[1] = pos_y;
            rect[2] = pos_x + size_w; rect[3] = pos_y;
            rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
            rect[6] = pos_x; rect[7] = pos_y + size_h;

            cx = (rect[0] + rect[2]) * 0.5f;
            cy = (rect[1] + rect[5]) * 0.5f;
            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] -= cx;
                rect[i * 2 + 1] -= cy;
            }

            // Corner pair 0-1
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x0 = rect[0] * c0 - rect[1] * s0;
                f32 y0 = rect[0] * s0 + rect[1] * c0;
                f32 x1 = rect[2] * c0 - rect[3] * s0;
                f32 y1 = rect[2] * s0 + rect[3] * c0;
                rect[0] = x0; rect[1] = y0;
                rect[2] = x1; rect[3] = y1;
            }

            // Corner pair 2-3
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x2 = rect[4] * c0 - rect[5] * s0;
                f32 y2 = rect[4] * s0 + rect[5] * c0;
                f32 x3 = rect[6] * c0 - rect[7] * s0;
                f32 y3 = rect[6] * s0 + rect[7] * c0;
                rect[4] = x2; rect[5] = y2;
                rect[6] = x3; rect[7] = y3;
            }

            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] += cx;
                rect[i * 2 + 1] += cy;
            }

            FUN_0021d890(base + 0x100, rect);

            if ((u32)counter_f < 6) {
                alpha = 0.0f;
            } else if ((u32)counter_f < 15) {
                alpha = 1.0f - (f32)((u32)counter_f - 6) / 9.0f;
            } else if ((u32)counter_f < 18) {
                alpha = 1.0f;
            } else {
                alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[0] = 0xFF;
            colour[1] = 0xFF;
            colour[2] = 0xFF;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + 0x100, colour);
        }
        // Fetch resource again for slot 2 (retail fetches id 14 twice)
        resource = FUN_0021cca0(table, 14);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // Slot 2
        {
            f32 t_s2;
            if ((u32)counter_f < 7) {
                t_s2 = 0.0f;
            } else if ((u32)counter_f < 16) {
                t_s2 = (f32)((u32)counter_f - 7) / 9.0f;
            } else if ((u32)counter_f < 18) {
                t_s2 = 1.0f;
            } else {
                t_s2 = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }

            angle = (1.0f - t_s2) * 3.14159265f;
            pos_x = 100.0f + offset_x;
            pos_y = 30.0f + offset_y + (5.0f * ((f32)((u32)counter_f) / 20.0f));

            rect[0] = pos_x; rect[1] = pos_y;
            rect[2] = pos_x + size_w; rect[3] = pos_y;
            rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
            rect[6] = pos_x; rect[7] = pos_y + size_h;

            cx = (rect[0] + rect[2]) * 0.5f;
            cy = (rect[1] + rect[5]) * 0.5f;
            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] -= cx;
                rect[i * 2 + 1] -= cy;
            }

            // Corner pair 0-1
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
            f32 x0 = rect[0] * c0 - rect[1] * s0;
            f32 y0 = rect[0] * s0 + rect[1] * c0;
            f32 x1 = rect[2] * c0 - rect[3] * s0;
            f32 y1 = rect[2] * s0 + rect[3] * c0;
            }

            // Corner pair 2-3
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x2 = rect[4] * c0 - rect[5] * s0;
                f32 y2 = rect[4] * s0 + rect[5] * c0;
                f32 x3 = rect[6] * c0 - rect[7] * s0;
                f32 y3 = rect[6] * s0 + rect[7] * c0;
                rect[4] = x2; rect[5] = y2;
                rect[6] = x3; rect[7] = y3;
            }

            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] += cx;
                rect[i * 2 + 1] += cy;
            }

            FUN_0021d890(base + 0x200, rect);

            if ((u32)counter_f < 7) {
                alpha = 0.0f;
            } else if ((u32)counter_f < 16) {
                alpha = 1.0f - (f32)((u32)counter_f - 7) / 9.0f;
            } else if ((u32)counter_f < 18) {
                alpha = 1.0f;
            } else {
                alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[0] = 0xFF;
            colour[1] = 0xFF;
            colour[2] = 0xFF;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + 0x200, colour);
        }
        break;
    }
    case 7:
    {
        u32 i;
        u8* base = bytes + 0x1060;
        f32 pos_x;
        f32 pos_y;
        u32 resource;

        *(u32*)(bytes + 0x147c) = *(u32*)(bytes + 0x147c) + 1;
        // First loop: counter management and random resource assignment
        for (i = 0; i < 4; i++) {
            u32* slot = (u32*)(base + i * 4);
            u32 cnt = slot[0x100] + 1;
            slot[0x100] = cnt;
            if (cnt >= 40) {
                u8* record = base + i;
                record[0x410] = RpRandom() & 1;
                record[0x414] = (u8)RpRandom();
                record[0x418] = RpRandom() & 1;
                {
                    u32 res;
                    if (record[0x410] == 0) {
                        res = FUN_0021cca0(table, 0x0f);
                    } else if (record[0x410] == 1) {
                        res = FUN_0021cca0(table, 0x10);
                    } else {
                        res = 0;
                    }
                    FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)res);
                }
                slot[0x100] = cnt % 40;
            }
        }
        // Second loop: colour write with alpha computation
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 4; i++) {
            f32 val = (f32)((u32*)(base + i * 4))[0x100];
            f32 alpha;
            u32 alpha_bits;

            alpha = val / 40.0f;
            if (alpha <= 0.0f) {
                alpha = 0.0f;
            } else if (alpha <= 0.6f) {
                alpha = alpha / 0.6f;
            } else if (alpha <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - alpha) / (1.0f - 0.7f);
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }
        // Third loop: corner rotation and draw
        pos_x = 66.0f + offset_x;
        pos_y = 11.0f + offset_y;
        for (i = 0; i < 4; i++) {
            f32 angle;
            f32 s, c;
            f32 x0, y0, x1, y1, x2, y2, x3, y3;
            f32 t;

            // Fetch resource for draw based on flag
            if (*(base + i + 0x410) == 0) {
                resource = FUN_0021cca0(table, 0x0f);
            } else if (*(base + i + 0x410) == 1) {
                resource = FUN_0021cca0(table, 0x10);
            } else {
                resource = 0;
            }

            t = (f32)((u32*)(base + i * 4))[0x100];
            t = (t + 1.0f) / 40.0f;
            angle = (1.0f - t) * 3.14159f;
            s = sinf(angle);
            c = cosf(angle);
            x0 = D_0068E4F0[i * 4 + 0];
            y0 = D_0068E4F0[i * 4 + 1];
            x1 = D_0068E4F0[i * 4 + 2];
            y1 = D_0068E4F0[i * 4 + 3];
            x2 = D_0068E4F0[i * 4 + 2];
            y2 = D_0068E4F0[i * 4 + 3];
            x3 = D_0068E4F0[i * 4 + 0];
            y3 = D_0068E4F0[i * 4 + 1];
            rect0[0] = pos_x + x0 * c - y0 * s;
            rect0[1] = pos_y + x0 * s + y0 * c;
            rect0[2] = pos_x + x1 * c - y1 * s;
            rect0[3] = pos_y + x1 * s + y1 * c;
            rect1[0] = pos_x + x2 * c - y2 * s;
            rect1[1] = pos_y + x2 * s + y2 * c;
            rect1[2] = pos_x + x3 * c - y3 * s;
            rect1[3] = pos_y + x3 * s + y3 * c;
            rect2[0] = 255.0f * D_0068E4F0[i * 4 + 2];
            rect2[1] = 255.0f * D_0068E4F0[i * 4 + 3];
            rect2[2] = 255.0f * D_0068E4F0[i * 4 + 0];
            rect2[3] = 255.0f * D_0068E4F0[i * 4 + 1];
            sinf(angle);
            cosf(angle);
            FUN_0021e170(base + i * 256, rect0, rect1, rect2);
        }
        break;
    }
    case 8:
    {
        u32 resource;

        resource = FUN_0021cca0(table, 0x11);
        rect[0] = 39.0f + offset_x;
        rect[1] = 13.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(bytes + 0x1060, rect);
        break;
    }
    case 9:
    {
        u32 resource;

        resource = FUN_0021cca0(table, 0);
        rect[0] = 60.0f + offset_x;
        rect[1] = 41.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(bytes + 0x1060, rect);
        break;
    }
    }
#undef rect2
#undef rect1
#undef rect0
#undef rect
#undef colour
#undef rect_work
}















// W418 width negative: bppPanelDrawParameterLayout i s16 nd416/2276B -> 1520/2444B (over 2288B); reverted.
// FUN_00232EA0 NONMATCHING
void bppPanelDrawParameterLayout(BppPanelWork* work)
{
    u32 texture;
    BppPanelSetRenderState* setRenderState;
    BppPanelRenderQuad* renderQuad;
    u8* quad;
    s32 i;
    u32 frame;
    texture = func_0021c3f0(4);
    setRenderState = (BppPanelSetRenderState*)D_00960090;
    BPP_PANEL_SET_RENDER_STATE(9, 2);
    switch (work->layout) {
    case 0:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 3; i++) {
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE;
            /* Removing this final barrier worsens bppPanelDrawParameterLayout (nd416 -> nd475) - measured W164. */
            asm ("" : "+m"(quad));
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        }
        break;

    case 1:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 1);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 3; i++) {
            quad = (u8*)work + i * (BPP_PANEL_QUAD_SIZE * 2);
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * (BPP_PANEL_QUAD_SIZE * 2), 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * (BPP_PANEL_QUAD_SIZE * 2), 4, 0, 2, 3);
        }
        break;

    case 2:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 3);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 3; i++) {
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE;
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        }
        break;

    case 3:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 8);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        renderQuad = (BppPanelRenderQuad*)D_0096009c;
        
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 2, 3);
        BPP_PANEL_RENDER_QUAD((u8*)work + BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD((u8*)work + BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        break;

    case 4:
    case 10:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 9);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 2; i++) {
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        }
        break;

    case 5:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0xb);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        renderQuad = (BppPanelRenderQuad*)D_0096009c;
        
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 2, 3);
        BPP_PANEL_RENDER_QUAD((u8*)work + BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD((u8*)work + BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        for (i = 0; i < 3; i++) {
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE + BPP_PANEL_QUAD_SIZE * 2;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE + BPP_PANEL_QUAD_SIZE * 2, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE + BPP_PANEL_QUAD_SIZE * 2, 4, 0, 2, 3);
        }
        break;

    case 6:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0xd);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 3; i++) {
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE;
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        }
        break;

    case 7:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0xf);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        
        for (i = 0; i < 4; i++) {
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE;
            renderQuad = (BppPanelRenderQuad*)D_0096009c;
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 1, 2);
            BPP_PANEL_RENDER_QUAD((u8*)work + i * BPP_PANEL_QUAD_SIZE, 4, 0, 2, 3);
        }
        break;

    case 8:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0x11);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        renderQuad = (BppPanelRenderQuad*)D_0096009c;
        
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 2, 3);
        break;

    case 9:
        work = (BppPanelWork*)((u8*)work + BPP_PANEL_QUAD_OFFSET);
        frame = func_0021cca0(texture, 0);
        frame = func_0021cce0(frame);
        BPP_PANEL_SET_RENDER_STATE(1, frame);
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        renderQuad = (BppPanelRenderQuad*)D_0096009c;
        
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 1, 2);
        BPP_PANEL_RENDER_QUAD(work, 4, 0, 2, 3);
        break;
    }
}

// FUN_00233790
void bppPanelRequestStatusRefresh(BppPanelWork* work)
{
    work->flags |= BPP_PANEL_FLAG_STATUS_REFRESH;
}

// FUN_002337B0
void bppPanelCancelStatusRefresh(BppPanelWork* work)
{
    work->refreshTimer = 0;
    work->flags |= BPP_PANEL_FLAG_STATUS_REFRESH_PENDING;
    work->flags &= ~BPP_PANEL_FLAG_STATUS_REFRESH;
}

// FUN_002337E0
void bppPanelActivateDetail(BppPanelWork* work)
{
    K_ASSERT((~work->flags & BPP_PANEL_FLAG_VISIBLE) != 0, 0xb4e);
    work->detailTimer = 0;
    work->flags |= BPP_PANEL_FLAG_DETAIL_ACTIVE;
    work->flags |= BPP_PANEL_FLAG_VISIBLE;
}

// FUN_00233850
void bppPanelDeactivateDetail(BppPanelWork* work)
{
    K_ASSERT(work->flags & BPP_PANEL_FLAG_VISIBLE, 0xb58);
    work->flags &= ~BPP_PANEL_FLAG_DETAIL_ACTIVE;
    work->detailTimer = 0;
    work->flags |= BPP_PANEL_FLAG_DETAIL_CLOSING;
    work->flags &= ~BPP_PANEL_FLAG_VISIBLE;
}

// FUN_002338D0
void bppPanelShow(BppPanelWork* work)
{
    work->flags |= BPP_PANEL_FLAG_VISIBLE;
}

// FUN_002338F0
void bppPanelRequestHide(BppPanelWork* work)
{
    work->transitionTimer = 0;
    work->flags |= BPP_PANEL_FLAG_SECONDARY_LAYOUT;
}

// FUN_00233910
void bppPanelEnableActionOverlay(BppPanelWork* work)
{
    work->flags |= BPP_PANEL_FLAG_ACTION_OVERLAY;
}

// FUN_00233930
void bppPanelDisableActionOverlay(BppPanelWork* work)
{
    work->flags &= ~BPP_PANEL_FLAG_ACTION_OVERLAY;
}

// FUN_00233950
void bppPanelSetPrimaryAnimation(float value, BppPanelWork* work)
{
    work->primaryAnimation = value;
}

// FUN_00233960
void bppPanelSetSecondaryAnimation(float value, BppPanelWork* work)
{
    work->secondaryAnimation = value;
}
