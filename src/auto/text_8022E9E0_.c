#include <types.h>

extern s32 lbl_8055EFF4;  /* cnodes handed out */
extern void **lbl_8055EFF8; /* the "cnode::pool" ObjectPool */
extern s32 lbl_8055EFFC;  /* UIContexts handed out */
extern void **lbl_8055F000; /* the "UIContext::pool" ObjectPool */
extern s32 lbl_8055F004;  /* head/tail record of the UI-context list */
extern s32 lbl_8055B980;  /* "cnode" heap tag */
extern char lbl_80340280[]; /* "cnode::pool" */
extern char lbl_80340290[]; /* "UIContext::pool" */
extern char lbl_803402A0[]; /* "UIContextBegin called twice! UIC" */
extern char lbl_803402F4[]; /* "UIContextTracker" */
extern char lbl_80340308[]; /* "UIcontext: Some contexts not pop..." */
extern char lbl_80340344[]; /* "UIContext" */
extern f32 lbl_805635E0;  /* 1.0f */
extern f32 lbl_805635E4;
extern void *fn_801284F8(u32, void *); /* named-heap allocation */
extern void *fn_8012A13C(void *, void *, u32, u32); /* build an ObjectPool */
extern void *fn_8012A2D8(void **);     /* pop an element from a pool */
extern void fn_8012A364(void **, void *); /* push an element back onto a pool */
extern void fn_8012A570(u32, void *);
extern void fn_8012A5E8(void *);
extern void Abend_Panic(const char *);
extern void fn_802E30C8(char *);
extern void fn_8022ED50(s32);
extern f32 dotProduct3(f32, f32, f32, f32, f32, f32); /* matrix multiply-accumulate */
extern void fn_80128668(void *);  /* free */
extern void *fn_8022EC7C(void);
extern void *fn_8022ECC0(s32);

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
#define sUIContextList      lbl_8055F004 /* UI-context stack record: {head, tail} node links */
#define STR_UICONTEXT       lbl_80340344 /* "UIContext": the heap tag its contexts are allocated under */

/* operator new(0x3c, "UIContext"): take one UIContext off "UIContext::pool"
 * (fn_8022EAB8, defined below without its two arguments). */
#define UIContext_New() ((void *(*)(int, void *))fn_8022EAB8)(0x3C, (void *)&STR_UICONTEXT)

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
void *fn_8022E9E0(int unused0, void *unused1) {
    /* Lazily allocate/initialize the "cnode::pool" (0x20 bytes, 8 entries) and
       bump its live-use count when pool acquisition succeeds. */
    void *pool;
    (void)unused0;
    (void)unused1;
    if (lbl_8055EFF4 == 0) {
        pool = fn_801284F8(0x20, lbl_80340280);
        if (pool != 0) {
            pool = fn_8012A13C(pool, lbl_80340280, 0x20, 8);
        }
        lbl_8055EFF8 = pool;
    }
    if (fn_8012A2D8(lbl_8055EFF8) != 0) {
        lbl_8055EFF4 += 1;
    }
}
#pragma scheduling reset
#pragma cplusplus on
extern "C" void fn_8022EA58(void *context) {
    /* Return a context to its object pool and destroy the pool when the live count reaches zero. */
    class PoolObject { public: virtual ~PoolObject(); };
    fn_8012A364(lbl_8055EFF8, context);
    if (--lbl_8055EFF4 == 0) {
        delete (PoolObject *)lbl_8055EFF8;
        lbl_8055EFF8 = 0;
    }
}
#pragma cplusplus reset
#pragma push
#pragma scheduling invalid_target
int fn_8022EAB8(int unused0, void *unused1) {
    /* Lazily create the "UIContext::pool" of 0x3c-byte UIContexts, then bump the
     * live-use count when a context is successfully taken from it. */
    void *uiPool;
    int initialized;
    (void)unused0;
    (void)unused1;
    if (sUIContextLiveCount == 0) {
        uiPool = fn_801284F8(0x20, STR_UICONTEXT_POOL);
        if (uiPool != 0) {
            uiPool = fn_8012A13C(uiPool, STR_UICONTEXT_POOL, 0x20, 0x3c);
        }
        sUIContextPool = uiPool;
    }
    initialized = (int)fn_8012A2D8(sUIContextPool);
    if (initialized != 0) {
        sUIContextLiveCount += 1;
    }
    return initialized;
}
#pragma pop

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
    /* Initialize the global list record: warn if one already exists, allocate an 8-byte {head, tail} block, and clear both links. */
    if (lbl_8055F004 != 0) ((void (*)(const char *, ...))Abend_Panic)(lbl_803402A0);
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
/* RealName: GetTailPredecessorNode_8022EC7C */
void *fn_8022EC7C(void) {
    /* Return the node whose next link is the list tail, or 0 if the list is empty. */
    u32 *list = (u32 *)lbl_8055F004;
    u32 *node = (u32 *)list[0];
    u32 tail;
    if (!node) return 0;
    tail = list[1];
    if ((u32)node == tail) return 0;
    while (node[1] != tail) node = (u32 *)node[1];
    return node;
}

