// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".sdata") extern unsigned char lbl_8055EEB0[];
extern unsigned int lbl_8055EEB8;
extern unsigned char lbl_80489C88[];
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_80211604(void);
extern void fn_802115AC(void);
struct Object_802114F4 { void *next; unsigned int zero; unsigned int size; };
struct Root_802114F4 {
    unsigned int a, b, c, d, e;
    char pad1[0x6418 - 0x14];
    struct Object_802114F4 reg1;
    struct Object_802114F4 obj1;
    char pad2[0x6630 - 0x6430];
    struct Object_802114F4 reg2;
    struct Object_802114F4 obj2;
};
void fn_802114F4(void) {
    struct Object { void *next; unsigned int zero; unsigned int size; } *obj;
    unsigned int zero = 0;
    unsigned int size = 0x80;
    unsigned char *base = lbl_80489C88;
    fn_8000D838(lbl_8055EEB0);
    *(unsigned int *)base = zero;
    *(unsigned int *)(base + 4) = 123;
    *(unsigned int *)(base + 8) = zero;
    *(unsigned int *)(base + 0xc) = zero;
    *(unsigned int *)(base + 0x10) = zero;
    lbl_8055EEB8 = 0x7f000000;
    obj = (void *)(base + 0x6424);
    *(void **)(base + 0x6424) = (char *)obj + 0xc;
    obj->size = size;
    obj->zero = zero;
    __register_global_object((void *)obj, fn_80211604, base + 0x6418);
    obj = (void *)(base + 0x663c);
    *(void **)(base + 0x663c) = (char *)obj + 0xc;
    obj->size = size;
    obj->zero = zero;
    __register_global_object((void *)obj, fn_802115AC, base + 0x6630);
}
#pragma scheduling on
