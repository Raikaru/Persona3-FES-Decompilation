 #include "Kosaka/k_assert.h"
typedef int code(...);

extern float DAT_007cae00;
extern float DAT_007caf14;
extern float DAT_007caffc;
extern int DAT_006a6040[];
#pragma alias DAT_006a6040_abs DAT_006a6040
extern u8 DAT_006a6040_abs[];
extern int DAT_006a6510[];
#pragma alias DAT_006a6510_abs DAT_006a6510
extern u8 DAT_006a6510_abs[];
#pragma alias DAT_006A66D0_abs DAT_006A66D0
extern u8 DAT_006A66D0_abs[];
extern int DAT_006A6510[];
extern int DAT_006A66D0[];
extern int DAT_006a66d0[];
extern u32 DAT_007ce688;
extern u32 uGpffffb998;
extern s32 iGpffffb998;
extern char gp0xffffaad0;
extern void (*PTR_LAB_007bb900[])();
extern unsigned char DAT_006a6b20[];
extern void FUN_003e6e80(void);
#pragma alias DAT_006a6b20_second DAT_006a6b20
extern unsigned char DAT_006a6b20_second[];
#pragma alias DAT_006a6b20_log DAT_006a6b20
extern unsigned char DAT_006a6b20_log[];
/* FUSION_PROTOS */
u64 FUN_003df4a0(u64 param_1,int param_2);
u32 FUN_003dfac0(int *param_1);
void FUN_003dfae0(int *param_1,int *param_2);
int * FUN_003dfeb0(int param_1);
void FUN_003dff00(s32 param_1);
u32 FUN_003dff30(int *param_1);
int FUN_003dff80(int *param_1,int param_2);
void FUN_003c4710(int *param_1, int *param_2, int *param_3);
int *FUN_003c4820(int *param_1, int *param_2);
int FUN_003dffc0(int *param_1,int param_2,s32 param_3);
void FUN_003e0080(u64 param_1,int param_2,int param_3,u16 param_4);
#pragma alias FUN_003e0080_p FUN_003e0080
extern void FUN_003e0080_p(void *param_1,int param_2,int param_3,u16 param_4);
int FUN_003e0260(u32 param_1,u32 param_2);
int FUN_003e0330(int *param_1,s32 param_2,int param_3,u16 param_4);
int FUN_003e04e0(int *param_1,s32 param_2,int param_3,u16 param_4);
u64 FUN_003e0650(u32 *param_1);
void FUN_003e0680(u32 param_1,code* param_2,u32 param_3);
#pragma alias FUN_003e0680_32 FUN_003e0680
void FUN_003e0680_32(u32 param_1, code* param_2, u32 param_3);
#pragma alias FUN_003e0680_p FUN_003e0680
void FUN_003e0680_p(u32 param_1, code* param_2, void* param_3);
void FUN_003e0700(s32 param_1);
void FUN_003e0780(void);
u32 FUN_003e0830(void);
u64 FUN_003e0870(void);
u64 FUN_003e08e0(void);
void FUN_003e0920(void);
u32 FUN_003e0940(void);
void FUN_003e0950(s32);
#pragma alias FUN_003e0950_narg FUN_003e0950
extern void FUN_003e0950_narg();
void FUN_003e0a10(s32);
void FUN_003e0b70(void);
u8 FUN_003e0bb0(void);
u32 FUN_003e0bc0(void);
void FUN_003e0c20(void *param_1,u32 param_2,u32 param_3);
void FUN_003e6400(u64 param_1,u64 param_2);
/* code typedef moved above prototypes */
#include "h_pad.h"
#include "libm.h"

void memcpy();
void* memset(void*, s32, s32);
s32 sprintf(char*, const char*, ...);
void K_Assert();


extern char DAT_006A6020[];
typedef unsigned char byte;

typedef struct FclList FclList;
typedef struct FclOwner FclOwner;
typedef struct FclTaskLink FclTaskLink;
typedef struct FclNodeMeta FclNodeMeta;
typedef struct FclNodeData FclNodeData;
typedef struct FclResultStream FclResultStream;
typedef struct FclSelection FclSelection;
typedef struct FclSelectionSnapshot FclSelectionSnapshot;
typedef struct FclAnimationRecord FclAnimationRecord;
typedef struct FclResourceNode FclResourceNode;
typedef struct FclResourceMeta FclResourceMeta;
typedef struct FclResourceData FclResourceData;
typedef struct FclNodeListContext FclNodeListContext;
typedef struct FclNodeList FclNodeList;
typedef struct FclNodeLink FclNodeLink;
typedef struct FclAnimationNode FclAnimationNode;
typedef struct FclNodeValueStorage FclNodeValueStorage;
typedef struct FclNodeCreateData FclNodeCreateData;
typedef struct FclAnimationResultRecord FclAnimationResultRecord;
typedef struct FclDrawCallbackData FclDrawCallbackData;
typedef struct FclCallbackProxy FclCallbackProxy;
typedef struct FclCreatedTask FclCreatedTask;
typedef struct FclFusionDetail FclFusionDetail;
typedef struct FclFusionOutput FclFusionOutput;
typedef struct FclPersonaDefinition FclPersonaDefinition;
typedef struct FclPersonaTableEntry FclPersonaTableEntry;
typedef struct FclListUi FclListUi;

struct FclFusionDetail {
    u16 unused_00;                        /* 0x000 */
    u16 persona_id;                       /* 0x002 */
    byte level;                           /* 0x004 */
    byte pad05[0x17];                     /* 0x005 */
    byte base_stat_values[5];             /* 0x01c */
    byte pad21[0x13];                     /* 0x021 */
};

struct FclFusionOutput {
    u32 flags;                            /* 0x000 */
    FclFusionDetail detail;               /* 0x004 */
    byte stat_deltas[5];                  /* 0x038 */
    byte pad3d;                           /* 0x03d */
    s16 changed_skills[8];                /* 0x03e */
    byte pad4e[2];                        /* 0x04e */
    s32 bonus_experience;                 /* 0x050 */
};

struct FclPersonaTableEntry {
    byte data[0xe];
};

struct FclPersonaDefinition {
    u16 unused_00;                        /* 0x000 */
    union {
        byte arcana;
        byte variant_count;
        byte draw_variant;
    } field_02;                           /* 0x002 */
    byte pad03[0x0b];                     /* 0x003 */
};

struct FclSelection {
    u32 flags;                            /* 0x000 */
    u32 state;                            /* 0x004 */
    byte pad08[4];                        /* 0x008 */
    s32 current_choice_index;             /* 0x00c */
    FclFusionDetail** choice_list;        /* 0x010 */
    s32 result_choice_index;              /* 0x014 */
    FclFusionOutput fusion;               /* 0x018 */
    FclFusionDetail result_detail;        /* 0x06c */
    FclListUi* ui;                        /* 0x0a0 */
    s32 bonus_experience;                 /* 0x0a4 */
};

typedef char FclSelectionSizeMustBeA8[
    sizeof(FclSelection) == 0xa8 ? 1 : -1
];
typedef char FclFusionDetailSizeMustBe34[
    sizeof(FclFusionDetail) == 0x34 ? 1 : -1
];
typedef char FclFusionOutputSizeMustBe54[
    sizeof(FclFusionOutput) == 0x54 ? 1 : -1
];

enum FclSelectionState {
    FCL_SELECTION_STATE_INITIALIZE = 0,
    FCL_SELECTION_STATE_READY = 1,
    FCL_SELECTION_STATE_FINISH = 2,
    FCL_SELECTION_STATE_FINISHED = 3,
    FCL_SELECTION_STATE_INPUT = 4,
    FCL_SELECTION_STATE_ACTION_PENDING = 5,
    FCL_SELECTION_STATE_ACTION_WAIT = 6,
    FCL_SELECTION_STATE_ACTION_START = 7,
    FCL_SELECTION_STATE_ACTION_RESULT = 8
};

enum FclSelectionFlag {
    FCL_SELECTION_FLAG_VISIBLE = 0x01,
    FCL_SELECTION_FLAG_CONFIRM = 0x02,
    FCL_SELECTION_FLAG_UI_ACTION_3 = 0x04,
    FCL_SELECTION_FLAG_UI_ACTION_4 = 0x08,
    FCL_SELECTION_FLAG_UI_ACTION_2 = 0x10
};

enum FclFusionOutputFlag {
    FCL_FUSION_OUTPUT_ACTION_3 = 0x02,
    FCL_FUSION_OUTPUT_ACTION_2 = 0x08,
    FCL_FUSION_OUTPUT_ACTION_RESULT = 0x10
};
struct FclSelectionSnapshot {
    byte values[8];
};
struct FclAnimationRecord {
    byte enabled;                       /* 0x000 */
    byte pad01[0x1b];                   /* 0x001 */
};

struct FclList {
    u32 flags;                         /* 0x000 */
    s32 mode;                          /* 0x004 */
    s16 state;                         /* 0x008 */
    u16 state_pad;                     /* 0x00a */
    s32 capacity;                      /* 0x00c */
    s32 used;                          /* 0x010 */
    FclOwner* list;                    /* 0x014 */
    FclFusionDetail** values;             /* 0x018 */
    FclFusionOutput fusion;               /* 0x01c */
    FclListUi* ui;                        /* 0x070 */
    FclSelection selection;               /* 0x074 */
    byte input_copy[0x90];                /* 0x11c */
    FclResultStream* result;              /* 0x1ac */
    FclFusionDetail* embedded_values[1];  /* 0x1b0 */
};
typedef char FclListSizeMustBe1B4[
    sizeof(FclList) == 0x1b4 ? 1 : -1
];

typedef struct FclTaskContainer FclTaskContainer;
struct FclTaskContainer {
    byte prefix[0x44];
    FclList* work;                      /* 0x044 */
};
struct FclOwner {
    byte prefix[4];
    FclTaskLink* links;                 /* 0x004 */
    byte pad08[4];                      /* 0x008 */
    union {
        FclTaskLink* secondary_head;
        FclResourceNode* root_node;
    } root;                             /* 0x00c */
    u16 callback_entry_count;           /* 0x010 */
    byte pad12[0x12];                   /* 0x012 */
    FclTaskContainer* container;        /* 0x024 */
};
typedef struct FclAnimationState FclAnimationState;
struct FclAnimationState {
    u32 flags;                          /* 0x000 */
    byte pad04[0x10];                   /* 0x004 */
    FclOwner* task;                     /* 0x014 */
    byte pad18[0x58];                   /* 0x018 */
    void* ui;                           /* 0x070 */
};
 
typedef struct FclTextRecord FclTextRecord;
typedef struct FclTextFallbackData FclTextFallbackData;
typedef struct FclTextResourceData FclTextResourceData;
typedef struct FclTextResourceMeta FclTextResourceMeta;
typedef struct FclTextResourceNode FclTextResourceNode;
typedef struct FclGlyphSet FclGlyphSet;
typedef struct FclSoundLookup FclSoundLookup;
typedef struct FclTextLayout FclTextLayout;
typedef struct FclTextLayoutTemplate FclTextLayoutTemplate;
typedef union FclTextRuntimeTable FclTextRuntimeTable;

struct FclTextRecord {
    byte pad00[2];                        /* 0x000 */
    s16 text_id;                          /* 0x002 */
    byte format_value;                    /* 0x004 */
};

struct FclTextFallbackData {
    byte pad00[8];                        /* 0x000 */
    s16 fallback_text_ids[1];             /* 0x008 */
};

struct FclTextResourceData {
    byte pad00[4];                        /* 0x000 */
    u32 selection_mask;                   /* 0x004 */
    FclTextRecord* active_record;         /* 0x008 */
    byte pad0c[0x5c];                     /* 0x00c */
    FclTextFallbackData* fallback;        /* 0x068 */
    FclTextRecord* item_records[1];       /* 0x06c */
};

struct FclTextResourceMeta {
    byte pad00[0x1c];                     /* 0x000 */
    FclTextResourceData* data;            /* 0x01c */
};

struct FclTextResourceNode {
    s32 display_index;                    /* 0x000 */
    byte pad04[0x10];                     /* 0x004 */
    FclTextResourceMeta* meta;            /* 0x014 */
};

struct FclGlyphSet {
    char glyphs[0x11];                    /* 0x000 */
};

struct FclSoundLookup {
    byte pad00[2];                        /* 0x000 */
    s16 text_id;                          /* 0x002 */
    byte text_style;                      /* 0x004 */
};

struct FclTextLayout {
    byte data[0x28];                      /* 0x000 */
};

struct FclTextLayoutTemplate {
    byte data[1];                         /* 0x000 */
};

union FclTextRuntimeTable {
    char format_string[1];
    FclTextLayoutTemplate layout_template;
};

struct FclTaskLink {
    byte prefix[0x0c];
    FclTaskLink* secondary_next;         /* 0x00c */
    FclTaskLink* next;                   /* 0x010 */
    FclNodeMeta* payload;               /* 0x014 */
    byte suffix[8];
    FclTaskLink* tail_next;              /* 0x020 */
};


typedef union FclNodeMetaPayload FclNodeMetaPayload;
union FclNodeMetaPayload {
    FclNodeData* node_data;
    FclTextResourceNode* text_node;
};

struct FclNodeMeta {
    byte prefix[0x1c];
    FclNodeMetaPayload data;               /* 0x01c */
};

struct FclNodeData {
    s32 value;                              /* 0x000 */
    FclNodeData* record;                    /* 0x004 */
    FclFusionDetail* selection_detail;      /* 0x008 */
    FclFusionOutput fusion;                 /* 0x00c */
    FclResultStream* callback_target;       /* 0x060 */
    u32 visual_flags;                       /* 0x064 */
    const u16* sound_id;                    /* 0x068 */
    s32 slot_values[1];                     /* 0x06c */
};


struct FclResourceNode {
    byte pad00[0x14];                   /* 0x000 */
    FclResourceMeta* meta;              /* 0x014 */
};

struct FclResourceMeta {
    byte pad00[0x1c];                   /* 0x000 */
    FclResourceData* data;              /* 0x01c */
};

struct FclResourceData {
    byte pad00[0x0c];                   /* 0x000 */
    byte input[0x54];                   /* 0x00c */
    FclResultStream* callback_target;   /* 0x060 */
    u32 mode_flags;                     /* 0x064 */
    byte pad68[4];                      /* 0x068 */
    FclFusionDetail* selection_values[1]; /* 0x06c */
};

struct FclNodeListContext {
    byte pad00[4];                      /* 0x000 */
    FclNodeList* list;                  /* 0x004 */
};

struct FclNodeList {
    byte pad00[4];                      /* 0x000 */
    FclNodeLink* primary_head;          /* 0x004 */
    FclNodeLink* secondary_head;        /* 0x008 */
    byte pad0c[4];                      /* 0x00c */
    u16 allocation_count;               /* 0x010 */
    byte pad12[2];                      /* 0x012 */
};

struct FclNodeLink {
    byte pad00[0x0c];                   /* 0x000 */
    FclNodeLink* secondary_next;        /* 0x00c */
    FclNodeLink* next;                  /* 0x010 */
    FclAnimationNode* payload;          /* 0x014 */
};

