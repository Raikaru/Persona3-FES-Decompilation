#include "mw_harvest_compat.h"
#include "rw/rtquat.h"
#include "temporary.h"

typedef void (*RtQuatMatrixHelper)(RtQuat* quat, const RwMatrix* matrix);

// FUN_004bdcb0 NONMATCHING

RwBool RtQuatConvertFromMatrix(RtQuat* quat, const RwMatrix* matrix)
{
    RwReal s;
    RwReal h;
    RwReal trace;
    RwReal zero;
    RwBool result;
    RtQuatMatrixHelper helper;

    result = (quat != NULL) && (matrix != NULL);
    if (result)
    {
        zero = 0.0f;
        trace = matrix->right.x + (matrix->up.y + matrix->at.z);
        if (!(trace <= zero))
        {
            s = sqrtf(1.0f + trace);
            h = 0.5f / s;
            quat->real = 0.5f * s;
            quat->imag.x = h * (matrix->up.z - matrix->at.y);
            quat->imag.y = h * (matrix->at.x - matrix->right.z);
            quat->imag.z = h * (matrix->right.y - matrix->up.x);
        }
        else
        {
            if (!(matrix->right.x <= matrix->up.y))
            {
                if (!(matrix->right.x <= matrix->at.z))
                {
                    helper = (RtQuatMatrixHelper)((u8*)0x004c0000 - 0x24d0);
                }
                else
                {
                    helper = (RtQuatMatrixHelper)((u8*)0x004c0000 - 0x23d0);
                }
            }
            else if (!(matrix->up.y <= matrix->at.z))
            {
                helper = (RtQuatMatrixHelper)((u8*)0x004c0000 - 0x2450);
            }
            else
            {
                helper = (RtQuatMatrixHelper)((u8*)0x004c0000 - 0x23d0);
            }
            helper(quat, matrix);
        }
    }
    return result;
}
// FUN_004BDDE0 NONMATCHING
long FUN_004bdde0(float param_1,long param_2,long param_3,long param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    uStack_10 = 0x195;
    uStack_c = FUN_004c1d10(0xffffffff80000016);
    FUN_004c1c50(&uStack_10);
    param_2 = 0;
  }
  else {
    pfVar1 = (float *)param_2;
    if (param_4 == 2) {
      fVar2 = pfVar1[1];
      fVar6 = *pfVar1;
      fVar3 = pfVar1[2];
      fVar4 = pfVar1[3];
      fVar5 = (float)FUN_0052e878(param_1 * 0.008726646);
      fStack_34 = (float)FUN_0052e6d8(param_1 * 0.008726646);
      FUN_004c69f0(&fStack_40,param_3);
      fStack_3c = fStack_3c * fVar5;
      fStack_40 = fStack_40 * fVar5;
      fStack_38 = fStack_38 * fVar5;
      pfVar1[3] = fStack_34 * fVar4 - (fStack_38 * fVar3 + fStack_40 * fVar6 + fStack_3c * fVar2);
      *pfVar1 = fStack_3c * fVar3 - fStack_38 * fVar2;
      pfVar1[1] = fStack_38 * fVar6 - fStack_40 * fVar3;
      pfVar1[2] = fStack_40 * fVar2 - fStack_3c * fVar6;
      *pfVar1 = fVar6 * fStack_34 + *pfVar1 + 0.0;
      pfVar1[1] = fVar2 * fStack_34 + pfVar1[1] + 0.0;
      pfVar1[2] = fVar3 * fStack_34 + pfVar1[2] + 0.0;
      *pfVar1 = fStack_40 * fVar4 + *pfVar1 + 0.0;
      pfVar1[1] = fStack_3c * fVar4 + pfVar1[1] + 0.0;
      pfVar1[2] = fStack_38 * fVar4 + pfVar1[2] + 0.0;
    }
    else if (param_4 == 1) {
      fStack_2c = pfVar1[1];
      fStack_30 = *pfVar1;
      fStack_28 = pfVar1[2];
      fStack_24 = pfVar1[3];
      fVar2 = (float)FUN_0052e878(param_1 * 0.008726646);
      fStack_14 = (float)FUN_0052e6d8(param_1 * 0.008726646);
      FUN_004c69f0(&fStack_20,param_3);
      fStack_1c = fStack_1c * fVar2;
      fStack_20 = fStack_20 * fVar2;
      fStack_18 = fStack_18 * fVar2;
      pfVar1[3] = fStack_24 * fStack_14 -
                  (fStack_28 * fStack_18 + fStack_30 * fStack_20 + fStack_2c * fStack_1c);
      *pfVar1 = fStack_2c * fStack_18 - fStack_28 * fStack_1c;
      pfVar1[1] = fStack_28 * fStack_20 - fStack_30 * fStack_18;
      pfVar1[2] = fStack_30 * fStack_1c - fStack_2c * fStack_20;
      *pfVar1 = fStack_20 * fStack_24 + *pfVar1 + 0.0;
      pfVar1[1] = fStack_1c * fStack_24 + pfVar1[1] + 0.0;
      pfVar1[2] = fStack_18 * fStack_24 + pfVar1[2] + 0.0;
      *pfVar1 = fStack_30 * fStack_14 + *pfVar1 + 0.0;
      pfVar1[1] = fStack_2c * fStack_14 + pfVar1[1] + 0.0;
      pfVar1[2] = fStack_28 * fStack_14 + pfVar1[2] + 0.0;
    }
    else if (param_4 == 0) {
      fVar2 = (float)FUN_0052e878(param_1 * 0.008726646);
      fVar3 = (float)FUN_0052e6d8(param_1 * 0.008726646);
      pfVar1[3] = fVar3;
      FUN_004c69f0(param_2,param_3);
      *pfVar1 = *pfVar1 * fVar2;
      pfVar1[1] = pfVar1[1] * fVar2;
      pfVar1[2] = pfVar1[2] * fVar2;
    }
    else {
      uStack_8 = 0x195;
      uStack_4 = FUN_004c1d10(0xffffffff80000003,0x77e590);
      FUN_004c1c50(&uStack_8);
      param_2 = 0;
    }
  }
  return param_2;
}
// FUN_004be1e0 NONMATCHING
RwV3d* RtQuatTransformVectors(RwV3d* vectorsOut, const RwV3d* vectorsIn, const RwInt32 numPoints, const RtQuat* quat)
{
    RwV3d* result;
    RwReal w;
    RwReal x;
    RwReal y;
    RwReal z;
    RwReal vectorScale;
    RwReal twoXW;
    RwReal twoYW;
    RwReal twoZW;
    RwReal inX;
    RwReal inY;
    RwReal inZ;
    RwReal twoDot;
    RwReal outX;
    RwReal outY;
    RwReal outZ;
    RwInt32 i;

    result = vectorsOut;
    w = quat->real;
    y = quat->imag.y;
    x = quat->imag.x;
    z = quat->imag.z;
    vectorScale = (w * w) - ((y * y + x * x) + z * z);
    twoXW = (x + x) * w;
    twoYW = (y + y) * w;
    twoZW = (z + z) * w;

    if (numPoints > 0)
    {
        i = 0;
        do
        {
            inY = vectorsIn->y;
            inX = vectorsIn->x;
            inZ = vectorsIn->z;
            twoDot = ((y + y) * inY + (x + x) * inX) + (z + z) * inZ;
            outX = twoYW * inZ - twoZW * inY;
            outY = twoZW * inX - twoXW * inZ;
            outZ = twoXW * inY - twoYW * inX;
            outX = (x * twoDot + outX) + inX * vectorScale;
            outY = (y * twoDot + outY) + inY * vectorScale;
            outZ = (z * twoDot + outZ) + inZ * vectorScale;
            vectorsOut->x = outX;
            vectorsOut->y = outY;
            vectorsOut->z = outZ;
            vectorsIn++;
            vectorsOut++;
            i++;
        } while (i < numPoints);
    }

    return result;
}
