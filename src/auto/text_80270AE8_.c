// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void DBPrintf_80270B00(const char *fmt, ...) {
#pragma unused(fmt)
}

typedef signed int s32;
typedef unsigned char u8;
void *fn_80178C9C(void);
s32 fn_80270B50(void);
s32 fn_80270EC4(void *, s32);
void fn_80271578(void) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r3;
    temp_r3 = fn_80178C9C();
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 0xC);
    temp_r30 = temp_r3;
    fn_80270EC4(temp_r30, fn_80270B50());
    *(s32 *)((u8 *)temp_r30 + 0xC) = temp_r31;
}

