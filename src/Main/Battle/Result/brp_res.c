#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "h_cdvd.h"
#include "rw/rwplcore.h"

extern u32 D_00960178[];
extern void func_0021b4a0(void* resource);
extern void* memcpy(void* destination, const void* source, u32 size);
static const char sBrpBirthArchivePath[] = "battle/result/brp_birth.bin";
static const char sBrpCombineMessagePath[] = "facility/msg/msg_combine.bmd";

#define BRP_RES_ALLOC(size, flags) \
    (*(void* (**)(u32, u32))D_00960178)((size), (flags))
static u32* sBrpResWork; // puGpffffb644

// FUN_0024ba30
void brpRes0024ba30(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBrpResWork = param_1;
}

// FUN_0024BA50
void func_0024ba50(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    work = sBrpResWork;
    if ((work[1] & 1) != 0)
    {
        for (i = 0; i < 4; i++)
        {
            RwFree((void*)(uintptr_t)*(u32*)((u8*)work + i * 4 + 0x10));
        }
    }
    if ((work[1] & 2) != 0)
    {
        RwFree((void*)(uintptr_t)work[8]);
    }
    if ((work[1] & 4) != 0)
    {
        RwFree((void*)(uintptr_t)work[9]);
    }
    sBrpResWork = NULL;
}

// FUN_0024BB30
void func_0024bb30(void)
{
    void* file;
    s32 i;
    u32 fileSize;
    u32* work;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    work = sBrpResWork;
    if ((work[0] & 1) != 0)
    {
        if (H_Cdvd_IsFileLoaded((HCdvd*)(uintptr_t)work[2]))
        {
            for (i = 0; i < 6; i++)
            {
                switch (i)
                {
                    case 0:
                        sflResLoadGroundRasters(H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize));
                        break;
                    case 1:
                        func_0021b4a0(H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize));
                        break;
                    case 2:
                        file = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize);
                        work[4] = (u32)(uintptr_t)BRP_RES_ALLOC(
                            fileSize, 0x40000);
                        memcpy((void*)(uintptr_t)work[4], file,
                               *(volatile u32*)&fileSize);
                        break;
                    case 3:
                        file = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize);
                        work[5] = (u32)(uintptr_t)BRP_RES_ALLOC(
                            fileSize, 0x40000);
                        memcpy((void*)(uintptr_t)work[5], file,
                               *(volatile u32*)&fileSize);
                        break;
                    case 4:
                        file = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize);
                        work[6] = (u32)(uintptr_t)BRP_RES_ALLOC(
                            fileSize, 0x40000);
                        memcpy((void*)(uintptr_t)work[6], file,
                               *(volatile u32*)&fileSize);
                        break;
                    case 5:
                        file = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i, &fileSize);
                        work[7] = (u32)(uintptr_t)BRP_RES_ALLOC(
                            fileSize, 0x40000);
                        memcpy((void*)(uintptr_t)work[7], file,
                               *(volatile u32*)&fileSize);
                        break;
                    default:
                        K_ASSERT(false, 0x8e);
                        break;
                }
            }
            work[1] |= 1;
            H_Cdvd_Destroy((HCdvd*)(uintptr_t)work[2]);
            work[0] &= ~1;
        }
    }

    if ((work[0] & 2) != 0)
    {
        if (H_Cdvd_IsFileLoaded((HCdvd*)(uintptr_t)work[3]))
        {
            work[8] = (u32)(uintptr_t)BRP_RES_ALLOC(
                ((HCdvd*)(uintptr_t)work[3])->fileSize, 0x40000);
            memcpy((void*)(uintptr_t)work[8],
                   ((HCdvd*)(uintptr_t)work[3])->fileMemory,
                   *(volatile u32*)&((HCdvd*)(uintptr_t)work[3])->fileSize);
            work[1] |= 2;
            H_Cdvd_Destroy((HCdvd*)(uintptr_t)work[3]);
            work[0] &= ~2;
        }
    }
}

// FUN_0024BE40
void func_0024be40(void)
{
    u32* work;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    work = sBrpResWork;
    K_ASSERT((~work[1] & 1) != 0, 0xab);
    work[2] = (u32)(uintptr_t)H_Cdvd_Request(sBrpBirthArchivePath,
                                             HCDVD_FILEARCHIVE);
    work[0] |= 1;
}

// FUN_0024BF80
void func_0024bf80(void)
{
    u32* work;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    work = sBrpResWork;
    K_ASSERT((~work[0] & 2) != 0, 0xbf);
    K_ASSERT((~work[1] & 2) != 0, 0xc0);
    work[3] = (u32)(uintptr_t)H_Cdvd_Request(sBrpCombineMessagePath,
                                             HCDVD_FILENORMAL);
    work[0] |= 2;
}

static u32* sBrpRes334; // 007ce334

// FUN_0024bed0
u32 brpRes0024bed0(void)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    return *sBrpResWork & 1;
}

// FUN_0024bf20
u32 brpRes0024bf20(s32 param_1)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    return sBrpResWork[param_1 + 4];
}

// FUN_0024c040
u32 brpRes0024c040(void)
{
    K_ASSERT(sBrpRes334 != NULL, 0x39);
    return *sBrpRes334 & 2;
}

// FUN_0024c090
u32 brpRes0024c090(void)
{
    u32* work;

    K_ASSERT(sBrpRes334 != NULL, 0x39);
    work = sBrpRes334;
    K_ASSERT(work[1] & 2, 0xce);
    return work[8];
}
