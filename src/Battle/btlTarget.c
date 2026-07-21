#include "Battle/btlTarget.h"
#include "rw/rtquat.h"
#include "Script/scrScriptProcess.h"
#include "Script/scr.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Battle/btlPacket.h"
#include "Battle/btlAction.h"
#include "Battle/battle.h"
#include "Battle/btlUnit.h"
#include "Battle/btlVoice.h"
#include "Battle/btlBoss.h"
#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "Kosaka/k_assert.h"
#include "libm.h"
extern u32 func_002e4910();
#include "temporary.h"
#define BTLT_A8(ptr, offset) (*(u8*)((u8*)(ptr) + (offset)))
#define BTLT_A16(ptr, offset) (*(u16*)((u8*)(ptr) + (offset)))
#define BTLT_AS16(ptr, offset) (*(s16*)((u8*)(ptr) + (offset)))
#define BTLT_A32(ptr, offset) (*(u32*)((u8*)(ptr) + (offset)))
#define BTLT_D16(ptr, offset) (*(u16*)((u8*)(ptr) + (offset)))
#define BTLT_T8(base, offset) (*(u8*)(DAT_007ce3f8 + (base) + (offset)))
#define BTLT_T32(base, offset) (*(u32*)(DAT_007ce3f8 + (base) + (offset)))
#define BTLT_B32(offset) (*(u32*)(DAT_007ce3ec + (offset)))
#define BTLT_BS16(offset) (*(s16*)(DAT_007ce3ec + (offset)))
typedef struct BtlTargetPacketWork
{
    BtlAction *source;
    BtlAction *action;
    u8 data[0x1c];
    u16 effect;
    u16 targetFlags;
} BtlTargetPacketWork;

typedef struct BtlTargetScriptWork
{
    BtlAction* action;
    s32 procedureIndex;
    u32 started;
    ScrHeader* script;
} BtlTargetScriptWork;

typedef struct BtlTargetStatePacketWork
{
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;

typedef struct BtlTargetActionPacketWork
{
    BtlAction* action;
} BtlTargetActionPacketWork;

// FUN_002d7970
void FUN_002D7970(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount++;
    work->action->unit->packetCount++;
}

// FUN_002d7df0
void FUN_002D7DF0(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount--;
    work->action->unit->packetCount--;
}

void FUN_002dc550(BtlAction* action, u32 flags);
extern u16 FUN_002bff60(BtlAction* action, BtlTarget* target,
                         u16 commandId, u32 flags);

extern u8* iGpffffb6fc;
extern f32 fGpffff827c;
extern u8 DAT_00697880[];
extern f32 DAT_006978c0[];
extern u8* DAT_007ce42c;
extern BtlCommandRecord* iGpffffb710;
extern u32 DAT_007e094e;
extern u32 DAT_007e0958;
#pragma alias DAT_007e094e_u16 DAT_007e094e
#pragma alias DAT_007e0958_u16 DAT_007e0958
extern u16 DAT_007e094e_u16[];
extern u16 DAT_007e0958_u16[];
extern u8* gp0xffff9c60;
extern u8* gp0xffff9c68;
extern u8* gp0xffff9c70;
extern u8* gp0xffff9c78;
extern u32 uGpffffb7dc;
extern u32 uGpffffb7e0;
extern f32 fGpffff80d0;
extern void FUN_00521408(void* dst, s32 value, u32 size);
extern void FUN_0010A4E0(s32, s32, s32, s32);
extern void FUN_001FF310(void);
extern void FUN_001FF330(void);
extern s32 FUN_002FD7C0(void);
extern void FUN_002C6A00(void*, void*, u16);
extern s32 FUN_002FFBC0(s32);
extern void FUN_004C6AC0(f32*);
extern f32 FUN_004c6af0(f32*);
extern f32 FUN_004C6B20(RwV2d* dst, const RwV2d* src);
extern void FUN_004C6BE0(f32*, u64, s32);
extern f32 FUN_0052E9E8(f32);
extern f32 FUN_0052EA18(f32, f32);
extern void FUN_004BDDE0(u64, const void*, f32, s32);
extern void* FUN_0027EC10(s32, s32);
extern u32 FUN_0035C090(u32, u64);
extern s32 FUN_00195460();
extern s32 FUN_00198590(void);
extern u16 FUN_002d4cf0(u16 mask, u32 badStatus);
extern u16 FUN_002d4e10(u16 mask, u32 badStatus);
extern u32 FUN_002db480(void);
extern u32 FUN_002db690(void);
extern void FUN_002db650(u32 value);
extern u32 FUN_002db9f0(u16 command, u32 param);
extern void FUN_002dba80(void);
extern u8* iGpffffb720;
extern const char D_00697B18[];
extern const char* D_00697B90[];
extern s32 FUN_002daa20(BtlAction*, u16, s32, s32, s32);
typedef s64 (*BtlTargetEffectFn)(u64, u64, u64, u64);
extern u8* iGpffffb7b8;
extern BtlTargetEffectFn D_006978F0[];
void FUN_002db2a0(u32 param_1);
extern u8 D_00697980[];
extern u8 D_00697A50[];
extern u64 FUN_002FF790(void* genusBase);
extern u32 FUN_0030FC40(u32 command, DatUnit* unit_a, DatUnit* unit_b,
                        u32 param_4, u32 param_5);
extern void func_003c8f20(void);
extern void func_003c8f40(void);
extern void func_003c8f70(void);
extern void func_003c8fa0(void);
extern void func_003c8da0(u32 flags);
extern u32 func_00306e80(DatUnit* unit, u16 mode);

extern u8 DAT_00697730[];
extern u8 DAT_006977D0[];
extern s32 (*PTR_FUN_0069721c)(void*, s32);
extern s32 (*PTR_FUN_00697294)(void*, s32);
extern s32 (*PTR_FUN_006973cc)(void*, s32);
extern s32 (*PTR_FUN_006975e0[])(void*, u32);
extern u8* DAT_007ce484;
extern u8* DAT_007ce488;
static f32 btlTargetV2dLength(const RwV2d* v)
{
    return sqrtf(v->x * v->x + v->y * v->y);
}

// FUN_002d1570
void btlTargetInit(BtlTarget* target)
{
    memset(target, 0, sizeof(BtlTarget));
}

// FUN_002d15a0
void btlTargetReset(BtlTarget* target)
{
    target->targetedCount = 0;
    target->specificId = 0;
    target->unk_38 = 0;
    target->commandId = 0;

    memset(target->unk_3e, 0, sizeof(target->unk_3e));
}
// FUN_002d15e0
void FUN_002d15e0(BtlTarget* target)
{
    target->oldCommandId = target->commandId;
    target->oldSpecificId = target->specificId;
}

#pragma opt_loop_invariants on
// FUN_002d1600
u16 FUN_002d1600(BtlTarget* target)
{
    u16 mask = 0;
    u16 i = 0;
    u16 bit = 1;
    s32 count = target->targetedCount;

    for (; i < count; i++) {
        mask |= bit << target->targetedActions[i]->unit->genus;
    }
    return mask;
}
#pragma opt_loop_invariants off

// FUN_002d19b0
void FUN_002d19b0(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x2000) == 0) {
        *(u32*)(iGpffffb6fc + 0x0C) |= 0x2000;
        FUN_0010A4E0(0, 0x0F, 0, 3);
        FUN_001FF310();
    }
}

// FUN_002d1a10
void FUN_002d1a10(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x2000) != 0) {
        *(u32*)(iGpffffb6fc + 0x0C) &= ~0x2000u;
        FUN_0010A4E0(0, 0x0F, 0, 4);
        FUN_001FF330();
    }
}

// FUN_002d1a70
s32 FUN_002d1a70(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x80) != 0) {
        return 0;
    }
    return FUN_002FD7C0() != 0;
}

#pragma push
#pragma opt_rebuildconditionals off
// FUN_002d1ac0
void FUN_002d1ac0(void)
{
    s32 canToggle;
    u32* flags;
    u32 flagsValue;
    u32 mode;

    flags = (u32*)(iGpffffb6fc + 0x0c);
    if ((*flags & 0x80) != 0) {
        canToggle = 0;
    } else {
        if (FUN_002FD7C0() != 0)
            goto canToggleActive;
        canToggle = 0;
        goto canToggleDone;
    canToggleActive:
        canToggle = 1;
    canToggleDone:
        ;
    }
    if (canToggle == 0)
        goto done;
    flags = (u32*)(iGpffffb6fc + 0x0c);
    flagsValue = *flags;
    if ((flagsValue & 0x4000) == 0)
        goto done;
    mode = flagsValue & 0x2000;
    if (mode == 0)
        goto enableChecks;
    if ((DAT_007e094e_u16[0] & 0x10) != 0)
        goto disable;
    if ((DAT_007e0958_u16[0] & 0x10) != 0)
        goto disable;
    if ((DAT_007e094e_u16[0] & 0x20) != 0)
        goto disable;
    if ((DAT_007e0958_u16[0] & 0x20) == 0)
        goto done;
disable:
    if (mode == 0)
        goto done;
    *flags &= ~0x2000u;
    FUN_0010A4E0(0, 0x0f, 0, 4);
    FUN_001FF330();
    goto done;
enableChecks:
    if ((DAT_007e094e_u16[0] & 0x10) != 0)
        goto enable;
    if ((DAT_007e0958_u16[0] & 0x10) == 0)
        goto done;
enable:
    if (mode != 0)
        goto done;
    *flags |= 0x2000;
    FUN_0010A4E0(0, 0x0f, 0, 3);
    FUN_001FF310();
done:
    ;
}
#pragma pop

// FUN_002d1de0
void FUN_002d1de0(u64 task, const RwV3d* from, const RwV3d* to)
{
    f32 deltaX;
    f32 deltaZ;
    f32 angle;

    deltaX = to->x - from->x;
    deltaZ = to->z - from->z;
    angle = 0.0f;
    if (deltaX != 0.0f || deltaZ != 0.0f) {
        angle = fGpffff80d0 * FUN_0052EA18(deltaX, deltaZ);
    }
    FUN_004BDDE0(task, DAT_00697880, angle, 0);
}
// FUN_002d1e70
void FUN_002d1e70(f32* from, f32* to)
{
    f32 delta[3];
    delta[0] = from[0] - to[0];
    delta[1] = from[1] - to[1];
    delta[2] = from[2] - to[2];
    FUN_004C6AC0(delta);
}

// FUN_002d1ed0
void FUN_002d1ed0(f32* from, f32* to)
{
    f32 delta[4];
    delta[0] = from[0] - to[0];
    delta[1] = from[1] - to[1];
    delta[2] = from[2] - to[2];
    delta[1] = 0.0f;
    FUN_004C6AC0(delta);
}

// FUN_002d1f30
f32 FUN_002d1f30(f32* left, f32* right)
{
    f32 dot = left[0] * right[0] + left[1] * right[1] +
              left[2] * right[2];
    dot += left[3] * right[3];

    if (dot < 0.0f)
    {
        dot = left[0] * -right[0] + left[1] * -right[1] +
              left[2] * -right[2];
        dot += left[3] * -right[3];
    }
    return FUN_0052E9E8(dot) * 2.0f;
}

// FUN_002d1fd0
f32 FUN_002d1fd0(f32* a, f32* b, f32* point, f32* projected)
{
    f32 result;
    RwV2d axis;
    f32 distance;
    f32* pointAlias;
    f32 axisY;
    f32 dx;
    f32 dy;

    axis.x = a[0] - b[0];
    axis.y = a[1] - b[1];
    FUN_004C6B20(&axis, &axis);
    dx = point[0] - a[0];
    axisY = axis.y;
    distance = a[1];
    pointAlias = point;
    dy = point[1] - distance;
    result = dx * axisY + dy * -axis.x;
    distance = result;
    if (projected != NULL) {
        projected[0] = pointAlias[0] - distance * axisY;
        projected[1] = point[1] - distance * -axis.x;
    }
    return fabsf(distance);
}

// FUN_002d21e0
f32 FUN_002d21e0(f32 value, volatile f32* state)
{
    f32 current;
    f32 slopeBase;
    f32 remaining;
    f32 resultBase;
    f32 slope;
    f32 result;

    current = state[1];
    slopeBase = state[3];
    resultBase = state[4];
    remaining = current - value;

    if (remaining <= 0.0f)
    {
        return 1.0f;
    }
    if (remaining < state[0] * 0.5f)
    {
        slope = slopeBase - state[2] * value;
    }
    else
    {
        slope = state[2] * value + slopeBase;
    }
    result = slope * value + resultBase;
    state[1] = remaining;
    state[3] = slope;
    state[4] = result;
    return result;
}

// FUN_002d2280
void FUN_002d2280(s16* outX, s16* outZ, f32* position)
{
    s32 x = (s32)(position[0] + 1750.0f);
    s32 z = (s32)(position[2] + 1750.0f);
    s16 tileX = (s16)(x / 0x19);
    s16 tileZ = (s16)(z / 0x19);
    if (x % 0x19 > 0x0C) tileX++;
    if (z % 0x19 > 0x0C) tileZ++;
    if (outX != NULL) *outX = tileX;
    if (outZ != NULL) *outZ = tileZ;
}

#pragma alias FUN_002d2340_s16 FUN_002d2340
extern void FUN_002d2340_s16(f32 distance, u8* work, s16 start, s16 end);
#pragma push
#pragma opt_propagation off
// FUN_002d2340
void FUN_002d2340(f32 distance, u8* work, s32 start, s32 end)
{
    s32 tiles;
    s16 leftTile;
    s16 rightTile;
    s16 span;
    s16 topTile;
    s16 bottomTile;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    tiles = (s16)((s32)distance / 0x19);
    if ((s32)distance % 0x19 != 0)
        tiles = (s16)(tiles + 1);
    leftTile = start - tiles;
    rightTile = end - tiles;
    left = (f32)(leftTile * 0x19 - 0x6d6);
    right = (f32)(rightTile * 0x19 - 0x6d6);
    span = (s16)tiles * 2;
    topTile = leftTile + span;
    bottomTile = rightTile + span;
    top = (f32)(topTile * 0x19 - 0x6d6);
    bottom = (f32)(bottomTile * 0x19 - 0x6d6);
    *(f32*)(work + 0x504) = left;
    *(f32*)(work + 0x508) = right;
    *(f32*)(work + 0x634) = top;
    *(f32*)(work + 0x638) = right;
    *(f32*)(work + 0x764) = top;
    *(f32*)(work + 0x768) = bottom;
    *(f32*)(work + 0x894) = left;
    *(f32*)(work + 0x898) = bottom;
}
#pragma pop

// FUN_002d2470
s32 FUN_002d2470(const f32* a, const f32* b, const f32* point, f32 tolerance)
{
    RwV2d axis;
    f32 projected[2];
    f32 dy;
    f32 dx;
    f32 axisX;
    f32 axisY;
    axis.x = a[0] - b[0];
    axis.y = a[1] - b[1];
    FUN_004C6B20(&axis, &axis);
    dx = point[0] - a[0];
    dy = point[1] - a[1];
    axisX = -axis.x;
    axisY = axis.y;
    dy = dy * axisX;
    dx = dx * axisY + dy;
    projected[0] = point[0] - dx * axisY;
    projected[1] = point[1] - dx * axisX;
    if (((a[0] < projected[0] || b[0] > projected[0]) &&
         (a[0] > projected[0] || b[0] < projected[0])) ||
        ((a[1] < projected[1] || b[1] > projected[1]) &&
         (a[1] > projected[1] || b[1] < projected[1]))) {
        return 0;
    }
    return fabsf(dx) < tolerance;
}
#pragma alias FUN_002d2470_call FUN_002d2470
extern s32 FUN_002d2470_call(f32 tolerance, const f32* a, const f32* b,
                             const f32* point);
// FUN_002d1660 NONMATCHING
void FUN_002d1660(void* source, BtlTarget* target, u64 mask)
{
    u8* table = NULL;
    u32 state = 0;
    u16 total = 0;
    u16 roll;
    u16 i;
    u8* selected = NULL;

    FUN_002d15a0(target);
    mask &= 0xFFFFFu;
    if (mask == 0x200) {
        selected = gp0xffff9c78;
    } else if (mask == 0x40) {
        selected = gp0xffff9c70;
    } else if (mask == 0x20) {
        selected = gp0xffff9c68;
    } else if (mask == 0x10) {
        selected = gp0xffff9c60;
    } else if (mask == 8) {
        u8* work = *(u8**)((u8*)source + 0x30);
        if (work[0xA2] != 0 || *(s16*)(work + 0xA4) != 1) {
            state = PTR_FUN_00697294(source, 0) != 1;
        } else {
            state = 1;
        }
        table = DAT_006977D0;
    } else if (mask == 1) {
        s32 first = PTR_FUN_006973cc(source, 0);
        s32 second = PTR_FUN_0069721c(source, 1);
        if (first == 1 && second == 0) {
            state = 0;
        } else if (first != 1 && second == 0) {
            state = first == 0 ? 2 : state;
        } else if (first == 0 && second != 0) {
            state = 3;
        } else {
            state = 1;
        }
        table = DAT_00697730;
    }
    if (table != NULL) {
        table += (state & 0xFFFFu) * 0x28;
        for (i = 0; i < 5; i++) {
            total = (u16)(total + table[i * 8]);
        }
        roll = (u16)FUN_002FFBC0(total);
        total = 0;
        selected = NULL;
        for (i = 0; i < 5; i++) {
            u8 weight = table[i * 8];
            selected = table + i * 8;
            total = (u16)(total + weight);
            if (roll <= total && weight != 0) {
                break;
            }
        }
    }
    FUN_002C6A00(source, target, *(u16*)(selected + 2));
    {
        u32 callback = *(u32*)(selected + 4);
        s32 result = PTR_FUN_006975e0[(callback >> 24) * 2](
            source, callback & 0xFFFFFFu);
        if (result == 0) {
            PTR_FUN_006975e0[0](source, 0);
        }
    }
}

// FUN_002d4ed0 NONMATCHING
u32 FUN_002d4ed0(s32 param_1)
{
    u16 encountId;
    u32 encountFlags;
    u16 startValue;
    u16 startValue2;
    u32 threshold;

    encountId = gBtl->startInfo.enmUnits->encountId;
    if (encountId == 0x1d5)
    {
        u16 count = (u16)FUN_001756f0();
        u16 i;

        for (i = 0; i < count; i++)
        {
            DatPersonaWork* persona = datPersonaGetHeroPersona((s16)i);
            if (persona->id == 0x4c)
            {
                break;
            }
        }
        return i == count;
    }
    if (encountId == 0x1d4)
    {
        return 1;
    }

    /* These two halfwords are unnamed fields in the battle work. */
    startValue = *(u16*)((u8*)gBtl + 0xb9a);
    if (startValue == 0)
    {
        return 0;
    }

    encountFlags = *(u32*)((u8*)gEncountTbl + (u32)encountId * 0x1c);
    if ((encountFlags & 2) != 0)
    {
        return 0;
    }
    if ((encountFlags & 4) != 0)
    {
        return 1;
    }
    if ((u32)(uintptr_t)gBtl->actionList.head == (u32)param_1)
    {
        return 1;
    }

    threshold = (u32)*(DAT_007ce488 + ((startValue - 1u > 8u) ? 8u : (startValue - 1u)));
    startValue2 = *(u16*)((u8*)gBtl + 0xb9c);
    if (startValue2 != 0)
    {
        u32 index = (u32)startValue2 - 1u;
        if (index > 5u)
        {
            index = 5u;
        }
        threshold += (u32)*(DAT_007ce488 + index + 9u);
    }
    return datCalcRand(100) < threshold;
}

