// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80272354(void);
extern void fn_8002F634(void *, void *, int, int);
extern void fn_80015B20(void *, void *, void *);
extern void fn_801BFD34(void *, void *, void *);
extern float PSVECMag(float *);
extern double sin(double);
extern double cos(double);
extern float lbl_80564024, lbl_80564020, lbl_80563FAC, lbl_80563FB0, lbl_80563FA8;
extern float lbl_80564010, lbl_80564014, lbl_80564018, lbl_8056401C;
extern float lbl_802FA788[];
extern char lbl_80347364[];
extern char lbl_8049A2C8[];
extern char lbl_8049F9D8[];
extern int fn_80273B08(int, int);
extern void fn_80273978(void);
void fn_80273A88(void) {
    fn_8002F634(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}

void fn_80273AA4(void *arg0) {
    *(int *)arg0 = 0;
    *(char **)((char *)arg0 + 0x18) = lbl_80347364;
}

int fn_80273ABC(int arg0) {
    fn_80272354();
    return arg0;
}

void fn_80273AEC(void) {
    fn_8002F634(lbl_8049A2C8, fn_80273B08, 0x60, 0xC8);
}

int fn_80273B08(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        extern int fn_80128668(void);
        fn_80128668();
    }
    return arg0;
}

void fn_80273B48(void) {
}

void fn_80273B4C(void *arg0) {
    extern void fn_80015A20(void *, float *, float, float);
    extern void fn_80015B20(void *, void *, void *);
    extern float lbl_80563FA8, lbl_80563FAC, lbl_80563FB0, lbl_80563FB4;
    void *temp_r4 = *(void **)((char *)arg0 + 0x140);
    char out[0x24];
    float vec[3];
    float var_f1;
    float product;
    void *temp_r3;
    if (temp_r4 != 0) {
        if (*(unsigned char *)((char *)temp_r4 + 0x260C) != 0) var_f1 = lbl_80563FA8;
        else var_f1 = lbl_80563FAC;
        vec[0] = lbl_80563FB0;
        product = lbl_80563FB0 * lbl_80563FB4;
        vec[1] = product * var_f1;
        vec[2] = lbl_80563FB0;
        fn_80015A20(out, vec, var_f1, lbl_80563FB0);
        temp_r3 = (char *)arg0 + 0x58;
        fn_80015B20(temp_r3, out, (void *)((char *)arg0 + 0x58));
    }
}

void fn_8027445C(void) {
    extern void fn_80274268(void);
    fn_80274268();
}

