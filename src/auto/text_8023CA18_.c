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
    f32 fl[10];
    s32 result30;
    s32 argStruct[5];
    struct A48Obj obj;
    s32 big[90];
    s32 i;
    fn_8023CA54();
    if (lbl_8055F160 == 0) {
        lbl_8055F164 = lbl_8056373C;
    }
    result30 = fn_80208D70();
    obj.a5c = (s32)lbl_803415E8;
    obj.a70[3] = result30;
    obj.a70[1] = (s32)&lbl_8055F16C;
    obj.a70[0] = 0;
    obj.a70[2] = (s32)&lbl_8055F17C;
    obj.a70[4] = (s32)&lbl_8055F164;
    obj.a70[5] = (s32)obj.a98;
    obj.a70[6] = (s32)&lbl_8055F168;
    obj.a70[7] = (s32)&lbl_8055F170;
    obj.a70[8] = (s32)&lbl_8055F174;
    obj.a70[9] = 0;
    fn_8022D228(obj.a48, 0x11, 0x20);
    i = 0;
    do {
        fn_8022D350(obj.a48, &lbl_8055BB78, 0);
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
    big[0] = lbl_8055BAC0;
    big[1] = 8;
    big[2] = (s32)fn_8023CA18;
    big[3] = 0;
    big[4] = 0;
    big[5] = 0;
    big[6] = 5;
    big[7] = (s32)obj.a48;
    big[8] = 0;
    big[9] = 0;
    big[10] = lbl_8055BB80;
    big[11] = 0;
    big[12] = (s32)fn_8023CB54;
    big[13] = 0;
    big[14] = 0;
    big[15] = (s32)(lbl_803414D0 + 0x4C);
    big[16] = 9;
    big[17] = (s32)&lbl_8055F174;
    big[18] = *(s32 *)&fl[9];
    big[19] = *(s32 *)&fl[8];
    big[20] = (s32)(lbl_803414D0 + 0xB8);
    big[21] = 9;
    big[22] = (s32)&lbl_8055F16C;
    big[23] = *(s32 *)&fl[7];
    big[24] = *(s32 *)&fl[6];
    big[25] = (s32)(lbl_803414D0 + 0xC4);
    big[26] = 9;
    big[27] = (s32)&lbl_8055F168;
    big[28] = *(s32 *)&fl[5];
    big[29] = *(s32 *)&fl[4];
    big[30] = (s32)(lbl_803414D0 + 0x10);
    big[31] = 9;
    big[32] = (s32)&lbl_8055F164;
    big[33] = *(s32 *)&fl[3];
    big[34] = *(s32 *)&fl[2];
    big[35] = (s32)(lbl_803414D0 + 0x40);
    big[36] = 9;
    big[37] = (s32)&lbl_8055F170;
    big[38] = *(s32 *)&fl[1];
    big[39] = *(s32 *)&fl[0];
    big[40] = lbl_8055BB88;
    big[41] = 0;
    big[42] = 0;
    big[43] = -1;
    big[44] = 0;
    big[45] = lbl_8055BB70;
    big[46] = 7;
    big[47] = lbl_8055F17C;
    big[48] = (s32)(lbl_803414D0 + 0x7C);
    big[49] = 0;
    big[50] = (s32)(lbl_803414D0 + 0xD8);
    big[51] = 7;
    big[52] = lbl_8055F178;
    big[53] = (s32)(lbl_803414D0 + 0x90);
    big[54] = 0;
    big[55] = lbl_8055BB90;
    big[56] = 2;
    big[57] = (s32)&result30;
    big[58] = 0;
    big[59] = 0;
    big[60] = (s32)(lbl_803414D0 + 0xE4);
    big[61] = 3;
    big[62] = (s32)obj.a98;
    big[63] = 0x100;
    big[64] = 0;
    big[65] = (s32)(lbl_803414D0 + 0xF0);
    big[66] = 0xA;
    big[67] = (s32)obj.a48;
    big[68] = 0;
    big[69] = 0;
    big[70] = lbl_8055B860;
    big[71] = 6;
    big[72] = (s32)fn_8023CB80;
    big[73] = -1;
    big[74] = 0x1B;
    big[75] = lbl_8055BABC;
    big[76] = 8;
    big[77] = (s32)fn_8023CA50;
    big[78] = 1;
    big[79] = 0;
    big[80] = lbl_8055BAB8;
    big[81] = 8;
    big[82] = (s32)fn_80236914;
    big[83] = 2;
    big[84] = 0;
    big[85] = lbl_804987A0[0];
    big[86] = lbl_804987A0[1];
    big[87] = lbl_804987A0[2];
    big[88] = lbl_804987A0[3];
    big[89] = lbl_804987A0[4];
    argStruct[0] = (s32)arg0;
    argStruct[1] = (s32)big;
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
    fn_8022D2BC(obj.a48, -1);
    obj.a5c = (s32)lbl_803415E8;
    if (obj.a70[9] != 0) {
        obj.a70[9] = 0;
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
