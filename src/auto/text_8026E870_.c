// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct Vec {
    f32 x, y, z;
} Vec;
extern f32 lbl_80563E78;
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
extern void fn_8026FCFC(void);
extern f32 fn_8026EA8C();

#pragma push
#pragma dont_inline on
s32 fn_8026EA14(s32 arg0) {
    s32 shift = arg0 - 4;
    s32 result = 0;
    if ((unsigned)shift > 0x13)
        return result;
    if ((1 << shift) & 0x80017)
        result = 1;
    return result;
}
#pragma pop

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

#pragma pop
f32 fn_8026ECE4(void *arg0, f32 *arg1) {
    f32 value = fn_8026EB4C(arg0);
    if (value > lbl_8055F52C) {
        f32 denom = (f32)cos((double)(lbl_8055F52C * lbl_80563E68));
        *arg1 *= (f32)cos((double)(value * lbl_80563E68)) / denom;
    }
    return value;
}

s32 fn_8026F408(s32 arg0) { return arg0 <= 8; }

#pragma push
#pragma processor 750
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

void fn_802704E0(void) { fn_8026EA8C(); }

