extern void *lbl_80560078;
extern char lbl_80560060;
extern char lbl_8052E658;
extern int lbl_80560090;
extern char lbl_805600D0;
extern char lbl_805600D1;
extern float lbl_805651C4;
extern float lbl_8055D270;
extern int fn_802E622C(int, float);
extern int fn_802E61E4(int, float);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_805600C8;
extern void *lbl_80560080;
extern int fn_802EBD40(void);
int fn_802EBE00(int arg0) {
    if (arg0 == 1) fn_802EBD40();
    return 0;
}

void* fn_802EC0FC(void) {
    return lbl_80560080;
}

void fn_802EC11C(void *arg0) {
    lbl_80560078 = arg0;
}

extern void *lbl_80560078;
void* fn_802EC124(void) {
    return lbl_80560078;
}

void fn_802EC12C(void) {
    lbl_80560078 = (void*)-1;
}

void fn_802EC1D8(void) {
    lbl_805600C8 = 1;
}

extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern char lbl_8034E990;
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
void fn_802EC294(long arg0, long arg1) {
    long spC = 0;
    long sp8 = 0;
    long temp_r3;
    long *temp_r31 = &lbl_805076A0[arg0 * 2];
    temp_r3 = fn_8012C370(arg1, 0x4D4D5033, &spC, &sp8, 0, 0);
    if (temp_r3 != 0) {
        temp_r31[0] = temp_r3;
        temp_r31[1] = sp8;
    } else {
        fn_802E30C8(&lbl_8034E990, arg1);
    }
}

void fn_802EC32C(long arg0, long arg1) {
    if (arg0 != 0 && arg1 > 0) {
        lbl_80560060 = 0;
    }
}

long fn_802EC348(void *arg0, long arg1) {
    if (arg1 < 0) {
        return 0;
    }
    if (arg1 >= ((long *)arg0)[3]) {
        return 0;
    }
    ((long *)arg0)[2] = arg1;
    return 1;
}

long fn_802EC370(void *arg0) {
    return ((long *)arg0)[3];
}

long fn_802EC3F0(void *arg0, long arg1, long arg2) {
    long value = ((long *)arg0)[1];
    return fn_800B7C60(arg1, arg2, 1, value) == 1;
}

long fn_802EC42C(void *arg0) {
    return fn_800B7C64(((long *)arg0)[1], 0) == 0;
}

long fn_802EC45C(void *arg0) { return ((long *)arg0)[2]; }

typedef signed long s32;
extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern char lbl_8034E990;
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_80560060;
