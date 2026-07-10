#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"

static u32* sBrpSeq; // puGpffffb6d0 / iGpffffb6d0

extern void func_0024b8a0(void);
extern void func_0024a7f0(void);
extern void func_0024abd0(void);
extern void func_0024ab10(s16);
extern void func_0024aa90(void);
extern void func_0024a870(void);
extern void func_0024ac90(void);
extern void func_0024adf0(void);
extern u32 func_0024b9e0(void);
extern u32 func_0024ac40(void);
extern void FUN_00279750(void);
extern void func_00279660(void);
extern void func_002796b0(void);
extern u32 func_00279700(void);
extern u32 func_002797a0(void);
extern void func_002797f0(void);
extern void func_00279890(u32 mode, u32 page);
extern void func_00279120(void);
extern void func_002791b0(u16 skillId);
extern void func_002792c0(void);
extern void func_00279330(u32 value);
extern void brpParamSetUnlockedSkillLevel(u32 level);
extern void brpParamSetUnlockedSkillIndex(u32 index);
extern void func_00279510(u32 slot, u8 value);
extern void func_00279580(u32 slot, u8 value);
extern void func_002795f0(u32 slot, u8 value);
extern u32 func_00276cc0(void);
extern void brLvpnlDisableDrawing(void);
extern void brLvpnlEnableDrawing(void);
extern void scrClearTextBox(s32, s32, s32, s32);
extern void FUN_003c77a0(void);
extern void FUN_003c7990(s32);
extern u32 FUN_003c7850(void);
extern void FUN_003c7650(s32);
extern u32 FUN_003c7610(void);
extern void FUN_003c7bc0(s32, u32);
extern void FUN_003c7430(s32);
extern void FUN_003c74e0(s32);
extern void FUN_003c7560(s32);
extern void FUN_0010a4e0(s32, s32, s32, s32);
extern u32 FUN_00173220(u16);
extern DatPersonaWork* FUN_001749a0(s16);
extern u32 FUN_00175410(void);
extern u32 FUN_001756f0(void);
extern void FUN_00174e20(u16);
extern DatPersonaWork* FUN_001761b0(DatPersonaWork*);
extern void FUN_00176100(DatPersonaWork*, u8*);
extern void FUN_00175ce0(DatPersonaWork*, u8*);
extern u16 FUN_00176a30(DatPersonaWork*);
extern u16* FUN_00173370(DatPersonaWork*);
extern void FUN_00176d10(DatPersonaWork*, DatPersonaWork*);
extern u32 FUN_00173580(DatPersonaWork*, u16);
extern u32 FUN_00171250(s16);
extern u32 FUN_00170760(s32, s16);
extern void FUN_00170860(s32, s16, u16);
extern void FUN_001830c0(void*);
extern void FUN_001768e0(DatPersonaWork*, s16);
extern void FUN_00176840(DatPersonaWork*, u16);
extern u32 FUN_0016f490(s32);
extern u16 FUN_001fba70(s16);
extern u16 FUN_001fb560(s16);
extern u32 FUN_00171110(s16, s32);
extern void FUN_001828d0(s16, void*);
extern u32 FUN_002347e0(void);
extern void FUN_003c72d0(void*);
extern void FUN_001fb4b0(u8*, s32, s32, s8, u8*, u8*);
extern u8* FUN_00275050(s32);
extern u32 FUN_002751e0(void);
extern s32 func_00274f00(void);
extern u32 func_002741f0(void);
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u32 DAT_007ce4ec;
extern u32 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16* DAT_007ce438;
extern const char* PTR_s_Strength_0068ed70[];
extern u32 gp0xffff97d0;
extern void FUN_00523ac8(void*, ...);
extern void FUN_005225a8(u32, ...);
extern s32 FUN_00488f30(void);
extern u8* FUN_003d5c90(void);
extern u8 FUN_0016c470(s32);
extern void func_00279840(void);
extern u32 uGpffff97ec;

static inline u8* brpSeqBytes(void)
{
    return (u8*)sBrpSeq;
}

static inline u32 brpSeqU32(u32 offset)
{
    return *(u32*)(brpSeqBytes() + offset);
}

static inline s32 brpSeqS32(u32 offset)
{
    return *(s32*)(brpSeqBytes() + offset);
}

