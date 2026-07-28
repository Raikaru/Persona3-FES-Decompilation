#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "Main/Social/sfl_psel.h"

static u32* sSflResult; // iGpffffb5f0 / puGpffffb5f0

extern void brRoot001f1df0(u16* members, s32* count);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern void FUN_001f6e80(void);

// FUN_001f9630
void sflResult001f9630(void)
{
    u32* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = sSflResult;
    *(u32*)((int)p + 0x341c) = 0;
    *(u32*)((int)p + 0x3418) = 0;
}

// FUN_001f9800
void sflResult001f9800(int param_1, int* param_2)
{
    int i;
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    for (i = 0; i < *(s32*)(p + 0x3404); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)(p + i * 2 + 0x33f0);
    }
    *param_2 = *(s32*)(p + 0x3404);
}

// FUN_001f9890
u32 sflResult001f9890(void)
{
    K_ASSERT(sSflResult != NULL, 0x8c);
    return *(u32*)((u8*)sSflResult + 0x18);
}

// FUN_001f99f0
void sflResult001f99f0(void)
{
    u32* puVar1;

    K_ASSERT(sSflResult != NULL, 0x8c);
    puVar1 = sSflResult;
    puVar1[0xd03] = 0;
    switch (puVar1[2]) {
    case 1:
        puVar1[0xd33] = 0;
        puVar1[0xd34] = 0;
        puVar1[0xd32] = 0;
        *puVar1 |= 0x100;
        break;
    }
    FUN_001f6e80();
    puVar1[1] = 2;
}

// FUN_001f9100
void sflResult001f9100(void)
{
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    func_00217410((u16*)(p + 0x33f0), (s32*)(p + 0x3404));
    func_002174d0((u16*)(p + 0x33e0), (s32*)(p + 0x3400));
    func_00216800();
}

// FUN_001f9770
void sflResult001f9770(int param_1, int* param_2)
{
    int i;
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    for (i = 0; i < *(s32*)(p + 0x3400); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)(p + i * 2 + 0x33e0);
    }
    *param_2 = *(s32*)(p + 0x3400);
}

extern u8* func_00209d00(void);
extern void func_0021a670(u32, u32);
extern void func_0021a760(u16);
extern u32 func_0020c500(float, void*);
extern void func_0020c400(u32, void*, const float*, float*);
extern void func_004bdde0(float, float*, const float*, u32);
extern void func_001f6630(void);
extern void func_001f7210(void);
extern void func_0034ff90(u32, const u8*);
extern void func_0034ff70(u32, float);
extern void func_0034fdf0(u32, const float*);
extern void func_0034fe30(float, u32, float, float);
extern void func_0034fd30(u32);
extern void func_0034fd70(u32, u32);
extern void datSetFlag(s32, u8);
extern u32 func_001761b0(DatPersonaWork*);
extern void func_00175ce0(DatPersonaWork*, u8*);
extern void func_00176100(DatPersonaWork*, u8*);
extern void func_001fb4b0(void*, s32, s32, s32, s32*, s32*);
extern u32 func_001fba70(short);
extern void func_00176840(DatPersonaWork*, u16);
extern void func_001768e0(DatPersonaWork*, u16);
extern u8* iGpffffb740;

extern u8* iGpffffb730;
void func_001fa0d0(void);
void func_001fa450(void);
void func_001fa4f0(u32 param_1);
u32 func_001faea0(void);
void func_001fb130(u64 param_1,u64 param_2);
void func_001fb1b0(u64 param_1,u64 param_2);
void func_001fb1f0(DatPersonaWork* persona, u16* output, s32* outputCount);
void func_001fb3f0(int param_1,int param_2,int param_3,int *param_4,int *param_5);
u16 func_001fb560(u32 param_1);
u32 func_001fba70(short param_1);
int func_001fbca0(u16 param_1);
u8 * func_001fbd50(u16 param_1,int param_2);
int func_001fbdf0(s32 start, s32 end, s32 amount, s32 category, s32 scaleMode);
int func_001fbfa0(int param_1,int param_2,int param_3,short param_4,int param_5,long param_6);
void func_001fc1f0(void);
u8 func_001fc230(DatPersonaWork* persona);
u32 func_001fc3c0(DatPersonaWork* persona);
u32 func_001fc590(u8* event, void* target);
u32 func_001fc720(u8* persona);
int func_001fc870(u8* event, void* target);
void func_001fc980(u8* event, u16* result, s32* count);
void func_001fcb30(u8* event, u32* result, s32* count);
void func_001fccc0(u8* src, u8* dst, u32 skill);
void func_001fce20(u8* persona, u16* skills, s32 count);
void func_001fd350(u8* persona, u32* skills, s32 count);
extern s16 FUN_001706c0(s16 pcId, s16 index);
extern u8* pbGpffffb758;
extern u16* puGpffffb74c;
extern u16* puGpffffb730;
extern u16* puGpffffb750;
extern short* psGpffffb754;
extern char gp0xffff9700[];
extern char gp0xffff9708[];
extern char gp0xffff9710[];
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u8* DAT_007ce430;

extern u8* iGpffffb738;
extern int iGpffffb75c;
extern int iGpffffb760;
extern int iGpffffb764;
extern int iGpffffb768;
extern int iGpffffb76c;
extern int iGpffffb770;
extern int iGpffffb774;
extern int iGpffffb778;
extern u8* iGpffffb7ac;
extern u8* iGpffffb7b8;
extern f32 fGpffff8070;
extern f32 fGpffff83b0;
extern f32 fGpffff83b4;
extern char* pcGpffffb75c;
extern char* pcGpffffb760;
extern char* pcGpffffb764;
extern char* pcGpffffb768;
extern char* pcGpffffb76c;
extern char* pcGpffffb770;
extern char* pcGpffffb774;
extern char* pcGpffffb778;
extern u8 DAT_00684d70[];
#pragma alias DAT_00684d60 DAT_00684d70
extern u8 DAT_00684d60[];
#pragma alias FUN_00182c50_typed FUN_00182c50
extern void FUN_00182c50_typed(s16 skill, u8* dst);
extern void FUN_001831e0_typed(s16 slot, u32 index, u8* dst);

#pragma alias FUN_0016da50_typed FUN_0016da50
extern void FUN_0016da50_typed(s16 slot, s16 type, s16 index);


// FUN_001f9170 NONMATCHING
u32 sflResult001f9170(u32 player)
{
    s32 j;
    char* flags;
    s32 i;
    s16 members[6];
    s32 memberCount;
    flags = (char*)func_00209d00() + player * 0x1a;
    i = 0;
    for (; i <= 0xc; i++) {
        if (flags[i * 2] == 0) {
            continue;
        }
        switch (i) {
        case 0:
            if (datGetHp(1) < datGetMaxHp(1)) {
                return 1;
            }
            break;
        case 1:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetHp(members[j]) < datGetMaxHp(members[j])) {
                    return 1;
                }
            }
            break;
        case 2:
            if (datGetSp(1) < func_0016c670(1)) {
                return 1;
            }
            break;
        case 3:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetSp(members[j]) < func_0016c670(members[j])) {
                    return 1;
                }
            }
            break;
        case 4:
            if ((datGetBadStatusNoDown(1) & 0x80) != 0) {
                return 1;
            }
            break;
        case 5:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if ((datGetBadStatusNoDown(members[j]) & 0x80) != 0) {
                    return 1;
                }
            }
            break;
        case 7: {
            u16 condition = datGetPhysicalCondition(1);
            if ((u16)(condition - 3) < 3) {
                return 1;
            }
            break;
        }
        case 8:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                u16 condition = datGetPhysicalCondition(members[j]);
                if (condition == 3 || condition == 4 || condition == 5) {
                    return 1;
                }
            }
            break;
        case 9: {
            u16 condition = datGetPhysicalCondition(1);
            if (condition != 1 && condition != 2) {
                return 1;
            }
            break;
        }
        case 10:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                u16 condition = datGetPhysicalCondition(members[j]);
                if (condition != 1 && condition != 2) {
                    return 1;
                }
            }
            break;
        case 11:
            if (datGetPhysicalCondition(1) != 2) {
                return 1;
            }
            break;
        case 12:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetPhysicalCondition(members[j]) != 2) {
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}

