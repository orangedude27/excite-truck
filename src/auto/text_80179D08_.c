// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
typedef struct { s32 w[12]; } Blk12;
typedef struct { s32 w[9]; } Blk9;
static inline void MtxMulVec3(f32 *m, f32 *src, f32 *dst) {
    f32 x, y, z;
    if (dst == src) {
        x = src[0]; y = src[1]; z = src[2];
        dst[0] = (x * m[0] + y * m[3]) + z * m[6];
        dst[1] = (x * m[1] + y * m[4]) + z * m[7];
        dst[2] = (x * m[2] + y * m[5]) + z * m[8];
    } else {
        x = src[0]; y = src[1]; z = src[2];
        dst[0] = (x * m[0] + y * m[3]) + z * m[6];
        dst[1] = (x * m[1] + y * m[4]) + z * m[7];
        dst[2] = (x * m[2] + y * m[5]) + z * m[8];
    }
}

extern void fn_80128668(void *);
extern void fn_801E9DC4(void *);
extern s32 lbl_80331C70[16];
extern f32 lbl_80561B78;
extern f32 lbl_80561B7C;
extern void fn_8017A580(void *);
extern f32 PSVECMag(f32 *);
extern f64 sin(f64);
extern f64 cos(f64);
extern void fn_8017AE94(void *, f32 *, f32 *, f32);
extern f64 lbl_80561B90;
extern f32 lbl_80561B80, lbl_80561B84, lbl_80561B88, lbl_80561B8C;

#pragma cplusplus on
struct Fn80179E00Dummy {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
};
struct Fn80179F94Dummy {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual f32 m13(void *, void *, s32) = 0;
};
extern "C" inline void fn_80179E00_virtual_call(void *obj) {
    ((Fn80179E00Dummy *)obj)->m8();
}
#pragma cplusplus reset
extern void fn_80179E00_virtual_call(void *);

#pragma scheduling off
static f32 fn_load(void) { return lbl_80561B78; }
#pragma scheduling invalid_target
void *fn_80179D08(void *arg0) {
    f32 a = lbl_80561B7C;
    f32 b = lbl_80561B78;
    *(s32 *)arg0 = (s32)&lbl_80331C70[0];
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_8017A580(arg0);
    fn_801E9DC4((u8 *)arg0 + 0x6C);
    return arg0;
}
#pragma scheduling on
void fn_80179D8C(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

void fn_80179D94(void *arg0, void *arg1) {
    f32 b;
    f32 a;
    s32 zero;
    a = lbl_80561B7C;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = (s32)arg1;
    b = lbl_80561B78;
    *(f32 *)((u8 *)arg0 + 0x30) = a;
    *(f32 *)((u8 *)arg0 + 0x34) = a;
    *(f32 *)((u8 *)arg0 + 0x38) = a;
    *(s32 *)((u8 *)arg0 + 0x24) = zero;
    *(s32 *)((u8 *)arg0 + 0x28) = zero;
    *(f32 *)((u8 *)arg0 + 0x2C) = a;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)arg1;
    *(s32 *)((u8 *)arg0 + 0x4) = zero;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_801E9DC4((u8 *)arg0 + 0x6C);
}

#pragma cplusplus on
extern "C" void fn_80179E00(void *object) {
    /* Resets the object's per-frame state, updates children and transform, snapshots the current transform, and clears a flag word. */
    struct Dummy {
        virtual void m0() = 0; virtual void m1() = 0; virtual void m2() = 0;
        virtual void m3() = 0; virtual void m4() = 0; virtual void m5() = 0;
        virtual void m6() = 0; virtual void m7() = 0; virtual void m8() = 0;
    };
    s32 childIndex;
    void *childIter;
    s32 m, l, k, j, h, g, f, e, d, c, b, a;
    volatile s32 *base = (volatile s32 *)object;

    *(s32 *)((u8 *)object + 4) = 0;
    childIndex = 0;
    childIter = object;
    goto check;
loop:
    ((struct Dummy *)*(void **)((u8 *)childIter + 0x14))->m8();
    childIter = (u8 *)childIter + 4;
    childIndex++;
check:
    if (childIndex < *(s32 *)((u8 *)object + 0x28)) goto loop;
    fn_8017A580(object);
    b = base[0x70 / 4]; a = base[0x74 / 4];
    c = base[0x78 / 4]; d = base[0x7C / 4];
    e = base[0x80 / 4]; f = base[0x84 / 4];
    g = base[0x88 / 4]; h = base[0x8C / 4];
    j = base[0x90 / 4]; k = base[0x94 / 4];
    l = base[0x98 / 4]; m = base[0x9C / 4];
    *(s32 *)((u8 *)object + 0xA0) = b; *(s32 *)((u8 *)object + 0xA4) = a;
    *(s32 *)((u8 *)object + 0xA8) = c; *(s32 *)((u8 *)object + 0xAC) = d;
    *(s32 *)((u8 *)object + 0xB0) = e; *(s32 *)((u8 *)object + 0xB4) = f;
    *(s32 *)((u8 *)object + 0xB8) = g; *(s32 *)((u8 *)object + 0xBC) = h;
    *(s32 *)((u8 *)object + 0xC0) = j; *(s32 *)((u8 *)object + 0xC4) = k;
    *(s32 *)((u8 *)object + 0xC8) = l; *(s32 *)((u8 *)object + 0xCC) = m;
    fn_801E9DC4((u8 *)object + 0x6C);
    return;
}
#pragma cplusplus reset
void fn_80179EE4(void) {

}

