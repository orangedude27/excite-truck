// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D4D0;
extern s32 lbl_8055D4C0;
extern s32 lbl_8055D4C4;
extern s32 lbl_8055D4C8;
extern s32 fn_8023512C();
extern void fn_80235380();
extern s32 lbl_80350F88;
extern s32 lbl_80351214;
extern s32 lbl_8055D4BC;
typedef struct UnkF22C UnkF22C;
typedef struct UnkF22CVtable {
    void *unk_0x0;
    void *unk_0x4;
    void (*unk_0x8)(UnkF22C *, s32);
} UnkF22CVtable;
struct UnkF22C {
    UnkF22CVtable *vtable;
};
extern UnkF22C *lbl_8055D4B4;
extern UnkF22C *lbl_8055D4B8;
extern void fn_802328D4(void);
extern s32 fn_80232578(s32);
void fn_8000F330(void *arg0, void *arg1, s32 arg2) {
    lbl_8055D4C0 = fn_8023512C();
    lbl_8055D4C4 = fn_80232578((s32)arg1);
    lbl_8055D4C8 = fn_80232578(arg2);
}

void fn_8000F384(void) {
    if (lbl_8055D4C0 != 0) {
        fn_80235380();
        lbl_8055D4C0 = 0;
    }
    if (lbl_8055D4C4 != 0) {
        fn_802328D4();
        lbl_8055D4C4 = 0;
    }
    if (lbl_8055D4C8 != 0) {
        fn_802328D4();
        lbl_8055D4C8 = 0;
    }
}

void fn_8000F3E8(void) {
    lbl_8055D4D0 = fn_8023512C();
}

void fn_8000F40C(void) {
    if (lbl_8055D4D0 != 0) {
        fn_80235380(lbl_8055D4D0);
        lbl_8055D4D0 = 0;
    }
}

extern s32 lbl_8055D4CC;
void fn_8000F440(void) {
    lbl_8055D4CC = fn_8023512C();
}

extern s32 lbl_8055D4D4;
void fn_8000F498(void) {
    lbl_8055D4D4 = fn_8023512C();
}

void fn_80010EF0(void);
void fn_80010F08(void);
void fn_80010F20(void);
void fn_80010EC8(void) {
    fn_80010EF0();
    fn_80010F08();
    fn_80010F20();
}

