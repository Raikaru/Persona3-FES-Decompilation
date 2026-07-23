#include "temporary.h"
#include "Scene/mt_sceneFunc.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kernel/Kwln/kwlnTask.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u32 DAT_0067ef00;
extern u32 DAT_006a2da0;
extern u32 DAT_006a2da8;
extern u32 DAT_006a2ed8;
extern u32 DAT_006a2ee0;
extern u32 DAT_006a2ee8;
extern u32 DAT_006a2ef0;
extern u32 DAT_006a2ef8;
extern u32 DAT_006a2f00;
extern u32 DAT_006a2f08;
extern u32 DAT_006a2f10;
extern u32 DAT_006a2f18;
extern u32 DAT_006a2f20;
extern u32 DAT_006a2f28;
extern u32 DAT_006a2f30;
extern u32 DAT_006a2f38;
extern u32 DAT_006a2f40;
extern u32 DAT_006a2f48;
extern char DAT_006a2df0[];
extern u32 DAT_006a2f50;
extern u32 DAT_007cad5c;
extern u32 DAT_007cada0;
extern u32 DAT_007caea4;
extern u32 DAT_007caf1c;
extern u32 DAT_007cb0b8;
extern u32 DAT_007cd560;
extern u32 DAT_007cd564;
extern u32 DAT_007ce658;
extern u32 DAT_007ce65c;
extern u32 DAT_007ce660;
extern u32 DAT_007ce664;
extern u32 DAT_007ce668;
extern u32 DAT_0095aff0;
extern u32 DAT_0095aff4;
extern u32 DAT_0095aff8;
extern u32 DAT_0095affc;
extern u32 DAT_0095b000;
extern short * DAT_0095b070;
#pragma alias DAT_0095b070_ptr DAT_0095b070
extern u8 DAT_0095b070_ptr[];
extern u32 DAT_0095b074;
extern u32 DAT_0095b078;
extern u32 DAT_0095b0f8;
extern u32 DAT_0095b178;
extern u32 DAT_0095b1f8;
extern u32 DAT_0095b204;
extern u32 DAT_0095b208;
extern u32 DAT_0095b20c;
extern u32 DAT_0095b210;
extern u32 DAT_0095b218;
extern u32 DAT_0095b21c;
extern u32 DAT_0095b220;
extern u32 DAT_0095b224;
extern u32 DAT_0095b238;
extern u32 DAT_0095b240;
extern u32 DAT_0095b244;
extern u32 DAT_0095b248;
extern u32 DAT_0095b24c;
extern u32 DAT_0095b254;
extern u32 DAT_0095b258;
extern u32 DAT_0095b25c;
extern u32 DAT_0095b260;
extern u32 DAT_0095b264;
extern u32 DAT_0095b268;
extern u32 DAT_0095b26c;
extern u32 DAT_0095b270;
extern u32 DAT_0095b274;
extern u32 DAT_0095b278;
extern u32 DAT_0095b27c;
extern u32 DAT_0095b284;
extern u32 DAT_0095b288;
extern u32 * DAT_0095b28c;
extern u32 DAT_0095b290;
extern u32 DAT_0095b294;
extern u32 DAT_0095b298;
extern u16 * DAT_0095b29c;
extern u32 DAT_0095b2a4;
extern u32 DAT_0095b2b4;
extern u32 DAT_0095b434;
extern u32 DAT_0095b440;
extern u32 DAT_0095b444;
extern u32 DAT_0095b448;
extern u32 DAT_0095b44c;
extern u32 DAT_0095b454;
extern u32 DAT_0095b458;
extern u32 DAT_0095b45c;
extern u32 DAT_0095b460;
extern u32 DAT_0095b474;
extern u32 DAT_0095b47c;
extern u32 DAT_0095b480;
extern u32 DAT_0095b484;
extern u32 DAT_0095b488;
extern u32 DAT_0095b4a0;
extern u32 DAT_0095b4a8;
extern u32 DAT_0095b4b4;
extern u32 DAT_0095b4c0;
extern u32 DAT_0095b4d0;
extern u32 DAT_0095b4d4;
extern u32 DAT_0095b4e0;
extern u32 DAT_0095b4f0;
extern u32 DAT_0095b568;
extern u32 DAT_0095b5e0;
extern u32 DAT_0095b658;
#pragma alias DAT_0095b658_ptr DAT_0095b658
extern u8 DAT_0095b658_ptr[];
extern u32 DAT_0095b65c;
extern u32 DAT_0095b660;
#pragma alias DAT_0095b660_ptr DAT_0095b660
extern u8 DAT_0095b660_ptr[];
extern u32 DAT_0095b664;
extern u32 DAT_0095b668;
#pragma alias DAT_0095b668_ptr DAT_0095b668
extern u8 DAT_0095b668_ptr[];
extern u32 DAT_0095b66c;
extern u32 DAT_0095b670;
extern u32 DAT_0095b674;
extern u32 DAT_0095b678;
extern u32 DAT_0095b67c;
extern u32 DAT_0095b680;
extern u32 DAT_0095b684;
extern u32 DAT_0095b688;
extern u32 DAT_0095b68c;
extern u32 DAT_0095b690;
extern u32 DAT_0095b694;
extern u32 DAT_0095b698;
extern u32 DAT_0095b69c;
extern u32 DAT_0095b6a0;
extern u32 DAT_0095b6a4;
extern u32 DAT_0095b6a8;
extern u32 DAT_0095b6ac;
extern u32 DAT_0095b6b0;
extern u32 DAT_0095b6b4;
extern u32 DAT_0095b6b8;
extern u32 DAT_0095b6bc;
extern u32 DAT_0095b6c0;
extern u32 DAT_0095b6c4;
extern u32 DAT_0095b6c8;
extern u32 DAT_0095b6cc;
extern u32 DAT_0095b6d0;
extern u32 DAT_0095b6d4;
extern u32 DAT_0095b6d8;
extern u32 DAT_0095b6dc;
extern u32 DAT_0095b6e0;
extern u32 DAT_0095b6e4;
extern u32 DAT_0095b6e8;
extern u32 DAT_0095b6ec;
extern u32 DAT_0095b6f0;
extern u32 * DAT_0095b6f4;
extern u32 DAT_0095b6f8;
extern u32 DAT_0095b6fc;
extern u32 DAT_0095b700;
extern u32 DAT_0095b704;
extern u32 DAT_0095b708;
extern u32 DAT_0095b70c;
extern u32 DAT_0095b710;
extern u32 DAT_0095b714;
extern u32 DAT_0095b718;
extern u32 DAT_0095b71c;
extern u32 DAT_0095b720;
extern u32 DAT_0095b724;
extern u32 DAT_0095b728;
extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u8 * PTR_s_event_SiteibiEvent_bf_007cd570;
extern u8 * PTR_s_event_comuPack_pak_007cd568;
extern u8 * PTR_s_event_comuTable_bin_007cd56c;
extern u8 * PTR_s_icon_ICON1_EPL_006a3130[];
extern u16 * puGpffffa850;
extern float fGpffff8228;
extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960184;

void FUN_003bcc80();
void FUN_003bceb0(int param);
void FUN_0034fd70(Model* mdl, s32 type);
void FUN_003bc940();
void FUN_003b9610(Resrc* param);
void FUN_003bb7a0(Resrc* param);

typedef struct ResrcType7 ResrcType7;
struct ResrcType7
{
    Resrc base;
    u8 unkData_100[8];
    s32 unk_108;
};

typedef struct SceneInterpWork SceneInterpWork;
struct SceneInterpWork
{
  u8 pad0[0x10];
  float value10;
  float value14;
  float value18;
  u8 pad1[0xc];
  u32 flags28;
  u8 pad2[0x38];
  float value64;
  float value68;
  float value6c;
  float value70;
  float value74;
  float value78;
  u8 value7c;
  u8 value7d;
  u8 pad3[2];
  u32 value80;
  u32 value84;
};



/* Region 0x390000-0x3CFFFF recovered prototypes */
void* MT_SceneFunc_UpdateSceneMngTask(KwlnTask* sceneMngTask);
void MT_SceneFunc_DestroySceneMngTask(KwlnTask* sceneMngTask);
void* MT_SceneFunc_UpdateSceneMngDrawTask(KwlnTask* sceneMngDrawTask);
KwlnTask* MT_SceneFunc_CreateTasks();
u32 FUN_003b88c0(float param_1,Resrc *param_2,u32 *param_3,u32 param_4,u32 param_5);
#pragma alias FUN_003b88c0_scene FUN_003b88c0
extern u32 FUN_003b88c0_scene(Resrc *param_1,u32 param_2,float param_3,u32 param_4);
u32 FUN_003b89f0(u32 param_1,u32 param_2,float param_3,u32 param_4);
u8 FUN_003b8a60(SceneInterpWork *param_1,float *param_2,u32 param_3,u8 param_4);
u32  FUN_003b8b30(u64 param_1,float *param_2,u32 param_3,u8 param_4);
u32 FUN_003b8c30(u64 param_1,float *param_2,u32 param_3);
u32 FUN_003b8ce0(u32 param_1,u8 param_2,u32 param_3,u32 param_4);
#pragma alias FUN_003b8ce0_scene FUN_003b8ce0
extern u64 FUN_003b8ce0_scene(u32 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_003b8e10(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3);
u32 FUN_003b8f30(void);
u32  FUN_003b8ff0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                  u32 param_5,u32 param_6,float param_7);
 #pragma alias FUN_003b8ff0_typed FUN_003b8ff0
 extern u32 FUN_003b8ff0_typed(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                                u32 param_5,u32 param_6,float param_7);
