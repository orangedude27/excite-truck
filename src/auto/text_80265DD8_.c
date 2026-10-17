// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F488;
extern float lbl_8055F484;
extern float lbl_80499980[8];
extern float lbl_80563C6C;
extern float lbl_80563C20;
void fn_802693F4(void);
extern void fn_80265E08(void*);
extern float lbl_80563C24;
extern float lbl_8055C4E0;
extern float lbl_8055C4E4;
extern int lbl_8055C4E8;
extern int lbl_8055C4EC;
extern int lbl_804999A0[];
extern float fn_80129DC4(int, float, float);
extern int fn_80129D90(int, int, int);
extern float PSVECMag(void*);
void* fn_80265DD8(void* arg0) {
    fn_80265E08(arg0);
    return arg0;
}

void fn_80265E08(void* arg0) {
    float zero = lbl_80563C20;
    *(int*)((char*)arg0 + 0) = 0;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = 0;
}

void fn_80266070(void* arg0, void* arg1, void* arg2, void* arg3) {
    float scale = *(float*)((char*)arg0 + 0x10);
    float x = *(float*)((char*)arg3 + 0) * scale;
    float y = *(float*)((char*)arg3 + 4) * scale;
    float z = *(float*)((char*)arg3 + 8) * scale;
    float mag;
    float f;
    float* out = arg1;
    float* base = arg2;
    *(float*)((char*)0 + 0); 
    mag = PSVECMag(arg3);
    f = *(float*)((char*)arg0 + 0x14) * mag;
    out[0] = base[0] + x;
    out[1] = base[1] + (y + f);
    out[2] = base[2] + z;
}

extern float lbl_8055C4C0;
extern float lbl_80563C2C;
extern float lbl_8055C4C4;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
void fn_80266150(void *arg0);
int fn_80178CA4(void);
float PSQUATMultiply(float *arg0, int arg1);
void *fn_80266120(void *arg0) {
    fn_80266150(arg0);
    return arg0;
}

void fn_80266150(void *arg0) {
    *(float *)((char *)arg0 + 0xC) = lbl_80563C2C;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(float *)((char *)arg0 + 8) = lbl_8055C4C0;
}

void fn_802662D8(float *arg0, float *arg1, float *arg2, float *arg3, int arg4) {
    float t;
    float factor;
    t = PSQUATMultiply(arg2, arg4) - lbl_8055C4C4;
    t = t - lbl_80563C20;
    factor = lbl_80563C20 + arg0[3] * t;
    arg1[0] = arg2[0] + arg3[0] * factor;
    arg1[1] = arg2[1] + arg3[1] * factor;
    arg1[2] = arg2[2] + arg3[2] * factor;
}

void fn_802670A0(int *arg0, int arg1) {
    int count;
    int x;
    int y;
    int div;
    int a;
    int b;
    count = fn_80178CA4();
    x = count ^ 1;
    y = x >> 1;
    x &= count;
    y -= x;
    y = ((unsigned int)y) >> 31;
    y += 1;
    div = (count + y - 1) / y;
    a = lbl_8055CFF0 / y;
    b = lbl_8055CFF4 / div;
    arg0[16] = a;
    arg0[17] = b;
    arg0[14] = a * (arg1 / div);
    arg0[15] = b * (arg1 % div);
}

extern void *fn_80267EE4(int);
extern void fn_801EF024(void *);
extern void fn_80278288(void);
extern void fn_802733F0(void);
extern void fn_80209110(void *);
extern void *lbl_8055F490;
extern int lbl_8055F494;
extern float lbl_8055E3C8;
void fn_802678E4(void) { fn_80267EE4(0); }

void fn_80267E40(unsigned int arg0, float arg1, int arg2) {
    float temp_f29;
    float temp_f30;
    float temp_f31;
    int i;
    void *p;
    temp_f29 = lbl_8055E3C8;
    temp_f30 = lbl_80563C6C;
    temp_f31 = lbl_80563C2C;
    for (i = 0; i < 4; i++) {
        p = fn_80267EE4(i);
        if (*(unsigned int *)((char *)p + 0x140) == arg0) {
            if (arg1 > *(float *)((char *)p + 0x154) * (temp_f31 - ((temp_f29 - *(float *)((char *)p + 0x158)) / temp_f30))) {
                *(float *)((char *)p + 0x158) = temp_f29;
                *(float *)((char *)p + 0x154) = arg1;
                return;
            }
        }
    }
}

extern void fn_802734F0(void);
extern char lbl_80499080[];
extern float lbl_80499050[];
extern float lbl_8055F47C;
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern int lbl_8055F4A0;
extern int lbl_8055F4A4;
extern int lbl_8055F4A8;
extern void fn_801E9DC4(int *);
void fn_80267EE0(void) {
    fn_802734F0();
}

void *fn_80267EE4(int arg0) {
    return lbl_80499080 + arg0 * 0x228;
}

void fn_802682B0(void *arg0) {
    char *p = (char *)arg0;
    if (*(unsigned char *)(p + 0x138) != 0) {
        float b;
        float a;
        float *q;
        a = lbl_80563C2C;
        q = lbl_80499050 - 1;
        b = lbl_80563C20;
        *++q = a;
        q[1] = b; q[2] = b; q[3] = b;
        q[4] = a;
        q[5] = b; q[6] = b; q[7] = b;
        q[8] = a;
        q[9] = b; q[10] = b; q[11] = b;
    }
    fn_801BFD34(p + 0x7c, lbl_80499050 + 9, p + 0xc0);
    fn_80015B20(p + 0x58, lbl_80499050, p + 0xc0);
    *(float *)(p + 0xbc) = lbl_8055F47C;
}

void fn_80268B94(int arg0) {
    lbl_8055F4A0 = arg0;
    lbl_8055F4A4 = arg0;
    fn_801E9DC4(&lbl_8055F4A8);
}

extern void fn_801EA994(void);
extern int lbl_80499E50[];
void fn_8026A2B0(int arg0) {
    lbl_80499E50[arg0] = 1;
}

char fn_8026A38C(void) {
    return lbl_8055F488;
}

extern float lbl_8055F484;
extern float lbl_80563C6C;
extern float lbl_80499980[8];
extern float lbl_80563C20;
void fn_802693F4(void);
void fn_8026A51C(void) {
    fn_802693F4();
}

float fn_8026A520(int arg0) {
    if (arg0 >= 0 && (unsigned int)arg0 < 8U) {
        return lbl_80499980[arg0];
    }
    return lbl_80563C20;
}

void fn_8026A54C(float arg0) {
    lbl_8055F484 = arg0;
}

int fn_8026A554(int *arg0) {
    int index = *arg0;
    if (index >= 0 && (unsigned int)index < 8U) {
        lbl_80499980[index] = lbl_80563C6C;
    }
    return 4;
}
extern float lbl_80563C20;
