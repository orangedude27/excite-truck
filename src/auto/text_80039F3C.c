// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8037B8A0[32];
extern unsigned int lbl_8055D8F0;
extern unsigned char lbl_8055D8E0;
extern unsigned char lbl_8055D8E1;
extern unsigned char lbl_8055D900;
extern int lbl_8055D8F4;
extern unsigned int lbl_8037B8C0;
extern const char lbl_80302848[];
int fn_8003B380(int value) {
    lbl_8055D8F0 = value;
    return 1;
}

int fn_8003BB48(void) {
    return ((int *)lbl_8037B8A0)[1];
}

void *fn_8003BCC0(void) { return *(void **)&lbl_8037B8A0; }

unsigned int DVDLowUnmaskStatusInterrupts(void) { return 1; }

unsigned int DVDLowMaskCoverInterrupt(void) { return 1; }

int fn_8003BE40(void) { return 0; }