u32  FUN_003b91c0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                  u32 param_5,u32 param_6,float param_7);
u32  FUN_003b9260(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
#pragma alias FUN_003b9260_typed FUN_003b9260
extern u32 FUN_003b9260_typed(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
u32  FUN_003b9320(u32 param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
void FUN_003b93c0(u32 param_1,short param_2,short param_3,short param_4,

                 short param_5);
#pragma alias FUN_003b8ff0_scene FUN_003b8ff0
extern u32 FUN_003b8ff0_scene(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_00530da0_scene FUN_00530da0
extern u32 FUN_00530da0_scene(float param_1);
#pragma alias FUN_003bc0e0_scene FUN_003bc0e0
extern float FUN_003bc0e0_scene(char *param_1);
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias FUN_00100d80_typed_scene FUN_00100d80
extern void *FUN_00100d80_typed_scene(const char *param_1,u32 param_2);

// Note: FUN_003bd130 keeps an absolute table base in retail.
#pragma alias DAT_0095b000_abs DAT_0095b000
extern u8 DAT_0095b000_abs[];

extern void FUN_0019d3f0(const char *param_1,u32 param_2);
#pragma alias FUN_003b9260_scene FUN_003b9260
extern u32 FUN_003b9260_scene(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
u32 FUN_003b9500(Resrc* param_1,int param_2);
u32 FUN_003b9550(u64 param_1,int param_2);
u32 FUN_003b95a0(void);
void FUN_003b9610(Resrc* param_1);
u32 FUN_003baa70(u64 param_1);
u32 FUN_003bac40(Resrc *param_1,u32 param_2);
u32 FUN_003bb010(u64 param_1,u32 param_2);
void FUN_003bb060(u16 param_1,u8 param_2);
u32 FUN_003bb0c0(u16* param_1,int param_2);
u32 FUN_003bb180(u16 param_1,int param_2);
u32  FUN_003bb1d0(u16 param_1,u8 param_2,u8 param_3,u16 param_4,  u16 param_5);
u32 FUN_003bb280(void);
void FUN_003bb340(void);
void FUN_003bb390(u32 param_2,u16 param_3,float param_1);
void FUN_003bb400(u32 param_1);
void FUN_003bb450(float param_1,u32 param_2,u32 param_3,u32 param_4,  float *param_5,float *param_6);
void FUN_003bb620(u32 param_1,u32 *param_2,int param_3);
void FUN_003bb7a0(Resrc* param_1);
void FUN_003bb9b0(float *param_1);
void FUN_003bba70(int param_1);
void FUN_003bbaa0(float *param_1,float *param_2,float *param_3);
void FUN_003bbb90(u64 param_1,u32 *param_2);
void FUN_003bbc90(float param_1,float *param_2,float *param_3,float *param_4,float *param_5,  float *param_6,float *param_7);
void FUN_003bbd40(float param_1,char *param_2,u64 param_3);
float FUN_003bbed0(float param_1,float param_2,u32 param_3);
void FUN_003bbfd0(u32 param_1,u32 param_2,u64 param_3,u64 param_4,  u64 param_5,float *param_6,float *param_7);
float FUN_003bc0e0(char *param_1);
float FUN_003bc220(char *param_1,float param_2,float param_3,float *param_4,u32 *param_5);
float FUN_003bc730(char *param_1,int param_2);
int FUN_003bc8f0(char *param_1);
u8 FUN_003bc900(float *param_1);
void FUN_003bc940(void);
void FUN_003bcbf0(int param_1,int param_2);
void FUN_003bcc80(void);
int FUN_003bcda0(int *param_1,int *param_2);
void FUN_003bceb0(int param_1);
void FUN_003bd130(void);
u32 FUN_003bd1c0(u32 param_1);
#pragma alias FUN_003bd1c0_mt FUN_003bd1c0
extern u32 FUN_003bd1c0_mt(u32 param_1);
u32 FUN_003bd230(void);
void FUN_003bd280(void);
short ** FUN_003bd870(void);
u32 * FUN_003bd880(void);
u32 * FUN_003bd890(void);
u32 * FUN_003bd8a0(void);
u32 FUN_003bd8b0(u32 param_1,u32 param_2,u32 param_3);
u16 FUN_003bd9a0(u32 param_1,u32 param_2);
u32 FUN_003bda60(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
float FUN_003bdb80(void);
u32 FUN_003bdba0(void);
u16 FUN_003bdbb0(void);

/* Region call-cast macros */
#define FUN_003b88c0(...) ((u32 (*)(...))FUN_003b88c0)(__VA_ARGS__)
#define FUN_003b89f0(...) ((u32 (*)(...))FUN_003b89f0)(__VA_ARGS__)
#define FUN_003b8a60(...) ((u8 (*)(...))FUN_003b8a60)(__VA_ARGS__)
#define FUN_003b8b30(...) ((u32 (*)(...))FUN_003b8b30)(__VA_ARGS__)
#define FUN_003b8c30(...) ((u32 (*)(...))FUN_003b8c30)(__VA_ARGS__)
#define FUN_003b8ce0(...) ((u32 (*)(...))FUN_003b8ce0)(__VA_ARGS__)
#define FUN_003b8e10(...) ((u64 (*)(...))FUN_003b8e10)(__VA_ARGS__)
#define FUN_003b8e80(...) ((u32 (*)(...))FUN_003b8e80)(__VA_ARGS__)
#define FUN_003b8f30(...) ((u32 (*)(...))FUN_003b8f30)(__VA_ARGS__)
#define FUN_003b8ff0(...) ((u32 (*)(...))FUN_003b8ff0)(__VA_ARGS__)
#define FUN_003b91c0(...) ((u64 (*)(...))FUN_003b91c0)(__VA_ARGS__)
#define FUN_003b9260(...) ((u32 (*)(...))FUN_003b9260)(__VA_ARGS__)
#define FUN_003b9320(...) ((u64 (*)(...))FUN_003b9320)(__VA_ARGS__)
#define FUN_003b93c0(...) ((void (*)(...))FUN_003b93c0)(__VA_ARGS__)
#define FUN_003b9500(...) ((u32 (*)(...))FUN_003b9500)(__VA_ARGS__)
#define FUN_003b9550(...) ((u64 (*)(...))FUN_003b9550)(__VA_ARGS__)
#define FUN_003b95a0(...) ((u32 (*)(...))FUN_003b95a0)(__VA_ARGS__)
#define FUN_003b9610(...) ((void (*)(...))FUN_003b9610)(__VA_ARGS__)
#define FUN_003baa70(...) ((u32 (*)(...))FUN_003baa70)(__VA_ARGS__)
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#define FUN_003bb010(...) ((u32 (*)(...))FUN_003bb010)(__VA_ARGS__)
#define FUN_003bb060(...) ((void (*)(...))FUN_003bb060)(__VA_ARGS__)
#define FUN_003bb0c0(...) ((u32 (*)(...))FUN_003bb0c0)(__VA_ARGS__)
#define FUN_003bb180(...) ((u32 (*)(...))FUN_003bb180)(__VA_ARGS__)
#define FUN_003bb1d0(...) ((u32 (*)(...))FUN_003bb1d0)(__VA_ARGS__)
#define FUN_003bb280(...) ((u32 (*)(...))FUN_003bb280)(__VA_ARGS__)
#define FUN_003bb340(...) ((void (*)(...))FUN_003bb340)(__VA_ARGS__)
#define FUN_003bb390(...) ((void (*)(...))FUN_003bb390)(__VA_ARGS__)
#define FUN_003bb400(...) ((void (*)(...))FUN_003bb400)(__VA_ARGS__)
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#define FUN_003bb620(...) ((void (*)(...))FUN_003bb620)(__VA_ARGS__)
#define FUN_003bb7a0(...) ((void (*)(...))FUN_003bb7a0)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bbaa0(...) ((void (*)(...))FUN_003bbaa0)(__VA_ARGS__)
#define FUN_003bbb90(...) ((void (*)(...))FUN_003bbb90)(__VA_ARGS__)
#define FUN_003bbc90(...) ((void (*)(...))FUN_003bbc90)(__VA_ARGS__)
#define FUN_003bbd40(...) ((void (*)(...))FUN_003bbd40)(__VA_ARGS__)
#define FUN_003bbed0(...) ((float (*)(...))FUN_003bbed0)(__VA_ARGS__)
#define FUN_003bbfd0(...) ((void (*)(...))FUN_003bbfd0)(__VA_ARGS__)
#define FUN_003bc0e0(...) ((float (*)(...))FUN_003bc0e0)(__VA_ARGS__)
#define FUN_003bc220(...) ((float (*)(...))FUN_003bc220)(__VA_ARGS__)
#define FUN_003bc730(...) ((float (*)(...))FUN_003bc730)(__VA_ARGS__)
#define FUN_003bc8f0(...) ((int (*)(...))FUN_003bc8f0)(__VA_ARGS__)
#define FUN_003bc900(...) ((u8 (*)(...))FUN_003bc900)(__VA_ARGS__)
#define FUN_003bc940(...) ((void (*)(...))FUN_003bc940)(__VA_ARGS__)
#define FUN_003bcbf0(...) ((void (*)(...))FUN_003bcbf0)(__VA_ARGS__)
#define FUN_003bcc80(...) ((void (*)(...))FUN_003bcc80)(__VA_ARGS__)
#define FUN_003bcda0(...) ((int (*)(...))FUN_003bcda0)(__VA_ARGS__)
#define FUN_003bceb0(...) ((void (*)(...))FUN_003bceb0)(__VA_ARGS__)
#define FUN_003bd130(...) ((void (*)(...))FUN_003bd130)(__VA_ARGS__)
#define FUN_003bd1c0(...) ((u64 (*)(...))FUN_003bd1c0)(__VA_ARGS__)
#define FUN_003bd230(...) ((u32 (*)(...))FUN_003bd230)(__VA_ARGS__)
#define FUN_003bd280(...) ((void (*)(...))FUN_003bd280)(__VA_ARGS__)
#define FUN_003bd870(...) ((short ** (*)(...))FUN_003bd870)(__VA_ARGS__)
#define FUN_003bd880(...) ((u32 * (*)(...))FUN_003bd880)(__VA_ARGS__)
#define FUN_003bd890(...) ((u32 * (*)(...))FUN_003bd890)(__VA_ARGS__)
#define FUN_003bd8a0(...) ((u32 * (*)(...))FUN_003bd8a0)(__VA_ARGS__)
#define FUN_003bd8b0(...) ((u32 (*)(...))FUN_003bd8b0)(__VA_ARGS__)
#define FUN_003bd9a0(...) ((u16 (*)(...))FUN_003bd9a0)(__VA_ARGS__)
#define FUN_003bda60(...) ((u32 (*)(...))FUN_003bda60)(__VA_ARGS__)
#define FUN_003bdb80(...) ((float (*)(...))FUN_003bdb80)(__VA_ARGS__)
#define FUN_003bdba0(...) ((u32 (*)(...))FUN_003bdba0)(__VA_ARGS__)
#define FUN_003bdbb0(...) ((u16 (*)(...))FUN_003bdbb0)(__VA_ARGS__)


#pragma push
#pragma opt_loop_invariants on
// FUN_003bccb0
void* MT_SceneFunc_UpdateSceneMngTask(KwlnTask* sceneMngTask)
{
    s32 i;
    Resrc* res;
    ResrcType7* type7Res;
    s32 type7Status;

    (FUN_003bc940)();
    for (i = 1; i < RESRC_TYPE_MAX; i++)
    {
        for (res = MT_Scene_GetResListHead(i); res != NULL; res = res->next)
        {
            (FUN_003b9610)(res);
        }
    }

    type7Res = (ResrcType7*)MT_Scene_GetResListHead(7);
    type7Status = 1;
    for (; type7Res != NULL; type7Res = (ResrcType7*)type7Res->base.next)
    {
        if (type7Res->unk_108 == type7Status)
        {
            (FUN_003bb7a0)((Resrc*)type7Res);
            break;
        }
    }

    return KWLNTASK_CONTINUE;
}
#pragma pop

// FUN_003bcd80
void MT_SceneFunc_DestroySceneMngTask(KwlnTask* sceneMngTask)
{
    (FUN_003bcc80)();
}

// FUN_003bd010
void* MT_SceneFunc_UpdateSceneMngDrawTask(KwlnTask* sceneMngDrawTask)
{
    Resrc* res;

    res = MT_Scene_GetResListHead(6);
    (FUN_003bceb0)((int)res);
    for (; res != NULL; res = res->next)
    {
        if ((res->flags & 2) != 0 && *(Model**)((u8*)res + 0x104) != NULL)
        {
            switch (*(s8*)((u8*)res + 0x100))
            {
            case 0:
                break;
            case 1:
                FUN_0034fd70(*(Model**)((u8*)res + 0x104), 6);
                break;
            default:
                break;
            }
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_003bd0b0
KwlnTask* MT_SceneFunc_CreateTasks()
{
    KwlnTask* sceneMngTask;

    sceneMngTask = kwlnTaskCreate(NULL,
                                  "SceneManager Task",
                                  110,
                                  MT_SceneFunc_UpdateSceneMngTask,
                                  MT_SceneFunc_DestroySceneMngTask,
                                  NULL);


    kwlnTaskCreate(sceneMngTask,
                   "SceneManager Draw",
                   2109,
                   MT_SceneFunc_UpdateSceneMngDrawTask,
                   NULL,
                   NULL);

    return sceneMngTask;
}

#undef FUN_003b88c0
// FUN_003B88C0
u32 FUN_003b88c0(float param_1,Resrc *param_2,u32 *param_3,u32 param_4,u32 param_5)
{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 *puVar4;
  int iVar5;
  float fVar6;

  if (param_2 == 0) {
    return 0;
  }

  iVar3 = (int)param_2;
  uVar1 = param_2->flags;
  uVar1 = uVar1 | 1;
  param_2->flags = uVar1;
  uVar1 = uVar1 & 0xffffffbf;
  param_2->flags = uVar1;
  if (param_4 == 1) {
    param_2->flags = param_2->flags | 0x40;
  }
  *(float *)(iVar3 + 0x58) = param_1;
  *(u8 *)(iVar3 + 0x50) = 2;
  *(u32 *)(iVar3 + 0x5c) = 0;
  if (*(u32 *)(iVar3 + 0x54) == 0) {
    uVar2 = (u32)(*DAT_00960178_abs)(0x130,0x40000);
    *(u32 *)(iVar3 + 0x54) = uVar2;
    if (uVar2 == 0) {
      FUN_0019d3f0("mt_sceneFunc.c",0x23b);
    }
  }
  puVar4 = *(u32 **)(iVar3 + 0x54);
  iVar5 = 0x26;
  do {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    param_3 += 2;
    iVar5--;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 += 2;
  } while (0 < iVar5);
  fVar6 = FUN_003bc0e0_scene(*(char **)(iVar3 + 0x54));
  *(float *)(iVar3 + 0x60) = fVar6;
  uVar2 = FUN_00530da0_scene(fVar6);
  FUN_005225a8(DAT_006a2df0,uVar2);
  return 1;
}
#define FUN_003b88c0(...) ((u32 (*)(...))FUN_003b88c0)(__VA_ARGS__)
#undef FUN_003b89f0
// FUN_003B89F0

u32 FUN_003b89f0(u32 param_1,u32 param_2,float param_3,u32 param_4)



{

  u32 lVar1;
  u32 uVar2;

  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b88c0_scene((Resrc *)lVar1,param_2,param_3,param_4);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b89f0(...) ((u32 (*)(...))FUN_003b89f0)(__VA_ARGS__)
#undef FUN_003b8a60
#undef FUN_003bba70
#undef FUN_003bb9b0

// FUN_003B8A60


u8 FUN_003b8a60(SceneInterpWork *param_1,float *param_2,u32 param_3,u8 param_4)
{
  struct V3 {
    float x;
    float y;
    float z;
  } values;
  float source10;
  float source14;
  float source18;
  struct V3 *input;

  input = (struct V3 *)param_2;
  values = *input;
  source10 = 0.0f;
  source14 = 0.0f;
  source18 = 0.0f;

  if (param_1 == 0) {
    return 0;
  }

  FUN_003bba70((int)param_1);
  FUN_003bb9b0((float *)&values);
  param_1->flags28 |= 4;
  *(struct V3 *)&param_1->value64 =
      *(struct V3 *)&param_1->value10;
  *(struct V3 *)&param_1->value70 = values;
  param_1->value7c = 0;
  param_1->value7d = param_4;
  param_1->value80 = param_3;
  param_1->value84 = 0;

  return 1;
}

#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#define FUN_003b8a60(...) ((u8 (*)(...))FUN_003b8a60)(__VA_ARGS__)
#undef FUN_003b8b30
#undef FUN_003bba70
#undef FUN_003bb9b0
// FUN_003B8B30


u32

FUN_003b8b30(u64 param_1,float *param_2,u32 param_3,u8 param_4)



{

  u32 uVar1;


  int iVar3;

  struct V3 {
    float x;
    float y;
    float z;
  } values;
  struct V3 *input;
  

  iVar3 = FUN_003b5d10();

  if (iVar3 == 0) {

    uVar1 = 0;

  }

  else {

    input = (struct V3 *)param_2;
    values = *input;

    if (iVar3 == 0) {

      uVar1 = 0;

    }

    else {

      FUN_003bba70(iVar3);

      FUN_003bb9b0((float *)&values);


      *(u32 *)(iVar3 + 0x28) = *(u32 *)(iVar3 + 0x28) | 4;

      *(struct V3 *)(iVar3 + 0x64) = *(struct V3 *)(iVar3 + 0x10);
      *(struct V3 *)(iVar3 + 0x70) = values;
      *(u8 *)(iVar3 + 0x7c) = 0;

      *(u8 *)(iVar3 + 0x7d) = param_4;

      *(u32 *)(iVar3 + 0x80) = param_3;

      *(u32 *)(iVar3 + 0x84) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003b8b30(...) ((u32 (*)(...))FUN_003b8b30)(__VA_ARGS__)
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#undef FUN_003b8c30
// FUN_003B8C30


u32 FUN_003b8c30(u64 param_1,float *param_2,u32 param_3)


{

  int iVar1;

  u32 lVar2;


  u32 uVar3;
  u32 uVar4;
  float fVar1;

  float fVar2;

  float fVar3;

  

  lVar2 = FUN_003b5d10();

  if (lVar2 == 0) {

    uVar3 = 0;

  }

  else if (lVar2 == 0) {

    uVar3 = 0;

  }

  else {

    iVar1 = (int)lVar2;

    *(u32 *)(iVar1 + 0x28) = *(u32 *)(iVar1 + 0x28) | 0x8000;

    fVar1 = *(float *)(iVar1 + 0x1c);

    fVar2 = *(float *)(iVar1 + 0x20);

    fVar3 = *(float *)(iVar1 + 0x24);

    *(float *)(iVar1 + 0x88) = fVar1;

    *(float *)(iVar1 + 0x8c) = fVar2;

    *(float *)(iVar1 + 0x90) = fVar3;

    fVar2 = *(volatile float *)(param_2 + 0);
    fVar3 = *(volatile float *)(param_2 + 1);
    fVar1 = *(volatile float *)(param_2 + 2);

    *(float *)(iVar1 + 0x94) = fVar2;

    *(float *)(iVar1 + 0x98) = fVar3;

    *(float *)(iVar1 + 0x9c) = fVar1;

    *(u32 *)(iVar1 + 0xa0) = param_3;

    *(u32 *)(iVar1 + 0xa4) = 0;

    uVar3 = 1;

  }

  return uVar3;

}
#define FUN_003b8c30(...) ((u32 (*)(...))FUN_003b8c30)(__VA_ARGS__)
#undef FUN_003b8ce0
#pragma push
#pragma opt_rebuildconditionals off
 
// FUN_003B8CE0

u32 FUN_003b8ce0(u32 param_1,u8 param_2,u32 param_3,u32 param_4)
{
    u32 uVar1;
    int iVar2;
    u16 *puVar3;
    volatile u8 *puVar5;
    u8 bVar4;
    u8 bVar5;
    u8 bVar6;
    u8 bVar7;
    u8 bVar8;
    u8 auStack_8[8];

    if (param_1 == 0)
    {
        uVar1 = 0;
        goto end;
    }

    puVar3 = (u16 *)param_1;
    iVar2 = (int)(*puVar3 & 0xffc00) >> 10;
    if (iVar2 == 6)
    {
        goto type6;
    }
    switch (iVar2)
    {
    case 3:
        goto type3;
    default:
        goto unknown;
    }

type3:
    iVar2 = FUN_00318b00(*(u32 *)(puVar3 + 0x94));
    puVar5 = (volatile u8 *)iVar2;
    bVar5 = puVar5[0];
    bVar6 = puVar5[1];
    bVar7 = puVar5[2];
    bVar8 = puVar5[3];
    auStack_8[4] = bVar5;
    auStack_8[5] = bVar6;
    auStack_8[6] = bVar7;
    auStack_8[7] = bVar8;
    bVar4 = auStack_8[7];

    if (param_4 == 1)
    {
        *(u8 *)(puVar3 + 0x60) = 1;
    }
    else
    {
        *(u8 *)(puVar3 + 0x60) = 0;
    }
    goto finish;

type6:
    FUN_00350040(*(u32 *)(puVar3 + 0x82), auStack_8);
    bVar4 = auStack_8[3];
    goto finish;

unknown:
    uVar1 = 0;
    goto end;

finish:
    *(u32 *)(puVar3 + 0x14) = *(u32 *)(puVar3 + 0x14) | 0x4000;
    *(u8 *)(puVar3 + 0x5a) = bVar4;
    *(u8 *)((int)puVar3 + 0xb5) = param_2;
    *(u32 *)(puVar3 + 0x5c) = param_3;
    *(u32 *)((u8 *)puVar3 + 0xbc) = 0;
    uVar1 = 1;
    goto end;

end:
    return uVar1;
}
#pragma pop
#define FUN_003b8ce0(...) ((u32 (*)(...))FUN_003b8ce0)(__VA_ARGS__)
#undef FUN_003b8e10
// FUN_003B8E10

u64 FUN_003b8e10(u64 param_1,u64 param_2,u64 param_3,u64 param_4)



{

  u32 lVar1;

  u64 uVar2;
  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b8ce0_scene(lVar1,param_2,param_3,param_4);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b8e10(...) ((u64 (*)(...))FUN_003b8e10)(__VA_ARGS__)
#undef FUN_003b8e80
// FUN_003B8E80


u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3)


{

  u16 *puVar1;

  u32 uVar2;

  u32 lVar3;

  
  lVar3 = FUN_003b5d10();


  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    puVar1 = (u16 *)lVar3;

    if ((int)(*puVar1 & 0xffc00) >> 10 != 7) {

      uVar2 = 0;

    }

    else {

      *(u32 *)(puVar1 + 0x14) = *(u32 *)(puVar1 + 0x14) | 0x400;

      *(float *)(puVar1 + 0x62) = *(float *)(puVar1 + 0x80);

      *(float *)(puVar1 + 100) = param_2;

      *(u32 *)(puVar1 + 0x66) = param_3;

      *(u32 *)(puVar1 + 0x68) = 0;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003b8e80(...) ((u32 (*)(...))FUN_003b8e80)(__VA_ARGS__)
#undef FUN_003b8f30
// FUN_003B8F30


u32 FUN_003b8f30(void)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  u32 lVar4;

  

  lVar4 = FUN_003b5d10();

  if (lVar4 == 0) {

    uVar3 = 0;

  }

  else if (lVar4 == 0) {

    uVar3 = 0;

  }

  else {

    iVar2 = (int)lVar4;

    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffe;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffb;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffff7fff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffffbf;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffbff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffff7ff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffefff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffdfff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffbfff;

    uVar3 = 1;

  }

  return uVar3;

}
#define FUN_003b8f30(...) ((u32 (*)(...))FUN_003b8f30)(__VA_ARGS__)
#undef FUN_003b8ff0
// FUN_003B8FF0 NONMATCHING


u32

FUN_003b8ff0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,

            u32 param_6,float param_7)


{

  u32 uVar1;

  u32 lVar2;

  int iVar3;

  u16 *puVar4;

  

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    puVar4 = (u16 *)param_1;

    iVar3 = (int)(*puVar4 & 0xffc00) >> 10;

    if (iVar3 == 10) {

      uVar1 = *(u32 *)(puVar4 + 0x82);

    }

    else if (iVar3 == 3) {

      uVar1 = *(u32 *)(puVar4 + 0x94);

    }

    else if (iVar3 == 2) {

      uVar1 = *(u32 *)(puVar4 + 0x8c);

    }

    else {

      if (iVar3 != 1) {

        return 0;

      }

      uVar1 = *(u32 *)(puVar4 + 0x94);

    }

    lVar2 = FUN_003186e0(uVar1,param_2 & 0xffff,(short)param_3);

    if (lVar2 == 0) {

      FUN_003189f0(uVar1,param_2 & 0xffff,param_3);

      FUN_003182d0(uVar1,param_2 & 0xffff,(short)param_3,param_4,param_5 == 1);

      if (0 < param_6) {

        FUN_00318770((float)(int)param_6,uVar1,param_2 & 0xffff,param_3);

      }

      FUN_005225a8(0x6a2e10,uVar1,param_2,param_3);

    }

    *(u32 *)(puVar4 + 0x14) = *(u32 *)(puVar4 + 0x14) & 0xffffdfff;

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003b8ff0(...) ((u32 (*)(...))FUN_003b8ff0)(__VA_ARGS__)
#undef FUN_003b91c0
// FUN_003B91C0 NONMATCHING


u32

FUN_003b91c0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,

            u32 param_6,float param_7)



{

  u32 lVar1;

  u32 uVar2;

  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b8ff0_typed((u32)lVar1,param_2,param_3,param_4,param_5,param_6,param_7);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b91c0(...) ((u64 (*)(...))FUN_003b91c0)(__VA_ARGS__)
#undef FUN_003b9260
// FUN_003B9260


u32
FUN_003b9260(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,
              u32 param_5,u32 param_6,float param_7)
{
    u32 uVar1;
    int iVar2;
    u16 *puVar3;
    u16 *puVar4;

    puVar4 = (u16 *)param_1;
    if (param_1 == 0)
    {
        uVar1 = 0;
        goto end;
    }

    iVar2 = (int)(*puVar4 & 0xffc00) >> 10;
    if (iVar2 == 3)
    {
        goto type3;
    }
    if (iVar2 == 2)
    {
        goto type2;
    }
    switch (iVar2)
    {
    case 1:
        goto type1;
    default:
        goto unknown;
    }

type1:
    puVar3 = puVar4 + 0x88;
    goto finish;

type2:
    puVar3 = puVar4 + 0x80;
    goto finish;

type3:
    puVar3 = puVar4 + 0x88;
    goto finish;

unknown:
    uVar1 = 0;
    goto end;

finish:
    *(u32 *)(puVar4 + 0x14) = *(u32 *)(puVar4 + 0x14) | 0x2000;
    *(u32 *)puVar3 = param_2;
    *(u32 *)(puVar3 + 2) = param_3;
    *(u32 *)(puVar3 + 4) = param_4;
    *(u32 *)(puVar3 + 6) = param_5;
    *(u32 *)(puVar3 + 8) = param_6;
    *(float *)(puVar3 + 10) = param_7;
    uVar1 = 1;
    goto end;
end:
    return uVar1;
}

#define FUN_003b9260(...) ((u32 (*)(...))FUN_003b9260)(__VA_ARGS__)
#undef FUN_003b9320
#pragma push
#pragma opt_rebuildconditionals off
// FUN_003B9320


u32
FUN_003b9320(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
             u32 param_5,u32 param_6,float param_7)
{
    u32 *puVar3;
    u32 uVar2;

    puVar3 = (u32 *)FUN_003b5d10();
    if (puVar3 == 0)
    {
        goto zero;
    }
    uVar2 = FUN_003b9260_typed(puVar3,param_2,param_3,param_4,
                               param_5,param_6,param_7);
    goto end;

zero:
    uVar2 = 0;

end:
    return uVar2;
}

#pragma pop
#define FUN_003b9320(...) ((u64 (*)(...))FUN_003b9320)(__VA_ARGS__)
#undef FUN_003b93c0
// FUN_003B93C0 NONMATCHING


void FUN_003b93c0(u32 param_1,short param_2,short param_3,short param_4,

                 short param_5)



{

  u32 uVar1;

  u32 uVar3;

  u32 lVar2;

  

  uVar1 = (u16)param_1;

  uVar1 = (u16)(uVar1 & 0x3ff | 0xc00);

  uVar3 = (u32)param_4;

  if (uVar3 == -1) {

    lVar2 = FUN_003b5d10(uVar1);

    if (lVar2 != 0) {

      FUN_003b8ff0_typed(lVar2,0,param_2,param_3,1,0,1.0f);

    }

    goto end;

  }

  lVar2 = FUN_003b5d10(uVar1);

  if (lVar2 == 0) {

    goto second_done;

  }

  FUN_003b8ff0_typed(lVar2,0,param_2,param_3,0,0,1.0f);

second_done:

  lVar2 = FUN_003b5d10(uVar1);

  if (lVar2 != 0) {

    FUN_003b9260_typed((u32 *)lVar2,0,uVar3,param_5,1,0,1.0f);

  }

end:

  return;

}
#define FUN_003b93c0(...) ((void (*)(...))FUN_003b93c0)(__VA_ARGS__)
#undef FUN_003b9500
// FUN_003B9500


u32 FUN_003b9500(Resrc* param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  

  iVar2 = (int)param_1;

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    if (param_2 == 1) {

      *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) | 2;

    }

    else {

      *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffd;

    }

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003b9500(...) ((u32 (*)(...))FUN_003b9500)(__VA_ARGS__)
#undef FUN_003b9550
// FUN_003B9550


u32 FUN_003b9550(u64 param_1,int param_2)



{
  Resrc* lVar1;

  lVar1 = (Resrc*)FUN_003b5d10();

  if (lVar1 != 0) {
    return (FUN_003b9500)(lVar1,param_2);
  }

  return 0;
}
#define FUN_003b9550(...) ((u64 (*)(...))FUN_003b9550)(__VA_ARGS__)
#undef FUN_003b95a0
// FUN_003B95A0


u32 FUN_003b95a0(void)



{
  u32 uVar1;
  Resrc* lVar2;

  lVar2 = (Resrc*)FUN_003b5d10();

  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else if (lVar2 == 0) {
    uVar1 = 0;
  }
  else if ((*(u32 *)((int)lVar2 + 0x28) & 1) != 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }

  return uVar1;
}
#define FUN_003b95a0(...) ((u32 (*)(...))FUN_003b95a0)(__VA_ARGS__)
#undef FUN_003b9610
// FUN_003B9610 NONMATCHING








void FUN_003b9610(Resrc* param_1)



{

  u32 uVar1;

  u32 uVar2;

  short sVar3;

  u8 *puVar4;

  u16 *puVar5;

  int iVar6;

  int iVar7;

  u16 *puVar8;

  char cVar9;

  int iVar10;

  float fVar11;

  float fVar12;

  float fStack_88;

  float fStack_84;

  float fStack_80;

  float fStack_78;

  float fStack_74;

  float fStack_70;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  u8 auStack_8 [3];

  char cStack_5;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  char cStack_1;

  

  iVar10 = 0;

  if (param_1 != 0) {

    puVar8 = (u16 *)param_1;

    uVar1 = *(u32 *)(puVar8 + 0x14);

    if ((uVar1 & 0x20) == 0) {

      if ((uVar1 & 8) == 0) {

        iVar10 = 1;

      }

    }

    else {

      iVar10 = *(int *)(puVar8 + 0x7a);

      *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffffdf;

      puVar8[0x7a] = 0;

      puVar8[0x7b] = 0;

    }

    if (iVar10 < 0) {

      iVar10 = 0;

    }

    if ((*(u32 *)(puVar8 + 0x14) & 1) != 0) {

      fStack_18 = *(float *)(puVar8 + 0x1c);

      fStack_14 = *(float *)(puVar8 + 0x1e);

      fStack_10 = *(float *)(puVar8 + 0x20);

      fStack_28 = *(float *)(puVar8 + 2);

      fStack_24 = *(float *)(puVar8 + 4);

      fStack_20 = *(float *)(puVar8 + 6);

      cVar9 = (char)puVar8[0x28];

      if (cVar9 == '\0') {

        fStack_38 = fStack_18 - fStack_28;

        fStack_34 = fStack_14 - fStack_24;

        fStack_30 = fStack_10 - fStack_20;

        fVar11 = (float)FUN_004c6ac0(&fStack_38);

        iVar6 = iVar10;

        do {

          if (fVar11 <= *(float *)(puVar8 + 0x2c)) {

            *(float *)(puVar8 + 2) = fStack_18;

            *(float *)(puVar8 + 4) = fStack_14;

            *(float *)(puVar8 + 6) = fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

            FUN_005225a8(0x6a2e40);

            break;

          }

          FUN_004c69f0(&fStack_48,&fStack_38);

          if (0 < iVar6) {

            *(float *)(puVar8 + 2) =

                 fStack_48 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 2) + 0.0;

            *(float *)(puVar8 + 4) =

                 fStack_44 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 4) + 0.0;

            *(float *)(puVar8 + 6) =

                 fStack_40 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 6) + 0.0;

          }

          iVar6 = iVar6 + -1;

        } while (0 < iVar6);

        FUN_003b7460(param_1,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x01') {

        fStack_38 = fStack_18 - *(float *)(puVar8 + 0x16);

        fStack_34 = fStack_14 - *(float *)(puVar8 + 0x18);

        fStack_30 = fStack_10 - *(float *)(puVar8 + 0x1a);

        if (*(u32 *)(puVar8 + 0x30) == 0) {

          *(float *)(puVar8 + 2) = fStack_18;

          *(float *)(puVar8 + 4) = fStack_14;

          *(float *)(puVar8 + 6) = fStack_10;

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          FUN_005225a8(0x6a2e60);

        }

        else {

          fStack_38 = fStack_38 / (float)*(u32 *)(puVar8 + 0x30);

          fStack_34 = fStack_34 / (float)*(u32 *)(puVar8 + 0x30);

          fStack_30 = fStack_30 / (float)*(u32 *)(puVar8 + 0x30);

          switch(*(u8 *)((int)puVar8 + 0x51)) {

          case 0:

            *(float *)(puVar8 + 2) =

                 fStack_38 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x16) + 0.0;

            *(float *)(puVar8 + 4) =

                 fStack_34 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x18) + 0.0;

            *(float *)(puVar8 + 6) =

                 fStack_30 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x1a) + 0.0;

            break;

          case 1:

          case 2:

          case 3:

          case 4:

          case 5:

            fVar11 = (float)FUN_003bbed0((float)*(u32 *)(puVar8 + 0x30),

                                         (float)*(u32 *)(puVar8 + 0x2e));

            *(float *)(puVar8 + 2) = fStack_38 * fVar11 + *(float *)(puVar8 + 0x16) + 0.0;

            *(float *)(puVar8 + 4) = fStack_34 * fVar11 + *(float *)(puVar8 + 0x18) + 0.0;

            *(float *)(puVar8 + 6) = fStack_30 * fVar11 + *(float *)(puVar8 + 0x1a) + 0.0;

          }

          if (*(u32 *)(puVar8 + 0x2e) < *(u32 *)(puVar8 + 0x30)) {

            *(u32 *)(puVar8 + 0x2e) = *(u32 *)(puVar8 + 0x2e) + iVar10;

          }

          else {

            *(float *)(puVar8 + 2) = fStack_18;

            *(float *)(puVar8 + 4) = fStack_14;

            *(float *)(puVar8 + 6) = fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

        }

        FUN_003b7460(param_1,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x02') {

        FUN_003bc220((char *)*(u32 *)(puVar8 + 0x2a),*(float *)(puVar8 + 0x2e),
                     *(float *)(puVar8 + 0x30),&uStack_58,&uStack_68);

        if (*(float *)(puVar8 + 0x30) <= *(float *)(puVar8 + 0x2e)) {

          if ((*(u32 *)(puVar8 + 0x14) & 0x40) == 0) {

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

          else {

            *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) - *(float *)(puVar8 + 0x30);

          }

        }

        *(u32 *)(puVar8 + 2) = uStack_58;

        *(u32 *)(puVar8 + 4) = uStack_54;

        *(u32 *)(puVar8 + 6) = uStack_50;

        for (iVar6 = 0; iVar6 < iVar10; iVar6 = iVar6 + 1) {

          *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x2c);

        }

        FUN_003b7460(param_1,puVar8 + 2,0,0);

        if ((*(u32 *)(puVar8 + 0x14) & 8) == 0) {

          *(u32 *)(puVar8 + 8) = uStack_68;

          *(u32 *)(puVar8 + 10) = uStack_64;

          *(u32 *)(puVar8 + 0xc) = uStack_60;

          FUN_003b7460(param_1,0,puVar8 + 8,0);

        }

      }

    }

    if ((*(u32 *)(puVar8 + 0x14) & 4) != 0) {

      if (*(int *)(puVar8 + 0x40) == 0) {

        *(u32 *)(puVar8 + 8) = *(u32 *)(puVar8 + 0x38);

        *(u32 *)(puVar8 + 10) = *(u32 *)(puVar8 + 0x3a);

        *(u32 *)(puVar8 + 0xc) = *(u32 *)(puVar8 + 0x3c);

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffb;

        FUN_003b7460(param_1,0,puVar8 + 8,0);

      }

      else if (*(int *)(puVar8 + 0x42) == 0) {

        *(int *)(puVar8 + 0x42) = iVar10;

      }

      else {

        FUN_003bbaa0(puVar8 + 0x32,puVar8 + 0x38,&fStack_78);

        fVar11 = (float)*(u32 *)(puVar8 + 0x40);

        fStack_74 = fStack_74 / fVar11;

        switch(*(u8 *)((int)puVar8 + 0x7d)) {

        case 0:

          uVar1 = *(u32 *)(puVar8 + 0x42);

          fStack_88 = (fStack_78 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x32) + 0.0;

          fStack_84 = fStack_74 * (float)uVar1 + *(float *)(puVar8 + 0x34) + 0.0;

          fStack_80 = (fStack_70 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x36) + 0.0;

          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

          fVar12 = (float)FUN_003bbed0((float)*(u32 *)(puVar8 + 0x40),

                                       (float)*(u32 *)(puVar8 + 0x42),

                                       *(u8 *)((int)puVar8 + 0x7d));

          fStack_88 = (fStack_78 / fVar11) * fVar12 + *(float *)(puVar8 + 0x32) + 0.0;

          fStack_84 = fStack_74 * fVar12 + *(float *)(puVar8 + 0x34) + 0.0;

          fStack_80 = (fStack_70 / fVar11) * fVar12 + *(float *)(puVar8 + 0x36) + 0.0;

        }

        *(float *)(puVar8 + 8) = fStack_88;

        *(float *)(puVar8 + 10) = fStack_84;

        *(float *)(puVar8 + 0xc) = fStack_80;

        if (*(u32 *)(puVar8 + 0x42) < *(u32 *)(puVar8 + 0x40)) {

          *(u32 *)(puVar8 + 0x42) = *(u32 *)(puVar8 + 0x42) + iVar10;

        }

        else {

          *(u32 *)(puVar8 + 8) = *(u32 *)(puVar8 + 0x38);

          *(u32 *)(puVar8 + 10) = *(u32 *)(puVar8 + 0x3a);

          *(u32 *)(puVar8 + 0xc) = *(u32 *)(puVar8 + 0x3c);

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffb;

        }

        if (iVar10 != 0) {

          FUN_003b7460(param_1,0,puVar8 + 8,0);

        }

      }

    }

    FUN_003bb9b0(puVar8 + 8);

    if ((*(u32 *)(puVar8 + 0x14) & 0x8000) != 0) {

      if (*(u32 *)(puVar8 + 0x50) == 0) {

        *(u32 *)(puVar8 + 0xe) = *(u32 *)(puVar8 + 0x4a);

        *(u32 *)(puVar8 + 0x10) = *(u32 *)(puVar8 + 0x4c);

        *(u32 *)(puVar8 + 0x12) = *(u32 *)(puVar8 + 0x4e);

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffff7fff;

        FUN_003b7460(param_1,0,0,puVar8 + 0xe);

      }

      else {

        fVar11 = (float)*(u32 *)(puVar8 + 0x50);

        uVar1 = *(u32 *)(puVar8 + 0x52);

        *(float *)(puVar8 + 0xe) =

             ((*(float *)(puVar8 + 0x4a) - *(float *)(puVar8 + 0x44)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x44) + 0.0;

        *(float *)(puVar8 + 0x10) =

             ((*(float *)(puVar8 + 0x4c) - *(float *)(puVar8 + 0x46)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x46) + 0.0;

        *(float *)(puVar8 + 0x12) =

             ((*(float *)(puVar8 + 0x4e) - *(float *)(puVar8 + 0x48)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x48) + 0.0;

        if (*(u32 *)(puVar8 + 0x52) < *(u32 *)(puVar8 + 0x50)) {

          *(u32 *)(puVar8 + 0x52) = *(u32 *)(puVar8 + 0x52) + iVar10;

        }

        else {

          *(u32 *)(puVar8 + 0xe) = *(u32 *)(puVar8 + 0x4a);

          *(u32 *)(puVar8 + 0x10) = *(u32 *)(puVar8 + 0x4c);

          *(u32 *)(puVar8 + 0x12) = *(u32 *)(puVar8 + 0x4e);

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffff7fff;

        }

        if (iVar10 != 0) {

          FUN_003b7460(param_1,0,0,puVar8 + 0xe);

        }

      }

    }

    uVar1 = *(u32 *)(puVar8 + 0x14);

    if ((uVar1 & 0x4000) != 0) {

      uVar2 = *(u32 *)(puVar8 + 0x5c);

      if (uVar2 == 0) {

        cVar9 = *(char *)((int)puVar8 + 0xb5);

        *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffbfff;

      }

      else if (*(u32 *)(puVar8 + 0x5e) < uVar2) {

        fVar11 = (((float)*(u8 *)((int)puVar8 + 0xb5) - (float)(u8)puVar8[0x5a]) / (float)uVar2)

                 * (float)*(u32 *)(puVar8 + 0x5e) + (float)(u8)puVar8[0x5a] + 0.0;

        if (2.1474836e+09 <= fVar11) {

          fVar11 = fVar11 - 2.1474836e+09;

        }

        cVar9 = (char)(int)fVar11;

        *(int *)(puVar8 + 0x5e) = *(int *)(puVar8 + 0x5e) + iVar10;

      }

      else {

        cVar9 = *(char *)((int)puVar8 + 0xb5);

        *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffbfff;

      }

      iVar6 = (int)(*puVar8 & 0xffc00) >> 10;

      if (iVar6 == 6) {

        FUN_00350040(*(u32 *)(puVar8 + 0x82),auStack_8);

        cStack_5 = cVar9;

        FUN_0034ff90(*(u32 *)(puVar8 + 0x82),auStack_8);

      }

      else if (iVar6 == 3) {

        puVar4 = (u8 *)FUN_00318b00(*(u32 *)(puVar8 + 0x94));

        uStack_4 = *puVar4;

        uStack_3 = puVar4[1];

        uStack_2 = puVar4[2];

        cStack_1 = cVar9;

        if (cVar9 == -1) {

          FUN_00319070(*(u32 *)(puVar8 + 0x94));

        }

        else if ((char)puVar8[0x60] == '\0') {

          FUN_00319070(*(u32 *)(puVar8 + 0x94));

        }

        else {

          FUN_00319050(*(u32 *)(puVar8 + 0x94));

          FUN_005225a8(0x6a2e80);

        }

        FUN_00318ad0(*(u32 *)(puVar8 + 0x94),&uStack_4);

      }

    }

    if (((*(u32 *)(puVar8 + 0x14) & 0x400) != 0) && ((int)(*puVar8 & 0xffc00) >> 10 == 7)) {

      iVar6 = *(int *)(puVar8 + 0x66);

      fVar11 = *(float *)(puVar8 + 100);

      if (iVar6 < 1) {

        *(float *)(puVar8 + 0x80) = fVar11;

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffbff;

      }

      else {

        *(float *)(puVar8 + 0x80) =

             ((fVar11 - *(float *)(puVar8 + 0x62)) / (float)iVar6) * (float)*(u32 *)(puVar8 + 0x2e)

             + *(float *)(puVar8 + 0x62) + 0.0;

        if (*(int *)(puVar8 + 0x68) < iVar6) {

          *(int *)(puVar8 + 0x68) = *(int *)(puVar8 + 0x68) + iVar10;

        }

        else {

          *(float *)(puVar8 + 0x80) = fVar11;

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffbff;

        }

      }

    }

    iVar6 = (int)(*puVar8 & 0xffc00) >> 10;

    if (iVar6 == 1) {

      for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

        if (*(int *)(puVar8 + iVar6 * 2 + 0x80) != 0) {

          FUN_0034fd30();

        }

      }

    }

    else if (iVar6 == 3) {

      for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

        if (*(int *)(puVar8 + iVar6 * 2 + 0x80) != 0) {

          FUN_0034fd30();

        }

      }

    }

    else if ((iVar6 == 6) && (*(int *)(puVar8 + 0x82) != 0)) {

      FUN_0034fd30();

    }

    if ((*(u32 *)(puVar8 + 0x14) & 0x2000) != 0) {

      puVar5 = (u16 *)0x0;

      iVar6 = 0;

      iVar7 = (int)(*puVar8 & 0xffc00) >> 10;

      if (iVar7 == 3) {

        puVar5 = puVar8 + 0x88;

        iVar6 = *(int *)(puVar8 + 0x94);

      }

      else if (iVar7 == 2) {

        puVar5 = puVar8 + 0x80;

        iVar6 = *(int *)(puVar8 + 0x8c);

      }

      else if (iVar7 == 1) {

        puVar5 = puVar8 + 0x88;

        iVar6 = *(int *)(puVar8 + 0x94);

      }

      if ((puVar5 != (u16 *)0x0) && (*(char *)(*(int *)puVar5 * 0x9c + iVar6 + 0xee) == '\x01'))

      {

        FUN_003b8ff0(*(u32 *)(puVar5 + 10),param_1,*(int *)puVar5,*(u32 *)(puVar5 + 2)

                     ,*(u32 *)(puVar5 + 4),*(u32 *)(puVar5 + 6),

                     *(u32 *)(puVar5 + 8));

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffffdfff;

      }

    }

    puVar5 = puVar8 + 0x54;

    cVar9 = (char)puVar8[0x54];

    if ((cVar9 == '\x02') || (cVar9 == '\x01')) {

      if (cVar9 == '\x01') {

        if ((*(u32 *)(puVar8 + 0x14) & 1) == 0) {

          *(u8 *)puVar5 = 0;

          sVar3 = FUN_003baa70(puVar8 + 2);

          FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

          *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

          if (*(u8 *)((int)puVar8 + 0xa9) < 4) {

            return;

          }

          *(u8 *)((int)puVar8 + 0xa9) = 0;

          return;

        }

      }

      else {

        if (cVar9 != '\x02') {

          return;

        }

        if ((*(u32 *)(puVar8 + 0x14) & 4) == 0) {

          *(u8 *)puVar5 = 0;

          sVar3 = FUN_003baa70(puVar8 + 2);

          FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

          *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

          if (*(u8 *)((int)puVar8 + 0xa9) < 4) {

            return;

          }

          *(u8 *)((int)puVar8 + 0xa9) = 0;

          return;

        }

      }

      if (iVar10 != 0) {

        if (puVar8[0x58] == 0) {

          if (puVar8[0x56] == 0) {

            sVar3 = FUN_003baa70(puVar8 + 2);

            FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

            *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

            if (3 < *(u8 *)((int)puVar8 + 0xa9)) {

              *(u8 *)((int)puVar8 + 0xa9) = 0;

            }

          }

          puVar8[0x56] = puVar8[0x56] + 1;

          if (puVar8[0x57] <= puVar8[0x56]) {

            if (puVar8[0x57] == 0) {

              *(u8 *)puVar5 = 0;

            }

            else {

              puVar8[0x56] = 0;

            }

          }

        }

        else {

          puVar8[0x58] = puVar8[0x58] - 1;

        }

      }

    }

  }

  return;

}
#define FUN_003b9610(...) ((void (*)(...))FUN_003b9610)(__VA_ARGS__)
#undef FUN_003baa70
// FUN_003BAA70 NONMATCHING


u32 FUN_003baa70(u64 param_1)



{

  int iVar1;

  long lVar2;

  u32 uVar3;

  u32 uVar4;

  float fVar5;

  u64 uStack_20;

  u32 uStack_18;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  

  iVar1 = FUN_003b5d50(0x15);

  uVar4 = *puGpffffa850;

  uVar3 = puGpffffa850[1];

  if (((0x13 < uVar4) && (uVar4 < 0x1d)) && (0x31 < uVar3)) {

    uVar3 = uVar3 - 0x31;

  }

  if (*(int *)(&DAT_0067ef00 + uVar4 * 4) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)*(u8 *)(*(int *)(&DAT_0067ef00 + uVar4 * 4) + uVar3);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

      uStack_20 = DAT_006a2da0;

      uStack_18 = DAT_006a2da8;

      iStack_10 = iVar1 + 0x11c;

      iStack_c = iVar1 + 0x128;

      iStack_8 = iVar1 + 0x134;

      lVar2 = FUN_001aaad0(param_1,&iStack_10,&uStack_20);

      if (lVar2 == 1) {

        fVar5 = *(float *)((int)param_1 + 4);

        if ((fVar5 < *(float *)(iStack_10 + 4) + 100.0) &&

           (*(float *)(iStack_10 + 4) - 100.0 < fVar5)) {

          return *(u32 *)(iVar1 + 0x14c);

        }

      }

      iStack_10 = iVar1 + 0x128;

      iStack_c = iVar1 + 0x134;

      iStack_8 = iVar1 + 0x140;

      lVar2 = FUN_001aaad0(param_1,&iStack_10,&uStack_20);

      if (lVar2 == 1) {

        fVar5 = *(float *)((int)param_1 + 4);

        if ((fVar5 < *(float *)(iStack_10 + 4) + 100.0) &&

           (*(float *)(iStack_10 + 4) - 100.0 < fVar5)) {

          return *(u32 *)(iVar1 + 0x14c);

        }

      }

    }

  }

  return uVar4;

}
#define FUN_003baa70(...) ((u32 (*)(...))FUN_003baa70)(__VA_ARGS__)
#undef FUN_003bac40
// FUN_003BAC40 NONMATCHING


u32 FUN_003bac40(Resrc *param_1,u32 param_2)



{

  u8 bVar1;

  char cVar2;

  u8 bVar3;

  u32 uVar4;

  u32 lVar5;

  u32 uVar6;

  int iVar7;

  u16 *puVar8;

  

  if (param_1 == 0) {

    uVar4 = 0;

  }

  else {

    puVar8 = (u16 *)param_1;

    iVar7 = (int)(*puVar8 & 0xffc00) >> 10;

    if (iVar7 == 1) {

      if (param_2 == '\n') {

        if (*(int *)(puVar8 + 0x84) == 0) {

          lVar5 = FUN_003bd1c0_mt(10);

          if (lVar5 != 0) {

            lVar5 = FUN_0034fcd0(lVar5);

            *(int *)(puVar8 + 0x84) = (int)lVar5;

            if (lVar5 == 0) {

              FUN_0019d3f0("mt_sceneFunc.c",0x69a);

            }

            FUN_005225a8(0x6a2ec0);

          }

        }

        else {

          FUN_0034fd10();

          FUN_005225a8(0x6a2ea0);

        }

      }

      else {

        bVar1 = (char)puVar8[0x86] != '\0';

        bVar3 = !bVar1;

        iVar7 = *(int *)(puVar8 + (u32)bVar3 * 2 + 0x80);

        if (iVar7 != 0) {

          uVar6 = (*DAT_00960184)(1,8,0x40000);

          lVar5 = FUN_00194b20(0,0x6a2db0,0x1cef,0x3b8210,0x3b8270,uVar6);

          if (lVar5 != 0) {

            *(u32 *)uVar6 = 2;

            ((u32 *)uVar6)[1] = iVar7;

          }

          (puVar8 + (u32)bVar3 * 2 + 0x80)[0] = 0;

          (puVar8 + (u32)bVar3 * 2 + 0x80)[1] = 0;

        }

        lVar5 = FUN_003bd1c0_mt(param_2);

        if (lVar5 != 0) {

          lVar5 = FUN_0034fcd0(lVar5);

          *(int *)(puVar8 + (u32)bVar1 * 2 + 0x80) = (int)lVar5;

          if (lVar5 == 0) {

            FUN_0019d3f0("mt_sceneFunc.c",0x6b3);

          }

        }

        *(u8 *)(puVar8 + 0x86) = (char)puVar8[0x86] == '\0';

      }

    }

    else {

      if (iVar7 != 3) {

        return 0;

      }

      if (param_2 == '\n') {

        if (*(int *)(puVar8 + 0x84) == 0) {

          lVar5 = FUN_003bd1c0_mt(10);

          if (lVar5 != 0) {

            uVar4 = FUN_0034fcd0(lVar5);

            *(u32 *)(puVar8 + 0x84) = uVar4;

            FUN_005225a8(0x6a2ec0);

            if (*(int *)(puVar8 + 0x84) == 0) {

              FUN_0019d3f0("mt_sceneFunc.c",0x6c8);

            }

          }

        }

        else {

          FUN_0034fd10();

          FUN_005225a8(0x6a2ea0);

        }

      }

      else {

        cVar2 = (char)puVar8[0x86];

        bVar1 = cVar2 == '\0';

        *(u8 *)(puVar8 + 0x86) = cVar2 == '\0';

        iVar7 = *(int *)(puVar8 + (u32)bVar1 * 2 + 0x80);

        if (iVar7 != 0) {

          uVar6 = (*DAT_00960184)(1,8,0x40000);

          lVar5 = FUN_00194b20(0,0x6a2db0,0x1cef,0x3b8210,0x3b8270,uVar6);

          if (lVar5 != 0) {

            *(u32 *)uVar6 = 2;

            ((u32 *)uVar6)[1] = iVar7;

          }

          (puVar8 + (u32)bVar1 * 2 + 0x80)[0] = 0;

          (puVar8 + (u32)bVar1 * 2 + 0x80)[1] = 0;

        }

        lVar5 = FUN_003bd1c0_mt(param_2);

        if (lVar5 != 0) {

          lVar5 = FUN_0034fcd0(lVar5);

          *(int *)(puVar8 + (u32)(cVar2 != '\0') * 2 + 0x80) = (int)lVar5;

          if (lVar5 == 0) {

            FUN_0019d3f0("mt_sceneFunc.c",0x6e3);

          }

        }

      }

    }

    uVar4 = 1;

  }

  return uVar4;

}
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#undef FUN_003bac40
#undef FUN_003bb010
// FUN_003BB010


u32 FUN_003bb010(u64 param_1,u32 param_2)



{

  Resrc *lVar1;


  

  lVar1 = (Resrc *)FUN_003b5d10();

  if (lVar1 != 0) {

    return FUN_003bac40(lVar1,param_2);

  }

  return 0;

}
#define FUN_003bb010(...) ((u32 (*)(...))FUN_003bb010)(__VA_ARGS__)
#undef FUN_003bb060
#undef FUN_003bac40
// FUN_003BB060


void FUN_003bb060(u16 param_1,u8 param_2)



{
  Resrc *lVar1;

  

  lVar1 = (Resrc *)FUN_003b5d10((u16)(param_1 & 0x3ff | 0xc00));

  if (lVar1 != 0) {

    FUN_003bac40(lVar1,(u8)(param_2 & 0xff));

  }

  return;

}
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#define FUN_003bb060(...) ((void (*)(...))FUN_003bb060)(__VA_ARGS__)
#undef FUN_003bb0c0
// FUN_003BB0C0


u32 FUN_003bb0c0(u16* param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  u16 *puVar3;

  int iVar4;

  

  iVar4 = 0;

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    puVar3 = (u16 *)param_1;

    iVar2 = (int)(*puVar3 & 0xffc00) >> 10;

    if (iVar2 == 3) goto case1;
    switch (iVar2) {
    case 1:
      goto case3;
    default:
      goto switch_end;
    }
case3:
    iVar4 = *(int *)(puVar3 + 0xf2);
    goto switch_end;
case1:
    iVar4 = *(int *)(puVar3 + 0xf8);
switch_end:
    if (iVar4 == 0) {

      uVar1 = 0;

    }

    else {

      if (param_2 == 1) {

        FUN_0019c310(iVar4,3);

      }

      else {

        FUN_0019c310(iVar4,0);

      }

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003bb0c0(...) ((u32 (*)(...))FUN_003bb0c0)(__VA_ARGS__)
#undef FUN_003bb180
// FUN_003BB180


u32 FUN_003bb180(u16 param_1,int param_2)
{
  Resrc *lVar1;

  lVar1 = MT_Scene_GetRes(param_1);
  if (lVar1 != 0) {
    return (FUN_003bb0c0)((u16 *)lVar1,param_2);
  }

  return 0;
}
#define FUN_003bb180(...) ((u32 (*)(...))FUN_003bb180)(__VA_ARGS__)
#undef FUN_003bb1d0
// FUN_003BB1D0


u32

FUN_003bb1d0(u16 param_1,u8 param_2,u8 param_3,u16 param_4,

            u16 param_5)



{
  u32 lVar3;
  u32 uVar2;
  u8 *puVar4;

  lVar3 = (u32)MT_Scene_GetRes(param_1);

  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    puVar4 = (u8 *)(lVar3 + 0xa8);
    FUN_00521408(puVar4,0,10);
    puVar4[0] = param_2;
    puVar4[1] = 0;
    puVar4[2] = param_3;
    *(u16 *)(puVar4 + 6) = param_4;
    *(u16 *)(puVar4 + 8) = param_5;
    uVar2 = 1;
  }

  return uVar2;

}
#define FUN_003bb1d0(...) ((u32 (*)(...))FUN_003bb1d0)(__VA_ARGS__)
#undef FUN_003bb280
// FUN_003BB280


u32 FUN_003bb280(void)



{

  int iVar1;

  u32 uVar2;

  u32 lVar3;

  u16 *puVar4;

  lVar3 = FUN_003b5d10();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    puVar4 = (u16 *)lVar3;

    if (((*puVar4 & 0xffc00) >> 10) != 7) {

      uVar2 = 0;

    }

    else {

      for (iVar1 = FUN_003b5d50(7); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

        *(u32 *)(iVar1 + 0x108) = 0;

      }

      uVar2 = 1;

      *(u32 *)(lVar3 + 0x108) = uVar2;

    }
  }

  return uVar2;

}

#define FUN_003bb280(...) ((u32 (*)(...))FUN_003bb280)(__VA_ARGS__)
#undef FUN_003bb340
// FUN_003BB340


void FUN_003bb340(void)



{

  int iVar1;

  

  for (iVar1 = FUN_003b5d50(7); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

    *(u32 *)(iVar1 + 0x108) = 0;

  }

  return;

}
#define FUN_003bb340(...) ((void (*)(...))FUN_003bb340)(__VA_ARGS__)
#undef FUN_003bb390
// FUN_003BB390


void FUN_003bb390(u32 param_2,u16 param_3,float param_1)



{

  u16 localParam3;
  u16 localParam2;
  Resrc *lVar1;
  localParam3 = param_3;
  localParam2 = param_2;
  if ((RESRC_GET_TYPE(localParam2) == RESRC_TYPE_07) && (lVar1 = (Resrc*)FUN_003b5d10(param_2), lVar1 != 0)) {

    *(u16 *)((u8*)lVar1 + 0x10c) = localParam3;

    *(float *)((u8*)lVar1 + 0x104) = param_1;

  }

  return;

}
#define FUN_003bb390(...) ((void (*)(...))FUN_003bb390)(__VA_ARGS__)
#undef FUN_003bb400
// FUN_003BB400


void FUN_003bb400(u32 param_1)



{

  u16 localParam1;
  Resrc *lVar1;
  localParam1 = (u16)param_1;
  if ((RESRC_GET_TYPE(localParam1) == RESRC_TYPE_07) && (lVar1 = (Resrc*)FUN_003b5d10(param_1), lVar1 != 0)) {

    *(u16 *)((int)lVar1 + 0x10c) = 0;
    *(u32 *)((int)lVar1 + 0x104) = 0;

  }

  return;

}
#define FUN_003bb400(...) ((void (*)(...))FUN_003bb400)(__VA_ARGS__)
#undef FUN_003bb450
// FUN_003BB450 NONMATCHING


void FUN_003bb450(float param_1,u32 param_2,u32 param_3,u32 param_4,

                 float *param_5,float *param_6)



{

  float fVar1;

  float fVar2;

  u32 uStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  u32 uStack_a4;

  u32 uStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  u32 uStack_88;

  u32 uStack_80;

  u32 uStack_7c;

  u32 uStack_78;

  u64 uStack_70;

  u32 uStack_68;

  u64 uStack_60;

  u32 uStack_58;

  u64 uStack_50;

  u32 uStack_48;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  u64 uStack_10;

  u32 uStack_8;

  

  uStack_10 = DAT_006a2ed8;

  uStack_8 = DAT_006a2ee0;

  uStack_50 = DAT_006a2ee8;

  uStack_48 = DAT_006a2ef0;

  uStack_60 = DAT_006a2ef8;

  uStack_58 = DAT_006a2f00;

  uStack_70 = DAT_006a2f08;

  uStack_68 = DAT_006a2f10;

  uStack_88 = 0x3f800000;

  uStack_9c = 0x3f800000;

  uStack_b0 = 0x3f800000;

  uStack_a0 = 0;

  uStack_a8 = 0;

  uStack_ac = 0;

  uStack_8c = 0;

  uStack_90 = 0;

  uStack_98 = 0;

  uStack_78 = 0;

  uStack_7c = 0;

  uStack_80 = 0;

  uStack_a4 = uStack_a4 | 0x20003;

  FUN_004c31b0(param_3,&uStack_b0,&uStack_60,1);

  FUN_004c31b0(param_2,&uStack_b0,&uStack_50,1);

  FUN_004c31b0(param_4,&uStack_b0,&uStack_70,1);

  FUN_004c6c60(&fStack_20,&uStack_10,&uStack_b0);

  fVar1 = param_5[1];

  fVar2 = param_5[2];

  *param_6 = (*param_5 + 0.0) - fStack_20 * param_1;

  param_6[1] = (fVar1 + 0.0) - fStack_1c * param_1;

  param_6[2] = (fVar2 + 0.0) - fStack_18 * param_1;

  return;

}
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#undef FUN_003bb620
// FUN_003BB620 NONMATCHING


void FUN_003bb620(u32 param_1,u32 *param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  long lVar3;

  int iVar4;

  u64 *puVar5;

  u32 *puVar6;

  u32 auStack_d0 [16];

  u64 uStack_90;

  u32 uStack_88;

  float afStack_50 [2];

  float fStack_48;

  u64 uStack_40;

  u32 uStack_38;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  float fStack_8;

  

  fStack_10 = *(float *)(param_3 + 4);

  uStack_c = *(u32 *)(param_3 + 8);

  fStack_8 = *(float *)(param_3 + 0xc);

  uStack_20 = *(u32 *)(param_3 + 0x10);

  uStack_1c = *(u32 *)(param_3 + 0x14);

  uStack_18 = *(u32 *)(param_3 + 0x18);

  if ((*(short *)(param_3 + 0x10c) != 0) && (lVar3 = FUN_003b5d10(), lVar3 != 0)) {

    iVar4 = (int)lVar3;

    fStack_10 = *(float *)(iVar4 + 4);

    uStack_c = *(u32 *)(iVar4 + 8);

    fStack_8 = *(float *)(iVar4 + 0xc);

    param_1 = *(u32 *)(param_3 + 0x104);

    FUN_003b79a0(auStack_d0,&fStack_10,&uStack_20);

    puVar6 = auStack_d0;

    puVar5 = &uStack_90;

    iVar4 = 8;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      iVar4 = iVar4 + -1;

      *(u32 *)puVar5 = uVar1;

      *(u32 *)((int)puVar5 + 4) = uVar2;

      puVar5 = puVar5 + 1;

    } while (0 < iVar4);

    uStack_40 = uStack_90;

    uStack_38 = uStack_88;

    FUN_004c69f0(afStack_50,&uStack_40);

    fStack_10 = (fStack_10 + 0.0) - afStack_50[0] * 15.0;

    fStack_8 = (fStack_8 + 0.0) - fStack_48 * 15.0;

  }

  FUN_003bb450(param_1,uStack_20,uStack_1c,uStack_18,&fStack_10,&uStack_30);

  *param_2 = uStack_30;

  param_2[1] = uStack_2c;

  param_2[2] = uStack_28;

  return;

}
#define FUN_003bb620(...) ((void (*)(...))FUN_003bb620)(__VA_ARGS__)
#undef FUN_003bb7a0
// FUN_003BB7A0 NONMATCHING


void FUN_003bb7a0(Resrc* param_1)



{

  int iVar1;

  long lVar2;

  u32 *puVar3;

  long lVar4;

  int iVar6;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  u32 uStack_48;

  u32 uStack_44;

  u64 uStack_40;

  u32 uStack_38;

  u64 uStack_30;

  u32 uStack_28;

  u64 uStack_20;

  u32 uStack_18;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u64 uVar5;

  

  lVar4 = FUN_00198590();

  uStack_20 = DAT_006a2f18;

  uStack_18 = DAT_006a2f20;

  uStack_30 = DAT_006a2f28;

  uStack_28 = DAT_006a2f30;

  uStack_40 = DAT_006a2f38;

  uStack_38 = DAT_006a2f40;

  iVar1 = *(int *)((int)lVar4 + 4);

  if (((param_1 != 0) && (lVar4 != 0)) && (iVar1 != 0)) {

    FUN_003bb620(0,&uStack_10,param_1);

    iVar6 = (int)param_1;

    *(u32 *)(iVar6 + 4) = uStack_10;

    *(u32 *)(iVar6 + 8) = uStack_c;

    *(u32 *)(iVar6 + 0xc) = uStack_8;

    uVar5 = FUN_004c38c0();

    puVar3 = (u32 *)uVar5;

    puVar3[10] = 0x3f800000;

    puVar3[5] = 0x3f800000;

    *puVar3 = 0x3f800000;

    puVar3[4] = 0;

    puVar3[2] = 0;

    puVar3[1] = 0;

    puVar3[9] = 0;

    puVar3[8] = 0;

    puVar3[6] = 0;

    puVar3[0xe] = 0;

    puVar3[0xd] = 0;

    puVar3[0xc] = 0;

    puVar3[3] = puVar3[3] | 0x20003;

    FUN_004c31b0(*(u32 *)(iVar6 + 0x14),uVar5,&uStack_20,1);

    FUN_004c31b0(*(u32 *)(iVar6 + 0x10),uVar5,&uStack_30,1);

    FUN_004c31b0(*(u32 *)(iVar6 + 0x18),uVar5,&uStack_40,1);

    FUN_004c35d0(uVar5,&uStack_10,2);

    lVar2 = FUN_003bc900(&uStack_48);

    if (lVar2 == 1) {

      uStack_58 = uStack_48;

      uStack_54 = uStack_44;

      uStack_50 = 0;

      FUN_004c35d0(uVar5,&uStack_58);

    }

    FUN_004cb930(iVar1);

    FUN_004cb7f0(iVar1,uVar5,0);

    FUN_004c3880(uVar5);

    FUN_001a4580(*(u32 *)(iVar6 + 0x100),lVar4);

  }

  return;

}
#define FUN_003bb7a0(...) ((void (*)(...))FUN_003bb7a0)(__VA_ARGS__)
#undef FUN_003bb9b0
// FUN_003BB9B0 NONMATCHING


void FUN_003bb9b0(float *param_1)



{

  float *pfVar1;

  int iVar2;

  float afStack_10 [4];

  

  afStack_10[0] = *param_1;

  afStack_10[1] = param_1[1];

  afStack_10[2] = param_1[2];

  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {

    pfVar1 = afStack_10 + iVar2;

    while (360.0 <= *pfVar1) {

      *pfVar1 = *pfVar1 - 360.0;

    }

    while (*pfVar1 < 0.0) {

      *pfVar1 = *pfVar1 + 360.0;

    }

  }

  *param_1 = afStack_10[0];

  param_1[1] = afStack_10[1];

  param_1[2] = afStack_10[2];

  return;

}
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#undef FUN_003bba70
// FUN_003BBA70


void FUN_003bba70(int param_1)



{

  (FUN_003bb9b0)((float *)(param_1 + 0x10));

  return;

}
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#undef FUN_003bbaa0
// FUN_003BBAA0 NONMATCHING


void FUN_003bbaa0(float *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float fVar2;

  float afStack_20 [4];

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fStack_10 = *param_2 - *param_1;

  fStack_c = param_2[1] - param_1[1];

  fStack_8 = param_2[2] - param_1[2];

  FUN_003bb9b0(&fStack_10);

  afStack_20[0] = fStack_10;

  afStack_20[1] = fStack_c;

  afStack_20[2] = fStack_8;

  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {

    fVar2 = afStack_20[iVar1];

    if (180.0 < fVar2) {

      afStack_20[iVar1] = -(360.0 - fVar2);

    }

  }

  *param_3 = afStack_20[0];

  param_3[1] = afStack_20[1];

  param_3[2] = afStack_20[2];

  return;

}
#define FUN_003bbaa0(...) ((void (*)(...))FUN_003bbaa0)(__VA_ARGS__)
#undef FUN_003bbb90
// FUN_003BBB90 NONMATCHING


void FUN_003bbb90(u64 param_1,u32 *param_2)



{

  u64 uVar1;

  float fVar2;

  float afStack_20 [4];

  u64 uStack_10;

  float fStack_8;

  

  uStack_10 = DAT_006a2f48;

  fStack_8 = DAT_006a2f50;

  fVar2 = (float)FUN_004c69f0(afStack_20,param_1);

  if (fVar2 == 0.0) {

    *param_2 = 0;

    param_2[1] = 0;

    param_2[2] = 0;

  }

  else {

    afStack_20[1] = 0.0;

    uVar1 = FUN_00530da0(afStack_20[2] * fStack_8 +
                         afStack_20[0] * (float)uStack_10 + 0.0 + 0.0);

    uVar1 = FUN_0052e9a0(uVar1);

    fVar2 = (float)FUN_005318a0(uVar1);

    fVar2 = fGpffff8228 * fVar2;

    if (afStack_20[0] < 0.0) {

      fVar2 = fVar2 * -1.0;

    }

    param_2[1] = fVar2;

    *param_2 = 0;

    param_2[2] = 0;

  }

  return;

}
#define FUN_003bbb90(...) ((void (*)(...))FUN_003bbb90)(__VA_ARGS__)
#undef FUN_003bbc90
// FUN_003BBC90 NONMATCHING


void FUN_003bbc90(float param_1,float *param_2,float *param_3,float *param_4,float *param_5,

                 float *param_6,float *param_7)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  fVar8 = 1.0 - param_1;

  fVar11 = fVar8 * fVar8 * fVar8;

  fVar9 = param_1 * fVar8 * fVar8 * 3.0;

  fVar10 = fVar8 * 3.0 * param_1 * param_1;

  param_1 = param_1 * param_1 * param_1;

  fVar8 = *param_3;

  fVar1 = param_3[1];

  fVar2 = param_3[2];

  fVar3 = param_3[3];

  fVar4 = *param_4;

  fVar5 = param_4[1];

  fVar6 = param_4[2];

  fVar7 = param_4[3];

  *param_5 = param_2[3] * param_1 + param_2[2] * fVar10 + param_2[1] * fVar9 + *param_2 * fVar11;

  *param_6 = fVar3 * param_1 + fVar2 * fVar10 + fVar1 * fVar9 + fVar8 * fVar11;

  *param_7 = fVar7 * param_1 + fVar6 * fVar10 + fVar5 * fVar9 + fVar4 * fVar11;

  return;

}
#define FUN_003bbc90(...) ((void (*)(...))FUN_003bbc90)(__VA_ARGS__)
#undef FUN_003bbd40
// FUN_003BBD40 NONMATCHING


void FUN_003bbd40(float param_1,char *param_2,u64 param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  u32 auStack_30 [4];

  u32 auStack_20 [4];

  u32 auStack_10 [4];

  

  cVar1 = *param_2;

  if ('\0' < cVar1) {

    iVar4 = (int)param_3;

    if (1.0 <= param_1) {

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc + (cVar1 + -1) * 0x24;

        auStack_10[iVar3] = *(u32 *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(u32 *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(u32 *)(param_2 + iVar2 + 0xc);

      }

      FUN_003bbc90(0x3f800000,auStack_10,auStack_20,auStack_30,param_3,iVar4 + 4,iVar4 + 8);

    }

    else {

      fVar5 = 1.0 / (float)(int)cVar1;

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc + (int)(param_1 / fVar5) * 0x24;

        auStack_10[iVar3] = *(u32 *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(u32 *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(u32 *)(param_2 + iVar2 + 0xc);

      }

      for (; fVar5 < param_1; param_1 = param_1 - fVar5) {

      }

      FUN_003bbc90(param_1 / fVar5,auStack_10,auStack_20,auStack_30,param_3,iVar4 + 4,iVar4 + 8);

    }

  }

  return;

}
#define FUN_003bbd40(...) ((void (*)(...))FUN_003bbd40)(__VA_ARGS__)
#undef FUN_003bbed0
// FUN_003BBED0 NONMATCHING


float FUN_003bbed0(float param_1,float param_2,u32 param_3)



{

  u32 *puVar1;

  u8 auStack_140 [4];

  u32 uStack_13c;

  u32 uStack_138;

  u32 uStack_134;

  u32 uStack_130;

  u32 uStack_12c;

  u32 uStack_128;

  u32 uStack_124;

  u32 uStack_120;

  u32 uStack_11c;

  u32 uStack_118;

  u32 uStack_114;

  u32 uStack_110;

  u8 auStack_10 [4];

  float fStack_c;

  

  if (5 < param_3) {

    FUN_0019d3f0("mt_sceneFunc.c",0x980);

  }

  if (param_1 == 0.0) {

    param_2 = 1.0;

  }

  else {

    param_2 = param_2 / param_1;

  }

  auStack_140[0] = 1;

  uStack_13c = 0;

  uStack_138 = 0;

  uStack_134 = 0;

  puVar1 = (u32 *)FUN_003b55b0(param_3);

  uStack_130 = *puVar1;

  uStack_12c = puVar1[2];

  uStack_128 = 0;

  uStack_124 = puVar1[1];

  uStack_120 = puVar1[3];

  uStack_11c = 0;

  uStack_118 = 0x3f800000;

  uStack_114 = 0x3f800000;

  uStack_110 = 0;

  FUN_003bbd40(param_2,auStack_140,auStack_10);

  return fStack_c * param_1;

}
#define FUN_003bbed0(...) ((float (*)(...))FUN_003bbed0)(__VA_ARGS__)
#undef FUN_003bbfd0
// FUN_003BBFD0 NONMATCHING


void FUN_003bbfd0(u32 param_1,u32 param_2,u64 param_3,u64 param_4,
                  u64 param_5,float *param_6,float *param_7)



{

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  FUN_003bbc90();

  FUN_003bbc90(param_2,param_3,param_4,param_5,&fStack_8,&fStack_10,&fStack_18);

  fStack_28 = fStack_8 - fStack_4;

  fStack_24 = fStack_10 - fStack_c;

  fStack_20 = fStack_18 - fStack_14;

  FUN_004c6ac0(&fStack_28);

  *param_6 = fStack_4;

  param_6[1] = fStack_c;

  param_6[2] = fStack_14;

  *param_7 = fStack_8;

  param_7[1] = fStack_10;

  param_7[2] = fStack_18;

  return;

}
#define FUN_003bbfd0(...) ((void (*)(...))FUN_003bbfd0)(__VA_ARGS__)
#undef FUN_003bc0e0
// FUN_003BC0E0 NONMATCHING


float FUN_003bc0e0(char *param_1)



{

  int iVar1;

  long lVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  u32 auStack_50 [4];

  u32 auStack_40 [4];

  u32 auStack_30 [4];

  u8 auStack_20 [16];

  u8 auStack_10 [16];

  

  fVar5 = 0.0;

  for (lVar2 = 0; lVar2 < *param_1; lVar2 = (long)((int)lVar2 + 1)) {

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      iVar1 = iVar3 * 0xc + (int)lVar2 * 0x24;

      auStack_30[iVar3] = *(u32 *)(param_1 + iVar1 + 4);

      auStack_40[iVar3] = *(u32 *)(param_1 + iVar1 + 8);

      auStack_50[iVar3] = *(u32 *)(param_1 + iVar1 + 0xc);

    }

    fVar6 = 0.0;

    for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {

      FUN_003bbfd0((float)iVar3 * DAT_007cb0b8,(float)(iVar3 + 1) * DAT_007cb0b8,
                   auStack_30,auStack_40,auStack_50,auStack_10,auStack_20);
      fVar4 = 0.0;

      fVar6 = fVar6 + fVar4;

    }

    fVar5 = fVar5 + fVar6;

  }

  return fVar5;

}
#define FUN_003bc0e0(...) ((float (*)(...))FUN_003bc0e0)(__VA_ARGS__)
#undef FUN_003bc220
// FUN_003BC220 NONMATCHING


float FUN_003bc220(char *param_1,float param_2,float param_3,float *param_4,u32 *param_5)



{

  char cVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  u32 auStack_f0 [4];

  u32 auStack_e0 [4];

  u32 auStack_d0 [6];

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  float fStack_98;

  float fStack_94;

  float fStack_90;

  u8 auStack_88 [16];

  float fStack_78;

  float fStack_74;

  float fStack_70;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_48;

  float fStack_44;

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

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  fVar8 = 0.0;

  cVar1 = *param_1;

  fVar6 = (1.0 / (float)(int)cVar1) / 20.0;

  fVar7 = 0.0;

  if (param_3 <= param_2) {

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      iVar2 = iVar3 * 0xc + (cVar1 + -1) * 0x24;

      auStack_d0[iVar3] = *(u32 *)(param_1 + iVar2 + 4);
      auStack_e0[iVar3] = *(u32 *)(param_1 + iVar2 + 8);
      auStack_f0[iVar3] = *(u32 *)(param_1 + iVar2 + 0xc);

    }

    FUN_003bbc90(DAT_007caea4,auStack_d0,auStack_e0,auStack_f0,&fStack_4,&fStack_c,&fStack_14);

    FUN_003bbc90(0x3f800000,auStack_d0,auStack_e0,auStack_f0,&fStack_8,&fStack_10,&fStack_18);

    fStack_98 = fStack_8 - fStack_4;

    fStack_94 = fStack_10 - fStack_c;

    fStack_90 = fStack_18 - fStack_14;

    FUN_004c6ac0(&fStack_98);

    fStack_58 = fStack_8;

    fStack_54 = fStack_10;

    fStack_50 = fStack_18;

    *param_4 = fStack_8;

    param_4[1] = fStack_10;

    param_4[2] = fStack_18;

    fStack_68 = fStack_8 - fStack_4;

    fStack_64 = fStack_10 - fStack_c;

    fStack_60 = fStack_18 - fStack_14;

    FUN_004c69f0(auStack_88,&fStack_68);

    FUN_003bbb90(auStack_88,param_5);

    fVar6 = 1.0;

  }

  else {

    for (lVar4 = 0; lVar4 < *param_1; lVar4 = (long)((int)lVar4 + 1)) {

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 + (int)lVar4 * 3;

        auStack_d0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 4);
        auStack_e0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 8);
        auStack_f0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 0xc);

      }

      for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {

        fVar9 = (float)iVar3 * DAT_007cad5c;

        FUN_003bbc90(fVar9,auStack_d0,auStack_e0,auStack_f0,&fStack_1c,&fStack_24,&fStack_2c);

        FUN_003bbc90((float)(iVar3 + 1) * DAT_007cad5c,auStack_d0,auStack_e0,auStack_f0,&fStack_20,

                     &fStack_28,&fStack_30);

        fStack_a8 = fStack_20 - fStack_1c;

        fStack_a4 = fStack_28 - fStack_24;

        fStack_a0 = fStack_30 - fStack_2c;

        fVar5 = (float)FUN_004c6ac0(&fStack_a8);

        fStack_58 = fStack_20;

        fStack_54 = fStack_28;

        fStack_50 = fStack_30;

        fVar8 = fVar8 + fVar5;

        if (param_2 <= fVar8) {
          fVar8 = 1.0 - (fVar8 - param_2) / fVar5;

          fStack_68 = fStack_20 - fStack_1c;

          fStack_64 = fStack_28 - fStack_24;

          fStack_60 = fStack_30 - fStack_2c;

          *param_4 = fStack_68 * fVar8 + fStack_1c + 0.0;

          param_4[1] = fStack_64 * fVar8 + fStack_24 + 0.0;

          param_4[2] = fStack_60 * fVar8 + fStack_2c + 0.0;

          fVar9 = fVar9 + fVar6 * fVar8;

          FUN_003bbc90(fVar9,auStack_d0,auStack_e0,auStack_f0,&fStack_34,&fStack_3c,&fStack_44);

          FUN_003bbc90(fVar9 - DAT_007caf1c,auStack_d0,auStack_e0,auStack_f0,&fStack_38,&fStack_40,

                       &fStack_48);

          fStack_b8 = fStack_38 - fStack_34;

          fStack_b4 = fStack_40 - fStack_3c;

          fStack_b0 = fStack_48 - fStack_44;

          FUN_004c6ac0(&fStack_b8);

          fStack_78 = fStack_34 - fStack_38;

          fStack_74 = fStack_3c - fStack_40;

          fStack_70 = fStack_44 - fStack_48;

          FUN_004c69f0(auStack_88,&fStack_78);

          FUN_003bbb90(auStack_88,param_5);

          return fVar7 + fVar6 * fVar8;

        }

        fVar7 = fVar7 + fVar6;

      }

    }

    fVar6 = 0.0;

  }

  return fVar6;

}
#define FUN_003bc220(...) ((float (*)(...))FUN_003bc220)(__VA_ARGS__)
#undef FUN_003bc730
// FUN_003BC730 NONMATCHING


float FUN_003bc730(char *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  float fVar5;

  float fVar6;

  u32 auStack_60 [4];

  u32 auStack_50 [4];

  u32 auStack_40 [6];

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  fVar6 = 0.0;

  iVar3 = 0;

  lVar4 = 0;

  while( 1 ) {

    if (*param_1 <= lVar4) {

      return 0.0;

    }

    if (iVar3 == param_2) break;

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      iVar1 = iVar2 + (int)lVar4 * 3;

      auStack_40[iVar2] = *(u32 *)(param_1 + iVar1 * 0xc + 4);

      auStack_50[iVar2] = *(u32 *)(param_1 + iVar1 * 0xc + 8);

      auStack_60[iVar2] = *(u32 *)(param_1 + iVar1 * 0xc + 0xc);

    }

    for (iVar2 = 0; iVar2 < 0x14; iVar2 = iVar2 + 1) {

      FUN_003bbc90((float)iVar2 * DAT_007cb0b8,auStack_40,auStack_50,auStack_60,&fStack_4,&fStack_c,

                   &fStack_14);

      FUN_003bbc90((float)(iVar2 + 1) * DAT_007cb0b8,auStack_40,auStack_50,auStack_60,&fStack_8,

                   &fStack_10,&fStack_18);

      fStack_28 = fStack_8 - fStack_4;

      fStack_24 = fStack_10 - fStack_c;

      fStack_20 = fStack_18 - fStack_14;

      fVar5 = (float)FUN_004c6ac0(&fStack_28);

      fVar6 = fVar6 + fVar5;

    }

    iVar3 = iVar3 + 1;

    lVar4 = (long)((int)lVar4 + 1);

  }

  return fVar6;

}
#define FUN_003bc730(...) ((float (*)(...))FUN_003bc730)(__VA_ARGS__)
#undef FUN_003bc8f0
// FUN_003BC8F0


int FUN_003bc8f0(char *param_1)



{

  return *param_1 + -1;

}
#define FUN_003bc8f0(...) ((int (*)(...))FUN_003bc8f0)(__VA_ARGS__)
#pragma optimization_level 1
#undef FUN_003bc900
// FUN_003BC900


u8 FUN_003bc900(float *param_1)



{

  if (*(u16 *)&DAT_007ce658 == 0) {
    return 0;
  }
  param_1[0] = *(volatile float *)(uintptr_t)0x0095aff0;
  param_1[1] = *(volatile float *)(uintptr_t)0x0095aff4;
  return 1;

}
#define FUN_003bc900(...) ((u8 (*)(...))FUN_003bc900)(__VA_ARGS__)
#pragma optimization_level 2
#undef FUN_003bc940
// FUN_003BC940 NONMATCHING








void FUN_003bc940(void)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float afStack_10 [4];

  

  afStack_10[0] = DAT_007cd560;

  afStack_10[1] = (float)DAT_007cd564;

  if (DAT_007ce658 == 0) {

    DAT_0095aff0 = 0;

    DAT_0095aff4 = 0;

    DAT_0095aff8 = 0;

    DAT_0095affc = 0;

  }

  else if (DAT_007ce65c == 0) {

    DAT_007ce658 = 0;

  }

  else {

    afStack_10[2] = DAT_007cada0 * (float)DAT_007ce660;

    afStack_10[3] = DAT_007cada0 * (float)DAT_007ce664;

    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {

      fVar6 = afStack_10[iVar1 + 2];

      if (fVar6 != 0.0) {

        fVar3 = (float)FUN_00358030(0);

        fVar4 = afStack_10[iVar1 + 2];

        fVar5 = fVar4 * 0.5 + fVar4 * fVar3 * 0.5;

        pfVar2 = (float *)(&DAT_0095aff0 + iVar1);

        fVar3 = *pfVar2;

        if (fVar4 * afStack_10[iVar1] <= ABS(fVar3)) {

          if (fVar3 <= 0.0) {

            *pfVar2 = fVar3 + fVar5;

          }

          else {

            *pfVar2 = fVar3 - fVar5;

          }

        }

        else {

          fVar3 = (float)FUN_00358030(0);

          *pfVar2 = fVar5 * (fVar3 - 0.5) * 2.0 + *pfVar2 + 0.0;

        }

        if (*pfVar2 < -fVar6) {

          *pfVar2 = -fVar6;

        }

        if (fVar6 < *pfVar2) {

          *pfVar2 = fVar6;

        }

      }

    }

    if (0 < DAT_007ce65c) {

      DAT_007ce660 = DAT_007ce660 - (short)((int)(u32)DAT_007ce660 / (DAT_007ce65c + 5));

      DAT_007ce664 = DAT_007ce664 - (short)((int)(u32)DAT_007ce664 / (DAT_007ce65c + 5));

      DAT_007ce65c = DAT_007ce65c + -1;

    }

  }

  return;

}
#define FUN_003bc940(...) ((void (*)(...))FUN_003bc940)(__VA_ARGS__)
#undef FUN_003bcbf0
// FUN_003BCBF0


void FUN_003bcbf0(int param_1,int param_2)



{
  if (param_2 == 0) {
    *(u16 *)&DAT_007ce658 = 0;
  }
  else {
    *(u16 *)&DAT_007ce658 = 1;
    if (param_1 == 0) {
      *(short *)&DAT_007ce65c = -1;
    }
    else {
      *(u16 *)&DAT_007ce65c = (short)param_1;
    }
    *(u16 *)&DAT_007ce664 = param_2 * 10;
    *(u16 *)&DAT_007ce660 = (*(u16 *)&DAT_007ce664 << 2) / 10;
    FUN_003500a0(param_1,(short)param_2);
  }
  return;

}
#define FUN_003bcbf0(...) ((void (*)(...))FUN_003bcbf0)(__VA_ARGS__)
#undef FUN_003bcc80
// FUN_003BCC80


void FUN_003bcc80(void)



{

  *(u16 *)&DAT_007ce658 = 0;

  FUN_003500e0();

  return;

}
#define FUN_003bcc80(...) ((void (*)(...))FUN_003bcc80)(__VA_ARGS__)
#undef FUN_003bcda0
// FUN_003BCDA0 NONMATCHING


int FUN_003bcda0(int *param_1,int *param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  u8 auStack_b0 [48];

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  u8 auStack_70 [48];

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  iVar1 = FUN_00198590();

  iVar1 = FUN_004cb2f0(*(u32 *)(iVar1 + 4));

  fStack_30 = *(float *)(iVar1 + 0x30);

  fStack_2c = *(float *)(iVar1 + 0x34);

  fStack_28 = *(float *)(iVar1 + 0x38);

  iVar1 = *param_2;

  FUN_0034ffc0(*(u32 *)(*param_1 + 0x104),auStack_70);

  FUN_0034ffc0(*(u32 *)(iVar1 + 0x104),auStack_b0);

  fStack_10 = fStack_40 - fStack_30;

  fStack_c = fStack_3c - fStack_2c;

  fStack_8 = fStack_38 - fStack_28;

  fStack_20 = fStack_80 - fStack_30;

  fStack_1c = fStack_7c - fStack_2c;

  fStack_18 = fStack_78 - fStack_28;

  fVar2 = (float)FUN_004c6ac0(&fStack_10);

  fVar3 = (float)FUN_004c6ac0(&fStack_20);

  return (int)(fVar2 - fVar3);

}
#define FUN_003bcda0(...) ((int (*)(...))FUN_003bcda0)(__VA_ARGS__)
#undef FUN_003bceb0
// FUN_003BCEB0 NONMATCHING


void FUN_003bceb0(int param_1)



{

  u64 uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  for (iVar2 = param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xf8)) {

    if ((((*(u32 *)(iVar2 + 0x28) & 2) != 0) && (*(int *)(iVar2 + 0x104) != 0)) &&

       (*(char *)(iVar2 + 0x100) == '\0')) {

      iVar3 = iVar3 + 1;

    }

  }

  uVar1 = (*DAT_00960178)(iVar3 << 2,0x40000);

  iVar2 = 0;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0xf8)) {

    if ((((*(u32 *)(param_1 + 0x28) & 2) != 0) && (*(int *)(param_1 + 0x104) != 0)) &&

       (*(char *)(param_1 + 0x100) == '\0')) {

      *(int *)((int)uVar1 + iVar2 * 4) = param_1;

      iVar2 = iVar2 + 1;

    }

  }

  FUN_005225f8(uVar1,iVar3,4,0x3bcda0);

  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {

    FUN_0034fd70((Model *)*(u32 *)(*(int *)((int)uVar1 + iVar2 * 4) + 0x104),3);

  }

  (*DAT_0096017c)(uVar1);

  return;

}
#define FUN_003bceb0(...) ((void (*)(...))FUN_003bceb0)(__VA_ARGS__)
#undef FUN_003bd130
// FUN_003BD130


