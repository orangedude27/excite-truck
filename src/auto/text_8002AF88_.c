// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned long u32;
extern s32 OSGetConsoleType(void);
extern s32 WriteUARTN(char *, s32);
extern s32 fn_800300FC(void *, char *, s32 *, s32);
extern s32 fn_8009D000(s32);
extern s32 lbl_8055D688;
s32 __write_console(void *file, char *buffer, s32 *count, s32 mode) {
    /* Write console output: on non-dev hardware initialize UART once and send the
       buffer there, then pass the write through to the TRK console handler. */
    s32 initResult;

    if (!(OSGetConsoleType() & 0x20000000)) {
        initResult = 0;
        if (lbl_8055D688 == 0) {
            initResult = fn_8009D000(0xE100);
            if (initResult == 0) {
                lbl_8055D688 = 1;
            }
        }
        if (initResult != 0) {
            return 1;
        }
        if (WriteUARTN(buffer, *count) != 0) {
            *count = 0;
            return 1;
        }
    }
    fn_800300FC(file, buffer, count, mode);
    return 0;
}