void *fn_8022ECC0(s32 value) {
    /* Allocate a cnode for the UI context list, storing value with a null next link. */
    void *node = ((void *(*)(s32, void *))fn_8022E9E0)(8, &lbl_8055B980);
    ((s32 *)node)[0] = value;
    ((s32 *)node)[1] = 0;
    return node;
}

/* Append a newly allocated UI context node to the global UI context list. */
void fn_8022ED00(void) {
    s32 *node = (s32 *)((void *(*)(void))fn_8022ECC0)();
    if (((s32 *)lbl_8055F004)[1] == 0) {
        ((s32 *)lbl_8055F004)[0] = (s32)node;
        ((s32 *)lbl_8055F004)[1] = ((s32 *)lbl_8055F004)[0];
    } else {
        ((s32 *)((s32 *)lbl_8055F004)[1])[1] = (s32)node;
        ((s32 *)lbl_8055F004)[1] = (s32)node;
    }
}

#pragma dont_inline on
void fn_8022ED50(s32 arg0) {
    /* Detach the tail node's predecessor from the list in lbl_8055F004, then release arg0. */
    void *prevNode;

    prevNode = fn_8022EC7C();
    if (prevNode == 0) {
        ((s32 *)lbl_8055F004)[1] = 0;
        ((s32 *)lbl_8055F004)[0] = ((s32 *)lbl_8055F004)[1];
    } else {
        ((s32 *)prevNode)[1] = 0;
        ((s32 *)lbl_8055F004)[1] = (s32)prevNode;
    }
    fn_8022EA58((void *)arg0);
}
#pragma dont_inline reset

/* Pop the top UI context off the stack: release the tail node of the
   global UI-context list. */
void fn_8022EDB8(void) {
    fn_8022ED50(((s32 *)sUIContextList)[1]);
}

s32 fn_8022EDC4(void) {
    /* Return the value held by the tail node of the UI-context stack (the current UIContext), or 0 when the stack is empty. */
    s32 *tailNode = (s32 *)((s32 *)sUIContextList)[1];
    if (tailNode) return *tailNode;
    return 0;
}

#pragma push
#pragma processor 750
#pragma scheduling on
void *fn_8022EDE4(f32 *proto, f32 brightness) {
    /* Take a fresh UIContext off the "UIContext::pool" pool and start it as a copy
     * of the draw transform `proto` -- its 3x3 matrix and the three offsets, the
     * first 0x30 bytes of a UIContext, word by word through two temporaries --
     * with the given brightness and scale and rate both 1.0.  Callers push the
     * result (fn_8022ED00) to draw a widget in this new context. */
    s32 t0 = 0;
    s32 *dst = (s32 *)UIContext_New();
    s32 *src = (s32 *)proto;
    s32 t1;
    f32 one;
    t1 = src[0];
    t0 = src[1];
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
    one = lbl_805635E0; /* 1.0f */
    dst[11] = t0;
    ((UIContext *)dst)->brightness = brightness;
    ((UIContext *)dst)->scale = one;
    ((UIContext *)dst)->rate = one;
    return dst;
}
#pragma pop

/* Tail-call wrapper: release the given UIContext back to the shared pool via fn_8022EB30. */
void fn_8022EE98(void *context) {
    fn_8022EB30(context);
}

