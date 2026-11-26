// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float x, y, z; } Vec;
extern void fn_80272354(void);
extern void __array_delete(void *, void *, int, int);
extern void fn_80015B20(void *, void *, void *);
extern void fn_801BFD34(void *, void *, void *);
extern float PSVECMag(float *);
extern double sin(double);
extern double cos(double);
extern float lbl_80564024, lbl_80564020, lbl_80563FAC, lbl_80563FA8;
extern const float lbl_80563FB0;
extern float lbl_80564010, lbl_80564014, lbl_80564018, lbl_8056401C;
extern double lbl_80563FB8;
extern float lbl_80563FC0, lbl_80563FC4, lbl_80563FC8, lbl_80563FCC, lbl_80563FD0, lbl_80563FD4, lbl_80563FD8, lbl_80563FDC, lbl_80563FE0;
extern float lbl_8055F578;
extern unsigned char lbl_8055F57C;
extern int fn_801EA098(void *, void *, float *, int *, float, float);
extern float PSVECDotProduct(float *, float *);
extern double fn_8018AE3C(void *), fn_8018AE44(void *), fn_8018AE4C(void *);
extern void fn_80015A20(void *, float *, float, float);
extern void PSVECCrossProduct(void *, void *, void *);
extern void PSVECNormalize(void *, void *);
extern float lbl_802FA788[];
/* Callback table for the 32-record pool: fn_80273978 (delete), fn_80272C74, fn_80272738. */
extern char lbl_80347364[];
extern char lbl_8049A2C8[];
extern char lbl_8049F9D8[];
extern int fn_80273B08(int, int);
extern void fn_80273978(void);

/* Camera-like object built by fn_80275938 and driven by fn_80275B00:
 * +0x58 holds the 3x3 view matrix (three basis Vecs, built with PSVECCrossProduct /
 * PSVECNormalize), +0x88 the eye offset from the target, +0xC0 the field of view in
 * degrees (fn_80275B00 turns it into radians with lbl_80563FC0), +0x1B8/+0x1BC the
 * orbit distance and azimuth the eye offset is rebuilt from, and +0x35C/+0x360 a
 * saved field of view and view matrix that fn_80275FC0 copies back over the live ones. */
typedef struct CamState {
    /* 0x00 */ char pad000[0x58];
    /* 0x58 */ float viewMatrix[12];
    /* 0x88 */ char pad088[0x38];
    /* 0xC0 */ float fov;
    /* 0xC4 */ char pad0C4[0x298];
    /* 0x35C */ float savedFov;
    /* 0x360 */ float savedMatrix[12];
} CamState;

/* One 0x1C-byte record in the 32-element pool that fn_802739B8 allocates at
 * base+0x5780: +0x00 is a cleared state word, +0x18 points at the callback
 * table lbl_80347364. */
typedef struct {
    /* 0x00 */ int state;
    /* 0x04 */ char pad04[0x14];
    /* 0x18 */ char *callbacks;
} PoolRecord;

#pragma scheduling invalid_target
void fn_80273A88(void) {
    /* Tear down the array at lbl_8049F9D8: 32 records of 0x1C bytes each, run through the per-element deleting destructor fn_80273978 (MSL runtime array_delete). */
    __array_delete(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}
#pragma scheduling on
void fn_80273AA4(PoolRecord *record) {
    /* Per-element constructor: install the callback table and clear the state word. */
    record->callbacks = lbl_80347364;
    record->state = 0;
}
#pragma scheduling on
int fn_80273ABC(int object) {
    /* Pool constructor callback: initialize the object in place via fn_80272354, then return it. */
    fn_80272354();
    return object;
}

void fn_80273AEC(void) {
    /* Tear down the array at lbl_8049A2C8: 200 records of 0x60 bytes each, run through the per-element deleting destructor fn_80273B08 (MSL runtime array_delete). */
    __array_delete(lbl_8049A2C8, fn_80273B08, 0x60, 0xC8);
}

int fn_80273B08(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        extern int fn_80128668(void);
        fn_80128668();
    }
    return object;
}

/* Empty per-element constructor callback for the 200-record, 0x60-byte pool at
   lbl_8049A258+0x70, registered through fn_8002F53C by fn_802739B8; the records
   need no initialization, so this does nothing. */
void fn_80273B48(void) {
}

