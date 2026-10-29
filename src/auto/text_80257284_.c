// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80257A8C();
void *fn_80257470(void *);
void *fn_8022D850(void *, int, int, int);
void fn_8022D894(void *, int, int, void *, int);
void fn_80257A6C(int *, int, int);
void fn_8022D458(int, int, int *);
void fn_8022D7C4(int, int);
int fn_80128668(int);
extern int lbl_80563AB8;
int fn_8000DB34(void);
int fn_80012778(void);
int fn_80012780(void);
int fn_80012794(void);
int fn_802146BC(int *, int, int, int);
int fn_80247624(void);
extern char lbl_802FA5E0[], lbl_80498E38[];
extern int lbl_80344CD4, lbl_80344CF0;
extern int lbl_80563AA8, lbl_80563AB0;
extern int lbl_8055B860, lbl_8055BAB8, lbl_8055C1D8, lbl_8055C1E0, lbl_8055C1E8, lbl_8055C1F0;
extern void fn_80236914(void);
int fn_80012818(void);
void *fn_80012820(int);
void *fn_80012870(int, int);
char *fn_800081BC(void *);
char *fn_80008188(void *);
extern int stricmp(const char *, const char *);
extern char lbl_8055C1F8[];

#pragma cplusplus on
class MatchDispatch {
public:
    virtual void unused();
    virtual int matches(const char *);
};
#pragma cplusplus reset
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80257284(void) {
    // Fix note: reserve the full 0x2c0 target frame while keeping the global table addresses explicit.
    volatile int local[0xA6];
    register int zero = 0;
    register int other_zero = 0;
    register int table0;
    register int table1;
    register int table2;
    register int table3;
    register int list0;
    register int list1;
    register int list2;
    register int list3;
    register int ptr0;
    register int ptr1;
    register int ptr2;
    register int handler;
    register int count0;
    register int count1;
    register int count2;
    register int count3;
    register int minus_one;
    register int mask;
    int result;

    if (fn_80247624()) { fn_80012794(); fn_80012780(); }
    fn_80257470((int *)&local[50]);

    local[5] = other_zero;
    local[6] = 5;
    local[7] = (int)&local[50];
    local[8] = other_zero;
    local[9] = other_zero;
    local[10] = 13;
    local[11] = (int)&lbl_8055C1D8;
    local[12] = (int)&local[50];
    local[13] = other_zero;
    local[14] = other_zero;
    local[15] = 13;
    local[16] = (int)&lbl_8055C1E0;
    local[17] = (int)&local[57];
    local[18] = other_zero;
    local[19] = other_zero;
    local[20] = 13;
    local[21] = (int)&lbl_8055C1E8;
    local[22] = (int)&local[71];
    local[23] = other_zero;
    local[24] = other_zero;
    local[25] = 13;
    local[26] = (int)&lbl_8055C1F0;
    local[27] = (int)&local[149];
    local[28] = 1;
    local[29] = other_zero;

    fn_8000DA10((int)&local[149], (int)&local[71], (int)&local[57], 13,
                &lbl_8055C1D8, &lbl_8055C1E0, &lbl_8055C1E8, &lbl_8055C1F0);
    result = fn_8000DB34();

    table0 = *(int *)&lbl_802FA5E0;
    table1 = *(int *)((char *)&lbl_802FA5E0 + 8);
    table2 = *(int *)((char *)&lbl_802FA5E0 + 12);
    table3 = *(int *)((char *)&lbl_802FA5E0 + 16);
    list0 = *(int *)&lbl_80498E38;
    list1 = *(int *)((char *)&lbl_80498E38 + 4);
    list2 = *(int *)((char *)&lbl_80498E38 + 8);
    list3 = *(int *)((char *)&lbl_80498E38 + 12);
    ptr0 = (int)&lbl_80344CD4;
    ptr1 = (int)&lbl_8055B860;
    ptr2 = (int)&lbl_8055BAB8;
    handler = (int)&fn_80236914;
    count0 = 3;
    count1 = 6;
    count2 = 8;
    count3 = 2;
    minus_one = -1;
    mask = 0x1b;
    zero = 0;

    local[0] = table0;
    local[1] = (int)&local[5];
    local[2] = table1;
    local[3] = table2;
    local[4] = table3;
    local[30] = ptr0;
    local[31] = count0;
    local[32] = result;
    local[33] = zero;
    local[34] = other_zero;
    local[35] = ptr1;
    local[36] = count1;
    local[37] = other_zero;
    local[38] = minus_one;
    local[39] = mask;
    local[40] = ptr2;
    local[41] = count2;
    local[42] = handler;
    local[43] = count3;
    local[44] = other_zero;
    local[45] = list0;
    local[46] = list1;
    local[47] = list2;
    local[48] = list3;
    local[49] = *(int *)((char *)&lbl_80498E38 + 16);

    fn_802146BC((int *)&local[0], -999, -999, 1);
    if (fn_80247624()) { fn_80012794(); fn_80012778(); }
    fn_802574E0((int *)&local[50], minus_one);
}
#pragma pop

#pragma scheduling invalid_target
void *fn_80257470(void *arg0) {
    *(int *)arg0 = (int)&lbl_80344CF0;
    *(int *)((char *)arg0 + 0x14) = 0;
    ((void (*)(int, int, int, int *))fn_8022D458)((int)((char *)arg0 + 0x1C), 0x28, 2, &lbl_80563AA8);
    ((void (*)(int, int, int, int *))fn_8022D458)((int)((char *)arg0 + 0x54), 0x40, 2, &lbl_80563AB0);
    fn_80257B7C((int)((char *)arg0 + 0x18C));
    return arg0;
}
#pragma scheduling on

