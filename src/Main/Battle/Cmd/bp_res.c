#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "Main/Battle/Panel/bp_tex.h"
#include "Main/Battle/Panel/bs_root.h"
#include "Main/g_data.h"
#include "Kosaka/k_assert.h"
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

// FUN_0021bab0
u32 bpRes0021bab0(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return *sBpRes & 1;
}

// FUN_0021bb00
void bpRes0021bb00(u32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    sBpRes[0x1b] = param_1;
}

// FUN_0021c860
u32 bpRes0021c860(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return *sBpRes & 4;
}

// FUN_0021c930
void bpRes0021c930(void)
{
    int base;
    int i;

    K_ASSERT(sBpRes != NULL, 0x59);
    base = (int)sBpRes;
    K_ASSERT(*(u32*)(base + 4) & 0x100, 0x1f6);
    for (i = 0; i < 3; i++) {
        RwFree(*(void**)(base + i * 4 + 0x78));
    }
    *(u32*)(base + 4) &= 0xfffffeff;
}

// FUN_0021bb60
void bpRes0021bb60(void)
{
    int iVar1;
    int iVar2;

    K_ASSERT(sBpRes != NULL, 0x59);
    iVar1 = (int)sBpRes;
    if ((*(u32*)(iVar1 + 4) & 1) != 0) {
        for (iVar2 = 0; iVar2 < 7; iVar2++) {
            func_0021cc20(*(void**)(iVar1 + iVar2 * 4 + 0x10));
        }
        for (iVar2 = 0; iVar2 < 6; iVar2++) {
            RwFree(*(void**)(iVar1 + iVar2 * 4 + 0x54));
        }
    }
    if ((*(u32*)(iVar1 + 4) & 0x80) != 0) {
        func_0021c7e0();
    }
    if ((*(u32*)(iVar1 + 4) & 0x100) != 0) {
        bpRes0021c930();
    }
    if ((*(u32*)(iVar1 + 4) & 0x10) != 0) {
        func_0021cc20(*(void**)(iVar1 + 0x38));
    }
    if ((*(u32*)(iVar1 + 4) & 0x20) != 0) {
        func_0021cc20(*(void**)(iVar1 + 0x3c));
    }
    if ((*(u32*)(iVar1 + 4) & 0x40) != 0) {
        func_0021cc20(*(void**)(iVar1 + 0x40));
    }
    sBpRes = NULL;
}
// FUN_0021b920
void func_0021b920(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBpRes = param_1;
}

// FUN_0021b940
void func_0021b940(void)
{
    BpResWork* work;
    s32 i;
    s32 j;
    s32* unk_2c;

    K_ASSERT(sBpRes != NULL, 89);
    work = (BpResWork*)sBpRes;

    if (datGetScenarioMode() != 0)
    {
        if (datGetFlag(752))
        {
            work->bpAllCdvd = H_Cdvd_Request(D_0068E2F0, HCDVD_FILEARCHIVE);
        }
        else
        {
            work->bpAllCdvd = H_Cdvd_Request(D_0068E310, HCDVD_FILEARCHIVE);
        }
    }
    else
    {
        work->bpAllCdvd = H_Cdvd_Request(D_0068E330, HCDVD_FILEARCHIVE);
    }

    work->partyIdx = 0;
    for (i = 0; i < 3; i++)
    {
        if (datGetPartyId(i) != 0)
        {
            *(s32*)((s32)work + work->partyIdx * 4 + 0x48) = datGetPartyId(i);
            work->partyIdx++;
        }
    }

    for (j = 0; j < work->partyIdx; j++)
    {
        unk_2c = &work->unk_2c[j];
        *unk_2c = 0;
    }

    work->requestFlags |= 1;
}

// FUN_0021bb50
u64 func_0021bb50(void)
{
    return 0;
}

