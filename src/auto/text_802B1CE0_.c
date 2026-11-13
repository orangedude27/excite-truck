// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma push
#pragma cplusplus on
class ParticleConfig {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual const char *getText(const char *);
    virtual void v4();
    virtual void v5();
    virtual int getInt(const char *, int);
    virtual void v6();
    virtual float getFloat(const char *, float);
    virtual void v8();
    virtual int getBool(const char *, int);
};
#pragma pop
extern void *fn_801284F8(int, const char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern void fn_802B2C7C(void *);
extern void **fn_802B2384(void *, void **);
extern void *fn_802B23A8(void *, void *, void *);
extern int fn_802B2C44(void *);
extern char lbl_8034A2C4[];
extern char lbl_8034A2D8[];
extern char lbl_8055CDC8;
extern char lbl_8055CDD0;

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
extern float lbl_80564C00, lbl_80564C04, lbl_80564C08;
typedef struct { float x, y, z; } ParticleVec3;
extern float fn_80129DC4(float, float);
extern double cos(float);
extern double sin(float);
extern char lbl_8034A288[];
extern char lbl_8034A3F8[];
extern int lbl_8055CDC0;
extern void fn_802B8AE0(void *, void *);
extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void *, void (*)(void *), void *(*)(void *, int), int, int);
extern void fn_802B1FC0(void *);
extern void fn_802B1F64(void);
extern void *fn_802B1F68(void *, int);

