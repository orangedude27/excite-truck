// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_802B8DF8(void);
extern void fn_802B8DA0(void);
extern void __register_global_object(void *, void *, void *, void *, void *, void *, void *, void *, float, float, float);
__declspec(section ".sdata") extern unsigned char lbl_8055F9F0[];
extern int lbl_8055F9F8;
extern int lbl_8055F9FC;
extern unsigned char lbl_804BE7B8[];
__declspec(section ".sdata") extern float lbl_8055FA08[];
__declspec(section ".sdata") extern float lbl_8055FA10[];
__declspec(section ".sdata") extern float lbl_8055FA18[];
__declspec(section ".sdata") extern float lbl_8055FA20[];
extern float lbl_80564C5C;
extern float lbl_80564C88;
extern float lbl_80564CA8;
extern float lbl_80564C98;

void fn_802B8CA4(void) {
    register unsigned char *base asm("r30") = lbl_804BE7B8;
    register int zero asm("r31") = 0;
    register float *a08 asm("r10");
    register float *a10 asm("r9");
    register float *a18 asm("r8");
    register float *a20 asm("r7");
    register float v5C asm("f3");
    register float v88 asm("f2");
    register float vA8 asm("f1");
    register float v98 asm("f0");
    unsigned char *q;

    fn_8000D838(lbl_8055F9F0);
    v5C = lbl_80564C5C;
    v88 = lbl_80564C88;
    vA8 = lbl_80564CA8;
    v98 = lbl_80564C98;
    a08 = lbl_8055FA08;
    a10 = lbl_8055FA10;
    a18 = lbl_8055FA18;
    a20 = lbl_8055FA20;
    *(int *)(base + 4) = 0x7b;
    lbl_8055F9F8 = -65536;
    *(int *)(base + 0) = zero;
    *(int *)(base + 8) = zero;
    *(int *)(base + 12) = zero;
    *(int *)(base + 16) = zero;
    lbl_8055F9FC = 0x7f000000;
    lbl_8055FA08[0] = v5C;
    a08[1] = v88;
    lbl_8055FA10[0] = v5C;
    a10[1] = v88;
    lbl_8055FA18[0] = v5C;
    a18[1] = vA8;
    lbl_8055FA20[0] = v5C;
    a20[1] = v98;
    q = base + 0x20;
    *(void **)(base + 0x20) = q + 0xc;
    *(int *)(q + 8) = 0x10;
    *(int *)(q + 4) = zero;
    __register_global_object(q, fn_802B8DF8, base + 0x14, q + 0xc, a20, a18, a10, a08, vA8, v88, v5C);
    q = base + 0x12b8;
    *(int *)(q + 4) = zero;
    *(void **)q = q + 0xc;
    *(int *)(q + 8) = 0x20;
    ((void (*)(void *, void *, void *))__register_global_object)(q, fn_802B8DA0, base + 0x12ac);
}
