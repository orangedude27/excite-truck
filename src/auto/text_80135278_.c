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

// One stretch of a path: where it starts, the direction it runs in, the next
// stretch and how far along the path it begins.
typedef struct PathNode {
    /* 0x00 */ float x;                // start of the stretch
    /* 0x04 */ float y;
    /* 0x08 */ float dirX;             // direction of the stretch (not unit length)
    /* 0x0C */ float dirY;
    /* 0x10 */ float unk_10;
    /* 0x14 */ struct PathNode *next;
    /* 0x18 */ float length;           // length of this stretch
    /* 0x1C */ float pathDistance;     // distance along the path at the start
    /* 0x20 */ float value;            // per-node value the samplers interpolate
    /* 0x24 */ float unk_24;
} PathNode;

// The next stretch, read straight from memory every time: the path code reads it
// through a volatile pointer, so the compiler reloads it at each use.
#define PATH_NEXT(node) ((struct PathNode *)(*(volatile struct PathNode **)&(node)->next))

// A place along a path: the stretch it is on, how far along that stretch it is
// (0..1) and a tag saying how it was found - fn_80135B24 leaves 0x2710 when it
// cannot place the sample and writes 0 when it can.
typedef struct PathSample {
    /* 0x00 */ PathNode *node;
    /* 0x04 */ float fraction;
    /* 0x08 */ s32 tag;
} PathSample;

// The path follower object (Unk_80135278) as the samplers see it: its vtable
// and then the sample it has reached.
typedef struct PathCursor {
    /* 0x00 */ void *vtable;
    /* 0x04 */ PathSample sample;
} PathCursor;

// A 2D point or direction, as handed to and from the path samplers.
typedef struct PathVec {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
} PathVec;

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
#pragma scheduling off
void *fn_801352B8(Unk_80135278 *arg0) {
    Unk_80135278 *self;
    float value = lbl_80561320;

    arg0->unk_0 = (s32)&lbl_8032BE80;
    self = arg0;
    self->unk_4 = 0;
    self->unk_c = 0x2710;
    self->unk_8 = value;
    fn_80135390(self);
    return self;
}
#pragma scheduling on
#pragma dont_inline on
void *fn_8013530C(void *arg0, s32 arg1) {
    if (arg0 != (void*)0) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}
#pragma dont_inline off

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
#pragma scheduling invalid_target
void fn_801353C8(Unk_80135278 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    volatile float f = lbl_80561320;
    arg0->unk_4 = arg3;
    arg0->unk_8 = f;
    fn_801355C0(arg0, arg1, arg2, &arg0->unk_4, 0);
    fn_801357A4(arg0, arg1);
}
// The circular list of stretches the samplers search: only its first stretch
// is read here.  (The searches below walk it with fn_80135420's own loads.)
#define PATH_FIRST(list) (*(PathNode **)((char *)(list) + 0x1C))

#define PATH_ZERO lbl_80561320        /* 0.0f: the side of a stretch's start */
#define PAIR_ACROSS_LIMIT lbl_80561328 /* 1000.0f: how far off a straddling stretch a point may sit */
#define NEAREST_LIMIT lbl_8056132C    /* 4e6: squared reach of the fallback search */
#define MSG_NO_PAIR lbl_8032BDB8      /* "ideal: Can't find a good pair for %.2f,%.2f" */
#define MSG_UPSET lbl_8032BDE4        /* "ideal: Someone is probably going to be upset about this." */

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
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
                float dy;
                float dx;
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
            float dy;
            float dx;
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
            dist = along * along;
            dist += dotSquared;
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
#pragma pop
s32 fn_801353C4(void) {
    return fn_801357A4();
}

