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
int fn_80138C28(void *rect, float *out_t, float *out_distance) {
    float a;
    float b;
    float c;
    float disc;
    float roots[2];
    float term;
    float left;
    float right;
    float diff;
    float tmp;
    if (out_distance != 0)
        *out_distance = lbl_805613B8;
    left = *(float *)((char *)rect + 0x08);
    right = *(float *)((char *)rect + 0x14);
    diff = right - left;
    a = diff * lbl_805613C0;
    b = *(float *)((char *)rect + 0x10) - *(float *)((char *)rect + 0x04);
    c = *(float *)((char *)rect + 0x0C) - *(float *)((char *)rect + 0x00);
    if (fn_80138BFC(a) == 0) {
        tmp = lbl_805613C4 * a;
        disc = b * b - tmp * c;
        if (disc >= lbl_805613B8) {
            roots[0] = ((-b) + ((float)fn_8002F234(disc))) / (lbl_805613C8 * a);
            roots[1] = ((-b) - ((float)fn_8002F234(disc))) / (lbl_805613C8 * a);
            if (fn_80138BE4(roots[0], roots[1]) != 0) {
                float hi = roots[1];
                float lo = roots[0];
                *out_t = (lo > hi) ? (lo) : (hi);
            } else if (roots[0] >= lbl_805613B8) {
                float hi = roots[1];
                float lo = roots[0];
                *out_t = (lo < hi) ? (lo) : (hi);
            } else {
                *out_t = lbl_805613CC;
            }
            if ((*out_t) >= lbl_805613B8)
                return 1;
        } else if (out_distance != 0) {
            term = ((-b) > lbl_805613B8) ? (-b) : (lbl_805613B8);
            right = (float)__fabs((double)a);
            term = (term + b) * (lbl_805613C8 * right);
            *out_distance = ((term * term) - disc) / (lbl_805613C8 * c);
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
    extern int fn_80138C28(void*, float*, float*);
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