static inline u16 brpSeqU16(u32 offset)
{
    return *(u16*)(brpSeqBytes() + offset);
}

static inline s16 brpSeqS16(u32 offset)
{
    return *(s16*)(brpSeqBytes() + offset);
}

static inline u8 brpSeqU8(u32 offset)
{
    return *(u8*)(brpSeqBytes() + offset);
}

static inline void brpSeqPutU32(u32 offset, u32 value)
{
    *(u32*)(brpSeqBytes() + offset) = value;
}

static inline void brpSeqPutU16(u32 offset, u16 value)
{
    *(u16*)(brpSeqBytes() + offset) = value;
}

static inline void brpSeqPutU8(u32 offset, u8 value)
{
    *(u8*)(brpSeqBytes() + offset) = value;
}
void func_00272810(void);
void func_00273800(void);
void func_00273a10(void);
void func_00273b30(void);
void func_00273d50(void);
void func_00273e90(void);
void func_00274030(void);
void func_00274100(void);
u32 func_002741f0(void);
void func_002743a0(void);
void func_002743e0(void*, s32*);
void func_00274590(void);
void func_00274c00(void);
u8 func_00274d40(void);
u16 func_00274d90(void);
u32 func_00274e10(void);
s32 func_00274e90(void);

extern u32 FUN_00108710(void);
extern void func_00276a80(void);
extern void func_00276b10(void);
extern void func_002798f0(void);
// FUN_002737a0
void brpSeq002737a0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((*sBrpSeq & 0x40) != 0) {
        func_0024b8a0();
    }
}

// FUN_00273980
void brpSeq00273980(void)
{
    u32* puVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    puVar1 = sBrpSeq;
    K_ASSERT((~*puVar1 & 2) != 0, 0x3a8);
    puVar1[4] = 6;
    *puVar1 &= 0xfffffffe;
}

// FUN_00273c00
void brpSeq00273c00(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    FUN_00279750();
    scrClearTextBox(1, 0, 8, 2);
    *(u32*)(iVar1 + 0x18) = 0;
    *(u32*)(iVar1 + 0x10) = 3;
}

// FUN_00273e10
void brpSeq00273e10(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    K_ASSERT(*(int*)(iVar1 + 0x74) == 9, 0x40e);
    FUN_003c7430(3);
    *(u32*)(iVar1 + 0x18) = 2;
}

// FUN_00273c70
void brpSeq00273c70(void)
{
    u32* puVar1;
    u32 uVar2;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    puVar1 = sBrpSeq;
    *puVar1 &= 0xffffffef;
    K_ASSERT((~puVar1[2] & 1) != 0, 0x3ef);
    uVar2 = FUN_00173220(*(u16*)((int)puVar1 + 4));
    FUN_003c7bc0(0, uVar2);
    FUN_003c7430(8);
    FUN_003c74e0(9);
    FUN_003c7560(0);
    scrClearTextBox(1, 0, 8, 4);
    puVar1[7] = 0;
    puVar1[4] = 5;
}
// FUN_00272330
void func_00272330(u32* work)
{
    K_ASSERT(sBrpSeq == NULL, 0xb7);
    *work = 0;
    sBrpSeq = work;
}

// FUN_00272380
void func_00272380(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((brpSeqU32(0) & 0x80) != 0)
        FUN_003c77a0();
    K_ASSERT(sBrpSeq != NULL, 0xc8);
    sBrpSeq = NULL;
}

