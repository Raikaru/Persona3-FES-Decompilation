#include "Kernel/h_memcard.h"
#include "sce/libmc2.h"
#include "sce/libdbc.h"

static SceMc2SocketParam sSocketParam; // 00846eb0
static u_long128 sAddr[SCE_MC2_DMA_BUFFER_MAX] __attribute__((aligned(64))); // 00846b80

static s32 sMemcardAsync;        // 007ce00c
static s32 sMemcardAbort;        // 007ce01c
static s32 sMemcardSeqMode;      // 007ce03c
static s32 sSocketNo;            // 007ce024
static s32 sMemcardMode;         // 007ce038
static s32 sMemcardFile;         // 007ce034
static void* sMemcardBuffer;     // 007ce028
static s32 sMemcardBufferSize;   // 007ce030
static s32* sMemcardResult;      // 007ce02c

/* The memory-card UI and allocator entry points are function tables in the
 * retail image.  Keep these as opaque calls: their concrete implementations
 * live in the SDK/game support objects. */
extern s32 FUN_00514900();
extern s32 FUN_0017d800();
extern s32 FUN_0016f190();
extern s32 FUN_001021c0();
extern s32 FUN_005136f8();
extern s32 FUN_005137b8();
extern s32 FUN_00513968();
extern s32 FUN_00513cc8();
extern s32 FUN_00513de8();
extern s32 FUN_00513598();
extern s64 FUN_005140f8();
extern s32 FUN_005225a8();
extern s32 FUN_00523ac8();
extern s32 FUN_00524270();
extern s32 FUN_00521250();
extern s32 FUN_00521408();
extern s32 FUN_00523e68();
extern u32 D_00960178[];
extern u32 jtbl_0096017C[];
extern s32 D_00846EA0[];
extern s32 D_00846EA4[];
extern s32 D_00846EA8[];
extern u8 D_00846C80[];
extern u32 D_00846C90[];
extern u8 D_00846DA0[];
extern u8 D_005E4810[];
extern u8 D_005E4C10[];
extern u8 D_005E4BB0[];
extern u8 D_005E48A0[];
extern u8 D_005E49D0[];
extern u8 D_005E4870[];
extern u8 D_005E49A0[];
extern u8 D_005E4840[];
extern u8 D_005E4BE0[];
extern u8 D_005E4BF8[];
extern u8 D_005E4BC8[];
extern u8 D_005E46C0[];
extern u8 D_005E4700[];
extern u8 D_005E4730[];
extern u8 D_005E4760[];
extern u8 D_005E4780[];
extern u8 D_005E4784[];
extern u8 D_005E4788[];
extern u8 D_005E4790[];
extern u8 D_005E4810[];
extern u8 D_005E4830[];
extern u8 D_005E4840[];
extern u8 D_005E4870[];
extern u8 D_005E48A0[];
extern u8 D_005E48C8[];
extern u8 D_005E48E0[];
extern u8 D_005E4900[];
extern u8 D_005E4920[];
extern u8 D_005E4940[];
extern u8 D_005E4960[];
extern u8 D_005E4980[];
extern u8 D_005E49A0[];
extern u8 D_005E49D0[];
extern u8 D_005E4A00[];
extern u8 D_005E4A20[];
extern u8 D_005E4A40[];
extern u8 D_005E4A60[];
extern u8 D_005E4A80[];
extern u8 D_005E4AA0[];
extern u8 D_005E4AC0[];
extern u8 D_005E4AE0[];
extern u8 D_005E4B00[];
extern u8 D_005E4B20[];
extern u8 D_005E4B40[];
extern u8 D_005E4B50[];
extern u8 D_005E4B80[];
extern u8 D_00846780[];
extern u8 D_00846790[];
extern u8 D_00846800[];
extern u8 D_00846830[];
extern u8 D_00846840[];
extern u8 D_00846884[];
extern u8 D_008468C4[];
extern u8 D_00846904[];
extern u16 D_00846786;
extern s32 D_0084678C;

#define MEMCARD_ALLOC(size, flags) \
    (*(void* (**)(u32, u32))D_00960178)((size), (flags))
#define MEMCARD_FREE(memory) \
    (*(void (**)(void*))jtbl_0096017C)((memory))

/* The save-slot scanner has a separate work area in the original small-data
 * section.  These names describe the state represented by the GP-relative
 * fields used by the retail routines. */