struct FclNodeValueStorage {
    s32 values[1];                      /* 0x000 */
};

struct FclAnimationNode {
    s32 value;                          /* 0x000 */
    FclNodeLink* link;                  /* 0x004 */
    u32 flags;                          /* 0x008 */
    u32 field_0c;                       /* 0x00c */
    s32 source_value;                   /* 0x010 */
    s16 current_x;                      /* 0x014 */
    s16 current_y;                      /* 0x016 */
    s16 target_x;                       /* 0x018 */
    s16 target_y;                       /* 0x01a */
    s16 interpolated_x;                 /* 0x01c */
    s16 interpolated_y;                 /* 0x01e */
    s16 current_z;                      /* 0x020 */
    s16 target_z;                       /* 0x022 */
    s16 requested_z;                    /* 0x024 */
    s16 current_w;                      /* 0x026 */
    s16 target_w;                       /* 0x028 */
    s16 endpoint_w;                     /* 0x02a */
    s16 duration;                       /* 0x02c */
    u16 elapsed;                        /* 0x02e */
    u16 divisor;                        /* 0x030 */
    byte pad32[2];                      /* 0x032 */
    FclNodeValueStorage* value_storage; /* 0x034 */
    FclNodeValueStorage inline_storage; /* 0x038 */
};

struct FclNodeCreateData {
    byte pad00[0x38];                   /* 0x000 */
    FclNodeValueStorage inline_storage; /* 0x038 */
};

struct FclAnimationResultRecord {
    s32 value;                          /* 0x000 */
    byte pad04[4];                      /* 0x004 */
    s16 field08;                        /* 0x008 */
    s16 field0a;                        /* 0x00a */
    s16 field0c;                        /* 0x00c */
    s16 field0e;                        /* 0x00e */
    s16 field10;                        /* 0x010 */
    s16 field12;                        /* 0x012 */
    s16 field14;                        /* 0x014 */
    s16 field16;                        /* 0x016 */
    s16 field18;                        /* 0x018 */
    u16 field1a;                        /* 0x01a */
};

struct FclDrawCallbackData {
    s32 callback_arg0;                  /* 0x000 */
    s32 callback_arg1;                  /* 0x004 */
    s16 callback_arg2;                  /* 0x008 */
    s16 flags;                          /* 0x00a */
    FclList* work;                      /* 0x00c */
    FclResourceData* resource_data;     /* 0x010 */
    FclOwner* owner;                    /* 0x014 */
    FclResourceNode* node;              /* 0x018 */
};

typedef void (*FclCallback)(void);
typedef void FclProxyCallback(FclCallbackProxy*);

struct FclCallbackProxy {
    FclList* work;                      /* 0x000 */
    FclCreatedTask* created_task;       /* 0x004 */
};

struct FclCreatedTask {
    byte pad00[0x24];                   /* 0x000 */
    FclCallbackProxy* proxy;            /* 0x024 */
};

typedef struct FclDb650TextData FclDb650TextData;
typedef struct FclDb650Result FclDb650Result;
typedef struct FclDrawResult FclDrawResult;
typedef struct FclDrawCallbackRecord FclDrawCallbackRecord;

struct FclDb650TextData {
    byte pad00[2];                         /* 0x000 */
    u16 glyph_index;                       /* 0x002 */
    byte decimal_value;                    /* 0x004 */
};

struct FclDb650Result {
    byte pad00[0x10];                      /* 0x000 */
    s32 mode;                              /* 0x010 */
    s16 x;                                 /* 0x014 */
    s16 y;                                 /* 0x016 */
    byte pad18[0x0e];                      /* 0x018 */
    s16 alpha;                             /* 0x026 */
    byte pad28[0x0c];                      /* 0x028 */
    FclDb650TextData* text_data;           /* 0x034 */
};

struct FclDrawResult {
    byte pad00[0x10];                      /* 0x000 */
    s32 mode;                              /* 0x010 */
    s16 x_offset;                          /* 0x014 */
    s16 y_offset;                          /* 0x016 */
    byte pad18[0x0e];                      /* 0x018 */
    s16 alpha_scale;                       /* 0x026 */
};

struct FclDrawCallbackRecord {
    s32 x;                                 /* 0x000 */
    s32 y;                                 /* 0x004 */
    s16 alpha;                             /* 0x008 */
    u16 flags;                             /* 0x00a */
    FclList* work;                         /* 0x00c */
    FclNodeData* candidate_data;           /* 0x010 */
    FclOwner* owner;                       /* 0x014 */
    FclTaskLink* candidate;                /* 0x018 */
};

typedef char FclDrawCallbackRecordSizeMustBe1C[
    sizeof(FclDrawCallbackRecord) == 0x1c ? 1 : -1
];


FclOwner* FUN_003c58f0(s32, s32, s32, s32);
s32 FUN_003c6270(s32);
s32 FUN_003c6380(s32);
FclCreatedTask* FUN_003c44d0(s32, s32, s32, FclProxyCallback*);
s32 FUN_003c45f0(s32);
FclNodeLink* FUN_003c4910(FclNodeList*, s32, FclNodeValueStorage*);
s32 FUN_003c4df0(s32, s32);
u32 FUN_003c4e50(s32, s32);
s32 FUN_003c4e70(s32);
s32 FUN_003c5460(...);
s32 FUN_003c6c50(s32);
s32 FUN_003c6c80(s32);
s32 FUN_003c6ca0(s32);
s32 FUN_003c6cc0(s32);
s32 FUN_003c6ce0(s32);
void FUN_003c5a20(s32);
s32 FUN_003c6d10(s32);
s32 FUN_003c6d80(s32);
s32 FUN_003c6ec0(s32);
s32 FUN_003c6ee0(s32);
void FUN_003c6f10(s32);
void FUN_003c6f50(s32);
void FUN_003c9d00(FclListUi*, s32);
void FUN_003c9cd0(FclListUi*, s32);
void FUN_003c9e00(FclListUi*, s32);
void FUN_003c9e70(FclListUi*, s8);
void FUN_003c7430(s32);
void FUN_003c74e0(s32);
s32 FUN_003c7610(void);
void FUN_003c7700(void);
s32 FUN_003c7850(void);
u16 FUN_003d5dc0(u16);
s32 FUN_003d8230(FclFusionOutput*, FclFusionDetail**, s32);
s32 FUN_003d02e0(void);
s32 FUN_003d06d0(s32, s32, s32);
s32 FUN_003d6ae0(s32, s32, s32);
s32 FUN_003d6c90();
s32 FUN_003d6f80();
s32 FUN_003d7180();
s32 FUN_003d71d0();
s32 FUN_003d72f0();
s32 FUN_003d74f0(void);
s32 FUN_003d8370(s32, s32, s32);
s32 FUN_003d8850(s32, s32, s32);
s32 FUN_003d9cc0(s32);
void FUN_003d9ea0(FclList*);
void FUN_003c9b00(FclListUi*, FclFusionDetail*, FclFusionOutput*);
void FUN_0040e3c0(float, s32, s32, byte, s32, s32);
void FUN_0040e3f0(float, float, float, float, s32, s32, byte, s32, s32, s32, s32);
s32 FUN_0040eb50(float, s32, s32, byte, s16, const void*, s32);
s32 FUN_003b32d0(float, s32, s32, s32, s8, s32, const FclGlyphSet*, s32, s32);
void FUN_00523ac8(FclTextLayout*, const FclTextLayoutTemplate*, byte);
s32 FUN_0010a4e0(s32, s32, s32, s32);
u32 FUN_00175410(void);
FclGlyphSet* FUN_00177790(s32);
byte datGetLevel(s16);
extern FclPersonaDefinition* DAT_007ce420[];
extern u8* gp0xffffb730;
extern const FclGlyphSet* DAT_007ce4e4[];
extern const FclTextRuntimeTable DAT_007cd798;
extern u16 DAT_007cd79c;
extern u16 DAT_007cd79e;
extern u16 DAT_007cd7a0;
extern u16 DAT_007cd7a2;
extern u16 DAT_007cd7a4;
extern u16 DAT_007cd7a6;
extern u16 DAT_007cd7a8;
extern u16 DAT_007cd7aa;
extern s16 DAT_007cd7ac;
extern s16 DAT_007cd7ae;
extern s16 DAT_007cd7b0;
extern s16 DAT_007cd7b2;
extern char DAT_007cd7b8;
extern float DAT_007cadd0;
extern float DAT_007cad74;
extern s16 FUN_0016deb0(s16);
extern s8 FUN_0016dba0(s16);
extern s32 FUN_003d58c0(s16, s32);

FclAnimationNode* fclCombineList003df090(FclNodeListContext*, FclNodeCreateData*);
s32 fclCombineList003da3e0(FclList*, s32);
s32 fclCombineList003da470(FclList*, s32);
s32 fclCombineList003dd9e0(FclList*);
s32 fclCombineList003dda80(FclList*);
s32 fclCombineList003ddb00(FclList*);
s32 fclCombineList003de160(FclSelection*);
void fclCombineList003dd260(FclResultStream*, FclDrawResult*, FclDrawCallbackRecord*);
void fclCombineList003df220(FclAnimationNode*, s32, s32, s32, s16, s16);
void fclCombineList003ddb90(FclList*, FclSelection*);
s32 fclCombineList003ddd20(FclSelection*);
void fclCombineList003deb20(FclList*);
void fclCombineList003ded40(FclCallbackProxy*);

// FUN_003da0c0 NONMATCHING
FclList* fclCombineList003da0c0(void* param_1, s32 param_2)
{
    FclOwner* task;
    FclList* work;
    s32 mode;

    mode = param_2 == 0 ? 2 : (param_2 == 1 ? 3 : 0);
    K_ASSERT(mode != 0, 0x3b8);
    task = FUN_003c58f0(0, mode * 4 + 0x1b0, 0xc, 0x18);
    work = task->container->work;
    work->list = task;
    work->mode = param_2;
    work->capacity = mode;
    work->flags = 0;
    work->values = work->embedded_values;
    memcpy(work->input_copy, param_1, 0x90);
    FUN_003d9cc0((s32)work);
    FUN_003d8850((s32)work, 0xb, 0);
    FUN_003d8850((s32)work, 0, 0);
    FUN_003d8850((s32)work, 1, 0);
    FUN_003d8850((s32)work, 4, 0);
    FUN_003d8850((s32)work, 5, 0);
    FUN_003d8850((s32)work, 0xc, 0);
    FUN_003d8850((s32)work, 0xf, 0);
    FUN_003d8850((s32)work, 0x16, 0);
    FUN_003d8850((s32)work, 0xd, 0);
    FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 0);
    return work;
}

// FUN_003da2a0 NONMATCHING
void fclCombineList003da2a0(FclList* param_1)
{
    FclTaskLink* node;
    s32 i;
    s32 j;
    FclTaskLink* selected;

    node = param_1->list->links;
    i = 0;
    selected = 0;
    while (node != 0) {
        FclNodeData* data = node->payload->data.node_data;
        if (data->selection_detail != 0 &&
            data->selection_detail == (FclFusionDetail*)fclCombineList003da3e0(param_1, 0)) {
            selected = node;
            break;
        }
        node = node->next;
        i++;
    }
    if (selected != 0) selected->payload->data.node_data->record = 0;
    node = param_1->list->links;
    j = 0;
    while (node != 0) {
        FclNodeData* data = node->payload->data.node_data;
        if (data->selection_detail != 0 && j != i)
            data->record = (FclNodeData*)FUN_003d8370((s32)param_1->input_copy, i, j);
        else
            data->record = 0;
        j++;
        node = node->next;
    }
}

// FUN_003da3a0
void fclCombineList003da3a0(FclList* param_1)
{
    FclOwner* list;
    list = param_1->list;
    FUN_003dff00((s32)param_1->result);
    FUN_003c5a20((s32)list);
}
// FUN_003da3e0
s32 fclCombineList003da3e0(FclList* param_1, s32 param_2)
{
    s32 p;
    K_ASSERT(param_1 != 0, 0x411);
    if (param_1->capacity <= param_2) return 0;
    p = (s32)param_1->values[param_2];
    if (p != 0) return p;
    return 0;
}
// FUN_003da470 NONMATCHING
s32 fclCombineList003da470(FclList* param_1, s32 param_2)
{
    s32 i;
    s32 p;
    K_ASSERT(param_1 != 0, 0x438);
    if (param_2 == 0) return 0;
    i = 0;
    while (i < param_1->used) {
        K_ASSERT(param_1 != 0, 0x411);
        if (param_1->capacity <= i)
            p = 0;
        else {
            p = (s32)(void *)param_1->values;
            p += i << 2;
            p = *(s32 *)p;
        }
        if (p == 0) {
            i++;
            continue;
        }
        if (p == param_2)
            return param_2;
        i++;
    }
    return 0;
}

// FUN_003da570 NONMATCHING
void fclCombineList003da570(FclList* param_1, s32 param_2)
{
    FclTaskLink* node;
    FclNodeData* data;
    s32 mode;
    s32 i;
    s32 scratch[8];

    node = param_1->list->links;
    mode = param_1->mode;
    memset(scratch, 0, sizeof(scratch));
    memcpy(scratch, param_1->values, param_1->used * 4);
    while (node != 0) {
        data = node->payload->data.node_data;
        i = 0;
        while (i < param_1->capacity &&
               fclCombineList003da3e0(param_1, i) != (s32)data->selection_detail) {
            i++;
        }
        if (i >= param_1->capacity) {
            scratch[param_1->used] = (s32)data->selection_detail;
            FUN_003d6ae0((s32)&data->fusion, param_1->mode, (s32)scratch);
            scratch[param_1->used] = 0;
        } else {
            memset(&data->fusion, 0, 0x54);
        }
        node = node->next;
    }
}