// FUN_002d50c0 NONMATCHING
u16 FUN_002d50c0(void)
{
    u16 encountId = gBtl->startInfo.enmUnits->encountId;
    u16 startFlags = (u16)gBtl->startInfo.unk_00;
    u16 value1;
    u16 value2;
    u16 chance;
    u32 hasSpecialSkill = 0;
    BtlUnit* unit;

    if (encountId == 0x1fa && datGetFlag(0x1319) != 0)
    {
        return 2;
    }

    {
        u32 encountFlags = *(u32*)((u8*)gEncountTbl + (u32)encountId * 0x1c);
        if ((encountFlags & 8) != 0)
        {
            return 0;
        }
        if ((encountFlags & 0x10) != 0)
        {
            return 2;
        }
        if ((encountFlags & 0x800) != 0)
        {
            return 1;
        }
    }

    if ((startFlags & 4) != 0)
    {
        return 0;
    }

    for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
         unit != NULL;
         unit = unit->next)
    {
        if (unit->datUnit != NULL && datCalcHasSkill(unit->datUnit, 0x230) != 0)
        {
            hasSpecialSkill = 1;
            break;
        }
    }

    value1 = (u16)FUN_002d4cf0(1, 0);
    value2 = (u16)FUN_002d4cf0(2, 0);

    if ((startFlags & 1) == 0)
    {
        if ((startFlags & 2) == 0)
        {
            return 1;
        }
        if (datGetFlag(0x1319) == 0 || (startFlags & 8) != 0)
        {
            return 0;
        }

        {
            f32 ratio = ((f32)value2 / (f32)value1) * 20.0f;
            if (ratio >= 2147483648.0f)
            {
                ratio -= 2147483648.0f;
            }
            chance = (u16)(s32)ratio;
        }
        return datCalcRand(100) < chance ? 2 : 0;
    }

    {
        f32 ratio = ((f32)value1 / (f32)value2) * 20.0f;
        if (ratio >= 2147483648.0f)
        {
            ratio -= 2147483648.0f;
        }
        chance = (u16)(s32)ratio;
    }
    if (hasSpecialSkill != 0)
    {
        f32 ratio = (f32)chance * 0.5f;
        if (ratio >= 2147483648.0f)
        {
            ratio -= 2147483648.0f;
        }
        chance = (u16)(s32)ratio;
    }
    if (datGetFlag(0x1319) != 0)
    {
        return 2;
    }
    return datCalcRand(100) < chance ? 2 : 0;
}

// FUN_002d5550
u16 FUN_002d5550(void)
{
    return gBtl->startInfo.enmUnits->encountId;
}

// FUN_002d5570 NONMATCHING
u16 FUN_002d5570(s32 param_1)
{
    u16 result = 0xffff;

    if (param_1 < 0x110 || param_1 > 0x130)
    {
        return result;
    }
    if (param_1 == 0x115)
    {
        switch (datCalcRand(8))
        {
            case 0: result = 0x100; break;
            case 1: result = 0x101; break;
            case 2: result = 0x102; break;
            case 3: result = 0x103; break;
            case 4: result = 0x104; break;
            case 5: result = 0x105; break;
            case 6: result = 0x106; break;
            case 7: result = 0x109; break;
        }
    }
    else if (param_1 == 0x112 && datCalcRand(100) < 5)
    {
        result = 0x122;
    }
    return result;
}

// FUN_002d56a0 NONMATCHING
u32 FUN_002d56a0(s32 param_1)
{
    switch (param_1)
    {
        case 0x14b: return 0x98;
        case 0x14a: return 0x96;
        case 0x149: return 0x94;
        case 0x148: return 0x92;
        case 0x147: return 0x90;
        case 0x67:
        case 0x66:  return 0x44;
        case 0x170: return 0xa4;
        case 0x134: return 0x86;
        case 0x122: return 0x84;
        case 0x120: return 0xae;
        case 0x10e: return 0x82;
        case 0x10d: return 0x80;
        case 0x10c: return 0x7e;
        case 0x10b: return 0x7c;
        case 0x10a: return 0x7a;
        case 0x109: return 0x76;
        case 0x108: return 0x74;
        case 0x107: return 0x72;
        case 0x106: return 0x70;
        case 0x105: return 0x6e;
        case 0x104: return 0x6c;
        case 0x103: return 0x6a;
        case 0x102: return 0x68;
        case 0x101: return 0x66;
        case 0x100: return 0x64;
        case 0x0e8: return 0xaa;
        case 0x0e7: return 0xac;
        case 0x0e6: return 0xa8;
        case 0x0e5: return 0xa6;
        case 0x117: return 0x58;
        case 0x114: return 0x56;
        case 0x113: return 0x54;
        case 0x4a:
        case 0x49:  return 0x52;
        case 0xdd:  return 0xa0;
        case 0xdc:  return 0x9e;
        case 0xe3:  return 0x50;
        case 0xe2:  return 0x4e;
        case 0xd4:  return 0x9c;
        case 0xd3:
        case 0xd2:  return 0x8e;
        case 0xd1:
        case 0xd0:  return 0x8c;
        case 0xcf:
        case 0xce:  return 0x8a;
        case 0xdf:  return 0x9a;
        case 0xdb:
        case 0xda:  return 0x4c;
        case 0xd9:
        case 0xd8:  return 0x4a;
        case 0xd7:
        case 0xd6:  return 0x48;
        default:    return 0;
    }
}

typedef u8 undefined1;
typedef u16 ushort;
typedef u8 byte;
typedef u32 uint;
typedef void (*code)();
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef u64 ulong;
typedef u8 bool;
#ifndef false
#define false 0
#define true 1
#endif

/* Declaration notes: these raw FUN/LAB/DAT symbols are retained where no canonical
 * target-module API has been established.  FUN_0027ec10 is btlPacketCreate;
 * FUN_00300580/FUN_0030b5a0/FUN_0030b5e0/FUN_003005e0 are datCalc status/dead,
 * low-HP, and skill queries; FUN_002ffcc0/FUN_002ffd70/FUN_002ffdf0 are the
 * datCalc level/HP/max-HP queries.  FUN_00174800/FUN_00174a90 map to the
 * persona getters, FUN_0016c4f0/FUN_0016c5f0/FUN_0016c970/FUN_0016c920/
 * FUN_0016dd60/FUN_0017b170 map to datGetHp/datGetMaxHp/
 * datGetBadStatusNoDown/datGetPhysicalCondition/datGetPartyId/datGetTotalBtl.
 * iGpffffb6fc is the battle-work base (gBtl/DAT_007ce3ec alias); iGpffffb720
 * is the enemy-data table (DAT_007ce410 alias).  Retail ABI arguments omitted by
 * Ghidra are explicit in FUN_002d9d70: party slot, persona pc-id, and random-list
 * count.  FUN_002d8390 uses the retail slti/xori inversion (difference >= 4). */
extern u64 FUN_0016c4f0();
extern u64 FUN_0016c5f0();
extern u64 FUN_0016c920();
extern u64 FUN_0016c970();
extern u64 FUN_0016dd60();
extern u64 FUN_0016f190();
extern u64 FUN_00170670();
extern u64 FUN_001706c0();
extern u64 FUN_00170710();
extern u64 FUN_00170760();
extern u64 FUN_00170860();
extern u64 FUN_00174800();
extern u64 FUN_00174a90();
extern u64 FUN_00175360();
extern u64 FUN_00175ca0();
extern u64 FUN_0017b170();
extern u64 FUN_0027ec10();
extern u64 FUN_0029a1d0();
extern u64 FUN_002ddc10();
extern u32 func_002ddc10(u32 unitId);
extern u64 FUN_002ffbc0();
extern u64 FUN_002ffcc0();
extern u64 FUN_002ffd70();
extern u64 FUN_002ffdf0();
extern u64 FUN_00300410();
extern u64 FUN_00300480();
extern u64 FUN_00300580();
extern u64 FUN_003005e0();
extern u64 FUN_00301ca0();
extern void FUN_00302c50(u32 datUnit);
extern u64 FUN_003083f0();
extern u64 FUN_0030b5a0();
extern u64 FUN_0030b5e0();
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce410;
extern u8* iGpffffb6fc;
extern u8* iGpffffb720;

// FUN_002d7ef0
void func_002d7ef0(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    work->action->unit->packetCount++;
}

// FUN_002d7f10
u32 func_002d7f10(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    u8 value;

    if ((work->flags & 2) != 0)
    {
        work->action->unk_28 = 0;
    }
    else if ((work->flags & 1) != 0)
    {
        work->action->unk_28++;
    }
    else
    {
        value = work->action->unk_28;
        if (value > 0)
        {
            if (value > 1)
            {
                value = 1;
            }
            work->action->unk_28 = value - 1;
        }
    }
    return 1;
}

// FUN_002d7f90
void func_002d7f90(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    work->action->unit->packetCount--;
}

// FUN_002d7fb0
void FUN_002d7fb0(BtlAction* action, u8 flags)
{
    BtlPacket* packet = btlPacketCreate(0x701, sizeof(BtlTargetStatePacketWork));
    BtlTargetStatePacketWork* work;

    packet->initFunc = func_002d7ef0;
    packet->updateFunc = func_002d7f10;
    packet->destroyFunc = func_002d7f90;
    work = (BtlTargetStatePacketWork*)packet->workData;
    work->action = action;
    work->flags = flags;
}


// FUN_002d8020
void func_002d8020(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount++;
}

// FUN_002d8040
u32 FUN_002d8040(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    FUN_00302c50((u32)(uintptr_t)work->action->unit->datUnit);
    return 1;
}
// FUN_002d8070
void FUN_002d8070(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount--;
}


// FUN_002d8090
void FUN_002d8090(BtlAction* action)
{
    BtlPacket* packet = btlPacketCreate(0x703, sizeof(BtlTargetActionPacketWork));
    BtlTargetActionPacketWork* work;

    packet->initFunc = func_002d8020;
    packet->updateFunc = FUN_002d8040;
    packet->destroyFunc = FUN_002d8070;
    work = (BtlTargetActionPacketWork*)packet->workData;
    work->action = action;
}

// FUN_002d80f0
void func_002d80f0(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount++;
}

// FUN_002d8110 NONMATCHING

undefined4 FUN_002d8110(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  long lVar7;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x30);
  sVar6 = *(short *)(iVar2 + 0x6c);
  if ((sVar6 != 1) && (sVar6 != 9)) {
    if (sVar6 == 3) {
      if (*(char *)(iVar3 + 0xa2) == '\0') {
        sVar6 = *(short *)(iVar2 + 0x70);
        if (*(short *)(*(int *)(iVar3 + 0xa2c) + 2) == 1) {
          sVar4 = FUN_00170760(1,sVar6);
          FUN_00170860(*(undefined2 *)(*(int *)(iVar3 + 0xa2c) + 2),sVar6,sVar4 + -1);
        }
        else {
          uVar5 = 0;
          while ((uVar5 < 0xc &&
                 (sVar4 = FUN_00170670(*(undefined2 *)(*(int *)(iVar3 + 0xa2c) + 2),uVar5),
                 sVar6 != sVar4))) {
            uVar5 = uVar5 + 1;
          }
          sVar6 = FUN_001706c0(*(undefined2 *)(*(int *)(iVar3 + 0xa2c) + 2),uVar5);
          FUN_00170710(*(undefined2 *)(*(int *)(iVar3 + 0xa2c) + 2),uVar5,sVar6 + -1);
        }
      }
    }
    else if (sVar6 == 2) {
      uVar5 = *(ushort *)(iVar2 + 0x6e);
      lVar7 = FUN_003083f0(*(undefined4 *)(iVar3 + 0xa2c),uVar5);
      if (lVar7 != 0) {
        cVar1 = *(char *)(((uint)uVar5 * 10 + (uint)uVar5) * 4 + DAT_007ce3f8 + 3);
        if (cVar1 == '\x02') {
          FUN_00300480(*(undefined4 *)(iVar3 + 0xa2c),-(int)lVar7);
        }
        else if (cVar1 == '\x01') {
          FUN_00300410(*(undefined4 *)(iVar3 + 0xa2c),-(int)lVar7);
        }
      }
    }
  }
  return 1;
}

// FUN_002d8310
void func_002d8310(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount--;
}

// FUN_002d8330

void FUN_002d8330(BtlAction* action)
{
    BtlPacket* packet = btlPacketCreate(0x702, sizeof(BtlTargetActionPacketWork));
    BtlTargetActionPacketWork* work;

    packet->initFunc = func_002d80f0;
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002d8110;
    packet->destroyFunc = func_002d8310;
    work = (BtlTargetActionPacketWork*)packet->workData;
    work->action = action;
}

// FUN_002d8390 NONMATCHING

int FUN_002d8390(void)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  
  uVar7 = FUN_002d4e10(2,0x80000);
  uVar7 = uVar7 & 0xffff;
  if (uVar7 < 6) {
    uVar8 = FUN_002d4cf0(2,0x80000);
    uVar9 = FUN_002ffcc0(*(undefined4 *)(*(int *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30) + 0xa2c));
    bVar3 = (int)((uVar8 & 0xffff) - (uVar9 & 0xff)) >= 4;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    for (iVar10 = *(int *)(DAT_007ce3ec + 0x158); iVar10 != 0; iVar10 = *(int *)(iVar10 + 0xa34)) {
      lVar11 = FUN_00300580(*(undefined4 *)(iVar10 + 0xa2c),2);
      if (lVar11 != 0) {
        bVar6 = true;
      }
      uVar1 = *(ushort *)(DAT_007ce410 + (uint)*(ushort *)(iVar10 + 0xa4) * 0x3e);
      if ((uVar1 & 0x40) != 0) {
        bVar5 = true;
      }
      if ((uVar1 & 0x80) != 0) {
        bVar4 = true;
      }
    }
    sVar2 = *(short *)(DAT_007ce3ec + 0x1a);
    if (sVar2 == 2) {
      if (bVar4) {
        iVar10 = 0x5c;
      }
      else if (bVar5) {
        iVar10 = 0x5d;
      }
      else if (bVar3) {
        iVar10 = uVar7 + 0x51;
      }
      else {
        iVar10 = uVar7 + 0x56;
      }
    }
    else if (sVar2 == 1) {
      if (bVar4) {
        iVar10 = 0x50;
      }
      else if (bVar5) {
        iVar10 = 0x51;
      }
      else if (bVar3) {
        if (bVar6) {
          iVar10 = 5;
        }
        else {
          iVar10 = 0;
        }
        iVar10 = uVar7 + 0x3b + iVar10;
      }
      else {
        if (bVar6) {
          iVar10 = 5;
        }
        else {
          iVar10 = 0;
        }
        iVar10 = uVar7 + 0x45 + iVar10;
      }
    }
    else if (sVar2 == 0) {
      if (bVar4) {
        iVar10 = 10;
      }
      else if (bVar5) {
        iVar10 = 0xb;
      }
      else if (bVar3) {
        iVar10 = uVar7 - 1;
      }
      else {
        iVar10 = uVar7 + 4;
      }
    }
    else {
      iVar10 = -1;
    }
  }
  else {
    iVar10 = -1;
  }
  return iVar10;
}

// FUN_002D8610

undefined4 FUN_002d8610(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*(int *)(DAT_007ce3ec + 0xa20) == 0x5e) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = FUN_002d4e10(1,0x80000);
    if (uVar1 < 2) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0x5e;
    }
  }
  return uVar2;
}

// FUN_002D8680
int func_002D8680(u64 param_1, int param_2)
{
    int result = 1;

    (void)param_1;
    if (param_2 == 1)
    {
        goto one;
    }
    switch (param_2)
    {
    case 0:
        result = 0x5f;
        goto done;
    default:
        goto default_case;
    }
one:
    result = -1;
    goto done;
default_case:
    result = -1;
done:
    return result;
}
// FUN_002D86C0
int func_002D86C0(int param_1)
{
    int action = *(int*)(param_1 + 0x30);

    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
        case 2: return 0x60;
        case 3: return 0x61;
        case 4: return 0x62;
        case 5: return 0x63;
        case 7: return 0x64;
        case 8: return 0x65;
        case 9: return 0x66;
        case 10: return 0x67;
        default: return -1;
    }
}


// FUN_002d8850 MATCHING
s32 FUN_002d8850(s32 param_1)
{
    bool noRandom;
    if (*(u8*)(*(u8**)(param_1 + 0x30) + 0xa2) != 0) {
        return -1;
    }
    noRandom = (u16)FUN_002db480() == 0;
    switch (*(u16*)(*(u8**)(param_1 + 0x30) + 0xa4)) {
    case 2:
        if (noRandom) return 0x72;
        return 0x71;
    case 3:
        if (noRandom) return 0x74;
        return 0x73;
    case 4:
        if (noRandom) return 0x76;
        return 0x75;
    case 5:
        if (noRandom) return 0x78;
        return 0x77;
    case 7:
        if (noRandom) return 0x7a;
        return 0x79;
    case 8:
        if (noRandom) return 0x7c;
        return 0x7b;
    case 9:
        if (noRandom) return 0x7e;
        return 0x7d;
    case 10:
        if (noRandom) return 0x80;
        return 0x7f;
    default:
        return -1;
    }
}

// FUN_002d89e0 MATCHING
s32 func_002d89e0(u64 param_1, s32 param_2)
{
    (void)param_1;
    switch (param_2)
    {
    case 2:
        return 0xbf;
    case 3:
        return 0xc0;
    case 4:
        return 0xc1;
    case 5:
        return 0xc2;
    case 7:
        return 0xc3;
    case 8:
        return 0xc4;
    case 9:
        return 0xc5;
    case 10:
        return 0xc6;
    default:
        return -1;
    }
}