static s32 sSlotScanMode;    // 007ce010
static s32 sSlotScanResult;  // 007ce014
static s32 sSlotScanDone;    // 007ce018
static u32* sSlotScanTable;  // 007ce020

// FUN_0018f100
void H_Memcard_Init()
{
    sceDbcInit();
    sceMc2Init(0);

    sSocketParam.option = SCE_MC2_TYPE_PS2;
    sSocketParam.port = SCE_MC2_PORT_1;
    sSocketParam.slot = 0;

    sSocketNo = sceMc2CreateSocket(&sSocketParam, sAddr);
}

// FUN_0018f170
void func_0018f170(s32 file, void* buffer, s32 size)
{
    sMemcardMode = 0;
    sMemcardAsync = 0;
    sMemcardFile = file;
    sMemcardBuffer = buffer;
    sMemcardBufferSize = size;
    sMemcardSeqMode = 0;
}

// FUN_0018f190 Poll the memory-card socket and normalize errors.
s32 func_0018f190(s32* mode, u32* result, s32* error)
{
    s32 status;

    status = FUN_00514900();
    if (status != 1)
    {
        if (status != 0)
        {
            if (status == -1)
            {
                goto minus_return;
            }
            return status;

minus_return:
            return -1;
        }
        return 0;
    }

    switch (*mode)
    {
        case 5:
        case 6:
            if ((s32)*result < 0)
            {
                *error = 0;
                if ((s32)*result < 0)
                {
                    *result &= 0xffff;
                }
            }
            else
            {
                *error = 1;
            }
            break;

        default:
            if (*result == 0)
            {
                *error = 1;
            }
            if ((s32)*result < 0)
            {
                *result &= 0xffff;
            }
            break;
    }

    return 1;
}

// FUN_0018f2a0
void func_0018f2a0(void)
{
    sMemcardSeqMode = 9;
}

// FUN_0018f2b0
void func_0018f2b0(void)
{
    sMemcardSeqMode = 4;
}

