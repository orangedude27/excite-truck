// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8001980C(void);
extern void fn_800197B0(void);
extern char lbl_80357E00[];
__declspec(section ".sdata") extern char lbl_8055D580;
#pragma cplusplus on
extern "C" void fn_8000D838(void *);
extern "C" void __register_global_object(void *, void *, void *);
extern "C" void fn_8001980C(void);
extern "C" void fn_800197B0(void);
extern "C" char lbl_80357E00[];
struct OBJ_8001971C { char *vptr; int f4; int f8; void init(); };
inline void OBJ_8001971C::init() { f8 = 0x20; f4 = 0; }

extern "C" void fn_8001971C(void) {
    char *base = (char *)&lbl_80357E00;
    struct OBJ_8001971C *o1, *o2;
    fn_8000D838(&lbl_8055D580);
    o1 = (struct OBJ_8001971C *)(base + 0xC);
    *(char **)(base + 0xC) = (char *)o1 + 0xC;
    o1->init();
    __register_global_object(o1, (void *)fn_8001980C, base + 0);
    o2 = (struct OBJ_8001971C *)(base + 0x2A4);
    o2->init();
    *(char **)(base + 0x2A4) = (char *)o2 + 0xC;
    __register_global_object(o2, (void *)fn_800197B0, base + 0x298);
}
