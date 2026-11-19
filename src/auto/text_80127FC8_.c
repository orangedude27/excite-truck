// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern unsigned char lbl_8041E098[];
extern unsigned char lbl_8055DF68;
#pragma scheduling invalid_target
void fn_80127FC8(void) {
    unsigned char *end;
    unsigned char *p;
    unsigned char *start;
    unsigned char *bulkEnd;
    unsigned char *tailEnd;
    int length;
    int rounded;
    int countPlusOne;
    int bulkOK;
    int rangeOK;
    int signedOK;
    int signLength;
    int signRounded;
    unsigned int bulkCount;
    unsigned int tailCount;

    fn_8000D838(&lbl_8055DF68);
    end = lbl_8041E098 + 0xA8;
    p = lbl_8041E098 + 0x18;
    *(int *)(lbl_8041E098 + 0x10) = 0;
    *(int *)(lbl_8041E098 + 8) = 0;
    *(int *)(lbl_8041E098 + 0xC) = 0;
    lbl_8041E098[0x14] = 0;

    if ((unsigned long)p < (unsigned long)end) {
        start = lbl_8041E098 + 0x18;
        length = (int)((unsigned long)end - (unsigned long)start);
        rounded = (length + 0xF) / 16;
        countPlusOne = rounded + 1;
        bulkEnd = lbl_8041E098 + 0x28;
        if (countPlusOne > 8) {
            bulkOK = 0;
            rangeOK = 0;
            if ((unsigned long)start <= (unsigned long)end) {
                signLength = 1;
                if (!(signLength & (int)0x80000000) && ((length + 0xF) & (int)0x80000000)) {
                    signLength = 0;
                }
                if (signLength != 0) {
                    rangeOK = 1;
                }
            }
            if (rangeOK != 0) {
                signRounded = rounded & (int)0x80000000;
                signedOK = 1;
                if ((signRounded == 0) && (signRounded != (countPlusOne & (int)0x80000000))) {
                    signedOK = 0;
                }
                if (signedOK != 0) {
                    bulkOK = 1;
                }
            }
            if (bulkOK != 0) {
                bulkCount = (unsigned int)(((unsigned long)bulkEnd + 0x7F - (unsigned long)p) >> 7);
                if ((unsigned long)p < (unsigned long)bulkEnd) {
                    do {
                        *(int *)(p + 8) = 0;
                        *(int *)(p + 0) = 0;
                        *(int *)(p + 4) = 0;
                        p[0xC] = 0;
                        *(int *)(p + 0x18) = 0;
                        *(int *)(p + 0x10) = 0;
                        *(int *)(p + 0x14) = 0;
                        p[0x1C] = 0;
                        *(int *)(p + 0x28) = 0;
                        *(int *)(p + 0x20) = 0;
                        *(int *)(p + 0x24) = 0;
                        p[0x2C] = 0;
                        *(int *)(p + 0x38) = 0;
                        *(int *)(p + 0x30) = 0;
                        *(int *)(p + 0x34) = 0;
                        p[0x3C] = 0;
                        *(int *)(p + 0x48) = 0;
                        *(int *)(p + 0x40) = 0;
                        *(int *)(p + 0x44) = 0;
                        p[0x4C] = 0;
                        *(int *)(p + 0x58) = 0;
                        *(int *)(p + 0x50) = 0;
                        *(int *)(p + 0x54) = 0;
                        p[0x5C] = 0;
                        *(int *)(p + 0x68) = 0;
                        *(int *)(p + 0x60) = 0;
                        *(int *)(p + 0x64) = 0;
                        p[0x6C] = 0;
                        *(int *)(p + 0x78) = 0;
                        *(int *)(p + 0x70) = 0;
                        *(int *)(p + 0x74) = 0;
                        p[0x7C] = 0;
                        p += 0x80;
                        bulkCount--;
                    } while (bulkCount != 0);
                }
            }
        }
        tailEnd = lbl_8041E098 + 0xA8;
        tailCount = (unsigned int)(((unsigned long)tailEnd + 0xF - (unsigned long)p) >> 4);
        if ((unsigned long)p < (unsigned long)tailEnd) {
            do {
                *(int *)(p + 8) = 0;
                *(int *)(p + 0) = 0;
                *(int *)(p + 4) = 0;
                p[0xC] = 0;
                p += 0x10;
                tailCount--;
            } while (tailCount != 0);
        }
    }
    lbl_8041E098[0] = 0;
    *(int *)(lbl_8041E098 + 4) = 0;
}
