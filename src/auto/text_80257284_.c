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
extern char lbl_80344CD4[];
extern int lbl_80344CF0;
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
    // Fix note: use the project's MenuEntry field order and the full object workspace in the stack frame.
    typedef struct { int v[5]; } Header;
    typedef struct { int label; int type; int value; int flags; int id; } Entry;
    typedef struct { Header header; Entry entries[9]; int object[0x74]; } Frame;
    Frame frame;
    int result;

    if (fn_80247624()) { fn_80012794(); fn_80012780(); }
    fn_80257470(frame.object);

    frame.entries[0].label = 0;
    frame.entries[0].type = 5;
    frame.entries[0].value = (int)&frame.object[0];
    frame.entries[0].flags = 0;
    frame.entries[0].id = 0;
    frame.entries[1].label = (int)&lbl_8055C1D8;
    frame.entries[1].type = 13;
    frame.entries[1].value = (int)&frame.object[0];
    frame.entries[1].flags = 0;
    frame.entries[1].id = 0;
    frame.entries[2].label = (int)&lbl_8055C1E0;
    frame.entries[2].type = 13;
    frame.entries[2].value = (int)&frame.object[7];
    frame.entries[2].flags = 0;
    frame.entries[2].id = 0;
    frame.entries[3].label = (int)&lbl_8055C1E8;
    frame.entries[3].type = 13;
    frame.entries[3].value = (int)&frame.object[21];
    frame.entries[3].flags = 0;
    frame.entries[3].id = 0;
    frame.entries[4].label = (int)&lbl_8055C1F0;
    frame.entries[4].type = 13;
    frame.entries[4].value = (int)&frame.object[99];
    frame.entries[4].flags = 1;
    frame.entries[4].id = 0;

    fn_8000DA10((int)&frame.object[99], (int)&frame.object[21],
                (int)&frame.object[7], 13,
                &lbl_8055C1D8, &lbl_8055C1E0, &lbl_8055C1E8, &lbl_8055C1F0);
    result = fn_8000DB34();
    frame.entries[5].value = result;

    frame.header.v[0] = *(int *)&lbl_802FA5E0;
    frame.header.v[1] = (int)frame.entries;
    frame.header.v[2] = *(int *)((char *)&lbl_802FA5E0 + 8);
    frame.header.v[3] = *(int *)((char *)&lbl_802FA5E0 + 12);
    frame.header.v[4] = *(int *)((char *)&lbl_802FA5E0 + 16);
    frame.entries[5].label = (int)&lbl_80344CD4;
    frame.entries[5].type = 3;
    frame.entries[5].flags = 0;
    frame.entries[5].id = 0;
    frame.entries[6].label = (int)&lbl_8055B860;
    frame.entries[6].type = 6;
    frame.entries[6].value = 0;
    frame.entries[6].flags = -1;
    frame.entries[6].id = 0x1B;
    frame.entries[7].label = (int)&lbl_8055BAB8;
    frame.entries[7].type = 8;
    frame.entries[7].value = (int)fn_80236914;
    frame.entries[7].flags = 2;
    frame.entries[7].id = 0;
    frame.entries[8].label = *(int *)&lbl_80498E38;
    frame.entries[8].type = *(int *)((char *)&lbl_80498E38 + 4);
    frame.entries[8].value = *(int *)((char *)&lbl_80498E38 + 8);
    frame.entries[8].flags = *(int *)((char *)&lbl_80498E38 + 12);
    frame.entries[8].id = *(int *)((char *)&lbl_80498E38 + 16);

    if (fn_802146BC((int *)&frame.header, -999, -999, 1) == -1) {
        if (fn_80247624()) { fn_80012794(); fn_80012778(); }
    }
    fn_802574E0((int)frame.object, -1);
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