// FUN_0018f2c0 NONMATCHING. Advance the save/load card-dialog state machine.
s32 func_0018f2c0(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    s32 size;
    s32 value;

    FUN_005225a8(D_005E4810, sMemcardSeqMode);

    switch (sMemcardSeqMode)
    {
        case 0:
            cardMode = 0;
            cardCode = 0;
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
            {
                FUN_005136f8(sSocketNo, D_00846EA0);
                sMemcardSeqMode = 1;
            }
            break;

        case 1:
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
            {
                if (cardError == 0)
                {
                    switch (cardCode)
                    {
                        case 0x9003:
                            return -3;
                        case 0x6f:
                            return -5;
                        case 0x13:
                            return -5;
                        case 0x9001:
                            return -7;
                        case 0x2f:
                            sMemcardSeqMode = 3;
                            return 2;
                        default:
                            FUN_005225a8(D_005E4830);
                            break;
                    }
                }
                if (*D_00846EA0 != 2)
                {
                    return -1;
                }
                if (*D_00846EA4 == 0)
                {
                    sMemcardSeqMode = 3;
                    return 2;
                }
                if (sMemcardAsync != 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
                }
                else
                {
                    if (FUN_0017d800() != 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
                    }
                }
                if ((value = FUN_005137b8(sSocketNo, D_00846DA0, D_00846C80)) != 0)
                {
                    FUN_005225a8(D_005E4830, value);
                }
                sMemcardSeqMode = 2;
            }
            break;


        case 3:
        {
            s32 status;
            status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
            if (status == -1)
            {
                goto state3_error;
            }
            switch (status)
            {
                case 1:
                    if (cardError == 0)
                    {
                        switch (cardCode)
                        {
                            case 0x9003:
                                return -3;
                            case 0x6f:
                                return -3;
                            case 0x13:
                                return -3;
                            case 0x9001:
                                return -3;
                            case 0x2f:
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    goto state3_done;
            }
            goto state3_done;

state3_error:
            FUN_005136f8(sSocketNo, D_00846EA0);
state3_done:
            return 2;
        }
        case 4:
        {
            s32 status;
            status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
            switch (status)
            {
                case 1:
                    if (cardCode != 0)
                    {
                        goto state4_done;
                    }
                    if (cardCode == 0x2f)
                    {
                        goto state4_done;
                    }
                    switch (cardCode)
                    {
                        case 0x9003:
                        case 0x6f:
                        case 0x13:
                        case 0x9001:
                            goto state4_return3;
                        default:
                            break;
                    }
                    goto state4_done;
                case -1:
                    goto state4_error;
                default:
                    goto state4_done;
            }
state4_return3:
            return -3;
state4_error:
            FUN_00513598(sSocketNo);
            sMemcardSeqMode = 5;
state4_done:
            break;
        }
        case 5:
        {
            s32 status;
            status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
            switch (status)
            {
                case 1:
                    switch (cardError)
                    {
                        case 0:
                            goto state5_return3;
                        default:
                            sMemcardSeqMode = 6;
                            return 4;
                    }
                case -1:
                    goto state5_error;
                default:
                    goto state5_done;
            }
state5_return3:
            return -3;
state5_error:
            sMemcardSeqMode = 6;
state5_done:
            break;
        }
        case 2:
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
            {
                if (cardError == 0)
                {
                    switch (cardCode)
                    {
                        case 0x9003:
                            return -5;
                        case 0x6f:
                            return -5;
                        case 0x16:
                            return -5;
                        case 0x13:
                            return -5;
                        case 2:
                            sMemcardSeqMode = 6;
                            break;
                        default:
                            FUN_005225a8(D_005E48C8);
                            sMemcardSeqMode = 6;
                            return -7;
                    }
                }
                else
                {
                    sMemcardSeqMode = 8;
                    return 1;
                }
            }
            break;

        case 8:
        {
            s32 status;
            status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
            switch (status)
            {
                case 1:
                    if (cardError == 0)
                    {
                        switch (cardCode)
                        {
                            case 0x9003:
                                return -3;
                            case 0x6f:
                                return -3;
                            case 0x13:
                                return -3;
                            case 0x9001:
                                return -3;
                            case 0x2f:
                                return -3;
                            default:
                                break;
                        }
                    }
                    break;
                case -1:
                    FUN_005136f8(sSocketNo, D_00846EA0);
                    break;
                default:
                    break;
            }
            return 1;

        }
        case 9:
        {
            s32 status;
            status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
            switch (status)
            {
                case 1:
                    if (cardError != 0)
                    {
                        sMemcardSeqMode = 6;
                        break;
                    }
                    switch (cardCode)
                    {
                        case 0x9003:
                            return -3;
                        case 0x6f:
                            return -3;
                        case 0x13:
                            return -3;
                        case 0x9001:
                            return -3;
                        case 0x2f:
                            return -3;
                        default:
                            break;
                    }
                    break;
                case -1:
                    sMemcardSeqMode = 6;
                    break;
                default:
                    break;
            }
            break;

        }
        case 6:
            if (sMemcardAsync != 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E48E0, sMemcardFile);
            }
            else
            {
                if (FUN_0017d800() != 0)
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4900, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4920, sMemcardFile);
                    }
                }
                else
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4940, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4960, sMemcardFile);
                    }
                }
            }
            FUN_005225a8(D_005E4980, FUN_005140f8(sSocketNo, D_00846DA0));
            sMemcardSeqMode = 7;
            return 5;

        case 7:
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
            {
                if (cardError != 0)
                {
                    sMemcardSeqMode = 10;
                }
                else
                {
                    switch (cardCode)
                    {
                        case 0x11:
                            sMemcardSeqMode = 10;
                            break;
                        case 0x1c:
                            return -6;
                        default:
                            return -3;
                    }
                }
            }
            break;


        case 10:
            switch (sMemcardMode)
            {
            case 0:
            {
                if (sMemcardAsync != 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
                }
                else
                {
                    if (FUN_0017d800() == 0)
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E49D0, sMemcardFile, sMemcardFile);
                        }
                    }
                    else
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E49A0, sMemcardFile, sMemcardFile);
                        }
                    }
                }
                break;
            case 1:
            {
                if (sMemcardAsync != 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4A00, sMemcardFile);
                }
                else
                {
                    if (FUN_0017d800() == 0)
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4A60, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4A80, sMemcardFile);
                        }
                    }
                    else
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4A20, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4A40, sMemcardFile);
                        }
                    }
                }
                break;
            case 2:
            {
                if (sMemcardAsync != 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4AA0, sMemcardFile);
                }
                else
                {
                    if (FUN_0017d800() == 0)
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4B00, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4B20, sMemcardFile);
                        }
                    }
                    else
                    {
                        if (FUN_0016f190(0x1422) == 0)
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4AC0, sMemcardFile);
                        }
                        else
                        {
                            FUN_00523ac8(D_00846DA0, D_005E4AE0, sMemcardFile);
                        }
                    }
                }
            }
                break;
            default:
                break;
            }
            FUN_00513de8(sSocketNo, D_00846DA0);
            sMemcardSeqMode = 0xb;
            break;
        case 0xb:
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
            {
                if (cardError == 0)
                {
                    if (cardCode == 0x1c)
                    {
                        return -6;
                    }
                    if (cardCode != 0x11)
                    {
                        return -3;
                    }
                    sMemcardSeqMode = 0xc;
                }
                else
                {
                    sMemcardSeqMode = 0xc;
                }
            }
            break;

        case 0xc:
            switch (sMemcardMode)
            {
                case 0:
                    goto state12_mode0;
                case 1:
                    goto state12_mode1;
                case 2:
                    goto state12_mode2;
                default:
                    goto state12_done;
            }

