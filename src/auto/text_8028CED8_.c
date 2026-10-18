// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
extern int lbl_804B3400;
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
extern float lbl_80558DC4;
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
    if (lbl_8055F714 != 0 && __fabsf(fn_801E7E24()) >= lbl_80558DC4) {
        fn_8028D728();
    }
}

void fn_8028CFB0(void) {
    int *entry;
    int i;
    float time;
    float scale;
    if (lbl_8055F714 != 0) {
        time = fn_802C9A4C(lbl_8055F710);
        fn_802C9648(lbl_805643E8);
        entry = &lbl_804B3400;
        scale = lbl_805643EC;
        i = 0;
        do {
            if (entry[6] > 1) {
                fn_802C8BD0(entry[0]);
                if (fn_801E5370(entry[6], 4, scale * fn_801E88F0(-1)) != 0) {
                    fn_8028D7C0(i);
                    fn_801E58FC();
                }
                fn_802C8D74();
            }
            entry = (int *)((char *)entry + 0x1C);
            i++;
        } while (i < lbl_8055F728);
        fn_802C967C();
        fn_802C9A4C(time);
    }
}

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
extern int lbl_80348CA0;
extern int lbl_8055C8D0;
extern int fn_801345D8(void *, int, const void *, int);
extern void *fn_802AE414(void *);
extern void fn_8028D084(void *, void *);
int fn_8028D17C(void) {
    int i = 0;
    int *slot = &lbl_804B3470;
    lbl_8055F728 = 0;
    do {
        int temp;
        void *obj;
        fn_801345D8(&temp, 0x20, &lbl_80348CA0, i);
        obj = fn_802AE414(&temp);
        if (obj != 0) {
            void *vtable = *(void **)obj;
            obj = ((void *(*)(void *, int))(*(void **)((char *)vtable + 0x5C)))(obj, lbl_8055C8D0);
        }
        if (obj != 0) {
            fn_8028D084((char *)&lbl_804B3400 + lbl_8055F728 * 0x1C, obj);
            *slot = lbl_8055F728;
            lbl_8055F728++;
        } else {
            *slot = -1;
        }
        i++;
        slot++;
    } while (i < 8);
    return lbl_8055F728 > 0;
}

extern int lbl_804B3400;
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

extern double lbl_805643F8;
extern float lbl_805643F4;
extern void fn_801E53A8(void *, void *, void *, int, float);
void fn_8028D7C0(int arg0) {
    double d;
    float scale;
    int outer;
    int inner;
    int offset;
    int outerOffset;
    int *table;
    int *group;
    int *item;
    d = lbl_805643F8;
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
                        scale * ((float)*(unsigned short *)((char *)item + 0x24) - (float)d));
            offset += 0x28;
            inner++;
        }
        outerOffset += 0xC;
        outer++;
    }
}

