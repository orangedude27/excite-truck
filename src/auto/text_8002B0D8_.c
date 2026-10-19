extern double lbl_80560600, lbl_80560608, lbl_80560610, lbl_80560670;
extern double lbl_80560618, lbl_80560620, lbl_80560628, lbl_80560630, lbl_80560638, lbl_80560640;
extern double lbl_80560648, lbl_80560650, lbl_80560658, lbl_80560660, lbl_80560668;
extern double lbl_80560678, lbl_80560680;
extern float lbl_80558DB0;

static const double huge = 1.0e300;

// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

extern double lbl_80560AE0;
extern double lbl_80560AD0;
extern double lbl_80560A98;
extern double __kernel_tan(int, double, double);
extern int __ieee754_rem_pio2(double, double *);


extern unsigned char lbl_802FE850[];
extern double lbl_805609D8, lbl_805609E0, lbl_805609E8, lbl_805609F0, lbl_805609F8, lbl_80560A00, lbl_80560A08;
void fn_8002B0D8(unsigned char *s) {
    unsigned char *p;
    int c;
    p = s;
    while (*p != 0) {
        c = (signed char)*p;
        if (c < 0 || c >= 256) {
        } else {
            c = *(unsigned char *)(*(unsigned int *)(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x10) + c);
            *p = c;
        }
        p++;
    }
}

int stricmp(unsigned char *a, unsigned char *b) {
    int c1, c2;
    unsigned char *tbl;
    tbl = *(unsigned char **)(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x10);
    for (;;) {
        c1 = (signed char)*a;
        a++;
        if (c1 >= 0 && c1 < 256) c1 = tbl[c1];
        c2 = (signed char)*b;
        b++;
        if (c2 >= 0 && c2 < 256) c2 = tbl[c2];
        c1 = (signed char)c1;
        c2 = (signed char)c2;
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        if (!c1) return 0;
    }
}

void fn_8002B1D8(void) {
    fn_800248A4();
}

extern double lbl_80560950, lbl_80560958, lbl_80560960, lbl_80560968, lbl_80560970, lbl_80560978, lbl_80560980, lbl_80560988, lbl_80560990;
double __kernel_cos(double x, double y) {
    double z, v, r;
    int hx;
    union { double d; int i[2]; } u;
    z = x;
    hx = *(int *)&z & 0x7fffffff;
    if (hx < 0x3e400000 && (int)x == 0) return x;
    z = x * x;
    v = z * x;
    r = lbl_80560958 + z * (lbl_80560960 + z * (lbl_80560968 + z * (lbl_80560970 + z * (lbl_80560978 + lbl_80560980 * z))));
    if (hx < 0x3fd33333)
        return lbl_80560950 - ((lbl_80560988 * z) - ((z * v) - (x * y)));
    if (hx > 0x3fe90000)
        u.d = lbl_80560990;
    else {
        u.i[0] = hx + 0xffe00000;
        u.i[1] = 0;
    }
    return (lbl_80560950 - u.d) - (((lbl_80560988 * z) - u.d) - ((z * v) - (x * y)));
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
    union { double d; unsigned int w[2]; } u;
    int hx, ix, id;
    double z, w, s1, s2;
    u.d = x;
    hx = u.w[0];
    ix = hx & 0x7fffffff;
    if (ix >= 0x44100000) {
        if (ix > 0x7ff00000 || ((ix + 0x80100000 == 0) && u.w[1] != 0))
            return x + x;
        return hx > 0 ? lbl_802EE748[3] + lbl_802EE748[7] :
            -lbl_802EE748[3] - lbl_802EE748[7];
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000 && lbl_80560A48 + x > lbl_80560A50)
            return x;
        id = -1;
    } else {
        z = x;
        if (z < 0.0) z = -z;
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                z = (lbl_80560A58 * z - lbl_80560A50) / (lbl_80560A58 + z);
            } else {
                id = 1;
                z = (z - lbl_80560A50) / (lbl_80560A50 + z);
            }
        } else if (ix < 0x40038000) {
            id = 2;
            z = (z - lbl_80560A60) / (lbl_80560A50 + lbl_80560A60 * z);
        } else {
            id = 3;
            z = lbl_80560A68 / z;
        }
    }
    w = z * z;
    s1 = w * (lbl_802EE748[8] + w * (lbl_802EE748[10] + w * (lbl_802EE748[12] + w * (lbl_802EE748[14] + w * lbl_802EE748[16]))));
    s2 = w * (lbl_802EE748[9] + w * (lbl_802EE748[11] + w * (lbl_802EE748[13] + w * (lbl_802EE748[15] + w * (lbl_802EE748[17] + w * lbl_802EE748[18])))));
    if (id < 0) return z - z * (s1 + s2);
    z = lbl_802EE748[id] - ((z * (s1 + s2) - lbl_802EE748[id + 4]) - z);
    if (hx < 0) z = -z;
    return z;
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

