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
extern u32 func_001712d0(s16 id);
extern u32 func_00171250(s16 id);
#pragma alias campEquipComparatorCall FUN_00131000
extern int campEquipComparatorCall(const void* left, const void* right);
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
#pragma alias campEquipDrawSpriteCall FUN_001159f0
extern void campEquipDrawSpriteCall(void* parent, void* resource, s32 frame,
                                    u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campEquipDrawSpriteAltCall FUN_00115bc0
extern void campEquipDrawSpriteAltCall(void* parent, void* resource,
                                       s32 frame, u32 alpha, s32 red,
                                       s32 green, s32 blue, f32 x, f32 y,
                                       f32 scale);
#pragma alias campEquipMakeSpriteCall FUN_001158b0
extern void* campEquipMakeSpriteCall(void* parent, void* resource, s32 frame);
#pragma alias campEquipSetSpriteCall FUN_001127d0
extern void campEquipSetSpriteCall(void* sprite, s32 mode);
#pragma alias campEquipSubmitSpriteCall FUN_00115980
extern void campEquipSubmitSpriteCall(void* sprite);
#pragma alias campEquipDrawTextCall FUN_003b32d0
extern void campEquipDrawTextCall(f32 scale, s32 x, s32 y, s32 color,
                                  s32 style, s32 shadow, const char* text,
                                  s32 width, s32 maxWidth);
#pragma alias campEquipDrawValueCall FUN_003c7e20
extern void campEquipDrawValueCall(f32 scale, s32 x, s32 y, u32 color,
                                   s32 mode, s32 width, s32 style, u32 value);
#pragma alias campEquipFormatTextCall FUN_00523ac8
extern void campEquipFormatTextCall(char* buffer, const char* format, ...);
extern int sprintf(char* buffer, const char* format, ...);
extern void* DAT_007cdf50;
extern u16 DAT_007e0952;
extern u16 DAT_007e095a;
extern u16 DAT_007e094e;
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e095a_abs DAT_007e095a
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e095a_abs[];
extern u8 DAT_007e094e_abs[];
extern void* DAT_00833B70;
#pragma alias DAT_00833B70_abs DAT_00833B70
extern u8 DAT_00833B70_abs[];
extern void* DAT_00833BA0;
#pragma alias DAT_00833BA0_abs DAT_00833BA0
extern u8 DAT_00833BA0_abs[];
#pragma alias DAT_007cb66c_scalar DAT_007cb66c
extern char DAT_007cb66c[];
extern char DAT_007cb66c_scalar;
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

#pragma push
#pragma opt_rebuildconditionals off
// FUN_00131090
s32 FUN_00131090(void* output, void* unused, s16 pcId, s32 category)
{
    u16 indexes[300];
    s32 index;
    s32 count;
    u16 equipmentId;
    u16* outputIndexes;
    s16 pcIdValue;
    s32 categoryValue;
    s32 copyIndex;

    (void)unused;
    outputIndexes = (u16*)output;
    categoryValue = category;
    count = 0;
    index = 0;
    pcIdValue = pcId;
    for (; index < 300; index++) {
        equipmentId = datGetEquipmentId(pcIdValue, index);
        if (equipmentId == 0) {
            continue;
        }
        if ((func_001712d0((s16)equipmentId) & 0x20) == 0) {
            continue;
        }
        if (func_00171250((s16)equipmentId) != categoryValue) {
            continue;
        }
        indexes[count++] = (u16)index;
    }
    if (count > 1) {
        qsort(indexes, count, sizeof(indexes[0]), campEquipComparatorCall);
    }
    for (copyIndex = 0; copyIndex < count; copyIndex++) {
        outputIndexes[copyIndex] = indexes[copyIndex];
    }
    return count;
}
#pragma pop

static inline CampEquipSprite* campEquipMakeSprite(void* atlas, s32 tile)
{
    return (CampEquipSprite*)FUN_001158b0(0, atlas, tile);
}

static inline void campEquipDrawSprite(void* atlas, s32 tile, f32 scale,
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

static inline void campEquipAnimateMain(u32* work, s32 mode)
{
    CampVec2 position;
    CampVec2 start;

    position.x = 0.0f;
    position.y = 60.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 90.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 120.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 150.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 487.0f;
    position.y = 234.0f;
    start = position;
    start.x += 300.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 182.0f;
    position.y = 242.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

    position.x = 28.0f;
    position.y = 415.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, mode,
                  *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);
}
static inline void campEquipInitializeMain(u32* work)
{
    CampVec2 position;
    CampVec2 start;

    position.x = 0.0f;
    position.y = 60.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 90.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 120.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 150.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 487.0f;
    position.y = 234.0f;
    start = position;
    start.x += 300.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 182.0f;
    position.y = 242.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

    position.x = 28.0f;
    position.y = 415.0f;
    start = position;
    start.x -= 600.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, 1,
                  *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);
}

