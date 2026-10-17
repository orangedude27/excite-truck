// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct Node604 { f32 lo; f32 hi; u8 pad[0x1C]; struct Node604 *next; } Node604;
void *fn_80128668();
extern f32 lbl_8032C118[];
extern f32 lbl_80559C60;
extern f32 lbl_80561418, lbl_8056141C, lbl_80561420;
f32 fn_80134B58(f32 *, f32);

void *fn_8013A264(void *arg0) {
    f32 base = lbl_80561418;
    f32 *p = lbl_8032C118;
    *(f32 *)((u8 *)arg0 + 0xC) = fn_80134B58(p, base);
    *(f32 *)((u8 *)arg0 + 8) = fn_80134B58(p + 4, base);
    *(f32 *)((u8 *)arg0 + 0x10) = fn_80134B58(p + 8, base);
    *(f32 *)((u8 *)arg0 + 0x18) = fn_80134B58(&lbl_80559C60, lbl_8056141C);
    *(f32 *)((u8 *)arg0 + 0x14) = base;
    *(f32 *)((u8 *)arg0 + 0x1C) = base;
    *(f32 *)((u8 *)arg0 + 4) = lbl_80561420;
    *(s32 *)arg0 = 0;
    return arg0;
}

void **fn_8013A598(void **arg0, s32 arg1) {
    if (arg0 != 0) {
        while (*arg0 != 0) {
            *arg0 = *(void **)((u8 *)*arg0 + 0x24);
            fn_80128668();
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8013A604(void **arg0, f32 value) {
    Node604 *node = (Node604 *)*arg0;
    s32 found;
    while (node != 0) {
        found = 0;
        if (value >= node->lo && value <= node->hi) found = 1;
        if (found) return (u8 *)node + 8;
        node = node->next;
    }
    return (u8 *)arg0 + 4;
}
