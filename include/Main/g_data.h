/*This file is horrible*/

#ifndef G_DATA_H
#define G_DATA_H

#include "Main/Battle/Data/datUnit.h"
#include "Main/Battle/Data/datPersona.h"
#include "datCalendar.h"
#include "pcId.h"
#include "g_flags.h"

#define MAX_CHARACTER_LEVEL 99

#define SOCIAL_STAT_MIN_POINT 0
#define SOCIAL_STAT_MAX_POINT 999

typedef enum
{
    SCENARIO_MODE_JOURNEY,
    SCENARIO_MODE_ANSWER
} ScenarioMode; 

typedef enum
{
    ARCANA_00,
    ARCANA_FOOL,
    ARCANA_MAGICIAN,
    ARCANA_PRIESTESS,
    ARCANA_EMPRESS,
    ARCANA_EMPEROR,
    ARCANA_HIERORPHTANT,
    ARCANA_LOVERS,
    ARCANA_CHARIOT,
    ARCANA_JUSTICE,
    ARCANA_HERMIT,
    ARCANA_FORTUNE,
    ARCANA_STRENGTH,
    ARCANA_HANGED_MAN,
    ARCANA_DEATH,
    ARCANA_TOWER,
    ARCANA_STAR,
    ARCANA_MOON,
    ARCANA_SUN,
    ARCANA_JUDGMENT,
    ARCANA_AEON,
    ARCANA_17,
    ARCANA_18,
    ARCANA_19,
    ARCANA_1A,
    ARCANA_1B,
    ARCANA_1C,
    ARCANA_1D,
    ARCANA_1E,
    ARCANA_1F,
} Arcanas;

typedef enum
{
    SOCIAL_LINK_NONE = -1,
    SOCIAL_LINK_SEES,
    SOCIAL_LINK_KENJI,
    SOCIAL_LINK_HIDETOSHI = 4,
    SOCIAL_LINK_OLD_COUPLE,
    SOCIAL_LINK_YUKARI,
    SOCIAL_LINK_FUUKA,
    SOCIAL_LINK_MITSURU,
    SOCIAL_LINK_AIGIS,
    SOCIAL_LINK_YUKO,
    SOCIAL_LINK_CHIHIRO,
    SOCIAL_LINK_KAZUSHI_TRACK,
    SOCIAL_LINK_KAZUSHI_KENDO,
    SOCIAL_LINK_KAZUSHI_SWIM,
    SOCIAL_LINK_MAYA = 16,
    SOCIAL_LINK_KEISUKE_PHOTO,
    SOCIAL_LINK_KEISUKE_ART,
    SOCIAL_LINK_KEISUKE_MUSIC,
    SOCIAL_LINK_MAIKO = 21,
    SOCIAL_LINK_PHAROS,
    SOCIAL_LINK_BEBE,
    SOCIAL_LINK_TANAKA,
    SOCIAL_LINK_MUTATSU,
    SOCIAL_LINK_MAMORU,
    SOCIAL_LINK_NOZOMI,
    SOCIAL_LINK_AKINARI,
    SOCIAL_LINK_NYX_TEAM,
} PlayerSocialLink;

typedef enum
{
    PHYSICAL_CONDITION_GOOD,
    PHYSICAL_CONDITION_UNK1, // not in final game 
    PHYSICAL_CONDITION_GREAT,
    PHYSICAL_CONDITION_TIRED,
    PHYSICAL_CONDITION_UNK2, // not in final game 
    PHYSICAL_CONDITION_SICK
} CharacterPhysicalCondition;

typedef enum
{
    AI_TACTIC_ACT_FREELY = 1,
    AI_TACTIC_KNOCK_DOWN,
    AI_TACTIC_ATTACK_FALLEN,
    AI_TACTIC_FULL_ASSAULT,
    AI_TACTIC_HEAL_SUPPORT,
    AI_TACTIC_CONSERVE_SP,
    AI_TACTIC_ASSIGN_TARGET,
    AI_TACTIC_SAME_TARGET,
    AI_TACTIC_STAND_BY,
    AI_TACTIC_ORGIA_MODE,
    AI_TACTIC_MAX
} AiTactic;

typedef enum
{
    EQUIPMENT_TYPE_WEAPON,
    EQUIPMENT_TYPE_ARMOR,
    EQUIPMENT_TYPE_BOOTS,
    EQUIPMENT_TYPE_ACCESSORY
} EquimentTypes;

typedef enum
{
    WEAPON_TYPE_1H_SWORD,
    WEAPON_TYPE_2H_SWORD,
    WEAPON_TYPE_AXE,
    WEAPON_TYPE_FIST,
    WEAPON_TYPE_SPEAR,
    WEAPON_TYPE_KNIFE,
    WEAPON_TYPE_BOW,
    WEAPON_TYPE_GUN
} WeaponTypes;

