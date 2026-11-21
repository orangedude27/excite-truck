/* Locale-aware string comparison and the MSL stream-position (ftell) helper,
 * from SDK/MSL code that had no original source file. */

/* Global locale state: +0x38 holds the active locale, whose +0x10 is the
 * character collation table used by the comparison below. */
extern unsigned char lbl_802FE850[];
int fn_800248A4(unsigned char *str1, unsigned char *str2, int n)
{
    /* Locale-aware strncmp: compare up to n bytes of two strings through the active
       locale's collation table, returning -1, 0, or 1. */
    register int locale;
    register int c1;
    register int c2;
    register signed char sc1;
    register unsigned char skip;
    locale = *(int *)(lbl_802FE850 + 0x38);
    while (n > 0) {
        skip = (c1 = (signed char)*str1, str1++, c1 < 0 || c1 >= 256);
        c1 = (skip != 0) ? c1 : (unsigned char)*(unsigned char *)(*(int *)(locale + 0x10) + c1);
        sc1 = (signed char)c1;
        skip = (c2 = (signed char)*str2, str2++, c2 < 0 || c2 >= 256);
        c2 = (skip != 0) ? c2 : (unsigned char)*(unsigned char *)(*(int *)(locale + 0x10) + c2);
        if (sc1 < (signed char)c2) return -1;
        if (sc1 > (signed char)c2) return 1;
        if (sc1 == 0) return 0;
        n--;
    }
    return 0;
}

extern int lbl_8055D680;
int _ftell(file)
void *file;
{
    /* Return the current file position for a stream, accounting for buffer/undo state and newlines in text mode; sets errno on invalid stream. */
    unsigned int ioState;
    int wideCharAdjust, bufferUsed, position, charsToScan;
    unsigned char *bufferPtr;
    unsigned char ch;
    wideCharAdjust = 0;
    if ((unsigned char)(((*(volatile unsigned int *)((char *)file + 4) >> 0x16) & 7) + 0xFF) > 1 ||
        *(unsigned char *)((char *)file + 0xA) != 0) {
        lbl_8055D680 = 0x28; return -1;
    }
    ioState = *(unsigned int *)((char *)file + 8) >> 0x1D;
    if (!ioState) return *(int *)((char *)file + 0x18);
    bufferPtr = *(unsigned char **)((char *)file + 0x1C);
    bufferUsed = *(int *)((char *)file + 0x24) - (int)bufferPtr;
    position = *(int *)((char *)file + 0x34) + bufferUsed;
    if (ioState >= 3) { wideCharAdjust = ioState - 2; position -= wideCharAdjust; }
    if (((*(volatile unsigned int *)((char *)file + 4) >> 0x13) & 1) == 0) {
        charsToScan = bufferUsed - wideCharAdjust;
        for (; charsToScan != 0; charsToScan--) { ch = *bufferPtr++; if (ch == 10) position++; }
    }
    return position;
}

/* MSL ftell thunk: tail-call _ftell to report the current position of a stream. */
void fn_80024A0C(void) {
    _ftell();
}
