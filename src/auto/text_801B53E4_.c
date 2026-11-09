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
extern f32 lbl_80562698, lbl_8056269C;
extern s32 lbl_8055E6EC;
extern s32 lbl_8055E6F0;
extern void *lbl_8055E6F4;
extern char lbl_80335E88[], lbl_80335EB4[];
extern void *fn_8012850C(s32, void *);
extern void *fn_8002F37C(void *, void *, void *, s32, s32);
extern void fn_802E317C(const char *, ...);
extern void *fn_801B5984(void *);
extern void *fn_801B591C(void *, s32);
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

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801B561C(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 x0, f32 y0, f32 x1, f32 y1, f32 u1, f32 u2) {
    typedef void (*Rec)(void *, s32, void *, s32, f32, f32, f32, f32);
    f32 r[16];
    u8 hit[4];
    s32 count;
    s32 i;
    f32 h, mx, my, size;
    s32 *node;
    s32 off;
    s32 cnt;
    s32 pool;
    s32 *p2 = (s32 *)arg2;

    h = lbl_80562698;
    mx = h * (x0 + x1);
    my = h * (y0 + y1);
    count = 0;
    r[0] = x0; r[1] = y0; r[2] = mx; r[3] = my;
    r[4] = mx; r[5] = y0; r[6] = x1; r[7] = my;
    r[8] = x0; r[9] = my; r[10] = mx; r[11] = y1;
    r[12] = mx; r[13] = my; r[14] = x1; r[15] = y1;
    off = -1;
    *(s32 *)hit = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_80435EB8[0] < r[i * 4 + 2] && lbl_80435EB8[2] > r[i * 4 + 0]
            && lbl_80435EB8[1] < r[i * 4 + 3] && lbl_80435EB8[3] > r[i * 4 + 1]) {
            hit[i] = 1;
            off = i;
            count++;
        }
    }
    if (count == 0) {
        fn_802E317C(lbl_80335E88);
        return;
    }
    if (count == 1) {
        if (p2[2] == 0) {
            p2[2] = (s32)fn_8002F37C(fn_8012850C(0x40, lbl_80335EB4), fn_801B5984, fn_801B591C, 0xC, 4);
        }
        ((Rec)fn_801B561C)(arg0, arg1, (char *)p2[2] + off * 0xC, arg3 + 1,
                           r[off * 4], r[off * 4 + 1], r[off * 4 + 2], r[off * 4 + 3]);
        return;
    }
    size = x1 - x0;
    h = y1 - y0;
    size = size > h ? size : h;
    if (size < lbl_8056269C) {
        cnt = lbl_8055E6F0;
        pool = (s32)lbl_8055E6F4;
        off = cnt * 0xC;
        lbl_8055E6F0 = cnt + 1;
        node = (s32 *)(pool + off);
        *(s32 *)(pool + off) = (s32)arg0;
        node[1] = arg1;
        node[2] = p2[0];
        p2[0] = (s32)node;
        p2[1]++;
        lbl_8055E6EC++;
        return;
    }
    if (p2[2] == 0) {
        p2[2] = (s32)fn_8002F37C(fn_8012850C(0x40, lbl_80335EB4), fn_801B5984, fn_801B591C, 0xC, 4);
    }
    for (i = 0; i < 4; i++) {
        if (hit[i] != 0) {
            ((Rec)fn_801B561C)(arg0, arg1, (char *)p2[2] + i * 0xC, arg3 + 1,
                               r[i * 4], r[i * 4 + 1], r[i * 4 + 2], r[i * 4 + 3]);
        }
    }
}
#pragma scheduling on
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
void *fn_801B5984(void *arg0) {
    register s32 *p = (s32 *)arg0;
    p[1] = 0; p[2] = 0; p[0] = 0;
    lbl_8055E6E8 = lbl_8055E6E8 + 1;
    return arg0;
}

void fn_801B59A4(void *arg0, s32 arg1, s32 arg2) {
    struct State {
        s32 total;
        s32 max;
        s32 unk8;
        u16 *records;
        s32 used;
        s32 unk14;
        u16 *values;
    } *state = (struct State *)lbl_80435EC8;
    struct Entry {
        struct Entry *nodes;
        s32 count;
        struct Entry *children;
    } *entry = (struct Entry *)arg0;
    volatile u16 *record;
    struct Entry *node;
    s32 childStart;
    s32 i;
    s32 offset;

    if (arg2 >= state->max) {
        state->max = arg2 + 1;
    }

    record = state->records + arg2 * 4;
    record[0] = (u16)state->total;
    record[1] = (u16)(state->total + (u16)entry->count);
    record[3] = 0;
    if (entry->children != NULL) {
        record[2] = (u16)state->max;
    } else {
        record[2] = 0;
    }

    node = entry->nodes;
    while (node != NULL) {
        state->values[state->used] = (u16)node->count;
        state->used++;
        node = *(struct Entry **)((u8 *)node + 8);
    }

    *(s32 *)lbl_80435EC8 = *(s32 *)lbl_80435EC8 + entry->count;
    if (entry->children != NULL) {
        state->max += 4;
        childStart = record[2];
        i = 0;
        offset = 0;
        do {
            fn_801B59A4((u8 *)entry->children + offset, arg1 + 1, childStart);
            childStart++;
            i++;
            offset += 0xC;
        } while (i < 4);
    }
}

