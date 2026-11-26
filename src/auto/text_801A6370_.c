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
    virtual void d16(); virtual void d17(); virtual void d18();
    virtual void d21(float *);
};
#pragma cplusplus reset

extern float lbl_80562418;
extern float lbl_8056241C;
extern double lbl_80562420;
extern float lbl_80562428;
extern float *fn_80265D98(void);
extern void fn_8012F57C(int, void *, void *, float);
#pragma dont_inline on
/* Integrate one axis of constant-acceleration motion over dt:
   pos + vel*dt + 0.5*accel*dt^2 (lbl_80562418 is 0.5f). */
float fn_801A6370(float pos, float vel, float accel, float dt) {
    float half = lbl_80562418 * accel;
    vel *= dt;
    pos += vel;
    half *= dt;
    return pos + dt * half;
}
#pragma dont_inline reset

float fn_801A6390(int arg0, int arg1) {
    int delta = arg0 - arg1;
    return lbl_8056241C * (float)delta;
}

#pragma dont_inline on
#pragma scheduling invalid_target
float fn_801A63C4(int endTick, int startTick) {
    /* Elapsed time between two tick stamps: fn_801A6390 turns the gap into
       seconds on one time base, then this rescales onto the spline's time base. */
    return (lbl_80562428 * fn_801A6390(endTick, startTick)) / lbl_8056241C;
}
#pragma scheduling on
#pragma dont_inline off

/* Linearly interpolates three components from a to b by per-component factors in t (out = a + t*(b-a)). */
void fn_801A63F4(void *outVec, void *aVec, void *bVec, void *tVec) {
    float *out = (float *)outVec;
    float *a = (float *)aVec;
    float *b = (float *)bVec;
    float *t = (float *)tVec;
    float bZ;
    float bY;
    float aX;
    float bX;
    float aY;
    float tZ;
    float tY;
    float tX;
    float aZ;
    bZ = b[2];
    bY = b[1];
    bX = b[0];
    aX = a[0];
    aY = a[1];
    tZ = t[2];
    tY = t[1];
    tX = t[0];
    aZ = a[2];
    out[2] = aZ + tZ * (bZ - aZ);
    out[1] = aY + tY * (bY - aY);
    out[0] = aX + tX * (bX - aX);
}

/* One control point of the spline this object evaluates: fn_801A6484 default-
   constructs an array of four of them at +0x2708, and fn_801A69F4 reads the
   first (+0x2708) and last (+0x272C) as the ends of the segment in play. */
typedef struct {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
} SplinePoint;

#pragma dont_inline on
/* Default constructor for one SplinePoint: clears its three components and
   hands the point back, the way these constructors return their object. */
