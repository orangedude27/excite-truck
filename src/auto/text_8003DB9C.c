// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D949;
char __GXIsGPFifoReady(void) {
    return lbl_8055D949;
}

void GXGetFifoPtrs(void *arg0, int *arg1, int *arg2) {
    int value1 = ((int *)arg0)[0x14 / 4];
    int value2 = ((int *)arg0)[0x18 / 4];
    *arg1 = value1;
    *arg2 = value2;
}

int GXGetFifoBase(int *arg0) {
    return *arg0;
}

int GXGetFifoSize(void *arg0) {
    return ((int *)arg0)[2];
}

int GXGetFifoCount(void *arg0) {
    return ((int *)arg0)[0x1C / 4];
}

unsigned char GXGetFifoWrap(void *arg0) { return *(unsigned char *)((char *)arg0 + 0x20); }

extern void *lbl_8055D94C;
void* GXGetCurrentGXThread(void) {
    return lbl_8055D94C;
}

void GXGetLightPos(unsigned int x, unsigned int y, unsigned int z) {
    extern unsigned short *__peReg;
    *__peReg = (unsigned short)((x & 1) | ((y & 7) << 1) | ((z & 1) << 4));
}

void GXInitLightDir(unsigned int x, unsigned int y, unsigned int *arg2) {
    *arg2 = 0xC8000000 | ((x & 0x3FF) << 2) | ((y & 0x3FF) << 12) | 0x400000;
}

unsigned int GXGetLightDir(unsigned int value) {
    extern unsigned int lbl_8055D978;
    extern int OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(void);
    unsigned int old = lbl_8055D978;
    OSDisableInterrupts();
    lbl_8055D978 = value;
    OSRestoreInterrupts();
    return old;
}

extern unsigned short *__peReg;
extern unsigned int lbl_8055D978;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern void (*lbl_8055D978_callback)(unsigned short);
void GXInitSpecularDir(unsigned int arg0, void *ctx) {
    unsigned char local[0x2E0];
    unsigned short value = __peReg[7];
    if (lbl_8055D978 != 0) {
        OSClearContext(local + 8);
        OSSetCurrentContext(local + 8);
        ((void (*)(unsigned short))lbl_8055D978)(value);
        OSClearContext(local + 8);
        OSSetCurrentContext(ctx);
    }
    __peReg[5] |= 4;
}

void GXInitTexObjTlut(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

int GXGetTexObjHeight(void *arg0) {
    return ((int *)arg0)[4];
}

unsigned short GXGetTexObjWrapT(void *arg0) {
    return (unsigned short)(((*(unsigned int *)((char *)arg0 + 8)) >> 10) & 0x3ff) + 1;
}

int GXGetTexObjMipMap(void *arg0) {
    return *(int *)((char *)arg0 + 0x14);
}

int GXGetTexObjLODAll(int *arg0) {
    return *arg0 & 3;
}

int GXGetTexObjWrap_Internal(unsigned int *arg0) {
    return (*arg0 >> 2) & 3;
}

