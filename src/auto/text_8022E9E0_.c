#include <types.h>

extern s32 lbl_8055EFF4;
extern void **lbl_8055EFF8;
extern s32 lbl_8055EFFC;
extern void **lbl_8055F000;
extern char lbl_80340280[];
extern char lbl_80340290[];
extern void *fn_801284F8(u32, void *);
typedef void (*VFunc)(s32);
struct Vtbl8022E { void *pad; VFunc dtor; };
extern void *fn_8012A13C(void *, void *, u32, u32);
extern void *fn_8012A2D8(void **);
extern void fn_8012A364(void **, void *);
extern void fn_8012A570(u32, void *);
extern void fn_8012A5E8(void *);
extern s32 lbl_8055F004;
extern char lbl_803402A0[];
extern char lbl_80340344[];
extern char lbl_803402F4[];
extern char lbl_80340308[];
extern void fn_802E317C(const char *);
extern void fn_802E30C8(char *);
extern void fn_8022ED50(s32);
extern f32 lbl_805635E0;
extern f32 lbl_805635E4;
extern void fn_80128668(void *);
extern void *fn_8022EC7C(void);
extern void *fn_8022ECC0(s32);

/* Fixed-size object pool built by fn_8012A13C/fn_8012A17C: one block of
 * `count` elements of `stride` bytes, threaded into a free list that starts
 * at the block itself (fn_8012A218).  fn_8012A2D8 pops an element off it and
 * fn_8012A364 pushes one back; `live` counts the elements handed out. */
typedef struct ObjectPool {
    void *vtbl;           /* 0x00 */
    u8 warnWhenEmpty;     /* 0x04 */
    u8 ownsBlock;         /* 0x05 */
    const char *name;     /* 0x08 */
    void *block;          /* 0x0C */
    void *free;           /* 0x10 free list head */
    s32 stride;           /* 0x14 element size */
    s32 count;            /* 0x18 capacity */
    s32 live;             /* 0x1C elements handed out */
} ObjectPool;             /* 0x20 bytes */

#define STR_CNODE_POOL      lbl_80340280 /* "cnode::pool" */
#define STR_UICONTEXT_POOL  lbl_80340290 /* "UIContext::pool" */
#define sCNodePool          lbl_8055EFF8 /* ObjectPool of 8-byte cnodes */
#define sCNodeLiveCount     lbl_8055EFF4 /* cnodes handed out */
#define sUIContextPool      lbl_8055F000 /* ObjectPool of 0x3c-byte UIContexts */
#define sUIContextLiveCount lbl_8055EFFC /* UIContexts handed out */

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void fn_8022E9E0(void) {
    if (lbl_8055EFF4 == 0) {
        void *p = fn_801284F8(0x20, (void *)&lbl_80340280);
        if (p) p = fn_8012A13C(p, lbl_80340280, 0x20, 8);
        lbl_8055EFF8 = (void **)p;
    }
    if (((int (*)(void **))fn_8012A2D8)(lbl_8055EFF8) != 0) {
        *(volatile s32 *)&lbl_8055EFF4 = *(volatile s32 *)&lbl_8055EFF4 + 1;
    }
}
#pragma scheduling reset
#pragma cplusplus on
extern "C" void fn_8022EA58(void *arg0) {
    class Unk8022EA58 { public: virtual ~Unk8022EA58(); };
    fn_8012A364(lbl_8055EFF8, arg0);
    if (--lbl_8055EFF4 == 0) {
        delete (Unk8022EA58 *)lbl_8055EFF8;
        lbl_8055EFF8 = 0;
    }
}
#pragma cplusplus reset
void fn_8022EAB8(void) {
    if (!lbl_8055EFFC) {
        void *p;
        p = fn_801284F8(0x20, (void *)&lbl_80340290[0]);
        lbl_8055F000 = (void **)(p ? fn_8012A13C(p, lbl_80340290, 0x20, 0x3c) : p);
    }
    if (!fn_8012A2D8(lbl_8055F000)) return;
    lbl_8055EFFC = 1 + lbl_8055EFFC;
}

