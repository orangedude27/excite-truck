// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <string.h>
extern void fn_80241354(void*);
extern s32 lbl_803428B0[][16][3];
s32 fn_80243478(s32);

void fn_80243460(void* arg0) {
    fn_80241354((u8*)arg0 - 0x10);
}

extern void fn_80241820(void*);
void fn_80243468(void* arg0) {
    fn_80241820((u8*)arg0 - 0x10);
}

extern void fn_802408B0(void*);
void fn_80243470(void* arg0) {
    fn_802408B0((u8*)arg0 - 0x10);
}

#pragma dont_inline on
s32 fn_80243478(s32 arg0) {
    s32 count = 0;
    s32 (*entry)[3] = lbl_803428B0[arg0];
    s32 i;
    for (i = 0; i < 16; i++) {
        if (entry[i][0] == 0) return count;
        count++;
    }
    return count;
}

s32 fn_80243528(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)lbl_803428B0 + arg1 * 48;
    s32 sum = 0;
    s32 processed = 0;
    s32 groups;
    s32 left;
    if (arg0 <= 0) return 0;
    if (arg0 > 8) {
        groups = arg0 - 8;
        if (arg0 <= 0x7FFFFFFE) {
            groups = (groups + 7) >> 3;
            if (arg0 - 8 > 0) {
                do {
                    sum += p[1];
                    sum += p[4];
                    sum += p[7];
                    sum += p[10];
                    sum += p[13];
                    sum += p[16];
                    sum += p[19];
                    sum += p[22];
                    processed += 8;
                    p += 24;
                } while (--groups);
            }
        }
    }
    left = arg0 - processed;
    p = (s32 *)lbl_803428B0 + arg1 * 48 + processed * 3;
    if (processed < arg0) {
        do {
            sum += p[1];
            p += 3;
        } while (--left);
    }
    return sum;
}

s32 fn_80243710(s32 arg0, s32 arg1) {
    s32 result = 0;
    if (arg0 >= 0 && arg0 <= fn_80243478(arg1)) result = 1;
    return result;
}

__declspec(section ".sdata") extern s32 lbl_8055BE0C;
__declspec(section ".sdata") extern s32 lbl_8055BE10;
extern s32 fn_80230E90(s32);
extern s32 fn_80243528(s32, s32);
extern s32 fn_8024360C(s32);
extern s32 fn_80243710(s32, s32);
#pragma push
#pragma use_lmw_stmw off
s32 fn_80243764(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 old0 = *(s32 *)arg0;
    s32 old1 = *(s32 *)arg1;
    s32 next = old1 + arg3;
    s32 value, count, current;
    if ((*(s32 *)arg1 = next) < 0) *(s32 *)arg1 = 4;
    else if (next > 4) *(s32 *)arg1 = 0;
    if (*(s32 *)arg1 != old1) {
        fn_80243528(*(s32 *)arg0, old1);
        value = fn_8024360C(*(s32 *)arg1);
        count = fn_80243478(*(s32 *)arg1);
        if (fn_80243478(old1) != count) {
            if (fn_80243710(lbl_8055BE0C, *(s32 *)arg1) && *(s32 *)arg0 == lbl_8055BE10) {
                s32 temp = lbl_8055BE10;
                lbl_8055BE10 = lbl_8055BE0C;
                lbl_8055BE0C = temp;
                value = temp;
            } else {
                lbl_8055BE10 = value;
                lbl_8055BE0C = *(s32 *)arg0;
            }
        } else {
            lbl_8055BE10 = -1;
            lbl_8055BE0C = -1;
        }
        *(s32 *)arg0 = value;
    }
    current = *(s32 *)arg0 + arg2;
    *(s32 *)arg0 = current;
    if (current < 0) *(s32 *)arg0 = fn_80243478(*(s32 *)arg1) - 1;
    else if (*(s32 *)arg0 > fn_80243478(*(s32 *)arg1) - 1) *(s32 *)arg0 = 0;
    if (*(s32 *)arg0 != lbl_8055BE10) {
        lbl_8055BE0C = -1;
        lbl_8055BE10 = -1;
    }
    if (old0 != *(s32 *)arg0 || old1 != *(s32 *)arg1) {
        fn_80230E90(0);
        return 1;
    }
    return 0;
}
#pragma pop
void fn_802438EC(char* arg0) {
    s32 len = strlen(arg0);
    if (len > 0) {
        u8* end = (u8*)((u32)len + (u32)arg0);
        if ((s32)end[-1] == '_') end[-1] = 0;
    }
}

