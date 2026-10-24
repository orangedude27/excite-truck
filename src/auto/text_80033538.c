// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055D7F0;
extern unsigned int lbl_8055D7F4;
extern unsigned int lbl_8055D7F8;
extern unsigned char *lbl_8055D7FC;
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int OSDisableInterrupts(void);
extern double cos(double);
extern double fn_8002F234(float);
extern float lbl_80560AEC;
extern float lbl_80560AF0;
extern float lbl_80560AF4;
extern float lbl_80560AF8;
extern float lbl_80560AFC;
void fn_80033538(void *arg0, short arg1) {
    int state;
    state = OSDisableInterrupts();
    *(short *)((char *)arg0 + 0x14A) = arg1;
    *(unsigned int *)((char *)arg0 + 0x1C) |= 8;
    OSRestoreInterrupts(state);
}

void fn_80033584(void *arg1, void *arg0) {
    unsigned int flags = 0;
    unsigned short *src = (unsigned short *)((char *)arg1 + 4);
    unsigned short *dst = (unsigned short *)((char *)arg0 + 0x14E);
    unsigned short value;
    OSDisableInterrupts();
    value = *(unsigned short *)arg1; *(unsigned short *)((char *)arg0 + 0x14C) = value; if (value) flags |= 0x1;
    value = *(unsigned short *)((char *)arg1 + 2); dst[0] = value; if (value) flags |= 0x5;
    value = src[0]; dst[1] = value; if (value) flags |= 0x2;
    value = src[1]; dst[2] = value; if (value) flags |= 0x6;
    value = src[2]; dst[3] = value; if (value) flags |= 0x10000;
    value = src[3]; dst[4] = value; if (value) flags |= 0x50000;
    value = src[4]; dst[5] = value; if (value) flags |= 0x20000;
    value = src[5]; dst[6] = value; if (value) flags |= 0x60000;
    value = src[6]; dst[7] = value; if (value) flags |= 0x200000;
    value = src[7]; dst[8] = value; if (value) flags |= 0xA00000;
    value = src[8]; dst[9] = value; if (value) flags |= 0x400000;
    value = src[9]; dst[10] = value; if (value) flags |= 0xC00000;
    value = src[10]; dst[11] = value; if (value) flags |= 0x04000000;
    value = src[11]; dst[12] = value; if (value) flags |= 0x14000000;
    value = src[12]; dst[13] = value; if (value) flags |= 0x08000000;
    value = src[13]; dst[14] = value; if (value) flags |= 0x18000000;
    value = src[14]; dst[15] = value; if (value) flags |= 0x8;
    value = src[15]; dst[16] = value; if (value) flags |= 0x18;
    value = src[16]; dst[17] = value; if (value) flags |= 0x80000;
    value = src[17]; dst[18] = value; if (value) flags |= 0x180000;
    value = src[18]; dst[19] = value; if (value) flags |= 0x01000000;
    value = src[19]; dst[20] = value; if (value) flags |= 0x03000000;
    value = src[20]; dst[21] = value; if (value) flags |= 0x20000000;
    value = src[21]; dst[22] = value; if (value) flags |= 0x60000000;
    *(unsigned int *)((char *)arg0 + 0x144) = flags;
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x12;
    OSRestoreInterrupts(0);
}

void fn_800337C4(void *arg0, void *arg1) {
    int state;
    state = OSDisableInterrupts();
    *(unsigned short *)((char *)arg0 + 0x1AC) = *(unsigned short *)arg1;
    *(short *)((char *)arg0 + 0x1AE) = *(short *)((char *)arg1 + 2);
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x200;
    OSRestoreInterrupts(state);
}

