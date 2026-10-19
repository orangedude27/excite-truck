#include <types.h>
#include <revolution/MTX/vec.h>

extern char lbl_8055E839;
extern s32 lbl_8055E828;
extern s32 lbl_8055E81C;
extern s32 lbl_8055E820;
extern s32 lbl_8055E824;
extern char lbl_8055E838;
extern u8 lbl_8055E83F;
extern u8 lbl_8055E840;
extern void (*lbl_8055E86C)(void);
extern s32 lbl_8055E870;
extern char lbl_80337474[];
extern char lbl_80438464[];
extern char lbl_8043846C[];
extern char lbl_80438478[];
extern char lbl_80438484[];
extern char lbl_80438490[];
extern char lbl_80438564[];
extern char lbl_804383F8[];
extern char lbl_80438408[];
extern char lbl_8055AA54[];
  
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E7E2;
extern s32 lbl_8055E804;
extern f32 lbl_805629CC;
extern u8* fn_8017960C(s32);
extern Vec lbl_80438268;
extern Vec lbl_8043848C;
extern char lbl_804380F0[256];
extern f32 lbl_8055E834;
extern f32 lbl_8055F47C;
extern s32 lbl_80499050[];
extern s32 lbl_80438220[];
extern s32 lbl_80437E24[];
extern void *fn_801C3C80(void);
extern void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
extern s32 fn_801C3B7C(const void *, const void *);
extern s32 fn_801C3524(char *);
extern char *strcpy(char *, const char *);
extern char lbl_80437FC0[304];
extern char lbl_80336EC8[];
extern char lbl_80336EE8[];
extern char lbl_80336F0C[];
extern s32 lbl_8055E7F0;
extern s32 lbl_8055E7F8;
extern s32 lbl_80499050[12];
extern s32 lbl_804381F0[12];
extern s32 lbl_80438220[12];
extern f32 lbl_8056296C;
extern f32 lbl_8055E3C8;
extern f32 lbl_80562970;
extern f32 cos(f32);
extern f32 sin(f32);
extern void fn_801B7C8C(s32, s32, f32 *);
extern void *fn_80178C9C(void);
extern void fn_801B8054(s32, void *, f32, f32);
extern void fn_80015A20(void *, f32 *);
extern void fn_80015B20(s32, void *, s32);
extern f32 lbl_80562978;
extern f32 lbl_80562980;
extern f32 lbl_80562994;
extern f32 lbl_80562974;
extern f32 lbl_805629C8;
extern s32 lbl_80437E24[3];
extern f32 lbl_80558DC4[];
extern double fn_8002F234(float);
extern void fn_8012F57C(float *, float *, float *, float);
extern f32 lbl_8056296C, lbl_80562970, lbl_80562974;
f32 fn_801C2F58(s32 arg0, f32 arg1) {
    f32 result = lbl_8056296C;
    if (arg0 > 0) {
        s32 remainder = arg0 - 8;
        s32 count = 0;
        if (arg0 > 8 && arg0 <= 0x7FFFFFFE) {
            count = 1;
        }
        if (count != 0) {
            s32 loops = (remainder + 7) / 8;
            while (loops-- != 0) {
                result *= arg1;
                result *= arg1;
                result *= arg1;
                result *= arg1;
                result *= arg1;
                result *= arg1;
                result *= arg1;
                result *= arg1;
                if (remainder <= 0)
                    break;
            }
        }
        remainder = arg0 - 8 * count;
        while (remainder-- != 0) {
            result *= arg1;
        }
    }
    return result;
}

void fn_801C2FF4(float *out, float *a, float *b, float weight) {
    float qa[4], qb[4], q[4], trace, root, half=lbl_80562974, w, x, y, z;
    int i,j,k;
    trace=a[0]+a[4]+a[8];
    if(trace>lbl_80562970){ root=fn_8002F234(lbl_8056296C+trace); qa[0]=half*root; root=half/root; qa[1]=root*(a[5]-a[7]); qa[2]=root*(a[6]-a[2]); qa[3]=root*(a[1]-a[3]); }
    else { i=0; if(a[4]>a[0])i=1; if(a[8]>a[i*3+i])i=2; j=(i+1)%3; k=(j+1)%3; root=fn_8002F234(lbl_8056296C+a[i*3+i]-(a[j*3+k]+a[k*3+j])); qa[i]=half*root; root=half/root; qa[3]=root*(a[j*3+k]-a[k*3+j]); qa[j]=root*(a[i*3+j]+a[j*3+i]); qa[k]=root*(a[i*3+k]+a[k*3+i]); }
    trace=b[0]+b[4]+b[8];
    if(trace>lbl_80562970){ root=fn_8002F234(lbl_8056296C+trace); qb[0]=half*root; root=half/root; qb[1]=root*(b[5]-b[7]); qb[2]=root*(b[6]-b[2]); qb[3]=root*(b[1]-b[3]); }
    else { i=0; if(b[4]>b[0])i=1; if(b[8]>b[i*3+i])i=2; j=(i+1)%3; k=(j+1)%3; root=fn_8002F234(lbl_8056296C+b[i*3+i]-(b[j*3+k]+b[k*3+j])); qb[i]=half*root; root=half/root; qb[3]=root*(b[j*3+k]-b[k*3+j]); qb[j]=root*(b[i*3+j]+b[j*3+i]); qb[k]=root*(b[i*3+k]+b[k*3+i]); }
    fn_8012F57C(q,qa,qb,weight);
    w=q[0]; x=q[1]; y=q[2]; z=q[3];
    out[9]=a[9]+weight*(b[9]-a[9]); out[10]=a[10]+weight*(b[10]-a[10]); out[11]=a[11]+weight*(b[11]-a[11]);
    out[0]=1-2*(y*y+z*z); out[4]=1-2*(x*x+z*z); out[8]=1-2*(x*x+y*y);
    out[7]=2*(y*z-w*x); out[2]=2*(y*z+w*x); out[1]=2*(x*y-w*z); out[3]=2*(x*y+w*z);
    out[6]=2*(x*z-w*y); out[5]=2*(x*z+w*y);
}

f32 fn_801C3450(f32 arg0) {
    f32 denom;
    f32 value;
    denom = fn_801C2F58(2, lbl_80562978);
    value = (f32)(s32)(arg0 * fn_801C2F58(2, lbl_80562978));
    return (value - *(f32 *)&lbl_80562980) / denom;
}

s32 fn_801C34CC(f32 arg0, f32 arg1) {
    f32 diff = arg0 - arg1;
    f64 abs = __fabs((f64)diff);
    return (f32)abs <= lbl_80558DC4[0];
}

f32 fn_801C34F4(f32 arg0) {
    extern f32 lbl_80562988;
    extern f32 lbl_8056298C;
    return (lbl_80562988 * arg0) / lbl_8056298C;
}

s32 fn_801C3508(s32 arg0, s32 arg1) {
    return (arg0 & (1 << arg1)) != 0;
}

#pragma auto_inline off
s32 fn_801C3954(s32 arg0) {
    char buf[0x100];
    char *p;
    s32 result;
    p = strcpy(buf, (char *)arg0);
    result = 0;
    do {
        s32 found = 0;
        char c;
        while ((c = *p) != ' ' && c != 0) p++;
        if (c == 0) found = 1;
        *p = 0;
        result |= fn_801C3524(buf);
        if (found) break;
        p++;
    } while (1);
    return result;
}
#pragma auto_inline on
s32 fn_801C3A00(u32 arg0) {
    s32 i;
    for (i = 0; i < lbl_8055E804; i++) {
        if (arg0 == (1U << i))
            return i;
    }
    return -1;
}

extern f32 cos(f32);
extern f32 sin(f32);
extern void fn_801B7C8C(s32, s32, f32 *);
extern void *fn_80178C9C(void);
extern void fn_801B8054(s32, void *, f32, f32);
extern void fn_80015A20(void *, f32 *);
extern void fn_80015B20(s32, void *, s32);
void fn_801C3A3C(s32 arg0, f32 arg1, f32 arg2) {
    void *p = fn_80178C9C();
    void *r = *(void **)(*(char **)((char *)p + 0x2C) + 0x20);
    while (r != 0 && *(u8 *)((char *)r + 0x34) != 0)
        r = *(void **)((char *)r + 0x14);
    fn_801B8054(arg0, p, lbl_80562970, (r != 0 ? *(f32 *)((char *)r + 0x1C) : lbl_80562970) + arg1);
    {
        f32 values[3];
        values[0] = arg2;
        values[1] = lbl_80562970;
        values[2] = lbl_80562970;
        fn_80015A20(&values[1], &values[0]);
        fn_80015B20(arg0, &values[1], arg0);
    }
}

