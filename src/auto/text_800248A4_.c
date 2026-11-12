// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_802FE850[];
int fn_800248A4(unsigned char *a, unsigned char *b, int n) {
    unsigned int locale;
    register int c asm("r7") = 0;
    register int scratch asm("r0") = 0;
    register int first asm("r8") = 0;
    int raw = 0;
    locale = *(volatile unsigned int *)(lbl_802FE850 + 0x38);
    while (n > 0) {
        c = (signed char)*a++;
        scratch = 0;
        if (c < 0 || c >= 256) scratch = 1;
        if (scratch == 0) goto l1;
        goto a1;
l1:
        c = *(unsigned char *)(*(unsigned int *)(locale + 16) + c);
a1:
        raw = *b++;
        first = (signed char)c;
        c = (signed char)raw;
        scratch = 0;
        if (c < 0 || c >= 256) scratch = 1;
        if (scratch == 0) goto l2;
        goto a2;
l2:
        c = *(unsigned char *)(*(unsigned int *)(locale + 16) + c);
a2:
        scratch = (signed char)c;
        if (first < scratch) return -1;
        if (first > scratch) return 1;
        if (first == 0) return 0;
        n--;
    }
    return 0;
}

extern int lbl_8055D680;
int _ftell(file)
void *file;
{
    /* Return the current file position for a stream, accounting for buffer/undo state and newlines; sets errno on invalid stream. */
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

void fn_80024A0C(void) {
    _ftell();
}
