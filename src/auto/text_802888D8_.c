__declspec(section ".data") extern int lbl_80348AE8;
extern int fn_8028E61C(int *);
extern int fn_8028E2F8(int *, int *, int, int, float, float, float, float, float, float, float);
extern float fn_801E7E24(void);
__declspec(section ".data") extern int lbl_80348B24;
extern float lbl_80564274, lbl_80564280, lbl_80564284, lbl_80564288, lbl_8056428C, lbl_8056429C;
extern float lbl_805642A4, lbl_805642B0, lbl_805642C8, lbl_805642F4, lbl_805642F8;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    float sp8, spC, sp10, sp14, sp18, sp1C;
    int sp20, sp24;
    float sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    float sp48, sp4C;
    float sp50, sp54;
    char pad50[0xC];
    int sp64;
    float sp68;
    char pad64[4];
          float sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94;
      float sp98, sp9C;
      char tail[0x18];
} fn_802897E0Frame;

typedef struct {
    float sp8, spC, sp10, sp14, sp18, sp1C;
    int sp20, sp24;
    float sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    float sp48, sp4C;
    float sp50, sp54;
    char pad50[0xC];
    int sp64;
    float sp68;
    char pad64[4];
    float sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94;
    float sp98, sp9C;
    char tail[8];
} fn_80289394Frame;

extern int lbl_8055F6DC;
extern int lbl_8055C880;
extern float lbl_80564280, lbl_8056428C, lbl_8056429C, lbl_805642A4, lbl_805642BC, lbl_805642C0, lbl_805642C4, lbl_805642C8, lbl_805642D4, lbl_805642D8, lbl_805642DC, lbl_805642E0, lbl_805642E4, lbl_805642E8, lbl_805642EC;
extern char lbl_80348B10[];
extern char lbl_80348B6C[];
extern char lbl_80348AFC[];
extern float lbl_8056427C, lbl_80564294, lbl_805642B4, lbl_805642B8, lbl_805642CC, lbl_805642D0;
extern float lbl_80564298, lbl_80564284, lbl_805642AC, lbl_805642B0, lbl_80564300, lbl_80564314, lbl_80564318, lbl_8056431C, lbl_80564320, lbl_80564324;
extern void *lbl_8055F6E0;
extern int lbl_8055F6E4;
extern int fn_80289554(int);
extern int fn_80289F54(int);
extern int fn_80287B5C(void);
extern int fn_80287B14(void);
extern int fn_8028A330(int *, int);
extern int fn_8028E398(int);
extern int fn_80128668(void *);
extern void *fn_80288B88(void *, int);
extern void *fn_80289EE0(void *, int);
extern void *__dt__12PhysicsWorldFv_80289C20(void *, int);
extern void *__dt__Q210JASDrumSet5TPercFv_802894F4(void *, int);
extern void fn_80289084();
extern int fn_80289154(int);
extern int fn_80289268(int);
extern int fn_80289394(int);
extern void *fn_801284F8(int, void *);
extern int fn_80287B38(void *);
extern int lbl_8055F6D8;
extern char lbl_80348A90[];
extern void fn_80288A74(void **, int);
void fn_802888D8(void) {
    int r3;
    int r0;
    char *data = lbl_80348A90;
    r3 = (int)fn_801284F8(0x6c, data + 0xc);
    if (r3) r3 = fn_80288B40(r3);
    lbl_8055F6D8 = r3;
    r3 = (int)fn_801284F8(8, data + 0x20);
    if (r3) r3 = fn_80289BE8(r3);
    lbl_8055F6E0 = (void *)r3;
    r3 = (int)fn_801284F8(0xa8, data + 0x30);
    if (r3) r3 = fn_802894B4(r3);
    lbl_8055F6DC = r3;
    r3 = (int)fn_801284F8(8, data + 0x44);
    r0 = r3;
    if (r3) r0 = fn_80289EA0(r3);
    lbl_8055F6E4 = r0;
    fn_80287B38(fn_80288A74);
}

void fn_80288988(void) {
    fn_80289EE0((void *)lbl_8055F6E4, 1);
    lbl_8055F6E4 = 0;
    __dt__12PhysicsWorldFv_80289C20(lbl_8055F6E0, 1);
    lbl_8055F6E0 = 0;
    __dt__Q210JASDrumSet5TPercFv_802894F4((void *)lbl_8055F6DC, 1);
    lbl_8055F6DC = 0;
    fn_80288B88((void *)lbl_8055F6D8, 1);
    lbl_8055F6D8 = 0;
}

void fn_802889F0(void) {
    fn_80289554(lbl_8055F6DC);
    fn_80289F54(lbl_8055F6E4);
}

void fn_80288A1C(void) {}

#pragma push
#pragma peephole off
void fn_80288A20(void) {
    fn_801E7E24();
}
#pragma pop
extern void *lbl_8055F6E0;
extern int fn_8028E584(int, int, int);
void fn_80288A40(int arg0, int arg1) { fn_8028E584(*(int *)((char *)lbl_8055F6E0 + 4), arg0, arg1); }

void fn_80288A58(int arg0, int arg1) { fn_8028E584(*(int *)lbl_8055F6E0, arg0, arg1);}

void fn_80288A70(void) {}