void *fn_801A644C(void *point) {
    memset(point, 0, sizeof(SplinePoint));
    return point;
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

/* No-op element callback: fn_801A6484 passes this as the initializer to
 * fn_8002F37C when creating the object's task array at +0x2700.  It leaves
 * each element untouched. */
void fn_801A6520(void) {
}

extern void fn_8018381C(void);
extern void fn_801A6558(void *);
extern void fn_801A67B0(void *);
extern void *KERNEL_GetTimeMs(void);
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
void fn_801A6524(void *object) {
    /* Initialize the object: run the shared transform/state setup path, then its type-specific field initialization. */
    fn_8018381C();
    fn_801A6558(object);
}

#pragma opt_propagation off
void fn_801A6558(void *arg0) {
    float zero;
    float one;
    void *tmp;
    *(int *)((char *)arg0 + 0x2778) = 4;
    tmp = KERNEL_GetTimeMs();
    zero = lbl_80562430;
    one = lbl_8056242C;
    *(void **)((char *)arg0 + 0x277C) = tmp;
    *(float *)((char *)arg0 + 0x273C) = one;
    *(float *)((char *)arg0 + 0x2738) = one;
    *(int *)((char *)arg0 + 0x2704) = 0;
    *(float *)((char *)arg0 + 0x272C) = zero;
    *(float *)((char *)arg0 + 0x2730) = zero;
    *(float *)((char *)arg0 + 0x2734) = zero;
    *(float *)((char *)arg0 + 0x2708) = zero;
    *(float *)((char *)arg0 + 0x270C) = zero;
    *(float *)((char *)arg0 + 0x2710) = zero;
    *(float *)((char *)arg0 + 0x2714) = zero;
    *(float *)((char *)arg0 + 0x2718) = zero;
    *(float *)((char *)arg0 + 0x271C) = zero;
    *(float *)((char *)arg0 + 0x2720) = zero;
    *(float *)((char *)arg0 + 0x2724) = zero;
    *(float *)((char *)arg0 + 0x2728) = zero;
    memset(*(void **)((char *)arg0 + 0x2700), 0, 0xE7);
    if (*(unsigned char *)((char *)arg0 + 0x2740))
        fn_801A67B0(arg0);
}
#pragma opt_propagation reset
extern void fn_80182074(void);
extern void *getDeitySlot(int);
extern void fn_80265D40(void *, int, float);
#pragma scheduling invalid_target
/* Reset the camera/vehicle state: initialize internals, bind the tracked object for slot 0x1EC, clear runtime flags, seed default scalar fields, then notify 80265D40 and mark state active (0x267C). */
void fn_801A65FC(void *obj) {
    float zeroValue;
    float oneValue;
    int objectSlot;
    fn_80182074();
    *(void **)((char *)obj + 0x2774) =
        getDeitySlot(*(int *)((char *)obj + 0x1EC));
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
#pragma scheduling reset
int fn_801A6724(void *arg0) {
    int flag = *(int *)((char *)arg0 + 0x2704);
    int ret;
    if (flag > 0) {
        float v = fn_801A6390(lbl_8055E3C4, *(int *)(*(char **)((char *)arg0 + 0x2700) + 4));
        ret = (v > lbl_80562434);
    } else {
        ret = 0;
        if (fn_801E89EC() == 1 && ((int)KERNEL_GetTimeMs() - *(int *)((char *)arg0 + 0x277C) > 0x7D0)) {
            ret = 1;
        }
    }
    return ret;
}
extern float lbl_80562438;
void fn_801A67B0(void *camera) {
    /* When a move starts attached, mark the followed move as running (0x2704 = 1)
       and seed the camera's up/side vector block (0x11C) with -1.0f. */
    float negativeOne = lbl_80562438;
    *(int *)((char *)camera + 0x2704) = 1;
    *(float *)((char *)camera + 0x11C) = negativeOne;
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
 *             frame and 0x277C the time (KERNEL_GetTimeMs, ms) it entered it
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
/* Per-frame update of a camera that follows a move record: restarts the state timer on state change, hands off the move when it still has time left, or finishes the move — copies the saved pose into the node, clears the up/side vectors, pushes the pose to the scene record — and, when the move just ended, hands the record's settings to the camera and its slot record and updates the camera. */ extern "C" void updateCameraMoveFollow(void *self) {
    char *camera = (char *)self;
    int gameState = *(int *)(camera + 0x2610);
    *(char *)(camera + 0x1e9) = 0;
    if (gameState != *(int *)(camera + 0x2778))
        *(void **)(camera + 0x277C) = KERNEL_GetTimeMs();
    if (fn_801A6724(self) == 0) {
        if (*(unsigned char *)(camera + 0x2740) != 0) {
            char *attachedObj = (*(Fn801A67C4Vt **)(camera + 0x2774))->d2();
            if (*(int *)(attachedObj + 0x24) == 0) {
                *(unsigned char *)(camera + 0x2740) = 0;
                *(char *)(camera + 0x2741) = 1;
            }
        }
    } else {
        float zeroFloat;
        *(int *)(camera + 0x2704) = 0;
        *(unsigned char *)(camera + 0x2740) = 1;
        *(int *)(camera + 0x3C) = *(int *)(camera + 0x2744);
        *(int *)(camera + 0x40) = *(int *)(camera + 0x2748);
        *(int *)(camera + 0x44) = *(int *)(camera + 0x274C);
        *(int *)(camera + 0x48) = *(int *)(camera + 0x2750);
        *(int *)(camera + 0x4C) = *(int *)(camera + 0x2754);
        *(int *)(camera + 0x50) = *(int *)(camera + 0x2758);
        *(int *)(camera + 0x54) = *(int *)(camera + 0x275C);
        *(int *)(camera + 0x58) = *(int *)(camera + 0x2760);
        *(int *)(camera + 0x5C) = *(int *)(camera + 0x2764);
        *(int *)(camera + 0x60) = *(int *)(camera + 0x2768);
        *(int *)(camera + 0x64) = *(int *)(camera + 0x276C);
        *(int *)(camera + 0x68) = *(int *)(camera + 0x2770);
        fn_8017A580(self);
        zeroFloat = lbl_80562430;
        *(float *)(camera + 0x118) = zeroFloat;
        *(float *)(camera + 0x11C) = zeroFloat;
        *(float *)(camera + 0x120) = zeroFloat;
        *(float *)(camera + 0x124) = zeroFloat;
        *(float *)(camera + 0x128) = zeroFloat;
        *(float *)(camera + 0x12C) = zeroFloat;
        fn_8018ADBC(self, zeroFloat);
        fn_8018ADB4(self, lbl_80562430);
        fn_8018ADC4(self, lbl_80562430);
        (*(Fn801A67C4Vt **)(camera + 0x2774))->d7();
        fn_801BE168(*(void **)(camera + 0x1EC), camera + 0x3C, camera + 0x118, camera + 0x124);
    }
    if (*(unsigned char *)(camera + 0x2740) == 0 && *(int *)(camera + 0x2704) == 3) {
        fn_8018ADA4(self, *(float *)(*(char **)(camera + 0x2700) + 0xD));
        fn_8018ADCC(self, lbl_80562430);
        if (*(int *)(*(char **)(camera + 0x2700) + 0x15) != -1)
            fn_8018ADD4(self, *(int *)(*(char **)(camera + 0x2700) + 0x15));
        fn_8018ADC4(self, lbl_80562430);
        fn_8018ADBC(self, *(float *)(*(char **)(camera + 0x2700) + 0x9));
        fn_8018ADB4(self, *(float *)(*(char **)(camera + 0x2700) + 0x11));
        fn_80136EA4(lbl_8055E0D0, *(int *)(camera + 0x1EC));
        if ((gameState != 2 || *(int *)(camera + 0x2778) != 0) && gameState != 0)
            fn_801A7444(self);
        *(char *)(camera + 0x2741) = 0;
    }
    *(int *)(camera + 0x2778) = gameState;
}
#pragma cplusplus reset
extern int lbl_8055E3C4;
extern double lbl_80562440;
#pragma push
#pragma processor 750
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" void fn_8017A580(void *);
extern "C" void fn_801A69F4(void *arg0, float *arg1)
{
#pragma opt_propagation off
  char *p = (char *) arg0;
  int k = lbl_8055E3C4;
  float t[3], out0[3], outA[3], outB[3];
  float a0;
  double a, b, c, d, x, z;
  double ab, ak, dk, y, da, xden, xnum, ka, kb, ynum, znum, yden;
  a0 = fn_801A63C4(k, *((int *) ((*((char **) (p + 0x2700))) + 4)));
  t[0] = fn_801A6370(*((float *) ((*((char **) (p + 0x2700))) + 0x1e)), *((float *) (p + 0x2708)), *((float *) (p + 0x272c)), a0);
  t[1] = fn_801A6370(*((float *) ((*((char **) (p + 0x2700))) + 0x22)), *((float *) (p + 0x270c)), *((float *) (p + 0x2730)), a0);
  t[2] = fn_801A6370(*((float *) ((*((char **) (p + 0x2700))) + 0x26)), *((float *) (p + 0x2710)), *((float *) (p + 0x2734)), a0);
  a = fn_801A63C4(*((int *) ((*((char **) (p + 0x2700))) + 0x51)), *((int *) ((*((char **) (p + 0x2700))) + 0x9e)));
  b = fn_801A63C4(*((int *) ((*((char **) (p + 0x2700))) + 4)), *((int *) ((*((char **) (p + 0x2700))) + 0x9e)));
  c = fn_801A63C4(k, *((int *) ((*((char **) (p + 0x2700))) + 0x9e)));
  d = c + c;
  ab = a - b;
  ak = a - lbl_80562440;
  dk = d - lbl_80562440;
  da = d - a;
  xden = ak * ab;
  xnum = dk - b;
  ka = lbl_80562440 - a;
  kb = lbl_80562440 - b;
  ynum = da - b;
  znum = dk - a;
  yden = ka * kb;
  x = xnum / xden;
  y = ynum / yden;
  z = znum / ((b - lbl_80562440) * (b - a));
  {
    char *data = *((char **) (p + 0x2700));
    out0[0] = (((*((float *) (data + 0x6b))) * x) + ((*((float *) (data + 0xb8))) * y)) + ((*((float *) (data + 0x1e))) * z);
    data = *((char **) (p + 0x2700));
    out0[1] = (((*((float *) (data + 0x6f))) * x) + ((*((float *) (data + 0xbc))) * y)) + ((*((float *) (data + 0x22))) * z);
    data = *((char **) (p + 0x2700));
    out0[2] = (((*((float *) (data + 0x73))) * x) + ((*((float *) (data + 0xc0))) * y)) + ((*((float *) (data + 0x26))) * z);
  }
  fn_801A63F4(outA, p + 0x60, t, arg1 + 1);
  *((float *) (p + 0x60)) = outA[0];
  *((float *) (p + 0x64)) = outA[1];
  *((float *) (p + 0x68)) = outA[2];
  fn_8017A580(arg0);
  fn_801A63F4(outB, p + 0x118, out0, arg1 + 1);
  *((float *) (p + 0x118)) = outB[0];
  *((float *) (p + 0x11c)) = outB[1];
  *((float *) (p + 0x120)) = outB[2];
}
#pragma ppc_psq_save reset
#pragma cplusplus reset
#pragma pop
extern void fn_801E9DC4(void *);
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_801A6C14(void *arg0) {
    struct { float prefix[3]; float matrix[9]; float vec[3]; float zero[3]; int count; short tag; } data;
    float *matrix; unsigned char temp_b2, temp_b1; float one, zero;
    float temp_f10, temp_f10_2, temp_f11, temp_f12, temp_f1, temp_f1_2, temp_f1_3;
    float temp_f2, temp_f2_2, temp_f3, temp_f3_2, temp_f4, temp_f4_2, temp_f5, temp_f5_2;
    float temp_f6, temp_f6_2, temp_f7, temp_f7_2, temp_f8, temp_f9, temp_f9_2;
    void *temp_r3, *temp_r4, *temp_r4_2, *temp_r4_3, *temp_r4_4, *temp_r4_5;
    one = 1.0f; zero = 0.0f; matrix = data.matrix; data.tag = -1;
    temp_r4 = M2C_FIELD(arg0, void **, 0x2700);
    temp_f8 = M2C_FIELD(temp_r4, float *, 0x2A); temp_f2 = M2C_FIELD(temp_r4, float *, 0x2E);
    temp_f1 = M2C_FIELD(temp_r4, float *, 0x32); temp_f3 = temp_f8 + temp_f8;
    temp_f12 = temp_f2 + temp_f2; temp_f7 = M2C_FIELD(temp_r4, float *, 0x36);
    temp_f11 = temp_f1 + temp_f1; temp_f5 = temp_f8 * temp_f3; temp_f4 = temp_f2 * temp_f12;
    temp_f1_2 = temp_f1 * temp_f11; temp_f10 = temp_f7 * temp_f3; temp_f9 = temp_f2 * temp_f11;
    data.matrix[0] = one - (temp_f4 + temp_f1_2); temp_f2_2 = temp_f9 + temp_f10;
    temp_f10_2 = temp_f7 * temp_f12; temp_f6 = temp_f8 * temp_f11; temp_f9_2 = temp_f7 * temp_f11;
    data.matrix[4] = one - (temp_f5 + temp_f1_2); temp_f7_2 = temp_f8 * temp_f12;
    temp_f5_2 = temp_f6 + temp_f10_2; temp_f3_2 = temp_f6 - temp_f10_2;
    temp_f6_2 = temp_f7_2 - temp_f9_2; data.matrix[7] = temp_f9 - temp_f10;
    temp_f4_2 = temp_f7_2 + temp_f9_2; data.matrix[6] = temp_f5_2; data.matrix[3] = temp_f6_2;
    data.matrix[1] = temp_f4_2; data.matrix[2] = temp_f3_2; data.matrix[5] = temp_f2_2;
    data.matrix[8] = one - (temp_f5 + temp_f4);
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x2700);
    data.vec[0] = M2C_FIELD(temp_r4_2, float *, 0x1E); data.vec[1] = M2C_FIELD(temp_r4_2, float *, 0x22);
    temp_f1_3 = M2C_FIELD(temp_r4_2, float *, 0x26); data.vec[2] = temp_f1_3;
    data.zero[0] = zero; data.zero[1] = zero; data.zero[2] = zero; data.count = 0;
    fn_801E9DC4(&data.tag); ((Fn801A6C14Dispatch *)arg0)->d21(matrix);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_3, int *, 0x9A) = (int) M2C_FIELD(temp_r4_3, int *, 0);
    M2C_FIELD(temp_r4_3, int *, 0x9E) = (int) M2C_FIELD(temp_r4_3, int *, 4);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xA2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 8);
    M2C_FIELD(temp_r4_3, float *, 0xA3) = (float) M2C_FIELD(temp_r4_3, float *, 9);
    M2C_FIELD(temp_r4_3, float *, 0xA7) = (float) M2C_FIELD(temp_r4_3, float *, 0xD);
    M2C_FIELD(temp_r4_3, float *, 0xAB) = (float) M2C_FIELD(temp_r4_3, float *, 0x11);
    M2C_FIELD(temp_r4_3, int *, 0xAF) = (int) M2C_FIELD(temp_r4_3, int *, 0x15);
    M2C_FIELD(temp_r4_3, float *, 0xB3) = (float) M2C_FIELD(temp_r4_3, float *, 0x19);
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1D); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB7) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xB8) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x1F); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x20);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB9) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xBA) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x21); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x22);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBB) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xBC) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x23); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x24);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBD) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xBE) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x25); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x26);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBF) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xC0) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x27); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x28);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC1) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xC2) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x29); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2A);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC3) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xC4) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2B); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2C);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC5) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xC6) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2D); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC7) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xC8) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x2F); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x30);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC9) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xCA) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x31); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x32);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCB) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xCC) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x33); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x34);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCD) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xCE) = temp_b2;
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x35);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x36);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x37);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x38);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD3) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x39);
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3A); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3B);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD4) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xD5) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3C); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3D);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD6) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xD7) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3E); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x3F);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD8) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xD9) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0x40); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0x41);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDA) = temp_b1; M2C_FIELD(temp_r4_3, unsigned char *, 0xDB) = temp_b2;
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
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xB7); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xB8);
    M2C_FIELD(temp_r3, unsigned char *, 0x6A) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x6B) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xB9); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBA);
    M2C_FIELD(temp_r3, unsigned char *, 0x6C) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x6D) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBB); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBC);
    M2C_FIELD(temp_r3, unsigned char *, 0x6E) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x6F) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBD); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBE);
    M2C_FIELD(temp_r3, unsigned char *, 0x70) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x71) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xBF); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC0);
    M2C_FIELD(temp_r3, unsigned char *, 0x72) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x73) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC1); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC2);
    M2C_FIELD(temp_r3, unsigned char *, 0x74) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x75) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC3); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC4);
    M2C_FIELD(temp_r3, unsigned char *, 0x76) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x77) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC5); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC6);
    M2C_FIELD(temp_r3, unsigned char *, 0x78) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x79) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC7); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC8);
    M2C_FIELD(temp_r3, unsigned char *, 0x7A) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x7B) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xC9); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xCA);
    M2C_FIELD(temp_r3, unsigned char *, 0x7C) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x7D) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xCB); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xCC);
    M2C_FIELD(temp_r3, unsigned char *, 0x7E) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x7F) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xCD); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xCE);
    M2C_FIELD(temp_r3, unsigned char *, 0x80) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x81) = temp_b2;
    M2C_FIELD(temp_r3, unsigned char *, 0x82) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCF);
    M2C_FIELD(temp_r3, unsigned char *, 0x83) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD0);
    M2C_FIELD(temp_r3, unsigned char *, 0x84) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD1);
    M2C_FIELD(temp_r3, unsigned char *, 0x85) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD2);
    M2C_FIELD(temp_r3, unsigned char *, 0x86) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD3);
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD4); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD5);
    M2C_FIELD(temp_r3, unsigned char *, 0x87) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x88) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD6); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD7);
    M2C_FIELD(temp_r3, unsigned char *, 0x89) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x8A) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD8); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xD9);
    M2C_FIELD(temp_r3, unsigned char *, 0x8B) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x8C) = temp_b2;
    temp_b1 = M2C_FIELD(temp_r4_3, unsigned char *, 0xDA); temp_b2 = M2C_FIELD(temp_r4_3, unsigned char *, 0xDB);
    M2C_FIELD(temp_r3, unsigned char *, 0x8D) = temp_b1; M2C_FIELD(temp_r3, unsigned char *, 0x8E) = temp_b2;
    M2C_FIELD(temp_r3, unsigned char *, 0x8F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDC);
    M2C_FIELD(temp_r3, unsigned char *, 0x90) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDD);
    M2C_FIELD(temp_r3, unsigned char *, 0x91) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDE);
    M2C_FIELD(temp_r3, unsigned char *, 0x92) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDF);
    M2C_FIELD(temp_r3, unsigned char *, 0x93) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE0);
    M2C_FIELD(temp_r3, unsigned char *, 0x94) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE1);
    data.prefix[0] = zero;
    M2C_FIELD(temp_r3, unsigned char *, 0x95) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE2);
    data.prefix[1] = zero;
    M2C_FIELD(temp_r3, int *, 0x96) = (int) M2C_FIELD(temp_r4_3, int *, 0xE3);
    temp_r4_4 = M2C_FIELD(arg0, void **, 0x2700);
    data.prefix[2] = zero;
    M2C_FIELD(temp_r4_4, int *, 0x51) = (int) (M2C_FIELD(temp_r4_4, int *, 0x51) - 1);
    temp_r4_5 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_5, int *, 0x9E) = (int) (M2C_FIELD(temp_r4_5, int *, 0x9E) - 2);
    M2C_FIELD(arg0, float *, 0x2720) = zero; M2C_FIELD(arg0, float *, 0x2724) = zero;
    M2C_FIELD(arg0, float *, 0x2728) = zero; M2C_FIELD(arg0, float *, 0x2714) = zero;
    M2C_FIELD(arg0, float *, 0x2718) = zero; M2C_FIELD(arg0, float *, 0x271C) = zero;
    M2C_FIELD(arg0, float *, 0x2708) = zero; M2C_FIELD(arg0, float *, 0x270C) = zero;
    M2C_FIELD(arg0, float *, 0x2710) = zero;
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Spherical interpolation of a move's rotation quaternion at the current time.
 * fromKey/toKey are animation keyframe records: +4 is the tick stamp and +0x2A
 * the four-float quaternion. fn_801A63C4 converts tick gaps to time, so the
 * ratio here is (elapsed from the earlier key) / (span between the two keys);
 * that 0..1 factor feeds fn_8012F57C's quaternion slerp into outQuat. */
