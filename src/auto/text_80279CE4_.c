// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804A1968[];
extern void *memset(void *, int, unsigned int);
extern int fn_80131808(const char *);
extern void fn_80131818(void *);
extern void fn_80279F58(void *, void *);
extern void fn_802E317C(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80347A08[];
extern const char lbl_80347A1C[];
extern const float lbl_80564120;
void fn_80279D3C(void) {
}

extern float lbl_80564108,lbl_8056410C,lbl_80564110,lbl_80564114,lbl_80564118,lbl_8056411C,lbl_80564124,lbl_80564128,lbl_8056412C,lbl_80564130,lbl_80564134,lbl_80564138,lbl_8056413C,lbl_80564140,lbl_80564144,lbl_80564148,lbl_8056414C,lbl_80564150,lbl_80564154,lbl_80564158,lbl_8056415C,lbl_80564160,lbl_80564164,lbl_80564168,lbl_8056416C,lbl_80564170,lbl_80564174,lbl_80564178,lbl_8056417C,lbl_80564180,lbl_80564184,lbl_80564188,lbl_8056418C,lbl_80564190,lbl_80564194;
void fn_80279D40(void *arg0, int arg1) {
float *f=(float *)arg0; int *w=(int *)arg0;
memset(arg0,0,0x138);
f[0]=lbl_80564108; f[3]=lbl_80564110; f[6]=lbl_80564118; f[7]=lbl_8056411C; f[24]=lbl_80564160;
f[1]=lbl_8056410C; f[2]=lbl_8056410C; f[4]=lbl_80564114; f[5]=lbl_80564114;
f[11]=lbl_80564120; f[12]=lbl_80564124; w[13]=4; f[14]=lbl_80564128; f[15]=lbl_8056412C; f[16]=lbl_80564130; f[17]=lbl_80564134; f[8]=lbl_80564138; f[9]=lbl_80564138; f[10]=lbl_8056413C;
f[30]=lbl_80564140; f[31]=lbl_80564144; f[20]=lbl_80564148; f[21]=lbl_8056414C; f[22]=lbl_80564150; f[23]=lbl_80564154; f[25]=lbl_80564158; f[26]=lbl_8056415C; f[27]=lbl_80564120; f[28]=lbl_80564120; f[29]=lbl_80564120; f[32]=lbl_80564164; f[33]=lbl_80564168;
f[34]=lbl_80564170; f[35]=lbl_80564174; f[36]=lbl_80564178; f[37]=lbl_8056417C; f[39]=lbl_80564180; f[40]=lbl_80564184; f[38]=lbl_80564188;
f[41]=lbl_80564164; f[42]=lbl_80564168; f[43]=lbl_80564170; f[44]=lbl_80564174; f[45]=lbl_80564178; f[46]=lbl_8056417C; f[48]=lbl_80564180; f[49]=lbl_80564184; f[47]=lbl_80564188; f[50]=lbl_80564164;
f[51]=lbl_8056416C; f[52]=lbl_80564170; f[53]=lbl_80564174; f[54]=lbl_80564178; f[55]=lbl_8056417C; f[57]=lbl_80564180; f[58]=lbl_80564184; f[56]=lbl_80564188; f[59]=lbl_80564164;
f[60]=lbl_8056416C; f[61]=lbl_80564170; f[62]=lbl_80564174; f[63]=lbl_80564178; f[64]=lbl_8056417C; f[66]=lbl_80564180; f[67]=lbl_80564184; f[65]=lbl_80564188; f[68]=lbl_80564120; f[69]=lbl_80564120; f[70]=lbl_80564120; f[71]=lbl_8056418C; f[72]=lbl_80564190; f[73]=lbl_80564120; f[74]=lbl_80564194;
}

#pragma scheduling invalid_target
void fn_8027A714(void *arg0, const char *arg1) {
    char buf[0x100];
    void *result;

    sprintf(buf, lbl_80347A08, arg1);
    result = (void *)fn_80131808(buf);
    if (result == 0) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347A1C, buf);
    }
    fn_80279F58(arg0, result);
    fn_80131818(result);
}
#pragma scheduling on

