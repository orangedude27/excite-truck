// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern f32 lbl_8055A2F4;
extern s32 lbl_8055E3C4;
extern f32 lbl_8055E3C8;
extern f32 lbl_80561B20;
extern f32 lbl_8055E460;
extern f32 lbl_80561B1C;
extern s32 lbl_8055E3C0;
void fn_8013A208(void);
extern s32 lbl_8055E3CC;
extern u32 lbl_8055E3F8;
extern s32 lbl_8055E3E0;
extern s32 lbl_8055E3F4;
extern u8 lbl_8055E3EC;
extern char lbl_803316EC[];
extern char lbl_8033170C[];
extern f32 lbl_8055E3FC;
extern f32 lbl_80561B38;
extern f32 lbl_80561B3C;
s32 fn_8012F458(s32, s32);
s32 fn_8012F4AC(s32, void *, s32);
s32 fn_80179658(s32);
void fn_80176CC8(void);
void fn_802E317C(const char *);
s32 fn_8017ED00(f32);

void fn_80176610(void) {
    fn_80176CC8();
}

void fn_8017677C(void) {
}

void fn_80176858(void) {
    fn_80177138();
}

int fn_80176F9C(void);
void fn_801770C8(void);
void fn_8017691C(void) {
    if (fn_80176F9C() == 0) {
        fn_801770C8();
    }
}

void fn_80176948(void *arg0, s32 *arg1) {
    s32 value = lbl_8055E3CC;
    *arg1 = value;
    fn_8012F458(lbl_8055E3E0, value);
    fn_8012F4AC(lbl_8055E3E0, arg0, *(s32 *)((char *)arg0 + 4));
    lbl_8055E3CC += fn_80179658(*(s32 *)arg0);
}

s32 fn_801769A8(void);
extern u8 lbl_804303C8[12];
s32 fn_801769A8(void) {
    return ((s32*)lbl_804303C8)[1];
}

void *fn_801769B8(void) { return *(void **)&lbl_804303C8; }

extern void *lbl_8055E3E8;
void* fn_801769C4(void) {
    return lbl_8055E3E8;
}

extern u8 lbl_804303E0[];
void *__AXFXGetLfoSinTable_801769CC(void) {
    return lbl_804303E0;
}

u32 *fn_801769D8(void) { return &lbl_8055E3F8; }

void __AXDSPInitCallback_801769E0(void) {
    lbl_8055E3C0 = 1;
}

void fn_801769EC(void) {
    lbl_8055E3C0 = 2;
    fn_8013A208();
}

extern char lbl_8055E3BD;
char fn_801769F8(void) {
    return lbl_8055E3BD;
}

extern void* lbl_8055A2F0;
void fn_80176A00(s32 arg0) {
    *(volatile s32*)&lbl_8055A2F0 = arg0;
    if (*(volatile s32*)&lbl_8055A2F0 == 1) {
        lbl_8055E460 = lbl_80561B1C;
    }
}

extern void *lbl_8055A2F0;
void* fn_80176A1C(void) {
    return lbl_8055A2F0;
}

void fn_80176A24(f32 arg0) {
    lbl_8055A2F4 = arg0;
}

void fn_80176A34(s32 arg0) {
    lbl_8055E3C4 = arg0;
    lbl_8055E3C8 = lbl_80561B20 * (f32)arg0;
}

void fn_80176A6C(void) {
    fn_801771A8();
}

void fn_80176BA8(void) {

}

void fn_80176BAC(void) {
    f32 now = lbl_8055E3C8;
    f32 delta = now - lbl_8055E3FC;
    f32 value = delta;
    if (value > lbl_80561B38)
        value = lbl_80561B38;
    if (value < lbl_80561B3C)
        value = lbl_80561B3C;
    fn_8017ED00(value);
    lbl_8055E3FC = now;
}

extern char lbl_8055E3D4;
void fn_80176DD4(void) {
    lbl_8055E3D4 = 1;
}

void fn_80176F24(void) {
    fn_80176EC0();
}

extern void fn_80177658(void *);
extern void fn_80177608(void);
extern void fn_80177618(void);
extern void fn_80177628(void);
extern void fn_80177638(void);
void fn_80177790(void) { fn_80177658((void *)fn_80177608); }

void fn_8017779C(void) { fn_80177658(&fn_80177618); }

void fn_801777A8(void) { fn_80177658(&fn_80177628); }

void fn_801777B4(void) { fn_80177658(&fn_80177638); }

extern unsigned char fn_80177648[];
void fn_801777C0(void) {
    fn_80177658(fn_80177648);
}

void fn_801777CC(void) {
    fn_801776C4();
}

void fn_801777D0(void) {
    fn_80177720();
}


