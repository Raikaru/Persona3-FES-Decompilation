#include "Main/Battle/Data/datCalc.h"
#include "Main/g_data.h"
#include "Kosaka/k_assert.h"
#include "Graphics/Effect/effMisc.h"
typedef struct DatCalcEnemy
{
    u8 unk_00[4];
    u16 hp;
    u8 unk_06[8];
    u16 skills[8];
    u8 unk_1e[0x20];
} DatCalcEnemy;

typedef struct DatCalcEquipmentEffect
{
    u8 unk_00[0x1c];
    u32 skillId;
    u8 unk_20[4];
} DatCalcEquipmentEffect;

typedef struct DatCalcWeapon
{
    u8 unk_00[4];
    u32 category;
    u8 unk_08[0x20];
} DatCalcWeapon;

extern DatCalcEnemy* D_007CE410;
extern u16 func_0016cc00(s16 pcId);
extern DatCalcWeapon* func_00170d60(s16 weaponId);
extern DatCalcEquipmentEffect* func_00170e40(s16 equipmentId);
extern const char D_0069aa80[];
u32 datCalc00308ba0(void);
u16* func_00308bb0(DatUnit* unit);

static u32 sPrevPercentRand; // 007ce510

// FUN_002ffbc0
u32 datCalcRand(u32 max)
{
    u32 rand;

    K_ASSERT(max != 0, 26);

    if (max == DATCALC_RAND_PERCENT)
    {
        rand = (((effMiscRand(NULL) % 4096) + (effMiscRand(NULL) % 4096)) % 4096) / 41;
        
        if (sPrevPercentRand >= rand - 3 && 
            sPrevPercentRand <= rand + 3)
        {
            rand = (((effMiscRand(NULL) % 4096) + (effMiscRand(NULL) % 4096)) % 4096) / 41;
        }

        sPrevPercentRand = rand;
    }
    else
    {
        rand = effMiscRand(NULL) % max;
    }

    return rand;
}

// FUN_002ffcc0
u8 datCalcGetLevel(DatUnit* unit){
    u8 level;
    DatPersonaWork* persona;

    if (unit->flags & UNIT_FLAG_ENEMY || IS_HERO(unit->id))
    {
        level = unit->level;
    }
    else
    {
        persona = datPersonaGetByPcId(unit->id);
        K_ASSERT(persona != NULL, 66);

        level = datPersonaGetLevel(persona);
    }

    K_ASSERT(level > 0, 70);

    return level;
}

// FUN_002ffd70
u16 datCalcGetHp(DatUnit* unit)
{
    return unit->hp;
}

// FUN_002ffd80
u16 datCalcGetSp(DatUnit* unit)
{
    return unit->sp;
}

// FUN_002ffd90
void datCalcSetHp(DatUnit* unit, u16 hp)
{
    if (hp > 999 && !(unit->flags & UNIT_FLAG_ENEMY))
    {
        hp = 999;
    }

    unit->hp = hp;
}

// FUN_002ffdc0
void datCalcSetSp(DatUnit* unit, u16 sp)
{
    if (sp > 999 && !(unit->flags & UNIT_FLAG_ENEMY))
    {
        sp = 999;
    }

    unit->sp = sp;
}

// FUN_002ffdf0 NONMATCHING
u16 datCalcGetMaxHp(DatUnit* unit)
{
    u16 pcId;
    u16 baseHp;
    s32 bonus;
    s32 hp;

    pcId = unit->id;
    bonus = 0;

    if (unit->flags & UNIT_FLAG_ENEMY)
    {
        K_ASSERT(pcId < 0x150, 169);
        baseHp = D_007CE410[pcId].hp;
    }
    else
    {
        K_ASSERT(pcId < PC_MAX, 172);
        baseHp = func_0016cc00((s16)pcId);
    }

    if (datCalcHasSkill(unit, 0x219))
    {
        bonus += (baseHp * 10) / 100;
    }
    if (datCalcHasSkill(unit, 0x21a))
    {
        bonus += (baseHp * 20) / 100;
    }
    if (datCalcHasSkill(unit, 0x21b))
    {
        bonus += (baseHp * 30) / 100;
    }
    if (datCalcHasSkill(unit, 0x26c))
    {
        bonus += (baseHp * 50) / 100;
    }
    if (datCalcHasSkill(unit, 0x237))
    {
        bonus += baseHp;
    }
    if (datCalcHasSkill(unit, 0x238))
    {
        bonus -= (baseHp * 50) / 100;
    }

    hp = baseHp + bonus;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x1a) * 10;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x1b) * 20;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x1c) * 30;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x1d) * 40;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x1e) * 50;
    hp += (u16)datCalcCountEquipmentWithEffect(unit, 0x8e) * 100;

    if (!(unit->flags & UNIT_FLAG_ENEMY) && hp >= 1000)
    {
        hp = 999;
    }

    return (u16)hp;
}

// FUN_003004f0
u32 datCalcSetBadStatus(DatUnit* unit, u32 badStatus)
{
    u32 low;

    low = badStatus & 0x000FFFFF;

    if (low != 0)
    {
        unit->bad = (unit->bad & 0xFFF00000) | low;
    }

    return unit->bad |= (badStatus & 0xFFF00000);
}

// FUN_00300530
u32 datCalcGetBadStatusNoDown(DatUnit* unit)
{
    return unit->bad & 0x000FFFFF;
}

// FUN_00300550
u32 datCalcGetBadStatus(DatUnit* unit)
{
    return unit->bad;
}

// FUN_00300560
u32 datCalcClearBadStatus(DatUnit* unit, u32 badStatus)
{
    return unit->bad &= ~badStatus;
}

// FUN_00300580
u32 datCalcChkBadStatus(DatUnit* unit, u32 badStatus)
{
    return (unit->bad & badStatus) != 0;
}

// FUN_003005e0 NONMATCHING
u32 datCalcHasSkill(DatUnit* unit, u16 skillId)
{
    DatCalcEquipmentEffect* accessoryEffect;
    u16* skills;
    u16 count;
    u16 i;
    s16 pcId;
    s16 equipmentIdx;
    u16 equipmentId;

    count = (u16)datCalc00308ba0();
    skills = func_00308bb0(unit);

    for (i = 0; i < count; i++)
    {
        if (skills[i] == skillId)
        {
            return 1;
        }
    }

    if (unit->flags & UNIT_FLAG_ENEMY)
    {
        return 0;
    }

    pcId = (s16)unit->id;
    equipmentIdx = datGetEquipmentIdx(pcId, EQUIPMENT_TYPE_ACCESSORY);
    if (equipmentIdx < 0)
    {
        return 0;
    }

    equipmentId = datGetEquipmentId(pcId, equipmentIdx);
    accessoryEffect = func_00170e40((s16)equipmentId);

    if (accessoryEffect != NULL && accessoryEffect->skillId == skillId)
    {
        return 1;
    }

    return 0;
}

