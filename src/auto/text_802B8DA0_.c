#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
int fn_802B8E50(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

int fn_802B9100(void) {
    return 0;
}

void fn_802B98D0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

int fn_802B9914(void *arg0) {
    return (short)((int *)arg0)[6];
}

extern int lbl_802FAB60[];
int fn_802B9920(int arg0) {
    int v = arg0 + 0x200;
    int idx = (v >> 31) + (v << 27) + ((v << 27) >> 27);
    return (short)lbl_802FAB60[idx];
}

void fn_802B9AA4(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x14);
    arg1[1] = *(float *)((char *)arg0 + 0x18);
    arg2[0] = *(float *)((char *)arg0 + 0x1C);
    arg2[1] = *(float *)((char *)arg0 + 0x20);
}

void fn_802B9AC8(void) {
}

s32 fn_802B9ACC(void *arg0) { return ((s32 *)arg0)[2]; }

void fn_802B9B2C(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B9B40(void *arg0) {
    ((int *)arg0)[1] = 0;
    ((int *)arg0)[0] = 0;
}

int fn_802B9B50(int **arg0, int **arg1) {
    return (*arg0)[2] - (*arg1)[2];
}

void fn_802B9CF4(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B9EC8(void *arg0) {
    void *p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            fn_80128670(((s32 *)p)[3]);
            if (p != 0) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}

void fn_802B9FC0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

extern int lbl_802FAB60[];
extern void *lbl_8055FA84;
void fn_802BA004(void) {
    lbl_8055FA84 = 0;
}

void fn_802BA560(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 8) = 3;
    *(char *)((char *)arg0 + 0xC) = 1;
}

void fn_802BAA50(void *arg0) {
    float a = *(float *)arg0;
    float b = *((float *)arg0 + 1);
    *(float *)arg0 = b;
    *((float *)arg0 + 1) = -a;
}

typedef signed char s8;
void fn_802BAF98(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