state12_mode0:
            if (sMemcardAsync != 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
            }
            else
            {
                if (FUN_0017d800() != 0)
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E49A0, sMemcardFile, sMemcardFile);
                    }
                }
                else
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E49D0, sMemcardFile, sMemcardFile);
                    }
                }
            }
            FUN_00513cc8(sSocketNo, D_00846DA0, sMemcardBuffer, 0, sMemcardBufferSize);
            goto state12_done;

state12_mode1:
            if (sMemcardAsync != 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E4A00, sMemcardFile);
            }
            else
            {
                if (FUN_0017d800() != 0)
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4A20, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4A40, sMemcardFile);
                    }
                }
                else
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4A60, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4A80, sMemcardFile);
                    }
                }
            }
            size = 0;
            FUN_00513cc8(sSocketNo, D_00846DA0, FUN_001021c0(D_005E4B40, &size), 0, size);
            goto state12_done;

state12_mode2:
            if (sMemcardAsync != 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E4AA0, sMemcardFile);
            }
            else
            {
                if (FUN_0017d800() != 0)
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4AC0, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4AE0, sMemcardFile);
                    }
                }
                else
                {
                    if (FUN_0016f190(0x1422) == 0)
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4B00, sMemcardFile);
                    }
                    else
                    {
                        FUN_00523ac8(D_00846DA0, D_005E4B20, sMemcardFile);
                    }
                }
            }
            FUN_00521408(D_00846780, 0, 0x3c4);
            FUN_00524270(D_00846780, 0x7cc0c8);
            if (FUN_0017d800() == 0)
            {
                if ((sMemcardFile >= 0) && (sMemcardFile < 0x10))
                {
                    FUN_00524270(D_00846840, D_005E4B50);
                    FUN_00523e68(D_00846840, sMemcardFile * 8 + D_005E4790);
                }
            }
            else if ((sMemcardFile >= 0) && (sMemcardFile < 0x10))
            {
                FUN_00524270(D_00846840, D_005E4B80);
                FUN_00523e68(D_00846840, sMemcardFile * 8 + D_005E4790);
            }
            D_00846786 = 0x12;
            D_0084678C = 0x60;
            FUN_00521250(D_00846790, D_005E46C0, 0x40);
            FUN_00521250(D_00846780 + 0x50, D_005E4700, 0x30);
            FUN_00521250(D_00846800, D_005E4730, 0x30);
            FUN_00521250(D_00846830, D_005E4760, 0x10);
            FUN_00524270(D_00846884, D_005E4780);
            FUN_00524270(D_008468C4, D_005E4784);
            FUN_00524270(D_00846904, D_005E4788);
            FUN_00513cc8(sSocketNo, D_00846DA0, D_00846780, 0, 0x3c4);

state12_done:
            sMemcardSeqMode = 0xd;
            break;

        case 0xd:
            if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
            {
                if (cardError != 0)
                {
                    if (sMemcardMode == 2)
                    {
                        return 100;
                    }
                    sMemcardMode++;
                    sMemcardSeqMode = 10;
                    break;
                }
                if (cardCode != 0x1c)
                {
                    if (cardCode == 0x11)
                    {
                        sMemcardSeqMode = 0xc;
                    }
                    else
                    {
                        return -3;
                    }
                }
                else
                {
                    return -6;
                }
            }
            break;
    }

