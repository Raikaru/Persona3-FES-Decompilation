#include "h_snd.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/g_data.h"
#include "rw/rwplcore.h"
#include "temporary.h"

#define HSND_CHANNEL_COUNT 6
#define HSND_SLOT_COUNT    6
typedef struct HsndBackendControl
{
    u32 flags;               /* 0x00 */
    u32 voiceCount;          /* 0x04 */
    u32 timeout;             /* 0x08 */
    u32 padC;                /* 0x0C */
    u32 pending;             /* 0x10 */
    u8 class;                /* 0x14 */
    u8 pad15[3];
    u32 data18;              /* 0x18 */
    u32 data1C;              /* 0x1C */
    u32 data20;              /* 0x20 */
    u32 data24;              /* 0x24 */
} HsndBackendControl;



static HsndChannel sChannels[16];
static HsndSlotWork sSlotWork[HSND_SLOT_COUNT];
#pragma alias sSlotWork_alt sSlotWork
extern u8 sSlotWork_alt[];
static HsndBackendControl sBackendControls[HSND_CHANNEL_COUNT];
static s16 sBgmRestartCountdown;
static void* sChannelData0[HSND_CHANNEL_COUNT];
static void* sChannelData1[HSND_CHANNEL_COUNT];
static void* sChannelData2[HSND_CHANNEL_COUNT];
static void* sChannelData3[HSND_CHANNEL_COUNT];
static u8 sChannelMap[HSND_CHANNEL_COUNT][8];