#pragma opt_loop_invariants on
// FUN_003da700 NONMATCHING
s32 fclCombineList003da700(FclList* param_1)
{
    FclTaskLink* node;
    FclTaskLink* candidate;
    FclNodeData* data;
    s32 selection_result;
    s32 selector_mode;
    s32 i;
    s32 candidate_index;
    u16 selected_ids[12];
    byte transformed[0x54];
    FclOwner* list;
    list = param_1->list;
    if (FUN_003c6270((s32)list) == 3) {
        if (param_1->flags & 0x10) return 1;
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 1);
        return 2;
    }
    if (FUN_003c6ce0((s32)list) != 0 || FUN_003c6d10((s32)list) != 0)
        FUN_0010a4e0(0, 0, 0, 0);
    if (FUN_003c6ca0((s32)list) != 0 || FUN_003c6cc0((s32)list) != 0)
        FUN_0010a4e0(0, 0, 0, 5);

    switch (param_1->state) {
    case 0:
    case 1:
    case 2:
        return 0;

    case 3:
        FUN_003d8850((s32)param_1, 0xb, 1);
        candidate = (FclTaskLink*)FUN_003c6c50((s32)list);
        if (candidate == 0) goto state3_cancel;
        data = candidate->payload->data.node_data;
        K_ASSERT(param_1 != 0, 0x465);
        K_ASSERT(data != 0, 0x466);
        if (data->selection_detail != 0 &&
            fclCombineList003da470(param_1, (s32)data->selection_detail) == 0 &&
            ((param_1->flags & 1) == 0 || data->fusion.detail.persona_id != 0))
            goto state3_accept;
state3_reject:
        FUN_0010a4e0(0, 0, 0, 8);
        return 0;

state3_accept:
        FUN_0010a4e0(0, 0, 0, 1);
        FUN_003c4e50((s32)list, (s32)list + 4);
        param_1->values[param_1->used] = data->selection_detail;
        param_1->used++;
        if (param_1->used >= param_1->capacity) {
            param_1->state = 4;
            FUN_003c6f10((s32)list);
            memcpy(&param_1->fusion, &data->fusion, 0x54);
            FUN_003d8850((s32)param_1, 4, 1);
            FUN_003d8850((s32)param_1, 6, 1);
            FUN_003d8850((s32)param_1, 0xc, 1);
            FUN_003d8850((s32)param_1, 0xf, 1);
            FUN_003d8850((s32)param_1, 0x17, 1);
            FUN_003d8850((s32)param_1, 0x1c, 1);
            return 0;
        }

        if (param_1->used + 1 >= param_1->capacity) {
            if ((param_1->flags & 8) == 0 && param_1->used + 1 != param_1->capacity)
                K_ASSERT(0, 0x4ab);
            fclCombineList003da570(param_1, (s32)data);
            param_1->flags |= 1;
            param_1->flags |= 8;
            FUN_003d8850((s32)param_1, 1, 1);
            FUN_003d8850((s32)param_1, 5, 1);
            FUN_003d8850((s32)param_1, 3, 0);
            FUN_003d8850((s32)param_1, 6, 0);
        }
        if (param_1->mode == 1 && param_1->used + 2 == param_1->capacity) {
            fclCombineList003da2a0(param_1);
            FUN_003d8850((s32)param_1, 0xd, 1);
        }
        FUN_003d8850((s32)param_1, 0x17, 1);
        FUN_003d8850((s32)param_1, 0x19, 0);
        return 0;

state3_cancel:
        if (FUN_003c6c80((s32)list) == 0) goto state3_global_cancel;
        FUN_0010a4e0(0, 0, 0, 2);
        if (param_1->used != 0 || param_1->used == param_1->capacity - 1) {
            candidate_index = -1;
            node = list->links;
            while (node != 0) {
                if (node->payload->data.node_data->selection_detail == param_1->values[param_1->used - 1]) {
                    candidate_index = node->payload->data.node_data->fusion.flags - 1;
                    break;
                }
                node = node->next;
            }
            FUN_003c4df0((s32)list, candidate_index);
        } else {
            FUN_003c4df0((s32)list, -1);
        }
        K_ASSERT(param_1 != 0, 0x408);
        param_1->used--;
        param_1->values[param_1->used] = 0;
        if (param_1->flags & 1) {
            param_1->flags &= ~1;
            FUN_003d8850((s32)param_1, 1, 0);
            FUN_003d8850((s32)param_1, 3, 1);
            FUN_003d8850((s32)param_1, 5, 0);
            FUN_003d8850((s32)param_1, 6, 1);
            FUN_003d8850((s32)param_1, 0x16, 0);
            FUN_003d8850((s32)param_1, 0x18, 1);
            FUN_003d8850((s32)param_1, 0x1b, 1);
        } else {
            FUN_003d8850((s32)param_1, 0x16, 0);
            FUN_003d8850((s32)param_1, 0x18, 1);
            FUN_003d8850((s32)param_1, 0x1b, 1);
        }
        if (param_1->used < param_1->capacity - 1) {
            param_1->flags &= ~8;
            if (param_1->used == 0 && param_1->mode == 1) {
                node = list->links;
                while (node != 0) {
                    node->payload->data.node_data->record = 0;
                    node = node->next;
                }
                FUN_003d8850((s32)param_1, 0xd, 0);
            }
            return 0;
        }
        FUN_003c6f50((s32)list);
        param_1->state = 2;
        FUN_003d8850((s32)param_1, 0, 1);
        FUN_003d8850((s32)param_1, 1, 1);
        FUN_003d8850((s32)param_1, 4, 1);
        FUN_003d8850((s32)param_1, 5, 1);
        FUN_003d8850((s32)param_1, 0xc, 1);
        FUN_003d8850((s32)param_1, 0xf, 1);
        FUN_003d8850((s32)param_1, 0x16, 1);
        FUN_003d8850((s32)param_1, 0xd, 1);
        return 0;

state3_global_cancel:
        if ((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_TRIANGLE) == 0 &&
            (gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_TRIANGLE) == 0) return 0;
        FUN_0010a4e0(0, 0, 0, 3);
        node = list->root.secondary_head;
        data = node->payload->data.node_data;
        if (data == 0 || data->selection_detail == 0) return 0;
        param_1->state = 6;
        FUN_003c6f10((s32)list);
        FUN_003c6ea0((s32)list);
        FUN_003d8850((s32)param_1, 4, 1);
        if (param_1->flags & 1)
            FUN_003d8850((s32)param_1, 6, 1);
        else
            FUN_003d8850((s32)param_1, 5, 1);
        FUN_003d8850((s32)param_1, 0xc, 1);
        FUN_003d8850((s32)param_1, 0xf, 1);
        FUN_003d8850((s32)param_1, 0x16, 1);
        FUN_003d8850((s32)param_1, 0x1c, 1);
        if (param_1->used == 0) FUN_003d8850((s32)param_1, 0xd, 1);
        return 0;

    case 4:
        if (FUN_003dff30((int *)param_1->result) == 0) return 0;
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 1);
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 9, 0);
        param_1->state = 5;
        fclCombineList003ddb90(param_1, &param_1->selection);
        goto selection_input;

    case 5:
selection_input:
        selection_result = fclCombineList003ddd20(&param_1->selection);
        if (selection_result == 2) goto selection_back;
        if (selection_result == 1) goto selection_confirm;
        return 0;

    case 6:
        if (FUN_003c6d80((s32)list) & 5) return 0;
        param_1->state = 7;
        fclCombineList003dd9e0(param_1);
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 1);
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 8, 0);

    case 7:
        if (fclCombineList003dda80(param_1) == 0) return 0;
        FUN_0010a4e0(0, 0, 0, 4);
        param_1->state = 3;
        FUN_003c6ee0((s32)list);
        FUN_003d8850((s32)param_1, 4, 0);
        if (param_1->flags & 1)
            FUN_003d8850((s32)param_1, 6, 0);
        else
            FUN_003d8850((s32)param_1, 5, 0);
        FUN_003d8850((s32)param_1, 0xc, 0);
        FUN_003d8850((s32)param_1, 0xf, 0);
        FUN_003d8850((s32)param_1, 0x16, 0);
        FUN_003d8850((s32)param_1, 0x1c, 0);
        if (param_1->used != 0) return 0;
        FUN_003d8850((s32)param_1, 0xd, 0);
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 0);
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 8, 1);
        FUN_003c6ec0((s32)list);
        return 0;
    }

    return 0;

selection_confirm:
    selector_mode = 0;
    if (param_1->mode == 1) selector_mode = 1;
    if (param_1->fusion.flags & 4) selector_mode = 2;
    if (FUN_003d6c90(selector_mode) != 0) {
        memset(selected_ids, 0, sizeof(selected_ids));
        for (i = 0; i < param_1->capacity; i++) {
            K_ASSERT(param_1->values[i] != 0, 0x504);
            selected_ids[i] = param_1->values[i]->persona_id;
        }
        if (FUN_003d7180(selector_mode) != 0) {
            if (FUN_003d71d0(transformed, &param_1->fusion, selected_ids) != 0) {
                param_1->flags |= 0x40;
                param_1->flags |= 0x80;
                memcpy(&param_1->fusion, transformed, 0x54);
            }
        } else if (FUN_003d6f80(transformed, &param_1->fusion, selected_ids) != 0) {
            param_1->flags |= 0x40;
            memcpy(&param_1->fusion, transformed, 0x54);
        }
    }
    FUN_003d72f0((s32)&param_1->fusion.detail);
    FUN_003c6f10((s32)list);
    FUN_003c6f50((s32)list);
    param_1->state = 2;
    param_1->flags |= 0x10;
    return 0;

selection_back:
    FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 5, 0);
    FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 9, 1);
    param_1->state = 3;
    K_ASSERT(param_1 != 0, 0x408);
    param_1->used--;
    param_1->values[param_1->used] = 0;
    FUN_003c6ee0((s32)list);
    FUN_003d8850((s32)param_1, 4, 0);
    FUN_003d8850((s32)param_1, 6, 0);
    FUN_003d8850((s32)param_1, 0xc, 0);
    FUN_003d8850((s32)param_1, 0xf, 0);
    FUN_003d8850((s32)param_1, 0x16, 0);
    FUN_003d8850((s32)param_1, 0x1c, 0);
    return 0;
}
#pragma opt_loop_invariants off

// FUN_003db580
s32 fclCombineList003db580(FclList* param_1)
{
    if (param_1 == 0) return 0;
    FUN_003c6380((s32)param_1->list);
    fclCombineList003ddb00(param_1);
    fclCombineList003de160(&param_1->selection);
    return 0;
}

// FUN_003DB5E0
void fclCombineList003db5e0(FclOwner* param_1)
{
    FclTaskLink* node;

    FUN_003e0650((u32 *)param_1->container->work->result);
    for (node = param_1->links; node != 0; node = node->next) {
        FUN_003e0650((u32 *)node->payload->data.node_data->callback_target);
    }
}


#pragma opt_loop_invariants on
// FUN_003db650 NONMATCHING
void fclCombineList003db650(FclResultStream* stream, FclDb650Result* result,
                             FclOwner* owner)
{
    FclList* work;
    FclDb650TextData* text_data;
    s32 index;
    s32 draw_variant;
    s16 x;
    s16 y;
    s16 alpha;
    char number_text[0x10];
    work = owner->container->work;
    x = result->x;
    y = result->y;
    alpha = result->alpha;
    (void)stream;

    switch (result->mode) {
    case 4:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1a, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1b, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1c, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1d, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1e, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x1f, 0);
        return;

    case 5:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x20, 0);
        for (index = 0; index < (s32)owner->callback_entry_count; index++) {
            FUN_0040e3c0(0.0f, x + index * 0x16, y, alpha,
                         0x21, index * 2);
        }
        return;

    case 6:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x32, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x33, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x34, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x35, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x36, 0);
        return;

    case 9:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x47, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x48, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x49, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x4a, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x4b, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x4c, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x4d, 0);
        return;

    case 10:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x3f, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x40, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x41, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x42, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x43, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x44, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x45, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x46, 0);
        return;

    case 12:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x0e, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x0f, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x10, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x11, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x12, 0);
        FUN_003b32d0(0.0f, x + 0x197, y + 0x33,
                     (s32)alpha | -0x100, 6, 1, FUN_00177790(1), 0x10, 0x74);
        FUN_0040e3c0(0.0f, x + 3, y, alpha, 0x13, 0);
        sprintf(number_text, DAT_007cd798.format_string, (s32)datGetLevel(1));
        FUN_0040eb50(0.0f, x + 0x26b, y + 0x35, alpha,
                      3, number_text, 1);
        return;

    case 13:
        if ((work->flags & 0x10000) == 0) return;
        index = (s32)(FUN_00175410() & 0xffff) - 4;
        FUN_0040e3f0(1.0f, 1.0f, 1.0f + 0.2f * (float)index,
                      1.0f + 0.2f * (float)index,
                      x + 0x16c + index * 5,
                      y + 0x88 + index * 6, alpha, 0x2e, 0, 0, 0);
        return;

    case 14:
        if ((work->flags & 0x10000) == 0) return;
        index = (s32)(FUN_00175410() & 0xffff) - 4;
        FUN_0040e3f0(1.0f, 1.0f, 1.0f + 0.2f * (float)index,
                      1.0f + 0.2f * (float)index,
                      x + 0x16c + index * 5,
                      y + 0x88 + index * 6, alpha, 0x2e, 0, 0, 0);
        return;
    case 15:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(2.0f, x, y, alpha, 0x0b, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x0c, work->mode);
        return;

    case 20:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x15, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x16, 0);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x17, 0);
        text_data = result->text_data;
        if (text_data == 0 || text_data->glyph_index == 0) return;
        draw_variant = (s32)DAT_007ce420[text_data->glyph_index]->field_02.draw_variant;
        FUN_0040e3c0(0.0f, x, y, alpha, 0x18,
                      (byte)((draw_variant - 1) * 2));
        FUN_003b32d0(0.0f, x + 0x8a, y + 0x35,
                     (s32)alpha | -0x100, 6, 3,
                     DAT_007ce4e4[text_data->glyph_index], 0x10, 0x6e);
        FUN_0040e3c0(0.0f, x, y, alpha, 0x14, 0);
        sprintf(number_text, DAT_007cd798.format_string, (s32)text_data->decimal_value);
        FUN_0040eb50(0.0f, x + 0x157, y + 0x34, alpha,
                      3, number_text, 1);
        return;

    case 21:
        if ((work->flags & 0x10000) != 0) return;
        FUN_0040e3c0(0.0f, x, y + 0x1a, alpha, 0x16, 1);
        FUN_0040e3c0(0.0f, x, y + 0x1a, alpha, 0x17, 0);
        text_data = result->text_data;
        if (text_data == 0 || text_data->glyph_index == 0) return;
        draw_variant = (s32)DAT_007ce420[text_data->glyph_index]->field_02.draw_variant;
        FUN_0040e3c0(0.0f, x, y + 0x1a, alpha, 0x18,
                      (byte)((draw_variant - 1) * 2));
        FUN_003b32d0(0.0f, x + 0x8a, y + 0x4f,
                     (s32)alpha | -0x100, 6, 3,
                     DAT_007ce4e4[text_data->glyph_index], 0x10, 0x6e);
        FUN_0040e3c0(0.0f, x, y + 0x1a, alpha, 0x14, 0);
        sprintf(number_text, DAT_007cd798.format_string, (s32)text_data->decimal_value);
        FUN_0040eb50(0.0f, x + 0x157, y + 0x4e, alpha,
                      3, number_text, 1);
        return;

    case 7:
    case 8:
    case 11:
    case 16:
    case 17:
    case 18:
    case 19:
    default:
        return;
    }
}
#pragma opt_loop_invariants off

// FUN_003dc210
void fclCombineList003dc210(s32 unused0, s32 unused1, s32 unused2, FclOwner* owner)
{
    FclList* work = owner->container->work;

    (void)unused0;
    (void)unused1;
    (void)unused2;
    FUN_003e0680_32((u32)(void *)work->result,
                    (code *)fclCombineList003db650,
                    (u32)(void *)owner);
    work->flags |= 0x10000;
    FUN_003c4e70((s32)owner);
    work->flags &= 0xfffeffff;
    work->flags |= 0x10000;
    FUN_003e0680_32((u32)(void *)work->result,
                    (code *)fclCombineList003db650,
                    (u32)(void *)owner);
    work->flags &= 0xfffeffff;
}