void FUN_003bd130(void)



{

  void *pVar1;

  void **ppVar2;

  int iVar2;

  

  for (iVar2 = 0; iVar2 < 0x19; iVar2 = iVar2 + 1) {

    if (PTR_s_icon_ICON1_EPL_006a3130[iVar2] != (u8 *)0x0) {

      ppVar2 = (void **)(DAT_0095b000_abs + iVar2 * 4);
      asm volatile("" : "+m"(*ppVar2));

      pVar1 = FUN_00100d80_typed_scene((const char *)PTR_s_icon_ICON1_EPL_006a3130[iVar2],0);

      *ppVar2 = pVar1;

      FUN_001023a0(pVar1);

    }

  }

  return;

}
#define FUN_003bd130(...) ((void (*)(...))FUN_003bd130)(__VA_ARGS__)
#undef FUN_003bd1c0
// FUN_003BD1C0


u32 FUN_003bd1c0(u32 param_1)
{
  u8 auStack_4[4];
  u8 **ppuVar1;

  if (0x19 < param_1) {
    return 0;
  }

  ppuVar1 = (u8 **)PTR_s_icon_ICON1_EPL_006a3130 + param_1;
  if (*ppuVar1 == (u8 *)0x0) {
    return 0;
  }

  return FUN_001021c0(*ppuVar1, auStack_4);
}
#define FUN_003bd1c0(...) ((u64 (*)(...))FUN_003bd1c0)(__VA_ARGS__)
#undef FUN_003bd230
// FUN_003BD230


