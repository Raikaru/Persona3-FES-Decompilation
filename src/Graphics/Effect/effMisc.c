#include "Graphics/Effect/effMisc.h"
#include "libm.h"
#include "Kernel/Kwln/kwln.h"
#include "sce/eestruct.h"
#include "temporary.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];

static EffRandState sRandState; // 00957bf0

typedef struct EffRenderState
{
    u32 renderState;
    u32 value;
} EffRenderState;

static const EffRenderState sEffRenderStates[6] =
{
    {rwRENDERSTATEFOGENABLE, false},
    {rwRENDERSTATEVERTEXALPHAENABLE, true},
    {rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD},
    {rwRENDERSTATECULLMODE, rwCULLMODECULLNONE},
    {rwRENDERSTATEZTESTENABLE, true},
    {rwRENDERSTATEZWRITEENABLE, false}
};

// FUN_00357dd0
void effMiscQuatMultiplyVU()
{
    __asm__ volatile (
        ".set noreorder               \n"
        "vmul.xyzw vf2, vf10, vf11    \n"
        "vopmula.xyz ACC, vf10, vf11  \n"
        "vmaddaw.xyz ACC, vf11, vf10  \n"
        "vmaddaw.xyz ACC, vf10, vf11  \n"
        "vopmsub.xyz vf10, vf11, vf10 \n"
        "vmulaw.w ACC, vf10, vf11     \n"
        "vmsubax.w ACC, vf0, vf2      \n"
        "vmsubay.w ACC, vf0, vf2      \n"
        "vmsubz.w vf10, vf0, vf2      \n"
        ".set reorder"
        :
        :
        : "vf2", "ACC", "memory"
    );
}

// FUN_00357e00
void effMiscNormalizeVU()
{
    __asm__ volatile (
        ".set noreorder            \n"
        "vmul.xyzw vf2, vf10, vf10 \n"
        "vaddax.w ACC, vf2, vf2    \n"
        "vmadday.w ACC, vf0, vf2   \n"
        "vmaddz.w vf3, vf0, vf2    \n"
        "vrsqrt Q, vf0w, vf3w      \n"
        "vwaitq                    \n"
        "vmulq.xyzw vf10, vf10, Q  \n"
        ".set reorder"
        :
        :
        : "vf2", "vf3", "ACC", "Q", "memory"
    );
}

// FUN_00357e30
void func_00357e30(void)
{
    __asm__ volatile (
        ".set noreorder                              \n"
        "vaddw.xyz vf1, vf0, vf0w                    \n"
        "vadd.xyzw vf2, vf10, vf10                   \n"
        "vmulx.w vf28, vf0, vf0x                     \n"
        "vmulx.w vf29, vf0, vf0x                     \n"
        "vmulx.w vf30, vf0, vf0x                     \n"
        "vmul.xyzw vf3, vf10, vf2                    \n"
        "vmuly.xyzw vf4, vf10, vf2y                  \n"
        "vmulz.xyzw vf5, vf10, vf2z                  \n"
        "vmulx.xyzw vf6, vf10, vf2x                  \n"
        "vaddaw.xyz ACC, vf0, vf0w                   \n"
        "vmsubay.x ACC, vf1, vf3y                    \n"
        "vmsubz.x vf28, vf1, vf3z                    \n"
        "vmsubax.y ACC, vf1, vf3x                    \n"
        "vmsubz.y vf29, vf1, vf3z                    \n"
        "vmsubax.z ACC, vf1, vf3x                    \n"
        "vmsuby.z vf30, vf1, vf3y                    \n"
        "vmulax.y ACC, vf1, vf4x                     \n"
        "vmsubw.y vf28, vf1, vf5w                    \n"
        "vaddw.x vf29, vf4, vf5w                     \n"
        "vsubw.x vf30, vf5, vf4w                     \n"
        "vmulax.z ACC, vf1, vf5x                     \n"
        "vmaddw.z vf28, vf1, vf4w                    \n"
        "vmulay.z ACC, vf1, vf5y                     \n"
        "vmsubw.z vf29, vf1, vf6w                    \n"
        "vaddw.y vf30, vf5, vf6w                     \n"
        "vmove.xyzw vf31, vf0                        \n"
        ".set reorder"
        :
        :
        : "vf1", "vf2", "vf3", "vf4", "vf5", "vf6", "vf28", "vf29", "vf30", "vf31", "ACC", "memory"
    );
}