// FUN_001f9680
/* Removing this loses FUN_001f9680 (MATCH nd0 -> MISMATCH nd57) - measured W161. */
#pragma opt_loop_invariants on
u32 sflResult001f9680(const s32* request)
{
    u8* base;
    s32* entry;
    s32 i;
    s32 count;
    s32 stride;
    u32 result;

    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    i = 0;
    count = *(s32*)(base + 0x33dc);
    result = 1;
    stride = 0x670;
    while (i < count)
    {
        entry = (s32*)(base + i * stride + 0x5c);
        if (entry[0] == request[0])
        {
            switch (request[0])
            {
            case 0:
                if (*(u16*)&entry[1] == *(u16*)&request[1])
                    return result;
                break;
            case 1:
                if (entry[1] == request[1] || entry[2] == request[2])
                    return result;
                break;
            }
        }
        i++;
    }
    return 0;
}
#pragma opt_loop_invariants off

// FUN_001f98d0
void sflResult001f98d0(void)
{
    u8* base;
    s32 i;
    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    if ((*(u32*)base & 0x80) != 0) {
        switch (*(u32*)(base + 8)) {
        case 1:
            for (i = 0; i < *(s32*)(base + 0x33dc); i++) {
                s32* entry = (s32*)(base + i * 0x670 + 0x5c);
                switch (entry[0]) {
                case 0:
                    func_0021a760(*(u16*)(entry + 1));
                    break;
                case 1:
                    func_0021a670(entry[1], entry[2]);
                    break;
                }
            }
            *(u32*)base |= 0x80;
            *(u32*)(base + 4) = 0;
            break;
        case 0:
            func_001f6630();
            break;
        }
        *(u32*)base &= ~0x80;
    }
}

#pragma optimization_level 3
// FUN_001f9a80 NONMATCHING
void sflResult001f9a80(void)
{
    u8* base;
    s32 i;
    s32 count;

    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    *(u32*)(base + 0x3408) = 0;
    if (*(u32*)(base + 8) == 1) {
        count = *(s32*)(base + 0x3418);
        for (i = 0; i < count; i++) {
            u32 index = *(u32*)(base + 0x1c + i * 4);
            u8* entry = base + index * 0x670 + 0x68;
            float scale[3] = {10.0f, 10.0f, 10.0f};
            float origin[2] = {(float)i * 220.0f + 320.0f, 184.0f};
            float rect[4];
            float quad[3] = {0.0f, 1.0f, 0.0f};
            u32 frame;

            sflRes0020d630(entry, scale);
            frame = func_0020c500(200.0f, entry);
            func_0020c400(frame, entry, origin, rect);
            rect[1] += 100.0f;
            sflRes0020d650(entry, rect);
            func_004bdde0(180.0f, quad, quad, 0);
            sflRes0020d690(entry, quad);
        }
        *(u32*)(base + 0x36d8) = 0;
        *(u32*)(base + 0x36dc) = 0;
        *(u32*)(base + 0x36d4) = 0;
        *(u32*)base |= 0x200;
        if (*(u32*)(base + 0x341c) != 0) {
            *(u32*)(base + 0x34d0) = 0;
            *(u32*)(base + 0x34c8) = 1;
            *(u32*)base |= 0x100;
        }
    }
    func_001f7210();
    *(u32*)(base + 4) = 7;
}
#pragma optimization_level 2

// FUN_001f9c60
void sflResult001f9c60(void)
{
    struct Vector3 {
        float x;
        float y;
        float z;
    };
    u8* base;
    u8 color[4];
    struct Vector3 position;
    u32 index;
    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    index = *(u32*)(base + 0x3408);
    index *= 4;
    index += (u32)base;
    index = *(u32*)(index + 0x1c);
    position = *(struct Vector3*)(base + index * 0x670 + 0x88);
    position.x = 0.0f;
    position.y = 120.0f;
    position.z = 200.0f;
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0034ff90(*(u32*)(base + 0x34e0), color);
    func_0034ff70(*(u32*)(base + 0x34e0), fGpffff8070);
    func_0034fdf0(*(u32*)(base + 0x34e0), (float*)&position);
    func_0034fe30(0.0f, *(u32*)(base + 0x34e0), 0.0f, 0.0f);
    func_0034fd30(*(u32*)(base + 0x34e0));
    func_0034fd70(*(u32*)(base + 0x34e0), 7);
}

// FUN_001f9d70
void sflResult001f9d70(u16 index)
{
    switch (index) {
    case 2: datSetFlag(0x1211, 1); break;
    case 3: datSetFlag(0x1212, 1); break;
    case 4: datSetFlag(0x1213, 1); break;
    case 5: datSetFlag(0x1214, 1); break;
    case 7: datSetFlag(0x1216, 1); break;
    case 8: datSetFlag(0x1217, 1); break;
    case 9: datSetFlag(0x1218, 1); break;
    case 10: datSetFlag(0x1219, 1); break;
    default: K_ASSERT(false, 0x49); break;
    }
}

// FUN_001f9e90 NONMATCHING
void sflResult001f9e90(u16 owner, s32 exp)
{
    DatPersonaWork* persona;
    u8 growth[40];
    s32 skillOffset;
    s32 skillCount;
    s32 i;
    u8 level;
    u8 ownerType;

    K_ASSERT(exp >= 0, 0x5e);
    K_ASSERT(owner >= 2 && owner <= 10, 0x6f);
    FUN_005225a8(0x684bb8, owner);
    level = datGetLevel(owner);
    persona = datPersonaGetByPcId(owner);
    K_ASSERT(persona != NULL, 0x75);
    datPersonaAddExp(persona, exp);
    if (func_001761b0(persona) == 0) {
        return;
    }
    func_00175ce0(persona, growth);
    skillOffset = (persona->id - 0xc0) * 0x26e;
    ownerType = *((u8*)persona + 4);
    func_001fb4b0(iGpffffb740 + skillOffset + 4, 0x20,
                 ownerType, growth[0], &skillOffset, &skillCount);
    func_00176100(persona, growth);
    for (i = 0; i < skillCount; i++) {
        u8* skill = iGpffffb740 + (persona->id - 0xc0) * 0x26e +
                    4 + skillOffset * 4 + i * 4;
        if (skill[1] == 2) {
            FUN_005225a8(0x684be0, *(u16*)(skill + 2));
            func_001768e0(persona, *(u16*)(skill + 2));
        } else if (skill[1] == 1) {
            FUN_005225a8(0x684bc8, *(u16*)(skill + 2));
            func_00176840(persona, *(u16*)(skill + 2));
        }
    }
    FUN_005225a8(0x684bf8, owner, level);
    (void)level;
}
#pragma optimization_level 3
#define FUN_00182c50 FUN_00182c50_typed
#define FUN_001831e0 FUN_001831e0_typed
#define FUN_0016da50 FUN_0016da50_typed
// FUN_001FA0D0 NONMATCHING


