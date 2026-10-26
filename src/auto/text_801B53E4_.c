// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stddef.h>

extern f32 lbl_80562690;
extern f32 lbl_805626A0;
extern f32 lbl_805626A4;
extern f32 lbl_805626A8;
extern f32 lbl_80435EB8[4];
extern void fn_801B561C(void *, s32, void *, s32, f32, f32, f32, f32, f32, f32);
extern void fn_8002F6AC(void *(*)(void *, s32));
extern void fn_80128668(void *);

s32 fn_801B53E4(void *arg0) {
    s32 var_r5;

    var_r5 = 0;
    if (((u32)(*(s32 *)((u8 *)arg0 + 0x18) + 0xBDB10000) == 0x5820U) &&
        (*(s32 *)((u8 *)arg0 + 0x20) == 0x6E)) {
        var_r5 = 1;
    }
    return var_r5;
}

void fn_801B5410(void *arg0, void *arg1, void *arg2) {
    f32 *m;
    register f32 one;
    register f32 scale;
    register f32 product;
    register f32 sum;

    m = *(f32 **)((u8 *)arg0 + 0xC);
    scale = *(f32 *)((u8 *)arg0 + 0x2C);
    product = m[6] * scale;
    one = lbl_80562690;
    sum = m[9] + product;
    *(f32 *)arg1 = sum;
    product = m[7] * scale;
    sum = m[10] + product;
    *(f32 *)((u8 *)arg1 + 4) = sum;
    product = m[8] * scale;
    sum = m[11] + product;
    *(f32 *)((u8 *)arg1 + 8) = sum;

    scale = -*(f32 *)((u8 *)arg0 + 0x2C);
    product = m[6] * scale;
    sum = m[9] + product;
    *(f32 *)arg2 = sum;
    product = m[7] * scale;
    sum = m[10] + product;
    *(f32 *)((u8 *)arg2 + 4) = sum;
    product = m[8] * scale;
    *(f32 *)((u8 *)arg2 + 4) = one;
    sum = m[11] + product;
    *(f32 *)((u8 *)arg2 + 8) = sum;
    *(f32 *)((u8 *)arg1 + 4) = one;
}

s32 fn_801B54A8(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

void *fn_801B591C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 temp = *(s32 *)((u8 *)arg0 + 8);
        if (temp != 0) {
            ((void (*)(void *, void *(*)(void *, s32)))fn_8002F6AC)((void *)temp, fn_801B591C);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_8055E6E8;
extern s32 lbl_8055E6EC;
extern u8 lbl_80435EC8[];
extern void fn_801A49FC(void *);
extern void fn_80128658(void *);
void fn_801B5984(void *arg0) {
    register s32 *p = (s32 *)arg0;
    p[1] = 0; p[2] = 0; p[0] = 0;
    lbl_8055E6E8 = lbl_8055E6E8 + 1;
}

void fn_801B59A4(void *arg0, s32 arg1, s32 arg2) {
    s32 *state = (s32 *)lbl_80435EC8;
    u8 *record;
    void *node;
    s32 i, offset;
    if (arg2 >= state[1]) state[1] = arg2 + 1;
    record = (u8 *)state[3] + arg2 * 8;
    *(u16 *)record = (u16)state[0];
    *(u16 *)(record + 2) = (u16)(state[0] + (u16)*(s32 *)((u8 *)arg0 + 4));
    *(u16 *)(record + 6) = 0;
    if (*(s32 *)((u8 *)arg0 + 8) != 0) *(u16 *)(record + 4) = (u16)state[1];
    else *(u16 *)(record + 4) = 0;
    node = *(void **)arg0;
    while (node != NULL) {
        *(u16 *)(*(u8 **)(lbl_80435EC8 + 0x18) + state[4] * 2) = (u16)*(s32 *)((u8 *)node + 4);
        state[4]++;
        node = *(void **)((u8 *)node + 8);
    }
    state[0] += *(s32 *)((u8 *)arg0 + 4);
    if (*(s32 *)((u8 *)arg0 + 8) != 0) {
        state[1] += 4; i = 0; offset = 0;
        do {
            fn_801B59A4((u8 *)*(void **)((u8 *)arg0 + 8) + offset, arg1 + 1, (u16)*(u16 *)(record + 4) + i);
            i++; offset += 0xC;
        } while (i < 4);
    }
}

void fn_801B5AE4(void) {
    u8 *buffer;
    lbl_8055E6E8 = 0;
    buffer = lbl_80435EC8;
    lbl_8055E6EC = 0;
    memset(buffer, 0, 0x1C);
}
#pragma scheduling on
void fn_801B5BDC(void **arg0, s32 arg1, void *arg2) {
    s32 n;
    void **dst = arg0;
    void *node = arg2;
    if (arg1 > 0) {
        n = (u32)arg1 >> 3;
        if (n != 0) {
            do {
                dst[0] = node; node = *(void **)((u8 *)node + 0x44);
                dst[1] = node; node = *(void **)((u8 *)node + 0x44);
                dst[2] = node; node = *(void **)((u8 *)node + 0x44);
                dst[3] = node; node = *(void **)((u8 *)node + 0x44);
                dst[4] = node; node = *(void **)((u8 *)node + 0x44);
                dst[5] = node; node = *(void **)((u8 *)node + 0x44);
                dst[6] = node; node = *(void **)((u8 *)node + 0x44);
                dst[7] = node; node = *(void **)((u8 *)node + 0x44);
                dst += 8;
                n--;
            } while (n != 0);
        }
        arg1 &= 7;
        if (arg1 != 0) {
            do {
                *dst++ = node;
                node = *(void **)((u8 *)node + 0x44);
                arg1--;
            } while (arg1 != 0);
        }
    }
}

void fn_801B5C58(void *arg0) {
    s32 index = 0;
    s32 i = 0;
    void *item;
    void *object;
    void **vtable;
    while (i < *(s32 *)arg0) {
        item = *(void **)((u8 *)arg0 + 4);
        item = *(void **)((u8 *)item + index);
        fn_801A49FC(item);
        item = *(void **)((u8 *)arg0 + 4);
        item = *(void **)((u8 *)item + index);
        object = *(void **)((u8 *)item + 0x3C);
        if (object != NULL) {
            vtable = *(void ***)object;
            ((void (*)(void *, s32))vtable[2])(object, 1);
        }
        item = *(void **)((u8 *)arg0 + 4);
        item = *(void **)((u8 *)item + index);
        if (item != NULL) {
            vtable = *(void ***)item;
            ((void (*)(void *, s32))vtable[11])(item, 1);
        }
        index += 4;
        i++;
    }
    fn_80128658(arg0);
}

s32 fn_801B5D10(void *arg0) {
    s32 count = 0;
    goto check;
loop:
    arg0 = *(void **)((u8 *)arg0 + 0x44);
    count++;
check:
    if (arg0 != NULL) goto loop;
    return count;
}

