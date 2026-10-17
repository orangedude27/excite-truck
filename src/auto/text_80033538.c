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

void fn_800337C4(void *arg0, void *arg1) {
    int state;
    state = OSDisableInterrupts();
    *(unsigned short *)((char *)arg0 + 0x1AC) = *(unsigned short *)arg1;
    *(short *)((char *)arg0 + 0x1AE) = *(short *)((char *)arg1 + 2);
    *(unsigned int *)((char *)arg0 + 0x1C) |= 0x200;
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

void *__AXGetCurrentProfile(void) {
    unsigned int index;
    if (lbl_8055D7F0 != 0) {
        index = lbl_8055D7F4;
        lbl_8055D7F4 = (index + 1) % lbl_8055D7F8;
        return lbl_8055D7FC + index * 0x38;
    }
    return 0;
}