#pragma opt_loop_invariants on
// FUN_003dc2d0 NONMATCHING
void fclCombineList003dc2d0(s32 base_x, s32 base_y, s16 alpha, FclOwner* owner,
                             FclTaskLink* source_link, s32 selected_style,
                             s32 alternate_layout)
{
    FclTextResourceNode* resource_node;
    FclTextResourceData* resource_data;
    FclTextRecord* record;
    FclPersonaDefinition* definition;
    char formatted_text[0x28];
    u16 glyph_styles[2];
    u16 string_styles[2];
    s32 i;
    float scaled_alpha;
    u32 scaled_color;

    resource_node = source_link->payload->data.text_node;
    resource_data = resource_node->meta->data;
    record = resource_data->active_record;
    glyph_styles[0] = DAT_007cd79c;
    glyph_styles[1] = DAT_007cd79e;
    string_styles[0] = DAT_007cd7a0;
    string_styles[1] = DAT_007cd7a2;

    if (record == 0) {
        FUN_0040e3c0(0.0f, base_x, base_y, (byte)alpha, 0x26, 0);
        for (i = 0; i < 8; i++) {
            FUN_0040e3c0(0.0f, base_x + i * 0x15, base_y, (byte)alpha,
                          0x27, selected_style);
        }
        for (i = 0; i < 2; i++) {
            FUN_0040e3c0(0.0f, base_x + i * 0x15, base_y, (byte)alpha,
                          0x28, selected_style);
        }
    } else {
        definition = DAT_007ce420[record->text_id];
        sprintf(formatted_text, DAT_007cd798.format_string, record->format_value);

        if (alternate_layout == 0) {
            FUN_0040e3c0(0.0f, base_x, base_y, (byte)alpha, 0x25,
                          (definition->field_02.variant_count - 1) * 2 + selected_style);
            FUN_003b32d0(0.0f, base_x + 0x76, base_y + 0x7e,
                          ((u32)(byte)alpha) | 0xffffff00,
                          (s8)glyph_styles[selected_style], 1,
                          DAT_007ce4e4[record->text_id], 0x10, 0x6e);
            FUN_0040eb50(0.0f, base_x + 0x145, base_y + 0x7f, (byte)alpha,
                          (s16)string_styles[selected_style], formatted_text, 1);
        } else {
            FUN_0040e3c0(0.0f, base_x, base_y, (byte)alpha, 0x25,
                          (definition->field_02.variant_count - 1) * 2 + 1);
            if (selected_style == 0) {
                scaled_alpha = DAT_007cadd0 * (float)alpha;
                scaled_color = ((u32)scaled_alpha & 0xff) | 0xffffff00;
                FUN_003b32d0(0.0f, base_x + 0x76, base_y + 0x7e, scaled_color,
                              (s8)glyph_styles[0], 1,
                              DAT_007ce4e4[record->text_id], 0x10, 0x6e);
                FUN_0040eb50(0.0f, base_x + 0x145, base_y + 0x7f,
                              (byte)scaled_alpha, (s16)string_styles[0],
                              formatted_text, 1);
            } else {
                FUN_003b32d0(0.0f, base_x + 0x76, base_y + 0x7e,
                              ((u32)(byte)alpha) | 0xffffff00,
                              (s8)glyph_styles[selected_style], 1,
                              DAT_007ce4e4[record->text_id], 0x10, 0x6e);
                FUN_0040eb50(0.0f, base_x + 0x145, base_y + 0x7f, (byte)alpha,
                              (s16)string_styles[selected_style], formatted_text, 1);
            }
        }
    }

    if (alternate_layout == 0 && selected_style == 0) {
        FUN_0040e3c0(0.0f, base_x, base_y, (byte)alpha, 0x24,
                      (resource_node->display_index - 1) * 2);
    } else {
        FUN_0040e3c0(0.0f, base_x, base_y, (byte)alpha, 0x24,
                      (resource_node->display_index - 1) * 2 + 1);
    }

    (void)owner;
}
#pragma opt_loop_invariants off

// FUN_003dc700 NONMATCHING
void fclCombineList003dc700(s32 base_x, s32 base_y, s16 alpha, FclOwner* owner,
                             FclTaskLink* source_link, s32 selected_style,
                             s32 unused_alternate)
{
    FclTextResourceNode* resource_node;
    FclTextResourceData* resource_data;
    FclTextRecord* record;
    FclPersonaDefinition* definition;
    char formatted_text[0x28];
    u16 text_styles[4];
    s32 i;
    s32 fallback_text_id;
    s32 row_y;
    float scaled_alpha;
    u32 scaled_color;

    resource_node = source_link->payload->data.text_node;
    resource_data = resource_node->meta->data;
    text_styles[2] = DAT_007cd7a4;
    text_styles[3] = DAT_007cd7a6;
    text_styles[0] = DAT_007cd7a8;
    text_styles[1] = DAT_007cd7aa;
    scaled_alpha = DAT_007cadd0 * (float)alpha;

    for (i = 0; i < owner->container->work->capacity; i++) {
        record = resource_data->item_records[i];
        row_y = base_y + i * 0x18;

        if (record == 0) {
            fallback_text_id = resource_data->fallback->fallback_text_ids[i];
            definition = DAT_007ce420[fallback_text_id];
            FUN_0040e3c0(0.0f, base_x, row_y, (byte)alpha, 0x25,
                          (definition->field_02.variant_count - 1) * 2 + 1);
            scaled_color = ((u32)scaled_alpha & 0xff) | 0xffffff00;
            FUN_003b32d0(0.0f, base_x + 0x76, row_y + 0x7e, scaled_color,
                          (s8)text_styles[selected_style + 2], 1,
                          DAT_007ce4e4[fallback_text_id], 0x10, 0x6e);
            FUN_0040e3c0(0.0f, base_x, row_y, (byte)alpha, 0x24, i * 2 + 1);
        } else {
            definition = DAT_007ce420[record->text_id];
            sprintf(formatted_text, DAT_007cd798.format_string, record->format_value);
            FUN_0040e3c0(0.0f, base_x, row_y, (byte)alpha, 0x25,
                          (definition->field_02.variant_count - 1) * 2 + selected_style);
            FUN_003b32d0(0.0f, base_x + 0x76, row_y + 0x7e,
                          ((u32)(byte)alpha) | 0xffffff00,
                          (s8)text_styles[selected_style + 2], 1,
                          DAT_007ce4e4[record->text_id], 0x10, 0x6e);
            FUN_0040eb50(0.0f, base_x + 0x145, row_y + 0x7f, (byte)alpha,
                          (s16)text_styles[selected_style], formatted_text, 1);
            FUN_0040e3c0(0.0f, base_x, row_y, (byte)alpha, 0x24,
                          i * 2 + selected_style);
        }
    }

    (void)unused_alternate;
}

// FUN_003dca10 NONMATCHING
void fclCombineList003dca10(s32 base_x, s32 base_y, s16 alpha, FclOwner* owner,
                             FclTaskLink* source_link, s32 selected_style)
{
    FclTextResourceNode* resource_node;
    FclTextResourceData* resource_data;
    s32 available_count;
    s32 i;

    available_count = (s32)(FUN_00175410() & 0xffff);
    resource_node = source_link->payload->data.text_node;
    resource_data = resource_node->meta->data;

    if (owner->container->work->capacity == 3) {
        for (i = 0; i < 0xc; i++) {
            if (i < available_count) {
                if ((resource_data->selection_mask & (1 << i)) == 0) {
                    FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                                  0x2b, selected_style);
                } else {
                    FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                                  0x2a, selected_style);
                }
            } else {
                FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                              0x2d, 0);
            }
        }
    } else {
        for (i = 0; i < 0xc; i++) {
            if (i < available_count) {
                if ((resource_data->selection_mask & (1 << i)) == 0) {
                    FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                                  0x2b, selected_style);
                } else {
                    FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                                  0x2a, selected_style);
                }
            } else {
                FUN_0040e3c0(0.0f, base_x + i * 0x16, base_y, (byte)alpha,
                              0x2d, 0);
            }
        }
    }
}

#pragma opt_loop_invariants on
// FUN_003dcc90 NONMATCHING
void fclCombineList003dcc90(s32 x, s32 y, s16 alpha, FclOwner* owner,
                             FclTaskLink* source_link, s32 selected)
{
    FclNodeData* data;
    FclSoundLookup lookup;
    FclTextLayout layout;
    s16 text_shades[2];
    s16 text_palettes[2];
    s16 text_id;
    byte text_style;
    s32 draw_variant;
    s32 i;

    text_shades[0] = DAT_007cd7ac;
    text_shades[1] = DAT_007cd7ae;
    text_palettes[0] = DAT_007cd7b0;
    text_palettes[1] = DAT_007cd7b2;
    data = source_link->payload->data.node_data;

    if (data->fusion.detail.persona_id == 0) {
        if (data->sound_id != 0) {
            FUN_00176680(&lookup, *data->sound_id);
            text_id = lookup.text_id;
            text_style = lookup.text_style;
            draw_variant = DAT_007ce420[text_id]->field_02.draw_variant;
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x39,
                          (draw_variant - 1) * 2 + selected);

            if (((data->visual_flags & 2) == 0) && ((data->visual_flags & 1) != 0)) {
                for (i = 0; i < 8; i++) {
                    FUN_0040e3c0(0.0f, x + 0x122 + i * 0x15, y, (byte)alpha,
                                  0x27, selected);
                }
                for (i = 0; i < 2; i++) {
                    FUN_0040e3c0(0.0f, x + 0x122 + i * 0x15, y, (byte)alpha,
                                  0x28, selected);
                }
            } else {
                FUN_003b32d0(0.0f, x + 0x19c, y + 0x7e,
                              (s32)((byte)alpha | 0xffffff00),
                              (s8)(text_shades[selected] >> 8), 1,
                              DAT_007ce4e4[text_id], 0x10, 0x6e);
                FUN_00523ac8(&layout, &DAT_007cd798.layout_template, text_style);
                FUN_0040eb50(0.0f, x + 0x260, y + 0x7f, (byte)alpha,
                              text_palettes[selected], &layout, 1);
            }
        }
    } else {
        text_id = data->fusion.detail.persona_id;
        text_style = data->fusion.detail.level;
        draw_variant = DAT_007ce420[text_id]->field_02.draw_variant;
        FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x39,
                      (draw_variant - 1) * 2 + selected);
        FUN_003b32d0(0.0f, x + 0x19c, y + 0x7e,
                      (s32)((byte)alpha | 0xffffff00),
                      (s8)(text_shades[selected] >> 8), 1,
                      DAT_007ce4e4[text_id], 0x10, 0x6e);
        FUN_00523ac8(&layout, &DAT_007cd798.layout_template, text_style);
        FUN_0040eb50(0.0f, x + 0x260, y + 0x7f, (byte)alpha,
                      text_palettes[selected], &layout, 1);
    }

    (void)owner;
}
#pragma opt_loop_invariants off

// FUN_003dcfb0 NONMATCHING
void fclCombineList003dcfb0(FclResultStream* callback_target, FclDrawResult* result,
                             FclDrawCallbackRecord* record, s32 selected)
{
    s32 x;
    s32 y;
    s16 alpha;

    x = record->x + result->x_offset;
    y = record->y + result->y_offset;
    alpha = (s16)(((s32)record->alpha * (s32)result->alpha_scale) / 0xff);
    if (selected == 0) {
        alpha = (s16)((float)alpha * DAT_007cad74);
    }

    if (record->owner->container->work->mode < 2) {
        if ((record->work->flags & 1) == 0) {
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x31, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x2f, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x30, 0);
        } else if ((record->flags & 2) == 0) {
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x31, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3c, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x2f, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3b, 0);
        } else {
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x31, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3d, 0);
            FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3e, 0);
        }
    } else {
        FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x53, 0);
        FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x51, 0);
        FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x52, 0);
    }

    (void)callback_target;
}
// FUN_003dd260 NONMATCHING
void fclCombineList003dd260(FclResultStream* callback_target, FclDrawResult* result,
                             FclDrawCallbackRecord* record)
{
    s32 x;
    s32 y;
    s32 i;
    s32 selected;
    s32 alternate;
    s32 mode;
    s16 alpha;

    x = record->x + result->x_offset;
    y = record->y + result->y_offset;
    alpha = (s16)(((s32)record->alpha * (s32)result->alpha_scale) / 0xff);
    selected = (record->flags & 1) != 0;
    alternate = (record->flags & 2) != 0;
    mode = result->mode;

    if (alpha != 0) {
        switch (mode) {
        case 11:
            if ((record->work->flags & 0x10000) == 0) {
                fclCombineList003dcfb0(callback_target, result, record, selected);
            }
            break;

        case 0:
            if ((record->work->flags & 0x10000) == 0) {
                fclCombineList003dc2d0(x, y, alpha, record->owner, record->candidate,
                                        selected, alternate);
            } else {
                if (alternate != 0) {
                    FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x23, selected);
                } else {
                    FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x22, selected);
                }
                FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x29, 0);
            }
            break;

        case 1:
            if ((record->work->flags & 0x10000) != 0) {
                fclCombineList003dca10(x, y, alpha, record->owner,
                                        record->candidate, selected);
            }
            break;

        case 2:
            if ((record->work->flags & 0x10000) != 0) {
                FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x31, 0);
                FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3d, 0);
                FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3e, 0);
            }
            break;

        case 3:
            if (alternate == 0) {
                if ((record->work->flags & 0x10000) == 0) {
                    fclCombineList003dcc90(x, y, alpha, record->owner,
                                            record->candidate, selected);
                } else {
                    FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x37, 0);
                    FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x38, selected);
                    FUN_0040e3c0(0.0f, x, y, (byte)alpha, 0x3a, 0);
                }
            }
            break;

        case 7:
            if ((record->work->flags & 0x10000) == 0) {
                fclCombineList003dcc90(x - 0x145, y, alpha, record->owner,
                                        record->candidate, selected);
            } else {
                FUN_0040e3c0(0.0f, x - 0x145, y, (byte)alpha, 0x37, 0);
                FUN_0040e3c0(0.0f, x - 0x145, y, (byte)alpha, 0x38, selected);
                FUN_0040e3c0(0.0f, x - 0x145, y, (byte)alpha, 0x3a, 0);
            }
            break;

        case 8:
            if (selected != 0) {
                if ((record->work->flags & 0x10000) == 0) {
                    for (i = 0; i < record->owner->container->work->capacity; i++) {
                        if (record->candidate_data->slot_values[i] == 0) {
                            FUN_0040e3c0(0.0f, x + 0x128, result->y_offset + i * 0x18,
                                          (byte)alpha, 0x23, 0);
                            FUN_0040e3c0(0.0f, x + 0x128, result->y_offset + i * 0x18,
                                          (byte)alpha, 0x29, 0);
                        } else {
                            FUN_0040e3c0(0.0f, x + 0x128, result->y_offset + i * 0x18,
                                          (byte)alpha, 0x22, 0);
                            FUN_0040e3c0(0.0f, x + 0x128, result->y_offset + i * 0x18,
                                          (byte)alpha, 0x29, 0);
                        }
                    }
                } else {
                    fclCombineList003dc700(x + 0x128, result->y_offset, alpha,
                                            record->owner, record->candidate, 0, 0);
                }
            }
            break;
        }
    }
}