// FUN_00357ea0
void func_00357ea0(f32 angleX, f32 angleY, f32 angleZ)
{
    RwV4d quaternion;
    f32 halfAngle;
    f32 cosY;
    f32 sinY;
    f32 cosZ;
    f32 cosX;
    f32 sinX;
    f32 sinZ;

    halfAngle = -angleX * 0.5f;
    cosX = cosf(halfAngle);
    sinX = sinf(halfAngle);
    halfAngle = -angleY * 0.5f;
    cosY = cosf(halfAngle);
    sinY = sinf(halfAngle);
    halfAngle = -angleZ * 0.5f;
    cosZ = cosf(halfAngle);
    sinZ = sinf(halfAngle);
    quaternion.x = cosX * (sinZ * sinY) + sinX * (cosZ * cosY);
    quaternion.y = cosX * (cosZ * sinY) - sinX * (sinZ * cosY);
    quaternion.z = cosX * (sinZ * cosY) + sinX * (cosZ * sinY);
    quaternion.w = cosX * (cosZ * cosY) - sinX * (sinZ * sinY);

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf10, 0(%0)        \n"
        ".set reorder"
        :
        : "r" (&quaternion)
        : "vf10", "memory"
    );
}

// FUN_00357fd0. [0;16777215]
u32 effMiscRand(EffRandState* state)
{
    u32 x0;
    u32 x1;
    u32 x2;
    u32 x3;
    u32 rand;

    if (state == NULL)
    {
        state = &sRandState;
    }

    x0 = state->x[0];
    x1 = state->x[1];
    x2 = state->x[2];
    x3 = state->x[3];

    rand = ((x1 << 0x02) | (((x0 >> 0x1e)) % 4)) ^ ((x3 << 0x01) | (((x2 >> 0x1f)) % 2));

    state->x[0] = rand;
    state->x[1] = x0;
    state->x[2] = x1;
    state->x[3] = x2;

    return rand;
}

// FUN_00358030. [0.0f;1.0f[
f32 effMiscRandFloat(EffRandState* state)
{
    return (f32)(effMiscRand(state) & 0xFFFFFF) / 16777216.0f;
}

// FUN_003580b0. [0;max[
u32 effMiscRandRange(EffRandState* state, u32 max)
{
    return effMiscRand(state) % max;
}

// FUN_003580f0
void effMiscRandInit(EffRandState* state, u32 seed)
{
    u32 x;

    if (state == NULL)
    {
        state = &sRandState;
    }

    x = seed ^ 0xAED1A0C;
    state->x[0] = x;

    x = (x << 0x18) | (x >> 0x08);
    state->x[1] = x;

    x = x ^ 0xAA5A02FE;
    x = (x << 0x18) | (x >> 0x08);
    state->x[2] = x;

    x = x ^ 0x11BE81C7;
    state->x[3] = (x << 0x18) | (x >> 0x08);
}

// FUN_00358160
void func_00358160(f32 angle)
{
    RwMatrix matrix;
    f32 cosine;
    f32 sine;

    cosine = cosf(angle);
    sine = sinf(angle);

    __asm__ volatile (
        ".set noreorder          \n"
        "qmfc2.ni $5, $vf0       \n"
        "pextuw $4, $0, $5       \n"
        "pextuw $2, $0, $4       \n"
        "pextuw $3, $4, $0       \n"
        "sq $2, 0(%0)            \n"
        "sq $3, 16(%0)           \n"
        "sq $4, 32(%0)           \n"
        "sq $5, 48(%0)           \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "$2", "$3", "$4", "$5", "memory"
    );
    matrix.up.y = cosine;
    matrix.up.z = sine;
    matrix.at.y = -sine;
    matrix.at.z = cosine;

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf28, 0(%0)        \n"
        "lqc2 vf29, 16(%0)       \n"
        "lqc2 vf30, 32(%0)       \n"
        "lqc2 vf31, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf28", "vf29", "vf30", "vf31", "memory"
    );
}