// FUN_00300870
u16 datCalcCountEquipmentWithEffectById(u16 pcId, u16 effect)
{
    u16 count;
    s16 equipmentIdx;
    u8 equipmentEffect;
    u32 effectId;
    s16 firstPcId;

    K_ASSERT(pcId < PC_MAX, 646);

    count = 0;
    firstPcId = (s16)pcId;
    effectId = effect;

    equipmentIdx = datGetEquipmentIdx(firstPcId, EQUIPMENT_TYPE_WEAPON);
    equipmentEffect = datGetEquipmentEffect(firstPcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    equipmentIdx = datGetEquipmentIdx((s16)pcId, EQUIPMENT_TYPE_ARMOR);
    equipmentEffect = datGetEquipmentEffect((s16)pcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    equipmentIdx = datGetEquipmentIdx((s16)pcId, EQUIPMENT_TYPE_BOOTS);
    equipmentEffect = datGetEquipmentEffect((s16)pcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    return count;
}

// FUN_003009a0
u16 datCalcCountEquipmentWithEffect(DatUnit* unit, u16 effect)
{
    u16 pcId;
    u16 count;
    s16 equipmentIdx;
    u8 equipmentEffect;
    u32 effectId;
    s16 firstPcId;

    if (unit->flags & UNIT_FLAG_ENEMY)
    {
        return 0;
    }

    pcId = unit->id;
    K_ASSERT(pcId < PC_MAX, 646);

    count = 0;
    firstPcId = (s16)pcId;
    effectId = effect;

    equipmentIdx = datGetEquipmentIdx(firstPcId, EQUIPMENT_TYPE_WEAPON);
    equipmentEffect = datGetEquipmentEffect(firstPcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    equipmentIdx = datGetEquipmentIdx((s16)pcId, EQUIPMENT_TYPE_ARMOR);
    equipmentEffect = datGetEquipmentEffect((s16)pcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    equipmentIdx = datGetEquipmentIdx((s16)pcId, EQUIPMENT_TYPE_BOOTS);
    equipmentEffect = datGetEquipmentEffect((s16)pcId, equipmentIdx);
    if (effectId == equipmentEffect)
    {
        count++;
    }

    return count;
}

// FUN_00300d80
u32 datCalcGetPassiveSkillFlags(DatUnit* unit)
{
    u32 flags;

    flags = 0;

    if (datCalcHasSkill(unit, SKILL_REGENERATE1))
    {
        flags |= PASSIVESKILL_FLAG_REGENERATE1;
    }
    if (datCalcHasSkill(unit, SKILL_REGENERATE2))
    {
        flags |= PASSIVESKILL_FLAG_REGENERATE2;
    }
    if (datCalcHasSkill(unit, SKILL_REGENERATE3))
    {
        flags |= PASSIVESKILL_FLAG_REGENERATE3;
    }

    if (datCalcHasSkill(unit, SKILL_INVIGORATE1))
    {
        flags |= PASSIVESKILL_FLAG_INVIGORATE1;
    }
    if (datCalcHasSkill(unit, SKILL_INVIGORATE2))
    {
        flags |= PASSIVESKILL_FLAG_INVIGORATE2;
    }
    if (datCalcHasSkill(unit, SKILL_INVIGORATE3))
    {
        flags |= PASSIVESKILL_FLAG_INVIGORATE3;
    }

    if (datCalcHasSkill(unit, SKILL_SPRINGOFLIFE1))
    {
        flags |= PASSIVESKILL_FLAG_SPRINGOFLIFE1;
    }
    if (datCalcHasSkill(unit, SKILL_SPRINGOFLIFE2))
    {
        flags |= PASSIVESKILL_FLAG_SPRINGOFLIFE2;
    }

    return flags;
}

// FUN_00308ba0
u32 datCalc00308ba0(void)
{
    return 8;
}

// FUN_00308c60
u32 datCalcGetHeldWeaponType(DatUnit* unit)
{
    s16 weaponIdx;
    u16 weaponId;
    DatCalcWeapon* weapon;
    u32 category;

    if (unit->flags & UNIT_FLAG_ENEMY)
    {
        return WEAPON_TYPE_1H_SWORD;
    }

    switch (unit->id)
    {
        case PC_HERO:
            weaponIdx = datGetEquipmentIdx(PC_HERO, EQUIPMENT_TYPE_WEAPON);
            weaponId = datGetEquipmentId(PC_HERO, weaponIdx);
            weapon = func_00170d60((s16)weaponId);
            category = weapon->category;

            switch (category)
            {
                case 0x1:
                case 0x100:
                    return WEAPON_TYPE_2H_SWORD;
                case 0x2:
                case 0x200:
                    return WEAPON_TYPE_1H_SWORD;
                case 0x4:
                case 0x400:
                    return WEAPON_TYPE_BOW;
                case 0x8:
                case 0x800:
                    return WEAPON_TYPE_SPEAR;
                case 0x10:
                case 0x1000:
                    return WEAPON_TYPE_AXE;
                case 0x20:
                case 0x2000:
                    return WEAPON_TYPE_FIST;
                case 0x40:
                case 0x4000:
                    return WEAPON_TYPE_GUN;
                case 0x80:
                case 0x8000:
                    return WEAPON_TYPE_KNIFE;
                default:
                    K_ASSERT(false, 4237);
                    goto default_weapon_type;
            }
        case PC_YUKARI:
            return WEAPON_TYPE_BOW;
        case PC_AIGIS:
            return WEAPON_TYPE_GUN;
        case PC_MITSURU:
            return WEAPON_TYPE_1H_SWORD;
        case PC_JUNPEI:
            return WEAPON_TYPE_2H_SWORD;
        case PC_FUUKA:
            return WEAPON_TYPE_1H_SWORD;
        case PC_AKIHIKO:
            return WEAPON_TYPE_FIST;
        case PC_KEN:
            return WEAPON_TYPE_SPEAR;
        case PC_SHINJIRO_OR_METIS:
            return WEAPON_TYPE_AXE;
        case PC_KOROMARU:
            return WEAPON_TYPE_KNIFE;
        default:
            K_ASSERT(false, 4259);
default_weapon_type:
            return WEAPON_TYPE_1H_SWORD;
    }
}

// FUN_0030b5a0
u32 datCalcIsDead(const DatUnit* unit, s32 hpDelta)
{
    if (unit->bad & UNIT_BADSTATUS_DEAD ? 1 : 0)
    {
        return true;
    }

    return (unit->hp + hpDelta) <= 0;
}

// FUN_0030b5e0
u32 datCalcIsLowHp(DatUnit* unit)
{
    u16 hp;

    hp = unit->hp;

    return ((hp * 100) / datCalcGetMaxHp(unit)) < 26; // is hp below 26%
}

extern f32 sqrtf(f32);
extern u32 FUN_0016c5f0();
extern u32 FUN_0016c670();
extern u32 FUN_0016c920();
extern u32 FUN_0016cb80();
extern u32 FUN_0016ccb0();
extern u32 FUN_0016cf40();
extern u32 FUN_0016cf90();
extern u32 FUN_0016d9d0();
extern u32 FUN_0016f190();
extern u32 FUN_0016f630();
extern u32 FUN_0016f900();
extern u32 FUN_0016f9f0();
extern u32 FUN_0016fae0();
extern u32 FUN_0016fbd0();
extern u32 FUN_0016fcc0();
extern u32 FUN_00170760();
extern u32 FUN_00170d60();
extern u32 FUN_00170e40();
extern u32 FUN_00170e90();
extern u32 FUN_00173380();
extern u32 FUN_00173460();
extern u32 FUN_00173510();
extern u32 FUN_001738d0();
extern u32 FUN_00174960();
extern u32 FUN_00174a90();
extern u32 FUN_001752b0();
extern u32 FUN_00175410();
extern u32 FUN_0017d800();
extern u32 FUN_00181b10();
extern u32 FUN_0019d3f0();
extern u32 FUN_002ffbc0();
extern u32 FUN_002ffcc0();
extern u32 FUN_002ffd70();
extern u32 FUN_002ffdf0();
extern u32 FUN_003004f0();
extern u32 FUN_003004F0();
extern u32 FUN_00300530();
extern u32 FUN_00300550();
extern u32 FUN_00300560();
extern u32 FUN_00300580();
extern u32 FUN_003005E0();
extern u32 FUN_003005e0();
extern u32 FUN_00300870();
extern u32 FUN_003009a0();
extern u32 FUN_003009A0();
extern u32 FUN_00300D80();
extern u32 FUN_00300d80();
extern u32 FUN_00308ba0();
extern u32 FUN_00308BA0();
extern u32 FUN_00308C60();
extern u32 FUN_00308c60();
extern u32 FUN_0030B5A0();
extern u32 FUN_0030b5a0();
extern u32 FUN_0030b5e0();
extern u32 FUN_0030B5E0();
extern u32 FUN_00311190(int);
#pragma alias FUN_00311190_typed FUN_00311190
extern void FUN_00311190_typed(u32);
extern u32 FUN_003111f0();
extern u32 FUN_00311250();
extern void FUN_0035f080(float);
extern u32 FUN_003951d0();
u32 FUN_00300100(u32 param_1);
s32 FUN_00300410(DatUnit *unit,s32 hpDelta);
s32 FUN_00300480(DatUnit *unit,s32 spDelta);
u32 FUN_003005a0(u16* param);
u8 FUN_00300700(u16 *param_1,s16 param_2);
u8 FUN_00300750(u16 param_1,u16 param_2);
s32 FUN_00300af0(s32 param_1);
u8 FUN_00300b60(u16 *param_1,u32 param_2);
u8 FUN_00300c90(u32 param_1,u32 param_2);
u32 FUN_00300e90(u32 param_1);
s8 FUN_00300f60(int param_1,u32 param_2);
void FUN_00301030(int param_1,u32 param_2,u8 param_3);
void FUN_00301150(int param_1,u8 param_2,s8 param_3);
u8 FUN_00301230(int param_1,u32 param_2,char param_3);
void FUN_00301540(int param_1,u32 param_2);
void FUN_00301690(u32 param_1);
s8 FUN_00301750(int param_1,u32 param_2);
void FUN_00301870(int param_1);

float FUN_00301880(u32 param_1,u32 param_2);
u8 FUN_00301ca0(u32 param_1,u32 param_2);
void FUN_00302380(u32 param_1,u32 param_2,u32 param_3);
void FUN_00302c50(u32 param_1);

void FUN_00302d40(u32 param_1);
u8 FUN_00302f50(u32 param_1);

u32 FUN_00303130(u32 param_1,u32 param_2,u32 param_3,u16 param_4,short param_5,
                 short param_6,u32 param_7,char param_8);

u32 FUN_00305970(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_00306020(u32 param_1,u32 param_2,u32 param_3,short param_4);
u32 FUN_00306510(u32 param_1,u32 param_2,u32 param_3,u16 param_4);
u32 FUN_00306610(u32 param_1,s32 param_2,s32 param_3,u32 param_4);
u32 FUN_003068d0(u32 param_1,s32 param_2,s32 param_3,u32 param_4);
u32
FUN_00306bc0(u32 param_1,s32 param_2,s32 param_3,u32 param_4,s32 param_5,s32 param_6,
            s32 param_7);
u32 FUN_00306d90(u16 param_1,u32 param_2);
u32 FUN_00306e80(s32 param_1,s32 param_2);
int FUN_003080c0(short param_1);
short FUN_00308120(short param_1,int param_2);
s32 FUN_003082f0(s32 param_1,u32 param_2);
#pragma alias FUN_003082f0_one FUN_003082f0
extern s32 FUN_003082f0_one(s32 param_1);
u32 FUN_003083f0(u32 param_1,u32 param_2);
u8 FUN_003086c0(void *param_1,u32 param_2);
u32 FUN_003086f0(u32 param_1,u32 param_2);
u32 FUN_00308860(u16 param_1);
u8 FUN_003088b0(u16 param_1);
u16 FUN_00308930(u16 *param_1);
u8 FUN_00308a50(u16 param_1);
u16 FUN_00308a80(u32 param_1);
int FUN_00308bb0(u16 *param_1);
u16 FUN_00308ed0(u16 *param_1);
u8 FUN_00308f80(u16 *param_1);
u8 FUN_00308fd0(u16 *param_1,u16 param_2);
u32 FUN_00309080(u16 *param_1,char param_2);
u32 FUN_00309250(u16 *param_1,char param_2);
u8 FUN_003093a0(u16 *param_1);
u32 FUN_00309490(s32 param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_0030a740(s32 param_1,u32 param_2,u32 param_3,short param_4);
u32 FUN_0030af00(s32 param_1,u16 *param_2,u32 param_3,u32 param_4,u32 param_5);
u32
FUN_0030b130(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5);
u32 FUN_0030b210(u32 param_1,int param_2,u16 param_3,short param_4);
u32 FUN_0030b4b0(u32 param_1,u32 param_2);
u32 FUN_0030b640(s32 param_1,u32 param_2);
u32 FUN_0030b9a0(u32 param_1,u16 param_2,u16 param_3);
int FUN_0030bb40(u16 param_1);
int FUN_0030bbb0(u8 param_1);
u16 FUN_0030bc20(s16 param_1);

u32 FUN_0030bc50(int param_1);
short FUN_0030bde0(u16 *param_1,s32 param_2);
int FUN_0030c0c0(void);
s32 FUN_0030c220(s32 param_1);
u8 FUN_0030c2a0(u32 param_1);
u32 FUN_0030c3a0(u16 *param_1);
void FUN_0030c440(void);
void FUN_0030c490(u16 param_1);
void FUN_0030c520(void);
void FUN_0030c930(void);
void FUN_0030cb90(void);
void FUN_0030cc40(void);
void FUN_0030cdb0(void);
void FUN_0030cec0(void);
void FUN_0030cf00(void);
void FUN_0030d000(void);
void FUN_0030d0e0(void);
void FUN_0030d1c0(void);
void FUN_0030d2a0(void);
void FUN_0030d380(void);
void FUN_0030d460(void);
void FUN_0030d4a0(void);
void FUN_0030d4e0(void);
void FUN_0030d610(void);
void FUN_0030d760(void);
void FUN_0030db80(void);
void FUN_0030ddf0(void);
void FUN_0030dec0(void);
void FUN_0030e030(void);
void FUN_0030e140(void);
void FUN_0030e180(void);
void FUN_0030e280(void);
void FUN_0030e360(void);
void FUN_0030e440(void);
void FUN_0030e520(void);
void FUN_0030e600(void);
void FUN_0030e6e0(void);
void FUN_0030e720(void);
void FUN_0030e760(void);
void FUN_0030e8a0(void);
void FUN_0030ea00(void);
void FUN_0030ee10(void);
void FUN_0030f070(void);
void FUN_0030f120(void);
void FUN_0030f290(void);
void FUN_0030f3a0(void);
void FUN_0030f3e0(void);
void FUN_0030f4e0(void);
void FUN_0030f5c0(void);
void FUN_0030f6a0(void);
void FUN_0030f780(void);
void FUN_0030f860(void);
void FUN_0030f940(void);
void FUN_0030f980(void);
void FUN_0030f9c0(void);
void FUN_0030faf0(void);
u32
FUN_0030fc40(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
            u32 param_5);
u32 FUN_0030fdc0(void);

float FUN_0030fdf0(int param_1,u32 param_2);
extern f32 DAT_007cad74;
extern f32 DAT_007cad8c;
extern f32 DAT_007cadb4;
extern u32 DAT_007cae84;
extern u32 DAT_007caf8c;
extern u32 DAT_007ce3ec;
extern u32 DAT_007ce3f4;
extern u32 DAT_007ce3f8;
extern u32 DAT_007ce3fc;
extern u32 DAT_007ce410;
extern u32 DAT_007ce414;
extern u32 DAT_007ce46c;
extern u32 DAT_007ce470;
extern u32 DAT_007ce478;
extern u32 DAT_007ce47c;
extern u32 DAT_00957190;
extern u32 DAT_00957194;
extern u32 DAT_00957198;
extern u32 DAT_0095719c;
extern u32 DAT_009571a0;
extern u32 DAT_009571a4;
extern void (*PTR_LAB_0069aa90[])(void);
extern void (*PTR_LAB_0069aae0[])(void);
extern void (*PTR_LAB_0069ab30[])(void);
extern f32 fGpffff8070;
extern f32 fGpffff8084;
extern f32 fGpffff8088;
extern f32 fGpffff80a4;
extern f32 fGpffff80c4;
extern f32 fGpffff80e0;
extern f32 fGpffff8194;
extern f32 fGpffff8278;
extern f32 fGpffff829c;
extern f32 fGpffff82a0;
extern f32 fGpffff82a4;
extern f32 fGpffff82a8;
extern f32 fGpffff82ac;
extern u32 gp0xffff9d08;
extern u32 iGpffffb704;
extern u32 iGpffffb708;
extern u32 iGpffffb720;
extern u32 iGpffffb790;
extern u32 iGpffffb79c;
extern u32 iGpffffb7a4;
extern u32 iGpffffb7a8;
extern u32 iGpffffb7fc;
extern u32 iGpffffb800;

// FUN_00300100 NONMATCHING
u32 FUN_00300100(u32 param_1)

{
  u16 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  s32 lVar8;
  u32 uVar9;
  u16 *puVar10;
  u32 uVar11;
  
  uVar11 = 0;
  puVar10 = (u16 *)param_1;
  uVar1 = puVar10[1];
  if ((*puVar10 & 4) == 0) {
    if (10 < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0xc6);
    }
    uVar9 = FUN_0016ccb0(uVar1);
    uVar9 = uVar9 & 0xffff;
  }
  else {
    if (0x14f < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0xc3);
    }
    uVar9 = (u32)*(u16 *)((u32)uVar1 * 0x3e + DAT_007ce410 + 6);
  }
  lVar8 = FUN_003005e0(param_1,0x21c);
  if (lVar8 != 0) {
    uVar11 = (uVar9 * 10) / 100;
  }
  lVar8 = FUN_003005e0(param_1,0x21d);
  if (lVar8 != 0) {
    uVar11 = uVar11 + (uVar9 * 0x14) / 100;
  }
  lVar8 = FUN_003005e0(param_1,0x21e);
  if (lVar8 != 0) {
    uVar11 = uVar11 + (uVar9 * 0x1e) / 100;
  }
  lVar8 = FUN_003005e0(param_1,0x26d);
  if (lVar8 != 0) {
    uVar11 = uVar11 + (uVar9 * 0x32) / 100;
  }
  lVar8 = FUN_003005e0(param_1,0x237);
  if (lVar8 != 0) {
    uVar11 = uVar11 - (uVar9 * 0x32) / 100;
  }
  lVar8 = FUN_003005e0(param_1,0x238);
  if (lVar8 != 0) {
    uVar11 = uVar11 + uVar9;
  }
  uVar2 = FUN_003009a0(param_1,0x1f);
  uVar3 = FUN_003009a0(param_1,0x20);
  uVar4 = FUN_003009a0(param_1,0x21);
  uVar5 = FUN_003009a0(param_1,0x22);
  uVar6 = FUN_003009a0(param_1,0x23);
  uVar7 = FUN_003009a0(param_1,0x8f);
  uVar9 = uVar9 + uVar11 + (uVar2 & 0xffff) * 10 + (uVar3 & 0xffff) * 0x14 + (uVar4 & 0xffff) * 0x1e
                  + (uVar5 & 0xffff) * 0x28 + (uVar6 & 0xffff) * 0x32 + (uVar7 & 0xffff) * 100;
  if (((*puVar10 & 4) == 0) && (999 < (int)uVar9)) {
    uVar9 = 999;
  }
  return uVar9 & 0xffff;
}





// FUN_00300410
s32 FUN_00300410(DatUnit *unit,s32 hpDelta)

{
  s32 maxHp;
  s32 newHp;

  newHp = unit->hp + hpDelta;
  if (newHp < 0) {
    newHp = 0;
  }
  maxHp = datCalcGetMaxHp(unit) & 0xFFFF;
  if (maxHp < newHp) {
    newHp = maxHp;
  }
  unit->hp = (u16)newHp;
  return newHp & 0xFFFF;
}





// FUN_00300480
s32 FUN_00300480(DatUnit *unit,s32 spDelta)

{
  s32 maxSp;
  s32 newSp;

  newSp = unit->sp + spDelta;
  if (newSp < 0) {
    newSp = 0;
  }
  maxSp = FUN_00300100((u32)unit) & 0xFFFF;
  if (maxSp < newSp) {
    newSp = maxSp;
  }
  unit->sp = (u16)newSp;
  return newSp & 0xFFFF;
}





// FUN_003005a0
u32 FUN_003005a0(u16* param)
{
    if ((*param & 4) != 0)
    {
        return 0;
    }

    return FUN_0016c920(((s16*)param)[1]);
}





// FUN_00300700
u8 FUN_00300700(u16 *param_1,s16 param_2)

{
  s32 found;
  
  if ((*param_1 & 4) != 0) {
    return 0;
  }
  found = (u16)FUN_00170760(*(s16 *)(param_1 + 1),param_2);
  return found > 0;
}





// FUN_00300750
u8 FUN_00300750(u16 param_1,u16 param_2)
{
  s32 pcId;
  s16 uVar2;
  u16 uVar3;
  u32 target;
  
  if ((param_1 < 11) == false) {
    FUN_0019d3f0((u32)D_0069aa80, 0x259);
  }
  pcId = (s16)param_1;
  target = param_2 & 0xffff;
  uVar2 = FUN_0016cb80(pcId,0);
  uVar3 = FUN_0016f900(pcId,uVar2);
  if (target == (uVar3 & 0xff)) {
    return true;
  }
  uVar2 = FUN_0016cb80(pcId,1);
  uVar3 = FUN_0016f900(pcId,uVar2);
  if (target == (uVar3 & 0xff)) {
    return true;
  }
  uVar2 = FUN_0016cb80((s16)param_1,2);
  uVar3 = FUN_0016f900((s16)param_1,uVar2);
  return target == (uVar3 & 0xff);
}




// FUN_00300af0
s32 FUN_00300af0(s32 param_1)

{
  s32 index;
  u8 *record;

  index = param_1 & 0xFFFF;
  if (index >= 0x1D0) {
    return 0;
  }
  record = (u8 *)iGpffffb708 + index * 0x2C;
  if (*record & 2) {
    return 0;
  }
  return (record[1] & 1) != 0;
}





// FUN_00300b60 NONMATCHING
u8 FUN_00300b60(u16 *param_1,u32 param_2)

{
  u16 uVar1;
  u8 bVar2;
  
  if (4 < (param_2 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x2e1);
  }
  uVar1 = param_1[1];
  if ((*param_1 & 4) == 0) {
    if (10 < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0x2eb);
    }
    bVar2 = FUN_00173510(uVar1,param_2);
  }
  else {
    if (0x14f < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0x2e8);
    }
    bVar2 = *(u8 *)(((u32)param_2 & 0xffff) + (u32)uVar1 * 0x3e + iGpffffb720 + 8);
  }
  if (bVar2 == 0) {
    bVar2 = 1;
  }
  else if (99 < bVar2) {
    bVar2 = 99;
  }
  return bVar2;
}





// FUN_00300c90
u8 FUN_00300c90(u32 param_1,u32 param_2)
{
  u8 bVar1;
  u16 *puVar2;
  
  if ((s32)(param_2 & 0xffff) < 0 || (s32)(param_2 & 0xffff) >= 5) {
    FUN_0019d3f0((u32)D_0069aa80, 0x304);
  }
  puVar2 = (u16 *)param_1;
  if ((*puVar2 & 4) != 0) {
    bVar1 = FUN_00300b60((u16*)param_1,param_2);
  }
  else {
    if (puVar2[1] >= 11) {
      FUN_0019d3f0((u32)D_0069aa80, 0x30b);
    }
    bVar1 = FUN_001738d0(puVar2[1],param_2);
  }
  if ((s32)bVar1 <= 0) {
    bVar1 = 1;
  }
  else if (99 < bVar1) {
    bVar1 = 99;
  }
  return bVar1;
}






// FUN_00300e90
u32 FUN_00300e90(u32 param_1)
{
  char cVar1;
  s16 uVar2;
  u32 uVar3;
  
  uVar2 = FUN_003082f0_one(0);
  uVar3 = FUN_003080c0(uVar2);
  if ((uVar3 & 0xe0001) == 0) {
    if ((uVar3 & 0xe) != 0) {
      cVar1 = FUN_00301750(param_1,0x11);
      if ('\0' < cVar1) {
        return 1;
      }
    }
    else if ((uVar3 & 0x100) == 0) {
      cVar1 = FUN_00301750(param_1,0x12);
      if ('\0' < cVar1) {
        return 1;
      }
    }
  }
  return 0;
}





// FUN_00300f60
s8 FUN_00300f60(int param_1,u32 param_2)
{
  s8 value;
  u8 index;
  u16 offset;

  if ((s32)(param_2 & 0xff) >= 0x15) {
    FUN_0019d3f0((u32)D_0069aa80,0x406);
  }
  index = param_2;
  offset = index >> 1;
  if (index & 1) {
    value = *(u8 *)(offset + param_1 + 0x1c) >> 4;
  }
  else {
    value = *(u8 *)(offset + param_1 + 0x1c) & 0xf;
  }
  if (7 < value) {
    value = (s8)(value - 0xf);
  }
  return value;
}

// FUN_00301030 NONMATCHING
void FUN_00301030(int param_1,u32 param_2,u8 param_3)
{
  int iVar1;
  
  if (0x14 < (param_2 & 0xff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x438);
  }
  if (('\a' < (char)param_3) || ((char)param_3 < -7)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x439);
  }
  iVar1 = (int)(param_2 & 0xff) >> 1;
  if ((char)param_3 < '\0') {
    param_3 = param_3 + 0xf;
  }
  if ((param_2 & 1) == 0) {
    iVar1 = iVar1 + param_1;
    *(u8 *)(iVar1 + 0x1c) = *(u8 *)(iVar1 + 0x1c) & 0xf0 | param_3 & 0xf;
  }
  else {
    iVar1 = iVar1 + param_1;
    *(u8 *)(iVar1 + 0x1c) = *(u8 *)(iVar1 + 0x1c) & 0xf | param_3 << 4;
  }
  return;
}





// FUN_00301150
void FUN_00301150(int param_1,u8 param_2,s8 param_3)
{
  u8 index;
  u16 offset;
  u8 value;
  
  index = param_2;
  if ((s32)index >= 0x15) {
    FUN_0019d3f0((u32)D_0069aa80, 0x455);
  }
  if ((char)param_3 < '\0') {
    FUN_0019d3f0((u32)D_0069aa80, 0x456);
  }
  offset = index >> 1;
  if (index & 1) {
    value = *(u8 *)(offset + param_1 + 0x29);
    *(u8 *)(offset + param_1 + 0x29) = value & 0xf | (param_3 & 0xf) << 4;
  }
  else {
    value = *(u8 *)(offset + param_1 + 0x29);
    *(u8 *)(offset + param_1 + 0x29) = value & 0xf0 | param_3 & 0xf;
  }
  return;
}





// FUN_00301230 NONMATCHING
u8 FUN_00301230(int param_1,u32 param_2,char param_3)

{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  short sVar4;
  u32 uVar5;
  
  uVar3 = param_2 & 0xff;
  if (0x14 < uVar3) {
    FUN_0019d3f0((u32)D_0069aa80, 0x46d);
  }
  sVar4 = 0;
  if (uVar3 < 0x11) {
    if (0x14 < uVar3) {
      FUN_0019d3f0((u32)D_0069aa80, 0x406);
    }
    iVar2 = (int)(param_2 & 0xff) >> 1;
    uVar5 = param_2 & 1;
    if (uVar5 == 0) {
      bVar1 = *(u8 *)(iVar2 + param_1 + 0x1c) & 0xf;
    }
    else {
      bVar1 = (u8)((int)(u32)*(u8 *)(iVar2 + param_1 + 0x1c) >> 4);
    }
    if (7 < bVar1) {
      bVar1 = bVar1 - 0xf;
    }
    if (param_3 == '\0') {
      return bVar1;
    }
    sVar4 = (short)(char)bVar1 + (short)param_3;
    if (sVar4 < 2) {
      if (sVar4 < -1) {
        sVar4 = -1;
      }
    }
    else {
      sVar4 = 1;
    }
    bVar1 = (u8)sVar4;
    if (0x14 < uVar3) {
      FUN_0019d3f0((u32)D_0069aa80, 0x438);
    }
    if (('\a' < (char)bVar1) || ((char)bVar1 < -7)) {
      FUN_0019d3f0((u32)D_0069aa80, 0x439);
    }
    if ((char)bVar1 < '\0') {
      bVar1 = bVar1 + 0xf;
    }
    if (uVar5 == 0) {
      *(u8 *)(iVar2 + param_1 + 0x1c) = *(u8 *)(iVar2 + param_1 + 0x1c) & 0xf0 | bVar1 & 0xf;
    }
    else {
      *(u8 *)(iVar2 + param_1 + 0x1c) = *(u8 *)(iVar2 + param_1 + 0x1c) & 0xf | bVar1 << 4;
    }
    if (sVar4 == 0) {
      *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & ~(1 << (param_2 & 0x1f));
    }
    else {
      *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 1 << (param_2 & 0x1f);
    }
    if (0x14 < uVar3) {
      FUN_0019d3f0((u32)D_0069aa80, 0x455);
    }
    if (uVar5 == 0) {
      *(u8 *)(iVar2 + param_1 + 0x29) = *(u8 *)(iVar2 + param_1 + 0x29) & 0xf0;
    }
    else {
      *(u8 *)(iVar2 + param_1 + 0x29) = *(u8 *)(iVar2 + param_1 + 0x29) & 0xf;
    }
  }
  else {
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 1 << (param_2 & 0x1f);
  }
  return (u8)sVar4;
}





// FUN_00301540 NONMATCHING
void FUN_00301540(int param_1,u32 param_2)

{
  int iVar1;
  u32 uVar2;
  
  uVar2 = param_2 & 0xff;
  if (0x14 < uVar2) {
    FUN_0019d3f0((u32)D_0069aa80, 0x499);
  }
  if (uVar2 < 0x11) {
    if (0x14 < uVar2) {
      FUN_0019d3f0((u32)D_0069aa80, 0x438);
    }
    iVar1 = (int)uVar2 >> 1;
    if ((param_2 & 1) == 0) {
      *(u8 *)(iVar1 + param_1 + 0x1c) = *(u8 *)(iVar1 + param_1 + 0x1c) & 0xf0;
    }
    else {
      *(u8 *)(iVar1 + param_1 + 0x1c) = *(u8 *)(iVar1 + param_1 + 0x1c) & 0xf;
    }
    if (0x14 < uVar2) {
      FUN_0019d3f0((u32)D_0069aa80, 0x455);
    }
    if ((param_2 & 1) == 0) {
      *(u8 *)(iVar1 + param_1 + 0x29) = *(u8 *)(iVar1 + param_1 + 0x29) & 0xf0;
    }
    else {
      *(u8 *)(iVar1 + param_1 + 0x29) = *(u8 *)(iVar1 + param_1 + 0x29) & 0xf;
    }
  }
  *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & ~(1 << (param_2 & 0x1f));
  return;
}





// FUN_00301690
void FUN_00301690(u32 param_1)

{
  u32 uVar1;
  
  for (uVar1 = 0; uVar1 < 0x15; uVar1 = uVar1 + 1) {
    if ((s32)(uVar1 & 0xff) < 0x15) {
    }
    else {
      FUN_0019d3f0((u32)D_0069aa80,0x499);
    }
    if ((s32)(uVar1 & 0xff) < 0x11) {
      FUN_00301030(param_1,(u8)uVar1,0);
      FUN_00301150(param_1,(u8)uVar1,0);
    }
    *(u32 *)((int)param_1 + 0x14) = *(u32 *)((int)param_1 + 0x14) & ~(1 << (uVar1 & 0xff));
  }
  return;
}





// FUN_00301750
s8 FUN_00301750(int param_1,u32 param_2)

{
  s8 nibble;
  u8 result;
  u8 index;
  u16 offset;
  s32 uVar3;

  uVar3 = param_2 & 0xff;
  if (uVar3 >= 0x15) {
    FUN_0019d3f0((u32)D_0069aa80,0x4b8);
  }
  if (uVar3 < 0x11) {
    if (uVar3 >= 0x15) {
      FUN_0019d3f0((u32)D_0069aa80,0x406);
    }
    index = param_2;
    offset = index >> 1;
    if (index & 1) {
      nibble = *(u8 *)(offset + param_1 + 0x1c) >> 4;
    }
    else {
      nibble = *(u8 *)(offset + param_1 + 0x1c) & 0xf;
    }
    if (7 < nibble) {
      nibble = (s8)(nibble - 0xf);
    }
    return nibble;
  }
  result = (*(u32 *)(param_1 + 0x14) & 1 << uVar3) != 0;
  return result;
}




// FUN_00301870
void FUN_00301870(int param_1)

{
  *(u32 *)(param_1 + 0x18) = 0;
  return;
}





// FUN_00301880 NONMATCHING

float FUN_00301880(u32 param_1,u32 param_2)

{
  u8 bVar1;
  char cVar2;
  int iVar3;
  u32 uVar4;
  u16 *puVar5;
  float fVar6;
  
  uVar4 = param_2 & 0xff;
  if (0x14 < (s32)uVar4) {
    FUN_0019d3f0(0x69aa80,0x4e8);
    FUN_0019d3f0(0x69aa80,0x4b8);
  }
  puVar5 = (u16 *)param_1;
  if ((s32)uVar4 < 0x11) {
    cVar2 = FUN_00300f60(param_1,param_2);
  }
  else {
    cVar2 = (*(u32 *)(puVar5 + 10) & 1 << ((u32)uVar4 & 0x1f)) != 0;
  }
  if ((cVar2 < -1) || ('\x01' < cVar2)) {
    FUN_0019d3f0(0x69aa80,0x4ec);
  }
  bVar1 = (*puVar5 & 4) != 0;
  fVar6 = 1.0;
  if (uVar4 == 0x14) {
    fVar6 = 1.0;
    if ('\0' < cVar2) {
      fVar6 = fGpffff82a0;
    }
  }
  else if (uVar4 == 0x13) {
    fVar6 = 1.0;
    if ('\0' < cVar2) {
      fVar6 = fGpffff82a0;
    }
  }
  else {
    iVar3 = (int)cVar2;
    if (uVar4 == 4) {
      fVar6 = (float)*(u8 *)(iVar3 + (u32)bVar1 * 3 + iGpffffb790 + 7) / 100.0;
    }
    else if (uVar4 == 3) {
      fVar6 = (float)*(u8 *)(((u32)bVar1 * 3 + iGpffffb790 + 1) - iVar3) / 100.0;
    }
    else if (uVar4 == 2) {
      fVar6 = (float)*(u8 *)(((u32)bVar1 * 3 + iGpffffb790 + 7) - iVar3) / 100.0;
    }
    else if (uVar4 == 1) {
      fVar6 = (float)*(u8 *)(iVar3 + (u32)bVar1 * 3 + iGpffffb790 + 1) / 100.0;
      if ((*(u32 *)(puVar5 + 10) & 0x100000) != 0) {
        fVar6 = fVar6 * fGpffff82a0;
      }
    }
    else if ((uVar4 == 0) &&
            (fVar6 = (float)*(u8 *)((int)cVar2 + (u32)bVar1 * 3 + iGpffffb790 + 1) / 100.0,
            (*(u32 *)(puVar5 + 10) & 0x80000) != 0)) {
      fVar6 = fVar6 * fGpffff82a0;
    }
  }
  return fVar6;
}





// FUN_00301ca0 NONMATCHING
u8 FUN_00301ca0(u32 param_1,u32 param_2)

{
  char cVar1;
  u8 bVar2;
  int iVar3;
  
  if (param_2 == 0) {
    bVar2 = false;
  }
  else if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 4) == 0) {
        if ((param_2 & 8) == 0) {
          if ((param_2 & 0x10) == 0) {
            if ((param_2 & 0x20) == 0) {
              if ((param_2 & 0x40) == 0) {
                if ((param_2 & 0x80) == 0) {
                  if ((param_2 & 0x100) == 0) {
                    if ((param_2 & 0x200) == 0) {
                      iVar3 = (int)param_1;
                      if ((param_2 & 0x400) == 0) {
                        if ((param_2 & 0x800) == 0) {
                          if ((param_2 & 0x4000) == 0) {
                            if ((param_2 & 0x8000) == 0) {
                              if ((param_2 & 0x10000) == 0) {
                                if ((param_2 & 0x20000) == 0) {
                                  if ((param_2 & 0x40000) == 0) {
                                    if ((param_2 & 0x80000) == 0) {
                                      if ((param_2 & 0x100000) == 0) {
                                        if ((param_2 & 0x200000) == 0) {
                                          if ((param_2 & 0x400000) == 0) {
                                            if ((param_2 & 0x800000) == 0) {
                                              if ((param_2 & 0x1000000) == 0) {
                                                if ((param_2 & 0x2000000) == 0) {
                                                  if ((param_2 & 0x4000000) == 0) {
                                                    if ((param_2 & 0x1000) == 0) {
                                                      if ((param_2 & 0x2000) == 0) {
                                                        FUN_0019d3f0((u32)D_0069aa80, 0x5a2);
                                                        bVar2 = false;
                                                      }
                                                      else {
                                                        cVar1 = FUN_00300f60(param_1,0);
                                                        if ((((cVar1 < '\0') ||
                                                             (cVar1 = FUN_00300f60(param_1,1),
                                                             cVar1 < '\0')) ||
                                                            (cVar1 = FUN_00300f60(param_1,2),
                                                            cVar1 < '\0')) ||
                                                           ((((cVar1 = FUN_00300f60(param_1,3),
                                                              cVar1 < '\0' ||
                                                              (cVar1 = FUN_00300f60(param_1,4),
                                                              cVar1 < '\0')) ||
                                                             ((cVar1 = FUN_00300f60(param_1,0xd),
                                                              '\0' < cVar1 ||
                                                              ((cVar1 = FUN_00300f60(param_1,0xe),
                                                               '\0' < cVar1 ||
                                                               (cVar1 = FUN_00300f60(param_1,0xf),
                                                               '\0' < cVar1)))))) ||
                                                            (cVar1 = FUN_00300f60(param_1,0x10),
                                                            '\0' < cVar1)))) {
                                                          bVar2 = false;
                                                        }
                                                        else {
                                                          bVar2 = true;
                                                        }
                                                      }
                                                    }
                                                    else {
                                                      cVar1 = FUN_00300f60(param_1,0);
                                                      if ((((cVar1 < '\x01') &&
                                                           (cVar1 = FUN_00300f60(param_1,1),
                                                           cVar1 < '\x01')) &&
                                                          (cVar1 = FUN_00300f60(param_1,2),
                                                          cVar1 < '\x01')) &&
                                                         ((cVar1 = FUN_00300f60(param_1,3),
                                                          cVar1 < '\x01' &&
                                                          (cVar1 = FUN_00300f60(param_1,4),
                                                          cVar1 < '\x01')))) {
                                                        bVar2 = true;
                                                      }
                                                      else {
                                                        bVar2 = false;
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    cVar1 = FUN_00300f60(param_1,0xb);
                                                    bVar2 = cVar1 != '\0';
                                                  }
                                                }
                                                else {
                                                  cVar1 = FUN_00300f60(param_1,10);
                                                  bVar2 = cVar1 != '\0';
                                                }
                                              }
                                              else {
                                                cVar1 = FUN_00300f60(param_1,9);
                                                bVar2 = cVar1 != '\0';
                                              }
                                            }
                                            else {
                                              cVar1 = FUN_00300f60(param_1,8);
                                              bVar2 = cVar1 != '\0';
                                            }
                                          }
                                          else {
                                            cVar1 = FUN_00300f60(param_1,7);
                                            bVar2 = cVar1 != '\0';
                                          }
                                        }
                                        else {
                                          cVar1 = FUN_00300f60(param_1,0x10);
                                          bVar2 = cVar1 != '\0';
                                        }
                                      }
                                      else {
                                        cVar1 = FUN_00300f60(param_1,0xf);
                                        bVar2 = cVar1 != '\0';
                                      }
                                    }
                                    else {
                                      cVar1 = FUN_00300f60(param_1,0xe);
                                      bVar2 = cVar1 != '\0';
                                    }
                                  }
                                  else {
                                    cVar1 = FUN_00300f60(param_1,0xd);
                                    bVar2 = cVar1 != '\0';
                                  }
                                }
                                else {
                                  bVar2 = (*(u32 *)(iVar3 + 0x14) & 0x40000) != 0;
                                }
                              }
                              else {
                                bVar2 = (*(u32 *)(iVar3 + 0x14) & 0x20000) != 0;
                              }
                            }
                            else {
                              cVar1 = FUN_00300f60(param_1,6);
                              bVar2 = cVar1 != '\0';
                            }
                          }
                          else {
                            cVar1 = FUN_00300f60(param_1,5);
                            bVar2 = cVar1 != '\0';
                          }
                        }
                        else {
                          bVar2 = (*(u32 *)(iVar3 + 0x14) & 0x100000) != 0;
                        }
                      }
                      else {
                        bVar2 = (*(u32 *)(iVar3 + 0x14) & 0x80000) != 0;
                      }
                    }
                    else {
                      cVar1 = FUN_00300f60(param_1,4);
                      bVar2 = cVar1 < '\0';
                    }
                  }
                  else {
                    cVar1 = FUN_00300f60(param_1,4);
                    bVar2 = '\0' < cVar1;
                  }
                }
                else {
                  cVar1 = FUN_00300f60(param_1,3);
                  bVar2 = cVar1 < '\0';
                }
              }
              else {
                cVar1 = FUN_00300f60(param_1,3);
                bVar2 = '\0' < cVar1;
              }
            }
            else {
              cVar1 = FUN_00300f60(param_1,2);
              bVar2 = cVar1 < '\0';
            }
          }
          else {
            cVar1 = FUN_00300f60(param_1,2);
            bVar2 = '\0' < cVar1;
          }
        }
        else {
          cVar1 = FUN_00300f60(param_1,1);
          bVar2 = cVar1 < '\0';
        }
      }
      else {
        cVar1 = FUN_00300f60(param_1,1);
        bVar2 = '\0' < cVar1;
      }
    }
    else {
      cVar1 = FUN_00300f60(param_1,0);
      bVar2 = cVar1 < '\0';
    }
  }
  else {
    cVar1 = FUN_00300f60(param_1,0);
    bVar2 = '\0' < cVar1;
  }
  return bVar2;
}





