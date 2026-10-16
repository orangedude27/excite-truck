// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8029CD14(void);
extern void fn_8029C934(void);
extern void fn_8029C650(void);
extern void *fn_8029D464(void *, int);
extern int lbl_8055F7F8;
extern int lbl_8055F7F0;
extern int lbl_804B5010;
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

void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

void fn_8029C650(void) { register int value=lbl_8055CAA8; if(value != -1) fn_802C6CF8(); }

void fn_8029C934(void) {
    int *p;
    int i = 0;
#pragma push
#pragma small_data off
    p = &lbl_804B5010;
#pragma pop
    do {
        fn_8029D464((void *)*p, 1);
        ++p;
        ++i;
    } while (i < lbl_8055F7F0);
    lbl_8055F7F0 = 0;
}

void fn_8029CD14(void) {
    if (lbl_8055F7F8 != 0) {
        fn_8028E398();
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
    int stride = *(int *)((char *)arg0 + 0xC);
    short *data = *(short **)((char *)arg0 + 4);
    int index = arg1 + arg2 * stride;
    float val = lbl_8056469C * arg3 + data[index];
    int out = (int)val;
    if (out < -32768) out = -32768;
    else if (out > 32767) out = 32767;
    data[index] = out;
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
