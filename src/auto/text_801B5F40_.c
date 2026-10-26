#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055E708;
extern s32 lbl_8055E70C;
extern s32 lbl_8055E714;
extern void fn_80128668(s32);
extern void fn_80128670(s32);
extern f32 lbl_805626B0;
extern f32 lbl_805626B4;
extern void *lbl_8055E710;
extern char lbl_80335EE0[];
extern void fn_802E317C(const char *);
void __AXPushCallbackStack(void *arg0) {
    *((void **)arg0 + 1) = lbl_8055E710;
    lbl_8055E710 = arg0;
}

extern void *fn_8012850C(s32, void *);
extern s32 fn_8002F37C(void *, void *, s32, s32, s32);
extern void *fn_801284F8(s32, void *);
extern void NWC24Data_Init_801B6098(s32 *);
extern void fn_801B608C(s32 *);
extern s32 lbl_8055A8D0;
void fn_801B5FA0(void) {
    s32 count;
    s32 offset;
    void *node;
    void *previous;
    void *memory;

    count = lbl_8055A8D0;
    memory = fn_8012850C((count << 3) + 0x10, (u8 *)&lbl_80335EE0 + 0x18);
    lbl_8055E708 = fn_8002F37C(memory, (void *)NWC24Data_Init_801B6098, 0, 8, count);
    memory = fn_8012850C(0x9C50, (u8 *)&lbl_80335EE0 + 0x28);
    lbl_8055E70C = fn_8002F37C(memory, (void *)fn_801B608C, 0, 4, 0x2710);
    count = 0;
    lbl_8055E710 = 0;
    node = fn_801284F8(4, (u8 *)&lbl_80335EE0 + 0x34);
    if (node != 0) {
        *(s32 *)node = 0;
    }
    lbl_8055E714 = (s32)node;
    previous = lbl_8055E710;
    offset = 0;
    while (count < lbl_8055A8D0) {
        count++;
        node = (u8 *)lbl_8055E708 + offset;
        *(void **)((u8 *)node + 4) = previous;
        previous = node;
        offset += 8;
        lbl_8055E710 = node;
    }
}

void fn_801B608C(s32 *arg0) {
    *arg0 = 0;
}

void NWC24Data_Init_801B6098(s32 *arg0) { arg0[0] = 0; arg0[1] = 0; }

void fn_801B60A8(void) {
    fn_80128668(lbl_8055E714);
    if (lbl_8055E708 != 0) fn_80128670(lbl_8055E708 - 0x10);
    if (lbl_8055E70C != 0) fn_80128670(lbl_8055E70C - 0x10);
}

s32 fn_801B60F4(f32 *arg0, f32 arg1) {
    f32 step = lbl_805626B0;
    s32 x;
    s32 y;
    if (!(arg1 <= step)) return lbl_8055E714;
    x = (s32)((arg0[0] + lbl_805626B4) / step);
    if (x < 0) x = 0;
    else if (x >= 100) x = 99;
    y = (s32)((arg0[2] + lbl_805626B4) / step);
    if (y < 0) y = 0;
    else if (y >= 100) y = 99;
    return (s32)((u32)lbl_8055E70C + ((y * 100 + x) * 4));
}

extern float lbl_805626B8;
#pragma scheduling invalid_target
void fn_801B619C(void *arg0, int *arg1, float *arg2) {
    int x0, x1, y0, y1, count;
    float t;
    t = arg2[0] - lbl_805626B8; t = t + lbl_805626B4; x0 = (int)(t / lbl_805626B0);
    if (x0 < 0) x0 = 0; else if (x0 >= 100) x0 = 99;
    t = lbl_805626B8 + arg2[0]; t = t + lbl_805626B4; x1 = (int)(t / lbl_805626B0);
    if (x1 < 0) x1 = 0; else if (x1 >= 100) x1 = 99;
    t = arg2[2] - lbl_805626B8; t = t + lbl_805626B4; y0 = (int)(t / lbl_805626B0);
    if (y0 < 0) y0 = 0; else if (y0 >= 100) y0 = 99;
    t = lbl_805626B8 + arg2[2]; t = t + lbl_805626B4; y1 = (int)(t / lbl_805626B0);
    if (y1 < 0) y1 = 0; else if (y1 >= 100) y1 = 99;
    if (x0 != x1) {
        if (y0 != y1) {
            *arg1 = 4;
            ((unsigned int *)arg0)[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
            ((unsigned int *)arg0)[1] = lbl_8055E70C + ((x1 + y0 * 100) * 4);
            ((unsigned int *)arg0)[2] = lbl_8055E70C + ((x0 + y1 * 100) * 4);
            ((unsigned int *)arg0)[3] = lbl_8055E70C + ((x1 + y1 * 100) * 4);
        } else {
            *arg1 = 2;
            ((unsigned int *)arg0)[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
            ((unsigned int *)arg0)[1] = lbl_8055E70C + ((x1 + y0 * 100) * 4);
        }
    } else if (y0 != y1) {
        *arg1 = 2;
        ((unsigned int *)arg0)[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
        ((unsigned int *)arg0)[1] = lbl_8055E70C + ((x0 + y1 * 100) * 4);
    } else {
        *arg1 = 1;
        ((unsigned int *)arg0)[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
    }
    count = *arg1;
    ((unsigned int *)arg0)[count] = lbl_8055E714;
    *arg1 = count + 1;
}
#pragma scheduling on
extern void *fn_801B5F40(void);
extern void __AXPushCallbackStack(void *);
extern char lbl_80335F20[];
void fn_801B63E0(void **head, s32 value) {
    void *node = fn_801B5F40();
    *(s32 *)node = value;
    *(void **)((u8 *)node + 4) = *head;
    *head = node;
}

#pragma scheduling invalid_target
void fn_801B6428(void **head, void *value) {
    void *node = *head;
    void *next;
    if (*(void **)node == value) {
        *head = *(void **)((u8 *)node + 4);
        __AXPushCallbackStack(node);
        return;
    }
    next = *(void **)((u8 *)node + 4);
    if (next != 0) {
        if (*(void **)next == value) {
            *(void **)((u8 *)node + 4) = *(void **)((u8 *)next + 4);
            __AXPushCallbackStack(next);
        } else {
            fn_802E317C((const char *)&lbl_80335F20);
        }
    }
}
#pragma scheduling on