// FUN_00302380 NONMATCHING
void FUN_00302380(u32 param_1,u32 param_2,u32 param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_2 != 0) {
    if ((param_2 & 1) != 0) {
      FUN_00301230(param_1,0,0);
    }
    cVar1 = (char)param_3;
    if ((param_2 & 2) != 0) {
      FUN_00301230(param_1,0,-cVar1);
    }
    if ((param_2 & 4) != 0) {
      FUN_00301230(param_1,1,param_3);
    }
    if ((param_2 & 8) != 0) {
      FUN_00301230(param_1,1,-cVar1);
    }
    if ((param_2 & 0x10) != 0) {
      FUN_00301230(param_1,2,param_3);
    }
    if ((param_2 & 0x20) != 0) {
      FUN_00301230(param_1,2,-cVar1);
    }
    if ((param_2 & 0x40) != 0) {
      FUN_00301230(param_1,3,param_3);
    }
    if ((param_2 & 0x80) != 0) {
      FUN_00301230(param_1,3,-cVar1);
    }
    if ((param_2 & 0x100) != 0) {
      FUN_00301230(param_1,4,param_3);
    }
    if ((param_2 & 0x200) != 0) {
      FUN_00301230(param_1,4,-cVar1);
    }
    if ((param_2 & 0x400) != 0) {
      FUN_00301230(param_1,0x13,param_3);
    }
    if ((param_2 & 0x800) != 0) {
      FUN_00301230(param_1,0x14,param_3);
    }
    iVar2 = (int)param_1;
    if ((param_2 & 0x1000) != 0) {
      cVar1 = FUN_00300f60(param_1,0);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,0,0);
        FUN_00301150(param_1,0,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffe;
      }
      cVar1 = FUN_00300f60(param_1,1);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,1,0);
        FUN_00301150(param_1,1,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffd;
      }
      cVar1 = FUN_00300f60(param_1,2);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,2,0);
        FUN_00301150(param_1,2,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffb;
      }
      cVar1 = FUN_00300f60(param_1,3);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,3,0);
        FUN_00301150(param_1,3,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffff7;
      }
      cVar1 = FUN_00300f60(param_1,4);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,4,0);
        FUN_00301150(param_1,4,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xffffffef;
      }
    }
    if ((param_2 & 0x2000) != 0) {
      cVar1 = FUN_00300f60(param_1,0);
      if (cVar1 < '\0') {
        FUN_00301030(param_1,0,0);
        FUN_00301150(param_1,0,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffe;
      }
      cVar1 = FUN_00300f60(param_1,1);
      if (cVar1 < '\0') {
        FUN_00301030(param_1,1,0);
        FUN_00301150(param_1,1,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffd;
      }
      cVar1 = FUN_00300f60(param_1,2);
      if (cVar1 < '\0') {
        FUN_00301030(param_1,2,0);
        FUN_00301150(param_1,2,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffffb;
      }
      cVar1 = FUN_00300f60(param_1,3);
      if (cVar1 < '\0') {
        FUN_00301030(param_1,3,0);
        FUN_00301150(param_1,3,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffffff7;
      }
      cVar1 = FUN_00300f60(param_1,4);
      if (cVar1 < '\0') {
        FUN_00301030(param_1,4,0);
        FUN_00301150(param_1,4,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xffffffef;
      }
      cVar1 = FUN_00300f60(param_1,0xd);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,0xd,0);
        FUN_00301150(param_1,0xd,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xffffdfff;
      }
      cVar1 = FUN_00300f60(param_1,0xe);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,0xe,0);
        FUN_00301150(param_1,0xe,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xffffbfff;
      }
      cVar1 = FUN_00300f60(param_1,0xf);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,0xf,0);
        FUN_00301150(param_1,0xf,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xffff7fff;
      }
      cVar1 = FUN_00300f60(param_1,0x10);
      if ('\0' < cVar1) {
        FUN_00301030(param_1,0x10,0);
        FUN_00301150(param_1,0x10,0);
        *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar2 + 0x14) & 0xfffeffff;
      }
    }
    if ((param_2 & 0x4000) != 0) {
      FUN_00301230(param_1,5,param_3);
    }
    if ((param_2 & 0x8000) != 0) {
      FUN_00301230(param_1,6,param_3);
    }
    if ((param_2 & 0x10000) != 0) {
      FUN_00301230(param_1,0x11,param_3);
    }
    if ((param_2 & 0x20000) != 0) {
      FUN_00301230(param_1,0x12,param_3);
    }
    if ((param_2 & 0x40000) != 0) {
      FUN_00301230(param_1,0xd,param_3);
    }
    if ((param_2 & 0x80000) != 0) {
      FUN_00301230(param_1,0xe,param_3);
    }
    if ((param_2 & 0x100000) != 0) {
      FUN_00301230(param_1,0xf,param_3);
    }
    if ((param_2 & 0x200000) != 0) {
      FUN_00301230(param_1,0x10,param_3);
    }
    if ((param_2 & 0x400000) != 0) {
      FUN_00301230(param_1,7,param_3);
    }
    if ((param_2 & 0x800000) != 0) {
      FUN_00301230(param_1,8,param_3);
    }
    if ((param_2 & 0x1000000) != 0) {
      FUN_00301230(param_1,9,param_3);
    }
  }
  return;
}





// FUN_00302c50
void FUN_00302c50(u32 param_1)
{
    u32 i;
    u32 mask;

    mask = *(u32*)(param_1 + 0x18);
    if (mask != 0)
    {
        for (i = 0; i < 0x15; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                if ((s32)(i & 0xff) >= 0x15)
                {
                    FUN_0019d3f0((u32)D_0069aa80, 0x499);
                }
                if ((s32)(i & 0xff) < 0x11)
                {
                    FUN_00301030(param_1, (u8)i, 0);
                    FUN_00301150(param_1, (u8)i, 0);
                }
                *(u32*)(param_1 + 0x14) &= ~(1 << (i & 0xff));
            }
        }
        *(u32*)(param_1 + 0x18) = 0;
    }
}





// FUN_00302d40 NONMATCHING

void FUN_00302d40(u32 param_1)

{
  char cVar1;
  u8 bVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  
  for (uVar5 = 0; uVar5 < 0x11; uVar5 = uVar5 + 1) {
    uVar4 = uVar5 & 0xff;
    if (0x14 < uVar4) {
      FUN_0019d3f0((u32)D_0069aa80, 0x4b8);
    }
    iVar6 = (int)param_1;
    if (uVar4 < 0x11) {
      cVar1 = FUN_00300f60(param_1,(u8)(uVar5 & 0xff));
    }
    else {
      cVar1 = (*(u32 *)(iVar6 + 0x14) & 1 << uVar4) != 0;
    }
    if (0x14 < uVar4) {
      FUN_0019d3f0((u32)D_0069aa80, 0x421);
    }
    iVar3 = (int)(uVar5 & 0xff) >> 1;
    if ((uVar5 & 1) == 0) {
      bVar2 = *(u8 *)(iVar6 + iVar3 + 0x29) & 0xf;
    }
    else {
      bVar2 = (u8)((int)(u32)*(u8 *)(iVar6 + iVar3 + 0x29) >> 4);
    }
    if ((cVar1 != '\0') && (bVar2 < 0xf)) {
      if (0x14 < uVar4) {
        FUN_0019d3f0((u32)D_0069aa80, 0x455);
      }
      if ((uVar5 & 1) == 0) {
        *(u8 *)(iVar6 + iVar3 + 0x29) = *(u8 *)(iVar6 + iVar3 + 0x29) & 0xf0 | bVar2 + 1 & 0xf;
      }
      else {
        *(u8 *)(iVar6 + iVar3 + 0x29) =
             *(u8 *)(iVar6 + iVar3 + 0x29) & 0xf | (bVar2 + 1) * '\x10';
      }
    }
  }
  return;
}





// FUN_00302f50 NONMATCHING
u8 FUN_00302f50(u32 param_1)

{
  char cVar1;
  u8 bVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  
  uVar5 = 0;
  do {
    if (0x10 < uVar5) {
      return 0xff;
    }
    uVar4 = uVar5 & 0xff;
    if (0x14 < uVar4) {
      FUN_0019d3f0((u32)D_0069aa80, 0x4b8);
    }
    iVar6 = (int)param_1;
    if (uVar4 < 0x11) {
      cVar1 = FUN_00300f60(param_1,(u8)(uVar5 & 0xff));
    }
    else {
      cVar1 = (*(u32 *)(iVar6 + 0x14) & 1 << (uVar5 & 0x1f)) != 0;
    }
    if (0x14 < uVar4) {
      FUN_0019d3f0((u32)D_0069aa80, 0x421);
    }
    iVar3 = (int)(uVar5 & 0xff) >> 1;
    if ((uVar5 & 1) == 0) {
      bVar2 = *(u8 *)(iVar6 + iVar3 + 0x29) & 0xf;
    }
    else {
      bVar2 = (u8)((int)(u32)*(u8 *)(iVar6 + iVar3 + 0x29) >> 4);
    }
    if ((cVar1 != '\0') && (uVar5 != 0xb)) {
      if ((uVar5 == 9) || (uVar5 == 8)) {
        if (bVar2 != 0) {
          return (char)uVar5;
        }
      }
      else if (2 < bVar2) {
        return (char)uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}





// FUN_00303130 NONMATCHING

u32 FUN_00303130(u32 param_1,u32 param_2,u32 param_3,u16 param_4,short param_5,
                 short param_6,u32 param_7,char param_8)

{
  char cVar1;
  u8 bVar2;
  u8 uVar3;
  short sVar4;
  short sVar5;
  u32 uVar6;
  u32 uVar7;
  s32 lVar8;
  u16 *puVar9;
  u16 *puVar10;
  short unaff_s5_lo;
  short unaff_s6_lo;
  int iVar11;
  float fVar12;
  float fVar13;
  u32 uVar14;
  u32 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  u16 uStack_30;
  u16 uStack_20;
  
  if (0x26f < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x6c3);
  }
  if (0x1cf < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x6c4);
  }
  fVar13 = 1.0;
  uVar15 = 0;
  uVar14 = 0;
  uVar6 = 0;
  uStack_30 = 0;
  bVar2 = true;
  puVar9 = (u16 *)param_3;
  uVar7 = (u32)param_1;
  fVar16 = fVar13;
  fVar18 = fVar13;
  if (param_8 == '\x02') {
    iVar11 = (uVar7 & 0xffff) * 0x2c + iGpffffb708;
    unaff_s6_lo = *(short *)(iVar11 + 0x16);
    uStack_20 = (u16)*(u8 *)(iVar11 + 0x14);
    unaff_s5_lo = 0;
    uVar6 = (u32)puVar9[5];
    uStack_30 = FUN_00300100(param_3);
  }
  else if (param_8 == '\x01') {
    iVar11 = (uVar7 & 0xffff) * 0x2c + iGpffffb708;
    unaff_s6_lo = *(short *)(iVar11 + 0x12);
    uStack_20 = (u16)*(u8 *)(iVar11 + 0x11);
    unaff_s5_lo = 0;
    uVar6 = (u32)puVar9[4];
    uStack_30 = FUN_002ffdf0(param_3);
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80, 0x6e3);
  }
  switch(uStack_20) {
  case 0:
    break;
  case 1:
  case 0xc:
  case 0xe:
    cVar1 = *(char *)((uVar7 & 0xffff) * 0x2c + iGpffffb708 + 2);
    if (cVar1 == '\x02') {
      uVar14 = FUN_0030fc40(2,param_2,param_3,param_1,param_8);
    }
    else if (cVar1 == '\x01') {
      uVar14 = FUN_0030fc40(1,param_2,param_3,param_1,param_8);
    }
    else {
      FUN_0019d3f0((u32)D_0069aa80, 0x759);
    }
    uVar14 = uVar14 + (int)unaff_s5_lo;
    if (((uStack_20 == 0xd) || (uStack_20 == 0xc)) && ((int)uVar6 < (int)uVar14)) {
      uVar14 = uVar6;
    }
    if ((uStack_20 == 0xe) && (1 < param_4)) {
      uVar14 = (int)uVar14 / (int)(u32)param_4;
    }
    if ((int)uVar14 < 1) {
      uVar14 = 1;
    }
    bVar2 = false;
    break;
  case 2:
    cVar1 = *(char *)((uVar7 & 0xffff) * 0x2c + iGpffffb708 + 2);
    if (cVar1 == '\x02') {
      uVar15 = FUN_0030fc40(3,param_2,param_3,param_1,param_8);
    }
    else if (cVar1 == '\x01') {
      uVar15 = FUN_0030fc40(1,param_2,param_3,param_1,param_8);
    }
    else {
      FUN_0019d3f0((u32)D_0069aa80, 0x710);
    }
    uVar15 = uVar15 + (int)unaff_s5_lo;
    if ((int)uVar15 < 1) {
      uVar15 = 1;
    }
    bVar2 = false;
    break;
  case 3:
    if ((int)unaff_s6_lo + (int)unaff_s5_lo < (int)uVar6) {
      uVar14 = uVar6 - ((int)unaff_s6_lo + (int)unaff_s5_lo);
    }
    break;
  case 4:
  case 0xd:
    uVar14 = (int)unaff_s6_lo + (int)unaff_s5_lo;
    if ((uStack_20 == 0xd) && ((int)uVar6 < (int)uVar14)) {
      uVar14 = uVar6;
    }
    break;
  case 5:
    uVar15 = (int)unaff_s6_lo + (int)unaff_s5_lo;
    break;
  case 6:
    uVar14 = (int)unaff_s5_lo + 0x32;
    if ((int)uVar14 < 1) {
      uVar14 = 1;
    }
    bVar2 = false;
    break;
  case 7:
    uVar15 = (int)unaff_s5_lo + 0x32;
    if ((int)uVar15 < 1) {
      uVar15 = 1;
    }
    bVar2 = false;
    break;
  case 8:
    uVar14 = (int)(uVar6 * (int)unaff_s6_lo) / 100 + (int)unaff_s5_lo;
    if (((int)uVar14 < 1) && (0 < unaff_s6_lo)) {
      uVar14 = 1;
    }
    break;
  case 9:
    uVar15 = (int)(uVar6 * (int)unaff_s6_lo) / 100 + (int)unaff_s5_lo;
    if ((int)uVar15 < 1) {
      uVar15 = 1;
    }
    break;
  case 10:
    uVar14 = (int)((u32)uStack_30 * (int)unaff_s6_lo) / 100 + (int)unaff_s5_lo;
    if (((int)uVar14 < 1) && (0 < unaff_s6_lo)) {
      uVar14 = 1;
    }
    break;
  case 0xb:
    uVar15 = (int)((u32)uStack_30 * (int)unaff_s6_lo) / 100 + (int)unaff_s5_lo;
    if ((int)uVar15 < 1) {
      uVar15 = 1;
    }
    break;
  case 0xf:
    iVar11 = FUN_002ffbc0(unaff_s6_lo);
    uVar15 = iVar11 + unaff_s5_lo;
    break;
  case 0x10:
    iVar11 = FUN_0030fc40(0xf,param_2,param_3,param_1,param_8);
    uVar14 = iVar11 + unaff_s5_lo;
    if ((int)uVar14 < 1) {
      uVar14 = 1;
    }
    bVar2 = false;
    break;
  default:
    FUN_0019d3f0((u32)D_0069aa80, 0x790);
  }
  fVar17 = fVar13;
  fVar12 = fVar13;
  if (((bVar2) || (fVar17 = 1.0, fVar12 = 1.0, (int)uVar14 < 1)) || ((param_7 & 1) != 0))
  goto LAB_00305784;
  sVar4 = FUN_003082f0(param_2,param_1);
  iVar11 = (uVar7 & 0xffff) * 0x2c;
  cVar1 = *(char *)(iVar11 + iGpffffb708 + 2);
  puVar10 = (u16 *)param_2;
  if (cVar1 == '\x02') {
    fVar18 = (float)FUN_00301880(param_2,1);
    fVar12 = (float)FUN_00301880(param_3,3);
    *(u32 *)(puVar10 + 0xc) = *(u32 *)(puVar10 + 0xc) | 0x100000;
  }
  else if (cVar1 == '\x01') {
    fVar18 = (float)FUN_00301880(param_2,0);
    fVar12 = (float)FUN_00301880(param_3,3);
    *(u32 *)(puVar10 + 0xc) = *(u32 *)(puVar10 + 0xc) | 0x80000;
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80, 0x7a8);
    fVar12 = fVar13;
  }
  if (sVar4 == 6) {
    lVar8 = FUN_003005e0(param_2,0x216);
    if (lVar8 == 0) {
      if ((*puVar10 & 4) == 0) {
        sVar5 = FUN_00300870(puVar10[1],0xb0);
      }
      else {
        sVar5 = 0;
      }
      if (sVar5 != 0) goto LAB_00303ac8;
    }
    else {
LAB_00303ac8:
      fVar13 = 1.25;
    }
    lVar8 = FUN_003005e0(param_2,0x217);
    if (lVar8 != 0) {
      fVar13 = fVar13 * 1.5;
    }
  }
  else if (sVar4 == 5) {
    lVar8 = FUN_003005e0(param_2,0x214);
    if (lVar8 == 0) {
      if ((*puVar10 & 4) == 0) {
        sVar5 = FUN_00300870(puVar10[1],0xaf);
      }
      else {
        sVar5 = 0;
      }
      if (sVar5 != 0) goto LAB_00303a38;
    }
    else {
LAB_00303a38:
      fVar13 = 1.25;
    }
    lVar8 = FUN_003005e0(param_2,0x215);
    if (lVar8 != 0) {
      fVar13 = fVar13 * 1.5;
    }
  }
  else if (sVar4 == 4) {
    lVar8 = FUN_003005e0(param_2,0x212);
    if (lVar8 == 0) {
      if ((*puVar10 & 4) == 0) {
        sVar5 = FUN_00300870(puVar10[1],0xae);
      }
      else {
        sVar5 = 0;
      }
      if (sVar5 != 0) goto LAB_003039a8;
    }
    else {
LAB_003039a8:
      fVar13 = 1.25;
    }
    lVar8 = FUN_003005e0(param_2,0x213);
    if (lVar8 != 0) {
      fVar13 = fVar13 * 1.5;
    }
  }
  else if (sVar4 == 3) {
    lVar8 = FUN_003005e0(param_2,0x210);
    if (lVar8 == 0) {
      if ((*puVar10 & 4) == 0) {
        sVar5 = FUN_00300870(puVar10[1],0xad);
      }
      else {
        sVar5 = 0;
      }
      if (sVar5 != 0) goto LAB_00303918;
    }
    else {
LAB_00303918:
      fVar13 = 1.25;
    }
    lVar8 = FUN_003005e0(param_2,0x211);
    if (lVar8 != 0) {
      fVar13 = fVar13 * 1.5;
    }
  }
  fVar17 = fVar13;
  if (((*(u32 *)(puVar10 + 6) & 0x10) != 0) && (lVar8 = FUN_003005e0(param_2,0x21f), lVar8 != 0)) {
    puVar10[0x1c] = 0x121f;
    fVar17 = fVar13 * 2.0;
  }
  lVar8 = FUN_003088b0(param_1);
  if ((lVar8 != 0) && ((*puVar10 & 4) == 0)) {
    uVar3 = FUN_00308c60(param_2);
    switch(uVar3) {
    case 0:
      lVar8 = FUN_003005e0(param_2,0x248);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
      break;
    case 1:
      lVar8 = FUN_003005e0(param_2,0x249);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
      break;
    case 2:
      lVar8 = FUN_003005e0(param_2,0x23d);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
      break;
    case 3:
      lVar8 = FUN_003005e0(param_2,0x24a);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
      break;
    case 4:
      lVar8 = FUN_003005e0(param_2,0x246);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
      break;
    case 6:
      lVar8 = FUN_003005e0(param_2,0x247);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
    }
  }
  lVar8 = FUN_003088b0(param_1);
  if (lVar8 == 0) {
    cVar1 = *(char *)(iVar11 + iGpffffb708 + 2);
    if (cVar1 == '\x02') {
      lVar8 = FUN_003005e0(param_2,0x23e);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
    }
    else if (cVar1 == '\x01') {
      lVar8 = FUN_003005e0(param_2,0x23f);
      if (lVar8 != 0) {
        fVar17 = fVar17 * 1.25;
      }
    }
    else {
      FUN_0019d3f0((u32)D_0069aa80, 0x817);
    }
  }
  lVar8 = FUN_003005e0(param_3,0x234);
  if (lVar8 != 0) {
    fVar17 = fVar17 * 0.5;
  }
  if ((*(u32 *)(puVar10 + 6) & 0x100) != 0) {
    FUN_0017d800();
    fVar16 = fVar16 * 1.5;
  }
  if (param_6 == 2) {
    if ((*puVar10 & 4) == 0) {
      FUN_0016f190(0x1319);
      fVar18 = fVar18 * fGpffff82a4;
    }
    else {
      lVar8 = FUN_0016f190(0x1319);
      fVar13 = fGpffff82a8;
      if (lVar8 == 0) {
        fVar13 = fGpffff82a4;
      }
      fVar18 = fVar18 * fVar13;
    }
  }
  if (param_6 == 8) {
    FUN_0016f190(0x1319);
    fVar18 = fVar18 * 1.5;
  }
  if ((*(u32 *)(puVar10 + 6) & 0x10) != 0) {
    fVar16 = fVar16 * 1.5;
  }
  if ((*(u32 *)(puVar9 + 6) & 0x10) != 0) {
    fVar16 = fVar16 * 3.0;
  }
  if ((*(u32 *)(puVar9 + 6) & 2) != 0) {
    lVar8 = FUN_0016f190(0x1319);
    fVar13 = fGpffff8070;
    if (lVar8 != 0) {
      fVar13 = 1.5;
    }
    fVar16 = fVar16 * fVar13;
  }
  if ((*(u32 *)(puVar9 + 6) & 0x200) != 0) {
    fVar16 = fVar16 * 3.0;
  }
  if ((*(u32 *)(puVar9 + 6) & 0x100000) != 0) {
    lVar8 = FUN_0016f190(0x1319);
    fVar13 = fGpffff82ac;
    if (lVar8 == 0) {
      fVar13 = fGpffff8070;
    }
    fVar16 = fVar16 * fVar13;
  }
  if ((*(u32 *)(puVar9 + 6) & 0x100) != 0) {
    FUN_0017d800();
    fVar16 = fVar16 * 0.5;
  }
  if ((*puVar10 & 4) != 0) {
    if (0x14f < puVar10[1]) {
      FUN_0019d3f0((u32)D_0069aa80, 0x853);
    }
    if ((*(u16 *)(iGpffffb720 + (u32)puVar10[1] * 0x3e) & 0x20) != 0) {
      fVar18 = fVar18 * 0.75;
    }
  }
  if ((*puVar10 & 4) == 0) {
    sVar5 = FUN_0016c920(puVar10[1]);
  }
  else {
    sVar5 = 0;
  }
  if (sVar5 == 3) {
    lVar8 = FUN_0016f190(0x1319);
    fVar13 = fGpffff80e0;
    if (lVar8 == 0) {
      fVar13 = fGpffff8084;
    }
    fVar16 = fVar16 * fVar13;
  }
  else {
    if ((*puVar10 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar10[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 == 5) {
      lVar8 = FUN_0016f190(0x1319);
      fVar13 = fGpffff8084;
      if (lVar8 != 0) {
        fVar13 = 0.5;
      }
      fVar16 = fVar16 * fVar13;
    }
  }
  if ((*puVar9 & 4) == 0) {
    sVar5 = FUN_0016c920(puVar9[1]);
  }
  else {
    sVar5 = 0;
  }
  if (sVar5 == 3) {
    lVar8 = FUN_0016f190(0x1319);
    fVar13 = fGpffff82a4;
    if (lVar8 == 0) {
      fVar13 = 1.5;
    }
    fVar16 = fVar16 * fVar13;
  }
  else {
    if ((*puVar9 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar9[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 == 5) {
      lVar8 = FUN_0016f190(0x1319);
      if (lVar8 == 0) {
        fVar13 = 1.5;
      }
      else {
        fVar13 = 2.0;
      }
      fVar16 = fVar16 * fVar13;
    }
  }
  switch(*(u8 *)(iVar11 + iGpffffb708 + 0x24)) {
  case 2:
    uVar6 = FUN_00181b10();
    if (0x1d < (uVar6 & 0xff)) {
      FUN_0019d3f0((u32)D_0069aa80, 0x86e);
    }
    fVar18 = fVar18 * ((float)*(u16 *)(iGpffffb7a4 + (uVar6 & 0xff) * 2) / 100.0);
    break;
  case 3:
    uVar6 = FUN_00181b10();
    if (0x1d < (uVar6 & 0xff)) {
      FUN_0019d3f0((u32)D_0069aa80, 0x873);
    }
    fVar18 = fVar18 * ((float)*(u16 *)(iGpffffb7a8 + (uVar6 & 0xff) * 2) / 100.0);
    break;
  case 4:
    if ((*puVar10 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar10[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 == 1) {
      fVar18 = fVar18 * 1.5;
    }
    else if (sVar5 == 2) {
      fVar18 = fVar18 * 2.0;
    }
    break;
  case 5:
    if ((*puVar10 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar10[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 == 3) {
      fVar18 = fVar18 * 1.5;
    }
    else if (sVar5 == 4) {
      fVar18 = fVar18 * 1.875;
    }
    else if (sVar5 == 5) {
      fVar18 = fVar18 * fGpffff82a8;
    }
    break;
  case 7:
    if ((*(u32 *)(puVar9 + 6) & 1) != 0) {
      fVar18 = fVar18 * 2.0;
    }
    break;
  case 8:
    if ((*(u32 *)(puVar9 + 6) & 0x100000) != 0) {
      fVar18 = fVar18 * 2.0;
    }
  }
  lVar8 = FUN_003088b0(param_1);
  if (((lVar8 != 0) && ((*puVar9 & 4) != 0)) && ((*puVar10 & 4) == 0)) {
    if (0x14f < puVar9[1]) {
      FUN_0019d3f0((u32)D_0069aa80, 0x89b);
    }
    switch(*(u8 *)((u32)puVar9[1] * 0x3e + iGpffffb720 + 2)) {
    case 2:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x24);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x90);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x91);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 3:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x25);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x92);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x93);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 4:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x26);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x94);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x95);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 5:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x27);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x96);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x97);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 6:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x28);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x98);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x99);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 7:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x29);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9a);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9b);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 8:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2a);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9c);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9d);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 9:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2b);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9e);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x9f);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 10:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2c);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa0);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa1);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 0xb:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2d);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa2);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa3);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 0xc:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2e);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa4);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa5);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 0xd:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x2f);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa6);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa7);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
      break;
    case 0xe:
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0x30);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.25;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa8);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.5;
      }
      if ((*puVar10 & 4) == 0) {
        lVar8 = FUN_00300750(puVar10[1],0xa9);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * 1.75;
      }
    }
  }
  if ((*puVar9 & 4) == 0) {
    if (((sVar4 == 2) || (sVar4 == 1)) || (sVar4 == 0)) {
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x52);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x53);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x54);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
    }
    if (((sVar4 == 6) || (sVar4 == 5)) || ((sVar4 == 4 || (sVar4 == 3)))) {
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x61);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x62);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],99);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
    }
    switch(sVar4) {
    case 0:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4c);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4d);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4e);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 1:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x49);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4a);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4b);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 2:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x4f);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x50);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x51);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 3:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x55);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x56);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x57);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 4:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x58);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x59);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5a);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 5:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5e);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5f);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x60);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
      break;
    case 6:
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5b);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff829c;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5c);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff8084;
      }
      if ((*puVar9 & 4) == 0) {
        lVar8 = FUN_00300750(puVar9[1],0x5d);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 != 0) {
        fVar18 = fVar18 * fGpffff80e0;
      }
    }
  }
  uVar14 = (u32)(fVar17 * fVar16 * fVar12 * (float)(int)uVar14 * fVar18);
  if (param_6 == 0x10) {
    uVar14 = 500;
  }
  else {
    if ((int)uVar14 < 0x7919) {
      uVar6 = (u32)*(u16 *)(iGpffffb708 + 0x28 + iVar11);
      if ((int)uVar14 < (int)uVar6) {
        uVar14 = uVar6;
      }
    }
    else {
      uVar14 = 31000;
    }
    iVar11 = FUN_002ffbc0(0xb);
    uVar14 = (int)(uVar14 * (iVar11 + 0x5f)) / 100;
  }
  if ((int)uVar14 < 1) {
    uVar14 = 1;
  }
