extern double lbl_80560600, lbl_80560608, lbl_80560610, lbl_80560670;
extern double lbl_80560618, lbl_80560620, lbl_80560628, lbl_80560630, lbl_80560638, lbl_80560640;
extern double lbl_80560648, lbl_80560650, lbl_80560658, lbl_80560660, lbl_80560668;
extern double lbl_80560678, lbl_80560680;
extern double lbl_80560688, lbl_80560690, lbl_80560698, lbl_805606A0;
extern double lbl_805606A8, lbl_805606B0, lbl_805606B8, lbl_805606C0, lbl_805606C8, lbl_805606D0;
extern double lbl_805606D8, lbl_805606E0, lbl_805606E8, lbl_805606F0, lbl_805606F8, lbl_80560700, lbl_80560708;
extern int lbl_80558DB0[];
extern double fabs(double);
extern double __fabs(double);
extern double fn_8002F234(double);

static const double huge = 1.0e300;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <errno.h>

#define __HI(x) (*(int*)&x)
#define __LO(x) (*(1+(int*)&x))

/* e_pow.c constants (see src/MSL/e_pow.c); unnamed in the game's .sdata2. */
extern double lbl_802EE4D8[];
extern double lbl_805607E8, lbl_805607F0, lbl_805607F8, lbl_80560800, lbl_80560808, lbl_80560810;
extern double lbl_80560818, lbl_80560820, lbl_80560828, lbl_80560830, lbl_80560838, lbl_80560840;
extern double lbl_80560848, lbl_80560850, lbl_80560858, lbl_80560860, lbl_80560868, lbl_80560870;
extern double lbl_80560878, lbl_80560880, lbl_80560888, lbl_80560890, lbl_80560898, lbl_805608A0;
extern double lbl_805608A8, lbl_805608B0, lbl_805608B8, lbl_805608C0, lbl_805608C8, lbl_805608D0;
extern double lbl_805608D8, lbl_805608E0, lbl_805608E8;
extern int lbl_8055D680;
extern double fn_8002B060(int, double);
#define pow_one      lbl_805607E8
#define pow_zero     lbl_805607F0
#define pow_inf      lbl_805607F8 /* huge*huge, folded */
#define pow_half     lbl_80560800
#define pow_third    lbl_80560808
#define pow_quarter  lbl_80560810
#define pow_ivln2_h  lbl_80560818
#define pow_ivln2_l  lbl_80560820
#define pow_ivln2    lbl_80560828
#define pow_two53    lbl_80560830
#define pow_L1       lbl_80560838
#define pow_L2       lbl_80560840
#define pow_L3       lbl_80560848
#define pow_L4       lbl_80560850
#define pow_L5       lbl_80560858
#define pow_L6       lbl_80560860
#define pow_three    lbl_80560868
#define pow_cp_h     lbl_80560870
#define pow_cp_l     lbl_80560878
#define pow_cp       lbl_80560880
#define pow_negone   lbl_80560888
#define pow_huge     lbl_80560890
#define pow_ovt      lbl_80560898
#define pow_tiny     lbl_805608A0
#define pow_lg2_h    lbl_805608A8
#define pow_lg2      lbl_805608B0
#define pow_lg2_l    lbl_805608B8
#define pow_P1       lbl_805608C0
#define pow_P2       lbl_805608C8
#define pow_P3       lbl_805608D0
#define pow_P4       lbl_805608D8
#define pow_P5       lbl_805608E0
#define pow_two      lbl_805608E8
#define pow_bp(k)    lbl_802EE4D8[k]
#define pow_dp_h(k)  lbl_802EE4D8[2 + (k)]
#define pow_dp_l(k)  lbl_802EE4D8[4 + (k)]

static const double
    ln2_hi = 6.93147180369123816490e-01,
    ln2_lo = 1.90821492927058770002e-10,
    two54 = 1.80143985094819840000e+16,
    Lg1 = 6.666666666666735130e-01,
    Lg2 = 3.999999999940941908e-01,
    Lg3 = 2.857142874366239149e-01,
    Lg4 = 2.222219843214978396e-01,
    Lg5 = 1.818357216161805012e-01,
    Lg6 = 1.531383769920937332e-01,
    Lg7 = 1.479819860511658591e-01;

static double zero;


extern double lbl_80560AE0;
extern double lbl_80560AD0;
extern double lbl_80560A98;
extern double __kernel_tan(int, double, double);
extern int __ieee754_rem_pio2(double, double *);


extern unsigned char lbl_802FE850[];
extern double lbl_805609D8, lbl_805609E0, lbl_805609E8, lbl_805609F0, lbl_805609F8, lbl_80560A00, lbl_80560A08;
void fn_8002B0D8(unsigned char *s) {
    register unsigned char *p = s;
    register unsigned char *base = lbl_802FE850;
    register int c;
    register int skip;

    goto check;
loop:
    c = (signed char)*p;
    skip = 0;
    if (c < 0 || c >= 256) skip = 1;
    if (skip != 0) goto store;
    c = *(unsigned char *)(*(unsigned int *)(*(unsigned int *)(base + 0x38) + 0x10) + c);
store:
    *p = (unsigned char)c;
    p++;
check:
    c = (signed char)*p;
    if (c != 0) goto loop;
}

int stricmp(unsigned char *a, unsigned char *b) {
    register int base = (int)(unsigned char *)lbl_802FE850;
    register int locale;
    register signed char c1;
    register signed char c2;
    register int skip;

    locale = *(int *)(base + 0x38);
    for (;;) {
        skip = 0;
        c1 = (signed char)*a;
        a++;
        if (c1 < 0 || c1 >= 256) skip = 1;
        if (skip != 0) goto cont;
        c1 = (signed char)*(unsigned char *)(*(int *)(locale + 0x10) + c1);
    cont:
        skip = 0;
        c2 = (signed char)*b;
        b++;
        if (c2 < 0 || c2 >= 256) skip = 1;
        if (skip != 0) goto cont2;
        c2 = (signed char)*(unsigned char *)(*(int *)(locale + 0x10) + c2);
    cont2:
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        if (c1 == 0) return 0;
    }
}

