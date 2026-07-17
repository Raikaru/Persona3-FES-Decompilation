#include "Main/Battle/Panel/bs_root.h"
#include "Main/Battle/Panel/bp_tex.h"
#include "h_cdvd.h"
#include "rw/rwcore.h"

#define BSROOT_INIT_TMXCOUNT 2

// `bpTex0021c9f0` returns an opaque rush-panel sprite resource.
static void* sRushRaster;                        // 007ce3a8
static RwRaster* sRasters[BSROOT_INIT_TMXCOUNT]; // 007ce3a0

// FUN_00267260
void bsRootInit(void)
{
    HCdvd* cdvd;
    s32 contentId;
    void* file;
    u32 fileSize;

    cdvd = H_Cdvd_Request("battle/panel/bs_init.bin", HCDVD_FILENORMAL); // BUG: should be 'HCDVD_FILEARCHIVE'
    H_Cdvd_ReadSync(cdvd);

    for (contentId = 0; contentId < BSROOT_INIT_MAX; contentId++)
    {
        file = H_Cdvd_ArchiveGetFile(cdvd, contentId, &fileSize);

        switch (contentId)
        {
            case BSROOT_INIT_PCADVANTAGE:
                sRasters[contentId] = bpTexCreateTmxRaster(file);
                break;
            case BSROOT_INIT_ECADVANTAGE:
                sRasters[contentId] = bpTexCreateTmxRaster(file);
                break;

            case BSROOT_INIT_RUSH:
                sRushRaster = bpTex0021c9f0(file);
                break;
        }
    }

    H_Cdvd_Destroy(cdvd);
}

// FUN_00267370
RwRaster* bsRootGetRaster(u32 id)
{
    return sRasters[id];
}

// FUN_00267390
void* bsRootGetRushRaster(void)
{
    return sRushRaster;
}