// FUN_002d8a80 MATCHING
s32 func_002d8a80(void)
{
    s32 result;

    switch (*(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a1:
        result = 0x88;
        break;
    default:
        result = 0x87;
        break;
    }
    return result;
}

// FUN_002d8ac0 MATCHING
s32 func_002d8ac0(void)
{
    s32 result;

    switch (*(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a1:
        result = 0x84;
        break;
    default:
        result = 0x83;
        break;
    }
    return result;
}

// FUN_002d8b00 MATCHING
s32 func_002d8b00(void)
{
    return 0x8f;
}

// FUN_002d8b10 MATCHING
s32 func_002d8b10(void)
{
    return 0xb6;
}

// FUN_002d8b20 MATCHING
s32 func_002d8b20(void)
{
    return 0xb1;
}

// FUN_002d8b30 MATCHING
s32 func_002d8b30(void)
{
    return 0xb2;
}

// FUN_002d8b40

s32 FUN_002d8b40(s32 param_1)
{
    u32 personaId;
    u16 hp;
    u16 maxHp;
    s32 hpPercent;

    if (*(s32*)(iGpffffb6fc + 0x148) != param_1)
    {
        return -1;
    }
    if (FUN_0016f190(0x1362) != 0)
    {
        if (FUN_0016f190(0x1361) != 0)
        {
            return 0x1ba;
        }
        if (FUN_0016f190(0x1360) != 0)
        {
            return 0x1bc;
        }
    }
    if (*(u16*)(iGpffffb6fc + 0xb9a) == 0)
    {
        return 0x6c;
    }

    personaId = *(u32*)(*(s32*)(param_1 + 0x30) + 0xa2c);
    hp = (u16)FUN_002ffd70(personaId);
    maxHp = (u16)FUN_002ffdf0(personaId);
    hpPercent = hp * 100 / maxHp;
    if (hpPercent > 0x46)
    {
        if (*(s32*)(*(s32*)(iGpffffb6fc + 0x148) + 0x20) < 3)
        {
            if (FUN_002ddc10(6) == 0)
            {
                return 0xce;
            }
            return 0xd1;
        }
    }
    if (hpPercent <= 0x1e)
    {
        goto criticalHp;
    }
    if (FUN_002ddc10(6) == 0)
    {
        return 0xcf;
    }
    return 0xd2;
criticalHp:
    if (FUN_002ddc10(6) == 0)
    {
        return 0xd0;
    }
    return 0xd3;
}

// FUN_002d8cf0 MATCHING
s32 func_002d8cf0(s32 param_1)
{
    s32 action;

    action = *(s32*)(param_1 + 0x30);
    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
    case 1:
        return 0xd4;
    case 2:
        return 0xd5;
    case 3:
        return 0xd6;
    case 4:
        return 0xd7;
    case 5:
        return 0xd8;
    case 7:
        return 0xd9;
    case 8:
        return 0xda;
    case 9:
        return 0xdb;
    case 10:
        return 0xdc;
    default:
        return -1;
    }
}

// FUN_002d8db0 MATCHING
s32 func_002d8db0(void)
{
    return -1;
}

// FUN_002d8dc0 MATCHING
s32 func_002d8dc0(s32 param_1)
{
    s32 action;

    action = *(s32*)(param_1 + 0x30);
    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
    case 1:
        return 0xdd;
    case 2:
        return 0xde;
    case 3:
        return 0xdf;
    case 4:
        return 0xe0;
    case 5:
        return 0xe1;
    case 7:
        return 0xe2;
    case 8:
        return 0xe3;
    case 9:
        return 0xe4;
    case 10:
        return 0xe5;
    default:
        return -1;
    }
}

// FUN_002d8e80

s32 FUN_002d8e80(BtlAction* action, s32 mode)
{
    s32 result;

    if (mode != 0)
    {
        result = 0xe8;
    }
    else if ((action->unk_18 & 0x1800) != 0)
    {
        result = 0xe9;
    }
    else
    {
        if (func_002ddc10(6) == 0)
        {
            result = 0xe6;
        }
        else
        {
            result = 0xe7;
        }
    }
    return result;
}

// FUN_002d8ef0
s32 FUN_002d8ef0(BtlAction* action)
{
    s32 result;

    if (gBtl->actionList.head == action)
    {
        result = 0xea;
    }
    else if (action->unit->genus == UNIT_GENUS_EC)
    {
        result = 0xeb;
    }
    else
    {
        result = -1;
    }
    return result;
}

// FUN_002d8f40
s32 FUN_002d8f40(BtlAction* action)
{
    s32 result;

    if (gBtl->actionList.head == action)
    {
        result = 0x18e;
    }
    else
    {
        result = -1;
    }
    return result;
}

// FUN_002d8f70 NONMATCHING

int FUN_002d8f70(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(u8 *)(*(u32 *)(param_1 + 0x30) + 0xa2) == 0) {
    uVar3 = FUN_002d4e10(2,0x80000);
    uVar3 = uVar3 & 0xffff;
    uVar2 = *(ushort *)(param_1 + 0x1a);
    *(ushort *)(param_1 + 0x1a) = uVar2 | 0x40;
    switch(*(undefined2 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    default:
      iVar4 = -1;
      break;
    case 1:
      bVar1 = *(byte *)(param_1 + 0x28);
      if ((bVar1 < 2) || ((uVar2 & 0x40) == 0)) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0xf0 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0xf3 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0xf5 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0xf6 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 2:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0xfb - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0xfe - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x100 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x101 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x101;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 3:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x106 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x109 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x10b - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x10c - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x10c;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 4:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x111 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x114 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x116 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x117 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x117;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 5:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x11c - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x11f - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x121 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x122 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x122;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 7:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x127 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x12a - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 300 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x12d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x12d;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 8:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x132 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x135 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x137 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x138 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x138;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 9:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x13d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x140 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x142 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x143 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x143;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 10:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x148 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x14b - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x14d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x14e - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x14e;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
  }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}

// FUN_002d9d70 NONMATCHING

short FUN_002d9d70(int param_1)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  short sVar11;
  bool bVar12;
  short *psVar13;
  short asStack_100 [128];
  
  if (*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == '\0') {
    uVar7 = 0;
    uVar4 = 0;
    for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
      lVar8 = FUN_0030b5a0(*(undefined4 *)(iVar2 + 0xa2c),0);
      if ((lVar8 == 0) &&
         ((lVar8 = FUN_0029a1d0(iVar2), lVar8 == 0 || ((*(ushort *)((int)lVar8 + 0x18) & 0x20) == 0)
          ))) {
        lVar8 = FUN_0030b5e0(*(undefined4 *)(iVar2 + 0xa2c));
        if (lVar8 != 0) {
          asStack_100[uVar7 * 2] = 0x174;
          asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
          uVar7 = uVar7 + 1 & 0xffff;
          uVar4 = uVar4 + 1;
        }
        lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),1);
        if (lVar8 == 0) {
          lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),4);
          if (lVar8 == 0) {
            lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),8);
            if (lVar8 == 0) {
              lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x10);
              if (lVar8 == 0) {
                lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x20);
                if (lVar8 == 0) {
                  lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x40);
                  if (lVar8 != 0) {
                    asStack_100[uVar7 * 2] = 0x1c6;
                    asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
                    uVar7 = uVar7 + 1 & 0xffff;
                  }
                }
                else {
                  asStack_100[uVar7 * 2] = 0x1bd;
                  asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
                  uVar7 = uVar7 + 1 & 0xffff;
                }
              }
              else {
                asStack_100[uVar7 * 2] = 0x1ac;
                asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
                uVar7 = uVar7 + 1 & 0xffff;
              }
            }
            else {
              asStack_100[uVar7 * 2] = 0x1a3;
              asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
              uVar7 = uVar7 + 1 & 0xffff;
            }
          }
          else {
            asStack_100[uVar7 * 2] = 0x19a;
            asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
            uVar7 = uVar7 + 1 & 0xffff;
          }
        }
        else {
          asStack_100[uVar7 * 2] = 399;
          asStack_100[uVar7 * 2 + 1] = *(short *)(iVar2 + 0xa4);
          uVar7 = uVar7 + 1 & 0xffff;
        }
        if ((*(ushort *)(iVar2 + 0xa4) != 1) && (*(ushort *)(iVar2 + 0xa4) < 0xb)) {
          uVar9 = FUN_00174800(*(undefined2 *)(iVar2 + 0xa4));
          FUN_00175ca0(uVar9);
        }
        if ((*(short *)(iVar2 + 0xa4) == 1) && (lVar8 = FUN_0017b170(), lVar8 < 2)) {
          psVar13 = asStack_100 + uVar7 * 2;
          *psVar13 = -1;
          sVar11 = FUN_0016c920(*(undefined2 *)(iVar2 + 0xa4));
          if (sVar11 == 5) {
            *psVar13 = 0x188;
          }
          else if (sVar11 == 4) {
            *psVar13 = -1;
          }
          else if (sVar11 == 3) {
            *psVar13 = 0x187;
          }
          else if (sVar11 == 1) {
            *psVar13 = -1;
          }
          else if (sVar11 == 2) {
            *psVar13 = 0x186;
          }
          if (-1 < *psVar13) {
            asStack_100[uVar7 * 2 + 1] = -1;
            uVar7 = uVar7 + 1 & 0xffff;
          }
        }
        else if ((*(short *)(iVar2 + 0xa4) == 3) &&
                (lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x200), lVar8 != 0)) {
          asStack_100[uVar7 * 2] = 0x1b5;
          asStack_100[uVar7 * 2 + 1] = -1;
          uVar7 = uVar7 + 1 & 0xffff;
        }
      }
    }
    if (2 < uVar4) {
      asStack_100[uVar7 * 2] = 0x17d;
      asStack_100[uVar7 * 2 + 1] = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
      uVar3 = FUN_0016dd60(uVar4);
      if (((uVar3 != 0) && (uVar3 < 0xb)) && (FUN_00288fe0(0, uVar3) == NULL)) {
        uVar5 = 0;
        while ((uVar5 < 4 &&
               (((iVar2 = *(int *)(iGpffffb6fc + uVar5 * 4 + 0xbac), iVar2 == 0 ||
                 (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) || (*(ushort *)(iVar2 + 2) != uVar3)))))
        {
          uVar5 = uVar5 + 1 & 0xffff;
        }
        if (uVar5 == 4) {
          uVar5 = 0;
          while ((uVar5 < 3 &&
                 (((iVar2 = *(int *)(iGpffffb6fc + uVar5 * 8 + 0xbc4), iVar2 == 0 ||
                   (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) || (*(ushort *)(iVar2 + 2) != uVar3)))
                 )) {
            uVar5 = uVar5 + 1 & 0xffff;
          }
          if (uVar5 == 3) {
            uVar5 = FUN_0016c4f0(uVar3);
            uVar10 = FUN_0016c970(uVar3);
            if ((((uVar5 & 0xffff) != 0) && ((uVar10 & 0x80000) == 0)) &&
               (uVar6 = FUN_0016c5f0(uVar3), ((uVar5 & 0xffff) * 100) / (uVar6 & 0xffff) < 0x1f)) {
              switch(uVar3) {
              case 2:
                asStack_100[uVar7 * 2] = 0x17e;
                break;
              case 3:
                asStack_100[uVar7 * 2] = 0x17f;
                break;
              case 4:
                asStack_100[uVar7 * 2] = 0x180;
                break;
              case 5:
                asStack_100[uVar7 * 2] = 0x181;
                break;
              case 7:
                asStack_100[uVar7 * 2] = 0x182;
                break;
              case 8:
                asStack_100[uVar7 * 2] = 0x183;
                break;
              case 9:
                asStack_100[uVar7 * 2] = 0x184;
                break;
              case 10:
                asStack_100[uVar7 * 2] = 0x185;
              }
              asStack_100[uVar7 * 2 + 1] = -1;
              uVar7 = uVar7 + 1 & 0xffff;
            }
          }
        }
      }
    }
    bVar12 = false;
    for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
      if ((*(ushort *)(iGpffffb720 + (uint)*(ushort *)(iVar2 + 0xa4) * 0x3e) & 0x40) != 0) {
        bVar12 = true;
      }
    }
    if (bVar12) {
      asStack_100[uVar7 * 2] = 0x18d;
      asStack_100[uVar7 * 2 + 1] = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar4 = FUN_002d4e10(2,0x80000);
    uVar10 = (ulong)uVar4;
    if ((long)*(short *)(iGpffffb6fc + 0xa34) == uVar10) {
      if ((uVar10 < 5) && (uVar10 != 0)) {
        asStack_100[uVar7 * 2] = uVar4 + 0x188;
        asStack_100[uVar7 * 2 + 1] = -1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
    }
    else {
      *(ushort *)(iGpffffb6fc + 0xa34) = uVar4;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),10)
    ;
    if (lVar8 != 0) {
      asStack_100[uVar7 * 2] = 0x1b6;
      asStack_100[uVar7 * 2 + 1] = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),
                         0x80);
    if (lVar8 != 0) {
      asStack_100[uVar7 * 2] = 0x1b7;
      asStack_100[uVar7 * 2 + 1] = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),
                         0x220);
    if (lVar8 != 0) {
      asStack_100[uVar7 * 2] = 0x1b8;
      asStack_100[uVar7 * 2 + 1] = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar9 = FUN_00175360();
    uVar9 = FUN_00174a90(uVar9);
    lVar8 = FUN_002d5550();
    if ((lVar8 == 0x1ad) ||
       ((*(short *)((int)uVar9 + 2) != 0xbf &&
        (lVar8 = FUN_003005e0(*(undefined4 *)
                               (*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),0x261),
        lVar8 == 0)))) {
      FUN_00175ca0(uVar9);
    }
    if (uVar7 == 0) {
      sVar11 = -1;
    }
    else {
      uVar7 = FUN_002ffbc0(uVar7);
      sVar11 = asStack_100[(uVar7 & 0xffff) * 2];
      if ((long)*(int *)(iGpffffb6fc + 0xa30) == (long)sVar11) {
        sVar11 = -1;
      }
      else {
        *(int *)(iGpffffb6fc + 0xa30) = (int)sVar11;
        sVar1 = asStack_100[(uVar7 & 0xffff) * 2 + 1];
        if (-1 < sVar1) {
          if ((long)sVar11 == 399) {
            if (sVar1 == 1) {
              sVar11 = -1;
            }
            else {
              sVar11 = sVar11 + 2;
            }
          }
          switch(sVar1) {
          case 2:
            sVar11 = sVar11 + 1;
            break;
          case 3:
            sVar11 = sVar11 + 2;
            break;
          case 4:
            sVar11 = sVar11 + 3;
            break;
          case 5:
            sVar11 = sVar11 + 4;
            break;
          case 7:
            sVar11 = sVar11 + 5;
            break;
          case 8:
            sVar11 = sVar11 + 6;
            break;
          case 9:
            sVar11 = sVar11 + 7;
            break;
          case 10:
            sVar11 = sVar11 + 8;
          }
        }
      }
    }
  }
  else {
    sVar11 = -1;
  }
  return sVar11;
}

// FUN_002d2990
int FUN_002d2990(const float *param_1, const float *param_2, const float *param_3)
{
    float cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
                  (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);

    if (cross <= 0.0f)
    {
        goto nonpositive;
    }
    return 1;

nonpositive:
    return -(cross < 0.0f);
}

