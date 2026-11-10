#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E1E8;
extern char *lbl_8055E1EC;
s32 fn_80144E38(s32 arg0, s32 arg1, s8 *arg2) {
    char *base = (char *)lbl_8055E1EC;
    char *e1;
    char *e2;
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
    e1 += 8;
    if (*(s32 *)(e1 + 0x1514) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x1518) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x151C) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x1520) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x1524) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
    if (*(s32 *)(e1 + 0x1528) > *(s32 *)(e2 + 0x1514)) {
        *arg2 = 0;
    }
ret:
    return *(s32 *)(base + (arg1 << 5) + arg0 * 4 + 0x1514);
}

char fn_80144F2C(void) {
    return lbl_8055E1E8;
}

s32 fn_80144F34(void *arg0, s32 arg1, s8 *arg2) {
    return fn_80144E38((s32)arg0, arg1, arg2);
}