// FUN_00272400 NONMATCHING
void func_00272400(u32* param)
{
    DatPersonaWork* persona;
    u16* skills;
    u16 skillCount;
    u32 i;
    u32 resultCount;
    u8* entry;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    K_ASSERT((brpSeqU32(0) & 1) == 0, 0xd6);
    K_ASSERT((brpSeqU32(0) & 2) == 0, 0xd7);
    K_ASSERT((brpSeqU32(0) & 0x10) == 0, 0xd8);
    K_ASSERT((brpSeqU32(0) & 0x20) == 0, 0xd9);

    brpSeqPutU32(0, brpSeqU32(0) & ~0x0cu);
    brpSeqPutU16(4, (u16)param[1]);
    brpSeqPutU32(8, param[0]);
    if ((brpSeqU32(0) & 0x80) == 0)
    {
        FUN_003c72d0((void*)FUN_002347e0());
        brpSeqPutU32(0, brpSeqU32(0) | 0x80);
    }

    persona = FUN_001749a0((s16)brpSeqU16(4));
    brpSeqPutU32(0x30, (u32)(uintptr_t)persona);
    K_ASSERT(FUN_001761b0(persona) != 0, 0xe8);
    FUN_00175ce0(persona, brpSeqBytes() + 0x38);
    brpSeqPutU32(0x34, (u32)(uintptr_t)(DAT_007ce428 +
                 (u32)brpSeqU16(4) * 0x46));

    skillCount = FUN_00176a30(persona);
    skills = FUN_00173370(persona);
    for (i = 0; i < skillCount; i++)
        brpSeqPutU16(0x60 + i * 2, skills[i]);
    brpSeqPutU32(0x74, skillCount);
    FUN_001fb4b0(brpSeqBytes() + 0x34, 0x10,
                 (s32)DAT_007ce420[brpSeqU16(4) * 0x0e + 4] -
                 (s32)DAT_007ce420[*(u16*)(brpSeqBytes() + 0x30) * 0x0e + 3],
                 (s8)brpSeqU8(0x38), brpSeqBytes() + 0x78,
                 brpSeqBytes() + 0x7c);
    brpSeqPutU32(0x1b0, 0);
    brpSeqPutU32(0x1b4, func_00274f00());
    FUN_00176100(persona, brpSeqBytes() + 0x38);
    if (func_002741f0() != 0)
        brpSeqPutU32(0, brpSeqU32(0) | 0x10);

    brpSeqPutU32(0x28, 0);
    for (i = 0; i < 5 && brpSeqU8(0x5a + i) == 0; i++)
        ;
    brpSeqPutU32(0x28, i);
    brpSeqPutU32(0x2c, 0);
    for (i = 0; i < 5; i++)
        if (brpSeqU8(0x5a + i) != 0)
            brpSeqPutU32(0x2c, i);

    resultCount = FUN_002751e0();
    brpSeqPutU32(0x1c0, resultCount);
    for (i = 0; i < resultCount; i++)
    {
        entry = FUN_00275050((s32)i);
        brpSeqPutU16(0x1c4 + i * 8, *(u16*)(entry + 2));
        brpSeqPutU32(0x1c8 + i * 8,
                     (u32)entry[0] +
                     DAT_007ce420[brpSeqU16(4) * 0x0e + 3]);
    }

    brpSeqPutU32(0x10, 0);
    if (brpSeqU32(0x28) < 5 && brpSeqU32(0x2c) < 5)
        func_00279660();
    func_00274c00();
    brpSeqPutU32(0, brpSeqU32(0) | 0x101);
}

