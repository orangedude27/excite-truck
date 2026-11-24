// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562708;
extern float lbl_80562704;
extern float lbl_80562738;
void fn_801B7760(int, int, float, float);
#pragma dont_inline fn_801B78EC
void fn_801B78EC(int, int, int, float, float, float);
double fn_8002F234(float);
void fn_801B7C8C(int, float *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_801769A8(void);
extern int fn_801769B8(void);
extern int fn_801796B4(void);
/* Determine a control/result state for a physics command request.
 * Returns 1 by default, 2 when the command flags bit 0x100 is clear, and can
 * return 0, 3, or 4 depending on the active command mode, command flags, and
 * the cached per-frame mode flag. Requests 0x50/0x51 are forced to 0 while
 * that cached flag is set. */
int fn_801B7688(int requestId) {
    int result;
    int activeMode;
    int isIdleMode;
    int commandFlags;

    commandFlags = *((int *)__AXFXGetLfoSinTable_801769CC() + 1);
    result = 1;
    if (commandFlags & 0x100) {
        activeMode = fn_801769B8();
        isIdleMode = (activeMode == 0);
        switch (requestId) {
        case 0x51:
            if (isIdleMode != 0 || activeMode == 1) result = 0;
            break;
        case 0x50:
        case 0x52:
            if (isIdleMode != 0) result = 0;
            if (activeMode == 1) result = 3;
            if (fn_801769A8() & 0x400) result = 4;
            break;
        case 0x53:
            break;
        }
    } else {
        result = 2;
    }

    if (fn_801796B4() != 0 && (unsigned)(requestId - 0x50) <= 1) result = 0;
    return result;
}

double cos(double);
double sin(double);
 #pragma scheduling invalid_target
 #pragma push
  #pragma processor 750
void fn_801B7760(int arg0, int arg1, float farg0, float farg1) {
    struct Vector {
        float x, y, z, w;
        int pad;
        struct Vector * volatile next;
    };
    struct Args {
        struct Vector *value;
        float t;
    };
    const struct Args *a = (const struct Args *)arg1;
    struct Vector *p = a->value;
    float t = a->t;
    float angle = farg1;
    float offset = farg0;
    volatile double temp;
    float value[4];

    value[2] = p->x + t * (p->next->x - p->x);
    value[3] = p->y + t * (p->next->y - p->y);
    value[0] = p->z + t * (p->next->z - p->z);
    value[1] = p->w + t * (p->next->w - p->w);
    {
        float length = fn_8002F234(value[0] * value[0] + value[1] * value[1]);
        float scale = lbl_80562704 / length;
        float z;

        value[0] *= scale;
        value[1] *= scale;
        temp = *(double *)&value[0];
        z = value[0];
        {
            float normW = ((float *)&temp)[1];
            float normZ = ((float *)&temp)[0];
            float negZ = (float)-((double)normZ);

            value[2] += normW * offset;
            value[3] += negZ * offset;
            ((float *)&temp)[0] = normW;
            ((float *)&temp)[1] = negZ;
        }
        offset = (float)cos(angle);
        {
            float sine = (float)sin(angle);
            float w = value[1];
            float zz = value[0];
            value[1] = z * sine + w * offset;
            value[0] = zz * offset - w * sine;
        }
    }
    fn_801B7C8C(arg0, &value[2], value);
    *(int *)((char *)arg0 + 0x3C) = 0;
}
#pragma pop
#pragma scheduling on
extern void fn_80135B24(void *, float);
extern void fn_80136468(void *, float);
#pragma push
#pragma processor 750
void fn_801B78EC(int arg0, int arg1, int arg2, float farg0, float farg1, float farg2) {
    /* Compute an interpolated track/sample triple from arg1 via one of two helpers, then apply it with arg0/farg0/farg2. */
    struct Triple {
        int first;
        float second;
        int third;
    };
    struct Triple slots[3];
    (void)arg1;
    slots[2].first = 0;
    slots[2].third = 0x2710;
    slots[2].second = 0.0f;
    if (arg2 != 0) {
        ((void (*)(void *, void *, float))fn_80135B24)(&slots[1], (void *)arg1, farg1);
        slots[2].first = slots[1].first;
        slots[2].second = slots[1].second;
        slots[2].third = slots[1].third;
    } else {
        ((void (*)(void *, void *, float))fn_80136468)(&slots[0], (void *)arg1, farg1);
        slots[2].first = slots[0].first;
        slots[2].second = slots[0].second;
        slots[2].third = slots[0].third;
    }
    fn_801B7760(arg0, (int)&slots[2], farg0, farg2);
}
#pragma pop

float fn_801B79AC(void) {
#define getCurrentLeague fn_80137C54
    /* Return the carLength field (+0x04) of the currently selected AI driver
     * league; passing -1 to getCurrentLeague selects the active league. */
    return *(float *)((char *)getCurrentLeague(-1) + 4);
#undef getCurrentLeague
}

#pragma dont_inline fn_801B79AC
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma cplusplus on
extern "C" float lbl_80562700, lbl_80562708, lbl_8056270C, lbl_80562710, lbl_80562714;
extern "C" double lbl_80562718;
extern "C" void *fn_801B2ED0(unsigned int);
extern "C" unsigned int fn_801B3050(unsigned int);
extern "C" float fn_80139048(void);
extern "C" void *fn_80156A40(float);
extern "C" float fn_801B79AC(void);
extern "C" float fn_80134C1C(void);
extern "C" void fn_801B78EC(int, int, int, float, float, float);
extern "C" void *__AXFXGetLfoSinTable_801769CC(void);
/* Set up an audio placement for start modes 1/2: derive the interpolation from
   the slot and active league, apply it through fn_801B78EC, then set the
   placement's three output coefficients. */
extern "C" void fn_801B79D4(void *placement, unsigned int slot, int startType) {
    struct V1 {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual int v5();
    };
    struct V2 {
        virtual void w0(); virtual void *w1(int); virtual void w2();
        virtual void *w3();
    };
    struct Node {
        char pad[0x10];
        unsigned int key;
        Node *next;
        char pad2[4];
        float value;
    };
    unsigned int slotIndex = slot;
    unsigned voiceSource = ((V1 *)fn_801B2ED0(slotIndex))->v5();
    float interp = fn_80139048();
    float carLength = fn_801B79AC();
    interp = lbl_8056270C + (carLength + interp);
    if (startType != 0x53 && startType != 0x54) slotIndex = fn_801B3050((unsigned)slotIndex);
    float side = (slotIndex & 1) ? lbl_80562700 : -lbl_80562700;
    float negLength = -fn_801B79AC();
    float phase = negLength * lbl_80562710;
    float baseOffset = lbl_80562714;
    unsigned long signBit = slotIndex >> 31;
    register int half = (int)(signBit + slotIndex) >> 1;
    interp = phase - (float)half * interp;
    V2 *listHolder = (V2 *)((V2 *)fn_80156A40(phase))->w1(0);
    Node *head = *(Node **)((char *)listHolder + 0x1C);
    Node *node = head;
    Node *best = head;
    do {
        if (node->key > best->key) best = node;
        node = node->next;
    } while (node != head);
    float delta = best->value - baseOffset;
    interp = ((int *)((char *)__AXFXGetLfoSinTable_801769CC() + 0x10))[0] & 1 ? interp : delta + interp;
    fn_801B78EC((int)placement, voiceSource, 0, side, interp, lbl_80562708);
    if (*(int *)((char *)placement + 0x44) == 1) {
        float scale = fn_80134C1C();
        *(float *)((char *)placement + 0x30) = *(float *)((char *)placement + 0x18) * scale;
        *(float *)((char *)placement + 0x34) = *(float *)((char *)placement + 0x1C) * scale;
        *(float *)((char *)placement + 0x38) = *(float *)((char *)placement + 0x20) * scale;
    } else {
        float fixedValue = lbl_80562708;
        *(float *)((char *)placement + (int)0x30) = fixedValue;
        *(float *)((char *)placement + 0x34) = fixedValue;
        *(float *)((char *)placement + 0x38) = fixedValue;
    }
}
#pragma cplusplus reset
#pragma pop
#pragma cplusplus reset

void PSVECCrossProduct(float *, float *, float *);
void PSVECNormalize(float *, float *);
#pragma processor gekko
void fn_801B7BA8(float *arg0, float *arg1, float *arg2) {
    float a[3];
    float b[3];
    float c[3];
    float v, w, u, z, y, x;

    x = arg1[0];
    y = arg1[1];
    z = arg1[2];
    u = arg2[0];
    v = arg2[1];
    w = lbl_80562708;
    a[0] = x;
    a[1] = y;
    a[2] = z;
    b[0] = u;
    b[1] = w;
    b[2] = v;
    PSVECCrossProduct(a, b, c);
    PSVECCrossProduct(c, a, b);
    PSVECNormalize(c, c);
    PSVECNormalize(a, a);
    PSVECNormalize(b, b);
    arg0[0] = c[0]; arg0[1] = c[1]; arg0[2] = c[2];
    arg0[3] = a[0]; arg0[4] = a[1]; arg0[5] = a[2];
    arg0[6] = b[0]; arg0[7] = b[1]; arg0[8] = b[2];
}
void fn_801E9DC4(void *, float *, float *);
int fn_801E9E30(void *, float *);
void fn_801E9E78(void *, float *, float *, int *);
void fn_801B7BA8(float *, float *, float *);
extern float lbl_80562710, lbl_80562724, lbl_80562728, lbl_8056272C;
void fn_801B7C8C(int arg0, float *arg1, float *arg2) {
#pragma opt_common_subs off
    struct XF { float m[9]; float p[3]; } xf;
    struct V2 { float x, y; };
    float pts[9];
    float normal[3];
    float delta1[3];
    float delta2[3];
    struct V2 d;
    int sp8;
    register int i;
    float a, b, z;

    d = *(struct V2 *)arg2;
    a = arg1[0];
    b = arg1[1];
    z = -d.x;
    normal[0] = 0.0f;
    normal[1] = 1.0f;
    normal[2] = 0.0f;
    pts[0] = a + arg2[0] * lbl_80562724;
    pts[1] = 0.0f;
    pts[2] = b + arg2[1] * lbl_80562724;
    pts[3] = a + arg2[0] * lbl_80562710 + d.y * lbl_80562710;
    pts[4] = 0.0f;
    pts[5] = b + arg2[1] * lbl_80562710 + z * lbl_80562710;
    pts[6] = pts[3] + d.y * lbl_80562728;
    pts[7] = 0.0f;
    pts[8] = pts[5] + z * lbl_80562728;
    xf.p[0] = a;
    xf.p[1] = 0.0f;
    xf.p[2] = b;
    d.x = d.y;
    d.y = z;
    ((void (*)(void *))fn_801E9DC4)((char *)arg0 + 0x40);
    for (i = 0; i < 3; i++) {
        if (fn_801E9E30((char *)arg0 + 0x40, &pts[i * 3]) == 0) break;
    }
    if (i == 3) {
        fn_801E9E78((char *)arg0 + 0x40, xf.p, normal, &sp8);
        delta1[0] = pts[3] - pts[0];
        delta1[1] = pts[4] - pts[1];
        delta1[2] = pts[5] - pts[2];
        delta2[0] = pts[6] - pts[0];
        delta2[1] = pts[7] - pts[1];
        delta2[2] = pts[8] - pts[2];
        PSVECCrossProduct(delta2, delta1, normal);
        PSVECNormalize(normal, normal);
    } else {
        ((void (*)(void *))fn_801E9DC4)((char *)arg0 + 0x40);
        fn_801E9E78((char *)arg0 + 0x40, xf.p, normal, &sp8);
    }
    fn_801B7BA8(xf.m, normal, arg2);
    xf.p[0] += xf.m[3] * lbl_8056272C;
    xf.p[1] += xf.m[4] * lbl_8056272C;
    xf.p[2] += xf.m[5] * lbl_8056272C;
    *(struct XF *)arg0 = xf;
    ((int *)arg0)[0xF] = 0;
    ((float *)arg0)[0xC] = 0.0f;
    ((float *)arg0)[0xD] = 0.0f;
    ((float *)arg0)[0xE] = 0.0f;
}

extern void *fn_80178C9C(void);
extern void fn_801B78EC(int, int, int, float, float, float);
extern void fn_801B8054(int, int, float, float);
extern float lbl_80562720;
extern const float lbl_80562730;
extern float lbl_80562734;
#pragma push
#pragma processor 750
void fn_801B7F4C(void *arg0, int deltaY, int arg2) {
    void *rootObj;
    void *container;
    void *subObject;
    float yStep;
    float baseOffset;

    /* Position arg0 relative to the current root: offset from a subobject if present, else use a scaled delta. */
    (void)arg2;
    yStep = lbl_80562730;
    if (*(void **)((char *)*(void **)((char *)fn_80178C9C() + 0x2C) + 0x20) != 0) {
        container = *(void **)((char *)fn_80178C9C() + 0x2C);
        subObject = *(void **)((char *)container + 0x20);
        baseOffset = lbl_80562734 + *(float *)((char *)subObject + 0x1C);
        rootObj = fn_80178C9C();
        fn_801B8054((int)arg0, (int)rootObj, lbl_80562708, (lbl_80562720 + baseOffset) + (float)deltaY * yStep);
    } else {
        rootObj = fn_80178C9C();
        fn_801B78EC((int)arg0, (int)rootObj, 0, lbl_80562708, (float)deltaY * yStep, lbl_80562708);
    }
}
#pragma pop
void fn_801B8040(int obj, int source, float offset) {
    /* Position `obj` from `source` (a value/t descriptor) via the core
     * interpolation/normalization path, with no final rotation (angle 0.0f). */
    fn_801B7760(obj, source, offset, lbl_80562708);
}

#pragma dont_inline fn_801B78EC
void fn_801B8048(int obj, int source, float offset, float interp) {
    /* Position `obj` from `source` via the first (mode-0) interpolation path; the final angle is 0.0f. */
    fn_801B78EC(obj, source, 0, offset, interp, lbl_80562708);
}

#pragma dont_inline fn_801B78EC
void fn_801B8054(int obj, int source, float offset, float interp) {
    /* Position `obj` from `source` via the second (mode-1) interpolation path; the final angle is 0.0f. */
    fn_801B78EC(obj, source, 1, offset, interp, lbl_80562708);
}

#pragma scheduling on
/* Set up a transform on target from an entity record's horizontal position and normalized facing direction. */ /* Set up a transform on target from an entity record's horizontal position and normalized facing direction. */ void fn_801B8060(int target, const void *record) {
    float position[2];
    float direction[2];
    float dirX;
    float dirZ;
    float dirLenSq;
    float posX;
    float posZ;
    float dirLen;
    float invDirLen;

    dirX = *(float *)((char *)record + 0x18);
    dirZ = *(float *)((char *)record + 0x20);
    dirLenSq = dirX * dirX + dirZ * dirZ;
    posX = *(float *)((char *)record + 0x24);
    posZ = *(float *)((char *)record + 0x2C);
    position[0] = posX;
    position[1] = posZ;
    direction[0] = dirX;
    direction[1] = dirZ;
    dirLen = (float)((double (*)(float, float, float, float, float))fn_8002F234)(
        dirLenSq, dirZ, dirX, posZ, posX);
    invDirLen = (lbl_80562738 > dirLen) ? lbl_80562738 : dirLen;
    invDirLen = lbl_80562704 / invDirLen;
    direction[0] *= invDirLen;
    direction[1] *= invDirLen;
    fn_801B7C8C(target, position, direction);
}
extern char lbl_80336718[];
extern int fn_802E317C(char *, ...);
#pragma dont_inline on
void fn_801B8100(void *placement, int slot, int startType) {
    #define sUnknownStartModeFmt lbl_80336718
    #define sPanic fn_802E317C
    /* Clears a car-placement result, lets the UI try to fill it first, otherwise
     * derives a start mode from startType, records it at +0x44 and dispatches to
     * the matching placement routine (panicking on an unrecognised mode). */
    int mode;
    memset(placement, 0, 80);
    if (fn_801796B4() == 0) {
        if (fn_801B8630(placement, slot, startType) != 0)
            return;
    }
    mode = fn_801B7688(startType);
    *(int *)((char *)placement + 0x44) = mode;
    switch (mode) {
        case 3:
        case 4:
        case 0:
            fn_801B7F4C(placement, slot, startType);
            return;
        case 1:
        case 2:
            fn_801B79D4(placement, slot, startType);
            return;
        default:
            sPanic(sUnknownStartModeFmt, mode);
    }
    #undef sPanic
    #undef sUnknownStartModeFmt
}
#pragma dont_inline reset
