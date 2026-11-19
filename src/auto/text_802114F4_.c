// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".sdata") extern unsigned char lbl_8055EEB0[];
extern unsigned int lbl_8055EEB8;
extern unsigned char lbl_80489C88[];
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_80211604(void);
extern void fn_802115AC(void);
#pragma scheduling invalid_target
void fn_802114F4(void) {
    struct Object { void *next; unsigned int zero; unsigned int size; } *obj;
    unsigned char *base = lbl_80489C88;
    unsigned int zero = 0;
    unsigned int size = 0x80;
    unsigned char *p;
    fn_8000D838(lbl_8055EEB0);
    *(unsigned int *)base = zero;
    p = base;
    *(unsigned int *)(p + 4) = 123;
    *(unsigned int *)(p + 8) = zero;
    *(unsigned int *)(p + 0xc) = zero;
    *(unsigned int *)(p + 0x10) = zero;
    lbl_8055EEB8 = 0x7f000000;
    obj = (struct Object *)(base + 0x6424);
    obj->next = (char *)obj + 0xc;
    obj->size = size;
    obj->zero = zero;
    __register_global_object((void *)obj, fn_80211604, base + 0x6418);
    obj = (struct Object *)(base + 0x663c);
    obj->next = (char *)obj + 0xc;
    obj->size = size;
    obj->zero = zero;
    __register_global_object((void *)obj, fn_802115AC, base + 0x6630);
}
#pragma scheduling on
