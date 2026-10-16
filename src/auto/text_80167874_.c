#include "types.h"
#include <string.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
extern s32 fn_80128668(void);
extern s32 lbl_80330020;
extern char lbl_803300E0[];
extern void fn_802E317C(const char *);
s32 *fn_80167874(s32 arg0) {
    s32 *entry = &lbl_80330020;
    for (;;) {
        s32 value = *entry;
        if (value == arg0)
            return entry;
        if (value == 6) {
            fn_802E317C(lbl_803300E0);
            return &lbl_80330020;
        }
        entry = (s32 *)((u8 *)entry + 0x20);
    }
}

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

s32 fn_80168944(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_803301B8;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

extern char lbl_80330364[];
s32 fn_80169108(s32 arg0, s32 arg1) {
    s32 addr = (s32)lbl_80330364;
    s32 len = strlen((char *)addr);
    s32 r = fn_8002B1D8(arg1, (s32 *)addr, len);
    return (u32)__cntlzw(r) >> 5;
}

s32 fn_801698B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a;
    s32 b;
    s32 min;
    s32 max;
    s32 mid;

    a = arg2 - arg0;
    if (arg0 > a) {
        a = arg0;
    }
    b = arg3 - arg1;
    if (arg1 > b) {
        b = arg1;
    }
    min = a;
    max = b;
    if (b < a) {
        min = b;
        max = a;
    }
    mid = (min + max) >> 1;
    if (mid >= 5) {
        return 1;
    }
    if (mid >= 3) {
        return 2;
    }
    return 3;
}

s32 fn_80169928(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a;
    s32 b;

    a = arg3 - arg1;
    if (arg1 > a) {
        a = arg1;
    }
    b = arg2 - arg0;
    if (arg0 > b) {
        b = arg0;
    }
    if (a < b) {
        b = a;
    }
    if (b > 2) {
        return 3;
    }
    return b + 1;
}

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
s32 fn_80169978(s32 arg0) {
    s32 r = 0;
    if (fn_8002B1D8(arg0, &lbl_8055A198, 4) != 0) {
        if (fn_8002B1D8(arg0, &lbl_8055A1A0, 4) == 0) {
            r = 1;
        }
    }
    else {
        r = 1;
    }
    return r;
}

extern char lbl_8055A1B8;
s32 fn_80169D64(s32 arg0) {
    s32 p = (s32)&lbl_8055A1B8;
    s32 len = strlen((char *)p);
    s32 r = fn_8002B1D8(arg0, (s32 *)p, len);
    return (u32)__cntlzw(r) >> 5;
}

