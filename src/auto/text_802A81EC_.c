#include "types.h"
void fn_802A8A4C(s32, s32);
static inline void transform_802A8A4C(f32 *m, f32 *src, f32 *dst) {
    if ((u32)src == (u32)dst) {
        f32 x=src[0], y=src[1], z=src[2];
        dst[0]=z*m[6]+(x*m[0]+y*m[3]);
        dst[1]=z*m[7]+(x*m[1]+y*m[4]);
        dst[2]=z*m[8]+(x*m[2]+y*m[5]);
    } else {
        dst[0]=src[2]*m[6]+(src[0]*m[0]+src[1]*m[3]);
        dst[1]=src[2]*m[7]+(src[0]*m[1]+src[1]*m[4]);
        dst[2]=src[2]*m[8]+(src[0]*m[2]+src[1]*m[5]);
    }
}
extern f32 PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_80564928, lbl_8056494C;
extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern f32 fn_80287BC8(f32, f32);
extern f32 lbl_80564944, lbl_80564948, lbl_80564950;


extern f32 lbl_8055E3C8;

extern s32 lbl_804BD6C4[];
extern f32 lbl_8055F8D4;
extern f32 lbl_8055F8D8;
extern f32 lbl_80564954;

s32 fn_802A8A34(void* ptr);
s32 fn_802A8A3C(s32 *arg0, s32 arg1);
void fn_802A8978(void);
void fn_802A81EC(void);

void fn_802A81EC(void) {

}

