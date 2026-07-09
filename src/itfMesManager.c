#include "itfMesManager.h"
#include "Script/scr.h"
#include "Kosaka/k_assert.h"

u8 itfMesMngCheckBmdMagic(BmdHeader* bmdHeader);

#define ITFMES_HANDLE_STRIDE            0x34
#define ITFMES_HANDLE_ACTIVE_MES_OFFSET 0x2c

typedef struct ItfMesHandleSystem
{
    u8 bytes[0x100];
} ItfMesHandleSystem;

static ItfMesHandleSystem sItfMesHandleSystem;

extern void FUN_003a4dd0(s32 mesHandleIdx);

// FUN_003a2d80
s32 itfMesMngInitialize(BmdHeader* bmdHeader)
{
    // TODO

    return 0;
}

// FUN_003a3060
void itfMesMngDestroyHandle(s32 mesHandleIdx)
{
    if (mesHandleIdx >= 0
        && *(ItfMes**)((u8*)&sItfMesHandleSystem
                       + mesHandleIdx * ITFMES_HANDLE_STRIDE
                       + ITFMES_HANDLE_ACTIVE_MES_OFFSET) != NULL)
    {
        FUN_003a4dd0(mesHandleIdx);
    }
}

// FUN_003a4990
void itfMesMngChangeWindowType(s32 mesHandleIdx, u16 type, u32 param_3)
{
    // TODO
}

// FUN_003a5090
u8 itfMesMngCheckBmdMagic(BmdHeader* bmdHeader)
{
    s8 isMagicValid;

    isMagicValid = true;
    switch (bmdHeader->magic)
    {
        case BMD_HEADER_MAGIC1:
        case BMD_HEADER_MAGIC0: break;

        default: isMagicValid = false;
    }
    
    if (isMagicValid)
    {
        return true;
    }
    
    return false;
}

// FUN_003a3ba0
void itfMesMng003a3ba0(s32 mesHandleIdx, u32 param_2)
{
    int iVar1;

    iVar1 = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(iVar1 != 0, 0x956);
    *(u32*)(iVar1 + 0x50) = param_2;
}

// FUN_003a3e10
void itfMesMng003a3e10(s32 mesHandleIdx, u32 param_2)
{
    u32* puVar1;

    puVar1 = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(puVar1 != NULL, 0xa81);
    *puVar1 |= param_2 & 0xffff0000;
}

// FUN_003a3e90
void itfMesMng003a3e90(s32 mesHandleIdx, u32 param_2)
{
    u32* puVar1;

    puVar1 = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(puVar1 != NULL, 0xa96);
    *puVar1 &= ~(param_2 & 0xffff0000);
}

// FUN_003a3da0
u32 itfMesMng003a3da0(s32 mesHandleIdx)
{
    u32* p;

    p = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != NULL, 0xa54);
    return *p;
}

// FUN_003a3f20
s16 itfMesMng003a3f20(s32 mesHandleIdx)
{
    int p;

    p = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != 0, 0xaa9);
    return *(s16*)(p + 0x56);
}