void fn_801C3AF8(s32 arg0, s32 arg1, f32 arg2) {
    f32 values[3];
    values[0] = cos(arg2);
    values[1] = sin(arg2);
    fn_801B7C8C(arg0, arg1, &values[1]);
}

s32 *__AXFXGetLfoSinTable_801769CC(void);
void *fn_8001285C(s32);
extern f32 lbl_80562990;
extern f32 lbl_8055E7E4;
f32 fn_801C3B6C(void) {
    return lbl_8055E3C8 + lbl_8055E7E4;
}

s32 fn_801C3B7C(const void *arg0, const void *arg1) {
    f32 a = *(f32 *)arg0;
    f32 b = *(f32 *)arg1;
    if (b < lbl_80562990)
        return -1;
    if (a < lbl_80562990)
        return 1;
    if (fn_801C34CC(a, b))
        return *(s32 *)((char *)arg0 + 4) - *(s32 *)((char *)arg1 + 4);
    if (a < b)
        return -1;
    return 1;
}

#pragma push
#pragma scheduling off
void fn_801C3C14(s32 arg0) {
    s32 offset = arg0 * 0x30C;
    memset((void *)(lbl_8055E7F8 + offset), 0, 0x30C);
    *(f32 *)(lbl_8055E7F8 + offset) = lbl_80562994;
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
          (int (*)(const void *, const void *))fn_801C3B7C);
    lbl_8055E7F0--;
}
#pragma pop
extern char lbl_8055E80D;
extern f32 lbl_8055E810;
void *fn_801C3C80(void) {
    s32 i;
    s32 max;
    s32 offset;
    s32 count;
    char *entry;

    i = lbl_8055E7F0;
    entry = (char *)lbl_8055E7F8 + i * 0x30C;
    lbl_8055E7F0 = i + 1;
    if (lbl_8055E80D != 0) {
        *(f32 *)entry = lbl_8055E810;
    } else {
        fn_801C3B6C();
        *(f32 *)entry = ((f32 (*)(void))fn_801C3450)();
    }
    max = 0;
    offset = 0;
    count = 0;
    while (count < lbl_8055E7F0 - 1) {
        if (fn_801C34CC(*(f32 *)entry, *(f32 *)((char *)lbl_8055E7F8 + offset))) {
            i = *(s32 *)((char *)lbl_8055E7F8 + offset + 4);
            if (i > max)
                max = i;
        }
        offset += 0x30C;
        count++;
    }
    *(s32 *)(entry + 4) = max + 1;
    return entry;
}

extern void fn_80128670(void);
extern s32 fn_8012850C(s32, void *);
extern void fn_801C3D88(void *);
extern char lbl_80336D84[];
extern char lbl_80336D90[];
extern char lbl_8055E7E8;
extern char lbl_8055E7E9;
extern char lbl_8055E7E3;
extern s32 lbl_8055E808;

s32 fn_801C3D5C(void) {
    return *(s32 *)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
}

void fn_801C9834(void);
void fn_801C4AD0(void) {
    lbl_8055E7E9 = 0;
    lbl_8055E7E8 = 0;
    lbl_8055E7E2 = 0;
    lbl_8055E7E3 = 0;
    lbl_8055E7F0 = 0;
    lbl_8055E804 = 0;
    lbl_8055E808 = 0;
    lbl_8055E7E4 = lbl_80562970;
    *(f32 *)&lbl_80437E24[2] = lbl_80562994;
    *(s32 *)&lbl_80437E24[0] = 0;
    fn_801C9834();
}

extern void fn_801C98F0(void);

#pragma scheduling off
void fn_801C4B10(void) {
    lbl_8055E804 = 0;
    while ((s32)fn_8017960C(lbl_8055E804 += 1) != 0) {
    }
    lbl_8055E7F8 = fn_8012850C(0xC300, lbl_80336D84);
    fn_801C3D88(lbl_80336D90);
}
#pragma scheduling on
void fn_801C4B74(void) {
    fn_801C98F0();
    if ((void *)(unsigned long)lbl_8055E7F8 != 0) {
        fn_80128670();
        lbl_8055E7F8 = 0;
    }
}
#pragma scheduling on
char fn_801C5B60(void) {
    return lbl_8055E7E2;
}

