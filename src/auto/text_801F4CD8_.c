typedef struct GridEdge_801F5508 {
    short from;
    short to;
    float distance;
} GridEdge_801F5508;

// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void *fn_8012850C();
extern float PSVECSquareDistance(float *, float *);
extern char lbl_8033AD94[];
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EC18;
extern void *lbl_8055EC14;
extern void *lbl_8055EC10;
extern void *lbl_8055EC1C;
extern void *lbl_8055EC20;
extern char lbl_8033ACE8[32];
__declspec(section ".data") extern float lbl_80558DC4;
extern void fn_801E8C84(float *);
extern void *fn_801284F8(int, void *);
extern char lbl_8033AC68[];
extern char *lbl_8033AC9C[5];
extern char lbl_8033AD08[];
extern int stricmp(const char *, const char *);
extern void fn_8012F9E8(void *, void *, void *);
extern void fn_801F7160(void *);
extern void fn_801F7220(void *);
extern void *fn_802AE414(void);
extern void fn_802E317C(const char *, ...);
extern void fn_801F7280(void *, void *, void *);
extern char lbl_8033AE54[], lbl_8033AE78[];
extern char lbl_8055B1C0[];
typedef int (*GetterI)(void *, const char *);
typedef void (*SetterV)(void *, const char *);
extern void fn_801F5344(void *, void *, void *);
extern void fn_801F70D0(void *, int);
extern void *fn_801F6D60(void *, int);
typedef void *FN_801F6A08_RETURN;
extern FN_801F6A08_RETURN fn_801F6A08(void *, int);
extern void fn_801F75A4();
extern void *fn_801F69C8(void *);
extern void *fn_801F6D20(void *);
extern void *fn_801F7090(void *);
void fn_801F4CD8(void) {
    char *data = lbl_8033AC68;
    void *ptr;

    ptr = fn_801284F8(0x904, data + 0x48);
    if (ptr != 0) {
        ptr = fn_801F69C8(ptr);
    }
    lbl_8055EC10 = ptr;

    ptr = fn_801284F8(0x2A4, data + 0x5C);
    if (ptr != 0) {
        ptr = fn_801F6D20(ptr);
    }
    lbl_8055EC14 = ptr;

    ptr = fn_801284F8(0x124, data + 0x70);
    if (ptr != 0) {
        ptr = fn_801F7090(ptr);
    }
    lbl_8055EC18 = ptr;
    lbl_8055EC1C = 0;
    lbl_8055EC20 = 0;
}

void fn_801F4D64(void) {
    fn_801F70D0(lbl_8055EC18, 1);
    lbl_8055EC18 = 0;
    fn_801F6D60(lbl_8055EC14, 1);
    lbl_8055EC14 = 0;
    fn_801F6A08(lbl_8055EC10, 1);
    lbl_8055EC10 = 0;
    lbl_8055EC1C = 0;
    lbl_8055EC20 = 0;
}

void fn_801F4DC4(void) {
    fn_801F7160(lbl_8055EC18);
}

void fn_801F4DCC(void) {
    fn_801F7220(lbl_8055EC18);
}

#pragma scheduling invalid_target
void fn_801F4DD4(void *arg0, void *arg1) {
    void *temp_r3;
    temp_r3 = fn_802AE414();
    if (temp_r3 == 0) {
        fn_802E317C(lbl_8033ACE8, arg0);
    }
    fn_801F7280(lbl_8055EC18, temp_r3, arg1);
}
#pragma scheduling on
extern void *fn_801284F8(int, void *);
extern char lbl_8033AC68[];
extern char *lbl_8033AC9C[5];
extern char lbl_8033AD08[];
extern int stricmp(const char *, const char *);
extern void fn_8012F9E8(void *, void *, void *);
extern void fn_80128670(int);
int fn_801F4E44(const char *arg0) {
    unsigned int i;
    i = 0;
    while (5 > i) {
        if (stricmp(arg0, lbl_8033AC9C[i]) == 0) {
            return i + 1;
        }
        i++;
    }
    fn_802E317C(lbl_8033AD08, arg0);
    return 0;
}

typedef struct Vec3_801F4F9C {
    float x, y, z;
} Vec3_801F4F9C;

typedef struct Vec2_801F4F9C {
    float x, y;
} Vec2_801F4F9C;

typedef struct Vertex_801F4F9C {
    Vec3_801F4F9C pos;
    unsigned int color;
    Vec2_801F4F9C uv;
} Vertex_801F4F9C;

#pragma cplusplus on
class DummyObj_801F4F9C {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual Vec3_801F4F9C d11(const char *);
    virtual Vec3_801F4F9C d12(const char *, Vec3_801F4F9C);
    virtual Vec2_801F4F9C d13(const char *);
};
class DummyObj_801F7280 {
public:
  virtual void d0();
  virtual void d1();
  virtual void d2();
  virtual const char *d5(const char *);
  virtual void d6();
  virtual void d7();
  virtual void d8();
  virtual float d9(const char *);
};
class Obj_801F4ECC {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual int getValue(const char *, int);
};
#pragma cplusplus on
extern "C" {
__declspec(section ".sdata") extern char lbl_8055B178[];
__declspec(section ".sdata") extern char lbl_8055B180[];
__declspec(section ".sdata") extern char lbl_8055B184[];
extern float lbl_80562FB0;
extern float lbl_80562FB4;
}
#pragma cplusplus off

