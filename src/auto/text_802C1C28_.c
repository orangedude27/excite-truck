// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055CFA0, lbl_8055FB2C, lbl_8055FB30;
extern float lbl_804C1050[16];
extern float lbl_8055FB38;
extern float lbl_80564E50, lbl_80564E54, lbl_80564E60, lbl_80564E70, lbl_80564E78, lbl_80564E7C, lbl_80564E80, lbl_80564E84, lbl_80564E88;
extern void *fn_802C110C(int);
extern void *fn_802C120C(void);
extern float fn_80129DC4(int, float, float);
extern void *lbl_8055FB50;
extern int lbl_8034AFB8;
extern int lbl_8034AFC8;
extern char lbl_8034AFD8[];
extern int lbl_8055FB54;
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void fn_802B52C0(void *);
int fn_802CA294(void *, int, int, int, void *);
int fn_802D9628(short, short, unsigned int);
void fn_802C1C28(void) {}

void fn_802C1C2C(void) {}

void fn_802C1C30(void) {}

#pragma dont_inline on
void fn_802C1F80(int arg0) {}

#pragma dont_inline on
void fn_802C1F84(int arg0) {}

void fn_802C1F88(int arg0) {}

#pragma dont_inline off

void fn_802C2054(int arg0) { fn_802C1F80(arg0 - 4); }

void fn_802C205C(int arg0) { fn_802C1F84(arg0 - 4); }

void fn_802C2064(int arg0) { fn_802C1F88(arg0 - 4); }

void fn_802C206C(int arg0) { fn_802C1F8C(arg0 - 4); }

int fn_802C2074(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802C20DC(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

short fn_802C2120(int arg0) {
    return (short)(((arg0 << 8) / 1024) + 0x80);
}

#pragma dont_inline on
void fn_802C217C(void) {
    fn_802C20DC((int *)&lbl_8055FB50);
    if (lbl_8055FB54 == 0) return;
    fn_802B52B4();
    lbl_8055FB54 = 0;
}
#pragma dont_inline reset
void* fn_802C21B8(void) {
    return lbl_8055FB50;
}

void fn_802C21C0(void) {
    int value = lbl_8055FB54;
    if (value != 0) fn_802B52C0(lbl_8034AFD8);
}

void fn_802C21DC(int x, int y, unsigned int color) {
    int packed;
    short sx, sy;
    int *state;
    if (lbl_8055FB54 != 0) {
        packed = ((color & 0xFF) << 24) | ((color & 0xFF00) << 8) | ((color & 0xFF0000) >> 8) | ((color >> 24) & 0xFF);
        sx = fn_802C2120(x);
        sy = fn_802C2120(y);
        state = (int *)lbl_8055FB54;
        ((unsigned int *)state[2])[sx + (state[0] * (state[1] - 1 - sy))] = packed;
        fn_802CA294(lbl_8055FB50, sx, 0, sy, (void *)lbl_8055FB54);
        fn_802D9628(sx, sy, packed);
    }
}

