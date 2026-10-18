#include <types.h>
#include <revolution/MTX/vec.h>

extern char lbl_8055E839;
extern s32 lbl_8055E828;
extern s32 lbl_8055E81C;
extern s32 lbl_8055E820;
extern s32 lbl_8055E824;
extern char lbl_8055E838;
extern u8 lbl_8055E83F;
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
    f32 numerator;
    f32 offset;

    denom = fn_801C2F58(2, lbl_80562978);
    numerator = (f32)(s32)(arg0 * denom);
    offset = *(f32 *)&lbl_80562980;
    return (f32)((s32)numerator - (s32)offset) / denom;
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
    sprintf(lbl_80437FC0, lbl_80336EC8, (double)((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}

extern char lbl_80336EE8[];
void fn_801C72F0(void) {
    void *ptr;
    f32 *value;
    ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 7;
    strncpy((char *)ptr + 0x10C, lbl_804380F0, 0x1FF);
    value = (f32 *)ptr;
    sprintf(lbl_80437FC0, lbl_80336EE8, *value);
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
extern char lbl_8055E841;
extern s32 lbl_8055E844;
extern char lbl_8055E83A;
extern char lbl_8055E83C;
extern void (*lbl_8055E868)(void);
extern s32 lbl_8055E848;
extern int atoi(const char *);
extern char lbl_8055E83B;
extern char lbl_8055E83D;
extern Vec lbl_80438250;
typedef struct {
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
    fn_801C855C();
    i = 11;
    p = (u8 *)lbl_80337474;
    idx = 0;
loop:
    if (p[0] == 0xFF) goto done;
    idx++;
    if (p[1] == 0xFF) goto done;
    idx++;
    if (p[2] == 0xFF) goto done;
    idx++;
    if (p[3] == 0xFF) goto done;
    idx++;
    if (p[4] == 0xFF) goto done;
    p += 5;
    idx++;
    if (--i) goto loop;
done:
    lbl_8055E824 = idx;
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
#pragma pop
extern char lbl_8055E7E0;
extern char lbl_8055E7E1;
extern char lbl_8055E80C;
extern s32 lbl_8033701C;
s32 fn_801C9708(void);
s32 fn_80176780(s32, s32);
s32 fn_801CA070(s32 *);
s32 fn_801C9514(void);
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
