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
extern char lbl_8032C1E8[];
extern char lbl_8032C1F8[];
extern void *fn_8001285C(int);
extern void *fn_80012820(int);
extern float lbl_80561438;
extern float lbl_8056143C;
extern char lbl_80559CB8[];
extern char lbl_80559CBC[];
extern int fn_8013A9C0(void *, void *, void *, void *);
extern int fn_8027AA48(void);
extern void fn_802E30C8(char *, ...);
extern float fn_8013AA68(void *, void *, void *, void *);
typedef struct { int pad[3]; int (*m_fn)(void); } unkVtable;
typedef struct { int pad[7]; int (*m_fn)(void); } unkVtable7;
typedef struct { int pad[9]; float (*m_float)(char *); } unkVtableFloat;
void fn_8013A660(unkVtable **arg0, char *arg1, char *arg2) {
    int result = ((int (*)(void *))(*arg0)->m_fn)(arg0);
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

#pragma push
#pragma inline_depth(0)
char *fn_8013A708(char *arg0, int arg1, int arg2) {
    strcpy(arg0, (char *)fn_8013A6D4(arg1));
    fn_80028E00(arg0, arg2);
    return arg0;
}
#pragma pop

#pragma dont_inline fn_8013A708
int fn_8013A760(unkVtable **arg0, int arg1) {
    char buffer[0x20];
    int i = 0;
    do {
        char *name = ((char *(*)(char *, int, int))fn_8013A708)(buffer, i, arg1);
        if (((int (*)(unkVtable *, char *))(*arg0)->m_fn)(*arg0, name) != 0)
            return 1;
        i++;
    } while (i < 3);
    return 0;
}
#pragma push
#pragma scheduling invalid_target
void fn_8013A7E8(unkVtable **arg0, char *arg1, char *arg2) {
    char buffer[0x20];
    int i = 0;
    do {
        char *name = ((char *(*)(char *, int, int))fn_8013A708)(buffer, i, (int)arg1);
        ((void (*)(unkVtable **, char *, char *))fn_8013A660)(arg0, name, arg2);
        i++;
    } while (i < 3);
}
#pragma pop
extern char lbl_8032C1E8[];
extern char lbl_8032C1F8[];
#pragma cplusplus on
extern "C" int fn_8013A860(float *arg0, void *arg1) {
    class LocalVtable {
    public:
        virtual void v1();
        virtual int check(char *);
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float get(char *);
    };
    int result = ((LocalVtable *)arg1)->check(lbl_8032C1E8);
    if (result != 0) {
        arg0[0] = ((LocalVtable *)arg1)->get(lbl_8032C1F8);
        arg0[1] = ((LocalVtable *)arg1)->get(lbl_8032C1E8);
    }
    return result;
}

#pragma cplusplus on
extern "C" float fn_8013A90C(void *arg0, int arg1, int arg2, float arg3) {
    class LocalVtable {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float get(char *);
    };
    char sp28[0x20];
    char sp8[0x20];
    float temp_f1;
    float temp_f31;
    temp_f31 = ((LocalVtable *)arg0)->get(
        ((char *(*)(char *, int, int))fn_8013A708)(sp8, arg2 + 1, arg1));
    temp_f1 = ((LocalVtable *)arg0)->get(
        ((char *(*)(char *, int, int))fn_8013A708)(sp28, arg2, arg1));
    return temp_f1 + arg3 * (temp_f31 - temp_f1);
}
#pragma cplusplus off

#pragma cplusplus off
extern void *fn_8001285C(int);
extern void *fn_80012820(int);
extern int fn_8013A760(unkVtable **, int);
extern void fn_8013A7E8(unkVtable **, char *, char *);
extern float fn_8013A90C(void *, int, int, float);
extern void fn_8013B6C0(int *, float *, int);
extern char lbl_8032C264[];
float fn_8013AA68(void *, void *, void *, void *);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8013AC2C(register int *arg0) {
    /* Resolve the object handle and dispatch the virtual callback at offset 0x28. */
    struct Target {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8(char *, float);
    };
    void *parent = fn_80012820(*(int *)((char *)fn_8001285C(*arg0) + 4));
    Target *object = *(Target **)((char *)parent + 0x80);
    object->f8(lbl_8032C264, lbl_80561440);
}
#pragma cplusplus off
#pragma scheduling on
void DBPrintf_8013B490(const char *fmt, ...) {
#pragma unused(fmt)
}

extern void fn_8013AC78(int, int *);
extern void fn_802049DC(int, int, float, float, float);
extern char lbl_8032C358[];
extern float lbl_80561450;
extern float lbl_80561454;
extern float lbl_80561438;
void fn_8013B4E0(void *arg0) {
    int sp8[10];
    char *src = (char *)arg0;
    int *dst = sp8;
    int i = 0;
    int value;
    while (i < *(int *)((char *)arg0 + 0x3C0)) {
        value = *(int *)(src + 0x68);
        src += 0x78;
        i++;
        *dst = value;
        dst++;
    }
    fn_8013AC78(0, sp8);
    lbl_80559C98 = lbl_80561440;
    fn_802049DC((int)(void *)lbl_8032C358, (int)(void *)&lbl_80559C98,
                lbl_80561450, lbl_80561454, lbl_80561438);
    lbl_8055E160 = 1;
    lbl_8055E161 = 0;
}

void fn_8013B56C(void) {
    lbl_8055E160 = 0;
}

#pragma scheduling invalid_target
void *fn_8013B578(int arg0) {
    register char *base = lbl_8042F858;
    register int offset = arg0 * 8;
    return base + offset + 8;
}
#pragma scheduling on
extern void **fn_801B2ED0(void);
extern void *fn_80138B1C(int);
extern float lbl_80561430;
#pragma cplusplus on
extern "C" float fn_8013B590(void) {
    void *object = *fn_801B2ED0();
    int value = ((int (*)(void *))((void **)object)[7])(object);
    void *result = fn_80138B1C(*(int *)((char *)value + 0x2C));
    if (result != 0)
        return *(float *)((char *)result + 0xC);
    return lbl_80561430;
}
#pragma cplusplus off
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
    if (arg2 <= 4) {
        *arg0 = lbl_802F9360[arg2 * 2];
        *arg1 = *(float *)((char *)lbl_802F9360 + arg2 * 8 + 4);
    } else {
        fn_802E317C(lbl_8032C374, arg2);
        {
            float fallback = lbl_80561434;
            *arg0 = 0;
            *arg1 = fallback;
        }
    }
}

#pragma dont_inline on
float fn_8013B744(int arg0) {
    if ((unsigned char)lbl_8055E161 != 0) {
        return lbl_80561440 - lbl_80561460 * (float)arg0;
    }
    return *(float *)((char *)fn_8013B578(arg0) + 4) * lbl_80559C98;
}
#pragma dont_inline reset
