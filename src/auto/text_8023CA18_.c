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
extern s32 lbl_8055B860;
extern void fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
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
        strcpy(*(char **)((u8 *)p + 0x28), ((const char *(*)(void *))(*(s32 **)item)[3])(item));
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
