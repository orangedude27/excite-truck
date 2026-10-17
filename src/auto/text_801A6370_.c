// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562418;
extern float lbl_8056241C;
extern float lbl_80562420;
extern float lbl_80562428;
extern float *fn_80265D98(void);
extern void fn_8012F57C(int, void *, void *, float);
float fn_801A6370(float arg0, float arg1, float arg2, float arg3) {
    return arg0 + arg1 * arg3 + arg3 * (lbl_80562418 * arg2 * arg3);
}

float fn_801A6390(int arg0, int arg1) {
    int delta = arg0 - arg1;
    return lbl_8056241C * (float)delta;
}

float fn_801A63C4(int arg0, int arg1) {
    return (lbl_80562428 * fn_801A6390(arg0, arg1)) / lbl_8056241C;
}

void fn_801A63F4(void *arg0, void *arg1, void *arg2, void *arg3) {
    float *out = (float *)arg0;
    float *a = (float *)arg1;
    float *b = (float *)arg2;
    float *t = (float *)arg3;
    float ax = a[0], ay = a[1], az = a[2];
    float bx = b[0], by = b[1], bz = b[2];
    float tx = t[0], ty = t[1], tz = t[2];
    out[2] = az + tz * (bz - az);
    out[1] = ay + ty * (by - ay);
    out[0] = ax + tx * (bx - ax);
}

void fn_801A6520(void) {

}

extern void fn_8018381C(void);
extern void fn_801A6558(void *);
extern void fn_801A67B0(void *);
extern void *fn_802E2C20(void);
extern void fn_80182010(void);
extern void *fn_801A644C(void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern void *memset(void *, int, unsigned int);
extern float lbl_8056242C;
extern float lbl_80562430;
extern char lbl_80333CA8;
extern char lbl_80333CB8;
extern void fn_801A6520(void);
void fn_801A6524(void *arg0) {
    fn_8018381C();
    fn_801A6558(arg0);
}

void fn_801A6558(void *arg0) {
    *(int *)((char *)arg0 + 0x2778) = 4;
    *(void **)((char *)arg0 + 0x277C) = fn_802E2C20();
    *(float *)((char *)arg0 + 0x273C) = lbl_8056242C;
    *(float *)((char *)arg0 + 0x2738) = lbl_8056242C;
    *(int *)((char *)arg0 + 0x2704) = 0;
    *(float *)((char *)arg0 + 0x272C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2730) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2734) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2708) = lbl_80562430;
    *(float *)((char *)arg0 + 0x270C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2710) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2714) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2718) = lbl_80562430;
    *(float *)((char *)arg0 + 0x271C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2720) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2724) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2728) = lbl_80562430;
    memset(*(void **)((char *)arg0 + 0x2700), 0, 0xE7);
    if (*(unsigned char *)((char *)arg0 + 0x2740))
        fn_801A67B0(arg0);
}

