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
void *fn_802556BC(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x120) = arg1;
    *(void **)((u8 *)arg0 + 0xFC) = lbl_80344BC0;
    *(s32 *)((u8 *)arg0 + 0x110) = 0;
    *(void **)arg0 = lbl_80344B98;
    *(u8 *)((u8 *)arg0 + 0x114) = 0;
    fn_80255200(arg0, 0);
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

s32 fn_802571F0(void) { return 0; }

void fn_802571F8(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 1; }

void fn_80257204(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 0; }

void fn_80257210(void) {}

