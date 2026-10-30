// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
__declspec(section ".data") extern int lbl_804B3400;
extern int lbl_8055F728;
extern int lbl_8055F724;
extern int lbl_8055F718, lbl_8055F71C, lbl_8055F720;
extern float lbl_8055F710, lbl_805643E8, lbl_805643EC;
extern float fn_801E88F0(int);
extern float fn_802C9A4C(float);
extern void fn_802C9648(float);
extern void fn_802C8BD0(int);
extern int fn_801E5370(int, int, float);
extern void fn_8028D7C0(int);
extern void fn_801E58FC(void);
extern void fn_802C8D74(void);
extern void fn_802C967C(void);
extern float lbl_80558DC4[];
extern float fn_801E7E24(void);
extern void fn_8028D728(void);
extern void fn_8028D4FC(void);
extern void fn_8028D4A0(void);
extern void fn_8028D25C(void);
extern int fn_8028D17C(void);
extern void fn_8028D2B4(void);
extern void fn_8028DDF0(void *, int);
extern void fn_80287B38(void *);
void fn_8028CED8(void) {
    if (fn_8028D17C() != 0) {
        fn_8028D2B4();
        fn_80287B38(fn_8028DDF0);
        lbl_8055F714 = 1;
    }
}

void fn_8028CF18(void) {
    if (lbl_8055F714 != 0) {
        fn_8028D4A0();
        fn_8028D25C();
        lbl_8055F714 = 0;
    }
}

void fn_8028CF50(void) {
    if (lbl_8055F714 != 0) {
        fn_8028D4FC();
    }
}

void fn_8028CF64(void) {
    if (lbl_8055F714 != 0) {
        float value = fn_801E7E24();
        float abs = (float)__fabs((double)value);
        if (!(abs <= lbl_80558DC4[0]))
            fn_8028D728();
    }
}

#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
void fn_8028CFB0(void) {
    int *entry;
    int i;
    float scale;
    float time;
    if (lbl_8055F714 != 0) {
        time = fn_802C9A4C(lbl_8055F710);
        fn_802C9648(lbl_805643E8);
        entry = &lbl_804B3400;
        scale = lbl_805643EC;
        for (i = 0; i < *(volatile int *)&lbl_8055F728; i++) {
            if (entry[6] > 1) {
                fn_802C8BD0(entry[0]);
                if (fn_801E5370(entry[6], 4, scale * fn_801E88F0(-1)) != 0) {
                    fn_8028D7C0(i);
                    fn_801E58FC();
                }
                fn_802C8D74();
            }
            entry = (int *)((char *)entry + 0x1C);
        }
        fn_802C967C();
        fn_802C9A4C(time);
    }
}
#pragma scheduling on
#pragma paired_single reset
#pragma paired reset
extern int fn_802CAC28(int);
extern int fn_802E317C(char *, ...);
extern char lbl_80348C50[];
extern char lbl_8055C8C8[];
void fn_8028D084(void *arg0, void *arg1) {
    char *base = lbl_80348C50;
    int value;
    void **vtable = *(void ***)arg1;
    ((void (*)(void *, const char *))vtable[5])(arg1, lbl_8055C8C8);
    *(int *)arg0 = fn_802CAC28(0);
    *(float *)((char *)arg0 + 4) = ((float (*)(void *, char *))vtable[9])(arg1, base);
    *(float *)((char *)arg0 + 8) = ((float (*)(void *, char *))vtable[9])(arg1, base + 0xC);
    *(float *)((char *)arg0 + 0xC) = ((float (*)(void *, char *))vtable[9])(arg1, base + 0x18);
    value = ((int (*)(void *, char *))vtable[7])(arg1, base + 0x24);
    *(int *)((char *)arg0 + 0x10) = value;
    if (value < 8 || value > 0x24)
        fn_802E317C(base + 0x30, value);
}
#pragma scheduling on
extern char lbl_804B3470[];
extern char lbl_80348CA0[];
extern int lbl_8055C8D0;
extern int fn_801345D8(void *, int, const void *, ...);
extern void *fn_802AE414(void *);
extern void fn_8028D084(void *, void *);
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
int fn_8028D17C(void) {
    register char *base;
    register int *slot;
    int i;
    register int invalid;
    char temp[0x20];
    void *obj;

    slot = (int *)lbl_804B3470;
    lbl_8055F728 = 0;
    base = (char *)&lbl_804B3400;
    i = 0;
    invalid = -1;
    for (; i < 8; i++) {
        fn_801345D8(temp, 0x20, lbl_80348CA0, i);
        obj = fn_802AE414(temp);
        if (obj != 0) {
            obj = ((void *(*)(void *, void *))(*(void ***)obj)[23])(obj, &lbl_8055C8D0);
        }
        if (obj != 0) {
            fn_8028D084(base + lbl_8055F728 * 0x1C, obj);
            *slot = lbl_8055F728;
            lbl_8055F728++;
        } else {
            *slot = invalid;
        }
        slot++;
    }
    return lbl_8055F728 > 0;
}
#pragma dont_inline reset
#pragma scheduling reset
#pragma use_lmw_stmw reset
extern int lbl_8055F728;
extern void fn_802CAC54(int);
void fn_8028D25C(void) {
    int *ptr = (int *)(void *)&lbl_804B3400;
    int i = 0;
    while (i < lbl_8055F728) {
        fn_802CAC54(*ptr);
        ptr = (int *)((char *)ptr + 0x1C);
        i++;
    }
}