static inline void campEquipCloseMain(u32* work)
{
    CampVec2 position;

    position.x = 0.0f;
    position.y = 60.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x00), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 90.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x44), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 120.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x88), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 0.0f;
    position.y = 150.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0xcc), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 487.0f;
    position.y = 234.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x154), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 182.0f;
    position.y = 242.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x110), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

    position.x = 28.0f;
    position.y = 415.0f;
    func_0018bc10(100.0f, (void*)(work[0xae] + 0x198), 0, 2, 1,
                  *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);
}

static inline void campEquipAnimateList(u32* work, s32 mode)
{
    if (mode == 1) {
        CampVec2 position;
        CampVec2 start;
        s16 category;

        position.x = 19.0f;
        position.y = 36.0f;
        start = position;
        start.x -= 300.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x00), 0, 2, mode,
                      *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

        position.x = 419.0f;
        position.y = 37.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x44), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        category = *(s16*)((u8*)work + 0x1c);
        position.x = 0.0f;
        position.y = 65.0f + 30.0f * (f32)category;
        position.y -= 5.0f;
        start.x = 0.0f;
        start.y = 60.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x88), 0, 2, mode,
                      *(u64*)&position, *(u64*)&start, 0, 0, 0, 0);

        position.x = 117.0f;
        position.y = 108.0f;
        start = position;
        start.x += 100.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0xcc), 0, 2, mode,
                      *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

        position.x = 487.0f;
        position.y = 365.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x110), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 169.0f;
        position.y = 242.0f;
        start = position;
        start.x -= 600.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x198), 0, 2, mode,
                      *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);

        position.x = 28.0f;
        position.y = 415.0f;
        start = position;
        start.x -= 600.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x1dc), 0, 2, mode,
                      *(u64*)&start, *(u64*)&position, 0, 0, 0, 0);
    } else {
        CampVec2 position;

        position.x = 19.0f;
        position.y = 36.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x00), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 419.0f;
        position.y = 37.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x44), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 0.0f;
        position.y = 60.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x88), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 117.0f;
        position.y = 108.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0xcc), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 487.0f;
        position.y = 365.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x110), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 169.0f;
        position.y = 242.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x198), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);

        position.x = 28.0f;
        position.y = 415.0f;
        func_0018bc10(100.0f, (void*)(work[0xaf] + 0x1dc), 0, 2, mode,
                      *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);
    }
}