extern float fn_801E7E24(void);
extern int lbl_8055F6D8, lbl_8055F6DC, lbl_8055F6E4;
extern float lbl_80558DC4, lbl_80564270;
extern int fn_80288BF0(int, int, int);
extern int fn_80289558(int, int);
extern void fn_80289FC4(int **, int, int);
__declspec(section ".data") extern float lbl_80558DC4;
#pragma push
#pragma use_lmw_stmw off
void fn_80288A74(void **arg0, int arg1) {
    void **q;
    int i;
    void **p;
    int temp;
    int *obj;
    float limit;
    float value;

    value = __fabs(fn_801E7E24());
    if (!(value <= lbl_80558DC4)) {
        limit = lbl_80564270;
        p = arg0;
        q = arg0;
        i = 0;
        while (i < arg1) {
            if (*((unsigned char *)q + 0xC) && *((float *)q + 2) < limit) {
                obj = (int *)*q;
                temp = obj[23];
                fn_80288BF0(lbl_8055F6D8, *(int *)((char *)p + 4), temp);
                fn_80289558(lbl_8055F6DC, *(int *)((char *)p + 4));
                fn_80289FC4((int **)lbl_8055F6E4, *(int *)((char *)p + 4), temp);
            }
            p = (void **)((char *)p + 0x10);
            q = (void **)((char *)q + 0x10);
            i++;
        }
    }
}
#pragma pop
int fn_80288B40(int arg0) {
    fn_80289084(); fn_80289154(arg0); fn_80289268(arg0); fn_80289394(arg0); return arg0;
}

int fn_80287B5C(void);
int fn_8028A330(int *, int);
int fn_80287B14(void);
int fn_8028E398(int);
int fn_80128668(void *);
void *fn_80288B88(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 0x68));
        fn_8028E398(*(int *)((char *)arg0 + 0x64));
        fn_8028E398(*(int *)((char *)arg0 + 0x60));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma processor 750
#pragma scheduling on
#pragma use_lmw_stmw off
int fn_80288BF0(int arg0, int arg1, int arg2) {
    extern void *fn_80287B24(int);
    extern int fn_8028E584(int, int, int);
    volatile float sp28, sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    volatile float *matrix;
    volatile float *vector;
    float m3,m4,m5,m0,m1,m2,m6,m7,m8;
    float x, y, z;
    float p0,p1,p2,p3,p4,p5,p6,p7,p8;

    if (arg2 == 2) {
        matrix = (float *)fn_80287B24(arg1);
        vector = (float *)((char *)arg0 + arg1 * 0xC);
        if ((volatile float *)&sp20 == vector) {
            m3=matrix[3]; y=vector[1]; m4=matrix[4]; p3=y*m3;
            m5=matrix[5]; m0=matrix[0]; p4=y*m4;
            x=vector[0]; m1=matrix[1]; p0=x*m0;
            m2=matrix[2]; p1=x*m1; m6=matrix[6]; p2=x*m2;
            p5=y*m5; z=vector[2]; m7=matrix[7]; p6=z*m6;
            m8=matrix[8]; p7=z*m7; p8=z*m8;
            sp20 = p6 + (p0 + p3);
            sp24 = p7 + (p1 + p4);
            sp28 = p8 + (p2 + p5);
        } else {
            p3 = matrix[3] * vector[1]; p0 = matrix[0] * vector[0]; p6 = matrix[6] * vector[2];
            sp20 = p6 + (p0 + p3);
            p4 = matrix[4] * vector[1]; p1 = matrix[1] * vector[0]; p7 = matrix[7] * vector[2];
            sp24 = p7 + (p1 + p4);
            p5 = matrix[5] * vector[1]; p2 = matrix[2] * vector[0]; p8 = matrix[8] * vector[2];
            sp28 = p8 + (p2 + p5);
        }
        x = sp28; y = sp24;
        sp20 += matrix[9]; sp24 += matrix[10]; sp28 += matrix[11];
        return ((int (*)(int, float *, void *, float, float))fn_8028E584)(
            *(int *)((char *)arg0 + 0x60), (float *)&sp20, (char *)matrix + 0x34, x, y);
    } else if ((unsigned)(arg2 - 6) <= 1U) {
        matrix = (float *)fn_80287B24(arg1);
        vector = (float *)((char *)arg0 + arg1 * 0xC);
        if ((volatile float *)&sp14 == vector) {
            p3 = matrix[3] * vector[1]; p4 = matrix[4] * vector[1]; p5 = matrix[5] * vector[1];
            p0 = matrix[0] * vector[0]; p1 = matrix[1] * vector[0]; p2 = matrix[2] * vector[0];
            p6 = matrix[6] * vector[2]; p7 = matrix[7] * vector[2]; p8 = matrix[8] * vector[2];
            sp14 = p6 + (p0 + p3);
            sp18 = p7 + (p1 + p4);
            sp1C = p8 + (p2 + p5);
        } else {
            p3 = matrix[3] * vector[1]; p0 = matrix[0] * vector[0]; p6 = matrix[6] * vector[2];
            sp14 = p6 + (p0 + p3);
            p4 = matrix[4] * vector[1]; p1 = matrix[1] * vector[0]; p7 = matrix[7] * vector[2];
            sp18 = p7 + (p1 + p4);
            p5 = matrix[5] * vector[1]; p2 = matrix[2] * vector[0]; p8 = matrix[8] * vector[2];
            sp1C = p8 + (p2 + p5);
        }
        x = sp1C; y = sp18;
        sp14 += matrix[9]; sp18 += matrix[10]; sp1C += matrix[11];
        return ((int (*)(int, float *, void *, float, float))fn_8028E584)(
            *(int *)((char *)arg0 + 0x64), (float *)&sp14, (char *)matrix + 0x34, x, y);
    } else if ((unsigned)(arg2 - 10) <= 1U) {
        matrix = (float *)fn_80287B24(arg1);
        vector = (float *)((char *)arg0 + arg1 * 0xC);
        if ((volatile float *)&sp8 == vector) {
            p3 = matrix[3] * vector[1]; p4 = matrix[4] * vector[1]; p5 = matrix[5] * vector[1];
            p0 = matrix[0] * vector[0]; p1 = matrix[1] * vector[0]; p2 = matrix[2] * vector[0];
            p6 = matrix[6] * vector[2]; p7 = matrix[7] * vector[2]; p8 = matrix[8] * vector[2];
            sp8 = p6 + (p0 + p3);
            spC = p7 + (p1 + p4);
            sp10 = p8 + (p2 + p5);
        } else {
            p3 = matrix[3] * vector[1]; p0 = matrix[0] * vector[0]; p6 = matrix[6] * vector[2];
            sp8 = p6 + (p0 + p3);
            p4 = matrix[4] * vector[1]; p1 = matrix[1] * vector[0]; p7 = matrix[7] * vector[2];
            spC = p7 + (p1 + p4);
            p5 = matrix[5] * vector[1]; p2 = matrix[2] * vector[0]; p8 = matrix[8] * vector[2];
            sp10 = p8 + (p2 + p5);
        }
        x = sp10; y = spC;
        sp8 += matrix[9]; spC += matrix[10]; sp10 += matrix[11];
        return ((int (*)(int, float *, void *, float, float))fn_8028E584)(
            *(int *)((char *)arg0 + 0x68), (float *)&sp8, (char *)matrix + 0x34, x, y);
    }
}

