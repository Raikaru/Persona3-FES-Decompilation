#include "Camp/_h_camp_equip.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "h_maestro.h"
#include "rw/rwplcore.h"


typedef struct CampEquipSprite
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[0x13];
    f32 spriteScale;
    u8 red;
    u8 green;
    u8 blue;
    u8 reserved33;
} CampEquipSprite;

extern void* FUN_00100d80();
extern s32 FUN_001016b0();
extern void* FUN_00102100();
extern s32 FUN_00111f30();
extern void* FUN_001158b0();
extern s32 FUN_001159f0();
extern s32 FUN_00115bc0();
extern void FUN_00115980();
extern void FUN_001127d0();
extern s32 FUN_0011e380();
extern u16 func_001712d0(s16 id);
extern u32 func_00171250(s16 id);
extern void qsort(void* base, u32 count, u32 width,
                  int (*compare)(const void*, const void*));
extern s32 FUN_0010a4e0();
extern s32 FUN_0011abd0();
extern s32 FUN_0016c4f0();
extern s32 FUN_0016c5f0();
extern s32 FUN_0016c570();
extern s32 FUN_0016cf40();
extern s32 FUN_0016cf90();
extern s32 FUN_0016f630();
extern s32 FUN_0016f810();
extern s32 FUN_0016f900();
extern void FUN_0012e3b0();
extern void FUN_0012f6d0();
extern u32 FUN_0012dc20();
extern u32 FUN_0012dcf0();
extern void FUN_0012ddc0();
extern s32 FUN_0012df50();
extern void FUN_0012e170(void* atlas, s32 baseTile, CampVec2 position,
                         s32 scale, s32 red, s32 green, s32 blue, s32 alpha,
                         s32 value, s32 digits);
extern s32 FUN_003b2cb0();
extern s32 FUN_003c7e20();
extern void FUN_00523ac8();
extern int sprintf(char* buffer, const char* format, ...);
extern void* DAT_007cdf50;
extern s32 DAT_007e0952;
extern s32 DAT_007e095a;
extern s32 DAT_007e094e;
extern void* DAT_00833B70;
extern void* DAT_00833BA0;
extern void* DAT_007cb66c;
extern void* H_Maestro_001120a0(s32 font);

void* FUN_0012c430(KwlnTask*);
void FUN_001124b0();
void H_Cdvd_Destroy();

// FUN_00130e40. Destroy callback of the "H_CampSoubi1Draw" (equip screen) task
void h_campEquipDestroySoubi1DrawTask(KwlnTask* task)
{
    int* workData;

    workData = (int*)task->workData;
    if (workData[0xae] != 0) {
        RwFree((void*)workData[0xae]);
    }
    workData[0xae] = 0;
    if (workData[0xaf] != 0) {
        RwFree((void*)workData[0xaf]);
    }
    workData[0xaf] = 0;
    if (workData[0xb0] != 0) {
        RwFree((void*)workData[0xb0]);
    }
    workData[0xb0] = 0;
    if (workData[0xac] != 0) {
        FUN_001124b0(workData[0xac]);
    }
    workData[0xac] = 0;
    if (workData[0xad] != 0) {
        FUN_001124b0(workData[0xad]);
    }
    workData[0xad] = 0;
    if (workData[0] != 0) {
        H_Cdvd_Destroy(workData[0]);
    }
    workData[0] = 0;
    RwFree(workData);
}

// FUN_00130f20
KwlnTask* h_campEquipCreateSoubi1DrawTask(KwlnTask* parent, u32 priority, CampVec2 param_3, u16 param_4)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x2c4, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampSoubi1Draw", priority, FUN_0012c430, h_campEquipDestroySoubi1DrawTask, workData);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((int)workData + 8) = param_3;
    workData[5] = 1;
    *(u16*)((int)workData + 0x12) = param_4;
    return task;
}
// FUN_00131000
int FUN_00131000(const void* left, const void* right)
{
    u16 leftId;
    u16 rightId;

    leftId = datGetEquipmentId(1, *(const u16*)left);
    rightId = datGetEquipmentId(1, *(const u16*)right);
    if (leftId == rightId) {
        return 0;
    }
    if (leftId < rightId) {
        return -1;
    }
    return 1;
}

