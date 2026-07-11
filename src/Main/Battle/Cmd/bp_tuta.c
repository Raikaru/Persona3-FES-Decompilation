#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251a80(void);
void FUN_00251e10(void);
u32 FUN_00251e80(void);
void FUN_00251ed0(void);
u32 FUN_003c7610(void);
extern int iGpffffb658;
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068e9d0[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

static u32* sBpTutaWork; // puGpffffb658

// FUN_00251a70
void bpTuta00251a70(u32* param_1)
{
    *param_1 = 0;
    sBpTutaWork = param_1;
}

/* Recovered battle-misc harvest: 0x00251A80-0x00251ED0 */
// FUN_00251A80 NONMATCHING


void FUN_00251a80(void)
{
    u32 state;
    u32* work;
    u32 result;
    u32 selection;

    if (sBpTutaWork == NULL) {
        FUN_0019d3f0(DAT_0068e9d0, 0x31);
    }

    work = sBpTutaWork;
    if ((~*sBpTutaWork & 1) == 0) {
        switch (sBpTutaWork[1]) {
        case 0:
            if (FUN_0021c860() == 0) {
                work[1] = 1;
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
                work[2] = 0;
            }
            break;

        case 1:
            state = sBpTutaWork[2];
            switch (state) {
            case 0:
                FUN_003c7990();
                if (FUN_003c7850() == 0) {
                    switch (FUN_003c7610()) {
                    case 0:
                        FUN_003c7650();
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 6;
                        } else {
                            selection = 2;
                        }
                        FUN_003c7430(selection);
                        FUN_003c74e0(3);
                        work[2] = 1;
                        break;

                    case 1:
                        FUN_003c7650();
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 7;
                        } else {
                            selection = 4;
                        }
                        FUN_003c7430(selection);
                        work[2] = 2;
                        break;
                    }
                }
                break;

            case 1:
                FUN_003c7990();
                if (FUN_003c7850() == 0) {
                    switch (FUN_003c7610()) {
                    case 0:
                        FUN_003c7650();
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 6;
                        } else {
                            selection = 2;
                        }
                        FUN_003c7430(selection);
                        FUN_003c74e0(3);
                        FUN_003c7560(1);
                        work[2] = 1;
                        break;

                    case 1:
                        FUN_003c7650();
                        result = FUN_0017d800();
                        if (result != 0) {
                            selection = 7;
                        } else {
                            selection = 4;
                        }
                        FUN_003c7430(selection);
                        work[2] = 2;
                        break;
                    }
                }
                break;

            case 2:
                FUN_003c7990();
                if (FUN_003c7850() == 0) {
                    FUN_003c7650(1);
                    if (FUN_0017d800() == 0) {
                        FUN_00251ed0();
                        *work &= ~1;
                    } else {
                        FUN_003c94e0(FUN_0021c8b0(2));
                        FUN_003c9790(8);
                        work[2] = 3;
                    }
                }
                break;

            case 3:
                FUN_003c7990();
                if (FUN_003c7850() == 0) {
                    FUN_003c7650(1);
                    FUN_003c77a0();
                    FUN_00251ed0();
                    *work &= ~1;
                }
                break;
            }
            break;
        }
    }
}

// FUN_00251E10


void FUN_00251e10(void)



{

  u32 *puVar1;

  

  if (sBpTutaWork == (u32 *)0x0) {
    FUN_0019d3f0(DAT_0068e9d0,0x31);

  }

  puVar1 = sBpTutaWork;

  FUN_0016f1f0(0x1306,1);

  FUN_0021c7f0();

  puVar1[1] = 0;

  *puVar1 = *puVar1 | 1;

  return;

}

// FUN_00251E80


u32 FUN_00251e80(void)



{

  if (sBpTutaWork == (u32 *)0x0) {
    FUN_0019d3f0(DAT_0068e9d0,0x31);

  }

  return *sBpTutaWork & 1;

}

// FUN_00251ED0


void FUN_00251ed0(void)



{

  if (iGpffffb658 == 0) {
    FUN_0019d3f0(DAT_0068e9d0,0x31);

  }

  FUN_003c77a0();

  FUN_0021c930();

  return;

}
