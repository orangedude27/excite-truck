// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
extern void fn_80253824(void *);
extern s32 fn_80128668(void);
extern char lbl_80344B98[];
extern char lbl_80344BC0[];
extern void fn_80255200(void *, s32);
void fn_80253254(void) {}

void fn_80253258(void) {
    extern float lbl_80563A04, lbl_80563A08, lbl_80563A0C, lbl_80563A10;
    extern void PSVECNormalize(float *, float *);
    extern void fn_802C9A1C(float *);
    float x, y, z, scale;
    float v[3];
    x = lbl_80563A04; y = lbl_80563A08; z = lbl_80563A0C; scale = lbl_80563A10;
    v[0] = x * scale; v[1] = y * scale; v[2] = z * scale;
    PSVECNormalize(v, v); fn_802C9A1C(v);
}

void *fn_8025343C(void *arg0) {
    extern void fn_802532BC(void);
    extern float fn_8023659C(void);
    extern int fn_801F0008(void);
    extern int fn_801284E8(char *, int);
    extern char lbl_803447C0[], lbl_803447CC[];
    fn_802532BC();
    *(float *)((u8 *)arg0 + 4) = fn_8023659C();
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = fn_801284E8(lbl_803447C0, fn_801F0008());
    *(s32 *)((u8 *)arg0 + 0x24) = fn_801284E8(lbl_803447CC, fn_801F0008());
    return arg0;
}

void *__dt__Q210JASDrumSet5TPercFv_802534B0(void *arg0, s32 arg1) {
    extern void fn_80128658(s32);
    if (arg0 != 0) {
        fn_80128658(*(s32 *)((u8 *)arg0 + 0x20));
        fn_80128658(*(s32 *)((u8 *)arg0 + 0x24));
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void fn_80253C48(void *arg0) {
    s32 temp = *(s32 *)((u8 *)arg0 + 0x28);
    if (temp != -1) {
        fn_802C6CF8(temp);
        *(s32 *)((u8 *)arg0 + 0x28) = -1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x3FC) != 0) {
        fn_801D21B4(*(s32 *)((u8 *)arg0 + 0x3FC));
        *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
    }
}

void fn_80254354(void *arg0) {
    extern float lbl_80563A2C;
    s32 var_r0, i;
    u8 *p;
    fn_802C7AE0(*(s32 *)((u8 *)arg0 + 0x14), (u8 *)arg0 + 0x598, -1, lbl_80563A2C);
    p = (u8 *)arg0 + 0x5D8;
    i = 0;
    do {
        var_r0 = 0;
        if (i == 0) {
            var_r0 = 0;
        }
        if (i == 1) {
            var_r0 = 1;
        }
        if (var_r0 != 0)
            fn_801F1474(*(s32 *)((u8 *)arg0 + 0x18), p, lbl_80563A2C);
        else
            fn_801F1474(*(s32 *)((u8 *)arg0 + 0x1C), p, lbl_80563A2C);
        i++;
        p += 0x30;
    } while (i < 4);
}

void fn_80254568(void *arg0, s32 arg1, s32 arg2) {
    void *sp8;
    sp8 = 0;
    fn_801E2CCC(arg1, arg2, &sp8);
    *(s32 *)arg0 = *(s32 *)((u8 *)sp8 + 0x24);
    *(s32 *)((u8 *)arg0 + 4) = *(s32 *)((u8 *)sp8 + 0x28);
    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)sp8 + 0x2C);
}

void fn_80255604(s32 arg0) {
    extern char lbl_803447C0[];
    extern u8 lbl_8055F330;
    fn_8012E81C(lbl_803447C0 + 0x1E0);
    fn_8012E81C(lbl_803447C0 + 0x1F0);
    fn_8012E81C(lbl_803447C0 + 0x1FC);
    fn_8012E96C(lbl_803447C0 + 0x208);
    fn_80203C50(arg0 != 0);
    fn_801EFF4C();
    lbl_8055F330 = 0;
    fn_802AB9E8();
}

void fn_8025567C(void) {
    extern u8 lbl_8055F330;
    if (lbl_8055F330 != 0) {
        fn_802AE9D0();
        fn_80252BC8();
    }
    fn_802ABC2C();
    fn_801EFF70();
    fn_80203DC8();
    fn_802C7A00();
}

void *fn_802556BC(void *arg0, s32 arg1) {
    extern char lbl_80344B98[];
    extern char lbl_80344BC0[];
    extern void fn_80255200(void *, s32);
    void *p = lbl_80344B98;
    *(s32 *)((u8 *)arg0 + 0x120) = arg1;
    *(void **)((u8 *)arg0 + 0xFC) = (void *)lbl_80344BC0;
    *(s32 *)((u8 *)arg0 + 0x110) = 0;
    *(void **)arg0 = p;
    *(u8 *)((u8 *)arg0 + 0x114) = 0;
    fn_80255200(arg0, 0);
    return arg0;
}

s32 fn_80255718(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80255904(void *arg0) {
    extern void fn_80253824(void *);
    fn_80253824(*(void **)((u8 *)arg0 + 8));
}

u8 fn_8025590C(void *arg0) {
    return **(u8 **)((u8 *)arg0 + 8);
}

void fn_80255918(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC) = arg1;
}

void fn_80255920(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x118) = arg1;
}

void fn_80255A7C(void) {
}

void fn_80255A80(void) {
}

__declspec(section ".sdata") extern s32 lbl_8055F340;
__declspec(section ".sdata") extern u8 lbl_8055F330;
__declspec(section ".sdata") extern float lbl_80563A64, lbl_80563A68, lbl_80563A6C, lbl_80563A70;
__declspec(section ".sdata") extern char lbl_8055C1C8[];
extern char lbl_80344A48[];
__declspec(section ".data") extern void *lbl_80498E28[];
extern void fn_80255604(s32);
extern void fn_80252BF0(void);
extern void fn_80252F50(float);
extern s32 fn_802C6FC0(void *, s32, s32);
#pragma dont_inline fn_80255604
void fn_80255A84(void *arg0) {
    if (lbl_8055F340 == 0) {
        fn_80255604(*(s32 *)((char *)arg0 + 0x120));
    }
    if (lbl_8055F330 != 0) {
        fn_80252BF0();
        fn_80252F50(lbl_80563A64);
        *(s32 *)((char *)arg0 + 0xE4) = fn_802C6FC0(lbl_8055C1C8, 0, 0);
    } else {
        *(s32 *)((char *)arg0 + 0xE4) = -1;
        if (*(s32 *)((char *)arg0 + 0x120) == 0) {
            *(s32 *)((char *)arg0 + 0xE4) = fn_802C6FC0(lbl_80344A48, 0, 0);
        }
    }
    *(s32 *)((char *)arg0 + 4) = lbl_8055F340;
    lbl_8055F340++;
    lbl_80498E28[*(s32 *)((char *)arg0 + 4)] = arg0;
    *(float *)((char *)arg0 + 0x9C) = lbl_80563A68;
    *(float *)((char *)arg0 + 0xA0) = lbl_80563A6C;
    *(float *)((char *)arg0 + 0xA4) = lbl_80563A70;
}
s32 fn_802571F0(void) { return 0; }

void fn_802571F8(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 1; }

void fn_80257204(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 0; }

void fn_80257210(void) {}

