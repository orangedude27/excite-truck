#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012850C(int, int);
extern f32 lbl_805619A0;
void *fn_80128668(void *);
void fn_802C6CF8(int);
void *fn_8016C29C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 16) != 0) {
            int temp = *(int *)arg0;
            *((unsigned char *)arg0 + 16) = 0;
            if (temp != -1) {
                fn_802C6CF8(temp);
                *(int *)arg0 = -1;
            }
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8016C55C(void *arg0, void *arg1) {
    int index;
    void *base;
    void *dst;
    unsigned char byte;
    float x;
    float y;
    index = ((int *)arg0)[1];
    base = *((void **)arg0);
    index = index;
    byte = *(unsigned char *)arg1;
    ((int *)arg0)[1] = index + 1;
    dst = (void *)((char *)base + index * 16);
    *(int *)((char *)arg1 + 0) = *(int *)((char *)arg1 + 0);
    *(unsigned char *)dst = byte;
    *(int *)((char *)dst + 4) = *(int *)((char *)arg1 + 4);
    x = *(float *)((char *)arg1 + 8);
    y = *(float *)((char *)arg1 + 12);
    *(float *)((char *)dst + 8) = x;
    *(float *)((char *)dst + 12) = y;
}

void *fn_8016C598(void *arg0, int arg1, int arg2) {
    int temp = fn_8012850C(arg1 * 16, arg2);
    ((int *)arg0)[0] = temp;
    ((int *)arg0)[3] = temp;
    ((int *)arg0)[2] = arg1;
    ((int *)arg0)[1] = 0;
    return arg0;
}

int fn_8016C760(void *arg0) { return ((int *)arg0)[1]; }

extern f32 lbl_805619A0;
void fn_8016CD10(void *arg0) {
    *((u8 *)arg0 + 0x30) = 0;
    *((u8 *)arg0 + 0x31) = 0;
    *((f32 *)((u8 *)arg0 + 0x34)) = lbl_805619A0;
}

void fn_8016CD28(void *arg0) {
    *((u8 *)arg0 + 0x10) = 0;
    ((s32 *)arg0)[0] = -1;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[3] = 3;
}

void fn_8016CEFC(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

s32 fn_8016DE10(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

u32 fn_80170FD4(void) { return 1; }

void fn_80171208(void *arg0, s32 arg1) {
    fn_801B0C78((void *)arg1);
}