#pragma dont_inline on
#pragma cplusplus on
extern "C" void *fn_80179EE8(void *obj, s32 shouldFree) {
    struct ItemDummy {
        virtual void m0(s32) = 0;
    };
    u8 *p;
    void *item;
    s32 i;

    /* Destroys contained items (vtable+0x8) and optionally frees the object; returns obj. */
    if (obj != NULL) {
        *(s32 *)obj = (s32)&lbl_80331C70[0];
        p = (u8 *)obj;
        i = 0;
        goto check;
    loop:
        item = *(void **)(p + 0x14);
        if (item != NULL)
            ((ItemDummy *)item)->m0(1);
        p += 4;
        i += 1;
    check:
        if (i < *(s32 *)((u8 *)obj + 0x28))
            goto loop;
        if (shouldFree > 0)
            fn_80128668(obj);
    }
    return obj;
}
#pragma cplusplus reset
#pragma dont_inline reset

#pragma push
#pragma scheduling off
#pragma cplusplus on
extern "C" void fn_80179F94(void *arg0, void *arg1) {
    s32 count;
    void *slot;
    f32 value;
    f32 old;
    count = *(s32 *)((u8 *)arg0 + 0x24);
    slot = (u8 *)arg0 + count * 4;
    *(void **)((u8 *)slot + 0x14) = arg1;
    count++;
    *(s32 *)((u8 *)arg0 + 0x24) = count;
    *(s32 *)((u8 *)arg0 + 0x28) = count;
    value = ((Fn80179F94Dummy *)arg1)->m13(arg1, slot, count - 1);
    old = *(f32 *)((u8 *)arg0 + 0x2C);
    old = old > value ? old : value;
    *(f32 *)((u8 *)arg0 + 0x2C) = old;
}
#pragma cplusplus reset
#pragma pop
void fn_8017A004(void) {

}

void fn_8017A008(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}