void fn_8027A888(float *arg0) {
    float zero = lbl_80564120;
    arg0[0] = zero;
    arg0[1] = zero;
    arg0[2] = zero;
    arg0[3] = zero;
    arg0[4] = zero;
    arg0[5] = zero;
    arg0[6] = zero;
    arg0[7] = zero;
    arg0[8] = zero;
}

void fn_8027A8B4(void *arg0, void *arg1, int arg_sp0) {
    float a0 = *(float *)((char *)arg0 + 0);
    float a1 = *(float *)((char *)arg0 + 4);
    float a2 = *(float *)((char *)arg0 + 8);
    float a3 = *(float *)((char *)arg0 + 0xC);
    float a54 = *(float *)((char *)arg0 + 0x54);
    float a50 = *(float *)((char *)arg0 + 0x50);
    float a30 = *(float *)((char *)arg0 + 0x30);
    float a114 = *(float *)((char *)arg0 + 0x114);
    float a110 = *(float *)((char *)arg0 + 0x110);
    float a84 = *(float *)((char *)arg0 + 0x84);
    float a88 = *(float *)((char *)arg0 + 0x88);
    float a8c = *(float *)((char *)arg0 + 0x8C);
    float aa8 = *(float *)((char *)arg0 + 0xA8);
    float aac = *(float *)((char *)arg0 + 0xAC);
    float ab0 = *(float *)((char *)arg0 + 0xB0);
    float acc = *(float *)((char *)arg0 + 0xCC);
    float ad0 = *(float *)((char *)arg0 + 0xD0);
    float ad4 = *(float *)((char *)arg0 + 0xD4);
    float af0 = *(float *)((char *)arg0 + 0xF0);
    float af4 = *(float *)((char *)arg0 + 0xF4);
    float af8 = *(float *)((char *)arg0 + 0xF8);
    float b0 = *(float *)((char *)arg1 + 0);
    float b4 = *(float *)((char *)arg1 + 4);
    float b8 = *(float *)((char *)arg1 + 8);
    float bc = *(float *)((char *)arg1 + 0xC);
    float b10 = *(float *)((char *)arg1 + 0x10);
    float b14 = *(float *)((char *)arg1 + 0x14);
    float b18 = *(float *)((char *)arg1 + 0x18);
    float b1c = *(float *)((char *)arg1 + 0x1C);
    float b20 = *(float *)((char *)arg1 + 0x20);
    a0 *= b0; a1 *= b4; a2 *= b4; a3 *= b4;
    a54 *= b8; a50 *= b8; a30 *= bc;
    a110 *= b1c; a114 *= b20;
    a84 *= b18; a88 *= b10; a8c *= b14;
    aa8 *= b18; aac *= b10; ab0 *= b14;
    acc *= b18; ad0 *= b10; ad4 *= b14;
    af0 *= b18; af4 *= b10; af8 *= b14;
    *(float *)((char *)arg0 + 0) = a0;
    *(float *)((char *)arg0 + 4) = a1;
    *(float *)((char *)arg0 + 8) = a2;
    *(float *)((char *)arg0 + 0xC) = a3;
    *(float *)((char *)arg0 + 0x54) = a54;
    *(float *)((char *)arg0 + 0x50) = a50;
    *(float *)((char *)arg0 + 0x30) = a30;
    *(float *)((char *)arg0 + 0x110) = a110;
    *(float *)((char *)arg0 + 0x114) = a114;
    *(float *)((char *)arg0 + 0x84) = a84;
    *(float *)((char *)arg0 + 0x88) = a88;
    *(float *)((char *)arg0 + 0x8C) = a8c;
    *(float *)((char *)arg0 + 0xA8) = aa8;
    *(float *)((char *)arg0 + 0xAC) = aac;
    *(float *)((char *)arg0 + 0xB0) = ab0;
    *(float *)((char *)arg0 + 0xCC) = acc;
    *(float *)((char *)arg0 + 0xD0) = ad0;
    *(float *)((char *)arg0 + 0xD4) = ad4;
    *(float *)((char *)arg0 + 0xF0) = af0;
    *(float *)((char *)arg0 + 0xF4) = af4;
    *(float *)((char *)arg0 + 0xF8) = af8;
}

