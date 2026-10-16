extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;

extern int lbl_8055FC70;
extern int lbl_8055FC78;
extern void fn_802CFFAC(unsigned char, unsigned char, unsigned char);
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

int fn_802C90E0(void) {
    return lbl_8055FC70 == 0;
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

void fn_802C9474(void) {
    if ((unsigned char)lbl_8055FC94 != 0) return;
    lbl_8055FC94 = 1;
    fn_802E30C8(lbl_8055D030, lbl_8034B4E0);
}

int fn_802C94A0();
void fn_802C9638(int arg0, int arg1) {
    fn_802C94A0(arg0, arg1, 0);
}

#pragma dont_inline on
void fn_802C9640(int arg0) {
    fn_802C9638(arg0, 0);
}
#pragma dont_inline off
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

void *fn_802C96DC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802C974C(((float *)arg0)[0], ((float *)arg0)[1], ((float *)arg0)[2]);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_802C98DC(float *arg0, float *arg1, float *arg2, float *arg3) {
    *arg0 = lbl_8055FC44;
    *arg1 = lbl_8055FC38;
    *arg2 = lbl_8055FC3C;
    *arg3 = lbl_8055FC48;
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

int fn_802C990C(int arg0) {
    int previous = lbl_8055FC78;
    lbl_8055FC78 = arg0;
    fn_802CFFAC((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC7C;
extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
int fn_802C9950(int arg0) {
    int previous = lbl_8055FC7C;
    lbl_8055FC7C = arg0;
    fn_802D0160((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC80;
extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
int fn_802C9994(int arg0) {
    int previous = lbl_8055FC80;
    lbl_8055FC80 = arg0;
    fn_802D0188((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern char lbl_804C1440[];
extern float lbl_8055D01C;
void fn_802C99D8(void) {
    fn_802D01B0(lbl_804C1440, lbl_8055D01C);
}

float fn_802C99E8(float arg0) {
    float previous = lbl_8055D01C;
    lbl_8055D01C = arg0;
    fn_802C99D8();
    return previous;
}

void fn_802C9A1C(float *arg0) {
    float x = arg0[0];
    float y = arg0[1];
    float z = arg0[2];
    lbl_804C1440[0] = x;
    lbl_804C1440[1] = y;
    lbl_804C1440[2] = z;
    fn_802C99D8();
}

void *fn_802C9A40(void) {
    return lbl_804C1440;
}

void fn_802C9A4C(void) {
    fn_802D93E0();
}

#pragma dont_inline off
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

int fn_802C9C24(void *arg0) {
    void *p = *(void **)((char *)arg0 + 8);
    void *q = *(void **)((char *)p + 4);
    return *(int *)q + 4;
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
extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;