extern float PSQUATMultiply(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern void PSVECNormalize(void *, void *);
extern double atan(double), fn_8002EF30(float), fabs(double);
extern float lbl_80558DC4[];
extern float  lbl_80563FC4, lbl_80563FD8, lbl_80563FFC, lbl_80564000, lbl_80564004, lbl_80564008, lbl_8056400C;
extern float lbl_80558DC4[];
extern float  lbl_80563FC4, lbl_80563FD8, lbl_80563FFC, lbl_80564000, lbl_80564004, lbl_80564008, lbl_8056400C;
#pragma push
#pragma processor 750
int fn_80274730(void *arg0, float arg1, float arg2, float arg3, float arg4) {
    float up[3], forward[3], side[3], right[3];
    char *p=arg0;
    float x,y,z,d,scale,dist,lower,angle,ratio,speed,v;
    x=(*(float *)(p+0x4c))-(*(float *)(p+0x7c)); y=(*(float *)(p+0x50))-(*(float *)(p+0x80)); z=(*(float *)(p+0x54))-(*(float *)(p+0x84));
    (*(float *)(p+0x70))=x; (*(float *)(p+0x74))=y; (*(float *)(p+0x78))=z;
    if ((float)__fabs(x)<=lbl_80558DC4[0] && (float)__fabs(z)<=lbl_80558DC4[0]) {
        x=(*(float *)(p+0xd8)); z=(*(float *)(p+0xe0)); (*(float *)(p+0x70))=x; (*(float *)(p+0x78))=z;
    }
    up[0]=lbl_80563FB0; up[1]=lbl_80563FAC; up[2]=lbl_80563FB0;
    PSVECCrossProduct(up,p+0x70,p+0x58);
    PSVECCrossProduct(p+0x70,p+0x58,p+0x64);
    x=(*(float *)(p+0x58)); y=(*(float *)(p+0x5c)); z=(*(float *)(p+0x60)); right[0]=x; right[1]=y; right[2]=z;
    x=(*(float *)(p+0x70)); y=(*(float *)(p+0x74)); z=(*(float *)(p+0x78)); forward[0]=x; forward[1]=y; forward[2]=z;
    PSVECCrossProduct(forward,right,side);
    PSVECNormalize(right,right); PSVECNormalize(side,side);
    PSVECCrossProduct(right,side,forward);
    (*(float *)(p+0x58))=right[0]; (*(float *)(p+0x5c))=right[1]; (*(float *)(p+0x60))=right[2];
    (*(float *)(p+0x64))=side[0]; (*(float *)(p+0x68))=side[1]; (*(float *)(p+0x6c))=side[2];
    (*(float *)(p+0x70))=forward[0]; (*(float *)(p+0x74))=forward[1]; (*(float *)(p+0x78))=forward[2];
    d=PSQUATMultiply(p+0x7c,p+0x4c);
    if (arg2>lbl_80563FB0) {
        scale=(lbl_80563FAC-arg4)*(d-arg2);
        x=(*(float *)(p+0x7c))+(*(float *)(p+0x70))*scale; y=(*(float *)(p+0x80))+(*(float *)(p+0x74))*scale; z=(*(float *)(p+0x84))+(*(float *)(p+0x78))*scale;
        (*(float *)(p+0x7c))=x; (*(float *)(p+0x80))=y; (*(float *)(p+0x84))=z;
    }
    dist=PSQUATMultiply(p+0x7c,p+0x4c);
    lower=lbl_80563FFC; angle=lbl_80564000; v=lbl_80564004;
    if (arg3>lbl_80564008) ratio=lbl_80563FAC/arg3; else ratio=lbl_80563FAC;
    speed=lbl_8056400C*ratio;
    v=lbl_80563FD8*(float)atan((speed/dist)*(float)fn_8002EF30(v*lbl_80563FC4));
    angle=angle<v?angle:v;
    angle=angle>lower?angle:lower;
    if(arg1>lbl_80563FB0) { (*(float *)(p+0xbc))=arg1; (*(float *)(p+0x194))=arg1; }
    else { v=(*(float *)(p+0x194)); v=v+lbl_80563FAC*(angle-v); (*(float *)(p+0xbc))=v; (*(float *)(p+0x194))=v; }
    v=lbl_80563FB0; (*(float *)(p+0x120))=v; (*(float *)(p+0x124))=v; (*(float *)(p+0x128))=v;
}

extern float lbl_80563FA8, lbl_80563FB0;
void fn_80274E94(void *arg0) {
    fn_80274730(arg0, lbl_80563FA8, lbl_80563FA8, lbl_80563FA8, lbl_80563FB0);
}

#pragma pop

extern float PSVECDotProduct(float *, float *);
extern void fn_8026E850(float *, float *, void *, float *);
void fn_802750C4(void *arg0, float arg1, float arg2) {
    float sp8[3];
    float sp14[3];
    float dot;
    float scale;
    sp8[0] = lbl_80563FB0;
    sp8[1] = lbl_80563FAC;
    sp8[2] = lbl_80563FB0;
    fn_8026E850((float *)((char *)arg0 + 0x7C), (float *)((char *)arg0 + 0xE4), arg0, sp8);
    sp14[0] = *(float *)((char *)arg0 + 0xE4) - *(float *)((char *)arg0 + 0x7C);
    sp14[1] = *(float *)((char *)arg0 + 0xE8) - *(float *)((char *)arg0 + 0x80);
    sp14[2] = *(float *)((char *)arg0 + 0xEC) - *(float *)((char *)arg0 + 0x84);
    dot = PSVECDotProduct((float *)((char *)arg0 + 0x70), sp14);
    scale = (dot - arg2) * arg1;
    *(float *)((char *)arg0 + 0x7C) += *(float *)((char *)arg0 + 0x70) * scale;
    *(float *)((char *)arg0 + 0x80) += *(float *)((char *)arg0 + 0x74) * scale;
    *(float *)((char *)arg0 + 0x84) += *(float *)((char *)arg0 + 0x78) * scale;
}

void fn_802751AC(void *arg0, float angle) {
    float axis[3], input[3], matrix[12];
    float mag, scale, x, y, z, s, c, t;
    unsigned int *src = (unsigned int *)((char *)arg0 + 0xC0);
    unsigned int *dst = (unsigned int *)((char *)arg0 + 0x58);
    int i;
    for (i = 0; i < 12; i++) dst[i] = src[i];
    input[0] = lbl_80564024 * lbl_802FA788[3];
    input[1] = lbl_80564024 * lbl_802FA788[4];
    input[2] = lbl_80564024 * lbl_802FA788[5];
    axis[0] = lbl_802FA788[0]; axis[1] = lbl_802FA788[1]; axis[2] = lbl_802FA788[2];
    mag = PSVECMag(input);
    if (mag > lbl_80564020) {
        scale = lbl_80563FAC / mag;
        x = input[0] * scale; y = input[1] * scale; z = input[2] * scale;
        s = (float)sin(angle); c = (float)cos(angle); t = lbl_80563FAC - c;
        matrix[0] = c + t * x * x;
        matrix[1] = y * (t * x) + s * z;
        matrix[2] = z * (t * x) - s * y;
        matrix[3] = y * (t * x) - s * z;
        matrix[4] = c + t * y * y;
        matrix[5] = z * (t * y) + s * x;
        matrix[6] = z * (t * x) + s * y;
        matrix[7] = z * (t * y) - s * x;
        matrix[8] = c + t * z * z;
    } else {
        matrix[0] = lbl_80563FAC; matrix[1] = lbl_80563FB0; matrix[2] = lbl_80563FB0;
        matrix[3] = lbl_80563FB0; matrix[4] = lbl_80563FAC; matrix[5] = lbl_80563FB0;
        matrix[6] = lbl_80563FB0; matrix[7] = lbl_80563FB0; matrix[8] = lbl_80563FAC;
    }
    fn_801BFD34((char *)arg0 + 0x7C, axis, (char *)arg0 + 0xC0);
    fn_80015B20((char *)arg0 + 0x58, matrix, (char *)arg0 + 0xC0);
    *(float *)((char *)arg0 + 0xBC) = lbl_80564024 * angle;
}

void fn_80275FC0(void *arg0) {
    *(int *)((char *)arg0 + 0x58) = *(int *)((char *)arg0 + 0x1A4);
    *(int *)((char *)arg0 + 0x5C) = *(int *)((char *)arg0 + 0x1A8);
    *(int *)((char *)arg0 + 0x60) = *(int *)((char *)arg0 + 0x1AC);
    *(int *)((char *)arg0 + 0x64) = *(int *)((char *)arg0 + 0x1B0);
    *(int *)((char *)arg0 + 0x68) = *(int *)((char *)arg0 + 0x1B4);
    *(int *)((char *)arg0 + 0x6C) = *(int *)((char *)arg0 + 0x1B8);
    *(int *)((char *)arg0 + 0x70) = *(int *)((char *)arg0 + 0x1BC);
    *(int *)((char *)arg0 + 0x74) = *(int *)((char *)arg0 + 0x1C0);
    *(int *)((char *)arg0 + 0x78) = *(int *)((char *)arg0 + 0x1C4);
    *(int *)((char *)arg0 + 0x7C) = *(int *)((char *)arg0 + 0x1C8);
    *(int *)((char *)arg0 + 0x80) = *(int *)((char *)arg0 + 0x1CC);
    *(int *)((char *)arg0 + 0x84) = *(int *)((char *)arg0 + 0x1D0);
    *(float *)((char *)arg0 + 0xBC) = *(float *)((char *)arg0 + 0x1D4);
}

void fn_80276044(int arg0) {
    fn_80276BE4(arg0 + 0x58, arg0 + 0xBC);
}

int fn_802704D4(int, int);
int fn_80276BE4(int, int);
int fn_80274730(void *, float, float, float, float);
void fn_80276054(int arg0) {
    fn_802704D4(4, arg0);
}