void fn_8002B1D8(void) {
    fn_800248A4();
}

extern double fn_8002F234(double);

/* MSL e_acos.c constants (see src/MSL/e_acos.c); the game's .sdata2 keeps
 * them unnamed, so alias them to the reference names. */
#define acos_zero      lbl_80560600 /*  0.0: acos(1) */
#define acos_pi        lbl_80560608 /*  pi + 2.0*pio2_lo: acos(-1) */
#define acos_pio2_hi   lbl_80560610 /*  1.57079632679489655800e+00 */
#define acos_pS0       lbl_80560618 /*  1.66666666666666657415e-01 */
#define acos_pS1       lbl_80560620 /* -3.25565818622400915405e-01 */
#define acos_pS2       lbl_80560628 /*  2.01212532134862925881e-01 */
#define acos_pS3       lbl_80560630 /* -4.00555345006794114027e-02 */
#define acos_pS4       lbl_80560638 /*  7.91534994289814532176e-04 */
#define acos_pS5       lbl_80560640 /*  3.47933107596021167570e-05 */
#define acos_one       lbl_80560648 /*  1.0 */
#define acos_qS1       lbl_80560650 /* -2.40339491173441421878e+00 */
#define acos_qS2       lbl_80560658 /*  2.02094576023350569471e+00 */
#define acos_qS3       lbl_80560660 /* -6.88283971605453293030e-01 */
#define acos_qS4       lbl_80560668 /*  7.70381505559019352791e-02 */
#define acos_pio2_lo   lbl_80560670 /*  6.12323399573676603587e-17 */
#define acos_half      lbl_80560678 /*  0.5 */
#define acos_nan       (*(float *)&lbl_80558DB0) /* MSL NAN: a float quiet NaN */
#define acos_sqrt      fn_8002F234               /* sqrt(): b __ieee754_sqrt */

/* acos(x), from MSL's e_acos.c: pi/2 - asin(x), evaluated with e_asin.c's
 * rational R(z) = pS(z)/qS(z).  |x| <= 0.5 uses it on x*x directly; past 0.5
 * the argument is folded to z = (1 -+ x)/2 and s = sqrt(z) so the result stays
 * accurate against the endpoints.  |x| > 1 gives NaN, |x| == 1 gives 0 or pi. */
double __ieee754_acos(double x) {
    double z, p, q, r, w, s, c, df;
    int hx, ix;

    hx = __HI(x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) { /* |x| >= 1 */
        if (((ix - 0x3ff00000) | __LO(x)) == 0) {
            /* |x|==1 */
            if (hx > 0)
                return acos_zero; /* acos(1) = 0 */
            else
                return acos_pi; /* acos(-1) = pi */
        }
        return acos_nan; /* acos(|x|>1) is NaN */
    }
    if (ix < 0x3fe00000) { /* |x| < 0.5 */
        if (ix <= 0x3c600000)
            return acos_pio2_hi; /* |x| < 2**-57: pi/2 (the + pio2_lo rounds away) */
        z = x * x;
        p = z * (acos_pS0 + z * (acos_pS1 + z * (acos_pS2 + z * (acos_pS3 + z * (acos_pS4 + acos_pS5 * z)))));
        q = acos_one + z * (acos_qS1 + z * (acos_qS2 + z * (acos_qS3 + acos_qS4 * z)));
        r = p / q;
        return acos_pio2_hi - (x - (acos_pio2_lo - x * r));
    } else if (hx < 0) { /* x < -0.5 */
        z = (acos_one + x) * acos_half;
        p = z * (acos_pS0 + z * (acos_pS1 + z * (acos_pS2 + z * (acos_pS3 + z * (acos_pS4 + acos_pS5 * z)))));
        q = acos_one + z * (acos_qS1 + z * (acos_qS2 + z * (acos_qS3 + acos_qS4 * z)));
        s = acos_sqrt(z);
        r = p / q;
        w = r * s - acos_pio2_lo;
        return acos_pi - 2.0 * (s + w);
    } else { /* x > 0.5 */
        z = (acos_one - x) * acos_half;
        s = acos_sqrt(z);
        df = s;
        __LO(df) = 0; /* df = high part of sqrt(z) */
        c = (z - df * df) / (s + df); /* correction so df + c ~ sqrt(z) */
        p = z * (acos_pS0 + z * (acos_pS1 + z * (acos_pS2 + z * (acos_pS3 + z * (acos_pS4 + acos_pS5 * z)))));
        q = acos_one + z * (acos_qS1 + z * (acos_qS2 + z * (acos_qS3 + acos_qS4 * z)));
        r = p / q;
        w = r * s + c;
        return 2.0 * (df + w);
    }
}

