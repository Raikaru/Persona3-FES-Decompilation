#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"
#include "rw/rwcore.h"
#include "libm.h"

static u32* sSflPanel; // DAT_007ce318
/* This owner begins at 0x0023D7A0; 0x0023F480 switches to bi_main.c/DAT_007CE31C. */

extern int DAT_0068e800[];
extern float DAT_0068e810[];
extern float DAT_0068e820[];
extern int DAT_0068e830[];
extern int DAT_0068e834[];
extern float DAT_0068e840[];
extern float DAT_0068e844[];
extern float DAT_0068e850[];
extern float DAT_0068e854[];
extern float DAT_0068e858;
extern float DAT_007cad78;
extern float DAT_007cae0c;
extern float DAT_007caf38;
extern float DAT_007cb034;
typedef int (*code)(...);
extern code DAT_00960090[];
extern code DAT_0096009c[];
#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];
#pragma alias DAT_0096009c_abs DAT_0096009c
extern u8 DAT_0096009c_abs[];
void func_0021d890();
void func_0021d8e0();
void func_0021d950();
void func_0021e170();
void func_0021eb80();
void func_004cb750();
u32 func_00255130();
void scrClearTextBox();
float sinf(float);
float cosf(float);
void func_0023dac0(void);

// FUN_0023D7A0
void func_0023d7a0(u32* work)
{
    work[0] = 0;
    sSflPanel = work;
}

// FUN_0023D7B0
void func_0023d7b0(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    sSflPanel = NULL;
}

// FUN_0023D7F0
void func_0023d7f0(void)
{
    u32* work;
    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    work[1] = 3;
    K_ASSERT(~*work & 1, 0x9c);
    *work |= 1;
}

// FUN_0023D870
void sflPanel0023d870(void)
{
    u32* work;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    K_ASSERT(*work & 1, 0xa3);
    *work &= 0xfffffffe;
}

// FUN_0023d8f0
void func_0023d8f0(void)
{
    u32* work;
    float t;
    RwV3d cameraOffset;
    float scale;
    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    K_ASSERT(*work & 1, 0xb2);

    switch (work[1]) {
    case 0:
        if ((s32)work[2] < 0x32) {
            work[2]++;
        } else {
            *work &= 0xfffffffd;
        }
        break;
    case 1:
        if ((s32)work[2] < 0x1e) {
            work[2]++;
        } else {
            *work &= 0xfffffffd;
        }
        break;
    case 2:
        if ((s32)work[2] < 0x1e) {
            work[2]++;
        } else {
            *work &= 0xfffffffd;
        }
        break;
    }
    func_0023dac0();
    scale = 200.0f;

    switch (work[1]) {
    case 0:
        if ((s32)work[2] < 0x32) {
            t = (float)((s32)work[2] + 1) / 50.0f;
            t = t * scale - t * (t * 100.0f) - 100.0f;
            cameraOffset.x = 0.0f;
            cameraOffset.y = 0.0f;
            cameraOffset.z = t;
            func_004cb750(kwlnGetMainCamera()->object.object.parent, &cameraOffset, 0);
        }
        break;
    default:
        break;
    }
}