// FUN_002d2a00 NONMATCHING
int FUN_002d2a00(float param_1, float *param_2, float *param_3)
{
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        if (((param_2[0] <= *(float *)(node + 0x08)) ||
             (param_2[1] <= *(float *)(node + 0x0c)) ||
             (*(float *)(node + 0x268) <= param_2[0]) ||
             (*(float *)(node + 0x26c) <= param_2[1])) &&
            ((param_3[0] <= *(float *)(node + 0x08)) ||
             (param_3[1] <= *(float *)(node + 0x0c)) ||
             (*(float *)(node + 0x268) <= param_3[0]) ||
             (*(float *)(node + 0x26c) <= param_3[1])))
        {
            int i;
            for (i = 0; i < 4; ++i)
            {
                float *edge = (float *)(node + i * 0x130 + 0x08);
                float *next = (float *)(node + (((i + 1) & 3) * 0x130) + 0x08);
                int side_a = FUN_002d2990(edge, next, param_2);
                int side_b = FUN_002d2990(edge, next, param_3);

                if (side_a != side_b)
                {
                    side_a = FUN_002d2990(param_2, param_3, edge);
                    side_b = FUN_002d2990(param_2, param_3, next);
                    if (side_a != side_b)
                    {
                        return 1;
                    }
                }
                if (FUN_002d2470_call(param_1, param_2, param_3, edge) != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// FUN_002d2c10 NONMATCHING
int FUN_002d2c10(float *param_1, float *param_2)
{
    u8 *node;

    if (*(u8 **)((u8 *)param_2 + 0x10) == (u8 *)param_1)
    {
        return 1;
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        int i;
        for (i = 0; i < 4; ++i)
        {
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next = (float *)(node + (((i + 1) & 3) * 0x130) + 0x08);

            if ((edge != param_1) && (edge != param_2) && (next != param_1) && (next != param_2))
            {
                int side_a = FUN_002d2ee0(edge, next, param_1);
                int side_b = FUN_002d2ee0(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = FUN_002d2ee0(param_1, param_2, edge);
                    side_b = FUN_002d2ee0(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        return 1;
                    }
                }
            }
        }
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        int i;
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            float *edge = (float *)(record + 0x08);
            float *next = *(float **)(record + 0x18);

            if (edge == param_1)
            {
                return 0;
            }
            if ((0.0f < *(float *)(record + 0x1c)) && (next != NULL))
            {
                int side_a = FUN_002d2ee0(edge, next, param_1);
                int side_b = FUN_002d2ee0(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = FUN_002d2ee0(param_1, param_2, edge);
                    side_b = FUN_002d2ee0(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// FUN_002d2ee0
int FUN_002d2ee0(const float *param_1, const float *param_2, const float *param_3)
{
    int side;
    float cross;

    cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
            (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);
    if (cross >= 0.0f)
    {
        side = 1;
    }
    else
    {
        side = -(cross < 0.0f);
    }
    return side;
}

// FUN_002d2f50 NONMATCHING
u32 FUN_002d2f50(float param_1, u8 *param_2)
{
    u16 count = 0;
    u32 i;
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        u32 i;
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            float *point = (float *)(record + 0x08);

            if ((point != (float *)param_2) &&
                (0.0f < *(float *)(record + 0x1c)) &&
                (param_1 <= *(float *)(record + 0x20)) &&
                (FUN_002d25c0(param_2, point) == 0))
            {
                RwV2d delta;
                float *out;
                delta.x = *(float *)(param_2 + 0x08) - *(float *)(record + 0x10);
                delta.y = *(float *)(param_2 + 0x0c) - *(float *)(record + 0x14);
                out = (float *)(param_2 + 0xb0 + ((u32)count * 4));
                *out = btlTargetV2dLength(&delta);
                *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = (u8 *)point;
                count = (u16)(count + 1);
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        u8 *record = iGpffffb6fc + i * 0x130;
        float *point = (float *)(record + 0x2d0);

        if ((point != (float *)param_2) &&
            (0.0f < *(float *)(record + 0x2e4)) &&
            (FUN_002d25c0(param_2, point) == 0))
        {
            RwV2d delta;
            float *out;
            delta.x = *(float *)(param_2 + 0x08) - *(float *)(record + 0x2d8);
            delta.y = *(float *)(param_2 + 0x0c) - *(float *)(record + 0x2dc);
            out = (float *)(param_2 + 0xb0 + ((u32)count * 4));
            *out = btlTargetV2dLength(&delta);
            *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = (u8 *)point;
            count = (u16)(count + 1);
        }
    }

    if ((iGpffffb6fc + 0x790 != param_2) && (FUN_002d25c0(param_2, iGpffffb6fc + 0x790) == 0))
    {
        RwV2d delta;
        float *out;
        delta.x = *(float *)(param_2 + 0x08) - *(float *)(iGpffffb6fc + 0x798);
        delta.y = *(float *)(param_2 + 0x0c) - *(float *)(iGpffffb6fc + 0x79c);
        out = (float *)(param_2 + 0xb0 + ((u32)count * 4));
        *out = btlTargetV2dLength(&delta);
        *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = iGpffffb6fc + 0x790;
        count = (u16)(count + 1);
    }

    if ((iGpffffb6fc + 0x8c0 != param_2) && (FUN_002d25c0(param_2, iGpffffb6fc + 0x8c0) == 0))
    {
        RwV2d delta;
        float *out;
        delta.x = *(float *)(param_2 + 0x08) - *(float *)(iGpffffb6fc + 0x8c8);
        delta.y = *(float *)(param_2 + 0x0c) - *(float *)(iGpffffb6fc + 0x8cc);
        out = (float *)(param_2 + 0xb0 + ((u32)count * 4));
        *out = btlTargetV2dLength(&delta);
        *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = iGpffffb6fc + 0x8c0;
        count = (u16)(count + 1);
    }

    *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = NULL;
    return count;
}

// FUN_002d32b0 NONMATCHING
void FUN_002d32b0(float param_1)
{
    u8* other;
    int j;
    int haveBounds = 0;
    s16 corner0X;
    s16 corner0Y;
    s16 corner1X;
    s16 corner1Y;
    s16 corner2X;
    s16 corner2Y;
    s16 corner3X;
    s16 corner3Y;
    float extent[4];
    int i;
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        if (haveBounds == 0)
        {
            s16 tileX = *(s16 *)(node + 0x00);
            s16 tileY = *(s16 *)(node + 0x02);
            float z = *(float *)(node + 0x04);
            corner3X = tileX;
            corner2X = tileX;
            corner1X = tileX;
            corner0X = tileX;
            corner3Y = tileY;
            corner2Y = tileY;
            corner1Y = tileY;
            corner0Y = tileY;
            extent[3] = z;
            extent[2] = z;
            extent[1] = z;
            extent[0] = z;
            haveBounds = 1;
        }
        else
        {
            s16 tileX = *(s16 *)(node + 0x00);
            s16 tileY = *(s16 *)(node + 0x02);
            float z = *(float *)(node + 0x04);
            if ((tileX <= corner0X) && (tileY <= corner0Y))
            {
                corner0X = tileX;
                corner0Y = tileY;
                extent[0] = z;
            }
            if ((corner1X <= tileX) && (tileY <= corner1Y))
            {
                corner1X = tileX;
                corner1Y = tileY;
                extent[1] = z;
            }
            if ((corner2X <= tileX) && (corner2Y <= tileY))
            {
                corner2X = tileX;
                corner2Y = tileY;
                extent[2] = z;
            }
            if ((tileX <= corner3X) && (corner3Y <= tileY))
            {
                corner3X = tileX;
                corner3Y = tileY;
                extent[3] = z;
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        s32 whole = (s32)(extent[i] + 500.0f);
        s16 margin = (s16)(whole / 0x19);
        s16 x;
        s16 y;

        if ((whole % 0x19) != 0)
        {
            margin = (s16)(margin + 1);
        }

        if (i == 3)
        {
            x = (s16)(corner3X - margin);
            y = (s16)(margin + corner3Y);
            if (x < 0)
            {
                x = 0;
            }
        }
        else if (i == 2)
        {
            x = (s16)(margin + corner2X);
            y = (s16)(margin + corner2Y);
        }
        else if (i == 1)
        {
            x = (s16)(margin + corner1X);
            y = (s16)(corner1Y - margin);
            if (y < 0)
            {
                y = 0;
            }
        }
        else
        {
            x = (s16)(corner0X - margin);
            y = (s16)(corner0Y - margin);
            if (x < 0)
            {
                x = 0;
            }
            if (y < 0)
            {
                y = 0;
            }
        }

        *(float *)(iGpffffb6fc + i * 0x130 + 0x2d0) = (float)((s32)x * 0x19 - 0x6d6);
        *(float *)(iGpffffb6fc + i * 0x130 + 0x2d4) = (float)((s32)y * 0x19 - 0x6d6);
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            float *point = (float *)(record + 0x08);
            float bestDistance = 7000.0f;
            float candidateX = 0.0f;
            float candidateY = 0.0f;
            float candidateZ = 0.0f;
            RwV2d bestDirection;
            u8 *bestPoint = NULL;

            for (other = *(u8 **)(iGpffffb6fc + 0x2cc); other != NULL; other = *(u8 **)(other + 0x4cc))
            {
                if (node != other)
                {
                    for (j = 0; j < 4; ++j)
                    {
                        float *candidate = (float *)(other + j * 0x130 + 0x08);
                        RwV2d delta;
                        RwV2d direction;
                        float distance;

                        delta.x = candidate[0] - point[0];
                        delta.y = candidate[1] - point[1];
                        distance = FUN_004C6B20(&direction, &delta);
                        if ((fGpffff827c < direction.x * DAT_006978c0[i * 2] +
                                           direction.y * DAT_006978c0[i * 2 + 1]) &&
                            (distance < bestDistance) &&
                            (FUN_002d2c10(point, candidate) == 0))
                        {
                            bestDirection.x = direction.x;
                            bestDirection.y = direction.y;
                            candidateX = (float)((s32)*(s16 *)(other + 0x00) * 0x19 - 0x6d6);
                            candidateY = (float)((s32)*(s16 *)(other + 0x02) * 0x19 - 0x6d6);
                            candidateZ = *(float *)(other + 0x04);
                            bestDistance = distance;
                            bestPoint = (u8 *)candidate;
                        }
                    }
                }
            }

            for (j = 0; j < 4; ++j)
            {
                u8 *playerRecord = iGpffffb6fc + j * 0x130;
                float *candidate = (float *)(playerRecord + 0x2d0);
                RwV2d delta;
                RwV2d direction;
                float distance;

                delta.x = candidate[0] - point[0];
                delta.y = candidate[1] - point[1];
                distance = FUN_004C6B20(&direction, &delta);
                if ((fGpffff827c < direction.x * DAT_006978c0[i * 2] +
                                   direction.y * DAT_006978c0[i * 2 + 1]) &&
                    (distance < bestDistance) &&
                    (FUN_002d2c10(point, candidate) == 0))
                {
                    bestDirection.x = direction.x;
                    bestDirection.y = direction.y;
                    bestPoint = (u8 *)candidate;
                    candidateX = candidate[0];
                    candidateY = candidate[1];
                    candidateZ = 0.0f;
                    bestDistance = distance;
                }
            }

            if (bestPoint == NULL)
            {
                *(float *)(record + 0x1c) = -1.0f;
            }
            else
            {
                *(float *)(record + 0x10) = point[0] + bestDirection.x * bestDistance * 0.5f;
                *(float *)(record + 0x14) = point[1] + bestDirection.y * bestDistance * 0.5f;
                *(u8 **)(record + 0x18) = bestPoint;
                *(float *)(record + 0x1c) = bestDistance;

                {
                    RwV2d centerDelta;
                    float centerDistance;
                    centerDelta.x = (float)((s32)*(s16 *)node * 0x19 - 0x6d6) - candidateX;
                    centerDelta.y = (float)((s32)*(s16 *)(node + 0x02) * 0x19 - 0x6d6) - candidateY;
                    centerDistance = btlTargetV2dLength(&centerDelta);
                    *(float *)(record + 0x20) = centerDistance - (*(float *)(node + 0x04) + candidateZ);
                }
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        u8 *playerRecord = iGpffffb6fc + i * 0x130;
        float *start = (float *)(playerRecord + 0x2d0);
        float bestDistance = 7000.0f;
        float *bestPoint = NULL;
        RwV2d bestDirection;

        for (other = *(u8 **)(iGpffffb6fc + 0x2cc); other != NULL; other = *(u8 **)(other + 0x4cc))
        {
            for (j = 0; j < 4; ++j)
            {
                float *candidate = (float *)(other + j * 0x130 + 0x08);
                RwV2d delta;
                float distance;

                delta.x = candidate[0] - start[0];
                delta.y = candidate[1] - start[1];
                distance = btlTargetV2dLength(&delta);
                if (distance < bestDistance)
                {
                    FUN_004C6B20(&bestDirection, &delta);
                    bestPoint = candidate;
                    bestDistance = distance;
                }
            }
        }

        if ((bestPoint == NULL) ||
            (*(float **)((u8 *)bestPoint + 0x10) == (float *)(playerRecord + 0x2d0)))
        {
            *(float *)(playerRecord + 0x2e4) = -1.0f;
        }
        else
        {
            *(float *)(playerRecord + 0x2d8) = start[0] + bestDirection.x * bestDistance * 0.5f;
            *(float *)(playerRecord + 0x2dc) = start[1] + bestDirection.y * bestDistance * 0.5f;
            *(float **)(playerRecord + 0x2e0) = bestPoint;
            *(float *)(playerRecord + 0x2e4) = bestDistance;
            *(float *)(playerRecord + 0x2e8) = 500.0f;
        }
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            if ((*(float *)(record + 0x1c) <= 0.0f) ||
                (*(float *)(record + 0x20) < param_1))
            {
                *(u32 *)(record + 0x38) = 0;
            }
            else
            {
                FUN_002d2f50(param_1, record + 0x08);
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        u8 *playerRecord = iGpffffb6fc + i * 0x130;
        if (0.0f < *(float *)(playerRecord + 0x2e4))
        {
            FUN_002d2f50(param_1, playerRecord + 0x2d0);
        }
        else
        {
            *(u32 *)(playerRecord + 0x300) = 0;
        }
    }

    FUN_002d2f50(param_1, iGpffffb6fc + 0x790);
    FUN_002d2f50(param_1, iGpffffb6fc + 0x8c0);
}

/* Caveats:
 * - iGpffffb6fc, fGpffff827c, and DAT_006978c0 are raw retail globals; no stable named API was established.
 * - FUN_002d2470, FUN_002d25c0, and FUN_004C6B20 are raw helper declarations; FUN_004C6B20 is the retail 2-D normalize helper.
 */
// FUN_002d3d70
void FUN_002d3d70(void)
{
    *(u32*)(iGpffffb6fc + 0x2cc) = 0;
    *(f32*)(iGpffffb6fc + 0x7a4) = -1.0f;
    *(f32*)(iGpffffb6fc + 0x8d4) = -1.0f;
    *(f32*)(iGpffffb6fc + 0x2d0) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x2d4) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x400) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x404) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x530) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x534) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x660) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x664) = 1750.0f;
}

// FUN_002d3e00 NONMATCHING
void FUN_002d3e00(BtlUnit* unit, RwV3d* outPos)
{
    RwV3d center;
    f32 radius;
    s32 x;
    s32 z;
    s16 tileX;
    s16 tileZ;
    u8* raw = (u8*)unit;
    u8* head;

    btlUnitGetSphereWorldCenter(unit, &center);
    radius = unit->sphereRadius * unit->scale;
    x = (s32)(center.x + 1750.0f);
    z = (s32)(center.z + 1750.0f);
    tileX = (s16)(x / 0x19);
    tileZ = (s16)(z / 0x19);
    if (x % 0x19 >= 0x0d) tileX++;
    if (z % 0x19 >= 0x0d) tileZ++;

    if (outPos != NULL)
    {
        outPos->x = (f32)((s32)tileX * 0x19 - 0x6d6);
        outPos->y = 0.0f;
        outPos->z = (f32)((s32)tileZ * 0x19 - 0x6d6);
    }
    FUN_002d2340_s16(radius, raw, tileX, tileZ);
    *(s16*)(raw + 0x4fc) = tileX;
    *(s16*)(raw + 0x4fe) = tileZ;
    *(f32*)(raw + 0x500) = radius;
    *(u32*)(raw + 0x9c4) = 0;

    head = *(u8**)(iGpffffb6fc + 0x2cc);
    *(u8**)(raw + 0x9c8) = head;
    if (head != NULL)
    {
        *(u8**)(head + 0x4c8) = raw + 0x4fc;
    }
    *(u8**)(iGpffffb6fc + 0x2cc) = raw + 0x4fc;
    unit->flags3 |= 4;
}

// FUN_002d3fe0
void FUN_002d3fe0(BtlUnit* unit)
{
    u8* raw = (u8*)unit;
    u8* next;
    u8* prev;

    if ((unit->flags3 & 4) == 0)
    {
        return;
    }
    unit->flags3 &= ~4u;
    next = *(u8**)(raw + 0x9c8);
    if (next != NULL)
    {
        *(u8**)(next + 0x4c8) = *(u8**)(raw + 0x9c4);
    }
    prev = *(u8**)(raw + 0x9c4);
    if (prev != NULL)
    {
        *(u8**)(prev + 0x4cc) = *(u8**)(raw + 0x9c8);
    }
    else
    {
        *(u8**)(iGpffffb6fc + 0x2cc) = *(u8**)(raw + 0x9c8);
    }
}

// FUN_002d4040 NONMATCHING
u32 FUN_002d4040(BtlUnit* unit)
{
    RwV3d center;
    f32 radius;
    s32 x;
    s32 z;
    s16 tileX;
    s16 tileZ;
    u8* raw = (u8*)unit;

    if ((unit->flags3 & 4) == 0)
    {
        return 0;
    }
    btlUnitGetSphereWorldCenter(unit, &center);
    radius = unit->sphereRadius * unit->scale;
    x = (s32)(center.x + 1750.0f);
    z = (s32)(center.z + 1750.0f);
    tileX = (s16)(x / 0x19);
    tileZ = (s16)(z / 0x19);
    if (x % 0x19 >= 0x0d) tileX++;
    if (z % 0x19 >= 0x0d) tileZ++;
    if (*(s16*)(raw + 0x4fc) == tileX &&
        *(s16*)(raw + 0x4fe) == tileZ &&
        *(f32*)(raw + 0x500) == radius)
    {
        return 0;
    }
    FUN_002d2340_s16(radius, raw, tileX, tileZ);
    *(s16*)(raw + 0x4fc) = tileX;
    *(s16*)(raw + 0x4fe) = tileZ;
    *(f32*)(raw + 0x500) = radius;
    return 1;
}

// FUN_002d41c0 NONMATCHING
u32 FUN_002d41c0(RwV2d* output, f32 radius)
{
    RwV2d points[128];
    RwV2d previousDelta;
    RwV2d currentDelta;
    RwV2d previousUnit;
    RwV2d currentUnit;
    RwV2d p0;
    RwV2d p1;
    RwV2d p2;
    RwV2d p3;
    u8* node;
    u8* chosen;
    u16 count;
    u16 i;
    f32 previousLength;
    f32 currentLength;
    f32 halfRadius;
    f32 dot;

    count = 0;
    halfRadius = radius * 0.5f;
    if (FUN_002d2a00(halfRadius,
                     (f32*)(iGpffffb6fc + 0x798),
                     (f32*)(iGpffffb6fc + 0x8c8)) == 0)
    {
        points[0].x = *(f32*)(iGpffffb6fc + 0x8c8);
        points[0].y = *(f32*)(iGpffffb6fc + 0x8cc);
        points[1].x = *(f32*)(iGpffffb6fc + 0x798);
        points[1].y = *(f32*)(iGpffffb6fc + 0x79c);
        count = 2;
    }
    else
    {
        node = iGpffffb6fc + 0x8c0;
        while (node != NULL)
        {
            chosen = node;
            if (count > 0)
            {
                while (node != NULL)
                {
                    if (FUN_002d2a00(halfRadius,
                                     (f32*)&points[count - 1],
                                     (f32*)(node + 8)) != 0)
                    {
                        break;
                    }
                    chosen = node;
                    node = *(u8**)(node + 0x2c);
                }
            }
            points[count].x = *(f32*)(chosen + 8);
            points[count].y = *(f32*)(chosen + 0xc);
            if (count >= 2)
            {
                previousDelta.x = points[count - 1].x -
                                  points[count - 2].x;
                previousDelta.y = points[count - 1].y -
                                  points[count - 2].y;
                currentDelta.x = points[count].x -
                                 points[count - 1].x;
                currentDelta.y = points[count].y -
                                 points[count - 1].y;
                dot = previousDelta.x * currentDelta.x +
                      previousDelta.y * currentDelta.y;
                if (dot > 0.0f)
                {
                    previousLength =
                        FUN_004C6B20(&previousUnit, &previousDelta);
                    currentLength =
                        FUN_004C6B20(&currentUnit, &currentDelta);
                    if (previousLength < 250.0f &&
                        currentLength < 250.0f)
                    {
                        count--;
                        node = chosen;
                        continue;
                    }
                    points[count - 1].x =
                        points[count - 2].x +
                        currentUnit.x * currentLength * 0.65f;
                    points[count - 1].y =
                        points[count - 2].y +
                        currentUnit.y * currentLength * 0.65f;
                }
            }
            count++;
            node = *(u8**)(chosen + 0x2c);
            if (count >= 0x7f)
                break;
        }
    }

    if (count < 2)
    {
        *(u16*)((u8*)output + 0x400) = 0;
        return 0;
    }
    if (count < 3)
    {
        output[0] = points[1];
        output[1] = points[0];
        *(u16*)((u8*)output + 0x400) = 2;
        return 1;
    }

    i = 0;
    while (count - 1 > 0)
    {
        u16 index = count - 1;
        if ((u16)(index + 1) < count)
            p0 = points[index + 1];
        else
            p0 = points[count - 1];
        p1 = points[index];
        if (index == 0)
            p2 = points[0];
        else
            p2 = points[index - 1];
        if (index < count - 1)
            p3 = points[index + 1];
        else
            p3 = points[count - 1];

        output[i] = p1;
        output[i + 1].x = 0.8671875f * p1.x -
                          0.0703125f * p0.x +
                          0.226563f * p2.x -
                          0.0234375f * p3.x;
        output[i + 1].y = 0.8671875f * p1.y -
                          0.0703125f * p0.y +
                          0.226563f * p2.y -
                          0.0234375f * p3.y;
        output[i + 2].x = -0.0625f * p1.x +
                          0.5625f * p0.x +
                          0.5625f * p2.x -
                          0.0625f * p3.x;
        output[i + 2].y = -0.0625f * p1.y +
                          0.5625f * p0.y +
                          0.5625f * p2.y -
                          0.0625f * p3.y;
        output[i + 3].x = 0.226563f * p1.x -
                          0.0234375f * p0.x +
                          0.8671875f * p2.x -
                          0.0703125f * p3.x;
        output[i + 3].y = 0.226563f * p1.y -
                          0.0234375f * p0.y +
                          0.8671875f * p2.y -
                          0.0703125f * p3.y;
        i += 4;
        count--;
    }
    output[i] = points[0];
    *(u16*)((u8*)output + 0x400) = i + 1;
    return 1;
}

// FUN_002d4800
void FUN_002d4800(void* work)
{
    *(u16*)((u8*)work + 0x400) = 0;
    *(u16*)((u8*)work + 0x402) = 0;
}

// FUN_002d4810
void* FUN_002d4810(void)
{
    f32 bestDistance = 350000.0f;
    u8* node;
    u8* current;
    u8* best;
    u8* prev;
    u8** head = (u8**)(iGpffffb6fc + 0x9f0);

    current = *head;
    node = current;
    while (node != NULL)
    {
        f32 distance = *(f32*)(node + 0x20);
        if (bestDistance > distance)
        {
            best = node;
            bestDistance = distance;
        }
        node = *(u8**)(node + 0x24);
    }

    prev = NULL;
    while (current != NULL)
    {
        if (current == best)
        {
            break;
        }
        prev = current;
        current = *(u8**)(current + 0x24);
    }
    if (current != NULL)
    {
        if (prev != NULL)
        {
            *(u8**)(prev + 0x24) = *(u8**)(current + 0x24);
        }
        else
        {
            *head = *(u8**)(current + 0x24);
        }
    }
    return best;
}

// FUN_002d48c0 NONMATCHING
u32 FUN_002d48c0(void* work, const RwV2d* start, const RwV2d* end, f32 radius)
{
    u8* selected;
    u8* current;
    u8* previous;
    u8* record;
    u8* slot;
    u16 index;
    u32 inFirst;
    u32 inSecond;
    u32 result;
    f32 score;
    RwV2d delta;

    *(u8*)((u8*)work + 0x404) = 1;
    if (FUN_002d2a00(radius * 0.5f, (f32*)start, (f32*)end) == 0)
    {
        *(f32*)((u8*)work + 0x00) = start->x;
        *(f32*)((u8*)work + 0x04) = start->y;
        *(f32*)((u8*)work + 0x08) = end->x;
        *(f32*)((u8*)work + 0x0c) = end->y;
        *(u16*)((u8*)work + 0x400) = 2;
        *(u8*)((u8*)work + 0x404) = 2;
        return 1;
    }

    *(f32*)(iGpffffb6fc + 0x798) = start->x;
    *(f32*)(iGpffffb6fc + 0x79c) = start->y;
    *(f32*)(iGpffffb6fc + 0x8c8) = end->x;
    *(f32*)(iGpffffb6fc + 0x8cc) = end->y;
    FUN_002d32b0(radius);
    if (*(u32*)(iGpffffb6fc + 0x7c0) == 0 ||
        *(u32*)(iGpffffb6fc + 0x8f0) == 0)
    {
        *(u8*)((u8*)work + 0x404) = 3;
        return 0;
    }

    *(u32*)(iGpffffb6fc + 0x9f0) = 0;
    *(u32*)(iGpffffb6fc + 0x9f4) = 0;
    *(u32*)(iGpffffb6fc + 0x7ac) = 0;
    delta.x = *(f32*)(iGpffffb6fc + 0x798) -
              *(f32*)(iGpffffb6fc + 0x8c8);
    delta.y = *(f32*)(iGpffffb6fc + 0x79c) -
              *(f32*)(iGpffffb6fc + 0x8cc);
    *(f32*)(iGpffffb6fc + 0x7b0) = FUN_004c6af0((f32*)&delta);
    *(u32*)(iGpffffb6fc + 0x7bc) = 0;
    *(u32*)(iGpffffb6fc + 0x7b4) = *(u32*)(iGpffffb6fc + 0x9f0);
    *(u32*)(iGpffffb6fc + 0x9f0) = (u32)(iGpffffb6fc + 0x790);

    result = 0;
    for (;;)
    {
        selected = (u8*)FUN_002d4810();
        if (selected == iGpffffb6fc + 0x8c0)
        {
            result = 1;
            break;
        }

        index = 0;
        while (*(u8**)(selected + 0x30 + index * 4) != NULL)
        {
            score = *(f32*)(selected + 0x1c) +
                    *(f32*)(selected + 0xb0 + index * 4);
            inFirst = 0;
            for (current = *(u8**)(iGpffffb6fc + 0x9f0);
                 current != NULL;
                 current = *(u8**)(current + 0x24))
            {
                if (current == iGpffffb6fc)
                {
                    inFirst = 1;
                    break;
                }
            }
            inSecond = 0;
            for (current = *(u8**)(iGpffffb6fc + 0x9f4);
                 current != NULL;
                 current = *(u8**)(current + 0x28))
            {
                if (current == iGpffffb6fc)
                {
                    inSecond = 1;
                    break;
                }
            }
            if ((inFirst == 0 && inSecond == 0) ||
                *(f32*)(selected + 0x1c) > score)
            {
                slot = selected + 0x30 + index * 4;
                record = *(u8**)slot;
                *(f32*)(selected + 0x1c) = score;
                delta.x = *(f32*)(record + 0x08) -
                          *(f32*)(iGpffffb6fc + 0x8c8);
                delta.y = *(f32*)(record + 0x0c) -
                          *(f32*)(iGpffffb6fc + 0x8cc);
                *(f32*)(record + 0x20) +=
                    FUN_004c6af0((f32*)&delta);
                *(u8**)(record + 0x2c) = selected;
                if (inSecond != 0)
                {
                    previous = NULL;
                    current = *(u8**)(iGpffffb6fc + 0x9f4);
                    while (current != record)
                    {
                        previous = current;
                        current = *(u8**)(current + 0x28);
                    }
                    if (previous != NULL)
                        *(u8**)(previous + 0x28) =
                            *(u8**)(current + 0x28);
                    else
                        *(u8**)(iGpffffb6fc + 0x9f4) =
                            *(u8**)(current + 0x28);
                }
                if (inFirst == 0)
                {
                    *(u8**)(record + 0x24) =
                        *(u8**)(iGpffffb6fc + 0x9f0);
                    *(u8**)(iGpffffb6fc + 0x9f0) = record;
                }
            }
            index++;
        }
        if (*(u8**)(selected + 0x30 + index * 4) == NULL)
        {
            *(u8**)(selected + 0x28) =
                *(u8**)(iGpffffb6fc + 0x9f4);
            *(u8**)(iGpffffb6fc + 0x9f4) = selected;
        }
        if (*(u8**)(iGpffffb6fc + 0x9f0) == NULL)
            break;
    }
    if (result != 0)
    {
        *(u8*)((u8*)work + 0x404) = 2;
    }
    else
    {
        *(u8*)((u8*)work + 0x404) = 3;
    }
    return result;
}

// FUN_002d4cc0
u32 FUN_002d4cc0(u16 index)
{
    u32 value = *((u8*)iGpffffb6fc + index * 0x1c);

    if (value == 0)
    {
        return 1;
    }
    return value;
}

// FUN_002d4cf0
u16 FUN_002d4cf0(u16 mask, u32 badStatus)
{
    u8* node;
    u32 total;
    u16 count;
    u32 targetMask;
    u16 average;

    total = 0;
    count = 0;
    node = *(u8**)(iGpffffb6fc + 0x14c);
    targetMask = mask;
    for (; node != NULL;
         node = *(u8**)(node + 0x4a8))
    {
        BtlUnit* unit;

        if ((*(u16*)(node + 0x1a) & 1) == 0)
        {
            continue;
        }
        unit = *(BtlUnit**)(node + 0x30);
        if ((targetMask & (1u << unit->genus)) == 0)
        {
            continue;
        }
        if (badStatus != 0 &&
            datCalcChkBadStatus(unit->datUnit, badStatus) != 0)
        {
            continue;
        }
        total = (u16)(total + datCalcGetLevel(unit->datUnit));
        count++;
    }
    if (count == 0)
    {
        return 1;
    }
    average = (u16)((s32)(u16)total / (s32)(u16)count);
    if (average == 0)
    {
        return 1;
    }
    return average;
}

// FUN_002d4e10
u16 FUN_002d4e10(u16 mask, u32 badStatus)
{
    u32 status;
    u8* node;
    u16 count;
    u32 targetMask;

    status = badStatus;
    count = 0;
    node = *(u8**)(iGpffffb6fc + 0x14c);
    targetMask = mask;
    for (; node != NULL;
         node = *(u8**)(node + 0x4a8))
    {
        BtlUnit* unit;
        u16 flags = *(u16*)(node + 0x1a);

        if ((flags & 1) == 0)
        {
            continue;
        }
        if ((flags & 8) == 0)
        {
            continue;
        }
        unit = *(BtlUnit**)(node + 0x30);
        if ((targetMask & (1u << unit->genus)) == 0)
        {
            continue;
        }
        if (datCalcChkBadStatus(unit->datUnit, status) != 0)
        {
            continue;
        }
        count++;
    }
    return count;
}

// FUN_002d5b50
s32 FUN_002d5b50(s32 param_1)
{
    s32 result;

    if (param_1 == 0x14b) goto return_13;
    if (param_1 == 0x14a) goto return_12;
    if (param_1 == 0x149) goto return_12;
    if (param_1 == 0x148) goto return_12;

    switch (param_1)
    {
    case 0x147:
        goto return_12;
    default:
        goto return_default;
    }

return_12:
    result = 0xc;
    goto end;
return_13:
    result = 0xd;
    goto end;
return_default:
    result = -1;
    goto end;
end:
    return result;
}

// FUN_002d5bc0
s32 FUN_002d5bc0(void)
{
    return (s32)datCalcRand(5) + 0x147;
}

// FUN_002d5bf0
u32 FUN_002d5bf0(BtlUnit* unit)
{
    if (datGetScenarioMode() == 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }
    if (unit->datUnit->id != 1)
    {
        return 0;
    }
    return unit->genus == 0;
}

// FUN_002d5c70
u32 FUN_002d5c70(BtlUnit* unit)
{
    if (datGetScenarioMode() == 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }
    if (unit->datUnit->id != 9)
    {
        return 0;
    }
    return unit->genus == 0;
}

// FUN_002d5cf0
u32 FUN_002d5cf0(BtlUnit* unit)
{
    s16 equipmentIdx;
    u16 equipmentType;
    s16 equipmentId;

    if (unit->genus != 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }

    equipmentType = unit->datUnit->id;
    switch (equipmentType)
    {
        case 2:
        case 4:
            break;
        default:
            goto return_zero;
    }

    equipmentIdx = datGetEquipmentIdx((s16)equipmentType, 1);
    equipmentId =
        datGetEquipmentId((s16)unit->datUnit->id, equipmentIdx);
    if (equipmentId != 0x41e)
    {
        goto return_zero;
    }
    return 1;

return_zero:
    return 0;
}

// FUN_002d5dc0
void FUN_002d5dc0(void* param_1)
{
    memset(param_1, 0, 0x1c);
    ((s8*)param_1)[0x19] = -1;
}

// FUN_002d5e00
void FUN_002d5e00(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x14) = 0;
}

#pragma opt_loop_invariants on
// FUN_002d5e10
u32 FUN_002d5e10(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u16*)(result + 0xfa) & 4) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002d5eb0
u32 FUN_002d5eb0(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    u32 statusMask;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    statusMask = 0x100000;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u32*)(result + 0xe8) & statusMask) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002d5f50
u32 FUN_002d5f50(BtlAction* action)
{
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;

    while ((u16)targetIndex < targetCount)
    {
        BtlAction* target = action->target.targetedActions[(u16)targetIndex];
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 1;
        }
        targetIndex = (u16)(targetIndex + 1);
    }
    return 0;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002d5fb0
s32 FUN_002d5fb0(BtlAction* action)
{
    BtlAction* target;
    s32 resultCount;
    s32 resultIndex;
    s32 result = 0;
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;
    s32 one = 1;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        if (target != action)
        {
            if (action->unit->genus != target->unit->genus)
            {
                return 0;
            }
            if (result == 0)
            {
                resultIndex = 0;
                resultCount = *(u8*)((u8*)target + 0xc8);
                for (; (u16)resultIndex < resultCount;
                     resultIndex = (u16)(resultIndex + 1))
                {
                    u8* resultData =
                        (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
                    if (*(s32*)(resultData + 0xe0) > 0)
                    {
                        result = one;
                    }
                    if (*(s32*)(resultData + 0xec) != 0)
                    {
                        result = one;
                    }
                }
            }
        }
    }
    return result;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002d6090
u32 FUN_002d6090(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    u32 statusMask;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    statusMask = 0x80000;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u32*)(result + 0xec) & statusMask) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002d6130
s32 FUN_002d6130(BtlAction* action)
{
    BtlAction* target;
    s32 resultCount;
    s32 resultIndex;
    s32 result = 0;
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;
    s32 one = 1;

    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 0;
        }
        if ((*(u16*)((u8*)target + 0xcc) & 0x500) != 0)
        {
            return 0;
        }
        if (result == 0)
        {
            resultCount = *(u8*)((u8*)target + 0xc8);
            resultIndex = 0;
            for (; (u16)resultIndex < resultCount;
                 resultIndex = (u16)(resultIndex + 1))
            {
                u8* resultData =
                    (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
                if (*(s32*)(resultData + 0xe0) < 0)
                {
                    result = one;
                    break;
                }
            }
        }
    }
    return result;
}
#pragma opt_loop_invariants off

// FUN_002d6210
u32 FUN_002d6210(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(BtlAction **)((u8 *)action + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 1;
        }
        if ((*(u16*)((u8*)target + 0xcc) & 0x500) != 0)
        {
            return 1;
        }
    }
    return 0;
}