// FUN_003dd800 NONMATCHING
void fclCombineList003dd800(s32 x, s32 y, s32 alpha, FclOwner* owner,
                             FclTaskLink* candidate)
{
    FclDrawCallbackRecord record;
    FclList* work;
    FclNodeData* candidate_data;
    FclFusionDetail* selection_detail;
    FclFusionDetail* list_detail;
    s32 i;
    s32 found;

    memset(&record, 0, sizeof(record));
    work = owner->container->work;
    candidate_data = candidate->payload->data.node_data;

    if (candidate == owner->root.secondary_head) {
        record.flags |= 1;
    }

    found = 0;
    selection_detail = candidate_data->selection_detail;
    if ((selection_detail != 0) &&
        (((work->flags & 1) == 0) || (candidate_data->fusion.detail.persona_id != 0))) {
        K_ASSERT(work != 0, 0x438);
        for (i = 0; i < work->used; i++) {
            K_ASSERT(work != 0, 0x411);
            if (i < work->capacity) {
                list_detail = work->values[i];
            } else {
                list_detail = 0;
            }
            if (list_detail == selection_detail) {
                found = 1;
                break;
            }
        }
    }

    if (found == 0) {
        record.flags |= 2;
    }

    record.x = x;
    record.y = y;
    record.alpha = alpha;
    record.work = work;
    record.candidate_data = candidate_data;
    record.owner = owner;
    record.candidate = candidate;
    FUN_003e0680((u64)(u32)(void *)candidate_data->callback_target,
                  (code*)fclCombineList003dd260, (u64)(u32)(void *)&record);
}

// FUN_003dd9e0
s32 fclCombineList003dd9e0(FclList* list)
{
    FclNodeData* data;

    data = list->list->root.secondary_head->payload->data.node_data;
    list->flags |= 0x20;
    FUN_003c9d00(list->ui, 4);
    FUN_003c9d00(list->ui, 8);
    FUN_003c9e00(list->ui, 0);
    FUN_003c9cd0(list->ui, -1);
    FUN_003c9b00(list->ui, data->selection_detail, 0);
    return 0;
}

// FUN_003dda80
s32 fclCombineList003dda80(FclList* param_1)
{
    s32 enabled = 0;

    if ((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_CIRCLE) != 0 ||
        (gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_CIRCLE) != 0) {
        enabled = 1;
        param_1->flags &= ~0x20;
        FUN_003c9d00(param_1->ui, 0x10);
    }
    return enabled;
}

// FUN_003ddb00
s32 fclCombineList003ddb00(FclList* list)
{
    FclNodeData* data;
    FclSelectionSnapshot local;
    byte* cleared;
    s32 clear_count;

    cleared = local.values;
    clear_count = sizeof(local);
    if (cleared != 0) {
        do {
            *cleared = 0;
            cleared++;
            clear_count--;
        } while (clear_count != 0);
    }
    if ((list->flags & 0x20) == 0) return 0;

    data = list->list->root.secondary_head->payload->data.node_data;
    FUN_003c9b00(list->ui, data->selection_detail, 0);
    return 0;
}

// FUN_003ddb90
void fclCombineList003ddb90(FclList* list, FclSelection* selection)
{
    s32 result_choice_index;
    s32 i;
    s16 social_link_index;
    s32 bonus_experience;

    s32 persona_offset;
    memset(selection, 0, 0xa8);
    selection->flags |= 1;
    selection->state = 0;
    selection->choice_list = list->values;
    result_choice_index = list->capacity;
    selection->result_choice_index = result_choice_index;
    selection->current_choice_index = result_choice_index;
    memcpy(&selection->fusion, &list->fusion, 0x54);
    memcpy(&selection->result_detail, &list->fusion.detail, 0x34);
    for (i = 0; i < 5; i++) {
        *(((byte *)((s32)selection + i)) + 0x88) -=
            *(((byte *)((s32)list + i)) + 0x54);
    }
    selection->ui = list->ui;
    FUN_003c9d00(selection->ui, 4);
    FUN_003c9d00(selection->ui, 8);
    FUN_003c9e00(selection->ui, 2);
    FUN_003c9e30(selection->ui, (s8)(selection->result_choice_index + 1),
                  (s8)selection->current_choice_index);
    FUN_003c9b00(selection->ui, &selection->result_detail, &selection->fusion);
    persona_offset = selection->result_detail.persona_id;
    persona_offset = persona_offset * 0xe;
    persona_offset += (s32)(void *)gp0xffffb730;
    social_link_index = FUN_0016deb0(
        ((FclPersonaTableEntry *)(void *)persona_offset)->data[2]);
    if (FUN_0016dba0(social_link_index) != 0) {
        bonus_experience = FUN_003d58c0(social_link_index, selection->result_detail.level);
        selection->bonus_experience = bonus_experience;
        selection->fusion.bonus_experience = bonus_experience;
    }
}

// FUN_003ddd20 NONMATCHING
s32 fclCombineList003ddd20(FclSelection* selection)
{
    switch (selection->state) {
    case FCL_SELECTION_STATE_INITIALIZE:
        selection->state = FCL_SELECTION_STATE_READY;
        break;

    case FCL_SELECTION_STATE_READY:
        selection->state = FCL_SELECTION_STATE_INPUT;
        break;

    case FCL_SELECTION_STATE_FINISH:
        selection->state = FCL_SELECTION_STATE_FINISHED;
        selection->flags &= ~FCL_SELECTION_FLAG_VISIBLE;
        FUN_003c9d00(selection->ui, 0x10);
        if ((selection->flags & FCL_SELECTION_FLAG_CONFIRM) != 0) {
            selection->flags &= ~FCL_SELECTION_FLAG_CONFIRM;
            return 1;
        }
        return 2;

    case FCL_SELECTION_STATE_FINISHED:
        break;

    case FCL_SELECTION_STATE_INPUT:
        if (((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_L1) != 0) ||
            ((gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_L1) != 0)) {
            FUN_0010a4e0(0, 0, 0, 5);
            selection->current_choice_index--;
            if (selection->current_choice_index < 0) {
                selection->current_choice_index = selection->result_choice_index;
            }
        } else if (((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_R1) != 0) ||
                   ((gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_R1) != 0)) {
            FUN_0010a4e0(0, 0, 0, 5);
            selection->current_choice_index++;
            if (selection->result_choice_index < selection->current_choice_index) {
                selection->current_choice_index = 0;
            }
        } else if (((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_CROSS) != 0) ||
                   ((gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_CROSS) != 0)) {
            FUN_0010a4e0(0, 0, 0, 1);
            if (selection->current_choice_index == selection->result_choice_index) {
                selection->state = FCL_SELECTION_STATE_ACTION_PENDING;
            } else {
                selection->current_choice_index = selection->result_choice_index;
            }
        } else if (((gPads[HPAD_PORT_1].btn[0].justPressed & HPAD_BTN_CIRCLE) != 0) ||
                   ((gPads[HPAD_PORT_1].btn[1].released & HPAD_BTN_CIRCLE) != 0)) {
            FUN_0010a4e0(0, 0, 0, 2);
            if (selection->current_choice_index == selection->result_choice_index) {
                selection->state = FCL_SELECTION_STATE_FINISH;
            } else {
                selection->current_choice_index = selection->result_choice_index;
            }
        }
        break;

    case FCL_SELECTION_STATE_ACTION_PENDING:
        selection->state = FCL_SELECTION_STATE_ACTION_START;
        break;

    case FCL_SELECTION_STATE_ACTION_WAIT:
        if (FUN_003c7850() == 0) {
            FUN_003c7700();
            selection->state = FCL_SELECTION_STATE_ACTION_START;
        }
        break;

    case FCL_SELECTION_STATE_ACTION_START:
        if ((selection->fusion.flags & FCL_FUSION_OUTPUT_ACTION_3) != 0) {
            selection->flags |= FCL_SELECTION_FLAG_UI_ACTION_3;
            FUN_003c7430(3);
        } else if (FUN_003d8230(&selection->fusion, selection->choice_list,
                                 selection->result_choice_index) != 0) {
            selection->flags |= FCL_SELECTION_FLAG_UI_ACTION_4;
            FUN_003c7430(4);
        } else if ((selection->fusion.flags & FCL_FUSION_OUTPUT_ACTION_2) != 0) {
            selection->flags |= FCL_SELECTION_FLAG_UI_ACTION_2;
            FUN_003c7430(2);
        } else {
            FUN_003c7430((s32)FUN_003d5dc0(selection->fusion.detail.persona_id));
            FUN_003c74e0(0);
        }
        selection->state = FCL_SELECTION_STATE_ACTION_RESULT;

    case FCL_SELECTION_STATE_ACTION_RESULT:
        if (FUN_003c7850() == 0) {
            FUN_003c7700();
            if ((selection->fusion.flags & FCL_FUSION_OUTPUT_ACTION_RESULT) != 0) {
                selection->flags &= ~FCL_SELECTION_FLAG_UI_ACTION_2;
                selection->state = FCL_SELECTION_STATE_INPUT;
            } else if ((selection->flags & FCL_SELECTION_FLAG_UI_ACTION_3) != 0) {
                selection->flags &= ~FCL_SELECTION_FLAG_UI_ACTION_3;
                selection->state = FCL_SELECTION_STATE_INPUT;
            } else if ((selection->flags & FCL_SELECTION_FLAG_UI_ACTION_4) != 0) {
                selection->flags &= ~FCL_SELECTION_FLAG_UI_ACTION_4;
                selection->state = FCL_SELECTION_STATE_INPUT;
            } else if (FUN_003c7610() == 0) {
                selection->state = FCL_SELECTION_STATE_FINISH;
                selection->flags |= FCL_SELECTION_FLAG_CONFIRM;
            } else {
                selection->state = FCL_SELECTION_STATE_INPUT;
            }
        }
        break;

    default:
        break;
    }
    return 0;
}

// FUN_003de160
s32 fclCombineList003de160(FclSelection* selection)
{
    FclListUi* ui;
    FclFusionDetail* detail;
    FclFusionOutput* fusion;
    u32 flags;
    FclSelectionSnapshot local;
    byte* cleared;
    s32 clear_count;

    ui = selection->ui;
    cleared = local.values;
    clear_count = sizeof(local);
    if (cleared != 0) {
        do {
            *cleared = 0;
            cleared++;
            clear_count--;
        } while (clear_count != 0);
    }
    if ((selection->flags & 1) == 0) return 0;

    if (selection->current_choice_index == selection->result_choice_index) {
        detail = &selection->result_detail;
        fusion = &selection->fusion;
        flags = selection->fusion.flags;
    } else {
        detail = selection->choice_list[selection->current_choice_index];
        fusion = 0;
        flags = 0;
    }
    FUN_003c9e70(ui, (s8)selection->current_choice_index);
    FUN_003c9b00(ui, detail, fusion);
    if ((flags & 2) != 0 || (flags & 8) != 0)
        FUN_003c9cd0(ui, 0x202020ff);
    else
        FUN_003c9cd0(ui, -1);
    return 0;
}

// FUN_003de290 NONMATCHING
FclList* fclCombineList003de290(void* input, s32 state)
{
    FclOwner* task;
    FclList* work;
    s32 capacity;

    capacity = state == 4 ? 6 : (state == 3 ? 5 : (state == 2 ? 4 : 0));
    K_ASSERT(capacity != 0, 0x966);
    task = FUN_003c58f0(0, capacity * 4 + 0x1b0, 0xc, 0x18);
    work = task->container->work;
    work->list = task;
    work->mode = state;
    work->capacity = capacity;
    work->flags = 0;
    work->values = work->embedded_values;
    memcpy(work->input_copy, input, 0x90);
    FUN_003d9ea0(work);
    FUN_003d8850((s32)work, 0xb, 0);
    FUN_003d8850((s32)work, 7, 0);
    FUN_003d8850((s32)work, 8, 0);
    FUN_003d8850((s32)work, 9, 0);
    FUN_003d8850((s32)work, 0xa, 0);
    FUN_003d8850((s32)work, 0xc, 0);
    FUN_003d8850((s32)work, 0xf, 0);
    FUN_003d8850((s32)work, 0x16, 0);
    FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 6, 0);
    return work;
}

// FUN_003de470
s32 fclCombineList003de470(FclList* work)
{
    s32 selection_state;
    s32 i;
    byte validated_input[0x54];
    s16 selected_values[0xc];
    FclResourceNode* selection;
    FclResourceData* resource_data;
    FclOwner* task = work->list;

    if (FUN_003c6270((s32)task) == 3) {
        if ((work->flags & 0x10) != 0) return 1;
        FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 6, 1);
        return 2;
    }
    if (FUN_003c6ce0((s32)task) != 0 || FUN_003c6d10((s32)task) != 0)
        FUN_0010a4e0(0, 0, 0, 0);
    if (FUN_003c6ca0((s32)task) != 0 || FUN_003c6cc0((s32)task) != 0)
        FUN_0010a4e0(0, 0, 0, 5);

    switch (work->state) {
    case 2:
        break;

    case 3:
        FUN_003d8850((s32)work, 0xb, 1);
        selection = (FclResourceNode*)FUN_003c6c50((s32)task);
        if (selection != 0) {
            resource_data = selection->meta->data;
            if ((resource_data->mode_flags & 1) != 0) {
                FUN_0010a4e0(0, 0, 0, 8);
                break;
            }
            FUN_0010a4e0(0, 0, 0, 1);
            work->state = 4;
            FUN_003c6f10((s32)task);
            memcpy(&work->fusion, resource_data->input, sizeof(work->fusion));
            fclCombineList003deb20(work);
            FUN_003d6ae0((s32)&work->fusion, *(volatile s32 *)&work->mode,
                         (s32)work->values);
            FUN_003d8850((s32)work, 7, 1);
            FUN_003d8850((s32)work, 8, 1);
            FUN_003d8850((s32)work, 9, 1);
            FUN_003d8850((s32)work, 0xa, 1);
            FUN_003d8850((s32)work, 0xc, 1);
            FUN_003d8850((s32)work, 0xf, 1);
            FUN_003d8850((s32)work, 0x16, 1);
        } else if (FUN_003c6c80((s32)task) != 0) {
            FUN_0010a4e0(0, 0, 0, 2);
            FUN_003c6f50((s32)task);
            work->state = 2;
            FUN_003d8850((s32)work, 7, 1);
            FUN_003d8850((s32)work, 8, 1);
            FUN_003d8850((s32)work, 9, 1);
            FUN_003d8850((s32)work, 0xa, 1);
            FUN_003d8850((s32)work, 0xc, 1);
            FUN_003d8850((s32)work, 0xf, 1);
            FUN_003d8850((s32)work, 0x16, 1);
        }
        break;

    case 4:
        if (FUN_003dff30((int *)work->result) != 0) {
            FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 6, 1);
            FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 9, 0);
            work->state = 5;
            fclCombineList003ddb90(work, &work->selection);
        } else {
            break;
        }
    case 5:
        selection_state = fclCombineList003ddd20(&work->selection);
        switch (selection_state) {
        case 1:
            FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 9, 1);
            if (FUN_003d6c90(2) != 0) {
                memset(selected_values, 0, sizeof(selected_values));
                for (i = 0; i < work->capacity; i++) {
                    K_ASSERT(work->values[i] != 0, 0x9c4);
                    selected_values[i] = work->values[i]->persona_id;
                }
                if (FUN_003d6f80(validated_input, &work->fusion, selected_values) != 0) {
                    work->flags |= 0x40;
                    memcpy(&work->fusion, validated_input, sizeof(work->fusion));
                }
            }
            FUN_003d72f0((s32)&work->fusion.detail);
            FUN_003c6f10((s32)task);
            FUN_003c6f50((s32)task);
            work->state = 2;
            work->flags |= 0x10;
            break;

        case 2:
            FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 6, 0);
            FUN_003d06d0(FUN_003c5460(FUN_003d02e0()), 9, 1);
            work->state = 3;
            K_ASSERT(work != 0, 0x408);
            work->used--;
            work->values[work->used] = 0;
            FUN_003c6ee0((s32)task);
            FUN_003d8850((s32)work, 0xb, 0);
            FUN_003d8850((s32)work, 7, 0);
            FUN_003d8850((s32)work, 8, 0);
            FUN_003d8850((s32)work, 9, 0);
            FUN_003d8850((s32)work, 0xa, 0);
            FUN_003d8850((s32)work, 0xc, 0);
            FUN_003d8850((s32)work, 0xf, 0);
            FUN_003d8850((s32)work, 0x16, 0);
        }
        break;
    }
    return 0;
}