#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_8022EB30(void *arg0) {
    class Unk8022EB30 { public: virtual ~Unk8022EB30(); };
    fn_8012A364(lbl_8055F000, arg0);
    if (--lbl_8055EFFC == 0) {
        delete (Unk8022EB30 *)lbl_8055F000;
        lbl_8055F000 = 0;
    }
}
#pragma cplusplus reset
#pragma push
#pragma scheduling invalid_target
void fn_8022EB90(void) {
    if (lbl_8055F004 != 0) ((void (*)(const char *, ...))fn_802E317C)(lbl_803402A0);
    lbl_8055F004 = (s32)fn_801284F8(8, lbl_803402F4);
    *(s32 *)lbl_8055F004 = 0;
    ((s32 *)lbl_8055F004)[1] = *(s32 *)lbl_8055F004;
}
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8022EBF0(void) {
    void *node;

    if (((s32 *)lbl_8055F004)[1] != 0) {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_80340308);
        node = fn_8022EC7C();
        goto test;
loop:
        fn_8022ED50(((s32 *)lbl_8055F004)[1]);
        node = fn_8022EC7C();
test:
        if (node != 0)
            goto loop;
        fn_8022EA58((void *)((s32 *)lbl_8055F004)[1]);
        ((s32 *)lbl_8055F004)[1] = 0;
        ((s32 *)lbl_8055F004)[0] = 0;
    }
    fn_80128668((void *)lbl_8055F004);
    lbl_8055F004 = 0;
}
#pragma dont_inline off
#pragma pop
void *fn_8022EC7C(void) {
    u32 *p = (u32 *)lbl_8055F004;
    u32 *node = (u32 *)p[0];
    u32 tail;
    if (!node) return 0;
    tail = p[1];
    if ((u32)node == tail) return 0;
    while (node[1] != tail) node = (u32 *)node[1];
    return node;
}

extern s32 lbl_8055B980;
void *fn_8022ECC0(s32 arg0) {
    void *p = ((void *(*)(s32, void *))fn_8022E9E0)(8, &lbl_8055B980);
    ((s32 *)p)[0] = arg0;
    ((s32 *)p)[1] = 0;
    return p;
}

void fn_8022ED00(void) {
    s32 *p = (s32 *)((void *(*)(void))fn_8022ECC0)();
    if (((s32 *)lbl_8055F004)[1] == 0) {
        ((s32 *)lbl_8055F004)[0] = (s32)p;
        ((s32 *)lbl_8055F004)[1] = ((s32 *)lbl_8055F004)[0];
    } else {
        ((s32 *)((s32 *)lbl_8055F004)[1])[1] = (s32)p;
        ((s32 *)lbl_8055F004)[1] = (s32)p;
    }
}

#pragma dont_inline on
void fn_8022ED50(s32 arg0) {
    void *node;
    node = fn_8022EC7C();
    if (node == 0) {
        ((s32 *)lbl_8055F004)[1] = 0;
        ((s32 *)lbl_8055F004)[0] = ((s32 *)lbl_8055F004)[1];
    } else {
        ((s32 *)node)[1] = 0;
        ((s32 *)lbl_8055F004)[1] = (s32)node;
    }
    fn_8022EA58((void *)arg0);
}
#pragma dont_inline reset

void fn_8022EDB8(void) {
    fn_8022ED50(((s32 *)lbl_8055F004)[1]);
}

s32 fn_8022EDC4(void) {
    s32 *p = (s32 *)((s32 *)lbl_8055F004)[1];
    if (p) return *p;
    return 0;
}