extern f32 lbl_80561B80, lbl_80561B84, lbl_80561B88, lbl_80561B8C;
extern f32 lbl_80561B98, lbl_80561B9C;
extern f32 lbl_80558DC4[];
extern f64 fn_8002EFA8(f64);
extern f32 fn_8002F234(void *, int, int, f32, f32, f32, f32, f32, f32, f32);
extern f64 lbl_80561B90;
extern f32 PSVECMag(f32 *);
extern f64 sin(f64);
extern f64 cos(f64);
extern void fn_8017AE94(void *, f32 *, f32 *, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_8017A028(void *o,u16 *p,u16 *q,s32 *r,s32 *s,f32 angle) {
 f32 va[3],vb[3],a[3],b[3],m[9],n[9],x,y,z,mag,k,c,si,t;
 fn_8017A008((u8*)va,(u8*)p+8,12);fn_8017A008((u8*)vb,(u8*)q+8,12);
 x=((f32)p[2]-lbl_80561B7C)/lbl_80561B80; if(x<lbl_80561B78)x=((f32)p[2]-lbl_80561B7C)/lbl_80561B80; if(x>lbl_80561B7C)x=lbl_80561B7C;
 y=((f32)p[1]-lbl_80561B7C)/lbl_80561B80; if(y<lbl_80561B78)y=((f32)p[1]-lbl_80561B7C)/lbl_80561B80; if(y>lbl_80561B7C)y=lbl_80561B7C;
 z=((f32)p[0]-lbl_80561B7C)/lbl_80561B80; if(z<lbl_80561B78)z=((f32)p[0]-lbl_80561B7C)/lbl_80561B80; if(z>lbl_80561B7C)z=lbl_80561B7C;
 a[0]=lbl_80561B84+z*lbl_80561B88;a[1]=lbl_80561B84+y*lbl_80561B88;a[2]=lbl_80561B84+x*lbl_80561B88;
 x=((f32)q[2]-lbl_80561B7C)/lbl_80561B80;if(x<lbl_80561B78)x=((f32)q[2]-lbl_80561B7C)/lbl_80561B80;if(x>lbl_80561B7C)x=lbl_80561B7C;
 y=((f32)q[1]-lbl_80561B7C)/lbl_80561B80;if(y<lbl_80561B78)y=((f32)q[1]-lbl_80561B7C)/lbl_80561B80;if(y>lbl_80561B7C)y=lbl_80561B7C;
 z=((f32)q[0]-lbl_80561B7C)/lbl_80561B80;if(z<lbl_80561B78)z=((f32)q[0]-lbl_80561B7C)/lbl_80561B80;if(z>lbl_80561B7C)z=lbl_80561B7C;
 b[0]=lbl_80561B84+z*lbl_80561B88;b[1]=lbl_80561B84+y*lbl_80561B88;b[2]=lbl_80561B84+x*lbl_80561B88;
 mag=PSVECMag(a);if(mag>lbl_80561B8C){k=lbl_80561B78/mag;x=k*a[0];y=k*a[1];z=k*a[2];si=(f32)sin(mag);c=(f32)cos(mag);t=lbl_80561B78-c;m[0]=c+t*x*x;m[1]=t*x*y+si*z;m[2]=t*x*z-si*y;m[3]=t*x*y-si*z;m[4]=c+t*y*y;m[5]=t*y*z+si*x;m[6]=t*x*z+si*y;m[7]=t*y*z-si*x;m[8]=c+t*z*z;}else{m[0]=lbl_80561B78;m[1]=lbl_80561B7C;m[2]=lbl_80561B7C;m[3]=lbl_80561B7C;m[4]=lbl_80561B78;m[5]=lbl_80561B7C;m[6]=lbl_80561B7C;m[7]=lbl_80561B7C;m[8]=lbl_80561B78;}
 mag=PSVECMag(b);if(mag>lbl_80561B8C){k=lbl_80561B78/mag;x=k*b[0];y=k*b[1];z=k*b[2];si=(f32)sin(mag);c=(f32)cos(mag);t=lbl_80561B78-c;n[0]=c+t*x*x;n[1]=t*x*y+si*z;n[2]=t*x*z-si*y;n[3]=t*x*y-si*z;n[4]=c+t*y*y;n[5]=t*y*z+si*x;n[6]=t*x*z+si*y;n[7]=t*y*z-si*x;n[8]=c+t*z*z;}else{n[0]=lbl_80561B78;n[1]=lbl_80561B7C;n[2]=lbl_80561B7C;n[3]=lbl_80561B7C;n[4]=lbl_80561B78;n[5]=lbl_80561B7C;n[6]=lbl_80561B7C;n[7]=lbl_80561B7C;n[8]=lbl_80561B78;}
 fn_8017AE94((u8*)o+0x3c,m,n,angle);fn_8017A580(o);*r=20;*s=20;
}
#pragma pop
void fn_8017A578(void *arg0) {
    fn_8017A580(arg0);
}

void fn_8017A57C(void) {

}

void fn_8017A580(void *arg0) {
    u8 *p = (u8 *)arg0;
    s32 i;
    f32 x, y, z;
    void *v;
    s32 n;
    for (i = 0; i < 12; i++) ((s32 *)p)[0x28/4 + i] = ((s32 *)p)[0x1C/4 + i];
    if (p + 0x94 == p + 0x30) {
        x = *(f32 *)(p+0x30); y = *(f32 *)(p+0x34); z = *(f32 *)(p+0x38);
        *(f32 *)(p+0x94) = (x * *(f32 *)(p+0x3C) + y * *(f32 *)(p+0x48)) + z * *(f32 *)(p+0x54);
        *(f32 *)(p+0x98) = (x * *(f32 *)(p+0x40) + y * *(f32 *)(p+0x4C)) + z * *(f32 *)(p+0x58);
        *(f32 *)(p+0x9C) = (x * *(f32 *)(p+0x44) + y * *(f32 *)(p+0x50)) + z * *(f32 *)(p+0x5C);
    } else {
        x = *(f32 *)(p+0x30); y = *(f32 *)(p+0x34); z = *(f32 *)(p+0x38);
        *(f32 *)(p+0x94) = (x * *(f32 *)(p+0x3C) + y * *(f32 *)(p+0x48)) + z * *(f32 *)(p+0x54);
        *(f32 *)(p+0x98) = (x * *(f32 *)(p+0x40) + y * *(f32 *)(p+0x4C)) + z * *(f32 *)(p+0x58);
        *(f32 *)(p+0x9C) = (x * *(f32 *)(p+0x44) + y * *(f32 *)(p+0x50)) + z * *(f32 *)(p+0x5C);
    }
    *(f32 *)(p+0x94) += *(f32 *)(p+0x60);
    *(f32 *)(p+0x98) += *(f32 *)(p+0x64);
    *(f32 *)(p+0x9C) += *(f32 *)(p+0x68);
    for (i=0;i<9;i++) ((s32 *)p)[0x1c+i] = ((s32 *)p)[0x0f+i];
    if (((s32 (**)(void *))*(void **)p)[17](arg0) && ((s32 (**)(void *))*(void **)p)[16](arg0)) {
      for (i=0;i<*(s32 *)(p+0x28);i++) {
        v=*(void **)(p+0x14+i*4);
        ((void (**)(void *))*(void **)v)[3](v);
      }
    }
}

void fn_8017A800(void) {

}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
s32 fn_8017A804(void *arg0, void *arg1) {
    f32 v[3], q[4];
    f32 *qp;
    f32 (*m)[3] = (f32 (*)[3])((u8 *)arg0 + 0x3C);
    f32 trace, t, scale, angle, si, x, y, z;
    s32 i, j, k, pad;
    *(f32 *)((u8 *)arg1+8)=*(f32 *)((u8 *)arg0+0x60);
    *(f32 *)((u8 *)arg1+12)=*(f32 *)((u8 *)arg0+0x64);
    *(f32 *)((u8 *)arg1+16)=*(f32 *)((u8 *)arg0+0x68);
    trace=m[2][2]+(m[0][0]+m[1][1]);
    if(trace>lbl_80561B7C){
        t=(f32)((double (*)(float))fn_8002F234)(lbl_80561B78+trace);
        scale=lbl_80561B98/t;
        q[3]=lbl_80561B98*t;
        q[0]=scale*(m[1][2]-m[2][1]);
        q[1]=scale*(m[2][0]-m[0][2]);
        q[2]=scale*(m[0][1]-m[1][0]);
    }else{
        qp = q;
        i=0;
        if(m[1][1]>m[0][0])i=1;
        if(m[2][2]>m[i][i])i=2;
        j=(i+1)%3; k=(j+1)%3;
        t=(f32)((double (*)(float))fn_8002F234)(lbl_80561B78+(m[i][i]-(m[j][j]+m[k][k])));
        scale=lbl_80561B98/t;
        qp[i]=lbl_80561B98*t;
        qp[3]=scale*(m[j][k]-m[k][j]);
        qp[j]=scale*(m[i][j]+m[j][i]);
        qp[k]=scale*(m[i][k]+m[k][i]);
    }
    angle=(f32)fn_8002EFA8(q[3]);
    si=(f32)sin(angle);
    if((f32)__fabs(si)>lbl_80558DC4[0]){
        scale=(lbl_80561B9C*angle)/si;
        v[0]=q[0]*scale; v[1]=q[1]*scale; v[2]=q[2]*scale;
    }else{v[0]=lbl_80561B7C;v[1]=lbl_80561B7C;v[2]=lbl_80561B7C;}
    x=(v[0]-lbl_80561B84)/lbl_80561B88;
    x=lbl_80561B78<x?lbl_80561B78:x;
    x=x>lbl_80561B7C?x:lbl_80561B7C;
    y=(v[1]-lbl_80561B84)/lbl_80561B88;
    ((s16*)arg1)[0]=(s16)(lbl_80561B98+(lbl_80561B7C+x*lbl_80561B80));
    y=lbl_80561B78<y?lbl_80561B78:y;
    y=y>lbl_80561B7C?y:lbl_80561B7C;
    z=(v[2]-lbl_80561B84)/lbl_80561B88;
    ((s16*)arg1)[1]=(s16)(lbl_80561B98+(lbl_80561B7C+y*lbl_80561B80));
    z=lbl_80561B78<z?lbl_80561B78:z;
    z=z>lbl_80561B7C?z:lbl_80561B7C;
    ((s16*)arg1)[2]=(s16)(lbl_80561B98+(lbl_80561B7C+z*lbl_80561B80));
    return 20;
}
#pragma pop

void fn_8017AB84(void *matrix, float *dst, const float *src) {
    if (dst == src) {
        float x = src[0], y = src[1], z = src[2];
        float ox = (x * *(float *)((char *)matrix + 0x3C) + y * *(float *)((char *)matrix + 0x48)) + z * *(float *)((char *)matrix + 0x54);
        float oy = (x * *(float *)((char *)matrix + 0x40) + y * *(float *)((char *)matrix + 0x4C)) + z * *(float *)((char *)matrix + 0x58);
        float oz = (x * *(float *)((char *)matrix + 0x44) + y * *(float *)((char *)matrix + 0x50)) + z * *(float *)((char *)matrix + 0x5C);
        dst[0] = ox;
        dst[1] = oy;
        dst[2] = oz;
    } else {
        dst[0] = (src[0] * *(float *)((char *)matrix + 0x3C) + src[1] * *(float *)((char *)matrix + 0x48)) + src[2] * *(float *)((char *)matrix + 0x54);
        dst[1] = (src[0] * *(float *)((char *)matrix + 0x40) + src[1] * *(float *)((char *)matrix + 0x4C)) + src[2] * *(float *)((char *)matrix + 0x58);
        dst[2] = (src[0] * *(float *)((char *)matrix + 0x44) + src[1] * *(float *)((char *)matrix + 0x50)) + src[2] * *(float *)((char *)matrix + 0x5C);
    }
    dst[0] += *(float *)((char *)matrix + 0x60);
    dst[1] += *(float *)((char *)matrix + 0x64);
    dst[2] += *(float *)((char *)matrix + 0x68);
}


void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017B038(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_8017B090(void) {

}

int fn_8017B094(void) {
    return 0x14;
}

void fn_8017B09C(void* arg0, signed char* arg1) {
    *arg1 = 0;
}
extern int lbl_80331C28[64];
#pragma scheduling off
void** fn_8017ACCC(void** arg0) {
    fn_80179D08(arg0);
    *arg0 = &lbl_80331C28;
    return arg0;
}

extern void *fn_801284F8(int, void *);
extern void fn_80179F94(void *, void *);
extern void fn_802E30C8(const char *);
extern f32 fn_8002F234(void *, int, int, f32, f32, f32, f32, f32, f32, f32);
extern f32 lbl_80561BA0, lbl_80561BA4;
extern const char lbl_80331BF8[], lbl_80331C04[], lbl_80333B98[], lbl_803338C0[];
#pragma dont_inline fn_80179F94
void fn_8017AD08(void *dst, void *src) {
    unsigned char *srcBytes = (unsigned char *)src;
    unsigned char *dstBytes = (unsigned char *)dst;
    void *obj;
    int first, second;
    int zero = 0;
    int box = 0x424F5820;
    float x, y, z;
    const char *vtable;

    ((void (*)(void *))fn_80179D94)(dst);

    first = *(int *)(srcBytes + 8);
    second = *(int *)(srcBytes + 0xC);
    *(int *)(dstBytes + 0x3C) = first;
    *(int *)(dstBytes + 0x40) = second;
    first = *(int *)(srcBytes + 0x10);
    second = *(int *)(srcBytes + 0x14);
    *(int *)(dstBytes + 0x44) = first;
    *(int *)(dstBytes + 0x48) = second;
    first = *(int *)(srcBytes + 0x18);
    second = *(int *)(srcBytes + 0x1C);
    *(int *)(dstBytes + 0x4C) = first;
    *(int *)(dstBytes + 0x50) = second;
    first = *(int *)(srcBytes + 0x20);
    second = *(int *)(srcBytes + 0x24);
    *(int *)(dstBytes + 0x54) = first;
    *(int *)(dstBytes + 0x58) = second;
    *(int *)(dstBytes + 0x5C) = *(int *)(srcBytes + 0x28);
    first = *(int *)(srcBytes + 0x2C);
    second = *(int *)(srcBytes + 0x30);
    *(int *)(dstBytes + 0x60) = first;
    *(int *)(dstBytes + 0x64) = second;
    *(int *)(dstBytes + 0x68) = *(int *)(srcBytes + 0x34);

    fn_8017A580(dst);
    if (*(int *)(srcBytes + 0x38) == 0) {
        obj = fn_801284F8(0x38, (void *)lbl_80331BF8);
        if (obj != 0) {
            z = *(float *)(srcBytes + 0x44);
            vtable = lbl_80333B98;
            y = *(float *)(srcBytes + 0x40);
            x = *(float *)(srcBytes + 0x3C);
            *(void **)obj = (void *)vtable;
            *(void **)((unsigned char *)obj + 0xC) = dstBytes + 0x3C;
            *(float *)((unsigned char *)obj + 0x10) = lbl_80561BA0;
            *(float *)((unsigned char *)obj + 0x14) = lbl_80561BA4;
            *(int *)((unsigned char *)obj + 0x18) = box;
            *(int *)((unsigned char *)obj + 0x20) = 100;
            *(int *)((unsigned char *)obj + 4) = zero;
            *(int *)((unsigned char *)obj + 8) = zero;
            *(int *)((unsigned char *)obj + 0x1C) = zero;
            *(void **)obj = (void *)lbl_803338C0;
            *(float *)((unsigned char *)obj + 0x24) = x;
            *(float *)((unsigned char *)obj + 0x28) = y;
            *(float *)((unsigned char *)obj + 0x2C) = z;
            *(int *)((unsigned char *)obj + 0x34) = zero;
            *(float *)((unsigned char *)obj + 0x30) = lbl_80561BA4 +
                (float)((double (*)(float))fn_8002F234)(x * x + y * y + z * z);
            fn_80179F94(dst, obj);
            return;
        }
    }
    fn_802E30C8(lbl_80331C04);
}

extern void PSVECCrossProduct(float *, float *, float *);
extern void PSVECNormalize(float *, float *);
#pragma optimize_for_size on
#pragma unroll off
void fn_8017AE94(void *arg0, float *arg1, float *arg2, float farg0) {
    float *base = (float *)arg0;
    float *out = base;
    float *a = arg1;
    float *b = arg2;
    struct Temps { float sp8[3]; float sp14[3]; float sp20[3]; } temp;
    register int i;
    for (i = 0; i < 2; i++) {
        float vb0, va0, vb1, d0, va1, vb2, d1, va2, p0, vb3;
        float p1, d2, va3, v0, vb4, d3, p2, va4, d4, vb5;
        float va5, p3, v1, d5, p4, p5, v2, v3, v4, v5;
        vb0 = b[0];
        va0 = a[0];
        vb1 = b[1];
        d0 = vb0 - va0;
        va1 = a[1];
        vb2 = b[2];
        d1 = vb1 - va1;
        va2 = a[2];
        p0 = farg0 * d0;
        vb3 = b[3];
        p1 = farg0 * d1;
        d2 = vb2 - va2;
        va3 = a[3];
        v0 = va0 + p0;
        vb4 = b[4];
        d3 = vb3 - va3;
        p2 = farg0 * d2;
        va4 = a[4];
        d4 = vb4 - va4;
        vb5 = b[5];
        va5 = a[5];
        p3 = farg0 * d3;
        out[0] = v0;
        v1 = va1 + p1;
        a += 6;
        d5 = vb5 - va5;
        p4 = farg0 * d4;
        b += 6;
        p5 = farg0 * d5;
        out[1] = v1;
        v2 = va2 + p2;
        v3 = va3 + p3;
        v4 = va4 + p4;
        out[2] = v2;
        v5 = va5 + p5;
        out[3] = v3;
        out[4] = v4;
        out[5] = v5;
        out += 6;
    }
    PSVECNormalize(base, base);
    PSVECNormalize(base + 3, base + 3);
    PSVECNormalize(base + 6, base + 6);
    {
        float x, y, z;
        z = base[2]; y = base[1]; x = base[0];
        temp.sp8[0] = x; temp.sp8[1] = y; temp.sp8[2] = z;
        z = base[8]; y = base[7]; x = base[6];
        temp.sp20[0] = x; temp.sp20[1] = y; temp.sp20[2] = z;
    }
    PSVECCrossProduct(temp.sp20, temp.sp8, temp.sp14);
    PSVECNormalize(temp.sp8, temp.sp8);
    PSVECNormalize(temp.sp14, temp.sp14);
    PSVECCrossProduct(temp.sp8, temp.sp14, temp.sp20);
    base[0] = temp.sp8[0]; base[1] = temp.sp8[1]; base[2] = temp.sp8[2];
    base[3] = temp.sp14[0]; base[4] = temp.sp14[1]; base[5] = temp.sp14[2];
    base[6] = temp.sp20[0]; base[7] = temp.sp20[1]; base[8] = temp.sp20[2];
}
#pragma unroll reset
#pragma optimize_for_size reset
