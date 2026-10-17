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

int fn_802BB87C(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802BB8E4(int* arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

int fn_802BB928(int arg0) {
    unsigned int temp_r3 = arg0 + 0x200;
    unsigned int sign = temp_r3 >> 31;
    return (int)(temp_r3 + sign) >> 1;
}

short fn_802BB93C(int arg0) {
    unsigned int temp_r3 = arg0 + 0x200;
    unsigned int sign = temp_r3 >> 31;
    return (short)(0x1FF - (((int)(temp_r3 + sign)) >> 1));
}

extern int fn_802CAC54(int);
extern int lbl_804C00B0[];
extern int fn_802D9628(short, short, unsigned int);
void fn_802BB958(short arg0, int arg1, unsigned char* arg2, unsigned char* arg3) {
    short temp_r30 = fn_802BB928(arg0);
    short temp_r29 = fn_802BB93C(arg1);
    int* var_r31 = lbl_804C00B0;
    int var_r28 = 0;
    do {
        if (*var_r31 != 0) {
            unsigned char temp_r4 = *arg2;
            if (temp_r4 != *arg3) {
                fn_802D9628(temp_r30, temp_r29, ((unsigned int)temp_r4 << 24) | ((unsigned int)temp_r4 << 16) | ((unsigned int)temp_r4 << 8) | temp_r4);
            }
        }
        var_r28 += 1;
        var_r31 += 1;
        arg3++;
        arg2++;
    } while (var_r28 < 6);
}

#pragma dont_inline fn_802BB87C
void fn_802BBBC8(void) {
    extern int lbl_80564CF8;
    extern int lbl_80564CFC;
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    extern signed char lbl_8055CF30[];
    extern signed char lbl_8055FA90;
    extern char lbl_8034AAB8[];
    extern char lbl_8034AAC4[];
    extern void fn_801345D8(void *, int, char *, int, signed char);
    extern int fn_802CA294(void);
    extern int fn_802E317C(char *, int);
    extern signed char fn_802B05E4(void);
    int args[2];
    int *out0 = lbl_804C0098;
    int *out1 = lbl_804C00B0;
    int i = 0;
    args[0] = lbl_80564CF8;
    args[1] = lbl_80564CFC;
    do {
        fn_801345D8(&args[0], 0x20, lbl_8034AAB8, args[i / 3], lbl_8055CF30[i % 3]);
        *out0 = fn_802BB87C((int)&args[0]);
        if (*out0 == -2) fn_802E317C(lbl_8034AAC4, i);
        if (*out0 == -2) *out1 = 0;
        else *out1 = fn_802CA294();
        i++;
        out0++;
        out1++;
    } while (i < 6);
    lbl_8055FA90 = fn_802B05E4();
}
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

  extern int lbl_804C0098[];
extern void fn_802BB8E4(int*);
extern unsigned int fn_802D972C(int, int, ...);
extern int fn_802E30C8(const char*, int, int, unsigned int);
extern char lbl_8034AAF0[];
void fn_802BBE34(void) {
    int var_r28 = 0;
    do {
        int var_r27 = 0;
        do {
            int *var_r29 = lbl_804C00B0;
            unsigned int var_r26 = 0;
            int var_r25 = 0;
            do {
                if (*var_r29 != 0) {
                    var_r26 += (fn_802D972C(var_r28, var_r27) >> 16) & 0xFF;
                }
                var_r25 += 1;
                var_r29++;
            } while (var_r25 < 6);
            if (var_r26 != 0xFF) {
                fn_802E30C8(lbl_8034AAF0, var_r28, var_r27, var_r26);
            }
            var_r27 += 1;
        } while (var_r27 < 0x200);
        var_r28 += 1;
    } while (var_r28 < 0x200);
}

int fn_802BBF94(unsigned int arg0) {
    return ((arg0 >> 4) & 0xF) | (arg0 & 0xF);
}

#pragma dont_inline fn_802BBF94
void fn_802BBFA4(unsigned char *arg0, int arg1, int arg2, int arg3) {
    int i;
    int sum;
    int delta;
    unsigned char *p;
    unsigned char value;

    p = arg0;
    i = 0;
    do {
        *p = fn_802BBF94(*p);
        i++;
        p++;
    } while (i < 6);

    sum = arg0[0] + arg0[1] + arg0[2] + arg0[3] + arg0[4] + arg0[5];
    if (sum != 0xFF) {
        value = arg0[arg1];
        delta = sum - 0xFF;
        if ((int)value >= delta) {
            arg0[arg1] = value - delta;
            return;
        }
        i = 0;
        p = arg0;
        while (sum != 0xFF && i < 6) {
            if (i != arg2) {
                value = *p;
                delta = sum - 0xFF;
                if (delta < value)
                    value = delta;
                sum -= value;
                *p -= value;
            }
            i++;
            p++;
        }
    }
}
extern int lbl_804C0098[4];
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