__declspec(section ".sdata") extern char lbl_8055BE14[];
void fn_80243938(char *arg0, char *arg1) {
    s32 len = strlen(arg0);
    char *dst = arg0;

    if (len == 0) return;
    if (arg0[len - 1] == '_') return;
    if (len + 1 >= (s32)arg1) return;

    arg1 = (char *)((s32)arg1 - 1);
    while (*dst != 0) {
        dst++;
        arg1 = (char *)((s32)arg1 - 1);
    }
    if ((s32)arg1 <= 0) return;

    {
        char *src = lbl_8055BE14;
        while ((*dst++ = *src++) != 0) {
            arg1 = (char *)((s32)arg1 - 1);
            if ((s32)arg1 <= 0) {
                dst[-1] = 0;
                return;
            }
        }
    }
}

extern s32 fn_80128668(void);
extern void fn_80221E7C(void);
extern s32 fn_802328D4(char*);
extern s32 fn_802C519C(char*);
extern char lbl_80342CEC[];
s32 fn_80243BD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80243C18(void) {
    fn_80221E7C();
}

extern void fn_80243938(char *, char *);
void fn_802443C0(void *arg0) {
    char *str;
    void *obj = arg0;
    fn_802438EC(*(char **)((u8 *)obj + 0x18));
    str = *(char **)((u8 *)obj + 0x18);
    if (strlen(str) != 0) {
        *(char **)((u32)strlen(str) + (u32)str - 1) = 0;
    }
    fn_80243938(*(char **)((u8 *)obj + 0x18), *(char **)((u8 *)obj + 0x1C));
}

void fn_8024442C(void *arg0) {
    u8 *field = (u8 *)arg0 + 0x29;
    *field = (s32)((*field == 0) ? 1 : 0);
}

extern s32 fn_80244558(void *);
#pragma push
#pragma cplusplus on
struct Dummy_80244440 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
#pragma cplusplus on
extern "C" s32 fn_80244440(void *arg0, s32 arg1) {
    switch (arg1) {
    case 0x125: fn_80243764((u8 *)arg0 + 0x30, (u8 *)arg0 + 0x2C, -1, 0); goto yes;
    case 0x127: fn_80243764((u8 *)arg0 + 0x30, (u8 *)arg0 + 0x2C, 1, 0); goto yes;
    case 0x126: fn_80243764((u8 *)arg0 + 0x30, (u8 *)arg0 + 0x2C, 0, -1); goto yes;
    case 0x128: fn_80243764((u8 *)arg0 + 0x30, (u8 *)arg0 + 0x2C, 0, 1); goto yes;
    case 0xD:
        ((Dummy_80244440 *)arg0)->f22();
        goto yes;
    case 0x1B:
        if (fn_80244558(arg0) > 0) {
            ((Dummy_80244440 *)arg0)->f23();
            goto yes;
        }
        return 0;
    default: return 0;
    }
yes:
    return 1;
}
#pragma cplusplus off
u8 fn_80244550(void *arg0) {
    return *((u8 *)arg0 + 0x28);
}

s32 fn_80244558(void *arg0) {
    char *str = *(char **)((u8 *)arg0 + 0x18);
    s32 len = strlen(str);
    if (len > 0 && *(s8 *)((u32)len + (u32)str - 1) == '_') len--;
    return len;
}

