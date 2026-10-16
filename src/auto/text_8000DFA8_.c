// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D4A8;
extern f32 lbl_80350F28[][6];

typedef struct Unk0x18 {
    f32 unk_0x00;
    f32 unk_0x04;
    f32 unk_0x08;
    f32 unk_0x0C;
    s32 unk_0x10;
    s32 unk_0x14;
} Unk0x18;
extern Unk0x18 lbl_8034F6B0[0x100];
extern void fn_80010A50(f32, f32, f32, f32, s32, s32);
extern void fn_80010B74(void);
extern void fn_80010B7C(void);
extern void fn_802C8BD0(s32);
extern void fn_802C8D74(void);
extern void fn_80234AEC(void);
extern void *fn_80010BEC(void *);
extern void fn_802346C8(void *);

extern s32 lbl_8055D4D0;
extern s32 lbl_8055D4C0;
extern s32 lbl_8055D4C4;
extern s32 lbl_8055D4C8;
extern s32 fn_8023512C();
extern void fn_80235380();
__declspec(section ".data") extern s32 lbl_80350F88;
__declspec(section ".data") extern s32 lbl_80351214;
extern s32 lbl_8055D4BC;
typedef struct UnkF22C UnkF22C;
typedef struct UnkF22CVtable {
    void *unk_0x0;
    void *unk_0x4;
    void (*unk_0x8)();
} UnkF22CVtable;
struct UnkF22C {
    UnkF22CVtable *vtable;
};
extern UnkF22C *lbl_8055D4B4;
extern UnkF22C *lbl_8055D4B8;
extern void fn_802328D4(void);
extern s32 fn_80232578(s32);
void fn_8000F22C(void) {
    UnkF22C *obj;
    void (*destroy)(UnkF22C *, s32);
    if (lbl_8055D4BC != 0) fn_80235380(lbl_8055D4BC);
    lbl_8055D4BC = 0;
    obj = lbl_8055D4B4;
    if (obj != 0) {
        if (obj != 0) {
            destroy = obj->vtable->unk_0x8;
            destroy(obj, 1);
        }
    }
    obj = lbl_8055D4B8;
    if (obj != 0) {
        if (obj != 0) {
            destroy = obj->vtable->unk_0x8;
            destroy(obj, 1);
        }
    }
}

void fn_8000F2A8(s32 arg0, s32 arg1) {
    lbl_80350F88 = fn_8023512C(arg0);
    lbl_80351214 = fn_8023512C(arg1);
}

void fn_8000F2EC(void) {
    if (lbl_80350F88 != 0) fn_80235380(lbl_80350F88);
    if (lbl_80351214 != 0) fn_80235380(lbl_80351214);
}

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

void fn_8000F464(void) {
    if (lbl_8055D4CC != 0) {
        fn_80235380(lbl_8055D4CC);
        lbl_8055D4CC = 0;
    }
}

extern s32 lbl_8055D4D4;
void fn_8000F498(void) {
    lbl_8055D4D4 = fn_8023512C();
}

void fn_8000F4BC(void) {
    if (lbl_8055D4D4 != 0) {
        fn_80235380(lbl_8055D4D4);
        lbl_8055D4D4 = 0;
    }
}

void fn_800109E4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    s32 sp18;
    s32 sp1C;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg3;
    sp14 = arg4;
    sp18 = arg0;
    sp1C = arg0;
    fn_80010B74();
    fn_80010A50(arg1, arg2, arg3, arg4, arg0, arg0);
    fn_80010B7C();
}

void fn_80010B74(void) {
    fn_802C8BD0(-1);
}

void fn_80010B80(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Unk0x18 *entry;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    s32 sp18;
    s32 sp1C;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg3;
    sp14 = arg4;
    sp18 = arg0;
    sp1C = arg0;
    if (lbl_8055D4A8 < 0x100) {
        entry = &lbl_8034F6B0[lbl_8055D4A8];
        entry->unk_0x00 = (f32)arg1;
        entry->unk_0x04 = (f32)arg2;
        entry->unk_0x08 = (f32)arg3;
        entry->unk_0x0C = (f32)arg4;
        entry->unk_0x10 = arg0;
        entry->unk_0x14 = arg0;
        lbl_8055D4A8++;
    }
}

void fn_80010EF0(void);
void fn_80010F08(void);
void fn_80010F20(void);
void fn_80010EC8(void) {
    fn_80010EF0();
    fn_80010F08();
    fn_80010F20();
}

void fn_80011A2C(void *arg0) {
    fn_802346C8(fn_80010BEC(arg0));
}

void fn_80011A50(void) {
    lbl_8055D4A8 = 0;
    fn_80234AEC();
}

f32 fn_80011DC0(s32 arg0) {
    return lbl_80350F28[arg0][0];
}

f32 fn_80011DD4(s32 arg0) {
    return lbl_80350F28[arg0][1];
}

