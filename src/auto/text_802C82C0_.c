extern int lbl_8055FC70;
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[3];

extern int lbl_8055FC70;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern char lbl_8055FC8C;
extern void *lbl_8055FC90;
void* fn_802C83C4(void) {
    return lbl_8055FC90;
}

extern void *lbl_8055D018;
void fn_802C86E8(void* hi) {
    lbl_8055D018 = hi;
}

extern void fn_802CAD74(void);
void fn_802C8B70(void) {
    fn_802CAD74();
    lbl_8055FC70 = 2;
}

extern void fn_801E4FF4(void);
void fn_802C8E48(void) {
    fn_801E4FF4();
    lbl_8055FC70 = 2;
}

void fn_802C9294(int arg0, int arg1) {
    if (arg0 != -1 && arg0 != -2) {
        char value = arg1 != 1;
        lbl_8055FC75 = !value;
        lbl_8055FC74 = 1;
    } else {
        lbl_8055FC74 = 0;
        lbl_8055FC75 = 0;
    }
    fn_802CB29C();
}

extern void fn_802C8C04(int);
extern void fn_802C8D74(void);
extern int lbl_8055FC70;
extern int fn_802CB29C(void);
extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern void fn_802C92DC(int, int, int, int, int);
#pragma dont_inline on
void fn_802C92D0(void) {
#pragma dont_inline off
    fn_802C8C04(-1);
}

void fn_802C92D8(void) {
    fn_802C8D74();
}

void fn_802C942C(int arg0) {
    fn_802C92D0();
    fn_802C92DC(0, 0, lbl_8055CFF0, lbl_8055CFF4, arg0);
    fn_802C92D8();
}

extern void fn_802C9638(int, int);
extern void fn_802C974C();
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[];
void fn_802C9648(float arg0) {
    float f3 = lbl_8055FC38;
    float f4 = lbl_8055FC3C;
    float f0 = f3 * arg0;
    float f2 = f4 * arg0;
    lbl_804C144C[0] = f3;
    lbl_804C144C[1] = f4;
    lbl_8055FC38 = f0;
    lbl_8055FC3C = f2;
    fn_802C974C(lbl_804C144C, f0, f2, lbl_804C144C[2], f4);
}

void fn_802C967C(void) {
    fn_802C974C(lbl_804C144C, lbl_804C144C[0], lbl_804C144C[1], lbl_804C144C[2]);
}

void *fn_802C9694(void *arg0) {
    ((float *)arg0)[0] = lbl_8055FC38;
    ((float *)arg0)[1] = lbl_8055FC3C;
    ((float *)arg0)[2] = lbl_8055FC40;
    fn_802C974C(arg0);
    return arg0;
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

extern char lbl_804C1440[];
extern float lbl_8055D01C;
void fn_802C99D8(void) {
    fn_802D01B0(lbl_804C1440, lbl_8055D01C);
}

char fn_802C9A58(void) {
    return lbl_8055FC8C;
}

extern char lbl_8055FC8D;
char fn_802C9A60(void) {
    return lbl_8055FC8D;
}

extern char lbl_8055FC8E;
char fn_802C9A68(void) {
    return lbl_8055FC8E;
}

extern void *lbl_8055FC68;
void* fn_802C9C38(void) {
    return lbl_8055FC68;
}

extern void *lbl_8055FC60;
void* fn_802C9C40(void) {
    return lbl_8055FC60;
}

extern void *lbl_8055FC64;
void* fn_802C9C48(void) {
    return lbl_8055FC64;
}

extern void *lbl_8055FC5C;
void* fn_802C9C50(void) {
    return lbl_8055FC5C;
}

