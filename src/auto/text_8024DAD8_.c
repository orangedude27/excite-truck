// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
static inline void CleanupEntries(void *table) {
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128670(s32);
    extern s32 fn_80128668(void *);
    s32 offset, i;
    u8 *entry;
    if (table != 0) {
        i = 0;
        offset = 0;
        for (; i < *(s32 *)((u8 *)table + 4); offset += 0x38, i++) {
            entry = *(u8 **)table + offset;
            fn_802CAC54(*(s32 *)(entry + 0x20));
            fn_802CAC54(*(s32 *)(entry + 0x24));
        }
        fn_80128670(*(s32 *)table);
        fn_80128668(table);
    }
}
extern double lbl_80563958;
extern unsigned char lbl_80498C48[];
s32 fn_8001668C(s32, s32);
s32 *fn_80016BC8(s32);
extern unsigned char lbl_803444D8[];
extern void *lbl_8055F2E4;
extern s32 lbl_8055F2E8;
#pragma push
#pragma use_lmw_stmw off
void *fn_8024E920(void *arg0, s32 arg1) {
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    unsigned char *entry;
    s32 i, offset;
    void *table;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_803444D8;
        fn_80128670(*(s32 *)((u8 *)arg0 + 0xCC));
        if (--lbl_8055F2E8 == 0) {
            CleanupEntries(lbl_8055F2E4);
            lbl_8055F2E4 = 0;
        }
        if (arg0 != 0) {
            *(void **)arg0 = lbl_8034453C;
            fn_80128670(*(s32 *)((u8 *)arg0 + 0x18));
            fn_80235380(*(s32 *)((u8 *)arg0 + 0x24));
            fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x20));
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
s32 fn_8024EB94(void *arg0) { return *(s32 *)((char *)arg0 + 0x1C); }

s32 fn_8024EB9C(void *arg0, s32 arg1) { return *(s32 *)((char *)arg0 + 0xCC) + arg1 * 0x14; }

void fn_8024EBAC(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((char *)arg0 + 0x2C) = arg1;
    if (arg2 != 0) {
        *(f32 *)((char *)arg0 + 0x28) = (f32)arg1;
    }
}

s32 fn_8024EBE4(s32 arg0) {
    fn_8001668C(arg0 + 0x60, 0);
    if (lbl_80498C48[4] != 0) {
        return *fn_80016BC8(0);
    }
    return *(s32 *)((char *)fn_80016BC8(0) + 4);
}

extern void fn_8024739C(void);
typedef unsigned int u32;
extern s32 fn_80129800(s32);
extern void fn_802E4A10(void);
extern void fn_80216D28(void);
extern s32 fn_80214D50(s32);
extern u32 lbl_8055F2EC;
extern unsigned char lbl_8034453C[];
extern s32 fn_80128670(s32);
extern s32 fn_80235380(s32);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128668(void *);
void *fn_8024FB64(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8034453C;
        fn_80128670(*(s32 *)((u8 *)arg0 + 0x18));
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x24));
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x20));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8024FFF8(void *arg0, s32 arg1) {
    extern char lbl_803443B0[];
    if (arg0) {
        void *child = *(void **)((char *)arg0 + 0x188);
        *(void **)arg0 = lbl_803443B0;
        if (child) {
            if (child) ((void (*)(void *, s32))(*(void ***)child)[1])(child, 1);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern f32 lbl_80563960;
extern void fn_802354A0(s32, s32, f32, f32, f32, f32, f32, s32);
extern f32 fn_80216CB4(void);
#pragma push
#pragma processor 750
void fn_802514B4(void *arg0, s32 arg1, f32 x, f32 y, f32 w, f32 h) {
    s32 value = *(s32 *)(*(char **)((char *)arg0 + 0xCC) + arg1 * 0x14 + 0x10);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 0, -1, x, y, lbl_80563960, w, h);
    fn_80216CB4();
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 3, value, x, y, lbl_80563960, w, h);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 6, -1, x, y, lbl_80563960, w, h);
}
#pragma pop
extern void fn_80255904(s32);
extern void fn_80214A9C(s32, f32);
extern void fn_80221F94(void *, s32);
extern void *fn_801284F8(u32, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
extern f32 lbl_80563960, lbl_805639C0, lbl_80558DC4;
extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[], lbl_803443B0[];
void fn_80251D0C(void *arg0) {
    fn_80255904(*(s32 *)((char *)arg0 + 0x20));
    *(s32 *)((char *)arg0 + 0x190) = -1;
    *(u8 *)((char *)arg0 + 0x28) = 0; *(u8 *)((char *)arg0 + 0x48) = 0;
    *(u8 *)((char *)arg0 + 0x88) = 0; *(u8 *)((char *)arg0 + 0x108) = 0;
    *(f32 *)((char *)arg0 + 0x194) = lbl_80563960;
    *(f32 *)((char *)arg0 + 0x198) = lbl_805639C0;
    fn_80214A9C(0x1f, lbl_80563960);
    *(u8 *)((char *)arg0 + 0x19c) = 0;
}

s32 fn_80252238(void *arg0, s32 arg1) {
    extern f32 lbl_80558DC4;
    if (arg1 != 13) return 0;
    if ((f32)fabs((double)*(f32 *)((char *)arg0 + 0x194)) > lbl_80558DC4) return 0;
    if ((f32)fabs((double)*(f32 *)((char *)arg0 + 0x198)) > lbl_80558DC4) return 0;
    fn_80221F94(arg0, 0);
    return 1;
}

#pragma push
#pragma opt_common_subs off
void *fn_802522A8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 4 != 0) {
            fn_80128670(*(s32 *)((char *)arg0 + 0x10));
            if ((char *)arg0 + 4 != 0) {
                *(s32 *)((char *)arg0 + 4) = 0;
                *(s32 *)((char *)arg0 + 8) = 0;
                *(s32 *)((char *)arg0 + 0xC) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop

void fn_80252454(void *arg0, s32 arg1, s32 arg2) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    *(s32 *)((char *)base + offset + 0x44) = arg2;
}

s32 fn_80252468(void *arg0) { return *(s32 *)((char *)arg0 + 8); }

s32 fn_80252470(void *arg0, s32 arg1) { return *(s32 *)((char *)arg0 + 4) + arg1 * 0x48; }

u8 fn_80252480(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(u8 *)((char *)base + offset + 0x20);
}

char *fn_80252494(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    char *base = *(char **)((char *)arg0 + 4);
    return base + offset + 0x21;
}

u8 fn_802524A8(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(u8 *)((char *)base + offset + 0x41);
}

s32 fn_802524BC(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(s32 *)((char *)base + offset + 0x44);
}

