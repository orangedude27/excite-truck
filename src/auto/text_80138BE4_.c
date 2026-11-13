// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* One body's motion along a single axis: where it is, how fast, and how that
 * speed is changing. A MotionPair holds the two of them whose *relative* motion
 * is the quadratic (target.position - self.position)
 *                      + (target.velocity - self.velocity) * t
 *                      + 0.5 * (target.acceleration - self.acceleration) * t * t
 * whose zero crossing fn_80138C28 solves for (the AI uses it for a truck
 * closing on the truck ahead: gap, speed and the speed controller's own rate). */
typedef struct Motion1D {
    /* 0x0 */ float position;
    /* 0x4 */ float velocity;
    /* 0x8 */ float acceleration;
} Motion1D;

typedef struct MotionPair {
    /* 0x00 */ Motion1D self;
    /* 0x0C */ Motion1D target;
} MotionPair;

#define motion_is_zero fn_80138BFC /* |x| <= 10 * 2^-24 */
#define opposite_signs fn_80138BE4 /* arg0 * arg1 < 0 */
#define motion_sqrt    fn_8002F234 /* MSL sqrt() */

#define ZERO        lbl_805613B8 /* 0.0f */
#define HALF        lbl_805613C0 /* 0.5f */
#define FOUR        lbl_805613C4 /* 4.0f */
#define TWO         lbl_805613C8 /* 2.0f */
#define NO_CROSSING lbl_805613CC /* -1.0f: no crossing time ahead */

extern int lbl_8055E100;
extern float lbl_80558DC4[];
extern float lbl_805613BC;
extern float lbl_805613B8;
void fn_80138F38(void *);
#pragma dont_inline on
int fn_80138BE4(float arg0, float arg1) {
    return (arg0 * arg1) < lbl_805613B8;
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_80138BFC(float arg0) {
    return (float)__fabs((double)arg0) <= lbl_805613BC * lbl_80558DC4[0];
}
#pragma dont_inline reset

extern float lbl_805613C0;
extern float lbl_805613C8;
extern float lbl_805613D0;
extern float lbl_805613C4, lbl_805613CC;
extern double fn_8002F234(float);
extern double fabs(double);
#pragma push
#pragma scheduling invalid_target
extern double __fabs(double);
#pragma push
#pragma processor 750
/* Solves a MotionPair's relative motion for the time its position crosses zero:
 * con + lin * t + quad * t * t == 0, con/lin/quad being the differences of the
 * two Motion1Ds' position, velocity and acceleration (quad = half the
 * acceleration difference). Returns 1 with *out_time on the crossing ahead: the
 * far root when the two straddle zero, the near one when both lie ahead, and
 * NO_CROSSING when neither does. Returns 0 otherwise, and when the quadratic
 * never reaches zero writes how far it falls short into *out_distance. */
int fn_80138C28(MotionPair *motion, float *out_time, float *out_distance) {
    float quad;
    float lin;
    float con;
    float discriminant;
    float roots[2];
    float term;
    float selfAccel;
    float targetAccel;
    float accelDelta;
    float fourQuad;
    if (out_distance != 0)
        *out_distance = ZERO;
    selfAccel = motion->self.acceleration;
    targetAccel = motion->target.acceleration;
    accelDelta = targetAccel - selfAccel;
    quad = accelDelta * HALF;
    lin = motion->target.velocity - motion->self.velocity;
    con = motion->target.position - motion->self.position;
    if (motion_is_zero(quad) == 0) {
        fourQuad = FOUR * quad;
        discriminant = lin * lin - fourQuad * con;
        if (discriminant >= ZERO) {
            roots[0] = ((-lin) + ((float)motion_sqrt(discriminant))) / (TWO * quad);
            roots[1] = ((-lin) - ((float)motion_sqrt(discriminant))) / (TWO * quad);
            if (opposite_signs(roots[0], roots[1]) != 0) {
                float hi = roots[1];
                float lo = roots[0];
                *out_time = (lo > hi) ? (lo) : (hi);
            } else if (roots[0] >= ZERO) {
                float hi = roots[1];
                float lo = roots[0];
                *out_time = (lo < hi) ? (lo) : (hi);
            } else {
                *out_time = NO_CROSSING;
            }
            if ((*out_time) >= ZERO)
                return 1;
        } else if (out_distance != 0) {
            float absQuad;
            term = ((-lin) > ZERO) ? (-lin) : (ZERO);
            absQuad = (float)__fabs((double)quad);
            term = (term + lin) * (TWO * absQuad);
            *out_distance = ((term * term) - discriminant) / (TWO * con);
        }
    }
    return 0;
}
#pragma pop
float fn_80138DF4(void *arg0) {
    float spC;
    float sp8;
    float temp_f1;
    float temp_f1_2;
    float temp_f2;
    float temp_f3;
    float var_f31;
    float var_f4;
    int state;
    if (fn_80138BFC(*(float *)((char *)arg0 + 0xC) - *(float *)arg0) == 0) {
        if (fn_80138BFC(*(float *)((char *)arg0 + 0x14) - *(float *)((char *)arg0 + 8)) == 0) {
            if (fn_80138C28(arg0, &spC, &sp8)) {
                var_f4 = spC;
                temp_f1 = (*(float *)((char *)arg0 + 0x10) + (var_f4 * *(float *)((char *)arg0 + 0x14))) - *(float *)((char *)arg0 + 4);
                if (var_f4 <= lbl_805613D0)
                    var_f4 = lbl_805613D0;
                var_f31 = temp_f1 / var_f4;
                lbl_8055E100 = -5;
            } else {
                var_f31 = sp8;
                lbl_8055E100 = -4;
            }
        } else {
            temp_f2 = *(float *)((char *)arg0 + 0xC) - *(float *)arg0;
            temp_f1_2 = *(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 4);
            temp_f3 = temp_f1_2 * temp_f1_2;
            var_f31 = temp_f3 / (lbl_805613C8 * temp_f2);
            if (fn_80138BE4(temp_f1_2, temp_f2))
                var_f31 = -var_f31;
            temp_f2 = *(float *)((char *)arg0 + 0xC) - *(float *)arg0;
            temp_f1_2 = *(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 4);
            if (fn_80138BE4(temp_f1_2, temp_f2) == 0)
                state = -2;
            else
                state = -3;
            lbl_8055E100 = state;
        }
    } else {
        var_f31 = lbl_805613B8;
        lbl_8055E100 = -1;
    }
    return var_f31;
}
#pragma pop
void fn_80138F38(void *arg0) {
    extern float lbl_805613B8;
    extern float lbl_805613C0;
    extern int lbl_8055E100;
    extern float fn_80138DF4(void*);
    float sp8;
    union U { struct { int a; int b; int c; float d; float e; float f; } s; double _a; } sp10;
    register float x;
    register float y;
    register float ratio;
    register float square;
    register float product;
    register float value;
    if (*(float*)((char*)arg0 + 0x10) > lbl_805613B8) {
        if (*(float*)((char*)arg0 + 0x14) < lbl_805613B8) {
            if (fn_80138C28(arg0, &sp8, 0)) {
                x = *(float*)((char*)arg0 + 0x10);
                y = *(float*)((char*)arg0 + 0x14);
                ratio = -x / y;
                if (ratio <= sp8) {
                    square = ratio * ratio;
                    product = ratio * x;
                    value = *(float*)((char*)arg0 + 0xC);
                    value += product;
                    value += (lbl_805613C0 * y) * square;
                    ((int*)&sp10)[0] = ((int*)arg0)[0];
                    ((int*)&sp10)[1] = ((int*)arg0)[1];
                    ((int*)&sp10)[2] = ((int*)arg0)[2];
                    ((int*)&sp10)[3] = ((int*)arg0)[3];
                    ((int*)&sp10)[4] = ((int*)arg0)[4];
                    ((int*)&sp10)[5] = ((int*)arg0)[5];
                    sp10.s.d = value;
                    sp10.s.e = lbl_805613B8;
                    sp10.s.f = lbl_805613B8;
                    fn_80138DF4(&sp10);
                    lbl_8055E100 += 6;
                    return;
                }
            }
        }
    }
    fn_80138DF4(arg0);
}
void fn_80139030(void *arg0) {
    lbl_8055E100 = -6;
    fn_80138F38(arg0);
}