LAB_00305784:
  if (((!bVar2) && (0 < (int)uVar15)) && ((param_7 & 1) == 0)) {
    if ((*puVar9 & 4) == 0) {
      sVar4 = FUN_0016c920(puVar9[1]);
    }
    else {
      sVar4 = 0;
    }
    if (sVar4 == 5) {
      FUN_0016f190(0x1319);
      fVar16 = fVar16 * 0.5;
    }
    lVar8 = FUN_003005e0(param_2,0x23a);
    if (lVar8 != 0) {
      fVar17 = fVar17 * 2.0;
    }
    uVar15 = (u32)(fVar17 * fVar16 * fVar12 * (float)(int)uVar15 * fVar18);
    if ((int)uVar15 < 0x7919) {
      uVar7 = (u32)*(u16 *)(iGpffffb708 + 0x28 + (uVar7 & 0xffff) * 0x2c);
      if ((int)uVar15 < (int)uVar7) {
        uVar15 = uVar7;
      }
    }
    else {
      uVar15 = 31000;
    }
    iVar11 = FUN_002ffbc0(0xb);
    uVar15 = (int)(uVar15 * (iVar11 + 0x5f)) / 100;
    if ((int)uVar15 < 1) {
      uVar15 = 1;
    }
  }
  uVar7 = uVar14;
  if ((param_5 == 0x400) && (0 < (int)uVar14)) {
    uVar7 = 0;
    uVar15 = uVar14;
  }
  if (((param_5 == 4) || (param_5 == 2)) || (param_5 == 0x100)) {
    uVar15 = 0;
    uVar7 = 0;
  }
  if (0 < (int)uVar7) {
    uVar15 = -uVar7;
  }
  return uVar15;
}





// FUN_00305970 NONMATCHING

u32 FUN_00305970(u32 param_1,u32 param_2,u32 param_3)

{
  u8 bVar1;
  char cVar2;
  short sVar3;
  u16 uVar4;
  int iVar5;
  u32 uVar6;
  s32 lVar7;
  u32 uVar8;
  u32 uVar9;
  u16 *puVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  u16 auStack_30 [24];
  
  if (0x26f < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xac9);
  }
  bVar1 = false;
  iVar11 = ((u32)param_1 & 0xffff) * 0x2c;
  uVar9 = *(u32 *)(iVar11 + DAT_007ce3f8 + 0x1c) & 0xffffff;
  if (*(char *)(iVar11 + DAT_007ce3f8 + 0x18) == '\x03') {
    uVar6 = 0;
    for (uVar8 = 0; uVar8 < 0x18; uVar8 = uVar8 + 1 & 0xffff) {
      if ((uVar9 & 1 << (uVar8 & 0x1f)) != 0) {
        auStack_30[uVar6] = (u16)uVar8;
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
    iVar5 = FUN_002ffbc0(uVar6);
    uVar9 = 1 << (auStack_30[iVar5] & 0x1f);
  }
  fVar13 = 1.0;
  if ((uVar9 == 0) ||
     ((cVar2 = *(char *)(DAT_007ce3f8 + 0x18 + iVar11), cVar2 != '\x01' &&
      (fVar13 = 1.0, cVar2 != '\x03')))) goto LAB_00305f20;
  puVar10 = (u16 *)param_3;
  if ((*(char *)(iVar11 + DAT_007ce3f8 + 0x24) == '\x01') && ((*(u32 *)(puVar10 + 6) & 8) != 0)) {
    return uVar9;
  }
  sVar3 = FUN_00308120((short)param_1,uVar9);
  {
    extern u32 FUN_00306e80(s32 param_1,u32 param_2);
    uVar6 = FUN_00306e80(param_3,sVar3);
  }
  if (sVar3 == 5) {
    lVar7 = FUN_003005e0(param_3,0x1f8);
    if (lVar7 != 0) {
      uVar6 = uVar6 | 0x1000000;
    }
  }
  else if ((sVar3 == 4) && (lVar7 = FUN_003005e0(param_3,0x1f7), lVar7 != 0)) {
    uVar6 = uVar6 | 0x1000000;
  }
  if ((uVar6 & 0x27000000) != 0) {
    return 0;
  }
  if ((uVar9 & 0x100000) != 0) {
    if ((*(u32 *)(puVar10 + 6) & 0x100000) != 0) {
      return 0;
    }
    if ((*puVar10 & 0x10) != 0) {
      return 0;
    }
  }
  fVar13 = ((float)(uVar6 & 0xffff) / 100.0) * 1.0;
  if ((uVar9 & 0x80000) == 0) {
    if ((*puVar10 & 4) == 0) {
      sVar3 = FUN_0016c920(puVar10[1]);
    }
    else {
      sVar3 = 0;
    }
    if (sVar3 == 5) {
LAB_00305ccc:
      lVar7 = FUN_0016f190(0x1319);
      if (lVar7 == 0) {
        fVar12 = 2.0;
      }
      else {
        fVar12 = 2.5;
      }
      fVar13 = fVar13 * fVar12;
    }
    else {
      if ((*puVar10 & 4) == 0) {
        sVar3 = FUN_0016c920(puVar10[1]);
      }
      else {
        sVar3 = 0;
      }
      if (sVar3 == 4) goto LAB_00305ccc;
    }
    cVar2 = FUN_00300f60(param_3,7);
    if ('\0' < cVar2) {
      fVar13 = fVar13 * 1.5;
    }
  }
  uVar4 = FUN_003082f0(param_2,param_1);
  switch(uVar4) {
  case 8:
    lVar7 = FUN_003005e0(param_2,599);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 9:
    lVar7 = FUN_003005e0(param_2,600);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 10:
    lVar7 = FUN_003005e0(param_2,0x250);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 0xb:
    lVar7 = FUN_003005e0(param_2,0x251);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 0xc:
    lVar7 = FUN_003005e0(param_2,0x252);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 0xd:
    lVar7 = FUN_003005e0(param_2,0x253);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 0xe:
    lVar7 = FUN_003005e0(param_2,0x254);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
    break;
  case 0xf:
    lVar7 = FUN_003005e0(param_2,0x255);
    if (lVar7 != 0) {
      fVar13 = fVar13 * 1.25;
    }
  }
  if (((uVar9 & 0x80000) == 0) && (lVar7 = FUN_003005e0(param_2,0x256), lVar7 != 0)) {
    fVar13 = fVar13 * 1.25;
  }
LAB_00305f20:
  if (uVar9 == 0) {
    uVar9 = 0;
  }
  else {
    if (*(u8 *)(iVar11 + DAT_007ce3f8 + 0x19) < 100) {
      iVar11 = FUN_0030fc40(0x10,param_2,param_3,param_1,uVar9);
      iVar11 = (int)((float)iVar11 * fVar13);
      if (iVar11 < 100) {
        if (iVar11 < 0) {
          iVar11 = 0;
        }
      }
      else {
        iVar11 = 99;
      }
      iVar5 = FUN_002ffbc0(100);
      if (iVar5 < iVar11) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar9 = 0;
    }
  }
  return uVar9;
}





// FUN_00306020 NONMATCHING
u32 FUN_00306020(u32 param_1,u32 param_2,u32 param_3,short param_4)

{
  u16 uVar1;
  char cVar2;
  u16 uVar3;
  u32 uVar4;
  s32 lVar5;
  
  if (0x1cf < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xb95);
  }
  if (param_4 == 1) {
    cVar2 = *(char *)(((u32)param_1 & 0xffff) * 0x2c + DAT_007ce3f8 + 0x18);
    if ((cVar2 == '\x01') || (cVar2 == '\x03')) {
      uVar4 = FUN_00305970(param_1,param_2,param_3);
      if (((*(u32 *)((int)param_3 + 0xc) & 0xfffff) != 0) && ((uVar4 & 0x180000) == 0)) {
        uVar4 = 0;
      }
    }
    else {
      lVar5 = FUN_003088b0(param_1);
      if ((lVar5 != 0) && ((*(u32 *)((int)param_3 + 0xc) & 0xfffff) == 0)) {
        if ((*(u16 *)param_2 & 4) == 0) {
          uVar1 = ((u16 *)param_2)[1];
          if (10 < (short)uVar1) {
            FUN_0019d3f0((u32)D_0069aa80, 0x2b9);
          }
          uVar3 = FUN_0016cb80(uVar1,0);
          cVar2 = FUN_0016f900(uVar1,uVar3);
        }
        else {
          cVar2 = '\0';
        }
        if (cVar2 == -0x54) {
          uVar4 = FUN_00305970(0xb4,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == -0x55) {
          uVar4 = FUN_00305970(0xb3,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == -0x56) {
          uVar4 = FUN_00305970(0xb2,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == 'B') {
          uVar4 = FUN_00305970(0xb1,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == 'A') {
          uVar4 = FUN_00305970(0xb0,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '@') {
          uVar4 = FUN_00305970(0xaf,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '?') {
          uVar4 = FUN_00305970(0xae,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '>') {
          uVar4 = FUN_00305970(0xad,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '=') {
          uVar4 = FUN_00305970(0xac,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '<') {
          uVar4 = FUN_00305970(0xab,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == ';') {
          uVar4 = FUN_00305970(0xaa,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == ':') {
          uVar4 = FUN_00305970(0xa9,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '9') {
          uVar4 = FUN_00305970(0xa8,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '8') {
          uVar4 = FUN_00305970(0xa7,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '7') {
          uVar4 = FUN_00305970(0xa6,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '6') {
          uVar4 = FUN_00305970(0xa5,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '5') {
          uVar4 = FUN_00305970(0xa4,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '4') {
          uVar4 = FUN_00305970(0xa3,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '3') {
          uVar4 = FUN_00305970(0xa2,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '2') {
          uVar4 = FUN_00305970(0xa1,param_2,param_3);
          return uVar4;
        }
        if (cVar2 == '1') {
          uVar4 = FUN_00305970(0xa0,param_2,param_3);
          return uVar4;
        }
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}





// FUN_00306510
u32 FUN_00306510(u32 param_1,u32 param_2,u32 param_3,u16 param_4)

{
  u32 uVar1;
  int iVar2;
  
  if ((s32)(param_1 & 0xffff) < 0x1d0) {
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80,0xbfa);
  }
  if (param_4 != 1) {
    uVar1 = 0;
  }
  else {
    iVar2 = ((u32)param_1 & 0xffff) * 0x2c;
    iVar2 += DAT_007ce3f8;
    if (*(u8 *)(iVar2 + 0x18) != '\x02') {
      uVar1 = 0;
    }
    else {
      if (*(u8 *)(iVar2 + 0x19) < 100) {
        FUN_0019d3f0((u32)D_0069aa80,0xc05);
      }
      uVar1 = FUN_00305970(param_1,param_2,param_3);
    }
  }
  return uVar1;
}





// FUN_00306610 NONMATCHING
u32 FUN_00306610(u32 param_1,s32 param_2,s32 param_3,u32 param_4)

{
  u32 uVar1;
  s32 lVar2;
  s32 lVar3;
  u32 uVar4;
  s32 lVar5;
  u32 uVar6;
  int iVar7;
  
  if (0x1cf < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xc22);
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    lVar2 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,1);
    lVar3 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,2);
    uVar4 = FUN_00306020(param_1,param_2,param_3,1);
    if (0x1cf < (param_1 & 0xffff)) {
      FUN_0019d3f0((u32)D_0069aa80, 0xbfa);
    }
    iVar7 = ((u32)param_1 & 0xffff) * 0x2c + DAT_007ce3f8;
    if (*(char *)(iVar7 + 0x18) == '\x02') {
      if (*(u8 *)(iVar7 + 0x19) < 100) {
        FUN_0019d3f0((u32)D_0069aa80, 0xc05);
      }
      lVar5 = FUN_00305970(param_1,param_2,param_3);
    }
    else {
      lVar5 = 0;
    }
    if ((((lVar2 == 0) && (lVar3 == 0)) && (uVar4 == 0)) && (lVar5 == 0)) {
      return 0;
    }
    iVar7 = (int)param_3;
    if ((uVar4 & 0xfffff) != 0) {
      *(u32 *)(iVar7 + 0xc) = *(u32 *)(iVar7 + 0xc) & 0xfff00000 | (u32)((uVar4 << 0x2c) >> 0x2c)
      ;
    }
    uVar6 = *(u32 *)(iVar7 + 0xc) | (u32)uVar4 & 0xfff00000;
    *(u32 *)(iVar7 + 0xc) = uVar6;
    *(u32 *)(iVar7 + 0xc) = uVar6 & ~(u32)lVar5;
    if (lVar3 != 0) {
      uVar6 = (u32)*(u16 *)(iVar7 + 10) + (int)lVar3;
      if ((int)uVar6 < 0) {
        uVar6 = 0;
      }
      uVar1 = FUN_00300100(param_3);
      if ((int)(uVar1 & 0xffff) < (int)uVar6) {
        uVar6 = uVar1 & 0xffff;
      }
      *(short *)(iVar7 + 10) = (short)uVar6;
    }
    if (lVar2 != 0) {
      uVar6 = (u32)*(u16 *)(iVar7 + 8) + (int)lVar2;
      if ((int)uVar6 < 0) {
        uVar6 = 0;
      }
      uVar1 = FUN_002ffdf0(param_3);
      if ((int)(uVar1 & 0xffff) < (int)uVar6) {
        uVar6 = uVar1 & 0xffff;
      }
      *(short *)(iVar7 + 8) = (short)uVar6;
      if (*(short *)(iVar7 + 8) == 0) {
        *(u32 *)(iVar7 + 0xc) = *(u32 *)(iVar7 + 0xc) & 0xfff00000 | 0x80000;
      }
    }
  }
  return 1;
}





// FUN_003068d0 NONMATCHING
u32 FUN_003068d0(u32 param_1,s32 param_2,s32 param_3,u32 param_4)

{
  u16 uVar1;
  u16 uVar2;
  u32 uVar3;
  s32 lVar4;
  s32 lVar5;
  s32 lVar6;
  int iVar7;
  u32 uVar8;
  
  if (0x1cf < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xc67);
  }
  uVar8 = 0;
  if (param_2 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  lVar4 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,1);
  lVar5 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,2);
  lVar6 = FUN_00306020(param_1,param_2,param_3,1);
  if (0x1cf < (param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xbfa);
  }
  iVar7 = ((u32)param_1 & 0xffff) * 0x2c + DAT_007ce3f8;
  if (*(char *)(iVar7 + 0x18) == '\x02') {
    if (*(u8 *)(iVar7 + 0x19) < 100) {
      FUN_0019d3f0((u32)D_0069aa80, 0xc05);
    }
    uVar3 = FUN_00305970(param_1,param_2,param_3);
  }
  else {
    uVar3 = 0;
  }
  *(u32 *)((int)param_2 + 0x18) = 0;
  iVar7 = (int)param_3;
  *(u32 *)(iVar7 + 0x18) = 0;
  if ((((lVar4 == 0) && (lVar5 == 0)) && (lVar6 == 0)) && (uVar3 == 0)) {
    uVar8 = 0xffff;
  }
  if (uVar3 != 0) {
    if ((*(u32 *)(iVar7 + 0xc) & uVar3) != 0) {
      return 0;
    }
    uVar8 = uVar8 | 4;
    if ((uVar3 & 0x80000) != 0) {
      return uVar8;
    }
  }
  if ((*(u32 *)(iVar7 + 0xc) & 0x80000) == 0) {
    if (0 < lVar5) {
      uVar1 = *(u16 *)(iVar7 + 10);
      uVar2 = FUN_00300100(param_3);
      if (uVar1 < uVar2) {
        return 0;
      }
      uVar8 = uVar8 | 2;
    }
    if (0 < lVar4) {
      uVar1 = *(u16 *)(iVar7 + 8);
      uVar2 = FUN_002ffdf0(param_3);
      if (uVar1 < uVar2) {
        uVar8 = 0;
      }
      else {
        uVar8 = uVar8 | 1;
      }
    }
  }
  else {
    uVar8 = 0xffff;
  }
  return uVar8;
}





// FUN_00306bc0 NONMATCHING
u32
FUN_00306bc0(u32 param_1,s32 param_2,s32 param_3,u32 param_4,s32 param_5,s32 param_6,
            s32 param_7)

{
  u32 uVar1;
  int iVar2;
  
  if (0x1cf < (s32)(param_1 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xcc5);
  }
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar1 = 0;
  }
  else {
    if (param_5 != 0) {
      uVar1 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,1);
      *(u32 *)param_5 = uVar1;
    }
    if (param_6 != 0) {
      uVar1 = FUN_00303130(param_1,param_2,param_3,1,1,1,param_4,2);
      *(u32 *)param_6 = uVar1;
    }
    if (param_7 != 0) {
      if (0x1cf < (s32)(param_1 & 0xffff)) {
        FUN_0019d3f0((u32)D_0069aa80, 0xbfa);
      }
      iVar2 = ((u32)param_1 & 0xffff) * 0x2c + DAT_007ce3f8;
      if (*(u8 *)(iVar2 + 0x18) == 2) {
        if (*(u8 *)(iVar2 + 0x19) < 100) {
          FUN_0019d3f0((u32)D_0069aa80, 0xc05);
        }
        uVar1 = FUN_00305970(param_1,param_2,param_3);
      }
      else {
        uVar1 = 0;
      }
    }
    *(u32 *)((int)param_2 + 0x18) = 0;
    *(u32 *)((int)param_3 + 0x18) = 0;
    uVar1 = 1;
  }
  return uVar1;
}





// FUN_00306d90
u32 FUN_00306d90(u16 param_1,u32 param_2)
{
  u32 uVar1;
  s32 lVar2;
  u32 uVar3;
  u32 uVar4;

  uVar3 = param_2 & 0xffff;
  uVar1 = (uVar3 & 0xff00) << 0x10;
  uVar3 = (uVar3 & 0xffff00ff) * 5;
  uVar4 = uVar1 | uVar3;
  if ((uVar4 & 0xffff) == 0) {
    if ((uVar4 & 0x8000000) != 0) {
      lVar2 = FUN_0016f190(0x1319);
      if (lVar2 == 0) {
        uVar4 = uVar4 | 0x7d;
      }
      else {
        if (param_1 == 0) {
          uVar1 = 0x7d;
        }
        else {
          uVar1 = 0x96;
        }
        uVar4 = uVar4 | uVar1;
      }
    }
    else if ((uVar4 & 0x27000000) != 0) {
      uVar4 = uVar4 | 100;
    }
    else if ((uVar4 & 0x10000000) != 0) {
      uVar4 = uVar4 | 0x32;
    }
  }
  return uVar4;
}





// FUN_00306e80 NONMATCHING
u32 FUN_00306e80(s32 param_1,s32 param_2)

{
  u8 bVar1;
  u16 uVar2;
  u32 uVar3;
  u32 uVar7;
  char cVar5;
  short sVar6;
  u32 uVar10;
  s32 lVar8;
  u32 uVar9;
  u8 bVar4;
  u16 *puVar11;

  short type;
  
  uVar10 = 0;
  bVar1 = false;
  bVar4 = false;
  type = (short)param_2;
  if (((type == 0x12) || (type == 0x11)) || (type == 0x10)) goto LAB_00306f00;
  if (type == -1) goto LAB_00306ef4;
  goto LAB_00306f0c;
LAB_00306ef4:
  return 0;
LAB_00306f00:
  return 100;
LAB_00306f0c:
  if (param_1 == 0) {
    FUN_0019d3f0((u32)D_0069aa80, 0xd2b);
  }
  if ((0x12 < type) || (type < 0)) {
    FUN_0019d3f0((u32)D_0069aa80, 0xd2c);
  }
  puVar11 = (u16 *)param_1;
  if ((*puVar11 & 4) == 0) {
    uVar7 = FUN_00173460(puVar11[1],param_2 & 0xffff);
  }
  else {
    if (0x14f < puVar11[2]) {
      FUN_0019d3f0((u32)D_0069aa80, 0xd37);
    }
    uVar2 = *(u16 *)(DAT_007ce414 + (u32)puVar11[2] * 0x20 + type * 2);
    uVar9 = (uVar2 & 0xff00) << 0x10;
    uVar3 = (uVar2 & 0xffff00ff) * 5;
    uVar7 = uVar9 | uVar3;
    if (uVar3 == 0) {
      if ((uVar9 & 0x8000000) == 0) {
        if ((uVar9 & 0x27000000) == 0) {
          if ((uVar9 & 0x10000000) != 0) {
            uVar7 = uVar7 | 0x32;
          }
        }
        else {
          uVar7 = uVar7 | 100;
        }
      }
      else {
        lVar8 = FUN_0016f190(0x1319);
        if (lVar8 == 0) {
          uVar7 = uVar7 | 0x7d;
        }
        else {
          uVar7 = uVar7 | 0x96;
        }
      }
    }
  }
  if (((type == 2) || (type == 1)) || (type == 0)) {
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x52);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x53);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x54);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) goto LAB_0030711c;
      }
    }
    bVar4 = true;
  }
LAB_0030711c:
  if ((((type == 6) || (type == 5)) || (type == 4)) || (type == 3)) {
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x61);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x62);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],99);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) goto LAB_003071f4;
      }
    }
    bVar4 = true;
  }
LAB_003071f4:
  switch(type) {
  case 0:
    lVar8 = FUN_003005e0(param_1,0x1d0);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d1);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d2);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d3);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x4c);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x4d);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x4e);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 1:
    lVar8 = FUN_003005e0(param_1,0x1d4);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d5);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d6);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d7);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x49);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x4a);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x4b);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 2:
    lVar8 = FUN_003005e0(param_1,0x1d8);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1d9);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1da);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1db);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x4f);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x50);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x51);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 3:
    lVar8 = FUN_003005e0(param_1,0x1dc);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1dd);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1de);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1df);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    cVar5 = FUN_00300f60(param_1,0xd);
    bVar1 = '\0' < cVar5;
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x55);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x56);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x57);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 4:
    lVar8 = FUN_003005e0(param_1,0x1e0);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e1);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e2);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e3);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    cVar5 = FUN_00300f60(param_1,0xe);
    bVar1 = '\0' < cVar5;
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x58);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x59);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x5a);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 5:
    lVar8 = FUN_003005e0(param_1,0x1e4);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e5);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e6);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e7);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    cVar5 = FUN_00300f60(param_1,0x10);
    bVar1 = '\0' < cVar5;
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x5e);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x5f);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x60);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 6:
    lVar8 = FUN_003005e0(param_1,0x1e8);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1e9);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1ea);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1eb);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x4000000;
    }
    cVar5 = FUN_00300f60(param_1,0xf);
    bVar1 = '\0' < cVar5;
    if ((*puVar11 & 4) == 0) {
      lVar8 = FUN_00300750(puVar11[1],0x5b);
    }
    else {
      lVar8 = 0;
    }
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        lVar8 = FUN_00300750(puVar11[1],0x5c);
      }
      else {
        lVar8 = 0;
      }
      if (lVar8 == 0) {
        if ((*puVar11 & 4) == 0) {
          lVar8 = FUN_00300750(puVar11[1],0x5d);
        }
        else {
          lVar8 = 0;
        }
        if (lVar8 == 0) break;
      }
    }
    bVar4 = true;
    break;
  case 8:
    lVar8 = FUN_003005e0(param_1,0x1ec);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1ed);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1ee);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    break;
  case 9:
    lVar8 = FUN_003005e0(param_1,0x1ef);
    if (lVar8 != 0) {
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f0);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f1);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x2000000;
    }
    break;
  case 10:
    lVar8 = FUN_003005e0(param_1,0x264);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xb7);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307be4;
    }
    else {
LAB_00307be4:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f2);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1fa);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    break;
  case 0xb:
    lVar8 = FUN_003005e0(param_1,0x26b);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xbc);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307c84;
    }
    else {
LAB_00307c84:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f9);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    break;
  case 0xc:
    lVar8 = FUN_003005e0(param_1,0x265);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xb8);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307d04;
    }
    else {
LAB_00307d04:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,499);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1fa);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    break;
  case 0xd:
    lVar8 = FUN_003005e0(param_1,0x266);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xb9);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307da4;
    }
    else {
LAB_00307da4:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,500);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1fa);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    break;
  case 0xe:
    lVar8 = FUN_003005e0(param_1,0x267);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xba);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307e44;
    }
    else {
LAB_00307e44:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f5);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1fa);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    break;
  case 0xf:
    lVar8 = FUN_003005e0(param_1,0x268);
    if (lVar8 == 0) {
      if ((*puVar11 & 4) == 0) {
        sVar6 = FUN_00300870(puVar11[1],0xbb);
      }
      else {
        sVar6 = 0;
      }
      if (sVar6 != 0) goto LAB_00307ee4;
    }
    else {
LAB_00307ee4:
      uVar10 = 0x10000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1f6);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
    lVar8 = FUN_003005e0(param_1,0x1fa);
    if (lVar8 != 0) {
      uVar10 = uVar10 | 0x1000000;
    }
  }
  if ((type != 7) && (lVar8 = FUN_003005e0(param_1,0x1fb), lVar8 != 0)) {
    uVar10 = uVar10 | 0x1000000;
  }
  if ((bVar4) && ((uVar7 & 0x8000000) != 0)) {
    uVar7 = uVar7 & 0xf7ff0000 | 100;
  }
  if (uVar10 != 0) {
    if (((uVar10 & 0x10000000) != 0) && ((uVar7 & 0x7000000) == 0)) {
      uVar7 = uVar7 & 0xf7ff0000 | 0x10000032;
    }
    if (((uVar10 & 0x1000000) != 0) && ((uVar7 & 0x6000000) == 0)) {
      uVar7 = uVar7 & 0xe7ff0000 | 0x1000064;
    }
    if (((uVar10 & 0x2000000) != 0) && ((uVar7 & 0x4000000) == 0)) {
      uVar7 = uVar7 & 0xe6ff0000 | 0x2000064;
    }
    if ((uVar10 & 0x4000000) != 0) {
      uVar7 = uVar7 & 0xe4ff0000 | 0x4000064;
    }
  }
  if ((bVar1) && ((uVar7 & 0x17000000) != 0)) {
    uVar7 = uVar7 & 0xe8ff0000 | 100;
  }
  return uVar7;
}





