// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_802DAA18(void);

extern void *lbl_8055F9A0;
void fn_802B087C(void **arg0);
void fn_802AE64C(void *);
void fn_8002F6AC(int, void (*)(void));
void *fn_802B0808(void *, int);
void fn_80128668(void *);
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void **fn_802B59CC(void);
extern char lbl_8034A078[];
extern char lbl_8034A0B4[], lbl_8034A0C4[];
extern int lbl_8055F998, lbl_8055F99C;
void fn_802B8AE0(void *, void *);
void fn_802B0710(void);
int fn_802B0628(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802B0690(int *arg0) {
    int value = *arg0;
    if (value != -2) {
        fn_802CAC54(value);
        *arg0 = -2;
    }
}

void fn_802B06D4(void) {
    void **obj = fn_802B59CC();
    (*(void (***)(void *, void *, int))obj)[12](obj, lbl_8034A078, 0);
}

extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int);
extern void fn_802B0860(void *);
extern char lbl_8034A0A8[];
extern char lbl_8034A27C[];
extern char lbl_8055CD88[];
void fn_802B0710(void) {
    void *obj;
    int *fields;
    int i;
    int offset;
    int *entry;
    obj = fn_801284F8(0x14, lbl_8034A0A8);
    if (obj != 0) {
        fn_8012850C(0x550, lbl_8055CD88);
        fields = (int *)fn_8002F37C(fn_802B0860, fn_802B0808, 0x10, 0x54);
        ((int **)obj)[1] = fields;
        ((int *)obj)[3] = 0x54;
        ((int *)obj)[2] = 0;
        ((int **)obj)[4] = fields;
        ((void **)obj)[0] = fn_8012850C(0x15000, lbl_8034A27C);
        i = 0;
        offset = 0;
        while (i < ((int *)obj)[3]) {
            entry = (int *)((char *)((int *)obj)[1] + ((int *)obj)[2] * 0x10);
            ((int *)obj)[2] = ((int *)obj)[2] + 1;
            *entry = (int)((char *)((int *)obj)[0] + offset);
            offset += 0x400;
            entry[2] = 0x200;
            entry[1] = 0;
            i++;
        }
        ((int *)obj)[2] = 0;
    }
    lbl_8055F9A0 = obj;
}

