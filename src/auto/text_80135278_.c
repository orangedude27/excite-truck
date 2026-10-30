// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;

void fn_8013605C(void *);
void fn_80135F64(int, s32, s32, s32, s32);
extern float lbl_8055E3C8;
extern float lbl_8056133C;
void fn_80136714(void *);
extern float lbl_80561320;
extern float lbl_80561324;
extern s32 lbl_8032BE80[];

typedef struct {
    s32 unk_0;
    s32 unk_4;
    float unk_8;
    s32 unk_c;
    float unk_10;
    float unk_14;
    float unk_18;
    float unk_1c;
    float unk_20;
    float unk_24;
    u8 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    float unk_38, unk_3c, unk_40, unk_44, unk_48, unk_4c;
    float *unk_50;
    s32 unk_54, unk_58, unk_5c, unk_60;
} Unk_80135278;

s32 fn_80135D60(Unk_80135278 *, s32);
void fn_80135390(Unk_80135278 *);
void fn_801355C0(void *, s32, s32, void *, s32);
s32 fn_801357A4();

extern void *fn_80156A40(void);

typedef struct {
    float unk_0;
    float unk_4;
} Diffs2_80135278;

static float fn_80135278_dot(float *a, Diffs2_80135278 d) {
    return a[0] * d.unk_0 + a[1] * d.unk_4;
}

static Diffs2_80135278 fn_80135278_diff(float *b, float *c) {
    Diffs2_80135278 r;
    r.unk_0 = b[0] - c[0];
    r.unk_4 = b[1] - c[1];
    return r;
}