void func_001fa0d0(void)
{
    s16 uVar1;
    char* pcVar2;
    u32 uVar3;
    u8 auStack_20[16];

    for (uVar3 = 0; (int)uVar3 < 0xb; uVar3 = uVar3 + 1) {
        uVar1 = (s16)uVar3;
        switch (uVar3) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
            switch (uVar3 & 0xffff) {
            default:
                FUN_0019d3f0(0x684ba8, 0x35);
                pcVar2 = (char*)0;
                break;
            case 2:
                pcVar2 = pcGpffffb75c;
                break;
            case 3:
                pcVar2 = pcGpffffb760;
                break;
            case 4:
                pcVar2 = pcGpffffb764;
                break;
            case 5:
                pcVar2 = pcGpffffb768;
                break;
            case 7:
                pcVar2 = pcGpffffb76c;
                break;
            case 8:
                pcVar2 = pcGpffffb770;
                break;
            case 9:
                pcVar2 = pcGpffffb774;
                break;
            case 10:
                pcVar2 = pcGpffffb778;
                break;
            }
            if (*pcVar2 != '\0') {
                FUN_0019d3f0(0x684ba8, 200);
            }
            if (*(u16*)(pcVar2 + 2) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 2), auStack_20);
                FUN_001831e0(uVar1, 0, auStack_20);
                FUN_0016da50(uVar1, 0, 0);
            }
            if (*(u16*)(pcVar2 + 4) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 4), auStack_20);
                FUN_001831e0(uVar1, 1, auStack_20);
                FUN_0016da50(uVar1, 1, 1);
            }
            if (*(u16*)(pcVar2 + 6) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 6), auStack_20);
                FUN_001831e0(uVar1, 2, auStack_20);
                FUN_0016da50(uVar1, 2, 2);
            }
            if (*(u16*)(pcVar2 + 8) != 0) {
                FUN_00182c50((s16)*(u16*)(pcVar2 + 8), auStack_20);
                FUN_001831e0(uVar1, 3, auStack_20);
                FUN_0016da50(uVar1, 3, 3);
            }
            break;
        case 6:
            FUN_00182c50(0xfe, auStack_20);
            FUN_001831e0(uVar1, 0, auStack_20);
            FUN_0016da50(uVar1, 0, 0);
            FUN_00182c50(0x43f, auStack_20);
            FUN_001831e0(uVar1, 1, auStack_20);
            FUN_0016da50(uVar1, 1, 1);
            FUN_00182c50(0x821, auStack_20);
            FUN_001831e0(uVar1, 2, auStack_20);
            FUN_0016da50(uVar1, 2, 2);
            FUN_00182c50(0xc47, auStack_20);
            FUN_001831e0(uVar1, 3, auStack_20);
            FUN_0016da50(uVar1, 3, 3);
        }
    }
}
#undef FUN_00182c50
#undef FUN_001831e0
#undef FUN_0016da50
#pragma optimization_level 2


// FUN_001fa450
void func_001fa450(void)



{

  int lVar1;

  

  lVar1 = FUN_0017d800();

  if (lVar1 == 0) {

    FUN_005225a8("brfUpdateFriendEquip\n");

    func_001fa4f0(2);

    func_001fa4f0(3);

    func_001fa4f0(4);

    func_001fa4f0(5);

    func_001fa4f0(7);

    func_001fa4f0(8);

    func_001fa4f0(9);

    func_001fa4f0(10);

  }

  return;

}
// FUN_001FA4F0 NONMATCHING


void func_001fa4f0(u32 param_1)



{

  u8 bVar1;

  u8 bVar2;

  short sVar3;

  u16 uVar4;

  u32 uVar5;

  int iVar6;

  s32 lVar7;

  u32 uVar8;

  u32 uVar10;

  s16 uVar9;

  u32 uVar11;

  u8 bVar12;

  u8 bVar13;

  int iVar14;

  u16 unaff_s7_lo;

  u16 unaff_s8_lo;

  u32 uStack_a0;

  u32 uStack_90;

  u32 uStack_80;

  u32 uStack_70;

  u16 uStack_60;

  u16 uStack_50;

  int iStack_30;

  u8 auStack_20 [24];

  int iStack_8;

  int iStack_4;

  

  uVar10 = param_1 & 0xffff;

  switch((int)uVar10) {

  default:

    FUN_0019d3f0(0x684ba8,0x136);

    break;

  case 2:

  case 3:

  case 4:

  case 5:

  case 7:

  case 8:

  case 9:

  case 10:

    break;

  }

  uVar9 = (u16)param_1;

  uVar5 = FUN_0016c470(uVar9);

  uVar5 = uVar5 & 0xff;

  iVar6 = FUN_00177d10(uVar10);

  if (iVar6 < (int)uVar5) {

    switch((int)uVar10) {

    default:

      FUN_0019d3f0(0x684ba8,0x35);

      iVar14 = 0;

      break;

    case 2:

      iVar14 = iGpffffb75c;

      break;

    case 3:

      iVar14 = iGpffffb760;

      break;

    case 4:

      iVar14 = iGpffffb764;

      break;

    case 5:

      iVar14 = iGpffffb768;

      break;

    case 7:

      iVar14 = iGpffffb76c;

      break;

    case 8:

      iVar14 = iGpffffb770;

      break;

    case 9:

      iVar14 = iGpffffb774;

      break;

    case 10:

      iVar14 = iGpffffb778;

    }

    func_001fb3f0(iVar14,iVar6,uVar5 - iVar6,&iStack_4,&iStack_8);

    iVar14 = iVar14 + iStack_4 * 10;

    uVar11 = 0;

    sVar3 = FUN_0016cb80(uVar9,0);

    bVar1 = sVar3 != -1;

    if (bVar1) {

      unaff_s7_lo = FUN_0016f630(uVar9);

      iVar6 = FUN_00170d60(unaff_s7_lo);

      uStack_70 = (u32)*(u16 *)(iVar6 + 0x20);

    }

    sVar3 = FUN_0016cb80(uVar9,1);

    bVar12 = bVar1;

    if (sVar3 != -1) {

      unaff_s8_lo = FUN_0016f630(uVar9);

      iVar6 = FUN_00170da0(unaff_s8_lo);

      uStack_80 = (u32)*(u16 *)(iVar6 + 0x16);

      bVar12 = 2;

    }

    sVar3 = FUN_0016cb80(uVar9,2);

    if (sVar3 != -1) {

      uStack_50 = FUN_0016f630(uVar9);

      iVar6 = FUN_00170df0(uStack_50);

      uStack_90 = (u32)*(u16 *)(iVar6 + 0x16);

      bVar12 = bVar12 | 4;

    }

    sVar3 = FUN_0016cb80(uVar9,3);

    if (sVar3 != -1) {

      uStack_60 = FUN_0016f630(uVar9);

      iVar6 = FUN_00170e40(uStack_60);

      uStack_a0 = (u32)*(u16 *)(iVar6 + 0x14);

      bVar12 = bVar12 | 8;

    }

    bVar2 = bVar1;

    bVar13 = bVar12;

    for (iStack_30 = 0; iStack_30 < iStack_8; iStack_30 = iStack_30 + 1) {

      if (*(short *)(iVar14 + 2) != 0) {

        iVar6 = FUN_00170d60(*(short *)(iVar14 + 2));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x20);

        if (bVar2) {

          if ((int)uStack_70 < (int)uVar8) {

            unaff_s7_lo = *(u16 *)(iVar14 + 2);

            uVar11 = uVar11 | 1;

            uStack_70 = uVar8;

          }

        }

        else {

          unaff_s7_lo = *(u16 *)(iVar14 + 2);

          bVar2 = true;

          uVar11 = uVar11 | 1;

          uStack_70 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 4) != 0) {

        iVar6 = FUN_00170da0(*(short *)(iVar14 + 4));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x16);

        if ((bVar13 & 2) == 0) {

          unaff_s8_lo = *(u16 *)(iVar14 + 4);

          bVar13 = bVar13 | 2;

          uVar11 = uVar11 | 2;

          uStack_80 = uVar8;

        }

        else if ((int)uStack_80 < (int)uVar8) {

          unaff_s8_lo = *(u16 *)(iVar14 + 4);

          uVar11 = uVar11 | 2;

          uStack_80 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 6) != 0) {

        iVar6 = FUN_00170df0(*(short *)(iVar14 + 6));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x16);

        if ((bVar13 & 4) == 0) {

          uStack_50 = *(u16 *)(iVar14 + 6);

          bVar13 = bVar13 | 4;

          uVar11 = uVar11 | 4;

          uStack_90 = uVar8;

        }

        else if ((int)uStack_90 < (int)uVar8) {

          uStack_50 = *(u16 *)(iVar14 + 6);

          uVar11 = uVar11 | 4;

          uStack_90 = uVar8;

        }

      }

      if (*(short *)(iVar14 + 8) != 0) {

        iVar6 = FUN_00170e40(*(short *)(iVar14 + 8));

        uVar8 = (u32)*(u16 *)(iVar6 + 0x14);

        if ((bVar13 & 8) == 0) {

          uStack_60 = *(u16 *)(iVar14 + 8);

          bVar13 = bVar13 | 8;

          uVar11 = uVar11 | 8;

          uStack_a0 = uVar8;

        }

        else if ((int)uStack_a0 < (int)uVar8) {

          uStack_60 = *(u16 *)(iVar14 + 8);

          uVar11 = uVar11 | 8;

          uStack_a0 = uVar8;

        }

      }

      iVar14 = iVar14 + 10;

    }

    if ((uVar11 & 1) != 0) {

      FUN_00182c50(unaff_s7_lo,auStack_20);

      if (bVar1) {

        uVar4 = FUN_0016cb80(uVar9,0);

        lVar7 = func_00177ca0(uVar10,0);

        if (lVar7 != 0) {

          func_00177b90(param_1,0,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,0);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x1df);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 2) != 0) {

      FUN_00182c50(unaff_s8_lo,auStack_20);

      if ((bVar12 & 2) != 0) {

        uVar4 = FUN_0016cb80(uVar9,1);

        lVar7 = func_00177ca0(uVar10,1);

        if (lVar7 != 0) {

          func_00177b90(param_1,1,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,1);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x1f7);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 4) != 0) {

      FUN_00182c50(uStack_50,auStack_20);

      if ((bVar12 & 4) != 0) {

        uVar4 = FUN_0016cb80(uVar9,2);

        lVar7 = func_00177ca0(uVar10,2);

        if (lVar7 != 0) {

          func_00177b90(param_1,2,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,2);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x210);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if ((uVar11 & 8) != 0) {

      FUN_00182c50(uStack_60,auStack_20);

      if ((bVar12 & 8) != 0) {

        uVar4 = FUN_0016cb80(uVar9,3);

        lVar7 = func_00177ca0(uVar10,3);

        if (lVar7 != 0) {

          func_00177b90(param_1,3,uVar4);

          func_00177c50(uVar10,uVar4);

        }

        FUN_001831e0(uVar9,uVar4,auStack_20);

      }

      else {

        sVar3 = FUN_0016cb80(uVar9,3);

        if (sVar3 != -1) {

          FUN_0019d3f0(0x684ba8,0x229);

        }

        iVar6 = 0;

        while ((iVar6 < 4 && (sVar3 = FUN_0016f630(uVar9,iVar6), sVar3 != 0))) {

          iVar6 = iVar6 + 1;

        }

        FUN_001831e0(uVar9,(short)iVar6,auStack_20);

      }

    }

    if (uVar11 != 0) {

      FUN_001f9d70(param_1);

    }

    FUN_00177ce0(uVar10,uVar5);

  }

  return;

}
#pragma optimization_level 3
// FUN_001FAEA0 NONMATCHING


