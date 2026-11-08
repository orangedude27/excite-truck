// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct Vec {
    f32 x, y, z;
} Vec;
typedef struct Mat3x3 {
    Vec a, b, c;
} Mat3x3;
typedef struct Transform {
    Vec a, b, c, d;
} Transform;
typedef struct Car {
    char pad0[4];
    s32 state;
    char pad8[0x74];
    Vec v7C;
    char pad88[0x34];
    f32 unkBC;
    s32 mC0[6];
    Vec vD8;
    Vec vE4;
    s32 mF0[6];
    Vec v108;
    Vec v114;
    char pad120[0xC];
    Vec v12C;
    char pad138[4];
    f32 unk13C;
    void *sub;
    char pad144[0x54];
    f32 unk198;
    f32 unk19C;
} Car;
extern f32 lbl_80563E78;
extern f32 lbl_80563E8C;
extern f32 lbl_80563E90;
extern f32 lbl_80563E94;
extern f32 lbl_80563E98;
extern f32 lbl_80563E9C;
extern f32 lbl_80563EA0;
extern double lbl_80563EB0;
extern s32 lbl_8049A208[];
extern s32 fn_8026F408(s32);
extern f32 fn_801E9FDC(void *, f32, f32);
extern s32 fn_801784DC(Vec *, f32 *, s32, s32, s32, f32, f32);
extern f32 fn_8026A520(s32);
extern f32 lbl_8049A218[];
extern f32 lbl_8055F52C;
extern f32 lbl_80563E68;
extern f32 lbl_80563E30;
extern f32 lbl_80563E38;
extern f32 lbl_80563E3C;
extern f32 lbl_80563E50;
extern f32 lbl_80563E54;
extern f32 lbl_80563E58;
extern f32 lbl_8055E3C8;
extern f32 lbl_80563E4C;
extern f32 lbl_80563E6C;
extern f32 lbl_80563E70;
extern f32 lbl_80563E74;
extern f32 lbl_80563E84;
extern f32 lbl_80563E88;
extern f32 lbl_80563EA8;
extern f32 lbl_80563EB8;
extern f32 lbl_80563EBC;
extern f32 lbl_80563EC0;
extern f32 lbl_80563EC4;
extern f32 lbl_80563EC8;
extern f32 lbl_80563ECC;
extern f32 lbl_80563ED0;
extern f32 lbl_80563ED4;
extern f32 lbl_80563ED8;
extern f32 lbl_80563EDC;
extern f32 lbl_80563EE0;
extern f32 lbl_80563EE4;
extern f32 lbl_80563EE8;
f32 PSVECDotProduct(const Vec *, const Vec *);
f32 PSVECMag(const Vec *);
s32 fn_801EA03C(void *, void *);
void fn_8026E870(Vec *, Vec *, void *, Vec *);
void fn_8026EF48(void *, void *, void *, f32);
extern f32 fn_8026EB4C(void *);
extern s32 fn_80178CA4(void);
extern double cos(double);
extern double atan(double);
extern double fn_8002EF30(f32);
extern void fn_8026FCFC();
extern f32 fn_8026EA8C(s32, void *, f32);

#pragma push
#pragma dont_inline on
extern f32 lbl_80563E34;
extern void PSVECCrossProduct(const Vec *, const Vec *, Vec *);
extern void PSVECNormalize(const Vec *, Vec *);
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8026E870(Vec *arg0, Vec *arg1, void *arg2, Vec *arg3) {
    struct Output {
        unsigned char pad[0x58];
        Vec side;
        Vec up;
        Vec forward;
        Vec position;
    };
    struct Output *out = (struct Output *)arg2;
    Vec delta;
    Vec up;
    Vec forward;
    Vec side;
    f32 dot;
    f32 x, y, z, dx;
    f32 sideX, sideY, sideZ;
    f32 upX, upY, upZ;

    x = arg0->x;
    dx = arg1->x - x;
    out->position.x = x;
    delta.x = dx;
    y = arg0->y;
    out->position.y = y;
    delta.y = arg1->y - out->position.y;
    z = arg0->z;
    out->position.z = z;
    delta.z = arg1->z - out->position.z;
    dot = PSVECDotProduct(&delta, &delta);
    if (dot < lbl_80563E30) return;
    if (lbl_80563E34 > (f32)__fabs((double)delta.x) &&
        lbl_80563E34 > (f32)__fabs((double)delta.z)) return;
    out->forward.x = delta.x;
    out->forward.y = delta.y;
    out->forward.z = delta.z;
    PSVECCrossProduct(arg3, &out->forward, &out->side);
    PSVECCrossProduct(&out->forward, &out->side, &out->up);
    sideZ = out->side.z;
    sideY = out->side.y;
    sideX = out->side.x;
    side.x = sideX;
    side.y = sideY;
    side.z = sideZ;
    upZ = out->forward.z;
    upY = out->forward.y;
    upX = out->forward.x;
    up.x = upX;
    up.y = upY;
    up.z = upZ;
    PSVECCrossProduct(&up, &side, &forward);
    PSVECNormalize(&side, &side);
    PSVECNormalize(&forward, &forward);
    PSVECCrossProduct(&side, &forward, &up);
    out->side.x = side.x;
    out->side.y = side.y;
    out->side.z = side.z;
    out->up.x = forward.x;
    out->up.y = forward.y;
    out->up.z = forward.z;
    out->forward.x = up.x;
    out->forward.y = up.y;
    out->forward.z = up.z;
}
s32 fn_8026EA14(s32 arg0) {
    s32 shift = arg0 - 4;
    s32 result = 0;
    s32 one = 1;
    if ((unsigned)shift <= 0x13 && ((one << shift) & 0x80017)) result = 1;
    return result;
}
#pragma scheduling on