// FUN_00131090 NONMATCHING
s32 FUN_00131090(void* output, void* unused, s16 pcId, s16 category)
{
    u16 indexes[300];
    s32 count;
    s32 index;
    u16 equipmentId;
    u16* outputIndexes;

    (void)unused;
    outputIndexes = (u16*)output;
    count = 0;
    for (index = 0; index < 300; index++) {
        equipmentId = datGetEquipmentId(pcId, index);
        if (equipmentId == 0) {
            continue;
        }
        if ((func_001712d0((s16)equipmentId) & 0x20) == 0) {
            continue;
        }
        if (func_00171250((s16)equipmentId) != (u32)(s32)category) {
            continue;
        }
        indexes[count++] = (u16)index;
    }
    if (count >= 2) {
        qsort(indexes, count, 2, FUN_00131000);
    }
    for (index = 0; index < count; index++) {
        outputIndexes[index] = indexes[index];
    }
    return count;
}

static u32* campEquipWord(void* work, s32 offset)
{
    return (u32*)((u8*)work + offset);
}

static CampEquipSprite* campEquipMakeSprite(void* atlas, s32 tile)
{
    return (CampEquipSprite*)FUN_001158b0(0, atlas, tile);
}

static void campEquipDrawSprite(void* atlas, s32 tile, f32 scale,
                                f32 x, f32 y, u8 alpha)
{
    CampEquipSprite* sprite;

    sprite = campEquipMakeSprite(atlas, tile);
    sprite->spriteScale = scale;
    sprite->x = x;
    sprite->y = y;
    sprite->alpha = alpha;
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
}

// FUN_0012DC20
u32 FUN_0012dc20(u32* work)
{
    s32 i;
    u32 allFinished;
    u8* records;

    allFinished = 1;
    i = 0;
    while (i < 10) {
        records = (u8*)work[0xae];
        if (*(s32*)(records + i * 0x44 + 4) != 0) {
            if (func_0018b700(records + i * 0x44) != 0) {
                FUN_0012e3b0((void*)work, i,
                             (u8*)work[0xae] + i * 0x44);
            }
            records = (u8*)work[0xae];
            if (*(s32*)(records + i * 0x44 + 0x18) !=
                *(s32*)(records + i * 0x44 + 0x20)) {
                allFinished = 0;
            }
        }
        i++;
    }
    return allFinished;
}

// FUN_0012DCF0
u32 FUN_0012dcf0(u32* work)
{
    s32 i;
    u32 allFinished;
    u8* records;

    allFinished = 1;
    i = 0;
    while (i < 10) {
        records = (u8*)work[0xaf];
        if (*(s32*)(records + i * 0x44 + 4) != 0) {
            if (func_0018b700(records + i * 0x44) != 0) {
                FUN_0012f6d0((void*)work, i,
                             (u8*)work[0xaf] + i * 0x44);
            }
            records = (u8*)work[0xaf];
            if (*(s32*)(records + i * 0x44 + 0x18) !=
                *(s32*)(records + i * 0x44 + 0x20)) {
                allFinished = 0;
            }
        }
        i++;
    }
    return allFinished;
}

// FUN_0012DDC0
void FUN_0012ddc0(void* arg)
{
    u32* work;
    CampEquipSprite* sprite;

    work = (u32*)arg;
    if (func_0018b700((void*)work[0xb0]) == 0) {
        return;
    }
    sprite = (CampEquipSprite*)FUN_001158b0(0, (void*)work[0xac], 0x1d);
    sprite->spriteScale = *(f32*)((u8*)work[0xb0] + 0x24);
    sprite->x = *(f32*)((u8*)work[0xb0] + 0x38) + 268.0f;
    sprite->y = *(f32*)((u8*)work[0xb0] + 0x3c);
    sprite->alpha = (u8)((u32*)work[0xb0])[0x10];
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
    sprite = (CampEquipSprite*)FUN_001158b0(0, (void*)work[0xac], 0x1d);
    sprite->spriteScale = *(f32*)((u8*)work[0xb0] + 0x24);
    sprite->x = *(f32*)((u8*)work[0xb0] + 0x38) + 268.0f + 700.0f;
    sprite->y = *(f32*)((u8*)work[0xb0] + 0x3c);
    sprite->alpha = (u8)((u32*)work[0xb0])[0x10];
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
    ((f32*)work[0xb0])[0xc] -= 1.0f;
    if (((f32*)work[0xb0])[0xc] < -700.0f) {
        ((f32*)work[0xb0])[0xc] += 700.0f;
    }
}

