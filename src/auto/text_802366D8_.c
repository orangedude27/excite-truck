// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

/* This module's static record -- tag byte 0x31 at +0, next pointer at +4 -- which
 * fn_8000D838 pushes onto the static-record list headed by lbl_8055D450. */
extern int lbl_8055F088;
/* A record of the node-entry class fn_8021227C searches by name (+0x00) and type
 * (+0x04), 0x14 bytes wide: the name and three words, then the handle at +0x10,
 * the fields fn_80212340 releases when the entry goes away.  A record with no
 * name and type 0x7B is an empty one, and fn_8021227C stops the table there. */
extern unsigned int lbl_80498638[];
/* The module's other static, brought up at 0x7F000000 (1.7e38 read as a float). */
extern unsigned int lbl_8055F090;
/* fn_8000D838: tag this record 0x31 and chain it first on the list at lbl_8055D450. */
extern int fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802366D8(void) {
    int v;
    unsigned int *p;
    fn_8000D838(&lbl_8055F088);
    p = lbl_80498638 + 1;
    lbl_80498638[0] = 0;
    v = 0x7B;
    lbl_80498638[1] = v;
    lbl_80498638[2] = 0;
    lbl_80498638[3] = 0;
    lbl_80498638[4] = 0;
    lbl_8055F090 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3E0 = fn_802366D8;
