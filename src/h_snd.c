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



static HsndChannel sChannels[HSND_CHANNEL_COUNT];
static HsndSlotWork sSlotWork[HSND_SLOT_COUNT];
static HsndBackendControl sBackendControls[HSND_CHANNEL_COUNT];
static s16 sBgmRestartCountdown;
static void* sChannelData0[HSND_CHANNEL_COUNT];
static void* sChannelData1[HSND_CHANNEL_COUNT];
static void* sChannelData2[HSND_CHANNEL_COUNT];
static void* sChannelData3[HSND_CHANNEL_COUNT];
static s16 sChannelMap[HSND_CHANNEL_COUNT];

/* Retail D_005D4014: BGM id is the direct 12-byte-record index. */
static const char* const sBgmAdxStrings[116] =
{
    "01.ADX", "01.ADX", "26.ADX", NULL, "26.ADX", "26.ADX", "26.ADX", NULL,
    "26.ADX", NULL, "26.ADX", NULL, "26.ADX", NULL, "26.ADX", NULL,
    "26.ADX", NULL, "26.ADX", "19.ADX", "20.ADX", "21.ADX", "22.ADX", "23.ADX",
    "24.ADX", "25.ADX", "26.ADX", "27.ADX", "28.ADX", "29.ADX", "30.ADX", "31.ADX",
    "32.ADX", "26.ADX", "26.ADX", "35.ADX", "36.ADX", "37.ADX", "38.ADX", "39.ADX",
    "40.ADX", "THEME.ADX", "THEME.ADX", "43.ADX", "44.ADX", "45.ADX", "46.ADX", "THEME.ADX",
    "THEME.ADX", "THEME.ADX", "50.ADX", "51.ADX", "52.ADX", "53.ADX", "54.ADX", "55.ADX",
    "56.ADX", "THEME.ADX", "THEME.ADX", "THEME.ADX", "60.ADX", "61.ADX", "62.ADX", "63.ADX",
    "THEME.ADX", "THEME.ADX", "THEME.ADX", "THEME.ADX", "THEME.ADX", "THEME.ADX", "70.ADX", "71.ADX",
    "72.ADX", "73.ADX", "74.ADX", "75.ADX", "76.ADX", "77.ADX", "78.ADX", "79.ADX",
    "80.ADX", "81.ADX", "82.ADX", "83.ADX", "84.ADX", "85.ADX", "86.ADX", "87.ADX",
    "88.ADX", "89.ADX", "90.ADX", "91.ADX", "92.ADX", "93.ADX", "94.ADX", "95.ADX",
    "96.ADX", "97.ADX", "98.ADX", "99.ADX", "100.ADX", "101.ADX", "102.ADX", "103.ADX",
    "104.ADX", "105.ADX", "106.ADX", "107.ADX", "108.ADX", "109.ADX", "110.ADX", "111.ADX",
    "112.ADX", "113.ADX", "114.ADX", "115.ADX",
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

#define HSND_BACKEND_ALLOC(context, flags) \
    (*(void* (**)(void*, u32))D_00960178)((context), (flags))

// FUN_00108740 NONMATCHING
void func_00108740(void)
{
    void* context;
    void* backendData;
    s32 i;

    sSndInitParams.outputLevel = DAT_007cad28;
    sSndInitParams.enabled = true;
    sSndInitParams.initialized = true;
    sSndInitParams.reserved = 0;
    func_0057f768(&sSndInitParams);
    func_0054cfe8();
    func_0054d468();
    func_005497b0(30);

    memset(&sBackendControls[0], 0, sizeof(HsndBackendControl));
    sBackendControls[0].flags = 3;
    sBackendControls[0].voiceCount = 2;
    sBackendControls[0].timeout = 0xBB80;
    sBackendControls[0].pending = 1;
    sBackendControls[0].class = 1;
    context = func_0054d080(&sBackendControls[0]);
    backendData = HSND_BACKEND_ALLOC(context, 0x40000);
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
    sBackendControls[2].flags = 3;
    sBackendControls[2].voiceCount = 1;
    sBackendControls[2].timeout = 0x5DC0;
    sBackendControls[2].pending = 1;
    sBackendControls[2].class = 2;
    context = func_0054d080(&sBackendControls[2]);
    sChannelData0[2] = HSND_BACKEND_ALLOC(context, 0x40000);
    sChannelData1[2] = context;

    memset(&sBackendControls[3], 0, sizeof(HsndBackendControl));
    sBackendControls[3].flags = 2;
    sBackendControls[3].voiceCount = 2;
    sBackendControls[3].timeout = 0x5DC0;
    sBackendControls[3].pending = 1;
    sBackendControls[3].class = 3;
    context = func_0054d080(&sBackendControls[3]);
    sChannelData0[3] = HSND_BACKEND_ALLOC(context, 0x40000);
    sChannelData1[3] = context;

    memset(&sBackendControls[4], 0, sizeof(HsndBackendControl));
    sBackendControls[4].flags = 2;
    sBackendControls[4].voiceCount = 2;
    sBackendControls[4].timeout = 0x5DC0;
    sBackendControls[4].pending = 1;
    sBackendControls[4].class = 3;
    context = func_0054d080(&sBackendControls[4]);
    sChannelData0[4] = HSND_BACKEND_ALLOC(context, 0x40000);
    sChannelData1[4] = context;

    memset(sSlotWork, 0, sizeof(sSlotWork));
    for (i = 0; i < HSND_CHANNEL_COUNT; i++)
    {
        sChannels[i].active = false;
        sChannels[i].state = HSND_CHANNEL_INACTIVE;
        sChannels[i].id = HSND_BGM_NONE;
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
extern void* D_007E39F0;
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
    s32 i;
    HsndChannel* bgm;
    HsndChannel* channel;
    s32 status;

    func_00540ec0();
    func_0051db00(3, 0x80, 0x7F, 0x7F);

    for (i = 0; i < HSND_SLOT_COUNT; i++)
    {
        func_00108e80(&sSlotWork[i]);
    }

    bgm = &sChannels[0];
    if (bgm->active != false)
    {
        if (bgm->gate != false && sBgmRestartCountdown != 0)
        {
            sBgmRestartCountdown--;
            if (sBgmRestartCountdown == 0)
            {
                func_0054d118(bgm->handle, true);
            }
        }

        func_0054d3a8(bgm->handle, false);
        status = func_0054d148(bgm->handle);
        if (status == 3)
        {
            bgm->active = false;
        }
        else if (status == 4)
        {
            func_00109070(0);
            H_Snd_00109180(0);
            func_0054d208(bgm->handle, true);
        }
    }

    for (i = 2; i < HSND_CHANNEL_COUNT; i++)
    {
        channel = &sChannels[i];
        if (channel->active == false)
        {
            continue;
        }

        status = func_0054d148(channel->handle);
        if (status == 3)
        {
            channel->active = false;
        }
        else if (status == 4)
        {
            func_00109070(i);
            H_Snd_00109180(i);
            func_0054d208(channel->handle, true);
        }
        else if (channel->state == HSND_CHANNEL_STARTING)
        {
            func_0054d100(channel->handle);
            channel->state = HSND_CHANNEL_PLAYING;
        }
        else if (channel->state == HSND_CHANNEL_PLAYING)
        {
            H_Snd_00109180(i);
            channel->state = HSND_CHANNEL_PLAYING;
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
u8 func_00109040(s16 id)
{
    H_Snd_PlayBgm(id, true);
    return true;
}

// FUN_00109070 NONMATCHING
u8 func_00109070(s16 channelIndex)
{
    HsndChannel* channel;

    channel = H_Snd_GetChannel(channelIndex);
    if (channel != NULL && channel->active != false)
    {
        func_0054d100(channel->handle);
        H_Snd_ClearChannel(channel);
    }

    return true;
}

// FUN_00109170
u8 func_00109170(void)
{
    /* The retail hook intentionally reports that no optional backend exists. */
    return false;
}

// FUN_00109180 NONMATCHING
void H_Snd_00109180(s32 channelIndex)
{
    HsndChannel* channel;
    HsndBackendControl* control;
    const char* name;

    channel = H_Snd_GetChannel(channelIndex);
    if (channel == NULL)
    {
        return;
    }

    if (channelIndex == 0)
    {
        /* BGM uses the first word of the retail D_005D4014 record. */
        func_0054d1a8(channel->handle, -0x1E);
        if (func_0054d130(channel->handle) != 0)
        {
            func_0054d118(channel->handle, false);
        }

        name = sBgmAdxStrings[channel->id];
        sprintf(channel->name, "%s", name);
        func_0054d238(channel->handle, true);
        if (channel->id == 0x3D)
        {
            H_Snd_ApplyChannelFade(channel, 1);
            func_0054d2b0(channel->handle, 10);
        }
        else
        {
            H_Snd_ApplyChannelFade(channel, 0x1E);
            func_0054d2b0(channel->handle, 0x37);
        }
        func_0054d0a0(channel->handle, channel->name);
        func_0054d208(channel->handle, true);
        channel->active = true;
        channel->state = HSND_CHANNEL_STARTING;
        return;
    }

    if (channel->handle != NULL)
    {
        func_0054d060(channel->handle);
        channel->handle = NULL;
    }

    /* D_007E42E0 + channel * 0x28 is initialized before every request. */
    control = &sBackendControls[channelIndex];
    memset(control, 0, sizeof(HsndBackendControl));
    control->flags = 2;
    control->voiceCount = 2;
    control->timeout = 0x5DC0;
    control->class = channelIndex == 2 ? 2 : 3;
    if (channelIndex == 2)
    {
        control->flags = 3;
        control->voiceCount = 1;
    }

    switch (channel->startMode)
    {
        case HSND_START_BGM:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            func_0054d238(channel->handle, false);
            break;

        case HSND_START_SE:
        case HSND_START_SE_WITH_PARAM:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            if (sChannelData3[channelIndex] != NULL)
            {
                func_0054d328(channel->handle);
            }
            func_0054d238(channel->handle, false);
            H_Snd_ApplyChannelFade(channel, channelIndex == 4 ? 0x5A : 0);
            break;

        case HSND_START_STREAM:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            func_0054d238(channel->handle, false);
            H_Snd_ApplyChannelFade(channel, channelIndex == 4 ? 0x5A : 0);
            func_0054d0e8(channel->handle, channel->modeData, channel->modeArg.parameter);
            break;

        case HSND_START_STREAM_FADE:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            func_0054d0d0(channel->handle, sChannelData0[channelIndex],
                           sChannelData1[channelIndex]);
            break;

        case HSND_START_CDVD:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            func_0054d0b8(channel->handle, channel->modeArg.data, channel->id);
            break;

        case HSND_START_NAMED_STREAM:
            channel->handle = func_0054d030(control, sChannelData0[channelIndex],
                                             sChannelData1[channelIndex]);
            if (channelIndex == 0)
            {
                func_00102530(channel->handle, channel->name);
            }
            else
            {
                func_001025c0(channel->handle, channel->name);
            }
            break;

        default:
            break;
    }

    func_0054d208(channel->handle, true);
    channel->active = true;
    channel->state = HSND_CHANNEL_STARTING;
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

// FUN_001099D0 NONMATCHING
u8 H_Snd_PlayBgm(s16 id, s32 unused)
{
    HsndChannel* bgm;

    (void)unused;
    bgm = &sChannels[0];
    if (id != H_Snd_GetCurrentBgmId())
    {
        func_0054d208(bgm->handle, true);
        bgm->gate = false;
        bgm->active = true;
        bgm->state = HSND_CHANNEL_STARTING;
        bgm->previousId = bgm->id;
        bgm->id = id;
        bgm->requestType = HSND_START_BGM;
        sprintf(bgm->name, "%s", sBgmAdxStrings[id]);

        if (datGetFlag(0x141E) == false)
        {
            H_Snd_00109180(0);
        }
    }

    return true;
}

// FUN_00109AE0 NONMATCHING
void H_Snd_FUN_00109ae0(s32 slotIndex, void* data0, u32 data0Size, void* data1,
                         u32 data1Size, void* data2, u32 data2Size)
{
    HsndSlotWork* slot;

    if (H_Snd_FUN_00109df0(slotIndex) != 0)
    {
        sSlotWork[slotIndex].param2 = 0x3E7;
        return;
    }

    slot = &sSlotWork[slotIndex];
    if (slot->state == HSND_CHANNEL_PLAYING && slot->param2 != 0x3E7)
    {
        K_Assert(__FILE__, 0x32C);
    }

    slot->callbackMode = true;
    slot->completed = false;
    slot->param1 = slotIndex;
    slot->param2 = 0x3E7;
    slot->state = 2;
    slot->data0 = data0;
    slot->data3 = data0Size;
    slot->data1 = data1;
    slot->data4 = data1Size;
    slot->data2 = data2;
    slot->data5 = data2Size;
}

// FUN_00109CA0 NONMATCHING
u8 H_Snd_FUN_00109ca0(s16 slotIndex, s16 parameter)
{
    HsndSlotWork* slot;

    slot = &sSlotWork[slotIndex];
    if (H_Snd_FUN_00109df0(slotIndex) != 0)
    {
        return parameter == slot->param2;
    }

    if (slot->state == HSND_CHANNEL_PLAYING && parameter != slot->param2)
    {
        K_Assert(__FILE__, 0x34B);
    }

    slot->callbackMode = false;
    slot->completed = false;
    slot->param1 = slotIndex;
    slot->param2 = parameter;
    slot->state = 2;
    return true;
}

// FUN_00109DF0
u32 H_Snd_FUN_00109df0(s32 slotIndex)
{
    s16 index;

    index = slotIndex;
    return sSlotWork[index].state == HSND_CHANNEL_STARTING;
}

// FUN_00109E30 NONMATCHING
void func_00109e30(s16 channelIndex)
{
    HsndChannel* channel;
    s16 index;

    index = channelIndex;
    if (index < HSND_CHANNEL_COUNT)
    {
        channel = &sChannels[index];
        if (channel->active != false)
        {
            func_0054d220(channel->handle, 10);

            if (index < 2)
            {
                if (channel->active != false)
                {
                    func_0054d100(channel->handle);
                    channel->state = HSND_CHANNEL_INACTIVE;
                    channel->active = false;
                    channel->id = HSND_BGM_NONE;
                }
            }
            else
            {
                if (channel->active != false)
                {
                    func_0054d100(channel->handle);
                    channel->state = HSND_CHANNEL_INACTIVE;
                    channel->active = false;
                    channel->id = HSND_BGM_NONE;
                }
            }
        }
    }
}

// FUN_00109F60 NONMATCHING
u8 func_00109f60(s16 channelIndex, s16 mappedChannelIndex)
{
    HsndChannel* channel;
    HsndChannel* mappedChannel;

    channel = H_Snd_GetChannel(channelIndex);
    if (channelIndex >= HSND_CHANNEL_COUNT)
    {
        return true;
    }

    if (channel != NULL && channel->active != false)
    {
        func_0054d100(channel->handle);
        H_Snd_ClearChannel(channel);
    }

    mappedChannel = H_Snd_GetChannel(sChannelMap[mappedChannelIndex]);
    if (mappedChannel != NULL)
    {
        mappedChannel->active = false;
        mappedChannel->state = HSND_CHANNEL_INACTIVE;
    }

    return true;
}

// FUN_0010A0E0
void H_Snd_FUN_0010a0e0(s16 bank, s16 cue)
{
    func_0010da70(bank, cue);
}

// FUN_0010A100 NONMATCHING
void func_0010a100(s16 channelIndex, s32 unused, s32 fadeFrames)
{
    HsndChannel* channel;

    (void)unused;
    channel = H_Snd_GetChannel(channelIndex);
    if (channel != NULL && channel->active != false)
    {
        H_Snd_ApplyChannelFade(channel, fadeFrames);
        func_0054d100(channel->handle);
        H_Snd_ClearChannel(channel);
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
u8 func_0010a2e0(void* streamData, s32 channelIndex, s16 id)
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

// FUN_0010A5A0 NONMATCHING
void* H_Snd_StreamTaskUpdate(KwlnTask* task)
{
    HsndStreamTaskWork* work;
    char filename[256];
    s32 status;

    work = task->workData;
    switch (work->state)
    {
        case 2:
            break;

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
