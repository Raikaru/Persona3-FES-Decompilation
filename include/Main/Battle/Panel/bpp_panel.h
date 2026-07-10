#ifndef BPP_PANEL_H
#define BPP_PANEL_H

#include "Utils.h"

typedef struct BppPanelWork {
    u32 flags;
    u8 reserved_0004[0x82c];
    s32 layout;
    u8 reserved_0834[0x10];
    s32 transitionTimer;
    s32 detailTimer;
    s32 refreshTimer;
    float primaryAnimation;
    float secondaryAnimation;
} BppPanelWork;

enum {
    BPP_PANEL_FLAG_DRAW_PARAMETER_LAYOUT = 0x4,
    BPP_PANEL_FLAG_STATUS_REFRESH = 0x8,
    BPP_PANEL_FLAG_VISIBLE = 0x10,
    BPP_PANEL_FLAG_SECONDARY_LAYOUT = 0x20,
    BPP_PANEL_FLAG_DETAIL_ACTIVE = 0x40,
    BPP_PANEL_FLAG_DETAIL_CLOSING = 0x80,
    BPP_PANEL_FLAG_STATUS_REFRESH_PENDING = 0x100,
    BPP_PANEL_FLAG_ACTION_OVERLAY = 0x200,
};

void bppPanelDrawParameterLayout(BppPanelWork* work);
void bppPanelRequestStatusRefresh(BppPanelWork* work);
void bppPanelCancelStatusRefresh(BppPanelWork* work);
void bppPanelActivateDetail(BppPanelWork* work);
void bppPanelDeactivateDetail(BppPanelWork* work);
void bppPanelShow(BppPanelWork* work);
void bppPanelRequestHide(BppPanelWork* work);
void bppPanelEnableActionOverlay(BppPanelWork* work);
void bppPanelDisableActionOverlay(BppPanelWork* work);
void bppPanelSetPrimaryAnimation(float value, BppPanelWork* work);
void bppPanelSetSecondaryAnimation(float value, BppPanelWork* work);

#endif
