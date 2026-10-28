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
#pragma scheduling invalid_target
void fn_80273A88(void) {
    fn_8002F634(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}
#pragma scheduling on
void fn_80273AA4(void *arg0) {
    *(char **)((char *)arg0 + 0x18) = lbl_80347364;
    *(int *)arg0 = 0;
}
#pragma scheduling on
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

#pragma scheduling invalid_target
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
        fn_80015B20(temp_r3, out, temp_r3);
    }
}
#pragma scheduling on
void fn_8027445C(void) {
    extern void fn_80274268();
extern void fn_80274460(void);
    fn_80274268();
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80274660(void *arg0, void *arg1) {
    extern void fn_80015A20(void *, float *, float, float);
    extern float lbl_80563FF0, lbl_80563FF4, lbl_80563FF8;
    float matrix[9];
    float vec[3];
    float one = lbl_80563FB0;
    float zero = lbl_80563FAC;
    float angle = lbl_80563FF0;
    float offset;
    char *p = (char *)arg1;

    *(float *)(p + 0x5C) = one;
    *(float *)(p + 0x58) = zero;
    *(float *)(p + 0x60) = one;
    *(float *)(p + 0x64) = one;
    *(float *)(p + 0x68) = zero;
    *(float *)(p + 0x6C) = one;
    *(float *)(p + 0x70) = one;
    *(float *)(p + 0x74) = one;
    *(float *)(p + 0x78) = zero;
    *(float *)(p + 0x7C) = one;
    *(float *)(p + 0x80) = one;
    *(float *)(p + 0x84) = one;
    vec[0] = angle;
    vec[1] = one;
    vec[2] = one;
    fn_80015A20(matrix, vec, one, zero);
    fn_80015B20(p + 0x58, matrix, p + 0x58);
    *(float *)(p + 0x7C) = *(float *)(p + 0xE4);
    *(float *)(p + 0x80) = *(float *)(p + 0xE8);
    *(float *)(p + 0x84) = *(float *)(p + 0xEC);
    if (*(int *)(p + 0x10) == 10) {
        offset = lbl_80563FF4;
    } else {
        offset = lbl_80563FF8;
    }
    *(float *)(p + 0x124) = lbl_80563FB0;
    *(float *)(p + 0x80) += offset;
}
#pragma scheduling on
#pragma pop
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

extern int fn_801EA098(void *, void *, float *, int *, float, float);
extern float lbl_8055F580;
extern float lbl_80563FDC;
extern unsigned char lbl_8055F584;
extern double lbl_80563FB8;
#pragma push
#pragma processor 750
void fn_802749FC(void *arg0, void *arg1) {
    extern float PSVECDotProduct(float *, float *);
    struct { int sp8; float spC[3]; float sp18[3]; float sp24[3]; float sp30[3]; float sp3C; float pad[2]; float sp48[3]; } local;
    unsigned long m11, m10, m9, m8, m7, m6, m5, m4, m3, m2, m1, m0;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_f7_2;
    float temp_f8;
    float var_f3;
    float var_f5;

    if ((int) (*(unsigned char *)((char *)arg0 + 0x138)) != 0) {
        float zero = lbl_80563FAC;
        float one = lbl_80563FB0;
        (*(float *)((char *)arg0 + 0x28)) = one;
        (*(float *)((char *)arg0 + 0x2C)) = zero;
        (*(float *)((char *)arg0 + 0x30)) = one;
        (*(float *)((char *)arg0 + 0x34)) = one;
        (*(float *)((char *)arg0 + 0x38)) = one;
        (*(float *)((char *)arg0 + 0x3C)) = one;
    }
    m0 = *(volatile unsigned int *)((char *)arg0 + 0xC0);
    m1 = *(volatile unsigned int *)((char *)arg0 + 0xC4);
    m2 = *(volatile unsigned int *)((char *)arg0 + 0xC8);
    m3 = *(volatile unsigned int *)((char *)arg0 + 0xCC);
    m4 = *(volatile unsigned int *)((char *)arg0 + 0xD0);
    m5 = *(volatile unsigned int *)((char *)arg0 + 0xD4);
    m6 = *(volatile unsigned int *)((char *)arg0 + 0xD8);
    m7 = *(volatile unsigned int *)((char *)arg0 + 0xDC);
    m8 = *(volatile unsigned int *)((char *)arg0 + 0xE0);
    m9 = *(volatile unsigned int *)((char *)arg0 + 0xE4);
    m10 = *(volatile unsigned int *)((char *)arg0 + 0xE8);
    m11 = *(volatile unsigned int *)((char *)arg0 + 0xEC);
    *(unsigned int *)((char *)arg0 + 0x58) = m0;
    *(unsigned int *)((char *)arg0 + 0x5C) = m1;
    *(unsigned int *)((char *)arg0 + 0x60) = m2;
    *(unsigned int *)((char *)arg0 + 0x64) = m3;
    *(unsigned int *)((char *)arg0 + 0x68) = m4;
    *(unsigned int *)((char *)arg0 + 0x6C) = m5;
    *(unsigned int *)((char *)arg0 + 0x70) = m6;
    *(unsigned int *)((char *)arg0 + 0x74) = m7;
    *(unsigned int *)((char *)arg0 + 0x78) = m8;
    *(unsigned int *)((char *)arg0 + 0x7C) = m9;
    *(unsigned int *)((char *)arg0 + 0x80) = m10;
    *(unsigned int *)((char *)arg0 + 0x84) = m11;
    if (&local.sp30[0] == arg1) {
        temp_f6 = (*(float *)((char *)arg1 + 4));
        temp_f0 = (*(float *)((char *)arg1 + 0));
        temp_f7 = (*(float *)((char *)arg1 + 8));
        local.sp30[0] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x70)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x58)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x64)))));
        local.sp30[1] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x74)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x5C)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x68)))));
        local.sp30[2] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x78)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x60)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x6C)))));
    } else {
        local.sp30[0] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x70)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x58)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x64)))));
        local.sp30[1] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x74)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x5C)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x68)))));
        local.sp30[2] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x78)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x60)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x6C)))));
    }
    (*(float *)((char *)((char *)arg0 + 0x7C))) = (float) ((*(float *)((char *)((char *)arg0 + 0x7C))) + local.sp30[0]);
    (*(float *)((char *)((char *)arg0 + 0x80))) = (float) ((*(float *)((char *)((char *)arg0 + 0x80))) + local.sp30[1]);
    (*(float *)((char *)((char *)arg0 + 0x84))) = (float) ((*(float *)((char *)((char *)arg0 + 0x84))) + local.sp30[2]);
    local.sp8 = 0;
    if ((signed char) lbl_8055F584 == 0) {
        temp_f0_2 = (float) cos(lbl_80563FB8);
        lbl_8055F584 = 1;
        lbl_8055F580 = temp_f0_2;
    }
    if (fn_801EA098((char *)(*(void **)((char *)arg0 + 0x140)) + 0x6C, &local.sp3C, &local.sp48[0], &local.sp8, (*(float *)((char *)((char *)arg0 + 0xE4))), (*(float *)((char *)((char *)arg0 + 0xEC)))) == 0) {
        local.sp48[0] = (*(float *)((char *)((char *)arg0 + 0xCC)));
        local.sp48[1] = (*(float *)((char *)((char *)arg0 + 0xD0)));
        local.sp48[2] = (*(float *)((char *)((char *)arg0 + 0xD4)));
    } else {
        temp_f0_3 = (PSVECDotProduct(&local.sp48[0], (float *)((unsigned int)arg0 + 0xCC)) - lbl_8055F580) / (lbl_80563FAC - lbl_8055F580);
        var_f5 = lbl_80563FB0;
        var_f5 = (var_f5 > temp_f0_3) ? var_f5 : temp_f0_3;
        temp_f4 = local.sp48[0] * var_f5;
        temp_f3 = local.sp48[1] * var_f5;
        temp_f2 = local.sp48[2] * var_f5;
        local.sp48[0] = temp_f4;
        temp_f1 = lbl_80563FAC - var_f5;
        local.sp48[1] = temp_f3;
        local.sp48[2] = temp_f2;
        local.sp48[0] = temp_f4 + ((*(float *)((char *)((char *)arg0 + 0xCC))) * temp_f1);
        local.sp48[1] = temp_f3 + ((*(float *)((char *)((char *)arg0 + 0xD0))) * temp_f1);
        local.sp48[2] = temp_f2 + ((*(float *)((char *)((char *)arg0 + 0xD4))) * temp_f1);
    }
    if ((int) (*(unsigned char *)((char *)((char *)arg0 + 0x138))) != 0) {
        var_f3 = lbl_80563FB0;
    } else {
        var_f3 = lbl_80563FDC;
    }
    temp_f5 = (*(float *)((char *)((char *)arg0 + 0x28))) * var_f3;
    temp_f8 = (*(float *)((char *)((char *)arg0 + 0x2C))) * var_f3;
    temp_f7_2 = (*(float *)((char *)((char *)arg0 + 0x30))) * var_f3;
    (*(float *)((char *)((char *)arg0 + 0x28))) = temp_f5;
    temp_f6_2 = lbl_80563FAC - var_f3;
    (*(float *)((char *)((char *)arg0 + 0x2C))) = temp_f8;
    (*(float *)((char *)((char *)arg0 + 0x30))) = temp_f7_2;
    temp_f3_2 = temp_f5 + (local.sp48[0] * temp_f6_2);
    (*(float *)((char *)((char *)arg0 + 0x28))) = temp_f3_2;
    temp_f3_3 = temp_f8 + (local.sp48[1] * temp_f6_2);
    (*(float *)((char *)((char *)arg0 + 0x2C))) = temp_f3_3;
    temp_f3_4 = local.sp48[2] * temp_f6_2;
    (*(float *)((char *)((char *)arg0 + 0x64))) = (float) ((temp_f3_2 * lbl_80563FC4) + ((*(float *)((char *)((char *)arg0 + 0xCC))) * lbl_80563FC4));
    (*(float *)((char *)((char *)arg0 + 0x68))) = (float) ((temp_f3_3 * lbl_80563FC4) + ((*(float *)((char *)((char *)arg0 + 0xD0))) * lbl_80563FC4));
    temp_f2_2 = temp_f7_2 + temp_f3_4;
    temp_f1_2 = temp_f2_2 * lbl_80563FC4;
    (*(float *)((char *)((char *)arg0 + 0x30))) = temp_f2_2;
    (*(float *)((char *)((char *)arg0 + 0x6C))) = (float) (temp_f1_2 + ((*(float *)((char *)((char *)arg0 + 0xD4))) * lbl_80563FC4));
    PSVECCrossProduct((char *)((char *)arg0 + 0x64), (char *)((char *)arg0 + 0x70), (char *)((char *)arg0 + 0x58));
    PSVECCrossProduct((void *)((unsigned int)arg0 + 0x58), (void *)((unsigned int)arg0 + 0x64), (void *)((unsigned int)arg0 + 0x70));
    local.spC[0] = (*(float *)((char *)((char *)arg0 + 0x58)));
    local.spC[1] = (*(float *)((char *)((char *)arg0 + 0x5C)));
    local.spC[2] = (*(float *)((char *)((char *)arg0 + 0x60)));
    temp_f2_3 = (*(float *)((char *)((char *)arg0 + 0x78)));
    temp_f1_3 = (*(float *)((char *)((char *)arg0 + 0x74)));
    local.sp24[0] = (*(float *)((char *)((char *)arg0 + 0x70)));
    local.sp24[1] = temp_f1_3;
    local.sp24[2] = temp_f2_3;
    PSVECCrossProduct(&local.sp24[0], &local.spC[0], &local.sp18[0]);
    PSVECNormalize(&local.spC[0], &local.spC[0]);
    PSVECNormalize(&local.sp18[0], &local.sp18[0]);
    PSVECCrossProduct(&local.spC[0], &local.sp18[0], &local.sp24[0]);
    (*(float *)((char *)((char *)arg0 + 0x58))) = local.spC[0];
    (*(float *)((char *)((char *)arg0 + 0x5C))) = local.spC[1];
    (*(float *)((char *)((char *)arg0 + 0x60))) = local.spC[2];
    (*(float *)((char *)((char *)arg0 + 0x64))) = local.sp18[0];
    (*(float *)((char *)((char *)arg0 + 0x68))) = local.sp18[1];
    (*(float *)((char *)((char *)arg0 + 0x6C))) = local.sp18[2];
    (*(float *)((char *)((char *)arg0 + 0x70))) = local.sp24[0];
    (*(float *)((char *)((char *)arg0 + 0x74))) = local.sp24[1];
    (*(float *)((char *)((char *)arg0 + 0x78))) = local.sp24[2];
}
#pragma pop
extern float lbl_80563FA8, lbl_80563FB0;
void fn_80274E94(void *arg0) {
    fn_80274730(arg0, lbl_80563FA8, lbl_80563FA8, lbl_80563FA8, lbl_80563FB0);
}

