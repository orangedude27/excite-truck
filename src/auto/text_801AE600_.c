extern int lbl_80435780[];
extern float fn_801AF9EC(int, float *);
extern void *fn_801AF8D0(int);
extern void fn_801AFABC();
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern char lbl_80558DC4[];
extern float lbl_8055E630;
extern float lbl_8056255C;
  extern float lbl_80562558;
  extern float lbl_80562560;
extern float lbl_80562570;
extern int lbl_8055E628;
extern signed char lbl_8055E635;
  extern int lbl_8055E62C;
  extern double lbl_80562568;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80435740[];
extern const char lbl_80335980[];
extern const char lbl_80335990[];
extern const char lbl_803359AC[];
extern const char lbl_803359BC[];
extern const char lbl_803359CC[];
extern int fn_8012850C(int, const char *);
extern int fn_802794AC(int, void *);
extern float lbl_80562574;
extern void fn_801AFA20(void);
typedef struct {
    unsigned char b[0x60];
} Blob60;
typedef struct {
    int id;
    Blob60 b;
    int f64, f68, f6c;
    unsigned char f70;
    int f74;
} Ent78;
typedef struct {
    char pad[0x20];
    Ent78 e[8];
} Src;
typedef struct {
    float a;
    float b;
} Pair8;

int fn_801AE618(int arg0);
#pragma dont_inline on
int fn_801AE600(int arg0) {
    return arg0 == 0x50;
}
#pragma dont_inline reset

short fn_801AE610(int arg0, short arg1) {
    return 0;
}

