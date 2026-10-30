// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
void* fn_802BB7CC(void* arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_802BB824(void* arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma dont_inline on
int fn_802BB87C(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}
#pragma pop

void fn_802BB8E4(int* arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

int fn_802BB928(int arg0) {
    return (arg0 + 0x200) / 2;
}

short fn_802BB93C(int arg0) {
    unsigned int value = (unsigned int)arg0 + 0x200;
    unsigned int sign = value >> 31;
    int rounded = (int)sign + (int)value;
    return (short)(0x1FF - (rounded >> 1));
}

extern int fn_802CAC54(int);
extern int lbl_804C00B0[];
extern int fn_802D9628(short, short, unsigned int);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802BB958(short arg0, int arg1, unsigned char *arg2, unsigned char *arg3) {
    int temp_r29;
    short temp_r30;
    int *var_r31;
    int var_r28;
    temp_r30 = fn_802BB928(arg0);
    temp_r29 = fn_802BB93C(arg1);
    var_r31 = lbl_804C00B0;
    var_r28 = 0;
    do {
        int value = *var_r31;
        if (value != 0) {
            unsigned char temp_r4 = *arg2;
            if (temp_r4 != *arg3) {
                ((void (*)(void *, int, int, unsigned int))fn_802D9628)(
                    (void *)value, temp_r30, temp_r29,
                    ((unsigned int)temp_r4 << 24) | ((unsigned int)temp_r4 << 16) |
                    ((unsigned int)temp_r4 << 8) | temp_r4);
            }
        }
        var_r28 += 1;
        var_r31 += 1;
        arg3++;
        arg2++;
    } while (var_r28 < 6);
}
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_802BBBC8(void) {
    extern int lbl_80564CF8;
    extern int lbl_80564CFC;
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    extern signed char lbl_8055CF30;
    extern signed char lbl_8055FA90;
    extern char lbl_8034AAB8[];
    extern char lbl_8034AAC4[];
    extern void fn_801345D8(char *, int, char *, ...);
    extern int fn_802E317C(char *, ...);
    extern int fn_802CA294(void);
    extern signed char fn_802B05E4(void);
    char sp10[0x20];
    int args[2];
    register signed char *colors;
    int *var_r26;
    int *var_r27;
    int temp_r3;
    int var_r25;
    int var_r3;

    args[0] = lbl_80564CF8;
    var_r27 = lbl_804C0098;
    var_r26 = lbl_804C00B0;
    args[1] = lbl_80564CFC;
    var_r25 = 0;
    colors = &lbl_8055CF30;
    do {
        fn_801345D8(sp10, 0x20, lbl_8034AAB8, args[var_r25 / 3], colors[var_r25 % 3]);
        temp_r3 = fn_802BB87C((int)sp10);
        *var_r27 = temp_r3;
        if (temp_r3 == -2) {
            fn_802E317C(lbl_8034AAC4, var_r25);
        }
        if (*var_r27 == -2) {
            var_r3 = 0;
        } else {
            var_r3 = fn_802CA294();
        }
        var_r25 += 1;
        *var_r26 = var_r3;
        var_r27++;
        var_r26++;
    } while (var_r25 < 6);
    lbl_8055FA90 = fn_802B05E4();
}
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma inline_depth(0)
void fn_802BBCC4(void) {
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    int *var_r30 = lbl_804C0098;
    int *var_r29 = lbl_804C00B0;
    int var_r28 = 0;
    do {
        fn_802BB8E4(var_r30);
        var_r28 += 1;
        *var_r29 = 0;
        var_r30++;
        var_r29++;
    } while (var_r28 < 6);
}

#pragma push
#pragma use_lmw_stmw off
unsigned char fn_802BBD38(int arg0, int arg1, int arg2) {
    extern signed char lbl_8055FA90;
    extern int fn_802D972C(void *, int, int);
    int *slot;
    int value;
    int x;
    short y;
    int x2;
    int y2;
    int invalid;
    unsigned char result;

    if ((unsigned char)lbl_8055FA90 != 0)
        return (unsigned char)(~((arg2 - 1) | (1 - arg2)) >> 31);

    result = 0;
    slot = lbl_804C00B0 + arg2;
    value = *slot;
    if (value != 0) {
        x = fn_802BB928(arg0);
        y = fn_802BB93C(arg1);
        invalid = 0;
        if ((short)x < 0 || (short)x >= 0x200 || y < 0 || y >= 0x200)
            invalid = 1;

        if (invalid == 0) {
            y2 = (short)fn_802BB93C(arg1);
            x2 = (short)fn_802BB928(arg0);
            value = *slot;
            result = (unsigned char)(((unsigned int)((int (*)(void *, int, int))fn_802D972C)(
                (void *)value, x2, y2)) >> 8);
        } else {
            result = (unsigned char)(~((arg2 - 2) | (2 - arg2)) >> 31);
        }
    }
    return result;
}
#pragma pop
  extern int lbl_804C0098[];
extern void fn_802BB8E4(int*);
extern int fn_802D972C(void *, int, int);
extern int fn_802E30C8(const char*, ...);
extern char lbl_8034AAF0[];
#pragma scheduling invalid_target
void fn_802BBE34(void) {
    int var_r28 = 0;
    do {
        int var_r27 = 0;
        do {
            int *var_r29 = lbl_804C00B0;
            unsigned int var_r26 = 0;
            int var_r25 = 0;
            do {
                int value = *var_r29;
                if (value != 0) {
                    var_r26 += ((unsigned int)((int (*)(void *, int, int))fn_802D972C)(
                        (void *)value, var_r28, var_r27) >> 8) & 0xFF;
                }
                var_r25 += 1;
                var_r29 += 1;
            } while (var_r25 < 6);
            if (var_r26 != 0xFF) {
                fn_802E30C8(lbl_8034AAF0, var_r28, var_r27, var_r26);
            }
            var_r27 += 1;
        } while (var_r27 < 0x200);
        var_r28 += 1;
    } while (var_r28 < 0x200);
}
#pragma scheduling on
extern int fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern int fn_802BBA08(void *, int);
extern int lbl_8055CF20;
extern int lbl_8055CF28;
#pragma push
#pragma scheduling invalid_target
void fn_802BBEE4(void) {
    register int result;
    register unsigned char status;

    fn_802BBE34();
    result = fn_80128690();
    status = (unsigned char)result;
    if (status == 0)
        fn_80128684();
    fn_802BBA08(&lbl_8055CF20, 0);
    fn_802BBA08(&lbl_8055CF28, 3);
    status = (unsigned char)result;
    if (status == 0)
        fn_80128678();
}
#pragma pop
extern const char lbl_8034AB00[];
#pragma push
#pragma scheduling invalid_target
void fn_802BBF44(unsigned char *arg0, int arg1) {
    register unsigned int value5;
    register unsigned int value4;
    register unsigned int value3;
    register unsigned int value2;
    register unsigned int value1;
    register unsigned int value0;
    unsigned int sum;

    value0 = arg0[0];
    value1 = arg0[1];
    value2 = arg0[2];
    value3 = arg0[3];
    value4 = arg0[4];
    value5 = arg0[5];
    sum = value0 + value1;
    sum += value2;
    sum += value3;
    sum += value4;
    sum += value5;
    if (sum != 0xFF) {
        fn_802E30C8(lbl_8034AB00, value0, value1, value2,
                    value3, value4, value5, arg1);
    }
}
#pragma pop
int fn_802BBF94(unsigned char arg0) {
    int res = (arg0 >> 4) & 0xF;
    return __rlwimi(res, arg0, 0, 24, 27);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802BBFA4(unsigned char *arg0, int arg1, int arg2, int arg3) {
    register unsigned char *base = arg0;
    register int index = arg1;
    register int skip = arg2;
    register unsigned char *p = arg0;
    register int i = 0;
    register int value0;
    register int value1;
    register int value2;
    register int value3;
    register int value4;
    register int value5;
    register int sum;
    register int j;
    int delta;
    int value;

    do {
        *p = (unsigned char)fn_802BBF94(*p);
        i++;
        p++;
    } while (i < 6);

    value0 = base[0];
    value1 = base[1];
    value2 = base[2];
    value3 = base[3];
    value4 = base[4];
    value5 = base[5];
    sum = value0 + value1;
    sum += value2;
    sum += value3;
    sum += value4;
    sum += value5;
    if (sum != 0xFF) {
        value = base[index];
        delta = sum - 0xFF;
        if (value >= delta) {
            base[index] = value - delta;
            return;
        }
        j = 0;
        do {
            if (j != skip) {
                value = *base;
                delta = sum - 0xFF;
                if (delta < value) {
                    value = delta;
                }
                sum -= value;
                *base -= value;
            }
            j++;
            base++;
        } while (sum != 0xFF && j < 6);
    }
}
#pragma pop
extern int lbl_804C0098[4];
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