// FUN_0012DF50
s32 FUN_0012df50(u32 mask)
{
    if ((mask & 0x000001) != 0) return 0;
    if ((mask & 0x000002) != 0) return 1;
    if ((mask & 0x000004) != 0) return 2;
    if ((mask & 0x000008) != 0) return 3;
    if ((mask & 0x000010) != 0) return 4;
    if ((mask & 0x000020) != 0) return 5;
    if ((mask & 0x000040) != 0) return 6;
    if ((mask & 0x000080) != 0) return 7;
    if ((mask & 0x000100) != 0) return 0;
    if ((mask & 0x000200) != 0) return 1;
    if ((mask & 0x000400) != 0) return 2;
    if ((mask & 0x000800) != 0) return 3;
    if ((mask & 0x001000) != 0) return 4;
    if ((mask & 0x002000) != 0) return 5;
    if ((mask & 0x004000) != 0) return 6;
    if ((mask & 0x008000) != 0) return 7;
    if ((mask & 0x010000) != 0) return 9;
    if ((mask & 0x020000) != 0) return 10;
    if ((mask & 0x040000) != 0) return 11;
    if ((mask & 0x080000) != 0) return 13;
    if ((mask & 0x100000) != 0) return 13;
    return 0;
}

// FUN_0012E170
void FUN_0012e170(void* atlas, s32 baseTile, CampVec2 position,
                  s32 scale, s32 red, s32 green, s32 blue, s32 alpha,
                  s32 value, s32 digits)
{
    f32 x;

    x = position.x;
    if (digits == 3) {
        if (value >= 100) {
            CampEquipSprite* sprite;

            sprite = (CampEquipSprite*)FUN_001158b0(
                0, atlas, baseTile + value / 100);
            sprite->spriteScale = (f32)scale;
            sprite->x = x;
            sprite->y = position.y;
            sprite->alpha = (u8)alpha;
            sprite->red = (u8)red;
            sprite->green = (u8)green;
            sprite->blue = (u8)blue;
            FUN_001127d0(sprite, 1);
            FUN_00115980(sprite);
        }
        x += 16.0f;
        digits--;
    }
    if (digits == 2) {
        if (value >= 10) {
            CampEquipSprite* sprite;

            sprite = (CampEquipSprite*)FUN_001158b0(
                0, atlas, baseTile + (value / 10) % 10);
            sprite->spriteScale = (f32)scale;
            sprite->x = x;
            sprite->y = position.y;
            sprite->alpha = (u8)alpha;
            sprite->red = (u8)red;
            sprite->green = (u8)green;
            sprite->blue = (u8)blue;
            FUN_001127d0(sprite, 1);
            FUN_00115980(sprite);
        }
        x += 16.0f;
    }
    {
        CampEquipSprite* sprite;

        sprite = (CampEquipSprite*)FUN_001158b0(
            0, atlas, baseTile + value % 10);
        sprite->spriteScale = (f32)scale;
        sprite->x = x;
        sprite->y = position.y;
        sprite->alpha = (u8)alpha;
        sprite->red = (u8)red;
        sprite->green = (u8)green;
        sprite->blue = (u8)blue;
        FUN_001127d0(sprite, 1);
        FUN_00115980(sprite);
    }
}

static void campEquipAnimateMain(u32* work, s32 mode)
{
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, mode, 0x4270000000000000ULL, 0x42700000c4160000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, mode, 0x42b4000000000000ULL, 0x42b40000c4160000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, mode, 0x42f0000000000000ULL, 0x42f00000c4160000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, mode, 0x4316000000000000ULL, 0x43160000c4160000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, mode, 0x436a000043f38000ULL, 0x436a00004444c000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, mode, 0x4372000043360000ULL, 0x43720000c3d10000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, mode, 0x43cf800041e00000ULL, 0x43cf8000c40f0000ULL, 0, 0, 0, 0);
}
static void campEquipInitializeMain(u32* work)
{
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, 1, 0x42700000c4160000ULL, 0x4270000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, 1, 0x42b40000c4160000ULL, 0x42b4000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, 1, 0x42f00000c4160000ULL, 0x42f0000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, 1, 0x43160000c4160000ULL, 0x4316000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, 1, 0xc28400004444c000ULL, 0x436a000043f38000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, 1, 0x43720000c3d10000ULL, 0x4372000043360000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, 1, 0x43cf8000c40f0000ULL, 0x43cf800041e00000ULL, 0, 0, 0, 0);
}