extern void *fn_8012850C(int, void *);
extern int fn_80287B14(void);
extern void *fn_8002F37C(void *, void (*)(void), int, int, int);
extern void fn_8028D49C(void);
#pragma push
#pragma scheduling invalid_target
void fn_8028D2B4(void) {
    typedef struct {
        int value0;
        int value1;
        int value2;
        int value3;
        int size;
        int value5;
        int value6;
    } Entry;
    register char *names = lbl_80348C50;
    register int sum = 0;
    int i = 0;
    int slots;
    int records;
    void *buffer;
    int *current;
    int *entry;
    int *ptr;
    int outer;
    int inner;

    for (; i < lbl_8055F728; i++)
        sum += ((Entry *)&lbl_804B3400)[i].size;

    slots = fn_80287B14() * 4;
    sum *= slots;
    lbl_8055F724 = slots;
    records = lbl_8055F728 * slots;
    buffer = fn_8012850C(sum * 0x28 + 0x10, names + 0x5C);
    lbl_8055F718 = (int)fn_8002F37C(buffer, fn_8028D49C, 0, 0x28, sum);
    lbl_8055F71C = (int)fn_8012850C(records * 0xC, names + 0x6C);
    lbl_8055F720 = (int)fn_8012850C(*(volatile int *)&lbl_8055F724 * 8, names + 0x80);

    entry = &lbl_804B3400;
    current = (int *)lbl_8055F718;
    ptr = (int *)lbl_8055F71C;
    for (outer = 0; outer < lbl_8055F728; outer++) {
        *(int **)((char *)entry + 0x14) = ptr;
        for (inner = 0; inner < *(volatile int *)&lbl_8055F724; inner++) {
            *ptr = (int)current;
            ptr[2] = entry[4];
            ptr += 3;
            current = (int *)((char *)current + entry[4] * 0x28);
        }
        entry += 7;
    }
}
#pragma pop

void fn_8028D49C(void) {
}

extern int lbl_8055F718, lbl_8055F71C, lbl_8055F720;
extern int fn_80128670(int);
void fn_8028D4A0(void) {
    fn_80128670(lbl_8055F720);
    lbl_8055F720 = 0;
    fn_80128670(lbl_8055F71C);
    lbl_8055F71C = 0;
    if (lbl_8055F718 != 0) {
        fn_80128670(lbl_8055F718 - 0x10);
    }
    lbl_8055F718 = 0;
}

extern int lbl_8055F724;
extern float lbl_805643F0;
extern void fn_8028D58C(void *);
void fn_8028D4FC(void) {
    typedef struct { unsigned char pad[0x14]; int *items; int total; } Entry;
    Entry *entry = (Entry *)&lbl_804B3400;
    int i, j;
    for (i = 0; i < lbl_8055F728; i++) {
        int *item = entry[i].items;
        for (j = 0; j < lbl_8055F724; j++)
            *(int *)((char *)item + j * 0xC + 4) = 0;
    }
    for (i = 0; i < lbl_8055F724; i++) {
        *(int *)((char *)lbl_8055F720 + i * 8) = -1;
        *(float *)((char *)lbl_8055F720 + i * 8 + 4) = lbl_805643F0;
    }
}

