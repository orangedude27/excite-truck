// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8001980C(void);
extern void fn_800197B0(void);
extern char lbl_80357E00[];
__declspec(section ".sdata") extern char lbl_8055D580;
struct GObj { char *vptr; int a; int b; };

void fn_8001971C(void) {
    char *base = (char *)&lbl_80357E00;
    char *temp_r3;
    char *temp_r3_2;

    fn_8000D838(&lbl_8055D580);
    temp_r3 = base + 0xC;
    *(char **)(base + 0xC) = temp_r3 + 0xC;
    *(int *)(temp_r3 + 8) = 0x20;
    *(int *)(temp_r3 + 4) = 0;
    __register_global_object(temp_r3, (void *)fn_8001980C, base);
    temp_r3_2 = base + 0x2A4;
    *(int *)(temp_r3_2 + 8) = 0x20;
    *(char **)(base + 0x2A4) = temp_r3_2 + 0xC;
    *(int *)(temp_r3_2 + 4) = 0;
    __register_global_object(temp_r3_2, (void *)fn_800197B0, base + 0x298);
}