done:
    return 0;
}

// FUN_00190580
void func_00190580(void)
{
    sMemcardAbort = 1;
}

// FUN_00190590 Poll cancellation/error status for a transaction.
s32 func_00190590(void)
{
    s32 status;
    s32 cardMode;
    s32 cardCode;
    s32 cardError;

    if (sMemcardAbort != 0)
    {
        status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
        if (status == -1)
        {
            sMemcardAbort = 0;
            FUN_005136f8(sSocketNo, D_00846EA0);
        }
    }
    else
    {
        status = func_0018f190(&cardMode, (u32*)&cardCode, &cardError);
        if (status == 1)
        {
            FUN_005136f8(sSocketNo, D_00846EA0);
            if (cardError == 0)
            {
                switch (cardCode)
                {
                    case 0x9003:
                        goto card_error_9003;
                    case 0x6f:
                        goto card_error_6f;
                    case 0x13:
                        goto card_error_13;
                    case 0x9001:
                        goto card_error_9001;
                    case 0x2f:
                        goto card_error_2f;
                    default:
                        goto card_state;
                }
        }
            goto card_state;
    }
        }
    goto card_done;

card_error_9003:
    return 3;
card_error_6f:
    return -5;
card_error_13:
    return -5;
card_error_9001:
    return -4;
card_error_2f:
    return -2;

card_state:
    if (*D_00846EA0 != 2)
    {
        return -1;
    }
    if (*D_00846EA4 == 0)
    {
        return -2;
    }
    goto card_done;

card_done:
    return 0;
}

// FUN_00190700
void func_00190700(s32 file, void* buffer, s32* result)
{
    sMemcardSeqMode = 0;
    sMemcardMode = 0;
    sMemcardFile = file;
    sMemcardBuffer = buffer;
    sMemcardResult = result;
}

// FUN_00190720 Advance the load transaction state machine.
s32 func_00190720(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    FUN_005225a8(D_005E4810, sMemcardSeqMode);

    switch (sMemcardSeqMode)
    {
        case 0:
            goto state0;
        case 1:
            goto state1;
        case 2:
            goto state2;
        case 3:
            goto state3;
        default:
            goto done;
    }

state0:
    cardMode = 0;
    cardCode = 0;
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        FUN_005136f8(sSocketNo, D_00846EA0);
        sMemcardSeqMode = 1;
    }
    goto done;

state1:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError == 0)
        {
            switch (cardCode)
            {
                case 0x9003:
                    goto state1_error3;
                case 0x6f:
                    goto state1_error5b;
                case 0x13:
                    goto state1_error5a;
                case 0x9001:
                    goto state1_error4;
                case 0x2f:
                    goto state1_error2;
                default:
                    break;
            }
        }
        goto state1_continue;
state1_error3:
        return -3;
state1_error5b:
        return -5;
state1_error5a:
        return -5;
state1_error4:
        return -4;
state1_error2:
        return -2;
state1_continue:
        if (*D_00846EA0 != 2)
        {
            return -1;
        }
        if (*D_00846EA4 == 0)
        {
            return -2;
        }
        if (sMemcardAsync != 0)
        {
            FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
        }
        else
        {
            if (FUN_0017d800() != 0)
            {
                if (FUN_0016f190(0x1422) == 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
                }
                else
                {
                    FUN_00523ac8(D_00846DA0, D_005E49A0, sMemcardFile, sMemcardFile);
                }
            }
            else
            {
                if (FUN_0016f190(0x1422) == 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
                }
                else
                {
                    FUN_00523ac8(D_00846DA0, D_005E49D0, sMemcardFile, sMemcardFile);
                }
            }
        }
        FUN_005137b8(sSocketNo, D_00846DA0, D_00846C80);
        sMemcardSeqMode = 2;
    }
    goto done;

state2:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError == 0)
        {
            switch (cardCode)
            {
                case 0x6f:
                    goto state2_error5c;
                case 0x16:
                    goto state2_error5b;
                case 2:
                    goto state2_error8;
                case 0x13:
                    goto state2_error5a;
                default:
                    break;
            }
        }
        goto state2_continue;
state2_error5c:
        return -5;
