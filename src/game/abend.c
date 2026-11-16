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
    /* Opens the log file, writes a separator banner, the studio name, and another separator. */
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
    /* Close the abnormal-end log file if it is open, then invalidate its handle. */
    #define ABEND_LOG_FILE lbl_8055D178  /* s32 abend log-file handle, -1 when closed */
    #define CloseLogFile   fn_802E3734   /* closes a file handle and invalidates it */
    if (ABEND_LOG_FILE != -1) {
        CloseLogFile(&ABEND_LOG_FILE);
        ABEND_LOG_FILE = -1;
    }
    #undef CloseLogFile
    #undef ABEND_LOG_FILE
}

/* Variadic wrapper that forwards a formatted message to fn_802E3028 with flag 0. */
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
/* Report a fatal "ABEND" with the given message, then deliberately fault on a
 * write to address 0 and hang so the process cannot continue. */
void fn_802E3150(void *message) {
    int zero = 0;
    fn_802E30C8(sAbendFormat, message);
    *(int *)0 = zero;
    for (;;) {}
}
#pragma scheduling on
#pragma dont_inline reset
/* Report a fatal "PANIC" with a formatted message, then print "ABEND" and halt. */
void fn_802E317C(int fmt, ...) {
    va_list args;

    /* Fix note: start the variadic list after its sole fixed argument. */
    va_start(args, fmt);
    fn_802E3028((const char *)fmt, args, (int)&sPanicPrefix);
    va_end(args);
    fn_802E3150(&sPanicLabel);
    exit(-1);
}