// FUN_002727C0
u32 func_002727c0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    return brpSeqU32(0) & 1;
}
// FUN_00272810 NONMATCHING
void func_00272810(void)
{
    DatPersonaWork* persona;
    u32 state;
    u32 slot;
    u32 last;
    u32 index;
    u16 skillId;
    u32 selected;
    u32 done;
    u32 mode;
    u32 page;
    u32 pad;
    u8 text[256];

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((brpSeqU32(0) & 1) != 0)
    {
        state = brpSeqU32(0x10);
        switch (state)
        {
        case 0:
            if ((brpSeqU32(0) & 0x100) != 0 && func_00276cc0() == 0)
                brpSeqPutU32(0, brpSeqU32(0) & ~0x100u);
            break;
        case 1:
            if (brpSeqU32(0x14) == 0)
            {
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    if (brpSeqU32(0x28) < 5 && brpSeqU32(0x2c) < 5)
                    {
                        FUN_003c7650(0);
                        func_00273b30();
                    }
                    else
                    {
                        FUN_003c7650(1);
                        brpSeqPutU32(0x10, 2);
                        func_00273800();
                    }
                }
            }
            break;
        case 2:
            if (brpSeqU32(0x24) == 1)
            {
                if (func_00279700() == 0)
                    func_00273800();
            }
            else if (brpSeqU32(0x24) == 0)
            {
                slot = brpSeqU32(0x28);
                last = brpSeqU32(0x2c);
                FUN_003c7990(slot == last);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(slot == last);
                    while (slot < last && slot < 4)
                    {
                        slot++;
                        if (brpSeqU8(0x5b + slot) != 0)
                            break;
                    }
                    brpSeqPutU32(0x28, slot);
                    if (slot < last)
                    {
                        FUN_00523ac8(text, &gp0xffff97d0,
                                     brpSeqU8(0x5b + slot));
                        FUN_003c7bc0(0, (u32)(uintptr_t)PTR_s_Strength_0068ed70[slot]);
                        FUN_003c7bc0(1, (u32)(uintptr_t)text);
                        FUN_003c7430(1);
                        FUN_0010a4e0(1, 0, 8, 1);
                    }
                    else
                    {
                        func_002796b0();
                        brpSeqPutU32(0x24, 1);
                    }
                }
            }
            break;
        case 3:
            switch (brpSeqU32(0x18))
            {
            case 0:
                if (func_002797a0() == 0)
                {
                    skillId = brpSeqU16(0x1c4 + brpSeqU32(0x1b0) * 8);
                    brpSeqPutU16(0x60 + brpSeqU32(0x74) * 2, skillId);
                    brpSeqPutU32(0x74, brpSeqU32(0x74) + 1);
                    FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                    FUN_003c7bc0(1, DAT_007ce4ec + skillId * 0x13);
                    FUN_003c7430(2);
                    brpSeqPutU32(0x18, 1);
                }
                break;
            case 1:
                selected = brpSeqU32(0x74);
                FUN_003c7990(selected < 9);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(selected < 9);
                    if (selected < 9)
                        func_00274100();
                    else
                        func_00273e10();
                }
                break;
            case 2:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    func_002797f0();
                    brpSeqPutU32(0x1b8, 0);
                    brpSeqPutU32(0x1bc, 0);
                    func_00279890(0, 0);
                    brpSeqPutU32(0x18, 3);
                }
                break;
            case 3:
                pad = DAT_007e0952;
                if ((DAT_007e094e & 0x40) == 0)
                {
                    mode = brpSeqU32(0x1b8);
                    page = brpSeqU32(0x1bc);
                    if (mode < 2 && (pad & 0x4000) != 0)
                        page = page < 3 ? page + 1 : 0;
                    else if (mode < 2 && (pad & 0x1000) != 0)
                        page = page != 0 ? page - 1 : 3;
                    else if ((pad & 0x8000) != 0)
                        mode = mode != 0 ? mode - 1 : 2;
                    else if ((pad & 0x2000) != 0)
                        mode = mode < 2 ? mode + 1 : 0;
                    brpSeqPutU32(0x1b8, mode);
                    brpSeqPutU32(0x1bc, page);
                    if ((pad & 0xf000) != 0)
                    {
                        func_00279890(mode, page);
                        FUN_0010a4e0(0, 0, 0, 0);
                    }
                    index = mode == 2 ? 8 : page + mode * 4;
                    skillId = brpSeqU16(0x60 + index * 2);
                    uGpffff97ec = skillId == 0 ? (u32)-1 : skillId;
                }
                else
                {
                    index = brpSeqU32(0x1b8) == 2 ?
                            8 : brpSeqU32(0x1bc) +
                            brpSeqU32(0x1b8) * 4;
                    skillId = brpSeqU16(0x60 + index * 2);
                    FUN_003c7bc0(0, DAT_007ce4ec + skillId * 0x13);
                    FUN_003c7430(4);
                    FUN_003c74e0(5);
                    FUN_0010a4e0(0, 0, 0, 1);
                    brpSeqPutU32(0x18, 4);
                }
                break;
            case 4:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0 && FUN_003c7610() == 0)
                {
                    FUN_003c7650(1);
                    index = brpSeqU32(0x1b8) == 2 ?
                            8 : brpSeqU32(0x1bc) +
                            brpSeqU32(0x1b8) * 4;
                    skillId = brpSeqU16(0x60 + index * 2);
                    for (slot = index; slot + 1 < brpSeqU32(0x74); slot++)
                        brpSeqPutU16(0x60 + slot * 2,
                                     brpSeqU16(0x62 + slot * 2));
                    brpSeqPutU32(0x74, brpSeqU32(0x74) - 1);
                    FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                    FUN_003c7bc0(1, DAT_007ce4ec + skillId * 0x13);
                    FUN_003c7430(index == 8 ? 6 : 7);
                    brpSeqPutU32(0x18, 5);
                }
                break;
            case 5:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    func_00274100();
                }
                break;
            }
            break;
        case 4:
            FUN_003c7990(1);
            if (FUN_003c7850() == 0)
            {
                FUN_003c7650(1);
                if (brpSeqU32(0x20) == 1)
                {
                    func_00273800();
                }
                else if (FUN_003c7610() == 1)
                {
                    FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                    FUN_003c7430(0xe);
                    brpSeqPutU32(0x20, 1);
                }
                else
                {
                    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
                    FUN_003c7bc0(0, DAT_007ce4ec +
                                  brpSeqU16(0xa2) * 0x13);
                    FUN_003c7bc0(1, DAT_007ce4ec +
                                  brpSeqU16(0xa2) * 0x13);
                    FUN_003c7430(brpSeqU32(0x9c) == 1 ? 0x10 : 0xf);
                    FUN_0010a4e0(1, 0, 8, 3);
                    FUN_001768e0(persona, brpSeqS16(0xa0));
                    FUN_00176840(persona, brpSeqU16(0xa2));
                    brpSeqPutU32(0x20, 1);
                }
            }
            break;
        case 5:
            switch (brpSeqU32(0x1c))
            {
            case 0:
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(0);
                    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
                    if (FUN_003c7610() == 1)
                    {
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7430(10);
                        brpSeqPutU32(0x1c, 1);
                    }
                    else
                    {
                        brpSeqPutU32(0x1c, 3);
                        if ((persona->flags & 8) != 0)
                        {
                            brpSeqPutU16(0x84, (u16)FUN_001fba70(brpSeqS16(4)));
                            brpSeqPutU32(0xa4, 1);
                            brpSeqPutU32(0, brpSeqU32(0) | 8);
                            FUN_0024a7f0();
                        }
                        else
                        {
                            brpSeqPutU16(0x80, FUN_001fb560(brpSeqS16(4)));
                            brpSeqPutU32(0xa4, 0);
                            brpSeqPutU32(0, brpSeqU32(0) | 4);
                            FUN_0024a7f0();
                        }
                        FUN_003c77a0();
                        persona->flags &= (u16)~0x0cu;
                    }
                }
                break;
            case 1:
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(0);
                    func_00273800();
                }
                break;
            case 2:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    FUN_0024aa90();
                    brpSeqPutU32(0x1c, 5);
                }
                break;
            case 3:
                if (func_0024ac40() == 0 && FUN_00108710() != 0)
                {
                    func_00276a80();
                    func_002798f0();
                    brLvpnlDisableDrawing();
                    FUN_0024a870();
                    brpSeqPutU32(0x1c, 4);
                }
                break;
            case 4:
                if (func_0024b9e0() == 0)
                {
                    FUN_003c72d0((void*)FUN_002347e0());
                    if (brpSeqU32(0xa4) == 1)
                    {
                        if (FUN_00171250(brpSeqS16(0x84)) == 4)
                            FUN_003c7bc0(1, FUN_00171110(brpSeqS16(0x84), 0));
                        else
                        {
                            FUN_001828d0(brpSeqS16(0x84), brpSeqBytes() + 0x88);
                            FUN_003c7bc0(1,
                                         FUN_00171110(brpSeqS16(0x84),
                                                      brpSeqU8(0x90)));
                        }
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7430(0xc);
                    }
                    else
                    {
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7bc0(1, FUN_00173220(brpSeqU16(0x80)));
                        FUN_003c7430(0xb);
                    }
                    brpSeqPutU32(0x1c, 2);
                }
                break;
            case 5:
                if (func_0024b9e0() == 0)
                {
                    FUN_0024ac90();
                    brpSeqPutU32(0, brpSeqU32(0) & ~0x40u);
                    func_002798f0();
                    func_00276b10();
                    brLvpnlEnableDrawing();
                    brpSeqPutU32(0x1c, 6);
                }
                break;
            case 6:
                if (FUN_00108710() != 0)
                    func_00273800();
                break;
            }
            break;
        default:
            break;
        }
        if ((brpSeqU32(0) & 0x40) != 0)
            func_0024adf0();
    }
}
// FUN_00273800 NONMATCHING
void func_00273800(void)
{
    u32 state;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    state = brpSeqU32(0x10);
    for (;;)
    {
        if (state == 5)
        {
            func_00273a10();
            brpSeqPutU32(0x10, 6);
            func_00273980();
            return;
        }
        if (state == 4)
            break;
        if (state == 3)
        {
            func_002743a0();
            func_00274590();
            if ((brpSeqU32(0) & 0x20) != 0)
            {
                func_00273d50();
                return;
            }
            state = 4;
        }
        else if (state == 2)
        {
            if (brpSeqU32(0x1b4) != 0)
            {
                func_00273c00();
                return;
            }
            state = 3;
        }
        else
        {
            K_ASSERT(0, 0x39b);
            K_ASSERT(0, 0x39f);
            return;
        }
    }
    if ((brpSeqU32(0) & 0x10) == 0)
        state = 5;
    else
    {
        func_00273c70();
        return;
    }
    brpSeqPutU32(0x10, state);
}