void fn_8003381C(void *arg0, void *arg1) {
    int state;
    unsigned short mode;
    state = OSDisableInterrupts();
    *(unsigned int *)((unsigned char *)arg0 + 0x1B0) = *(unsigned int *)((unsigned char *)arg1 + 0x0);
    *(unsigned int *)((unsigned char *)arg0 + 0x1B4) = *(unsigned int *)((unsigned char *)arg1 + 0x4);
    *(unsigned int *)((unsigned char *)arg0 + 0x1B8) = *(unsigned int *)((unsigned char *)arg1 + 0x8);
    *(unsigned int *)((unsigned char *)arg0 + 0x1BC) = *(unsigned int *)((unsigned char *)arg1 + 0xC);
    mode = *(unsigned short *)((unsigned char *)arg1 + 2);
    switch (mode) {
    case 0:
        break;
    case 10:
        *(unsigned int *)((unsigned char *)arg0 + 0x1C0) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1C4) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1C8) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1CC) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D0) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D4) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D8) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1DC) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1E0) = 0x08000000;
        *(unsigned int *)((unsigned char *)arg0 + 0x1E4) = 0;
        break;
    case 25:
        *(unsigned int *)((unsigned char *)arg0 + 0x1C0) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1C4) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1C8) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1CC) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D0) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D4) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1D8) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1DC) = 0;
        *(unsigned int *)((unsigned char *)arg0 + 0x1E0) = 0x01000000;
        *(unsigned int *)((unsigned char *)arg0 + 0x1E4) = 0;
        break;
    }
    *(unsigned int *)((unsigned char *)arg0 + 0x1C) = (*(unsigned int *)((unsigned char *)arg0 + 0x1C) & 0xFFFF0FFF) | 0x10000 | 0x800;
    OSRestoreInterrupts(state);
}

void fn_80033918(void *arg0, void *arg1) {
    int state;
    state = OSDisableInterrupts();
    *(unsigned int *)((char *)arg0 + 0x1C0) = *(unsigned int *)arg1;
    *(unsigned int *)((char *)arg0 + 0x1C4) = *(unsigned int *)((char *)arg1 + 4);
    *(unsigned int *)((char *)arg0 + 0x1C8) = *(unsigned int *)((char *)arg1 + 8);
    *(unsigned int *)((char *)arg0 + 0x1CC) = *(unsigned int *)((char *)arg1 + 0xC);
    *(unsigned int *)((char *)arg0 + 0x1D0) = *(unsigned int *)((char *)arg1 + 0x10);
    *(unsigned int *)((char *)arg0 + 0x1D4) = *(unsigned int *)((char *)arg1 + 0x14);
    *(unsigned int *)((char *)arg0 + 0x1D8) = *(unsigned int *)((char *)arg1 + 0x18);
    *(unsigned int *)((char *)arg0 + 0x1DC) = *(unsigned int *)((char *)arg1 + 0x1C);
    *(unsigned int *)((char *)arg0 + 0x1E0) = *(unsigned int *)((char *)arg1 + 0x20);
    *(unsigned int *)((char *)arg0 + 0x1E4) = *(unsigned int *)((char *)arg1 + 0x24);
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x10000;
    OSRestoreInterrupts(state);
}

void fn_800339B0(void *arg0, void *arg1) {
    int state;
    state = OSDisableInterrupts();
    *(unsigned short *)((char *)arg0 + 0x1E8) = *(unsigned short *)arg1;
    *(unsigned short *)((char *)arg0 + 0x1EA) = *(unsigned short *)((char *)arg1 + 2);
    *(unsigned short *)((char *)arg0 + 0x1EC) = *(unsigned short *)((char *)arg1 + 4);
    *(unsigned short *)((char *)arg0 + 0x1EE) = *(unsigned short *)((char *)arg1 + 6);
    *(unsigned short *)((char *)arg0 + 0x1F0) = *(unsigned short *)((char *)arg1 + 8);
    *(unsigned short *)((char *)arg0 + 0x1F2) = *(unsigned short *)((char *)arg1 + 0xA);
    *(unsigned short *)((char *)arg0 + 0x1F4) = *(unsigned short *)((char *)arg1 + 0xC);
    *(unsigned int *)((char *)arg0 + 0x1C) = (*(unsigned int *)((char *)arg0 + 0x1C) & 0xFFFBFFFF) | 0x20000;
    OSRestoreInterrupts(state);
}

extern float lbl_80560AE8;
extern unsigned int __cvt_fp2unsigned(float);
void fn_80033A34(void *arg0, float arg1) {
    int state;
    unsigned int value;
    state = OSDisableInterrupts();
    value = __cvt_fp2unsigned(lbl_80560AE8 * arg1);
    *(unsigned short *)((char *)arg0 + 0x1EA) = value;
    *(unsigned short *)((char *)arg0 + 0x1E8) = value >> 16;
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x40000;
    OSRestoreInterrupts(state);
}

