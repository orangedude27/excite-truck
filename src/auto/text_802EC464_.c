// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

void fn_802EC464(void);
DECL_SECTION(".ctors") funcptr_t D_802ED624 = fn_802EC464;

extern int lbl_80560058;
extern int lbl_80560068;
extern int lbl_80560070;
extern void fn_8000D838(void *);
void fn_802EC464(void) {
    fn_8000D838(&lbl_80560058);
    *(volatile int *)((char *)&lbl_80560068 + 4) = 0;
    *(volatile int *)&lbl_80560068 = 0;
    (*(volatile int *)&lbl_80560068)++;
    *(volatile int *)((char *)&lbl_80560070 + 4) = 0;
    *(volatile int *)&lbl_80560070 = 0;
    (*(volatile int *)&lbl_80560070)++;
}
