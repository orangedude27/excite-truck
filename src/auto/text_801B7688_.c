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
        if (zero != 0) goto shared;
        if (state == 1) result = 0;
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
void fn_801B7760(int arg0, int arg1, float farg0, float farg1) {
    struct Vector {
        float x;
        float y;
        float z;
        float w;
        int pad;
        struct Vector * volatile next;
    };
    struct Args {
        struct Vector *value;
        float t;
    };
    struct Result {
        float z;
        float w;
        float x;
        float y;
    };
    struct Vector *p = ((struct Args *)arg1)->value;
    float t = ((struct Args *)arg1)->t;
    float angle = farg1;
    float offset = farg0;
    double temp;
    struct Result value;

    value.x = p->x + t * (p->next->x - p->x);
    value.y = p->y + t * (p->next->y - p->y);
    value.z = p->z + t * (p->next->z - p->z);
    value.w = p->w + t * (p->next->w - p->w);
    {
        float length = fn_8002F234(value.z * value.z + value.w * value.w);
        float scale = lbl_80562704 / length;
        float z;

        value.z *= scale;
        value.w *= scale;
        temp = *(double *)&value.z;
        z = value.z;
        {
            float normZ = ((float *)&temp)[0];
            float normW = ((float *)&temp)[1];
            float negZ = -normZ;
            float offsetW = normW * offset;
            value.x += offsetW;
            value.y += negZ * offset;
        }
        offset = (float)cos(angle);
        {
            float sine = (float)sin(angle);
            value.z = z * offset - value.w * sine;
            value.w = z * sine + value.w * offset;
        }
    }
    fn_801B7C8C(arg0, &value.x, &value.z);
    *(int *)((char *)arg0 + 0x3C) = 0;
}
#pragma scheduling on
extern void fn_80135B24(void *, float);
extern void fn_80136468(void *, float);
void fn_801B78EC(int arg0, int arg1, int arg2, float farg0, float farg1, float farg2) {
    struct Triple {
        int first;
        float second;
        int third;
    };
    struct Triple slots[3];

    (void)arg1;
    slots[2].first = 0;
    slots[2].second = lbl_80562708;
    slots[2].third = 0x2710;
    if (arg2 != 0) {
        fn_80135B24(&slots[1], farg1);
        slots[2].first = slots[1].first;
        slots[2].second = slots[1].second;
        slots[2].third = slots[1].third;
    } else {
        fn_80136468(&slots[0], farg1);
        slots[2].first = slots[0].first;
        slots[2].second = slots[0].second;
        slots[2].third = slots[0].third;
    }
    fn_801B7760(arg0, (int)&slots[2], farg0, farg2);
}

#pragma dont_inline fn_801B79AC
float fn_801B79AC(void) {
    return *(float *)((char *)fn_80137C54(-1) + 4);
}

