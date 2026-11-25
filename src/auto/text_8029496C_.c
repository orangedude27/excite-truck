// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2C_FIELD(expr, type, offset) (*(type)((unsigned char *)(expr) + (offset)))

typedef struct { float x, y, z; } Vec80295;

#include <math.h>
extern float PSVECDotProduct(const Vec80295 *, const Vec80295 *);
extern void PSVECNormalize(const Vec80295 *, Vec80295 *);
extern float fn_801E88F0(int);
extern void *fn_80287B24(int);
extern void fn_80294CCC(const Vec80295 *, const Vec80295 *, const Vec80295 *, unsigned int, int, float, float);
extern const unsigned short lbl_802FA9B0[];
extern void fn_802C8DB8(void *, int, void *, int);
extern void *DrawList_getCurrentMatrix(void);
extern float DrawList_squaredDistanceToCamera(void *);
extern void fn_802C8BD0(int);
extern void DrawList_RestoreNormalMode(void);
extern char lbl_804B42F0[];
extern float lbl_80564518, lbl_8056452C, lbl_80564538, lbl_8056453C, lbl_80564540;
extern char lbl_80349338[];
extern char lbl_8055C998[8], lbl_8055C9A0[4], lbl_8055C9A4[8], lbl_8055C9AC[4];
extern float lbl_8056451C, lbl_80564520, lbl_80564544;
extern int fn_80288070(int, int, int *);
extern int fn_80287E20(int, int);
extern void *fn_80287E80(int, int);
int fn_80287B14(void);
int fn_802CAC54(int);
extern int lbl_8055C990;
extern int lbl_8055C994;
#pragma scheduling off
/* Trivial constructor registered for the RotationAxis object pool (see
 * text_80294918_.c): the pooled type needs no initialization, so this does
 * nothing. */
void fn_8029496C(void) {

}

#pragma push
#pragma processor 750
void fn_80294970(void) {
    extern char lbl_803492D0[];
    extern char lbl_804B42F0[];
    extern int lbl_8055C990;
    extern int lbl_8055C994;
    extern float lbl_80564518, lbl_8056451C, lbl_80564520, lbl_80564524, lbl_80564528;
    extern int fn_80287B14(void);
    extern int fn_80288208(int);
    extern int fn_802CAC28(void *, int);
    extern void *fn_801E1F44(void);
    extern void fn_801345D8(char *, int, const char *, int);
    extern void fn_80295CC4(void *self, int a, int b, Vec80295 *input, int unused, float *pos, float size);

    int i, j;
    char *obj;
    char *base = lbl_803492D0;

    obj = lbl_804B42F0;
    for (i = 0; i < fn_80287B14(); i++) {
        *(int *)(obj + 0x180) = 0;
        obj += 0x184;
    }

    lbl_8055C990 = fn_802CAC28(base, 0);
    lbl_8055C994 = fn_802CAC28(base + 0xC, 0);

    if (*(char *)((char *)fn_801E1F44() + 4) != 0 || *(int *)fn_801E1F44() == 1) {
        float f1_val = lbl_80564518;
        float f0_val = lbl_8056451C;
        float f2_val = lbl_80564520;
        char *truck = lbl_804B42F0;

        for (i = 0; i < fn_80287B14(); i++) {
            Vec80295 c_head, p_head;
            Vec80295 c_tail, p_tail;
            Vec80295 c_acc, p_acc;
            int truck_id;
            char name[64];

            c_head.x = f1_val; c_head.y = f1_val; c_head.z = f1_val;
            p_head.x = f0_val; p_head.y = f0_val; p_head.z = f1_val;

            c_tail.x = f1_val; c_tail.y = f0_val; c_tail.z = f0_val;
            p_tail.x = f0_val; p_tail.y = f0_val; p_tail.z = f2_val;

            c_acc.x = f1_val; c_acc.y = f1_val; c_acc.z = f1_val;
            p_acc.x = f0_val; p_acc.y = f0_val; p_acc.z = f1_val;

            truck_id = fn_80288208(i);

            fn_80295CC4(truck, truck_id, (int)(base + 0x18), &c_head, 0, (float *)&p_head, lbl_80564524);
            fn_80295CC4(truck, truck_id, (int)(base + 0x28), &c_head, 0, (float *)&p_head, lbl_80564524);
            fn_80295CC4(truck, truck_id, (int)(base + 0x38), &c_tail, 0, (float *)&p_tail, lbl_80564528);
            fn_80295CC4(truck, truck_id, (int)(base + 0x48), &c_tail, 0, (float *)&p_tail, lbl_80564528);

            for (j = 0; j < 8; j++) {
                fn_801345D8(name, 0x40, base + 0x58, j + 1);
                fn_80295CC4(truck, truck_id, (int)name, &c_acc, 0, (float *)&p_acc, lbl_80564528);
            }

            truck += 0x184;
        }
    }
}
#pragma pop

