#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct PhobNode {
    s32 value;
    struct PhobNode *next;
} PhobNode;

extern s32 lbl_8055E708;
extern s32 lbl_8055E70C;
extern s32 lbl_8055E714;
extern void fn_80128668(s32);
extern void fn_80128670(s32);
extern f32 lbl_805626B0;
extern f32 lbl_805626B4;
extern void *lbl_8055E710;
extern char lbl_80335EE0[];
extern void fn_802E317C(const char *, ...);
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_801B5F40(void) {
    void *node = lbl_8055E710;
    if (node) {
        lbl_8055E710 = ((void **)node)[1];
        ((void **)node)[1] = 0;
        return node;
    }
    fn_802E317C(lbl_80335EE0);
    return 0;
}
#pragma scheduling on
#pragma dont_inline reset

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
#pragma scheduling invalid_target
void fn_801B5FA0(void) {
    /* Initialize the Phob (physics object) node pools and free list. */
    s32 count;
    s32 offset;
    s32 i;
    void *node;
    void *memory;

    count = lbl_8055A8D0;
    memory = fn_8012850C((count << 3) + 0x10, lbl_80335EE0 + 0x18);
    lbl_8055E708 = fn_8002F37C(memory, (void *)NWC24Data_Init_801B6098, 0, 8, count);
    memory = fn_8012850C(0x9C50, lbl_80335EE0 + 0x28);
    lbl_8055E70C = fn_8002F37C(memory, (void *)fn_801B608C, 0, 4, 0x2710);
    count = 0;
    lbl_8055E710 = 0;
    node = fn_801284F8(4, lbl_80335EE0 + 0x34);
    if (node != 0) {
        *(s32 *)node = count;
    }
    lbl_8055E714 = (s32)node;
    i = 0;
    offset = 0;
    while (i < lbl_8055A8D0) {
        i++;
        node = (u8 *)lbl_8055E708 + offset;
        *(void **)((u8 *)node + 4) = lbl_8055E710;
        offset += 8;
        lbl_8055E710 = node;
    }
}
#pragma scheduling on
void fn_801B608C(s32 *arg0) {
    *arg0 = 0;
}

void NWC24Data_Init_801B6098(s32 *arg0) { arg0[0] = 0; arg0[1] = 0; }

void fn_801B60A8(void) {
    fn_80128668(lbl_8055E714);
    if (lbl_8055E708 != 0) fn_80128670(lbl_8055E708 - 0x10);
    if (lbl_8055E70C != 0) fn_80128670(lbl_8055E70C - 0x10);
}

s32 fn_801B60F4(void *arg0, f32 arg1) {
    s32 x;
    s32 y;
    if (arg1 > lbl_805626B0)
        return lbl_8055E714;
    x = (s32)((*(f32 *)arg0 + lbl_805626B4) / lbl_805626B0);
    if (x < 0)
        x = 0;
    else if (x >= 0x64)
        x = 0x63;
    y = (s32)((*(f32 *)((u8 *)arg0 + 8) + lbl_805626B4) / lbl_805626B0);
    if (y < 0)
        y = 0;
    else if (y >= 0x64)
        y = 0x63;
    return lbl_8055E70C + ((x + y * 0x64) * 4);
}

extern float lbl_805626B8;
static inline s32 GridCell(f32 v) {
    s32 i;
    v += lbl_805626B4;
    i = __OSf32tos32_801B619C(v / lbl_805626B0);
    if (i < 0)
        i = 0;
    else if (i >= 0x64)
        i = 0x63;
    return i;
}
#pragma peephole off
void fn_801B619C(u32 *arg0, s32 *arg1, f32 *arg2) {
    s32 x0 = GridCell(arg2[0] - lbl_805626B8);
    s32 x1 = GridCell(lbl_805626B8 + arg2[0]);
    s32 y0 = GridCell(arg2[2] - lbl_805626B8);
    s32 y1 = GridCell(lbl_805626B8 + arg2[2]);
    if (x0 != x1) {
        if (y0 != y1) {
            *arg1 = 4;
            arg0[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
            arg0[1] = lbl_8055E70C + ((x1 + y0 * 100) * 4);
            arg0[2] = lbl_8055E70C + ((x0 + y1 * 100) * 4);
            arg0[3] = lbl_8055E70C + ((x1 + y1 * 100) * 4);
        } else {
            *arg1 = 2;
            arg0[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
            arg0[1] = lbl_8055E70C + ((x1 + y0 * 100) * 4);
        }
    } else if (y0 != y1) {
        *arg1 = 2;
        arg0[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
        arg0[1] = lbl_8055E70C + ((x0 + y1 * 100) * 4);
    } else {
        *arg1 = 1;
        arg0[0] = lbl_8055E70C + ((x0 + y0 * 100) * 4);
    }
    {
        arg0[(*arg1)++] = lbl_8055E714;
    }
}
#pragma peephole reset
extern void *fn_801B5F40(void);
extern void __AXPushCallbackStack(void *);
extern char lbl_80335F20[];
void fn_801B63E0(void **head, s32 value) {
    void *node = fn_801B5F40();
    *(s32 *)node = value;
    *(void **)((u8 *)node + 4) = *head;
    *head = node;
}

#pragma scheduling on
#pragma dont_inline on
void fn_801B6428(void **head, void *value) {
    void *node = *head;
    void *prev;
    void *cur;
    if (*(void **)node == value) {
        *head = *(void **)((u8 *)node + 4);
        __AXPushCallbackStack(node);
        return;
    }
    prev = node;
    cur = *(void **)((u8 *)node + 4);
    while (cur != 0) {
        if (*(void **)cur == value) {
            *(void **)((u8 *)prev + 4) = *(void **)((u8 *)cur + 4);
            __AXPushCallbackStack(cur);
            return;
        }
        prev = cur;
        cur = *(void **)((u8 *)cur + 4);
    }
    fn_802E317C(lbl_80335F20);
}