#pragma dont_inline on
int fn_801AE618(int arg0) {
    return arg0 & 1;
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801AE620(void *arg0) {
    return fn_801AE618(*(unsigned short *)((char *)arg0 + 0xE));
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801AE628(int arg0) {
    struct {
        int count;
        int indices[8];
        int max_val;
    } data;
    register int i;
    register int offset;
    register char *entry;

    data.max_val = -1;
    data.count = 0;
    for (i = 0, offset = 0; i < lbl_80435780[0x3C0 / 4]; offset += 0x1C, i++) {
        entry = (char *)*lbl_8055E624 + offset;
        if (fn_801AE620(entry) != 0) {
            if (*(short *)(entry + 0x14) >= data.max_val) {
                if (*(short *)(entry + 0x14) > data.max_val) {
                    data.count = 0;
                }
                data.indices[data.count++] = i;
                data.max_val = *(short *)(entry + 0x14);
            }
        }
    }

    for (offset = 0, i = 0; i < lbl_80435780[0x3C0 / 4]; i++, offset += 0x1C) {
        entry = (char *)*lbl_8055E624 + offset;
        if (fn_801AE620(entry) != 0) {
            int k;
            *(short *)(entry + 0x10) = fn_801AE610(arg0, *(short *)(entry + 0xC));
            *(short *)(entry + 0x12) = 0;
            if (*(short *)(entry + 0x14) != 0) {
                *(short *)(entry + 0x12) += 5;
            }
            for (k = 0; k < data.count; k++) {
                if (i == data.indices[k]) {
                    *(short *)(entry + 0x12) += 5;
                }
            }
        }
    }
}
int fn_801AE790(void *arg0) {
    return *((unsigned char *)arg0 + 0x70) & 3;
}
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_801AE79C(int arg0) {
    register int flag;
    register int *base;
    register char *entry;
    short selected;
    int index;

    flag = 0;
    if (arg0 == 2 && lbl_80435780[0x3C0 / 4] > 10)
        flag = 1;
    if (flag != 0) {
        entry = (char *)lbl_80435780;
        base = (int *)entry;
        selected = 0;
        index = 0;
        for (; index < base[0x3C0 / 4]; entry += 0x78, index++) {
            if (*(int *)entry == 0x50 && fn_801AE790(entry) == 0) {
                void *value = fn_801AF8D0(index);
                if (value != 0)
                    selected = *(short *)((char *)value + 0xC);
            }
        }
        if (selected >= 1)
            fn_801AFABC(lbl_8055E628, selected);
    }
}
#pragma scheduling on
extern int lbl_8055E62C;
extern float lbl_8056255C;
extern double lbl_80562568;
void fn_801AE874(unsigned short *arg0, int arg1) {
    unsigned short value = *arg0 | 1;
    *arg0 = value;
    if (arg1) *arg0 = value | 4;
}

#pragma scheduling invalid_target
void fn_801AE894(void *arg0) {
    float temp_f2;
    float temp_f4;
    register int temp_r0;

    temp_r0 = *(short *)((char *)arg0 + 0x18);
    if (temp_r0 > 0) {
        temp_f4 = *(float *)arg0;
        if (temp_f4 > lbl_8056255C) {
            temp_f2 = (lbl_8055E630 * (float)temp_r0) / temp_f4;
            *(float *)((char *)arg0 + 4) = temp_f2;
            *(float *)((char *)arg0 + 4) =
                temp_f2 * ((float)temp_r0 / (float)lbl_8055E62C);
            return;
        }
    }
    *(float *)((char *)arg0 + 4) = lbl_80562560;
}

#pragma processor 750
#pragma dont_inline on
void fn_801AE928(void) {
    int count;
    float duration;
    int offset;
    int index;
    char *entry;
    count = fn_801EA994();
    duration = lbl_80562560;
    index = 0;
    offset = 0;
    while (index < count) {
        if (index < lbl_8055E624[1]) {
            entry = (char *)lbl_8055E624[0] + offset;
            if (!fn_801AE620(entry)) {
                fn_801AE874((unsigned short *)(entry + 0xE), 1);
                *(unsigned short *)(entry + 0xE) |= 8;
                *(float *)entry = duration;
                fn_801AE894(entry);
            }
        }
        offset += 0x1C;
        index++;
    }
}
#pragma dont_inline reset
#pragma processor gekko

float fn_801AE9E0(int arg0, float *arg1) {
    char *entry;
    if (arg1 != 0) *arg1 = lbl_80562560;
    entry = (char *)lbl_8055E624[0] + arg0 * 0x1C;
    if (fn_801AE620(entry)) {
        if (arg1 != 0) *arg1 = lbl_8055E630 / *(float *)(entry + 8);
        return *(float *)(entry + 8);
    }
    return lbl_80562558;
}

#pragma small_data off
extern float lbl_80562560;
extern float lbl_8055E630;
extern float lbl_80562558;
extern int lbl_8055E62C;
extern double lbl_80562568;
extern float lbl_8056255C;
extern void fn_801AE874(unsigned short *, int);
extern void fn_801AE894(void *);
extern int fn_801EA994(void);
extern double __fabs(double);
int fn_801AEA64(float arg0, float arg1) {
    /* Round the absolute float difference and compare with the full-address tolerance. */
    float diff = arg0 - arg1;
    float magnitude = (float)__fabs((double)diff);
    if (magnitude <= *(float *)(void *)&lbl_80558DC4) return 0;
    if (arg1 < arg0) return 1;
    return -1;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
int fn_801AEB58(const void *arg0, const void *arg1) {
    float f31;
    float f1;
    float f2;
    int temp = *(const int *)arg1;
    f31 = fn_801AF9EC(*(const int *)arg0, 0);
    f1 = fn_801AF9EC(temp, 0);
    f2 = f1;
    if (f31 < lbl_8056255C)
        f31 = lbl_80562570;
    if (f1 < lbl_8056255C)
        f2 = lbl_80562570;
    return fn_801AEA64(f31, f2);
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling invalid_target
void fn_801AEBD0(void) {
    int value = lbl_8055E62C;
    int count = lbl_80435780[0x3C0 / 4];
    int i;
    int share;
    int remainder;

    for (i = 0; i < count; i++) {
        short *item = (short *)(*lbl_8055E624 + i * 0x1C);
        value -= item[0x14 / 2];
    }

    share = value / 3;
    remainder = value % 3;

    {
        register int *global = lbl_80435780;
        int offset;
        for (offset = 0, i = 0;
             i < *(volatile int *)((char *)global + 0x3C0);
             offset += 0x1C, i++) {
            char *entry = (char *)*(volatile int *)lbl_8055E624 + offset;
            short type = *(short *)(entry + 0xC);
            if (type < 4) {
                *(short *)(entry + 0x14) += share;
                if (type == 1)
                    *(short *)(entry + 0x14) += remainder;
            }
        }
    }
}
#pragma scheduling on
void fn_801AED54(void) {

}

void fn_801AED58(void) {

}

extern signed char lbl_8055E634;
extern void fn_801B8778(void);
extern void fn_801B878C(void);
extern float fn_801AF9EC(int, float *);
extern int fn_801AEA64(float, float);
extern void *fn_801AF8D0(int);
void fn_801AED5C(void) {
    lbl_8055E634 = 1;
    fn_801B8778();
}

void fn_801AED68(void) {
    lbl_8055E634 = 0;
    fn_801B878C();
}

extern void *lbl_8055E620;
extern int fn_801B2F24(void);
extern int fn_801B3050(int);
extern int fn_801B2ED4(void);
extern void *memset(void *, int, unsigned int);
#pragma paired off
#pragma paired_single off
void fn_801AED74(void) {
    register int *base;
    register void *data;
    register int i;
    register int offset;
    register int **table;
    register int j;
    register int *entry;
    register int count;
    register int byteOffset;
    register float value;

    if (*(unsigned char *)&lbl_8055E634 == 0) {
        base = lbl_8055E624;
        i = 0;
        value = lbl_80562558;
        offset = 0;
        for (; i < base[1]; i++) {
            int selected;
            data = (char *)base[0] + offset;
            memset(data, 0, 0x1C);
            *(float *)((char *)data + 8) = value;
            *(short *)((char *)data + 0xC) = -100;
            if (i < fn_801B2F24())
                selected = fn_801B3050(i);
            else
                selected = -1;
            *(short *)((char *)data + 0x1A) = selected;
            offset += 0x1C;
        }
        table = (int **)lbl_8055E620;
        for (j = 0; j != 6; j += 3) {
            entry = table[0];
            if (entry != 0) {
                count = 0;
                byteOffset = 0;
                while (count < entry[1]) {
                    *(short *)((char *)entry[0] + byteOffset + 6) = 0;
                    count++;
                    byteOffset += 8;
                }
            }
            entry = table[1];
            if (entry != 0) {
                count = 0;
                byteOffset = 0;
                while (count < entry[1]) {
                    *(short *)((char *)entry[0] + byteOffset + 6) = 0;
                    count++;
                    byteOffset += 8;
                }
            }
            entry = table[2];
            if (entry != 0) {
                count = 0;
                byteOffset = 0;
                while (count < entry[1]) {
                    *(short *)((char *)entry[0] + byteOffset + 6) = 0;
                    count++;
                    byteOffset += 8;
                }
            }
            entry = table[3];
            if (entry != 0) {
                count = 0;
                byteOffset = 0;
                while (count < entry[1]) {
                    *(short *)((char *)entry[0] + byteOffset + 6) = 0;
                    count++;
                    byteOffset += 8;
                }
            }
            table += 4;
        }
    }
    lbl_8055E62C = fn_801B2ED4();
}

void fn_801AEF28(Src *arg0) {
    int *p;
    int *q;
    int i, off;
    char *base = (char *)lbl_80435740;
    Ent78 *dst = (Ent78 *)(base + 0x40);
    int *dcount = (int *)(base + 0x40 + 0x3C0);
    lbl_8055E635 = 1;
    p = (int *)fn_801284F8(0x24, lbl_80335980);
    if (p != 0) {
        memset(p, 0, 0x20);
        p[8] = 8;
    }
    lbl_8055E620 = p;
    q = (int *)fn_801284F8(8, lbl_80335990);
    if (q != 0) {
        float v;
        q[1] = 8;
        q[0] = fn_8012850C(q[1] * 0x1C, lbl_803359CC);
        v = lbl_80562558;
        for (i = 0, off = 0; i < q[1]; i++, off += 0x1C) {
            char *d = (char *)q[0] + off;
            int sel;
            memset(d, 0, 0x1C);
            *(float *)(d + 8) = v;
            *(short *)(d + 0xC) = -100;
            if (i < fn_801B2F24())
                sel = fn_801B3050(i);
            else
                sel = -1;
            *(short *)(d + 0x1A) = sel;
        }
    }
    lbl_8055E624 = q;
    lbl_8055E628 = ((int (*)(void *))fn_801AFA20)(arg0);
    *dcount = 0;
    for (i = 0; i < *(int *)((char *)arg0 + 0x3E0); i++) {
        Ent78 *s = &arg0->e[i];
        Ent78 *d = &dst[i];
        int id = s->id;
        if (fn_802794AC(id, (char *)arg0 + 0x3E4) == 0)
            break;
        d->id = id;
        d->b = s->b;
        d->f64 = s->f64;
        d->f68 = s->f68;
        d->f6c = s->f6c;
        d->f70 = s->f70;
        d->f74 = s->f74;
        ((int *)(base + 0x408))[i] = *dcount;
        (*dcount)++;
        if (fn_801AE600(id) != 0) {
            int *r = (int *)lbl_8055E620;
            int *t = (int *)fn_801284F8(8, lbl_803359AC);
            if (t != 0) {
                int k;
                t[1] = 0x1F5;
                t[0] = fn_8012850C(0xFA8, lbl_803359BC);
                for (k = 0; k < t[1]; k++)
                    *(short *)((char *)t[0] + k * 8 + 6) = 0;
            }
            r[i] = (int)t;
        }
    }
    for (i = 0; i < *dcount; i++) {
        lbl_80435740[i * 2] = lbl_80562560;
        lbl_80435740[i * 2 + 1] = lbl_8056255C;
    }
    lbl_8055E634 = 0;
    lbl_8055E630 = lbl_80562574;
    lbl_8055E62C = -1;
    for (i = 0; i < 4; i++)
        memset(base + 0x428 + i * 0x10, 0, 0x10);
}

#pragma paired_single reset
#pragma paired reset
extern void fn_801AFA5C(int);
extern void fn_80128670(void *);
extern void fn_80128668();
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_801AF598(void) {
    register unsigned int i;
    register int **slot;
    register int *entry;
    register int **array;
    int value = lbl_8055E628;
    int zero = 0;
    lbl_8055E635 = zero;
    fn_801AFA5C(value);
    array = (int **)lbl_8055E620;
    lbl_8055E628 = zero;
    if (array != 0) {
        slot = array;
        for (i = 0; i < 8U; i++, slot++) {
            entry = *slot;
            if (entry == 0)
                goto clear;
            if (entry == 0)
                goto clear;
            fn_80128670((void *)*entry);
            *entry = zero;
            fn_80128668(entry);
        clear:
            *(volatile int **)slot = 0;
        }
        fn_80128668(array);
    }
    {
        register int **last;
        last = (int **)lbl_8055E624;
        lbl_8055E620 = 0;
        if (last != 0) {
            fn_80128670((void *)*last);
            *last = 0;
            fn_80128668(last);
        }
    }
    lbl_8055E624 = 0;
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling invalid_target
void fn_801AF65C(void) {
    int *base = lbl_80435780;
    int offset = 0;
    int i = 0;
    while (i < base[0x3C0 / 4]) {
        char *entry = (char *)lbl_8055E624[0] + offset;
        if (fn_801AE620(entry) && *fn_801EA9A0(i)) {
            *(unsigned short *)(entry + 0xE) |= 2;
        }
        offset += 0x1C;
        i++;
    }
}
extern int fn_801769B8(void);
extern void fn_801AE928(void);
extern void fn_801AF65C(void);
extern void fn_801AFAB0(void);
extern void fn_801AFAB4(void);
extern void fn_801AFAB8(void);
extern int fn_80137C4C(void);
extern int fn_801AEAA4(const void *, const void *);
extern int fn_801AEB58(const void *, const void *);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern void fn_801B3208(int, int, float);
#pragma small_data off
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801AF6FC(void) {
    register float *base = lbl_80435740;
    register int mode;
    register unsigned int notTwo;
    register float *value;
    register int dataIndex;
    register int entryCount;
    register int entryOffset;
    register int rank;
    register int *sorted;
    register int *finalSorted;
    register int finalIndex;
    register volatile int *area = (volatile int *)((char *)base + 0x40);
    register int (*compare)(const void *, const void *);

    mode = fn_801769B8();
    notTwo = (unsigned int)((2 - mode) | (mode - 2)) >> 31;
    if (notTwo == 0) {
        fn_801AE928();
    }
    fn_801AF65C();

    for (entryCount = 0, entryOffset = 0; entryCount < ((int *)lbl_8055E620)[8]; entryCount++, entryOffset += 4) {
        int *entry = (int *)*(void **)((char *)lbl_8055E620 + entryOffset);
        if (entry != 0) {
            ((void (*)(int, int, int))fn_801AFAB0)(lbl_8055E628, entry[0], entry[1]);
        }
    }

    if (notTwo == 0) {
        ((void (*)(int, int, int))fn_801AFAB4)(lbl_8055E628, lbl_8055E624[0], lbl_8055E624[1]);
    }

    if (mode == 1) {
        value = base;
        for (dataIndex = 0; dataIndex < area[0x3c0 / 4]; dataIndex++, value += 2) {
            value[0] = fn_801AE9E0(dataIndex, value + 1);
        }
    }

    sorted = (int *)((char *)base + 0x408);
    compare = fn_801AEAA4;
    if (mode == 1) {
        compare = fn_801AEB58;
    }
    qsort(sorted, area[0x3c0 / 4], 4, compare);

    rank = 0;
    sorted = (int *)((char *)base + 0x408);
    for (; rank < area[0x3c0 / 4]; rank++, sorted++) {
        int index = *sorted;
        short rankValue = rank + 1;
        *(short *)((char *)lbl_8055E624[0] + index * 0x1C + 0xC) = rankValue;
    }

    fn_801AEBD0();
    fn_801AE628((int)fn_80137C4C());

    if (notTwo == 0) {
        ((void (*)(int, int, int))fn_801AFAB8)(lbl_8055E628, lbl_8055E624[0], lbl_8055E624[1]);
    }

    fn_801AE79C(mode);

    if (mode == 1) {
        finalSorted = (int *)((char *)base + 0x408);
        for (finalIndex = 0; finalIndex < area[0x3c0 / 4]; finalIndex++, finalSorted++) {
            int index = *finalSorted;
            float itemValue = fn_801AF9EC(index, 0);
            fn_801B3208(index, finalIndex, itemValue);
        }
    }
}
#pragma scheduling on
#pragma dont_inline reset
#pragma small_data on

#pragma scheduling on
void *fn_801AF8D0(int arg0) {
 void *result = 0;
 if (arg0 < lbl_8055E624[1]) {
  result = (char *)lbl_8055E624[0] + arg0 * 0x1C;
  if (!fn_801AE620(result)) {
   result = 0;
  }
 }
 return result;
}

#pragma small_data off
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801AF92C(void *arg0) {
    void *base = arg0;
    char *entry;
    int count;
    register int i;
    register int zero = 0;
    register int minusOne = -1;

    if (fn_801B8728() != 0)
        goto done;
    if (fn_801B2C70(base) != 0)
        goto done;

    count = lbl_80435780[0x3C0 / 4];
    *(int *)base = count;
    entry = (char *)base + 0x10;
    i = 0;
    *(int *)((char *)base + 4) = zero;
    *((signed char *)base + 0xC) = zero;
    *((signed char *)base + 0xD) = 1;

    for (; i < count; entry += 0x14, i++) {
        void *item = fn_801AF8D0(i);
        if (item != 0) {
            *(int *)(entry + 4) = *(short *)((char *)item + 0xC);
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        } else {
            *(int *)(entry + 4) = minusOne;
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        }
    }

done:
    ;
}
#pragma scheduling on
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma small_data on
float fn_801AF9EC(int arg0, float *arg1) {
    if (arg1 != 0) *arg1 = ((float (*)[2])lbl_80435740)[arg0][1];
    return lbl_80435740[arg0 * 2];
}

#pragma scheduling invalid_target
void fn_801AFA20(void) {
    /* Pass the check result through and set its failure value to minus one. */
    int result = fn_801284F8(4, lbl_803359A0);
    if (result != 0) {
        ((void (*)(int *, int))fn_801AFA64)((int *)result, -1);
    }
}
#pragma scheduling on
void fn_801AFA5C(int arg0) { fn_801AFA70(arg0, 1); }

extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];

void fn_801AFA64(int *arg0) { *arg0 = 0; }

int fn_801AFA70(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

void fn_801AFAB4(void) {

}

void fn_801AFABC(void) {

}

void fn_801AFAB8(void) {

}

void fn_801AFAB0(void) {

}
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
