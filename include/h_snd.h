#ifndef H_SND_H
#define H_SND_H

#include "Utils.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwlnTask.h"

#define HSND_BGM_PLAYING     1
#define HSND_BGM_NOT_PLAYING 0

typedef enum
{
    HSND_BGM_TARTARUS_THEBEL = 1,            // 01.ADX (1st block, also used for Monad)
    HSND_BGM_MASS_DESTRUCTION,               // 26.ADX (Id in the code is 2 but ADX id = 26)
    HSND_BGM_SHADOW = 19,                    // 19.ADX
    HSND_BGM_DEEP_BREATH,                    // 20.ADX
    HSND_BGM_BASEMENT,                       // 21.ADX
    HSND_BGM_DEEP_MENTALITY,                 // 22.ADX
    HSND_BGM_DEEP_BREATH_2,                  // 23.ADX (unused)
    HSND_BGM_DEEP_BREATH_3,                  // 24.ADX (unused)
    HSND_BGM_MOON_REACHING_OUT_STARS,        // 25.ADX
    HSND_BGM_MASTER_OF_SHADOW = 27,          // 27.ADX
    HSND_BGM_UNAVOIDABLE_BATTLE,             // 28.ADX (strega battle ost)
    HSND_BGM_BURN_MY_DREAD_LAST,             // 29.ADX
    HSND_BGM_BATTLE_HYMN_OF_SOUL,            // 30.ADX (nyx battle)
    HSND_BGM_MASTER_OF_TARTARUS,             // 31.ADX (tartarus bosses)
    HSND_BGM_KYOTO,                          // 32.ADX
    HSND_BGM_TROUBLED = 35,                  // 35.ADX
    HSND_BGM_ESCAPED_THE_DARKNESS,           // 36.ADX
    HSND_BGM_LIVING_WITH_DETERMINATION,      // 37.ADX
    HSND_BGM_JOY_1,                          // 38.ADX
    HSND_BGM_FEARFUL_EXPERIENCE,             // 39.ADX
    HSND_BGM_CALAMITY,                       // 40.ADX
    HSND_BGM_JOY_2 = 43,                     // 43.ADX
    HSND_BGM_MYSTERIOUS_FEELING,             // 44.ADX
    HSND_BGM_CRISIS,                         // 45.ADX
    HSND_BGM_PATH_IS_OPEN,                   // 46.ADX (social link level 10)
    HSND_BGM_WANT_TO_BE_CLOSE = 50,          // 50.ADX
    HSND_BGM_CHANGING_SEASONS,               // 51.ADX
    HSND_BGM_MEMORIES_OF_SCHOOL_1,           // 52.ADX (school during january)
    HSND_BGM_IWATODAI_DORM,                  // 53.ADX
    HSND_BGM_ARIA_OF_THE_SOUL,               // 54.ADX
    HSND_BGM_TANAKA_AMAZING_COMM,            // 55.ADX
    HSND_BGM_PAULOWNIA_MALL,                 // 56.ADX
    HSND_BGM_AFTER_BATTLE = 60,              // 60.ADX
    HSND_BGM_UNK_34,                         // 61.ADX (unused)
    HSND_BGM_PATH_WAS_CLOSED,                // 62.ADX (game over)
    HSND_BGM_TARTARUS_ARQA = 70,             // 70.ADX (tartarus 2nd block)
    HSND_BGM_VOICE_SOMEONE_CALLS,            // 71.ADX (tartarus 1st floor)
    HSND_BGM_TARTARUS_TZIAH,                 // 72.ADX (tartarus 4th block)
    HSND_BGM_TARTARUS_HARABAH,               // 73.ADX (tartarus 5th block)
    HSND_BGM_TARTARUS_ADAMAH_1,              // 74.ADX (tartarus 6rd block)
    HSND_BGM_TARTARUS_ADAMAH_2,              // 75.ADX (tartarus 6th block again)
    HSND_BGM_DEEP_MENTALITY_2,               // 76.ADX (unused)
    HSND_BGM_LIVING_WITH_DETERMINATION_DORM, // 77.ADX (dorm during january)
    HSND_BGM_AFTER_BATTLE_2,                 // 78.ADX
    HSND_BGM_MISTIC,                         // 79.ADX
    HSND_BGM_MEMORIES_OF_CITY,               // 80.ADX (city during january)
    HSND_BGM_TARTARUS_YABBASHAH,             // 81.ADX (tartarus 3rd block)
    HSND_BGM_UNK_48,                         // 82.ADX
    HSND_BGM_UNK_49,                         // 83.ADX
    HSND_BGM_UNK_50,                         // 84.ADX
    HSND_BGM_TRANQUILITY,                    // 85.ADX
    HSND_BGM_SOCIAL_LINK_UP,                 // 86.ADX
    HSND_BGM_ADVENTURED_ACT,                 // 87.ADX
    HSND_BGM_MEMORIES_OF_SCHOOL_2,           // 88.ADX (march 5th)
    HSND_BGM_DURING_THE_TEST,                // 89.ADX (exam)
    HSND_BGM_UNK_56,                         // 90.ADX
    HSND_BGM_AFTERNOON_BREAK,                // 91.ADX
    HSND_BGM_UNK_58,                         // 92.ADX
    HSND_BGM_VELVET_ROOM_FINAL,              // 93.ADX
    HSND_BGM_MASS_DESTRUCTION_FES = 106,     // 106.ADX
    HSND_BGM_HEARTFUL_CRY = 113,             // 113.ADX
    HSND_BGM_DARKNESS,                       // 114.ADX (the answer final boss)
    HSND_BGM_MAIN_MENU,                      // 115.ADX
    HSND_BGM_NONE = -1,
} BgmId;

