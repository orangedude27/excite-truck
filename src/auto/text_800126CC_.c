#include "decomp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80012790(void) {
    fn_80012984();
}

extern void *lbl_80558AD8;
void* fn_80012810(void) {
    return lbl_80558AD8;
}

extern void *lbl_8055D504;
void* fn_80012818(void) {
    return lbl_8055D504;
}

extern void *lbl_8055D508;
void* fn_80012854(void) {
    return lbl_8055D508;
}

extern void *fn_8001285C(void);
extern char *fn_80012820(int);
extern const char *fn_80007FF0(int);
extern int fn_80012938(float);
extern float lbl_80560358;
void fn_80012910(void) {
    fn_80007FF0(*(int *)((char *)fn_8001285C() + 8));
}

int fn_80012938(float f) {
    if (f > lbl_80560358) {
        return 2;
    }
    return 1;
}

void fn_80012954(void) {
    char *p = fn_80012820(*(int *)((char *)fn_8001285C() + 4));
    fn_80012938(*(float *)(p + 0x78));
}

