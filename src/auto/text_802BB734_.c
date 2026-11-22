// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_802BB824(void);
extern void fn_802BB7CC(void);
extern char lbl_8055FA60;
extern int lbl_8055FA68;
extern char lbl_804BFFE8[];
struct Obj802BB734 { void *next; int zero; int size; };
static inline void init802BB734(struct Obj802BB734 *o, int size, void (*dtor)(void), void *arg) {
    o->size = size;
    o->zero = 0;
    __register_global_object(o, dtor, arg);
}
void fn_802BB734(void) {
    char *base = (char *)lbl_804BFFE8;
    struct Obj802BB734 *object;
    fn_8000D838(&lbl_8055FA60);
    object = (struct Obj802BB734 *)(base + 0xC);
    *(char **)(base + 0xC) = (char *)object + 0xC;
    object->size = 0x10;
    lbl_8055FA68 = 0xFFFF0000;
    object->zero = 0;
    __register_global_object(object, fn_802BB824, base + 0);
    object = (struct Obj802BB734 *)(base + 0x64);
    object->zero = 0;
    *(char **)(base + 0x64) = (char *)object + 0xC;
    object->size = 4;
    __register_global_object(object, fn_802BB7CC, base + 0x58);
}
#pragma scheduling on
