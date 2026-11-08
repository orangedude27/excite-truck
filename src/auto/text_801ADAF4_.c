// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_801284F8(s32, void *);
extern void fn_80128668(void *);
extern void *lbl_8055E604;
extern char lbl_8033596C[];
extern void *lbl_8055A8B8;
extern const f32 lbl_80562520;
extern const f32 lbl_8056254C;
extern const f32 lbl_80562550;

extern s32 fn_801E9EC4(void *, void *, void *, s32 *);
extern f32 PSVECDotProduct(const f32 *, const f32 *);
extern f32 PSVECMag(const f32 *);
extern void PSVECNormalize(const f32 *, f32 *);
extern void fn_8017B6D4(void *, f32 *, f32 *);
extern f32 fn_8019DF88(void *, f32 *, void *, f32 *, f32 *, f32, f32);
extern void fn_8017B5D4(void *, s32, s32, f32 *, f32 *, s32, s32, s32, f32);
extern void fn_802E30C8(void *, s32, ...);
extern char lbl_80335950[];
extern s32 lbl_8055E3C4;
extern const f32 lbl_80558DC4[];
extern const f32 lbl_80562524, lbl_80562528, lbl_8056252C, lbl_80562530, lbl_80562534, lbl_80562538, lbl_8056253C, lbl_80562540, lbl_80562544, lbl_80562548;
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

typedef struct {
    s32 unk_0x0;
    f32 v[3];
    f32 unk_0x10, unk_0x14, unk_0x18;
    f32 acc[3];
} Ent801ADB44;

typedef struct Obj801ADB44 {
    void **vtbl;
    u8 pad4[0xC];
    s32 id;
    s32 unk_0x14;
    u8 pad18[0xC];
    s32 unk_0x24;
    u8 pad28[0x38];
    f32 org[3];
    u8 unk_0x6C[0x68];
    f32 unk_0xD4;
    u8 padD8[0x70];
    u8 unk_0x148[1];
} Obj801ADB44;

static inline void xf(f32 *out, f32 *in, u8 *m) {
    if (out == in) {
        f32 y = in[1], x = in[0], z = in[2];
        f32 o0 = z * F(m, 0x54) + (x * F(m, 0x3C) + y * F(m, 0x48));
        f32 o1 = z * F(m, 0x58) + (x * F(m, 0x40) + y * F(m, 0x4C));
        f32 o2 = z * F(m, 0x5C) + (x * F(m, 0x44) + y * F(m, 0x50));
        out[0] = o0;
        out[1] = o1;
        out[2] = o2;
    } else {
        out[0] = in[2] * F(m, 0x54) + (in[0] * F(m, 0x3C) + in[1] * F(m, 0x48));
        out[1] = in[2] * F(m, 0x58) + (in[0] * F(m, 0x40) + in[1] * F(m, 0x4C));
        out[2] = in[2] * F(m, 0x5C) + (in[0] * F(m, 0x44) + in[1] * F(m, 0x50));
    }
}

