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
    s32 *base = (s32 *)&lbl_803414D0;
    lbl_8055F160 = zero;
    fn_801333E8(4, base + 0, &lbl_8055F160);
    lbl_8055F164 = lbl_80563738;
    fn_801331C4(4, base + 4, &lbl_8055F164);
    lbl_8055F168 = lbl_80563738;
    fn_801331C4(4, base + 8, &lbl_8055F168);
    lbl_8055F16C = lbl_80563738;
    fn_801331C4(4, base + 12, &lbl_8055F16C);
    fn_80209030(lbl_8055F16C);
    lbl_8055F17C = zero;
    fn_801332D0(4, &lbl_8055BB70, &lbl_8055F17C);
    fn_80209090(lbl_8055F17C);
    lbl_8055F170 = lbl_80563738;
    fn_801331C4(4, base + 16, &lbl_8055F170);
    lbl_8055F174 = lbl_80563738;
    fn_801331C4(4, base + 19, &lbl_8055F174);
    lbl_8055F178 = 1;
    fn_801332D0(4, base + 23, &lbl_8055F178);
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
    f32 fl[10];
    s32 result30;
    s32 argStruct[5];
    s32 a48[5];
    s32 a5c;
    s32 pad60[4];
    s32 a70[10];
    s32 a98[64];
    s32 big1[40];
    s32 big2[50];
    s32 i;
    fn_8023CA54();
    if (lbl_8055F160 == 0) {
        lbl_8055F164 = lbl_8056373C;
    }
    result30 = fn_80208D70();
    a5c = (s32)lbl_803415E8;
    a70[3] = result30;
    a70[1] = (s32)&lbl_8055F16C;
    a70[0] = 0;
    a70[2] = (s32)&lbl_8055F17C;
    a70[4] = (s32)&lbl_8055F164;
    a70[5] = (s32)a98;
    a70[6] = (s32)&lbl_8055F168;
    a70[7] = (s32)&lbl_8055F170;
    a70[8] = (s32)&lbl_8055F174;
    a70[9] = 0;
    fn_8022D228(a48, 0x11, 0x20);
    i = 0;
    do {
        fn_8022D350(a48, &lbl_8055BB78, 0);
        i++;
    } while (i < 0x11);
    fl[0] = lbl_80563738;
    fl[1] = lbl_8056373C;
    fl[2] = lbl_80563738;
    fl[3] = lbl_8056373C;
    fl[4] = lbl_80563738;
    fl[5] = lbl_8056373C;
    fl[6] = lbl_80563738;
    fl[7] = lbl_8056373C;
    fl[8] = lbl_80563738;
    fl[9] = lbl_8056373C;
    big1[0] = lbl_8055BAC0;
    big1[1] = 8;
    big1[2] = (s32)fn_8023CA18;
    big1[3] = 0;
    big1[4] = 0;
    big1[5] = 0;
    big1[6] = 5;
    big1[7] = (s32)a48;
    big1[8] = 0;
    big1[9] = 0;
    big1[10] = lbl_8055BB80;
    big1[11] = 0;
    big1[12] = (s32)fn_8023CB54;
    big1[13] = 0;
    big1[14] = 0;
    big1[15] = (s32)(lbl_803414D0 + 0x4C);
    big1[16] = 9;
    big1[17] = (s32)&lbl_8055F174;
    big1[18] = *(s32 *)&fl[9];
    big1[19] = *(s32 *)&fl[8];
    big1[20] = (s32)(lbl_803414D0 + 0xB8);
    big1[21] = 9;
    big1[22] = (s32)&lbl_8055F16C;
    big1[23] = *(s32 *)&fl[7];
    big1[24] = *(s32 *)&fl[6];
    big1[25] = (s32)(lbl_803414D0 + 0xC4);
    big1[26] = 9;
    big1[27] = (s32)&lbl_8055F168;
    big1[28] = *(s32 *)&fl[5];
    big1[29] = *(s32 *)&fl[4];
    big1[30] = (s32)(lbl_803414D0 + 0x10);
    big1[31] = 9;
    big1[32] = (s32)&lbl_8055F164;
    big1[33] = *(s32 *)&fl[3];
    big1[34] = *(s32 *)&fl[2];
    big1[35] = (s32)(lbl_803414D0 + 0x40);
    big1[36] = 9;
    big1[37] = (s32)&lbl_8055F170;
    big1[38] = *(s32 *)&fl[1];
    big1[39] = *(s32 *)&fl[0];
    big2[0] = lbl_8055BB88;
    big2[1] = 0;
    big2[2] = 0;
    big2[3] = -1;
    big2[4] = 0;
    big2[5] = lbl_8055BB70;
    big2[6] = 7;
    big2[7] = lbl_8055F17C;
    big2[8] = (s32)(lbl_803414D0 + 0x7C);
    big2[9] = 0;
    big2[10] = (s32)(lbl_803414D0 + 0xD8);
    big2[11] = 7;
    big2[12] = lbl_8055F178;
    big2[13] = (s32)(lbl_803414D0 + 0x90);
    big2[14] = 0;
    big2[15] = lbl_8055BB90;
    big2[16] = 2;
    big2[17] = (s32)&result30;
    big2[18] = 0;
    big2[19] = 0;
    big2[20] = (s32)(lbl_803414D0 + 0xE4);
    big2[21] = 3;
    big2[22] = (s32)a98;
    big2[23] = 0x100;
    big2[24] = 0;
    big2[25] = (s32)(lbl_803414D0 + 0xF0);
    big2[26] = 0xA;
    big2[27] = (s32)a48;
    big2[28] = 0;
    big2[29] = 0;
    big2[30] = lbl_8055B860;
    big2[31] = 6;
    big2[32] = (s32)fn_8023CB80;
    big2[33] = -1;
    big2[34] = 0x1B;
    big2[35] = lbl_8055BABC;
    big2[36] = 8;
    big2[37] = (s32)fn_8023CA50;
    big2[38] = 1;
    big2[39] = 0;
    big2[40] = lbl_8055BAB8;
    big2[41] = 8;
    big2[42] = (s32)fn_80236914;
    big2[43] = 2;
    big2[44] = 0;
    big2[45] = lbl_804987A0[0];
    big2[46] = lbl_804987A0[1];
    big2[47] = lbl_804987A0[2];
    big2[48] = lbl_804987A0[3];
    big2[49] = lbl_804987A0[4];
    argStruct[0] = (s32)arg0;
    argStruct[1] = (s32)big1;
    argStruct[2] = 0;
    argStruct[3] = 0;
    argStruct[4] = 0;
    if (fn_802146BC(argStruct, -999, -999, 1, 0, lbl_804987A0[4], 8, 0x100) == -2) {
        fn_8023CBA4();
    }
    lbl_8055F160 = (lbl_8055F164 == lbl_80563740) ? 1 : 0;
    fn_8013323C(4, lbl_803414D0 + 0x10, lbl_8055F164);
    fn_80133460(4, lbl_803414D0, lbl_8055F160);
    fn_8013323C(4, lbl_803414D0 + 0x20, lbl_8055F168);
    fn_8013323C(4, lbl_803414D0 + 0x40, lbl_8055F170);
    fn_8013323C(4, lbl_803414D0 + 0x4C, lbl_8055F174);
    fn_80133348(4, lbl_803414D0 + 0x5C, lbl_8055F178);
    fn_8022D2BC(a48, -1);
    a5c = (s32)lbl_803415E8;
    if (a70[9] != 0) {
        a70[9] = 0;
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
void fn_8023D1FC(void *p) {
    s32 n;
    void *item;
    fn_80221EA0(p, 2, *(s32 *)((u8 *)p + 0x24), 4);
    fn_80221EA0(p, 0, *(s32 *)((u8 *)p + 0x18), 4);
    fn_80221EA0(p, 1, *(s32 *)((u8 *)p + 0x20), 4);
    fn_80221EA0(p, 3, *(s32 *)((u8 *)p + 0x1c), 4);
    fn_80221EA0(p, 4, *(s32 *)((u8 *)p + 0x2c), 4);
    fn_80221EA0(p, 5, *(s32 *)((u8 *)p + 0x30), 4);
    fn_80221EA0(p, 6, *(s32 *)((u8 *)p + 0x34), 4);
    n = **(s32 **)((u8 *)p + 0x24);
    if (n >= 0 && n < fn_80208D3C()) {
        item = fn_80208D4C(n);
#pragma cplusplus on
        struct ItemView {
            virtual void unused();
            virtual const char* getName();
        };
        strcpy(*(char **)((u8 *)p + 0x28), ((ItemView*)item)->getName());
#pragma cplusplus reset
    } else {
        strcpy(*(char **)((u8 *)p + 0x28), (const char*)&lbl_8055BB98);
    }
}

extern s32 lbl_8055BB68;
typedef struct Obj8023 {
    u8 pad[0x18];
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    char *f28;
    s32 f2c;
    s32 f30;
    s32 f34;
} Obj8023;
typedef struct Vtbl8023 {
    void *v0;
    void *v1;
    void *v2;
    const char *(*v3)(void *);
} Vtbl8023;
