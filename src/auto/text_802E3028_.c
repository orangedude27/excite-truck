// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>

#pragma dont_inline on
void fn_802E3028(const char *fmt, va_list args, int flag) {}
#pragma dont_inline reset

int fn_802E302C(void) { return 1; }

void fn_802E3090(void) {}

extern void fn_802E30C8(const char *, ...);
extern char lbl_8034CF34[];
extern void fn_802E3150(void *);
extern void fn_802E3028();
extern char lbl_8055D190;
extern char lbl_8055D198;
extern void exit(int);
void fn_802E317C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, ...) {
    fn_802E3028();
    fn_802E3150(&lbl_8055D198);
    exit(-1);
}