extern void fn_80128668(void *);
extern void fn_802C6CF8(s32);
void fn_802A85C8(void) {
    void *entry;
    s32 j;
    s32 offset;
    s32 suboffset;
    s32 i;

    i = 0;
    offset = 0;
    while (i < lbl_804BD6C4[1]) {
        entry = *(void **)((u32)lbl_804BD6C4[0] + offset);
        if (entry != 0) {
            j = 0;
            suboffset = 0;
            while (j < *(s32 *)((u8 *)entry + 0x2C)) {
                fn_802C6CF8(*(s32 *)((u32)*(u32 *)((u8 *)entry + 0x28) + suboffset));
                suboffset += 4;
                j++;
            }
            *(s32 *)((u8 *)entry + 0x2C) = 0;
            *(s32 *)((u8 *)entry + 0x70) = 0;
            if ((u32)entry + 0x6C != 0) {
                *(s32 *)((u8 *)entry + 0x70) = 0;
                if ((u32)entry + 0x6C != 0) {
                    *(s32 *)((u8 *)entry + 0x6C) = 0;
                    *(s32 *)((u8 *)entry + 0x70) = 0;
                    *(s32 *)((u8 *)entry + 0x74) = 0;
                }
            }
            if ((u32)entry + 0x28 != 0) {
                if ((u32)entry + 0x28 != 0) {
                    *(s32 *)((u8 *)entry + 0x28) = 0;
                    *(s32 *)((u8 *)entry + 0x2C) = 0;
                    *(s32 *)((u8 *)entry + 0x30) = 0;
                }
            }
            fn_80128668(entry);
        }
        offset += 4;
        i++;
    }
    lbl_804BD6C4[1] = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802A86A4(void) {
    struct { f32 a[4]; f32 p[3]; f32 v[3]; } sp;
    s32 i, offset, j, suboffset;
    u8 *entry;
    f32 *v;
    f32 z, y, x, scale, speed;
    f32 zero = lbl_80564928;
    f32 one = lbl_8056494C;
    f32 half = lbl_80564950;
    i = 0; offset = 0;
    while (i < lbl_804BD6C4[1]) {
        entry = *(u8 **)((u32)lbl_804BD6C4[0] + offset);
        memset(&sp, 0, 0);
        x = *(f32 *)(entry + 0x60);
        y = *(f32 *)(entry + 0x64);
        z = *(f32 *)(entry + 0x68);
        sp.p[0] = x; sp.p[1] = y; sp.p[2] = z;
        sp.a[1] = *(f32 *)(entry + 0x58);
        sp.a[0] = *(f32 *)(entry + 0x44);
        sp.a[3] = *(f32 *)(entry + 0x4c);
        sp.a[2] = *(f32 *)(entry + 0x4c);
        memcpy(entry + 0x18, &sp, 0x10);
        ((f32 *)entry)[0] = sp.p[0];
        ((f32 *)entry)[1] = sp.p[1];
        ((f32 *)entry)[2] = sp.p[2];
        z = fn_80287BC8(lbl_80564944, lbl_80564948);
        ((f32 *)entry)[3] = fn_80287BC8(lbl_80564944, lbl_80564948);
        ((f32 *)entry)[4] = zero;
        ((f32 *)entry)[5] = z;
        if ((f32)__fabs(PSVECDotProduct(entry + 0xc, entry + 0xc)) <= lbl_80558DC4) ((f32 *)entry)[3] = one;
        PSVECNormalize(entry + 0xc, entry + 0xc);
        speed = ((f32 *)entry)[8];
        ((f32 *)entry)[3] *= speed;
        ((f32 *)entry)[4] *= speed;
        ((f32 *)entry)[5] *= speed;
        j = 0; suboffset = 0;
        sp.a[1] = *(f32 *)(entry + 0x5c);
        sp.a[0] = *(f32 *)(entry + 0x48);
        sp.a[3] = *(f32 *)(entry + 0x54);
        sp.a[2] = *(f32 *)(entry + 0x50);
        scale = *(f32 *)(entry + 0x48) * half;
        while (j < *(s32 *)(entry + 0x70)) {
            v = (f32 *)(*(u32 *)(entry + 0x6c) + suboffset);
            z = fn_80287BC8(-scale, scale);
            y = fn_80287BC8(-scale, scale);
            x = fn_80287BC8(-scale, scale);
            sp.v[0] = x; sp.v[1] = y; sp.v[2] = z;
            sp.p[0] = ((f32 *)entry)[0] + (f32)x;
            sp.p[1] = ((f32 *)entry)[1] + (f32)y;
            sp.p[2] = ((f32 *)entry)[2] + (f32)z;
            memcpy(v + 6, &sp, 0x10);
            v[0] = sp.p[0]; v[1] = sp.p[1]; v[2] = sp.p[2];
            y = fn_80287BC8(lbl_80564944, lbl_80564948);
            v[3] = fn_80287BC8(lbl_80564944, lbl_80564948);
            v[4] = zero; v[5] = y;
            if ((f32)__fabs(PSVECDotProduct(v + 3, v + 3)) <= lbl_80558DC4) v[3] = one;
            PSVECNormalize(v + 3, v + 3);
            speed = v[8];
            v[3] *= speed; v[4] *= speed; v[5] *= speed;
            suboffset += 0x28; j++;
        }
        offset += 4; i++;
    }
}
#pragma pop

void fn_802A8978(void) {
    s32* base;
    u8* entry;
    s32 j;
    s32 offset;
    s32 i;
    f32 temp;

    temp = lbl_8055E3C8;
    lbl_8055F8D4 = temp - lbl_8055F8D8;
    if (temp < lbl_8055F8D8) {
        lbl_8055F8D4 = lbl_80564954;
    }
    lbl_8055F8D8 = temp;
    base = (s32*)&lbl_804BD6C4;
    i = 0;
    offset = 0;
    while (i < base[1]) {
        entry = *(u8**)((u32)lbl_804BD6C4[0] + offset);
        fn_802A8A4C((s32)entry, (s32)(entry + 0x60));
        j = 0;
        while (j < fn_802A8A34((void*)(entry + 0x6c))) {
            fn_802A8A4C(fn_802A8A3C((s32 *)(entry + 0x6c), j), (s32)entry);
            j++;
        }
        offset += 4;
        i++;
    }
}

s32 fn_802A8A34(void* ptr) {
    return ((s32*)ptr)[1];
}

s32 fn_802A8A3C(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 0x28;
}

extern f64 fn_8002F234(f32), cos(f64), sin(f64);
extern f32 lbl_80564958, lbl_80564968, lbl_8056496C;
extern f64 lbl_80564960;
#pragma push
void fn_802A8A4C(s32 arg0, s32 arg1) {
    f32 m[9], v[2], d[2], p[2], q[2];
    f32 *a = (f32 *)arg0, *b = (f32 *)arg1;
    f32 length, dot, angle, scale, t, c, s, x, y, z;
    v[0]=a[3]; v[1]=a[5];
    scale=lbl_8056494C/(f32)fn_8002F234(v[0]*v[0]+v[1]*v[1]);
    v[0]*=scale; v[1]*=scale;
    p[0]=a[0]; p[1]=a[2];
    q[0]=b[0]; q[1]=b[2];
    d[0]=q[0]-p[0]; d[1]=q[1]-p[1];
    length=d[0]*d[0]+d[1]*d[1];
    if (!((f32)__fabs(length)<=lbl_80558DC4)) {
        scale=lbl_8056494C/(f32)fn_8002F234(length);
        d[0]*=scale; d[1]*=scale;
    }
    dot=v[0]*d[0]+v[1]*d[1];
    angle=fn_80287BC8(lbl_80564928,lbl_8056494C);
    t=a[6]*lbl_80564958;
    if (length>t*t && dot>(f32)cos(lbl_80564960)) angle=lbl_80564928;
    t=a[6]/lbl_80564968;
    t=t*t;
    scale=(length-t)/(a[6]*a[6]-t);
    scale=lbl_8056494C<scale?lbl_8056494C:scale;
    scale=scale>lbl_80564928?scale:lbl_80564928;
    angle=lbl_8055F8D4*((lbl_80564928+scale*(angle-lbl_80564928))*(lbl_8056496C*a[7]));
    c=(f32)cos(angle); s=(f32)sin(angle);
    m[0]=c; m[1]=lbl_80564928; m[2]=-s;
    m[3]=lbl_80564928; m[4]=lbl_8056494C; m[5]=lbl_80564928;
    m[6]=s; m[7]=lbl_80564928; m[8]=c;
    transform_802A8A4C(m,a+3,a+3);
    PSVECNormalize(a+3,a+3);
    scale=(length-lbl_80564928)/(a[6]*a[6]-lbl_80564928);
    scale=lbl_8056494C<scale?lbl_8056494C:scale;
    scale=scale>lbl_80564928?scale:lbl_80564928;
    t=a[8]+scale*(a[9]-a[8]);
    a[3]*=t; a[4]*=t; a[5]*=t;
    a[0]+=a[3]*lbl_8055F8D4;
    a[1]+=a[4]*lbl_8055F8D4;
    a[2]+=a[5]*lbl_8055F8D4;
}
#pragma pop

extern f32 PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
extern void PSVECCrossProduct(const void *, const void *, void *);
extern void fn_802C744C(s32 arg0, void *arg1);
extern f32 lbl_80558DC4;
extern f32 lbl_80564928;
extern f32 lbl_8056494C;
__declspec(section ".data") extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
#pragma use_lmw_stmw off
void fn_802A8DE8(void) {
    f32 vecData[6];
    f32 crossIn[3];
    f32 crossOut[3];
    f32 fx;
    f32 fy;
    register s32 i;
    register s32 *table;
    register s32 offset;
    register u8 *vec;
    register void *entry;
    register s32 j;

    fy = lbl_80564928;
    fx = lbl_8056494C;
    table = (s32 *)&lbl_804BD6C4;
    i = 0;
    offset = 0;
    while (i < table[1]) {
        entry = *(void **)((u32)lbl_804BD6C4[0] + offset);
        j = 0;
        vec = (u8 *)0;
        while (j < *(s32 *)((u8 *)entry + 0x70)) {
            f32 *src = (f32 *)(*(u32 *)((u8 *)entry + 0x6C) + (u32)vec);
            vecData[3] = src[0];
            vecData[4] = src[1];
            vecData[5] = src[2];
            vecData[0] = src[3];
            vecData[1] = src[4];
            vecData[2] = src[5];
            if ((f32)__fabs((f64)PSVECDotProduct(&vecData[0], &vecData[0])) <= lbl_80558DC4) {
                vecData[0] = fy;
                vecData[1] = fy;
                vecData[2] = fx;
            }
            PSVECNormalize(&vecData[0], &vecData[0]);
            crossIn[0] = fy;
            crossIn[1] = fx;
            crossIn[2] = fy;
            PSVECCrossProduct(crossIn, &vecData[0], crossOut);
            fn_802C744C(*(s32 *)(*(u32 *)((u8 *)entry + 0x28) + ((j % *(s32 *)((u8 *)entry + 0x2C)) * 4)), crossOut);
            vec = (u8 *)((u32)vec + 0x28);
            j++;
        }
        offset += 4;
        i++;
    }
}
#pragma pop
