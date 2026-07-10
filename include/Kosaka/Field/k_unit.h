#ifndef K_UNIT_H
#define K_UNIT_H

#include "Utils.h"
#include "rw/rwplcore.h"

#define FLDUNIT_PC_HERO 0
#define FLDUNIT_PC_MAX  4

#define FLDUNIT_EC_MAX 24

typedef struct HCdvd HCdvd;
typedef struct Model Model;
typedef struct ResrcModelChar ResrcModelChar;
typedef struct DatUnitGenusBase DatUnitGenusBase;
typedef struct BtlEncountTable BtlEncountTable;
typedef struct KwlnTask KwlnTask;

// 8 bytes
typedef struct FldUnitMdl
{
    u16 type;   // 0x00
    u16 id;     // 0x02
    Model* mdl; // 0x04
} FldUnitMdl;

// 448 bytes
typedef struct FldUnit
{
    RwMatrix matBeforeBtl;       // 0x00. Saved matrix before entering a battle
    u8 unkData1[0x04];
    s32 unk_44;                   // 0x44
    DatUnitGenusBase* genusBase; // 0x48. Either 'DatUnitPc' or 'DatUnitEc'
    BtlEncountTable* encount;    // 0x4c
    Model* mdl;                  // 0x50
    ResrcModelChar* resrc;       // 0x54
    s32 unk_58;                  // 0x58
    u8 unkData2[0xfc];
    RwV3d spawnPos;              // 0x158
    s32 unk_164;                 // 0x164
    void* unk_168;               // 0x168
    KwlnTask* unk_16c;            // 0x16c
    KwlnTask* unk_170;            // 0x170
    KwlnTask* unk_174;            // 0x174
    KwlnTask* unk_178;            // 0x178
    u32 unk_17c;                 // 0x17c. Sprite/effect task marker
    KwlnTask* unk_180;            // 0x180
    s32 unk_184;                  // 0x184
    s32 unk_188;                  // 0x188
    s32 unk_18c;                  // 0x18c
    u32 scaleIdx;                // 0x190. Index for an array of different scale (RwV3d)
    s16 xGrid;                   // 0x194
    s16 zGrid;                   // 0x196
    u8 unkData4[0x10];
    u16 charId;                  // 0x1a8
    u8 unkData5[0x06];
    HCdvd* scrCdvd;              // 0x1b0
    void* unk_1b4;               // 0x1b4
    u8 unkData6[0x08];
} FldUnit;

extern FldUnitMdl gFldUnitsPcMdl[FLDUNIT_PC_MAX];
extern FldUnit gFldUnitsPc[FLDUNIT_PC_MAX];

extern FldUnit gFldUnitsEc[FLDUNIT_EC_MAX];

void K_FldUnit_DestroyPcMdl(s32 unitId);
FldUnit* K_FldUnit_FindFreePc();
FldUnit* K_FldUnit_CreateReaper(u32 unused, const RwV3d* spawnPos);
void K_FldUnit_Destroy(FldUnit* unit);
void K_FldUnit_DestroyAllPc();
void K_FldUnit_DestroyAllEc();

void func_001d0270(void);
void func_001d03f0(u16 charId);
s32 func_001d0720(s32 targetCount);
u8* func_001d0880(s32 ordinal, s32 targetCount);
void func_001d0bc0(void* output, u32 count);
u32 func_001d0e40(void);
void func_001d0e50(s32 isDungeon);
void func_001d11b0(void);
u32 func_001d12d0(void);
void func_001d1360(void);
void func_001d1640(FldUnit* unit, s32 destroyModel);
void func_001d1780(s32 includeHero);
void func_001d17f0(s32 destroyModel);
void func_001d1860(u32 value);
void func_001d1910(void);
void func_001d19d0(void);
u32 func_001d1a90(void);
void func_001d1b60(void);
void func_001d1c20(void);
u32 func_001d1ce0(void);
void func_001d1db0(void* work, const void* source, u16 resourceId);
void func_001d1fa0(void);
void func_001d2210(void);
void func_001d22a0(void* work);
u8* func_001d2300(s32 ordinal, s32 maxCount);
void func_001d2610(void);
void func_001d2a10(void);
void* func_001d32a0(KwlnTask* task);
void func_001d36c0(KwlnTask* task);
KwlnTask* func_001d36f0(KwlnTask* parent);
u32 func_001d3790(KwlnTask* task);
void func_001d37f0(KwlnTask* task, u32 value);
void func_001d3810(KwlnTask* task, u32 value);
s32 func_001d3830(KwlnTask* task);
s32 func_001d38a0(KwlnTask* task);
void func_001d38d0(KwlnTask* task, s32 multiplier);
void func_001d39c0(KwlnTask* task);
void* func_001d3a30(KwlnTask* task);
void func_001d3c10(KwlnTask* task);
KwlnTask* func_001d3c40(KwlnTask* parent, u32 model);
void* func_001d3ce0(KwlnTask* task);
void func_001d40b0(KwlnTask* task);
KwlnTask* func_001d40e0(KwlnTask* parent, FldUnit* unit);
void func_001d4180(void);
void func_001d4290(void);
u32 func_001d43e0(void* object);

/* Existing callers use the auto-generated uppercase spellings. */
#define FUN_001d0270 func_001d0270
#define FUN_001d03f0 func_001d03f0
#define FUN_001d0720 func_001d0720
#define FUN_001d0880 func_001d0880
#define FUN_001d0bc0 func_001d0bc0
#define FUN_001d0e40 func_001d0e40
#define FUN_001d0e50 func_001d0e50
#define FUN_001d11b0 func_001d11b0
#define FUN_001d12d0 func_001d12d0
#define FUN_001d1360 func_001d1360
#define FUN_001d1640 func_001d1640
#define FUN_001d1780 func_001d1780
#define FUN_001d17f0 func_001d17f0
#define FUN_001d1860 func_001d1860
#define FUN_001d1910 func_001d1910
#define FUN_001d19d0 func_001d19d0
#define FUN_001d1a90 func_001d1a90
#define FUN_001d1b60 func_001d1b60
#define FUN_001d1c20 func_001d1c20
#define FUN_001d1ce0 func_001d1ce0
#define FUN_001d1db0 func_001d1db0
#define FUN_001d1fa0 func_001d1fa0
#define FUN_001d2210 func_001d2210
#define FUN_001d22a0 func_001d22a0
#define FUN_001d2300 func_001d2300
#define FUN_001d2610 func_001d2610
#define FUN_001d2a10 func_001d2a10
#define FUN_001d32a0 func_001d32a0
#define FUN_001d36c0 func_001d36c0
#define FUN_001d36f0 func_001d36f0
#define FUN_001d3790 func_001d3790
#define FUN_001d37f0 func_001d37f0
#define FUN_001d3810 func_001d3810
#define FUN_001d3830 func_001d3830
#define FUN_001d38a0 func_001d38a0
#define FUN_001d38d0 func_001d38d0
#define FUN_001d39c0 func_001d39c0
#define FUN_001d3a30 func_001d3a30
#define FUN_001d3c10 func_001d3c10
#define FUN_001d3c40 func_001d3c40
#define FUN_001d3ce0 func_001d3ce0
#define FUN_001d40b0 func_001d40b0
#define FUN_001d40e0 func_001d40e0
#define FUN_001d4180 func_001d4180
#define FUN_001d4290 func_001d4290
#define FUN_001d43e0 func_001d43e0

#endif