// FUN_003deb20
void fclCombineList003deb20(FclList* work)
{
    FclResourceData* data = work->list->root.root_node->meta->data;
    s32 i;
    s32 used;

    for (used = 0, i = 0; i < work->capacity; used++, i++) {
        work->values[i] = *(FclFusionDetail**)((s32)data + i * 4 + 0x6c);
    }
    work->used = used;
}

// FUN_003deb80
void fclCombineList003deb80(s32 unused0, s32 unused1, s32 unused2, FclOwner* owner)
{
    FclList* work = owner->container->work;

    (void)unused0;
    (void)unused1;
    (void)unused2;
    FUN_003e0680_32((u32)(void *)work->result,
                    (code *)fclCombineList003db650,
                    (u32)(void *)owner);
    work->flags |= 0x10000;
    FUN_003c4e70((s32)owner);
    work->flags &= 0xfffeffff;
}

// FUN_003dec00
void fclCombineList003dec00(s32 arg0, s32 arg1, s16 arg2, FclOwner* owner,
                             FclResourceNode* node)
{
    FclDrawCallbackData data;
    FclList* work;
    FclResourceData* resource_data;
    code *callback;

    memset(&data, 0, sizeof(data));
    work = owner->container->work;
    resource_data = node->meta->data;
    if (node == owner->root.root_node) data.flags |= 1;
    data.callback_arg0 = arg0;
    data.callback_arg1 = arg1;
    data.callback_arg2 = arg2;
    data.work = work;
    data.resource_data = resource_data;
    data.owner = owner;
    data.node = node;
    callback = (code *)fclCombineList003dd260;
    FUN_003e0680_p((u32)(void *)resource_data->callback_target,
                   callback,
                   &data);
}

// FUN_003decd0
FclCallbackProxy* fclCombineList003decd0(FclList* work)
{
    FclCreatedTask* created;
    FclCallbackProxy* proxy;

    K_ASSERT(work != 0, 0xa3e);
    created = FUN_003c44d0(0x14, 0, 0, fclCombineList003ded40);
    proxy = created->proxy;
    proxy->created_task = created;
    proxy->work = work;
    return proxy;
}

// FUN_003ded40
void fclCombineList003ded40(FclCallbackProxy* proxy)
{
    if (proxy != 0) FUN_003c45f0((s32)proxy->created_task);
}

// FUN_003ded70
void fclCombineList003ded70(FclCallbackProxy* proxy)
{
    FUN_003c4e70((s32)proxy->created_task);
}

// FUN_003deda0
void fclCombineList003deda0(FclNodeListContext* context)
{
    FclNodeList* list;
    FclNodeLink* primary_node;
    FclNodeLink* secondary_node;
    FclAnimationNode* payload;
    FclAnimationNode* selected;

    if (context == 0) return;
    list = context->list;
    selected = (FclAnimationNode*)FUN_003dfac0((int*)context);
    if (selected == 0) return;

    primary_node = list->primary_head;
    while (primary_node != 0) {
        if (primary_node == selected->link) break;
        payload = primary_node->payload;
        FUN_003dfae0((int*)context, (int*)payload);
        primary_node = primary_node->next;
    }

    secondary_node = list->secondary_head;
    while (secondary_node != 0) {
        if (secondary_node == selected->link) break;
        payload = secondary_node->payload;
        FUN_003dfae0((int*)context, (int*)payload);
        secondary_node = secondary_node->secondary_next;
    }

    if (selected->link != 0) {
        payload = selected->link->payload;
        FUN_003dfae0((int*)context, (int*)payload);
    }
}

// FUN_003dee80
FclAnimationNode* fclCombineList003dee80(FclNodeListContext* context, s32 value, s32 preset,
                                          s32 source_value, s16 direction, s16 duration)
{
    FclAnimationNode* payload;

    payload = fclCombineList003df090(context, 0);
    fclCombineList003df220(payload, value, preset, source_value, direction, duration);
    return payload;
}

// FUN_003def10
s32 fclCombineList003def10(u32 value)
{
    if (value <= 1) goto zero;
    return (value + 1) * 9;
zero:
    return 0;
}

// FUN_003def40
s32 fclCombineList003def40(s32 width, s32 count, s32 index)
{
    s32 step;

    if (count > 1) {
        step = (index * width) / (count - 1);
    } else {
        step = 0;
    }
    return (width >> 1) - step + 0x5a;
}

// FUN_003def80
s32 fclCombineList003def80(FclNodeListContext* context)
{
    FclNodeLink* node;
    FclAnimationNode* selected;
    node = context->list->primary_head;
    selected = (FclAnimationNode*)FUN_003dfac0((int*)context);
    if (selected == 0)
        return 0;
    while (node != 0) {
        FclAnimationNode* payload = node->payload;
        if ((payload->flags & 4) != 0) {
            s16 direction = *(volatile s16*)((u8*)selected + 0x20);

            fclCombineList003df220(payload, payload->value, 1, payload->source_value,
                                    direction, 0);
        }
        node = node->next;
    }
    return 1;
}

// FUN_003df010
s32 fclCombineList003df010(FclNodeListContext* context)
{
    FclNodeLink* node = context->list->primary_head;

    if (FUN_003dfac0((int *)context) == 0) return 1;
    while (node != 0) {
        if ((node->payload->flags & 4) == 0) return 0;
        node = node->next;
    }
    return 1;
}

// FUN_003df090
FclAnimationNode* fclCombineList003df090(FclNodeListContext* context,
                                          FclNodeCreateData* create_data)
{
    FclNodeLink* link;
    FclAnimationNode* payload;

    link = FUN_003c4910(context->list, context->list->allocation_count + 1,
                         &create_data->inline_storage);
    payload = link->payload;
    payload->link = link;
    if (create_data != 0) payload->value_storage = &payload->inline_storage;
    payload->field_0c = 0;
    payload->flags |= 4;
    return payload;
}

// FUN_003df100
FclAnimationNode* fclCombineList003df100(FclAnimationNode* node,
                                          FclAnimationResultRecord* result)
{
    node->source_value = result->value;
    if (result->field08 == -0x8000) node->target_x = node->current_x;
    else node->current_x = node->target_x = result->field08;
    if (result->field0a == -0x8000) node->target_y = node->current_y;
    else node->current_y = node->target_y = result->field0a;
    if (result->field0c != -0x8000) node->interpolated_x = result->field0c;
    if (result->field0e != -0x8000) node->interpolated_y = result->field0e;
    if (result->field10 == -0x8000) node->target_z = node->current_z;
    else node->current_z = node->target_z = result->field10;
    if (result->field12 != -0x8000) node->requested_z = result->field12;
    if (result->field14 == -0x8000) node->target_w = node->current_w;
    else node->current_w = node->target_w = result->field14;
    if (result->field16 != -0x8000) node->endpoint_w = result->field16;
    node->duration = result->field18;
    node->divisor = result->field1a;
    return node;
}

// FUN_003df220 NONMATCHING
void fclCombineList003df220(FclAnimationNode* node, s32 value, s32 preset,
                             s32 source_value, s16 direction, s16 duration)
{
    float radians;

    K_ASSERT(node != 0, 0xb1b);
    if ((node->flags & 4) == 0) return;

    if (preset == 0) {
        node->current_x = 0x140;
        node->target_x = 0x140;
        node->current_y = 0x1f8;
        node->target_y = 0x1f8;
        node->current_w = 0;
        node->target_w = 0;
        node->endpoint_w = 0xff;
        node->current_z = direction;
        node->target_z = direction;
        node->requested_z = direction;
        node->divisor = 10;
        radians = 0.017453292f * (float)node->requested_z;
        node->interpolated_x = (s16)(320.0f + 1000.0f * cosf(radians));
        node->interpolated_y = (s16)(508.0f - 1000.0f * sinf(radians));
        node->flags |= 2;
    } else if (preset == 1) {
        node->target_x = node->current_x;
        node->target_y = node->current_y;
        node->target_w = node->current_w;
        node->endpoint_w = 0;
        node->target_z = node->current_z;
        node->requested_z = direction;
        node->divisor = 10;
        radians = 0.017453292f * (float)node->requested_z;
        node->interpolated_x = (s16)(320.0f + 1000.0f * cosf(radians));
        node->interpolated_y = (s16)(508.0f - 1000.0f * sinf(radians));
        node->flags |= 2;
    }

    node->source_value = source_value;
    node->duration = duration;
    node->value = value;
    node->field_0c = 1;
    node->flags &= ~4;
}

// HARVESTED 3D-42FF





















// FUN_003DF4A0 NONMATCHING
u64 FUN_003df4a0(u64 param_1,int param_2)



{

  int iVar1;

  short sVar2;

  float fVar3;

  float fVar4;

  

  iVar1 = *(int *)(param_2 + 0x14);

  switch(*(u32 *)(iVar1 + 0xc)) {
  case 0:
    break;

  case 1:

    sVar2 = *(short *)(iVar1 + 0x2c) + -1;

    *(short *)(iVar1 + 0x2c) = sVar2;

    if (sVar2 < 1) {

      *(u16 *)(iVar1 + 0x2c) = 0;

      if ((*(u32 *)(iVar1 + 8) & 2) == 0) {

        *(u32 *)(iVar1 + 0xc) = 2;

      }

      else {

        *(u32 *)(iVar1 + 0xc) = 3;

      }

    }

    break;

  case 2:

    *(u32 *)(iVar1 + 0xc) = 4;

    *(u16 *)(iVar1 + 0x2e) = 0;

  case 4:

    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + 1;

    sVar2 = *(short *)(iVar1 + 0x18);

    fVar3 = (float)sinf((DAT_007cae00 * (float)*(u16 *)(iVar1 + 0x2e)) /

                                (float)*(u16 *)(iVar1 + 0x30));

    *(short *)(iVar1 + 0x14) =

         (short)(int)((float)((int)*(short *)(iVar1 + 0x1c) - (int)sVar2) * fVar3 +

                     (float)(int)sVar2 + 0.0f);

    sVar2 = *(short *)(iVar1 + 0x1a);

    fVar3 = (float)sinf((DAT_007cae00 * (float)*(u16 *)(iVar1 + 0x2e)) /

                                (float)*(u16 *)(iVar1 + 0x30));

    *(short *)(iVar1 + 0x16) =

         (short)(int)((float)((int)*(short *)(iVar1 + 0x1e) - (int)sVar2) * fVar3 +

                     (float)(int)sVar2 + 0.0f);

    sVar2 = *(short *)(iVar1 + 0x22);

    fVar3 = (float)sinf((DAT_007cae00 * (float)*(u16 *)(iVar1 + 0x2e)) /

                                (float)*(u16 *)(iVar1 + 0x30));

    *(short *)(iVar1 + 0x20) =

         (short)(int)((float)((int)*(short *)(iVar1 + 0x24) - (int)sVar2) * fVar3 +

                     (float)(int)sVar2 + 0.0f);

    *(short *)(iVar1 + 0x26) =

         *(short *)(iVar1 + 0x28) +

         (short)((int)((u32)*(u16 *)(iVar1 + 0x2e) *

                      ((int)*(short *)(iVar1 + 0x2a) - (int)*(short *)(iVar1 + 0x28))) /

                (int)(u32)*(u16 *)(iVar1 + 0x30));

    if (*(u16 *)(iVar1 + 0x30) <= *(u16 *)(iVar1 + 0x2e)) {

      *(u16 *)(iVar1 + 0x14) = *(u16 *)(iVar1 + 0x1c);

      *(u16 *)(iVar1 + 0x16) = *(u16 *)(iVar1 + 0x1e);

      *(u16 *)(iVar1 + 0x20) = *(u16 *)(iVar1 + 0x24);

      *(u16 *)(iVar1 + 0x26) = *(u16 *)(iVar1 + 0x2a);

      *(u16 *)(iVar1 + 0x2e) = 0;

      *(u32 *)(iVar1 + 0xc) = 6;

      *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 4;

    }

    break;

  case 3:

    *(u32 *)(iVar1 + 0xc) = 5;

    *(u16 *)(iVar1 + 0x2e) = 0;

  case 5:

    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + 1;

    sVar2 = *(short *)(iVar1 + 0x22);

    fVar3 = (float)sinf((DAT_007cae00 * (float)*(u16 *)(iVar1 + 0x2e)) /

                                (float)*(u16 *)(iVar1 + 0x30));

    sVar2 = (short)(int)((float)((int)*(short *)(iVar1 + 0x24) - (int)sVar2) * fVar3 +

                        (float)(int)sVar2 + 0.0);

    *(short *)(iVar1 + 0x20) = sVar2;

    fVar4 = DAT_007caf14 * (float)(int)sVar2;

    fVar3 = (float)cosf(fVar4);

    fVar4 = (float)sinf(fVar4);

    *(short *)(iVar1 + 0x14) = (short)(int)(fVar3 * 464.0f + 320.0f);

    *(short *)(iVar1 + 0x16) = (short)(int)(504.0f - fVar4 * 464.0f);

    *(short *)(iVar1 + 0x26) =

         *(short *)(iVar1 + 0x28) +

         (short)((int)((u32)*(u16 *)(iVar1 + 0x2e) *

                      ((int)*(short *)(iVar1 + 0x2a) - (int)*(short *)(iVar1 + 0x28))) /

                (int)(u32)*(u16 *)(iVar1 + 0x30));

    if (*(u16 *)(iVar1 + 0x30) <= *(u16 *)(iVar1 + 0x2e)) {

      *(u16 *)(iVar1 + 0x14) = *(u16 *)(iVar1 + 0x1c);

      *(u16 *)(iVar1 + 0x16) = *(u16 *)(iVar1 + 0x1e);

      *(u16 *)(iVar1 + 0x20) = *(u16 *)(iVar1 + 0x24);

      *(u16 *)(iVar1 + 0x26) = *(u16 *)(iVar1 + 0x2a);

      *(u16 *)(iVar1 + 0x2e) = 0;

      *(u32 *)(iVar1 + 0xc) = 6;

      *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 4;

    }

  case 6:
    break;
  }

  return 0;

}

