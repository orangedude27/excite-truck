// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <macros.h>

extern void __register_global_object(void *, void *, void *);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801312EC(void *, void *);
extern void fn_8022D98C(void *, void *, float, float, float, float, float);
extern void fn_80215EA8(void), fn_80215EC4(void), fn_80215F04(void), fn_80215F1C(void), fn_80215F5C(void);
extern char lbl_8033D678[], lbl_8033D684[], lbl_8033D6F0[], lbl_80490510[];
extern int lbl_8055B840, lbl_8055B848, lbl_8055B850, lbl_8055B858, lbl_8055EEF8;
extern int lbl_8055EF00, lbl_8055EF04;
extern char lbl_8055EF50[];
extern float lbl_80563434, lbl_80563450, lbl_80563454;
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" void fn_80215CF4(void) {
    register char *base asm("r30");
    register unsigned int zero asm("r31");
    char *p;

    base = lbl_80490510;
    fn_8000D838(&lbl_8055EEF8);
    zero = 0;
    lbl_8055EF00 = 0xFFFF0000;
    *(int *)(base + 0) = zero;
    *(int *)(base + 4) = 0x7B;
    *(int *)(base + 8) = zero;
    *(int *)(base + 0xC) = zero;
    *(int *)(base + 0x10) = zero;
    lbl_8055EF04 = 0x7F000000;
    fn_801312EC(base + 0x108, &lbl_8055B840);
    fn_801312EC(base + 0x114, lbl_8033D678);
    fn_801312EC(base + 0x120, &lbl_8055B848);
    fn_801312EC(base + 0x12C, &lbl_8055B850);
    fn_801312EC(base + 0x138, &lbl_8055B858);
    fn_801312EC(base + 0x144, lbl_8033D684);
    fn_8022D98C(base + 0x160, lbl_8055EF50, lbl_80563434, lbl_80563454, lbl_80563450, lbl_80563434, lbl_80563450);
    __register_global_object(base + 0x160, &fn_80215F5C, base + 0x150);
    p = base + 0x18C;
    *p = zero;
    p[8] = zero;
    *(int *)(p + 0xC) = (int)lbl_8033D6F0;
    *(int *)(p + 4) = -1;
    *(int *)(p + 0x10) = zero;
    __register_global_object(p, &fn_80215F1C, base + 0x180);
    p = base + 0x1E0;
    *(int *)(p + 4) = zero;
    p[0xC] = zero;
    fn_8002F53C(base + 0x200, &fn_80215F04, &fn_80215EC4, 0x18, 0x10);
    __register_global_object(0, &fn_80215EA8, base + 0x1F0);
    *(int *)(base + 0x380) = zero;
    *(int *)(base + 0x384) = zero;
    *(int *)(base + 0x388) = zero;
}
#pragma cplusplus reset
#pragma scheduling on