// FUN_003080c0
int FUN_003080c0(short param_1)

{
  if (param_1 < 0x13) {
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80,0xea8);
  }
  return 1 << ((int)param_1 + 1U);
}





// FUN_00308120 NONMATCHING
short FUN_00308120(short param_1,int param_2)

{
  short unaff_s0_lo;
  
  if ((param_1 != -1) && (unaff_s0_lo = FUN_003082f0(0,param_1), unaff_s0_lo == 8)) {
    return 8;
  }
  if (param_2 == 0x100000) {
    unaff_s0_lo = 7;
  }
  else if (param_2 == 0x80000) {
    unaff_s0_lo = 9;
  }
  else if (param_2 == 0x400) {
    unaff_s0_lo = 7;
  }
  else if (param_2 == 0x200) {
    unaff_s0_lo = 7;
  }
  else if (param_2 == 0x100) {
    unaff_s0_lo = 7;
  }
  else if (param_2 == 0x80) {
    unaff_s0_lo = 0xb;
  }
  else if (param_2 == 0x40) {
    unaff_s0_lo = 5;
  }
  else if (param_2 == 0x20) {
    unaff_s0_lo = 4;
  }
  else if (param_2 == 0x10) {
    unaff_s0_lo = 0xf;
  }
  else if (param_2 == 8) {
    unaff_s0_lo = 0xe;
  }
  else if (param_2 == 4) {
    unaff_s0_lo = 0xd;
  }
  else if (param_2 == 2) {
    unaff_s0_lo = 0xc;
  }
  else if (param_2 == 1) {
    unaff_s0_lo = 10;
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80, 0xee9);
  }
  return unaff_s0_lo;
}





// FUN_003082f0
s32 FUN_003082f0(s32 param_1,u32 param_2)
{
  s16 sVar1;
  u16 uVar1;
  s32 index;
  u16 *puVar3;

  index = (u16)param_2;
  if (((param_1 != 0) && (index < 0x1d0)) &&
      ((*(u8 *)(DAT_007ce3f8 + index * 0x2c) & 2) != 0)) {
    puVar3 = (u16 *)param_1;
    if ((*puVar3 & 4) != 0) {
      index = *(u16 *)((u8 *)(uintptr_t)((u32)puVar3[1] * 0x3e) +
                       (uintptr_t)DAT_007ce410 + 0x3c);
    }
    else {
      sVar1 = FUN_0016cb80((s16)puVar3[1],0);
      uVar1 = FUN_0016f630((s16)puVar3[1],sVar1);
      index = FUN_00170d60((s16)uVar1);
      return (s32)*(short *)(index + 0x1e);
    }
  }
  return (s32)*(char *)(DAT_007ce3f4 + ((u32)index & 0xffff) * 2);
}





// FUN_003083f0 NONMATCHING
u32 FUN_003083f0(u32 param_1,u32 param_2)

{
  char cVar1;
  u32 uVar2;
  s32 lVar3;
  int iVar4;
  u16 *puVar5;
  
  if (0x1cf < param_2) {
    FUN_0019d3f0((u32)D_0069aa80, 0xf27);
  }
  uVar2 = 0;
  lVar3 = FUN_0017d800();
  puVar5 = (u16 *)param_1;
  if ((lVar3 == 0) || ((*(u32 *)(puVar5 + 6) & 0x100) == 0)) {
    cVar1 = *(char *)((u32)param_2 * 0x2c + DAT_007ce3f8 + 3);
    if (cVar1 == '\x02') {
      if ((*puVar5 & 4) != 0) {
        if (0x14f < puVar5[1]) {
          FUN_0019d3f0((u32)D_0069aa80, 0xf51);
        }
        if ((*(u16 *)(DAT_007ce410 + (u32)puVar5[1] * 0x3e) & 2) != 0) {
          return 0;
        }
      }
      if ((*(u8 *)(DAT_007ce3f8 + (u32)param_2 * 0x2c) & 0x10) == 0) {
        iVar4 = (u32)param_2 * 0x2c + DAT_007ce3f8;
        uVar2 = (u32)*(u16 *)(iVar4 + 4) + (u32)*(u16 *)(iVar4 + 6);
      }
      else {
        uVar2 = FUN_00300100(param_1);
        iVar4 = (u32)param_2 * 0x2c + DAT_007ce3f8;
        uVar2 = (int)((uVar2 & 0xffff) * (u32)*(u16 *)(iVar4 + 4)) / 100 +
                (u32)*(u16 *)(iVar4 + 6);
      }
      if (uVar2 != 0) {
        lVar3 = FUN_003005e0(param_1,0x235);
        if (lVar3 != 0) {
          uVar2 = uVar2 >> 1;
        }
        if (uVar2 == 0) {
          uVar2 = 1;
        }
      }
    }
    else if (cVar1 == '\x01') {
      if ((*puVar5 & 4) == 0) {
        uVar2 = FUN_002ffdf0(param_1);
        iVar4 = (u32)param_2 * 0x2c + DAT_007ce3f8;
        uVar2 = (int)((uVar2 & 0xffff) * (u32)*(u16 *)(iVar4 + 4)) / 100 +
                (u32)*(u16 *)(iVar4 + 6);
        lVar3 = FUN_003005e0(param_1,0x236);
        if (lVar3 != 0) {
          uVar2 = uVar2 >> 1;
        }
        if (uVar2 == 0) {
          uVar2 = 1;
        }
      }
      else {
        if (0x14f < puVar5[1]) {
          FUN_0019d3f0((u32)D_0069aa80, 0xf38);
        }
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}





// FUN_003086c0
u8 FUN_003086c0(void *param_1,u32 param_2)

{
  u8 *table;

  table = (u8 *)DAT_007ce3f8;
  return table[(param_2 & 0xffff) * 0x2c + 3];
}





// FUN_003086f0
u32 FUN_003086f0(u32 param_1,u32 param_2)
{
  u8 cVar1;
  u32 uVar2;
  s32 lVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  
  uVar5 = 0;
  if ((s32)(param_2 & 0xffff) >= 0x270) {
    FUN_0019d3f0((u32)D_0069aa80, 0xf93);
  }
  uVar2 = FUN_003083f0(param_1,param_2);
  iVar4 = ((u32)param_2 & 0xffff) * 0x2c;
  cVar1 = *(char *)(iVar4 + DAT_007ce3f8 + 3);
  iVar6 = (int)param_1;
  if (cVar1 == '\x02') {
    goto case2;
  }
  switch (cVar1) {
  case '\x01':
    goto case1;
  default:
    goto done;
  }
case1:
  lVar3 = FUN_003005e0(param_1,0x242);
  if (lVar3 != 0) {
    uVar5 = 3;
    goto done;
  }
  if ((*(u8 *)(DAT_007ce3f8 + iVar4) & 1) == 0) {
    if (*(u16 *)(iVar6 + 8) <= uVar2) {
      uVar5 = 1;
    }
  }
  else if (*(u16 *)(iVar6 + 8) < uVar2) {
    uVar5 = 1;
  }
  goto done;
case2:
  lVar3 = FUN_003005e0(param_1,0x241);
  if (lVar3 != 0) {
    uVar5 = 3;
    goto done;
  }
  if (*(u16 *)(iVar6 + 10) < uVar2) {
    uVar5 = 2;
  }
done:
  return uVar5;
}





// FUN_00308860
u32 FUN_00308860(u16 param_1)

{
  u32 uVar1;
  
  switch(param_1) {
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}





// FUN_003088b0
u8 FUN_003088b0(u16 param_1)

{
  if (param_1 < 0x1d0) {
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80,0xfdb);
  }
  return (*(u8 *)(iGpffffb708 + (u32)param_1 * 0x2c) & 2) != 0;
}





// FUN_00308930
u16 FUN_00308930(u16 *param_1)
{
  s16 sVar1;
  u16 uVar1;
  int iVar2;
  
  if ((*param_1 & 4) != 0) {
    return *(u16 *)((u8 *)(uintptr_t)((u32)param_1[1] * 0x3e) +
                    (uintptr_t)iGpffffb720 + 0x3c);
  }
  sVar1 = FUN_0016cb80((s16)param_1[1],0);
  uVar1 = FUN_0016f630((s16)param_1[1],sVar1);
  iVar2 = FUN_00170d60((s16)uVar1);
  switch(*(u16 *)(iVar2 + 0x1e)) {
  case 0:
    return 0;
  case 1:
    return 0x15f;
  case 2:
    return 0x15e;
  case 3:
    return 0x15d;
  case 5:
    return 0x15c;
  case 6:
    return 0x15b;
  case 4:
    return 0x15a;
  default:
    return 0;
  }
}





// FUN_00308a50
u8 FUN_00308a50(u16 param_1)

{
  u32 uVar1 = 0;

  if (param_1 < 0x110) {
    goto done;
  }
  if (param_1 >= 0x131) {
    goto done;
  }
  uVar1 = 1;
done:
  return uVar1 != 0;
}





// FUN_00308a80 NONMATCHING
u16 FUN_00308a80(u32 param_1)

{
  u16 uVar2;
  u16 uVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u16 auStack_20 [16];
  
  uVar3 = FUN_00308ba0();
  iVar4 = FUN_00308bb0((u16*)param_1);
  uVar6 = 0;
  uVar5 = 0;
  while ((uVar5 < (uVar3 & 0xffff) && (uVar6 < 0x10))) {
    uVar2 = *(u16 *)(iVar4 + uVar5 * 2);
    switch(uVar2) {
    case 0xc0:
    case 0xc1:
    case 0xc2:
    case 0xc3:
    case 0xc4:
    case 0xc5:
      auStack_20[uVar6] = uVar2;
      uVar6 = uVar6 + 1 & 0xffff;
      break;
    default:
      break;
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if (uVar6 == 0) {
    return 0;
  }
  iVar4 = FUN_002ffbc0(uVar6);
  return auStack_20[iVar4];
}





// FUN_00308bb0
int FUN_00308bb0(u16 *param_1)

{
  int iVar1;
  
  if ((*param_1 & 4) == 0) {
    if (param_1[1] >= 0xb) {
      FUN_0019d3f0((u32)D_0069aa80,0x1051);
    }
    iVar1 = (int)FUN_00173380(param_1[1]);
  }
  else {
    if (param_1[1] >= 0x150) {
      FUN_0019d3f0((u32)D_0069aa80,0x1054);
    }
    iVar1 = iGpffffb720 + (u32)param_1[1] * 0x3e + 0xe;
  }
  return iVar1;
}





// FUN_00308ed0
u16 FUN_00308ed0(u16 *param_1)
{
    u16 result;

    if ((*param_1 & 4) != 0)
    {
        return 0;
    }

    if (param_1[1] >= 0xb)
    {
        FUN_0019d3f0((u32)D_0069aa80, 0x10b8);
    }

    result = FUN_0016f630(
        (s16)param_1[1],
        (s16)FUN_0016cb80((s16)param_1[1], 0));

    if (result >= 0xff)
    {
        FUN_0019d3f0((u32)D_0069aa80, 0x10bd);
    }

    return result;
}





// FUN_00308f80
u8 FUN_00308f80(u16 *param_1)

{
  u32 uVar2;

  if ((*param_1 & 4) != 0) {
    return 1;
  }
  uVar2 = FUN_00308c60();
  return ((u8*)&gp0xffff9d08)[uVar2 & 0xff];
}





// FUN_00308fd0
u8 FUN_00308fd0(u16 *param_1,u16 param_2)
{
  u8 mode;

  if ((*param_1 & 4) != 0) {
    mode = 1;
  }
  else {
    u32 index = FUN_00308c60();
    mode = ((u8 *)&gp0xffff9d08)[index & 0xff];
  }
  if (mode == 1) {
    return 1;
  }
  if ((param_2 & 6) != 0) {
    return mode;
  }
  if (param_2 == 8) {
    return 2;
  }
  return 1;
}





// FUN_00309080 NONMATCHING
u32 FUN_00309080(u16 *param_1,char param_2)

{
  u16 uVar1;
  u16 uVar2;
  u32 uVar3;
  int iVar4;
  
  if ((*param_1 & 4) == 0) {
    uVar1 = param_1[1];
    if (10 < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0x1116);
    }
    uVar2 = FUN_0016cb80(uVar1,0);
    if (param_2 == '\x01') {
      uVar3 = FUN_0016fae0(uVar1,uVar2);
      return uVar3;
    }
    if (param_2 == '\0') {
      uVar3 = FUN_0016f9f0(uVar1);
      return uVar3;
    }
    FUN_0019d3f0((u32)D_0069aa80, 0x111f);
  }
  else {
    uVar1 = param_1[1];
    if (0x14f < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0x1106);
    }
    iVar4 = (u32)uVar1 * 0x3e;
    uVar1 = *(u16 *)(iVar4 + iGpffffb720 + 0x3c);
    if ((*(u8 *)(iGpffffb708 + ((u32)uVar1 * 10 + (u32)uVar1) * 4) & 2) == 0) {
      FUN_0019d3f0((u32)D_0069aa80, 0x1108);
    }
    if (param_2 == '\x01') {
      return (u32)*(u8 *)(iVar4 + iGpffffb720 + 0x38);
    }
    if (param_2 == '\0') {
      return (u32)*(u16 *)(iVar4 + iGpffffb720 + 0x3a);
    }
    FUN_0019d3f0((u32)D_0069aa80, 0x1112);
  }
  return 0;
}





// FUN_00309250 NONMATCHING
u32 FUN_00309250(u16 *param_1,char param_2)

{
  u16 uVar1;
  u16 uVar2;
  u32 uVar3;
  
  if ((*param_1 & 4) == 0) {
    uVar1 = param_1[1];
    if (10 < uVar1) {
      FUN_0019d3f0((u32)D_0069aa80, 0x1141);
    }
    if (param_2 == '\x01') {
      uVar2 = FUN_0016cb80(uVar1);
      uVar3 = FUN_0016fbd0(uVar1,uVar2);
      return uVar3;
    }
    if (param_2 == '\0') {
      uVar2 = FUN_0016cb80(uVar1,2);
      uVar3 = FUN_0016fcc0(uVar1,uVar2);
      return uVar3;
    }
    FUN_0019d3f0((u32)D_0069aa80, 0x114b);
  }
  else {
    if (param_2 == '\x01') {
      return 10;
    }
    if (param_2 == '\0') {
      return 10;
    }
    FUN_0019d3f0((u32)D_0069aa80, 0x113d);
  }
  return 0;
}





// FUN_003093a0
u8 FUN_003093a0(u16 *param_1)

{
  s16 uVar1;
  u16 result;
  u32 uVar2;
  
  if ((*param_1 & 4) != 0) {
    uVar2 = 0;
  }
  else {
    if (param_1[1] >= 0xb) {
      FUN_0019d3f0((u32)D_0069aa80, 0x10b8);
    }
    uVar1 = FUN_0016cb80((s16)param_1[1],0);
    result = FUN_0016f630((s16)param_1[1],uVar1);
    if (result >= 0xff) {
      FUN_0019d3f0((u32)D_0069aa80, 0x10bd);
    }
    uVar2 = result;
  }
  result = uVar2;
  if ((result < 0xc0) || (result >= 0xe0)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x115f);
  }
  return *(u8 *)(result + iGpffffb79c + -0xc0);
}





// FUN_00309490 NONMATCHING
u32 FUN_00309490(s32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u8 bVar1;
  char cVar2;
  u16 uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  u32 uVar7;
  s32 lVar8;
  u32 uVar9;
  u32 uVar10;
  u8 *pbVar11;
  u32 uVar12;
  short sVar13;
  u16 unaff_s1_lo;
  u16 uVar14;
  u16 *puVar16;
  u16 *puVar17;
  s32 lVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  u16 uVar15;
  
  if (0x1cf < (param_3 & 0xffff)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x1175);
  }
  uVar12 = (u32)param_3 & 0xffff;
  iVar19 = uVar12 * 0x2c;
  pbVar11 = (u8 *)(iVar19 + iGpffffb708);
  puVar16 = (u16 *)param_2;
  if (pbVar11[0x24] == 1) {
    if ((*(u32 *)(puVar16 + 6) & 8) != 0) {
      return 1;
    }
    return 4;
  }
  puVar17 = (u16 *)param_1;
  if (((param_1 == 0) || (0x1cf < (param_3 & 0xffff))) || ((*pbVar11 & 2) == 0)) {
LAB_003095fc:
    lVar18 = (s32)*(char *)(iGpffffb704 + uVar12 * 2);
  }
  else {
    if ((*puVar17 & 4) != 0) {
      uVar12 = (u32)*(u16 *)((u32)puVar17[1] * 0x3e + iGpffffb720 + 0x3c);
      goto LAB_003095fc;
    }
    uVar3 = FUN_0016cb80(puVar17[1],0);
    uVar3 = FUN_0016f630(puVar17[1],uVar3);
    iVar6 = FUN_00170d60(uVar3);
    lVar18 = (s32)*(short *)(iVar6 + 0x1e);
  }
  sVar13 = (short)lVar18;
  if (0x12 < sVar13) {
    FUN_0019d3f0((u32)D_0069aa80, 0xea8);
  }
  uVar12 = 1 << ((int)sVar13 + 1U & 0x1f);
  if ((uVar12 & 0xe0001) == 0) {
    if ((uVar12 & 0xe) == 0) {
      if (((uVar12 & 0x100) == 0) && ((*(u32 *)(puVar16 + 10) & 0x40000) != 0)) {
        *(u32 *)(puVar16 + 0xc) = *(u32 *)(puVar16 + 0xc) | 0x40000;
        return 0x200;
      }
    }
    else {
      if ((*(u32 *)(puVar16 + 10) & 0x20000) != 0) {
        *(u32 *)(puVar16 + 0xc) = *(u32 *)(puVar16 + 0xc) | 0x20000;
        return 0x200;
      }
      if ((param_4 & 2) == 0) {
        sVar5 = 0;
        lVar8 = FUN_003005e0(param_2,0x222);
        if (lVar8 == 0) {
          if ((*puVar16 & 4) == 0) {
            sVar4 = FUN_00300870(puVar16[1],0xb3);
          }
          else {
            sVar4 = 0;
          }
          if (sVar4 != 0) goto LAB_00309700;
          lVar8 = FUN_003005e0(param_2,0x221);
          if (lVar8 == 0) {
            if ((*puVar16 & 4) == 0) {
              sVar4 = FUN_00300870(puVar16[1],0xb2);
            }
            else {
              sVar4 = 0;
            }
            if (sVar4 != 0) goto LAB_00309760;
            lVar8 = FUN_003005e0(param_2,0x220);
            if (lVar8 == 0) {
              if ((*puVar16 & 4) == 0) {
                sVar4 = FUN_00300870(puVar16[1],0xb1);
              }
              else {
                sVar4 = 0;
              }
              if (sVar4 != 0) goto LAB_003097c0;
            }
            else {
LAB_003097c0:
              sVar5 = 10;
              unaff_s1_lo = 0x1220;
            }
          }
          else {
LAB_00309760:
            sVar5 = 0xf;
            unaff_s1_lo = 0x1221;
          }
        }
        else {
LAB_00309700:
          sVar5 = 0x14;
          unaff_s1_lo = 0x1222;
        }
        if ((sVar5 != 0) && (sVar4 = FUN_002ffbc0(100), sVar4 < sVar5)) {
          puVar16[0x1c] = unaff_s1_lo;
          return 0x200;
        }
      }
    }
    cVar2 = FUN_00300f60(param_2,0xb);
    if ('\0' < cVar2) {
      return 0x200;
    }
    cVar2 = FUN_00300f60(param_2,8);
    if ('\0' < cVar2) {
      return 0x100;
    }
    cVar2 = FUN_00300f60(param_2,9);
    if ('\0' < cVar2) {
      return 0x100;
    }
    uVar9 = FUN_0030b4b0(param_2,lVar18);
    if ((uVar9 & 0x2000000) != 0) {
      return 0x200;
    }
    if ((uVar9 & 0x4000000) != 0) {
      return 0x400;
    }
    if ((uVar9 & 0x1000000) != 0) {
      return 0x100;
    }
  }
  bVar1 = *(u8 *)(iGpffffb708 + 0xe + iVar19);
  if (bVar1 == 0) {
    return 4;
  }
  if ((*(u32 *)(puVar16 + 6) & 0x100000) != 0) {
    return 1;
  }
  if (99 < bVar1) {
    return 1;
  }
  if ((*puVar16 & 0x80) != 0) {
    return 1;
  }
  uVar10 = *(u32 *)(puVar16 + 6) & 0xfffff;
  if ((((uVar10 == 0x200) || (uVar10 == 2)) || (uVar10 == 0x40)) || (uVar10 == 0x20)) {
    return 1;
  }
  fVar20 = (float)FUN_00301880(param_1,4);
  fVar21 = (float)FUN_00301880(param_2,2);
  fVar25 = 1.0;
  fVar24 = 1.0;
  iVar19 = 0;
  uVar15 = 0;
  uVar14 = 0;
  fVar23 = fVar25;
  if ((*puVar17 & 4) == 0) {
    sVar5 = FUN_0016c920(puVar17[1]);
  }
  else {
    sVar5 = 0;
  }
  if (sVar5 == 5) {
LAB_00309aac:
    lVar18 = FUN_0016f190(0x1319);
    fVar22 = fGpffff8088;
    if (lVar18 == 0) {
      fVar22 = 0.5;
    }
    fVar23 = fVar23 * fVar22;
  }
  else {
    if ((*puVar17 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar17[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 == 4) goto LAB_00309aac;
  }
  if ((*puVar16 & 4) == 0) {
    sVar5 = FUN_0016c920(puVar16[1]);
  }
  else {
    sVar5 = 0;
  }
  if (sVar5 != 5) {
    if ((*puVar16 & 4) == 0) {
      sVar5 = FUN_0016c920(puVar16[1]);
    }
    else {
      sVar5 = 0;
    }
    if (sVar5 != 4) {
      if ((*puVar16 & 4) == 0) {
        sVar5 = FUN_0016c920(puVar16[1]);
      }
      else {
        sVar5 = 0;
      }
      if (sVar5 != 1) {
        if ((*puVar16 & 4) == 0) {
          sVar5 = FUN_0016c920(puVar16[1]);
        }
        else {
          sVar5 = 0;
        }
        if (sVar5 == 2) {
          fVar23 = fVar23 * fGpffff829c;
        }
      }
      goto LAB_00309c04;
    }
  }
  lVar18 = FUN_0016f190(0x1319);
  fVar22 = fGpffff82a8;
  if (lVar18 == 0) {
    fVar22 = 2.0;
  }
  fVar23 = fVar23 * fVar22;
LAB_00309c04:
  if ((param_4 & 2) == 0) {
    uVar14 = uVar15;
    switch(sVar13) {
    case 0:
      lVar18 = FUN_003005e0(param_2,0x1fd);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x1fc);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x11fc;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x11fd;
      }
      break;
    case 1:
      lVar18 = FUN_003005e0(param_2,0x1ff);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x1fe);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x11fe;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x11ff;
      }
      break;
    case 2:
      lVar18 = FUN_003005e0(param_2,0x201);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x200);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x1200;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x1201;
      }
      break;
    case 3:
      lVar18 = FUN_003005e0(param_2,0x203);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x202);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x1202;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x1203;
      }
      break;
    case 4:
      lVar18 = FUN_003005e0(param_2,0x205);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x204);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x1204;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x1205;
      }
      break;
    case 5:
      lVar18 = FUN_003005e0(param_2,0x209);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x208);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x1208;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x1209;
      }
      break;
    case 6:
      lVar18 = FUN_003005e0(param_2,0x207);
      if (lVar18 == 0) {
        lVar18 = FUN_003005e0(param_2,0x206);
        fVar25 = fVar24;
        if (lVar18 != 0) {
          fVar25 = fGpffff80a4 * 1.0;
          uVar14 = 0x1206;
        }
      }
      else {
        fVar25 = fGpffff80c4 * 1.0;
        uVar14 = 0x1207;
      }
    }
    if (fVar25 == 1.0) {
      if (((uVar12 & 0xe) != 0) && (lVar18 = FUN_003005e0(param_2,0x20e), lVar18 != 0)) {
        fVar25 = fVar25 * fGpffff80a4;
        uVar14 = 0x120e;
      }
      if (((uVar12 & 0x6f0) != 0) && (lVar18 = FUN_003005e0(param_2,0x20f), lVar18 != 0)) {
        fVar25 = fVar25 * fGpffff80a4;
        uVar14 = 0x120f;
      }
    }
    lVar18 = FUN_003005e0(param_2,0x234);
    if (lVar18 != 0) {
      return 1;
    }
    lVar18 = FUN_003005e0(param_2,0x233);
    if (lVar18 != 0) {
      fVar25 = fVar25 * 0.5;
    }
    cVar2 = FUN_00300f60(param_2,10);
    if ('\0' < cVar2) {
      fVar25 = fVar25 * fGpffff80e0;
    }
    if ((*(u32 *)(puVar16 + 6) & 0x100) != 0) {
      FUN_0017d800();
      fVar23 = fVar23 * 0.5;
    }
  }
  iVar6 = FUN_0030fc40(4,param_1,param_2,param_3,0);
  if ((*puVar16 & 4) == 0) {
    if (((sVar13 == 2) || (sVar13 == 1)) || (sVar13 == 0)) {
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x70);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x71);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x72);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
    }
    if (((sVar13 == 6) || (sVar13 == 5)) || ((sVar13 == 4 || (sVar13 == 3)))) {
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7f);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x80);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x81);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
    }
    switch(sVar13) {
    case 0:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6a);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6b);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6c);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 1:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x67);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x68);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x69);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 2:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6d);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6e);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x6f);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 3:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x73);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x74);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x75);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 4:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x76);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x77);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x78);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 5:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7c);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7d);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7e);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
      break;
    case 6:
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x79);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 5;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7a);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 10;
      }
      if ((*puVar16 & 4) == 0) {
        lVar18 = FUN_00300750(puVar16[1],0x7b);
      }
      else {
        lVar18 = 0;
      }
      if (lVar18 != 0) {
        iVar19 = iVar19 + 0xf;
      }
    }
  }
  iVar19 = (int)(fVar25 * fVar23 * fVar21 * (float)iVar6 * fVar20) - iVar19;
  if (iVar19 < 100) {
    if (iVar19 < 0x32) {
      iVar19 = 0x32;
    }
  }
  else {
    iVar19 = 99;
  }
  iVar6 = FUN_002ffbc0(100);
  if (iVar6 < iVar19) {
    uVar7 = 1;
  }
  else {
    puVar16[0x1c] = uVar14;
    uVar7 = 4;
  }
  return uVar7;
}





