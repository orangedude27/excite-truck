// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8018C510(void);
void __AXDSPInitCallback_801AFC38(void);
void fn_801BD790(void);
extern float lbl_80434930[];
extern float lbl_80434908[];
extern float lbl_80434950[];
extern float lbl_804348E8[];
extern unsigned char lbl_8055E4F4;
float fn_80181A48(void *arg0) {
 volatile float *p = lbl_804348E8;
 if (*((unsigned char *)arg0 + 0x259D)) {
   p += 18;
 } else if (lbl_8055E4F4) {
   p += 26;
 } else {
   p += 8;
 }
 return *((float *)((unsigned char *)arg0 + 0x2D0)) + p[7];
}

float fn_80181A94(void) { if (lbl_8055E4F4) return lbl_80434950[14]; return lbl_80434908[2]; }

float fn_80181AC0(void) { if (lbl_8055E4F4) return lbl_80434950[15]; return lbl_80434908[3]; }

float fn_80181AEC(void) { return lbl_80434930[3]; }

void fn_80181FC4(void) {
    fn_8018C510();
    __AXDSPInitCallback_801AFC38();
    fn_801BD790();
}

void fn_80181FEC(void* alarm) {
    fn_801D14EC(fn_801D1184(alarm));
}

void fn_801836DC(void) {

}

int fn_80186DDC(void) { return 0; }

void fn_80186DE4(void) {
    fn_8018A8A8();
}

int fn_80188E24(void) { return 0; }

typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern f32 lbl_80561CD0;
int fn_801C2BF8(int, f32 *);
void **fn_801B83A0(void);
int fn_801BF1B8(int, int);
extern f32 lbl_80561CAC;
void fn_80189C64(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x26AC) != 0) {
        fn_801BF1B8(*(int *)((char *)arg0 + 0x1EC), (*(unsigned char *)((char *)arg0 + 0x26AC) = 0, 0));
    }
    *(float *)((char *)arg0 + 0x26A8) = lbl_80561CAC;
}

void fn_8018A088(void) {

}

void fn_8018A2BC(void) {

}

void fn_8018ADA4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25DC) = farg0; }

void fn_8018ADAC(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25DC) = farg0; }

void fn_8018ADB4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E0) = farg0; }

void fn_8018ADBC(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E4) = farg0; }

void fn_8018ADC4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E8) = farg0; }

void fn_8018ADCC(void *arg0, float arg1) {
    *(float *)((unsigned char *)arg0 + 0x25EC) = arg1;
}

extern int lbl_8055E918;
void fn_8018ADEC(void *arg0) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C) + 8) = -10;
}

void fn_8018AF00(void) {

}

void fn_8018BDEC(void *arg0) {
    f32 sp[12];
    int value;
    sp[0]=lbl_80561CD0; sp[1]=lbl_80561CAC; sp[2]=lbl_80561CAC; sp[3]=lbl_80561CAC;
    sp[4]=lbl_80561CD0; sp[5]=lbl_80561CAC; sp[6]=lbl_80561CAC; sp[7]=lbl_80561CAC;
    sp[8]=lbl_80561CD0; sp[9]=lbl_80561CAC; sp[10]=lbl_80561CAC; sp[11]=lbl_80561CAC;
    value=*(int *)((u8 *)arg0+0x26C4);
    if(value) fn_801C2BF8(value,sp);
}

void fn_8018BF44(int *arg0) { *arg0 = 0x0FF807FF; }

int fn_8018BF54(void) { return 0; }

void fn_8018BF5C(void) {

}

void fn_8018BF60(void) {

}

int fn_8018BF64(void) { return 0x44; }