// FUN_003581f0 NONMATCHING
void func_003581f0(const RwV3d* axis, RwMatrix* matrix, f32 angle)
{
    f32 angle_p;
    f32 xSquared;
    f32 ySquared;
    f32 zSquared;
    f32 xz;
    const RwV3d* axis_p;
    RwMatrix* matrix_p;
    RwV3d normalizedAxis;
    f32 cosine;
    f32 sine;
    f32 x;
    f32 y;
    f32 z;
    angle_p = angle;
    axis_p = axis;
    matrix_p = matrix;
    cosine = cosf(angle_p);
    sine = sinf(angle_p);

    __asm__ volatile (
        ".set noreorder                              \n"
        "lqc2 vf10, 0(%0)                            \n"
        "vmul.xyz vf2, vf10, vf10                    \n"
        "vmulax.w ACC, vf0, vf2x                     \n"
        "vmadday.w ACC, vf0, vf2y                    \n"
        "vmaddz.w vf2, vf0, vf2z                    \n"
        "vrsqrt Q, vf0w, vf2w                       \n"
        "vwaitq                                      \n"
        "vmulq.xyz vf10, vf10, Q                    \n"
        ".set reorder"
        :
        : "r" (axis_p)
        : "vf2", "vf10", "ACC", "Q", "memory"
    );
    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf10, 0(%0)        \n"
        ".set reorder"
        :
        : "r" (&normalizedAxis)
        : "memory"
    );

    x = normalizedAxis.x;
    y = normalizedAxis.y;
    z = normalizedAxis.z;
    xSquared = x * x;
    matrix_p->right.x = xSquared + (1.0f - xSquared) * cosine;
    matrix_p->right.y = x * y * (1.0f - cosine) + z * sine;
    xz = x * z;
    matrix_p->right.z = xz * (1.0f - cosine) - y * sine;
    matrix_p->flags = 0;

    matrix_p->up.x = z * sine - x * y * (1.0f - cosine);
    ySquared = y * y;
    matrix_p->up.y = ySquared + (1.0f - ySquared) * cosine;
    xSquared = y * z;
    ySquared = x * sine;
    matrix_p->up.z = ySquared + xSquared * (1.0f - cosine);
    matrix_p->pad1 = 0;

    matrix_p->at.x = y * sine + x * z * (1.0f - cosine);
    matrix_p->at.y = y * z * (1.0f - cosine) - x * sine;
    zSquared = z * z;
    matrix_p->at.z = zSquared + (1.0f - zSquared) * cosine;
    matrix_p->pad2 = 0;

    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf0, 0x30(%0)       \n"
        ".set reorder"
        :
        : "r" (matrix_p)
        : "memory"
    );
}

// FUN_00358340
void func_00358340(const RwV3d* axis, f32 angle)
{
    RwMatrix matrix;

    func_003581f0(axis, &matrix, angle);
    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf28, 0(%0)        \n"
        "lqc2 vf29, 16(%0)       \n"
        "lqc2 vf30, 32(%0)       \n"
        "lqc2 vf31, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf28", "vf29", "vf30", "vf31", "memory"
    );
}

// FUN_00358380
void func_00358380(f32 angle)
{
    RwMatrix matrix;
    f32 cosine;
    f32 sine;

    cosine = cosf(angle);
    sine = sinf(angle);

    __asm__ volatile (
        ".set noreorder          \n"
        "qmfc2.ni $5, $vf0       \n"
        "pextuw $4, $0, $5       \n"
        "pextuw $2, $0, $4       \n"
        "pextuw $3, $4, $0       \n"
        "sq $2, 0(%0)            \n"
        "sq $3, 16(%0)           \n"
        "sq $4, 32(%0)           \n"
        "sq $5, 48(%0)           \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "$2", "$3", "$4", "$5", "memory"
    );
    matrix.right.x = cosine;
    matrix.right.z = -sine;
    matrix.at.x = sine;
    matrix.at.z = cosine;

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf24, 0(%0)        \n"
        "lqc2 vf25, 16(%0)       \n"
        "lqc2 vf26, 32(%0)       \n"
        "lqc2 vf27, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf24", "vf25", "vf26", "vf27", "memory"
    );
}

