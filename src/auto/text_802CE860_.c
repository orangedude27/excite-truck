// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int endMeshPass();
extern int beginMeshPass(int);
/* Tail-call beginMeshPass with the index converted to a word byte offset (index * 4); the callee ignores the argument. */
void fn_802CE860(int index) { beginMeshPass(index * 4); }

/* Finish the particle system's dynamic mesh pass: flush the accumulated
 * vertex/index buffers and drop the mesh mode back to idle (endMeshPass). */
void fn_802CE868(void) { endMeshPass(); }

extern void *fn_802C86DC(void);
extern int fn_801E4F3C(int, int, float, float, float, float, float);
extern float lbl_80564F70, lbl_80564F74, lbl_80564F78, lbl_80564F7C;
extern float lbl_802FAC60[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802CE86C(void *arg0, int arg1, float scale, double x0, double y0, double z0)
{
  struct SignTable
  {
    float v[3];
  };
  struct Locals
  {
    volatile float output[3];
    float signs[3];
    volatile float homes[3];
  };
  struct Locals local;
  float coeff0;
  float zero;
  float coeff1;
  float xBase;
  float yBase;
  float zBase;
  float x;
  float y;
  float *a;
  float *b;
  int i;
  a = (float *) fn_802C86DC();
  b = (float *) fn_802C86DC();
  *((struct SignTable *) local.signs) = *((struct SignTable *) lbl_802FAC60);
  coeff0 = lbl_80564F78;
  zero = lbl_80564F70;
  coeff1 = lbl_80564F7C;
  local.homes[0] = x0;
  local.homes[1] = y0;
  local.homes[2] = z0;
  xBase = (float) x0;
  yBase = (float) y0;
  zBase = (float) z0;
  x = local.signs[arg1 & 1];
  y = local.signs[arg1 & 2];
  for (i = 0; i < 4; i++)
  {
    float f4;
    float f5;
    float dx;
    float dy;
    float q;
    float t;
    float u;
    float v;
    float w;
    float xx;
    float yy;
    float zz;
    f4 = (i & 1) ? (lbl_80564F70) : (lbl_80564F74);
    f5 = (i & 2) ? (lbl_80564F70) : (lbl_80564F74);
    dx = (coeff0 * f4) - zero;
    dy = zero + (coeff1 * f5);
    q = scale * (dx * x);
    t = scale * (dy * y);
    u = xBase + (a[0] * q);
    v = yBase + (a[1] * q);
    w = ((double) zBase) + (a[2] * q);
    xx = u + (b[3] * t);
    yy = v + (b[4] * t);
    zz = w + (b[5] * t);
    local.output[0] = xx;
    local.output[1] = yy;
    local.output[2] = zz;
    if (fn_801E4F3C((int) arg0, i >= 2, xx, yy, zz, f4, f5) != 0)
    {
      break;
    }
  }

}
#pragma scheduling on
#pragma pop
