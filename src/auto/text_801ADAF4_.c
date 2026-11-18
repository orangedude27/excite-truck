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
/* Calls fn_801AD888 on the owning object, recovered from an embedded sub-object pointer by subtracting 0x23C;
 * fn_801AD888 invokes the virtual d2() method and clears the owner's active flag (+0x220). */
void fn_801ADAF4(void *subObject) {
    fn_801AD888((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801AD8C8(void **);
/* Calls fn_801AD8C8 on the owning object, recovered from an embedded sub-object pointer by subtracting 0x23C. */
void fn_801ADAFC(void *subObject) {
    fn_801AD8C8((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801AD99C(void **);
/* Calls fn_801AD99C on the owning object, recovered from an embedded sub-object pointer by subtracting 0x23C. */
void fn_801ADB04(void *subObject) {
    fn_801AD99C((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA38(void **);
/* Forwards to fn_801ADA38 with the owning object, recovered from a sub-object pointer by subtracting 0x23C (default-event dispatch / clear active flag). */
void fn_801ADB0C(void *subObject) {
    fn_801ADA38((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA7C(void **);
/* Forwards to fn_801ADA7C, which reads the owning object's active flag (+0x220); the owner is recovered from a sub-object pointer by subtracting 0x23C. */
void fn_801ADB14(void *subObject) {
    fn_801ADA7C((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA84(void **);
/* Forwards to fn_801ADA84, which reads the owning object's short field at +0x6C; the owner is recovered from a sub-object pointer by subtracting 0x23C. */
void fn_801ADB1C(void *subObject) {
    fn_801ADA84((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA8C(void **);
/* Forwards to fn_801ADA8C, which returns the owning object's sub-field at +0x118; the owner is recovered from a sub-object pointer by subtracting 0x23C. */
void fn_801ADB24(void *subObject) {
    fn_801ADA8C((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA94(void **);
/* Returns a pointer to the owning object's position/origin vector at +0x60; the owner is recovered from an embedded sub-object pointer by subtracting 0x23C. */
void fn_801ADB2C(void *subObject) {
    fn_801ADA94((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADA9C(void **);
/* Forwards to fn_801ADA9C, which notifies the interface object held at +0x240; the owner is recovered from a sub-object pointer by subtracting 0x23C. */
void fn_801ADB34(void *subObject) {
    fn_801ADA9C((void **)((u8 *)subObject - 0x23C));
}

extern void fn_801ADAB8(void **);
/* Forwards to fn_801ADAB8, which reads the owning object's interface pointer at +0x240; the owner is recovered from a sub-object pointer by subtracting 0x23C. */
void fn_801ADB3C(void *subObject) {
    fn_801ADAB8((void **)((u8 *)subObject - 0x23C));
}

#pragma push
#pragma processor 750
void fn_801ADB44(Ent801ADB44 *a, Obj801ADB44 *b) {
    struct { s32 flag; f32 r[3], e[3], v[3], w[3], t[3], d[3], pos[3], n[3], hit[3]; } s;
    s32 found;
    f32 dist, dot, k, m, lim, q, pen;
    f32 *av = a->v;
    if (a->v[1] * F(b, 0x4C) + a->v[0] * F(b, 0x40) + a->v[2] * F(b, 0x58) > lbl_80562520) {
        return;
    }
    xf(s.pos, av, (u8 *)b);
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
            pen = lbl_80562548;
            pen = (pen > dist) ? pen : dist;
            fn_8017B5D4(b, b->unk_0x24 > 0 ? b->unk_0x14 : 0, 0, s.r, s.pos, s.flag, 0, 0, pen);
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
/* Zero the 3-component acceleration (acc) vector at +0x1C..+0x24 of an entity. */
void fn_801AE158(void *obj) {
    struct { f32 x; f32 y; f32 z; } zeroVec;
    zeroVec.x = lbl_80562520;
    zeroVec.y = lbl_80562520;
    zeroVec.z = lbl_80562520;
    *(f32 *)((u8 *)obj + 0x1C) = zeroVec.x;
    *(f32 *)((u8 *)obj + 0x20) = zeroVec.y;
    *(f32 *)((u8 *)obj + 0x24) = zeroVec.z;
}

   static inline void ae_init_small(u8 *p) {
     F(p,4)=lbl_80562520; F(p,8)=lbl_80562520; F(p,0xC)=lbl_80562520;
     F(p,0x10)=lbl_8056254C; F(p,0x14)=lbl_80562550; F(p,0x18)=lbl_80562520;
     F(p,0x1C)=lbl_80562520; F(p,0x20)=lbl_80562520; F(p,0x24)=lbl_80562520;
     *(s32 *)(p+0)=0;
 }
  #pragma scheduling invalid_target
  #pragma unroll off
  void *fn_801AE180(void) {
    s32 temp_r12, temp_r3, temp_r8_2, temp_r9, var_r4, var_r5, var_r5_2, var_r8;
    u32 temp_r11;
    void **temp_r31;
    void *temp_r3_2, *temp_r5;
    u8 *temp_r3_3, *temp_r5_2, *temp_r7, *temp_r8, *var_r6;

    temp_r31 = lbl_8055E604;
    temp_r3_2 = *temp_r31;
    if ((temp_r3_2 == 0) || (*(s32 *)((u8 *)temp_r3_2 + 4) == 0x40)) {
        temp_r3_3 = (u8 *)fn_801284F8(0xA08, *(void **)((u8 *)temp_r31 + 4));
        if (temp_r3_3 != 0) {
            var_r6 = temp_r3_3 + 0x30;
            temp_r5_2 = temp_r3_3 + 0xA08;
            F(temp_r3_3, 0xC) = lbl_80562520; F(temp_r3_3, 0x10) = lbl_80562520;
            F(temp_r3_3, 0x14) = lbl_80562520; F(temp_r3_3, 0x18) = lbl_8056254C;
            F(temp_r3_3, 0x1C) = lbl_80562550; F(temp_r3_3, 0x20) = lbl_80562520;
            F(temp_r3_3, 0x24) = lbl_80562520; F(temp_r3_3, 0x28) = lbl_80562520;
            F(temp_r3_3, 0x2C) = lbl_80562520; *(s32 *)(temp_r3_3 + 8) = 0;
            if (var_r6 < temp_r5_2) {
                temp_r8 = temp_r3_3 + 0x30;
                temp_r9 = temp_r5_2 - temp_r8;
                temp_r11 = (temp_r9 + 0x27) / 40;
                temp_r12 = temp_r11 + 1;
                temp_r7 = temp_r3_3 + 0x8C8;
                if (temp_r12 > 8) {
                    var_r4 = 0; var_r5 = 0;
                    if (temp_r7 <= temp_r5_2) {
                        var_r8 = 1;
                        if (!(temp_r9 & 0x80000000) && ((temp_r9 + 0x27) & 0x80000000)) var_r8 = 0;
                        if (var_r8 != 0) var_r5 = 1;
                    }
                    if (var_r5 != 0) {
                        temp_r8_2 = temp_r11 & 0x80000000;
                        var_r5_2 = 1;
                        if ((temp_r8_2 == 0) && (temp_r8_2 != (s32)(temp_r12 & 0x80000000))) var_r5_2 = 0;
                        if (var_r5_2 != 0) var_r4 = 1;
                    }
                    if (var_r4 != 0) {
                        for (; var_r6 < temp_r7; var_r6 += 0x140) {
                            F(var_r6,4)=lbl_80562520; F(var_r6,8)=lbl_80562520; F(var_r6,0xC)=lbl_80562520;
                            F(var_r6,0x10)=lbl_8056254C; F(var_r6,0x14)=lbl_80562550; F(var_r6,0x18)=lbl_80562520;
                            F(var_r6,0x1C)=lbl_80562520; F(var_r6,0x20)=lbl_80562520; F(var_r6,0x24)=lbl_80562520;
                            *(s32 *)(var_r6+0)=0;
                            F(var_r6,0x2C)=lbl_80562520; F(var_r6,0x30)=lbl_80562520; F(var_r6,0x34)=lbl_80562520;
                            F(var_r6,0x38)=lbl_8056254C; F(var_r6,0x3C)=lbl_80562550; F(var_r6,0x40)=lbl_80562520;
                            F(var_r6,0x44)=lbl_80562520; F(var_r6,0x48)=lbl_80562520; F(var_r6,0x4C)=lbl_80562520;
                            *(s32 *)(var_r6+0x28)=0;
                            F(var_r6,0x54)=lbl_80562520; F(var_r6,0x58)=lbl_80562520; F(var_r6,0x5C)=lbl_80562520;
                            F(var_r6,0x60)=lbl_8056254C; F(var_r6,0x64)=lbl_80562550; F(var_r6,0x68)=lbl_80562520;
                            F(var_r6,0x6C)=lbl_80562520; F(var_r6,0x70)=lbl_80562520; F(var_r6,0x74)=lbl_80562520;
                            *(s32 *)(var_r6+0x50)=0;
                            F(var_r6,0x7C)=lbl_80562520; F(var_r6,0x80)=lbl_80562520; F(var_r6,0x84)=lbl_80562520;
                            F(var_r6,0x88)=lbl_8056254C; F(var_r6,0x8C)=lbl_80562550; F(var_r6,0x90)=lbl_80562520;
                            F(var_r6,0x94)=lbl_80562520; F(var_r6,0x98)=lbl_80562520; F(var_r6,0x9C)=lbl_80562520;
                            *(s32 *)(var_r6+0x78)=0;
                            F(var_r6,0xA4)=lbl_80562520; F(var_r6,0xA8)=lbl_80562520; F(var_r6,0xAC)=lbl_80562520;
                            F(var_r6,0xB0)=lbl_8056254C; F(var_r6,0xB4)=lbl_80562550; F(var_r6,0xB8)=lbl_80562520;
                            F(var_r6,0xBC)=lbl_80562520; F(var_r6,0xC0)=lbl_80562520; F(var_r6,0xC4)=lbl_80562520;
                            *(s32 *)(var_r6+0xA0)=0;
                            F(var_r6,0xCC)=lbl_80562520; F(var_r6,0xD0)=lbl_80562520; F(var_r6,0xD4)=lbl_80562520;
                            F(var_r6,0xD8)=lbl_8056254C; F(var_r6,0xDC)=lbl_80562550; F(var_r6,0xE0)=lbl_80562520;
                            F(var_r6,0xE4)=lbl_80562520; F(var_r6,0xE8)=lbl_80562520; F(var_r6,0xEC)=lbl_80562520;
                            *(s32 *)(var_r6+0xC8)=0;
                            F(var_r6,0xF4)=lbl_80562520; F(var_r6,0xF8)=lbl_80562520; F(var_r6,0xFC)=lbl_80562520;
                            F(var_r6,0x100)=lbl_8056254C; F(var_r6,0x104)=lbl_80562550; F(var_r6,0x108)=lbl_80562520;
                            F(var_r6,0x10C)=lbl_80562520; F(var_r6,0x110)=lbl_80562520; F(var_r6,0x114)=lbl_80562520;
                            *(s32 *)(var_r6+0xF0)=0;
                            F(var_r6,0x11C)=lbl_80562520; F(var_r6,0x120)=lbl_80562520; F(var_r6,0x124)=lbl_80562520;
                            F(var_r6,0x128)=lbl_8056254C; F(var_r6,0x12C)=lbl_80562550; F(var_r6,0x130)=lbl_80562520;
                            F(var_r6,0x134)=lbl_80562520; F(var_r6,0x138)=lbl_80562520; F(var_r6,0x13C)=lbl_80562520;
                            *(s32 *)(var_r6+0x118)=0;
                        }
                    }
                }
                {
                    u32 n = ((u32)(temp_r5_2 - var_r6) + 0x27) / 0x28;
#pragma ctrloop on
                    do {
                        F(var_r6,4)=lbl_80562520; F(var_r6,8)=lbl_80562520; F(var_r6,0xC)=lbl_80562520;
                        F(var_r6,0x10)=lbl_8056254C; F(var_r6,0x14)=lbl_80562550; F(var_r6,0x18)=lbl_80562520;
                        F(var_r6,0x1C)=lbl_80562520; F(var_r6,0x20)=lbl_80562520; F(var_r6,0x24)=lbl_80562520;
                        *(s32 *)(var_r6+0)=0;
                        var_r6 += 0x28;
                    } while (--n != 0);
#pragma ctrloop reset
                }
            }
            *(s32 *)(temp_r3_3+4) = 0;
            *(void **)temp_r3_3 = 0;
        }
        *(void **)temp_r3_3 = *temp_r31;
        *temp_r31 = temp_r3_3;
    }
    temp_r5 = *temp_r31;
    temp_r3 = *(s32 *)((u8 *)temp_r5 + 4);
    *(s32 *)((u8 *)temp_r5 + 4) = temp_r3 + 1;
    return (u8 *)temp_r5 + temp_r3 * 0x28 + 8;
}
 #pragma unroll reset
 #pragma scheduling on
 void fn_801AE4C4(void) {
    void *result = (void *)fn_801284F8(8, &lbl_8033596C);
    if (result != NULL) {
        *(s32 *)result = 0;
        *(void **)((u8 *)result + 4) = &lbl_8055A8B8;
        lbl_8055E604 = result;
    }
}

#pragma scheduling off
void fn_801AE50C(void) {
    struct { void *head; void *next; void *cur; } locals;
    locals.head = lbl_8055E604;
    if (locals.head != 0) {
        while ((locals.cur = *(void *volatile *)locals.head) != 0) {
            locals.next = *(void **)locals.cur;
            fn_80128668(locals.cur);
            *(void *volatile *)locals.head = locals.next;
        }
        fn_80128668(locals.head);
    }
    lbl_8055E604 = 0;
}
#pragma scheduling on
