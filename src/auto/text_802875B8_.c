// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F6C8;
typedef signed int s32;
typedef unsigned char u8;
s32 fn_8028774C(void *arg0) {
    return *((u8 *)arg0 + 0x1C) == 0;
}

void fn_80287AF0(void* alarm) {
    fn_8028A9F4(fn_80292864(alarm));
}

void fn_80288868(void* hi) {
    lbl_8055F6C8 = hi;
}
