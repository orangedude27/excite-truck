// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
__declspec(section ".data") extern int lbl_804B3400;
extern int lbl_8055F728;
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
    int value;
    void **vtable = *(void ***)arg1;
    ((void (*)(void *, const char *))vtable[5])(arg1, lbl_8055C8C8);
    *(int *)arg0 = fn_802CAC28(0);
    *(float *)((char *)arg0 + 4) = ((float (*)(void *, char *))vtable[9])(arg1, lbl_80348C50);
    *(float *)((char *)arg0 + 8) = ((float (*)(void *, char *))vtable[9])(arg1, lbl_80348C50 + 0xC);
    *(float *)((char *)arg0 + 0xC) = ((float (*)(void *, char *))vtable[9])(arg1, lbl_80348C50 + 0x18);
    value = ((int (*)(void *, char *))vtable[7])(arg1, lbl_80348C50 + 0x24);
    *(int *)((char *)arg0 + 0x10) = value;
    if (value < 8 || value > 0x24)
        fn_802E317C(lbl_80348C50 + 0x30, value);
}

extern int lbl_804B3470;
extern char lbl_80348CA0[];
extern int lbl_8055C8D0;
extern int fn_801345D8(void *, int, const void *, int);
extern void *fn_802AE414(void *);
extern void fn_8028D084(void *, void *);
#pragma dont_inline on
int fn_8028D17C(void) {
    int i;
    int temp;
    int invalid;
    int *slot;
    char *base;
    void *obj;

    lbl_8055F728 = 0;
    slot = &lbl_804B3470;
    base = (char *)&lbl_804B3400;
    i = 0;
    invalid = -1;
    for (; i < 8; i++) {
        fn_801345D8(&temp, 0x20, &lbl_80348CA0, i);
        obj = fn_802AE414(&temp);
        if (obj != 0) {
            obj = ((void *(*)(void *, void *))(((void **)*(void **)obj)[23]))(obj, &lbl_8055C8D0);
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
    unsigned char *base = *(unsigned char **)arg0;
    unsigned int count = *(unsigned int *)((char *)arg0 + 4);
    unsigned int start_index = count - *(unsigned int *)((char *)arg0 + 8) + 2;
    unsigned char *end = base + count * 0x28;
    unsigned char *start = base + ((start_index & (-(int)start_index >> 31)) * 0x28);
    unsigned int n = (unsigned int)(end + 0x27 - start) / 0x28;
    unsigned char *src = start;
    unsigned char *dst = base;
    while (src < end) {
        if (src[0x26] != 0 &&
            (*(unsigned short *)(src + 0x24) >= 0x100 ||
             *(unsigned short *)(src - 4) >= 0x100 ||
             src + 0x28 >= end ||
             (src[0x4E] != 0 && *(unsigned short *)(src + 0x4C) >= 0x100)))
            src[0x26] = 1;
        else
            src[0x26] = 0;
        src += 0x28;
    }
    src = start;
    while (src < end) {
        if (src[0x26] != 0 || (src + 0x28 < end && src[0x4E] != 0)) {
            int v;
            int x;
            float f;
            f = *(float *)(src + 0); *(float *)(dst + 0) = f;
            f = *(float *)(src + 4); *(float *)(dst + 4) = f;
            f = *(float *)(src + 8); *(float *)(dst + 8) = f;
            f = *(float *)(src + 0xC); *(float *)(dst + 0xC) = f;
            f = *(float *)(src + 0x10); *(float *)(dst + 0x10) = f;
            f = *(float *)(src + 0x14); *(float *)(dst + 0x14) = f;
            f = *(float *)(src + 0x18); *(float *)(dst + 0x18) = f;
            f = *(float *)(src + 0x1C); *(float *)(dst + 0x1C) = f;
            f = *(float *)(src + 0x20); *(float *)(dst + 0x20) = f;
            v = *(unsigned short *)(src + 0x24) - 0x80;
            x = v < 0 ? -v : v;
            *(unsigned short *)(dst + 0x24) = (unsigned short)(v & (v < 0 ? -1 : 0));
            dst[0x26] = src[0x26];
            dst += 0x28;
        }
        src += 0x28;
    }
    *(unsigned int *)((char *)arg0 + 4) = (dst - base) / 0x28;
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
void fn_8028D7C0(int arg0) {
    float scale;
    int outer;
    int inner;
    int offset;
    int outerOffset;
    int *table;
    int *group;
    int *item;

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
            fn_801E53A8(item, (char *)item + 0xC, (char *)item + 0x18,
                        *((unsigned char *)item + 0x26) != 0,
                        scale * (float)*(unsigned short *)((char *)item + 0x24));
            offset += 0x28;
            inner++;
        }
        outerOffset += 0xC;
        outer++;
    }
}