typedef enum HsndChannelState
{
    HSND_CHANNEL_INACTIVE,
    HSND_CHANNEL_STARTING,
    HSND_CHANNEL_PLAYING,
    HSND_CHANNEL_RELEASING,
} HsndChannelState;

typedef enum HsndStartMode
{
    HSND_START_BGM,
    HSND_START_SE,
    HSND_START_SE_WITH_PARAM,
    HSND_START_STREAM,
    HSND_START_STREAM_FADE,
    HSND_START_CDVD,
    HSND_START_NAMED_STREAM,
} HsndStartMode;

/* Retail D_007E4430: six contiguous 0x134-byte sound records. */
typedef union HsndChannelModeArg
{
    void* data;
    s32 parameter;
} HsndChannelModeArg;

typedef struct HsndChannel
{
    u32 active;              /* 0x00 */
    u32 gate;                /* 0x04 */
    s16 id;                  /* 0x08 */
    s16 previousId;          /* 0x0A */
    s16 state;               /* 0x0C */
    s16 startMode;           /* 0x0E */
    void* handle;            /* 0x10: ACSSND handle */
    s16 requestType;         /* 0x14 */
    char name[0x102];        /* 0x16 */
    void* modeData;          /* 0x118 */
    HsndChannelModeArg modeArg; /* 0x11C */
    u8 pad120[0x10];         /* 0x120 */
    s16 resetId;             /* 0x130 */
    u8 pad132[2];            /* 0x132 */
} HsndChannel;

/* Retail D_007E5770: deferred sound request consumed by func_00108e80. */
typedef struct HsndSlotWork
{
    s16 state;               /* 0x00 */
    s16 param2;              /* 0x02 */
    s16 param1;              /* 0x04 */
    s16 pad6;                /* 0x06 */
    u32 completed;           /* 0x08 */
    s16 callbackMode;        /* 0x0C */
    s16 padE;                /* 0x0E */
    void* data0;             /* 0x10 */
    void* data1;             /* 0x14 */
    void* data2;             /* 0x18 */
    u32 data3;               /* 0x1C */
    u32 data4;               /* 0x20 */
    u32 data5;               /* 0x24 */
} HsndSlotWork;

/* Work data for the task created at 0x0010A770. */
typedef struct HsndStreamTaskWork
{
    u32 state;               /* 0x00 */
    void* source;            /* 0x04 */
    void* arg0;              /* 0x08 */
    s32 namePart0;           /* 0x0C */
    s32 namePart1;           /* 0x10 */
    u32 frameCount;          /* 0x14 */
    u32 completedFrames;     /* 0x18 */
    void* callback;          /* 0x1C */
    HCdvd* cdvd;             /* 0x20 */
} HsndStreamTaskWork;

void func_00108740(void);
void func_00108bc0(void);
void func_00108e80(HsndSlotWork* slot);
s16 H_Snd_GetCurrentBgmId(void);
void H_Snd_StopBgm(void);
void H_Snd_StopBgmFade(s16 fadeDuration);
u8 func_00109040(s16 id, s16 unused);
u8 func_00109070(s32 channelIndex);
u8 func_00109170(void);
void H_Snd_00109180(s32 channelIndex);
s16 func_001099a0(void);
u8 H_Snd_PlayBgm(s16 id, s32 unused);
u8 H_Snd_FUN_00109ae0(s32 slotIndex, void* data0, u32 data0Size, void* data1,
                      u32 data1Size, void* data2, u32 data2Size);
u8 H_Snd_FUN_00109ca0(s16 slotIndex, s16 parameter);
u32 H_Snd_FUN_00109df0(s32 slotIndex);
void func_00109e30(s16 channelIndex);
u8 func_00109f60(s16 channelIndex, s16 mappedChannelIndex);
void H_Snd_FUN_0010a0e0(s16 bank, s16 cue);
void func_0010a100(s16 channelIndex, s32 unused, s32 fadeFrames);
u8 func_0010a240(s16 channelIndex, void* streamData, s16 parameter);
u8 func_0010a2e0(void* streamData, s32 channelIndex, u16 id);
u8 func_0010a370(s16 channelIndex, const char* name);
u8 func_0010a410(s16 channelIndex, const char* name);
void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
s32 func_0010a500(s16 channelIndex);
void* H_Snd_StreamTaskUpdate(KwlnTask* task);
void H_Snd_StreamTaskDestroy(KwlnTask* task);
u8 H_Snd_StreamTaskIsFinished(KwlnTask* task);
KwlnTask* H_Snd_CreateStreamTask(KwlnTask* parent, void* source, void* callback,
                                 void* arg0, s32 namePart0, s32 namePart1);

#endif