// FUN_002d6290
u32 FUN_002d6290(BtlAction* action)
{
    s16 specificId = action->target.specificId;
    return FUN_002bff60(action, NULL, specificId, 0) == 0;
}

// FUN_002d62d0
u32 FUN_002d62d0(BtlAction* action)
{
    s32 genus = action->unit->genus;
    s32 targetCount = action->target.targetedCount;
    s32 targetIndex;

    if (targetCount < 2)
    {
        return 0;
    }

    targetIndex = 0;
    genus = (u8)genus;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        BtlAction* target = *(BtlAction **)((u8 *)action + 0x38 + (u32)(u16)targetIndex * 4);
        if ((target->unk_1a & 1) != 0 && target->unit->genus != genus)
        {
            return 0;
        }
    }
    return 1;
}

// FUN_002d6370
u32 FUN_002d6370(u16 commandId)
{
    u8* units = (u8*)DAT_007ce3f8;
    s32 id = (s32)(s16)commandId;
    return units[id * 0x2c + 2] == 1;
}

// FUN_002d63b0
u32 FUN_002d63b0(BtlUnit* unit, s16 commandId, s32 param_3)
{
    u8* commandTable = (u8*)DAT_007ce3f8;
    s32 id = (s32)commandId;
    u8 commandType;
    s32 result;

    commandType = commandTable[id * 0x2c + 2];
    if (commandType != 1)
    {
        result = 0;
    }
    else
    {
        result = 1;
        if (param_3 == 0 ||
            ((*(u16*)(DAT_007ce42c + (u32)unit->charId * 0x58) & 0x10) != 0) ||
            ((iGpffffb710[id].flags & 1) == 0))
        {
            result = 0;
        }
    }
    return result;
}
// FUN_002d6460 NONMATCHING
s32 FUN_002d6460(BtlAction* action, s32* param_2, u32 param_3,
                 u64 param_4, s32 param_5)
{
    s32 result = -1;
    u32 flags = (u32)param_2[2];
    u32 mode;

    if (flags != 0 || ((u32)param_2[4] & 0x3c02aaU) != 0)
    {
        result = -2;
    }

    if ((flags & 0x100000U) != 0)
    {
        result = 8;
    }
    else if (param_2[0] < 0 || (flags & 0x80000U) != 0)
    {
        result = 2;
    }
    else if (((u32)param_2[3] & 0x100000U) != 0)
    {
        result = 10;
    }
    mode = param_3 & 0xffff;

    if (mode == 2 || mode == 4)
    {
        result = (action->unit->flags3 & 0x80U) != 0 ? 0x16 : -4;
    }
    if ((*(u16*)((u8*)param_2 + 0x1a) & 4) != 0)
    {
        result = (action->unit->flags3 & 0x80U) != 0 ? 0x16 : -3;
    }
    if (param_5 != 0)
    {
        result = (action->unit->flags3 & 0x20U) != 0 ? 0x12 : 2;
    }
    if ((((u32)param_2[3] & 0x80000U) != 0) &&
        datCalcChkBadStatus(action->unit->datUnit, UNIT_BADSTATUS_DEAD) != 0 &&
        (action->unit->flags3 & 0x200U) != 0)
    {
        result = 0x13;
    }
    return result;
}

