// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80565160, lbl_80565164, lbl_80565168, lbl_8056516C;
extern float lbl_80565170, lbl_80565174, lbl_80565178;
extern int lbl_8055D208, lbl_8055D210, lbl_8055D218, lbl_8055D220;
extern int lbl_8034D898, lbl_8034D8A8;
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
int fn_802E77B8(void) { return 0; }

void *fn_802E77C0(int x) {
    if (x == -2) return &lbl_8055D210;
    if (x < -2) {
        if (x == -4) return &lbl_8034D8A8;
        if (x >= -4) goto fallback;
        goto fallback;
    }
    if (x == 0) return &lbl_8055D208;
    if (x < 0) return &lbl_8034D898;
fallback:
    if (x == -4) return &lbl_8055D218;
    return &lbl_8055D220;
}

float fn_802E7824(float arg0, float arg1) {
    float top = lbl_80565160;
    float low = lbl_80565164;
    float scale = top / (top - arg1);
    if (arg0 != low) {
        float value = scale * (arg0 + arg1);
        if (value < low) value = low;
        if (value > lbl_8056516C) value = lbl_8056516C;
        return value;
    } else {
        float value = scale * (arg0 - arg1);
        if (value < lbl_80565168) value = lbl_80565168;
        if (value > low) value = low;
        return value;
    }
}

float fn_802E78A4(float x) {
    float t;
    t = fn_802E7824(lbl_80565174 + x, lbl_80565178);
    x = fn_802E7824(x - lbl_80565174, lbl_80565178);
    x = lbl_80565170 * (x + t);
    return x + lbl_80565164 * (x * __fabs(x) - x);
}

extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
void fn_802E7A14(int arg0) {
    fn_801282EC(0x80);
    fn_801282F4();
    lbl_80507258[lbl_8056000C] = fn_801284E8(&lbl_8055D224, arg0);
    lbl_8056000C++;
}

