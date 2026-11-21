#include "misc_io.h"
#include "abort_exit.h"
#include "ansi_files.h"

void __stdio_atexit(void) {
    /* Install __close_all as the stdio shutdown hook run at program exit. */
    __stdio_exit = __close_all;
}
