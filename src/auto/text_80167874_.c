#include "types.h"
#include <string.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
extern s32 fn_80128668(void);
s32 fn_80167D58(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167D98(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167DD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167E18(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80167E58(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int *fn_80167E98(int *arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = 0;
        if (arg1 > 0)
            fn_80128668();
    }
    return arg0;
}

void fn_80167EE0(s32 *arg0) {
    *arg0 = 0;
}

extern s32 fn_8002B1D8(s32, s32 *, s32);
extern char lbl_803301B8[];
extern s32 lbl_8055E354;
void fn_801688B4(s32 arg0) {
    s32 i = 0;
    s32 j = 0;
    while (i < *(s32 *)(&lbl_8055E354 + 0x1D4D0)) {
        s32 *p = *(s32 **)(&lbl_8055E354 + 0x1D4CC) + j;
        if (arg0 == *p) {
            *(char *)(p + 4) = 1;
        }
        j += 0x20;
        i += 1;
    }
}

void fn_801688FC(s32 arg0) {
    s32 i = 0;
    s32 j = 0;
    while (i < *(s32 *)(&lbl_8055E354 + 0x1D4D0)) {
        s32 *p = *(s32 **)(&lbl_8055E354 + 0x1D4CC) + j;
        if (arg0 == *p) {
            *(char *)(p + 4) = 0;
        }
        j += 0x20;
        i += 1;
    }
}

s32 fn_80168944(s32 arg0) {
    s32 len = strlen((char *)lbl_803301B8);
    s32 r = fn_8002B1D8(arg0, (s32 *)lbl_803301B8, len);
    return (u32)__cntlzw(r) >> 5;
}

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
s32 fn_80169978(s32 arg0) {
    s32 r;
    if ((r = fn_8002B1D8(arg0, &lbl_8055A198, 4)) == 0) {
        return 1;
    }
    if (fn_8002B1D8(arg0, &lbl_8055A1A0, 4) == 0) {
        return 1;
    }
    return 0;
}

extern char lbl_8055A1B8;
s32 fn_80169D64(s32 arg0) {
    s32 p = (s32)&lbl_8055A1B8;
    s32 len = strlen((char *)p);
    s32 r = fn_8002B1D8(arg0, (s32 *)p, len);
    s32 ret = (u32)__cntlzw(r) >> 5;
    return ret;
}

