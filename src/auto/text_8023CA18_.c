#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern char lbl_803415CC[0xC0];
extern s32 lbl_8055BB68;
extern char lbl_803415E8[];
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8023CA18(void) {
    if (lbl_8055BB68 == 0) {
        fn_80214A9C(0x1F);
    }
    fn_80214A9C(1);
}

void fn_8023CA50(void) {}

extern char lbl_803414D0[];
extern u8 lbl_8055F160;
extern f32 lbl_8055F164;
extern f32 lbl_8055F168;
extern f32 lbl_8055F16C;
extern f32 lbl_8055F170;
extern f32 lbl_8055F174;
extern s32 lbl_8055F178;
extern s32 lbl_8055F17C;
extern s32 lbl_8055BB70;
extern f32 lbl_80563738;
extern void fn_801333E8(s32, s32 *, u8 *);
extern void fn_801331C4(s32, void *, f32 *);
extern void fn_801332D0(s32, void *, s32 *);
extern void fn_80209030(f32);
extern void fn_80209090(s32);
#pragma push
#pragma scheduling invalid_target
void fn_8023CA54(void) {
    s32 zero = 0;
    char *base = (char *)&lbl_803414D0;
    lbl_8055F160 = zero;
    fn_801333E8(4, (s32 *)&base[0], &lbl_8055F160);
    lbl_8055F164 = lbl_80563738;
    fn_801331C4(4, &base[0x10], &lbl_8055F164);
    lbl_8055F168 = lbl_80563738;
    fn_801331C4(4, &base[0x20], &lbl_8055F168);
    lbl_8055F16C = lbl_80563738;
    fn_801331C4(4, &base[0x30], &lbl_8055F16C);
    fn_80209030(lbl_8055F16C);
    lbl_8055F17C = zero;
    fn_801332D0(4, &lbl_8055BB70, &lbl_8055F17C);
    fn_80209090(lbl_8055F17C);
    lbl_8055F170 = lbl_80563738;
    fn_801331C4(4, &base[0x40], &lbl_8055F170);
    lbl_8055F174 = lbl_80563738;
    fn_801331C4(4, &base[0x4C], &lbl_8055F174);
    lbl_8055F178 = 1;
    fn_801332D0(4, &base[0x5C], &lbl_8055F178);
}
#pragma pop
s32 fn_8023CB54(void) {
    fn_801330E8(4);
    fn_8023CA54();
    return 0;
}

