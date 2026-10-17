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