extern void fn_801AD888(void **);
void fn_801ADAF4(void *arg0) {
    fn_801AD888((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD8C8(void **);
void fn_801ADAFC(void *arg0) {
    fn_801AD8C8((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD99C(void **);
void fn_801ADB04(void *arg0) {
    fn_801AD99C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA38(void **);
void fn_801ADB0C(void *arg0) {
    fn_801ADA38((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA7C(void **);
void fn_801ADB14(void *arg0) {
    fn_801ADA7C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA84(void **);
void fn_801ADB1C(void *arg0) {
    fn_801ADA84((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA8C(void **);
void fn_801ADB24(void *arg0) {
    fn_801ADA8C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA94(void **);
void fn_801ADB2C(void *arg0) {
    fn_801ADA94((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA9C(void **);
void fn_801ADB34(void *arg0) {
    fn_801ADA9C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADAB8(void **);
void fn_801ADB3C(void *arg0) {
    fn_801ADAB8((void **)((u8 *)arg0 - 0x23C));
}

#pragma push
#pragma processor 750
void fn_801ADB44(Ent801ADB44 *a, Obj801ADB44 *b) {
    struct { s32 flag; f32 r[3], e[3], v[3], w[3], t[3], d[3], pos[3], n[3], hit[3]; } s;
    s32 found;
    f32 dist, dot, k, m, lim, q;
    if (a->v[2] * F(b, 0x58) + (a->v[0] * F(b, 0x40) + a->v[1] * F(b, 0x4C)) > lbl_80562520) {
        return;
    }
    xf(s.pos, a->v, (u8 *)b);
    s.pos[0] += b->org[0];
    s.pos[1] += b->org[1];
    s.pos[2] += b->org[2];
    dist = lbl_80562520;
    s.flag = 0;
    found = fn_801E9EC4(b->unk_0x6C, s.hit, s.n, &s.flag);
    if (found) {
        s.d[0] = s.hit[0] - s.pos[0];
        s.d[1] = s.hit[1] - s.pos[1];
        s.d[2] = s.hit[2] - s.pos[2];
        dist = PSVECDotProduct(s.d, s.n);
    }
    if (!found || dist > lbl_80562524) {
        s.n[0] = s.pos[0] - b->org[0];
        s.n[1] = s.pos[1] - b->org[1];
        s.n[2] = s.pos[2] - b->org[2];
        PSVECNormalize(s.n, s.n);
        s.n[0] *= lbl_80562528;
        s.n[1] *= lbl_80562528;
        s.n[2] *= lbl_80562528;
        dist = lbl_8056252C;
    }
    if (dist > lbl_80562520) {
        fn_8017B6D4(b, s.t, s.pos);
        dot = PSVECDotProduct(s.t, s.n);
        s.w[0] = s.t[0] + s.n[0] * -dot;
        s.w[1] = s.t[1] + s.n[1] * -dot;
        s.w[2] = s.t[2] + s.n[2] * -dot;
        a->acc[0] = a->acc[0] + s.w[0] * lbl_80562530;
        a->acc[1] = a->acc[1] + s.w[1] * lbl_80562530;
        a->acc[2] = a->acc[2] + s.w[2] * lbl_80562530;
        m = PSVECMag(a->acc);
        if (m > lbl_80562534) {
            k = lbl_80562534 / m;
            a->acc[0] *= k;
            a->acc[1] *= k;
            a->acc[2] *= k;
        }
        if ((f32)__fabs(a->unk_0x18) <= lbl_80558DC4[0]) {
            f32 sg = (dot < lbl_80562520) ? lbl_80562538 : lbl_8056252C;
            m = sg * (dist * a->unk_0x10);
        } else {
            q = dist * a->unk_0x10 - dot * a->unk_0x18;
            m = lbl_80562520;
            m = (m > q) ? m : q;
        }
        s.v[0] = s.n[0] * m;
        s.v[1] = s.n[1] * m;
        s.v[2] = s.n[2] * m;
        s.e[0] = s.w[0] * (lbl_8056253C * b->unk_0xD4);
        s.e[1] = s.w[1] * (lbl_8056253C * b->unk_0xD4);
        s.e[2] = s.w[2] * (lbl_8056253C * b->unk_0xD4);
        k = lbl_80562540 * b->unk_0xD4;
        s.e[0] += a->acc[0] * k;
        s.e[1] += a->acc[1] * k;
        s.e[2] += a->acc[2] * k;
        k = PSVECMag(s.e);
        lim = m * a->unk_0x14;
        lim = (lim > lbl_80562544) ? lim : lbl_80562544;
        if (k > lim) {
            k = lim / k;
            s.e[0] *= k;
            s.e[1] *= k;
            s.e[2] *= k;
        }
        s.v[0] += s.e[0];
        s.v[1] += s.e[1];
        s.v[2] += s.e[2];
        ((void (*)(void *, f32 *, f32 *, s32, s32))b->vtbl[0x48 / 4])(b, s.v, s.pos, s.flag, 0);
        k = fn_8019DF88(b->org, s.t, b->unk_0x148, s.pos, s.n, b->unk_0xD4, lbl_80562520);
        if (k > lbl_80562520) {
            s.r[0] = s.n[0] * k;
            s.r[1] = s.n[1] * k;
            s.r[2] = s.n[2] * k;
            fn_8017B5D4(b, b->unk_0x24 > 0 ? b->unk_0x14 : 0, 0, s.r, s.pos, s.flag, 0, 0,
                        (lbl_80562548 > dist) ? lbl_80562548 : dist);
            if (b->id == 0x50434152) {
                fn_802E30C8(lbl_80335950, lbl_8055E3C4, s.pos[0], s.pos[1], s.pos[2]);
            }
        }
    } else {
        a->acc[0] = lbl_80562520;
        a->acc[1] = lbl_80562520;
        a->acc[2] = lbl_80562520;
    }
}
#pragma pop
void fn_801AE158(void *arg0) {
    struct { f32 field1; f32 field2; f32 field3; } locals;
    locals.field1 = lbl_80562520;
    locals.field2 = lbl_80562520;
    locals.field3 = lbl_80562520;
    *(f32 *)((u8 *)arg0 + 0x1C) = locals.field1;
    *(f32 *)((u8 *)arg0 + 0x20) = locals.field2;
    *(f32 *)((u8 *)arg0 + 0x24) = locals.field3;
}

#pragma scheduling invalid_target
void *fn_801AE180(void) {
     s32 var_r8;
     s32 var_r5_2;
     s32 var_r5;
     s32 var_r4;
     s32 temp_r9;
     s32 temp_r8_2;
     s32 temp_r3;
     s32 temp_r12;
     s32 var_ctr_2;
     s32 var_ctr;
     u32 temp_r11;
     void **temp_r31;
     u8 *var_r6;
     u8 *temp_r5_2;
     u8 *temp_r8;
     u8 *temp_r7;
     u8 *temp_r5_3;
     u8 *temp_r5;
     u8 *temp_r3_3;
     u8 *temp_r3_2;

      temp_r31 = lbl_8055E604;
      temp_r3_2 = (*(void **)((u8 *)(temp_r31) + (0)));
      if (!temp_r3_2 || ((s32) (*(s32 *)((u8 *)(temp_r3_2) + (4))) == 0x40)) {
          temp_r3_3 = (u8 *)fn_801284F8(0xA08, (void *)(*(s32 *)((u8 *)(temp_r31) + (4))));
          if (temp_r3_3 != NULL) {
              var_r6 = temp_r3_3 + 0x30;
              temp_r5_2 = temp_r3_3 + 0xA08;
              (*(f32 *)((u8 *)(temp_r3_3) + (0xC))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x10))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x14))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x18))) = (f32) lbl_8056254C;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x1C))) = (f32) lbl_80562550;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x20))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x24))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x28))) = (f32) lbl_80562520;
              (*(f32 *)((u8 *)(temp_r3_3) + (0x2C))) = (f32) lbl_80562520;
              (*(s32 *)((u8 *)(temp_r3_3) + (8))) = 0;
              if ((temp_r3_3 + 0x30) < (temp_r3_3 + 0xA08)) {
                  temp_r8 = temp_r5_2 - 0x9D8;
                  temp_r9 = temp_r5_2 - temp_r8;
                  temp_r11 = (temp_r9 + 0x27) / 40;
                  temp_r12 = temp_r11 + 1;
                  temp_r7 = temp_r3_3 + 0x8C8;
                  if (temp_r12 > 8) {
                      var_r4 = 0;
                      var_r5 = 0;
                      if (temp_r8 <= temp_r5_2) {
                          var_r8 = 1;
                          if (!(temp_r9 & 0x80000000) && ((temp_r9 + 0x27) & 0x80000000)) {
                              var_r8 = 0;
                          }
                          if (var_r8 != 0) {
                              var_r5 = 1;
                          }
                      }
                      if (var_r5 != 0) {
                          temp_r8_2 = temp_r11 & 0x80000000;
                          var_r5_2 = 1;
                          if ((temp_r8_2 == 0) && (temp_r8_2 != (s32) (temp_r12 & 0x80000000))) {
                              var_r5_2 = 0;
                          }
                          if (var_r5_2 != 0) {
                              var_r4 = 1;
                          }
                      }
                      if (var_r4 != 0) {
                          var_ctr = (u32) ((temp_r7 + 0x13F) - var_r6) / 320U;
                          if (var_r6 < temp_r7) {
                              do {
                                  (*(f32 *)((u8 *)(var_r6) + (4))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (8))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xC))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x10))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x14))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x18))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x1C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x20))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x24))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0x2C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x30))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x34))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x38))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x3C))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x40))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x44))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x48))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x4C))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0x28))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0x54))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x58))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x5C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x60))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x64))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x68))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x6C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x70))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x74))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0x50))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0x7C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x80))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x84))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x88))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x8C))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x90))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x94))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x98))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x9C))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0x78))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0xA4))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xA8))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xAC))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xB0))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0xB4))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0xB8))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xBC))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xC0))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xC4))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0xA0))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0xCC))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xD0))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xD4))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xD8))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0xDC))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0xE0))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xE4))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xE8))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xEC))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0xC8))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0xF4))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xF8))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0xFC))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x100))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x104))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x108))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x10C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x110))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x114))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0xF0))) = 0;
                                  (*(f32 *)((u8 *)(var_r6) + (0x11C))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x120))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x124))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x128))) = (f32) lbl_8056254C;
                                  (*(f32 *)((u8 *)(var_r6) + (0x12C))) = (f32) lbl_80562550;
                                  (*(f32 *)((u8 *)(var_r6) + (0x130))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x134))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x138))) = (f32) lbl_80562520;
                                  (*(f32 *)((u8 *)(var_r6) + (0x13C))) = (f32) lbl_80562520;
                                  (*(s32 *)((u8 *)(var_r6) + (0x118))) = 0;
                                  var_r6 += 0x140;
                                  var_ctr -= 1;
                              } while (var_ctr != 0);
                          }
                      }
                  }
                  temp_r5_3 = temp_r3_3 + 0xA08;
                  var_ctr_2 = (u32) ((temp_r5_3 + 0x27) - var_r6) / 40U;
                  if (var_r6 < temp_r5_3) {
                      do {
                          (*(f32 *)((u8 *)(var_r6) + (4))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (8))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (0xC))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (0x10))) = (f32) lbl_8056254C;
                          (*(f32 *)((u8 *)(var_r6) + (0x14))) = (f32) lbl_80562550;
                          (*(f32 *)((u8 *)(var_r6) + (0x18))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (0x1C))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (0x20))) = (f32) lbl_80562520;
                          (*(f32 *)((u8 *)(var_r6) + (0x24))) = (f32) lbl_80562520;
                          (*(s32 *)((u8 *)(var_r6) + (0))) = 0;
                          var_r6 += 0x28;
                          var_ctr_2 -= 1;
                      } while (var_ctr_2 != 0);
                  }
              }
              (*(s32 *)((u8 *)(temp_r3_3) + (4))) = 0;
              (*(void **)((u8 *)(temp_r3_3) + (0))) = ((void *)0);
          }
          (*(void **)((u8 *)(temp_r3_3) + (0))) = (void *) (*(void **)((u8 *)(temp_r31) + (0)));
          (*(void **)((u8 *)(temp_r31) + (0))) = temp_r3_3;
      }
      temp_r5 = (*(void **)((u8 *)(temp_r31) + (0)));
      temp_r3 = (*(s32 *)((u8 *)(temp_r5) + (4)));
      (*(s32 *)((u8 *)(temp_r5) + (4))) = (s32) (temp_r3 + 1);
      return temp_r5 + (temp_r3 * 0x28) + 8;
  }
#pragma scheduling on
void fn_801AE4C4(void) {
    void *result = (void *)fn_801284F8(8, &lbl_8033596C);
    if (result != NULL) {
        *(s32 *)result = 0;
        *(void **)((u8 *)result + 4) = &lbl_8055A8B8;
        lbl_8055E604 = result;
    }
}

void fn_801AE50C(void) {
    void *ptr = lbl_8055E604;
    if (ptr != NULL) {
        void *r31;
        do {
            r31 = *(void **)ptr;
            fn_80128668(ptr);
            *(void **)ptr = r31;
            ptr = r31;
        } while (ptr != NULL);
        lbl_8055E604 = NULL;
    }
}

