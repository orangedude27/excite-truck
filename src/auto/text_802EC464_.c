// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

void fn_802EC464(void);
DECL_SECTION(".ctors") funcptr_t D_802ED624 = fn_802EC464;

/* lbl_80560058: 8-byte (.sbss) record zeroed/linked by fn_8000D838. */
extern int lbl_80560058;
/* lbl_80560068/lbl_80560070: 8-byte (.sbss) counters, [1] cleared then [0] set
 * to 1 (a "generation"/initialized sentinel pair). */
extern int lbl_80560068;
extern int lbl_80560070;
extern void fn_8000D838(void *);
void fn_802EC464(void) {
    /* .ctors init: set up the 8-byte record at lbl_80560058 (fn_8000D838 fills
       and links it), then initialize the two 8-byte counter/sentinel pairs at
       lbl_80560068 and lbl_80560070 by clearing their high word and setting the
       low word to 1. */
    fn_8000D838(&lbl_80560058);
    *(volatile int *)((char *)&lbl_80560068 + 4) = 0;
    *(volatile int *)&lbl_80560068 = 0;
    (*(volatile int *)&lbl_80560068)++;
    *(volatile int *)((char *)&lbl_80560070 + 4) = 0;
    *(volatile int *)&lbl_80560070 = 0;
    (*(volatile int *)&lbl_80560070)++;
}