u32 FUN_003bd230(void)



{

  u8 uVar1;

  

  FUN_0035ed20(0);

  uVar1 = FUN_0035ed20(1);

  (FUN_003bb010)(0x400,uVar1);

  return 1;

}
#define FUN_003bd230(...) ((u32 (*)(...))FUN_003bd230)(__VA_ARGS__)
#undef FUN_003bd280
// FUN_003BD280 NONMATCHING


void FUN_003bd280(void)



{

  u32 uVar1;

  int iVar2;

  int *piVar3;

  u8 auStack_4 [4];

  

  uVar1 = FUN_00100d80(PTR_s_event_comuPack_pak_007cd568,1);

  DAT_007ce668 = (u32)uVar1;

  FUN_001023a0(uVar1);

  DAT_0095b070 = (short *)FUN_001021c0(PTR_s_event_comuTable_bin_007cd56c,auStack_4);

  DAT_0095b074 = FUN_001021c0(PTR_s_event_SiteibiEvent_bf_007cd570,auStack_4);

  if (*DAT_0095b070 == 1) {

    piVar3 = (int *)(DAT_0095b070 + 2);

    for (iVar2 = 0; iVar2 < 0x90; iVar2 = iVar2 + 1) {

      if (*piVar3 == 0) {

        *(u32 *)(&DAT_0095b078 + iVar2 * 4) = 0;

      }

      else {

        *(int *)(&DAT_0095b078 + iVar2 * 4) = (int)DAT_0095b070 + *piVar3;

      }

      *(int *)(&DAT_0095b2b4 + iVar2 * 4) = piVar3[1];

      piVar3 = piVar3 + 2;

    }

    FUN_005225a8(0x6a3250,*DAT_0095b070,(char)DAT_0095b070[1]);

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b4f0 + iVar2 * 4) = *(u32 *)(&DAT_0095b078 + iVar2 * 4);

    }

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b568 + iVar2 * 4) = *(u32 *)(&DAT_0095b0f8 + iVar2 * 4);

    }

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b5e0 + iVar2 * 4) = *(u32 *)(&DAT_0095b178 + iVar2 * 4);

    }

    if (DAT_0095b1f8 != 0) {

      DAT_0095b658 = DAT_0095b1f8;

      DAT_0095b65c = DAT_0095b434 / 0x18;

    }

    if (DAT_0095b220 != 0) {

      DAT_0095b660 = DAT_0095b220;

      DAT_0095b664 = DAT_0095b45c >> 2;

    }

    if (DAT_0095b224 != 0) {

      DAT_0095b668 = DAT_0095b224;

      DAT_0095b66c = DAT_0095b460 / 6;

    }

    DAT_0095b670 = DAT_0095b238;

    DAT_0095b674 = DAT_0095b474 / 10;

    DAT_0095b678 = DAT_0095b204;

    DAT_0095b67c = DAT_0095b440 / 3;

    DAT_0095b680 = DAT_0095b208;

    DAT_0095b684 = DAT_0095b444 / 3;

    DAT_0095b688 = DAT_0095b20c;

    DAT_0095b68c = DAT_0095b448 / 5;

    DAT_0095b690 = DAT_0095b210;

    DAT_0095b694 = DAT_0095b44c / 5;

    DAT_0095b698 = DAT_0095b218;

    DAT_0095b69c = DAT_0095b454 / 5;

    DAT_0095b6a0 = DAT_0095b21c;

    DAT_0095b6a4 = DAT_0095b458 / 3;

    DAT_0095b6a8 = DAT_0095b240;

    DAT_0095b6ac = DAT_0095b47c / 0x18;

    DAT_0095b6b0 = DAT_0095b244;

    DAT_0095b6b4 = DAT_0095b480 >> 1;

    DAT_0095b6b8 = DAT_0095b248;

    DAT_0095b6bc = DAT_0095b484 >> 4;

    DAT_0095b6c0 = DAT_0095b2a4;

    DAT_0095b6c4 = DAT_0095b4e0 / 3;

    DAT_0095b6c8 = DAT_0095b24c;

    DAT_0095b6cc = DAT_0095b488 >> 1;

    DAT_0095b6f8 = DAT_0095b254;

    DAT_0095b6fc = DAT_0095b274;

    DAT_0095b700 = DAT_0095b270;

    DAT_0095b704 = DAT_0095b258;

    DAT_0095b708 = DAT_0095b25c;

    DAT_0095b70c = DAT_0095b260;

    DAT_0095b710 = DAT_0095b264;

    DAT_0095b714 = DAT_0095b4a0 / 0x1a;

    DAT_0095b6d8 = DAT_0095b278;

    DAT_0095b6dc = DAT_0095b4b4 / 5;

    DAT_0095b6d0 = DAT_0095b26c;

    DAT_0095b6d4 = DAT_0095b4a8 / 0xc;

    DAT_0095b718 = DAT_0095b268;

    DAT_0095b6e0 = DAT_0095b27c;

    DAT_0095b6e4 = DAT_0095b284;

    DAT_0095b6e8 = DAT_0095b4c0 / 0xc;

    DAT_0095b6ec = DAT_0095b288;

    DAT_0095b6f4 = DAT_0095b28c;

    DAT_0095b6f0 = DAT_0095b290;

    DAT_0095b71c = DAT_0095b294;

    DAT_0095b720 = DAT_0095b4d0 / 6;

    DAT_0095b724 = DAT_0095b298;

    DAT_0095b728 = DAT_0095b4d4 >> 3;

  }

  else {

    FUN_005225a8(0x6a3200);

    DAT_0095b070 = (short *)0x0;

  }

  return;

}
#define FUN_003bd280(...) ((void (*)(...))FUN_003bd280)(__VA_ARGS__)
#undef FUN_003bd870
// FUN_003BD870