void fn_80033AAC(void *arg0, void *arg1) {
 int state=OSDisableInterrupts();
 *(unsigned short *)((char *)arg0+0x1F6)=*(unsigned short *)arg1;
 *(unsigned short *)((char *)arg0+0x1F8)=*(unsigned short *)((char *)arg1+2);
 *(unsigned short *)((char *)arg0+0x1FA)=*(unsigned short *)((char *)arg1+4);
 *(unsigned int *)((char *)arg0+0x1C)|=0x80000;
 OSRestoreInterrupts(state);
}

void fn_80033B0C(void *arg0, void *arg1) {
 int state=OSDisableInterrupts();
 *(unsigned short *)((char *)arg0+0x1FC)=*(unsigned short *)arg1;
 *(unsigned short *)((char *)arg0+0x1FE)=*(unsigned short *)((char *)arg1+2);
 *(unsigned short *)((char *)arg0+0x200)=*(unsigned short *)((char *)arg1+4);
 *(unsigned short *)((char *)arg0+0x202)=*(unsigned short *)((char *)arg1+6);
 *(unsigned int *)((char *)arg0+0x1C)|=0x100000;
 OSRestoreInterrupts(state);
}

void fn_80033B74(void *arg0, short arg1, short arg2) {
    int state = OSDisableInterrupts();
    *(short *)((char *)arg0 + 0x200) = arg1;
    *(short *)((char *)arg0 + 0x202) = arg2;
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x00200000;
    OSRestoreInterrupts(state);
}

void AXGetLpfCoefs(unsigned int arg0, short *arg1, short *arg2) {
    float angle = ((float)arg0 * lbl_80560AF0) / lbl_80560AF4;
    float c = (float)cos((double)angle);
    float t = lbl_80560AEC - c;
    float v = (float)fn_8002F234(t * t - lbl_80560AF8);
    short coef = (short)(lbl_80560AFC * -(v - t));
    *arg2 = coef;
    *arg1 = 0x7fff - (unsigned short)coef;
}

void fn_80033C8C(void *arg0, short arg1) {
    int state = OSDisableInterrupts();
    *(short *)((char *)arg0 + 0x20C) = arg1;
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x01000000;
    OSRestoreInterrupts(state);
}

void fn_80033CD8(void *arg0, void *arg1) {
    unsigned short flags;
    unsigned short value;
    unsigned short *dst;
    unsigned short *src;
    unsigned int bits;
    flags = 0;
    OSDisableInterrupts();
    src = (unsigned short *)((char *)arg1 + 4);
    dst = (unsigned short *)((char *)arg0 + 0x212);
    value = *(unsigned short *)arg1; *(unsigned short *)((char *)arg0 + 0x210) = value; if (value) flags |= 1;
    value = src[0]; dst[0] = value; if (value) flags |= 0x2;
    value = src[1]; dst[1] = value; if (value) flags |= 0x4;
    value = src[2]; dst[2] = value; if (value) flags |= 0x8;
    value = src[3]; dst[3] = value; if (value) flags |= 0x10;
    value = src[4]; dst[4] = value; if (value) flags |= 0x20;
    value = src[5]; dst[5] = value; if (value) flags |= 0x40;
    value = src[6]; dst[6] = value; if (value) flags |= 0x80;
    value = src[7]; dst[7] = value; if (value) flags |= 0x100;
    value = src[8]; dst[8] = value; if (value) flags |= 0x200;
    value = src[9]; dst[9] = value; if (value) flags |= 0x400;
    value = src[10]; dst[10] = value; if (value) flags |= 0x800;
    value = src[11]; dst[11] = value; if (value) flags |= 0x1000;
    value = src[12]; dst[12] = value; if (value) flags |= 0x2000;
    value = src[13]; dst[13] = value; if (value) flags |= 0x4000;
    value = src[14]; dst[14] = value; if (value) flags |= 0x8000;
    *(unsigned short *)((char *)arg0 + 0x20e) = flags;
    bits = *(unsigned int *)((char *)arg0 + 0x1c);
    bits |= 0x06000000;
    *(unsigned int *)((char *)arg0 + 0x1c) = bits;
    OSRestoreInterrupts(0);
}

void *__AXGetCurrentProfile(void)
{
  unsigned char *new_var;
  unsigned int index;
  int new_var2;
  if (lbl_8055D7F0 != 0)
  {
    index = lbl_8055D7F4;
    new_var = lbl_8055D7FC;
    new_var2 = index * 0x38;
    new_var = new_var + new_var2;
    lbl_8055D7F4 = (index + 1) % lbl_8055D7F8;
    return new_var;
  }
  return 0;
}

