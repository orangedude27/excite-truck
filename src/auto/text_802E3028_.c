// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>

#pragma dont_inline on
void fn_802E3028(const char *fmt, va_list args, int flag) {}
#pragma dont_inline reset

extern void fn_802E367C(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_8000D82C(void);
extern char lbl_8034CEF8[];
extern int lbl_8055D178;
extern int lbl_8055D180;
extern int lbl_8055D188;

extern void fn_802E3734(int *);
extern int lbl_8055D178;
void fn_802E3090(void) {
    if (lbl_8055D178 != -1) {
        fn_802E3734(&lbl_8055D178);
        lbl_8055D178 = -1;
    }
}

extern void fn_802E30C8(const char *, ...);
extern char lbl_8034CF34[];
extern void fn_802E3150(void *);
extern void fn_802E3028();
extern char lbl_8055D190;
extern char lbl_8055D198;
extern void exit(int);
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802E3150(void *arg0) {
    int tmp = 0;
    fn_802E30C8(lbl_8034CF34, arg0);
    *(int *)0 = tmp;
    for (;;) {}
}
#pragma scheduling on
#pragma dont_inline reset
void fn_802E317C(int a0, ...) {
    va_list args;

    /* Fix note: start the variadic list after its sole fixed argument. */
    va_start(args, a0);
    fn_802E3028((const char *)a0, args, (int)&lbl_8055D190);
    va_end(args);
    fn_802E3150(&lbl_8055D198);
    exit(-1);
}

