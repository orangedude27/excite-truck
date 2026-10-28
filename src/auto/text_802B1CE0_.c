// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void *fn_801284F8(int, const char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern void fn_802B2C7C(void *);
extern void fn_802B2384(void *, void **);
extern void *fn_802B23A8(void *, void *, void *);
extern int fn_802B2C44(void *);
extern char lbl_8034A2C4[];
extern char lbl_8034A2D8[];
extern const char lbl_8055CDC8[];
extern const char lbl_8055CDD0[];

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
extern char lbl_8034A288[];
extern char lbl_8034A3F8[];
extern const char lbl_8055CDC0[];
extern void fn_802B8AE0(void *, void *);
extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void *, void *, int, int);
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
        int used;
        int capacity;
        void *storage;
    } Pool;
    Pool *pool;
    void *nodeStorage;
    void *nodes;
    void *data;
    void *entry;
    int i;
    int offset;
    int index;
    fn_802B8AE0(lbl_8034A288 + 0xC, &lbl_8055F9B4);
    fn_802B8AE0(lbl_8034A288 + 0x18, &lbl_8055F9B0);
    pool = (Pool *)fn_801284F8(0x14, lbl_8034A288 + 0x28);
    if (pool != 0) {
        nodeStorage = fn_8012850C(0x610, lbl_8055CDC0);
        nodes = fn_8002F37C(nodeStorage, fn_802B1FC0, 0x10, 0x60);
        pool->nodes = nodes;
        pool->capacity = 0x60;
        pool->used = 0;
        pool->storage = nodeStorage;
        index = 0x60 << 6;
        nodeStorage = fn_8012850C(index * 0x14 + 0x10, lbl_8034A3F8);
        data = fn_8002F37C(nodeStorage, fn_802B1F64, 0x14, index);
        pool->data = data;
        i = 0;
        offset = 0;
        do {
            index = pool->used;
            i++;
            data = pool->data;
            nodes = pool->nodes;
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
    void *table;
    int i;
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
                    *(int *)((char *)r25 + 0x40c) = 0;
                    if ((char *)r25 + 0x408 != 0) {
                        if ((char *)r25 + 0x408 != 0) {
                            *(int *)((char *)r25 + 0x408) = 0;
                            *(int *)((char *)r25 + 0x40c) = 0;
                            *(int *)((char *)r25 + 0x410) = 0;
                        }
                    }
                    fn_80128668(r25);
                }
            }
            *(int *)((char *)r27 + 4) = 0;
            if (r27 != 0) {
                if (r27 != 0) {
                    *(int *)r27 = 0;
                    *((int *)r27 + 1) = 0;
                    *((int *)r27 + 2) = 0;
                }
            }
            fn_80128668(r27);
        }
    }
    *(int *)((char *)table + 4) = 0;
}
#pragma pop

void fn_80128670(void *);
void fn_802B218C(void *);
void fn_8002F6AC(int, void (*)(void));
void *fn_802B1F68(void *, int);
void fn_80128668(void *);
void fn_802B2104(void **arg0);
void fn_802CAC54(void);
void fn_802C6C20(void);
int fn_80129D90(int, int, int);

