#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_res.h"
#include "rw/rwplcore.h"

extern int H_Cdvd_IsFileLoaded(u32 request);
extern void H_Cdvd_Destroy(u32 request);
extern void* H_Cdvd_ArchiveGetFile(u32 archive, s32 index, u32* size);
extern u32 bpTex0021c9f0(void* data);
extern u32 bpTexCreateTmxRaster(void* data);
extern void func_0021cc20(u32 texture);
extern void func_004cde90(u32 resource);
extern void* memcpy(void* dest, const void* src, u32 size);
extern void (*jtbl_0096017C)(void* memory);

static u32* sBrRes; // puGpffffb61c
extern char DAT_0068e6b0[];
extern char DAT_0068e6d0[];
extern char DAT_0068e6f0[];
extern char DAT_0068e710[];
extern char DAT_0068e730[];
extern char DAT_0068e750[];
extern char DAT_0068e770[];
int datGetScenarioMode();
int datGetFlag();
u32 H_Cdvd_Request();

// FUN_00233970
void brRes00233970(u32* param_1)
{
    K_ASSERT(sBrRes == NULL, 0x58);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    sBrRes = param_1;
}


// FUN_002339d0
void brRes002339d0(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 1) != 0, 0x65);
    lVar3 = datGetScenarioMode();
    if (lVar3 != 0) {
        lVar3 = datGetFlag(0x2f0);
        if (lVar3 != 0) {
            puVar1[3] = H_Cdvd_Request(DAT_0068e6b0, 1);
        } else {
            puVar1[3] = H_Cdvd_Request(DAT_0068e6d0, 1);
        }
    } else {
        puVar1[3] = H_Cdvd_Request(DAT_0068e6f0, 1);
    }
    *puVar1 |= 1;
}

// FUN_00233ad0
u32 brRes00233ad0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 1;
}

// FUN_00233b20
void brRes00233b20(void)
{
    u32* puVar1;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 2) != 0, 0x7e);
    puVar1[4] = H_Cdvd_Request(DAT_0068e710, 1);
    *puVar1 |= 2;
}

// FUN_00233bb0
u32 brRes00233bb0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 2;
}

// FUN_00233c00
void brRes00233c00(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 4) != 0, 0x8c);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x8d);
    lVar3 = datGetScenarioMode();
    if (lVar3 != 0) {
        lVar3 = datGetFlag(0x2f0);
        if (lVar3 != 0) {
            puVar1[5] = H_Cdvd_Request(DAT_0068e730, 1);
        } else {
            puVar1[5] = H_Cdvd_Request(DAT_0068e750, 1);
        }
    } else {
        puVar1[5] = H_Cdvd_Request(DAT_0068e770, 1);
    }
    *puVar1 |= 4;
}

// FUN_00233d20
u32 brRes00233d20(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[0] & 4;
}

// FUN_00233d70
u32 brRes00233d70(s32 index)
{
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT(work[1] & 0x10, 0xb3);
    return work[index + 0xe];
}

// FUN_00233df0
u32 brRes00233df0(s32 index)
{
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT(work[1] & 0x10, 0xba);
    return work[index + 0x12];
}

// FUN_00233e70
void brRes00233e70(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    if (work[1] & 1) {
        func_0021cc20(work[7]);
    }
    if (work[1] & 2) {
        func_0021cc20(work[8]);
    }
    if (work[1] & 4) {
        for (i = 0; i < 2; i++) {
            (*(void (**)(void*))0x0096017C)(*(void**)((u8*)work + i * 4 + 0x24));
        }
    }
    if (work[1] & 0x40) {
        for (i = 0; i < 2; i++) {
            func_0021cc20(*(u32*)((u8*)work + i * 4 + 0x30));
        }
    }
    if (work[1] & 0x20) {
        (*(void (**)(void*))0x0096017C)((void*)work[11]);
    }
    if (work[1] & 0x10) {
        K_ASSERT(sBrRes != NULL, 0x52);
        work = sBrRes;
        K_ASSERT(work[1] & 0x10, 0xa5);
        for (i = 0; i < 4; i++) {
            func_0021cc20(*(u32*)((u8*)work + i * 4 + 0x38));
        }
        for (i = 0; i < 2; i++) {
            func_004cde90(*(u32*)((u8*)work + i * 4 + 0x48));
        }
        work[1] &= ~0x10;
    }
    sBrRes = NULL;
}