static void campEquipCloseMain(u32* work)
{
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, 1, 0x4270000000000000ULL, 0x4270000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, 1, 0x42b4000000000000ULL, 0x42b4000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, 1, 0x42f0000000000000ULL, 0x42f0000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, 1, 0x4316000000000000ULL, 0x4316000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, 1, 0x436a000043f38000ULL, 0x436a000043f38000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, 1, 0x4372000043360000ULL, 0x4372000043360000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, 1, 0x43cf800041e00000ULL, 0x43cf800041e00000ULL, 0, 0, 0, 0);
}

static void campEquipAnimateList(u32* work, s32 mode)
{
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x00), 0, 2, mode, 0x4210000041980000ULL, 0x42100000c38c8000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x44), 0, 2, mode, 0x4214000043d18000ULL, 0x4214000043d18000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x88), 0, 2, mode, 0x4270000000000000ULL, 0x4270000000000000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0xcc), 0, 2, mode, 0x42d8000042ea0000ULL, 0x42d8000042ea0000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x110), 0, 2, mode, 0x43b6800043f38000ULL, 0x43b6800043f38000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x198), 0, 2, mode, 0x4372000043290000ULL, 0x4372000043290000ULL, 0, 0, 0, 0);
    func_0018bc10(100.0f, (void*)(work[0xaf] + 0x1dc), 0, 2, mode, 0x43cf800041e00000ULL, 0x43cf800041e00000ULL, 0, 0, 0, 0);
}

