#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

typedef struct
{
    u32 flags;
    u32 unused[0x183];
    u32 animationFrame;
    u32 animationMode;
} BrLvpnlWork;

enum
{
    BR_LVPNL_FLAG_ACTIVE = 1 << 0,
    BR_LVPNL_FLAG_ANIMATING = 1 << 1,
    BR_LVPNL_FLAG_VISIBLE = 1 << 2,
    BR_LVPNL_FLAG_DRAW_DISABLED = 1 << 3,
};

static BrLvpnlWork* sBrLvpnl; // DAT_007ce3c8

// FUN_002767e0
void brLvpnlStartEntranceAnimation(void)
{
    BrLvpnlWork* work;

    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    work = sBrLvpnl;
    if (work->flags & BR_LVPNL_FLAG_VISIBLE) {
        work->animationMode = 1;
        work->animationFrame = 0;
        work->flags |= BR_LVPNL_FLAG_ANIMATING;
    } else {
        work->animationMode = 0;
        work->animationFrame = 0;
        work->flags |= BR_LVPNL_FLAG_ANIMATING;
        work->flags |= BR_LVPNL_FLAG_VISIBLE;
    }
}

// FUN_00276870
void brLvpnlDisableDrawing(void)
{
    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    sBrLvpnl->flags |= BR_LVPNL_FLAG_DRAW_DISABLED;
}

// FUN_002768c0
void brLvpnlEnableDrawing(void)
{
    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    sBrLvpnl->flags &= ~BR_LVPNL_FLAG_DRAW_DISABLED;
}
