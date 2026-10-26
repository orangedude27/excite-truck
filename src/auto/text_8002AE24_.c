// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned long __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
extern int __StringRead(void *, int, int);
extern __declspec(section ".sdata") int lbl_8055D680;
int atoi(const char *str) {
    unsigned long sp18[2];
    int overflow;
    int negative;
    int count;
    unsigned long value;
    int error_result;

    sp18[0] = (unsigned long)str;
    sp18[1] = 0;
    value = __strtoul(10, 0x7FFFFFFF, __StringRead, sp18,
                     &count, &negative, &overflow);

    if (overflow || ((!negative) && (value > 0x7FFFFFFF)) ||
                    (negative && (value > 0x80000000))) {
        error_result = negative ? (int)0x80000000U : 0x7FFFFFFF;
        lbl_8055D680 = 0x22;
        return error_result;
    }
    if (negative) {
        value = (unsigned long)-(long)value;
    }
    return (int)value;
}