double __ieee754_asin(x)
double x;
{
    double t, w, p, q, c, r, s;
    int hx, ix;

    hx = __HI(x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        if (((ix - 0x3ff00000) | __LO(x)) == 0)
            return lbl_80560688 * x + lbl_80560690 * x;
        return *(float *)&lbl_80558DB0;
    } else if (ix < 0x3fe00000) {
        if (ix < 0x3e400000) {
            if (lbl_80560698 + x > lbl_805606A0)
                return x;
        } else
            t = x * x;
        p = t * (lbl_805606A8 + t * (lbl_805606B0 + t * (lbl_805606B8 + t * (lbl_805606C0 + t * (lbl_805606C8 + lbl_805606D0 * t)))));
        q = lbl_805606A0 + t * (lbl_805606D8 + t * (lbl_805606E0 + t * (lbl_805606E8 + lbl_805606F0 * t)));
        r = p / q;
        *(volatile double *)&w = r;
        return x + x * r;
    }
    w = lbl_805606A0 - __fabs(x);
    t = lbl_805606F8 * w;
    p = t * (lbl_805606A8 + t * (lbl_805606B0 + t * (lbl_805606B8 + t * (lbl_805606C0 + t * (lbl_805606C8 + lbl_805606D0 * t)))));
    q = lbl_805606A0 + t * (lbl_805606D8 + t * (lbl_805606E0 + t * (lbl_805606E8 + lbl_805606F0 * t)));
    s = fn_8002F234(t);
    if (ix >= 0x3FEF3333) {
        r = p / q;
        *(volatile double *)&w = r;
        t = lbl_80560688 - (lbl_80560700 * (s + s * r) - lbl_80560690);
    } else {
        w = s;
        __LO(w) = 0;
        c = (t - w * w) / (s + w);
        r = p / q;
        p = r * (lbl_80560700 * s) - (lbl_80560690 - lbl_80560700 * c);
        q = lbl_80560708 - lbl_80560700 * w;
        t = lbl_80560708 - (p - q);
    }
    if (hx > 0)
        return t;
    else
        return -t;
}

extern double atan(double);
extern double fabs(double);
extern double __fabs(double);
double __ieee754_atan2(y, x)
double y, x;
{
    static const double
        tiny = 1.0e-300,
        zero = 0.0,
        pi_o_4 = 7.8539816339744827900E-01,
        pi_o_2 = 1.5707963267948965580E+00,
        pi = 3.1415926535897931160E+00,
        pi_lo = 1.2246467991473531772E-16;

    double z;
    int k, m, hx, hy, ix, iy;
    unsigned lx, ly;

    hx = __HI(x);
    ix = hx & 0x7fffffff;
    lx = __LO(x);
    hy = __HI(y);
    iy = hy & 0x7fffffff;
    ly = __LO(y);
    if (((ix | ((lx | -lx) >> 31)) > 0x7ff00000) ||
        ((iy | ((ly | -ly) >> 31)) > 0x7ff00000))
        return x + y;
    if ((hx - 0x3ff00000 | lx) == 0)
        return atan(y);
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if ((iy | ly) == 0) {
        switch (m) {
        case 0:
        case 1:
            return y;
        case 2:
            return pi + tiny;
        case 3:
            return -pi - tiny;
        }
    }
    if ((ix | lx) == 0)
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
            case 0:
                return pi_o_4 + tiny;
            case 1:
                return -pi_o_4 - tiny;
            case 2:
                return 3.0 * pi_o_4 + tiny;
            case 3:
                return -3.0 * pi_o_4 - tiny;
            }
        } else {
            switch (m) {
            case 0:
                return zero;
            case 1:
                return -zero;
            case 2:
                return pi + tiny;
            case 3:
                return -pi - tiny;
            }
        }
    }
    if (iy == 0x7ff00000)
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

    k = (iy - ix) >> 20;
    if (k > 60)
        z = pi_o_2 + 0.5 * pi_lo;
    else if (hx < 0 && k < -60)
        z = 0.0;
    else
        z = atan(__fabs(y / x));
    switch (m) {
    case 0:
        return z;
    case 1:
        __HI(z) ^= 0x80000000;
        return z;
    case 2:
        return pi - (z - pi_lo);
    default:
        return (z - pi_lo) - pi;
    }
}

// fdlibm's Zero[] = {0.0, -0.0}; Zero[(unsigned)sx >> 31] is sign(x)*0
#define Zero lbl_802EE4C8
extern double Zero[];
/*
 * __ieee754_fmod(x,y)  (fdlibm e_fmod.c)
 * Return x mod y in exact arithmetic: the remainder of x/y with the sign of x,
 * computed on the IEEE-754 bits of x and y as integer words (hx/lx = high/low
 * word of |x|, hy/ly = of |y|, sx = sign bit of x, ix/iy = their exponents).
 * Method: shift and subtract - scale |x| and |y| up to 1.52 fixed point,
 * subtract y from x repeatedly, then renormalise the result.
 */
