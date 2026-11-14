// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80182010(void);
extern void *fn_801A644C(void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern void fn_801A6520(void);
extern char lbl_80333CA8[];
extern char lbl_80333CB8[];
extern int lbl_8055E3C4;
extern float lbl_80562434;
extern int fn_801E89EC(void);

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))

#pragma cplusplus on
struct Fn801A6C14Dispatch {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(float *);
};
#pragma cplusplus reset

extern float lbl_80562418;
extern float lbl_8056241C;
extern double lbl_80562420;
extern float lbl_80562428;
extern float *fn_80265D98(void);
extern void fn_8012F57C(int, void *, void *, float);
#pragma dont_inline on
float fn_801A6370(float arg0, float arg1, float arg2, float arg3) {
    return arg0 + arg1 * arg3 + arg3 * (arg3 * (lbl_80562418 * arg2));
}
#pragma dont_inline reset

float fn_801A6390(int arg0, int arg1) {
    return (float)(arg0 - arg1) * lbl_8056241C;
}

#pragma dont_inline on
#pragma scheduling invalid_target
float fn_801A63C4(int arg0, int arg1) {
    return (lbl_80562428 * fn_801A6390(arg0, arg1)) / lbl_8056241C;
}
#pragma scheduling on
#pragma dont_inline off

void fn_801A63F4(void *arg0, void *arg1, void *arg2, void *arg3) {
    float *out = (float *)arg0;
    float *a = (float *)arg1;
    float *b = (float *)arg2;
    float *t = (float *)arg3;
    float bz;
    float by;
    float ax;
    float bx;
    float ay;
    float tz;
    float ty;
    float tx;
    float az;
    bz = b[2];
    by = b[1];
    bx = b[0];
    ax = a[0];
    ay = a[1];
    tz = t[2];
    ty = t[1];
    tx = t[0];
    az = a[2];
    out[2] = az + tz * (bz - az);
    out[1] = ay + ty * (by - ay);
    out[0] = ax + tx * (bx - ax);
}

#pragma dont_inline on
void *fn_801A644C(void *arg0) {
    memset(arg0, 0, 0xC);
    return arg0;
}
#pragma dont_inline off

void *fn_801A6484(void *arg0) {
    /* Initialize this object: run base init, set vtable, clear embedded
     * 0xC-byte entries at +0x2708..+0x272C, and create/store its netcar task. */
    char *end;
    char *current;
    void *handle;

    fn_80182010();
    *(void **)arg0 = &lbl_80333CB8;
    current = (char *)arg0 + 0x2708;
    end = (char *)arg0 + 0x272C;
    do {
        fn_801A644C(current);
        current += 0xC;
    } while (current < end);
    fn_801A644C(end);
    handle = fn_8012850C(0xF7, &lbl_80333CA8);
    *(void **)((char *)arg0 + 0x2700) =
        ((void *(*)(void *, void (*)(void), int, int, int))fn_8002F37C)(
            handle, fn_801A6520, 0, 0x4D, 3);
    return arg0;
}

void fn_801A6520(void) {
}

