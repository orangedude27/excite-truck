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

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
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

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
f32 fn_800109A0(s32 arg0) {
    return (f32)arg0 / (f32)lbl_80558A90;
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
    Unk0x18 entry;

    entry.unk_0x00 = (f32)arg1;
    entry.unk_0x04 = (f32)arg2;
    entry.unk_0x08 = (f32)arg3;
    entry.unk_0x0C = (f32)arg4;
    entry.unk_0x10 = arg0;
    entry.unk_0x14 = arg0;
    if (lbl_8055D4A8 < 0x100) {
        lbl_8034F6B0[lbl_8055D4A8++] = entry;
    }
}

#pragma dont_inline on
void *fn_80010BEC(void *arg0) {
    Unk0x18 *entry;
    s32 i;

    if (lbl_8055D4A8 > 0) {
        fn_80010B74();
        entry = lbl_8034F6B0;
        i = 0;
        while (i < lbl_8055D4A8) {
            fn_80010A50(entry->unk_0x00, entry->unk_0x04, entry->unk_0x08,
                        entry->unk_0x0C, entry->unk_0x10, entry->unk_0x14);
            entry++;
            i++;
        }
        fn_80010B7C();
        lbl_8055D4A8 = 0;
    }
}
#pragma dont_inline off

void fn_80010EF0(void);
void fn_80010F08(void);
void fn_80010F20(void);
void fn_80010EC8(void) {
    fn_80010EF0();
    fn_80010F08();
    fn_80010F20();
}

typedef struct Unk80350F88Entry {
    char name[0x28];
    u8 unk_0x28;
    s32 unk_0x2C;
    s32 unk_0x30;
    s32 unk_0x34;
    s32 unk_0x38;
    f32 unk_0x3C;
} Unk80350F88Entry;

typedef struct Unk80350F88 {
    s32 unk_0x00;
    u8 unk_0x04;
    Unk80350F88Entry entries[10];
    s32 unk_0x288;
} Unk80350F88;
extern char *strncpy(char *, const char *, unsigned long);
extern f32 lbl_80560264;
extern f32 lbl_80560280;
extern void fn_802353F4(f32, f32, f32, f32, f32, f32);
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
void fn_80010E94(f32 x, f32 y, f32 a, f32 b, s32 c, s32 d) {
    if (lbl_80560280 == a && lbl_80560280 == b) {
        fn_802353F4(x, y, lbl_80560264, b, b, a);
    } else {
        fn_802354A0(c, d, -1, x, y, lbl_80560264, a, b);
    }
}
void fn_80010EF0(void) {
    Unk80350F88 *p = (Unk80350F88 *)&lbl_80350F88;

    p->unk_0x288 = 0;
    p->unk_0x04 = 0;
}

extern void fn_80011280(s32, s32);
extern void fn_8000E3B4(s32);
extern void fn_8000E874(s32);
extern void fn_8000EF74(s32);
void fn_80010F38(char *name, s32 a2, s32 a3, s32 a4, f32 f1) {
    Unk80350F88 *base = (Unk80350F88 *)&lbl_80350F88;
    Unk80350F88Entry *entry = &base->entries[base->unk_0x288++];
    char *n = name;
    s32 v2 = a2;
    s32 v3 = a3;
    s32 v4 = a4;

    strncpy(entry->name, n, 0x28);
    entry->unk_0x28 = 0;
    entry->unk_0x2C = v2;
    entry->unk_0x30 = v3;
    entry->unk_0x34 = 0;
    entry->unk_0x38 = v4;
    entry->unk_0x3C = f1;
}

void fn_800111A4(char *name, s32 a1, s32 a2, s32 a3, s32 a4, f32 f) {
    s32 idx;
    s8 *entry;

    idx = *(s32 *)((s8 *)&lbl_80350F88 + 0x288);
    *(s32 *)((s8 *)&lbl_80350F88 + 0x288) = idx + 1;
    entry = (s8 *)&lbl_80350F88 + idx * 0x40 + 8;
    strncpy((char *)entry, name, 0x28);
    *(entry + 0x28) = 0;
    *(s32 *)(entry + 0x2c) = a1;
    *(s32 *)(entry + 0x30) = a2;
    *(s32 *)(entry + 0x34) = a3;
    *(s32 *)(entry + 0x38) = a4;
    *(f32 *)(entry + 0x3c) = f;
}

void fn_8001123C(s32 arg0) {
    fn_8000E3B4(arg0);
    fn_8000E874(arg0);
    fn_8000EF74(arg0);
}

void fn_80011278(s32 arg0) {
    fn_80011280(arg0, lbl_8055D4D4);
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