#pragma push
#pragma dont_inline on
f32 fn_8026EA44(s32 arg0) {
    switch (arg0) {
    case 6:
        return lbl_80563E38;
    case 8:
    case 4:
        return lbl_80563E3C;
    case 7:
        return lbl_80563E30;
    default:
        return lbl_80563E3C;
    }
}

extern f32 lbl_80563E40, lbl_80563E44, lbl_80563E48, lbl_80563E4C;
f32 fn_8026EA8C(s32 arg0, void *arg1, f32 farg0) {
    f32 value;
    switch (arg0) {
    case 4:
        return lbl_80563E40;
    case 5:
        return lbl_80563E44;
    case 6:
        return lbl_80563E48;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    default:
        value = lbl_80563E48 + lbl_80563E4C * farg0;
        if (value < lbl_80563E40)
            return value;
        return lbl_80563E40;
    }
}

#pragma pop

#pragma push
#pragma dont_inline on
f32 fn_8026EAEC(f32 farg0) {
    f32 value;
    if (fn_80178CA4() > 1) {
        value = lbl_80563E58 * (f32)atan(lbl_80563E54 * (f32)fn_8002EF30(farg0 * lbl_80563E50));
    } else {
        value = farg0;
    }
    return value;
}

extern f32 lbl_80563E5C;
extern f32 lbl_8055F530;
extern f32 lbl_8055F534;
extern f32 lbl_8055F528;
extern f32 lbl_80563E60;
extern f32 lbl_80563E64;
extern f32 fn_8026EAEC(f32);
extern int fn_801769F8(void);
extern int fn_800216D0(void);
extern void *fn_801B2ED0(s32);
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" f32 fn_8026EB4C(void *arg0) {
    class Obj {
    public:
        virtual void dummy0();
        virtual void dummy1();
        virtual void *getMethod();
    };

    f32 temp_f31;
    f32 f30;
    f32 f1;
    f32 f2;
    f32 diff;
    f32 t;
    int c;
    int flag;

    char *sub = *(char **)((char *)arg0 + 0x140);
    f1 = !(*(f32 *)(sub + 0x258C) > lbl_80563E5C) ? lbl_8055F534 : lbl_8055F530;
    f30 = fn_8026EAEC(f1);

    f2 = lbl_8055F528;
    diff = lbl_8055F52C - f2;
    t = *(f32 *)((char *)arg0 + 0x13C);
    temp_f31 = fn_8026EAEC(f2 + t * diff);

    sub = *(char **)((char *)arg0 + 0x140);
    flag = 0;
    c = 1;
    int cond2 = *(f32 *)(sub + 0x258C) > lbl_80563E5C;
    if (!cond2 && *(u8 *)(sub + 0x259C) == 0) {
        c = 0;
    }
    if (c != 0) {
        int cond3 = *(f32 *)(sub + 0x25E0) > lbl_80563E50;
        if (cond3 != 0) {
            flag = 1;
        }
    }

    if (*(s32 *)((char *)arg0 + 4) != *(s32 *)((char *)arg0 + 0x10)) {
        f30 = flag ? f30 : temp_f31;
    } else if (fn_801769F8() != 0 || fn_800216D0() != 0 || *(s32 *)(*(char **)((char *)arg0 + 0x140) + 0x2620) < 1) {
        f30 = *(f32 *)((char *)arg0 + 0x194);
    } else {
        if (flag) {
            void *obj = fn_801B2ED0(*(s32 *)(*(char **)((char *)arg0 + 0x140) + 0x1EC));
            void *res = ((Obj *)obj)->getMethod();
            if (*(s32 *)((char *)res + 0x24) != 1) {
                f2 = *(f32 *)((char *)arg0 + 0x194);
                f30 = f2 + lbl_80563E60 * (f30 - f2);
                goto end;
            }
        }
        f2 = *(f32 *)((char *)arg0 + 0x194);
        f30 = f2 + lbl_80563E64 * (temp_f31 - f2);
    }

end:
    return f30;
}
#pragma cplusplus reset
#pragma pop