// FUN_003DFAC0


u32 FUN_003dfac0(int *param_1)



{

  return **(u32 **)(*(int *)(*(int *)(*param_1 + 0xc) + 0x14) + 0x1c);

}

// FUN_003DFAE0 NONMATCHING


void FUN_003dfae0(int *param_1,int *param_2)



{

  u8 bVar1;

  short sVar2;

  short sVar3;

  u16 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  fVar10 = 1.0f;

  bVar1 = *(int *)(*param_1 + 0xc) == *param_2;

  if (bVar1) {

    fVar10 = DAT_007caffc;

  }

  sVar2 = (short)param_2[5];

  sVar3 = *(short *)((int)param_2 + 0x16);

  uVar4 = *(u16 *)((int)param_2 + 0x26);

  iVar6 = (short)param_2[8] + -0x5a;

  iVar5 = -iVar6;

  if (bVar1) {

    FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,2,bVar1,0x26,0);

    if ((param_2[2] & 2U) == 0) {

      if (iVar7 == 6) {

        fVar11 = 36.0f - fVar10 * 68.0f;

        fVar14 = -2.0f - fVar10;

      }

      else {

        fVar11 = fVar10 * -34.0f;

        fVar14 = 42.0f - fVar10 * 41.0f;

      }


      fVar13 = DAT_007caf14 * (float)iVar6;

      fVar8 = (float)cosf(fVar13);

      fVar9 = (float)sinf(fVar13);

      fVar12 = fVar11 * fVar8 + fVar14 * fVar9;

      fVar8 = (float)sinf(fVar13);

      fVar9 = (float)cosf(fVar13);

      FUN_0040e3f0(0,(float)iVar5,fVar10,fVar10,(int)((float)(int)sVar2 + fVar12),

                   (int)((float)(int)sVar3 + -fVar11 * fVar8 + fVar14 * fVar9),uVar4 & 0xff,4,

                   (iVar7 + -1) * 2,0,0);

    }

    FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,6,(iVar7 + -1) * 2,

                 0x32,0xffffffffffffffa0);

    if ((iVar7 != 6) && (iVar7 != 7)) {

      FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,7,0,0x32,

                   0xffffffffffffff8f);

    }

  }

  else {

    FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,2,0,0x26,0);

    iVar7 = (iVar7 + -1) * 2;

    FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,3,iVar7 + (u32)bVar1

                 ,0x22,0);

    FUN_0040e3f0(0,(float)iVar5,0x3f800000,0x3f800000,sVar2,sVar3,uVar4 & 0xff,bVar1 + 5,iVar7,0x1d,

                 0xffffffffffffffb1);

  }

  return;

}

// FUN_003DFEB0
int * FUN_003dfeb0(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = (s32)FUN_003c44d0(8,0,0,(FclProxyCallback*)FUN_003df4a0);

  piVar1 = *(int **)(iVar2 + 0x24);

  *piVar1 = iVar2;

  piVar1[1] = param_1;

  return piVar1;

}

// FUN_003DFF00
void FUN_003dff00(s32 param_1)
{
    if (param_1 != 0) {
        FUN_003c45f0(*(u32 *)param_1);
    }
}

// FUN_003DFF30
u32 FUN_003dff30(int *param_1)
{
    int iVar1;

    iVar1 = *(int *)(*param_1 + 4);
    goto check;
body:
    if ((*(u32 *)(*(int *)(iVar1 + 0x14) + 8) & 4) == 0) {
        return 0;
    }
    iVar1 = *(int *)(iVar1 + 0x10);
check:
    if (iVar1 != 0) goto body;
    return 1;
}

// FUN_003DFF80
#pragma push
#pragma opt_rebuildconditionals off
int FUN_003dff80(int* param_1, int param_2)
{
  int node;
  int result;

  node = *(int *)(*param_1 + 4);
  while (node != 0) {
    result = *(int *)(node + 0x14);
    if (*(int *)(result + 0x10) == param_2) {
      return result;
    }
    node = *(int *)(node + 0x10);
  }
  return 0;
}
#pragma pop

// FUN_003DFFC0 NONMATCHING


int FUN_003dffc0(int *param_1,int param_2,s32 param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *param_1;

  for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    iVar3 = *(int *)(iVar2 + 0x14);

    if (*(int *)(iVar3 + 0x10) == param_2) goto LAB_003e0008;

  }

  iVar3 = 0;
LAB_003e0008:

  if (iVar3 == 0) {

    iVar1 = (s32)FUN_003c4910((FclNodeList *)iVar1,*(u16 *)(iVar1 + 0x10) + 1,(FclNodeValueStorage *)((int)param_3 + 0x38));

    iVar3 = *(int *)(iVar1 + 0x14);

    *(int *)(iVar3 + 4) = iVar1;

    if (param_3 != 0) {

      *(int *)(iVar3 + 0x34) = iVar3 + 0x38;

    }

    *(u32 *)(iVar3 + 0xc) = 0;

    *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) | 4;

  }

  *(u32 *)(iVar3 + 0xc) = 1;

  *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffffb;

  return iVar3;

}

// FUN_003E0080


void FUN_003e0080(u64 param_1,int param_2,int param_3,u16 param_4)



{

  int iVar1;
  int iVar2;
  int *piVar5;
  int *piVar4;
  int iVar3;
  struct {
    s32 first;
    u8 prefix[0x14];
    struct {
      volatile u16 value;
      u16 pad;
      volatile int index;
      u8 tail[0x14];
    } pairs[43];
    volatile u16 last;
  } work;

  piVar5 = (int*)DAT_006a6040_abs;

  piVar4 = (int*)&work;

  iVar3 = 0x9a;

  do {

    iVar1 = *piVar5;

    iVar2 = piVar5[1];

    piVar5 = piVar5 + 2;

    iVar3 = iVar3 + -1;

    *piVar4 = iVar1;

    piVar4[1] = iVar2;

    piVar4 = piVar4 + 2;

  } while (0 < iVar3);

  work.first = param_2;
  work.pairs[0].value = param_4;
  work.pairs[0].index = param_2;
  work.pairs[1].value = param_4;
  work.pairs[1].index = param_2;
  work.pairs[2].value = param_4;
  work.pairs[2].index = param_2;
  work.pairs[3].value = param_4;
  work.pairs[3].index = param_2;
  work.pairs[4].value = param_4;
  work.pairs[4].index = param_2;
  work.pairs[5].value = param_4;
  work.pairs[5].index = param_2;
  work.pairs[6].value = param_4;
  work.pairs[6].index = param_2;
  work.pairs[7].value = param_4;
  work.pairs[7].index = param_2;
  work.pairs[8].value = param_4;
  work.pairs[8].index = param_2;
  work.pairs[9].value = param_4;
  work.pairs[9].index = param_2;
  work.pairs[10].value = param_4;
  work.pairs[10].index = param_2;
  work.pairs[11].value = param_4;
  work.pairs[11].index = param_2;
  work.pairs[12].value = param_4;
  work.pairs[12].index = param_2;
  work.pairs[13].value = param_4;
  work.pairs[13].index = param_2;
  work.pairs[14].value = param_4;
  work.pairs[14].index = param_2;
  work.pairs[15].value = param_4;
  work.pairs[15].index = param_2;
  work.pairs[16].value = param_4;
  work.pairs[16].index = param_2;
  work.pairs[17].value = param_4;
  work.pairs[17].index = param_2;
  work.pairs[18].value = param_4;
  work.pairs[18].index = param_2;
  work.pairs[19].value = param_4;
  work.pairs[19].index = param_2;
  work.pairs[20].value = param_4;
  work.pairs[20].index = param_2;
  work.pairs[21].value = param_4;
  work.pairs[21].index = param_2;
  work.pairs[22].value = param_4;
  work.pairs[22].index = param_2;
  work.pairs[23].value = param_4;
  work.pairs[23].index = param_2;
  work.pairs[24].value = param_4;
  work.pairs[24].index = param_2;
  work.pairs[25].value = param_4;
  work.pairs[25].index = param_2;
  work.pairs[26].value = param_4;
  work.pairs[26].index = param_2;
  work.pairs[27].value = param_4;
  work.pairs[27].index = param_2;
  work.pairs[28].value = param_4;
  work.pairs[28].index = param_2;
  work.pairs[29].value = param_4;
  work.pairs[29].index = param_2;
  work.pairs[30].value = param_4;
  work.pairs[30].index = param_2;
  work.pairs[31].value = param_4;
  work.pairs[31].index = param_2;
  work.pairs[32].value = param_4;
  work.pairs[32].index = param_2;
  work.pairs[33].value = param_4;
  work.pairs[33].index = param_2;
  work.pairs[34].value = param_4;
  work.pairs[34].index = param_2;
  work.pairs[35].value = param_4;
  work.pairs[35].index = param_2;
  work.pairs[36].value = param_4;
  work.pairs[36].index = param_2;
  work.pairs[37].value = param_4;
  work.pairs[37].index = param_2;
  work.pairs[38].value = param_4;
  work.pairs[38].index = param_2;
  work.pairs[39].value = param_4;
  work.pairs[39].index = param_2;
  work.pairs[40].value = param_4;
  work.pairs[40].index = param_2;
  work.pairs[41].value = param_4;
  work.pairs[41].index = param_2;
  work.pairs[42].value = param_4;
  work.pairs[42].index = param_2;
  work.last = param_4;

  memcpy(param_1,(int*)&work + param_2 * 0xe + param_3 * 7,0x1c);

  return;

}

// FUN_003E0260 NONMATCHING


int FUN_003e0260(u32 param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  u8 auStack_20 [4];
  int iStack_1c;

  FUN_003e0080_p((void *)auStack_20,0,0,0);
  iVar1 = FUN_003dff80((int *)param_1,param_2);
  if (iVar1 == 0) {
    iVar2 = (s32)FUN_003c4910((FclNodeList *)*(int *)param_1,
                              *(u16 *)(*(int *)param_1 + 0x10) + 1,
                              (FclNodeValueStorage *)(iStack_1c + 0x38));
    iVar1 = *(int *)(iVar2 + 0x14);
    *(int *)(iVar1 + 4) = iVar2;
    if (iStack_1c != 0)
      *(int *)(iVar1 + 0x34) = iVar1 + 0x38;
    *(u32 *)(iVar1 + 0xc) = 0;
    *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 4;
  }
  *(u32 *)(iVar1 + 0xc) = 1;
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) & 0xfffffffb;
  fclCombineList003df100((FclAnimationNode *)iVar1,
                         (FclAnimationResultRecord *)auStack_20);
  return iVar1;
}

// FUN_003E0330
int FUN_003e0330(int *param_1,s32 param_2,int param_3,u16 param_4)
{
    struct FclPair {
        s32 first;
        s32 second;
    };
    struct {
        s32 table[0x70];
        u8 result[0x1c];
    } work;
    struct FclPair *src;
    struct FclPair *dst;
    s32 first;
    s32 second;
    s32 count;
    s32 result_word;
    FclAnimationNode* node;
    FclNodeLink* link;

    src = (struct FclPair *)DAT_006a6510_abs;
    dst = (struct FclPair *)work.table;
    count = 0x38;
    do {
        first = src->first;
        second = src->second;
        src++;
        count--;
        dst->first = first;
        dst->second = second;
        dst++;
    } while (count > 0);
    work.table[0] = param_2;
    *(u16 *)((byte *)work.table + 0x18) = param_4;
    *(s32 *)((byte *)work.table + 0x1c) = work.table[0];
    *(u16 *)((byte *)work.table + 0x34) = param_4;
    *(s32 *)((byte *)work.table + 0x38) = work.table[0];
    *(u16 *)((byte *)work.table + 0x50) = param_4;
    *(s32 *)((byte *)work.table + 0x54) = work.table[0];
    *(u16 *)((byte *)work.table + 0x6c) = param_4;
    *(s32 *)((byte *)work.table + 0x70) = work.table[0];
    *(u16 *)((byte *)work.table + 0x88) = param_4;
    *(s32 *)((byte *)work.table + 0x8c) = work.table[0];
    *(u16 *)((byte *)work.table + 0xa4) = param_4;
    *(s32 *)((byte *)work.table + 0xa8) = work.table[0];
    *(u16 *)((byte *)work.table + 0xc0) = param_4;
    *(s32 *)((byte *)work.table + 0xc4) = work.table[0];
    *(u16 *)((byte *)work.table + 0xdc) = param_4;
    *(s32 *)((byte *)work.table + 0xe0) = work.table[0];
    *(u16 *)((byte *)work.table + 0xf8) = param_4;
    *(s32 *)((byte *)work.table + 0xfc) = work.table[0];
    *(u16 *)((byte *)work.table + 0x114) = param_4;
    *(s32 *)((byte *)work.table + 0x118) = work.table[0];
    *(u16 *)((byte *)work.table + 0x130) = param_4;
    *(s32 *)((byte *)work.table + 0x134) = work.table[0];
    *(u16 *)((byte *)work.table + 0x14c) = param_4;
    *(s32 *)((byte *)work.table + 0x150) = work.table[0];
    *(u16 *)((byte *)work.table + 0x168) = param_4;
    *(s32 *)((byte *)work.table + 0x16c) = work.table[0];
    *(u16 *)((byte *)work.table + 0x184) = param_4;
    *(s32 *)((byte *)work.table + 0x188) = work.table[0];
    *(u16 *)((byte *)work.table + 0x1a0) = param_4;
    *(s32 *)((byte *)work.table + 0x1a4) = work.table[0];
    *(u16 *)((byte *)work.table + 0x1bc) = param_4;
    memcpy(work.result,
           work.table + work.table[0] * 0xe + param_3 * 7,
           0x1c);
    result_word = *(s32 *)(work.result + 4);
    node = (FclAnimationNode *)FUN_003dff80(param_1, param_2);
    if (node == 0) {
        link = FUN_003c4910((FclNodeList *)*(int *)param_1,
                            *(u16 *)(*(int *)param_1 + 0x10) + 1,
                            (FclNodeValueStorage *)(result_word + 0x38));
        node = link->payload;
        node->link = link;
        if (result_word != 0)
            node->value_storage = &node->inline_storage;
        node->field_0c = 0;
        node->flags |= 4;
    }
    node->field_0c = 1;
    node->flags &= 0xfffffffb;
    fclCombineList003df100(node, (FclAnimationResultRecord *)work.result);
    return (int)node;
}

