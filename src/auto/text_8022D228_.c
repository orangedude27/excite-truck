// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma use_lmw_stmw off
#pragma small_data off
extern int sprintf(char *, const char *, ...);
extern char lbl_8055B958[8];
extern float lbl_805635D0;
extern float lbl_805635D4;
extern double lbl_805635C8;
extern char lbl_803401A0[];
extern float lbl_805635C0;
extern float lbl_805635C4;

extern char *strcpy(char *, const char *);
void fn_80128668(void);
extern char *fn_8022D82C(void *, int, int);
extern char *strncpy(char *, const char *, unsigned long);
extern double fabs(double);
extern float lbl_80558DC4[];
extern void *fn_8012850C(int, const char *);
extern char lbl_80340108[];
extern char lbl_80340114[];
#pragma scheduling invalid_target
void *fn_8022D228(void *arg0, int arg1, int arg2, int arg3) {
    /* Initialize a fixed-capacity string list: store capacity/count/maxLen and allocate
     * the pointer table plus one (maxLen+1)-byte buffer per entry. */
    int offset;
    int i;
    void *result;
    *(int *)arg0 = arg1;
    *(int *)((char *)arg0 + 4) = arg2;
    result = arg0;
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)((char *)arg0 + 0x10) = fn_8012850C(arg1 * 4, lbl_80340108);
    i = 0;
    offset = 0;
    while (i < arg1) {
        *(void **)((char *)*(void **)((char *)result + 0x10) + offset) = fn_8012850C(arg2 + 1, lbl_80340114);
        i++;
        offset += 4;
    }
    return result;
}
#pragma scheduling on
void *fn_8022D2BC(void *object, int freeObject) {
    /* Free each entry in the pointer table at +0x10 (count at +0x00), free the table, then optionally free object. */
    int offset;
    int index;
    if (object != 0) {
        index = 0;
        offset = 0;
        while (index < *(int *)object) {
            fn_80128670(*(void **)((char *)(*(void **)((char *)object + 0x10)) + offset));
            offset += 4;
            index++;
        }
        fn_80128670(*(void **)((char *)object + 0x10));
        if (freeObject > 0) ((void (*)(void *))fn_80128668)(object);
    }
    return object;
}
#pragma scheduling on
/* Append a string entry into a fixed-capacity string table, storing a per-entry tag byte after the null terminator. */
void fn_8022D350(void *arg0, const char *arg1, char arg2) {
    if (*(int *)((char *)arg0 + 8) < *(int *)((char *)arg0)) {
        strncpy((*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)],
                arg1, *(int *)((char *)arg0 + 4));
        (*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)]
            [*(int *)((char *)arg0 + 4) - 1] = 0;
        (*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)]
            [*(int *)((char *)arg0 + 4)] = arg2;
        (*(int *)((char *)arg0 + 8))++;
        (*(int *)((char *)arg0 + 0xC))++;
    }
}

char *fn_8022D3F8(void *arg0, int arg1, int *arg2) {
    if (arg1 >= 0 && arg1 < *(int *)((char *)arg0 + 8)) {
        if (arg2 != 0) {
            *arg2 = ((signed char *)(*(char ***)((char *)arg0 + 0x10))[arg1])[
                *(int *)((char *)arg0 + 4)];
        }
        return (*(char ***)((char *)arg0 + 0x10))[arg1];
    }
    if (arg2 != 0) *arg2 = 0;
    return 0;
}

extern void fn_8022D76C(void *);
#pragma scheduling invalid_target
void *fn_8022D458(void *arg0, int arg1, int arg2, int *arg3) {
    char *base;
    int size;
    int i;
    base = lbl_80340108;
    size = arg2 * 4;
    *(int *)((char *)arg0 + 0xC) = arg1;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 4) = arg2;
    *(void **)((char *)arg0 + 0x18) = fn_8012850C(size, base + 0x38);
    *(void **)((char *)arg0 + 0x1C) = fn_8012850C(size, base + 0x44);
    *(int *)((char *)arg0 + 0x10) = arg1;
    *(int *)((char *)arg0 + 0x2C) = -1;
    *(int *)((char *)arg0 + 0x24) = 0;
    *(int *)((char *)arg0 + 0x28) = 0x55495442;
    *(int *)((char *)arg0 + 0x14) = 0;
    for (i = 0; i < arg2; i++) {
        ((int *)(*(int *)((char *)arg0 + 0x18)))[i] = arg3[i];
        ((int *)(*(int *)((char *)arg0 + 0x1C)))[i] = *(int *)((char *)arg0 + 0x14);
        *(int *)((char *)arg0 + 0x14) += ((int *)(*(int *)((char *)arg0 + 0x18)))[i] + 1;
    }
    *(void **)arg0 = fn_8012850C(arg1 * *(int *)((char *)arg0 + 0x14), base + 0x50);
    fn_8022D76C(arg0);
    return arg0;
}
void fn_8022D76C(void *arg0) {
    memset(*(void **)arg0, 0, *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x14));
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x24) += 1;
}