extern s32 lbl_8055E800;
extern u8 lbl_8055E818, lbl_8055E819;
extern f32 lbl_805629A0, lbl_805629AC, lbl_805629C0, lbl_805629C4;
extern char lbl_80336E88[];
extern s32 fn_80179630(s32);
extern f32 fn_80144514(f32, f32, f32, f32, f32, f32);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_8020655C(void *, s32);
extern void fn_802E317C(void *);
extern struct Unk_80437D88 lbl_80437D88;
#pragma push
#pragma dont_inline on
s32 fn_801C5B68(char *arg0, s32 arg1) {
    extern char lbl_8055E80C;
    void *sp28;
    void *sp24;
    s32 sp20;
    f32 rotation[9], saved[12], basis[12], velocity[3], axis[3], translated[3], offset[3];
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f30_3;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f23;
    f32 var_f29;
    s32 temp_r10;
    s32 temp_r5;
    s32 var_r29;
    char *temp_r31;
    char *temp_r4;
    char *temp_r5_2;
    char *temp_r6;
    char *temp_r9;

    if (arg1 == 0) {
        lbl_8055E800 += 1;
    }
    if ((fn_801C5B60() != 0) && ((s32) lbl_8055E80C == 0)) {
        (*(f32 *)((char *)(&lbl_80499050) + 0x24)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 8));
        (*(f32 *)((char *)(&lbl_80499050) + 0x28)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0xC));
        (*(f32 *)((char *)(&lbl_80499050) + 0x2C)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x10));
        (*(f32 *)((char *)(&lbl_80499050) + 0)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x14));
        (*(f32 *)((char *)(&lbl_80499050) + 4)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x18));
        (*(f32 *)((char *)(&lbl_80499050) + 8)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x1C));
        (*(f32 *)((char *)(&lbl_80499050) + 0xC)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x20));
        (*(f32 *)((char *)(&lbl_80499050) + 0x10)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x24));
        (*(f32 *)((char *)(&lbl_80499050) + 0x14)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x28));
        (*(f32 *)((char *)(&lbl_80499050) + 0x18)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x2C));
        (*(f32 *)((char *)(&lbl_80499050) + 0x1C)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x30));
        (*(f32 *)((char *)(&lbl_80499050) + 0x20)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x34));
        lbl_8055F47C = (*(f32 *)((char *)(&lbl_80437D88) + 0x50));
    }
    if ((fn_801C5B60() == 0) || ((s32) lbl_8055E80C != 0)) {
        return 0;
    }
    if ((s8) lbl_8055E818 == 0) {
        lbl_8055E818 = 1;
    }
    if ((s8) lbl_8055E819 == 0) {
        lbl_8055E819 = 1;
    }
    memset(arg0, 0, 0xE0);
    var_r29 = fn_80179630(arg1);
    if ((s32) (*(s32 *)((char *)(&lbl_80437D88) + 0x58)) >= 0) {
        var_r29 = (*(s32 *)((char *)(&lbl_80437D88) + 0x58));
    }
    temp_r31 = (char *)fn_8017960C(var_r29);
    (*(s32 *)((char *)(arg0) + 0x68)) = (s32) ((*(s32 *)((char *)(arg0) + 0x68)) | 5);
    if (fn_801C3B6C() > (*(f32 *)((char *)(&lbl_80437D88) + 4))) {
        var_f29 = (*(f32 *)((char *)(&lbl_80437D88) + 4)) - (*(f32 *)((char *)(&lbl_80437D88) + 0));
    } else {
        var_f29 = fn_801C3B6C() - (*(f32 *)((char *)(&lbl_80437D88) + 0));
    }
    temp_f2 = (*(f32 *)((char *)(&lbl_80437D88) + 4)) - (*(f32 *)((char *)(&lbl_80437D88) + 0));
    if (temp_f2 > lbl_805629AC) {
        temp_f3 = var_f29 / temp_f2;
        var_f0 = lbl_80562990;
        if (temp_f3 < var_f0) {

        } else {
            var_f0 = lbl_8056296C;
            if (temp_f3 > var_f0) {

            } else if (temp_f3 > lbl_80562970) {
                var_f0 = (temp_f3 * (lbl_805629C0 * temp_f3 * temp_f3)) + (lbl_805629C4 * temp_f3 * temp_f3);
            } else {
                var_f0 = (temp_f3 * (lbl_805629C0 * temp_f3 * temp_f3)) - (lbl_805629C4 * temp_f3 * temp_f3);
            }
        }
        if ((s32) (*(u8 *)((char *)(&lbl_80437D88) + 0x54)) != 0) {
            var_f29 = var_f0 * temp_f2;
        }
    }
    (*(f32 *)((char *)(arg0) + 0x24)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 8));
    (*(f32 *)((char *)(arg0) + 0x28)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0xC));
    (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x10));
    (*(f32 *)((char *)(arg0) + 0)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x14));
    (*(f32 *)((char *)(arg0) + 4)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x18));
    (*(f32 *)((char *)(arg0) + 8)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x1C));
    (*(f32 *)((char *)(arg0) + 0xC)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x20));
    (*(f32 *)((char *)(arg0) + 0x10)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x24));
    (*(f32 *)((char *)(arg0) + 0x14)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x28));
    (*(f32 *)((char *)(arg0) + 0x18)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x2C));
    (*(f32 *)((char *)(arg0) + 0x1C)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x30));
    (*(f32 *)((char *)(arg0) + 0x20)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x34));
    temp_f8 = (*(f32 *)((char *)(&lbl_80437D88) + 0x38)) * var_f29;
    temp_f6 = (*(f32 *)((char *)(&lbl_80437D88) + 0x3C)) * var_f29;
    temp_f7 = (*(f32 *)((char *)(&lbl_80437D88) + 0x40)) * var_f29;
    velocity[0] = temp_f8;
    velocity[1] = temp_f6;
    velocity[2] = temp_f7;
    if (&translated[0] == &velocity[0]) {
        translated[0] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x18))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 0))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0xC))));
        translated[1] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x1C))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 4))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x10))));
        translated[2] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x20))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 8))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x14))));
    } else {
        translated[0] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x18))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 0))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0xC))));
        translated[1] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x1C))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 4))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x10))));
        translated[2] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x20))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 8))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x14))));
    }
    (*(f32 *)((char *)(arg0) + 0x24)) = (f32) ((*(f32 *)((char *)(arg0) + 0x24)) + translated[0]);
    (*(f32 *)((char *)(arg0) + 0x28)) = (f32) ((*(f32 *)((char *)(arg0) + 0x28)) + translated[1]);
    (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((char *)(arg0) + 0x2C)) + translated[2]);
    temp_f2_2 = (*(f32 *)((char *)(&lbl_80437D88) + 0x44)) * var_f29;
    temp_f1 = (*(f32 *)((char *)(&lbl_80437D88) + 0x48)) * var_f29;
    axis[0] = temp_f2_2;
    axis[1] = temp_f1;
    axis[2] = (*(f32 *)((char *)(&lbl_80437D88) + 0x4C)) * var_f29;
    temp_f1_2 = PSVECMag((Vec *)&axis[0]);
    if (temp_f1_2 > lbl_805629A0) {
        temp_f4 = lbl_8056296C / temp_f1_2;
        temp_f31 = temp_f4 * axis[0];
        temp_f24 = temp_f4 * axis[1];
        temp_f23 = temp_f4 * axis[2];
        temp_f30 = (f32) sin(temp_f1_2);
        temp_f9 = (f32) cos(temp_f1_2);
        temp_f0 = lbl_8056296C - temp_f9;
        temp_f3_2 = temp_f30 * temp_f23;
        temp_f6_2 = temp_f0 * temp_f31;
        temp_f4_2 = temp_f24 * temp_f6_2;
        rotation[0] = temp_f9 + (temp_f0 * (temp_f31 * temp_f31));
        temp_f6_3 = temp_f23 * temp_f6_2;
        temp_f2_3 = temp_f30 * temp_f24;
        rotation[1] = temp_f4_2 + temp_f3_2;
        temp_f3_3 = temp_f23 * (temp_f0 * temp_f24);
        temp_f0_2 = temp_f30 * temp_f31;
        rotation[3] = temp_f4_2 - temp_f3_2;
        rotation[2] = temp_f6_3 - temp_f2_3;
        rotation[4] = temp_f9 + (temp_f0 * (temp_f24 * temp_f24));
        rotation[5] = temp_f3_3 + temp_f0_2;
        rotation[6] = temp_f6_3 + temp_f2_3;
        rotation[7] = temp_f3_3 - temp_f0_2;
        rotation[8] = temp_f9 + (temp_f0 * (temp_f23 * temp_f23));
    } else {
        rotation[1] = lbl_80562970;
        rotation[0] = lbl_8056296C;
        rotation[2] = lbl_80562970;
        rotation[3] = lbl_80562970;
        rotation[4] = lbl_8056296C;
        rotation[5] = lbl_80562970;
        rotation[6] = lbl_80562970;
        rotation[7] = lbl_80562970;
        rotation[8] = lbl_8056296C;
    }
    if (((void *)arg0 == (void *)&rotation[0]) || (arg0 == arg0)) {
        temp_f31_2 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), rotation[0], (*(f32 *)((char *)(arg0) + 0xC)), rotation[1], (*(f32 *)((char *)(arg0) + 0x18)), rotation[2]);
        temp_f30_2 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), rotation[3], (*(f32 *)((char *)(arg0) + 0xC)), rotation[4], (*(f32 *)((char *)(arg0) + 0x18)), rotation[5]);
        temp_f28 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), rotation[6], (*(f32 *)((char *)(arg0) + 0xC)), rotation[7], (*(f32 *)((char *)(arg0) + 0x18)), rotation[8]);
        temp_f27 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), rotation[0], (*(f32 *)((char *)(arg0) + 0x10)), rotation[1], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[2]);
        temp_f26 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), rotation[3], (*(f32 *)((char *)(arg0) + 0x10)), rotation[4], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[5]);
        temp_f25 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), rotation[6], (*(f32 *)((char *)(arg0) + 0x10)), rotation[7], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[8]);
        temp_f24_2 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), rotation[0], (*(f32 *)((char *)(arg0) + 0x14)), rotation[1], (*(f32 *)((char *)(arg0) + 0x20)), rotation[2]);
        temp_f23_2 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), rotation[3], (*(f32 *)((char *)(arg0) + 0x14)), rotation[4], (*(f32 *)((char *)(arg0) + 0x20)), rotation[5]);
        temp_f1_3 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), rotation[6], (*(f32 *)((char *)(arg0) + 0x14)), rotation[7], (*(f32 *)((char *)(arg0) + 0x20)), rotation[8]);
        (*(f32 *)((char *)(arg0) + 0)) = temp_f31_2;
        (*(f32 *)((char *)(arg0) + 0xC)) = temp_f30_2;
        (*(f32 *)((char *)(arg0) + 0x18)) = temp_f28;
        (*(f32 *)((char *)(arg0) + 4)) = temp_f27;
        (*(f32 *)((char *)(arg0) + 0x10)) = temp_f26;
        (*(f32 *)((char *)(arg0) + 0x1C)) = temp_f25;
        (*(f32 *)((char *)(arg0) + 8)) = temp_f24_2;
        (*(f32 *)((char *)(arg0) + 0x14)) = temp_f23_2;
        (*(f32 *)((char *)(arg0) + 0x20)) = temp_f1_3;
    } else {
        temp_f1_4 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), rotation[0], (*(f32 *)((char *)(arg0) + 0xC)), rotation[1], (*(f32 *)((char *)(arg0) + 0x18)), rotation[2]);
        (*(f32 *)((char *)(arg0) + 0)) = temp_f1_4;
        temp_f1_5 = fn_80144514((f32) temp_f1_4, rotation[3], (*(f32 *)((char *)(arg0) + 0xC)), rotation[4], (*(f32 *)((char *)(arg0) + 0x18)), rotation[5]);
        (*(f32 *)((char *)(arg0) + 0xC)) = temp_f1_5;
        (*(f32 *)((char *)(arg0) + 0x18)) = fn_80144514((*(f32 *)((char *)(arg0) + 0)), rotation[6], (f32) temp_f1_5, rotation[7], (*(f32 *)((char *)(arg0) + 0x18)), rotation[8]);
        temp_f1_6 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), rotation[0], (*(f32 *)((char *)(arg0) + 0x10)), rotation[1], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[2]);
        (*(f32 *)((char *)(arg0) + 4)) = temp_f1_6;
        temp_f1_7 = fn_80144514((f32) temp_f1_6, rotation[3], (*(f32 *)((char *)(arg0) + 0x10)), rotation[4], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[5]);
        (*(f32 *)((char *)(arg0) + 0x10)) = temp_f1_7;
        (*(f32 *)((char *)(arg0) + 0x1C)) = fn_80144514((*(f32 *)((char *)(arg0) + 4)), rotation[6], (f32) temp_f1_7, rotation[7], (*(f32 *)((char *)(arg0) + 0x1C)), rotation[8]);
        temp_f1_8 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), rotation[0], (*(f32 *)((char *)(arg0) + 0x14)), rotation[1], (*(f32 *)((char *)(arg0) + 0x20)), rotation[2]);
        (*(f32 *)((char *)(arg0) + 8)) = temp_f1_8;
        temp_f1_9 = fn_80144514((f32) temp_f1_8, rotation[3], (*(f32 *)((char *)(arg0) + 0x14)), rotation[4], (*(f32 *)((char *)(arg0) + 0x20)), rotation[5]);
        (*(f32 *)((char *)(arg0) + 0x14)) = temp_f1_9;
        (*(f32 *)((char *)(arg0) + 0x20)) = fn_80144514((*(f32 *)((char *)(arg0) + 8)), rotation[6], (f32) temp_f1_9, rotation[7], (*(f32 *)((char *)(arg0) + 0x20)), rotation[8]);
    }
    if ((s32) (*(s32 *)((char *)(&lbl_80437D88) + 0x58)) >= 0) {
        saved[0] = (*(f32 *)((char *)(arg0) + 0));
        saved[1] = (*(f32 *)((char *)(arg0) + 4));
        saved[2] = (*(f32 *)((char *)(arg0) + 8));
        saved[3] = (*(f32 *)((char *)(arg0) + 0xC));
        saved[4] = (*(f32 *)((char *)(arg0) + 0x10));
        saved[5] = (*(f32 *)((char *)(arg0) + 0x14));
        saved[6] = (*(f32 *)((char *)(arg0) + 0x18));
        saved[7] = (*(f32 *)((char *)(arg0) + 0x1C));
        saved[8] = (*(f32 *)((char *)(arg0) + 0x20));
        saved[9] = (*(f32 *)((char *)(arg0) + 0x24));
        saved[10] = (*(f32 *)((char *)(arg0) + 0x28));
        saved[11] = (*(f32 *)((char *)(arg0) + 0x2C));
        switch ((s32) (*(s32 *)((char *)(&lbl_80437D88) + 0x5C))) { /* irregular */
        case 0:
            basis[1] = lbl_80562970;
            basis[0] = lbl_8056296C;
            basis[2] = lbl_80562970;
            basis[3] = lbl_80562970;
            basis[4] = lbl_8056296C;
            basis[5] = lbl_80562970;
            basis[6] = lbl_80562970;
            basis[7] = lbl_80562970;
            basis[8] = lbl_8056296C;
            basis[9] = lbl_80562970;
            basis[10] = lbl_80562970;
            basis[11] = lbl_80562970;
            break;
        case 1:
            basis[0] = (*(f32 *)((char *)(temp_r31) + 0x274));
            basis[1] = (*(f32 *)((char *)(temp_r31) + 0x278));
            basis[2] = (*(f32 *)((char *)(temp_r31) + 0x27C));
            basis[3] = (*(f32 *)((char *)(temp_r31) + 0x280));
            basis[4] = (*(f32 *)((char *)(temp_r31) + 0x284));
            basis[5] = (*(f32 *)((char *)(temp_r31) + 0x288));
            basis[6] = (*(f32 *)((char *)(temp_r31) + 0x28C));
            basis[7] = (*(f32 *)((char *)(temp_r31) + 0x290));
            basis[8] = (*(f32 *)((char *)(temp_r31) + 0x294));
            basis[9] = (*(f32 *)((char *)(temp_r31) + 0x298));
            basis[10] = (*(f32 *)((char *)(temp_r31) + 0x29C));
            basis[11] = (*(f32 *)((char *)(temp_r31) + 0x2A0));
            break;
        case 2:
            basis[0] = (*(f32 *)((char *)(temp_r31) + 0x70));
            basis[1] = (*(f32 *)((char *)(temp_r31) + 0x74));
            basis[2] = (*(f32 *)((char *)(temp_r31) + 0x78));
            basis[3] = (*(f32 *)((char *)(temp_r31) + 0x7C));
            basis[4] = (*(f32 *)((char *)(temp_r31) + 0x80));
            basis[5] = (*(f32 *)((char *)(temp_r31) + 0x84));
            basis[6] = (*(f32 *)((char *)(temp_r31) + 0x88));
            basis[7] = (*(f32 *)((char *)(temp_r31) + 0x8C));
            basis[8] = (*(f32 *)((char *)(temp_r31) + 0x90));
            basis[9] = (*(f32 *)((char *)(temp_r31) + 0x94));
            basis[10] = (*(f32 *)((char *)(temp_r31) + 0x98));
            basis[11] = (*(f32 *)((char *)(temp_r31) + 0x9C));
            break;
        default:
            fn_802E317C(&lbl_80336E88);
            break;
        }
        if ((s32) (*(s32 *)((char *)(&lbl_80437D88) + 0x5C)) != 1) {
            fn_801BFD34(arg0 + 0x24, &saved[9], &basis[0]);
            fn_80015B20((s32)arg0, &saved[0], (s32)&basis[0]);
        } else {
            (*(f32 *)((char *)(arg0) + 0x24)) = basis[9];
            (*(f32 *)((char *)(arg0) + 0x28)) = basis[10];
            (*(f32 *)((char *)(arg0) + 0x2C)) = basis[11];
            if (((void *)arg0 == (void *)&saved[0]) || ((void *)arg0 == (void *)&basis[0])) {
                temp_f23_3 = fn_80144514(basis[0], saved[0], basis[3], saved[1], basis[6], saved[2]);
                temp_f24_3 = fn_80144514(basis[0], saved[3], basis[3], saved[4], basis[6], saved[5]);
                temp_f25_2 = fn_80144514(basis[0], saved[6], basis[3], saved[7], basis[6], saved[8]);
                temp_f26_2 = fn_80144514(basis[1], saved[0], basis[4], saved[1], basis[7], saved[2]);
                temp_f27_2 = fn_80144514(basis[1], saved[3], basis[4], saved[4], basis[7], saved[5]);
                temp_f28_2 = fn_80144514(basis[1], saved[6], basis[4], saved[7], basis[7], saved[8]);
                temp_f31_3 = fn_80144514(basis[2], saved[0], basis[5], saved[1], basis[8], saved[2]);
                temp_f30_3 = fn_80144514(basis[2], saved[3], basis[5], saved[4], basis[8], saved[5]);
                temp_f1_10 = fn_80144514(basis[2], saved[6], basis[5], saved[7], basis[8], saved[8]);
                (*(f32 *)((char *)(arg0) + 0)) = temp_f23_3;
                (*(f32 *)((char *)(arg0) + 0xC)) = temp_f24_3;
                (*(f32 *)((char *)(arg0) + 0x18)) = temp_f25_2;
                (*(f32 *)((char *)(arg0) + 4)) = temp_f26_2;
                (*(f32 *)((char *)(arg0) + 0x10)) = temp_f27_2;
                (*(f32 *)((char *)(arg0) + 0x1C)) = temp_f28_2;
                (*(f32 *)((char *)(arg0) + 8)) = temp_f31_3;
                (*(f32 *)((char *)(arg0) + 0x14)) = temp_f30_3;
                (*(f32 *)((char *)(arg0) + 0x20)) = temp_f1_10;
            } else {
                (*(f32 *)((char *)(arg0) + 0)) = fn_80144514(basis[0], saved[0], basis[3], saved[1], basis[6], saved[2]);
                (*(f32 *)((char *)(arg0) + 0xC)) = fn_80144514(basis[0], saved[3], basis[3], saved[4], basis[6], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x18)) = fn_80144514(basis[0], saved[6], basis[3], saved[7], basis[6], saved[8]);
                (*(f32 *)((char *)(arg0) + 4)) = fn_80144514(basis[1], saved[0], basis[4], saved[1], basis[7], saved[2]);
                (*(f32 *)((char *)(arg0) + 0x10)) = fn_80144514(basis[1], saved[3], basis[4], saved[4], basis[7], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x1C)) = fn_80144514(basis[1], saved[6], basis[4], saved[7], basis[7], saved[8]);
                (*(f32 *)((char *)(arg0) + 8)) = fn_80144514(basis[2], saved[0], basis[5], saved[1], basis[8], saved[2]);
                (*(f32 *)((char *)(arg0) + 0x14)) = fn_80144514(basis[2], saved[3], basis[5], saved[4], basis[8], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x20)) = fn_80144514(basis[2], saved[6], basis[5], saved[7], basis[8], saved[8]);
            }
            if (&offset[0] == &saved[9]) {
                offset[0] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x18))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 0))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0xC))));
                offset[1] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x1C))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 4))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x10))));
                offset[2] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x20))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 8))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x14))));
            } else {
                offset[0] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x18))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 0))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0xC))));
                offset[1] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x1C))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 4))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x10))));
                offset[2] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x20))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 8))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x14))));
            }
            (*(f32 *)((char *)(arg0) + 0x24)) = (f32) ((*(f32 *)((char *)(arg0) + 0x24)) + offset[0]);
            (*(f32 *)((char *)(arg0) + 0x28)) = (f32) ((*(f32 *)((char *)(arg0) + 0x28)) + offset[1]);
            (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((char *)(arg0) + 0x2C)) + offset[2]);
        }
    }
    
    if (((f32) __fabs((*(f32 *)((char *)(&lbl_80437D88) + 0x64)))  > lbl_80558DC4[0]) && (var_f29 < (*(f32 *)((char *)(&lbl_80437D88) + 0x64)))) {
        var_f23 = var_f29 / (*(f32 *)((char *)(&lbl_80437D88) + 0x64));
        if ((s32) (*(s32 *)((char *)(&lbl_80437D88) + 0x60)) == 1) {
            var_f0_2 = lbl_80562990;
            if (var_f23 < var_f0_2) {

            } else {
                var_f0_2 = lbl_8056296C;
                if (var_f23 > var_f0_2) {

                } else if (var_f23 > lbl_80562970) {
                    var_f0_2 = (var_f23 * (lbl_805629C0 * var_f23 * var_f23)) + (lbl_805629C4 * var_f23 * var_f23);
                } else {
                    var_f0_2 = (var_f23 * (lbl_805629C0 * var_f23 * var_f23)) - (lbl_805629C4 * var_f23 * var_f23);
                }
            }
            var_f23 = var_f0_2;
        }
        fn_801C2FF4((f32 *)arg0, (f32 *)((char *)&lbl_80437D88 + 0x68), (f32 *)arg0, var_f23);
        (*(f32 *)((char *)(&lbl_80437D88) + 0x50)) = (f32) ((*(f32 *)((char *)(&lbl_80437D88) + 0x98)) + (var_f23 * ((*(f32 *)((char *)(&lbl_80437D88) + 0x50)) - (*(f32 *)((char *)(&lbl_80437D88) + 0x98)))));
    } else {
        (*(f32 *)((char *)(&lbl_80437D88) + 0x68)) = (f32) (*(f32 *)((char *)(arg0) + 0));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x6C)) = (f32) (*(f32 *)((char *)(arg0) + 4));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x70)) = (f32) (*(f32 *)((char *)(arg0) + 8));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x74)) = (f32) (*(f32 *)((char *)(arg0) + 0xC));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x78)) = (f32) (*(f32 *)((char *)(arg0) + 0x10));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x7C)) = (f32) (*(f32 *)((char *)(arg0) + 0x14));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x80)) = (f32) (*(f32 *)((char *)(arg0) + 0x18));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x84)) = (f32) (*(f32 *)((char *)(arg0) + 0x1C));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x88)) = (f32) (*(f32 *)((char *)(arg0) + 0x20));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x8C)) = (f32) (*(f32 *)((char *)(arg0) + 0x24));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x90)) = (f32) (*(f32 *)((char *)(arg0) + 0x28));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x94)) = (f32) (*(f32 *)((char *)(arg0) + 0x2C));
        (*(f32 *)((char *)(&lbl_80437D88) + 0x98)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x50));
    }
    temp_r5 = arg1 * 0x30;
    (*(f32 *)((char *)(arg0) + 0x30)) = (f32) (*(f32 *)((char *)(&lbl_80437D88) + 0x50));
    temp_r4 = (char *)&lbl_80437D88 + 0x148;
    *(f32 *)(temp_r4 + temp_r5) = (*(f32 *)((char *)(arg0) + 0));
    temp_r9 = temp_r4 + temp_r5;
    temp_r10 = arg1 * 0xC;
    (*(f32 *)((char *)(temp_r9) + 4)) = (f32) (*(f32 *)((char *)(arg0) + 4));
    temp_r6 = (char *)&lbl_80437D88 + 0x208;
    temp_r5_2 = temp_r6 + temp_r10;
    (*(f32 *)((char *)(temp_r9) + 8)) = (f32) (*(f32 *)((char *)(arg0) + 8));
    (*(f32 *)((char *)(temp_r9) + 0xC)) = (f32) (*(f32 *)((char *)(arg0) + 0xC));
    *(f32 *)(temp_r9 + 0x10) = *(f32 *)(arg0 + 0x10);
    *(f32 *)(temp_r9 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(f32 *)(temp_r9 + 0x18) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(temp_r9 + 0x1C) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(temp_r9 + 0x20) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(temp_r9 + 0x24) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(temp_r9 + 0x28) = *(f32 *)(arg0 + 0x28);
    *(f32 *)(temp_r9 + 0x2C) = *(f32 *)(arg0 + 0x2C);
    *(f32 *)(temp_r6 + temp_r10) = (*(f32 *)((char *)(temp_r31) + 0x118));
    (*(f32 *)((char *)(temp_r5_2) + 4)) = (f32) (*(f32 *)((char *)(temp_r31) + 0x11C));
    (*(f32 *)((char *)(temp_r5_2) + 8)) = (f32) (*(f32 *)((char *)(temp_r31) + 0x120));
    (*(s32 *)((char *)(arg0) + 0x60)) = var_r29;
    (*(s32 *)((char *)(arg0) + 0x5C)) = 0xB;
    (*(s32 *)((char *)(arg0) + 0x58)) = 0xB;
    (*(s16 *)((char *)(arg0) + 0x64)) = (s16) (*(s16 *)((char *)(temp_r31) + 0x6C));
    sp20 = var_r29;
    sp24 = temp_r9;
    sp28 = temp_r5_2;
    fn_8020655C(&sp20, 0);
    return 1;
}
#pragma pop
s32 fn_801C6C28(Vec* arg0) {
    s32 result = -1;
    s32 i;
    
    for (i = 0; i < lbl_8055E804; i++) {
        if (PSVECSquareDistance((Vec*)(fn_8017960C(i) + 0x60), arg0) < lbl_805629CC) {
            result = i;
            break;
        }
    }
    
    return result;
}