short ** FUN_003bd870(void)
{
  return (short **)DAT_0095b070_ptr;
}
#define FUN_003bd870(...) ((short ** (*)(...))FUN_003bd870)(__VA_ARGS__)
#undef FUN_003bd880
// FUN_003BD880


u32 * FUN_003bd880(void)
{
  return (u32 *)DAT_0095b658_ptr;
}
#define FUN_003bd880(...) ((u32 * (*)(...))FUN_003bd880)(__VA_ARGS__)
#undef FUN_003bd890
// FUN_003BD890


u32 * FUN_003bd890(void)
{
  return (u32 *)DAT_0095b660_ptr;
}
#define FUN_003bd890(...) ((u32 * (*)(...))FUN_003bd890)(__VA_ARGS__)
#undef FUN_003bd8a0
// FUN_003BD8A0


u32 * FUN_003bd8a0(void)
{
  return (u32 *)DAT_0095b668_ptr;
}
#define FUN_003bd8a0(...) ((u32 * (*)(...))FUN_003bd8a0)(__VA_ARGS__)
#undef FUN_003bd8b0
// FUN_003BD8B0 NONMATCHING


u32 FUN_003bd8b0(u32 param_1,u32 param_2,u32 param_3)



{

  u32 uVar1;

  u16 *puVar2;

  int iVar3;

  

  iVar3 = 0;

  do {

    if (DAT_0095b720 <= iVar3) {

      if (((long)param_1 < 0) || (499 < (long)param_1)) {

        if (((long)param_1 < 0x3de) || (999 < (long)param_1)) {

          uVar1 = 0xffffffff;

        }

        else {

          uVar1 = 0;

        }

      }

      else {

        uVar1 = 0;

      }

      return uVar1;

    }

    puVar2 = (u16 *)(DAT_0095b71c + iVar3 * 6);

    if (*(u8 *)((int)puVar2 + 3) == 0xff) {

      if ((param_1 == *puVar2) && (param_2 == (u8)puVar2[1])) {

        return (u32)(u8)puVar2[2];

      }

    }

    else if (((param_1 == *puVar2) && (param_2 == (u8)puVar2[1])) &&

            (param_3 == *(u8 *)((int)puVar2 + 3))) {

      return (u32)(u8)puVar2[2];

    }

    iVar3 = iVar3 + 1;

  } while( 1 );

}
#define FUN_003bd8b0(...) ((u32 (*)(...))FUN_003bd8b0)(__VA_ARGS__)
#undef FUN_003bd9a0
// FUN_003BD9A0 NONMATCHING