void *fn_8022D7C4(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*(int *)((char *)arg0 + 0x18));
        fn_80128670(*(int *)((char *)arg0 + 0x1C));
        fn_80128670(*(int *)arg0);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

#pragma push
#pragma dont_inline on
char *fn_8022D82C(void *arg0, int arg1, int arg2) {
    return *(char **)arg0 +
           arg1 * *(int *)((char *)arg0 + 0x14) +
           (*(int **)((char *)arg0 + 0x1C))[arg2];
}
#pragma pop

char *fn_8022D850(void *arg0, int arg1, int arg2, int *arg3) {
    char *ptr = fn_8022D82C(arg0, arg1, arg2);
    if (arg3 != 0) *arg3 = (signed char)*ptr;
    return ptr + 1;
}

#pragma scheduling reset
/* Write a string cell in a fixed-stride table: store the tag byte, copy the text, update the used row count, and bump the modification count. */
void fn_8022D894(void *arg0, int arg1, int arg2, const char *arg3, signed char arg4) {
    char *ptr = fn_8022D82C(arg0, arg1, arg2);
    int next = arg1 + 1;
    int len;
    if (next > *(int *)((char *)arg0 + 8)) *(int *)((char *)arg0 + 8) = next;
    len = (*(int **)((char *)arg0 + 0x18))[arg2];
    *ptr = arg4;
    strncpy(ptr + 1, arg3, len);
    ptr += len;
    *ptr = 0;
    *(int *)((char *)arg0 + 0x24) += 1;
}
#pragma scheduling invalid_target
void fn_8022D924(volatile int *p, int arg1) {
    int cnt = p[0x24 / 4];
    int v = p[0x2C / 4];
    p[0x10 / 4] = arg1;
    p[0x24 / 4] = cnt + 1;
    if (v < 0) return;
    if (v >= 0) { arg1 = v; goto divide; }
    return;
store:
    cnt = p[0x24 / 4];
    p[0x20 / 4] = arg1;
    p[0x24 / 4] = cnt + 1;
    return;
divide:
    cnt = p[0x10 / 4];
    p[0x2C / 4] = arg1;
    arg1 = arg1 / cnt;
    p[0x24 / 4] = p[0x24 / 4] + 1;
    goto store;
}
#pragma scheduling on
int fn_8022D97C(int *arg0, int arg1) {
    return *arg0 + arg1 * 0x28;
}