#pragma scheduling invalid_target
float fn_80135278(float *a, float *b, float *c) {
    return a[0] * (b[0] - c[0]) + a[1] * (b[1] - c[1]);
}
#pragma scheduling invalid_target
void *fn_801352B8(Unk_80135278 *arg0) {
    float value = lbl_80561320;
    Unk_80135278 *self;

    arg0->unk_0 = (s32)&lbl_8032BE80;
    self = arg0;
    self->unk_4 = 0;
    self->unk_c = 0x2710;
    self->unk_8 = value;
    fn_80135390(self);
    return self;
}
#pragma scheduling reset
void *fn_8013530C(void *arg0, s32 arg1) {
    if (arg0 != (void*)0) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_80135354(Unk_80135278 *arg0) {
    float g, f;
    f = lbl_80561320;
    g = lbl_80561324;
    arg0->unk_8 = f;
    arg0->unk_4 = 0;
    arg0->unk_c = 0;
    arg0->unk_20 = f;
    arg0->unk_24 = f;
    arg0->unk_10 = g;
    arg0->unk_14 = f;
    arg0->unk_18 = f;
    arg0->unk_1c = f;
    arg0->unk_28 = 0;
    arg0->unk_2c = 0;
}

#pragma dont_inline on
void fn_80135390(Unk_80135278 *arg0) {
    fn_80135354(arg0);
    arg0->unk_30 = 0;
}
#pragma dont_inline off

#pragma dont_inline on
void fn_801353C8(Unk_80135278 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    float f = lbl_80561320;
    arg0->unk_4 = arg3;
    arg0->unk_8 = f;
    fn_801355C0(arg0, arg1, arg2, &arg0->unk_4, 0);
    fn_801357A4(arg0, arg1);
}
#pragma scheduling invalid_target
void *fn_80135420(float *point, void *unused, void *list) {
    extern double __fabs(double);
    extern void fn_802E30C8(const char *, ...);
    extern const char lbl_8032BDB8[], lbl_8032BDE4[];
    extern float lbl_80561328, lbl_8056132C;
    float threshold;
    float bestDistance = lbl_80561328;
    void *best;
    void *node = *(void **)((char *)list + 0x1C);
    threshold = lbl_80561320;
    best = 0;
    do {
        if (fn_80135278((float *)((char *)node + 8), point, node) > threshold) {
            void *next = *(void **)((char *)node + 0x14);
            if (fn_80135278((float *)((char *)next + 8), point, next) < threshold) {
                float dx;
                float dy;
                float normalY;
                float normalX;
                float negativeNormalY;
                float dist;
                volatile float savedDiff[2];
                dx = point[0] - ((float *)node)[0];
                dy = point[1] - ((float *)node)[1];
                savedDiff[0] = dx;
                savedDiff[1] = dy;
                normalY = ((float *)node)[2];
                normalX = ((float *)node)[3];
                negativeNormalY = -normalY;
                dist = (float)__fabs((double)(normalX * dx + negativeNormalY * dy));
                if (dist < bestDistance) {
                    best = node;
                    bestDistance = dist;
                }
            }
        }
        node = *(void **)((char *)node + 0x14);
    } while (node != *(void **)((char *)list + 0x1C));
    if (best == 0) {
        float fallbackDistance = lbl_8056132C;
        node = *(void **)((char *)list + 0x1C);
        do {
            float dx;
            float dy;
            float nx;
            float ny;
            float dot;
            float dotSquared;
            float along;
            float dist;
            volatile float savedDiff[2];
            dx = point[0] - ((float *)node)[0];
            dy = point[1] - ((float *)node)[1];
            savedDiff[0] = dx;
            savedDiff[1] = dy;
            nx = ((float *)node)[3];
            ny = -((float *)node)[2];
            dot = nx * dx + ny * dy;
            dotSquared = dot * dot;
            along = fn_80135278((float *)((char *)node + 8), point, node);
            dist = dotSquared + along * along;
            if (dist < fallbackDistance) {
                best = node;
                fallbackDistance = dist;
            }
            node = *(void **)((char *)node + 0x14);
        } while (node != *(void **)((char *)list + 0x1C));
    }
    if (best == 0) {
        fn_802E30C8(lbl_8032BDB8, point[0], point[1]);
        fn_802E30C8(lbl_8032BDE4);
    }
    return best;
}
#pragma scheduling on
s32 fn_801353C4(void) {
    return fn_801357A4();
}

s32 fn_801355B8(void *arg0, void *arg1) {
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_801355C0(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    extern double fn_8002F234(float);
    extern double __fabs(double);
    extern float lbl_80561330;
    s32 id = *(s32 *)((char *)arg0 + 0xC);
    void **nodeState = (void **)arg3;
    float *fractionState = (float *)((char *)arg3 + 4);
    void *node;
    void *next;
    float scratch[6];
    float zero;
    float epsilon;
    float one;
    float fraction;
    float length;
    float dot;

    *(s32 *)((char *)arg3 + 8) = id;
    if (((s32 (*)(void *, void *, void *, void *))fn_801355B8)(arg0, (void *)arg1, arg3, (char *)arg3 + 4) != 0) return;
    if (*nodeState == 0) {
        *nodeState = fn_80135420((float *)arg1, (void *)arg2, *(void **)((char *)arg0 + 0x2C));
        *fractionState = lbl_80561320;
    }
    if (*nodeState == 0) return;
    one = lbl_80561324;
    arg2 = 0;
    epsilon = lbl_80561330;
    zero = lbl_80561320;

loop_start:
    node = *nodeState;
    fraction = *fractionState;
    next = *(void **)((char *)node + 0x14);
    scratch[2] = *(float *)((char *)node + 8) +
                 fraction * (*(float *)((char *)next + 8) - *(float *)((char *)node + 8));
    scratch[3] = *(float *)((char *)node + 0xC) +
                 fraction * (*(float *)((char *)next + 0xC) - *(float *)((char *)node + 0xC));
    scratch[4] = *(float *)node + fraction * (*(float *)next - *(float *)node);
    scratch[5] = *(float *)((char *)node + 4) +
                 fraction * (*(float *)((char *)next + 4) - *(float *)((char *)node + 4));
    length = (float)fn_8002F234(scratch[2] * scratch[2] + scratch[3] * scratch[3]);
    length = one / length;
    scratch[0] = ((float *)arg1)[0] - scratch[4];
    scratch[1] = ((float *)arg1)[1] - scratch[5];
    scratch[2] *= length;
    scratch[3] *= length;
    dot = scratch[2] * scratch[0] + scratch[3] * scratch[1];
    if ((float)__fabs((double)dot) < epsilon) goto done;
    if (dot < zero) {
        *fractionState = zero;
        goto done;
    }
advance:
    length = *(float *)((char *)node + 0x18);
    if (dot > length) {
        dot -= length;
        node = *(void **)((char *)node + 0x14);
        *nodeState = node;
        goto advance;
    }
    *fractionState = dot / length;
    ++arg2;
    if (arg2 < 10) goto loop_start;
done:
    return;
}
#pragma pop
void fn_80135B24(void *arg0, void *arg1, float farg0) {
    void *entry;
    void *node;
    void *base;
    float initial = lbl_80561320;

    *(void **)arg0 = 0;
    base = *(void **)((char *)arg1 + 0x2C);
    *(s32 *)((char *)arg0 + 8) = 0x2710;
    *(float *)((char *)arg0 + 4) = initial;
    node = *(void **)((char *)base + 0x20);
    *(void **)arg0 = node;
    if (node != 0) {
        for (;;) {
            node = *(void **)arg0;
            entry = *(void **)((char *)node + 0x14);
            if (*(float *)((char *)entry + 0x1C) >= farg0) {
                break;
            }
            if (*((u8 *)entry + 0x34) != 3) {
                break;
            }
            *(void **)arg0 = entry;
        }
        *(float *)((char *)arg0 + 4) = (farg0 - *(float *)((char *)node + 0x1C)) / *(float *)((char *)node + 0x18);
        *(s32 *)((char *)arg0 + 8) = 0;
    }
}
#pragma scheduling invalid_target
void fn_80135B9C(void *arg0, void *arg1, void *arg2, float *arg3, void *arg4, float amount) {
    extern double fn_8002F234(float);
    float step;
    register float fraction;
    float remaining;
    float length;
    float dx;
    float dy;
    float scale;
    float temp;
    int id;
    char *node;

    node = *(char **)((char *)arg0 + 4);
    if (node == 0) {
        if (arg2 != 0) {
            float second;
            float first;
            first = lbl_80561320;
            second = lbl_80561324;
            *(float *)arg2 = first;
            *((float *)arg2 + 1) = second;
        }
        if (arg1 != 0) {
            float zero = lbl_80561320;
            *(float *)arg1 = zero;
            *((float *)arg1 + 1) = zero;
        }
        return;
    }
    step = *(float *)(node + 0x18);
    fraction = *(float *)((char *)arg0 + 8);
    remaining = amount / step;
    if (fraction + remaining > lbl_80561324) {
        temp = lbl_80561324 - fraction;
        node = *(char **)(node + 0x14);
        remaining = amount - temp * step;
        while (remaining > *(float *)(node + 0x18)) {
            step = *(float *)(node + 0x18);
            node = *(char **)(node + 0x14);
            remaining -= step;
        }
        fraction = remaining / *(float *)(node + 0x18);
    } else {
        fraction += remaining;
    }
    if (arg1 != 0) {
        dx = *(float *)(*(volatile char **)(node + 0x14)) - *(float *)node;
        *(float *)arg1 = *(float *)node + fraction * dx;
        dy = *(float *)(*(volatile char **)(node + 0x14) + 4) - *(float *)(node + 4);
        *((float *)arg1 + 1) = *(float *)(node + 4) + fraction * dy;
    }
    if (arg2 != 0) {
        dx = *(float *)(*(volatile char **)(node + 0x14) + 8) - *(float *)(node + 8);
        *(float *)arg2 = *(float *)(node + 8) + fraction * dx;
        dy = *(float *)(*(volatile char **)(node + 0x14) + 0xC) - *(float *)(node + 0xC);
        *((float *)arg2 + 1) = *(float *)(node + 0xC) + fraction * dy;
        length = (*((float *)arg2) * *((float *)arg2)) +
                 (*((float *)arg2 + 1) * *((float *)arg2 + 1));
        scale = lbl_80561324 / (float)fn_8002F234(length);
        *(float *)arg2 *= scale;
        *((float *)arg2 + 1) *= scale;
    }
    if (arg4 != 0) {
        id = *(int *)((char *)arg0 + 0xC);
        *(char **)arg4 = node;
        *((float *)arg4 + 1) = fraction;
        *(int *)((char *)arg4 + 8) = id;
    }
    if (arg3 != 0) {
        float endValue;
        float startValue;
        endValue = *(float *)(*(volatile char **)(node + 0x14) + 0x20);
        startValue = *(float *)(node + 0x20);
        *(float *)arg3 = startValue + fraction * (endValue - startValue);
    }
}
#pragma scheduling reset
s32 fn_80135D60(Unk_80135278 *arg0, s32 arg1) {
    if ((unsigned long)arg1 != (unsigned long)arg0->unk_2c) {
        fn_80135354(arg0);
        arg0->unk_2c = arg1;
        if (arg1 == 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
extern void fn_80135EA8(void *, s32, s32);
extern void fn_80135F4C(void *);
extern s32 lbl_8032BE6C[];
#pragma cplusplus on
extern "C" void *fn_80135DC4(void *arg0, s32 arg1, s32 arg2) {
    struct Dummy {
        virtual s32 f0(s32);
        virtual s32 f1(s32);
        char pad[0x4C];
        s32 field50;
        s32 field54;
        volatile s32 field58;
    };
    Dummy *self = (Dummy *)arg0;
    ((void (*)(void *))fn_801352B8)(arg0);
    self->field58 = 0;
    *(s32 **)self = lbl_8032BE6C;
    self->field54 = 0;
    self->field50 = 0;
    if (arg2 == 0) {
        Dummy *obj = (Dummy *)fn_80156A40();
        arg2 = obj->f0(0);
    }
    if (self->f1(arg2) != 0) {
        if (arg1 != 0) {
            void *p = *(void **)((char *)self + 0x2C);
            fn_80135EA8(&self->field50, *(s32 *)((char *)p + 0x18) >> 16, 2);
        } else {
            self->field58 = 0;
            self->field54 = 0;
            self->field50 = 0;
        }
        ((void (*)(void *))fn_80135F4C)(arg0);
    }
    return arg0;
}
#pragma cplusplus reset
extern s32 fn_8012850C(s32, void *);
extern s32 lbl_8032BE20[];
void fn_80135EA8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp = arg1 + arg2;
    *(s32 *)((char *)arg0 + 4) = arg1;
    *(s32 *)((char *)arg0 + 8) = temp;
    *(s32 *)arg0 = fn_8012850C(temp * 4, lbl_8032BE20);
}

#pragma scheduling invalid_target
void fn_80135EF0(void *arg0, s32 arg1) {
    register s32 zero = 0;
    register Unk_80135278 *obj = (Unk_80135278 *)arg0;
    if (fn_80135D60(obj, arg1) == 1) {
        obj->unk_34 = zero;
        obj->unk_5c = zero;
        if (obj->unk_50 != 0) {
            register s32 value = *(s32 *)((u8 *)obj->unk_2c + 0x18);
            obj->unk_54 = value >> 16;
        }
    }
}
#pragma scheduling reset
void fn_80135F4C(void *arg0) {
    int x = *(int *)(*(char **)((char *)arg0 + 0x2C) + 0x1C);
    fn_80135F64((int)arg0, x, x + 8, 1, 0);
}

#pragma dont_inline on
void fn_80135F64(int arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
 s32 offset, i;
 fn_801353C8((void *)arg0,arg1,arg2,arg4);
 fn_80136714((void *)arg0);
 if(arg3 != 0 && *(s32 *)((char *)arg0+0x50)!=0) {
  float a=lbl_8055E3C8;
  float f=lbl_8056133C+a;
  for(i=0,offset=0;i<*(s32 *)((char *)arg0+0x54);i++,offset+=4)
   *(float *)(*(char **)((char *)arg0+0x50)+offset)=f;
  fn_8013605C((void *)arg0);
 } else fn_8013605C((void *)arg0);
 {
  Unk_80135278 *obj=(Unk_80135278 *)arg0;
  volatile float *v=(volatile float *)obj;
  Unk_80135278 *p=(Unk_80135278 *)obj->unk_4;
  float a,b,c,d,e,f,g,h,z;
  a=-v[4]; z=lbl_80561320;
  obj->unk_44=z;
  b=v[6];
  obj->unk_4c=z;
  c=v[7]; d=*(volatile float *)((char *)p+0x18); e=*(volatile float *)((char *)p+0x1c);
  a=a*c;
  f=v[2]; g=v[5];
  d=d*f;
  obj->unk_5c=0;
  h=g*b;
  obj->unk_60=0;
  e=e+d;
  a=h+a;
  obj->unk_48=e;
  obj->unk_40=a;
 }
}
#pragma dont_inline off

void fn_8013605C(void *arg0) {
    *(signed char *)((char *)arg0 + 0x64) = 0;
}

#pragma scheduling invalid_target
int fn_80136068(Unk_80135278 *arg0, void *arg1, int arg2) {
    extern float lbl_8055E3C8;
    extern float lbl_80561324;
    extern float lbl_80561338;
    extern float lbl_80561340;
    extern float lbl_80561344;
    extern float lbl_80561348;
    struct { char *node; float fraction; int saved; } locals;
    int changed;
    int status;
    int base;
    unsigned int start;
    unsigned int end;
    int keep;
    float dist;
    float length;
    float old48;
    float old40;
    float value;
    float edge;
    float delta;

    if ((void *)arg0->unk_2c == 0) {
        return 2;
    }
    locals.node = (char *)arg0->unk_4;
    locals.fraction = arg0->unk_8;
    changed = (((unsigned int)locals.node - (unsigned int)(char *)arg0->unk_60) | ((unsigned int)(char *)arg0->unk_60 - (unsigned int)locals.node)) >> 31;
    locals.saved = arg0->unk_c;
    status = fn_801353C4();
    base = arg0->unk_34;
    start = *(unsigned int *)(locals.node + 0x10);
    if (base != 0) {
        end = *(unsigned int *)((char *)(void *)arg0->unk_2c + 0x18);
        start = (end + (start - base)) % end;
    }

    if (status == 0) {
        char *head = (char *)arg0->unk_4;
        if (arg2 != 0) {
        char *walk = locals.node;
        float total = lbl_80561324 - locals.fraction;
        {
            unsigned int index;
            do {
                total += lbl_80561324;
                walk = *(char **)(walk + 0x14);
                index = *(unsigned int *)(walk + 0x10);
                if (base != 0) {
                    unsigned int size = *(unsigned int *)((char *)(void *)arg0->unk_2c + 0x18);
                    index = (size + (index - base)) % size;
                }
            } while (index > start);
        }
        walk = locals.node;
        length = lbl_80561324 - locals.fraction;
        do {
            length += lbl_80561324;
            walk = *(char **)(walk + 0x14);
        } while (walk != head);
        *(float *)arg2 = lbl_80561340 * (lbl_80561324 - (total / (length + arg0->unk_8)));
        }
    }

    {
        char *saved = (char *)arg0->unk_5c;
        if (saved != 0 && (status == 2 || status == 0)) {
            int cleanupBase = *(volatile s32 *)&arg0->unk_34;
            float fill = lbl_8055E3C8;
            unsigned int a = *(unsigned int *)(saved + 0x10);
            if (cleanupBase != 0) {
                unsigned int size = *(unsigned int *)((char *)(void *)arg0->unk_2c + 0x18);
                a = (size + (a - cleanupBase)) % size;
            }
            start = ((int)a) >> 16;
            {
                unsigned int b = *(unsigned int *)((char *)arg0->unk_4 + 0x10);
                if (cleanupBase != 0) {
                    unsigned int size = *(unsigned int *)((char *)(void *)arg0->unk_2c + 0x18);
                    b = (size + (b - cleanupBase)) % size;
                }
                end = ((int)b) >> 16;
            }
            while ((unsigned int)start != (unsigned int)end) {
                *(float *)((char *)arg0->unk_50 + start * 4) = fill;
                start = (start + 1) % (unsigned int)arg0->unk_54;
            }
        }
    }
    arg0->unk_5c = arg0->unk_4;
    fn_80136714(arg0);

    {
        old48 = arg0->unk_48;
        old40 = arg0->unk_40;
        arg0->unk_48 = *(float *)((char *)arg0->unk_4 + 0x1C) +
                                  *(float *)((char *)arg0->unk_4 + 0x18) * arg0->unk_8;
    arg0->unk_40 = arg0->unk_14 * arg0->unk_18 +
                              -arg0->unk_10 * arg0->unk_1c;

        keep = 1;
        if (!changed) {
            if (*(unsigned char *)((char *)arg0->unk_4 + 0x35) == *(unsigned char *)(locals.node + 0x35) &&
                *(unsigned char *)((char *)arg0->unk_4 + 0x34) == *(unsigned char *)(locals.node + 0x34)) {
                keep = 0;
            }
        }
    if (!keep) {
        value = arg0->unk_48 - old48;
        arg0->unk_4c = value;
        edge = *(float *)((char *)arg0->unk_2c +
                          *(unsigned char *)((char *)arg0->unk_4 + 0x34) * 4 + 8);
        if (value < -edge * lbl_80561338) {
            arg0->unk_4c = value + edge;
        }
        delta = lbl_80561344 * (arg0->unk_40 - old40);
        arg0->unk_4c *= lbl_80561344;
        arg0->unk_44 = delta + lbl_80561348 * (arg0->unk_44 - delta);
        }
    }
    arg0->unk_60 = arg0->unk_4;
    return status;
}
#pragma scheduling invalid_target
int fn_801363A0(void *arg0, void *arg1) {
    void *temp_r6 = *(void * volatile *)arg1;
    int temp_r31 = *(int *)((char *)temp_r6 + 0x10);
    int var = *(int *)((char *)*(void **)((char *)temp_r6 + 0x14) + 0x10);
    if (var == 0) {
        var = *(int *)((char *)*(void **)((char *)arg0 + 0x2C) + 0x18);
    }
    return temp_r31 + (unsigned int)(*(float *)((char *)arg1 + 4) * (float)(var - temp_r31));
}
#pragma scheduling on
extern float lbl_80561358;
extern double lbl_80561360;
void fn_80136414(void *arg0, void *arg1, s32 arg2) {
    unsigned long low;
    unsigned long index;
    union {
        double value;
        struct { unsigned long hi, lo; } words;
    } converted;
    float divisor;
    float fraction;
    char *node;
    char *base;

    low = (unsigned long)arg2 & 0xFFFF;
    converted.words.hi = 0x43300000;
    node = *(char **)((char *)arg1 + 0x2C);
    converted.words.lo = low;
    index = ((unsigned long)arg2) >> 16;
    fraction = converted.value - lbl_80561360;
    divisor = lbl_80561358;
    base = *(char **)(node + 0x1C);
    *(char **)arg0 = base + index * 0x3C;
    *(s32 *)((char *)arg0 + 8) = 0;
    *(float *)((char *)arg0 + 4) = fraction / divisor;
}

extern double fn_8002EFB4(double, double);
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8032BE30[];
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
void fn_80136468(Unk_80135278 *out, Unk_80135278 *self, float f) {
    char *p = (char *)*(void **)((char *)self + 0x2c);
    char *latestP;
    char *sentinel;
    char *cursor;
    char *q;
    register float *period;
    float d;
    s32 mode;
    s32 limit;
    if (p == 0) {
        float zero = lbl_80561320;
        *(s32 *)out = 0;
        *(s32 *)((char *)out + 8) = 0x2710;
        *(float *)((char *)out + 4) = zero;
        return;
    }
    mode = *(s32 *)((char *)self + 0xc);
    period = (float *)(p + 8);
    if (f > lbl_80561320) {
        d = (float)fn_8002EFB4((double)f, (double)*period);
    } else {
        d = *period - (float)fn_8002EFB4((double)-f, (double)*period);
    }
    limit = 0x2710;
    cursor = *(char **)(p + 0x1c);
    latestP = (char *)*(void * volatile *)((char *)self + 0x2c);
    sentinel = *(char **)(latestP + 0x1c);
    while (1) {
        q = *(char **)(cursor + 0x14);
        if (q == sentinel)
            break;
        if (*(float *)(q + 0x1c) >= d)
            break;
        limit--;
        cursor = q;
        if (limit <= 0) {
            fn_802E30C8(lbl_8032BE30, mode, (double)d, (double)*period);
            d = lbl_80561320;
            break;
        }
    }
    latestP = (char *)*(void * volatile *)((char *)self + 0x2c);
    sentinel = *(char **)(latestP + 0x1c);
    if (*(u8 *)(sentinel + 0x34) != *(u8 *)(q + 0x34)) {
        d = lbl_80561320;
    } else {
        d = (d - *(float *)(sentinel + 0x1c)) / *(float *)(sentinel + 0x18);
    }
    *(s32 *)out = (s32)q;
    *(float *)((char *)out + 4) = d;
    *(s32 *)((char *)out + 8) = mode;
}
#pragma cplusplus reset

#pragma scheduling invalid_target
void fn_80136594(void *arg0, s32 arg1, s32 arg2) {
    float f = lbl_80561320;
    s32 *p = (s32 *)arg0;
    p[0] = 0;
    p[2] = 0x2710;
    *(float *)(p + 1) = f;
    fn_801355C0((void *)arg1, arg2, 0, arg0, 0);
}
#pragma push
#pragma scheduling invalid_target
float fn_801365C4(Unk_80135278 *a, Unk_80135278 *b) {
    s32 same, offset, pos, count, i, j;
    unsigned long length;
    Unk_80135278 *p;
    void *data;
    float value, result;
    data = (void *)a->unk_2c;
    if (data == 0 || b->unk_4 == 0 || a->unk_4 == 0 || b->unk_54 != a->unk_54)
        return lbl_80561320;
    p = (Unk_80135278 *)a->unk_4;
    same = p == (Unk_80135278 *)b->unk_4;
    offset = ((-same | same) >> 31) - 1;
    pos = *(s32 *)((char *)p + 0x10);
    if (a->unk_34 != 0) {
        length = *(unsigned long *)((char *)data + 0x18);
        pos = (length + (pos - a->unk_34)) % length;
    }
    count = a->unk_54;
    i = ((pos >> 16) + (count + offset)) % count;
    j = (i + 1) % count;
    value = a->unk_8 * (b->unk_50[j] - b->unk_50[i]) + b->unk_50[i];
    if (same)
        result = a->unk_8 * (a->unk_50[j] - a->unk_50[i]) + a->unk_50[i];
    else
        result = lbl_8055E3C8;
    return result - value;
}
#pragma pop
s32 fn_801366C0(void *arg0, void *arg1, float farg0) {
    if (*(s32 *)((char *)arg0 + 4) == 0 ||
        *(s32 *)(*(s32 *)((char *)arg0 + 0x2C) + 0x1C) == 0)
        return 0;
    return ((*(float *)((char *)arg1 + 0) * *(float *)((char *)arg0 + 0x10))
          + (*(float *)((char *)arg1 + 8) * *(float *)((char *)arg0 + 0x14))) < -farg0;
}

void fn_80136714(void *arg0) {
    float a = *(float *)((char *)arg0 + 0x10);
    float b = *(float *)((char *)arg0 + 0x14);
    *(float *)((char *)arg0 + 0x38) = b;
    *(float *)((char *)arg0 + 0x3C) = -a;
}

extern void *fn_80156A40(void);

typedef struct {
    void *unk_0;
    void *unk_4;
    void *(*unk_8)(void *, s32);
} Vt_8013672C;

typedef struct {
    Vt_8013672C *vtbl;
} Unk_8013672C_vt;

#pragma cplusplus on
extern "C" float fn_8013672C(void) {
    class Obj {
    public:
        virtual void *get(s32 index);
    };
    Obj *obj = (Obj *)fn_80156A40();
    void *ret = obj->get(0);
    return *(float *)((char *)ret + 8);
}
#pragma cplusplus reset
void fn_80136764(void) {
    fn_801564B0();
}

void fn_80136768(void) {
    fn_801569FC();
}

void *fn_8013676C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u8 *)arg0 + 0x50 != 0) {
            if (*(s32 *)((u8 *)arg0 + 0x50) != 0) {
                fn_80128670();
            }
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
        }
        fn_8013530C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_801367E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1();
    };
    s32 r = ((Dummy *)arg0)->f1();
    if (r == 1) {
        fn_801353C8((Unk_80135278 *)arg0, arg2, arg3, 0);
    }
}
#pragma cplusplus on
extern "C" void fn_80136854(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1();
    };
    s32 r = ((Dummy *)arg0)->f1();
    if (r == 1) {
        fn_80135F64((int)arg0, arg2, arg3, 1, 0);
    }
}
#pragma cplusplus reset
