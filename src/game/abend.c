// abend — abnormal-end reporting ("ABEND: %s").
// Recovered TU window 0x802E3028..0x802E3214 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E3214 (+ .ctors slot 0x802ED5EC) remains in
// auto/text_802E3214_.c pending a promotion pass.
#include <stdarg.h>

extern int File_Open(int);            /* opens the log file, returns its handle */
extern void fn_802E30C8(const char *, ...);
extern void *__AXGetStudio_8000D82C(void);
extern char ABEND_Separator[];
#define sSeparator     ABEND_Separator /* "================================" */
extern int ABEND_LogFileHandle;
#define sLogFileHandle ABEND_LogFileHandle
extern int ABEND_LogFileName;
#define sLogFileName   ABEND_LogFileName /* "log.log" */
extern char ABEND_FormatStringS;
#define sFmtPercentS   ABEND_FormatStringS /* "%s" */

#pragma dont_inline on
/* Formatted-message sink for the abnormal-end logger: `prefix` is 0 for a plain
 * message or a panic-prefix string. This build leaves the writer empty. */
void fn_802E3028(const char *fmt, va_list args, int prefix) {}

#pragma scheduling invalid_target
int Abend_InitLog(void) {
    /* Opens the log file, writes a separator banner, the studio name, and another separator. */
    sLogFileHandle = File_Open((int)&sLogFileName);
    fn_802E30C8(sSeparator);
    fn_802E30C8(&sFmtPercentS, __AXGetStudio_8000D82C());
    fn_802E30C8(sSeparator);
    return 1;
}
#pragma scheduling on

extern void fn_802E3734(int *);
/* Abend_CloseLog: close the abnormal-end log file if it is still open, then reset its handle to -1; called from KERNEL_Shutdown. */ void fn_802E3090(void) {
    /* Close the abnormal-end log file if it is open, then invalidate its handle. */
    #define CloseLogFile fn_802E3734 /* closes a file handle and invalidates it */
    if (sLogFileHandle != -1) {
        CloseLogFile(&sLogFileHandle);
        sLogFileHandle = -1;
    }
    #undef CloseLogFile
}

/* Forward a formatted message to the abnormal-end logger's sink with no panic prefix. */
void fn_802E30C8(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fn_802E3028(fmt, args, 0);
    va_end(args);
}

extern char lbl_8034CF34[];
extern void Abend_ReportFatal(void *);
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
/* Log the ABEND banner with the given label, then fault on a write to address 0 and hang so execution cannot continue. */ void Abend_ReportFatal(void *label) {
    int zero = 0;
    fn_802E30C8(sAbendFormat, label);
    *(int *)0 = zero;
    for (;;) {}
}
#pragma scheduling on
#pragma dont_inline reset
/* Report a fatal "PANIC" with a formatted message, then print "ABEND" and halt. */
/* Fatal panic: log the formatted message under the "PANIC: " prefix, then emit the ABEND banner (which faults and hangs); exit(-1) is a fallback. */ /* Fatal panic: log the formatted message under the "PANIC: " prefix, then emit the ABEND banner (which faults and hangs); exit(-1) is a fallback. */ /* Fatal panic: log the formatted message under the "PANIC: " prefix, then emit the ABEND banner (which faults and hangs); exit(-1) is a fallback. */ void Abend_Panic(int fmt, ...) {
    va_list args;

    va_start(args, fmt);
    fn_802E3028((const char *)fmt, args, (int)&sPanicPrefix);
    va_end(args);
    Abend_ReportFatal(&sPanicLabel);
    exit(-1);
}

