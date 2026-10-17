// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F93C;
extern int lbl_8055F940;
extern int lbl_8055F944;
extern int lbl_8055F948;
extern signed char lbl_8055F94C;
extern const char lbl_8055CC88[];
extern int fn_802E2C20(void);
extern int sscanf(const char *, ...);
extern void fn_802AC344(void);
int fn_802AC174(const char *arg0) {
    int sp8;
    sp8 = 0;
    if (sscanf(arg0, &lbl_8055CC88, &sp8) == 1) return sp8;
    return -1;
}

int fn_802AC2B4(void **arg0, int arg1, float *arg2) {
    void *vtable;
    int (*check)(void *);
    float (*value)(void *, int);
    if (arg0 == 0) return 0;
    vtable = *arg0;
    check = *(int (**)(void *))((char *)vtable + 0xC);
    if (check(vtable) == 0) return 0;
    if (arg2 == 0) return 1;
    vtable = *arg0;
    value = *(float (**)(void *, int))((char *)vtable + 0x24);
    *arg2 = value(*arg0, arg1);
    return 1;
}

void fn_802AC454(void) { fn_802AC344(); }

void fn_802AC458(void) {
    lbl_8055F93C = 0;
    lbl_8055F944 = fn_802E2C20();
    lbl_8055F948 = 0;
    lbl_8055F940 = 0;
    lbl_8055F94C = 1;
}

void fn_802AC49C(void) {
    lbl_8055F93C = 0;
}

extern float lbl_80564ACC;
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FA4[];
extern void *fn_801284F8(int, void *, void *);
extern void *fn_8012850C(int, void *);
extern int fn_802AC4A8(const char *, int);
void fn_802AD308(void) {}

void fn_802AD414(void *arg0, float farg0) {
    int outer = 0;
    int offset = 0;
    while (outer < *(int *)((char *)arg0 + 0x24)) {
        int inner = 0;
        int byteOffset = 0;
        char *group = *(char **)((char *)arg0 + 0x28) + offset;
        int count = *(int *)(group + 4) - 1;
        if (count > 0) {
            do {
                char *entries = *(char **)(group + 8);
                float a = *(float *)(entries + byteOffset);
                char *entry = entries + byteOffset;
                float b = *(float *)(entries + (inner + 1) * 0x38);
                if (farg0 >= a && farg0 <= lbl_80564ACC + b) {
                    int idx = *(int *)group;
                    char *records = *(char **)((char *)arg0 + 0x20);
                    char *record = records + idx * 0x28;
                    int *p = *(int **)(record + 4);
                    if (p) *p = *(int *)(entry + 0x34);
                    break;
                }
                byteOffset += 0x38;
                inner++;
            } while (--count != 0);
        }
        offset += 0xC;
        outer++;
    }
}

void *fn_802ADDD8(void *arg0, int arg1) {
    int *obj = (int *)fn_801284F8(0x10, &lbl_80349FA4, &lbl_80349FA4);
    if (obj) {
        int data = (int)fn_8012850C(arg1 * 0x74, &lbl_8055CD70);
        obj[0] = data;
        obj[2] = arg1;
        obj[1] = 0;
        obj[3] = data;
    }
    *(int **)arg0 = obj;
    *(float *)((char *)arg0 + 4) = lbl_8055E3C8;
    return arg0;
}