#pragma opt_loop_invariants on
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
            CampVec2 position;

            position.x = 0.0f;
            position.y = 382.0f;
            func_0018bc10(100.0f, (void*)(work[0xb0]), 0, 2, 1,
                          *(u64*)&position, *(u64*)&position, 0, 0, 0, 0);
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
            if ((*(u16*)DAT_007e0952_abs & 0x40) != 0) {
                FUN_0010a4e0(0, 0, 0, 1);
                work[1] = 7;
            } else if ((*(u16*)DAT_007e0952_abs & 0x20) != 0) {
                FUN_0010a4e0(0, 0, 0, 2);
                work[1] = 5;
            } else if ((*(u16*)DAT_007e0952_abs & 0x1000) != 0 ||
                       (*(u16*)DAT_007e095a_abs & 0x1000) != 0) {
                if (*(s16*)((u8*)work + 0x1c) != 0) {
                    FUN_0010a4e0(0, 0, 0, 0);
                    --*(s16*)((u8*)work + 0x1c);
                }
            } else if ((*(u16*)DAT_007e0952_abs & 0x4000) != 0 ||
                       (*(u16*)DAT_007e095a_abs & 0x4000) != 0) {
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
                                            *(s16*)((u8*)work + 0x1c));
            work[1] = 8;
        }
        FUN_0012ddc0(work);
        FUN_0012dc20(work);
        break;
    case 8:
        campEquipAnimateMain(work, 2);
        campEquipAnimateList(work, 1);
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
        if ((*(u16*)DAT_007e094e_abs & 0x40) != 0) {
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
                FUN_0016cf40(pcId, (s16)((oldHp * FUN_0016c5f0(pcId)) / oldMaxHp));
            }
            newMaxSp = (u16)func_0016c670(pcId);
            if (oldMaxSp != newMaxSp) {
                FUN_0016cf90(pcId, (s16)((oldSp * func_0016c670(pcId)) / oldMaxSp));
            }
        } else if ((*(u16*)DAT_007e094e_abs & 0x20) != 0) {
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
#pragma opt_loop_invariants off

static inline CampVec2 campEquipRecordPosition(const u8* record)
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

/* Retail reloads these atlas globals from their absolute addresses in each
 * branch. Keep explicit aliases so the source preserves those load modes,
 * even though the remaining function-wide register/scheduling residual is
 * larger than the direct GP-relative form. */
#pragma opt_loop_invariants on
#pragma optimization_level 3
// FUN_0012E3B0 NONMATCHING
void FUN_0012e3b0(void* work, s32 index, u8* record)
{
    register void* parent;
    s32 styles[4];
    char labels[4][0x100];
    CampVec2 position;
    s32 i;

    for (i = 0; i < 4; i++) {
        s16 equipment;
        u16 id;
        u8 effect;

        equipment = datGetEquipmentIdx(*(s16*)((u8*)work + 0x12),
                                       (s16)i);
        styles[i] = FUN_0012df50(func_0016f720(1, equipment));
        id = (u16)datGetEquipmentId(*(s16*)((u8*)work + 0x12),
                                    equipment);
        effect = (u8)func_0016f810(*(s16*)((u8*)work + 0x12),
                                   equipment);
        campEquipFormatTextCall(labels[i], &DAT_007cb66c_scalar,
                                func_00171110((s16)id, (s16)effect));
    }

    switch (index) {
    case 0:
        {
            s32 valueA;
            s32 valueB;

            valueA = func_0016f9f0(
                *(s16*)((u8*)work + 0x12),
                datGetEquipmentIdx(*(s16*)((u8*)work + 0x12), 0)) & 0xffff;
            valueB = func_0016fae0(
                *(s16*)((u8*)work + 0x12),
                datGetEquipmentIdx(*(s16*)((u8*)work + 0x12), 0)) & 0xffff;
            if (*(s16*)((u8*)work + 0x1c) == 0) {
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0x18, *(u8*)(record + 0x40),
                                        *(f32*)(record + 0x38),
                                        *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0, *(u8*)(record + 0x40),
                                        28.0f + *(f32*)(record + 0x38),
                                        6.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)DAT_00833B70_abs,
                                        styles[0] * 2 + 1,
                                        *(u8*)(record + 0x40),
                                        139.0f + *(f32*)(record + 0x38),
                                        1.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawTextCall(
                    *(f32*)(record + 0x24),
                    (s32)(179.0f + *(f32*)(record + 0x38)),
                    (s32)(10.0f + *(f32*)(record + 0x3c)),
                    (0xff - *(u32*)(record + 0x40)) | ~0xff,
                    6, 1, labels[0], 0x10, 0x78);
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        9, *(u8*)(record + 0x40),
                                        406.0f + *(f32*)(record + 0x38),
                                        8.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0xf, *(u8*)(record + 0x40),
                                        (f32)0x1fb + *(f32*)(record + 0x38),
                                        8.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                position.x = (f32)0x1bb + *(f32*)(record + 0x38);
                position.y = 15.0f + *(f32*)(record + 0x3c);
                FUN_0012e170(H_Maestro_001120a0(1), 0xb, position,
                             (s32)*(f32*)(record + 0x24),
                             0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                             valueA, 3);
                position.x = 544.0f + *(f32*)(record + 0x38);
                FUN_0012e170(H_Maestro_001120a0(1), 0xb, position,
                             (s32)*(f32*)(record + 0x24),
                             0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                             valueB, 3);
                return;
            }
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    1, *(u8*)(record + 0x40),
                                    28.0f + *(f32*)(record + 0x38),
                                    6.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteAltCall(
                parent, *(void**)DAT_00833B70_abs, styles[0] * 2,
                *(u8*)(record + 0x40), 0x20, 0x43, 0x78,
                139.0f + *(f32*)(record + 0x38),
                1.0f + *(f32*)(record + 0x3c),
                *(f32*)(record + 0x24));
            campEquipDrawTextCall(
                *(f32*)(record + 0x24),
                (s32)(179.0f + *(f32*)(record + 0x38)),
                (s32)(10.0f + *(f32*)(record + 0x3c)),
                (0xff - *(u32*)(record + 0x40)) | ~0xff,
                0xa, 1, labels[0], 0x10, 0x78);
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    0xa, *(u8*)(record + 0x40),
                                    406.0f + *(f32*)(record + 0x38),
                                    8.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    0x10, *(u8*)(record + 0x40),
                                    (f32)0x1fb + *(f32*)(record + 0x38),
                                    8.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            position.x = (f32)0x1bb + *(f32*)(record + 0x38);
            position.y = 15.0f + *(f32*)(record + 0x3c);
            FUN_0012e170(H_Maestro_001120a0(2), 0xb, position,
                         (s32)*(f32*)(record + 0x24),
                         0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                         valueA, 3);
            position.x = 544.0f + *(f32*)(record + 0x38);
            FUN_0012e170(H_Maestro_001120a0(2), 0xb, position,
                         (s32)*(f32*)(record + 0x24),
                         0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                         valueB, 3);
        }
        return;
    case 1:
        {
            s32 value;

            value = func_0016fbd0(
                *(s16*)((u8*)work + 0x12),
                datGetEquipmentIdx(*(s16*)((u8*)work + 0x12), 1)) & 0xffff;
            if (*(s16*)((u8*)work + 0x1c) == 1) {
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0x18, *(u8*)(record + 0x40),
                                        *(f32*)(record + 0x38),
                                        *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        2, *(u8*)(record + 0x40),
                                        28.0f + *(f32*)(record + 0x38),
                                        6.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)DAT_00833B70_abs,
                                        styles[1] * 2 + 1,
                                        *(u8*)(record + 0x40),
                                        139.0f + *(f32*)(record + 0x38),
                                        1.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawTextCall(
                    *(f32*)(record + 0x24),
                    (s32)(179.0f + *(f32*)(record + 0x38)),
                    (s32)(10.0f + *(f32*)(record + 0x3c)),
                    (0xff - *(u32*)(record + 0x40)) | ~0xff,
                    6, 1, labels[1], 0x10, 0x78);
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0xb, *(u8*)(record + 0x40),
                                        406.0f + *(f32*)(record + 0x38),
                                        8.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                position.x = (f32)0x1bb + *(f32*)(record + 0x38);
                position.y = 15.0f + *(f32*)(record + 0x3c);
                FUN_0012e170(H_Maestro_001120a0(1), 0xb, position,
                             (s32)*(f32*)(record + 0x24),
                             0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                             value, 3);
                return;
            }
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    3, *(u8*)(record + 0x40),
                                    28.0f + *(f32*)(record + 0x38),
                                    6.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteAltCall(
                parent, *(void**)DAT_00833B70_abs, styles[1] * 2,
                *(u8*)(record + 0x40), 0x20, 0x43, 0x78,
                139.0f + *(f32*)(record + 0x38),
                1.0f + *(f32*)(record + 0x3c),
                *(f32*)(record + 0x24));
            campEquipDrawTextCall(
                *(f32*)(record + 0x24),
                (s32)(179.0f + *(f32*)(record + 0x38)),
                (s32)(10.0f + *(f32*)(record + 0x3c)),
                (0xff - *(u32*)(record + 0x40)) | ~0xff,
                0xa, 1, labels[1], 0x10, 0x78);
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    0xc, *(u8*)(record + 0x40),
                                    406.0f + *(f32*)(record + 0x38),
                                    8.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            position.x = (f32)0x1bb + *(f32*)(record + 0x38);
            position.y = 15.0f + *(f32*)(record + 0x3c);
            FUN_0012e170(H_Maestro_001120a0(2), 0xb, position,
                         (s32)*(f32*)(record + 0x24),
                         0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                         value, 3);
        }
        return;
    case 2:
        {
            s32 value;

            value = func_0016fcc0(
                *(s16*)((u8*)work + 0x12),
                datGetEquipmentIdx(*(s16*)((u8*)work + 0x12), 2)) & 0xffff;
            if (*(s16*)((u8*)work + 0x1c) == 2) {
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0x18, *(u8*)(record + 0x40),
                                        *(f32*)(record + 0x38),
                                        *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        4, *(u8*)(record + 0x40),
                                        28.0f + *(f32*)(record + 0x38),
                                        6.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawSpriteCall(parent, *(void**)DAT_00833B70_abs,
                                        styles[2] * 2 + 1,
                                        *(u8*)(record + 0x40),
                                        139.0f + *(f32*)(record + 0x38),
                                        1.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                campEquipDrawTextCall(
                    *(f32*)(record + 0x24),
                    (s32)(179.0f + *(f32*)(record + 0x38)),
                    (s32)(10.0f + *(f32*)(record + 0x3c)),
                    (0xff - *(u32*)(record + 0x40)) | ~0xff,
                    6, 1, labels[2], 0x10, 0x78);
                campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                        0xd, *(u8*)(record + 0x40),
                                        406.0f + *(f32*)(record + 0x38),
                                        8.0f + *(f32*)(record + 0x3c),
                                        *(f32*)(record + 0x24));
                position.x = (f32)0x1bb + *(f32*)(record + 0x38);
                position.y = 15.0f + *(f32*)(record + 0x3c);
                FUN_0012e170(H_Maestro_001120a0(1), 0xb, position,
                             (s32)*(f32*)(record + 0x24),
                             0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                             value, 3);
                return;
            }
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    5, *(u8*)(record + 0x40),
                                    28.0f + *(f32*)(record + 0x38),
                                    6.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteAltCall(
                parent, *(void**)DAT_00833B70_abs, styles[2] * 2,
                *(u8*)(record + 0x40), 0x20, 0x43, 0x78,
                139.0f + *(f32*)(record + 0x38),
                1.0f + *(f32*)(record + 0x3c),
                *(f32*)(record + 0x24));
            campEquipDrawTextCall(
                *(f32*)(record + 0x24),
                (s32)(179.0f + *(f32*)(record + 0x38)),
                (s32)(10.0f + *(f32*)(record + 0x3c)),
                (0xff - *(u32*)(record + 0x40)) | ~0xff,
                0xa, 1, labels[2], 0x10, 0x78);
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    0xe, *(u8*)(record + 0x40),
                                    406.0f + *(f32*)(record + 0x38),
                                    8.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            position.x = (f32)0x1bb + *(f32*)(record + 0x38);
            position.y = 15.0f + *(f32*)(record + 0x3c);
            FUN_0012e170(H_Maestro_001120a0(2), 0xb, position,
                         (s32)*(f32*)(record + 0x24),
                         0xff, 0xff, 0xff, *(u8*)(record + 0x40),
                         value, 3);
        }
        return;
    case 3:
        if (*(s16*)((u8*)work + 0x1c) == 3) {
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    0x18, *(u8*)(record + 0x40),
                                    *(f32*)(record + 0x38),
                                    *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                    6, *(u8*)(record + 0x40),
                                    28.0f + *(f32*)(record + 0x38),
                                    6.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawSpriteCall(parent, *(void**)DAT_00833B70_abs,
                                    styles[3] * 2 + 1,
                                    *(u8*)(record + 0x40),
                                    139.0f + *(f32*)(record + 0x38),
                                    1.0f + *(f32*)(record + 0x3c),
                                    *(f32*)(record + 0x24));
            campEquipDrawTextCall(
                *(f32*)(record + 0x24),
                (s32)(179.0f + *(f32*)(record + 0x38)),
                (s32)(10.0f + *(f32*)(record + 0x3c)),
                (0xff - *(u32*)(record + 0x40)) | ~0xff,
                6, 1, labels[3], 0x10, 0x78);
            return;
        }
        campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b0),
                                7, *(u8*)(record + 0x40),
                                28.0f + *(f32*)(record + 0x38),
                                6.0f + *(f32*)(record + 0x3c),
                                *(f32*)(record + 0x24));
        campEquipDrawSpriteAltCall(
            parent, *(void**)DAT_00833B70_abs, styles[3] * 2,
            *(u8*)(record + 0x40), 0x20, 0x43, 0x78,
            139.0f + *(f32*)(record + 0x38),
            1.0f + *(f32*)(record + 0x3c),
            *(f32*)(record + 0x24));
        campEquipDrawTextCall(
            *(f32*)(record + 0x24),
            (s32)(179.0f + *(f32*)(record + 0x38)),
            (s32)(10.0f + *(f32*)(record + 0x3c)),
            (0xff - *(u32*)(record + 0x40)) | ~0xff,
            0xa, 1, labels[3], 0x10, 0x78);
        return;
    case 4:
        {
            s32 id;
            s32 color;

            id = datGetEquipmentId(
                     *(s16*)((u8*)work + 0x12),
                     datGetEquipmentIdx(*(s16*)((u8*)work + 0x12),
                                        *(s16*)((u8*)work + 0x1c))) & 0xffff;
            color = func_0016f900(
                        *(s16*)((u8*)work + 0x12),
                        datGetEquipmentIdx(*(s16*)((u8*)work + 0x12),
                                           *(s16*)((u8*)work + 0x1c))) & 0xff;
            campEquipDrawValueCall(
                *(f32*)(record + 0x24), (s32)*(f32*)(record + 0x38),
                (s32)*(f32*)(record + 0x3c),
                (0xff - *(u32*)(record + 0x40)) | ~0xff,
                1, 0xa, 1, (u32)id | ((u32)color << 16));
        }
        return;
    case 5:
        {
            CampEquipSprite* sprite;

            sprite = (CampEquipSprite*)campEquipMakeSpriteCall(
                0, *(void**)((u8*)work + 0x2b0), 0x1a);
            sprite->spriteScale = *(f32*)(record + 0x24);
            sprite->x = *(f32*)(record + 0x38);
            sprite->y = *(f32*)(record + 0x3c);
            sprite->alpha = *(u8*)(record + 0x40);
            *(f32*)((u8*)sprite + 0x20) = -45.0f;
            campEquipSetSpriteCall(sprite, 1);
            campEquipSubmitSpriteCall(sprite);
        }
        return;
    case 6:
        campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b4),
                                0, *(u8*)(record + 0x40),
                                *(f32*)(record + 0x38),
                                *(f32*)(record + 0x3c),
                                *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(parent, *(void**)((u8*)work + 0x2b4),
                                5, *(u8*)(record + 0x40),
                                (44.0f + *(f32*)(record + 0x38)) - 28.0f,
                                *(f32*)(record + 0x3c),
                                *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(parent, *(void**)DAT_00833BA0_abs, 0,
                                *(u8*)(record + 0x40),
                                (486.0f + *(f32*)(record + 0x38)) - 28.0f,
                                *(f32*)(record + 0x3c),
                                *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(parent, *(void**)DAT_00833BA0_abs, 1,
                                *(u8*)(record + 0x40),
                                ((f32)0x231 + *(f32*)(record + 0x38)) - 28.0f,
                                *(f32*)(record + 0x3c),
                                *(f32*)(record + 0x24));
        return;
    default:
        return;
    }
}
#pragma optimization_level 2
#pragma opt_loop_invariants off

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