void fn_8022EE9C(void) {
    /* Build an identity 3x3 rotation/translation matrix and install it as the current UI context. */
    f32 identityMatrix[12];
    identityMatrix[0] = 1.0f;
    identityMatrix[1] = 0.0f;
    identityMatrix[2] = 0.0f;
    identityMatrix[3] = 0.0f;
    identityMatrix[4] = 1.0f;
    identityMatrix[5] = 0.0f;
    identityMatrix[6] = 0.0f;
    identityMatrix[7] = 0.0f;
    identityMatrix[8] = 1.0f;
    identityMatrix[9] = 0.0f;
    identityMatrix[10] = 0.0f;
    identityMatrix[11] = 0.0f;
    fn_8022EDE4(identityMatrix, 1.0f);
}

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
        m00 = dotProduct3(right->mtx[0][0], left->mtx[0][0], right->mtx[1][0], left->mtx[0][1], right->mtx[2][0], left->mtx[0][2]);
        m10 = dotProduct3(right->mtx[0][0], left->mtx[1][0], right->mtx[1][0], left->mtx[1][1], right->mtx[2][0], left->mtx[1][2]);
        m20 = dotProduct3(right->mtx[0][0], left->mtx[2][0], right->mtx[1][0], left->mtx[2][1], right->mtx[2][0], left->mtx[2][2]);
        m01 = dotProduct3(right->mtx[0][1], left->mtx[0][0], right->mtx[1][1], left->mtx[0][1], right->mtx[2][1], left->mtx[0][2]);
        m11 = dotProduct3(right->mtx[0][1], left->mtx[1][0], right->mtx[1][1], left->mtx[1][1], right->mtx[2][1], left->mtx[1][2]);
        m21 = dotProduct3(right->mtx[0][1], left->mtx[2][0], right->mtx[1][1], left->mtx[2][1], right->mtx[2][1], left->mtx[2][2]);
        m02 = dotProduct3(right->mtx[0][2], left->mtx[0][0], right->mtx[1][2], left->mtx[0][1], right->mtx[2][2], left->mtx[0][2]);
        m12 = dotProduct3(right->mtx[0][2], left->mtx[1][0], right->mtx[1][2], left->mtx[1][1], right->mtx[2][2], left->mtx[1][2]);
        m22 = dotProduct3(right->mtx[0][2], left->mtx[2][0], right->mtx[1][2], left->mtx[2][1], right->mtx[2][2], left->mtx[2][2]);
        dst->mtx[0][0] = m00; dst->mtx[1][0] = m10; dst->mtx[2][0] = m20;
        dst->mtx[0][1] = m01; dst->mtx[1][1] = m11; dst->mtx[2][1] = m21;
        dst->mtx[0][2] = m02; dst->mtx[1][2] = m12; dst->mtx[2][2] = m22;
    } else {
        dst->mtx[0][0] = dotProduct3(right->mtx[0][0], left->mtx[0][0], right->mtx[1][0], left->mtx[0][1], right->mtx[2][0], left->mtx[0][2]);
        dst->mtx[1][0] = dotProduct3(right->mtx[0][0], left->mtx[1][0], right->mtx[1][0], left->mtx[1][1], right->mtx[2][0], left->mtx[1][2]);
        dst->mtx[2][0] = dotProduct3(right->mtx[0][0], left->mtx[2][0], right->mtx[1][0], left->mtx[2][1], right->mtx[2][0], left->mtx[2][2]);
        dst->mtx[0][1] = dotProduct3(right->mtx[0][1], left->mtx[0][0], right->mtx[1][1], left->mtx[0][1], right->mtx[2][1], left->mtx[0][2]);
        dst->mtx[1][1] = dotProduct3(right->mtx[0][1], left->mtx[1][0], right->mtx[1][1], left->mtx[1][1], right->mtx[2][1], left->mtx[1][2]);
        dst->mtx[2][1] = dotProduct3(right->mtx[0][1], left->mtx[2][0], right->mtx[1][1], left->mtx[2][1], right->mtx[2][1], left->mtx[2][2]);
        dst->mtx[0][2] = dotProduct3(right->mtx[0][2], left->mtx[0][0], right->mtx[1][2], left->mtx[0][1], right->mtx[2][2], left->mtx[0][2]);
        dst->mtx[1][2] = dotProduct3(right->mtx[0][2], left->mtx[1][0], right->mtx[1][2], left->mtx[1][1], right->mtx[2][2], left->mtx[1][2]);
        dst->mtx[2][2] = dotProduct3(right->mtx[0][2], left->mtx[2][0], right->mtx[1][2], left->mtx[2][1], right->mtx[2][2], left->mtx[2][2]);
    }
    dst->pos[0] = left->pos[0] + right->pos[0];
    dst->pos[1] = left->pos[1] + right->pos[1];
    dst->pos[2] = left->pos[2] + right->pos[2];
}
#pragma pop
