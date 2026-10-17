// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E160;
extern int lbl_802F9350[3];
extern char lbl_8042F858[];
extern int lbl_802F9360[];
extern char lbl_8032C374[];
extern char lbl_8032C364[];
extern float lbl_80561434;
extern float lbl_80561440;
extern float lbl_80561448;
extern float lbl_80561460;
extern float lbl_80559C98;
extern char lbl_8055E161;
extern float fn_80134B58(float *, float);
extern float fn_8013B5DC(int, int);
extern int fn_80028E00(char *, int);
extern int fn_8013A6D4(int);
extern int fn_802E317C(char *, ...);
extern char lbl_8032C1A0[];
typedef struct { int pad[3]; int (*m_fn)(void); } unkVtable;
void fn_8013A660(unkVtable **arg0, char *arg1, char *arg2) {
    int result;
    result = (*arg0)->m_fn();
    if (result == 0) {
        fn_802E317C(lbl_8032C1A0, arg2, arg1);
    }
}

int fn_8013A6C4(void *arg0, void *arg1) {
    return *(int *)((char *)arg0 + 8) - *(int *)((char *)arg1 + 8);
}

int fn_8013A6D4(int arg0) {
    int values[3];
    int *p = lbl_802F9350;
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[arg0];
}

char *fn_8013A708(char *arg0, int arg1, int arg2) {
    strcpy(arg0, (char *)fn_8013A6D4(arg1));
    fn_80028E00(arg0, arg2);
    return arg0;
}

int fn_8013A860(float *arg0, unkVtable **arg1) {
    int result = (*arg1)->m_fn();
    if (result != 0) {
        arg0[0] = ((float (*)(void))(*arg1)->m_fn)();
        arg0[1] = ((float (*)(void))(*arg1)->m_fn)();
    }
    return result;
}

extern void *fn_8001285C(int);
extern void *fn_80012820(int);
extern int fn_8013A760(unkVtable **, int);
extern void fn_8013A7E8(unkVtable **, char *, char *);
extern float fn_8013A90C(void *, int, int, float);
extern void fn_8013B6C0(int *, float *, int);
extern char lbl_8032C264[];
float fn_8013AA68(void *, void *, void *, void *);
void fn_8013AC2C(int *arg0) {
    void *p = fn_80012820(*(int *)((char *)fn_8001285C(*arg0) + 4));
    void *obj = *(void **)((char *)p + 0x80);
    ((void (*)(void *, char *, float))(*(void ***)obj)[10])(obj, lbl_8032C264, lbl_80561440);
}

void DBPrintf_8013B490(const char *fmt, ...) {
#pragma unused(fmt)
}

void fn_8013B56C(void) {
    lbl_8055E160 = 0;
}

void *fn_8013B578(int arg0) {
    char *base = lbl_8042F858;
    int offset = arg0 * 8;
    return base + offset + 8;
}

float fn_8013B650(int arg0) {
    float temp = fn_80134B58((float *)lbl_8032C364, lbl_80561434);
    return fn_8013B5DC(arg0, 3) + temp;
}

void fn_8013B6A4(int arg0, float arg1) {
    char *p = lbl_8042F858 + arg0 * 8;
    *(float *)(p + 0xC) = arg1;
    *(float *)(p + 8) = arg1;
}

extern int lbl_802F9360[];
extern char lbl_8032C374[];
extern char lbl_8032C364[];
extern float lbl_80561434;
extern float lbl_80561440;
extern float lbl_80561460;
extern float lbl_80559C98;
extern char lbl_8055E161;
extern float fn_80134B58(float *, float);
extern float fn_8013B5DC(int, int);
extern void *fn_8013B578(int);
void fn_8013B6C0(int *arg0, float *arg1, int arg2) {
    char *p = (char *)lbl_802F9360;
    p += arg2 * 8;
    if (arg2 <= 4) {
        *arg0 = *(int *)p;
        *arg1 = *(float *)(p + 4);
    } else {
        fn_802E317C(lbl_8032C374, arg2);
        *arg0 = 0;
        *arg1 = lbl_80561434;
    }
}

float fn_8013B744(int arg0) {
    if (lbl_8055E161 != 0) {
        return lbl_80561440 - lbl_80561460 * (float)arg0;
    }
    return *(float *)((char *)fn_8013B578(arg0) + 4) * lbl_80559C98;
}

