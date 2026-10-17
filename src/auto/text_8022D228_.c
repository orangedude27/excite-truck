// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int sprintf(char *, const char *, ...);
extern char lbl_8055B958[8];
extern float lbl_805635D0;
extern float lbl_805635D4;
extern double lbl_805635C8;
extern int lbl_803401A0;
extern float lbl_805635C0;
extern float lbl_805635C4;

extern char *strcpy(char *, const char *);
extern int lbl_803401A0;
extern float lbl_805635C0;
extern float lbl_805635C4;
void fn_80128668(void);
void fn_8022D924(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 0x24);
    int value = *(int *)((char *)arg0 + 0x2C);
    int next = count + 1;
    *(int *)((char *)arg0 + 0x10) = arg1;
    if (value >= 0) {
        *(int *)((char *)arg0 + 0x24) = next;
        if (value != 0) {
            *(int *)((char *)arg0 + 0x20) = value;
            *(int *)((char *)arg0 + 0x24) = next + 1;
            *(int *)((char *)arg0 + 0x2C) = arg1;
            *(int *)((char *)arg0 + 0x20) = arg1 / *(int *)((char *)arg0 + 0x10);
            *(int *)((char *)arg0 + 0x24) = next + 2;
        }
    } else {
        *(int *)((char *)arg0 + 0x24) = next;
    }
}

int fn_8022D97C(int *arg0, int arg1) {
    return *arg0 + arg1 * 0x28;
}

void fn_8022D98C(void *arg0, int arg1, float arg2, float arg3, float arg4, float arg5, float arg6) {
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(int **)arg0 = &lbl_803401A0;
    *(float *)((char *)arg0 + 4) = arg2;
    *(float *)((char *)arg0 + 8) = arg3;
    *(float *)((char *)arg0 + 0xC) = arg5;
    *(float *)((char *)arg0 + 0x10) = arg6;
    *(int *)((char *)arg0 + 0x1C) = 0;
    do {
        float f = arg4 * lbl_805635C0;
        int n = *(int *)((char *)arg0 + 0x1C);
        *(int *)((char *)arg0 + 0x1C) = n + 1;
        if (f - (float)(int)f >= lbl_805635C4) break;
        if (n + 1 >= 4) break;
    } while (1);
    *(float *)((char *)arg0 + 0x14) = arg4 / (arg3 - arg2);
}