s32 fn_801355B8(void *arg0, void *arg1, void *arg2, void *arg3) {
    return 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801355C0(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    extern double fn_8002F234(float);
    extern double __fabs(double);
    extern float lbl_80561330;
    typedef struct { void *node; float frac; s32 unk8; } State;
    void *node;
    void *next;
    float fraction;
    float length;
    float dot;
    float scratch[6];
    float zero;
    float epsilon;
    float one;
    State *st = (State *)arg3;
    void *tmpNode;
    float tmpFrac;
    st->unk8 = *(s32 *)((char *)arg0 + 0xC);
    if (((s32 (*)(void *, void *, void *, void *))fn_801355B8)(arg0, (void *)arg1, arg3, &st->frac) != 0) return;
    if (st->node == 0) {
        tmpNode = fn_80135420((float *)arg1, (void *)arg2, *(void **)((char *)arg0 + 0x2C));
        tmpFrac = lbl_80561320;
        st->node = tmpNode;
        st->frac = tmpFrac;
    }
    if (st->node == 0) return;
    one = lbl_80561324;
    arg2 = 0;
    epsilon = lbl_80561330;
    zero = lbl_80561320;
loop_start:
    node = st->node;
    fraction = st->frac;
    next = *(void **)((char *)node + 0x14);
    scratch[2] = *(float *)((char *)node + 8) + fraction * (*(float *)((char *)next + 8) - *(float *)((char *)node + 8));
    scratch[3] = *(float *)((char *)node + 0xC) + fraction * (*(float *)((char *)next + 0xC) - *(float *)((char *)node + 0xC));
    scratch[4] = *(float *)node + fraction * (*(float *)next - *(float *)node);
    scratch[5] = *(float *)((char *)node + 4) + fraction * (*(float *)((char *)next + 4) - *(float *)((char *)node + 4));
    length = (float)fn_8002F234(scratch[2] * scratch[2] + scratch[3] * scratch[3]);
    length = one / length;
    scratch[0] = ((float *)arg1)[0] - scratch[4];
    scratch[1] = ((float *)arg1)[1] - scratch[5];
    scratch[2] *= length;
    scratch[3] *= length;
    dot = scratch[2] * scratch[0] + scratch[3] * scratch[1];
    if ((float)__fabs((double)dot) < epsilon) goto done;
    if (dot < zero) {
        st->frac = zero;
        goto done;
    }
    length = *(float *)((char *)node + 0x18);
    if (dot > length) {
        do {
            dot -= length;
            node = *(void **)((char *)node + 0x14);
            st->node = node;
            length = *(float *)((char *)node + 0x18);
        } while (dot > length);
    }
    st->frac = dot / length;
    ++arg2;
    if (arg2 < 10) goto loop_start;
done:
    return;
}
#pragma scheduling invalid_target
void fn_80135B24(void *arg0, void *arg1, float farg0) {
    register void *entry;
    register void *node;
    void *base;
    float initial = lbl_80561320;
    *(void **)arg0 = 0;
    base = *(void **)((char *)arg1 + 0x2C);
    *(s32 *)((char *)arg0 + 8) = 0x2710;
    *(float *)((char *)arg0 + 4) = initial;
    node = *(void **)((char *)base + 0x20);
    *(void **)arg0 = node;
    if (node == 0) goto done;
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
done:
    return;
}
#pragma scheduling on
void fn_80135B9C(PathCursor *cursor, PathVec *posOut, PathVec *dirOut, float *valueOut, PathSample *sampleOut, float amount) {
    /* Move the follower's place along its path by `amount` world units and read
     * the path there.  Every output is optional: posOut gets the position,
     * dirOut the path direction scaled to unit length, valueOut the node value
     * interpolated across the stretch and sampleOut the new place (stretch,
     * fraction and tag).  Distance left over at the end of one stretch carries
     * into the next nodes; with no node to work from the outputs fall back to
     * position (0, 0) and direction (0, 1). */
    extern double fn_8002F234(float);  // sqrt
    float step;
    register float fraction;
    float remaining;
    float length;
    float dx;
    float dy;
    float scale;
    float temp;
    int id;
    PathNode *node;

    node = cursor->sample.node;
    if (node == 0) {
        if (dirOut != 0) {
            float second;
            float first;
            first = lbl_80561320;   // 0.0f
            second = lbl_80561324;  // 1.0f
            dirOut->x = first;
            dirOut->y = second;
        }
        if (posOut != 0) {
            float zero = lbl_80561320;
            posOut->x = zero;
            posOut->y = zero;
        }
        return;
    }
    step = node->length;
    fraction = cursor->sample.fraction;
    remaining = amount / step;
    if (fraction + remaining > lbl_80561324) {  // past the end of this stretch
        temp = lbl_80561324 - fraction;
        node = PATH_NEXT(node);
        remaining = amount - temp * step;
        while (remaining > node->length) {  // walk whole stretches off
            step = node->length;
            node = PATH_NEXT(node);
            remaining -= step;
        }
        fraction = remaining / node->length;
    } else {
        fraction += remaining;
    }
    if (posOut != 0) {  // the position between this node and the next
        dx = PATH_NEXT(node)->x - node->x;
        posOut->x = node->x + fraction * dx;
        dy = PATH_NEXT(node)->y - node->y;
        posOut->y = node->y + fraction * dy;
    }
    if (dirOut != 0) {  // the direction there, scaled to unit length
        dx = PATH_NEXT(node)->dirX - node->dirX;
        dirOut->x = node->dirX + fraction * dx;
        dy = PATH_NEXT(node)->dirY - node->dirY;
        dirOut->y = node->dirY + fraction * dy;
        length = (dirOut->x * dirOut->x) + (dirOut->y * dirOut->y);
        scale = lbl_80561324 / (float)fn_8002F234(length);
        dirOut->x *= scale;
        dirOut->y *= scale;
    }
    if (sampleOut != 0) {
        id = cursor->sample.tag;
        sampleOut->node = node;
        sampleOut->fraction = fraction;
        sampleOut->tag = id;
    }
    if (valueOut != 0) {  // the node value across the same stretch
        float endValue;
        float startValue;
        endValue = PATH_NEXT(node)->value;
        startValue = node->value;
        *valueOut = startValue + fraction * (endValue - startValue);
    }
}
#pragma opt_propagation off
#pragma opt_dead_assignments off
s32 fn_80135D60(Unk_80135278 *arg0, s32 arg1) {
    if ((unsigned long)arg1 != (unsigned long)arg0->unk_2c) {
        fn_80135354(arg0);
        arg0->unk_2c = arg1;
        switch (arg1) {
        default:
            return 1;
        case 0:
            return 0;
        }
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
    /* Construct/init this object: run base init, set vtable/fields to defaults,
       resolve a default resource via fn_80156A40/f0 when arg2 is 0, then if the
       virtual setup (f1) succeeds either initialize the field50 buffer from data
       at arg0+0x2C (count = *(s32*)(p+0x18) >> 16, +2 extra) when arg1 != 0 or
       clear those fields, and finally run fn_80135F4C. */
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
s32 fn_80135EF0(void *arg0, s32 arg1) {
    Unk_80135278 *obj = (Unk_80135278 *)arg0;
    s32 res = fn_80135D60(obj, arg1);
    if (res == 1) {
        obj->unk_34 = 0;
        obj->unk_5c = 0;
        if (obj->unk_50 != 0) {
            obj->unk_54 = *(s32 *)((u8 *)obj->unk_2c + 0x18) >> 16;
        }
    }
    return res;
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
  Unk_80135278 *p;
  float a,z,c,e,d,f,g,h,b;
  float t = v[4];
  a = -t; z=lbl_80561320;
  p=(Unk_80135278 *)obj->unk_4;
  obj->unk_44=z;
  b=v[6];
  obj->unk_4c=z;
  c=v[7]; d=*(volatile float *)((char *)p+0x18); e=*(volatile float *)((char *)p+0x1c);
  a*=c;
  f=v[2]; g=v[5];
  d*=f;
  obj->unk_5c=0;
  h=g*b;
  obj->unk_60=0;
  e+=d;
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
int fn_80136068(void *arg0, void *arg1, int arg2) {
    extern float lbl_8055E3C8;
    extern float lbl_80561324;
    extern float lbl_80561338;
    extern float lbl_80561340;
    extern float lbl_80561344;
    extern float lbl_80561348;
    char *self = (char *)arg0;
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

    if (*(void **)(self + 0x2C) == 0) {
        return 2;
    }
    locals.node = *(char **)(self + 4);
    locals.fraction = *(float *)(self + 8);
    changed = (((unsigned int)locals.node - (unsigned int)*(char **)(self + 0x60)) | ((unsigned int)*(char **)(self + 0x60) - (unsigned int)locals.node)) >> 31;
    locals.saved = *(int *)(self + 0xC);
    status = fn_801353C4();
    base = *(int *)(self + 0x34);
    start = *(unsigned int *)(locals.node + 0x10);
    if (base != 0) {
        end = *(unsigned int *)((char *)*(void **)(self + 0x2C) + 0x18);
        start = (end + (start - base)) % end;
    }

    if (status == 0) {
        char *head = *(char **)(self + 4);
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
                    unsigned int size = *(unsigned int *)((char *)*(void **)(self + 0x2C) + 0x18);
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
        *(float *)arg2 = lbl_80561340 * (lbl_80561324 - (total / (length + *(float *)(self + 8))));
        }
    }

    {
        char *saved = *(char **)(self + 0x5C);
        if (saved != 0 && (status == 2 || status == 0)) {
            int cleanupBase = *(volatile int *)(self + 0x34);
            float fill = lbl_8055E3C8;
            unsigned int a = *(unsigned int *)(saved + 0x10);
            if (cleanupBase != 0) {
                unsigned int size = *(unsigned int *)((char *)*(void **)(self + 0x2C) + 0x18);
                a = (size + (a - cleanupBase)) % size;
            }
            start = ((int)a) >> 16;
            {
                unsigned int b = *(unsigned int *)(*(char **)(self + 4) + 0x10);
                if (cleanupBase != 0) {
                    unsigned int size = *(unsigned int *)((char *)*(void **)(self + 0x2C) + 0x18);
                    b = (size + (b - cleanupBase)) % size;
                }
                end = ((int)b) >> 16;
            }
            while ((unsigned int)start != (unsigned int)end) {
                *(float *)(*(char **)(self + 0x50) + start * 4) = fill;
                start = (start + 1) % *(unsigned int *)(self + 0x54);
            }
        }
    }
    *(char **)(self + 0x5C) = *(char **)(self + 4);
    fn_80136714(arg0);

    {
        old48 = *(float *)(self + 0x48);
        old40 = *(float *)(self + 0x40);
        *(float *)(self + 0x48) = *(float *)(*(char **)(self + 4) + 0x1C) +
                                  *(float *)(*(char **)(self + 4) + 0x18) * *(float *)(self + 8);
    *(float *)(self + 0x40) = *(float *)(self + 0x14) * *(float *)(self + 0x18) +
                              -*(float *)(self + 0x10) * *(float *)(self + 0x1C);

        keep = 1;
        if (!changed) {
            if (*(unsigned char *)(*(char **)(self + 4) + 0x35) == *(unsigned char *)(locals.node + 0x35) &&
                *(unsigned char *)(*(char **)(self + 4) + 0x34) == *(unsigned char *)(locals.node + 0x34)) {
                keep = 0;
            }
        }
    if (!keep) {
        value = *(float *)(self + 0x48) - old48;
        *(float *)(self + 0x4C) = value;
        edge = *(float *)(*(char **)(self + 0x2C) +
                          *(unsigned char *)(*(char **)(self + 4) + 0x34) * 4 + 8);
        if (value < -edge * lbl_80561338) {
            *(float *)(self + 0x4C) = value + edge;
        }
        delta = lbl_80561344 * (*(float *)(self + 0x40) - old40);
        *(float *)(self + 0x4C) *= lbl_80561344;
        *(float *)(self + 0x44) = delta + lbl_80561348 * (*(float *)(self + 0x44) - delta);
        }
    }
    *(char **)(self + 0x60) = *(char **)(self + 4);
    return status;
}
int fn_801363A0(void *arg0, void *arg1) {
    void *temp_r6;
    int temp_r31;
    int var;
    temp_r6 = *(void **)arg1;
    temp_r31 = *(int *)((char *)temp_r6 + 0x10);
    var = *(int *)((char *)*(void **)((char *)temp_r6 + 0x14) + 0x10);
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
extern "C" void fn_80136468(Unk_80135278 *out, Unk_80135278 *self, float f) {
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
    s32 length;
    s32 p_data;
    s32 p;
    float value, result;
    p_data = a->unk_2c;
    if (p_data == 0 || b->unk_4 == 0 || a->unk_4 == 0 || b->unk_54 != a->unk_54)
        return lbl_80561320;
    p = a->unk_4;
    same = (void *)p == (void *)b->unk_4;
    offset = ((-same | same) >> 31) - 1;
    pos = *(s32 *)(p + 0x10);
    if (a->unk_34 != 0) {
        length = *(s32 *)(p_data + 0x18);
        pos = ((unsigned long)length + (pos - a->unk_34)) % (unsigned long)length;
    }
    count = a->unk_54;
    i = ((pos >> 16) + (count + offset)) % count;
    j = (i + 1) % count;
    value = b->unk_50[i] + a->unk_8 * (b->unk_50[j] - b->unk_50[i]);
    if (same)
        result = a->unk_50[i] + a->unk_8 * (a->unk_50[j] - a->unk_50[i]);
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
    struct Local { char pad[0x50]; void *field_50; } *obj = arg0;
    if (arg0 != 0) {
        if (&obj->field_50 != 0) {
            if (obj->field_50 != 0) {
                fn_80128670((s32)obj->field_50);
            }
            obj->field_50 = 0;
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
