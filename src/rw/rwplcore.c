#include "rw/rwplcore.h"

#include "temporary.h"

typedef RwV3d* (*RwV3dTransformPointFn)(RwV3d* pointOut, const RwV3d* pointIn, const RwMatrix* matrix);

extern RwInt32 rwV3dTransformPointOffset;
extern RwInt32 rwMatrixTolerancesOffset;

// 00960070
RwGlobals rwGlobals;

// FUN_004c2cc0
#pragma optimization_level 3
RwBool RwEngineGetMatrixTolerances(RwMatrixTolerance* const tolerance)
{
    RwUInt8* globals;
    RwBool result;

    globals = (RwUInt8*)&rwGlobals;
    result = true;
    *tolerance = *(RwMatrixTolerance*)(globals + rwMatrixTolerancesOffset + 0xc);

    return result;
}
#pragma optimization_level 2

// FUN_004c2d20
RwMatrix* RwMatrixOptimize(RwMatrix* matrix, const RwMatrixTolerance* tolerance)
{
    // TODO

    return NULL;
}

// FUN_004c2f10
#pragma optimization_level 3
RwMatrix* RwMatrixUpdate(RwMatrix* matrix)
{
    matrix->flags &= ~(rwMATRIXTYPEMASK | rwMATRIXINTERNALIDENTITY);

    return matrix;
}
#pragma optimization_level 2

// FUN_004c2f30 NONMATCHING
RwMatrix* RwMatrixMultiply(RwMatrix* matrixOut, const RwMatrix* matrixIn1, const RwMatrix* matrixIn2)
{
    RwMatrixMultiplyVUMacro(matrixOut, matrixIn1, matrixIn2);

    return matrixOut;
}

// FUN_004c31b0
RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, RwReal angle, RwOpCombineType combineOp)
{
    // TODO

    return matrix;
}

// FUN_004c33d0
RwMatrix* RwMatrixScale(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp)
{
    // TODO

    return matrix;
}

// FUN_004c35d0
RwMatrix* RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp)
{
    // TODO

    return matrix;
}

// FUN_004c69f0
RwReal RwV3dNormalize(RwV3d* out, const RwV3d* in)
{
    // TODO

    return 0.0f;
}

// FUN_004c6ac0
RwReal RwV3dLength(const RwV3d* in)
{
    // TODO

    return 0.0f;
}

// FUN_004c6af0
#pragma optimization_level 3
RwReal RwV2dLength(const RwV2d* in)
{
    RwReal y = in->y;
    RwReal x = in->x;

    return sqrtf((y * y) + (x * x));
}
#pragma optimization_level 2

// FUN_004c6be0
#pragma optimization_level 3
RwV3d* RwV3dTransformPoint(RwV3d* pointOut, const RwV3d* pointIn, const RwMatrix* matrix)
{
    (*(RwV3dTransformPointFn*)((RwUInt8*)&rwGlobals + rwV3dTransformPointOffset + 8))(pointOut, pointIn, matrix);

    return pointOut;
}
#pragma optimization_level 2

// FUN_004ca510 NONMATCHING
RwUInt32 RwEngineGetVersion()
{
    return RW_LIB_VERSION;
}

// FUN_004ca850
RwBool RwEngineInit(const RwMemoryFunctions* memFuncs, RwUInt32 flags, RwUInt32 resArenaSize)
{
    // TODO

    return true;
}