// FUN_0012C430 NONMATCHING
void* FUN_0012c430(KwlnTask* task)
{
    u32* work;

    work = (u32*)task->workData;
    switch (work[1]) {
    case 0:
        if (FUN_0011e380(DAT_007cdf50, 0xf) == 0) {
            return NULL;
        }
        work[0xae] = (u32)func_0018b6d0(10);
        work[0xaf] = (u32)func_0018b6d0(10);
        work[0xb0] = (u32)func_0018b6d0(1);
        work[0] = (u32)FUN_00100d80(0x5db100, 1);
        work[1] = 1;
        break;
    case 1:
        if (FUN_001016b0(work[0]) != 0) {
            u8 scratch[4];

            func_0018bc10(100.0f, (void*)(work[0xb0]), 0, 2, 1, 0x43bf000000000000ULL, 0x43bf000000000000ULL, 0, 0, 0, 0);
            work[0xac] = (u32)FUN_00112420(FUN_00102100(work[0], 0, scratch));
            work[0xad] = (u32)FUN_00112420(FUN_00102100(work[0], 1, scratch));
            work[1] = 2;
        }
        break;
    case 2:
        if (FUN_00111f30((void*)work[0xac]) != 0 &&
            FUN_00111f30((void*)work[0xad]) != 0) {
            work[1] = 3;
        }
        break;
    case 3:
        campEquipInitializeMain(work);
        work[1] = 4;
        break;
    case 4:
        if (work[6] != 0) {
            if ((DAT_007e0952 & 0x40) != 0) {
                FUN_0010a4e0(0, 0, 0, 1);
                work[1] = 7;
            } else if ((DAT_007e0952 & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                work[1] = 5;
            } else if ((DAT_007e0952 & 0x1000) != 0 ||
                       (DAT_007e095a & 0x1000) != 0) {
                if (*(s16*)((u8*)work + 0x1c) != 0) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    --*(s16*)((u8*)work + 0x1c);
                }
            } else if ((DAT_007e0952 & 0x4000) != 0 ||
                       (DAT_007e095a & 0x4000) != 0) {
                if (*(s16*)((u8*)work + 0x1c) != 3) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    ++*(s16*)((u8*)work + 0x1c);
                }
            }
        }
        FUN_0012ddc0(work);
        work[6] = FUN_0012dc20(work);
        break;
    case 5:
        campEquipAnimateMain(work, 2);
        FUN_0012ddc0(work);
        FUN_0012dc20(work);
        func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, 2, 0x4372000043360000ULL, 0x43720000c3d10000ULL, 0, 0, 0, 0);
        func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, 2, 0x43cf800041e00000ULL, 0x43cf8000c40f0000ULL, 0, 0, 0, 0);
        func_0018bc10(100.0f, (void*)(work[0xb0]), 0, 2, 2, *(u64*)((u8*)work[0xb0] + 0x38), *(u64*)((u8*)work[0xb0] + 0x38), 0, 0, 0, 0);
        work[1] = 6;
        break;
    case 6:
        FUN_0012ddc0(work);
        if (FUN_0012dc20(work) != 0) {
            return (void*)-1;
        }
        break;
    case 7:
        if (FUN_0011e380(DAT_007cdf50, 0x10) != 0) {
            work[9] = 0;
            work[8] = 0;
            work[0xab] = (u32)FUN_00131090(work + 10, work + 0xa0,
                                            *(u16*)((u8*)work + 0x12),
                                            *(u16*)((u8*)work + 0x1c));
            work[1] = 8;
        }
        FUN_0012ddc0(work);
        FUN_0012dc20(work);
        break;
    case 8:
        campEquipAnimateMain(work, 2);
        campEquipAnimateList(work, 1);
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0xcc), 0, 2, 1, 0x42d8000043590000ULL, 0x42d8000042ea0000ULL, 0, 0, 0, 0);
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x110), 0, 2, 1, 0x438480004412c000ULL, 0x43b6800043f38000ULL, 0, 0, 0, 0);
        FUN_0012ddc0(work);
        FUN_0012dc20(work);
        FUN_0012dcf0(work);
        work[1] = 9;
        break;
    case 9:
        FUN_0012ddc0(work);
        FUN_0012dc20(work);
        if (FUN_0012dcf0(work) != 0) {
            work[1] = 10;
        }
        break;
    case 10:
        if ((DAT_007e094e & 0x40) != 0) {
            s16 pcId;
            s16 category;
            u16 oldMaxHp;
            u16 oldHp;
            u16 oldMaxSp;
            u16 oldSp;
            u16 newIndex;
            u16 newMaxHp;
            u16 newMaxSp;

            FUN_0010a4e0(0, 0, 0, 7);
            pcId = *(s16*)((u8*)work + 0x12);
            category = *(s16*)((u8*)work + 0x1c);
            newIndex = *(u16*)((u8*)work + 0x28 + (work[9] + work[8]) * 2);
            oldMaxHp = (u16)FUN_0016c5f0(pcId);
            oldHp = (u16)FUN_0016c4f0(pcId);
            oldMaxSp = (u16)func_0016c670(pcId);
            oldSp = (u16)FUN_0016c570(pcId);
            datSetEquipmentIdx(pcId, category, newIndex);
            newMaxHp = (u16)FUN_0016c5f0(pcId);
            if (oldMaxHp != newMaxHp) {
                FUN_0016cf40(pcId, (s16)((oldHp * newMaxHp) / oldMaxHp));
            }
            newMaxSp = (u16)func_0016c670(pcId);
            if (oldMaxSp != newMaxSp) {
                FUN_0016cf90(pcId, (s16)((oldSp * newMaxSp) / oldMaxSp));
            }
        } else if ((DAT_007e094e & 0x20) != 0) {
            FUN_0010a4e0(0, 0, 0, 2);
            work[1] = 0xb;
        } else {
            FUN_0011abd0((void*)work[0xab], 5, &work[9], &work[8]);
        }
        FUN_0012ddc0(work);
        FUN_0012dcf0(work);
        break;
    case 0xb:
        if (FUN_0011e380(DAT_007cdf50, 0xf) != 0) {
            campEquipCloseMain(work);
            campEquipAnimateList(work, 2);
            work[1] = 0xc;
        }
        FUN_0012ddc0(work);
        FUN_0012dcf0(work);
        break;
    case 0xc:
        FUN_0012ddc0(work);
        if (FUN_0012dc20(work) != 0 && FUN_0012dcf0(work) != 0) {
            work[1] = 4;
        }
        break;
    }
    return NULL;
}

static CampVec2 campEquipRecordPosition(const u8* record)
{
    CampVec2 position;

    position.x = *(f32*)(record + 0x38);
    position.y = *(f32*)(record + 0x3c);
    return position;
}