void PSVECCrossProduct(float *, float *, float *);
void PSVECNormalize(float *, float *);
void fn_801B7BA8(float *arg0, float *arg1, float *arg2) {
    float a[3];
    float b[3];
    float c[3];
    volatile float *p = arg1;
    volatile float *q = arg2;
    float x = p[0];
    float y = p[1];
    float z = p[2];
    float u = q[0];
    float v = q[1];
    a[0] = x; a[1] = y; a[2] = z;
    b[0] = u; b[1] = lbl_80562708; b[2] = v;
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
    float base[3];
    float points[9];
    float matrix[12];
    float out[9];
    float normal[3];
    float cross[3];
    float delta1[3];
    float delta2[3];
    int flags;
    int i;
    float x = arg2[0];
    float y = arg2[1];
    float nx = -x;
    float a = arg1[0];
    float b = arg1[1];
    float z = (float)nx;

    base[0] = a;
    base[1] = lbl_80562708;
    base[2] = b;

    points[0] = a + x * lbl_80562724;
    points[1] = lbl_80562708;
    points[2] = b + y * lbl_80562724;
    points[3] = a + x * lbl_80562710 + y * lbl_80562710;
    points[4] = lbl_80562708;
    points[5] = b + y * lbl_80562710 + z * lbl_80562710;
    points[6] = a + y * lbl_80562728;
    points[7] = lbl_80562708;
    points[8] = b + z * lbl_80562728;

    fn_801E9DC4((char *)arg0 + 0x40, arg1, arg2);
    for (i = 0; i < 3; i++) {
        if (fn_801E9E30((char *)arg0 + 0x40, &points[i * 3]) == 0)
            break;
    }
    flags = i < 3;
    if (!flags) {
        fn_801E9E78((char *)arg0 + 0x40, base, matrix, (int *)0);
        delta1[0] = points[3] - points[0];
        delta1[1] = points[4] - points[1];
        delta1[2] = points[5] - points[2];
        delta2[0] = points[6] - points[0];
        delta2[1] = points[7] - points[1];
        delta2[2] = points[8] - points[2];
        PSVECCrossProduct(delta2, delta1, matrix);
        PSVECNormalize(matrix, matrix);
    } else {
        fn_801E9DC4((char *)arg0 + 0x40, arg1, arg2);
        fn_801E9E78((char *)arg0 + 0x40, base, matrix, (int *)0);
    }
    fn_801B7BA8(out, matrix, arg2);
    base[0] += out[3] * lbl_8056272C;
    base[1] += out[4] * lbl_8056272C;
    base[2] += out[5] * lbl_8056272C;
    *(float **)(arg0) = (float *)0;
}

extern void *fn_80178C9C(void);
extern void fn_801B78EC(int, int, int, float, float, float);
extern void fn_801B8054(int, int, float, float);
extern float lbl_80562720;
extern const float lbl_80562730;
extern float lbl_80562734;
void fn_801B7F4C(void *arg0, int arg1, int arg2) {
    void *root;
    void *container;
    void *object;
    float base;
    float offset;

    (void)arg2;
    if (*(void **)((char *)*(void **)((char *)fn_80178C9C() + 0x2C) + 0x20) != 0) {
        container = *(void **)((char *)fn_80178C9C() + 0x2C);
        object = *(void **)((char *)container + 0x20);
        base = lbl_80562734 + *(float *)((char *)object + 0x1C);
        root = fn_80178C9C();
        offset = lbl_80562720 + base;
        fn_801B8054((int)arg0, (int)root, lbl_80562708,
                    offset + (float)arg1 * lbl_80562730);
    } else {
        root = fn_80178C9C();
        fn_801B78EC((int)arg0, (int)root, 0, lbl_80562708,
                    (float)arg1 * lbl_80562730, lbl_80562708);
    }
}

void fn_801B8040(int arg0, int arg1, float farg0) {
    fn_801B7760(arg0, arg1, farg0, lbl_80562708);
}

#pragma dont_inline fn_801B78EC
void fn_801B8048(int arg0, int arg1, float farg0, float farg1) {
    fn_801B78EC(arg0, arg1, 0, farg0, farg1, lbl_80562708);
}

#pragma dont_inline fn_801B78EC
void fn_801B8054(int arg0, int arg1, float farg0, float farg1) {
    fn_801B78EC(arg0, arg1, 1, farg0, farg1, lbl_80562708);
}

#pragma optimize_for_size on
#pragma scheduling invalid_target
void fn_801B8060(int arg0, void *arg1) {
    float position[2];
    float direction[2];
    float x;
    float y;
    float sum;
    float xPos;
    float yPos;
    float length;
    float scale;

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
#pragma scheduling on
#pragma optimize_for_size off
extern char lbl_80336718[];
extern int fn_802E317C(char *, ...);
void fn_801B8100(void *arg0, int arg1, int arg2) {
    int result;
    memset(arg0, 0, 0x50);
    if (fn_801796B4() != 0)
        return;
    if (fn_801B8630(arg0, arg1, arg2) != 0)
        return;
    result = fn_801B7688(arg2);
    *(int *)((char *)arg0 + 0x44) = result;
    switch (result) {
        case 3:
        case 4:
        case 0:
            fn_801B7F4C(arg0, arg1, arg2);
            return;
        case 1:
        case 2:
            fn_801B79D4(arg0, arg1, arg2);
            return;
        default:
            fn_802E317C(lbl_80336718, result);
    }
}