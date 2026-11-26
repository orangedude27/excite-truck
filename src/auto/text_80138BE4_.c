// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* One body's motion along a single axis: where it is, how fast, and how that
 * speed is changing. A MotionPair holds the two of them whose *relative* motion
 * is the quadratic (target.position - self.position)
 *                      + (target.velocity - self.velocity) * t
 *                      + 0.5 * (target.acceleration - self.acceleration) * t * t
 * whose zero crossing solveMotionCrossingTime solves for (the AI uses it for a truck
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
extern const float lbl_805613B8;
void fn_80138F38();
#pragma dont_inline on
/* Return nonzero when a*b is negative, i.e. the two values have opposite signs (opposite_signs in the motion-crossing solver). */
int fn_80138BE4(float a, float b) {
    return (a * b) < ZERO;
}
#pragma dont_inline reset

#pragma dont_inline on
/* Near-zero test for the motion-crossing solver (motion_is_zero): true when
 * |value| is within the small tolerance 10 * lbl_80558DC4[0]. */
int fn_80138BFC(float value) {
    return (float)__fabs((double)value) <= lbl_805613BC * lbl_80558DC4[0];
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
int solveMotionCrossingTime(MotionPair *motion, float *out_time, float *out_distance) {
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
#pragma scheduling on
float fn_80138DF4(void *arg0) {
    const void *carg = arg0;
    float spC;
    float sp8;
    float temp_f1;
    float temp_f1_2;
    float temp_f2;
    float temp_f3;
    float temp_f3_2;
    float var_f31;
    float var_f4;
    int state;
    if (fn_80138BFC(*(const float *)((const char *)carg + 0xC) - *(const float *)carg) == 0) {
        float b = *(const float *)((const char *)carg + 8);
        float a = *(const float *)((const char *)carg + 0x14);
        if (fn_80138BFC(a - b) == 0) {
            if (solveMotionCrossingTime(arg0, &spC, &sp8) != 0) {
                float pos14 = *(const float *)((const char *)carg + 0x14);
                var_f4 = spC;
                temp_f1 = (*(const float *)((const char *)carg + 0x10) + (var_f4 * pos14)) - *(const float *)((const char *)carg + 4);
                var_f4 = (var_f4 > lbl_805613D0) ? var_f4 : lbl_805613D0;
                var_f31 = temp_f1 / var_f4;
                lbl_8055E100 = -5;
            } else {
                var_f31 = sp8;
                lbl_8055E100 = -4;
            }
        } else {
            temp_f2 = *(const float *)((const char *)carg + 0xC) - *(const float *)carg;
            temp_f1_2 = *(const float *)((const char *)carg + 0x10) - *(const float *)((const char *)carg + 4);
            temp_f3 = temp_f1_2 * temp_f1_2;
            var_f31 = temp_f3 / (lbl_805613C8 * temp_f2);
            if (fn_80138BE4(temp_f1_2, temp_f2) != 0) {
                var_f31 = -var_f31;
            }
            temp_f3_2 = *(const float *)((const char *)carg + 0xC);
            temp_f2 = temp_f3_2 - *(const float *)carg;
            temp_f1_2 = *(const float *)((const char *)carg + 0x10) - *(const float *)((const char *)carg + 4);
            {
                int result = fn_80138BE4(temp_f1_2, temp_f2);
                state = -2;
                if (result != 0)
                    state = -3;
            }
            lbl_8055E100 = state;
        }
    } else {
        var_f31 = lbl_805613B8;
        lbl_8055E100 = -1;
    }
    return var_f31;
}
#pragma scheduling invalid_target
void fn_80138F38(const void *arg0)
{
  extern int lbl_8055E100;
  extern float fn_80138DF4(void *);
  float sp8;
  union U
  {
    struct 
    {
      int a;
      int b;
      int c;
      float d;
      float e;
      float f;
    } s;
    double _a;
  } sp10;
  register float x;
  register float y;
  register float ratio;
  register float square;
  register float value;
  register float product;
  if ((*((const float *) (((const char *) arg0) + 0x10))) > 0.0f)
  {
    float temp;
    temp = *((const float *) (((const char *) arg0) + 0x14));
    if (temp < 0.0f)
    {
      if (solveMotionCrossingTime((MotionPair *) arg0, &sp8, 0))
      {
        x = *((const float *) (((const char *) arg0) + 0x10));
        y = *((const float *) (((const char *) arg0) + 0x14));
        ratio = (-x) / y;
        if (ratio <= sp8)
        {
          square = ratio * ratio;
          product = ratio * x;
          value = *((const float *) (((const char *) arg0) + 0xC));
          value += product;
          value += (0.5f * y) * square;
          ((int *) (&sp10))[0] = ((const int *) arg0)[0];
          ((int *) (&sp10))[1] = ((const int *) arg0)[1];
          ((int *) (&sp10))[2] = ((const int *) arg0)[2];
          ((int *) (&sp10))[3] = ((const int *) arg0)[3];
          ((int *) (&sp10))[4] = ((const int *) arg0)[4];
          ((int *) (&sp10))[5] = ((const int *) arg0)[5];
          sp10.s.d = value;
          sp10.s.f = 0.0f;
          sp10.s.e = 0.0f;
          fn_80138DF4(&sp10);
          lbl_8055E100 += 6;
          return;
        }
      }
    }
  }
  fn_80138DF4((void *) arg0);
}
void fn_80139030(MotionPair *motion) {
    /* Seeds the motion status code to -6 so fn_80138F38's success path (+6) yields 0; failures set a negative code. */
#define s_motionState lbl_8055E100
    s_motionState = -6;
#undef s_motionState
    fn_80138F38(motion);
}
