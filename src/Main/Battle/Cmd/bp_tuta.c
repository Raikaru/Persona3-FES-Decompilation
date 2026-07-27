#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#pragma alias bpTutaInit FUN_00251a70
#pragma alias bpTutaUpdate FUN_00251A80
#pragma alias bpTutaStart FUN_00251E10
#pragma alias bpTutaIsActive FUN_00251E80
#pragma alias bpTutaClose FUN_00251ED0
#pragma alias datSetFlag FUN_0016f1f0


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void bpTutaUpdate(void);
void bpTutaStart(void);
u32 bpTutaIsActive(void);
void bpTutaClose(void);
u32 FUN_003c7610(void);
void FUN_003c7990(s32 mode);
u32 FUN_003c7650(s32 close);
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068e9d0[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

typedef struct BpTutaWork
{
    u32 flags;
    u32 phase;
    u32 step;
} BpTutaWork;

static BpTutaWork* sBpTutaWork;

// FUN_00251a70
void bpTutaInit(BpTutaWork* work)
{
    work->flags = 0;
    sBpTutaWork = work;
}

/* Recovered battle-misc harvest: 0x00251A80-0x00251ED0 */
// FUN_00251A80


void bpTutaUpdate(void)
{
    u32 state;
    BpTutaWork* work;
    u32 result;
    u32 selection;

    if (sBpTutaWork == NULL) {
        FUN_0019d3f0(DAT_0068e9d0, 0x31);
    }

    work = sBpTutaWork;
    if ((~sBpTutaWork->flags & 1) == 0) {
        switch (sBpTutaWork->phase) {
        case 0:
            if (FUN_0021c860() == 0) {
                work->phase = 1;
                FUN_003c72d0(FUN_0021c8b0(2));
                result = FUN_0017d800();
                if (result != 0) {
                    selection = 5;
                } else {
                    selection = 0;
                }
                FUN_003c7430(selection);
                FUN_003c74e0(1);
                FUN_003c7560(0);
                work->step = 0;
            }
            break;

        case 1:
            state = sBpTutaWork->step;
            switch (state) {
            case 0:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0) {
                    switch (FUN_003c7610()) {
                    case 0:
                        FUN_003c7650(1);
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 6;
                        } else {
                            selection = 2;
                        }
                        FUN_003c7430(selection);
                        FUN_003c74e0(3);
                        work->step = 1;
                        break;

                    case 1:
                        FUN_003c7650(1);
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 7;
                        } else {
                            selection = 4;
                        }
                        FUN_003c7430(selection);
                        work->step = 2;
                        break;
                    }
                }
                break;

            case 1:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0) {
                    switch (FUN_003c7610()) {
                    case 0:
                        FUN_003c7650(1);
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 6;
                        } else {
                            selection = 2;
                        }
                        FUN_003c7430(selection);
                        FUN_003c74e0(3);
                        FUN_003c7560(1);
                        work->step = 1;
                        break;

                    case 1:
                        FUN_003c7650(1);
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 7;
                        } else {
                            selection = 4;
                        }
                        FUN_003c7430(selection);
                        work->step = 2;
                        break;
                    }
                }
                break;

            case 2:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0) {
                    FUN_003c7650(1);
                    if (FUN_0017d800() == 0) {
                        bpTutaClose();
                        work->flags &= ~1;
                    } else {
                        FUN_003c94e0(FUN_0021c8b0(2));
                        FUN_003c9790(8);
                        work->step = 3;
                    }
                }
                break;

            case 3:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0) {
                    FUN_003c7650(1);
                    FUN_003c77a0();
                    bpTutaClose();
                    work->flags &= ~1;
                }
                break;
            }
            break;
        }
    }
}

// FUN_00251E10


void bpTutaStart(void)
{
    BpTutaWork* work;

    if (sBpTutaWork == NULL) {
        FUN_0019d3f0(DAT_0068e9d0, 0x31);
    }
    work = sBpTutaWork;
    datSetFlag(0x1306, 1);
    FUN_0021c7f0();
    work->phase = 0;
    work->flags |= 1;
}

// FUN_00251E80


u32 bpTutaIsActive(void)
{
    if (sBpTutaWork == NULL) {
        FUN_0019d3f0(DAT_0068e9d0, 0x31);
    }
    return sBpTutaWork->flags & 1;
}

// FUN_00251ED0


void bpTutaClose(void)
{
    if (sBpTutaWork == NULL) {
        FUN_0019d3f0(DAT_0068e9d0, 0x31);
    }
    FUN_003c77a0();
    FUN_0021c930();
}