u16 FUN_003bd9a0(u32 param_1,u32 param_2)



{

  long lVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  while( 1 ) {

    if (DAT_0095b728 <= iVar2) {

      return 0;

    }

    iVar3 = iVar2 * 8;

    if ((param_1 == *(u16 *)(DAT_0095b724 + iVar3)) &&

       (param_2 == (u8)((u16 *)(DAT_0095b724 + iVar3))[1])) break;

    iVar2 = iVar2 + 1;

  }

  lVar1 = FUN_003951d0(0xa88);

  if (lVar1 == 1) {

    return *(u16 *)(iVar3 + DAT_0095b724 + 4);

  }

  return *(u16 *)(iVar3 + DAT_0095b724 + 6);

}
#define FUN_003bd9a0(...) ((u16 (*)(...))FUN_003bd9a0)(__VA_ARGS__)
#undef FUN_003bda60
// FUN_003BDA60 NONMATCHING


u32 FUN_003bda60(u32 param_1,u32 param_2,u32 param_3,u32 param_4)



{

  int iVar1;

  long lVar2;

  u8 *pbVar3;

  int iVar4;

  

  iVar1 = DAT_0095b674;

  iVar4 = 0;

  do {

    if (iVar1 <= iVar4) {

      return 0xffffffff;

    }

    pbVar3 = (u8 *)(DAT_0095b670 + iVar4 * 10);

    if ((((param_1 == *pbVar3) && (param_2 == pbVar3[1])) && (param_3 == *(u16 *)(pbVar3 + 2)))

       && (param_4 == pbVar3[4])) {

      if (*(short *)(pbVar3 + 8) == 0) {

        return (u32)*(u16 *)(pbVar3 + 6);

      }

      lVar2 = FUN_003951d0();

      if (lVar2 != 1) {

        return (u32)*(u16 *)(iVar4 * 10 + DAT_0095b670 + 6);

      }

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

}
#define FUN_003bda60(...) ((u32 (*)(...))FUN_003bda60)(__VA_ARGS__)
#undef FUN_003bdb80
// FUN_003BDB80


float FUN_003bdb80(void)



{

  return **(float **)0x0095b6f4;

}
#define FUN_003bdb80(...) ((float (*)(...))FUN_003bdb80)(__VA_ARGS__)
#undef FUN_003bdba0
// FUN_003BDBA0


u32 FUN_003bdba0(void)



{

  return *(u32 *)0x0095b6f0;

}
#define FUN_003bdba0(...) ((u32 (*)(...))FUN_003bdba0)(__VA_ARGS__)
#undef FUN_003bdbb0
// FUN_003BDBB0


u16 FUN_003bdbb0(void)



{

  return **(u16 **)0x0095b29c;

}
#define FUN_003bdbb0(...) ((u16 (*)(...))FUN_003bdbb0)(__VA_ARGS__)
