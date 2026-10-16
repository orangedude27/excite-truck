#include <types.h>
#include <revolution/MTX/vec.h>

extern char lbl_8055E839;
  
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E7E2;
extern s32 lbl_8055E804;
extern f32 lbl_805629CC;
extern u8* fn_8017960C(s32);
extern Vec lbl_80438268;
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
    
    if (val < lbl_80562970) {
        if (lbl_8055E3C8 >= val) {
            diff = lbl_8055E3C8 - val;
            if (diff <= lbl_80562978) {
                ptr[2] = lbl_80562994;
                ptr[0] = 0.0f;
                ptr[1] = 0.0f;
            }
        }
    }
    
    str1 = (s32 *)&lbl_80437E24[1];
    if (strlen((const char *)str1) != 0) {
        fn_8000FC8C((const char *)str1);
    }
    str0 = (s32 *)&lbl_80437E24[0];
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
    s32 *src = lbl_80499050;
    s32 *dst = lbl_80438220;
    
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
    
    fn_801C957C(1, src[10], src[9], src[8], src[7], src[6], src[5], src[4]);
}

void fn_801C7254(void *arg0) {
    f32 *ptr = (f32 *)arg0;
    f32 t0 = ptr[1];
    f32 t1 = ptr[3];
    f32 t2 = ptr[2];
    f32 t3 = ptr[6];
    f32 t4 = ptr[5];
    f32 t5 = ptr[7];
    ptr[1] = t1;
    ptr[3] = t0;
    ptr[2] = t3;
    ptr[6] = t2;
    ptr[5] = t5;
    ptr[7] = t4;
}

