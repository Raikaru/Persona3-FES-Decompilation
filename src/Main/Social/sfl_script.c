#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00259630(void);
void FUN_00259740(void);
void FUN_00259850(int param_1,const void* param_2);
void FUN_002599c0(u16 param_1,u16 param_2);
void FUN_00259a60(u16 param_1,u16 param_2);
u64 FUN_00259d10(void);
u32 FUN_00259d80(s16 *param_1);
u32 FUN_00259e60(void);
u32 FUN_00259ea0(u16 *param_1);
u32 FUN_00259ed0(void);
u32 FUN_00259f40(s16 *param_1);
u32 FUN_00259fc0(s16 *param_1);
u32 FUN_0025a030(s16 *param_1);
extern u16 DAT_0068ead4[];
extern u16 D_0068EAD0[];
extern u16 D_0068EAD4[];
extern code* PTR_FUN_0068ead0;
extern int iGpffffb668;
extern u32 iGpffffb66c;
extern u32 uGpffffb668;
extern const char D_0068EB60[];
extern const char D_0068eb18[];
extern const char D_0068eb28[];
extern const char D_0068eb98[];
extern const char D_0068eb40[];
extern const char D_0068eb80[];
void FUN_00521250(void* destination, const void* source, u32 size);
extern const char D_0068eba8[];

void FUN_0019d3f0(const char* message, u32 line);
void FUN_005225a8(const char* message, ...);
void FUN_00255810(s16 param_1);

static u32* sSflScript; // puGpffffb668


// FUN_00259640
void sflScript00259640(void)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[2] = work[1];
    *work |= 1;
}

// FUN_00259970
void sflScript00259970(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(0, 0);
}

// FUN_00259b00
void sflScript00259b00(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(2, &arg);
}

// FUN_00259b60
void sflScript00259b60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(4, &arg);
}

// FUN_00259bc0
void sflScript00259bc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(5, 0);
}

// FUN_00259c60
void sflScript00259c60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(7, &arg);
}

s32 FUN_00256430();

// FUN_00259690
void sflScript00259690(u32 param_1, u32 param_2)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[1] = param_1;
    work[3] = param_1;
    work[4] = param_2;
}

// FUN_002596f0
u32 sflScript002596f0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    return *sSflScript & 1;
}

// FUN_00259c10
void sflScript00259c10(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(6, 0);
}

// FUN_00259cc0
void sflScript00259cc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(8, 0);
}

// FUN_00259e00
u32 sflScript00259e00(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    if (FUN_00256430() != 0) {
        return 0;
    }
    return 1;
}

// FUN_00259610
void sflScript00259610(u32* param_1)
{
    *param_1 = 0;
    param_1[5] = 0;
    sSflScript = param_1;
}

/* Recovered battle-misc harvest: 0x00259630-0x0025A030 */
// FUN_00259630


void FUN_00259630(void)



{

  uGpffffb668 = 0;

  return;

}

// FUN_00259740


void FUN_00259740(void)



{

  u16 *cursor;
  u32 *work;
  u32 callback_result;
  int opcode_offset;
  u32 next_offset;
  u16 *command_entry;
  u32 flags;
  u32 length;
  u32 has_length;

  

  if (sSflScript == (u32 *)0x0) {
    FUN_0019d3f0(D_0068eb18, 0x43);

  }

  work = sSflScript;

  flags = ~*sSflScript;
  if ((flags & 1U) == 0U) {

    while( 1 ) {

      cursor = (u16 *)work[2];
      opcode_offset = (u32)*cursor * 8;
      command_entry = D_0068EAD0 + ((u32)*cursor * 4);
      length = (u32)command_entry[2];
      has_length = (length != 0) ^ 1U;
      if (has_length == 0) {
        cursor += 1;
        if (((u32)cursor & 3) != 0) {
          cursor += 1;
        }
      } else {
        cursor = (u16 *)0x0;
      }
      callback_result = (*(code *)command_entry)(cursor);
      if (callback_result == 0) break;
      next_offset = work[2] + 2;
      if (command_entry[2] != 0) {
        if ((next_offset & 3) != 0) {
          next_offset += 2;
        }
        next_offset += (u32)(u16)command_entry[2];
        if ((next_offset & 1) != 0) {
          next_offset += 1;
        }
      }
      work[2] = next_offset;

    }

  }

  return;

}

// FUN_002599C0


void FUN_002599c0(u16 param_1,u16 param_2)



{

  u8 *cursor;
  s32 count;

  u16 params[2];

  

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(D_0068eb18,0x43);

  }

  cursor = (u8*)params;
  count = sizeof(params);
  if (cursor != NULL) {
    do {
      *cursor++ = 0;
      count--;
    } while (count != 0);
  }

  params[0] = param_1;

  params[1] = param_2;


  FUN_00259850(1, params);
  return;

}

