// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D7E0;
void* fn_800328E8(void) {
    return lbl_8055D7E0;
}

void fn_80033148(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    *(short *)(p + 0x148) = 0;
    *(short *)(p + 0x17C) = 0;
    *(int *)(p + 0x1C) = 0x115000A4;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x30) = (int)(p + 0x34);
    *(short *)(p + 0x18E) = 0;
    *(short *)(p + 0x18C) = 0;
    *(short *)(p + 0x18A) = 0;
    *(short *)(p + 0x1FC) = 0;
    *(short *)(p + 0x204) = 0;
    *(short *)(p + 0x20C) = 0;
    *(short *)(p + 0x240) = 0;
    *(short *)(p + 0x242) = 0;
    *(short *)(p + 0x244) = 0;
    *(short *)(p + 0x246) = 0;
    *(short *)(p + 0x248) = 0;
}

void fn_80033404(void) {

}

extern unsigned char lbl_80363C60[];
extern unsigned long OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned long);
void fn_80033408(void *arg0, int arg1) {
    unsigned char *p = (unsigned char *)arg0;
    OSDisableInterrupts();
    switch (arg1) {
    case 0: *(short *)(p + 0x140) = 2; break;
    case 1: *(short *)(p + 0x140) = 1; break;
    case 2: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 0; break;
    case 3: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 1; break;
    case 4: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 2; break;
    }
    *(unsigned int *)(p + 0x1C) |= 1;
    OSRestoreInterrupts(0);
}