// FUN_00273A10 NONMATCHING
void func_00273a10(void)
{
    DatPersonaWork* persona;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    if ((brpSeqU32(0) & 8) != 0)
    {
        if (FUN_00171250(brpSeqS16(0x84)) == 4)
        {
            u32 exp = FUN_00170760(1, brpSeqS16(0x84)) + 1;
            if (exp > 99)
                exp = 99;
            FUN_00170860(1, brpSeqS16(0x84), (u16)exp);
        }
        else
            FUN_001830c0(brpSeqBytes() + 0x88);
        brpSeqPutU32(0, brpSeqU32(0) & ~8u);
    }
    if ((brpSeqU32(0) & 4) != 0)
        func_00274030();
    (void)persona;
}

// FUN_00273B30 NONMATCHING
void func_00273b30(void)
{
    u8 text[256];
    u32 slot;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    slot = brpSeqU32(0x28);
    FUN_00523ac8(text, &gp0xffff97d0, brpSeqU8(0x5a + slot));
    FUN_003c7bc0(0, (u32)(uintptr_t)PTR_s_Strength_0068ed70[slot]);
    FUN_003c7bc0(1, (u32)(uintptr_t)text);
    FUN_003c7430(1);
    FUN_0010a4e0(1, 0, 8, 1);
    brpSeqPutU32(0x24, 0);
    brpSeqPutU32(0x10, 2);
}