// FUN_002d6620 NONMATCHING
void FUN_002d6620(BtlAction *action)
{
    BtlUnit *unit;
    DatUnit *selfDat;
    u16 specificId;
    u64 mappedId;
    u32 id;
    u32 tableOffset;
    u8 attackType;
    u8 datType;
    u32 specialFlags;
    u16 inherited = 0;
    u16 successfulTargets = 0;
    u8 finalFlags = 0;
    u16 targetIndex;

    unit = action->unit;
    selfDat = unit->datUnit;
    specificId = action->target.specificId;
    *(u16 *)((u8 *)action + 0x72) = action->target.specificId;
    mappedId = (u64)FUN_002d5570(specificId);
    if (mappedId != -1)
    {
        id = (u32)mappedId & 0xffff;
        action->target.specificId = (u16)mappedId;
        FUN_002c3770(action, 0);
    }
    else
    {
        id = specificId;
    }

    specialFlags = (action->target.commandId == 3) ? 1 : 0;
    if ((action->target.commandId == 3) && (action->target.unk_38 != 0))
        specialFlags = 1;

    tableOffset = id * 0x2c;
    attackType = BTLT_T8(tableOffset, 0x11);
    *(u16 *)((u8 *)selfDat + 0x38) = 0;
    datType = (u8)FUN_003082f0(selfDat, id);

    BTLT_A8(action, 0xc8) = 0;
    BTLT_A16(action, 0xcc) = 0;
    BTLT_A32(action, 0xd0) = 0;
    BTLT_A32(action, 0xd4) = 0;
    BTLT_A8(action, 0xca) = 0;
    BTLT_A8(action, 0xc9) = 0;
    BTLT_A32(action, 0xd8) = 0;
    BTLT_A16(action, 0xdc) = 0;
    BTLT_AS16(action, 0xde) = -1;

    if ((specialFlags == 0) && ((u64)FUN_003088b0(id) == 0))
    {
        u64 tacticResult = (u64)FUN_003086f0(selfDat, id);
        if (tacticResult == 2)
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = unit->genus == 0 ? 0x3c : 0x3d;
        }
        else if (tacticResult == 1)
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = unit->genus == 0 ? 0x3a : 0x3b;
        }
        if ((unit->genus == 1) && ((u64)datCalcChkBadStatus(selfDat, 4) != 0))
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = unit->genus == 0 ? 0x3e : 0x3f;
        }
    }

    if (BTLT_A32(action, 0xd8) == 1)
    {
        BTLT_A8(action, 0xca) = 0;
    }
    else
    {
        u16 targetCount = action->target.targetedCount;
        if (targetCount > 1)
        {
            u16 index = 0;
            while ((index < targetCount) && (action->target.targetedActions[index] != action))
                index++;
            if (index != targetCount)
            {
                for (; index < (u16)(targetCount - 1); index++)
                    action->target.targetedActions[index] = action->target.targetedActions[index + 1];
                action->target.targetedActions[index] = action;
            }
        }

        for (targetIndex = 0; targetIndex < targetCount; targetIndex++)
        {
            BtlAction *target = action->target.targetedActions[targetIndex];
            DatUnit *targetDat = target->unit->datUnit;
            DatUnit *candidateDat = targetDat;
            BtlAction *candidateAction = target;
            u16 efficacy;
            u8 slotCount;
            u8 chance;
            u8 slotIndex;
            u32 weaponType;
            f32 scale = 1.0f;
            s32 total = 0;
            s32 resultA;
            s32 resultB;
            u32 slotStatus;
            u32 slotOtherStatus;
            u32 baseValue;
            u32 targetSpecial;
            u8 terminate;

            *(u16 *)((u8 *)targetDat + 0x38) = 0;
            BTLT_A8(target, 0xc8) = 0;
            BTLT_A16(target, 0xcc) = 0;
            BTLT_A32(target, 0xd0) = 0;
            BTLT_A32(target, 0xd4) = 0;
            BTLT_A8(target, 0xca) = 0;
            BTLT_A8(target, 0xc9) = 0;
            BTLT_A32(target, 0xd8) = 0;
            BTLT_A16(target, 0xdc) = 0;
            BTLT_AS16(target, 0xde) = -1;

            efficacy = (u16)FUN_00309490(selfDat, targetDat, id, specialFlags);
            if (efficacy == 0x200)
            {
                efficacy = (u16)FUN_00309490(selfDat, selfDat, id, specialFlags | 2);
                if ((efficacy == 4) || (efficacy == 2))
                    efficacy = 1;
                else if (efficacy == 0x200)
                    efficacy = 0x100;
                BTLT_A32(target, 0xd4) = 1;
                candidateDat = selfDat;
                candidateAction = action;
            }

            if (BTLT_A32(target, 0xd4) == 0)
                targetSpecial = (u16)FUN_0030a740(selfDat, candidateDat, id, efficacy, specialFlags);
            else
                targetSpecial = ((s8)FUN_00301750(targetDat, 0xb) < 1) ? 1 : 0x10;

            if ((u64)FUN_003088b0(id) == 0)
            {
                slotCount = (u8)FUN_0030b9a0(selfDat, id, targetSpecial);
                chance = 1;
            }
            else
            {
                slotCount = 1;
                weaponType = (u32)FUN_00308c60(selfDat) & 0xff;
                chance = (u8)FUN_00308fd0(selfDat, targetSpecial);
                scale = (f32)DAT_007ce484[(weaponType & 0xff) * 3 + (u32)chance - 1] / 100.0f;
            }

            if ((BTLT_A32(target, 0xd4) == 0) &&
                ((efficacy == 0x100) || (efficacy == 4) || (efficacy == 2) ||
                 (efficacy == 0x400) || (efficacy == 0x200)))
            {
                slotCount = 1;
                chance = 1;
            }
            else if (BTLT_A32(target, 0xd4) != 0)
            {
                slotCount = 1;
                chance = 1;
            }

            if (BTLT_A32(target, 0xd4) == 0)
            {
                resultA = (s32)FUN_0030b130(selfDat, candidateDat, id, efficacy, targetSpecial, specialFlags);
                resultB = (s32)FUN_0030b210(selfDat, targetDat, id, efficacy, targetSpecial, specialFlags);
                if ((resultA != 1) && (resultB != 1))
                    resultA = (s32)FUN_002fd220(action, target);
            }
            else
            {
                resultA = 0;
                resultB = 0;
            }

            slotStatus = (u32)FUN_00306020(id, selfDat, candidateDat, efficacy, targetSpecial, specialFlags);
            slotOtherStatus = (u32)FUN_00306510(id, selfDat, candidateDat, efficacy, targetSpecial, specialFlags);
            if ((BTLT_T8(tableOffset, 0x18) == 1) &&
                ((BTLT_T32(tableOffset, 0x1c) & 0x80000) != 0) &&
                ((slotStatus & 0x80000) == 0))
                resultA = 0;
            if ((BTLT_A32(target, 0xd4) != 0) ||
                ((BTLT_D16(selfDat, 0) & 4) == (BTLT_D16(candidateDat, 0) & 4)))
                slotStatus &= 0xffffff9f;
            if (slotStatus == 0x80000)
                BTLT_A32(target, 0xd0) = 1;

            if ((efficacy == 1) && (BTLT_A32(target, 0xd4) == 0) &&
                ((s16)func_002e4910(target, id, specialFlags) == 0))
                baseValue = BTLT_T32(tableOffset, 0x20);
            else
                baseValue = 0;

            BTLT_A16(target, 0xcc) = efficacy;
            BTLT_A16(target, 0xce) = (u16)targetSpecial;
            if ((BTLT_A32(target, 0xd4) == 1) || ((efficacy & 0x500) != 0))
                func_002e32a0(action, target, id);

            for (slotIndex = 0; slotIndex < slotCount; slotIndex++)
            {
                u32 slotOffset = (u32)slotIndex * 0x1c;
                u8 *slotPtr = (u8 *)target + slotOffset;
                s32 amountA;
                s32 amountB;
                u8 callbackResult;

                *(u16 *)(slotPtr + 0xfa) = 0;
                *(u16 *)(slotPtr + 0xf4) = 0;
                *(u16 *)(slotPtr + 0xf6) = 0;
                amountA = (s32)FUN_00303130(id, selfDat, candidateDat, 1, efficacy, targetSpecial, specialFlags, 1);
                amountB = (s32)FUN_00303130(id, selfDat, candidateDat, 1, efficacy, targetSpecial, specialFlags, 2);
                amountA = (s32)((f32)amountA * scale);
                *(u32 *)(slotPtr + 0xe8) = slotStatus;
                *(u32 *)(slotPtr + 0xec) = slotOtherStatus;
                if ((attackType == 0xd) || (attackType == 0xc))
                    *(u16 *)(slotPtr + 0xf4) = (u16)FUN_0051e0e0(amountA);
                if ((BTLT_T8(tableOffset, 0x14) == 0xd) || (BTLT_T8(tableOffset, 0x14) == 0xc))
                    *(u16 *)(slotPtr + 0xf6) = (u16)FUN_0051e0e0(amountB);
                *(u32 *)(slotPtr + 0xf0) = baseValue;
                *(u8 *)(slotPtr + 0xf9) = datType;
                *(s32 *)(slotPtr + 0xe0) = amountA;
                *(s32 *)(slotPtr + 0xe4) = amountB;
                total += amountA;

                if (BTLT_T8(tableOffset, 0x24) == 9)
                    *(u16 *)(slotPtr + 0xfa) |= 0x80;
                else if (BTLT_T8(tableOffset, 0x24) == 6)
                    *(u16 *)(slotPtr + 0xfa) |= 0x20;
                if (id == 0x126)
                    *(u16 *)(slotPtr + 0xfa) |= 0x200;
                else if ((id == 0x128) || (id == 0x127) || (id == 0x125))
                    *(u16 *)(slotPtr + 0xfa) |= 0x100;
                if ((BTLT_T8(tableOffset, 0) & 1) != 0)
                    *(u16 *)(slotPtr + 0xfa) |= 0x40;
                if (attackType == 0x10)
                    *(u16 *)(slotPtr + 0xfa) |= 8;

                terminate = ((u64)datCalcIsDead(candidateDat, total) != 0);
                if ((terminate == 0) && ((slotStatus & 0x80000) != 0))
                    terminate = ((slotOtherStatus & 0x80000) == 0);
                if (((slotIndex + 1) == slotCount) || (terminate != 0))
                {
                    if (resultA == 0)
                    {
                        u8 forceFlag = 0;
                        if (((total < 0) || (efficacy == 0x100) || (efficacy == 0x400)) &&
                            ((u64)datCalcChkBadStatus(candidateDat, 0x100000) != 0))
                            forceFlag = 1;
                        if ((BTLT_A32(target, 0xd4) == 1) &&
                            ((u64)datCalcChkBadStatus(targetDat, 0x100000) != 0))
                            forceFlag = 1;
                        if (forceFlag != 0)
                        {
                            *(u16 *)(slotPtr + 0xfa) |= 1;
                            if ((BTLT_A32(target, 0xd4) == 1) ||
                                (efficacy == 0x100) || (efficacy == 0x400))
                                *(u16 *)(slotPtr + 0xfa) |= 2;
                        }
                    }
                    else
                    {
                        *(u32 *)(slotPtr + 0xe8) |= 0x100000;
                    }
                    if (resultB != 0)
                        *(u16 *)(slotPtr + 0xfa) |= 4;
                    if ((efficacy == 1) && (BTLT_A32(target, 0xd4) == 0) && (resultB != 1))
                    {
                        if (resultA != 0)
                            successfulTargets++;
                    }
                    else
                    {
                        finalFlags = 2;
                    }
                }

                if (terminate != 0)
                {
                    s16 hpDelta = (s16)FUN_0030b640(candidateAction->unit->datUnit, id);
                    if (hpDelta < 0)
                    {
                        callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 1);
                        BTLT_A32(target, 0xd0) = 1;
                        BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
                        if (action == candidateAction)
                            *(u16 *)(slotPtr + 0xf4) = 0;
                    }
                    else
                    {
                        BTLT_AS16(target, 0x460) = hpDelta;
                        *(u16 *)(slotPtr + 0xfa) |= 0x10;
                        callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 0);
                        BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
                    }
                    slotCount = (u8)(slotIndex + 1);
                    break;
                }

                callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 0);
                BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
            }

            {
                u16 targetValue = BTLT_D16(selfDat, 0x38);
                if ((targetValue == 0) && (BTLT_D16(targetDat, 0x38) != 0))
                    targetValue = BTLT_D16(targetDat, 0x38);
                inherited = targetValue;
            }
            {
                s16 overrideValue = (s16)FUN_002d56a0(id);
                if (overrideValue == 0)
                {
                    if (inherited != 0)
                        BTLT_A16(target, 0xdc) = inherited;
                }
                else
                    BTLT_AS16(target, 0xdc) = overrideValue;
            }
            BTLT_A8(target, 0xc8) = slotCount;
            BTLT_A8(target, 0xc9) = chance;
        }

        if (action->target.targetedCount == successfulTargets)
            finalFlags |= 1;
        if (BTLT_AS16(action, 0xde) == -1)
            BTLT_A16(action, 0xde) = (u16)FUN_002d5b50(id);
        if (((s16)FUN_002e47a0(action, id, specialFlags) != 0) && (BTLT_A32(action, 0xd8) != 1))
            BTLT_A16(action, 0xdc) = (u16)FUN_002e4720();
        BTLT_A8(action, 0xca) = finalFlags;
    }
}