// FUN_0030a740 NONMATCHING
u32 FUN_0030a740(s32 param_1,u32 param_2,u32 param_3,short param_4)

{
  char cVar1;
  u8 bVar2;
  u16 uVar3;
  short sVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  s32 lVar9;
  s32 lVar10;
  u32 uVar11;
  u32 uVar12;
  int iVar13;
  s32 lVar14;
  u16 *puVar15;
  int iVar16;
  float fVar17;
  
  uVar12 = param_3 & 0xffff;
  if (0x1cf < uVar12) {
    FUN_0019d3f0((u32)D_0069aa80, 0x139b);
  }
  if ((((param_4 == 4) || (param_4 == 2)) || (param_4 == 0x100)) ||
     ((param_4 == 0x400 || (param_4 == 0x200)))) {
    return 1;
  }
  uVar6 = (u32)param_3;
  uVar11 = uVar6 & 0xffff;
  puVar15 = (u16 *)param_1;
  if (((param_1 != 0) && (uVar12 < 0x1d0)) && ((*(u8 *)(iGpffffb708 + uVar11 * 0x2c) & 2) != 0)) {
    if ((*puVar15 & 4) == 0) {
      uVar3 = FUN_0016cb80(puVar15[1],0);
      uVar3 = FUN_0016f630(puVar15[1],uVar3);
      iVar16 = FUN_00170d60(uVar3);
      lVar14 = (s32)*(short *)(iVar16 + 0x1e);
      goto LAB_0030a8c0;
    }
    uVar11 = (u32)*(u16 *)((u32)puVar15[1] * 0x3e + iGpffffb720 + 0x3c);
  }
  lVar14 = (s32)*(char *)(iGpffffb704 + uVar11 * 2);
LAB_0030a8c0:
  if (0x12 < (short)lVar14) {
    FUN_0019d3f0((u32)D_0069aa80, 0xea8);
  }
  uVar7 = 1;
  uVar11 = 1 << ((int)(short)lVar14 + 1U & 0x1f);
  if ((uVar11 & 0xe0001) == 0) {
    uVar8 = FUN_0030b4b0(param_2,lVar14);
    if (((uVar11 & 0xe) == 0) &&
       (((uVar11 & 0x100) == 0 || (*(char *)((uVar6 & 0xffff) * 0x2c + iGpffffb708 + 2) != '\x01')))
       ) {
      if ((uVar8 & 0x8000000) == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 4;
      }
    }
    else {
      iVar16 = (uVar6 & 0xffff) * 0x2c;
      cVar1 = *(char *)(iGpffffb708 + 0x25 + iVar16);
      if (cVar1 == '\0') {
        if ((uVar8 & 0x8000000) == 0) {
          uVar7 = 1;
        }
        else {
          uVar7 = 4;
        }
      }
      else if ((*(u16 *)param_2 & 0x100) == 0) {
        if ((uVar8 & 0x8000000) == 0) {
          fVar17 = 1.0;
          lVar14 = 0;
          if (cVar1 == 'd') {
            lVar14 = 100;
          }
          cVar1 = *(char *)(iVar16 + iGpffffb708 + 2);
          if (cVar1 != '\x02') {
            if (cVar1 == '\x01') {
              lVar9 = lVar14;
              if (lVar14 == 0) {
                lVar9 = FUN_0030fc40(5,param_1,param_2,param_3,0);
              }
              lVar10 = FUN_003005e0(param_2,0x231);
              if (lVar10 != 0) {
                fVar17 = 0.5;
              }
              lVar10 = FUN_003005e0(param_1,0x232);
              if (lVar10 != 0) {
                fVar17 = fVar17 * 2.0;
              }
              iVar13 = 0;
              uVar6 = *(u32 *)((u16 *)param_2 + 6) & 0xfffff;
              if (uVar6 == 0x40) {
                iVar13 = 100;
              }
              else if (uVar6 == 8) {
                iVar13 = 100;
              }
              else if (uVar6 == 4) {
                iVar13 = 0x28;
              }
              else if (uVar6 == 2) {
                iVar13 = 0x32;
              }
              if ((*puVar15 & 4) == 0) {
                sVar4 = FUN_0016c920(puVar15[1]);
              }
              else {
                sVar4 = 0;
              }
              if (sVar4 != 1) {
                if ((*puVar15 & 4) == 0) {
                  sVar4 = FUN_0016c920(puVar15[1]);
                }
                else {
                  sVar4 = 0;
                }
                if (sVar4 == 2) {
                  iVar13 = iVar13 + 0xf;
                }
              }
              if (0x1cf < uVar12) {
                FUN_0019d3f0((u32)D_0069aa80, 0xfdb);
              }
              if ((*(u8 *)(iGpffffb708 + iVar16) & 2) != 0) {
                if ((*puVar15 & 4) == 0) {
                  lVar10 = FUN_00300750(puVar15[1],0x43);
                }
                else {
                  lVar10 = 0;
                }
                if (lVar10 != 0) {
                  iVar13 = iVar13 + 5;
                }
                if ((*puVar15 & 4) == 0) {
                  lVar10 = FUN_00300750(puVar15[1],0x44);
                }
                else {
                  lVar10 = 0;
                }
                if (lVar10 != 0) {
                  iVar13 = iVar13 + 10;
                }
                if ((*puVar15 & 4) == 0) {
                  lVar10 = FUN_00300750(puVar15[1],0x45);
                }
                else {
                  lVar10 = 0;
                }
                if (lVar10 != 0) {
                  iVar13 = iVar13 + 0xf;
                }
              }
              cVar1 = FUN_00300f60(param_1,5);
              if ('\0' < cVar1) {
                iVar13 = iVar13 + 7;
              }
              cVar1 = FUN_00300f60(param_1,6);
              if ('\0' < cVar1) {
                iVar13 = iVar13 + 0xf;
              }
              iVar13 = (int)((float)(int)lVar9 * fVar17) + iVar13;
              if (iVar13 < 0x65) {
                if (iVar13 < 0) {
                  iVar13 = 0;
                }
              }
              else {
                iVar13 = 100;
              }
              lVar9 = FUN_002ffbc0(100);
              if (lVar9 < lVar14) {
                return 2;
              }
              lVar14 = FUN_002ffbc0(100);
              if (lVar14 < 0) {
                return 2;
              }
              iVar5 = FUN_002ffbc0(100);
              if (iVar5 < iVar13) {
                return 2;
              }
              if (0x1cf < uVar12) {
                FUN_0019d3f0((u32)D_0069aa80, 0xfdb);
              }
              if ((*(u8 *)(iGpffffb708 + iVar16) & 2) != 0) {
                if ((*puVar15 & 4) == 0) {
                  uVar6 = FUN_00308c60(param_1);
                  bVar2 = (&gp0xffff9d08)[uVar6 & 0xff];
                }
                else {
                  bVar2 = 1;
                }
                if ((1 < bVar2) && ((*puVar15 & 4) == 0)) {
                  iVar16 = (int)((float)iVar13 * 2.0);
                  if (iVar16 < 0x33) {
                    if (iVar16 < 0) {
                      iVar16 = 0;
                    }
                  }
                  else {
                    iVar16 = 0x32;
                  }
                  iVar13 = FUN_002ffbc0(100);
                  if (iVar13 < iVar16) {
                    return 8;
                  }
                }
              }
            }
            else {
              FUN_0019d3f0((u32)D_0069aa80, 0x147e);
            }
          }
          uVar7 = 1;
        }
        else {
          uVar7 = 4;
        }
      }
      else if ((uVar8 & 0x8000000) == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 4;
      }
    }
  }
  return uVar7;
}





// FUN_0030af00 NONMATCHING
u32 FUN_0030af00(s32 param_1,u16 *param_2,u32 param_3,u32 param_4,u32 param_5)

{
  u16 uVar1;
  short sVar2;
  int iVar3;
  u32 uVar4;
  u16 *puVar5;
  
  if (0x1cf < param_3) {
    FUN_0019d3f0((u32)D_0069aa80, 0x1494);
  }
  if ((*(u32 *)(param_2 + 6) & 0x100000) != 0) {
    return false;
  }
  if (param_4 != 1) {
    return false;
  }
  if ((*param_2 & 0x10) != 0) {
    return false;
  }
  iVar3 = (u32)param_3 * 0x2c + iGpffffb708;
  if ((*(char *)(iVar3 + 0x11) == '\0') &&
     ((*(char *)(iVar3 + 0x18) != '\x01' || ((*(u32 *)(iVar3 + 0x1c) & 0x80000) == 0)))) {
    return false;
  }
  uVar4 = (u32)param_3;
  if (((param_1 != 0) && (param_3 < 0x1d0)) &&
     ((*(u8 *)(iGpffffb708 + (u32)param_3 * 0x2c) & 2) != 0)) {
    puVar5 = (u16 *)param_1;
    if ((*puVar5 & 4) == 0) {
      uVar1 = FUN_0016cb80(puVar5[1],0);
      uVar1 = FUN_0016f630(puVar5[1],uVar1);
      iVar3 = FUN_00170d60(uVar1);
      sVar2 = *(short *)(iVar3 + 0x1e);
      goto LAB_0030b0bc;
    }
    uVar4 = (u32)*(u16 *)((u32)puVar5[1] * 0x3e + iGpffffb720 + 0x3c);
  }
  sVar2 = (short)*(char *)(iGpffffb704 + uVar4 * 2);
LAB_0030b0bc:
  if (0x12 < sVar2) {
    FUN_0019d3f0((u32)D_0069aa80, 0xea8);
  }
  return (1 << ((int)sVar2 + 1U & 0x1f) & 0xe0001U) == 0;
}





// FUN_0030b130
u32
FUN_0030b130(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5)

