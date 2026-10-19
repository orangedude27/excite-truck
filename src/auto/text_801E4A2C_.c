// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>
typedef signed int s32;
typedef unsigned char u8;
typedef signed short s16;
extern s32 fn_80128668(s32 *);
extern s32 fn_802C4C80(s32);
extern s32 fn_802C4FF8(const char *);
extern s32 fn_802C4F2C(s32, s32 *, s32 *);
extern s32 fn_802C501C(void);
extern s32 fn_802C4EFC(s32);
extern s32 fn_801E4BEC(s32, s32, s32, s32, s32, const char *, char *);
extern char lbl_8055AEF0[];
extern char *strncpy(char *, const char *, unsigned long);
void fn_801E4A2C(s32 *arg0) {
    if (arg0 != 0) {
        fn_802C4C80(*arg0);
        fn_80128668(arg0);
    }
}

#pragma scheduling off
s32 fn_801E4A6C(s32 *arg0, const u8 *arg1) {
    s32 sum = 0;
    s32 index;
    if (arg0) {
        while (*arg1 != 0) {
            index = *arg1;
            sum += *(s16 *)((u8 *)arg0 + (index << 1) + 0x204);
            arg1++;
        }
        return sum;
    }
    return fn_802C4FF8((const char *)arg1);
}
s32 fn_801E4AB0(s32 *arg0, const u8 *arg1, s32 count) {
    s32 sum = 0;
    if (arg0 != 0) {
        while (*arg1 && count > 0) {
            s16 value = ((volatile s16 *)((u8 *)arg0 + 0x204))[*arg1];
            --count;
            ++arg1;
            sum += value;
        }
        return sum;
    }
    return fn_802C4FF8((const char *)arg1);
}
#pragma scheduling off
s32 fn_801E4B00(s32 *arg0) {
    s32 scratch;
    s32 result;
    if (arg0 != 0) {
        result = 0;
        fn_802C4F2C(*arg0, &scratch, &result);
        return result;
    }
    return fn_802C501C();
}

#pragma scheduling off
s32 fn_801E4B48(s32 *arg0) {
    s32 spC;
    s32 sp8;
    s32 result;
    if (arg0 != 0) {
        sp8 = 0;
        fn_802C4F2C(*arg0, &spC, &sp8);
        result = fn_802C4EFC(*arg0) - sp8;
    } else {
        result = 0;
    }
    return result;
}
#pragma dont_inline on
s32 fn_801E4BA8(s32 *arg0) {
    s32 temp_r31 = fn_801E4B48(arg0);
    s32 result = fn_801E4B00(arg0);
    result += temp_r31;
    return result;
}
#pragma dont_inline off
extern s32 fn_801E4B00(s32 *);
extern s32 fn_801E4B48(s32 *);
extern s32 fn_802C4EFC(s32);
extern s32 fn_801E4BEC(s32, s32, s32, s32, s32, const char *, char *);
extern char lbl_8055AEF0[];
extern char *strncpy(char *, const char *, unsigned long);
void fn_801E4DBC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, const char *arg5, unsigned long arg6, const char *arg7) {
    char buf[0x100];
    strncpy(buf, arg5, arg6);
    buf[arg6] = 0;
    fn_801E4BEC(arg0, arg1, arg2, arg3, arg4, lbl_8055AEF0, buf);
}

#pragma scheduling on