u32 func_001faea0(void)



{

  u8 uVar1;

  u16 uVar2;

  long lVar3;

  long lVar4;

  int iVar5;

  u32 uVar6;

  u8 auStack_8 [8];

  

  uVar2 = FUN_0035ed20(0);

  lVar3 = FUN_00174800(uVar2);

  lVar4 = FUN_0017d800();

  if ((lVar4 == 0) && (lVar3 != 0)) {

    for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {

      uVar1 = FUN_00173b00(lVar3,uVar6 & 0xffff);

      auStack_8[uVar6] = uVar1;

    }

  }

  iVar5 = (int)lVar3;

  switch(uVar2) {

  default:

    FUN_0019d3f0(0x684ba8,0x2ca);

    break;

  case 1:

    lVar4 = FUN_0017d800();

    if ((lVar4 != 0) && (*(short *)(iVar5 + 2) == 0xc3)) {

      FUN_00174e20(1);

      FUN_00175130(1);

      FUN_00174b40(*(u16 *)(iVar5 + 2));

    }

    break;

  case 2:

    if (*(short *)(iVar5 + 2) == 0xc0) {

      func_001fb130(uVar2,0xc1);

    }

    break;

  case 3:

    if (*(short *)(iVar5 + 2) == 0xc2) {

      func_001fb130(uVar2,0xc3);

    }

    break;

  case 4:

    if (*(short *)(iVar5 + 2) == 0xc4) {

      func_001fb130(uVar2,0xc5);

    }

    break;

  case 5:

    if (*(short *)(iVar5 + 2) == 0xc6) {

      func_001fb130(uVar2,199);

    }

    break;

  case 6:

    if (*(short *)(iVar5 + 2) == 200) {

      func_001fb130(uVar2,0xc9);

    }

    break;

  case 7:

    if (*(short *)(iVar5 + 2) == 0xca) {

      func_001fb130(uVar2,0xcb);

    }

    break;

  case 8:

    if (*(short *)(iVar5 + 2) == 0xcc) {

      func_001fb130(uVar2,0xcd);

    }

  }

  lVar4 = FUN_0017d800();

  if ((lVar4 == 0) && (lVar3 != 0)) {

    for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {

      FUN_00173b60(uVar2,uVar6 & 0xffff,auStack_8[uVar6]);

    }

  }

  return 1;

}
#pragma optimization_level 2


// FUN_001fb130
void func_001fb130(u64 param_1,u64 param_2)



{

  u16 uVar1;

  u32 uVar2;

  int iVar3;

  

  iVar3 = FUN_00174800();

  uVar1 = *(u8 *)(iVar3 + 4);

  FUN_00175820(param_1,param_2);

  uVar2 = FUN_00174800(param_1);

  uVar2 = func_00176210(uVar2,uVar1);

  FUN_001f9e90(param_1,uVar2);

  return;

}
// FUN_001FB1B0


void func_001fb1b0(u64 param_1,u64 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00174800();

  FUN_001770d0(*(u16 *)(iVar1 + 2),param_2);

  return;

}
// FUN_001FB1F0 NONMATCHING


void func_001fb1f0(DatPersonaWork* persona, u16* output, s32* outputCount)
{
    u16* skills;
    s32 skillCount;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    s32 i;
    s32 outputSize;
    s32 j;

    skills = datPersonaGetSkills(persona);
    skillCount = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    outputSize = 0;
    for (i = 0; i < indexCount; i++, current += 4)
    {
        switch (current[1])
        {
        case 1:
            j = 0;
            while (j < skillCount)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == skillCount)
            {
                K_ASSERT(outputSize < 8, 0x5b);
                output[outputSize] = *(u16*)(current + 2);
                outputSize++;
            }
            break;
        }
        if (outputSize == 8)
            break;
    }
    *outputCount = outputSize;
}
// FUN_001FB3F0
#pragma optimization_level 2
/* Removing this loses FUN_001fb3f0 (MATCH nd0 -> MISMATCH nd137) - measured W161. */
#pragma opt_loop_invariants on
void func_001fb3f0(int param_1,int param_2,int param_3,int *param_4,int *param_5)
{
    int param_3_p = param_3;
    s32 first;
    s32 last;
    s32 foundStart;
    s32 upperBound;
    s32 i;
    u8 *entry;

  upperBound = param_2 + param_3_p;
  i = 0;
  foundStart = 0;
  /* Removing this barrier loses func_001fb3f0 (MATCH nd0 -> MISMATCH nd2) - measured W164. */
  asm ("" : "+r"(i));
  while (1) {
    entry = (u8 *)(param_1 + i * 10);
    if ((*(u16 *)(entry + 2) == 0) &&
        (*(u16 *)(entry + 4) == 0) &&
        (*(u16 *)(entry + 6) == 0) &&
        (*(u16 *)(entry + 8) == 0)) {
      break;
    }
    if ((param_2 < (int)(u32)*entry) &&
        ((int)(u32)*entry <= upperBound)) {
      if (!foundStart) {
        first = i;
        foundStart = 1;
      }
      last = i;
    }
    i = i + 1;
  }
  if (foundStart) {
    *param_4 = first;
    *param_5 = (last + 1) - first;
  } else {
    *param_4 = 0;
    *param_5 = 0;
  }
}
#pragma opt_loop_invariants off
#pragma optimization_level 2
// FUN_001FB4B0
/* Removing this loses FUN_001fb4b0 (MATCH nd0 -> MISMATCH nd118) - measured W161. */
#pragma opt_loop_invariants on