double copysign(double x, double y) {
    union { double d; unsigned int i[2]; } b, a;
    a.d = x;
    b.d = y;
    a.i[0] = (a.i[0] & 0x7fffffff) | (b.i[0] & 0x80000000);
    return a.d;
}

extern double lbl_80560A80;
extern double __kernel_cos(double, double);
extern double __kernel_sin(int, double, double);
__declspec(section ".sdata") extern double lbl_80560A80;
#pragma dont_inline __kernel_sin
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
                if (i0 < 0) { i0 = 0; i1 = 0; }
                else if ((i0 & 1) | i1) { i0 = 0xbff00000; i1 = 0; }
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
    int hx, lx;
    u.d = x;
    hx = u.i[0];
    lx = u.i[1];
    *eptr = 0;
    hx &= 0x7fffffff;
    if (hx < 0x7ff00000) {
        if ((hx | lx) == 0) return x;
        if (hx < 0x00100000) {
            *eptr = -54;
            x *= lbl_80560A98;
            u.d = x;
            hx = u.i[0] & 0x7fffffff;
        }
        *eptr += (hx >> 20) - 0x3fe;
        u.i[0] = (u.i[0] & 0x800fffff) | 0x3fe00000;
        return u.d;
    }
    return x;
}

extern int __fpclassifyd(double);
extern double copysign(double, double);
extern double lbl_80560AA0, lbl_80560AA8, lbl_80560AB0, lbl_80560AB8, lbl_80560AC0;
double ldexp(int arg0, double x) {
    union { double d; unsigned int w[2]; } u;
    int exp, newexp;
    u.d = x;
    if (__fpclassifyd(x) <= 2 || lbl_80560AA0 == x)
        return x;
    exp = (u.w[0] >> 20) & 0x7FF;
    if (exp == 0) {
        if ((u.w[1] | (u.w[0] & 0x7FFFFFFF)) == 0)
            return x;
        x *= lbl_80560AA8;
        u.d = x;
        exp = ((u.w[0] >> 20) & 0x7FF) - 0x36;
        if (arg0 < -0xC350)
            return lbl_80560AB0 * x;
    }
    if (exp == 0x7FF)
        return x + x;
    newexp = exp + arg0;
    if (newexp > 0x7FE)
        return lbl_80560AB8 * copysign(lbl_80560AB8, x);
    if (newexp > 0) {
        u.w[0] = (u.w[0] & 0x800FFFFF) | (newexp << 20);
        return u.d;
    }
    if (newexp <= -0x36) {
        if (arg0 > 0xC350)
            return lbl_80560AB8 * copysign(lbl_80560AB8, x);
        return lbl_80560AB0 * copysign(lbl_80560AB0, x);
    }
    u.w[0] = (u.w[0] & 0x800FFFFF) | ((newexp + 0x36) << 20);
    return lbl_80560AC0 * u.d;
}

__declspec(section ".sdata") extern double lbl_80560AC8;
#pragma dont_inline __kernel_sin
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

void fn_8002EFB4(void) {
    __ieee754_fmod();
}

void fn_8002EFB8(void) {
    __ieee754_log();
}

void fn_8002EFBC(void) {
    __ieee754_pow();
}

double fn_8002F208(void) {
    fn_8002EFB8();
    return lbl_80560AE0 * __ieee754_log();
}

void fn_8002F230(void) {

}

extern double lbl_80560600, lbl_80560608, lbl_80560610, lbl_80560670;
extern double lbl_80560618, lbl_80560620, lbl_80560628, lbl_80560630, lbl_80560638, lbl_80560640;
extern double lbl_80560648, lbl_80560650, lbl_80560658, lbl_80560660, lbl_80560668;
extern double lbl_80560678, lbl_80560680;
extern float lbl_80558DB0;
extern double __ieee754_sqrt(double);
double fn_8002F234(double x) {
    __ieee754_sqrt(x);
}

