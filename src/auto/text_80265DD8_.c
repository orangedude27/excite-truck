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
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(float *)((char *)arg0 + 8) = lbl_8055C4C0;
    *(float *)((char *)arg0 + 0xC) = lbl_80563C2C;
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
    int temp;
    int half;
    int a;
    int b;
    int div;
    count = fn_80178CA4();
    temp = count ^ 1;
    half = temp >> 1;
    a = temp & count;
    temp = half - a;
    temp = ((unsigned int)temp) >> 31;
    temp += 1;
    div = (count + temp - 1) / temp;
    a = lbl_8055CFF0 / temp;
    b = lbl_8055CFF4 / div;
    arg0[0x40 / 4] = a;
    arg0[0x44 / 4] = b;
    arg0[0x38 / 4] = a * (arg1 / div);
    arg0[0x3C / 4] = b * (arg1 % div);
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
