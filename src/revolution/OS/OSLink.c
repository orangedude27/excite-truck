#include <revolution/OS.h>

void __OSModuleInit(void) {
    /* Reset the dynamic-module (REL) registry before any modules are linked. */
    OS_FIRST_REL = OS_LAST_REL = NULL;
    OS_REL_NAME_TABLE = NULL;
}