extern char lbl_8033AD28[];
extern char lbl_8033AD34[];
extern char lbl_8055B168[];
extern char lbl_8055B170[];
__declspec(section ".sdata") extern char lbl_8055B168[];
__declspec(section ".sdata") extern char lbl_8055B170[];
#pragma cplusplus on
extern "C" int fn_801F4ECC(void *arg0) {
    int result = 0;
    Obj_801F4ECC *object = (Obj_801F4ECC *)arg0;

    if (object->getValue(lbl_8055B168, 0)) result |= 1;
    if (object->getValue(lbl_8033AD28, 0)) result |= 2;
    if (object->getValue(lbl_8055B170, 0)) result |= 4;
    if ((result & 1) && (result & 4)) fn_802E317C(lbl_8033AD34);
    return result;
}
#pragma cplusplus off
typedef int (*F0)(void);
typedef void *(*F2)(void *, void *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_801F52BC(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    int result = 0;
    if (((int (*)(void *))(*(void ***)arg0)[3])(arg0) != 0) {
        result = ((int (*)(int, int, int))fn_8012F9E8)(arg2, arg3, ((int (*)(void *, int))(*(void ***)arg0)[5])(arg0, arg1));
    }
    return result;
}

#pragma scheduling invalid_target
void fn_801F5508(void *arg0) {
    int temp_r5 = *(int *)((char *)arg0 + 0x2C);
    int temp_r6 = *(int *)((char *)arg0 + 0x30);
    int temp_r30 = ((temp_r6 - 1) * temp_r5) + (temp_r6 * (temp_r5 - 1));
    char *temp_r31 = (char *)((void *(*)(int, void *))fn_8012850C)(
        temp_r30 * 8, lbl_8033AD94);
    int var_r29 = 0;
    int var_r24 = 0;
    int var_r25;
    int var_r23;
    int temp_r28;
    int temp_r5_2;
    int temp_r0;
    char *temp_r27;
    void *temp_r4;
    int var_r27;
    char *temp_r24;
    int temp_r5_3;
    void *temp_r4_2;
    int temp_r0_2;
    int temp_r5_4;

    goto loop_5;
loop_3:
    temp_r5 = *(int *)((char *)arg0 + 0x2C);
    var_r25 = var_r29 * 8;
    var_r23 = 1;
    temp_r28 = var_r24 * temp_r5;
    goto loop_1;
loop_2:
    temp_r5_2 = temp_r28 + var_r23;
    temp_r4 = *(void **)((char *)arg0 + 4);
    temp_r0 = temp_r5_2 - 1;
    *(short *)(temp_r31 + var_r25) = (short)temp_r0;
    temp_r27 = temp_r31 + var_r25;
    *(short *)(temp_r27 + 2) = (short)temp_r5_2;
    var_r29 += 1;
    var_r25 += 8;
    *(float *)(temp_r27 + 4) = PSVECSquareDistance(
        (float *)((char *)temp_r4 + temp_r0 * 0xC),
        (float *)((char *)temp_r4 + temp_r5_2 * 0xC));
    var_r23 += 1;
    goto loop_1;
loop_1:
    if (var_r23 < *(int *)((char *)arg0 + 0x2C)) goto loop_2;
    var_r24 += 1;
loop_5:
    if (var_r24 < *(int *)((char *)arg0 + 0x30)) goto loop_3;

    temp_r28 = 0;
    goto loop_11;
loop_9:
    var_r25 = var_r29 * 8;
    var_r27 = 1;
    goto loop_8;
loop_10:
    temp_r5_3 = *(int *)((char *)arg0 + 0x2C);
    temp_r4_2 = *(void **)((char *)arg0 + 4);
    temp_r24 = temp_r31 + var_r25;
    temp_r0_2 = temp_r28 + ((var_r27 - 1) * temp_r5_3);
    temp_r5_4 = temp_r28 + (var_r27 * temp_r5_3);
    *(short *)(temp_r31 + var_r25) = (short)temp_r0_2;
    *(short *)(temp_r24 + 2) = (short)temp_r5_4;
    var_r29 += 1;
    var_r25 += 8;
    *(float *)(temp_r24 + 4) = PSVECSquareDistance(
        (float *)((char *)temp_r4_2 + temp_r0_2 * 0xC),
        (float *)((char *)temp_r4_2 + temp_r5_4 * 0xC));
    var_r27 += 1;
    goto loop_8;
loop_8:
    if (var_r27 < *(int *)((char *)arg0 + 0x30)) goto loop_10;
    temp_r28 += 1;
loop_11:
    if (temp_r28 < *(int *)((char *)arg0 + 0x2C)) goto loop_9;

    *(void **)((char *)arg0 + 0x14) = temp_r31;
    *(int *)((char *)arg0 + 0x18) = temp_r30;
}
#pragma scheduling on
extern void *fn_8002F37C();
extern void *fn_8012850C();
extern char lbl_8033ADA4[];
extern char lbl_8033ADC4[];
extern void fn_801F596C(void);
#pragma scheduling invalid_target
void fn_801F5664(void *arg0, int arg1) {
    int var_r31;
    void *temp_r3;
    void *temp_r3_3;
    void *temp_r4;
    void *temp_r4_10;
    void *temp_r4_2;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    void *temp_r4_7;
    void *temp_r4_8;
    void *temp_r5_2;
    void *temp_r5_3;
    void *temp_r5_4;
    void *temp_r5_5;
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r7;
    int temp_r0;
    int temp_r0_2;
    int temp_r0_3;
    int temp_r0_4;
    int temp_r7_2;
    int var_r8;
    int temp_r0_5;
    int temp_r3_2;
    int temp_r4_3;
    int temp_r4_9;
    int temp_r5;
    int var_r4;
    int var_r5;
    int var_r6;
    int var_r6_2;
    int var_r8_2;
    int temp_r0_6;

    temp_r0_6 = *(int *)((char *)arg0 + 0x30);
    var_r31 = *(int *)((char *)arg0 + 0x2C);
    switch (arg1) {
    case 1:
    case 4:
        var_r31 = 2;
        break;
    case 2:
        var_r31 = 4;
        break;
    case 5:
        var_r31 = temp_r0_6;
        break;
    case 3:
        break;
    default:
        fn_802E317C(lbl_8033ADA4, arg1);
        var_r31 = 0;
        break;
    }
    temp_r3 = fn_8002F37C(fn_8012850C((var_r31 * 0x10) + 0x10, lbl_8033ADC4), fn_801F596C, 0, 0x10, var_r31);
    var_r6 = 0;
    var_r4 = 0;
    var_r5 = 0;
    switch (arg1) {
    case 2:
        var_r6 = 2;
        temp_r0 = (*(int *)((char *)arg0 + 0x30) - 1) * *(int *)((char *)arg0 + 0x2C);
        temp_r4 = *(void **)((char *)arg0 + 4);
        temp_r5 = temp_r0 * 0xC;
        *(short *)temp_r3 = temp_r0;
        temp_r4_2 = (char *)temp_r4 + temp_r5;
        *(float *)((char *)temp_r3 + 4) = *(float *)temp_r4_2;
        *(float *)((char *)temp_r3 + 8) = *(float *)((char *)temp_r4_2 + 4);
        *(float *)((char *)temp_r3 + 0xC) = *(float *)((char *)temp_r4_2 + 8);
        temp_r5_2 = *(void **)((char *)arg0 + 4);
        temp_r0_2 = (*(int *)((char *)arg0 + 0x2C) * *(int *)((char *)arg0 + 0x30)) - 1;
        temp_r4_3 = temp_r0_2 * 0xC;
        *(short *)((char *)temp_r3 + 0x10) = temp_r0_2;
        temp_r4_4 = (char *)temp_r5_2 + temp_r4_3;
        *(float *)((char *)temp_r3 + 0x14) = *(float *)((char *)temp_r5_2 + temp_r4_3);
        *(float *)((char *)temp_r3 + 0x18) = *(float *)((char *)temp_r4_4 + 4);
        *(float *)((char *)temp_r3 + 0x1C) = *(float *)((char *)temp_r4_4 + 8);
        /* fallthrough */
    case 1:
        temp_r5_3 = *(void **)((char *)arg0 + 4);
        temp_r4_5 = (char *)temp_r3 + (var_r6 * 0x10);
        *(short *)temp_r4_5 = 0;
        temp_r6 = (char *)temp_r3 + ((var_r6 + 1) * 0x10);
        *(float *)((char *)temp_r4_5 + 4) = *(float *)((char *)temp_r5_3 + 0);
        *(float *)((char *)temp_r4_5 + 8) = *(float *)((char *)temp_r5_3 + 4);
        *(float *)((char *)temp_r4_5 + 0xC) = *(float *)((char *)temp_r5_3 + 8);
        temp_r4_6 = *(void **)((char *)arg0 + 4);
        temp_r0_3 = *(int *)((char *)arg0 + 0x2C) - 1;
        temp_r3_2 = temp_r0_3 * 0xC;
        *(short *)((char *)temp_r6 + 0) = temp_r0_3;
        temp_r3_3 = (char *)temp_r4_6 + temp_r3_2;
        *(float *)((char *)temp_r6 + 4) = *(float *)((char *)temp_r4_6 + temp_r3_2);
        *(float *)((char *)temp_r6 + 8) = *(float *)((char *)temp_r3_3 + 4);
        *(float *)((char *)temp_r6 + 0xC) = *(float *)((char *)temp_r3_3 + 8);
        break;
    case 3:
        var_r8 = 0;
        var_r6_2 = 0;
        while (var_r8 < *(int *)((char *)arg0 + 0x2C)) {
            temp_r4_7 = (char *)temp_r3 + var_r5;
            *(short *)temp_r4_7 = var_r8;
            temp_r7 = (char *)*(void **)((char *)arg0 + 4) + var_r6_2;
            var_r6_2 += 0xC;
            var_r5 += 0x10;
            var_r8 += 1;
            *(float *)((char *)temp_r4_7 + 4) = *(float *)temp_r7;
            *(float *)((char *)temp_r4_7 + 8) = *(float *)((char *)temp_r7 + 4);
            *(float *)((char *)temp_r4_7 + 0xC) = *(float *)((char *)temp_r7 + 8);
        }
        break;
    case 4:
        temp_r4_8 = *(void **)((char *)arg0 + 4);
        *(short *)temp_r3 = 0;
        *(float *)((char *)temp_r3 + 4) = *(float *)((char *)temp_r4_8 + 0);
        *(float *)((char *)temp_r3 + 8) = *(float *)((char *)temp_r4_8 + 4);
        *(float *)((char *)temp_r3 + 0xC) = *(float *)((char *)temp_r4_8 + 8);
        temp_r5_4 = *(void **)((char *)arg0 + 4);
        temp_r0_4 = (*(int *)((char *)arg0 + 0x30) - 1) * *(int *)((char *)arg0 + 0x2C);
        temp_r4_9 = temp_r0_4 * 0xC;
        *(short *)((char *)temp_r3 + 0x10) = temp_r0_4;
        temp_r4_10 = (char *)temp_r5_4 + temp_r4_9;
        *(float *)((char *)temp_r3 + 0x14) = *(float *)((char *)temp_r5_4 + temp_r4_9);
        *(float *)((char *)temp_r3 + 0x18) = *(float *)((char *)temp_r4_10 + 4);
        *(float *)((char *)temp_r3 + 0x1C) = *(float *)((char *)temp_r4_10 + 8);
        break;
    case 5:
        var_r8_2 = 0;
        while (var_r8_2 < *(int *)((char *)arg0 + 0x30)) {
            temp_r5_5 = (char *)temp_r3 + var_r4;
            temp_r6_2 = *(void **)((char *)arg0 + 4);
            temp_r7_2 = *(int *)((char *)arg0 + 0x2C) * var_r8_2;
            temp_r0_5 = temp_r7_2 * 0xC;
            *(short *)temp_r5_5 = temp_r7_2;
            temp_r6_3 = (char *)temp_r6_2 + temp_r0_5;
            var_r4 += 0x10;
            var_r8_2 += 1;
            *(float *)((char *)temp_r5_5 + 4) = *(float *)((char *)temp_r6_2 + temp_r0_5);
            *(float *)((char *)temp_r5_5 + 8) = *(float *)((char *)temp_r6_3 + 4);
            *(float *)((char *)temp_r5_5 + 0xC) = *(float *)((char *)temp_r6_3 + 8);
        }
        break;
    default:
        fn_802E317C(lbl_8033ADA4, arg1);
        break;
    }
    *(void **)((char *)arg0 + 0x1C) = temp_r3;
    *(int *)((char *)arg0 + 0x20) = var_r31;
}
#pragma scheduling on
void fn_801F596C(void) {

}

extern float PSQUATMultiply(void *, void *);
extern double fn_8002F208(float);
extern void fn_801F5970(void *, void *);
extern void fn_801F5508(void *);
extern void fn_801F5664(void *, int);
extern int fn_802CAC28(int, int);
__declspec(section ".sdata") extern float lbl_80562FD0;
extern float __fabsf(float);
extern double __fabs(double);
#pragma scheduling invalid_target
void fn_801F602C(void *arg0, int arg1, int arg2, int arg3, int arg4) {
float var_f31, var_f30, temp_f1, temp_f1_2;
float temp_f0, temp_f0_2, temp_f0_3, temp_f0_4;
float var_f1, var_f1_2, var_f1_3, var_f1_4;
float var_f0, var_f0_2, var_f0_3, var_f0_4;
float var_f29, var_f28, var_f27, var_f26, temp_f0_5, var_f1_5, productY;
int temp_r0, temp_r0_2, temp_r0_3, temp_r0_4;
int var_r0, var_r0_2, var_r0_3, var_r0_4, var_r3, var_r3_2, var_r3_3, var_r3_4;
var_f31 = PSQUATMultiply((void *)(arg1 + 0x30), (void *)(arg1 + 0x48));
temp_f1 = PSQUATMultiply((void *)arg1, (void *)(arg1 + 0x18));
if (temp_f1 > var_f31) var_f31 = temp_f1;
var_f30 = PSQUATMultiply((void *)(arg1 + 0x18), (void *)(arg1 + 0x48));
temp_f1_2 = PSQUATMultiply((void *)arg1, (void *)(arg1 + 0x30));
if (temp_f1_2 > var_f30) var_f30 = temp_f1_2;
if (arg4 & 4) {
*(int *)((char *)arg0 + 0x2C) = 2;
*(int *)((char *)arg0 + 0x30) = 2;
} else if (!(arg4 & 1)) {
var_r3 = 2;
temp_r0 = (int)(var_f31 * *(float *)(arg1 + 0x60));
if (temp_r0 > 2) var_r3 = temp_r0;
var_r0 = 8;
if (var_r3 < 8) var_r0 = var_r3;
var_r3_2 = 2;
temp_r0_2 = (int)(var_f30 * *(float *)(arg1 + 0x64));
if (temp_r0_2 > 2) var_r3_2 = temp_r0_2;
var_r0_2 = 4;
if (var_r3_2 < 4) var_r0_2 = var_r3_2;
*(int *)((char *)arg0 + 0x2C) = var_r0;
*(int *)((char *)arg0 + 0x30) = var_r0_2;
} else {
var_r3_3 = 2;
temp_r0_3 = (int)(lbl_80562FD0 * (var_f31 * *(float *)(arg1 + 0x60)));
if (temp_r0_3 > 2) var_r3_3 = temp_r0_3;
var_r0_3 = 8;
if (var_r3_3 < 8) var_r0_3 = var_r3_3;
var_r3_4 = 2;
temp_r0_4 = (int)(lbl_80562FD0 * (var_f30 * *(float *)(arg1 + 0x64)));
if (temp_r0_4 > 2) var_r3_4 = temp_r0_4;
var_r0_4 = 4;
if (var_r3_4 < 4) var_r0_4 = var_r3_4;
*(int *)((char *)arg0 + 0x2C) = var_r0_3;
*(int *)((char *)arg0 + 0x30) = var_r0_4;
}
temp_f0 = *(float *)(arg1 + 0x58); var_f1 = *(float *)(arg1 + 0x40);
var_f1 = (var_f1 < temp_f0) ? var_f1 : temp_f0;
var_f0 = *(float *)(arg1 + 0x28); var_f0 = (var_f0 < var_f1) ? var_f0 : var_f1;
var_f29 = *(float *)(arg1 + 0x10); var_f29 = (var_f29 < var_f0) ? var_f29 : var_f0;
temp_f0_2 = *(float *)(arg1 + 0x58); var_f1_2 = *(float *)(arg1 + 0x40);
var_f1_2 = (var_f1_2 > temp_f0_2) ? var_f1_2 : temp_f0_2;
var_f0_2 = *(float *)(arg1 + 0x28); var_f0_2 = (var_f0_2 > var_f1_2) ? var_f0_2 : var_f1_2;
var_f28 = *(float *)(arg1 + 0x10); var_f28 = (var_f28 > var_f0_2) ? var_f28 : var_f0_2;
temp_f0_3 = *(float *)(arg1 + 0x5C); var_f1_3 = *(float *)(arg1 + 0x44);
var_f1_3 = (var_f1_3 < temp_f0_3) ? var_f1_3 : temp_f0_3;
var_f0_3 = *(float *)(arg1 + 0x2C); var_f0_3 = (var_f0_3 < var_f1_3) ? var_f0_3 : var_f1_3;
var_f27 = *(float *)(arg1 + 0x14); var_f27 = (var_f27 < var_f0_3) ? var_f27 : var_f0_3;
temp_f0_4 = *(float *)(arg1 + 0x5C); var_f1_4 = *(float *)(arg1 + 0x44);
var_f1_4 = (var_f1_4 > temp_f0_4) ? var_f1_4 : temp_f0_4;
var_f0_4 = *(float *)(arg1 + 0x2C); var_f0_4 = (var_f0_4 > var_f1_4) ? var_f0_4 : var_f1_4;
var_f26 = *(float *)(arg1 + 0x14); var_f26 = (var_f26 > var_f0_4) ? var_f26 : var_f0_4;
*(int *)((char *)arg0 + 0x24) = fn_802CAC28(arg2, 0);
var_f1_5 = (float)__fabs((double)(var_f26 - var_f27));
temp_f0_5 = (float)__fabs((double)(var_f28 - var_f29));
temp_f0_5 = (temp_f0_5 > var_f1_5) ? temp_f0_5 : var_f1_5;
var_f31 = ((var_f31) > (var_f30)) ? var_f31 : var_f30;
*(float *)((char *)arg0 + 0x28) = (float)fn_8002F208(temp_f0_5 / var_f31);
fn_801F5970(arg0, (void *)arg1); fn_801F5508(arg0); fn_801F5664(arg0, arg3);
}
#pragma scheduling on
void fn_801F6358(void *arg0) {
    int temp;
    fn_80128670(*(int *)((char *)arg0 + 0xC));
    temp = *(int *)arg0;
    if (temp != 0) {
        fn_80128670(temp - 0x10);
    }
}

#pragma dont_inline on
void fn_801F639C(void *arg0) {
    int temp_r4 = *(int*)((char*)arg0 + 0x1C);
    if (temp_r4 != 0) {
        fn_80128670(temp_r4 - 0x10);
    }
    fn_80128670(*(int*)((char*)arg0 + 0x14));
    fn_801F6358(arg0);
    fn_802CAC54(*(int*)((char*)arg0 + 0x24));
}

#pragma scheduling invalid_target
void fn_801F63F0(void *arg0, float *arg1, float arg2) {
    extern float lbl_80562FB0, lbl_80562FD4, lbl_80562FD8;
    float a,b,c,x,y,z,t,u,v;
    int i,off,r0,r4;
    void *p,*q;

    off=0; i=0;
    x=lbl_80562FB0-arg2;
    a=arg1[0]; t=lbl_80562FD8; b=arg1[1]; c=a*t; z=arg1[2]; b=b*t; z=z*t;
    t=lbl_80562FD4; y=-(x); v=c; u=b; x=t-arg2; a=b; b=z;
    goto check;
loop:
    r4=*(int*)((char*)arg0+4); i++; r0=*(int*)((char*)arg0+8);
    p=(char*)r4+off; q=(char*)r0+off;
    c=*(float*)p; c=c*x;
    t=*(float*)q; t=t*y;
    a=c+v; b=*(float*)((char*)p+4); b=b*x;
    z=*(float*)((char*)p+8); z=z*x;
    t=a+t; *(float*)q=t; c=*(float*)((char*)q+4);
    c=c*y; b=u+b; z=v+z; *(float*)((char*)q+4)=b+c;
    off+=0xC;
    c=*(float*)((char*)q+8); c=c*y; *(float*)((char*)q+8)=z+c;
check:
    if (i<*(int*)((char*)arg0+0x10)) goto loop;
    r4=*(int*)((char*)arg0+4); *(int*)((char*)arg0+4)=*(int*)((char*)arg0+8); *(int*)((char*)arg0+8)=r4;
}
#pragma scheduling on
extern float lbl_80562FB0;
extern float lbl_80562FD4;
extern float lbl_80562FD8;
#pragma scheduling invalid_target
void fn_801F64E4(void *arg0, float *arg1, float arg2) {
    float sp10, spC, sp8;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
    int r0, r4, r6, r7;
    void *r5, *r8;
    float *p4;
    r7 = 0;
    r6 = 0;
    f9 = lbl_80562FD4 - arg2;
    f10 = -(lbl_80562FB0 - arg2);
    p4 = arg1;
    while (r7 < *(int *)((char *)arg0 + 0x10)) {
        r5 = *(void **)((char *)arg0 + 4);
        r7++;
        r0 = *(int *)((char *)arg0 + 8);
        r8 = (char *)r5 + r6;
        r5 = (char *)r0 + r6;
        f0 = *p4;
        f3 = *(float *)r8;
        f1 = *(float *)((char *)r0 + r6);
        f2 = f0 * lbl_80562FD8;
        f8 = f3 * f9;
        f3 = *(float *)((char *)r8 + 4);
        f1 = f1 * f10;
        f0 = *(float *)((char *)r5 + 4);
        f7 = f3 * f9;
        f4 = f0 * f10;
        f6 = *(float *)((char *)r8 + 8);
        f5 = f8 + f1;
        f3 = *(float *)((char *)r5 + 8);
        f1 = p4[1];
        f0 = p4[2];
        f6 = f6 * f9;
        f3 = f3 * f10;
        sp8 = f8;
        f2 = f5 + f2;
        f4 = f7 + f4;
        f1 = f1 * lbl_80562FD8;
        *(float *)((char *)r0 + r6) = f2;
        f3 = f6 + f3;
        f0 = f0 * lbl_80562FD8;
        f1 = f4 + f1;
        spC = f7;
        f0 = f3 + f0;
        sp10 = f6;
        *(float *)((char *)r5 + 4) = f1;
        sp8 = f5;
        spC = f4;
        sp10 = f3;
        *(float *)((char *)r5 + 8) = f0;
        r6 += 0xC;
        p4 += 3;
    }
    r4 = *(int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = *(int *)((char *)arg0 + 8);
    *(int *)((char *)arg0 + 8) = r4;
}
#pragma scheduling on
#pragma push
#pragma paired off
#pragma paired_single off
extern float PSVECDotProduct(const void *, const void *);
#pragma pop
extern float lbl_80562FDC;
extern float lbl_80562FE0;
#pragma push
#pragma paired reset
#pragma paired_single reset
void fn_801F65D0(void *arg0) {
    float delta[3];
    register float var_f31;
    register float var_f30;
    float weight, dot;
    int offset, i;
    unsigned char *entry;
    float *a, *b;

    var_f31 = lbl_80562FDC;
    var_f30 = lbl_80562FE0;
    i = 0;
    offset = 0;
    goto check;

loop:
    entry = *(unsigned char **)((char *)arg0 + 0x14) + offset;
    a = (float *)(*(unsigned char **)((char *)arg0 + 4) +
                  *(unsigned short *)entry * 0xC);
    b = (float *)(*(unsigned char **)((char *)arg0 + 4) +
                  *(unsigned short *)(entry + 2) * 0xC);
    delta[0] = b[0] - a[0];
    delta[1] = b[1] - a[1];
    delta[2] = b[2] - a[2];
    dot = PSVECDotProduct(delta, delta);
    weight = *(float *)(entry + 4);
    offset += 8;
    i += 1;
    weight = var_f31 - weight / (weight + dot);
    a[0] += delta[0] * (var_f31 * weight);
    a[1] += delta[1] * (var_f31 * weight);
    a[2] += delta[2] * (var_f31 * weight);
    b[0] += delta[0] * (var_f30 * weight);
    b[1] += delta[1] * (var_f30 * weight);
    b[2] += delta[2] * (var_f30 * weight);
check:
    if (i < *(int *)((char *)arg0 + 0x18)) goto loop;
}
#pragma pop

#pragma dont_inline on
void fn_801F6728(void *arg0) {
    int i;
    int offset;
    unsigned short index;
    char *records;
    char *record;
    char *output;
    i = 0;
    offset = 0;
    records = *(char **)((char *)arg0 + 0x1C);
    while (i < *(int *)((char *)arg0 + 0x20)) {
        record = records + offset;
        output = *(char **)((char *)arg0 + 4);
        index = *(unsigned short *)(records + offset);
        *(float *)(output + index * 0xC) = *(float *)(record + 4);
        *(float *)(output + index * 0xC + 4) = *(float *)(record + 8);
        *(float *)(output + index * 0xC + 8) = *(float *)(record + 0xC);
        offset += 0x10;
        i++;
    }
}
#pragma dont_inline off

extern void fn_801E8CB8(float *, float *);
extern float fn_80287BC8(float, float);
extern float lbl_80562FE4;
void fn_801F6778(float *out, int count, float *angles, float offset, float scale, float unused) {
    float spC, sp8;
    float f6, f4, f31, f30, f29, f28, f27, f26;
    int i;
    float *dst;
    dst = out;
    sp8 = lbl_80562FE4;
    fn_801E8CB8(&spC, &sp8);
    i = 0;
    f6 = sp8 * scale;
    f4 = spC; /* placeholder overwritten below */
    f31 = spC * f6;
    f29 = spC * f6;
    f30 = spC * f6 - offset;
    f28 = angles[0] * f6;
    f27 = angles[1] * f6;
    f26 = angles[2] * f6;
    while (i < count) {
        dst[0] = f31 + fn_80287BC8(-f28, f28);
        dst[1] = f30 + fn_80287BC8(-f27, f27);
        dst[2] = f29 + fn_80287BC8(-f26, f26);
        i++;
        dst += 3;
    }
}

#pragma paired_single off
#pragma scheduling invalid_target
void fn_801F6880(void *arg0) {
    extern float fn_802C9A4C(float);
    extern void fn_802C8BD0(void *);
    extern int fn_802C8DBC(int);
    extern void fn_802C8E00(int, int, void *, float, float, float, float, float);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    float temp_f31;
    int temp_r0, temp_r0_2, temp_r3, temp_r4, temp_r5_2;
    int var_r30, var_r31, var_r28;
    void *temp_r3_2, *temp_r3_3, *temp_r5, *temp_r5_3;

    temp_f31 = fn_802C9A4C(*(float *)((char *)arg0 + 0x28));
    fn_802C8BD0(*(void **)((char *)arg0 + 0x24));
    if (fn_802C8DBC((*(int *)((char *)arg0 + 0x30) - 1) *
                    (*(int *)((char *)arg0 + 0x2C) * 2)) != 0) {
        var_r31 = 1;
        goto row_setup;
    inner_body:
        temp_r0 = *(int *)((char *)arg0 + 0x2C);
        temp_r4 = (var_r30 + var_r28 * temp_r0) * 0xC;
        temp_r0_2 = *(int *)((char *)arg0 + 0xC);
        temp_r3 = *(int *)((char *)arg0 + 4);
        temp_r3_2 = (void *)(temp_r3 + temp_r4);
        temp_r5 = (void *)(temp_r0_2 + temp_r4);
        fn_802C8E00(*(int *)((char *)temp_r5 + 8), var_r30 > 0, temp_r5,
                    *(float *)(temp_r3 + temp_r4),
                    *(float *)((char *)temp_r3_2 + 4),
                    *(float *)((char *)temp_r3_2 + 8),
                    *(float *)(temp_r4 + temp_r0_2),
                    *(float *)((char *)temp_r5 + 4));
        temp_r5_2 = (var_r30 + var_r31 * *(int *)((char *)arg0 + 0x2C)) * 0xC;
        temp_r3_3 = (void *)(*(int *)((char *)arg0 + 0xC) + temp_r5_2);
        temp_r5_3 = (void *)(*(int *)((char *)arg0 + 4) + temp_r5_2);
        fn_802C8E00(*(int *)((char *)temp_r3_3 + 8), var_r30 > 0, temp_r5_3,
                    *(float *)temp_r5_3,
                    *(float *)((char *)temp_r5_3 + 4),
                    *(float *)((char *)temp_r5_3 + 8),
                    *(float *)temp_r3_3,
                    *(float *)((char *)temp_r3_3 + 4));
        var_r30 += 1;
    inner_check:
        if (var_r30 < *(int *)((char *)arg0 + 0x2C)) goto inner_body;
        var_r31 += 1;
    outer_check:
        if (var_r31 < *(int *)((char *)arg0 + 0x30)) goto row_setup;
        goto done;
    row_setup:
        var_r28 = var_r31 - 1;
        var_r30 = 0;
        goto inner_check;
    done:
        fn_802C8E48();
    }
    fn_802C8D74();
    fn_802C9A4C(temp_f31);
}
#pragma scheduling on
#pragma paired_single reset

void *fn_801F69C8(void *arg0) {
    memset(arg0,0,0x900);
    *(int *)((char *)arg0+0x900)=0;
    return arg0;
}

#pragma scheduling invalid_target
FN_801F6A08_RETURN fn_801F6A08(void *arg0, int arg1) {
    void *entry;
    int i;

    if (arg0 != 0) {
        entry = arg0;
        i = 0;
        goto check;
    loop:
        fn_801F639C(entry);
        entry = (char *)entry + 0x48;
        i++;
    check:
        if (i < *(int *)((char *)arg0 + 0x900)) {
            goto loop;
        }
        *(int *)((char *)arg0 + 0x900) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern float fn_801E7E24(void);
extern unsigned char fn_802CDB20(int, int);
#pragma scheduling invalid_target
void fn_801F6A98(void *arg0, int arg1) {
    extern float lbl_80558DC4;
    float sp[6];
    float offset, scale;
    int enabled;
    void *entry;
    int i;

    enabled = !((float)__fabs((double)fn_801E7E24()) <= lbl_80558DC4);
    entry = arg0;
    i = 0;
    goto check;
loop:
    if (enabled != 0) {
        scale = *(float *)((char *)entry + 0x40);
        offset = *(float *)((char *)entry + 0x3C);
        fn_801E8C84(&sp[0]);
        sp[3] = sp[0] * scale;
        sp[5] = sp[2] * scale;
        sp[4] = sp[1] * scale - offset;
        fn_801F63F0(entry, &sp[3], *(float *)((char *)entry + 0x44));
    }
    fn_801F65D0(entry);
    fn_801F6728(entry);
    *(unsigned char *)((char *)entry + 0x38) =
        fn_802CDB20(arg1, *(int *)((char *)entry + 0x34));
    entry = (char *)entry + 0x48;
    i++;
check:
    if (i < *(int *)((char *)arg0 + 0x900)) goto loop;
}
#pragma scheduling on
extern void fn_801F602C(void *, int, int, int, int);
extern char lbl_8033ADF8[];
__declspec(section ".sdata") extern char lbl_8055B19C[];
__declspec(section ".sdata") extern char lbl_8055B1A8[];
__declspec(section ".sdata") extern char lbl_8055B1B0[];
__declspec(section ".sdata") extern char lbl_8055B1B8[];
extern float lbl_80562FE8;
typedef float (*Getter)(void *, const char *);
typedef void (*Setter)(void *, const char *);
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801F6C04(void *self, int a, int b, void *object, int flags, int extra) {
    int count, got;
    unsigned char *slot;
    int old;
    DummyObj_801F7280 *object2;

    count = *(int *)((char *)self + 0x900);
    if (count >= 0x20) fn_802E317C(lbl_8033ADF8);
    count = *(int *)((char *)self + 0x900);
    slot = (unsigned char *)self + count * 0x48;
    object2 = (DummyObj_801F7280 *)object;
    old = fn_801F4E44(object2->d5(lbl_8055B19C));
    got = fn_801F4ECC(object);
    fn_801F602C(slot, a, b, old, got);
    *(int *)(slot + 0x34) = flags;
    slot[0x38] = 1;
    *(float *)(slot + 0x3C) = lbl_80562FE8 * object2->d9(lbl_8055B1A8);
    *(float *)(slot + 0x40) = object2->d9(lbl_8055B1B0);
    *(float *)(slot + 0x44) = object2->d9(lbl_8055B1B8);
    *(int *)((char *)self + 0x900) = *(int *)((char *)self + 0x900) + 1;
}
#pragma cplusplus reset
#pragma dont_inline off

void *fn_801F6D20(void *arg0) {
    int size = 0x2A0;
    memset(arg0, 0, size);
    *(int *)((char *)arg0 + 0x2A0) = 0;
    return arg0;
}

void *fn_801F6D60(void *arg0, int arg1) {
    if (arg0 != 0) {
        void *entry = arg0;
        int i = 0;
        for (; i < *(int *)((char *)arg0 + 0x2A0); entry = (char *)entry + 0x54, i++) {
            fn_801F639C(entry);
        }
        *(int *)((char *)arg0 + 0x2A0) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern char lbl_8033AE20[], lbl_8033AE48[];
extern int fn_801F4E44(const char *);
extern int fn_801F4ECC(void *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801F6F3C(void *arg0, int arg1, int arg2, void *arg3, int arg4) {
    class DummyDispatch {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual const char *getName(const char *);
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual float getFloat(const char *);
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual Vec3_801F4F9C getVector(const char *);
    };

    char *slot;
    int old, got;
    Vec3_801F4F9C sp;

    if (*(int *)((char *)arg0 + 0x2A0) >= 8) {
        fn_802E317C(lbl_8033AE20);
    }
    slot = (char *)arg0 + *(int *)((char *)arg0 + 0x2A0) * 0x54;
    old = ((int (*)(const char *))fn_801F4E44)(
        ((DummyDispatch *)arg3)->getName(lbl_8055B19C));
    got = ((int (*)(void *))fn_801F4ECC)(arg3);
    fn_801F602C(slot, arg1, arg2, old, got);
    *(int *)(slot + 0x34) = arg4;
    slot[0x38] = 1;
    *(float *)(slot + 0x3C) =
        lbl_80562FE8 * ((DummyDispatch *)arg3)->getFloat(lbl_8055B1A8);
    *(float *)(slot + 0x40) = ((DummyDispatch *)arg3)->getFloat(lbl_8055B1B0);
    *(float *)(slot + 0x44) = ((DummyDispatch *)arg3)->getFloat(lbl_8055B1B8);
    sp = ((DummyDispatch *)arg3)->getVector(lbl_8033AE48);
    *(float *)(slot + 0x48) = sp.x;
    *(float *)(slot + 0x4C) = sp.y;
    *(float *)(slot + 0x50) = sp.z;
    *(int *)((char *)arg0 + 0x2A0) =
        *(int *)((char *)arg0 + 0x2A0) + 1;
}
#pragma cplusplus off
#pragma pop
void *fn_801F7090(void *arg0) {
    memset(arg0,0,0x120);
    *(int *)((char *)arg0+0x120)=0;
    return arg0;
}

extern void fn_801F639C(void *);
extern void fn_801F6880(void *);
void fn_801F70D0(void *arg0, int arg1) {
    int i;
    void *entry;
    if (arg0 != 0) {
        entry = arg0;
        i = 0;
        do {
            fn_801F639C(entry);
            entry = (char *)entry + 0x48;
            i++;
        } while (i < *(int *)((char *)arg0 + 0x120));
        *(int *)((char *)arg0 + 0x120) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
}

extern void fn_801E8C84(float *);
void fn_801F7160(void *arg0) {
    float sp[6];
    float offset, scale;
    void *entry;
    int i;

    entry = arg0;
    i = 0;
    while (i < *(int *)((char *)arg0 + 0x120)) {
        scale = *(float *)((char *)entry + 0x40);
        offset = *(float *)((char *)entry + 0x3C);
        fn_801E8C84(&sp[0]);
        sp[3] = sp[0] * scale;
        sp[5] = sp[2] * scale;
        sp[4] = sp[1] * scale - offset;
        fn_801F63F0(entry, &sp[3], *(float *)((char *)entry + 0x44));
        fn_801F65D0(entry);
        fn_801F6728(entry);
        entry = (char *)entry + 0x48;
        i++;
    }
}

#pragma dont_inline on
void fn_801F7220(void *arg0) {
    void *entry;
    int i;
    i = 0;
    entry = arg0;
    while (i < *(int *)((char *)arg0 + 0x120)) {
        fn_801F6880(entry);
        entry = (char *)entry + 0x48;
        i++;
    }
}

__declspec(section ".sdata") extern char lbl_8055B19C[];
__declspec(section ".sdata") extern char lbl_8055B1A8[];
__declspec(section ".sdata") extern char lbl_8055B1B0[];
__declspec(section ".sdata") extern char lbl_8055B1B8[];
__declspec(section ".sdata") extern char lbl_8055B1C0[];
#pragma cplusplus on
extern "C" void fn_801F7280(void *arg0, void *arg1, void *arg2) {
    char sp8[0x68];
    int got;
    char *slot;
    int value;
    int old;
    DummyObj_801F7280 *object;
    if (*(int *)((char *)arg0 + 0x120) >= 4) {
        fn_802E317C(lbl_8033AE54);
    }
    got = fn_801F4ECC(arg1);
    if (got & 1) {
        fn_802E317C(lbl_8033AE78);
    }
    slot = (char *)arg0 + *(int *)((char *)arg0 + 0x120) * 0x48;
    object = (DummyObj_801F7280 *)arg1;
    value = (int)object->d5(lbl_8055B1C0);
    old = fn_801F4E44(object->d5(lbl_8055B19C));
    fn_801F5344(sp8, arg1, arg2);
    fn_801F602C(slot, (int)sp8, value, old, got);
    *(int *)(slot + 0x34) = -1;
    slot[0x38] = 1;
    *(float *)(slot + 0x3C) = lbl_80562FE8 * object->d9(lbl_8055B1A8);
    *(float *)(slot + 0x40) = object->d9(lbl_8055B1B0);
    *(float *)(slot + 0x44) = object->d9(lbl_8055B1B8);
    *(int *)((char *)arg0 + 0x120) = *(int *)((char *)arg0 + 0x120) + 1;
}
#pragma cplusplus reset
extern void fn_801F6A98();
void fn_801F73E0(void) {
    fn_801F6A98(lbl_8055EC10);
}

extern void fn_801F6B98(void *);
void fn_801F73E8(void) { fn_801F6B98(lbl_8055EC10); }

extern void fn_801F6DF0(void *);
void fn_801F73F0(void) { fn_801F6DF0(lbl_8055EC14); }

#pragma dont_inline on
void fn_801F6EC0(void *arg0) {
    int i;
    void *p, *q;
    i = 0;
    p = arg0;
    q = arg0;
    while (i < *(int *)((char *)arg0 + 0x2A0)) {
        if (*(unsigned char *)((char *)p + 0x38) != 0) fn_801F6880(q);
        p = (char *)p + 0x54;
        q = (char *)q + 0x54;
        i++;
    }
}
#pragma dont_inline reset
void fn_801F73F8(void) { fn_801F6EC0(lbl_8055EC14); }

extern char lbl_8033AD7C[], lbl_8033AD88[];
extern float lbl_80562FB8;
void fn_801F7400(void *out, void *base, void *obj) {
    int a=*(int*)((char*)base+0x60), b=*(int*)((char*)base+0x5c), c=*(int*)((char*)base+0x58);
    char *p=(char*)base+c*0x18, *q=(char*)base+b*0x18, *r=(char*)base+a*0x18;
    *(int*)((char*)out+0x34)=*(int*)(r+0x14); *(int*)((char*)out+0x38)=*(int*)(r+0x18); *(int*)((char*)out+0x30)=*(int*)(r+0x10);
    *(int*)((char*)out+0x18)=*(int*)(q+0x10); *(int*)((char*)out+0x1c)=*(int*)(q+0x14); *(int*)((char*)out+0x20)=*(int*)(q+0x18);
    *(int*)((char*)out+0x28)=*(int*)(q+0x20); *(int*)((char*)out+0x2c)=*(int*)(q+0x24); *(int*)((char*)out+0x24)=*(int*)(q+0x1c);
    *(int*)out=*(int*)(p+0x10); *(int*)((char*)out+4)=*(int*)(p+0x14); *(int*)((char*)out+8)=*(int*)(p+0x18); *(int*)((char*)out+0xc)=*(int*)(p+0x1c);
    *(int*)((char*)out+0x10)=*(int*)(p+0x20); *(int*)((char*)out+0x14)=*(int*)(p+0x24);
    *(int*)((char*)out+0x3c)=*(int*)(r+0x1c); *(int*)((char*)out+0x54)=*(int*)(q+0x1c);
    *(float*)((char*)out+0x40)=*(float*)(r+0x20); *(float*)((char*)out+0x44)=*(float*)(r+0x24);
    *(float*)((char*)out+0x28)=*(float*)(q+0x20); *(float*)((char*)out+0x2c)=*(float*)(q+0x24);
    *(float*)((char*)out+0x10)=*(float*)(p+0x20); *(float*)((char*)out+0x14)=*(float*)(p+0x24);
    *(float*)((char*)out+0x48)=(*(float*)((char*)out+0x30)+*(float*)((char*)out+0x18))-*(float*)out;
    *(float*)((char*)out+0x4c)=(*(float*)((char*)out+0x34)+*(float*)((char*)out+0x1c))-*(float*)((char*)out+4);
    *(float*)((char*)out+0x50)=(*(float*)((char*)out+0x38)+*(float*)((char*)out+0x20))-*(float*)((char*)out+8);
    *(float*)((char*)out+0x58)=(*(float*)(q+0x20)+*(float*)(r+0x20))-*(float*)(p+0x20);
    *(float*)((char*)out+0x5c)=(*(float*)(q+0x24)+*(float*)(r+0x24))-*(float*)(p+0x24);
    if (((int(*)(void*,int,void*,int))fn_801F52BC)(obj,(int)lbl_8033AD7C,(char*)out+0x60,4)==0) *(float*)((char*)out+0x60)=lbl_80562FB8;
    if (((int(*)(void*,int,void*,int))fn_801F52BC)(obj,(int)lbl_8033AD88,(char*)out+0x64,4)==0) *(float*)((char*)out+0x64)=lbl_80562FB8;
}

#pragma scheduling invalid_target
extern void *fn_802C9C24(void *);
extern void fn_802CD320(void *, int);
extern char lbl_8033AF20[];
extern char lbl_8033AF08[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801F75A4(void *arg0, void *arg1, void *arg2, int arg3) {
    char *data = lbl_8033AC68;
    void *sp8[0x1A];
    void *temp_r30;
    void *temp_r29;
    void **allocated;

    temp_r30 = ((void *(*)(void *))fn_802AE414)(arg1);
    if (temp_r30 == 0) {
        fn_802E317C(data + 0x80, arg1);
    }
    temp_r29 = fn_802C9C24(*(void **)((char *)*(void **)((char *)arg0 + 8) + 4));
    fn_801F7400(sp8, arg1, temp_r30);

    if ((fn_801F4ECC(temp_r30) & 1) == 0) {
        ((void (*)(void *, void *, void *, void *, int))fn_801F6C04)(
            lbl_8055EC10, sp8, temp_r29, temp_r30, arg3);
        if (arg2 != 0 && lbl_8055EC1C == 0) {
            allocated = ((void **(*)(int, void *))fn_801284F8)(4, data + 0x240);
            if (allocated != 0) {
                *allocated = lbl_8033AF20;
                lbl_8055EC1C = allocated;
                fn_802CD320(arg2, (int)allocated);
            }
        }
    } else {
        fn_801F6F3C(lbl_8055EC14, (int)sp8, (int)temp_r29, temp_r30, arg3);
        if (arg2 != 0 && lbl_8055EC20 == 0) {
            allocated = ((void **(*)(int, void *))fn_801284F8)(4, data + 0x254);
            if (allocated != 0) {
                *allocated = lbl_8033AF08;
                lbl_8055EC20 = allocated;
                fn_802CD320(arg2, (int)allocated);
            }
        }
    }
}
#pragma pop

void fn_801F76F8(void *arg0, unsigned char *p) {
    unsigned char a,b,c,d,e,f,g,h;
    int i;
    a=p[0x2c]; b=p[0x2d]; c=p[0x2e]; d=p[0x2f];
    e=p[0x30]; f=p[0x31]; g=p[0x32]; h=p[0x33];
    p[0x2c]=p[0x3b]; p[0x3b]=a; p[0x2d]=p[0x3a]; p[0x3a]=b;
    p[0x2e]=p[0x39]; p[0x39]=c; p[0x2f]=p[0x38]; p[0x38]=d;
    p[0x30]=p[0x37]; p[0x37]=e; p[0x31]=p[0x36]; p[0x36]=f;
    p[0x32]=p[0x35]; p[0x35]=g; p[0x33]=p[0x34]; p[0x34]=h;
    for (i=0;i<3;i++) {
        unsigned char *q=p+0x3c+i*0x18;
        a=q[0]; q[0]=q[3]; q[3]=a; a=q[1]; q[1]=q[2]; q[2]=a;
        a=q[4]; q[4]=q[7]; q[7]=a; a=q[5]; q[5]=q[6]; q[6]=a;
        a=q[8]; q[8]=q[0xb]; q[0xb]=a; a=q[9]; q[9]=q[0xa]; q[0xa]=a;
        a=q[0xc]; q[0xc]=q[0xf]; q[0xf]=a; a=q[0xd]; q[0xd]=q[0xe]; q[0xe]=a;
        a=q[0x10]; q[0x10]=q[0x13]; q[0x13]=a; a=q[0x11]; q[0x11]=q[0x12]; q[0x12]=a;
        a=q[0x14]; q[0x14]=q[0x17]; q[0x17]=a; a=q[0x15]; q[0x15]=q[0x16]; q[0x16]=a;
    }
    a=p[0x84]; b=p[0x85]; c=p[0x86]; d=p[0x87]; e=p[0x88]; f=p[0x89];
    p[0x84]=p[0x8f]; p[0x8f]=a; p[0x85]=p[0x8e]; p[0x8e]=b;
    p[0x86]=p[0x8d]; p[0x8d]=c; p[0x87]=p[0x8c]; p[0x8c]=d;
    p[0x88]=p[0x8b]; p[0x8b]=e; p[0x89]=p[0x8a]; p[0x8a]=f;
}

void fn_801F78D8(void) {

}

extern void fn_801F75A4();
#pragma scheduling invalid_target
void fn_801F78DC(void *arg0, void *arg1) {
    fn_801F75A4(arg1, (char *)arg1 + 0x2C, arg0);
}
#pragma scheduling on
extern const char lbl_8033AECC[];
extern const char lbl_8033AED8[];
#pragma scheduling invalid_target
void *fn_801F78F0(void) {
    void **p = fn_801284F8(4, (void*)lbl_8033AECC);
    if (p != 0) {
        *p = (void*)lbl_8033AED8;
    }
    return p;
}
#pragma scheduling on

int fn_801F7930(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801F7970(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern int fn_80128668(void);
int fn_801F79B0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801F79F0(void) { return 3; }

int fn_801F79F8(void) { return 3; }

void fn_801F7A00(void) {

}
extern float lbl_80562FB0;
extern float lbl_80562FD4;
extern float lbl_80562FD8;
