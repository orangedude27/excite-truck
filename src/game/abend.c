// abend — abnormal-end reporting ("ABEND: %s").
// Recovered TU window 0x802E3028..0x802E3214 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E3214 (+ .ctors slot 0x802ED5EC) remains in
// auto/text_802E3214_.c pending a promotion pass.
#include <stdarg.h>

extern int fn_802E367C(int);
extern void fn_802E30C8(const char *, ...);
extern void *__AXGetStudio_8000D82C(void);
extern char lbl_8034CEF8[];
extern int lbl_8055D178;
extern int lbl_8055D180;
extern char lbl_8055D188;

#pragma dont_inline on
void fn_802E3028(const char *fmt, va_list args, int flag) {}

#pragma scheduling invalid_target
int fn_802E302C(void) {
    lbl_8055D178 = fn_802E367C((int)&lbl_8055D180);
    fn_802E30C8(lbl_8034CEF8);
    fn_802E30C8(&lbl_8055D188, __AXGetStudio_8000D82C());
    fn_802E30C8(lbl_8034CEF8);
    return 1;
}
#pragma scheduling on

extern int fn_802E367C(int);
extern void fn_802E30C8(const char *, ...);
extern void fn_8000D82C(void);
extern void *__AXGetStudio_8000D82C(void);
extern char lbl_8034CEF8[];
extern int lbl_8055D178;
extern int lbl_8055D180;
extern char lbl_8055D188;

extern void fn_802E3734(int *);
extern int lbl_8055D178;
void fn_802E3090(void) {
    if (lbl_8055D178 != -1) {
        fn_802E3734(&lbl_8055D178);
        lbl_8055D178 = -1;
    }
}

void fn_802E30C8(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fn_802E3028(fmt, args, 0);
    va_end(args);
}

extern void fn_802E30C8(const char *, ...);
extern char lbl_8034CF34[];
extern void fn_802E3150(void *);
extern void fn_802E3028();
extern char lbl_8055D190;
extern char lbl_8055D198;
extern void exit(int);

#define sPanicPrefix lbl_8055D190 /* "PANIC: " */
#define sPanicLabel lbl_8055D198  /* "PANIC" */
#define sAbendFormat lbl_8034CF34  /* "\nABEND: %s\n" */
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