int fn_8022DA34(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8022DA74(void *arg0, char *arg1) {
    float high = *(float *)((char *)arg0 + 8);
    float low = *(float *)((char *)arg0 + 4);
    float range = high - low;
    sprintf(arg1, lbl_8055B958, *(int *)((char *)arg0 + 0x1C), lbl_805635D0 + (low + **(float **)((char *)arg0 + 0x18) * range), range, low);
}
#pragma scheduling reset
float fn_8022DAB0(void *arg0) {
    float low = *(float *)((char *)arg0 + 0xC);
    return (**(float **)((char *)arg0 + 0x18) - low) / (*(float *)((char *)arg0 + 0x10) - low);
}

void fn_8022DAD0(void *arg0, float arg1) {
    float high = *(float *)((char *)arg0 + 0x10);
    float low = *(float *)((char *)arg0 + 0xC);
    float step = *(float *)((char *)arg0 + 0x14);
    **(float **)((char *)arg0 + 0x18) = step * (float)(int)(lbl_805635D4 + ((low + arg1 * (high - low)) / step));
}

void fn_8022DB34(void *arg0, char *arg1) {
    int value = **(int **)((char *)arg0 + 4);
    sprintf(arg1, *(char **)((char *)arg0 + 0x10), value, arg0);
}

void fn_8022DB50(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    *(int *)arg0 = arg1;
    *(int *)((char *)arg0 + 4) = arg2;
    *(int *)((char *)arg0 + 0x10) = arg3;
    *(int *)((char *)arg0 + 8) = arg3;
    while (*(int *)((char *)arg0 + 8) < 5) {
        *(int *)((char *)arg0 + 8) += *(int *)((char *)arg0 + 0x10);
    }
    *(int *)((char *)arg0 + 0x14) = arg4;
    *(int *)((char *)arg0 + 0xC) = 0;
    *(char *)((char *)arg0 + 0x18) = 0;
}

int fn_8022DB94(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_8022DBD4(void *arg0) {
    int *array = *(int **)arg0;
    return array[*(int *)((char *)arg0 + 0xC)];
}

int fn_8022DBE8(void *arg0) {
    int *array = *(int **)((char *)arg0 + 4);
    return array[*(int *)((char *)arg0 + 0xC)];
}

void fn_8022DBFC(void *arg0) {
    int value = *(int *)((char *)arg0 + 0xC) + 1;
    *(int *)((char *)arg0 + 0xC) = value;
    if (value >= *(int *)((char *)arg0 + 0x10)) *(int *)((char *)arg0 + 0xC) = 0;
}

void fn_8022DC20(void *arg0) {
    int value = *(int *)((char *)arg0 + 0xC) - 1;
    *(int *)((char *)arg0 + 0xC) = value;
    if (value < 0) *(int *)((char *)arg0 + 0xC) = *(int *)((char *)arg0 + 0x10) - 1;
}

void fn_8022DC40(void *arg0, int arg1) {
    int step;
    *(int *)((char *)arg0 + 0xC) = arg1;
    goto check;
loop:
    *(int *)((char *)arg0 + 0xC) -= step;
check:
    step = *(int *)((char *)arg0 + 0x10);
    if (*(int *)((char *)arg0 + 0xC) >= step) goto loop;
}

int fn_8022DC68(void *arg0, int arg1) {
    int value;
    int saved = *(int *)((char *)arg0 + 0xC);
    fn_8022DC40(arg0, arg1);
    value = fn_8022DBD4(arg0);
    fn_8022DC40(arg0, saved);
    return value;
}

void *fn_8022DCC4(void *arg0, char **arg1, int arg2, int arg3) {
    char **var_r31 = arg1;
    char *var_r30 = (char *)arg0;
    int var_r29 = 0;
    while (var_r29 < arg2) {
        strcpy(var_r30, *var_r31);
        var_r31++;
        var_r30 += 0x10;
        var_r29++;
    }
    *(int *)((char *)arg0 + 0x40) = arg2;
    *(int *)((char *)arg0 + 0x44) = arg3;
    return arg0;
}

void *fn_8022DD38(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0x40) = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_8022DD80(void *arg0) { return *(int *)((char *)arg0 + 0x40); }

int fn_8022DD88(void *arg0) { return *(int *)((char *)arg0 + 0x44); }

int fn_8022DD90(int arg0,int arg1) { return arg0 + arg1 * 16; }

void fn_8022DD9C(void *arg0,int *arg1,int *arg2) {
*arg1=*(int *)((char *)arg0+0x18); *arg2=4;
}

void fn_8022DDB0(void *arg0) {
float *temp_r4;
float temp_f3;
float var_f4;
float temp_f0;
temp_f0=lbl_805635D4;
temp_r4=*(float **)((char *)arg0+0x18);
temp_f3=*(float *)((char *)arg0+0x14);
{
float temp_f1=*temp_r4;
float temp_f2=temp_f1+temp_f3;
temp_f2=temp_f2/temp_f3;
temp_f0=temp_f0+temp_f2;
temp_f0=(float)(int)temp_f0;
temp_f0=temp_f3*temp_f0;
}
var_f4=*(float *)((char *)arg0+0x10);
if(var_f4>=temp_f0) var_f4=temp_f0;
*temp_r4=var_f4;
}

void fn_8022DE1C(void *arg0) {
    float *temp_r4;
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float temp_f3;
    float var_f4;
    temp_f0 = lbl_805635D4;
    temp_r4 = *(float **)((char *)arg0 + 0x18);
    temp_f3 = *(float *)((char *)arg0 + 0x14);
    temp_f1 = *temp_r4;
    temp_f2 = temp_f1 - temp_f3;
    temp_f2 = temp_f2 / temp_f3;
    temp_f0 = temp_f0 + temp_f2;
    temp_f0 = (float)(int)temp_f0;
    var_f4 = *(float *)((char *)arg0 + 0x0C);
    temp_f0 = temp_f3 * temp_f0;
    if (var_f4 > temp_f0) {
    } else {
        var_f4 = temp_f0;
    }
    *temp_r4 = var_f4;
}

int fn_8022DEC4(void *arg0) {
    extern float lbl_80558DC4;
    float diff = *(float *)((char *)arg0 + 0xC) - **(float **)((char *)arg0 + 0x18);
    if (diff < 0.0f) diff = -diff;
    return diff <= lbl_80558DC4 ? 0 : 1;
}

void fn_8022DF00(void *arg0, int *arg1, int *arg2) {
    *arg1 = *(int *)((char *)arg0 + 4);
    *arg2 = 4;
}

void fn_8022DF14(void *arg0) {
    int *temp_r6;
    int temp_r5;
    int var_r0;
    int var_r3;
    temp_r6 = *(int **)((char *)arg0 + 4);
    temp_r5 = *(int *)((char *)arg0 + 0xC);
    var_r0 = *temp_r6 + 1;
    if (temp_r5 < var_r0) var_r0 = temp_r5;
    var_r3 = *(int *)((char *)arg0 + 8);
    if (var_r0 > var_r3) *temp_r6 = var_r0;
}

void fn_8022DF48(void *arg0) {
    int *temp_r6;
    int temp_r5;
    int var_r0;
    int var_r3;
    temp_r6 = *(int **)((char *)arg0 + 4);
    temp_r5 = *(int *)((char *)arg0 + 0xC);
    var_r0 = *temp_r6 - 1;
    if (temp_r5 < var_r0) var_r0 = temp_r5;
    var_r3 = *(int *)((char *)arg0 + 8);
    if (var_r0 > var_r3) *temp_r6 = var_r0;
}

int fn_8022DF9C(void *arg0) {
    int *ptr = *(int **)((char *)arg0 + 4);
    return *(int *)((char *)arg0 + 8) != *ptr;
}

float fn_8022DFBC(void *arg0) {
    int temp_r6 = *(int *)((char *)arg0 + 8);
    int temp_r0 = *(int *)((char *)arg0 + 0xC) - temp_r6;
    int temp_r5 = **(int **)((char *)arg0 + 4) - temp_r6;
    return (float)temp_r5 / (float)temp_r0;
}

void fn_8022E014(void *arg0, float arg1) {
    int temp = *(int *)((char *)arg0 + 8);
    *(int *)*(int **)((char *)arg0 + 4) = temp + (int)(arg1 * (float)(*(int *)((char *)arg0 + 0xC) - temp));
}

int fn_8022E064(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