#pragma scheduling invalid_target
/* Applies a conditional Y-axis rotation to this object's local transform when it has a linked object. */
#pragma dont_inline on
void fn_80273B4C(void *arg0) {
    extern void fn_80015A20(void *, float *, float, float);
    extern void fn_80015B20(void *, void *, void *);
    extern float lbl_80563FA8, lbl_80563FAC, lbl_80563FB4;
    void *linkedObj = *(void **)((char *)arg0 + 0x140);
    char rotationMatrix[0x24];
    float angles[3];
    float yAngle;
    float scaledZero;
    void *transform;

    if (linkedObj != 0) {
        if (*(unsigned char *)((char *)linkedObj + 0x260C) != 0) yAngle = lbl_80563FA8;
        else yAngle = lbl_80563FAC;
        angles[0] = lbl_80563FB0;
        scaledZero = lbl_80563FB0 * lbl_80563FB4;
        angles[1] = scaledZero * yAngle;
        angles[2] = lbl_80563FB0;
        fn_80015A20(rotationMatrix, angles, yAngle, lbl_80563FB0);
        transform = (char *)arg0 + 0x58;
        fn_80015B20(transform, rotationMatrix, transform);
    }
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
void fn_80273BD0(void *arg0) {
#pragma opt_common_subs off
    struct { int sp8; float spC[3]; float sp18[3]; float sp24[3]; float sp30[3]; float sp3C[3]; float sp48[3]; float sp54[3]; float sp60[3]; float sp6C[3]; float sp78[9]; float sp9C[9]; } local;
    struct Words12 { unsigned int w[12]; };
    char *cam;
    float *r4;
    float f, g, h, var_f5, var_f3, temp_f0_3;
    double d30, d31, d1;
    if (*(unsigned char *)((char *)arg0 + 0x138) != 0) {
        float zero = lbl_80563FAC;
        float one = lbl_80563FB0;
        *(float *)((char *)arg0 + 0x28) = one;
        *(float *)((char *)arg0 + 0x2C) = zero;
        *(float *)((char *)arg0 + 0x30) = one;
        *(float *)((char *)arg0 + 0x34) = one;
        *(float *)((char *)arg0 + 0x38) = one;
        *(float *)((char *)arg0 + 0x3C) = one;
    }
    *(struct Words12 *)((char *)arg0 + 0x58) = *(struct Words12 *)((char *)arg0 + 0xC0);
    cam = *(char **)((char *)arg0 + 0x140);
    if (*(unsigned char *)(cam + 0x260C) != 0) r4 = (float *)(cam + 0x5D0);
    else r4 = (float *)(cam + 0x5C4);
    if (&local.sp30[0] == r4) {
        float t6 = r4[1], t0 = r4[0], t7 = r4[2];
        local.sp30[0] = t7 * *(float *)((char *)arg0 + 0x70) + (t0 * *(float *)((char *)arg0 + 0x58) + t6 * *(float *)((char *)arg0 + 0x64));
        local.sp30[1] = t7 * *(float *)((char *)arg0 + 0x74) + (t0 * *(float *)((char *)arg0 + 0x5C) + t6 * *(float *)((char *)arg0 + 0x68));
        local.sp30[2] = t7 * *(float *)((char *)arg0 + 0x78) + (t0 * *(float *)((char *)arg0 + 0x60) + t6 * *(float *)((char *)arg0 + 0x6C));
    } else {
        local.sp30[0] = r4[2] * *(float *)((char *)arg0 + 0x70) + (r4[0] * *(float *)((char *)arg0 + 0x58) + r4[1] * *(float *)((char *)arg0 + 0x64));
        local.sp30[1] = r4[2] * *(float *)((char *)arg0 + 0x74) + (r4[0] * *(float *)((char *)arg0 + 0x5C) + r4[1] * *(float *)((char *)arg0 + 0x68));
        local.sp30[2] = r4[2] * *(float *)((char *)arg0 + 0x78) + (r4[0] * *(float *)((char *)arg0 + 0x60) + r4[1] * *(float *)((char *)arg0 + 0x6C));
    }
    *(float *)((char *)arg0 + 0x7C) = *(float *)((char *)arg0 + 0x7C) + local.sp30[0];
    *(float *)((char *)arg0 + 0x80) = *(float *)((char *)arg0 + 0x80) + local.sp30[1];
    *(float *)((char *)arg0 + 0x84) = *(float *)((char *)arg0 + 0x84) + local.sp30[2];
    local.sp8 = 0;
    if ((signed char)lbl_8055F57C == 0) {
        f = (float)cos(lbl_80563FB8);
        lbl_8055F57C = 1;
        lbl_8055F578 = f;
    }
    if (fn_801EA098(*(char **)((char *)arg0 + 0x140) + 0x6C, local.sp60, local.sp6C, &local.sp8, *(float *)((char *)arg0 + 0xE4), *(float *)((char *)arg0 + 0xEC)) == 0) {
        local.sp6C[0] = *(float *)((char *)arg0 + 0xCC);
        local.sp6C[1] = *(float *)((char *)arg0 + 0xD0);
        local.sp6C[2] = *(float *)((char *)arg0 + 0xD4);
    } else {
        temp_f0_3 = (PSVECDotProduct(local.sp6C, (float *)((unsigned int)arg0 + 0xCC)) - lbl_8055F578) / (lbl_80563FAC - lbl_8055F578);
        var_f5 = lbl_80563FB0;
        var_f5 = (var_f5 > temp_f0_3) ? var_f5 : temp_f0_3;
        f = local.sp6C[0] * var_f5;
        g = local.sp6C[1] * var_f5;
        h = local.sp6C[2] * var_f5;
        local.sp6C[0] = f;
        local.sp6C[1] = g;
        local.sp6C[2] = h;
        var_f3 = lbl_80563FAC - var_f5;
        local.sp6C[0] = f + *(float *)((char *)arg0 + 0xCC) * var_f3;
        local.sp6C[1] = g + *(float *)((char *)arg0 + 0xD0) * var_f3;
        local.sp6C[2] = h + *(float *)((char *)arg0 + 0xD4) * var_f3;
    }
    if (*(unsigned char *)((char *)arg0 + 0x138) != 0) var_f3 = lbl_80563FB0;
    else var_f3 = lbl_80563FC0;
    {
        float a = *(float *)((char *)arg0 + 0x28) * var_f3;
        float b = *(float *)((char *)arg0 + 0x2C) * var_f3;
        float c = *(float *)((char *)arg0 + 0x30) * var_f3;
        float k = lbl_80563FAC - var_f3;
        *(float *)((char *)arg0 + 0x28) = a;
        *(float *)((char *)arg0 + 0x2C) = b;
        *(float *)((char *)arg0 + 0x30) = c;
        a = a + local.sp6C[0] * k;
        *(float *)((char *)arg0 + 0x28) = a;
        b = b + local.sp6C[1] * k;
        *(float *)((char *)arg0 + 0x2C) = b;
        *(float *)((char *)arg0 + 0x64) = a * lbl_80563FC4 + *(float *)((char *)arg0 + 0xCC) * lbl_80563FC4;
        *(float *)((char *)arg0 + 0x68) = b * lbl_80563FC4 + *(float *)((char *)arg0 + 0xD0) * lbl_80563FC4;
        c = c + local.sp6C[2] * k;
        *(float *)((char *)arg0 + 0x30) = c;
        *(float *)((char *)arg0 + 0x6C) = c * lbl_80563FC4 + *(float *)((char *)arg0 + 0xD4) * lbl_80563FC4;
    }
    PSVECCrossProduct((char *)((char *)arg0 + 0x64), (char *)((char *)arg0 + 0x70), (char *)((char *)arg0 + 0x58));
    PSVECCrossProduct((void *)((unsigned int)arg0 + 0x58), (void *)((unsigned int)arg0 + 0x64), (void *)((unsigned int)arg0 + 0x70));
    local.spC[0] = *(float *)((char *)arg0 + 0x58);
    local.spC[1] = *(float *)((char *)arg0 + 0x5C);
    local.spC[2] = *(float *)((char *)arg0 + 0x60);
    local.sp24[0] = *(float *)((char *)arg0 + 0x70);
    local.sp24[1] = *(float *)((char *)arg0 + 0x74);
    local.sp24[2] = *(float *)((char *)arg0 + 0x78);
    PSVECCrossProduct(local.sp24, local.spC, local.sp18);
    PSVECNormalize(local.spC, local.spC);
    PSVECNormalize(local.sp18, local.sp18);
    PSVECCrossProduct(local.spC, local.sp18, local.sp24);
    *(float *)((char *)arg0 + 0x58) = local.spC[0];
    *(float *)((char *)arg0 + 0x5C) = local.spC[1];
    *(float *)((char *)arg0 + 0x60) = local.spC[2];
    *(float *)((char *)arg0 + 0x64) = local.sp18[0];
    *(float *)((char *)arg0 + 0x68) = local.sp18[1];
    *(float *)((char *)arg0 + 0x6C) = local.sp18[2];
    *(float *)((char *)arg0 + 0x70) = local.sp24[0];
    *(float *)((char *)arg0 + 0x74) = local.sp24[1];
    *(float *)((char *)arg0 + 0x78) = local.sp24[2];
    if (*(unsigned char *)((char *)arg0 + 0x138) == 0) {
        float s = lbl_80563FC8;
        float x = *(float *)((char *)arg0 + 0x34) * s;
        float y = *(float *)((char *)arg0 + 0x38) * s;
        float z = *(float *)((char *)arg0 + 0x3C) * s;
        *(float *)((char *)arg0 + 0x34) = x;
        *(float *)((char *)arg0 + 0x38) = y;
        *(float *)((char *)arg0 + 0x3C) = z;
        d30 = fn_8018AE4C(*(void **)((char *)arg0 + 0x140));
        d31 = fn_8018AE44(*(void **)((char *)arg0 + 0x140));
        d1 = fn_8018AE3C(*(void **)((char *)arg0 + 0x140));
        {
            float k = lbl_80563FCC;
            float f3 = (float)d1 * k;
            float f4 = (float)d31 * k;
            float f2 = (float)d30 * k;
            local.sp54[0] = (float)d1;
            local.sp54[1] = (float)d31;
            local.sp54[2] = (float)d30;
            *(float *)((char *)arg0 + 0x34) = *(float *)((char *)arg0 + 0x34) + f3;
            *(float *)((char *)arg0 + 0x38) = *(float *)((char *)arg0 + 0x38) + f4;
            *(float *)((char *)arg0 + 0x3C) = *(float *)((char *)arg0 + 0x3C) + f2;
        }
        {
            float f6 = lbl_80563FD0 * (lbl_80563FD4 * (float)fn_8018AE4C(*(void **)((char *)arg0 + 0x140)));
            *(float *)((char *)arg0 + 0x7C) = *(float *)((char *)arg0 + 0x7C) + *(float *)((char *)arg0 + 0xD8) * f6;
            *(float *)((char *)arg0 + 0x80) = *(float *)((char *)arg0 + 0x80) + *(float *)((char *)arg0 + 0xDC) * f6;
            *(float *)((char *)arg0 + 0x84) = *(float *)((char *)arg0 + 0x84) + *(float *)((char *)arg0 + 0xE0) * f6;
        }
        {
            float f8 = lbl_80563FD4 * ((float)fn_8018AE44(*(void **)((char *)arg0 + 0x140)) - lbl_80563FDC * *(float *)((char *)arg0 + 0x38));
            float f7 = lbl_80563FD8 * (lbl_80563FD0 * f8);
            *(float *)((char *)arg0 + 0x7C) = *(float *)((char *)arg0 + 0x7C) + *(float *)((char *)arg0 + 0xCC) * f7;
            *(float *)((char *)arg0 + 0x80) = *(float *)((char *)arg0 + 0x80) + *(float *)((char *)arg0 + 0xD0) * f7;
            *(float *)((char *)arg0 + 0x84) = *(float *)((char *)arg0 + 0x84) + *(float *)((char *)arg0 + 0xD4) * f7;
        }
    }
    fn_80273B4C(arg0);
    local.sp48[0] = *(float *)(*(char **)((char *)arg0 + 0x140) + 0x5C0);
    local.sp48[1] = lbl_80563FB0;
    local.sp48[2] = lbl_80563FB0;
    fn_80015A20(local.sp9C, local.sp48, local.sp48[0], lbl_80563FB0);
    fn_80015B20((char *)arg0 + 0x58, local.sp9C, (char *)arg0 + 0x58);
    if (*(unsigned char *)(*(char **)((char *)arg0 + 0x140) + 0x260C) != 0) {
        local.sp3C[0] = lbl_80563FB0;
        local.sp3C[1] = lbl_80563FE0;
        local.sp3C[2] = lbl_80563FB0;
        fn_80015A20(local.sp78, local.sp3C, lbl_80563FB0, lbl_80563FB0);
        fn_80015B20((char *)arg0 + 0x58, local.sp78, (char *)arg0 + 0x58);
    }
}
#pragma pop

#pragma dont_inline fn_80273B4C
void fn_80274268(void *cam) {
    extern void applyFlippedTransform(void *);
    extern void fn_80273B4C(void *);
    extern const float lbl_80563FE8, lbl_80563FE4, lbl_80563FEC;
    struct MtxWords { unsigned int word[12]; };
    struct TransformObj {
        unsigned char pad0[0x58];
        struct MtxWords mtx;
        unsigned char pad1[0x20];
        unsigned char pad2[0x18];
        struct MtxWords srcMtx;
    };
    float y, z, x;
    struct { Vec result; Vec offset; } work;
    // Camera placement (mode 2): restore the saved rotation matrix, rotate a
    // fixed local offset (0, 0.8, -0.1 + (state-1.397)) by that rotation and
    // add it to the camera position, then recompute the rotation from the
    // current angles. If the state flag is set, defer to the mode-3 placement.
    char *state = *(char **)((char *)cam + 0x140);
    if (*(unsigned char *)(state + 0x260C) != 0) {
        applyFlippedTransform(cam);
        return;
    }
    ((struct TransformObj *)cam)->mtx = ((struct TransformObj *)cam)->srcMtx;
    x = lbl_80563FB0;
    y = lbl_80563FE8;
    z = lbl_80563FEC + (*(float *)(state + 0x2458) - lbl_80563FE4);
    work.offset.x = x;
    work.offset.y = y;
    work.offset.z = z;
    {
        float *vector;
        float *result;
        result = &work.result.x;
        vector = &work.offset.x;
        if (result == vector) {
            float m00, m01, m02, m10, m11, m20, m21, m12, m22;
            float o0, o1, o2;
            m10 = *(float *)((char *)cam + 0x64);
            m00 = *(float *)((char *)cam + 0x58);
            m11 = *(float *)((char *)cam + 0x68);
            m01 = *(float *)((char *)cam + 0x5C);
            m12 = *(float *)((char *)cam + 0x6C);
            m02 = *(float *)((char *)cam + 0x60);
            m20 = *(float *)((char *)cam + 0x70);
            m21 = *(float *)((char *)cam + 0x74);
            m22 = *(float *)((char *)cam + 0x78);
            o0 = z * m20 + (x * m00 + y * m10);
            o1 = z * m21 + (x * m01 + y * m11);
            o2 = z * m22 + (x * m02 + y * m12);
            result[0] = o0;
            result[1] = o1;
            result[2] = o2;
        } else {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
            m10 = *(float *)((char *)cam + 0x64);
            m00 = *(float *)((char *)cam + 0x58);
            m20 = *(float *)((char *)cam + 0x70);
            result[0] = vector[2] * m20 + (vector[0] * m00 + vector[1] * m10);
            m11 = *(float *)((char *)cam + 0x68);
            m01 = *(float *)((char *)cam + 0x5C);
            m21 = *(float *)((char *)cam + 0x74);
            result[1] = vector[2] * m21 + (vector[0] * m01 + vector[1] * m11);
            m12 = *(float *)((char *)cam + 0x6C);
            m02 = *(float *)((char *)cam + 0x60);
            m22 = *(float *)((char *)cam + 0x78);
            result[2] = vector[2] * m22 + (vector[0] * m02 + vector[1] * m12);
        }
    }
    *(float *)((char *)cam + 0x7C) += work.result.x;
    *(float *)((char *)cam + 0x80) += work.result.y;
    *(float *)((char *)cam + 0x84) += work.result.z;
    fn_80273B4C(cam);
}
void fn_8027445C(void) {
    extern void fn_80274268();
    /* Vtable thunk: tail-forward to the camera placement (mode 2) helper. */
    fn_80274268();
}

#pragma push
#pragma processor 750
void applyFlippedTransform(void *obj) {
#pragma opt_common_subs off
#pragma scheduling on
    /* Mode-3 placement: copy the source 3x4 transform at +0xC0 over the live one at +0x58,
     * compose a half-turn about Y into it (fn_80015A20 builds the Euler (0, pi, 0) matrix,
     * fn_80015B20 the 3x3 product), then add the (0, 0.8, 0) offset rotated into the flipped
     * basis to the translation column at +0x7C. */
    struct MtxWords { unsigned int word[12]; };
    struct TransformObj {
        unsigned char pad0[0x58];
        struct MtxWords mtx;    /* +0x58 live 3x4 transform; translation at +0x7C */
        unsigned char pad1[0x20];
        unsigned char pad2[0x18];
        struct MtxWords srcMtx; /* +0xC0 source transform copied from the linked object */
    };
    float x, y, z;
    struct {
        Vec result;
        Vec offset;
        float angles[3];
        float rotMtx[9];
    } work;
    ((struct TransformObj *)obj)->mtx = ((struct TransformObj *)obj)->srcMtx;
    work.angles[0] = 0.0f;
    work.angles[1] = 3.1415927f;
    work.angles[2] = 0.0f;
    ((void (*)(void *, float *))fn_80015A20)(work.rotMtx, work.angles);
    fn_80015B20((char *)obj + 0x58, work.rotMtx, (char *)obj + 0x58);
    x = 0.0f;
    y = 0.8f;
    z = 0.0f;
    work.offset.x = x;
    work.offset.y = y;
    work.offset.z = z;
    {
        float *vector;
        float *result;
        result = &work.result.x;
        vector = &work.offset.x;
        if (result == vector) {
            float m00, m01, m02, m10, m11, m20, m21, m12, m22;
            float o0, o1, o2;
            m10 = *(float *)((char *)obj + 0x64);
            m00 = *(float *)((char *)obj + 0x58);
            m11 = *(float *)((char *)obj + 0x68);
            m01 = *(float *)((char *)obj + 0x5C);
            m12 = *(float *)((char *)obj + 0x6C);
            m02 = *(float *)((char *)obj + 0x60);
            m20 = *(float *)((char *)obj + 0x70);
            m21 = *(float *)((char *)obj + 0x74);
            m22 = *(float *)((char *)obj + 0x78);
            o0 = z * m20 + (x * m00 + y * m10);
            o1 = z * m21 + (x * m01 + y * m11);
            o2 = z * m22 + (x * m02 + y * m12);
            result[0] = o0;
            result[1] = o1;
            result[2] = o2;
        } else {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
            m10 = *(float *)((char *)obj + 0x64);
            m00 = *(float *)((char *)obj + 0x58);
            m20 = *(float *)((char *)obj + 0x70);
            result[0] = vector[2] * m20 + (vector[0] * m00 + vector[1] * m10);
            m11 = *(float *)((char *)obj + 0x68);
            m01 = *(float *)((char *)obj + 0x5C);
            m21 = *(float *)((char *)obj + 0x74);
            result[1] = vector[2] * m21 + (vector[0] * m01 + vector[1] * m11);
            m12 = *(float *)((char *)obj + 0x6C);
            m02 = *(float *)((char *)obj + 0x60);
            m22 = *(float *)((char *)obj + 0x78);
            result[2] = vector[2] * m22 + (vector[0] * m02 + vector[1] * m12);
        }
    }
    *(float *)((char *)obj + 0x7C) += work.result.x;
    *(float *)((char *)obj + 0x80) += work.result.y;
    *(float *)((char *)obj + 0x84) += work.result.z;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Reset this object's 3x4 transform at +0x58 to identity, compose a +90-degree X rotation, set its translation from the position at +0xE4/E8/EC, add a mode-dependent height offset (10.1 for mode 10, else 50) to Y, and clear +0x124. */
void fn_80274660(void *unused, void *object) {
    extern void fn_80015A20(void *, float *, float, float);
    extern float lbl_80563FF4, lbl_80563FF8;
    float matrix[9];
    float vec[3];
    float offset;
    char *p = (char *)object;
    *(float *)(p + 0x5C) = 0.0f;
    *(float *)(p + 0x58) = 1.0f;
    *(float *)(p + 0x60) = 0.0f;
    *(float *)(p + 0x64) = 0.0f;
    *(float *)(p + 0x68) = 1.0f;
    *(float *)(p + 0x6C) = 0.0f;
    *(float *)(p + 0x70) = 0.0f;
    *(float *)(p + 0x74) = 0.0f;
    *(float *)(p + 0x78) = 1.0f;
    *(float *)(p + 0x7C) = 0.0f;
    *(float *)(p + 0x80) = 0.0f;
    *(float *)(p + 0x84) = 0.0f;
    vec[0] = 1.5707964f;
    vec[1] = 0.0f;
    vec[2] = 0.0f;
    fn_80015A20(matrix, vec, 0.0f, 1.0f);
    fn_80015B20(p + 0x58, matrix, p + 0x58);
    *(float *)(p + 0x7C) = *(float *)(p + 0xE4);
    *(float *)(p + 0x80) = *(float *)(p + 0xE8);
    *(float *)(p + 0x84) = *(float *)(p + 0xEC);
    if (*(int *)(p + 0x10) == 10) {
        offset = lbl_80563FF4;
    } else {
        offset = lbl_80563FF8;
    }
    {
        float y = *(float *)(p + 0x80) + offset;
        *(float *)(p + 0x124) = 0.0f;
        *(float *)(p + 0x80) = y;
    }
}
#pragma scheduling on
#pragma pop
extern float PSQUATMultiply(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern void PSVECNormalize(void *, void *);
extern double atan(double), fn_8002EF30(float), fabs(double);
extern float lbl_80558DC4[];
extern float  lbl_80563FC4, lbl_80563FD8, lbl_80563FFC, lbl_80564000, lbl_80564004, lbl_80564008, lbl_8056400C;
extern float lbl_80558DC4[];
extern float  lbl_80563FC4, lbl_80563FD8, lbl_80563FFC, lbl_80564000, lbl_80564004, lbl_80564008, lbl_8056400C;
#pragma push
#pragma processor 750
int fn_80274730(void *arg0, float arg1, float arg2, float arg3, float arg4) {
    float up[3], forward[3], side[3], right[3];
    char *p=arg0;
    float x,y,z,d,scale,dist,lower,angle,ratio,speed,v;
    float th;
    x=(*(float *)(p+0x4c))-(*(float *)(p+0x7c)); y=(*(float *)(p+0x50))-(*(float *)(p+0x80)); z=(*(float *)(p+0x54))-(*(float *)(p+0x84));
    (*(float *)(p+0x70))=x; (*(float *)(p+0x74))=y; (*(float *)(p+0x78))=z;
    th=lbl_80558DC4[0];
    if ((float)__fabs(x)<=th && (float)__fabs(z)<=th) {
        (*(float *)(p+0x70))=(*(float *)(p+0xd8)); (*(float *)(p+0x78))=(*(float *)(p+0xe0));
    }
    up[0]=lbl_80563FB0; up[1]=lbl_80563FAC; up[2]=lbl_80563FB0;
    PSVECCrossProduct(up,p+0x70,p+0x58);
    PSVECCrossProduct(p+0x70,p+0x58,p+0x64);
    z=(*(float *)(p+0x60)); y=(*(float *)(p+0x5c)); x=(*(float *)(p+0x58)); right[0]=x; right[1]=y; right[2]=z;
    z=(*(float *)(p+0x78)); y=(*(float *)(p+0x74)); x=(*(float *)(p+0x70)); forward[0]=x; forward[1]=y; forward[2]=z;
    PSVECCrossProduct(forward,right,side);
    PSVECNormalize(right,right); PSVECNormalize(side,side);
    PSVECCrossProduct(right,side,forward);
    (*(float *)(p+0x58))=right[0]; (*(float *)(p+0x5c))=right[1]; (*(float *)(p+0x60))=right[2];
    (*(float *)(p+0x64))=side[0]; (*(float *)(p+0x68))=side[1]; (*(float *)(p+0x6c))=side[2];
    (*(float *)(p+0x70))=forward[0]; (*(float *)(p+0x74))=forward[1]; (*(float *)(p+0x78))=forward[2];
    d=PSQUATMultiply(p+0x7c,p+0x4c);
    if (arg2>lbl_80563FB0) {
        scale=(lbl_80563FAC-arg4)*(d-arg2);
        x=(*(float *)(p+0x7c))+(*(float *)(p+0x70))*scale; y=(*(float *)(p+0x80))+(*(float *)(p+0x74))*scale; z=(*(float *)(p+0x84))+(*(float *)(p+0x78))*scale;
        (*(float *)(p+0x7c))=x; (*(float *)(p+0x80))=y; (*(float *)(p+0x84))=z;
    }
    dist=PSQUATMultiply(p+0x7c,p+0x4c);
    lower=lbl_80563FFC; angle=lbl_80564000; v=lbl_80564004;
    if (arg3>lbl_80564008) ratio=lbl_80563FAC/arg3; else ratio=lbl_80563FAC;
    speed=lbl_8056400C*ratio;
    v=lbl_80563FD8*(float)atan((speed/dist)*(float)fn_8002EF30(v*lbl_80563FC4));
    angle=angle<v?angle:v;
    angle=angle>lower?angle:lower;
    if(arg1>lbl_80563FB0) { (*(float *)(p+0xbc))=arg1; (*(float *)(p+0x194))=arg1; }
    else { v=(*(float *)(p+0x194)); v=v+lbl_80563FAC*(angle-v); (*(float *)(p+0xbc))=v; (*(float *)(p+0x194))=v; }
    v=lbl_80563FB0; (*(float *)(p+0x120))=v; (*(float *)(p+0x124))=v; (*(float *)(p+0x128))=v;
}

extern int fn_801EA098(void *, void *, float *, int *, float, float);
extern float lbl_8055F580;
extern float lbl_80563FDC;
extern unsigned char lbl_8055F584;
extern double lbl_80563FB8;
#pragma push
#pragma processor 750
void fn_802749FC(void *arg0, void *arg1) {
#pragma opt_common_subs off
    extern float PSVECDotProduct(float *, float *);
    struct { int sp8; float spC[3]; float sp18[3]; float sp24[3]; float sp30[3]; float sp3C; float pad[2]; float sp48[3]; } local;
    unsigned int m11, m10, m9, m8, m7, m6, m5, m4, m3, m2, m1, m0;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_f7_2;
    float temp_f8;
    float var_f3;
    float var_f5;

    if ((int) (*(unsigned char *)((char *)arg0 + 0x138)) != 0) {
        float zero = lbl_80563FAC;
        float one = lbl_80563FB0;
        (*(float *)((char *)arg0 + 0x28)) = one;
        (*(float *)((char *)arg0 + 0x2C)) = zero;
        (*(float *)((char *)arg0 + 0x30)) = one;
        (*(float *)((char *)arg0 + 0x34)) = one;
        (*(float *)((char *)arg0 + 0x38)) = one;
        (*(float *)((char *)arg0 + 0x3C)) = one;
    }
    m0 = *(volatile unsigned int *)((char *)arg0 + 0xC0);
    m1 = *(volatile unsigned int *)((char *)arg0 + 0xC4);
    m2 = *(volatile unsigned int *)((char *)arg0 + 0xC8);
    m3 = *(volatile unsigned int *)((char *)arg0 + 0xCC);
    m4 = *(volatile unsigned int *)((char *)arg0 + 0xD0);
    m5 = *(volatile unsigned int *)((char *)arg0 + 0xD4);
    m6 = *(volatile unsigned int *)((char *)arg0 + 0xD8);
    m7 = *(volatile unsigned int *)((char *)arg0 + 0xDC);
    m8 = *(volatile unsigned int *)((char *)arg0 + 0xE0);
    m9 = *(volatile unsigned int *)((char *)arg0 + 0xE4);
    m10 = *(volatile unsigned int *)((char *)arg0 + 0xE8);
    m11 = *(volatile unsigned int *)((char *)arg0 + 0xEC);
    *(unsigned int *)((char *)arg0 + 0x58) = m0;
    *(unsigned int *)((char *)arg0 + 0x5C) = m1;
    *(unsigned int *)((char *)arg0 + 0x60) = m2;
    *(unsigned int *)((char *)arg0 + 0x64) = m3;
    *(unsigned int *)((char *)arg0 + 0x68) = m4;
    *(unsigned int *)((char *)arg0 + 0x6C) = m5;
    *(unsigned int *)((char *)arg0 + 0x70) = m6;
    *(unsigned int *)((char *)arg0 + 0x74) = m7;
    *(unsigned int *)((char *)arg0 + 0x78) = m8;
    *(unsigned int *)((char *)arg0 + 0x7C) = m9;
    *(unsigned int *)((char *)arg0 + 0x80) = m10;
    *(unsigned int *)((char *)arg0 + 0x84) = m11;
    if (&local.sp30[0] == arg1) {
        temp_f6 = (*(float *)((char *)arg1 + 4));
        temp_f0 = (*(float *)((char *)arg1 + 0));
        temp_f7 = (*(float *)((char *)arg1 + 8));
        local.sp30[0] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x70)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x58)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x64)))));
        local.sp30[1] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x74)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x5C)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x68)))));
        local.sp30[2] = (temp_f7 * (*(float *)((char *)((char *)arg0 + 0x78)))) + ((temp_f0 * (*(float *)((char *)((char *)arg0 + 0x60)))) + (temp_f6 * (*(float *)((char *)((char *)arg0 + 0x6C)))));
    } else {
        local.sp30[0] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x70)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x58)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x64)))));
        local.sp30[1] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x74)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x5C)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x68)))));
        local.sp30[2] = ((*(float *)((char *)arg1 + 8)) * (*(float *)((char *)((char *)arg0 + 0x78)))) + (((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)((char *)arg0 + 0x60)))) + ((*(float *)((char *)arg1 + 4)) * (*(float *)((char *)((char *)arg0 + 0x6C)))));
    }
    (*(float *)((char *)((char *)arg0 + 0x7C))) = (float) ((*(float *)((char *)((char *)arg0 + 0x7C))) + local.sp30[0]);
    (*(float *)((char *)((char *)arg0 + 0x80))) = (float) ((*(float *)((char *)((char *)arg0 + 0x80))) + local.sp30[1]);
    (*(float *)((char *)((char *)arg0 + 0x84))) = (float) ((*(float *)((char *)((char *)arg0 + 0x84))) + local.sp30[2]);
    local.sp8 = 0;
    if ((signed char) lbl_8055F584 == 0) {
        temp_f0_2 = (float) cos(lbl_80563FB8);
        lbl_8055F584 = 1;
        lbl_8055F580 = temp_f0_2;
    }
    if (fn_801EA098((char *)(*(void **)((char *)arg0 + 0x140)) + 0x6C, &local.sp3C, &local.sp48[0], &local.sp8, (*(float *)((char *)((char *)arg0 + 0xE4))), (*(float *)((char *)((char *)arg0 + 0xEC)))) == 0) {
        local.sp48[0] = (*(float *)((char *)arg0 + 0xCC));
        local.sp48[1] = (*(float *)((char *)arg0 + 0xD0));
        local.sp48[2] = (*(float *)((char *)arg0 + 0xD4));
    } else {
        temp_f0_3 = (PSVECDotProduct(&local.sp48[0], (float *)((unsigned int)arg0 + 0xCC)) - lbl_8055F580) / (lbl_80563FAC - lbl_8055F580);
        var_f5 = lbl_80563FB0;
        var_f5 = (var_f5 > temp_f0_3) ? var_f5 : temp_f0_3;
        temp_f4 = local.sp48[0] * var_f5;
        temp_f3 = local.sp48[1] * var_f5;
        temp_f2 = local.sp48[2] * var_f5;
        local.sp48[0] = temp_f4;
        temp_f1 = lbl_80563FAC - var_f5;
        local.sp48[1] = temp_f3;
        local.sp48[2] = temp_f2;
        local.sp48[0] = temp_f4 + ((*(float *)((char *)arg0 + 0xCC)) * temp_f1);
        local.sp48[1] = temp_f3 + ((*(float *)((char *)arg0 + 0xD0)) * temp_f1);
        local.sp48[2] = temp_f2 + ((*(float *)((char *)arg0 + 0xD4)) * temp_f1);
    }
    if ((int) (*(unsigned char *)((char *)arg0 + 0x138)) != 0) {
        var_f3 = lbl_80563FB0;
    } else {
        var_f3 = lbl_80563FDC;
    }
    temp_f5 = (*(float *)((char *)((char *)arg0 + 0x28))) * var_f3;
    temp_f8 = (*(float *)((char *)((char *)arg0 + 0x2C))) * var_f3;
    temp_f7_2 = (*(float *)((char *)((char *)arg0 + 0x30))) * var_f3;
    (*(float *)((char *)arg0 + 0x28)) = temp_f5;
    temp_f6_2 = lbl_80563FAC - var_f3;
    (*(float *)((char *)arg0 + 0x2C)) = temp_f8;
    (*(float *)((char *)arg0 + 0x30)) = temp_f7_2;
    temp_f3_2 = temp_f5 + (local.sp48[0] * temp_f6_2);
    (*(float *)((char *)arg0 + 0x28)) = temp_f3_2;
    temp_f3_3 = temp_f8 + (local.sp48[1] * temp_f6_2);
    (*(float *)((char *)arg0 + 0x2C)) = temp_f3_3;
    temp_f3_4 = local.sp48[2] * temp_f6_2;
    (*(float *)((char *)arg0 + 0x64)) = (float) ((temp_f3_2 * lbl_80563FC4) + ((*(float *)((char *)arg0 + 0xCC)) * lbl_80563FC4));
    (*(float *)((char *)arg0 + 0x68)) = (float) ((temp_f3_3 * lbl_80563FC4) + ((*(float *)((char *)arg0 + 0xD0)) * lbl_80563FC4));
    temp_f2_2 = temp_f7_2 + temp_f3_4;
    temp_f1_2 = temp_f2_2 * lbl_80563FC4;
    (*(float *)((char *)arg0 + 0x30)) = temp_f2_2;
    (*(float *)((char *)arg0 + 0x6C)) = (float) (temp_f1_2 + ((*(float *)((char *)arg0 + 0xD4)) * lbl_80563FC4));
    PSVECCrossProduct((char *)((char *)arg0 + 0x64), (char *)((char *)arg0 + 0x70), (char *)((char *)arg0 + 0x58));
    PSVECCrossProduct((void *)((unsigned int)arg0 + 0x58), (void *)((unsigned int)arg0 + 0x64), (void *)((unsigned int)arg0 + 0x70));
    local.spC[0] = (*(float *)((char *)((char *)arg0 + 0x58)));
    local.spC[1] = (*(float *)((char *)((char *)arg0 + 0x5C)));
    local.spC[2] = (*(float *)((char *)((char *)arg0 + 0x60)));
    temp_f2_3 = (*(float *)((char *)((char *)arg0 + 0x78)));
    temp_f1_3 = (*(float *)((char *)((char *)arg0 + 0x74)));
    local.sp24[0] = (*(float *)((char *)((char *)arg0 + 0x70)));
    local.sp24[1] = temp_f1_3;
    local.sp24[2] = temp_f2_3;
    PSVECCrossProduct(&local.sp24[0], &local.spC[0], &local.sp18[0]);
    PSVECNormalize(&local.spC[0], &local.spC[0]);
    PSVECNormalize(&local.sp18[0], &local.sp18[0]);
    PSVECCrossProduct(&local.spC[0], &local.sp18[0], &local.sp24[0]);
    (*(float *)((char *)arg0 + 0x58)) = local.spC[0];
    (*(float *)((char *)arg0 + 0x5C)) = local.spC[1];
    (*(float *)((char *)arg0 + 0x60)) = local.spC[2];
    (*(float *)((char *)arg0 + 0x64)) = local.sp18[0];
    (*(float *)((char *)arg0 + 0x68)) = local.sp18[1];
    (*(float *)((char *)arg0 + 0x6C)) = local.sp18[2];
    (*(float *)((char *)arg0 + 0x70)) = local.sp24[0];
    (*(float *)((char *)arg0 + 0x74)) = local.sp24[1];
    (*(float *)((char *)arg0 + 0x78)) = local.sp24[2];
}
#pragma pop
extern float lbl_80563FA8;
void fn_80274E94(void *object) {
    /* Update the object's camera/orientation state with inactive (-1.0f) inputs and 0.0f scale. */
    fn_80274730(object, lbl_80563FA8, lbl_80563FA8, lbl_80563FA8, lbl_80563FB0);
}