void fn_80274EA8(void *arg0) {
    float vec[3];
    float magnitude;
    float scale;
    char *p = (char *)arg0;

    vec[0] = *(float *)(p + 0x7C) - *(float *)(p + 0xE4);
    vec[1] = *(float *)(p + 0x80) - *(float *)(p + 0xE8);
    vec[2] = *(float *)(p + 0x84) - *(float *)(p + 0xEC);
    magnitude = PSVECMag(vec);
    if (magnitude > lbl_80564010) {
        scale = -(magnitude - lbl_80564010) / magnitude;
        *(float *)(p + 0x7C) += vec[0] * scale;
        *(float *)(p + 0x80) += vec[1] * scale;
        *(float *)(p + 0x84) += vec[2] * scale;
    }
    fn_80274730(arg0, lbl_80563FA8, lbl_80564014, lbl_80564018, lbl_8056401C);
}

static inline void helper_80274F74(void *arg0, void *arg1) {
    float magnitude;
    float scale;
    float cosine;
    float y;
    float z;
    float sine;
    float x;

    magnitude = PSVECMag(arg1);
    if (magnitude > lbl_80564020) {
        scale = lbl_80563FAC / magnitude;
        x = scale * *(float *)arg1;
        y = scale * *(float *)((char *)arg1 + 4);
        z = scale * *(float *)((char *)arg1 + 8);
        sine = (float)sin(magnitude);
        cosine = (float)cos(magnitude);
        {
            float xx = x * x;
            float yy = y * y;
            float t = lbl_80563FAC - cosine;
            float zz = z * z;
            float sz = sine * z;
            float tx = t * x;
            float txx = t * xx;
            float tyy = t * yy;
            float ty = t * y;
            float txy = y * tx;
            float m00 = cosine + txx;
            float tzz = t * zz;
            float txz = z * tx;
            float sy = sine * y;
            *(float *)((char *)arg0 + 0x58) = m00;
            *(float *)((char *)arg0 + 0x5C) = txy + sz;
            {
                float tyz = z * ty;
                float sx = sine * x;
                *(float *)((char *)arg0 + 0x64) = txy - sz;
                *(float *)((char *)arg0 + 0x60) = txz - sy;
                *(float *)((char *)arg0 + 0x68) = cosine + tyy;
                *(float *)((char *)arg0 + 0x6C) = tyz + sx;
                *(float *)((char *)arg0 + 0x70) = txz + sy;
                *(float *)((char *)arg0 + 0x74) = tyz - sx;
                *(float *)((char *)arg0 + 0x78) = cosine + tzz;
            }
        }
    } else {
        float f0 = lbl_80563FB0;
        float f1 = lbl_80563FAC;
        *(float *)((char *)arg0 + 0x5C) = f0;
        *(float *)((char *)arg0 + 0x58) = f1;
        *(float *)((char *)arg0 + 0x60) = f0;
        *(float *)((char *)arg0 + 0x64) = f0;
        *(float *)((char *)arg0 + 0x68) = f1;
        *(float *)((char *)arg0 + 0x6C) = f0;
        *(float *)((char *)arg0 + 0x70) = f0;
        *(float *)((char *)arg0 + 0x74) = f0;
        *(float *)((char *)arg0 + 0x78) = f1;
    }
}