extern int fn_80287E20();
extern void fn_80287ED0(float *, void *, int, int);
extern int lbl_8055C884, lbl_8055C88C;
extern float lbl_80564274, lbl_80564278;
#pragma push
#pragma scheduling invalid_target
void fn_80289084(void *arg0) {
    float result[3];
    volatile float fallback[3];
    float f31 = lbl_80564278;
    float f30 = lbl_80564274;
    float *dst = (float *)arg0;
    int i = 0;

    while (i < fn_80287B14()) {
        void *obj = (void *)fn_80288208(i);
        if (fn_80287E20(obj, &lbl_8055C884)) {
            fn_80287ED0(result, obj, (int)&lbl_8055C884, (int)&lbl_8055C88C);
            dst[0] = result[0];
            dst[1] = result[1];
            dst[2] = result[2];
        } else {
            dst[0] = f30;
            dst[1] = f31;
            fallback[0] = f30;
            fallback[1] = f31;
            fallback[2] = f30;
            dst[2] = f30;
        }
        dst += 3;
        i++;
    }
}

extern float lbl_80564274, lbl_8056427C, lbl_80564280, lbl_80564284, lbl_80564288;
extern float lbl_8056428C, lbl_80564290, lbl_80564294, lbl_80564298, lbl_8056429C;
extern float lbl_805642A0, lbl_805642A4, lbl_805642A8, lbl_805642AC;
int fn_80289154(int arg0) {
    fn_802897E0Frame frame;
    register float f0;
    register float f1;
    register float f2;
    register float f3;
    register float f4;
    register float f5;
    register float f6;
    register float f7;
    register float f8;
    register float f9;
    register float f10;
    register float f11;
    register float f12;
    register float f13;
    register int size;
    register int two;
    register int five;

    fn_8028E61C((int *)&frame.sp20);
    f9 = *(volatile float *)&lbl_8056428C;
    size = 0x60;
    f10 = *(volatile float *)&lbl_80564288;
    two = 2;
    f5 = *(volatile float *)&lbl_80564298;
    f4 = *(volatile float *)&lbl_8056429C;
    five = 5;
    f13 = *(volatile float *)&lbl_8056427C;
    f12 = *(volatile float *)&lbl_80564280;
    f11 = *(volatile float *)&lbl_80564284;
    f8 = *(volatile float *)&lbl_80564274;
    f7 = *(volatile float *)&lbl_80564290;
    f6 = *(volatile float *)&lbl_80564294;
    f3 = *(volatile float *)&lbl_805642A0;
    f2 = *(volatile float *)&lbl_805642A4;
    f1 = *(volatile float *)&lbl_805642A8;
    f0 = *(volatile float *)&lbl_805642AC;

    frame.sp24 = size;
    frame.sp28 = f13;
    frame.sp2C = f12;
    frame.sp20 = two;
    frame.sp68 = f11;
    frame.sp64 = five;
    frame.sp14 = f10;
    frame.sp18 = f10;
    frame.sp1C = f10;
    frame.sp30 = f10;
    frame.sp34 = f10;
    frame.sp38 = f10;
    frame.sp8 = f9;
    frame.spC = f9;
    frame.sp10 = f9;
    frame.sp3C = f9;
    frame.sp40 = f9;
    frame.sp44 = f9;
    frame.sp48 = f8;
    frame.sp4C = f7;
    frame.sp50 = f6;
    frame.sp54 = f9;
    frame.sp90 = f5;
    frame.sp88 = f5;
    frame.sp80 = f5;
    frame.sp94 = f4;
    frame.sp8C = f4;
    frame.sp84 = f4;
    frame.sp78 = f3;
    frame.sp7C = f2;
    frame.sp70 = f1;
    frame.sp74 = f5;
    frame.sp98 = f0;
    frame.sp9C = f9;

    return *(int *)((char *)arg0 + 0x60) =
        fn_8028E2F8((int *)&frame.sp20, (int *)&lbl_80348AE8, lbl_8055C880, two,
                    f1, f2, f3, f4, f5, f6, f7);
}