state2_error5b:
        return -5;
state2_error8:
        return -8;
state2_error5a:
        return -5;
state2_continue:

        if (sMemcardAsync != 0)
        {
            FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
        }
        else
        {
            if (FUN_0017d800() != 0)
            {
                if (FUN_0016f190(0x1422) == 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
                }
                else
                {
                    FUN_00523ac8(D_00846DA0, D_005E49A0, sMemcardFile, sMemcardFile);
                }
            }
            else
            {
                if (FUN_0016f190(0x1422) == 0)
                {
                    FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
                }
                else
                {
                    FUN_00523ac8(D_00846DA0, D_005E49D0, sMemcardFile, sMemcardFile);
                }
            }
        }
        FUN_00513968(sSocketNo, D_00846DA0, sMemcardBuffer, 0, D_00846C90[0]);
        sMemcardSeqMode = 3;
    }
    goto done;

state3:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError != 0)
        {
            *sMemcardResult = cardCode;
        }
        else
        {
            switch (cardCode)
            {
                case 0x6f:
                    goto state3_error5e;
                case 0x16:
                    goto state3_error5d;
                case 0xd:
                    goto state3_error5c;
                case 2:
                    goto state3_error5b;
                case 0x13:
                    goto state3_error5a;
                default:
                    break;
            }
        }
        goto state3_continue;
state3_error5e:
        return -3;
state3_error5d:
        return -3;
state3_error5c:
        return -3;
state3_error5b:
        return -3;
state3_error5a:
        return -3;
state3_continue:
        FUN_005225a8(D_005E4BB0, cardCode);
        return 100;
    }

done:
    return 0;
}

// FUN_00190cb0
void func_00190cb0(u32* table)
{
    sMemcardSeqMode = 0;
    sSlotScanTable = table;
    sMemcardMode = 0;
    sMemcardFile = 0;
}

// FUN_00190cd0
s32 func_00190cd0(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    u32 checksum;
    u32 i;
    u8* recordData;

    switch (sMemcardSeqMode)
    {
        case 0:
            goto state0;
        case 1:
            goto state1;
        case 2:
            goto state2;
        case 3:
            goto state3;
        default:
            goto done;
    }

state0:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        FUN_005225a8(D_005E4BC8, FUN_005136f8(sSocketNo, D_00846EA0));
        sMemcardSeqMode = 1;
    }
    goto done;

state1:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) != 1)
    {
        goto done;
    }
    if (cardError != 0)
    {
        goto state1_card_error;
    }
    switch (cardCode)
    {
        case 0x9003:
            goto state1_card_error;
        case 0x6f:
            goto state1_error6f;
        case 0x13:
            goto state1_error13;
        case 0x9001:
            goto state1_error9001;
        case 0x2f:
            goto state1_error2f;
        default:
            goto state1_card_error;
    }

state1_error6f:
    return -5;
state1_error13:
    return -5;
state1_error9001:
    return -4;
state1_error2f:
    return -2;

state1_card_error:
    if (*D_00846EA0 != 2)
    {
        return -1;
    }
    if (*D_00846EA4 == 0)
    {
        return -2;
    }
    sMemcardSeqMode = 2;
    goto done;

state2:
    sMemcardBuffer = MEMCARD_ALLOC(0x38, 0x40000);
    if (sMemcardAsync != 0)
    {
        FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
    }
    else
    {
        if (FUN_0017d800() != 0)
        {
            if (FUN_0016f190(0x1422) == 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
            }
            else
            {
                FUN_00523ac8(D_00846DA0, D_005E49A0, sMemcardFile, sMemcardFile);
            }
        }
        else
        {
            if (FUN_0016f190(0x1422) == 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
            }
            else
            {
                FUN_00523ac8(D_00846DA0, D_005E49D0, sMemcardFile, sMemcardFile);
            }
        }
    }
    FUN_00513968(sSocketNo, D_00846DA0, sMemcardBuffer, 0, 0x38);
    FUN_005225a8(D_005E4BE0, D_00846DA0, 0x38);
    sMemcardSeqMode = 3;
    goto done;