static inline void campEquipDrawItemList(void* work, u8* record, s32 xOffset,
                                  s32 yOffset, char* text)
{
    register void* parent;
    s32 row;
    s32 first;
    s32 count;
    s16 pcId;
    f32 scale;
    void* atlas;
    u8 alpha;

    first = *(s32*)((u8*)work + 0x24);
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
        selected = *(s32*)((u8*)work + 0x20) == item;
        y = *(f32*)(record + 0x3c) + (f32)(row * 30);
        campEquipDrawSpriteCall(
            parent, atlas, selected != 0 ? 0x25 : 0x26, alpha,
            *(f32*)(record + 0x38) + (f32)xOffset, y, scale);
        FUN_003b2cb0(scale, (s32)(*(f32*)(record + 0x38) + xOffset + 20),
                     (s32)y, 0xff - alpha, selected != 0 ? 6 : 10,
                     1, text, 0x10, 0);
    }
}
#pragma opt_loop_invariants on
// FUN_0012F6D0 NONMATCHING
void FUN_0012f6d0(void* work, s32 index, u8* record)
{
    char text[0x100];
    register void* parent;
    s16 pcId;
    s16 slot;
    s32 yDiv;
    s32 valA;
    s32 valB;
    s32 style;
    u16 equipment;
    u16 id;
    u8 effect;
    f32 posX;
    f32 posY;
    f32 scale;
    u8 alpha;
    CampVec2 equipVecA;
    CampVec2 equipVecB;

    switch ((u32)index) {
    case 0:
        campEquipDrawSpriteCall(
            parent, *(void**)((u8*)work + 0x2b0), 0x17,
            (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38),
            *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
        break;
    case 1:
        datGetEquipmentIdx(
            *(s16*)((u8*)work + 0x12), *(s16*)((u8*)work + 0x1c));
        switch (*(s16*)((u8*)work + 0x1c)) {
        case 0:
            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x12,
                (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38),
                *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x15,
                (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38) + 89.0f,
                *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
            break;
        case 1:
            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x13,
                (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38) + 4.0f,
                *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
            break;
        case 2:
            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x14,
                (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38) + 4.0f,
                *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
            break;
        default:
            break;
        }
        break;
    case 2:
        pcId = *(s16*)((u8*)work + 0x12);
        equipment = datGetEquipmentIdx(
            pcId, *(s16*)((u8*)work + 0x1c));
        style = FUN_0012df50(func_0016f720(1, equipment));
        id = datGetEquipmentId(pcId, equipment);
        effect = func_0016f810(pcId, equipment);
        sprintf(text, "%d", (s32)func_00171110(id, effect));
        campEquipDrawSpriteCall(
            parent, *(void**)((u8*)work + 0x2b0), 0x18,
            (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38),
            *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
        slot = *(s16*)((u8*)work + 0x1c);
        scale = *(f32*)(record + 0x24);
        posX = *(f32*)(record + 0x38);
        posY = *(f32*)(record + 0x3c);
        alpha = (u8)*(u32*)(record + 0x40);
        equipVecA.x = posX + 443.0f;
        equipVecA.y = posY + 15.0f;
        equipVecB.x = posX + 544.0f;
        equipVecB.y = posY + 15.0f;
        switch (slot) {
        case 0:
            valA = func_0016f9f0(pcId, equipment);
            FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                         equipVecA,
                         (s32)scale, 0xff, 0, 0, alpha, valA, 3);
            valB = func_0016fae0(pcId, equipment);
            FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                         equipVecB,
                         (s32)scale, 0xff, 0, 0, alpha, valB, 3);
            break;
        case 1:
            valA = func_0016fbd0(pcId, equipment);
            FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                         equipVecA,
                         (s32)scale, 0xff, 0, 0, alpha, valA, 3);
            break;
        case 2:
        default:
            valA = func_0016fcc0(pcId, equipment);
            FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                         equipVecA,
                         (s32)scale, 0xff, 0, 0, alpha, valA, 3);
            break;
        }
        campEquipDrawSpriteCall(
            parent, *(void**)((u8*)work + 0x2b0), style,
            alpha, posX + 48.0f,
            posY + 6.0f, scale);
        FUN_003b2cb0(
            scale,
            (s32)(posX + 179.0f),
            (s32)(posY + 10.0f),
            0xff - alpha,
            slot == 0 ? 6 : 10, 1, text, 0x10,
            0x78);
        break;
    case 3:
        {
            s32 itemCount;
            s32 firstItem;
            s16 equipmentIdx;
            s32 row;

            pcId = *(s16*)((u8*)work + 0x12);
            slot = *(s16*)((u8*)work + 0x1c);
            itemCount = *(s32*)((u8*)work + 0x2ac);
            firstItem = *(s32*)((u8*)work + 0x24);
            scale = *(f32*)(record + 0x24);
            posX = *(f32*)(record + 0x38);
            posY = *(f32*)(record + 0x3c);
            alpha = (u8)*(u32*)(record + 0x40);

            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x27,
                alpha,
                483.0f + posX,
                1.0f + posY,
                scale);

            if (itemCount > 5) {
                yDiv = (s32)(90 * firstItem) / (itemCount - 5);
            } else {
                yDiv = 0;
            }

            campEquipDrawSpriteCall(
                parent, *(void**)((u8*)work + 0x2b0), 0x28,
                alpha,
                483.0f + posX,
                3.0f + posY + (f32)yDiv,
                scale);

            equipmentIdx = datGetEquipmentIdx(pcId, slot);

            switch (slot) {
            case 0:
                valA = func_0016f9f0(pcId, equipmentIdx);
                valB = func_0016fae0(pcId, equipmentIdx);
                break;
            case 1:
                valA = func_0016fbd0(pcId, equipmentIdx);
                break;
            case 2:
            default:
                valA = func_0016fcc0(pcId, equipmentIdx);
                break;
            }

            for (row = 0; row < 5; row++) {
                s32 item;
                u16 eq;
                u16 equipId;
                u8 equipEffect;
                s32 equipStyle;

                item = firstItem + row;
                if (item >= itemCount) {
                    continue;
                }
                eq = *(u16*)((u8*)work + 0x28 + item * 2);
                equipStyle = FUN_0012df50(func_0016f720(1, eq));
                equipId = datGetEquipmentId(pcId, eq);
                equipEffect = func_0016f810(pcId, eq);
                sprintf(text, "%d", (s32)func_00171110(equipId, equipEffect));
                if (*(s32*)((u8*)work + 0x20) != item) {
                    campEquipDrawSpriteCall(
                        parent, *(void**)((u8*)work + 0x2b0), equipStyle,
                        alpha,
                        posX,
                        posY + (f32)(row * 30),
                        scale);
                } else {
                    campEquipDrawSpriteCall(
                        parent, *(void**)((u8*)work + 0x2b0), equipStyle,
                        alpha,
                        posX,
                        posY + (f32)(row * 30),
                        scale);
                }

                FUN_003b2cb0(
                    scale,
                    (s32)(posX + 20.0f),
                    (s32)(posY + (f32)(row * 30)),
                    0xff - alpha,
                    *(s32*)((u8*)work + 0x20) == item ? 6 : 10,
                    1, text, 0x10, 0);
            }

            for (row = 0; row < itemCount - firstItem; row++) {
                s32 item;
                u16 eq;
                u16 equipId;
                u8 equipEffect;
                s32 equipStyle;
                s32 selected;
                s32 statA;
                s32 statB;
                f32 statY;

                item = firstItem + row;
                if (item >= itemCount) {
                    continue;
                }
                eq = *(u16*)((u8*)work + 0x28 + item * 2);

                statY = posY + 3.0f + (f32)yDiv + (f32)(row * 30) + 15.0f;
                equipVecA.x = posX + 483.0f;
                equipVecA.y = statY;
                equipVecB.x = posX + 544.0f;
                equipVecB.y = statY;
                switch (slot) {
                case 0:
                    statA = func_0016f9f0(pcId, eq);
                    FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                                 equipVecA,
                                 (s32)scale, 0xff, 0, 0, alpha, statA, 3);
                    statB = func_0016fae0(pcId, eq);
                    FUN_0012e170(H_Maestro_001120a0(2), 0xb,
                                 equipVecB,
                                 (s32)scale, 0xff, 0, 0, alpha, statB, 3);
                    break;
                case 1:
                    statA = func_0016fbd0(pcId, eq);
                    FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                                 equipVecA,
                                 (s32)scale, 0xff, 0, 0, alpha, statA, 3);
                    break;
                case 2:
                default:
                    statA = func_0016fcc0(pcId, eq);
                    FUN_0012e170(H_Maestro_001120a0(1), 0xb,
                                 equipVecA,
                                 (s32)scale, 0xff, 0, 0, alpha, statA, 3);
                    break;
                }

                equipStyle = FUN_0012df50(func_0016f720(1, eq));
                equipId = datGetEquipmentId(pcId, eq);
                equipEffect = func_0016f810(pcId, eq);
                sprintf(text, "%d", (s32)func_00171110(equipId, equipEffect));
                selected = *(s32*)((u8*)work + 0x20) == item;
                campEquipDrawSpriteCall(
                    parent, *(void**)((u8*)work + 0x2b0), selected != 0 ? 0x25 : 0x26,
                    alpha,
                    posX + 483.0f,
                    posY + 3.0f + (f32)yDiv + (f32)(row * 30),
                    scale);
                FUN_003b2cb0(
                    scale,
                    (s32)(posX + 483.0f + 20.0f),
                    (s32)(posY + 3.0f + (f32)yDiv + (f32)(row * 30)),
                    0xff - alpha,
                    selected != 0 ? 6 : 10, 1, text, 0x10, 0);
            }
        }
        break;
    case 4:
        {
            void* sprite;
            sprite = campEquipMakeSpriteCall(
                NULL, *(void**)((u8*)work + 0x2b0), 0x1b);
            *(f32*)((u8*)sprite + 0x2c) = *(f32*)(record + 0x24);
            *(f32*)((u8*)sprite + 0x10) = *(f32*)(record + 0x38);
            *(f32*)((u8*)sprite + 0x14) = *(f32*)(record + 0x3c);
            *(u8*)((u8*)sprite + 0x18) = (u8)*(u32*)(record + 0x40);
            *(f32*)((u8*)sprite + 0x20) = -164.0f;
            campEquipSetSpriteCall(sprite, 1);
            campEquipSubmitSpriteCall(sprite);
        }
        break;
    case 5:
        break;
    case 6:
        pcId = *(s16*)((u8*)work + 0x12);
        equipment = *(u16*)((u8*)work + 0x28 +
                            (*(s32*)((u8*)work + 0x20) +
                             *(s32*)((u8*)work + 0x24)) * 2);
        id = datGetEquipmentId(pcId, equipment);
        effect = datGetEquipmentEffect(pcId, equipment);
        FUN_003c7e20(
            *(f32*)(record + 0x24), (s32)*(f32*)(record + 0x38),
            (s32)*(f32*)(record + 0x3c),
            0xff - (u8)*(u32*)(record + 0x40), 1, 10, 1,
            (id & 0xffff) | ((effect & 0xff) << 16));
        break;
    case 7:
        campEquipDrawSpriteCall(
            parent, *(void**)((u8*)work + 0x2b4), 0,
            (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38),
            *(f32*)(record + 0x3c), *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(
            parent, *(void**)((u8*)work + 0x2b4), 6,
            (u8)*(u32*)(record + 0x40), *(f32*)(record + 0x38) + 1.0f,
            *(f32*)(record + 0x3c) + 32.0f, *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(
            parent, DAT_00833BA0, 2, (u8)*(u32*)(record + 0x40),
            *(f32*)(record + 0x38) + 435.0f,
            *(f32*)(record + 0x3c) + 2.0f, *(f32*)(record + 0x24));
        campEquipDrawSpriteCall(
            parent, DAT_00833BA0, 1, (u8)*(u32*)(record + 0x40),
            *(f32*)(record + 0x38) + 561.0f,
            *(f32*)(record + 0x3c) + 2.0f, *(f32*)(record + 0x24));
        break;
    }

}
