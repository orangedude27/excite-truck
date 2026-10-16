#include <types.h>
#include <revolution/MTX/vec.h>

extern char lbl_8055E839;
extern s32 lbl_8055E828;
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
extern char lbl_80437FC0[304];
extern char lbl_80336EC8[];
extern char lbl_80336EE8[];
extern s32 lbl_8055E7F0;
extern s32 lbl_8055E7F8;
extern s32 lbl_80499050[12];
extern s32 lbl_804381F0[12];
extern s32 lbl_80438220[12];
extern f32 lbl_8056296C;
extern f32 lbl_8055E3C8;
extern f32 lbl_80562970;
extern f32 lbl_80562978;
extern f32 lbl_80562994;
extern f32 lbl_80562974;
extern f32 lbl_805629C8;
extern s32 lbl_80437E24[3];
extern f32 lbl_80558DC4[];
extern double fn_8002F234(float);
extern void fn_8012F57C(float *, float *, float *, float);
extern f32 lbl_8056296C, lbl_80562970, lbl_80562974;
void fn_801C2FF4(float *out, float *a, float *b, float weight) {
    float qa[4], qb[4], q[4];
    float x, y, z, w, s;
    int i, j, k;
    x = a[0] + a[4] + a[8];
    if (x > lbl_80562970) {
        s = (float)fn_8002F234(lbl_8056296C + x);
        s = lbl_80562974 / s;
        qa[0] = lbl_80562974 * (lbl_80562974 / s);
        qa[1] = s * (a[5] - a[7]);
        qa[2] = s * (a[6] - a[2]);
        qa[3] = s * (a[1] - a[3]);
    } else {
        i = 0;
        if (a[4] > a[0]) i = 1;
        if (a[8] > a[i * 3 + i]) i = 2;
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        s = (float)fn_8002F234(lbl_8056296C + a[i * 3 + i] - (a[j * 3 + k] + a[k * 3 + j]));
        s = lbl_80562974 / s;
        qa[i] = lbl_80562974 * (lbl_80562974 / s);
        qa[3] = s * (a[j * 3 + k] - a[k * 3 + j]);
        qa[j] = s * (a[i * 3 + j] + a[j * 3 + i]);
        qa[k] = s * (a[i * 3 + k] + a[k * 3 + i]);
    }
    x = b[0] + b[4] + b[8];
    if (x > lbl_80562970) {
        s = (float)fn_8002F234(lbl_8056296C + x);
        s = lbl_80562974 / s;
        qb[0] = lbl_80562974 * (lbl_80562974 / s);
        qb[1] = s * (b[5] - b[7]);
        qb[2] = s * (b[6] - b[2]);
        qb[3] = s * (b[1] - b[3]);
    } else {
        i = 0;
        if (b[4] > b[0]) i = 1;
        if (b[8] > b[i * 3 + i]) i = 2;
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        s = (float)fn_8002F234(lbl_8056296C + b[i * 3 + i] - (b[j * 3 + k] + b[k * 3 + j]));
        s = lbl_80562974 / s;
        qb[i] = lbl_80562974 * (lbl_80562974 / s);
        qb[3] = s * (b[j * 3 + k] - b[k * 3 + j]);
        qb[j] = s * (b[i * 3 + j] + b[j * 3 + i]);
        qb[k] = s * (b[i * 3 + k] + b[k * 3 + i]);
    }
    fn_8012F57C(q, qa, qb, weight);
    w=q[0]; x=q[1]; y=q[2]; z=q[3];
    out[12] = a[12] + weight*(b[12]-a[12]);
    out[13] = a[13] + weight*(b[13]-a[13]);
    out[14] = a[14] + weight*(b[14]-a[14]);
    out[0]=1-2*(y*y+z*z); out[4]=1-2*(x*x+z*z); out[8]=1-2*(x*x+y*y);
    out[7]=2*(y*z-w*x); out[2]=2*(y*z+w*x);
    out[1]=2*(x*y-w*z); out[3]=2*(x*y+w*z);
    out[6]=2*(x*z-w*y); out[5]=2*(x*z+w*y);
}

s32 fn_801C34CC(f32 arg0, f32 arg1) {
    f32 diff = arg0 - arg1;
    f64 abs = __fabs((f64)diff);
    return (f32)abs <= lbl_80558DC4[0];
}

s32 *__AXFXGetLfoSinTable_801769CC(void);
void *fn_8001285C(s32);
extern f32 lbl_80562990;
extern f32 lbl_8055E7E4;
f32 fn_801C3B6C(void) {
    return lbl_8055E7E4 + lbl_8055E3C8;
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

void fn_801C3C14(s32 arg0) {
    s32 offset = arg0 * 0x30C;
    memset((void *)(lbl_8055E7F8 + offset), 0, 0x30C);
    *(f32 *)(lbl_8055E7F8 + offset) = lbl_80562994;
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
          (int (*)(const void *, const void *))fn_801C3B7C);
    lbl_8055E7F0--;
}

s32 fn_801C3D5C(void) {
    return *(s32 *)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
}

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
    s32 *sptr = (s32 *)ptr;
    s32 tmp = 2;
    sptr[2] = tmp;
    (void)sptr;
    sprintf(lbl_80437FC0, lbl_80336EC8, ((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}

extern char lbl_80336EE8[];
void fn_801C72F0(void) {
    void *ptr;
    f32 val;
    
    ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 7;
    strncpy((char *)ptr + 0x10C, lbl_804380F0, 0x1FF);
    val = ((f32 *)ptr)[0];
    sprintf(lbl_80437FC0, lbl_80336EE8, val);
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
void fn_801C7770(void) {
    u32 value = __cntlzw(lbl_8055E83E);
    lbl_8055E83E = value >> 5;
}

void fn_801C77C0(void) {
    lbl_8055E844 = atoi(lbl_804380F0);
    lbl_8055E841 = 0;
    fn_801C957C(0);
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
extern char lbl_8055A95C[];
extern char lbl_8055AA44[];
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
    lbl_8055E83A = 0;
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

#pragma push
#pragma small_data off
#pragma pop
void fn_801C7F64(void) {
    strcpy(lbl_80438380, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438380[0] == 0) strcpy(lbl_80438380, lbl_8055A95C);
    fn_801C957C(0);
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83A = 1;
}
extern s32 lbl_8055E854;
extern void fn_801C78D8(void);
void fn_801C80BC(void) {
    lbl_8055E854 = 0;
    fn_801C78D8();
}

void fn_801C94B8(void) {
    fn_80238A74();
}

void fn_801C94BC(void) {
    fn_80238B44();
}

void fn_801C9830(void) {
    return;
}

void fn_801C98F0(void) {
    fn_801C9444();
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

void fn_801C7254(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 t;
    
    t = p[1]; p[1] = p[3]; p[3] = t;
    t = p[2]; p[2] = p[6]; p[6] = t;
    t = p[5]; p[5] = p[7]; p[7] = t;
}