float fn_801A70EC(int outQuat, const void *fromKey, void *toKey, int nowTick) {
    float blend;
    float span;
    span = fn_801A63C4(*(int *)((char *)toKey + 4), *(const int *)((const char *)fromKey + 4));
    blend = fn_801A63C4(nowTick, *(const int *)((const char *)fromKey + 4));
    blend /= span;
    fn_8012F57C(outQuat, (char *)fromKey + 0x2A, (char *)toKey + 0x2A, blend);
    return blend;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
extern double fn_8002F234(double);
#pragma scheduling invalid_target
void fn_801A7178(void *arg0, float *arg1) {
    int time = lbl_8055E3C4;
    float a[4], b[4], q[4], rot[4];
    float *rotp;
    float (*m)[3];
    char *p = arg0;
    char *data;
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
/* Blend parameters of the camera's move-following update.
 *
 * The camera (the object fn_801A6484 builds) is updated with four blend
 * parameters that fn_801A7444 reads back from here, the first of them the
 * factor between the camera's own pose and the pose the move record hands
 * back.  When the camera has no move to follow - the game state at 0x2610 is
 * 0, or the move has just ended (the flag at 0x2741) - it is blended all the
 * way over, so all four come out 1.0; otherwise they are the four floats
 * getMoveBlendParams() points at (a stub returning null in this build). */
void fn_801A7530(void *camera, void *blendParams) {
    /* Two words moved as one aggregate: that is what makes the compiler pair
     * the loads and stores below as the original does
     * (lwz r4,4 / lwz r0,8 / stw r4,4 / stw r0,8). */
    typedef struct { int first; int second; } WordPair;
    /* Names for the symbols this file declares by their original labels. */
#define one_f              lbl_8056242C /* 1.0f */
#define getMoveBlendParams fn_80265D98
    float one;
    float *src;

    if (*(int *)((char *)camera + 0x2610) == 0 ||
        *(unsigned char *)((char *)camera + 0x2741) != 0) {
        one = one_f;
        *(float *)((char *)blendParams + 4) = one;
        *(float *)((char *)blendParams + 8) = one;
        *(float *)((char *)blendParams + 0xC) = one;
        *(float *)blendParams = one;
    } else {
        src = getMoveBlendParams();
        *(float *)blendParams = *src;
        *(WordPair *)((char *)blendParams + 4) = *(WordPair *)((char *)src + 4);
        *(int *)((char *)blendParams + 0xC) = *(int *)((char *)src + 0xC);
    }
#undef one_f
#undef getMoveBlendParams
}
