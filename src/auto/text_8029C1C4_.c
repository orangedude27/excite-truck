// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8029CD14(void);
extern void fn_8029CB3C(void);
extern void fn_8029C934(void);
extern void fn_8029C650(void);
extern void *fn_8029D464(void *, int);
extern int lbl_8055F7F8;
extern int lbl_8055F7F0;
extern int lbl_804B5010[];
extern int lbl_8055CAA8;
extern void fn_8028E398(void);
extern void fn_802C6CF8(void);
extern void fn_802CAC54(int);
extern void fn_80128670(int);
extern void fn_80128668(void *);
extern unsigned char lbl_80349780[];
extern float lbl_80564648;
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void);
extern float lbl_8056469C;
extern double lbl_80564680;
extern float fn_801E88F0(int);
extern float fn_802C88E8(void *);
extern int fn_802C9640(void *);

void fn_8029C1C4(void) {
    lbl_8055F7FC = 0;
    fn_8029C570(); fn_8029C73C(); fn_8029C998(); fn_8029CBA0(); fn_8029C664();
    if (fn_802BF4F0() == 0 && lbl_8055F7F0 <= 0 && lbl_8055F7F4 > 0) fn_80287B38(fn_8029C450);
}

void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

void fn_8029C25C(void) {
    int *p;
    int i;
    float v = fn_801E7E24();
    if (__fabsf(v) > lbl_80558DC4) {
        p = (int *)&lbl_804B5010;
        i = 0;
        do { fn_8029D574(*p++); ++i; } while (i < lbl_8055F7F0);
    }
}

void fn_8029C650(void) { register int value=lbl_8055CAA8; if(value != -1) fn_802C6CF8(); }

void fn_8029C934(void) {
    int *p = (int *)lbl_804B5010;
    int i = 0;
    while (i < lbl_8055F7F0) {
        fn_8029D464((void *)*p, 1);
        ++p;
        ++i;
    }
    lbl_8055F7F0 = 0;
}

void fn_8029CD14(void) {
    if (lbl_8055F7F8 != 0) {
        ((void (*)(int))fn_8028E398)(lbl_8055F7F8);
        lbl_8055F7F8 = 0;
    }
}

void *fn_8029D464(void *arg0,int arg1) {
 if(arg0) { fn_802CAC54(*(int *)((unsigned char *)arg0+0x74)); fn_80128670(*(int *)((unsigned char *)arg0+0x70)); fn_80128670(*(int *)arg0); if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

extern float fn_801E88F0(int);
extern float fn_802C88E8(void *);
extern int fn_802C9640(void *);
extern float lbl_80564648;
extern unsigned char lbl_80349780[];
int fn_8029D4CC(void *arg0) {
    float scale = fn_801E88F0(-1);
    float squaredScale = scale * scale;
    float radius = fn_802C88E8((char *)arg0 + 0x54) * squaredScale;
    float temp_f0 = lbl_80564648 + *(float *)((char *)arg0 + 0x60);
    int result = 0;
    temp_f0 = temp_f0 * temp_f0;
    if (radius >= temp_f0) {
        return 0;
    }
    if (fn_802C9640((char *)arg0 + 0x54) != 0) {
        result = 1;
    }
    return result;
}

void fn_8029D550(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x54);
    arg1[1] = *(float *)((char *)arg0 + 0x58);
    arg1[2] = *(float *)((char *)arg0 + 0x5C);
    *arg2 = *(float *)((char *)arg0 + 0x60);
}

extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void);
extern float lbl_8056469C;
void fn_8029DF64(void *arg0, int arg1, int arg2, float arg3) {
    int low = -32768;
    int stride;
    short *data;
    int index;
    float val;
    int cvt;
    int out;
    stride = *(int *)((char *)arg0 + 0xC);
    data = *(short **)((char *)arg0 + 4);
    index = arg1 + arg2 * stride;
    val = lbl_8056469C * arg3 + (float)data[index];
    cvt = (int)val;
    if (cvt > -32768) low = cvt;
    out = 32767;
    if (low < 32767) out = low;
    data[index] = out;
}

