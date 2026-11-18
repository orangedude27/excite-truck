// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void fn_801D1C68(void *arg0, int arg1) {
    int offset;
    volatile unsigned char *record;
    int i;
    unsigned char *relocRecord;
    unsigned char b;
    unsigned char a;
    unsigned int value;

    if (((unsigned int *)arg0)[0] != 0) ((unsigned int *)arg0)[0] = ((unsigned int *)arg0)[0] + arg1; else ((unsigned int *)arg0)[0] = 0;
    if (((unsigned int *)arg0)[1] != 0) ((unsigned int *)arg0)[1] = ((unsigned int *)arg0)[1] + arg1; else ((unsigned int *)arg0)[1] = 0;
    if (((unsigned int *)arg0)[2] != 0) ((unsigned int *)arg0)[2] = ((unsigned int *)arg0)[2] + arg1; else ((unsigned int *)arg0)[2] = 0;
    if (((unsigned int *)arg0)[3] != 0) ((unsigned int *)arg0)[3] = ((unsigned int *)arg0)[3] + arg1; else ((unsigned int *)arg0)[3] = 0;

    i = 0;
    offset = 0;
    goto check20;
loop20:
    i++;
    record = (unsigned char *)((unsigned int *)arg0)[0] + offset;
    a = *((unsigned char *)((unsigned int *)arg0)[0] + offset);
    b = record[3];
    offset += 0x14;
    record[0] = b;
    record[3] = a;
    a = record[1];
    b = record[2];
    record[1] = b;
    record[2] = a;
    a = record[4];
    b = record[7];
    record[4] = b;
    record[7] = a;
    a = record[5];
    b = record[6];
    record[5] = b;
    record[6] = a;
    a = record[8];
    b = record[11];
    record[8] = b;
    record[11] = a;
    a = record[9];
    b = record[10];
    record[9] = b;
    record[10] = a;
    a = record[12];
    b = record[15];
    record[12] = b;
    record[15] = a;
    a = record[13];
    b = record[14];
    record[13] = b;
    record[14] = a;
    a = record[16];
    b = record[19];
    record[16] = b;
    record[19] = a;
    a = record[17];
    b = record[18];
    record[17] = b;
    record[18] = a;
check20:
    if (i < ((int *)arg0)[4]) goto loop20;

    i = 0;
    offset = 0;
    goto check16;
loop16:
    i++;
    record = (unsigned char *)((unsigned int *)arg0)[1] + offset;
    a = *((unsigned char *)((unsigned int *)arg0)[1] + offset);
    b = record[3];
    offset += 0x10;
    record[0] = b;
    record[3] = a;
    a = record[1];
    b = record[2];
    record[1] = b;
    record[2] = a;
    a = record[4];
    b = record[7];
    record[4] = b;
    record[7] = a;
    a = record[5];
    b = record[6];
    record[5] = b;
    record[6] = a;
    a = record[8];
    b = record[11];
    record[8] = b;
    record[11] = a;
    a = record[9];
    b = record[10];
    record[9] = b;
    record[10] = a;
    a = record[12];
    b = record[15];
    record[12] = b;
    record[15] = a;
    a = record[13];
    b = record[14];
    record[13] = b;
    record[14] = a;
check16:
    if (i < ((int *)arg0)[5]) goto loop16;

    i = 0;
    offset = 0;
    goto check12;
loop12:
    i++;
    record = (unsigned char *)((unsigned int *)arg0)[2] + offset;
    a = *((unsigned char *)((unsigned int *)arg0)[2] + offset);
    b = record[3];
    record[0] = b;
    record[3] = a;
    a = record[1];
    b = record[2];
    record[1] = b;
    record[2] = a;
    a = record[4];
    b = record[7];
    record[4] = b;
    record[7] = a;
    a = record[5];
    b = record[6];
    record[5] = b;
    record[6] = a;
    a = record[8];
    b = record[11];
    record[8] = b;
    record[11] = a;
    a = record[9];
    b = record[10];
    record[9] = b;
    record[10] = a;
    relocRecord = (unsigned char *)((unsigned int *)arg0)[2] + offset;
    value = *(unsigned int *)(relocRecord + 8);
    offset += 0xC;
    *(unsigned int *)(relocRecord + 8) = ((unsigned int *)arg0)[0] + value * 0x14;
