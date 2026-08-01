#include "Kosaka/k_assert.h"
#include "Utils.h"



#pragma alias bseInit FUN_0021b650
#pragma alias bseShutdown FUN_0021b660
#pragma alias bseRequestSelection FUN_0021b670
#pragma alias bseIsSelectionPending FUN_0021b6f0
#pragma alias bseWasSelectionCancelled FUN_0021b740
#pragma alias bseGetSelectionResult FUN_0021b7c0
#pragma alias bseCancelSelection FUN_0021b830
#pragma alias bseCompleteSelection FUN_0021b8b0


static u32* sBseWork; // DAT_007ce300

extern void bpRoot001fe510(u32 request);
extern void FUN_0010a4e0(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern int printf(const char* format, ...);



// FUN_0021b670
void bseRequestSelection(u32 request)
{
    u32* work;
    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    work[1] = request;
    bpRoot001fe510(request);
    *work |= 1;
    *work &= ~2u;
}

// FUN_0021b6f0
u32 bseIsSelectionPending(void)
{
    K_ASSERT(sBseWork != NULL, 0x1e);
    return *sBseWork & 1;
}

// FUN_0021b740
u32 bseWasSelectionCancelled(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    K_ASSERT(~*work & 1, 0x47);
    return *work & 2;
}

// FUN_0021b7c0
u32 bseGetSelectionResult(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    K_ASSERT(~*work & 1, 0x4f);
    return work[2];
}

// FUN_0021b830
void bseCancelSelection(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    FUN_0010a4e0(0, 0, 0, 2);
    *work |= 2;
    *work &= ~1u;
}

// FUN_0021b8b0
void bseCompleteSelection(void* result)
{
    u32* work;
    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    printf("");
    work[2] = (u32)result;
    *work &= ~1u;
}


#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "Main/Battle/Panel/bp_tex.h"
#include "Main/Battle/Panel/bs_root.h"
#include "Main/g_data.h"
#include "rw/rwplcore.h"

static u32* sBpRes; // puGpffffb614 / DAT_007ce304
void func_0021cc20(void* texture);
void func_0021c7e0(void);
void func_0021b940(void);
extern char D_0068E2F0[];
extern char D_0068E310[];
extern char D_0068E330[];
extern char D_0068E350[];
extern void* memcpy(void* dest, const void* src, u32 size);

typedef struct BpResWork
{
    u32 requestFlags;
    u32 destroyFlags;
    HCdvd* bpAllCdvd;
    u8 unkData1[0x20];
    s32 unk_2c[3];
    u8 unkData2[0x0c];
    s32 partyIdx;
    s32 partyIds[3];
} BpResWork;





// FUN_0021b920
void func_0021b920(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBpRes = param_1;
}



/* Removing this loses FUN_0021bcb0 (MATCH nd0 -> MISMATCH nd17) - measured W161. */
