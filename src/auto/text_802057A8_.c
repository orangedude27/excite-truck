// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma ppc_psq_save off
extern int lbl_8055ED6C;
extern void fn_802CAC54(void);
extern int fn_802CAC28(const char *, int);
extern char lbl_8033BC40[];
extern int fn_801E85A4(void);
extern unsigned char fn_802C2C00(unsigned char);
extern void fn_80205D5C(void);
extern int fn_80205964(void);
extern void fn_80205850(void);
extern void fn_80205FCC(void);
extern void fn_802059C0(void);
extern int fn_801B8570(void);
extern void fn_801E866C(int);
#pragma inline no fn_80205964
extern void fn_802C8CBC(int);
extern void fn_802C8DBC(int);
extern void fn_802C8E48(void);
extern void fn_802C8D74(void);
extern void fn_802057A8(int, int, float, float, float, float);
#pragma dont_inline fn_802057A8
extern float lbl_80563194, lbl_805631A8, lbl_805631B8, lbl_805631BC, lbl_805631C0;
#pragma dont_inline on
extern void fn_802C8E00(float, float, float, float, float, float, float);
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern float lbl_80563190, lbl_80563194, lbl_80563198, lbl_8056319C;
extern float lbl_805631A0, lbl_805631A4, lbl_805631A8;
#pragma scheduling invalid_target
void fn_802057A8(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5) {
    extern double lbl_805631B0;
    register unsigned int high asm("r5") = 0x43300000;
    register unsigned int raw asm("r0");
    register unsigned int converted asm("r6");
    register float temp_f1 asm("f1") = arg2;
    register float temp_f6 asm("f6");
    register float temp_f7 asm("f7");
    struct {
        float coords[3];
        unsigned int pad;
        union {
            struct {
                unsigned int hi;
                unsigned int lo;
            } words;
            double d;
        } conv1;
        union {
            struct {
                unsigned int hi;
                unsigned int lo;
            } words;
            double d;
        } conv2;
    } local;

    temp_f1 -= lbl_80563194;
    temp_f6 = temp_f1 * lbl_80563198;
    raw = (unsigned int)lbl_8055CFF0;
    converted = raw ^ 0x80000000U;
    local.conv1.words.lo = converted;
    local.conv1.words.hi = high;
    raw = (unsigned int)lbl_8055CFF4;
    raw ^= 0x80000000U;
    local.conv2.words.lo = raw;
    local.conv2.words.hi = high;
    temp_f6 = temp_f6 * lbl_8056319C;
    temp_f1 = arg3 * lbl_805631A4;
    temp_f7 = lbl_805631A0 + temp_f1;
    temp_f6 = lbl_80563190 + temp_f6;
    local.coords[2] = lbl_805631A8;
    local.coords[0] = (float)(local.conv1.d - lbl_805631B0);
    local.coords[0] *= temp_f6;
    local.coords[1] = (float)(local.conv2.d - lbl_805631B0);
    local.coords[1] *= temp_f7;
    ((void (*)(int, int, float, float, float, float, float, float, float))fn_802C8E00)(
        arg0, arg1, local.coords[0], local.coords[1], local.coords[2], arg4, arg5, temp_f6, temp_f7);
}
#pragma scheduling on
/* Initializes/configures a set of 8 parameter entries via fn_802057A8 using constant float globals (-1, 0, 1, 0.005, 0.995), bracketed by setup/teardown calls to fn_802C8CBC/DBC/E48/D74. */
void fn_80205850(void) {
    fn_802C8CBC(-1);
    fn_802C8DBC(0x20);
    fn_802057A8(-1, 0, lbl_80563194, lbl_805631A8, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 0, lbl_805631B8, lbl_805631A8, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 1, lbl_80563194, lbl_805631BC, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 1, lbl_805631B8, lbl_805631BC, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 0, lbl_80563194, lbl_805631C0, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 0, lbl_805631B8, lbl_805631C0, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 1, lbl_80563194, lbl_805631B8, lbl_805631A8, lbl_805631A8);
    fn_802057A8(-1, 1, lbl_805631B8, lbl_805631B8, lbl_805631A8, lbl_805631A8);
    fn_802C8E48();
    fn_802C8D74();
}

