// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;

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
    int *ptr = (int *)*arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            int value = ptr[2];
            if (value != -2) {
                fn_802CAC54();
                ptr[2] = -2;
            }
            value = ptr[0];
            if (value != 0) fn_802C6C20();
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
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
#pragma scheduling reset
void fn_802B2D94(int *arg0) {
    int i;
    i = 0;
    lbl_8055F9B4 = 0;
    lbl_8055F9B0 = 0;
    do {
        fn_802B2E08(*fn_802B320C(arg0, i));
        i++;
    } while (i < fn_802B2E00(arg0));
}

int fn_802B2E00(void *arg0) {
    return ((int *)arg0)[1];
}

int *fn_802B320C(int *arg0, int arg1) {
    return (int *)((char *)*arg0 + arg1 * 4);
}

extern char lbl_8034A3BC[];
extern void fn_802E30C8(const char *, int, int, int);
void fn_802B321C(int *param_1, int *param_2, int *param_3, int param_4)
{
    int i;
    int offset;
    int item;
    int *entry;
    int *value;
    int count;

    if (param_4 < 0 || param_3[1] <= param_4) {
        fn_802E30C8(lbl_8034A3BC, param_4, 0, param_3[1]);
        return;
    }
    item = *(int *)(*param_3 + param_4 * 4);
    if (param_1 != 0) {
        i = 0;
        offset = 0;
        while (i < *(int *)(item + 0x40C) && param_1[1] + 1 <= param_1[2]) {
            i++;
            count = param_1[1];
            entry = *(int **)(*(int *)(item + 0x408) + offset);
            offset += 4;
            param_1[1] = count + 1;
            value = (int *)((char *)param_1[0] + count * 0xC);
            value[0] = *(int *)((char *)entry + 0x2A4);
            value[1] = (int)entry;
            value[2] = (int)((char *)entry + 0x298);
        }
    }
    if (param_2 != 0)
        *param_2 = item + 4;
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

typedef struct {
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

int fn_802B2C44(void *arg0) {
    void **vtable = *(void ***)arg0;
    int (*method)(void) = (int (*)(void))vtable[0x17];
    return method() != 0;
}

#pragma push
#pragma use_lmw_stmw off
int fn_802B2C98(char *arg0) {
    Unk802B2C98 *base = &lbl_804BE1FC;
    int result = 0;
    int i;
    for (i = 0; i < base->m4; i++) {
        if (stricmp(arg0, *(char **)((char *)((void **)base->m0)[i] + 0x24)) == 0) {
            result = (int)((void **)base->m0)[i];
            break;
        }
    }
    return result;
}
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
