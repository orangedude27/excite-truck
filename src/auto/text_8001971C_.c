// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8001980C(void);
extern void fn_800197B0(void);
extern char lbl_80357E00[];
__declspec(section ".sdata") extern char lbl_8055D580;
struct OBJ_8001971C { char *vptr; int f4; int f8; };
static inline void init_obj_8001971C(struct OBJ_8001971C *o) { o->f8 = 0x20; o->f4 = 0; }

void fn_8001971C(void) {
    char *base = (char *)&lbl_80357E00;
    struct OBJ_8001971C *o1, *o2;
    fn_8000D838(&lbl_8055D580);
    o1 = (struct OBJ_8001971C *)(base + 0xC);
    *(char **)(base + 0xC) = (char *)o1 + 0xC;
    o1->f8 = 0x20;
    o1->f4 = 0;
    __register_global_object(o1, (void *)fn_8001980C, base + 0);
    o2 = (struct OBJ_8001971C *)(base + 0x2A4);
    o2->f8 = 0x20;
    *(char **)(base + 0x2A4) = (char *)o2 + 0xC;
    o2->f4 = 0;
    __register_global_object(o2, (void *)fn_800197B0, base + 0x298);
}