#pragma scheduling invalid_target
/* Releases the two cached truck effect handles and resets them; iterates truck slots. */
void fn_80294C68(void) {
    int truckIndex;
    fn_802CAC54(lbl_8055C990);
    fn_802CAC54(lbl_8055C994);
    lbl_8055C990 = -1;
    truckIndex = 0;
    lbl_8055C994 = -1;
    while (truckIndex < fn_80287B14()) {
        truckIndex++;
    }
}
#pragma scheduling on
/* No-op subsystem-init hook called from the startup sequence (fn_80287914);
 * the truck-effects setup it stands in for actually runs in fn_80294970. */
void fn_80294CC0(void) {

}

/* No-op subsystem-init hook called from the secondary startup sequence
 * (fn_8028797C). */
void fn_80294CC4(void) {

}

void fn_80294ED4(void);
/* Per-mode update thunk: always runs the truck-effects update pass in
 * fn_80294ED4, regardless of the mode its caller (fn_80287A6C) selects. */
void fn_80294CC8(void) { fn_80294ED4(); }

#pragma push
#pragma processor 750
void fn_80294CCC(const Vec80295 *arg0, const Vec80295 *arg1, const Vec80295 *arg2, unsigned int arg3, int arg4, float farg0, float farg1)
{
  unsigned short sp8[6];
  float sp18[4][6];
  float t30;
  float t4;
  float t3;
  float t11;
  float t10;
  float t7;
  float t27;
  float t28;
  float t4_2;
  float t5;
  float t6;
  float t13;
  float t12;
  float t11_2;
  float t29;
  float f0;
  float t2;
  float t7_2;
  float s31;
  float t5_2;
  float t0_2;
  float t8;
  float u0;
  float t9;
  float __repair_u0_1;
  float u1;
  float v0;
  float v1;
  float s00;
  float s01;
  float s02;
  float s10;
  float s11;
  float s12;
  float s20;
  float s21;
  float s22;
  float t3_2;
  float s30;
  float s32;
  t30 = -farg0;
  t4 = arg1->x;
  if (1)
  {
    t3 = arg1->y; t11 = arg1->z;
    t10 = (*arg0).x; t9 = arg0->y; t4_2 = arg0->z;
    t27 = t10 + (t4 * t30); t28 = t9 + (t3 * t30); t3_2 = t4_2 + (t11 * t30);
    t7 = arg2->x; t5 = arg2->y; t6 = arg2->z;
    t13 = t10 + (t4 * farg0); t12 = t9 + (t3 * farg0); t11_2 = t4_2 + (t11 * farg0);
  }
  t29 = t7 * farg1; f0 = -farg1; t8 = t5 * farg1; t2 = t6 * farg1;
  t7_2 = t7 * f0; t5_2 = t5 * f0; t0_2 = t6 * f0;
  s00 = t27 + t29; s01 = t8 + t28; s02 = t2 + t3_2;
  s10 = t13 + t29; s11 = t12 + t8; s12 = t11_2 + t2;
  s20 = t27 + t7_2; s21 = t5_2 + t28; s22 = t3_2 + t0_2;
  s30 = t13 + t7_2; s31 = t12 + t5_2; s32 = t0_2 + t11_2;
  sp8[0] = lbl_802FA9B0[0]; sp8[1] = lbl_802FA9B0[1]; sp8[2] = lbl_802FA9B0[2];
  sp8[3] = lbl_802FA9B0[3]; sp8[4] = lbl_802FA9B0[4]; sp8[5] = lbl_802FA9B0[5];
  sp18[0][0] = s00; sp18[0][1] = s01; sp18[0][2] = s02;
  sp18[1][0] = s10; sp18[1][1] = s11; sp18[1][2] = s12;
  sp18[2][0] = s20; sp18[2][1] = s21; sp18[2][2] = s22;
  sp18[3][0] = s30; sp18[3][1] = s31; sp18[3][2] = s32;
  *((unsigned int *) (&sp18[3][3])) = arg3;
  *((unsigned int *) (&sp18[2][3])) = arg3;
  *((unsigned int *) (&sp18[1][3])) = arg3 & 0xFFFF;
  *((unsigned int *) (&sp18[0][3])) = arg3;
  if (((arg4 - 1) + 1) >= ((0 - 1) + 1))
  {
    u0 = ((float) (arg4 % 2)) * lbl_8056452C;
    u1 = lbl_8056452C + u0;
    v0 = (float) (arg4 / 2);
    v1 = lbl_80564518 + v0;
    sp18[2][4] = u0;
    sp18[0][4] = u0;
    sp18[3][4] = u1;
    sp18[1][4] = u1;
    sp18[1][5] = v0;
    sp18[0][5] = v0;
    sp18[3][5] = v1;
    sp18[2][5] = v1;
  }
  else
  {
    __repair_u0_1 = lbl_8056451C; u1 = lbl_80564518; v0 = lbl_8056451C; v1 = lbl_80564518;
    sp18[2][4] = __repair_u0_1;
    sp18[0][4] = __repair_u0_1;
    sp18[3][4] = u1;
    sp18[1][4] = u1;
    sp18[1][5] = v0;
    sp18[0][5] = v0;
    sp18[3][5] = v1;
    sp18[2][5] = v1;
  }
  fn_802C8DB8(sp18, 4, sp8, 6);
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80294ED4(void)
{
  Vec80295 sp8;
  Vec80295 sp14;
  Vec80295 sp20;
  Vec80295 sp2C;
  Vec80295 sp38;
  Vec80295 sp44;
  Vec80295 sp50;
  Vec80295 sp5C;
  Vec80295 sp68;
  Vec80295 sp74;
  Vec80295 sp80;
  Vec80295 sp8C;
  Vec80295 sp98;
  Vec80295 spA4;
  Vec80295 spB0;
  Vec80295 spBC;
  Vec80295 spC8;
  Vec80295 spD4;
  Vec80295 *ptr_sp74;
  Vec80295 *ptr_sp14;
  Vec80295 *ptr_sp68;
  Vec80295 *ptr_sp20;
  Vec80295 *ptr_sp80;
  Vec80295 *ptr_sp2C;
  Vec80295 *ptr_sp8C;
  Vec80295 *ptr_sp38;
  Vec80295 *ptr_sp98;
  Vec80295 *ptr_spA4;
  Vec80295 *ptr_spBC;
  int spF0;
  unsigned char *var_r14;
  unsigned char *var_r17;
  unsigned char *var_r18;
  unsigned char *var_r21;
  float temp_f31;
  float temp_f30;
  float temp_f29;
  float temp_f28;
  float temp_f27;
  float temp_f26;
  float temp_f25;
  float temp_f31_2;
  float temp_f30_2;
  float temp_f29_2;
  float temp_f28_2;
  float temp_f26_3;
  float temp_f0;
  float temp_f0_2;
  float temp_f0_3;
  float temp_f0_4;
  float temp_f0_5;
  float temp_f1;
  float temp_f1_2;
  float temp_f1_3;
  float temp_f1_4;
  float temp_f1_5;
  float temp_f26_2;
  float temp_f2;
  float temp_f2_2;
  float temp_f2_3;
  float temp_f2_4;
  float temp_f3;
  float temp_f3_2;
  float temp_f3_3;
  float temp_f3_4;
  float temp_f3_5;
  float temp_f4;
  float temp_f4_2;
  float temp_f5;
  float temp_f5_2;
  float temp_f6;
  float temp_f6_2;
  float temp_f6_3;
  float temp_f6_4;
  float temp_f7;
  float temp_f7_2;
  float temp_f7_3;
  float temp_f7_4;
  float var_f1;
  float var_f1_2;
  int temp_r0;
  int temp_r0_2;
  int temp_r3_4;
  int temp_r3_5;
  int var_r15;
  int var_r15_2;
  int var_r17_2;
  int var_r27;
  int var_r4;
  unsigned char temp_r0_3;
  unsigned char temp_r5;
  unsigned char temp_r7;
  void *temp_r16;
  void *temp_r16_2;
  void *temp_r3;
  void *temp_r3_2;
  void *temp_r3_3;
  void *temp_r3_6;
  void *temp_r3_7;
  temp_f27 = lbl_80564538;
  temp_r3 = DrawList_getCurrentMatrix();
  spD4 = *((Vec80295 *) temp_r3);
  spC8 = *((Vec80295 *) (((unsigned char *) temp_r3) + 0xC));
  fn_802C8BD0(lbl_8055C990);
  temp_f29 = lbl_80564518;
  temp_f30 = lbl_8056451C;
  temp_f31 = lbl_80564540;
  var_r18 = (unsigned char *) lbl_804B42F0;
  temp_f25 = lbl_8056452C;
  temp_f28 = lbl_8056453C;
  ptr_sp74 = &sp74;
  ptr_sp14 = &sp14;
  ptr_sp68 = &sp68;
  ptr_sp20 = &sp20;
  ptr_sp80 = &sp80;
  ptr_sp2C = &sp2C;
  ptr_sp8C = &sp8C;
  ptr_sp38 = &sp38;
  ptr_sp98 = &sp98;
  ptr_spA4 = &spA4;
  ptr_spBC = &spBC;
  spF0 = 0;
  do
  {
    temp_r16 = fn_80287B24(spF0);
    temp_f26 = fn_801E88F0(-1);
    if ((!((DrawList_squaredDistanceToCamera(((unsigned char *) temp_r16) + 0x24) * temp_f26) > temp_f27)) && (!((*((int *) (((char *) temp_r16) + 0x68))) & 8)))
    {
      var_r15 = 0;
      if (((int) (*((int *) (((char *) var_r18) + 0x180)))) > 0)
      {
        var_r17 = var_r18;
        do
        {
          temp_r3_2 = *((void **) (((char *) var_r17) + 0));
          temp_r3_3 = ((unsigned char *) temp_r3_2) + 0x24;
          if (ptr_spBC == temp_r3_3)
          {
            temp_f6 = *((float *) (((char *) temp_r3_3) + 4));
            temp_f0 = *((float *) (((char *) temp_r3_2) + 0x24));
            temp_f7 = *((float *) (((char *) temp_r3_3) + 8));
            spBC.x = (temp_f7 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f0 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f6 * (*((float *) (((char *) temp_r16) + 0xC)))));
            spBC.y = (temp_f7 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f0 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f6 * (*((float *) (((char *) temp_r16) + 0x10)))));
            spBC.z = (temp_f7 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f0 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f6 * (*((float *) (((char *) temp_r16) + 0x14)))));
          }
          else
          {
            spBC.x = ((*((float *) (((char *) temp_r3_3) + 8))) * (*((float *) (((char *) temp_r16) + 0x18)))) + (((*((float *) (((char *) temp_r3_2) + 0x24))) * (*((float *) (((char *) temp_r16) + 0)))) + ((*((float *) (((char *) temp_r3_3) + 4))) * (*((float *) (((char *) temp_r16) + 0xC)))));
            spBC.y = ((*((float *) (((char *) temp_r3_3) + 8))) * (*((float *) (((char *) temp_r16) + 0x1C)))) + (((*((float *) (((char *) temp_r3_2) + 0x24))) * (*((float *) (((char *) temp_r16) + 4)))) + ((*((float *) (((char *) temp_r3_3) + 4))) * (*((float *) (((char *) temp_r16) + 0x10)))));
            spBC.z = ((*((float *) (((char *) temp_r3_3) + 8))) * (*((float *) (((char *) temp_r16) + 0x20)))) + (((*((float *) (((char *) temp_r3_2) + 0x24))) * (*((float *) (((char *) temp_r16) + 8)))) + ((*((float *) (((char *) temp_r3_3) + 4))) * (*((float *) (((char *) temp_r16) + 0x14)))));
          }
          temp_f3 = spBC.x + (*((float *) (((char *) temp_r16) + 0x24)));
          spBC.x = temp_f3;
          temp_f2 = spBC.y + (*((float *) (((char *) temp_r16) + 0x28)));
          spBC.y = temp_f2;
          temp_f1 = spBC.z + (*((float *) (((char *) temp_r16) + 0x2C)));
          spBC.z = temp_f1;
          spB0.x = temp_f3 - (*((float *) (((char *) temp_r3) + 0x24)));
          spB0.y = temp_f2 - (*((float *) (((char *) temp_r3) + 0x28)));
          spB0.z = temp_f1 - (*((float *) (((char *) temp_r3) + 0x2C)));
          if (PSVECDotProduct(&spB0, &spB0) > temp_f28)
          {
            PSVECNormalize(&spB0, &spB0);
            if (ptr_spA4 == ((void *) (var_r17 + 4)))
            {
              temp_f6_2 = *((float *) (((char *) var_r17) + 8));
              temp_f0_2 = *((float *) (((char *) var_r17) + 4));
              temp_f7_2 = *((float *) (((char *) var_r17) + 0xC));
              spA4.x = (temp_f7_2 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f0_2 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f6_2 * (*((float *) (((char *) temp_r16) + 0xC)))));
              spA4.y = (temp_f7_2 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f0_2 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f6_2 * (*((float *) (((char *) temp_r16) + 0x10)))));
              spA4.z = (temp_f7_2 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f0_2 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f6_2 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              temp_f4 = *((float *) (((char *) var_r17) + 8));
              temp_f3_2 = *((float *) (((char *) var_r17) + 4));
              temp_f5 = *((float *) (((char *) var_r17) + 0xC));
              spA4.x = (temp_f5 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f3_2 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f4 * (*((float *) (((char *) temp_r16) + 0xC)))));
              spA4.y = (temp_f5 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f3_2 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f4 * (*((float *) (((char *) temp_r16) + 0x10)))));
              spA4.z = (temp_f5 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f3_2 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f4 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            var_f1 = PSVECDotProduct(&spB0, ptr_spA4);
            if (temp_f29 < var_f1)
            {
              var_f1 = temp_f29;
            }
            if (var_f1 > temp_f30)
            {
            }
            else
            {
              var_f1 = temp_f30;
            }
            temp_f26_2 = temp_f29 - var_f1;
            sp38.x = temp_f30;
            sp38.y = temp_f30;
            sp38.z = temp_f29;
            if (ptr_sp98 == ptr_sp38)
            {
              sp98.x = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp98.y = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp98.z = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              sp98.x = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp98.y = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp98.z = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            sp2C.x = temp_f29;
            sp2C.y = temp_f30;
            sp2C.z = temp_f30;
            if (ptr_sp8C == ptr_sp2C)
            {
              sp8C.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp8C.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp8C.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              sp8C.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp8C.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp8C.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            var_r27 = 0xFF;
            temp_r3_4 = (int) (temp_f31 * ((float) fabs(PSVECDotProduct(&spB0, ptr_sp98))));
            temp_r0 = temp_r3_4 & (((int) ((-temp_r3_4) & (~temp_r3_4))) >> 0x1F);
            if (temp_r0 < 0xFF)
            {
              var_r27 = temp_r0;
            }
            var_r4 = 0xFF;
            temp_r3_5 = (int) (temp_f31 * ((float) fabs(PSVECDotProduct(&spB0, ptr_sp8C))));
            temp_r0_2 = temp_r3_5 & (((int) ((-temp_r3_5) & (~temp_r3_5))) >> 0x1F);
            if (temp_r0_2 < 0xFF)
            {
              var_r4 = temp_r0_2;
            }
            temp_r5 = *((unsigned char *) (((char *) var_r17) + 0x18));
            temp_r0_3 = *((unsigned char *) (((char *) var_r17) + 0x19));
            temp_r7 = *((unsigned char *) (((char *) var_r17) + 0x1A));
            sp20.x = temp_f29;
            sp20.y = temp_f30;
            sp20.z = temp_f30;
            if (ptr_sp20 == ptr_sp80)
            {
              sp80.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp80.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp80.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              sp80.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp80.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp80.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f29 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            sp14.x = temp_f30;
            sp14.y = temp_f30;
            sp14.z = temp_f29;
            if (ptr_sp68 == ptr_sp14)
            {
              sp68.x = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp68.y = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp68.z = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              sp68.x = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp68.y = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp68.z = (temp_f29 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f30 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            sp8.x = temp_f30;
            sp8.y = temp_f29;
            sp8.z = temp_f30;
            if (ptr_sp74 == (&sp8))
            {
              sp74.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp74.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp74.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            else
            {
              sp74.x = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x18)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 0)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0xC)))));
              sp74.y = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x1C)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 4)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0x10)))));
              sp74.z = (temp_f30 * (*((float *) (((char *) temp_r16) + 0x20)))) + ((temp_f30 * (*((float *) (((char *) temp_r16) + 8)))) + (temp_f29 * (*((float *) (((char *) temp_r16) + 0x14)))));
            }
            temp_f1_2 = *((float *) (((char *) var_r17) + 0x14));
            temp_f2_2 = temp_f26_2 * temp_f1_2;
            fn_80294CCC(ptr_spBC, ptr_sp80, ptr_sp74, ((temp_r7 | (((temp_r5 << 0x10) & (~0xFF00)) | ((temp_r0_3 << 8) & 0xFF00))) & (~0xFF000000)) | (var_r27 << 0x18), *((int *) (((char *) var_r17) + 0x1C)), (temp_f1_2 + temp_f2_2) * temp_f25, ((*((float *) (((char *) var_r17) + 0x10))) + temp_f2_2) * temp_f25);
            temp_f1_3 = *((float *) (((char *) var_r17) + 0x14));
            temp_f2_3 = temp_f26_2 * temp_f1_3;
            fn_80294CCC(ptr_spBC, ptr_sp68, ptr_sp74, ((temp_r7 | (((temp_r0_3 << 8) & (~0xFF0000)) | ((temp_r5 << 0x10) & 0xFF0000))) & (~0xFF000000)) | (var_r4 << 0x18), *((int *) (((char *) var_r17) + 0x1C)), (temp_f1_3 + temp_f2_3) * temp_f25, ((*((float *) (((char *) var_r17) + 0x10))) + temp_f2_3) * temp_f25);
          }
          var_r17 += 0x20;
          var_r15 += 1;
        }
        while (var_r15 < ((int) (*((int *) (((char *) var_r18) + 0x180)))));
      }
    }
    var_r18 += 0x184;
    spF0 += 1;
  }
  while (spF0 < fn_80287B14());
  DrawList_RestoreNormalMode();
  fn_802C8BD0(lbl_8055C994);
  temp_f29_2 = lbl_80564518;
  temp_f28_2 = lbl_8056451C;
  var_r14 = (unsigned char *) lbl_804B42F0;
  temp_f26_3 = lbl_8056452C;
  temp_f31_2 = lbl_8056453C;
  var_r15_2 = 0;
  do
  {
    temp_r16_2 = fn_80287B24(var_r15_2);
    temp_f30_2 = fn_801E88F0(-1);
    if ((!((DrawList_squaredDistanceToCamera(((unsigned char *) temp_r16_2) + 0x24) * temp_f30_2) > temp_f27)) && (!((*((int *) (((char *) temp_r16_2) + 0x68))) & 8)))
    {
      var_r17_2 = 0;
      if (((int) (*((int *) (((char *) var_r14) + 0x180)))) > 0)
      {
        var_r21 = var_r14;
        do
        {
          temp_r3_6 = *((void **) (((char *) var_r21) + 0));
          temp_r3_7 = ((unsigned char *) temp_r3_6) + 0x24;
          if ((&sp5C.x) == temp_r3_7)
          {
            temp_f6_3 = *((float *) (((char *) temp_r3_7) + 4));
            temp_f0_3 = *((float *) (((char *) temp_r3_6) + 0x24));
            temp_f7_3 = *((float *) (((char *) temp_r3_7) + 8));
            sp5C.x = (temp_f7_3 * (*((float *) (((char *) temp_r16_2) + 0x18)))) + ((temp_f0_3 * (*((float *) (((char *) temp_r16_2) + 0)))) + (temp_f6_3 * (*((float *) (((char *) temp_r16_2) + 0xC)))));
            sp5C.y = (temp_f7_3 * (*((float *) (((char *) temp_r16_2) + 0x1C)))) + ((temp_f0_3 * (*((float *) (((char *) temp_r16_2) + 4)))) + (temp_f6_3 * (*((float *) (((char *) temp_r16_2) + 0x10)))));
            sp5C.z = (temp_f7_3 * (*((float *) (((char *) temp_r16_2) + 0x20)))) + ((temp_f0_3 * (*((float *) (((char *) temp_r16_2) + 8)))) + (temp_f6_3 * (*((float *) (((char *) temp_r16_2) + 0x14)))));
          }
          else
          {
            sp5C.x = ((*((float *) (((char *) temp_r3_7) + 8))) * (*((float *) (((char *) temp_r16_2) + 0x18)))) + (((*((float *) (((char *) temp_r3_6) + 0x24))) * (*((float *) (((char *) temp_r16_2) + 0)))) + ((*((float *) (((char *) temp_r3_7) + 4))) * (*((float *) (((char *) temp_r16_2) + 0xC)))));
            sp5C.y = ((*((float *) (((char *) temp_r3_7) + 8))) * (*((float *) (((char *) temp_r16_2) + 0x1C)))) + (((*((float *) (((char *) temp_r3_6) + 0x24))) * (*((float *) (((char *) temp_r16_2) + 4)))) + ((*((float *) (((char *) temp_r3_7) + 4))) * (*((float *) (((char *) temp_r16_2) + 0x10)))));
            sp5C.z = ((*((float *) (((char *) temp_r3_7) + 8))) * (*((float *) (((char *) temp_r16_2) + 0x20)))) + (((*((float *) (((char *) temp_r3_6) + 0x24))) * (*((float *) (((char *) temp_r16_2) + 8)))) + ((*((float *) (((char *) temp_r3_7) + 4))) * (*((float *) (((char *) temp_r16_2) + 0x14)))));
          }
          temp_f3_3 = sp5C.x + (*((float *) (((char *) temp_r16_2) + 0x24)));
          sp5C.x = temp_f3_3;
          temp_f2_4 = sp5C.y + (*((float *) (((char *) temp_r16_2) + 0x28)));
          sp5C.y = temp_f2_4;
          temp_f1_4 = sp5C.z + (*((float *) (((char *) temp_r16_2) + 0x2C)));
          sp5C.z = temp_f1_4;
          sp50.x = temp_f3_3 - (*((float *) (((char *) temp_r3) + 0x24)));
          sp50.y = temp_f2_4 - (*((float *) (((char *) temp_r3) + 0x28)));
          sp50.z = temp_f1_4 - (*((float *) (((char *) temp_r3) + 0x2C)));
          if (PSVECDotProduct(&sp50, &sp50) > temp_f31_2)
          {
            PSVECNormalize(&sp50, &sp50);
            if ((&sp44.x) == ((void *) (var_r21 + 4)))
            {
              temp_f6_4 = *((float *) (((char *) var_r21) + 8));
              temp_f0_4 = *((float *) (((char *) var_r21) + 4));
              temp_f7_4 = *((float *) (((char *) var_r21) + 0xC));
              sp44.x = (temp_f7_4 * (*((float *) (((char *) temp_r16_2) + 0x18)))) + ((temp_f0_4 * (*((float *) (((char *) temp_r16_2) + 0)))) + (temp_f6_4 * (*((float *) (((char *) temp_r16_2) + 0xC)))));
              sp44.y = (temp_f7_4 * (*((float *) (((char *) temp_r16_2) + 0x1C)))) + ((temp_f0_4 * (*((float *) (((char *) temp_r16_2) + 4)))) + (temp_f6_4 * (*((float *) (((char *) temp_r16_2) + 0x10)))));
              sp44.z = (temp_f7_4 * (*((float *) (((char *) temp_r16_2) + 0x20)))) + ((temp_f0_4 * (*((float *) (((char *) temp_r16_2) + 8)))) + (temp_f6_4 * (*((float *) (((char *) temp_r16_2) + 0x14)))));
            }
            else
            {
              temp_f4_2 = *((float *) (((char *) var_r21) + 8));
              temp_f3_4 = *((float *) (((char *) var_r21) + 4));
              temp_f5_2 = *((float *) (((char *) var_r21) + 0xC));
              sp44.x = (temp_f5_2 * (*((float *) (((char *) temp_r16_2) + 0x18)))) + ((temp_f3_4 * (*((float *) (((char *) temp_r16_2) + 0)))) + (temp_f4_2 * (*((float *) (((char *) temp_r16_2) + 0xC)))));
              sp44.y = (temp_f5_2 * (*((float *) (((char *) temp_r16_2) + 0x1C)))) + ((temp_f3_4 * (*((float *) (((char *) temp_r16_2) + 4)))) + (temp_f4_2 * (*((float *) (((char *) temp_r16_2) + 0x10)))));
              sp44.z = (temp_f5_2 * (*((float *) (((char *) temp_r16_2) + 0x20)))) + ((temp_f3_4 * (*((float *) (((char *) temp_r16_2) + 8)))) + (temp_f4_2 * (*((float *) (((char *) temp_r16_2) + 0x14)))));
            }
            var_f1_2 = PSVECDotProduct(&sp50, &sp44);
            if (temp_f29_2 < var_f1_2)
            {
              var_f1_2 = temp_f29_2;
            }
            if (var_f1_2 > temp_f28_2)
            {
            }
            else
            {
              var_f1_2 = temp_f28_2;
            }
            temp_f0_5 = temp_f29_2 - var_f1_2;
            temp_f3_5 = *((float *) (((char *) var_r21) + 0x14));
            temp_f1_5 = *((float *) (((char *) var_r21) + 0x10));
            fn_80294CCC(&sp5C, &spD4, &spC8, (*((unsigned char *) (((char *) var_r21) + 0x1A))) | (((((*((unsigned char *) (((char *) var_r21) + 0x18))) << 0x10) | 0x80000000) & (~0xFF00)) | (((*((unsigned char *) (((char *) var_r21) + 0x19))) << 8) & 0xFF00)), -1, (temp_f3_5 + (temp_f0_5 * temp_f3_5)) * temp_f26_3, (temp_f1_5 + (temp_f0_5 * temp_f1_5)) * temp_f26_3);
          }
          var_r21 += 0x20;
          var_r17_2 += 1;
        }
        while (var_r17_2 < ((int) (*((int *) (((char *) var_r14) + 0x180)))));
      }
    }
    var_r14 += 0x184;
    var_r15_2 += 1;
  }
  while (var_r15_2 < fn_80287B14());
  DrawList_RestoreNormalMode();
}
#pragma push
#pragma processor gekko
#pragma optimization_level 4
#pragma scheduling invalid_target
/* AddTruckLight: appends one light to a truck's light queue -- the 0x184-byte
 * per-truck block of lbl_804B42F0, twelve entries followed by their count at
 * +0x180.  fn_80295CC4 fills the fields in from the light's "color", "width",
 * "height" and "light_type" properties (the lights are looked up by name:
 * "left headlight", "right taillight", "acc light %d", ...), and fn_80294ED4
 * walks the queue to draw each one as a billboard in the lights.tex/glowz.tex
 * page.  The colour arrives packed as RGBA and is split into its bytes. */