int fn_8012C33C(void);
int fn_802CAC28(int, int);
extern void fn_80128668(void *);
void *fn_802B1CE0(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_802B1D38(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

int fn_802B1DA0(void *arg0) {
    int tag = *(int *)arg0;
    switch (tag) {
    case 0x53494E44:
        return ((int *)arg0)[8];
    case 0x4E444C32:
        return ((int *)arg0)[7] - 2;
    default:
        return 0x3E8;
    }
}

extern void *lbl_8055F9BC;
extern struct Unk802B2C98 lbl_804BE1FC;
void fn_802B21D4(void **);
void fn_802B2104(void **);
void fn_80128668(void *);
extern int lbl_8055CDB8;
int stricmp(const char *, const char *);
#pragma push
#pragma cplusplus on
extern "C" int fn_802B1DE8(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&lbl_8055CDB8, ((Obj *)arg0)->getName()) == 0;
}

extern "C" void fn_802B1E28(void) {
    typedef struct Pool {
        void *data;
        void *nodes;
        volatile int used;
        volatile int capacity;
        void *storage;
    } Pool;
    typedef void *(*AllocArray)(void *, void (*)(void *), void *(*)(void *, int), int, int);
    Pool *pool;
    void *storage;
    void *nodes;
    void *data;
    void *entry;
    int count;
    int size;
    int offset;
    int i;
    int index;
    fn_802B8AE0(lbl_8034A288 + 0xC, &lbl_8055F9B4);
    fn_802B8AE0(lbl_8034A288 + 0x18, &lbl_8055F9B0);
    pool = (Pool *)fn_801284F8(0x14, lbl_8034A288 + 0x28);
    if (pool != 0) {
        storage = fn_8012850C(0x610, (const char *)&lbl_8055CDC0);
        nodes = ((AllocArray)fn_8002F37C)(storage, fn_802B1FC0, fn_802B1F68, 0x10, 0x60);
        pool->nodes = nodes;
        pool->capacity = 0x60;
        pool->used = 0;
        pool->storage = nodes;
        count = pool->capacity;
        size = count << 6;
        storage = fn_8012850C(size * 0x14 + 0x10, lbl_8034A3F8);
        data = ((AllocArray)fn_8002F37C)(storage, (void (*)(void *))fn_802B1F64, (void *(*)(void *, int))0, 0x14, size);
        pool->data = data;
        i = 0;
        offset = 0;
        do {
            index = pool->used;
            i++;
            nodes = pool->nodes;
            data = pool->data;
            pool->used = index + 1;
            entry = (char *)nodes + index * 0x10;
            *(void **)entry = (char *)data + offset;
            offset += 0x500;
            *(int *)((char *)entry + 8) = 0x40;
            *(int *)((char *)entry + 4) = 0;
        } while (i < pool->capacity);
        pool->used = 0;
    }
    lbl_8055F9BC = pool;
}

#pragma cplusplus reset
#pragma pop
void fn_802B1F64(void) {
}

void *fn_802B1F68(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B1FC0(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_common_subs off
void fn_802B1FD4(void) {
    int i;
    void *table;
    int zero = 0;
    void *r27;
    int j;
    void *r25;
    int k;
    void *r23;
    int off_i;
    int off_j;
    int off_k;
    fn_802B2104(&lbl_8055F9BC);
    table = &lbl_804BE1FC;
    i = 0;
    off_i = 0;
    for (; i < *(int *)((char *)table + 4); off_i += 4, i++) {
        r27 = *(void **)(*(char **)&lbl_804BE1FC + off_i);
        if (r27 != 0) {
            for (j = 0, off_j = 0; j < *(int *)((char *)r27 + 4); off_j += 4, j++) {
                r25 = *(void **)(*(char **)r27 + off_j);
                if (r25 != 0) {
                    for (k = 0, off_k = 0; k < *(int *)((char *)r25 + 0x40c); off_k += 4, k++) {
                        r23 = *(void **)(*(char **)((char *)r25 + 0x408) + off_k);
                        if (r23 != 0) {
                            fn_802B21D4((void **)((char *)r23 + 0xc));
                            fn_80128668(r23);
                        }
                    }
                    *(int *)((char *)r25 + 0x40c) = zero;
                    if ((char *)r25 + 0x408 != 0) {
                        if ((char *)r25 + 0x408 != 0) {
                            *(int *)((char *)r25 + 0x408) = zero;
                            *(int *)((char *)r25 + 0x40c) = zero;
                            *(int *)((char *)r25 + 0x410) = zero;
                        }
                    }
                    fn_80128668(r25);
                }
            }
            *(int *)((char *)r27 + 4) = zero;
            if (r27 != 0) {
                if (r27 != 0) {
                    *(int *)r27 = zero;
                    *((int *)r27 + 1) = zero;
                    *((int *)r27 + 2) = zero;
                }
            }
            fn_80128668(r27);
        }
    }
    *(int *)((char *)table + 4) = zero;
}
#pragma pop

void fn_80128670(void *);
void fn_802B218C(void *);
void fn_8002F6AC(int, void (*)(void));
void *fn_802B1F68(void *, int);
void fn_80128668(void *);
void fn_802B2104(void **arg0);
void fn_802CAC54(int);
void fn_802C6C20(void *);
int fn_80129D90(int, int, int);

#pragma push
#pragma opt_common_subs off
void fn_802B2104(void **objectSlot) {
    /* Destroy the object stored in *objectSlot and clear the slot. Frees the
     * object's owned buffer, runs the element destructor over its pool, clears
     * the object's bookkeeping fields, then deletes the object. */
    void *object = *objectSlot;
    if (object != 0) {
        if (object != 0) {
            fn_802B218C(object);
            if ((char *)object + 4 != 0) {
                fn_8002F6AC(((int *)object)[4], (void (*)(void))fn_802B1F68);
                if ((char *)object + 4 != 0) {
                    ((int *)object)[1] = 0;
                    ((int *)object)[2] = 0;
                    ((int *)object)[3] = 0;
                }
            }
            fn_80128668(object);
        }
        *objectSlot = 0;
    }
}
#pragma pop
void fn_802B218C(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != 0) {
        if (buf != 0) {
            fn_80128670((char *)buf - 0x10);
        }
        *(void **)arg0 = 0;
    }
}

#pragma push
#pragma opt_common_subs off
void fn_802B21D4(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            int handle = ((int *)ptr)[2];
            if (handle != -2) {
                fn_802CAC54(handle);
                ((int *)ptr)[2] = -2;
            }
            {
                void *resource = *(void **)ptr;
                if (resource != 0) {
                    fn_802C6C20(resource);
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma opt_common_subs off
extern "C" void fn_802B224C(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void *v3(const char *);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual int v21(const char *);
    };
    char name[16];
    void *object;
    int index;
    void *child;
    void *item;
    unsigned int count;
    void **items;
    Obj *self = (Obj *)arg0;
    count = *(int *)((char *)&lbl_804BE1FC + 4);
    if ((int)(count + 1) > *(int *)((char *)&lbl_804BE1FC + 8))
        return;
    object = fn_801284F8(0x28, lbl_8034A2C4);
    if (object != 0) {
        fn_802B2C7C(object);
        index = 1;
        do {
            fn_801345D8(name, 0x10, (const char *)&lbl_8055CDC8, index);
            if (((int (*)(void *, void *))fn_802B2C44)(self, name) == 0)
                break;
            child = fn_801284F8(0x454, lbl_8034A2D8);
            if (child != 0) {
                child = fn_802B23A8(child, (void *)self->v21(name), (void *)(index - 1));
            }
            item = child;
            fn_802B2384(object, &item);
            index++;
        } while (1);
        *(void **)((char *)object + 0x24) = self->v3((const char *)&lbl_8055CDD0);
    }
    count = *(int *)((char *)&lbl_804BE1FC + 4);
    items = *(void ***)&lbl_804BE1FC;
    *(int *)((char *)&lbl_804BE1FC + 4) = count + 1;
    items[count] = object;
}

int *fn_802B2384(int *arg0, int *arg1) {
    unsigned long count = arg0[1];
    int *base = (int *)arg0[0];
    int val = *arg1;
    int *entry;
    arg0[1] = count + 1;
    entry = base + count;
    *entry = val;
    return entry;
}

#pragma pop

extern char lbl_8034A2E8[];
extern char lbl_8055CDD8;
extern void *fn_801284F8(int, const char *);
extern void fn_802B2504(int *, int);
extern void *fn_802B2958(void *, void *);
extern void fn_802B2934(void *, void **);
extern void fn_802B257C(void *);
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" void *fn_802B23A8(void *arg0, void *arg1, void *arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual int v10(const char *, int);
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void *v22(int);
    };

    int j;
    void *item;
    void *alloc;
    void *sp8;
    int val = 0;
    char *p = (char *)arg0;
    int i = 16;

    *(int *)((char *)arg0 + 0x40C) = 0;
    *(int *)((char *)arg0 + 0x410) = i;
    *(void **)((char *)arg0 + 0x408) = (char *)arg0 + 0x414;
    *(char *)((char *)arg0 + 4) = 0;
    *(char *)((char *)arg0 + 5) = 0;

    do {
        *(int *)(p + 8) = val++;
        *(int *)(p + 0xC) = val++;
        *(int *)(p + 0x10) = val++;
        *(int *)(p + 0x14) = val++;
        *(int *)(p + 0x18) = val++;
        *(int *)(p + 0x1C) = val++;
        *(int *)(p + 0x20) = val++;
        *(int *)(p + 0x24) = val++;
        p += 0x20;
    } while (--i);

    fn_802B2504((int *)((char *)arg0 + 8), 0x80);
    *(char *)((char *)arg0 + 5) = ((Obj *)arg1)->v10(&lbl_8055CDD8, 1);
    *(char *)((char *)arg0 + 4) = *(char *)((char *)arg0 + 5);

    for (j = 0; (item = ((Obj *)arg1)->v22(j)) != 0; j++) {
        if (fn_802B1DE8(item) != 0) {
            alloc = fn_801284F8(0x2A8, lbl_8034A2E8);
            if (alloc != 0) {
                sp8 = fn_802B2958(alloc, item);
                fn_802B2934((char *)arg0 + 0x408, &sp8);
            }
        }
    }

    fn_802B257C(arg0);
    *(void **)arg0 = arg2;
    return arg0;
}
#pragma cplusplus reset
#pragma pop

#pragma pop
int fn_80129D90(int, int, int);
#pragma push
#pragma use_lmw_stmw off
void fn_802B2504(int *dst, int count) {
    int limit;
    int offset;
    int i;
    i = 0;
    limit = count - 1;
    offset = 0;
    while (i < limit) {
        int j = fn_80129D90(0, i + 1, count);
        int tmp = dst[offset / 4];
        dst[offset / 4] = dst[j];
        dst[j] = tmp;
        i++;
        offset += 4;
    }
}
#pragma pop
void fn_802B28BC(int *, int);
void *memset(void *, int, unsigned int);
void fn_802B257C(void *arg0) {
    int count;
    int total = 0;
    int i = 0;
    count = *(int *)((char *)arg0 + 0x40C);
    while (i < count) {
        int *entry = (int *)((char *)*(int *)((char *)arg0 + 0x408) + i * 0x20);
        total += *(int *)entry[0];
        total += *(int *)entry[1];
        total += *(int *)entry[2];
        total += *(int *)entry[3];
        total += *(int *)entry[4];
        total += *(int *)entry[5];
        total += *(int *)entry[6];
        total += *(int *)entry[7];
        i++;
    }
    {
        int index = 0;
        while (total > 0x80) {
            int *item = (int *)((int *)*(int **)((char *)arg0 + 0x408))[index];
            if (*item > 0) { (*item)--; total--; }
            index++;
            if (index >= count) index = 0;
        }
    }
    {
        int *out = (int *)((char *)arg0 + 0x208);
        memset(out, 0, 0x200);
    }
    if (*(unsigned char *)((char *)arg0 + 4) == 0) fn_802B28BC((int *)((char *)arg0 + 0x208), 0x80);
}

#pragma push
#pragma use_lmw_stmw off
void fn_802B28BC(int *dst, int count) {
    int limit;
    int offset;
    int i;
    i = 0;
    limit = count - 1;
    offset = 0;
    while (i < limit) {
        int j = fn_80129D90(0, i + 1, count);
        int tmp = dst[offset / 4];
        dst[offset / 4] = dst[j];
        dst[j] = tmp;
        i++;
        offset += 4;
    }
}

extern void fn_802B2C34(void (*)(void *), void *);
extern char lbl_8055CDE0[8], lbl_8055CDE8[4], lbl_8055CDEC[4];
extern void fn_802C6B44(void *);
extern int fn_802B110C(void *, int);
extern int fn_802C9C24(void *);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_802B2958(void *arg0, void *arg1) {
    char *base = lbl_8034A288;
    char *obj = (char *)arg0;
    char *p = (char *)fn_801284F8(12, base + 0x70);
    const char *name;
    void *item, *child;
    int key, value, valid;
    float *entry;
    float one, zero, radius, sn, c, angle;
    unsigned int i;
    if (p != 0) {
        name = ((ParticleConfig *)arg1)->getText(lbl_8055CDE0);
        *(int *)(p + 8) = -2;
        if (stricmp(name, lbl_8055CDE8) == 0) {
            *(void **)p = 0;
        } else {
            item = ((void *(*)(void *, void *))fn_802B2C34)((void *)fn_802C6B44, (void *)name);
            *(void **)p = item;
            if (item != 0) {
                child = *(void **)((char *)item + 4);
                key = fn_802C9C24(child);
                value = *(int *)((char *)child + 12);
                valid = 0;
                if (value != 0) {
                    *(int *)(p + 8) = ((int (*)(void *, int))fn_802B110C)((void *)fn_802B1D38, key);
                    if (*(int *)(p + 8) == -2)
                        fn_802E317C(base + 0x80, key);
                    *(int *)(p + 4) = value;
                    valid = 1;
                }
                if (!valid) fn_802E317C(base + 0xA0, name);
            } else {
                fn_802E317C(base + 0xE4, name);
            }
        }
    }
    *(void **)(obj + 12) = p;
    *(int *)(obj + 0x14) = 0;
    *(int *)(obj + 0x10) = 0;
    *(int *)obj = ((ParticleConfig *)arg1)->getInt(lbl_8055CDEC, 1);
    *(const char **)(obj + 0x2A4) = ((ParticleConfig *)arg1)->getText(lbl_8055CDE0);
    *(float *)(obj + 8) = ((ParticleConfig *)arg1)->getFloat(base + 0x104, lbl_80564C00);
    *(float *)(obj + 0x298) = ((ParticleConfig *)arg1)->getFloat(base + 0x110, lbl_80564C04);
    *(float *)(obj + 0x29C) = ((ParticleConfig *)arg1)->getFloat(base + 0x11C, lbl_80564C04);
    *(char *)(obj + 4) = ((ParticleConfig *)arg1)->getBool(base + 0x128, 0);
    entry = (float *)(obj + 0x18);
    zero = lbl_80564C00;
    one = lbl_80564C04;
    for (i = 0; i < 16; i++, entry += 10) {
        entry[9] = ((float (*)(int, float, float))fn_80129DC4)(0, *(float *)(obj + 0x298), *(float *)(obj + 0x29C));
        angle = ((float (*)(int, float, float))fn_80129DC4)(0, lbl_80564C00, lbl_80564C08);
        c = (float)cos(angle);
        sn = (float)sin(angle);
        radius = entry[9];
        entry[0] = c * radius;
        entry[1] = zero * radius;
        entry[2] = -sn * radius;
        radius = entry[9];
        entry[3] = zero * radius;
        entry[4] = one * radius;
        entry[5] = zero * radius;
        radius = entry[9];
        entry[6] = sn * radius;
        entry[7] = zero * radius;
        entry[8] = c * radius;
    }
    *(char *)(obj + 0x2A0) = 0;
    return obj;
}
#pragma pop

#pragma scheduling invalid_target
void fn_802B2C34(void (*fn)(void *), void *arg) {
    fn(arg);
}
#pragma scheduling invalid_target
void fn_802B2D94(int *arg0) {
    int *object = arg0;
    int i;
    lbl_8055F9B4 = 0;
    lbl_8055F9B0 = 0;
    i = 0;
    goto check;
loop:
    fn_802B2E08(*fn_802B320C(object, i));
    i++;
check:
    if (i < fn_802B2E00(object)) {
        goto loop;
    }
}
#pragma scheduling on
#pragma push
#pragma dont_inline on
int fn_802B2E00(void *arg0) {
    return ((int *)arg0)[1];
}
#pragma pop

extern double cos(float);
extern double sin(float);
extern double fn_8002EFB4(float, double);
extern float fn_80129DC4(float, float);
extern float fn_801E7E18(void);
extern void fn_801F1C24(float *);
extern void fn_802C28C0(void);
extern void fn_802C8BD0(void);
extern void fn_802C8D74(void);
extern void fn_802DC71C(int, int);
extern void fn_802DC8B4(void);
extern void fn_802DCAE4(int, float *, void *, void *, float);
extern float lbl_80564C00, lbl_80564C04, lbl_80564C08;
extern float lbl_80564C0C, lbl_80564C10, lbl_80564C20;
extern double lbl_80564C18, lbl_80564C28;
#pragma push
#pragma processor 750
int fn_802B2E08(int arg0) {
    char *base, *obj, *transform;
    register float *entry;
    char *head;
    float stack[24];
    double conversion;
    float scaleX, scaleY, scaleZ, normal, vertical;
    float angle, cosine, sine, radial, radius, c, x, x2, yz, x3;
    float product0, product1, product2;
    float phase, phase2, scale;
    register int arrayOffset, j, index;
    int zero, eight, row, byteOffset, n;
    unsigned char *data, *record;
    unsigned short selector;

    base = (char *)arg0;
    conversion = lbl_80564C28;
    scaleX = lbl_80564C0C;
    index = 0;
    scaleY = lbl_80564C10;
    scaleZ = lbl_80564C20;
    arrayOffset = 0;
    normal = lbl_80564C00;
    vertical = lbl_80564C04;
    zero = 0;
    eight = 8;
    goto outer_check;

outer_body:
    obj = *(char **)(*(char **)(base + 0x408) + arrayOffset);
    head = *(char **)(obj + 0x10);
    if (head != 0) {
        if (*(unsigned char *)(obj + 0x2A0) != 0) {
            entry = (float *)(obj + 0x18);
            radial = normal;
            j = 0;
            do {
                radius = ((float (*)(int, float, float))fn_80129DC4)(
                    0, *(float *)(obj + 0x298), *(float *)(obj + 0x29C));
                entry[9] = radius;
                angle = ((float (*)(int, float, float))fn_80129DC4)(
                    0, lbl_80564C00, lbl_80564C08);
                cosine = (float)cos(angle);
                sine = (float)sin(angle);
                x = entry[9];
                c = cosine;
                j++;
                product1 = radial * x;
                product0 = c * x;
                product2 = -sine * x;
                entry[0] = product0;
                entry[1] = product1;
                entry[2] = product2;
                x2 = entry[9];
                yz = radial * x2;
                entry[3] = yz;
                entry[4] = vertical * x2;
                entry[5] = yz;
                x3 = entry[9];
                entry[6] = sine * x3;
                entry[7] = radial * x3;
                entry[8] = c * x3;
                entry += 10;
            } while ((unsigned int)j < 16u);
            *(unsigned char *)(obj + 0x2A0) = (unsigned char)zero;
        }

        if (*(unsigned char *)(obj + 4) != 0) {
            fn_801F1C24(stack);
            entry = (float *)(obj + 0x18);
            {
                volatile float *vEntry = (volatile float *)entry;
                for (j = 0; j < eight; j++) {
                    scale = vEntry[9];
                    entry[0] = stack[0] * scale;
                    entry[1] = stack[1] * scale;
                    entry[2] = stack[2] * scale;
                    scale = vEntry[9];
                    entry[3] = stack[3] * scale;
                    entry[4] = stack[4] * scale;
                    entry[5] = stack[5] * scale;
                    scale = vEntry[9];
                    entry[6] = stack[6] * scale;
                    entry[7] = stack[7] * scale;
                    entry[8] = stack[8] * scale;
                    scale = vEntry[19];
                    entry[10] = stack[0] * scale;
                    entry[11] = stack[1] * scale;
                    entry[12] = stack[2] * scale;
                    scale = vEntry[19];
                    entry[13] = stack[3] * scale;
                    entry[14] = stack[4] * scale;
                    entry[15] = stack[5] * scale;
                    scale = vEntry[19];
                    entry[16] = stack[6] * scale;
                    entry[17] = stack[7] * scale;
                    entry[18] = stack[8] * scale;
                    entry += 20;
                    vEntry = (volatile float *)entry;
                }
            }
        } else if (*(float *)(obj + 8) > normal) {
            phase = fn_801E7E18();
            phase2 = scaleZ * phase;
            entry = (float *)(obj + 0x18);
            j = 0;
            do {
                angle = (float)fn_8002EFB4(
                    (scaleX * (float)j) / scaleY + phase, lbl_80564C18);
                sine = (float)sin(angle);
                entry[3] = *(float *)(obj + 8) * sine;
                angle = (float)fn_8002EFB4(
                    (scaleX * (float)j) / scaleY + phase2, lbl_80564C18);
                cosine = (float)cos(angle);
                j++;
                entry[5] = *(float *)(obj + 8) * cosine;
                entry += 10;
            } while (j < 16);
        }

        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC71C(*(int *)(*(char **)(obj + 0xC) + 4),
                    *(int *)(*(char **)(obj + 0xC) + 8));
        do {
            n = *(int *)(head + 4);
            row = 0;
            byteOffset = 0;
            while (row < n) {
                data = *(unsigned char **)head;
                record = data + byteOffset;
                stack[21] = *(float *)(record + 4);
                stack[22] = *(float *)(record + 8);
                stack[23] = *(float *)(record + 0xC);
                selector = *(unsigned short *)record;
                transform = obj + ((selector & 0xF) * 0x28);
                ((ParticleVec3 *)(stack+12))[0] = ((ParticleVec3 *)(transform+0x18))[0];
                ((ParticleVec3 *)(stack+12))[1] = ((ParticleVec3 *)(transform+0x18))[1];
                ((ParticleVec3 *)(stack+12))[2] = ((ParticleVec3 *)(transform+0x18))[2];
                fn_802DCAE4(*(int *)(*(char **)(obj + 0xC) + 4), stack + 12, transform,
                            record, *(float *)(record + 0x10));
                byteOffset += 0x14;
                row++;
            }
            head = *(char **)(head + 0xC);
        } while (head != 0);
        fn_802DC8B4();
        fn_802C8D74();
    }
    arrayOffset += 4;
    index++;
outer_check:
    if (index < *(int *)(base + 0x40C))
        goto outer_body;
}
#pragma pop
#pragma push
#pragma dont_inline on
int *fn_802B320C(int *arg0, int arg1) {
    return (int *)((char *)*arg0 + arg1 * 4);
}
#pragma pop

extern char lbl_8034A3BC[];
extern void fn_802E30C8(const char *, ...);
void fn_802B321C(int *param_1, int *param_2, int *param_3, int param_4)
{
    int item;

    if (param_4 >= 0 && param_4 < param_3[1]) {
        item = *(int *)(*param_3 + param_4 * 4);
        if (param_1 != 0) {
            int i = 0;
            int offset = 0;
            do {
                int count;
                int *entry;
                i++;
                count = param_1[1];
                entry = *(int **)(*(int *)(item + 0x408) + offset);
                offset += 4;
                param_1[1] = count + 1;
                *(int *)((char *)param_1[0] + count * 0xC) =
                    *(int *)((char *)entry + 0x2A4);
                *(int *)((char *)param_1[0] + count * 0xC + 4) = (int)entry;
                *(int *)((char *)param_1[0] + count * 0xC + 8) =
                    (int)((char *)entry + 0x298);
            } while (i < *(int *)(item + 0x40C) &&
                     param_1[1] + 1 <= param_1[2]);
        }
        if (param_2 != 0)
            *param_2 = item + 4;
        return;
    }
    fn_802E30C8(lbl_8034A3BC, param_4, 0, param_3[1]);
}

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
int fn_802B3340(int);
void fn_802B32E0(int *arg0) {
    int *object = arg0;
    int i = 0;
    goto check;
loop:
    fn_802B3340(*fn_802B320C(object, i));
    i++;
check:
    if (i < fn_802B2E00(object)) {
        goto loop;
    }
}

void *fn_802B3DA4(void *arg0, int arg1, int arg2) {
    void *result = 0;
    if (arg2 >= 0 && arg2 < ((int *)arg0)[1]) {
        void *items = *(void **)arg0;
        void *entry = (char *)((void **)items)[arg2] + ((arg1 & 0x7F) * 4);
        void *obj = *(void **)((char *)entry + 0x208);
        result = 0;
        if (obj != 0) {
            void *inner = *(void **)((char *)obj + 0xC);
            result = 0;
            if (*(int *)inner != 0) {
                result = (char *)obj + 0x10;
            }
        }
    }
    return result;
}

#pragma push
#pragma scheduling invalid_target
void fn_802B3E00(void *arg0, void *arg1, short arg2, float farg0) {
    extern int lbl_8055F9B8;
    extern void *lbl_8055F9BC;
    typedef struct Entry802B3E00 {
        short value; unsigned short padding; float x; float y; float z; float weight;
    } Entry802B3E00;
    typedef struct Node802B3E00 {
        void *data; volatile int count; int capacity; struct Node802B3E00 *next;
    } Node802B3E00;
    typedef struct Queue802B3E00 { Node802B3E00 *head; Node802B3E00 *tail; } Queue802B3E00;
    typedef struct Pool802B3E00 { void *unknown0; Node802B3E00 *nodes; volatile int used; int capacity; } Pool802B3E00;
    Queue802B3E00 *queue = (Queue802B3E00 *)arg0;
    Node802B3E00 *tail = queue->tail;
    Pool802B3E00 *pool = (Pool802B3E00 *)lbl_8055F9BC;
    Entry802B3E00 *out = 0;
    int index; void *data; Node802B3E00 *node;
    if (tail == 0 || tail->count + 1 > tail->capacity) {
        Node802B3E00 *newNode = 0;
        if (pool->used + 1 <= pool->capacity) {
            newNode = (Node802B3E00 *)((char *)pool->nodes + pool->used++ * 0x10);
            newNode->count = 0; newNode->next = 0;
        }
        if (newNode != 0) {
            if (queue->head == 0) queue->head = newNode;
            { Node802B3E00 *prev = queue->tail; if (prev != 0) prev->next = newNode; }
            queue->tail = newNode; newNode->next = 0;
            node = queue->tail; index = node->count; data = node->data;
            out = (Entry802B3E00 *)((char *)data + index * 0x14);
            node->count = index + 1;
        }
    } else {
        index = tail->count; data = tail->data;
        out = (Entry802B3E00 *)((char *)data + index * 0x14);
        tail->count = index + 1;
    }
    if (out != 0) {
        float x = ((float *)arg1)[0]; float y = ((float *)arg1)[1];
        out->x = x;
        { float z = ((float *)arg1)[2]; out->y = y; out->z = z; }
        out->value = arg2; out->weight = farg0;
    } else lbl_8055F9B8 += 1;
}
#pragma pop
int fn_802B3F0C(void *arg0) {
    return ((int *)arg0)[1];
}

typedef struct {
    void *m0;
    void *m4;
    void *m8;
    void *mC;
    void *m10;
    void *m14;
    void *m18;
    void *m1C;
    void *m20;
    void *m24;
    void *m28;
    void *m2C;
    void *m30;
    void *m34;
    void *m38;
    void *m3C;
    void *m40;
    void *m44;
    void *m48;
    void *m4C;
    void *m50;
    void *m54;
    void (*m58)(void);
    int (*m5C)(void);
} Unk802B2C44;

typedef struct Unk802B2C98 {
    void *m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
} Unk802B2C98;
extern Unk802B2C98 lbl_804BE1FC;

extern int lbl_8055F9B8;
extern void *lbl_8055F9BC;

#pragma push
#pragma cplusplus on
extern "C" int fn_802B2C44(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual int v21();
    };
    return ((Obj *)arg0)->v21() != 0;
}
#pragma cplusplus reset
#pragma pop
#pragma scheduling invalid_target
void fn_802B2C7C(void *arg0) {
    *(int *)arg0 = (int)((char *)arg0 + 0xC);
    *(int *)((char *)arg0 + 8) = 6;
    *(int *)((char *)arg0 + 4) = 0;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
#pragma scheduling invalid_target
/* Look up an entry by name in lbl_804BE1FC and return it, or 0 if not found. */
int fn_802B2C98(char *name) {
    void *table;
    int offset;
    int result;
    int i;

    table = &lbl_804BE1FC;
    result = 0;
    i = 0;
    offset = 0;
    for (; i < *(int *)((char *)table + 4); offset += 4, i++) {
        if (stricmp(name, *(char **)(*(char **)(*(char **)&lbl_804BE1FC + offset) + 0x24)) == 0) {
            result = (int)((void **)*(char **)&lbl_804BE1FC)[i];
            break;
        }
    }
    return result;
}
#pragma scheduling on
#pragma pop
void fn_802B2D24(void *arg0) {
    int i = 0;
    int j;
    int index = 0;
    int innerIndex;
    while (i < ((int *)arg0)[1]) {
        void *cur = *(void **)((char *)*(void **)arg0 + index);
        ((int *)lbl_8055F9BC)[2] = 0;
        j = 0;
        innerIndex = 0;
        while (j < ((int *)cur)[0x103]) {
            void *entry = *(void **)((char *)*(void **)((char *)cur + 0x408) + innerIndex);
            ((int *)entry)[5] = 0;
            ((int *)entry)[4] = 0;
            j++;
            innerIndex += 4;
        }
        index += 4;
        i++;
    }
    lbl_8055F9B8 = 0;
}
