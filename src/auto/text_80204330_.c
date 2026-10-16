// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055ED48;
extern int fn_802E2C20(void);
int fn_80204354(void);
extern float lbl_80563168, lbl_8056316C, lbl_80563170, lbl_80563174, lbl_80563178, lbl_8056317C;
extern double lbl_80563180;
int fn_80204354(void) { return fn_802E2C20() - (int)lbl_8055ED48; }

int fn_802E2C20(void);
extern int fn_80145E70(void*);
extern char lbl_8033BB18[];
extern int lbl_8055ED3C, lbl_8055ED40, lbl_8055ED44;
unsigned int fn_8020437C(void) {
    unsigned int temp = (unsigned int)fn_80204354() ^ 0xDAC;
    return ((temp >> 1) - (temp & 0xDAC)) >> 31;
}

void fn_802043B0(int *arg0) {
 float val = lbl_80563168;
 float temp = ((float)fn_80204354() - lbl_8056316C) / lbl_80563170;
 int packed;
 if (val < temp) val = temp;
 if (val > lbl_80563174) val = lbl_80563174;
 packed = *arg0 & 0xFFFFFF;
 *arg0 = packed;
 *arg0 = packed | ((int)(lbl_80563178 + val * lbl_8056317C) << 24);
}

void fn_80204460(void) {
    lbl_8055ED3C = 0;
    lbl_8055ED40 = 0;
    lbl_8055ED48 = 0;
    lbl_8055ED44 = fn_80145E70(lbl_8033BB18);
}

void fn_80204A50(void) {
    fn_80204330();
}
