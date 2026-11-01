// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma paired off
#pragma paired_single off
extern void fn_80129AFC(void);
extern void fn_802C2B48(void);
extern void fn_802C8530(void);
extern void fn_802C855C(void);
extern void fn_802C8638(float*);
extern void fn_802C86E8(unsigned int);
extern void fn_802C87B4(int, int, int, int);
extern void fn_802C88BC(int);
extern void fn_802C8BD0(int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, float, float);
extern void fn_802C8D74(void);
extern void fn_802C8DB8(float*, int, unsigned short*, int);
extern void fn_802C974C(float, float, float);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802E30C8(void*, ...);
extern unsigned short fn_802E46F0(void);
extern int fn_802E47B8(void);
extern char lbl_80343E90[];
extern unsigned short lbl_802FA510[];
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern float lbl_80563908;
extern float lbl_8056390C;
extern float lbl_80563910;
extern float lbl_80563914;
extern float lbl_80563918;
extern float lbl_8056391C;
extern void fn_8024BB98(void*);
extern void fn_8024BBF4(void*);
void fn_8024BDDC(void* arg0) {
    fn_8024BB98((char*)arg0 - 0x34);
}

extern void __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110(void*);
void fn_8024BDE4(void* arg0) {
    __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110((char*)arg0 - 0x34);
}

void fn_8024BDEC(void* arg0) {
    fn_8024BBF4((char*)arg0 - 0x18);
}

extern void fn_8024BCC0(void*);
void fn_8024BDF4(void* arg0) {
    fn_8024BCC0((char*)arg0 - 0x18);
}

extern void __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(void*);
void fn_8024BDFC(void* arg0) {
    __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC((char*)arg0 - 0x18);
}

void fn_8024BE04(void) {
    float m[12];
    float v[24];
    unsigned short idx[6];
    float one, zero, z;
    int h, i;
    fn_802E30C8(lbl_80343E90);
    h = fn_802CAC28(lbl_80343E90 + 0xC, 0);
    zero = lbl_8056390C;
    one = lbl_80563908;
    z = zero - lbl_80563910;
    for (i = 0;; i++) {
        m[0] = one; m[1] = zero; m[2] = zero; m[3] = zero;
        m[4] = one; m[5] = zero; m[6] = zero; m[7] = zero;
        m[8] = one; m[9] = zero; m[10] = zero; m[11] = z;
        fn_802C8530();
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_802C86E8(0xFF7F7F7F);
        fn_802C88BC(3);
        fn_802C974C(lbl_80563914, lbl_80563918, lbl_8056391C);
        fn_802C8638(m);
        v[0] = zero; v[1] = zero; v[2] = zero;
        idx[0] = lbl_802FA510[0];
        idx[1] = lbl_802FA510[1];
        idx[2] = lbl_802FA510[2];
        idx[3] = lbl_802FA510[3];
        idx[4] = lbl_802FA510[4];
        idx[5] = lbl_802FA510[5];
        fn_802C8BD0(h, idx[4], idx[3], idx[2], idx[1], idx[0], zero, zero);
        fn_802C8DB8(v, 4, idx, 6);
        fn_802C8D74();
        fn_802C855C();
        fn_802C2B48();
        if ((i & 0x3f) == 0) fn_802E30C8(lbl_80343E90 + 0x18, i);
        fn_80129AFC();
        if (fn_802E47B8() != 0 && fn_802E46F0() == 0x1b) break;
    }
    fn_802CAC54(h);
    fn_802E30C8(lbl_80343E90 + 0x24);
}