void fn_80274F74(void *arg0, void *arg1, float angle) {
    helper_80274F74(arg0, arg1);
    *(float *)((char *)arg0 + 0xBC) = angle;
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

extern float lbl_80564030, lbl_80563FDC, lbl_80563FD8, lbl_80564024, lbl_80564020, lbl_80563FAC, lbl_80563FB0;
extern float lbl_802FA7C0[];
extern double sin(double), cos(double);
void fn_802756A4(void *arg0) {
    char *p = (char *)arg0;
    char *state = *(char **)(p + 0x140);
    float axis[3];
    float basis[9];
    float mag, scale, x, y, z, s, c, t;
    int i;
    for (i = 0; i < 3; i++) axis[i] = *(float *)(state + 0x2538 + i * 4) + lbl_80564030;
    axis[1] = *(float *)(state + 0x253C) + lbl_80563FDC;
    axis[2] = *(float *)(state + 0x2540) + lbl_80563FD8;
    for (i = 0; i < 12; i++) *(int *)(p + 0x58 + i * 4) = *(int *)(p + 0xC0 + i * 4);
    x = lbl_80564024 * lbl_802FA7C0[3];
    y = lbl_80564024 * lbl_802FA7C0[4];
    z = lbl_80564024 * lbl_802FA7C0[5];
    mag = PSVECMag((float[]){x,y,z});
    if (mag > lbl_80564020) {
       scale = lbl_80563FAC / mag;
       x *= scale; y *= scale; z *= scale;
       s = (float)sin(mag); c = (float)cos(mag); t = lbl_80563FAC - c;
       basis[0]=c+t*x*x; basis[1]=t*x*y+s*z; basis[2]=t*x*z-s*y;
       basis[3]=t*x*y-s*z; basis[4]=c+t*y*y; basis[5]=t*y*z+s*x;
       basis[6]=t*x*z+s*y; basis[7]=t*y*z-s*x; basis[8]=c+t*z*z;
    } else {
       basis[0]=lbl_80563FAC; basis[1]=lbl_80563FB0; basis[2]=lbl_80563FB0;
       basis[3]=lbl_80563FB0; basis[4]=lbl_80563FAC; basis[5]=lbl_80563FB0;
       basis[6]=lbl_80563FB0; basis[7]=lbl_80563FB0; basis[8]=lbl_80563FAC;
    }
    fn_801BFD34(p+0x7C, p+0x6C, p+0xC0);
    fn_80015B20(p+0x58, basis, p+0xC0);
    *(float *)(p+0xBC)=lbl_80564024*lbl_802FA7C0[6];
}

extern float lbl_8055E3C8, lbl_8055F588, lbl_80563FC4, lbl_80563FD8, lbl_80564040;
extern double lbl_80564038;
extern double fn_8002EFB4(float, double);
extern int fn_801E9E30(void *, float *);
void fn_80275B9C(void *arg0, float farg0, float farg1, float farg2) {
 char *p=(char*)arg0; float v[14], angle, sine, cosine, a,b,c;
 angle=(float)fn_8002EFB4(farg2*lbl_8055E3C8,lbl_80564038); *(float*)(p+0x15C)=angle;
 sine=farg0*(float)sin(angle); cosine=(float)cos(*(float*)(p+0x15C));
 v[9]=lbl_80563FB0; v[10]=sine; v[8]=farg0*cosine;
 v[11]=*(float*)(p+0xE4)+v[8]; v[12]=*(float*)(p+0xE8)+lbl_80563FB0; v[13]=*(float*)(p+0xEC)+sine;
 if(fn_801E9E30(p+0x1EC,&v[11])==0) {
 a=v[13]; b=lbl_80563FD8+lbl_8055F588; c=v[11]; v[12]=b;
 v[5]=a+lbl_80563FC4*(*(float*)(p+0xEC)-a);
 v[3]=c+lbl_80563FC4*(*(float*)(p+0xE4)-c);
 v[4]=b+lbl_80563FC4*(*(float*)(p+0xE8)-b);
 v[11]=v[3]; v[12]=v[4]; v[13]=v[5];
 } else lbl_8055F588=v[12];
 angle=v[12]+farg1; v[2]=lbl_80563FB0; v[12]=angle; v[3]=lbl_80563FAC; v[4]=lbl_80563FB0;
 fn_8026E850(&v[11],(float*)(p+0xE4),arg0,&v[2]); *(float*)(p+0xBC)=lbl_80564040;
}

void fn_80275D0C(void *arg0, void *arg1) {
    float v[3], u[3], w[3], axis[3], matrix[9], temp[3];
    float mag, scale, s, c, t, x, y, z;
    float *p=(float *)((char *)arg0+0xC0);
    int i;
    for(i=0;i<12;i++) ((float *)((char *)arg0+0x58))[i]=p[i];
    v[0]=p[9]; v[1]=p[10]; v[2]=p[11];
    u[0]=p[6]; u[1]=p[7]; u[2]=p[8];
    w[0]=p[12]; w[1]=p[13]; w[2]=p[14];
    axis[0]=lbl_80563FB0; axis[1]=lbl_80563FAC; axis[2]=lbl_80563FB0;
    PSVECCrossProduct(axis,u,temp);
    PSVECCrossProduct(u,temp,axis);
    temp[0]=v[0]*lbl_80564024; temp[1]=v[1]*lbl_80564024; temp[2]=v[2]*lbl_80564024;
    mag=PSVECMag(temp);
    if(mag>lbl_80564020) {
        scale=lbl_80563FAC/mag; x=temp[0]*scale; y=temp[1]*scale; z=temp[2]*scale;
        s=(float)sin(mag); c=(float)cos(mag); t=lbl_80563FAC-c;
        matrix[0]=c+t*x*x; matrix[1]=t*x*y+s*z; matrix[2]=t*x*z-s*y;
        matrix[3]=t*x*y-s*z; matrix[4]=c+t*y*y; matrix[5]=t*y*z+s*x;
        matrix[6]=t*x*z+s*y; matrix[7]=t*y*z-s*x; matrix[8]=c+t*z*z;
    } else {
        matrix[0]=lbl_80563FAC; matrix[1]=lbl_80563FB0; matrix[2]=lbl_80563FB0;
        matrix[3]=lbl_80563FB0; matrix[4]=lbl_80563FAC; matrix[5]=lbl_80563FB0;
        matrix[6]=lbl_80563FB0; matrix[7]=lbl_80563FB0; matrix[8]=lbl_80563FAC;
    }
    fn_801BFD34((char *)arg0+0x7C,(char *)arg0+0x84,u);
    fn_80015B20((char *)arg0+0x58,matrix,u);
    *(float *)((char *)arg0+0xBC)=lbl_80564024*w[2];
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

