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

/* One entry of the UI draw-context stack (pushed by fn_8022ED00, popped by
 * fn_8022EDB8, current one from fn_8022EDC4); the game names the 0x3c-byte
 * object "UIContext" (lbl_80340344) and allocates it from "UIContext::pool".
 * The matrix is 3x3 row-major; composing two contexts (fn_8022EEF8) multiplies
 * them (left * right), adds the offsets and multiplies the three factors. */
typedef struct UIContext {
    f32 mtx[3][3];    /* 0x00 rotation/scale */
    f32 pos[3];       /* 0x24 x, y, z offset added to what is drawn */
    f32 brightness;   /* 0x30 scales the colour's top byte (fn_80230B9C) */
    f32 scale;        /* 0x34 scales the drawn size */
    f32 rate;         /* 0x38 line/text width rate */
} UIContext;          /* 0x3c bytes */

#define STR_CNODE_POOL      lbl_80340280 /* "cnode::pool" */
#define STR_UICONTEXT_POOL  lbl_80340290 /* "UIContext::pool" */
#define sCNodePool          lbl_8055EFF8 /* ObjectPool of 8-byte cnodes */
#define sCNodeLiveCount     lbl_8055EFF4 /* cnodes handed out */
#define sUIContextPool      lbl_8055F000 /* ObjectPool of 0x3c-byte UIContexts */
#define sUIContextLiveCount lbl_8055EFFC /* UIContexts handed out */

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void *fn_8022E9E0(int arg0, void *arg1) {
    void *value;
    (void)arg0;
    (void)arg1;
    if (lbl_8055EFF4 == 0) {
        value = fn_801284F8(0x20, lbl_80340280);
        if (value != 0) {
            value = fn_8012A13C(value, lbl_80340280, 0x20, 8);
        }
        lbl_8055EFF8 = value;
    }
    if (fn_8012A2D8(lbl_8055EFF8) != 0) {
        lbl_8055EFF4 += 1;
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
int fn_8022EAB8(void) {
    void *value;
    int ret;
    if (lbl_8055EFFC == 0) {
        value = fn_801284F8(0x20, lbl_80340290);
        if (value != 0) {
            value = fn_8012A13C(value, lbl_80340290, 0x20, 0x3c);
        }
        lbl_8055F000 = value;
    }
    ret = (int)fn_8012A2D8(lbl_8055F000);
    if (ret != 0) {
        lbl_8055EFFC += 1;
    }
    return ret;
}

#pragma dont_inline on
#pragma cplusplus on
// Releases one UIContext: pushes it back onto the "UIContext::pool" free list
// (fn_8012A364) and, once the last context handed out is back, deletes the pool
// itself through its virtual destructor and forgets it.
extern "C" void fn_8022EB30(void *context) {
    class PoolObject { public: virtual ~PoolObject(); };
    fn_8012A364(sUIContextPool, context);
    if (--sUIContextLiveCount == 0) {
        delete (PoolObject *)sUIContextPool;
        sUIContextPool = 0;
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
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8022EBF0(void) {
    /* Shut down the node list: if any nodes remain, log, drain and free them, then free the list object. */
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
void *fn_8022EDE4(float *arg0, float farg0) {
    int *dst = (int *)((void *(*)(int, void *))fn_8022EAB8)(0x3C, (void *)&lbl_80340344);
    int *src = (int *)arg0;
    int t0, t1;
    float k;
    t0 = src[1];
    t1 = src[0];
    dst[0] = t1;
    t1 = src[2];
    dst[1] = t0;
    t0 = src[3];
    dst[2] = t1;
    t1 = src[4];
    dst[3] = t0;
    t0 = src[5];
    dst[4] = t1;
    t1 = src[6];
    dst[5] = t0;
    t0 = src[7];
    dst[6] = t1;
    t1 = src[8];
    dst[7] = t0;
    t0 = src[9];
    dst[8] = t1;
    t1 = src[10];
    dst[9] = t0;
    t0 = src[11];
    dst[10] = t1;
    k = lbl_805635E0;
    dst[11] = t0;
    ((float *)dst)[12] = farg0;
    ((float *)dst)[13] = k;
    ((float *)dst)[14] = k;
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
/* Combines two UI draw-contexts into `dst`: the 3x3 matrices multiply
 * (dst->mtx = left->mtx * right->mtx), the draw offsets add and the three
 * factors (brightness, scale, rate) multiply.  Callers build a widget's own
 * context, combine it with the current one (fn_8022EDC4) and push the result
 * (fn_8022ED00) for the widget to draw in.  When `dst` is one of the inputs
 * every product goes through a temporary first, so nothing is overwritten
 * before the last row that reads it. */
void fn_8022EEF8(UIContext *dst, const UIContext *left, const UIContext *right) {
    f32 m00, m10, m20, m01, m11, m21, m02, m12, m22;

    dst->brightness = left->brightness * right->brightness;
    dst->scale = left->scale * right->scale;
    dst->rate = left->rate * right->rate;
    if (dst == left || dst == right) {
        m00 = fn_80144514(right->mtx[0][0], left->mtx[0][0], right->mtx[1][0], left->mtx[0][1], right->mtx[2][0], left->mtx[0][2]);
        m10 = fn_80144514(right->mtx[0][0], left->mtx[1][0], right->mtx[1][0], left->mtx[1][1], right->mtx[2][0], left->mtx[1][2]);
        m20 = fn_80144514(right->mtx[0][0], left->mtx[2][0], right->mtx[1][0], left->mtx[2][1], right->mtx[2][0], left->mtx[2][2]);
        m01 = fn_80144514(right->mtx[0][1], left->mtx[0][0], right->mtx[1][1], left->mtx[0][1], right->mtx[2][1], left->mtx[0][2]);
        m11 = fn_80144514(right->mtx[0][1], left->mtx[1][0], right->mtx[1][1], left->mtx[1][1], right->mtx[2][1], left->mtx[1][2]);
        m21 = fn_80144514(right->mtx[0][1], left->mtx[2][0], right->mtx[1][1], left->mtx[2][1], right->mtx[2][1], left->mtx[2][2]);
        m02 = fn_80144514(right->mtx[0][2], left->mtx[0][0], right->mtx[1][2], left->mtx[0][1], right->mtx[2][2], left->mtx[0][2]);
        m12 = fn_80144514(right->mtx[0][2], left->mtx[1][0], right->mtx[1][2], left->mtx[1][1], right->mtx[2][2], left->mtx[1][2]);
        m22 = fn_80144514(right->mtx[0][2], left->mtx[2][0], right->mtx[1][2], left->mtx[2][1], right->mtx[2][2], left->mtx[2][2]);
        dst->mtx[0][0] = m00; dst->mtx[1][0] = m10; dst->mtx[2][0] = m20;
        dst->mtx[0][1] = m01; dst->mtx[1][1] = m11; dst->mtx[2][1] = m21;
        dst->mtx[0][2] = m02; dst->mtx[1][2] = m12; dst->mtx[2][2] = m22;
    } else {
        dst->mtx[0][0] = fn_80144514(right->mtx[0][0], left->mtx[0][0], right->mtx[1][0], left->mtx[0][1], right->mtx[2][0], left->mtx[0][2]);
        dst->mtx[1][0] = fn_80144514(right->mtx[0][0], left->mtx[1][0], right->mtx[1][0], left->mtx[1][1], right->mtx[2][0], left->mtx[1][2]);
        dst->mtx[2][0] = fn_80144514(right->mtx[0][0], left->mtx[2][0], right->mtx[1][0], left->mtx[2][1], right->mtx[2][0], left->mtx[2][2]);
        dst->mtx[0][1] = fn_80144514(right->mtx[0][1], left->mtx[0][0], right->mtx[1][1], left->mtx[0][1], right->mtx[2][1], left->mtx[0][2]);
        dst->mtx[1][1] = fn_80144514(right->mtx[0][1], left->mtx[1][0], right->mtx[1][1], left->mtx[1][1], right->mtx[2][1], left->mtx[1][2]);
        dst->mtx[2][1] = fn_80144514(right->mtx[0][1], left->mtx[2][0], right->mtx[1][1], left->mtx[2][1], right->mtx[2][1], left->mtx[2][2]);
        dst->mtx[0][2] = fn_80144514(right->mtx[0][2], left->mtx[0][0], right->mtx[1][2], left->mtx[0][1], right->mtx[2][2], left->mtx[0][2]);
        dst->mtx[1][2] = fn_80144514(right->mtx[0][2], left->mtx[1][0], right->mtx[1][2], left->mtx[1][1], right->mtx[2][2], left->mtx[1][2]);
        dst->mtx[2][2] = fn_80144514(right->mtx[0][2], left->mtx[2][0], right->mtx[1][2], left->mtx[2][1], right->mtx[2][2], left->mtx[2][2]);
    }
    dst->pos[0] = left->pos[0] + right->pos[0];
    dst->pos[1] = left->pos[1] + right->pos[1];
    dst->pos[2] = left->pos[2] + right->pos[2];
}
#pragma pop