double __ieee754_fmod(double x, double y) {
    int n, hx, hy, hz, ix, iy, sx, i;
    unsigned int lx, ly, lz;

    hx = __HI(x);   /* high word of x */
    lx = __LO(x);   /* low  word of x */
    hy = __HI(y);   /* high word of y */
    ly = __LO(y);   /* low  word of y */
    sx = hx & 0x80000000; /* sign of x */
    hx ^= sx;       /* |x| */
    hy &= 0x7FFFFFFF; /* |y| */

    /* purge off exception values */
    if (((hy | ly) == 0) ||        /* y = 0, or */
        (hx >= 0x7FF00000) ||      /* x not finite, or */
        ((hy | ((ly | -ly) >> 31)) > 0x7FF00000U)) { /* y is NaN */
        return (x * y) / (x * y);  /* NaN */
    }
    if (hx <= hy) {
        if ((hx < hy) || (lx < ly)) {
            return x;              /* |x| < |y|: return x */
        }
        if (lx == ly) {
            return Zero[(unsigned int)sx >> 31]; /* |x| = |y|: return sign(x)*0 */
        }
    }

    /* determine ix = ilogb(x) */
    if (hx < 0x00100000) { /* subnormal x */
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1) {
                ix -= 1;
            }
        } else {
            for (ix = -1022, i = hx << 11; i > 0; i <<= 1) {
                ix -= 1;
            }
        }
    } else {
        ix = (hx >> 20) - 1023;
    }
    /* determine iy = ilogb(y) */
    if (hy < 0x00100000) { /* subnormal y */
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1) {
                iy -= 1;
            }
        } else {
            for (iy = -1022, i = hy << 11; i > 0; i <<= 1) {
                iy -= 1;
            }
        }
    } else {
        iy = (hy >> 20) - 1023;
    }

    /* set up {hx,lx}, {hy,ly} and align y to x */
    if (ix >= -1022) {
        hx = 0x00100000 | (0x000FFFFF & hx); /* 1.52 fixed point */
    } else { /* subnormal x, shift x to normal */
        n = -1022 - ix;
        if (n <= 31) {
            hx = (hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else {
            hx = lx << (n - 32);
            lx = 0;
        }
    }
    if (iy >= -1022) {
        hy = 0x00100000 | (0x000FFFFF & hy);
    } else { /* subnormal y, shift y to normal */
        n = -1022 - iy;
        if (n <= 31) {
            hy = (hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else {
            hy = ly << (n - 32);
            ly = 0;
        }
    }

    /* fix point fmod */
    n = ix - iy; /* number of subtract-and-shift steps */
    while (n--) {
        hz = hx - hy; /* x - y, 64 bits */
        lz = lx - ly;
        if (lx < ly) {
            hz -= 1; /* borrow */
        }
        if (hz < 0) { /* x < y: shift x up and try again */
            hx = hx + hx + (lx >> 31);
            lx = lx + lx;
        } else {
            if ((hz | lz) == 0) {
                return Zero[(unsigned int)sx >> 31]; /* exact: sign(x)*0 */
            }
            hx = hz + hz + (lz >> 31); /* x = (x - y) shifted up */
            lx = lz + lz;
        }
    }
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly) {
        hz -= 1;
    }
    if (hz >= 0) { /* one last subtraction fits */
        hx = hz;
        lx = lz;
    }

    /* convert back to floating value and restore the sign */
    if ((hx | lx) == 0) {
        return Zero[(unsigned int)sx >> 31]; /* sign(x)*0 */
    }
    while (hx < 0x00100000) { /* normalize x */
        hx = hx + hx + (lx >> 31);
        lx = lx + lx;
        iy -= 1;
    }
    if (iy >= -1022) { /* normal output */
        hx = (hx - 0x00100000) | ((iy + 1023) << 20);
        __HI(x) = hx | sx;
        __LO(x) = lx;
    } else { /* subnormal output */
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((unsigned int)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = (hx << (32 - n)) | (lx >> n);
            hx = sx;
        } else {
            lx = hx >> (n - 32);
            hx = sx;
        }
        __HI(x) = hx | sx;
        __LO(x) = lx;
    }
    return x; /* exact output */
}
#undef Zero

double __ieee754_log(x)
double x;
{
	double hfsq,f,s,z,R,w,t1,t2,dk;
	int k,hx,i,j;
	unsigned lx;

	hx = __HI(x);
	lx = __LO(x);

	k=0;
	if (hx < 0x00100000) {
	    if (((hx&0x7fffffff)|lx)==0)
		return -two54/zero;
	    if (hx<0) { errno = EDOM; return (x-x)/zero; }
	    k -= 54; x *= two54;
	    hx = __HI(x);
	}
	if (hx >= 0x7ff00000) return x+x;
	k += (hx>>20)-1023;
	hx &= 0x000fffff;
	i = (hx+0x95f64)&0x100000;
	__HI(x) = hx|(i^0x3ff00000);
	k += (i>>20);
	f = x-1.0;
	if((0x000fffff&(2+hx))<3) {
	    if(f==zero) { if(k==0) return zero;  else {dk=(double)k;
				 return dk*ln2_hi+dk*ln2_lo;}
	    }
	    R = f*f*(0.5-0.33333333333333333*f);
	    if(k==0) return f-R; else {dk=(double)k;
	    	     return dk*ln2_hi-((R-dk*ln2_lo)-f);}
	}
 	s = f/(2.0+f);
	dk = (double)k;
	z = s*s;
	i = hx-0x6147a;
	w = z*z;
	j = 0x6b851-hx;
	t1= w*(Lg2+w*(Lg4+w*Lg6));
	t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
	i |= j;
	R = t2+t1;
	if(i>0) {
	    hfsq=0.5*f*f;
	    if(k==0) return f-(hfsq-s*(hfsq+R)); else
		     return dk*ln2_hi-((hfsq-(s*(hfsq+R)+dk*ln2_lo))-f);
	} else {
	    if(k==0) return f-s*(f-R); else
		     return dk*ln2_hi-((s*(f-R)-dk*ln2_lo)-f);
	}
}

/* Constants of fdlibm's e_rem_pio2.c (see the reference copy in
 * src/MSL/e_rem_pio2.c); the game keeps them in .sdata2 / .rodata, so they
 * are only reachable through these labels. Aliased with macros -- the game's
 * data symbols cannot be renamed yet -- and #undef'd after the function that
 * uses them so the rest of the file is untouched. */
extern const double lbl_805608F8, lbl_80560900, lbl_80560908, lbl_80560910, lbl_80560918, lbl_80560920, lbl_80560928, lbl_80560930, lbl_80560938, lbl_80560940;
extern const int lbl_802EE508[], lbl_802EE610[];

#define pio2_zero      lbl_805608F8 /*  0.0 */
#define pio2_1         lbl_80560900 /*  0x3FF921FB, 0x54400000: first 33 bits of pi/2 */
#define pio2_1t        lbl_80560908 /*  pi/2 - pio2_1 */
#define pio2_2         lbl_80560910 /*  next 33 bits of pi/2 */
#define pio2_2t        lbl_80560918 /*  pi/2 - (pio2_1+pio2_2) */
#define pio2_half      lbl_80560920 /*  0.5, for rounding t*2/pi to the nearest int */
#define pio2_invpio2   lbl_80560928 /*  53 bits of 2/pi */
#define pio2_3         lbl_80560930 /*  third 33 bits of pi/2 */
#define pio2_3t        lbl_80560938 /*  pi/2 - (pio2_1+pio2_2+pio2_3) */
#define pio2_two24     lbl_80560940 /*  2^24, scales the chunks of x apart */
#define pio2_two_over_pi lbl_802EE508 /* 396 hex digits of 2/pi, 24 bits per int */
#define pio2_npio2_hw  lbl_802EE610 /* high words of n*pi/2, n = 1..32: exact halfway cases */
#pragma push
#pragma opt_common_subs off
/*
 * __ieee754_rem_pio2(x, y) -- fdlibm argument reduction for sin/cos/tan.
 *
 * Reduces x modulo pi/2 and returns the remainder as an unevaluated sum
 * y[0] + y[1]; the return value is the number n of quarter turns, signed like
 * x, with x ~= n*pi/2 + y[0] + y[1].  |x| below pi/4 needs nothing, below
 * 3pi/4 it is one subtraction of pi/2, up to 2^19*pi/2 the 33+33+33-bit
 * pieces of pi/2 are subtracted one round at a time until no bits cancel, and
 * anything larger is split into 24-bit chunks for __kernel_rem_pio2() and the
 * 2/pi table.  See the reference source in src/MSL/e_rem_pio2.c.
 */
int __ieee754_rem_pio2(double x, double *y)
{
	double z,w,t,r,fn;	/* z: x shifted / reduced, r-w: the remainder, fn: n as a double */
	double tx[3];		/* |x| split into three 24-bit chunks for the kernel */
	int e0,i,j,nx,n,hx; register int ix;	/* hx: high word of x, ix: |x| without its sign */

	hx = __HI(x);		/* high word of x */
	ix = hx&0x7fffffff;
	if(ix<=0x3fe921fb)   /* |x| ~<= pi/4 , no need for reduction */
	    {y[0] = x; y[1] = pio2_zero; return 0;}
	if(ix<0x4002d97c) {  /* |x| < 3pi/4, special case with n=+-1 */
	    if(hx>0) { 
		z = x - pio2_1; *(volatile double *)&z = z;	/* keep z rounded to memory */
		if(ix!=0x3ff921fb) { 	/* 33+53 bit pi is good enough */
		    y[0] = z - pio2_1t;
		    y[1] = (z-y[0])-pio2_1t;
		} else {		/* near pi/2, use 33+33+53 bit pi */
		    z -= pio2_2; *(volatile double *)&z = z;
		    y[0] = z - pio2_2t;
		    y[1] = (z-y[0])-pio2_2t;
		}
		return 1;
	    } else {	/* negative x */
		z = pio2_1 + x; *(volatile double *)&z = z;
		if(ix!=0x3ff921fb) { 	/* 33+53 bit pi is good enough */
		    y[0] = pio2_1t + z;
		    y[1] = (z-y[0])+pio2_1t;
		} else {		/* near pi/2, use 33+33+53 bit pi */
		    z += pio2_2; *(volatile double *)&z = z;
		    y[0] = pio2_2t + z;
		    y[1] = (z-y[0])+pio2_2t;
		}
		return -1;
	    }
	}
	if(ix<=0x413921fb) { /* |x| ~<= 2^19*(pi/2), medium size */
	    t  = __fabs(x);
	    n  = (int) (pio2_half+pio2_invpio2*t);	/* nearest number of quarter turns */
	    fn = (double)n;
	    r  = t-pio2_1*fn;
	    w  = pio2_1t*fn;	/* 1st round good to 85 bit */
	    if(n<32&&ix!=pio2_npio2_hw[n-1]) {	/* not an exact n*pi/2 high word */
		y[0] = r-w;	/* quick check no cancellation */
	    } else {
	        j  = ix>>20;	/* exponent of x */
	        y[0] = r-w; 
	        i = j-(((__HI(y[0]))>>20)&0x7ff);	/* bits lost to cancellation */
	        if(i>16) {  /* 2nd iteration needed, good to 118 */
		    t  = r;
		    w  = pio2_2*fn;	
		    r  = t-w;
		    w  = pio2_2t*fn-((t-r)-w);	
		    y[0] = r-w;
		    i = j-(((__HI(y[0]))>>20)&0x7ff);
		    if(i>49)  {	/* 3rd iteration need, 151 bits acc */
		    	t  = r;	/* will cover all possible cases */
		    	w  = pio2_3*fn;	
		    	r  = t-w;
		    	w  = pio2_3t*fn-((t-r)-w);	
		    	y[0] = r-w;
		    }
		}
	    }
	    y[1] = (r-y[0])-w;
	    if(hx<0) 	{y[0] = -y[0]; y[1] = -y[1]; return -n;}
	    else	 return n;
	}
    /* 
     * all other (large) arguments
     */
	if(ix>=0x7ff00000) {		/* x is inf or NaN */
	    y[0]=y[1]=x-x; return 0;
	}
    /* set z = scalbn(|x|,ilogb(x)-23) */
	__LO(z) = __LO(x);
	e0 	= (ix>>20)-1046;	/* e0 = ilogb(z)-23; */
	__HI(z) = ix - (e0<<20);
	for(i=0;i<2;i++) {		/* peel two 24-bit integer chunks off z */
		tx[i] = (double)((int)(z));
		z     = (z-tx[i])*pio2_two24;
	}
	*(volatile double *)&z = z; tx[2] = z;	/* last chunk, through memory */
	nx = 3;
	while(tx[nx-1]==pio2_zero) nx--;	/* skip zero term */
	n  =  __kernel_rem_pio2(tx,y,e0,nx,2,pio2_two_over_pi);
	if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
	return n;
}
#pragma pop
#undef pio2_zero
#undef pio2_1
#undef pio2_1t
#undef pio2_2
#undef pio2_2t
#undef pio2_half
#undef pio2_invpio2
#undef pio2_3
#undef pio2_3t
#undef pio2_two24
#undef pio2_two_over_pi
#undef pio2_npio2_hw
extern double lbl_80560950, lbl_80560958, lbl_80560960, lbl_80560968, lbl_80560970, lbl_80560978, lbl_80560980, lbl_80560988, lbl_80560990;
double __kernel_cos(double x, double y) {
    double a, hz, z, r, qx;
    int ix, hx;

    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0) return lbl_80560950;
    }
    z = x * x;
    r = z * (lbl_80560958 + z * (lbl_80560960 + z * (lbl_80560968 + z * (lbl_80560970 + z * (lbl_80560978 + lbl_80560980 * z)))));
    if (ix < 0x3fd33333) {
        return lbl_80560950 - (lbl_80560988 * z - (z * r - x * y));
    } else {
        if (ix > 0x3fe90000) {
            qx = lbl_80560990;
        } else {
            ((int *)&qx)[0] = ix - 0x00200000;
            ((int *)&qx)[1] = 0;
        }
        hz = lbl_80560988 * z - qx;
        a = lbl_80560950 - qx;
        return a - (hz - (z * r - x * y));
    }
}

