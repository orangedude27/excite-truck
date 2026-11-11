// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stddef.h>
#include <revolution/MTX/mtxtypes.h>

/* One link of the object list fn_801B5D30 packs into a quad tree; the same
 * list fn_801B5D10 counts and fn_801B5BDC turns into an array. */
struct ObjectLink {
    u8 pad[0x3C];
    void *object;              /* +0x3C: the BPX object this link stands for */
    u8 pad_40[4];
    struct ObjectLink *next;   /* +0x44: the next link, NULL at the list's end */
};

/* A BPX scene object, as far as this unit reads it.  Its 3x4 transform holds a
 * direction in [6..8] and its position in [9..11]; fn_801B5410 walks the
 * position by +-length along that direction to get the two ends of the
 * straight segment the object stands for. */
struct BpxObject {
    u8 pad[0x0C];
    f32 *matrix;  /* +0x0C */
    u32 magic;    /* +0x18: 'BPX ' */
    u32 kind;     /* +0x20: what the object is; fn_801B53E4 filters on it */
    f32 length;   /* +0x2C: how far each end sits from the position */
    s32 links;    /* +0x34: bit 0 / bit 1 - the first / second end has a neighbour */
};

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
    f32 scale;
    f32 product;
    f32 sum;
    f32 one;
    f32 m6;
    f32 m9;
    m = *(f32 **)((u8 *)arg0 + 0xC);
    scale = *(f32 *)((u8 *)arg0 + 0x2C);
    m6 = m[6];
    m9 = m[9];
    product = m6 * scale;
    sum = m9 + product;
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
    one = lbl_80562690;
    product = m[8] * scale;
    *(f32 *)((u8 *)arg2 + 4) = one;
    sum = m[11] + product;
    *(f32 *)((u8 *)arg2 + 8) = sum;
    *(f32 *)((u8 *)arg1 + 4) = one;
}

s32 fn_801B54A8(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

extern float lbl_80562694;
extern float PSVECSquareDistance(void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_801B54B0(s32 arg0) {
    s32 sp2C[3];
    s32 sp20[3];
    s32 sp14[3];
    s32 sp8[3];
    f32 threshold;
    void *outer;
    void *inner;
    void *a;
    void *b;
    threshold = lbl_80562694;
    outer = (void *)arg0;
    while (outer != NULL) {
        if (fn_801B53E4(*(void **)((u8 *)outer + 0x3C)) != 0) {
            a = (void *)fn_801B54A8(outer);
            fn_801B5410(*(void **)((u8 *)outer + 0x3C), sp2C, sp20);
            inner = (void *)arg0;
            while (inner != NULL) {
                if (fn_801B53E4(*(void **)((u8 *)inner + 0x3C)) != 0) {
                    b = (void *)fn_801B54A8(inner);
                    fn_801B5410(*(void **)((u8 *)inner + 0x3C), sp14, sp8);
                    if (PSVECSquareDistance(sp2C, sp14) < threshold) {
                        *(s32 *)((u8 *)a + 0x34) |= 1;
                        *(s32 *)((u8 *)b + 0x34) |= 1;
                    }
                    if (PSVECSquareDistance(sp2C, sp8) < threshold) {
                        *(s32 *)((u8 *)a + 0x34) |= 1;
                        *(s32 *)((u8 *)b + 0x34) |= 2;
                    }
                    if (PSVECSquareDistance(sp20, sp14) < threshold) {
                        *(s32 *)((u8 *)a + 0x34) |= 2;
                        *(s32 *)((u8 *)b + 0x34) |= 1;
                    }
                    if (PSVECSquareDistance(sp20, sp8) < threshold) {
                        *(s32 *)((u8 *)a + 0x34) |= 2;
                        *(s32 *)((u8 *)b + 0x34) |= 2;
                    }
                }
                inner = *(void **)((u8 *)inner + 0x44);
            }
        }
        outer = *(void **)((u8 *)outer + 0x44);
    }
}
#pragma pop

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
    extern u8 lbl_80435EC8[];
    struct Entry { struct Entry *nodes; s32 count; struct Entry *children; } *entry = (struct Entry *)arg0;
    u16 *records; u16 *record; struct Entry *node; s32 childStart; s32 offset; s32 w;
    s32 max = *(s32 *)(lbl_80435EC8 + 4);
    if (arg2 >= max) { *(s32 *)(lbl_80435EC8 + 4) = arg2 + 1; }
    records = *(u16 **)(lbl_80435EC8 + 0xC);
    record = records + arg2 * 4;
    record[0] = *(u16 *)lbl_80435EC8;
    record[1] = *(u16 *)lbl_80435EC8 + (u16)entry->count;
    record[3] = 0;
    if (entry->children != NULL) { record[2] = *(u16 *)(lbl_80435EC8 + 4); } else { record[2] = 0; }
    node = entry->nodes;
    while (node != NULL) {
        (*(u16 **)(lbl_80435EC8 + 0x18))[*(s32 *)(lbl_80435EC8 + 0x10)] = (u16)node->count;
        (*(s32 *)(lbl_80435EC8 + 0x10))++;
        node = *(struct Entry **)((u8 *)node + 8);
    }
    *(s32 *)lbl_80435EC8 = *(s32 *)lbl_80435EC8 + entry->count;
    if (entry->children != NULL) {
        *(s32 *)(lbl_80435EC8 + 4) += 4;
        childStart = record[2]; offset = 0; w = 0;
        do {
            fn_801B59A4((u8 *)entry->children + offset, arg1 + 1, childStart);
            childStart++; w++; offset += 0xC;
        } while (w < 4);
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

#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_801B5B04(void *arg0, void **arg1, s32 arg2) {
    class V {
    public:
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(float *, float *);
    };
    f32 out[6];
    f32 base;
    void **item;
    s32 i;
    void *obj;

    base = lbl_805626A0;
    item = arg1;
    for (i = 0; i < arg2; i++) {
        obj = *item;
        obj = *(void **)((u8 *)obj + 0x3C);
        ((V *)obj)->m12(&out[3], &out[0]);
        lbl_80435EB8[1] = out[5] - base;
        lbl_80435EB8[0] = out[3] - base;
        lbl_80435EB8[2] = base + out[0];
        lbl_80435EB8[3] = base + out[2];
        fn_801B561C(*item, i, arg0, 0, lbl_805626A4, lbl_805626A4, lbl_805626A8, lbl_805626A8, base + out[0], out[5] - base);
        item++;
    }
}
#pragma pop
void fn_801B5BDC(void **arg0, s32 arg1, void *arg2) {
    void **dst = arg0;
    void *node = arg2;
    for (; arg1 > 0; arg1--) {
        *dst++ = node;
        node = *(void **)((u8 *)node + 0x44);
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801B5C58(void *arg0) {
    class D {
    public:
        virtual void m0(int);
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9(int);
    };
    s32 index = 0;
    s32 i = 0;
    void *item;
    void *object;
    while (i < *(s32 *)arg0) {
        item = *(void **)((unsigned char *)arg0 + 4);
        item = *(void **)((unsigned char *)item + index);
        fn_801A49FC(item);
        item = *(void **)((unsigned char *)arg0 + 4);
        item = *(void **)((unsigned char *)item + index);
        object = *(void **)((unsigned char *)item + 0x3C);
        if (object != 0) {
            ((D *)object)->m0(1);
        }
        item = *(void **)((unsigned char *)arg0 + 4);
        item = *(void **)((unsigned char *)item + index);
        if (item != 0) {
            ((D *)item)->m9(1);
        }
        index += 4;
        i++;
    }
    fn_80128658(arg0);
}
#pragma pop
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
