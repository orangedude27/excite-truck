#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void PSVECCrossProduct(void *, void *, void *);
typedef struct { float x, y, z; } FV3;
static inline void fv3_sub(const FV3 *a, const FV3 *b, FV3 *out) {
    float x = a->x - b->x, y = a->y - b->y, z = a->z - b->z;
    out->x = x; out->y = y; out->z = z;
}
extern float PSVECDotProduct(void *, void *);
extern void PSVECNormalize(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern float lbl_805628B8, lbl_805628BC, lbl_805628CC;
extern void fn_8019EECC(void *, void *);
extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);

/* No operation. */
void fn_801BF210(void) {

}

#pragma scheduling invalid_target
void *fn_801BF214(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_8017B0B0(void);
    extern int fn_801C1BA4(int, int, int, void *, int);
    extern int lbl_8055A948;
    extern char lbl_80336A90[];
    extern char lbl_80437D48[];
    extern int lbl_8055E7BC;
    void *p = fn_801284F8(0x278, &lbl_8055A948);
    if (p) {
        register unsigned int index;
        fn_8017B0B0();
        *(char **)p = lbl_80336A90;
        *(int *)((char *)p + 0x1EC) = 0;
        *(int *)((char *)p + 0x1F0) = -1;
        index = lbl_8055E7BC;
        *(void **)(lbl_80437D48 + index * 4) = p;
        lbl_8055E7BC = index + 1;
        *(int *)((char *)p + 0x214) = fn_801C1BA4(4, 6, 2, lbl_80437D48, index + 1);
    }
    return p;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_801BF2A4(int arg0, int arg1, float *arg2, float *arg3, float *arg4, int arg5, int *arg6)
{
  extern void fn_8001BA68(void *);
  extern void fn_80144B54(void *, int);
  extern void fn_80144DAC(float *, float *);
  extern void fn_80144DC8(void *);
  extern int fn_801602B4(int);
  char *new_var;
  extern void fn_8017E388(void *, int, int);
  extern int fn_8017EAFC(int);
  extern int fn_8017EB04(int);
  extern void fn_801C1CBC(int, int, void *, int, void *, int, void *);
  extern void fn_801C256C(int, int, int, int);
  extern void fn_801E9DC4(void);
  extern void GXInitLightAttnA_80144B44(void *, float, float, float);
  extern float fn_801C0178(void);
  extern int fn_801C0170(void *);
  extern int fn_801C0168(void *);
  extern void fn_801C014C(void *, float *);
  extern void fn_801C0124(float *, float *, float);
  extern long fn_801C00F8(void *, long);
  extern long fn_801C00F0(void *);
  extern void fn_801C00B8(void *, float *);
  extern void fn_801BFF64(float *, const float *);
  extern void fn_801BFECC(void *, void *);
  extern void GXInitLightAttnA_801BFEBC(void *, float, float, float);
  extern long fn_801BFEB4(long);
  extern void fn_801BFEB0(void);
  extern void fn_801BFE7C(float *, float *, float *);
  extern void fn_801BFD34(float *, float *, const float *);
  extern void fn_801BFB2C(char *, float *, FV3 *);
  extern void fn_801BF75C(float *, const float *, const float *, int);
  extern int fn_801BF754(int);
  extern float lbl_805628C0;
  extern float lbl_805628C4;
  extern float lbl_805628C8;
  extern float lbl_805628B8;
  extern char lbl_80558DC4[];
  extern long long lbl_802F98D0[];
  extern char lbl_80437D48[];
  extern int lbl_8055E7BC;
  struct 
  {
    float sp8[3];
    float sp14[3];
    float sp20[3];
    float sp2C[3];
    int sp38[6];
    float sp50[12];
    float sp80[3];
    float sp8C[3];
    float sp98[3];
    float spA4[3];
    float spB0[12];
    float spE0[20];
    int sp130[24];
  } frame;
  register void *found;
  int cb;
  if (((float) fabs(arg3[0] - arg4[0])) <= (*((float *) lbl_80558DC4)))
  {
    if (((float) fabs(arg3[1] - arg4[1])) <= (*((float *) lbl_80558DC4)))
    {
      if (((float) fabs(arg3[2] - arg4[2])) <= (*((float *) lbl_80558DC4)))
      {
        return 0;
      }
    }
  }
  found = 0;
  {
    struct SearchCtx { void **ptr; int cnt; } sc;
    int i;
    sc.ptr = (void **) lbl_80437D48;
    sc.cnt = lbl_8055E7BC;
    for (i = 0; i < sc.cnt; i++)
    {
      void *obj = *sc.ptr;
      if ((*((int *) (((char *) obj) + 0x1EC))) == 0)
      {
        found = ((void **) lbl_80437D48)[i];
        break;
      }
      sc.ptr++;
    }

  }
  if (found == 0)
  {
    float f0val;
    float f1val = *((float *) (((char *) ((void **) lbl_80437D48)[0]) + 0x218));
    found = ((void **) lbl_80437D48)[0];
    {
      struct SearchCtx { void **ptr; int cnt; } sc;
      int j;
      sc.ptr = (void **) lbl_80437D48;
      sc.cnt = lbl_8055E7BC;
      for (j = 0; j < sc.cnt; j++)
      {
        void *obj = *sc.ptr;
        f0val = *((float *) (((char *) obj) + 0x218));
        if (f0val <= f1val)
        {
          f1val = f0val;
          found = obj;
        }
        sc.ptr++;
      }

    }
  }
  if (found != 0)
  {
    *((float *) (((char *) found) + 0x218)) = fn_801C0178();
    *((int *) (((char *) found) + 0x1EC)) = arg0;
    *((int *) (((char *) found) + 0x1F0)) = fn_801C0170((void *) arg0);
    *((int *) (((char *) found) + 0x1F4)) = arg1;
    *((int *) (((char *) found) + 0x1F8)) = fn_801C0168((void *) ((long) (*((int *) (((char *) found) + 0x1EC)))));
    fn_801C014C(found, arg2);
    fn_8001BA68(frame.sp8);
    fn_801C0124(frame.sp8, arg2, lbl_805628C0);
    cb = fn_801C00F8(found, 0);
    if (cb != 0)
    {
      if (((unsigned) (((int) fn_801C00F0((void *) cb)) - 0x53500000)) == 0x4852U)
      {
        fn_801C00B8((void *) cb, frame.sp8);
      }
    }
    fn_80144B54(frame.sp50, fn_8017EB04(arg0));
    fn_801BFF64(frame.sp50, frame.sp8);
    fn_801BFECC(found, frame.sp50);
    GXInitLightAttnA_801BFEBC(((char *) found) + 0x118, lbl_805628B8, lbl_805628B8, lbl_805628B8);
    GXInitLightAttnA_801BFEBC(((char *) found) + 0x124, lbl_805628B8, lbl_805628B8, lbl_805628B8);
    fn_801BFEB4((long) found);
    fn_801E9DC4();
    ((void (*)(void *)) fn_801BFEB0)(frame.spE0);
    ((void (*)(void *)) fn_801BFEB0)(&frame.spE0[5]);
    ((void (*)(void *)) fn_801BFEB0)(&frame.spE0[10]);
    ((void (*)(void *)) fn_801BFEB0)(&frame.spE0[15]);
    {
      struct Big
      {
        long long v[12];
      } *dst = (struct Big *) frame.sp130;
      struct Big *src = (struct Big *) lbl_802F98D0;
      *dst = *src;
    }
    fn_8001BA68(frame.sp14);
    fn_8001BA68(frame.sp20);
    fn_801BFE7C(frame.sp14, arg3, arg2);
    fn_801BFE7C(frame.sp20, arg4, arg2);
    *((int *) (((char *) found) + 0x21C)) = 0;
    *((int *) (((char *) found) + 0x220)) = 0;
    *((int *) (((char *) found) + 0x224)) = 1;
    *((int *) (((char *) found) + 0x228)) = 0;
    *((int *) (((char *) found) + 0x22C)) = 2;
    new_var = (char *) found;
    fn_8017E388(new_var + 0x230, 1, 0);
    {
      int c;
      int b;
      int a;
      float cond2;
      float cond1;
      a = 1;
      b = 4;
      cond2 = frame.sp20[1] - frame.sp14[1];
      cond1 = frame.sp20[0] - frame.sp14[0];
      c = 2;
      if (cond2 > cond1)
      {
        b = 1;
        c = 2;
        a = 4;
      }
      {
        float f31v = lbl_805628C8;
        float f30v = lbl_805628C4;
        int idx = 0;
        float *p = frame.spE0;
        do
        {
          float var_f3;
          float var_f2;
          float var_f1;
          if (idx & c)
          {
            var_f3 = frame.sp14[2];
          }
          else
          {
            var_f3 = frame.sp20[2];
          }
          if (idx & b)
          {
            var_f2 = frame.sp14[1];
          }
          else
          {
            var_f2 = frame.sp20[1];
          }
          if (idx & a)
          {
            var_f1 = frame.sp14[0];
          }
          else
          {
            var_f1 = frame.sp20[0];
          }
          GXInitLightAttnA_80144B44(frame.sp2C, var_f1, var_f2, var_f3);
          fn_801BFD34(p, frame.sp2C, frame.sp50);
          p[3] = f30v;
          idx++;
          p[4] = f31v;
          p += 5;
        }
        while (idx < 4);
      }
    }
    fn_8001BA68(frame.sp80);
    fn_8001BA68(frame.sp8C);
    fn_8001BA68(frame.sp98);
    fn_8001BA68(frame.spA4);
    {
      float *srcp = frame.spE0;
      float *dstp = frame.sp80;
      int idx = 0;
      do
      {
        fn_80144DAC(dstp, srcp);
        idx++;
        srcp += 5;
        dstp += 3;
      }
      while (idx < 4);
    }
    fn_80144DC8(frame.spB0);
    fn_801BFB2C(found, frame.spB0, (FV3 *) frame.sp80);
    ((void (*)(float *, float *, float *)) fn_801BF75C)((float *) (((char *) found) + 0x230), frame.sp50, frame.spB0);
    {
      int idx = 0;
      int *dstp = frame.sp38;
      int *srcp = arg6;
      while (idx < arg5)
      {
        dstp[0] = *srcp;
        dstp[1] = fn_801602B4(arg0);
        srcp++;
        idx++;
        dstp[2] = 0;
        dstp += 3;
      }

    }
    fn_801C1CBC(*((int *) (((char *) found) + 0x214)), 4, frame.spE0, 6, frame.sp130, arg5, frame.sp38);
    {
      int r26v = fn_801BF754(arg0);
      int r25v = fn_801602B4(arg0);
      fn_801C256C(*((int *) (((char *) found) + 0x214)), fn_8017EAFC(arg0), r25v + 0x24, r26v);
    }
    return 1;
  }
  return 0;
}
#pragma pop
int fn_801BF754(int object) {
    /* Field-offset helper: return a pointer to the field at +0x124 of the given object. */
    return object + 0x124;
}

/* Dot product of two 3-vectors handed over as six scalars: (ax,ay,az) . (bx,by,bz),
 * summed as (az*bz) + ((ax*bx) + (ay*by)). */
extern float fn_80144514(float, float, float, float, float, float);
#pragma push
#pragma processor 750
/* out = a^-1 composed with b, for two 4x3 column-major rigid transforms: the 3x3
 * rotation in elements 0..8 (stored as its three basis vectors x, y and z) and the
 * translation in 9..11.  The rotation of the result is a^T * b - each element is the
 * dot product of one of a's basis vectors with one of b's - and its translation is
 * a^T * (b.t - a.t), so the result is b seen from a's frame.  a's rotation is copied
 * and transposed in place first, which turns a's columns (the basis vectors) into the
 * rows the nine dot products walk; when the caller passes out == b the products are
 * collected in temporaries before being stored, so writing out cannot disturb the
 * reads of b. */
void fn_801BF75C(float *out, const float *b, const float *a, int unused) {
    /* a's rotation, transposed; the raw bits member keeps the copy a plain 9-float block. */
    union { unsigned int bits[9]; float values[9]; } rotT;
    register float *t = rotT.values;
    float e1, e2, e5;                     /* off-diagonal elements being swapped */
    float m22;                            /* result element (row 2, column 2) */
    float m00, m01, m02, m10, m11, m12, m20, m21; /* the other result elements */
    float dx, dy, dz;                     /* b.t - a.t */
    float az, ay, ax, bx, by, bz, cx, cy, cz; /* a's rotation, by basis vector */
    ((FV3 *)rotT.values)[0] = ((const FV3 *)a)[0];
    ((FV3 *)rotT.values)[1] = ((const FV3 *)a)[1];
    ((FV3 *)rotT.values)[2] = ((const FV3 *)a)[2];
    e1 = t[1];
    e2 = t[2];
    e5 = t[5];
    t[1] = t[3];
    t[3] = e1;
    t[2] = t[6];
    t[6] = e2;
    t[5] = t[7];
    t[7] = e5;
    if (out == b || out == rotT.values) {
        m00 = fn_80144514(t[0], b[0], t[3], b[1], t[6], b[2]);
        m01 = fn_80144514(t[0], b[3], t[3], b[4], t[6], b[5]);
        m02 = fn_80144514(t[0], b[6], t[3], b[7], t[6], b[8]);
        m10 = fn_80144514(t[1], b[0], t[4], b[1], t[7], b[2]);
        m11 = fn_80144514(t[1], b[3], t[4], b[4], t[7], b[5]);
        m12 = fn_80144514(t[1], b[6], t[4], b[7], t[7], b[8]);
        m20 = fn_80144514(t[2], b[0], t[5], b[1], t[8], b[2]);
        m21 = fn_80144514(t[2], b[3], t[5], b[4], t[8], b[5]);
        m22 = fn_80144514(t[2], b[6], t[5], b[7], t[8], b[8]);
        out[0] = m00;
        out[3] = m01;
        out[6] = m02;
        out[1] = m10;
        out[4] = m11;
        out[7] = m12;
        out[2] = m20;
        out[5] = m21;
        out[8] = m22;
    } else {
        out[0] = fn_80144514(t[0], b[0], t[3], b[1], t[6], b[2]);
        out[3] = fn_80144514(t[0], b[3], t[3], b[4], t[6], b[5]);
        out[6] = fn_80144514(t[0], b[6], t[3], b[7], t[6], b[8]);
        out[1] = fn_80144514(t[1], b[0], t[4], b[1], t[7], b[2]);
        out[4] = fn_80144514(t[1], b[3], t[4], b[4], t[7], b[5]);
        out[7] = fn_80144514(t[1], b[6], t[4], b[7], t[7], b[8]);
        out[2] = fn_80144514(t[2], b[0], t[5], b[1], t[8], b[2]);
        out[5] = fn_80144514(t[2], b[3], t[5], b[4], t[8], b[5]);
        out[8] = fn_80144514(t[2], b[6], t[5], b[7], t[8], b[8]);
    }
    dx = b[9] - a[9];
    out[9] = dx;
    dy = b[10] - a[10];
    out[10] = dy;
    dz = b[11] - a[11];
    ax = a[0]; bx = a[3]; cx = a[6];
    ay = a[1]; by = a[4]; cy = a[7];
    az = a[2]; bz = a[5]; cz = a[8];
    az = dz * az + (dx * ax + dy * ay);
    bz = dz * bz + (dx * bx + dy * by);
    cz = dz * cz + (dx * cx + dy * cy);
    out[9] = az; out[10] = bz; out[11] = cz;
}
#pragma pop
void fn_801BFD34(float *, float *, const float *);
/* Builds an orthonormal basis from four indexed points in the point array:
 * origin at index *(int*)(base+0x21C), axes from (idx 0x224-0x220) and
 * (idx 0x22C-0x228). Falls back to identity axes when the cross product is
 * degenerate (dot <= lbl_805628CC), then stores the resulting transform parts
 * via fn_801BFD34/fn_80015B20. */
void fn_801BFB2C(char *base, float *out, FV3 *points) {
    float normal[3], axis1[3], axis0[3];
    float basis[12];
    FV3 *pA, *pB;
    float z, y, x;

    pA = &points[*(int *)(base + 0x21C)];
    x = pA->x; y = pA->y; z = pA->z;
    basis[9] = x; basis[10] = y; basis[11] = z;
    pA = &points[*(int *)(base + 0x220)];
    pB = &points[*(int *)(base + 0x224)];
    x = pB->x - pA->x; y = pB->y - pA->y; z = pB->z - pA->z;
    basis[0] = x; basis[1] = y; basis[2] = z;
    pA = &points[*(int *)(base + 0x228)];
    pB = &points[*(int *)(base + 0x22C)];
    x = pB->x - pA->x; y = pB->y - pA->y; z = pB->z - pA->z;
    basis[3] = x; basis[4] = y; basis[5] = z;
    PSVECCrossProduct(&basis[0], &basis[3], &basis[6]);
    if (PSVECDotProduct(&basis[6], &basis[6]) > lbl_805628CC) {
        float a0, a1, a2, b0, b1, b2;
        a2 = basis[2]; a1 = basis[1]; a0 = basis[0]; b2 = basis[8]; b1 = basis[7]; b0 = basis[6];
        axis0[0] = a0; axis0[1] = a1; axis0[2] = a2;
        normal[0] = b0; normal[1] = b1; normal[2] = b2;
        PSVECCrossProduct(normal, axis0, axis1);
        PSVECNormalize(axis0, axis0);
        PSVECNormalize(axis1, axis1);
        PSVECCrossProduct(axis0, axis1, normal);
        basis[0] = axis0[0]; basis[1] = axis0[1]; basis[2] = axis0[2];
        basis[3] = axis1[0]; basis[4] = axis1[1]; basis[5] = axis1[2];
        basis[6] = normal[0]; basis[7] = normal[1]; basis[8] = normal[2];
    } else {
        float zero = lbl_805628B8, one = lbl_805628BC;
        basis[1] = zero;
        basis[0] = one;
        basis[2] = zero;
        basis[3] = zero;
        basis[4] = one;
        basis[5] = zero;
        basis[6] = zero;
        basis[7] = zero;
        basis[8] = one;
    }
    fn_801BFD34(out + 9, (float *)(base + 0x254), basis);
    fn_80015B20(out, base + 0x230, basis);
}

#pragma dont_inline off
#pragma opt_propagation reset

#pragma scheduling invalid_target
/* Transform a 3D point by a 3x4 matrix (3x3 rotation/scale in elements 0-8, translation in 9-11) into out; handles out == in. */
void fn_801BFD34(float *out, float *in, const float *mtx) {
    if (out == in) {
        float x, y, z;
        float m0, m3, m6, m1, m4, m7, m2, m5, m8;
        m3 = mtx[3];
        m4 = mtx[4];
        m5 = mtx[5];
        m0 = mtx[0];
        m1 = mtx[1];
        m2 = mtx[2];
        m6 = mtx[6];
        m7 = mtx[7];
        m8 = mtx[8];
        x = in[0];
        y = in[1];
        z = in[2];
        out[0] = z * m6 + (x * m0 + y * m3);
        out[1] = z * m7 + (x * m1 + y * m4);
        out[2] = z * m8 + (x * m2 + y * m5);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        float y;
        m10 = mtx[3];
        m00 = mtx[0];
        m20 = mtx[6];
        m11 = mtx[4];
        m01 = mtx[1];
        m21 = mtx[7];
        m12 = mtx[5];
        m02 = mtx[2];
        m22 = mtx[8];
        out[0] = in[2] * m20 + (in[0] * m00 + in[1] * m10);
        y = in[1];
        out[1] = in[2] * m21 + (in[0] * m01 + y * m11);
        y = in[1];
        out[2] = in[2] * m22 + (in[0] * m02 + y * m12);
    }
    {
        float tx = out[0] + mtx[9];
        float ty = out[1] + mtx[10];
        float tz = out[2] + mtx[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
}
#pragma scheduling reset
/* Add two 3D vectors component-wise and store the result in out. */
void fn_801BFE7C(float *out, float *a, float *b) {
    float x = a[0] + b[0];
    float y = a[1] + b[1];
    float z = a[2] + b[2];
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

/* No-op stub. */
void fn_801BFEB0(void) {

}

/* Return the address of the embedded field at offset 0x6C of base. */
long fn_801BFEB4(long base) { return base + 0x6C; }

/* GXInitLightAttnA: store the three cosine-attenuation coefficients (aa, ab, ac) at the head of a GX light object. */
void GXInitLightAttnA_801BFEBC(void *lightObj, float aa, float ab, float ac) {
    ((float *)lightObj)[0] = aa;
    ((float *)lightObj)[1] = ab;
    ((float *)lightObj)[2] = ac;
}

#pragma scheduling on
#pragma scheduling invalid_target
void fn_801BFECC(void *arg0, void *arg1) {
    int a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0;
    a3 = *(volatile int *)((char *)arg1 + 0x0C);
    a4 = *(volatile int *)((char *)arg1 + 0x10);
    a2 = *(volatile int *)((char *)arg1 + 0x08);
    a1 = *(volatile int *)((char *)arg1 + 0x04);
    a0 = *(volatile int *)((char *)arg1 + 0x00);
    a5 = *(volatile int *)((char *)arg1 + 0x14);
    a6 = *(volatile int *)((char *)arg1 + 0x18);
    a7 = *(volatile int *)((char *)arg1 + 0x1C);
    a8 = *(volatile int *)((char *)arg1 + 0x20);
    a9 = *(volatile int *)((char *)arg1 + 0x24);
    a10 = *(volatile int *)((char *)arg1 + 0x28);
    a11 = *(volatile int *)((char *)arg1 + 0x2C);
    *(int *)((char *)arg0 + 0x3C) = a0;
    *(int *)((char *)arg0 + 0x40) = a1;
    *(int *)((char *)arg0 + 0x44) = a2;
    *(int *)((char *)arg0 + 0x48) = a3;
    *(int *)((char *)arg0 + 0x4C) = a4;
    *(int *)((char *)arg0 + 0x50) = a5;
    *(int *)((char *)arg0 + 0x54) = a6;
    *(int *)((char *)arg0 + 0x58) = a7;
    *(int *)((char *)arg0 + 0x5C) = a8;
    *(int *)((char *)arg0 + 0x60) = a9;
    *(int *)((char *)arg0 + 0x64) = a10;
    *(int *)((char *)arg0 + 0x68) = a11;
    ((void (*)(void *, void *, int, int, int, int, int, int))fn_8017A580)(arg0, arg1, a10, a9, a8, a7, a6, a5);
}
static inline void inline_transform_vec(float *out, const float *in, const float *m) {
    if (out == in) {
        float y0 = m[3] * in[1];
        float y1 = m[4] * in[1];
        float y2 = m[5] * in[1];

        float x0 = m[0] * in[0];
        float x1 = m[1] * in[0];
        float x2 = m[2] * in[0];

        float z0 = m[6] * in[2];
        float z1 = m[7] * in[2];
        float z2 = m[8] * in[2];

        out[0] = z0 + (x0 + y0);
        out[1] = z1 + (x1 + y1);
        out[2] = z2 + (x2 + y2);
    } else {
        {
            float m3 = m[3];
            float y0 = in[1] * m3;
            float m0 = m[0];
            float x0 = in[0] * m0;
            float m6 = m[6];
            float z0 = in[2] * m6;
            out[0] = (x0 + y0) + z0;
        }
        {
            float m4 = m[4];
            float y1 = in[1] * m4;
            float m1 = m[1];
            float x1 = in[0] * m1;
            float m7 = m[7];
            float z1 = in[2] * m7;
            out[1] = (x1 + y1) + z1;
        }
        {
            float m5 = m[5];
            float y2 = in[1] * m5;
            float m2 = m[2];
            float x2 = in[0] * m2;
            float m8 = m[8];
            float z2 = in[2] * m8;
            out[2] = (x2 + y2) + z2;
        }
    }
}

#pragma scheduling invalid_target
/* Add a point to a 3x4 transform: rotate `vec` by the matrix's 3x3 orientation
 * (rows [0..2], [3..5], [6..8], read as out[i] = x*m[i] + y*m[3+i] + z*m[6+i])
 * and add the result into its translation column [9..11].  The in-place case
 * (vec pointing at the caller's own scratch, which is what `moved` is here)
 * reads the vector first so the partial results don't overwrite it. */
void fn_801BFF64(float *mtx, const float *vec) {
    float moved[3];
    if (moved == vec) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = mtx[3]; m11 = mtx[4]; m12 = mtx[5];
        m00 = mtx[0]; m01 = mtx[1]; m02 = mtx[2];
        m20 = mtx[6]; m21 = mtx[7]; m22 = mtx[8];
        x = vec[0]; y = vec[1]; z = vec[2];
        moved[0] = z * m20 + (x * m00 + y * m10);
        moved[1] = z * m21 + (x * m01 + y * m11);
        moved[2] = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        m10 = mtx[3]; m00 = mtx[0]; m20 = mtx[6];
        moved[0] = vec[2] * m20 + (vec[0] * m00 + vec[1] * m10);
        m11 = mtx[4]; m01 = mtx[1]; m21 = mtx[7];
        moved[1] = vec[2] * m21 + (vec[0] * m01 + vec[1] * m11);
        m12 = mtx[5]; m02 = mtx[2]; m22 = mtx[8];
        moved[2] = vec[2] * m22 + (vec[0] * m02 + vec[1] * m12);
    }
    mtx[9] += moved[0];
    mtx[10] += moved[1];
    mtx[11] += moved[2];
}
extern void fn_8019EECC(void *, void *);
/* Copy a 3D position into the object's +0x28 field, then add the source object's
   offset vector (source+0x30) to it via fn_8019EECC when a source pointer exists at +4. */
void fn_801C00B8(void *sphere, float *position) {
    struct Sphere { char pad[0x28]; float posX, posY, posZ; };
    struct Sphere *obj = (struct Sphere *)sphere;
    void *offsetSource = *(void **)((char *)sphere + 4);
    float z, y, x;
    x = position[0];
    y = position[1];
    z = position[2];
    obj->posX = x;
    obj->posY = y;
    obj->posZ = z;
    if (offsetSource == 0) return;
    fn_8019EECC(offsetSource, &obj->posX);
}

/* Returns the 4-byte type tag (four-character code) at offset +0x18 of `obj`, which callers compare against tags such as 'SPHR'. */
long fn_801C00F0(void *obj) { return *(long *)((char *)obj + 0x18); }

long fn_801C00F8(void *obj, long index) {
    // Bounds-checked lookup of an entry in the pointer array embedded at +0x14 of obj (its length is at +0x24);
    // returns 0 when index is out of range.
    if (index >= 0 && index < *(long *)((char *)obj + 0x24))
        return *(long *)((char *)obj + index * 4 + 0x14);
    return 0;
}

/* Scale a 3-component vector component-wise: out = src * scale. */
void fn_801C0124(float *out, float *src, float scale) {
    float z, y, x;
    x = src[0];
    y = src[1];
    z = src[2];
    x *= scale;
    y *= scale;
    z *= scale;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);
void fn_801C014C(void *object, float *position) {
    /* Copy a 3-component position into the object at +0x30/+0x34/+0x38 and notify fn_8017A57C. */
    float x = position[0];
    float y = position[1];
    float z = position[2];
    *(float *)((char *)object + 0x30) = x;
    *(float *)((char *)object + 0x34) = y;
    *(float *)((char *)object + 0x38) = z;
    fn_8017A57C(y, x);
}

// Return the 32-bit field stored at offset 0x5A4 of the given scene state object.
int fn_801C0168(void *sceneState) { return *(int *)((char *)sceneState + 0x5A4); }

// Return the 32-bit field stored at offset 0x59C of the given object.
int fn_801C0170(void *object) { return *(int *)((char *)object + 0x59C); }

/* Returns the shared game clock (seconds since start), used to timestamp
   scene-state records such as the one stamped at +0x218 by the caller. */
float fn_801C0178(void) {
    extern float lbl_8055E3C8; /* current game time */
    return lbl_8055E3C8;
}

extern void fn_801C1C7C(void *, int);
extern void fn_80179EE8(void *, int);
extern void fn_80128668(void *);
extern int lbl_8055E7BC;
extern char lbl_80336A90[];
/* Destructor-like cleanup: installs vtable, decrements ref count, tears down subobject at +0x214, runs base dtor, optionally frees. */
void *fn_801C0180(void *self, int deleteFlag) {
    int refCount;
    if (self != 0) {
        *(void **)self = lbl_80336A90;
        refCount = lbl_8055E7BC;
        lbl_8055E7BC = refCount - 1;
        fn_801C1C7C(*(void **)((char *)self + 0x214), refCount);
        if (self != 0) fn_80179EE8(self, 0);
        if (deleteFlag > 0) fn_80128668(self);
    }
    return self;
}

/* Initializes an object (arg0) with setup params from arg1, sets default transform/volume fields, creates a "panelvol" subobject, attaches it, and clears a flag at 0x1E8. */
void fn_801C0204(void *obj, int *param) {
    struct Setup {
        int value;
        int size;
        float first;
        float second;
        float third;
        float fourth;
    };
    struct Frame {
        float stack0;
        float stack1;
        float stack2;
        float stack3;
        float stack4;
        float stack5;
        float stack6;
        float stack7;
        float stack8;
        float stack9;
        volatile struct Setup setup;
    };
    extern void *memset(void *, int, unsigned int);
    extern void fn_8017B0F8(void *, void *);
    extern void *fn_801284F8(int, void *);
    extern void *fn_801A25F8(void *, void *, int, void *, float);
    extern void fn_80179F94(void *, void *);
    extern float lbl_805628B8, lbl_805628D0, lbl_805628D4, lbl_805628D8;
    extern float lbl_805628DC, lbl_805628E0, lbl_805628E4;
    extern char lbl_80336AE4[];
    struct Frame frame;
    void *result;
    memset((void *)&frame.setup, 0, 0x18);
    {
        float next, first;
        int value;
        /* lbl_805628D0 = 45.45, lbl_805628D4 = 4.22799 */
        first = *(volatile float *)&lbl_805628D0;
        frame.setup.size = 0x18;
        next = *(volatile float *)&lbl_805628D4;
        value = *(volatile int *)param;
        frame.setup.value = value;
        frame.setup.first = first;
        frame.setup.second = next;
        frame.setup.third = next;
        frame.setup.fourth = next;
    }
    fn_8017B0F8(obj, (void *)&frame.setup);
    {
        float f3 = lbl_805628B8;
        float f2 = lbl_805628D8;
        float f1 = lbl_805628DC;
        float f0 = lbl_805628E0;
        *(float *)((char *)obj + 0x1FC) = f3;
        *(float *)((char *)obj + 0x200) = f3;
        *(float *)((char *)obj + 0x204) = f2;
        *(float *)((char *)obj + 0x208) = f3;
        *(float *)((char *)obj + 0x20C) = f1;
        *(float *)((char *)obj + 0x210) = f0;
        frame.stack6 = f3;
        frame.stack1 = f3;
        frame.stack5 = f3;
        result = ((void *(*)(int, const char *, float, float, float))fn_801284F8)(
            0x34, lbl_80336AE4, f1, f2, f3);
    }
    if (result != 0) {
        float value = lbl_805628E4;
        int field = *(int *)((char *)obj + 0x214);
        result = fn_801A25F8(result, (char *)obj + 0x3C, field, obj, value);
    }
    fn_80179F94(obj, result);
    *(unsigned char *)((char *)obj + 0x1E8) = 0;
}

static inline void helper_801C02F4(void *self, int flag) {
    if (flag) {
        *(int *)((char *)self + 0x1F0) = 0;
    } else {
        *(int *)((char *)self + 0x1F0) = -1;
    }
}

#pragma opt_propagation reset
void fn_801C02F4(void *arg0) {
    struct Mat43 {
        float m[4][3];
    };
    extern float lbl_805628B8, lbl_805628BC, lbl_805628E8, lbl_805628EC;
    extern void fn_8017B164(void *);
    register void *self = arg0;
    struct Mat43 mat;
    float f = lbl_805628E8;

    *(int *)((char *)arg0 + 0x1EC) = 0;
    *(float *)((char *)arg0 + 0x218) = f;
    if (*(int *)((char *)self + 0x1EC) != 0) {
        *(int *)((char *)arg0 + 0x1F0) = 0;
    } else {
        *(int *)((char *)arg0 + 0x1F0) = -1;
    }
    fn_8017B164(self);

    mat.m[0][0] = lbl_805628BC;
    mat.m[0][1] = lbl_805628B8;
    mat.m[0][2] = lbl_805628B8;
    mat.m[1][0] = lbl_805628B8;
    mat.m[1][1] = lbl_805628BC;
    mat.m[1][2] = lbl_805628B8;
    mat.m[2][0] = lbl_805628B8;
    mat.m[2][1] = lbl_805628B8;
    mat.m[2][2] = lbl_805628BC;
    mat.m[3][0] = lbl_805628B8;
    mat.m[3][2] = lbl_805628B8;
    mat.m[3][1] = lbl_805628EC;

    *(int *)((char *)self + 0x1F4) = -1;
    *(int *)((char *)self + 0x1F8) = 0;
    *(struct Mat43 *)((char *)self + 0x3C) = mat;
    ((void (*)(void *))fn_8017A580)(self);

    {
        float f0, f1, f2;
        f2 = lbl_805628B8;
        f1 = lbl_805628E8;
        f0 = lbl_805628BC;
        *(float *)((char *)self + 0x118) = f2;
        *(float *)((char *)self + 0x11C) = f2;
        *(float *)((char *)self + 0x120) = f2;
        *(float *)((char *)self + 0x124) = f2;
        *(float *)((char *)self + 0x128) = f2;
        *(float *)((char *)self + 0x12C) = f2;
        *(float *)((char *)self + 0x260) = f2;
        *(float *)((char *)self + 0x264) = f1;
        *(float *)((char *)self + 0x268) = f2;
        *(float *)((char *)self + 0x26C) = f2;
        *(float *)((char *)self + 0x270) = f0;
        *(float *)((char *)self + 0x274) = f2;
    }
}
int fn_801C0440(void *sceneLight) {
    // Nonzero if this scene light is in use: +0x1EC holds its owner id (0 when free).
    return *(int *)((char *)sceneLight + 0x1EC) != 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_801C0454(void *arg0) {
    extern void fn_80144DAC(float *, float *);
    extern void fn_80144DC8(void *);
    extern void fn_8017C7C8(void *, void *, void *);
    extern int fn_801E9E78(void *, float *, float *, void *, int);
    extern void fn_801C2694(int, void *, int *, float *, float *, void *, void *);
    extern float fn_80144CC8(float);
    extern void fn_801C092C(void *, void *, void *, int);
    extern void fn_801C0D3C(void *);
    extern void fn_801C0D6C(void *);
    extern float fn_801C0E44(FV3 *v);
    extern void fn_801C0E4C(void *, void *, void *);
    extern void fn_801C0E60(float *, float *, float *);
    extern float lbl_805628C8;
    extern float lbl_805628F0;
    extern float lbl_805628F4;
    extern float lbl_805628F8;
    extern float lbl_805628FC;
    struct Pt { float x, y, z; };
    struct {
        float sp8;
        int spC;
        struct Pt tmpPts[16];
        float spD0[3];
        float spDC[3];
        float spE8[3];
        float spF4[3];
        float sp100[12];
        float sp130[12];
        struct Pt pts[14];
    } frame;
    int i;
    int n;
    float f31;
    if (*(int *)((char *)arg0 + 0x1EC) != 0) {
        if (*(int *)((char *)arg0 + 0x214) != 0) {
            fn_8017C7C8(arg0, frame.spF4, frame.spE8);
            frame.spC = 8;
            *(int *)&frame.spDC[0] = *(int *)((char *)arg0 + 0x60);
            *(int *)&frame.spDC[1] = *(int *)((char *)arg0 + 0x64);
            *(int *)&frame.spDC[2] = *(int *)((char *)arg0 + 0x68);
            if (fn_801E9E78((char *)arg0 + 0x6C, frame.spDC, frame.spD0, &frame.sp8, *(int *)((char *)arg0 + 0x60)) != 0) {
                frame.spDC[0] = frame.spDC[0] + (frame.spD0[0] * lbl_805628C8);
                frame.spDC[1] = frame.spDC[1] + (frame.spD0[1] * lbl_805628C8);
                frame.spDC[2] = frame.spDC[2] + (frame.spD0[2] * lbl_805628C8);
                frame.spD0[0] = frame.spD0[0] * lbl_805628F0;
                frame.spD0[1] = frame.spD0[1] * lbl_805628F0;
                frame.spD0[2] = frame.spD0[2] * lbl_805628F0;
                frame.spD0[0] = frame.spD0[0] + (*(float *)((char *)arg0 + 0x26C) * lbl_805628F4);
                frame.spD0[1] = frame.spD0[1] + (*(float *)((char *)arg0 + 0x270) * lbl_805628F4);
                frame.spD0[2] = frame.spD0[2] + (*(float *)((char *)arg0 + 0x274) * lbl_805628F4);
                PSVECNormalize(frame.spD0, frame.spD0);
                *(float *)((char *)arg0 + 0x260) = frame.spDC[0];
                *(float *)((char *)arg0 + 0x264) = frame.spDC[1];
                *(float *)((char *)arg0 + 0x268) = frame.spDC[2];
                *(float *)((char *)arg0 + 0x26C) = frame.spD0[0];
                *(float *)((char *)arg0 + 0x270) = frame.spD0[1];
                *(float *)((char *)arg0 + 0x274) = frame.spD0[2];
                fn_801C2694(*(int *)((char *)arg0 + 0x214), frame.pts, &frame.spC, frame.spDC, frame.spD0, frame.spF4, frame.spE8);
                n = frame.spC;
                for (i = 0; i < n; i++) {
                    frame.tmpPts[i] = frame.pts[i];
                    frame.tmpPts[i].y += lbl_805628F8;
                }
                fn_80144DC8(&frame.sp100[0]);
                fn_80144DAC(&frame.sp100[9], &frame.pts[*(int *)((char *)arg0 + 0x21C)].x);
                fn_801C0E60(&frame.sp100[0], &frame.pts[*(int *)((char *)arg0 + 0x224)].x, &frame.pts[*(int *)((char *)arg0 + 0x220)].x);
                fn_801C0E60(&frame.sp100[3], &frame.pts[*(int *)((char *)arg0 + 0x22C)].x, &frame.pts[*(int *)((char *)arg0 + 0x228)].x);
                fn_801C0E4C(&frame.sp100[6], &frame.sp100[0], &frame.sp100[3]);
                f31 = fn_80144CC8(lbl_805628FC);
                if (((float (*)(void *))fn_801C0E44)(&frame.sp100[6]) > f31) {
                    fn_801C0D6C(&frame.sp100[0]);
                } else {
                    fn_801C0D3C(&frame.sp100[0]);
                }
                ((void (*)(void *, void *, void *))fn_801C092C)(frame.sp130, (char *)arg0 + 0x230, &frame.sp100[0]);
                {
                    struct Pt *dst = (struct Pt *)((char *)arg0 + 0x3C);
                    struct Pt *src = (struct Pt *)frame.sp130;
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    dst[3] = src[3];
                }
                ((void (*)(void *))fn_8017A580)(arg0);
            }
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma processor 750
void fn_801C092C(void *outMtx, void *inMtx, void *multMtx, int unused) {
    /* Concatenate two 3x4 transforms: out = matrix * input.
     *
     * Every matrix here is twelve floats: the 3x3 part in column-major order
     * (the element of row r, column c at c * 3 + r, so m<col><row> below) and
     * the translation column at [9..11].  The 3x3 part is the plain product
     * row(matrix) . col(input), each element through fn_80144514() (the
     * three-term dot product ax*bx + ay*by + az*bz), and the translation is
     * matrix applied to input's translation plus matrix's own translation.
     *
     * Both halves keep an alias-safe path: when the translation is read from
     * where it is about to be written (out + 9 == input + 9) its three floats
     * are latched first, and when the output is the input or the multiplier all
     * nine products are taken before any of them is stored. */
    float *out = (float *)outMtx;
    float *input = (float *)inMtx;
    float *matrix = (float *)multMtx;
    float r0c0, r0c1, r0c2, r1c0;
    float r1c1, r1c2, r2c0, r2c1;
    float r2c2;
    if (out + 9 == input + 9) {
        /* Same translation column: latch input's translation before writing. */
        float tx, ty, tz;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = matrix[3]; m11 = matrix[4]; m12 = matrix[5];
        m00 = matrix[0]; m01 = matrix[1]; m02 = matrix[2];
        m20 = matrix[6]; m21 = matrix[7]; m22 = matrix[8];
        tx = input[9]; ty = input[10]; tz = input[11];
        out[9] = tz * m20 + (tx * m00 + ty * m10);
        out[10] = tz * m21 + (tx * m01 + ty * m11);
        out[11] = tz * m22 + (tx * m02 + ty * m12);
    } else {
        float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        m10 = matrix[3]; m00 = matrix[0]; m20 = matrix[6];
        out[9] = input[11] * m20 + (input[9] * m00 + input[10] * m10);
        m11 = matrix[4]; m01 = matrix[1]; m21 = matrix[7];
        out[10] = input[11] * m21 + (input[9] * m01 + input[10] * m11);
        m12 = matrix[5]; m02 = matrix[2]; m22 = matrix[8];
        out[11] = input[11] * m22 + (input[9] * m02 + input[10] * m12);
    }
    out[9] += matrix[9];
    out[10] += matrix[10];
    out[11] += matrix[11];
    if (out == input || out == matrix) {
        /* Output aliases one of the operands: take every product first. */
        r0c0 = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        r0c1 = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        r0c2 = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        r1c0 = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        r1c1 = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        r1c2 = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        r2c0 = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        r2c1 = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        r2c2 = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
        out[0] = r0c0;
        out[3] = r0c1;
        out[6] = r0c2;
        out[1] = r1c0;
        out[4] = r1c1;
        out[7] = r1c2;
        out[2] = r2c0;
        out[5] = r2c1;
        out[8] = r2c2;
    } else {
        out[0] = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        out[3] = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        out[6] = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        out[1] = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        out[4] = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        out[7] = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        out[2] = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        out[5] = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        out[8] = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
    }
}
/* Initialize the 3x3 matrix at out to the identity (1.0 on the diagonal, 0.0 elsewhere). */
void fn_801C0D3C(void *out)
{
    float *m = (float *)out;
    float zero = lbl_805628B8;
    float one = lbl_805628BC;
    m[1] = zero;
    m[0] = one;
    m[2] = zero;
    m[3] = zero;
    m[4] = one;
    m[5] = zero;
    m[6] = zero;
    m[7] = zero;
    m[8] = one;
}

#pragma pop
/* Reverse-ordered scalar loads keep the vector copies and final register restore matching. */
void fn_801C0D6C(void *arg0) {
    /* Orthonormalize a 3x3 basis (3 row vectors in a float[9]) using cross products and normalization. */
    extern void PSVECNormalize(void *, void *);
    float vec2[3];
    float cross[3];
    float vec0[3];
    float *matrix = (float *)arg0;
    float x, y, z, a, b, c;
    z = matrix[2];
    y = matrix[1];
    x = matrix[0];
    vec0[0] = x;
    vec0[1] = y;
    vec0[2] = z;
    c = matrix[8];
    b = matrix[7];
    a = matrix[6];
    vec2[0] = a;
    vec2[1] = b;
    vec2[2] = c;
    PSVECCrossProduct(vec2, vec0, cross);
    PSVECNormalize(vec0, vec0);
    PSVECNormalize(cross, cross);
    PSVECCrossProduct(vec0, cross, vec2);
    matrix[0] = vec0[0];
    matrix[1] = vec0[1];
    matrix[2] = vec0[2];
    matrix[3] = cross[0];
    matrix[4] = cross[1];
    matrix[5] = cross[2];
    matrix[6] = vec2[0];
    matrix[7] = vec2[1];
    matrix[8] = vec2[2];
}
#pragma scheduling on
extern float PSVECDotProduct(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_805628B8;
extern float lbl_805628BC;
/* Squared length of a 3D vector: its dot product with itself. Callers test a cross
   product with it to tell a usable basis from a degenerate (near-parallel) one. */
float fn_801C0E44(FV3 *v) { return PSVECDotProduct(v, v); }

/* Compute the cross product of vectors `a` and `b` into `out`. */
void fn_801C0E4C(void *out, void *a, void *b) {
    PSVECCrossProduct(a, b, out);
}

void fn_801C0E60(float *out, float *lhs, float *rhs) {
    /* Subtract two 3D vectors component-wise: out = lhs - rhs. */
    fv3_sub((const FV3 *)lhs, (const FV3 *)rhs, (FV3 *)out);
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_801C0E94(void *arg0, int arg1) {
    extern float lbl_805628BC, lbl_8055E460;
    extern char lbl_80558DC4[];
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float base = lbl_805628BC;
    float top = lbl_8055E460;
    float delta = top - base;
    if ((float)fabs((double)delta) <= *(float *)lbl_80558DC4) {
        unsigned int v0 = *(unsigned int *)(src + 0x70);
        unsigned int v1 = *(unsigned int *)(src + 0x74);
        *(unsigned int *)(dst + 0x00) = v0;
        *(unsigned int *)(dst + 0x04) = v1;
        v0 = *(unsigned int *)(src + 0x78);
        v1 = *(unsigned int *)(src + 0x7C);
        *(unsigned int *)(dst + 0x08) = v0;
        *(unsigned int *)(dst + 0x0C) = v1;
        v0 = *(unsigned int *)(src + 0x80);
        v1 = *(unsigned int *)(src + 0x84);
        *(unsigned int *)(dst + 0x10) = v0;
        *(unsigned int *)(dst + 0x14) = v1;
        v0 = *(unsigned int *)(src + 0x88);
        v1 = *(unsigned int *)(src + 0x8C);
        *(unsigned int *)(dst + 0x18) = v0;
        *(unsigned int *)(dst + 0x1C) = v1;
        *(unsigned int *)(dst + 0x20) = *(unsigned int *)(src + 0x90);
        v0 = *(unsigned int *)(src + 0x94);
        v1 = *(unsigned int *)(src + 0x98);
        *(unsigned int *)(dst + 0x24) = v0;
        *(unsigned int *)(dst + 0x28) = v1;
        *(unsigned int *)(dst + 0x2C) = *(unsigned int *)(src + 0x9C);
    } else {
        struct Blend6 { float v[6]; } tmp[2];
        float *a = (float *)(src + 0x70);
        float *b = (float *)(src + 0xA0);
        int i;
        for (i = 0; i < 2; i++) {
            float a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3], a4 = a[4], a5 = a[5];
            float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3], b4 = b[4], b5 = b[5];
            tmp[i].v[0] = b0 + lbl_8055E460 * (a0 - b0);
            tmp[i].v[1] = b1 + lbl_8055E460 * (a1 - b1);
            tmp[i].v[2] = b2 + lbl_8055E460 * (a2 - b2);
            tmp[i].v[3] = b3 + lbl_8055E460 * (a3 - b3);
            tmp[i].v[4] = b4 + lbl_8055E460 * (a4 - b4);
            tmp[i].v[5] = b5 + lbl_8055E460 * (a5 - b5);
            a += 6;
            b += 6;
        }
        *(unsigned int *)(dst + 0x00) = *(unsigned int *)&tmp[0].v[0];
        *(unsigned int *)(dst + 0x04) = *(unsigned int *)&tmp[0].v[1];
        *(unsigned int *)(dst + 0x08) = *(unsigned int *)&tmp[0].v[2];
        *(unsigned int *)(dst + 0x0C) = *(unsigned int *)&tmp[0].v[3];
        *(unsigned int *)(dst + 0x10) = *(unsigned int *)&tmp[0].v[4];
        *(unsigned int *)(dst + 0x14) = *(unsigned int *)&tmp[0].v[5];
        *(unsigned int *)(dst + 0x18) = *(unsigned int *)&tmp[1].v[0];
        *(unsigned int *)(dst + 0x1C) = *(unsigned int *)&tmp[1].v[1];
        *(unsigned int *)(dst + 0x20) = *(unsigned int *)&tmp[1].v[2];
        *(unsigned int *)(dst + 0x24) = *(unsigned int *)&tmp[1].v[3];
        *(unsigned int *)(dst + 0x28) = *(unsigned int *)&tmp[1].v[4];
        *(unsigned int *)(dst + 0x2C) = *(unsigned int *)&tmp[1].v[5];
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
    dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    *(unsigned int *)(dst + 0x34) = *(unsigned int *)(src + 0x1F0);
    *(unsigned int *)(dst + 0x38) = *(unsigned int *)(src + 0x1F4);
    *(unsigned int *)(dst + 0x3C) = *(unsigned int *)(src + 0x1F8);
}
#pragma pop