s32 fn_8023CB80(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

extern s32 lbl_804987A0[];
extern s32 lbl_802FA090[];
extern f32 lbl_8056373C;
extern f32 lbl_80563740;
extern s32 lbl_8055BB78;
extern s32 lbl_8055BB80;
extern s32 lbl_8055BB88;
extern s32 lbl_8055BB90;
extern s32 lbl_8055BAB8;
extern s32 lbl_8055BABC;
extern s32 lbl_8055BAC0;
extern s32 fn_80208D70(void);
extern void fn_8022D228(void *, s32, s32);
extern void fn_8022D350(void *, void *, s32);
extern void fn_8022D2BC(void *, s32);
extern void fn_8013323C(s32, void *, f32);
extern void fn_80133460(s32, void *, u8);
extern void fn_80133348(s32, void *, s32);
extern void fn_80236914(void);
extern void fn_8023CA54(void);
extern void fn_8023CBA4(void);
struct A48Obj { s32 a48[5]; s32 a5c; s32 pad[4]; s32 a70[10]; s32 a98[64]; };
struct Frame8023 { f32 fl[10]; s32 result; s32 argStruct[5]; struct A48Obj obj; s32 big[90]; };
extern s32 lbl_8055B860;
extern s32 fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
void fn_8023CBA4(void) {
    s32 data[20];
    s32 *v = lbl_802FA090;
    data[6] = 6;
    data[1] = (s32)&data[5];
    data[5] = (s32)&lbl_8055B860;
    data[0] = v[0];
    data[7] = 0;
    data[8] = -1;
    data[9] = 0x1B;
    data[11] = 6;
    data[10] = (s32)&lbl_8055B860;
    data[12] = 0;
    data[13] = -2;
    data[14] = 0xD;
    data[2] = v[2];
    data[3] = v[3];
    data[4] = v[4];
    data[15] = lbl_804987A0[0];
    data[16] = lbl_804987A0[1];
    data[17] = lbl_804987A0[2];
    data[18] = lbl_804987A0[3];
    data[19] = lbl_804987A0[4];
    fn_802146BC(data, -999, -999, 1, v[4], v[3], v[2], v[0]);
}

void fn_8023CC84(char *arg0) {
    struct Frame8023 fr;
    s32 i;
    char *base = lbl_803414D0;
    char *p7c = base + 0x7C;
    char *p90 = base + 0x90;
    fn_8023CA54();
    if (lbl_8055F160 == 0) {
        lbl_8055F164 = lbl_8056373C;
    }
    fr.result = fn_80208D70();
    fr.obj.a5c = (s32)lbl_803415E8;
    fr.obj.a70[3] = fr.result;
    fr.obj.a70[1] = (s32)&lbl_8055F16C;
    fr.obj.a70[0] = 0;
    fr.obj.a70[2] = (s32)&lbl_8055F17C;
    fr.obj.a70[4] = (s32)&lbl_8055F164;
    fr.obj.a70[5] = (s32)fr.obj.a98;
    fr.obj.a70[6] = (s32)&lbl_8055F168;
    fr.obj.a70[7] = (s32)&lbl_8055F170;
    fr.obj.a70[8] = (s32)&lbl_8055F174;
    fr.obj.a70[9] = 0;
    fn_8022D228(fr.obj.a48, 0x11, 0x20);
    i = 0;
    do {
        fn_8022D350(fr.obj.a48, &lbl_8055BB78, 0);
        i++;
    } while (i < 0x11);
    fr.fl[0] = lbl_80563738;
    fr.fl[1] = lbl_8056373C;
    fr.fl[2] = lbl_80563738;
    fr.fl[3] = lbl_8056373C;
    fr.fl[4] = lbl_80563738;
    fr.fl[5] = lbl_8056373C;
    fr.fl[6] = lbl_80563738;
    fr.fl[7] = lbl_8056373C;
    fr.fl[8] = lbl_80563738;
    fr.fl[9] = lbl_8056373C;
    fr.big[0] = lbl_8055BAC0;
    fr.big[1] = 8;
    fr.big[2] = (s32)fn_8023CA18;
    fr.big[3] = 0;
    fr.big[4] = 0;
    fr.big[5] = 0;
    fr.big[6] = 5;
    fr.big[7] = (s32)fr.obj.a48;
    fr.big[8] = 0;
    fr.big[9] = 0;
    fr.big[10] = lbl_8055BB80;
    fr.big[11] = 0;
    fr.big[12] = (s32)fn_8023CB54;
    fr.big[13] = 0;
    fr.big[14] = 0;
    fr.big[15] = (s32)(base + 0x4C);
    fr.big[16] = 9;
    fr.big[17] = (s32)&lbl_8055F174;
    fr.big[18] = *(s32 *)&fr.fl[9];
    fr.big[19] = *(s32 *)&fr.fl[8];
    fr.big[20] = (s32)(base + 0xB8);
    fr.big[21] = 9;
    fr.big[22] = (s32)&lbl_8055F16C;
    fr.big[23] = *(s32 *)&fr.fl[7];
    fr.big[24] = *(s32 *)&fr.fl[6];
    fr.big[25] = (s32)(base + 0xC4);
    fr.big[26] = 9;
    fr.big[27] = (s32)&lbl_8055F168;
    fr.big[28] = *(s32 *)&fr.fl[5];
    fr.big[29] = *(s32 *)&fr.fl[4];
    fr.big[30] = (s32)(base + 0x10);
    fr.big[31] = 9;
    fr.big[32] = (s32)&lbl_8055F164;
    fr.big[33] = *(s32 *)&fr.fl[3];
    fr.big[34] = *(s32 *)&fr.fl[2];
    fr.big[35] = (s32)(base + 0x40);
    fr.big[36] = 9;
    fr.big[37] = (s32)&lbl_8055F170;
    fr.big[38] = *(s32 *)&fr.fl[1];
    fr.big[39] = *(s32 *)&fr.fl[0];
    fr.big[40] = lbl_8055BB88;
    fr.big[41] = 0;
    fr.big[42] = 0;
    fr.big[43] = -1;
    fr.big[44] = 0;
    fr.big[45] = lbl_8055BB70;
    fr.big[46] = 7;
    fr.big[47] = lbl_8055F17C;
    fr.big[48] = (s32)p7c;
    fr.big[49] = 0;
    fr.big[50] = (s32)(base + 0xD8);
    fr.big[51] = 7;
    fr.big[52] = lbl_8055F178;
    fr.big[53] = (s32)p90;
    fr.big[54] = 0;
    fr.big[55] = lbl_8055BB90;
    fr.big[56] = 2;
    fr.big[57] = (s32)&fr.result;
    fr.big[58] = 0;
    fr.big[59] = 0;
    fr.big[60] = (s32)(base + 0xE4);
    fr.big[61] = 3;
    fr.big[62] = (s32)fr.obj.a98;
    fr.big[63] = 0x100;
    fr.big[64] = 0;
    fr.big[65] = (s32)(base + 0xF0);
    fr.big[66] = 0xA;
    fr.big[67] = (s32)fr.obj.a48;
    fr.big[68] = 0;
    fr.big[69] = 0;
    fr.big[70] = lbl_8055B860;
    fr.big[71] = 6;
    fr.big[72] = (s32)fn_8023CB80;
    fr.big[73] = -1;
    fr.big[74] = 0x1B;
    fr.big[75] = lbl_8055BABC;
    fr.big[76] = 8;
    fr.big[77] = (s32)fn_8023CA50;
    fr.big[78] = 1;
    fr.big[79] = 0;
    fr.big[80] = lbl_8055BAB8;
    fr.big[81] = 8;
    fr.big[82] = (s32)fn_80236914;
    fr.big[83] = 2;
    fr.big[84] = 0;
    fr.big[85] = lbl_804987A0[0];
    fr.big[86] = lbl_804987A0[1];
    fr.big[87] = lbl_804987A0[2];
    fr.big[88] = lbl_804987A0[3];
    fr.big[89] = lbl_804987A0[4];
    fr.argStruct[0] = (s32)arg0;
    fr.argStruct[1] = (s32)fr.big;
    fr.argStruct[2] = 0;
    fr.argStruct[3] = 0;
    fr.argStruct[4] = 0;
    if (fn_802146BC(fr.argStruct, -999, -999, 1, 0, lbl_804987A0[4], 8, 0x100) == -2) {
        fn_8023CBA4();
    }
    lbl_8055F160 = (lbl_8055F164 == lbl_80563740) ? 1 : 0;
    fn_8013323C(4, base + 0x10, lbl_8055F164);
    fn_80133460(4, base, lbl_8055F160);
    fn_8013323C(4, base + 0x20, lbl_8055F168);
    fn_8013323C(4, base + 0x40, lbl_8055F170);
    fn_8013323C(4, base + 0x4C, lbl_8055F174);
    fn_80133348(4, base + 0x5C, lbl_8055F178);
    fn_8022D2BC(fr.obj.a48, -1);
    fr.obj.a5c = (s32)lbl_803415E8;
    if (fr.obj.a70[9] != 0) {
        fr.obj.a70[9] = 0;
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80128668(void *);
extern "C" void *fn_8023D134(void *arg0, s32 arg1) {
    struct VTable_8023D134 {
        virtual void destroy(s32);
    };
    if (arg0 != NULL) {
        void *prev = *(void **)((u8 *)arg0 + 0x38);
        *(void **)arg0 = (void *)lbl_803415E8;
        if (prev != NULL) {
            if (prev != NULL)
                ((VTable_8023D134 *)prev)->destroy(1);
            *(void **)((u8 *)arg0 + 0x38) = NULL;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
#pragma cplusplus off
void fn_8023D1C0(void) {
    lbl_8055BB68 = 0;
    fn_8023CC84(lbl_803415CC);
    lbl_8055BB68 = 2;
}

void fn_8023D1F8(void) {}

extern void fn_80221EA0(void *, s32, s32, s32);
extern s32 fn_80208D3C(void);
extern void *fn_80208D4C(s32);
extern char *strcpy(char *, const char *);
extern u8 lbl_8055BB98;
/* Refreshes this object's cached field pointers and copies the selected item's name (or "N/A") into its name buffer. */
void fn_8023D1FC(void *obj) {
    s32 itemIndex;
    void *item;
    fn_80221EA0(obj, 2, *(s32 *)((u8 *)obj + 0x24), 4);
    fn_80221EA0(obj, 0, *(s32 *)((u8 *)obj + 0x18), 4);
    fn_80221EA0(obj, 1, *(s32 *)((u8 *)obj + 0x20), 4);
    fn_80221EA0(obj, 3, *(s32 *)((u8 *)obj + 0x1c), 4);
    fn_80221EA0(obj, 4, *(s32 *)((u8 *)obj + 0x2c), 4);
    fn_80221EA0(obj, 5, *(s32 *)((u8 *)obj + 0x30), 4);
    fn_80221EA0(obj, 6, *(s32 *)((u8 *)obj + 0x34), 4);
    itemIndex = **(s32 **)((u8 *)obj + 0x24);
    if (itemIndex >= 0 && itemIndex < fn_80208D3C()) {
        item = fn_80208D4C(itemIndex);
#pragma cplusplus on
        struct ItemView {
            virtual void unused();
            virtual const char* getName();
        };
        strcpy(*(char **)((u8 *)obj + 0x28), ((ItemView*)item)->getName());
#pragma cplusplus reset
    } else {
        strcpy(*(char **)((u8 *)obj + 0x28), (const char*)&lbl_8055BB98);
    }
}

extern void fn_80208D60(int);
extern void fn_8020A5F8(float *, float);

/* Sound-options panel (vtable lbl_803415E8: deleting destructor fn_8023D134,
 * refresh fn_8023D1FC, apply-field fn_8023D304).  Its fields 0..6 are the value
 * pointers fn_8023D1FC registers with fn_80221EA0; fn_8023D304 pushes the field
 * the player changed into the sound code. */
typedef struct SoundOptions {
    u8 pad00[0x14];
    void *fieldList;     /* 0x14 field list fn_80221EA0 passes on */
    f32 *effectsVolume;  /* 0x18 field 0: "effects_volume" */
    f32 *musicVolume;    /* 0x1C field 3: music volume */
    s32 *speakerMode;    /* 0x20 field 1: 0..2 */
    s32 *deviceIndex;    /* 0x24 field 2: chosen sound device */
    char *deviceName;    /* 0x28 its name, STR_N_A when there is none */
    f32 *level;          /* 0x2C field 4: level handed to `widget` */
    s32 f30;             /* 0x30 field 5 */
    s32 f34;             /* 0x34 field 6 */
    void *widget;        /* 0x38 level (+0x8) and dirty flags (+0x49..+0x4D) */
} SoundOptions;

#define sound_device_count  fn_80208D3C /* size of the sound device list */
#define sound_device_get    fn_80208D4C /* index -> device (getName at vtable +0xC) */
#define sound_device_select fn_80208D60 /* index -> current device */
#define effects_volume_set  fn_80209030 /* clamped, saved as "effects_volume" */
#define speaker_mode_set    fn_80209090 /* 0..2, else 0 */
#define music_volume_set    fn_8020A5F8 /* f32 music volume */
#define STR_N_A             lbl_8055BB98 /* "N/A" */
void fn_8023D304(void *arg0, int arg1) {
    float *tmp;
    float f;
    int idx;
    void *item;
    void *o38;
    switch (arg1) {
    case 2:
        if (*(int *)(*(int *)((char *)arg0 + 0x24)) >= (int)fn_80208D3C()) {
            *(int *)(*(int *)((char *)arg0 + 0x24)) = (int)fn_80208D3C() - 1;
        }
        fn_80208D60(*(int *)(*(int *)((char *)arg0 + 0x24)));
        idx = *(int *)(*(int *)((char *)arg0 + 0x24));
        if (idx >= 0 && idx < (int)fn_80208D3C()) {
#pragma cplusplus on
            struct IV1 { virtual void u0(); virtual const char *getName(); };
            item = fn_80208D4C(idx);
            strcpy(*(char **)((char *)arg0 + 0x28), ((struct IV1 *)item)->getName());
#pragma cplusplus reset
            return;
        }
        strcpy(*(char **)((char *)arg0 + 0x28), (const char *)&lbl_8055BB98);
        return;
    case 3:
        tmp = *(float **)((char *)arg0 + 0x1C);
        fn_8020A5F8(tmp, *tmp);
        return;
    case 0:
        tmp = *(float **)((char *)arg0 + 0x18);
        ((void (*)(float *, float))fn_80209030)(tmp, *tmp);
        return;
    case 1:
        fn_80209090(*(int *)(*(int *)((char *)arg0 + 0x20)));
        return;
    case 4:
        o38 = *(void **)((char *)arg0 + 0x38);
        if (o38 != 0) {
            f = *(float *)(*(int *)((char *)arg0 + 0x2C));
            if (f != *(float *)((char *)o38 + 8)) {
                *(char *)((char *)o38 + 0x4D) = 1;
                *(float *)((char *)o38 + 8) = f;
            }
            o38 = *(void **)((char *)arg0 + 0x38);
            *(char *)((char *)o38 + 0x4A) = 1;
            *(char *)((char *)o38 + 0x4C) = 0;
            o38 = *(void **)((char *)arg0 + 0x38);
            *(char *)((char *)o38 + 0x49) = 1;
            *(char *)((char *)o38 + 0x4B) = 0;
            *(char *)((char *)o38 + 0x4A) = 0;
        }
        return;
    case 5:
    case 6:
        return;
    default:
        return;
    }
}

extern s32 lbl_8055BB68;

