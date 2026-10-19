// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    float x, y, z;
    int id;
    float u, v;
} TrailPt;

extern int lbl_8055EA6C;
extern int lbl_8055EA64;
extern int fn_802CAC54(int);
extern int fn_802C6CF8(int);
extern int lbl_8055EA6C, lbl_8055EA64;
extern float lbl_8055EA68, lbl_80562D08;
extern int lbl_80339910, lbl_80339920;
extern int fn_802CAC28(int *, int);
extern int fn_802C6FC0(int *, int, int);
extern int fn_802C7760(int *, float *, int *, int *, float *, int *);
void fn_801E3C04(void) {
    int a, c, d, f;
    float b, e;
    lbl_8055EA6C = fn_802CAC28(&lbl_80339910, 0);
    lbl_8055EA64 = fn_802C6FC0(&lbl_80339920, 0, 0);
    fn_802C7760(&a, &b, &c, &d, &e, &f);
    lbl_8055EA68 = fabsf(e - b) * lbl_80562D08;
}

void fn_801E3C88(void) {
    fn_802CAC54(lbl_8055EA6C);
    fn_802C6CF8(lbl_8055EA64);
}

extern float lbl_8055EA68, lbl_80562CF4;
extern int fn_802C744C(int, float *);
extern int fn_801E4040(void *, void *, int);
void fn_801E41D8(void *arg0, void *arg1, int arg2) {
    fn_801E4040(arg0, arg1, arg2);
}

extern void fn_801E370C(float *, int, float, float, float, float, float, float, float, float, float, float, float);
void fn_801E44F4(void *arg0, int arg1, float farg0, float farg1, float farg2) {
    float sp[12];
    sp[0] = *(float *)((char *)arg0 + 0x0) * farg0;
    sp[1] = *(float *)((char *)arg0 + 0x4) * farg0;
    sp[2] = *(float *)((char *)arg0 + 0x8) * farg0;
    sp[3] = *(float *)((char *)arg0 + 0xC) * farg1;
    sp[4] = *(float *)((char *)arg0 + 0x10) * farg1;
    sp[5] = *(float *)((char *)arg0 + 0x14) * farg1;
    sp[6] = *(float *)((char *)arg0 + 0x18) * farg2;
    sp[7] = *(float *)((char *)arg0 + 0x1C) * farg2;
    sp[8] = *(float *)((char *)arg0 + 0x20) * farg2;
    sp[9] = *(float *)((char *)arg0 + 0x24);
    sp[10] = *(float *)((char *)arg0 + 0x28);
    sp[11] = *(float *)((char *)arg0 + 0x2C);
    fn_801E370C(sp, arg1, sp[0], sp[1], sp[2], sp[3], sp[4], sp[5], sp[6], sp[7], sp[8], sp[9], sp[10]);
}