// FUN_003E04E0
int FUN_003e04e0(int *param_1,s32 param_2,int param_3,u16 param_4)
{
    struct FclPair {
        s32 first;
        s32 second;
    };
    struct {
        s32 table[0x38];
        u8 result[0x1c];
    } work;
    struct FclPair *src;
    struct FclPair *dst;
    s32 count;
    s32 result_word;
    s32 first;
    s32 second;
    FclAnimationNode* node;
    FclNodeLink* link;

    src = (struct FclPair *)DAT_006A66D0_abs;
    dst = (struct FclPair *)work.table;
    count = 0x1c;
    do {
        first = src->first;
        second = src->second;
        src++;
        count--;
        dst->first = first;
        dst->second = second;
        dst++;
    } while (count > 0);
    work.table[0] = param_2;
    *(u16 *)((byte *)work.table + 0x18) = param_4;
    *(s32 *)((byte *)work.table + 0x1c) = work.table[0];
    *(u16 *)((byte *)work.table + 0x34) = param_4;
    *(s32 *)((byte *)work.table + 0x38) = work.table[0];
    *(u16 *)((byte *)work.table + 0x50) = param_4;
    *(s32 *)((byte *)work.table + 0x54) = work.table[0];
    *(u16 *)((byte *)work.table + 0x6c) = param_4;
    *(s32 *)((byte *)work.table + 0x70) = work.table[0];
    *(u16 *)((byte *)work.table + 0x88) = param_4;
    *(s32 *)((byte *)work.table + 0x8c) = work.table[0];
    *(u16 *)((byte *)work.table + 0xa4) = param_4;
    *(s32 *)((byte *)work.table + 0xa8) = work.table[0];
    *(u16 *)((byte *)work.table + 0xc0) = param_4;
    *(s32 *)((byte *)work.table + 0xc4) = work.table[0];
    *(u16 *)((byte *)work.table + 0xdc) = param_4;
    memcpy(work.result,
           work.table + work.table[0] * 0xe + param_3 * 7,
           0x1c);
    result_word = *(s32 *)(work.result + 4);
    node = (FclAnimationNode *)FUN_003dff80(param_1, param_2);
    if (node == 0) {
        link = FUN_003c4910((FclNodeList *)*(int *)param_1,
                            *(u16 *)(*(int *)param_1 + 0x10) + 1,
                            (FclNodeValueStorage *)(result_word + 0x38));
        node = link->payload;
        node->link = link;
        if (result_word != 0)
            node->value_storage = &node->inline_storage;
        node->field_0c = 0;
        node->flags |= 4;
    }
    node->field_0c = 1;
    node->flags &= 0xfffffffb;
    fclCombineList003df100(node, (FclAnimationResultRecord *)work.result);
    return (int)node;
}

// FUN_003E0650


u64 FUN_003e0650(u32 *param_1)



{

  FUN_003c4e70(*param_1);

  return 0;

}

// FUN_003E0680


void FUN_003e0680(u32 param_1,code* param_2,u32 param_3)



{

  int iVar1;

  

  for (iVar1 = *(int *)(*(int *)param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    (*param_2)(param_1,*(u32 *)(iVar1 + 0x14),param_3);

  }

  return;

}

#pragma push
#pragma opt_rebuildconditionals off
// FUN_003E0700


void FUN_003e0700(s32 param_1)



{

  u32 uStack_4;

  uStack_4 = (u32)param_1;
  if (param_1 == 4)
      goto change_seq;
  if (param_1 == 2)
      goto change_seq;
  if (param_1 == 1)
      goto change_seq;
  switch (param_1) {
  case 0:
      goto change_seq;
  default:
      goto default_seq;
  }
change_seq:
  adminiChangeSeq(7, &uStack_4, 4, 0);
  goto done;

default_seq:
  FUN_003e0780();

done:
  return;

}
#pragma pop

// FUN_003E0780 NONMATCHING


void FUN_003e0780(void)



{
  int iVar1;
  u32 uVar2;

  FUN_003e0950_narg();
  iVar1 = FUN_003c5460(DAT_007ce688);
  uVar2 = kwlnTaskCreate(0,(char *)&DAT_007cd7b8,10,FUN_003e0830,0,0);
  *(int *)(iVar1 + 0x80) = (int)uVar2;
  uVar2 = kwlnTaskCreate(uVar2,0x6a6ad8,0x18b6,FUN_003e0870,0,0);
  kwlnTaskCreate(uVar2,0x6a6ae8,0x106f,FUN_003e08e0,0,0);
  return;
}

// FUN_003E0830
u32 FUN_003e0830(void)
{
    if (FUN_003e0bc0() != 0) goto failed;
    goto succeeded;
failed:
    return -1;
succeeded:
    return 0;
}

// FUN_003E0870
u64 FUN_003e0870(void)



{

  int iVar1;

  

  iVar1 = FUN_003c5460(uGpffffb998);

  FUN_003e6d40();

  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 0x20;

  FUN_003e0680(*(s32 *)(iVar1 + 0x98),(code*)FUN_003e6400,0);

  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) & 0xffffffdf;

  return 0;

}

// FUN_003E08E0
u64 FUN_003e08e0(void)



{

  int iVar1;

  

  iVar1 = FUN_003c5460(uGpffffb998);

  FUN_003e0680(*(s32 *)(iVar1 + 0x98),(code*)FUN_003e6400,0);

  return 0;

}

// FUN_003E0920


void FUN_003e0920(void)



{

  FUN_003e0bb0();

  return;

}

// FUN_003E0940


u32 FUN_003e0940(void)



{

  return uGpffffb998;

}

// FUN_003E0950
void FUN_003e0950(s32 arg)
{
    s32 work;
    s32 param_1 = arg;
    if (iGpffffb998 != 0)
    {
        return;
    }

    iGpffffb998 = FUN_003c5180((s32)FUN_003e6e80, 0x9c);
    work = FUN_003c5460(iGpffffb998);
    *(s32*)work = param_1;
    *(s32*)(work + 0x98) = (s32)FUN_003dfeb0(work);
    *(s32*)(work + 4) = 1;
    printf(&gp0xffffaad0, (char*)DAT_006a6b20 - 0x28, 0x1a9);
    printf((char*)DAT_006a6b20_second - 0x18, param_1);
    H_Dbprt_FmtLog((char*)DAT_006a6b20_log - 0x18, param_1);
}

// FUN_003E0A10 NONMATCHING


void FUN_003e0a10(s32 param_1)



{

  int *piVar1;

  long lVar2;

  int iVar3;

  

  piVar1 = (int *)FUN_003c5460();

  lVar2 = datGetFlag(0x121f);

  if (lVar2 == 1) {

    datSetFlag(0x1407,0);

  }

  FUN_0040e360();

  iVar3 = *piVar1;

  if (iVar3 == 8) {

    FUN_003c7dd0();

    FUN_003c7dd0(9);

  }

  else if ((((iVar3 == 4) || (iVar3 == 2)) || (iVar3 == 1)) || (iVar3 == 0)) {

    MT_Scene_Destroy();

  }

  FUN_003c77a0();

  if (piVar1[0x16] == 0) {

    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {

      if (piVar1[iVar3 * 2 + 0x18] != 0) {

        H_Cdvd_Destroy();

        piVar1[iVar3 * 2 + 0x18] = 0;

        piVar1[iVar3 * 2 + 0x19] = 0;

      }

    }

  }

  else {

    H_Cdvd_Destroy();

    piVar1[0x16] = 0;

  }

  FUN_003dff00(piVar1[0x26]);

  return;

}



// FUN_003E0B70
void FUN_003e0b70(void)
{
    if (iGpffffb998 != 0) {
        FUN_003e0a10(iGpffffb998);
        FUN_003c5220(iGpffffb998);
    }
    iGpffffb998 = 0;
}

// FUN_003E0BB0


u8 FUN_003e0bb0(void)



{

  return iGpffffb998 != 0;

}

// FUN_003E0BC0
u32 FUN_003e0bc0(void)
{
    if (FUN_003c5490(uGpffffb998) != 0) {
        FUN_003e0a10(uGpffffb998);
        FUN_003c5220(uGpffffb998);
        uGpffffb998 = 0;
        return 1;
    }
    return 0;
}

#define FCL_SET_RESULT(T, I, V) (((FclAnimationResultRecord *)(T))[I].value = (V)); (((FclAnimationResultRecord *)(T))[I].field18 = 0);
#define FCL_COMBINE_CASE(ID, SLOT, INDEX) \
    do { \
        FclAnimationNode* s0 = *(FclAnimationNode **)((unsigned char *)param_1 + 0x98); \
        unsigned char table[0x3f0]; \
        FclAnimationNode* node; \
        FclAnimationResultRecord* source; \
        u32 *src; \
        u32 *dst; \
        s32 count; \
        u32 value0; \
        u32 value1; \
        src = (u32 *)DAT_006a6b20; \
        dst = (u32 *)table; \
        count = 0x7e; \
        do { \
            value0 = src[0]; \
            value1 = src[1]; \
            src += 2; \
            count--; \
            dst[0] = value0; \
            dst[1] = value1; \
            dst += 2; \
        } while (count > 0); \
        FCL_SET_RESULT(table, 0, ID) \
        FCL_SET_RESULT(table, 1, ID) \
        FCL_SET_RESULT(table, 2, ID) \
        FCL_SET_RESULT(table, 3, ID) \
        FCL_SET_RESULT(table, 4, ID) \
        FCL_SET_RESULT(table, 5, ID) \
        FCL_SET_RESULT(table, 6, ID) \
        FCL_SET_RESULT(table, 7, ID) \
        FCL_SET_RESULT(table, 8, ID) \
        FCL_SET_RESULT(table, 9, ID) \
        FCL_SET_RESULT(table, 10, ID) \
        FCL_SET_RESULT(table, 11, ID) \
        FCL_SET_RESULT(table, 12, ID) \
        FCL_SET_RESULT(table, 13, ID) \
        FCL_SET_RESULT(table, 14, ID) \
        FCL_SET_RESULT(table, 15, ID) \
        FCL_SET_RESULT(table, 16, ID) \
        FCL_SET_RESULT(table, 17, ID) \
        FCL_SET_RESULT(table, 18, ID) \
        FCL_SET_RESULT(table, 19, ID) \
        FCL_SET_RESULT(table, 20, ID) \
        FCL_SET_RESULT(table, 21, ID) \
        FCL_SET_RESULT(table, 22, ID) \
        FCL_SET_RESULT(table, 23, ID) \
        FCL_SET_RESULT(table, 24, ID) \
        FCL_SET_RESULT(table, 25, ID) \
        FCL_SET_RESULT(table, 26, ID) \
        FCL_SET_RESULT(table, 27, ID) \
        FCL_SET_RESULT(table, 28, ID) \
        FCL_SET_RESULT(table, 29, ID) \
        FCL_SET_RESULT(table, 30, ID) \
        FCL_SET_RESULT(table, 31, ID) \
        FCL_SET_RESULT(table, 32, ID) \
        FCL_SET_RESULT(table, 33, ID) \
        FCL_SET_RESULT(table, 34, ID) \
        FCL_SET_RESULT(table, 35, ID) \
        source = &((FclAnimationResultRecord *)table)[(SLOT)]; \
        memcpy(&result_storage[37 - (INDEX)].record, source, 0x1c); \
        node = (FclAnimationNode *)FUN_003dffc0((int *)s0, (ID), result_storage[37 - (INDEX)].record.value); \
        if ((ID) == 0) { \
            FUN_003c4820((int *)(s0->value + 4), (int *)node->link); \
            FUN_003c4710((int *)(s0->value + 4), 0, (int *)node->link); \
        } \
        fclCombineList003df100(node, &result_storage[37 - (INDEX)].record); \
    } while (0)

// FUN_003E0C20 NONMATCHING
void FUN_003e0c20(void *param_1, u32 param_2, u32 param_3)
{
    struct {
        u32 pad;
        FclAnimationResultRecord record;
    } result_storage[38];

    switch (param_2) {
    case 0:
        if (*(u32 *)param_1 == 3) {
            break;
        }
        if (param_3 == 0) {
            FCL_COMBINE_CASE(0, 0, 0);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(0, 1, 1);
        }
        break;
    case 1:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(1, 2, 2);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(1, 3, 3);
        }
        break;
    case 2:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(2, 4, 4);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(2, 5, 5);
        } else if (param_3 == 2) {
            FCL_COMBINE_CASE(2, 5, 6);
        }
        break;
    case 3:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(3, 6, 7);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(3, 7, 8);
        } else if (param_3 == 2) {
            FCL_COMBINE_CASE(3, 7, 9);
        }
        break;
    case 4:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(4, 8, 10);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(4, 9, 11);
        }
        break;
    case 5:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(5, 10, 12);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(5, 11, 13);
        }
        break;
    case 6:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(6, 12, 14);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(6, 13, 15);
        }
        break;
    case 7:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(7, 14, 16);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(7, 15, 17);
        }
        break;
    case 8:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(8, 16, 18);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(8, 17, 19);
        }
        break;
    case 9:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(9, 18, 20);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(9, 19, 21);
        }
        break;
    case 10:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(10, 20, 22);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(10, 21, 23);
        }
        break;
    case 11:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(11, 22, 24);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(11, 23, 25);
        }
        break;
    case 12:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(12, 24, 26);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(12, 25, 27);
        }
        break;
    case 13:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(13, 26, 28);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(13, 27, 29);
        }
        break;
    case 14:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(14, 28, 30);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(14, 29, 31);
        }
        break;
    case 15:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(15, 30, 32);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(15, 31, 33);
        }
        break;
    case 16:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(16, 32, 34);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(16, 33, 35);
        }
        break;
    case 17:
        if (param_3 == 0) {
            FCL_COMBINE_CASE(17, 34, 36);
        } else if (param_3 == 1) {
            FCL_COMBINE_CASE(17, 35, 37);
        } else if (param_3 == 3) {
            FclAnimationNode* node =
                (FclAnimationNode *)FUN_003dff80(
                    *(int **)((unsigned char *)param_1 + 0x98), 0x11);
            node->value_storage->values[0] |= 2;
        } else if (param_3 == 4) {
            FclAnimationNode* node =
                (FclAnimationNode *)FUN_003dff80(
                    *(int **)((unsigned char *)param_1 + 0x98), 0x11);
            node->value_storage->values[0] &= ~2;
        }
        break;
    default:
        break;
    }
}
#undef FCL_COMBINE_CASE
