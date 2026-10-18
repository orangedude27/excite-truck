// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
__declspec(section ".data") extern s32 lbl_803514A0;


extern f32 lbl_80350EC4[];
extern f32 lbl_80350ED8[];

extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 fn_80232578(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
extern f32 lbl_8056025C;
extern f32 lbl_80560260;
extern f32 lbl_805602C4;
extern f32 lbl_805602C0;
extern f32 fn_80011E54(void);
extern f32 fn_80011E90(void);
extern f32 fn_80011E1C(s32);
extern f32 fn_80011DC0(s32);
extern s32 lbl_8055D498;
extern void fn_80234470(void);
extern void fn_802328D4();

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
  extern void fn_802328D4();
  extern char lbl_802FC414[];
extern s32 fn_80232578(s32);
extern s32 lbl_80351738[0x54];
extern s32 lbl_8055D494;
extern UnkF22C *lbl_8055D4B0;
extern void fn_802C6CF8(s32);
extern s32 lbl_80558A94;
extern s32 fn_802C6FC0(s32, s32, s32);
  extern void fn_80234470(void);
  extern s32 lbl_8055D498;
  extern s32 lbl_8055D49C;
  extern s32 fn_8023441C(void);
  extern f32 fn_80011EDC(void);
      extern s32 fn_801E85A4(void);
  extern f32 fn_80011E54(void);
  extern f32 fn_80011E90(void);
  extern f32 fn_80011E1C(s32);
  extern f32 fn_80011DC0(s32);
  extern f32 lbl_80560260;
  extern f32 lbl_805602C4;
  extern f32 lbl_805602C0;
extern s32 fn_80207848(void *, s32);
extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern char lbl_802FC3DC[];
extern s32 fn_802E317C(void *);
extern char lbl_802FC420[];
extern char lbl_802FC42C[];
#pragma scheduling off
#pragma peephole off
void fn_8000F188(s32 arg0) {
    lbl_80558A94 = fn_802C6FC0(arg0, 0, 0);
}
#pragma peephole on
#pragma scheduling reset
void fn_8000F1B4(void) {
    fn_802C6CF8(lbl_80558A94);
    lbl_80558A94 = -1;
}

void fn_8000F1E0(void) {
    s32 flag;
    flag = 1;
    lbl_8055D4BC = fn_8023512C();
    lbl_8055D4B4 = (UnkF22C *)fn_80207848(lbl_802FC420, flag);
    lbl_8055D4B8 = (UnkF22C *)fn_80207848(lbl_802FC42C, flag);
}

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
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 fn_80232578(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
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

void fn_8000FB44(void) {
    UnkF22C *obj;
    void (*destroy)(UnkF22C *, s32);

    if (lbl_80351738[0x14] != 0) fn_80235380();
    lbl_80351738[0x14] = 0;
    fn_802328D4(lbl_8055D494);
    lbl_8055D494 = 0;
    obj = lbl_8055D4B0;
    if (obj != 0) {
        if (obj != 0) {
            destroy = obj->vtable->unk_0x8;
            destroy(obj, 1);
        }
    }
    lbl_8055D4B0 = (UnkF22C *)0;
    fn_8000F40C();
    fn_8000F464();
    fn_8000F384();
    fn_8000F1B4();
    fn_8000F2EC();
    fn_8000F22C();
    fn_8000F4BC();
}

void fn_800103B8(s32 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, const char *fmt, ...) {
    extern f32 lbl_80560280;
    extern f32 lbl_80560264;
    extern f32 lbl_805602C8;
    extern s32 lbl_8055D490;
    extern int vsprintf(char *, const char *, va_list);
    extern void fn_80233010(char *, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
    char buffer[0x220];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80233010(buffer, lbl_8055D490, farg1, farg2, farg3, lbl_805602C8 * farg0, lbl_80560280, lbl_80560264, arg0, arg1, 1);
}

#pragma dont_inline off
extern void fn_80010FDC(s32);
extern f32 lbl_80560280;
extern f32 fn_8023293C(s32, f32);
extern f32 fn_80235F64(s32, s32);
extern f32 lbl_8056025C;
extern f32 lbl_80560264;
extern f32 lbl_80560290;
extern f32 lbl_805602F8;
extern f32 lbl_805602FC;
extern s32 lbl_80558A90;
extern s32 lbl_8055D494;
extern UnkF22C *lbl_8055D4B0;
void fn_8001071C(void) {
    fn_80010FDC(0xD);
}

s32 fn_8001084C(s32 arg0) {
    f32 f = fn_8023293C(lbl_8055D490, lbl_80560264);
    f64 d = (f64)(f32)arg0 * (f64)f;
    f32 num = (f32)(d - lbl_80560268);
    f32 den = (f32)(lbl_80558A90 ^ 0x8000);
    f32 q = num / den;
    return (s32)q;
}

f32 fn_800108C8(f32 farg0, s32 arg0) {
    f32 r = farg0 * fn_8023293C(lbl_8055D490, lbl_80560264);
    f32 c = lbl_805602C8;
    return c * r;
}

extern s32 lbl_80558A90;
f32 fn_8001090C(f64 farg0) {
    return lbl_805602C8 * ((f32)farg0 * (f32)fn_80232B70(lbl_8055D490));
}

s32 fn_80010964(s32 arg0) {
    return (s32)(arg0 * fn_80232B70(lbl_8055D490)) / (s32)lbl_80558A90;
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
#pragma scheduling off
void fn_80010EF0(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_80350F88;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

void fn_80010F08(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_80351214;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

void fn_80010F20(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_803514A0;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

#pragma scheduling on
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

f32 fn_80011DEC(s32 arg0) {
    return lbl_80350F28[arg0][2];
}

f32 fn_80011E04(s32 arg0) {
    return lbl_80350F28[arg0][4];
}

f32 fn_80011E1C(s32 arg0) {
    return lbl_80350F28[arg0][5];
}

f32 fn_80011E34(void) {
    return lbl_80350EC4[1];
}

f32 fn_80011E44(void) {
    return lbl_80350EC4[2];
}

f32 fn_80011E54(void) {
    return lbl_80350EC4[0];
}

extern f32 lbl_80350EC4[];
f32 fn_80011E60(void) {
    return lbl_80350EC4[3];
}

f32 fn_80011E70(void) {
    f32 value;
    value = lbl_80350EC4[1] + lbl_80350EC4[2];
    return value * lbl_8056025C;
}

f32 fn_80011E90(void) {
    f32 value;
    value = lbl_80350EC4[0] + lbl_80350EC4[3];
    return value * lbl_8056025C;
}

f32 fn_80011EB0(s32 arg0) {
    return lbl_80350ED8[arg0 * 5 + 2];
}

f32 fn_80011EC8(s32 arg0) {
    return lbl_80350ED8[arg0 * 5];
}

extern s32 *lbl_8055D4AC;
extern void fn_80128668(void *);
void fn_800120BC(void) {
    s32 **base;
    s32 *row;
    s32 i, j;
    base = (s32 **)lbl_8055D4AC;
    if (base != 0) {
        for (i = 0; i < 2; i++) {
            row = (s32 *)base;
            for (j = 0; j < 3; j++) {
                if (row[1] != 0) {
                    ((void (*)(void *, s32))(*(void ***)row[1])[1])((void *)row[1], 1);
                }
                row++;
            }
            base += 3;
        }
        fn_80128668((void *)lbl_8055D4AC);
    }
    lbl_8055D4AC = 0;
}

void fn_80012158(void) {
    s32 *base = (s32 *)lbl_8055D4AC;
    s32 *p;
    s32 n;
    void *obj;
    p = base + base[0];
    obj = (void *)p[1];
    if (obj == 0) return;
    *((u8 *)obj + 0x49) = 1;
    *((u8 *)obj + 0x4B) = 0;
    *((u8 *)obj + 0x4A) = 0;
    n = base[0];
    n++;
    base[0] = n;
    if (n < 3) return;
    base[0] = 0;
}

void fn_800121A4(void) {
    s32 *base = (s32 *)lbl_8055D4AC;
    s32 *p;
    s32 n;
    void *obj;
    p = base + base[0];
    obj = (void *)p[4];
    if (obj == 0) return;
    *((u8 *)obj + 0x49) = 1;
    *((u8 *)obj + 0x4B) = 0;
    *((u8 *)obj + 0x4A) = 0;
    n = base[0];
    n++;
    base[0] = n;
    if (n < 3) return;
    base[0] = 0;
}

extern void fn_801331C4(s32, void *, f32 *);
extern void *lbl_802FC580;
void fn_800121F0(void) {
    f32 sp8;
    s32 *base = (s32 *)lbl_8055D4AC;
    s32 *p;
    s32 i;
    sp8 = lbl_80560264;
    fn_801331C4(4, lbl_802FC580, &sp8);
    for (i = 0; i < 2; i++) {
        p = (s32 *)base[1];
        if (p != 0 && sp8 != *(f32 *)(p + 2)) {
            *(u8 *)(p + 0x4D) = 1;
            *(f32 *)(p + 2) = sp8;
        }
        p = (s32 *)base[2];
        if (p != 0 && sp8 != *(f32 *)(p + 2)) {
            *(u8 *)(p + 0x4D) = 1;
            *(f32 *)(p + 2) = sp8;
        }
        p = (s32 *)base[3];
        if (p != 0 && sp8 != *(f32 *)(p + 2)) {
            *(u8 *)(p + 0x4D) = 1;
            *(f32 *)(p + 2) = sp8;
        }
        base += 3;
    }
}

s32 fn_800122B4(s32 arg0, s32 arg1) {
    s32 sp1C;
    char sp8[0x14];

    fn_801310B4(sp8, 0x14, arg0);
    sp1C = fn_80130FE0(arg0);
    strcpy((char *)arg1, sp8);
    return arg1;
}

void fn_8000F158(void) {
    fn_802328D4(lbl_8055D498);
    fn_80234470();
    lbl_8055D490 = 0;
}

extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern s32 lbl_802FC2A8[];
s32 fn_8000DFA8(s32 arg0) {
    return lbl_802FC2A8[arg0 * 3 + 1];
}

s32 fn_8000DFC0(s32 arg0) {
    return lbl_802FC2A8[arg0 * 3 + 2];
}

s32 fn_8000E2D8(s32 arg0) {
    switch (arg0) {
    case 0:
    case 3:
        return 0;
    case 1:
        return -0x29FFC4;
    case 2:
        return -0x32D37D;
    case 4:
        return 0xFF2D2DC8;
    default:
        return -0x100;
    }
}

s32 fn_8000E338(s32 arg0) {
    s32 var_r3;
    if (arg0 <= 0xF) {
        if ((f32)((f64 (*)(f32, f64))fn_8002EFB4)(
                ((f32 (*)(void))fn_801E7E18)(), lbl_80560278) > lbl_8056025C)
            return -1;
    }
    if (arg0 <= 0x28) return 0xFFF70000;
    var_r3 = 0xFF278F27;
    if (arg0 <= 0x46) var_r3 = 0xFFE5A703;
    return var_r3;
}

f32 fn_8000EDC0(s32 arg0) {
    f32 f1;
    if (fn_801E85A4() > 2) {
        return lbl_80560264;
    }
    if (arg0 < 0xC) {
        if (arg0 >= 0xE) {
            f1 = lbl_80560264;
        } else {
            f1 = lbl_80560264;
            fn_802E317C(&lbl_802FC3A4);
        }
    } else if (arg0 < 0xE) {
        if (arg0 == 0xB) {
            f1 = lbl_80560264;
        } else {
            f1 = lbl_805602B8;
        }
    } else if (arg0 == 0xD) {
        f1 = lbl_805602BC;
    } else {
        f1 = lbl_80560264;
    }
    return f1;
}

s32 fn_8000EE54(s32 arg0) {
    switch (arg0) {
    case 13:
        return -1;
    default:
        fn_802E317C(&lbl_802FC3DC);
        break;
    case 11:
        return -1;
    case 14:
        return -0x5400;
    case 12:
        return -0x5400;
    }
}

f32 fn_8000EEC8(s32 arg0, f32 arg1) {
    f32 f1;
    f32 f31;

    if (fn_801E85A4() == 1) {
        if (arg0 < 0) {
            f1 = fn_80011E54();
        } else {
            f1 = fn_80011DC0(arg0);
        }
        return f1 - lbl_80560260;
    }
    if (arg0 < 0) {
        f1 = fn_80011E90();
    } else {
        f31 = lbl_805602C4 * fn_80011DC0(arg0);
        f1 = (lbl_805602C0 * fn_80011E1C(arg0)) + f31;
    }
    return f1 + (lbl_8056025C * arg1);
}

void fn_8000F0E4(void) {
    f32 f1;

    lbl_8055D490 = fn_8023441C();
    f1 = (f32)fn_80232B70(0);
    f1 = f1 - (f32)lbl_80560268;
    lbl_80558A90 = (s32)(lbl_805602C8 * f1);
    lbl_8055D49C = fn_80011EDC();
    lbl_8055D498 = fn_80232578((s32)lbl_802FC414);
}

