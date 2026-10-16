// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern float lbl_805635D4;
extern double lbl_805635C8;

extern char *strcpy(char *, const char *);
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