/* Clamp the object's position to a max radius from a reference point, then update its camera/orientation state. */
void fn_80274EA8(void *object) {
    float offset[3];
    float distance;
    float correctionScale;
    char *objectBytes = (char *)object;

    offset[0] = *(float *)(objectBytes + 0x7C) - *(float *)(objectBytes + 0xE4);
    offset[1] = *(float *)(objectBytes + 0x80) - *(float *)(objectBytes + 0xE8);
    offset[2] = *(float *)(objectBytes + 0x84) - *(float *)(objectBytes + 0xEC);
    distance = PSVECMag(offset);
    if (distance > lbl_80564010) {
        correctionScale = -(distance - lbl_80564010) / distance;
        *(float *)(objectBytes + 0x7C) += offset[0] * correctionScale;
        *(float *)(objectBytes + 0x80) += offset[1] * correctionScale;
        *(float *)(objectBytes + 0x84) += offset[2] * correctionScale;
    }
    fn_80274730(object, lbl_80563FA8, lbl_80564014, lbl_80564018, lbl_8056401C);
}

static inline void helper_80274F74(void *arg0, void *arg1) {
    float magnitude;
    float scale;
    float cosine;
    float y;
    float z;
    float sine;
    float x;

    magnitude = PSVECMag(arg1);
    if (magnitude > lbl_80564020) {
        scale = lbl_80563FAC / magnitude;
        x = scale * *(float *)arg1;
        y = scale * *(float *)((char *)arg1 + 4);
        z = scale * *(float *)((char *)arg1 + 8);
        sine = (float)sin(magnitude);
        cosine = (float)cos(magnitude);
        {
            float xx = x * x;
            float yy = y * y;
            float t = lbl_80563FAC - cosine;
            float zz = z * z;
            float sz = sine * z;
            float tx = t * x;
            float txx = t * xx;
            float tyy = t * yy;
            float ty = t * y;
            float txy = y * tx;
            float m00 = cosine + txx;
            float tzz = t * zz;
            float txz = z * tx;
            float sy = sine * y;
            *(float *)((char *)arg0 + 0x58) = m00;
            *(float *)((char *)arg0 + 0x5C) = txy + sz;
            {
                float tyz = z * ty;
                float sx = sine * x;
                *(float *)((char *)arg0 + 0x64) = txy - sz;
                *(float *)((char *)arg0 + 0x60) = txz - sy;
                *(float *)((char *)arg0 + 0x68) = cosine + tyy;
                *(float *)((char *)arg0 + 0x6C) = tyz + sx;
                *(float *)((char *)arg0 + 0x70) = txz + sy;
                *(float *)((char *)arg0 + 0x74) = tyz - sx;
                *(float *)((char *)arg0 + 0x78) = cosine + tzz;
            }
        }
    } else {
        float f0 = lbl_80563FB0;
        float f1 = lbl_80563FAC;
        *(float *)((char *)arg0 + 0x5C) = f0;
        *(float *)((char *)arg0 + 0x58) = f1;
        *(float *)((char *)arg0 + 0x60) = f0;
        *(float *)((char *)arg0 + 0x64) = f0;
        *(float *)((char *)arg0 + 0x68) = f1;
        *(float *)((char *)arg0 + 0x6C) = f0;
        *(float *)((char *)arg0 + 0x70) = f0;
        *(float *)((char *)arg0 + 0x74) = f0;
        *(float *)((char *)arg0 + 0x78) = f1;
    }
}

