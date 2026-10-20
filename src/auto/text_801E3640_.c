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

#pragma push
#pragma processor 750
void fn_801E3CB4(void *arg0, void *arg1, int arg2, float farg0) {
    extern float lbl_80558DC4[];
    extern float lbl_80562CF4;
    extern float lbl_80562CF8;
    extern float lbl_80562CFC;
    extern float lbl_80562D0C;
    extern float lbl_80562D10;
    extern float PSVECMag(float *);
    extern void fn_801E3640(void *, float *);
    extern int fn_801E36F0(int);
    extern unsigned short lbl_802F99E8[];
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *, int, void *, int);
    extern void fn_802C8D74(void);
    extern void fn_802C9904(void);
    float vec[9];
    TrailPt pts[5];
    unsigned short frame[6];
    float scale;
    float mag;
    float s;
    int i;
    int result;

    fn_801E3640(arg1, vec);
    scale = lbl_80562D0C * farg0;
    mag = PSVECMag(&vec[6]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = -farg0 / mag;
        vec[6] = vec[6] * s;
        vec[7] = vec[7] * s;
        vec[8] = vec[8] * s;
    }
    mag = PSVECMag(&vec[0]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = (scale * lbl_80562D08) / mag;
        vec[0] = vec[0] * s;
        vec[1] = vec[1] * s;
        vec[2] = vec[2] * s;
    }
    mag = PSVECMag(&vec[3]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = (scale * lbl_80562D08) / mag;
        vec[3] = vec[3] * s;
        vec[4] = vec[4] * s;
        vec[5] = vec[5] * s;
    }
    pts[0].x = lbl_80562CF4;
    pts[0].y = lbl_80562CF4;
    pts[0].z = lbl_80562CF4;
    pts[1].x = vec[6] + vec[0] * lbl_80562CFC;
    pts[1].y = vec[7] + vec[1] * lbl_80562CFC;
    pts[1].z = vec[8] + vec[2] * lbl_80562CFC;
    pts[2].x = vec[6] + vec[0] * lbl_80562CF8;
    pts[2].y = vec[7] + vec[1] * lbl_80562CF8;
    pts[2].z = vec[8] + vec[2] * lbl_80562CF8;
    pts[3].x = vec[6] + vec[3] * lbl_80562CFC;
    pts[3].y = vec[7] + vec[4] * lbl_80562CFC;
    pts[3].z = vec[8] + vec[5] * lbl_80562CFC;
    pts[4].x = vec[6] + vec[3] * lbl_80562CF8;
    pts[4].y = vec[7] + vec[4] * lbl_80562CF8;
    pts[4].z = vec[8] + vec[5] * lbl_80562CF8;
    result = fn_801E36F0(arg2);
    for (i = 0; i < 5; i++) {
        pts[i].id = arg2;
        pts[i].u = lbl_80562D10 * i;
        pts[i].v = lbl_80562D10 * i;
        pts[i].x = pts[i].x + *(float *)((char *)arg0 + 0x0);
        pts[i].y = pts[i].y + *(float *)((char *)arg0 + 0x4);
        pts[i].z = pts[i].z + *(float *)((char *)arg0 + 0x8);
    }
    pts[0].id = result;
    for (i = 0; i < 6; i++) {
        frame[i] = lbl_802F99E8[i];
    }
    fn_802C8BD0(lbl_8055EA6C);
    fn_802C8DB8(pts, 5, frame, 6);
    fn_802C8D74();
    fn_802C9904();
}
#pragma pop
extern float lbl_8055EA68, lbl_80562CF4;
extern int fn_802C744C(int, float *);
extern int fn_801E4040();
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

