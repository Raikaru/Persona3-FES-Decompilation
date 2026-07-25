/* Complete rewrite of btlActionUpdateStateAttack for retail matching.
 * Retail: 8320 bytes at 0x0028eb50. Frame -0x2c0.
 * Register bindings: $s4=action, $s3=victim (action->target.targetedActions[0]),
 *   $s0=action->uid (u64), $s7=action->unit, $s6=basis,
 *   $s2=basis (same as $s6 for these purposes), $s1=temp packet ptr
 * Packet idiom: pkt->unk_00 = <kind>(byte), pkt->parentUID = other->uid (u64 at +0x08 from +0x58),
 *   pkt->actionUID = action->uid (u64 at +0x60), then btlPacketRegister(pkt, <type>).
 */

/* Retail offsets cited per block. Blocks written in retail order. */

// === Block 0: retail +0..+768 (Prologue, init, root/rotate packets, group/hit loops) ===
// These are already present in the current code; the divergence starts at +44.
// The loops need the correct content from the retail inner loop.

// === Block 1: retail +768..+888 (victim->flags_0xfa & 4 check) ===
// This block is MISSING from our current code.
// Offset 768: lhu $v0, 0xfa($s3) -> (victim->flags_0xfa & 4)
// If zero (no flag), create two packets via FUN_002886e0 and FUN_00288950.
// Then set action->field_0x18 |= 0x200 at +856.

// === Block 2: retail +888..+1040 (end of group loop, outer group loop back-edge) ===
// FUN_002d7e20, FUN_002bdbd0, then group loop increment and check.

// === Block 3: retail +1040..+1700 (genus dispatch, anim mode selection) ===
// This area is in our code but structured differently.
// Retail has fewer genus values (0/1/2) and specific anim mode setup.

// === Block 4: retail +1700..+3400 (MAJOR MISSING SECTION - ~1700 bytes) ===
// Extended packet chains post-loop including:
// - FUN_0028a0f0 voice checks
// - btlVoice002e2be0 calls with multiple voice IDs
// - FUN_0028a540 target info
// - FUN_002baf90 support/skill packets
// - gBtl flags manipulation
// - FUN_002d5dc0 workBuf init
// - FUN_002d7e20 hit result 
// - Camera packets with FUN_00282130
// - FUN_00284c90
// - Multiple FUN_002dd100 effect packets
// - FUN_002d7fb0 parameter packet
// - FUN_002d8090 effect packets
// - FUN_002bd850 weapon packets
// - FUN_002bdbd0 hit result
// - FUN_002bd230 movement
// - Many btlPacketRegister calls
// Plus block at +3364..+3640 with FUN_002db740, FUN_0027f2f0, btlVoice002e2be0

// === Block 5: retail +3400..+7064 (MORE MISSING - ~3664 bytes) ===
// Continuation of post-loop packets:
// - More FUN_002db740 damage packets
// - Extended condition chains for genus/skill/voice
// - Weapon equip packets (FUN_002bd850)
// - FUN_002baf90 support
// - Persona-related checks
// - Hit timing calculations
// - Multiple effect/sound packets

// === Block 6: retail +7064..+8132 (Persona section - ~1068 bytes) ===
// - victim->0xfa & 1 check for persona animation
// - FUN_002d5dc0, FUN_002d7e20
// - FUN_00284200 with victim->unit
// - FUN_00284c90 with victim->unit
// This is partially in our code but the structure differs.

// === Block 7: retail +8132..+8320 (Final state transition - ~188 bytes) ===
// - sp+0x240 loop counter management
// - FUN_002dc130 check -> state 0x19 or 0x1e
// - btlActionSetState
// - Epilogue

/* Auxiliary stack variable access macros (used throughout). */
#define ACT_S8(a,o)  (*(s8*)((u8*)(a)+(o)))
#define ACT_U8(a,o)  (*(u8*)((u8*)(a)+(o)))
#define ACT_S16(a,o) (*(s16*)((u8*)(a)+(o)))
#define ACT_U16(a,o) (*(u16*)((u8*)(a)+(o)))
#define ACT_U32(a,o) (*(u32*)((u8*)(a)+(o)))
#define ACT_S32(a,o) (*(s32*)((u8*)(a)+(o)))

/* GP-relative global access */
#define GP_U32(o) (*(u32*)((u8*)gBtl + (o)))
#define GP_U16(o) (*(u16*)((u8*)gBtl + (o)))