void func_001fb4b0(void* entries, s32 capacity, s32 lowerBound, s32 range,
                   s32* firstIndex, s32* indexCount)
{
  s32 upperBound;
  int i;
  int first;
  int last;
  s32 foundStart;
  s32 foundRange;
  u32 value;
  u8* entry;

  upperBound = lowerBound + range;
  first = 0;
  foundStart = 0;
  foundRange = 0;
  i = 0;
  while (i < capacity) {
    entry = (u8*)entries + i * 4;
    if (((s8*)entry)[1] == 0) {
      break;
    }
    value = (u32)*entry;
    if (lowerBound < (int)value) {
      if (!foundStart) {
        foundStart = 1;
        first = i;
        last = i;
      }
      if ((int)value <= upperBound) {
        foundRange = 1;
        last = i;
      }
    }
    i = i + 1;
  }
  if (foundRange) {
    *firstIndex = first;
    *indexCount = (last + 1) - first;
  } else {
    *firstIndex = first;
    *indexCount = 0;
  }
}
#pragma opt_loop_invariants off
#pragma optimization_level 3
// FUN_001FB560 NONMATCHING


u16 func_001fb560(u32 param_1)



{

  u8 bVar1;

  u16 uVar2;

  u32 uVar3;

  int iVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  int iVar9;

  u32 uVar10;

  int iVar11;

  u16 *puVar12;

  u8 bVar13;

  u32 unaff_s8_lo;

  u16 auStack_220 [16];

  u16 auStack_200 [256];

  

  FUN_005225a8(0x684c40,param_1 & 0xffff);

  uVar8 = FUN_0016c7e0(1);

  uVar3 = FUN_0016d280(uVar8);

  uVar3 = uVar3 & 0xff;

  iVar4 = FUN_001749a0(param_1);

  bVar1 = *(u8 *)(iVar4 + 4);

  uVar5 = FUN_001756f0();

  uVar5 = uVar5 & 0xffff;

  for (iVar4 = 0; iVar4 < (int)uVar5; iVar4 = iVar4 + 1) {

    iVar9 = FUN_00174a90((short)iVar4);

    auStack_220[iVar4] = *(u16 *)(iVar9 + 2);

  }

  FUN_005225a8(0x684c60);

  iVar4 = -1;

  iVar11 = 0;

  iVar9 = 0;

  for (puVar12 = puGpffffb74c;

      (((u32)*puVar12 != 0 || (puVar12[1] != 0)) || ((char)puVar12[2] != '\0'));

      puVar12 = puVar12 + 3) {

    if ((u32)*puVar12 == (param_1 & 0xffff)) {

      if (iVar4 == -1) {

        iVar4 = iVar9;

      }

      iVar11 = iVar11 + 1;

    }

    iVar9 = iVar9 + 1;

  }

  FUN_005225a8(0x684c70,iVar11);

  bVar13 = false;

  iVar9 = 0;

  do {

    if (iVar11 <= iVar9) {

LAB_001fb794:

      if ((bVar13) &&

         (FUN_005225a8(0x684ca0,*(u8 *)((int)puGpffffb730 + unaff_s8_lo * 0xe + 3),uVar3),

         *(u8 *)((int)puGpffffb730 + unaff_s8_lo * 0xe + 3) <= uVar3)) {

        FUN_005225a8(&gp0xffff9708);

        uVar2 = puVar12[1];

      }

      else {

        FUN_005225a8(0x684c90);

        FUN_005225a8(0x684cd0);

        iVar4 = 0;

        puVar12 = puGpffffb730;

        for (uVar7 = 0; (int)uVar7 < 0x100; uVar7 = uVar7 + 1) {

          uVar2 = *puVar12;

          if ((((((uVar2 & 8) == 0) && ((uVar2 & 0x10) == 0)) && ((uVar2 & 4) == 0)) &&

              (((uVar2 & 2) == 0 && (uVar10 = (u32)*(u8 *)((int)puVar12 + 3), bVar1 <= uVar10))))

             && ((uVar10 <= bVar1 + 10 && (uVar10 <= uVar3)))) {

            for (iVar9 = 0; (iVar9 < (int)uVar5 && (uVar7 != auStack_220[iVar9])); iVar9 = iVar9 + 1

                ) {

            }

            if ((int)uVar5 <= iVar9) {

              auStack_200[iVar4] = (u16)uVar7;

              iVar4 = iVar4 + 1;

            }

          }

          puVar12 = puVar12 + 7;

        }

        FUN_005225a8(0x684ce0,iVar4);

        if (iVar4 == 0) {

          FUN_005225a8(0x684c90);

          puVar12 = puGpffffb750;

          for (iVar4 = 0; iVar4 < 0xd; iVar4 = iVar4 + 1) {

            for (iVar9 = 0; (iVar9 < (int)uVar5 && (*puVar12 != auStack_220[iVar9]));

                iVar9 = iVar9 + 1) {

            }

            if ((int)uVar5 <= iVar9) {

              return *puVar12;

            }

            puVar12 = puVar12 + 1;

          }

          FUN_0019d3f0(0x684c28,0x169);

          uVar2 = 0;

        }

        else {

          FUN_005225a8(&gp0xffff9708);

          FUN_005225a8(0x684cf8);

          for (iVar9 = 0; iVar9 < iVar4; iVar9 = iVar9 + 1) {

            FUN_005225a8(&gp0xffff9710,iVar9,auStack_200[iVar9]);

          }

          iVar9 = FUN_00488f30();

          FUN_005225a8(0x684d08,iVar9 % iVar4);

          uVar2 = auStack_200[iVar9 % iVar4];

        }

      }

      return uVar2;

    }

    puVar12 = puGpffffb74c + (iVar4 + iVar9) * 3;

    for (iVar6 = 0; (iVar6 < (int)uVar5 && (puVar12[1] != auStack_220[iVar6])); iVar6 = iVar6 + 1) {

    }

    if ((int)uVar5 <= iVar6) {

      FUN_005225a8(&gp0xffff9700,puVar12[1]);

      iVar6 = FUN_00488f30();

      FUN_005225a8(0x684c80,iVar6 % 100,(char)puVar12[2]);

      if ((u32)(iVar6 % 100) < (u32)(u8)puVar12[2]) {

        FUN_005225a8(&gp0xffff9708);

        unaff_s8_lo = (u32)puVar12[1];

        bVar13 = true;

        goto LAB_001fb794;

      }

      FUN_005225a8(0x684c90);

    }

    iVar9 = iVar9 + 1;

  } while( true );

}
#pragma optimization_level 2
#pragma optimization_level 3
// FUN_001FBA70 NONMATCHING


