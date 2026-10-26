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
__declspec(section ".sdata") extern float lbl_8055FA08;
__declspec(section ".sdata") extern float lbl_8055FA10;
__declspec(section ".sdata") extern float lbl_8055FA18;
__declspec(section ".sdata") extern float lbl_8055FA20;
extern float lbl_80564C5C;
extern float lbl_80564C88;
extern float lbl_80564CA8;
extern float lbl_80564C98;

void fn_802B8CA4(void) {
    unsigned char *p;
    unsigned char *q;
    fn_8000D838(lbl_8055F9F0);
    p = lbl_804BE7B8;
    q = p + 0x20;
    *(int *)(p + 4) = 0x7b;
    lbl_8055F9F8 = -65536;
    *(int *)(p + 0) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 12) = 0;
    *(int *)(p + 16) = 0;
    lbl_8055F9FC = 0x7f000000;
    lbl_8055FA08 = lbl_80564C5C;
    *((float *)&lbl_8055FA08 + 1) = lbl_80564C88;
    lbl_8055FA10 = lbl_80564C5C;
    *((float *)&lbl_8055FA10 + 1) = lbl_80564C88;
    lbl_8055FA18 = lbl_80564C5C;
    *((float *)&lbl_8055FA18 + 1) = lbl_80564CA8;
    lbl_8055FA20 = lbl_80564C5C;
    *((float *)&lbl_8055FA20 + 1) = lbl_80564C98;
    *(void **)(p + 0x20) = q + 0xc;
    *(int *)(q + 8) = 0x10;
    *(int *)(q + 4) = 0;
    __register_global_object(q, fn_802B8DF8, p + 0x14, q + 0xc, &lbl_8055FA20, &lbl_8055FA18, &lbl_8055FA10, &lbl_8055FA08, lbl_80564CA8, lbl_80564C88, lbl_80564C5C);
    q = p + 0x12b8;
    *(int *)(q + 4) = 0;
    *(void **)q = q + 0xc;
    *(int *)(q + 8) = 0x20;
    ((void (*)(void *, void *, void *))__register_global_object)(q, fn_802B8DA0, p + 0x12ac);
}
