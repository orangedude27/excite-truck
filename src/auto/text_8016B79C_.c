#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012850C(int, int);
extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248[];
extern char lbl_8055A268[];
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, void *);
extern void fn_8016A438(void);
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern f32 lbl_805619A0;
extern char lbl_80330AEC[];
extern char lbl_803306D0[];
extern void fn_801345D8(void *, s32, void *, s32);
extern void fn_802E317C(const char *, ...);
extern void fn_8016A15C(char *);
void *fn_80128668(void *);
void fn_802C6CF8(int);
int fn_8016C25C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) { fn_80128668((void *)arg0); }
    return arg0;
}

void *fn_8016C29C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 16) != 0) {
            int temp = *(int *)arg0;
            *((unsigned char *)arg0 + 16) = 0;
            if (temp != -1) {
                fn_802C6CF8(temp);
                *(int *)arg0 = -1;
            }
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8016C55C(void *arg0, void *arg1) {
    int index;
    void *dst;
    index = ((int *)arg0)[1];
    ((int *)arg0)[1] = index + 1;
    dst = (void *)((char *)*((void **)arg0) + index * 16);
    *(unsigned char *)dst = *(unsigned char *)arg1;
    *(int *)((char *)dst + 4) = *(int *)((char *)arg1 + 4);
    *(float *)((char *)dst + 8) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)dst + 12) = *(float *)((char *)arg1 + 12);
}

void *fn_8016C598(void *arg0, int arg1, int arg2) {
    int temp = fn_8012850C(arg1 * 16, arg2);
    ((int *)arg0)[0] = temp;
    ((int *)arg0)[3] = temp;
    ((int *)arg0)[2] = arg1;
    ((int *)arg0)[1] = 0;
    return arg0;
}

int fn_8016C760(void *arg0) { return ((int *)arg0)[1]; }

extern f32 lbl_805619A0;
void fn_8016CD10(void *arg0) {
    *((f32 *)((u8 *)arg0 + 0x34)) = lbl_805619A0;
    *((u8 *)arg0 + 0x30) = 0;
    *((u8 *)arg0 + 0x31) = 0;
}

void fn_8016CD28(void *arg0) {
    int zero = 0;
    int minusOne = -1;
    *((u8 *)arg0 + 0x10) = zero;
    ((int *)arg0)[0] = minusOne;
    ((int *)arg0)[1] = zero;
    ((int *)arg0)[2] = zero;
    ((int *)arg0)[3] = 3;
}

void fn_8016CDE0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0) = 0;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

s32 fn_8016CDF8(void *arg0, void *obj) {
    char sp8[0x1E];
    s32 count = 0;
    fn_801345D8(sp8, 0x1E, lbl_8033072C, 0);
    while (((s32 (*)(void *, char *))(*(u32 **)obj)[3])(obj, sp8) != 0) {
        count++;
        fn_801345D8(sp8, 0x1E, lbl_803308A0, count);
    }
    return count;
}

void fn_8016CE94(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 4) = arg1;
}

extern f32 lbl_80561980;
extern char lbl_8033072C[];
extern char lbl_803308A0[];
void *fn_8016CEC0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    fn_8000DA10();
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80561980;
    return arg0;
}

void fn_8016CEFC(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

s32 fn_8016DD98(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
        case 0:
            return 5;
        case 1:
            return 0xA;
        case 2:
            return 0xF;
        default:
            fn_802E317C((const char *)lbl_80330AEC);
            return 0;
    }
}

s32 fn_8016DE08(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_8016DE10(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

extern f32 lbl_8055E3C8;
extern f32 lbl_80561998;
extern void fn_8001B450(s32);
extern void fn_802BAF98(void *, s8);
void fn_8016DFB8(void *arg0) {
    char sp8;
    char pad[0x28];
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    if (value == 1) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 1) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 3) {
        fn_801345D8(&sp8, 0x1e, lbl_803306D0 + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
    } else {
        fn_802E317C(lbl_803306D0 + 0x288);
    }
    fn_8016A15C(&sp8);
}

void fn_8016E06C(void *arg0) {
    s32 index = *(s32 *)((u8 *)arg0 + 0x2c);
    if (index < *(s32 *)((u8 *)arg0 + 0x3c)) {
        u8 *item = (u8 *)*(void **)((u8 *)arg0 + 0x18) + index * 0x14;
        s32 i;
        s32 offset;
        *item = 1;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        *(s32 *)(item + 0x10) = 0;
        i = 0;
        offset = 0;
        while (i < *(s32 *)item) {
            if (*(s32 *)((u8 *)*(void **)item + offset + 4) != 0) {
                fn_802BAF98((u8 *)*(void **)item + offset, 1);
            }
            offset += 0x44;
            i += 1;
        }
    }
}

void fn_8016E118(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    if (value != -1) {
        fn_8001B450(value);
        *(s32 *)((u8 *)arg0 + 0x24) = -1;
    }
}

void fn_8016E15C(void *arg0, void *arg1) {
    s32 i;
    s32 offset;
    *(f32 *)((u8 *)arg0 + 0xc) = lbl_80561998;
    *(u8 *)((u8 *)arg0 + 9) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        i += 1;
        *(u8 *)((u8 *)*(void **)arg1 + offset + 0x30) = 0;
        offset += 0x38;
    }
}

s32 fn_8016E1A4(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x14);
}

void fn_8016E314(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0) = *(f32 *)((u8 *)arg0 + 4);
}

u8 fn_8016E320(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x9c);
}

extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248[];
extern char lbl_8055A268[];
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, void *);
extern void fn_8016A438(void);
s32 fn_8016FFE4(void) { return 0x1408; }

s32 fn_80170E78(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x1ec); }

f32 fn_80170E80(f32 *arg0) { return *arg0; }

u8 fn_80170E90(void *arg0) { return *(u8 *)((u8 *)arg0 + 8); }

extern char lbl_803306D0[];
extern char lbl_80330AEC[];
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern void fn_801345D8(void *, s32, void *, s32);
extern void fn_802E317C(const char *, ...);
void fn_80170E98(void *arg0, void *arg1, s32 arg2) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    if (value == 1) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 1) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
    } else if (value >= 0 && value < 3) {
        fn_801345D8(arg1, arg2, lbl_803306D0 + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
    } else {
        fn_802E317C(lbl_803306D0 + 0x288);
    }
}

u32 fn_80170FD4(void) { return 1; }

void fn_80171208(void *arg0, s32 arg1) {
    fn_801B0C78((void *)arg1);
}