// FUN_00273D50 NONMATCHING
void func_00273d50(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
    FUN_003c7bc0(1, DAT_007ce4ec + brpSeqU16(0xa0) * 0x13);
    FUN_003c7430(0xd);
    FUN_003c74e0(9);
    brpSeqPutU32(0, brpSeqU32(0) & ~0x20u);
    brpSeqPutU32(0x20, 0);
    brpSeqPutU32(0x10, 4);
}

// FUN_00273E90 NONMATCHING
void func_00273e90(void)
{
    DatPersonaWork* persona;
    u16 current[8];
    u16* skills;
    u32 count;
    u32 i;
    u32 j;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    count = FUN_00176a30(persona);
    skills = FUN_00173370(persona);
    for (i = 0; i < count && i < ARRAY_SIZE(current); i++)
        current[i] = skills[i];
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < brpSeqU32(0x74) &&
             brpSeqU16(0x60 + j * 2) != current[i]; j++)
            ;
        if (j >= brpSeqU32(0x74))
            FUN_001768e0(persona, current[i]);
    }
    for (i = 0; i < brpSeqU32(0x74); i++)
    {
        for (j = 0; j < count && brpSeqU16(0x60 + i * 2) != current[j]; j++)
            ;
        if (j >= count)
            FUN_00176840(persona, brpSeqU16(0x60 + i * 2));
    }
}
// FUN_00274030 NONMATCHING
void func_00274030(void)
{
    u16 current;
    u16 maximum;
    DatPersonaWork* currentPersona;
    DatPersonaWork* targetPersona;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    current = (u16)FUN_001756f0();
    maximum = (u16)FUN_00175410();
    K_ASSERT(maximum > current, 0x447);
    FUN_00174e20(brpSeqU16(0x80));
    currentPersona = FUN_001749a0(brpSeqS16(4));
    targetPersona = FUN_001749a0(brpSeqS16(0x80));
    FUN_00176d10(targetPersona, currentPersona);
    brpSeqPutU32(0, brpSeqU32(0) & ~4u);
}