#pragma scheduling invalid_target
void fn_80274F74(void *arg0, void *arg1, float angle) {
    helper_80274F74(arg0, arg1);
    *(float *)((char *)arg0 + 0xBC) = angle;
}
extern float PSVECDotProduct(float *, float *);
extern void fn_8026E850(float *, float *, void *, float *);
#pragma processor 7400
/* Aim the object at its look-at target (+0xE4) using a +Y up vector, then slide its position (+0x7C) along the direction at +0x70 to correct the distance. */
void fn_802750C4(void *object, float gain, float desired) {
    float toTarget[3];
    float up[3];
    float dot;
    float delta;
    float step;
    char *p = (char *)object;
    up[0] = 0.0f;
    up[1] = 1.0f;
    up[2] = 0.0f;
    fn_8026E850((float *)(p + 0x7C), (float *)(p + 0xE4), object, up);
    toTarget[0] = *(float *)(p + 0xE4) - *(float *)(p + 0x7C);
    toTarget[1] = *(float *)(p + 0xE8) - *(float *)(p + 0x80);
    toTarget[2] = *(float *)(p + 0xEC) - *(float *)(p + 0x84);
    dot = PSVECDotProduct((float *)(p + 0x70), toTarget);
    delta = dot - desired;
    step = delta * gain;
    *(float *)(p + 0x7C) += *(float *)(p + 0x70) * step;
    *(float *)(p + 0x80) += *(float *)(p + 0x74) * step;
    *(float *)(p + 0x84) += *(float *)(p + 0x78) * step;
}
#pragma processor 750
void fn_802751AC(void *arg0)
{
  struct Matrix
  {
    int v[12];
  };
  char *self = (char *) arg0;
  float axis[3];
  float input[3];
  float matrix[9];
  volatile int params[7];
  float mag;
  float scale;
  float x;
  float s;
  float c;
  float t;
  volatile int *p = (volatile int *) lbl_802FA788;
  float z;
  float y;
  params[3] = p[3]; params[4] = p[4]; params[5] = p[5];
  params[0] = p[0]; params[1] = p[1]; params[2] = p[2] ^ 0;
  params[6] = p[6];
  *((struct Matrix *) (self + 0x58)) = *((struct Matrix *) (self + 0xC0));
  input[0] = lbl_80564024 * (*((float *) (&params[3])));
  input[1] = lbl_80564024 * (*((float *) (&params[4])));
  input[2] = lbl_80564024 * (*((float *) (&params[5])));
  axis[0] = *((float *) (&params[0])); axis[1] = *((float *) (&params[1])); axis[2] = *((float *) (&params[2]));
  mag = PSVECMag(input);
  if (mag > lbl_80564020)
  {
    scale = lbl_80563FAC / mag;
    x = scale * input[0]; y = scale * input[1]; z = scale * input[2];
    s = (float) sin(mag); c = (float) cos(mag); t = lbl_80563FAC - c;
    matrix[0] = c + (t * (x * x));
    matrix[1] = (y * (t * x)) + (z * s);
    matrix[2] = (z * (t * x)) - (s * y);
    matrix[3] = (y * (x * t)) - (s * z);
    matrix[4] = (0, c + (t * (y * y)));
    matrix[5] = (s * x) + (z * (t * y));
    matrix[6] = (0, (z * (t * x)) + (s * y));
    matrix[7] = (z * (t * y)) - (s * x);
    matrix[8] = c + (t * (z * z));
  }
  else
  {
    matrix[0] = lbl_80563FAC;
    matrix[1] = (double) lbl_80563FB0;
    matrix[2] = lbl_80563FB0;
    matrix[3] = lbl_80563FB0; matrix[4] = lbl_80563FAC; matrix[5] = lbl_80563FB0;
    matrix[6] = lbl_80563FB0; matrix[7] = lbl_80563FB0; matrix[8] = lbl_80563FAC;
  }
  fn_801BFD34(self + 0x7C, axis, self + 0xC0);
  fn_80015B20(self + 0x58, matrix, self + 0xC0);
  *((float *) (self + 0xBC)) = (*((float *) (&params[6]))) * lbl_80564024;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80275410(void *arg0) {
    extern float lbl_802FA7A4[], lbl_80564028, lbl_8056402C;
    extern const float lbl_80563FE8;
    struct Matrix { int v[12]; };
    struct Params { float a[7]; };
    char *self = (char *)arg0;
    char *state = *(char **)(self+0x140);
    struct Params params = *(struct Params *)lbl_802FA7A4;
    float axis[4], input[4], matrix[12];
    float mag, scale, x, y, z, s, c, t;
    axis[0] = *(float *)(state+0x2450) + lbl_80563FE8;
    axis[1] = *(float *)(state+0x2454) + lbl_80564028;
    axis[2] = *(float *)(state+0x2458) + lbl_8056402C;
    *(struct Matrix *)(self+0x58) = *(struct Matrix *)(self+0xC0);
    input[0] = lbl_80564024 * params.a[3];
    input[1] = lbl_80564024 * params.a[4];
    input[2] = lbl_80564024 * params.a[5];
    mag = PSVECMag(input);
    if (mag > lbl_80564020) {
        scale = lbl_80563FAC / mag;
        x = scale * input[0]; y = scale * input[1]; z = scale * input[2];
        s = (float)sin(mag); c = (float)cos(mag); t = lbl_80563FAC - c;
        matrix[0] = c + t * (x*x);
        matrix[1] = y * (t*x) + s*z;
        matrix[2] = z * (t*x) - s*y;
        matrix[3] = y * (t*x) - s*z;
        matrix[4] = c + t * (y*y);
        matrix[5] = z * (t*y) + s*x;
        matrix[6] = z * (t*x) + s*y;
        matrix[7] = z * (t*y) - s*x;
        matrix[8] = c + t * (z*z);
    } else {
        matrix[0]=lbl_80563FAC; matrix[1]=lbl_80563FB0; matrix[2]=lbl_80563FB0;
        matrix[3]=lbl_80563FB0; matrix[4]=lbl_80563FAC; matrix[5]=lbl_80563FB0;
        matrix[6]=lbl_80563FB0; matrix[7]=lbl_80563FB0; matrix[8]=lbl_80563FAC;
    }
    fn_801BFD34(self+0x7C, axis, self+0xC0);
    fn_80015B20(self+0x58, matrix, self+0xC0);
    *(float *)(self+0xBC) = lbl_80564024 * params.a[6];
}
#pragma pop

extern float lbl_80564030, lbl_80563FDC, lbl_80563FD8, lbl_80564024, lbl_80564020, lbl_80563FAC;
extern float lbl_802FA7C0[];
extern double sin(double), cos(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802756A4(void *arg0)
{
  extern float lbl_802FA7C0[];
  extern float lbl_80564030;
  extern float lbl_80563FDC;
  extern float lbl_80563FD8;
  struct Matrix
  {
    int v[12];
  };
  struct Params
  {
    float a[7];
  };
  char *self = (char *) arg0;
  char *state = *((char **) (((char *) arg0) + 0x140));
  struct Params params = *((struct Params *) lbl_802FA7C0);
  float axis[4];
  float input[4];
  float matrix[12];
  float mag;
  float scale;
  float x;
  float y;
  float z;
  float s;
  float c;
  float t;
  axis[0] = (*((float *) (state + 0x2538))) + lbl_80564030;
  axis[1] = (*((float *) (state + 0x253C))) + lbl_80563FDC;
  axis[2] = lbl_80563FD8 + (*((float *) (state + 0x2540)));
  *((struct Matrix *) (((char *) arg0) + 0x58)) = *((struct Matrix *) (((char *) arg0) + 0xC0));
  input[1] = (long long) (lbl_80564024 * ((0, params.a[4])));
  input[0] = lbl_80564024 * params.a[3];
  input[2] = lbl_80564024 * params.a[5];
  mag = PSVECMag(input);
  if (mag > lbl_80564020)
  {
    scale = lbl_80563FAC / mag;
    x = scale * input[0]; y = scale * input[1]; z = scale * input[2];
    s = (float) sin(mag); c = (float) cos(mag); t = lbl_80563FAC - c;
    matrix[0] = c + (t * (x * x));
    matrix[1] = (y * (t * x)) + (s * z);
    matrix[2] = (z * (t * x)) - (y * s);
    matrix[3] = (y * (t * x)) - (s * z);
    matrix[4] = c + (t * (y * y));
    matrix[5] = (s * x) + (z * (t * y));
    matrix[6] = (z * (t * x)) + (s * y);
    matrix[7] = (z * (t * y)) - (s * x);
    matrix[8] = c + (t * ((0, (double) (z * z))));
  }
  else
  {
    if (1)
    {
      matrix[0] = lbl_80563FAC; matrix[1] = lbl_80563FB0;
    }
    matrix[2] = lbl_80563FB0;
    matrix[3] = lbl_80563FB0; matrix[4] = lbl_80563FAC; matrix[5] = lbl_80563FB0;
    matrix[6] = lbl_80563FB0; matrix[7] = lbl_80563FB0; matrix[8] = lbl_80563FAC;
  }
  fn_801BFD34(((char *) arg0) + 0x7C, axis, ((char *) arg0) + 0xC0);
  fn_80015B20(self + 0x58, matrix, self + 0xC0);
  *((float *) (((char *) arg0) + 0xBC)) = params.a[6] * lbl_80564024;
}

extern float lbl_802FA7DC[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80275938(void *arg0)
{
  struct Matrix
  {
    int v[12];
  };
  char *self = (char *) arg0;
  float axis[3];
  float input[3];
  float matrix[9];
  volatile int params[7];
  float mag;
  float scale;
  float x;
  float y;
  float z;
  float s;
  float c;
  float t;
  volatile int *p = (volatile int *) lbl_802FA7DC;
  params[3] = p[3]; params[4] = p[4]; params[5] = p[5];
  params[0] = (0, p[0]); params[1] = p[1]; params[2] = p[2];
  params[6] = p[6];
  *((struct Matrix *) (self + 0x58)) = *((struct Matrix *) (self + 0xC0));
  input[0] = lbl_80564024 * (*((float *) (&params[3])));
  input[1] = (0, lbl_80564024 * (*((float *) (&params[4]))));
  input[2] = lbl_80564024 * (*((float *) (&params[5])));
  axis[0] = *((float *) (&params[0])); axis[1] = *((float *) (&params[1])); axis[2] = *((float *) (&params[2]));
  mag = PSVECMag(input);
  if (mag > lbl_80564020)
  {
    scale = lbl_80563FAC / mag;
    x = scale * input[0];
    if (1)
    {
      if (1)
      {
        y = scale * input[1]; z = scale * input[2];
        s = (float) sin(mag); c = (float) cos(mag); t = lbl_80563FAC - c;
        matrix[0] = c + (t * (x * x));
        matrix[1] = (y * (t * x)) + (s * z);
        matrix[2] = (z * (t * x)) - (y * s);
        matrix[3] = (0, (y * (t * x)) - (s * z));
      }
    }
    matrix[4] = c + (t * (y * y));
    matrix[5] = (0, (s * x) + (z * (t * y)));
    matrix[6] = (z * (t * x)) + (s * y);
    matrix[7] = (z * (t * y)) - (s * x);
    matrix[8] = c + (t * ((0, z * z)));
  }
  else
  {
    matrix[0] = lbl_80563FAC; matrix[1] = lbl_80563FB0;
    do
    {
      matrix[2] = lbl_80563FB0; matrix[3] = lbl_80563FB0; matrix[4] = lbl_80563FAC;
    }
    while (0);
    matrix[5] = lbl_80563FB0;
    matrix[6] = lbl_80563FB0; matrix[7] = lbl_80563FB0; matrix[8] = lbl_80563FAC;
  }
  fn_801BFD34(self + 0x7C, axis, self + 0xC0);
  fn_80015B20(((char *) arg0) + 0x58, matrix, ((char *) arg0) + 0xC0);
  *((float *) (((char *) arg0) + 0xBC)) = (*((float *) (&params[6]))) * lbl_80564024;
}
#pragma pop

#pragma pop
extern float lbl_8055E3C8, lbl_8055F588, lbl_80563FC4, lbl_80563FD8, lbl_80564040;
extern double lbl_80564038;
extern double fn_8002EFB4(float, double);
extern int fn_801E9E30(void *, float *);
#pragma processor 750
void fn_80275B9C(void *arg0, float farg0, float farg1, float farg2) {
    struct Vec3 { float x, y, z; };
    struct Vec3 pos;
    struct Vec3 offset;
    struct Vec3 temp;
    struct Vec3 up;
    char *p = (char *)arg0;
    float angle;
    float s;
    float c;
    float py;
    float factor;

    angle = (float)fn_8002EFB4(farg2 * lbl_8055E3C8, 6.2831854820251465);
    *(float *)(p + 0x15C) = angle;
    s = farg0 * (float)sin(angle);
    c = farg0 * (float)cos(*(float *)(p + 0x15C));

    offset.y = lbl_80563FB0;
    offset.z = s;
    offset.x = c;

    pos.x = *(float *)(p + 0xE4) + offset.x;
    pos.y = *(float *)(p + 0xE8) + offset.y;
    pos.z = *(float *)(p + 0xEC) + offset.z;

    if (fn_801E9E30(p + 0x1EC, (float *)&pos) == 0) {
        factor = lbl_80563FC4;
        py = lbl_80563FD8 + lbl_8055F588;
        pos.y = py;
        temp.z = pos.z + factor * (*(float *)(p + 0xEC) - pos.z);
        temp.x = pos.x + factor * (*(float *)(p + 0xE4) - pos.x);
        temp.y = pos.y + factor * (*(float *)(p + 0xE8) - pos.y);
        pos.x = temp.x;
        pos.y = temp.y;
        pos.z = temp.z;
    } else {
        lbl_8055F588 = pos.y;
    }

    pos.y += farg1;
    up.x = lbl_80563FB0;
    up.y = lbl_80563FAC;
    up.z = lbl_80563FB0;

    fn_8026E850((float *)&pos, (float *)(p + 0xE4), arg0, (float *)&up);
    *(float *)(p + 0xBC) = lbl_80564040;
}
#pragma push
#pragma use_lmw_stmw off
void fn_80275D0C(void *arg0, void *arg1)
{
  struct Words12
  {
    unsigned int value[12];
  };
  struct Words7
  {
    unsigned int value[7];
  };
  struct Work
  {
    float sp8[3];
    struct Words7 local_14;
    float sp30[3];
    float sp3C[3];
    float sp48[3];
    float sp54[3];
    float matrix[9];
    float sp84[3];
    char pad[0x20];
  } work;
  extern const struct Words7 lbl_802FA7F8;
  float x;
  float s;
  float z;
  float y;
  float mag;
  float scale;
  float c;
  float t;
  float m2;
  float m1;
  float m0;
  float zero;
  float one;
  work.local_14 = lbl_802FA7F8;
  *((struct Words12 *) (((char *) arg0) + ((unsigned long long) 0x58))) = *((struct Words12 *) (((char *) arg0) + 0xC0));
  work.sp54[0] = *((float *) (((char *) arg0) + 0xE4));
  work.sp54[1] = *((float *) (((char *) arg0) + 0xE8));
  do
  {
    work.sp54[2] = *((float *) (((char *) arg0) + 0xEC)); work.sp48[0] = *((float *) (((char *) arg0) + 0xD8)); work.sp48[1] = *((float *) (((char *) arg0) + 0xDC)); work.sp48[2] = *((float *) (((char *) arg0) + 0xE0)); work.sp3C[0] = lbl_80563FB0; work.sp3C[1] = lbl_80563FAC;
  }
  while (0);
  work.sp3C[2] = lbl_80563FB0;
  PSVECCrossProduct(work.sp3C, work.sp48, work.sp30);
  PSVECCrossProduct(work.sp48, work.sp30, work.sp3C);
  m2 = ((float *) (&work.local_14))[5] * lbl_80564024;
  m1 = ((float *) (&work.local_14))[4] * lbl_80564024;
  m0 = ((float *) (&work.local_14))[3] * lbl_80564024;
  work.sp84[1] = ((float *) (&work.local_14))[1];
  work.sp84[0] = ((float *) (&work.local_14))[0];
  work.sp84[2] = ((float *) (&work.local_14))[2];
  work.sp8[0] = m0;
  work.sp8[1] = m1;
  work.sp8[2] = m2;
  mag = PSVECMag(work.sp8);
  if (mag > lbl_80564020)
  {
    scale = lbl_80563FAC / mag;
    x = scale * work.sp8[0];
    y = scale * work.sp8[1];
    z = scale * work.sp8[2];
    s = (float) sin(mag);
    c = (float) cos(mag);
    t = lbl_80563FAC - c;
    work.matrix[0] = c + (t * (x * x));
    work.matrix[1] = (y * (t * x)) + (s * z);
    work.matrix[3] = (y * (t * x)) - (s * z);
    work.matrix[2] = (z * (t * x)) - (s * y);
    work.matrix[4] = (0, c + (t * (y * y)));
    work.matrix[5] = (s * x) + (z * (t * y));
    work.matrix[6] = (z * (t * x)) + (s * y);
    work.matrix[7] = (z * (t * y)) - (s * x);
    work.matrix[8] = c + (t * (z * z));
  }
  else
  {
    zero = lbl_80563FB0;
    one = lbl_80563FAC;
    work.matrix[1] = zero;
    work.matrix[0] = one;
    work.matrix[2] = zero;
    work.matrix[3] = zero;
    work.matrix[4] = one;
    work.matrix[5] = zero;
    work.matrix[6] = zero;
    work.matrix[7] = zero;
    work.matrix[8] = one;
  }
  fn_801BFD34(((char *) arg0) + 0x7C, work.sp84, work.sp30);
  fn_80015B20(((char *) arg0) + 0x58, work.matrix, work.sp30);
  *((float *) (((char *) arg0) + 0xBC)) = ((float *) (&work.local_14))[6] * lbl_80564024;
}
#pragma pop
#pragma pop
void fn_80275FC0(void *camera) {
    /* Camera mode 21: make the view transform and angle an outside system stored
     * for this camera (0x1A4/0x1D4) the ones in use (0x058/0x0BC), for fn_80276044
     * to hand to the renderer.  See the Camera struct in src/auto/text_80265DD8_.c. */
    *(int *)((char *)camera + 0x58) = *(int *)((char *)camera + 0x1A4);
    *(int *)((char *)camera + 0x5C) = *(int *)((char *)camera + 0x1A8);
    *(int *)((char *)camera + 0x60) = *(int *)((char *)camera + 0x1AC);
    *(int *)((char *)camera + 0x64) = *(int *)((char *)camera + 0x1B0);
    *(int *)((char *)camera + 0x68) = *(int *)((char *)camera + 0x1B4);
    *(int *)((char *)camera + 0x6C) = *(int *)((char *)camera + 0x1B8);
    *(int *)((char *)camera + 0x70) = *(int *)((char *)camera + 0x1BC);
    *(int *)((char *)camera + 0x74) = *(int *)((char *)camera + 0x1C0);
    *(int *)((char *)camera + 0x78) = *(int *)((char *)camera + 0x1C4);
    *(int *)((char *)camera + 0x7C) = *(int *)((char *)camera + 0x1C8);
    *(int *)((char *)camera + 0x80) = *(int *)((char *)camera + 0x1CC);
    *(int *)((char *)camera + 0x84) = *(int *)((char *)camera + 0x1D0);
    *(float *)((char *)camera + 0xBC) = *(float *)((char *)camera + 0x1D4);
}

void fn_80276044(CamState *camera) {
    /* Camera mode 25: copy the shared default-camera record's view matrix, translation
     * vector and trailing FOV float into this camera at +0x58 and +0xBC. */
    fn_80276BE4((int)&camera->viewMatrix, (int)camera + 0xBC);
}

int fn_802704D4(int, int);
int fn_80276BE4(int, int);
int fn_80274730(void *, float, float, float, float);
void fn_80276054(int camera) {
    /* Camera mode 22: set up the camera through preset/mode 4 (fn_802704D4), the same transform path used by modes 4-8/23. */
    fn_802704D4(4, camera);
}
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
