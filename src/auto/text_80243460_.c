// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <string.h>
extern void fn_80241354(void*);
extern s32 lbl_803428B0[][16][3];
extern char lbl_80342CEC[];
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
    s32 (*entry)[3] = lbl_803428B0[arg0];
    s32 count = 0;
    s32 i;
    for (i = 0; i < 16; i++) {
        if ((*entry)[0] == 0) break;
        count++;
        entry++;
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

#pragma unroll on
s32 fn_8024360C(s32 value, s32 tableIndex) {
    s32 *entry = (s32 *)lbl_803428B0 + tableIndex * 48;
    s32 start = 0;
    s32 best = 0;
    s32 index = 0;
    s32 length;
    s32 end;
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            length = entry[1 + j * 3];
            end = start + length;
            if (length > 0)
                best = index;
            if (value >= start && value < end)
                return index;
            start = end;
            index++;
        }
        entry += 12;
    }
    return best;
}
#pragma unroll reset

s32 fn_80243710(s32 arg0, s32 arg1) {
    s32 result = 0;
    if (arg0 >= 0 && arg0 <= fn_80243478(arg1)) result = 1;
    return result;
}

__declspec(section ".sdata") extern s32 lbl_8055BE0C;
__declspec(section ".sdata") extern s32 lbl_8055BE10;
extern s32 fn_80230E90(s32);
extern s32 fn_80243528(s32, s32);
extern s32 fn_8024360C(s32, s32);
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
        value = fn_8024360C(*(s32 *)arg1, *(s32 *)arg1);
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
    register int len = strlen(arg0);
    register char *dst = arg0;
    register char *src;

    if (len != 0) {
        if (arg0[len - 1] == '_') goto done;
        if (len + 1 >= (s32)arg1) goto done;
    }

    src = lbl_8055BE14;
    goto scan_test;

scan_body:
    arg1 = (char *)(arg1 - 1);
    dst += 1;

scan_test:
    if (*dst != 0) goto scan_body;
    if ((s32)arg1 <= 0) goto done;
    goto copy_body;

copy_check:
    arg1 = (char *)(arg1 - 1);
    if ((s32)arg1 > 0) goto copy_body;
    dst[-1] = 0;
    goto done;

copy_body:
    while ((*dst++ = *src++) != 0) goto copy_check;

done:
    return;
}

#pragma scheduling invalid_target
void fn_802439E8(void *arg0, s32 arg1, s32 arg2) {
    s32 value = 0xB;
    volatile s32 *field = (volatile s32 *)((u8 *)arg0 + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x18) = arg1;
    *(char **)arg0 = lbl_80342CEC;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *field = arg2;
    if (arg2 <= 0xB)
        value = arg2;
    *field = value;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = 0;
    *((u8 *)arg0 + 0x29) = 1;
    *((u8 *)arg0 + 0x28) = 0;
}
#pragma scheduling on

extern s32 fn_80232578(s32);
extern s32 fn_802C5130(s32);
extern void fn_802E30C8(const char *, ...);
extern s32 fn_80131234(const char *);
void fn_80243A38(void *arg0) {
    s32 *entry;
    s32 group, i, type;
    *(s32 *)((u8 *)arg0 + 0x20) = fn_80232578((s32)((u8 *)lbl_803428B0 + 0x3C0));
    *(s32 *)((u8 *)arg0 + 0x24) = fn_802C5130((s32)((u8 *)lbl_803428B0 + 0x3CC));
    if (*(s32 *)((u8 *)arg0 + 0x24) == 0)
        fn_802E30C8((char *)lbl_803428B0 + 0x3D8);
    fn_80243938(*(char **)((u8 *)arg0 + 0x18), *(char **)((u8 *)arg0 + 0x1C));
    entry = (s32 *)lbl_803428B0;
    group = 0;
    do {
        i = 0;
        while (i < fn_80243478(group)) {
            type = entry[2];
            if (type == 4) goto next;
            if (type < 4) {
                if (type != 2) goto next;
                if (entry[0] == 0) goto next;
                if (strlen((char *)entry[0]) >= 1) goto next;
                entry[0] = fn_80131234((char *)lbl_803428B0 + 0x410);
            } else {
                if (type >= 6) goto next;
                if (entry[0] == 0) goto next;
                if (strlen((char *)entry[0]) >= 1) goto next;
                entry[0] = fn_80131234((char *)lbl_803428B0 + (type == 3 ? 0x3FC : 0x420));
            }
        next:
            entry += 3;
            i++;
        }
        group++;
        entry = (s32 *)lbl_803428B0 + group * 48;
    } while (group < 5);
}

extern s32 fn_802328D4(char *);
extern s32 fn_802C519C(char *);
void fn_80243B84(void *arg0) {
    char **obj = (char **)arg0;
    fn_802438EC(obj[6]);
    fn_802C519C(obj[9]);
    obj[9] = 0;
    fn_802328D4(obj[8]);
    obj[8] = 0;
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
    u8 *str;
    fn_802438EC(*(char **)((u8 *)arg0 + 0x18));
    str = (u8 *)*(char **)((u8 *)arg0 + 0x18);
    if (strlen((char *)str) != 0) {
        *(u8 *)(str + strlen((char *)str) - 1) = (u8)0;
    }
    fn_80243938(*(char **)((u8 *)arg0 + 0x18), *(char **)((u8 *)arg0 + 0x1C));
}

void fn_8024442C(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x29) = !*(u8 *)((u8 *)arg0 + 0x29);
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

