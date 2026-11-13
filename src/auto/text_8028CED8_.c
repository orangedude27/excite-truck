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

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028CFB0(void) {
    /* Update active entries in the table, processing those with pending work and restoring the previous timer state. */
    int *entry;
    int i;
    float scale;
    float savedTime;
    if (lbl_8055F714 != 0) {
        savedTime = fn_802C9A4C(lbl_8055F710);
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
        fn_802C9A4C(savedTime);
    }
}
#pragma pop
extern int fn_802CAC28(int);
extern int fn_802E317C(char *, ...);
extern char lbl_80348C50[];
extern char lbl_8055C8C8[];
#pragma cplusplus on
struct Obj8028D084 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(const char *);
    virtual void f6();
    virtual int f7(char *);
    virtual void f8();
    virtual float f9(char *);
};
#pragma cplusplus reset
void fn_8028D084(void *arg0, void *arg1) {
    extern char lbl_8055C8C8[8];
    char *base = lbl_80348C50;
    const char *tex = lbl_8055C8C8;
    int value;
    ((void (*)(void *, const char *))(*(void ***)arg1)[5])(arg1, tex);
    *(int *)arg0 = fn_802CAC28(0);
    *(float *)((char *)arg0 + 4) = ((float (*)(void *, char *))(*(void ***)arg1)[9])(arg1, base);
    *(float *)((char *)arg0 + 8) = ((float (*)(void *, char *))(*(void ***)arg1)[9])(arg1, base + 0xC);
    *(float *)((char *)arg0 + 0xC) = ((float (*)(void *, char *))(*(void ***)arg1)[9])(arg1, base + 0x18);
    value = ((int (*)(void *, char *))(*(void ***)arg1)[7])(arg1, base + 0x24);
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
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_8028D17C(void) {
    register char *base;
    register int *slot;
    register int i;
    register int invalid;
    char temp[0x20];
    register void *obj;

    slot = (int *)lbl_804B3470;
    lbl_8055F728 = 0;
    base = (char *)&lbl_804B3400;
    i = 0;
    invalid = -1;
    for (; i < 8; i++) {
        fn_801345D8(temp, 0x20, lbl_80348CA0, i);
        obj = fn_802AE414(temp);
        if (obj != 0) {
            void **vt = *(void ***)obj;
            typedef void *(*F)(void *, void *);
            obj = ((F *)vt)[23](obj, &lbl_8055C8D0);
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
        int unk0;
        int unk4;
        int unk8;
        int unkC;
        int elemCount; /* 0x10 */
        int subRecords; /* 0x14 */
        int unk18;
    } SkidDef;
    register char *labelStrings = lbl_80348C50;
    register int totalElems = 0;
    int i = 0;
    int slots;
    int records;
    void *buffer;
    int *current;
    int *entry;
    int *ptr;
    int defIndex;
    int slotIndex;

    /* Allocate and initialize per-definition skid particle/element buffers. */
    for (; i < lbl_8055F728; i++)
        totalElems += ((SkidDef *)&lbl_804B3400)[i].elemCount;

    slots = fn_80287B14() * 4;
    totalElems *= slots;
    lbl_8055F724 = slots;
    records = lbl_8055F728 * slots;
    buffer = fn_8012850C(totalElems * 0x28 + 0x10, labelStrings + 0x5C);
    lbl_8055F718 = (int)fn_8002F37C(buffer, fn_8028D49C, 0, 0x28, totalElems);
    lbl_8055F71C = (int)fn_8012850C(records * 0xC, labelStrings + 0x6C);
    lbl_8055F720 = (int)fn_8012850C(*(volatile int *)&lbl_8055F724 * 8, labelStrings + 0x80);

    entry = &lbl_804B3400;
    current = (int *)lbl_8055F718;
    ptr = (int *)lbl_8055F71C;
    for (defIndex = 0; defIndex < lbl_8055F728; defIndex++) {
        *(int **)((char *)entry + 0x14) = ptr;
        for (slotIndex = 0; slotIndex < *(volatile int *)&lbl_8055F724; slotIndex++) {
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
#pragma scheduling invalid_target
void fn_8028D4FC(void) {
    typedef struct { unsigned char pad[0x14]; int *items; int total; } Entry;
    Entry *e = (Entry *)&lbl_804B3400;
    int off;
    int i, j;
    int *itemp;
    i = 0;
    while (i < *(volatile int *)&lbl_8055F728) {
        j = 0;
        off = 0;
        while (j < *(volatile int *)&lbl_8055F724) {
            itemp = (int *)((char *)e->items + off);
            *(int *)((char *)itemp + 4) = 0;
            j++;
            off += 0xC;
        }
        e++;
        i++;
    }
    {
        float f = lbl_805643F0;
        int k = 0;
        unsigned int o = 0;
        while (k < *(volatile int *)&lbl_8055F724) {
            int *b = (int *)*(volatile int *)&lbl_8055F720;
            *(int *)((char *)b + o) = -1;
            *(float *)((char *)b + o + 4) = f;
            k++;
            o += 8;
        }
    }
}
#pragma scheduling on
void fn_8028D58C(void *arg0) {
    unsigned int count;
    int startIndex;
    unsigned char *base;
    unsigned char *end;
    unsigned char *start;
    unsigned char *dst;
    unsigned char *current;
    int normalized;
    count = *(unsigned int *)((char *)arg0 + 4);
    startIndex = (int)count - *(int *)((char *)arg0 + 8) + 2;
    startIndex = startIndex & ((-startIndex & ~startIndex) >> 31);
    base = *(unsigned char **)arg0;
    end = base + count * 0x28;
    start = base + (unsigned int)startIndex * 0x28;
    for (current = start; current < end; current += 0x28) {
        unsigned int marker = 0;
        if (current > start && current[0x26] != 0 &&
            (*(unsigned short *)(current + 0x24) >= 0x100 ||
             *(unsigned short *)(current - 4) >= 0x100 ||
             current + 0x28 >= end ||
             (current[0x4E] != 0 && *(unsigned short *)(current + 0x4C) >= 0x100))) {
            marker = 1;
        }
        current[0x26] = (unsigned char)marker;
    }
    dst = *(unsigned char * volatile *)arg0;
    for (current = start; current < end; current += 0x28) {
        if (current[0x26] != 0 || (current + 0x28 < end && current[0x4E] != 0)) {
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
            *(unsigned short *)(dst + 0x24) = (unsigned short)normalized;
            dst[0x26] = current[0x26];
            dst += 0x28;
        }
    }
    *(int *)((char *)arg0 + 4) = (dst - *(unsigned char * volatile *)arg0) / 0x28;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028D728(void) {
    /* Recompute totals for each group entry by compacting/updating its items. */
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
                *((unsigned int *)&raw + 1) = *(unsigned short *)((char *)item + 0x24);
                fn_801E53A8(item, (char *)item + 0xC, (char *)item + 0x18, *((unsigned char *)item + 0x26) != 0, (float)(raw - bias) * scale);
            }
            offset += 0x28;
            inner++;
        }
        outerOffset += 0xC;
        outer++;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float lbl_80564400;
extern float lbl_80564404;
extern float lbl_80564408;
extern float lbl_8056440C;
extern float lbl_80564410;
extern void PSVECCrossProduct(void *, void *, void *);
void fn_8028D89C(void *arg0, int arg1, float arg2) {
    void *base;
    unsigned char *entry;
    int idx, kind, key;
    int *state;
    unsigned char *group;
    void *p;
    void *g;
    unsigned char *item;
    float cross[3];
    float t;
    int i;
    base = *(void **)arg0;
    entry = (unsigned char *)base + arg1 * 0x3c;
    idx = arg1 + *(int *)((unsigned char *)arg0 + 4) * 4;
    state = (int *)((unsigned char *)&lbl_8055F720 + idx * 8);
    kind = *(int *)(entry + 0xa8);
    if (kind >= 8) goto clear;
    key = ((int *)&lbl_804B3470)[kind];
    if (key < 0) goto clear;
    group = (unsigned char *)&lbl_804B3400 + key * 0x1c;
    if (!(*(unsigned char *)(entry + 0xa0))) goto clear;
    if (!(*(float *)(entry + 0x98) > *(float *)(group + 0xc))) goto clear;
    if (state[0] == key && arg2 > lbl_80564400 + *(float *)(state + 1)) {
        p = *(void **)(group + 0x14);
        g = (unsigned char *)p + idx * 0xc;
        item = (unsigned char *)*(void **)g + *(int *)((unsigned char *)g + 4) * 0x28;
        *(float *)(item + 0) = *(float *)(entry + 0x7c);
        *(float *)(item + 4) = *(float *)(entry + 0x80);
        *(float *)(item + 8) = *(float *)(entry + 0x84);
        *(float *)(item + 0xc) = *(float *)((unsigned char *)base + 0x34) * lbl_80564404;
        *(float *)(item + 0x10) = *(float *)((unsigned char *)base + 0x38) * lbl_80564404;
        *(float *)(item + 0x14) = *(float *)((unsigned char *)base + 0x3c) * lbl_80564404;
        PSVECCrossProduct((unsigned char *)base + 0x40, entry + 0x88, cross);
        t = (*(int *)(entry + 0x9c) & 8) ? lbl_8056440C : lbl_80564408;
        *(float *)(item + 0x18) = cross[0] * t;
        *(float *)(item + 0x1c) = cross[1] * t;
        *(float *)(item + 0x20) = cross[2] * t;
        t = *(float *)(entry + 0x98);
        if (lbl_805643F0 > *(float *)(group + 0xc)) t -= lbl_805643F0;
        else t -= *(float *)(group + 0xc);
        i = (int)(lbl_80564410 * (*(float *)(group + 4) + *(float *)(group + 8) * t));
        if (i < 0) i = 0;
        *(unsigned short *)(item + 0x24) = i;
        *(unsigned char *)(item + 0x26) = 1;
        *(int *)((unsigned char *)*(void **)g + 4) = *(int *)((unsigned char *)*(void **)g + 4) + 1;
        *(int *)(group + 0x18) = *(int *)(group + 0x18) + 1;
        *(float *)(state + 1) = arg2;
        state[0] = key;
        return;
    } else {
        p = *(void **)(group + 0x14);
        g = (unsigned char *)p + idx * 0xc;
        if (state[0] == key) {
            item = (unsigned char *)*(void **)g + (*(int *)((unsigned char *)g + 4) - 1) * 0x28;
            *(float *)(item + 0) = *(float *)(entry + 0x7c);
        } else {
            item = (unsigned char *)*(void **)g + *(int *)((unsigned char *)g + 4) * 0x28;
            *(float *)(item + 0) = *(float *)(entry + 0x7c);
        }
        *(float *)(item + 4) = *(float *)(entry + 0x80);
        *(float *)(item + 8) = *(float *)(entry + 0x84);
        *(float *)(item + 0xc) = *(float *)((unsigned char *)base + 0x34) * lbl_80564404;
        *(float *)(item + 0x10) = *(float *)((unsigned char *)base + 0x38) * lbl_80564404;
        *(float *)(item + 0x14) = *(float *)((unsigned char *)base + 0x3c) * lbl_80564404;
        PSVECCrossProduct((unsigned char *)base + 0x40, entry + 0x88, cross);
        t = (*(int *)(entry + 0x9c) & 8) ? lbl_8056440C : lbl_80564408;
        *(float *)(item + 0x18) = cross[0] * t;
        *(float *)(item + 0x1c) = cross[1] * t;
        *(float *)(item + 0x20) = cross[2] * t;
        t = *(float *)(entry + 0x98);
        if (lbl_805643F0 > *(float *)(group + 0xc)) t -= lbl_805643F0;
        else t -= *(float *)(group + 0xc);
        i = (int)(lbl_80564410 * (*(float *)(group + 4) + *(float *)(group + 8) * t));
        if (i < 0) i = 0;
        *(unsigned short *)(item + 0x24) = i;
        if (state[0] != key) {
            *(unsigned char *)(item + 0x26) = 0;
            {
                unsigned char *next = item + 0x28;
                *(float *)(next + 0) = *(float *)(item + 0);
                *(float *)(next + 4) = *(float *)(item + 4);
                *(float *)(next + 8) = *(float *)(item + 8);
                *(float *)(next + 0xc) = *(float *)(item + 0xc);
                *(float *)(next + 0x10) = *(float *)(item + 0x10);
                *(float *)(next + 0x14) = *(float *)(item + 0x14);
                *(float *)(next + 0x18) = *(float *)(item + 0x18);
                *(float *)(next + 0x1c) = *(float *)(item + 0x1c);
                *(float *)(next + 0x20) = *(float *)(item + 0x20);
                *(unsigned short *)(next + 0x24) = *(unsigned short *)(item + 0x24);
                *(unsigned char *)(next + 0x26) = 1;
                *(int *)((unsigned char *)*(void **)g + 4) = *(int *)((unsigned char *)*(void **)g + 4) + 2;
                *(int *)(group + 0x18) = *(int *)(group + 0x18) + 2;
            }
        } else {
            *(int *)((unsigned char *)*(void **)g + 4) = *(int *)((unsigned char *)*(void **)g + 4) + 1;
            *(int *)(group + 0x18) = *(int *)(group + 0x18) + 1;
        }
        state[0] = key;
        return;
    }
clear:
    state[0] = -1;
}
#pragma pop

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