{
  u32 uVar1;
  s32 lVar2;
  
  if ((s32)(param_3 & 0xffff) >= 0x1d0) {
    FUN_0019d3f0((u32)D_0069aa80,0x14c2);
  }
  lVar2 = FUN_0030af00(param_1,(u16*)param_2,param_3,param_4,param_5);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else if (((param_5 & 0xffff) == 2) || ((param_5 & 0xffff) == 4)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}





// FUN_0030b210 NONMATCHING
u32 FUN_0030b210(u32 param_1,int param_2,u16 param_3,short param_4)

{
  u16 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  s32 lVar6;
  u16 *puVar7;
  
  if (0x1cf < param_3) {
    FUN_0019d3f0((u32)D_0069aa80, 0x14f5);
  }
  if ((*(u8 *)(iGpffffb708 + (u32)param_3 * 0x2c) & 2) == 0) {
    uVar5 = 0;
  }
  else if ((*(u32 *)(param_2 + 0xc) & 0x100000) == 0) {
    puVar7 = (u16 *)param_1;
    if ((*puVar7 & 0x20) == 0) {
      if ((*puVar7 & 4) == 0) {
        if (10 < puVar7[1]) {
          FUN_0019d3f0((u32)D_0069aa80, 0x1506);
        }
        uVar1 = puVar7[1];
        if ((uVar1 == 3) || (uVar1 == 2)) {
          return 0;
        }
        if ((uVar1 == 1) && ((cVar2 = FUN_00308c60(param_1), cVar2 == '\x06' || (cVar2 == '\a')))) {
          return 0;
        }
      }
      if ((param_4 == 4) || (param_4 == 2)) {
        if ((*puVar7 & 4) == 0) {
          iVar3 = 0x46;
        }
        else {
          iVar3 = 100;
        }
        if ((*puVar7 & 4) == 0) {
          lVar6 = FUN_00300750(puVar7[1],100);
        }
        else {
          lVar6 = 0;
        }
        if (lVar6 != 0) {
          iVar3 = 0x50;
        }
        if ((*puVar7 & 4) == 0) {
          lVar6 = FUN_00300750(puVar7[1],0x65);
        }
        else {
          lVar6 = 0;
        }
        if (lVar6 != 0) {
          iVar3 = 0x32;
        }
        if ((*puVar7 & 4) == 0) {
          lVar6 = FUN_00300750(puVar7[1],0x66);
        }
        else {
          lVar6 = 0;
        }
        if (lVar6 != 0) {
          iVar3 = 0;
        }
        iVar4 = FUN_002ffbc0(100);
        if (iVar4 < iVar3) {
          uVar5 = 1;
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}





// FUN_0030b4b0
u32 FUN_0030b4b0(u32 param_1,u32 param_2)

{
  u32 uVar1;
  u32 uVar2;
  short sVar3;
  
  sVar3 = (short)param_2;
  if (sVar3 == -1) {
    uVar1 = 0;
  }
  else {
    if (sVar3 >= 0x13) {
      FUN_0019d3f0((u32)D_0069aa80,0x154b);
    }
    if (sVar3 >= 0x13) {
      FUN_0019d3f0((u32)D_0069aa80,0xea8);
    }
    uVar2 = 1 << ((int)sVar3 + 1);
    if ((uVar2 & 1) != 0) {
      uVar1 = 0;
    }
    else if ((uVar2 & 0xe0000) != 0) {
      uVar1 = 100;
    }
    else {
      {
        extern u32 FUN_00306e80(s32 param_1,u32 param_2);
        uVar1 = FUN_00306e80(param_1,param_2);
      }
    }
  }
  return uVar1;
}





// FUN_0030b640 NONMATCHING
u32 FUN_0030b640(s32 param_1,u32 param_2)

{
  u8 bVar1;
  u16 uVar2;
  short sVar3;
  int iVar4;
  s32 lVar5;
  u16 *puVar6;
  u32 uVar7;
  
  uVar7 = 0xffffffff;
  puVar6 = (u16 *)param_1;
  if ((*puVar6 & 0x40) != 0) {
    return 0;
  }
  param_2 = param_2 & 0xffff;
  if (((param_1 != 0) && (param_2 < 0x1d0)) && ((*(u8 *)(iGpffffb708 + param_2 * 0x2c) & 2) != 0))
  {
    if ((*puVar6 & 4) == 0) {
      uVar2 = FUN_0016cb80(puVar6[1],0);
      uVar2 = FUN_0016f630(puVar6[1],uVar2);
      iVar4 = FUN_00170d60(uVar2);
      sVar3 = *(short *)(iVar4 + 0x1e);
      goto LAB_0030b740;
    }
    param_2 = (u32)*(u16 *)((u32)puVar6[1] * 0x3e + iGpffffb720 + 0x3c);
  }
  sVar3 = (short)*(char *)(iGpffffb704 + param_2 * 2);
LAB_0030b740:
  if (sVar3 == 8) {
    if ((*puVar6 & 4) == 0) {
      sVar3 = FUN_00170760(puVar6[1],0xfc7);
      bVar1 = sVar3 != 0;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar7 = 0x1b6;
    }
    lVar5 = FUN_003005e0(param_1,0x244);
    if ((lVar5 != 0) && (lVar5 = FUN_002ffbc0(100), lVar5 < 10)) {
      uVar7 = 0x244;
    }
    lVar5 = FUN_003005e0(param_1,0x24b);
    if ((lVar5 != 0) && (lVar5 = FUN_002ffbc0(100), lVar5 < 0x32)) {
      uVar7 = 0x24b;
    }
    lVar5 = FUN_003005e0(param_1,0x259);
    if (lVar5 != 0) {
      uVar7 = 0x259;
    }
  }
  else if (sVar3 == 9) {
    if ((*puVar6 & 4) == 0) {
      sVar3 = FUN_00170760(puVar6[1],0xfc7);
      bVar1 = sVar3 != 0;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar7 = 0x1b6;
    }
    lVar5 = FUN_003005e0(param_1,0x245);
    if ((lVar5 != 0) && (lVar5 = FUN_002ffbc0(100), lVar5 < 10)) {
      uVar7 = 0x245;
    }
    lVar5 = FUN_003005e0(param_1,0x24c);
    if ((lVar5 != 0) && (lVar5 = FUN_002ffbc0(100), lVar5 < 0x32)) {
      uVar7 = 0x24c;
    }
    lVar5 = FUN_003005e0(param_1,0x25a);
    if (lVar5 != 0) {
      uVar7 = 0x25a;
    }
  }
  if ((short)uVar7 == -1) {
    if (((*puVar6 & 0x400) == 0) && (lVar5 = FUN_003005e0(param_1,0x23c), lVar5 != 0)) {
      uVar7 = 0x23c;
    }
    else if (((*puVar6 & 8) == 0) && (lVar5 = FUN_003005e0(param_1,0x23b), lVar5 != 0)) {
      uVar7 = 0x23b;
    }
  }
  lVar5 = FUN_003005e0(param_1,0x261);
  if (lVar5 != 0) {
    uVar7 = 0x261;
  }
  return uVar7;
}





// FUN_0030b9a0 NONMATCHING
u32 FUN_0030b9a0(u32 param_1,u16 param_2,u16 param_3)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u8 *pbVar4;
  
  if (0x1cf < param_2) {
    FUN_0019d3f0((u32)D_0069aa80, 0x160b);
  }
  pbVar4 = (u8 *)(iGpffffb708 + (u32)param_2 * 0x2c);
  if ((*pbVar4 & 2) == 0) {
    uVar1 = (u32)pbVar4[0xf];
    uVar2 = (u32)pbVar4[0x10];
    if ((pbVar4[0xf] == 0) || (uVar2 == 0)) {
      FUN_0019d3f0((u32)D_0069aa80, 0x1619);
    }
    if (uVar1 < uVar2) {
      iVar3 = FUN_002ffbc0(uVar2 - uVar1);
      uVar1 = uVar1 + iVar3 & 0xff;
    }
  }
  else if ((*(u16 *)param_1 & 4) == 0) {
    if ((*(u16 *)param_1 & 4) == 0) {
      uVar1 = FUN_00308c60(param_1);
      uVar2 = (u32)(u8)(&gp0xffff9d08)[uVar1 & 0xff];
    }
    else {
      uVar2 = 1;
    }
    uVar1 = 1;
    if ((uVar2 != 1) && (uVar1 = uVar2, (param_3 & 6) == 0)) {
      if (param_3 == 8) {
        uVar1 = 2;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}





// FUN_0030bb40
int FUN_0030bb40(u16 param_1)

{
  if (param_1 < 0x270) {
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80,0x162a);
  }
  return iGpffffb7fc + (u32)param_1 * 0x13;
}





// FUN_0030bbb0
int FUN_0030bbb0(u8 param_1)

{
  if (param_1 < 0x20) {
  }
  else {
    FUN_0019d3f0((u32)D_0069aa80,0x1638);
  }
  return iGpffffb800 + (u32)param_1 * 0x15;
}





// FUN_0030bc20
u16 FUN_0030bc20(s16 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00170e90(param_1);
  return *(u16 *)(iVar1 + 8);
}





// FUN_0030bc50 NONMATCHING

u32 FUN_0030bc50(int param_1)

{
  s32 lVar1;
  u32 uVar2;
  float fVar3;
  
  if (0x14f < *(u16 *)(param_1 + 2)) {
    FUN_0019d3f0((u32)D_0069aa80, 0x165b);
  }
  uVar2 = (u32)*(u16 *)(iGpffffb720 + (u32)*(u16 *)(param_1 + 2) * 0x3e + 0x20);
  lVar1 = FUN_0016f190(0xbd0);
  if (lVar1 == 1) {
    fVar3 = fGpffff8194 * (float)uVar2;
    if (fVar3 < 2.1474836e+09) {
      uVar2 = (u32)fVar3;
    }
    else {
      uVar2 = (int)(fVar3 - 2.1474836e+09) | 0x80000000;
    }
  }
  lVar1 = FUN_0016f190(0x1311);
  if (lVar1 == 1) {
    fVar3 = fGpffff8070 * (float)uVar2;
    if (fVar3 < 2.1474836e+09) {
      uVar2 = (u32)fVar3;
    }
    else {
      uVar2 = (int)(fVar3 - 2.1474836e+09) | 0x80000000;
    }
  }
  return uVar2;
}





// FUN_0030bde0 NONMATCHING
short FUN_0030bde0(u16 *param_1,s32 param_2)

{
  u16 uVar1;
  float fVar2;
  u8 bVar3;
  u16 uVar4;
  u16 uVar5;
  s32 lVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  u32 uVar10;
  
  if ((*param_1 & 4) == 0) {
    FUN_0019d3f0((u32)D_0069aa80, 0x167b);
  }
  if (0x14f < param_1[1]) {
    FUN_0019d3f0((u32)D_0069aa80, 0x167c);
  }
  iVar9 = iGpffffb720 + (u32)param_1[1] * 0x3e;
  sVar7 = 0;
  if (param_2 != 0) {
    *(u32 *)param_2 = 0;
  }
  if ((((*(short *)(iVar9 + 0x34) != 0) && (*(short *)(iVar9 + 0x32) != 0)) &&
      (lVar6 = FUN_0016f190(), lVar6 != 0)) &&
     ((bVar3 = FUN_002ffbc0(100), bVar3 < *(u8 *)(iVar9 + 0x36) &&
      (sVar7 = *(short *)(iVar9 + 0x34), param_2 != 0)))) {
    *(u32 *)param_2 = 1;
  }
  if (sVar7 == 0) {
    uVar5 = 0;
    for (uVar10 = 0; uVar10 < 4; uVar10 = uVar10 + 1 & 0xffff) {
      iVar8 = iVar9 + uVar10 * 4;
      uVar4 = *(u16 *)(iVar8 + 0x22);
      if ((uVar4 != 0) &&
         ((uVar4 < 5000 || (lVar6 = FUN_003951d0(0x1588 - (u32)uVar4), lVar6 == 0)))) {
        uVar5 = uVar5 + *(u8 *)(iVar8 + 0x24);
      }
    }
    uVar10 = 200;
    lVar6 = FUN_0016f190(0xbd8);
    if (lVar6 == 1) {
      fVar2 = fGpffff8278;
      if (2.1474836e+09 <= fGpffff8278) {
        fVar2 = fGpffff8278 - 2.1474836e+09;
      }
      uVar10 = (int)fVar2 & 0xffff;
      if (uVar10 == 0) {
        uVar10 = 1;
      }
    }
    if ((uVar5 != 0) && (uVar4 = FUN_002ffbc0(uVar10), uVar4 < uVar5)) {
      uVar5 = FUN_002ffbc0(uVar5);
      uVar4 = 0;
      for (uVar10 = 0; uVar10 < 4; uVar10 = uVar10 + 1 & 0xffff) {
        iVar8 = iVar9 + uVar10 * 4;
        uVar1 = *(u16 *)(iVar8 + 0x22);
        if ((uVar1 != 0) &&
           (((uVar1 < 5000 || (lVar6 = FUN_003951d0(0x1588 - (u32)uVar1), lVar6 == 0)) &&
            (uVar4 = uVar4 + *(u8 *)(iVar8 + 0x24), uVar5 < uVar4)))) {
          return *(short *)(iVar8 + 0x22);
        }
      }
    }
  }
  return sVar7;
}





// FUN_0030c0c0 NONMATCHING
int FUN_0030c0c0(void)

{
  short sVar1;
  u16 uVar2;
  int iVar3;
  s32 lVar4;
  short sVar5;
  u16 uVar6;
  u32 uVar7;
  
  lVar4 = FUN_0017d800();
  if (lVar4 == 0) {
    sVar1 = FUN_001752b0();
    uVar2 = FUN_00175410();
    for (uVar7 = 0; uVar7 < 0x20; uVar7 = uVar7 + 1 & 0xffff) {
      iVar3 = DAT_007ce3fc + uVar7 * 6;
      sVar5 = *(short *)(iVar3 + 2);
      if (sVar1 == sVar5) {
        sVar5 = *(short *)(iVar3 + 4);
LAB_0030c164:
        for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1) {
          lVar4 = FUN_00174960(uVar6);
          if ((lVar4 != 0) && (iVar3 = FUN_00174a90(uVar6), *(short *)(iVar3 + 2) == sVar5)) {
            return DAT_007ce3fc + uVar7 * 6;
          }
        }
      }
      else if (sVar1 == *(short *)(iVar3 + 4)) goto LAB_0030c164;
    }
  }
  return 0;
}





// FUN_0030c220
s32 FUN_0030c220(s32 param_1)

{
  s32 index;
  s32 valid;

  valid = 0;
  index = param_1 & 0xFFFF;
  if ((index >= 0x110) && (index < 0x131)) {
    valid = 1;
  }
  K_ASSERT(!!valid == 1, 0x170D);
  return DAT_007ce3fc + (index - 0x110) * 6;
}





// FUN_0030c2a0
u8 FUN_0030c2a0(u32 param_1)

{
  u16 uVar1;
  u16 uVar2;
  s32 lVar3;
  
  uVar1 = FUN_0030fc40(7,param_1,param_1,0,0);
  lVar3 = FUN_003005e0(param_1,0x218);
  if (lVar3 != 0) {
    uVar1 += 10;
  }
  lVar3 = FUN_0016f190(0x1319);
  if (lVar3 == 0) {
    if (uVar1 > 0x5a) {
      uVar1 = 0x5a;
    }
    else if (uVar1 < 0x32) {
      uVar1 = 0x32;
    }
  }
  else {
    if (uVar1 > 0x5a) {
      uVar1 = 0x5a;
    }
    else if (uVar1 < 5) {
      uVar1 = 5;
    }
  }
  uVar2 = FUN_002ffbc0(100);
  return uVar2 < uVar1;
}





// FUN_0030c3a0
u32 FUN_0030c3a0(u16 *param_1)

{
  u32 uVar1;
  
  if ((*param_1 & 4) == 0) {
    uVar1 = 0;
  }
  else {
    if (param_1[1] >= 0x150) {
      FUN_0019d3f0((u32)D_0069aa80,0x174d);
    }
    if ((*(u16 *)(DAT_007ce410 + (u32)param_1[1] * 0x3e) & 4) != 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}





// FUN_0030c440
void FUN_0030c440(void)

{
  u16 uVar1;
  
  for (uVar1 = 1; uVar1 < 0xb; uVar1++) {
    FUN_0030c490(uVar1);
  }
  return;
}





// FUN_0030c490
void FUN_0030c490(u16 param_1)

{
  s16 id;
  s16 value;

  id = (s16)param_1;
  value = (s16)FUN_0016c5f0(id);
  FUN_0016cf40(id,value);
  value = (s16)FUN_0016c670(id);
  FUN_0016cf90(id,value);
  FUN_0016d9d0(id,-1);
}





// FUN_0030c510
void datCalcNoOp(void)
{
}

// FUN_0030c520 NONMATCHING
void FUN_0030c520(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  lVar1 = FUN_00311250();
  if (lVar1 == 0) {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar7 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = DAT_007cad74 * (fVar7 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar7 = (float)FUN_0030fdf0(0xd,0);
      fVar3 = (float)FUN_0030fdf0(0x17,0);
      fVar2 = sqrtf(((fVar2 * 30.0f) / (fVar4 * 5.0f)) * (fVar7 / 5.0f)) * 10.0f * fVar3 * DAT_007caf8c;
      fVar7 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (fVar2 - 10.0f) * fVar7;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = sqrtf(((fVar4 * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f * fVar6 *
              fVar7;
    }
  }
  else {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar7 = (float)FUN_0030fdf0(0xe,2);
      fVar5 = DAT_007cad74 * (fVar7 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar7 = (float)FUN_0030fdf0(0xd,0);
      fVar3 = (float)FUN_0030fdf0(0xc,0);
      fVar4 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = DAT_007caf8c *
              sqrtf(((fVar2 * 30.0f) / (fVar5 * 5.0f)) * (fVar7 / 5.0f)) * 10.0f * fVar3 * fVar4;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = sqrtf((((fVar4 - 30.0f) * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f *
              fVar6 * fVar7;
    }
  }
  FUN_00311190((int)fVar7);
  return;
}





// FUN_0030c930 NONMATCHING
void FUN_0030c930(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x20,0);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = DAT_007cad74 * (fVar3 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
    fVar2 = (float)FUN_0030fdf0(0x13,0);
    fVar3 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar2 * 30.0f) / (fVar4 * 5.0f)) * (fVar3 / 5.0f)) * 10.0f;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar2 = (fVar4 * fVar2 + fVar3 + 0.0f) * DAT_007caf8c;
    fVar3 = (float)FUN_0030fdf0(0xc,0);
    fVar3 = (fVar2 - 10.0f) * fVar3;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xe,2);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = (float)FUN_0030fdf0(0x13,0);
    fVar5 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar4 * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f;
    fVar2 = (float)FUN_0030fdf0(0xc,0);
    fVar4 = fVar4 * fVar2;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar3 = fVar4 * fVar2 + fVar3 + 0.0f;
  }
  FUN_00311190((int)fVar3);
  return;
}





// FUN_0030cb90
void FUN_0030cb90(void)
{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  lVar1 = FUN_003111f0();
  if (lVar1 != 0) {
    fVar3 = (float)FUN_0030fdf0(0x13,0);
    fVar2 = (float)FUN_0030fdf0(0x1a,0);
    fVar3 = fVar3 + fVar2;
  }
  else {
    fVar4 = (float)FUN_0030fdf0(0x1a,0);
    fVar3 = DAT_007cadb4 * fVar4 + (float)FUN_0030fdf0(0x13,0);
  }
  FUN_00311190((int)fVar3);
  return;
}





// FUN_0030cc40 NONMATCHING
void FUN_0030cc40(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar5 = (fVar2 + 200.0f) / (fVar3 + 200.0f);
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0x1f,0);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = fVar5 * ((fVar2 + 200.0f) / (fVar3 / 2.0f + 200.0f)) * fVar4;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = ((fVar2 + 200.0f) / (fVar3 + 200.0f)) * fVar4;
  }
  FUN_00311190((int)fVar4);
  return;
}





// FUN_0030cdb0
void FUN_0030cdb0(void)
{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  lVar1 = FUN_003111f0();
  if (lVar1 == 0)
    goto zero;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 50.0f;
  fVar4 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 50.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar4 / fVar3;
  fVar2 = (float)FUN_0030fdf0(0x14,0);
  fVar2 = fVar2 * fVar4;
  goto done;
zero:
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 50.0f;
  fVar4 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 50.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar4 / fVar3;
  fVar3 = (float)FUN_0030fdf0(0x14,0);
  fVar3 = fVar3 * fVar4;
  fVar2 = DAT_007cad74 * fVar3;
done:
  FUN_00311190((int)fVar2);
  return;
}





// FUN_0030cec0
void FUN_0030cec0(void)

{
  float fVar1;
  
  FUN_003111f0();
  fVar1 = (float)FUN_0030fdf0(0x15,0);
  FUN_00311190((int)fVar1);
  return;
}





// FUN_0030cf00
void FUN_0030cf00(void)
{
  float fVar4;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0030fdf0(0xd,3);
  fVar3 = 100.0f;
  fVar1 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,3);
  fVar3 = 100.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar1 / fVar3;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 100.0f;
  fVar1 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 100.0f;
  fVar3 = fVar3 + fVar2;
  fVar3 = fVar1 / fVar3;
  fVar2 = fVar4 * fVar3;
  fVar1 = fVar2 * 75.0f;
  fVar3 = (float)FUN_0030fdf0(0x22,0);
  fVar3 = fVar3 * 5.0f + fVar1;
  FUN_00311190((int)(fVar3 + 0.0f));
  return;
}





// FUN_0030d000
#pragma schedule off
void FUN_0030d000(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
  #pragma push
  #pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
  #pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}




// FUN_0030d0e0
#pragma schedule off
void FUN_0030d0e0(void)
{
  float fVar1;
  float fVar2;

  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030d1c0
#pragma schedule off
void FUN_0030d1c0(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030d2a0
#pragma schedule off
void FUN_0030d2a0(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 40.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030d380
#pragma schedule off
void FUN_0030d380(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 30.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030d460
void FUN_0030d460(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
}





// FUN_0030d4a0
void FUN_0030d4a0(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
}





// FUN_0030d4e0 NONMATCHING
void FUN_0030d4e0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (float)FUN_0030fdf0(0xe,2);
  fVar2 = (float)FUN_0030fdf0(0xe,2);
  fVar3 = (float)FUN_0030fdf0(0x13,0);
  fVar4 = (float)FUN_0030fdf0(0xd,0);
  fVar5 = (float)FUN_0030fdf0(0xc,0);
  fVar6 = (float)FUN_0030fdf0(0x17,0);
  fVar7 = (float)FUN_0030fdf0(0x1b,0);
  fVar8 = (float)FUN_0030fdf0(0x21,0);
  FUN_00311190((int)(sqrtf((((fVar3 - 30.0f) * 30.0f) / ((fVar1 + fVar2) * 5.0f)) * (fVar4 / 5.0f)) *
                     10.0f * fVar5 * fVar6 * fVar7 * fVar8 * DAT_007cad74));
  return;
}





// FUN_0030d610 NONMATCHING
void FUN_0030d610(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = DAT_007cad74 * ((fVar2 * fVar3 * (fVar4 + 100.0f)) / (fVar5 + 100.0f));
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = (fVar2 * fVar3 * (fVar4 + 100.0f)) / (fVar5 + 100.0f);
  }
  FUN_00311190((int)fVar2);
  return;
}





// FUN_0030d760 NONMATCHING
void FUN_0030d760(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  lVar1 = FUN_00311250();
  if (lVar1 == 0) {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar5 = DAT_007cad74 * (fVar3 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar3 = (float)FUN_0030fdf0(0xd,0);
      fVar4 = (float)FUN_0030fdf0(0x17,0);
      fVar2 = sqrtf(((fVar2 * 30.0f) / (fVar5 * 5.0f)) * (fVar3 / 5.0f)) * 10.0f * fVar4 * DAT_007cadb4;
      fVar3 = (float)FUN_0030fdf0(0xc,0);
      fVar3 = (fVar2 - 10.0f) * fVar3;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar3 = DAT_007cae84 *
              sqrtf(((fVar4 * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f * fVar6 *
              fVar7;
    }
  }
  else {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar6 = DAT_007cad74 * (fVar3 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar3 = (float)FUN_0030fdf0(0xd,0);
      fVar4 = (float)FUN_0030fdf0(0xc,0);
      fVar5 = (float)FUN_0030fdf0(0x17,0);
      fVar3 = DAT_007cadb4 *
              sqrtf(((fVar2 * 30.0f) / (fVar6 * 5.0f)) * (fVar3 / 5.0f)) * 10.0f * fVar4 * fVar5;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar3 = DAT_007cae84 *
              sqrtf((((fVar4 - 30.0f) * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f *
              fVar6 * fVar7;
    }
  }
  FUN_00311190((int)fVar3);
  return;
}





// FUN_0030db80 NONMATCHING
void FUN_0030db80(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x20,0);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = DAT_007cad74 * (fVar3 * 2.0f + (fVar2 / 2.0f) / 2.0f + 0.0f);
    fVar2 = (float)FUN_0030fdf0(0x13,0);
    fVar3 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar2 * 30.0f) / (fVar4 * 5.0f)) * (fVar3 / 5.0f)) * 10.0f;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar2 = (fVar4 * fVar2 + fVar3 + 0.0f) * DAT_007cadb4;
    fVar3 = (float)FUN_0030fdf0(0xc,0);
    fVar3 = (fVar2 - 10.0f) * fVar3;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xe,2);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = (float)FUN_0030fdf0(0x13,0);
    fVar5 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar4 * 30.0f) / ((fVar2 + fVar3) * 5.0f)) * (fVar5 / 5.0f)) * 10.0f;
    fVar2 = (float)FUN_0030fdf0(0xc,0);
    fVar4 = fVar4 * fVar2;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar3 = (fVar4 * fVar2 + fVar3 + 0.0f) * DAT_007cae84;
  }
  FUN_00311190((int)fVar3);
  return;
}

// FUN_0030ddf0 NONMATCHING
void FUN_0030ddf0(void)
{
  s32 lVar1;
  float fVar2;
  float fVar3;

  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x1a,0);
    fVar3 = (float)FUN_0030fdf0(0x13,0);
    fVar2 = fVar2 * 0.5f + fVar3 + 0.0f;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0x13,0);
    fVar3 = (float)FUN_0030fdf0(0x1a,0);
    fVar2 = (fVar2 + fVar3) * 1.5f;
  }
  FUN_00311190((int)fVar2);
  return;
}





// FUN_0030dec0 NONMATCHING
void FUN_0030dec0(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar5 = (fVar2 + 200.0f) / (fVar3 + 200.0f);
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0x1f,0);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = fVar5 * ((fVar2 + 200.0f) / (fVar3 / 2.0f + 200.0f)) * fVar4;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = ((fVar2 + 200.0f) / (fVar3 + 200.0f)) * fVar4;
  }
  FUN_00311190((int)fVar4);
  return;
}