// FUN_002d7560 NONMATCHING
void FUN_002d7560(BtlAction *action)
{
    u32 i;
    BtlUnit *unit = action->unit;
    DatUnit *dat = unit->datUnit;
    if (((action->unk_1a & 1) != 0) && (unit->genus == 1))
    {
        s32 outFlag;
        if (unit->charId > 0x14f)
            FUN_0019d3f0(0x6978e0, 0x37e);
        if ((action->unk_1a & 0x20) == 0)
        {
            u32 rawValue;
            f32 timeScale;
            f32 value;
            f32 scaled;
            u32 amount;
            s16 personaId;
            action->unk_1a |= 0x20;
            rawValue = (u32)FUN_0030bc50(dat);
            timeScale = (f32)FUN_001c0070();
            value = ((s32)rawValue < 0) ? (f32)rawValue : (f32)(s32)rawValue;
            scaled = value * timeScale;
            if (scaled < 2147483648.0f)
                amount = (u32)scaled;
            else
                amount = (u32)(scaled - 2147483648.0f) | 0x80000000;
            BTLT_B32(0xbfc) += amount;

            personaId = (s16)FUN_0030bde0(dat, &outFlag);
            if ((outFlag != 1) && (BTLT_AS16(action, 0x80) != 0) &&
                ((u8)FUN_002ffbc0(100) < BTLT_A8(action, 0x82)))
                personaId = BTLT_AS16(action, 0x80);
            if (personaId != 0)
            {
                u8 found = 0;
                for (i = 0; i < 3; i++)
                {
                    if (BTLT_BS16(0xbe0 + i * 8) == personaId)
                    {
                        BTLT_B32(0xbe4 + i * 8)++;
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    for (i = 0; i < 3; i++)
                    {
                        if (BTLT_BS16(0xbe0 + i * 8) == 0)
                        {
                            BTLT_BS16(0xbe0 + i * 8) = personaId;
                            BTLT_B32(0xbe4 + i * 8) = 1;
                            BTLT_B32(0xbf8) = i + 1;
                            break;
                        }
                    }
                }
            }
            if ((*(u16 *)(DAT_007ce410 + (u32)unit->charId * 0x3e) & 0x40) != 0)
                BTLT_B32(0xbdc) |= 2;
            switch (BTLT_D16(dat, 2))
            {
            case 0xc4: BTLT_B32(0xc20) |= 8; break;
            case 0xc3: BTLT_B32(0xc20) |= 4; break;
            case 0xc2: BTLT_B32(0xc20) |= 2; break;
            case 0xc1: BTLT_B32(0xc20) |= 1; break;
            default: break;
            }
        }
    }
}

// FUN_002d7890
void FUN_002d7890(BtlAction* action, u64 mode)
{
    BtlUnit* unit = action->unit;
    u32 flags;

    FUN_002fa510(action, mode);
    if (mode == 1)
    {
        if (BTLT_A16(action, 0x460) != 0x1b6)
        {
            datCalcSetHp(unit->datUnit, 1);
        }
        FUN_00300560(unit->datUnit, 0x80000);
        unit->flags3 |= 0x10;
    }
    else
    {
        FUN_002ffd90(unit->datUnit, 0);
        FUN_00300560(unit->datUnit, 0xffffff);
        FUN_003004f0(unit->datUnit, 0x80000);
        flags = unit->flags3 | 1;
        unit->flags3 = flags;
        unit->flags3 = flags & 0xffffffef;
    }
}

// FUN_002d79a0 NONMATCHING
u32 FUN_002d79a0(void *arg)
{
    BtlTargetPacketWork *work = (BtlTargetPacketWork *)arg;
    BtlAction *action = work->action;
    BtlUnit *unit;
    u64 oldDead;
    u64 oldLowHp;
    u64 oldDown;

    if ((action->unk_1a & 1) == 0)
        return 1;
    unit = action->unit;
    oldDead = datCalcIsDead(unit->datUnit, 0);
    oldLowHp = datCalcIsLowHp(unit->datUnit);
    oldDown = datCalcChkBadStatus(unit->datUnit, 0x200);

    if ((work->targetFlags & 2) != 0)
        action->unk_18 |= 0x1000;
    if ((work->targetFlags & 4) != 0)
        action->unk_18 |= 0x800;
    if ((*(u32 *)(work->data + 8) & 0x100000) != 0)
        action->unk_18 |= 0x2000;

    if ((BTLT_B32(0xc) & 0x10) != 0)
    {
        FUN_00300410(unit->datUnit, *(s32 *)(work->data + 0));
        FUN_00300480(unit->datUnit, *(s32 *)(work->data + 4));
        if (((*(s32 *)(work->data + 0) < 0) || (*(s32 *)(work->data + 4) < 0)) && (unit->genus == 0))
            FUN_001feea0(unit->charId);
    }
    if ((BTLT_B32(0xc) & 0x20) != 0)
    {
        FUN_002dc550(action, *(u32 *)(work->data + 8));
        FUN_003004f0(unit->datUnit, *(u32 *)(work->data + 8));
        FUN_00300560(unit->datUnit, *(u32 *)(work->data + 12));
    }
    if (*(u32 *)(work->data + 16) != 0)
        FUN_00302380(unit->datUnit, *(u32 *)(work->data + 16), 1);

    {
        u64 currentDead = datCalcIsDead(unit->datUnit, 0);
        if ((currentDead == 0) || (oldDead != 0))
        {
            u64 currentLowHp = datCalcIsLowHp(unit->datUnit);
            if ((currentLowHp == 0) || (oldLowHp != 0))
            {
                u64 currentDown = datCalcChkBadStatus(unit->datUnit, 0x200);
                if ((currentDown != 0) && (oldDown == 0))
                    FUN_002daa20(action, 0x1c, 0, 0, 0);
            }
            else
                FUN_002daa20(action, 0x1a, 0, 0, 0);
        }
        else
        {
            if (unit->genus == 1)
            {
                BTLT_BS16(0xb9a)++;
                if ((*(u16 *)(work->data + 0x1a) & 8) != 0)
                    BTLT_BS16(0xb9c)++;
                {
                    u32 level = (u32)datCalcGetLevel(unit->datUnit) & 0xff;
                    BTLT_B32(0xc14) += level;
                    if ((s32)BTLT_B32(0xc10) < (s32)level)
                        BTLT_B32(0xc10) = level;
                }
            }
            {
                u8 rumble = ((*(u16 *)(work->data + 0x1a) & 0x10) != 0);
                FUN_002fa510(action, rumble);
                if (rumble != 0)
                {
                    if (BTLT_A16(action, 0x460) != 0x1b6)
                        datCalcSetHp(unit->datUnit, 1);
                    FUN_00300560(unit->datUnit, 0x80000);
                    unit->flags3 |= 0x10;
                }
                else
                {
                    u32 oldFlags;
                    FUN_002ffd90(unit->datUnit, 0);
                    FUN_00300560(unit->datUnit, 0xffffff);
                    FUN_003004f0(unit->datUnit, 0x80000);
                    oldFlags = unit->flags3 | 1;
                    unit->flags3 = oldFlags;
                    unit->flags3 = oldFlags & 0xffffffef;
                }
            }
            if ((u64)datCalcIsDead(unit->datUnit, 0) != 0)
            {
                if (BTLT_B32(0x148) == (u32)(uintptr_t)action)
                {
                    FUN_00103c30(0x19, 0x96, 0x19, 0);
                    FUN_002daa20(action, 0x13, ((*(u32 *)(work->data + 8) & 0x80000) != 0), 0, 2);
                }
                else
                    FUN_002daa20(action, 0x1b, 0, 0, 0);
            }
        }
    }
    func_002faa50(work->source, action, (BtlTargetResult*)work->data);
    FUN_002831c0(unit, 6);
    return 1;
}

// FUN_002d7e20
BtlPacket *FUN_002d7e20(BtlAction *source, BtlAction *action, const void *data, u16 effect, u16 targetFlags)
{
    BtlPacket *packet = btlPacketCreate(0x700, 0x28);
    BtlTargetPacketWork *work;
    packet->initFunc = FUN_002D7970;
    packet->updateFunc = FUN_002d79a0;
    packet->destroyFunc = FUN_002D7DF0;
    work = (BtlTargetPacketWork *)packet->workData;
    work->source = source;
    work->action = action;
    memcpy(work->data, data, 0x1c);
    work->effect = effect;
    work->targetFlags = targetFlags;
    return packet;
}

/* Required existing declarations/notes:
 * - DAT_007ce3ec is the battle-global base; DAT_007ce3f8 is the 0x2c-byte
 *   attack/effect table, DAT_007ce410 is the 0x3e-byte character table, and
 *   DAT_007ce484 is the weapon-type x three-column scale table.
 * - FUN_002d6460 is the preceding target-slot helper.  All other raw FUN_/DAT_
 *   names above remain unnamed because no canonical public API was established.
 */

// FUN_002da810
s32 FUN_002da810(BtlAction* action)
{
    if (*(BtlAction**)(iGpffffb6fc + 0x148) != action)
    {
        return -1;
    }
    if (datCalcChkBadStatus(action->unit->datUnit, 1) == 0)
    {
        return -1;
    }

    switch (action->target.commandId)
    {
        case 1:
            if (FUN_002d1600(&action->target) == 1)
            {
                return 0x18f;
            }
            break;
        case 2:
            if (FUN_002d1600(&action->target) == 2 &&
                FUN_00308860(action->target.specificId) != 0)
            {
                return 0x190;
            }
            break;
        case 0xb:
            if (datGetScenarioMode() == 0)
            {
                return 0x191;
            }
            break;
        default:
            break;
    }

    return -1;
}

// FUN_002da930
u64 FUN_002da930(u64 param_1, u64 command, u64 param_3, u64 param_4)
{
    switch (command)
    {
        case 0x1cf:
            *(u16*)(iGpffffb6fc + 0xa14) = 2;
            break;
        case 0x1d0:
            *(u16*)(iGpffffb6fc + 0xa14) = 3;
            break;
        case 0x1d1:
            *(u16*)(iGpffffb6fc + 0xa14) = 4;
            break;
        case 0x1d2:
            *(u16*)(iGpffffb6fc + 0xa14) = 5;
            break;
        case 0x1d3:
            *(u16*)(iGpffffb6fc + 0xa14) = 7;
            break;
        case 0x1d4:
            *(u16*)(iGpffffb6fc + 0xa14) = 8;
            break;
        case 0x1d5:
            *(u16*)(iGpffffb6fc + 0xa14) = 9;
            break;
        case 0x1d6:
            *(u16*)(iGpffffb6fc + 0xa14) = 10;
            break;
        case 0x1d7:
            *(u16*)(iGpffffb6fc + 0xa14) = 6;
            break;
        default:
            break;
    }
    return command;
}

// FUN_002daa20 NONMATCHING
s32 FUN_002daa20(BtlAction* param_1, u16 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    u8* btl;
    u32 effectId;
    u32* effectFlags;
    u8* resourceTable;
    u8* resultTable;
    u8* resultRecord;
    BtlTargetEffectFn effect;
    u64 result;

    btl = iGpffffb6fc;
    effectId = param_2;

    if ((*(u32*)(btl + 0xc) & 0x01000000) == 0)
    {
        return 1;
    }
    if (*(u16*)(btl + 0xa18) != 0)
    {
        return 0;
    }
    if (datGetFlag(0x1317) != 0)
    {
        return 1;
    }
    if ((param_5 & 6) == 0 && (*(u16*)(btl + 0xa16) & 1) != 0)
    {
        return 1;
    }

    effectFlags = (u32*)(iGpffffb7b8 +
        (u32)*(u16*)(*(u8**)(btl + 0xbbc) + 8) * 0x1c);
    if (effectId != 0x1f && (*effectFlags & 0x400) != 0)
    {
        return 1;
    }
    if ((*(u16*)(btl + 0xa16) & 1) != 0)
    {
        if ((s32)*(s16*)(btl + 0xa24) == (s32)effectId ||
            (s32)*(s16*)(btl + 0xa2c) == (s32)effectId)
        {
            return 1;
        }
    }

    effect = D_006978F0[effectId];
    if (effect == NULL)
    {
        return 1;
    }
    result = effect((u64)(uintptr_t)param_1, param_3, param_4, 0);
    if (result < 0)
    {
        return 1;
    }

    resourceTable = *(u8**)(btl + 0xa1c);
    resultTable = *(u8**)(resourceTable + 0x110);
    resultRecord = resultTable + ((u32)result & 0xffff) * 0xc;
    if ((*effectFlags & 0x1000) != 0 && *resultRecord != 0)
    {
        return 1;
    }

    if (datGetScenarioMode() != 0)
    {
        u64 mode = FUN_002d5550();
        if ((mode == 0x1b3 || mode == 0x1b2 || mode == 0x1b1) &&
            ((*(u16*)resultRecord >> 8) != 0))
        {
            return 1;
        }
    }

    if ((param_5 & 2) != 0)
    {
        FUN_002dba80();
        *(u16*)(btl + 0xa36) = 2;
    }
    else
    {
        *(u16*)(btl + 0xa36) = 0;
    }

    return FUN_002db9f0(param_2, (u64)result);
}

#pragma push
#pragma opt_rebuildconditionals off
// FUN_002dad00
void FUN_002dad00(void)
{
    u8* base;
    u16* modePtr;
    u16 mode;
    s16* counter;
    u8* resourceTable;
    u8* record;
    s32 offset;
    u32 recordOffset;
    u32 randomValue;

    base = iGpffffb6fc;
    modePtr = (u16*)(base + 0xa18);
    mode = *modePtr;
    switch (mode) {
    case 0:
        goto updateFlag;
    case 1:
        counter = (s16*)(base + 0xa36);
        if (*counter > 0) {
            *counter = *counter - 1;
            goto updateFlag;
        }
        *modePtr = 2;
    case 2:
        break;
    default:
        goto updateFlag;
    }
    resourceTable = *(u8**)(iGpffffb6fc + 0xa1c);
    record = *(u8**)(resourceTable + 0x110);
    recordOffset = (u32)*(u16*)(iGpffffb6fc + 0xa28) * 0xc;
    recordOffset += (u32)record;
    offset = *(u32*)(recordOffset + 4);
    record += offset;
    FUN_003c8dd0(record);
    randomValue = datCalcRand((u32)FUN_003a3010(record));
    FUN_003c8de0(*(u16*)(iGpffffb6fc + 0xa14), randomValue, 0, 0);
    *(u32*)(iGpffffb6fc + 0xa20) = *(u32*)(iGpffffb6fc + 0xa28);
    *(u16*)(iGpffffb6fc + 0xa24) = *(s16*)(iGpffffb6fc + 0xa2c);
    *(u16*)(iGpffffb6fc + 0xa16) |= 1;
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
updateFlag:
    if (FUN_003c8ea0() == 0)
        *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}
#pragma pop

// FUN_002dae30 NONMATCHING
void FUN_002dae30(u64 param_1)
{
    u8* btl;
    u32 stop;
    u32 slotIndex;

    btl = iGpffffb6fc;
    stop = 0;
    slotIndex = 0;
    while (slotIndex < 3 && stop == 0)
    {
        u32 bit = (1u << (slotIndex & 0x1f)) & 0xffff;
        if ((*(u16*)(btl + 0xa04) & bit) != 0)
        {
            if (param_1 != 0)
            {
                u8* slot = btl + slotIndex * 4;
                *(u16*)(slot + 0x9f8) = *(u16*)(slot + 0x9f8) + 1;
            }

            if (bit == 4)
            {
                u16 currentId = FUN_002db690();
                u8* currentUnit = (u8*)btlUnitFindFromId(currentId);
                if (currentUnit == NULL ||
                    datCalcIsDead(*(DatUnit**)(currentUnit + 0xa2c), 0) != 0)
                {
                    BtlUnit* unit;
                    unit = *(BtlUnit**)(btl + 0x158);
                    while (unit != NULL &&
                           (((unit->flags3 & 8) == 0 ||
                             datCalcIsDead(unit->datUnit, 0) != 0) ||
                            unit->charId != *(u16*)(btl + 0xa0c)))
                    {
                        unit = unit->next;
                    }
                    if (unit == NULL)
                    {
                        u8* slot = btl + slotIndex * 4;
                        *(u16*)(slot + 0x9f8) = *(u16*)(slot + 0x9fa);
                    }
                    else
                    {
                        FUN_002db650(*(u32*)((u8*)unit + 0xa8));
                    }
                }
            }
            else if (bit == 1 && *(u32*)(btl + 0xa10) == 0 &&
                     FUN_0029adf0(*(BtlAction**)(btl + 0x148)) == 0)
            {
                u8* candidates[3];
                u32 candidateCount = 0;
                u32 i;
                for (i = 0; i < 3; i++)
                {
                    u8* candidate = *(u8**)(btl + 0xbc4 + i * 8);
                    if (candidate != NULL &&
                        (*(u16*)(candidate + 0xa) & 1) == 0 &&
                        FUN_002ff790(candidate) == 0)
                    {
                        candidates[candidateCount] = candidate;
                        candidateCount = (candidateCount + 1) & 0xffff;
                    }
                }
                if (candidateCount == 0)
                {
                    *(u16*)(btl + 0xa04) &= (u16)~1;
                }
                else
                {
                    u8* selected = candidates[datCalcRand(candidateCount)];
                    *(u8**)(btl + 0xa10) = selected;
                    FUN_002daa20(0, 7, *(u16*)(*(u8**)(selected + 4) + 2), 0, 4);
                }
            }

            {
                u8* slot = btl + slotIndex * 4;
                if (*(u16*)(slot + 0x9fa) <= *(u16*)(slot + 0x9f8))
                {
                    if (bit == 4)
                    {
                        BtlAction* action = *(BtlAction**)(btl + 0x148);
                        if (FUN_0029adf0(action) == 0)
                        {
                            action->unk_16 = 7;
                            FUN_0029a380(action);
                            stop = 1;
                            *(u16*)(btl + 0xa04) &= (u16)~4;
                        }
                    }
                    else if (bit == 2)
                    {
                        BtlAction* action = *(BtlAction**)(btl + 0x148);
                        if (FUN_0029adf0(action) == 0)
                        {
                            action->unk_16 = 0x13;
                            FUN_0029a380(action);
                            stop = 1;
                            *(u16*)(btl + 0xa04) &= (u16)~2;
                        }
                    }
                    else if (bit == 1 && (*(u16*)(btl + 0xa06) & 1) == 0 &&
                             FUN_0029adf0(*(BtlAction**)(btl + 0x148)) == 0)
                    {
                        if (FUN_002db480() == 0 && *(u32*)(btl + 0xa10) != 0)
                        {
                            u8* selected = *(u8**)(btl + 0xa10);
                            BtlAction* action = (BtlAction*)FUN_00289650(
                                0, *(u16*)(*(u8**)(selected + 4) + 2));
                            *(u16*)(selected + 0xa) |= 1;
                            FUN_001fdd40();
                            action->unk_16 = 0x11;
                            FUN_0029a380(action);
                            *(u16*)(btl + 0xa06) |= 1;
                            stop = 1;
                            FUN_002db2a0(0);
                        }
                        else
                        {
                            *(u16*)(btl + 0xa04) &= (u16)~1;
                        }
                    }
                }
            }
        }
        slotIndex = (slotIndex + 1) & 0xffff;
    }
}

// FUN_002db2a0 NONMATCHING
void FUN_002db2a0(u32 param_1)
{
    s16 threshold;
    u32 index;

    index = param_1 & 0xffff;
    *(u16*)(iGpffffb6fc + 0xa04) |=
        (u16)(1u << index);

    if (index == 2)
    {
        if (datGetFlag(0x140) != 0)
        {
            threshold = (s16)(datCalcRand(2) + 2);
        }
        else if (datGetFlag(0x141) != 0)
        {
            threshold = (s16)(datCalcRand(2) + 3);
        }
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(s16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
    }
    else if (index == 1)
    {
        threshold = (s16)(datCalcRand(1) + 2);
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(s16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
    }
    else if (index == 0)
    {
        threshold = (s16)(datCalcRand(0) + 2);
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(s16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
        *(u32*)(iGpffffb6fc + 0xa10) = 0;
    }
}
typedef struct BtlTargetActionWork
{
    BtlAction* action;
    u16 command;
    u16 pad_06;
    s32 param_3;
    s32 param_4;
    s32 param_5;
    s32 result;
} BtlTargetActionWork;

typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;

typedef struct BtlTargetCdWork
{
    u8 unk_00[4];
    u16 resource;
    u16 state;
} BtlTargetCdWork;

// FUN_002db420
void FUN_002db420(u32 param_1)
{
    u16* flags = (u16*)(iGpffffb6fc + 0xa04);
    *flags &= (u16)~(1u << (param_1 & 0xffff));
}

// FUN_002db450
u32 FUN_002db450(u32 param_1)
{
    return ((u32)*(u16*)(iGpffffb6fc + 0xa04) &
            (1u << (param_1 & 0xffff))) != 0;
}

// FUN_002db480 NONMATCHING
u32 FUN_002db480(void)
{
    u16 activeCount = 0;
    u16 enabledCount = 0;
    u16 slot;

    for (slot = 0; slot < 3; slot++)
    {
        u8* enemyGroup = *(u8**)(iGpffffb6fc + slot * 8 + 0xbc4);
        if (enemyGroup != NULL && FUN_002FF790(enemyGroup) == 0)
        {
            activeCount++;
            if ((*(u16*)(enemyGroup + 0x0a) & 1) == 0)
            {
                return 0;
            }
            enabledCount++;
        }
    }
    if (activeCount != 0 && activeCount == enabledCount)
    {
        return 2;
    }

    enabledCount = 0;
    for (slot = 0; slot < 4; slot++)
    {
        s16 pcId = datGetPartyId(slot);
        if (pcId != 0)
        {
            BtlUnit* unit = *(BtlUnit**)(iGpffffb6fc + 0x150);
            while (unit != NULL && unit->charId != (u16)pcId)
            {
                unit = unit->next;
            }
            if (unit == NULL)
            {
                DatUnit* datUnit = datGetUnit(pcId);
                enabledCount++;
                if (datCalcIsDead(datUnit, 0) == 0)
                {
                    break;
                }
            }
        }
    }
    if (enabledCount != 0 && slot == 4)
    {
        return 3;
    }
    return 1;
}

// FUN_002db650
void FUN_002db650(u32 param_1)
{
    BtlUnit* unit;
    *(u32*)(iGpffffb6fc + 0xa08) = param_1;
    unit = btlUnitFindFromId((u16)param_1);
    *(u16*)(iGpffffb6fc + 0xa0c) = unit->charId;
}

// FUN_002db690
u32 FUN_002db690(void)
{
    return *(u32*)(iGpffffb6fc + 0xa08);
}

// FUN_002db6a0
u32 FUN_002db6a0(void* param_1)
{
    BtlTargetActionWork* work = (BtlTargetActionWork*)param_1;
    s32 result;
    if (work->result == 0)
    {
        work->result = FUN_002daa20(work->action, work->command,
                                    work->param_3, work->param_4,
                                    work->param_5);
    }
    result = work->result;
    if (result == 1 && (work->param_5 & 1) != 0 &&
        ((*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0 ||
         *(u16*)(iGpffffb6fc + 0xa18) != 0))
    {
        result = 0;
    }
    return result;
}

// FUN_002db740
BtlPacket* FUN_002db740(BtlAction* action, u16 command, u32 param_3,
                        u32 param_4, u32 param_5)
{
    BtlPacket* packet = btlPacketCreate(0x800, 0x18);
    BtlTargetActionWork* work;
    packet->updateFunc = FUN_002db6a0;
    work = (BtlTargetActionWork*)packet->workData;
    work->action = action;
    work->command = command;
    work->param_3 = param_3;
    work->param_4 = param_4;
    work->param_5 = param_5;
    work->result = 0;
    return packet;
}

// FUN_002db7d0
u32 FUN_002db7d0(void* param_1)
{
    BtlTargetSimpleWork* work = (BtlTargetSimpleWork*)param_1;
    FUN_002db9f0(work->command, work->param);
    return 1;
}

// FUN_002db800
BtlPacket* FUN_002db800(u16 command, u32 param)
{
    BtlPacket* packet = btlPacketCreate(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = FUN_002db7d0;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}

// FUN_002db860
u32 FUN_002db860(void* param_1)
{
    (void)param_1;
    FUN_002dba80();
    return 1;
}

// FUN_002db890
BtlPacket* FUN_002db890(void)
{
    BtlPacket* packet = btlPacketCreate(0x802, 0);
    packet->updateFunc = FUN_002db860;
    return packet;
}

// FUN_002db8d0
void FUN_002db8d0(void)
{
    s32 empty;

    FUN_00521408(iGpffffb6fc + 0x9f8, 0, 0x40);
    *(u32*)(iGpffffb6fc + 0xa1c) = 0;
    empty = -1;
    *(u32*)(iGpffffb6fc + 0xa20) = empty;
    *(s16*)(iGpffffb6fc + 0xa24) = empty;
    *(u32*)(iGpffffb6fc + 0xa28) = empty;
    *(s16*)(iGpffffb6fc + 0xa2c) = empty;
    *(u32*)(iGpffffb6fc + 0xa30) = empty;
    *(s16*)(iGpffffb6fc + 0xa34) = empty;
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) = 0;
    *(u16*)(iGpffffb6fc + 0xa14) = 6;
    *(u16*)(iGpffffb6fc + 0xa36) = 0;
}

// FUN_002db960
void FUN_002db960(void)
{
    FUN_002dad00();
}

// FUN_002db980
void FUN_002db980(void)
{
    HCdvd* cdvd = *(HCdvd**)(iGpffffb6fc + 0xa1c);
    if (cdvd != NULL)
    {
        H_Cdvd_Destroy(cdvd);
        *(HCdvd**)(iGpffffb6fc + 0xa1c) = NULL;
        *(u32*)(iGpffffb6fc + 0x0c) &= 0xfeffffff;
    }
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
    func_003c8f20();
}

// FUN_002db9f0
u32 FUN_002db9f0(u16 param_1, u32 param_2)
{
    u32 result;
    u8* base = iGpffffb6fc;
    if ((*(u16*)(base + 0xa16) & 1) != 0)
    {
        if (*(u32*)(base + 0xa20) == param_2)
        {
            result = 1;
            goto done;
        }
        if (*(u32*)(base + 0xa28) == param_2)
        {
            result = 1;
            goto done;
        }
    }
    *(u16*)(base + 0xa2c) = param_1;
    base = iGpffffb6fc;
    *(u32*)(base + 0xa28) = param_2;
    result = 1;
    *(u16*)(iGpffffb6fc + 0xa18) = (u16)result;
done:
    return result;
}

// FUN_002dba60
u32 FUN_002dba60(void)
{
    return (*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0;
}

// FUN_002dba80
void FUN_002dba80(void)
{
    func_003c8f40();
    func_003c8f70();
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}

// FUN_002dbac0
void FUN_002dbac0(void)
{
    func_003c8f40();
    func_003c8fa0();
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}

// FUN_002dbb00 NONMATCHING
u32 FUN_002dbb00(BtlUnit* param_1)
{
    u16 candidates[16];
    u16 count = 0;
    u16 firstCount = 0;
    u16 slot;
    u8* encounter = *(u8**)(iGpffffb6fc + 0xbbc);
    u8* table;
    u32 result;

    if (datGetScenarioMode() != 0)
    {
        u32 encounterId = FUN_002d5550();
        if (encounterId == 0x1b3 || encounterId == 0x1b2 || encounterId == 0x1b1)
        {
            return 0xffffffff;
        }
    }
    if (param_1->charId > 0x14f)
    {
        K_Assert(D_00697B18, 0x96f);
    }
    if ((*(u16*)(iGpffffb720 + (u32)param_1->charId * 0x3e + 0x1e) & 0x20) != 0)
    {
        return 0xffffffff;
    }
    table = (datGetFlag(0x141) != 0) ? D_00697980 : D_00697A50;
    for (slot = 0; slot < 10; slot++)
    {
        u8* entry = table + (u32)slot * 0x12;
        if (entry[6] != 0 &&
            (func_00306e80(param_1->datUnit, slot) & 0x08000000) != 0)
        {
            if (*(u16*)(encounter + 8) == 0x1a1)
            {
                candidates[count] = *(u16*)(entry + 8);
            }
            else
            {
                candidates[count] = *(u16*)(entry + datCalcRand(entry[6]) * 2);
            }
            count++;
            firstCount++;
        }
    }
    if (count == 0)
    {
        count = 0;
        for (slot = 0; slot < 10; slot++)
        {
            u8* entry = table + (u32)slot * 0x12;
            if (entry[0x10] != 0 &&
                (func_00306e80(param_1->datUnit, slot) & 0x07000000) != 0)
            {
                candidates[count] = *(u16*)(entry + datCalcRand(entry[0x10]) * 2 + 0x0a);
                count++;
            }
        }
        if (count == 0)
        {
            if (*(u16*)(encounter + 8) == 0x1a1)
                result = *(u16*)(table + 0xbc);
            else
                result = *(u16*)(table + datCalcRand(*(u8*)(table + 0xba)) * 2 + 0xb4);
        }
        else
        {
            result = candidates[datCalcRand(count)];
        }
    }
    else if (firstCount < 2)
    {
        result = candidates[datCalcRand(firstCount)];
    }
    else
    {
        result = (datGetFlag(0x141) == 0) ? 0x3d4 : 0x209;
    }
    return result;
}

#pragma push
// FUN_002dbeb0
u32 FUN_002dbeb0(void* param_1)
{
    BtlTargetCdWork* work = (BtlTargetCdWork*)param_1;

    switch (work->state)
    {
    case 0:
        *(u16*)(iGpffffb6fc + 0xa14) = (work->resource == 0) ? 4 : 6;
    case 1:
        *(HCdvd**)(iGpffffb6fc + 0xa1c) = H_Cdvd_Request(D_00697B90[work->resource], 0);
        work->state = 2;
        goto zero;
    case 2:
        if (H_Cdvd_IsFileLoaded(*(HCdvd**)(iGpffffb6fc + 0xa1c)) == 0)
            goto zero;
    case 3:
        func_003c8da0((1u << *(u16*)(iGpffffb6fc + 0xa14)) | 1);
        work->state = 4;
    case 4:
        *(u32*)(iGpffffb6fc + 0x0c) |= 0x01000000;
        goto one;
    default:
        goto zero;
    }
one:
    return 1;
zero:
    return 0;
}
#pragma pop

// FUN_002dbfe0
BtlPacket* FUN_002dbfe0(u16 param_1)
{
    BtlPacket* packet = btlPacketCreate(0x803, 8);
    BtlTargetCdWork* work;
    packet->unk_47 &= (u8)~BTLPACKET_FLAG_AUTO_DESTROY;
    packet->updateFunc = FUN_002dbeb0;
    work = (BtlTargetCdWork*)packet->workData;
    work->resource = (datGetScenarioMode() != 0) ? 2 : param_1;
    work->state = 0;
    return packet;
}
// FUN_002dc070
u32 FUN_002dc070(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    u16 chance;

    if (datCalcChkBadStatus(datUnit, 0x100000) != 0)
    {
        return 1;
    }
    if (datCalcChkBadStatus(datUnit, 0x10037f) == 0)
    {
        return 0;
    }
    chance = 100;
    switch (datCalcGetBadStatusNoDown(datUnit))
    {
    case 8:
        chance = 50;
        break;
    default:
        break;
    }
    return datCalcRand(100) < chance;
}

// FUN_002dc130
u32 FUN_002dc130(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    if ((action->unk_18 & 4) != 0)
    {
        return 0;
    }
    return datCalcChkBadStatus(datUnit, 0x80) != 0;
}

// FUN_002dc180 NONMATCHING
u32 FUN_002dc180(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    u32 status = datCalcGetBadStatus(datUnit);
    u32 result = 0;
    u32 index;

    for (index = 0; index < 0x18; index++)
    {
        u32 bit = 1u << index;
        u32 chance = 0;
        u32 threshold = 0;
        u32 useCounter = 1;
        u32 reduceBySkills = 0;

        if ((status & bit) == 0)
        {
            continue;
        }
        switch (bit)
        {
        case 0x100:
            threshold = (datGetScenarioMode() != 0) ? 5 : 4;
            useCounter = 1;
            break;
        case 0x200:
            threshold = 3;
            useCounter = 1;
            break;
        case 0x40:
            chance = FUN_0030FC40(0xe, datUnit, datUnit, 0, 0x40);
            threshold = 2;
            useCounter = 0;
            reduceBySkills = 1;
            break;
        case 0x20:
            chance = FUN_0030FC40(0xd, datUnit, datUnit, 0, 0x20);
            threshold = 2;
            useCounter = 0;
            reduceBySkills = 1;
            break;
        case 0x10:
            if (*(u8*)((u8*)action + 0x28) == 0 &&
                *(u8*)((u8*)action + 0x29) == 0)
            {
                chance = FUN_0030FC40(0xc, datUnit, datUnit, 0, 0x10);
                threshold = 4;
                reduceBySkills = 1;
            }
            break;
        case 8:
            chance = FUN_0030FC40(0xb, datUnit, datUnit, 0, 8);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 4:
            chance = FUN_0030FC40(0xa, datUnit, datUnit, 0, 4);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 2:
            chance = FUN_0030FC40(9, datUnit, datUnit, 0, 2);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 1:
            chance = FUN_0030FC40(8, datUnit, datUnit, 0, 1);
            threshold = 4;
            reduceBySkills = 1;
            break;
        default:
            break;
        }
        if (reduceBySkills && threshold != 0)
        {
            if (datCalcHasSkill(datUnit, 0x262) != 0)
            {
                threshold >>= 1;
                if (threshold == 0)
                    threshold = 1;
            }
            if (datCalcHasSkill(datUnit, 0x263) != 0)
                threshold = 1;
        }
        if (useCounter == 0 || *((u8*)action + index + 0x462) > 1)
        {
            u8 counter = *((u8*)action + index + 0x462);
            if (counter < threshold || threshold == 0)
            {
                if (datCalcRand(100) < chance)
                    result |= bit;
            }
            else
            {
                result |= bit;
            }
        }
    }
    return result;
}

/* Required symbol/type notes:
 * - The canonical TU must provide iGpffffb6fc (Battle work base), iGpffffb7b8
 *   (the 0x1c-byte effect-flag table base), and D_006978F0, an array of
 *   four-argument effect callbacks returning signed 64-bit values.
 * - Existing headers provide BtlAction/BtlTarget/BtlUnit, datCalcRand,
 *   datCalcChkBadStatus, datCalcIsDead, datGetFlag, datGetScenarioMode, and
 *   btlUnitFindFromId. If the TU keeps raw retail aliases instead, map these
 *   to FUN_002FFBC0, FUN_00300580, FUN_0030B5A0, FUN_0016F190,
 *   FUN_0017D800, and FUN_00289030 respectively.
 * - Unresolved retail helpers required by these bodies are FUN_002d1600,
 *   FUN_00308860, FUN_002db9f0, FUN_002dba80, FUN_002db690, FUN_002db650,
 *   FUN_002ff790, FUN_002d5550, FUN_003a3010, FUN_003c8dd0,
 *   FUN_003c8de0, FUN_003c8ea0, FUN_0029adf0, FUN_0029a380,
 *   FUN_00289650, FUN_001fdd40, and the recursive FUN_002daa20/FUN_002db2a0.
 * - FUN_002db2a0 intentionally leaves threshold unchanged when both 0x140
 *   and 0x141 are clear, matching retail's uninitialized saved-register path;
 *   normal retail call paths select one of those flags.
 */

#pragma opt_loop_invariants on
// FUN_002dc550
void FUN_002dc550(BtlAction* action, u32 flags)
{
    if (flags != 0)
    {
        u32 badStatus = datCalcGetBadStatus(action->unit->datUnit);
        u32 i;
        u32 bit;

        i = 0;
        bit = 1;
        for (; i < 0x18; i++)
        {
            u32 mask = bit << i;
            if ((flags & mask) != 0 && (badStatus & mask) == 0)
            {
                *((u8*)action + 0x462 + i) = 0;
            }
        }
    }
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002dc5e0
void FUN_002dc5e0(BtlAction* action)
{
    u32 badStatus = datCalcGetBadStatus(action->unit->datUnit);
    u32 i;
    u32 bit;

    i = 0;
    bit = 1;
    for (; i < 0x18; i++)
    {
        if ((badStatus & (bit << i)) != 0)
        {
            u8* counter = (u8*)action + 0x462 + i;
            if (*counter < 0xff)
            {
                (*counter)++;
            }
        }
    }
}
#pragma opt_loop_invariants off

// FUN_002dc670 NONMATCHING
s16 FUN_002dc670(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    s16 result = 0;

    if (datCalcGetBadStatusNoDown(datUnit) == 0x80)
    {
        u16 maxHp = datCalcGetMaxHp(datUnit);

        if ((datUnit->flags & UNIT_FLAG_ENEMY) == 0)
        {
            result = (s16)(((s32)maxHp * -100) / 500);
        }
        else
        {
            u16 tableFlags = *(u16*)(DAT_007ce410 + (u32)datUnit->id * 0x3e);
            if ((tableFlags & 0x400) != 0)
            {
                result = -0x32;
            }
            else if ((tableFlags & 0x800) != 0)
            {
                result = -100;
            }
            else if ((tableFlags & 0x1000) != 0)
            {
                result = -0x96;
            }
            else if ((tableFlags & 0x2000) != 0)
            {
                result = -0xc8;
            }
            else
            {
                result = (s16)(((s32)maxHp * -100) / 0x14d);
            }

            if (result > 999)
            {
                result = 999;
            }
        }
    }

    if (datCalcIsDead(datUnit, result) != 0)
    {
        result = (s16)(-((s32)(u16)datCalcGetHp(datUnit) - 1));
    }

    return result;
}

// FUN_002dc830 NONMATCHING
s32 FUN_002dc830(BtlAction* action)
{
    BtlUnit* unit;
    s32 result;
    u32 status;

    if ((action->unk_1a & 1) == 0)
    {
        return -1;
    }

    unit = action->unit;
    result = -1;
    status = datCalcGetBadStatusNoDown(unit->datUnit);

    if (status == 0x200)
    {
        if (action->target.commandId == 0xb ||
            action->target.commandId == 8 ||
            action->target.commandId == 7)
            result = 0x14;
    }
    else if (status == 0x40)
    {
        if (action->target.commandId == 0xb) result = 0xc;
    }
    else if (status == 0x20)
    {
        if (action->target.commandId == 0xb) result = 10;
    }
    else if (status == 0x10)
    {
        if (*(u8*)((u8*)action + 0x28) == 0 &&
            *(u8*)((u8*)action + 0x29) == 0)
            result = 0x12;
    }
    else if (status == 8)
    {
        if (action->target.commandId == 0xb ||
            action->target.commandId == 8 ||
            action->target.commandId == 7)
            result = 0x10;
        else if (action->target.commandId == 0xc ||
                 action->target.commandId == 6)
            result = 0xe;
    }
    else if (status == 1)
    {
        result = 8;
        if (action->target.commandId == 1) result = 6;
    }

    if (result >= 0 && unit->genus != 0)
        result++;
    return result;
}

// FUN_002dca60 NONMATCHING
s32 FUN_002dca60(BtlAction* action)
{
    BtlUnit* unit;
    s32 result;

    if ((action->unk_1a & 1) == 0)
    {
        return -1;
    }

    unit = action->unit;
    result = -1;
    switch (datCalcGetBadStatusNoDown(unit->datUnit))
    {
        case 0x200: result = 0x38; break;
        case 0x100: result = 0x36; break;
        case 0x40: result = 0x34; break;
        case 0x20: result = 0x32; break;
        case 0x10: result = 0x30; break;
        case 8: result = 0x2e; break;
        case 4: result = 0x2c; break;
        case 2: result = 0x2a; break;
        case 1: result = 0x28; break;
        default: break;
    }

    if (result >= 0 && unit->genus != 0)
    {
        result++;
    }
    return result;
}

#pragma opt_loop_invariants on
// FUN_002dcbc0
void FUN_002dcbc0(void)
{
    u16 i;
    s32 empty;
    u8 state;

    *(u16*)((u8*)gBtl + 0xa90) = 5;
    empty = -1;
    *(s8*)((u8*)gBtl + 0xa92) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++)
    {
        u32 offset = ((u32)i & 0xffff) * 6;
        *(s16*)((u8*)gBtl + 0xa94 + offset) = empty;
        *(s16*)((u8*)gBtl + 0xa96 + offset) = empty;
        *(u8*)((u8*)gBtl + 0xa98 + offset) = state;
    }
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_002dcc40
void FUN_002dcc40(void)
{
    s8* counter;
    u16 i;

    counter = (s8*)((u8*)gBtl + 0xa92);
    if (*counter >= 0)
    {
        (*counter)++;
        if (*counter >= 3)
        {
            *(s8*)((u8*)gBtl + 0xa92) = -1;
        }
    }

    for (i = 0; i < 0x10; i++)
    {
        counter = (s8*)gBtl;
        {
            u32 offset = ((u32)i & 0xffff) * 6;
            u8* slot = (u8*)counter + offset;
            counter = (s8*)(slot + 0xa98);

            if (*counter >= 0)
            {
                (*counter)++;
                if (*counter >= 3)
                {
                    *(s16*)((u8*)gBtl + 0xa94 + offset) = -1;
                    *(s16*)((u8*)gBtl + 0xa96 + offset) = -1;
                    *(s8*)((u8*)gBtl + 0xa98 + offset) = -1;
                }
            }
        }
    }
}
#pragma opt_loop_invariants off

// FUN_002dcd20
void FUN_002dcd20(void)
{
}

// FUN_002d1c20
u32 FUN_002d1c20(void* data)
{
    u8* state = (u8*)data;
    u32 result;

    if (((BtlTargetScriptWork*)state)->started == 0)
    {
        BtlTargetScriptWork* work = (BtlTargetScriptWork*)state;

        FUN_002C6F50(work->action, &work->action->target,
                     work->script, work->procedureIndex);
        *((u8*)work->action + 0x68) = 1;
        work->started = 1;
        goto return_zero;
    }
    else
    {
        state = (u8*)&((BtlTargetScriptWork*)state)->action->target;
        if (state[0x30] == 0)
        {
            result = 1;
        }
        else
        {
            KwlnTask* task = *(KwlnTask**)(state + 0x4c);

            if (task == NULL)
            {
                result = 1;
            }
            else
            {
                result = FUN_00195460(task);
                if (result == 0)
                {
                    state[0x30] = 0;
                    *(u32*)(state + 0x4c) = 0;
                    result = 1;
                }
                else
                {
                    result = 0;
                }
            }
        }
    }

    if (result == 0)
    {
        goto return_zero;
    }
    return 1;

return_zero:
    return 0;
}


// FUN_002d1d00
BtlPacket* FUN_002d1d00(BtlAction* action, u16 mode,
                         const char* procedureName)
{
    BtlPacket* packet = FUN_0027EC10(0xd00, 0x10);
    BtlTargetScriptWork* work;

    packet->unk_47 &= 0xee;
    packet->updateFunc = FUN_002d1c20;
    work = (BtlTargetScriptWork*)packet->workData;
    switch (mode)
    {
        case 1:
            work->script = (ScrHeader*)(uintptr_t)uGpffffb7dc;
            break;
        case 2:
            work->script = (ScrHeader*)(uintptr_t)uGpffffb7e0;
            break;
    }
    work->action = action;
    work->procedureIndex = scrFindPrcdIdxByName(work->script, procedureName);
    work->started = 0;
    return packet;
}


// FUN_002d20a0
u32 FUN_002d20a0(const RwV3d* projected, f32* screen)
{
    RwCamera* camera;
    RwV3d cameraPoint;
    f32 nearPlane;
    f32 farPlane;
    f32 x;
    f32 y;

    camera = kwlnGetMainCamera();
    RwV3dTransformPoint(&cameraPoint, projected,
                        (RwMatrix*)((uintptr_t)camera + 0x20));

    camera = kwlnGetMainCamera();
    nearPlane = camera->nearPlane;
    camera = kwlnGetMainCamera();
    farPlane = camera->farPlane;

    if ((cameraPoint.z <= nearPlane) || !(cameraPoint.z < farPlane))
    {
        return 0;
    }

    x = (cameraPoint.x / cameraPoint.z) * 640.0f;
    y = (cameraPoint.y / cameraPoint.z) * 448.0f;
    if ((x < -640.0f) || !(x <= 1280.0f) ||
        (y < -448.0f) || !(y <= 896.0f))
    {
        return 0;
    }

    screen[0] = x;
    screen[1] = y;
    return 1;
}


// FUN_002d25c0 NONMATCHING
s32 FUN_002d25c0(const u8* param_1, const u8* param_2)
{
    s32 result;
    s32 i;
    u8* list;

    result = 0;
    list = *(u8**)(iGpffffb6fc + 0x2cc);
    do
    {
        if ((list == NULL) || (result != 0))
        {
            return result;
        }

        for (i = 0; i < 4; i++)
        {
            u8* cell = list + i * 0x130;
            const f32* cellPoint = (const f32*)(cell + 8);

            if ((0.0f < *(f32*)(cell + 0x1c)) &&
                ((const u8*)cellPoint != param_1) &&
                ((const u8*)cellPoint != param_2))
            {
                RwV2d delta;
                const f32* otherPoint;
                s32 side1;
                s32 side2;

                delta.x = *(f32*)(cell + 0x10) - *(const f32*)(param_1 + 8);
                delta.y = *(f32*)(cell + 0x14) - *(const f32*)(param_1 + 0xc);
                if (!(RwV2dLength(&delta) < 1.0f))
                {
                    delta.x = *(f32*)(cell + 0x10) - *(const f32*)(param_2 + 8);
                    delta.y = *(f32*)(cell + 0x14) - *(const f32*)(param_2 + 0xc);
                    if (!(RwV2dLength(&delta) < 1.0f))
                    {
                        otherPoint = *(const f32**)(cell + 0x18);
                        side1 = FUN_002d2990(cellPoint, otherPoint,
                                             (const f32*)(param_1 + 8));
                        side2 = FUN_002d2990(cellPoint, otherPoint,
                                             (const f32*)(param_2 + 8));
                        if (side1 != side2)
                        {
                            side1 = FUN_002d2990((const f32*)(param_1 + 8),
                                                 (const f32*)(param_2 + 8),
                                                 cellPoint);
                            side2 = FUN_002d2990((const f32*)(param_1 + 8),
                                                 (const f32*)(param_2 + 8),
                                                 otherPoint);
                            if (side1 != side2)
                            {
                                result = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (result == 0)
        {
            if ((((*(const f32*)(param_1 + 8) <= *(f32*)(list + 8)) ||
                  (*(const f32*)(param_1 + 0xc) <= *(f32*)(list + 0xc))) ||
                 ((*(f32*)(list + 0x268) <= *(const f32*)(param_1 + 8)) ||
                  (*(f32*)(list + 0x26c) <= *(const f32*)(param_1 + 0xc)))) &&
                (((*(const f32*)(param_2 + 8) <= *(f32*)(list + 8)) ||
                  (*(const f32*)(param_2 + 0xc) <= *(f32*)(list + 0xc))) ||
                 ((*(f32*)(list + 0x268) <= *(const f32*)(param_2 + 8)) ||
                  (*(f32*)(list + 0x26c) <= *(const f32*)(param_2 + 0xc)))))
            {
                for (i = 0; i < 4; i++)
                {
                    const f32* edgeA =
                        (const f32*)(list + (((i + 1U) & 3) * 0x130) + 8);
                    const f32* edgeB = (const f32*)(list + i * 0x130 + 8);
                    s32 side1 = FUN_002d2990(edgeB, edgeA,
                                             (const f32*)(param_1 + 8));
                    s32 side2 = FUN_002d2990(edgeB, edgeA,
                                             (const f32*)(param_2 + 8));

                    if (side1 != side2)
                    {
                        side1 = FUN_002d2990((const f32*)(param_1 + 8),
                                             (const f32*)(param_2 + 8), edgeB);
                        side2 = FUN_002d2990((const f32*)(param_1 + 8),
                                             (const f32*)(param_2 + 8), edgeA);
                        if (side1 != side2)
                        {
                            result = 1;
                            break;
                        }
                    }
                }
            }
        }

        list = *(u8**)(list + 0x4cc);
    } while (1);
}