state3:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) != 1)
    {
        goto done;
    }
    FUN_005225a8(D_005E4BF8, cardCode);
    if (cardError == 0)
    {
        switch (cardCode)
        {
            case 0x6f:
                goto state3_error6f;
            case 0x16:
                goto state3_error16;
            case 0xd:
                goto state3_errord;
            case 2:
                goto state3_error2;
            case 0x13:
                goto state3_error13;
            default:
                goto state3_after;
        }

state3_error6f:
        MEMCARD_FREE(sMemcardBuffer);
        return -3;
state3_error16:
        MEMCARD_FREE(sMemcardBuffer);
        return -3;
state3_errord:
        MEMCARD_FREE(sMemcardBuffer);
        return -3;
state3_error2:
        MEMCARD_FREE(sMemcardBuffer);
        sSlotScanTable[sMemcardFile] = 0;
        goto state3_after;
state3_error13:
        MEMCARD_FREE(sMemcardBuffer);
        return -3;
    }
    FUN_00521250((u8*)sSlotScanTable + sMemcardFile * 0x34 + 0x40,
                 (u8*)sMemcardBuffer + 4, 0x34);
    MEMCARD_FREE(sMemcardBuffer);
    if (cardCode >= 0)
    {
        recordData = (u8*)sSlotScanTable + sMemcardFile * 0x34 + 0x40;
        checksum = 0;
        for (i = 0; i < 0x32; i++)
        {
            checksum = (u16)((checksum + recordData[i]) & 0xff);
        }
        if (*(u16*)(recordData + 0x32) != (checksum & 0xff))
        {
            FUN_00521408(recordData, 0, 0x34);
        }
        sSlotScanTable[sMemcardFile] = 1;
    }
    else
    {
        sSlotScanTable[sMemcardFile] = 0;
    }

state3_after:
    sMemcardFile++;
    if (sMemcardFile == 0x10)
    {
        return 100;
    }
    sMemcardSeqMode = 2;
    goto done;

done:
    return 0;
}

// FUN_00191240
void func_00191240(void)
{
    sMemcardSeqMode = 0;
    sMemcardMode = 0;
    sMemcardFile = 0;
}

// FUN_00191260. Scan slot records until a valid card is found.
s32 func_00191260(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;

    FUN_005225a8(D_005E4C10, sMemcardSeqMode);

    switch (sMemcardSeqMode)
    {
        case 0:
            goto state0;
        case 1:
            goto state1;
        case 2:
            goto state2;
        case 3:
            goto state3;
        default:
            goto done;
    }

state0:
    sSlotScanResult = -1;
    sSlotScanDone = 1;
    cardMode = 0;
    cardCode = 0;
    sSlotScanMode = 0;
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        FUN_005136f8(sSocketNo, D_00846EA0);
        sMemcardSeqMode = 1;
    }
    goto done;

state1:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError == 0)
        {
            if (cardCode == 0x2f)
            {
                goto state1_error64;
            }
            if (cardCode == 0x9001)
            {
                goto state1_error4;
            }
            if (cardCode == 0x9003)
            {
                goto state1_error3;
            }
            if (cardCode == 0x13)
            {
                goto state1_error5a;
            }
            switch (cardCode)
            {
                case 0x6f:
                    goto state1_error5b;
                default:
                    break;
            }
            goto state1_error9;
        }
        goto state1_card_error;
    }
    goto done;
 

state1_error5b:
    return -5;
state1_error5a:
    return -5;
state1_error3:
    FUN_005136f8(sSocketNo, D_00846EA0);
    goto done;
state1_error4:
    return -4;
state1_error64:
    return 100;
state1_error9:
    return -9;

state1_card_error:
    if (*D_00846EA0 == 2)
    {
        if (*D_00846EA8 >= 0x4e)
        {
            if (sSlotScanDone != 0)
            {
                return 100;
            }
            sSlotScanResult = 100;
            sMemcardSeqMode = 2;
            goto done;
        }
        sMemcardSeqMode = 2;
        goto done;
    }
    return -1;

state2:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        if (sMemcardAsync != 0)
        {
            FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
        }
        else
        {
            if (sSlotScanMode == 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
            }
            else
            {
                FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
            }
        }
        FUN_005137b8(sSocketNo, D_00846DA0, D_00846C80);
        sMemcardSeqMode = 3;
    }
    goto done;