void fn_80295C70(void *arg0, int light, const float *pos, unsigned int rgba, int lightType, float width, float height) {
    /* One queued light: the light object, the point it hangs at on the truck,
       its height and width, its colour and type. */
    struct Light { void *object; float x, y, z; float height, width; unsigned char rgb[3]; int type; };
    /* A truck's lights and how many of the twelve slots are in use. */
    struct LightQueue { struct Light lights[12]; int count; };
    struct LightQueue *queue = (struct LightQueue *)arg0;
    float z, y, x;
    unsigned char red = rgba >> 16;
    unsigned char green = rgba >> 8;
    struct Light *entry;
    entry = &queue->lights[queue->count];
    entry->object = (void *)light;
    x = pos[0];
    y = pos[1];
    z = pos[2];
    entry->x = x;
    entry->y = y;
    entry->z = z;
    entry->height = height;
    entry->width = width;
    entry->rgb[0] = red;
    entry->rgb[1] = green;
    entry->rgb[2] = rgba;
    entry->type = lightType;
    queue->count++;
}
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_80295CC4(void *self, int a, int b, const Vec80295 *input, int unused, float *pos, float size) {
    class Props {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int getInt(char *name, int def);
        virtual void v7();
        virtual float getFloat(char *name, float def);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual Vec80295 getVec(char *name, Vec80295 def);
    };
    Vec80295 col = { input->x, input->y, input->z };
    int id;
    unsigned int packed;
    int extra;
    float base, sx, sy;
    Props *obj;
    if (fn_80288070(a,b,&id)) {
        if (fn_80287E20(a,b)) {
            Vec80295 result;
            unsigned char r,g,bl;
            int t;
            obj = (Props *)fn_80287E80(a,b);
            result = obj->getVec(lbl_8055C998,col);
            t=(int)(lbl_80564544*result.z); t=t>0?t:0; bl=(t<255?t:255);
            t=(int)(lbl_80564544*result.y); t=t>0?t:0; g=(t<255?t:255);
            t=(int)(lbl_80564544*result.x); t=t>0?t:0; r=(t<255?t:255);
            packed=bl | ((g << 8) | (0xFF000000U | (r << 16)));
            base = obj->getFloat(lbl_8055C9A0,size);
            sx = obj->getFloat(lbl_8055C9A4,lbl_80564520);
            sy = obj->getFloat(lbl_8055C9AC,lbl_80564520);
            if (sx <= lbl_8056451C || sy <= lbl_8056451C) { sy=base; sx=base; }
            extra = obj->getInt(lbl_80349338,0);
        } else {
            unsigned char r,g,bl;
            int t;
            t=(int)(lbl_80564544*col.z); t=t>0?t:0; bl=(t<255?t:255);
            t=(int)(lbl_80564544*col.y); t=t>0?t:0; g=(t<255?t:255);
            t=(int)(lbl_80564544*col.x)>0?(int)((unsigned)lbl_80564544*col.x):0;
            r=(t<255?t:255);
            packed=bl | ((g << 8) | (0xFF000000U | (r << 16)));
            sx=size; sy=size; extra=0;
        }
        fn_80295C70(self,id,pos,packed,extra,sx,sy);
    }
}
#pragma pop

#pragma scheduling on