extern int lbl_802EE690[];
extern double lbl_802EE6A0[];
extern double lbl_80560998,lbl_805609C8,lbl_805609A8,lbl_805609A0;
extern double fn_8002B060(int,double);
extern double floor(double);
int __kernel_rem_pio2(double *x,double *y,int e0,int nx,int prec,const int *ipio2)
{
	int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	double z,fw,f[20],fq[20],q[20];

    /* initialize jk*/
	jk = lbl_802EE690[prec];
	jp = jk;

    /* determine jx,jv,q0, note that 3>q0 */
	jx =  nx-1;
	jv = (e0-3)/24; if(jv<0) jv=0;
	q0 =  e0-24*(jv+1);

    /* set up f[0] to f[jx+jk] where f[jx+jk] = ipio2[jv+jk] */
	j = jv-jx; m = jx+jk;
	for(i=0;i<=m;i++,j++) f[i] = (j<0)? 0.0 : (double) ipio2[j];

    /* compute q[0],q[1],...q[jk] */
	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
    /* distill q[] into iq[] reversingly */
	for(i=0,j=jz,z=q[jz];j>0;i++,j--) {
	    fw    =  (double)((int)(5.9604644775390625e-8* z));
	    iq[i] =  (int)(z-16777216.0*fw);
	    z     =  q[j-1]+fw;
	}

    /* compute n */
	z  = fn_8002B060(q0,z);		/* actual value of z */
	z -= 8.0*floor(z*0.125);		/* trim off integer >= 8 */
	n  = (int) z;
	z -= (double)n;
	ih = 0;
	if(q0>0) {	/* need iq[jz-1] to determine n */
	    i  = (iq[jz-1]>>(24-q0)); n += i;
	    iq[jz-1] -= i<<(24-q0);
	    ih = iq[jz-1]>>(23-q0);
	} 
	else if(q0==0) ih = iq[jz-1]>>23;
	else if(z>=0.5) ih=2;

	if(ih>0) {	/* q > 0.5 */
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {	/* compute 1-q */
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x1000000- j;
		    }
		} else  iq[i] = 0xffffff - j;
	    }
	    if(q0>0) {		/* rare case: chance is 1 in 12 */
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7fffff; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3fffff; break;
	        }
	    }
	    if(ih==2) {
		z = 1.0 - z;
		if(carry!=0) z -= fn_8002B060(q0,1.0);
	    }
	}

    /* check if recomputation is needed */
	if(z==0.0) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) { /* need recomputation */
		for(k=1;iq[jk-k]==0;k++);   /* k = no. of terms needed */

		for(i=jz+1;i<=jz+k;i++) {   /* add q[jz+1] to q[jz+k] */
		    f[jx+i] = (double) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

    /* chop off 0.0 terms */
	if(z==0.0) {
	    jz -= 1; q0 -= 24;
	    while(iq[jz]==0) { jz--; q0-=24;}
	} else { /* break z into 24-bit if necessary */
	    z = fn_8002B060(-q0,z);
	    if(z>=16777216.0) { 
		fw = (double)((int)(5.9604644775390625e-8*z));
		iq[jz] = (int)(z-16777216.0*fw);
		jz += 1; q0 += 24;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

    /* convert integer "bit" chunk to floating-point value */
	fw = fn_8002B060(q0,1.0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(double)iq[i]; fw*=5.9604644775390625e-8;
	}

    /* compute lbl_802EE6A0[0,...,jp]*q[jz,...,0] */
	for(i=jz;i>=0;i--) {
	    for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += lbl_802EE6A0[k]*q[i+k];
	    fq[jz-i] = fw;
	}

    /* compress fq[] into y[] */
	switch(prec) {
	    case 0:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw; 
		break;
	    case 1:
	    case 2:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i]; 
		y[0] = (ih==0)? fw: -fw; 
		fw = fq[0]-fw;
		for (i=1;i<=jz;i++) fw += fq[i];
		y[1] = (ih==0)? fw: -fw; 
		break;
	    case 3:	/* painful */
		for (i=jz;i>0;i--) {
		    fw      = fq[i-1]+fq[i]; 
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (i=jz;i>1;i--) {
		    fw      = fq[i-1]+fq[i]; 
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (fw=0.0,i=jz;i>=2;i--) fw += fq[i]; 
		if(ih==0) {
		    y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
		} else {
		    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
		}
	}
	return n&7;
}

double __kernel_sin(int iy, double x, double y) {
    double z, v, r;
    int hx;
    z = x;
    hx = *(int *)&z & 0x7fffffff;
    if (hx < 0x3e400000 && (int)x == 0) return x;
    z = x * x;
    v = z * x;
    r = lbl_805609D8 + z * (lbl_805609E0 + z * (lbl_805609E8 + z * (lbl_805609F0 + lbl_805609F8 * z)));
    if (iy == 0)
        return x + v * (lbl_80560A00 + z * r);
    return x - ((z * (lbl_80560A08 * y - v * r) - y) - lbl_80560A00 * v);
}

extern double lbl_802EE748[];
extern double lbl_80560A48, lbl_80560A50, lbl_80560A58, lbl_80560A60, lbl_80560A68;
double atan(double x) {
    double w, s1, s2, z, t;
    int ix, hx, id;
    double *atanhi = lbl_802EE748;
    double *atanlo = lbl_802EE748 + 4;
    double *aT = lbl_802EE748 + 8;
    hx = __HI(x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x44100000) {
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && (__LO(x) != 0)))
            return x + x;
        if (hx > 0)
            return atanhi[3] + atanlo[3];
        else
            return -atanhi[3] - atanlo[3];
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000) {
            if (lbl_80560A48 + x > lbl_80560A50)
                return x;
        }
        id = -1;
    } else {
        t = __fabs(x);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                x = (lbl_80560A58 * t - lbl_80560A50) / (lbl_80560A58 + t);
            } else {
                id = 1;
                x = (t - lbl_80560A50) / (lbl_80560A50 + t);
            }
        } else {
            if (ix < 0x40038000) {
                id = 2;
                x = (t - lbl_80560A60) / (lbl_80560A50 + lbl_80560A60 * t);
            } else {
                id = 3;
                x = lbl_80560A68 / t;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0)
        return x - x * (s1 + s2);
    z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
    return (hx < 0) ? -z : z;
}

double ceil(double x) {
    int i0, i1, j0;
    unsigned i, j;
    union { double d; int w[2]; } u;
    u.d = x;
    i0 = u.w[0];
    i1 = u.w[1];
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {	/* raise inexact if x != 0 */
            if (huge + x > 0.0) {	/* return 0*sign(x) if |x|<1 */
                if (i0 < 0) { i0 = 0x80000000; i1 = 0; }
                else if ((i0 | i1) != 0) { i0 = 0x3ff00000; i1 = 0; }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) return x;	/* x is integral */
            if (huge + x > 0.0) {	/* raise inexact flag */
                if (i0 > 0) i0 += (0x00100000) >> j0;
                i0 &= (~i); i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) return x + x;	/* inf or NaN */
        else return x;		/* x is integral */
    } else {
        i = ((unsigned)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) return x;	/* x is integral */
        if (huge + x > 0.0) {		/* raise inexact flag */
            if (i0 > 0) {
                if (j0 == 20) i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1) i0 += 1;	/* got a carry */
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    u.w[0] = i0;
    u.w[1] = i1;
    return u.d;
}

#pragma dont_inline on
double copysign(double x, double y) {
    union { double d; unsigned int i[2]; } b, a;
    a.d = x;
    b.d = y;
    a.i[0] = (a.i[0] & 0x7fffffff) | (b.i[0] & 0x80000000);
    return a.d;
}
#pragma dont_inline reset

extern double lbl_80560A80;
extern double __kernel_cos(double, double);
extern double __kernel_sin(int, double, double);
__declspec(section ".sdata") extern double lbl_80560A80;
#pragma push
#pragma dont_inline on
#pragma scheduling 750
double cos(double x) {
    double y[2];
    int n, ix;

    ix = *(int *)&x;
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) return __kernel_cos(x, lbl_80560A80);
    else if (ix >= 0x7ff00000) return x - x;
    else {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3) {
        case 0: return __kernel_cos(y[0], y[1]);
        case 1: return -__kernel_sin(1, y[0], y[1]);
        case 2: return -__kernel_cos(y[0], y[1]);
        default: return __kernel_sin(1, y[0], y[1]);
        }
    }
}
#pragma pop
double floor(double x) {
    int i0, i1, j0;
    unsigned i, j;
    union { double d; int w[2]; } u;
    u.d = x;
    i0 = u.w[0];
    i1 = u.w[1];
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {	/* raise inexact if x != 0 */
            if (huge + x > 0.0) {	/* return 0*sign(x) if |x|<1 */
                if (i0 >= 0) { i0 = i1 = 0; }
                else if (((i0 & 0x7fffffff) | i1) != 0) { i0 = 0xbff00000; i1 = 0; }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) return x;	/* x is integral */
            if (huge + x > 0.0) {	/* raise inexact flag */
                if (i0 < 0) i0 += (0x00100000) >> j0;
                i0 &= (~i); i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) return x + x;	/* inf or NaN */
        else return x;		/* x is integral */
    } else {
        i = ((unsigned)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) return x;	/* x is integral */
        if (huge + x > 0.0) {		/* raise inexact flag */
            if (i0 < 0) {
                if (j0 == 20) i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1) i0 += 1;	/* got a carry */
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    u.w[0] = i0;
    u.w[1] = i1;
    return u.d;
}

double frexp(double x, int *eptr) {
    union { double d; unsigned int i[2]; } u;
    int highWord;
    int absHigh;
    int lowWord;

    u.d = x;
    highWord = u.i[0];
    absHigh = highWord & 0x7fffffff;
    lowWord = u.i[1];
    *eptr = 0;
    if (absHigh < 0x7ff00000) {
        if ((absHigh | lowWord) == 0)
            return x;
        if (absHigh < 0x00100000) {
            double scale = lbl_80560A98;
            *(volatile int *)eptr = -54;
            u.d *= scale;
            highWord = u.i[0];
            absHigh = highWord & 0x7fffffff;
        }
        *eptr += (absHigh >> 20) - 0x3fe;
        u.i[0] = (highWord & 0x800fffff) | 0x3fe00000;
        return u.d;
    }
    return x;
}

extern int __fpclassifyd(double);
extern double copysign(double, double);
extern double lbl_80560AA0, lbl_80560AA8, lbl_80560AB0, lbl_80560AB8, lbl_80560AC0;
#pragma dont_inline copysign
double ldexp(double x, int n) {
    int exp;
    int hx, lx;

    if (__fpclassifyd(x) <= 2 || lbl_80560AA0 == x)
        return x;

    hx = *(int *)&x;
    lx = ((int *)&x)[1];
    exp = (hx >> 20) & 0x7FF;

    if (exp == 0) {
        if ((lx | (hx & 0x7FFFFFFF)) == 0)
            return x;
        x *= lbl_80560AA8;
        hx = *(int *)&x;
        exp = ((hx >> 20) & 0x7FF) - 0x36;
        if (n < -50000)
            return lbl_80560AB0 * x;
    }

    if (exp == 0x7FF)
        return x + x;

    exp += n;
    if (exp > 0x7FE)
        return lbl_80560AB8 * copysign(lbl_80560AB8, x);

    if (exp > 0) {
        *(int *)&x = (hx & 0x800FFFFF) | (exp << 20);
        return x;
    }

    if (exp <= -0x36) {
        if (n > 50000)
            return lbl_80560AB8 * copysign(lbl_80560AB8, x);
        return lbl_80560AB0 * copysign(lbl_80560AB0, x);
    }

    exp += 0x36;
    *(int *)&x = (hx & 0x800FFFFF) | (exp << 20);
    return lbl_80560AC0 * x;
}
__declspec(section ".sdata") extern double lbl_80560AC8;
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
double sin(double x) {
    double y[2];
    int n, ix;

    ix = *(int *)&x;
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) return __kernel_sin(0, x, lbl_80560AC8);
    else if (ix >= 0x7ff00000) return x - x;
    else {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3) {
        case 0: return __kernel_sin(1, y[0], y[1]);
        case 1: return __kernel_cos(y[0], y[1]);
        case 2: return -__kernel_sin(1, y[0], y[1]);
        default: return -__kernel_cos(y[0], y[1]);
        }
    }
}
#pragma pop
double fn_8002EF30(double x) {
    int hx;
    double y[2];
    hx = *(int *)&x & 0x7fffffff;
    if (hx <= 0x3fe921fb) return __kernel_tan(1, x, 0.0);
    if (hx >= 0x7ff00000) return x - x;
    hx = __ieee754_rem_pio2(x, y);
    return __kernel_tan(1 - ((hx & 1) << 1), y[0], y[1]);
}

extern double __ieee754_acos(double);

double fn_8002EFA8(double x) {
    return __ieee754_acos(x);
}

void fn_8002EFAC(void) {
    __ieee754_asin();
}

void fn_8002EFB0(void) {
    __ieee754_atan2();
}

extern double __ieee754_fmod(double, double);

double fn_8002EFB4(double x, double y) {
    return __ieee754_fmod(x, y);
}

double fn_8002EFB8(void) {
    return __ieee754_log();
}

void fn_8002EFBC(void) {
    __ieee754_pow();
}

extern unsigned long __float_nan[];
double __ieee754_sqrt(double x)
{
    double z;
    int sign = (int)0x80000000;
    unsigned r, t1, s1, ix1, q1;
    int ix0, s0, q, m, t, i;

    ix0 = __HI(x);
    ix1 = __LO(x);

    if ((ix0 & 0x7ff00000) == 0x7ff00000) {
        errno = EDOM;
        return x * x + x;
    }
    if (ix0 <= 0) {
        if (((ix0 & (~sign)) | ix1) == 0) return x;
        else if (ix0 < 0) {
            errno = EDOM;
            return *(float*)&__float_nan;
        }
    }
    m = (ix0 >> 20);
    if (m == 0) {
        while (ix0 == 0) {
            m -= 21;
            ix0 |= (ix1 >> 11);
            ix1 <<= 21;
        }
        for (i = 0; (ix0 & 0x00100000) == 0; i++) ix0 <<= 1;
        m -= i - 1;
        ix0 |= (ix1 >> (32 - i));
        ix1 <<= i;
    }
    m -= 1023;
    ix0 = (ix0 & 0x000fffff) | 0x00100000;
    if (m & 1) {
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
    }
    m >>= 1;

    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    q = q1 = s0 = s1 = 0;
    r = 0x00200000;

    while (r != 0) {
        t = s0 + r;
        if (t <= ix0) {
            s0 = t + r;
            ix0 -= t;
            q += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    r = sign;
    while (r != 0) {
        t1 = s1 + r;
        t = s0;
        if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
            s1 = t1 + r;
            if (((t1 & sign) == sign) && (s1 & sign) == 0) s0 += 1;
            ix0 -= t;
            if (ix1 < t1) ix0 -= 1;
            ix1 -= t1;
            q1 += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    if ((ix0 | ix1) != 0) {
        z = 1.0 - 1.0e-300;
        if (z >= 1.0) {
            z = 1.0 + 1.0e-300;
            if (q1 == (unsigned)0xffffffff) { q1 = 0; q += 1; }
            else if (z > 1.0) {
                if (q1 == (unsigned)0xfffffffe) q += 1;
                q1 += 2;
            } else
                q1 += (q1 & 1);
        }
    }
    ix0 = (q >> 1) + 0x3fe00000;
    ix1 = q1 >> 1;
    if ((q & 1) == 1) ix1 |= sign;
    ix0 += (m << 20);
    __HI(z) = ix0;
    __LO(z) = ix1;
    return z;
}

double fn_8002F208(void) {
    return lbl_80560AE0 * fn_8002EFB8();
}

void fn_8002F230(void) {

}

extern double lbl_80560600, lbl_80560608, lbl_80560610, lbl_80560670;
extern double lbl_80560618, lbl_80560620, lbl_80560628, lbl_80560630, lbl_80560638, lbl_80560640;
extern double lbl_80560648, lbl_80560650, lbl_80560658, lbl_80560660, lbl_80560668;
extern double lbl_80560678, lbl_80560680;
extern double __ieee754_sqrt(double);
double fn_8002F234(double x) {
    __ieee754_sqrt(x);
}