#pragma push
#pragma scheduling invalid_target
void fn_8022D98C(void *arg0, int arg1, float arg2, float arg3, float arg4, float arg5, float arg6) {
    float value = arg4;
    volatile int *count = (volatile int *)((char *)arg0 + 0x1C);
    int n;
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(void **)arg0 = lbl_803401A0;
    *(float *)((char *)arg0 + 4) = arg2;
    *(float *)((char *)arg0 + 8) = arg3;
    *(float *)((char *)arg0 + 0xC) = arg5;
    *(float *)((char *)arg0 + 0x10) = arg6;
    *count = 0;
    do {
        n = *count;
        value = value * lbl_805635C0;
        *count = n + 1;
        if ((value - (float)(int)value > lbl_805635C4) == 0)
            break;
        if (*count < 4)
            continue;
        break;
    } while (1);
    *(float *)((char *)arg0 + 0x14) = arg4 / (arg3 - arg2);
}
#pragma pop
int fn_8022DA34(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
void fn_8022DA74(void *arg0, char *arg1) {
    register void *data = arg0;
    register float high = *(volatile float *)((char *)arg0 + 8);
    register float low = *(volatile float *)((char *)data + 4);
    register float range = high - low;
    register float fraction = **(float **)((char *)data + 0x18);
    register int precision = *(int *)((char *)data + 0x1C);
    sprintf(arg1, lbl_8055B958, precision, lbl_805635D0 + (low + fraction * range), range, low);
}
#pragma pop
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

#pragma push
#pragma scheduling invalid_target
void fn_8022DB34(void *arg0, char *arg1) {
    int value = **(int **)((char *)arg0 + 4);
    sprintf(arg1, *(char **)((char *)arg0 + 0x10), value, arg0);
}
#pragma pop
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

#pragma dont_inline on
int fn_8022DBD4(void *arg0) {
    int *array = *(int **)arg0;
    return array[*(int *)((char *)arg0 + 0xC)];
}
#pragma dont_inline off

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

#pragma dont_inline on
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
#pragma dont_inline off

int fn_8022DC68(void *arg0, int arg1) {
    int saved = *(int *)((char *)arg0 + 0xC);
    int value;
    fn_8022DC40(arg0, arg1);
    value = fn_8022DBD4(arg0);
    fn_8022DC40(arg0, saved);
    return value;
}

#pragma push
#pragma use_lmw_stmw off
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
#pragma pop
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

#pragma push
#pragma opt_propagation off
#pragma scheduling invalid_target
void fn_8022DDB0(void *arg0) {
    float c = lbl_805635D4;
    float *p = *(float **)((char *)arg0 + 0x18);
    float step = *(float *)((char *)arg0 + 0x14);
    float v = step * (float)(int)(c + ((*p + step) / step));
    float low = *(float *)((char *)arg0 + 0x10);
    *p = (low < v) ? low : v;
}
#pragma scheduling on
void fn_8022DE1C(void *arg0) {
    float c = lbl_805635D4;
    float *p = *(float **)((char *)arg0 + 0x18);
    float step = *(float *)((char *)arg0 + 0x14);
    float v = step * (float)(int)(c + ((*p - step) / step));
    float low = *(float *)((char *)arg0 + 0x0C);
    *p = (low > v) ? low : v;
}
#pragma scheduling invalid_target
int fn_8022DE88(void *arg0) {
    float current = *(float *)((char *)arg0 + 0x10);
    float *value_ptr = *(float **)((char *)arg0 + 0x18);
    float value = *value_ptr;
    float mag = (float)__fabs(current - value);
    if (mag <= *(float *)(void *)&lbl_80558DC4) return 0;
    if (mag > *(float *)(void *)&lbl_80558DC4) return 1;
    return 1;
}
#pragma pop
extern double __fabs(double);
#pragma push
#pragma optimization_level 1
int fn_8022DEC4(void *arg0) {
    float *valuePtr = *(float **)((char *)arg0 + 0x18);
    float current = *(float *)((char *)arg0 + 0xC);
    float value = *valuePtr;
    float diff = current - value;
    float mag = __fabs(diff);
    if (mag <= lbl_80558DC4[0]) {
        return 0;
    } else {
        return 1;
    }
}
#pragma pop
void fn_8022DF00(void *arg0, int *arg1, int *arg2) {
    *arg1 = *(int *)((char *)arg0 + 4);
    *arg2 = 4;
}

void fn_8022DF14(void *arg0) {
    int cur;
    int hi;
    int *p;
    int v;
    int lo;
    p = *(int **)((char *)arg0 + 4);
    hi = *(int *)((char *)arg0 + 0xC);
    cur = *p;
    if (hi < cur + 1) {
        v = hi;
    } else {
        v = cur + 1;
    }
    lo = *(int *)((char *)arg0 + 8);
    if (v > lo) {
        lo = v;
    }
    *p = lo;
}

void fn_8022DF48(void *arg0) {
    int cur;
    int hi;
    int *p;
    int v;
    int lo;
    p = *(int **)((char *)arg0 + 4);
    hi = *(int *)((char *)arg0 + 0xC);
    cur = *p;
    if (hi < cur - 1) {
        v = hi;
    } else {
        v = cur - 1;
    }
    lo = *(int *)((char *)arg0 + 8);
    if (v > lo) {
        lo = v;
    }
    *p = lo;
}

extern char *fn_8022D82C(void *, int, int);
extern char *strncpy(char *, const char *, unsigned long);
extern double fabs(double);
int fn_8022DF7C(void *arg0) {
    int *ptr = *(int **)((char *)arg0 + 4);
    return *(int *)((char *)arg0 + 0xC) != *ptr;
}

int fn_8022DF9C(void *arg0) {
    int *ptr = *(int **)((char *)arg0 + 4);
    return *(int *)((char *)arg0 + 8) != *ptr;
}

#pragma scheduling invalid_target
float fn_8022DFBC(void *arg0) {
    int offset = *(int *)((char *)arg0 + 8);
    int denominator = *(int *)((char *)arg0 + 0xC) - offset;
    int numerator = **(int **)((char *)arg0 + 4) - offset;
    float convertedNumerator = (float)numerator;
    float convertedDenominator = (float)denominator;
    return convertedNumerator / convertedDenominator;
}
#pragma scheduling on
void fn_8022E014(void *arg0, float arg1) {
    int temp = *(int *)((char *)arg0 + 8);
    *(int *)*(int **)((char *)arg0 + 4) = temp + (int)(arg1 * (float)(*(int *)((char *)arg0 + 0xC) - temp));
}

int fn_8022E064(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