/* Retail D_005D4014: BGM id is the direct 12-byte-record index. */
static const char* const sBgmAdxStrings[116][3] =
{
    {"01.ADX", NULL, NULL},
    {"01.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {NULL, NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"19.ADX", NULL, NULL},
    {"20.ADX", NULL, NULL},
    {"21.ADX", NULL, NULL},
    {"22.ADX", NULL, NULL},
    {"23.ADX", NULL, NULL},
    {"24.ADX", NULL, NULL},
    {"25.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"27.ADX", NULL, NULL},
    {"28.ADX", NULL, NULL},
    {"29.ADX", NULL, NULL},
    {"30.ADX", NULL, NULL},
    {"31.ADX", NULL, NULL},
    {"32.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"26.ADX", NULL, NULL},
    {"35.ADX", NULL, NULL},
    {"36.ADX", NULL, NULL},
    {"37.ADX", NULL, NULL},
    {"38.ADX", NULL, NULL},
    {"39.ADX", NULL, NULL},
    {"40.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"43.ADX", NULL, NULL},
    {"44.ADX", NULL, NULL},
    {"45.ADX", NULL, NULL},
    {"46.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"50.ADX", NULL, NULL},
    {"51.ADX", NULL, NULL},
    {"52.ADX", NULL, NULL},
    {"53.ADX", NULL, NULL},
    {"54.ADX", NULL, NULL},
    {"55.ADX", NULL, NULL},
    {"56.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"60.ADX", NULL, NULL},
    {"61.ADX", NULL, NULL},
    {"62.ADX", NULL, NULL},
    {"63.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"THEME.ADX", NULL, NULL},
    {"70.ADX", NULL, NULL},
    {"71.ADX", NULL, NULL},
    {"72.ADX", NULL, NULL},
    {"73.ADX", NULL, NULL},
    {"74.ADX", NULL, NULL},
    {"75.ADX", NULL, NULL},
    {"76.ADX", NULL, NULL},
    {"77.ADX", NULL, NULL},
    {"78.ADX", NULL, NULL},
    {"79.ADX", NULL, NULL},
    {"80.ADX", NULL, NULL},
    {"81.ADX", NULL, NULL},
    {"82.ADX", NULL, NULL},
    {"83.ADX", NULL, NULL},
    {"84.ADX", NULL, NULL},
    {"85.ADX", NULL, NULL},
    {"86.ADX", NULL, NULL},
    {"87.ADX", NULL, NULL},
    {"88.ADX", NULL, NULL},
    {"89.ADX", NULL, NULL},
    {"90.ADX", NULL, NULL},
    {"91.ADX", NULL, NULL},
    {"92.ADX", NULL, NULL},
    {"93.ADX", NULL, NULL},
    {"94.ADX", NULL, NULL},
    {"95.ADX", NULL, NULL},
    {"96.ADX", NULL, NULL},
    {"97.ADX", NULL, NULL},
    {"98.ADX", NULL, NULL},
    {"99.ADX", NULL, NULL},
    {"100.ADX", NULL, NULL},
    {"101.ADX", NULL, NULL},
    {"102.ADX", NULL, NULL},
    {"103.ADX", NULL, NULL},
    {"104.ADX", NULL, NULL},
    {"105.ADX", NULL, NULL},
    {"106.ADX", NULL, NULL},
    {"107.ADX", NULL, NULL},
    {"108.ADX", NULL, NULL},
    {"109.ADX", NULL, NULL},
    {"110.ADX", NULL, NULL},
    {"111.ADX", NULL, NULL},
    {"112.ADX", NULL, NULL},
    {"113.ADX", NULL, NULL},
    {"114.ADX", NULL, NULL},
    {"115.ADX", NULL, NULL},
};

/* ACSSND entry points used by the retail sound state machine. */
typedef struct HsndInitParams
{
    f32 outputLevel;
    u32 enabled;
    u32 initialized;
    u32 reserved;
} HsndInitParams;

static HsndInitParams sSndInitParams;

extern const f32 DAT_007cad28;
extern void func_0057f768(void* params);
extern void func_0054cfe8(void);
extern void func_0054d468(void);
extern void func_005497b0(s32 frames);
extern void* func_0054d080(void* control);
extern void func_0054d250(void* handle, s32 value);
extern void func_0054d2e0(void* handle, s32 value);
extern void func_0054d4b8(s32 value);
extern void func_0054d4f0(s32 value);
extern void func_0054d528(s32 value);
extern void* func_0054d030(void* control, void* data0, void* data1);
extern void func_0054d220(void* handle, s32 frames);
extern void func_0054d238(void* handle, s32 value);
extern void func_0054d2b0(void* handle, s32 parameter);
extern u32 D_00960178[];
 #pragma alias H_Snd_FUN_00109df0_s16 H_Snd_FUN_00109df0
 extern u32 H_Snd_FUN_00109df0_s16(s16 slotIndex);

#define HSND_BACKEND_ALLOC(context, flags) \
    (*(void* (**)(void*, u32))D_00960178)((context), (flags))

// FUN_00108740 NONMATCHING
void func_00108740(void)
{
    void* context;
    void* backendData;
    void* (*backendAlloc)(void*, u32);
    s32 i;
    HsndSlotWork* slotWork;

    sSndInitParams.outputLevel = DAT_007cad28;
    sSndInitParams.enabled = true;
    sSndInitParams.initialized = true;
    sSndInitParams.reserved = 0;
    func_0057f768(&sSndInitParams);
    func_0054cfe8();
    func_0054d468();
    func_005497b0(30);

    memset(&sBackendControls[0], 0, sizeof(HsndBackendControl));
    sBackendControls[0].class = 1;
    sBackendControls[0].data18 = 0;
    sBackendControls[0].data1C = 0;
    sBackendControls[0].data20 = 0;
    sBackendControls[0].flags = 3;
    sBackendControls[0].voiceCount = 2;
    sBackendControls[0].timeout = 0xBB80;
    sBackendControls[0].pending = 1;
    context = func_0054d080(&sBackendControls[0]);
    backendAlloc = (void* (*)(void*, u32))D_00960178;
    backendData = backendAlloc(context, 0x40000);
    sChannelData0[0] = backendData;
    sChannelData1[0] = context;
    sChannels[0].handle = func_0054d030(&sBackendControls[0], backendData, context);
    func_0054d238(sChannels[0].handle, true);
    func_0054d220(sChannels[0].handle, 30);
    func_0054d2b0(sChannels[0].handle, 0x23);
    func_0054d250(sChannels[0].handle, 0xF);
    func_0054d528(0x3C);
    func_0054d4b8(0xF);
    func_0054d4f0(0xB4);
    func_0054d2e0(sChannels[0].handle, 10);

    memset(&sBackendControls[2], 0, sizeof(HsndBackendControl));
    sBackendControls[2].class = 2;
    sBackendControls[2].data18 = 0;
    sBackendControls[2].data1C = 0;
    sBackendControls[2].data20 = 0;
    sBackendControls[2].flags = 3;
    sBackendControls[2].voiceCount = 1;
    sBackendControls[2].timeout = 0x5DC0;
    sBackendControls[2].pending = 1;
    context = func_0054d080(&sBackendControls[2]);
    sChannelData0[2] = backendAlloc(context, 0x40000);
    sChannelData1[2] = context;
    sChannels[2].handle = NULL;

    memset(&sBackendControls[3], 0, sizeof(HsndBackendControl));
    sBackendControls[3].class = 3;
    sBackendControls[3].data18 = 0;
    sBackendControls[3].data1C = 0;
    sBackendControls[3].data20 = 0;
    sBackendControls[3].flags = 2;
    sBackendControls[3].voiceCount = 2;
    sBackendControls[3].timeout = 0x5DC0;
    sBackendControls[3].pending = 1;
    context = func_0054d080(&sBackendControls[3]);
    sChannelData0[3] = backendAlloc(context, 0x40000);
    sChannelData1[3] = context;

    sChannels[3].handle = NULL;
    memset(&sBackendControls[4], 0, sizeof(HsndBackendControl));
    sBackendControls[4].class = 3;
    sBackendControls[4].data18 = 0;
    sBackendControls[4].data1C = 0;
    sBackendControls[4].data20 = 0;
    sBackendControls[4].flags = 2;
    sBackendControls[4].voiceCount = 2;
    sBackendControls[4].timeout = 0x5DC0;
    sBackendControls[4].pending = 1;
    context = func_0054d080(&sBackendControls[4]);
    sChannelData0[4] = backendAlloc(context, 0x40000);
    sChannelData1[4] = context;

    sChannels[4].handle = NULL;
    slotWork = sSlotWork;
    for (i = 0; i < HSND_SLOT_COUNT; i++)
    {
        slotWork[i].state = 0;
        slotWork[i].completed = false;
    }
    for (i = 0; i < 16; i++)
    {
        sChannels[i].active = false;
        sChannels[i].previousId = 0;
        sChannels[i].state = HSND_CHANNEL_INACTIVE;
        sChannels[i].resetId = HSND_BGM_NONE;
    }
    sBgmRestartCountdown = 0;
}

extern void func_00540ec0(void);
extern void func_0051db00(s32 group, s32 left, s32 right, s32 rear);
extern void func_0054d060(void* handle);
extern void* func_0054d030(void* control, void* data0, void* data1);
extern void func_0054d0a0(void* handle, const char* name);
extern void func_0054d0b8(void* handle, void* data, s16 id);
extern void func_0054d0d0(void* handle, void* data0, void* data1);
extern void func_0054d0e8(void* handle, void* data, s32 parameter);
extern void func_0054d100(void* handle);
extern void func_0054d118(void* handle, s32 value);
extern s32 func_0054d130(void* handle);
extern s32 func_0054d148(void* handle);
extern void func_0054d1a8(void* handle, s32 value);
extern void func_0054d208(void* handle, s32 enabled);
extern void func_0054d220(void* handle, s32 frames);
extern void func_0054d238(void* handle, s32 value);
extern void func_0054d2b0(void* handle, s32 parameter);
extern void func_0054d328(void* handle);
extern void func_0054d3a8(void* handle, s32 value);
extern void func_00102530(void* handle, const char* name);
extern void func_001025c0(void* handle, const char* name);
extern void func_001024a0(void* source, const char* name, s32 flags, void* callback);
extern s32 func_0053c268(void* source);
extern void func_0010d6f0(s16 param1, s16 param2);
extern void func_0010d7b0(s16 param1, s16 param2, void* data0, u32 data0Size,
                           void* data1, u32 data1Size, void* data2, u32 data2Size);
extern s32 func_0010d910(s16 param1);
extern void func_0010da70(s16 bank, s16 cue);
extern void func_0010db60(s32 bank, s32 cue, s32 variant, s32 pan);
extern char D_007E39F0[];
extern u32 D_00960184[];
#define HSND_ALLOC(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184)(count, size, flags)

static HsndChannel* H_Snd_GetChannel(s32 index)
{
    if (index < 0 || index >= HSND_CHANNEL_COUNT)
    {
        return NULL;
    }

    return &sChannels[index];
}

static void H_Snd_ClearChannel(HsndChannel* channel)
{
    channel->active = false;
    channel->state = HSND_CHANNEL_INACTIVE;
    channel->id = HSND_BGM_NONE;
}

static void H_Snd_ApplyChannelFade(HsndChannel* channel, s32 frames)
{
    if (channel->handle != NULL)
    {
        func_0054d220(channel->handle, frames);
    }
}

// FUN_00108BC0 NONMATCHING
void func_00108bc0(void)
{
    s16 i;
    HsndChannel* channel;
    void** handle;
    s16* state;
    s32 status;

    func_00540ec0();
    func_0051db00(3, 0x80, 0x7F, 0x7F);

    for (i = 0; i < HSND_SLOT_COUNT; i++)
    {
        func_00108e80(&sSlotWork[i]);
    }

    if (sChannels[0].active != false)
    {
        if (sChannels[0].gate != false && sBgmRestartCountdown != 0)
        {
            sBgmRestartCountdown--;
            if (sBgmRestartCountdown == 0)
            {
                func_0054d118(sChannels[0].handle, true);
            }
        }

        func_0054d3a8(sChannels[0].handle, false);
        status = func_0054d148(sChannels[0].handle);
        if (status == 3)
        {
            sChannels[0].active = false;
        }
        else if (status == 4)
        {
            func_00109070(0);
            H_Snd_00109180(0);
            func_0054d208(sChannels[0].handle, true);
        }
    }

    for (i = 2; i < HSND_CHANNEL_COUNT; i++)
    {
        channel = &sChannels[i];
        handle = &channel->handle;
        state = &channel->state;
        if (channel->active == false)
        {
            continue;
        }

        status = func_0054d148(*handle);
        if (status == 3)
        {
            channel->active = false;
        }
        else if (status == 4)
        {
            func_00109070(i);
            H_Snd_00109180(i);
            func_0054d208(*handle, true);
        }
        else if (*state == HSND_CHANNEL_STARTING)
        {
            func_0054d100(*handle);
            *state = HSND_CHANNEL_PLAYING;
        }
        else if (*state == HSND_CHANNEL_PLAYING)
        {
            H_Snd_00109180(i);
            *state = HSND_CHANNEL_PLAYING;
        }
    }
}

// FUN_00108E50
s16 H_Snd_GetCurrentBgmId(void)
{
    if (sChannels[0].active == false)
    {
        return HSND_BGM_NONE;
    }

    return sChannels[0].id;
}

// FUN_00108E80
void func_00108e80(HsndSlotWork* slot)
{
    switch (slot->state)
    {
        case 0:
            slot->state = 1;
            break;

        case 1:
            break;

        case 2:
            if (slot->callbackMode == 0)
            {
                func_0010d6f0(slot->param1, slot->param2);
            }
            else
            {
                func_0010d7b0(slot->param1, slot->param2, slot->data0, slot->data3,
                               slot->data1, slot->data4, slot->data2, slot->data5);
            }
            slot->state = 3;
            break;

        case 3:
            if (func_0010d910(slot->param1) != 0)
            {
                slot->completed = true;
                slot->state = 1;
            }
            break;

        default:
            break;
    }
}

// FUN_00108F70
void H_Snd_StopBgm(void)
{
    if (sChannels[0].active != false)
    {
        func_0054d100(sChannels[0].handle);
        sChannels[0].active = false;
        sChannels[0].state = HSND_CHANNEL_INACTIVE;
        sChannels[0].id = HSND_BGM_NONE;
    }
}

// FUN_00108FD0
void H_Snd_StopBgmFade(s16 fadeDuration)
{
    func_0054d220(sChannels[0].handle, fadeDuration);
    if (sChannels[0].active != false)
    {
        func_0054d100(sChannels[0].handle);
        sChannels[0].active = false;
        sChannels[0].state = HSND_CHANNEL_INACTIVE;
        sChannels[0].id = HSND_BGM_NONE;
    }
}

// FUN_00109040
u8 func_00109040(s16 id, s16 unused)
{
    H_Snd_PlayBgm(id, true);
    return true;
}

// FUN_00109070
u8 func_00109070(s32 channelIndex)
{
    if (channelIndex < 2)
    {
        if (sChannels[channelIndex].active != false)
        {
            func_0054d100(sChannels[channelIndex].handle);
            sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
            sChannels[channelIndex].active = false;
            sChannels[channelIndex].id = HSND_BGM_NONE;
        }
    }
    else
    {
        if (sChannels[channelIndex].active != false)
        {
            func_0054d100(sChannels[channelIndex].handle);
            sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
            sChannels[channelIndex].active = false;
            sChannels[channelIndex].id = HSND_BGM_NONE;
        }
    }

    return true;
}

// FUN_00109170
u8 func_00109170(void)
{
    /* The retail hook intentionally reports that no optional backend exists. */
    return false;
}

/* Retail 0x1091A4-0x109994: reconstructed BGM and backend dispatch logic from retail instructions. */
// FUN_00109180 NONMATCHING
void H_Snd_00109180(s32 channelIndex)
{
    char name[0x100];
    void** handle;
    s32 channelOffset;
    s16* requestType;

    if (channelIndex == 0)
    {
        if (sBgmRestartCountdown == 1)
        {
            func_0054d1a8(sChannels[0].handle, -0x32);
        }
        else
        {
            func_0054d1a8(sChannels[0].handle, -0x1E);
        }
        sprintf(name, "%s", sBgmAdxStrings[sChannels[channelIndex].id][0]);
        if (func_0054d130(sChannels[0].handle) != 0)
        {
            func_0054d118(sChannels[0].handle, 0);
        }
        if (sChannels[0].id == 0x3D)
        {
            func_0054d238(sChannels[0].handle, 1);
            func_0054d220(sChannels[0].handle, 1);
            func_0054d2b0(sChannels[0].handle, 10);
        }
        else
        {
            func_0054d238(sChannels[0].handle, 1);
            func_0054d220(sChannels[0].handle, 0x1E);
            func_0054d2b0(sChannels[0].handle, 0x37);
        }
        func_0054d0a0(sChannels[0].handle, name);
        func_0054d208(sChannels[0].handle, 1);
        sChannels[channelIndex].active = 1;
        sChannels[channelIndex].state = HSND_CHANNEL_STARTING;
        return;
    }

    channelOffset = channelIndex * sizeof(HsndChannel);
    handle = (void**)((char*)sChannels + channelOffset + 0x10);
    if (*handle != NULL)
    {
        func_0054d060(*handle);
        *handle = NULL;
    }

    sBackendControls[channelIndex].data18 = 0;
    sBackendControls[channelIndex].data20 = 0;
    sBackendControls[channelIndex].data1C = 0;
    sBackendControls[channelIndex].class = channelIndex == 2 ? 2 : 3;
    sBackendControls[channelIndex].flags = 2;
    sBackendControls[channelIndex].voiceCount = 2;
    sBackendControls[channelIndex].timeout = 0x5DC0;

    requestType = (s16*)((char*)sChannels + channelOffset + 0x14);
    switch (*requestType)
    {
        case HSND_START_NAMED_STREAM:
            sBackendControls[channelIndex].data20 = 0;
            sBackendControls[channelIndex].pending = 1;
            *handle = func_0054d030(&sBackendControls[channelIndex],
                                    sChannelData0[channelIndex],
                                    sChannelData1[channelIndex]);
            func_0054d238(*handle, 0);
            if (channelIndex == 4)
            {
                func_0054d220(*handle, 0x5A);
            }
            else
            {
                func_0054d220(*handle, 0);
            }
            func_0054d0a0(*handle, (char*)(requestType + 1));
            func_0054d208(*handle, 1);
            break;

        case HSND_START_BGM:
        case HSND_START_SE:
        case HSND_START_CDVD:
            if (channelIndex >= 2)
            {
                if (*requestType == HSND_START_CDVD)
                {
                    sBackendControls[channelIndex].data20 = 0;
                }
                sBackendControls[channelIndex].pending = 1;
                *handle = func_0054d030(&sBackendControls[channelIndex],
                                        sChannelData0[channelIndex],
                                        sChannelData1[channelIndex]);
                if (sBackendControls[channelIndex].data20 != 0)
                {
                    func_0054d328(*handle);
                }
                func_0054d238(*handle, 0);
                if (channelIndex == 4)
                {
                    func_0054d220(*handle, 0x5A);
                }
                else
                {
                    func_0054d220(*handle, 0);
                }
            }
            if (*requestType == HSND_START_CDVD)
            {
                func_0054d0b8(*handle, sChannels[channelIndex].modeArg.data,
                              sChannels[channelIndex].id);
            }
            else if (channelIndex == 0)
            {
                func_00102530(*handle, (char*)(requestType + 1));
            }
            else
            {
                func_001025c0(*handle, (char*)(requestType + 1));
            }
            func_0054d208(*handle, 1);
            break;

        case HSND_START_SE_WITH_PARAM:
        case HSND_START_STREAM_FADE:
            if (channelIndex >= 2)
            {
                sBackendControls[channelIndex].class =
                    channelIndex == 2 ? 2 : 3;
                sBackendControls[channelIndex].pending = 1;
                if (*requestType == HSND_START_STREAM_FADE)
                {
                    sBackendControls[channelIndex].data20 = 0;
                    sBackendControls[channelIndex].pending = 2;
                }
                *handle = func_0054d030(&sBackendControls[channelIndex],
                                        sChannelData0[channelIndex],
                                        sChannelData1[channelIndex]);
                if (sBackendControls[channelIndex].data20 != 0)
                {
                    func_0054d328(*handle);
                }
                func_0054d238(*handle, 0);
                if (channelIndex == 4)
                {
                    func_0054d220(*handle, 0x5A);
                }
                else
                {
                    func_0054d220(*handle, 0);
                }
            }
            func_0054d0d0(*handle, sChannelData0[channelIndex],
                          sChannelData1[channelIndex]);
            break;

        case HSND_START_STREAM:
            if (channelIndex >= 2)
            {
                sBackendControls[channelIndex].class = 3;
                sBackendControls[channelIndex].pending = 2;
                sBackendControls[channelIndex].data20 = 0;
                *handle = func_0054d030(&sBackendControls[channelIndex],
                                        sChannelData0[channelIndex],
                                        sChannelData1[channelIndex]);
                if (sBackendControls[channelIndex].data20 != 0)
                {
                    func_0054d328(*handle);
                }
                func_0054d238(*handle, 0);
                if (channelIndex == 4)
                {
                    func_0054d220(*handle, 0x5A);
                }
                else
                {
                    func_0054d220(*handle, 0);
                }
            }
            func_0054d0e8(*handle, sChannels[channelIndex].modeData,
                          sChannels[channelIndex].modeArg.parameter);
            break;

        default:
            break;
    }

    sChannels[channelIndex].active = 1;
    sChannels[channelIndex].state = HSND_CHANNEL_STARTING;
}

// FUN_001099A0
s16 func_001099a0(void)
{
    if (sChannels[0].active == false)
    {
        return HSND_BGM_NONE;
    }

    return sChannels[0].id;
}

// FUN_001099D0
u8 H_Snd_PlayBgm(s16 id, s32 unused)
{
    s32 current;

    (void)unused;
    if (sChannels[0].active == false)
    {
        current = HSND_BGM_NONE;
    }
    else
    {
        current = sChannels[0].id;
    }

    if (id != current)
    {
        func_0054d208(sChannels[0].handle, true);
        sChannels[0].gate = false;
        sChannels[0].active = true;
        sChannels[0].state = HSND_CHANNEL_STARTING;
        sChannels[0].previousId = sChannels[0].id;
        sChannels[0].id = id;
        sChannels[0].requestType = HSND_START_BGM;
        sprintf(sChannels[0].name, "%s", sBgmAdxStrings[id][0]);

        if (datGetFlag(0x141E) != 0)
        {
            return true;
        }
        H_Snd_00109180(0);
    }

done:
    return true;
}

// FUN_00109AE0 NONMATCHING
void H_Snd_FUN_00109ae0(s32 slotIndex, void* data0, u32 data0Size, void* data1,
                         u32 data1Size, void* data2, u32 data2Size)
{
    if (H_Snd_FUN_00109df0(slotIndex) != 0)
    {
        s16 index = (s16)slotIndex;
        sSlotWork[index].param2 = 0x3E7;
    }
    else
    {
        if (sSlotWork[(s16)slotIndex].state == HSND_CHANNEL_RELEASING)
        {
            K_Assert(__FILE__, 0x32C);
        }
    }

    sSlotWork[(s16)slotIndex].callbackMode = true;
    sSlotWork[(s16)slotIndex].completed = false;
    sSlotWork[(s16)slotIndex].param1 = slotIndex;
    sSlotWork[(s16)slotIndex].param2 = 0x3E7;
    ((HsndSlotWork *)sSlotWork_alt)[(s16)slotIndex].state = 2;
    sSlotWork[(s16)slotIndex].data0 = data0;
    sSlotWork[(s16)slotIndex].data1 = data1;
    sSlotWork[(s16)slotIndex].data2 = data2;
    sSlotWork[(s16)slotIndex].data3 = data0Size;
    sSlotWork[(s16)slotIndex].data4 = data1Size;
    sSlotWork[(s16)slotIndex].data5 = data2Size;
}
// FUN_00109CA0
u8 H_Snd_FUN_00109ca0(s16 slotIndex, s16 parameter)
{
    if (H_Snd_FUN_00109df0_s16(slotIndex) != 0)
    {
        if (parameter == sSlotWork[slotIndex].param2)
        {
            return true;
        }
    }
    else
    {
        if (sSlotWork[slotIndex].state == HSND_CHANNEL_RELEASING && parameter != sSlotWork[slotIndex].param2)
        {
            K_Assert(__FILE__, 0x34B);
        }
    }

    sSlotWork[slotIndex].callbackMode = false;
    sSlotWork[slotIndex].completed = false;
    sSlotWork[slotIndex].param1 = slotIndex;
    sSlotWork[slotIndex].param2 = parameter;
    sSlotWork[slotIndex].state = 2;
    return true;
}

// FUN_00109DF0
u32 H_Snd_FUN_00109df0(s32 slotIndex)
{
    s16 index;

    index = slotIndex;
    return sSlotWork[index].state == HSND_CHANNEL_STARTING;
}

// FUN_00109E30
void func_00109e30(s16 channelIndex)
{
    s16 original;
    s16 normalized;

    original = channelIndex;
    normalized = channelIndex;
    if (sChannels[original].active != false)
    {
        func_0054d220(sChannels[original].handle, 10);
        if (normalized < 2)
        {
            if (sChannels[original].active != false)
            {
                func_0054d100(sChannels[original].handle);
                sChannels[original].state = HSND_CHANNEL_INACTIVE;
                sChannels[original].active = false;
                sChannels[original].id = HSND_BGM_NONE;
            }
        }
        else
        {
            if (sChannels[original].active != false)
            {
                func_0054d100(sChannels[original].handle);
                sChannels[original].state = HSND_CHANNEL_INACTIVE;
                sChannels[original].active = false;
                sChannels[original].id = HSND_BGM_NONE;
            }
        }
    }
}

// FUN_00109F60
u8 func_00109f60(s16 channelIndex, s16 mappedChannelIndex)
{
    s32 index;
    s16 mappedIndex;
    
    mappedIndex = mappedChannelIndex;
    index = channelIndex;
    if (index < HSND_CHANNEL_COUNT)
    {
        if (index < 2)
        {
            if (sChannels[index].active != false)
            {
                func_0054d100(sChannels[index].handle);
                sChannels[index].state = HSND_CHANNEL_INACTIVE;
                sChannels[index].active = false;
                sChannels[index].id = HSND_BGM_NONE;
            }
        }
        else
        {
            if (sChannels[index].active != false)
            {
                func_0054d100(sChannels[index].handle);
                sChannels[index].state = HSND_CHANNEL_INACTIVE;
                sChannels[index].active = false;
                sChannels[index].id = HSND_BGM_NONE;
            }
        }
    }
    else
    {
        return true;
    }

    sChannels[sChannelMap[mappedIndex][0]].active = false;
    sChannels[sChannelMap[mappedIndex][0]].state = HSND_CHANNEL_INACTIVE;
    return true;
}

// FUN_0010A0E0
void H_Snd_FUN_0010a0e0(s16 bank, s16 cue)
{
    func_0010da70(bank, cue);
}

// FUN_0010A100
void func_0010a100(s16 channelIndex, s32 unused, s32 fadeFrames)
{
    (void)unused;
    if (channelIndex < HSND_CHANNEL_COUNT)
    {
        if (sChannels[channelIndex].active != false)
        {
            func_0054d220(sChannels[channelIndex].handle, fadeFrames);

            if (channelIndex < 2)
            {
                if (sChannels[channelIndex].active != false)
                {
                    func_0054d100(sChannels[channelIndex].handle);
                    sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
                    sChannels[channelIndex].active = false;
                    sChannels[channelIndex].id = HSND_BGM_NONE;
                }
            }
            else
            {
                if (sChannels[channelIndex].active != false)
                {
                    func_0054d100(sChannels[channelIndex].handle);
                    sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
                    sChannels[channelIndex].active = false;
                    sChannels[channelIndex].id = HSND_BGM_NONE;
                }
            }
        }
    }
}

// FUN_0010A240
u8 func_0010a240(s16 channelIndex, void* streamData, s16 parameter)
{
    if (channelIndex < HSND_CHANNEL_COUNT)
    {
        sChannels[channelIndex].active = true;
        sChannels[channelIndex].modeArg.parameter = parameter;
        sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
        sChannels[channelIndex].startMode = HSND_START_STREAM;
        sChannels[channelIndex].modeData = streamData;
        H_Snd_00109180(channelIndex);
    }

    return true;
}

// FUN_0010A2E0
u8 func_0010a2e0(void* streamData, s32 channelIndex, u16 id)
{
    sChannels[channelIndex].active = true;
    sChannels[channelIndex].id = id;
    sChannels[channelIndex].modeArg.data = streamData;
    sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
    sChannels[channelIndex].startMode = HSND_START_CDVD;
    H_Snd_00109180(channelIndex);

    return true;
}

// FUN_0010A370
u8 func_0010a370(s16 channelIndex, const char* name)
{
    if (channelIndex < HSND_CHANNEL_COUNT)
    {
        sChannels[channelIndex].active = true;
        sChannels[channelIndex].id = 0;
        sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
        sChannels[channelIndex].startMode = HSND_START_BGM;
        strcpy(sChannels[channelIndex].name, name);
        H_Snd_00109180(channelIndex);
    }

    return true;
}

// FUN_0010A410
u8 func_0010a410(s16 channelIndex, const char* name)
{
    char path[256];

    if (channelIndex < HSND_CHANNEL_COUNT)
    {
        sprintf(path, "%s", name);
        sChannels[channelIndex].active = true;
        sChannels[channelIndex].id = 0;
        sChannels[channelIndex].state = HSND_CHANNEL_INACTIVE;
        sChannels[channelIndex].startMode = HSND_START_NAMED_STREAM;
        strcpy(sChannels[channelIndex].name, path);
        H_Snd_00109180(channelIndex);
    }

    return true;
}

// FUN_0010A4E0
void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan)
{
    func_0010db60(bank, cue, variant, pan);
}

// FUN_0010A500
s32 func_0010a500(s16 channelIndex)
{
    s16 index;
    s32 result;

    index = channelIndex;
    if (index == 5)
    {
        return false;
    }

    if (index >= 2)
    {
        if (sChannels[index].active != false)
        {
            result = func_0054d148(sChannels[index].handle) != 3;
            return result;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// FUN_0010A5A0
void* H_Snd_StreamTaskUpdate(KwlnTask* task)
{
    HsndStreamTaskWork* work;
    char filename[256];
    s32 status;

    work = task->workData;
    switch (work->state)
    {
        case 0:
            work->completedFrames = 0;
            sprintf(filename, "sound/v%03d%03d.afs", work->namePart0, work->namePart1);
            if (work->callback == NULL)
            {
                func_001024a0(work->source, filename, false, D_007E39F0);
            }
            else
            {
                func_001024a0(work->source, filename, false, work->callback);
            }
            work->state = 1;
            break;

        case 1:
            work->completedFrames++;
            status = func_0053c268(work->source);
            if (status == 4)
            {
                work->state = 0;
            }
            else if (status == 3)
            {
                printf("##### AFS =[%03d:%03d]  : TIME[%d] \n", work->namePart0,
                       work->namePart1, work->completedFrames);
                work->state = 2;
            }
            break;

        case 2:
            break;

        default:
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0010A6D0
void H_Snd_StreamTaskDestroy(KwlnTask* task)
{
    HsndStreamTaskWork* work;

    work = task->workData;
    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    RwFree(work);
}

// FUN_0010A720
u8 H_Snd_StreamTaskIsFinished(KwlnTask* task)
{
    HsndStreamTaskWork* work;

    work = task->workData;
    if (work->state == 2)
    {
        kwlnTaskDestroyWithHierarchy(task);
        return true;
    }

    return false;
}

// FUN_0010A770
KwlnTask* H_Snd_CreateStreamTask(KwlnTask* parent, void* source, void* callback, void* arg0,
                                 s32 namePart0, s32 namePart1)
{
    HsndStreamTaskWork* work;
    KwlnTask* task;

    work = HSND_ALLOC(1, 0x24, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, "H_AfsSetProc", 0x18BF, H_Snd_StreamTaskUpdate,
                          H_Snd_StreamTaskDestroy, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->arg0 = arg0;
    work->namePart0 = namePart0;
    work->namePart1 = namePart1;
    work->source = source;
    work->callback = callback;
    return task;
}
