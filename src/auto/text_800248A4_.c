// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_802FE850[];
int fn_800248A4(unsigned char *a, unsigned char *b, int n) {
    unsigned char *tbl;
    int c1, c2;
    tbl = *(unsigned char **)(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x10);
    while (n > 0) {
        c1 = (signed char)*a++;
        if (c1 >= 0 && c1 < 256)
            c1 = (signed char)tbl[c1];
        c2 = (signed char)*b++;
        if (c2 >= 0 && c2 < 256)
            c2 = (signed char)tbl[c2];
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        if (c1 == 0) return 0;
        n--;
    }
    return 0;
}

extern int lbl_8055D680;
int _ftell(arg0)
void *arg0;
{
    unsigned int temp_r5;
    int var_r6, temp_r4, var_r7, var_ctr;
    unsigned char *var_r8;
    unsigned char temp_r0_2;
    var_r6 = 0;
    if ((unsigned char)(((*(volatile unsigned int *)((char *)arg0 + 4) >> 0x16) & 7) + 0xFF) > 1 ||
        *(unsigned char *)((char *)arg0 + 0xA) != 0) {
        lbl_8055D680 = 0x28; return -1;
    }
    temp_r5 = *(unsigned int *)((char *)arg0 + 8) >> 0x1D;
    if (!temp_r5) return *(int *)((char *)arg0 + 0x18);
    var_r8 = *(unsigned char **)((char *)arg0 + 0x1C);
    temp_r4 = *(int *)((char *)arg0 + 0x24) - (int)var_r8;
    var_r7 = *(int *)((char *)arg0 + 0x34) + temp_r4;
    if (temp_r5 >= 3) { var_r6 = temp_r5 - 2; var_r7 -= var_r6; }
    if (((*(volatile unsigned int *)((char *)arg0 + 4) >> 0x13) & 1) == 0) {
        var_ctr = temp_r4 - var_r6;
        for (; var_ctr != 0; var_ctr--) { temp_r0_2 = *var_r8++; if (temp_r0_2 == 10) var_r7++; }
    }
    return var_r7;
}

void fn_80024A0C(void) {
    _ftell();
}