state3:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError != 0)
        {
            goto state3_error64;
        }
        if (cardCode == 2)
        {
            goto state3_card2;
        }
        if (cardCode == 0x13)
        {
            goto state3_error5a;
        }
        if (cardCode == 0x16)
        {
            goto state3_error5b;
        }
        if (cardCode == 0x6f)
        {
            goto state3_error5c;
        }
        switch (cardCode)
        {
            case 0x9003:
                goto state3_error5d;
            default:
                break;
        }
    }
    goto done;

state3_error5d:
    return -5;
state3_error5c:
    return -5;
state3_error5b:
    return -5;
state3_error5a:
    return -5;

state3_card2:
    sMemcardFile++;
    if (sMemcardFile != 0x10)
    {
        goto state3_card2_continue;
    }
    if (sSlotScanMode == 1)
    {
        if (sSlotScanResult != 100)
        {
            return -6;
        }
        return 100;
    }
    sMemcardFile = 0;
    sSlotScanMode = 1;
state3_card2_continue:
    sMemcardSeqMode = 2;
    goto done;

state3_error64:
    sSlotScanDone = 1;
    return 100;

done:
    return 0;
}

// FUN_00191640
void func_00191640(s32 slot)
{
    sMemcardSeqMode = 0;
    sMemcardMode = 0;
    sMemcardFile = slot;
}

// FUN_00191660. Scan one slot and report card status.
s32 func_00191660(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;

    FUN_005225a8(D_005E4C10, sMemcardSeqMode);

    switch (sMemcardSeqMode)
    {
        case 0:
            goto state0;
        case 1:
            goto state1;
        case 2:
            goto state2;
        case 3:
            goto state3;
        default:
            goto done;
    }

state0:
    cardMode = 0;
    cardCode = 0;
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        FUN_005136f8(sSocketNo, D_00846EA0);
        sMemcardSeqMode = 1;
    }
    goto done;

state1:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError == 0)
        {
            if (cardCode == 0x2f)
            {
                goto state1_error64;
            }
            if (cardCode == 0x9001)
            {
                goto state1_error4;
            }
            if (cardCode == 0x9003)
            {
                goto state1_error3;
            }
            if (cardCode == 0x13)
            {
                goto state1_error5a;
            }
            switch (cardCode)
            {
                case 0x6f:
                    goto state1_error5b;
                default:
                    break;
            }
            goto state1_error9;
        }
        goto state1_card_error;
    }
    goto done;

state1_error5b:
    return -5;
state1_error5a:
    return -5;
state1_error3:
    FUN_005136f8(sSocketNo, D_00846EA0);
    goto done;
state1_error4:
    return -4;
state1_error64:
    return 100;
state1_error9:
    return -9;

state1_card_error:
    if (*D_00846EA0 != 2)
    {
        goto state1_card_error_bad;
    }
    if (*D_00846EA8 >= 0x4e)
    {
        return 100;
    }
    sMemcardSeqMode = 2;
    goto done;
state1_card_error_bad:
    return -1;

state2:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == -1)
    {
        if (sMemcardAsync != 0)
        {
            FUN_00523ac8(D_00846DA0, D_005E4840, sMemcardFile, sMemcardFile);
        }
        else
        {
            if (FUN_0017d800() != 0)
            {
                FUN_00523ac8(D_00846DA0, D_005E48A0, sMemcardFile, sMemcardFile);
            }
            else
            {
                FUN_00523ac8(D_00846DA0, D_005E4870, sMemcardFile, sMemcardFile);
            }
        }
        FUN_005137b8(sSocketNo, D_00846DA0, D_00846C80);
        sMemcardSeqMode = 3;
    }
    goto done;

state3:
    if (func_0018f190(&cardMode, (u32*)&cardCode, &cardError) == 1)
    {
        if (cardError != 0)
        {
            goto state3_error64;
        }
        if (cardCode == 2)
        {
            goto state3_error6;
        }
        if (cardCode == 0x13)
        {
            goto state3_error5a;
        }
        if (cardCode == 0x16)
        {
            goto state3_error5b;
        }
        if (cardCode == 0x6f)
        {
            goto state3_error5c;
        }
        switch (cardCode)
        {
            case 0x9003:
                goto state3_error5d;
            default:
                break;
        }
    }
    goto done;

state3_error5d:
    return -5;
state3_error5c:
    return -5;
state3_error5b:
    return -5;
state3_error5a:
    return -5;
state3_error6:
    return -6;
state3_error64:
    return 100;

done:
    return 0;
}

