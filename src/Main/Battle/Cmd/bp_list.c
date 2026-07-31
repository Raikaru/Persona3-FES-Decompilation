#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

// "bas" (original file name: bas_main.c) is the thin request interface for the
// battle "analyze" command: the battle command menu (bcm_main.c) requests an
// enemy analyze page here, bp_root.c opens it (bpRootRequestAnalyze) and
// acknowledges completion through basClearAnalyzePending.

// BasWork.flags
#define BAS_PENDING 1 // an analyze request is in flight

// 8 bytes. Lives inside bp_root's panel work data
typedef struct
{
    u32 flags;  // 0x00. See 'BAS_*'
    u32 unitId; // 0x04. Unit whose analyze page was requested
} BasWork;

static BasWork* sBasWork; // puGpffffb63c

void bpRootRequestAnalyze(u32 unitId); // bp_root.c

// FUN_0024a6c0
void basInit(BasWork* work)
{
    work->flags = 0;
    sBasWork = work;
}

// FUN_0024a6d0
void basShutdown(void)
{
    sBasWork = NULL;
}