#pragma dont_inline on
void fn_801B5AE4(void) {
    u8 *buffer;
    lbl_8055E6E8 = 0;
    buffer = lbl_80435EC8;
    lbl_8055E6EC = 0;
    memset(buffer, 0, 0x1C);
}
#pragma dont_inline reset

void fn_801B5B04(void *arg0, void **arg1, s32 arg2) {
    f32 out[3];
    f32 base;
    s32 i;
    void **item;
    void *obj;
    void **vtbl;

    base = lbl_805626A0;
    item = arg1;
    i = 0;
    do {
        obj = *item;
        obj = *(void **)((u8 *)obj + 0x3C);
        vtbl = *(void ***)obj;
        ((void (*)(void *, f32 *, f32 *))vtbl[14])(obj, &out[1], &out[0]);
        lbl_80435EB8[0] = out[1] - base;
        lbl_80435EB8[1] = out[2] - base;
        lbl_80435EB8[2] = base + out[0];
        lbl_80435EB8[3] = base + out[2];
        fn_801B561C(*item, i, arg0, 0, lbl_805626A4, lbl_805626A4, lbl_805626A8, lbl_805626A8, base + out[0], out[2] - base);
        item = (void **)((u8 *)item + 4);
        i++;
    } while (i < arg2);
}

#pragma scheduling on
void fn_801B5BDC(void **arg0, s32 arg1, void *arg2) {
    void **dst = arg0;
    void *node = arg2;
    for (; arg1 > 0; arg1--) {
        *dst++ = node;
        node = *(void **)((u8 *)node + 0x44);
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

#pragma dont_inline on
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

extern s32 lbl_8055E6F0;
extern void *lbl_8055E6F4;
extern u8 lbl_80335EC8[];
extern u8 lbl_80335ED4[];
extern u8 lbl_8055A8C8[1];
extern void *fn_8012850C(s32, void *);
extern void *fn_801284E8(void *, s32);
extern void fn_80128670(void *);
#pragma optimize_for_size on
#pragma optimize_for_size on
void *fn_801B5D30(s32 *arg0) {
    s32 tmp1[3];
    s32 tmp2[3];
    s32 count;
    s32 size;
    void *buf;
    s32 *obj;
    void *p;
    void *q;

    fn_801B5AE4();
    fn_801B54B0(*arg0);
    count = fn_801B5D10((void *)*arg0);
    size = count * 4;
    buf = fn_8012850C(size, lbl_80335EC8);
    fn_801B5BDC(buf, count, (void *)*arg0);
    tmp1[1] = 0;
    tmp1[2] = 0;
    tmp1[0] = 0;
    lbl_8055E6E8++;
    lbl_8055E6F0 = 0;
    lbl_8055E6F4 = fn_8012850C(0x60000, lbl_80335ED4);
    fn_801B5B04(tmp1, buf, count);
    fn_80128670(buf);
    fn_80128670(lbl_8055E6F4);
    lbl_8055E6F4 = NULL;
    if (tmp1[2] != 0) {
        ((void (*)(void *, void *(*)(void *, s32)))fn_8002F6AC)((void *)tmp1[2], fn_801B591C);
    }
    obj = (s32 *)fn_801284E8(lbl_8055A8C8, size + lbl_8055E6EC * 2 + lbl_8055E6E8 * 8 + 0x18);
    obj[0] = count;
    p = (u8 *)obj + 0x18;
    q = (u8 *)p + count * 4;
    obj[2] = lbl_8055E6EC;
    obj[1] = (s32)p;
    obj[3] = (s32)q;
    obj[4] = (s32)((u8 *)q + lbl_8055E6EC * 2);
    obj[5] = (s32)fn_801B5C58;
    fn_801B5BDC(p, count, (void *)*arg0);
    tmp2[1] = 0;
    tmp2[2] = 0;
    tmp2[0] = 0;
    lbl_8055E6E8++;
    lbl_8055E6F0 = 0;
    lbl_8055E6F4 = fn_8012850C(0x60000, lbl_80335ED4);
    fn_801B5B04(tmp2, (void **)obj[1], obj[0]);
    memset(lbl_80435EC8, 0, 0x1C);
    *(s32 *)lbl_80435EC8 = 0;
    *(s32 *)(lbl_80435EC8 + 8) = lbl_8055E6E8;
    *(s32 *)(lbl_80435EC8 + 0xC) = obj[4];
    *(s32 *)(lbl_80435EC8 + 0x14) = obj[2];
    *(s32 *)(lbl_80435EC8 + 0x18) = obj[3];
    fn_801B59A4(tmp2, 0, 0);
    fn_80128670(lbl_8055E6F4);
    lbl_8055E6F4 = NULL;
    *arg0 = 0;
    if (tmp2[2] != 0) {
        ((void (*)(void *, void *(*)(void *, s32)))fn_8002F6AC)((void *)tmp2[2], fn_801B591C);
    }
    return obj;
}
#pragma optimize_for_size reset
