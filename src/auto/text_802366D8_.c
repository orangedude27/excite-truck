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
/* Static initializer of this module (the .ctors entry D_802ED3E0): register the
 * module's static record with the runtime, then bring up the two statics the
 * module's code works on -- the node entry lbl_80498638, written empty (no name,
 * type 0x7B, no handle), which is also where a table of such entries ends, and
 * lbl_8055F090, set to 0x7F000000. */
void fn_802366D8(void) {
#define NODE_TYPE_EMPTY 0x7B /* type of an empty node entry; fn_8021227C stops the
                              * table it is walking when it reads it */
    s32 type;
    unsigned int *record;
    fn_8000D838(&lbl_8055F088);
    record = lbl_80498638 + 1; /* the record's base the stores below run off; dead,
                                * kept by the opt_dead_assignments pragma above */
    lbl_80498638[0] = 0;       /* +0x00 name: none */
    type = NODE_TYPE_EMPTY;
    lbl_80498638[1] = type;    /* +0x04 type: empty */
    lbl_80498638[2] = 0;       /* +0x08 */
    lbl_80498638[3] = 0;       /* +0x0C */
    lbl_80498638[4] = 0;       /* +0x10 handle: none */
    lbl_8055F090 = 0x7F000000;
#undef NODE_TYPE_EMPTY
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3E0 = fn_802366D8;