// FUN_00274100 NONMATCHING
void func_00274100(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    brpSeqPutU32(0x1b0, brpSeqU32(0x1b0) + 1);
    func_00279120();
    func_002792c0();
    func_00274c00();
    func_00279840();
    if (brpSeqU32(0x1b0) < brpSeqU32(0x1b4))
    {
        func_00279750();
        FUN_0010a4e0(1, 0, 8, 2);
        brpSeqPutU32(0x18, 0);
        brpSeqPutU32(0x10, 3);
    }
    else
        func_00273800();
}

// FUN_002741F0 NONMATCHING
u32 func_002741f0(void)
{
    DatPersonaWork* persona;
    u16* skills;
    u32 skillCount;
    u32 i;
    u32 j;
    u8* growth;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    skills = FUN_00173370(persona);
    skillCount = FUN_00176a30(persona);
    if ((brpSeqU32(8) & 1) != 0 ||
        (*(u16*)(brpSeqBytes() + 0x30) & 4) != 0)
        return 0;
    if ((*(u16*)(brpSeqBytes() + 0x30) & 8) == 0)
    {
        if (FUN_0016f490(1) == 300)
            return 0;
    }
    else
    {
        K_ASSERT(FUN_001756f0() <= FUN_00175410(), 0x474);
        if (FUN_001756f0() == FUN_00175410())
            return 0;
    }
    growth = brpSeqBytes() + 0x34;
    for (i = 0; i < 0x10; i++)
    {
        u8 kind = growth[i * 4 + 7];
        if (kind == 0)
            return 0;
        if (growth[i * 4 + 6] <=
            DAT_007ce420[brpSeqU16(4) * 0x0e + 4] -
            DAT_007ce420[brpSeqU16(4) * 0x0e + 3] &&
            kind == 4)
            return 1;
        for (j = 0; j < skillCount && skills[j] != *(u16*)(growth + i * 4 + 8); j++)
            ;
    }
    return 0;
}

// FUN_002743A0
void func_002743a0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    func_00273e90();
}

// FUN_002743E0 NONMATCHING
void func_002743e0(void* destination, s32* count)
{
    DatPersonaWork* persona;
    u16* skills;
    u32 skillCount;
    u32 i;
    u32 outCount;
    u8* growth;
    u8 kind;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    skills = FUN_00173370(persona);
    skillCount = FUN_00176a30(persona);
    outCount = 0;
    for (i = 0; i < skillCount; i++)
        ((u16*)destination)[outCount++] = skills[i];
    growth = brpSeqBytes() + 0x34;
    for (i = brpSeqU32(0x78); i < 0x10; i++)
    {
        growth = brpSeqBytes() + 0x34 + i * 4;
        kind = growth[7];
        if (kind == 3)
            K_ASSERT(0, 0x4cc);
        else if (kind == 1)
        {
            K_ASSERT(outCount < 16, 0x4c4);
            ((u16*)destination)[outCount++] = *(u16*)(growth + 8);
        }
        else if (kind != 4 && kind != 0)
            K_ASSERT(kind != 2, 0x4bc);
    }
    *count = (s32)outCount;
}
// FUN_00274590 NONMATCHING
void func_00274590(void)
{
    DatPersonaWork* persona;
    u16* skills;
    u16 excluded[16];
    u16 candidates[16];
    s32 excludedCount;
    u32 skillCount;
    u32 candidateCount;
    u32 i;
    u32 j;
    u32 random;
    u32 chosen;
    u8* rankMap;
    u8 level;
    u8 desiredRank;
    u8 variant;
    u8* pair;
    u16 first;
    u16 second;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    skills = FUN_00173370(persona);
    skillCount = FUN_00176a30(persona);
    func_002743e0(excluded, &excludedCount);
    rankMap = FUN_003d5c90();
    level = FUN_0016c470(1);
    FUN_005225a8(0x68edc0);
    FUN_005225a8(0x68ede0, level);
    FUN_005225a8(0x68edf0, level, 10);
    if (level < 0xb)
    {
        FUN_005225a8(0x68ee00);
        return;
    }

    random = (u32)FUN_00488f30();
    if (random % 100 >= 12)
    {
        FUN_005225a8(0x68ee00);
        return;
    }
    variant = (u8)FUN_00488f30();
    candidateCount = 0;
    for (pair = (u8*)DAT_007ce438;
         *(u16*)pair != 0 || *(u16*)(pair + 2) != 0; pair += 4)
    {
        first = *(u16*)pair;
        second = *(u16*)(pair + 2);
        for (i = 0; i < skillCount && skills[i] != first; i++)
            ;
        if (i < skillCount)
        {
            for (j = 0; j < (u32)excludedCount && excluded[j] != second; j++)
                ;
            if (j == (u32)excludedCount && candidateCount < ARRAY_SIZE(candidates))
                candidates[candidateCount++] = first;
        }
    }

    if (candidateCount == 0)
    {
        FUN_005225a8(0x68ee00);
        return;
    }

    chosen = candidates[(u32)FUN_00488f30() % candidateCount];
    desiredRank = rankMap[chosen] + 1;
    candidateCount = 0;
    for (i = 0; i < 0x270; i++)
    {
        if (rankMap[i] == desiredRank)
        {
            for (j = 0; j < (u32)excludedCount && excluded[j] != i; j++)
                ;
            if (j == (u32)excludedCount && candidateCount < ARRAY_SIZE(candidates))
                candidates[candidateCount++] = (u16)i;
        }
    }
    if (candidateCount == 0)
    {
        FUN_005225a8(0x68ee00);
        return;
    }

    chosen = candidates[(u32)FUN_00488f30() % candidateCount];
    brpSeqPutU16(0xa0, (u16)chosen);
    brpSeqPutU16(0xa2, (u16)(rankMap[chosen]));
    brpSeqPutU32(0x9c, variant != 0 ? 1 : 0);
    brpSeqPutU32(0, brpSeqU32(0) | 0x20);
}

