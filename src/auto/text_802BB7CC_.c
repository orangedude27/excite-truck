// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
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
    return ((int)((temp_r3 >> 31) + temp_r3)) >> 1;
}

short fn_802BB93C(int arg0) {
    unsigned int temp_r3 = arg0 + 0x200;
    return (short)(0x1FF - (((int)((temp_r3 >> 31) + temp_r3)) >> 1));
}

extern int fn_802CAC54(int);
extern int lbl_804C00B0[];
extern int fn_802D9628(short, short, unsigned int);
void fn_802BB958(int arg0, int arg1, unsigned char* arg2, unsigned char* arg3, int arg4) {
    short temp_r30;
    short temp_r29;
    int* var_r31;
    int var_r28;
    unsigned char* var_r26;
    unsigned char* var_r27;
    unsigned char temp_r4;
    var_r26 = arg2;
    var_r27 = arg3;
    temp_r30 = fn_802BB928((short)arg0);
    temp_r29 = fn_802BB93C(arg1);
    var_r31 = lbl_804C00B0;
    var_r28 = 0;
    do {
        if (*var_r31 != 0) {
            temp_r4 = *var_r26;
            if (temp_r4 != *var_r27) {
                fn_802D9628(temp_r30, temp_r29, ((unsigned int)temp_r4 << 24) | ((unsigned int)temp_r4 << 16) | ((unsigned int)temp_r4 << 8) | temp_r4);
            }
        }
        var_r28 += 1;
        var_r31 += 1;
        var_r27 += 1;
        var_r26 += 1;
    } while (var_r28 < 6);
}

extern int lbl_804C0098[4];
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
