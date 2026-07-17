#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251060(void);
void FUN_002510d0(void);
void FUN_002518b0(s32 param_1);
u32 FUN_002519d0(void);
void FUN_00251a20(void);
extern int iGpffffb654;
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068e9c0[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

static u32* sBpTut654; // puGpffffb654
typedef struct BpTutWork
{
    u32 flags;
    u32 phase;
    u32 type;
    u32 step;
    KwlnTask* task;
} BpTutWork;

s32 FUN_0021c8b0(s32 param_1);
u32 FUN_001114b0(KwlnTask* task);
void FUN_00111500(KwlnTask* task);
void FUN_00111530(KwlnTask* task);
u32 FUN_00195460(KwlnTask* task);
void FUN_003c72d0(s32 handle);
void FUN_003c7430(s32 param_1);
void FUN_003c74e0(s32 param_1);
void FUN_003c7560(s32 param_1);
void FUN_003c7650(s32 param_1);
void FUN_003c77a0(void);
u32 FUN_003c7850(void);
void FUN_003c7990(s32 param_1);

// FUN_00251010
void bpTut00251010(void* param_1, s32 param_2)
{
    *(s32*)((u8*)param_1 + 0x10) += param_2;
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251030
void bpTut00251030(void* param_1)
{
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251050
void bpTut00251050(u32* param_1)
{
    *param_1 = 0;
    sBpTut654 = param_1;
}

/* Recovered battle-misc harvest: 0x00251060-0x00251A20 */
// FUN_00251060


void FUN_00251060(void)



{

  if (sBpTut654 == (u32 *)0x0) {

    FUN_0019d3f0(DAT_0068e9c0, 0x39);

  }

  if ((~*sBpTut654 & 1) == 0) {

    FUN_0019d3f0(DAT_0068e9c0, 0x49);

  }

  sBpTut654 = (u32 *)0x0;

  return;

}

// FUN_002510D0 NONMATCHING
void FUN_002510d0(void)
{
    BpTutWork* work;
    u32 value;
    u32 result;
    s16 flags[4];

    if (sBpTut654 == NULL) {
        FUN_0019d3f0(DAT_0068e9c0, 0x39);
    }
    work = (BpTutWork*)sBpTut654;
    if ((~work->flags & 1) == 0) {
        switch (work->phase) {
        case 0:
            if ((FUN_0021c860() == 0) &&
                (FUN_001114b0(work->task) != 0)) {
                FUN_003c72d0(FUN_0021c8b0(0));
                FUN_00111530(work->task);
                value = work->type;
                if (value == 3) {
                    FUN_003c7430(0x10);
                } else if (value == 2) {
                    FUN_003c7430(0xb);
                } else if (value == 1) {
                    FUN_003c7430(5);
                } else if (value == 0) {
                    FUN_003c7430(0);
                }
                value = work->type;
                if (value == 3) {
                    FUN_003c74e0(0x11);
                } else if (value == 2) {
                    FUN_003c74e0(0xc);
                } else if (value == 1) {
                    FUN_003c74e0(6);
                } else if (value == 0) {
                    FUN_003c74e0(0);
                }
                FUN_003c7560(0);
                work->step = 0;
                work->phase = 1;
            }
            break;

        case 1:
            switch (work->step) {
            case 0:
                FUN_003c7990(1);
                result = FUN_003c7850();
                if (result == 0) {
                    result = FUN_003c7610();
                    if (result == 1) {
                        FUN_003c7650(1);
                        value = work->type;
                        if (value == 3) {
                            FUN_003c7430(0x14);
                        } else if (value == 2) {
                            FUN_003c7430(0xf);
                        } else if (value == 1) {
                            FUN_003c7430(10);
                        } else if (value == 0) {
                            FUN_003c7430(4);
                        }
                        work->step = 2;
                    } else if (result == 0) {
                        FUN_003c7650(1);
                        value = work->type;
                        if (value == 1) {
                            FUN_003c7430(7);
                            work->step = 3;
                        } else if ((value == 3) || (value == 2) || (value == 0)) {
                            if (value == 3) {
                                FUN_003c7430(0x12);
                            } else if (value == 2) {
                                FUN_003c7430(0xd);
                            } else if (value == 0) {
                                FUN_003c7430(0);
                            }
                            value = work->type;
                            if (value == 3) {
                                FUN_003c74e0(0x13);
                            } else if (value == 2) {
                                FUN_003c74e0(0xe);
                            } else if (value == 0) {
                                FUN_003c74e0(0);
                            }
                            FUN_003c7560(0);
                            work->step = 1;
                        }
                    }
                }
                break;

            case 1:
                FUN_003c7990(1);
                result = FUN_003c7850();
                if (result == 0) {
                    result = FUN_003c7610();
                    if (result == 0) {
                        FUN_003c7650(1);
                        value = work->type;
                        if (value == 3) {
                            FUN_003c7430(0x14);
                        } else if (value == 2) {
                            FUN_003c7430(0xf);
                        } else if (value == 1) {
                            FUN_003c7430(10);
                        } else if (value == 0) {
                            FUN_003c7430(4);
                        }
                        work->step = 2;
                    } else if (result == 1) {
                        FUN_003c7650(1);
                        value = work->type;
                        if (value == 1) {
                            FUN_003c7430(7);
                            work->step = 3;
                        } else if ((value == 3) || (value == 2) || (value == 0)) {
                            if (value == 3) {
                                FUN_003c7430(0x12);
                            } else if (value == 2) {
                                FUN_003c7430(0xd);
                            } else if (value == 0) {
                                FUN_003c7430(0);
                            }
                            value = work->type;
                            if (value == 3) {
                                FUN_003c74e0(0x13);
                            } else if (value == 2) {
                                FUN_003c74e0(0xe);
                            } else if (value == 0) {
                                FUN_003c74e0(0);
                            }
                            FUN_003c7560(0);
                            work->step = 1;
                        }
                    }
                }
                break;

            case 2:
                FUN_003c7990(1);
                result = FUN_003c7850();
                if (result == 0) {
                    FUN_003c7650(1);
                    FUN_00111500(work->task);
                    work->step = 7;
                }
                break;

            case 3:
                FUN_003c7990(1);
                result = FUN_003c7850();
                if (result == 0) {
                    FUN_003c7650(1);
                    FUN_00111500(work->task);
                    FUN_003c77a0();
                    work->step = 4;
                }
                break;

            case 4:
                result = FUN_00195460(work->task);
                if (result == 0) {
                    FUN_003c94e0(FUN_0021c8b0(1));
                    FUN_003c9790(0);
                    work->step = 5;
                }
                break;

            case 5:
                FUN_003c7990(1);
                result = FUN_003c7850();
                if (result == 0) {
                    FUN_003c7650(1);
                    FUN_003c77a0();
                    FUN_003c72d0(FUN_0021c8b0(0));
                    FUN_003c7430(8);
                    FUN_003c74e0(9);
                    FUN_003c7560(0);
                    flags[0] = 4;
                    flags[1] = 4;
                    flags[2] = 2;
                    flags[3] = 0;
                    work->task = (KwlnTask*)FUN_00110f80(0, *(s64*)flags);
                    work->step = 6;
                }
                break;

            case 6:
                result = FUN_001114b0(work->task);
                if (result != 0) {
                    FUN_00111530(work->task);
                    work->step = 1;
                }
                break;

            case 7:
                result = FUN_00195460(work->task);
                if (result == 0) {
                    FUN_00251a20();
                    work->flags &= ~1;
                }
                break;
            }
            break;
        }
    }
}

// FUN_002518B0


void FUN_002518b0(s32 param_1)
{
    u32* work;
    s16 flags[4];

    if (sBpTut654 == NULL) {
        FUN_0019d3f0(DAT_0068e9c0, 0x39);
    }
    work = sBpTut654;
    switch (param_1) {
    case 0:
        FUN_0016f1f0(0x1307, 1);
        break;
    case 1:
        FUN_0016f1f0(0x1308, 1);
        break;
    case 2:
        FUN_0016f1f0(0x1309, 1);
        break;
    case 3:
        FUN_0016f1f0(0x130a, 1);
        break;
    }
    FUN_0021c7f0();
    flags[0] = 4;
    flags[1] = 4;
    flags[2] = 2;
    flags[3] = 0;
    work[4] = FUN_00110f80(0, *(s64*)flags);
    work[1] = 0;
    work[0] |= 1;
    work[2] = param_1;
}

// FUN_002519D0


u32 FUN_002519d0(void)



{

  if (sBpTut654 == (u32 *)0x0) {
    FUN_0019d3f0(DAT_0068e9c0,0x39);

  }

  return *sBpTut654 & 1;

}

// FUN_00251A20


void FUN_00251a20(void)



{

  if (iGpffffb654 == 0) {
    FUN_0019d3f0(DAT_0068e9c0,0x39);

  }

  FUN_003c77a0();

  FUN_0021c930();

  return;

}