// FUN_0023dac0 NONMATCHING
void func_0023dac0(void)
{
    u32* work;
    RwRGBA color;
    float panelPosition[2];
    float panelDirection[2];
    float panelSize[2];
    float quad[8];
    float alpha;
    float scale;
    float angle;
    float xOffset;
    int frame;
    int i;
    int j;
    int interval;
    int mode;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    mode = work[1];
    if (mode == 2 || mode == 1) {
        goto mode12;
    }
    switch (mode) {
    case 0:
    {
        int mode0_i;
        frame = work[2];
        if (frame < 4) {
            xOffset = 526.0f;
        } else if (frame < 8) {
            scale = (float)(frame - 4) / 4.0f;
            xOffset = 526.0f;
            scale = 1.0f - scale;
            xOffset *= scale;
        } else {
            xOffset = 0.0f;
        }
        if (frame < 0x1a) {
            alpha = 1.0f;
        } else {
            alpha = (float)(frame - 0x1a) / 24.0f;
            alpha = 1.0f - alpha;
        }

        quad[0] = 0.0f;
        quad[1] = 0.0f;
        quad[2] = 174.0f;
        quad[3] = 0.0f;
        quad[4] = 174.0f;
        quad[5] = 32.0f;
        quad[6] = 0.0f;
        quad[7] = 32.0f;
        for (mode0_i = 0; mode0_i < 4; mode0_i++) {
        }
        mode0_i = 0;
        xOffset += 114.0f;
        for (; mode0_i < 4; mode0_i++) {
            quad[mode0_i * 2] += xOffset;
            quad[mode0_i * 2 + 1] += 59.0f;
        }
        func_0021d8e0(work + 0x44, quad);
        color.r = 0xff;
        color.g = 0xff;
        color.b = 0xff;
        color.a = (unsigned char)(alpha * 255.0f);
        func_0021d950(work + 0x44, &color);

        frame = work[2];
        if (frame < 4) {
            scale = (float)frame / 4.0f;
            xOffset = 614.0f;
            scale = 1.0f - scale;
            xOffset *= scale;
        } else {
            xOffset = 0.0f;
        }
        if (frame < 0x1a) {
            alpha = 1.0f;
        } else {
            alpha = (float)(frame - 0x1a) / 24.0f;
            alpha = 1.0f - alpha;
        }
        quad[0] = 0.0f;
        quad[1] = 0.0f;
        quad[2] = 64.0f;
        quad[3] = 0.0f;
        quad[4] = 64.0f;
        quad[5] = 64.0f;
        quad[6] = 0.0f;
        quad[7] = 64.0f;
        scale = DAT_007cae0c;
        for (mode0_i = 0; mode0_i < 4; mode0_i++) {
            quad[mode0_i * 2] *= scale;
            quad[mode0_i * 2 + 1] *= scale;
        }
        mode0_i = 0;
        xOffset += 26.0f;
        for (; mode0_i < 4; mode0_i++) {
            quad[mode0_i * 2] += xOffset;
            quad[mode0_i * 2 + 1] += 65.0f;
        }
        func_0021d890(work + 4, quad);
        color.a = (unsigned char)(alpha * 255.0f);
        func_0021d950(work + 4, &color);
    }
    goto done;
    default:
        return;
    }

mode12:
    frame = work[2];

    for (i = 0; i < 2; i++) {
        switch (i) {
        case 0:
            panelDirection[0] = 0.0f;
            panelDirection[1] = -1.0f;
            scale = 1.0f;
            if (frame == 0x1e) {
                interval = 3;
            } else {
                interval = -1;
                for (j = 0; j < 4; j++) {
                    if (frame < DAT_0068e800[j]) {
                        interval = j - 1;
                        break;
                    }
                }
            }
            K_ASSERT(interval >= 0, 0x1b7);
            K_ASSERT(interval < 4, 0x1b8);
            K_ASSERT(interval >= 0, 0x1bb);
            K_ASSERT(interval < 4, 0x1bc);
            alpha = (float)(frame - DAT_0068e800[interval]) /
                    (float)(DAT_0068e800[interval + 1] - DAT_0068e800[interval]);
            panelPosition[0] = alpha * (DAT_0068e820[interval + 1] - DAT_0068e820[interval]) +
                               DAT_0068e820[interval];
            scale = alpha * (DAT_0068e810[interval + 1] - DAT_0068e810[interval]) +
                    DAT_0068e810[interval];
            break;
        case 1:
            if (frame == 0x1e) {
                interval = 2;
                scale = DAT_0068e858;
            } else {
                interval = -1;
                for (j = 0; j < 3; j++) {
                    if (frame < DAT_0068e830[j]) {
                        interval = j - 1;
                        break;
                    }
                }
                scale = 1.0f;
            }
            K_ASSERT(interval >= 0, 0x1d8);
            K_ASSERT(interval >= 0, 0x1db);
            K_ASSERT(interval < 3, 0x1dc);
            alpha = (float)(frame - DAT_0068e830[interval]) /
                    (float)(DAT_0068e834[interval] - DAT_0068e830[interval]);
            panelPosition[0] = alpha * (DAT_0068e840[interval + 1] - DAT_0068e840[interval]) +
                               DAT_0068e840[interval];
            angle = DAT_007caf38 *
                    (alpha * (DAT_0068e850[interval + 1] - DAT_0068e850[interval]) +
                     DAT_0068e850[interval]) /
                    360.0f * 2.0f;
            panelDirection[0] = sinf(angle);
            panelDirection[1] = -cosf(angle);
            break;
        }
        panelPosition[1] = 224.0f;
        panelSize[0] = scale * 690.0f;
        panelSize[1] = scale * 488.0f;
        func_0021e170(work + 0x84 + i * 0x40, panelPosition, panelDirection, panelSize);
        color.a = (unsigned char)(panelPosition[0] * 255.0f);
        color.r = 0xff;
        color.g = 0xff;
        color.b = 0xff;
        func_0021d950(work + 0x84 + i * 0x40, &color);
    }

    panelDirection[0] = sinf(DAT_007cb034);
    panelDirection[1] = -cosf(DAT_007cb034);
    panelPosition[0] = 320.0f;
    panelPosition[1] = 182.0f;
    if (mode == 1) {
        panelSize[0] = 463.0f;
    } else {
        panelSize[0] = 510.0f;
    }
    panelSize[1] = 89.0f;

    if (frame < 7) {
        scale = DAT_007cad78 * (1.0f - (float)frame / 7.0f) + 1.0f;
        alpha = (float)frame / 7.0f;
    } else {
        scale = 1.0f;
        if (frame < 0xf) {
            alpha = 1.0f - (float)(frame - 7) / 8.0f;
        } else {
            alpha = 0.0f;
        }
    }
    panelSize[0] *= scale;
    panelSize[1] *= scale;
    func_0021e170(work + 0x104, panelPosition, panelDirection, panelSize);
    color.a = (unsigned char)(alpha * 255.0f);
    func_0021d950(work + 0x104, &color);

    if (frame < 7) {
        alpha = 0.0f;
    } else if (frame < 0xf) {
        alpha = (float)(frame - 7) / 8.0f;
    } else if (frame < 0x16) {
        alpha = 1.0f;
    } else {
        alpha = 1.0f - (float)(frame - 0x16) / 8.0f;
    }
    panelDirection[0] = sinf(DAT_007cb034);
    panelDirection[1] = -cosf(DAT_007cb034);
    panelSize[0] = mode == 1 ? 463.0f : 510.0f;
    panelSize[1] = 89.0f;
    func_0021e170(work + 0x144, panelPosition, panelDirection, panelSize);
    color.a = (unsigned char)(alpha * 255.0f);
    func_0021d950(work + 0x144, &color);

    if (frame < 7) {
        scale = 1.0f;
        alpha = 0.0f;
    } else if (frame < 0xf) {
        scale = DAT_007cad78 * (1.0f - (float)(frame - 7) / 8.0f) + 1.0f;
        alpha = (float)(frame - 7) / 8.0f;
    } else if (frame < 0x1a) {
        scale = DAT_007cad78 * (float)(frame - 0xf) / 11.0f + 1.0f;
        alpha = 1.0f - (float)(frame - 0xf) / 11.0f;
    } else {
        scale = 1.0f;
        alpha = 0.0f;
    }
    panelDirection[0] = sinf(DAT_007cb034);
    panelDirection[1] = -cosf(DAT_007cb034);
    panelSize[0] = (mode == 1 ? 463.0f : 510.0f) * scale;
    panelSize[1] = 89.0f * scale;
    func_0021e170(work + 0x184, panelPosition, panelDirection, panelSize);
    color.a = (unsigned char)(alpha * 255.0f);
    func_0021d950(work + 0x184, &color);
done:
    return;
}