// 6 bytes
typedef struct DatSocial
{
    s16 academicPoint;
    s16 charmPoint;
    s16 couragePoint;
} DatSocial;

// 6 bytes
typedef struct DatPhysical
{
    u16 physicalCondition; // See enum CharacterPhysicalCondition
    u16 fatigueCounter;    // if 0, character will become tired
    u16 oldFatigueCounter; // value before entering tartarus
} DatPhysical;

// 20 bytes
typedef struct DatEquipment
{
    u16 id;          // 0x00
    u16 unk_02;      // 0x02
    u32 type;        // 0x04
    u8 unk_08;       // 0x08
    u8 effect;       // 0x09
    u16 firstStat;   // 0x0a
    u16 secondStat;  // 0x0c
    u16 unk_0e;      // 0x0e
    u16 unk_10;      // 0x10
    u8 unk_12[2];    // 0x12
} DatEquipment;

// 16 bytes
typedef struct DatHeroEquipment
{
    s16 equipmentsIdx[4];     // See enum EquipmentTypes to access each idx
    DatEquipment* equipments; // 00836794 -> 010c15f0
    void* unkPtr;             // 00836798 -> 010c2d90
} DatHeroEquipment;

typedef struct DatHeroPersona
{
    s16 equippedPersona;         // 0 to 11
    DatPersonaWork personas[12];
} DatHeroPersona;

// 0x52c bytes. datInitSocialLink clears 0x508 bytes beginning at +0x14.
typedef struct DatHeroStatus
{
    DatSocial socialStats;       // 0x00
    u32 nextExp;                 // 0x08
    DatPhysical physicalState;   // 0x0c
    u8 unk_12[2];
    s16 activeSocialLink;        // 0x14
    s8 socialLinkStat[30];       // 0x16
    u8 socialLinkData[0x4e8];    // 0x34
    u8 unk_51c[0x10];
} DatHeroStatus;

// 868 bytes
typedef struct DatPc
{
    s32 unk_00;
    DatUnit unit;
    DatSocial socialStats;
    u8 unkData1[0x06];
    DatPhysical physicalState;
    u8 unk_52[2];               // pad: equipmentsIdx is at DatPc+0x54
    s16 equipmentsIdx[4];       // always 0, 1, 2, 3
    DatEquipment equipments[4]; // 0x5c
    u8 unkData2[0x2e];
    DatPersonaWork persona;
    u8 unk_110[0x250];
    u32 unk_360;
} DatPc;

// 17656 bytes through savedDungeonFloor
typedef struct DatGlobal
{
    u8 unkData1[0x24];
    DatUnit heroUnit;               // 00836224
    DatHeroStatus heroStatus;       // 00836260
    DatHeroEquipment heroEquip;     // 0083678c
    CalendarWork calendarWork;      // 0083679c
    u8 unkData3[0x400];
    DatHeroPersona heroPersona;     // 00836ba8
    DatPersonaWork compendium[256]; // 00836e1c
    u32 flags[FLG_ARR_SIZE];        // 0083a21c. See g_flags.h.
    u32 auxData[128];               // 0083a4dc
    s32 heroMoney;                  // 0083a6dc
    s16 partyIds[4];                // 0083a6e0
    u32 totalBtl;                   // 0083a6e8
    u32 savedFldMajorId;            // 0083a6ec
    u32 savedFldMinorId;            // 0083a6f0
    u32 savedDungeonFloor;          // 0083a6f4
} DatGlobal;

extern DatGlobal gGlobalWork;
extern DatPc gPcs[PC_MAX];

void datSetScenarioMode(u32 scenario);
u32 datGetScenarioMode(void);

u16 func_0016c670(s16 pcId);
u8 func_0016dbc0(s16 socialLink, u32* personaId);
u8 func_0016df30(s16 socialLink);
u16 func_00170760(s16 pcId, s16 index);
void func_00170860(s16 pcId, s16 index, u16 value);
void* func_00170e90(s16 id);
void* func_00170ed0(s16 id, s32* category);
const char* func_00171110(s16 id, s16 field);
void func_0016f320(void);
u32 FUN_0016f380(u32 idx);
void FUN_0016f3e0(u32 idx, u32 value);
void dat0016f450(void);
s32 func_0016f490(s16 pcId);