extern void fn_8018381C(void);
extern void fn_801A6558(void *);
extern void fn_801A67B0(void *);
extern void *fn_802E2C20(void);
extern void fn_80182010(void);
extern void *fn_801A644C(void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern float lbl_8056242C;
extern float lbl_80562430;
extern void fn_801A6520(void);
extern void fn_801BE168(void *, void *, void *, void *);
extern void fn_801A7444(void *);
#pragma cplusplus on
struct Fn801A67C4Vt {
    virtual void d0(); virtual void d1(); virtual char *d2(); virtual void d3();
    virtual char *d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9();
};
#pragma cplusplus reset
void fn_801A6524(void *arg0) {
    fn_8018381C();
    fn_801A6558(arg0);
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801A6558(void *arg0) {
    float zero;
    float one;
    void *tmp;
    char *p = (char *)arg0;
    *(int *)(p + 0x2778) = 4;
    tmp = fn_802E2C20();
    zero = lbl_80562430;
    one = lbl_8056242C;
    *(void **)(p + 0x277C) = tmp;
    *(float *)(p + 0x273C) = one;
    *(float *)(p + 0x2738) = one;
    *(int *)(p + 0x2704) = 0;
    *(float *)(p + 0x272C) = zero;
    *(float *)(p + 0x2730) = zero;
    *(float *)(p + 0x2734) = zero;
    *(float *)(p + 0x2708) = zero;
    *(float *)(p + 0x270C) = zero;
    *(float *)(p + 0x2710) = zero;
    *(float *)(p + 0x2714) = zero;
    *(float *)(p + 0x2718) = zero;
    *(float *)(p + 0x271C) = zero;
    *(float *)(p + 0x2720) = zero;
    *(float *)(p + 0x2724) = zero;
    *(float *)(p + 0x2728) = zero;
    memset(*(void **)(p + 0x2700), 0, 0xE7);
    if (*(unsigned char *)(p + 0x2740))
        fn_801A67B0(arg0);
}
#pragma scheduling on
#pragma dont_inline reset
extern void fn_80182074(void);
extern void *fn_801B2EC0(int);
extern void fn_80265D40(void *, int, float);
#pragma scheduling invalid_target
/* Reset the camera/vehicle state: initialize internals, bind the tracked object for slot 0x1EC, clear runtime flags, seed default scalar fields, then notify 80265D40 and mark state active (0x267C). */
void fn_801A65FC(void *obj) {
    float zeroValue;
    float oneValue;
    int objectSlot;
    fn_80182074();
    *(void **)((char *)obj + 0x2774) =
        fn_801B2EC0(*(int *)((char *)obj + 0x1EC));
    *(volatile unsigned char *)((char *)obj + 0x2740) = 0;
    *(volatile unsigned char *)((char *)obj + 0x2741) = 1;
    fn_801A6558(obj);
    zeroValue = *(volatile float *)&lbl_80562430;
    oneValue = *(volatile float *)&lbl_8056242C;
    *(volatile float *)((char *)obj + 0x2748) = zeroValue;
    objectSlot = *(volatile int *)((char *)obj + 0x1EC);
    *(volatile float *)((char *)obj + 0x2744) = oneValue;
    *(volatile float *)((char *)obj + 0x274C) = zeroValue;
    *(volatile float *)((char *)obj + 0x2750) = zeroValue;
    *(volatile float *)((char *)obj + 0x2754) = oneValue;
    *(volatile float *)((char *)obj + 0x2758) = zeroValue;
    *(volatile float *)((char *)obj + 0x275C) = zeroValue;
    *(volatile float *)((char *)obj + 0x2760) = zeroValue;
    *(volatile float *)((char *)obj + 0x2764) = oneValue;
    *(volatile float *)((char *)obj + 0x2768) = zeroValue;
    *(volatile float *)((char *)obj + 0x276C) = zeroValue;
    *(volatile float *)((char *)obj + 0x2770) = zeroValue;
    fn_80265D40(obj, objectSlot, oneValue);
    *(int *)((char *)obj + 0x267C) = 1;
}
#pragma scheduling on
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern void fn_801836E0(void *, int);
extern void fn_80265D44(void);
/* Destructor-like cleanup: installs vtable lbl_80333CB8, releases owned buffer at +0x2700, resets state, and optionally frees the object. */
void *fn_801A669C(void *object, int shouldFree) {
    if (object != 0) {
        *(void **)object = (char *)lbl_80333CB8;
        fn_80265D44();
        if (*(int *)((char *)object + 0x2700) != 0)
            fn_80128670(*(int *)((char *)object + 0x2700) - 0x10);
        *(int *)((char *)object + 0x2700) = 0;
        fn_801836E0(object, 0);
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_801A6724(void *arg0) {
    int ret;
    if (*(int *)((char *)arg0 + 0x2704) > 0) {
        float v = fn_801A6390(lbl_8055E3C4, *(int *)(*(char **)((char *)arg0 + 0x2700) + 4));
        ret = (v > lbl_80562434);
    } else {
        ret = 0;
        if (fn_801E89EC() == 1 && ((int)fn_802E2C20() - *(int *)((char *)arg0 + 0x277C) > 0x7D0)) {
            ret = 1;
        }
    }
    return ret;
}
#pragma scheduling on
#pragma dont_inline reset

extern float lbl_80562438;
void fn_801A67B0(void *arg0) {
    float value = lbl_80562438;
    *(int *)((char *)arg0 + 0x2704) = 1;
    *(float *)((char *)arg0 + 0x11C) = value;
}

extern void fn_8017A580(void *);
extern int fn_801A6724(void *);
extern void fn_8018ADA4(void *, float);
extern void fn_8018ADB4(void *, float);
extern void fn_8018ADBC(void *, float);
extern void fn_8018ADC4(void *, float);
extern void fn_8018ADCC(void *, float);
extern void fn_8018ADD4(void *, int);
extern void fn_80136EA4(int, int);
extern int lbl_8055E0D0;
#pragma cplusplus on
/* Per-frame update of a camera that follows a move record.
 *
 * The camera (the object fn_801A6484 builds) keeps:
 *   0x3C    its pose, a 3x4 matrix the node is drawn with; 0x2744 the pose a
 *             finished move hands back for it
 *   0x118, 0x124
 *           the camera's up and side vectors
 *   0x2610  the game state the camera runs in; 0x2778 the state it ran in last
 *             frame and 0x277C the time (fn_802E2C20, ms) it entered it
 *   0x2700  the move record it follows; 0x2704 what that move is doing (0
 *             idle, 1 running, 3 just ended), 0x2740 that one is running and
 *             0x2741 that one has just ended
 *   0x2774  the object the camera is attached to; 0x1EC its slot index
 *
 * Restarts the state timer when the state changed.  While the move still has
 * time left (fn_801A6724) the update only gives the move up, and only if the
 * attached object went away; once the time is up the move stops, the saved
 * pose is copied into the node, its up and side vectors are cleared and the
 * pose is pushed into the scene's record for the slot (fn_801BE168).  A move
 * that has just ended (mode 3, no longer running) also hands the record's own
 * settings - the floats at 0xD, 0x9 and 0x11 and the id at 0x15 unless it is
 * -1 - to the camera and its slot record, notes the slot with the array
 * manager (fn_80136EA4) and updates the camera at once (fn_801A7444), unless
 * the camera has only just been started. */
extern "C" void fn_801A67C4(void *self) {
    char *cam = (char *)self;
    int state = *(int *)(cam + 0x2610);
    *(char *)(cam + 0x1e9) = 0;
    if (state != *(int *)(cam + 0x2778))
        *(void **)(cam + 0x277C) = fn_802E2C20();
    if (fn_801A6724(self) == 0) {
        if (*(unsigned char *)(cam + 0x2740) != 0) {
            char *attached = (*(Fn801A67C4Vt **)(cam + 0x2774))->d2();
            if (*(int *)(attached + 0x24) == 0) {
                *(unsigned char *)(cam + 0x2740) = 0;
                *(char *)(cam + 0x2741) = 1;
            }
        }
    } else {
        float zero;
        *(int *)(cam + 0x2704) = 0;
        *(unsigned char *)(cam + 0x2740) = 1;
        *(int *)(cam + 0x3C) = *(int *)(cam + 0x2744);
        *(int *)(cam + 0x40) = *(int *)(cam + 0x2748);
        *(int *)(cam + 0x44) = *(int *)(cam + 0x274C);
        *(int *)(cam + 0x48) = *(int *)(cam + 0x2750);
        *(int *)(cam + 0x4C) = *(int *)(cam + 0x2754);
        *(int *)(cam + 0x50) = *(int *)(cam + 0x2758);
        *(int *)(cam + 0x54) = *(int *)(cam + 0x275C);
        *(int *)(cam + 0x58) = *(int *)(cam + 0x2760);
        *(int *)(cam + 0x5C) = *(int *)(cam + 0x2764);
        *(int *)(cam + 0x60) = *(int *)(cam + 0x2768);
        *(int *)(cam + 0x64) = *(int *)(cam + 0x276C);
        *(int *)(cam + 0x68) = *(int *)(cam + 0x2770);
        fn_8017A580(self);
        zero = lbl_80562430;
        *(float *)(cam + 0x118) = zero;
        *(float *)(cam + 0x11C) = zero;
        *(float *)(cam + 0x120) = zero;
        *(float *)(cam + 0x124) = zero;
        *(float *)(cam + 0x128) = zero;
        *(float *)(cam + 0x12C) = zero;
        fn_8018ADBC(self, zero);
        fn_8018ADB4(self, lbl_80562430);
        fn_8018ADC4(self, lbl_80562430);
        (*(Fn801A67C4Vt **)(cam + 0x2774))->d7();
        fn_801BE168(*(void **)(cam + 0x1EC), cam + 0x3C, cam + 0x118, cam + 0x124);
    }
    if (*(unsigned char *)(cam + 0x2740) == 0 && *(int *)(cam + 0x2704) == 3) {
        fn_8018ADA4(self, *(float *)(*(char **)(cam + 0x2700) + 0xD));
        fn_8018ADCC(self, lbl_80562430);
        if (*(int *)(*(char **)(cam + 0x2700) + 0x15) != -1)
            fn_8018ADD4(self, *(int *)(*(char **)(cam + 0x2700) + 0x15));
        fn_8018ADC4(self, lbl_80562430);
        fn_8018ADBC(self, *(float *)(*(char **)(cam + 0x2700) + 0x9));
        fn_8018ADB4(self, *(float *)(*(char **)(cam + 0x2700) + 0x11));
        fn_80136EA4(lbl_8055E0D0, *(int *)(cam + 0x1EC));
        if ((state != 2 || *(int *)(cam + 0x2778) != 0) && state != 0)
            fn_801A7444(self);
        *(char *)(cam + 0x2741) = 0;
    }
    *(int *)(cam + 0x2778) = state;
}
#pragma cplusplus reset
extern int lbl_8055E3C4;
extern double lbl_80562440;
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" void fn_8017A580(void *);
extern "C" void fn_801A69F4(void *arg0, float *arg1) {
    char *p = (char *)arg0;
    int k = lbl_8055E3C4;
    float t[3];
    float out0[3], outA[3], outB[3];
    float a0;
    double a, b, c, d, x, y, z;
    a0 = fn_801A63C4(k, *(int *)(*(char **)(p + 0x2700) + 4));
    t[0] = fn_801A6370(*(float *)(*(char **)(p + 0x2700) + 0x1e), *(float *)(p + 0x2708), *(float *)(p + 0x272c), a0);
    t[1] = fn_801A6370(*(float *)(*(char **)(p + 0x2700) + 0x22), *(float *)(p + 0x270c), *(float *)(p + 0x2730), a0);
    t[2] = fn_801A6370(*(float *)(*(char **)(p + 0x2700) + 0x26), *(float *)(p + 0x2710), *(float *)(p + 0x2734), a0);
    a = fn_801A63C4(*(int *)(*(char **)(p + 0x2700) + 0x51), *(int *)(*(char **)(p + 0x2700) + 0x9e));
    b = fn_801A63C4(*(int *)(*(char **)(p + 0x2700) + 4), *(int *)(*(char **)(p + 0x2700) + 0x9e));
    c = fn_801A63C4(k, *(int *)(*(char **)(p + 0x2700) + 0x9e));
    d = c + c;
    x = (d - lbl_80562440 - b) / ((a - lbl_80562440) * (a - b));
    y = ((d - a) - b) / ((lbl_80562440 - a) * (lbl_80562440 - b));
    z = (d - lbl_80562440 - a) / ((b - lbl_80562440) * (b - a));
    {
        char *data = *(char **)(p + 0x2700);
        out0[0] = *(float *)(data + 0x6b) * x + *(float *)(data + 0xb8) * y + *(float *)(data + 0x1e) * z;
        data = *(char **)(p + 0x2700);
        out0[1] = *(float *)(data + 0x6f) * x + *(float *)(data + 0xbc) * y + *(float *)(data + 0x22) * z;
        data = *(char **)(p + 0x2700);
        out0[2] = *(float *)(data + 0x73) * x + *(float *)(data + 0xc0) * y + *(float *)(data + 0x26) * z;
    }
    fn_801A63F4(outA, p + 0x60, t, arg1 + 1);
    *(float *)(p + 0x60) = outA[0];
    *(float *)(p + 0x64) = outA[1];
    *(float *)(p + 0x68) = outA[2];
    fn_8017A580(arg0);
    fn_801A63F4(outB, p + 0x118, out0, arg1 + 1);
    *(float *)(p + 0x118) = outB[0];
    *(float *)(p + 0x11c) = outB[1];
    *(float *)(p + 0x120) = outB[2];
}
#pragma ppc_psq_save reset
#pragma cplusplus reset
extern void fn_801E9DC4(void *);
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_801A6C14(void *arg0) {
    struct { float prefix[3]; float matrix[9]; float vec[3]; float zero[3]; int count; short tag; } data;
    float *matrix;
    unsigned char temp_b2, temp_b1;
    float one, zero;
    int sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;
    float sp20;
    float sp1C;
    float sp18;
    float sp14;
    float temp_f10;
    float temp_f10_2;
    float temp_f11;
    float temp_f12;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f3;
    float temp_f3_2;
    float temp_f4;
    float temp_f4_2;
    float temp_f5;
    float temp_f5_2;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_f7_2;
    float temp_f8;
    float temp_f9;
    float temp_f9_2;
    void *temp_r3;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;

    matrix = data.matrix;
    one = lbl_8056242C;
    data.tag = -1;
    zero = lbl_80562430;
    temp_r4 = M2C_FIELD(arg0, void **, 0x2700);
    temp_f8 = M2C_FIELD(temp_r4, float *, 0x2A);
    temp_f2 = M2C_FIELD(temp_r4, float *, 0x2E);
    temp_f1 = M2C_FIELD(temp_r4, float *, 0x32);
    temp_f3 = temp_f8 + temp_f8;
    temp_f12 = temp_f2 + temp_f2;
    temp_f7 = M2C_FIELD(temp_r4, float *, 0x36);
    temp_f11 = temp_f1 + temp_f1;
    temp_f5 = temp_f8 * temp_f3;
    temp_f4 = temp_f2 * temp_f12;
    temp_f1_2 = temp_f1 * temp_f11;
    temp_f10 = temp_f7 * temp_f3;
    temp_f9 = temp_f2 * temp_f11;
    data.matrix[0] = one - (temp_f4 + temp_f1_2);
    temp_f2_2 = temp_f9 + temp_f10;
    temp_f10_2 = temp_f7 * temp_f12;
    temp_f6 = temp_f8 * temp_f11;
    temp_f9_2 = temp_f7 * temp_f11;
    data.matrix[4] = one - (temp_f5 + temp_f1_2);
    temp_f7_2 = temp_f8 * temp_f12;
    temp_f5_2 = temp_f6 + temp_f10_2;
    temp_f3_2 = temp_f6 - temp_f10_2;
    temp_f6_2 = temp_f7_2 - temp_f9_2;
    data.matrix[7] = temp_f9 - temp_f10;
    temp_f4_2 = temp_f7_2 + temp_f9_2;
    data.matrix[6] = temp_f5_2;
    data.matrix[3] = temp_f6_2;
    data.matrix[1] = temp_f4_2;
    data.matrix[2] = temp_f3_2;
    data.matrix[5] = temp_f2_2;
    data.matrix[8] = one - (temp_f5 + temp_f4);
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x2700);
    data.vec[0] = M2C_FIELD(temp_r4_2, float *, 0x1E);
    data.vec[1] = M2C_FIELD(temp_r4_2, float *, 0x22);
    temp_f1_3 = M2C_FIELD(temp_r4_2, float *, 0x26);
    data.vec[2] = temp_f1_3;
    data.zero[0] = zero;
    data.zero[1] = zero;
    data.zero[2] = zero;
    data.count = 0;
    fn_801E9DC4(&data.tag);
    ((Fn801A6C14Dispatch *)arg0)->d21(matrix);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_3, int *, 0x9A) = (int) M2C_FIELD(temp_r4_3, int *, 0);
    M2C_FIELD(temp_r4_3, int *, 0x9E) = (int) M2C_FIELD(temp_r4_3, int *, 4);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xA2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 8);
    M2C_FIELD(temp_r4_3, float *, 0xA3) = (float) M2C_FIELD(temp_r4_3, float *, 9);
    M2C_FIELD(temp_r4_3, float *, 0xA7) = (float) M2C_FIELD(temp_r4_3, float *, 0xD);
    M2C_FIELD(temp_r4_3, float *, 0xAB) = (float) M2C_FIELD(temp_r4_3, float *, 0x11);
    M2C_FIELD(temp_r4_3, int *, 0xAF) = (int) M2C_FIELD(temp_r4_3, int *, 0x15);
    M2C_FIELD(temp_r4_3, float *, 0xB3) = (float) M2C_FIELD(temp_r4_3, float *, 0x19);
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1D);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB7) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB8) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1F);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x20);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB9) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBA) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x21);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x22);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBB) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBC) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x23);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x24);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBD) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBE) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x25);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x26);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBF) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC0) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x27);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x28);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC1) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC2) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x29);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2A);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC3) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC4) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2B);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2C);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC5) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC6) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2D);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC7) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC8) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2F);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x30);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC9) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCA) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x31);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x32);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCB) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCC) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x33);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x34);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCD) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCE) = temp_b2;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x35);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x36);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x37);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x38);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD3) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x39);
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3A);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3B);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD4) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD5) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3C);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3D);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD6) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD7) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3E);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3F);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD8) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD9) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x40);
    temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x41);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDA) = temp_b1;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDB) = temp_b2;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDC) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x42);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDD) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x43);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDE) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x44);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x45);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x46);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x47);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x48);
    M2C_FIELD(temp_r4_3, int *, 0xE3) = (int) M2C_FIELD(temp_r4_3, int *, 0x49);
    temp_r3 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r3, int *, 0x4D) = (int) M2C_FIELD(temp_r4_3, int *, 0x9A);
    M2C_FIELD(temp_r3, int *, 0x51) = (int) M2C_FIELD(temp_r4_3, int *, 0x9E);
    M2C_FIELD(temp_r3, unsigned char *, 0x55) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xA2);
    M2C_FIELD(temp_r3, float *, 0x56) = (float) M2C_FIELD(temp_r4_3, float *, 0xA3);
    M2C_FIELD(temp_r3, float *, 0x5A) = (float) M2C_FIELD(temp_r4_3, float *, 0xA7);
    M2C_FIELD(temp_r3, float *, 0x5E) = (float) M2C_FIELD(temp_r4_3, float *, 0xAB);
    M2C_FIELD(temp_r3, int *, 0x62) = (int) M2C_FIELD(temp_r4_3, int *, 0xAF);
    M2C_FIELD(temp_r3, float *, 0x66) = (float) M2C_FIELD(temp_r4_3, float *, 0xB3);
    M2C_FIELD(temp_r3, unsigned char *, 0x6A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB7);
    M2C_FIELD(temp_r3, unsigned char *, 0x6B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB8);
    M2C_FIELD(temp_r3, unsigned char *, 0x6C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB9);
    M2C_FIELD(temp_r3, unsigned char *, 0x6D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBA);
    M2C_FIELD(temp_r3, unsigned char *, 0x6E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBB);
    M2C_FIELD(temp_r3, unsigned char *, 0x6F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBC);
    M2C_FIELD(temp_r3, unsigned char *, 0x70) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBD);
    M2C_FIELD(temp_r3, unsigned char *, 0x71) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBE);
    M2C_FIELD(temp_r3, unsigned char *, 0x72) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBF);
    M2C_FIELD(temp_r3, unsigned char *, 0x73) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC0);
    M2C_FIELD(temp_r3, unsigned char *, 0x74) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC1);
    M2C_FIELD(temp_r3, unsigned char *, 0x75) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC2);
    M2C_FIELD(temp_r3, unsigned char *, 0x76) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC3);
    M2C_FIELD(temp_r3, unsigned char *, 0x77) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC4);
    M2C_FIELD(temp_r3, unsigned char *, 0x78) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC5);
    M2C_FIELD(temp_r3, unsigned char *, 0x79) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC6);
    M2C_FIELD(temp_r3, unsigned char *, 0x7A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC7);
    M2C_FIELD(temp_r3, unsigned char *, 0x7B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC8);
    M2C_FIELD(temp_r3, unsigned char *, 0x7C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC9);
    M2C_FIELD(temp_r3, unsigned char *, 0x7D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCA);
    M2C_FIELD(temp_r3, unsigned char *, 0x7E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCB);
    M2C_FIELD(temp_r3, unsigned char *, 0x7F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCC);
    M2C_FIELD(temp_r3, unsigned char *, 0x80) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCD);
    M2C_FIELD(temp_r3, unsigned char *, 0x81) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCE);
    M2C_FIELD(temp_r3, unsigned char *, 0x82) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCF);
    M2C_FIELD(temp_r3, unsigned char *, 0x83) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD0);
    M2C_FIELD(temp_r3, unsigned char *, 0x84) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD1);
    M2C_FIELD(temp_r3, unsigned char *, 0x85) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD2);
    M2C_FIELD(temp_r3, unsigned char *, 0x86) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD3);
    M2C_FIELD(temp_r3, unsigned char *, 0x87) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD4);
    M2C_FIELD(temp_r3, unsigned char *, 0x88) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD5);
    M2C_FIELD(temp_r3, unsigned char *, 0x89) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD6);
    M2C_FIELD(temp_r3, unsigned char *, 0x8A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD7);
    M2C_FIELD(temp_r3, unsigned char *, 0x8B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD8);
    M2C_FIELD(temp_r3, unsigned char *, 0x8C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD9);
    M2C_FIELD(temp_r3, unsigned char *, 0x8D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDA);
    M2C_FIELD(temp_r3, unsigned char *, 0x8E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDB);
    M2C_FIELD(temp_r3, unsigned char *, 0x8F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDC);
    M2C_FIELD(temp_r3, unsigned char *, 0x90) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDD);
    M2C_FIELD(temp_r3, unsigned char *, 0x91) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDE);
    M2C_FIELD(temp_r3, unsigned char *, 0x92) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDF);
    M2C_FIELD(temp_r3, unsigned char *, 0x93) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE0);
    M2C_FIELD(temp_r3, unsigned char *, 0x94) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE1);
    zero = lbl_80562430;
    data.prefix[0] = zero;
    M2C_FIELD(temp_r3, unsigned char *, 0x95) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE2);
    data.prefix[1] = zero;
    M2C_FIELD(temp_r3, int *, 0x96) = (int) M2C_FIELD(temp_r4_3, int *, 0xE3);
    temp_r4_4 = M2C_FIELD(arg0, void **, 0x2700);
    data.prefix[2] = zero;
    M2C_FIELD(temp_r4_4, int *, 0x51) = (int) (M2C_FIELD(temp_r4_4, int *, 0x51) - 1);
    temp_r4_5 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_5, int *, 0x9E) = (int) (M2C_FIELD(temp_r4_5, int *, 0x9E) - 2);
    M2C_FIELD(arg0, float *, 0x2720) = zero;
    M2C_FIELD(arg0, float *, 0x2724) = zero;
    M2C_FIELD(arg0, float *, 0x2728) = zero;
    M2C_FIELD(arg0, float *, 0x2714) = zero;
    M2C_FIELD(arg0, float *, 0x2718) = zero;
    M2C_FIELD(arg0, float *, 0x271C) = zero;
    M2C_FIELD(arg0, float *, 0x2708) = zero;
    M2C_FIELD(arg0, float *, 0x270C) = zero;
    M2C_FIELD(arg0, float *, 0x2710) = zero;
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
float fn_801A70EC(int arg0, void *arg1, void *arg2, int arg3) {
    float ratio;
    float denominator;
    denominator = fn_801A63C4(((int *)arg2)[1], ((int *)arg1)[1]);
    ratio = fn_801A63C4(arg3, ((int *)arg1)[1]);
    ratio /= denominator;
    fn_8012F57C(arg0, (char *)arg1 + 0x2A, (char *)arg2 + 0x2A, ratio);
    return ratio;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
extern double fn_8002F234(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_801A7178(void *arg0, float *arg1) {
    float a[4], b[4], q[4], rot[4];
    float *rotp;
    float (*m)[3];
    char *p = arg0;
    char *data;
    int time = lbl_8055E3C4;
    float trace, t, scale, blend, tick, step, thr;
    float m00, m11, m22, tmp;
    int k,j,i;
    float *mk,*mj,*mi;
    float x,y,z,w,xy,wz,xz,wy,yz,wx,zz,yy,xx,one,x2,y2,z2;
    float d0,d1,d2, a0,a1,a2,a3,a4,a5;
    data = *(char **)(p + 0x2700);
    fn_801A70EC((int)a, data+0x4d, data, time);
    data = *(char **)(p + 0x2700);
    fn_801A70EC((int)b, data+0x9a, data+0x4d, time);
    fn_8012F57C((int)q,b,a,*(float *)(p+0x2738));
    m = (float (*)[3])(p+0x3c);
    thr = lbl_80562430;
    m00 = *(volatile float *)&m[0][0];
    m11 = *(volatile float *)&m[1][1];
    tick = *(volatile float *)(p+0x2738);
    tmp = m00 + m11;
    m22 = *(volatile float *)&m[2][2];
    step = *(volatile float *)(p+0x273c);
    trace = m22 + tmp;
    blend = *arg1;
    *(float *)(p+0x2738) = tick+step;
    if (trace > thr) {
        t = (float)fn_8002F234(lbl_8056242C + trace);
        scale = lbl_80562418 / t;
        rot[3] = lbl_80562418 * t;
        rot[0] = scale * (m[1][2] - m[2][1]);
        rot[1] = scale * (m[2][0] - m[0][2]);
        rot[2] = scale * (m[0][1] - m[1][0]);
    } else {
        rotp=rot;
        i=0;
        if (*(volatile float *)&m[1][1] > *(volatile float *)&m[0][0]) i=1;
        if (m[2][2] > m[i][i]) i=2;
        j=(i+1)%3;
        k=(j+1)%3;
        mk=m[k]; mj=m[j]; mi=m[i];
        t=(float)fn_8002F234(lbl_8056242C + (mi[i] - (mj[j]+mk[k])));
        scale=lbl_80562418/t;
        rotp[i]=lbl_80562418*t;
        rotp[3]=scale*(mj[k]-mk[j]);
        rotp[j]=scale*(mi[j]+mj[i]);
        rotp[k]=scale*(mi[k]+mk[i]);
    }
    fn_8012F57C((int)q,rot,q,blend);
    x=q[0]; y=q[1]; z=q[2]; w=q[3];
    x2=x+x; y2=y+y; z2=z+z;
    xx=x*x2; yy=y*y2; zz=z*z2;
    one=lbl_8056242C;
    wx=w*x2; yz=y*z2;
    d0=one-(yy+zz); d1=one-(xx+zz); d2=one-(xx+yy);
    a0=yz-wx; a1=yz+wx;
    wy=w*y2; xz=x*z2; wz=w*z2;
    xy=x*y2;
    a2=xz+wy; a3=xz-wy; a4=xy-wz; a5=xy+wz;
    *(float *)(p+0x3c)=d0;
    *(float *)(p+0x4c)=d1;
    *(float *)(p+0x58)=a0;
    *(float *)(p+0x54)=a2;
    *(float *)(p+0x48)=a4;
    *(float *)(p+0x40)=a5;
    *(float *)(p+0x44)=a3;
    *(float *)(p+0x50)=a1;
    *(float *)(p+0x5c)=d2;
}
#pragma pop

extern float lbl_8056242C, lbl_80562430, lbl_80562448;
extern void fn_801A69F4(void *, float *);
extern void fn_801A6C14(void *);
extern void fn_801A7178(void *, float *);
extern void fn_801A7530(void *, void *);
extern void fn_801BE168(void *, void *, void *, void *);
extern float PSVECDotProduct(void *, void *);
/* Updates object/camera state: computes blend via fn_801A7530/fn_801A69F4/
   fn_801A7178, scales vector at +0x124 by (1-blend), resets direction at +0x118
   if its dot product exceeds threshold, applies transform, and clears a flag. */
void fn_801A7444(void *arg0) {
    float blend, one, up, side;
    char *obj = (char *)arg0;
    fn_801A7530(obj, &blend);
    fn_801A69F4(obj, &blend);
    fn_801A7178(obj, &blend);
    one = lbl_8056242C;
    *(float *)(obj + 0x124) *= one - blend;
    *(float *)(obj + 0x128) *= one - blend;
    *(float *)(obj + 0x12C) *= one - blend;
    if (PSVECDotProduct(obj + 0x118, obj + 0x118) > lbl_80562448) {
        side = lbl_80562430;
        up = lbl_8056242C;
        *(float *)(obj + 0x118) = side;
        *(float *)(obj + 0x11C) = up;
        *(float *)(obj + 0x120) = side;
    }
    fn_801BE168(*(void **)(obj + 0x1EC), obj + 0x3C, obj + 0x118, obj + 0x124);
    if (*(unsigned char *)(*(char **)(obj + 0x2700) + 0x48)) {
        fn_801A6C14(obj);
        *(unsigned char *)(*(char **)(obj + 0x2700) + 0x48) = 0;
    }
}

#pragma scheduling reset
void fn_801A7530(void *arg0, void *arg1) {
    typedef struct { int first; int second; } Pair;
    float zero;
    float *v;
    if (*(int *)((char *)arg0 + 0x2610) == 0 || *(unsigned char *)((char *)arg0 + 0x2741) != 0) {
        zero = lbl_8056242C;
        *(float *)((char *)arg1 + 4) = zero;
        *(float *)((char *)arg1 + 8) = zero;
        *(float *)((char *)arg1 + 0xC) = zero;
        *(float *)arg1 = zero;
    } else {
        v = fn_80265D98();
        *(float *)arg1 = *v;
        *(Pair *)((char *)arg1 + 4) = *(Pair *)((char *)v + 4);
        *(int *)((char *)arg1 + 0xC) = *(int *)((char *)v + 0xC);
    }
}