// FUN_00358410
void func_00358410(void)
{
    __asm__ volatile (
        ".set noreorder                              \n"
        "vmulax.xyzw ACC, vf24, vf28x                \n"
        "vmadday.xyzw ACC, vf25, vf28y               \n"
        "vmaddaz.xyzw ACC, vf26, vf28z               \n"
        "vmaddw.xyzw vf28, vf27, vf28w               \n"
        "vmulax.xyzw ACC, vf24, vf29x                \n"
        "vmadday.xyzw ACC, vf25, vf29y               \n"
        "vmaddaz.xyzw ACC, vf26, vf29z               \n"
        "vmaddw.xyzw vf29, vf27, vf29w               \n"
        "vmulax.xyzw ACC, vf24, vf30x                \n"
        "vmadday.xyzw ACC, vf25, vf30y               \n"
        "vmaddaz.xyzw ACC, vf26, vf30z               \n"
        "vmaddw.xyzw vf30, vf27, vf30w               \n"
        "vmulax.xyzw ACC, vf24, vf31x                \n"
        "vmadday.xyzw ACC, vf25, vf31y               \n"
        "vmaddaz.xyzw ACC, vf26, vf31z               \n"
        "vmaddw.xyzw vf31, vf27, vf31w               \n"
        ".set reorder"
        :
        :
        : "vf28", "vf29", "vf30", "vf31", "ACC", "memory"
    );
}

// Corrected SCE_GS_SET_TEST_1 afail argument to match retail's ATEST_1 constant.
// Remaining residual is MWCC's fixed argument-register order for getRenderState/
// setRenderState calls (simple-load arg vs computed-address arg); 2 independent
// reorder attempts (temp var, syntactic variant) had zero effect on emitted code.

// FUN_00358460 NONMATCHING
void func_00358460(const RwRGBA* color, u32 saveAndRestoreRenderState)
{
    u32 i;
    u32 j;
    const EffRenderState* renderState;
    RwIm2DVertex vertices[4];
    u32 savedRenderStates[6];
    f32 zBufferNear;
    f32 recipZ;

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < 6; i++)
        {
            renderState = &sEffRenderStates[i];
            (*((RwGlobals*)rwGlobals_abs)->device.getRenderState)(renderState->renderState, &savedRenderStates[i]);
            (*((RwGlobals*)rwGlobals_abs)->device.setRenderState)(renderState->renderState, (void*)renderState->value);
        }

        (*((RwGlobals*)rwGlobals_abs)->device.setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 1, 0, 1, 0));
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 5, 127, 1, 0, 0, 1, 3));
    }

    zBufferNear = ((RwGlobals*)rwGlobals_abs)->device.zBufferNear;
    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[0].u.els.scrVertex.z = zBufferNear;
    vertices[0].u.els.color.r = (f32)color->r;
    vertices[0].u.els.color.g = (f32)color->g;
    vertices[0].u.els.color.b = (f32)color->b;
    vertices[0].u.els.color.a = (f32)color->a;
    vertices[0].u.els.recipZ = recipZ;

    vertices[1].u.els.scrVertex.x = 0.0f;
    vertices[1].u.els.scrVertex.y = 448.0f;
    vertices[1].u.els.scrVertex.z = zBufferNear;
    vertices[1].u.els.color.r = (f32)color->r;
    vertices[1].u.els.color.g = (f32)color->g;
    vertices[1].u.els.color.b = (f32)color->b;
    vertices[1].u.els.color.a = (f32)color->a;
    vertices[1].u.els.recipZ = recipZ;

    vertices[2].u.els.scrVertex.x = 640.0f;
    vertices[2].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.z = zBufferNear;
    vertices[2].u.els.color.r = (f32)color->r;
    vertices[2].u.els.color.g = (f32)color->g;
    vertices[2].u.els.color.b = (f32)color->b;
    vertices[2].u.els.color.a = (f32)color->a;
    vertices[2].u.els.recipZ = recipZ;

    vertices[3].u.els.scrVertex.x = 640.0f;
    vertices[3].u.els.scrVertex.y = 448.0f;
    vertices[3].u.els.scrVertex.z = zBufferNear;
    vertices[3].u.els.color.r = (f32)color->r;
    vertices[3].u.els.color.g = (f32)color->g;
    vertices[3].u.els.color.b = (f32)color->b;
    vertices[3].u.els.color.a = (f32)color->a;
    vertices[3].u.els.recipZ = recipZ;

    (*((RwGlobals*)rwGlobals_abs)->device.fpIm2DRenderPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);

    if (saveAndRestoreRenderState)
    {
        for (j = 0; j < 6; j++)
        {
            renderState = &sEffRenderStates[j];
            (*((RwGlobals*)rwGlobals_abs)->device.setRenderState)(renderState->renderState, (void*)savedRenderStates[j]);
        }
    }
}
