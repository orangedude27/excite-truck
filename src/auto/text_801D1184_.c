// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801D11D4(void) {
    fn_801D11D8();
}

extern void *fn_801284F8(int, const char *);
extern void fn_801D0FA4(void);
extern char lbl_80338208;
extern char lbl_80338214;
extern void *lbl_804348E8[];
extern float lbl_80562A48;
extern void fn_801819A0(void *, void *, void *, float, float, float);
extern float lbl_80562A4C;
void fn_801D1244(float *arg0) {
    *arg0 = lbl_80562A4C;
}

void fn_801D1250(float *arg0, int arg1) {
    char *p = (char *)lbl_804348E8[arg1];
    float f4 = *(float *)(p + 0x25d0);
    float f5 = *(float *)(p + 0x25f4);
    float f6;
    if (f4 > arg0[11]) {
        f6 = f4 - arg0[8];
        if (lbl_80562A4C > f6)
            f6 = lbl_80562A4C;
        {
            float val = arg0[3] + (arg0[2] * f4 + arg0[1] * (f4 * f4)) - arg0[9] * f6;
            f6 = arg0[10];
            if (f6 <= val)
                f6 = val;
        }
    } else {
        f6 = arg0[6] + (arg0[5] * f4 + arg0[4] * (f4 * f4));
    }
    arg0[0] = f5 * f6 - f4 * arg0[7];
}

void fn_801D1008(void*, unsigned int);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D130C(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801D1008((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

extern int lbl_8055E908;
extern int fn_80128670(int);
void fn_801D1364(void) {
    if (lbl_8055E908 != 0) {
        fn_80128670(lbl_8055E908 - 0x10);
    }
    lbl_8055E908 = 0;
}

void fn_801D139C(void) {

}

extern int lbl_8055E8F8;
extern char lbl_8055ABD0;
void fn_801D1250(float*, int);
void fn_8012850C(int, void*);
void* fn_8002F37C(void (*)(void*), int, int, int);
void fn_801D14BC(void*);
extern void fn_8012850C();
extern void *fn_8002F37C();
void fn_801D13A0(void) {
 int offset=0; int i=0;
 while(i<lbl_8055E8F8) { fn_801D1250((float*)(lbl_8055E908+offset),i); offset+=0x34; i++; }
}

void fn_801D1458(int arg1) {
 ((void (*)(int))fn_801D11D4)(lbl_8055E908+arg1*0x34);
}

void fn_801D1468(void) {
    int count = lbl_8055E8F8;
    fn_8012850C(count * 0x34 + 0x10, &lbl_8055ABD0);
    lbl_8055E908 = (int)fn_8002F37C(fn_801D14BC, 0, 0x34, count);
}

void fn_801D14BC(void* arg0) {
 float value=lbl_80562A4C;
 *(float*)((char*)arg0+0x18)=value; *(float*)((char*)arg0+0x14)=value;
 *(float*)((char*)arg0+0x10)=value; *(float*)((char*)arg0+0xc)=value;
 *(float*)((char*)arg0+8)=value; *(float*)((char*)arg0+4)=value;
 *(float*)((char*)arg0+0x1c)=value; *(float*)((char*)arg0+0x20)=value;
}

extern void *lbl_804348E8[];
extern float lbl_80562A48;
extern float lbl_80562A4C;
extern void fn_801819A0(void *, void *, void *, float, float, float);