void fn_8028D58C(void *arg0) {
    unsigned int count;
    unsigned int iterations;
    unsigned int i;
    unsigned int marker;
    int startIndex;
    int normalized;
    unsigned char *base;
    unsigned char *end;
    unsigned char *start;
    unsigned char *current;
    unsigned char *dst;
    count = *(unsigned int *)((char *)arg0 + 4);
    startIndex = count - *(unsigned int *)((char *)arg0 + 8) + 2;
    startIndex = startIndex & ((-startIndex & ~startIndex) >> 31);
    base = *(unsigned char **)arg0;
    end = base + count * 0x28;
    start = base + startIndex * 0x28;
    iterations = (unsigned int)(end + 0x27 - start) / 0x28;
    current = start;
    i = iterations;
    while (i != 0) {
        i--;
        marker = 0;
        if (current > start && current[0x26] != 0 &&
            (*(unsigned short *)(current + 0x24) >= 0x100 ||
             *(unsigned short *)(current - 4) >= 0x100 ||
             current + 0x28 >= end ||
             (current[0x4E] != 0 && *(unsigned short *)(current + 0x4C) >= 0x100)))
            marker = 1;
        current[0x26] = marker;
        current += 0x28;
    }
    current = start;
    iterations = (unsigned int)(end + 0x27 - current) / 0x28;
    dst = (unsigned char *)*(volatile unsigned int *)arg0;
    i = iterations;
    while (i != 0) {
        i--;
        if (current[0x26] != 0 ||
            (current + 0x28 < end && current[0x4E] != 0)) {
            *(float *)(dst + 0x00) = *(float *)(current + 0x00);
            *(float *)(dst + 0x04) = *(float *)(current + 0x04);
            *(float *)(dst + 0x08) = *(float *)(current + 0x08);
            *(float *)(dst + 0x0C) = *(float *)(current + 0x0C);
            *(float *)(dst + 0x10) = *(float *)(current + 0x10);
            *(float *)(dst + 0x14) = *(float *)(current + 0x14);
            *(float *)(dst + 0x18) = *(float *)(current + 0x18);
            *(float *)(dst + 0x1C) = *(float *)(current + 0x1C);
            *(float *)(dst + 0x20) = *(float *)(current + 0x20);
            normalized = *(unsigned short *)(current + 0x24) - 0x80;
            normalized = normalized & ((-normalized & ~normalized) >> 31);
            *(unsigned short *)(dst + 0x24) = normalized;
            dst[0x26] = current[0x26];
            dst += 0x28;
        }
        current += 0x28;
    }
    *(unsigned int *)((char *)arg0 + 4) =
        (dst - (unsigned char *)*(volatile unsigned int *)arg0) / 0x28;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028D728(void) {
    typedef struct { unsigned char pad[0x14]; int *items; int total; } Entry;
    Entry *entry = (Entry *)&lbl_804B3400;
    int i, j;
    for (i = 0; i < lbl_8055F728; i++) {
        entry[i].total = 0;
        for (j = 0; j < lbl_8055F724; j++) {
            int *item = (int *)((char *)entry[i].items + j * 0xC);
            fn_8028D58C(item);
            entry[i].total += item[1];
        }
    }
}
#pragma scheduling on
#pragma pop
extern double lbl_805643F8;
extern float lbl_805643F4;
extern void fn_801E53A8(void *, void *, void *, int, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma fp_contract on
#pragma use_lmw_stmw off
void fn_8028D7C0(int arg0) {
    register float scale;
    register double bias;
    register int outerOffset;
    register int offset;
    register int *table;
    register int outer;
    register int *group;
    register int inner;
    register int *item;

    bias = lbl_805643F8;
    scale = lbl_805643F4;
    table = (int *)((char *)&lbl_804B3400 + arg0 * 0x1C);
    outer = 0;
    outerOffset = 0;
    while (outer < lbl_8055F724) {
        group = (int *)((char *)table[5] + outerOffset);
        inner = 0;
        offset = 0;
        while (inner < group[1]) {
            item = (int *)((char *)group[0] + offset);
            {
                double raw;
                *(unsigned int *)&raw = 0x43300000;
                *((unsigned int *)&raw + 1) =
                    *(unsigned short *)((char *)item + 0x24);
                fn_801E53A8(item, (char *)item + 0xC, (char *)item + 0x18,
                            *((unsigned char *)item + 0x26) != 0,
                            scale * (float)(raw - bias));
            }
            offset += 0x28;
            inner++;
        }
        outerOffset += 0xC;
        outer++;
    }
}

extern int lbl_804B3490[];
extern float lbl_80564414;
extern float fn_801E7E18(void);
extern void fn_8028D89C(void *, int, float);
void fn_8028DDF0(register void *arg0, register int arg1) {
    typedef struct {
        int *items;
        int index;
        float f8;
        unsigned char c;
    } Entry;
    typedef struct {
        int a, b, c, d, e, f, g, h;
    } Output;
    Entry *entry = (Entry *)arg0;
    register int invalid;
    register int *slot;
    register int i;
    register float threshold;
    register float result;
    float value;
    float abs;

    value = fn_801E7E24();
    abs = (float)__fabs((double)value);
    if (abs <= lbl_80558DC4[0])
        return;

    threshold = lbl_80564414;
    result = fn_801E7E18();
    slot = lbl_804B3490;
    i = 0;
    invalid = -1;
    while (i < arg1) {
        if (entry->f8 < threshold &&
            (void *)(unsigned long)entry->items[0x19] == (void *)slot[entry->index] &&
            entry->c != 0) {
            int j;
            for (j = 0; j < 4; j++)
                fn_8028D89C(entry, j, result);
        } else {
            int offset = entry->index << 5;
            *(int *)((char *)(unsigned long)lbl_8055F720 + offset) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 8) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 0x10) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 0x18) = invalid;
        }
        slot[entry->index] = entry->items[0x19];
        entry++;
        i++;
    }
}

#pragma scheduling on
#pragma pop