// FUN_0023e970 NONMATCHING
void func_0023e970(void)
{
    int base;
    s32 mode;
    s32 i;
    void* texture;
    volatile code *quad;
    volatile code *state;
    volatile code *render;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    base = (int)sSflPanel;
    K_ASSERT(*(u32*)base & 1, 0x29b);

    render = (code *)&DAT_00960090_abs;
    (*render)(9, 2);
    (*render)(0x14, 2);
    (*render)(8, 0);
    (*render)(6, 0);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    mode = *(s32*)(base + 4);
    if (mode == 2 || mode == 1) {
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        state = (code *)&DAT_00960090_abs;
        (*state)(6, 1);
        texture = sflRes0020e690(0);
        (*state)(1, texture);
        for (i = 0; i < 2; i++) {
            quad = (code *)&DAT_0096009c_abs;
            (*quad)(base + 0x210 + i * 0x100, 4, 0, 1, 2);
            (*quad)(base + 0x210 + i * 0x100, 4, 0, 2, 3);
        }
        (*state)(6, 0);

        texture = sflRes0020e690(mode);
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        render = (code *)&DAT_00960090_abs;
        (*render)(1, texture);
        quad = (code *)&DAT_0096009c_abs;
        (*quad)(base + 0x610, 4, 0, 1, 2);
        (*quad)(base + 0x610, 4, 0, 2, 3);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        (*render)(1, texture);
        quad = (code *)&DAT_0096009c_abs;
        (*quad)(base + 0x510, 4, 0, 1, 2);
        (*quad)(base + 0x510, 4, 0, 2, 3);
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        (*render)(1, texture);
        quad = (code *)&DAT_0096009c_abs;
        (*quad)(base + 0x410, 4, 0, 1, 2);
        (*quad)(base + 0x410, 4, 0, 2, 3);
    } else if (mode == 0) {
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        state = render;
        (*state)(1, sflRes0020e510(0));
        quad = (code *)&DAT_0096009c_abs;
        (*quad)(base + 0x110, 4, 0, 1, 2);
        (*quad)(base + 0x110, 4, 0, 2, 3);
        texture = sflRes0020e610(*(s32*)(base + 0xc) - 1);
        (*state)(1, texture);
        quad = (code *)&DAT_0096009c_abs;
        (*quad)(base + 0x10, 4, 0, 1, 2);
        (*quad)(base + 0x10, 4, 0, 2, 3);
    }
}

