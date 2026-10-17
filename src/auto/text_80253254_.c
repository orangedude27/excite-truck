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
    float v[3];
    v[0] = lbl_80563A04 * lbl_80563A10;
    v[1] = lbl_80563A08 * lbl_80563A10;
    v[2] = lbl_80563A0C * lbl_80563A10;
    PSVECNormalize(v, v);
    fn_802C9A1C(v);
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

s32 fn_802571F0(void) { return 0; }

void fn_802571F8(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 1; }

void fn_80257204(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 0; }

void fn_80257210(void) {}