int fn_802574E0(int arg0, int arg1) { int temp_r3; if (arg0 != 0) { temp_r3 = arg0 + 0x18C; if (temp_r3 != 0) fn_8022D7C4(temp_r3, 0); fn_8022D7C4(arg0 + 0x54, -1); fn_8022D7C4(arg0 + 0x1C, -1); if (arg1 > 0) fn_80128668(arg0); } return arg0; }

#pragma cplusplus on
extern "C" void fn_80257558(void *arg0, void *arg1) {
    int outer;
    int inner;
    int found;
    int index;
    int name;
    int count;
    void *entry;
    char *candidate;

    *(int *)((char *)arg0 + 0x18) = 0;
    outer = 0;
    while (outer < fn_80012818()) {
        entry = fn_80012820(outer);
        found = 0;
        inner = 0;
        do {
            if (((MatchDispatch *)*(void **)((char *)fn_80012870(outer, inner) + 0x20))->matches(lbl_8055C1F8) != 0) {
                found = 1;
            }
            inner++;
        } while (found == 0 && inner < *(int *)((char *)entry + 0x70));
        if (found != 0) {
            name = (int)fn_800081BC((char *)entry + 8);
            found = 0;
            index = 0;
            do {
                candidate = (char *)fn_8022D850((char *)arg0 + 0x1C, index, 1, 0);
                if (stricmp((char *)name, candidate) == 0) {
                    found = 1;
                }
                index++;
            } while (found == 0 && index < *(int *)((char *)arg0 + 0x24));
            if (found == 0) {
                count = *(int *)((char *)arg0 + 0x24);
                fn_8022D894((char *)arg0 + 0x1C, count, 1, (void *)name, 0);
                fn_8022D894((char *)arg0 + 0x1C, count, 0, fn_80008188((char *)entry + 8), 0);
            }
        }
        outer++;
    }
    *(int *)((char *)arg0 + 0x4C) = 0;
    fn_8022D894((char *)arg0 + 0x1C, *(int *)((char *)arg0 + 0x4C), 0,
                fn_8022D850((char *)arg0 + 0x1C, 0, 0, 0), 1);
    *(char *)((char *)arg0 + 0x50) = 1;
}
#pragma cplusplus reset

int fn_80257904(void *arg0, int arg1) {
    char *self = (char *)arg0;
    switch (arg1) {
    case 0x125:
        if (*(int *)(self + 0x18) == 1)
            *(int *)(self + 0x18) = 0;
        goto return_one;
    case 0x127:
        if (*(int *)(self + 0x18) == 0 && *(int *)(self + 0x5C) > 0)
            *(int *)(self + 0x18) = 1;
        goto return_one;
    case 0x126:
    case 0x128:
        switch (*(int *)(self + 0x18)) {
        case 0: {
            int use = (unsigned int)arg1 == 0x128u;
            int value;
            fn_8022D894(self + 0x1C, *(int *)(self + 0x4C), 0,
                        fn_8022D850(self + 0x1C, *(int *)(self + 0x4C), 0, 0), 0);
            value = *(int *)(self + 0x24);
            fn_80257A6C((int *)(self + 0x4C), use ? 1 : -1, value);
            *(char *)(self + 0x50) = 1;
            goto return_one;
        }
        case 1: {
            int use = (unsigned int)arg1 == 0x128u;
            int value;
            fn_8022D894(self + 0x54, *(int *)(self + 0x84), 0,
                        fn_8022D850(self + 0x54, *(int *)(self + 0x84), 0, 0), 0);
            value = *(int *)(self + 0x5C);
            fn_80257A6C((int *)(self + 0x84), use ? 1 : -1, value);
            *(char *)(self + 0x88) = 1;
            goto return_one;
        }
        }
        goto return_one;
    }
    return 0;
return_one:
    return 1;
}

void fn_80257A6C(int *arg0, int arg1, int arg2) { *arg0 = (*arg0 + (arg2 + arg1)) % arg2; }

int fn_8000DA10(void);
int fn_8001BA74(int);
void *fn_8001BA6C(void);
void fn_8001BC38(void *, int, int, int, int);
int fn_8001BCF0(void *);
void *fn_8001BD38(void *, void *, int);
void fn_8022D76C(void);
extern char lbl_80344CE4[];
#pragma dont_inline on
void fn_80257A8C(void *arg0) {
    char sp1C[0x24];
    char sp8[0x14];
    int var_r30;
    int temp_r29;

    fn_8022D76C();
    var_r30 = 0;
    do {
        temp_r29 = fn_8001BA74(var_r30 + 1);
        fn_8022D894(arg0, var_r30, 0, fn_8001BA6C(), 0);
        fn_8001BC38(sp1C, fn_8000DA10(), temp_r29, *(int *)((char *)arg0 + 0x30), 0);
        if (fn_8001BCF0(sp1C) != 0) {
            fn_8022D894(arg0, var_r30, 1, fn_8001BD38(sp1C, sp8, 0x14), 0);
        } else {
            fn_8022D894(arg0, var_r30, 1, &lbl_80344CE4, 0);
        }
        var_r30 += 1;
    } while (var_r30 < 7);
}
#pragma dont_inline reset

#pragma scheduling invalid_target
int fn_80257B7C(int arg0) { ((int (*)(int, int, int, int *))fn_8022D458)(arg0, 7, 2, &lbl_80563AB8); return arg0; }
#pragma scheduling on

void fn_80257BB8(void *arg0, int arg1) { *(int *)((char *)arg0 + 0x30) = arg1; fn_80257A8C(arg0); }
