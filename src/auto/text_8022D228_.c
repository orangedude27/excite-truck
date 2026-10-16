// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
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

void fn_8022E014(void *arg0, float arg1) {
    int temp = *(int *)((char *)arg0 + 8);
    *(int *)*(int **)((char *)arg0 + 4) = temp + (int)(arg1 * (float)(*(int *)((char *)arg0 + 0xC) - temp));
}

int fn_8022E064(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

