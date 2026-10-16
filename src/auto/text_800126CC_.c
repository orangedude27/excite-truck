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

extern int lbl_8055D508;
void* fn_80012854(void) {
    return (void*)lbl_8055D508;
}

extern char lbl_80352AD0[];
extern int lbl_802FC700;
extern void fn_802E317C(int *, int, int);
extern void fn_80131818(void *);
extern char lbl_8035183C[];
extern char lbl_8055D500;
extern int lbl_8055D514;
extern char lbl_803518C0[];
extern char lbl_803551E0[];
void *fn_80012870(int arg0, int arg1) {
    char *p = &lbl_80352AD0[0];
    int i = 0;
    int j = 0;
    int count = lbl_8055D508;
    while (count > 0) {
        if (*(int *)(p + 4) == arg0 && p[0x24] != 0 && j == arg1) {
            return &lbl_80352AD0[i * 0x28];
        }
        j++;
        p += 0x28;
        i++;
        count--;
    }
    fn_802E317C(&lbl_802FC700, arg0, arg1);
    return 0;
}

extern void *fn_8001285C(void);
extern char *fn_80012820(int);
extern const char *fn_80007FF0(int);
extern int fn_80012938(float);
extern float lbl_80560358;
void fn_80012910(void) {
    fn_80007FF0(*(int *)((char *)fn_8001285C() + 8));
}

int fn_80012938(float f) DECOMP_DONT_INLINE {
    if (f > lbl_80560358) {
        return 2;
    }
    return 1;
}

void fn_80012954(void) {
    char *p = fn_80012820(*(int *)((char *)fn_8001285C() + 4));
    fn_80012938(*(float *)(p + 0x78));
}