void fn_801C6CB0(void) {
    return;
}

void fn_801C6CB4(void) {
    fn_801C957C(1);
}

void fn_801C6CBC(void) {
    sprintf(lbl_804380F0, "%s %d", lbl_804380F0, fn_801C6C28(&lbl_80438268));
}

void fn_801C6D00(void) {
    s32 *src = lbl_80499050;
    s32 *dst = lbl_804381F0;
    s32 temp;
    
    temp = *src++;
    *dst++ = temp;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    lbl_8055E834 = lbl_8055F47C;
}

void fn_801C7288(void);
void fn_801C7288(void) {
    fn_801C957C(0);
}

void fn_801C7290(void) {
    void *ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 2;
    sprintf(lbl_80437FC0, lbl_80336EC8, ((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}

extern char lbl_80336EE8[];
void fn_801C72F0(void) {
    void *ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 7;
    strncpy((char *)ptr + 0x10C, lbl_804380F0, 0x1FF);
    sprintf(lbl_80437FC0, lbl_80336EE8, (double)((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    fn_801C957C(0);
}

void fn_801C7374(void);
void fn_801C7374(void) {
    fn_801C957C(0);
}

void fn_801C737C(void) {
    lbl_8055E839 = 1;
}

extern char lbl_8055E839;
void fn_801C7388(void) {
    lbl_8055E839 = 0;
}

void fn_801C7394(void) {
    s32 temp_r3;

    if (lbl_8055E7F0 > 0) {
        fn_801C3C14(lbl_8055E828);
        temp_r3 = lbl_8055E7F0 - 1;
        if (lbl_8055E828 > temp_r3) {
            lbl_8055E828 = temp_r3;
        }
    }
}

void fn_801C7524(void) {
    s32 index;
    fn_801C957C(1);
    index = lbl_8055E828 * 0x30C;
    sprintf(lbl_804380F0, lbl_8055AA54, *(f32 *)(lbl_8055E7F8 + index));
}

extern u8 lbl_8055E83E;
extern u8 lbl_8055E841;
extern s32 lbl_8055E844;
extern char lbl_8055E83A;
extern char lbl_8055E83C;
extern void (*lbl_8055E868)(void);
extern s32 lbl_8055E848;
extern int atoi(const char *);
extern char lbl_8055E83B;
extern char lbl_8055E83D;
extern Vec lbl_80438250;
typedef struct Unk_80437D88 {
    char pad_0[0x4D4];
    Vec f_4D4;
    Vec f_4E0;
    char pad_1[0x6F8 - 0x4EC];
    Vec f_6F8;
} Unk_80437D88;
extern Unk_80437D88 lbl_80437D88;
extern void fn_801C7964(void);
extern s32 lbl_8055E828;
extern char lbl_8055AA54[];
extern s32 fn_801C34CC(f32, f32);
#pragma scheduling off
extern s32 lbl_8055E82C;
void fn_801C855C(void);
extern unsigned char lbl_8055E83E;
void fn_801C7770(void) {
    lbl_8055E83E = (lbl_8055E83E == 0);
}

void fn_801C7784(void) { lbl_8055E83F = !lbl_8055E83F; }

void fn_801C7798(void) {
    lbl_8055E840 = !lbl_8055E840;
}

void fn_801C77AC(void) {
    lbl_8055E841 = lbl_8055E841 == 0;
}

#pragma scheduling on
void fn_801C77C0(void) {
    lbl_8055E844 = atoi(lbl_804380F0);
    lbl_8055E841 = 0;
    fn_801C957C(0);
}

extern u8 lbl_8055E83F;
extern u8 lbl_8055E840;
extern char lbl_8055AA5C[];
extern char lbl_8055AA64[];
extern char lbl_80336F24[];
void fn_801C77FC(void) {
    char name[0x10];
    void *entry = fn_801C3C80();
    s32 flag;

    *(s32 *)((char *)entry + 8) = 3;
    *(u8 *)((char *)entry + 0x15) = lbl_8055E83F;
    *(u8 *)((char *)entry + 0x14) = lbl_8055E83E;
    flag = lbl_8055E840;
    *(s32 *)((char *)entry + 0x10) = flag != 0;
    flag = lbl_8055E841;
    if (flag != 0)
        *(s32 *)((char *)entry + 0xC) = -1;
    else
        *(s32 *)((char *)entry + 0xC) = lbl_8055E844;
    if (flag != 0) {
        strcpy(name, lbl_8055AA5C);
    } else {
        sprintf(name, lbl_8055AA64, lbl_8055E844);
    }
    sprintf(lbl_80437FC0, lbl_80336F24, name, *(f32 *)entry);
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
          (int (*)(const void *, const void *))fn_801C3B7C);
}

#pragma auto_inline off
void fn_801C78D8(void) {
    lbl_8055E83C = 1;
    fn_801C957C(1);
    lbl_8055E83A = 1;
    lbl_8055E868 = fn_801C6CBC;
}

void fn_801C791C(void) {
    fn_801C78D8();
    lbl_8055E848 = 2;
}

void (*fn_801C7944(void))(void) {
    lbl_8055E83A = 1;
    lbl_8055E848 = 0;
    lbl_8055E868 = fn_801C6CB0;
    return fn_801C6CB0;
}

#pragma scheduling on
void fn_801C7964(void) {
    Vec* src = &lbl_80438268;
    Vec* dst = &lbl_80438250;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
void (*fn_801C7990(void))(void) {
    lbl_80437D88.f_6F8.x = lbl_80437D88.f_4E0.x;
    lbl_80437D88.f_6F8.y = lbl_80437D88.f_4E0.y;
    lbl_80437D88.f_6F8.z = lbl_80437D88.f_4E0.z;
    lbl_8055E83B = 1;
    lbl_80437D88.f_4D4.x = lbl_80437D88.f_4E0.x;
    lbl_80437D88.f_4D4.y = lbl_80437D88.f_4E0.y;
    lbl_80437D88.f_4D4.z = lbl_80437D88.f_4E0.z;
    lbl_8055E868 = fn_801C7964;
    return fn_801C7964;
}

void fn_801C79E0(void) {
    Vec *src = &lbl_80438268;
    Vec *dst = &lbl_8043848C;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    lbl_8055E83B = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83D = 1;
}

extern char lbl_80438280[];
extern char lbl_80438380[];
extern char lbl_8055A95C[7];
extern char lbl_8055AA44[4];
extern Vec lbl_80438498;
extern char lbl_8055E83D;
void fn_801C7A28(void) {
    lbl_80438498.x = lbl_80438268.x;
    lbl_80438498.y = lbl_80438268.y;
    lbl_80438498.z = lbl_80438268.z;
    lbl_8055E83A = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83D = 0;
    ((void (*)(f32, f32))fn_801C78D8)(lbl_80438268.y, lbl_80438268.x);
}

extern f64 atof(const char *);
void fn_801C7A6C(void) {
    f32 value = (f32)atof(lbl_804380F0);
    ((Vec *)0x80438498)->x = lbl_80562970;
    ((Vec *)0x80438498)->y = lbl_80562970;
    ((Vec *)0x80438498)->z = value;
    strcpy(lbl_804380F0, (char *)0x8055AA44);
}

#pragma push
#pragma small_data off
#pragma pop
extern Vec lbl_8043848C;
void fn_801C7AC4(void) {
    strcpy(lbl_80438280, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438280[0] == 0) strcpy(lbl_80438280, lbl_8055A95C);
}
void fn_801C7B28(void) {
    strcpy(lbl_80438380, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438380[0] == 0) strcpy(lbl_80438380, lbl_8055A95C);
    lbl_8055E868 = fn_801C6CB0;
    {
        volatile s32 zero = 0;
        lbl_8055E83A = zero;
    }
}

#pragma push
#pragma small_data off
#pragma pop
void fn_801C7BA0(void) {
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83D = 0; lbl_8055E83C = 0; lbl_8055E83B = 0; lbl_8055E83A = 0;
    strcpy(lbl_80438280, lbl_8055AA44);
    strcpy(lbl_80438380, lbl_8055AA44);
    fn_801C957C(0);
}

#pragma push
#pragma scheduling on
void fn_801C7C04(void) {
    extern f32 lbl_805629D4, lbl_8055E84C;
    extern char lbl_80336F4C[], lbl_80336F88[];
    extern double fn_8002EFB0(f32, f32);
    char *base = (char *)&lbl_80437D88;
    char *obj;
    Vec *start = (Vec *)(base + 0x6F8), *mid = (Vec *)(base + 0x704), *end = (Vec *)(base + 0x710);
    f32 a[2], b[2], c[2], d[2], e[2], f[2], g[2], h[2], i[2];
    f32 *p, *q;
    f32 x, y, len, scale;
    lbl_8055E84C = lbl_805629D4 * (f32)atof(base + 0x368);
    fn_801C957C(0);
    obj = fn_801C3C80();
    *(s32 *)(obj + 8) = 4;
    *(s32 *)(obj + 0x210) = lbl_8055E848;
    strcpy(obj + 0x10, base + 0x4F8);
    strcpy(obj + 0x110, base + 0x5F8);
    *(s32 *)(obj + 0xC) = fn_801C3954((s32)obj + 0x10);
    *(s32 *)(obj + 0xC) &= ~fn_801C3954((s32)obj + 0x110);
    *(f32 *)(obj + 0x214) = lbl_8055E84C;
    switch (*(s32 *)(obj + 0x210)) {
    case 2:
        *(f32 *)(obj + 0x220) = lbl_80562970;
        b[1] = end->z; b[0] = end->x;
        *(f32 *)(obj + 0x218) = b[0]; *(f32 *)(obj + 0x21C) = b[1];
        break;
    case 0:
        c[0] = start->x; c[1] = start->z;
        *(f32 *)(obj + 0x218) = c[0]; *(f32 *)(obj + 0x21C) = c[1];
        d[0] = end->x; d[1] = end->z;
        *(f32 *)(obj + 0x224) = d[0] - *(f32 *)(obj + 0x218);
        *(f32 *)(obj + 0x228) = d[1] - *(f32 *)(obj + 0x21C);
        f[1] = start->z; e[1] = mid->z;
        f[0] = start->x; e[0] = mid->x;
        a[0] = e[0] - f[0]; a[1] = e[1] - f[1];
        g[0] = lbl_80562970; g[1] = lbl_8056296C;
        q = g; p = a;
        len = a[0]*a[0] + a[1]*a[1];
        if (!((f32)__fabs((f64)(len-lbl_8056296C)) <= lbl_80558DC4[0])) {
            i[0] = a[0]; i[1] = a[1];
            scale = lbl_8056296C / (f32)fn_8002F234(len);
            i[0] *= scale; i[1] *= scale; p = i;
        }
        len = g[0]*g[0] + g[1]*g[1];
        if (!((f32)__fabs((f64)(len-lbl_8056296C)) <= lbl_80558DC4[0])) {
            h[0] = g[0]; h[1] = g[1];
            scale = lbl_8056296C / (f32)fn_8002F234(len);
            h[0] *= scale; h[1] *= scale; q = h;
        }
        *(f32 *)(obj + 0x220) = (f32)fn_8002EFB0(p[0]*q[1]-q[0]*p[1], p[0]*q[0]+p[1]*q[1]);
        break;
    default:
        fn_802E317C(lbl_80336F4C);
        break;
    }
    sprintf(base + 0x238, lbl_80336F88, *(f32 *)(base+0x6F8), *(f32 *)(base+0x700), *(f32 *)obj);
    fn_801C7BA0();
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}
#pragma pop
extern s32 lbl_8055E850;
extern void fn_801C78D8(void);
void fn_801C7EF4(void) {
    lbl_8055E850 = 0;
    fn_801C78D8();
}

extern char lbl_8055A964[7];
void fn_801C7F00(void) {
    strcpy(lbl_80438280, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438280[0] == 0) strcpy(lbl_80438280, lbl_8055A964);
}

#pragma push
#pragma small_data off
#pragma pop
void fn_801C7F64(void) {
    strcpy(lbl_80438380, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438380[0] == 0) strcpy(lbl_80438380, lbl_8055A95C);
    fn_801C957C(0);
    *(volatile s32 *)&lbl_8055E868 = (s32)fn_801C6CB0;
    *(volatile u8 *)&lbl_8055E83A = 1;
}

void fn_801C7FE4(void) {
    extern char lbl_80336FB0[];
    Unk_80437D88 *base = &lbl_80437D88;
    void *obj;
    lbl_8055E83A = 0;
    obj = fn_801C3C80();
    *(s32 *)((char *)obj + 8) = 6;
    *(s32 *)((char *)obj + 0xC) = lbl_8055E850;
    strcpy((char *)obj + 0x14, (char *)base + 0x4F8);
    strcpy((char *)obj + 0x114, (char *)base + 0x5F8);
    *(s32 *)((char *)obj + 0x10) = fn_801C3954((s32)obj + 0x14);
    *(s32 *)((char *)obj + 0x10) &= ~fn_801C3954((s32)obj + 0x114);
    *(f32 *)((char *)obj + 0x214) = *(f32 *)((char *)base + 0x4E0);
    *(f32 *)((char *)obj + 0x218) = *(f32 *)((char *)base + 0x4E4);
    *(f32 *)((char *)obj + 0x21C) = *(f32 *)((char *)base + 0x4E8);
    sprintf((char *)base + 0x238, lbl_80336FB0, *(f32 *)obj);
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}

extern s32 lbl_8055E854;
extern void fn_801C78D8(void);
void fn_801C80BC(void) {
    lbl_8055E854 = 0;
    fn_801C78D8();
}

void fn_801C80C8(void) {
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83A = 1;
    lbl_8055E854 = 2;
}

void fn_801C8190(void) {
    lbl_8055E854 = 1;
    fn_801C78D8();
}

extern f32 lbl_8055E85C;
extern f32 lbl_8055E860;
extern f32 lbl_8055A958;
extern s32 lbl_8055E864;
extern char lbl_804384A8[];
extern char lbl_804385A8[];
extern char lbl_80336FDC[];
extern void fn_801C7BA0(void);
void fn_801C819C(void) {
    lbl_8055E85C = lbl_80438268.x;
    lbl_8055E860 = lbl_80438268.z;
    fn_801C78D8();
}

extern char lbl_8055A964[7];
void fn_801C81B8(void) {
    strcpy(lbl_804384A8, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_804384A8[0] == 0) strcpy(lbl_804384A8, lbl_8055A964);
}

void fn_801C821C(void) {
    strcpy(lbl_804385A8, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_804385A8[0] == 0)
        strcpy(lbl_804385A8, lbl_8055A95C);
    lbl_8055E83A = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83C = 0;
}
#pragma push
#pragma scheduling off
#pragma dont_inline on
void fn_801C8298(void) {
    char *dst = lbl_804384A8;
    strcpy(dst, lbl_8055AA44);
    strcpy(lbl_804385A8, lbl_8055AA44);
    lbl_8055E864 = 0;
    fn_801C7BA0();
}

void fn_801C82E0(void) {
    extern char lbl_80336FC4[];
    extern f32 lbl_805629D4;
    extern f32 lbl_8055E85C;
    extern f32 lbl_8055E860;
    extern f32 lbl_8055E858;
    extern s32 lbl_8055E864;
    Unk_80437D88 *base = &lbl_80437D88;
    void *obj;
    f32 value = (f32)atof((char *)base + 0x368);
    lbl_8055E858 = lbl_805629D4 * value;
    obj = fn_801C3C80();
    *(s32 *)((char *)obj + 8) = 5;
    strcpy((char *)obj + 0x10, (char *)base + 0x720);
    *(s32 *)((char *)obj + 0x210) = lbl_8055E854;
    strcpy((char *)obj + 0x110, (char *)base + 0x820);
    *(s32 *)((char *)obj + 0xC) = fn_801C3954((s32)obj + 0x10);
    *(s32 *)((char *)obj + 0xC) &= ~fn_801C3954((s32)obj + 0x110);
    sprintf((char *)base + 0x238, lbl_80336FC4, *(f32 *)obj);
    *(f32 *)((char *)obj + 0x21C) = lbl_8055E85C;
    *(f32 *)((char *)obj + 0x220) = lbl_8055E860;
    *(f32 *)((char *)obj + 0x218) = lbl_8055E858;
    *(s32 *)((char *)obj + 0x214) = lbl_8055E864;
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    fn_801C8298();
}

#pragma dont_inline off
#pragma pop
void fn_801C83D0(void) {
    f32 value = (f32)atof(lbl_804380F0);
    lbl_8055A958 = value;
    sprintf(lbl_80437FC0, lbl_80336FDC, value);
    fn_801C957C(0);
}

void fn_801C94B8(void) {
    fn_80238A74();
}

void fn_801C94BC(void) {
    fn_80238B44();
}

void fn_801C94C0(s32 arg0, s32 arg1) {
    fn_8023895C();
    ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg0, arg1, (char *)((u32)lbl_80437FC0 | 0), -1);
    fn_802389E4();
}

extern void fn_801769EC(void);
extern void fn_80176610(void);
extern void __AXDSPInitCallback_801769E0(void);
#pragma push
#pragma processor 750
void fn_801C9514(void) {
    f32 end;
    f32 start;
    start = lbl_8055E3C8;
    fn_801769EC();
    end = lbl_805629AC + start;
    while (lbl_8055E3C8 < end && lbl_8055E3C8 >= start) {
        fn_80176610();
    }
    __AXDSPInitCallback_801769E0();
}
#pragma pop
void fn_801C95EC(f32 arg0) {
    lbl_8055E81C = arg0;
    lbl_8055E820 = arg0;
    lbl_8055E824 = arg0;
    fn_801C957C(1);
}

void fn_801C96E4(void) {
    lbl_8055E82C = lbl_8055E828 / 10;
}

void fn_801C9830(void) {
    return;
}

extern void fn_801C855C(void);
#pragma scheduling off
void fn_801C9834(void) {
    u8 *p;
    s32 idx;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    fn_801C855C();
    i = 11;
    p = (u8 *)&lbl_80337474;
    idx = 0;
loop:
    if (p[0] == 0xFF) { lbl_8055E824 = idx; goto done; }
    a = idx + 1;
    if (p[1] == 0xFF) { lbl_8055E824 = a; goto done; }
    b = a + 1;
    if (p[2] == 0xFF) { lbl_8055E824 = b; goto done; }
    c = b + 1;
    if (p[3] == 0xFF) { lbl_8055E824 = c; goto done; }
    d = c + 1;
    if (p[4] == 0xFF) { lbl_8055E824 = d; goto done; }
    p += 5;
    idx = d + 1;
    if (--i) goto loop;
done:
    lbl_8055E838 = 0;
}
#pragma scheduling on
void fn_801C98F0(void) {
    fn_801C9444();
}

#pragma push
#pragma scheduling off
void fn_801C98F4(u8 *p, s32 n) {
    s32 i;
    if (n <= 0) return;
    for (i = 0; i < n; i++) {
        while ((s8)*p != 0) p++;
        p++;
    }
}

extern char lbl_80336B00[];
extern s32 lbl_8055E814;
extern s32 fn_802E367C(void);
extern void fn_802E3734(s32 *);
extern void fn_802E3AD0(s32, const char *, ...);
s32 fn_801CA070(s32 *arg0) {
 s32 handle;
 s32 i, offset;
 s32 value;
 void *obj;
 char *base=lbl_80336B00;
 handle=fn_802E367C();
 if(handle!=-1) {
  value=lbl_8055E814;
  if(value==0) {
   obj=(void*)fn_801C3D5C();
   if(((s32(*)(void*,char*))(*(void***)obj)[3])(obj,base+0x130)!=0) {
    obj=(void*)fn_801C3D5C();
    value=((s32(*)(void*,char*))(*(void***)obj)[5])(obj,base+0x130);
   } else value=fn_80007F90(__AXFXGetLfoSinTable_801769CC()[1]);
  }
  fn_802E3AD0(handle,base+0xD04,value);
  fn_802E3AD0(handle,base+0xD10,lbl_8055A958);
  for(i=0,offset=0;i<lbl_8055E7F0;offset+=0x30C,i++)
   fn_801C9920(lbl_8055E7F8+offset,handle);
  fn_802E3AD0(handle,base+0xD24);
  fn_802E3734(&handle);
  sprintf(lbl_80437FC0,base+0xD30,arg0);
 } else sprintf(lbl_80437FC0,base+0xD48,arg0);
}

#pragma pop
extern char lbl_8055E7E0;
extern char lbl_8055E7E1;
extern char lbl_8055E80C;
extern s32 lbl_8033701C;
s32 fn_801C9708(void);
s32 fn_80176780(s32, s32);
s32 fn_801CA070(s32 *);
void fn_801C9514(void);
s32 fn_801C968C(s32);
s32 fn_801CB114(s32 arg0) {
    if ((u8)lbl_8055E838 != 0) return fn_801C9708();
    if (arg0 == 0x68) lbl_8055E7E0 = (u8)lbl_8055E7E0 == 0;
    if ((u8)lbl_8055E7E0 != 0) return 0;
    switch (arg0) {
    case 0x63: lbl_8055E80C = (u8)lbl_8055E80C == 0; break;
    case 0x72: fn_80176780(0x4200, 0); lbl_8055E7E1 = 1; break;
    case 0x6C: fn_801CA070(&lbl_8033701C); break;
    case 0x69: fn_801C9514(); break;
    case 0x126: fn_801C968C(-1); break;
    case 0x128: fn_801C968C(1); break;
    case 0x5B:
        if ((u8)lbl_8055E839 != 0) {
            if (lbl_8055E828 > 0) lbl_8055E828 -= 1;
            fn_801C96E4();
        } break;
    case 0x5D:
        if ((u8)lbl_8055E839 != 0) {
            if (lbl_8055E828 < lbl_8055E7F0 - 1) lbl_8055E828 += 1;
            fn_801C96E4();
        } break;
    case 0xD: fn_801C95EC((f32)0); break;
    }
    return 0;
}

extern s32 strlen(const char*);
extern void fn_8000FC8C(const char*);
extern void fn_8000FDF0(const char*);
extern f32 fn_801C3B6C(void);

extern void *fn_801C3C80(void);
extern void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
extern s32 fn_801C3B7C(const void *, const void *);
extern char lbl_80437FC0[304];
extern char lbl_80336EC8[];
extern s32 lbl_8055E7F0;
extern s32 lbl_8055E7F8;
void fn_801C6B70(void) {
    f32 val;
    f32 diff;
    s32 *str1;
    s32 *str0;
    f32 *ptr;
    
    ptr = (f32 *)&lbl_80437E24[0];
    val = ptr[2];
    
    if (val >= lbl_80562970) {
        if (lbl_8055E3C8 >= val) {
            diff = lbl_8055E3C8 - val;
            if (diff <= lbl_80562978) {
                ptr[2] = lbl_80562994;
                ptr[0] = 0.0f;
                ptr[1] = 0.0f;
            }
        }
    }
    
    str1 = (s32 *)lbl_80437E24[1];
    if (strlen((const char *)str1) != 0) {
        fn_8000FC8C((const char *)str1);
    }
    str0 = (s32 *)lbl_80437E24[0];
    if (strlen((const char *)str0) != 0) {
        fn_8000FDF0((const char *)str0);
    }
}

void fn_801C6AD0(s32 *arg0) {
    if (lbl_8055E7E2) {
        f32 temp_f1 = fn_801C3B6C();
        if (temp_f1 < lbl_8056296C) {
            f32 diff = lbl_805629C8 * (lbl_8056296C - temp_f1);
            s32 original = *arg0;
            s32 result;
            if (diff >= lbl_80562970) {
                result = (s32)(diff - lbl_80562974);
            } else {
                result = (s32)(diff + lbl_80562974);
            }
            if (result > original) {
                if (result < 0xFF) {
                    *arg0 = result;
                }
            }
        }
    }
}

#pragma push
#pragma scheduling off
void fn_801C6D94(void) {
    s32 r30, r31, r12, r11, r10, r9, r8, r7, r6, r5, r4, r0;
    s32 *src;
    s32 *dst;
    
    src = lbl_80499050;
    dst = lbl_80438220;
    
    r30 = *src++;
    *dst++ = r30;
    r31 = *src;  *src++;
    *dst = r31;  dst++;
    r12 = *src;  *src++;
    *dst = r12;  dst++;
    r11 = *src;  *src++;
    *dst = r11;  dst++;
    r10 = *src;  *src++;
    *dst = r10;  dst++;
    r9 = *src;   *src++;
    *dst = r9;   dst++;
    r8 = *src;   *src++;
    *dst = r8;   dst++;
    r7 = *src;   *src++;
    *dst = r7;   dst++;
    r6 = *src;   *src++;
    *dst = r6;   dst++;
    r5 = *src;   *src++;
    *dst = r5;   dst++;
    r4 = *src;   *src++;
    *dst = r4;   dst++;
    r0 = *src;   *src++;
    *dst = r0;   dst++;
    
    fn_801C957C(1, r4, r5, r6, r7, r8, r9, r10);
}
#pragma pop
void fn_801C7254(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 t;
    
    t = p[1]; p[1] = p[3]; p[3] = t;
    t = p[2]; p[2] = p[6]; p[6] = t;
    t = p[5]; p[5] = p[7]; p[7] = t;
}