void *fn_802B0808(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            ((int *)arg0)[0] = 0;
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B0860(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B0874(void) {
    fn_802B087C(&lbl_8055F9A0);
}

#pragma push
#pragma opt_common_subs off
void fn_802B087C(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802AE64C(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], (void (*)(void))fn_802B0808);
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
void fn_802B0904(void) {
    ((int *)lbl_8055F9A0)[2] = 0;
}

void fn_802B0914(void) {
    register void *first = lbl_8034A0B4;
    register void *second;
    fn_802B8AE0(first, &lbl_8055F998);
    second = lbl_8034A0C4;
    fn_802B8AE0(second, &lbl_8055F99C);
    fn_802B0710();
}

extern void *fn_802B0AC0(void *, int);
void fn_802B0954(int arg0) {
    extern void *lbl_804BE104;
    extern void fn_8002F634(void *, void *, int, int);
    extern void fn_802B0690(int *);
    extern void fn_802B0874(void);
    extern void fn_80128668(void *);
    int i = 0, outer_off = 0, outer = 0, row_off = 0, column = 0, column_off = 0;
    int *array;
    int outer_count;
    void *obj;
    fn_802B0874();
    array = *(int **)&lbl_804BE104;
    outer_count = *(int *)((char *)&lbl_804BE104 + 4);
    goto outer_check;
outer_loop:
    obj = *(void **)((char *)array + outer_off);
    if (obj != 0) {
        outer = 0; row_off = 0;
        goto row_check;
row_loop:
        {
            char *row = *(char **)((char *)obj + 0xC) + row_off;
            fn_802B0690((int *)(row + 0x7C));
            column = 0; column_off = 0;
            goto col_check;
col_loop:
            fn_802B0690((int *)(*(char **)(row + 4) + column_off));
            column_off += 0x10; ++column;
col_check:
            if (column < *(int *)(row + 8)) goto col_loop;
            *(int *)(row + 8) = 0;
            row_off += 0x80; ++outer;
row_check:
            if (outer < *(int *)((char *)obj + 0x10)) goto row_loop;
        }
        *(int *)((char *)obj + 0x10) = 0;
        if (*(int *)((char *)obj + 8) == *(int *)((char *)obj + 4))
            *(int *)((char *)obj + 8) = -2;
        fn_802B0690((int *)((char *)obj + 4));
        fn_802B0690((int *)((char *)obj + 8));
        if ((char *)obj + 0x324 != 0) {
            if ((char *)obj + 0x324 != 0) {
                *(int *)((char *)obj + 0x324) = 0;
                *(int *)((char *)obj + 0x328) = 0;
                *(int *)((char *)obj + 0x32C) = 0;
            }
        }
        if ((char *)obj + 0x318 != 0) {
            if ((char *)obj + 0x318 != 0) {
                *(int *)((char *)obj + 0x318) = 0;
                *(int *)((char *)obj + 0x31C) = 0;
                *(int *)((char *)obj + 0x320) = 0;
            }
        }
        if ((char *)obj + 0xC != 0) {
            fn_8002F634((char *)obj + 0x18, fn_802B0AC0, 0x80, 6);
            if ((char *)obj + 0xC != 0) {
                *(int *)((char *)obj + 0xC) = 0;
                *(int *)((char *)obj + 0x10) = 0;
                *(int *)((char *)obj + 0x14) = 0;
            }
        }
        fn_80128668(obj);
    }
    outer_off += 4; ++i;
outer_check:
    if (i < outer_count) goto outer_loop;
    *(int *)((char *)&lbl_804BE104 + 4) = 0;
}

#pragma opt_common_subs off
void *fn_802B0AC0(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 4 != 0) {
            if ((char *)arg0 + 4 != 0) {
                ((int *)arg0)[1] = 0;
                ((int *)arg0)[2] = 0;
                ((int *)arg0)[3] = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void *lbl_804BE104;
extern char lbl_8055F980;
char fn_802B05E4(void);
char fn_802B05EC(void);
void fn_802B0904(void);
void fn_802BAFA0(void);
int fn_802CFFA0(void);
int stricmp(const char *, const char *);
extern float lbl_80564BD0;
void fn_802BAFF8(int, void *);
typedef struct { float x, y, z; } Vec3_802B;
#pragma push
#pragma scheduling invalid_target
void fn_802B110C(void (*fn)(void *), void *arg) {
    fn(arg);
}
#pragma pop
void fn_802B111C(void *arg0) {
    ((int *)arg0)[1] = (int)((char *)arg0 + 0x10);
    ((int *)arg0)[3] = 6;
    ((int *)arg0)[2] = 0;
}

void *fn_802B1138(const char *name) {
    void *result = 0;
    int count = 0;
    int offset = 0;
    while (count < ((int *)lbl_804BE104)[1]) {
        void *entry = ((void **)lbl_804BE104)[offset / 4];
        if (stricmp(name, (const char *)entry + 0xa3c) == 0) {
            result = entry;
            break;
        }
        offset += 4;
        count += 1;
    }
    return result;
}

void fn_802B11BC(void *arg0) {
    int i;
    char found = 0;
    lbl_8055F99C = 0;
    lbl_8055F998 = 0;
    ((int *)arg0)[0x318 / 4] = fn_802CFFA0();
    ((int *)arg0)[0x320 / 4] = 0x3000;
    ((int *)arg0)[0x31c / 4] = 0;
    fn_802BAFA0();
    fn_802B0904();
    for (i = 0; i < 0xd; i++) {
        int *p = (int *)((char *)arg0 + 0x934 + i * 0x14);
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
    ((int *)arg0)[0xa38 / 4] = 0;
    ((int *)arg0)[0x328 / 4] = 0;
    if (((int *)arg0)[1] == -2 || fn_802B05E4() != 0 || fn_802B05EC() != 0) {
        found = 1;
    }
    ((char *)arg0)[1] = found;
}

int fn_802B127C(void *arg0, Vec3_802B *src) {
    int *self = (int *)arg0;
    int next;
    int i;
    float x, y, z;
    float *base, *dst;
    if (self == 0) return 0;
    next = self[0x31c / 4] + 1;
    if (next <= self[0x320 / 4]) {
        i = self[0x31c / 4];
        x = src->x;
        y = src->y;
        z = src->z;
        base = (float *)self[0x318 / 4];
        self[0x31c / 4] = i + 1;
        dst = (float *)((char *)base + i * 12);
        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    }
    return (unsigned short)(self[0x31c / 4] - 1);
}

int fn_802B12E0(void *arg0, void *arg1, void *arg2, int arg3) {
    int index, size, used, result = 0, next;
    int *entry, *pool, *list;
    void *slot, *node;
    if (arg0 == 0) return 0;
    if ((arg3 <= 4) || (((unsigned char *)arg0)[1] != 0)) index = ((int *)arg2)[2] & 0x3f;
    else index = 0;
    list = (int *)((char *)arg0 + index * 4);
    slot = (void *)list[0x934 / 4];
    pool = (int *)lbl_8055F9A0;
    if (slot == 0 || ((int *)slot)[1] + 0x18 > ((int *)slot)[2]) {
        node = 0;
        if (pool[2] + 1 <= pool[3]) {
            used = pool[2];
            pool[2] = used + 1;
            node = (char *)pool[1] + used * 0x10;
            ((int *)node)[1] = 0;
            ((int *)node)[3] = 0;
        }
        if (node != 0) {
            ((int *)node)[3] = list[0x934 / 4];
            list[0x934 / 4] = (int)node;
            entry = (int *)node;
            size = entry[1];
            entry[1] = size + 0x18;
            result = entry[0] + size * 2;
        }
    } else {
        entry = (int *)slot;
        size = entry[1];
        entry[1] = size + 0x18;
        result = entry[0] + size * 2;
    }
    if (result != 0) {
        *(int *)arg1 = result;
        *(short *)((char *)arg1 + 6) = 0x18;
    }
    next = (result == 0) ? 0 : 1;
    if (next != 0) ((int *)arg0)[0xA38 / 4] = (int)list;
    return next;
}

void fn_802B13F8(void *arg0, int arg1, void *arg2, int arg3, float farg0) {
    int *self = (int *)arg0;
    int *obj;
    int sp8;
    int flag;
    if (self == 0) {
        return;
    }
    flag = 0;
    sp8 = ((int *)arg2)[0];
    obj = *(int **)((char *)self[0xa38 / 4]);
    obj[1] = obj[1] - (0x18 - *(unsigned short *)((char *)arg2 + 4));
    self[0xa38 / 4] = 0;
    if (arg3 == 4) {
        if (farg0 < lbl_80564BD0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        if (self[0x328 / 4] + 1 <= self[0x32c / 4]) {
            int i = self[0x328 / 4];
            float f = lbl_80564BD0 - farg0;
            int *dst = (int *)((char *)self[0x324 / 4] + i * 8);
            self[0x328 / 4] = i + 1;
            ((float *)dst)[1] = f;
            dst[0] = sp8;
        }
    }
    fn_802BAFF8(arg1, &sp8);
}

extern float lbl_80564BB8, lbl_80564BD0, lbl_80564BD4, lbl_80564BD8;
extern float lbl_80564BDC, lbl_80564BE0, lbl_80564BE4, lbl_80564BE8;
extern double lbl_80564BF0;
extern float lbl_804BE190[];
extern unsigned short lbl_802FAAB0[];
extern void fn_802C28C0(void);
extern void fn_802C8BD0(void);
extern void fn_802C8D74(void);
extern void fn_802DC3C0(int);
extern void fn_802DC440(void);
extern void fn_802DC464();
extern float fn_801DCF48(int, float, float);
#pragma push
  #pragma ppc_psq_save off
    #pragma scheduling invalid_target
void fn_802B1758(void *arg0) {
    float setupA[3];
    float setupB[3];
    void *node;
    int cacheCount;
    void *cache;
    int state;
    int i;
    int offset;
    int sign;
    float radius;
    float *point;
    float z;
    float y;
    float x;
    unsigned short values[14];

    node = *(void **)((char *)arg0 + 0x934);
    if (node != 0 && *(int *)((char *)arg0 + 4) != -2) {
        state = *(int *)((char *)arg0 + 4);
        setupA[2] = lbl_80564BD0;
        setupA[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
        setupA[1] = lbl_80564BD8;
        fn_802DA704(1, setupA, 1);
        fn_802DAA18();
        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC3C0(state);

        cache = *(void **)((char *)arg0 + 0x318);
        cacheCount = *(int *)((char *)arg0 + 0x31C);
        node = *(void **)((char *)arg0 + 0x934);
        while (node != 0) {
            fn_802DC464(cache, cacheCount, *(void **)node, *(int *)((char *)node + 4));
            node = *(void **)((char *)node + 0xC);
        }
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)arg0 + 0x328)) {
            char *entry = (char *)*(void **)((char *)arg0 + 0x324) + offset;
            setupA[2] = *(float *)(entry + 4);
            fn_802DA704(1, setupA, 1);
            fn_802DAA18();
            node = *(void **)entry;
            fn_802DC464(cache, cacheCount, node, *(unsigned short *)node + 1);
            offset += 8;
            i++;
        }
        fn_802DC440();
        fn_802C8D74();
    }

    if (*(unsigned char *)arg0 != 0) {
        state = *(int *)((char *)arg0 + 8);
        if (state != -2) {
            if (state == *(int *)((char *)arg0 + 4))
                setupB[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
            else
                setupB[0] = lbl_80564BDC / (lbl_80564BD4 * lbl_80564BB8);
            setupB[1] = lbl_80564BD8;
            setupB[2] = lbl_80564BD0;
            fn_802DA704(1, setupB, 1);
            fn_802DAA18();
            fn_802C28C0();
            fn_802C8BD0();
            fn_802DC3C0(state);

            radius = lbl_80564BD4 * lbl_80564BB8 * lbl_80564BE4;
            radius = lbl_80564BE0 + radius;
            point = lbl_804BE190;
            for (i = 0; i < 4; i++) {
                sign = (i & 1) ? -1 : 1;
                x = (float)sign * radius;
                sign = (i & 2) ? -1 : 1;
                z = (float)sign * radius;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            radius = lbl_80564BE8 * lbl_80564BB8;
            point = lbl_804BE190 + 12;
            for (i = 4; i < 8; i++) {
                sign = (i & 1) ? -1 : 1;
                x = radius * (float)sign;
                sign = (i & 2) ? -1 : 1;
                z = radius * (float)sign;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            values[0] = lbl_802FAAB0[0];
            values[1] = lbl_802FAAB0[1];
            values[2] = lbl_802FAAB0[2];
            values[3] = lbl_802FAAB0[3];
            values[4] = lbl_802FAAB0[4];
            values[5] = lbl_802FAAB0[5];
            values[6] = lbl_802FAAB0[6];
            values[7] = lbl_802FAAB0[7];
            values[8] = lbl_802FAAB0[8];
            values[9] = lbl_802FAAB0[9];
            values[10] = lbl_802FAAB0[10];
            values[11] = lbl_802FAAB0[11];
            values[12] = lbl_802FAAB0[12];
            values[13] = lbl_802FAAB0[13];
            fn_802DC464(lbl_804BE190, 8, values, 0xE,
                lbl_802FAAB0[0x18 / 2], lbl_802FAAB0[0x16 / 2],
                lbl_802FAAB0[0x14 / 2], lbl_802FAAB0[0x12 / 2]);
            fn_802DC440();
            fn_802C8D74();
        }
    }
    *(int *)((char *)arg0 + 0x328) = 0;
}
#pragma pop
int fn_802B1AF0(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802B1AF8(int *arg0, int arg1) { return *arg0 + arg1 * 2; }

int fn_802B1B08(void *arg0) { return ((int *)arg0)[1]; }

int fn_802B1B10(int *arg0) { return *arg0; }

int fn_802B1B18(int *arg0) { return *arg0 == 0; }

int fn_802B1B28(int *arg0, int arg1) {
    return *arg0 + (arg1 * 0xC);
}

int fn_802B1B38(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802B1B40(int *arg0, int arg1) {
    return *arg0 + (arg1 * 0x10);
}

int fn_802B1B50(int *arg0, int arg1) {
    return *arg0 + (arg1 << 7);
}


extern float lbl_80564BF8;
extern int fn_802DA704(int, void *, int);
extern void fn_802DAA18(void);
void fn_802B1B60(void *arg0) {
    float sp8[3];
    int count = 0;
    int offset = 0;
    void *list = *(void **)((char *)arg0 + 0xC);
    while (count < *(int *)((char *)list + 8)) {
        char *entry = *(char **)((char *)list + 4) + offset;
        sp8[count * 3] = *(float *)(entry + 4);
        sp8[count * 3 + 1] = *(float *)(entry + 8);
        sp8[count * 3 + 2] = lbl_80564BF8;
        offset += 0x10;
        count++;
    }
    fn_802DA704(1, sp8, 2);
    fn_802DAA18();
}

int fn_802B1BE4(void *arg0) {
    return ((int *)arg0)[1];
}

void fn_802B1BEC(void) {
}

void fn_802B1BF0(void *arg0, void *arg1, int arg2) {
    float *src = (float *)((char *)((int *)arg0)[0x318 / 4] + arg2 * 0xc);
    float *dst = (float *)arg1;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

int fn_802B1C14(void *arg0) {
    return ((int *)arg0)[4];
}

extern int lbl_8034A270;
void *fn_802B1C1C(void *arg0, int arg1) {
    if (arg1 >= 0 && arg1 < ((int *)arg0)[4]) {
        return *(void **)((char *)((int *)arg0)[3] + arg1 * 0x80 + 0x70);
    }
    return &lbl_8034A270;
}

int fn_802B1C50(void *arg0, int arg1, int arg2) {
    if (arg1 >= 0 && arg1 < *(int *)((char *)arg0 + 0x10)) {
        char *base = (char *)*(int *)((char *)arg0 + 0xC);
        return *(int *)(base + (arg2 << 2) + (arg1 << 7) + 0x74);
    }
    return 0;
}

extern int lbl_8034A270;
