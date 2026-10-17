// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned long u32;
extern s32 OSGetConsoleType(void);
extern s32 WriteUARTN(char *, s32);
extern s32 fn_800300FC(void *, char *, s32 *, s32);
extern s32 fn_8009D000(s32);
extern s32 lbl_8055D688;
s32 __write_console(void *arg0, char *arg1, s32 *arg2, s32 arg3) {
    s32 var_r3;

    if (!(OSGetConsoleType() & 0x20000000)) {
        var_r3 = 0;
        if (lbl_8055D688 == 0) {
            var_r3 = fn_8009D000(0xE100);
            if (var_r3 == 0) {
                lbl_8055D688 = 1;
            }
        }
        if (var_r3 != 0) {
            return 1;
        }
        if (WriteUARTN(arg1, *arg2) != 0) {
            *arg2 = 0;
            return 1;
        }
    }
    fn_800300FC(arg0, arg1, arg2, arg3);
    return 0;
}