static void campEquipBuildLabels(void* work, char labels[4][0x100])
{
    s16 pcId;
    s32 i;
    s16 equipment;
    u16 name;
    u8 style;

    pcId = *(s16*)((u8*)work + 0x12);
    for (i = 0; i < 4; i++) {
        equipment = datGetEquipmentIdx(pcId, (s16)i);
        style = (u8)FUN_0012df50(func_0016f720(1, equipment));
        name = (u16)FUN_0016f630(pcId, equipment);
        FUN_00523ac8(labels[i], DAT_007cb66c, func_00171110(name, func_0016f810(pcId, equipment)));
        (void)style;
    }
}

static void campEquipDrawCategory(void* work, u8* record, s16 category,
                                  char labels[4][0x100])
{
    CampVec2 position;
    f32 scale;
    u8 alpha;
    s32 selected;
    s32 style;
    s32 font;
    s32 valueA;
    s32 valueB;
    void* glyphs;

    position = campEquipRecordPosition(record);
    scale = *(f32*)(record + 0x24);
    alpha = (u8)*(u32*)(record + 0x40);
    selected = *(s16*)((u8*)work + 0x1c) == category;
    style = selected != 0 ? 6 : 10;
    font = selected != 0 ? 1 : 2;
    glyphs = H_Maestro_001120a0(font);

    if (category == 0) {
        s16 pcId;
        s16 equipment;

        pcId = *(s16*)((u8*)work + 0x12);
        equipment = datGetEquipmentIdx(pcId, category);
        valueA = func_0016f9f0(pcId, equipment);
        valueB = func_0016fae0(pcId, equipment);
        FUN_001159f0(position.x, position.y, scale);
        FUN_001159f0(position.x + 28.0f, position.y + 6.0f, scale);
        if (selected != 0) {
            FUN_001159f0(position.x + 139.0f, position.y + 1.0f, scale);
        } else {
            FUN_00115bc0(position.x + 139.0f, position.y + 1.0f, scale);
        }
        FUN_003b32d0(scale, (s32)(position.x + 179.0f),
                     (s32)(position.y + 10.0f), 0xff - alpha, style, 1,
                     labels[category], 0x10, 0x78);
        FUN_001159f0(position.x + 406.0f, position.y + 8.0f, scale);
        FUN_001159f0(position.x + 507.0f, position.y + 8.0f, scale);
        campEquipDrawSprite(glyphs, 0, scale, position.x + 443.0f,
                            position.y + 15.0f, alpha);
        FUN_0012e170(glyphs, 0xb,
                     (CampVec2){position.x + 443.0f, position.y + 15.0f},
                     (s32)scale, 0xff, 0xff, 0xff, alpha, valueA, 3);
        FUN_0012e170(glyphs, 0xb,
                     (CampVec2){position.x + 544.0f, position.y + 15.0f},
                     (s32)scale, 0xff, 0xff, 0xff, alpha, valueB, 3);
    } else if (category == 1 || category == 2) {
        s16 pcId;
        s16 equipment;

        pcId = *(s16*)((u8*)work + 0x12);
        equipment = datGetEquipmentIdx(pcId, category);
        valueA = category == 1 ? func_0016fbd0(pcId, equipment)
                               : func_0016fcc0(pcId, equipment);
        FUN_001159f0(position.x, position.y, scale);
        FUN_001159f0(position.x + 28.0f, position.y + 6.0f, scale);
        if (selected != 0) {
            FUN_001159f0(position.x + 139.0f, position.y + 1.0f, scale);
        } else {
            FUN_00115bc0(position.x + 139.0f, position.y + 1.0f, scale);
        }
        FUN_003b32d0(scale, (s32)(position.x + 179.0f),
                     (s32)(position.y + 10.0f), 0xff - alpha, style, 1,
                     labels[category], 0x10, 0x78);
        FUN_001159f0(position.x + 406.0f, position.y + 8.0f, scale);
        FUN_0012e170(glyphs, 0xb,
                     (CampVec2){position.x + 443.0f, position.y + 15.0f},
                     (s32)scale, 0xff, 0xff, 0xff, alpha, valueA, 3);
    } else if (category == 3) {
        FUN_001159f0(position.x, position.y, scale);
        FUN_001159f0(position.x + 28.0f, position.y + 6.0f, scale);
        if (selected != 0) {
            FUN_001159f0(position.x + 139.0f, position.y + 1.0f, scale);
        } else {
            FUN_00115bc0(position.x + 139.0f, position.y + 1.0f, scale);
        }
        FUN_003b32d0(scale, (s32)(position.x + 179.0f),
                     (s32)(position.y + 10.0f), 0xff - alpha, style, 1,
                     labels[category], 0x10, 0x78);
    }
}

