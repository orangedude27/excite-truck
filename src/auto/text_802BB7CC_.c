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

extern int lbl_804C0098[4];
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
