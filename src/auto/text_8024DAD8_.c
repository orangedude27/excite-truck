// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern double lbl_80563958;
extern unsigned char lbl_80498C48[];
s32 fn_8001668C(s32, s32);
s32 *fn_80016BC8(s32);
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