u32 func_001fba70(short param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  int iVar6;

  short *psVar7;

  u8 bVar8;

  int iVar9;

  u32 unaff_s7;

  

  iVar1 = FUN_001749a0();

  iVar9 = 0;

  iVar6 = 0;

  iVar3 = -1;

  for (psVar7 = psGpffffb754; ((*psVar7 != 0 || (psVar7[1] != 0)) || ((char)psVar7[2] != '\0'));

      psVar7 = psVar7 + 3) {

    if (*psVar7 == param_1) {

      if (iVar3 == -1) {

        iVar3 = iVar6;

      }

      iVar9 = iVar9 + 1;

    }

    iVar6 = iVar6 + 1;

  }

  FUN_005225a8(0x684d20,iVar9);

  bVar8 = false;

  iVar6 = 0;

  do {

    psVar7 = psGpffffb754;

    if (iVar9 <= iVar6) {

LAB_001fbbd0:

      if (!bVar8) {

        FUN_005225a8(0x684c90);

        lVar4 = func_001fbca0(*(u8 *)(iVar1 + 4));

        FUN_005225a8(0x684d30,lVar4);

        if (lVar4 == 0) {

          FUN_0019d3f0(0x684c28,0x1b3);

        }

        iVar3 = FUN_00488f30();

        iVar3 = iVar3 % (int)lVar4;

        FUN_005225a8(0x684d40,iVar3);

        iVar3 = (int)func_001fbd50(*(u8 *)(iVar1 + 4),iVar3);

        unaff_s7 = (u32)*(u16 *)(iVar3 + 2);

      }

      return unaff_s7;

    }

    iVar5 = iVar3 + iVar6;

    FUN_005225a8(&gp0xffff9700,psGpffffb754[iVar5 * 3 + 1]);

    iVar2 = FUN_00488f30();

    FUN_005225a8(0x684c80,iVar2 % 100,(char)psVar7[iVar5 * 3 + 2]);

    if ((u32)(iVar2 % 100) < (u32)*(u8 *)(psVar7 + iVar5 * 3 + 2)) {

      FUN_005225a8(&gp0xffff9708);

      unaff_s7 = (u32)(u16)psVar7[iVar5 * 3 + 1];

      bVar8 = true;

      goto LAB_001fbbd0;

    }

    FUN_005225a8(0x684c90);

    iVar6 = iVar6 + 1;

  } while( true );

}
#pragma optimization_level 2


// FUN_001fbca0
int func_001fbca0(u16 param_1)
{
  u8* entry;
  int count;
  int target;
  u8 lower;

  count = 0;
  entry = pbGpffffb758;
  target = param_1;

check_entry:
  lower = *entry;
  if (lower != 0) goto inspect_entry;
  if (entry[1] != 0) goto inspect_entry;
  if (*(u16*)(entry + 2) == 0) goto done;

inspect_entry:
  if (target < lower) goto next_entry;
  if (target >= entry[1]) goto next_entry;
  FUN_005225a8("%d <= %d < %d\n", lower, target, entry[1]);
  count++;

next_entry:
  entry += 4;
  goto check_entry;

done:
  return count;
}


// FUN_001fbd50
u8* func_001fbd50(u16 param_1, int param_2)
{
  u8* entry;
  int matchIndex;
  int target;

  entry = pbGpffffb758;
  matchIndex = 0;
  target = param_1;

check_entry:
  if (*entry != 0) goto inspect_entry;
  if (entry[1] != 0) goto inspect_entry;
  if (*(u16*)(entry + 2) == 0) goto no_match;

inspect_entry:
  if (target >= *entry) {
    if (target < entry[1]) {
      if (matchIndex == param_2) return entry;
      matchIndex++;
    }
  }
  entry += 4;
  goto check_entry;

no_match:
  K_ASSERT(false, 0x1f3);
  return NULL;
}
// FUN_001FBDF0 NONMATCHING


int func_001fbdf0(s32 start, s32 end, s32 amount, s32 category, s32 scaleMode)
{
    u32* flags;
    f32 value;
    f32 factor;
    s32 i;

    flags = (u32*)(iGpffffb7b8 + category * 0x1c);
    factor = fGpffff8070;
    if (scaleMode != 4)
    {
        if (scaleMode == 3)
            factor = 1.0f;
        else
        {
            factor = fGpffff83b4;
            if (scaleMode != 2)
            {
                factor = fGpffff83b0;
                if (scaleMode != 1)
                    K_ASSERT(false, 0x21e);
            }
        }
    }

    if ((*flags & 0x80) == 0)
    {
        i = end - start;
        if (i < 10)
        {
            if (i < -9)
                i = 0;
            else
                i += 10;
        }
        else
            i = 0x14;
        K_ASSERT(i >= 0 && i <= 0x14, 0x20b);
        value = (f32)amount * *(f32*)(iGpffffb7ac + i * 4);
    }
    else
        value = (f32)amount;

    i = (s32)(value * factor);
    if (i > 0xffff)
        i = 0xffff;
    return i;
}
// FUN_001FBFA0 NONMATCHING


int func_001fbfa0(int param_1,int param_2,int param_3,short param_4,int param_5,long param_6)



{

  u32 *puVar1;

  int iVar2;
  int level;

  float fVar4;

  float fVar5;

  float fVar3;


  

  puVar1 = (u32 *)(iGpffffb7b8 + param_5 * 0x1c);

  level = param_2 - param_1;

  if (level >= 10) {

    level = 0x14;

  }

  else {

    if (level < -9) {

      level = 0;

    }

    else {

      level = level + 10;

    }

  }

  if ((level < 0) || (0x14 < level)) {

    FUN_0019d3f0(0x684c28,0x20b);

  }

  fVar4 = *(float *)(iGpffffb7ac + level * 4);

  fVar5 = 0.0;

  if (param_4 == 0x229) {

    fVar5 = 0.25;

  }

  else if (param_4 == 0x22a) {

    fVar5 = 0.5;

  }

  else if (param_4 == 0x22b) {

    fVar5 = 1.0;

  }

  else {

    FUN_0019d3f0(0x684c28,0x243);

  }

  fVar3 = fGpffff8070;

  if (param_6 != 4) {
    if (param_6 == 3) {
      fVar3 = 1.0;
    } else {
      fVar3 = fGpffff83b4;
      if (param_6 != 2) {
        fVar3 = fGpffff83b0;
        if (param_6 != 1) {
          FUN_0019d3f0(0x684c28,0x24e);
        }
      }
    }
  }

  if ((*puVar1 & 0x80) == 0) {

    fVar4 = (float)param_3 * fVar4;

  }

  else {

    fVar4 = (float)param_3;

  }

  iVar2 = (int)(fVar3 * fVar4 * fVar5);

  if (0xffff < iVar2) {

    iVar2 = 0xffff;

  }

  return iVar2;

}
// FUN_001FC1F0


