// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
#pragma inline no fn_802057A8
extern void fn_802057A8(int, int, float, float, float, float);
extern float lbl_80563194, lbl_805631A8, lbl_805631B8, lbl_805631BC, lbl_805631C0;
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
#pragma ppc_psq_save on
#pragma scheduling invalid_target
void fn_802059C0(void) {
    double sp18,sp20,bias2;
    float temp_f14,temp_f14_2,temp_f15,temp_f16,temp_f17,temp_f19,temp_f21,temp_f23,temp_f24,temp_f25,temp_f26,temp_f27,temp_f28,temp_f29,temp_f30,temp_f31;
    float var_f0,var_f18,var_f1,var_f1_2,var_f1_3,var_f20,var_f20_2,var_f2;
    int var_r25,temp_r29,temp_r26,temp_r26_2,temp_r27,temp_r24,temp_r23,temp_r4,var_r0,var_r4;
    void *temp_r3;
    register unsigned int raw;
    union { struct { unsigned int hi,lo; } words; double d; } conv;
    temp_f21=fn_8013672C();
    raw=(unsigned int)*(int*)((char*)fn_801E7E3C()+8);
    conv.words.hi=0x43300000; conv.words.lo=raw^0x80000000U;
    temp_f19=temp_f21*(float)(conv.d-lbl_805631B0);
    temp_r29=fn_801E85A4(); temp_f24=lbl_805631A8; var_r25=0;
    sp18=(double)lbl_805631E8; temp_f23=lbl_805631B8; temp_f25=lbl_805631C4; temp_f26=lbl_805631C8;
    temp_f17=lbl_805631CC; temp_f27=lbl_805631D4; temp_f28=lbl_805631D0; temp_f29=lbl_805631D8;
    temp_f30=lbl_805631DC; temp_f31=lbl_805631E0; sp20=(double)lbl_805631E4; bias2=lbl_805631B0;
    goto loop_condition;
loop_body:
        temp_r26=((int(*)(int))fn_801E866C)(var_r25);
        if(fn_801B8570()!=0) {
            temp_r3=fn_801EA9A0(temp_r26);
            var_r4=*(int*)((char*)temp_r3+0x1C);
            var_f1=*(float*)((char*)*(void**)((char*)temp_r3+8)+0x2C8);
            if(var_r4==0){var_r4=1;var_f1=lbl_805631A8;}
            raw=(unsigned int)(var_r4-1); conv.words.hi=0x43300000; conv.words.lo=raw^0x80000000U;
            var_f1_2=(var_f1+((float)(conv.d-bias2)*temp_f21))/temp_f19;
            if(temp_f23<var_f1_2)var_f1_2=temp_f23;
            var_f0=(var_f1_2-temp_f24)/temp_f25;
            if(temp_f23<var_f0)var_f0=temp_f23;
            if(temp_f24>var_f0)var_f0=temp_f24;
            temp_r4=(int)(temp_f24+var_f0*temp_f26);
            temp_r24=(temp_r4<<24)|(var_r25==0 ? 0xFFFF0000 : 0xFF0000FF); temp_r23=temp_r24&0xFF7F7F7F;
            if(var_r25==0)var_f18=lbl_80563194;else var_f18=lbl_805631B8;
            temp_f16=var_f18*temp_f17; var_f2=(var_f1_2-temp_f24)/temp_f23; temp_f15=temp_f28*(temp_f27*temp_f17);
            if(temp_f23<var_f2)var_f2=temp_f23;
            if(temp_f24>var_f2)var_f2=temp_f24;
            temp_f14=temp_f15+var_f2*(temp_f23-temp_f15);
            if((unsigned char)temp_r4!=0) {
                fn_802C8CBC(-1); fn_802C8DBC(6);
                temp_r27=temp_r24&0xFFFFFF;
                fn_802057A8(temp_r27,0,var_f18,temp_f14,lbl_805631A8,lbl_805631A8);
                temp_r26_2=temp_r23&0xFFFFFF;
                fn_802057A8(temp_r26_2,0,lbl_805631A8,temp_f14,lbl_805631A8,lbl_805631A8);
                var_f20=temp_f14-temp_f29; if(temp_f24>var_f20)var_f20=temp_f24;
                fn_802057A8(temp_r24,1,var_f18,var_f20,lbl_805631A8,lbl_805631A8);
                fn_802057A8(temp_r23,1,lbl_805631A8,var_f20,lbl_805631A8,lbl_805631A8);
                var_f1_3=(var_f20-temp_f30)/temp_f31; if(temp_f23<var_f1_3)var_f1_3=temp_f23;
                if(temp_f24>var_f1_3)var_f1_3=temp_f24;
                var_f20_2=var_f20-((float)sp20+(var_f1_3*(float)sp18));
                if(temp_f24>var_f20_2)var_f20_2=temp_f24;
                fn_802057A8(temp_r27,1,var_f18,var_f20_2,lbl_805631A8,lbl_805631A8);
                fn_802057A8(temp_r26_2,1,lbl_805631A8,var_f20_2,lbl_805631A8,lbl_805631A8);
                fn_802C8E48(); fn_802C8D74();
            }
            if(lbl_8055ED6C!=-2) {
                ((void(*)(void))fn_802C8CBC)(); fn_802C8DBC(4);
                fn_802057A8(-1,0,temp_f16,temp_f14,lbl_805631B8,lbl_805631A8);
                fn_802057A8(-1,0,lbl_805631A8,temp_f14,lbl_805631B8,lbl_805631B8);
                temp_f14_2=temp_f14-temp_f15;
                fn_802057A8(-1,1,temp_f16,temp_f14_2,lbl_805631A8,lbl_805631A8);
                fn_802057A8(-1,1,lbl_805631A8,temp_f14_2,lbl_805631A8,lbl_805631B8);
                fn_802C8E48(); fn_802C8D74();
            }
        }
        var_r25++;
loop_condition:
    if(var_r25<temp_r29) goto loop_body;
}
#pragma scheduling on
extern float lbl_80563198, lbl_805631A0, lbl_805631CC, lbl_805631E4, lbl_805631F0, lbl_805631F4;
extern double lbl_805631B0;
extern void *lbl_804891D0;
extern void *lbl_804891DC;
extern void *lbl_8033BC18;
extern void *lbl_8033BC2C;
extern int lbl_8055CFF0, lbl_8055CFF4;
extern unsigned int lbl_8055E044;
extern unsigned char lbl_8055ED70, lbl_8055ED71;
extern void *fn_802C86DC(void);
extern void fn_802C88FC(void *, int);
extern void fn_802C8638(void *);
extern void fn_801312EC(void *, void *);
extern void fn_80131318(void);
extern void fn_80010188(int, int, int, float, float, float, float, float);
void fn_80205FCC(void) {
    int sp64, sp60, sp5C, sp58, sp54, sp50, sp4C, sp48, sp44, sp40, sp3C, sp38;
    float sp1C, sp18, sp14;
    int temp_r4;
    void *temp_r3;
    float temp_f31;
    temp_r3 = fn_802C86DC();
    sp38 = *(int *)((char *)temp_r3 + 0);
    sp3C = *(int *)((char *)temp_r3 + 4);
    sp40 = *(int *)((char *)temp_r3 + 8);
    sp44 = *(int *)((char *)temp_r3 + 0xC);
    sp48 = *(int *)((char *)temp_r3 + 0x10);
    sp4C = *(int *)((char *)temp_r3 + 0x14);
    sp50 = *(int *)((char *)temp_r3 + 0x18);
    sp54 = *(int *)((char *)temp_r3 + 0x1C);
    sp58 = *(int *)((char *)temp_r3 + 0x20);
    temp_r4 = *(int *)((char *)temp_r3 + 0x24);
    sp5C = temp_r4;
    sp60 = *(int *)((char *)temp_r3 + 0x28);
    sp64 = *(int *)((char *)temp_r3 + 0x2C);
    fn_802C88FC(&sp14, temp_r4);
    sp14 *= lbl_80563194;
    sp18 *= lbl_80563194;
    sp1C *= lbl_80563194;
    fn_802C8638(&sp14);
    if ((signed char)lbl_8055ED70 == 0) {
        fn_801312EC(lbl_804891D0, lbl_8033BC18);
        lbl_8055ED70 = 1;
    }
    if ((signed char)lbl_8055ED71 == 0) {
        fn_801312EC(lbl_804891DC, lbl_8033BC2C);
        lbl_8055ED71 = 1;
    }
    if (*(unsigned int *)((char *)lbl_804891DC + 8) != lbl_8055E044) fn_80131318();
    fn_80010188(-1, 0xC, *(int *)((char *)lbl_804891DC + 4), lbl_805631F0, lbl_80563198 * (float)lbl_8055CFF0, lbl_805631CC + lbl_805631E4 * (float)lbl_8055CFF4, lbl_80563198, (float)lbl_8055CFF0);
    temp_f31 = lbl_805631A0 * (float)lbl_8055CFF4 + lbl_805631F4;
    if (*(unsigned int *)((char *)lbl_804891D0 + 8) != lbl_8055E044) fn_80131318();
    fn_80010188(-1, 0x24, *(int *)((char *)lbl_804891D0 + 4), lbl_805631F0, lbl_80563198 * (float)lbl_8055CFF0, temp_f31, 0.0f, 0.0f);
    fn_802C8638(&sp38);
}

void fn_802061F8(void) {
    lbl_8055ED6C = fn_802CAC28(lbl_8033BC40, 0);
}

void fn_80206228(void) {
    if (lbl_8055ED6C != -2) {
        ((void (*)(int))fn_802CAC54)(lbl_8055ED6C);
        lbl_8055ED6C = -2;
    }
}

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
