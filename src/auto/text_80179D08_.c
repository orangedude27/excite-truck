// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

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

#pragma scheduling off
static f32 fn_load(void) { return lbl_80561B78; }
void* fn_80179D08(void *arg0) {
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
    b = lbl_80561B78;
    *(s32 *)((u8 *)arg0 + 0xC) = (s32)arg1;
    a = lbl_80561B7C;
    *(f32 *)((u8 *)arg0 + 0x30) = a;
    *(f32 *)((u8 *)arg0 + 0x34) = a;
    *(f32 *)((u8 *)arg0 + 0x38) = a;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(f32 *)((u8 *)arg0 + 0x2C) = a;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)arg1;
    *(s32 *)((u8 *)arg0 + 0x4) = 0;
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

void fn_80179E00(void *arg0) {
    s32 i;
    void *p;
    s32 last; s32 m, l, k, j, h, g, f, e, d, c, b, a;
    i = 0; p = arg0;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    goto check;
loop:
    ((void (**)(void *))*(void **)*(void **)((u8 *)p + 0x14))[10](*(void **)((u8 *)p + 0x14));
    p = (u8 *)p + 4; i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x28)) goto loop;
    fn_8017A580(arg0);
    a = *(s32 *)((u8 *)arg0 + 0x70); b = *(s32 *)((u8 *)arg0 + 0x74);
    c = *(s32 *)((u8 *)arg0 + 0x78); d = *(s32 *)((u8 *)arg0 + 0x7C);
    e = *(s32 *)((u8 *)arg0 + 0x80); f = *(s32 *)((u8 *)arg0 + 0x84);
    g = *(s32 *)((u8 *)arg0 + 0x88); h = *(s32 *)((u8 *)arg0 + 0x8C);
    j = *(s32 *)((u8 *)arg0 + 0x90); k = *(s32 *)((u8 *)arg0 + 0x94);
    l = *(s32 *)((u8 *)arg0 + 0x98); m = *(s32 *)((u8 *)arg0 + 0x9C);
    *(s32 *)((u8 *)arg0 + 0xA0) = a; *(s32 *)((u8 *)arg0 + 0xA4) = b;
    *(s32 *)((u8 *)arg0 + 0xA8) = c; *(s32 *)((u8 *)arg0 + 0xAC) = d;
    *(s32 *)((u8 *)arg0 + 0xB0) = e; *(s32 *)((u8 *)arg0 + 0xB4) = f;
    *(s32 *)((u8 *)arg0 + 0xB8) = g; *(s32 *)((u8 *)arg0 + 0xBC) = h;
    *(s32 *)((u8 *)arg0 + 0xC0) = j; *(s32 *)((u8 *)arg0 + 0xC4) = k;
    *(s32 *)((u8 *)arg0 + 0xC8) = l; *(s32 *)((u8 *)arg0 + 0xCC) = m;
    fn_801E9DC4((u8 *)arg0 + 0x6C);
}

void fn_80179EE4(void) {

}

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
extern f64 lbl_80561B90;
extern f32 PSVECMag(f32 *);
extern f64 sin(f64);
extern f64 cos(f64);
extern void fn_8017AE94(void *, f32 *, f32 *, f32);
void fn_8017A028(void *arg0,u16 *arg1,u16 *arg2,s32 *arg3,s32 *arg4,f32 arg5) {
f32 a[3],b[3],m0[12],m1[12],x,y,z,mag,k,c,s,t;
fn_8017A008((u8*)a,(u8*)arg1+8,12); fn_8017A008((u8*)b,(u8*)arg2+8,12);
#define CL(v) ((v)<0.0f?0.0f:((v)>1.0f?1.0f:(v)))
x=CL(((f32)arg1[2]-1.0f)/65535.0f)*2.0f-1.0f; y=CL(((f32)arg1[1]-1.0f)/65535.0f)*2.0f-1.0f; z=CL(((f32)arg1[0]-1.0f)/65535.0f)*2.0f-1.0f; a[0]=x;a[1]=y;a[2]=z;
x=CL(((f32)arg2[2]-1.0f)/65535.0f)*2.0f-1.0f; y=CL(((f32)arg2[1]-1.0f)/65535.0f)*2.0f-1.0f; z=CL(((f32)arg2[0]-1.0f)/65535.0f)*2.0f-1.0f; b[0]=x;b[1]=y;b[2]=z;
mag=PSVECMag(a); if(mag>lbl_80561B8C){k=1.0f/mag;x=a[0]*k;y=a[1]*k;z=a[2]*k;s=(f32)sin(mag);c=(f32)cos(mag);t=1.0f-c;m0[0]=c+t*x*x;m0[1]=t*x*y+s*z;m0[2]=t*x*z-s*y;m0[3]=t*x*y-s*z;m0[4]=c+t*y*y;m0[5]=t*y*z+s*x;m0[6]=t*x*z+s*y;m0[7]=t*y*z-s*x;m0[8]=c+t*z*z;}else{m0[0]=1;m0[1]=0;m0[2]=0;m0[3]=0;m0[4]=1;m0[5]=0;m0[6]=0;m0[7]=0;m0[8]=1;}
mag=PSVECMag(b);if(mag>lbl_80561B8C){k=1.0f/mag;x=b[0]*k;y=b[1]*k;z=b[2]*k;s=(f32)sin(mag);c=(f32)cos(mag);t=1.0f-c;m1[0]=c+t*x*x;m1[1]=t*x*y+s*z;m1[2]=t*x*z-s*y;m1[3]=t*x*y-s*z;m1[4]=c+t*y*y;m1[5]=t*y*z+s*x;m1[6]=t*x*z+s*y;m1[7]=t*y*z-s*x;m1[8]=c+t*z*z;}else{m1[0]=1;m1[1]=0;m1[2]=0;m1[3]=0;m1[4]=1;m1[5]=0;m1[6]=0;m1[7]=0;m1[8]=1;}
fn_8017AE94((u8*)arg0+0x3c,m0,m1,arg5);fn_8017A580(arg0);*arg3=20;*arg4=20;}

void fn_8017A578(void *arg0) {
    fn_8017A580(arg0);
}

void fn_8017A57C(void) {

}

void fn_8017A800(void) {

}

void fn_80179EE8(void*, s32);
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
#pragma scheduling on