// FUN_0021bcb0 NONMATCHING
void func_0021bcb0(void)
{
    u32* work;
    u32 fileSize;
    u32 flags;
    void* data;
    void* memory;
    s32 i;
    s32 index;

    K_ASSERT(sBpRes != NULL, 0x59);
    work = sBpRes;
    if ((*work & 1) != 0)
    {
        if ((work[1] & 1) == 0 &&
            H_Cdvd_IsFileLoaded((HCdvd*)(uintptr_t)work[2]) != 0)
        {
            for (i = 0; i < 13; i++)
            {
                data = H_Cdvd_ArchiveGetFile((HCdvd*)(uintptr_t)work[2],
                                             i, &fileSize);
                switch (i)
                {
                case 0: work[4] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 1: work[7] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 2: work[8] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 3: work[9] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 4: work[5] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 5:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x18] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                case 6:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x19] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                case 7:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x16] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                case 8: work[6] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 9:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x15] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                case 10: work[6] = (u32)(uintptr_t)bpTex0021c9f0(data); break;
                case 11:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x17] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                case 12:
                    memory = RwMalloc(fileSize, 0x40000);
                    work[0x1a] = (u32)(uintptr_t)memory;
                    memcpy(memory, data, fileSize);
                    break;
                default:
                    K_ASSERT(0, 0x120);
                    break;
                }
            }
            for (index = 0; index < (s32)work[0x11]; index++)
            {
                flags = 0x10 << (index & 0x1f);
                if ((work[1] & flags) == 0)
                {
                    i = (s32)work[index + 0x12];
                    if (i < 6)
                    {
                        data = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i + 0xb, &fileSize);
                    }
                    else
                    {
                        data = H_Cdvd_ArchiveGetFile(
                            (HCdvd*)(uintptr_t)work[2], i + 10, &fileSize);
                    }
                    work[index + 0xe] =
                        (u32)(uintptr_t)bpTex0021c9f0(data);
                    work[1] |= flags;
                }
            }
            work[1] |= 1;
            H_Cdvd_Destroy((HCdvd*)(uintptr_t)work[2]);
        }
        if ((work[1] & 1) != 0)
        {
            for (index = 0;
                 index < (s32)work[0x11] &&
                 (work[1] & (0x10 << (index & 0x1f))) != 0;
                 index++)
            {
            }
            if (index == (s32)work[0x11])
            {
                *work &= ~1u;
            }
        }
    }
    if ((*work & 2) != 0 &&
        H_Cdvd_IsFileLoaded((HCdvd*)(uintptr_t)work[0x1c]) != 0)
    {
        *work &= ~2u;
        K_ASSERT((~work[1] & 0x80) != 0, 0x15b);
        work[0x1d] = (u32)(uintptr_t)bpTexCreateTmxRaster(
            ((HCdvd*)(uintptr_t)work[0x1c])->fileMemory);
        work[1] |= 0x80;
        H_Cdvd_Destroy((HCdvd*)(uintptr_t)work[0x1c]);
    }
    if ((*work & 4) != 0 &&
        H_Cdvd_IsFileLoaded((HCdvd*)(uintptr_t)work[0x21]) != 0)
    {
        *work &= ~4u;
        K_ASSERT((~work[1] & 0x100) != 0, 0x165);
        for (i = 0; i < 3; i++)
        {
            data = H_Cdvd_ArchiveGetFile((HCdvd*)(uintptr_t)work[0x21],
                                         i, &fileSize);
            memory = RwMalloc(fileSize, 0x40000);
            work[0x1e + i] = (u32)(uintptr_t)memory;
            memcpy(memory, data, fileSize);
        }
        work[1] |= 0x100;
        H_Cdvd_Destroy((HCdvd*)(uintptr_t)work[0x21]);
    }
}

// FUN_0021c3f0
u32 func_0021c3f0(s32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return sBpRes[param_1 + 4];
}

// FUN_0021c450 NONMATCHING
u32 func_0021c450(u32 param_1)
{
    u32* work;
    s32 i;

    K_ASSERT(sBpRes != NULL, 0x59);
    work = sBpRes;
    if ((param_1 & 0xffff) == 1)
    {
        K_ASSERT((work[1] & 1) != 0, 0x193);
        return work[9];
    }
    for (i = 0; i < (s32)work[0x11] &&
         work[i + 0x12] != (param_1 & 0xffff); i++)
    {
    }
    K_ASSERT(i < (s32)work[0x11], 0x19e);
    return work[i + 0xe];
}

// FUN_0021c550 NONMATCHING
u32 func_0021c550(s32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 1) != 0, 0x1a9);
    return sBpRes[param_1 + 0x18];
}

// FUN_0021c5d0 NONMATCHING
u32 func_0021c5d0(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 1) != 0, 0x1b1);
    return sBpRes[0x16];
}

// FUN_0021c640 NONMATCHING
u32 func_0021c640(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 1) != 0, 0x1b9);
    return sBpRes[0x15];
}

// FUN_0021c6b0 NONMATCHING
u32 func_0021c6b0(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 1) != 0, 0x1c1);
    return sBpRes[0x17];
}

// FUN_0021c720 NONMATCHING
u32 func_0021c720(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 1) != 0, 0x1c9);
    return sBpRes[0x1a];
}

// FUN_0021c790
RwRaster* func_0021c790(u32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return bsRootGetRaster(param_1);
}

// FUN_0021c7e0
void func_0021c7e0(void)
{
}

// FUN_0021c7f0 NONMATCHING
void func_0021c7f0(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    sBpRes[0x21] = (u32)(uintptr_t)H_Cdvd_Request(
        D_0068E350, HCDVD_FILENORMAL);
    *sBpRes |= 4;
}

// FUN_0021c8b0 NONMATCHING
u32 func_0021c8b0(s32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    K_ASSERT((sBpRes[1] & 0x100) != 0, 0x1ec);
    return sBpRes[param_1 + 0x1e];
}