DatUnit* datGetUnit(s16 pcId);
void datInitUnit(s16 pcId);
u8 datGetLevel(s16 pcId);
u16 datGetHp(s16 pcId);
u16 datGetSp(s16 pcId);
s16 datGetEquippedPersona();
u16 datGetPersonaId(s16 pcId);
u32 datGetBadStatusNoDown(s16 pcId);
void datSetBadStatus(s16 pcId, u32 flags);
void datSetOldFatigueCounter(s16 pcId, u16 oldFatigueCounter);
void datClearBadStatus(s16 pcId, u32 flags);
u32 datGetExpUntilNextLevel(s16 pcId);
u8 datDidCharacterLevelUp(s16 pcId, u32 expGain);
void datSetAiTactic(s16 pcId, s16 aiTacticId);
s32 datGetMoney();
void datSetMoney(u32 money);
u32 datAddMoney(s32 amount);
s16 datGetPartyId(s32 idx);
void datSetPartyId(s32 idx, s16 pcId);
s8 datGetAiTactic(s16 pcId);
void datSetPhysicalCondition(s16 pcId, u16 physicalCondition);
void datSetFatigueCounter(s16 pcId, u16 fatigueCounter);
void FUN_0016ca90(s16 pcId, s16 fatigueChange);
void datSetHp(s16 pcId, s16 hp);
void datSetSp(s16 pcId, s16 sp);
void datSetLevel(s16 pcId, u8 level);
void datSetNextExp(s16 pcId, u32 nextExp);
u16 datGetFatigueCounter(s16 pcId);
u16 datGetOldFatigueCounter(s16 pcId);
void datSetActiveSocialLink(u16 activeSocialLink);
s16 *datGetActiveSocialLinkPtr();
s16 datGetDaysSinceApr5();
u8 datGetTime();
s16 datGetDaysSkipTarget();
u8 datGetTimeSkipTarget();
u32 datGetSkipToTarget();
void datSetAcademicPoint(s16 pcId, s16 academicPoint);
void datSetCharmPoint(s16 pcId, s16 charmPoint);
void datSetCouragePoint(s16 pcId, s16 couragePoint);
s16 datGetAcademicPoint(s16 pcId);
s16 datGetCharmPoint(s16 pcId);
s16 datGetCouragePoint(s16 pcId);
s16 datGetAcademicLevel(s16 academicPoint);
s16 datGetCharmLevel(s16 charmPoint);
s16 datGetCourageLevel(s16 couragePoint);
u32 datGetNextExp(s16 pcId);
u16 datGetPhysicalCondition(s16 pcId);
s16 datGetEquipmentIdx(s16 pcId, s16 equipmentType);
void datSetEquipmentIdx(s16 pcId, s16 equipmentType, s16 equipmentIdx);
void datSetDaysSinceApr5(s16 daysSinceApr5);
void datSetTime(u8 time);
void datSetDaysSkipTarget(s16 days);
void datSetTimeSkipTarget(s8 time);
void datSetSkipToTarget(u32 val);
u32 datGetFlag(s32 bit);
void datSetFlag(s32 bit, u8 enabled);
void datClearFlagAll();
u16 datGetEquipmentId(s16 pcId, s32 equipmentIdx);
u32 func_0016f720(s16 pcId, s32 equipmentIdx);
u8 func_0016f810(s16 pcId, s32 equipmentIdx);
u8 datGetEquipmentEffect(s16 pcId, s32 equipmentIdx);
u16 func_0016f9f0(s16 pcId, s32 equipmentIdx);
u16 func_0016fae0(s16 pcId, s32 equipmentIdx);
u16 func_0016fbd0(s16 pcId, s32 equipmentIdx);
u16 func_0016fcc0(s16 pcId, s32 equipmentIdx);
DatEquipment* func_0016fdb0(s16 pcId, s32 equipmentIdx);
void func_0016fea0(s16 pcId, s32 equipmentIdx, u16 value);
void func_0016ff90(s16 pcId, s32 equipmentIdx, u32 value);
void func_00170080(s16 pcId, s32 equipmentIdx, u8 value);
void func_00170170(s16 pcId, s32 equipmentIdx, u8 value);
void func_00170260(s16 pcId, s32 equipmentIdx, u16 value);
void func_00170350(s16 pcId, s32 equipmentIdx, u16 value);
void func_00170440(s16 pcId, s32 equipmentIdx, u16 value);
void func_00170530(s16 pcId, s32 equipmentIdx, u16 value);
void datInitPersona(s16 pcId);
void datCompendiumInit();
void datInitSocialLink();
s16 datGetActiveSocialLink();
s8 datGetSocialLinkLevel(s16 socialLink);
u32 datGetTotalBtl();
DatPersonaWork* datGetPersonaByCompendium(s32 idx);

u32 datScrCmd_SAVE_PARTY();
u32 datScrCmd_RESTORE_PARTY();
u32 datScrCmd_CLEAR_PARTY_ID();
u32 datScrCmd_GET_PARTY_ID();
u32 datScrCmd_GET_MONEY();
u32 datScrCmd_ADD_MONEY();
u32 datScrCmd_REMOVE_MONEY();

#endif // G_DATA_H