/* btlPacketRegister already declared; BTLPACKET_TYPE constants */
#ifndef BTLPACKET_TYPE_0
#define BTLPACKET_TYPE_0 0
#endif
#ifndef BTLPACKET_TYPE_1
#define BTLPACKET_TYPE_1 1
#endif
#ifndef BTLPACKET_TYPE_2D
#define BTLPACKET_TYPE_2D 3
#endif
#ifndef BTLPACKET_TYPE_3D
#define BTLPACKET_TYPE_3D 3
#endif

/* Forward declarations for functions used in this rewrite */
extern void FUN_002d5dc0(s32* buf);
extern BtlPacket* FUN_002bd590(BtlUnit* unit, u16 id);
extern void btlPacketRegister(BtlPacket* pkt, u32 type);
extern BtlPacket* btlUnitCreateRotateTowardUnitPacket(BtlUnit* src, BtlUnit* dst, u32 mode);
extern s32 btlUnitGetAnimFrame(BtlUnit* unit);
extern BtlPacket* btlUnitCreateAnimPacket(BtlUnit* unit, u16 animId, u32 mode, f32 speed, u32 loop);
extern BtlPacket* FUN_002d7e20(BtlAction* a, BtlAction* b, void* c, u16 d, u16 e);
extern BtlPacket* FUN_002bdbd0(BtlUnit* a, BtlUnit* b, u16 c, u16 d, u16 e, u32 f, u32 g, void* h);
extern BtlPacket* FUN_002886e0(BtlUnit* a, BtlUnit* b, u32 c);
extern BtlPacket* FUN_00288950(BtlUnit* a, u32 b);
extern BtlPacket* FUN_00282130(BtlUnit* unit, u32 a);
extern s16 FUN_002f8eb0(BtlUnit* unit, u16 id);
extern BtlPacket* FUN_00284200(BtlUnit* unit, u16 anim, u32 a, u32 b, f32 speed);
extern s32 FUN_00283fe0(BtlUnit* unit, u32 anim);
extern s32 FUN_00283e40(BtlUnit* unit, u32 anim);
extern BtlPacket* btlVoice002e2be0(BtlAction* action, u16 voice, u32 a, u32 b, u32 c);
extern BtlPacket* FUN_002b7bd0(BtlUnit* a, BtlUnit* b, u16 c, f32 d);
extern u32 FUN_0028a0f0(BtlAction* action);
extern void FUN_0028a540(BtlAction* action, u64 id, u16* a, u16* b, u16* c, u16* d);
extern BtlPacket* FUN_002baf90(u32 uid, BtlUnit* a, BtlUnit* b, u32 c, u32 d);
extern BtlPacket* FUN_002dd100(u32 a, u32 b, u32 c);
extern s32 FUN_002838d0(BtlUnit* unit, u32 anim, f32 speed);
extern BtlPacket* FUN_002d8090(BtlAction* action);
extern BtlPacket* FUN_002d7fb0(BtlAction* action, u32 param);
extern BtlPacket* FUN_002bd850(BtlUnit* unit, s16 id);
extern BtlPacket* FUN_002bd230(BtlUnit* unit, u32 a, u32 b);
extern void FUN_002d5dc0(s32* buf);
extern BtlPacket* FUN_00284c90(BtlUnit* unit);
extern BtlPacket* FUN_00283750(BtlUnit* unit, u32 anim, f32 speed);
extern BtlPacket* FUN_00283c70(BtlUnit* unit, u32 anim, u32 a);
extern BtlPacket* FUN_002835e0(BtlUnit* unit, u32 anim, f32 speed);
extern BtlPacket* FUN_002db740(BtlAction* action, u16 a, u32 b, u32 c, u32 d);
extern BtlPacket* FUN_0027f2f0(void);
extern s32 FUN_002fd160(BtlAction* action);
extern s32 FUN_002d4e10(u32 a, u32 b);
extern s32 FUN_002ffbc0(u32 a);
extern s64 FUN_002b7060(u32 a);
extern s32 FUN_002d6130(BtlAction* action);
extern s32 FUN_002d6210(BtlAction* action);
extern s32 FUN_002d5f50(BtlAction* action);
extern u16 FUN_003082f0(DatUnit* unit, u64 id);
extern u16 FUN_00308c60(BtlUnit* unit);
extern u16 FUN_00308ed0(BtlUnit* unit);
extern u16 FUN_00308f80(BtlUnit* unit);
extern u16 FUN_003093a0(BtlUnit* unit);
extern void btlActionSetState(BtlAction* action, u16 state);
extern u32 FUN_002dc130(BtlAction* action);
#endif