// FUN_0012E3B0 NONMATCHING
void FUN_0012e3b0(void* work, s32 index, void* recordData)
{
    u8* record;
    char labels[4][0x100];
    CampVec2 position;
    s16 category;
    s16 pcId;

    record = (u8*)recordData;
    category = *(s16*)((u8*)work + 0x1c);
    pcId = *(s16*)((u8*)work + 0x12);
    position = campEquipRecordPosition(record);
    campEquipBuildLabels(work, labels);

    switch (index) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (category == index) {
            campEquipDrawCategory(work, record, (s16)index, labels);
        } else {
            campEquipDrawCategory(work, record, (s16)index, labels);
        }
        break;
    case 4:
        {
            s16 equipment;
            u32 icon;
            u32 color;

            equipment = datGetEquipmentIdx(pcId, category);
            icon = (u32)FUN_0016f630(pcId, equipment);
            color = (u32)FUN_0016f900(pcId, equipment);
            FUN_003c7e20(*(void**)(record + 0x24), (s32)position.x,
                         (s32)position.y, 0xff - *(u32*)(record + 0x40),
                         1, 10, 1, (icon & 0xffff) | ((color & 0xff) << 16));
        }
        break;
    case 5:
        campEquipDrawSprite(*(void**)((u8*)work + 0x2b0), 0x1a,
                            *(f32*)(record + 0x24), position.x, position.y,
                            (u8)*(u32*)(record + 0x40));
        break;
    case 6:
        FUN_001159f0(position.x, position.y, *(void**)(record + 0x24));
        FUN_001159f0(position.x + 16.0f, position.y,
                     *(void**)(record + 0x24));
        FUN_001159f0(position.x + 458.0f, position.y,
                     *(void**)(record + 0x24));
        FUN_001159f0(position.x + 533.0f, position.y,
                     *(void**)(record + 0x24));
        break;
    default:
        break;
    }
}

static void campEquipDrawEquipmentEffect(void* work, u8* record,
                                         s32 tile, f32 xOffset, f32 yOffset)
{
    s16 pcId;
    s16 equipment;
    void* atlas;
    f32 scale;
    u8 alpha;

    pcId = *(s16*)((u8*)work + 0x12);
    equipment = datGetEquipmentIdx(pcId, *(s16*)((u8*)work + 0x1c));
    atlas = *(void**)((u8*)work + 0x2b0);
    scale = *(f32*)(record + 0x24);
    alpha = (u8)*(u32*)(record + 0x40);
    FUN_001159f0(*(f32*)(record + 0x38) + xOffset,
                 *(f32*)(record + 0x3c) + yOffset, atlas, tile, scale,
                 alpha);
}