// FUN_00274C00 NONMATCHING
void func_00274c00(void)
{
    DatPersonaWork* persona;
    u32 i;
    u16 skill;
    u8 value;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    for (i = 0; i < brpSeqU32(0x74); i++)
        func_002791b0(brpSeqU16(0x60 + i * 2));
    if (func_00274d40() != 0)
    {
        func_00279330(func_00274d90());
        brpParamSetUnlockedSkillLevel(func_00274e10());
    }
    brpParamSetUnlockedSkillIndex((u32)func_00274e90());
    for (i = 0; i < 5; i++)
    {
        skill = (u16)FUN_00173580(persona, (u16)i);
        value = (u8)skill;
        func_00279510(i, value);
        func_00279580(i, value);
        func_002795f0(i, brpSeqU8(0x5a + i));
    }
}

// FUN_00274D40
u8 func_00274d40(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    return brpSeqS32(0x1b0) < brpSeqS32(0x1c0);
}

// FUN_00274D90 NONMATCHING
u16 func_00274d90(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    K_ASSERT(brpSeqU32(0x1c0) > brpSeqU32(0x1b0), 0x5de);
    return brpSeqU16(0x1c4 + brpSeqU32(0x1b0) * 8);
}

// FUN_00274E10 NONMATCHING
u32 func_00274e10(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    K_ASSERT(brpSeqU32(0x1c0) > brpSeqU32(0x1b0), 0x5e6);
    return brpSeqU32(0x1c8 + brpSeqU32(0x1b0) * 8);
}

// FUN_00274E90
s32 func_00274e90(void)
{
    s32 remaining;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    remaining = (s32)brpSeqU32(0x1c0) - (s32)brpSeqU32(0x1b0);
    return remaining < 2 ? 0 : remaining - 1;
}

// FUN_00274F00 NONMATCHING
s32 func_00274f00(void)
{
    DatPersonaWork* persona;
    u16* skills;
    u32 skillCount;
    u32 i;
    u32 j;
    u32 count;
    u8 kind;
    u8* growth;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
    skills = FUN_00173370(persona);
    skillCount = FUN_00176a30(persona);
    count = 0;
    growth = brpSeqBytes() + 0x34;
    for (i = 0; i < brpSeqU32(0x7c); i++)
    {
        kind = growth[(brpSeqU32(0x78) + i) * 4 + 7];
        if (kind == 0)
            break;
        if (kind == 1)
        {
            u16 skill = *(u16*)(growth + (brpSeqU32(0x78) + i) * 4 + 8);
            for (j = 0; j < skillCount && skills[j] != skill; j++)
                ;
            if (j == skillCount)
                count++;
        }
        else if (kind != 4)
            K_ASSERT(0, 0x612);
    }
    return (s32)count;
}