#pragma push
#pragma processor 750
void *fn_8022EDE4(f32 *arg0, f32 farg0) {
    s32 *dst = (s32 *)((void *(*)(int, void *))fn_8022EAB8)(0x3c, (void *)&lbl_80340344);
    s32 *src = (s32 *)arg0;
    s32 t0, t1;
    f32 k;
    t0 = src[0];
    t1 = src[1];
    dst[0] = t0;
    t0 = src[2];
    dst[1] = t1;
    t1 = src[3];
    dst[2] = t0;
    t0 = src[4];
    dst[3] = t1;
    t1 = src[5];
    dst[4] = t0;
    t0 = src[6];
    dst[5] = t1;
    t1 = src[7];
    dst[6] = t0;
    t0 = src[8];
    dst[7] = t1;
    t1 = src[9];
    dst[8] = t0;
    t0 = src[10];
    dst[9] = t1;
    t1 = src[11];
    dst[10] = t0;
    k = lbl_805635E0;
    dst[11] = t1;
    ((f32 *)dst)[12] = farg0;
    ((f32 *)dst)[13] = k;
    ((f32 *)dst)[14] = k;
    return dst;
}
#pragma pop

void fn_8022EE98(void *arg0) {
    fn_8022EB30(arg0);
}

extern f32 lbl_805635E0;
extern f32 lbl_805635E4;
extern void *fn_8022EDE4(f32 *, f32);
void fn_8022EE9C(void) {
    f32 a[12];
    a[0] = 1.0f;
    a[1] = 0.0f;
    a[2] = 0.0f;
    a[3] = 0.0f;
    a[4] = 1.0f;
    a[5] = 0.0f;
    a[6] = 0.0f;
    a[7] = 0.0f;
    a[8] = 1.0f;
    a[9] = 0.0f;
    a[10] = 0.0f;
    a[11] = 0.0f;
    fn_8022EDE4(a, 1.0f);
}

extern f32 fn_80144514(f32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
void fn_8022EEF8(f32 *dst, f32 *left, f32 *right, s32 arg3) {
    f32 temp_f1;
    f32 temp_f24, temp_f25, temp_f26, temp_f27, temp_f28, temp_f29, temp_f30, temp_f31;

    dst[12] = left[12] * right[12];
    dst[13] = left[13] * right[13];
    dst[14] = left[14] * right[14];
    if (dst == left || dst == right) {
        temp_f24 = fn_80144514(right[0], left[0], right[3], left[1], right[6], left[2]);
        temp_f25 = fn_80144514(right[0], left[3], right[3], left[4], right[6], left[5]);
        temp_f26 = fn_80144514(right[0], left[6], right[3], left[7], right[6], left[8]);
        temp_f27 = fn_80144514(right[1], left[0], right[4], left[1], right[7], left[2]);
        temp_f28 = fn_80144514(right[1], left[3], right[4], left[4], right[7], left[5]);
        temp_f29 = fn_80144514(right[1], left[6], right[4], left[7], right[7], left[8]);
        temp_f30 = fn_80144514(right[2], left[0], right[5], left[1], right[8], left[2]);
        temp_f31 = fn_80144514(right[2], left[3], right[5], left[4], right[8], left[5]);
        temp_f1 = fn_80144514(right[2], left[6], right[5], left[7], right[8], left[8]);
        dst[0] = temp_f24; dst[3] = temp_f25; dst[6] = temp_f26;
        dst[1] = temp_f27; dst[4] = temp_f28; dst[7] = temp_f29;
        dst[2] = temp_f30; dst[5] = temp_f31; dst[8] = temp_f1;
    } else {
        dst[0] = fn_80144514(right[0], left[0], right[3], left[1], right[6], left[2]);
        dst[3] = fn_80144514(right[0], left[3], right[3], left[4], right[6], left[5]);
        dst[6] = fn_80144514(right[0], left[6], right[3], left[7], right[6], left[8]);
        dst[1] = fn_80144514(right[1], left[0], right[4], left[1], right[7], left[2]);
        dst[4] = fn_80144514(right[1], left[3], right[4], left[4], right[7], left[5]);
        dst[7] = fn_80144514(right[1], left[6], right[4], left[7], right[7], left[8]);
        dst[2] = fn_80144514(right[2], left[0], right[5], left[1], right[8], left[2]);
        dst[5] = fn_80144514(right[2], left[3], right[5], left[4], right[8], left[5]);
        dst[8] = fn_80144514(right[2], left[6], right[5], left[7], right[8], left[8]);
    }
    dst[9] = left[9] + right[9];
    dst[10] = left[10] + right[10];
    dst[11] = left[11] + right[11];
}
#pragma pop
