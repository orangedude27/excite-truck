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
void fn_801ADB44(void *a, void *b) {
    f32 flagpad;
    s32 flag;
    f32 r[3], e[3], v[3], w[3], t[3], d[3], pos[3], n[3], hit[3];
    s32 found;
    f32 dist, dot, k, m, lim;
    if (F(a, 0xC) * F(b, 0x58) + (F(a, 4) * F(b, 0x40) + F(a, 8) * F(b, 0x4C)) > lbl_80562520) {
        return;
    }
    xf(pos, (f32 *)((u8 *)a + 4), b);
    pos[0] += F(b, 0x60);
    pos[1] += F(b, 0x64);
    pos[2] += F(b, 0x68);
    dist = lbl_80562520;
    flag = 0;
    found = fn_801E9EC4((u8 *)b + 0x6C, hit, n, &flag);
    if (found) {
        d[0] = hit[0] - pos[0];
        d[1] = hit[1] - pos[1];
        d[2] = hit[2] - pos[2];
        dist = PSVECDotProduct(d, n);
    }
    if (!found || dist > lbl_80562524) {
        n[0] = pos[0] - F(b, 0x60);
        n[1] = pos[1] - F(b, 0x64);
        n[2] = pos[2] - F(b, 0x68);
        PSVECNormalize(n, n);
        n[0] *= lbl_80562528;
        n[1] *= lbl_80562528;
        n[2] *= lbl_80562528;
        dist = lbl_8056252C;
    }
    if (dist > lbl_80562520) {
        fn_8017B6D4(b, t, pos);
        dot = PSVECDotProduct(t, n);
        w[0] = t[0] + n[0] * -dot;
        w[1] = t[1] + n[1] * -dot;
        w[2] = t[2] + n[2] * -dot;
        F(a, 0x1C) = F(a, 0x1C) + w[0] * lbl_80562530;
        F(a, 0x20) = F(a, 0x20) + w[1] * lbl_80562530;
        F(a, 0x24) = F(a, 0x24) + w[2] * lbl_80562530;
        m = PSVECMag((f32 *)((u8 *)a + 0x1C));
        if (m > lbl_80562534) {
            k = lbl_80562534 / m;
            F(a, 0x1C) *= k;
            F(a, 0x20) *= k;
            F(a, 0x24) *= k;
        }
        if (__fabs(F(a, 0x18)) <= *(const f32 *)&lbl_80558DC4) {
            f32 s = (dot < lbl_80562520) ? lbl_80562538 : lbl_8056252C;
            m = dist * F(a, 0x10) * s;
        } else {
            f32 q = dist * F(a, 0x10) - dot * F(a, 0x18);
            m = lbl_80562520;
            if (!(m > q)) m = q;
        }
        v[0] = n[0] * m;
        v[1] = n[1] * m;
        v[2] = n[2] * m;
        e[0] = w[0] * (lbl_8056253C * F(b, 0xD4));
        e[1] = w[1] * (lbl_8056253C * F(b, 0xD4));
        e[2] = w[2] * (lbl_8056253C * F(b, 0xD4));
        k = lbl_80562540 * F(b, 0xD4);
        e[0] += F(a, 0x1C) * k;
        e[1] += F(a, 0x20) * k;
        e[2] += F(a, 0x24) * k;
        k = PSVECMag(e);
        lim = m * F(a, 0x14);
        if (!(lim > lbl_80562544)) lim = lbl_80562544;
        if (k > lim) {
            k = lim / k;
            e[0] *= k;
            e[1] *= k;
            e[2] *= k;
        }
        v[0] += e[0];
        v[1] += e[1];
        v[2] += e[2];
        (*(void (**)(void *, f32 *, f32 *, s32, s32))(*(u8 **)b + 0x48))(b, v, pos, flag, 0);
        k = fn_8019DF88((u8 *)b + 0x60, t, (u8 *)b + 0x148, pos, n, F(b, 0xD4), lbl_80562520);
        if (k > lbl_80562520) {
            r[0] = n[0] * k;
            r[1] = n[1] * k;
            r[2] = n[2] * k;
            fn_8017B5D4(b, *(s32 *)((u8 *)b + 0x24) > 0 ? *(s32 *)((u8 *)b + 0x14) : 0, 0, r, pos, flag, 0, 0,
                        lbl_80562548 > dist ? dist : lbl_80562548);
            if (*(s32 *)((u8 *)b + 0x10) == 0x50434152) {
                fn_802E30C8(lbl_80335950, lbl_8055E3C4, pos[0], pos[1], pos[2]);
            }
        }
    } else {
        F(a, 0x1C) = lbl_80562520;
        F(a, 0x20) = lbl_80562520;
        F(a, 0x24) = lbl_80562520;
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

