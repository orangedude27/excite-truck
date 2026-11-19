// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct Obj801D8FF8 {
    void *link;
    int unk_04;
    int unk_08;
} Obj801D8FF8;

#pragma push
#pragma scheduling invalid_target
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, void *, void *, int, int);
extern void fn_801D9090(void);
extern unsigned char lbl_804422D8[];
extern int lbl_8055E948;
extern int lbl_8055E950;
extern float lbl_80562B24;
extern float lbl_80562ADC;
#pragma push
#pragma scheduling invalid_target
struct Fields801D8FF8 { volatile unsigned int f0, f1, f2, f3, f4; };
struct Values801D8FF8 { volatile float a, b; };
void fn_801D8FF8(void) {
    volatile unsigned int *base = (volatile unsigned int *)lbl_804422D8;
    unsigned char *obj;
    volatile float *values;
    fn_8000D838(&lbl_8055E948);
    obj = (unsigned char *)base + 0xCC;
    values = (volatile float *)((unsigned char *)base + 0x38);
    base[0] = 0;
    base[1] = 0x7B;
    base[2] = 0;
    base[3] = 0;
    base[4] = 0;
    *(volatile int *)&lbl_8055E950 = 0x7F000000;
    values[0] = lbl_80562B24;
    values[1] = lbl_80562ADC;
    *(volatile void **)obj = obj + 0x0C;
    *(volatile int *)(obj + 0x08) = 0x40;
    *(volatile int *)(obj + 0x04) = 0;
    __register_global_object(obj, fn_801D9090, (unsigned char *)base + 0xC0, obj + 0x0C, (float *)values, 0x7F000000, 0);
}
#pragma pop