#pragma processor 750
f32 fn_8026ECE4(void *arg0, f32 *arg1) {
    f32 denom;
    f32 value;
    value = fn_8026EB4C(arg0);
    if (value > lbl_8055F52C) {
        denom = (f32)cos((double)(lbl_8055F52C * lbl_80563E68));
        *arg1 *= (f32)cos((double)(value * lbl_80563E68)) / denom;
    }
    return value;
}
#pragma processor reset
extern f32 lbl_80563E7C;
extern f32 lbl_80563E80;
void fn_8026ED64(s32 *arg0, Vec *arg1, Vec *arg2, f32 farg0) {
    f32 *entry = lbl_8049A218 + (*arg0 * 4);
    f32 curve;
    f32 curve2;
    f32 t;
    f32 blend;
    f32 factor;
    f32 dx;
    f32 dy;
    f32 dz;
    volatile Vec delta;

    curve = entry[3];
    if (curve < lbl_80563E6C)
        curve = lbl_80563E6C;
    else if (curve > lbl_80563E30)
        curve = lbl_80563E30;
    else if (curve > lbl_80563E78)
        curve = (lbl_80563E70 * curve * curve * curve) + (lbl_80563E74 * curve * curve);
    else
        curve = (lbl_80563E70 * curve * curve * curve) - (lbl_80563E74 * curve * curve);

    t = (entry[1] - lbl_80563E78) / lbl_80563E7C;
    if (t < lbl_80563E30)
        t = lbl_80563E30;
    if (t > lbl_80563E78)
        t = lbl_80563E78;
    factor = lbl_80563E78 + t * lbl_80563E30;
    factor = factor * curve;
    factor = lbl_80563E80 * factor;
    factor = farg0 * factor;
    arg1->y = arg1->y + factor;

    dx = arg2->x - arg1->x;
    curve2 = entry[3];
    dy = arg2->y - arg1->y;
    dz = arg2->z - arg1->z;
    delta.x = dx;
    delta.y = dy;
    delta.z = dz;

    if (curve2 < lbl_80563E6C)
        curve2 = lbl_80563E6C;
    else if (curve2 > lbl_80563E30)
        curve2 = lbl_80563E30;
    else if (curve2 > lbl_80563E78)
        curve2 = (lbl_80563E70 * curve2 * curve2 * curve2) + (lbl_80563E74 * curve2 * curve2);
    else
        curve2 = (lbl_80563E70 * curve2 * curve2 * curve2) - (lbl_80563E74 * curve2 * curve2);

    blend = lbl_80563E6C - lbl_80563E50 * curve2;
    arg1->x = arg2->x + delta.x * blend;
    arg1->y = arg2->y + delta.y * blend;
    arg1->z = arg2->z + delta.z * blend;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8026EF48(void *arg0, void *arg1, void *arg2, f32 farg0) {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Vec sp48;
    Vec sp3C;
    Vec sp30;
    Vec sp24;
    Vec sp18;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    void *sub;
    s32 flag;
    void *rec;
    f32 *entry;
    sub = *(void **)((char *)arg0 + 0x140);
    entry = lbl_8049A218 + (*(s32 *)arg0 * 4);
    if (fn_801769F8() == 0) {
        sp48 = *(Vec *)((char *)sub + 0x60);
        flag = *(s32 *)((char *)sub + 0x2620) > 0;
        f30 = sp48.z;
        f31 = sp48.y;
        rec = (char *)sub + 0x6C;
        f29 = fn_801E9FDC(rec, lbl_80563E84 + sp48.x, lbl_80563E84 + f30);
        sp3C.x = lbl_80563E84 + sp48.x;
        sp3C.y = f31;
        sp3C.z = lbl_80563E84 + f30;
        if (fn_801784DC(&sp3C, &sp14, 0, 0, (s32)fn_8026F408, lbl_80563E84 + sp48.x, lbl_80563E84) != 0) {
            f29 = f29 > sp14 ? f29 : sp14;
        }
        f28 = fn_801E9FDC(rec, sp48.x - lbl_80563E84, lbl_80563E84 + f30);
        sp30.x = sp48.x - lbl_80563E84;
        sp30.y = f31;
        sp30.z = lbl_80563E84 + f30;
        if (fn_801784DC(&sp30, &sp10, 0, 0, (s32)fn_8026F408, sp48.x - lbl_80563E84, lbl_80563E84) != 0) {
            f28 = f28 > sp10 ? f28 : sp10;
        }
        f27 = fn_801E9FDC(rec, sp48.x - lbl_80563E84, f30 - lbl_80563E84);
        sp24.x = sp48.x - lbl_80563E84;
        sp24.y = f31;
        sp24.z = f30 - lbl_80563E84;
        if (fn_801784DC(&sp24, &spC, 0, 0, (s32)fn_8026F408, sp48.x - lbl_80563E84, lbl_80563E84) != 0) {
            f27 = f27 > spC ? f27 : spC;
        }
        f26 = fn_801E9FDC(rec, lbl_80563E84 + sp48.x, f30 - lbl_80563E84);
        sp18.x = lbl_80563E84 + sp48.x;
        sp18.y = f31;
        sp18.z = f30 - lbl_80563E84;
        if (fn_801784DC(&sp18, &sp8, 0, 0, (s32)fn_8026F408, lbl_80563E84 + sp48.x, lbl_80563E84) != 0) {
            f26 = f26 > sp8 ? f26 : sp8;
        }
        f2 = lbl_80563E68 * ((f27 + f26) + f28 + f29);
        if (flag != 0) {
            entry[0] = f2 - sp48.y;
            entry[2] = lbl_80563E78;
        } else {
            entry[2] = entry[2] + lbl_80563E88;
        }
        f0 = (entry[2] - lbl_80563E78) / lbl_80563E30;
        f3 = lbl_80563E30;
        f3 = f3 > f0 ? f3 : f0;
        f3 = f3 > lbl_80563E78 ? f3 : lbl_80563E78;
        f4 = entry[0] + (sp48.y - f2);
        f1 = lbl_80563E88 * (lbl_80563E8C + f3 * lbl_80563E90);
        if (flag != 0) {
            f2 = lbl_80563E94;
        } else {
            f2 = lbl_80563E98;
        }
        if (f4 < entry[1]) {
            f0 = entry[1] - f2;
            f4 = f4 > f0 ? f4 : f0;
        } else {
            f0 = entry[1] + f1;
            f4 = f4 > f0 ? f4 : f0;
        }
        entry[1] = f4;
        if ((f32)(fn_8026A520(*(s32 *)((char *)sub + 0x1EC)) == lbl_80563E78) == lbl_80563E78) {
            f1 = lbl_80563E9C + entry[3];
            f1 = f1 > lbl_80563E30 ? f1 : lbl_80563E30;
            entry[3] = f1;
        } else {
            f0 = entry[3] - lbl_80563EA0;
            f0 = f0 > lbl_80563E78 ? f0 : lbl_80563E78;
            entry[3] = f0;
        }
    }
    f0 = entry[1];
    f2 = lbl_80563E78;
    f2 = f2 > f0 ? f2 : f0;
    f3 = ((f32 *)lbl_8049A208)[3];
    f0 = lbl_80563EA8 + ((f32 *)lbl_8049A208)[2];
    f3 = f3 > f0 ? f3 : f0;
    f4 = lbl_80563E30;
    f1 = (f2 - ((f32 *)lbl_8049A208)[2]) / (f3 - ((f32 *)lbl_8049A208)[2]);
    f4 = f4 > f1 ? f4 : f1;
    f4 = f4 > lbl_80563E78 ? f4 : lbl_80563E78;
    f4 = lbl_80563E78 + f4 * lbl_80563E30;
    ((Vec *)arg1)->y = ((Vec *)arg1)->y + ((f32 *)lbl_8049A208)[0] * f4;
    ((Vec *)arg2)->y = ((Vec *)arg2)->y + ((f32 *)lbl_8049A208)[1] * f4;
    f1 = lbl_80563E30;
    f0 = lbl_80563E4C * f4;
    f1 = f1 > f0 ? f1 : f0;
    fn_8026ED64((s32 *)arg0, (Vec *)arg1, (Vec *)arg2, f1);
}
#pragma pop

#pragma scheduling off
s32 fn_8026F408(s32 arg0) { return arg0 <= 8; }
#pragma scheduling reset

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
void fn_8026F420(s32 arg0, s32 arg1, void *arg2) {
    f32 sp8;
    Vec spC;
    Vec sp18;
    Vec sp24;
    Vec sp30;
    Vec sp3C;
    Vec sp48;
    f32 f1;
    f32 f2;
    f32 f0;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f31;
    f32 f6;
    f32 f5;
    f32 f1_poly;
    f32 f0_poly;
    f32 scale;
    f32 sign;
    f32 inv_mag;
    f32 limit;
    char *sub;
    Vec *v120;
    int cond;
    int is_seven;
    int cond24;
    int flag;

    cond = fn_80178CA4() > 1;
    if (arg0 == 8) {
        f1 = cond ? lbl_80563EB8 : lbl_80563EBC;
    } else {
        f1 = cond ? lbl_80563EC0 : lbl_80563E78;
    }

    sub = *(char **)((char *)arg2 + 0x140);
    is_seven = (arg0 == 7);
    sp8 = *(f32 *)(sub + 0x5B4) + f1;
    f1 = *(f32 *)(sub + 0x2688);
    f31 = *(f32 *)(sub + 0x5B8);
    cond24 = f1 > lbl_80563E78;

    if (*(u8 *)((char *)arg2 + 0x138) != 0 || cond24) {
        *(f32 *)((char *)arg2 + 0xC) = lbl_80563E78;
        if (fn_8026EA14(arg1) == 0 && arg0 != 0x17) {
            *(s32 *)((char *)arg2 + 0x18) = 4;
            *(f32 *)((char *)arg2 + 0x8) = lbl_80563E78;
        } else {
            *(s32 *)((char *)arg2 + 0x18) = arg1;
        }

        if ((*(s32 *)((char *)arg2 + 0x18) != 0x17 && arg0 != 0x17) || *(u8 *)((char *)arg2 + 0x139) != 0) {
            *(f32 *)((char *)arg2 + 0x8) = lbl_80563E78;
        }

        if (fn_8026EA14(arg1) == 0 || *(u8 *)((char *)arg2 + 0x139) != 0 || cond24) {
            *(f32 *)((char *)arg2 + 0x114) = *(f32 *)((char *)arg2 + 0xE4);
            *(f32 *)((char *)arg2 + 0x118) = *(f32 *)((char *)arg2 + 0xE8);
            *(f32 *)((char *)arg2 + 0x11C) = *(f32 *)((char *)arg2 + 0xEC);

            *(f32 *)((char *)arg2 + 0x114) += *(f32 *)((char *)arg2 + 0xD8) * lbl_80563EC4;
            *(f32 *)((char *)arg2 + 0x118) += *(f32 *)((char *)arg2 + 0xDC) * lbl_80563EC4;
            *(f32 *)((char *)arg2 + 0x11C) += *(f32 *)((char *)arg2 + 0xE0) * lbl_80563EC4;

            *(s32 *)((char *)arg2 + 0xF0) = *(s32 *)((char *)arg2 + 0xC0);
            *(s32 *)((char *)arg2 + 0xF4) = *(s32 *)((char *)arg2 + 0xC4);
            *(s32 *)((char *)arg2 + 0xF8) = *(s32 *)((char *)arg2 + 0xC8);
            *(s32 *)((char *)arg2 + 0xFC) = *(s32 *)((char *)arg2 + 0xCC);
            *(s32 *)((char *)arg2 + 0x100) = *(s32 *)((char *)arg2 + 0xD0);
            *(s32 *)((char *)arg2 + 0x104) = *(s32 *)((char *)arg2 + 0xD4);
            *(s32 *)((char *)arg2 + 0x108) = *(s32 *)((char *)arg2 + 0xD8);
            *(s32 *)((char *)arg2 + 0x10C) = *(s32 *)((char *)arg2 + 0xDC);
            *(s32 *)((char *)arg2 + 0x110) = *(s32 *)((char *)arg2 + 0xE0);

            if (is_seven) {
                *(f32 *)((char *)arg2 + 0x118) -= lbl_80563E84;
            } else {
                *(f32 *)((char *)arg2 + 0x118) += lbl_80563E84;
            }
            *(f32 *)((char *)arg2 + 0x8) = lbl_80563E78;
        }
    }

    f2 = lbl_80563E30;
    f0 = lbl_80563EC8 * *(f32 *)((char *)arg2 + 0xC);
    if (f2 >= f0) {
        f2 = f0;
    }
    if (f2 <= lbl_80563E78) {
        f2 = lbl_80563E78;
    }

    f30 = lbl_80563E6C;
    if (f2 >= lbl_80563E6C) {
        f30 = lbl_80563E30;
        if (f2 <= lbl_80563E30) {
            f1_poly = lbl_80563E70 * f2;
            f0_poly = lbl_80563E74 * f2;
            f1_poly *= f2;
            f0_poly *= f2;
            f1_poly = f2 * f1_poly;
            if (f2 > lbl_80563E78) {
                f30 = f1_poly + f0_poly;
            } else {
                f30 = f1_poly - f0_poly;
            }
        }
    }

    if (arg0 == 0x17) {
        if (fn_801769F8() == 0) {
            *(f32 *)((char *)arg2 + 0x8) += lbl_80563E88;
        }
        f30 = lbl_80563E30;
    }

    sp48.x = *(f32 *)((char *)arg2 + 0xE4);
    sp48.y = *(f32 *)((char *)arg2 + 0xE8);
    sp48.z = *(f32 *)((char *)arg2 + 0xEC);
    *(f32 *)((char *)arg2 + 0xBC) = fn_8026ECE4(arg2, &sp8);
    f29 = fn_8026EA44(arg0);
    f1 = fn_8026EA44(*(s32 *)((char *)arg2 + 0x18));
    f0 = f29 - f1;
    sp48.y += *(f32 *)(sub + 0x5E4) * (f31 + (f1 + f30 * f0));

    *(s32 *)((char *)arg2 + 0x58) = *(s32 *)((char *)arg2 + 0xF0);
    *(s32 *)((char *)arg2 + 0x5C) = *(s32 *)((char *)arg2 + 0xF4);
    *(s32 *)((char *)arg2 + 0x60) = *(s32 *)((char *)arg2 + 0xF8);
    *(s32 *)((char *)arg2 + 0x64) = *(s32 *)((char *)arg2 + 0xFC);
    *(s32 *)((char *)arg2 + 0x68) = *(s32 *)((char *)arg2 + 0x100);
    *(s32 *)((char *)arg2 + 0x6C) = *(s32 *)((char *)arg2 + 0x104);
    *(s32 *)((char *)arg2 + 0x70) = *(s32 *)((char *)arg2 + 0x108);
    *(s32 *)((char *)arg2 + 0x74) = *(s32 *)((char *)arg2 + 0x10C);
    *(s32 *)((char *)arg2 + 0x78) = *(s32 *)((char *)arg2 + 0x110);
    *(s32 *)((char *)arg2 + 0x7C) = *(s32 *)((char *)arg2 + 0x114);
    *(s32 *)((char *)arg2 + 0x80) = *(s32 *)((char *)arg2 + 0x118);
    *(s32 *)((char *)arg2 + 0x84) = *(s32 *)((char *)arg2 + 0x11C);

    sp30.x = lbl_80563E78;
    sp30.y = lbl_80563E30;
    sp30.z = lbl_80563E78;
    fn_8026E870((Vec *)((char *)arg2 + 0x7C), &sp48, arg2, &sp30);

    v120 = (Vec *)((char *)arg2 + 0x120);
    flag = 0;
    sp3C.x = lbl_80563E78;
    sp3C.y = lbl_80563E78;
    sp3C.z = lbl_80563E78;
    if (PSVECDotProduct(v120, v120) < lbl_80563E30) {
        flag = 1;
        sp3C.x = v120->x;
        sp3C.y = v120->y;
        sp3C.z = v120->z;
    } else {
        inv_mag = lbl_80563E30 / PSVECMag(v120);
        sp3C.x = v120->x * inv_mag;
        sp3C.y = v120->y * inv_mag;
        sp3C.z = v120->z * inv_mag;
    }

    if (fn_801769F8() == 0) {
        if (flag != 0 || PSVECDotProduct(&sp3C, (Vec *)((char *)arg2 + 0x70)) >= lbl_80563E78) {
            scale = lbl_80563ECC * PSVECDotProduct(&sp3C, (Vec *)((char *)arg2 + 0x58));
        } else {
            sign = PSVECDotProduct(&sp3C, (Vec *)((char *)arg2 + 0x58)) > lbl_80563E78 ? lbl_80563E30 : lbl_80563E6C;
            scale = lbl_80563ECC * sign;
        }
        *(f32 *)((char *)arg2 + 0x7C) += *(f32 *)((char *)arg2 + 0x58) * scale;
        *(f32 *)((char *)arg2 + 0x80) += *(f32 *)((char *)arg2 + 0x5C) * scale;
        *(f32 *)((char *)arg2 + 0x84) += *(f32 *)((char *)arg2 + 0x60) * scale;
    }

    sp24.x = lbl_80563E78;
    sp24.y = lbl_80563E30;
    sp24.z = lbl_80563E78;
    fn_8026E870((Vec *)((char *)arg2 + 0x7C), &sp48, arg2, &sp24);

    if (arg0 == 8) {
        f28 = lbl_80563E30 - lbl_80563E68 * *(f32 *)((char *)arg2 + 0x13C);
    } else {
        f28 = lbl_80563E30 - lbl_80563ED0 * *(f32 *)((char *)arg2 + 0x13C);
    }

    f27 = *(f32 *)(sub + 0x5E4);
    f29 = fn_8026EA8C(arg0, sub, *(f32 *)((char *)arg2 + 0x8));
    f1 = fn_8026EA8C(*(s32 *)((char *)arg2 + 0x18), sub, *(f32 *)((char *)arg2 + 0x8));
    f0 = f29 - f1;

    f6 = ((f1 + f30 * f0) * (f28 * f27)) - sp8;
    *(f32 *)((char *)arg2 + 0x7C) = sp48.x + *(f32 *)((char *)arg2 + 0x70) * f6;
    f1 = sp48.y + *(f32 *)((char *)arg2 + 0x74) * f6;
    *(f32 *)((char *)arg2 + 0x80) = f1;
    *(f32 *)((char *)arg2 + 0x84) = sp48.z + *(f32 *)((char *)arg2 + 0x78) * f6;

    *(s32 *)((char *)arg2 + 0xF0) = *(s32 *)((char *)arg2 + 0x58);
    *(s32 *)((char *)arg2 + 0xF4) = *(s32 *)((char *)arg2 + 0x5C);
    *(s32 *)((char *)arg2 + 0xF8) = *(s32 *)((char *)arg2 + 0x60);
    *(s32 *)((char *)arg2 + 0xFC) = *(s32 *)((char *)arg2 + 0x64);
    *(s32 *)((char *)arg2 + 0x100) = *(s32 *)((char *)arg2 + 0x68);
    *(s32 *)((char *)arg2 + 0x104) = *(s32 *)((char *)arg2 + 0x6C);
    *(s32 *)((char *)arg2 + 0x108) = *(s32 *)((char *)arg2 + 0x70);
    *(s32 *)((char *)arg2 + 0x10C) = *(s32 *)((char *)arg2 + 0x74);
    *(s32 *)((char *)arg2 + 0x110) = *(s32 *)((char *)arg2 + 0x78);
    *(s32 *)((char *)arg2 + 0x114) = *(s32 *)((char *)arg2 + 0x7C);
    *(s32 *)((char *)arg2 + 0x118) = *(s32 *)((char *)arg2 + 0x80);
    *(s32 *)((char *)arg2 + 0x11C) = *(s32 *)((char *)arg2 + 0x84);

    *(f32 *)((char *)arg2 + 0x80) = f1 - lbl_80563EA8;

    if (is_seven != 0 || *(u8 *)(sub + 0x260C) != 0) {
        f5 = lbl_80563E4C;
        *(f32 *)((char *)arg2 + 0x7C) = *(f32 *)((char *)arg2 + 0xE4) * lbl_80563E58 - *(f32 *)((char *)arg2 + 0x114);
        *(f32 *)((char *)arg2 + 0x80) = *(f32 *)((char *)arg2 + 0xE8) * lbl_80563E58 - *(f32 *)((char *)arg2 + 0x118);
        *(f32 *)((char *)arg2 + 0x84) = *(f32 *)((char *)arg2 + 0xEC) * lbl_80563E58 - *(f32 *)((char *)arg2 + 0x11C);

        switch (arg0) {
        case 4:
            f5 = lbl_80563ED4;
            break;
        case 6:
            f5 = lbl_80563ED8;
            break;
        }

        limit = *(f32 *)((char *)arg2 + 0xE8) + lbl_80563E30;
        f1 = *(f32 *)((char *)arg2 + 0x80) + (f5 + lbl_80563E58 * f31) * *(f32 *)(sub + 0x5E4);
        *(f32 *)((char *)arg2 + 0x80) = f1;
        if (f1 > limit) {
            *(f32 *)((char *)arg2 + 0x80) = limit;
        }

        sp18.x = lbl_80563E78;
        sp18.y = lbl_80563E30;
        sp18.z = lbl_80563E78;
        fn_8026E870((Vec *)((char *)arg2 + 0x7C), &sp48, arg2, &sp18);
    }

    f27 = is_seven ? lbl_80563EDC : lbl_80563E50;
    *(f32 *)((char *)arg2 + 0x190) = lbl_8055E3C8;
    f28 = *(f32 *)((char *)arg2 + 0x80);

    if (fn_801EA03C(sub + 0x6C, (Vec *)((char *)arg2 + 0x7C)) == 0) {
        *(f32 *)((char *)arg2 + 0x80) = f28;
        *(f32 *)((char *)arg2 + 0x18C) = lbl_80563EE0 - lbl_80563EE4 * (lbl_80563EE0 - *(f32 *)((char *)arg2 + 0x18C));
    } else {
        f0 = *(f32 *)((char *)arg2 + 0x80) + f27;
        *(f32 *)((char *)arg2 + 0x80) = f0;
        if (f0 < f28) {
            *(f32 *)((char *)arg2 + 0x80) = f28;
        }
        *(f32 *)((char *)arg2 + 0x18C) = *(f32 *)((char *)arg2 + 0x18C) * lbl_80563EE4;
    }

    f2 = *(f32 *)((char *)arg2 + 0x18C);
    if (f2 > lbl_80563EE0) {
        f2 = lbl_80563EE0;
    }
    if (f2 < lbl_80563E78) {
        f2 = lbl_80563E78;
    }

    f1 = *(f32 *)((char *)arg2 + 0x80);
    *(f32 *)((char *)arg2 + 0x18C) = f2;
    *(f32 *)((char *)arg2 + 0x80) = f1 + f2;

    fn_8026EF48(arg2, (Vec *)((char *)arg2 + 0x7C), &sp48, f1);

    spC.x = lbl_80563E78;
    spC.y = lbl_80563E30;
    spC.z = lbl_80563E78;
    fn_8026E870((Vec *)((char *)arg2 + 0x7C), &sp48, arg2, &spC);

    if (fn_801769F8() == 0) {
        f1 = *(f32 *)((char *)arg2 + 0xC) + lbl_80563E88;
        if (f1 > lbl_80563EE8) {
            f1 = lbl_80563EE8;
        }
        *(f32 *)((char *)arg2 + 0xC) = f1;
    }
}
#pragma cplusplus reset
#pragma pop
f32 fn_8026FCE0(f32 farg0, f32 farg1) {
    f32 diff = lbl_80563E30 - farg1;
    f32 square = farg0 * farg0;
    return (diff * farg0) + (farg1 * square);
}

extern f32 lbl_80563ED8;
extern f32 lbl_80563F1C;
extern f32 lbl_80563E40;
extern f32 lbl_80563E44;
extern f32 lbl_80563E48;
extern f32 lbl_80563E4C;
extern f32 lbl_80563E38;
extern f32 lbl_80563E3C;
extern f32 lbl_80563E38;
extern f32 lbl_80563E38;
extern s32 lbl_8049A208[];
void fn_8027045C(void) {
    ((f32 *)&lbl_8049A208)[0] = lbl_80563ED8;
    ((f32 *)&lbl_8049A208)[1] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[2] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[3] = lbl_80563F1C;
}

void fn_80270484(void) {
    f32 value = lbl_80563E78;
    f32 *p = lbl_8049A218 - 1;
    *++p = value;
    p[1] = value;
    p[3] = value;
    p[2] = value;
    p[4] = value;
    p[5] = value;
    p[7] = value;
    p[6] = value;
    p[8] = value;
    p[9] = value;
    p[11] = value;
    p[10] = value;
    p[12] = value;
    p[13] = value;
    p[15] = value;
    p[14] = value;
}

void fn_802704D0(void) { fn_8026FCFC(); }

void fn_802704D4(void *arg0, void *arg1) {
    ((void (*)(void *, s32, void *))fn_802704D0)(arg0, *(s32 *)((u8 *)arg1 + 4), arg1);
}

void fn_802704E0(void) { ((f32 (*)())fn_8026EA8C)(); }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern f32 lbl_80558DC4[];
extern f32 lbl_80563EA4;
extern f32 lbl_80563F00;
extern f32 lbl_80563F04;
extern f32 lbl_80563F08;
extern f32 lbl_80563F0C;
extern f32 lbl_80563F14;
extern f32 lbl_80563F18;
extern f32 lbl_80563F20;
extern f32 lbl_80563F24;
extern f32 lbl_80563F28;
#pragma push
#pragma processor 750
void fn_802704E4(Car *car) {
    Vec sp48;
    Vec sp3C;
    Vec sp30;
    Vec sp24;
    Vec sp18;
    Vec spC;
    f32 sp8;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f2;
    f32 f1;
    f32 f0;
    f32 f7;
    f32 f6;
    int cond;
    int cond29;

    cond = fn_80178CA4() > 1;
    f0 = lbl_80563E30 - car->unk13C * lbl_80563ED0;
    f1 = *(f32 *)((char *)car->sub + 0x5B4);
    f2 = cond ? lbl_80563ED8 : lbl_80563EC0;
    f1 = f2 + f1 * f0;
    sp8 = f1;
    f29 = lbl_80563F20 + *(f32 *)((char *)car->sub + 0x5B8);

    if (car->state != 9) {
        *(s32 *)&car->v114.x = *(s32 *)&car->vE4.x;
        *(s32 *)&car->v114.y = *(s32 *)&car->vE4.y;
        *(s32 *)&car->v114.z = *(s32 *)&car->vE4.z;

        f7 = car->v114.x + car->vD8.x * lbl_80563E44;
        f6 = car->v114.y + car->vD8.y * lbl_80563E44;
        f2 = car->v114.z + car->vD8.z * lbl_80563E44;

        car->mF0[0] = car->mC0[0];
        car->mF0[1] = car->mC0[1];
        car->mF0[2] = car->mC0[2];
        car->mF0[3] = car->mC0[3];
        car->mF0[4] = car->mC0[4];
        car->mF0[5] = car->mC0[5];
        *(s32 *)&car->v108.x = *(s32 *)&car->vD8.x;
        *(s32 *)&car->v108.y = *(s32 *)&car->vD8.y;
        *(s32 *)&car->v108.z = *(s32 *)&car->vD8.z;

        car->v114.x = f7;
        car->v114.y = f6;
        car->v114.z = f2;
    }

    f31 = (*(u8 *)((char *)car->sub + 0x260C) != 0) ? lbl_80563E30 : lbl_80563E78;
    car->unkBC = fn_8026ECE4(car, &sp8);

    sp48 = car->vE4;

    f0 = *(f32 *)((char *)car->sub + 0x5E4);
    f1 = cond ? lbl_80563F24 : lbl_80563E58;
    sp48.y += f1 * f0;

    if ((f32)__fabs(f31 - car->unk19C) <= lbl_80558DC4[0]) {
        cond29 = *(f32 *)((char *)car->sub + 0x25D8) < lbl_80563F28;
        cond = !((f32)__fabs(f31) <= lbl_80558DC4[0]);

        sp3C.x = sp48.x - car->v114.x;
        sp3C.y = sp48.y - car->v114.y;
        sp3C.z = sp48.z - car->v114.z;
        f1 = PSVECMag(&sp3C);
        if (f1 <= lbl_80563EA8) f1 = lbl_80563EA8;

        f1 = lbl_80563E30 / f1;
        car->v108.x = sp3C.x * f1;
        car->v108.y = sp3C.y * f1;
        car->v108.z = sp3C.z * f1;

        f1 = PSVECMag(&car->v12C);
        f0 = (f1 - lbl_80563F00) / lbl_80563F04;
        f1 = lbl_80563E30;
        if (f1 >= f0) f1 = f0;
        if (f1 <= lbl_80563E78) f1 = lbl_80563E78;

        if (((cond != 0) && (cond29 == 0)) || ((cond29 != 0) && (cond == 0))) {
            f1 *= lbl_80563EA8;
        } else {
            f1 = fn_8026FCE0(f1, lbl_80563F08);
        }

        f30 = f1 + lbl_80563F0C * (car->unk198 - f1);
        car->unk198 = f30;

        sp30 = car->vD8;
        if (cond != 0) {
            sp30.x *= lbl_80563E6C;
            sp30.y *= lbl_80563E6C;
            sp30.z *= lbl_80563E6C;
        }

        sp30.y *= lbl_80563EA4;
        f1 = PSVECMag(&sp30);
        f0 = lbl_80563E60;
        if (f0 <= f1) f0 = f1;
        f7 = lbl_80563E30 / f0;
        sp30.x *= f7;
        sp30.y *= f7;
        sp30.z *= f7;

        f6 = f30 + lbl_80563F14 * (lbl_80563E30 - f30);
        f2 = sp30.z + f6 * (car->v108.z - sp30.z);
        f1 = sp30.y + f6 * (car->v108.y - sp30.y);
        f0 = sp30.x + f6 * (car->v108.x - sp30.x);

        sp18.z = f2;
        sp18.x = f0;
        sp18.y = f1;
        car->v108.x = f0;
        car->v108.y = f1;
        car->v108.z = f2;
    } else {
        f2 = lbl_80563E6C;
        f0 = car->v108.x * f2;
        f1 = car->v108.y * f2;
        f2 = car->v108.z * f2;
        car->v108.x = f0;
        car->v108.y = f1;
        car->v108.z = f2;
    }

    f2 = lbl_80563F18 * *(f32 *)((char *)car->sub + 0x5E4);
    car->v114.x = sp48.x + car->v108.x * f2;
    car->v114.y = sp48.y + car->v108.y * f2;
    car->v114.z = sp48.z + car->v108.z * f2;

    f1 = -sp8 * *(f32 *)((char *)car->sub + 0x5E4);
    car->v7C.x = car->vE4.x + car->v108.x * f1;
    car->v7C.y = car->vE4.y + car->v108.y * f1;
    car->v7C.z = car->vE4.z + car->v108.z * f1;
    car->v7C.y += f29 * *(f32 *)((char *)car->sub + 0x5E4);

    sp24 = car->v7C;

    if (fn_801EA03C((char *)car->sub + 0x6C, &sp24) != 0) {
        f0 = (lbl_80563E50 + sp24.y) * *(f32 *)((char *)car->sub + 0x5E4);
        f2 = car->v7C.y;
        f2 = f2 > f0 ? f2 : f0;
        sp24.y = f2;
    } else {
        sp24.x = car->v7C.x;
        sp24.y = car->v7C.y;
        sp24.z = car->v7C.z;
    }

    ((void (*)(void *, Vec *, Vec *))fn_8026EF48)(car, &sp24, &sp48);

    spC.x = lbl_80563E78;
    spC.y = lbl_80563E30;
    spC.z = lbl_80563E78;
    fn_8026E870(&sp24, &sp48, car, &spC);

    car->unk19C = f31;
}
#pragma pop