check12:
    if (i < ((int *)arg0)[6]) goto loop12;

    i = 0;
    offset = 0;
    goto check28;
loop28:
    i++;
    record = (unsigned char *)((unsigned int *)arg0)[3] + offset;
    a = *((unsigned char *)((unsigned int *)arg0)[3] + offset);
    b = record[3];
    offset += 0x1c;
    record[0] = b;
    record[3] = a;
    a = record[1];
    b = record[2];
    record[1] = b;
    record[2] = a;
    a = record[4];
    b = record[7];
    record[4] = b;
    record[7] = a;
    a = record[5];
    b = record[6];
    record[5] = b;
    record[6] = a;
    a = record[8];
    b = record[11];
    record[8] = b;
    record[11] = a;
    a = record[9];
    b = record[10];
    record[9] = b;
    record[10] = a;
    a = record[12];
    b = record[15];
    record[12] = b;
    record[15] = a;
    a = record[13];
    b = record[14];
    record[13] = b;
    record[14] = a;
    a = record[16];
    b = record[19];
    record[16] = b;
    record[19] = a;
    a = record[17];
    b = record[18];
    record[17] = b;
    record[18] = a;
    a = record[20];
    b = record[23];
    record[20] = b;
    record[23] = a;
    a = record[21];
    b = record[22];
    record[21] = b;
    record[22] = a;
    a = record[24];
    b = record[27];
    record[24] = b;
    record[27] = a;
    a = record[25];
    b = record[26];
    record[25] = b;
    record[26] = a;
check28:
    if (i < ((int *)arg0)[7]) goto loop28;
}

void *fn_8012C370(unsigned int, int *, int, int, unsigned char *);
void fn_802E317C(const char *, ...);
extern char lbl_80338268[];
extern char lbl_80338284[];
#pragma push
#pragma dont_inline off
void *fn_801D2008(void *arg0) {
    int error = 0;
    unsigned char swap = 1;
    unsigned char *result;
    volatile unsigned char *p;
    unsigned char b;
    unsigned char a;
    int i;

    result = (unsigned char *)((void *(*)(void *, unsigned int, int *, int, int, unsigned char *))fn_8012C370)(arg0, 0x434D7368, &error, 0, 0, &swap);
    if (result == 0) {
        fn_802E317C(lbl_80338268, arg0);
    }
    if (error != 0) {
        fn_802E317C(lbl_80338284, error, 0);
    }
    if (swap != 0) {
        p = result;
        for (i = 0; i < 8; i++) {
            a = p[0]; b = p[3]; p[0] = b; p[3] = a;
            a = p[1]; b = p[2]; p[1] = b; p[2] = a;
            a = p[4]; b = p[7]; p[4] = b; p[7] = a;
            a = p[5]; b = p[6]; p[5] = b; p[6] = a;
            a = p[8]; b = p[11]; p[8] = b; p[11] = a;
            a = p[9]; b = p[10]; p[9] = b; p[10] = a;
            a = p[12]; b = p[15]; p[12] = b; p[15] = a;
            a = p[13]; b = p[14]; p[13] = b; p[14] = a;
            a = p[16]; b = p[19]; p[16] = b; p[19] = a;
            a = p[17]; b = p[18]; p[17] = b; p[18] = a;
            a = p[20]; b = p[23]; p[20] = b; p[23] = a;
            a = p[21]; b = p[22]; p[21] = b; p[22] = a;
            a = p[24]; b = p[27]; p[24] = b; p[27] = a;
            a = p[25]; b = p[26]; p[25] = b; p[26] = a;
            p += 0x1c;
        }
        fn_801D1C68(result, (int)result);
    }
    return result;
}
#pragma pop
void fn_801D21B4(void) {
    fn_8012C4D8();
}
