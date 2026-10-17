// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <macros.h>

extern char lbl_8055D07D;
char fn_802CA7D4(void) { return 1; }

char fn_802CA7DC(const char *arg0) { return (signed char)*arg0 == 0x2A; }

int fn_802CA7F4(const char *arg0) { return strchr(arg0, 0x2F) != 0; }

int fn_802DB2C0(int);
int fn_802CA57C(int, int, int);
int fn_802CA4E0(int, int, int, int, int);
int fn_802CA898(int, int, int);
void fn_802D8FB4(void);
extern int lbl_8055D058;
extern int lbl_8055D078;
void fn_802CB38C(int arg0, int arg1, int arg2) {
    fn_802CA57C(lbl_8055D078, 0, arg2);
    fn_802CA4E0(arg0, lbl_8055D058, 0, arg1, arg0);
}

void fn_802CB3F4(void) {
    fn_802D8FB4();
}

void fn_802CB3F8(void) {
}

extern char lbl_8055FCBC[];
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
extern float lbl_80564F40;
extern float lbl_80564F44;
extern float lbl_8055FCC4;
  extern unsigned short lbl_8055FCA8;
int fn_802CAF8C(int arg0) {
    if (arg0 == -1)
        return 0;
    return *(unsigned short *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 0xC) != lbl_8055FCA8;
}
void fn_802CC550(int, float, float);
int fn_802CB274(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C0(p[0x28 / 4]);
}

int fn_802DB2C4(int);
int fn_802CB288(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C4(p[0x28 / 4]);
}

char fn_802CAFC8(int arg0) {
    if (arg0 == -1)
        return 5;
    return *(char *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 8);
}

char fn_802CAFF0(int arg0) {
    if (arg0 == -1)
        return 0x32;
    return *(char *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 9);
}

unsigned short fn_802CB3FC(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    unsigned short *q = (unsigned short *)p[0x2C / 4];
    if ((int)q[1] > (int)q[0])
        return q[1];
    return q[0];
}
void fn_802CC73C(char arg0) {
    lbl_8055D07D = arg0;
}

char fn_802CC744(void) {
    return lbl_8055D07D;
}

int fn_802CC74C(void) {
    char *p = *(char **)lbl_8055FCBC;
    if (p == 0)
        return 0;
    if (*(int *)(p + 4) == 0)
        return 0;
    return 1;
}

extern void fn_802E317C(const char *, ...);
extern char lbl_8034B7D0[];
extern char fn_802CA7DC(const char *);