void func_001fc1f0(void)
{
    DatPersonaWork* persona;

    persona = datPersonaGetByPcId(1);
    datPersonaAddExp(persona, 0x18);
}
#pragma optimization_level 2
/* Removing this loses FUN_001fc230 (MATCH nd0 -> MISMATCH nd78) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001FC230


u8 func_001fc230(DatPersonaWork* persona)
{
    u16* skills;
    s32 count;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    s32 i;
    s32 j;

    skills = datPersonaGetSkills(persona);
    count = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    for (i = 0; i < indexCount; i++, current += 4)
    {
        if (current[1] == 1)
        {
            j = 0;
            while (j < count)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == count)
                break;
        }
    }
    return i < indexCount;
}
// FUN_001FC3C0
u32 func_001fc3c0(DatPersonaWork* persona)
{
    u16* skills;
    s32 count;
    s8* entry;
    s8* current;
    s32 firstIndex;
    s32 indexCount;
    register s32 active;
    register s32 limit;
    register s32 i;
    register s32 j;
    u32 result;

    skills = datPersonaGetSkills(persona);
    count = datPersonaCountValidSkills(persona);
    if (FUN_00175ca0(persona) != 0)
    {
        entry = (s8*)DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
        func_001fb4b0(entry, 0x20, persona->level,
                     99 - persona->level, &firstIndex, &indexCount);
    }
    else
    {
        entry = (s8*)DAT_007ce428 + persona->id * 0x46 + 6;
        func_001fb4b0(entry, 0x10,
                     persona->level -
                         DAT_007ce420[persona->id * 0xe + 3],
                     99 - persona->level, &firstIndex, &indexCount);
    }

    current = entry + firstIndex * 4;
    i = 0;
    limit = indexCount;
    active = 1;
    for (; i < limit; i++, current += 4)
    {
        if (current[1] == active)
        {
            j = 0;
            while (j < count)
            {
                if (*(u16*)(current + 2) == skills[j])
                    break;
                j++;
            }
            if (j == count)
                break;
        }
    }

    if (FUN_00175ca0(persona) != 0)
        result = *(u8*)current;
    else
        result = *(u8*)current + DAT_007ce420[persona->id * 0xe + 3];
    return result;
}
#pragma opt_loop_invariants off

// FUN_001FC590
u32 func_001fc590(u8* event, void* target)
{
    u32 result = 0;
    s32 damage;
    u32 criticalDamage;
    s32 boosted;
    u16 skill;

    skill = FUN_00308930();
    damage = FUN_00303130(skill, event, target, 1, 1, 1, 0, 1);
    if ((*(u16*)event & 4) == 0) goto branch_zero;
    damage = (s32)((f32)damage * 0.5f);
    criticalDamage = FUN_00488f30();
    if ((u32)(criticalDamage % 500) < 100)
        damage = 0;
    goto after_branch;
branch_zero:
    damage = (s32)((f32)damage * 1.5f);
    criticalDamage = FUN_00488f30();
    if ((u32)(criticalDamage % 500) < 100)
        damage *= 3;
after_branch:

    FUN_00300410(target, damage);
    if (datCalcIsDead(target, 0) != 0)
    {
        if ((*(u16*)event & 4) == 0)
            result = func_001fc870(event, target);
        datCalcClearBadStatus(target, 0x80);
        datCalcSetBadStatus(target, 0x80000);
    }
    return result;
}
// FUN_001FC720 NONMATCHING


u32 func_001fc720(u8* param_1)
{
  u32 uVar1;
  int in_v1_lo;
  int unaff_s0_lo;
  u32 unaff_s0_hi;
  long lVar2;
  u8 auStack_50[48];
  u8 auStack_20[24];
  int iStack_8;
  int iStack_4;

  if (in_v1_lo / 3 >= in_v1_lo) {
    if ((~*(u16*)param_1 & 4) == 0)
      FUN_0019d3f0(0x684d60, 0xaa);

    func_001fc980(param_1, (u16*)auStack_20, &iStack_4);
    func_001fcb30(param_1, (u32*)auStack_50, &iStack_8);
    lVar2 = (long)((unaff_s0_lo * 0x1e) / 100);
    if ((lVar2 < CONCAT44(unaff_s0_hi, unaff_s0_lo)) || (iStack_8 == 0)) {
      if (iStack_4 == 0) {
        if ((CONCAT44(unaff_s0_hi, unaff_s0_lo) < lVar2) ||
            (iStack_8 == 0)) {
          uVar1 = 0;
        }
        else {
          func_001fd350(param_1, (u32*)auStack_50, 1);
          uVar1 = 1;
        }
      }
      else {
        func_001fce20(param_1, (u16*)auStack_20, 1);
        uVar1 = 1;
      }
    }
    else {
      func_001fd350(param_1, (u32*)auStack_50, 1);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_001FC870 NONMATCHING

int func_001fc870(u8* event, void* target)
{
    s32 raw;
    s32 level;
    s32 delta;
    f32 amount;
    f32 scale;

    raw = FUN_0030bc50(target);
    if (raw < 0)
        amount = (f32)(((u32)raw >> 1) | (raw & 1)) * 2.0f;
    else
        amount = (f32)raw;

    level = FUN_00173300(*(u16*)(event + 2));
    delta = *(u8*)((u8*)target + 6) - (level & 0xff);
    if (delta < -10)
        delta = -10;
    if (delta > 10)
        delta = 10;

    scale = 1.0f;
    if (1.0f <= amount * *(f32*)(DAT_00684d70 + (delta + 10) * 4))
        scale = amount * *(f32*)(DAT_00684d70 + (delta + 10) * 4);
    FUN_001f9e90(*(u16*)(event + 2), (s32)scale);
    return (s32)scale;
}
// FUN_001FC980 NONMATCHING


void func_001fc980(u8* event, u16* result, s32* count)
{
    DatPersonaWork* persona;
    u16* skills;
    u32 skillCount;
    u16 skill;
    u32 i;
    u32 resultCount;
    s32 hp;
    u32 sp;
    u32 status;

    persona = datPersonaGetByPcId(*(u16*)(event + 2));
    skills = datPersonaGetSkills(persona);
    skillCount = datPersonaCountValidSkills(persona);
    resultCount = 0;
    for (i = 0; i < skillCount; i++)
    {
        skill = skills[i];
        if (FUN_00300af0(skill) == 0)
            continue;
        if (FUN_0017b660(*(s16*)(event + 2), skill) != 0)
            continue;
        if (skill != 0xc2 && skill != 0xc1 && skill != 0xc0)
            continue;

        FUN_0017be10(*(s16*)(event + 2), *(s16*)(event + 2), skill, 0,
                     &hp, &sp, &status);
        FUN_005225a8(0x684dd0, hp, sp, status);
        if (hp <= 0)
            continue;
        if (FUN_0017bb40(skill) != 0)
            continue;
        result[resultCount] = skill;
        resultCount++;
    }
    *count = resultCount;
    FUN_005225a8(0x684df0, resultCount);
}
// FUN_001FCB30 NONMATCHING
void func_001fcb30(u8* event, u32* result, s32* count)
{
    s16 skill;
    s32 i;
    u32 skillId;
    u16 pcId;
    s32 resultCount;
    u32 hp;
    u32 sp;
    u32 status;

    resultCount = 0;
    for (i = 0; i < 0xc; i++)
    {
        pcId = *(u16*)(event + 2);
        skill = FUN_001706c0(pcId, (u16)i);
        if (skill != 0)
        {
            skill = FUN_00170670(pcId, (u16)i);
            skillId = FUN_00170e90(skill);
            if (FUN_0017b4e0(*(u16*)(skillId + 8)) != 0)
            {
                FUN_0017be10(pcId, pcId, *(u16*)(skillId + 8), 1,
                             (s32*)&hp, &sp, &status);
                FUN_005225a8(0x684dd0, hp, sp, status);
                if (hp > 0 && (skill == 0xfa2 || skill == 0xfa1))
                {
                    result[resultCount] = FUN_00170670(pcId, (u16)i) & 0xffff;
                    resultCount++;
                }
            }
        }
    }
    *count = resultCount;
    FUN_005225a8(0x684e00, resultCount);
}


// FUN_001FCCC0
void func_001fccc0(u8* src, u8* dst, u32 skillId)
{
    u16 skill;
    u32 entry;
    s32 event_id;
    s32 i;
    s16 currentSkill;

    entry = FUN_00170e90((s16)skillId);
    skill = *(u16*)(entry + 8);
    if (FUN_0017b4e0(skill) == 0)
        FUN_0019d3f0((u32)(DAT_00684d60 - 0x10), 0x23a);

    FUN_0017b860(*(s16*)(dst + 2), *(s16*)(src + 2), skill, 1);
    for (i = 0; i < 0xc; i++) {
        event_id = *(s16*)(src + 2);
        currentSkill = FUN_001706c0(event_id, (s16)i);
        if (currentSkill != 0) {
            event_id = *(s16*)(src + 2);
            if (skillId == (FUN_00170670(event_id, (s16)i) & 0xffff))
                break;
        }
    }
    if (i >= 0xc)
        FUN_0019d3f0((u32)(DAT_00684d60 - 0x10), 0x249);
    event_id = *(s16*)(src + 2);
    currentSkill = FUN_001706c0(event_id, (s16)i);
    event_id = *(s16*)(src + 2);
    FUN_00170710(event_id, (s16)i, (s16)(currentSkill - 1));
}
#pragma optimization_level 3
// FUN_001FCE20 NONMATCHING


void func_001fce20(u8* param_1,u16 *param_2,int param_3)



{

  u16 uVar1;

  int iVar2;

  short sVar3;

  short sVar4;

  u32 uVar5;

  u32 uVar6;

  long lVar7;

  long lVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;
  int iVar13;


  u16 auStack_50 [8];

  u16 auStack_40 [8];

  int aiStack_30 [9];

  u8 auStack_c [4];

  u8 auStack_8 [4];

  int iStack_4;

  

  if (param_3 == 0) {

    FUN_0019d3f0(0x684d60,0x29b);

  }

  iVar13 = (int)param_1;

  if (param_3 == 1) {

    uVar1 = *param_2;

    lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),uVar1);

    if (lVar7 != 0) {

      FUN_0019d3f0(0x684d60,0x215);

    }

    sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),uVar1);

    FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0);

    sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),uVar1);

    if (sVar4 == 2) {

      sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));

      FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

    }

    else if (sVar4 == 1) {

      sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));

      FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

    }

  }

  else {

    uVar5 = FUN_002ffd70(param_1);

    uVar6 = FUN_002ffdf0(param_1);

    iVar10 = 0;

    iVar9 = 0;

    for (iVar11 = 0; iVar11 < param_3; iVar11 = iVar11 + 1) {

      uVar1 = param_2[iVar11];

      lVar7 = FUN_0017c070(uVar1);

      if (lVar7 == 0) {

        auStack_40[iVar10] = uVar1;

        iVar10 = iVar10 + 1;

      }

      else {

        auStack_50[iVar9] = uVar1;

        iVar9 = iVar9 + 1;

      }

    }

    for (iVar11 = 0; iVar11 < iVar10; iVar11 = iVar11 + 1) {

      FUN_0017be10(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),auStack_40[iVar11],0,

                   &iStack_4,auStack_8,auStack_c);

      aiStack_30[iVar11] = ((uVar5 & 0xffff) + iStack_4) - (uVar6 & 0xffff);

    }

    lVar7 = FUN_0051e0e0(aiStack_30[0]);

    iVar11 = 0;

    for (iVar12 = 1; iVar12 < iVar10; iVar12 = iVar12 + 1) {

      iVar2 = aiStack_30[iVar12];

      lVar8 = FUN_0051e0e0(iVar2);

      if (lVar8 < lVar7) {

        lVar7 = FUN_0051e0e0(iVar2);

        iVar11 = iVar12;

      }

    }

    uVar1 = auStack_40[iVar11];

    FUN_0017be10(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0,&iStack_4,auStack_8

                 ,auStack_c);

    iStack_4 = iStack_4 + (uVar5 & 0xffff);

    if (((int)(((uVar6 & 0xffff) * 0x50) / 100) < iStack_4) || (iVar9 == 0)) {

      lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),uVar1);

      if (lVar7 != 0) {

        FUN_0019d3f0(0x684d60,0x215);

      }

      sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),uVar1);

      FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),uVar1,0);

      sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),uVar1);

      if (sVar4 == 2) {

        sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));

        FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

      }

      else if (sVar4 == 1) {

        sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));

        FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

      }

    }

    else {

      lVar7 = FUN_0017b660(*(u16 *)(iVar13 + 2),auStack_50[0]);

      if (lVar7 != 0) {

        FUN_0019d3f0(0x684d60,0x215);

      }

      sVar3 = FUN_0017b5b0(*(u16 *)(iVar13 + 2),auStack_50[0]);

      FUN_0017b860(*(u16 *)(iVar13 + 2),*(u16 *)(iVar13 + 2),auStack_50[0],0);

      sVar4 = FUN_0017b500(*(u16 *)(iVar13 + 2),auStack_50[0]);

      if (sVar4 == 2) {

        sVar4 = FUN_0016c570(*(u16 *)(iVar13 + 2));

        FUN_0016cf90(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

      }

      else if (sVar4 == 1) {

        sVar4 = FUN_0016c4f0(*(u16 *)(iVar13 + 2));

        FUN_0016cf40(*(u16 *)(iVar13 + 2),sVar4 - sVar3);

      }

    }

  }

  return;

}
#pragma optimization_level 2
// FUN_001FD350 NONMATCHING


void func_001fd350(u8* param_1,u32 *param_2,int param_3)



{

  u16 uVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  s32 lVar7;

  s32 lVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u32 auStack_70 [8];

  u32 auStack_50 [8];

  int aiStack_30 [9];

  u8 auStack_c [4];

  u8 auStack_8 [4];

  int iStack_4;

  

  if (param_3 == 0) {

    FUN_0019d3f0(0x684d60,0x2fa);

  }

  if (param_3 == 1) {

    func_001fccc0(param_1,param_1,*param_2);

  }

  else {

    uVar4 = FUN_002ffd70(param_1);

    uVar5 = FUN_002ffdf0(param_1);

    iVar6 = 0;

    iVar9 = 0;

    for (iVar10 = 0; iVar10 < param_3; iVar10 = iVar10 + 1) {

      uVar2 = param_2[iVar10];

      iVar11 = FUN_00170e90((short)uVar2);

      lVar7 = FUN_0017c070(*(u16 *)(iVar11 + 8));

      if (lVar7 == 0) {

        auStack_50[iVar6] = uVar2;

        iVar6 = iVar6 + 1;

      }

      else {

        auStack_70[iVar9] = uVar2;

        iVar9 = iVar9 + 1;

      }

    }

    for (iVar10 = 0; iVar10 < iVar6; iVar10 = iVar10 + 1) {

      iVar11 = FUN_00170e90(*(u16 *)(param_2 + iVar10));

      uVar1 = *(u16 *)((int)param_1 + 2);

      FUN_0017be10(uVar1,uVar1,*(u16 *)(iVar11 + 8),1,&iStack_4,auStack_8,auStack_c);

      aiStack_30[iVar10] = ((uVar4 & 0xffff) + iStack_4) - (uVar5 & 0xffff);

    }

    lVar7 = FUN_0051e0e0(aiStack_30[0]);

    iVar10 = 0;

    for (iVar11 = 1; iVar11 < iVar6; iVar11 = iVar11 + 1) {

      iVar3 = aiStack_30[iVar11];

      lVar8 = FUN_0051e0e0(iVar3);

      if (lVar8 < lVar7) {

        lVar7 = FUN_0051e0e0(iVar3);

        iVar10 = iVar11;

      }

    }

    iVar6 = FUN_00170e90(*(u16 *)(param_2 + iVar10));

    uVar1 = *(u16 *)((int)param_1 + 2);

    FUN_0017be10(uVar1,uVar1,*(u16 *)(iVar6 + 8),1,&iStack_4,auStack_8,auStack_c);

    iStack_4 = iStack_4 + (uVar4 & 0xffff);

    if (((int)(((uVar5 & 0xffff) * 0x50) / 100) < iStack_4) || (iVar9 == 0)) {

      func_001fccc0(param_1,param_1,auStack_50[iVar10]);

    }

    else {

      func_001fccc0(param_1,param_1,auStack_70[0]);

    }

  }

  return;

}