extern float fn_80287BC8(float, float);
extern void fn_8028E590(int, float *, float *, float);
extern int fn_8029DFE0(float *, float, float);
extern float lbl_80564628;
extern float lbl_80564634;
extern float lbl_80564658;
extern float lbl_8056465C;
extern float lbl_80564660;
extern float lbl_80564664;
extern float lbl_80564668;
extern float lbl_80564674;
void fn_8029E49C(int unused, void *arg1, int arg2) {
    float sp1C, sp18, sp14, sp10, spC, sp8;
    float temp_f0, temp_f0_2, temp_f1, temp_f2, temp_f3, temp_f6, temp_f7;
    float var_f1, var_f31, var_f5;
    unsigned char *temp_r31, *temp_r5;
    temp_r5 = (unsigned char *)arg1 + arg2 * 0x3C;
    temp_r31 = temp_r5 + 0x70;
    if ((unsigned char *)&sp14 == temp_r31) {
        temp_f6 = *(float *)(temp_r31 + 4); temp_f0 = *(float *)(temp_r31); temp_f7 = *(float *)(temp_r31 + 8);
        sp14 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x18) + (temp_f0 * *(float *)arg1 + temp_f6 * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x1C) + (temp_f0 * *(float *)((unsigned char *)arg1 + 4) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = temp_f7 * *(float *)((unsigned char *)arg1 + 0x20) + (temp_f0 * *(float *)((unsigned char *)arg1 + 8) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x14));
    } else {
        sp14 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x18) + (*(float *)temp_r31 * *(float *)arg1 + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x1C) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 4) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x20) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 8) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x14));
    }
    temp_f2 = sp18; temp_f1 = sp1C;
    sp14 += *(float *)((unsigned char *)arg1 + 0x24);
    sp18 = temp_f2 + *(float *)((unsigned char *)arg1 + 0x28);
    sp1C = temp_f1 + *(float *)((unsigned char *)arg1 + 0x2C);
    if (fn_8029DFE0(&sp14, temp_f1, temp_f2)) {
        sp18 += lbl_8056465C;
        if (*(float *)temp_r31 > lbl_80564628) var_f1 = lbl_80564658; else var_f1 = lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (*(float *)((unsigned char *)arg1 + 0x50) * var_f1);
        sp8 = *(float *)((unsigned char *)arg1 + 0x34) + *(float *)arg1 * temp_f3;
        spC = *(float *)((unsigned char *)arg1 + 0x38) + *(float *)((unsigned char *)arg1 + 4) * temp_f3;
        sp10 = *(float *)((unsigned char *)arg1 + 0x3C) + *(float *)((unsigned char *)arg1 + 8) * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * *(float *)((unsigned char *)arg1 + 0x50);
        if (var_f5 < temp_f0_2) {} else var_f5 = temp_f0_2;
        sp8 += *(float *)((unsigned char *)arg1 + 0xC) * var_f5;
        spC += *(float *)((unsigned char *)arg1 + 0x10) * var_f5;
        sp10 += *(float *)((unsigned char *)arg1 + 0x14) * var_f5;
        if (*(float *)temp_r31 > lbl_80564628) var_f31 = lbl_80564658; else var_f31 = lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &sp14, &sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(int *)((char *)arg0 + 0x40));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8029EC64(void *, int);
extern float lbl_805646A8;
void fn_8029EA34(void *arg0, void **arg1) {
    float radius, dz, dx;
    void *temp;
    int i, offset;
    temp = *arg1;
    radius = *(float *)((char *)arg0 + 0x3C);
    dz = *(float *)((char *)temp + 0x2C) - *(float *)((char *)arg0 + 0x38);
    dx = *(float *)((char *)temp + 0x24) - *(float *)((char *)arg0 + 0x30);
    if (!(dx * dx + dz * dz > radius * radius)) {
        i = 0; offset = 0;
        do {
            if (!(*(unsigned int *)((char *)*arg1 + offset + 0x9C) & 8))
                fn_8029EC64(arg0, i);
            i++; offset += 0x3C;
        } while (i < 4);
    }
}

int fn_8029EAE8(void *arg0) {
    float temp_f31;
    int var_r31;
    temp_f31 = lbl_805646A8;
    var_r31 = 0;
    if (fn_802C88E8((char *)arg0 + 0x30) < temp_f31 &&
        ((int (*)(void *, float))fn_802C9640)((char *)arg0 + 0x30, *(float *)((char *)arg0 + 0x3C)) != 0) {
        var_r31 = 1;
    }
    return var_r31;
}

int fn_8029EF1C(void) {
    return 0;
}

void fn_8029EF24(void) {
}

void fn_8029EF28(void) {
}

void fn_8029EF2C(void) {
}

int fn_8029EF30(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8029EF38(void *arg0) {
    return *(int *)((char *)arg0 + 0x64);
}

void fn_8029EF40(void) {
    fn_8029EF28();
}

#pragma dont_inline on
void fn_8029EF44(void) {
    fn_8029EF2C();
}
#pragma dont_inline off
void fn_8029EF48(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 1;
}

void fn_8029EF54(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 0;
}

int fn_8029EF60(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x68);
}
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void);
extern float lbl_8056469C;
