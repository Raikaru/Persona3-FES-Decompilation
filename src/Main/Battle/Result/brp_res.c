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

// FUN_0024BA50 NONMATCHING
void func_0024ba50(void)
{
    u32 i;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    if ((sBrpResWork[1] & 1) != 0)
    {
        for (i = 0; i < 4; i++)
        {
            RwFree((void*)(uintptr_t)sBrpResWork[4 + i]);
        }
    }
    if ((sBrpResWork[1] & 2) != 0)
    {
        RwFree((void*)(uintptr_t)sBrpResWork[8]);
    }
    if ((sBrpResWork[1] & 4) != 0)
    {
        RwFree((void*)(uintptr_t)sBrpResWork[9]);
    }
    sBrpResWork = NULL;
}

// FUN_0024BB30 NONMATCHING
void func_0024bb30(void)
{
    u32 i;
    u32 fileSize;
    void* file;
    void* allocation;
    HCdvd* archive;
    HCdvd* stream;

    K_ASSERT(sBrpResWork != NULL, 0x39);
    if ((sBrpResWork[0] & 1) != 0)
    {
        archive = (HCdvd*)(uintptr_t)sBrpResWork[2];
        if (H_Cdvd_IsFileLoaded(archive))
        {
            for (i = 0; i < 6; i++)
            {
                file = H_Cdvd_ArchiveGetFile(archive, (s32)i, &fileSize);
                switch (i)
                {
                    case 0:
                        sflRes0020e800(file);
                        break;
                    case 1:
                        func_0021b4a0(file);
                        break;
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                        allocation = BRP_RES_ALLOC(fileSize, 0x40000);
                        sBrpResWork[4 + i - 2] = (u32)(uintptr_t)allocation;
                        memcpy(allocation, file, fileSize);
                        break;
                    default:
                        K_ASSERT(false, 0x8e);
                        break;
                }
            }
            sBrpResWork[1] |= 1;
            H_Cdvd_Destroy(archive);
            sBrpResWork[0] &= ~1;
        }
    }

    if ((sBrpResWork[0] & 2) != 0)
    {
        stream = (HCdvd*)(uintptr_t)sBrpResWork[3];
        if (H_Cdvd_IsFileLoaded(stream))
        {
            fileSize = stream->fileSize;
            allocation = BRP_RES_ALLOC(fileSize, 0x40000);
            sBrpResWork[8] = (u32)(uintptr_t)allocation;
            memcpy(allocation, stream->fileMemory, fileSize);
            sBrpResWork[1] |= 2;
            H_Cdvd_Destroy(stream);
            sBrpResWork[0] &= ~2;
        }
    }
}

// FUN_0024BE40 NONMATCHING
void func_0024be40(void)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    K_ASSERT((sBrpResWork[1] & 1) == 0, 0xab);
    sBrpResWork[2] = (u32)(uintptr_t)H_Cdvd_Request(sBrpBirthArchivePath,
                                                     HCDVD_FILEARCHIVE);
    sBrpResWork[0] |= 1;
}

// FUN_0024BF80 NONMATCHING
void func_0024bf80(void)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    K_ASSERT((sBrpResWork[0] & 2) == 0, 0xbf);
    K_ASSERT((sBrpResWork[1] & 2) == 0, 0xc0);
    sBrpResWork[3] = (u32)(uintptr_t)H_Cdvd_Request(sBrpCombineMessagePath,
                                                     HCDVD_FILENORMAL);
    sBrpResWork[0] |= 2;
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