#pragma push
#pragma opt_common_subs off
void fn_802B2104(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802B218C(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], (void (*)(void))fn_802B1F68);
                if ((char *)ptr + 4 != 0) {
                    ((int *)ptr)[1] = 0;
                    ((int *)ptr)[2] = 0;
                    ((int *)ptr)[3] = 0;
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
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
            if (((int *)ptr)[2] == -2) {
            } else {
                fn_802CAC54();
                ((int *)ptr)[2] = -2;
            }
            if (((int *)ptr)[0] == 0) {
            } else {
                fn_802C6C20();
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_802B224C(void *arg0) {
    char name[16];
    void *object;
    void *child;
    int index;
    int count;
    void **items;
    int value;
    void *(*get_value)(void *, const char *);

    count = *(int *)((char *)&lbl_804BE1FC + 4);
    if (count + 1 > *(int *)((char *)&lbl_804BE1FC + 8))
        return;

    object = fn_801284F8(0x28, lbl_8034A2C4);
    if (object != 0) {
        fn_802B2C7C(object);
        index = 1;
        do {
            fn_801345D8(name, 0x10, (const char *)&lbl_8055CDC8, index);
            if (((int (*)(void *, void *))fn_802B2C44)(arg0, name) == 0)
                break;
            child = fn_801284F8(0x454, lbl_8034A2D8);
            if (child != 0) {
                value = (*(int (**)(void *, void *))((char *)*(void **)arg0 + 0x5C))(arg0, name);
                child = fn_802B23A8(child, (void *)value, (void *)(index - 1));
            }
            fn_802B2384(object, &child);
            index++;
        } while (1);
        get_value = (void *(*)(void *, const char *))((char *)*(void **)arg0 + 0x14);
        *(void **)((char *)object + 0x24) = get_value(arg0, lbl_8055CDD0);
    }

    items = *(void ***)&lbl_804BE1FC;
    count = *(int *)((char *)&lbl_804BE1FC + 4);
    *(int *)((char *)&lbl_804BE1FC + 4) = count + 1;
    items[count] = object;
}
#pragma pop

extern char lbl_8034A2E8[];
extern char lbl_8055CDD8;
extern void *fn_801284F8(int, const char *);
extern void fn_802B2504(int *, int);
extern void *fn_802B2958(void *);
extern void fn_802B2934(void *, void **);
extern void fn_802B257C(void *);
void *fn_802B23A8(void *arg0, void *arg1, void *arg2) {
    int i;
    void *result;
    void *item;
    int (*get_name)(void *, const char *, int);
    void *(*get_item)(void *, int);
    *(int *)((char *)arg0 + 0x40C) = 0;
    *(int *)((char *)arg0 + 0x410) = 0x10;
    *(void ***)((char *)arg0 + 0x408) = (void **)((char *)arg0 + 0x414);
    *(char *)((char *)arg0 + 4) = 0;
    *(char *)((char *)arg0 + 5) = 0;
    for (i = 0; i < 16; i++) {
        int *p = (int *)((char *)arg0 + 8 + i * 0x20);
        p[0] = i * 8;
        p[1] = i * 8 + 1;
        p[2] = i * 8 + 2;
        p[3] = i * 8 + 3;
        p[4] = i * 8 + 4;
        p[5] = i * 8 + 5;
        p[6] = i * 8 + 6;
        p[7] = i * 8 + 7;
    }
    fn_802B2504((int *)((char *)arg0 + 8), 0x80);
    get_name = *(int (**)(void *, const char *, int))(*(void ***)arg1 + 0x30/4);
    *(char *)((char *)arg0 + 5) = get_name(arg1, &lbl_8055CDD8, 1);
    *(char *)((char *)arg0 + 4) = *(char *)((char *)arg0 + 5);
    get_item = *(void *(**)(void *, int))(*(void ***)arg1 + 0x60/4);
    i = 0;
    while ((item = get_item(arg1, i)) != 0) {
        if (fn_802B1DE8(item) != 0) {
            result = fn_801284F8(0x2A8, lbl_8034A2E8);
            if (result != 0) {
                result = fn_802B2958(item);
                *(void **)((char *)arg0 + 8) = result;
                fn_802B2934((char *)arg0 + 0x408, (void **)((char *)arg0 + 8));
            }
        }
        i++;
    }
    fn_802B257C(arg0);
    *(void **)arg0 = arg2;
    return arg0;
}

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
    int count, i, total, index, *items, *item, *entry;
    int remaining, share, used, rem, slot, k;
    int *out;
    count = *(int *)((char *)arg0 + 0x40C);
    items = *(int **)((char *)arg0 + 0x408);
    total = 0;
    for (i = 0; i < count; i++) {
        entry = (int *)((char *)items + i * 0x20);
        total += *(int *)entry[0];
        total += *(int *)entry[1];
        total += *(int *)entry[2];
        total += *(int *)entry[3];
        total += *(int *)entry[4];
        total += *(int *)entry[5];
        total += *(int *)entry[6];
        total += *(int *)entry[7];
    }
    index = 0;
    while (total > 0x80) {
        item = (int *)items[index];
        if (*item > 0) { (*item)--; total--; }
        index++;
        if (index >= count) index = 0;
    }
    out = (int *)((char *)arg0 + 0x208);
    memset(out, 0, 0x200);
    remaining = 0x80 - total;
    slot = 0;
    for (i = 0; i < count; i++) {
        item = (int *)((char *)items[i]);
        share = (remaining * 2) / count;
        if (share > remaining) share = remaining;
        used = *item;
        rem = used % share;
        for (k = 0; k < rem; k++) out[slot++] = 0;
        remaining -= rem;
        for (k = 0; k < used; k++) out[slot++] = (int)item;
    }
    if (*(unsigned char *)((char *)arg0 + 4) == 0) fn_802B28BC(out, 0x80);
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
int fn_802B2E00(void *arg0) {
    return ((int *)arg0)[1];
}

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
#pragma scheduling invalid_target
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
            entry = (float *)(obj + 0x18);
            phase2 = scaleZ * phase;
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
            do {
                data = *(unsigned char **)head;
                record = data + byteOffset;
                stack[21] = *(float *)(record + 4);
                stack[22] = *(float *)(record + 8);
                stack[23] = *(float *)(record + 0xC);
                selector = *(unsigned short *)record;
                transform = obj + ((selector & 0xF) * 0x28);
                (*(unsigned int *)&stack[12]) = *(unsigned int *)(transform + 0x18);
                (*(unsigned int *)&stack[13]) = *(unsigned int *)(transform + 0x1C);
                (*(unsigned int *)&stack[14]) = *(unsigned int *)(transform + 0x20);
                (*(unsigned int *)&stack[15]) = *(unsigned int *)(transform + 0x24);
                (*(unsigned int *)&stack[16]) = *(unsigned int *)(transform + 0x28);
                (*(unsigned int *)&stack[17]) = *(unsigned int *)(transform + 0x2C);
                (*(unsigned int *)&stack[18]) = *(unsigned int *)(transform + 0x30);
                (*(unsigned int *)&stack[19]) = *(unsigned int *)(transform + 0x34);
                (*(unsigned int *)&stack[20]) = *(unsigned int *)(transform + 0x38);
                fn_802DCAE4(*(int *)(*(char **)(obj + 0xC) + 4), stack + 12, transform,
                            record, *(float *)(record + 0x10));
                byteOffset += 0x14;
                row++;
            } while (row < n);
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
#pragma scheduling on
int *fn_802B320C(int *arg0, int arg1) {
    return (int *)((char *)*arg0 + arg1 * 4);
}

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

int fn_802B2E00(void *);
int fn_802B2E08(int);
int *fn_802B320C(int *, int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
int fn_802B3340(int);
void fn_802B32E0(int *arg0) {
    int i = 0;
    do {
        fn_802B3340(*fn_802B320C(arg0, i));
        i++;
    } while (i < fn_802B2E00(arg0));
}

void *fn_802B3DA4(void *arg0, int arg1, int arg2) {
    void *result = 0;
    if (arg2 >= 0 && arg2 < ((int *)arg0)[1]) {
        void *items = *(void **)arg0;
        void *entry = (char *)((void **)items)[arg2] + ((arg1 & 0x7F) * 4);
        void *obj = *(void **)((char *)entry + 0x208);
        if (obj != 0 && *(int *)*(void **)((char *)obj + 0xC) != 0) {
            result = (char *)obj + 0x10;
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
        short value;
        unsigned short padding;
        float x;
        float y;
        float z;
        float weight;
    } Entry802B3E00;
    typedef struct Node802B3E00 {
        void *data;
        volatile int count;
        int capacity;
        struct Node802B3E00 *next;
    } Node802B3E00;
    typedef struct Queue802B3E00 {
        Node802B3E00 *head;
        Node802B3E00 *tail;
    } Queue802B3E00;
    typedef struct Pool802B3E00 {
        void *unknown0;
        Node802B3E00 *nodes;
        volatile int used;
        int capacity;
    } Pool802B3E00;
    Queue802B3E00 *queue = (Queue802B3E00 *)arg0;
    Node802B3E00 *tail = queue->tail;
    Node802B3E00 *node;
    Pool802B3E00 *pool = (Pool802B3E00 *)lbl_8055F9BC;
    Entry802B3E00 *out = 0;
    int index;
    void *data;

    if (tail == 0 || tail->count + 1 > tail->capacity) {
        Node802B3E00 *newNode = 0;
        if (pool->used + 1 <= pool->capacity) {
            newNode = (Node802B3E00 *)((char *)pool->nodes + pool->used++ * 0x10);
            newNode->count = 0;
            newNode->next = 0;
        }
        if (newNode != 0) {
            if (queue->head == 0) {
                queue->head = newNode;
            }
            {
                Node802B3E00 *prev = queue->tail;
                if (prev != 0) {
                    prev->next = newNode;
                }
            }
            queue->tail = newNode;
            newNode->next = 0;
            node = queue->tail;
            index = node->count;
            data = node->data;
            out = (Entry802B3E00 *)((char *)data + index * 0x14);
            node->count = index + 1;
        }
    } else {
        index = tail->count;
        data = tail->data;
        out = (Entry802B3E00 *)((char *)data + index * 0x14);
        tail->count = index + 1;
    }
    if (out != 0) {
        float x = ((float *)arg1)[0];
        float y = ((float *)arg1)[1];
        out->x = x;
        {
            float z = ((float *)arg1)[2];
            out->y = y;
            out->z = z;
        }
        out->value = arg2;
        out->weight = farg0;
    } else {
        lbl_8055F9B8 += 1;
    }
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

#pragma scheduling invalid_target
int fn_802B2C98(char *arg0) {
    Unk802B2C98 *base = &lbl_804BE1FC;
    int result;
    int i;
    result = 0;
    i = 0;
    while (i < base->m4) {
        if (stricmp(arg0, *(char **)((char *)((void **)lbl_804BE1FC.m0)[i] + 0x24)) == 0) {
            result = (int)((void **)lbl_804BE1FC.m0)[i];
            break;
        }
        i++;
    }
    return result;
}
#pragma scheduling on
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