int fn_80289268(int arg0) {
    fn_802897E0Frame frame;
    register float f0;
    register float f1;
    register float f2;
    register float f3;
    register float f4;
    register float f5;
    register float f6;
    register float f7;
    register float f8;
    register float f9;
    register float f10;
    register float f11;
    register float f12;
    register float f13;
    register float f30;
    register float f31;
    register int size;
    register int five;

    fn_8028E61C((int *)&frame.sp20);
    f12 = *(volatile float *)&lbl_805642B8;
    size = 0xA0;
    f11 = *(volatile float *)&lbl_805642BC;
    f7 = *(volatile float *)&lbl_805642C8;
    f6 = *(volatile float *)&lbl_80564280;
    five = 5;
    f31 = *(volatile float *)&lbl_8056427C;
    f30 = *(volatile float *)&lbl_805642B0;
    f13 = *(volatile float *)&lbl_805642B4;
    f10 = *(volatile float *)&lbl_805642C0;
    f9 = *(volatile float *)&lbl_805642C4;
    f8 = *(volatile float *)&lbl_80564294;
    f5 = *(volatile float *)&lbl_805642CC;
    f4 = *(volatile float *)&lbl_80564288;
    f3 = *(volatile float *)&lbl_805642D0;
    f2 = *(volatile float *)&lbl_805642D4;
    f1 = *(volatile float *)&lbl_805642D8;
    f0 = *(volatile float *)&lbl_8056428C;
    frame.sp24 = size;
    frame.sp28 = f31;
    frame.sp2C = f30;
    frame.sp20 = 2;
    frame.sp68 = f13;
    frame.sp64 = five;
    frame.sp14 = f12;
    frame.sp18 = f12;
    frame.sp1C = f12;
    frame.sp30 = f12;
    frame.sp34 = f12;
    frame.sp38 = f12;
    frame.sp8 = f11;
    frame.spC = f11;
    frame.sp10 = f11;
    frame.sp3C = f11;
    frame.sp40 = f11;
    frame.sp44 = f11;
    frame.sp48 = f10;
    frame.sp4C = f9;
    frame.sp50 = f8;
    frame.sp54 = f7;
    frame.sp90 = f7;
    frame.sp88 = f7;
    frame.sp80 = f7;
    frame.sp94 = f6;
    frame.sp8C = f6;
    frame.sp84 = f6;
    frame.sp78 = f5;
    frame.sp7C = f4;
    frame.sp70 = f3;
    frame.sp74 = f2;
    frame.sp98 = f1;
    frame.sp9C = f0;
    *(int *)((char *)arg0 + 0x64) =
        ((int (*)(int *, int *, int, float, float, float, float, float, float, float))fn_8028E2F8)(
            (int *)&frame.sp20, (int *)(void *)lbl_80348AFC, lbl_8055C880,
            f1, f2, f3, f4, f5, f6, f7);
}

#pragma push
#pragma scheduling invalid_target
int fn_80289394(int arg0) {
    fn_80289394Frame frame;
    register float f1;
    register float f2;
    register float f3;
    register float f4;
    register float f5;
    register float f6;
    register float f7;
    register float f8;
    register float f9;
    register float f10;
    register float f11;
    register float f12;
    register float f13;
    register float f31;
    register int size;
    register int five;

    fn_8028E61C((int *)&frame.sp20);
    f9 = *(volatile float *)&lbl_805642BC;
    size = 0x100;
    f5 = *(volatile float *)&lbl_805642C8;
    f11 = *(volatile float *)&lbl_805642E0;
    f10 = *(volatile float *)&lbl_805642C0;
    five = 5;
    f31 = *(volatile float *)&lbl_805642D4;
    f13 = *(volatile float *)&lbl_805642A4;
    f12 = *(volatile float *)&lbl_805642DC;
    f8 = *(volatile float *)&lbl_805642C4;
    f7 = *(volatile float *)&lbl_8056429C;
    f6 = *(volatile float *)&lbl_80564280;
    f4 = *(volatile float *)&lbl_805642E4;
    f3 = *(volatile float *)&lbl_805642E8;
    f2 = *(volatile float *)&lbl_805642EC;
    f1 = *(volatile float *)&lbl_805642D8;
    frame.sp24 = size;
    frame.sp28 = f31;
    frame.sp2C = f13;
    frame.sp20 = 2;
    frame.sp68 = f12;
    frame.sp64 = five;
    frame.sp14 = f11;
    frame.sp18 = f10;
    frame.sp1C = f11;
    frame.sp30 = f11;
    frame.sp34 = f10;
    frame.sp38 = f11;
    frame.sp8 = f9;
    frame.spC = f9;
    frame.sp10 = f9;
    frame.sp3C = f9;
    frame.sp40 = f9;
    frame.sp44 = f9;
    frame.sp48 = f10;
    frame.sp4C = f8;
    frame.sp50 = f7;
    frame.sp54 = f6;
    frame.sp90 = f5;
    frame.sp88 = f5;
    frame.sp80 = f5;
    frame.sp94 = f5;
    frame.sp8C = f5;
    frame.sp84 = f5;
    frame.sp78 = f4;
    frame.sp7C = f11;
    frame.sp70 = f3;
    frame.sp74 = f2;
    frame.sp98 = f1;
    frame.sp9C = *(volatile float *)&lbl_8056428C;
    *(int *)((char *)arg0 + 0x68) =
        ((int (*)(int *, int *, int, float, float, float, float, float, float, float))fn_8028E2F8)(
            (int *)&frame.sp20, (int *)(void *)&lbl_80348B10, lbl_8055C880,
            f1, f2, f3, f4, f5, f6, f7);
}
#pragma pop
void fn_802896E4(void *);
int fn_802894B4(int arg0) {
    fn_802896E4((void *)arg0);
    fn_802897E0(arg0);
    fn_80289554(arg0);
    return arg0;
}

void *__dt__Q210JASDrumSet5TPercFv_802894F4(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 0xA4));
        fn_8028E398(*(int *)((char *)arg0 + 0xA0));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80289554(int arg0) {
    return fn_8028967C(arg0);
}

