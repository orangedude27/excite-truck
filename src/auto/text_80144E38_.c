#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E1E8;
extern char *lbl_8055E1EC;
#pragma opt_common_subs on
#pragma opt_propagation on
s32 fn_80144E38(s32 arg0, s32 arg1, s8 *arg2) {
    char *base = lbl_8055E1EC;
    char *e1;
    char *e2;
    char *e1b;
    if (arg2 != 0) {
        *arg2 = 1;
    }
    if (arg2 == 0) {
        goto ret;
    }
    *arg2 = 1;
    e1 = base + (arg1 << 5);
    e2 = e1 + arg0 * 4;
    if (*(s32 *)(e1 + 0x1514) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x1518) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    e1b = e1 + 8;
    if (*(s32 *)(e1b + 0x1514) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1b + 0x1518) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1b + 0x151C) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1b + 0x1520) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1b + 0x1524) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1b + 0x1528) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
ret:
    return *(s32 *)(base + (arg1 << 5) + arg0 * 4 + 0x1514);
}
char fn_80144F2C(void) {
    /* Return the flag byte that gates drawing of the HUD's counts element. */
    return lbl_8055E1E8;
}

/* Tail-call wrapper for fn_80144E38(): returns the count held at
 * lbl_8055E1EC + 0x1514 + (group * 8 + entry) * 4 and, through `flag` (NULL
 * allowed), whether that count is the best of its group's eight entries --
 * fn_80144E38 stores 1 and clears it as soon as one of the eight exceeds the
 * entry.  fn_80015658 prints groups 0 and 1 for the record id at race-state
 * +0x24 as the HUD's two "%d" strings. */
s32 fn_80144F34(void *entry, s32 group, s8 *flag) {
    return fn_80144E38((s32)entry, group, flag);
}