#pragma dont_inline
int fn_80205964(void) {
    int i = 0;
    while (i < fn_801E85A4()) {
        fn_801E866C(i);
        if (fn_801B8570() != 0) return 1;
        ++i;
    }
    return 0;
}

extern float fn_8013672C(void);
extern void *fn_801E7E3C(void);
extern void *fn_801EA9A0(int);
extern float lbl_80563194,lbl_805631A8,lbl_805631B8,lbl_805631C4,lbl_805631C8,lbl_805631CC,lbl_805631D0,lbl_805631D4,lbl_805631D8,lbl_805631DC,lbl_805631E0,lbl_805631E4,lbl_805631E8;
extern double lbl_805631B0;
#pragma push
#pragma processor 750
void fn_802059C0(void) {
    double sp18,sp20,bias;
    float temp_f14,temp_f15,temp_f16,temp_f19,temp_f21,f1,f0,f2,f18,f20;
    float k0,k1,kC4,kC8,kCC,kD4,kD0,kD8,kDC,kE0;
    int i,n,idx,col,col2,c24,c23,c4,cnt;
    void *obj;
    union { struct { unsigned int hi,lo; } w; double d; } conv;
    temp_f21=fn_8013672C();
    temp_f19=temp_f21*(float)*(int*)((char*)fn_801E7E3C()+8);
    n=fn_801E85A4();
    sp18=lbl_805631E8; k0=lbl_805631A8; i=0;
    sp20=lbl_805631E4; k1=lbl_805631B8; bias=lbl_805631B0;
    kC4=lbl_805631C4; kC8=lbl_805631C8; kCC=lbl_805631CC; kD4=lbl_805631D4;
    kD0=lbl_805631D0; kD8=lbl_805631D8; kDC=lbl_805631DC; kE0=lbl_805631E0;
    for(;i<n;i++){
        idx=((int(*)(int))fn_801E866C)(i);
        if(fn_801B8570()==0) continue;
        obj=fn_801EA9A0(idx);
        cnt=*(int*)((char*)obj+0x1C);
        f1=*(float*)((char*)*(void**)((char*)obj+8)+0x2C8);
        if(cnt==0){cnt=1;f1=lbl_805631A8;}
        conv.w.hi=0x43300000; conv.w.lo=(unsigned int)(cnt-1)^0x80000000U;
        f1=(f1+(float)(conv.d-bias)*temp_f21)/temp_f19;
        if(k1<f1)f1=k1;
        f0=(f1-k0)/kC4;
        if(k1<f0)f0=k1;
        if(k0>f0)f0=k0;
        c4=(int)(k0+f0*kC8);
        c24=(c4<<24)|(i==0 ? 0xFFFF0000 : 0xFF0000FF); c23=c24&0xFF7F7F7F;
        if(i==0)f18=lbl_80563194;else f18=lbl_805631B8;
        temp_f16=f18*kCC;
        f2=(f1-k0)/k1;
        temp_f15=kD0*(kD4*kCC);
        if(k1<f2)f2=k1;
        if(k0>f2)f2=k0;
        temp_f14=temp_f15+f2*(k1-temp_f15);
        if((unsigned char)c4!=0){
            fn_802C8CBC(-1); fn_802C8DBC(6);
            col=c24&0xFFFFFF; col2=c23&0xFFFFFF;
            fn_802057A8(col,0,f18,temp_f14,lbl_805631A8,lbl_805631A8);
            fn_802057A8(col2,0,lbl_805631A8,temp_f14,lbl_805631A8,lbl_805631A8);
            f20=temp_f14-kD8; if(k0>f20)f20=k0;
            fn_802057A8(c24,1,f18,f20,lbl_805631A8,lbl_805631A8);
            fn_802057A8(c23,1,lbl_805631A8,f20,lbl_805631A8,lbl_805631A8);
            f1=(f20-kDC)/kE0;
            if(k1<f1)f1=k1;
            if(k0>f1)f1=k0;
            f20=f20-((float)sp20+f1*(float)sp18);
            if(k0>f20)f20=k0;
            fn_802057A8(col,1,f18,f20,lbl_805631A8,lbl_805631A8);
            fn_802057A8(col2,1,lbl_805631A8,f20,lbl_805631A8,lbl_805631A8);
            fn_802C8E48(); fn_802C8D74();
        }
        if(lbl_8055ED6C!=-2){
            ((void(*)(int))fn_802C8CBC)(0); fn_802C8DBC(4);
            fn_802057A8(-1,0,temp_f16,temp_f14,lbl_805631B8,lbl_805631A8);
            fn_802057A8(-1,0,lbl_805631A8,temp_f14,lbl_805631B8,lbl_805631B8);
            temp_f14=temp_f14-temp_f15;
            fn_802057A8(-1,1,temp_f16,temp_f14,lbl_805631A8,lbl_805631A8);
            fn_802057A8(-1,1,lbl_805631A8,temp_f14,lbl_805631A8,lbl_805631B8);
            fn_802C8E48(); fn_802C8D74();
        }
    }
}
#pragma pop
extern int lbl_802F9D90[4];
extern float lbl_805631D4, lbl_805631EC;
#pragma ppc_psq_save off
void fn_80205D5C(void) {
    int rawr[4];
    float off[4];
    float a[3], b[3], c[3], d[3];
    float f3, f0, f31, f29, f30;
    int i;
    fn_802C8CBC(-1);
    fn_802C8DBC(0x10);
    f3 = lbl_80563198 * (lbl_805631D4 * (float)lbl_8055CFF0);
    f31 = (float)lbl_8055CFF0 * lbl_80563198;
    f29 = lbl_805631A8;
    rawr[0] = lbl_802F9D90[0];
    rawr[1] = lbl_802F9D90[1];
    rawr[2] = lbl_802F9D90[2];
    rawr[3] = lbl_802F9D90[3];
    f0 = lbl_805631EC * f3;
    off[0] = f0;
    off[1] = f3;
    off[2] = f3;
    off[3] = f0;
    for (i = 0; i < 4; i++) {
        a[0] = f31 + off[i];
        a[1] = (float)lbl_8055CFF4 * *(float *)&rawr[i];
        a[2] = f29;
        ((void (*)(int, int, float, float, float, float, float))fn_802C8E00)(0x404040, i > 0, a[0], a[1], a[2], f29, f29);
        b[0] = f31;
        b[1] = (float)lbl_8055CFF4 * *(float *)&rawr[i];
        b[2] = f29;
        ((void (*)(int, int, float, float, float, float, float))fn_802C8E00)(0xFF404040, i > 0, f31, b[1], f29, f29, f29);
    }
    f30 = lbl_805631A8;
    for (i = 0; i < 4; i++) {
        c[0] = f31 - off[i];
        c[1] = (float)lbl_8055CFF4 * *(float *)&rawr[i];
        c[2] = f30;
        ((void (*)(int, int, float, float, float, float, float))fn_802C8E00)(0x404040, i > 0, c[0], c[1], c[2], f30, f30);
        d[0] = f31;
        d[1] = (float)lbl_8055CFF4 * *(float *)&rawr[i];
        d[2] = f30;
        ((void (*)(int, int, float, float, float, float, float))fn_802C8E00)(0xFF404040, i > 0, f31, d[1], f30, f30, f30);
    }
    fn_802C8E48();
    fn_802C8D74();
}
#pragma ppc_psq_save reset
extern float lbl_80563198, lbl_805631A0, lbl_805631CC, lbl_805631E4, lbl_805631F0, lbl_805631F4;
extern double lbl_805631B0;
extern char lbl_804891D0[];
extern char lbl_804891DC[];
extern char lbl_8033BC18[];
extern char lbl_8033BC2C[];
extern int lbl_8055CFF0, lbl_8055CFF4;
extern unsigned int lbl_8055E044;
extern unsigned char lbl_8055ED70, lbl_8055ED71;
extern void *fn_802C86DC(void);
extern void fn_802C88FC();
extern void fn_802C8638(void *);
extern void fn_801312EC(void *, void *);
extern void fn_80131318(void);
extern void fn_80010188(int, int, int, ...);
typedef struct { float m[12]; } Mtx48;
typedef struct { int w[8]; } Blk32;
typedef struct { int w[3]; } Blk12;
typedef struct { Blk32 a; int b; Blk12 c; } Cam48;
#pragma cplusplus on
#pragma push
#pragma processor 750
extern "C" void fn_80205FCC(void) {
    Cam48 cam;
    Mtx48 buf;
    float f31;
    cam = *(Cam48 *)fn_802C86DC();
    fn_802C88FC(&buf);
    buf.m[3] *= lbl_80563194;
    buf.m[4] *= lbl_80563194;
    buf.m[5] *= lbl_80563194;
    fn_802C8638(&buf);
    if ((signed char)lbl_8055ED70 == 0) {
        fn_801312EC(lbl_804891D0, lbl_8033BC18);
        lbl_8055ED70 = 1;
    }
    if ((signed char)lbl_8055ED71 == 0) {
        fn_801312EC(lbl_804891DC, lbl_8033BC2C);
        lbl_8055ED71 = 1;
    }
    if (*(unsigned int *)(lbl_804891DC + 8) != lbl_8055E044) fn_80131318();
    fn_80010188(-1, 0xC, *(int *)(lbl_804891DC + 4), lbl_805631F0, lbl_80563198 * (float)lbl_8055CFF0, lbl_805631CC + lbl_805631E4 * (float)lbl_8055CFF4);
    f31 = lbl_805631A0 * (float)lbl_8055CFF4 + lbl_805631F4;
    if (*(unsigned int *)(lbl_804891D0 + 8) != lbl_8055E044) fn_80131318();
    fn_80010188(-1, 0x24, *(int *)(lbl_804891D0 + 4), lbl_805631F0, lbl_80563198 * (float)lbl_8055CFF0, f31);
    fn_802C8638(&cam);
}
#pragma cplusplus reset
void fn_802061F8(void) {
    lbl_8055ED6C = fn_802CAC28(lbl_8033BC40, 0);
}

void fn_80206228(void) {
    if (lbl_8055ED6C != -2) {
        ((void (*)(int))fn_802CAC54)(lbl_8055ED6C);
        lbl_8055ED6C = -2;
    }
}

#pragma dont_inline reset
void fn_8020625C(void) {
    unsigned char old;
    if (fn_801E85A4() > 1) {
        old = fn_802C2C00(0);
        fn_80205D5C();
        if (fn_80205964() != 0) {
            fn_80205850();
            fn_80205FCC();
        }
        fn_802059C0();
        fn_802C2C00(old);
    }
}

extern int lbl_8055ED6C;
extern void fn_802CAC54(void);
extern int fn_802CAC28(const char *, int);
extern char lbl_8033BC40[];
extern int fn_801E85A4(void);
extern unsigned char fn_802C2C00(unsigned char);
extern void fn_80205D5C(void);
extern int fn_80205964(void);
extern void fn_80205850(void);
extern void fn_80205FCC(void);
extern void fn_802059C0(void);
extern int fn_801B8570(void);
extern void fn_801E866C(int);