// FUN_0030e030
void FUN_0030e030(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  lVar1 = FUN_003111f0();
  if (lVar1 == 0)
    goto zero;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 50.0f;
  fVar4 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 50.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar4 / fVar3;
  fVar3 = (float)FUN_0030fdf0(0x14,0);
  fVar3 = fVar3 * fVar4;
  goto done;
zero:
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 50.0f;
  fVar4 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 50.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar4 / fVar3;
  fVar3 = (float)FUN_0030fdf0(0x14,0);
  fVar3 = fVar3 * fVar4 * 0.5f;
done:
  FUN_00311190((int)fVar3);
}





// FUN_0030e140
void FUN_0030e140(void)

{
  float fVar1;
  
  FUN_003111f0();
  fVar1 = (float)FUN_0030fdf0(0x15,0);
  FUN_00311190((int)fVar1);
  return;
}





// FUN_0030e180
void FUN_0030e180(void)
{
  float fVar4;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0030fdf0(0xd,3);
  fVar3 = 60.0f;
  fVar1 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,3);
  fVar3 = 60.0f;
  fVar3 = fVar3 + fVar2;
  fVar4 = fVar1 / fVar3;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar3 = 30.0f;
  fVar1 = fVar3 + fVar2;
  fVar2 = (float)FUN_0030fdf0(0xe,4);
  fVar3 = 30.0f;
  fVar3 = fVar3 + fVar2;
  fVar3 = fVar1 / fVar3;
  fVar2 = fVar4 * fVar3;
  fVar1 = fVar2 * 85.0f;
  fVar3 = (float)FUN_0030fdf0(0x22,0);
  fVar3 = fVar3 * 5.0f + fVar1;
  FUN_00311190((int)(fVar3 + 0.0f));
  return;
}





// FUN_0030e280
#pragma schedule off
void FUN_0030e280(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030e360
#pragma schedule off
void FUN_0030e360(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030e440
#pragma schedule off
void FUN_0030e440(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030e520
#pragma schedule off
void FUN_0030e520(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 40.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030e600
#pragma schedule off
void FUN_0030e600(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 30.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030e6e0
void FUN_0030e6e0(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
}





// FUN_0030e720
void FUN_0030e720(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
}





// FUN_0030e760 NONMATCHING
void FUN_0030e760(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (float)FUN_0030fdf0(0xe,2);
  fVar2 = (float)FUN_0030fdf0(0xe,2);
  fVar3 = (float)FUN_0030fdf0(0x13,0);
  fVar4 = (float)FUN_0030fdf0(0xd,0);
  fVar5 = (float)FUN_0030fdf0(0xc,0);
  fVar6 = (float)FUN_0030fdf0(0x17,0);
  fVar7 = (float)FUN_0030fdf0(0x1b,0);
  fVar8 = (float)FUN_0030fdf0(0x21,0);
  FUN_00311190((int)(sqrtf((((fVar3 - 30.0) * 30.0) / ((fVar1 + fVar2) * 5.0)) * (fVar4 / 5.0)) *
                     10.0 * fVar5 * fVar6 * 2.0 * fVar7 * fVar8 * DAT_007cad74));
  return;
}





// FUN_0030e8a0 NONMATCHING
void FUN_0030e8a0(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = ((fVar2 * fVar3 * (fVar4 + 100.0)) / (fVar5 + 100.0)) * 0.5;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = (fVar2 * fVar3 * (fVar4 + 100.0)) / (fVar5 + 100.0);
  }
  FUN_00311190((int)fVar2);
  return;
}





// FUN_0030ea00 NONMATCHING
void FUN_0030ea00(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  lVar1 = FUN_00311250();
  if (lVar1 == 0) {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar7 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = DAT_007cad74 * (fVar7 * 2.0 + (fVar2 / 2.0) / 2.0 + 0.0);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar7 = (float)FUN_0030fdf0(0xd,0);
      fVar3 = (float)FUN_0030fdf0(0x17,0);
      fVar2 = sqrtf(((fVar2 * 30.0) / (fVar4 * 5.0)) * (fVar7 / 5.0)) * 10.0 * fVar3 * DAT_007cad8c;
      fVar7 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (fVar2 - 10.0) * fVar7;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = sqrtf(((fVar4 * 30.0) / ((fVar2 + fVar3) * 5.0)) * (fVar5 / 5.0)) * 10.0 * fVar6 *
              fVar7;
    }
  }
  else {
    lVar1 = FUN_003111f0();
    if (lVar1 == 0) {
      fVar2 = (float)FUN_0030fdf0(0x20,0);
      fVar7 = (float)FUN_0030fdf0(0xe,2);
      fVar5 = DAT_007cad74 * (fVar7 * 2.0 + (fVar2 / 2.0) / 2.0 + 0.0);
      fVar2 = (float)FUN_0030fdf0(0x13,0);
      fVar7 = (float)FUN_0030fdf0(0xd,0);
      fVar3 = (float)FUN_0030fdf0(0xc,0);
      fVar4 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = DAT_007cad8c *
              sqrtf(((fVar2 * 30.0) / (fVar5 * 5.0)) * (fVar7 / 5.0)) * 10.0 * fVar3 * fVar4;
    }
    else {
      fVar2 = (float)FUN_0030fdf0(0xe,2);
      fVar3 = (float)FUN_0030fdf0(0xe,2);
      fVar4 = (float)FUN_0030fdf0(0x13,0);
      fVar5 = (float)FUN_0030fdf0(0xd,0);
      fVar6 = (float)FUN_0030fdf0(0xc,0);
      fVar7 = (float)FUN_0030fdf0(0x17,0);
      fVar7 = sqrtf((((fVar4 - 30.0) * 30.0) / ((fVar2 + fVar3) * 5.0)) * (fVar5 / 5.0)) * 10.0 *
              fVar6 * fVar7;
    }
  }
  FUN_00311190((int)fVar7);
  return;
}





// FUN_0030ee10 NONMATCHING
void FUN_0030ee10(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x20,0);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = DAT_007cad74 * (fVar3 * 2.0 + (fVar2 / 2.0) / 2.0 + 0.0);
    fVar2 = (float)FUN_0030fdf0(0x13,0);
    fVar3 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar2 * 30.0) / (fVar4 * 5.0)) * (fVar3 / 5.0)) * 10.0;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar2 = (fVar4 * fVar2 + fVar3 + 0.0) * DAT_007cad8c;
    fVar3 = (float)FUN_0030fdf0(0xc,0);
    fVar3 = (fVar2 - 10.0) * fVar3;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xe,2);
    fVar3 = (float)FUN_0030fdf0(0xe,2);
    fVar4 = (float)FUN_0030fdf0(0x13,0);
    fVar5 = (float)FUN_0030fdf0(0xd,1);
    fVar4 = sqrtf(((fVar4 * 30.0) / ((fVar2 + fVar3) * 5.0)) * (fVar5 / 5.0)) * 10.0;
    fVar2 = (float)FUN_0030fdf0(0xc,0);
    fVar4 = fVar4 * fVar2;
    fVar2 = (float)FUN_0030fdf0(0x17,0);
    fVar3 = (float)FUN_0030fdf0(0x19,0);
    fVar3 = fVar4 * fVar2 + fVar3 + 0.0;
  }
  FUN_00311190((int)fVar3);
  return;
}





// FUN_0030f070
void FUN_0030f070(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  lVar1 = FUN_003111f0();
  if (lVar1 != 0) {
    fVar3 = (float)FUN_0030fdf0(0x13,0);
    fVar2 = (float)FUN_0030fdf0(0x1a,0);
    fVar3 = fVar3 + fVar2;
  }
  else {
    fVar4 = (float)FUN_0030fdf0(0x1a,0);
    fVar3 = DAT_007cadb4 * fVar4 + (float)FUN_0030fdf0(0x13,0);
  }
  FUN_00311190((int)fVar3);
  return;
}





// FUN_0030f120 NONMATCHING
void FUN_0030f120(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar5 = (fVar2 + 200.0) / (fVar3 + 200.0);
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0x1f,0);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = fVar5 * ((fVar2 + 200.0) / (fVar3 / 2.0 + 200.0)) * fVar4;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xd,3);
    fVar3 = (float)FUN_0030fdf0(0xe,3);
    fVar4 = (float)FUN_0030fdf0(0x11,0);
    fVar4 = ((fVar2 + 200.0) / (fVar3 + 200.0)) * fVar4;
  }
  FUN_00311190((int)fVar4);
  return;
}





// FUN_0030f290 NONMATCHING
void FUN_0030f290(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar2 = (float)FUN_0030fdf0(0xe,4);
    fVar3 = (float)FUN_0030fdf0(0x14,0);
    fVar4 = DAT_007cad74 * fVar3 * ((fVar4 + 50.0) / (fVar2 + 50.0));
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0xd,4);
    fVar3 = (float)FUN_0030fdf0(0xe,4);
    fVar4 = (float)FUN_0030fdf0(0x14,0);
    fVar4 = fVar4 * ((fVar2 + 50.0) / (fVar3 + 50.0));
  }
  FUN_00311190((int)fVar4);
  return;
}





// FUN_0030f3a0
void FUN_0030f3a0(void)

{
  float fVar1;
  
  FUN_003111f0();
  fVar1 = (float)FUN_0030fdf0(0x15,0);
  FUN_00311190((int)fVar1);
  return;
}





// FUN_0030f3e0
void FUN_0030f3e0(void)

{
  float fVar3;
  float fVar2;
  float fVar1;
  
  fVar1 = (float)FUN_0030fdf0(0xd,3) + 150.0f;
  fVar2 = (float)FUN_0030fdf0(0xe,3) + 150.0f;
  fVar3 = fVar1 / fVar2;
  fVar1 = (float)FUN_0030fdf0(0xd,4) + 150.0f;
  fVar2 = (float)FUN_0030fdf0(0xe,4) + 150.0f;
  fVar1 = fVar1 / fVar2;
  fVar2 = fVar3 * fVar1 * 30.0f;
  fVar1 = (float)FUN_0030fdf0(0x22,0);
  FUN_00311190((int)(fVar1 * 5.0f + fVar2 + 0.0f));
  return;
}





// FUN_0030f4e0
#pragma schedule off
void FUN_0030f4e0(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030f5c0
#pragma schedule off
void FUN_0030f5c0(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030f6a0
#pragma schedule off
void FUN_0030f6a0(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 50.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030f780
#pragma schedule off
void FUN_0030f780(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 40.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030f860
#pragma schedule off
void FUN_0030f860(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0030fdf0(1,0);
  fVar2 = fVar1 - 1.0f;
  fVar1 = 2.0f + 3.0f * fVar2;
  fVar2 = (float)FUN_0030fdf0(0x10,0);
  fVar1 *= fVar2;
#pragma push
#pragma opt_rebuildconditionals off
  if (fVar1 <= 0.0f)
    goto nonpositive;
  fVar2 = (float)FUN_0030fdf0(0xd,4);
  fVar2 = (fVar2 / fVar1) * 30.0f;
  goto done;
nonpositive:
  fVar2 = 1.0f;
done:
#pragma pop
  FUN_00311190_typed((int)fVar2);
  return;
}





// FUN_0030f940
void FUN_0030f940(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
}





// FUN_0030f980
void FUN_0030f980(void)

{
  float fVar1 = 100.0f;
  FUN_00311190(fVar1);
  return;
}





// FUN_0030f9c0 NONMATCHING
void FUN_0030f9c0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (float)FUN_0030fdf0(0xe,2);
  fVar2 = (float)FUN_0030fdf0(0xe,2);
  fVar3 = (float)FUN_0030fdf0(0x13,0);
  fVar4 = (float)FUN_0030fdf0(0xd,0);
  fVar5 = (float)FUN_0030fdf0(0xc,0);
  fVar6 = (float)FUN_0030fdf0(0x17,0);
  fVar7 = (float)FUN_0030fdf0(0x1b,0);
  fVar8 = (float)FUN_0030fdf0(0x21,0);
  FUN_00311190((int)(sqrtf((((fVar3 - 30.0) * 30.0) / ((fVar1 + fVar2) * 5.0)) * (fVar4 / 5.0)) *
                     10.0 * fVar5 * fVar6 * fVar7 * fVar8 * DAT_007cad74));
  return;
}





// FUN_0030faf0 NONMATCHING
void FUN_0030faf0(void)

{
  s32 lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = FUN_003111f0();
  if (lVar1 == 0) {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = ((fVar2 * fVar3 * (fVar4 + 100.0)) / (fVar5 + 100.0)) * 1.5;
  }
  else {
    fVar2 = (float)FUN_0030fdf0(0x12,0);
    fVar3 = (float)FUN_0030fdf0(0x10,0);
    fVar4 = (float)FUN_0030fdf0(0xd,4);
    fVar5 = (float)FUN_0030fdf0(0xe,4);
    fVar2 = (fVar2 * fVar3 * (fVar4 + 100.0)) / (fVar5 + 100.0);
  }
  FUN_00311190((int)fVar2);
  return;
}





// FUN_0030fc40 NONMATCHING
u32
FUN_0030fc40(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
            u32 param_5)

{
  s32 lVar1;
  int iVar2;
  
  DAT_009571a4 = DAT_009571a4 & 0xfffe;
  DAT_00957190 = param_2;
  DAT_00957194 = param_3;
  DAT_0095719c = param_4;
  DAT_009571a0 = param_5;
  lVar1 = FUN_0016f190(0x1311);
  iVar2 = (int)param_1;
  if (lVar1 == 1) {
    if (0x10 < param_1) {
      FUN_0019d3f0(0x69ab78,0x8b);
    }
    PTR_LAB_0069aae0[iVar2]();
  }
  else {
    lVar1 = FUN_0016f190(0x1319);
    if (lVar1 == 1) {
      if (0x10 < param_1) {
        FUN_0019d3f0(0x69ab78,0x90);
      }
      PTR_LAB_0069ab30[iVar2]();
    }
    else {
      if (0x10 < param_1) {
        FUN_0019d3f0(0x69ab78,0x93);
      }
      PTR_LAB_0069aa90[iVar2]();
    }
  }
  if ((DAT_009571a4 & 1) == 0) {
    FUN_0019d3f0(0x69ab78,0x9b);
  }
  return DAT_00957198;
}





// FUN_0030fdc0
u32 FUN_0030fdc0(void)

{
  FUN_0035f080(0.0f);
  return 1;
}





// FUN_0030fdf0 NONMATCHING

float FUN_0030fdf0(int param_1,u32 param_2)

{
  int iVar1;
  u16 uVar2;
  u16 uVar3;
  u16 uVar4;
  short sVar5;
  u32 uVar6;
  u8 *pbVar7;
  float unaff_f20;
  
  switch(param_1) {
  default:
    FUN_0019d3f0(0x69ab78,0x1cb);
    break;
  case 1:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xbe);
    }
    uVar6 = FUN_002ffcc0(DAT_00957190);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 2:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xc2);
    }
    uVar6 = FUN_002ffcc0(DAT_00957194);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 3:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xc6);
    }
    uVar6 = FUN_002ffd70(DAT_00957190);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 4:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xca);
    }
    uVar6 = FUN_002ffd70(DAT_00957194);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 5:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xce);
    }
    uVar6 = FUN_002ffdf0(DAT_00957190);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 6:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xd2);
    }
    uVar6 = FUN_002ffdf0(DAT_00957194);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 7:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xd6);
    }
    unaff_f20 = (float)*(u16 *)(DAT_00957190 + 10);
    break;
  case 8:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xda);
    }
    unaff_f20 = (float)*(u16 *)(DAT_00957194 + 10);
    break;
  case 9:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xde);
    }
    uVar6 = FUN_00300100(DAT_00957190);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 10:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xe2);
    }
    uVar6 = FUN_00300100(DAT_00957194);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0xb:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xe6);
    }
    uVar2 = FUN_003082f0(DAT_00957190,DAT_0095719c);
    uVar3 = FUN_00306e80(DAT_00957190,(short)uVar2);
    unaff_f20 = (float)uVar3 / 100.0;
    break;
  case 0xc:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0xec);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0xed);
    }
    uVar2 = FUN_003082f0(DAT_00957190,DAT_0095719c);
    uVar3 = FUN_00306e80(DAT_00957194,(short)uVar2);
    unaff_f20 = (float)uVar3 / 100.0;
    break;
  case 0xd:
    if (4 < (s32)param_2) {
      FUN_0019d3f0(0x69ab78,0x110);
    }
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x111);
    }
    uVar6 = FUN_00300c90(DAT_00957190,param_2 & 0xffff);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0xe:
    if (4 < (s32)param_2) {
      FUN_0019d3f0(0x69ab78,0x11a);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x11b);
    }
    uVar6 = FUN_00300c90(DAT_00957194,param_2 & 0xffff);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0xf:
  case 0x10:
    iVar1 = DAT_00957194;
    if (param_1 == 0xf) {
      iVar1 = DAT_00957190;
    }
    sVar5 = FUN_00308120(DAT_0095719c,DAT_009571a0);
    if (0x12 < sVar5) {
      FUN_0019d3f0(0x69ab78,0xfc);
    }
    if (((sVar5 == 0x11) || (sVar5 == 0x10)) || (sVar5 == -1)) {
      uVar3 = 100;
    }
    else {
      uVar3 = FUN_00306e80(iVar1,(short)sVar5);
    }
    unaff_f20 = (float)uVar3 / 100.0;
    break;
  case 0x11:
    if (0x1cf < DAT_0095719c) {
      FUN_0019d3f0(0x69ab78,0x11f);
    }
    pbVar7 = (u8 *)(DAT_007ce3f8 + ((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4);
    if ((*pbVar7 & 2) == 0) {
      unaff_f20 = (float)pbVar7[0xe];
    }
    else {
      if (DAT_00957190 == 0) {
        FUN_0019d3f0(0x69ab78,0x122);
      }
      uVar6 = FUN_00309080((u16*)DAT_00957190,1);
      if ((s32)uVar6 < 0) {
        unaff_f20 = (float)(uVar6 & 0xffffffff);
      }
      else {
        unaff_f20 = (float)(int)uVar6;
      }
    }
    break;
  case 0x12:
    if (0x1cf < DAT_0095719c) {
      FUN_0019d3f0(0x69ab78,0x129);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x19);
    break;
  case 0x13:
    if (0x1cf < DAT_0095719c) {
      FUN_0019d3f0(0x69ab78,0x12d);
    }
    pbVar7 = (u8 *)(DAT_007ce3f8 + ((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4);
    if (((*pbVar7 & 2) == 0) && (pbVar7[0x11] != 0x10)) {
      if (DAT_009571a0 == 1) {
        unaff_f20 = (float)(int)*(short *)(pbVar7 + 0x12);
      }
      else if (DAT_009571a0 == 2) {
        unaff_f20 = (float)(int)*(short *)(pbVar7 + 0x16);
      }
      else {
        FUN_0019d3f0(0x69ab78,0x13c);
      }
    }
    else {
      if (DAT_00957190 == 0) {
        FUN_0019d3f0(0x69ab78,0x131);
      }
      uVar6 = FUN_00309080((u16*)DAT_00957190,0);
      if ((s32)uVar6 < 0) {
        unaff_f20 = (float)(uVar6 & 0xffffffff);
      }
      else {
        unaff_f20 = (float)(int)uVar6;
      }
    }
    break;
  case 0x14:
    if (0x1cf < DAT_0095719c) {
      FUN_0019d3f0(0x69ab78,0x141);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x25);
    break;
  case 0x15:
    if (0x1cf < DAT_0095719c) {
      FUN_0019d3f0(0x69ab78,0x145);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x26);
    break;
  case 0x16:
    unaff_f20 = 31000.0;
    break;
  case 0x17:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x14c);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x14d);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar4 = FUN_002ffcc0(DAT_00957194);
    sVar5 = (uVar3 & 0xff) - (uVar4 & 0xff);
    if (sVar5 < -0x1f) {
      sVar5 = -0x1f;
    }
    else if (0x1f < sVar5) {
      sVar5 = 0x1f;
    }
    if (DAT_007ce3ec == 0) {
      unaff_f20 = *(float *)(DAT_007ce46c + (short)(sVar5 + 0x5e) * 4);
    }
    else {
      unaff_f20 = *(float *)(DAT_007ce46c + (short)(sVar5 + 0x1f) * 4);
    }
    break;
  case 0x18:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x172);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x173);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar3 = uVar3 & 0xff;
    uVar4 = FUN_002ffcc0(DAT_00957194);
    uVar4 = uVar4 & 0xff;
    if (uVar4 < uVar3) {
      sVar5 = (uVar3 - uVar4) + -1;
    }
    else {
      sVar5 = (uVar3 - uVar4) + 1;
    }
    sVar5 = sVar5 / 3;
    if (sVar5 < -6) {
      sVar5 = -6;
    }
    else if (6 < sVar5) {
      sVar5 = 6;
    }
    unaff_f20 = *(float *)(sVar5 * 4 + DAT_007ce470 + 0x18);
    break;
  case 0x19:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x185);
    }
    uVar3 = FUN_00300c90(DAT_00957190,1);
    uVar3 = (uVar3 & 0xff) / 10;
    if (9 < uVar3) {
      uVar3 = 9;
    }
    unaff_f20 = (float)(int)*(short *)(DAT_007ce478 + (short)uVar3 * 2);
    break;
  case 0x1a:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x18d);
    }
    uVar3 = FUN_00300c90(DAT_00957190,1);
    uVar3 = (uVar3 & 0xff) / 5;
    if (0x14 < uVar3) {
      uVar3 = 0x14;
    }
    unaff_f20 = (float)(int)*(short *)(DAT_007ce47c + (short)uVar3 * 2);
    break;
  case 0x1b:
    unaff_f20 = (float)(*(u16 *)(DAT_007ce3ec + 0xb98) + 1);
    break;
  case 0x1c:
    unaff_f20 = (float)DAT_00957198;
    break;
  case 0x1d:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x19b);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957190,0);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0x1e:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x19f);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957190,1);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0x1f:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x1a3);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957194,0);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0x20:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x1a7);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957194,1);
    if ((s32)uVar6 < 0) {
      unaff_f20 = (float)(uVar6 & 0xffffffff);
    }
    else {
      unaff_f20 = (float)(int)uVar6;
    }
    break;
  case 0x21:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0(0x69ab78,0x1ab);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0(0x69ab78,0x1ac);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar4 = FUN_002ffcc0(DAT_00957194);
    sVar5 = (uVar3 & 0xff) - (uVar4 & 0xff);
    if (sVar5 < -0x1f) {
      sVar5 = -0x1f;
    }
    else if (0x1f < sVar5) {
      sVar5 = 0x1f;
    }
    unaff_f20 = *(float *)(sVar5 * 4 + DAT_007ce46c + 0x7c);
    break;
  case 0x22:
    unaff_f20 = (float)*(u16 *)(DAT_007ce3ec + 0xb9e);
  }
  return unaff_f20;
}




