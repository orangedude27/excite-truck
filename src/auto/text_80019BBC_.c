// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_803583C8;
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern float lbl_80560418;
extern float lbl_8056041C;
extern float lbl_803582C0;
extern double cos(double);
extern double sin(double);
void fn_80019BBC(void) {
    float angle = lbl_80560418;
    float step = lbl_8056041C;
    float initial = angle;
    float *p = &lbl_803582C0;
    int i = 0;
    do {
        *p++ = (float)cos(angle);
        p[0] = (float)sin(angle);
        p[1] = initial;
        p += 2;
        angle += step;
        i++;
    } while (i < 20);
    ((float *)&lbl_803582C0)[60] = lbl_80560418;
    ((float *)&lbl_803582C0)[61] = lbl_80560418;
    ((float *)&lbl_803582C0)[62] = lbl_80560418;
}

void fn_8001A1F0(void) {
}

void fn_8001B7B8(void) {
    fn_802D3050();
}
extern int lbl_803583C8;
extern float lbl_80560418;
extern float lbl_8056041C;
extern float lbl_803582C0;
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern double cos(double);
extern double sin(double);
