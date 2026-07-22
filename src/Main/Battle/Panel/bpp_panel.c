#include "Main/Battle/Panel/bpp_panel.h"
#include "Kosaka/k_assert.h"

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


// FUN_00232EA0 NONMATCHING
void bppPanelDrawParameterLayout(BppPanelWork* work)
{
    u32 texture;
    BppPanelSetRenderState* setRenderState;
    u8* quad;
    BppPanelRenderQuad* renderQuad;
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
            asm volatile("" : "+m"(quad));
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
            asm volatile("" : "+m"(quad));
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
            asm volatile("" : "+m"(quad));
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
            quad = (u8*)work + i * BPP_PANEL_QUAD_SIZE;
            asm volatile("" : "+m"(quad));
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
            asm volatile("" : "+m"(quad));
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
            asm volatile("" : "+m"(quad));
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
            asm volatile("" : "+m"(quad));
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
