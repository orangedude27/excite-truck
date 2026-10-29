// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_805599E8;
extern unsigned char lbl_80422F40[];
extern signed char lbl_8032AFE0[];
#pragma dont_inline on
unsigned char fn_8012F7E0(signed char arg0) {
    int i, j;
    signed char index;
    if (lbl_805599E8 != 0) {
        lbl_805599E8 = 0;
        memset(&lbl_80422F40, 0xFF, 0x100);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 16; j++) {
                index = *((signed char *)&lbl_8032AFE0 + i * 16 + j);
                *((unsigned char *)&lbl_80422F40 + index) = i * 16 + j;
            }
        }
    }
    return *((unsigned char *)&lbl_80422F40 + arg0);
}

extern int strlen(const char *);
extern int fn_8012F968(unsigned char *);
int fn_8012F9E8(unsigned char *out, int max, unsigned char *in) {
    int len = strlen((const char *)in);
    int ok = 1;
    if (len & 3) return 0;
    {
        int inpos = 0;
        int outpos = 0;
        while (inpos < len && outpos < max) {
            int value = fn_8012F968(in + inpos);
            if (!(value & 0xFF000000)) {
                volatile unsigned char *dst = out + outpos;
                int shift = 16;
                while (outpos < max && shift >= 0) {
                    *dst = (unsigned int)value >> shift;
                    shift -= 8;
                    outpos++;
                    dst++;
                }
            } else {
                ok = 0;
                break;
            }
            inpos += 4;
        }
    }
    return ok;
}

#pragma dont_inline off