int fn_8028967C(int arg0) {
    int i;
    int *p = (int *)arg0;
    memset(p, 0, 0xA0);
    for (i = 0; i < fn_80287B14(); i++) {
        p[2] = *(int *)((char *)fn_80288208(i) + 0x24);
        p += 5;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_802896E4(void *arg0) {
    fn_802897E0Frame frame;
    register float f9;
    register float f7;
    register float f4;
    register float f3;
    register float f10;
    register float f8;
    register float f6;
    register float f5;
    register float f2;
    register float f1;
    register float f0;
    register int size;
    register int zero;

    fn_8028E61C((int *)&frame.sp20);
    f8 = *(volatile float *)&lbl_8056428C;
    size = 0x80;
    f7 = *(volatile float *)&lbl_805642B0;
    zero = 0;
    f4 = *(volatile float *)&lbl_805642F4;
    f3 = *(volatile float *)&lbl_80564288;
    f0 = *(volatile float *)&lbl_80564280;
    f10 = *(volatile float *)&lbl_80564284;
    f6 = *(volatile float *)&lbl_80564274;
    f5 = *(volatile float *)&lbl_8056429C;
    f2 = *(volatile float *)&lbl_805642F8;
    f1 = *(volatile float *)&lbl_805642A4;
    f9 = *(volatile float *)&lbl_805642C8;
    frame.sp24 = size;
    frame.sp28 = f0;
    frame.sp2C = f8;
    frame.sp20 = zero;
    frame.sp68 = f10;
    frame.sp64 = 6;
    frame.sp14 = f7;
    frame.sp18 = f7;
    frame.sp1C = f7;
    frame.sp30 = f7;
    frame.sp34 = f7;
    frame.sp38 = f7;
    frame.sp8 = f8;
    frame.spC = f8;
    frame.sp10 = f8;
    frame.sp3C = f8;
    frame.sp40 = f8;
    frame.sp44 = f8;
    frame.sp48 = f6;
    frame.sp50 = f5;
    frame.sp54 = f8;
    frame.sp90 = f4;
    frame.sp88 = f4;
    frame.sp80 = f4;
    frame.sp94 = f3;
    frame.sp8C = f3;
    frame.sp84 = f3;
    frame.sp78 = f2;
    frame.sp7C = f7;
    frame.sp70 = f1;
    frame.sp74 = f9;
    *(int *)((char *)arg0 + 0xA0) =
        fn_8028E2F8((int *)&frame.sp20, &lbl_80348B24, lbl_8055C880, zero,
                    f1, f2, f3, f4, f5, f6, f7);
}
#pragma pop
extern int fn_8028E61C(int *);
extern int fn_8028E2F8(int *, int *, int, int, float, float, float, float, float, float, float);
__declspec(section ".data") extern int lbl_80348B34;
extern int lbl_8055C880;
extern float lbl_8056427C, lbl_80564284, lbl_8056428C, lbl_8056429C;
extern float lbl_80564274, lbl_80564280, lbl_80564288, lbl_80564290, lbl_80564294, lbl_80564298, lbl_805642A0, lbl_805642A4, lbl_805642A8, lbl_805642AC;
extern int lbl_80348AE8;
extern float lbl_805642B0, lbl_805642F8, lbl_805642FC, lbl_80564300;
#pragma push
#pragma scheduling invalid_target
int fn_802897E0(int arg0) {
    fn_802897E0Frame frame;
    register float f6;
    register float f4;
    register float f1;
    register float f2;
    register float f7;
    register float f5;
    register float f3;
    register float f0;
    register int size;
    register int zero;

    fn_8028E61C((int *)&frame.sp20);
    f6 = lbl_8056428C;
    size = 0x60;
    f4 = lbl_805642B0;
    zero = 0;
    f1 = lbl_80564300;
    f2 = lbl_8056427C;
    f7 = lbl_805642FC;
    f5 = lbl_80564284;
    f3 = lbl_8056429C;
    f0 = lbl_805642F8;
    frame.sp28 = f7;
    frame.sp2C = f6;
    frame.sp20 = zero;
    frame.sp68 = f5;
    frame.sp64 = 6;
    frame.sp14 = f4;
    frame.sp18 = f4;
    frame.sp1C = f4;
    frame.sp30 = f4;
    frame.sp34 = f4;
    frame.sp38 = f4;
    frame.sp8 = f6;
    frame.spC = f6;
    frame.sp10 = f6;
    frame.sp3C = f6;
    frame.sp40 = f6;
    frame.sp44 = f6;
    frame.sp50 = f3;
    frame.sp54 = f2;
    frame.sp8C = f1;
    frame.sp94 = f1;
    frame.sp84 = f1;
    frame.sp90 = f1;
    frame.sp88 = f1;
    frame.sp80 = f1;
    frame.sp78 = f0;
    frame.sp7C = f4;
    frame.sp70 = f2;
    frame.sp74 = f1;
    frame.sp24 = size;
    return *(int *)((char *)arg0 + 0xA4) =
        fn_8028E2F8((int *)&frame.sp20, &lbl_80348B34, lbl_8055C880, zero,
                    f1, f2, f3, f4, f5, f6, f7);
}
#pragma pop
void fn_802898CC(void *self, int arg0, int arg1, int arg2) {
    extern void *fn_80287B24(int);
    extern int fn_80288208(int);
    extern int fn_80288060(int, int);
    float sp14[3];
    float sp8[3];
    float *vec;
    float *mat;
    float a;
    float b;
    float c;

    vec = (float *)fn_80287B24(arg1);
    mat = (float *)fn_80288060(fn_80288208(arg1), arg2);
    if ((float *)((char *)mat + 0x24) == sp14) {
        float m1 = *(float *)((char *)mat + 0x28);
        float m0 = *(float *)((char *)mat + 0x24);
        float m2 = *(float *)((char *)mat + 0x2C);
        float x3 = vec[3];
        float x4 = vec[4];
        float x5 = vec[5];
        float x0 = vec[0];
        float x1 = vec[1];
        float x2 = vec[2];
        float x6 = vec[6];
        float x7 = vec[7];
        float x8 = vec[8];
        float q0 = m1 * x3;
        float q1 = m1 * x4;
        float q2 = m1 * x5;
        float p0 = m0 * x0;
        float p1 = m0 * x1;
        float p2 = m0 * x2;
        float r0 = m2 * x6;
        float r1 = m2 * x7;
        float r2 = m2 * x8;
        sp14[0] = r0 + (p0 + q0);
        sp14[1] = r1 + (p1 + q1);
        sp14[2] = r2 + (p2 + q2);
    } else {
        sp14[0] = (*(float *)((char *)mat + 0x2C) * vec[6]) + ((*(float *)((char *)mat + 0x24) * vec[0]) + (*(float *)((char *)mat + 0x28) * vec[3]));
        sp14[1] = (*(float *)((char *)mat + 0x2C) * vec[7]) + ((*(float *)((char *)mat + 0x24) * vec[1]) + (*(float *)((char *)mat + 0x28) * vec[4]));
        sp14[2] = (*(float *)((char *)mat + 0x2C) * vec[8]) + ((*(float *)((char *)mat + 0x24) * vec[2]) + (*(float *)((char *)mat + 0x28) * vec[5]));
    }
    sp14[0] += *(float *)((char *)vec + 0x24);
    sp14[1] += *(float *)((char *)vec + 0x28);
    sp14[2] += *(float *)((char *)vec + 0x2C);

    if ((float *)((char *)mat + 0xC) == sp8) {
        float m1 = *(float *)((char *)mat + 0x10);
        float m0 = *(float *)((char *)mat + 0xC);
        float m2 = *(float *)((char *)mat + 0x14);
        float x3 = vec[3];
        float x4 = vec[4];
        float x5 = vec[5];
        float x0 = vec[0];
        float x1 = vec[1];
        float x2 = vec[2];
        float x6 = vec[6];
        float x7 = vec[7];
        float x8 = vec[8];
        float q0 = m1 * x3;
        float q1 = m1 * x4;
        float q2 = m1 * x5;
        float p0 = m0 * x0;
        float p1 = m0 * x1;
        float p2 = m0 * x2;
        float r0 = m2 * x6;
        float r1 = m2 * x7;
        float r2 = m2 * x8;
        sp8[0] = r0 + (p0 + q0);
        sp8[1] = r1 + (p1 + q1);
        sp8[2] = r2 + (p2 + q2);
    } else {
        sp8[0] = (*(float *)((char *)mat + 0x14) * vec[6]) + ((*(float *)((char *)mat + 0xC) * vec[0]) + (*(float *)((char *)mat + 0x10) * vec[3]));
        sp8[1] = (*(float *)((char *)mat + 0x14) * vec[7]) + ((*(float *)((char *)mat + 0xC) * vec[1]) + (*(float *)((char *)mat + 0x10) * vec[4]));
        sp8[2] = (*(float *)((char *)mat + 0x14) * vec[8]) + ((*(float *)((char *)mat + 0xC) * vec[2]) + (*(float *)((char *)mat + 0x10) * vec[5]));
    }

    a = sp8[0] * lbl_805642FC;
    b = sp8[1] * lbl_805642FC;
    c = sp8[2] * lbl_805642FC;
    sp8[0] = *(float *)((char *)vec + 0x34) + a;
    sp8[1] = *(float *)((char *)vec + 0x38) + b;
    sp8[2] = *(float *)((char *)vec + 0x3C) + c;
    fn_8028E584(arg0, (int)sp14, (int)sp8);
}
#pragma pop
void fn_80289C80(int *);
int fn_80289BE8(int arg0) {
    fn_80289C80((int *)arg0);
    fn_80289D94(arg0);
    return arg0;
}

void *__dt__12PhysicsWorldFv_80289C20(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 4));
        fn_8028E398(*(int *)arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern int lbl_80348B44;
extern float lbl_8056427C;
extern float lbl_80564290;
extern float lbl_80564294;
extern float lbl_805642B8;
extern float lbl_80564300;
extern float lbl_80564304;
extern float lbl_80564308;
void fn_80289C80(int *arg0) {
    struct Frame {
        float sp8, spC, sp10, sp14, sp18, sp1C;
        int sp20;
        int sp24;
        float sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
        float sp48, sp4C, sp50, sp54;
        unsigned char pad58[0xC];
        int sp64;
        float sp68;
        unsigned char pad6C[4];
        float sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C;
    } frame;

    fn_8028E61C(&frame.sp20);
    frame.sp24 = 0x60;
    frame.sp28 = lbl_8056427C;
    frame.sp2C = lbl_80564300;
    frame.sp20 = 0;
    frame.sp68 = lbl_80564284;
    frame.sp64 = 1;
    frame.sp14 = lbl_80564304;
    frame.sp18 = lbl_80564304;
    frame.sp1C = lbl_80564304;
    frame.sp30 = lbl_80564304;
    frame.sp34 = lbl_80564304;
    frame.sp38 = lbl_80564304;
    frame.sp8 = lbl_8056428C;
    frame.spC = lbl_8056428C;
    frame.sp10 = lbl_8056428C;
    frame.sp3C = lbl_8056428C;
    frame.sp40 = lbl_8056428C;
    frame.sp44 = lbl_8056428C;
    frame.sp48 = lbl_8056428C;
    frame.sp4C = lbl_80564290;
    frame.sp50 = lbl_80564294;
    frame.sp54 = lbl_80564284;
    frame.sp90 = lbl_80564274;
    frame.sp88 = lbl_80564274;
    frame.sp80 = lbl_80564274;
    frame.sp94 = lbl_805642C8;
    frame.sp8C = lbl_805642C8;
    frame.sp84 = lbl_805642C8;
    frame.sp78 = lbl_80564308;
    frame.sp7C = lbl_805642B8;
    frame.sp70 = lbl_80564278;
    frame.sp74 = lbl_805642C0;
    frame.sp98 = lbl_805642D8;
    frame.sp9C = lbl_8056428C;

    *arg0 = ((int (*)(int *, int *, int, int, float, float, float, float, float,
                      float, float, float, float, float, float, float, float))fn_8028E2F8)(
        &frame.sp20, &lbl_80348B44, lbl_8055C880, 0,
        lbl_805642C0, lbl_80564278, lbl_805642B8, lbl_80564308,
        lbl_805642C8, lbl_80564274, lbl_80564294, lbl_80564290,
        lbl_8056428C, lbl_80564304, lbl_80564284, lbl_80564300, lbl_8056427C);
}

extern char lbl_80348B58[];
extern float lbl_80564290, lbl_80564294, lbl_805642B8, lbl_805642D8;
extern float lbl_80564308, lbl_8056430C, lbl_80564310;
int fn_80289D94(void *arg0) {
    struct Frame {
        volatile float sp8, spC, sp10, sp14, sp18, sp1C;
        volatile int sp20, sp24;
        volatile float sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
        volatile float sp48, sp4C, sp50, sp54;
        unsigned char pad58[0xC];
        volatile int sp64;
        volatile float sp68;
        unsigned char pad6C[4];
        volatile float sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C;
    } frame;
    register float f8;
    register float f9;
    register float f10;
    register float f4;
    register float f7;
    register float f11;
    register float f6;
    register float f5;
    register float f3;
    register float f2;
    register float f1;
    register float f0;
    register int size;
    register int zero;
    register int one;
    fn_8028E61C((int *)&frame.sp20);
    f8 = lbl_8056428C;
    size = 0x80;
    f9 = lbl_80564284;
    zero = 0;
    f10 = lbl_805642C8;
    f4 = lbl_80564274;
    one = 1;
    f7 = lbl_80564290;
    f11 = lbl_8056430C;
    f6 = lbl_80564294;
    f5 = lbl_805642B0;
    f3 = lbl_80564308;
    f2 = lbl_805642B8;
    f1 = lbl_80564310;
    f0 = lbl_805642D8;
    frame.sp24 = size;
    frame.sp28 = f11;
    frame.sp2C = f10;
    frame.sp20 = zero;
    frame.sp68 = f9;
    frame.sp64 = one;
    frame.sp14 = f9;
    frame.sp18 = f9;
    frame.sp1C = f9;
    frame.sp30 = f9;
    frame.sp34 = f9;
    frame.sp38 = f9;
    frame.sp8 = f8;
    frame.spC = f8;
    frame.sp10 = f8;
    frame.sp3C = f8;
    frame.sp40 = f8;
    frame.sp44 = f8;
    frame.sp48 = f8;
    frame.sp4C = f7;
    frame.sp50 = f6;
    frame.sp54 = f5;
    frame.sp90 = f4;
    frame.sp88 = f4;
    frame.sp80 = f4;
    frame.sp94 = f10;
    frame.sp8C = f10;
    frame.sp84 = f10;
    frame.sp78 = f3;
    frame.sp7C = f2;
    frame.sp70 = f1;
    frame.sp74 = f7;
    frame.sp98 = f0;
    frame.sp9C = f8;
    *(int *)((char *)arg0 + 4) =
        ((int (*)(int *, int *, int, int, float, float, float, float, float, float, float))fn_8028E2F8)(
            (int *)&frame.sp20, (int *)&lbl_80348B58, lbl_8055C880, zero,
            f1, f2, f3, f4, f5, f6, f7);
}

extern int fn_8028A1A4(int);
int fn_80289EA0(int arg0) {
    fn_8028A084();
    fn_8028A1A4(arg0);
    fn_80289F54(arg0);
    return arg0;
}

void *fn_80289EE0(void *arg0, int arg1) {
    if (arg0 != 0) {
        int temp = *(int *)arg0;
        if (temp != 0)
            fn_80128670(temp - 0x10);
        *(int *)arg0 = 0;
        fn_8028E398(*(int *)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
int fn_80289F54(int arg0) {
    int offset = 0;
    int i = 0;
    while (i < fn_80287B14()) {
        i++;
        *(int *)((char *)*(int *)arg0 + offset + 0x64) = 0;
        offset += 0x68;
    }
}
#pragma push
#pragma scheduling invalid_target
void fn_80289FC4(int **arg0, int arg1, int arg2) {
    char *temp = (char *)*arg0 + arg1 * 0x68;
    if (arg2 == 3 && *(void **)(temp + 0x64) == 0 &&
        *(long *)(temp + 0x60) > 0) {
        int index = fn_80287B5C();
        *(void **)(temp + 0x64) = temp + index * 0x18;
        fn_8028A330((int *)arg0, arg1);
    } else if (arg2 != 3 && *(void **)(temp + 0x64) != 0) {
        *(void **)(temp + 0x64) = 0;
    } else if (*(void **)(temp + 0x64) != 0) {
        fn_8028A330((int *)arg0, arg1);
    }
}

int fn_8028A084(int arg0) {
    fn_80289394Frame frame;
    register float f0;
    register float f1;
    register float f2;
    register float f3;
    register float f4;
    register float f5;
    register float f6;
    register float f7;
    register float f8;
    register float f9;
    register float f10;
    register float f11;
    register float f12;
    register float f13;
    register float f31;
    register int size;
    register int six;

    fn_8028E61C((int *)&frame.sp20);
    f9 = *(volatile float *)&lbl_8056428C;
    size = 0x80;
    f11 = *(volatile float *)&lbl_80564298;
    f4 = *(volatile float *)&lbl_80564300;
    f3 = *(volatile float *)&lbl_80564324;
    six = 6;
    f12 = *(volatile float *)&lbl_80564284;
    f10 = *(volatile float *)&lbl_80564314;
    f2 = *(volatile float *)&lbl_805642AC;
    f31 = *(volatile float *)&lbl_805642D4;
    f13 = *(volatile float *)&lbl_805642A4;
    f8 = *(volatile float *)&lbl_80564274;
    f7 = *(volatile float *)&lbl_80564318;
    f6 = *(volatile float *)&lbl_8056431C;
    f5 = *(volatile float *)&lbl_80564320;
    f1 = *(volatile float *)&lbl_805642C4;
    f0 = *(volatile float *)&lbl_805642B0;
    frame.sp24 = size;
    frame.sp28 = f31;
    frame.sp2C = f13;
    frame.sp20 = 2;
    frame.sp68 = f12;
    frame.sp64 = six;
    frame.sp14 = f11;
    frame.sp18 = f10;
    frame.sp1C = f11;
    frame.sp30 = f11;
    frame.sp34 = f10;
    frame.sp38 = f11;
    frame.sp8 = f9;
    frame.spC = f9;
    frame.sp10 = f9;
    frame.sp3C = f9;
    frame.sp40 = f9;
    frame.sp44 = f9;
    frame.sp48 = f8;
    frame.sp4C = f7;
    frame.sp50 = f6;
    frame.sp54 = f5;
    frame.sp90 = f4;
    frame.sp88 = f4;
    frame.sp80 = f4;
    frame.sp94 = f3;
    frame.sp8C = f3;
    frame.sp84 = f3;
    frame.sp78 = f2;
    frame.sp7C = f12;
    frame.sp70 = f1;
    frame.sp74 = f0;
    frame.sp98 = f2;
    frame.sp9C = f9;
    *(int *)((char *)arg0 + 4) =
        ((int (*)(int *, int *, int, float, float, float, float, float, float, float))fn_8028E2F8)(
            (int *)&frame.sp20, (int *)(void *)lbl_80348B6C, lbl_8055C880,
            f1, f2, f3, f4, f5, f6, f7);
}

#pragma scheduling on
#pragma pop
extern int fn_80288208(int);
extern int fn_80287E20(void *, void *);
extern void *fn_80287E80(int, void *);
extern void *fn_8012850C(int, void *, int);
extern void *fn_8002F37C(int, void (*)(void), int, int, int);
extern void fn_8028A32C(void);
extern char lbl_80348B7C[], lbl_80348B8C[];
extern int lbl_8055C88C, lbl_8055C890, lbl_8055C898;
int fn_8028A1A4(int out) {
    int count = fn_80287B14();
    int i;
    int j;
    int offset;
    char *entry;
    char *cursor;
    void *obj;
    void *item;
    float a[3];
    float b[3];

    *(void **)out = fn_8002F37C(
        (int)fn_8012850C(count * 0x68 + 0x10, lbl_80348B7C, count * 0x68),
        fn_8028A32C, 0, 0x68, count);

    for (i = 0, offset = 0; i < fn_80287B14(); i++, offset += 0x68) {
        obj = (void *)fn_80288208(i);
        entry = (char *)*(void **)out + offset;
        if (fn_80287E20(obj, lbl_80348B8C)) {
            obj = fn_80287E80((int)obj, lbl_80348B8C);
            *(int *)(entry + 0x60) =
                ((int (*)(void *, int))(*(void ***)obj)[7])(obj, lbl_8055C890);
            for (j = 0, cursor = entry; j < *(int *)(entry + 0x60);
                 j++, cursor += 0x18) {
                item = ((void *(*)(void *, int))(*(void ***)obj)[24])(obj, j);
                ((void (*)(float *, void *, int))(*(void ***)item)[13])(
                    a, item, lbl_8055C88C);
                *(float *)(cursor + 0x0) = a[0];
                *(float *)(cursor + 0x4) = a[1];
                *(float *)(cursor + 0x8) = a[2];
                ((void (*)(float *, void *, int))(*(void ***)item)[13])(
                    b, item, lbl_8055C898);
                *(float *)(cursor + 0xC) = b[0];
                *(float *)(cursor + 0x10) = b[1];
                *(float *)(cursor + 0x14) = b[2];
            }
        } else {
            *(int *)(entry + 0x60) = 0;
        }
    }
}

void fn_8028A32C(void) {}

extern float lbl_805642B4;
extern void *fn_80287B24(int);
int fn_8028A330(int *arg0, int arg1) {
 float sp14[3], sp8[3], *mat=(float*)fn_80287B24(arg1);
 float *vec=*(float**)(*(char**)arg0+arg1*0x68+0x64);
 float a,b,c;
 if(vec==sp14) {
  sp14[0]=vec[2]*mat[6]+(vec[0]*mat[0]+vec[1]*mat[3]);
  sp14[1]=vec[2]*mat[7]+(vec[0]*mat[1]+vec[1]*mat[4]);
  sp14[2]=vec[2]*mat[8]+(vec[0]*mat[2]+vec[1]*mat[5]);
 } else {
  sp14[0]=vec[2]*mat[6]+(vec[0]*mat[0]+vec[1]*mat[3]);
  sp14[1]=vec[2]*mat[7]+(vec[0]*mat[1]+vec[1]*mat[4]);
  sp14[2]=vec[2]*mat[8]+(vec[0]*mat[2]+vec[1]*mat[5]);
 }
 sp14[0]+=mat[9]; sp14[1]+=mat[10]; sp14[2]+=mat[11];
 a=vec[3]*lbl_805642B4; b=vec[4]*lbl_805642B4; c=vec[5]*lbl_805642B4;
 sp8[0]=a*mat[0]+b*mat[3]+c*mat[6];
 sp8[1]=a*mat[1]+b*mat[4]+c*mat[7];
 sp8[2]=a*mat[2]+b*mat[5]+c*mat[8];
 sp8[0]+=mat[13]; sp8[1]+=mat[14]; sp8[2]+=mat[15];
 fn_8028E584(arg0[1],(int)sp14,(int)sp8);
}