static void campEquipDrawItemList(void* work, u8* record, s32 xOffset,
                                  s32 yOffset)
{
    s32 row;
    s32 first;
    s32 count;
    s16 pcId;
    f32 scale;
    void* atlas;
    u8 alpha;
    char text[0x100];

    first = *(s32*)((u8*)work + 0x20);
    count = *(s32*)((u8*)work + 0x2ac);
    pcId = *(s16*)((u8*)work + 0x12);
    scale = *(f32*)(record + 0x24);
    atlas = *(void**)((u8*)work + 0x2b0);
    alpha = (u8)*(u32*)(record + 0x40);
    for (row = 0; row < 5; row++) {
        s32 item;
        u16 equipment;
        u16 id;
        u8 effect;
        s32 selected;
        f32 y;

        item = first + row;
        if (item >= count) {
            continue;
        }
        equipment = *(u16*)((u8*)work + 0x28 + item * 2);
        id = datGetEquipmentId(pcId, equipment);
        effect = datGetEquipmentEffect(pcId, equipment);
        sprintf(text, "%d", (s32)func_00171110(id, effect));
        selected = *(s32*)((u8*)work + 0x24) == item;
        y = *(f32*)(record + 0x3c) + (f32)(row * 30);
        FUN_001159f0(*(f32*)(record + 0x38) + (f32)xOffset, y,
                     atlas, selected != 0 ? 0x25 : 0x26, scale, alpha);
        FUN_003b2cb0(scale, (s32)(*(f32*)(record + 0x38) + xOffset + 20),
                     (s32)y, 0xff - alpha, selected != 0 ? 6 : 10,
                     1, text, 0x10, 0);
    }
}
// FUN_0012F6D0 NONMATCHING
void FUN_0012f6d0(void* work, s32 index, void* recordData)
{
    u8* record;
    s16 category;
    CampVec2 position;
    f32 scale;
    void* atlas;
    u8 alpha;

    if (index < 0 || index >= 8) {
        return;
    }
    record = (u8*)recordData;
    category = *(s16*)((u8*)work + 0x1c);
    position = campEquipRecordPosition(record);
    scale = *(f32*)(record + 0x24);
    atlas = *(void**)((u8*)work + 0x2b0);
    alpha = (u8)*(u32*)(record + 0x40);

    switch (index) {
    case 0:
        campEquipDrawSprite(atlas, 0x17, scale, position.x, position.y,
                            alpha);
        break;
    case 1:
        switch (category) {
        case 0:
            campEquipDrawSprite(atlas, 0x12, scale, position.x, position.y,
                                alpha);
            campEquipDrawSprite(atlas, 0x15, scale, position.x + 89.0f,
                                position.y, alpha);
            break;
        case 1:
            campEquipDrawSprite(atlas, 0x13, scale, position.x + 12.0f,
                                position.y, alpha);
            break;
        case 2:
            campEquipDrawSprite(atlas, 0x14, scale, position.x + 12.0f,
                                position.y, alpha);
            break;
        default:
            break;
        }
        break;
    case 2:
        {
            s16 pcId;
            s16 equipment;
            s32 style;
            u16 id;
            u8 effect;
            char text[0x100];

            pcId = *(s16*)((u8*)work + 0x12);
            equipment = datGetEquipmentIdx(pcId, category);
            style = FUN_0012df50(func_0016f720(1, equipment));
            id = datGetEquipmentId(pcId, equipment);
            effect = func_0016f810(pcId, equipment);
            sprintf(text, "%d", (s32)func_00171110(id, effect));
            campEquipDrawSprite(atlas, 0x18, scale, position.x, position.y,
                                alpha);
            campEquipDrawSprite(atlas, style, scale, position.x + 48.0f,
                                position.y + 6.0f, alpha);
            FUN_003b2cb0(scale, (s32)(position.x + 179.0f),
                         (s32)(position.y + 10.0f), 0xff - alpha,
                         category == 0 ? 6 : 10, 1, text, 0x10, 0x78);
        }
        break;
    case 3:
        campEquipDrawSprite(atlas, 0x18, scale, position.x, position.y,
                            alpha);
        campEquipDrawItemList(work, record, 0, 0);
        break;
    case 4:
        campEquipDrawSprite(atlas, 0x27, scale, position.x + 483.0f,
                            position.y + 1.0f, alpha);
        campEquipDrawSprite(atlas, 0x28, scale, position.x + 483.0f,
                            position.y + 3.0f, alpha);
        campEquipDrawItemList(work, record, 16, -10);
        break;
    case 5:
        campEquipDrawSprite(atlas, 0x1b, scale, position.x, position.y,
                            alpha);
        break;
    case 6:
        {
            s16 pcId;
            s16 equipment;
            u16 id;
            u8 effect;

            pcId = *(s16*)((u8*)work + 0x12);
            equipment = *(u16*)((u8*)work + 0x28 +
                                (*(s32*)((u8*)work + 0x20) +
                                 *(s32*)((u8*)work + 0x24)) * 2);
            id = datGetEquipmentId(pcId, equipment);
            effect = datGetEquipmentEffect(pcId, equipment);
            FUN_003c7e20(scale, (s32)position.x, (s32)position.y,
                         0xff - alpha, 1, 10, 1,
                         (id & 0xffff) | ((effect & 0xff) << 16));
        }
        break;
    case 7:
        atlas = *(void**)((u8*)work + 0x2b4);
        FUN_001159f0(position.x, position.y, atlas, 0, scale, alpha);
        FUN_001159f0(position.x + 1.0f, position.y + 32.0f, atlas, 6,
                     scale, alpha);
        campEquipDrawSprite(DAT_00833BA0, 2, scale, position.x + 435.0f,
                            position.y + 2.0f, alpha);
        campEquipDrawSprite(DAT_00833BA0, 1, scale, position.x + 561.0f,
                            position.y + 2.0f, alpha);
        break;
    }
}