// FUN_00259A60


void FUN_00259a60(u16 param_1,u16 param_2)



{

  u8 *cursor;
  s32 count;

  u16 params[2];

  

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(D_0068eb18,0x43);

  }

  cursor = (u8*)params;
  count = sizeof(params);
  if (cursor != NULL) {
    do {
      *cursor++ = 0;
      count--;
    } while (count != 0);
  }

  params[0] = param_1;

  params[1] = param_2;


  FUN_00259850(3, params);
  return;

}


// FUN_00259D10
u64 FUN_00259d10(void)
{
    u32 *work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    FUN_005225a8(D_0068eb28);
    *work &= ~1;
    return 0;
}

// FUN_00259D80
u32 FUN_00259d80(s16 *param_1)
{
    s16 *next;

    if (iGpffffb668 == 0) {
        FUN_0019d3f0(D_0068eb18, 0x43);
    }
    next = param_1 + 1;
    FUN_005225a8(D_0068eb40, param_1[0], next[0]);
    FUN_002551d0(param_1[0], next[0]);
    return 1;
}

// FUN_00259E60


u32 FUN_00259e60(void)



{

  FUN_005225a8(D_0068EB60);

  FUN_00257130();

  return 1;

}

// FUN_00259EA0
u32 FUN_00259ea0(u16 *param_1)
{
    FUN_002584e0(*param_1);
    return 1;
}

// FUN_00259ED0
u32 FUN_00259ed0(void)
{
    if (iGpffffb66c == 0) {
        FUN_00255b20();
        iGpffffb66c = 1;
        goto done_zero;
    }
    if (FUN_00255f30() != 0) {
        return 0;
    }
    iGpffffb66c = 0;
    return 1;
done_zero:
    return 0;
}
// FUN_00259F40
u32 FUN_00259f40(s16 *param_1)
{
    s16 *next;

    if (iGpffffb668 == 0) {
        FUN_0019d3f0(D_0068eb18, 0x43);
    }
    next = param_1 + 1;
    FUN_005225a8(D_0068eb80, param_1[0], next[0]);
    FUN_00255570(param_1[0], next[0]);
    return 1;
}

// FUN_00259FC0
u32 FUN_00259fc0(s16 *param_1)
{
  if (iGpffffb668 == 0) {
    FUN_0019d3f0(D_0068eb18, 0x43);
  }
  FUN_005225a8(D_0068eb98, *param_1);
  FUN_00255810(*param_1);
  return 1;
}

// FUN_0025A030
u32 FUN_0025a030(s16 *param_1)
{
    u32 *work;
    u32 count;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    count = *(u16 *)param_1;
    if ((~work[0] & 2) != 0) {
        FUN_005225a8(D_0068eba8, *param_1);
        work[5] = 0;
        if (count == 0) {
            return 1;
        }
    } else {
        work[5] += 1;
        if (work[5] == count) {
            work[0] &= ~2;
            return 1;
        }
    }
    work[0] |= 2;
    return 0;
}

/* Recovered battle-misc harvest: 0x00259850-0x00259850 */
// FUN_00259850


void FUN_00259850(int param_1,const void* param_2)



{
  u16 *packet_cursor;
  u8 *work;
  u16 *next_cursor;
  u32 cursor;

  if (iGpffffb668 == 0) {
    FUN_0019d3f0(D_0068eb18, 0x43);
  }
  work = (u8 *)iGpffffb668;
  packet_cursor = *(u16 **)(work + 0xc);
  *packet_cursor = (short)param_1;
  next_cursor = packet_cursor + 1;
  if (*(u16 *)((u8 *)D_0068EAD4 + param_1 * 8) != 0) {
    if (((u32)next_cursor & 3) != 0) {
      next_cursor += 1;
    }
    FUN_00521250(next_cursor,param_2,
                 *(u16 *)((u8 *)D_0068EAD4 + param_1 * 8));
    next_cursor = (u16 *)((int)next_cursor +
                     *(u16 *)((u8 *)D_0068EAD4 + param_1 * 8));
  }
  cursor = ((u32 *)work)[3];
  cursor += (u32)next_cursor - cursor;
  ((u32 *)work)[3] = cursor;
  if ((int)cursor - *(int *)(work + 4) > *(int *)(work + 0x10)) {
    FUN_0019d3f0(D_0068eb18, 0xb2);
  }
  if ((*(u32 *)(work + 0xc) & 1) != 0) {
    *(u32 *)(work + 0xc) = *(u32 *)(work + 0xc) + 1;
  }
}