// FUN_0023ee50
void func_0023ee50(void)
{
    u32* work;
    s32 selection;
    int* image;
    float uv[4];
    RwV3d origin;

    float width;
    float height;
    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    selection = func_00255130();
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    func_004cb750(kwlnGetMainCamera()->object.object.parent, &origin, 0);
    K_ASSERT(selection != 0, 0x2fd);
    K_ASSERT(selection <= 6, 0x2fe);

    image = sflRes0020e610(selection - 1);
    width = (float)image[3];
    height = (float)image[4];
    uv[0] = 0.0f / width;
    uv[1] = 0.0f / height;
    uv[2] = width / width;
    uv[3] = height / height;
    func_0021eb80(work + 4, uv);

    image = sflRes0020e510(0);
    width = (float)image[3];
    height = (float)image[4];
    uv[0] = 1.0f / width;
    uv[1] = 0.0f / height;
    uv[2] = 174.0f / width;
    uv[3] = 32.0f / height;
    func_0021eb80(work + 0x44, uv);

    work[2] = 0;
    work[1] = 0;
    *work |= 2;
    work[3] = selection;
    func_0023dac0();
    scrClearTextBox(1, 0, 6, 0);
}

// FUN_0023f010
void func_0023f010(void)
{
    u32* work;
    int* image;
    float uv[4];
    int i;
    float width;
    float height;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;

    {
        float u0;
        float v0;
        float u1;
        float v1;

        image = sflRes0020e690(0);
        width = (float)image[3];
        height = (float)image[4];
        i = 0;
        u0 = 0.0f / width;
        v0 = 0.0f / height;
        u1 = width / width;
        v1 = height / height;
        while (i < 2) {
            uv[0] = u0;
            uv[1] = v0;
            uv[2] = u1;
            uv[3] = v1;
            func_0021eb80(work + 0x84 + i * 0x40, uv);
            i++;
        }
    }

    {
        float u0;
        float v0;
        float u1;
        float v1;

        image = sflRes0020e690(1);
        width = (float)image[3];
        height = (float)image[4];
        i = 0;
        u0 = 1.0f / width;
        v0 = 1.0f / height;
        u1 = 463.0f / width;
        v1 = 89.0f / height;
        while (i < 3) {
            uv[0] = u0;
            uv[1] = v0;
            uv[2] = u1;
            uv[3] = v1;
            func_0021eb80(work + 0x104 + i * 0x40, uv);
            i++;
        }
    }

    work[2] = 0;
    work[1] = 1;
    *work |= 2;
    func_0023dac0();
}

// FUN_0023f1d0
void func_0023f1d0(void)
{
    u32* work;
    int* image;
    float uv[4];
    int i;
    float width;
    float height;
    float u0;
    float v0;
    float u1;
    float v1;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;

    image = sflRes0020e690(0);
    width = (float)image[3];
    height = (float)image[4];
    i = 0;
    u0 = 0.0f / width;
    v0 = 0.0f / height;
    u1 = width / width;
    v1 = height / height;
    while (i < 2) {
        uv[0] = u0;
        uv[1] = v0;
        uv[2] = u1;
        uv[3] = v1;
        func_0021eb80(work + 0x84 + i * 0x40, uv);
        i++;
    }

    image = sflRes0020e690(2);
    width = (float)image[3];
    height = (float)image[4];
    i = 0;
    u0 = 1.0f / width;
    v0 = 1.0f / height;
    u1 = 510.0f / width;
    v1 = 89.0f / height;
    while (i < 3) {
        uv[0] = u0;
        uv[1] = v0;
        uv[2] = u1;
        uv[3] = v1;
        func_0021eb80(work + 0x104 + i * 0x40, uv);
        i++;
    }

    work[2] = 0;
    work[1] = 2;
    *work |= 2;
    func_0023dac0();
}

// FUN_0023F390
u32 sflPanel0023f390(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    return *sSflPanel & 2;
}

// FUN_0023F3E0
void sflPanel0023f3e0(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    *sSflPanel |= 8;
}

// FUN_0023F430
void sflPanel0023f430(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    *sSflPanel &= 0xfffffff7;
}
