// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8001980C(void);
extern void fn_800197B0(void);
extern char lbl_80357E00[];
__declspec(section ".sdata") extern char lbl_8055D580;
struct OBJ_8001971C { char *vptr; int f4; int f8; };

void fn_8001971C(void) {
    char *base = (char *)&lbl_80357E00;
    register char *o1, *o2;
    fn_8000D838(&lbl_8055D580);
    o1 = base + 0xC;
    *(char **)(base + 0xC) = o1 + 0xC;
    *(int *)(o1 + 8) = 0x20;
    *(int *)(o1 + 4) = 0;
    __register_global_object(o1, (void *)fn_8001980C, base);
    o2 = base + 0x2A4;
    *(int *)(o2 + 8) = 0x20;
    *(char **)(base + 0x2A4) = o2 + 0xC;
    *(int *)(o2 + 4) = 0;
    __register_global_object(o2, (void *)fn_800197B0, base + 0x298);
}
