// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
extern int lbl_804B3400;
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
extern void fn_8028DDF0(void);
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

extern int lbl_804B3400;
extern int lbl_8055F728;
extern void fn_802CAC54(int);
void fn_8028D25C(void) {
    int *ptr = (int *)((char *)&lbl_804B3400);
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