// FUN_00234070
void brRes00234070(void)
{
    u32* work;
    void* data;
    s32 i;
    u32 flags;
    u32 size;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    if (work[0] & 1) {
        flags = work[1];
        if (~flags & 1) {
            K_ASSERT((~flags & 2) != 0, 0xea);
            if (H_Cdvd_IsFileLoaded(work[3])) {
                for (i = 0; i < 2; i++) {
                    switch (i) {
                    case 0:
                        work[7] = bpTex0021c9f0(H_Cdvd_ArchiveGetFile(work[3], i, &size));
                        work[1] |= 1;
                        break;
                    case 1:
                        work[8] = bpTex0021c9f0(H_Cdvd_ArchiveGetFile(work[3], i, &size));
                        work[1] |= 2;
                        break;
                    default:
                        K_ASSERT(0, 0xfe);
                    }
                }
                H_Cdvd_Destroy(work[3]);
            }
        } else {
            K_ASSERT((flags & 1) && (flags & 2), 0x109);
        }
        if ((work[1] & 1) && (work[1] & 2)) {
            work[0] &= ~1;
        }
    }
    if ((work[0] & 2) && H_Cdvd_IsFileLoaded(work[4])) {
        for (i = 0; i < 5; i++) {
            switch (i) {
            case 0:
            {
                void* copy;
                data = H_Cdvd_ArchiveGetFile(work[4], i, &size);
                copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
                work[9] = (u32)copy;
                memcpy(copy, data, *(volatile u32*)&size);
                break;
            }
            case 1:
            {
                void* copy;
                data = H_Cdvd_ArchiveGetFile(work[4], i, &size);
                copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
                work[10] = (u32)copy;
                memcpy(copy, data, *(volatile u32*)&size);
                break;
            }
            case 2:
                brRes00234710(H_Cdvd_ArchiveGetFile(work[4], i, &size), *(volatile u32*)&size);
                break;
            case 3:
                brRes00234690(0, H_Cdvd_ArchiveGetFile(work[4], i, &size));
                break;
            case 4:
                brRes00234690(1, H_Cdvd_ArchiveGetFile(work[4], i, &size));
                break;
            default:
                K_ASSERT(0, 0x132);
            }
        }
        work[1] |= 4;
        H_Cdvd_Destroy(work[4]);
        work[0] &= ~2;
    }
    if ((work[0] & 4) && H_Cdvd_IsFileLoaded(work[5])) {
        for (i = 0; i < 6; i++) {
            void* archiveData;
            archiveData = H_Cdvd_ArchiveGetFile(work[5], i, &size);
            switch (i) {
            case 0:
                work[0xe] = bpTex0021c9f0(archiveData);
                break;
            case 1:
                work[0x12] = bpTexCreateTmxRaster(archiveData);
                break;
            case 2:
                work[0x13] = bpTexCreateTmxRaster(archiveData);
                break;
            case 4:
                work[0xf] = bpTex0021c9f0(archiveData);
                break;
            case 5:
                work[0x10] = bpTex0021c9f0(archiveData);
                break;
            case 3:
                work[0x11] = bpTex0021c9f0(archiveData);
                break;
            default:
                K_ASSERT(0, 0x159);
            }
        }
        H_Cdvd_Destroy(work[5]);
        work[1] |= 0x10;
        work[0] &= ~4;
    }
}

// FUN_00234570
u32 brRes00234570(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 7];
}

// FUN_002345d0
u32 brRes002345d0(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 9];
}

// FUN_00234630
u32 brRes00234630(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 0xc];
}

// FUN_00234690
void brRes00234690(s32 index, void* data)
{
    u32* work;
    u32 texture;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    texture = bpTex0021c9f0(data);
    work[index + 0xc] = texture;
    work[1] |= 0x40;
}

// FUN_00234710
void brRes00234710(void* data, u32 size)
{
    u32* work;
    void* copy;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT((~work[1] & 0x20) != 0, 0x182);
    copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
    memcpy(copy, data, size);
    work[11] = (u32)copy;
    work[1] |= 0x20;
}

// FUN_002347e0
u32 brRes002347e0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[11];
}
