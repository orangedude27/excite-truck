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
int fn_801B7688(int arg0) {
    int result;
    int state;
    int zero;
    int flags;

    flags = *((int *)__AXFXGetLfoSinTable_801769CC() + 1);
    result = 1;
    if (flags & 0x100) {
        state = fn_801769B8();
        zero = (state == 0);
        if (arg0 == 0x52) goto shared;
        if (arg0 >= 0x52) goto done;
        if (arg0 == 0x50) goto shared;
        if (arg0 >= 0x50) goto middle;
        if (arg0 < 0x50) goto done;
        goto done;

middle:
        if (zero == 0) {
            if (state == 1) result = 0;
        }
        goto done;

shared:
        if (zero != 0) result = 0;
        if (state == 1) result = 3;
        if (fn_801769A8() & 0x400) result = 4;
    } else {
        result = 2;
    }

done:
    if (fn_801796B4() != 0 && (unsigned)(arg0 - 0x50) <= 1) result = 0;
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
    struct Vector *p = ((struct Args *)arg1)->value;
    float t = ((struct Args *)arg1)->t;
    float angle = farg1;
    float offset = farg0;
    double temp;
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
            float normW, normZ, negZ;
            normZ = ((float *)&temp)[0];
            normW = ((float *)&temp)[1];
            negZ = -normZ;
            ((float *)&temp)[0] = normW;
            ((float *)&temp)[1] = negZ;
            value[2] += ((float *)&temp)[0] * offset;
            value[3] += ((float *)&temp)[1] * offset;
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
extern "C" void fn_801B79D4(void *arg0, unsigned int arg1, int arg2) {
    struct V1 {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(); virtual int v5x();
    };
    struct V2 {
        virtual void w0(); virtual void *w1(int); virtual void w2();
        virtual void *w3();
    };
    struct Node {
        unsigned int key;
        Node *next;
        float value;
    };
    unsigned int var28 = arg1;
    int r30 = ((V1 *)fn_801B2ED0(var28))->v5x();
    float f31 = fn_80139048();
    float sum = lbl_8056270C + (fn_801B79AC() + f31);
    if (arg2 != 0x53 && arg2 != 0x54) var28 = fn_801B3050(var28);
    float f30 = (var28 & 1) ? lbl_80562700 : -lbl_80562700;
    float f1 = -fn_801B79AC() * lbl_80562710;
    float f29 = lbl_80562714;
    float v31 = f1 - (float)((int)((var28 >> 31) + var28) >> 1) * sum;
    V2 *holder = (V2 *)((V2 *)fn_80156A40(f1))->w1(0);
    Node *head = (Node *)(((char *)holder) + 0x1C);
    Node *cur = head;
    Node *best = head;
    do {
        if (cur->key > best->key) best = cur;
        cur = cur->next;
    } while (cur != head);
    f29 = best->value - f29;
    if (((int *)((char *)__AXFXGetLfoSinTable_801769CC() + 0x10))[0] & 1) { } else v31 += f29;
    fn_801B78EC((int)arg0, r30, 0, f30, v31, lbl_80562708);
    if (*(int *)((char *)arg0 + 0x44) == 1) {
        float scale = fn_80134C1C();
        *(float *)((char *)arg0 + 0x30) = *(float *)((char *)arg0 + 0x18) * scale;
        *(float *)((char *)arg0 + 0x34) = *(float *)((char *)arg0 + 0x1C) * scale;
        *(float *)((char *)arg0 + 0x38) = *(float *)((char *)arg0 + 0x20) * scale;
    } else {
        *(float *)((char *)arg0 + 0x30) = lbl_80562708;
        *(float *)((char *)arg0 + 0x34) = lbl_80562708;
        *(float *)((char *)arg0 + 0x38) = lbl_80562708;
    }
}
#pragma cplusplus reset
#pragma pop
#pragma cplusplus reset

void PSVECCrossProduct(float *, float *, float *);
void PSVECNormalize(float *, float *);
#pragma opt_propagation off
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
#pragma opt_propagation reset
void fn_801E9DC4(void *, float *, float *);
int fn_801E9E30(void *, float *);
void fn_801E9E78(void *, float *, float *, int *);
void fn_801B7BA8(float *, float *, float *);
extern float lbl_80562710, lbl_80562724, lbl_80562728, lbl_8056272C;
void fn_801B7C8C(int arg0, float *arg1, float *arg2) {
    struct XF { float m[9]; float p[3]; } xf;
    struct V2 { float x, y; };
    float pts[9];
    float normal[3];
    float delta1[3];
    float delta2[3];
    struct V2 d;
    int sp8;
    int i, found;
    float a, b, z;
    float t1, t2;

    d = *(struct V2 *)arg2;
    a = arg1[0];
    b = arg1[1];
    z = -d.x;
    xf.p[0] = a;
    xf.p[1] = lbl_80562708;
    xf.p[2] = b;
    normal[0] = lbl_80562708;
    normal[1] = lbl_80562704;
    normal[2] = lbl_80562708;
    pts[0] = a + arg2[0] * lbl_80562724;
    pts[1] = lbl_80562708;
    pts[2] = b + arg2[1] * lbl_80562724;
    t1 = a + arg2[0] * lbl_80562710 + d.y * lbl_80562710;
    t2 = b + arg2[1] * lbl_80562710 + z * lbl_80562710;
    pts[3] = t1;
    pts[4] = lbl_80562708;
    pts[5] = t2;
    pts[6] = t1 + d.y * lbl_80562728;
    pts[7] = lbl_80562708;
    pts[8] = t2 + z * lbl_80562728;
    d.x = d.y;
    d.y = z;
    ((void (*)(void *))fn_801E9DC4)((char *)arg0 + 0x40);
    found = 0;
    for (i = 0; i < 3; i++) {
        if (fn_801E9E30((char *)arg0 + 0x40, &pts[i * 3]) == 0) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
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
    ((float *)arg0)[0xC] = lbl_80562708;
    ((float *)arg0)[0xD] = lbl_80562708;
    ((float *)arg0)[0xE] = lbl_80562708;
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
void fn_801B8060(int arg0, void *arg1) {
    float position[2];
    float direction[2];
    float x, y, sum, xPos, yPos, length, scale;

    x = *(float *)((char *)arg1 + 0x18);
    y = *(float *)((char *)arg1 + 0x20);
    sum = x * x + y * y;
    xPos = *(float *)((char *)arg1 + 0x24);
    yPos = *(float *)((char *)arg1 + 0x2C);
    position[0] = xPos;
    position[1] = yPos;
    direction[0] = x;
    direction[1] = y;
    length = (float)((double (*)(float, float, float, float, float))fn_8002F234)(
        sum, y, x, yPos, xPos);
    scale = (lbl_80562738 > length) ? lbl_80562738 : length;
    scale = lbl_80562704 / scale;
    direction[0] *= scale;
    direction[1] *= scale;
    fn_801B7C8C(arg0, position, direction);
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
